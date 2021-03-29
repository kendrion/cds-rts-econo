 /**
 * <interfacename>CmpUserGroupsDBConfiguration</interfacename>
 * <description> 
 *	This interface is used to configure the user groups of the a user management.
 *
*   If a user group database is not configurable (e.g. the implementation depends on the operating system) this interface must not be implemented by the
 *  user group database component. This allows only the authentication of users from different clients but not the configuration of user groups using the 
 *  CODESYS online services.
 * </description>
 *
 * <copyright>
 * Copyright (c) 2019 CODESYS Development GmbH. All rights reserved.
 * </copyright>
 */


	
	
#ifndef _CMPUSERGROUPSDBCONFIGURATIONITF_H_
#define _CMPUSERGROUPSDBCONFIGURATIONITF_H_

#include "CmpStd.h"

 

 




STATICITF_DEF RTS_RESULT CDECL UserGroupsDBConfigRelease(RTS_HANDLE hDatabase);
typedef RTS_RESULT (CDECL * PFUSERGROUPSDBCONFIGRELEASE) (RTS_HANDLE hDatabase);
#if defined(CMPUSERGROUPSDBCONFIGURATION_NOTIMPLEMENTED) || defined(USERGROUPSDBCONFIGRELEASE_NOTIMPLEMENTED)
	#define USE_UserGroupsDBConfigRelease
	#define EXT_UserGroupsDBConfigRelease
	#define GET_UserGroupsDBConfigRelease(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserGroupsDBConfigRelease(p0)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserGroupsDBConfigRelease  FALSE
	#define EXP_UserGroupsDBConfigRelease  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserGroupsDBConfigRelease
	#define EXT_UserGroupsDBConfigRelease
	#define GET_UserGroupsDBConfigRelease(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigRelease(p0) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigRelease(((ICmpUserGroupsDBConfiguration*)p0)->pBase->hInstance))
	#define CHK_UserGroupsDBConfigRelease  TRUE
	#define EXP_UserGroupsDBConfigRelease  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSERGROUPSDBCONFIGURATION_EXTERNAL)
	#define USE_UserGroupsDBConfigRelease
	#define EXT_UserGroupsDBConfigRelease
	#define GET_UserGroupsDBConfigRelease(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigRelease(p0) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigRelease(((ICmpUserGroupsDBConfiguration*)p0)->pBase->hInstance))
	#define CHK_UserGroupsDBConfigRelease  TRUE
	#define EXP_UserGroupsDBConfigRelease  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserGroupsDBConfigurationUserGroupsDBConfigRelease
	#define EXT_CmpUserGroupsDBConfigurationUserGroupsDBConfigRelease
	#define GET_CmpUserGroupsDBConfigurationUserGroupsDBConfigRelease  ERR_OK
	#define CAL_CmpUserGroupsDBConfigurationUserGroupsDBConfigRelease(p0)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigRelease())
	#define CHK_CmpUserGroupsDBConfigurationUserGroupsDBConfigRelease  TRUE
	#define EXP_CmpUserGroupsDBConfigurationUserGroupsDBConfigRelease  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserGroupsDBConfigRelease
	#define EXT_UserGroupsDBConfigRelease
	#define GET_UserGroupsDBConfigRelease(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigRelease(p0)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigRelease())
	#define CHK_UserGroupsDBConfigRelease  TRUE
	#define EXP_UserGroupsDBConfigRelease  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserGroupsDBConfigRelease
	#define EXT_UserGroupsDBConfigRelease
	#define GET_UserGroupsDBConfigRelease(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigRelease(p0) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigRelease(((ICmpUserGroupsDBConfiguration*)p0)->pBase->hInstance))
	#define CHK_UserGroupsDBConfigRelease  TRUE
	#define EXP_UserGroupsDBConfigRelease  ERR_OK
#endif




/**
 * <description>Import the user group database from a backup.</description>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Succeeded</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Failed releasing user management</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserGroupsDBConfigImport(RTS_HANDLE hDatabase, RTS_UI8 *pData, RTS_SIZE dataSize);
typedef RTS_RESULT (CDECL * PFUSERGROUPSDBCONFIGIMPORT) (RTS_HANDLE hDatabase, RTS_UI8 *pData, RTS_SIZE dataSize);
#if defined(CMPUSERGROUPSDBCONFIGURATION_NOTIMPLEMENTED) || defined(USERGROUPSDBCONFIGIMPORT_NOTIMPLEMENTED)
	#define USE_UserGroupsDBConfigImport
	#define EXT_UserGroupsDBConfigImport
	#define GET_UserGroupsDBConfigImport(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserGroupsDBConfigImport(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserGroupsDBConfigImport  FALSE
	#define EXP_UserGroupsDBConfigImport  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserGroupsDBConfigImport
	#define EXT_UserGroupsDBConfigImport
	#define GET_UserGroupsDBConfigImport(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigImport(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigImport(((ICmpUserGroupsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBConfigImport  TRUE
	#define EXP_UserGroupsDBConfigImport  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSERGROUPSDBCONFIGURATION_EXTERNAL)
	#define USE_UserGroupsDBConfigImport
	#define EXT_UserGroupsDBConfigImport
	#define GET_UserGroupsDBConfigImport(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigImport(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigImport(((ICmpUserGroupsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBConfigImport  TRUE
	#define EXP_UserGroupsDBConfigImport  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserGroupsDBConfigurationUserGroupsDBConfigImport
	#define EXT_CmpUserGroupsDBConfigurationUserGroupsDBConfigImport
	#define GET_CmpUserGroupsDBConfigurationUserGroupsDBConfigImport  ERR_OK
	#define CAL_CmpUserGroupsDBConfigurationUserGroupsDBConfigImport(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigImport(p1,p2))
	#define CHK_CmpUserGroupsDBConfigurationUserGroupsDBConfigImport  TRUE
	#define EXP_CmpUserGroupsDBConfigurationUserGroupsDBConfigImport  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserGroupsDBConfigImport
	#define EXT_UserGroupsDBConfigImport
	#define GET_UserGroupsDBConfigImport(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigImport(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigImport(p1,p2))
	#define CHK_UserGroupsDBConfigImport  TRUE
	#define EXP_UserGroupsDBConfigImport  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserGroupsDBConfigImport
	#define EXT_UserGroupsDBConfigImport
	#define GET_UserGroupsDBConfigImport(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigImport(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigImport(((ICmpUserGroupsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBConfigImport  TRUE
	#define EXP_UserGroupsDBConfigImport  ERR_OK
#endif




/**
 * <description>Export the user group database into a backup.</description>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Succeeded</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Failed releasing user management</errorcode>
 */
STATICITF_DEF RTS_SIZE CDECL UserGroupsDBConfigExport(RTS_HANDLE hDatabase, RTS_UI8 *pData, RTS_SIZE maxSize, RTS_RESULT *pResult);
typedef RTS_SIZE (CDECL * PFUSERGROUPSDBCONFIGEXPORT) (RTS_HANDLE hDatabase, RTS_UI8 *pData, RTS_SIZE maxSize, RTS_RESULT *pResult);
#if defined(CMPUSERGROUPSDBCONFIGURATION_NOTIMPLEMENTED) || defined(USERGROUPSDBCONFIGEXPORT_NOTIMPLEMENTED)
	#define USE_UserGroupsDBConfigExport
	#define EXT_UserGroupsDBConfigExport
	#define GET_UserGroupsDBConfigExport(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserGroupsDBConfigExport(p0,p1,p2,p3)  (RTS_SIZE)ERR_NOTIMPLEMENTED
	#define CHK_UserGroupsDBConfigExport  FALSE
	#define EXP_UserGroupsDBConfigExport  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserGroupsDBConfigExport
	#define EXT_UserGroupsDBConfigExport
	#define GET_UserGroupsDBConfigExport(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigExport(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigExport(((ICmpUserGroupsDBConfiguration*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserGroupsDBConfigExport  TRUE
	#define EXP_UserGroupsDBConfigExport  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSERGROUPSDBCONFIGURATION_EXTERNAL)
	#define USE_UserGroupsDBConfigExport
	#define EXT_UserGroupsDBConfigExport
	#define GET_UserGroupsDBConfigExport(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigExport(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigExport(((ICmpUserGroupsDBConfiguration*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserGroupsDBConfigExport  TRUE
	#define EXP_UserGroupsDBConfigExport  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserGroupsDBConfigurationUserGroupsDBConfigExport
	#define EXT_CmpUserGroupsDBConfigurationUserGroupsDBConfigExport
	#define GET_CmpUserGroupsDBConfigurationUserGroupsDBConfigExport  ERR_OK
	#define CAL_CmpUserGroupsDBConfigurationUserGroupsDBConfigExport(p0,p1,p2,p3)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigExport(p1,p2,p3))
	#define CHK_CmpUserGroupsDBConfigurationUserGroupsDBConfigExport  TRUE
	#define EXP_CmpUserGroupsDBConfigurationUserGroupsDBConfigExport  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserGroupsDBConfigExport
	#define EXT_UserGroupsDBConfigExport
	#define GET_UserGroupsDBConfigExport(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigExport(p0,p1,p2,p3)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigExport(p1,p2,p3))
	#define CHK_UserGroupsDBConfigExport  TRUE
	#define EXP_UserGroupsDBConfigExport  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserGroupsDBConfigExport
	#define EXT_UserGroupsDBConfigExport
	#define GET_UserGroupsDBConfigExport(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigExport(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigExport(((ICmpUserGroupsDBConfiguration*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserGroupsDBConfigExport  TRUE
	#define EXP_UserGroupsDBConfigExport  ERR_OK
#endif




/**
 * <description>Add a new user group to the user database</description>
 * <param name="pszGroup" type="IN">Group name</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Group could be added</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_DUPLICATE">Group already exists</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter. pszGroup = NULL or empty</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOMEMORY">No memory available to store new group</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">The user management is not initialized or it is not loaded yet</errorcode>
 * <result>Handle to the added group or RTS_INVALID_HANDLE if failed</result>
 */
STATICITF_DEF RTS_RESULT CDECL UserGroupsDBConfigAdd(RTS_HANDLE hDatabase, char *pszGroup);
typedef RTS_RESULT (CDECL * PFUSERGROUPSDBCONFIGADD) (RTS_HANDLE hDatabase, char *pszGroup);
#if defined(CMPUSERGROUPSDBCONFIGURATION_NOTIMPLEMENTED) || defined(USERGROUPSDBCONFIGADD_NOTIMPLEMENTED)
	#define USE_UserGroupsDBConfigAdd
	#define EXT_UserGroupsDBConfigAdd
	#define GET_UserGroupsDBConfigAdd(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserGroupsDBConfigAdd(p0,p1)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserGroupsDBConfigAdd  FALSE
	#define EXP_UserGroupsDBConfigAdd  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserGroupsDBConfigAdd
	#define EXT_UserGroupsDBConfigAdd
	#define GET_UserGroupsDBConfigAdd(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigAdd(p0,p1) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigAdd(((ICmpUserGroupsDBConfiguration*)p0)->pBase->hInstance,p1))
	#define CHK_UserGroupsDBConfigAdd  TRUE
	#define EXP_UserGroupsDBConfigAdd  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSERGROUPSDBCONFIGURATION_EXTERNAL)
	#define USE_UserGroupsDBConfigAdd
	#define EXT_UserGroupsDBConfigAdd
	#define GET_UserGroupsDBConfigAdd(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigAdd(p0,p1) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigAdd(((ICmpUserGroupsDBConfiguration*)p0)->pBase->hInstance,p1))
	#define CHK_UserGroupsDBConfigAdd  TRUE
	#define EXP_UserGroupsDBConfigAdd  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserGroupsDBConfigurationUserGroupsDBConfigAdd
	#define EXT_CmpUserGroupsDBConfigurationUserGroupsDBConfigAdd
	#define GET_CmpUserGroupsDBConfigurationUserGroupsDBConfigAdd  ERR_OK
	#define CAL_CmpUserGroupsDBConfigurationUserGroupsDBConfigAdd(p0,p1)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigAdd(p1))
	#define CHK_CmpUserGroupsDBConfigurationUserGroupsDBConfigAdd  TRUE
	#define EXP_CmpUserGroupsDBConfigurationUserGroupsDBConfigAdd  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserGroupsDBConfigAdd
	#define EXT_UserGroupsDBConfigAdd
	#define GET_UserGroupsDBConfigAdd(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigAdd(p0,p1)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigAdd(p1))
	#define CHK_UserGroupsDBConfigAdd  TRUE
	#define EXP_UserGroupsDBConfigAdd  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserGroupsDBConfigAdd
	#define EXT_UserGroupsDBConfigAdd
	#define GET_UserGroupsDBConfigAdd(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigAdd(p0,p1) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigAdd(((ICmpUserGroupsDBConfiguration*)p0)->pBase->hInstance,p1))
	#define CHK_UserGroupsDBConfigAdd  TRUE
	#define EXP_UserGroupsDBConfigAdd  ERR_OK
#endif




/**
 * <description>Remove user group from the user database</description>
 * <param name="hGroup" type="IN">Handle to the group</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Group could be removed</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid group handle</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserGroupsDBConfigRemove(RTS_HANDLE hDatabase, char *pszGroup);
typedef RTS_RESULT (CDECL * PFUSERGROUPSDBCONFIGREMOVE) (RTS_HANDLE hDatabase, char *pszGroup);
#if defined(CMPUSERGROUPSDBCONFIGURATION_NOTIMPLEMENTED) || defined(USERGROUPSDBCONFIGREMOVE_NOTIMPLEMENTED)
	#define USE_UserGroupsDBConfigRemove
	#define EXT_UserGroupsDBConfigRemove
	#define GET_UserGroupsDBConfigRemove(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserGroupsDBConfigRemove(p0,p1)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserGroupsDBConfigRemove  FALSE
	#define EXP_UserGroupsDBConfigRemove  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserGroupsDBConfigRemove
	#define EXT_UserGroupsDBConfigRemove
	#define GET_UserGroupsDBConfigRemove(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigRemove(p0,p1) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigRemove(((ICmpUserGroupsDBConfiguration*)p0)->pBase->hInstance,p1))
	#define CHK_UserGroupsDBConfigRemove  TRUE
	#define EXP_UserGroupsDBConfigRemove  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSERGROUPSDBCONFIGURATION_EXTERNAL)
	#define USE_UserGroupsDBConfigRemove
	#define EXT_UserGroupsDBConfigRemove
	#define GET_UserGroupsDBConfigRemove(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigRemove(p0,p1) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigRemove(((ICmpUserGroupsDBConfiguration*)p0)->pBase->hInstance,p1))
	#define CHK_UserGroupsDBConfigRemove  TRUE
	#define EXP_UserGroupsDBConfigRemove  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserGroupsDBConfigurationUserGroupsDBConfigRemove
	#define EXT_CmpUserGroupsDBConfigurationUserGroupsDBConfigRemove
	#define GET_CmpUserGroupsDBConfigurationUserGroupsDBConfigRemove  ERR_OK
	#define CAL_CmpUserGroupsDBConfigurationUserGroupsDBConfigRemove(p0,p1)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigRemove(p1))
	#define CHK_CmpUserGroupsDBConfigurationUserGroupsDBConfigRemove  TRUE
	#define EXP_CmpUserGroupsDBConfigurationUserGroupsDBConfigRemove  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserGroupsDBConfigRemove
	#define EXT_UserGroupsDBConfigRemove
	#define GET_UserGroupsDBConfigRemove(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigRemove(p0,p1)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigRemove(p1))
	#define CHK_UserGroupsDBConfigRemove  TRUE
	#define EXP_UserGroupsDBConfigRemove  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserGroupsDBConfigRemove
	#define EXT_UserGroupsDBConfigRemove
	#define GET_UserGroupsDBConfigRemove(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigRemove(p0,p1) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigRemove(((ICmpUserGroupsDBConfiguration*)p0)->pBase->hInstance,p1))
	#define CHK_UserGroupsDBConfigRemove  TRUE
	#define EXP_UserGroupsDBConfigRemove  ERR_OK
#endif




/**
 * <description>Set properties of a group</description>
 * <param name="hGroup" type="IN">Handle to the group</param>
 * <param name="pulProperty" type="IN">Pointer to set the properties. For details see category "UserDB properties"</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Properties could be set</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid user group or property pointer = NULL</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserGroupsDBConfigSetProperty(RTS_HANDLE hDatabase, char *pszGroup, RTS_UI32 ulProperty);
typedef RTS_RESULT (CDECL * PFUSERGROUPSDBCONFIGSETPROPERTY) (RTS_HANDLE hDatabase, char *pszGroup, RTS_UI32 ulProperty);
#if defined(CMPUSERGROUPSDBCONFIGURATION_NOTIMPLEMENTED) || defined(USERGROUPSDBCONFIGSETPROPERTY_NOTIMPLEMENTED)
	#define USE_UserGroupsDBConfigSetProperty
	#define EXT_UserGroupsDBConfigSetProperty
	#define GET_UserGroupsDBConfigSetProperty(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserGroupsDBConfigSetProperty(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserGroupsDBConfigSetProperty  FALSE
	#define EXP_UserGroupsDBConfigSetProperty  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserGroupsDBConfigSetProperty
	#define EXT_UserGroupsDBConfigSetProperty
	#define GET_UserGroupsDBConfigSetProperty(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigSetProperty(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigSetProperty(((ICmpUserGroupsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBConfigSetProperty  TRUE
	#define EXP_UserGroupsDBConfigSetProperty  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSERGROUPSDBCONFIGURATION_EXTERNAL)
	#define USE_UserGroupsDBConfigSetProperty
	#define EXT_UserGroupsDBConfigSetProperty
	#define GET_UserGroupsDBConfigSetProperty(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigSetProperty(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigSetProperty(((ICmpUserGroupsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBConfigSetProperty  TRUE
	#define EXP_UserGroupsDBConfigSetProperty  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserGroupsDBConfigurationUserGroupsDBConfigSetProperty
	#define EXT_CmpUserGroupsDBConfigurationUserGroupsDBConfigSetProperty
	#define GET_CmpUserGroupsDBConfigurationUserGroupsDBConfigSetProperty  ERR_OK
	#define CAL_CmpUserGroupsDBConfigurationUserGroupsDBConfigSetProperty(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigSetProperty(p1,p2))
	#define CHK_CmpUserGroupsDBConfigurationUserGroupsDBConfigSetProperty  TRUE
	#define EXP_CmpUserGroupsDBConfigurationUserGroupsDBConfigSetProperty  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserGroupsDBConfigSetProperty
	#define EXT_UserGroupsDBConfigSetProperty
	#define GET_UserGroupsDBConfigSetProperty(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigSetProperty(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigSetProperty(p1,p2))
	#define CHK_UserGroupsDBConfigSetProperty  TRUE
	#define EXP_UserGroupsDBConfigSetProperty  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserGroupsDBConfigSetProperty
	#define EXT_UserGroupsDBConfigSetProperty
	#define GET_UserGroupsDBConfigSetProperty(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigSetProperty(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigSetProperty(((ICmpUserGroupsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBConfigSetProperty  TRUE
	#define EXP_UserGroupsDBConfigSetProperty  ERR_OK
#endif




/**
 * <description>Add a new user to a group
 * NOTE: The required user handle is not compatible with a handle from the UserMgr, and these handles must not be mixed.
 * A UserMgr handle can be converted to a UserDB handle by using UserMgrGetUserDBHandle().
 * </description>
 * <param name="hGroup" type="IN">Handle to the group</param>
 * <param name="hUser" type="IN">Handle to the user</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">User could be added or is already added</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter. hGroup or hUser invalid</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOMEMORY">No memory available to add user to group</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">The user management is not initialized or it is not loaded yet</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserGroupsDBConfigAddUser(RTS_HANDLE hDatabase, char *pszGroup, char *pszUser);
typedef RTS_RESULT (CDECL * PFUSERGROUPSDBCONFIGADDUSER) (RTS_HANDLE hDatabase, char *pszGroup, char *pszUser);
#if defined(CMPUSERGROUPSDBCONFIGURATION_NOTIMPLEMENTED) || defined(USERGROUPSDBCONFIGADDUSER_NOTIMPLEMENTED)
	#define USE_UserGroupsDBConfigAddUser
	#define EXT_UserGroupsDBConfigAddUser
	#define GET_UserGroupsDBConfigAddUser(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserGroupsDBConfigAddUser(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserGroupsDBConfigAddUser  FALSE
	#define EXP_UserGroupsDBConfigAddUser  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserGroupsDBConfigAddUser
	#define EXT_UserGroupsDBConfigAddUser
	#define GET_UserGroupsDBConfigAddUser(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigAddUser(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigAddUser(((ICmpUserGroupsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBConfigAddUser  TRUE
	#define EXP_UserGroupsDBConfigAddUser  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSERGROUPSDBCONFIGURATION_EXTERNAL)
	#define USE_UserGroupsDBConfigAddUser
	#define EXT_UserGroupsDBConfigAddUser
	#define GET_UserGroupsDBConfigAddUser(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigAddUser(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigAddUser(((ICmpUserGroupsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBConfigAddUser  TRUE
	#define EXP_UserGroupsDBConfigAddUser  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserGroupsDBConfigurationUserGroupsDBConfigAddUser
	#define EXT_CmpUserGroupsDBConfigurationUserGroupsDBConfigAddUser
	#define GET_CmpUserGroupsDBConfigurationUserGroupsDBConfigAddUser  ERR_OK
	#define CAL_CmpUserGroupsDBConfigurationUserGroupsDBConfigAddUser(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigAddUser(p1,p2))
	#define CHK_CmpUserGroupsDBConfigurationUserGroupsDBConfigAddUser  TRUE
	#define EXP_CmpUserGroupsDBConfigurationUserGroupsDBConfigAddUser  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserGroupsDBConfigAddUser
	#define EXT_UserGroupsDBConfigAddUser
	#define GET_UserGroupsDBConfigAddUser(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigAddUser(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigAddUser(p1,p2))
	#define CHK_UserGroupsDBConfigAddUser  TRUE
	#define EXP_UserGroupsDBConfigAddUser  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserGroupsDBConfigAddUser
	#define EXT_UserGroupsDBConfigAddUser
	#define GET_UserGroupsDBConfigAddUser(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigAddUser(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigAddUser(((ICmpUserGroupsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBConfigAddUser  TRUE
	#define EXP_UserGroupsDBConfigAddUser  ERR_OK
#endif




/**
 * <description>Remove a user from a group
 * NOTE: The required user handle is not compatible with a handle from the UserMgr, and these handles must not be mixed.
 * A UserMgr handle can be converted to a UserDB handle by using UserMgrGetUserDBHandle().
 * </description>
 * <param name="hGroup" type="IN">Handle to the group</param>
 * <param name="hUser" type="IN">Handle to the user</param>
  * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">User could be removed</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter. hGroup or hUser invalid</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">The user management is not initialized or it is not loaded yet</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserGroupsDBConfigRemoveUser(RTS_HANDLE hDatabase, char *pszGroup, char *pszUser);
typedef RTS_RESULT (CDECL * PFUSERGROUPSDBCONFIGREMOVEUSER) (RTS_HANDLE hDatabase, char *pszGroup, char *pszUser);
#if defined(CMPUSERGROUPSDBCONFIGURATION_NOTIMPLEMENTED) || defined(USERGROUPSDBCONFIGREMOVEUSER_NOTIMPLEMENTED)
	#define USE_UserGroupsDBConfigRemoveUser
	#define EXT_UserGroupsDBConfigRemoveUser
	#define GET_UserGroupsDBConfigRemoveUser(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserGroupsDBConfigRemoveUser(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserGroupsDBConfigRemoveUser  FALSE
	#define EXP_UserGroupsDBConfigRemoveUser  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserGroupsDBConfigRemoveUser
	#define EXT_UserGroupsDBConfigRemoveUser
	#define GET_UserGroupsDBConfigRemoveUser(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigRemoveUser(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigRemoveUser(((ICmpUserGroupsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBConfigRemoveUser  TRUE
	#define EXP_UserGroupsDBConfigRemoveUser  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSERGROUPSDBCONFIGURATION_EXTERNAL)
	#define USE_UserGroupsDBConfigRemoveUser
	#define EXT_UserGroupsDBConfigRemoveUser
	#define GET_UserGroupsDBConfigRemoveUser(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigRemoveUser(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigRemoveUser(((ICmpUserGroupsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBConfigRemoveUser  TRUE
	#define EXP_UserGroupsDBConfigRemoveUser  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserGroupsDBConfigurationUserGroupsDBConfigRemoveUser
	#define EXT_CmpUserGroupsDBConfigurationUserGroupsDBConfigRemoveUser
	#define GET_CmpUserGroupsDBConfigurationUserGroupsDBConfigRemoveUser  ERR_OK
	#define CAL_CmpUserGroupsDBConfigurationUserGroupsDBConfigRemoveUser(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigRemoveUser(p1,p2))
	#define CHK_CmpUserGroupsDBConfigurationUserGroupsDBConfigRemoveUser  TRUE
	#define EXP_CmpUserGroupsDBConfigurationUserGroupsDBConfigRemoveUser  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserGroupsDBConfigRemoveUser
	#define EXT_UserGroupsDBConfigRemoveUser
	#define GET_UserGroupsDBConfigRemoveUser(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigRemoveUser(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigRemoveUser(p1,p2))
	#define CHK_UserGroupsDBConfigRemoveUser  TRUE
	#define EXP_UserGroupsDBConfigRemoveUser  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserGroupsDBConfigRemoveUser
	#define EXT_UserGroupsDBConfigRemoveUser
	#define GET_UserGroupsDBConfigRemoveUser(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigRemoveUser(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigRemoveUser(((ICmpUserGroupsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBConfigRemoveUser  TRUE
	#define EXP_UserGroupsDBConfigRemoveUser  ERR_OK
#endif




/**
 * <description>Add a group as a member to another group. So that group is derived from the first one</description>
 * <param name="hGroup" type="IN">First group to derive from</param>
 * <param name="hGroupMember" type="IN">New member group which is derived from the first group (hGroup) after this operation</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Group could be added</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_DUPLICATE">Group is already added</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter. hGroup or hGroupMember invalid</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOMEMORY">No memory available to add group to another group</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">The user management is not initialized or it is not loaded yet</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserGroupsDBConfigAddMember(RTS_HANDLE hDatabase, char *pszGroup, char *pszGroupToAdd);
typedef RTS_RESULT (CDECL * PFUSERGROUPSDBCONFIGADDMEMBER) (RTS_HANDLE hDatabase, char *pszGroup, char *pszGroupToAdd);
#if defined(CMPUSERGROUPSDBCONFIGURATION_NOTIMPLEMENTED) || defined(USERGROUPSDBCONFIGADDMEMBER_NOTIMPLEMENTED)
	#define USE_UserGroupsDBConfigAddMember
	#define EXT_UserGroupsDBConfigAddMember
	#define GET_UserGroupsDBConfigAddMember(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserGroupsDBConfigAddMember(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserGroupsDBConfigAddMember  FALSE
	#define EXP_UserGroupsDBConfigAddMember  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserGroupsDBConfigAddMember
	#define EXT_UserGroupsDBConfigAddMember
	#define GET_UserGroupsDBConfigAddMember(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigAddMember(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigAddMember(((ICmpUserGroupsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBConfigAddMember  TRUE
	#define EXP_UserGroupsDBConfigAddMember  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSERGROUPSDBCONFIGURATION_EXTERNAL)
	#define USE_UserGroupsDBConfigAddMember
	#define EXT_UserGroupsDBConfigAddMember
	#define GET_UserGroupsDBConfigAddMember(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigAddMember(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigAddMember(((ICmpUserGroupsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBConfigAddMember  TRUE
	#define EXP_UserGroupsDBConfigAddMember  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserGroupsDBConfigurationUserGroupsDBConfigAddMember
	#define EXT_CmpUserGroupsDBConfigurationUserGroupsDBConfigAddMember
	#define GET_CmpUserGroupsDBConfigurationUserGroupsDBConfigAddMember  ERR_OK
	#define CAL_CmpUserGroupsDBConfigurationUserGroupsDBConfigAddMember(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigAddMember(p1,p2))
	#define CHK_CmpUserGroupsDBConfigurationUserGroupsDBConfigAddMember  TRUE
	#define EXP_CmpUserGroupsDBConfigurationUserGroupsDBConfigAddMember  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserGroupsDBConfigAddMember
	#define EXT_UserGroupsDBConfigAddMember
	#define GET_UserGroupsDBConfigAddMember(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigAddMember(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigAddMember(p1,p2))
	#define CHK_UserGroupsDBConfigAddMember  TRUE
	#define EXP_UserGroupsDBConfigAddMember  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserGroupsDBConfigAddMember
	#define EXT_UserGroupsDBConfigAddMember
	#define GET_UserGroupsDBConfigAddMember(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigAddMember(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigAddMember(((ICmpUserGroupsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBConfigAddMember  TRUE
	#define EXP_UserGroupsDBConfigAddMember  ERR_OK
#endif




/**
 * <description>Remove a group as a member from another group. So the group is no longer derived from the first one</description>
 * <param name="hGroup" type="IN">First group to remove the derived group from</param>
 * <param name="hGroupMember" type="IN">Member group which is no longer derived from the first group (hGroup) after this operation</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Group could be removed</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter. hGroup or hGroupMember invalid</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">The user management is not initialized or it is not loaded yet</errorcode>
 */
 STATICITF_DEF RTS_RESULT CDECL UserGroupsDBConfigRemoveMember(RTS_HANDLE hDatabase, char *pszGroup, char *pszGroupToRemove);
typedef RTS_RESULT (CDECL * PFUSERGROUPSDBCONFIGREMOVEMEMBER) (RTS_HANDLE hDatabase, char *pszGroup, char *pszGroupToRemove);
#if defined(CMPUSERGROUPSDBCONFIGURATION_NOTIMPLEMENTED) || defined(USERGROUPSDBCONFIGREMOVEMEMBER_NOTIMPLEMENTED)
	#define USE_UserGroupsDBConfigRemoveMember
	#define EXT_UserGroupsDBConfigRemoveMember
	#define GET_UserGroupsDBConfigRemoveMember(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserGroupsDBConfigRemoveMember(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserGroupsDBConfigRemoveMember  FALSE
	#define EXP_UserGroupsDBConfigRemoveMember  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserGroupsDBConfigRemoveMember
	#define EXT_UserGroupsDBConfigRemoveMember
	#define GET_UserGroupsDBConfigRemoveMember(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigRemoveMember(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigRemoveMember(((ICmpUserGroupsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBConfigRemoveMember  TRUE
	#define EXP_UserGroupsDBConfigRemoveMember  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSERGROUPSDBCONFIGURATION_EXTERNAL)
	#define USE_UserGroupsDBConfigRemoveMember
	#define EXT_UserGroupsDBConfigRemoveMember
	#define GET_UserGroupsDBConfigRemoveMember(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigRemoveMember(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigRemoveMember(((ICmpUserGroupsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBConfigRemoveMember  TRUE
	#define EXP_UserGroupsDBConfigRemoveMember  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserGroupsDBConfigurationUserGroupsDBConfigRemoveMember
	#define EXT_CmpUserGroupsDBConfigurationUserGroupsDBConfigRemoveMember
	#define GET_CmpUserGroupsDBConfigurationUserGroupsDBConfigRemoveMember  ERR_OK
	#define CAL_CmpUserGroupsDBConfigurationUserGroupsDBConfigRemoveMember(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigRemoveMember(p1,p2))
	#define CHK_CmpUserGroupsDBConfigurationUserGroupsDBConfigRemoveMember  TRUE
	#define EXP_CmpUserGroupsDBConfigurationUserGroupsDBConfigRemoveMember  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserGroupsDBConfigRemoveMember
	#define EXT_UserGroupsDBConfigRemoveMember
	#define GET_UserGroupsDBConfigRemoveMember(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigRemoveMember(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigRemoveMember(p1,p2))
	#define CHK_UserGroupsDBConfigRemoveMember  TRUE
	#define EXP_UserGroupsDBConfigRemoveMember  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserGroupsDBConfigRemoveMember
	#define EXT_UserGroupsDBConfigRemoveMember
	#define GET_UserGroupsDBConfigRemoveMember(fl)  ERR_OK
	#define CAL_UserGroupsDBConfigRemoveMember(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDBConfiguration*)p0)->IUserGroupsDBConfigRemoveMember(((ICmpUserGroupsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBConfigRemoveMember  TRUE
	#define EXP_UserGroupsDBConfigRemoveMember  ERR_OK
#endif






typedef struct
{
	IBase_C *pBase;
	PFUSERGROUPSDBCONFIGRELEASE IUserGroupsDBConfigRelease;
 	PFUSERGROUPSDBCONFIGIMPORT IUserGroupsDBConfigImport;
 	PFUSERGROUPSDBCONFIGEXPORT IUserGroupsDBConfigExport;
 	PFUSERGROUPSDBCONFIGADD IUserGroupsDBConfigAdd;
 	PFUSERGROUPSDBCONFIGREMOVE IUserGroupsDBConfigRemove;
 	PFUSERGROUPSDBCONFIGSETPROPERTY IUserGroupsDBConfigSetProperty;
 	PFUSERGROUPSDBCONFIGADDUSER IUserGroupsDBConfigAddUser;
 	PFUSERGROUPSDBCONFIGREMOVEUSER IUserGroupsDBConfigRemoveUser;
 	PFUSERGROUPSDBCONFIGADDMEMBER IUserGroupsDBConfigAddMember;
 	PFUSERGROUPSDBCONFIGREMOVEMEMBER IUserGroupsDBConfigRemoveMember;
 } ICmpUserGroupsDBConfiguration_C;

#ifdef CPLUSPLUS
class ICmpUserGroupsDBConfiguration : public IBase
{
	public:
		virtual RTS_RESULT CDECL IUserGroupsDBConfigRelease(void) =0;
		virtual RTS_RESULT CDECL IUserGroupsDBConfigImport(RTS_UI8 *pData, RTS_SIZE dataSize) =0;
		virtual RTS_SIZE CDECL IUserGroupsDBConfigExport(RTS_UI8 *pData, RTS_SIZE maxSize, RTS_RESULT *pResult) =0;
		virtual RTS_RESULT CDECL IUserGroupsDBConfigAdd(char *pszGroup) =0;
		virtual RTS_RESULT CDECL IUserGroupsDBConfigRemove(char *pszGroup) =0;
		virtual RTS_RESULT CDECL IUserGroupsDBConfigSetProperty(char *pszGroup, RTS_UI32 ulProperty) =0;
		virtual RTS_RESULT CDECL IUserGroupsDBConfigAddUser(char *pszGroup, char *pszUser) =0;
		virtual RTS_RESULT CDECL IUserGroupsDBConfigRemoveUser(char *pszGroup, char *pszUser) =0;
		virtual RTS_RESULT CDECL IUserGroupsDBConfigAddMember(char *pszGroup, char *pszGroupToAdd) =0;
		virtual RTS_RESULT CDECL IUserGroupsDBConfigRemoveMember(char *pszGroup, char *pszGroupToRemove) =0;
};
	#ifndef ITF_CmpUserGroupsDBConfiguration
		#define ITF_CmpUserGroupsDBConfiguration static ICmpUserGroupsDBConfiguration *pICmpUserGroupsDBConfiguration = NULL;
	#endif
	#define EXTITF_CmpUserGroupsDBConfiguration
#else	/*CPLUSPLUS*/
	typedef ICmpUserGroupsDBConfiguration_C		ICmpUserGroupsDBConfiguration;
	#ifndef ITF_CmpUserGroupsDBConfiguration
		#define ITF_CmpUserGroupsDBConfiguration
	#endif
	#define EXTITF_CmpUserGroupsDBConfiguration
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_CMPUSERGROUPSDBCONFIGURATIONITF_H_*/
