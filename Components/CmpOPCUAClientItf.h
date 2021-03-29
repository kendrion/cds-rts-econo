 /**
 * <interfacename>CmpOPCUAClient</interfacename>
 * <description></description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */
 

	
	
#ifndef _CMPOPCUACLIENTITF_H_
#define _CMPOPCUACLIENTITF_H_

#include "CmpStd.h"

 

 





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
/*  Comments are ignored for m4 compiler so restructured text can be used.  */

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
RTS_HANDLE CDECL OPCUAClient_Create(OpcUa_ApplicationDescription *pConfiguration, RTS_RESULT *pResult);
typedef RTS_HANDLE (CDECL * PFOPCUACLIENT_CREATE) (OpcUa_ApplicationDescription *pConfiguration, RTS_RESULT *pResult);
#if defined(CMPOPCUACLIENT_NOTIMPLEMENTED) || defined(OPCUACLIENT_CREATE_NOTIMPLEMENTED)
	#define USE_OPCUAClient_Create
	#define EXT_OPCUAClient_Create
	#define GET_OPCUAClient_Create(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OPCUAClient_Create(p0,p1)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_OPCUAClient_Create  FALSE
	#define EXP_OPCUAClient_Create  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OPCUAClient_Create
	#define EXT_OPCUAClient_Create
	#define GET_OPCUAClient_Create(fl)  CAL_CMGETAPI( "OPCUAClient_Create" ) 
	#define CAL_OPCUAClient_Create  OPCUAClient_Create
	#define CHK_OPCUAClient_Create  TRUE
	#define EXP_OPCUAClient_Create  CAL_CMEXPAPI( "OPCUAClient_Create" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_EXTERNAL)
	#define USE_OPCUAClient_Create
	#define EXT_OPCUAClient_Create
	#define GET_OPCUAClient_Create(fl)  CAL_CMGETAPI( "OPCUAClient_Create" ) 
	#define CAL_OPCUAClient_Create  OPCUAClient_Create
	#define CHK_OPCUAClient_Create  TRUE
	#define EXP_OPCUAClient_Create  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_Create", (RTS_UINTPTR)OPCUAClient_Create, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClientOPCUAClient_Create
	#define EXT_CmpOPCUAClientOPCUAClient_Create
	#define GET_CmpOPCUAClientOPCUAClient_Create  ERR_OK
	#define CAL_CmpOPCUAClientOPCUAClient_Create pICmpOPCUAClient->IOPCUAClient_Create
	#define CHK_CmpOPCUAClientOPCUAClient_Create (pICmpOPCUAClient != NULL)
	#define EXP_CmpOPCUAClientOPCUAClient_Create  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OPCUAClient_Create
	#define EXT_OPCUAClient_Create
	#define GET_OPCUAClient_Create(fl)  CAL_CMGETAPI( "OPCUAClient_Create" ) 
	#define CAL_OPCUAClient_Create pICmpOPCUAClient->IOPCUAClient_Create
	#define CHK_OPCUAClient_Create (pICmpOPCUAClient != NULL)
	#define EXP_OPCUAClient_Create  CAL_CMEXPAPI( "OPCUAClient_Create" ) 
#else /* DYNAMIC_LINK */
	#define USE_OPCUAClient_Create  PFOPCUACLIENT_CREATE pfOPCUAClient_Create;
	#define EXT_OPCUAClient_Create  extern PFOPCUACLIENT_CREATE pfOPCUAClient_Create;
	#define GET_OPCUAClient_Create(fl)  s_pfCMGetAPI2( "OPCUAClient_Create", (RTS_VOID_FCTPTR *)&pfOPCUAClient_Create, (fl), 0, 0)
	#define CAL_OPCUAClient_Create  pfOPCUAClient_Create
	#define CHK_OPCUAClient_Create  (pfOPCUAClient_Create != NULL)
	#define EXP_OPCUAClient_Create  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_Create", (RTS_UINTPTR)OPCUAClient_Create, 0, 0) 
#endif




RTS_RESULT CDECL OPCUAClient_Delete(RTS_HANDLE hClient);
typedef RTS_RESULT (CDECL * PFOPCUACLIENT_DELETE) (RTS_HANDLE hClient);
#if defined(CMPOPCUACLIENT_NOTIMPLEMENTED) || defined(OPCUACLIENT_DELETE_NOTIMPLEMENTED)
	#define USE_OPCUAClient_Delete
	#define EXT_OPCUAClient_Delete
	#define GET_OPCUAClient_Delete(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OPCUAClient_Delete(p0)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_OPCUAClient_Delete  FALSE
	#define EXP_OPCUAClient_Delete  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OPCUAClient_Delete
	#define EXT_OPCUAClient_Delete
	#define GET_OPCUAClient_Delete(fl)  CAL_CMGETAPI( "OPCUAClient_Delete" ) 
	#define CAL_OPCUAClient_Delete  OPCUAClient_Delete
	#define CHK_OPCUAClient_Delete  TRUE
	#define EXP_OPCUAClient_Delete  CAL_CMEXPAPI( "OPCUAClient_Delete" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_EXTERNAL)
	#define USE_OPCUAClient_Delete
	#define EXT_OPCUAClient_Delete
	#define GET_OPCUAClient_Delete(fl)  CAL_CMGETAPI( "OPCUAClient_Delete" ) 
	#define CAL_OPCUAClient_Delete  OPCUAClient_Delete
	#define CHK_OPCUAClient_Delete  TRUE
	#define EXP_OPCUAClient_Delete  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_Delete", (RTS_UINTPTR)OPCUAClient_Delete, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClientOPCUAClient_Delete
	#define EXT_CmpOPCUAClientOPCUAClient_Delete
	#define GET_CmpOPCUAClientOPCUAClient_Delete  ERR_OK
	#define CAL_CmpOPCUAClientOPCUAClient_Delete pICmpOPCUAClient->IOPCUAClient_Delete
	#define CHK_CmpOPCUAClientOPCUAClient_Delete (pICmpOPCUAClient != NULL)
	#define EXP_CmpOPCUAClientOPCUAClient_Delete  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OPCUAClient_Delete
	#define EXT_OPCUAClient_Delete
	#define GET_OPCUAClient_Delete(fl)  CAL_CMGETAPI( "OPCUAClient_Delete" ) 
	#define CAL_OPCUAClient_Delete pICmpOPCUAClient->IOPCUAClient_Delete
	#define CHK_OPCUAClient_Delete (pICmpOPCUAClient != NULL)
	#define EXP_OPCUAClient_Delete  CAL_CMEXPAPI( "OPCUAClient_Delete" ) 
#else /* DYNAMIC_LINK */
	#define USE_OPCUAClient_Delete  PFOPCUACLIENT_DELETE pfOPCUAClient_Delete;
	#define EXT_OPCUAClient_Delete  extern PFOPCUACLIENT_DELETE pfOPCUAClient_Delete;
	#define GET_OPCUAClient_Delete(fl)  s_pfCMGetAPI2( "OPCUAClient_Delete", (RTS_VOID_FCTPTR *)&pfOPCUAClient_Delete, (fl), 0, 0)
	#define CAL_OPCUAClient_Delete  pfOPCUAClient_Delete
	#define CHK_OPCUAClient_Delete  (pfOPCUAClient_Delete != NULL)
	#define EXP_OPCUAClient_Delete  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_Delete", (RTS_UINTPTR)OPCUAClient_Delete, 0, 0) 
#endif




OpcUa_ApplicationDescription* CDECL OPCUAClient_GetConfig(RTS_HANDLE hClient, RTS_RESULT *pResult);
typedef OpcUa_ApplicationDescription* (CDECL * PFOPCUACLIENT_GETCONFIG) (RTS_HANDLE hClient, RTS_RESULT *pResult);
#if defined(CMPOPCUACLIENT_NOTIMPLEMENTED) || defined(OPCUACLIENT_GETCONFIG_NOTIMPLEMENTED)
	#define USE_OPCUAClient_GetConfig
	#define EXT_OPCUAClient_GetConfig
	#define GET_OPCUAClient_GetConfig(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OPCUAClient_GetConfig(p0,p1)  (OpcUa_ApplicationDescription*)ERR_NOTIMPLEMENTED
	#define CHK_OPCUAClient_GetConfig  FALSE
	#define EXP_OPCUAClient_GetConfig  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OPCUAClient_GetConfig
	#define EXT_OPCUAClient_GetConfig
	#define GET_OPCUAClient_GetConfig(fl)  CAL_CMGETAPI( "OPCUAClient_GetConfig" ) 
	#define CAL_OPCUAClient_GetConfig  OPCUAClient_GetConfig
	#define CHK_OPCUAClient_GetConfig  TRUE
	#define EXP_OPCUAClient_GetConfig  CAL_CMEXPAPI( "OPCUAClient_GetConfig" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_EXTERNAL)
	#define USE_OPCUAClient_GetConfig
	#define EXT_OPCUAClient_GetConfig
	#define GET_OPCUAClient_GetConfig(fl)  CAL_CMGETAPI( "OPCUAClient_GetConfig" ) 
	#define CAL_OPCUAClient_GetConfig  OPCUAClient_GetConfig
	#define CHK_OPCUAClient_GetConfig  TRUE
	#define EXP_OPCUAClient_GetConfig  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_GetConfig", (RTS_UINTPTR)OPCUAClient_GetConfig, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClientOPCUAClient_GetConfig
	#define EXT_CmpOPCUAClientOPCUAClient_GetConfig
	#define GET_CmpOPCUAClientOPCUAClient_GetConfig  ERR_OK
	#define CAL_CmpOPCUAClientOPCUAClient_GetConfig pICmpOPCUAClient->IOPCUAClient_GetConfig
	#define CHK_CmpOPCUAClientOPCUAClient_GetConfig (pICmpOPCUAClient != NULL)
	#define EXP_CmpOPCUAClientOPCUAClient_GetConfig  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OPCUAClient_GetConfig
	#define EXT_OPCUAClient_GetConfig
	#define GET_OPCUAClient_GetConfig(fl)  CAL_CMGETAPI( "OPCUAClient_GetConfig" ) 
	#define CAL_OPCUAClient_GetConfig pICmpOPCUAClient->IOPCUAClient_GetConfig
	#define CHK_OPCUAClient_GetConfig (pICmpOPCUAClient != NULL)
	#define EXP_OPCUAClient_GetConfig  CAL_CMEXPAPI( "OPCUAClient_GetConfig" ) 
#else /* DYNAMIC_LINK */
	#define USE_OPCUAClient_GetConfig  PFOPCUACLIENT_GETCONFIG pfOPCUAClient_GetConfig;
	#define EXT_OPCUAClient_GetConfig  extern PFOPCUACLIENT_GETCONFIG pfOPCUAClient_GetConfig;
	#define GET_OPCUAClient_GetConfig(fl)  s_pfCMGetAPI2( "OPCUAClient_GetConfig", (RTS_VOID_FCTPTR *)&pfOPCUAClient_GetConfig, (fl), 0, 0)
	#define CAL_OPCUAClient_GetConfig  pfOPCUAClient_GetConfig
	#define CHK_OPCUAClient_GetConfig  (pfOPCUAClient_GetConfig != NULL)
	#define EXP_OPCUAClient_GetConfig  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_GetConfig", (RTS_UINTPTR)OPCUAClient_GetConfig, 0, 0) 
#endif



 
/*********************************************************************
 * Discovery Services (can be sent without connecting the client!) [Facet=CORE]
 *********************************************************************/
typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_GETENDPOINTS_CALLBACK)(RTS_HANDLE hClient, RTS_UINTPTR pcbGetEndpointsData, OpcUa_StatusCode uStatus,  OpcUa_Int32 numOfEndpoints, OpcUa_EndpointDescription* pEndpoints);
typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_FINDSERVERS_CALLBACK)(RTS_HANDLE hClient, RTS_UINTPTR pcbFindServersData, OpcUa_StatusCode uStatus, OpcUa_Int32 numOfServers, OpcUa_ApplicationDescription *pServerList);
typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_FINDSERVERSONNETWORK_CALLBACK)(RTS_HANDLE hClient, RTS_UINTPTR pcbFindServersOnNetworkData, OpcUa_StatusCode uStatus, OpcUa_DateTime lastCounterResetTime, OpcUa_Int32 numOfServers, OpcUa_ServerOnNetwork *pServerList);
                                                                
RTS_RESULT CDECL OPCUAClientDiscovery_GetEndpoints(RTS_HANDLE hClient, OpcUa_String* psEndpointURL, PF_OPCUACLIENT_GETENDPOINTS_CALLBACK cbfGetEndpoints, RTS_UINTPTR pcbGetEndpointsData);
typedef RTS_RESULT (CDECL * PFOPCUACLIENTDISCOVERY_GETENDPOINTS) (RTS_HANDLE hClient, OpcUa_String* psEndpointURL, PF_OPCUACLIENT_GETENDPOINTS_CALLBACK cbfGetEndpoints, RTS_UINTPTR pcbGetEndpointsData);
#if defined(CMPOPCUACLIENT_NOTIMPLEMENTED) || defined(OPCUACLIENTDISCOVERY_GETENDPOINTS_NOTIMPLEMENTED)
	#define USE_OPCUAClientDiscovery_GetEndpoints
	#define EXT_OPCUAClientDiscovery_GetEndpoints
	#define GET_OPCUAClientDiscovery_GetEndpoints(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OPCUAClientDiscovery_GetEndpoints(p0,p1,p2,p3)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_OPCUAClientDiscovery_GetEndpoints  FALSE
	#define EXP_OPCUAClientDiscovery_GetEndpoints  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OPCUAClientDiscovery_GetEndpoints
	#define EXT_OPCUAClientDiscovery_GetEndpoints
	#define GET_OPCUAClientDiscovery_GetEndpoints(fl)  CAL_CMGETAPI( "OPCUAClientDiscovery_GetEndpoints" ) 
	#define CAL_OPCUAClientDiscovery_GetEndpoints  OPCUAClientDiscovery_GetEndpoints
	#define CHK_OPCUAClientDiscovery_GetEndpoints  TRUE
	#define EXP_OPCUAClientDiscovery_GetEndpoints  CAL_CMEXPAPI( "OPCUAClientDiscovery_GetEndpoints" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_EXTERNAL)
	#define USE_OPCUAClientDiscovery_GetEndpoints
	#define EXT_OPCUAClientDiscovery_GetEndpoints
	#define GET_OPCUAClientDiscovery_GetEndpoints(fl)  CAL_CMGETAPI( "OPCUAClientDiscovery_GetEndpoints" ) 
	#define CAL_OPCUAClientDiscovery_GetEndpoints  OPCUAClientDiscovery_GetEndpoints
	#define CHK_OPCUAClientDiscovery_GetEndpoints  TRUE
	#define EXP_OPCUAClientDiscovery_GetEndpoints  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClientDiscovery_GetEndpoints", (RTS_UINTPTR)OPCUAClientDiscovery_GetEndpoints, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClientOPCUAClientDiscovery_GetEndpoints
	#define EXT_CmpOPCUAClientOPCUAClientDiscovery_GetEndpoints
	#define GET_CmpOPCUAClientOPCUAClientDiscovery_GetEndpoints  ERR_OK
	#define CAL_CmpOPCUAClientOPCUAClientDiscovery_GetEndpoints pICmpOPCUAClient->IOPCUAClientDiscovery_GetEndpoints
	#define CHK_CmpOPCUAClientOPCUAClientDiscovery_GetEndpoints (pICmpOPCUAClient != NULL)
	#define EXP_CmpOPCUAClientOPCUAClientDiscovery_GetEndpoints  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OPCUAClientDiscovery_GetEndpoints
	#define EXT_OPCUAClientDiscovery_GetEndpoints
	#define GET_OPCUAClientDiscovery_GetEndpoints(fl)  CAL_CMGETAPI( "OPCUAClientDiscovery_GetEndpoints" ) 
	#define CAL_OPCUAClientDiscovery_GetEndpoints pICmpOPCUAClient->IOPCUAClientDiscovery_GetEndpoints
	#define CHK_OPCUAClientDiscovery_GetEndpoints (pICmpOPCUAClient != NULL)
	#define EXP_OPCUAClientDiscovery_GetEndpoints  CAL_CMEXPAPI( "OPCUAClientDiscovery_GetEndpoints" ) 
#else /* DYNAMIC_LINK */
	#define USE_OPCUAClientDiscovery_GetEndpoints  PFOPCUACLIENTDISCOVERY_GETENDPOINTS pfOPCUAClientDiscovery_GetEndpoints;
	#define EXT_OPCUAClientDiscovery_GetEndpoints  extern PFOPCUACLIENTDISCOVERY_GETENDPOINTS pfOPCUAClientDiscovery_GetEndpoints;
	#define GET_OPCUAClientDiscovery_GetEndpoints(fl)  s_pfCMGetAPI2( "OPCUAClientDiscovery_GetEndpoints", (RTS_VOID_FCTPTR *)&pfOPCUAClientDiscovery_GetEndpoints, (fl), 0, 0)
	#define CAL_OPCUAClientDiscovery_GetEndpoints  pfOPCUAClientDiscovery_GetEndpoints
	#define CHK_OPCUAClientDiscovery_GetEndpoints  (pfOPCUAClientDiscovery_GetEndpoints != NULL)
	#define EXP_OPCUAClientDiscovery_GetEndpoints  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClientDiscovery_GetEndpoints", (RTS_UINTPTR)OPCUAClientDiscovery_GetEndpoints, 0, 0) 
#endif



RTS_RESULT CDECL OPCUAClientDiscovery_FindServers(RTS_HANDLE hClient, OpcUa_String* psEndpointURL, PF_OPCUACLIENT_FINDSERVERS_CALLBACK cbfFindServers, RTS_UINTPTR pcbFindServersData);
typedef RTS_RESULT (CDECL * PFOPCUACLIENTDISCOVERY_FINDSERVERS) (RTS_HANDLE hClient, OpcUa_String* psEndpointURL, PF_OPCUACLIENT_FINDSERVERS_CALLBACK cbfFindServers, RTS_UINTPTR pcbFindServersData);
#if defined(CMPOPCUACLIENT_NOTIMPLEMENTED) || defined(OPCUACLIENTDISCOVERY_FINDSERVERS_NOTIMPLEMENTED)
	#define USE_OPCUAClientDiscovery_FindServers
	#define EXT_OPCUAClientDiscovery_FindServers
	#define GET_OPCUAClientDiscovery_FindServers(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OPCUAClientDiscovery_FindServers(p0,p1,p2,p3)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_OPCUAClientDiscovery_FindServers  FALSE
	#define EXP_OPCUAClientDiscovery_FindServers  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OPCUAClientDiscovery_FindServers
	#define EXT_OPCUAClientDiscovery_FindServers
	#define GET_OPCUAClientDiscovery_FindServers(fl)  CAL_CMGETAPI( "OPCUAClientDiscovery_FindServers" ) 
	#define CAL_OPCUAClientDiscovery_FindServers  OPCUAClientDiscovery_FindServers
	#define CHK_OPCUAClientDiscovery_FindServers  TRUE
	#define EXP_OPCUAClientDiscovery_FindServers  CAL_CMEXPAPI( "OPCUAClientDiscovery_FindServers" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_EXTERNAL)
	#define USE_OPCUAClientDiscovery_FindServers
	#define EXT_OPCUAClientDiscovery_FindServers
	#define GET_OPCUAClientDiscovery_FindServers(fl)  CAL_CMGETAPI( "OPCUAClientDiscovery_FindServers" ) 
	#define CAL_OPCUAClientDiscovery_FindServers  OPCUAClientDiscovery_FindServers
	#define CHK_OPCUAClientDiscovery_FindServers  TRUE
	#define EXP_OPCUAClientDiscovery_FindServers  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClientDiscovery_FindServers", (RTS_UINTPTR)OPCUAClientDiscovery_FindServers, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClientOPCUAClientDiscovery_FindServers
	#define EXT_CmpOPCUAClientOPCUAClientDiscovery_FindServers
	#define GET_CmpOPCUAClientOPCUAClientDiscovery_FindServers  ERR_OK
	#define CAL_CmpOPCUAClientOPCUAClientDiscovery_FindServers pICmpOPCUAClient->IOPCUAClientDiscovery_FindServers
	#define CHK_CmpOPCUAClientOPCUAClientDiscovery_FindServers (pICmpOPCUAClient != NULL)
	#define EXP_CmpOPCUAClientOPCUAClientDiscovery_FindServers  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OPCUAClientDiscovery_FindServers
	#define EXT_OPCUAClientDiscovery_FindServers
	#define GET_OPCUAClientDiscovery_FindServers(fl)  CAL_CMGETAPI( "OPCUAClientDiscovery_FindServers" ) 
	#define CAL_OPCUAClientDiscovery_FindServers pICmpOPCUAClient->IOPCUAClientDiscovery_FindServers
	#define CHK_OPCUAClientDiscovery_FindServers (pICmpOPCUAClient != NULL)
	#define EXP_OPCUAClientDiscovery_FindServers  CAL_CMEXPAPI( "OPCUAClientDiscovery_FindServers" ) 
#else /* DYNAMIC_LINK */
	#define USE_OPCUAClientDiscovery_FindServers  PFOPCUACLIENTDISCOVERY_FINDSERVERS pfOPCUAClientDiscovery_FindServers;
	#define EXT_OPCUAClientDiscovery_FindServers  extern PFOPCUACLIENTDISCOVERY_FINDSERVERS pfOPCUAClientDiscovery_FindServers;
	#define GET_OPCUAClientDiscovery_FindServers(fl)  s_pfCMGetAPI2( "OPCUAClientDiscovery_FindServers", (RTS_VOID_FCTPTR *)&pfOPCUAClientDiscovery_FindServers, (fl), 0, 0)
	#define CAL_OPCUAClientDiscovery_FindServers  pfOPCUAClientDiscovery_FindServers
	#define CHK_OPCUAClientDiscovery_FindServers  (pfOPCUAClientDiscovery_FindServers != NULL)
	#define EXP_OPCUAClientDiscovery_FindServers  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClientDiscovery_FindServers", (RTS_UINTPTR)OPCUAClientDiscovery_FindServers, 0, 0) 
#endif



RTS_RESULT CDECL OPCUAClientDiscovery_FindServersOnNetwork(RTS_HANDLE hClient, OpcUa_String* psEndpointURL, OpcUa_UInt32 startingRecordId, OpcUa_UInt32 maxRecordsToReturn, OpcUa_Int32 numServerCapabilityFilters, OpcUa_String *psServerCapabilityFilters, PF_OPCUACLIENT_FINDSERVERSONNETWORK_CALLBACK cbfFindServersOnNetwork, RTS_UINTPTR pcbFindServersOnNetworkData);
typedef RTS_RESULT (CDECL * PFOPCUACLIENTDISCOVERY_FINDSERVERSONNETWORK) (RTS_HANDLE hClient, OpcUa_String* psEndpointURL, OpcUa_UInt32 startingRecordId, OpcUa_UInt32 maxRecordsToReturn, OpcUa_Int32 numServerCapabilityFilters, OpcUa_String *psServerCapabilityFilters, PF_OPCUACLIENT_FINDSERVERSONNETWORK_CALLBACK cbfFindServersOnNetwork, RTS_UINTPTR pcbFindServersOnNetworkData);
#if defined(CMPOPCUACLIENT_NOTIMPLEMENTED) || defined(OPCUACLIENTDISCOVERY_FINDSERVERSONNETWORK_NOTIMPLEMENTED)
	#define USE_OPCUAClientDiscovery_FindServersOnNetwork
	#define EXT_OPCUAClientDiscovery_FindServersOnNetwork
	#define GET_OPCUAClientDiscovery_FindServersOnNetwork(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OPCUAClientDiscovery_FindServersOnNetwork(p0,p1,p2,p3,p4,p5,p6,p7)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_OPCUAClientDiscovery_FindServersOnNetwork  FALSE
	#define EXP_OPCUAClientDiscovery_FindServersOnNetwork  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OPCUAClientDiscovery_FindServersOnNetwork
	#define EXT_OPCUAClientDiscovery_FindServersOnNetwork
	#define GET_OPCUAClientDiscovery_FindServersOnNetwork(fl)  CAL_CMGETAPI( "OPCUAClientDiscovery_FindServersOnNetwork" ) 
	#define CAL_OPCUAClientDiscovery_FindServersOnNetwork  OPCUAClientDiscovery_FindServersOnNetwork
	#define CHK_OPCUAClientDiscovery_FindServersOnNetwork  TRUE
	#define EXP_OPCUAClientDiscovery_FindServersOnNetwork  CAL_CMEXPAPI( "OPCUAClientDiscovery_FindServersOnNetwork" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_EXTERNAL)
	#define USE_OPCUAClientDiscovery_FindServersOnNetwork
	#define EXT_OPCUAClientDiscovery_FindServersOnNetwork
	#define GET_OPCUAClientDiscovery_FindServersOnNetwork(fl)  CAL_CMGETAPI( "OPCUAClientDiscovery_FindServersOnNetwork" ) 
	#define CAL_OPCUAClientDiscovery_FindServersOnNetwork  OPCUAClientDiscovery_FindServersOnNetwork
	#define CHK_OPCUAClientDiscovery_FindServersOnNetwork  TRUE
	#define EXP_OPCUAClientDiscovery_FindServersOnNetwork  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClientDiscovery_FindServersOnNetwork", (RTS_UINTPTR)OPCUAClientDiscovery_FindServersOnNetwork, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClientOPCUAClientDiscovery_FindServersOnNetwork
	#define EXT_CmpOPCUAClientOPCUAClientDiscovery_FindServersOnNetwork
	#define GET_CmpOPCUAClientOPCUAClientDiscovery_FindServersOnNetwork  ERR_OK
	#define CAL_CmpOPCUAClientOPCUAClientDiscovery_FindServersOnNetwork pICmpOPCUAClient->IOPCUAClientDiscovery_FindServersOnNetwork
	#define CHK_CmpOPCUAClientOPCUAClientDiscovery_FindServersOnNetwork (pICmpOPCUAClient != NULL)
	#define EXP_CmpOPCUAClientOPCUAClientDiscovery_FindServersOnNetwork  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OPCUAClientDiscovery_FindServersOnNetwork
	#define EXT_OPCUAClientDiscovery_FindServersOnNetwork
	#define GET_OPCUAClientDiscovery_FindServersOnNetwork(fl)  CAL_CMGETAPI( "OPCUAClientDiscovery_FindServersOnNetwork" ) 
	#define CAL_OPCUAClientDiscovery_FindServersOnNetwork pICmpOPCUAClient->IOPCUAClientDiscovery_FindServersOnNetwork
	#define CHK_OPCUAClientDiscovery_FindServersOnNetwork (pICmpOPCUAClient != NULL)
	#define EXP_OPCUAClientDiscovery_FindServersOnNetwork  CAL_CMEXPAPI( "OPCUAClientDiscovery_FindServersOnNetwork" ) 
#else /* DYNAMIC_LINK */
	#define USE_OPCUAClientDiscovery_FindServersOnNetwork  PFOPCUACLIENTDISCOVERY_FINDSERVERSONNETWORK pfOPCUAClientDiscovery_FindServersOnNetwork;
	#define EXT_OPCUAClientDiscovery_FindServersOnNetwork  extern PFOPCUACLIENTDISCOVERY_FINDSERVERSONNETWORK pfOPCUAClientDiscovery_FindServersOnNetwork;
	#define GET_OPCUAClientDiscovery_FindServersOnNetwork(fl)  s_pfCMGetAPI2( "OPCUAClientDiscovery_FindServersOnNetwork", (RTS_VOID_FCTPTR *)&pfOPCUAClientDiscovery_FindServersOnNetwork, (fl), 0, 0)
	#define CAL_OPCUAClientDiscovery_FindServersOnNetwork  pfOPCUAClientDiscovery_FindServersOnNetwork
	#define CHK_OPCUAClientDiscovery_FindServersOnNetwork  (pfOPCUAClientDiscovery_FindServersOnNetwork != NULL)
	#define EXP_OPCUAClientDiscovery_FindServersOnNetwork  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClientDiscovery_FindServersOnNetwork", (RTS_UINTPTR)OPCUAClientDiscovery_FindServersOnNetwork, 0, 0) 
#endif




/*********************************************************************
 * Session services [Facet=CORE]
 *********************************************************************/

typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_CONNECTION_CALLBACK)(RTS_HANDLE hConnection, RTS_UINTPTR pcbConnectionData, OPCUACLIENTCONNECTIONSTATE connectionState, OpcUa_StatusCode reason);
typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_VERIFY_CERTIFICATE_CALLBACK)(RTS_HANDLE hConnection, RTS_UINTPTR pcbVerifyCertData, RTS_HANDLE hServerCertificate);
typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_GETCREDENTIALS_CALLBACK)(RTS_HANDLE hConnection, RTS_UINTPTR pcbGetCredentialsData, OPCUAClientUserToken* pUserToken);

RTS_HANDLE CDECL OPCUAClient_Connect(RTS_HANDLE hClient, OPCUAClientConnectionConfiguration* pConnectionConfiguration, PF_OPCUACLIENT_CONNECTION_CALLBACK cbfConnection, RTS_UINTPTR pcbConnectionData, PF_OPCUACLIENT_VERIFY_CERTIFICATE_CALLBACK cbfVerifyCertificate, RTS_UINTPTR pcbVerifyCertData,		PF_OPCUACLIENT_GETCREDENTIALS_CALLBACK cbfGetCredentials,  RTS_UINTPTR pcbGetCredentialsData);
typedef RTS_HANDLE (CDECL * PFOPCUACLIENT_CONNECT) (RTS_HANDLE hClient, OPCUAClientConnectionConfiguration* pConnectionConfiguration, PF_OPCUACLIENT_CONNECTION_CALLBACK cbfConnection, RTS_UINTPTR pcbConnectionData, PF_OPCUACLIENT_VERIFY_CERTIFICATE_CALLBACK cbfVerifyCertificate, RTS_UINTPTR pcbVerifyCertData,		PF_OPCUACLIENT_GETCREDENTIALS_CALLBACK cbfGetCredentials,  RTS_UINTPTR pcbGetCredentialsData);
#if defined(CMPOPCUACLIENT_NOTIMPLEMENTED) || defined(OPCUACLIENT_CONNECT_NOTIMPLEMENTED)
	#define USE_OPCUAClient_Connect
	#define EXT_OPCUAClient_Connect
	#define GET_OPCUAClient_Connect(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OPCUAClient_Connect(p0,p1,p2,p3,p4,p5,p6,p7)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_OPCUAClient_Connect  FALSE
	#define EXP_OPCUAClient_Connect  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OPCUAClient_Connect
	#define EXT_OPCUAClient_Connect
	#define GET_OPCUAClient_Connect(fl)  CAL_CMGETAPI( "OPCUAClient_Connect" ) 
	#define CAL_OPCUAClient_Connect  OPCUAClient_Connect
	#define CHK_OPCUAClient_Connect  TRUE
	#define EXP_OPCUAClient_Connect  CAL_CMEXPAPI( "OPCUAClient_Connect" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_EXTERNAL)
	#define USE_OPCUAClient_Connect
	#define EXT_OPCUAClient_Connect
	#define GET_OPCUAClient_Connect(fl)  CAL_CMGETAPI( "OPCUAClient_Connect" ) 
	#define CAL_OPCUAClient_Connect  OPCUAClient_Connect
	#define CHK_OPCUAClient_Connect  TRUE
	#define EXP_OPCUAClient_Connect  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_Connect", (RTS_UINTPTR)OPCUAClient_Connect, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClientOPCUAClient_Connect
	#define EXT_CmpOPCUAClientOPCUAClient_Connect
	#define GET_CmpOPCUAClientOPCUAClient_Connect  ERR_OK
	#define CAL_CmpOPCUAClientOPCUAClient_Connect pICmpOPCUAClient->IOPCUAClient_Connect
	#define CHK_CmpOPCUAClientOPCUAClient_Connect (pICmpOPCUAClient != NULL)
	#define EXP_CmpOPCUAClientOPCUAClient_Connect  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OPCUAClient_Connect
	#define EXT_OPCUAClient_Connect
	#define GET_OPCUAClient_Connect(fl)  CAL_CMGETAPI( "OPCUAClient_Connect" ) 
	#define CAL_OPCUAClient_Connect pICmpOPCUAClient->IOPCUAClient_Connect
	#define CHK_OPCUAClient_Connect (pICmpOPCUAClient != NULL)
	#define EXP_OPCUAClient_Connect  CAL_CMEXPAPI( "OPCUAClient_Connect" ) 
#else /* DYNAMIC_LINK */
	#define USE_OPCUAClient_Connect  PFOPCUACLIENT_CONNECT pfOPCUAClient_Connect;
	#define EXT_OPCUAClient_Connect  extern PFOPCUACLIENT_CONNECT pfOPCUAClient_Connect;
	#define GET_OPCUAClient_Connect(fl)  s_pfCMGetAPI2( "OPCUAClient_Connect", (RTS_VOID_FCTPTR *)&pfOPCUAClient_Connect, (fl), 0, 0)
	#define CAL_OPCUAClient_Connect  pfOPCUAClient_Connect
	#define CHK_OPCUAClient_Connect  (pfOPCUAClient_Connect != NULL)
	#define EXP_OPCUAClient_Connect  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_Connect", (RTS_UINTPTR)OPCUAClient_Connect, 0, 0) 
#endif




RTS_RESULT CDECL OPCUAClient_Disconnect(RTS_HANDLE hConnection);
typedef RTS_RESULT (CDECL * PFOPCUACLIENT_DISCONNECT) (RTS_HANDLE hConnection);
#if defined(CMPOPCUACLIENT_NOTIMPLEMENTED) || defined(OPCUACLIENT_DISCONNECT_NOTIMPLEMENTED)
	#define USE_OPCUAClient_Disconnect
	#define EXT_OPCUAClient_Disconnect
	#define GET_OPCUAClient_Disconnect(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OPCUAClient_Disconnect(p0)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_OPCUAClient_Disconnect  FALSE
	#define EXP_OPCUAClient_Disconnect  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OPCUAClient_Disconnect
	#define EXT_OPCUAClient_Disconnect
	#define GET_OPCUAClient_Disconnect(fl)  CAL_CMGETAPI( "OPCUAClient_Disconnect" ) 
	#define CAL_OPCUAClient_Disconnect  OPCUAClient_Disconnect
	#define CHK_OPCUAClient_Disconnect  TRUE
	#define EXP_OPCUAClient_Disconnect  CAL_CMEXPAPI( "OPCUAClient_Disconnect" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_EXTERNAL)
	#define USE_OPCUAClient_Disconnect
	#define EXT_OPCUAClient_Disconnect
	#define GET_OPCUAClient_Disconnect(fl)  CAL_CMGETAPI( "OPCUAClient_Disconnect" ) 
	#define CAL_OPCUAClient_Disconnect  OPCUAClient_Disconnect
	#define CHK_OPCUAClient_Disconnect  TRUE
	#define EXP_OPCUAClient_Disconnect  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_Disconnect", (RTS_UINTPTR)OPCUAClient_Disconnect, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClientOPCUAClient_Disconnect
	#define EXT_CmpOPCUAClientOPCUAClient_Disconnect
	#define GET_CmpOPCUAClientOPCUAClient_Disconnect  ERR_OK
	#define CAL_CmpOPCUAClientOPCUAClient_Disconnect pICmpOPCUAClient->IOPCUAClient_Disconnect
	#define CHK_CmpOPCUAClientOPCUAClient_Disconnect (pICmpOPCUAClient != NULL)
	#define EXP_CmpOPCUAClientOPCUAClient_Disconnect  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OPCUAClient_Disconnect
	#define EXT_OPCUAClient_Disconnect
	#define GET_OPCUAClient_Disconnect(fl)  CAL_CMGETAPI( "OPCUAClient_Disconnect" ) 
	#define CAL_OPCUAClient_Disconnect pICmpOPCUAClient->IOPCUAClient_Disconnect
	#define CHK_OPCUAClient_Disconnect (pICmpOPCUAClient != NULL)
	#define EXP_OPCUAClient_Disconnect  CAL_CMEXPAPI( "OPCUAClient_Disconnect" ) 
#else /* DYNAMIC_LINK */
	#define USE_OPCUAClient_Disconnect  PFOPCUACLIENT_DISCONNECT pfOPCUAClient_Disconnect;
	#define EXT_OPCUAClient_Disconnect  extern PFOPCUACLIENT_DISCONNECT pfOPCUAClient_Disconnect;
	#define GET_OPCUAClient_Disconnect(fl)  s_pfCMGetAPI2( "OPCUAClient_Disconnect", (RTS_VOID_FCTPTR *)&pfOPCUAClient_Disconnect, (fl), 0, 0)
	#define CAL_OPCUAClient_Disconnect  pfOPCUAClient_Disconnect
	#define CHK_OPCUAClient_Disconnect  (pfOPCUAClient_Disconnect != NULL)
	#define EXP_OPCUAClient_Disconnect  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_Disconnect", (RTS_UINTPTR)OPCUAClient_Disconnect, 0, 0) 
#endif




/*********************************************************************
 * DataAccess services [Facet=CORE]
 *********************************************************************/
typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_READ_CALLBACK)(RTS_HANDLE hConnection, RTS_UINTPTR pcbReadData, OpcUa_StatusCode serviceResult, OpcUa_UInt32 numOfValues, OpcUa_ReadValueId *pRequests, OpcUa_DataValue *pValues);

RTS_RESULT CDECL OPCUAClient_Read(RTS_HANDLE hConnection, OpcUa_Double maxAge, OpcUa_TimestampsToReturn timestampsToReturn, OpcUa_ReadValueId *pNodesToRead, OpcUa_Int32 numOfNodes, PF_OPCUACLIENT_READ_CALLBACK cbfRead, RTS_UINTPTR pcbReadData);
typedef RTS_RESULT (CDECL * PFOPCUACLIENT_READ) (RTS_HANDLE hConnection, OpcUa_Double maxAge, OpcUa_TimestampsToReturn timestampsToReturn, OpcUa_ReadValueId *pNodesToRead, OpcUa_Int32 numOfNodes, PF_OPCUACLIENT_READ_CALLBACK cbfRead, RTS_UINTPTR pcbReadData);
#if defined(CMPOPCUACLIENT_NOTIMPLEMENTED) || defined(OPCUACLIENT_READ_NOTIMPLEMENTED)
	#define USE_OPCUAClient_Read
	#define EXT_OPCUAClient_Read
	#define GET_OPCUAClient_Read(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OPCUAClient_Read(p0,p1,p2,p3,p4,p5,p6)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_OPCUAClient_Read  FALSE
	#define EXP_OPCUAClient_Read  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OPCUAClient_Read
	#define EXT_OPCUAClient_Read
	#define GET_OPCUAClient_Read(fl)  CAL_CMGETAPI( "OPCUAClient_Read" ) 
	#define CAL_OPCUAClient_Read  OPCUAClient_Read
	#define CHK_OPCUAClient_Read  TRUE
	#define EXP_OPCUAClient_Read  CAL_CMEXPAPI( "OPCUAClient_Read" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_EXTERNAL)
	#define USE_OPCUAClient_Read
	#define EXT_OPCUAClient_Read
	#define GET_OPCUAClient_Read(fl)  CAL_CMGETAPI( "OPCUAClient_Read" ) 
	#define CAL_OPCUAClient_Read  OPCUAClient_Read
	#define CHK_OPCUAClient_Read  TRUE
	#define EXP_OPCUAClient_Read  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_Read", (RTS_UINTPTR)OPCUAClient_Read, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClientOPCUAClient_Read
	#define EXT_CmpOPCUAClientOPCUAClient_Read
	#define GET_CmpOPCUAClientOPCUAClient_Read  ERR_OK
	#define CAL_CmpOPCUAClientOPCUAClient_Read pICmpOPCUAClient->IOPCUAClient_Read
	#define CHK_CmpOPCUAClientOPCUAClient_Read (pICmpOPCUAClient != NULL)
	#define EXP_CmpOPCUAClientOPCUAClient_Read  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OPCUAClient_Read
	#define EXT_OPCUAClient_Read
	#define GET_OPCUAClient_Read(fl)  CAL_CMGETAPI( "OPCUAClient_Read" ) 
	#define CAL_OPCUAClient_Read pICmpOPCUAClient->IOPCUAClient_Read
	#define CHK_OPCUAClient_Read (pICmpOPCUAClient != NULL)
	#define EXP_OPCUAClient_Read  CAL_CMEXPAPI( "OPCUAClient_Read" ) 
#else /* DYNAMIC_LINK */
	#define USE_OPCUAClient_Read  PFOPCUACLIENT_READ pfOPCUAClient_Read;
	#define EXT_OPCUAClient_Read  extern PFOPCUACLIENT_READ pfOPCUAClient_Read;
	#define GET_OPCUAClient_Read(fl)  s_pfCMGetAPI2( "OPCUAClient_Read", (RTS_VOID_FCTPTR *)&pfOPCUAClient_Read, (fl), 0, 0)
	#define CAL_OPCUAClient_Read  pfOPCUAClient_Read
	#define CHK_OPCUAClient_Read  (pfOPCUAClient_Read != NULL)
	#define EXP_OPCUAClient_Read  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_Read", (RTS_UINTPTR)OPCUAClient_Read, 0, 0) 
#endif





typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_WRITE_CALLBACK)(RTS_HANDLE hConnection, RTS_UINTPTR pcbWriteData, OpcUa_StatusCode serviceResult, OpcUa_UInt32 numOfValues, OpcUa_WriteValue *pRequests, OpcUa_StatusCode* pResults);

RTS_RESULT CDECL OPCUAClient_Write(RTS_HANDLE hConnection, OpcUa_WriteValue *pNodesToWrite, OpcUa_Int32 numOfNodes, PF_OPCUACLIENT_WRITE_CALLBACK cbfWrite, RTS_UINTPTR pcbWriteData);
typedef RTS_RESULT (CDECL * PFOPCUACLIENT_WRITE) (RTS_HANDLE hConnection, OpcUa_WriteValue *pNodesToWrite, OpcUa_Int32 numOfNodes, PF_OPCUACLIENT_WRITE_CALLBACK cbfWrite, RTS_UINTPTR pcbWriteData);
#if defined(CMPOPCUACLIENT_NOTIMPLEMENTED) || defined(OPCUACLIENT_WRITE_NOTIMPLEMENTED)
	#define USE_OPCUAClient_Write
	#define EXT_OPCUAClient_Write
	#define GET_OPCUAClient_Write(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OPCUAClient_Write(p0,p1,p2,p3,p4)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_OPCUAClient_Write  FALSE
	#define EXP_OPCUAClient_Write  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OPCUAClient_Write
	#define EXT_OPCUAClient_Write
	#define GET_OPCUAClient_Write(fl)  CAL_CMGETAPI( "OPCUAClient_Write" ) 
	#define CAL_OPCUAClient_Write  OPCUAClient_Write
	#define CHK_OPCUAClient_Write  TRUE
	#define EXP_OPCUAClient_Write  CAL_CMEXPAPI( "OPCUAClient_Write" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_EXTERNAL)
	#define USE_OPCUAClient_Write
	#define EXT_OPCUAClient_Write
	#define GET_OPCUAClient_Write(fl)  CAL_CMGETAPI( "OPCUAClient_Write" ) 
	#define CAL_OPCUAClient_Write  OPCUAClient_Write
	#define CHK_OPCUAClient_Write  TRUE
	#define EXP_OPCUAClient_Write  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_Write", (RTS_UINTPTR)OPCUAClient_Write, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClientOPCUAClient_Write
	#define EXT_CmpOPCUAClientOPCUAClient_Write
	#define GET_CmpOPCUAClientOPCUAClient_Write  ERR_OK
	#define CAL_CmpOPCUAClientOPCUAClient_Write pICmpOPCUAClient->IOPCUAClient_Write
	#define CHK_CmpOPCUAClientOPCUAClient_Write (pICmpOPCUAClient != NULL)
	#define EXP_CmpOPCUAClientOPCUAClient_Write  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OPCUAClient_Write
	#define EXT_OPCUAClient_Write
	#define GET_OPCUAClient_Write(fl)  CAL_CMGETAPI( "OPCUAClient_Write" ) 
	#define CAL_OPCUAClient_Write pICmpOPCUAClient->IOPCUAClient_Write
	#define CHK_OPCUAClient_Write (pICmpOPCUAClient != NULL)
	#define EXP_OPCUAClient_Write  CAL_CMEXPAPI( "OPCUAClient_Write" ) 
#else /* DYNAMIC_LINK */
	#define USE_OPCUAClient_Write  PFOPCUACLIENT_WRITE pfOPCUAClient_Write;
	#define EXT_OPCUAClient_Write  extern PFOPCUACLIENT_WRITE pfOPCUAClient_Write;
	#define GET_OPCUAClient_Write(fl)  s_pfCMGetAPI2( "OPCUAClient_Write", (RTS_VOID_FCTPTR *)&pfOPCUAClient_Write, (fl), 0, 0)
	#define CAL_OPCUAClient_Write  pfOPCUAClient_Write
	#define CHK_OPCUAClient_Write  (pfOPCUAClient_Write != NULL)
	#define EXP_OPCUAClient_Write  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_Write", (RTS_UINTPTR)OPCUAClient_Write, 0, 0) 
#endif




/*********************************************************************
 * Subscription services [Facet=CORE]
 *********************************************************************/
 typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_SUBSCRIPTION_STATE_CALLBACK)(RTS_HANDLE hSubscription, RTS_UINTPTR pcbSubscriptionData, OPCUACLIENTSUBSCRIPTIONSTATE newState, OpcUa_StatusCode reason);
 typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_SUBSCRIPTION_PARAMETER_CALLBACK)(RTS_HANDLE hSubscription, RTS_UINTPTR pcbSubscriptionData, OpcUa_Double publishingInterval, OpcUa_UInt32 lifetimeCount, OpcUa_UInt32 maxKeepAliveCount, OpcUa_UInt32 maxNotificationsPerPublish, OpcUa_Byte priority, OpcUa_StatusCode reason);

RTS_HANDLE CDECL OPCUAClient_CreateSubscription(RTS_HANDLE hConnection, OpcUa_Double publishingInterval, OpcUa_UInt32 lifetimeCount, OpcUa_UInt32 maxKeepAliveCount, OpcUa_UInt32 maxNotificationsPerPublish, OpcUa_Boolean publishingEnabled, OpcUa_Byte priority, PF_OPCUACLIENT_SUBSCRIPTION_STATE_CALLBACK cbfSubscriptionState, RTS_UINTPTR pcbSubscriptionStateData, PF_OPCUACLIENT_SUBSCRIPTION_PARAMETER_CALLBACK cbfSubscriptionParameter, RTS_UINTPTR pcbSubscriptionParameterData, RTS_RESULT *pResult);
typedef RTS_HANDLE (CDECL * PFOPCUACLIENT_CREATESUBSCRIPTION) (RTS_HANDLE hConnection, OpcUa_Double publishingInterval, OpcUa_UInt32 lifetimeCount, OpcUa_UInt32 maxKeepAliveCount, OpcUa_UInt32 maxNotificationsPerPublish, OpcUa_Boolean publishingEnabled, OpcUa_Byte priority, PF_OPCUACLIENT_SUBSCRIPTION_STATE_CALLBACK cbfSubscriptionState, RTS_UINTPTR pcbSubscriptionStateData, PF_OPCUACLIENT_SUBSCRIPTION_PARAMETER_CALLBACK cbfSubscriptionParameter, RTS_UINTPTR pcbSubscriptionParameterData, RTS_RESULT *pResult);
#if defined(CMPOPCUACLIENT_NOTIMPLEMENTED) || defined(OPCUACLIENT_CREATESUBSCRIPTION_NOTIMPLEMENTED)
	#define USE_OPCUAClient_CreateSubscription
	#define EXT_OPCUAClient_CreateSubscription
	#define GET_OPCUAClient_CreateSubscription(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OPCUAClient_CreateSubscription(p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_OPCUAClient_CreateSubscription  FALSE
	#define EXP_OPCUAClient_CreateSubscription  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OPCUAClient_CreateSubscription
	#define EXT_OPCUAClient_CreateSubscription
	#define GET_OPCUAClient_CreateSubscription(fl)  CAL_CMGETAPI( "OPCUAClient_CreateSubscription" ) 
	#define CAL_OPCUAClient_CreateSubscription  OPCUAClient_CreateSubscription
	#define CHK_OPCUAClient_CreateSubscription  TRUE
	#define EXP_OPCUAClient_CreateSubscription  CAL_CMEXPAPI( "OPCUAClient_CreateSubscription" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_EXTERNAL)
	#define USE_OPCUAClient_CreateSubscription
	#define EXT_OPCUAClient_CreateSubscription
	#define GET_OPCUAClient_CreateSubscription(fl)  CAL_CMGETAPI( "OPCUAClient_CreateSubscription" ) 
	#define CAL_OPCUAClient_CreateSubscription  OPCUAClient_CreateSubscription
	#define CHK_OPCUAClient_CreateSubscription  TRUE
	#define EXP_OPCUAClient_CreateSubscription  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_CreateSubscription", (RTS_UINTPTR)OPCUAClient_CreateSubscription, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClientOPCUAClient_CreateSubscription
	#define EXT_CmpOPCUAClientOPCUAClient_CreateSubscription
	#define GET_CmpOPCUAClientOPCUAClient_CreateSubscription  ERR_OK
	#define CAL_CmpOPCUAClientOPCUAClient_CreateSubscription pICmpOPCUAClient->IOPCUAClient_CreateSubscription
	#define CHK_CmpOPCUAClientOPCUAClient_CreateSubscription (pICmpOPCUAClient != NULL)
	#define EXP_CmpOPCUAClientOPCUAClient_CreateSubscription  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OPCUAClient_CreateSubscription
	#define EXT_OPCUAClient_CreateSubscription
	#define GET_OPCUAClient_CreateSubscription(fl)  CAL_CMGETAPI( "OPCUAClient_CreateSubscription" ) 
	#define CAL_OPCUAClient_CreateSubscription pICmpOPCUAClient->IOPCUAClient_CreateSubscription
	#define CHK_OPCUAClient_CreateSubscription (pICmpOPCUAClient != NULL)
	#define EXP_OPCUAClient_CreateSubscription  CAL_CMEXPAPI( "OPCUAClient_CreateSubscription" ) 
#else /* DYNAMIC_LINK */
	#define USE_OPCUAClient_CreateSubscription  PFOPCUACLIENT_CREATESUBSCRIPTION pfOPCUAClient_CreateSubscription;
	#define EXT_OPCUAClient_CreateSubscription  extern PFOPCUACLIENT_CREATESUBSCRIPTION pfOPCUAClient_CreateSubscription;
	#define GET_OPCUAClient_CreateSubscription(fl)  s_pfCMGetAPI2( "OPCUAClient_CreateSubscription", (RTS_VOID_FCTPTR *)&pfOPCUAClient_CreateSubscription, (fl), 0, 0)
	#define CAL_OPCUAClient_CreateSubscription  pfOPCUAClient_CreateSubscription
	#define CHK_OPCUAClient_CreateSubscription  (pfOPCUAClient_CreateSubscription != NULL)
	#define EXP_OPCUAClient_CreateSubscription  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_CreateSubscription", (RTS_UINTPTR)OPCUAClient_CreateSubscription, 0, 0) 
#endif




RTS_RESULT CDECL OPCUAClient_DeleteSubscription(RTS_HANDLE hSubscription);
typedef RTS_RESULT (CDECL * PFOPCUACLIENT_DELETESUBSCRIPTION) (RTS_HANDLE hSubscription);
#if defined(CMPOPCUACLIENT_NOTIMPLEMENTED) || defined(OPCUACLIENT_DELETESUBSCRIPTION_NOTIMPLEMENTED)
	#define USE_OPCUAClient_DeleteSubscription
	#define EXT_OPCUAClient_DeleteSubscription
	#define GET_OPCUAClient_DeleteSubscription(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OPCUAClient_DeleteSubscription(p0)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_OPCUAClient_DeleteSubscription  FALSE
	#define EXP_OPCUAClient_DeleteSubscription  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OPCUAClient_DeleteSubscription
	#define EXT_OPCUAClient_DeleteSubscription
	#define GET_OPCUAClient_DeleteSubscription(fl)  CAL_CMGETAPI( "OPCUAClient_DeleteSubscription" ) 
	#define CAL_OPCUAClient_DeleteSubscription  OPCUAClient_DeleteSubscription
	#define CHK_OPCUAClient_DeleteSubscription  TRUE
	#define EXP_OPCUAClient_DeleteSubscription  CAL_CMEXPAPI( "OPCUAClient_DeleteSubscription" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_EXTERNAL)
	#define USE_OPCUAClient_DeleteSubscription
	#define EXT_OPCUAClient_DeleteSubscription
	#define GET_OPCUAClient_DeleteSubscription(fl)  CAL_CMGETAPI( "OPCUAClient_DeleteSubscription" ) 
	#define CAL_OPCUAClient_DeleteSubscription  OPCUAClient_DeleteSubscription
	#define CHK_OPCUAClient_DeleteSubscription  TRUE
	#define EXP_OPCUAClient_DeleteSubscription  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_DeleteSubscription", (RTS_UINTPTR)OPCUAClient_DeleteSubscription, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClientOPCUAClient_DeleteSubscription
	#define EXT_CmpOPCUAClientOPCUAClient_DeleteSubscription
	#define GET_CmpOPCUAClientOPCUAClient_DeleteSubscription  ERR_OK
	#define CAL_CmpOPCUAClientOPCUAClient_DeleteSubscription pICmpOPCUAClient->IOPCUAClient_DeleteSubscription
	#define CHK_CmpOPCUAClientOPCUAClient_DeleteSubscription (pICmpOPCUAClient != NULL)
	#define EXP_CmpOPCUAClientOPCUAClient_DeleteSubscription  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OPCUAClient_DeleteSubscription
	#define EXT_OPCUAClient_DeleteSubscription
	#define GET_OPCUAClient_DeleteSubscription(fl)  CAL_CMGETAPI( "OPCUAClient_DeleteSubscription" ) 
	#define CAL_OPCUAClient_DeleteSubscription pICmpOPCUAClient->IOPCUAClient_DeleteSubscription
	#define CHK_OPCUAClient_DeleteSubscription (pICmpOPCUAClient != NULL)
	#define EXP_OPCUAClient_DeleteSubscription  CAL_CMEXPAPI( "OPCUAClient_DeleteSubscription" ) 
#else /* DYNAMIC_LINK */
	#define USE_OPCUAClient_DeleteSubscription  PFOPCUACLIENT_DELETESUBSCRIPTION pfOPCUAClient_DeleteSubscription;
	#define EXT_OPCUAClient_DeleteSubscription  extern PFOPCUACLIENT_DELETESUBSCRIPTION pfOPCUAClient_DeleteSubscription;
	#define GET_OPCUAClient_DeleteSubscription(fl)  s_pfCMGetAPI2( "OPCUAClient_DeleteSubscription", (RTS_VOID_FCTPTR *)&pfOPCUAClient_DeleteSubscription, (fl), 0, 0)
	#define CAL_OPCUAClient_DeleteSubscription  pfOPCUAClient_DeleteSubscription
	#define CHK_OPCUAClient_DeleteSubscription  (pfOPCUAClient_DeleteSubscription != NULL)
	#define EXP_OPCUAClient_DeleteSubscription  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_DeleteSubscription", (RTS_UINTPTR)OPCUAClient_DeleteSubscription, 0, 0) 
#endif




RTS_RESULT CDECL OPCUAClient_ModifySubscription(RTS_HANDLE hSubscription, OpcUa_Double reqPublishingInterval, OpcUa_UInt32 reqLifeTimeCount, OpcUa_UInt32 reqMaxKeepAliveCount, OpcUa_UInt32 maxNotificationsPerPublish, OpcUa_Byte priority);
typedef RTS_RESULT (CDECL * PFOPCUACLIENT_MODIFYSUBSCRIPTION) (RTS_HANDLE hSubscription, OpcUa_Double reqPublishingInterval, OpcUa_UInt32 reqLifeTimeCount, OpcUa_UInt32 reqMaxKeepAliveCount, OpcUa_UInt32 maxNotificationsPerPublish, OpcUa_Byte priority);
#if defined(CMPOPCUACLIENT_NOTIMPLEMENTED) || defined(OPCUACLIENT_MODIFYSUBSCRIPTION_NOTIMPLEMENTED)
	#define USE_OPCUAClient_ModifySubscription
	#define EXT_OPCUAClient_ModifySubscription
	#define GET_OPCUAClient_ModifySubscription(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OPCUAClient_ModifySubscription(p0,p1,p2,p3,p4,p5)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_OPCUAClient_ModifySubscription  FALSE
	#define EXP_OPCUAClient_ModifySubscription  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OPCUAClient_ModifySubscription
	#define EXT_OPCUAClient_ModifySubscription
	#define GET_OPCUAClient_ModifySubscription(fl)  CAL_CMGETAPI( "OPCUAClient_ModifySubscription" ) 
	#define CAL_OPCUAClient_ModifySubscription  OPCUAClient_ModifySubscription
	#define CHK_OPCUAClient_ModifySubscription  TRUE
	#define EXP_OPCUAClient_ModifySubscription  CAL_CMEXPAPI( "OPCUAClient_ModifySubscription" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_EXTERNAL)
	#define USE_OPCUAClient_ModifySubscription
	#define EXT_OPCUAClient_ModifySubscription
	#define GET_OPCUAClient_ModifySubscription(fl)  CAL_CMGETAPI( "OPCUAClient_ModifySubscription" ) 
	#define CAL_OPCUAClient_ModifySubscription  OPCUAClient_ModifySubscription
	#define CHK_OPCUAClient_ModifySubscription  TRUE
	#define EXP_OPCUAClient_ModifySubscription  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_ModifySubscription", (RTS_UINTPTR)OPCUAClient_ModifySubscription, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClientOPCUAClient_ModifySubscription
	#define EXT_CmpOPCUAClientOPCUAClient_ModifySubscription
	#define GET_CmpOPCUAClientOPCUAClient_ModifySubscription  ERR_OK
	#define CAL_CmpOPCUAClientOPCUAClient_ModifySubscription pICmpOPCUAClient->IOPCUAClient_ModifySubscription
	#define CHK_CmpOPCUAClientOPCUAClient_ModifySubscription (pICmpOPCUAClient != NULL)
	#define EXP_CmpOPCUAClientOPCUAClient_ModifySubscription  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OPCUAClient_ModifySubscription
	#define EXT_OPCUAClient_ModifySubscription
	#define GET_OPCUAClient_ModifySubscription(fl)  CAL_CMGETAPI( "OPCUAClient_ModifySubscription" ) 
	#define CAL_OPCUAClient_ModifySubscription pICmpOPCUAClient->IOPCUAClient_ModifySubscription
	#define CHK_OPCUAClient_ModifySubscription (pICmpOPCUAClient != NULL)
	#define EXP_OPCUAClient_ModifySubscription  CAL_CMEXPAPI( "OPCUAClient_ModifySubscription" ) 
#else /* DYNAMIC_LINK */
	#define USE_OPCUAClient_ModifySubscription  PFOPCUACLIENT_MODIFYSUBSCRIPTION pfOPCUAClient_ModifySubscription;
	#define EXT_OPCUAClient_ModifySubscription  extern PFOPCUACLIENT_MODIFYSUBSCRIPTION pfOPCUAClient_ModifySubscription;
	#define GET_OPCUAClient_ModifySubscription(fl)  s_pfCMGetAPI2( "OPCUAClient_ModifySubscription", (RTS_VOID_FCTPTR *)&pfOPCUAClient_ModifySubscription, (fl), 0, 0)
	#define CAL_OPCUAClient_ModifySubscription  pfOPCUAClient_ModifySubscription
	#define CHK_OPCUAClient_ModifySubscription  (pfOPCUAClient_ModifySubscription != NULL)
	#define EXP_OPCUAClient_ModifySubscription  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_ModifySubscription", (RTS_UINTPTR)OPCUAClient_ModifySubscription, 0, 0) 
#endif




RTS_RESULT CDECL OPCUAClient_SetPublishingMode(RTS_HANDLE hSubscription, OpcUa_Boolean publishingEnabled);
typedef RTS_RESULT (CDECL * PFOPCUACLIENT_SETPUBLISHINGMODE) (RTS_HANDLE hSubscription, OpcUa_Boolean publishingEnabled);
#if defined(CMPOPCUACLIENT_NOTIMPLEMENTED) || defined(OPCUACLIENT_SETPUBLISHINGMODE_NOTIMPLEMENTED)
	#define USE_OPCUAClient_SetPublishingMode
	#define EXT_OPCUAClient_SetPublishingMode
	#define GET_OPCUAClient_SetPublishingMode(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OPCUAClient_SetPublishingMode(p0,p1)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_OPCUAClient_SetPublishingMode  FALSE
	#define EXP_OPCUAClient_SetPublishingMode  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OPCUAClient_SetPublishingMode
	#define EXT_OPCUAClient_SetPublishingMode
	#define GET_OPCUAClient_SetPublishingMode(fl)  CAL_CMGETAPI( "OPCUAClient_SetPublishingMode" ) 
	#define CAL_OPCUAClient_SetPublishingMode  OPCUAClient_SetPublishingMode
	#define CHK_OPCUAClient_SetPublishingMode  TRUE
	#define EXP_OPCUAClient_SetPublishingMode  CAL_CMEXPAPI( "OPCUAClient_SetPublishingMode" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_EXTERNAL)
	#define USE_OPCUAClient_SetPublishingMode
	#define EXT_OPCUAClient_SetPublishingMode
	#define GET_OPCUAClient_SetPublishingMode(fl)  CAL_CMGETAPI( "OPCUAClient_SetPublishingMode" ) 
	#define CAL_OPCUAClient_SetPublishingMode  OPCUAClient_SetPublishingMode
	#define CHK_OPCUAClient_SetPublishingMode  TRUE
	#define EXP_OPCUAClient_SetPublishingMode  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_SetPublishingMode", (RTS_UINTPTR)OPCUAClient_SetPublishingMode, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClientOPCUAClient_SetPublishingMode
	#define EXT_CmpOPCUAClientOPCUAClient_SetPublishingMode
	#define GET_CmpOPCUAClientOPCUAClient_SetPublishingMode  ERR_OK
	#define CAL_CmpOPCUAClientOPCUAClient_SetPublishingMode pICmpOPCUAClient->IOPCUAClient_SetPublishingMode
	#define CHK_CmpOPCUAClientOPCUAClient_SetPublishingMode (pICmpOPCUAClient != NULL)
	#define EXP_CmpOPCUAClientOPCUAClient_SetPublishingMode  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OPCUAClient_SetPublishingMode
	#define EXT_OPCUAClient_SetPublishingMode
	#define GET_OPCUAClient_SetPublishingMode(fl)  CAL_CMGETAPI( "OPCUAClient_SetPublishingMode" ) 
	#define CAL_OPCUAClient_SetPublishingMode pICmpOPCUAClient->IOPCUAClient_SetPublishingMode
	#define CHK_OPCUAClient_SetPublishingMode (pICmpOPCUAClient != NULL)
	#define EXP_OPCUAClient_SetPublishingMode  CAL_CMEXPAPI( "OPCUAClient_SetPublishingMode" ) 
#else /* DYNAMIC_LINK */
	#define USE_OPCUAClient_SetPublishingMode  PFOPCUACLIENT_SETPUBLISHINGMODE pfOPCUAClient_SetPublishingMode;
	#define EXT_OPCUAClient_SetPublishingMode  extern PFOPCUACLIENT_SETPUBLISHINGMODE pfOPCUAClient_SetPublishingMode;
	#define GET_OPCUAClient_SetPublishingMode(fl)  s_pfCMGetAPI2( "OPCUAClient_SetPublishingMode", (RTS_VOID_FCTPTR *)&pfOPCUAClient_SetPublishingMode, (fl), 0, 0)
	#define CAL_OPCUAClient_SetPublishingMode  pfOPCUAClient_SetPublishingMode
	#define CHK_OPCUAClient_SetPublishingMode  (pfOPCUAClient_SetPublishingMode != NULL)
	#define EXP_OPCUAClient_SetPublishingMode  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_SetPublishingMode", (RTS_UINTPTR)OPCUAClient_SetPublishingMode, 0, 0) 
#endif




/*********************************************************************
 * Monitored Items services [Facet=CORE]
 *********************************************************************/

typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_MONITOREDITEM_STATE_CALLBACK)(RTS_HANDLE hMonitoredItem, RTS_UINTPTR pcbMonitoredItemData, RTS_IEC_INT newState, OpcUa_StatusCode reason);
typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_MONITOREDITEM_PARAMETER_CALLBACK)(RTS_HANDLE hMonitoredItem, RTS_UINTPTR pcbMonitoredItemData, OpcUa_Double revisedSamplingInterval, OpcUa_UInt32 revisedQueueSize, OpcUa_ExtensionObject filterResult, OpcUa_StatusCode reason);
typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_MONITOREDITEM_VALUE_CALLBACK)(RTS_HANDLE hMonitoredItem, RTS_UINTPTR pcbMonitoredItemData, OpcUa_DataValue value, OpcUa_StatusCode reason);
typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_MONITOREDITEM_EVENT_CALLBACK)(RTS_HANDLE hMonitoredItem, RTS_UINTPTR pcbMonitoredItemData, OpcUa_Int32 noOfEventFields, OpcUa_Variant* eventFields, OpcUa_StatusCode reason);

RTS_RESULT CDECL OPCUAClient_CreateMonitoredItems(RTS_HANDLE hSubscription, OpcUa_TimestampsToReturn eTimestampsToReturn, OpcUa_Int32 nNoOfItemsToCreate, OPCUAClientMonitoredItemConfiguration* pMonitoredItemsToCreate, PF_OPCUACLIENT_MONITOREDITEM_STATE_CALLBACK cbfMonitoredItemState, PF_OPCUACLIENT_MONITOREDITEM_PARAMETER_CALLBACK cbfMonitoredItemParameter, PF_OPCUACLIENT_MONITOREDITEM_VALUE_CALLBACK cbfMonitoredItemValue, PF_OPCUACLIENT_MONITOREDITEM_EVENT_CALLBACK cbfMonitoredItemEvent);
typedef RTS_RESULT (CDECL * PFOPCUACLIENT_CREATEMONITOREDITEMS) (RTS_HANDLE hSubscription, OpcUa_TimestampsToReturn eTimestampsToReturn, OpcUa_Int32 nNoOfItemsToCreate, OPCUAClientMonitoredItemConfiguration* pMonitoredItemsToCreate, PF_OPCUACLIENT_MONITOREDITEM_STATE_CALLBACK cbfMonitoredItemState, PF_OPCUACLIENT_MONITOREDITEM_PARAMETER_CALLBACK cbfMonitoredItemParameter, PF_OPCUACLIENT_MONITOREDITEM_VALUE_CALLBACK cbfMonitoredItemValue, PF_OPCUACLIENT_MONITOREDITEM_EVENT_CALLBACK cbfMonitoredItemEvent);
#if defined(CMPOPCUACLIENT_NOTIMPLEMENTED) || defined(OPCUACLIENT_CREATEMONITOREDITEMS_NOTIMPLEMENTED)
	#define USE_OPCUAClient_CreateMonitoredItems
	#define EXT_OPCUAClient_CreateMonitoredItems
	#define GET_OPCUAClient_CreateMonitoredItems(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OPCUAClient_CreateMonitoredItems(p0,p1,p2,p3,p4,p5,p6,p7)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_OPCUAClient_CreateMonitoredItems  FALSE
	#define EXP_OPCUAClient_CreateMonitoredItems  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OPCUAClient_CreateMonitoredItems
	#define EXT_OPCUAClient_CreateMonitoredItems
	#define GET_OPCUAClient_CreateMonitoredItems(fl)  CAL_CMGETAPI( "OPCUAClient_CreateMonitoredItems" ) 
	#define CAL_OPCUAClient_CreateMonitoredItems  OPCUAClient_CreateMonitoredItems
	#define CHK_OPCUAClient_CreateMonitoredItems  TRUE
	#define EXP_OPCUAClient_CreateMonitoredItems  CAL_CMEXPAPI( "OPCUAClient_CreateMonitoredItems" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_EXTERNAL)
	#define USE_OPCUAClient_CreateMonitoredItems
	#define EXT_OPCUAClient_CreateMonitoredItems
	#define GET_OPCUAClient_CreateMonitoredItems(fl)  CAL_CMGETAPI( "OPCUAClient_CreateMonitoredItems" ) 
	#define CAL_OPCUAClient_CreateMonitoredItems  OPCUAClient_CreateMonitoredItems
	#define CHK_OPCUAClient_CreateMonitoredItems  TRUE
	#define EXP_OPCUAClient_CreateMonitoredItems  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_CreateMonitoredItems", (RTS_UINTPTR)OPCUAClient_CreateMonitoredItems, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClientOPCUAClient_CreateMonitoredItems
	#define EXT_CmpOPCUAClientOPCUAClient_CreateMonitoredItems
	#define GET_CmpOPCUAClientOPCUAClient_CreateMonitoredItems  ERR_OK
	#define CAL_CmpOPCUAClientOPCUAClient_CreateMonitoredItems pICmpOPCUAClient->IOPCUAClient_CreateMonitoredItems
	#define CHK_CmpOPCUAClientOPCUAClient_CreateMonitoredItems (pICmpOPCUAClient != NULL)
	#define EXP_CmpOPCUAClientOPCUAClient_CreateMonitoredItems  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OPCUAClient_CreateMonitoredItems
	#define EXT_OPCUAClient_CreateMonitoredItems
	#define GET_OPCUAClient_CreateMonitoredItems(fl)  CAL_CMGETAPI( "OPCUAClient_CreateMonitoredItems" ) 
	#define CAL_OPCUAClient_CreateMonitoredItems pICmpOPCUAClient->IOPCUAClient_CreateMonitoredItems
	#define CHK_OPCUAClient_CreateMonitoredItems (pICmpOPCUAClient != NULL)
	#define EXP_OPCUAClient_CreateMonitoredItems  CAL_CMEXPAPI( "OPCUAClient_CreateMonitoredItems" ) 
#else /* DYNAMIC_LINK */
	#define USE_OPCUAClient_CreateMonitoredItems  PFOPCUACLIENT_CREATEMONITOREDITEMS pfOPCUAClient_CreateMonitoredItems;
	#define EXT_OPCUAClient_CreateMonitoredItems  extern PFOPCUACLIENT_CREATEMONITOREDITEMS pfOPCUAClient_CreateMonitoredItems;
	#define GET_OPCUAClient_CreateMonitoredItems(fl)  s_pfCMGetAPI2( "OPCUAClient_CreateMonitoredItems", (RTS_VOID_FCTPTR *)&pfOPCUAClient_CreateMonitoredItems, (fl), 0, 0)
	#define CAL_OPCUAClient_CreateMonitoredItems  pfOPCUAClient_CreateMonitoredItems
	#define CHK_OPCUAClient_CreateMonitoredItems  (pfOPCUAClient_CreateMonitoredItems != NULL)
	#define EXP_OPCUAClient_CreateMonitoredItems  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_CreateMonitoredItems", (RTS_UINTPTR)OPCUAClient_CreateMonitoredItems, 0, 0) 
#endif




RTS_RESULT CDECL OPCUAClient_ModifyMonitoredItems(RTS_HANDLE hSubscription, OpcUa_TimestampsToReturn eTimestampsToReturn, OpcUa_Int32 nNoOfItemsToModify, OPCUAClientMonitoredItemConfiguration* pMonitoredItemsToModify);
typedef RTS_RESULT (CDECL * PFOPCUACLIENT_MODIFYMONITOREDITEMS) (RTS_HANDLE hSubscription, OpcUa_TimestampsToReturn eTimestampsToReturn, OpcUa_Int32 nNoOfItemsToModify, OPCUAClientMonitoredItemConfiguration* pMonitoredItemsToModify);
#if defined(CMPOPCUACLIENT_NOTIMPLEMENTED) || defined(OPCUACLIENT_MODIFYMONITOREDITEMS_NOTIMPLEMENTED)
	#define USE_OPCUAClient_ModifyMonitoredItems
	#define EXT_OPCUAClient_ModifyMonitoredItems
	#define GET_OPCUAClient_ModifyMonitoredItems(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OPCUAClient_ModifyMonitoredItems(p0,p1,p2,p3)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_OPCUAClient_ModifyMonitoredItems  FALSE
	#define EXP_OPCUAClient_ModifyMonitoredItems  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OPCUAClient_ModifyMonitoredItems
	#define EXT_OPCUAClient_ModifyMonitoredItems
	#define GET_OPCUAClient_ModifyMonitoredItems(fl)  CAL_CMGETAPI( "OPCUAClient_ModifyMonitoredItems" ) 
	#define CAL_OPCUAClient_ModifyMonitoredItems  OPCUAClient_ModifyMonitoredItems
	#define CHK_OPCUAClient_ModifyMonitoredItems  TRUE
	#define EXP_OPCUAClient_ModifyMonitoredItems  CAL_CMEXPAPI( "OPCUAClient_ModifyMonitoredItems" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_EXTERNAL)
	#define USE_OPCUAClient_ModifyMonitoredItems
	#define EXT_OPCUAClient_ModifyMonitoredItems
	#define GET_OPCUAClient_ModifyMonitoredItems(fl)  CAL_CMGETAPI( "OPCUAClient_ModifyMonitoredItems" ) 
	#define CAL_OPCUAClient_ModifyMonitoredItems  OPCUAClient_ModifyMonitoredItems
	#define CHK_OPCUAClient_ModifyMonitoredItems  TRUE
	#define EXP_OPCUAClient_ModifyMonitoredItems  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_ModifyMonitoredItems", (RTS_UINTPTR)OPCUAClient_ModifyMonitoredItems, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClientOPCUAClient_ModifyMonitoredItems
	#define EXT_CmpOPCUAClientOPCUAClient_ModifyMonitoredItems
	#define GET_CmpOPCUAClientOPCUAClient_ModifyMonitoredItems  ERR_OK
	#define CAL_CmpOPCUAClientOPCUAClient_ModifyMonitoredItems pICmpOPCUAClient->IOPCUAClient_ModifyMonitoredItems
	#define CHK_CmpOPCUAClientOPCUAClient_ModifyMonitoredItems (pICmpOPCUAClient != NULL)
	#define EXP_CmpOPCUAClientOPCUAClient_ModifyMonitoredItems  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OPCUAClient_ModifyMonitoredItems
	#define EXT_OPCUAClient_ModifyMonitoredItems
	#define GET_OPCUAClient_ModifyMonitoredItems(fl)  CAL_CMGETAPI( "OPCUAClient_ModifyMonitoredItems" ) 
	#define CAL_OPCUAClient_ModifyMonitoredItems pICmpOPCUAClient->IOPCUAClient_ModifyMonitoredItems
	#define CHK_OPCUAClient_ModifyMonitoredItems (pICmpOPCUAClient != NULL)
	#define EXP_OPCUAClient_ModifyMonitoredItems  CAL_CMEXPAPI( "OPCUAClient_ModifyMonitoredItems" ) 
#else /* DYNAMIC_LINK */
	#define USE_OPCUAClient_ModifyMonitoredItems  PFOPCUACLIENT_MODIFYMONITOREDITEMS pfOPCUAClient_ModifyMonitoredItems;
	#define EXT_OPCUAClient_ModifyMonitoredItems  extern PFOPCUACLIENT_MODIFYMONITOREDITEMS pfOPCUAClient_ModifyMonitoredItems;
	#define GET_OPCUAClient_ModifyMonitoredItems(fl)  s_pfCMGetAPI2( "OPCUAClient_ModifyMonitoredItems", (RTS_VOID_FCTPTR *)&pfOPCUAClient_ModifyMonitoredItems, (fl), 0, 0)
	#define CAL_OPCUAClient_ModifyMonitoredItems  pfOPCUAClient_ModifyMonitoredItems
	#define CHK_OPCUAClient_ModifyMonitoredItems  (pfOPCUAClient_ModifyMonitoredItems != NULL)
	#define EXP_OPCUAClient_ModifyMonitoredItems  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_ModifyMonitoredItems", (RTS_UINTPTR)OPCUAClient_ModifyMonitoredItems, 0, 0) 
#endif




RTS_RESULT CDECL OPCUAClient_SetMonitoringMode(RTS_HANDLE hSubscription, OpcUa_MonitoringMode monitoringMode, OpcUa_Int32 nNoOfMonitoredItems, RTS_HANDLE *phItems);
typedef RTS_RESULT (CDECL * PFOPCUACLIENT_SETMONITORINGMODE) (RTS_HANDLE hSubscription, OpcUa_MonitoringMode monitoringMode, OpcUa_Int32 nNoOfMonitoredItems, RTS_HANDLE *phItems);
#if defined(CMPOPCUACLIENT_NOTIMPLEMENTED) || defined(OPCUACLIENT_SETMONITORINGMODE_NOTIMPLEMENTED)
	#define USE_OPCUAClient_SetMonitoringMode
	#define EXT_OPCUAClient_SetMonitoringMode
	#define GET_OPCUAClient_SetMonitoringMode(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OPCUAClient_SetMonitoringMode(p0,p1,p2,p3)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_OPCUAClient_SetMonitoringMode  FALSE
	#define EXP_OPCUAClient_SetMonitoringMode  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OPCUAClient_SetMonitoringMode
	#define EXT_OPCUAClient_SetMonitoringMode
	#define GET_OPCUAClient_SetMonitoringMode(fl)  CAL_CMGETAPI( "OPCUAClient_SetMonitoringMode" ) 
	#define CAL_OPCUAClient_SetMonitoringMode  OPCUAClient_SetMonitoringMode
	#define CHK_OPCUAClient_SetMonitoringMode  TRUE
	#define EXP_OPCUAClient_SetMonitoringMode  CAL_CMEXPAPI( "OPCUAClient_SetMonitoringMode" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_EXTERNAL)
	#define USE_OPCUAClient_SetMonitoringMode
	#define EXT_OPCUAClient_SetMonitoringMode
	#define GET_OPCUAClient_SetMonitoringMode(fl)  CAL_CMGETAPI( "OPCUAClient_SetMonitoringMode" ) 
	#define CAL_OPCUAClient_SetMonitoringMode  OPCUAClient_SetMonitoringMode
	#define CHK_OPCUAClient_SetMonitoringMode  TRUE
	#define EXP_OPCUAClient_SetMonitoringMode  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_SetMonitoringMode", (RTS_UINTPTR)OPCUAClient_SetMonitoringMode, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClientOPCUAClient_SetMonitoringMode
	#define EXT_CmpOPCUAClientOPCUAClient_SetMonitoringMode
	#define GET_CmpOPCUAClientOPCUAClient_SetMonitoringMode  ERR_OK
	#define CAL_CmpOPCUAClientOPCUAClient_SetMonitoringMode pICmpOPCUAClient->IOPCUAClient_SetMonitoringMode
	#define CHK_CmpOPCUAClientOPCUAClient_SetMonitoringMode (pICmpOPCUAClient != NULL)
	#define EXP_CmpOPCUAClientOPCUAClient_SetMonitoringMode  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OPCUAClient_SetMonitoringMode
	#define EXT_OPCUAClient_SetMonitoringMode
	#define GET_OPCUAClient_SetMonitoringMode(fl)  CAL_CMGETAPI( "OPCUAClient_SetMonitoringMode" ) 
	#define CAL_OPCUAClient_SetMonitoringMode pICmpOPCUAClient->IOPCUAClient_SetMonitoringMode
	#define CHK_OPCUAClient_SetMonitoringMode (pICmpOPCUAClient != NULL)
	#define EXP_OPCUAClient_SetMonitoringMode  CAL_CMEXPAPI( "OPCUAClient_SetMonitoringMode" ) 
#else /* DYNAMIC_LINK */
	#define USE_OPCUAClient_SetMonitoringMode  PFOPCUACLIENT_SETMONITORINGMODE pfOPCUAClient_SetMonitoringMode;
	#define EXT_OPCUAClient_SetMonitoringMode  extern PFOPCUACLIENT_SETMONITORINGMODE pfOPCUAClient_SetMonitoringMode;
	#define GET_OPCUAClient_SetMonitoringMode(fl)  s_pfCMGetAPI2( "OPCUAClient_SetMonitoringMode", (RTS_VOID_FCTPTR *)&pfOPCUAClient_SetMonitoringMode, (fl), 0, 0)
	#define CAL_OPCUAClient_SetMonitoringMode  pfOPCUAClient_SetMonitoringMode
	#define CHK_OPCUAClient_SetMonitoringMode  (pfOPCUAClient_SetMonitoringMode != NULL)
	#define EXP_OPCUAClient_SetMonitoringMode  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_SetMonitoringMode", (RTS_UINTPTR)OPCUAClient_SetMonitoringMode, 0, 0) 
#endif




RTS_RESULT CDECL OPCUAClient_DeleteMonitoredItems(RTS_HANDLE hSubscription, OpcUa_Int32 nNoOfItemsToDelete, RTS_HANDLE *phItems);
typedef RTS_RESULT (CDECL * PFOPCUACLIENT_DELETEMONITOREDITEMS) (RTS_HANDLE hSubscription, OpcUa_Int32 nNoOfItemsToDelete, RTS_HANDLE *phItems);
#if defined(CMPOPCUACLIENT_NOTIMPLEMENTED) || defined(OPCUACLIENT_DELETEMONITOREDITEMS_NOTIMPLEMENTED)
	#define USE_OPCUAClient_DeleteMonitoredItems
	#define EXT_OPCUAClient_DeleteMonitoredItems
	#define GET_OPCUAClient_DeleteMonitoredItems(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OPCUAClient_DeleteMonitoredItems(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_OPCUAClient_DeleteMonitoredItems  FALSE
	#define EXP_OPCUAClient_DeleteMonitoredItems  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OPCUAClient_DeleteMonitoredItems
	#define EXT_OPCUAClient_DeleteMonitoredItems
	#define GET_OPCUAClient_DeleteMonitoredItems(fl)  CAL_CMGETAPI( "OPCUAClient_DeleteMonitoredItems" ) 
	#define CAL_OPCUAClient_DeleteMonitoredItems  OPCUAClient_DeleteMonitoredItems
	#define CHK_OPCUAClient_DeleteMonitoredItems  TRUE
	#define EXP_OPCUAClient_DeleteMonitoredItems  CAL_CMEXPAPI( "OPCUAClient_DeleteMonitoredItems" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_EXTERNAL)
	#define USE_OPCUAClient_DeleteMonitoredItems
	#define EXT_OPCUAClient_DeleteMonitoredItems
	#define GET_OPCUAClient_DeleteMonitoredItems(fl)  CAL_CMGETAPI( "OPCUAClient_DeleteMonitoredItems" ) 
	#define CAL_OPCUAClient_DeleteMonitoredItems  OPCUAClient_DeleteMonitoredItems
	#define CHK_OPCUAClient_DeleteMonitoredItems  TRUE
	#define EXP_OPCUAClient_DeleteMonitoredItems  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_DeleteMonitoredItems", (RTS_UINTPTR)OPCUAClient_DeleteMonitoredItems, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClientOPCUAClient_DeleteMonitoredItems
	#define EXT_CmpOPCUAClientOPCUAClient_DeleteMonitoredItems
	#define GET_CmpOPCUAClientOPCUAClient_DeleteMonitoredItems  ERR_OK
	#define CAL_CmpOPCUAClientOPCUAClient_DeleteMonitoredItems pICmpOPCUAClient->IOPCUAClient_DeleteMonitoredItems
	#define CHK_CmpOPCUAClientOPCUAClient_DeleteMonitoredItems (pICmpOPCUAClient != NULL)
	#define EXP_CmpOPCUAClientOPCUAClient_DeleteMonitoredItems  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OPCUAClient_DeleteMonitoredItems
	#define EXT_OPCUAClient_DeleteMonitoredItems
	#define GET_OPCUAClient_DeleteMonitoredItems(fl)  CAL_CMGETAPI( "OPCUAClient_DeleteMonitoredItems" ) 
	#define CAL_OPCUAClient_DeleteMonitoredItems pICmpOPCUAClient->IOPCUAClient_DeleteMonitoredItems
	#define CHK_OPCUAClient_DeleteMonitoredItems (pICmpOPCUAClient != NULL)
	#define EXP_OPCUAClient_DeleteMonitoredItems  CAL_CMEXPAPI( "OPCUAClient_DeleteMonitoredItems" ) 
#else /* DYNAMIC_LINK */
	#define USE_OPCUAClient_DeleteMonitoredItems  PFOPCUACLIENT_DELETEMONITOREDITEMS pfOPCUAClient_DeleteMonitoredItems;
	#define EXT_OPCUAClient_DeleteMonitoredItems  extern PFOPCUACLIENT_DELETEMONITOREDITEMS pfOPCUAClient_DeleteMonitoredItems;
	#define GET_OPCUAClient_DeleteMonitoredItems(fl)  s_pfCMGetAPI2( "OPCUAClient_DeleteMonitoredItems", (RTS_VOID_FCTPTR *)&pfOPCUAClient_DeleteMonitoredItems, (fl), 0, 0)
	#define CAL_OPCUAClient_DeleteMonitoredItems  pfOPCUAClient_DeleteMonitoredItems
	#define CHK_OPCUAClient_DeleteMonitoredItems  (pfOPCUAClient_DeleteMonitoredItems != NULL)
	#define EXP_OPCUAClient_DeleteMonitoredItems  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_DeleteMonitoredItems", (RTS_UINTPTR)OPCUAClient_DeleteMonitoredItems, 0, 0) 
#endif




RTS_RESULT CDECL OPCUAClient_ExtensionObjectAttachReadOnly(OpcUa_UInt32 TypeId, OpcUa_ExtensionObject* pExtensionObject, OpcUa_Void* pObject);
typedef RTS_RESULT (CDECL * PFOPCUACLIENT_EXTENSIONOBJECTATTACHREADONLY) (OpcUa_UInt32 TypeId, OpcUa_ExtensionObject* pExtensionObject, OpcUa_Void* pObject);
#if defined(CMPOPCUACLIENT_NOTIMPLEMENTED) || defined(OPCUACLIENT_EXTENSIONOBJECTATTACHREADONLY_NOTIMPLEMENTED)
	#define USE_OPCUAClient_ExtensionObjectAttachReadOnly
	#define EXT_OPCUAClient_ExtensionObjectAttachReadOnly
	#define GET_OPCUAClient_ExtensionObjectAttachReadOnly(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OPCUAClient_ExtensionObjectAttachReadOnly(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_OPCUAClient_ExtensionObjectAttachReadOnly  FALSE
	#define EXP_OPCUAClient_ExtensionObjectAttachReadOnly  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OPCUAClient_ExtensionObjectAttachReadOnly
	#define EXT_OPCUAClient_ExtensionObjectAttachReadOnly
	#define GET_OPCUAClient_ExtensionObjectAttachReadOnly(fl)  CAL_CMGETAPI( "OPCUAClient_ExtensionObjectAttachReadOnly" ) 
	#define CAL_OPCUAClient_ExtensionObjectAttachReadOnly  OPCUAClient_ExtensionObjectAttachReadOnly
	#define CHK_OPCUAClient_ExtensionObjectAttachReadOnly  TRUE
	#define EXP_OPCUAClient_ExtensionObjectAttachReadOnly  CAL_CMEXPAPI( "OPCUAClient_ExtensionObjectAttachReadOnly" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_EXTERNAL)
	#define USE_OPCUAClient_ExtensionObjectAttachReadOnly
	#define EXT_OPCUAClient_ExtensionObjectAttachReadOnly
	#define GET_OPCUAClient_ExtensionObjectAttachReadOnly(fl)  CAL_CMGETAPI( "OPCUAClient_ExtensionObjectAttachReadOnly" ) 
	#define CAL_OPCUAClient_ExtensionObjectAttachReadOnly  OPCUAClient_ExtensionObjectAttachReadOnly
	#define CHK_OPCUAClient_ExtensionObjectAttachReadOnly  TRUE
	#define EXP_OPCUAClient_ExtensionObjectAttachReadOnly  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_ExtensionObjectAttachReadOnly", (RTS_UINTPTR)OPCUAClient_ExtensionObjectAttachReadOnly, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClientOPCUAClient_ExtensionObjectAttachReadOnly
	#define EXT_CmpOPCUAClientOPCUAClient_ExtensionObjectAttachReadOnly
	#define GET_CmpOPCUAClientOPCUAClient_ExtensionObjectAttachReadOnly  ERR_OK
	#define CAL_CmpOPCUAClientOPCUAClient_ExtensionObjectAttachReadOnly pICmpOPCUAClient->IOPCUAClient_ExtensionObjectAttachReadOnly
	#define CHK_CmpOPCUAClientOPCUAClient_ExtensionObjectAttachReadOnly (pICmpOPCUAClient != NULL)
	#define EXP_CmpOPCUAClientOPCUAClient_ExtensionObjectAttachReadOnly  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OPCUAClient_ExtensionObjectAttachReadOnly
	#define EXT_OPCUAClient_ExtensionObjectAttachReadOnly
	#define GET_OPCUAClient_ExtensionObjectAttachReadOnly(fl)  CAL_CMGETAPI( "OPCUAClient_ExtensionObjectAttachReadOnly" ) 
	#define CAL_OPCUAClient_ExtensionObjectAttachReadOnly pICmpOPCUAClient->IOPCUAClient_ExtensionObjectAttachReadOnly
	#define CHK_OPCUAClient_ExtensionObjectAttachReadOnly (pICmpOPCUAClient != NULL)
	#define EXP_OPCUAClient_ExtensionObjectAttachReadOnly  CAL_CMEXPAPI( "OPCUAClient_ExtensionObjectAttachReadOnly" ) 
#else /* DYNAMIC_LINK */
	#define USE_OPCUAClient_ExtensionObjectAttachReadOnly  PFOPCUACLIENT_EXTENSIONOBJECTATTACHREADONLY pfOPCUAClient_ExtensionObjectAttachReadOnly;
	#define EXT_OPCUAClient_ExtensionObjectAttachReadOnly  extern PFOPCUACLIENT_EXTENSIONOBJECTATTACHREADONLY pfOPCUAClient_ExtensionObjectAttachReadOnly;
	#define GET_OPCUAClient_ExtensionObjectAttachReadOnly(fl)  s_pfCMGetAPI2( "OPCUAClient_ExtensionObjectAttachReadOnly", (RTS_VOID_FCTPTR *)&pfOPCUAClient_ExtensionObjectAttachReadOnly, (fl), 0, 0)
	#define CAL_OPCUAClient_ExtensionObjectAttachReadOnly  pfOPCUAClient_ExtensionObjectAttachReadOnly
	#define CHK_OPCUAClient_ExtensionObjectAttachReadOnly  (pfOPCUAClient_ExtensionObjectAttachReadOnly != NULL)
	#define EXP_OPCUAClient_ExtensionObjectAttachReadOnly  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_ExtensionObjectAttachReadOnly", (RTS_UINTPTR)OPCUAClient_ExtensionObjectAttachReadOnly, 0, 0) 
#endif




/*********************************************************************
 * View services [Facet=CORE]
 *********************************************************************/
typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_BROWSE_CALLBACK)(RTS_HANDLE hConnection, RTS_UINTPTR pcbCallbackData, OpcUa_StatusCode serviceResult, OpcUa_UInt32 numOfResults, OpcUa_BrowseResult *results);
typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_BROWSENEXT_CALLBACK)(RTS_HANDLE hConnection, RTS_UINTPTR pcbCallbackData, OpcUa_StatusCode serviceResult, OpcUa_UInt32 numOfResults, OpcUa_BrowseResult *results);
typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_TRANSLATEBROWSEPATHSTONODEIDS_CALLBACK)(RTS_HANDLE hConnection, RTS_UINTPTR pcbCallbackData, OpcUa_StatusCode serviceResult, OpcUa_UInt32 numOfResults, OpcUa_BrowsePathResult *results);
typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_REGISTERNODES_CALLBACK)(RTS_HANDLE hConnection, RTS_UINTPTR pcbCallbackData, OpcUa_StatusCode serviceResult, OpcUa_UInt32 numOfNodes, OpcUa_NodeId *registeredNodeIds);
typedef OpcUa_StatusCode(CDECL *PF_OPCUACLIENT_UNREGISTERNODES_CALLBACK)(RTS_HANDLE hConnection, RTS_UINTPTR pcbCallbackData, OpcUa_StatusCode serviceResult);
 
RTS_RESULT CDECL OPCUAClient_Browse(RTS_HANDLE hConnection, OpcUa_ViewDescription view, OpcUa_Int32 requestedMaxReferencesPerNode, OpcUa_Int32 noOfNodesToBrowse, OpcUa_BrowseDescription *pNodesToBrowse, void*cbfCallback, RTS_UINTPTR pcbCallbackData);
typedef RTS_RESULT (CDECL * PFOPCUACLIENT_BROWSE) (RTS_HANDLE hConnection, OpcUa_ViewDescription view, OpcUa_Int32 requestedMaxReferencesPerNode, OpcUa_Int32 noOfNodesToBrowse, OpcUa_BrowseDescription *pNodesToBrowse, void*cbfCallback, RTS_UINTPTR pcbCallbackData);
#if defined(CMPOPCUACLIENT_NOTIMPLEMENTED) || defined(OPCUACLIENT_BROWSE_NOTIMPLEMENTED)
	#define USE_OPCUAClient_Browse
	#define EXT_OPCUAClient_Browse
	#define GET_OPCUAClient_Browse(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OPCUAClient_Browse(p0,p1,p2,p3,p4,p5,p6)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_OPCUAClient_Browse  FALSE
	#define EXP_OPCUAClient_Browse  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OPCUAClient_Browse
	#define EXT_OPCUAClient_Browse
	#define GET_OPCUAClient_Browse(fl)  CAL_CMGETAPI( "OPCUAClient_Browse" ) 
	#define CAL_OPCUAClient_Browse  OPCUAClient_Browse
	#define CHK_OPCUAClient_Browse  TRUE
	#define EXP_OPCUAClient_Browse  CAL_CMEXPAPI( "OPCUAClient_Browse" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_EXTERNAL)
	#define USE_OPCUAClient_Browse
	#define EXT_OPCUAClient_Browse
	#define GET_OPCUAClient_Browse(fl)  CAL_CMGETAPI( "OPCUAClient_Browse" ) 
	#define CAL_OPCUAClient_Browse  OPCUAClient_Browse
	#define CHK_OPCUAClient_Browse  TRUE
	#define EXP_OPCUAClient_Browse  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_Browse", (RTS_UINTPTR)OPCUAClient_Browse, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClientOPCUAClient_Browse
	#define EXT_CmpOPCUAClientOPCUAClient_Browse
	#define GET_CmpOPCUAClientOPCUAClient_Browse  ERR_OK
	#define CAL_CmpOPCUAClientOPCUAClient_Browse pICmpOPCUAClient->IOPCUAClient_Browse
	#define CHK_CmpOPCUAClientOPCUAClient_Browse (pICmpOPCUAClient != NULL)
	#define EXP_CmpOPCUAClientOPCUAClient_Browse  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OPCUAClient_Browse
	#define EXT_OPCUAClient_Browse
	#define GET_OPCUAClient_Browse(fl)  CAL_CMGETAPI( "OPCUAClient_Browse" ) 
	#define CAL_OPCUAClient_Browse pICmpOPCUAClient->IOPCUAClient_Browse
	#define CHK_OPCUAClient_Browse (pICmpOPCUAClient != NULL)
	#define EXP_OPCUAClient_Browse  CAL_CMEXPAPI( "OPCUAClient_Browse" ) 
#else /* DYNAMIC_LINK */
	#define USE_OPCUAClient_Browse  PFOPCUACLIENT_BROWSE pfOPCUAClient_Browse;
	#define EXT_OPCUAClient_Browse  extern PFOPCUACLIENT_BROWSE pfOPCUAClient_Browse;
	#define GET_OPCUAClient_Browse(fl)  s_pfCMGetAPI2( "OPCUAClient_Browse", (RTS_VOID_FCTPTR *)&pfOPCUAClient_Browse, (fl), 0, 0)
	#define CAL_OPCUAClient_Browse  pfOPCUAClient_Browse
	#define CHK_OPCUAClient_Browse  (pfOPCUAClient_Browse != NULL)
	#define EXP_OPCUAClient_Browse  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_Browse", (RTS_UINTPTR)OPCUAClient_Browse, 0, 0) 
#endif



RTS_RESULT CDECL OPCUAClient_BrowseNext(RTS_HANDLE hConnection, OpcUa_Boolean releaseContinuationPoints, OpcUa_Int32 noOfContinuationPoints, OpcUa_ByteString *pContinuationPoints, void*cbfCallback, RTS_UINTPTR pcbCallbackData);
typedef RTS_RESULT (CDECL * PFOPCUACLIENT_BROWSENEXT) (RTS_HANDLE hConnection, OpcUa_Boolean releaseContinuationPoints, OpcUa_Int32 noOfContinuationPoints, OpcUa_ByteString *pContinuationPoints, void*cbfCallback, RTS_UINTPTR pcbCallbackData);
#if defined(CMPOPCUACLIENT_NOTIMPLEMENTED) || defined(OPCUACLIENT_BROWSENEXT_NOTIMPLEMENTED)
	#define USE_OPCUAClient_BrowseNext
	#define EXT_OPCUAClient_BrowseNext
	#define GET_OPCUAClient_BrowseNext(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OPCUAClient_BrowseNext(p0,p1,p2,p3,p4,p5)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_OPCUAClient_BrowseNext  FALSE
	#define EXP_OPCUAClient_BrowseNext  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OPCUAClient_BrowseNext
	#define EXT_OPCUAClient_BrowseNext
	#define GET_OPCUAClient_BrowseNext(fl)  CAL_CMGETAPI( "OPCUAClient_BrowseNext" ) 
	#define CAL_OPCUAClient_BrowseNext  OPCUAClient_BrowseNext
	#define CHK_OPCUAClient_BrowseNext  TRUE
	#define EXP_OPCUAClient_BrowseNext  CAL_CMEXPAPI( "OPCUAClient_BrowseNext" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_EXTERNAL)
	#define USE_OPCUAClient_BrowseNext
	#define EXT_OPCUAClient_BrowseNext
	#define GET_OPCUAClient_BrowseNext(fl)  CAL_CMGETAPI( "OPCUAClient_BrowseNext" ) 
	#define CAL_OPCUAClient_BrowseNext  OPCUAClient_BrowseNext
	#define CHK_OPCUAClient_BrowseNext  TRUE
	#define EXP_OPCUAClient_BrowseNext  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_BrowseNext", (RTS_UINTPTR)OPCUAClient_BrowseNext, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClientOPCUAClient_BrowseNext
	#define EXT_CmpOPCUAClientOPCUAClient_BrowseNext
	#define GET_CmpOPCUAClientOPCUAClient_BrowseNext  ERR_OK
	#define CAL_CmpOPCUAClientOPCUAClient_BrowseNext pICmpOPCUAClient->IOPCUAClient_BrowseNext
	#define CHK_CmpOPCUAClientOPCUAClient_BrowseNext (pICmpOPCUAClient != NULL)
	#define EXP_CmpOPCUAClientOPCUAClient_BrowseNext  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OPCUAClient_BrowseNext
	#define EXT_OPCUAClient_BrowseNext
	#define GET_OPCUAClient_BrowseNext(fl)  CAL_CMGETAPI( "OPCUAClient_BrowseNext" ) 
	#define CAL_OPCUAClient_BrowseNext pICmpOPCUAClient->IOPCUAClient_BrowseNext
	#define CHK_OPCUAClient_BrowseNext (pICmpOPCUAClient != NULL)
	#define EXP_OPCUAClient_BrowseNext  CAL_CMEXPAPI( "OPCUAClient_BrowseNext" ) 
#else /* DYNAMIC_LINK */
	#define USE_OPCUAClient_BrowseNext  PFOPCUACLIENT_BROWSENEXT pfOPCUAClient_BrowseNext;
	#define EXT_OPCUAClient_BrowseNext  extern PFOPCUACLIENT_BROWSENEXT pfOPCUAClient_BrowseNext;
	#define GET_OPCUAClient_BrowseNext(fl)  s_pfCMGetAPI2( "OPCUAClient_BrowseNext", (RTS_VOID_FCTPTR *)&pfOPCUAClient_BrowseNext, (fl), 0, 0)
	#define CAL_OPCUAClient_BrowseNext  pfOPCUAClient_BrowseNext
	#define CHK_OPCUAClient_BrowseNext  (pfOPCUAClient_BrowseNext != NULL)
	#define EXP_OPCUAClient_BrowseNext  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_BrowseNext", (RTS_UINTPTR)OPCUAClient_BrowseNext, 0, 0) 
#endif



RTS_RESULT CDECL OPCUAClient_TranslateBrowsePathsToNodeIds(RTS_HANDLE hConnection, OpcUa_Int32 noOfBrowsePaths, OpcUa_BrowsePath *pBrowsePaths, void*cbfCallback, RTS_UINTPTR pcbCallbackData);
typedef RTS_RESULT (CDECL * PFOPCUACLIENT_TRANSLATEBROWSEPATHSTONODEIDS) (RTS_HANDLE hConnection, OpcUa_Int32 noOfBrowsePaths, OpcUa_BrowsePath *pBrowsePaths, void*cbfCallback, RTS_UINTPTR pcbCallbackData);
#if defined(CMPOPCUACLIENT_NOTIMPLEMENTED) || defined(OPCUACLIENT_TRANSLATEBROWSEPATHSTONODEIDS_NOTIMPLEMENTED)
	#define USE_OPCUAClient_TranslateBrowsePathsToNodeIds
	#define EXT_OPCUAClient_TranslateBrowsePathsToNodeIds
	#define GET_OPCUAClient_TranslateBrowsePathsToNodeIds(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OPCUAClient_TranslateBrowsePathsToNodeIds(p0,p1,p2,p3,p4)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_OPCUAClient_TranslateBrowsePathsToNodeIds  FALSE
	#define EXP_OPCUAClient_TranslateBrowsePathsToNodeIds  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OPCUAClient_TranslateBrowsePathsToNodeIds
	#define EXT_OPCUAClient_TranslateBrowsePathsToNodeIds
	#define GET_OPCUAClient_TranslateBrowsePathsToNodeIds(fl)  CAL_CMGETAPI( "OPCUAClient_TranslateBrowsePathsToNodeIds" ) 
	#define CAL_OPCUAClient_TranslateBrowsePathsToNodeIds  OPCUAClient_TranslateBrowsePathsToNodeIds
	#define CHK_OPCUAClient_TranslateBrowsePathsToNodeIds  TRUE
	#define EXP_OPCUAClient_TranslateBrowsePathsToNodeIds  CAL_CMEXPAPI( "OPCUAClient_TranslateBrowsePathsToNodeIds" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_EXTERNAL)
	#define USE_OPCUAClient_TranslateBrowsePathsToNodeIds
	#define EXT_OPCUAClient_TranslateBrowsePathsToNodeIds
	#define GET_OPCUAClient_TranslateBrowsePathsToNodeIds(fl)  CAL_CMGETAPI( "OPCUAClient_TranslateBrowsePathsToNodeIds" ) 
	#define CAL_OPCUAClient_TranslateBrowsePathsToNodeIds  OPCUAClient_TranslateBrowsePathsToNodeIds
	#define CHK_OPCUAClient_TranslateBrowsePathsToNodeIds  TRUE
	#define EXP_OPCUAClient_TranslateBrowsePathsToNodeIds  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_TranslateBrowsePathsToNodeIds", (RTS_UINTPTR)OPCUAClient_TranslateBrowsePathsToNodeIds, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClientOPCUAClient_TranslateBrowsePathsToNodeIds
	#define EXT_CmpOPCUAClientOPCUAClient_TranslateBrowsePathsToNodeIds
	#define GET_CmpOPCUAClientOPCUAClient_TranslateBrowsePathsToNodeIds  ERR_OK
	#define CAL_CmpOPCUAClientOPCUAClient_TranslateBrowsePathsToNodeIds pICmpOPCUAClient->IOPCUAClient_TranslateBrowsePathsToNodeIds
	#define CHK_CmpOPCUAClientOPCUAClient_TranslateBrowsePathsToNodeIds (pICmpOPCUAClient != NULL)
	#define EXP_CmpOPCUAClientOPCUAClient_TranslateBrowsePathsToNodeIds  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OPCUAClient_TranslateBrowsePathsToNodeIds
	#define EXT_OPCUAClient_TranslateBrowsePathsToNodeIds
	#define GET_OPCUAClient_TranslateBrowsePathsToNodeIds(fl)  CAL_CMGETAPI( "OPCUAClient_TranslateBrowsePathsToNodeIds" ) 
	#define CAL_OPCUAClient_TranslateBrowsePathsToNodeIds pICmpOPCUAClient->IOPCUAClient_TranslateBrowsePathsToNodeIds
	#define CHK_OPCUAClient_TranslateBrowsePathsToNodeIds (pICmpOPCUAClient != NULL)
	#define EXP_OPCUAClient_TranslateBrowsePathsToNodeIds  CAL_CMEXPAPI( "OPCUAClient_TranslateBrowsePathsToNodeIds" ) 
#else /* DYNAMIC_LINK */
	#define USE_OPCUAClient_TranslateBrowsePathsToNodeIds  PFOPCUACLIENT_TRANSLATEBROWSEPATHSTONODEIDS pfOPCUAClient_TranslateBrowsePathsToNodeIds;
	#define EXT_OPCUAClient_TranslateBrowsePathsToNodeIds  extern PFOPCUACLIENT_TRANSLATEBROWSEPATHSTONODEIDS pfOPCUAClient_TranslateBrowsePathsToNodeIds;
	#define GET_OPCUAClient_TranslateBrowsePathsToNodeIds(fl)  s_pfCMGetAPI2( "OPCUAClient_TranslateBrowsePathsToNodeIds", (RTS_VOID_FCTPTR *)&pfOPCUAClient_TranslateBrowsePathsToNodeIds, (fl), 0, 0)
	#define CAL_OPCUAClient_TranslateBrowsePathsToNodeIds  pfOPCUAClient_TranslateBrowsePathsToNodeIds
	#define CHK_OPCUAClient_TranslateBrowsePathsToNodeIds  (pfOPCUAClient_TranslateBrowsePathsToNodeIds != NULL)
	#define EXP_OPCUAClient_TranslateBrowsePathsToNodeIds  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_TranslateBrowsePathsToNodeIds", (RTS_UINTPTR)OPCUAClient_TranslateBrowsePathsToNodeIds, 0, 0) 
#endif



RTS_RESULT CDECL OPCUAClient_RegisterNodes(RTS_HANDLE hConnection, OpcUa_Int32 noOfNodesToRegister, OpcUa_NodeId *pNodesToRegister, void*cbfCallback, RTS_UINTPTR pcbCallbackData);
typedef RTS_RESULT (CDECL * PFOPCUACLIENT_REGISTERNODES) (RTS_HANDLE hConnection, OpcUa_Int32 noOfNodesToRegister, OpcUa_NodeId *pNodesToRegister, void*cbfCallback, RTS_UINTPTR pcbCallbackData);
#if defined(CMPOPCUACLIENT_NOTIMPLEMENTED) || defined(OPCUACLIENT_REGISTERNODES_NOTIMPLEMENTED)
	#define USE_OPCUAClient_RegisterNodes
	#define EXT_OPCUAClient_RegisterNodes
	#define GET_OPCUAClient_RegisterNodes(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OPCUAClient_RegisterNodes(p0,p1,p2,p3,p4)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_OPCUAClient_RegisterNodes  FALSE
	#define EXP_OPCUAClient_RegisterNodes  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OPCUAClient_RegisterNodes
	#define EXT_OPCUAClient_RegisterNodes
	#define GET_OPCUAClient_RegisterNodes(fl)  CAL_CMGETAPI( "OPCUAClient_RegisterNodes" ) 
	#define CAL_OPCUAClient_RegisterNodes  OPCUAClient_RegisterNodes
	#define CHK_OPCUAClient_RegisterNodes  TRUE
	#define EXP_OPCUAClient_RegisterNodes  CAL_CMEXPAPI( "OPCUAClient_RegisterNodes" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_EXTERNAL)
	#define USE_OPCUAClient_RegisterNodes
	#define EXT_OPCUAClient_RegisterNodes
	#define GET_OPCUAClient_RegisterNodes(fl)  CAL_CMGETAPI( "OPCUAClient_RegisterNodes" ) 
	#define CAL_OPCUAClient_RegisterNodes  OPCUAClient_RegisterNodes
	#define CHK_OPCUAClient_RegisterNodes  TRUE
	#define EXP_OPCUAClient_RegisterNodes  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_RegisterNodes", (RTS_UINTPTR)OPCUAClient_RegisterNodes, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClientOPCUAClient_RegisterNodes
	#define EXT_CmpOPCUAClientOPCUAClient_RegisterNodes
	#define GET_CmpOPCUAClientOPCUAClient_RegisterNodes  ERR_OK
	#define CAL_CmpOPCUAClientOPCUAClient_RegisterNodes pICmpOPCUAClient->IOPCUAClient_RegisterNodes
	#define CHK_CmpOPCUAClientOPCUAClient_RegisterNodes (pICmpOPCUAClient != NULL)
	#define EXP_CmpOPCUAClientOPCUAClient_RegisterNodes  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OPCUAClient_RegisterNodes
	#define EXT_OPCUAClient_RegisterNodes
	#define GET_OPCUAClient_RegisterNodes(fl)  CAL_CMGETAPI( "OPCUAClient_RegisterNodes" ) 
	#define CAL_OPCUAClient_RegisterNodes pICmpOPCUAClient->IOPCUAClient_RegisterNodes
	#define CHK_OPCUAClient_RegisterNodes (pICmpOPCUAClient != NULL)
	#define EXP_OPCUAClient_RegisterNodes  CAL_CMEXPAPI( "OPCUAClient_RegisterNodes" ) 
#else /* DYNAMIC_LINK */
	#define USE_OPCUAClient_RegisterNodes  PFOPCUACLIENT_REGISTERNODES pfOPCUAClient_RegisterNodes;
	#define EXT_OPCUAClient_RegisterNodes  extern PFOPCUACLIENT_REGISTERNODES pfOPCUAClient_RegisterNodes;
	#define GET_OPCUAClient_RegisterNodes(fl)  s_pfCMGetAPI2( "OPCUAClient_RegisterNodes", (RTS_VOID_FCTPTR *)&pfOPCUAClient_RegisterNodes, (fl), 0, 0)
	#define CAL_OPCUAClient_RegisterNodes  pfOPCUAClient_RegisterNodes
	#define CHK_OPCUAClient_RegisterNodes  (pfOPCUAClient_RegisterNodes != NULL)
	#define EXP_OPCUAClient_RegisterNodes  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_RegisterNodes", (RTS_UINTPTR)OPCUAClient_RegisterNodes, 0, 0) 
#endif



RTS_RESULT CDECL OPCUAClient_UnregisterNodes(RTS_HANDLE hConnection, OpcUa_Int32 noOfNodesToUnregister, OpcUa_NodeId *pNodesToUnregister, void*cbfCallback, RTS_UINTPTR pcbCallbackData);
typedef RTS_RESULT (CDECL * PFOPCUACLIENT_UNREGISTERNODES) (RTS_HANDLE hConnection, OpcUa_Int32 noOfNodesToUnregister, OpcUa_NodeId *pNodesToUnregister, void*cbfCallback, RTS_UINTPTR pcbCallbackData);
#if defined(CMPOPCUACLIENT_NOTIMPLEMENTED) || defined(OPCUACLIENT_UNREGISTERNODES_NOTIMPLEMENTED)
	#define USE_OPCUAClient_UnregisterNodes
	#define EXT_OPCUAClient_UnregisterNodes
	#define GET_OPCUAClient_UnregisterNodes(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OPCUAClient_UnregisterNodes(p0,p1,p2,p3,p4)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_OPCUAClient_UnregisterNodes  FALSE
	#define EXP_OPCUAClient_UnregisterNodes  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OPCUAClient_UnregisterNodes
	#define EXT_OPCUAClient_UnregisterNodes
	#define GET_OPCUAClient_UnregisterNodes(fl)  CAL_CMGETAPI( "OPCUAClient_UnregisterNodes" ) 
	#define CAL_OPCUAClient_UnregisterNodes  OPCUAClient_UnregisterNodes
	#define CHK_OPCUAClient_UnregisterNodes  TRUE
	#define EXP_OPCUAClient_UnregisterNodes  CAL_CMEXPAPI( "OPCUAClient_UnregisterNodes" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_EXTERNAL)
	#define USE_OPCUAClient_UnregisterNodes
	#define EXT_OPCUAClient_UnregisterNodes
	#define GET_OPCUAClient_UnregisterNodes(fl)  CAL_CMGETAPI( "OPCUAClient_UnregisterNodes" ) 
	#define CAL_OPCUAClient_UnregisterNodes  OPCUAClient_UnregisterNodes
	#define CHK_OPCUAClient_UnregisterNodes  TRUE
	#define EXP_OPCUAClient_UnregisterNodes  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_UnregisterNodes", (RTS_UINTPTR)OPCUAClient_UnregisterNodes, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClientOPCUAClient_UnregisterNodes
	#define EXT_CmpOPCUAClientOPCUAClient_UnregisterNodes
	#define GET_CmpOPCUAClientOPCUAClient_UnregisterNodes  ERR_OK
	#define CAL_CmpOPCUAClientOPCUAClient_UnregisterNodes pICmpOPCUAClient->IOPCUAClient_UnregisterNodes
	#define CHK_CmpOPCUAClientOPCUAClient_UnregisterNodes (pICmpOPCUAClient != NULL)
	#define EXP_CmpOPCUAClientOPCUAClient_UnregisterNodes  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OPCUAClient_UnregisterNodes
	#define EXT_OPCUAClient_UnregisterNodes
	#define GET_OPCUAClient_UnregisterNodes(fl)  CAL_CMGETAPI( "OPCUAClient_UnregisterNodes" ) 
	#define CAL_OPCUAClient_UnregisterNodes pICmpOPCUAClient->IOPCUAClient_UnregisterNodes
	#define CHK_OPCUAClient_UnregisterNodes (pICmpOPCUAClient != NULL)
	#define EXP_OPCUAClient_UnregisterNodes  CAL_CMEXPAPI( "OPCUAClient_UnregisterNodes" ) 
#else /* DYNAMIC_LINK */
	#define USE_OPCUAClient_UnregisterNodes  PFOPCUACLIENT_UNREGISTERNODES pfOPCUAClient_UnregisterNodes;
	#define EXT_OPCUAClient_UnregisterNodes  extern PFOPCUACLIENT_UNREGISTERNODES pfOPCUAClient_UnregisterNodes;
	#define GET_OPCUAClient_UnregisterNodes(fl)  s_pfCMGetAPI2( "OPCUAClient_UnregisterNodes", (RTS_VOID_FCTPTR *)&pfOPCUAClient_UnregisterNodes, (fl), 0, 0)
	#define CAL_OPCUAClient_UnregisterNodes  pfOPCUAClient_UnregisterNodes
	#define CHK_OPCUAClient_UnregisterNodes  (pfOPCUAClient_UnregisterNodes != NULL)
	#define EXP_OPCUAClient_UnregisterNodes  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OPCUAClient_UnregisterNodes", (RTS_UINTPTR)OPCUAClient_UnregisterNodes, 0, 0) 
#endif






typedef struct
{
	IBase_C *pBase;
	PFOPCUACLIENT_CREATE IOPCUAClient_Create;
 	PFOPCUACLIENT_DELETE IOPCUAClient_Delete;
 	PFOPCUACLIENT_GETCONFIG IOPCUAClient_GetConfig;
 	PFOPCUACLIENTDISCOVERY_GETENDPOINTS IOPCUAClientDiscovery_GetEndpoints;
 	PFOPCUACLIENTDISCOVERY_FINDSERVERS IOPCUAClientDiscovery_FindServers;
 	PFOPCUACLIENTDISCOVERY_FINDSERVERSONNETWORK IOPCUAClientDiscovery_FindServersOnNetwork;
 	PFOPCUACLIENT_CONNECT IOPCUAClient_Connect;
 	PFOPCUACLIENT_DISCONNECT IOPCUAClient_Disconnect;
 	PFOPCUACLIENT_READ IOPCUAClient_Read;
 	PFOPCUACLIENT_WRITE IOPCUAClient_Write;
 	PFOPCUACLIENT_CREATESUBSCRIPTION IOPCUAClient_CreateSubscription;
 	PFOPCUACLIENT_DELETESUBSCRIPTION IOPCUAClient_DeleteSubscription;
 	PFOPCUACLIENT_MODIFYSUBSCRIPTION IOPCUAClient_ModifySubscription;
 	PFOPCUACLIENT_SETPUBLISHINGMODE IOPCUAClient_SetPublishingMode;
 	PFOPCUACLIENT_CREATEMONITOREDITEMS IOPCUAClient_CreateMonitoredItems;
 	PFOPCUACLIENT_MODIFYMONITOREDITEMS IOPCUAClient_ModifyMonitoredItems;
 	PFOPCUACLIENT_SETMONITORINGMODE IOPCUAClient_SetMonitoringMode;
 	PFOPCUACLIENT_DELETEMONITOREDITEMS IOPCUAClient_DeleteMonitoredItems;
 	PFOPCUACLIENT_EXTENSIONOBJECTATTACHREADONLY IOPCUAClient_ExtensionObjectAttachReadOnly;
 	PFOPCUACLIENT_BROWSE IOPCUAClient_Browse;
 	PFOPCUACLIENT_BROWSENEXT IOPCUAClient_BrowseNext;
 	PFOPCUACLIENT_TRANSLATEBROWSEPATHSTONODEIDS IOPCUAClient_TranslateBrowsePathsToNodeIds;
 	PFOPCUACLIENT_REGISTERNODES IOPCUAClient_RegisterNodes;
 	PFOPCUACLIENT_UNREGISTERNODES IOPCUAClient_UnregisterNodes;
 } ICmpOPCUAClient_C;

#ifdef CPLUSPLUS
class ICmpOPCUAClient : public IBase
{
	public:
		virtual RTS_HANDLE CDECL IOPCUAClient_Create(OpcUa_ApplicationDescription *pConfiguration, RTS_RESULT *pResult) =0;
		virtual RTS_RESULT CDECL IOPCUAClient_Delete(RTS_HANDLE hClient) =0;
		virtual OpcUa_ApplicationDescription* CDECL IOPCUAClient_GetConfig(RTS_HANDLE hClient, RTS_RESULT *pResult) =0;
		virtual RTS_RESULT CDECL IOPCUAClientDiscovery_GetEndpoints(RTS_HANDLE hClient, OpcUa_String* psEndpointURL, PF_OPCUACLIENT_GETENDPOINTS_CALLBACK cbfGetEndpoints, RTS_UINTPTR pcbGetEndpointsData) =0;
		virtual RTS_RESULT CDECL IOPCUAClientDiscovery_FindServers(RTS_HANDLE hClient, OpcUa_String* psEndpointURL, PF_OPCUACLIENT_FINDSERVERS_CALLBACK cbfFindServers, RTS_UINTPTR pcbFindServersData) =0;
		virtual RTS_RESULT CDECL IOPCUAClientDiscovery_FindServersOnNetwork(RTS_HANDLE hClient, OpcUa_String* psEndpointURL, OpcUa_UInt32 startingRecordId, OpcUa_UInt32 maxRecordsToReturn, OpcUa_Int32 numServerCapabilityFilters, OpcUa_String *psServerCapabilityFilters, PF_OPCUACLIENT_FINDSERVERSONNETWORK_CALLBACK cbfFindServersOnNetwork, RTS_UINTPTR pcbFindServersOnNetworkData) =0;
		virtual RTS_HANDLE CDECL IOPCUAClient_Connect(RTS_HANDLE hClient, OPCUAClientConnectionConfiguration* pConnectionConfiguration, PF_OPCUACLIENT_CONNECTION_CALLBACK cbfConnection, RTS_UINTPTR pcbConnectionData, PF_OPCUACLIENT_VERIFY_CERTIFICATE_CALLBACK cbfVerifyCertificate, RTS_UINTPTR pcbVerifyCertData, PF_OPCUACLIENT_GETCREDENTIALS_CALLBACK cbfGetCredentials, RTS_UINTPTR pcbGetCredentialsData) =0;
		virtual RTS_RESULT CDECL IOPCUAClient_Disconnect(RTS_HANDLE hConnection) =0;
		virtual RTS_RESULT CDECL IOPCUAClient_Read(RTS_HANDLE hConnection, OpcUa_Double maxAge, OpcUa_TimestampsToReturn timestampsToReturn, OpcUa_ReadValueId *pNodesToRead, OpcUa_Int32 numOfNodes, PF_OPCUACLIENT_READ_CALLBACK cbfRead, RTS_UINTPTR pcbReadData) =0;
		virtual RTS_RESULT CDECL IOPCUAClient_Write(RTS_HANDLE hConnection, OpcUa_WriteValue *pNodesToWrite, OpcUa_Int32 numOfNodes, PF_OPCUACLIENT_WRITE_CALLBACK cbfWrite, RTS_UINTPTR pcbWriteData) =0;
		virtual RTS_HANDLE CDECL IOPCUAClient_CreateSubscription(RTS_HANDLE hConnection, OpcUa_Double publishingInterval, OpcUa_UInt32 lifetimeCount, OpcUa_UInt32 maxKeepAliveCount, OpcUa_UInt32 maxNotificationsPerPublish, OpcUa_Boolean publishingEnabled, OpcUa_Byte priority, PF_OPCUACLIENT_SUBSCRIPTION_STATE_CALLBACK cbfSubscriptionState, RTS_UINTPTR pcbSubscriptionStateData, PF_OPCUACLIENT_SUBSCRIPTION_PARAMETER_CALLBACK cbfSubscriptionParameter, RTS_UINTPTR pcbSubscriptionParameterData, RTS_RESULT *pResult) =0;
		virtual RTS_RESULT CDECL IOPCUAClient_DeleteSubscription(RTS_HANDLE hSubscription) =0;
		virtual RTS_RESULT CDECL IOPCUAClient_ModifySubscription(RTS_HANDLE hSubscription, OpcUa_Double reqPublishingInterval, OpcUa_UInt32 reqLifeTimeCount, OpcUa_UInt32 reqMaxKeepAliveCount, OpcUa_UInt32 maxNotificationsPerPublish, OpcUa_Byte priority) =0;
		virtual RTS_RESULT CDECL IOPCUAClient_SetPublishingMode(RTS_HANDLE hSubscription, OpcUa_Boolean publishingEnabled) =0;
		virtual RTS_RESULT CDECL IOPCUAClient_CreateMonitoredItems(RTS_HANDLE hSubscription, OpcUa_TimestampsToReturn eTimestampsToReturn, OpcUa_Int32 nNoOfItemsToCreate, OPCUAClientMonitoredItemConfiguration* pMonitoredItemsToCreate, PF_OPCUACLIENT_MONITOREDITEM_STATE_CALLBACK cbfMonitoredItemState, PF_OPCUACLIENT_MONITOREDITEM_PARAMETER_CALLBACK cbfMonitoredItemParameter, PF_OPCUACLIENT_MONITOREDITEM_VALUE_CALLBACK cbfMonitoredItemValue, PF_OPCUACLIENT_MONITOREDITEM_EVENT_CALLBACK cbfMonitoredItemEvent) =0;
		virtual RTS_RESULT CDECL IOPCUAClient_ModifyMonitoredItems(RTS_HANDLE hSubscription, OpcUa_TimestampsToReturn eTimestampsToReturn, OpcUa_Int32 nNoOfItemsToModify, OPCUAClientMonitoredItemConfiguration* pMonitoredItemsToModify) =0;
		virtual RTS_RESULT CDECL IOPCUAClient_SetMonitoringMode(RTS_HANDLE hSubscription, OpcUa_MonitoringMode monitoringMode, OpcUa_Int32 nNoOfMonitoredItems, RTS_HANDLE *phItems) =0;
		virtual RTS_RESULT CDECL IOPCUAClient_DeleteMonitoredItems(RTS_HANDLE hSubscription, OpcUa_Int32 nNoOfItemsToDelete, RTS_HANDLE *phItems) =0;
		virtual RTS_RESULT CDECL IOPCUAClient_ExtensionObjectAttachReadOnly(OpcUa_UInt32 TypeId, OpcUa_ExtensionObject* pExtensionObject, OpcUa_Void* pObject) =0;
		virtual RTS_RESULT CDECL IOPCUAClient_Browse(RTS_HANDLE hConnection, OpcUa_ViewDescription view, OpcUa_Int32 requestedMaxReferencesPerNode, OpcUa_Int32 noOfNodesToBrowse, OpcUa_BrowseDescription *pNodesToBrowse, void*cbfCallback, RTS_UINTPTR pcbCallbackData) =0;
		virtual RTS_RESULT CDECL IOPCUAClient_BrowseNext(RTS_HANDLE hConnection, OpcUa_Boolean releaseContinuationPoints, OpcUa_Int32 noOfContinuationPoints, OpcUa_ByteString *pContinuationPoints, void*cbfCallback, RTS_UINTPTR pcbCallbackData) =0;
		virtual RTS_RESULT CDECL IOPCUAClient_TranslateBrowsePathsToNodeIds(RTS_HANDLE hConnection, OpcUa_Int32 noOfBrowsePaths, OpcUa_BrowsePath *pBrowsePaths, void*cbfCallback, RTS_UINTPTR pcbCallbackData) =0;
		virtual RTS_RESULT CDECL IOPCUAClient_RegisterNodes(RTS_HANDLE hConnection, OpcUa_Int32 noOfNodesToRegister, OpcUa_NodeId *pNodesToRegister, void*cbfCallback, RTS_UINTPTR pcbCallbackData) =0;
		virtual RTS_RESULT CDECL IOPCUAClient_UnregisterNodes(RTS_HANDLE hConnection, OpcUa_Int32 noOfNodesToUnregister, OpcUa_NodeId *pNodesToUnregister, void*cbfCallback, RTS_UINTPTR pcbCallbackData) =0;
};
	#ifndef ITF_CmpOPCUAClient
		#define ITF_CmpOPCUAClient static ICmpOPCUAClient *pICmpOPCUAClient = NULL;
	#endif
	#define EXTITF_CmpOPCUAClient
#else	/*CPLUSPLUS*/
	typedef ICmpOPCUAClient_C		ICmpOPCUAClient;
	#ifndef ITF_CmpOPCUAClient
		#define ITF_CmpOPCUAClient
	#endif
	#define EXTITF_CmpOPCUAClient
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_CMPOPCUACLIENTITF_H_*/
