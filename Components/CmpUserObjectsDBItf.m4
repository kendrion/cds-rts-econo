/**
 * <interfacename>CmpUserObjectsDB</interfacename>
 * <description> 
 *	Interface for the user rights management database.
 *
 *	   Here you have to store the tree of all objects of the runtime system with their assigned user-groups and the configured rights on it.
 *
 *	   Example:
 *			- Object: Name = "Device"; UserGroup = "Administrator" | Rights = USERDB_RIGHT_ALL | DeniedRights = USERDB_RIGHT_NONE; 
 *									   UserGroup = "..." | Rights = ... | DeniedRights = ...;
 *									   ...
 *			- Object: Name = "Device.MyObject"; UserGroup = "Administrator" | Rights = USERDB_RIGHT_ALL | DeniedRights = USERDB_RIGHT_NONE; 
 *												UserGroup = "..." | Rights = ... | DeniedRights = ...;
 *												...
 *
 *	For details see CmpUserMgrItf.h.
 *
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved. GmbH
 * </copyright>
 */

SET_INTERFACE_NAME(`CmpUserObjectsDB')
REF_ITF(`CmpMemPoolItf.m4')
#include "CmpItf.h"

/**
 * <category>Static defines</category>
 * <description>Number of objects at startup</description>
 */
#ifndef USERDB_NUM_OF_STATIC_OBJECTS
	#define USERDB_NUM_OF_STATIC_OBJECTS		6
#endif

/**
 * <category>Static defines</category>
 * <description>Number of user-group specific rights at startup</description>
 */
#ifndef USERDB_NUM_OF_STATIC_GROUPRIGHTS
	#define USERDB_NUM_OF_STATIC_GROUPRIGHTS	10
#endif

/**
 * <category>Properties</category>
 * <description>These defines are used as properties of the UserDB Objects. Use as bit-mask.</description>
 * <element name="USERDB_HIDE_OBJECT">Hides the object from being uploaded to the IDE.</element>
 * <element name="USERDB_EXPLICIT_RIGHTS">Evaluates only the explicit configured rights on that object. Don't check the parent 
 *	objects if no rights are configured. If no explicit rights are found access is denied.</element>
 */
#define USERDB_HIDE_OBJECT             1
#define USERDB_EXPLICIT_RIGHTS         2

#ifdef __cplusplus
extern "C" {
#endif

/* --------- Objects and Rights management --------------------- */

/**
 * <description>
 *	Get the used access rights for the object specified by handle.
 *	NOTE: In case the used rights are not set the function returns USERDB_RIGHT_ALL.
 * </description>
 * <param name="hObject" type="IN">Handle to the object</param>
 * <param name="pulUsedRights" type="OUT">Pointer to used access rights</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Rights are successfully set</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid object handle or invalid pointer</errorcode>
 * <result>Error code</result>
 */
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserObjectsDBGetUsedRights', `(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_UI32 *pulUsedRights)')

/**
 * <description>Get the properties for the object specified by handle.</description>
 * <param name="hObject" type="IN">Handle to the object</param>
 * <param name="pulProperties" type="OUT">Pointer to properties</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Rights are successfully set</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid object handle or invalid pointer</errorcode>
 * <result>Error code</result>
 */
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserObjectsDBGetProperties', `(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_UI32 *pulProperties)')

/**
 * <description>Get a unique identifier of an object</description>
 * <param name="hObject" type="IN">Handle to object</param>
 * <param name="pulID" type="OUT">Pointer to get the ObjectID</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">ObjectID could be retrieved</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid object handle</errorcode>
 */
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserObjectsDBGetID', `(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_UI32 *pulID)')

/* Object iteration */

/**
 * <description>Iteration interface to get the first object of the user rights management</description>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">First object of the user rights management available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">No object available</errorcode>
 * <result>Handle to the first object in the user rights management or RTS_INVALID_HANDLE if failed</result>
 */
DEF_CLASSITF_API(`RTS_HANDLE', `CDECL', `UserObjectsDBGetFirst', `(RTS_HANDLE hDatabase, RTS_RESULT *pResult)')

/**
 * <description>Iteration interface to get next object of the user rights management. Must be started with UserObjectsDBGetFirst()</description>
 * <param name="hPrevObject" type="IN">Handle to the previous object retrieved via UserObjectsDBGetFirst() or subsequent calls of UserObjectsDBGetNext()</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Next object available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid handles</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">No next object available</errorcode>
 * <result>Handle to the next object in the user rights management or RTS_INVALID_HANDLE if failed</result>
 */
DEF_CLASSITF_API(`RTS_HANDLE', `CDECL', `UserObjectsDBGetNext', `(RTS_HANDLE hDatabase, RTS_HANDLE hPrevObject, RTS_RESULT *pResult)')

/* Single object access */

/**
 * <description>Open object specified by its name</description>
 * <param name="pszObject" type="IN">Full object name (see object tree)</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Object could be opened</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter. pszObject = NULL or empty</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">The user management is not initialized or it is not loaded yet</errorcode>
 * <result>Handle to the object or RTS_INVALID_HANDLE if failed</result>
 */
DEF_CLASSITF_API(`RTS_HANDLE', `CDECL', `UserObjectsDBOpen', `(RTS_HANDLE hDatabase, char *pszObject, RTS_RESULT *pResult)')

/**
 * <description>Close an object</description>
 * <param name="hObject" type="IN">Handle to the object</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Object could be closed</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid object handle</errorcode>
 */
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserObjectsDBClose', `(RTS_HANDLE hDatabase, RTS_HANDLE hObject)')

/**
 * <description>Get object name</description>
 * <param name="hObject" type="IN">Handle to the object</param>
 * <param name="pszObject" type="OUT">Pointer to get object name</param>
 * <param name="piMaxLen" type="INOUT">Pointer to length of buffer in pszObject. If pszObject = NULL, only the length of the object name is returned in *piMaxLen</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Object name is returned</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid object handle or pszObject = NULL and piMaxLen = NULL</errorcode>
 */
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserObjectsDBGetName', `(RTS_HANDLE hDatabase, RTS_HANDLE hObject, char *pszObject, int *piMaxLen)')

/**
 * <description>Get the complete object path name</description>
 * <param name="hObject" type="IN">Handle to the object</param>
 * <param name="pszObject" type="IN">Full object path name (see object tree)</param>
 * <param name="piMaxLen" type="INOUT">Pointer to length of buffer in pszObject. If pszObject = NULL, only the length of the object name is returned in *piMaxLen</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Object name is returned</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid object handle or pszObject = NULL and piMaxLen = NULL</errorcode>
 */
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserObjectsDBGetPath', `(RTS_HANDLE hDatabase, RTS_HANDLE hObject, char *pszObject, int *piMaxLen)')

/**
 * <description>Get first child object in object tree of the specified father object</description>
 * <param name="hFatherObject" type="IN">Handle to the father object</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">First child object available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter hFatherObject</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">The user management is not initialized or it is not loaded yet</errorcode>
 * <result>Handle to the child object or RTS_INVALID_HANDLE if failed</result>
 */
DEF_CLASSITF_API(`RTS_HANDLE', `CDECL', `UserObjectsDBGetFirstChild', `(RTS_HANDLE hDatabase, RTS_HANDLE hFatherObject, RTS_RESULT *pResult)')

/**
 * <description>Get next child object in object tree of the specified father object. Must be started with UserObjectsDBGetFirstChild()</description>
 * <param name="hFatherObject" type="IN">Handle to the father object</param>
 * <param name="hPrevChildObject" type="IN">Handle to the previous child object retrieved by UserObjectsDBGetFirstChild() or subsequent calls of UserObjectsDBGetNextChild()</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Next child object available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter hFatherObject or hPrevChildObject</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">The user management is not initialized or it is not loaded yet</errorcode>
 * <result>Handle to the next child object or RTS_INVALID_HANDLE if failed</result>
 */
DEF_CLASSITF_API(`RTS_HANDLE', `CDECL', `UserObjectsDBGetNextChild', `(RTS_HANDLE hDatabase, RTS_HANDLE hFatherObject, RTS_HANDLE hPrevChildObject, RTS_RESULT *pResult)')

/**
 * <description>Get the father object in object tree of the specified child object</description>
 * <param name="hChildObject" type="IN">Handle to the child object</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Father object could be retrieved</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter hChildObject</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">The user management is not initialized or it is not loaded yet</errorcode>
 * <result>Handle to the father/parent object or RTS_INVALID_HANDLE if failed</result>
 */
DEF_CLASSITF_API(`RTS_HANDLE', `CDECL', `UserObjectsDBGetFather', `(RTS_HANDLE hDatabase, RTS_HANDLE hChildObject, RTS_RESULT *pResult)')

/* Iteration over all groups that are assigned to the object */

/**
 * <description>Iteration interface to get the first group in the user rights management of the specified object</description>
 * <param name="hObject" type="IN">Handle to the object</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">First group available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">No group available</errorcode>
 * <result>Handle to the first group of the object in the user rights management or RTS_INVALID_HANDLE if failed</result>
 */
DEF_CLASSITF_API(`RTS_HANDLE', `CDECL', `UserObjectsDBGetFirstGroup', `(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_RESULT *pResult)')

/**
 * <description>Iteration interface to get next group in the user rights management of the specified object. Must be started with UserObjectsDBGetFirstGroup()</description>
 * <param name="hObject" type="IN">Handle to the object</param>
 * <param name="hPrevGroup" type="IN">Handle to the previous group retrieved via UserObjectsDBGetFirstGroup() or subsequent calls of UserObjectsDBGetNextGroup()</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Next group available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid handles</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">No next group available</errorcode>
 * <result>Handle to the next group of the object in the user rights management or RTS_INVALID_HANDLE if failed</result>
 */
DEF_CLASSITF_API(`RTS_HANDLE', `CDECL', `UserObjectsDBGetNextGroup', `(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_HANDLE hPrevGroup, RTS_RESULT *pResult)')

/* Get rights */

/**
 * <description>Get the rights and the denied rights of a group on a specified object</description>
 * <param name="hObject" type="IN">Handle to object</param>
 * <param name="hGroup" type="IN">Handle to the group which access rights are requested</param>
 * <element name="pulRights" type="IN">Pointer to get rights of the group. See category "User rights" for details</element>
 * <element name="pulDeniedRights" type="IN">Pointer to get denied rights of the group. See category "User rights" for details</element>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Access rights could be retrieved</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid handles</errorcode>
 */
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserObjectsDBGetGroupRights', `(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_HANDLE hGroup, RTS_UI32 *pulRights, RTS_UI32 *pulDeniedRights)')

/**
 * <description>Check access rights of a user on an object (authorization)</description>
 * <param name="pszObject" type="IN">Full object name (see object tree)</param>
 * <param name="hUser" type="IN">Handle to the user which access rights are checked</param>
 * <element name="ulRequestedRights" type="IN">Requested access rights. See category "User rights" for details</element>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Access permitted</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Access rights could not be retrieved, so no access rights!</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_ACCESS_RIGHTS">No access rights!</errorcode>
 */
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserObjectsDBHasRights', `(RTS_HANDLE hDatabase, char *pszObject, RTS_HANDLE hUser, RTS_UI32 ulRequestedRights)')

/**
 * <description>Get the rights and the denied rights of a user on a specified object</description>
 * <param name="pszObject" type="IN">Full object name (see object tree)</param>
 * <param name="hUser" type="IN">Handle to the user which access rights are requested</param>
 * <element name="pulRights" type="IN">Pointer to get rights of the user. See category "User rights" for details</element>
 * <element name="pulDeniedRights" type="IN">Pointer to get denied rights of the user. See category "User rights" for details</element>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Access rights could be retrieved</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid handles</errorcode>
 */
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserObjectsDBGetRights', `(RTS_HANDLE hDatabase, char *pszObject, RTS_HANDLE hUser, RTS_UI32 *pulRights, RTS_UI32 *pulDeniedRights)')

/**
 * <description>Explicitly activate the usage of user authentication: no assuming of administrator rights
 * NOTE: The UserObjectsDB is activated implicitly when a DB file is loaded or configured via CODESYS.
 * </description>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Activation was successful</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">The user management is not initialized or it is not loaded yet</errorcode>
 */
DEF_CLASSITF_API(`RTS_RESULT', `CDECL', `UserObjectsDBActivate', `(RTS_HANDLE hDatabase)')

#ifdef __cplusplus
}
#endif
