/**
 * <interfacename>CmpUserGroupsDB</interfacename>
 * <description> 
 *	This interface provides the minimal set of functions that must be implemented to replace the default CODESYS user database. 
 *	
 *  All user groups and their assigned users are managed and stored here.
 * </description>
 *
 * <copyright>
 * Copyright (c) 2019 CODESYS Development GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`CmpUserGroupsDB')

DEF_CLASSITF_API(`RTS_HANDLE', `CDECL', `UserGroupsDBGetGroup', `(RTS_HANDLE hDatabase, char *pszGroupName, RTS_RESULT *pResult)')

/**
 * <description>Iteration interface to get the first group to which the user is assigned
 * NOTE: The required user handle is not compatible with a handle from the UserMgr, and these handles must not be mixed.
 * A UserMgr handle can be converted to a UserDB handle by using UserMgrGetUserDBHandle().
 * </description>
 * <param name="hUser" type="IN">Handle to the user</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">First user group available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid user handle</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">No user group configured</errorcode>
 * <result>Handle to the first user group or RTS_INVALID_HANDLE if failed</result>
 */
DEF_CLASSITF_API(`RTS_HANDLE', `CDECL', `UserGroupsDBGetFirstGroup', `(RTS_HANDLE hDatabase, RTS_RESULT *pResult)')

/**
 * <description>Iteration interface to get next configured user group to which the user is assigned. Must be started with UserDBGetFirstGroup()
 * NOTE: The required user handle is not compatible with a handle from the UserMgr, and these handles must not be mixed.
 * A UserMgr handle can be converted to a UserDB handle by using UserMgrGetUserDBHandle().
 * </description>
 * <param name="hUser" type="IN">Handle to the user</param>
 * <param name="hPrevGroup" type="IN">Handle to the previous user group retrieved via UserDBGetFirstGroup() or subsequent calls of UserDBGetNextGroup()</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Next user group available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">No next user group available</errorcode>
 * <result>Handle to the next user group or RTS_INVALID_HANDLE if failed</result>
 */
DEF_CLASSITF_API(`RTS_HANDLE', `CDECL', `UserGroupsDBGetNextGroup', `(RTS_HANDLE hDatabase, RTS_HANDLE hPrevGroup, RTS_RESULT *pResult)')



DEF_CLASSITF_API(`char*', `CDECL', `UserGroupsDBGetName', `(RTS_HANDLE hDatabase, RTS_HANDLE hGroup, RTS_RESULT *pResult)')

DEF_CLASSITF_API(`RTS_UI32', `CDECL', `UserGroupsDBGetProperty', `(RTS_HANDLE hDatabase, RTS_HANDLE hGroup, RTS_RESULT *pResult)')

/**
 * <description>Check if the user is a member of the group
 * NOTE: The required user handle is not compatible with a handle from the UserMgr, and these handles must not be mixed.
 * A UserMgr handle can be converted to a UserDB handle by using UserMgrGetUserDBHandle().
 * </description>
 * <param name="hGroup" type="IN">Handle to the user group</param>
 * <param name="hUser" type="IN">Handle to the user</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">User is a member of the group</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid user or user group handle</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">User is no member of the specified user group</errorcode>
 */
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserGroupsDBGroupHasUser', `(RTS_HANDLE hDatabase, RTS_HANDLE hGroup, char *pszUser)')

/**
 * <description>Check if a user group is a member of the first specified group</description>
 * <param name="hGroup" type="IN">Handle to the first user group</param>
 * <param name="hGroupMember" type="IN">Handle to the user group to check if it is a member of hGroup</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">User group is a member of the first group</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid user group handles</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">User group is no member of the specified user group</errorcode>
 */
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserGroupsDBGroupHasMember', `(RTS_HANDLE hDatabase, RTS_HANDLE hGroup, RTS_HANDLE hGroupMember)')

/**
 * <description>Iteration interface to get the first user of the user group</description>
 * <param name="hGroup" type="IN">Handle to the user group</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">First user in the group available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">No user configured in the user group</errorcode>
 * <result>Handle to the first user in the user group or RTS_INVALID_HANDLE if failed</result>
 */
DEF_CLASSITF_API(`char*', `CDECL', `UserGroupsDBGetFirstUser', `(RTS_HANDLE hDatabase, RTS_HANDLE hGroup, RTS_HANDLE *phIterator, RTS_RESULT *pResult)')

/**
 * <description>Iteration interface to get next configured user of the user group. Must be started with UserDBGroupGetFirstUser()</description>
 * <param name="hGroup" type="IN">Handle to the user group</param>
 * <param name="hPrevUser" type="IN">Handle to the previous user retrieved via UserDBGroupGetFirstUser() or subsequent calls of UserDBGroupGetNextUser()</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Next user available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid handles</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">No next user available</errorcode>
 * <result>Handle to the next user or RTS_INVALID_HANDLE if failed</result>
 */
DEF_CLASSITF_API(`char*', `CDECL', `UserGroupsDBGetNextUser', `(RTS_HANDLE hDatabase, RTS_HANDLE hGroup, RTS_HANDLE *phIterator, RTS_RESULT *pResult)')

/**
 * <description>Iteration interface to get the first user group as member of the specified group</description>
 * <param name="hGroup" type="IN">Handle to the user group</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">First user group member available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid user group handle</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">No user group configured</errorcode>
 * <result>Handle to the first user group member or RTS_INVALID_HANDLE if failed</result>
 */
DEF_CLASSITF_API(`RTS_HANDLE', `CDECL', `UserGroupsDBGetFirstGroupMember', `(RTS_HANDLE hDatabase, RTS_HANDLE hGroup, RTS_RESULT *pResult)')

/**
 * <description>Iteration interface to get next configured user group as member of the specified group. Must be started with UserDBGroupGetFirstMember()</description>
 * <param name="hGroup" type="IN">Handle to the user group</param>
 * <param name="hPrevGroupMember" type="IN">Handle to the previous user group retrieved via UserDBGroupGetFirstMember() or subsequent calls of UserDBGroupGetNextMember()</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Next user group member available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">No next user group member available</errorcode>
 * <result>Handle to the next user group member or RTS_INVALID_HANDLE if failed</result>
 */
DEF_CLASSITF_API(`RTS_HANDLE', `CDECL', `UserGroupsDBGetNextGroupMember', `(RTS_HANDLE hDatabase, RTS_HANDLE hGroup, RTS_HANDLE hPrevMember, RTS_RESULT *pResult)')