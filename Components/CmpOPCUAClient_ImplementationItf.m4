/**
 * <interfacename>CmpOPCUAClient Implementation</interfacename>
 * <description></description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`CmpOPCUAClient_Implementation')
SET_PLACEHOLDER_NAME(`CmpOPCUAClient Implementation')
REF_ITF(`CmpOPCUAClientItf.m4')

/**
 * ATTENTION: Update the connectionstatecallbackwrapper_struct of CmpOPCUAClient_ImplementationItf.m4 if
 * the signature of this functions is changed
 */
typedef struct tagconnectionstatecallbackwrapper_struct
{
	RTS_IEC_HANDLE hConnection;			/* VAR_INPUT */	
	RTS_IEC_UXINT pcbConnectionData;	/* VAR_INPUT */	
	RTS_IEC_INT connectionState;		/* VAR_INPUT, Enum: OPCUACLIENTCONNECTIONSTATE */
	RTS_IEC_UDINT reason;				/* VAR_INPUT, Enum: OPCUA_STATUSCODE */
	OpcUa_StatusCode ConnectionStateCallbackWrapper;	/* VAR_OUTPUT*/
} connectionstatecallbackwrapper_struct;

/**
 * ATTENTION: Update the findserverscallbackwrapper_struct of CmpOPCUAClient_ImplementationItf.m4 if
 * the signature of this functions is changed
 */
typedef struct tagfindserverscallbackwrapper_struct
{
	RTS_IEC_HANDLE hClient;				/* VAR_INPUT */	
	RTS_IEC_UXINT pcbFindServers;		/* VAR_INPUT */	
	RTS_IEC_UDINT serviceResult;		/* VAR_INPUT, Enum: OPCUA_STATUSCODE */
	RTS_IEC_DINT numOfServers;			/* VAR_INPUT */	
	OpcUa_ApplicationDescription *pServerList;	/* VAR_INPUT */	
	OpcUa_StatusCode FindServersCallbackWrapper;	/* VAR_OUTPUT*/
} findserverscallbackwrapper_struct;

/**
 * ATTENTION: Update the findserversonnetworkcallbackwrapper_struct of CmpOPCUAClient_ImplementationItf.m4 if
 * the signature of this functions is changed
 */
typedef struct tagfindserversonnetworkcallbackwrapper_struct
{
	RTS_IEC_HANDLE hClient;				/* VAR_INPUT */	
	RTS_IEC_UXINT pcbFindServersOnNetwork;		/* VAR_INPUT */	
	RTS_IEC_UDINT serviceResult;		/* VAR_INPUT, Enum: OPCUA_STATUSCODE */
	RTS_IEC_LINT lastCounterResetTime;	/* VAR_INPUT */	
	RTS_IEC_DINT numOfServers;			/* VAR_INPUT */	
	OpcUa_ServerOnNetwork *pServerList;	/* VAR_INPUT */	
	OpcUa_StatusCode FindServersOnNetworkCallbackWrapper;	/* VAR_OUTPUT*/
} findserversonnetworkcallbackwrapper_struct;

/**
 * ATTENTION: Update the getendpointscallbackwrapper_struct of CmpOPCUAClient_ImplementationItf.m4 if
 * the signature of this functions is changed
 */
typedef struct taggetendpointscallbackwrapper_struct
{
	RTS_IEC_HANDLE hClient;				/* VAR_INPUT */	
	RTS_IEC_UXINT pcbGetEndpointsData;	/* VAR_INPUT */	
	RTS_IEC_UDINT serviceResult;		/* VAR_INPUT, Enum: OPCUA_STATUSCODE */
	RTS_IEC_DINT numOfEndpoints;		/* VAR_INPUT */	
	OpcUa_EndpointDescription *pEndpoints;	/* VAR_INPUT */	
	OpcUa_StatusCode GetEndpointsCallbackWrapper;	/* VAR_OUTPUT*/
} getendpointscallbackwrapper_struct;

/**
 * ATTENTION: Update the getusercredentialscallbackwrapper_struct of CmpOPCUAClient_ImplementationItf.m4 if
 * the signature of this functions is changed
 */
typedef struct taggetusercredentialscallbackwrapper_struct
{
	RTS_IEC_HANDLE hConnection;			/* VAR_INPUT */	
	RTS_IEC_UXINT pcbGetCredentialsData;	/* VAR_INPUT */	
	OPCUAClientUserToken *pUserToken;	/* VAR_INPUT */	
	OpcUa_StatusCode GetUserCredentialsCallbackWrapper;	/* VAR_OUTPUT*/
} getusercredentialscallbackwrapper_struct;

/**
 * ATTENTION: Update the readcallbackwrapper_struct of CmpOPCUAClient_ImplementationItf.m4 if
 * the signature of this functions is changed
 */
typedef struct tagreadcallbackwrapper_struct
{
	RTS_IEC_HANDLE hConnection;			/* VAR_INPUT */	
	RTS_IEC_UXINT pcbReadCallbackData;	/* VAR_INPUT */	
	RTS_IEC_UDINT serviceResult;		/* VAR_INPUT, Enum: OPCUA_STATUSCODE */
	RTS_IEC_DINT numOfValues;			/* VAR_INPUT */	
	OpcUa_ReadValueId *pRequests;	/* VAR_INPUT */	
	OpcUa_DataValue *pValues;	/* VAR_INPUT */	
	OpcUa_StatusCode ReadCallbackWrapper;	/* VAR_OUTPUT*/
} readcallbackwrapper_struct;

/**
 * ATTENTION: Update the writecallbackwrapper_struct of CmpOPCUAClient_ImplementationItf.m4 if
 * the signature of this functions is changed
 */
typedef struct tagwritecallbackwrapper_struct
{
	RTS_IEC_HANDLE hConnection;			/* VAR_INPUT */	
	RTS_IEC_UXINT pcbWriteCallbackData;	/* VAR_INPUT */	
	RTS_IEC_UDINT serviceResult;		/* VAR_INPUT, Enum: OPCUA_STATUSCODE */
	RTS_IEC_DINT numOfNodes;			/* VAR_INPUT */	
	OpcUa_WriteValue *pRequests;	/* VAR_INPUT */	
	OpcUa_StatusCode *pResults;	/* VAR_INPUT */	
	OpcUa_StatusCode WriteCallbackWrapper;	/* VAR_OUTPUT*/
} writecallbackwrapper_struct;

/**
 * ATTENTION: Update the verifyservercertificatecallbackwrapper_struct of CmpOPCUAClient_ImplementationItf.m4 if
 * the signature of this functions is changed
 */
typedef struct tagverifyservercertificatecallbackwrapper_struct
{
	RTS_IEC_HANDLE hConnection;			/* VAR_INPUT */	
	RTS_IEC_UXINT pcbVerifyCertData;	/* VAR_INPUT */	
	RTS_IEC_HANDLE hServerCertificate;	/* VAR_INPUT */	
	OpcUa_StatusCode VerifyServerCertificateCallbackWrapper;	/* VAR_OUTPUT*/
} verifyservercertificatecallbackwrapper_struct;

/**
 * ATTENTION: Update the subscriptionstatechangecallbackwrapper_struct of CmpOPCUAClient_ImplementationItf.m4 if
 * the signature of this functions is changed
 */
typedef struct tagsubscriptionstatechangecallback_struct
{
	RTS_IEC_HANDLE hSubscription;			/* VAR_INPUT */	
	RTS_IEC_UXINT pcbSubscriptionData;		/* VAR_INPUT */	
	OPCUACLIENTSUBSCRIPTIONSTATE newState;	/* VAR_INPUT */	
	OpcUa_StatusCode reason;				/* VAR_INPUT */	
	OpcUa_StatusCode SubscriptionStateChangeCallback;	/* VAR_OUTPUT*/
} subscriptionstatechangecallback_struct;

/**
 * ATTENTION: Update the subscriptionparameterchangecallbackwrapper_struct of CmpOPCUAClient_ImplementationItf.m4 if
 * the signature of this functions is changed
 */
typedef struct tagsubscriptionparameterchangecallback_struct
{
	RTS_IEC_HANDLE hSubscription;			/* VAR_INPUT */	
	RTS_IEC_UXINT pcbSubscriptionData;		/* VAR_INPUT */	
	RTS_IEC_LREAL publishingInterval;       /* VAR_INPUT */	
	RTS_IEC_UDINT lifeTimeCount;            /* VAR_INPUT */	
	RTS_IEC_UDINT maxKeepAliveCount;        /* VAR_INPUT */	
	RTS_IEC_UDINT maxNotificationsPerPublish; /* VAR_INPUT */
	RTS_IEC_USINT priority;					/* VAR_INPUT */
	OpcUa_StatusCode reason;				/* VAR_INPUT */	
	OpcUa_StatusCode SubscriptionParameterChangeCallback;	/* VAR_OUTPUT*/
} subscriptionparameterchangecallback_struct;

/**
* ATTENTION: Update the monitoreditemstatecallbackwrapper_struct of CmpOPCUAClient_ImplementationItf.m4 if
* the signature of this functions is changed
*/
typedef struct tagmonitoreditemstatecallback_struct
{
	RTS_IEC_HANDLE hMonitoredItem;			/* VAR_INPUT */
	RTS_IEC_UXINT pcbMonitoredItemData;		/* VAR_INPUT */
	RTS_IEC_INT newState;					/* VAR_INPUT */
	OpcUa_StatusCode reason;				/* VAR_INPUT */
	OpcUa_StatusCode MonitoredItemStateCallback;	/* VAR_OUTPUT*/
} monitoreditemstatecallback_struct;

/**
* ATTENTION: Update the monitoreditemparametercallbackwrapper_struct of CmpOPCUAClient_ImplementationItf.m4 if
* the signature of this functions is changed
*/
typedef struct tagmonitoreditemparametercallback_struct
{
	RTS_IEC_HANDLE hMonitoredItem;			/* VAR_INPUT */
	RTS_IEC_UXINT pcbMonitoredItemData;		/* VAR_INPUT */
	RTS_IEC_DINT monitoringMode;			/* VAR_INPUT */
	RTS_IEC_LREAL samplingInterval;			/* VAR_INPUT */
	RTS_IEC_UDINT queueSize;				/* VAR_INPUT */
	OpcUa_ExtensionObject filter;			/* VAR_INPUT */
	OpcUa_StatusCode reason;				/* VAR_INPUT */
	OpcUa_StatusCode MonitoredItemParameterCallback;	/* VAR_OUTPUT*/
} monitoreditemparametercallback_struct;

/**
* ATTENTION: Update the monitoreditemvaluecallbackwrapper_struct of CmpOPCUAClient_ImplementationItf.m4 if
* the signature of this functions is changed
*/
typedef struct tagmonitoreditemvaluecallback_struct
{
	RTS_IEC_HANDLE hMonitoredItem;			/* VAR_INPUT */
	RTS_IEC_UXINT pcbMonitoredItemData;		/* VAR_INPUT */
	OpcUa_DataValue value;					/* VAR_INPUT */
	OpcUa_StatusCode reason;				/* VAR_INPUT */
	OpcUa_StatusCode MonitoredItemValueCallback;	/* VAR_OUTPUT*/
} monitoreditemvaluecallback_struct;

/**
* ATTENTION: Update the monitoreditemeventcallbackwrapper_struct of CmpOPCUAClient_ImplementationItf.m4 if
* the signature of this functions is changed
*/
typedef struct tagmonitoreditemeventcallback_struct
{
	RTS_IEC_HANDLE hMonitoredItem;			/* VAR_INPUT */
	RTS_IEC_UXINT pcbMonitoredItemData;		/* VAR_INPUT */
	OpcUa_Int32 noOfEventFields;			/* VAR_INPUT */
	OpcUa_Variant* eventFields;				/* VAR_INPUT */
	OpcUa_StatusCode reason;				/* VAR_INPUT */
	OpcUa_StatusCode MonitoredItemEventCallback;	/* VAR_OUTPUT*/
} monitoreditemeventcallback_struct;

/**
* ATTENTION: Update the browsecallbackwrapper_struct of CmpOPCUAClient_ImplementationItf.m4 if
* the signature of this functions is changed
*/
typedef struct tagbrowsecallbackwrapper_struct
{
	RTS_IEC_HANDLE hConnection;			/* VAR_INPUT */
	RTS_IEC_UXINT pcbCallbackData;		/* VAR_INPUT */
	OpcUa_StatusCode serviceResult;		/* VAR_INPUT */
	OpcUa_UInt32 numOfResults;			/* VAR_INPUT */
	OpcUa_BrowseResult *results;		/* VAR_INPUT */
	OpcUa_StatusCode BrowseCallbackWrapper;	/* VAR_OUTPUT*/
} browsecallbackwrapper_struct;

/**
* ATTENTION: Update the browsenextcallbackwrapper_struct of CmpOPCUAClient_ImplementationItf.m4 if
* the signature of this functions is changed
*/
typedef struct tagbrowsenextcallbackwrapper_struct
{
	RTS_IEC_HANDLE hConnection;			/* VAR_INPUT */
	RTS_IEC_UXINT pcbCallbackData;		/* VAR_INPUT */
	OpcUa_StatusCode serviceResult;		/* VAR_INPUT */
	OpcUa_UInt32 numOfResults;			/* VAR_INPUT */
	OpcUa_BrowseResult *results;		/* VAR_INPUT */
	OpcUa_StatusCode BrowseNextCallbackWrapper;	/* VAR_OUTPUT*/
} browsenextcallbackwrapper_struct;

/**
* ATTENTION: Update the translatebrowsepathstonodeidscallbackwrapper_struct of CmpOPCUAClient_ImplementationItf.m4 if
* the signature of this functions is changed
*/
typedef struct tagtranslatebrowsepathstonodeidscallbackwrapper_struct
{
	RTS_IEC_HANDLE hConnection;			/* VAR_INPUT */
	RTS_IEC_UXINT pcbCallbackData;		/* VAR_INPUT */
	OpcUa_StatusCode serviceResult;		/* VAR_INPUT */
	OpcUa_UInt32 numOfResults;			/* VAR_INPUT */
	OpcUa_BrowsePathResult *results;	/* VAR_INPUT */
	OpcUa_StatusCode TranslateBrowsePathsToNodeIdsCallbackWrapper;	/* VAR_OUTPUT*/
} translatebrowsepathstonodeidscallbackwrapper_struct;

/**
* ATTENTION: Update the registernodescallbackwrapper_struct of CmpOPCUAClient_ImplementationItf.m4 if
* the signature of this functions is changed
*/
typedef struct tagregisternodescallbackwrapper_struct
{
	RTS_IEC_HANDLE hConnection;				/* VAR_INPUT */
	RTS_IEC_UXINT pcbCallbackData;			/* VAR_INPUT */
	OpcUa_StatusCode serviceResult;			/* VAR_INPUT */
	OpcUa_UInt32 numOfNodes;				/* VAR_INPUT */
	OpcUa_NodeId *registeredNodeIds;	/* VAR_INPUT */
	OpcUa_StatusCode RegisterNodesCallbackWrapper;	/* VAR_OUTPUT*/
} registernodescallbackwrapper_struct;

/**
* ATTENTION: Update the unregisternodescallbackwrapper_struct of CmpOPCUAClient_ImplementationItf.m4 if
* the signature of this functions is changed
*/
typedef struct tagunregisternodescallbackwrapper_struct
{
	RTS_IEC_HANDLE hConnection;			/* VAR_INPUT */
	RTS_IEC_UXINT pcbCallbackData;		/* VAR_INPUT */
	OpcUa_StatusCode serviceResult;		/* VAR_INPUT */
	OpcUa_StatusCode UnregisterNodesCallbackWrapper;	/* VAR_OUTPUT*/
} unregisternodescallbackwrapper_struct;

/** EXTERN LIB SECTION BEGIN **/
/*  Comments are ignored for m4 compiler so restructured text can be used. changecom(`/*', `*/') */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description>opcuaclient_browse_internal</description>
 */
typedef struct tagopcuaclient_browse_internal_struct
{
	RTS_IEC_HANDLE hConnection;			/* VAR_INPUT */	
	OpcUa_ViewDescription view;			/* VAR_INPUT */	
	RTS_IEC_DINT requestedMaxReferencesPerNode;	/* VAR_INPUT */	
	RTS_IEC_DINT noOfNodesToBrowse;		/* VAR_INPUT */	
	OpcUa_BrowseDescription *pNodesToBrowse;	/* VAR_INPUT */	
	RTS_IEC_BYTE *cbfCallback;			/* VAR_INPUT */	
	RTS_IEC_UXINT pcbCallbackData;		/* VAR_INPUT */	
	RTS_IEC_RESULT OPCUAClient_Browse_internal;	/* VAR_OUTPUT */	
} opcuaclient_browse_internal_struct;

DEF_API(`void',`CDECL',`opcuaclient_browse_internal',`(opcuaclient_browse_internal_struct *p)',1,RTSITF_GET_SIGNATURE(0x6BD93DFC, 0xC49DAFBB),0x03051000)

/**
 * <description>opcuaclient_browsenext_internal</description>
 */
typedef struct tagopcuaclient_browsenext_internal_struct
{
	RTS_IEC_HANDLE hConnection;			/* VAR_INPUT */	
	RTS_IEC_BOOL releaseContinuationPoints;	/* VAR_INPUT */	
	RTS_IEC_DINT noOfContinuationPoints;	/* VAR_INPUT */	
	OpcUa_ByteString *pContinuationPoints;	/* VAR_INPUT */	
	RTS_IEC_BYTE *cbfCallback;			/* VAR_INPUT */	
	RTS_IEC_UXINT pcbCallbackData;		/* VAR_INPUT */	
	RTS_IEC_RESULT OPCUAClient_BrowseNext_internal;	/* VAR_OUTPUT */	
} opcuaclient_browsenext_internal_struct;

DEF_API(`void',`CDECL',`opcuaclient_browsenext_internal',`(opcuaclient_browsenext_internal_struct *p)',1,RTSITF_GET_SIGNATURE(0xD8FD4FBA, 0x96744413),0x03051000)

/**
 * <description>opcuaclient_connect_internal</description>
 */
typedef struct tagopcuaclient_connect_internal_struct
{
	RTS_IEC_HANDLE hClient;				/* VAR_INPUT */	
	OPCUAClientConnectionConfiguration *pConnectionConfiguration;	/* VAR_INPUT */	
	RTS_IEC_BYTE *cbfConnection;		/* VAR_INPUT */	
	RTS_IEC_UXINT pcbConnectionData;	/* VAR_INPUT */	
	RTS_IEC_BYTE *cbfVerifyCertificate;	/* VAR_INPUT */	
	RTS_IEC_UXINT pcbVerifyCertData;	/* VAR_INPUT */	
	RTS_IEC_BYTE *cbfGetCredentials;	/* VAR_INPUT */	
	RTS_IEC_UXINT pcbGetCredentialsData;	/* VAR_INPUT */	
	RTS_IEC_HANDLE OPCUAClient_Connect_internal;	/* VAR_OUTPUT */	
} opcuaclient_connect_internal_struct;

DEF_API(`void',`CDECL',`opcuaclient_connect_internal',`(opcuaclient_connect_internal_struct *p)',1,RTSITF_GET_SIGNATURE(0xBB6335AF, 0xF9429CFA),0x03051000)

/**
 * <description>opcuaclient_create_internal</description>
 */
typedef struct tagopcuaclient_create_internal_struct
{
	OpcUa_ApplicationDescription *pConfiguration;	/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_HANDLE OPCUAClient_Create_internal;	/* VAR_OUTPUT */	
} opcuaclient_create_internal_struct;

DEF_API(`void',`CDECL',`opcuaclient_create_internal',`(opcuaclient_create_internal_struct *p)',1,0x8877DB57,0x03051000)

/**
 * <description>opcuaclient_createmonitoreditems_internal</description>
 */
typedef struct tagopcuaclient_createmonitoreditems_internal_struct
{
	RTS_IEC_HANDLE hSubscription;		/* VAR_INPUT */	
	RTS_IEC_DINT eTimestampsToReturn;	/* VAR_INPUT, Enum: OPCUA_TIMESTAMPSTORETURN */
	RTS_IEC_DINT noOfItemsToCreate;		/* VAR_INPUT */	
	OPCUAClientMonitoredItemConfiguration *pMonitoredItemsToCreate;	/* VAR_INPUT */	
	RTS_IEC_BYTE *cbfMonitoredItemState;	/* VAR_INPUT */	
	RTS_IEC_BYTE *cbfMonitoredItemParam;	/* VAR_INPUT */	
	RTS_IEC_BYTE *cbfMonitoredItemValue;	/* VAR_INPUT */	
	RTS_IEC_BYTE *cbfMonitoredItemEvent;	/* VAR_INPUT */	
	RTS_IEC_RESULT OPCUAClient_CreateMonitoredItems_internal;	/* VAR_OUTPUT */	
} opcuaclient_createmonitoreditems_internal_struct;

DEF_API(`void',`CDECL',`opcuaclient_createmonitoreditems_internal',`(opcuaclient_createmonitoreditems_internal_struct *p)',1,RTSITF_GET_SIGNATURE(0x78929EB6, 0x015C5817),0x03051000)

/**
 * <description>opcuaclient_createsubscription_internal</description>
 */
typedef struct tagopcuaclient_createsubscription_internal_struct
{
	RTS_IEC_HANDLE hConnection;			/* VAR_INPUT */	
	RTS_IEC_LREAL publishingInterval;	/* VAR_INPUT */	
	RTS_IEC_UDINT lifetimeCount;		/* VAR_INPUT */	
	RTS_IEC_UDINT maxKeepAliveCount;	/* VAR_INPUT */	
	RTS_IEC_UDINT maxNotificationsPerPublish;	/* VAR_INPUT */	
	RTS_IEC_BOOL publishingEnabled;		/* VAR_INPUT */	
	RTS_IEC_USINT priority;				/* VAR_INPUT */	
	RTS_IEC_BYTE *cbfSubscriptionState;	/* VAR_INPUT */	
	RTS_IEC_UXINT pcbSubscriptionStateData;	/* VAR_INPUT */	
	RTS_IEC_BYTE *cbfSubscriptionParameter;	/* VAR_INPUT */	
	RTS_IEC_UXINT pcbSubscriptionParameterData;	/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_HANDLE OPCUAClient_CreateSubscription_internal;	/* VAR_OUTPUT */	
} opcuaclient_createsubscription_internal_struct;

DEF_API(`void',`CDECL',`opcuaclient_createsubscription_internal',`(opcuaclient_createsubscription_internal_struct *p)',1,RTSITF_GET_SIGNATURE(0x479BC219, 0x6B7DAD5C),0x03051000)

/**
 * Delete an OPC UA client. This will close all connections and cleanup 
 * all ressources used by this client instance.
 */
typedef struct tagopcuaclient_delete_struct
{
	RTS_IEC_HANDLE hClient;				/* VAR_INPUT */	/* Hanlde of the OPC UA client created with OPCUAClient_Create. */
	RTS_IEC_RESULT OPCUAClient_Delete;	/* VAR_OUTPUT */	
} opcuaclient_delete_struct;

DEF_API(`void',`CDECL',`opcuaclient_delete',`(opcuaclient_delete_struct *p)',1,0xCEA47AB5,0x03051000)

/**
 * This function deletes a set of monitored items from a subscription.
 */
typedef struct tagopcuaclient_deletemonitoreditems_struct
{
	RTS_IEC_HANDLE hSubscription;		/* VAR_INPUT */	/* Handle to the subscription of the monitored items */
	RTS_IEC_DINT noOfItemsToDelete;		/* VAR_INPUT */	/* Number of items to delete. */
	RTS_IEC_HANDLE *phItems;			/* VAR_INPUT */	/* Pointer to an array of monitored item handles. */
	RTS_IEC_RESULT OPCUAClient_DeleteMonitoredItems;	/* VAR_OUTPUT */	
} opcuaclient_deletemonitoreditems_struct;

DEF_API(`void',`CDECL',`opcuaclient_deletemonitoreditems',`(opcuaclient_deletemonitoreditems_struct *p)',1,0x7D549257,0x03051000)

/**
 * This function deletes a subscription and all assigned monitored items on the server.
 */
typedef struct tagopcuaclient_deletesubscription_struct
{
	RTS_IEC_HANDLE hSubscription;		/* VAR_INPUT */	/* Handle to the subscription to delete. */
	RTS_IEC_RESULT OPCUAClient_DeleteSubscription;	/* VAR_OUTPUT */	
} opcuaclient_deletesubscription_struct;

DEF_API(`void',`CDECL',`opcuaclient_deletesubscription',`(opcuaclient_deletesubscription_struct *p)',1,0x8F3E26C1,0x03051000)

/**
 * Disconnect the OPC UA client. All ressources dedicated to this session will be cleand up.
 */
typedef struct tagopcuaclient_disconnect_struct
{
	RTS_IEC_HANDLE hConnection;			/* VAR_INPUT */	/* Handle to the connection to disconnect. */
	RTS_IEC_RESULT OPCUAClient_Disconnect;	/* VAR_OUTPUT */	
} opcuaclient_disconnect_struct;

DEF_API(`void',`CDECL',`opcuaclient_disconnect',`(opcuaclient_disconnect_struct *p)',1,0x7D055791,0x03051000)

/**
 * <description>opcuaclient_extensionobjectattachreadonly</description>
 */
typedef struct tagopcuaclient_extensionobjectattachreadonly_struct
{
	RTS_IEC_UDINT TypeId;				/* VAR_INPUT */	
	OpcUa_ExtensionObject *pExtensionObject;	/* VAR_INPUT */	
	RTS_IEC_BYTE *pObject;				/* VAR_INPUT */	
	RTS_IEC_RESULT OPCUAClient_ExtensionObjectAttachReadOnly;	/* VAR_OUTPUT */	
} opcuaclient_extensionobjectattachreadonly_struct;

DEF_API(`void',`CDECL',`opcuaclient_extensionobjectattachreadonly',`(opcuaclient_extensionobjectattachreadonly_struct *p)',1,0x18A06F69,0x03051000)

/**
 * <description>opcuaclient_findservers_internal</description>
 */
typedef struct tagopcuaclient_findservers_internal_struct
{
	RTS_IEC_HANDLE hClient;				/* VAR_INPUT */	
	OpcUa_String *psEndpointURL;		/* VAR_INPUT */	
	RTS_IEC_BYTE *cbfFindServers;		/* VAR_INPUT */	
	RTS_IEC_UXINT pcbFindServers;		/* VAR_INPUT */	
	RTS_IEC_RESULT OPCUAClient_FindServers_internal;	/* VAR_OUTPUT */	
} opcuaclient_findservers_internal_struct;

DEF_API(`void',`CDECL',`opcuaclient_findservers_internal',`(opcuaclient_findservers_internal_struct *p)',1,RTSITF_GET_SIGNATURE(0x1DA83372, 0xAB40D53F),0x03051000)

/**
 * <description>opcuaclient_findserversonnetwork_internal</description>
 */
typedef struct tagopcuaclient_findserversonnetwork_internal_struct
{
	RTS_IEC_HANDLE hClient;				/* VAR_INPUT */	
	OpcUa_String *psEndpointURL;		/* VAR_INPUT */	
	RTS_IEC_UDINT udiStartingRecordId;	/* VAR_INPUT */	
	RTS_IEC_UDINT udiMaxRecordsToReturn;	/* VAR_INPUT */	
	RTS_IEC_DINT numServerCapabilityFilters;	/* VAR_INPUT */	
	OpcUa_String *psServerCapabilityFilters;	/* VAR_INPUT */	
	RTS_IEC_BYTE *cbfFindServersOnNetwork;	/* VAR_INPUT */	
	RTS_IEC_UXINT pcbFindServersOnNetwork;	/* VAR_INPUT */	
	RTS_IEC_RESULT OPCUAClient_FindServersOnNetwork_internal;	/* VAR_OUTPUT */	
} opcuaclient_findserversonnetwork_internal_struct;

DEF_API(`void',`CDECL',`opcuaclient_findserversonnetwork_internal',`(opcuaclient_findserversonnetwork_internal_struct *p)',1,RTSITF_GET_SIGNATURE(0x71C0561A, 0x246AA4A9),0x03051000)

/**
 * Retrieve the configuration of specific OPC UA client.
 */
typedef struct tagopcuaclient_getconfig_struct
{
	RTS_IEC_HANDLE hClient;				/* VAR_INPUT */	/* Handle to the OPC UA client. */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Result of the operation. */
	OpcUa_ApplicationDescription *OPCUAClient_GetConfig;	/* VAR_OUTPUT */	
} opcuaclient_getconfig_struct;

DEF_API(`void',`CDECL',`opcuaclient_getconfig',`(opcuaclient_getconfig_struct *p)',1,0xDF886940,0x03051000)

/**
 * <description>opcuaclient_getendpoints_internal</description>
 */
typedef struct tagopcuaclient_getendpoints_internal_struct
{
	RTS_IEC_HANDLE hClient;				/* VAR_INPUT */	
	OpcUa_String *psEndpointURL;		/* VAR_INPUT */	
	RTS_IEC_BYTE *cbfGetEndpoints;		/* VAR_INPUT */	
	RTS_IEC_UXINT pcbGetEndpoints;		/* VAR_INPUT */	
	RTS_IEC_RESULT OPCUAClient_GetEndpoints_internal;	/* VAR_OUTPUT */	
} opcuaclient_getendpoints_internal_struct;

DEF_API(`void',`CDECL',`opcuaclient_getendpoints_internal',`(opcuaclient_getendpoints_internal_struct *p)',1,RTSITF_GET_SIGNATURE(0x88FF5C72, 0xE23AC925),0x03051000)

/**
 * <description>opcuaclient_modifymonitoreditems_internal</description>
 */
typedef struct tagopcuaclient_modifymonitoreditems_internal_struct
{
	RTS_IEC_HANDLE hSubscription;		/* VAR_INPUT */	
	RTS_IEC_DINT eTimestampsToReturn;	/* VAR_INPUT, Enum: OPCUA_TIMESTAMPSTORETURN */
	RTS_IEC_DINT noOfItemsToModify;		/* VAR_INPUT */	
	OPCUAClientMonitoredItemConfiguration *pMonitoredItemsToModify;	/* VAR_INPUT */	
	RTS_IEC_RESULT OPCUAClient_ModifyMonitoredItems_internal;	/* VAR_OUTPUT */	
} opcuaclient_modifymonitoreditems_internal_struct;

DEF_API(`void',`CDECL',`opcuaclient_modifymonitoreditems_internal',`(opcuaclient_modifymonitoreditems_internal_struct *p)',1,RTSITF_GET_SIGNATURE(0xF325D610, 0x971FB0CA),0x03051000)

/**
 * <description>opcuaclient_modifysubscription_internal</description>
 */
typedef struct tagopcuaclient_modifysubscription_internal_struct
{
	RTS_IEC_HANDLE hSubscription;		/* VAR_INPUT */	
	RTS_IEC_LREAL reqPublishingInterval;	/* VAR_INPUT */	
	RTS_IEC_UDINT reqLifeTimeCount;		/* VAR_INPUT */	
	RTS_IEC_UDINT reqMaxKeepAliveCount;	/* VAR_INPUT */	
	RTS_IEC_UDINT maxNotificationsPerPublish;	/* VAR_INPUT */	
	RTS_IEC_USINT priority;				/* VAR_INPUT */	
	RTS_IEC_RESULT OPCUAClient_ModifySubscription_internal;	/* VAR_OUTPUT */	
} opcuaclient_modifysubscription_internal_struct;

DEF_API(`void',`CDECL',`opcuaclient_modifysubscription_internal',`(opcuaclient_modifysubscription_internal_struct *p)',1,0xFD8D1AF6,0x03051000)

/**
 * <description>opcuaclient_read_internal</description>
 */
typedef struct tagopcuaclient_read_internal_struct
{
	RTS_IEC_HANDLE hConnection;			/* VAR_INPUT */	
	RTS_IEC_LREAL maxAge;				/* VAR_INPUT */	
	RTS_IEC_DINT timestampsToReturn;	/* VAR_INPUT, Enum: OPCUA_TIMESTAMPSTORETURN */
	OpcUa_ReadValueId *pNodesToRead;	/* VAR_INPUT */	
	RTS_IEC_DINT numNodes;				/* VAR_INPUT */	
	RTS_IEC_BYTE *cbfReadCallback;		/* VAR_INPUT */	
	RTS_IEC_UXINT pcbCallbackData;		/* VAR_INPUT */	
	RTS_IEC_RESULT OPCUAClient_Read_internal;	/* VAR_OUTPUT */	
} opcuaclient_read_internal_struct;

DEF_API(`void',`CDECL',`opcuaclient_read_internal',`(opcuaclient_read_internal_struct *p)',1,RTSITF_GET_SIGNATURE(0x0C31538B, 0x83047E1E),0x03051000)

/**
 * <description>opcuaclient_registernodes_internal</description>
 */
typedef struct tagopcuaclient_registernodes_internal_struct
{
	RTS_IEC_HANDLE hConnection;			/* VAR_INPUT */	
	RTS_IEC_DINT noOfNodesToRegister;	/* VAR_INPUT */	
	OpcUa_NodeId *pNodesToRegister;		/* VAR_INPUT */	
	RTS_IEC_BYTE *cbfCallback;			/* VAR_INPUT */	
	RTS_IEC_UXINT pcbCallbackData;		/* VAR_INPUT */	
	RTS_IEC_RESULT OPCUAClient_RegisterNodes_internal;	/* VAR_OUTPUT */	
} opcuaclient_registernodes_internal_struct;

DEF_API(`void',`CDECL',`opcuaclient_registernodes_internal',`(opcuaclient_registernodes_internal_struct *p)',1,RTSITF_GET_SIGNATURE(0xCC5F5C06, 0x195A207A),0x03051000)

/**
 * <description>opcuaclient_setmonitoringmode_internal</description>
 */
typedef struct tagopcuaclient_setmonitoringmode_internal_struct
{
	RTS_IEC_HANDLE hSubscription;		/* VAR_INPUT */	
	RTS_IEC_DINT monitoringMode;		/* VAR_INPUT, Enum: OPCUA_MONITORINGMODE */
	RTS_IEC_DINT noOfMonitoredItems;	/* VAR_INPUT */	
	RTS_IEC_HANDLE *phItems;			/* VAR_INPUT */	
	RTS_IEC_RESULT OPCUAClient_SetMonitoringMode_internal;	/* VAR_OUTPUT */	
} opcuaclient_setmonitoringmode_internal_struct;

DEF_API(`void',`CDECL',`opcuaclient_setmonitoringmode_internal',`(opcuaclient_setmonitoringmode_internal_struct *p)',1,0x19605156,0x03051000)

/**
 * <description>opcuaclient_setpublishingmode_internal</description>
 */
typedef struct tagopcuaclient_setpublishingmode_internal_struct
{
	RTS_IEC_HANDLE hSubscription;		/* VAR_INPUT */	
	RTS_IEC_BOOL publishingEnabled;		/* VAR_INPUT */	
	RTS_IEC_RESULT OPCUAClient_SetPublishingMode_internal;	/* VAR_OUTPUT */	
} opcuaclient_setpublishingmode_internal_struct;

DEF_API(`void',`CDECL',`opcuaclient_setpublishingmode_internal',`(opcuaclient_setpublishingmode_internal_struct *p)',1,0xE984A6EF,0x03051000)

/**
 * <description>opcuaclient_translatebrowsepathstonodeids_internal</description>
 */
typedef struct tagopcuaclient_translatebrowsepathstonodeids_internal_struct
{
	RTS_IEC_HANDLE hConnection;			/* VAR_INPUT */	
	RTS_IEC_DINT noOfBrowsePaths;		/* VAR_INPUT */	
	OpcUa_BrowsePath *pBrowsePaths;		/* VAR_INPUT */	
	RTS_IEC_BYTE *cbfCallback;			/* VAR_INPUT */	
	RTS_IEC_UXINT pcbCallbackData;		/* VAR_INPUT */	
	RTS_IEC_RESULT OPCUAClient_TranslateBrowsePathsToNodeIds_internal;	/* VAR_OUTPUT */	
} opcuaclient_translatebrowsepathstonodeids_internal_struct;

DEF_API(`void',`CDECL',`opcuaclient_translatebrowsepathstonodeids_internal',`(opcuaclient_translatebrowsepathstonodeids_internal_struct *p)',1,RTSITF_GET_SIGNATURE(0xAD7C432A, 0x0EEA6B66),0x03051000)

/**
 * <description>opcuaclient_unregisternodes_internal</description>
 */
typedef struct tagopcuaclient_unregisternodes_internal_struct
{
	RTS_IEC_HANDLE hConnection;			/* VAR_INPUT */	
	RTS_IEC_DINT noOfNodesToUnregister;	/* VAR_INPUT */	
	OpcUa_NodeId *pNodesToUnregister;	/* VAR_INPUT */	
	RTS_IEC_BYTE *cbfCallback;			/* VAR_INPUT */	
	RTS_IEC_UXINT pcbCallbackData;		/* VAR_INPUT */	
	RTS_IEC_RESULT OPCUAClient_UnregisterNodes_internal;	/* VAR_OUTPUT */	
} opcuaclient_unregisternodes_internal_struct;

DEF_API(`void',`CDECL',`opcuaclient_unregisternodes_internal',`(opcuaclient_unregisternodes_internal_struct *p)',1,RTSITF_GET_SIGNATURE(0xE6C50D5E, 0x9B084061),0x03051000)

/**
 * <description>opcuaclient_write_internal</description>
 */
typedef struct tagopcuaclient_write_internal_struct
{
	RTS_IEC_HANDLE hConnection;			/* VAR_INPUT */	
	OpcUa_WriteValue *pNodesToWrite;	/* VAR_INPUT */	
	RTS_IEC_DINT numOfNodes;			/* VAR_INPUT */	
	RTS_IEC_BYTE *cbfWriteCallback;		/* VAR_INPUT */	
	RTS_IEC_UXINT pcbCallbackData;		/* VAR_INPUT */	
	RTS_IEC_RESULT OPCUAClient_Write_internal;	/* VAR_OUTPUT */	
} opcuaclient_write_internal_struct;

DEF_API(`void',`CDECL',`opcuaclient_write_internal',`(opcuaclient_write_internal_struct *p)',1,RTSITF_GET_SIGNATURE(0x3300C94E, 0x231AEA7F),0x03051000)

#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/

