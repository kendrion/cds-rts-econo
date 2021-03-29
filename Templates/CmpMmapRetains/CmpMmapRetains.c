/**
 * <name>CmpMmapRetains.c</name>
 * <description> 
 *  Example for an empty runtime component frame that can be used as a starting point to develop own components.
 *
 *  MANDATORY FUNCTIONS:
 *  - ComponentEntry()
 *  - ExportFunctions()
 *  - ImportFunctions()
 *  - CmpGetVersion()
 *  - HookFunction()
 * </description>
 *
 * <copyright>(c) 2003-2016 3S-Smart Software Solutions</copyright>
 */

#include "CmpStd.h"
#include "CmpMmapRetainsDep.h"

#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

USE_STMT

#ifndef RTS_COMPACT_MICRO

/**
 * <description>Entry function of the component. Called at startup for each component. Used to exchange function pointers with the component manager.</description>
 * <param name="pInitStruct" type="IN">Pointer to structure with:
 *		pfExportFunctions	OUT Pointer to function that exports component functions
 *		pfImportFunctions	OUT Pointer to function that imports functions from other components
 *		pfGetVersion		OUT Pointer to function to get component version
 *		pfRegisterAPI		IN	Pointer to component mangager function to register a api function
 *		pfGetAPI			IN	Pointer to component mangager function to get a api function
 *		pfCallHook			IN	Pointer to component mangager function to call a hook function
 * </param> 
 * <result>ERR_OK if component could be initialized, else error code.</result>
 */
DLL_DECL int CDECL ComponentEntry(INIT_STRUCT *pInitStruct)
{
	pInitStruct->CmpId = COMPONENT_ID;
	pInitStruct->pfExportFunctions = ExportFunctions;
	pInitStruct->pfImportFunctions = ImportFunctions;
	pInitStruct->pfGetVersion = CmpGetVersion;
	pInitStruct->pfHookFunction = HookFunction;
	pInitStruct->pfCreateInstance = NULL;
	pInitStruct->pfDeleteInstance = NULL;

	s_pfCMRegisterAPI = pInitStruct->pfCMRegisterAPI;
	s_pfCMRegisterAPI2 = pInitStruct->pfCMRegisterAPI2;
	s_pfCMGetAPI = pInitStruct->pfCMGetAPI;
	s_pfCMGetAPI2 = pInitStruct->pfCMGetAPI2;
	s_pfCMCallHook = pInitStruct->pfCMCallHook;
	s_pfCMRegisterClass = pInitStruct->pfCMRegisterClass;
	s_pfCMCreateInstance = pInitStruct->pfCMCreateInstance;
	return ERR_OK;
}

/**
 * <description>Publish exported functions to the component manager, to make them available for other components.
 * Use generated macro EXPORT_STMT.</description>
 * <result>ERR_OK or error code in case of error</result>
 */
static int CDECL ExportFunctions(void)
{
	/* Macro to export functions */
	EXPORT_STMT;
	return ERR_OK;
}

/**
 * <description>Import function pointers from other components. Use generated macro IMPORT_STMT.</description>
 * <result>ERR_OK or error code if function name could not be resolved</result>
 */
static int CDECL ImportFunctions(void)
{
	/* Macro to import functions */
	IMPORT_STMT;
	return ERR_OK;
}

/**
 * <description>Return the version of our component.</description>
 * <result>Version as defined in dep file</result>
 */
static RTS_UI32 CDECL CmpGetVersion(void)
{
	return CMP_VERSION;
}

#endif

/* Settings */
#define MAX_FILEPATH_LEN 255
static int s_iMaxFilePathLen = MAX_FILEPATH_LEN - 1;
static char s_szFilePath[MAX_FILEPATH_LEN];

static int s_iMaxFileSize;

static int s_iAutoFlush;

/* Handles */
static RTS_HANDLE s_hEventGetSRAM = RTS_INVALID_HANDLE;
static RTS_HANDLE s_hEventDownloadDone = RTS_INVALID_HANDLE;
static RTS_HANDLE s_hEventFlushRetains = RTS_INVALID_HANDLE;
static RTS_HANDLE s_hFile = RTS_INVALID_HANDLE;
static RTS_BOOL s_bFlushActive;
static void* s_pMem;
static void* s_pFileMem;

/* Functions */
static RTS_RESULT CDECL CreateEvents(void);
static RTS_RESULT CDECL OpenEvents(void);
static RTS_RESULT CDECL RegisterEventCallbacks(void);
static RTS_RESULT CDECL UnregisterEventCallbacks(void);
static RTS_RESULT CDECL CloseEvents(void);
static RTS_RESULT CDECL DeleteEvents(void);
static RTS_RESULT CDECL ReadConfiguration(void);
static RTS_RESULT CDECL MmapFile(void);
static RTS_RESULT CDECL MmapRam(void);
static RTS_RESULT CDECL MunmapFile(void);
static RTS_RESULT CDECL MunmapRam(void);
static void CDECL FlushImpl(void);
static void CDECL FlushRetains(RTS_BOOL bBackground);

/* Task functions */
static void CDECL FlushTask(SYS_TASK_PARAM* pParam);

/* Callbacks */
static void CDECL CBGetSRAM(EventParam* pEventParam);
static void CDECL CBDownloadDone(EventParam* pEventParam);
static void CDECL CBFlushRetains(EventParam* pEventParam);

/**
 * <description>Hook function to get all broadcast hooks of the component manager. All init and exit stuff must be implemented here!</description>
 * <param name="ulHook" type="IN">Kind of hook. See CH_ definitions in CmpItf.h for details.</param> 
 * <param name="ulParam1" type="IN">Hook specific first parameter. See definitions in CmpItf.h for details.</param> 
 * <param name="ulParam2" type="IN">Hook specific second parameter. See definitions in CmpItf.h for details.</param>  
 * <result>Error code</result>
 */
static RTS_RESULT CDECL HookFunction(RTS_UI32 ulHook, RTS_UINTPTR ulParam1, RTS_UINTPTR ulParam2)
{
	switch (ulHook)
	{
		case CH_INIT2:
		{
			if ((ReadConfiguration() != ERR_OK) || (CreateEvents() != ERR_OK) ||
					(OpenEvents() != ERR_OK) || (MmapFile() != ERR_OK) || (MmapRam() != ERR_OK))
			{
				return ERR_FAILED;
			}
			break;
		}
		case CH_INIT3:
		{
			if (RegisterEventCallbacks() != ERR_OK)
			{
				return ERR_FAILED;
			}
			break;
		}
		case CH_COMM_CYCLE:
		{
			/* cyclic */
			break;
		}
		case CH_EXIT3:
		{
			UnregisterEventCallbacks();

			break;
		}
		case CH_EXIT2:
		{
			CloseEvents();
			DeleteEvents();
			FlushRetains(0);
			MunmapRam();
			MunmapFile();
			break;
		}
	}
	return ERR_OK;
}

static RTS_RESULT CDECL CreateEvents(void)
{
	RTS_RESULT res = ERR_FAILED;
	s_hEventFlushRetains = CAL_EventCreate(EVT_FlushRetains, COMPONENT_ID, &res);
	if (s_hEventFlushRetains == RTS_INVALID_HANDLE)
	{
		CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_WARNING, res, 0, "Could not create EVT_FlushRetains");
	}
	return ERR_OK;
}

static RTS_RESULT CDECL OpenEvents(void)
{
	RTS_RESULT res = ERR_FAILED;

	/* open EVT_RetainGetSRAM */
	s_hEventGetSRAM = CAL_EventOpen(EVT_RetainGetSRAM, CMPID_CmpRetain, &res);
	if (s_hEventGetSRAM == RTS_INVALID_HANDLE)
	{
		CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_WARNING, res, 0, "Could not open EVT_RetainGetSRAM");
		return ERR_FAILED;
	}

	/* open EVT_DownloadDone */
	s_hEventDownloadDone = CAL_EventOpen(EVT_DownloadDone, CMPID_CmpApp, &res);
	if (s_hEventDownloadDone == RTS_INVALID_HANDLE)
	{
		CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_WARNING, res, 0, "Could not open EVT_DownloadDone");
		return ERR_FAILED;
	}

	return ERR_OK;
}

static RTS_RESULT CDECL RegisterEventCallbacks(void)
{
	RTS_RESULT res = ERR_FAILED;

	/* Register to EVT_FlushRetains */
	res = CAL_EventRegisterCallbackFunction(s_hEventFlushRetains, CBFlushRetains, 0);
	if (res != ERR_OK)
	{
		CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_WARNING, res, 0, "Could not register callback for EVT_FlushRetains");
		return ERR_FAILED;
	}

	/* Register to EVT_RetainGetSRAM */
	res = CAL_EventRegisterCallbackFunction(s_hEventGetSRAM, CBGetSRAM, 0);
	if (res != ERR_OK)
	{
		CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_WARNING, res, 0, "Could not register callback for EVT_RetainGetSRAM");
		return ERR_FAILED;
	}

	/* Register to EVT_DownloadDone */
	res = CAL_EventRegisterCallbackFunction(s_hEventDownloadDone, CBDownloadDone, 0);
	if (res != ERR_OK)
	{
		CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_WARNING, res, 0, "Could not register callback for EVT_DownloadDone");
		return ERR_FAILED;
	}

	return ERR_OK;
}

static RTS_RESULT CDECL UnregisterEventCallbacks(void)
{
	/* Unregister from EVT_DownloadDone */
	RTS_RESULT res = CAL_EventUnregisterCallbackFunction(s_hEventDownloadDone, CBDownloadDone);
	if (res != ERR_OK)
	{
		CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_WARNING, res, 0, "Could not unregister callback for EVT_DownloadDone");
	}

	/* Unregister from EVT_RetainGetSRAM */
	res = CAL_EventUnregisterCallbackFunction(s_hEventGetSRAM, CBGetSRAM);
	if (res != ERR_OK)
	{
		CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_WARNING, res, 0, "Could not unregister callback for EVT_RetainGetSRAM");
	}

	return ERR_OK;
}

static RTS_RESULT CDECL CloseEvents(void)
{
	RTS_RESULT res = ERR_FAILED;

	res = CAL_EventClose(s_hEventDownloadDone);
	if (res != ERR_OK)
	{
		CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_WARNING, res, 0, "Could not close EVT_DownloadDone");
	}
	s_hEventDownloadDone = RTS_INVALID_HANDLE;

	res = CAL_EventClose(s_hEventGetSRAM);
	if (res != ERR_OK)
	{
		CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_WARNING, res, 0, "Could not close EVT_RetainGetSRAM");
	}
	s_hEventGetSRAM = RTS_INVALID_HANDLE;

	return ERR_OK;
}

static RTS_RESULT CDECL DeleteEvents(void)
{
	RTS_RESULT res = ERR_FAILED;

	res = CAL_EventDelete(s_hEventFlushRetains);
	if (res != ERR_OK)
	{
		CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_WARNING, res, 0, "Could not delete EVT_FlushRetains");
	}
	s_hEventFlushRetains = RTS_INVALID_HANDLE;

	return ERR_OK;
}

static RTS_RESULT CDECL ReadConfiguration(void)
{
	/* read FilePath from config */
	RTS_RESULT res = CAL_SettgGetStringValue(CMPMMAPRETAINS_SECTION_NAME, CMPMMAPRETAINS_KEY_STRING_FILEPATH,
			s_szFilePath, &s_iMaxFilePathLen, CMPMMAPRETAINS_VALUE_STRING_FILEPATH_DEFAULT, 0);
	if (res != ERR_OK)
	{
		CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_WARNING, res, 0, "Could not read FilePath: %i", res);
	}
	/* read MaxFileSize from config */
	res = CAL_SettgGetIntValue(CMPMMAPRETAINS_SECTION_NAME, CMPMMAPRETAINS_KEY_INT_MAXSIZE_BYTES,
			&s_iMaxFileSize, CMPMMAPRETAINS_VALUE_INT_MAXSIZE_BYTES_DEFAULT, 0);
	if (res != ERR_OK)
	{
		CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_WARNING, res, 0, "Could not read MaxFileSize: %i", res);
	}
	/* read AutoFlush from config */
	res = CAL_SettgGetIntValue(CMPMMAPRETAINS_SECTION_NAME, CMPMMAPRETAINS_KEY_INT_AUTOFLUSH,
			&s_iAutoFlush, CMPMMAPRETAINS_KEY_INT_AUTOFLUSH_DEFAULT, 0);
	if (res != ERR_OK)
	{
		CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_WARNING, res, 0, "Could not read AutoFlush: %i", res);
	}

	return ERR_OK;
}

static RTS_RESULT CDECL MmapFile(void)
{
	/* open file */
	RTS_RESULT res = ERR_FAILED;
	s_hFile = CAL_SysFileOpen(s_szFilePath, AM_READ_PLUS, &res);
	if (res != ERR_OK)
	{
		CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_WARNING, res, 0, "Could not open file %s: %i", s_szFilePath, res);
		return ERR_FAILED;
	}
	/* extend/reduce file size */
	res = CAL_SysFileTruncate(s_hFile, s_iMaxFileSize);
	if (res != ERR_OK)
	{
		CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_WARNING, res, 0, "Could not truncate file %s (%i): %i", s_szFilePath, s_hFile, res);
		return ERR_FAILED;
	}
	/* mmap file */
	if (!s_iAutoFlush)
	{
		s_pFileMem = mmap(NULL, s_iMaxFileSize, PROT_WRITE, MAP_SHARED, fileno((FILE*)s_hFile), 0);
	}
	else
	{
		s_pFileMem = mmap(NULL, s_iMaxFileSize, PROT_READ | PROT_WRITE, MAP_SHARED, fileno((FILE*)s_hFile), 0);
	}
	if (s_pFileMem == MAP_FAILED)
	{
		CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_WARNING, res, 0, "Could not mmap file %s with length %i: %s", s_szFilePath, s_iMaxFileSize, strerror(errno));
		return ERR_FAILED;
	}

	return ERR_OK;
}

static RTS_RESULT CDECL MmapRam(void)
{
	if (!s_iAutoFlush)
	{
		s_pMem = mmap(NULL, s_iMaxFileSize, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
		if (s_pMem == MAP_FAILED)
		{
			CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_WARNING, ERR_FAILED, 0, "Could not mmap memory with length %i: %s", s_iMaxFileSize, strerror(errno));
			return ERR_FAILED;
		}

		memcpy(s_pMem, s_pFileMem, s_iMaxFileSize);
	}

	return ERR_OK;
}

static RTS_RESULT CDECL MunmapFile(void)
{
	int res = munmap(s_pFileMem, s_iMaxFileSize);
	if (res < 0)
	{
		CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_WARNING, ERR_FAILED, 0, "Could not munmap memory %p with length %i: %s",
				s_pFileMem, s_iMaxFileSize, strerror(errno));
	}
	s_pFileMem = NULL;

	/* close file */
	res = CAL_SysFileClose(s_hFile);
	if (res != ERR_OK)
	{
		CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_WARNING, res, 0, "Could not close file %s", s_szFilePath);
	}
	s_hFile = RTS_INVALID_HANDLE;

	return ERR_OK;
}

static RTS_RESULT CDECL MunmapRam(void)
{
	if (!s_iAutoFlush)
	{
		int res = munmap(s_pMem, s_iMaxFileSize);
		s_pMem = NULL;
		if (res < 0)
		{
			CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_WARNING, ERR_FAILED, 0, "Could not munmap memory %p with length %i: %s",
					s_pMem, s_iMaxFileSize, strerror(errno));
			return ERR_FAILED;
		}

		return ERR_OK;
	}
	return ERR_OK;
}

static void CDECL FlushImpl(void)
{
	msync(s_pFileMem, s_iMaxFileSize, MS_SYNC);
	CAL_SysFileFlush(s_hFile);
	s_bFlushActive = 0;
}

static void CDECL FlushRetains(RTS_BOOL bBackground)
{
	RTS_RESULT res = CAL_SysCpuTestAndSetBit(&s_bFlushActive, sizeof(s_bFlushActive), 0, 1);
	if (res != ERR_OK)
	{
		return;
	}

	if (!s_iAutoFlush)
	{
		memcpy(s_pFileMem, s_pMem, s_iMaxFileSize);
	}
	if (!bBackground)
	{
		FlushImpl();
	}
	else
	{
		RTS_HANDLE hTask = CAL_SysTaskCreate("FlushTask", FlushTask, NULL, TASKPRIO_ABOVENORMAL_BASE, 0, 0, NULL, &res);
		CAL_SysTaskAutoReleaseOnExit(hTask);
		CAL_SysTaskResume(hTask);
	}
}

static void CDECL FlushTask(SYS_TASK_PARAM* pParam)
{
	RTS_HANDLE hTask = pParam->hTask;

	CAL_SysTaskEnter(hTask);

	FlushImpl();

	CAL_SysTaskLeave(hTask);
	CAL_SysTaskEnd(hTask, 0);
	CAL_SysTaskSetExit(hTask);
}

static void CDECL CBGetSRAM(EventParam* pEventParam)
{
	if (pEventParam->EventId == EVT_RetainGetSRAM)
	{
		EVTPARAM_CmpRetainSRAM* pParam = (EVTPARAM_CmpRetainSRAM*)pEventParam->pParameter;
		pParam->pPhysicalAddress = NULL;
		pParam->ulRetainSize = s_iMaxFileSize;
		if (!s_iAutoFlush)
		{
			pParam->pMappedAddress = s_pMem;
		}
		else
		{
			pParam->pMappedAddress = s_pFileMem;
		}
	}
}

static void CDECL CBDownloadDone(EventParam* pEventParam)
{
	if (pEventParam->EventId == EVT_DownloadDone)
	{
		FlushRetains(0 /* bBackground */);
	}
}

static void CDECL CBFlushRetains(EventParam* pEventParam)
{
	if (pEventParam->EventId == EVT_FlushRetains)
	{
		EVTPARAM_FlushRetains* pParam = (EVTPARAM_FlushRetains*)pEventParam->pParameter;
		FlushRetains(pParam->bBackground);
	}
}
