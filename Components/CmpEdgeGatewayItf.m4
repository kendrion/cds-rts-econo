/**
 * <interfacename>CmpEdgeGateway</interfacename>
 * <description>
 *	Interface for Edge Gateway component.
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`CmpEdgeGateway')

REF_ITF(`CmpSrvItf.m4')

#ifndef CDECL
	#define CDECL
#endif

/**
 * <category>LogFilter masks</category>
 * <description>Mask to filter debug outputs module or scope specific</description>
 */

#define LFM_EDGE_MASK                                       0x00000FFF

#define LFM_EDGE_COMMON										0x00000001
#define LFM_EDGE_SERVICES                                   0x00000002
#define LFM_EDGE_CONNECTION                                 0x00000004
#define LFM_EDGE_SESSION                                    0x00000008

#define LFM_EDGE_SG_HANDSHAKE                               0x00000010
#define LFM_EDGE_SG_SESSION                                 0x00000020
#define LFM_EDGE_SG_EDGESERVICES                            0x00000040
#define LFM_EDGE_SG_PLCMANAGEMENT                           0x00000080
#define LFM_EDGE_SG_VARACCESS                               0x00000100


/**
 * <category>Maintenance Mode</category>
 * <description>These defines represent different options of the maintenance mode of the edge gateway.</description>
 */
#define CMPEDGEGATEWAY_MAINTENANCE_DEACTIVATED				0
#define CMPEDGEGATEWAY_MAINTENANCE_ALLOWD					1
#define CMPEDGEGATEWAY_MAINTENANCE_FINISHED					2
#ifndef CMPEDGEGATEWAY_MAINTENANCE_DURATION
	#define CMPEDGEGATEWAY_MAINTENANCE_DURATION					30*60*1000 /* Activate the maintenance mode for 30 minutes */
#endif


 

/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>Configure the server URL the edge gateway connects to.</description>
 */
#define CMPEDGEGATEWAY_INT_SERVER_COMM_STATE_KEY				"CommunicationState"
#ifndef CMPEDGEGATEWAY_INT_SERVER_COMM_STATE_DEFALT	
	#define CMPEDGEGATEWAY_INT_SERVER_COMM_STATE_DEFALT			0
#endif

#define CMPEDGEGATEWAY_INT_RECONNECT_TIME_KEY					"ReconnectTime"
#ifndef CMPEDGEGATEWAY_INT_RECONNECT_TIME_DEFAULT	
	#define CMPEDGEGATEWAY_INT_RECONNECT_TIME_DEFAULT			30
#endif

#define CMPEDGEGATEWAY_INT_KEEPALIVE_TIME_KEY					"KeepaliveTime"
#ifndef CMPEDGEGATEWAY_INT_KEEPALIVE_TIME_DEFAULT	
	#define CMPEDGEGATEWAY_INT_KEEPALIVE_TIME_DEFAULT			10
#endif

#define CMPEDGEGATEWAY_INT_MAX_SESSIONS_KEY						"MaxSessions"
#ifndef CMPEDGEGATEWAY_INT_MAX_SESSIONS_DEFAULT	
	#define CMPEDGEGATEWAY_INT_MAX_SESSIONS_DEFAULT				4
#endif

#define CMPEDGEGATEWAY_INT_MAX_ACTIVE_SESSIONS_KEY				"MaxActiveSessions"
#ifndef CMPEDGEGATEWAY_INT_MAX_ACTIVE_SESSIONS_DEFAULT	
	#define CMPEDGEGATEWAY_INT_MAX_ACTIVE_SESSIONS_DEFAULT		2
#endif

#define CMPEDGEGATEWAY_INT_SESSION_REACTIVATE_TIMEOUT_KEY		"SessionReactivateTimeout"
#ifndef CMPEDGEGATEWAY_INT_SESSION_REACTIVATE_TIMEOUT_DEFAULT	
	#define CMPEDGEGATEWAY_INT_REACTIVATE_TIMEOUT_TIMEOUT_DEFAULT 3600
#endif

#define CMPEDGEGATEWAY_INT_MESSAGE_SIZE_KEY						"MessageSize"
#ifndef CMPEDGEGATEWAY_INT_MESSAGE_SIZE_DEFAULT	
	#define CMPEDGEGATEWAY_INT_MESSAGE_SIZE_DEFAULT				102400
#endif

#define CMPEDGEGATEWAY_INT_MAX_PLCS_KEY							"MaxPlcs"
#ifndef CMPEDGEGATEWAY_INT_MAX_PLCS_DEFAULT	
	#define CMPEDGEGATEWAY_INT_MAX_PLCS_DEFAULT					100
#endif

#define CMPEDGEGATEWAY_INT_MAX_REQUESTS_KEY						"MaxRequests"
#ifndef CMPEDGEGATEWAY_INT_MAX_REQUESTS_DEFAULT	
	#define CMPEDGEGATEWAY_INT_MAX_REQUESTS_DEFAULT				10
#endif

#define CMPEDGEGATEWAY_INT_MAX_NOTIFICATIONS_KEY				"MaxNotifications"
#ifndef CMPEDGEGATEWAY_INT_MAX_NOTIFICATIONS_DEFAULT	
	#define CMPEDGEGATEWAY_INT_MAX_NOTIFICATIONS_DEFAULT		100
#endif

#define CMPEDGEGATEWAY_INT_NOTIFICATION_INHIGIT_TIME_KEY		"NotificationInhibitTime"
#ifndef CMPEDGEGATEWAY_INT_NOTIFICATION_INHIGIT_TIME_DEFAULT	
	#define CMPEDGEGATEWAY_INT_NOTIFICATION_INHIGIT_TIME_DEFAULT 500
#endif

#define CMPEDGEGATEWAY_INT_CONNECTION_TIMEOUT_KEY				"ConnectionTimeout"
#ifndef CMPEDGEGATEWAY_INT_CONNECTION_TIMEOUT_DEFAULT	
	#define CMPEDGEGATEWAY_INT_CONNECTION_TIMEOUT_DEFAULT		60
#endif

#define CMPEDGEGATEWAY_INT_CONFIGURATION_FINISHED_KEY			"ConfigurationFinished"
#ifndef CMPEDGEGATEWAY_INT_CONFIGURATION_FINISHED_DEFALT	
	#define CMPEDGEGATEWAY_INT_CONFIGURATION_FINISHED_DEFALT	0
#endif

#define CMPEDGEGATEWAY_INT_MAINTENANCEMODE_KEY					"MaintenanceMode"
#ifndef CMPEDGEGATEWAY_INT_MAINTENANCEMODE_DEFALT	
	#define CMPEDGEGATEWAY_INT_MAINTENANCEMODE_DEFALT			CMPEDGEGATEWAY_MAINTANANCE_DEACTIVATED
#endif

#define CMPEDGEGATEWAY_CAS_PREFIX								"Cas"

#define CMPEDGEGATEWAY_INT_NO_OF_CAS_KEY						"NumberOfServers"
#ifndef CMPEDGEGATEWAY_INT_NO_OF_CAS_DEFAULT	
	#define CMPEDGEGATEWAY_INT_NO_OF_CAS_DEFAULT				0
#endif
 
#define CMPEDGEGATEWAY_STRING_SERVER_URL_KEY					"Url"
#ifndef CMPEDGEGATEWAY_STRING_SERVER_URL_DEFAULT	
	#define CMPEDGEGATEWAY_STRING_SERVER_URL_DEFAULT			""
#endif

#define CMPEDGEGATEWAY_STRING_CIPHER_SUITE_KEY					"CipherSuite"
#ifndef CMPEDGEGATEWAY_STRING_CIPHER_SUITE_DEFAULT	
	#define CMPEDGEGATEWAY_STRING_CIPHER_SUITE_DEFAULT			""
#endif

#define CMPEDGEGATEWAY_STRING_CERT_THUMBPRINT_KEY				"CertThumbprint"
#ifndef CMPEDGEGATEWAY_STRING_CERT_THUMBPRINT_DEFAULT	
	#define CMPEDGEGATEWAY_STRING_CERT_THUMBPRINT_DEFAULT		""
#endif

#define CMPEDGEGATEWAY_STRING_HTTP_PROXY_KEY					"HttpProxy"
#ifndef CMPEDGEGATEWAY_STRING_HTTP_PROXY_DEFAULT	
	#define CMPEDGEGATEWAY_STRING_HTTP_PROXY_DEFAULT			""
#endif

#define CMPEDGEGATEWAY_INT_HTTP_PROXY_PORT_KEY					"HttpProxyPort"
#ifndef CMPEDGEGATEWAY_INT_HTTP_PROXY_PORT_DEFAULT	
	#define CMPEDGEGATEWAY_INT_HTTP_PROXY_PORT_DEFAULT			80
#endif

#define CMPEDGEGATEWAY_STRING_HTTP_PROXY_USER_KEY				"HttpProxyUser"
#ifndef CMPEDGEGATEWAY_STRING_HTTP_PROXY_USER_DEFAULT	
	#define CMPEDGEGATEWAY_STRING_HTTP_PROXY_USER_DEFAULT		""
#endif

#define CMPEDGEGATEWAY_STRING_HTTP_PROXY_PASSWORD_KEY			"HttpProxyPassword"
#ifndef CMPEDGEGATEWAY_STRING_HTTP_PROXY_PASSWORD_DEFAULT	
	#define CMPEDGEGATEWAY_STRING_HTTP_PROXY_PASSWORD_DEFAULT	""
#endif

/**
 * <category>Features</category>
 * <type>Int</type>
 * <description>
 *	Feature to indicate that the Edge Gateway is available in this runtime.
 * </description>
 */
#define EDGEGATEWAY_IS_AVAILABLE		0x00000001
#define EDGEGATEWAY_IS_CONFIGURABLE		0x00000002

typedef enum
{
	EDGE_SIGNATURE_RSA_PSS_SHA256 = 1,
	EDGE_SIGNATURE_ALGORITHM_MAX
} EDGE_SIGNATURE_ALGORITHM;

#define EDGE_MESSAGE_SIZE_MIN			16384
#define EDGE_MESSAGE_SIZE_MAX			524288

#define EDGE_PROTOCOL_VERSION_MIN		0x00010000
#define EDGE_PROTOCOL_VERSION_MAX		0x00010001

#define EDGE_CONNECTION_TIMEOUT_MIN		5
#define EDGE_CONNECTION_TIMEOUT_MAX		600

#define EDGE_WEBSOCK_PROTO 				"edgegw.codesys.com"


/* Header used for CAS - Edge communication */
typedef struct
{
	RTS_UI16 ui16HeaderTag;			/* Always 0xED6E to identify the Edge protocol */
	RTS_UI16 ui16HeaderLength;		/* Length of the header without ui16HeaderTag and ui16HeaderLength */
	RTS_UI16 ui16ServiceGroup;		/* Service group of Edge */
	RTS_UI16 ui16Service;			/* Service of Edge */
	RTS_UI32 ui32SessionId;			/* Id of the session the request belongs to */
	RTS_UI32 ui32ServiceLength;		/* Length of data following after this header */ 
	RTS_UI16 ui16CustomerId;		/* Reserved, must be set to 0x0000 -> 3S */
	RTS_UI16 ui16Result; 			/* Global service result code (RTS_RESULT): Only used for responses and notifications, must be set to 0x0000 in all other cases. */
	RTS_UI32 ui32MessageId;			/* Id to identify a message */
	RTS_UI32 ui32MessageIdAck;		/* Id to acknowledge received messages */
	RTS_UI32 ui32ContextId;			/* Id to assign responses and notifications to a request */
	RTS_UI64 ui64Timestamp;			/* Message UTC timestamp in milliseconds since 01.01.1970 00:00:00.000 */
} HEADER_TAG_EDGE;


/* Flags for services to identify the message  */
#define EDGESV_TYPE_MASK					0xC000  /* The 2 highest bits of the service are used to identify the message type */
#define EDGESV_SERVICE_MASK					~EDGESV_TYPE_MASK /* The remaining bits containing the service */
#define EDGESV_TYPE_REQUEST					0x0000  /* 00: Request */
#define EDGESV_TYPE_RESPONSE				0x8000  /* 10: Response */
#define EDGESV_TYPE_NOTIFICATION			0x4000  /* 01: Notification */
#define EDGESV_TYPE_RESERVED				0xC000  /* 11: reserved for future use*/

/* Flags for notification types */
#define EDGENT_PLC					0x00000001	/* Bit 1: PLC status */
#define EDGENT_APPLICATION			0x00000002  /* Bit 2: Application change and status */


/**
 * <category>Edge service groups</category>
 */
#define EDGESG_MAX_SERVICE_GROUP			0x0FFF 	/* Highest service group number to be used */
#define EDGESV_MAX_SERVICE 					0x0FFF 	/* Highest service number to be used */

#define EDGESG_HANDSHAKE 					0x0001 	/* Requests for handshake, communication is started by the Edge */
#define EDGESG_SESSION   					0x0002 	/* Session handling */
#define EDGESG_ACK							0x0003 	/* Acknowledge  */
#define EDGESG_EDGE_SERVICES				0x0004 	/* Echo, ... */
#define EDGESG_PLC_MANAGEMENT				0x0005 	/* Network scan, PLC lists, SyncSendService ...*/
#define EDGESG_PLC_VAR_ACCESS  				0x0006 	/* IecVarAccess services  */

/*
 * Protocol Hints:
 * ---------------
 *
 * 1. Data type ByteArray: The effective length of the byte array is encoded as RTS_UI32 in front of the data itself. [4 Byte length][x Bytes data]
 * 2. Strings: Strings are encoded with NUL termination.
 * 3. MemberString: The effective length of the string is encoded as RTS_UI16 in front of the data itself, including the NUL termination. [2 Byte length][x Number of characters + 1]
 * 4. MemberWString: The effective length of the wstring is encoded as RTS_UI16 in front of the data itself, including the NUL termination. [2 Byte length][x Number of RTS_WCHAR + 1]
 */

/**
 * <category>Service group EDGESG_HANDSHAKE</category>
 * <service group="EDGESG_HANDSHAKE" id="EDGESV_HANDSHAKE_HELLO" name="Hello"
 *  description="Initial Handshake. The handshaking is started by the edge device.">
 *	<request>
 *		<tag id="TAG_EDGE_MAX_PROTO_VERSION" name="Max protocol version" cardinality="1..?" type="RTS_UI32"
 *		 description="Maximum protocol version supported by the edge gateway (high word: major version, low word: minor version)."/>
 *		<tag id="TAG_EDGE_TARGET_TYPE" name="Target type" cardinality="1..?" type="RTS_UI32"
 *		 description="Type of the device which contains the edge gateway."/>
 *		<tag id="TAG_EDGE_TARGET_ID" name="Target ID" cardinality="1..?" type="RTS_UI32"
 *		 description="ID of the device containing the edge gateway."/>
 *		<tag id="TAG_EDGE_TARGET_VERSION" name="Target version" cardinality="1..?" type="RTS_UI32"
 *		 description="Version of the device containing the edge gateway."/>
 *		<tag id="TAG_EDGE_CORE_VERSION" name="Core version" cardinality="1..?" type="RTS_UI32"
 *		 description="Version of the CmpEdgeGateway."/>
 *		<tag id="TAG_EDGE_MAX_MESSAGE_SIZE" name="Max message size" cardinality="1..?" type="RTS_UI32"
 *		 description="Maximum supported frame size of the edge gateway."/>
 *		<tag id="TAG_EDGE_CONNECTION_TIMEOUT" name="Connection timeout" cardinality="1..?" type="RTS_UI32"
 *		 description="Default channel timeout of the edge gateway."/>
 *		<tag id="TAG_EDGE_CERTIFICATE" name="Certificate" cardinality="1..?" type="String"
 *		 description="Base64 encoded edge certificate."/>
 *	</request>
 *	<response ackrequired="false">
 *		<tag id="TAG_EDGE_EFF_PROTO_VERSION" name="Effective protocol version" cardinality="1..?" type="RTS_UI32"
 *		 description="Effective protocol version used on this channel (high word: major version, low word: minor version)."/>
 *		<tag id="TAG_EDGE_EFF_MESSAGE_SIZE" name="Effective message size" cardinality="1..?" type="RTS_UI32"
 *		 description="Effective frame size used on this channel."/>
 *		<tag id="TAG_EDGE_EFF_CONNECTION_TIMEOUT" name="Effective connection timeout" cardinality="1..?" type="RTS_UI32"
 *		 description="Effective timeout of this channel."/>
 *		<tag id="TAG_EDGE_SIGNATURE_ALGORITHM" name="Signature algorithm" cardinality="1..?" type="RTS_UI32"
 *		 description="Identifies the algorithm used by the edge to sign the nonce."/>
 *		<tag id="TAG_EDGE_SERVER_NONCE" name="Server nonce" cardinality="1..?" type="ByteArray"
 *		 description="A random nonce generated by the automation server."/>
 *	</response>
 * </service>
 */
#define EDGESV_HANDSHAKE_HELLO 0x01

/**
 * <category>Service group EDGESG_HANDSHAKE</category>
 * <service group="EDGESG_HANDSHAKE" id="EDGESV_HANDSHAKE_CAPABILITIES" name="Capabilities"
 *  description="Second part of handshaking. Used to verify the edge identity and to negotiate the capabilities of the channel.">
 *	<request>
 *		<tag id="TAG_EDGE_SIGNATURE_ALGORITHM" name="Signature algorithm" cardinality="1..?" type="RTS_UI32"
 *		 description="ID of signing algorithm used."/>
 *		<tag id="TAG_EDGE_SIGNATURE" name="Signature" cardinality="1..?" type="ByteArray"
 *		 description="Nonce of server signed by edge."/>
 *		<tag id="TAG_EDGE_CAPABILITIES" name="Capabilities" cardinality="0..?" type="To be defined"
 *		 description="Capabilities of the edge device."/>
 *	</request>
 *	<response ackrequired="false">
 *		<tag id="TAG_EDGE_EFF_CAPABILITIES" name="Effective capabilities" cardinality="0..?" type="To be defined"
 *		 description="Effective capabilities selected by automation server."/>
 *	</response>
 * </service>
 */
#define EDGESV_HANDSHAKE_CAPABILITIES 0x02

/**
 * <category>Service group EDGESG_HANDSHAKE</category>
 * <service group="EDGESG_HANDSHAKE" id="EDGESV_HANDSHAKE_NEW_EDGE_CERT" name="New edge cert"
 *  description="Service to tell the automation server that a new edge certificate is available. This service is just acknowledged. ">
 *	<request>
 *		<tag id="TAG_EDGE_CERTIFICATE" name="Certificate" cardinality="1..?" type="String"
 *		 description="Base64 encoded edge certificate."/>
 *	</request>
 *	<response ackrequired="false"/>
 * </service>
 */
#define EDGESV_HANDSHAKE_NEW_EDGE_CERT 0x03

/**
 * <category>Service group EDGESG_HANDSHAKE</category>
 * <service group="EDGESG_HANDSHAKE" id="EDGESV_HANDSHAKE_PONG" name="Pong"
 *  description="PONG service used as keep alive on the channel. This request is sent by the CAS or edge after 1/3 of the connection timeout if not packet has been sent. No response is sent!">
 *	<request/>
 *	<response ackrequired="false"/>
 * </service>
 */
#define EDGESV_HANDSHAKE_PONG 0x04

#define TAG_EDGE_MAX_PROTO_VERSION			0x0001
#define TAG_EDGE_EFF_PROTO_VERSION			0x0002
#define TAG_EDGE_MAX_MESSAGE_SIZE			0x0003
#define TAG_EDGE_EFF_MESSAGE_SIZE			0x0004
#define TAG_EDGE_TARGET_TYPE				0x0005
#define TAG_EDGE_TARGET_ID					0x0006
#define TAG_EDGE_TARGET_VERSION				0x0007
#define TAG_EDGE_CORE_VERSION				0x0008
#define TAG_EDGE_CERTIFICATE				0x0009
#define TAG_EDGE_SERVER_NONCE				0x000A
#define TAG_EDGE_SIGNATURE_ALGORITHM		0x000B
#define TAG_EDGE_SIGNATURE					0x000C
#define TAG_EDGE_CAPABILITIES				0x000D
#define TAG_EDGE_EFF_CAPABILITIES			0x000E
#define TAG_EDGE_CONNECTION_TIMEOUT			0x000F
#define TAG_EDGE_EFF_CONNECTION_TIMEOUT		0x0010

/**
 * <category>Service group EDGESG_SESSION</category>
 * <service group="EDGESG_SESSION" id="EDGESV_SESSION_CREATE" name="Create"
 *  description="Service to create a session on the edge gateway which is used by the CAS.">
 *	<request>
 *		<tag id="TAG_EDGE_SERVER_SESSION_TOKEN" name="Server session token" cardinality="1..?" type="ByteArray"
 *		 description="A session token generated by the CAS for long term identification of the session."/>
 *	</request>
 *	<response ackrequired="false">
 *		<tag id="TAG_EDGE_SESSION_ID" name="Session id" cardinality="0..?" type="RTS_UI32"
 *		 description="Session ID generated by the edge gateway to identify active sessions."/>
 *	</response>
 * </service>
 */
#define EDGESV_SESSION_CREATE 0x01

/**
 * <category>Service group EDGESG_SESSION</category>
 * <service group="EDGESG_SESSION" id="EDGESV_SESSION_ACTIVATE" name="Activate"
 *  description="Service to create a activate a session on the edge gateway. After activation the session is able to handle services and send notifications.">
 *	<request>
 *		<tag id="TAG_EDGE_SERVER_SESSION_TOKEN" name="Server session token" cardinality="1..?" type="ByteArray"
 *		 description="A session token generated by the CAS for long term identification of the session."/>
 *		<tag id="TAG_EDGE_SESSION_LAST_ACK" name="Last ack" cardinality="1..?" type="RTS_UI32"
 *		 description="MessageID of the last received message by the CAS after a connection interrupt. See 8.14 for details."/>
 *	</request>
 *	<response ackrequired="false">
 *		<tag id="TAG_EDGE_SESSION_ID" name="Session id" cardinality="0..?" type="RTS_UI32"
 *		 description="Session ID generated by the edge gateway to identify active sessions."/>
 *		<tag id="TAG_EDGE_SESSION_LAST_ACK" name="Last ack" cardinality="0..?" type="RTS_UI32"
 *		 description="MessageID of the last received message by the edge gateway after a connection interrupt. See 8.14 for details."/>
 *	</response>
 * </service>
 */
#define EDGESV_SESSION_ACTIVATE 0x02

/**
 * <category>Service group EDGESG_SESSION</category>
 * <service group="EDGESG_SESSION" id="EDGESV_SESSION_DELETE" name="Delete"
 *  description="Service to delete a session. All resources are cleaned up.">
 *	<request>
 *		<tag id="TAG_EDGE_SERVER_SESSION_TOKEN" name="Server session token" cardinality="1..?" type="ByteArray"
 *		 description="Token of the session to delete."/>
 *	</request>
 *	<response ackrequired="false"/>
 * </service>
 */
#define EDGESV_SESSION_DELETE 0x04

/**
 * <category>Service group EDGESG_SESSION</category>
 * <service group="EDGESG_SESSION" id="EDGESV_SESSION_DELETE_ALL_INACTIVE" name="Delete all inactive"
 *  description="">
 *	<request/>
 *	<response>
 *		<tag id="TAG_EDGE_SESSION_COUNT" name="Session count" cardinality="" type=""
 *		 description=""/>
 *	</response>
 * </service>
 */
#define EDGESV_SESSION_DELETE_ALL_INACTIVE 0x05

#define TAG_EDGE_SERVER_SESSION_TOKEN		0x0001
#define TAG_EDGE_SESSION_ID					0x0002
#define TAG_EDGE_SESSION_LAST_ACK			0x0003
#define TAG_EDGE_SESSION_COUNT				0x0004

/**
 * <category>Service group EDGESG_ACK</category>
 * <service group="EDGESG_ACK" id="EDGESV_ACK_CAS" name="CAS"
 *  description="Acknowledge service sent from CAS to edge. Used to acknowledge services without sending a new request.">
 *	<request/>
 *	<response ackrequired="false"/>
 * </service>
 */
#define EDGESV_ACK_CAS 0x01

/**
 * <category>Service group EDGESG_ACK</category>
 * <service group="EDGESG_ACK" id="EDGESV_ACK_EDGE" name="Edge"
 *  description="Acknowledge service sent from edge to CAS. Used to acknowledge services without sending a new request.">
 *	<request/>
 *	<response ackrequired="false"/>
 * </service>
 */
#define EDGESV_ACK_EDGE 0x02

/**
 * <category>Service group EDGESG_EDGE_SERVICES</category>
 * <service group="EDGESG_EDGE_SERVICES" id="EDGESV_EDGE_ECHO" name="Echo">
 *	<description>
 *		Echo service. Receives services and sends replies with dummy bytes as payload. If the tag TAG_EDGE_ECHO_REPLY_DATA_LEN is omitted in
 *		the request, the server sends an empty service reply without any tag. If the requested reply length in TAG_EDGE_ECHO_REPLY_DATA_LEN
 *		exceeds the communication buffer, then the length is limited to a value, which completely fills the communication buffer. If the requested
 *		reply length is greater than the requested length, then dummy bytes are generated by the server. If not, the payload is copied starting from
 *		the beginning of the request payload in TAG_EDGE_ECHO_DATA.
 *	</description>
 *	<request>
 *		<tag id="TAG_EDGE_ECHO_REQUEST_DATA_LEN" name="Request data length" cardinality="0..?" type="RTS_UI32"
 *		 description="Length of tag content in TAG_EDGE_ECHO_DATA."/>
 *		<tag id="TAG_EDGE_ECHO_REPLY_DATA_LEN" name="Reply data length" cardinality="0..?" type="RTS_UI32"
 *		 description="Requested length of reply content in TAG_EDGE_ECHO_DATA."/>
 *		<tag id="TAG_EDGE_ECHO_DATA" name="Data" cardinality="0..?" type="char*"
 *		 description="Dummy bytes as payload."/>
 *	</request>
 *	<response ackrequired="false">
 *		<tag id="TAG_EDGE_ECHO_REPLY_DATA_LEN" name="Reply data length" cardinality="0..?" type="RTS_UI32"
 *		 description="Length of tag content in TAG_EDGE_ECHO_DATA."/>
 *		<tag id="TAG_EDGE_ECHO_DATA" name="Data" cardinality="0..?" type="char*"
 *		 description="Dummy bytes as payload."/>
 *	</response>
 * </service>
 */
#define EDGESV_EDGE_ECHO 0x01

/**
 * <category>Service group EDGESG_EDGE_SERVICES</category>
 * <service group="EDGESG_EDGE_SERVICES" id="EDGESV_EDGE_GET_TIME" name="Get time"
 *  description="Service to retrieve the UTC time in milliseconds since 01.01.1970 00:00:00.000">
 *	<request/>
 *	<response ackrequired="false">
 *		<tag id="TAG_EDGE_TIME_UTC" name="UTC time" cardinality="1..?" type="RTS_SYSTIME"
 *		 description="UTC time in milliseconds."/>
 *	</response>
 * </service>
 */
#define EDGESV_EDGE_GET_TIME 0x02

/**
 * <category>Service group EDGESG_EDGE_SERVICES</category>
 * <service group="EDGESG_EDGE_SERVICES" id="EDGESV_EDGE_SET_TIME" name="Set time"
 *  description="Service to set the UTC time in milliseconds since 01.01.1970 00:00:00.000">
 *	<request>
 *		<tag id="TAG_EDGE_TIME_UTC" name="UTC time" cardinality="1..?" type="RTS_SYSTIME"
 *		 description="UTC time in milliseconds."/>
 *	</request>
 *	<response ackrequired="false"/>
 * </service>
 */
#define EDGESV_EDGE_SET_TIME 0x03

#define TAG_EDGE_ECHO_REQUEST_DATA_LEN		0x0001
#define TAG_EDGE_ECHO_REPLY_DATA_LEN		0x0002
#define TAG_EDGE_ECHO_DATA					0x0003
#define TAG_EDGE_TIME_UTC					0x0004

/**
 * <category>Service group EDGESG_PLC_MANAGEMENT</category>
 * <service group="EDGESG_PLC_MANAGEMENT" id="EDGESV_PLCMGM_NETWORK_SCAN" name="Network scan"
 *  description="Service to initiate a network scan. Found devices are transmitted as notifications. An empty response is sent after the scan is completed.">
 *	<request>
 *		<tag id="TAG_EDGE_GATEWAY_CONFIG" name="Gateway config" cardinality="0..?" type="">
 *			<description>
 *				Gateway configuration (members of GatewayConnectionStruct as stream with content as follows):
 *				[MemberString]: 	pszDeviceName
 *				[MemberString]: 	pszAddress
 *				[RTS_UI32]:		ulPort
 *				[MemberString]: 	pszPassword
 *			</description>
 *		</tag>
 *	</request>
 *	<response ackrequired="false">
 *		<tag id="TAG_EDGE_SCAN_NOTIFICATION" name="Scan notification" cardinality="0..?" type="">
 *			<description>
 *				Information about found node (members of NodeInfotyp2 as stream with content as follows):			
 *				[MemberString]:	pszNodeAddr
 *				[MemberString]:	pszParentAddr
 *				[MemberWString]:	pwszNodeName
 *				[MemberWString]:	pwszDeviceName
 *				[MemberWString]:	pwszVendorName
 *				[RTS_UI32]:		ulTargetType
 *				[RTS_UI32]:		ulTargetId
 *				[RTS_UI32]:		ulTargetVersion
 *				[RTS_UI16]:		wMaxChannels
 *				[RTS_UI16]:		wReserved
 *				[MemberString]:	pszSerialNumber
 *				[ByteArray]:		pbyOemData
 *				[RTS_UI32]:		ulFlags
 *				[RTS_UI8]:			byIntelByteOrder
 *				[RTS_UI8]:			byReserved
 *				[RTS_UI16]:		wRtsBlkDrvType
 *				[RTS_UI16]:		wGwBlkDrvType
 *				[RTS_UI16]:		wGwRtsNsVersion
 *				[RTS_UI32]:		ulGwClientGwVersion
 *			</description>
 *		</tag>
 *	</response>
 * </service>
 */
#define EDGESV_PLCMGM_NETWORK_SCAN 0x01

/**
 * <category>Service group EDGESG_PLC_MANAGEMENT</category>
 * <service group="EDGESG_PLC_MANAGEMENT" id="EDGESV_PLCMGM_ADD_PLCS" name="Add PLCs">
 *	<description>
 *		Service to add PLCs to the Edge management. The service can consist of one group reference (optional) and several PLC references (at least one) with corresponding configuration.
 *		For each PLC a consecutive sequence of the configuration is expected, followed by optional gateway configuration and/or one ore more configuration parameters.
 *	</description>
 *	<request>
 *		<tag id="TAG_EDGE_GROUP_REFERENCE" name="Group reference" cardinality="0..?" type="RTS_UI64"
 *		 description="Group reference."/>
 *		<tag id="TAG_EDGE_PLC_REFERENCE" name="PLC reference" cardinality="1..?" type="RTS_UI64"
 *		 description="PLC reference (0=Invalid)."/>
 *		<tag id="TAG_EDGE_PLC_CONFIG" name="PLC config" cardinality="1..?" type="">
 *			<description>
 *				PLC configuration:
 *				[RTS_I32]:			it (value of ItfType enumeration)
 *				[RTS_UI32]:		ulTimeout (in ms)
 *				[RTS_UI32]:		ulNumTries
 *				[RTS_UI32]:		ulWaitTime (in ms)
 *				[RTS_UI32]:		ulReconnectTime (in ms)
 *			</description>
 *		</tag>
 *		<tag id="TAG_EDGE_GATEWAY_CONFIG" name="Gateway config" cardinality="0..?" type="">
 *			<description>
 *				Gateway configuration (members of GatewayConnectionStruct as stream with content as follows):
 *				[MemberString]:	pszDeviceName
 *				[MemberString]:	pszAddress
 *				[RTS_UI32]:		ulPort
 *				[MemberString]: pszPassword
 *			</description>
 *		</tag>
 *		<tag id="TAG_EDGE_PLC_CONFIG_PARAMETER" name="PLC config parameter" cardinality="0..?" type="">
 *			<description>
 *				PLC configuration parameter:
 *				[MemberString]:	pszName
 *				[RTS_I32]:			Type (value of PlcParameterType enumeration)
 *				[Type Dependent]:	Value
 *				NOTE: The combination pszName="Address", Type=PLC_PT_STRING, Value=NULL is internally handled as local connection to the Edge Gateway itself.
 *			</description>
 *		</tag>
 *		<tag id="TAG_EDGE_PLC_INFO" name="PLC info" cardinality="0..?" type="">
 *			<description>
 *				Additional PLC information:
 *				[RTS_UI32]:		ulTargetType (See category "Device Types" in SysTargetItf.h)
 *				[RTS_UI32]:		ulTargetId (HiWord = VendorID, LowWord = ID)
 *				[MemberString]:	pszSerialNumber
 *			</description>
 *		</tag>
 *	</request>
 *	<response ackrequired="true"/>
 * </service>
 */
#define EDGESV_PLCMGM_ADD_PLCS 0x02

/**
 * <category>Service group EDGESG_PLC_MANAGEMENT</category>
 * <service group="EDGESG_PLC_MANAGEMENT" id="EDGESV_PLCMGM_REMOVE_PLCS" name="Remove PLCs"
 *  description="Service to remove PLCs from the Edge management. The service can consist of one group reference or several PLC references.">
 *	<request>
 *		<tag id="TAG_EDGE_GROUP_REFERENCE" name="Group reference" cardinality="0..?" type="RTS_UI64"
 *		 description="Group reference."/>
 *		<tag id="TAG_EDGE_PLC_REFERENCE" name="PLC reference" cardinality="0..?" type="RTS_UI64"
 *		 description="PLC reference (0=Invalid)."/>
 *	</request>
 *	<response ackrequired="true"/>
 * </service>
 */
#define EDGESV_PLCMGM_REMOVE_PLCS 0x03

/**
 * <category>Service group EDGESG_PLC_MANAGEMENT</category>
 * <service group="EDGESG_PLC_MANAGEMENT" id="EDGESV_PLCMGM_CONNECT_PLC" name="Connect PLC"
 *  description="Service to connect to a PLC.">
 *	<request>
 *		<tag id="TAG_EDGE_PLC_REFERENCE" name="PLC reference" cardinality="1..?" type="RTS_UI64"
 *		 description="PLC Reference (0=Invalid)."/>
 *	</request>
 *	<response ackrequired="true">
 *		<tag id="TAG_EDGE_PLC_DEVICEINFO" name="PLC device info" cardinality="0..?" type="">
 *			<description>
 *				Device info if connection succeeded (members of DeviceInfo2 as stream with content as follows):
 *				[MemberString]:	pszNodeAddress
 *				[MemberWString]:	pwszNodeName
 *				[MemberWString]:	pwszTargetName
 *				[MemberWString]:	pwszTargetVendorName
 *				[MemberString]:	pszTargetVersion
 *				[RTS_UI32]:		ulTargetId
 *				[RTS_UI32]:		ulTargetType
 *				[RTS_UI32]:		ulBufferSize
 *				[RTS_UI32]:		DeviceSessionId
 *				[RTS_UI32]:		bMotorola
 *				[MemberString]:	pszTargetSerialNumber
 *				[MemberString]:	pszTargetCoreVersion
 *				[RTS_UI32]:		ulTargetIdentFlags
 *				[RTS_UI16]:		usTargetChannels
 *				[RTS_UI16]:		usNumOfIpAddresses
 *				pIpAddressList (usNumOfIpAddresses entries of following data:)
 *				[char[16]]			szIp
 *				[char[16]]			szMask
 *			</description>
 *		</tag>
 *		<tag id="TAG_EDGE_PLC_STATE" name="PLC state" cardinality="0..?" type="RTS_I16"
 *		 description="Only if an error occurred during connect: new state as value of enumeration type PLCHANDLER_STATE (8/9: error)."/>
 *		<tag id="TAG_EDGE_PLC_ERROR" name="PLC error" cardinality="0..?" type="RTS_I16"
 *		 description="Error code (see PLCHandlerDefines.h) if TAG_EDGE_PLC_STATE is an error state."/>
 *	</response>
 * </service>
 */
#define EDGESV_PLCMGM_CONNECT_PLC 0x04

/**
 * <category>Service group EDGESG_PLC_MANAGEMENT</category>
 * <service group="EDGESG_PLC_MANAGEMENT" id="EDGESV_PLCMGM_DISCONNECT_PLC" name="Disconnect PLC"
 *  description="Service to disconnect from a PLC.">
 *	<request>
 *		<tag id="TAG_EDGE_PLC_REFERENCE" name="PLC reference" cardinality="1..?" type="RTS_UI64"
 *		 description="PLC Reference (0=Invalid)."/>
 *	</request>
 *	<response ackrequired="true"/>
 * </service>
 */
#define EDGESV_PLCMGM_DISCONNECT_PLC 0x05

/**
 * <category>Service group EDGESG_PLC_MANAGEMENT</category>
 * <service group="EDGESG_PLC_MANAGEMENT" id="EDGESV_PLCMGM_SYNC_SEND_SERVICE" name="Sync send service"
 *  description="Service to send a synchronous CODESYS Control L7 service to a connected PLC.">
 *	<request>
 *		<tag id="TAG_EDGE_PLC_REFERENCE" name="PLC reference" cardinality="1..?" type="RTS_UI64"
 *		 description="PLC Reference (0=Invalid)."/>
 *		<tag id="TAG_EDGE_PLC_SYNCSENDSERVICE_DATA" name="Data" cardinality="1..?" type="ByteArray"
 *		 description="Byte stream which should be sent to the PLC."/>
 *	</request>
 *	<response ackrequired="true">
 *		<tag id="TAG_EDGE_PLC_SYNCSENDSERVICE_DATA" name="Data" cardinality="0..?" type="ByteArray"
 *		 description="Byte stream with the PLCs response for the sent service."/>
 *	</response>
 * </service>
 */
#define EDGESV_PLCMGM_SYNC_SEND_SERVICE 0x06

/**
 * <category>Service group EDGESG_PLC_MANAGEMENT</category>
 * <service group="EDGESG_PLC_MANAGEMENT" id="EDGESV_PLCMGM_ADD_PLCS_TO_GROUP" name="Add PLCs to group">
 *	<description>
 *		Service to add PLCs to a group. The service can consist of one group reference (required) and several PLC references (at least one).
 *		Each PLC has to be configured already by a previous use of the service EDGESV_PLCMGM_ADD_PLCS.
 *	</description>
 *	<request>
 *		<tag id="TAG_EDGE_GROUP_REFERENCE" name="Group reference" cardinality="1..?" type="RTS_UI64"
 *		 description="Group reference."/>
 *		<tag id="TAG_EDGE_PLC_REFERENCE" name="PLC reference" cardinality="1..?" type="RTS_UI64"
 *		 description="PLC reference (0=Invalid)."/>
 *	</request>
 *	<response ackrequired="true"/>
 * </service>
 */
#define EDGESV_PLCMGM_ADD_PLCS_TO_GROUP 0x07

/**
 * <category>Service group EDGESG_PLC_MANAGEMENT</category>
 * <service group="EDGESG_PLC_MANAGEMENT" id="EDGESV_PLCMGM_REMOVE_PLCS_FROM_GROUP" name="Remove PLCs from group"
 *  description="Service to remove PLCs from a group. The service can consist of one group reference (required) and several PLC references (at least one).">
 *	<request>
 *		<tag id="TAG_EDGE_GROUP_REFERENCE" name="Group reference" cardinality="1..?" type="RTS_UI64"
 *		 description="Group reference."/>
 *		<tag id="TAG_EDGE_PLC_REFERENCE" name="PLC reference" cardinality="1..?" type="RTS_UI64"
 *		 description="PLC reference (0=Invalid)."/>
 *	</request>
 *	<response ackrequired="true"/>
 * </service>
 */
#define EDGESV_PLCMGM_REMOVE_PLCS_FROM_GROUP 0x08

/**
 * <category>Service group EDGESG_PLC_MANAGEMENT</category>
 * <service group="EDGESG_PLC_MANAGEMENT" id="EDGESV_PLCMGM_GROUP_NOTIFY" name="Group notify">
 *	<description>
 *		Service to register/unregister notifications for a group. The desired notification types are specified as flags in a bit field (0: stop notify, 1: start notify). See flags for notification types (EDGENT_*) above.
 *		NOTE:	- Each notification contains the PLC reference of the corresponding PLC.
 *		- For each application, the tag TAG_EDGE_APP_NAME is sent, followed by tags TAG_EDGE_APP_* containing the information about the changes for this application.
 *	</description>
 *	<request>
 *		<tag id="TAG_EDGE_GROUP_REFERENCE" name="Group reference" cardinality="1..?" type="RTS_UI64"
 *		 description="Group reference."/>
 *		<tag id="TAG_EDGE_NOTIFICATION_TYPES" name="Notification types" cardinality="1..?" type="RTS_UI32"
 *		 description="Notification types as flag field (each type corresponds to a unique bit in this field). See flags for notification types (EDGENT_*) above."/>
 *	</request>
 *	<response ackrequired="true"/>
 *	<notification ackrequired="true">
 *		<tag id="TAG_EDGE_PLC_REFERENCE" name="PLC reference" cardinality="1..?" type="RTS_UI64"
 *		 description="PLC reference (0=Invalid)."/>
 *		<tag id="TAG_EDGE_PLC_STATE" name="PLC state" cardinality="0..?" type="RTS_I16"
 *		 description="New state as value of enum type PLCHANDLER_STATE (4: running, 8/9: error, 0: not running)."/>
 *		<tag id="TAG_EDGE_PLC_DEVICEINFO" name="PLC device info" cardinality="0..?" type=""
 *		 description="Device info if new state is connected (see description of EDGESV_PLCMGM_CONNECT_PLC for detailed structure of the tag content)."/>
 *		<tag id="TAG_EDGE_APP_NUM_OF_APPS" name="Number of apps" cardinality="0..?" type="RTS_UI32"
 *		 description="Number of applications."/>
 *		<tag id="TAG_EDGE_APP_NAME" name="App name" cardinality="0..?" type="MemberString"
 *		 description="Application name."/>
 *		<tag id="TAG_EDGE_APP_DELETED" name="App deleted" cardinality="0..?" type="Empty"
 *		 description="Application has been removed."/>
 *		<tag id="TAG_EDGE_APP_INFO_LAST_CHANGE" name="Last change" cardinality="0..?" type="RTS_UI32"
 *		 description="ulLastChanges (UTC time in seconds since 1.1.1970 00:00:00)."/>
 *		<tag id="TAG_EDGE_APP_INFO_PROJECT" name="Project" cardinality="0..?" type="MemberString"
 *		 description="pszProject."/>
 *		<tag id="TAG_EDGE_APP_INFO_VERSION" name="Version" cardinality="0..?" type="MemberString"
 *		 description="pszVersion."/>
 *		<tag id="TAG_EDGE_APP_INFO_AUTHOR" name="Author" cardinality="0..?" type="MemberString"
 *		 description="pszAuthor."/>
 *		<tag id="TAG_EDGE_APP_INFO_DESCRIPTION" name="Description" cardinality="0..?" type="MemberString"
 *		 description="pszDescription."/>
 *		<tag id="TAG_EDGE_APP_INFO_PROFILE" name="Profile" cardinality="0..?" type="MemberString"
 *		 description="pszProfile."/>
 *		<tag id="TAG_EDGE_APP_INFO_CODE_GUID" name="Code GUID" cardinality="0..?" type="ByteArray"
 *		 description="CodeGuid."/>
 *		<tag id="TAG_EDGE_APP_INFO_DATA_GUID" name="Data GUID" cardinality="0..?" type="ByteArray"
 *		 description="DataGuid."/>
 *		<tag id="TAG_EDGE_APP_STATUS" name="App status" cardinality="0..?" type="RTS_I16"
 *		 description="New application status as value of enumeration type PLC_STATUS_ENUM."/>
 *		<tag id="TAG_EDGE_PLC_ERROR" name="PLC error" cardinality="0..?" type="RTS_I16"
 *		 description="Error code (see PLCHandlerDefines.h) if TAG_EDGE_PLC_STATE is an error state."/>
 *	</notification>
 * </service>
 */
#define EDGESV_PLCMGM_GROUP_NOTIFY 0x09

#define TAG_EDGE_GATEWAY_CONFIG				0x0001
#define TAG_EDGE_SCAN_NOTIFICATION			0x0002
#define TAG_EDGE_GROUP_REFERENCE			0x0003
#define TAG_EDGE_PLC_REFERENCE				0x0004
#define TAG_EDGE_PLC_CONFIG					0x0005
#define TAG_EDGE_PLC_CONFIG_PARAMETER		0x0006
#define TAG_EDGE_PLC_DEVICEINFO				0x0007
#define TAG_EDGE_PLC_SYNCSENDSERVICE_DATA	0x0008
#define TAG_EDGE_NOTIFICATION_TYPES			0x0009
#define TAG_EDGE_PLC_STATE					0x000A
#define TAG_EDGE_APP_NAME					0x000B
#define TAG_EDGE_APP_INFO_LAST_CHANGE		0x000C
#define TAG_EDGE_APP_INFO_PROJECT			0x000D
#define TAG_EDGE_APP_INFO_VERSION			0x000E
#define TAG_EDGE_APP_INFO_AUTHOR			0x000F
#define TAG_EDGE_APP_INFO_DESCRIPTION		0x0010
#define TAG_EDGE_APP_INFO_PROFILE			0x0011
#define TAG_EDGE_APP_INFO_CODE_GUID			0x0012
#define TAG_EDGE_APP_INFO_DATA_GUID			0x0013
#define TAG_EDGE_APP_STATUS					0x0014
#define TAG_EDGE_APP_DELETED				0x0015
#define TAG_EDGE_APP_NUM_OF_APPS			0x0016
#define TAG_EDGE_PLC_ERROR					0x0017
#define TAG_EDGE_PLC_INFO					0x0018

/**
 * <category>Service group EDGESG_PLC_VAR_ACCESS</category>
 * <Description>
 *		Services of the service group EDGESG_PLC_MANAGEMENT shall be usable in this group also.
 *		So we start with tag id 0x40 to leave space for future services in the group EDGESG_PLC_MANAGEMENT.
 * </Description>
 */

/**
 * <category>Service group EDGESG_PLC_VAR_ACCESS</category>
 * <service group="EDGESG_PLC_VAR_ACCESS" id="EDGESV_VAR_DEFINE_VARLIST" name="Define var list"
 *  description="Service to define a variable list. Value changes of the defined variables are sent as notification. A notification can contain several changes.">
 *	<request>
 *		<tag id="TAG_EDGE_PLC_REFERENCE" name="PLC reference" cardinality="1..?" type="RTS_UI64"
 *		 description="PLC reference (0=Invalid)."/>
 *		<tag id="TAG_EDGE_VARLIST_REFERENCE" name="Variable list reference" cardinality="1..?" type="RTS_UI64"
 *		 description="Variable list reference."/>
 *		<tag id="TAG_EDGE_VARLIST_UPDATERATE" name="Update rate" cardinality="0..?" type="RTS_UI32"
 *		 description="Update rate for the cyclic update of the variable values in ms (default: 200)."/>
 *		<tag id="TAG_EDGE_VARLIST_FLAGS" name="Flags" cardinality="0..?" type="RTS_UI32"
 *		 description="Flags for the variable list (e. g. consistency flags)."/>
 *		<tag id="TAG_EDGE_VARLIST_NUMOFSYMBOLS" name="Number of symbols" cardinality="1..?" type="RTS_UI32"
 *		 description="Number of symbols in the list."/>
 *		<tag id="TAG_EDGE_VARLIST_SYMBOLS" name="Symbols" cardinality="1..?" type="">
 *			<description>
 *				List of symbols as array (the number of array elements has to match to the number of symbols). Each array element has following members:
 *				[RTS_UI32]:		ulTypeId (see PlcSymbolDescStruct.ulTypeId)
 *				[RTS_UI32]:		ulSize (see PlcSymbolDescStruct.ulSize)
 *				[MemberString]:	pszSymbol (name of the symbol)
 *			</description>
 *		</tag>
 *	</request>
 *	<response ackrequired="true"/>
 *	<notification ackrequired="true">
 *		<tag id="TAG_EDGE_VARLIST_REFERENCE" name="Var list reference" cardinality="1..?" type="RTS_UI64"
 *		 description="Variable list reference."/>
 *		<tag id="TAG_EDGE_VAR_INDEX" name="Index" cardinality="0..?" type="RTS_UI32"
 *		 description="Start index of the symbol in the variable list (default: 0)."/>
 *		<tag id="TAG_EDGE_VAR_READ_VALUES" name="Read values" cardinality="1..?" type="">
 *			<description>
 *				List of Values (members of PlcVarValueStruct as stream with content as follows):
 *				[RTS_UI32]:		ulTimeStamp (Seconds since 1.1.1970 00:00:00 UTC)		
 *				[RTS_UI8]:		bQuality
 *				[ByteArray]:	byData
 *			</description>
 *		</tag>
 *	</notification>
 * </service>
 */
#define EDGESV_VAR_DEFINE_VARLIST 0x01

/**
 * <category>Service group EDGESG_PLC_VAR_ACCESS</category>
 * <service group="EDGESG_PLC_VAR_ACCESS" id="EDGESV_VAR_DELETE_VARLIST" name=""
 *  description="Service to delete a variable list.">
 *	<request>
 *		<tag id="TAG_EDGE_PLC_REFERENCE" name="PLC reference" cardinality="1..?" type="RTS_UI64"
 *		 description="PLC reference (0=Invalid)."/>
 *		<tag id="TAG_EDGE_VARLIST_REFERENCE" name="Variable list reference" cardinality="1..?" type="RTS_UI64"
 *		 description="Variable list reference."/>
 *	</request>
 *	<response ackrequired="true"/>
 * </service>
 */
#define EDGESV_VAR_DELETE_VARLIST 0x02

/**
 * <category>Service group EDGESG_PLC_VAR_ACCESS</category>
 * <service group="EDGESG_PLC_VAR_ACCESS" id="EDGESV_VAR_READ_VARLIST" name=""
 *  description="Service to read variables from a list.">
 *	<request>
 *		<tag id="TAG_EDGE_PLC_REFERENCE" name="PLC reference" cardinality="1..?" type="RTS_UI64"
 *		 description="PLC reference (0=Invalid)."/>
 *		<tag id="TAG_EDGE_VARLIST_REFERENCE" name="Variable list reference" cardinality="1..?" type="RTS_UI64"
 *		 description="Variable list reference."/>
 *	</request>
 *	<response ackrequired="false">
 *		<tag id="TAG_EDGE_VAR_READ_VALUES" name="Read values" cardinality="1..?" type=""
 *		 description="List of Values as array (see description of EDGESV_VAR_DEFINE_VARLIST for detailed structure of the tag content)."/>
 *	</response>
 * </service>
 */
#define EDGESV_VAR_READ_VARLIST 0x03

/**
 * <category>Service group EDGESG_PLC_VAR_ACCESS</category>
 * <service group="EDGESG_PLC_VAR_ACCESS" id="EDGESV_VAR_WRITE_VARS" name=""
 *  description="Service to write variables.">
 *	<request>
 *		<tag id="TAG_EDGE_PLC_REFERENCE" name="PLC reference" cardinality="1..?" type="RTS_UI64"
 *		 description="PLC reference (0=Invalid)."/>
 *		<tag id="TAG_EDGE_VARLIST_NUMOFSYMBOLS" name="Number of symbols" cardinality="1..?" type="RTS_UI32"
 *		 description="Number of values to write (must match to the size of the following lists)."/>
 *		<tag id="TAG_EDGE_VARLIST_SYMBOLS" name="Symbols" cardinality="1..?" type=""
 *		 description="List of symbols (see description of EDGESV_VAR_DEFINE_VARLIST for detailed structure of the tag content)."/>
 *		<tag id="TAG_EDGE_VAR_VALUES_TO_WRITE" name="Values to write" cardinality="1..?" type="Array of ByteArray"
 *		 description="List of the variables values."/>
 *	</request>
 *	<response ackrequired="true"/>
 * </service>
 */
#define EDGESV_VAR_WRITE_VARS 0x04

#define TAG_EDGE_VARLIST_REFERENCE			0x0040
#define TAG_EDGE_VARLIST_UPDATERATE			0x0041
#define TAG_EDGE_VARLIST_FLAGS				0x0042
#define TAG_EDGE_VARLIST_NUMOFSYMBOLS		0x0043
#define TAG_EDGE_VARLIST_SYMBOLS			0x0044
#define TAG_EDGE_VAR_INDEX					0x0045
#define TAG_EDGE_VAR_READ_VALUES			0x0046
#define TAG_EDGE_VAR_VALUES_TO_WRITE		0x0047

#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description>
 *	Routine to check whether the edge gateway component has the specified feature.
 * </description>
 * <param name="ulFeatures" type="IN">Feature flags, See corresponding category "Features".</param>
 * <result>ERR_OK if the flags are supported, an error code otherwise</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`EdgeGatewayHasFeature',`(RTS_UI32 ulFeatures)')

#ifdef __cplusplus
}
#endif