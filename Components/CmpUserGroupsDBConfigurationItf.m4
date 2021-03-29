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

SET_INTERFACE_NAME(`CmpUserGroupsDBConfiguration')

DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserGroupsDBConfigRelease', `(RTS_HANDLE hDatabase)')

/**
 * <description>Import the user group database from a backup.</description>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Succeeded</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Failed releasing user management</errorcode>
 */
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserGroupsDBConfigImport', `(RTS_HANDLE hDatabase, RTS_UI8 *pData, RTS_SIZE dataSize)')

/**
 * <description>Export the user group database into a backup.</description>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Succeeded</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Failed releasing user management</errorcode>
 */
DEF_CLASSITF_API(`RTS_SIZE', `CDECL', `UserGroupsDBConfigExport', `(RTS_HANDLE hDatabase, RTS_UI8 *pData, RTS_SIZE maxSize, RTS_RESULT *pResult)')

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
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserGroupsDBConfigAdd', `(RTS_HANDLE hDatabase, char *pszGroup)')

/**
 * <description>Remove user group from the user database</description>
 * <param name="hGroup" type="IN">Handle to the group</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Group could be removed</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid group handle</errorcode>
 */
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserGroupsDBConfigRemove', `(RTS_HANDLE hDatabase, char *pszGroup)')

/**
 * <description>Set properties of a group</description>
 * <param name="hGroup" type="IN">Handle to the group</param>
 * <param name="pulProperty" type="IN">Pointer to set the properties. For details see category "UserDB properties"</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Properties could be set</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid user group or property pointer = NULL</errorcode>
 */
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserGroupsDBConfigSetProperty', `(RTS_HANDLE hDatabase, char *pszGroup, RTS_UI32 ulProperty)')

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
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserGroupsDBConfigAddUser', `(RTS_HANDLE hDatabase, char *pszGroup, char *pszUser)')

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
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserGroupsDBConfigRemoveUser', `(RTS_HANDLE hDatabase, char *pszGroup, char *pszUser)')

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
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserGroupsDBConfigAddMember', `(RTS_HANDLE hDatabase, char *pszGroup, char *pszGroupToAdd)')

/**
 * <description>Remove a group as a member from another group. So the group is no longer derived from the first one</description>
 * <param name="hGroup" type="IN">First group to remove the derived group from</param>
 * <param name="hGroupMember" type="IN">Member group which is no longer derived from the first group (hGroup) after this operation</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Group could be removed</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter. hGroup or hGroupMember invalid</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">The user management is not initialized or it is not loaded yet</errorcode>
 */
 DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserGroupsDBConfigRemoveMember', `(RTS_HANDLE hDatabase, char *pszGroup, char *pszGroupToRemove)')
