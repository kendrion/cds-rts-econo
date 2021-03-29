 /**
 * <interfacename>CmpUserDBConfiguration</interfacename>
 * <description>
 *	This interface is used to configure a user database.
 *
 *  If a user database is not configurable (e.g. the implementation depends on the operating system) this interface must not be implemented by the
 *  database component. This allows only the authentication of users from different clients but not the configuration of users using the 
 *  CODESYS online services.
 * </description>
 *
 * <copyright>
 * Copyright (c) 2019 CODESYS Development GmbH. All rights reserved.
 * </copyright>
 */


	
	
#ifndef _CMPUSERDBCONFIGURATIONITF_H_
#define _CMPUSERDBCONFIGURATIONITF_H_

#include "CmpStd.h"

 

 



#include "CmpUserDBItf.h"

/**
 * <description>Clear the complete user database.</description>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Succeeded</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Failed releasing user management</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserDBConfigRelease(RTS_HANDLE hDatabase);
typedef RTS_RESULT (CDECL * PFUSERDBCONFIGRELEASE) (RTS_HANDLE hDatabase);
#if defined(CMPUSERDBCONFIGURATION_NOTIMPLEMENTED) || defined(USERDBCONFIGRELEASE_NOTIMPLEMENTED)
	#define USE_UserDBConfigRelease
	#define EXT_UserDBConfigRelease
	#define GET_UserDBConfigRelease(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserDBConfigRelease(p0)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserDBConfigRelease  FALSE
	#define EXP_UserDBConfigRelease  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserDBConfigRelease
	#define EXT_UserDBConfigRelease
	#define GET_UserDBConfigRelease(fl)  ERR_OK
	#define CAL_UserDBConfigRelease(p0) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigRelease(((ICmpUserDBConfiguration*)p0)->pBase->hInstance))
	#define CHK_UserDBConfigRelease  TRUE
	#define EXP_UserDBConfigRelease  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSERDBCONFIGURATION_EXTERNAL)
	#define USE_UserDBConfigRelease
	#define EXT_UserDBConfigRelease
	#define GET_UserDBConfigRelease(fl)  ERR_OK
	#define CAL_UserDBConfigRelease(p0) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigRelease(((ICmpUserDBConfiguration*)p0)->pBase->hInstance))
	#define CHK_UserDBConfigRelease  TRUE
	#define EXP_UserDBConfigRelease  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserDBConfigurationUserDBConfigRelease
	#define EXT_CmpUserDBConfigurationUserDBConfigRelease
	#define GET_CmpUserDBConfigurationUserDBConfigRelease  ERR_OK
	#define CAL_CmpUserDBConfigurationUserDBConfigRelease(p0)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigRelease())
	#define CHK_CmpUserDBConfigurationUserDBConfigRelease  TRUE
	#define EXP_CmpUserDBConfigurationUserDBConfigRelease  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserDBConfigRelease
	#define EXT_UserDBConfigRelease
	#define GET_UserDBConfigRelease(fl)  ERR_OK
	#define CAL_UserDBConfigRelease(p0)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigRelease())
	#define CHK_UserDBConfigRelease  TRUE
	#define EXP_UserDBConfigRelease  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserDBConfigRelease
	#define EXT_UserDBConfigRelease
	#define GET_UserDBConfigRelease(fl)  ERR_OK
	#define CAL_UserDBConfigRelease(p0) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigRelease(((ICmpUserDBConfiguration*)p0)->pBase->hInstance))
	#define CHK_UserDBConfigRelease  TRUE
	#define EXP_UserDBConfigRelease  ERR_OK
#endif




/**
 * <description>Import the user database from a backup.</description>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Succeeded</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Failed releasing user management</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserDBConfigImport(RTS_HANDLE hDatabase, RTS_UI8 *pData, RTS_SIZE dataSize);
typedef RTS_RESULT (CDECL * PFUSERDBCONFIGIMPORT) (RTS_HANDLE hDatabase, RTS_UI8 *pData, RTS_SIZE dataSize);
#if defined(CMPUSERDBCONFIGURATION_NOTIMPLEMENTED) || defined(USERDBCONFIGIMPORT_NOTIMPLEMENTED)
	#define USE_UserDBConfigImport
	#define EXT_UserDBConfigImport
	#define GET_UserDBConfigImport(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserDBConfigImport(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserDBConfigImport  FALSE
	#define EXP_UserDBConfigImport  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserDBConfigImport
	#define EXT_UserDBConfigImport
	#define GET_UserDBConfigImport(fl)  ERR_OK
	#define CAL_UserDBConfigImport(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigImport(((ICmpUserDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserDBConfigImport  TRUE
	#define EXP_UserDBConfigImport  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSERDBCONFIGURATION_EXTERNAL)
	#define USE_UserDBConfigImport
	#define EXT_UserDBConfigImport
	#define GET_UserDBConfigImport(fl)  ERR_OK
	#define CAL_UserDBConfigImport(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigImport(((ICmpUserDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserDBConfigImport  TRUE
	#define EXP_UserDBConfigImport  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserDBConfigurationUserDBConfigImport
	#define EXT_CmpUserDBConfigurationUserDBConfigImport
	#define GET_CmpUserDBConfigurationUserDBConfigImport  ERR_OK
	#define CAL_CmpUserDBConfigurationUserDBConfigImport(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigImport(p1,p2))
	#define CHK_CmpUserDBConfigurationUserDBConfigImport  TRUE
	#define EXP_CmpUserDBConfigurationUserDBConfigImport  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserDBConfigImport
	#define EXT_UserDBConfigImport
	#define GET_UserDBConfigImport(fl)  ERR_OK
	#define CAL_UserDBConfigImport(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigImport(p1,p2))
	#define CHK_UserDBConfigImport  TRUE
	#define EXP_UserDBConfigImport  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserDBConfigImport
	#define EXT_UserDBConfigImport
	#define GET_UserDBConfigImport(fl)  ERR_OK
	#define CAL_UserDBConfigImport(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigImport(((ICmpUserDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserDBConfigImport  TRUE
	#define EXP_UserDBConfigImport  ERR_OK
#endif




/**
 * <description>Export the user database into a backup.</description>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Succeeded</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Failed releasing user management</errorcode>
 */
STATICITF_DEF RTS_SIZE CDECL UserDBConfigExport(RTS_HANDLE hDatabase, RTS_UI8 *pData, RTS_SIZE maxSize, RTS_RESULT *pResult);
typedef RTS_SIZE (CDECL * PFUSERDBCONFIGEXPORT) (RTS_HANDLE hDatabase, RTS_UI8 *pData, RTS_SIZE maxSize, RTS_RESULT *pResult);
#if defined(CMPUSERDBCONFIGURATION_NOTIMPLEMENTED) || defined(USERDBCONFIGEXPORT_NOTIMPLEMENTED)
	#define USE_UserDBConfigExport
	#define EXT_UserDBConfigExport
	#define GET_UserDBConfigExport(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserDBConfigExport(p0,p1,p2,p3)  (RTS_SIZE)ERR_NOTIMPLEMENTED
	#define CHK_UserDBConfigExport  FALSE
	#define EXP_UserDBConfigExport  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserDBConfigExport
	#define EXT_UserDBConfigExport
	#define GET_UserDBConfigExport(fl)  ERR_OK
	#define CAL_UserDBConfigExport(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigExport(((ICmpUserDBConfiguration*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserDBConfigExport  TRUE
	#define EXP_UserDBConfigExport  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSERDBCONFIGURATION_EXTERNAL)
	#define USE_UserDBConfigExport
	#define EXT_UserDBConfigExport
	#define GET_UserDBConfigExport(fl)  ERR_OK
	#define CAL_UserDBConfigExport(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigExport(((ICmpUserDBConfiguration*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserDBConfigExport  TRUE
	#define EXP_UserDBConfigExport  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserDBConfigurationUserDBConfigExport
	#define EXT_CmpUserDBConfigurationUserDBConfigExport
	#define GET_CmpUserDBConfigurationUserDBConfigExport  ERR_OK
	#define CAL_CmpUserDBConfigurationUserDBConfigExport(p0,p1,p2,p3)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigExport(p1,p2,p3))
	#define CHK_CmpUserDBConfigurationUserDBConfigExport  TRUE
	#define EXP_CmpUserDBConfigurationUserDBConfigExport  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserDBConfigExport
	#define EXT_UserDBConfigExport
	#define GET_UserDBConfigExport(fl)  ERR_OK
	#define CAL_UserDBConfigExport(p0,p1,p2,p3)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigExport(p1,p2,p3))
	#define CHK_UserDBConfigExport  TRUE
	#define EXP_UserDBConfigExport  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserDBConfigExport
	#define EXT_UserDBConfigExport
	#define GET_UserDBConfigExport(fl)  ERR_OK
	#define CAL_UserDBConfigExport(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigExport(((ICmpUserDBConfiguration*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserDBConfigExport  TRUE
	#define EXP_UserDBConfigExport  ERR_OK
#endif




/**
 * <description>Add a new user to the user database</description>
 * <param name="hDatabase" type="IN">Handle to the configuration database.</param>
 * <param name="pszUser" type="IN">User name.</param>
 * <param name="pszPassword" type="IN">The users password.</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">User could be added</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_DUPLICATE">User already exists</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter. pszUser = NULL or empty</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOMEMORY">No memory available to store new user</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">The user management is not initialized or it is not loaded yet</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserDBConfigAddUser(RTS_HANDLE hDatabase, char *pszUser, UserMgrCredentials *pCredentials);
typedef RTS_RESULT (CDECL * PFUSERDBCONFIGADDUSER) (RTS_HANDLE hDatabase, char *pszUser, UserMgrCredentials *pCredentials);
#if defined(CMPUSERDBCONFIGURATION_NOTIMPLEMENTED) || defined(USERDBCONFIGADDUSER_NOTIMPLEMENTED)
	#define USE_UserDBConfigAddUser
	#define EXT_UserDBConfigAddUser
	#define GET_UserDBConfigAddUser(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserDBConfigAddUser(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserDBConfigAddUser  FALSE
	#define EXP_UserDBConfigAddUser  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserDBConfigAddUser
	#define EXT_UserDBConfigAddUser
	#define GET_UserDBConfigAddUser(fl)  ERR_OK
	#define CAL_UserDBConfigAddUser(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigAddUser(((ICmpUserDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserDBConfigAddUser  TRUE
	#define EXP_UserDBConfigAddUser  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSERDBCONFIGURATION_EXTERNAL)
	#define USE_UserDBConfigAddUser
	#define EXT_UserDBConfigAddUser
	#define GET_UserDBConfigAddUser(fl)  ERR_OK
	#define CAL_UserDBConfigAddUser(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigAddUser(((ICmpUserDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserDBConfigAddUser  TRUE
	#define EXP_UserDBConfigAddUser  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserDBConfigurationUserDBConfigAddUser
	#define EXT_CmpUserDBConfigurationUserDBConfigAddUser
	#define GET_CmpUserDBConfigurationUserDBConfigAddUser  ERR_OK
	#define CAL_CmpUserDBConfigurationUserDBConfigAddUser(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigAddUser(p1,p2))
	#define CHK_CmpUserDBConfigurationUserDBConfigAddUser  TRUE
	#define EXP_CmpUserDBConfigurationUserDBConfigAddUser  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserDBConfigAddUser
	#define EXT_UserDBConfigAddUser
	#define GET_UserDBConfigAddUser(fl)  ERR_OK
	#define CAL_UserDBConfigAddUser(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigAddUser(p1,p2))
	#define CHK_UserDBConfigAddUser  TRUE
	#define EXP_UserDBConfigAddUser  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserDBConfigAddUser
	#define EXT_UserDBConfigAddUser
	#define GET_UserDBConfigAddUser(fl)  ERR_OK
	#define CAL_UserDBConfigAddUser(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigAddUser(((ICmpUserDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserDBConfigAddUser  TRUE
	#define EXP_UserDBConfigAddUser  ERR_OK
#endif




/**
 * <description>Checks if a user exists.</description>
 * <param name="hDatabase" type="IN">Handle to the configuration database.</param>
 * <param name="pszUser" type="IN">User name.</param>
 * <result>True if the user exists, false otherwhise.</result>
 */
STATICITF_DEF RTS_BOOL CDECL UserDBConfigExistsUser(RTS_HANDLE hDatabase, char *pszUser);
typedef RTS_BOOL (CDECL * PFUSERDBCONFIGEXISTSUSER) (RTS_HANDLE hDatabase, char *pszUser);
#if defined(CMPUSERDBCONFIGURATION_NOTIMPLEMENTED) || defined(USERDBCONFIGEXISTSUSER_NOTIMPLEMENTED)
	#define USE_UserDBConfigExistsUser
	#define EXT_UserDBConfigExistsUser
	#define GET_UserDBConfigExistsUser(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserDBConfigExistsUser(p0,p1)  (RTS_BOOL)ERR_NOTIMPLEMENTED
	#define CHK_UserDBConfigExistsUser  FALSE
	#define EXP_UserDBConfigExistsUser  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserDBConfigExistsUser
	#define EXT_UserDBConfigExistsUser
	#define GET_UserDBConfigExistsUser(fl)  ERR_OK
	#define CAL_UserDBConfigExistsUser(p0,p1) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigExistsUser(((ICmpUserDBConfiguration*)p0)->pBase->hInstance,p1))
	#define CHK_UserDBConfigExistsUser  TRUE
	#define EXP_UserDBConfigExistsUser  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSERDBCONFIGURATION_EXTERNAL)
	#define USE_UserDBConfigExistsUser
	#define EXT_UserDBConfigExistsUser
	#define GET_UserDBConfigExistsUser(fl)  ERR_OK
	#define CAL_UserDBConfigExistsUser(p0,p1) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigExistsUser(((ICmpUserDBConfiguration*)p0)->pBase->hInstance,p1))
	#define CHK_UserDBConfigExistsUser  TRUE
	#define EXP_UserDBConfigExistsUser  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserDBConfigurationUserDBConfigExistsUser
	#define EXT_CmpUserDBConfigurationUserDBConfigExistsUser
	#define GET_CmpUserDBConfigurationUserDBConfigExistsUser  ERR_OK
	#define CAL_CmpUserDBConfigurationUserDBConfigExistsUser(p0,p1)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigExistsUser(p1))
	#define CHK_CmpUserDBConfigurationUserDBConfigExistsUser  TRUE
	#define EXP_CmpUserDBConfigurationUserDBConfigExistsUser  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserDBConfigExistsUser
	#define EXT_UserDBConfigExistsUser
	#define GET_UserDBConfigExistsUser(fl)  ERR_OK
	#define CAL_UserDBConfigExistsUser(p0,p1)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigExistsUser(p1))
	#define CHK_UserDBConfigExistsUser  TRUE
	#define EXP_UserDBConfigExistsUser  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserDBConfigExistsUser
	#define EXT_UserDBConfigExistsUser
	#define GET_UserDBConfigExistsUser(fl)  ERR_OK
	#define CAL_UserDBConfigExistsUser(p0,p1) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigExistsUser(((ICmpUserDBConfiguration*)p0)->pBase->hInstance,p1))
	#define CHK_UserDBConfigExistsUser  TRUE
	#define EXP_UserDBConfigExistsUser  ERR_OK
#endif




/**
 * <description>Remove user from the user database</description>
 * <param name="hDatabase" type="IN">Handle to the configuration database.</param>
 * <param name="pszUser" type="IN">Name of the user to remove.</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">User could be removed</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid user handle</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserDBConfigRemoveUser(RTS_HANDLE hDatabase, char *pszUser);
typedef RTS_RESULT (CDECL * PFUSERDBCONFIGREMOVEUSER) (RTS_HANDLE hDatabase, char *pszUser);
#if defined(CMPUSERDBCONFIGURATION_NOTIMPLEMENTED) || defined(USERDBCONFIGREMOVEUSER_NOTIMPLEMENTED)
	#define USE_UserDBConfigRemoveUser
	#define EXT_UserDBConfigRemoveUser
	#define GET_UserDBConfigRemoveUser(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserDBConfigRemoveUser(p0,p1)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserDBConfigRemoveUser  FALSE
	#define EXP_UserDBConfigRemoveUser  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserDBConfigRemoveUser
	#define EXT_UserDBConfigRemoveUser
	#define GET_UserDBConfigRemoveUser(fl)  ERR_OK
	#define CAL_UserDBConfigRemoveUser(p0,p1) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigRemoveUser(((ICmpUserDBConfiguration*)p0)->pBase->hInstance,p1))
	#define CHK_UserDBConfigRemoveUser  TRUE
	#define EXP_UserDBConfigRemoveUser  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSERDBCONFIGURATION_EXTERNAL)
	#define USE_UserDBConfigRemoveUser
	#define EXT_UserDBConfigRemoveUser
	#define GET_UserDBConfigRemoveUser(fl)  ERR_OK
	#define CAL_UserDBConfigRemoveUser(p0,p1) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigRemoveUser(((ICmpUserDBConfiguration*)p0)->pBase->hInstance,p1))
	#define CHK_UserDBConfigRemoveUser  TRUE
	#define EXP_UserDBConfigRemoveUser  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserDBConfigurationUserDBConfigRemoveUser
	#define EXT_CmpUserDBConfigurationUserDBConfigRemoveUser
	#define GET_CmpUserDBConfigurationUserDBConfigRemoveUser  ERR_OK
	#define CAL_CmpUserDBConfigurationUserDBConfigRemoveUser(p0,p1)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigRemoveUser(p1))
	#define CHK_CmpUserDBConfigurationUserDBConfigRemoveUser  TRUE
	#define EXP_CmpUserDBConfigurationUserDBConfigRemoveUser  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserDBConfigRemoveUser
	#define EXT_UserDBConfigRemoveUser
	#define GET_UserDBConfigRemoveUser(fl)  ERR_OK
	#define CAL_UserDBConfigRemoveUser(p0,p1)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigRemoveUser(p1))
	#define CHK_UserDBConfigRemoveUser  TRUE
	#define EXP_UserDBConfigRemoveUser  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserDBConfigRemoveUser
	#define EXT_UserDBConfigRemoveUser
	#define GET_UserDBConfigRemoveUser(fl)  ERR_OK
	#define CAL_UserDBConfigRemoveUser(p0,p1) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigRemoveUser(((ICmpUserDBConfiguration*)p0)->pBase->hInstance,p1))
	#define CHK_UserDBConfigRemoveUser  TRUE
	#define EXP_UserDBConfigRemoveUser  ERR_OK
#endif




/**
 * <description>Set or overwrite the password credential of the user.</description>
 * <param name="hDatabase" type="IN">Handle to the configuration database.</param>
 * <param name="pszUser" type="IN">Name of the user.</param>
 * <param name="pszPassword" type="IN">Pointer to password in clear text</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Password could be set</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid user handle or password = NULL</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_DUPLICATE">The new and the old password are the same</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserDBConfigSetUserCredentials(RTS_HANDLE hDatabase, char *pszUser, UserMgrCredentials *pCredentials);
typedef RTS_RESULT (CDECL * PFUSERDBCONFIGSETUSERCREDENTIALS) (RTS_HANDLE hDatabase, char *pszUser, UserMgrCredentials *pCredentials);
#if defined(CMPUSERDBCONFIGURATION_NOTIMPLEMENTED) || defined(USERDBCONFIGSETUSERCREDENTIALS_NOTIMPLEMENTED)
	#define USE_UserDBConfigSetUserCredentials
	#define EXT_UserDBConfigSetUserCredentials
	#define GET_UserDBConfigSetUserCredentials(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserDBConfigSetUserCredentials(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserDBConfigSetUserCredentials  FALSE
	#define EXP_UserDBConfigSetUserCredentials  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserDBConfigSetUserCredentials
	#define EXT_UserDBConfigSetUserCredentials
	#define GET_UserDBConfigSetUserCredentials(fl)  ERR_OK
	#define CAL_UserDBConfigSetUserCredentials(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigSetUserCredentials(((ICmpUserDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserDBConfigSetUserCredentials  TRUE
	#define EXP_UserDBConfigSetUserCredentials  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSERDBCONFIGURATION_EXTERNAL)
	#define USE_UserDBConfigSetUserCredentials
	#define EXT_UserDBConfigSetUserCredentials
	#define GET_UserDBConfigSetUserCredentials(fl)  ERR_OK
	#define CAL_UserDBConfigSetUserCredentials(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigSetUserCredentials(((ICmpUserDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserDBConfigSetUserCredentials  TRUE
	#define EXP_UserDBConfigSetUserCredentials  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserDBConfigurationUserDBConfigSetUserCredentials
	#define EXT_CmpUserDBConfigurationUserDBConfigSetUserCredentials
	#define GET_CmpUserDBConfigurationUserDBConfigSetUserCredentials  ERR_OK
	#define CAL_CmpUserDBConfigurationUserDBConfigSetUserCredentials(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigSetUserCredentials(p1,p2))
	#define CHK_CmpUserDBConfigurationUserDBConfigSetUserCredentials  TRUE
	#define EXP_CmpUserDBConfigurationUserDBConfigSetUserCredentials  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserDBConfigSetUserCredentials
	#define EXT_UserDBConfigSetUserCredentials
	#define GET_UserDBConfigSetUserCredentials(fl)  ERR_OK
	#define CAL_UserDBConfigSetUserCredentials(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigSetUserCredentials(p1,p2))
	#define CHK_UserDBConfigSetUserCredentials  TRUE
	#define EXP_UserDBConfigSetUserCredentials  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserDBConfigSetUserCredentials
	#define EXT_UserDBConfigSetUserCredentials
	#define GET_UserDBConfigSetUserCredentials(fl)  ERR_OK
	#define CAL_UserDBConfigSetUserCredentials(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigSetUserCredentials(((ICmpUserDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserDBConfigSetUserCredentials  TRUE
	#define EXP_UserDBConfigSetUserCredentials  ERR_OK
#endif




/**
 * <description>Get properties of a user</description>
 * <param name="hDatabase" type="IN">Handle to the configuration database.</param>
 * <param name="pszUser" type="IN">Name of the user.</param>
 * <param name="pResult" type="IN">Pointer to set the properties. For details see category "UserDB properties"</param>
 * <result>The users properties</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Properties could be set</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid user handle or property pointer = NULL</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Invalid combination of property flags (password change not allowed but password not up to date)</errorcode>
 */
STATICITF_DEF RTS_UI32 CDECL UserDBConfigGetUserProperty(RTS_HANDLE hDatabase, char *pszUser, RTS_RESULT *pResult);
typedef RTS_UI32 (CDECL * PFUSERDBCONFIGGETUSERPROPERTY) (RTS_HANDLE hDatabase, char *pszUser, RTS_RESULT *pResult);
#if defined(CMPUSERDBCONFIGURATION_NOTIMPLEMENTED) || defined(USERDBCONFIGGETUSERPROPERTY_NOTIMPLEMENTED)
	#define USE_UserDBConfigGetUserProperty
	#define EXT_UserDBConfigGetUserProperty
	#define GET_UserDBConfigGetUserProperty(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserDBConfigGetUserProperty(p0,p1,p2)  (RTS_UI32)ERR_NOTIMPLEMENTED
	#define CHK_UserDBConfigGetUserProperty  FALSE
	#define EXP_UserDBConfigGetUserProperty  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserDBConfigGetUserProperty
	#define EXT_UserDBConfigGetUserProperty
	#define GET_UserDBConfigGetUserProperty(fl)  ERR_OK
	#define CAL_UserDBConfigGetUserProperty(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigGetUserProperty(((ICmpUserDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserDBConfigGetUserProperty  TRUE
	#define EXP_UserDBConfigGetUserProperty  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSERDBCONFIGURATION_EXTERNAL)
	#define USE_UserDBConfigGetUserProperty
	#define EXT_UserDBConfigGetUserProperty
	#define GET_UserDBConfigGetUserProperty(fl)  ERR_OK
	#define CAL_UserDBConfigGetUserProperty(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigGetUserProperty(((ICmpUserDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserDBConfigGetUserProperty  TRUE
	#define EXP_UserDBConfigGetUserProperty  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserDBConfigurationUserDBConfigGetUserProperty
	#define EXT_CmpUserDBConfigurationUserDBConfigGetUserProperty
	#define GET_CmpUserDBConfigurationUserDBConfigGetUserProperty  ERR_OK
	#define CAL_CmpUserDBConfigurationUserDBConfigGetUserProperty(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigGetUserProperty(p1,p2))
	#define CHK_CmpUserDBConfigurationUserDBConfigGetUserProperty  TRUE
	#define EXP_CmpUserDBConfigurationUserDBConfigGetUserProperty  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserDBConfigGetUserProperty
	#define EXT_UserDBConfigGetUserProperty
	#define GET_UserDBConfigGetUserProperty(fl)  ERR_OK
	#define CAL_UserDBConfigGetUserProperty(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigGetUserProperty(p1,p2))
	#define CHK_UserDBConfigGetUserProperty  TRUE
	#define EXP_UserDBConfigGetUserProperty  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserDBConfigGetUserProperty
	#define EXT_UserDBConfigGetUserProperty
	#define GET_UserDBConfigGetUserProperty(fl)  ERR_OK
	#define CAL_UserDBConfigGetUserProperty(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigGetUserProperty(((ICmpUserDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserDBConfigGetUserProperty  TRUE
	#define EXP_UserDBConfigGetUserProperty  ERR_OK
#endif




/**
 * <description>Set properties of a user</description>
 * <param name="hDatabase" type="IN">Handle to the configuration database.</param>
 * <param name="pszUser" type="IN">Name of the user.</param>
 * <param name="property" type="IN">Pointer to set the properties. For details see category "UserDB properties"</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Properties could be set</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid user handle or property pointer = NULL</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Invalid combination of property flags (password change not allowed but password not up to date)</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserDBConfigSetUserProperty(RTS_HANDLE hDatabase, char *pszUser, RTS_UI32 property);
typedef RTS_RESULT (CDECL * PFUSERDBCONFIGSETUSERPROPERTY) (RTS_HANDLE hDatabase, char *pszUser, RTS_UI32 property);
#if defined(CMPUSERDBCONFIGURATION_NOTIMPLEMENTED) || defined(USERDBCONFIGSETUSERPROPERTY_NOTIMPLEMENTED)
	#define USE_UserDBConfigSetUserProperty
	#define EXT_UserDBConfigSetUserProperty
	#define GET_UserDBConfigSetUserProperty(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserDBConfigSetUserProperty(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserDBConfigSetUserProperty  FALSE
	#define EXP_UserDBConfigSetUserProperty  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserDBConfigSetUserProperty
	#define EXT_UserDBConfigSetUserProperty
	#define GET_UserDBConfigSetUserProperty(fl)  ERR_OK
	#define CAL_UserDBConfigSetUserProperty(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigSetUserProperty(((ICmpUserDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserDBConfigSetUserProperty  TRUE
	#define EXP_UserDBConfigSetUserProperty  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSERDBCONFIGURATION_EXTERNAL)
	#define USE_UserDBConfigSetUserProperty
	#define EXT_UserDBConfigSetUserProperty
	#define GET_UserDBConfigSetUserProperty(fl)  ERR_OK
	#define CAL_UserDBConfigSetUserProperty(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigSetUserProperty(((ICmpUserDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserDBConfigSetUserProperty  TRUE
	#define EXP_UserDBConfigSetUserProperty  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserDBConfigurationUserDBConfigSetUserProperty
	#define EXT_CmpUserDBConfigurationUserDBConfigSetUserProperty
	#define GET_CmpUserDBConfigurationUserDBConfigSetUserProperty  ERR_OK
	#define CAL_CmpUserDBConfigurationUserDBConfigSetUserProperty(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigSetUserProperty(p1,p2))
	#define CHK_CmpUserDBConfigurationUserDBConfigSetUserProperty  TRUE
	#define EXP_CmpUserDBConfigurationUserDBConfigSetUserProperty  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserDBConfigSetUserProperty
	#define EXT_UserDBConfigSetUserProperty
	#define GET_UserDBConfigSetUserProperty(fl)  ERR_OK
	#define CAL_UserDBConfigSetUserProperty(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigSetUserProperty(p1,p2))
	#define CHK_UserDBConfigSetUserProperty  TRUE
	#define EXP_UserDBConfigSetUserProperty  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserDBConfigSetUserProperty
	#define EXT_UserDBConfigSetUserProperty
	#define GET_UserDBConfigSetUserProperty(fl)  ERR_OK
	#define CAL_UserDBConfigSetUserProperty(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserDBConfiguration*)p0)->IUserDBConfigSetUserProperty(((ICmpUserDBConfiguration*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserDBConfigSetUserProperty  TRUE
	#define EXP_UserDBConfigSetUserProperty  ERR_OK
#endif




#ifdef CPLUSPLUS
extern "C" {
#endif

typedef struct
{
	RTS_UI32 loginProtocolType;
	RTS_HANDLE hDatabase;
} CmpUserDBConfig_Info;

#ifdef CPLUSPLUS
}
#endif




typedef struct
{
	IBase_C *pBase;
	PFUSERDBCONFIGRELEASE IUserDBConfigRelease;
 	PFUSERDBCONFIGIMPORT IUserDBConfigImport;
 	PFUSERDBCONFIGEXPORT IUserDBConfigExport;
 	PFUSERDBCONFIGADDUSER IUserDBConfigAddUser;
 	PFUSERDBCONFIGEXISTSUSER IUserDBConfigExistsUser;
 	PFUSERDBCONFIGREMOVEUSER IUserDBConfigRemoveUser;
 	PFUSERDBCONFIGSETUSERCREDENTIALS IUserDBConfigSetUserCredentials;
 	PFUSERDBCONFIGGETUSERPROPERTY IUserDBConfigGetUserProperty;
 	PFUSERDBCONFIGSETUSERPROPERTY IUserDBConfigSetUserProperty;
 } ICmpUserDBConfiguration_C;

#ifdef CPLUSPLUS
class ICmpUserDBConfiguration : public IBase
{
	public:
		virtual RTS_RESULT CDECL IUserDBConfigRelease(void) =0;
		virtual RTS_RESULT CDECL IUserDBConfigImport(RTS_UI8 *pData, RTS_SIZE dataSize) =0;
		virtual RTS_SIZE CDECL IUserDBConfigExport(RTS_UI8 *pData, RTS_SIZE maxSize, RTS_RESULT *pResult) =0;
		virtual RTS_RESULT CDECL IUserDBConfigAddUser(char *pszUser, UserMgrCredentials *pCredentials) =0;
		virtual RTS_BOOL CDECL IUserDBConfigExistsUser(char *pszUser) =0;
		virtual RTS_RESULT CDECL IUserDBConfigRemoveUser(char *pszUser) =0;
		virtual RTS_RESULT CDECL IUserDBConfigSetUserCredentials(char *pszUser, UserMgrCredentials *pCredentials) =0;
		virtual RTS_UI32 CDECL IUserDBConfigGetUserProperty(char *pszUser, RTS_RESULT *pResult) =0;
		virtual RTS_RESULT CDECL IUserDBConfigSetUserProperty(char *pszUser, RTS_UI32 property) =0;
};
	#ifndef ITF_CmpUserDBConfiguration
		#define ITF_CmpUserDBConfiguration static ICmpUserDBConfiguration *pICmpUserDBConfiguration = NULL;
	#endif
	#define EXTITF_CmpUserDBConfiguration
#else	/*CPLUSPLUS*/
	typedef ICmpUserDBConfiguration_C		ICmpUserDBConfiguration;
	#ifndef ITF_CmpUserDBConfiguration
		#define ITF_CmpUserDBConfiguration
	#endif
	#define EXTITF_CmpUserDBConfiguration
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_CMPUSERDBCONFIGURATIONITF_H_*/
