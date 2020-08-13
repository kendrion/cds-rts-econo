/**
 * <name>SysTarget</name>
 * <description> 
 *	Target specific functions
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2019 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */
SET_COMPONENT_NAME(`SysTarget')
COMPONENT_SOURCES(`SysTarget.c')
COMPONENT_SYSSOURCES(`SysTarget*.c')

COMPONENT_VERSION(`0x03050E28')
COMPONENT_VENDORID(`RTS_VENDORID_3S')

CATEGORY(`System')

USE_ITF(`CMItf.m4')
USE_ITF(`CMUtilsItf.m4')
USE_ITF(`CmpSettingsItf.m4')
USE_ITF(`SysMemItf.m4')
USE_ITF(`SysTargetItf.m4')
USE_ITF(`SysCpuHandlingItf.m4')
USE_ITF(`CmpSIL2Itf.m4')
USE_ITF(`CmpChecksumItf.m4')
USE_ITF(`CmpEventMgrItf.m4')
USE_ITF(`SysSocketItf.m4')

IMPLEMENT_ITF(`SysTargetItf.m4')

OPTIONAL_IMPORTS(
SIL2CheckCallerContext,
CRC32Init,
CRC32Update,
CRC32Finish,
EventCreate3,
EventDelete,
EventPost2,
EventOpen,
EventClose,
EventRegisterCallbackFunction,
EventUnregisterCallbackFunction,
SysSockGetFirstAdapterInfo,
SysSockGetNextAdapterInfo)

REQUIRED_IMPORTS(
CMUtlSafeStrCpy,
CMUtlsnprintf,
CMUtlSafeStrCat,
CMUtlwstrcpy,
CMUtlwstrcat,
CMUtlwstrlen,
CMUtlStrToW,
CMCheckSysTargetSignature,
CMUtlUtf8ToW,
SettgGetWStringValue,
SettgGetStringValue,
SettgGetIntValue,
SettgSetWStringValue,
SettgRemoveKey,
SysMemSwap,
SysMemAllocData,
SysMemFreeData,
SysTargetGetConfiguredNodeName,
SysTargetGetType,
SysTargetGetId,
SysTargetGetVersion)
