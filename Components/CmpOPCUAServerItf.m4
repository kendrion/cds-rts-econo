/**
 * <interfacename>CmpOPCUAServer</interfacename>
 * <description></description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`CmpOPCUAServer')
REF_ITF(`CmpOPCUAProviderItf.m4')
REF_ITF(`CmpSecurityManagerItf.m4')
REF_ITF(`CmpEventMgrItf.m4')

#include "opcua.h"

/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>Configure the name network adapter to be used by the OPC UA server. By Default OPC UA will bind to ANY address.</description>
 */
#define CMPOPCUAKEY_STRING_NETWORK_ADAPTER					"NetworkAdapter"
#ifndef CMPOPCUAVALUE_STRING_NETWORK_ADAPTER_DEFAULT	
	#define CMPOPCUAVALUE_STRING_NETWORK_ADAPTER_DEFAULT	""
#endif

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>Configure the port used by the OPC UA server. Default: 4840</description>
 */
#define CMPOPCUAKEY_INT_NETWORK_PORT						"NetworkPort"
#ifndef CMPOPCUAVALUE_INT_NETWORK_PORT_DEFAULT
	#define CMPOPCUAVALUE_INT_NETWORK_PORT_DEFAULT			4840
#endif

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>Use this setting to add the loop-back adapter as an OPC UA endpoint if it is missing in your configuration.</description>
 */
#define CMPOPCUAKEY_INT_USE_LOOPBACK						"UseLoopback"
#ifndef CMPOPCUAVALUE_INT_USE_LOOPBACK_DEFAULT	
	#define CMPOPCUAVALUE_INT_USE_LOOPBACK_DEFAULT			1
#endif

 /**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>Use this setting to set the network adapter update rate in ms. This rate is used to rescan the adapters and to add / remove the adapters.</description>
 */
#define CMPOPCUASERVERKEY_INT_ADAPTER_UPDATE_RATE						"AdapterUpdateRate"
#ifndef CMPOPCUASERVERVALUE_INT_ADAPTER_UPDATE_RATE_DEFAULT
#define CMPOPCUASERVERVALUE_INT_ADAPTER_UPDATE_RATE_DEFAULT		5000
#endif

 /**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>Use this setting to set the minimum sampling rate of monitored items in ms.</description>
 */
#define CMPOPCUASERVERKEY_INT_ITEM_MIN_SAMPLING_RATE					"ItemMinSamplingRate"
#ifndef CMPOPCUASERVERVALUE_INT_ITEM_MIN_SAMPLING_RATE_DEFAULT
#define CMPOPCUASERVERVALUE_INT_ITEM_MIN_SAMPLING_RATE_DEFAULT			100
#endif

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>Use this setting to configure how many worker tasks are created. The default of -1 will create between 1 and <Num of CPU-cores> - 1 
 * worker tasks. The worker tasks are responsible to to the sampling of monitored items.</description>
 */
#define CMPOPCUASERVERKEY_INT_NUM_OF_WORKERS					"NumOfWorkerTasks"
#ifndef CMPOPCUASERVERVALUE_INT_NUM_OF_WORKERS_DEFAULT
#define CMPOPCUASERVERVALUE_INT_NUM_OF_WORKERS_DEFAULT			-1
#endif


/**
 * <category>SecuritySettings</category>
 * <description>Available security policies.</description>
 * <element name="CmpOPCUAServer_SecurityPolicy_Basic128Rsa15" type="IN">Support of http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15 and higher</element>
 * <element name="CmpOPCUAServer_SecurityPolicy_Basic256" type="IN">Support of http://opcfoundation.org/UA/SecurityPolicy#Basic256 and higher</element>
 * <element name="CmpOPCUAServer_SecurityPolicy_Basic256Sha256" type="IN">Support of http://opcfoundation.org/UA/SecurityPolicy#Basic256Sha256 and higher</element>
 */
#define CMPOPCUASERVER_KEY_STRING_POLICY					CMPSETTINGS_CATEGORY_SECURITY ".CommunicationPolicy"
#define CMPOPCUASERVER_KEY_STRING_POLICY_DESC				"Policy for communication"

#define CMPOPCUASERVER_VALUE_POLICY_BASIC256SHA256			"POLICY_BASIC256SHA256"
#define CMPOPCUASERVER_VALUE_POLICY_BASIC256				"POLICY_BASIC256"
#define CMPOPCUASERVER_VALUE_POLICY_BASIC128RSA15			"POLICY_BASIC128RSA15"

 typedef enum
 {
    CmpOPCUAServer_SecurityPolicy_Basic128Rsa15,
    CmpOPCUAServer_SecurityPolicy_Basic256,
    CmpOPCUAServer_SecurityPolicy_Basic256Sha256
 } CmpOPCUAServer_SecurityPolicy;

#if !CMPOPCUASTACK_ALLOW_SHA1_BASED_SECURITY
#ifndef CMPOPCUASERVER_VALUE_POLICY_DEFAULT
	#define CMPOPCUASERVER_VALUE_POLICY_DEFAULT				CMPOPCUASERVER_VALUE_POLICY_BASIC256SHA256
#endif
#define CMPOPCUASERVER_VALUE_POLICY_LIST					{ \
																{(RTS_I32)CmpOPCUAServer_SecurityPolicy_Basic256Sha256, CMPSECMAN_SFLAGS_NONE, CMPOPCUASERVER_VALUE_POLICY_BASIC256SHA256, "Support for all policies beginning with Basic256Sha256 (AES 256 with SHA256) [By now highest security]"}\
															}
#else
#ifndef CMPOPCUASERVER_VALUE_POLICY_DEFAULT
	#define CMPOPCUASERVER_VALUE_POLICY_DEFAULT				CMPOPCUASERVER_VALUE_POLICY_BASIC128RSA15
#endif
#define CMPOPCUASERVER_VALUE_POLICY_LIST					{ \
																{(RTS_I32)CmpOPCUAServer_SecurityPolicy_Basic256Sha256, CMPSECMAN_SFLAGS_NONE, CMPOPCUASERVER_VALUE_POLICY_BASIC256SHA256, "Support for all policies beginning with Basic256Sha256 (AES 256 with SHA256) [By now highest security]"},\
																{(RTS_I32)CmpOPCUAServer_SecurityPolicy_Basic256, CMPSECMAN_SFLAGS_NONE, CMPOPCUASERVER_VALUE_POLICY_BASIC256, "Support for all policies beginning with Basic256 (AES 256 with SHA1)"},\
																{(RTS_I32)CmpOPCUAServer_SecurityPolicy_Basic128Rsa15, CMPSECMAN_SFLAGS_NONE, CMPOPCUASERVER_VALUE_POLICY_BASIC128RSA15, "Support for all policies beginning with Basic128Rsa15 (AES 128 with SHA1)"}\
															}
#endif

/**
 * <category>SecuritySettings</category>
 * <description>Available communication modes.</description>
 * <element name="CmpOPCUAServer_CommunicationMode_OnlyPlaintext" type="IN">No security Available: Only security policy None allowed. (Default without CmpSecurityManager)</element>
 * <element name="CmpOPCUAServer_CommunicationMode_PlainAndSecure" type="IN">Support all available modes. Includes None, Signed, Signed + Encrypted (Default with CmpSecurityManager)</element>
 * <element name="CmpOPCUAServer_CommunicationMode_OnlySigned" type="IN">Support for the selected secure policies. But only signing will be activated.</element>
 * <element name="CmpOPCUAServer_CommunicationMode_SignedAndEncrypted" type="IN">Support of the selected secure policies. Activate Signing and Encryption. [HIGHES SECURITY LEVEL]</element>
 */   
#define CMPOPCUASERVER_KEY_STRING_COMMMODE					CMPSETTINGS_CATEGORY_SECURITY ".CommunicationMode"
#define CMPOPCUASERVER_KEY_STRING_COMMMODE_DESC				"Mode of the communication"

#define CMPOPCUASERVER_VALUE_COMMMODE_SIGNED_AND_ENCRYPTED	"SIGNED_AND_ENCRYPTED"
#define CMPOPCUASERVER_VALUE_COMMMODE_MIN_SIGNED			"MIN_SIGNED"
#define CMPOPCUASERVER_VALUE_COMMMODE_ALL					"ALL"
#define CMPOPCUASERVER_VALUE_COMMMODE_ONLY_PLAINTEXT		"ONLY_PLAINTEXT"

#ifndef CMPOPCUASERVER_VALUE_COMMMODE_DEFAULT
	#define CMPOPCUASERVER_VALUE_COMMMODE_DEFAULT			CMPOPCUASERVER_VALUE_COMMMODE_ALL
#endif

typedef enum
{
    CmpOPCUAServer_CommMode_OnlyPlaintext,
    CmpOPCUAServer_CommMode_PlainAndSecure,
    CmpOPCUAServer_CommMode_MinSigned,
    CmpOPCUAServer_CommMode_SignedAndEncrypted
}CmpOPCUAServer_CommunicationMode;

#define CMPOPCUASERVER_VALUE_COMMMODE_LIST					{\
																{(RTS_I32)CmpOPCUAServer_CommMode_SignedAndEncrypted, CMPSECMAN_SFLAGS_NONE, CMPOPCUASERVER_VALUE_COMMMODE_SIGNED_AND_ENCRYPTED, "Only signed and encrypted communications profiles are added [HIGHEST_SECURITY_LEVEL]"},\
																{(RTS_I32)CmpOPCUAServer_CommMode_MinSigned, CMPSECMAN_SFLAGS_NONE, CMPOPCUASERVER_VALUE_COMMMODE_MIN_SIGNED, "Enforce a signed communication. Encryption optional available."},\
																{(RTS_I32)CmpOPCUAServer_CommMode_PlainAndSecure, CMPSECMAN_SFLAGS_NONE, CMPOPCUASERVER_VALUE_COMMMODE_ALL, "Add all available modes. No security, just signed, signed and encrypted"},\
																{(RTS_I32)CmpOPCUAServer_CommMode_OnlyPlaintext, CMPSECMAN_SFLAGS_NONE, CMPOPCUASERVER_VALUE_COMMMODE_ONLY_PLAINTEXT, "Support only plain-text communication. Default without security manager."}\
															}
/**
 * <category>SecuritySettings</category>
 * <description>This setting allows to disable the CmpOPCUAServer.</description>
 * <element name="CmpOPCUAServer_Deactivated" type="IN">The OPC UA server will be loaded as a component. But it will not be active. No ports will be opened.</element>
 * <element name="CmpOPCUAServer_Activated" type="IN">The OPC UA server is activated. (Default with and without CmpSecurityManager)</element>
 */
#define CMPOPCUASERVER_KEY_STRING_ACTIVATION				CMPSETTINGS_CATEGORY_SECURITY ".Activation"
#define CMPOPCUASERVER_KEY_STRING_ACTIVATION_DESC			"Activates the OPCUA Server by default."

#define CMPOPCUASERVER_VALUE_ACTIVATION_DEACTIVATED			"DEACTIVATED"
#define CMPOPCUASERVER_VALUE_ACTIVATION_ACTIVATED			"ACTIVATED"

#ifndef CMPOPCUASERVER_VALUE_ACTIVATION_DEFAULT
	#define CMPOPCUASERVER_VALUE_ACTIVATION_DEFAULT			CMPOPCUASERVER_VALUE_ACTIVATION_ACTIVATED
#endif

typedef enum
{
	CmpOPCUAServer_Deactivated,
	CmpOPCUAServer_Activated
}CmpOPCUAServer_Activation;

#define CMPOPCUASERVER_VALUE_ACTIVATION_LIST				{\
																{(RTS_I32)CmpOPCUAServer_Deactivated, CMPSECMAN_SFLAGS_NONE, CMPOPCUASERVER_VALUE_ACTIVATION_DEACTIVATED, "Deactivates the OPC UA Server"},\
																{(RTS_I32)CmpOPCUAServer_Activated, CMPSECMAN_SFLAGS_NONE, CMPOPCUASERVER_VALUE_ACTIVATION_ACTIVATED, "Activates the OPC UA Server. [Default]"}\
															}


/**
 * <category>SecuritySettings</category>
 * <description>This setting allows to control the behavior of the user authentication of the CmpOPCUAServer.</description>
 * <element name="CmpOPCUAServer_UserAuthentication_Disabled" type="IN">Deactivates the user authentication for the OPC UA server. Only anonymous token will be available.</element>
 * <element name="CmpOPCUAServer_UserAuthentication_Enabled" type="IN">Activates the user authentication for the OPC UA Server. [Default]</element>
 * <element name="CmpOPCUAServer_UserAuthentication_Enforced" type="IN">Enforces that the users must login. No Anonymous token will be available.</element>
 */
#define CMPOPCUASERVER_KEY_STRING_USER_AUTHENTICATION			CMPSETTINGS_CATEGORY_SECURITY ".UserAuthentication"
#define CMPOPCUASERVER_KEY_STRING_USER_AUTHENTICATION_DESC		"Configuration for the user authentication."
	
#define CMPOPCUASERVER_VALUE_USER_AUTHENTICATION_DISABLED		"DISABLED"
#define CMPOPCUASERVER_VALUE_USER_AUTHENTICATION_ENABLED		"ENABLED"
#define CMPOPCUASERVER_VALUE_USER_AUTHENTICATION_ENFORCED		"ENFORCED"

#ifndef CMPOPCUASERVER_VALUE_USER_AUTHENTICATION_DEFAULT
	#define CMPOPCUASERVER_VALUE_USER_AUTHENTICATION_DEFAULT	CMPOPCUASERVER_VALUE_USER_AUTHENTICATION_ENABLED
#endif

typedef enum
{
	CmpOPCUAServer_UserAuthentication_Disabled,
	CmpOPCUAServer_UserAuthentication_Enabled,
    CmpOPCUAServer_UserAuthentication_Enforced,
} CmpOPCUAServer_UserAuthentication;

#define CMPOPCUASERVER_VALUE_USER_AUTHENTICATION_LIST			{\
																	{(RTS_I32)CmpOPCUAServer_UserAuthentication_Disabled, CMPSECMAN_SFLAGS_NONE, CMPOPCUASERVER_VALUE_USER_AUTHENTICATION_DISABLED, "Deactivates the user authentication for the OPC UA server. Only Anonymus token will be available."},\
																	{(RTS_I32)CmpOPCUAServer_UserAuthentication_Enabled, CMPSECMAN_SFLAGS_NONE, CMPOPCUASERVER_VALUE_USER_AUTHENTICATION_ENABLED, "Activates the user authenticaiton for the OPC UA Server. [Default]"},\
																	{(RTS_I32)CmpOPCUAServer_UserAuthentication_Enforced, CMPSECMAN_SFLAGS_NONE, CMPOPCUASERVER_VALUE_USER_AUTHENTICATION_ENFORCED, "Enforces that the users must login. No Anonymous token will be available."}\
																}

/**
 * <category>SecuritySettings</category>
 * <description>This setting controls if the user name / password authentication token can be transmitted in plain text. This would be the case if SecurityPolicy None is activated without a server certificate.</description>
 * <element name="CmpOPCUAServer_AllowUserPasswordOnPlaintext_Allowed" type="IN">Allows to transmit the password in a plain-text way.</element>
 * <element name="CmpOPCUAServer_AllowUserPasswordOnPlaintext_Forbidden" type="IN">Forbids to transmit the password in a plain-text way.</element>
 */
#define CMPOPCUASERVER_KEY_STRING_ALLOW_USERPASSWORD_ON_PLAINTEXT			CMPSETTINGS_CATEGORY_SECURITY ".AllowUserPasswordOnPlaintext"
#define CMPOPCUASERVER_KEY_STRING_ALLOW_USERPASSWORD_ON_PLAINTEXT_DESC		"Configuration for the user authentication."
	
#define CMPOPCUASERVER_VALUE_ALLOW_USERPASSWORD_ON_PLAINTEXT_YES			"YES"
#define CMPOPCUASERVER_VALUE_ALLOW_USERPASSWORD_ON_PLAINTEXT_NO				"NO"

#ifndef CMPOPCUASERVER_VALUE_ALLOW_USERPASSWORD_ON_PLAINTEXT_DEFAULT
	#define CMPOPCUASERVER_VALUE_ALLOW_USERPASSWORD_ON_PLAINTEXT_DEFAULT	CMPOPCUASERVER_VALUE_ALLOW_USERPASSWORD_ON_PLAINTEXT_NO
#endif

typedef enum
{
    CmpOPCUAServer_AllowUserPasswordOnPlaintext_Yes,
	CmpOPCUAServer_AllowUserPasswordOnPlaintext_No
}CmpOPCUAServer_AllowUserPasswordOnPlaintext;

#define CMPOPCUASERVER_VALUE_ALLOW_USERPASSWORD_ON_PLAINTEXT_LIST			{\
																				{(RTS_I32)CmpOPCUAServer_AllowUserPasswordOnPlaintext_Yes, CMPSECMAN_SFLAGS_NONE, CMPOPCUASERVER_VALUE_ALLOW_USERPASSWORD_ON_PLAINTEXT_YES, "Allows to transmit the password in a plaintext way."},\
																				{(RTS_I32)CmpOPCUAServer_AllowUserPasswordOnPlaintext_No, CMPSECMAN_SFLAGS_NONE, CMPOPCUASERVER_VALUE_ALLOW_USERPASSWORD_ON_PLAINTEXT_NO, "Forbids to tramsit the password in a plaintext way."}\
																			}

/**
 * <category>SecuritySettings</category>
 * <description>Specifies the application name of the OPC UA Server.
 * </description>
 */
#define CMPOPCUASERVER_KEY_STRING_APP_NAME			CMPSETTINGS_CATEGORY_SECURITY ".ApplicationName"
#define CMPOPCUASERVER_KEY_STRING_APP_NAME_DESC		"The application name of the OPC UA server. This will be used for the certificate and the ApplicationName fields of the OPC UA Server."

#ifndef CMPOPCUASERVER_VALUE_APP_NAME_DEFAULT
	#define CMPOPCUASERVER_VALUE_APP_NAME_DEFAULT	NULL
#endif

/**
 * <category>SecuritySettings</category>
 * <description>Specifies the company or organization name.
 * </description>
 */
#define CMPOPCUASERVER_KEY_STRING_ORG_NAME			CMPSETTINGS_CATEGORY_SECURITY ".CompanyOrOrganizationName"
#define CMPOPCUASERVER_KEY_STRING_ORG_NAME_DESC		"The name of the organization running the OPC UA server. (If empty field is ignored)"

#ifndef CMPOPCUASERVER_VALUE_ORG_NAME_DEFAULT
	#define CMPOPCUASERVER_VALUE_ORG_NAME_DEFAULT	NULL
#endif


/**
 * <category>SecuritySettings</category>
 * <description>Specifies the location.
 * </description>
 */
#define CMPOPCUASERVER_KEY_STRING_CITY				CMPSETTINGS_CATEGORY_SECURITY ".City"
#define CMPOPCUASERVER_KEY_STRING_CITY_DESC			"Will fill up the city field of the OPC UA Server certificate. If empty the field won't be used."

#ifndef CMPOPCUASERVER_VALUE_CITY_DEFAULT
	#define CMPOPCUASERVER_VALUE_CITY_DEFAULT		NULL
#endif

/**
 * <category>SecuritySettings</category>
 * <description>Specifies the state.
 * </description>
 */
#define CMPOPCUASERVER_KEY_STRING_STATE				CMPSETTINGS_CATEGORY_SECURITY ".State"
#define CMPOPCUASERVER_KEY_STRING_STATE_DESC		"Will fill up the state field of the OPC UA Server certificate. If empty the field won't be used."

#ifndef CMPOPCUASERVER_VALUE_STATE_DEFAULT
	#define CMPOPCUASERVER_VALUE_STATE_DEFAULT		NULL
#endif

/**
 * <category>SecuritySettings</category>
 * <description>Specifies the country.
 * </description>
 */
#define CMPOPCUASERVER_KEY_STRING_COUNTRY				CMPSETTINGS_CATEGORY_SECURITY ".Country"
#define CMPOPCUASERVER_KEY_STRING_COUNTRY_DESC			"Will fill up the country field of the OPC UA Server certificate. If empty the field won't be used."

#ifndef CMPOPCUASERVER_VALUE_COUNTRY_DEFAULT
	#define CMPOPCUASERVER_VALUE_COUNTRY_DEFAULT		NULL
#endif


/**
 * <category>Static defines</category>
 * <description>Objects used by the OPC UA server to check basic access rights.</description>
 */
#define USERDB_OBJECT_OPCUASERVER		        "Device.RemoteConnections.OPCUAServer"


/*
 * Event definitions
 */


#define CMPOPCUASERVER_SESSION_ADDED        1
#define CMPOPCUASERVER_SESSION_CHANGED      2
#define CMPOPCUASERVER_SESSION_REMOVED      3
/**
 * <category>Event parameter</category>
 * <element name="event" type="OUT">Type of session change. Can be one of added, changed or removed. See CMPOPCUASERVER_SESSION_* values.</element>
 * <element name="ui32SessionId" type="OUT">SessionID of added, changed or removed session.</element>
 */
typedef struct
{
	RTS_UI32 event;
    RTS_UI32 ui32SessionId;
} EVTPARAM_CmpOPCUAServerSessionsChanged;
#define EVTPARAMID_CmpOPCUAServerSessionsChanged						0x0001
#define EVTVERSION_CmpOPCUAServerSessionsChanged						0x0001

/**
 * <category>Events</category>
 * <description>Event is sent if a session has been added, removed or changed.</description>
 * <param name="pEventParam" type="IN">EVTPARAM_CmpOPCUAServerSessionsChanged</param>
 */
#define EVT_CmpOPCUAServerSessionsChanged					MAKE_EVENTID(EVTCLASS_INFO, 1)


/**
 * <description>Additional fields for nodes of NodeClass Object.</description> 
 * <element name="eventNotifier">Field which kind of events are available.</element>
 */
struct _OpcUaObjectDescription
{
	/* Mandatory attributes */
	OpcUa_Byte eventNotifier;
};
typedef struct _OpcUaObjectDescription OpcUaObjectDescription;

/**
 * <description>Additional fields for nodes of NodeClass Variable.</description> 
 * <element name="bValueAvailable">Flag if the value is set or not:
 * - If this value is OpcUa_True the read operation will be done by the server. This is useful for static values. Write access will be denied.
 * - If this value is OpcUa_False the OPC UA Server will call OpcUaProviderRead of the provider that has added this node. OpcUaProviderWrite to write this node.</element>
 * <element name="value">Static value of the node.</element>
 * <element name="dataType">NodeID of the data type node. Mandatory.</element>
 * <element name="i32ValueRank">ValueRank of the value. Mandatory.</element>
 * <element name="accessLevel">Access level of the node. If bValueAvailable == OpcUa_True this will be changed to CurrentRead. Mandatory.</element>
 * <element name="useraccesslevel">Access level of the node with user rights taken into account. If pszObject is set the CmpUserMgr will be called to get the rights. Mandatory.</element>
 * <element name="historizing">Flag if historicity is available. By now not supported by the OPC UA server. Mandatory.</element>
 * <element name="bArrayDimensionSet">Flag if the array dimension is set.</element>
 * <element name="arrayDimensions">Description of the array dimensions. Mandatory if the ValueRank is not Scalar.</element>
 * <element name="bMinimumSamplingIntervalSet">Flag if the minimum sampling interval is set.</element>
 * <element name="minimumSamplingInterval">Minimum sampling interval of this node.</element>
 */
struct _OpcUaVariableDescription
{
	/* Mandatory attributes */
    OpcUa_Boolean			bValueAvailable;
	OpcUa_Variant			value;
	OpcUa_NodeId			dataType;
	OpcUa_Int32				i32ValueRank;
	OpcUa_Byte				accessLevel;
	OpcUa_Byte				useraccesslevel;
	OpcUa_Boolean			historizing;

	/* Optional attributes */
	OpcUa_Boolean			bArrayDimensionSet;
	OpcUa_Variant			arrayDimensions;
	OpcUa_Boolean			bMinimumSamplingIntervalSet;
	OpcUa_Double			minimumSamplingInterval;
};
typedef struct _OpcUaVariableDescription OpcUaVariableDescription;


/**
 * <description>Additional fields for nodes of NodeClass Method.</description> 
 * <element name="executable">Flag if the method is executable. Mandatory.</element>
 * <element name="userExecutable">Flag if the method executable taken the user rights into account. Mandatory.</element>
 */
struct _OpcUaMethodDescription
{
	/* Mandatory attributes */
	OpcUa_Boolean executable;
	OpcUa_Boolean userExecutable;
};
typedef struct _OpcUaMethodDescription OpcUaMethodDescription;


/**
 * <description>Additional fields for nodes of NodeClass ObjectType.</description> 
 * <element name="isAbstract">Flag if is an abstract ObjectType. Mandatory.</element>
 */
struct _OpcUaObjectTypeDescription
{
	/* Mandatory attributes */
	OpcUa_Boolean isAbstract;
};
typedef struct _OpcUaObjectTypeDescription OpcUaObjectTypeDescription;


/**
 * <description>Additional fields for nodes of NodeClass VariableType.</description> 
 * <element name="dataType">NodeID of the data type node. Mandatory.</element>
 * <element name="i32ValueRank">ValueRank of the value. Mandatory.</element>
 * <element name="isAbstract">Flag if is an abstract VariableType. Mandatory.</element>
 * <element name="bValueSet">Flag if a template value is available.</element>
 * <element name="value">Value if available.</element>
 * <element name="bArrayDimensionSet">Flag if the array dimension is set.</element>
 * <element name="arrayDimensions">Description of the array dimensions. Mandatory if the ValueRank is not Scalar.</element>
 */
struct _OpcUaVariableTypeDescription
{
	/* Mandatory attributes */
	OpcUa_NodeId			dataType;
	OpcUa_Int32				i32ValueRank;
	OpcUa_Boolean			isAbstract;

	/* Optional attributes */
	OpcUa_Boolean			bValueSet;
	OpcUa_Variant			value;
	OpcUa_Boolean			bArrayDimensionsSet;
	OpcUa_Variant			arrayDimensions;
	
};
typedef struct _OpcUaVariableTypeDescription OpcUaVariableTypeDescription;

/**
 * <description>Additional fields for nodes of NodeClass RefereceType.</description> 
 * <element name="isAbstract">Flag if is an abstract RefereceType. Mandatory.</element>
 * <element name="symmetric">Flag if this is a symmetric reference.</element>
 * <element name="bInverseNameSet">Flag if the inverse name is set.</element>
 * <element name="inverseName">Inverse name of the reference.</element>
 */
struct _OpcUaReferenceTypeDescription
{
	/* Mandatory attributes */
	OpcUa_Boolean			isAbstract;
	OpcUa_Boolean			symmetric;
	
	/* Optional attributes */
	OpcUa_Boolean			bInverseNameSet;
	OpcUa_LocalizedText		inverseName;

};
typedef struct _OpcUaReferenceTypeDescription OpcUaReferenceTypeDescription;

/**
 * <description>Additional fields for nodes of NodeClass DataType.</description> 
 * <element name="isAbstract">Flag if is an abstract DataType. Mandatory.</element>
 */
struct _OpcUaDataTypeDescription
{
	/* Mandatory attributes */
	OpcUa_Boolean			isAbstract;
};
typedef struct _OpcUaDataTypeDescription OpcUaDataTypeDescription;

/**
 * <description>Additional fields for nodes of NodeClass View.</description> 
 * <element name="containsNoLoops">Flag if this view contains loops.</element>
 * <element name="eventNotifier">Field which kind of events are available.</element>
 */
struct _OpcUaViewDescription
{
	/* Mandatory attributes */
	OpcUa_Boolean			containsNoLoops;
	OpcUa_Byte				eventNotifier;
};
typedef struct _OpcUaViewDescription OpcUaViewDescription;

union _OpcUaElementDescription
{
	OpcUaObjectDescription object;
	OpcUaVariableDescription variable;
	OpcUaMethodDescription method;
	OpcUaObjectTypeDescription objectType;
	OpcUaVariableTypeDescription variableType;
	OpcUaReferenceTypeDescription referenceType;
	OpcUaDataTypeDescription dataType;
	OpcUaViewDescription view;
};
typedef union _OpcUaElementDescription OpcUaElementDescription;

/**
 * <description>This structure describes a single node of the OPC UA address space. 
 * Check the OPC UA specification to get a detailed description of the different attributes.
 * </description> 
 * <element name="nodeId">NodeID of the node. Mandatory.</element>
 * <element name="nodeClass">NodeClass of the node. This field will be used to determine the correct union member of elementDescription. Mandatory. </element>
 * <element name="browseName">BrowseName of the node. Mandatory.</element>
 * <element name="displayName">DisplayName of the node. Mandatory.</element>
 * <element name="bDescriptionSet">Flag if the description is available. If false OpcUa_BadAttributeIdInvalid will be returned for this attribute.</element>
 * <element name="description">Description of the node.</element>
 * <element name="bWriteMaskSet">Flag if the WriteMask is available. If false OpcUa_BadAttributeIdInvalid will be returned for this attribute.</element>
 * <element name="ui32WriteMask">WriteMask of the node./element>
 * <element name="bUserWriteMaskSet">Flag if the UserWriteMask is available. If false OpcUa_BadAttributeIdInvalid will be returned for this attribute.<</element>
 * <element name="ui32UserWriteMask">User write mask of the node.</element>
 * <element name="typeDefinition">Type definition of the node. A HasTypeDefinition will be added automatically if this is not a NULL NodeID (ns=0,i=0). 
 * If a type definition is available this will be taken into account when browsing the address space.</element>
 * <element name="elementDescription">The remaining attributes for the different node classes.</element>
 * <element name="pszObject">User management object related to this node. This object will be used to check access rights to the node. This used for reading,
 * writing, browsing. If NULL is set, no special right will be checked.
 * </element> 
 */
struct _OpcUaServerNodeDescription
{
	/* Mandatory attributes */
	OpcUa_NodeId			nodeId;
	OpcUa_NodeClass			nodeClass;
	OpcUa_QualifiedName		browseName;
	OpcUa_LocalizedText		displayName;
	
	/* Optional attributes */
	OpcUa_Boolean			bDescriptionSet;
	OpcUa_LocalizedText		description;
	OpcUa_Boolean			bWriteMaskSet;
	OpcUa_UInt32			ui32WriteMask;
	OpcUa_Boolean			bUserWriteMaskSet;
	OpcUa_UInt32			ui32UserWriteMask;
    
    /* TypeDefinition */
    OpcUa_NodeId            typeDefinition;      

	/* Nodeclass specific attributes */
	OpcUaElementDescription	elementDescription;
    
    /* User management object */
    char*                   pszObject;
};
typedef struct _OpcUaServerNodeDescription OpcUaServerNodeDescription;


/**
 * <description>This structure describes a reference that should be added to the OPC UA server.
 * All IDs in this structure have to known to the OPC UA server.</description> 
 * <element name="startNode">ID of the node where the reference starts.</element>
 * <element name="destinationNode">ID of the node where the reference points to.</element>
 * <element name="referenceType">ID of the RefereceType to be used.</element>
 * <element name="bBidirectional">Flag if the reference should be added in both directions.</element>
 */
struct _OpcUaServerReferenceDescription
{
    OpcUa_NodeId startNode;
	OpcUa_NodeId destinationNode;
	OpcUa_NodeId referenceType;
    OpcUa_Boolean bBidirectional;
};
typedef struct _OpcUaServerReferenceDescription OpcUaServerReferenceDescription;


/** EXTERN LIB SECTION BEGIN **/
/*  Comments are ignored for m4 compiler so restructured text can be used. changecom(`/*', `*/') */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description>Enum: OpcUaServer_MessageSecurityMode</description>
 */
#define OPCUASERVER_MESSAGESECURITYMODE_INVALID    RTS_IEC_DWORD_C(0x0)	
#define OPCUASERVER_MESSAGESECURITYMODE_NONE    RTS_IEC_DWORD_C(0x1)	
#define OPCUASERVER_MESSAGESECURITYMODE_SIGN    RTS_IEC_DWORD_C(0x2)	
#define OPCUASERVER_MESSAGESECURITYMODE_SIGNANDENCRYPT    RTS_IEC_DWORD_C(0x3)	
/* Typed enum definition */
#define OPCUASERVER_MESSAGESECURITYMODE    RTS_IEC_DWORD

/**
 * <description>Enum: OpcUaServer_SessionEvents</description>
 */
#define OPCUASERVER_SESSIONEVENTS_SESSION_ADDED    RTS_IEC_DWORD_C(0x1)	
#define OPCUASERVER_SESSIONEVENTS_SESSION_CHANGED    RTS_IEC_DWORD_C(0x2)	
#define OPCUASERVER_SESSIONEVENTS_SESSION_REMOVED    RTS_IEC_DWORD_C(0x3)	
/* Typed enum definition */
#define OPCUASERVER_SESSIONEVENTS    RTS_IEC_DWORD

/**
 * <description>OpcUaServer_Session_Information</description>
 */
typedef struct tagOpcUaServer_Session_Information
{
	RTS_IEC_DWORD dwSessionId;		
	INADDR clientAddress;		/* SessionID of the session. */
	RTS_IEC_WSTRING pwsSessionName[256];		/* IpAddress of the client. In host byte order. */
	RTS_IEC_WSTRING pwsApplicationName[256];		/* Session name. This is set by the client. */
	RTS_IEC_WSTRING pwsApplicationUri[256];		/* Application name of client. */
	RTS_IEC_WSTRING pwsProductUri[256];		/* URI of the client instance. */
	RTS_IEC_WSTRING pwsSecurityPolicy[256];		/* URI of client type. */
	RTS_IEC_DWORD securityMode;		/* Security profile used by this session. */
	RTS_IEC_HANDLE hClientCertificate;		/* Security mode of the session. */
	RTS_IEC_HANDLE hUser;		/* Handle to the clients certificate. Only valid for secure connections. RTS_INVALID_HANDLE if not available. */
} OpcUaServer_Session_Information;

/**
 * This function returns the first available session. Use this function and 
 * OpcUaServerGetNextSession to get the initial session configuration. To get notified about 
 * changes register to the EVT_CmpOPCUAServerSessionsChanged event.</description>
 *
 * :return: SessionId of the first session. 0xFFFFFFFF if no session is available.</result>
 */
typedef struct tagopcuaservergetfirstsession_struct
{
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_DWORD OpcUaServerGetFirstSession;	/* VAR_OUTPUT */	
} opcuaservergetfirstsession_struct;

DEF_API(`void',`CDECL',`opcuaservergetfirstsession',`(opcuaservergetfirstsession_struct *p)',1,0xACB7E0DC,0x03050C00)

/**
 * This function returns the next available session.</description>
 *
 * :result: SessionId of the first session. 0xFFFFFFFF if no session is available.
 */
typedef struct tagopcuaservergetnextsession_struct
{
	RTS_IEC_DWORD dwLastSession;		/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* SessionID of the last session. */
	RTS_IEC_DWORD OpcUaServerGetNextSession;	/* VAR_OUTPUT */	
} opcuaservergetnextsession_struct;

DEF_API(`void',`CDECL',`opcuaservergetnextsession',`(opcuaservergetnextsession_struct *p)',1,0xE2BBF24A,0x03050C00)

/**
 * This function returns details about a specific session.
 *
 * :return: Result of the operation. ERR_NOT_OBJECT if the sessions is available. ERR_OK if everything went fine.
 */
typedef struct tagopcuaservergetsessioninfo_struct
{
	RTS_IEC_DWORD dwSessionId;			/* VAR_INPUT */	
	OpcUaServer_Session_Information *pInformation;	/* VAR_INPUT */	/* SessionID of the session. */
	RTS_IEC_RESULT OpcUaServerGetSessionInfo;	/* VAR_OUTPUT */	
} opcuaservergetsessioninfo_struct;

DEF_API(`void',`CDECL',`opcuaservergetsessioninfo',`(opcuaservergetsessioninfo_struct *p)',1,0x6AE85AE6,0x03050C00)

#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/


#define Max_NumericRanges 5
typedef enum _NumericRangeType
{
	RangeType_Index = 0,
	RangeType_Range
} NumericRangeType;


/**
 * <element name="uiFrom">Index or start of range if Type = Range.</element>
 * <element name="uiTo">End of range if Type = Range, unused otherwise.</element>
 */
typedef struct _NumericRange
{
	NumericRangeType Type;
	OpcUa_Int32 uiFrom;
	OpcUa_Int32 uiTo;
} NumericRange;

typedef struct _OpcUaServer_SimpleBrowsePath
{
    OpcUa_UInt32 ui32NumOfElements;     /* Number of qualified names building the actual browse path */
    OpcUa_QualifiedName* pBrowsePath;   /* Pointer to an array of qualified names building the path.*/
}OpcUaServer_BrowsePath;


/**
 * <description>Register a new data provider within the OPC UA server.</description>
 * <param name="providerInterface" type="IN">Table of the provider interface.</param>
 * <result>Operation result:
 * </result>
 **/
DEF_ITF_API(`RTS_RESULT',`CDECL',`OpcUaServerRegisterProvider',`(OpcUaProvider_Info* providerInterface)')

/**
 * <description>Unregister an already registered data provider within the OPC UA server. 
 *
 * IMPLEMENTATION NOTE: Use CH_EXIT_TASK or later to unregister the provider. Don't unregister the provider while the
 * OPC UA server is running. This may lead to undefined behavior.
 * </description>
 * <param name="providerInterface" type="IN">Table of the provider interface.</param>
 * <result>Operation result:
 * </result>
 **/
DEF_ITF_API(`RTS_RESULT',`CDECL',`OpcUaServerUnRegisterProvider',`(OpcUaProvider_Info* providerInterface)')

/**
 * <description>Check if to follow OPCU UA reference type ID. Since reference type IDs may are derived only the server who knows all IDs can check this.</description>
 * <param name="pRequestedReference" type="IN">The reference type ID the client requested.</param>
 * <param name="bIncludeSubtypes" type="IN">The flag if subtypes should be followed too. Set by the client.</param>
 * <param name="pReferenceToCheck" type="IN">The reference type ID the compare against. Usually the reference type ID of the current node (e.g. while browsing) in the address space.</param>
 * <result>The function returns OpcUa_True if following the reference type ID is allowed. OpcUa_False is returned otherwise.</result>
 **/
DEF_ITF_API(`OpcUa_Boolean',`CDECL',`OpcUaServerCheckReferenceRecursive',`(const OpcUa_NodeId* pRequestedReference, OpcUa_Boolean bIncludeSubtypes, const OpcUa_NodeId* pReferenceToCheck)')

/**
 * <description>This function checks if a reference type ID is valid.</description>
 * <param name="pRefTypeId" type="IN">Referece type ID to check.</param>
 * <result>Returns either OpcUa_Good or OpcUa_BadRefereceTypeIdInvalid.</result>
 **/
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaServerCheckIfReferenceIsValid',`(const OpcUa_NodeId* pRefTypeId)')

/**
 * <description>Get the name space index of the given name space. Do not relay on constant reference type IDs. They may depend on the registration order of different providers.</description>
 * <param name="pNamespace" type="IN">The name space of interest.</param>
 * <result>-1: If the name space is not registered yet. index: The index of the namespace. This does not change while the server is running.</result>
 **/
DEF_ITF_API(`OpcUa_Int16',`CDECL',`OpcUaServerGetNamespaceIndex',`(OpcUa_String* pNamespace)')

/**
 * <description>Register a new name space to the server. If the name space is registered already this index is returned.</description>
 * <param name="pNamespace" type="IN">Name space to register at the server.</param>
 * <result>Returns the index of the registered name space.</result>
 **/
DEF_ITF_API(`OpcUa_Int16',`CDECL',`OpcUaServerRegisterNamespace',`(OpcUa_String* pNamespace)')

/**
 * <description>Parse the index range string which is part of some OPC UA requests with arrays to a structured form.</description>
 * <param name="pString" type="IN">String to parse.</param>
 * <param name="pRangeArray" type="INOUT">Pointer to the arrays where to store the parsed index ranges.</param>
 * <param name="pMaxRanges" type="IN">Maximum length of the array.</param>
 * <result>Returns the index of the registered name space.</result>
 **/
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaServerParseIndexRange',`(const OpcUa_String *pString, NumericRange *pRangeArray, OpcUa_UInt32 *pMaxRanges)')

/**
 * <description>This function returns the minimum sampling rate supported by the server.</description>
 **/
DEF_ITF_API(`OpcUa_Double',`CDECL',`OpcUaServerGetMinimumSamplingRate',`(void)')



/**
 * <description>Use this function to add nodes to the address space of the OPC UA server. The nodes added by this function will
 * be handled by the server. In combination with OpcUaServerAddReferences it is possible to add a complex structures to the OPC UA server.
 * The OPC UA server will then take care on browsing, reading, writing, monitoring.
 
 * Note: The values given here are copied to the OPC UA server. You can safely use static or stack values to call this function. The caller is
 * is responsible for this data.
 *
 * Note: The nodes are added in one transaction. The OPC UA server prepares all nodes to be added. Only if everything was prepared properly the
 * complete set of nodes will be added to the server. If this function returns an error nothing was changed at the address space.
 *
 * Note: If a node is already existing in the address space this node will be skipped. No error is generated in this case.
 *
 * Note: Normally if the address space have changed a ModelChangedEvent is sent to the clients. This can be done using OpcUaServerIndicateAddressSpaceChange.</description>
 *
 * <param name="providerInterface" type="IN">Pointer to the provider description. Use the same value as in OpcUaServerRegisterProvider.</param>
 * <param name="pNode" type="IN">Pointer to a list of nodes to be added.</param>
 * <param name="numNodes" type="IN">How many nodes should be added.</param>
 * <result>Result of the Operation. 
 *      - ERR_OK if everything went fine. 
 *      - ERR_NOMEMORY if the server runs out of memory.
 *      - ERR_PARAMETER if if a given parameter was invalid.
 *      - ERR_PARAMETER if the given nodes are not configured properly</result> 
 **/
DEF_ITF_API(`RTS_RESULT',`CDECL',`OpcUaServerAddNodes',`(OpcUaProvider_Info* providerInterface, OpcUaServerNodeDescription *pNodes, RTS_UI32 numNodes)')

/**
 * <description>Use this function to add references to the address space of the OPC UA server. Use this function to add the references between
 * the nodes added with OpcUaServerAddNodes or to link the added nodes to already existing nodes.
 
 * Note: The values given here are copied to the OPC UA server. You can safely use static or stack values to call this function. The caller is
 * is responsible for this data.
 *
 * Note: The references are added in one transaction. The OPC UA server prepares all references to be added. Only if everything was prepared 
 * properly the complete set of references will be added to the server. If this function returns an error nothing was changed at the address space.
 *
 * Note: If an identical reference is already existing in the address space this node will be skipped. No error is generated in this case.
 *
 * * Note: Normally if the address space have changed a ModelChangedEvent is sent to the clients. This can be done using OpcUaServerIndicateAddressSpaceChange.</description>
 * <param name="pReferences" type="IN">Pointer to a list of references to be added.</param>
 * <param name="numReferences" type="IN">How many references should be added.</param>
 * <result>Result of the Operation. 
 *      - ERR_OK if everything went fine. 
 *      - ERR_NOMEMORY if the server runs out of memory.
 *      - ERR_PARAMETER if if a given parameter was invalid.
 *      - ERR_PARAMETER if the given references are not configured properly</result> 
 **/
DEF_ITF_API(`RTS_RESULT',`CDECL',`OpcUaServerAddReferences',`(OpcUaServerReferenceDescription *pReferences, RTS_UI32 numReferences)')

/**
 * <description>Use this function to add remove all nodes with all corresponding references that have been added by this provider.</description>
 * <param name="providerInterface" type="IN">Pointer to the provider description. Use the same value as in OpcUaServerRegisterProvider.</param>
 * <result>Result of the Operation. 
 *      - ERR_OK if everything went fine. 
 *      - ERR_PARAMETER if if providerInterface is not set.
 *      - ERR_FAILED if no nodes where found.
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`OpcUaServerRemoveNodes',`(OpcUaProvider_Info* providerInterface)')


/* Server event handling */

/**
 * <description>Registers a node defined by a provider as an event notifier. The node should have the SubscriptToEvents flags set. Since events are ordered hierarchical the parent
 * event notifier node has to be given. This function allows to notify the events in a performing way. The corresponding references have to be added by the provider by himself.</description>
 * <param name="pNode" type="IN">NodeId of the EventNotifier node</param>
 * <param name="pParentNotifier" type="IN">Pointer to the parent EventNotifier node. If NULL the server node will be assumed.</param>
 * <param name="pResult" type="IN">Pointer to result. 
 *      - ERR_OK if everything went fine. 
 *      - ERR_NOTIMPLEMENTED if eventing is not available in the configuration. 
 *      - ERR_DUPLICATE if the node was already registered. The handle of the original one is returned. Use OpcUaServerUnregisterEventNotifier to unregister.
 *      - ERR_FAILED if something failed.</param>
 * <result>Handle to the registered node. Has to be used by OpcUaServerFireEvent and OpcUaServerUnregisterEventNotifier</result>
 */
DEF_ITF_API(`RTS_HANDLE',`CDECL',`OpcUaServerRegisterEventNotifier',`(OpcUa_NodeId* pNode, OpcUa_NodeId* pParentNotifier, RTS_RESULT* pResult)')

/**
 * <description>Unregisters an event notifier. As events are organized hierarchical the complete subtree will be removed.</description>
 * <param name="hNotifier" type="IN">Handle to the event notifier.</param>
 * <result>Result of operation. ERR_OK if everything went fine. ERR_INVALID_HANDLE if hNotifier was not a valid handle. ERR_FAILED in other cases.</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`OpcUaServerUnregisterEventNotifier',`(RTS_HANDLE hNotifier)')

/**
 * <description>Registers a new event at the server. This function registers the event fields of the event type to fire this event.
 * This registered event is used to fire an actual event. The fired event contains only the corresponding values. They have to have
 * the same order as registered in this function. The mandatory fields of the BaseEventType are added by default. They don't have to be set. These are:
 *  - EventType: The value will be filled up by the server. Type of the event: Data type: OpcUa_NodeId
 *  - EventId: Unique Id of the event: Data type: OpcUa_ByteString
 *  - SourceNode: NodeId of the event source node. Data type: OpcUa_NodeId
 *  - SourceName: Name of the event source. Data type: OpcUa_String
 *  - Time: UtcTimestamp when the event occurred. Data type: OpcUa_DateTime
 *  - ReceiveTime: The value will be filled up by the server. Data type: OpcUa_DateTime.</param>
 *  - Message: Message of the event. Data type: OpcUa_LocalizedText
 *  - Severity: Severity of the event. Data type: OpcUa_UInt16. Range from 1 to 1000 is allowed
 * <param name="providerInterface" type="IN">Pointer to the provider which registered this event.</param>
 * <param name="pEventTypeId" type="IN">NodeId of the event type.</param>
 * <param name="ui32NumOfFields" type="IN">Number of browse paths of the event.</param>
 * <param name="pEventFields" type="IN">Browse paths of the event fields.</param>
 * <param name="pResult" type="IN">Pointer to result. 
 *      - ERR_OK if everything went fine. 
 *      - ERR_NOTIMPLEMENTED if eventing is not available in the configuration. 
 *      - ERR_DUPLICATE if the node was already registered. The handle of the original one is returned. Use OpcUaServerUnregisterEvent to unregister.
 *      - ERR_FAILED if something failed.</param>
 * <result>Handle to the registered node. Has to be used by OpcUaServerFireEvent and OpcUaServerUnregisterEvent</result>
 */
DEF_ITF_API(`RTS_HANDLE',`CDECL',`OpcUaServerRegisterEvent',`(OpcUaProvider_Info* providerInterface, OpcUa_NodeId* pEventTypeId, OpcUa_UInt32 ui32NumOfFields, OpcUaServer_BrowsePath* pEventFields, RTS_RESULT* pResult)')

/**
 * <description>Unregisters an event</description>
 * <param name="hNotifier" type="IN">Handle to the event</param>
 * <result>Result of operation. ERR_OK if everything went fine. ERR_INVALID_HANDLE if hEvent was not a valid handle. ERR_FAILED in other cases.</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`OpcUaServerUnregisterEvent',`(RTS_HANDLE hEvent)')

/**
 * <description>Send an event to the OPC UA Server. This event will be transmitted to all monitored items where the monitoring parameters match to the sent event.
 * According to the OPC UA specification events are also notified to the parent event notifier nodes. By doing so the server object will receive all events. The mandatory property ReveiveTime will be set by 
 * the server automatically. This function has all required attributes of the BaseEventType as parameters. Optional attributes or attributes of derived types can be set by last three parameters.</description>
 * <param name="hNotifier" type="IN">Handle to the event notifier.</param>
 * <param name="hEvent" type="IN">Handle to the registered event.</param>
 * <param name="pValues" type="IN">Pointer to the event instance values. Must have the same order as the registered fields of hEvent.
 * Note: The mandatory event fields of the BaseEventType must be available in pValues. Since EventType and ReceiveTime are handled by the server internally these values don't have to be set in pValues.
*  Therefor the minimum number of values is 6. The following order is used, Add the additional fields after these fields:
 *  1. EventId: Unique Id of the event: Data type: OpcUa_ByteString
 *  2. SourceNode: NodeId of the event source node. Data type: OpcUa_NodeId
 *  3. SourceName: Name of the event source. Data type: OpcUa_String
 *  4. Time: UtcTimestamp when the event occurred. Data type: OpcUa_UtcTime
 *  5. Message: Message of the event. Data type: OpcUa_LocalizedText
 *  6. Severity: Severity of the event. Data type: OpcUa_UInt16. Range from 1 to 1000 is allowed</param>
 * <result>Result of the Operation. 
 *      - ERR_OK if everything went fine. 
 *      - ERR_PARAMETER if some parameter is invalid.
 *      - ERR_INVALID_HANDLE if hNotifier or hEvent is not a valid handle.
 *      - ERR_NOTIMPLEMENTED if eventing is not supported by the OPC UA Server. 
 *      - ERR_FAILED if something went wrong.</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`OpcUaServerFireEvent',`(RTS_HANDLE hNotifier, RTS_HANDLE hEvent, OpcUa_Variant* pValues)')


/**
 * <description>Send a BaseModelChange event to the client. As source node the Server (ns=0;i=2253) is used. 
 * This will cause the client to rebuild the complete address space.
 *
 * Note: According to the OPC UA specification this should only be fired one per changing sequence. Fire this event if all changes are committed to
 * your provider or to the OPC UA server.</description>
 * <result>Result of the Operation. 
 *      - ERR_OK if everything went fine. 
 *      - ERR_NOTIMPLEMENTED if eventing is not supported by the OPC UA Server. 
 *      - ERR_FAILED if something went wrong.</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`OpcUaServerIndicateAddressSpaceChange',`(void)')

/* Server diagnostic information */

/**
 * <description>This function returns the first available session. Use this function and 
 * OpcUaServerGetNextSession to get the initial session configuration. To get notified about 
 * changes register to the EVT_CmpOPCUAServerSessionsChanged event.</description>
 * <param name="pResult" type="OUT">Result of the operation. ERR_NOT_OBJECT if no sessions are available.</param>
 * <result>SessionId of the first session. 0xFFFFFFFF if no session is available.</result>
 */
DEF_ITF_API(`RTS_UI32',`CDECL',`OpcUaServerGetFirstSession',`(RTS_RESULT* pResult)')

/**
 * <description>This function returns the next available session.</description>
 * <param name="ui32LastSessionId" type="IN">SessionID of the last session.</param>
 * <param name="pResult" type="OUT">Result of the operation. ERR_NOT_OBJECT if no sessions are available or ui32LastSession was invalid.</param>
 * <result>SessionId of the first session. 0xFFFFFFFF if no session is available.</result>
 */
DEF_ITF_API(`RTS_UI32',`CDECL',`OpcUaServerGetNextSession',`(RTS_UI32 ui32LastSessionId, RTS_RESULT* pResult)')

/**
 * <description>This function returns details about a specific session.</description>
 * <param name="ui32SessionId" type="IN">SessionID of the session.</param>
 * <param name="OpcUaServer_Session_Information" type="INOUT">Pointer to the information structure filled up by this function.</param>
 * <result> - ERR_OK if information is complete. 
 *          - ERR_CONVERSION_INCOMPLETE if some information got lost in conversion from UTF-8 to WSTRINGs
 *          - ERR_FAILED if something failed.
 *          - ERR_NO_OBJECT if session id was invalid.</param>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`OpcUaServerGetSessionInfo',`(RTS_UI32 ui32SessionId, OpcUaServer_Session_Information* pInformation)')


/* User Management */
/**
 * <description>This function checks if the user of the current session has access rights to the desired object.</description>
 * <param name="ui32SessionId" type="IN">SessionID of the session.</param>
 * <param name="pszObject">Object where to check the access rights.</param>
 * <param name="ui32RequestedRights" type="IN">Requested rights on this object.</param>
 * <result> - ERR_OK: Access allowed.
 *          - ERR_NO_ACCESS_RIGHTS: Access denied. 
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`OpcUaServerCheckAccessRights',`(RTS_UI32 ui32SessionId, char* pszObject, RTS_UI32 ui32RequestedRights)')

/**
 * <description>This function returns the user handle of the given session. This user handle can be used with the CmpUserMgr to check 
 * access rights when the object is unknown. (e.g. Access to symbols of the application)</description>
 * <param name="ui32SessionId" type="IN">SessionID of the session.</param>
 * <param name="pResult">Pointer to error code</param>
 * <result>Handle of sessions user. RTS_INVALID_HANDLE if no user is available or an error occurred.</result>
 */
DEF_ITF_API(`RTS_HANDLE',`CDECL',`OpcUaServerGetUserHandle',`(RTS_UI32 ui32SessionId, RTS_RESULT* pResult)')
