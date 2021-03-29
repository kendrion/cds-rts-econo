/**
 * <interfacename>CmpDevice</interfacename>
 * <description> 
 *	<p>Interface for the device component. This is the first component, that contacts a client to get
 *	online access to the target.
 *	Here for example the target identification is checked.</p>
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`CmpDevice')
REF_ITF(`CmpCommunicationLibItf.m4')

#include "CmpBinTagUtilItf.h"

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>
 *  Setting to store the current operation mode of the PLC.
 *  For possible values see category Device operation mode.
 *  Not a configuration option - only to be set/changed by the runtime system.
 * </description>
 */
#define DEVKEY_INT_OPERATION_MODE						"OperationMode"
#ifndef DEVVALUE_INT_OPERATION_MODE_DEFAULT
	#define DEVVALUE_INT_OPERATION_MODE_DEFAULT			DEV_OM_DEBUG
#endif

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>
 *  Setting to store some additional information for some operation modes, to be checked at startup.
 *  Not a configuration option - only to be set/changed/removed by the runtime system.
 * </description>
 */
#define DEVKEY_INT_OPERATION_MODE_CHECK					"OperationModeCheck"


/**
 * <category>Operations</category>
 * <description>
 *  Operations of the device component. Can be disabled with the event CMPID_CmpMgr::EVT_CmpMgr_DisableOperation!
 *	<ul>
 *		<li>OP_DEVICE_SET_OPERATION_MODE: Changes the operation mode of the PLC (see category: Device operation mode). </li>
 *	</ul>
 * </description>
 */
#define OP_DEVICE_SET_OPERATION_MODE				1


/**
 * <category>Device operation mode</category>
 * <description>
 *  The operation mode describes the global operation mode of a PLC. By default a PLC is in debug mode. In this mode all online actions like download, 
 *  debugging and so on are allowed. Other modes restrict some online services to prevent unintended changes by the user on a running machine.
 *
 *	NOTE:
 *	This feature must be activated for each mode in the device description of the target with the following target settings:
 *		- "locked_mode_supported": for DEV_OM_LOCKED
 *		- "operational_mode_supported": for DEV_OM_OPERATIONAL
 *	in the section "runtime_features" (see description of the target settings in the runtime documentation).
 *	With this enabled target settings, the end user can specify the operation mode in the programming system with the menu commands "Online" / "Operating Mode".
 *
 *	NOTE:
 *	To change the operation mode online on the controller, the online user need the USERDB_RIGHT_MODIFY right on the device node (typically Administrator rights)!
 *
 *	Here the available operation modes:
 *	<ul>
 *		<li>DEV_OM_NONE: Unspecified operation mode</li>
 *		<li>DEV_OM_DEBUG: Device is in debug mode: All operations are allowed</li>
 *		<li>DEV_OM_LOCKED: Device is locked: Previously set breakpoints and forced variables are further active, (file-)download and OnlineChange is blocked.
 *			NOTE: Target setting "locked_mode_supported" must be enabled in the device description of the target to use this feature!
 *		</li>
 *		<li>DEV_OM_OPERATIONAL: Device is operational: Debug, force, (file-)download and OnlineChange actions are blocked. This should be the operation mode of a machine in the 
 *		production process!
 *			NOTE: Target setting "operational_mode_supported" must be enabled in the device description of the target to use this feature!
 *		</li>
 *	</ul>
 * </description>
 */
#define DEV_OM_NONE				UINT32_C(0x00000000)
#define DEV_OM_DEBUG			UINT32_C(0x00000001)
#define DEV_OM_LOCKED			UINT32_C(0x00000002)
#define DEV_OM_OPERATIONAL		UINT32_C(0x00000003)

/**
 * <category>Interactive login commands</category>
 * <description>
 *	<ul>
 *		<li>DEV_ILC_NONE: Unspecified login command. Only used for pre-initialization, not in a service.</li>
 *		<li>DEV_ILC_IDENTIFY: The device should send a signal to its user interface (e. g. beep, blinking LED, ...) to identify it.</li>
 *		<li>DEV_ILC_LOGIN_REQUEST: Starts an interactive login. The mode is specified by the category Interactive login mode flags.</li>
 *		<li>DEV_ILC_LOGIN_POLL_RESULT: Polls the result of the interactive login, if it was not synchronously handled during request. 
 *          This is repeated until the device sends another result as ERR_PENDING or the user cancels the login </li>
 *		<li>DEV_ILC_LOGIN_CANCEL: Login was canceled by the user </li>
 *	</ul>
 * </description>
 */
#define DEV_ILC_NONE				UINT32_C(0x00000000)
#define DEV_ILC_IDENTIFY			UINT32_C(0x00000001)
#define DEV_ILC_LOGIN_REQUEST		UINT32_C(0x00000002)
#define DEV_ILC_LOGIN_POLL_RESULT	UINT32_C(0x00000003)
#define DEV_ILC_LOGIN_CANCEL		UINT32_C(0x00000004)

/**
 * <category>Interactive login mode flags</category>
 * <description>
 *	<ul>
 *		<li>DEV_ILMF_NONE: Unspecified login mode. Only used by the event for all login commands except DEV_ILC_LOGIN_REQUEST</li>
 *		<li>DEV_ILMF_ID: Data (string) to be compared on the device.</li>
 *		<li>DEV_ILMF_KEY_PRESS: Key press is requested. This service have to be answered with ERR_PENDING until the user presses the key on the device.</li>
 *		<li>DEV_ILMF_BLINK: The device should send a signal to its user interface (e. g. beep, blinking LED, ...) to identify it. </li>
 *		<li>DEV_ILMF_VERIFY_ID: Id verification was triggered in the background without any user interaction. 
 *			If this fails, the request is immediately repeated on the same session with a user provided id string.</li>
 *	</ul>
 * </description>
 */
#define DEV_ILMF_NONE				UINT32_C(0x00000000)
#define DEV_ILMF_ID					UINT32_C(0x00000001)
#define DEV_ILMF_KEY_PRESS			UINT32_C(0x00000002)
#define DEV_ILMF_BLINK				UINT32_C(0x00000004)
#define DEV_ILMF_VERIFY_ID			UINT32_C(0x80000000)

/**
* <category>DevSrvSession flags</category>
* <description>
*	<ul>
*		<li>RTS_DEV_SRV_SESSION_FLAG_NONE: No flag set</li>
*		<li>RTS_DEV_SRV_SESSION_FLAG_IMPLICIT: DevSrvSession was created implicit at login, no client information</li>
*		<li>RTS_DEV_SRV_SESSION_FLAG_EXPLICIT: DevSrvSession was created explicitly with client information</li>
*		<li>RTS_DEV_SRV_SESSION_LOGGED_IN: DevSrvSession is in logged in state</li>
*	</ul>
* </description>
*/
#define RTS_DEV_SRV_SESSION_FLAG_NONE		0x00000000
#define RTS_DEV_SRV_SESSION_FLAG_IMPLICIT	0x00000001
#define RTS_DEV_SRV_SESSION_FLAG_EXPLICIT	0x00000002
#define RTS_DEV_SRV_SESSION_LOGGED_IN		0x00000004

/**
 * <description> 
 *	Defines some special values for session ids
 * </description> 
 */
#define DEV_SRV_SESSION_ID_EMPTY				0x00000000
#define DEV_SRV_SESSION_ID_INVALID				0x00000001
#define DEV_SRV_SESSION_ID_INITAL_REQUEST		0x00000011
#define DEV_SRV_SESSION_ID_REMOTE_VISU_CLIENT	0x00000815
#define DEV_SRV_SESSION_ID_WEBSERVER			0x0000ABCD
#define DEV_SRV_SESSION_ID_VALIDATION_BIT		0x80000000


/**
 * <category>Online service tags</category>
 */
#define TAG_DEV_REPLY_IDENTIFICATION		0x01
#define TAG_DEV_REPLY_DEVICE_NAME			0x02
#define TAG_DEV_REPLY_VENDOR_NAME			0x03
#define TAG_DEV_REPLY_NODE_NAME				0x04
#define TAG_DEV_REPLY						0x05
#define TAG_DEV_REPLY_RTS_VERSION			0x06
#define TAG_DEV_REPLY_FLAGS					0x07
#define TAG_DEV_REPLY_NUM_CHANNELS			0x08
#define TAG_DEV_REPLY_SERIAL_NUMBER			0x09
#define TAG_DEV_REPLY_IP_ADDR_INFO			0x0A

#define TAG_DEV_REPLY_LOGIN					0x82
#define TAG_DEV_REPLY_LOGIN_RESULT			0x20
#define TAG_DEV_REPLY_LOGIN_SESSIONID		0x21

#define TAG_DEV_REPLY_SETTINGS				0x24  /* further tags used by SRV_DEV_LOGIN service are defined in CmpUserMgrItf */

#define TAG_DEV_RESET_ORIGIN_CONFIG				0x31
#define TAG_DEV_RESET_ORIGIN_CONFIG_OPTIONS		0x32
#define TAG_DEV_RESET_ORIGIN_RESULTS			0x33
#define TAG_DEV_RESET_ORIGIN_CONFIG_RIGHTS		0x34
#define TAG_DEV_RESET_ORIGIN_CONFIG_DESCS		0x84
#define TAG_DEV_RESET_ORIGIN_CONFIG_NUM_DESCS	0x35
#define TAG_DEV_RESET_ORIGIN_CONFIG_DESC		0x36

#define TAG_DEV_REPLY_LOGOUT				0x00

#define TAG_DEV_SESSIONID					0x01

#define TAG_DEV_ECHO_REQUEST_DATA_LEN		0x51
#define TAG_DEV_ECHO_REPLY_DATA_LEN			0x52
#define TAG_DEV_ECHO_DATA					0x53
#define TAG_DEV_OPERATION_MODE				0x54
#define TAG_DEV_INTERACTIVE_LOGIN_MODE		0x55
#define TAG_DEV_INTERACTIVE_LOGIN_DATA		0x56
#define TAG_DEV_INTERACTIVE_LOGIN_COMMAND	0x57
#define TAG_DEV_NODE_NAME					0x58

#define TAG_DEV_CLIENT_IDENTIFIER			0x83
#define TAG_DEV_CLIENT_TYPE					0x40
#define TAG_DEV_CLIENT_NAME					0x41
#define TAG_DEV_CLIENT_VENDOR				0x42
#define TAG_DEV_CLIENT_HOSTNAME				0x43
#define TAG_DEV_CLIENT_VERSION				0x44
#define TAG_DEV_CLIENT_CDS_VERSION			0x45
#define TAG_DEV_CLIENT_AUTH_TYPE			0x46


/**
 * <category>Online services</category>
 * <service group="SG_DEVICE" id="SRV_DEV_GET_TARGET_IDENT" name="Get target identity"
 *  description="">
 *	<request>
 *		<tag id="TAG_DEV_REPLY_IDENTIFICATION" name="Identification" cardinality="1..?" type=""
 *		 description="TODO"/>
 *	</request>
 *	<response>
 *		<tag id="TAG_DEV_REPLY_IDENTIFICATION" name="Identification" cardinality="0..?" type=""
 *		 description="TODO"/>
 *		<tag id="TAG_DEV_REPLY_DEVICE_NAME" name="Device name" cardinality="0..?" type=""
 *		 description="TODO"/>
 *		<tag id="TAG_DEV_REPLY_VENDOR_NAME" name="Vendor name" cardinality="0..?" type=""
 *		 description="TODO"/>
 *		<tag id="TAG_DEV_REPLY_NODE_NAME" name="Node name" cardinality="0..?" type=""
 *		 description="TODO"/>
 *		<tag id="TAG_DEV_REPLY" name="Reply" cardinality="1..?" type=""
 *		 description="TODO"/>
 *		<tag id="TAG_DEV_REPLY_RTS_VERSION" name="RTS version" cardinality="0..?" type=""
 *		 description="TODO"/>
 *		<tag id="TAG_DEV_REPLY_FLAGS" name="Flags" cardinality="0..?" type=""
 *		 description="TODO"/>
 *		<tag id="TAG_DEV_REPLY_NUM_CHANNELS" name="Number of channels" cardinality="0..?" type=""
 *		 description="TODO"/>
 *		<tag id="TAG_DEV_REPLY_SERIAL_NUMBER" name="Serial number" cardinality="0..?" type=""
 *		 description="TODO"/>
 *		<tag id="TAG_DEV_REPLY_IP_ADDR_INFO" name="IP address info" cardinality="0..?" type=""
 *		 description="TODO"/>
 *	</response>
 * </service>
 */
#define SRV_DEV_GET_TARGET_IDENT 0x01

/**
 * <category>Online services</category>
 * <service group="SG_DEVICE" id="SRV_DEV_LOGIN" name="Login">
 *	<description>
 *		Login service. Login as user on a session explicitly created by SRV_DEV_SESSION_CREATE. For old clients, which do not send the SRV_DEV_SESSION_CREATE service,
 *		the session is implicitly created by this service. Depending on the used authentication type, this service have to be sent several times.
 *	</description>
 *	<request>
 *		<tag id="TAG_USERMGR_CRYPT_TYPE" name="Crypt type" cardinality="1..?" type="RTS_UI32"
 *		 description="Authentication type. Must match to the type negotiated by SRV_DEV_SESSION_CREATE."/>
 *		<tag id="TAG_USERMGR_CRYPT_STEP" name="" cardinality="0..?" type="RTS_UI32"
 *		 description="Current step of login sequence. Not used for authentication type USERMGR_CRYPT_XOR."/>
 *		<tag id="TAG_USERMGR_CRYPT_CHALLENGE" name="Crypt challenge" cardinality="0..?" type="char*"
 *		 description="Challenge used for password encryption. Only used for authentication type USERMGR_CRYPT_XOR."/>
 *		<complextag id="TAG_USERMGR_CREDENTIALS" name="Credentials" cardinality="0..?"
 *		 description="Top level tag. Contains the user credentials.">
 *			<tag id="TAG_USERMGR_USER" name="User" cardinality="0..?" type="char*"
 *			 description="User name."/>
 *			<tag id="TAG_USERMGR_PASSWORD" name="Password" cardinality="0..?" type="char*"
 *			 description="Encrypted password."/>
 *		</complextag>
 *	</request>
 *	<response>
 *		<tag id="TAG_USERMGR_CRYPT_PUB_KEY" name="" cardinality="0..?" type="char*"
 *		 description="Public key used for password encryption. Only sent for authentication type USERMGR_CRYPT_ASYMMETRIC."/>
 *		<tag id="TAG_USERMGR_CRYPT_NONCE" name="" cardinality="0..?" type="char*"
 *		 description="Nonce used for password encryption. Only sent for authentication type USERMGR_CRYPT_ASYMMETRIC."/>
 *		<complextag id="TAG_ONLINE_ACCESS_RESULT" name="" cardinality="1..?"
 *		 description="Top level tag. Contains the service result, if access rights are missing for the requested service.">
 *			<tag id="TAG_USRMGR_REPLY_LOGIN_RESULT" name="" cardinality="1..?" type="RTS_UI16">
 *				<description>
 *					Result code of online operation.
 *					Important result codes, which should be handled by the client: ERR_OK, ERR_PENDING, ERR_TYPE_MISMATCH, ERR_CHANGE_PASSWORD, ERR_NOT_READY_YET, ERR_NO_ACCESS_RIGHTS
 *				</description>
 *			</tag>
 *		</complextag>
 *		<complextag id="TAG_ONLINE_ACCESS_OBJECT" name="" cardinality="1..?"
 *		 description="Top level tag. Describes the denied access.">
 *			<tag id="TAG_NAME" name="" cardinality="1..?" type="char*"
 *			 description="Object which should be accessed"/>
 *			<tag id="TAG_RIGHTS" name="" cardinality="1..?" type="RTS_UI32"
 *			 description="Needed rights to execute the requested access."/>
 *		</complextag>
 *		<tag id="TAG_USERMGR_CRYPT_TYPE" name="" cardinality="1..?" type="RTS_UI32"
 *		 description="Authentication type. Matches to the type negotiated by SRV_DEV_SESSION_CREATE."/>
 *		<tag id="TAG_USERMGR_CRYPT_CHALLENGE" name="" cardinality="0..?" type="char*"
 *		 description="Challenge used for password encryption. Only used for authentication type USERMGR_CRYPT_XOR."/>
 *		<complextag id="TAG_USRMGR_REPLY_LOGIN" name="Login reply" cardinality="1..?"
 *		 description="Top level tag. Contains the service result, if access rights are missing for the requested service.">
 *			<tag id="TAG_USRMGR_REPLY_LOGIN_RESULT" name="Login result" cardinality="1..?" type="RTS_UI16"
 *			 description="Result code of online operation."/>
 *			<tag id="TAG_DEV_REPLY_SETTINGS" name="Settings" cardinality="0..?" type="RTS_UI32"
 *			 description="Feature flags of the runtime system. Only sent, if the login was completed successfully."/>
 *			<tag id="TAG_DEV_REPLY_LOGIN_SESSIONID" name="Login session id" cardinality="0..?" type="RTS_UI32"
 *			 description="SessionID which has to be used for all further online services."/>
 *		</complextag>
 *		<complextag id="TAG_OBJECT" name="" cardinality="1..?"
 *		 description="Top level tag. Describes the denied access.">
 *			<tag id="TAG_NAME" name="" cardinality="1..?" type="char*"
 *			 description="Object which should be accessed"/>
 *			<tag id="TAG_RIGHTS" name="" cardinality="1..?" type="RTS_UI32"
 *			 description="Needed rights to execute the requested access."/>
 *		</complextag>
 *	</response>
 * </service>
 */
#define SRV_DEV_LOGIN 0x02

/**
 * <category>Online services</category>
 * <service group="SG_DEVICE" id="SRV_DEV_LOGOUT" name="Logout"
 *  description="">
 *	<request>
 *		<tag id="TODO_0x01" name="" cardinality="" type=""
 *		 description="TODO"/>
 *	</request>
 *	<response>
 *		<tag id="TAG_DEV_REPLY_LOGOUT" name="Logout reply" cardinality="" type=""
 *		 description="TODO"/>
 *	</response>
 * </service>
 */
#define SRV_DEV_LOGOUT 0x03

/**
 * <category>Online services</category>
 * <service group="SG_DEVICE" id="SRV_DEV_RESET_ORIGIN" name="Reset origin">
 *	<description>
 *		Reset Origin [Device]. Reset the device to factory settings.
 *		Compatibility note: if no tag TAG_DEV_RESET_ORIGIN_CONFIG_OPTIONS is received, the reset will affect all objects for which the current user has the needed rights (except objects specified by TAG_DEV_RESET_ORIGIN_CONFIG).
 *	</description>
 *	<request>
 *		<tag id="TAG_DEV_RESET_ORIGIN_CONFIG_OPTIONS" name="Reset origin config" cardinality="0..?" type="RTS_UI32">
 *			<description>
 *				See category "Reset Origin Configuration". Flag field for objects that shall not be handled during reset.
 *			</description>
 *		</tag>
 *		<tag id="TAG_DEV_RESET_ORIGIN_CONFIG" name="Reset origin config" cardinality="0..?" type="RTS_UI32">
 *			<description>
 *				Obsolete: use TAG_DEV_RESET_ORIGIN_CONFIG_OPTIONS instead.
 *			</description>
 *		</tag>
 *	</request>
 *	<response>
 *		<tag id="TAG_DEV_RESET_ORIGIN_RESULTS" name="Reset origin results" cardinality="0..1" type="RTS_UI32">
 *			<description>
 *				Only if an error occured during deletion of the configured objects: bit vector indicating the results for the requested configuration (bit=1: error deleting the corresponding object, bit=0: success).
 *			</description>
 *		</tag>
 *		<tag id="TAG_SERVICE_RESULT" name="Result" cardinality="" type=""
 *		 description="TODO"/>
 *	</response>
 * </service>
 */
#define SRV_DEV_RESET_ORIGIN 0x04

/**
 * <category>Online services</category>
 * <service group="SG_DEVICE" id="SRV_DEV_ECHO" name="Echo">
 *	<description>
 *		Echo service. Receives services and send replies with dummy bytes as payload. If the tag TAG_DEV_ECHO_REPLY_DATA_LEN is omitted in
 *		the request, the server sends an empty service reply without any tag. If the requested reply length in TAG_DEV_ECHO_REPLY_DATA_LEN
 *		exceeds the communication buffer, then the length is limited to a value, which completely fills the communication buffer. If the requested
 *		reply length is greater than the request length, then dummy bytes are generated by the server. If not, the payload is copied starting from
 *		the beginning of the request payload in TAG_DEV_ECHO_DATA.
 *	</description>
 *	<request>
 *		<tag id="TAG_DEV_ECHO_REQUEST_DATA_LEN" name="Request data length" cardinality="0..?" type="RTS_UI32"
 *		 description="Length of tag content in TAG_DEV_ECHO_DATA."/>
 *		<tag id="TAG_DEV_ECHO_REPLY_DATA_LEN" name="Reply data length" cardinality="0..?" type="RTS_UI32"
 *		 description="Requested length of reply content in TAG_DEV_ECHO_DATA."/>
 *		<tag id="TAG_DEV_ECHO_DATA" name="Data" cardinality="0..?" type="char*"
 *		 description="Dummy bytes as payload."/>
 *	</request>
 *	<response>
 *		<tag id="TAG_SERVICE_RESULT" name="Result" cardinality="0..?" type="RTS_UI16"
 *		 description="Result code of online operation"/>
 *		<tag id="TAG_DEV_ECHO_REPLY_DATA_LEN" name="Reply data length" cardinality="0..?" type="RTS_UI32"
 *		 description="Length of tag content in TAG_DEV_ECHO_DATA"/>
 *		<tag id="TAG_DEV_ECHO_DATA" name="Data" cardinality="0..?" type="char*"
 *		 description="Dummy bytes as payload."/>
 *	</response>
 * </service>
 */
#define SRV_DEV_ECHO 0x05

/**
 * <category>Online services</category>
 * <service group="SG_DEVICE" id="SRV_DEV_SET_OPERATION_MODE" name="Set operation mode"
 *  description="Sets one of the device operation modes of the PLC (see category: Device operation mode). Changing the operation mode may be denied by the PLC.">
 *	<request>
 *		<tag id="TAG_DEV_OPERATION_MODE" name="Operation mode" cardinality="0..?" type="RTS_UI32"
 *		 description="Operation mode to set."/>
 *	</request>
 *	<response>
 *		<tag id="TAG_SERVICE_RESULT" name="Result" cardinality="1..?" type="RTS_UI6"
 *		 description="Result code of online operation"/>
 *		<tag id="TAG_USER_NOTIFY" name="" cardinality="0..?" type="LogEntry"
 *		 description="User notification message, contains the component, which has denied the service"/>
 *	</response>
 * </service>
 */
#define SRV_DEV_SET_OPERATION_MODE 0x06

/**
 * <category>Online services</category>
 * <service group="SG_DEVICE" id="SRV_DEV_GET_OPERATION_MODE" name="Get operation mode"
 *  description="Retrieves the device operation modes of the PLC (see category: Device operation mode).">
 *	<request/>
 *	<response>
 *		<tag id="TAG_DEV_OPERATION_MODE" name="Operation mode" cardinality="1..?" type="RTS_UI32"
 *		 description="Current operation mode of the device."/>
 *	</response>
 * </service>
 */
#define SRV_DEV_GET_OPERATION_MODE 0x07

/**
 * <category>Online services</category>
 * <service group="SG_DEVICE" id="SRV_DEV_INTERACTIVE_LOGIN" name="Interactive login"
 *  description="Interactive login service. Helps to identify a PLC before login. ">
 *	<request>
 *		<tag id="TAG_DEV_INTERACTIVE_LOGIN_COMMAND" name="Command" cardinality="1..?" type="RTS_UI32">
 *			<description>
 *				See category "Interactive login commands".
 *			</description>
 *		</tag>
 *		<tag id="TAG_DEV_INTERACTIVE_LOGIN_MODE" name="Mode" cardinality="0..?" type="RTS_UI32"
 *		 description="See category Interactive login mode flags. Only used for command DEV_ILC_LOGIN_REQUEST."/>
 *		<tag id="TAG_DEV_INTERACTIVE_LOGIN_DATA" name="Data" cardinality="0..?" type="RTS_UI8*"
 *		 description="Login information to be checked by the runtime system. Only used for mode DEV_ILM_STRING"/>
 *	</request>
 *	<response>
 *		<tag id="TAG_SERVICE_RESULT" name="Result" cardinality="1..?" type="RTS_UI16">
 *			<description>
 *				Result code of online operation. Supported results: 
 *				ERR_OK (interactive login successful), 
 *				ERR_FAILED (generic error), 
 *				ERR_TIMEOUT (timeout elapsed on device side), 
 *				ERR_PENDING (device still waits for user action, e. g. key press), 
 *				ERR_NOT_SUPPORTED (requested login mode is not supported by the device) 
 *				ERR_ID_MISMATCH (login information does not match).
 *			</description>
 *		</tag>
 *		<tag id="TAG_DEV_REPLY_LOGIN_SESSIONID" name="Session id" cardinality="0..?" type="RTS_UI32">
 *			<description>
 *				SessionID which have to be used for all further online services on this channel. 
 *				Only returned for command DEV_ILC_LOGIN_REQUEST
 *			</description>
 *		</tag>
 *	</response>
 * </service>
 */
#define SRV_DEV_INTERACTIVE_LOGIN 0x08

/**
 * <category>Online services</category>
 * <service group="SG_DEVICE" id="SRV_DEV_SET_NODE_NAME" name="Set node name"
 *  description="Sets a new UTF-16 node name for the device.">
 *	<request>
 *		<tag id="TAG_DEV_NODE_NAME" name="Node name" cardinality="1..?" type="RTS_UI32">
 *			<description>
 *				New UTF-16 node name. By passing an empty string, the node name settings are
 *				deleted and so the default node name is set again.
 *			</description>
 *		</tag>
 *	</request>
 *	<response>
 *		<tag id="TAG_SERVICE_RESULT" name="Result" cardinality="1..?" type="RTS_UI6"
 *		 description="Result code of online operation. See description of SysTargetSetNodeName for details."/>
 *	</response>
 * </service>
 */
#define SRV_DEV_SET_NODE_NAME 0x09

/**
 * <category>Online services</category>
 * <service group="SG_DEVICE" id="SRV_DEV_SESSION_CREATE" name=""
 *  description="Service to create a session and identify the client. ">
 *	<request>
 *		<complextag id="TAG_DEV_CLIENT_IDENTIFIER" name="" cardinality="1..?"
 *		 description="Top level tag. Contains the client identification.">
 *			<tag id="TAG_DEV_CLIENT_TYPE" name="" cardinality="1..?" type="RTS_UI32"
 *			 description="The type of the client. See Client type in CmpSessionInformationItf."/>
 *			<tag id="TAG_DEV_CLIENT_NAME" name="" cardinality="0..?" type="char[]"
 *			 description="UTF-8 encoded name of the client."/>
 *			<tag id="TAG_DEV_CLIENT_VENDOR" name="" cardinality="0..?" type="char[]"
 *			 description="UTF-8 encoded vendor name of the client."/>
 *			<tag id="TAG_DEV_CLIENT_HOSTNAME" name="" cardinality="0..?" type="char[]"
 *			 description="UTF-8 encoded fully qualified host name (FQHN) of the system where the client is running."/>
 *			<tag id="TAG_DEV_CLIENT_VERSION" name="" cardinality="0..?" type="char[]"
 *			 description="UTF-8 encoded client version number."/>
 *			<tag id="TAG_DEV_CLIENT_CDS_VERSION" name="" cardinality="0..?" type="char[]"
 *			 description="UTF-8 encoded fully CODESYS version number."/>
 *		</complextag>
 *		<tag id="TAG_DEV_CLIENT_AUTH_TYPE" name="" cardinality="1..?" type=""
 *		 description="Authentication types supported by the client. See Crypt type in CmpUserMgrItf."/>
 *	</request>
 *	<response>
 *		<tag id="TAG_DEV_REPLY_LOGIN_SESSIONID" name="" cardinality="0..?" type="RTS_UI32"
 *		 description="SessionID which has to be used for all further online services of this client."/>
 *		<tag id="TAG_DEV_CLIENT_AUTH_TYPE" name="" cardinality="1..?" type="RTS_UI32"
 *		 description="Effective authentication type selected by the runtime"/>
 *	</response>
 * </service>
 */
#define SRV_DEV_SESSION_CREATE 0x0A

 /**
 * <category>Online services</category>
 * <service group="SG_DEVICE" id="SRV_DEV_RESET_ORIGIN_GET_CONFIG" name="Reset origin get configuration"
 *  description="Get Reset Origin [Device] configuration. Is used to retrieve information about objects that are handled by the reset.">
 *	<request>
 *	</request>
 *	<response>
 *		<tag id="TAG_DEV_RESET_ORIGIN_CONFIG_OPTIONS" name="Reset origin config" cardinality="1" type="RTS_UI32">
 *			<description>
 *				See category "Reset Origin Configuration". Each bit represents an object that is handled.
 *			</description>
 *		</tag>
 *		<tag id="TAG_DEV_RESET_ORIGIN_CONFIG_RIGHTS" name="Reset origin config rights" cardinality="1" type="RTS_UI32">
 *			<description>
 *				Indicates the user access rights for the configuration. Each bit represents the right for the corresponding bit in TAG_DEV_RESET_ORIGIN_CONFIG_OPTIONS
 *				(bit=0: the current user is allowed to delete the corresponding object, bit=1: the user is not allowed to delete the corresponding object).
 *			</description>
 *		</tag>
 *		<complextag id="TAG_DEV_RESET_ORIGIN_CONFIG_DESCS" name="" cardinality="1"
 *		 description="Top level tag. Contains the descriptions of the objects that are handled in ascending order corresponding to the bits in TAG_DEV_RESET_ORIGIN_CONFIG_OPTIONS">
 *			<tag id="TAG_DEV_RESET_ORIGIN_CONFIG_NUM_DESCS" name="" cardinality="1" type="RTS_UI16"
 *			 description="Number of following descriptions"/>
 *			<tag id="TAG_DEV_RESET_ORIGIN_CONFIG_DESC" name="" cardinality="1..?" type="RTS_UTF8STRING"
 *			 description="Description of the object"/>
 *		</complextag>
 *		<tag id="TAG_SERVICE_RESULT" name="Result" cardinality="1" type="RTS_UI16">
 *			<description>
 *				Result code of online operation. Supported results: 
 *				ERR_OK (configuration successfully retrieved), 
 *				ERR_FAILED (generic error).
 *			</description>
 *	</response>
 * </service>
 */
#define SRV_DEV_RESET_ORIGIN_GET_CONFIG 0x0B

/**
 * <category>Event parameter</category>
 * <element name="ui32LoginCommand" type="IN">Login command. See category "Interactive login commands" (look for DEV_ILC_xxx defines).</element>
 * <element name="ui32LoginMode" type="IN">Login mode. See category "Interactive login mode flags" (look for DEV_ILMF_xxx defines). Only used for command DEV_ILC_LOGIN_REQUEST.</element>
 * <element name="pui8LoginData" type="IN">Login information to be checked by the runtime system. Only used for mode DEV_ILM_STRING</element>
 * <element name="rLoginResult" type="OUT">Error code of event handler:
 *		<ul>
 *			<li>ERR_OK: Operation succeeded</li>
 *			<li>ERR_ID_MISMATCH: Is returned at DEV_ILMF_ID, if the ID does not match (e.g. the entered serial number is not identical to the target)</li>
 *			<li>ERR_PENDING: Is returned at DEV_ILMF_KEY_PRESS, if we wait for pressing the key</li>
 *		</ul>
 * </element>
 */
typedef struct
{
	RTS_UI32 ui32LoginCommand; 
	RTS_UI32 ui32LoginMode;
	RTS_UI8* pui8LoginData;
	RTS_RESULT rLoginResult;
} EVTPARAM_CmpDevice_InteractiveLogin;
#define EVTPARAMID_CmpDevice_InteractiveLogin	0x0001
#define EVTVERSION_CmpDevice_InteractiveLogin	0x0001

/**
 * <category>Event parameter</category>
 * <element name="ui32ResetOriginConfig" type="IN">Configuration bit vector. See category "Reset Origin Configuration".</element>
 * <element name="hUser" type="IN">User handle of the current user.</element>
 * <element name="ui32ResetOriginResults" type="OUT">Result bit vector corresponding to ui32ResetOriginConfig (bit=0: success, bit=1: failed).</element>
 */
typedef struct
{
	RTS_UI32 ui32ResetOriginConfig;
	RTS_HANDLE hUser;
	RTS_UI32 ui32ResetOriginResults;
} EVTPARAM_CmpDevice_ResetOrigin;
#define EVTPARAMID_CmpDevice_ResetOrigin	0x0001
#define EVTVERSION_CmpDevice_ResetOrigin	0x0002

/**
 * <category>Event parameter</category>
 * <element name="ui32OperationMode" type="IN">New operation mode of the device. See category Device operation mode for possible values.</element>
 */
typedef struct
{
	RTS_UI32 ui32OperationMode;
} EVTPARAM_CmpDevice_SetOperationMode;
#define EVTPARAMID_CmpDevice_SetOperationMode	0x0001
#define EVTVERSION_CmpDevice_SetOperationMode	0x0001

/**
 * <category>Event parameter</category>
 * <element name="hUser" type="IN">User handle of the current user.</element>
 * <element name="ui32ResetOriginConfigOptions" type="OUT">
 *		Configuration bit vector representing the possible objects that are handled. See category "Reset Origin Configuration".
 *		The callback has to set the bit for the object it is responsible for.
 * </element>
 * <element name="ui32ResetOriginConfigRights" type="OUT">
 *		Bit vector indicating the access rights for the specified user to delete the objects represented in ui32ResetOriginConfigOptions
 *		(bit=0: the current user is allowed to delete the corresponding object, bit=1: the user is not allowed to delete).
 * </element>
 */
typedef struct
{
	RTS_HANDLE hUser;
	RTS_UI32 ui32ResetOriginConfigOptions;
	RTS_UI32 ui32ResetOriginConfigRights;
} EVTPARAM_CmpDevice_ResetOriginGetConfig;
#define EVTPARAMID_CmpDevice_ResetOriginGetConfig	0x0002
#define EVTVERSION_CmpDevice_ResetOriginGetConfig	0x0001

/**
 * <category>Reset Origin Configuration</category>
 * <description>Configuration of the Reset Origin service &amp; event.
 *	NOTE: 
 *	If this list is extended, a corresponding description has to be added to the "Reset Origin Configuration Descriptions".
 *	Also, the list in the IDE should be extended including the localization of the description.
 * </description>
 */
#define DEV_ROC_RESET_ALL	0x00000000
#define DEV_ROC_USERMGMT	0x00000001
#define DEV_ROC_KEEP_USERDB	DEV_ROC_USERMGMT
#define DEV_ROC_PLCLOGIC	0x00000002
#define DEV_ROC_CERTS		0x00000004

/**
 * <category>Reset Origin Configuration Descriptions</category>
 * <description>Descriptions of the objects defined in category "Reset Origin Configuration".</description>
 */
#define DEV_ROC_DESCS	{\
							{ DEV_ROC_USERMGMT,	"User Management" }, \
							{ DEV_ROC_PLCLOGIC,	"PlcLogic" }, \
							{ DEV_ROC_CERTS,	"Certificates" }, \
						}

/* Structure to handle a mapping of a reset origin configuration flag and a description */
typedef struct RTS_ROC_TO_DESC_
{
	RTS_UI32 ui32Flag;
	RTS_UTF8STRING *pDesc;
} RTS_ROC_TO_DESC;

/**
 * <category>Events</category>
 * <description>Event is sent to operate the interactive login or the wink feature.
 *	1. Wink:
 *	   The user can select a device in the Gateway dialog, and let it "blink". This allows to identify a device in the list of devices found in the scan. This may be expecially neccessary while PLC don't have unique or meaningful names yet.
 *	2. Secure Login:
 *     During login, it can be guaranteed that the user is connecting to the correct PLC.
 * </description>
 * <param name="pEventParam" type="IN">EVTPARAM_CmpDevice_InteractiveLogin</param>
 */
#define EVT_CmpDevice_InteractiveLogin			MAKE_EVENTID(EVTCLASS_INFO, 1)

/**
 * <category>Events</category>
 * <description>Event is sent at reset origin device.</description>
 * <param name="pEventParam" type="IN">EVTPARAM_CmpDevice_ResetOrigin</param>
 */
#define EVT_CmpDevice_ResetOrigin 				MAKE_EVENTID(EVTCLASS_INFO, 2)

/**
 * <category>Events</category>
 * <description>Event is sent after operation mode has been set</description>
 * <param name="pEventParam" type="IN">EVTPARAM_CmpDevice_SetOperationMode</param>
 */
#define EVT_CmpDevice_SetOperationMode 			MAKE_EVENTID(EVTCLASS_INFO, 3)

 /**
 * <category>Events</category>
 * <description>Event is sent when the reset origin configuration is requested. Each responsible component has to add its information to the event parameter in the callback.</description>
 * <param name="pEventParam" type="IN">EVTPARAM_CmpDevice_ResetOriginGetConfig</param>
 */
#define EVT_CmpDevice_ResetOriginGetConfig		MAKE_EVENTID(EVTCLASS_INFO, 4)

/**
 * <category>Settings flags</category>
 * <description>Settings flags that re returned by the runtime system</description>
 */
#define SETTINGS_FLAG_KILLTASKONRESET			 0x01
#define SETTINGS_FLAG_COMPLEXMONITORING			 0x02
#define SETTINGS_FLAG_MONITORING2				 0x04
#define SETTINGS_FLAG_TRACE_SUPPORTS_MONITORING2 0x08
#define SETTINGS_FLAG_EDGE_GATEWAY				 0x10
#define SETTINGS_FLAG_EDGE_GATEWAY_CONFIGURABLE	 0x20

/**
 * <category>Static defines</category>
 * <description>Predefined objects in the runtime</description>
 */
#define USERDB_OBJECT_DEVICE		"Device"

typedef struct
{
	unsigned long ulSessionId;
	RTS_HANDLE hUser;
} DeviceSession;

/**
 * <category>Target identification</category>
 * <description>
 *	These values identifies a target completely unique!
 * </description>
 *	<element name="ulTargetType" type="IN">Target type. See category "Device Types" in SysTargetItf.h.</element>
 *	<element name="ulTargetId" type="IN">ID: HiWord = VendorID, LowWord = ID</element>
 *	<element name="ulTargetVersion" type="IN">Version of the target</element>
 */
typedef struct
{
	RTS_UI32 ulTargetType;
	RTS_UI32 ulTargetId;
	RTS_UI32 ulTargetVersion;
} TargetIdent;


/**
 * <category>Device description</category>
 * <description>
 * </description>
 *	<element name="targetIdent" type="IN">Target identification</element>
 *	<element name="pwszDeviceName" type="IN">Pointer to device name</element>
 *	<element name="nMaxDeviceNameLen" type="IN">Maximum length of the device name buffer in UNICODE characters (not bytes!)</element>
 *	<element name="pwszVendorName" type="IN">Pointer to vendor name</element>
 *	<element name="nMaxVendorNameLen" type="IN">Maximum length of the vendor name buffer in UNICODE characters (not bytes!)</element>
 *	<element name="pwszNodeName" type="IN">Pointer to node name</element>
 *	<element name="nMaxNodeNameLen" type="IN">Maximum length of the node name buffer in UNICODE characters (not bytes!)</element>
 */
typedef struct
{
	TargetIdent targetIdent;
	RTS_WCHAR *pwszDeviceName;
	RTS_SIZE nMaxDeviceNameLen;
	RTS_WCHAR *pwszVendorName;
	RTS_SIZE nMaxVendorNameLen;
	RTS_WCHAR *pwszNodeName;
	RTS_SIZE nMaxNodeNameLen;
} DeviceIdentification;


#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description>Retrieves the target identification</description>
 * <param name="pDevIdent" type="OUT">Pointer to identification. Is filled by the function. If string pointer are NULL,
 *	the real size of the strings is returned.</param>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`DevGetIdent',`(DeviceIdentification *pDevIdent)')

/**
 * <description>Checks the compatibility between a requested identification and the target identification</description>
 * <param name="pTargetIdentReq" type="IN">Requested target identification to check. Must not be NULL!</param>
 * <param name="pTargetIdent" type="IN">Own target identity. Can be NULL, then the built in target identification is used</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Target identifications matched</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">pTargetIdentReq is NULL</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_TYPE_MISMATCH">Type mismatch</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_ID_MISMATCH">ID mismatch</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_VERSION_MISMATCH">Version mismatch. Versions not compatible!</errorcode>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`DevCheckTargetIdent',`(TargetIdent *pTargetIdentReq, TargetIdent *pTargetIdent)')

/**
 * <description> 
 *  Function to set the operation mode of the device. Usually this is called by an online service, received from the development system.
 *  Switching to the new operation mode may be denied by another component.
 * </description>
 * <element name="ui32Operation" type="IN">New operation mode of the device. See category Device operation mode for possible values.</element>
 * <element name="pCmpIdDisabled" type="OUT">Pointer to ComponentID to get the component, which disabled the operation. Can be NULL.</element>
 * <result>
 *	<ul>
 *		<li>ERR_OK: New operation mode was successfully set</li>
 *		<li>ERR_OPERATION_DENIED: The component returned in pCmpIdDisabled has denied the new operation mode</li>
 *		<li>ERR_FAILED: Operation mode could not be set because of another error</li>
 *	</ul>
 * </result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`DevSetOperationMode',`(RTS_UI32 ui32OperationMode, CMPID *pCmpIdDisabled)')

/**
 * <description> 
 *  Function to get the current operation mode of the device.
 * </description>
 * <element name="pui32Operation" type="OUT">Pointer to return the current operation mode.</element>
 * <result>
 *	<ul>
 *		<li>ERR_OK: Current operation mode was returned in pui32Operation. See category Device operation mode for possible values.</li>
 *		<li>ERR_PARAMETER: pui32Operation was a pointer to NULL.</li>
 *	</ul>
 * </result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`DevGetOperationMode',`(RTS_UI32 *pui32OperationMode)')

/** 
 * <description>
 *   Retrieves the stored session id from the first session instance assigned to this channel.  
 * </description>
 * <param name="ulChannelHandle" type="IN">Id of the channel for which the session id should be read.</param>
 * <param name="pulSessionId" type="OUT">Pointer to return the session id.</param>
 * <result>error code</result>
*/
DEF_ITF_API(`RTS_RESULT',`CDECL', `DevGetSessionId',`(RTS_UI32 ulChannelHandle, RTS_UI32 *pulSessionId)')

/** 
 * <description>
 *   Retrieves the user handle assigned to the session.  
 * </description>
 * <param name="ui32SessionId" type="IN">Session id of which the user handle should be read.</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">User is available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">The session management is not initialized</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">The session is not available</errorcode>
 * <result>Handle of the user or RTS_INVALID_HANDLE if not available</result>
*/
DEF_ITF_API(`RTS_HANDLE',`CDECL', `DevGetSessionUser',`(RTS_UI32 ui32SessionId, RTS_RESULT *pResult)')

/** 
 * <description>
 *   Retrieves the authentication type used for the session.  
 * </description>
 * <param name="ui32SessionId" type="IN">Session id of which the authentication type should be read.</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Authentication type was read successfully</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">The session management is not initialized</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">The session is not available</errorcode>
 * <result>Crypt type (see CmpUserMgrItf) or USERMGR_CRYPT_INVALID if not available</result>
*/
DEF_ITF_API(`RTS_UI32',`CDECL', `DevGetSessionAuthType',`(RTS_UI32 ui32SessionId, RTS_RESULT *pResult)')

/** 
 * <description>
 *   Retrieves the specific flags describing the session.  
 * </description>
 * <param name="ui32SessionId" type="IN">Session id of which the session flags should be read.</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Flags were read successfully</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">The session management is not initialized</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">The session is not available</errorcode>
 * <result>Session flags</result>
*/
DEF_ITF_API(`RTS_UI32',`CDECL', `DevGetSessionFlags',`(RTS_UI32 ui32SessionId, RTS_RESULT *pResult)')

/** 
 * <description>
 *   Checks if a request is valid.
 * </description>
 * <param name="ulChannelHandle" type="IN">Id of the channel on which the request was received.</param>
 * <param name="pHeaderTag" type="IN">Pointer to the header of the request to check.</param>
 * <result>error code</result>
*/
DEF_ITF_API(`RTS_RESULT',`CDECL', `DevIsValidRequest',`(RTS_UI32 ulChannelHandle, HEADER_TAG_EXT *pHeaderTag, PROTOCOL_DATA_UNIT *pPduReply)')

/** 
 * <description>
 *   Reset origin device. Only supported if CmpEventMgr is available.
 * </description>
 * <param name="hUser" type="IN">User handle of the current user.</param>
 * <param name="ui32ResetOriginConfig" type="IN">Configuration bit vector. See category "Reset Origin Configuration".</param>
 * <param name="pui32ResetOriginResults" type="OUT">Optional: pointer to the bit vector indicating the results for the requested configuration
 *		(bit=1: error deleting the corresponding object, bit=0: success).</param>
 * <result>
 *	<ul>
 *		<li>ERR_OK: Reset origin device successful</li>
 *		<li>ERR_FAILED: At least one object could not be deleted. Check pui32Results for more information.</li>
 *	</ul>
 * </result>
*/
DEF_ITF_API(`RTS_RESULT',`CDECL', `DevResetOrigin',`(RTS_HANDLE hUser, RTS_UI32 ui32ResetOriginConfig, RTS_UI32 *pui32ResetOriginResults)')

/** 
 * <description>
 *   Get configuration for reset origin device. Returns the bit vector for objects that are handled by the reset and the corresponding rights for the specified user.
 * </description>
 * <param name="hUser" type="IN">User handle of the current user.</param>
 * <param name="pui32ResetOriginConfigOptions" type="OUT">Required: Pointer to the Configuration bit vector representing the possible objects that are handled. See category "Reset Origin Configuration".</param>
 * <param name="pui32ResetOriginConfigRights" type="OUT">Optional: pointer to the bit vector indicating the access rights for the specified user to delete the objects represented in pui32ResetOriginConfigOptions
 *		(bit=0: the current user is allowed to delete the corresponding object, bit=1: the user is not allowed to delete the corresponding object).</param>
 * <result>
 *	<ul>
 *		<li>ERR_OK: Configuration retrieved successfully</li>
 *		<li>ERR_PARAMETER: pui32ResetOriginConfigOptions is NULL</li>
 *	</ul>
 * </result>
*/
DEF_ITF_API(`RTS_RESULT',`CDECL', `DevResetOriginGetConfig',`(RTS_HANDLE hUser, RTS_UI32 *pui32ResetOriginConfigOptions, RTS_UI32 *pui32ResetOriginConfigRights)')


#ifdef __cplusplus
}
#endif
