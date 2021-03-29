/*****************************************************************************
*
*	Copyright:		© 3S - Smart Software Solutions GmbH, Kempten
*	Program:		Runtime System for the CoDeSys Soft-Plc
*	Module: 		SysTarget.c
*	Version:		1.0
*	Description:	Implements the SysTarget interface
*	Other components	-
******************************************************************************/

#include "CmpStd.h"
#include "SysTargetDep.h"

USE_STMT

#ifdef CPLUSPLUS
	static CSysTarget *s_pCSysTarget = NULL;
#endif

static RTS_UI32 s_ulTargetVersionMask = SYSTARGETVALUE_INT_TARGET_VERSION_MASK_DEFAULT;
static RTS_UI32 s_ulTargetVersionMaskCompatible = SYSTARGETVALUE_INT_TARGET_VERSION_COMPATIBILITY_MASK_DEFAULT;
static PFSYSTARGETGETSERIALNUMBER_SECURE s_pfSysTargetGetSerialNumber_Secure = NULL;
static RTS_HANDLE s_hEventWriteSetting = RTS_INVALID_HANDLE;
static RTS_HANDLE s_hEventSetNodeName = RTS_INVALID_HANDLE;
static RTS_HANDLE s_hEventSetNodeNameDone = RTS_INVALID_HANDLE;


static RTS_UI32 Pack(RTS_UI32 ulByte0, RTS_UI32 ulByte1, RTS_UI32 ulByte2, RTS_UI32 ulByte3);
static void Unpack(RTS_UI32 ulInput, RTS_UI32* pulByte0, RTS_UI32* pulByte1, RTS_UI32* pulByte2, RTS_UI32* pulByte3);
#if defined(RTS_DEBUG)
	static RTS_RESULT SysTargetModuleTest(void);
#endif
static void CDECL CBWriteSetting(EventParam *pEventParam);


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
	pInitStruct->pfCreateInstance = CreateInstance;
	pInitStruct->pfDeleteInstance = DeleteInstance;

	SysTargetOSInit(pInitStruct);

	s_pfCMRegisterAPI = pInitStruct->pfCMRegisterAPI;
	s_pfCMRegisterAPI2 = pInitStruct->pfCMRegisterAPI2;
	s_pfCMGetAPI = pInitStruct->pfCMGetAPI;
	s_pfCMGetAPI2 = pInitStruct->pfCMGetAPI2;
	s_pfCMCallHook = pInitStruct->pfCMCallHook;
	s_pfCMRegisterClass = pInitStruct->pfCMRegisterClass;
	s_pfCMCreateInstance = pInitStruct->pfCMCreateInstance;

#ifdef CPLUSPLUS
	INIT_LOCALS_STMT;
	s_pCSysTarget = NULL;

	if (pInitStruct->pfCMRegisterClass != NULL)
	{
		RTS_HANDLE hClass = pInitStruct->pfCMRegisterClass(COMPONENT_ID, CLASSID_CSysTarget);
		if (hClass == RTS_INVALID_HANDLE)
			return ERR_FAILED;
	}
#endif
	return ERR_OK;
}

static IBase* CDECL CreateInstance(CLASSID cid, RTS_RESULT *pResult)
{
#ifdef CPLUSPLUS
	if (cid == CLASSID_CSysTarget)
	{
		if (s_pCSysTarget == NULL)
			s_pCSysTarget = static_cast<CSysTarget *>(new CSysTarget());
		return (IBase *)s_pCSysTarget->QueryInterface(s_pCSysTarget, ITFID_IBase, pResult);
	}
#endif
	return NULL;
}

static RTS_RESULT CDECL DeleteInstance(IBase *pIBase)
{
#ifdef CPLUSPLUS
	if (pIBase->Release() == 0)
		s_pCSysTarget = NULL;
	return ERR_OK;
#else
	return ERR_NOTIMPLEMENTED;
#endif
}

static int CDECL ExportFunctions(void)
/*	Export function pointers as api */
{
#ifndef SYSTARGET_DISABLE_EXTREF
	EXPORT_STMT;
#endif
	return ERR_OK;
}

static int CDECL ImportFunctions(void)
/*	Get function pointers of other components */
{
	IMPORT_STMT;
	return ERR_OK;
}

static RTS_UI32 CDECL CmpGetVersion(void)
{
	return CMP_VERSION;
}

#endif /* RTS_COMPACT_MICRO */

static RTS_RESULT CDECL HookFunction(RTS_UI32 ulHook, RTS_UINTPTR ulParam1, RTS_UINTPTR ulParam2)
{
	RTS_RESULT Result = ERR_OK;

	switch (ulHook)
	{
		case CH_INIT:
		{
			INIT_STMT;
			break;
		}
		case CH_INIT2:
		{
			RTS_I32 iValue;

			if (CAL_SettgGetIntValue(COMPONENT_NAME, SYSTARGETKEY_INT_TARGET_VERSION_MASK, &iValue, (int)SYSTARGETVALUE_INT_TARGET_VERSION_MASK_DEFAULT, 0) == ERR_OK)
				s_ulTargetVersionMask = (RTS_UI32)iValue;
			/* Only for backward compatibility! */
			else if (CAL_SettgGetIntValue("CmpDevice", SYSTARGETKEY_INT_TARGET_VERSION_MASK, &iValue, (int)SYSTARGETVALUE_INT_TARGET_VERSION_MASK_DEFAULT, 0) == ERR_OK)
				s_ulTargetVersionMask = (RTS_UI32)iValue;

			if (CAL_SettgGetIntValue(COMPONENT_NAME, SYSTARGETKEY_INT_TARGET_VERSION_COMPATIBILITY_MASK, &iValue, (int)SYSTARGETVALUE_INT_TARGET_VERSION_COMPATIBILITY_MASK_DEFAULT, 0) == ERR_OK)
				s_ulTargetVersionMaskCompatible = (RTS_UI32)iValue;
			/* Only for backward compatibility! */
			else if (CAL_SettgGetIntValue("CmpDevice", SYSTARGETKEY_INT_TARGET_VERSION_COMPATIBILITY_MASK, &iValue, (int)SYSTARGETVALUE_INT_TARGET_VERSION_COMPATIBILITY_MASK_DEFAULT, 0) == ERR_OK)
				s_ulTargetVersionMaskCompatible = (RTS_UI32)iValue;

			s_hEventSetNodeName = RTS_INVALID_HANDLE;
			if (CHK_EventCreate3)
			{
				EventOptions eventOptions;
				eventOptions.flags = EMF_NO_IEC_CALLBACKS;
				eventOptions.nCallbacksPossible = 1;

				s_hEventSetNodeName = CAL_EventCreate3(EVT_SysTarget_SetNodeName, CMPID_SysTarget, &eventOptions, NULL);

				eventOptions.nCallbacksPossible = EVENT_CALLBACKS_NO_LIMIT;
				s_hEventSetNodeNameDone = CAL_EventCreate3(EVT_SysTarget_SetNodeNameDone, CMPID_SysTarget, &eventOptions, NULL);
			}
			break;
		}
		case CH_INIT3:
		{
			if (CHK_EventOpen)
			{
				s_hEventWriteSetting = CAL_EventOpen(EVT_Settg_WriteSetting, CMPID_CmpSettings, NULL);
				CAL_EventRegisterCallbackFunction(s_hEventWriteSetting, CBWriteSetting, 0);
			}
			break;
		}
		case CH_COMM_CYCLE:
		{
#ifdef RTS_COMPACT_MICRO
			return ERR_NO_COMM_CYCLE;
#else
	#if 0
			SysTargetModuleTest();
	#endif
			break;
#endif
		}
		case CH_EXIT3:
		{
			if (CHK_EventClose)
			{
				CAL_EventUnregisterCallbackFunction(s_hEventWriteSetting, CBWriteSetting);
				CAL_EventClose(s_hEventWriteSetting);
				s_hEventWriteSetting = RTS_INVALID_HANDLE;
			}
			break;
		}
		case CH_EXIT2:
		{
			if (CHK_EventDelete)
			{
				CAL_EventDelete(s_hEventSetNodeName);
				s_hEventSetNodeName = RTS_INVALID_HANDLE;
				CAL_EventDelete(s_hEventSetNodeNameDone);
				s_hEventSetNodeNameDone = RTS_INVALID_HANDLE;
			}
			break;
		}		
		case CH_EXIT_SYSTEM:
		{
			EXIT_STMT;
			break;
		}
		default:
			break;
	}
	if(Result == ERR_OK)
	{
		if (ulHook == CH_INIT_SYSTEM)
			  ulParam2 = (RTS_UINTPTR)&s_pfSysTargetGetSerialNumber_Secure;
		return SysTargetOSHookFunction(ulHook, ulParam1, ulParam2);
	}
	return Result;
}

RTS_RESULT CDECL SysTargetGetConfiguredNodeName(RTS_WCHAR *pwszName, RTS_SIZE *pnMaxLength)
{
	if (pnMaxLength != NULL)
	{
		RTS_I32 iLen = (RTS_I32)*pnMaxLength;
		RTS_RESULT Result = CAL_SettgGetWStringValue((const char*)COMPONENT_NAME, (const char*)SYSTARGETKEY_WSTRING_GET_NODENAME_UNICODE, (RTS_WCHAR *)pwszName, &iLen, (RTS_WCHAR *)RTS_WTEXT_EMPTY, 0);

		/* if the buffer is too small, the truncated string is ok here */
		if (Result == ERR_BUFFERSIZE)
			Result = ERR_OK;

		if (Result == ERR_OK)
		{
			if (pwszName != NULL)
				*pnMaxLength = iLen + 1;
			else
				*pnMaxLength = iLen;
		}
		else
		{
			char sz[512];

			iLen = sizeof(sz);
			Result = CAL_SettgGetStringValue(COMPONENT_NAME, SYSTARGETKEY_STRING_GET_NODENAME, sz, &iLen, "", 0);

			/* if the buffer is too small, the truncated string is ok here */
			if (Result == ERR_BUFFERSIZE)
				Result = ERR_OK;

			if (Result == ERR_OK)
			{
				if (pwszName != NULL)
				{
					CAL_CMUtlStrToW(sz, pwszName, *pnMaxLength);
					*pnMaxLength = (unsigned int)CAL_CMUtlwstrlen(pwszName) + 1;
				}
				else
					*pnMaxLength = iLen + 1;
			}
		}
		return Result;
	}
	return ERR_PARAMETER;
}

RTS_RESULT CDECL SysTargetSetNodeName(RTS_WCHAR *pwszName)
{
	RTS_I32 iNameLen = 0;
	RTS_RESULT Result;
	EVTPARAM_SysEvent_SetNodeName Param;

	if (pwszName == NULL)
	{
		return ERR_PARAMETER;
	}

	iNameLen = CAL_CMUtlwstrlen(pwszName);
	if (iNameLen >= SYSTARGET_MAX_NODE_NAME_LEN)
	{
		return ERR_OUT_OF_LIMITS;
	}

	Param.pwszName = pwszName;
	Param.rResult = ERR_OK;
	if (s_hEventSetNodeName != RTS_INVALID_HANDLE && CHK_EventPost2)
	{
		(void)CAL_EventPost2(s_hEventSetNodeName, EVTPARAMID_SysTarget_SetNodeName, EVTVERSION_SysTarget_SetNodeName, &Param);
	}

	if (Param.rResult == ERR_OK)
	{
		/* delete names from settings */
		if (CAL_SettgRemoveKey((const char*)COMPONENT_NAME, (const char*)SYSTARGETKEY_WSTRING_GET_NODENAME_UNICODE) == ERR_NO_ACCESS_RIGHTS)
		{
			return ERR_NO_ACCESS_RIGHTS;
		}
		if (CAL_SettgRemoveKey((const char*)COMPONENT_NAME, (const char*)SYSTARGETKEY_STRING_GET_NODENAME) == ERR_NO_ACCESS_RIGHTS)
		{
			return ERR_NO_ACCESS_RIGHTS;
		}

		if (pwszName[0] != 0)
		{
			Result = CAL_SettgSetWStringValue((const char*)COMPONENT_NAME, (const char*)SYSTARGETKEY_WSTRING_GET_NODENAME_UNICODE, (RTS_WCHAR *)pwszName, iNameLen);
			if (Result == ERR_NO_ACCESS_RIGHTS)
			{
				return ERR_NO_ACCESS_RIGHTS;
			}
			else if (Result == ERR_NOTIMPLEMENTED)
			{
				return ERR_NOT_SUPPORTED;
			}
			else if (Result != ERR_OK)
			{
				return ERR_FAILED;
			}
		}
		Param.pwszName = pwszName;
		Param.rResult = ERR_OK;
		if (s_hEventSetNodeNameDone != RTS_INVALID_HANDLE && CHK_EventPost2)
		{
			(void)CAL_EventPost2(s_hEventSetNodeNameDone, EVTPARAMID_SysTarget_SetNodeName, EVTVERSION_SysTarget_SetNodeName, &Param);
		}
		return ERR_OK;
	}
	else if (Param.rResult == ERR_NOTHING_TO_DO)
	{
		return ERR_OK;
	}
	else if (Param.rResult == ERR_NOT_SUPPORTED || Param.rResult == ERR_OPERATION_DENIED)
	{
		return Param.rResult;
	}
	else
	{
		return ERR_FAILED;
	}
}

/* <SIL2/> */
RTS_RESULT CDECL SysTargetGetType(RTS_UI32 *pulType)
{
	if (pulType == NULL)
		return ERR_PARAMETER;

	*pulType = SYSTARGET_DEVICE_TYPE;
	return ERR_OK;
}

/* <SIL2/> */
RTS_RESULT CDECL SysTargetGetId(RTS_UI32 *pulTargetId)
{
	if (pulTargetId == NULL)
		return ERR_PARAMETER;

	*pulTargetId = ADDVENDORID(SYSTARGET_VENDOR_ID, SYSTARGET_DEVICE_ID);
	return ERR_OK;
}

/* <SIL2/> */
RTS_RESULT CDECL SysTargetGetVersion(RTS_UI32 *pulVersion)
{
#if !defined(RTS_SIL2) && !defined(RTS_COMPACT_MICRO)
	RTS_RESULT Result;
	char szKey[100];
#endif

	if (pulVersion == NULL)
		return ERR_PARAMETER;

#if !defined(RTS_SIL2) && !defined(RTS_COMPACT_MICRO)
	CAL_CMUtlsnprintf(szKey, sizeof(szKey), "%s", SYSTARGETKEY_INT_GET_VERSION);
	Result = CAL_SettgGetIntValue(COMPONENT_NAME, szKey, (RTS_I32 *)pulVersion, (int)*pulVersion, 0);
	if (Result != ERR_OK)
		*pulVersion = SYSTARGET_DEVICE_VERSION;
#else
	*pulVersion = SYSTARGET_DEVICE_VERSION;
#endif
		
	return ERR_OK;
}

RTS_RESULT CDECL SysTargetGetDeviceName(RTS_WCHAR *pwszName, RTS_SIZE *pnMaxLength)
{
#ifndef RTS_COMPACT_MICRO
	RTS_RESULT Result;
	char szKey[100];
	RTS_I32 iLen;
#endif

	if (pnMaxLength == NULL)
		return ERR_PARAMETER;

#ifndef RTS_COMPACT_MICRO
	iLen = (RTS_I32)*pnMaxLength;
	CAL_CMUtlsnprintf(szKey, sizeof(szKey), "%s", SYSTARGETKEY_WSTRING_GET_DEVICENAME_UNICODE);
	Result = CAL_SettgGetWStringValue((const char*)COMPONENT_NAME, (const char*)szKey, (RTS_WCHAR *)pwszName, &iLen, (RTS_WCHAR *)RTS_WTEXT_EMPTY, 0);
	if (Result == ERR_OK)
	{
		*pnMaxLength = iLen + 1;
	}
	else
	{
		char sz[100];
		iLen = sizeof(sz);
	
		CAL_CMUtlsnprintf(szKey, sizeof(szKey), "%s", SYSTARGETKEY_STRING_GET_DEVICENAME);
		Result = CAL_SettgGetStringValue(COMPONENT_NAME, szKey, sz, &iLen, "", 0);
		if (Result == ERR_OK && pnMaxLength != NULL)
		{
			if (pwszName != NULL)
			{
				CAL_CMUtlStrToW(sz, pwszName, *pnMaxLength);
				*pnMaxLength = (unsigned int)CAL_CMUtlwstrlen(pwszName) + 1;
			}
			else
				*pnMaxLength = iLen + 1;
		}
		else
		{
			if (pwszName != NULL && pnMaxLength != NULL)
				CAL_CMUtlStrToW(SYSTARGET_DEVICE_NAME, pwszName, *pnMaxLength);
			if (pnMaxLength != NULL)
				*pnMaxLength = (unsigned int)(strlen(SYSTARGET_DEVICE_NAME) + 1);
		}
	}
#else
    if (pwszName != NULL && pnMaxLength != NULL)
            CAL_CMUtlStrToW(SYSTARGET_DEVICE_NAME, pwszName, *pnMaxLength);
    if (pnMaxLength != NULL)
            *pnMaxLength = (unsigned int)(strlen(SYSTARGET_DEVICE_NAME) + 1);
#endif
	return ERR_OK;
}

RTS_RESULT CDECL SysTargetGetVendorName(RTS_WCHAR *pwszName, RTS_SIZE *pnMaxLength)
{
#ifndef RTS_COMPACT_MICRO
	RTS_RESULT Result;
	char szKey[100];
	RTS_I32 iLen = (RTS_I32)*pnMaxLength;

	CAL_CMUtlsnprintf(szKey, sizeof(szKey), "%s", SYSTARGETKEY_WSTRING_GET_VENDORNAME_UNICODE);
	Result = CAL_SettgGetWStringValue((const char*)COMPONENT_NAME, (const char*)szKey, (RTS_WCHAR *)pwszName, &iLen, (RTS_WCHAR *)RTS_WTEXT_EMPTY, 0);
	if (Result == ERR_OK)
	{
		*pnMaxLength = iLen + 1;
	}
	else
	{
		char sz[100];
		iLen = sizeof(sz);
		
		CAL_CMUtlsnprintf(szKey, sizeof(szKey), "%s", SYSTARGETKEY_STRING_GET_VENDORNAME);		
		Result = CAL_SettgGetStringValue(COMPONENT_NAME, szKey, sz, &iLen, "", 0);
		if (Result == ERR_OK && pnMaxLength != NULL)
		{
			if (pwszName != NULL)
			{
				CAL_CMUtlStrToW(sz, pwszName, *pnMaxLength);
				*pnMaxLength = (unsigned int)CAL_CMUtlwstrlen(pwszName) + 1;
			}
			else
				*pnMaxLength = iLen + 1;
		}
		else
		{
			if (pwszName != NULL && pnMaxLength != NULL)
				CAL_CMUtlStrToW(SYSTARGET_VENDOR_NAME, pwszName, *pnMaxLength);
			if (pnMaxLength != NULL)
				*pnMaxLength = (unsigned int)(strlen(SYSTARGET_VENDOR_NAME) + 1);
		}
	}
#else
    if (pwszName != NULL && pnMaxLength != NULL)
            CAL_CMUtlStrToW(SYSTARGET_VENDOR_NAME, pwszName, *pnMaxLength);
    if (pnMaxLength != NULL)
            *pnMaxLength = (unsigned int)(strlen(SYSTARGET_VENDOR_NAME) + 1);
#endif
	return ERR_OK;
}

RTS_RESULT CDECL SysTargetGetOperatingSystemId(RTS_UI32 *pulOperatingSystemId)
{
	if (pulOperatingSystemId == NULL)
		return ERR_PARAMETER;
	*pulOperatingSystemId = SYSTARGET_OS_ID;
	return ERR_OK;
}

RTS_RESULT CDECL SysTargetGetProcessorId(RTS_UI32 *pulProcessorId)
{
	if (pulProcessorId == NULL)
		return ERR_PARAMETER;
	*pulProcessorId = SYSTARGET_CPU_ID;
	return ERR_OK;
}

RTS_RESULT CDECL SysTargetGetDeviceMask(RTS_UI16 *pusDeviceMask)
{
	if (pusDeviceMask == NULL)
		return ERR_PARAMETER;
	*pusDeviceMask = SYSTARGET_DEVICE_MASK;
	return ERR_OK;
}

static RTS_UI32 Pack(RTS_UI32 ulByte0, RTS_UI32 ulByte1, RTS_UI32 ulByte2, RTS_UI32 ulByte3)
{
	RTS_UI32 ulResult = ulByte3;
	ulResult += (ulByte2 << 8);
	ulResult += (ulByte1 << 16);
	ulResult += (ulByte0 << 24);
	return ulResult;
}

static void Unpack(RTS_UI32 ulInput, RTS_UI32* pulByte0, RTS_UI32* pulByte1, RTS_UI32* pulByte2, RTS_UI32* pulByte3)
{
	*pulByte0 = (ulInput >> 24) & 0xFF;
	*pulByte1 = (ulInput >> 16) & 0xFF;
	*pulByte2 = (ulInput >> 8) & 0xFF;
	*pulByte3 = ulInput & 0xFF;
}

RTS_RESULT CDECL SysTargetGetSignature(RTS_UI32 ulChallenge, RTS_UI32 *pulSignature)
{
	RTS_UI32 h0, h1, h2, h3;
	RTS_UI32 x0, x1, x2, x3;
	RTS_UI32 k0, k1, k2, k3;
	RTS_UI32 r0, r1, r2, r3;

	if (ulChallenge == 0 || pulSignature == NULL)
		return ERR_PARAMETER;

	/* Crypt CRC32 with the callenge */
	Unpack(SYSTARGET_SIGNATUREID, &h0, &h1, &h2, &h3);
	Unpack(ulChallenge, &k0, &k1, &k2, &k3);

	x0 = h2 ^ k3;
	x1 = h1 ^ k0;
	x2 = h0 ^ k2;
	x3 = h3 ^ k1;

	x0 ^= 0xC0;
	x1 ^= 0xDE;
	x2 ^= 0x51;
	x3 ^= 0x50;

	r0 = x1 ^ k2;
	r1 = x0 ^ k1;
	r2 = x3 ^ k3;
	r3 = x2 ^ k0;

	*pulSignature = Pack(r0, r1, r2, r3);
	return ERR_OK;
}

RTS_RESULT CDECL SysTargetGetSerialNumber_Secure(char **ppszSerialNumber, RTS_I32 *pnMaxLen)
{
	if (s_pfSysTargetGetSerialNumber_Secure != NULL)
		return s_pfSysTargetGetSerialNumber_Secure(ppszSerialNumber, pnMaxLen);
	return ERR_NOTIMPLEMENTED;
}

RTS_RESULT CDECL SysTargetCheckIdent(SysTargetIdent *pTargetIdentReq, SysTargetIdent *pTargetIdent)
{
	SysTargetIdent ti;

	if (pTargetIdentReq == NULL)
		return ERR_PARAMETER;

	if (pTargetIdent == NULL)
	{
		CAL_SysTargetGetType(&ti.ulTargetType);
		CAL_SysTargetGetId(&ti.ulTargetId);
		CAL_SysTargetGetVersion(&ti.ulTargetVersion);
		pTargetIdent = &ti;
	}

	/* Type check */
	if (pTargetIdentReq->ulTargetType != 0 && pTargetIdentReq->ulTargetType != pTargetIdent->ulTargetType)
		return ERR_TYPE_MISMATCH;
	
	/* ID check */
	if (pTargetIdentReq->ulTargetId != 0 && pTargetIdentReq->ulTargetId != pTargetIdent->ulTargetId)
		return ERR_ID_MISMATCH;

	/* Version check */
	/* Deny if DevDesc version is newer */ 
	if (pTargetIdentReq->ulTargetVersion != 0 && ((pTargetIdentReq->ulTargetVersion & s_ulTargetVersionMask) != (pTargetIdent->ulTargetVersion & s_ulTargetVersionMask)))
		return ERR_VERSION_MISMATCH;

	/* Deny if DevDesc version is not lower or equal the target version filtered by the compatibility mask */ 
	if (pTargetIdentReq->ulTargetVersion != 0 && s_ulTargetVersionMaskCompatible != 0 && 
		((pTargetIdentReq->ulTargetVersion & s_ulTargetVersionMaskCompatible) > (pTargetIdent->ulTargetVersion & s_ulTargetVersionMaskCompatible)))
		return ERR_VERSION_MISMATCH;
	return ERR_OK;
}

RTS_RESULT CDECL SysTargetGetAPI(API_RESOLVE_INFO apiInfo, RTS_VOID_FCTPTR *ppfAPIFunction)
{
	return ERR_NOTIMPLEMENTED;
}

static void CDECL CBWriteSetting(EventParam *pEventParam)
{
	switch (pEventParam->EventId)
	{
		case EVT_Settg_WriteSetting:
		{
			EVTPARAM_SettgWriteSetting *pParam = (EVTPARAM_SettgWriteSetting *)pEventParam->pParameter;
			
			if (pParam != NULL &&
				pParam->entry.pszComponentName != NULL &&
				strcmp(pParam->entry.pszComponentName, COMPONENT_NAME) == 0)
			{
				if (pParam->entry.pszKey != NULL)
				{
					if (strcmp(pParam->entry.pszKey, SYSTARGETKEY_STRING_GET_NODENAME) == 0 && pParam->entry.flags &  CMPSETTINGS_FLAGS_EDITABLE)
					{
						if ((pParam->entry.setting.editableSetting.flags & CMPSETTINGS_EFLAGS_EDITABLE_STRING) &&
							pParam->entry.setting.editableSetting.value.pStringSetting != NULL)
						{
							RTS_WCHAR *pwszNodeName;
							char *pszNodeName = pParam->entry.setting.editableSetting.value.pStringSetting;
							RTS_SIZE wstrLen = (RTS_SIZE)strlen(pszNodeName) + 1;

							pwszNodeName = (RTS_WCHAR*)CAL_SysMemAllocData(COMPONENT_NAME, wstrLen * sizeof(RTS_WCHAR), NULL);

							if (CAL_CMUtlUtf8ToW((RTS_UI8 *)pszNodeName, strlen(pszNodeName) + 1, pwszNodeName, wstrLen) == ERR_OK)
							{
								if (CAL_SysTargetSetNodeName(pwszNodeName) == ERR_OK)
									pParam->Result = ERR_NOTHING_TO_DO;
							}

							CAL_SysMemFreeData(COMPONENT_NAME, pwszNodeName);
						}
						else if ((pParam->entry.setting.editableSetting.flags & CMPSETTINGS_EFLAGS_EDITABLE_WSTRING) &&
							pParam->entry.setting.editableSetting.value.pWStringSetting != NULL)
						{
							if (CAL_SysTargetSetNodeName(pParam->entry.setting.editableSetting.value.pWStringSetting) == ERR_OK)
								pParam->Result = ERR_NOTHING_TO_DO;
						}
					}
				}
			}
			break;
		}
		default:
			break;
	}
}

#ifndef SYSTARGET_DISABLE_EXTREF
/* <SIL2/> */
void CDECL CDECL_EXT systargetgetvendorname(systargetgetvendorname_struct *p)
{
#ifdef RTS_SIL2
	if (CHK_SIL2CheckCallerContext && CAL_SIL2CheckCallerContext(RTS_SIL2_CALLERCTX_UNSAFE) != ERR_OK)
		return;
#endif
	p->SysTargetGetVendorName = SysTargetGetVendorName(p->pwszName, (RTS_SIZE *)p->pnMaxLength);
}

/* <SIL2/> */
void CDECL CDECL_EXT systargetgetversion(systargetgetversion_struct *p)
{
#ifdef RTS_SIL2
	if (CHK_SIL2CheckCallerContext && CAL_SIL2CheckCallerContext(RTS_SIL2_CALLERCTX_UNSAFE) != ERR_OK)
		return;
#endif
	p->SysTargetGetVersion = CAL_SysTargetGetVersion(p->pulVersion);
}

/* <SIL2/> */
void CDECL CDECL_EXT systargetgetnodename(systargetgetnodename_struct *p)
{
#ifdef RTS_SIL2
	if (CHK_SIL2CheckCallerContext && CAL_SIL2CheckCallerContext(RTS_SIL2_CALLERCTX_UNSAFE) != ERR_OK)
		return;
#endif
	p->SysTargetGetNodeName = SysTargetGetNodeName(p->pwszName, (RTS_SIZE *)p->pnMaxLength);
}

/* <SIL2/> */
void CDECL CDECL_EXT systargetgetdevicename(systargetgetdevicename_struct *p)
{
#ifdef RTS_SIL2
	if (CHK_SIL2CheckCallerContext && CAL_SIL2CheckCallerContext(RTS_SIL2_CALLERCTX_UNSAFE) != ERR_OK)
		return;
#endif
	p->SysTargetGetDeviceName = SysTargetGetDeviceName(p->pwszName, (RTS_SIZE *)p->pnMaxLength);
}

/* <SIL2/> */
void CDECL CDECL_EXT systargetgetid(systargetgetid_struct *p)
{
#ifdef RTS_SIL2
	if (CHK_SIL2CheckCallerContext && CAL_SIL2CheckCallerContext(RTS_SIL2_CALLERCTX_UNSAFE) != ERR_OK)
		return;
#endif
	p->SysTargetGetId = CAL_SysTargetGetId(p->pulTargetId);
}

/* <SIL2/> */
void CDECL CDECL_EXT systargetgetvendorname2(systargetgetvendorname2_struct *p)
{
#ifdef RTS_SIL2
	if (CHK_SIL2CheckCallerContext && CAL_SIL2CheckCallerContext(RTS_SIL2_CALLERCTX_UNSAFE) != ERR_OK)
		return;
#endif
	p->SysTargetGetVendorName2 = SysTargetGetVendorName(p->pwszName, (RTS_SIZE *)p->pnMaxLength);
}

/* <SIL2/> */
void CDECL CDECL_EXT systargetgettype(systargetgettype_struct *p)
{
#ifdef RTS_SIL2
	if (CHK_SIL2CheckCallerContext && CAL_SIL2CheckCallerContext(RTS_SIL2_CALLERCTX_UNSAFE) != ERR_OK)
		return;
#endif
	p->SysTargetGetType = CAL_SysTargetGetType(p->pulType);
}

/* <SIL2/> */
void CDECL CDECL_EXT systargetgetnodename2(systargetgetnodename2_struct *p)
{
#ifdef RTS_SIL2
	if (CHK_SIL2CheckCallerContext && CAL_SIL2CheckCallerContext(RTS_SIL2_CALLERCTX_UNSAFE) != ERR_OK)
		return;
#endif
	p->SysTargetGetNodeName2 = SysTargetGetNodeName(p->pwszName, (RTS_SIZE *)p->pnMaxLength);
}

/* <SIL2/> */
void CDECL CDECL_EXT systargetgettype2(systargetgettype2_struct *p)
{
#ifdef RTS_SIL2
	if (CHK_SIL2CheckCallerContext && CAL_SIL2CheckCallerContext(RTS_SIL2_CALLERCTX_UNSAFE) != ERR_OK)
		return;
#endif
	p->SysTargetGetType2 = CAL_SysTargetGetType(p->pulType);
}

/* <SIL2/> */
void CDECL CDECL_EXT systargetgetversion2(systargetgetversion2_struct *p)
{
#ifdef RTS_SIL2
	if (CHK_SIL2CheckCallerContext && CAL_SIL2CheckCallerContext(RTS_SIL2_CALLERCTX_UNSAFE) != ERR_OK)
		return;
#endif
	p->SysTargetGetVersion2 = CAL_SysTargetGetVersion(p->pulVersion);
}

/* <SIL2/> */
void CDECL CDECL_EXT systargetgetdevicename2(systargetgetdevicename2_struct *p)
{
#ifdef RTS_SIL2
	if (CHK_SIL2CheckCallerContext && CAL_SIL2CheckCallerContext(RTS_SIL2_CALLERCTX_UNSAFE) != ERR_OK)
		return;
#endif
	p->SysTargetGetDeviceName2 = SysTargetGetDeviceName(p->pwszName, (RTS_SIZE *)p->pnMaxLength);
}

/* <SIL2/> */
void CDECL CDECL_EXT systargetgetid2(systargetgetid2_struct *p)
{
#ifdef RTS_SIL2
	if (CHK_SIL2CheckCallerContext && CAL_SIL2CheckCallerContext(RTS_SIL2_CALLERCTX_UNSAFE) != ERR_OK)
		return;
#endif
	p->SysTargetGetId2 = CAL_SysTargetGetId(p->pulTargetId);
}

/* <SIL2/> */
void CDECL CDECL_EXT systargetgetprocessorid(systargetgetprocessorid_struct *p)
{
#ifdef RTS_SIL2
	if (CHK_SIL2CheckCallerContext && CAL_SIL2CheckCallerContext(RTS_SIL2_CALLERCTX_UNSAFE) != ERR_OK)
		return;
#endif
	p->SysTargetGetProcessorId = SysTargetGetProcessorId(p->pudiProcessorId);
}

/* <SIL2/> */
void CDECL CDECL_EXT systargetgetoperatingsystemid(systargetgetoperatingsystemid_struct *p)
{
#ifdef RTS_SIL2
	if (CHK_SIL2CheckCallerContext && CAL_SIL2CheckCallerContext(RTS_SIL2_CALLERCTX_UNSAFE) != ERR_OK)
		return;
#endif
	p->SysTargetGetOperatingSystemId = SysTargetGetOperatingSystemId(p->pudiOperatingSystemId);
}

/* <SIL2/> */
void CDECL CDECL_EXT systargetgetserialnumber(systargetgetserialnumber_struct *p)
{
#ifdef RTS_SIL2
	if (CHK_SIL2CheckCallerContext && CAL_SIL2CheckCallerContext(RTS_SIL2_CALLERCTX_UNSAFE) != ERR_OK)
		return;
#endif
	p->SysTargetGetSerialNumber = SysTargetGetSerialNumber(p->ppsSerialNumber, (RTS_I32 *)p->pnMaxLen);
}
#endif

/* pnMaxLen: Buffer size (= strlen + 1) */
RTS_RESULT CDECL SysTargetGetSerialNumber(char **ppszSerialNumber, RTS_I32 *pnMaxLen)
{
	static RTS_CSTRING s_szTargetSerialNumber[256] = { 0 };
	static RTS_I32 s_iNeededSerNoBufSize = 0; /* Buffer size (= strlen + 1) */

	if (pnMaxLen == NULL)
		return ERR_PARAMETER;
	
	if (s_szTargetSerialNumber[0] == '\0')
	{
		RTS_RESULT rResult;
		RTS_CSTRING *pszSerialNumber = s_szTargetSerialNumber;

		s_iNeededSerNoBufSize = sizeof(s_szTargetSerialNumber);
		rResult = SysTargetGetSerialNumber_(&pszSerialNumber, &s_iNeededSerNoBufSize);

		if ((rResult != ERR_OK) || (s_iNeededSerNoBufSize < 2) || (s_szTargetSerialNumber[0] == '\0'))
		{
			RTS_I32 i32NeededSerNoStrLen = sizeof(s_szTargetSerialNumber) - 1;
			rResult = CAL_SettgGetStringValue(COMPONENT_NAME, SYSTARGETKEY_STRING_SERIAL_NUMBER, s_szTargetSerialNumber, &i32NeededSerNoStrLen, "", 0);
			s_iNeededSerNoBufSize = i32NeededSerNoStrLen + 1;
		}

		if ((rResult != ERR_OK) || (s_iNeededSerNoBufSize < 2) || (s_szTargetSerialNumber[0] == '\0'))
		{
			static const RTS_CSTRING s_sz_PREFIX[] = "RTS-";

			if (CHK_CryptoGenerateRandomNumber)
			{
				RTS_UI64 ui64SerialNumber;
				RtsByteString temp;
				temp.pByData = (RTS_IEC_BYTE*)&ui64SerialNumber;
				temp.ui32Len = 0;
				temp.ui32MaxLen = sizeof(ui64SerialNumber);
				rResult = CAL_CryptoGenerateRandomNumber(sizeof(ui64SerialNumber), &temp);

				CAL_CMUtlsnprintf(s_szTargetSerialNumber, sizeof(s_szTargetSerialNumber), "%s%016" PRI_X64, s_sz_PREFIX, ui64SerialNumber);
				s_iNeededSerNoBufSize = strlen(s_szTargetSerialNumber) + 1;
			}

			if ((rResult != ERR_OK) || (s_iNeededSerNoBufSize < 2) || (s_szTargetSerialNumber[0] == '\0'))
			{
				if (CHK_SysSockGetFirstAdapterInfo && CHK_SysTimeGetMs)
				{
					static const RTS_UI64 ui64_NULL = UINT64_C(0);
					SOCK_ADAPTER_INFO *pAdapterInfo = CAL_SysSockGetFirstAdapterInfo(&rResult);
					if (pAdapterInfo != NULL)
					{
						while ((rResult == ERR_OK) && (memcmp(pAdapterInfo->aui8Mac, &ui64_NULL, 6) == 0))
						{
							pAdapterInfo = CAL_SysSockGetNextAdapterInfo(pAdapterInfo, &rResult);
						}
						if (rResult == ERR_OK)
						{
							RTS_UI16 ui16RandNumber;
							RTS_INT iSeed = (RTS_INT)CAL_SysTimeGetMs(); /* SysTimeGetMs() returns RTS_UI32 */
							if (CHK_SysTimeGetUs)
							{
								RTS_SYSTIME sysTime;
								CAL_SysTimeGetUs(&sysTime);
								iSeed ^= (RTS_INT)sysTime;
							}
							srand(iSeed);
							(void)rand(); /* Skip first */
							ui16RandNumber = (RTS_UI16)rand(); /* range: 0 to 0x7FFF */
							CAL_CMUtlsnprintf(s_szTargetSerialNumber, sizeof(s_szTargetSerialNumber),
								"%s%02" PRI_X8 "%02" PRI_X8 "%02" PRI_X8 "%02" PRI_X8 "%02" PRI_X8 "%02" PRI_X8 "%04" PRI_X16,
								s_sz_PREFIX,
								pAdapterInfo->aui8Mac[0], pAdapterInfo->aui8Mac[1], pAdapterInfo->aui8Mac[2],
								pAdapterInfo->aui8Mac[3], pAdapterInfo->aui8Mac[4], pAdapterInfo->aui8Mac[5],
								ui16RandNumber);
							s_iNeededSerNoBufSize = strlen(s_szTargetSerialNumber) + 1;
						}
					}
					else
						if (rResult == ERR_OK)
							rResult = ERR_FAILED;
				}
			}

			if ((rResult == ERR_OK) && (s_iNeededSerNoBufSize > 1) && (s_szTargetSerialNumber[0] != '\0'))
			{
				rResult = CAL_SettgSetStringValue(COMPONENT_NAME, SYSTARGETKEY_STRING_SERIAL_NUMBER, s_szTargetSerialNumber, s_iNeededSerNoBufSize - 1);
				if (rResult != ERR_OK)
				{
					/* If the settings are not writable (SettingsEmbedded) no serial number should be generated.
					 * Otherwise the device gets a different serial number every time this function is called.
					 */
					s_szTargetSerialNumber[0] = '\0';
					s_iNeededSerNoBufSize = 0;
				}
			}
		}
	}

	if (ppszSerialNumber == NULL)
	{
		*pnMaxLen = s_iNeededSerNoBufSize;
		return ERR_OK;
	}
	*pnMaxLen = MIN(s_iNeededSerNoBufSize, *pnMaxLen);

	if (*ppszSerialNumber == NULL)
	{
		*ppszSerialNumber = s_szTargetSerialNumber;
		return ERR_OK;
	}
	return CAL_CMUtlSafeStrCpy(*ppszSerialNumber, *pnMaxLen, s_szTargetSerialNumber);
}

#if defined(RTS_DEBUG)
static RTS_RESULT SysTargetModuleTest(void)
{
	/* ONLY FOR TESTING */
	static int s_bDebug = 1;
	char sz[64] = {0};
	char szSafe[64] = {0};
	RTS_I32 nMaxLen;

	if (s_bDebug)
	{
		char *psz = sz;
		RTS_RESULT result;
		int errors = 0;
		
		s_bDebug = 0;

		CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_DEBUG, ERR_OK, 0, "========= SysTarget test begin =========");

		psz = sz;
		nMaxLen = sizeof(sz);
		result = SysTargetGetSerialNumber(&psz, &nMaxLen);
		if (result == ERR_OK)
			CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_DEBUG, ERR_OK, 0, "SerialNumber\t\t= %s", psz);
		else
		{
			CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_DEBUG, ERR_OK, 0, "SerialNumber not supported: Result=%ld", result);
			errors++;
		}

		psz = szSafe;
		nMaxLen = sizeof(sz);
		result = SysTargetGetSerialNumber_Secure(&psz, &nMaxLen);
		if (result == ERR_OK)
			CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_DEBUG, ERR_OK, 0, "SerialNumber_Secure\t= %s", psz);
		else
		{
			CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_DEBUG, ERR_OK, 0, "SerialNumber_Secure not supported: Result=%ld", result);
			errors++;
		}
		memset(psz, 0, nMaxLen);
		nMaxLen = 32;
		result = SysTargetGetSerialNumber_Secure(&psz, &nMaxLen);
		if (result == ERR_OK)
			CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_DEBUG, ERR_OK, 0, "SerialNumber_Secure, trunc\t= %s", psz);
		else
		{
			CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_DEBUG, ERR_OK, 0, "SerialNumber_Secure not supported: Result=%ld", result);
			errors++;
		}
		
		CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_DEBUG, ERR_OK, 0, "========= SysTarget test end: Errors = %ld =========", errors);	
	}
	return ERR_OK;
}
#endif
