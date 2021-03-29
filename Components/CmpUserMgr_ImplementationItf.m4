/**
 * <interfacename>CmpUserMgr_Implementation</interfacename>
 * <description>External implementation of CmpUserMgr functions for authentication, authorization, and uesrobject handling</description>
 *
 * <copyright>
 * Copyright (c) 2020 CODESYS Development GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`CmpUserMgr_Implementation')
SET_PLACEHOLDER_NAME(`CmpUserMgr Implementation')

/** EXTERN LIB SECTION BEGIN **/
/*  Comments are ignored for m4 compiler so restructured text can be used. changecom(`/*', `*/') */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Changes the users password
 * :return: Error code
 * 	 + ERR_OK: Password changed successfully
 * 	 + ERR_NOTINITIALIZED: The user management is not initialized or it is not loaded yet
 * 	 + ERR_OPERATION_DENIED: Password change is either not supported or not allowed
 * 	 + ERR_USER_MISMATCH: User name does not match
 * 	 + ERR_INVALID_HANDLE: hUser is invalid or unknown
 */
typedef struct tagusermgrchangemypassword_struct
{
	RTS_IEC_HANDLE hUser;				/* VAR_INPUT */	/* Handle to the user */
	RTS_IEC_STRING *pszUser;			/* VAR_INPUT */	/* Name of the user, limited to 59 chars */
	RTS_IEC_STRING *pszOldPassword;		/* VAR_INPUT */	/* Old password (plain text), limited to 59 chars */
	RTS_IEC_STRING *pszNewPassword;		/* VAR_INPUT */	/* New password (plain text), limited to 59 chars */
	RTS_IEC_RESULT UserMgrChangeMyPassword;	/* VAR_OUTPUT */	
} usermgrchangemypassword_struct;

DEF_API(`void',`CDECL',`usermgrchangemypassword',`(usermgrchangemypassword_struct *p)',1,0x25575868,0x03051100)

/**
 * Gets user access rights on the specified object (authorization)!
 * :return: Error code
 * 	 + ERR_OK: If user has the requested rights on the object or if no user management is configured
 * 	 + ERR_PARAMETER: If user is not available or the object does not exist
 * 	 + ERR_FAILED: If something failed retrieving the access rights
 * 	 + ERR_NO_ACCESS_RIGHTS: Explicitly denied rights
 * 	 + ERR_INVALID_HANDLE: hUser is invalid or unknown
 */
typedef struct tagusermgrgetuseraccessrights_struct
{
	RTS_IEC_STRING *pszObject;			/* VAR_INPUT */	/* Full object name (see object tree) */
	RTS_IEC_HANDLE hUser;				/* VAR_INPUT */	/* Handle to the user */
	RTS_IEC_DWORD *pulRights;			/* VAR_INPUT */	/* Pointer to get admitted rights */
	RTS_IEC_DWORD *pulDeniedRights;		/* VAR_INPUT */	/* Pointer to get denied rights.

 .. note:: If the required right is denied _and_ admitted on the specified object, the denied right is more significant and so the access must be denied !! */
	RTS_IEC_RESULT UserMgrGetUserAccessRights;	/* VAR_OUTPUT */	
} usermgrgetuseraccessrights_struct;

DEF_API(`void',`CDECL',`usermgrgetuseraccessrights',`(usermgrgetuseraccessrights_struct *p)',1,0xB30BF82F,0x03051100)

/**
 * Checks user access rights on the specified object (authorization)!
 * :return: Error code
 * 	 + ERR_OK: If user has the requested rights on the object or if no user management is configured
 * 	 + ERR_PARAMETER: If user is not available or the object does not exist
 * 	 + ERR_FAILED: If something failed retrieving the access rights
 * 	 + ERR_NO_ACCESS_RIGHTS: Explicitly denied rights
 * 	 + ERR_INVALID_HANDLE: hUser is invalid or unknown
 */
typedef struct tagusermgrhasuseraccessrights_struct
{
	RTS_IEC_STRING *pszObject;			/* VAR_INPUT */	/* Full object name (see object tree) */
	RTS_IEC_HANDLE hUser;				/* VAR_INPUT */	/* Handle to the user */
	RTS_IEC_DWORD ulRequestedRights;	/* VAR_INPUT */	/* Requested rights on that object */
	RTS_IEC_RESULT UserMgrHasUserAccessRights;	/* VAR_OUTPUT */	
} usermgrhasuseraccessrights_struct;

DEF_API(`void',`CDECL',`usermgrhasuseraccessrights',`(usermgrhasuseraccessrights_struct *p)',1,0xB4009E6D,0x03051100)

/**
 * Checks if the user management is active.
 * :return: TRUE: The user management is activated or enforced. FALSE: The user management is not activated.
 */
typedef struct tagusermgrisactive_struct
{
	RTS_IEC_BOOL UserMgrIsActive;		/* VAR_OUTPUT */	
} usermgrisactive_struct;

DEF_API(`void',`CDECL',`usermgrisactive',`(usermgrisactive_struct *p)',1,0x29D8803F,0x03051100)

/**
 * Logs user in to the runtime system requiring an active user management.
 * :return: Handle to the user or RTS_INVALID_HANDLE if not available
 */
typedef struct tagusermgrlogin_struct
{
	RTS_IEC_STRING *pszUser;			/* VAR_INPUT */	/* Name of the user, limited to 59 chars */
	RTS_IEC_STRING *pszPassword;		/* VAR_INPUT */	/* Password (plain text), limited to 59 chars */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to error code
 	 + ERR_OK: User/password combination is valid
 	 + ERR_ACTIVATE_USERMGMT: The login was successful. But the user management is enforced and not active. Activate the user management.
 	 + ERR_CHANGE_PASSWORD: The login was successful. But the user must change his password.
 	 + ERR_NO_USERMGMT: Login was not successful. The user management is not activated. Use empty user and password to login.
 	 + ERR_NO_ACCESS_RIGHTS: The login was not successful, because of another reason. */
	RTS_IEC_HANDLE UserMgrLogin;		/* VAR_OUTPUT */	
} usermgrlogin_struct;

DEF_API(`void',`CDECL',`usermgrlogin',`(usermgrlogin_struct *p)',1,0xE7251EF7,0x03051100)

/**
 * Logout specified by the user
 * :return: Error code
 * 	 + ERR_OK: User is available and logout succeeded
 * 	 + ERR_PARAMETER: If user is not available
 * 	 + ERR_INVALID_HANDLE: hUser is invalid or unknown
 */
typedef struct tagusermgrlogout_struct
{
	RTS_IEC_HANDLE hUser;				/* VAR_INPUT */	/* Handle to the user */
	RTS_IEC_RESULT UserMgrLogout;		/* VAR_OUTPUT */	
} usermgrlogout_struct;

DEF_API(`void',`CDECL',`usermgrlogout',`(usermgrlogout_struct *p)',1,0xC9A61E57,0x03051100)

/**
 * Adds a new object to the user management, so the access rights can be configured on that object.
 *
 * .. note:: The name of the object must include the full name-space with "Device" as the root node, e.g. "Device.MyObject" or if it's a file system object with "/" as the root node.
 * :return: Handle to the object or RTS_INVALID_HANDLE if it could not be added
 */
typedef struct tagusermgrobjectadd_struct
{
	RTS_IEC_STRING *pszObject;			/* VAR_INPUT */	/* Full object name (see object tree) */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to error code
 	 + ERR_OK: Object could be added
 	 + ERR_PARAMETER: Object invalid = NULL or empty
 	 + ERR_NOTINITIALIZED: The user management is not initialized or it is not loaded yet
 	 + ERR_NOMEMORY: If memory could not be allocated to store this object */
	RTS_IEC_HANDLE UserMgrObjectAdd;	/* VAR_OUTPUT */	
} usermgrobjectadd_struct;

DEF_API(`void',`CDECL',`usermgrobjectadd',`(usermgrobjectadd_struct *p)',1,0xDF2F6AEC,0x03051100)

/**
 * Removes an object from the user management and all its children
 * :return: Error code
 * 	 + ERR_OK: Object could be removed
 * 	 + ERR_PARAMETER: Invalid object handle
 */
typedef struct tagusermgrobjectremove_struct
{
	RTS_IEC_HANDLE hObject;				/* VAR_INPUT */	/* Handle to object */
	RTS_IEC_RESULT UserMgrObjectRemove;	/* VAR_OUTPUT */	
} usermgrobjectremove_struct;

DEF_API(`void',`CDECL',`usermgrobjectremove',`(usermgrobjectremove_struct *p)',1,0xAFB36783,0x03051100)

/**
 * | Sets the used access rights for the object specified by handle.
 * | The rights are additionally stored in an internal list. In case USERDB_RIGHT_NONE is passed for ulUsedRights the previously stored rights are retrieved for this object.
 * :return: Error code
 * 	 + ERR_OK: Rights are successfully set
 * 	 + ERR_PARAMETER: Invalid object handle
 * 	 + ERR_NO_OBJECT: Object was not found for rights retrieval
 */
typedef struct tagusermgrobjectsetusedrights_struct
{
	RTS_IEC_HANDLE hObject;				/* VAR_INPUT */	/* Handle to the object */
	RTS_IEC_DWORD ulUsedRights;			/* VAR_INPUT */	/* Used access rights or USERDB_RIGHT_NONE for retrieval */
	RTS_IEC_RESULT UserMgrObjectSetUsedRights;	/* VAR_OUTPUT */	
} usermgrobjectsetusedrights_struct;

DEF_API(`void',`CDECL',`usermgrobjectsetusedrights',`(usermgrobjectsetusedrights_struct *p)',1,0xAA821FF5,0x03051100)

/**
 * Re-logs user in to the runtime system using an active user management. The user name must match to the user name used for the initial login of the user.
 * :return: Error code
 * 	 + ERR_OK: User/password combination is valid
 * 	 + ERR_NOTINITIALIZED: The user management is not initialized or it is not loaded yet
 * 	 + ERR_RELOGIN: hUser known, but not logged in
 * 	 + ERR_FAILED: Password is wrong.
 * 	 + ERR_USER_MISMATCH: User name does not match
 * 	 + ERR_INVALID_HANDLE: hUser is invalid or unknown
 */
typedef struct tagusermgrrelogin_struct
{
	RTS_IEC_HANDLE hUser;				/* VAR_INPUT */	/* Handle to the user */
	RTS_IEC_STRING *pszUser;			/* VAR_INPUT */	/* Name of the user, limited to 59 chars */
	RTS_IEC_STRING *pszPassword;		/* VAR_INPUT */	/* Password (plain text), limited to 59 chars */
	RTS_IEC_RESULT UserMgrRelogin;		/* VAR_OUTPUT */	
} usermgrrelogin_struct;

DEF_API(`void',`CDECL',`usermgrrelogin',`(usermgrrelogin_struct *p)',1,0x69692107,0x03051100)

#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/

