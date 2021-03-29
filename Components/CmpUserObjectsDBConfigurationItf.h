 /**
 * <interfacename>CmpUserObjectsDBConfiguration</interfacename>
 * <description>
 *	This interface is used to configure a database of user rights on objects. If the dateabase is not configurable (e.g. the implementation depends on the operating system) this
 *	interface may not be implemented by the database component. Doing so allows only the read access to the user rights on objects but not the configuration of user rights using the CODESYS online services.
 * </description>
 *
 * <copyright>
 * Copyright (c) 2019-2020 CODESYS Development GmbH. All rights reserved.
 * </copyright>
 */


	
	
#ifndef _CMPUSEROBJECTSDBCONFIGURATIONITF_H_
#define _CMPUSEROBJECTSDBCONFIGURATIONITF_H_

#include "CmpStd.h"

 

 




#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description>Load the user rights database into memory</description>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Succeeded</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Error loading user rights database</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTIMPLEMENTED">Is not implemented perhaps the UserObjectsDB is fix</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserObjectsDBConfigLoad(RTS_HANDLE hDatabase);
typedef RTS_RESULT (CDECL * PFUSEROBJECTSDBCONFIGLOAD) (RTS_HANDLE hDatabase);
#if defined(CMPUSEROBJECTSDBCONFIGURATION_NOTIMPLEMENTED) || defined(USEROBJECTSDBCONFIGLOAD_NOTIMPLEMENTED)
	#define USE_UserObjectsDBConfigLoad
	#define EXT_UserObjectsDBConfigLoad
	#define GET_UserObjectsDBConfigLoad(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBConfigLoad(p0)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserObjectsDBConfigLoad  FALSE
	#define EXP_UserObjectsDBConfigLoad  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBConfigLoad
	#define EXT_UserObjectsDBConfigLoad
	#define GET_UserObjectsDBConfigLoad(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigLoad(p0) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigLoad(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance))
	#define CHK_UserObjectsDBConfigLoad  TRUE
	#define EXP_UserObjectsDBConfigLoad  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDBCONFIGURATION_EXTERNAL)
	#define USE_UserObjectsDBConfigLoad
	#define EXT_UserObjectsDBConfigLoad
	#define GET_UserObjectsDBConfigLoad(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigLoad(p0) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigLoad(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance))
	#define CHK_UserObjectsDBConfigLoad  TRUE
	#define EXP_UserObjectsDBConfigLoad  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBConfigurationUserObjectsDBConfigLoad
	#define EXT_CmpUserObjectsDBConfigurationUserObjectsDBConfigLoad
	#define GET_CmpUserObjectsDBConfigurationUserObjectsDBConfigLoad  ERR_OK
	#define CAL_CmpUserObjectsDBConfigurationUserObjectsDBConfigLoad(p0)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigLoad())
	#define CHK_CmpUserObjectsDBConfigurationUserObjectsDBConfigLoad  TRUE
	#define EXP_CmpUserObjectsDBConfigurationUserObjectsDBConfigLoad  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBConfigLoad
	#define EXT_UserObjectsDBConfigLoad
	#define GET_UserObjectsDBConfigLoad(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigLoad(p0)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigLoad())
	#define CHK_UserObjectsDBConfigLoad  TRUE
	#define EXP_UserObjectsDBConfigLoad  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBConfigLoad
	#define EXT_UserObjectsDBConfigLoad
	#define GET_UserObjectsDBConfigLoad(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigLoad(p0) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigLoad(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance))
	#define CHK_UserObjectsDBConfigLoad  TRUE
	#define EXP_UserObjectsDBConfigLoad  ERR_OK
#endif




/**
 * <description>Storing the current user rights management into permanent database file</description>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Succeeded</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Error storing user rights database</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTIMPLEMENTED">Is not implemented perhaps the UserObjectsDB is fix</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserObjectsDBConfigStore(RTS_HANDLE hDatabase);
typedef RTS_RESULT (CDECL * PFUSEROBJECTSDBCONFIGSTORE) (RTS_HANDLE hDatabase);
#if defined(CMPUSEROBJECTSDBCONFIGURATION_NOTIMPLEMENTED) || defined(USEROBJECTSDBCONFIGSTORE_NOTIMPLEMENTED)
	#define USE_UserObjectsDBConfigStore
	#define EXT_UserObjectsDBConfigStore
	#define GET_UserObjectsDBConfigStore(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBConfigStore(p0)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserObjectsDBConfigStore  FALSE
	#define EXP_UserObjectsDBConfigStore  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBConfigStore
	#define EXT_UserObjectsDBConfigStore
	#define GET_UserObjectsDBConfigStore(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigStore(p0) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigStore(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance))
	#define CHK_UserObjectsDBConfigStore  TRUE
	#define EXP_UserObjectsDBConfigStore  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDBCONFIGURATION_EXTERNAL)
	#define USE_UserObjectsDBConfigStore
	#define EXT_UserObjectsDBConfigStore
	#define GET_UserObjectsDBConfigStore(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigStore(p0) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigStore(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance))
	#define CHK_UserObjectsDBConfigStore  TRUE
	#define EXP_UserObjectsDBConfigStore  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBConfigurationUserObjectsDBConfigStore
	#define EXT_CmpUserObjectsDBConfigurationUserObjectsDBConfigStore
	#define GET_CmpUserObjectsDBConfigurationUserObjectsDBConfigStore  ERR_OK
	#define CAL_CmpUserObjectsDBConfigurationUserObjectsDBConfigStore(p0)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigStore())
	#define CHK_CmpUserObjectsDBConfigurationUserObjectsDBConfigStore  TRUE
	#define EXP_CmpUserObjectsDBConfigurationUserObjectsDBConfigStore  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBConfigStore
	#define EXT_UserObjectsDBConfigStore
	#define GET_UserObjectsDBConfigStore(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigStore(p0)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigStore())
	#define CHK_UserObjectsDBConfigStore  TRUE
	#define EXP_UserObjectsDBConfigStore  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBConfigStore
	#define EXT_UserObjectsDBConfigStore
	#define GET_UserObjectsDBConfigStore(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigStore(p0) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigStore(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance))
	#define CHK_UserObjectsDBConfigStore  TRUE
	#define EXP_UserObjectsDBConfigStore  ERR_OK
#endif




/**
 * <description>Release user rights from all objects and delete persistant stored.</description>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Succeeded</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Failed releasing user rights from all objects</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTIMPLEMENTED">Is not implemented perhaps the UserObjectsDB is fix</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserObjectsDBConfigRelease(RTS_HANDLE hDatabase);
typedef RTS_RESULT (CDECL * PFUSEROBJECTSDBCONFIGRELEASE) (RTS_HANDLE hDatabase);
#if defined(CMPUSEROBJECTSDBCONFIGURATION_NOTIMPLEMENTED) || defined(USEROBJECTSDBCONFIGRELEASE_NOTIMPLEMENTED)
	#define USE_UserObjectsDBConfigRelease
	#define EXT_UserObjectsDBConfigRelease
	#define GET_UserObjectsDBConfigRelease(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBConfigRelease(p0)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserObjectsDBConfigRelease  FALSE
	#define EXP_UserObjectsDBConfigRelease  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBConfigRelease
	#define EXT_UserObjectsDBConfigRelease
	#define GET_UserObjectsDBConfigRelease(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigRelease(p0) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigRelease(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance))
	#define CHK_UserObjectsDBConfigRelease  TRUE
	#define EXP_UserObjectsDBConfigRelease  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDBCONFIGURATION_EXTERNAL)
	#define USE_UserObjectsDBConfigRelease
	#define EXT_UserObjectsDBConfigRelease
	#define GET_UserObjectsDBConfigRelease(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigRelease(p0) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigRelease(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance))
	#define CHK_UserObjectsDBConfigRelease  TRUE
	#define EXP_UserObjectsDBConfigRelease  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBConfigurationUserObjectsDBConfigRelease
	#define EXT_CmpUserObjectsDBConfigurationUserObjectsDBConfigRelease
	#define GET_CmpUserObjectsDBConfigurationUserObjectsDBConfigRelease  ERR_OK
	#define CAL_CmpUserObjectsDBConfigurationUserObjectsDBConfigRelease(p0)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigRelease())
	#define CHK_CmpUserObjectsDBConfigurationUserObjectsDBConfigRelease  TRUE
	#define EXP_CmpUserObjectsDBConfigurationUserObjectsDBConfigRelease  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBConfigRelease
	#define EXT_UserObjectsDBConfigRelease
	#define GET_UserObjectsDBConfigRelease(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigRelease(p0)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigRelease())
	#define CHK_UserObjectsDBConfigRelease  TRUE
	#define EXP_UserObjectsDBConfigRelease  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBConfigRelease
	#define EXT_UserObjectsDBConfigRelease
	#define GET_UserObjectsDBConfigRelease(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigRelease(p0) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigRelease(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance))
	#define CHK_UserObjectsDBConfigRelease  TRUE
	#define EXP_UserObjectsDBConfigRelease  ERR_OK
#endif




/**
 * <description>Release user rights from all objects</description>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Succeeded</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Failed releasing user rights from all objects</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTIMPLEMENTED">Is not implemented perhaps the UserObjectsDB is fix</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserObjectsDBConfigReleaseRights(RTS_HANDLE hDatabase);
typedef RTS_RESULT (CDECL * PFUSEROBJECTSDBCONFIGRELEASERIGHTS) (RTS_HANDLE hDatabase);
#if defined(CMPUSEROBJECTSDBCONFIGURATION_NOTIMPLEMENTED) || defined(USEROBJECTSDBCONFIGRELEASERIGHTS_NOTIMPLEMENTED)
	#define USE_UserObjectsDBConfigReleaseRights
	#define EXT_UserObjectsDBConfigReleaseRights
	#define GET_UserObjectsDBConfigReleaseRights(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBConfigReleaseRights(p0)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserObjectsDBConfigReleaseRights  FALSE
	#define EXP_UserObjectsDBConfigReleaseRights  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBConfigReleaseRights
	#define EXT_UserObjectsDBConfigReleaseRights
	#define GET_UserObjectsDBConfigReleaseRights(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigReleaseRights(p0) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigReleaseRights(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance))
	#define CHK_UserObjectsDBConfigReleaseRights  TRUE
	#define EXP_UserObjectsDBConfigReleaseRights  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDBCONFIGURATION_EXTERNAL)
	#define USE_UserObjectsDBConfigReleaseRights
	#define EXT_UserObjectsDBConfigReleaseRights
	#define GET_UserObjectsDBConfigReleaseRights(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigReleaseRights(p0) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigReleaseRights(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance))
	#define CHK_UserObjectsDBConfigReleaseRights  TRUE
	#define EXP_UserObjectsDBConfigReleaseRights  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBConfigurationUserObjectsDBConfigReleaseRights
	#define EXT_CmpUserObjectsDBConfigurationUserObjectsDBConfigReleaseRights
	#define GET_CmpUserObjectsDBConfigurationUserObjectsDBConfigReleaseRights  ERR_OK
	#define CAL_CmpUserObjectsDBConfigurationUserObjectsDBConfigReleaseRights(p0)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigReleaseRights())
	#define CHK_CmpUserObjectsDBConfigurationUserObjectsDBConfigReleaseRights  TRUE
	#define EXP_CmpUserObjectsDBConfigurationUserObjectsDBConfigReleaseRights  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBConfigReleaseRights
	#define EXT_UserObjectsDBConfigReleaseRights
	#define GET_UserObjectsDBConfigReleaseRights(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigReleaseRights(p0)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigReleaseRights())
	#define CHK_UserObjectsDBConfigReleaseRights  TRUE
	#define EXP_UserObjectsDBConfigReleaseRights  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBConfigReleaseRights
	#define EXT_UserObjectsDBConfigReleaseRights
	#define GET_UserObjectsDBConfigReleaseRights(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigReleaseRights(p0) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigReleaseRights(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance))
	#define CHK_UserObjectsDBConfigReleaseRights  TRUE
	#define EXP_UserObjectsDBConfigReleaseRights  ERR_OK
#endif




/* Objects management configuration */

/**
 * <description>
 *	Add a new object to the object management, so the access rights can be configured on that object.
 *	NOTE:
 *	The name of the object must include the full name-space with "Device" as the root node, e.g. "Device.MyObject" or if it's a file system object with "/" as the root node.
 * </description>
 * <param name="pszObject" type="IN">Full object name (see object tree)</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Object could be added</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Object invalid = NULL or empty</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">The user management is not initialized or it is not loaded yet</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOMEMORY">If memory could not be allocated to store this object</errorcode>
 * <result>Handle to the object or RTS_INVALID_HANDLE if it could not be added</result>
 */
STATICITF_DEF RTS_HANDLE CDECL UserObjectsDBConfigAdd(RTS_HANDLE hDatabase, char *pszObject, RTS_RESULT *pResult);
typedef RTS_HANDLE (CDECL * PFUSEROBJECTSDBCONFIGADD) (RTS_HANDLE hDatabase, char *pszObject, RTS_RESULT *pResult);
#if defined(CMPUSEROBJECTSDBCONFIGURATION_NOTIMPLEMENTED) || defined(USEROBJECTSDBCONFIGADD_NOTIMPLEMENTED)
	#define USE_UserObjectsDBConfigAdd
	#define EXT_UserObjectsDBConfigAdd
	#define GET_UserObjectsDBConfigAdd(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBConfigAdd(p0,p1,p2)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_UserObjectsDBConfigAdd  FALSE
	#define EXP_UserObjectsDBConfigAdd  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBConfigAdd
	#define EXT_UserObjectsDBConfigAdd
	#define GET_UserObjectsDBConfigAdd(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigAdd(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigAdd(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBConfigAdd  TRUE
	#define EXP_UserObjectsDBConfigAdd  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDBCONFIGURATION_EXTERNAL)
	#define USE_UserObjectsDBConfigAdd
	#define EXT_UserObjectsDBConfigAdd
	#define GET_UserObjectsDBConfigAdd(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigAdd(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigAdd(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBConfigAdd  TRUE
	#define EXP_UserObjectsDBConfigAdd  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBConfigurationUserObjectsDBConfigAdd
	#define EXT_CmpUserObjectsDBConfigurationUserObjectsDBConfigAdd
	#define GET_CmpUserObjectsDBConfigurationUserObjectsDBConfigAdd  ERR_OK
	#define CAL_CmpUserObjectsDBConfigurationUserObjectsDBConfigAdd(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigAdd(p1,p2))
	#define CHK_CmpUserObjectsDBConfigurationUserObjectsDBConfigAdd  TRUE
	#define EXP_CmpUserObjectsDBConfigurationUserObjectsDBConfigAdd  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBConfigAdd
	#define EXT_UserObjectsDBConfigAdd
	#define GET_UserObjectsDBConfigAdd(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigAdd(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigAdd(p1,p2))
	#define CHK_UserObjectsDBConfigAdd  TRUE
	#define EXP_UserObjectsDBConfigAdd  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBConfigAdd
	#define EXT_UserObjectsDBConfigAdd
	#define GET_UserObjectsDBConfigAdd(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigAdd(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigAdd(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBConfigAdd  TRUE
	#define EXP_UserObjectsDBConfigAdd  ERR_OK
#endif




/**
 * <description>
 *	Add a new object to the object management, so the access rights can be configured on that object.
 *	NOTE:
 *	The name of the object must include the full name space with "Device" as the root node, e.g. "Device.MyObject" or if it's a file system object with "/" as the root node.
 * </description>
 * <param name="pszObject" type="IN">Full object name (see object tree)</param>
 * <param name="properties" type="IN">Properties of the object. See Properties.</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Object could be added</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Object invalid = NULL or empty</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">The user management is not initialized or it is not loaded yet</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOMEMORY">If memory could not be allocated to store this object</errorcode>
 * <result>Handle to the object or RTS_INVALID_HANDLE if it could not be added</result>
 */
STATICITF_DEF RTS_HANDLE CDECL UserObjectsDBConfigAdd2(RTS_HANDLE hDatabase, char *pszObject, RTS_UI32 properties, RTS_RESULT *pResult);
typedef RTS_HANDLE (CDECL * PFUSEROBJECTSDBCONFIGADD2) (RTS_HANDLE hDatabase, char *pszObject, RTS_UI32 properties, RTS_RESULT *pResult);
#if defined(CMPUSEROBJECTSDBCONFIGURATION_NOTIMPLEMENTED) || defined(USEROBJECTSDBCONFIGADD2_NOTIMPLEMENTED)
	#define USE_UserObjectsDBConfigAdd2
	#define EXT_UserObjectsDBConfigAdd2
	#define GET_UserObjectsDBConfigAdd2(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBConfigAdd2(p0,p1,p2,p3)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_UserObjectsDBConfigAdd2  FALSE
	#define EXP_UserObjectsDBConfigAdd2  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBConfigAdd2
	#define EXT_UserObjectsDBConfigAdd2
	#define GET_UserObjectsDBConfigAdd2(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigAdd2(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigAdd2(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserObjectsDBConfigAdd2  TRUE
	#define EXP_UserObjectsDBConfigAdd2  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDBCONFIGURATION_EXTERNAL)
	#define USE_UserObjectsDBConfigAdd2
	#define EXT_UserObjectsDBConfigAdd2
	#define GET_UserObjectsDBConfigAdd2(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigAdd2(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigAdd2(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserObjectsDBConfigAdd2  TRUE
	#define EXP_UserObjectsDBConfigAdd2  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBConfigurationUserObjectsDBConfigAdd2
	#define EXT_CmpUserObjectsDBConfigurationUserObjectsDBConfigAdd2
	#define GET_CmpUserObjectsDBConfigurationUserObjectsDBConfigAdd2  ERR_OK
	#define CAL_CmpUserObjectsDBConfigurationUserObjectsDBConfigAdd2(p0,p1,p2,p3)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigAdd2(p1,p2,p3))
	#define CHK_CmpUserObjectsDBConfigurationUserObjectsDBConfigAdd2  TRUE
	#define EXP_CmpUserObjectsDBConfigurationUserObjectsDBConfigAdd2  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBConfigAdd2
	#define EXT_UserObjectsDBConfigAdd2
	#define GET_UserObjectsDBConfigAdd2(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigAdd2(p0,p1,p2,p3)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigAdd2(p1,p2,p3))
	#define CHK_UserObjectsDBConfigAdd2  TRUE
	#define EXP_UserObjectsDBConfigAdd2  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBConfigAdd2
	#define EXT_UserObjectsDBConfigAdd2
	#define GET_UserObjectsDBConfigAdd2(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigAdd2(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigAdd2(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserObjectsDBConfigAdd2  TRUE
	#define EXP_UserObjectsDBConfigAdd2  ERR_OK
#endif


 

/**
 * <description>Remove an object from the object management and all its children</description>
 * <param name="hObject" type="IN">Handle to object</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Object could be removed</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid object handle</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserObjectsDBConfigRemove(RTS_HANDLE hDatabase, RTS_HANDLE hObject);
typedef RTS_RESULT (CDECL * PFUSEROBJECTSDBCONFIGREMOVE) (RTS_HANDLE hDatabase, RTS_HANDLE hObject);
#if defined(CMPUSEROBJECTSDBCONFIGURATION_NOTIMPLEMENTED) || defined(USEROBJECTSDBCONFIGREMOVE_NOTIMPLEMENTED)
	#define USE_UserObjectsDBConfigRemove
	#define EXT_UserObjectsDBConfigRemove
	#define GET_UserObjectsDBConfigRemove(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBConfigRemove(p0,p1)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserObjectsDBConfigRemove  FALSE
	#define EXP_UserObjectsDBConfigRemove  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBConfigRemove
	#define EXT_UserObjectsDBConfigRemove
	#define GET_UserObjectsDBConfigRemove(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigRemove(p0,p1) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigRemove(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1))
	#define CHK_UserObjectsDBConfigRemove  TRUE
	#define EXP_UserObjectsDBConfigRemove  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDBCONFIGURATION_EXTERNAL)
	#define USE_UserObjectsDBConfigRemove
	#define EXT_UserObjectsDBConfigRemove
	#define GET_UserObjectsDBConfigRemove(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigRemove(p0,p1) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigRemove(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1))
	#define CHK_UserObjectsDBConfigRemove  TRUE
	#define EXP_UserObjectsDBConfigRemove  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBConfigurationUserObjectsDBConfigRemove
	#define EXT_CmpUserObjectsDBConfigurationUserObjectsDBConfigRemove
	#define GET_CmpUserObjectsDBConfigurationUserObjectsDBConfigRemove  ERR_OK
	#define CAL_CmpUserObjectsDBConfigurationUserObjectsDBConfigRemove(p0,p1)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigRemove(p1))
	#define CHK_CmpUserObjectsDBConfigurationUserObjectsDBConfigRemove  TRUE
	#define EXP_CmpUserObjectsDBConfigurationUserObjectsDBConfigRemove  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBConfigRemove
	#define EXT_UserObjectsDBConfigRemove
	#define GET_UserObjectsDBConfigRemove(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigRemove(p0,p1)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigRemove(p1))
	#define CHK_UserObjectsDBConfigRemove  TRUE
	#define EXP_UserObjectsDBConfigRemove  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBConfigRemove
	#define EXT_UserObjectsDBConfigRemove
	#define GET_UserObjectsDBConfigRemove(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigRemove(p0,p1) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigRemove(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1))
	#define CHK_UserObjectsDBConfigRemove  TRUE
	#define EXP_UserObjectsDBConfigRemove  ERR_OK
#endif




/**
 * <description>
 *	Add a new object under a father object specified by its name to the object management, so the access rights can be configured on that object.
 * </description>
 * <param name="hFatherObject" type="IN">Handle to the father object, under which the object will be added</param>
 * <param name="pszObject" type="IN">Object name (see object tree)</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Object could be added</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Object invalid = NULL or empty</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">The user management is not initialized or it is not loaded yet</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOMEMORY">If memory could not be allocated to store this object</errorcode>
 * <result>Handle to the object or RTS_INVALID_HANDLE if it could not be added</result>
 */
STATICITF_DEF RTS_HANDLE CDECL UserObjectsDBConfigAddChild(RTS_HANDLE hDatabase, RTS_HANDLE hFatherObject, char *pszObject, RTS_RESULT *pResult);
typedef RTS_HANDLE (CDECL * PFUSEROBJECTSDBCONFIGADDCHILD) (RTS_HANDLE hDatabase, RTS_HANDLE hFatherObject, char *pszObject, RTS_RESULT *pResult);
#if defined(CMPUSEROBJECTSDBCONFIGURATION_NOTIMPLEMENTED) || defined(USEROBJECTSDBCONFIGADDCHILD_NOTIMPLEMENTED)
	#define USE_UserObjectsDBConfigAddChild
	#define EXT_UserObjectsDBConfigAddChild
	#define GET_UserObjectsDBConfigAddChild(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBConfigAddChild(p0,p1,p2,p3)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_UserObjectsDBConfigAddChild  FALSE
	#define EXP_UserObjectsDBConfigAddChild  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBConfigAddChild
	#define EXT_UserObjectsDBConfigAddChild
	#define GET_UserObjectsDBConfigAddChild(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigAddChild(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigAddChild(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserObjectsDBConfigAddChild  TRUE
	#define EXP_UserObjectsDBConfigAddChild  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDBCONFIGURATION_EXTERNAL)
	#define USE_UserObjectsDBConfigAddChild
	#define EXT_UserObjectsDBConfigAddChild
	#define GET_UserObjectsDBConfigAddChild(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigAddChild(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigAddChild(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserObjectsDBConfigAddChild  TRUE
	#define EXP_UserObjectsDBConfigAddChild  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBConfigurationUserObjectsDBConfigAddChild
	#define EXT_CmpUserObjectsDBConfigurationUserObjectsDBConfigAddChild
	#define GET_CmpUserObjectsDBConfigurationUserObjectsDBConfigAddChild  ERR_OK
	#define CAL_CmpUserObjectsDBConfigurationUserObjectsDBConfigAddChild(p0,p1,p2,p3)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigAddChild(p1,p2,p3))
	#define CHK_CmpUserObjectsDBConfigurationUserObjectsDBConfigAddChild  TRUE
	#define EXP_CmpUserObjectsDBConfigurationUserObjectsDBConfigAddChild  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBConfigAddChild
	#define EXT_UserObjectsDBConfigAddChild
	#define GET_UserObjectsDBConfigAddChild(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigAddChild(p0,p1,p2,p3)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigAddChild(p1,p2,p3))
	#define CHK_UserObjectsDBConfigAddChild  TRUE
	#define EXP_UserObjectsDBConfigAddChild  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBConfigAddChild
	#define EXT_UserObjectsDBConfigAddChild
	#define GET_UserObjectsDBConfigAddChild(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigAddChild(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigAddChild(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserObjectsDBConfigAddChild  TRUE
	#define EXP_UserObjectsDBConfigAddChild  ERR_OK
#endif




/**
 * <description>
 *	Set the used access rights for the object specified by handle.
 *	The rights are additionally stored in an internal list. In case USERDB_RIGHT_NONE is passed for ulUsedRights the previously stored rights are retrieved for this object.
 * </description>
 * <param name="hObject" type="IN">Handle to the object</param>
 * <param name="ulUsedRights" type="IN">Used access rights or USERDB_RIGHT_NONE for retrieval</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Rights are successfully set</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid object handle</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">Object was not found for rights retrieval</errorcode>
 * <result>Error code</result>
 */
STATICITF_DEF RTS_RESULT CDECL UserObjectsDBConfigSetUsedRights(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_UI32 ulUsedRights);
typedef RTS_RESULT (CDECL * PFUSEROBJECTSDBCONFIGSETUSEDRIGHTS) (RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_UI32 ulUsedRights);
#if defined(CMPUSEROBJECTSDBCONFIGURATION_NOTIMPLEMENTED) || defined(USEROBJECTSDBCONFIGSETUSEDRIGHTS_NOTIMPLEMENTED)
	#define USE_UserObjectsDBConfigSetUsedRights
	#define EXT_UserObjectsDBConfigSetUsedRights
	#define GET_UserObjectsDBConfigSetUsedRights(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBConfigSetUsedRights(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserObjectsDBConfigSetUsedRights  FALSE
	#define EXP_UserObjectsDBConfigSetUsedRights  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBConfigSetUsedRights
	#define EXT_UserObjectsDBConfigSetUsedRights
	#define GET_UserObjectsDBConfigSetUsedRights(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigSetUsedRights(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigSetUsedRights(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBConfigSetUsedRights  TRUE
	#define EXP_UserObjectsDBConfigSetUsedRights  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDBCONFIGURATION_EXTERNAL)
	#define USE_UserObjectsDBConfigSetUsedRights
	#define EXT_UserObjectsDBConfigSetUsedRights
	#define GET_UserObjectsDBConfigSetUsedRights(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigSetUsedRights(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigSetUsedRights(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBConfigSetUsedRights  TRUE
	#define EXP_UserObjectsDBConfigSetUsedRights  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBConfigurationUserObjectsDBConfigSetUsedRights
	#define EXT_CmpUserObjectsDBConfigurationUserObjectsDBConfigSetUsedRights
	#define GET_CmpUserObjectsDBConfigurationUserObjectsDBConfigSetUsedRights  ERR_OK
	#define CAL_CmpUserObjectsDBConfigurationUserObjectsDBConfigSetUsedRights(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigSetUsedRights(p1,p2))
	#define CHK_CmpUserObjectsDBConfigurationUserObjectsDBConfigSetUsedRights  TRUE
	#define EXP_CmpUserObjectsDBConfigurationUserObjectsDBConfigSetUsedRights  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBConfigSetUsedRights
	#define EXT_UserObjectsDBConfigSetUsedRights
	#define GET_UserObjectsDBConfigSetUsedRights(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigSetUsedRights(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigSetUsedRights(p1,p2))
	#define CHK_UserObjectsDBConfigSetUsedRights  TRUE
	#define EXP_UserObjectsDBConfigSetUsedRights  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBConfigSetUsedRights
	#define EXT_UserObjectsDBConfigSetUsedRights
	#define GET_UserObjectsDBConfigSetUsedRights(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigSetUsedRights(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigSetUsedRights(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBConfigSetUsedRights  TRUE
	#define EXP_UserObjectsDBConfigSetUsedRights  ERR_OK
#endif




/**
 * <description>Set a unique identifier of an object</description>
 * <param name="hObject" type="IN">Handle to object</param>
 * <param name="ulID" type="IN">ObjectID to set</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">ObjectID could be set</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid object handle</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserObjectsDBConfigSetID(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_UI32 ulID);
typedef RTS_RESULT (CDECL * PFUSEROBJECTSDBCONFIGSETID) (RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_UI32 ulID);
#if defined(CMPUSEROBJECTSDBCONFIGURATION_NOTIMPLEMENTED) || defined(USEROBJECTSDBCONFIGSETID_NOTIMPLEMENTED)
	#define USE_UserObjectsDBConfigSetID
	#define EXT_UserObjectsDBConfigSetID
	#define GET_UserObjectsDBConfigSetID(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBConfigSetID(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserObjectsDBConfigSetID  FALSE
	#define EXP_UserObjectsDBConfigSetID  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBConfigSetID
	#define EXT_UserObjectsDBConfigSetID
	#define GET_UserObjectsDBConfigSetID(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigSetID(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigSetID(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBConfigSetID  TRUE
	#define EXP_UserObjectsDBConfigSetID  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDBCONFIGURATION_EXTERNAL)
	#define USE_UserObjectsDBConfigSetID
	#define EXT_UserObjectsDBConfigSetID
	#define GET_UserObjectsDBConfigSetID(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigSetID(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigSetID(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBConfigSetID  TRUE
	#define EXP_UserObjectsDBConfigSetID  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBConfigurationUserObjectsDBConfigSetID
	#define EXT_CmpUserObjectsDBConfigurationUserObjectsDBConfigSetID
	#define GET_CmpUserObjectsDBConfigurationUserObjectsDBConfigSetID  ERR_OK
	#define CAL_CmpUserObjectsDBConfigurationUserObjectsDBConfigSetID(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigSetID(p1,p2))
	#define CHK_CmpUserObjectsDBConfigurationUserObjectsDBConfigSetID  TRUE
	#define EXP_CmpUserObjectsDBConfigurationUserObjectsDBConfigSetID  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBConfigSetID
	#define EXT_UserObjectsDBConfigSetID
	#define GET_UserObjectsDBConfigSetID(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigSetID(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigSetID(p1,p2))
	#define CHK_UserObjectsDBConfigSetID  TRUE
	#define EXP_UserObjectsDBConfigSetID  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBConfigSetID
	#define EXT_UserObjectsDBConfigSetID
	#define GET_UserObjectsDBConfigSetID(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigSetID(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigSetID(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBConfigSetID  TRUE
	#define EXP_UserObjectsDBConfigSetID  ERR_OK
#endif




/* Rights management configuration */

/**
 * <description>Add a group to the specified object to manage access rights</description>
 * <param name="hObject" type="IN">Handle to object</param>
 * <param name="hGroup" type="IN">Handle to the group that should be attached</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Group could be added or is already added</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid handles</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOMEMORY">No memory to add group</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserObjectsDBConfigAddGroup(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_HANDLE hGroup);
typedef RTS_RESULT (CDECL * PFUSEROBJECTSDBCONFIGADDGROUP) (RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_HANDLE hGroup);
#if defined(CMPUSEROBJECTSDBCONFIGURATION_NOTIMPLEMENTED) || defined(USEROBJECTSDBCONFIGADDGROUP_NOTIMPLEMENTED)
	#define USE_UserObjectsDBConfigAddGroup
	#define EXT_UserObjectsDBConfigAddGroup
	#define GET_UserObjectsDBConfigAddGroup(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBConfigAddGroup(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserObjectsDBConfigAddGroup  FALSE
	#define EXP_UserObjectsDBConfigAddGroup  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBConfigAddGroup
	#define EXT_UserObjectsDBConfigAddGroup
	#define GET_UserObjectsDBConfigAddGroup(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigAddGroup(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigAddGroup(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBConfigAddGroup  TRUE
	#define EXP_UserObjectsDBConfigAddGroup  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDBCONFIGURATION_EXTERNAL)
	#define USE_UserObjectsDBConfigAddGroup
	#define EXT_UserObjectsDBConfigAddGroup
	#define GET_UserObjectsDBConfigAddGroup(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigAddGroup(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigAddGroup(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBConfigAddGroup  TRUE
	#define EXP_UserObjectsDBConfigAddGroup  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBConfigurationUserObjectsDBConfigAddGroup
	#define EXT_CmpUserObjectsDBConfigurationUserObjectsDBConfigAddGroup
	#define GET_CmpUserObjectsDBConfigurationUserObjectsDBConfigAddGroup  ERR_OK
	#define CAL_CmpUserObjectsDBConfigurationUserObjectsDBConfigAddGroup(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigAddGroup(p1,p2))
	#define CHK_CmpUserObjectsDBConfigurationUserObjectsDBConfigAddGroup  TRUE
	#define EXP_CmpUserObjectsDBConfigurationUserObjectsDBConfigAddGroup  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBConfigAddGroup
	#define EXT_UserObjectsDBConfigAddGroup
	#define GET_UserObjectsDBConfigAddGroup(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigAddGroup(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigAddGroup(p1,p2))
	#define CHK_UserObjectsDBConfigAddGroup  TRUE
	#define EXP_UserObjectsDBConfigAddGroup  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBConfigAddGroup
	#define EXT_UserObjectsDBConfigAddGroup
	#define GET_UserObjectsDBConfigAddGroup(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigAddGroup(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigAddGroup(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBConfigAddGroup  TRUE
	#define EXP_UserObjectsDBConfigAddGroup  ERR_OK
#endif




/**
 * <description>Remove a group from the specified object</description>
 * <param name="hObject" type="IN">Handle to object</param>
 * <param name="hGroup" type="IN">Handle to the group that should be removed</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Group could be removed</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid handles</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserObjectsDBConfigRemoveGroup(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_HANDLE hGroup);
typedef RTS_RESULT (CDECL * PFUSEROBJECTSDBCONFIGREMOVEGROUP) (RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_HANDLE hGroup);
#if defined(CMPUSEROBJECTSDBCONFIGURATION_NOTIMPLEMENTED) || defined(USEROBJECTSDBCONFIGREMOVEGROUP_NOTIMPLEMENTED)
	#define USE_UserObjectsDBConfigRemoveGroup
	#define EXT_UserObjectsDBConfigRemoveGroup
	#define GET_UserObjectsDBConfigRemoveGroup(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBConfigRemoveGroup(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserObjectsDBConfigRemoveGroup  FALSE
	#define EXP_UserObjectsDBConfigRemoveGroup  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBConfigRemoveGroup
	#define EXT_UserObjectsDBConfigRemoveGroup
	#define GET_UserObjectsDBConfigRemoveGroup(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigRemoveGroup(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigRemoveGroup(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBConfigRemoveGroup  TRUE
	#define EXP_UserObjectsDBConfigRemoveGroup  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDBCONFIGURATION_EXTERNAL)
	#define USE_UserObjectsDBConfigRemoveGroup
	#define EXT_UserObjectsDBConfigRemoveGroup
	#define GET_UserObjectsDBConfigRemoveGroup(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigRemoveGroup(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigRemoveGroup(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBConfigRemoveGroup  TRUE
	#define EXP_UserObjectsDBConfigRemoveGroup  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBConfigurationUserObjectsDBConfigRemoveGroup
	#define EXT_CmpUserObjectsDBConfigurationUserObjectsDBConfigRemoveGroup
	#define GET_CmpUserObjectsDBConfigurationUserObjectsDBConfigRemoveGroup  ERR_OK
	#define CAL_CmpUserObjectsDBConfigurationUserObjectsDBConfigRemoveGroup(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigRemoveGroup(p1,p2))
	#define CHK_CmpUserObjectsDBConfigurationUserObjectsDBConfigRemoveGroup  TRUE
	#define EXP_CmpUserObjectsDBConfigurationUserObjectsDBConfigRemoveGroup  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBConfigRemoveGroup
	#define EXT_UserObjectsDBConfigRemoveGroup
	#define GET_UserObjectsDBConfigRemoveGroup(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigRemoveGroup(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigRemoveGroup(p1,p2))
	#define CHK_UserObjectsDBConfigRemoveGroup  TRUE
	#define EXP_UserObjectsDBConfigRemoveGroup  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBConfigRemoveGroup
	#define EXT_UserObjectsDBConfigRemoveGroup
	#define GET_UserObjectsDBConfigRemoveGroup(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigRemoveGroup(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigRemoveGroup(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBConfigRemoveGroup  TRUE
	#define EXP_UserObjectsDBConfigRemoveGroup  ERR_OK
#endif




/**
 * <description>Set the access rights for the group at the specified object</description>
 * <param name="hObject" type="IN">Handle to object</param>
 * <param name="hGroup" type="IN">Handle to the group</param>
 * <element name="ulRights" type="IN">Rights of the group. See category "User rights" for details</element>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Access rights could be set</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid handles</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserObjectsDBConfigSetGroupRights(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_HANDLE hGroup, RTS_UI32 ulRights);
typedef RTS_RESULT (CDECL * PFUSEROBJECTSDBCONFIGSETGROUPRIGHTS) (RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_HANDLE hGroup, RTS_UI32 ulRights);
#if defined(CMPUSEROBJECTSDBCONFIGURATION_NOTIMPLEMENTED) || defined(USEROBJECTSDBCONFIGSETGROUPRIGHTS_NOTIMPLEMENTED)
	#define USE_UserObjectsDBConfigSetGroupRights
	#define EXT_UserObjectsDBConfigSetGroupRights
	#define GET_UserObjectsDBConfigSetGroupRights(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBConfigSetGroupRights(p0,p1,p2,p3)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserObjectsDBConfigSetGroupRights  FALSE
	#define EXP_UserObjectsDBConfigSetGroupRights  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBConfigSetGroupRights
	#define EXT_UserObjectsDBConfigSetGroupRights
	#define GET_UserObjectsDBConfigSetGroupRights(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigSetGroupRights(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigSetGroupRights(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserObjectsDBConfigSetGroupRights  TRUE
	#define EXP_UserObjectsDBConfigSetGroupRights  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDBCONFIGURATION_EXTERNAL)
	#define USE_UserObjectsDBConfigSetGroupRights
	#define EXT_UserObjectsDBConfigSetGroupRights
	#define GET_UserObjectsDBConfigSetGroupRights(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigSetGroupRights(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigSetGroupRights(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserObjectsDBConfigSetGroupRights  TRUE
	#define EXP_UserObjectsDBConfigSetGroupRights  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBConfigurationUserObjectsDBConfigSetGroupRights
	#define EXT_CmpUserObjectsDBConfigurationUserObjectsDBConfigSetGroupRights
	#define GET_CmpUserObjectsDBConfigurationUserObjectsDBConfigSetGroupRights  ERR_OK
	#define CAL_CmpUserObjectsDBConfigurationUserObjectsDBConfigSetGroupRights(p0,p1,p2,p3)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigSetGroupRights(p1,p2,p3))
	#define CHK_CmpUserObjectsDBConfigurationUserObjectsDBConfigSetGroupRights  TRUE
	#define EXP_CmpUserObjectsDBConfigurationUserObjectsDBConfigSetGroupRights  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBConfigSetGroupRights
	#define EXT_UserObjectsDBConfigSetGroupRights
	#define GET_UserObjectsDBConfigSetGroupRights(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigSetGroupRights(p0,p1,p2,p3)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigSetGroupRights(p1,p2,p3))
	#define CHK_UserObjectsDBConfigSetGroupRights  TRUE
	#define EXP_UserObjectsDBConfigSetGroupRights  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBConfigSetGroupRights
	#define EXT_UserObjectsDBConfigSetGroupRights
	#define GET_UserObjectsDBConfigSetGroupRights(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigSetGroupRights(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigSetGroupRights(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserObjectsDBConfigSetGroupRights  TRUE
	#define EXP_UserObjectsDBConfigSetGroupRights  ERR_OK
#endif




/**
 * <description>Set the denied access rights for the group at the specified object</description>
 * <param name="hObject" type="IN">Handle to object</param>
 * <param name="hGroup" type="IN">Handle to the group</param>
 * <element name="ulDeniedRights" type="IN">Denied rights of the group. See category "User rights" for details</element>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Access rights could be set</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid handles</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserObjectsDBConfigSetGroupDeniedRights(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_HANDLE hGroup, RTS_UI32 ulDeniedRights);
typedef RTS_RESULT (CDECL * PFUSEROBJECTSDBCONFIGSETGROUPDENIEDRIGHTS) (RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_HANDLE hGroup, RTS_UI32 ulDeniedRights);
#if defined(CMPUSEROBJECTSDBCONFIGURATION_NOTIMPLEMENTED) || defined(USEROBJECTSDBCONFIGSETGROUPDENIEDRIGHTS_NOTIMPLEMENTED)
	#define USE_UserObjectsDBConfigSetGroupDeniedRights
	#define EXT_UserObjectsDBConfigSetGroupDeniedRights
	#define GET_UserObjectsDBConfigSetGroupDeniedRights(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBConfigSetGroupDeniedRights(p0,p1,p2,p3)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserObjectsDBConfigSetGroupDeniedRights  FALSE
	#define EXP_UserObjectsDBConfigSetGroupDeniedRights  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBConfigSetGroupDeniedRights
	#define EXT_UserObjectsDBConfigSetGroupDeniedRights
	#define GET_UserObjectsDBConfigSetGroupDeniedRights(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigSetGroupDeniedRights(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigSetGroupDeniedRights(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserObjectsDBConfigSetGroupDeniedRights  TRUE
	#define EXP_UserObjectsDBConfigSetGroupDeniedRights  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDBCONFIGURATION_EXTERNAL)
	#define USE_UserObjectsDBConfigSetGroupDeniedRights
	#define EXT_UserObjectsDBConfigSetGroupDeniedRights
	#define GET_UserObjectsDBConfigSetGroupDeniedRights(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigSetGroupDeniedRights(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigSetGroupDeniedRights(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserObjectsDBConfigSetGroupDeniedRights  TRUE
	#define EXP_UserObjectsDBConfigSetGroupDeniedRights  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBConfigurationUserObjectsDBConfigSetGroupDeniedRights
	#define EXT_CmpUserObjectsDBConfigurationUserObjectsDBConfigSetGroupDeniedRights
	#define GET_CmpUserObjectsDBConfigurationUserObjectsDBConfigSetGroupDeniedRights  ERR_OK
	#define CAL_CmpUserObjectsDBConfigurationUserObjectsDBConfigSetGroupDeniedRights(p0,p1,p2,p3)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigSetGroupDeniedRights(p1,p2,p3))
	#define CHK_CmpUserObjectsDBConfigurationUserObjectsDBConfigSetGroupDeniedRights  TRUE
	#define EXP_CmpUserObjectsDBConfigurationUserObjectsDBConfigSetGroupDeniedRights  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBConfigSetGroupDeniedRights
	#define EXT_UserObjectsDBConfigSetGroupDeniedRights
	#define GET_UserObjectsDBConfigSetGroupDeniedRights(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigSetGroupDeniedRights(p0,p1,p2,p3)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigSetGroupDeniedRights(p1,p2,p3))
	#define CHK_UserObjectsDBConfigSetGroupDeniedRights  TRUE
	#define EXP_UserObjectsDBConfigSetGroupDeniedRights  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBConfigSetGroupDeniedRights
	#define EXT_UserObjectsDBConfigSetGroupDeniedRights
	#define GET_UserObjectsDBConfigSetGroupDeniedRights(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigSetGroupDeniedRights(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigSetGroupDeniedRights(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserObjectsDBConfigSetGroupDeniedRights  TRUE
	#define EXP_UserObjectsDBConfigSetGroupDeniedRights  ERR_OK
#endif





/**
 * <description>This function clears all granted and denied rights for all groups on that object.</description>
 * <param name="hObject" type="IN">Handle to object</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Access rights could be set</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid handles</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserObjectsDBConfigClearRights(RTS_HANDLE hDatabase, RTS_HANDLE hObject);
typedef RTS_RESULT (CDECL * PFUSEROBJECTSDBCONFIGCLEARRIGHTS) (RTS_HANDLE hDatabase, RTS_HANDLE hObject);
#if defined(CMPUSEROBJECTSDBCONFIGURATION_NOTIMPLEMENTED) || defined(USEROBJECTSDBCONFIGCLEARRIGHTS_NOTIMPLEMENTED)
	#define USE_UserObjectsDBConfigClearRights
	#define EXT_UserObjectsDBConfigClearRights
	#define GET_UserObjectsDBConfigClearRights(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBConfigClearRights(p0,p1)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserObjectsDBConfigClearRights  FALSE
	#define EXP_UserObjectsDBConfigClearRights  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBConfigClearRights
	#define EXT_UserObjectsDBConfigClearRights
	#define GET_UserObjectsDBConfigClearRights(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigClearRights(p0,p1) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigClearRights(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1))
	#define CHK_UserObjectsDBConfigClearRights  TRUE
	#define EXP_UserObjectsDBConfigClearRights  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDBCONFIGURATION_EXTERNAL)
	#define USE_UserObjectsDBConfigClearRights
	#define EXT_UserObjectsDBConfigClearRights
	#define GET_UserObjectsDBConfigClearRights(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigClearRights(p0,p1) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigClearRights(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1))
	#define CHK_UserObjectsDBConfigClearRights  TRUE
	#define EXP_UserObjectsDBConfigClearRights  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBConfigurationUserObjectsDBConfigClearRights
	#define EXT_CmpUserObjectsDBConfigurationUserObjectsDBConfigClearRights
	#define GET_CmpUserObjectsDBConfigurationUserObjectsDBConfigClearRights  ERR_OK
	#define CAL_CmpUserObjectsDBConfigurationUserObjectsDBConfigClearRights(p0,p1)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigClearRights(p1))
	#define CHK_CmpUserObjectsDBConfigurationUserObjectsDBConfigClearRights  TRUE
	#define EXP_CmpUserObjectsDBConfigurationUserObjectsDBConfigClearRights  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBConfigClearRights
	#define EXT_UserObjectsDBConfigClearRights
	#define GET_UserObjectsDBConfigClearRights(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigClearRights(p0,p1)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigClearRights(p1))
	#define CHK_UserObjectsDBConfigClearRights  TRUE
	#define EXP_UserObjectsDBConfigClearRights  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBConfigClearRights
	#define EXT_UserObjectsDBConfigClearRights
	#define GET_UserObjectsDBConfigClearRights(fl)  ERR_OK
	#define CAL_UserObjectsDBConfigClearRights(p0,p1) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDBConfiguration*)p0)->IUserObjectsDBConfigClearRights(((ICmpUserObjectsDBConfiguration*)p0)->pBase->hInstance,p1))
	#define CHK_UserObjectsDBConfigClearRights  TRUE
	#define EXP_UserObjectsDBConfigClearRights  ERR_OK
#endif




#ifdef __cplusplus
}
#endif



typedef struct
{
	IBase_C *pBase;
	PFUSEROBJECTSDBCONFIGLOAD IUserObjectsDBConfigLoad;
 	PFUSEROBJECTSDBCONFIGSTORE IUserObjectsDBConfigStore;
 	PFUSEROBJECTSDBCONFIGRELEASE IUserObjectsDBConfigRelease;
 	PFUSEROBJECTSDBCONFIGRELEASERIGHTS IUserObjectsDBConfigReleaseRights;
 	PFUSEROBJECTSDBCONFIGADD IUserObjectsDBConfigAdd;
 	PFUSEROBJECTSDBCONFIGADD2 IUserObjectsDBConfigAdd2;
 	PFUSEROBJECTSDBCONFIGREMOVE IUserObjectsDBConfigRemove;
 	PFUSEROBJECTSDBCONFIGADDCHILD IUserObjectsDBConfigAddChild;
 	PFUSEROBJECTSDBCONFIGSETUSEDRIGHTS IUserObjectsDBConfigSetUsedRights;
 	PFUSEROBJECTSDBCONFIGSETID IUserObjectsDBConfigSetID;
 	PFUSEROBJECTSDBCONFIGADDGROUP IUserObjectsDBConfigAddGroup;
 	PFUSEROBJECTSDBCONFIGREMOVEGROUP IUserObjectsDBConfigRemoveGroup;
 	PFUSEROBJECTSDBCONFIGSETGROUPRIGHTS IUserObjectsDBConfigSetGroupRights;
 	PFUSEROBJECTSDBCONFIGSETGROUPDENIEDRIGHTS IUserObjectsDBConfigSetGroupDeniedRights;
 	PFUSEROBJECTSDBCONFIGCLEARRIGHTS IUserObjectsDBConfigClearRights;
 } ICmpUserObjectsDBConfiguration_C;

#ifdef CPLUSPLUS
class ICmpUserObjectsDBConfiguration : public IBase
{
	public:
		virtual RTS_RESULT CDECL IUserObjectsDBConfigLoad(void) =0;
		virtual RTS_RESULT CDECL IUserObjectsDBConfigStore(void) =0;
		virtual RTS_RESULT CDECL IUserObjectsDBConfigRelease(void) =0;
		virtual RTS_RESULT CDECL IUserObjectsDBConfigReleaseRights(void) =0;
		virtual RTS_HANDLE CDECL IUserObjectsDBConfigAdd(char *pszObject, RTS_RESULT *pResult) =0;
		virtual RTS_HANDLE CDECL IUserObjectsDBConfigAdd2(char *pszObject, RTS_UI32 properties, RTS_RESULT *pResult) =0;
		virtual RTS_RESULT CDECL IUserObjectsDBConfigRemove(RTS_HANDLE hObject) =0;
		virtual RTS_HANDLE CDECL IUserObjectsDBConfigAddChild(RTS_HANDLE hFatherObject, char *pszObject, RTS_RESULT *pResult) =0;
		virtual RTS_RESULT CDECL IUserObjectsDBConfigSetUsedRights(RTS_HANDLE hObject, RTS_UI32 ulUsedRights) =0;
		virtual RTS_RESULT CDECL IUserObjectsDBConfigSetID(RTS_HANDLE hObject, RTS_UI32 ulID) =0;
		virtual RTS_RESULT CDECL IUserObjectsDBConfigAddGroup(RTS_HANDLE hObject, RTS_HANDLE hGroup) =0;
		virtual RTS_RESULT CDECL IUserObjectsDBConfigRemoveGroup(RTS_HANDLE hObject, RTS_HANDLE hGroup) =0;
		virtual RTS_RESULT CDECL IUserObjectsDBConfigSetGroupRights(RTS_HANDLE hObject, RTS_HANDLE hGroup, RTS_UI32 ulRights) =0;
		virtual RTS_RESULT CDECL IUserObjectsDBConfigSetGroupDeniedRights(RTS_HANDLE hObject, RTS_HANDLE hGroup, RTS_UI32 ulDeniedRights) =0;
		virtual RTS_RESULT CDECL IUserObjectsDBConfigClearRights(RTS_HANDLE hObject) =0;
};
	#ifndef ITF_CmpUserObjectsDBConfiguration
		#define ITF_CmpUserObjectsDBConfiguration static ICmpUserObjectsDBConfiguration *pICmpUserObjectsDBConfiguration = NULL;
	#endif
	#define EXTITF_CmpUserObjectsDBConfiguration
#else	/*CPLUSPLUS*/
	typedef ICmpUserObjectsDBConfiguration_C		ICmpUserObjectsDBConfiguration;
	#ifndef ITF_CmpUserObjectsDBConfiguration
		#define ITF_CmpUserObjectsDBConfiguration
	#endif
	#define EXTITF_CmpUserObjectsDBConfiguration
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_CMPUSEROBJECTSDBCONFIGURATIONITF_H_*/
