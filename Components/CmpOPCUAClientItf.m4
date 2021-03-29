/**
 * <interfacename>CmpOPCUAClient</interfacename>
 * <description></description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */
 
SET_INTERFACE_NAME(`CmpOPCUAClient')


/**
 * <category>LogFilter masks</category>
 * <description>Mask to filter debug outputs module or scope specific</description>
 */

#define LFM_OPCUA_CLIENT_MASK                               0x00000FFF

#define LFM_OPCUA_CLIENT_COMMON								0x00000001
#define LFM_OPCUA_CLIENT_DISCOVERY                          0x00000002
#define LFM_OPCUA_CLIENT_SESSION                            0x00000004
#define LFM_OPCUA_CLIENT_ATTRIBUTE                          0x00000008
#define LFM_OPCUA_CLIENT_SUBSCRIPTION                       0x00000010
#define LFM_OPCUA_CLIENT_MONITOREDITEM                      0x00000020
#define LFM_OPCUA_CLIENT_TRACE_FUNCTION_CALLS               0x00001000

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>Configure the maximum number of OPC UA clients that can be used in parallel.</description>
 */
#define CMPOPCUACLIENT_INT_MAX_CLIENTS					"MaxClients"
#ifndef CMPOPCUACLIENT_INT_MAX_CLIENTS_DEFAULT	
	#define CMPOPCUACLIENT_INT_MAX_CLIENTS_DEFAULT		10
#endif
#ifndef CMPOPCUACLIENT_STATIC_CLIENTS
	#define CMPOPCUACLIENT_STATIC_CLIENTS				5
#endif

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>Configure the maximum number of pysical OPC UA channels available to all clients.</description>
 */
#define CMPOPCUACLIENT_INT_MAX_CHANNELS					"MaxChannels"
#ifndef CMPOPCUACLIENT_INT_MAX_CHANNELS_DEFAULT	
	#define CMPOPCUACLIENT_INT_MAX_CHANNELS_DEFAULT		60
#endif
#ifndef CMPOPCUACLIENT_STATIC_CHANNELS
	#define CMPOPCUACLIENT_STATIC_CHANNELS				10
#endif

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>Configure the maximum number of OPC UA sessions that can be used in parallel.</description>
 */
#define CMPOPCUACLIENT_INT_MAX_SESSIONS					"MaxSessions"
#ifndef CMPOPCUACLIENT_INT_MAX_SESSIONS_DEFAULT	
	#define CMPOPCUACLIENT_INT_MAX_SESSIONS_DEFAULT		60
#endif
#ifndef CMPOPCUACLIENT_STATIC_SESSIONS
	#define CMPOPCUACLIENT_STATIC_SESSIONS				10
#endif

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>Configure the maximum number of OPC UA requests available to all clients.</description>
 */
#define CMPOPCUACLIENT_INT_MAX_REQUESTS					"MaxRequests"
#ifndef CMPOPCUACLIENT_INT_MAX_REQUESTS_DEFAULT	
	#define CMPOPCUACLIENT_INT_MAX_REQUESTS_DEFAULT		1000
#endif
#ifndef CMPOPCUACLIENT_STATIC_REQUESTS
	#define CMPOPCUACLIENT_STATIC_REQUESTS				100
#endif

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>Configure the maximum number of OPC UA subscriptions available to all clients.</description>
 */
#define CMPOPCUACLIENT_INT_MAX_SUBSCRIPTIONS					"MaxSubscriptions"
#ifndef CMPOPCUACLIENT_INT_MAX_SUBSCRIPTIONS_DEFAULT	
	#define CMPOPCUACLIENT_INT_MAX_SUBSCRIPTIONS_DEFAULT		100
#endif
#ifndef CMPOPCUACLIENT_STATIC_SUBSCRIPTIONS
	#define CMPOPCUACLIENT_STATIC_SUBSCRIPTIONS					10
#endif

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>Configure the maximum number of OPC UA monitored items available to all subscriptions.</description>
 */
#define CMPOPCUACLIENT_INT_MAX_MONITOREDITEMS					"MaxMonitoredItems"
#ifndef CMPOPCUACLIENT_INT_MAX_MONITOREDITEMS_DEFAULT	
	#define CMPOPCUACLIENT_INT_MAX_MONITOREDITEMS_DEFAULT		5000
#endif
#ifndef CMPOPCUACLIENT_STATIC_MONITOREDITEMS
    #define CMPOPCUACLIENT_STATIC_MONITOREDITEMS				100
#endif

/* internal */
#define IOPCUAClientMonitoredItemCallback void

/** EXTERN LIB SECTION BEGIN **/
/*  Comments are ignored for m4 compiler so restructured text can be used. changecom(`/*', `*/') */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description>Enum: OPCUAClientConnectionState</description>
 */
#define OPCUACLIENTCONNECTIONSTATE_CONNECTING    RTS_IEC_INT_C(0x0)	
#define OPCUACLIENTCONNECTIONSTATE_VERIFYSERVERCERT    RTS_IEC_INT_C(0x1)	
#define OPCUACLIENTCONNECTIONSTATE_CHECKCREDENTIALS    RTS_IEC_INT_C(0x2)	
#define OPCUACLIENTCONNECTIONSTATE_CONNECTED    RTS_IEC_INT_C(0x3)	
#define OPCUACLIENTCONNECTIONSTATE_DISCONNECTING    RTS_IEC_INT_C(0x4)	
#define OPCUACLIENTCONNECTIONSTATE_DISCONNECTED    RTS_IEC_INT_C(0x5)	
#define OPCUACLIENTCONNECTIONSTATE_FAILED    RTS_IEC_INT_C(0x6)	
/* Typed enum definition */
#define OPCUACLIENTCONNECTIONSTATE    RTS_IEC_INT

/**
 * <description>Enum: OPCUAClientMonitoredItemState</description>
 */
#define OPCUACLIENTMONITOREDITEMSTATE_INITIALIZED    RTS_IEC_INT_C(0x0)	
#define OPCUACLIENTMONITOREDITEMSTATE_CREATED    RTS_IEC_INT_C(0x1)	
#define OPCUACLIENTMONITOREDITEMSTATE_DELETED    RTS_IEC_INT_C(0x2)	
/* Typed enum definition */
#define OPCUACLIENTMONITOREDITEMSTATE    RTS_IEC_INT

/**
 * <description>Enum: OPCUAClientSubscriptionState</description>
 */
#define OPCUACLIENTSUBSCRIPTIONSTATE_INIT    RTS_IEC_UDINT_C(0x0)	
#define OPCUACLIENTSUBSCRIPTIONSTATE_CREATED    RTS_IEC_UDINT_C(0x1)	
#define OPCUACLIENTSUBSCRIPTIONSTATE_PUBLISHINGACTIVE    RTS_IEC_UDINT_C(0x2)	
#define OPCUACLIENTSUBSCRIPTIONSTATE_PUBLISHINGDEACTIVATED    RTS_IEC_UDINT_C(0x3)	
#define OPCUACLIENTSUBSCRIPTIONSTATE_TIMEOUT    RTS_IEC_UDINT_C(0x4)	
#define OPCUACLIENTSUBSCRIPTIONSTATE_DELETED    RTS_IEC_UDINT_C(0x5)	
/* Typed enum definition */
#define OPCUACLIENTSUBSCRIPTIONSTATE    RTS_IEC_UDINT

/**
 * <description>OPCAClientCredentials_UserPassword</description>
 */
typedef struct tagOPCAClientCredentials_UserPassword
{
	OpcUa_String username;		/* The username used to activate the session. */
	OpcUa_String password;		/* The password corresponding to the username */
} OPCAClientCredentials_UserPassword;

/**
 * <description>OPCUAClientConnectionConfiguration</description>
 */
typedef struct tagOPCUAClientConnectionConfiguration
{
	RTS_IEC_UDINT sizeofStruct;		/* Size of the strucutre. */
	OpcUa_EndpointDescription endpoint;		/* The endpoint to connect to. The endpoint should contain only user token policy that should be used to activate the session. */
	OpcUa_String sessionName;		/* The sessions name. */
	RTS_IEC_UDINT sessionTimeout;		/* The session timeout. */
} OPCUAClientConnectionConfiguration;

/**
 * <description>OPCUAClientCredentials</description>
 */
typedef union
{
	OPCAClientCredentials_UserPassword up;		/* Contains the User/Password credentials used for UserTokenType_UserName. */
	RTS_IEC_HANDLE cert;		/* Contains the certificate Certificate used for UserTokenType_Certificate. */
} OPCUAClientCredentials;

/**
 * <description>OPCUAClientMonitoredItemConfiguration</description>
 */
typedef struct tagOPCUAClientMonitoredItemConfiguration
{
	OpcUa_ReadValueId ItemToMonitor;		/* IN: The nodeID and Attribute ID of the item to monitore */
	RTS_IEC_DINT MonitoringMode;		/* IN: The initial monitorng mode of the item. */
	RTS_IEC_LREAL SamplingInterval;		/* IN: The sampling interval for sampling items. Will be revieced by the server. */
	OpcUa_ExtensionObject Filter;		/* IN: The filter to be applied to the monitored item. */
	RTS_IEC_UDINT QueueSize;		/* IN: The initial queue size of the monitored item. Will be reviced by the server. */
	RTS_IEC_BOOL DiscardOldest;		/* IN: Behavior on queue overflow: TRUE: The oldest sample will be removed. FALSE: the latest sample will be overwritten. */
	IOPCUAClientMonitoredItemCallback *callback;		/* IN: The callback interface for that monitored item. */
	RTS_IEC_UDINT statusCode;		/* OUT: The result of the operation for this item. */
	RTS_IEC_HANDLE hItem;		/* OUT: The handle of the monitored item. */
	RTS_IEC_UXINT pcbMonitoredItemCallbackData;		/* internal */
} OPCUAClientMonitoredItemConfiguration;

/**
 * <description>OPCUAClientUserToken</description>
 */
typedef struct tagOPCUAClientUserToken
{
	RTS_IEC_DINT credtype;		/* Identifies the actually used token type. */
	OPCUAClientCredentials entry;		/* Contains the user token. */
} OPCUAClientUserToken;

#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/
 
 /*********************************************************************
 * Creates and destroys client instances
 *********************************************************************/
DEF_ITF_API(`RTS_HANDLE',`CDECL',`OPCUAClient_Create',`(OpcUa_ApplicationDescription *pConfiguration, RTS_RESULT *pResult)')

DEF_ITF_API(`RTS_RESULT',`CDECL',`OPCUAClient_Delete',`(RTS_HANDLE hClient)')

DEF_ITF_API(`OpcUa_ApplicationDescription*',`CDECL',`OPCUAClient_GetConfig',`(RTS_HANDLE hClient, RTS_RESULT *pResult)')
 
/*********************************************************************
 * Discovery Services (can be sent without connecting the client!) [Facet=CORE]
 *********************************************************************/
typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_GETENDPOINTS_CALLBACK)(RTS_HANDLE hClient, RTS_UINTPTR pcbGetEndpointsData, OpcUa_StatusCode uStatus,  OpcUa_Int32 numOfEndpoints, OpcUa_EndpointDescription* pEndpoints);
typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_FINDSERVERS_CALLBACK)(RTS_HANDLE hClient, RTS_UINTPTR pcbFindServersData, OpcUa_StatusCode uStatus, OpcUa_Int32 numOfServers, OpcUa_ApplicationDescription *pServerList);
typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_FINDSERVERSONNETWORK_CALLBACK)(RTS_HANDLE hClient, RTS_UINTPTR pcbFindServersOnNetworkData, OpcUa_StatusCode uStatus, OpcUa_DateTime lastCounterResetTime, OpcUa_Int32 numOfServers, OpcUa_ServerOnNetwork *pServerList);
                                                                
DEF_ITF_API(`RTS_RESULT',`CDECL',`OPCUAClientDiscovery_GetEndpoints',`(RTS_HANDLE hClient, OpcUa_String* psEndpointURL, PF_OPCUACLIENT_GETENDPOINTS_CALLBACK cbfGetEndpoints, RTS_UINTPTR pcbGetEndpointsData)')
DEF_ITF_API(`RTS_RESULT',`CDECL',`OPCUAClientDiscovery_FindServers',`(RTS_HANDLE hClient, OpcUa_String* psEndpointURL, PF_OPCUACLIENT_FINDSERVERS_CALLBACK cbfFindServers, RTS_UINTPTR pcbFindServersData)')
DEF_ITF_API(`RTS_RESULT',`CDECL',`OPCUAClientDiscovery_FindServersOnNetwork',`(RTS_HANDLE hClient, OpcUa_String* psEndpointURL, OpcUa_UInt32 startingRecordId, OpcUa_UInt32 maxRecordsToReturn, OpcUa_Int32 numServerCapabilityFilters, OpcUa_String *psServerCapabilityFilters, PF_OPCUACLIENT_FINDSERVERSONNETWORK_CALLBACK cbfFindServersOnNetwork, RTS_UINTPTR pcbFindServersOnNetworkData)')

/*********************************************************************
 * Session services [Facet=CORE]
 *********************************************************************/

typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_CONNECTION_CALLBACK)(RTS_HANDLE hConnection, RTS_UINTPTR pcbConnectionData, OPCUACLIENTCONNECTIONSTATE connectionState, OpcUa_StatusCode reason);
typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_VERIFY_CERTIFICATE_CALLBACK)(RTS_HANDLE hConnection, RTS_UINTPTR pcbVerifyCertData, RTS_HANDLE hServerCertificate);
typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_GETCREDENTIALS_CALLBACK)(RTS_HANDLE hConnection, RTS_UINTPTR pcbGetCredentialsData, OPCUAClientUserToken* pUserToken);

DEF_ITF_API(`RTS_HANDLE',`CDECL',`OPCUAClient_Connect',`(RTS_HANDLE hClient, OPCUAClientConnectionConfiguration* pConnectionConfiguration, PF_OPCUACLIENT_CONNECTION_CALLBACK cbfConnection, RTS_UINTPTR pcbConnectionData, PF_OPCUACLIENT_VERIFY_CERTIFICATE_CALLBACK cbfVerifyCertificate, RTS_UINTPTR pcbVerifyCertData,		PF_OPCUACLIENT_GETCREDENTIALS_CALLBACK cbfGetCredentials,  RTS_UINTPTR pcbGetCredentialsData)')

DEF_ITF_API(`RTS_RESULT',`CDECL',`OPCUAClient_Disconnect',`(RTS_HANDLE hConnection)')

/*********************************************************************
 * DataAccess services [Facet=CORE]
 *********************************************************************/
typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_READ_CALLBACK)(RTS_HANDLE hConnection, RTS_UINTPTR pcbReadData, OpcUa_StatusCode serviceResult, OpcUa_UInt32 numOfValues, OpcUa_ReadValueId *pRequests, OpcUa_DataValue *pValues);

DEF_ITF_API(`RTS_RESULT',`CDECL',`OPCUAClient_Read',`(RTS_HANDLE hConnection, OpcUa_Double maxAge, OpcUa_TimestampsToReturn timestampsToReturn, OpcUa_ReadValueId *pNodesToRead, OpcUa_Int32 numOfNodes, PF_OPCUACLIENT_READ_CALLBACK cbfRead, RTS_UINTPTR pcbReadData)')


typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_WRITE_CALLBACK)(RTS_HANDLE hConnection, RTS_UINTPTR pcbWriteData, OpcUa_StatusCode serviceResult, OpcUa_UInt32 numOfValues, OpcUa_WriteValue *pRequests, OpcUa_StatusCode* pResults);

DEF_ITF_API(`RTS_RESULT',`CDECL',`OPCUAClient_Write',`(RTS_HANDLE hConnection, OpcUa_WriteValue *pNodesToWrite, OpcUa_Int32 numOfNodes, PF_OPCUACLIENT_WRITE_CALLBACK cbfWrite, RTS_UINTPTR pcbWriteData)')

/*********************************************************************
 * Subscription services [Facet=CORE]
 *********************************************************************/
 typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_SUBSCRIPTION_STATE_CALLBACK)(RTS_HANDLE hSubscription, RTS_UINTPTR pcbSubscriptionData, OPCUACLIENTSUBSCRIPTIONSTATE newState, OpcUa_StatusCode reason);
 typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_SUBSCRIPTION_PARAMETER_CALLBACK)(RTS_HANDLE hSubscription, RTS_UINTPTR pcbSubscriptionData, OpcUa_Double publishingInterval, OpcUa_UInt32 lifetimeCount, OpcUa_UInt32 maxKeepAliveCount, OpcUa_UInt32 maxNotificationsPerPublish, OpcUa_Byte priority, OpcUa_StatusCode reason);

DEF_ITF_API(`RTS_HANDLE',`CDECL',`OPCUAClient_CreateSubscription',`(RTS_HANDLE hConnection, OpcUa_Double publishingInterval, OpcUa_UInt32 lifetimeCount, OpcUa_UInt32 maxKeepAliveCount, OpcUa_UInt32 maxNotificationsPerPublish, OpcUa_Boolean publishingEnabled, OpcUa_Byte priority, PF_OPCUACLIENT_SUBSCRIPTION_STATE_CALLBACK cbfSubscriptionState, RTS_UINTPTR pcbSubscriptionStateData, PF_OPCUACLIENT_SUBSCRIPTION_PARAMETER_CALLBACK cbfSubscriptionParameter, RTS_UINTPTR pcbSubscriptionParameterData, RTS_RESULT *pResult)')

DEF_ITF_API(`RTS_RESULT',`CDECL',`OPCUAClient_DeleteSubscription',`(RTS_HANDLE hSubscription)')

DEF_ITF_API(`RTS_RESULT',`CDECL',`OPCUAClient_ModifySubscription',`(RTS_HANDLE hSubscription, OpcUa_Double reqPublishingInterval, OpcUa_UInt32 reqLifeTimeCount, OpcUa_UInt32 reqMaxKeepAliveCount, OpcUa_UInt32 maxNotificationsPerPublish, OpcUa_Byte priority)')

DEF_ITF_API(`RTS_RESULT',`CDECL',`OPCUAClient_SetPublishingMode',`(RTS_HANDLE hSubscription, OpcUa_Boolean publishingEnabled)')

/*********************************************************************
 * Monitored Items services [Facet=CORE]
 *********************************************************************/

typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_MONITOREDITEM_STATE_CALLBACK)(RTS_HANDLE hMonitoredItem, RTS_UINTPTR pcbMonitoredItemData, RTS_IEC_INT newState, OpcUa_StatusCode reason);
typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_MONITOREDITEM_PARAMETER_CALLBACK)(RTS_HANDLE hMonitoredItem, RTS_UINTPTR pcbMonitoredItemData, OpcUa_Double revisedSamplingInterval, OpcUa_UInt32 revisedQueueSize, OpcUa_ExtensionObject filterResult, OpcUa_StatusCode reason);
typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_MONITOREDITEM_VALUE_CALLBACK)(RTS_HANDLE hMonitoredItem, RTS_UINTPTR pcbMonitoredItemData, OpcUa_DataValue value, OpcUa_StatusCode reason);
typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_MONITOREDITEM_EVENT_CALLBACK)(RTS_HANDLE hMonitoredItem, RTS_UINTPTR pcbMonitoredItemData, OpcUa_Int32 noOfEventFields, OpcUa_Variant* eventFields, OpcUa_StatusCode reason);

DEF_ITF_API(`RTS_RESULT',`CDECL',`OPCUAClient_CreateMonitoredItems',`(RTS_HANDLE hSubscription, OpcUa_TimestampsToReturn eTimestampsToReturn, OpcUa_Int32 nNoOfItemsToCreate, OPCUAClientMonitoredItemConfiguration* pMonitoredItemsToCreate, PF_OPCUACLIENT_MONITOREDITEM_STATE_CALLBACK cbfMonitoredItemState, PF_OPCUACLIENT_MONITOREDITEM_PARAMETER_CALLBACK cbfMonitoredItemParameter, PF_OPCUACLIENT_MONITOREDITEM_VALUE_CALLBACK cbfMonitoredItemValue, PF_OPCUACLIENT_MONITOREDITEM_EVENT_CALLBACK cbfMonitoredItemEvent)')

DEF_ITF_API(`RTS_RESULT',`CDECL',`OPCUAClient_ModifyMonitoredItems',`(RTS_HANDLE hSubscription, OpcUa_TimestampsToReturn eTimestampsToReturn, OpcUa_Int32 nNoOfItemsToModify, OPCUAClientMonitoredItemConfiguration* pMonitoredItemsToModify)')

DEF_ITF_API(`RTS_RESULT',`CDECL',`OPCUAClient_SetMonitoringMode',`(RTS_HANDLE hSubscription, OpcUa_MonitoringMode monitoringMode, OpcUa_Int32 nNoOfMonitoredItems, RTS_HANDLE *phItems)')

DEF_ITF_API(`RTS_RESULT',`CDECL',`OPCUAClient_DeleteMonitoredItems',`(RTS_HANDLE hSubscription, OpcUa_Int32 nNoOfItemsToDelete, RTS_HANDLE *phItems)')

DEF_ITF_API(`RTS_RESULT',`CDECL',`OPCUAClient_ExtensionObjectAttachReadOnly',`(OpcUa_UInt32 TypeId, OpcUa_ExtensionObject* pExtensionObject, OpcUa_Void* pObject)')

/*********************************************************************
 * View services [Facet=CORE]
 *********************************************************************/
typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_BROWSE_CALLBACK)(RTS_HANDLE hConnection, RTS_UINTPTR pcbCallbackData, OpcUa_StatusCode serviceResult, OpcUa_UInt32 numOfResults, OpcUa_BrowseResult *results);
typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_BROWSENEXT_CALLBACK)(RTS_HANDLE hConnection, RTS_UINTPTR pcbCallbackData, OpcUa_StatusCode serviceResult, OpcUa_UInt32 numOfResults, OpcUa_BrowseResult *results);
typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_TRANSLATEBROWSEPATHSTONODEIDS_CALLBACK)(RTS_HANDLE hConnection, RTS_UINTPTR pcbCallbackData, OpcUa_StatusCode serviceResult, OpcUa_UInt32 numOfResults, OpcUa_BrowsePathResult *results);
typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_REGISTERNODES_CALLBACK)(RTS_HANDLE hConnection, RTS_UINTPTR pcbCallbackData, OpcUa_StatusCode serviceResult, OpcUa_UInt32 numOfNodes, OpcUa_NodeId *registeredNodeIds);
typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_UNREGISTERNODES_CALLBACK)(RTS_HANDLE hConnection, RTS_UINTPTR pcbCallbackData, OpcUa_StatusCode serviceResult);
 
DEF_ITF_API(`RTS_RESULT',`CDECL',`OPCUAClient_Browse',`(RTS_HANDLE hConnection, OpcUa_ViewDescription view, OpcUa_Int32 requestedMaxReferencesPerNode, OpcUa_Int32 noOfNodesToBrowse, OpcUa_BrowseDescription *pNodesToBrowse, void*cbfCallback, RTS_UINTPTR pcbCallbackData)')
DEF_ITF_API(`RTS_RESULT',`CDECL',`OPCUAClient_BrowseNext',`(RTS_HANDLE hConnection, OpcUa_Boolean releaseContinuationPoints, OpcUa_Int32 noOfContinuationPoints, OpcUa_ByteString *pContinuationPoints, void*cbfCallback, RTS_UINTPTR pcbCallbackData)')
DEF_ITF_API(`RTS_RESULT',`CDECL',`OPCUAClient_TranslateBrowsePathsToNodeIds',`(RTS_HANDLE hConnection, OpcUa_Int32 noOfBrowsePaths, OpcUa_BrowsePath *pBrowsePaths, void*cbfCallback, RTS_UINTPTR pcbCallbackData)')
DEF_ITF_API(`RTS_RESULT',`CDECL',`OPCUAClient_RegisterNodes',`(RTS_HANDLE hConnection, OpcUa_Int32 noOfNodesToRegister, OpcUa_NodeId *pNodesToRegister, void*cbfCallback, RTS_UINTPTR pcbCallbackData)')
DEF_ITF_API(`RTS_RESULT',`CDECL',`OPCUAClient_UnregisterNodes',`(RTS_HANDLE hConnection, OpcUa_Int32 noOfNodesToUnregister, OpcUa_NodeId *pNodesToUnregister, void*cbfCallback, RTS_UINTPTR pcbCallbackData)')
