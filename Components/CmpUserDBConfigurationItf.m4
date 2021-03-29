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

SET_INTERFACE_NAME(`CmpUserDBConfiguration')
REF_ITF(`CmpUserDBItf.m4')

/**
 * <description>Clear the complete user database.</description>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Succeeded</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Failed releasing user management</errorcode>
 */
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserDBConfigRelease', `(RTS_HANDLE hDatabase)')

/**
 * <description>Import the user database from a backup.</description>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Succeeded</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Failed releasing user management</errorcode>
 */
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserDBConfigImport', `(RTS_HANDLE hDatabase, RTS_UI8 *pData, RTS_SIZE dataSize)')

/**
 * <description>Export the user database into a backup.</description>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Succeeded</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Failed releasing user management</errorcode>
 */
DEF_CLASSITF_API(`RTS_SIZE', `CDECL', `UserDBConfigExport', `(RTS_HANDLE hDatabase, RTS_UI8 *pData, RTS_SIZE maxSize, RTS_RESULT *pResult)')

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
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserDBConfigAddUser', `(RTS_HANDLE hDatabase, char *pszUser, UserMgrCredentials *pCredentials)')

/**
 * <description>Checks if a user exists.</description>
 * <param name="hDatabase" type="IN">Handle to the configuration database.</param>
 * <param name="pszUser" type="IN">User name.</param>
 * <result>True if the user exists, false otherwhise.</result>
 */
DEF_CLASSITF_API(`RTS_BOOL', `CDECL', `UserDBConfigExistsUser', `(RTS_HANDLE hDatabase, char *pszUser)')

/**
 * <description>Remove user from the user database</description>
 * <param name="hDatabase" type="IN">Handle to the configuration database.</param>
 * <param name="pszUser" type="IN">Name of the user to remove.</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">User could be removed</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid user handle</errorcode>
 */
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserDBConfigRemoveUser', `(RTS_HANDLE hDatabase, char *pszUser)')

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
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserDBConfigSetUserCredentials', `(RTS_HANDLE hDatabase, char *pszUser, UserMgrCredentials *pCredentials)')

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
DEF_CLASSITF_API(`RTS_UI32', `CDECL', `UserDBConfigGetUserProperty', `(RTS_HANDLE hDatabase, char *pszUser, RTS_RESULT *pResult)')

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
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserDBConfigSetUserProperty', `(RTS_HANDLE hDatabase, char *pszUser, RTS_UI32 property)')

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

