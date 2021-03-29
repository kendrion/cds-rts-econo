/*****************************************************************************
*
*	Copyright:		� 3S - Smart Software Solutions GmbH, Kempten
*	Program:		Runtime System for the CoDeSys Soft-Plc
*	Module: 		System compontent - Tasks
*	Version:
*	Description:
******************************************************************************/

#ifndef STATICITF_DEF
	#define STATICITF_DEF	static
#endif

#include "CmpStd.h"
#include "CmpSysLogDep.h"

/* conflicting with syslog.h */
#undef LOG_INFO
#undef LOG_WARNING
#undef LOG_DEBUG	

#include <syslog.h>

USE_STMT

DECLARE_ADDREF
DECLARE_RELEASE
DECLARE_QUERYINTERFACE

typedef struct
{
	IBase Base;
	ICmpLog Out;
	ICmpLogBackend Log;
} IAllCmpSysLog;

DLL_DECL int CDECL ComponentEntry(INIT_STRUCT *pInitStruct)
{
	pInitStruct->CmpId = COMPONENT_ID;
	pInitStruct->pfExportFunctions = ExportFunctions;
	pInitStruct->pfImportFunctions = ImportFunctions;
	pInitStruct->pfGetVersion = CmpGetVersion;
	pInitStruct->pfHookFunction = HookFunction;
	pInitStruct->pfCreateInstance = CreateInstance;
	pInitStruct->pfDeleteInstance = DeleteInstance;

	s_pfCMRegisterAPI = pInitStruct->pfCMRegisterAPI;
	s_pfCMRegisterAPI2 = pInitStruct->pfCMRegisterAPI2;
	s_pfCMGetAPI = pInitStruct->pfCMGetAPI;
	s_pfCMGetAPI2 = pInitStruct->pfCMGetAPI2;
	s_pfCMCallHook = pInitStruct->pfCMCallHook;
	s_pfCMRegisterClass = pInitStruct->pfCMRegisterClass;
	s_pfCMCreateInstance = pInitStruct->pfCMCreateInstance;

	if (pInitStruct->pfCMRegisterClass != NULL)
		pInitStruct->pfCMRegisterClass(COMPONENT_ID, CLASSID_CCmpSysLog);
	return ERR_OK;
}

static IBase* CDECL CreateInstance(CLASSID cid, RTS_RESULT *pResult)
{
	if (cid == CLASSID_CCmpSysLog)
	{
		static IAllCmpSysLog CmpSysLog;
		CmpSysLog.Base.bIEC = 0;
		CmpSysLog.Base.QueryInterface = QueryInterface;
		CmpSysLog.Base.AddRef = AddRef;
		CmpSysLog.Base.Release = Release;
		return (IBase *)&CmpSysLog.Base;
	}
	return NULL;
}

static RTS_RESULT CDECL DeleteInstance(IBase *pIBase)
{
	return ERR_OK;
}

static int CDECL ExportFunctions(void)
{
	EXPORT_STMT;
	return ERR_OK;
}

static int CDECL ImportFunctions(void)
{
	IMPORT_STMT;
	return ERR_OK;
}

static RTS_UI32 CDECL CmpGetVersion(void)
{
	return CMP_VERSION;
}

static RTS_RESULT CDECL HookFunction(RTS_UI32 ulHook, RTS_UINTPTR ulParam1, RTS_UINTPTR ulParam2)
{
	switch (ulHook)
	{
		case CH_INIT_SYSTEM:
		{
			openlog("codesyscontrol", LOG_CONS, LOG_USER);
			break;
		}
		case CH_EXIT_SYSTEM:
		{
			EXIT_STMT;
			closelog();
			break;
		}
		default:
			break;
	}
	return ERR_OK;
}

IMPLEMENT_ADDREF
IMPLEMENT_RELEASE

static void *CDECL QueryInterface(IBase *pBase, ITFID iid, RTS_RESULT *pResult)
{
	if (iid == ITFID_IBase)
	{
		/* Every interface has as first element a pointer ro the IBase interface. So it doesn't matter, which interface
		   is used to get the IBase pointer */
		ICmpLog *pI = (ICmpLog *)pBase;
		pI->pBase->iRefCount++;
		return pI->pBase;
	}
	if (iid == ITFID_ICmpLogBackend)
	{
		IAllCmpSysLog *pI = (IAllCmpSysLog*)pBase;
		pI->Log.pBase = pBase;
		pI->Log.ILogBackendCreate = LogBackendCreate;
		pI->Log.ILogBackendDelete = LogBackendDelete;
		pI->Log.ILogBackendAdd = LogBackendAdd;
		pBase->iRefCount++;
		return &pI->Log;
	}
	return NULL;
}

STATICITF RTS_HANDLE CDECL LogBackendCreate(RTS_HANDLE hICmpLogBackend, CLASSID Class, LogOptions *pOptions)
{
	return (RTS_HANDLE)((RTS_UINTPTR)1);
}

STATICITF RTS_RESULT CDECL LogBackendDelete(RTS_HANDLE hLogOut)
{
	return ERR_OK;
}

STATICITF RTS_HANDLE CDECL LogBackendAdd(RTS_HANDLE hLogOut, LogOptions *pOptions, LogEntry *pLog, RTS_RESULT *pResult)
{
	char sz[30];
	int prio;

	if (CAL_CMGetCmpName(pLog->CmpId, sz, sizeof(sz)) != ERR_OK)
		CAL_CMUtlSafeStrCpy(sz, sizeof(sz), "***");
	switch(pLog->iClassID)
	{
		case 0x10 /*LOG_DEBUG*/:
		case LOG_PRINTF:
		{
			prio = LOG_DEBUG;
			break;
		}
		case 2 /*LOG_WARNING*/:
		{
			prio = LOG_WARNING;
			break;
		}
		case LOG_ERROR:
		{
			prio = LOG_ERR;
			break;
		}
		case LOG_EXCEPTION:
		{
			prio = LOG_CRIT;
			break;
		}
		default:
		{
			prio = LOG_INFO;
			break;
		}

	}
	syslog(prio, "%s: %s\n", sz, pLog->szInfo);

	if (pResult != NULL)
		*pResult = ERR_OK;

	return hLogOut;
}
