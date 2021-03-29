/**
 * <interfacename>CmpUserMgr</interfacename>
 * <description> 
 *  Interface for the user management component.
 *
 *  The user management in the runtime system is based on ACL (Access Control Lists). Here we have Users and UserGroups
 *  and access rights on objects.
 *
 *  The user manager requires some other interfaces to be implemented for full functionality:
 *
 *  1. CmpUserDB: This interface contains the basic functions to authentica users and to upload users to the CODESYS IDE
 *			in order to manage Groups. This interface has only read access to the database. No functions that can changed
 *			a value are defined here. This is the first interface to start if there is an existing user management that
 *			should be used by the CODESYS runtime system.
 *
 *	2. CmpUserDBConfiguration: This interface is used by the UserManager to Change the content of the users database. If this is
 *			not implemented it is not possible to manage the users and the corresponding credentials using the CODESYS IDE.
 *
 *	3. CmpUserGroupsDB: This interface provides access to existing user groups and users inside groups. This interface is
 *			read only too. No changes to the database can be done using this interface.
 * 
 *  4. CmpUserGroupsDBConfiguration: This interface allows to configure the user groups and allows to assign members to groups.
 *
 * 	All of these four interfaces are defined as static interfaces. To allow the user manager to use these interfaces it is
 *	required that the implementing component / components register the desired backends to the CmpUserMgr. It is possible to
 *	replace only the User Authentication interface and to stay with the default user groups and right database. This allows
 *	easy adoption of the CODESYS runtime to existing user databases.
 * 
 *  5. CmpUserObjectsDB:
 *
 *     Every object in the runtime system, that must be protected with access rights, is registered dynamically during startup of the runtime by the corresponding
 *     component under the appropriate folder.
 *
 *     The objects in the runtime system are organized as a tree with 2 root nodes:
 *     - Runtime system object:
 *          "Device"
 *              |----- "PlcLogic"
 *              |----------- "Application"
 *              |----- "Logger"
 *              |----- "Settings"
 *              |----- "UserManagement"	
 *
 *     - File system objects:
 *             "/"
 *              |----- "Temp"
 *              |----------- "Test.txt"
 *
 *     On every object there are assigned all user groups. And for every user group you can specify the appropriate access rights.
 *          
 *     There are 5 different access rights that can be specified at every group for each object:
 *
 *     - USERDB_RIGHT_NONE: Access denied
 *
 *     - USERDB_RIGHT_VIEW: Only view rights on the object. Object cannot be modified in any case!
 *
 *     - USERDB_RIGHT_MODIFY: Object can be viewed and modified
 *
 *     - USERDB_RIGHT_EXECUTE: Object can be executed
 *
 *     - USERDB_RIGHT_ADD_REMOVE: It is allowed to add and remove objects or sub objects
 *
 *     - USERDB_RIGHT_ALL: All rights allowed on the object
 *
 *     Not every access right is retrieved by an object. Which access rights are used are specified by each object and are masked in the user rights editor in the 
 *     programming system!
 *
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`CmpUserMgr')

REF_ITF(`CmpBinTagUtilItf.m4')
REF_ITF(`CmpDeviceItf.m4')
REF_ITF(`CmpCommunicationLibItf.m4')

#include "CmpItf.h"


/**
 * <category>Static defines</category>
 * <description>Number of predefined static login credential contexts used for authentication</description>
 */
#ifndef USERMGR_NUM_OF_STATIC_CREDENTIAL_CONTEXTS
	#define USERMGR_NUM_OF_STATIC_CREDENTIAL_CONTEXTS	4
#endif

/**
 * <category>Static defines</category>
 * <description>Number of predefined static session entries</description>
 */
#ifndef USERMGR_NUM_OF_STATIC_SESSIONS
	#define USERMGR_NUM_OF_STATIC_SESSIONS			8
#endif

/**
 * <category>Static defines</category>
 * <description>Max. length of the passwords. This value is used as buffer size and includes the terminating NUL. </description>
 */
#define USERMGR_MAX_PASSWORD_LEN					60

/**
 * <category>Static defines</category>
 * <description>Max. length of the user names. This value is used as buffer size and includes the terminating NUL. </description>
 */
#define USERMGR_MAX_USERNAME_LEN					60

/**
 * <category>Static defines</category>
 * <description>Max. length of the user group names. This value is used as buffer size and includes the terminating NUL. </description>
 */
#define USERMGR_MAX_GROUPNAME_LEN					60


/**
 * <category>Online services</category>
 * <service group="SG_CMPUSERMGR" id="SRV_READ_USER_MGMT" name="Read user management">
 * 	<description>
 *		Online service to read the user management.
 *
 *		This service requires a read right the user management. Additional the last authentication must not
 *		or than several minutes. It the last authentication is older than several minutes a OnlineAccessError with ERR_REAUTHENTICATE is returned.
 * 	</description>
 *	<request/>
 *	<response>
 *		<tag id="TAG_PROPERTY_USERS" name="UserDB Properties." cardinality="1" type="RTS_UI32" description="Properties of the user database."/>
 *		<tag id="TAG_PROPERTY_GROUPS" name="GroupDB Properties." cardinality="1" type="RTS_UI32" description="Properties of the user group database."/>
 *		<complextag id="TAG_USER" name="User" cardinality="0..n" description="This tag contains a user.">
 *			<tag id="TAG_NAME" name="UserName" cardinality="1" type="RTS_UTF8STRING" description="The user name."/>
 *			<tag id="TAG_PROPERTY" name="UserProperties" cardinality="1" type="RTS_UI32" description="The users properties"/>
 *		</complextag>
 *		<complextag id="TAG_GROUP" name="Group" cardinality="0..n" description="This tag contains a user group.">
 *			<tag id="TAG_NAME" name="GroupName" cardinality="1" type="RTS_UTF8STRING" description="The name of the user group name."/>
 *			<tag id="TAG_PROPERTY" name="GroupProperties" cardinality="1" type="RTS_UI32" description="The user groups properties"/>
 *			<tag id="TAG_USER_MEMBER" name="UserMember" cardinality="0..1" type="RTS_UTF8STRING" description="A user that is member of this group."/>
 *			<tag id="TAG_GROUP_MEMBER" name="GroupMember" cardinality="0..1" type="RTS_UTF8STRING" description="An other group that is member of this group./>
 *		</complextag>
 *	</response>
 * </service>
 */
#define SRV_READ_USER_MGMT							0x01

/**
 * <category>Online services</category>
 * <description>Online service to write the user management. This service is not supported since V3.5.16.0.</description>
 */
#define SRV_WRITE_USER_MGMT							0x02


/**
 * <category>Online services</category>
 * <service group="SG_CMPUSERMGR" id="SRV_READ_USER_RIGHTS_MGMT" name="Read user rights management">
 *	<description>
 *		Online service to read the user rights management
 *
 *		This service requires a read right the user management. Additional the last authentication must not
 *		or than several minutes. It the last authentication is older than several minutes a OnlineAccessError with ERR_REAUTHENTICATE is returned.
 *	</description>
 *	<request>
 *		<tag id="TAG_OBJECT_HANDLE" name="GroupDB Properties." cardinality="0..1" type="Binary" description="Handle of the last object received."/>
 *	</request>
 *	<response>
 *		<complextag id="TAG_OBJECT" name="Object" cardinality="0..n" description="An object of the user rights management.">
 *			<tag id="TAG_ERROR" name="Serviceresult" cardinality="0..1" type="RTS_UI16" description="Errorcode of the operation"/>
 *			<tag id="TAG_OBJECT_HANDLE" name="GroupDB Properties." cardinality="0..1" type="Binary" description="Handle of the last object transmitted. Send this within the next request to get the next bunch of objects."/>
 *			<tag id="TAG_NAME" name="ObjectName" cardinality="1" type="RTS_UTF8STRING" description="The name of the object."/>
 *			<tag id="TAG_ID" name="ID" cardinality="1" type="RTS_UI32" description="ID of the object."/>
 *			<tag id="TAG_PARENT_ID" name="ParentID" cardinality="1" type="RTS_UI32" description="ID of the parent object."/>
 *			<tag id="TAG_USED_RIGHTS" name="UsedRights" cardinality="0..1" type="RTS_UI32" description="The evaluated rights of this object."/>
 *			<tag id="TAG_PROPERTY" name="ObjectProperty" cardinality="0..1" type="RTS_UI32" description="The properties of the object"/>
 *			<complextag id="TAG_GROUP" name="Group" cardinality="0..n" description="A group that has configured rights on an object.">
 *				<tag id="TAG_NAME" name="GroupName" cardinality="1" type="RTS_UTF8STRING" description="The name of the group"/>
 *				<tag id="TAG_RIGHTS" name="GarntedRights" cardinality="0..1" type="RTS_UI32" description="The granted rights on that object."/>
 *				<tag id="TAG_DENIED_RIGHTS" name="DeniedRights" cardinality="0..1" type="RTS_UI32" description="The denied rights on that object."/>
 *			</complextag>
 *		</complextag>
 *		
 *	</response>
 * </service>
 */
#define SRV_READ_USER_RIGHTS_MGMT					0x03

 /**
 * <category>Online services</category>
 * <service group="SG_CMPUSERMGR" id="SRV_READ_USER_RIGHTS_MGMT" name="Read user rights management">
 *	<description>
 *		Online service to write the user rights management
 *
 *		This service requires a modify right the user management. Additional the last authentication must not
 *		or than several minutes. It the last authentication is older than several minutes a OnlineAccessError with ERR_REAUTHENTICATE is returned.
 *	</description>
 *	<request>
 *		<complextag id="TAG_OBJECT" name="Object" cardinality="0..n" description="An object of the user rights management.">
 *			<tag id="TAG_NAME" name="ObjectName" cardinality="1" type="RTS_UTF8STRING" description="The name of the object."/>
 *			<tag id="TAG_ID" name="ID" cardinality="1" type="RTS_UI32" description="ID of the object."/>
 *			<tag id="TAG_PARENT_ID" name="ParentID" cardinality="1" type="RTS_UI32" description="ID of the parent object."/>
 *			<complextag id="TAG_GROUP" name="Group" cardinality="0..n" description="A group that has configured rights on an object.">
 *				<tag id="TAG_NAME" name="GroupName" cardinality="1" type="RTS_UTF8STRING" description="The name of the group"/>
 *				<tag id="TAG_RIGHTS" name="GarntedRights" cardinality="0..1" type="RTS_UI32" description="The granted rights on that object."/>
 *				<tag id="TAG_DENIED_RIGHTS" name="DeniedRights" cardinality="0..1" type="RTS_UI32" description="The denied rights on that object."/>
 *			</complextag>
 *		</complextag>
 *	</request>
 *	<response>
 *		<tag id="TAG_ERROR" name="Serviceresult" cardinality="0..1" type="RTS_UI16" description="Errorcode of the operation"/>
 *	</response>
 * </service>
 */
#define SRV_WRITE_USER_RIGHTS_MGMT					0x04

/**
 * <category>Online services</category>
 * <description>Online service to add a single user. This service is not supported since V3.5.16.0.</description>
 */
#define SRV_USER_ADD								0x05

/**
 * <category>Online services</category>
 * <description>Online service to delete a single user. This service is not supported since V3.5.16.0.</description>
 */
#define SRV_USER_DELETE								0x06

/**
 * <category>Online services</category>
 * <description>Online service to change the password of a single user. This service is not supported since V3.5.16.0.</description>
 */
#define SRV_USER_CHANGE_PASSWORD					0x07

/**
 * <category>Online services</category>
 * <service group="SG_CMPUSERMGR" id="SRV_UPDATE_CURRENT_USER_CREDENTIALS" name="Update current credentials">
 *	 <description>Online service to change the credentials of the current user. This service is allowed to all authenticated users. This 
 *				service will only affect the user that has logged into the current session. This service requires that the user authenticates
 *				by using the existing credentials.</description>
 *	<request>
 *		<tag id="TAG_USERMGR_CRYPT_TYPE" name="LoginProtocolType" cardinality="1" type="RTS_UI32" description="Authentication type. Must match to the type negotiated by SRV_DEV_SESSION_CREATE."/>
 *		<tag id="TAG_USERMGR_CRYPT_STEP" name="CurrentLoginProtocolStep" cardinality="0..1" type="RTS_UI32" description="Current step of login sequence."/>
 *		<complextag id="TAG_USERMGR_CREDENTIALS" name="Credentials" cardinality="0..1" description="Top level tag. Contains the user credentials.">
 *			<tag id="TAG_USERMGR_PASSWORD" name="Password" cardinality="0..1" type="Binary" description="Encrypted old password."/>
 *			<tag id="TAG_USERMGR_NEW_PASSWORD" name="New Password" cardinality="0..1" type="Binary" description="Encrypted new password."/>
 *		</complextag>
 *	</request>
 *	<response>
 *		<tag id="TAG_USERMGR_CRYPT_PUB_KEY" name="PLC Public Key" cardinality="0..1" type="char*" description="Public key used for password encryption. Only sent for authentication type USERMGR_CRYPT_ASYMMETRIC."></tag>
 *		<tag id="TAG_USERMGR_CRYPT_NONCE" name="Nonce" cardinality="0..1" type="char*" description="Nonce used for password encryption. Only sent for authentication type USERMGR_CRYPT_ASYMMETRIC."></tag>
 *		<tag id="TAG_USERMGR_CRYPT_NONCE_NEW" name="NonceNew" cardinality="0..1" type="char*" description="Nonce used for encryption of the new password. Only sent for authentication type USERMGR_CRYPT_ASYMMETRIC."></tag>
 *		<tag id="TAG_USERMGR_CRYPT_CHALLENGE" name="Challange" cardinality="0..1" type="char*" description="Challange used for password encryption. Only sent for authentication type USERMGR_CRYPT_XOR."></tag>
 *		<tag id="TAG_USERMGR_CRYPT_CHALLENGE_NEW" name="ChallangeNew" cardinality="0..1" type="char*" description="Challange used for encryption of the new password. Only sent for authentication type USERMGR_CRYPT_XOR."></tag>
 *		<tag id="TAG_ERROR" cardinality="1" result="true" name="Serviceresult" type="RTS_UI16">
 *			<value define="ERR_OK" description="Password changed successfully" />
 *			<value define="ERR_NOT_SUPPORTED" description="Changing the credentials is not possible." />
 *			<value define="ERR_OPERATION_DENIED" description="The database is not configurable." />
 *			<value define="ERR_FAILED" description="Password not changed successfully" />
 *		</result>
 *	</response>
 * </service>
 */
#define SRV_UPDATE_CURRENT_USER_CREDENTIALS			0x08

/**
 * <category>Online services</category>
 * <service group="SG_CMPUSERMGR" id="SRV_ADD_USER" name="Add User">
 *	<description>
 *		Online service to add a new user. 
 *
 *		To add a user two steps are required:
 *		1. Request the runtime to add a new user. This service returns the required values depending on the login protocol used by the new user.
 *		2. Request contains the actual user that should be added.
 *
 *		This service requires a modify right the user management. Additional the last authentication must not
 *		or than several minutes. It the last authentication is older than several minutes a OnlineAccessError with ERR_REAUTHENTICATE is returned.
 *	</description>
 *	<request>
 *		<tag id="TAG_USERMGR_CRYPT_TYPE" name="LoginProtocolType" cardinality="1" type="RTS_UI32" description="Authentication type. This defines the protocol type of the new user."/>
 *		<tag id="TAG_USERMGR_CRYPT_STEP" name="CurrentLoginProtocolStep" cardinality="0..1" type="RTS_UI32" description="Current step of login sequence."/>
 *		<tag id="TAG_USERMGR_USER" name="Username" cardinality="1" type="RTS_UTF8STRING" description="The name of the new user."/>
 *		<tag id="TAG_PROPERTY" name="User Property" cardinality="1" type="RTS_UI32" description="Properties of the new user."/>
 *		<tag id="TAG_USERMGR_CREDENTIALS" name="Credentials" cardinality="0..1" description="Top level tag. Contains the user credentials. This is transmitted in the second step.">
 *			<tag id="TAG_USERMGR_NEW_PASSWORD" name="Password" cardinality="0..1" type="Binary" description="The encrypted password of the new user."/>
 *		</tag>
 *	</request>
 *	<response>
 *		<tag id="TAG_USERMGR_CRYPT_PUB_KEY" name="PLC Public Key" cardinality="0..1" type="char*" description="Public key used for password encryption. Only sent for authentication type USERMGR_CRYPT_ASYMMETRIC."/>
 *		<tag id="TAG_USERMGR_CRYPT_NONCE_NEW" name="Nonce" cardinality="0..1" type="char*" description="Nonce used for password encryption. Only sent for authentication type USERMGR_CRYPT_ASYMMETRIC."/>
 *		<tag id="TAG_USERMGR_CRYPT_CHALLENGE_NEW" name="Nonce" cardinality="0..1" type="char*" description="challange used for password encryption. Only sent for authentication type USERMGR_CRYPT_XOR."/>
 *		<tag id="TAG_ERROR" cardinality="1" result="true" name="Serviceresult" type="RTS_UI16">
 *			<value define="ERR_OK" description="User added successfully" />
 *			<value define="ERR_DUPLICATE" description="The user is existing already. No changes made to the database." />
 *			<value define="ERR_NOT_SUPPORTED" description="The requested login protocol is not supported by this PLC." />
 *			<value define="ERR_OPERATION_DENIED" description="The database is not configurable." />
 *		</tag>
 *	</result>
 *	</response>
 * </service>
 */
#define SRV_ADD_USER 0x09

/**
 * <category>Online services</category>
 * <service group="SG_CMPUSERMGR" id="SRV_REMOVE_USER" name="Remove User">
 *	<description>
 *		Remove a user from the database. Additional all group assignments of the user will be deleted. 
 *
 *		This service requires a modify right the user management. Additional the last authentication must not
 *		or than several minutes. It the last authentication is older than several minutes a OnlineAccessError with ERR_REAUTHENTICATE is returned.
 *	</description>
 *	<request>
 *		<tag id="TAG_USERMGR_USER" name="Username" cardinality="1" type="RTS_UTF8STRING" description="The name of the user."/>
 *	</request>
 *	<response>
 *		<tag id="TAG_ERROR" cardinality="1" result="true" name="Serviceresult" type="RTS_UI16">
 *			<value define="ERR_OK" description="User removedsuccessfully" />
 *			<value define="ERR_NO_OBJECT" description="The user is not existing. No changes made to the database." />
 *			<value define="ERR_NOT_SUPPORTED" description="Deleting the last administrator user is not possible." />
 *			<value define="ERR_OPERATION_DENIED" description="The database is not configurable." />
 *		</tag>
 *	</result>
 *	</response>
 * </service>
 */
#define SRV_REMOVE_USER 0x0A


/**
 * <category>Online services</category>
 * <service group="SG_CMPUSERMGR" id="SRV_SET_USER_PROPERTY" name="Set User Property">
 *	<description>
 *		Set the properies of a user.
 *
 *		This service requires a modify right the user management. Additional the last authentication must not
 *		or than several minutes. It the last authentication is older than several minutes a OnlineAccessError with ERR_REAUTHENTICATE is returned.
 *	</description>
 *	<request>
 *		<tag id="TAG_USERMGR_USER" name="Username" cardinality="1" type="RTS_UTF8STRING" description="The name of the user."/>
 *		<tag id="TAG_PROPERTY" name="Properties" cardinality="1" type="RTS_UI32" description="The name of the user."/>
 *	</request>
 *	<response>
 *		<tag id="TAG_ERROR" cardinality="1" result="true" name="Serviceresult" type="RTS_UI16">
 *			<value define="ERR_OK" description="User removedsuccessfully" />
 *			<value define="ERR_NO_OBJECT" description="The user is not existing. No changes made to the database." />
 *			<value define="ERR_OPERATION_DENIED" description="The database is not configurable." />
 *		</tag>
 *	</result>
 *	</response>
 * </service>
 */
#define SRV_SET_USER_PROPERTY 0x0B

/**
 * <category>Online services</category>
 * <service group="SG_CMPUSERMGR" id="SRV_SET_CREDENTIALS_USER" name="Set User Credentials">
 *	<description>
 *		Update the credentials of an existing user.  
 *
 *		This service requires a modify right the user management. Additional the last authentication must not
 *		or than several minutes. It the last authentication is older than several minutes a OnlineAccessError with ERR_REAUTHENTICATE is returned.
 *	</description>
 *	<request>
 *		<tag id="TAG_USERMGR_CRYPT_TYPE" name="LoginProtocolType" cardinality="1" type="RTS_UI32" description="Authentication type. Must match to the type negotiated by SRV_DEV_SESSION_CREATE."/>
 *		<tag id="TAG_USERMGR_CRYPT_STEP" name="CurrentLoginProtocolStep" cardinality="0..1" type="RTS_UI32" description="Current step of login sequence."/>
 *		<complextag id="TAG_USERMGR_CREDENTIALS" name="Credentials" cardinality="1" description="Top level tag. Contains the user credentials.">
 *			<tag id="TAG_USERMGR_USER" name="Username" cardinality="1" type="RTS_UTF8STRING" description="The name of the user."/>
 *			<tag id="TAG_USERMGR_PASSWORD" name="Password" cardinality="0..1" type="Binary" description="Encrypted password."/>
 *		</complextag>
 *	</request>
 *	<response>
 *		<tag id="TAG_USERMGR_CRYPT_PUB_KEY" name="PLC Public Key" cardinality="0..1" type="RTS_CSTRING" description="Public key used for password encryption. Only sent for authentication type USERMGR_CRYPT_ASYMMETRIC."/>
 *		<tag id="TAG_USERMGR_CRYPT_NONCE_NEW" name="Nonce" cardinality="0..1" type="char*" description="Nonce used for password encryption. Only sent for authentication type USERMGR_CRYPT_ASYMMETRIC."/>
 *		<tag id="TAG_USERMGR_CRYPT_CHALLENGE_NEW" name="Nonce" cardinality="0..1" type="char*" description="challange used for password encryption. Only sent for authentication type USERMGR_CRYPT_XOR."/>
 *		<tag id="TAG_ERROR" cardinality="1" result="true" name="Serviceresult" type="RTS_UI16">
 *			<value define="ERR_OK" description="Credentials changed successfully" />
 *			<value define="ERR_NO_OBJECT" description="The user is not existing. No changes made to the database." />
 *			<value define="ERR_NOT_SUPPORTED" description="The requested login protocol is not supported by this PLC." />
 *			<value define="ERR_OPERATION_DENIED" description="The database is not configurable." />
 *		</result>
 *	</response>  
 * </service>
 */
#define SRV_SET_CREDENTIALS_USER 0x0C

/**
 * <category>Online services</category>
 * <service group="SG_CMPUSERMGR" id="SRV_ADD_GROUP" name="Add a user group">
 *	<description>
 *		Add a new user group to the runtime system. 
 *
 *		This service requires a modify right the user management. Additional the last authentication must not
 *		or than several minutes. It the last authentication is older than several minutes a OnlineAccessError with ERR_REAUTHENTICATE is returned.
 *	</description>
 *	<request>
 *		<tag id="TAG_NAME" name="Group Name" cardinality="1" type="RTS_UTF8STRING" description="The name of the new group."/>
 *		<tag id="TAG_GROUP_MEMBER" name="Group Name" cardinality="0..1" type="RTS_UTF8STRING" description="The name of other groups that should be added to this group. Tag can occur 0..n times"/>
 *		<tag id="TAG_USER_MEMBER" name="Group Name" cardinality="0..1" type="RTS_UTF8STRING" description="The name of users that should be added to this group. Tag can occur 0..n times."/>
 *	</request>
 *	<response>
 *		<tag id="TAG_ERROR" cardinality="1" result="true" name="Serviceresult" type="RTS_UI16">
 *			<value define="ERR_OK" description="Group added successfully" />
  *			<value define="ERR_DUPLICATE" description="A group with this name is already existing." />
 *			<value define="ERR_OPERATION_DENIED" description="The database is not configurable." />
 *		</result>
 *	</response>  
 * </service>
 */
#define SRV_ADD_GROUP 0x0D

/**
 * <category>Online services</category>
 * <service group="SG_CMPUSERMGR" id="SRV_REMOVE_GROUP" name="Remove a user group">
 *	<description>
 *		Remove an existing user group from the runtime system. Additional this group is removed from all other groups where it was a member.
 *		
 *		This service requires a modify right the user management. Additional the last authentication must not
 *		or than several minutes. It the last authentication is older than several minutes a OnlineAccessError with ERR_REAUTHENTICATE is returned.
 *	</description>
 *	<request>
 *		<tag id="TAG_NAME" name="Group Name" cardinality="1" type="RTS_UTF8STRING" description="The name of the new group."/>
 *	</request>
 *	<response>
 *		<tag id="TAG_ERROR" cardinality="1" result="true" name="Serviceresult" type="RTS_UI16">
 *			<value define="ERR_OK" description="The group was removed successfully" />
 *			<value define="ERR_NO_OBJECT" description="The Group is not existing. No changes made to the database." />
 *			<value define="ERR_NOT_SUPPORTED" description="The administrator group can not be delete." />
 *			<value define="ERR_OPERATION_DENIED" description="The database is not configurable." />
 *		</result>
 *	</response>  
 * </service>
 */
#define SRV_REMOVE_GROUP 0x0E


/**
 * <category>Online services</category>
 * <service group="SG_CMPUSERMGR" id="SRV_SET_GROUP_CONFIG" name="Configure a user group">
 *	<description>
 *		Update the configuration of an existing user group. This service contains all users and groups that are member of the configured group.
 *		In a first step the configuration of the group will be cleared. As a second step the new configuration is stored and activated.
 *
 *		This service requires a modify right the user management. Additional the last authentication must not
 *		or than several minutes. It the last authentication is older than several minutes a OnlineAccessError with ERR_REAUTHENTICATE is returned.
 *	</description>
 *	<request>
 *		<tag id="TAG_NAME" name="Group Name" cardinality="1" type="RTS_UTF8STRING" description="The name of the group to configure."/>
 *		<tag id="TAG_GROUP_MEMBER" name="Group Name" cardinality="0..1" type="RTS_UTF8STRING" description="The name of other groups that should be added to this group. Tag can occur 0..n times"/>
 *		<tag id="TAG_USER_MEMBER" name="Group Name" cardinality="0..1" type="RTS_UTF8STRING" description="The name of users that should be added to this group. Tag can occur 0..n times."/>
 *	</request>
 *	<response>
 *		<tag id="TAG_ERROR" cardinality="1" result="true" name="Serviceresult" type="RTS_UI16">
 *			<value define="ERR_OK" description="The group configuration has been successfully stored." />
 *			<value define="ERR_NO_OBJECT" description="The group is not existing. No changes made to the database." />
 *			<value define="ERR_OPERATION_DENIED" description="The database is not configurable." />
 *		</result>
 *	</response>  
 * </service>
 */
#define SRV_SET_GROUP_CONFIG 0x0F

/**
 * <category>Online services</category>
 * <service group="SG_CMPUSERMGR" id="SRV_EXPORT_USER_MGMT" name="Export the user management.">
 *	<description>
 *		The service exports the user management into a backup file which can be uploaded by the CODESYS IDE.
 *		The backup contains the corresponding user database which can be restored to PLCs that contain the same
 *		backend components.
 *
 *		To complete the service call two messages two messages in each direction are neccesarry. In the first step
 *		the needed information to transmit the password which is used to secure the backup are collected from the device
 *		The second step transmit the encrypted password and returns the path of the backup file.
 *
 *		This service requires read rights on the User Management object.
 *	</description>
 *	<request>
 *		<tag id="TAG_USERMGR_CRYPT_TYPE" name="LoginProtocolType" cardinality="1" type="RTS_UI32" description="Authentication type. Must match to the type negotiated by SRV_DEV_SESSION_CREATE."/>
 *		<tag id="TAG_USERMGR_CRYPT_STEP" name="CurrentLoginProtocolStep" cardinality="0..1" type="RTS_UI32" description="Current step of login sequence."/>
 *		<complextag id="TAG_USERMGR_CREDENTIALS" name="Credentials" cardinality="1" description="Top level tag. Contains the password used to encrypt the backup file.">
 *			<tag id="TAG_USERMGR_PASSWORD" name="Password" cardinality="0..1" type="Binary" description="Encrypted password."/>
 *		</complextag>
 *	</request>
 *	<response>
 *		<tag id="TAG_USERMGR_CRYPT_PUB_KEY" name="PLC Public Key" cardinality="0..1" type="RTS_CSTRING" description="Public key used for password encryption. Only sent for authentication type USERMGR_CRYPT_ASYMMETRIC."/>
 *		<tag id="TAG_USERMGR_CRYPT_NONCE" name="Nonce" cardinality="0..1" type="char*" description="Nonce used for password encryption. Only sent for authentication type USERMGR_CRYPT_ASYMMETRIC."/>
 *		<tag id="TAG_USERMGR_CRYPT_CHALLENGE" name="Nonce" cardinality="0..1" type="char*" description="challange used for password encryption. Only sent for authentication type USERMGR_CRYPT_XOR."/>
 *		<tag id="TAG_USERMGR_BACKUP_FILE" cardinality="1" name="Backfile path" type="RTS_CSTRING" description="Path of the backup file on the PLC. Can be used by file transfer services to upload the file.">
 *		<tag id="TAG_ERROR" cardinality="1" result="true" name="Serviceresult" type="RTS_UI16">
 *			<value define="ERR_OK" description="The group configuration has been successfully stored." />
 *			<value define="ERR_PENDING" description="The password exchange has not finished yet." />
 *			<value define="ERR_OPERATION_DENIED" description="The database could not be exported." />
 *		</result>
 *	</response>  
 * </service>
 */
#define SRV_EXPORT_USER_MGMT 0x10

/**
 * <category>Online services</category>
 * <service group="SG_CMPUSERMGR" id="SRV_IMPORT_USER_MGMT" name="Import the user management.">
 *	<description>
 *		The service imports the user management from a backup file which can be downloaded by the CODESYS IDE.
 *		The backup contains the corresponding user database which can be restored to PLCs that contain the same
 *		backend components.
 *
 *		This service requires a modify right the user management. Additional the last authentication must not
 *		or than several minutes. It the last authentication is older than several minutes a OnlineAccessError with ERR_REAUTHENTICATE is returned.
 *	</description>
 *	<request>
 *		<tag id="TAG_USERMGR_CRYPT_TYPE" name="LoginProtocolType" cardinality="1" type="RTS_UI32" description="Authentication type. Must match to the type negotiated by SRV_DEV_SESSION_CREATE."/>
 *		<tag id="TAG_USERMGR_CRYPT_STEP" name="CurrentLoginProtocolStep" cardinality="0..1" type="RTS_UI32" description="Current step of login sequence."/>
 *		<complextag id="TAG_USERMGR_CREDENTIALS" name="Credentials" cardinality="1" description="Top level tag. Contains the password used to decrypt the backup file.">
 *			<tag id="TAG_USERMGR_PASSWORD" name="Password" cardinality="0..1" type="Binary" description="Encrypted password."/>
 *		</complextag>
 *		<tag id="TAG_USERMGR_BACKUP_FILE" cardinality="1" name="Backfile path" type="RTS_CSTRING" description="Path on the PLC to backup file to restore.">
 *	</request>
 *	<response>
 *		<tag id="TAG_USERMGR_CRYPT_PUB_KEY" name="PLC Public Key" cardinality="0..1" type="RTS_CSTRING" description="Public key used for password encryption. Only sent for authentication type USERMGR_CRYPT_ASYMMETRIC."/>
 *		<tag id="TAG_USERMGR_CRYPT_NONCE" name="Nonce" cardinality="0..1" type="char*" description="Nonce used for password encryption. Only sent for authentication type USERMGR_CRYPT_ASYMMETRIC."/>
 *		<tag id="TAG_USERMGR_CRYPT_CHALLENGE" name="Nonce" cardinality="0..1" type="char*" description="challange used for password encryption. Only sent for authentication type USERMGR_CRYPT_XOR."/>
 *		<tag id="TAG_ERROR" cardinality="1" result="true" name="Serviceresult" type="RTS_UI16">
 *			<value define="ERR_OK" description="The group configuration has been successfully stored." />
 *			<value define="ERR_OPERATION_DENIED" description="The database could not be imported." />
 *			<value define="ERR_PARAMETER" description="The file to be imported is not valid" />
 *			<value define="ERR_SECURITY_CHECKS_FAILED" description="The password of the import file was not valid." />
 *		</result>
 *	</response>  
 * </service>
 */
#define SRV_IMPORT_USER_MGMT 0x11


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
 * <category>Online tags</category>
 * <description>Tags for login service </description>
 */
#define TAG_USERMGR_CRYPT_TYPE						0x22 
#define TAG_USERMGR_CRYPT_CHALLENGE					0x23 
/* #define TAG_DEV_REPLY_SETTINGS					0x24  not used here, but reserve value --> defined in CmpDeviceItf */ 
#define TAG_USERMGR_CRYPT_STEP						0x25 
#define TAG_USERMGR_CRYPT_NONCE						0x26 
#define TAG_USERMGR_CRYPT_PUB_KEY					0x27 
#define TAG_USERMGR_CRYPT_NONCE_NEW					0x28
#define TAG_USERMGR_CRYPT_CHALLENGE_NEW					0x29 
#define TAG_USRMGR_REPLY_LOGIN						TAG_DEV_REPLY_LOGIN /* 0x82*/
#define TAG_USRMGR_REPLY_LOGIN_RESULT				TAG_DEV_REPLY_LOGIN_RESULT /* 0x20 */

#define TAG_USERMGR_CREDENTIALS						0x81
#define TAG_USERMGR_USER							0x10
#define TAG_USERMGR_PASSWORD						0x11
#define TAG_USERMGR_NEW_PASSWORD					0x12
#define TAG_USERMGR_BACKUP_FILE						0x13

/**
 * <category>Crypt types</category>
 * <description>Crypt types to cipher the password or alternative authentication algorithms. Values can be used as bit mask.</description>
 * <element name="USERMGR_CRYPT_INVALID" type="IN">Invalid of unknown crypt type</element>
 * <element name="USERMGR_CRYPT_XOR" type="IN">Disguise password with an XOR algorithm</element>
 * <element name="USERMGR_CRYPT_ASYMMETRIC" type="IN">Transport password with public key encryption</element>
 */
#define USERMGR_CRYPT_INVALID				0x00000000
#define USERMGR_CRYPT_XOR					0x00000001
#define USERMGR_CRYPT_ASYMMETRIC			0x00000002

/**
 * <category>Static defines</category>
 * <description>Predefined objects in the runtime</description>
 */
#define USERDB_OBJECT_USERMGMT		"Device.UserManagement"

/**
 * <category>Old database announcements</category>
 * <description>A database announces an old database to the user management</description>
 * <element name="USERMGR_OLDDATABASE_ANNOUNCE" type="IN">An old database is found and converting is requested. This may be denied.</element>
 * <element name="USERMGR_OLDDATABASE_FINISH" type="IN">An old database is converted and adjustment may be processed now</element>
 */
#define USERMGR_OLDDATABASE_ANNOUNCE		0x00000001
#define USERMGR_OLDDATABASE_FINISH			0x00000002


/**
 * <category>Event parameter</category>
 * <element name="bUserManagementChanged" type="IN">TRUE: User management database changed; FALSE: Not changed</element>
 * <element name="bRightsManagementChanged" type="IN">TRUE: Rights management database changed; FALSE: Not changed</element>
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
 * <description>Event is sent every time the user management database or the user-rights database was changed</description>
 * <param name="pEventParam" type="IN">EVTPARAM_CmpUserMgrDatabaseChanged</param>
 */
#define EVT_UserMgrDatabaseChanged		MAKE_EVENTID(EVTCLASS_INFO, 1)

/**
 * <category>Event parameter</category>
 * <element name="hUser" type="IN">Handle of a temprary administrator user, only valid with this event</element>
 * <element name="Result" type="OUT">Result of the adjustment</element>
 */
typedef struct
{
	RTS_HANDLE hUser;
	RTS_RESULT Result;
} EVTPARAM_CmpUserMgrAdjustDatabase;

#define EVTPARAMID_CmpUserMgrAdjustDatabase		0x0002
#define EVTVERSION_CmpUserMgrAdjustDatabase		0x0001

/**
 * <category>Events</category>
 * <description>
 * Event is sent when a default user management is to be created, especially with user groups and object rights.
 * The Result is preset with ERR_NOTIMPLEMENTED and in this standard case the user management creates the default database with user groups and object rights.
 * A temporary administrator user handle is provided for operations that require this.
 * With the Result set to ERR_OK a user management was successfully created within this event, or to any error if failed. 
 * </description>
 * <param name="pEventParam" type="IN">EVTPARAM_CmpUserMgrAdjustDatabase</param>
 */
#define EVT_UserMgrCreateDefaultDatabase		MAKE_EVENTID(EVTCLASS_INFO, 2)

/**
 * <category>Events</category>
 * <description>
 * Event is sent when an old user database is to be converted.
 * The Result is preset with ERR_OK and in this standard case the user management is converted to the new format.
 * With the Result set to ERR_OPERATION_DENIED this conversion is denied, that is as if there is no user database.
 * hUser is not used in this case and preset with RTS_INVALID_HANDLE.
 * NOTE: This event must be registered in CH_INIT2 because the database is loaded in CH_PRE_INIT3 already.
 * </description>
 * <param name="pEventParam" type="IN">EVTPARAM_CmpUserMgrAdjustDatabase</param>
 */
#define EVT_UserMgrConvertOldDatabaseAnnounce	MAKE_EVENTID(EVTCLASS_INFO, 3)

/**
 * <category>Events</category>
 * <description>
 * Event is sent when an old user database was successfully converted to the new format. The user database can be adjusted during this event.
 * A temporary administrator user handle is provided for operations that require this.
 * The Result is preset with ERR_OK.
 * NOTE: This event is not send when EVT_UserMgrConvertOldDatabaseAnnounce is denied.
 * NOTE: This event must be registered in CH_INIT2 because loading of the database is finished in CH_INIT3 already.
 * </description>
 * <param name="pEventParam" type="IN">EVTPARAM_CmpUserMgrAdjustDatabase</param>
 */
#define EVT_UserMgrConvertOldDatabaseFinish		MAKE_EVENTID(EVTCLASS_INFO, 4)

/**
 * <category>Static defines</category>
 * <description>
 *  Defines the update interval in ms for the key pair used by the asymmetric authentication algorithm. Whenever
 *  this time elapses since the startup of the device or the last key generation, the CmpUserMgr generates
 *  a new pair of keys in the background.
 * </description>
 */
#ifndef USERMGR_ASYMMETRIC_KEY_UPDATE_INTERVAL
	#define USERMGR_ASYMMETRIC_KEY_UPDATE_INTERVAL			(24*60*60*1000)	/* 24h */		
#endif

/**
 * <category>Settings</category>
 * <type>INT</type>
 * <description>
 *  This setting defines the startup behavior of the CmpUserMgr regarding key generation:
 *  The CmpUserMgr provides a key pair for the asymmetric authentication algorithm. Depending on the CPU performance
 *  of the device, the generation of this key pair may take about 2..100 seconds. As long as these keys are not available, 
 *  no client (e. g. the CODESYS Development system) is allowed to login. 
 *  Defined values (all other values are reserved for future use): 
 *  0:  The key pair is never stored and must be newly generated on each start of the runtime system. The keys are only
 *      kept in RAM.
 *  1:  Fast startup: When ever a new key pair is generated, these are stored. During startup the stored keys are loaded 
 *      to let the runtime system communicate immediately. If no keys exist (initial startup), then logins are blocked
 *      until the keys are available.   
 *  Independently of the settings the keys are updated regularly in the background. 
 * </description>
 */
#define USERMGRKEY_INT_FAST_KEY_STARTUP						"FastKeyStartup"
#ifndef USERMGRKEY_INT_FAST_KEY_STARTUP_DEFAULT
	#define USERMGRKEY_INT_FAST_KEY_STARTUP_DEFAULT			1
#endif

/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>
 *  Key identifier for asymmetric authentication. Used to handle stored keys for the asymmetric authentication algorithm.
 *  This setting is managed by the CmpUserMgr and must not be set by hand.
 * </description>
 */
#define USERMGR_KEY_STRING_ASYMMETRIC_AUTH_KEY				"AsymmetricAuthKey"

/**
 * <category>SecuritySettings</category>
 * <description>Security setting to select the authentication algorithm. Can be selected in CmpSecurityManager.
 *	NOTE:
 *		Security modes must be ordered in an descending sorting, i.e. the setting with the highest security level is found at the beginning of the list!
 * </description>
 */	
#define CMPUSERMGR_KEY_STRING_LOGIN_AUTH_TYPE			CMPSETTINGS_CATEGORY_SECURITY ".UserLogin_AuthenticationType"
#define CMPUSERMGR_KEY_STRING_LOGIN_AUTH_TYPE_DESC		"Authentication algorithm"

#define CMPUSERMGR_VALUE_LOGIN_AUTH_TYPE_ASYMM			"ONLY_ASYMMETRIC"
#define CMPUSERMGR_VALUE_LOGIN_AUTH_TYPE_AUTO			"AUTO_NEGOTIATE"
#define CMPUSERMGR_VALUE_LOGIN_AUTH_TYPE_LEGACY			"ONLY_LEGACY"

#ifndef CMPUSERMGR_VALUE_LOGIN_AUTH_TYPE_DEFAULT
	#define CMPUSERMGR_VALUE_LOGIN_AUTH_TYPE_DEFAULT	CMPUSERMGR_VALUE_LOGIN_AUTH_TYPE_AUTO
#endif


/**
 * <category>SecuritySettings</category>
 * <description>Security setting to select the authentication algorithm.
 * </description>
 */
typedef enum
{
	UserMgrLoginAuthType_Asymmetric,
	UserMgrLoginAuthType_Auto,
	UserMgrLoginAuthType_Legacy
} USERMGR_LOGIN_AUTH_TYPE;

#define CMPUSERMGR_VALUE_LOGIN_AUTH_TYPE_LIST		{ \
														{(RTS_I32)UserMgrLoginAuthType_Asymmetric, CMPSECMAN_SFLAGS_NONE, CMPUSERMGR_VALUE_LOGIN_AUTH_TYPE_ASYMM, "Password, asymmetric encryption"},\
														{(RTS_I32)UserMgrLoginAuthType_Auto, CMPSECMAN_SFLAGS_NONE, CMPUSERMGR_VALUE_LOGIN_AUTH_TYPE_AUTO, "Negotiate authentication algorithm"},\
														{(RTS_I32)UserMgrLoginAuthType_Legacy, CMPSECMAN_SFLAGS_NONE, CMPUSERMGR_VALUE_LOGIN_AUTH_TYPE_LEGACY, "Password, legacy encryption"},\
													}


/**
 * <category>SecuritySettings</category>
 * <description>Editable security setting: RSA key length for asymmetric authentication algorithm. 
 *  Minimal allowed value: MIN(CMPUSERMGR_VALUE_LOGIN_RSALEN_MIN, CMPSETTINGS_CATEGORY_SECURITY ".RSAMinKeyLen")
 * </description>
 */
#define CMPUSERMGR_KEY_INT_LOGIN_RSALEN				CMPSETTINGS_CATEGORY_SECURITY ".UserLogin_RSAKeyLen"
#define CMPUSERMGR_KEY_INT_LOGIN_RSALEN_DESC		"RSA key length for asymmetric authentication algorithm"

#ifndef CMPUSERMGR_VALUE_LOGIN_RSALEN_DEFAULT
	#define CMPUSERMGR_VALUE_LOGIN_RSALEN_DEFAULT	2048
#endif

#define CMPUSERMGR_VALUE_LOGIN_RSALEN_MIN			1024

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
 * <category>SecuritySettings</category>
 * <description>Editable security setting: Maximum time in [s} between subsequent services calls to edit the user management. If the time is expired the user has to authenticate again.
 * </description>
 */
#define CMPUSERMGR_KEY_INT_EDITTIMEOUT				CMPSETTINGS_CATEGORY_SECURITY ".UserMgrEditTimeout"
#define CMPUSERMGR_KEY_INT_EDITTIMEOUT_DESC			"Maximum time in [s} between subsequent services calls to edit the user management. If the time is expired the user has to authenticate again."

#ifndef CMPUSERMGR_VALUE_EDITTIMEOUT_DEFAULT
	#define CMPUSERMGR_VALUE_EDITTIMEOUT_DEFAULT	300
#endif

/**
 * <category>Predefined user groups</category>
 * <description>Predefined user groups</description>
 * <element name="USERDB_GROUP_ADMINISTRATOR" type="IN">Administrator group. A member of this groups has all access rights on all objects!</element>
 * <element name="USERDB_GROUP_DEVELOPER" type="IN">Developer group. A member of this groups has all access to the IEC applications an all related stuff.</element>
 * <element name="USERDB_GROUP_SERVICE" type="IN">Service group. A member of this groups has all access to object for maintenance and service operations.</element>
 * <element name="USERDB_GROUP_WATCH" type="IN">Watch group. A member of this groups has read-only access to the objects.</element>
 * <element name="USERDB_GROUP_EVERYONE" type="IN">Everyone group. This group is reserved for special further purposes and not be added to the user management.</element>
 * </element>
 */
#ifndef USERDB_GROUP_ADMINISTRATOR
	#define USERDB_GROUP_ADMINISTRATOR								"Administrator"
#endif
#ifndef USERDB_GROUP_DEVELOPER
	#define USERDB_GROUP_DEVELOPER									"Developer"
#endif
#ifndef USERDB_GROUP_SERVICE
	#define USERDB_GROUP_SERVICE									"Service"
#endif
#ifndef USERDB_GROUP_WATCH
	#define USERDB_GROUP_WATCH										"Watch"
#endif
#ifndef USERDB_GROUP_EVERYONE
	#define USERDB_GROUP_EVERYONE									"Everyone"
#endif

/**
 * <category>User rights</category>
 * <description>Defined rights that can fully control the access to an object</description>
 * <element name="USERDB_RIGHT_NONE" type="IN">Access denied</element>
 * <element name="USERDB_RIGHT_VIEW" type="IN">Only view rights on the object. Object cannot be modified in any way!</element>
 * <element name="USERDB_RIGHT_MODIFY" type="IN">Object can be viewed and modified</element>
 * <element name="USERDB_RIGHT_EXECUTE" type="IN">Object can be executed</element>
 * <element name="USERDB_RIGHT_ADD_REMOVE" type="IN">It is allowed to add and remove sub objects</element>
 * <element name="USERDB_RIGHT_OEM" type="IN">The upper 8 bits of the access rights are reserved for OEM specific access rights</element>
 * <element name="USERDB_RIGHT_ALL" type="IN">All rights allowed on the object</element>
 */
#define USERDB_RIGHT_NONE					UINT32_C(0x00000000)
#define USERDB_RIGHT_VIEW					UINT32_C(0x00000001)
#define USERDB_RIGHT_MODIFY					UINT32_C(0x00000002)
#define USERDB_RIGHT_EXECUTE				UINT32_C(0x00000004)
#define USERDB_RIGHT_ADD_REMOVE				UINT32_C(0x00000008)
#define USERDB_RIGHT_OEM					UINT32_C(0xFF000000)
#define USERDB_RIGHT_ALL					UINT32_C(0xFFFFFFFF)

/**
 * <category>Properties</category>
 * <description>These defines are used as properties of the UserDB Objects. Use as bit-mask.</description>
 * <element name="USERDB_HIDE_OBJECT">Hides the object from being uploaded to the IDE.</element>
 * <element name="USERDB_EXPLICIT_RIGHTS">Evaluates only the explicit configured rights on that object. Don't check the parent 
 *	objects if no rights are configured. If no explicit rights are found access is denied.</element>
 */
#define USERDB_HIDE_OBJECT             1
#define USERDB_EXPLICIT_RIGHTS         2

/**
 * <category>User and group properites</category>
 * <description>Properties for a user.</description>
 * <element name="USERMGR_ONLINE_PROP_PASSWORD_UP_TO_DATE" type="IN">The users password is up to date and must not be changed.</element>
 * <element name="USERMGR_ONLINE_PROP_PASSWORD_EDITABLE" type="IN">The user is allowed to change the password.</element>
 * <element name="USERMGR_ONLINE_PROP_ALL" type="IN">All properities set.</element>
 */
#define USERMGR_ONLINE_PROP_PASSWORD_UP_TO_DATE	UINT32_C(0x00001000)
#define USERMGR_ONLINE_PROP_PASSWORD_EDITABLE	UINT32_C(0x00002000)
#define USERMGR_ONLINE_PROP_ALL					UINT32_C(0xFFFFFF7F)

#define USERMGR_USER_PROP_PASSWORD_EXPIRED		UINT32_C(0x00001000)
#define USERMGR_USER_PROP_ALLOW_CHANGE_PASSWORD	UINT32_C(0x00002000)
#define USERMGR_USER_PROP_DEFAULT USERMGR_USER_PROP_ALLOW_CHANGE_PASSWORD | USERMGR_USER_PROP_PASSWORD_EXPIRED


/**
 * <category>Login protocol types</category>
 * <description>
 *  There are different protocols that can be used to authenticae a user. The following list contains the supported 
 *	credential types of the runtime system. It is not required that a runtime implements all available type. The available
 *	types depend on the actual implementaion of different user authenticators.
 *	<ul>
 *		<li>UserMgrCredentials_Type_Password: This login protocol transmitts the users password in plaintext over a TLS authenticated connection. This method is suitable if the credentials have
 *			to be forwarded to other databases such as LDAP, OS, or an OEM user database.</li>
 *		<li>UserMgrCredentials_Type_AUCPACE: This login protocol checks the credentials without transmitting the users password to the PLC. 
 *			It is suitable for embedded devices that have the CmpCryptoEmbedded available. A secure session is generated during login which can be used to protect further data within the session.</li>
 *		<li>UserMgrCredentials_Type_X509: This login protocol uses client certificates to authenticate the user. 
 *			A Nonce is digitally signed by the client with the users private key. Only suitable for lager systems with an implementation of CmpCrypto and CmpX509Cert</li>
 *	</ul>
 * </description>
 */
#define UserMgrCredentials_Type_Password	UINT32_C(1)

typedef struct
{
	char *pszPassword;
} UserMgrCredentials_Password;

#if 0
typedef struct
{
	RtsByteString 	Nonce;
	RtsByteString 	SignedData;
	RTS_SIZE		noneOffset;
	RTS_HANDLE		hClientCertificate;
	RtsByteString 	ClientSignature;	
} CmpUserMgr_X509_Parameter;
#endif

typedef union
{
	UserMgrCredentials_Password pwd;
}UserMgrCredentials_Store;

typedef struct
{
	RTS_UI32 credentialsType;
	UserMgrCredentials_Store credential;
}UserMgrCredentials;

#define USERMGR_DATAEXCHANGE_FOLDER "$UserMgr$"
#define USERMGR_USERGROUPS_EXCHANGE_FILE USERMGR_DATAEXCHANGE_FOLDER "/Users_Groups_export.dum2"
#define USERMGR_USERGROUPS_BACKUP_FILE USERMGR_DATAEXCHANGE_FOLDER "/Backup.dum2"


#ifdef __cplusplus
extern "C" {
#endif



/**
 * <description>Register a user database to the user manager. Only one database can be registered. If not database is registred then 
 * the user management will be deactivated if allowed.</description>
 * <param name="hDatabase" type="IN">Handle to the database.</param>
 * <param name="type" type="IN">The credentials type that the database supports.</param>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`UserMgrRegisterUserDB',`(RTS_HANDLE hDatabase, RTS_UI32 type)')
/**
 * <description>Unregister a user database from the user manager.</description>
 * <param name="hDatabase" type="IN">Handle to the database.</param>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`UserMgrUnregisterUserDB',`(RTS_HANDLE hDatabase)')

/**
 * <description>Register a configuration database. If this interface is registered the online services can change the user database.</description>
 * <param name="hDatabase" type="IN">Handle to the database.</param>
 * <param name="type" type="IN">The credentials type that the database supports.</param>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`UserMgrRegisterUserDBConfig',`(RTS_HANDLE hDatabase, RTS_UI32 type)')

/**
 * <description>Unregister a configuration database.</description>
 * <param name="hDatabase" type="IN">Handle to the database.</param>
 * <param name="type" type="IN">The credentials type that the database supports.</param>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`UserMgrUnregisterUserDBConfig',`(RTS_HANDLE hDatabase)')

/**
 * <description>Register user group database.</description>
 * <param name="hDatabase" type="IN">Handle to the database.</param>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`UserMgrRegisterUserGroupsDB',`(RTS_HANDLE hDatabase)')

/**
 * <description>Unregister user group database.</description>
 * <param name="hDatabase" type="IN">Handle to the database.</param>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`UserMgrUnregisterUserGroupsDB',`(RTS_HANDLE hDatabase)')

/**
 * <description>Register user group configuration database.</description>
 * <param name="hDatabase" type="IN">Handle to the database.</param>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`UserMgrRegisterUserGroupsDBConfig',`(RTS_HANDLE hDatabase)')

/**
 * <description>Unregister user group configuration database.</description>
 * <param name="hDatabase" type="IN">Handle to the database.</param>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`UserMgrUnregisterUserGroupsDBConfig',`(RTS_HANDLE hDatabase)')

/**
 * <description>Register user objects database.</description>
 * <param name="hDatabase" type="IN">Handle to the database.</param>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`UserMgrRegisterUserObjectsDB',`(RTS_HANDLE hDatabase)')

/**
 * <description>Unregister user objects database.</description>
 * <param name="hDatabase" type="IN">Handle to the database.</param>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`UserMgrUnregisterUserObjectsDB',`(RTS_HANDLE hDatabase)')

/**
 * <description>Register user objects database configuration.</description>
 * <param name="hDatabase" type="IN">Handle to the database.</param>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`UserMgrRegisterUserObjectsDBConfig',`(RTS_HANDLE hDatabase)')

/**
 * <description>Unregister user objects database configuration.</description>
 * <param name="hDatabase" type="IN">Handle to the database.</param>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`UserMgrUnregisterUserObjectsDBConfig',`(RTS_HANDLE hDatabase)')

/**
 * <description>Selects the authentication type out of the client proposals. Only to be called by CmpDevice.</description>
 * <param name="ui32ClientFlags" type="IN">Flags describing the clients behavior during login</param>
 * <param name="pui32AuthType" type="INOUT">In: Client proposed authentication type. Out: Selected authentication type.</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Login was successful</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">pui32AuthType is NULL</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_TYPE_MISMATCH">Non of the proposed authentication types matches the runtime requirements.</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrSelectAuthType', `(RTS_UI32 ui32ClientFlags, RTS_UI32 *pui32AuthType)')

/**
 * <description>Handles a UserMgr login request received by CmpDevice. Only to be called by CmpDevice.</description>
 * <param name="SessionId" type="IN">SessionId of the device's online connection</param>
 * <param name="SessionAuthType" type="IN">Authentication algorithm used for the online session</param>
 * <param name="SessionFlags" type="IN">Flags describing the online session</param>
 * <param name="pWriter" type="IN">Pointer the writer stream</param>
 * <param name="pReader" type="IN">Pointer the reader stream</param>
 * <param name="phUser" type="OUT">Pointer to return the user handle</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Login was successful</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PENDING">Login is in progress, further online services needed.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">At least one of the parameters is NULL</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_ACCESS_RIGHTS">Login was denied e. g. because of wrong user/password combination.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_TYPE_MISMATCH">Authentication type does not match the negotiated type</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrHandleLoginService', `(RTS_UI32 SessionId, RTS_UI32 SessionAuthType, RTS_UI32 SessionFlags, BINTAGWRITER *pWriter, BINTAGREADER *pReader, RTS_HANDLE *phUser)')

DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrIsServiceAllowed', `(RTS_UI32 channelID, HEADER_TAG_EXT *pHeader, PROTOCOL_DATA_UNIT *pPduReply)')

/**
 * <description>Checks if the user management is active.</description>
 * <result>TRUE: The user management is activated or enforced. FALSE: The user management is not activated.</result>
 */
DEF_ITF_API(`RTS_BOOL',`CDECL',`UserMgrIsActive',`(void)')

/**
 * <description>Logs user in to the runtime system using an active user management.</description>
 * <param name="pszUser" type="IN">Name of the user</param>
 * <param name="pszPassword" type="IN">Password (plain text)</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">User/password combination is valid</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_ACTIVATE_USERMGMT">The login was successful. But the user management is enforced and not active. Activate the user management.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_CHANGE_PASSWORD">The login was successful. But the user must change his password.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_USERMGMT">Login was not successful. The user management is not activated. Use empty user and password to login.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_ACCESS_RIGHTS">The login was not successful, because of another reason.</errorcode>
 * <result>Handle to the user or RTS_INVALID_HANDLE if not available</result>
 */
DEF_ITF_API(`RTS_HANDLE', `CDECL', `UserMgrLogin', `(char *pszUser, char *pszPassword, RTS_RESULT *pResult)')

/**
 * <description>Logout specified by the user</description>
 * <param name="hUser" type="IN">Handle to the user</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">User is available and logout succeeded</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">If user is not available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_INVALID_HANDLE">hUser is invalid or unknown</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrLogout', `(RTS_HANDLE hUser)')

/**
 * <description>Re-logs user in to the runtime system using an active user management. The user name must match to the user name used for the initial login of the user.</description>
 * <param name="hUser" type="IN">Handle to the user</param>
 * <param name="pszUser" type="IN">Name of the user</param>
 * <param name="pszPassword" type="IN">Password (plain text)</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">User/password combination is valid</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">pszUser is NULL</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">The user management is not initialized or it is not loaded yet</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_RELOGIN">hUser known, but not logged in</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Password is wrong.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_USER_MISMATCH">User name does not match</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_INVALID_HANDLE">hUser is invalid or unknown</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrRelogin', `(RTS_HANDLE hUser, char *pszUser, char *pszPassword)')

/**
 * <description>Checks if the a user is a member of the given group</description>
 * <param name="pszGroup" type="IN">Group name</param>
 * <param name="hUser" type="IN">Handle to the user</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">The user is a member of the given group</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">The user is not a member of the given group</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_INVALID_HANDLE">hUser is invalid or unknown</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrIsGroupMember', `(char *pszGroup, RTS_HANDLE hUser)')

/**
 * <description>Checks if the a user an administrator.</description>
 * <param name="hUser" type="IN">Handle to the user</param>
 * <result>TRUE: The user is an administrator, FALSE: The user is not an administrator.</result>
 */
DEF_ITF_API(`RTS_BOOL', `CDECL', `UserMgrIsAdministrator', `(RTS_HANDLE hUser)')

/**
 * <description>Checks user access rights on the specified object (authorization)!</description>
 * <param name="pszObject" type="IN">Full object name (see object tree)</param>
 * <param name="ulSessionId" type="IN">SessionID of the device online connection (see CmpDeviceItf.h)</param>
 * <param name="ulRequestedRights" type="IN">Requested rights on that object</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">If user has the requested rights on the object or if no user management is configured</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">If SessionID or user is not available or the object does not exist</errorcode>
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
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">If SessionID or user is not available or the object does not exist</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">If something failed retrieving the access rights</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_ACCESS_RIGHTS">Explicitly denied rights</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_INVALID_HANDLE">Related user handle of the session is invalid or unknown</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrGetAccessRights', `(char *pszObject, RTS_UI32 ulSessionId, RTS_UI32 *pulRights, RTS_UI32 *pulDeniedRights)')

/**
 * <description>Checks user access rights on the specified object (authorization)!</description>
 * <param name="pszObject" type="IN">Full object name (see object tree)</param>
 * <param name="hUser" type="IN">Handle to the user</param>
 * <param name="ulRequestedRights" type="IN">Requested rights on that object</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">If user has the requested rights on the object or if no user management is configured</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">If user is not available or the object does not exist</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">If something failed retrieving the access rights</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_ACCESS_RIGHTS">Explicitly denied rights</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_INVALID_HANDLE">hUser is invalid or unknown</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrHasUserAccessRights', `(char *pszObject, RTS_HANDLE hUser, RTS_UI32 ulRequestedRights)')

/**
 * <description>Gets user access rights on the specified object (authorization)!</description>
 * <param name="pszObject" type="IN">Full object name (see object tree)</param>
 * <param name="hUser" type="IN">Handle to the user</param>
 * <param name="pulRights" type="IN">Pointer to get admitted rights</param>
 * <param name="pulDeniedRights" type="IN">Pointer to get denied rights.
 *	 NOTE:
 *	 If the required right is denied _and_ admitted on the specified object, the denied right is more significant and so the access must be denied !!</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">If user has the requested rights on the object or if no user management is configured</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">If user is not available or the object does not exist</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">If something failed retrieving the access rights</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_ACCESS_RIGHTS">Explicitly denied rights</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_INVALID_HANDLE">hUser is invalid or unknown</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrGetUserAccessRights', `(char *pszObject, RTS_HANDLE hUser, RTS_UI32 *pulRights, RTS_UI32 *pulDeniedRights)')

/**
 * <description>Adds an value to an logged in user. This can be used as some kind of cache that exists as long as the user is logged in.</description>
 * <param name="hUser" type="IN">Handle to the user.</param>
 * <param name="key" type="IN">Access key for the cache value. This has to be used at UserMgrGetInfoOfUser to access the value.</param>
 * <param name="pValue" type="IN">Value to cache at the user.</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Value cached</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_DUPLICATE">The same key has been used already</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">The caching failed</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrAddInfoToUser', `(RTS_HANDLE hUser, RTS_SIZE key, RTS_TYPEDVALUE *pValue)')

/**
 * <description>Removes a specific cache value from an user.</description>
 * <param name="hUser" type="IN">Handle to the user.</param>
 * <param name="key" type="IN">Key of the cache value.</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Removing cache value successful</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">No cache value with this key available.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Removing cache value failed</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrRemoveInfoFromUser', `(RTS_HANDLE hUser, RTS_SIZE key)')

/**
 * <description>Removes a specific cache value from all logged in users.</description>
 * <param name="key" type="IN">Key of the cache value.</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Removing cache value successful</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Removing cache value failed</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrRemoveInfoFromAllUsers', `(RTS_SIZE key)')

/**
 * <description>Retrieves the value cached using UserMgrAddInfoToUser.</description>
 * <param name="hUser" type="IN">Handle to the user.</param>
 * <param name="key" type="IN">Key of the cache value.</param>
 * <param name="pValue" type="IN">Value to cache at the user.</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Retrieving cache value successful. Value copied to pValue.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Some parameter is invalid</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">No cache value with this key available.</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrGetInfoOfUser', `(RTS_HANDLE hUser, RTS_SIZE key, RTS_TYPEDVALUE *pValue)')

/**
 * <description>Retrieves user name from a user handle.</description>
 * <param name="hUser" type="IN">Handle to the user.</param>
 * <param name="pName" type="IN">Pointer to the buffer where to store the name.</param>
 * <param name="maxLen" type="IN">Maximum size of the user name.</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Retrieving cache value successful. Value copied to pValue.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_INVALID_HANDLE">hUser was not a valid user handle.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">pName was NULL.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_BUFFERSIZE">The buffer was too small.</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrGetUserName', `(RTS_HANDLE hUser, char *pName, RTS_UI32 maxLen)')

/**
 * <description>Get a group by it's name.</description>
 * <param name="pszGroupName" type="IN">Name of the group.</param>
 * <param name="pResult" type="OUT">Error code.</param>
 * <return>Handle to the group</return>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Group found.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">pszGroupName was NULL.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">There is not group with this name.</errorcode>
 */
DEF_ITF_API(`RTS_HANDLE',`CDECL', `UserMgrGetGroup', `(char *pszGroupName, RTS_RESULT *pResult)')

/**
 * <description>Checks if a user is member of a specific group.</description>
 * <param name="hGroup" type="IN">Handle to the uroup.</param>
 * <param name="hUser" type="IN">Handle to the user</param>
 * <return>TRUE: The user is member of that group. FALSE: The user is not member.</return>
 */
DEF_ITF_API(`RTS_BOOL',`CDECL', `UserMgrGroupHasUser', `(RTS_HANDLE hGroup, RTS_HANDLE hUser)')

/**
 * <description>Retrieves user name from a user group.</description>
 * <param name="hUser" type="IN">Handle to the group.</param>
 * <param name="pName" type="IN">Pointer to the buffer where to store the name.</param>
 * <param name="maxLen" type="IN">Maximum size of the user name.</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Retrieving cache value successful. Value copied to pValue.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_INVALID_HANDLE">hUser was not a valid user handle.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">pName was NULL.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_BUFFERSIZE">The buffer was too small.</errorcode>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL', `UserMgrGroupGetName', `(RTS_HANDLE hGroup, char *pName, RTS_UI32 maxLen)')



/**
 * <description>Adds a user to user database</description>
 * <param name="hUser" type="IN">Handle of user with the appropriate rights</param>
 * <param name="pszUserName" type="IN">Name of the user.</param>
 * <param name="pCredentials" type="IN">Credentials of the user.</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">User could be added</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">pszUserName was NULL.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOMEMORY">No memory to add</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_DUPLICATE">pszUserName is already added.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_ACCESS_RIGHTS">User has no access rights</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrAddUser', `(RTS_HANDLE hUser, char *pszUserName, UserMgrCredentials *pCredentials)')

/**
 * <description>Removes a user from user database</description>
 * <param name="hUser" type="IN">Handle of user with the appropriate rights</param>
 * <param name="pszUserName" type="IN">Name of the user.</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">User could be removed</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">pszUserName was NULL.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_ACCESS_RIGHTS">User has no access rights</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrRemoveUser', `(RTS_HANDLE hUser, char *pszUserName)')

/**
 * <description>Adds a group to user group database</description>
 * <param name="hUser" type="IN">Handle of user with the appropriate rights</param>
 * <param name="pszGroupName" type="IN">Name of the group.</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Group could be added</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">pszGroupName was NULL.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOMEMORY">No memory to add group</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_DUPLICATE">pszGroupName is already added.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Creating user or group lists failed</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_ACCESS_RIGHTS">User has no access rights</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrAddGroup', `(RTS_HANDLE hUser, char *pszGroupName)')

/**
 * <description>Removes a group from user group database</description>
 * <param name="hUser" type="IN">Handle of user with the appropriate rights</param>
 * <param name="pszGroupName" type="IN">Name of the group.</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Group was successfully removed</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">pszGroupName was NULL.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_ACCESS_RIGHTS">User has no access rights</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrRemoveGroup', `(RTS_HANDLE hUser, char *pszGroupName)')

/**
 * <description>Adds a user to a group in the user group database</description>
 * <param name="hUser" type="IN">Handle of user with the appropriate rights</param>
 * <param name="pszGroupName" type="IN">Name of the group.</param>
 * <param name="pszUserName" type="IN">Name of the user.</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">User could be added</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">pszGroupName or pszUserName was NULL.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOMEMORY">No memory to add user to group</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_DUPLICATE">pszUserName is already added.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_ACCESS_RIGHTS">User has no access rights</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrGroupAddUser', `(RTS_HANDLE hUser, char *pszGroupName, char *pszUserName)')

/**
 * <description>Removes user from a group in the user group database</description>
 * <param name="hUser" type="IN">Handle of user with the appropriate rights</param>
 * <param name="pszGroupName" type="IN">Name of the group.</param>
 * <param name="pszUserName" type="IN">Name of the user.</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">User could be removed</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">pszGroupName or pszUserName was NULL.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_ACCESS_RIGHTS">User has no access rights</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrGroupRemoveUser', `(RTS_HANDLE hUser, char *pszGroupName, char *pszUserName)')

/**
 * <description>Adds the error tag to the reply stream of an online service, if the service is denied because of a failed access right (authorization error)!</description>
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
 *	Adds a new object to the user management, so the access rights can be configured on that object.
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
DEF_ITF_API(`RTS_HANDLE', `CDECL', `UserMgrObjectAdd', `(char *pszObject, RTS_RESULT *pResult)')

/**
 * <description>Removes an object from the user management and all its children</description>
 * <param name="hObject" type="IN">Handle to object</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Object could be removed</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid object handle</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrObjectRemove', `(RTS_HANDLE hObject)')

/**
 * <description>
 *	Adds a new object under a father object specified by its name to the user management, so the access rights can be configured on that object.
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
 *	Sets the used access rights for the object specified by handle.
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
 *	Gets the used access rights for the object specified by handle.
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
 *	Opens an existing object.
 *	NOTE:
 *	The name of the object must include the full name space with "Device" as the root node, e.g. "Device.MyObject" or if it's a file system object with "/" as the root node.
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
 * <description>Closes an object</description>
 * <param name="hObject" type="IN">Handle to object</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Object could be closed</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid object handle</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrObjectClose', `(RTS_HANDLE hObject)')


/**
 * <description>
 *	Adds a new object to the object management, so the access rights can be configured on that object.
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
DEF_ITF_API(`RTS_HANDLE',`CDECL',`UserMgrObjectAdd2',`(char *pszObject, RTS_UI32 properties, RTS_RESULT *pResult)') 

/**
 * <description>Adds a group to the specified object to manage access rights</description>
 * <param name="hObject" type="IN">Handle to object</param>
 * <param name="hGroup" type="IN">Handle to the group that should be attached</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Group could be added or is already added</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid handles</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOMEMORY">No memory to add group</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrObjectAddGroup', `(RTS_HANDLE hObject, RTS_HANDLE hGroup)')

/**
 * <description>Removes a group from the specified object</description>
 * <param name="hObject" type="IN">Handle to object</param>
 * <param name="hGroup" type="IN">Handle to the group that should be removed</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Group could be removed</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid handles</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrObjectRemoveGroup', `(RTS_HANDLE hObject, RTS_HANDLE hGroup)')

/**
 * <description>Sets the access rights for the group at the specified object</description>
 * <param name="hObject" type="IN">Handle to object</param>
 * <param name="hGroup" type="IN">Handle to the group</param>
 * <element name="ulRights" type="IN">Rights of the group. See category "User rights" for details</element>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Access rights could be set</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid handles</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrObjectSetGroupRights', `(RTS_HANDLE hObject, RTS_HANDLE hGroup, RTS_UI32 ulRights)')

/**
 * <description>Sets the denied access rights for the group at the specified object</description>
 * <param name="hObject" type="IN">Handle to object</param>
 * <param name="hGroup" type="IN">Handle to the group</param>
 * <element name="ulDeniedRights" type="IN">Denied rights of the group. See category "User rights" for details</element>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Access rights could be set</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid handles</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrObjectSetGroupDeniedRights', `(RTS_HANDLE hObject, RTS_HANDLE hGroup, RTS_UI32 ulDeniedRights)')

/**
 * <description>This function clears all granted and denied rights for all groups on that object.</description>
 * <param name="hObject" type="IN">Handle to object</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Access rights could be set</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid handles</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrObjectClearRights', `(RTS_HANDLE hObject)')

/**
 * <description>Gets object name</description>
 * <param name="hObject" type="IN">Handle to the object</param>
 * <param name="pszObject" type="OUT">Pointer to get object name</param>
 * <param name="piMaxLen" type="INOUT">Pointer to length of buffer in pszObject. If pszObject = NULL, only the length of the object name is returned in *piMaxLen</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Object name is returned</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid object handle or pszObject = NULL and piMaxLen = NULL</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrObjectGetName', `(RTS_HANDLE hObject, char *pszObject, int *piMaxLen)')

/**
 * <description>Gets first child object in object tree of the specified father object</description>
 * <param name="hFatherObject" type="IN">Handle to the father object</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">First child object available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter hFatherObject</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">The user management is not initialized or it is not loaded yet</errorcode>
 * <result>Handle to the child object or RTS_INVALID_HANDLE if failed</result>
 */
DEF_ITF_API(`RTS_HANDLE', `CDECL', `UserMgrObjectGetFirstChild', `(RTS_HANDLE hFatherObject, RTS_RESULT *pResult)')

/**
 * <description>Gets next child object in object tree of the specified father object. Must be started with UserDBObjectGetFirstChild()</description>
 * <param name="hFatherObject" type="IN">Handle to the father object</param>
 * <param name="hPrevChildObject" type="IN">Handle to the previous child object retrieved by UserDBObjectGetFirstChild() or subsequent calls of UserDBObjectGetNextChild()</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Next child object available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter hFatherObject or hPrevChildObject</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">The user management is not initialized or it is not loaded yet</errorcode>
 * <result>Handle to the next child object or RTS_INVALID_HANDLE if failed</result>
 */
DEF_ITF_API(`RTS_HANDLE', `CDECL', `UserMgrObjectGetNextChild', `(RTS_HANDLE hFatherObject, RTS_HANDLE hPrevChildObject, RTS_RESULT *pResult)')

/**
 * <description>Iteration interface to get the first group in the user rights management of the specified object</description>
 * <param name="hObject" type="IN">Handle to the object</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">First group available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">No group available</errorcode>
 * <result>Handle to the first group of the object in the user rights management or RTS_INVALID_HANDLE if failed</result>
 */
DEF_ITF_API(`RTS_HANDLE', `CDECL', `UserMgrObjectGetFirstGroup', `(RTS_HANDLE hObject, RTS_RESULT *pResult)')

/**
 * <description>Iteration interface to get next group in the user rights management of the specified object. Must be started with UserDBObjectGetFirstGroup()</description>
 * <param name="hObject" type="IN">Handle to the object</param>
 * <param name="hPrevGroup" type="IN">Handle to the previous group retrieved via UserDBObjectGetFirstGroup() or subsequent calls of UserDBObjectGetNextGroup()</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Next group available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid handles</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">No next group available</errorcode>
 * <result>Handle to the next group of the object in the user rights management or RTS_INVALID_HANDLE if failed</result>
 */
DEF_ITF_API(`RTS_HANDLE', `CDECL', `UserMgrObjectGetNextGroup', `(RTS_HANDLE hObject, RTS_HANDLE hPrevGroup, RTS_RESULT *pResult)')

/**
 * <description>Gets the rights and the denied rights of a group on a specified object</description>
 * <param name="hObject" type="IN">Handle to object</param>
 * <param name="hGroup" type="IN">Handle to the group which access rights are requested</param>
 * <element name="pulRights" type="IN">Pointer to get rights of the group. See category "User rights" for details</element>
 * <element name="pulDeniedRights" type="IN">Pointer to get denied rights of the group. See category "User rights" for details</element>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Access rights could be retrieved</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid handles</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrObjectGetGroupRights', `(RTS_HANDLE hObject, RTS_HANDLE hGroup, RTS_UI32 *pulRights, RTS_UI32 *pulDeniedRights)')

/**
 * <description>Storing the current user rights management into permanent database file</description>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Succeeded</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Error storing user rights database</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTIMPLEMENTED">Is not implemented perhaps the UserRights is fix</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrRightsStore', `(void)')

/**
 * <description>
 * Checks if the given string fits in a buffer determined by the given length including the terminating NUL
 * Returns TRUE if the string was shortened to handle this case
 * </description>
 * <param name="psz" type="IN">The string to check</param>
 * <param name="len" type="IN">Maximum buffer length</param>
 * <result>TRUE means the string was shortened</result>
 */
DEF_ITF_API(`RTS_BOOL', `CDECL', `UserMgrCheckLen', `(char *psz, RTS_UI32 len)')

/**
 * <description>
 * Tells the UserManager that there is an old format database found:
 * The announcement ANNOUNCE may return an error other than ERR_OK (ERR_OPERATION_DENIED is recommended) which indicates that the conversion of the old database is denied.
 * The announcement FINISH tells the UserManager that an old database is converted and adjustment may be processed now.
 * </description>
 * <param name="info" type="IN">ANNOUNCE, FINISH, see Old database announcements</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Succeeded</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `UserMgrAnnounceOldDatabase', `(RTS_UI32 info)')

#ifdef __cplusplus
}
#endif
