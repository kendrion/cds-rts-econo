/**
 * <interfacename>CmpUserMgr</interfacename>
 * <description> 
 *  Interface for the user management component.
 *
 *  The user management in the runtime system is based on ACL (Access Control Lists). Here we have Users and UserGroups
 *  and access rights on objects.
 *
 *  Here are the principles of the user management:
 *
 *  1. There are users which are identified by its user name 
 *  2. A User can be a member of one or several UserGroups. But at least the user is a member of the group "Everyone".
 *  3. There are some predefined UserGroups, which covers the most typical use cases: 
 *     - "Administrator": Administrator group. A member of this groups has all access rights on all objects!
 *     - "Developer": Developer group. A member of this groups has all access to the IEC applications an all related stuff.
 *     - "Service": Service group. A member of this groups has all access to object for maintenance and service operations.
 *     - "Watch": Watch group. A member of this groups has read-only access to the objects.
 *     - "Everyone": Everyone group. A member of this groups has read-only access to the objects.
 *
 *  4. A UserGroup can be derived from another UserGroup an inherits all rights from the base group
 *  5. Every object in the runtime system, that must be protected with access rights is registered dynamically during startup of the runtime by the corresponding
 *     component under the appropriate folder.
 *     The objects in the runtime system are organized as a tree with 2 root nodes:
 *     - Runtime system object:
 *          "Device"
 *              |----- "PlcLogic"
 *              |----------- "Application"
 *              |----- "Logger"
 *              |----- "Settings"
 *              |----- "UserManagement"	
 *
 *     - Filesystem objects:
 *             "/"
 *              |----- "Temp"
 *              |----------- "Test.txt"
 *
 *  6. There are 5 different access rights that can be specified at every group for each object:
 *     - USERDB_RIGHT_NONE: Access denied
 *     - USERDB_RIGHT_VIEW: Only view rights on the object. Object cannot be modified in any case!
 *     - USERDB_RIGHT_MODIFY: Object can be viewed and modified
 *     - USERDB_RIGHT_EXECUTE: Object can be executed
 *     - USERDB_RIGHT_ADD_REMOVE: It is allowed to add and remove objects or subobjects
 *     - USERDB_RIGHT_ALL: All rights allowed on the object
 *
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2018 CODESYS GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`CmpUserMgr')

REF_ITF(`CmpUserDBItf.m4')
REF_ITF(`CmpBinTagUtilItf.m4')
REF_ITF(`CmpDeviceItf.m4')

#include "CmpItf.h"


/**
 * <category>Static defines</category>
 * <description>Number of predefined static session entries</description>
 */
#ifndef USERMGR_NUM_OF_STATIC_SESSIONS
	#define USERMGR_NUM_OF_STATIC_SESSIONS			8
#endif


/**
 * <category>Online services</category>
 * <description>
 *	Online service to read the user management.
 * </description>
 * <service name="SRV_READ_USER_MGMT">
 *	<Request>
 *		<No further tag>
 *	</Request>
 *	<Response>
 *		<tag name="TAG_PROPERTY_USERS" required="mandatory">[RTS_UI32]: User property</tag>
 *		<tag name="TAG_PROPERTY_GROUPS" required="mandatory">[RTS_UI32]: Group property</tag>
 *		<tag name="TAG_USER" required="mandatory">Top level tag may contain the following sub tags</tag>
 *			<tag name="TAG_NAME" required="optional">[char*]: NUL terminated name of the user</tag>
 *			<tag name="TAG_PASSWORD" required="optional">[char*]: Password as MD5 hash</tag>
 *			<tag name="TAG_PROPERTY" required="optional">[RTS_UI32]: User property</tag>
 *		<tag name="TAG_GROUP" required="mandatory">Top level tag may contain the following sub tags</tag>
 *			<tag name="TAG_NAME" required="optional">[char*]: NUL terminated name of the user</tag>
 *			<tag name="TAG_PASSWORD" required="optional">[char*]: Password as MD5 hash</tag>
 *			<tag name="TAG_PROPERTY" required="optional">[RTS_UI32]: User property</tag>
 *	</Response>
 * </service>
 */
#define SRV_READ_USER_MGMT							0x01

/**
 * <category>Online services</category>
 * <description>Online service to write the user management</description>
 */
#define SRV_WRITE_USER_MGMT							0x02

/**
 * <category>Online services</category>
 * <description>Online service to read the user rights management</description>
 */
#define SRV_READ_USER_RIGHTS_MGMT					0x03

/**
 * <category>Online services</category>
 * <description>Online service to write the user rights management</description>
 */
#define SRV_WRITE_USER_RIGHTS_MGMT					0x04

/**
 * <category>Online services</category>
 * <description>Online service to add a single user</description>
 */
#define SRV_USER_ADD								0x05

/**
 * <category>Online services</category>
 * <description>Online service to add a single user</description>
 */
#define SRV_USER_DELETE								0x06

/**
 * <category>Online services</category>
 * <description>Online service to add a single user</description>
 */
#define SRV_USER_CHANGE_PASSWORD					0x07


/**
 * <category>Online tags</category>
 * <description>Property of the database for users</description>
 */
#define TAG_PROPERTY_USERS							0x01

/**
 * <category>Online tags</category>
 * <description>Property of the database for groups</description>
 */
#define TAG_PROPERTY_GROUPS							0x02

/**
 * <category>Online tags</category>
 * <description>Name tag</description>
 */
#define TAG_NAME									0x03

/**
 * <category>Online tags</category>
 * <description>Property of an entry</description>
 */
#define TAG_PROPERTY								0x04

/**
 * <category>Online tags</category>
 * <description>Property of an entry</description>
 */
#define TAG_PASSWORD								0x05

/**
 * <category>Online tags</category>
 * <description>Group member</description>
 */
#define TAG_GROUP_MEMBER							0x06

/**
 * <category>Online tags</category>
 * <description>User member</description>
 */
#define TAG_USER_MEMBER								0x07

/**
 * <category>Online tags</category>
 * <description>Property of the database for groups</description>
 */
#define TAG_RIGHTS									0x08

/**
 * <category>Online tags</category>
 * <description>Property of the database for groups</description>
 */
#define TAG_DENIED_RIGHTS							0x09

/**
 * <category>Online tags</category>
 * <description>ID of an object</description>
 */
#define TAG_ID										0x0A

/**
 * <category>Online tags</category>
 * <description>Parent ID of an object</description>
 */
#define TAG_PARENT_ID								0x0B

/**
 * <category>Online tags</category>
 * <description>Object handle</description>
 */
#define TAG_OBJECT_HANDLE							0x0C

/**
 * <category>Online tags</category>
 * <description>Group handle</description>
 */
#define TAG_GROUP_HANDLE							0x0D

/**
 * <category>Online tags</category>
 * <description>Used rights</description>
 */
#define TAG_USED_RIGHTS								0x0E

/**
 * <category>Online tags</category>
 * <description>Version of Online User Manager</description>
 */
#define TAG_USRMGR_VERSION							0x0F

/**
 * <category>Online tags</category>
 * <description>Contains user information</description>
 */
#define TAG_USER									0x81

/**
 * <category>Online tags</category>
 * <description>Contains group information:
 *                     - group name
 *                     - list of users in this group
 *                     - list of child groups derived from this group
 * </description>
 */
#define TAG_GROUP									0x82

/**
 * <category>Online tags</category>
 * <description>Contains object information</description>
 */
#define TAG_OBJECT									0x83


/**
 * <category>User management session entry</category>
 * <description>
 *	Contains the correlation between the SessionID of the connection and the logged in User.
 * </description>
 * <element name="ulSessionId" type="IN">SessionID of the connection</element>
 * <element name="hUser" type="IN">Handle of the logged in user on the SessionID</element>
 */
typedef struct
{
	RTS_UI32 ulSessionId;
	RTS_HANDLE hUser;
} UserMgrSessionEntry;


/**
 * <category>Crypt types</category>
 * <description>Crypt types to chiffre the password</description>
 * <element name="USERMGR_CRYPT_INVALID" type="IN">Invalid of unknown crypt type</element>
 * <element name="USERMGR_CRYPT_XOR" type="IN">Disguise password with an XOR algorithm</element>
 */
#define USERMGR_CRYPT_INVALID				0x00000000
#define USERMGR_CRYPT_XOR					0x00000001

/**
 * <category>Static defines</category>
 * <description>Predefined objects in the runtime</description>
 */
#define USERDB_OBJECT_USERMGMT		"Device.UserManagement"


/**
 * <category>Event parameter</category>
 * <element name="bUserManagementChanged" type="IN">TRUE: Usermanagement database changed; FALSE: Not changed</element>
 * <element name="bRightsManagementChanged" type="IN">TRUE: Rightsmanagement database changed; FALSE: Not changed</element>
 */
typedef struct
{
	RTS_BOOL bUserManagementChanged;
	RTS_BOOL bRightsManagementChanged;
} EVTPARAM_CmpUserMgrDatabaseChanged;

#define EVTPARAMID_CmpUserMgrDatabaseChanged	0x0001
#define EVTVERSION_CmpUserMgrDatabaseChanged	0x0001

/**
 * <category>Events</category>
 * <description>Event is sent every time the usermanagement database or the userrights database was changed</description>
 * <param name="pEventParam" type="IN">EVTPARAM_CmpUserMgrDatabaseChanged</param>
 */
#define EVT_UserMgrDatabaseChanged		MAKE_EVENTID(EVTCLASS_INFO, 1)

/**
 * <category>Static defines</category>
 * <description>Number of unsuccessful login retries to limit failed user authentication
 * In case USERMGR_NUM_OF_LOGIN_RETRIES is set to 0 this security feature is disabled.
 * </description>
 */
#ifndef USERMGR_NUM_OF_LOGIN_RETRIES
	#define USERMGR_NUM_OF_LOGIN_RETRIES			3
#endif

/**
 * <category>Static defines</category>
 * <description>Timeout after USERMGR_NUM_OF_LOGIN_RETRIES unsuccessful login tries in seconds, i.e. the user is temporarily excluded
 * The maximal timeout value for user exclusion is 4233600 seconds which is equivalent to 49 days. But this is not persistent, i.e. a restart of the runtime resets the exclusion.
 * </description>
 */
#ifdef USERMGR_TIMEOUT_OF_LOGIN_RETRIES
	#define USERMGR_USERLOCK_TIME				USERMGR_TIMEOUT_OF_LOGIN_RETRIES
#endif
#ifndef USERMGR_USERLOCK_TIME
	#define USERMGR_USERLOCK_TIME				60
#endif


/**
 * <category>SecuritySettings</category>
 * <description>Security setting of the behavior, if login authentication fails. Can be selected in CmpSecurityManager.
 *	NOTE:
 *		Security modes must be ordered in an descending sorting, i.e. the setting with the highest security level is found at the beginning of the list!
 * </description>
 */
#define CMPUSERMGR_KEY_STRING_LOGIN				CMPSETTINGS_CATEGORY_SECURITY ".UserLogin_ErrorBehavior"
#define CMPUSERMGR_KEY_STRING_LOGIN_DESC		"Behavior on user login errors"

#define CMPUSERMGR_VALUE_LOGIN_EXCLUSION		"EXCLUSION"
#define CMPUSERMGR_VALUE_LOGIN_TIMEOUT			"TIMEOUT"
#define CMPUSERMGR_VALUE_LOGIN_NOEXCLUSION		"NOEXCLUSION"

#ifndef CMPUSERMGR_VALUE_LOGIN_DEFAULT
	#define CMPUSERMGR_VALUE_LOGIN_DEFAULT		CMPUSERMGR_VALUE_LOGIN_TIMEOUT
#endif


/**
 * <category>SecuritySettings</category>
 * <description>Security settings of the behavior when login authentication fails.
 * </description>
 */
typedef enum
{
	UserMgrLoginErr_NoExclusion,
	UserMgrLoginErr_Timeout,
	UserMgrLoginErr_Exclusion
} USERMGR_LOGIN_ERROR;

#define CMPUSERMGR_VALUE_LOGIN_LIST				{ \
													{(RTS_I32)UserMgrLoginErr_Exclusion, CMPSECMAN_SFLAGS_NONE, CMPUSERMGR_VALUE_LOGIN_EXCLUSION, "User is excluded permanently"},\
													{(RTS_I32)UserMgrLoginErr_Timeout, CMPSECMAN_SFLAGS_NONE, CMPUSERMGR_VALUE_LOGIN_TIMEOUT, "User is excluded temporarily. See setting [UserLockTime] which specifies the locked time."},\
													{(RTS_I32)UserMgrLoginErr_NoExclusion, CMPSECMAN_SFLAGS_NONE, CMPUSERMGR_VALUE_LOGIN_NOEXCLUSION, "No user exclusion"},\
												}

/**
 * <category>SecuritySettings</category>
 * <description>Editable security setting: Maximal number of failed login retries
 * </description>
 */
#define CMPUSERMGR_KEY_INT_MAXRETRIES				CMPSETTINGS_CATEGORY_SECURITY ".UserLogin_MaxRetries"
#define CMPUSERMGR_KEY_INT_MAXRETRIES_DESC			"Maximal number of failed login retries"

#ifndef CMPUSERMGR_VALUE_MAXRETRIES_DEFAULT
	#define CMPUSERMGR_VALUE_MAXRETRIES_DEFAULT		USERMGR_NUM_OF_LOGIN_RETRIES
#endif

/**
 * <category>SecuritySettings</category>
 * <description>Editable security setting: Exclusion timeout in seconds in case the maximal number of failed login retries is reached
 * </description>
 */
#define CMPUSERMGR_KEY_INT_LOCKTIME					CMPSETTINGS_CATEGORY_SECURITY ".User_LockTime"
#define CMPUSERMGR_KEY_INT_LOCKTIME_DESC			"Time in [s] which the user is locked after a maximum number of failed login"

#ifndef CMPUSERMGR_VALUE_LOCKTIME_DEFAULT
	#define CMPUSERMGR_VALUE_LOCKTIME_DEFAULT		USERMGR_USERLOCK_TIME
#endif

/**
 * <category>SecuritySettings</category>
 * <description>Security settings to enforce the usage of the user management.
 *	NOTE:
 *		Security modes must be ordered in an descending sorting, i.e. the setting with the highest security level is found at the beginning of the list!
 * </description>
 */
#define CMPUSERMGR_KEY_STRING_ENFORCE				CMPSETTINGS_CATEGORY_SECURITY ".UserMgmtEnforce"
#define CMPUSERMGR_KEY_STRING_ENFORCE_DESC			"Setting to enforce user management in general!"

#define CMPUSERMGR_VALUE_ENFORCE_YES				"YES"
#define CMPUSERMGR_VALUE_ENFORCE_NO					"NO"

#ifndef CMPUSERMGR_VALUE_ENFORCE_DEFAULT
	#define CMPUSERMGR_VALUE_ENFORCE_DEFAULT		CMPUSERMGR_VALUE_ENFORCE_NO
#endif

/**
 * <category>SecuritySettings</category>
 * <description>Security settings to enforce the usage of the user management.
 * </description>
 */
typedef enum
{
	UserMgmtEnforce_Yes,
	UserMgmtEnforce_No
} SECURITY_USERMGR_ENFORCE;

#define CMPUSERMGR_VALUE_ENFORCE_LIST			{\
													{(RTS_I32)UserMgmtEnforce_Yes, CMPSECMAN_SFLAGS_NONE, CMPUSERMGR_VALUE_ENFORCE_YES, "User management is enforced, i.e. no anonymous login possible"},\
													{(RTS_I32)UserMgmtEnforce_No, CMPSECMAN_SFLAGS_NONE, CMPUSERMGR_VALUE_ENFORCE_NO, "User management is optional"}\
												}



/**
 * <category>User state</category>
 * <description>The bit definitions for UserMgrGetState
 * </description>
 * <element name="USERMGR_US_NONE" type="The user is known</element>
 * <element name="USERMGR_US_LOGGEDIN" type="OUT">The user has successfully logged in</element>
 * <element name="USERMGR_US_AUTHENTICATED" type="OUT">The user is authenticated e.g. by password verification</element>
 */
#define USERMGR_US_NONE				UINT32_C(0x00000000)
#define USERMGR_US_LOGGEDIN			UINT32_C(0x00000001)
#define USERMGR_US_AUTHENTICATED	UINT32_C(0x00000002)


#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description>Login user on the usermanagement
 * NOTE: The returned handle is not compatible with a handle from the UserDB, and these handles must not be mixed.
 * </description>
 * <param name="pszUser" type="IN">Name of the user</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">User is available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">If pszUser is NULL</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">The user management is not initialized or it is not loaded yet</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT or ERR_PARAMETER">The user is not available in the user management</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOMEMORY">Could not store user information</errorcode>
 * <result>Handle to the user or RTS_INVALID_HANDLE if not available</result>
 */
DEF_ITF_API(`RTS_HANDLE', `CDECL', `UserMgrLogin', `(char *pszUser, RTS_RESULT *pResult)')

/**
 * <description>Logout specified by User
 * NOTE: The requred user handle is not compatible with a handle from the UserDB, and these handles must not be mixed.
 * </description>
 * <param name="hUser" type="IN">Handle to the user</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">User is available and logout succeeded</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">If user is not avilable</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_INVALID_HANDLE">hUser is invalid or unknown</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrLogout', `(RTS_HANDLE hUser)')

/**
 * <description>Logout specified by SessionID</description>
 * <param name="ulSessionId" type="IN">SessionID of the device online connection (see CmpDeviceItf.h)</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">SessionID or user is available and logout succeeded</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">If SessionID or user is not avilable</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_INVALID_HANDLE">Related user handle of the session is invalid or unknown</errorcode>
 */
 DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrLogoutBySessionId', `(RTS_UI32 ulSessionId)')

/**
 * <description>Check user password against credentials (authentication)!
 * NOTE: The requred user handle is not compatible with a handle from the UserDB, and these handles must not be mixed.
 * </description>
 * <param name="hUser" type="IN">Handle to the user</param>
 * <param name="pszPassword" type="IN">Pointer to the cleartext password!</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">User is available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">If user is not avilable</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">If user password does not match credentials</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_INVALID_HANDLE">hUser is invalid or unknown</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrCheckPassword', `(RTS_HANDLE hUser, char *pszPassword)')

/**
 * <description>Get properties of a user
 * NOTE: The requred user handle is not compatible with a handle from the UserDB, and these handles must not be mixed.
 * </description>
 * <param name="hUser" type="IN">Handle to the user</param>
 * <param name="pulProperty" type="OUT">Pointer to return the properties. For details see category "UserDB properties"</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Properties could be retrieved</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Property pointer = NULL</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_INVALID_HANDLE">hUser is invalid or unknown</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrGetProperty', `(RTS_HANDLE hUser, RTS_UI32 *pulProperty)')

/**
 * <description>Check if the a user is a member of the given group
 * NOTE: The requred user handle is not compatible with a handle from the UserDB, and these handles must not be mixed.
 * </description>
 * <param name="pszGroup" type="IN">Group name</param>
 * <param name="hUser" type="IN">Handle to the user</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">The user is a member of the given group</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">The user is not a member of the given group</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_INVALID_HANDLE">hUser is invalid or unknown</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrIsGroupMember', `(char *pszGroup, RTS_HANDLE hUser)')

/**
 * <description>Returns the user state
 * The returned bitfield shows whether the user is logged in and is authenticated (see category User state)
 * NOTE: The requred user handle is not compatible with a handle from the UserDB, and these handles must not be mixed.
 * </description>
 * <param name="hUser" type="IN">Handle to the user</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <result>User state</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Success</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_INVALID_HANDLE">hUser is invalid or unknown</errorcode>
 */
DEF_ITF_API(`RTS_UI32', `CDECL', `UserMgrGetState', `(RTS_HANDLE hUser, RTS_RESULT *pResult)')

/**
 * <description>Check user access rights on the specified object (authorization)!</description>
 * <param name="pszObject" type="IN">Full object name (see object tree)</param>
 * <param name="ulSessionId" type="IN">SessionID of the device online connection (see CmpDeviceItf.h)</param>
 * <param name="ulRequestedRights" type="IN">Requested rights on that object</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">If user has the requested rights on the object or if no user management is configured</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">If SessionID or user is not avilable or the object does not exist</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">If something failed retrieving the access rights</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_ACCESS_RIGHTS">Explicitly denied rights</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_INVALID_HANDLE">Related user handle of the session is invalid or unknown</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrHasAccessRights', `(char *pszObject, RTS_UI32 ulSessionId, RTS_UI32 ulRequestedRights)')

/**
 * <description>Get user access rights on the specified object (authorization)!</description>
 * <param name="pszObject" type="IN">Full object name (see object tree)</param>
 * <param name="ulSessionId" type="IN">SessionID of the device online connection (see CmpDeviceItf.h)</param>
 * <param name="pulRights" type="IN">Pointer to get admitted rights</param>
 * <param name="pulDeniedRights" type="IN">Pointer to get denied rights.
 *	 NOTE:
 *	 If the required right is denied _and_ admitted on the specified object, the denied right is more significant and so the access must be denied !!</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">If user has the requested rights on the object or if no user management is configured</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">If SessionID or user is not avilable or the object does not exist</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">If something failed retrieving the access rights</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_ACCESS_RIGHTS">Explicitly denied rights</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_INVALID_HANDLE">Related user handle of the session is invalid or unknown</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrGetAccessRights', `(char *pszObject, RTS_UI32 ulSessionId, RTS_UI32 *pulRights, RTS_UI32 *pulDeniedRights)')

/**
 * <description>Check user access rights on the specified object (authorization)!
 * NOTE: The requred user handle is not compatible with a handle from the UserDB, and these handles must not be mixed.
 * </description>
 * <param name="pszObject" type="IN">Full object name (see object tree)</param>
 * <param name="hUser" type="IN">Handle to the user</param>
 * <param name="ulRequestedRights" type="IN">Requested rights on that object</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">If user has the requested rights on the object or if no user management is configured</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">If user is not avilable or the object does not exist</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">If something failed retrieving the access rights</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_ACCESS_RIGHTS">Explicitly denied rights</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_INVALID_HANDLE">hUser is invalid or unknown</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrHasUserAccessRights', `(char *pszObject, RTS_HANDLE hUser, RTS_UI32 ulRequestedRights)')

/**
 * <description>Get user access rights on the specified object (authorization)!
 * NOTE: The requred user handle is not compatible with a handle from the UserDB, and these handles must not be mixed.
 * </description>
 * <param name="pszObject" type="IN">Full object name (see object tree)</param>
 * <param name="hUser" type="IN">Handle to the user</param>
 * <param name="pulRights" type="IN">Pointer to get admitted rights</param>
 * <param name="pulDeniedRights" type="IN">Pointer to get denied rights.
 *	 NOTE:
 *	 If the required right is denied _and_ admitted on the specified object, the denied right is more significant and so the access must be denied !!</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">If user has the requested rights on the object or if no user management is configured</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">If user is not avilable or the object does not exist</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">If something failed retrieving the access rights</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_ACCESS_RIGHTS">Explicitly denied rights</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_INVALID_HANDLE">hUser is invalid or unknown</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrGetUserAccessRights', `(char *pszObject, RTS_HANDLE hUser, RTS_UI32 *pulRights, RTS_UI32 *pulDeniedRights)')

/**
 * <description>Add online SessionID to the user (bind the user at this session)
 * NOTE: The requred user handle is not compatible with a handle from the UserDB, and these handles must not be mixed.
 * </description>
 * <param name="hUser" type="IN">Handle to the user</param>
 * <param name="ulSessionId" type="IN">SessionID of the device online connection (see CmpDeviceItf.h)</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">If user has the requested rights on the object or if no user management is configured</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">If CmpUserMgr component is still not initialized</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOMEMORY">Could not store SessionID</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrAddSessionId', `(RTS_HANDLE hUser, RTS_UI32 *pulSessionId)')

/**
 * <description>Remove online SessionID from the user (unbind the user from this session)</description>
 * <param name="hUser" type="IN">Handle to the user</param>
 * <param name="ulSessionId" type="IN">SessionID of the device online connection (see CmpDeviceItf.h)</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">If user has the requested rights on the object or if no user management is configured</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">If CmpUserMgr component is still not initialized</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOMEMORY">Could not store SessionID</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrRemoveSessionId', `(RTS_UI32 ulSessionId)')

/**
 * <description>Returns the user bound at the SessionID
 * NOTE: The returned handle is not compatible with a handle from the UserDB, and these handles must not be mixed.
 * </description>
 * <param name="ulSessionId" type="IN">SessionID of the device online connection (see CmpDeviceItf.h)</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">User is available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">If SessionID is invalid</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">The user management is not initialized or it is not loaded yet</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT or ERR_PARAMETER">The user is not available in the user management</errorcode>
 * <result>Handle to the user or RTS_INVALID_HANDLE if not available</result>
 */
DEF_ITF_API(`RTS_HANDLE', `CDECL', `UserMgrFindUserBySessionId', `(RTS_UI32 ulSessionId, RTS_RESULT *pResult)')

/**
 * <description>Adds an value to an logged in user. This can be used as some kind of chache that exists as long as the user is logged in.</description>
 * <param name="hUser" type="IN">Handle to the user.</param>
 * <param name="key" type="IN">Access key for the chace value. This has to be used at UserMgrGetInfoOfUser to access the value.</param>
 * <param name="pValue" type="IN">Value to cache at the user.</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Value cached</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_DUPLICATE">The same key has been used already</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">The caching failed</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrAddInfoToUser', `(RTS_HANDLE hUser, RTS_SIZE key, RTS_TYPEDVALUE *pValue)')

/**
 * <description>Removes a specific chace value from an user.</description>
 * <param name="hUser" type="IN">Handle to the user.</param>
 * <param name="key" type="IN">Key of the cache value.</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Removing cache value successfull</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">No cache value with this key available.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Removing cache value failed</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrRemoveInfoFromUser', `(RTS_HANDLE hUser, RTS_SIZE key)')

/**
 * <description>Removes a specific chace value from all logged in users.</description>
 * <param name="key" type="IN">Key of the cache value.</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Removing cache value successfull</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Removing cache value failed</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrRemoveInfoFromAllUsers', `(RTS_SIZE key)')

/**
 * <description>Retrieves the value cached using UserMgrAddInfoToUser.</description>
 * <param name="hUser" type="IN">Handle to the user.</param>
 * <param name="key" type="IN">Key of the cache value.</param>
 * <param name="pValue" type="IN">Value to cache at the user.</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Retrieving cache value successfull. Value copied to pValue.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Some parameter is invalid</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">No cache value with this key available.</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrGetInfoOfUser', `(RTS_HANDLE hUser, RTS_SIZE key, RTS_TYPEDVALUE *pValue)')

/**
 * <description>Add the error tag to the reply stream of an online service, if the service is denied because of a failed access right (authorization error)!</description>
 * <param name="pWriter" type="IN">Pointer the writer stream</param>
 * <param name="Result" type="IN">Result code of the operation</param>
 * <param name="pszObject" type="IN">Pointer to name of the object, whose access was denied</param>
 * <param name="ulRequestedRights" type="IN">Requested rights on the object, which are not enabled</param>
 * <param name="ulSessionId" type="IN">SessionID of the device online connection (see CmpDeviceItf.h)</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Reply tag could be created</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Reply tag could not be created</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrAddOnlineAccessError', `(BINTAGWRITER *pWriter, RTS_RESULT Result, char *pszObject, RTS_UI32 ulRequestedRights, RTS_UI32 ulSessionID)')

/**
 * <description>
 *	Add a new object to the user management, so the access rights can be configured on that object.
 *	NOTE:
 *	The name of the object must include the full namespace with "Device" as the root node, e.g. "Device.MyObject" or if it's a filesystem object with "/" as the root node.
 * </description>
 * <param name="pszObject" type="IN">Full object name (see object tree)</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Object could be added</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Object invalid = NULL or empty</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">The user management is not initialized or it is not loaded yet</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOMEMORY">If memory could not be allocated to store this object</errorcode>
 * <result>Handle to the object or RTS_INVALID_HANDLE if it could not be added</result>
 */
DEF_ITF_API(`RTS_HANDLE', `CDECL', `UserMgrObjectAdd', `(char *pszObject, RTS_RESULT *pResult)')

/**
 * <description>Remove an object from the user management and all its children</description>
 * <param name="hObject" type="IN">Handle to object</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Object could be removed</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid object handle</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrObjectRemove', `(RTS_HANDLE hObject)')

/**
 * <description>
 *	Add a new object under a father object specified by its name to the user management, so the access rights can be configured on that object.
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
DEF_ITF_API(`RTS_HANDLE', `CDECL', `UserMgrObjectAddChild', `(RTS_HANDLE hFatherObject, char *pszObject, RTS_RESULT *pResult)')

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
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrObjectSetUsedRights', `(RTS_HANDLE hObject, RTS_UI32 ulUsedRights)')

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
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrObjectGetUsedRights', `(RTS_HANDLE hObject, RTS_UI32 *pulUsedRights)')

/**
 * <description>
 *	Open an existing object.
 *	NOTE:
 *	The name of the object must include the full namespace with "Device" as the root node, e.g. "Device.MyObject" or if it's a filesystem object with "/" as the root node.
 * </description>
 * <param name="pszObject" type="IN">Full object name (see object tree)</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Object could be opened</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Object not available of invalid</errorcode>
 * <result>Handle to the object or RTS_INVALID_HANDLE if it is not available</result>
 */
DEF_ITF_API(`RTS_HANDLE', `CDECL', `UserMgrObjectOpen', `(char *pszObject, RTS_RESULT *pResult)')

/**
 * <description>Opens an existing object. Checks if the user is member of at least one group that has access to this object.</description>
 * <param name="pszObject" type="IN">Full object name (see object tree)</param>
 * <param name="hUser" type="IN">Handle of the logged in user.</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Object could be opened. User has access rights to the object.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Object not available of invalid.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_ACCESS_RIGHTS">User has no access rights to this object.</errorcode>
 * <result>Handle to the object or RTS_INVALID_HANDLE if it is not available or no access rights are existing.</result>
 */
DEF_ITF_API(`RTS_HANDLE', `CDECL', `UserMgrObjectOpen2', `(char *pszObject, RTS_HANDLE hUser, RTS_RESULT *pResult)')

/**
 * <description>Close an object</description>
 * <param name="hObject" type="IN">Handle to object</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Object could be closed</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid object handle</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrObjectClose', `(RTS_HANDLE hObject)')

/**
 * <description>Get a new challenge value to encrypt the password</description>
 * <param name="pulChallenge" type="OUT">Pointer to challenge to get the value</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Challenge could be generated</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter: pulChallenge = NULL</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrGetChallenge', `(RTS_UI32 *pulChallenge)')

/**
 * <description>Encrypt the password specified by crypt type</description>
 * <param name="pszPassword" type="IN">Cleartext password</param>
 * <param name="pszPasswordCrypted" type="OUT">Pointer to get the encrypted password</param>
 * <param name="pnPasswordCryptedSize" type="INOUT">Pointer to transmit the buffer length of pszPasswordCrypted or to return the necessary encrypted password length if result code is ERR_BUFFERSIZE</param>
 * <param name="ulCryptType" type="IN">Crypt type. See category "Crypt types" for details</param>
 * <param name="ulChallenge" type="IN">Challenge value to encrypt the password</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Password could be encrypted</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">At least one parameter is invalid</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOT_SUPPORTED">Unsupported encryption type</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_BUFFERSIZE">Buffer for pszPasswordCrypted is too short, so the requested length is returned in *pnPasswordCryptedSize</errorcode> 
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrCryptPassword', `(char *pszPassword, char *pszPasswordCrypted, int *pnPasswordCryptedSize, RTS_UI32 ulCryptType, RTS_UI32 ulChallenge)')

/**
 * <description>Decrypt the password specified by crypt type</description>
 * <param name="pszPasswordCrypted" type="IN">Encrypted password</param>
 * <param name="nPasswordCryptedSize" type="IN">Lenght of the encrypted password</param>
 * <param name="ulCryptType" type="IN">Crypt type. See category "Crypt types" for details</param>
 * <param name="ulChallenge" type="IN">Challenge value to encrypt the password</param>
 * <param name="pszPassword" type="IN">Cleartext password</param>
 * <param name="pnMaxLenPassword" type="INOUT">Pointer to transmit the buffer length of pszPassword or to return the necessary decrypted password length if result code is ERR_BUFFERSIZE</param>
  * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Password could be decrypted</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">At least one parameter is invalid</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOT_SUPPORTED">Unsupported decryption type</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_BUFFERSIZE">Buffer for pszPassword is too short, so the requested length is returned in *pnMaxLenPassword</errorcode> 
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrDecryptPassword', `(char *pszPasswordCrypted, int nPasswordCryptedSize, RTS_UI32 ulCryptType, RTS_UI32 ulChallenge, char *pszPassword, int *pnMaxLenPassword)')

#ifdef __cplusplus
}
#endif
