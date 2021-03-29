/**
 * <name>CmpPlcWink.c</name>
 * <description> 
 *  Example for an runtime component that implements the PlcWink feature.
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
#include "CmpPlcWinkDep.h"

#include "CmpEventMgrItf.h"
#include "CmpAppItf.h"

USE_STMT

#ifndef RTS_COMPACT_MICRO

DLL_DECL int CDECL ComponentEntry(INIT_STRUCT *pInitStruct)
/*	Used to exchange function pointers between component manager and components.
	Called at startup for each component.
	pInitStruct:			IN	Pointer to structure with:
		pfExportFunctions	OUT Pointer to function that exports component functions
		pfImportFunctions	OUT Pointer to function that imports functions from other components
		pfGetVersion		OUT Pointer to function to get component version
		pfRegisterAPI		IN	Pointer to component manager function to register a API function
		pfGetAPI			IN	Pointer to component manager function to get a API function
		pfCallHook			IN	Pointer to component manager function to call a hook function
	Return					ERR_OK if library could be initialized, else error code
*/
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

/* handle for Event */
static RTS_HANDLE s_hEventInteractiveLogin = RTS_INVALID_HANDLE;
/* callback function */
static void CDECL CBDeviceLogin(EventParam *pEventParam);


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
		case CH_INIT:

			break;
		case CH_INIT2:
			break;
		case CH_INIT3:
			s_hEventInteractiveLogin = CAL_EventOpen(EVT_CmpDevice_InteractiveLogin, CMPID_CmpDevice, NULL);
			CAL_EventRegisterCallbackFunction(s_hEventInteractiveLogin, CBDeviceLogin, 0);
			break;
		case CH_INIT_TASKS:
			break;
		case CH_INIT_COMM:

			break;
		case CH_INIT_FINISHED:
			break;

		/* Cyclic */
		case CH_COMM_CYCLE:
		{

			break;
		}


#ifndef RTS_COMPACT_MICRO
		case CH_EXIT_COMM:
			break;
		case CH_EXIT_TASKS:
			break;
		case CH_EXIT3:
			CAL_EventUnregisterCallbackFunction(s_hEventInteractiveLogin, CBDeviceLogin);
			CAL_EventClose(s_hEventInteractiveLogin);
			break;
		case CH_EXIT2:
			break;
		case CH_EXIT:
		{
			EXIT_STMT;
			break;
		}
#endif

		default:
			break;
	}
	return ERR_OK;
}


/**
* <description>Callback function that is called at login to the device or if someone pressed the "Wink" button in the communication dialog in CODESYS.</description>
* <param name="pEventParam" type="IN">Pointer to event parameter set.
*   pEventParam->pParameter is a pointer to EVTPARAM_CmpDevice_InteractiveLogin.
* </param>
* <result></result>
*/
static void CDECL CBDeviceLogin(EventParam *pEventParam)
{
	if (pEventParam->EventId == EVT_CmpDevice_InteractiveLogin && pEventParam->usVersion >= EVTVERSION_CmpDevice_InteractiveLogin)
	{
		EVTPARAM_CmpDevice_InteractiveLogin *pParam = (EVTPARAM_CmpDevice_InteractiveLogin *)pEventParam->pParameter;

		switch(pParam->ui32LoginCommand)
		{
			case DEV_ILC_IDENTIFY:
				/* Only used for device identification - triggered by the "wink" command in the CODESYS communication page.
				   For example let a LED blink for a few seconds.
				*/
				CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_INFO, ERR_OK, 0, "*** Interactive Login: Identify: blink blink blink ***");
				pParam->rLoginResult = ERR_OK;
				break;
		}
	}
}

