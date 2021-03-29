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

SET_INTERFACE_NAME(`CmpUserObjectsDBConfiguration')

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
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserObjectsDBConfigLoad', `(RTS_HANDLE hDatabase)')

/**
 * <description>Storing the current user rights management into permanent database file</description>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Succeeded</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Error storing user rights database</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTIMPLEMENTED">Is not implemented perhaps the UserObjectsDB is fix</errorcode>
 */
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserObjectsDBConfigStore', `(RTS_HANDLE hDatabase)')

/**
 * <description>Release user rights from all objects and delete persistant stored.</description>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Succeeded</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Failed releasing user rights from all objects</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTIMPLEMENTED">Is not implemented perhaps the UserObjectsDB is fix</errorcode>
 */
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserObjectsDBConfigRelease', `(RTS_HANDLE hDatabase)')

/**
 * <description>Release user rights from all objects</description>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Succeeded</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Failed releasing user rights from all objects</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTIMPLEMENTED">Is not implemented perhaps the UserObjectsDB is fix</errorcode>
 */
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserObjectsDBConfigReleaseRights', `(RTS_HANDLE hDatabase)')

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
DEF_CLASSITF_API(`RTS_HANDLE', `CDECL', `UserObjectsDBConfigAdd', `(RTS_HANDLE hDatabase, char *pszObject, RTS_RESULT *pResult)')

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
DEF_CLASSITF_API(`RTS_HANDLE',`CDECL',`UserObjectsDBConfigAdd2',`(RTS_HANDLE hDatabase, char *pszObject, RTS_UI32 properties, RTS_RESULT *pResult)') 

/**
 * <description>Remove an object from the object management and all its children</description>
 * <param name="hObject" type="IN">Handle to object</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Object could be removed</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid object handle</errorcode>
 */
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserObjectsDBConfigRemove', `(RTS_HANDLE hDatabase, RTS_HANDLE hObject)')

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
DEF_CLASSITF_API(`RTS_HANDLE', `CDECL', `UserObjectsDBConfigAddChild', `(RTS_HANDLE hDatabase, RTS_HANDLE hFatherObject, char *pszObject, RTS_RESULT *pResult)')

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
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserObjectsDBConfigSetUsedRights', `(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_UI32 ulUsedRights)')

/**
 * <description>Set a unique identifier of an object</description>
 * <param name="hObject" type="IN">Handle to object</param>
 * <param name="ulID" type="IN">ObjectID to set</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">ObjectID could be set</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid object handle</errorcode>
 */
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserObjectsDBConfigSetID', `(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_UI32 ulID)')

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
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserObjectsDBConfigAddGroup', `(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_HANDLE hGroup)')

/**
 * <description>Remove a group from the specified object</description>
 * <param name="hObject" type="IN">Handle to object</param>
 * <param name="hGroup" type="IN">Handle to the group that should be removed</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Group could be removed</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid handles</errorcode>
 */
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserObjectsDBConfigRemoveGroup', `(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_HANDLE hGroup)')

/**
 * <description>Set the access rights for the group at the specified object</description>
 * <param name="hObject" type="IN">Handle to object</param>
 * <param name="hGroup" type="IN">Handle to the group</param>
 * <element name="ulRights" type="IN">Rights of the group. See category "User rights" for details</element>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Access rights could be set</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid handles</errorcode>
 */
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserObjectsDBConfigSetGroupRights', `(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_HANDLE hGroup, RTS_UI32 ulRights)')

/**
 * <description>Set the denied access rights for the group at the specified object</description>
 * <param name="hObject" type="IN">Handle to object</param>
 * <param name="hGroup" type="IN">Handle to the group</param>
 * <element name="ulDeniedRights" type="IN">Denied rights of the group. See category "User rights" for details</element>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Access rights could be set</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid handles</errorcode>
 */
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserObjectsDBConfigSetGroupDeniedRights', `(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_HANDLE hGroup, RTS_UI32 ulDeniedRights)')


/**
 * <description>This function clears all granted and denied rights for all groups on that object.</description>
 * <param name="hObject" type="IN">Handle to object</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Access rights could be set</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid handles</errorcode>
 */
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserObjectsDBConfigClearRights', `(RTS_HANDLE hDatabase, RTS_HANDLE hObject)')

#ifdef __cplusplus
}
#endif
