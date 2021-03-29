/**
 * <name>CmpUserDBTemplate</name>
 * <description> 
 *	<p>An example on how to implement the user, group, and object databases and their configuration for the user management.</p>
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */
SET_COMPONENT_NAME(`CmpUserDBTemplate')
COMPONENT_SOURCES(`CmpUserDBTemplate.c')

COMPONENT_VERSION(`0x0305100A')

/* NOTE: REPLACE 0x0001 BY YOUR VENDORID */
COMPONENT_VENDORID(`0x0001')

#define CMPID_CmpUserDBTemplate		0x2000								/* NOTE: START HERE WITH YOUR COMPONENTIDS (see CmpItf.h */
#define CLASSID_CCmpUserDBTemplate	ADDVENDORID(CMP_VENDORID, 0x2000)	/* NOTE: START HERE WITH YOUR CLASSIDS (see CmpItf.h */
#define ITFID_ICmpUserDBTemplate		ADDVENDORID(CMP_VENDORID, 0x2000)	/* NOTE: START HERE WITH YOUR INTERFACEIDS (see CmpItf.h */

CATEGORY(`Templates')

IMPLEMENT_ITF(`CmpUserDBItf.m4',`CmpUserDBConfigurationItf.m4',`CmpUserGroupsDBItf.m4',`CmpUserGroupsDBConfigurationItf.m4',`CmpUserObjectsDBItf.m4',`CmpUserObjectsDBConfigurationItf.m4')

USE_ITF(`CMUtilsItf.m4')
USE_ITF(`CmpUserMgrItf.m4')
USE_ITF(`CmpCryptMD5Itf.m4')
USE_ITF(`CmpSrvItf.m4')
USE_ITF(`SysFileItf.m4')
USE_ITF(`CmpEventMgrItf.m4')
USE_ITF(`CmpDeviceItf.m4')

REQUIRED_IMPORTS(
CMUtlSafeStrCpy,
CMUtlStrRChr,
UserMgrGroupHasUser,
UserMgrIsAdministrator,
UserMgrRegisterUserDB,
UserMgrRegisterUserDBConfig,
UserMgrRegisterUserGroupsDB,
UserMgrRegisterUserGroupsDBConfig,
UserMgrRegisterUserObjectsDB,
UserMgrRegisterUserObjectsDBConfig,
UserMgrUnregisterUserDB,
UserMgrUnregisterUserDBConfig,
UserMgrUnregisterUserGroupsDB,
UserMgrUnregisterUserGroupsDBConfig,
UserMgrUnregisterUserObjectsDB,
UserMgrUnregisterUserObjectsDBConfig,
CryptMD5Calculate,
ServerGenerateSessionId,
SysFileOpen,
SysFileClose,
SysFileWrite,
SysFileRead,
SysFileDelete,
SysFileAddToBlacklist,
EventOpen,
EventRegisterCallbackFunction,
EventUnregisterCallbackFunction,
EventClose)
