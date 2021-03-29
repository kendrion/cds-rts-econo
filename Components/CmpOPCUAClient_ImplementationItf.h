 /**
 * <interfacename>CmpOPCUAClient Implementation</interfacename>
 * <description></description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */


	
	
#ifndef _CMPOPCUACLIENT_IMPLEMENTATIONITF_H_
#define _CMPOPCUACLIENT_IMPLEMENTATIONITF_H_

#include "CmpStd.h"

 

 



#include "CmpOPCUAClientItf.h"

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
/*  Comments are ignored for m4 compiler so restructured text can be used.  */

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

void CDECL CDECL_EXT opcuaclient_browse_internal(opcuaclient_browse_internal_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUACLIENT_BROWSE_INTERNAL_IEC) (opcuaclient_browse_internal_struct *p);
#if defined(CMPOPCUACLIENT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUACLIENT_BROWSE_INTERNAL_NOTIMPLEMENTED)
	#define USE_opcuaclient_browse_internal
	#define EXT_opcuaclient_browse_internal
	#define GET_opcuaclient_browse_internal(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaclient_browse_internal(p0) 
	#define CHK_opcuaclient_browse_internal  FALSE
	#define EXP_opcuaclient_browse_internal  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaclient_browse_internal
	#define EXT_opcuaclient_browse_internal
	#define GET_opcuaclient_browse_internal(fl)  CAL_CMGETAPI( "opcuaclient_browse_internal" ) 
	#define CAL_opcuaclient_browse_internal  opcuaclient_browse_internal
	#define CHK_opcuaclient_browse_internal  TRUE
	#define EXP_opcuaclient_browse_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_browse_internal", (RTS_UINTPTR)opcuaclient_browse_internal, 1, RTSITF_GET_SIGNATURE(0x6BD93DFC, 0xC49DAFBB), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaclient_browse_internal
	#define EXT_opcuaclient_browse_internal
	#define GET_opcuaclient_browse_internal(fl)  CAL_CMGETAPI( "opcuaclient_browse_internal" ) 
	#define CAL_opcuaclient_browse_internal  opcuaclient_browse_internal
	#define CHK_opcuaclient_browse_internal  TRUE
	#define EXP_opcuaclient_browse_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_browse_internal", (RTS_UINTPTR)opcuaclient_browse_internal, 1, RTSITF_GET_SIGNATURE(0x6BD93DFC, 0xC49DAFBB), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClient_Implementationopcuaclient_browse_internal
	#define EXT_CmpOPCUAClient_Implementationopcuaclient_browse_internal
	#define GET_CmpOPCUAClient_Implementationopcuaclient_browse_internal  ERR_OK
	#define CAL_CmpOPCUAClient_Implementationopcuaclient_browse_internal  opcuaclient_browse_internal
	#define CHK_CmpOPCUAClient_Implementationopcuaclient_browse_internal  TRUE
	#define EXP_CmpOPCUAClient_Implementationopcuaclient_browse_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_browse_internal", (RTS_UINTPTR)opcuaclient_browse_internal, 1, RTSITF_GET_SIGNATURE(0x6BD93DFC, 0xC49DAFBB), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaclient_browse_internal
	#define EXT_opcuaclient_browse_internal
	#define GET_opcuaclient_browse_internal(fl)  CAL_CMGETAPI( "opcuaclient_browse_internal" ) 
	#define CAL_opcuaclient_browse_internal  opcuaclient_browse_internal
	#define CHK_opcuaclient_browse_internal  TRUE
	#define EXP_opcuaclient_browse_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_browse_internal", (RTS_UINTPTR)opcuaclient_browse_internal, 1, RTSITF_GET_SIGNATURE(0x6BD93DFC, 0xC49DAFBB), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaclient_browse_internal  PFOPCUACLIENT_BROWSE_INTERNAL_IEC pfopcuaclient_browse_internal;
	#define EXT_opcuaclient_browse_internal  extern PFOPCUACLIENT_BROWSE_INTERNAL_IEC pfopcuaclient_browse_internal;
	#define GET_opcuaclient_browse_internal(fl)  s_pfCMGetAPI2( "opcuaclient_browse_internal", (RTS_VOID_FCTPTR *)&pfopcuaclient_browse_internal, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0x6BD93DFC, 0xC49DAFBB), 0x03051000)
	#define CAL_opcuaclient_browse_internal  pfopcuaclient_browse_internal
	#define CHK_opcuaclient_browse_internal  (pfopcuaclient_browse_internal != NULL)
	#define EXP_opcuaclient_browse_internal   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_browse_internal", (RTS_UINTPTR)opcuaclient_browse_internal, 1, RTSITF_GET_SIGNATURE(0x6BD93DFC, 0xC49DAFBB), 0x03051000) 
#endif


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

void CDECL CDECL_EXT opcuaclient_browsenext_internal(opcuaclient_browsenext_internal_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUACLIENT_BROWSENEXT_INTERNAL_IEC) (opcuaclient_browsenext_internal_struct *p);
#if defined(CMPOPCUACLIENT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUACLIENT_BROWSENEXT_INTERNAL_NOTIMPLEMENTED)
	#define USE_opcuaclient_browsenext_internal
	#define EXT_opcuaclient_browsenext_internal
	#define GET_opcuaclient_browsenext_internal(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaclient_browsenext_internal(p0) 
	#define CHK_opcuaclient_browsenext_internal  FALSE
	#define EXP_opcuaclient_browsenext_internal  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaclient_browsenext_internal
	#define EXT_opcuaclient_browsenext_internal
	#define GET_opcuaclient_browsenext_internal(fl)  CAL_CMGETAPI( "opcuaclient_browsenext_internal" ) 
	#define CAL_opcuaclient_browsenext_internal  opcuaclient_browsenext_internal
	#define CHK_opcuaclient_browsenext_internal  TRUE
	#define EXP_opcuaclient_browsenext_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_browsenext_internal", (RTS_UINTPTR)opcuaclient_browsenext_internal, 1, RTSITF_GET_SIGNATURE(0xD8FD4FBA, 0x96744413), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaclient_browsenext_internal
	#define EXT_opcuaclient_browsenext_internal
	#define GET_opcuaclient_browsenext_internal(fl)  CAL_CMGETAPI( "opcuaclient_browsenext_internal" ) 
	#define CAL_opcuaclient_browsenext_internal  opcuaclient_browsenext_internal
	#define CHK_opcuaclient_browsenext_internal  TRUE
	#define EXP_opcuaclient_browsenext_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_browsenext_internal", (RTS_UINTPTR)opcuaclient_browsenext_internal, 1, RTSITF_GET_SIGNATURE(0xD8FD4FBA, 0x96744413), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClient_Implementationopcuaclient_browsenext_internal
	#define EXT_CmpOPCUAClient_Implementationopcuaclient_browsenext_internal
	#define GET_CmpOPCUAClient_Implementationopcuaclient_browsenext_internal  ERR_OK
	#define CAL_CmpOPCUAClient_Implementationopcuaclient_browsenext_internal  opcuaclient_browsenext_internal
	#define CHK_CmpOPCUAClient_Implementationopcuaclient_browsenext_internal  TRUE
	#define EXP_CmpOPCUAClient_Implementationopcuaclient_browsenext_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_browsenext_internal", (RTS_UINTPTR)opcuaclient_browsenext_internal, 1, RTSITF_GET_SIGNATURE(0xD8FD4FBA, 0x96744413), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaclient_browsenext_internal
	#define EXT_opcuaclient_browsenext_internal
	#define GET_opcuaclient_browsenext_internal(fl)  CAL_CMGETAPI( "opcuaclient_browsenext_internal" ) 
	#define CAL_opcuaclient_browsenext_internal  opcuaclient_browsenext_internal
	#define CHK_opcuaclient_browsenext_internal  TRUE
	#define EXP_opcuaclient_browsenext_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_browsenext_internal", (RTS_UINTPTR)opcuaclient_browsenext_internal, 1, RTSITF_GET_SIGNATURE(0xD8FD4FBA, 0x96744413), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaclient_browsenext_internal  PFOPCUACLIENT_BROWSENEXT_INTERNAL_IEC pfopcuaclient_browsenext_internal;
	#define EXT_opcuaclient_browsenext_internal  extern PFOPCUACLIENT_BROWSENEXT_INTERNAL_IEC pfopcuaclient_browsenext_internal;
	#define GET_opcuaclient_browsenext_internal(fl)  s_pfCMGetAPI2( "opcuaclient_browsenext_internal", (RTS_VOID_FCTPTR *)&pfopcuaclient_browsenext_internal, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0xD8FD4FBA, 0x96744413), 0x03051000)
	#define CAL_opcuaclient_browsenext_internal  pfopcuaclient_browsenext_internal
	#define CHK_opcuaclient_browsenext_internal  (pfopcuaclient_browsenext_internal != NULL)
	#define EXP_opcuaclient_browsenext_internal   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_browsenext_internal", (RTS_UINTPTR)opcuaclient_browsenext_internal, 1, RTSITF_GET_SIGNATURE(0xD8FD4FBA, 0x96744413), 0x03051000) 
#endif


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

void CDECL CDECL_EXT opcuaclient_connect_internal(opcuaclient_connect_internal_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUACLIENT_CONNECT_INTERNAL_IEC) (opcuaclient_connect_internal_struct *p);
#if defined(CMPOPCUACLIENT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUACLIENT_CONNECT_INTERNAL_NOTIMPLEMENTED)
	#define USE_opcuaclient_connect_internal
	#define EXT_opcuaclient_connect_internal
	#define GET_opcuaclient_connect_internal(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaclient_connect_internal(p0) 
	#define CHK_opcuaclient_connect_internal  FALSE
	#define EXP_opcuaclient_connect_internal  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaclient_connect_internal
	#define EXT_opcuaclient_connect_internal
	#define GET_opcuaclient_connect_internal(fl)  CAL_CMGETAPI( "opcuaclient_connect_internal" ) 
	#define CAL_opcuaclient_connect_internal  opcuaclient_connect_internal
	#define CHK_opcuaclient_connect_internal  TRUE
	#define EXP_opcuaclient_connect_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_connect_internal", (RTS_UINTPTR)opcuaclient_connect_internal, 1, RTSITF_GET_SIGNATURE(0xBB6335AF, 0xF9429CFA), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaclient_connect_internal
	#define EXT_opcuaclient_connect_internal
	#define GET_opcuaclient_connect_internal(fl)  CAL_CMGETAPI( "opcuaclient_connect_internal" ) 
	#define CAL_opcuaclient_connect_internal  opcuaclient_connect_internal
	#define CHK_opcuaclient_connect_internal  TRUE
	#define EXP_opcuaclient_connect_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_connect_internal", (RTS_UINTPTR)opcuaclient_connect_internal, 1, RTSITF_GET_SIGNATURE(0xBB6335AF, 0xF9429CFA), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClient_Implementationopcuaclient_connect_internal
	#define EXT_CmpOPCUAClient_Implementationopcuaclient_connect_internal
	#define GET_CmpOPCUAClient_Implementationopcuaclient_connect_internal  ERR_OK
	#define CAL_CmpOPCUAClient_Implementationopcuaclient_connect_internal  opcuaclient_connect_internal
	#define CHK_CmpOPCUAClient_Implementationopcuaclient_connect_internal  TRUE
	#define EXP_CmpOPCUAClient_Implementationopcuaclient_connect_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_connect_internal", (RTS_UINTPTR)opcuaclient_connect_internal, 1, RTSITF_GET_SIGNATURE(0xBB6335AF, 0xF9429CFA), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaclient_connect_internal
	#define EXT_opcuaclient_connect_internal
	#define GET_opcuaclient_connect_internal(fl)  CAL_CMGETAPI( "opcuaclient_connect_internal" ) 
	#define CAL_opcuaclient_connect_internal  opcuaclient_connect_internal
	#define CHK_opcuaclient_connect_internal  TRUE
	#define EXP_opcuaclient_connect_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_connect_internal", (RTS_UINTPTR)opcuaclient_connect_internal, 1, RTSITF_GET_SIGNATURE(0xBB6335AF, 0xF9429CFA), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaclient_connect_internal  PFOPCUACLIENT_CONNECT_INTERNAL_IEC pfopcuaclient_connect_internal;
	#define EXT_opcuaclient_connect_internal  extern PFOPCUACLIENT_CONNECT_INTERNAL_IEC pfopcuaclient_connect_internal;
	#define GET_opcuaclient_connect_internal(fl)  s_pfCMGetAPI2( "opcuaclient_connect_internal", (RTS_VOID_FCTPTR *)&pfopcuaclient_connect_internal, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0xBB6335AF, 0xF9429CFA), 0x03051000)
	#define CAL_opcuaclient_connect_internal  pfopcuaclient_connect_internal
	#define CHK_opcuaclient_connect_internal  (pfopcuaclient_connect_internal != NULL)
	#define EXP_opcuaclient_connect_internal   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_connect_internal", (RTS_UINTPTR)opcuaclient_connect_internal, 1, RTSITF_GET_SIGNATURE(0xBB6335AF, 0xF9429CFA), 0x03051000) 
#endif


/**
 * <description>opcuaclient_create_internal</description>
 */
typedef struct tagopcuaclient_create_internal_struct
{
	OpcUa_ApplicationDescription *pConfiguration;	/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_HANDLE OPCUAClient_Create_internal;	/* VAR_OUTPUT */	
} opcuaclient_create_internal_struct;

void CDECL CDECL_EXT opcuaclient_create_internal(opcuaclient_create_internal_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUACLIENT_CREATE_INTERNAL_IEC) (opcuaclient_create_internal_struct *p);
#if defined(CMPOPCUACLIENT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUACLIENT_CREATE_INTERNAL_NOTIMPLEMENTED)
	#define USE_opcuaclient_create_internal
	#define EXT_opcuaclient_create_internal
	#define GET_opcuaclient_create_internal(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaclient_create_internal(p0) 
	#define CHK_opcuaclient_create_internal  FALSE
	#define EXP_opcuaclient_create_internal  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaclient_create_internal
	#define EXT_opcuaclient_create_internal
	#define GET_opcuaclient_create_internal(fl)  CAL_CMGETAPI( "opcuaclient_create_internal" ) 
	#define CAL_opcuaclient_create_internal  opcuaclient_create_internal
	#define CHK_opcuaclient_create_internal  TRUE
	#define EXP_opcuaclient_create_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_create_internal", (RTS_UINTPTR)opcuaclient_create_internal, 1, 0x8877DB57, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaclient_create_internal
	#define EXT_opcuaclient_create_internal
	#define GET_opcuaclient_create_internal(fl)  CAL_CMGETAPI( "opcuaclient_create_internal" ) 
	#define CAL_opcuaclient_create_internal  opcuaclient_create_internal
	#define CHK_opcuaclient_create_internal  TRUE
	#define EXP_opcuaclient_create_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_create_internal", (RTS_UINTPTR)opcuaclient_create_internal, 1, 0x8877DB57, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClient_Implementationopcuaclient_create_internal
	#define EXT_CmpOPCUAClient_Implementationopcuaclient_create_internal
	#define GET_CmpOPCUAClient_Implementationopcuaclient_create_internal  ERR_OK
	#define CAL_CmpOPCUAClient_Implementationopcuaclient_create_internal  opcuaclient_create_internal
	#define CHK_CmpOPCUAClient_Implementationopcuaclient_create_internal  TRUE
	#define EXP_CmpOPCUAClient_Implementationopcuaclient_create_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_create_internal", (RTS_UINTPTR)opcuaclient_create_internal, 1, 0x8877DB57, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaclient_create_internal
	#define EXT_opcuaclient_create_internal
	#define GET_opcuaclient_create_internal(fl)  CAL_CMGETAPI( "opcuaclient_create_internal" ) 
	#define CAL_opcuaclient_create_internal  opcuaclient_create_internal
	#define CHK_opcuaclient_create_internal  TRUE
	#define EXP_opcuaclient_create_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_create_internal", (RTS_UINTPTR)opcuaclient_create_internal, 1, 0x8877DB57, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaclient_create_internal  PFOPCUACLIENT_CREATE_INTERNAL_IEC pfopcuaclient_create_internal;
	#define EXT_opcuaclient_create_internal  extern PFOPCUACLIENT_CREATE_INTERNAL_IEC pfopcuaclient_create_internal;
	#define GET_opcuaclient_create_internal(fl)  s_pfCMGetAPI2( "opcuaclient_create_internal", (RTS_VOID_FCTPTR *)&pfopcuaclient_create_internal, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x8877DB57, 0x03051000)
	#define CAL_opcuaclient_create_internal  pfopcuaclient_create_internal
	#define CHK_opcuaclient_create_internal  (pfopcuaclient_create_internal != NULL)
	#define EXP_opcuaclient_create_internal   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_create_internal", (RTS_UINTPTR)opcuaclient_create_internal, 1, 0x8877DB57, 0x03051000) 
#endif


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

void CDECL CDECL_EXT opcuaclient_createmonitoreditems_internal(opcuaclient_createmonitoreditems_internal_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUACLIENT_CREATEMONITOREDITEMS_INTERNAL_IEC) (opcuaclient_createmonitoreditems_internal_struct *p);
#if defined(CMPOPCUACLIENT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUACLIENT_CREATEMONITOREDITEMS_INTERNAL_NOTIMPLEMENTED)
	#define USE_opcuaclient_createmonitoreditems_internal
	#define EXT_opcuaclient_createmonitoreditems_internal
	#define GET_opcuaclient_createmonitoreditems_internal(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaclient_createmonitoreditems_internal(p0) 
	#define CHK_opcuaclient_createmonitoreditems_internal  FALSE
	#define EXP_opcuaclient_createmonitoreditems_internal  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaclient_createmonitoreditems_internal
	#define EXT_opcuaclient_createmonitoreditems_internal
	#define GET_opcuaclient_createmonitoreditems_internal(fl)  CAL_CMGETAPI( "opcuaclient_createmonitoreditems_internal" ) 
	#define CAL_opcuaclient_createmonitoreditems_internal  opcuaclient_createmonitoreditems_internal
	#define CHK_opcuaclient_createmonitoreditems_internal  TRUE
	#define EXP_opcuaclient_createmonitoreditems_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_createmonitoreditems_internal", (RTS_UINTPTR)opcuaclient_createmonitoreditems_internal, 1, RTSITF_GET_SIGNATURE(0x78929EB6, 0x015C5817), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaclient_createmonitoreditems_internal
	#define EXT_opcuaclient_createmonitoreditems_internal
	#define GET_opcuaclient_createmonitoreditems_internal(fl)  CAL_CMGETAPI( "opcuaclient_createmonitoreditems_internal" ) 
	#define CAL_opcuaclient_createmonitoreditems_internal  opcuaclient_createmonitoreditems_internal
	#define CHK_opcuaclient_createmonitoreditems_internal  TRUE
	#define EXP_opcuaclient_createmonitoreditems_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_createmonitoreditems_internal", (RTS_UINTPTR)opcuaclient_createmonitoreditems_internal, 1, RTSITF_GET_SIGNATURE(0x78929EB6, 0x015C5817), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClient_Implementationopcuaclient_createmonitoreditems_internal
	#define EXT_CmpOPCUAClient_Implementationopcuaclient_createmonitoreditems_internal
	#define GET_CmpOPCUAClient_Implementationopcuaclient_createmonitoreditems_internal  ERR_OK
	#define CAL_CmpOPCUAClient_Implementationopcuaclient_createmonitoreditems_internal  opcuaclient_createmonitoreditems_internal
	#define CHK_CmpOPCUAClient_Implementationopcuaclient_createmonitoreditems_internal  TRUE
	#define EXP_CmpOPCUAClient_Implementationopcuaclient_createmonitoreditems_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_createmonitoreditems_internal", (RTS_UINTPTR)opcuaclient_createmonitoreditems_internal, 1, RTSITF_GET_SIGNATURE(0x78929EB6, 0x015C5817), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaclient_createmonitoreditems_internal
	#define EXT_opcuaclient_createmonitoreditems_internal
	#define GET_opcuaclient_createmonitoreditems_internal(fl)  CAL_CMGETAPI( "opcuaclient_createmonitoreditems_internal" ) 
	#define CAL_opcuaclient_createmonitoreditems_internal  opcuaclient_createmonitoreditems_internal
	#define CHK_opcuaclient_createmonitoreditems_internal  TRUE
	#define EXP_opcuaclient_createmonitoreditems_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_createmonitoreditems_internal", (RTS_UINTPTR)opcuaclient_createmonitoreditems_internal, 1, RTSITF_GET_SIGNATURE(0x78929EB6, 0x015C5817), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaclient_createmonitoreditems_internal  PFOPCUACLIENT_CREATEMONITOREDITEMS_INTERNAL_IEC pfopcuaclient_createmonitoreditems_internal;
	#define EXT_opcuaclient_createmonitoreditems_internal  extern PFOPCUACLIENT_CREATEMONITOREDITEMS_INTERNAL_IEC pfopcuaclient_createmonitoreditems_internal;
	#define GET_opcuaclient_createmonitoreditems_internal(fl)  s_pfCMGetAPI2( "opcuaclient_createmonitoreditems_internal", (RTS_VOID_FCTPTR *)&pfopcuaclient_createmonitoreditems_internal, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0x78929EB6, 0x015C5817), 0x03051000)
	#define CAL_opcuaclient_createmonitoreditems_internal  pfopcuaclient_createmonitoreditems_internal
	#define CHK_opcuaclient_createmonitoreditems_internal  (pfopcuaclient_createmonitoreditems_internal != NULL)
	#define EXP_opcuaclient_createmonitoreditems_internal   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_createmonitoreditems_internal", (RTS_UINTPTR)opcuaclient_createmonitoreditems_internal, 1, RTSITF_GET_SIGNATURE(0x78929EB6, 0x015C5817), 0x03051000) 
#endif


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

void CDECL CDECL_EXT opcuaclient_createsubscription_internal(opcuaclient_createsubscription_internal_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUACLIENT_CREATESUBSCRIPTION_INTERNAL_IEC) (opcuaclient_createsubscription_internal_struct *p);
#if defined(CMPOPCUACLIENT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUACLIENT_CREATESUBSCRIPTION_INTERNAL_NOTIMPLEMENTED)
	#define USE_opcuaclient_createsubscription_internal
	#define EXT_opcuaclient_createsubscription_internal
	#define GET_opcuaclient_createsubscription_internal(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaclient_createsubscription_internal(p0) 
	#define CHK_opcuaclient_createsubscription_internal  FALSE
	#define EXP_opcuaclient_createsubscription_internal  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaclient_createsubscription_internal
	#define EXT_opcuaclient_createsubscription_internal
	#define GET_opcuaclient_createsubscription_internal(fl)  CAL_CMGETAPI( "opcuaclient_createsubscription_internal" ) 
	#define CAL_opcuaclient_createsubscription_internal  opcuaclient_createsubscription_internal
	#define CHK_opcuaclient_createsubscription_internal  TRUE
	#define EXP_opcuaclient_createsubscription_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_createsubscription_internal", (RTS_UINTPTR)opcuaclient_createsubscription_internal, 1, RTSITF_GET_SIGNATURE(0x479BC219, 0x6B7DAD5C), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaclient_createsubscription_internal
	#define EXT_opcuaclient_createsubscription_internal
	#define GET_opcuaclient_createsubscription_internal(fl)  CAL_CMGETAPI( "opcuaclient_createsubscription_internal" ) 
	#define CAL_opcuaclient_createsubscription_internal  opcuaclient_createsubscription_internal
	#define CHK_opcuaclient_createsubscription_internal  TRUE
	#define EXP_opcuaclient_createsubscription_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_createsubscription_internal", (RTS_UINTPTR)opcuaclient_createsubscription_internal, 1, RTSITF_GET_SIGNATURE(0x479BC219, 0x6B7DAD5C), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClient_Implementationopcuaclient_createsubscription_internal
	#define EXT_CmpOPCUAClient_Implementationopcuaclient_createsubscription_internal
	#define GET_CmpOPCUAClient_Implementationopcuaclient_createsubscription_internal  ERR_OK
	#define CAL_CmpOPCUAClient_Implementationopcuaclient_createsubscription_internal  opcuaclient_createsubscription_internal
	#define CHK_CmpOPCUAClient_Implementationopcuaclient_createsubscription_internal  TRUE
	#define EXP_CmpOPCUAClient_Implementationopcuaclient_createsubscription_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_createsubscription_internal", (RTS_UINTPTR)opcuaclient_createsubscription_internal, 1, RTSITF_GET_SIGNATURE(0x479BC219, 0x6B7DAD5C), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaclient_createsubscription_internal
	#define EXT_opcuaclient_createsubscription_internal
	#define GET_opcuaclient_createsubscription_internal(fl)  CAL_CMGETAPI( "opcuaclient_createsubscription_internal" ) 
	#define CAL_opcuaclient_createsubscription_internal  opcuaclient_createsubscription_internal
	#define CHK_opcuaclient_createsubscription_internal  TRUE
	#define EXP_opcuaclient_createsubscription_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_createsubscription_internal", (RTS_UINTPTR)opcuaclient_createsubscription_internal, 1, RTSITF_GET_SIGNATURE(0x479BC219, 0x6B7DAD5C), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaclient_createsubscription_internal  PFOPCUACLIENT_CREATESUBSCRIPTION_INTERNAL_IEC pfopcuaclient_createsubscription_internal;
	#define EXT_opcuaclient_createsubscription_internal  extern PFOPCUACLIENT_CREATESUBSCRIPTION_INTERNAL_IEC pfopcuaclient_createsubscription_internal;
	#define GET_opcuaclient_createsubscription_internal(fl)  s_pfCMGetAPI2( "opcuaclient_createsubscription_internal", (RTS_VOID_FCTPTR *)&pfopcuaclient_createsubscription_internal, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0x479BC219, 0x6B7DAD5C), 0x03051000)
	#define CAL_opcuaclient_createsubscription_internal  pfopcuaclient_createsubscription_internal
	#define CHK_opcuaclient_createsubscription_internal  (pfopcuaclient_createsubscription_internal != NULL)
	#define EXP_opcuaclient_createsubscription_internal   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_createsubscription_internal", (RTS_UINTPTR)opcuaclient_createsubscription_internal, 1, RTSITF_GET_SIGNATURE(0x479BC219, 0x6B7DAD5C), 0x03051000) 
#endif


/**
 * Delete an OPC UA client. This will close all connections and cleanup 
 * all ressources used by this client instance.
 */
typedef struct tagopcuaclient_delete_struct
{
	RTS_IEC_HANDLE hClient;				/* VAR_INPUT */	/* Hanlde of the OPC UA client created with OPCUAClient_Create. */
	RTS_IEC_RESULT OPCUAClient_Delete;	/* VAR_OUTPUT */	
} opcuaclient_delete_struct;

void CDECL CDECL_EXT opcuaclient_delete(opcuaclient_delete_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUACLIENT_DELETE_IEC) (opcuaclient_delete_struct *p);
#if defined(CMPOPCUACLIENT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUACLIENT_DELETE_NOTIMPLEMENTED)
	#define USE_opcuaclient_delete
	#define EXT_opcuaclient_delete
	#define GET_opcuaclient_delete(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaclient_delete(p0) 
	#define CHK_opcuaclient_delete  FALSE
	#define EXP_opcuaclient_delete  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaclient_delete
	#define EXT_opcuaclient_delete
	#define GET_opcuaclient_delete(fl)  CAL_CMGETAPI( "opcuaclient_delete" ) 
	#define CAL_opcuaclient_delete  opcuaclient_delete
	#define CHK_opcuaclient_delete  TRUE
	#define EXP_opcuaclient_delete  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_delete", (RTS_UINTPTR)opcuaclient_delete, 1, 0xCEA47AB5, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaclient_delete
	#define EXT_opcuaclient_delete
	#define GET_opcuaclient_delete(fl)  CAL_CMGETAPI( "opcuaclient_delete" ) 
	#define CAL_opcuaclient_delete  opcuaclient_delete
	#define CHK_opcuaclient_delete  TRUE
	#define EXP_opcuaclient_delete  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_delete", (RTS_UINTPTR)opcuaclient_delete, 1, 0xCEA47AB5, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClient_Implementationopcuaclient_delete
	#define EXT_CmpOPCUAClient_Implementationopcuaclient_delete
	#define GET_CmpOPCUAClient_Implementationopcuaclient_delete  ERR_OK
	#define CAL_CmpOPCUAClient_Implementationopcuaclient_delete  opcuaclient_delete
	#define CHK_CmpOPCUAClient_Implementationopcuaclient_delete  TRUE
	#define EXP_CmpOPCUAClient_Implementationopcuaclient_delete  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_delete", (RTS_UINTPTR)opcuaclient_delete, 1, 0xCEA47AB5, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaclient_delete
	#define EXT_opcuaclient_delete
	#define GET_opcuaclient_delete(fl)  CAL_CMGETAPI( "opcuaclient_delete" ) 
	#define CAL_opcuaclient_delete  opcuaclient_delete
	#define CHK_opcuaclient_delete  TRUE
	#define EXP_opcuaclient_delete  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_delete", (RTS_UINTPTR)opcuaclient_delete, 1, 0xCEA47AB5, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaclient_delete  PFOPCUACLIENT_DELETE_IEC pfopcuaclient_delete;
	#define EXT_opcuaclient_delete  extern PFOPCUACLIENT_DELETE_IEC pfopcuaclient_delete;
	#define GET_opcuaclient_delete(fl)  s_pfCMGetAPI2( "opcuaclient_delete", (RTS_VOID_FCTPTR *)&pfopcuaclient_delete, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xCEA47AB5, 0x03051000)
	#define CAL_opcuaclient_delete  pfopcuaclient_delete
	#define CHK_opcuaclient_delete  (pfopcuaclient_delete != NULL)
	#define EXP_opcuaclient_delete   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_delete", (RTS_UINTPTR)opcuaclient_delete, 1, 0xCEA47AB5, 0x03051000) 
#endif


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

void CDECL CDECL_EXT opcuaclient_deletemonitoreditems(opcuaclient_deletemonitoreditems_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUACLIENT_DELETEMONITOREDITEMS_IEC) (opcuaclient_deletemonitoreditems_struct *p);
#if defined(CMPOPCUACLIENT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUACLIENT_DELETEMONITOREDITEMS_NOTIMPLEMENTED)
	#define USE_opcuaclient_deletemonitoreditems
	#define EXT_opcuaclient_deletemonitoreditems
	#define GET_opcuaclient_deletemonitoreditems(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaclient_deletemonitoreditems(p0) 
	#define CHK_opcuaclient_deletemonitoreditems  FALSE
	#define EXP_opcuaclient_deletemonitoreditems  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaclient_deletemonitoreditems
	#define EXT_opcuaclient_deletemonitoreditems
	#define GET_opcuaclient_deletemonitoreditems(fl)  CAL_CMGETAPI( "opcuaclient_deletemonitoreditems" ) 
	#define CAL_opcuaclient_deletemonitoreditems  opcuaclient_deletemonitoreditems
	#define CHK_opcuaclient_deletemonitoreditems  TRUE
	#define EXP_opcuaclient_deletemonitoreditems  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_deletemonitoreditems", (RTS_UINTPTR)opcuaclient_deletemonitoreditems, 1, 0x7D549257, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaclient_deletemonitoreditems
	#define EXT_opcuaclient_deletemonitoreditems
	#define GET_opcuaclient_deletemonitoreditems(fl)  CAL_CMGETAPI( "opcuaclient_deletemonitoreditems" ) 
	#define CAL_opcuaclient_deletemonitoreditems  opcuaclient_deletemonitoreditems
	#define CHK_opcuaclient_deletemonitoreditems  TRUE
	#define EXP_opcuaclient_deletemonitoreditems  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_deletemonitoreditems", (RTS_UINTPTR)opcuaclient_deletemonitoreditems, 1, 0x7D549257, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClient_Implementationopcuaclient_deletemonitoreditems
	#define EXT_CmpOPCUAClient_Implementationopcuaclient_deletemonitoreditems
	#define GET_CmpOPCUAClient_Implementationopcuaclient_deletemonitoreditems  ERR_OK
	#define CAL_CmpOPCUAClient_Implementationopcuaclient_deletemonitoreditems  opcuaclient_deletemonitoreditems
	#define CHK_CmpOPCUAClient_Implementationopcuaclient_deletemonitoreditems  TRUE
	#define EXP_CmpOPCUAClient_Implementationopcuaclient_deletemonitoreditems  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_deletemonitoreditems", (RTS_UINTPTR)opcuaclient_deletemonitoreditems, 1, 0x7D549257, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaclient_deletemonitoreditems
	#define EXT_opcuaclient_deletemonitoreditems
	#define GET_opcuaclient_deletemonitoreditems(fl)  CAL_CMGETAPI( "opcuaclient_deletemonitoreditems" ) 
	#define CAL_opcuaclient_deletemonitoreditems  opcuaclient_deletemonitoreditems
	#define CHK_opcuaclient_deletemonitoreditems  TRUE
	#define EXP_opcuaclient_deletemonitoreditems  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_deletemonitoreditems", (RTS_UINTPTR)opcuaclient_deletemonitoreditems, 1, 0x7D549257, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaclient_deletemonitoreditems  PFOPCUACLIENT_DELETEMONITOREDITEMS_IEC pfopcuaclient_deletemonitoreditems;
	#define EXT_opcuaclient_deletemonitoreditems  extern PFOPCUACLIENT_DELETEMONITOREDITEMS_IEC pfopcuaclient_deletemonitoreditems;
	#define GET_opcuaclient_deletemonitoreditems(fl)  s_pfCMGetAPI2( "opcuaclient_deletemonitoreditems", (RTS_VOID_FCTPTR *)&pfopcuaclient_deletemonitoreditems, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x7D549257, 0x03051000)
	#define CAL_opcuaclient_deletemonitoreditems  pfopcuaclient_deletemonitoreditems
	#define CHK_opcuaclient_deletemonitoreditems  (pfopcuaclient_deletemonitoreditems != NULL)
	#define EXP_opcuaclient_deletemonitoreditems   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_deletemonitoreditems", (RTS_UINTPTR)opcuaclient_deletemonitoreditems, 1, 0x7D549257, 0x03051000) 
#endif


/**
 * This function deletes a subscription and all assigned monitored items on the server.
 */
typedef struct tagopcuaclient_deletesubscription_struct
{
	RTS_IEC_HANDLE hSubscription;		/* VAR_INPUT */	/* Handle to the subscription to delete. */
	RTS_IEC_RESULT OPCUAClient_DeleteSubscription;	/* VAR_OUTPUT */	
} opcuaclient_deletesubscription_struct;

void CDECL CDECL_EXT opcuaclient_deletesubscription(opcuaclient_deletesubscription_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUACLIENT_DELETESUBSCRIPTION_IEC) (opcuaclient_deletesubscription_struct *p);
#if defined(CMPOPCUACLIENT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUACLIENT_DELETESUBSCRIPTION_NOTIMPLEMENTED)
	#define USE_opcuaclient_deletesubscription
	#define EXT_opcuaclient_deletesubscription
	#define GET_opcuaclient_deletesubscription(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaclient_deletesubscription(p0) 
	#define CHK_opcuaclient_deletesubscription  FALSE
	#define EXP_opcuaclient_deletesubscription  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaclient_deletesubscription
	#define EXT_opcuaclient_deletesubscription
	#define GET_opcuaclient_deletesubscription(fl)  CAL_CMGETAPI( "opcuaclient_deletesubscription" ) 
	#define CAL_opcuaclient_deletesubscription  opcuaclient_deletesubscription
	#define CHK_opcuaclient_deletesubscription  TRUE
	#define EXP_opcuaclient_deletesubscription  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_deletesubscription", (RTS_UINTPTR)opcuaclient_deletesubscription, 1, 0x8F3E26C1, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaclient_deletesubscription
	#define EXT_opcuaclient_deletesubscription
	#define GET_opcuaclient_deletesubscription(fl)  CAL_CMGETAPI( "opcuaclient_deletesubscription" ) 
	#define CAL_opcuaclient_deletesubscription  opcuaclient_deletesubscription
	#define CHK_opcuaclient_deletesubscription  TRUE
	#define EXP_opcuaclient_deletesubscription  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_deletesubscription", (RTS_UINTPTR)opcuaclient_deletesubscription, 1, 0x8F3E26C1, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClient_Implementationopcuaclient_deletesubscription
	#define EXT_CmpOPCUAClient_Implementationopcuaclient_deletesubscription
	#define GET_CmpOPCUAClient_Implementationopcuaclient_deletesubscription  ERR_OK
	#define CAL_CmpOPCUAClient_Implementationopcuaclient_deletesubscription  opcuaclient_deletesubscription
	#define CHK_CmpOPCUAClient_Implementationopcuaclient_deletesubscription  TRUE
	#define EXP_CmpOPCUAClient_Implementationopcuaclient_deletesubscription  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_deletesubscription", (RTS_UINTPTR)opcuaclient_deletesubscription, 1, 0x8F3E26C1, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaclient_deletesubscription
	#define EXT_opcuaclient_deletesubscription
	#define GET_opcuaclient_deletesubscription(fl)  CAL_CMGETAPI( "opcuaclient_deletesubscription" ) 
	#define CAL_opcuaclient_deletesubscription  opcuaclient_deletesubscription
	#define CHK_opcuaclient_deletesubscription  TRUE
	#define EXP_opcuaclient_deletesubscription  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_deletesubscription", (RTS_UINTPTR)opcuaclient_deletesubscription, 1, 0x8F3E26C1, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaclient_deletesubscription  PFOPCUACLIENT_DELETESUBSCRIPTION_IEC pfopcuaclient_deletesubscription;
	#define EXT_opcuaclient_deletesubscription  extern PFOPCUACLIENT_DELETESUBSCRIPTION_IEC pfopcuaclient_deletesubscription;
	#define GET_opcuaclient_deletesubscription(fl)  s_pfCMGetAPI2( "opcuaclient_deletesubscription", (RTS_VOID_FCTPTR *)&pfopcuaclient_deletesubscription, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x8F3E26C1, 0x03051000)
	#define CAL_opcuaclient_deletesubscription  pfopcuaclient_deletesubscription
	#define CHK_opcuaclient_deletesubscription  (pfopcuaclient_deletesubscription != NULL)
	#define EXP_opcuaclient_deletesubscription   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_deletesubscription", (RTS_UINTPTR)opcuaclient_deletesubscription, 1, 0x8F3E26C1, 0x03051000) 
#endif


/**
 * Disconnect the OPC UA client. All ressources dedicated to this session will be cleand up.
 */
typedef struct tagopcuaclient_disconnect_struct
{
	RTS_IEC_HANDLE hConnection;			/* VAR_INPUT */	/* Handle to the connection to disconnect. */
	RTS_IEC_RESULT OPCUAClient_Disconnect;	/* VAR_OUTPUT */	
} opcuaclient_disconnect_struct;

void CDECL CDECL_EXT opcuaclient_disconnect(opcuaclient_disconnect_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUACLIENT_DISCONNECT_IEC) (opcuaclient_disconnect_struct *p);
#if defined(CMPOPCUACLIENT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUACLIENT_DISCONNECT_NOTIMPLEMENTED)
	#define USE_opcuaclient_disconnect
	#define EXT_opcuaclient_disconnect
	#define GET_opcuaclient_disconnect(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaclient_disconnect(p0) 
	#define CHK_opcuaclient_disconnect  FALSE
	#define EXP_opcuaclient_disconnect  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaclient_disconnect
	#define EXT_opcuaclient_disconnect
	#define GET_opcuaclient_disconnect(fl)  CAL_CMGETAPI( "opcuaclient_disconnect" ) 
	#define CAL_opcuaclient_disconnect  opcuaclient_disconnect
	#define CHK_opcuaclient_disconnect  TRUE
	#define EXP_opcuaclient_disconnect  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_disconnect", (RTS_UINTPTR)opcuaclient_disconnect, 1, 0x7D055791, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaclient_disconnect
	#define EXT_opcuaclient_disconnect
	#define GET_opcuaclient_disconnect(fl)  CAL_CMGETAPI( "opcuaclient_disconnect" ) 
	#define CAL_opcuaclient_disconnect  opcuaclient_disconnect
	#define CHK_opcuaclient_disconnect  TRUE
	#define EXP_opcuaclient_disconnect  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_disconnect", (RTS_UINTPTR)opcuaclient_disconnect, 1, 0x7D055791, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClient_Implementationopcuaclient_disconnect
	#define EXT_CmpOPCUAClient_Implementationopcuaclient_disconnect
	#define GET_CmpOPCUAClient_Implementationopcuaclient_disconnect  ERR_OK
	#define CAL_CmpOPCUAClient_Implementationopcuaclient_disconnect  opcuaclient_disconnect
	#define CHK_CmpOPCUAClient_Implementationopcuaclient_disconnect  TRUE
	#define EXP_CmpOPCUAClient_Implementationopcuaclient_disconnect  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_disconnect", (RTS_UINTPTR)opcuaclient_disconnect, 1, 0x7D055791, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaclient_disconnect
	#define EXT_opcuaclient_disconnect
	#define GET_opcuaclient_disconnect(fl)  CAL_CMGETAPI( "opcuaclient_disconnect" ) 
	#define CAL_opcuaclient_disconnect  opcuaclient_disconnect
	#define CHK_opcuaclient_disconnect  TRUE
	#define EXP_opcuaclient_disconnect  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_disconnect", (RTS_UINTPTR)opcuaclient_disconnect, 1, 0x7D055791, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaclient_disconnect  PFOPCUACLIENT_DISCONNECT_IEC pfopcuaclient_disconnect;
	#define EXT_opcuaclient_disconnect  extern PFOPCUACLIENT_DISCONNECT_IEC pfopcuaclient_disconnect;
	#define GET_opcuaclient_disconnect(fl)  s_pfCMGetAPI2( "opcuaclient_disconnect", (RTS_VOID_FCTPTR *)&pfopcuaclient_disconnect, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x7D055791, 0x03051000)
	#define CAL_opcuaclient_disconnect  pfopcuaclient_disconnect
	#define CHK_opcuaclient_disconnect  (pfopcuaclient_disconnect != NULL)
	#define EXP_opcuaclient_disconnect   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_disconnect", (RTS_UINTPTR)opcuaclient_disconnect, 1, 0x7D055791, 0x03051000) 
#endif


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

void CDECL CDECL_EXT opcuaclient_extensionobjectattachreadonly(opcuaclient_extensionobjectattachreadonly_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUACLIENT_EXTENSIONOBJECTATTACHREADONLY_IEC) (opcuaclient_extensionobjectattachreadonly_struct *p);
#if defined(CMPOPCUACLIENT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUACLIENT_EXTENSIONOBJECTATTACHREADONLY_NOTIMPLEMENTED)
	#define USE_opcuaclient_extensionobjectattachreadonly
	#define EXT_opcuaclient_extensionobjectattachreadonly
	#define GET_opcuaclient_extensionobjectattachreadonly(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaclient_extensionobjectattachreadonly(p0) 
	#define CHK_opcuaclient_extensionobjectattachreadonly  FALSE
	#define EXP_opcuaclient_extensionobjectattachreadonly  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaclient_extensionobjectattachreadonly
	#define EXT_opcuaclient_extensionobjectattachreadonly
	#define GET_opcuaclient_extensionobjectattachreadonly(fl)  CAL_CMGETAPI( "opcuaclient_extensionobjectattachreadonly" ) 
	#define CAL_opcuaclient_extensionobjectattachreadonly  opcuaclient_extensionobjectattachreadonly
	#define CHK_opcuaclient_extensionobjectattachreadonly  TRUE
	#define EXP_opcuaclient_extensionobjectattachreadonly  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_extensionobjectattachreadonly", (RTS_UINTPTR)opcuaclient_extensionobjectattachreadonly, 1, 0x18A06F69, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaclient_extensionobjectattachreadonly
	#define EXT_opcuaclient_extensionobjectattachreadonly
	#define GET_opcuaclient_extensionobjectattachreadonly(fl)  CAL_CMGETAPI( "opcuaclient_extensionobjectattachreadonly" ) 
	#define CAL_opcuaclient_extensionobjectattachreadonly  opcuaclient_extensionobjectattachreadonly
	#define CHK_opcuaclient_extensionobjectattachreadonly  TRUE
	#define EXP_opcuaclient_extensionobjectattachreadonly  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_extensionobjectattachreadonly", (RTS_UINTPTR)opcuaclient_extensionobjectattachreadonly, 1, 0x18A06F69, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClient_Implementationopcuaclient_extensionobjectattachreadonly
	#define EXT_CmpOPCUAClient_Implementationopcuaclient_extensionobjectattachreadonly
	#define GET_CmpOPCUAClient_Implementationopcuaclient_extensionobjectattachreadonly  ERR_OK
	#define CAL_CmpOPCUAClient_Implementationopcuaclient_extensionobjectattachreadonly  opcuaclient_extensionobjectattachreadonly
	#define CHK_CmpOPCUAClient_Implementationopcuaclient_extensionobjectattachreadonly  TRUE
	#define EXP_CmpOPCUAClient_Implementationopcuaclient_extensionobjectattachreadonly  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_extensionobjectattachreadonly", (RTS_UINTPTR)opcuaclient_extensionobjectattachreadonly, 1, 0x18A06F69, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaclient_extensionobjectattachreadonly
	#define EXT_opcuaclient_extensionobjectattachreadonly
	#define GET_opcuaclient_extensionobjectattachreadonly(fl)  CAL_CMGETAPI( "opcuaclient_extensionobjectattachreadonly" ) 
	#define CAL_opcuaclient_extensionobjectattachreadonly  opcuaclient_extensionobjectattachreadonly
	#define CHK_opcuaclient_extensionobjectattachreadonly  TRUE
	#define EXP_opcuaclient_extensionobjectattachreadonly  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_extensionobjectattachreadonly", (RTS_UINTPTR)opcuaclient_extensionobjectattachreadonly, 1, 0x18A06F69, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaclient_extensionobjectattachreadonly  PFOPCUACLIENT_EXTENSIONOBJECTATTACHREADONLY_IEC pfopcuaclient_extensionobjectattachreadonly;
	#define EXT_opcuaclient_extensionobjectattachreadonly  extern PFOPCUACLIENT_EXTENSIONOBJECTATTACHREADONLY_IEC pfopcuaclient_extensionobjectattachreadonly;
	#define GET_opcuaclient_extensionobjectattachreadonly(fl)  s_pfCMGetAPI2( "opcuaclient_extensionobjectattachreadonly", (RTS_VOID_FCTPTR *)&pfopcuaclient_extensionobjectattachreadonly, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x18A06F69, 0x03051000)
	#define CAL_opcuaclient_extensionobjectattachreadonly  pfopcuaclient_extensionobjectattachreadonly
	#define CHK_opcuaclient_extensionobjectattachreadonly  (pfopcuaclient_extensionobjectattachreadonly != NULL)
	#define EXP_opcuaclient_extensionobjectattachreadonly   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_extensionobjectattachreadonly", (RTS_UINTPTR)opcuaclient_extensionobjectattachreadonly, 1, 0x18A06F69, 0x03051000) 
#endif


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

void CDECL CDECL_EXT opcuaclient_findservers_internal(opcuaclient_findservers_internal_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUACLIENT_FINDSERVERS_INTERNAL_IEC) (opcuaclient_findservers_internal_struct *p);
#if defined(CMPOPCUACLIENT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUACLIENT_FINDSERVERS_INTERNAL_NOTIMPLEMENTED)
	#define USE_opcuaclient_findservers_internal
	#define EXT_opcuaclient_findservers_internal
	#define GET_opcuaclient_findservers_internal(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaclient_findservers_internal(p0) 
	#define CHK_opcuaclient_findservers_internal  FALSE
	#define EXP_opcuaclient_findservers_internal  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaclient_findservers_internal
	#define EXT_opcuaclient_findservers_internal
	#define GET_opcuaclient_findservers_internal(fl)  CAL_CMGETAPI( "opcuaclient_findservers_internal" ) 
	#define CAL_opcuaclient_findservers_internal  opcuaclient_findservers_internal
	#define CHK_opcuaclient_findservers_internal  TRUE
	#define EXP_opcuaclient_findservers_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_findservers_internal", (RTS_UINTPTR)opcuaclient_findservers_internal, 1, RTSITF_GET_SIGNATURE(0x1DA83372, 0xAB40D53F), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaclient_findservers_internal
	#define EXT_opcuaclient_findservers_internal
	#define GET_opcuaclient_findservers_internal(fl)  CAL_CMGETAPI( "opcuaclient_findservers_internal" ) 
	#define CAL_opcuaclient_findservers_internal  opcuaclient_findservers_internal
	#define CHK_opcuaclient_findservers_internal  TRUE
	#define EXP_opcuaclient_findservers_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_findservers_internal", (RTS_UINTPTR)opcuaclient_findservers_internal, 1, RTSITF_GET_SIGNATURE(0x1DA83372, 0xAB40D53F), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClient_Implementationopcuaclient_findservers_internal
	#define EXT_CmpOPCUAClient_Implementationopcuaclient_findservers_internal
	#define GET_CmpOPCUAClient_Implementationopcuaclient_findservers_internal  ERR_OK
	#define CAL_CmpOPCUAClient_Implementationopcuaclient_findservers_internal  opcuaclient_findservers_internal
	#define CHK_CmpOPCUAClient_Implementationopcuaclient_findservers_internal  TRUE
	#define EXP_CmpOPCUAClient_Implementationopcuaclient_findservers_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_findservers_internal", (RTS_UINTPTR)opcuaclient_findservers_internal, 1, RTSITF_GET_SIGNATURE(0x1DA83372, 0xAB40D53F), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaclient_findservers_internal
	#define EXT_opcuaclient_findservers_internal
	#define GET_opcuaclient_findservers_internal(fl)  CAL_CMGETAPI( "opcuaclient_findservers_internal" ) 
	#define CAL_opcuaclient_findservers_internal  opcuaclient_findservers_internal
	#define CHK_opcuaclient_findservers_internal  TRUE
	#define EXP_opcuaclient_findservers_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_findservers_internal", (RTS_UINTPTR)opcuaclient_findservers_internal, 1, RTSITF_GET_SIGNATURE(0x1DA83372, 0xAB40D53F), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaclient_findservers_internal  PFOPCUACLIENT_FINDSERVERS_INTERNAL_IEC pfopcuaclient_findservers_internal;
	#define EXT_opcuaclient_findservers_internal  extern PFOPCUACLIENT_FINDSERVERS_INTERNAL_IEC pfopcuaclient_findservers_internal;
	#define GET_opcuaclient_findservers_internal(fl)  s_pfCMGetAPI2( "opcuaclient_findservers_internal", (RTS_VOID_FCTPTR *)&pfopcuaclient_findservers_internal, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0x1DA83372, 0xAB40D53F), 0x03051000)
	#define CAL_opcuaclient_findservers_internal  pfopcuaclient_findservers_internal
	#define CHK_opcuaclient_findservers_internal  (pfopcuaclient_findservers_internal != NULL)
	#define EXP_opcuaclient_findservers_internal   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_findservers_internal", (RTS_UINTPTR)opcuaclient_findservers_internal, 1, RTSITF_GET_SIGNATURE(0x1DA83372, 0xAB40D53F), 0x03051000) 
#endif


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

void CDECL CDECL_EXT opcuaclient_findserversonnetwork_internal(opcuaclient_findserversonnetwork_internal_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUACLIENT_FINDSERVERSONNETWORK_INTERNAL_IEC) (opcuaclient_findserversonnetwork_internal_struct *p);
#if defined(CMPOPCUACLIENT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUACLIENT_FINDSERVERSONNETWORK_INTERNAL_NOTIMPLEMENTED)
	#define USE_opcuaclient_findserversonnetwork_internal
	#define EXT_opcuaclient_findserversonnetwork_internal
	#define GET_opcuaclient_findserversonnetwork_internal(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaclient_findserversonnetwork_internal(p0) 
	#define CHK_opcuaclient_findserversonnetwork_internal  FALSE
	#define EXP_opcuaclient_findserversonnetwork_internal  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaclient_findserversonnetwork_internal
	#define EXT_opcuaclient_findserversonnetwork_internal
	#define GET_opcuaclient_findserversonnetwork_internal(fl)  CAL_CMGETAPI( "opcuaclient_findserversonnetwork_internal" ) 
	#define CAL_opcuaclient_findserversonnetwork_internal  opcuaclient_findserversonnetwork_internal
	#define CHK_opcuaclient_findserversonnetwork_internal  TRUE
	#define EXP_opcuaclient_findserversonnetwork_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_findserversonnetwork_internal", (RTS_UINTPTR)opcuaclient_findserversonnetwork_internal, 1, RTSITF_GET_SIGNATURE(0x71C0561A, 0x246AA4A9), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaclient_findserversonnetwork_internal
	#define EXT_opcuaclient_findserversonnetwork_internal
	#define GET_opcuaclient_findserversonnetwork_internal(fl)  CAL_CMGETAPI( "opcuaclient_findserversonnetwork_internal" ) 
	#define CAL_opcuaclient_findserversonnetwork_internal  opcuaclient_findserversonnetwork_internal
	#define CHK_opcuaclient_findserversonnetwork_internal  TRUE
	#define EXP_opcuaclient_findserversonnetwork_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_findserversonnetwork_internal", (RTS_UINTPTR)opcuaclient_findserversonnetwork_internal, 1, RTSITF_GET_SIGNATURE(0x71C0561A, 0x246AA4A9), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClient_Implementationopcuaclient_findserversonnetwork_internal
	#define EXT_CmpOPCUAClient_Implementationopcuaclient_findserversonnetwork_internal
	#define GET_CmpOPCUAClient_Implementationopcuaclient_findserversonnetwork_internal  ERR_OK
	#define CAL_CmpOPCUAClient_Implementationopcuaclient_findserversonnetwork_internal  opcuaclient_findserversonnetwork_internal
	#define CHK_CmpOPCUAClient_Implementationopcuaclient_findserversonnetwork_internal  TRUE
	#define EXP_CmpOPCUAClient_Implementationopcuaclient_findserversonnetwork_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_findserversonnetwork_internal", (RTS_UINTPTR)opcuaclient_findserversonnetwork_internal, 1, RTSITF_GET_SIGNATURE(0x71C0561A, 0x246AA4A9), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaclient_findserversonnetwork_internal
	#define EXT_opcuaclient_findserversonnetwork_internal
	#define GET_opcuaclient_findserversonnetwork_internal(fl)  CAL_CMGETAPI( "opcuaclient_findserversonnetwork_internal" ) 
	#define CAL_opcuaclient_findserversonnetwork_internal  opcuaclient_findserversonnetwork_internal
	#define CHK_opcuaclient_findserversonnetwork_internal  TRUE
	#define EXP_opcuaclient_findserversonnetwork_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_findserversonnetwork_internal", (RTS_UINTPTR)opcuaclient_findserversonnetwork_internal, 1, RTSITF_GET_SIGNATURE(0x71C0561A, 0x246AA4A9), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaclient_findserversonnetwork_internal  PFOPCUACLIENT_FINDSERVERSONNETWORK_INTERNAL_IEC pfopcuaclient_findserversonnetwork_internal;
	#define EXT_opcuaclient_findserversonnetwork_internal  extern PFOPCUACLIENT_FINDSERVERSONNETWORK_INTERNAL_IEC pfopcuaclient_findserversonnetwork_internal;
	#define GET_opcuaclient_findserversonnetwork_internal(fl)  s_pfCMGetAPI2( "opcuaclient_findserversonnetwork_internal", (RTS_VOID_FCTPTR *)&pfopcuaclient_findserversonnetwork_internal, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0x71C0561A, 0x246AA4A9), 0x03051000)
	#define CAL_opcuaclient_findserversonnetwork_internal  pfopcuaclient_findserversonnetwork_internal
	#define CHK_opcuaclient_findserversonnetwork_internal  (pfopcuaclient_findserversonnetwork_internal != NULL)
	#define EXP_opcuaclient_findserversonnetwork_internal   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_findserversonnetwork_internal", (RTS_UINTPTR)opcuaclient_findserversonnetwork_internal, 1, RTSITF_GET_SIGNATURE(0x71C0561A, 0x246AA4A9), 0x03051000) 
#endif


/**
 * Retrieve the configuration of specific OPC UA client.
 */
typedef struct tagopcuaclient_getconfig_struct
{
	RTS_IEC_HANDLE hClient;				/* VAR_INPUT */	/* Handle to the OPC UA client. */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Result of the operation. */
	OpcUa_ApplicationDescription *OPCUAClient_GetConfig;	/* VAR_OUTPUT */	
} opcuaclient_getconfig_struct;

void CDECL CDECL_EXT opcuaclient_getconfig(opcuaclient_getconfig_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUACLIENT_GETCONFIG_IEC) (opcuaclient_getconfig_struct *p);
#if defined(CMPOPCUACLIENT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUACLIENT_GETCONFIG_NOTIMPLEMENTED)
	#define USE_opcuaclient_getconfig
	#define EXT_opcuaclient_getconfig
	#define GET_opcuaclient_getconfig(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaclient_getconfig(p0) 
	#define CHK_opcuaclient_getconfig  FALSE
	#define EXP_opcuaclient_getconfig  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaclient_getconfig
	#define EXT_opcuaclient_getconfig
	#define GET_opcuaclient_getconfig(fl)  CAL_CMGETAPI( "opcuaclient_getconfig" ) 
	#define CAL_opcuaclient_getconfig  opcuaclient_getconfig
	#define CHK_opcuaclient_getconfig  TRUE
	#define EXP_opcuaclient_getconfig  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_getconfig", (RTS_UINTPTR)opcuaclient_getconfig, 1, 0xDF886940, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaclient_getconfig
	#define EXT_opcuaclient_getconfig
	#define GET_opcuaclient_getconfig(fl)  CAL_CMGETAPI( "opcuaclient_getconfig" ) 
	#define CAL_opcuaclient_getconfig  opcuaclient_getconfig
	#define CHK_opcuaclient_getconfig  TRUE
	#define EXP_opcuaclient_getconfig  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_getconfig", (RTS_UINTPTR)opcuaclient_getconfig, 1, 0xDF886940, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClient_Implementationopcuaclient_getconfig
	#define EXT_CmpOPCUAClient_Implementationopcuaclient_getconfig
	#define GET_CmpOPCUAClient_Implementationopcuaclient_getconfig  ERR_OK
	#define CAL_CmpOPCUAClient_Implementationopcuaclient_getconfig  opcuaclient_getconfig
	#define CHK_CmpOPCUAClient_Implementationopcuaclient_getconfig  TRUE
	#define EXP_CmpOPCUAClient_Implementationopcuaclient_getconfig  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_getconfig", (RTS_UINTPTR)opcuaclient_getconfig, 1, 0xDF886940, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaclient_getconfig
	#define EXT_opcuaclient_getconfig
	#define GET_opcuaclient_getconfig(fl)  CAL_CMGETAPI( "opcuaclient_getconfig" ) 
	#define CAL_opcuaclient_getconfig  opcuaclient_getconfig
	#define CHK_opcuaclient_getconfig  TRUE
	#define EXP_opcuaclient_getconfig  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_getconfig", (RTS_UINTPTR)opcuaclient_getconfig, 1, 0xDF886940, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaclient_getconfig  PFOPCUACLIENT_GETCONFIG_IEC pfopcuaclient_getconfig;
	#define EXT_opcuaclient_getconfig  extern PFOPCUACLIENT_GETCONFIG_IEC pfopcuaclient_getconfig;
	#define GET_opcuaclient_getconfig(fl)  s_pfCMGetAPI2( "opcuaclient_getconfig", (RTS_VOID_FCTPTR *)&pfopcuaclient_getconfig, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xDF886940, 0x03051000)
	#define CAL_opcuaclient_getconfig  pfopcuaclient_getconfig
	#define CHK_opcuaclient_getconfig  (pfopcuaclient_getconfig != NULL)
	#define EXP_opcuaclient_getconfig   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_getconfig", (RTS_UINTPTR)opcuaclient_getconfig, 1, 0xDF886940, 0x03051000) 
#endif


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

void CDECL CDECL_EXT opcuaclient_getendpoints_internal(opcuaclient_getendpoints_internal_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUACLIENT_GETENDPOINTS_INTERNAL_IEC) (opcuaclient_getendpoints_internal_struct *p);
#if defined(CMPOPCUACLIENT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUACLIENT_GETENDPOINTS_INTERNAL_NOTIMPLEMENTED)
	#define USE_opcuaclient_getendpoints_internal
	#define EXT_opcuaclient_getendpoints_internal
	#define GET_opcuaclient_getendpoints_internal(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaclient_getendpoints_internal(p0) 
	#define CHK_opcuaclient_getendpoints_internal  FALSE
	#define EXP_opcuaclient_getendpoints_internal  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaclient_getendpoints_internal
	#define EXT_opcuaclient_getendpoints_internal
	#define GET_opcuaclient_getendpoints_internal(fl)  CAL_CMGETAPI( "opcuaclient_getendpoints_internal" ) 
	#define CAL_opcuaclient_getendpoints_internal  opcuaclient_getendpoints_internal
	#define CHK_opcuaclient_getendpoints_internal  TRUE
	#define EXP_opcuaclient_getendpoints_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_getendpoints_internal", (RTS_UINTPTR)opcuaclient_getendpoints_internal, 1, RTSITF_GET_SIGNATURE(0x88FF5C72, 0xE23AC925), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaclient_getendpoints_internal
	#define EXT_opcuaclient_getendpoints_internal
	#define GET_opcuaclient_getendpoints_internal(fl)  CAL_CMGETAPI( "opcuaclient_getendpoints_internal" ) 
	#define CAL_opcuaclient_getendpoints_internal  opcuaclient_getendpoints_internal
	#define CHK_opcuaclient_getendpoints_internal  TRUE
	#define EXP_opcuaclient_getendpoints_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_getendpoints_internal", (RTS_UINTPTR)opcuaclient_getendpoints_internal, 1, RTSITF_GET_SIGNATURE(0x88FF5C72, 0xE23AC925), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClient_Implementationopcuaclient_getendpoints_internal
	#define EXT_CmpOPCUAClient_Implementationopcuaclient_getendpoints_internal
	#define GET_CmpOPCUAClient_Implementationopcuaclient_getendpoints_internal  ERR_OK
	#define CAL_CmpOPCUAClient_Implementationopcuaclient_getendpoints_internal  opcuaclient_getendpoints_internal
	#define CHK_CmpOPCUAClient_Implementationopcuaclient_getendpoints_internal  TRUE
	#define EXP_CmpOPCUAClient_Implementationopcuaclient_getendpoints_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_getendpoints_internal", (RTS_UINTPTR)opcuaclient_getendpoints_internal, 1, RTSITF_GET_SIGNATURE(0x88FF5C72, 0xE23AC925), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaclient_getendpoints_internal
	#define EXT_opcuaclient_getendpoints_internal
	#define GET_opcuaclient_getendpoints_internal(fl)  CAL_CMGETAPI( "opcuaclient_getendpoints_internal" ) 
	#define CAL_opcuaclient_getendpoints_internal  opcuaclient_getendpoints_internal
	#define CHK_opcuaclient_getendpoints_internal  TRUE
	#define EXP_opcuaclient_getendpoints_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_getendpoints_internal", (RTS_UINTPTR)opcuaclient_getendpoints_internal, 1, RTSITF_GET_SIGNATURE(0x88FF5C72, 0xE23AC925), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaclient_getendpoints_internal  PFOPCUACLIENT_GETENDPOINTS_INTERNAL_IEC pfopcuaclient_getendpoints_internal;
	#define EXT_opcuaclient_getendpoints_internal  extern PFOPCUACLIENT_GETENDPOINTS_INTERNAL_IEC pfopcuaclient_getendpoints_internal;
	#define GET_opcuaclient_getendpoints_internal(fl)  s_pfCMGetAPI2( "opcuaclient_getendpoints_internal", (RTS_VOID_FCTPTR *)&pfopcuaclient_getendpoints_internal, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0x88FF5C72, 0xE23AC925), 0x03051000)
	#define CAL_opcuaclient_getendpoints_internal  pfopcuaclient_getendpoints_internal
	#define CHK_opcuaclient_getendpoints_internal  (pfopcuaclient_getendpoints_internal != NULL)
	#define EXP_opcuaclient_getendpoints_internal   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_getendpoints_internal", (RTS_UINTPTR)opcuaclient_getendpoints_internal, 1, RTSITF_GET_SIGNATURE(0x88FF5C72, 0xE23AC925), 0x03051000) 
#endif


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

void CDECL CDECL_EXT opcuaclient_modifymonitoreditems_internal(opcuaclient_modifymonitoreditems_internal_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUACLIENT_MODIFYMONITOREDITEMS_INTERNAL_IEC) (opcuaclient_modifymonitoreditems_internal_struct *p);
#if defined(CMPOPCUACLIENT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUACLIENT_MODIFYMONITOREDITEMS_INTERNAL_NOTIMPLEMENTED)
	#define USE_opcuaclient_modifymonitoreditems_internal
	#define EXT_opcuaclient_modifymonitoreditems_internal
	#define GET_opcuaclient_modifymonitoreditems_internal(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaclient_modifymonitoreditems_internal(p0) 
	#define CHK_opcuaclient_modifymonitoreditems_internal  FALSE
	#define EXP_opcuaclient_modifymonitoreditems_internal  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaclient_modifymonitoreditems_internal
	#define EXT_opcuaclient_modifymonitoreditems_internal
	#define GET_opcuaclient_modifymonitoreditems_internal(fl)  CAL_CMGETAPI( "opcuaclient_modifymonitoreditems_internal" ) 
	#define CAL_opcuaclient_modifymonitoreditems_internal  opcuaclient_modifymonitoreditems_internal
	#define CHK_opcuaclient_modifymonitoreditems_internal  TRUE
	#define EXP_opcuaclient_modifymonitoreditems_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_modifymonitoreditems_internal", (RTS_UINTPTR)opcuaclient_modifymonitoreditems_internal, 1, RTSITF_GET_SIGNATURE(0xF325D610, 0x971FB0CA), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaclient_modifymonitoreditems_internal
	#define EXT_opcuaclient_modifymonitoreditems_internal
	#define GET_opcuaclient_modifymonitoreditems_internal(fl)  CAL_CMGETAPI( "opcuaclient_modifymonitoreditems_internal" ) 
	#define CAL_opcuaclient_modifymonitoreditems_internal  opcuaclient_modifymonitoreditems_internal
	#define CHK_opcuaclient_modifymonitoreditems_internal  TRUE
	#define EXP_opcuaclient_modifymonitoreditems_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_modifymonitoreditems_internal", (RTS_UINTPTR)opcuaclient_modifymonitoreditems_internal, 1, RTSITF_GET_SIGNATURE(0xF325D610, 0x971FB0CA), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClient_Implementationopcuaclient_modifymonitoreditems_internal
	#define EXT_CmpOPCUAClient_Implementationopcuaclient_modifymonitoreditems_internal
	#define GET_CmpOPCUAClient_Implementationopcuaclient_modifymonitoreditems_internal  ERR_OK
	#define CAL_CmpOPCUAClient_Implementationopcuaclient_modifymonitoreditems_internal  opcuaclient_modifymonitoreditems_internal
	#define CHK_CmpOPCUAClient_Implementationopcuaclient_modifymonitoreditems_internal  TRUE
	#define EXP_CmpOPCUAClient_Implementationopcuaclient_modifymonitoreditems_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_modifymonitoreditems_internal", (RTS_UINTPTR)opcuaclient_modifymonitoreditems_internal, 1, RTSITF_GET_SIGNATURE(0xF325D610, 0x971FB0CA), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaclient_modifymonitoreditems_internal
	#define EXT_opcuaclient_modifymonitoreditems_internal
	#define GET_opcuaclient_modifymonitoreditems_internal(fl)  CAL_CMGETAPI( "opcuaclient_modifymonitoreditems_internal" ) 
	#define CAL_opcuaclient_modifymonitoreditems_internal  opcuaclient_modifymonitoreditems_internal
	#define CHK_opcuaclient_modifymonitoreditems_internal  TRUE
	#define EXP_opcuaclient_modifymonitoreditems_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_modifymonitoreditems_internal", (RTS_UINTPTR)opcuaclient_modifymonitoreditems_internal, 1, RTSITF_GET_SIGNATURE(0xF325D610, 0x971FB0CA), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaclient_modifymonitoreditems_internal  PFOPCUACLIENT_MODIFYMONITOREDITEMS_INTERNAL_IEC pfopcuaclient_modifymonitoreditems_internal;
	#define EXT_opcuaclient_modifymonitoreditems_internal  extern PFOPCUACLIENT_MODIFYMONITOREDITEMS_INTERNAL_IEC pfopcuaclient_modifymonitoreditems_internal;
	#define GET_opcuaclient_modifymonitoreditems_internal(fl)  s_pfCMGetAPI2( "opcuaclient_modifymonitoreditems_internal", (RTS_VOID_FCTPTR *)&pfopcuaclient_modifymonitoreditems_internal, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0xF325D610, 0x971FB0CA), 0x03051000)
	#define CAL_opcuaclient_modifymonitoreditems_internal  pfopcuaclient_modifymonitoreditems_internal
	#define CHK_opcuaclient_modifymonitoreditems_internal  (pfopcuaclient_modifymonitoreditems_internal != NULL)
	#define EXP_opcuaclient_modifymonitoreditems_internal   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_modifymonitoreditems_internal", (RTS_UINTPTR)opcuaclient_modifymonitoreditems_internal, 1, RTSITF_GET_SIGNATURE(0xF325D610, 0x971FB0CA), 0x03051000) 
#endif


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

void CDECL CDECL_EXT opcuaclient_modifysubscription_internal(opcuaclient_modifysubscription_internal_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUACLIENT_MODIFYSUBSCRIPTION_INTERNAL_IEC) (opcuaclient_modifysubscription_internal_struct *p);
#if defined(CMPOPCUACLIENT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUACLIENT_MODIFYSUBSCRIPTION_INTERNAL_NOTIMPLEMENTED)
	#define USE_opcuaclient_modifysubscription_internal
	#define EXT_opcuaclient_modifysubscription_internal
	#define GET_opcuaclient_modifysubscription_internal(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaclient_modifysubscription_internal(p0) 
	#define CHK_opcuaclient_modifysubscription_internal  FALSE
	#define EXP_opcuaclient_modifysubscription_internal  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaclient_modifysubscription_internal
	#define EXT_opcuaclient_modifysubscription_internal
	#define GET_opcuaclient_modifysubscription_internal(fl)  CAL_CMGETAPI( "opcuaclient_modifysubscription_internal" ) 
	#define CAL_opcuaclient_modifysubscription_internal  opcuaclient_modifysubscription_internal
	#define CHK_opcuaclient_modifysubscription_internal  TRUE
	#define EXP_opcuaclient_modifysubscription_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_modifysubscription_internal", (RTS_UINTPTR)opcuaclient_modifysubscription_internal, 1, 0xFD8D1AF6, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaclient_modifysubscription_internal
	#define EXT_opcuaclient_modifysubscription_internal
	#define GET_opcuaclient_modifysubscription_internal(fl)  CAL_CMGETAPI( "opcuaclient_modifysubscription_internal" ) 
	#define CAL_opcuaclient_modifysubscription_internal  opcuaclient_modifysubscription_internal
	#define CHK_opcuaclient_modifysubscription_internal  TRUE
	#define EXP_opcuaclient_modifysubscription_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_modifysubscription_internal", (RTS_UINTPTR)opcuaclient_modifysubscription_internal, 1, 0xFD8D1AF6, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClient_Implementationopcuaclient_modifysubscription_internal
	#define EXT_CmpOPCUAClient_Implementationopcuaclient_modifysubscription_internal
	#define GET_CmpOPCUAClient_Implementationopcuaclient_modifysubscription_internal  ERR_OK
	#define CAL_CmpOPCUAClient_Implementationopcuaclient_modifysubscription_internal  opcuaclient_modifysubscription_internal
	#define CHK_CmpOPCUAClient_Implementationopcuaclient_modifysubscription_internal  TRUE
	#define EXP_CmpOPCUAClient_Implementationopcuaclient_modifysubscription_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_modifysubscription_internal", (RTS_UINTPTR)opcuaclient_modifysubscription_internal, 1, 0xFD8D1AF6, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaclient_modifysubscription_internal
	#define EXT_opcuaclient_modifysubscription_internal
	#define GET_opcuaclient_modifysubscription_internal(fl)  CAL_CMGETAPI( "opcuaclient_modifysubscription_internal" ) 
	#define CAL_opcuaclient_modifysubscription_internal  opcuaclient_modifysubscription_internal
	#define CHK_opcuaclient_modifysubscription_internal  TRUE
	#define EXP_opcuaclient_modifysubscription_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_modifysubscription_internal", (RTS_UINTPTR)opcuaclient_modifysubscription_internal, 1, 0xFD8D1AF6, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaclient_modifysubscription_internal  PFOPCUACLIENT_MODIFYSUBSCRIPTION_INTERNAL_IEC pfopcuaclient_modifysubscription_internal;
	#define EXT_opcuaclient_modifysubscription_internal  extern PFOPCUACLIENT_MODIFYSUBSCRIPTION_INTERNAL_IEC pfopcuaclient_modifysubscription_internal;
	#define GET_opcuaclient_modifysubscription_internal(fl)  s_pfCMGetAPI2( "opcuaclient_modifysubscription_internal", (RTS_VOID_FCTPTR *)&pfopcuaclient_modifysubscription_internal, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xFD8D1AF6, 0x03051000)
	#define CAL_opcuaclient_modifysubscription_internal  pfopcuaclient_modifysubscription_internal
	#define CHK_opcuaclient_modifysubscription_internal  (pfopcuaclient_modifysubscription_internal != NULL)
	#define EXP_opcuaclient_modifysubscription_internal   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_modifysubscription_internal", (RTS_UINTPTR)opcuaclient_modifysubscription_internal, 1, 0xFD8D1AF6, 0x03051000) 
#endif


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

void CDECL CDECL_EXT opcuaclient_read_internal(opcuaclient_read_internal_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUACLIENT_READ_INTERNAL_IEC) (opcuaclient_read_internal_struct *p);
#if defined(CMPOPCUACLIENT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUACLIENT_READ_INTERNAL_NOTIMPLEMENTED)
	#define USE_opcuaclient_read_internal
	#define EXT_opcuaclient_read_internal
	#define GET_opcuaclient_read_internal(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaclient_read_internal(p0) 
	#define CHK_opcuaclient_read_internal  FALSE
	#define EXP_opcuaclient_read_internal  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaclient_read_internal
	#define EXT_opcuaclient_read_internal
	#define GET_opcuaclient_read_internal(fl)  CAL_CMGETAPI( "opcuaclient_read_internal" ) 
	#define CAL_opcuaclient_read_internal  opcuaclient_read_internal
	#define CHK_opcuaclient_read_internal  TRUE
	#define EXP_opcuaclient_read_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_read_internal", (RTS_UINTPTR)opcuaclient_read_internal, 1, RTSITF_GET_SIGNATURE(0x0C31538B, 0x83047E1E), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaclient_read_internal
	#define EXT_opcuaclient_read_internal
	#define GET_opcuaclient_read_internal(fl)  CAL_CMGETAPI( "opcuaclient_read_internal" ) 
	#define CAL_opcuaclient_read_internal  opcuaclient_read_internal
	#define CHK_opcuaclient_read_internal  TRUE
	#define EXP_opcuaclient_read_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_read_internal", (RTS_UINTPTR)opcuaclient_read_internal, 1, RTSITF_GET_SIGNATURE(0x0C31538B, 0x83047E1E), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClient_Implementationopcuaclient_read_internal
	#define EXT_CmpOPCUAClient_Implementationopcuaclient_read_internal
	#define GET_CmpOPCUAClient_Implementationopcuaclient_read_internal  ERR_OK
	#define CAL_CmpOPCUAClient_Implementationopcuaclient_read_internal  opcuaclient_read_internal
	#define CHK_CmpOPCUAClient_Implementationopcuaclient_read_internal  TRUE
	#define EXP_CmpOPCUAClient_Implementationopcuaclient_read_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_read_internal", (RTS_UINTPTR)opcuaclient_read_internal, 1, RTSITF_GET_SIGNATURE(0x0C31538B, 0x83047E1E), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaclient_read_internal
	#define EXT_opcuaclient_read_internal
	#define GET_opcuaclient_read_internal(fl)  CAL_CMGETAPI( "opcuaclient_read_internal" ) 
	#define CAL_opcuaclient_read_internal  opcuaclient_read_internal
	#define CHK_opcuaclient_read_internal  TRUE
	#define EXP_opcuaclient_read_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_read_internal", (RTS_UINTPTR)opcuaclient_read_internal, 1, RTSITF_GET_SIGNATURE(0x0C31538B, 0x83047E1E), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaclient_read_internal  PFOPCUACLIENT_READ_INTERNAL_IEC pfopcuaclient_read_internal;
	#define EXT_opcuaclient_read_internal  extern PFOPCUACLIENT_READ_INTERNAL_IEC pfopcuaclient_read_internal;
	#define GET_opcuaclient_read_internal(fl)  s_pfCMGetAPI2( "opcuaclient_read_internal", (RTS_VOID_FCTPTR *)&pfopcuaclient_read_internal, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0x0C31538B, 0x83047E1E), 0x03051000)
	#define CAL_opcuaclient_read_internal  pfopcuaclient_read_internal
	#define CHK_opcuaclient_read_internal  (pfopcuaclient_read_internal != NULL)
	#define EXP_opcuaclient_read_internal   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_read_internal", (RTS_UINTPTR)opcuaclient_read_internal, 1, RTSITF_GET_SIGNATURE(0x0C31538B, 0x83047E1E), 0x03051000) 
#endif


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

void CDECL CDECL_EXT opcuaclient_registernodes_internal(opcuaclient_registernodes_internal_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUACLIENT_REGISTERNODES_INTERNAL_IEC) (opcuaclient_registernodes_internal_struct *p);
#if defined(CMPOPCUACLIENT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUACLIENT_REGISTERNODES_INTERNAL_NOTIMPLEMENTED)
	#define USE_opcuaclient_registernodes_internal
	#define EXT_opcuaclient_registernodes_internal
	#define GET_opcuaclient_registernodes_internal(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaclient_registernodes_internal(p0) 
	#define CHK_opcuaclient_registernodes_internal  FALSE
	#define EXP_opcuaclient_registernodes_internal  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaclient_registernodes_internal
	#define EXT_opcuaclient_registernodes_internal
	#define GET_opcuaclient_registernodes_internal(fl)  CAL_CMGETAPI( "opcuaclient_registernodes_internal" ) 
	#define CAL_opcuaclient_registernodes_internal  opcuaclient_registernodes_internal
	#define CHK_opcuaclient_registernodes_internal  TRUE
	#define EXP_opcuaclient_registernodes_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_registernodes_internal", (RTS_UINTPTR)opcuaclient_registernodes_internal, 1, RTSITF_GET_SIGNATURE(0xCC5F5C06, 0x195A207A), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaclient_registernodes_internal
	#define EXT_opcuaclient_registernodes_internal
	#define GET_opcuaclient_registernodes_internal(fl)  CAL_CMGETAPI( "opcuaclient_registernodes_internal" ) 
	#define CAL_opcuaclient_registernodes_internal  opcuaclient_registernodes_internal
	#define CHK_opcuaclient_registernodes_internal  TRUE
	#define EXP_opcuaclient_registernodes_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_registernodes_internal", (RTS_UINTPTR)opcuaclient_registernodes_internal, 1, RTSITF_GET_SIGNATURE(0xCC5F5C06, 0x195A207A), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClient_Implementationopcuaclient_registernodes_internal
	#define EXT_CmpOPCUAClient_Implementationopcuaclient_registernodes_internal
	#define GET_CmpOPCUAClient_Implementationopcuaclient_registernodes_internal  ERR_OK
	#define CAL_CmpOPCUAClient_Implementationopcuaclient_registernodes_internal  opcuaclient_registernodes_internal
	#define CHK_CmpOPCUAClient_Implementationopcuaclient_registernodes_internal  TRUE
	#define EXP_CmpOPCUAClient_Implementationopcuaclient_registernodes_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_registernodes_internal", (RTS_UINTPTR)opcuaclient_registernodes_internal, 1, RTSITF_GET_SIGNATURE(0xCC5F5C06, 0x195A207A), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaclient_registernodes_internal
	#define EXT_opcuaclient_registernodes_internal
	#define GET_opcuaclient_registernodes_internal(fl)  CAL_CMGETAPI( "opcuaclient_registernodes_internal" ) 
	#define CAL_opcuaclient_registernodes_internal  opcuaclient_registernodes_internal
	#define CHK_opcuaclient_registernodes_internal  TRUE
	#define EXP_opcuaclient_registernodes_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_registernodes_internal", (RTS_UINTPTR)opcuaclient_registernodes_internal, 1, RTSITF_GET_SIGNATURE(0xCC5F5C06, 0x195A207A), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaclient_registernodes_internal  PFOPCUACLIENT_REGISTERNODES_INTERNAL_IEC pfopcuaclient_registernodes_internal;
	#define EXT_opcuaclient_registernodes_internal  extern PFOPCUACLIENT_REGISTERNODES_INTERNAL_IEC pfopcuaclient_registernodes_internal;
	#define GET_opcuaclient_registernodes_internal(fl)  s_pfCMGetAPI2( "opcuaclient_registernodes_internal", (RTS_VOID_FCTPTR *)&pfopcuaclient_registernodes_internal, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0xCC5F5C06, 0x195A207A), 0x03051000)
	#define CAL_opcuaclient_registernodes_internal  pfopcuaclient_registernodes_internal
	#define CHK_opcuaclient_registernodes_internal  (pfopcuaclient_registernodes_internal != NULL)
	#define EXP_opcuaclient_registernodes_internal   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_registernodes_internal", (RTS_UINTPTR)opcuaclient_registernodes_internal, 1, RTSITF_GET_SIGNATURE(0xCC5F5C06, 0x195A207A), 0x03051000) 
#endif


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

void CDECL CDECL_EXT opcuaclient_setmonitoringmode_internal(opcuaclient_setmonitoringmode_internal_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUACLIENT_SETMONITORINGMODE_INTERNAL_IEC) (opcuaclient_setmonitoringmode_internal_struct *p);
#if defined(CMPOPCUACLIENT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUACLIENT_SETMONITORINGMODE_INTERNAL_NOTIMPLEMENTED)
	#define USE_opcuaclient_setmonitoringmode_internal
	#define EXT_opcuaclient_setmonitoringmode_internal
	#define GET_opcuaclient_setmonitoringmode_internal(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaclient_setmonitoringmode_internal(p0) 
	#define CHK_opcuaclient_setmonitoringmode_internal  FALSE
	#define EXP_opcuaclient_setmonitoringmode_internal  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaclient_setmonitoringmode_internal
	#define EXT_opcuaclient_setmonitoringmode_internal
	#define GET_opcuaclient_setmonitoringmode_internal(fl)  CAL_CMGETAPI( "opcuaclient_setmonitoringmode_internal" ) 
	#define CAL_opcuaclient_setmonitoringmode_internal  opcuaclient_setmonitoringmode_internal
	#define CHK_opcuaclient_setmonitoringmode_internal  TRUE
	#define EXP_opcuaclient_setmonitoringmode_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_setmonitoringmode_internal", (RTS_UINTPTR)opcuaclient_setmonitoringmode_internal, 1, 0x19605156, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaclient_setmonitoringmode_internal
	#define EXT_opcuaclient_setmonitoringmode_internal
	#define GET_opcuaclient_setmonitoringmode_internal(fl)  CAL_CMGETAPI( "opcuaclient_setmonitoringmode_internal" ) 
	#define CAL_opcuaclient_setmonitoringmode_internal  opcuaclient_setmonitoringmode_internal
	#define CHK_opcuaclient_setmonitoringmode_internal  TRUE
	#define EXP_opcuaclient_setmonitoringmode_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_setmonitoringmode_internal", (RTS_UINTPTR)opcuaclient_setmonitoringmode_internal, 1, 0x19605156, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClient_Implementationopcuaclient_setmonitoringmode_internal
	#define EXT_CmpOPCUAClient_Implementationopcuaclient_setmonitoringmode_internal
	#define GET_CmpOPCUAClient_Implementationopcuaclient_setmonitoringmode_internal  ERR_OK
	#define CAL_CmpOPCUAClient_Implementationopcuaclient_setmonitoringmode_internal  opcuaclient_setmonitoringmode_internal
	#define CHK_CmpOPCUAClient_Implementationopcuaclient_setmonitoringmode_internal  TRUE
	#define EXP_CmpOPCUAClient_Implementationopcuaclient_setmonitoringmode_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_setmonitoringmode_internal", (RTS_UINTPTR)opcuaclient_setmonitoringmode_internal, 1, 0x19605156, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaclient_setmonitoringmode_internal
	#define EXT_opcuaclient_setmonitoringmode_internal
	#define GET_opcuaclient_setmonitoringmode_internal(fl)  CAL_CMGETAPI( "opcuaclient_setmonitoringmode_internal" ) 
	#define CAL_opcuaclient_setmonitoringmode_internal  opcuaclient_setmonitoringmode_internal
	#define CHK_opcuaclient_setmonitoringmode_internal  TRUE
	#define EXP_opcuaclient_setmonitoringmode_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_setmonitoringmode_internal", (RTS_UINTPTR)opcuaclient_setmonitoringmode_internal, 1, 0x19605156, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaclient_setmonitoringmode_internal  PFOPCUACLIENT_SETMONITORINGMODE_INTERNAL_IEC pfopcuaclient_setmonitoringmode_internal;
	#define EXT_opcuaclient_setmonitoringmode_internal  extern PFOPCUACLIENT_SETMONITORINGMODE_INTERNAL_IEC pfopcuaclient_setmonitoringmode_internal;
	#define GET_opcuaclient_setmonitoringmode_internal(fl)  s_pfCMGetAPI2( "opcuaclient_setmonitoringmode_internal", (RTS_VOID_FCTPTR *)&pfopcuaclient_setmonitoringmode_internal, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x19605156, 0x03051000)
	#define CAL_opcuaclient_setmonitoringmode_internal  pfopcuaclient_setmonitoringmode_internal
	#define CHK_opcuaclient_setmonitoringmode_internal  (pfopcuaclient_setmonitoringmode_internal != NULL)
	#define EXP_opcuaclient_setmonitoringmode_internal   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_setmonitoringmode_internal", (RTS_UINTPTR)opcuaclient_setmonitoringmode_internal, 1, 0x19605156, 0x03051000) 
#endif


/**
 * <description>opcuaclient_setpublishingmode_internal</description>
 */
typedef struct tagopcuaclient_setpublishingmode_internal_struct
{
	RTS_IEC_HANDLE hSubscription;		/* VAR_INPUT */	
	RTS_IEC_BOOL publishingEnabled;		/* VAR_INPUT */	
	RTS_IEC_RESULT OPCUAClient_SetPublishingMode_internal;	/* VAR_OUTPUT */	
} opcuaclient_setpublishingmode_internal_struct;

void CDECL CDECL_EXT opcuaclient_setpublishingmode_internal(opcuaclient_setpublishingmode_internal_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUACLIENT_SETPUBLISHINGMODE_INTERNAL_IEC) (opcuaclient_setpublishingmode_internal_struct *p);
#if defined(CMPOPCUACLIENT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUACLIENT_SETPUBLISHINGMODE_INTERNAL_NOTIMPLEMENTED)
	#define USE_opcuaclient_setpublishingmode_internal
	#define EXT_opcuaclient_setpublishingmode_internal
	#define GET_opcuaclient_setpublishingmode_internal(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaclient_setpublishingmode_internal(p0) 
	#define CHK_opcuaclient_setpublishingmode_internal  FALSE
	#define EXP_opcuaclient_setpublishingmode_internal  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaclient_setpublishingmode_internal
	#define EXT_opcuaclient_setpublishingmode_internal
	#define GET_opcuaclient_setpublishingmode_internal(fl)  CAL_CMGETAPI( "opcuaclient_setpublishingmode_internal" ) 
	#define CAL_opcuaclient_setpublishingmode_internal  opcuaclient_setpublishingmode_internal
	#define CHK_opcuaclient_setpublishingmode_internal  TRUE
	#define EXP_opcuaclient_setpublishingmode_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_setpublishingmode_internal", (RTS_UINTPTR)opcuaclient_setpublishingmode_internal, 1, 0xE984A6EF, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaclient_setpublishingmode_internal
	#define EXT_opcuaclient_setpublishingmode_internal
	#define GET_opcuaclient_setpublishingmode_internal(fl)  CAL_CMGETAPI( "opcuaclient_setpublishingmode_internal" ) 
	#define CAL_opcuaclient_setpublishingmode_internal  opcuaclient_setpublishingmode_internal
	#define CHK_opcuaclient_setpublishingmode_internal  TRUE
	#define EXP_opcuaclient_setpublishingmode_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_setpublishingmode_internal", (RTS_UINTPTR)opcuaclient_setpublishingmode_internal, 1, 0xE984A6EF, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClient_Implementationopcuaclient_setpublishingmode_internal
	#define EXT_CmpOPCUAClient_Implementationopcuaclient_setpublishingmode_internal
	#define GET_CmpOPCUAClient_Implementationopcuaclient_setpublishingmode_internal  ERR_OK
	#define CAL_CmpOPCUAClient_Implementationopcuaclient_setpublishingmode_internal  opcuaclient_setpublishingmode_internal
	#define CHK_CmpOPCUAClient_Implementationopcuaclient_setpublishingmode_internal  TRUE
	#define EXP_CmpOPCUAClient_Implementationopcuaclient_setpublishingmode_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_setpublishingmode_internal", (RTS_UINTPTR)opcuaclient_setpublishingmode_internal, 1, 0xE984A6EF, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaclient_setpublishingmode_internal
	#define EXT_opcuaclient_setpublishingmode_internal
	#define GET_opcuaclient_setpublishingmode_internal(fl)  CAL_CMGETAPI( "opcuaclient_setpublishingmode_internal" ) 
	#define CAL_opcuaclient_setpublishingmode_internal  opcuaclient_setpublishingmode_internal
	#define CHK_opcuaclient_setpublishingmode_internal  TRUE
	#define EXP_opcuaclient_setpublishingmode_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_setpublishingmode_internal", (RTS_UINTPTR)opcuaclient_setpublishingmode_internal, 1, 0xE984A6EF, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaclient_setpublishingmode_internal  PFOPCUACLIENT_SETPUBLISHINGMODE_INTERNAL_IEC pfopcuaclient_setpublishingmode_internal;
	#define EXT_opcuaclient_setpublishingmode_internal  extern PFOPCUACLIENT_SETPUBLISHINGMODE_INTERNAL_IEC pfopcuaclient_setpublishingmode_internal;
	#define GET_opcuaclient_setpublishingmode_internal(fl)  s_pfCMGetAPI2( "opcuaclient_setpublishingmode_internal", (RTS_VOID_FCTPTR *)&pfopcuaclient_setpublishingmode_internal, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xE984A6EF, 0x03051000)
	#define CAL_opcuaclient_setpublishingmode_internal  pfopcuaclient_setpublishingmode_internal
	#define CHK_opcuaclient_setpublishingmode_internal  (pfopcuaclient_setpublishingmode_internal != NULL)
	#define EXP_opcuaclient_setpublishingmode_internal   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_setpublishingmode_internal", (RTS_UINTPTR)opcuaclient_setpublishingmode_internal, 1, 0xE984A6EF, 0x03051000) 
#endif


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

void CDECL CDECL_EXT opcuaclient_translatebrowsepathstonodeids_internal(opcuaclient_translatebrowsepathstonodeids_internal_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUACLIENT_TRANSLATEBROWSEPATHSTONODEIDS_INTERNAL_IEC) (opcuaclient_translatebrowsepathstonodeids_internal_struct *p);
#if defined(CMPOPCUACLIENT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUACLIENT_TRANSLATEBROWSEPATHSTONODEIDS_INTERNAL_NOTIMPLEMENTED)
	#define USE_opcuaclient_translatebrowsepathstonodeids_internal
	#define EXT_opcuaclient_translatebrowsepathstonodeids_internal
	#define GET_opcuaclient_translatebrowsepathstonodeids_internal(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaclient_translatebrowsepathstonodeids_internal(p0) 
	#define CHK_opcuaclient_translatebrowsepathstonodeids_internal  FALSE
	#define EXP_opcuaclient_translatebrowsepathstonodeids_internal  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaclient_translatebrowsepathstonodeids_internal
	#define EXT_opcuaclient_translatebrowsepathstonodeids_internal
	#define GET_opcuaclient_translatebrowsepathstonodeids_internal(fl)  CAL_CMGETAPI( "opcuaclient_translatebrowsepathstonodeids_internal" ) 
	#define CAL_opcuaclient_translatebrowsepathstonodeids_internal  opcuaclient_translatebrowsepathstonodeids_internal
	#define CHK_opcuaclient_translatebrowsepathstonodeids_internal  TRUE
	#define EXP_opcuaclient_translatebrowsepathstonodeids_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_translatebrowsepathstonodeids_internal", (RTS_UINTPTR)opcuaclient_translatebrowsepathstonodeids_internal, 1, RTSITF_GET_SIGNATURE(0xAD7C432A, 0x0EEA6B66), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaclient_translatebrowsepathstonodeids_internal
	#define EXT_opcuaclient_translatebrowsepathstonodeids_internal
	#define GET_opcuaclient_translatebrowsepathstonodeids_internal(fl)  CAL_CMGETAPI( "opcuaclient_translatebrowsepathstonodeids_internal" ) 
	#define CAL_opcuaclient_translatebrowsepathstonodeids_internal  opcuaclient_translatebrowsepathstonodeids_internal
	#define CHK_opcuaclient_translatebrowsepathstonodeids_internal  TRUE
	#define EXP_opcuaclient_translatebrowsepathstonodeids_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_translatebrowsepathstonodeids_internal", (RTS_UINTPTR)opcuaclient_translatebrowsepathstonodeids_internal, 1, RTSITF_GET_SIGNATURE(0xAD7C432A, 0x0EEA6B66), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClient_Implementationopcuaclient_translatebrowsepathstonodeids_internal
	#define EXT_CmpOPCUAClient_Implementationopcuaclient_translatebrowsepathstonodeids_internal
	#define GET_CmpOPCUAClient_Implementationopcuaclient_translatebrowsepathstonodeids_internal  ERR_OK
	#define CAL_CmpOPCUAClient_Implementationopcuaclient_translatebrowsepathstonodeids_internal  opcuaclient_translatebrowsepathstonodeids_internal
	#define CHK_CmpOPCUAClient_Implementationopcuaclient_translatebrowsepathstonodeids_internal  TRUE
	#define EXP_CmpOPCUAClient_Implementationopcuaclient_translatebrowsepathstonodeids_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_translatebrowsepathstonodeids_internal", (RTS_UINTPTR)opcuaclient_translatebrowsepathstonodeids_internal, 1, RTSITF_GET_SIGNATURE(0xAD7C432A, 0x0EEA6B66), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaclient_translatebrowsepathstonodeids_internal
	#define EXT_opcuaclient_translatebrowsepathstonodeids_internal
	#define GET_opcuaclient_translatebrowsepathstonodeids_internal(fl)  CAL_CMGETAPI( "opcuaclient_translatebrowsepathstonodeids_internal" ) 
	#define CAL_opcuaclient_translatebrowsepathstonodeids_internal  opcuaclient_translatebrowsepathstonodeids_internal
	#define CHK_opcuaclient_translatebrowsepathstonodeids_internal  TRUE
	#define EXP_opcuaclient_translatebrowsepathstonodeids_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_translatebrowsepathstonodeids_internal", (RTS_UINTPTR)opcuaclient_translatebrowsepathstonodeids_internal, 1, RTSITF_GET_SIGNATURE(0xAD7C432A, 0x0EEA6B66), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaclient_translatebrowsepathstonodeids_internal  PFOPCUACLIENT_TRANSLATEBROWSEPATHSTONODEIDS_INTERNAL_IEC pfopcuaclient_translatebrowsepathstonodeids_internal;
	#define EXT_opcuaclient_translatebrowsepathstonodeids_internal  extern PFOPCUACLIENT_TRANSLATEBROWSEPATHSTONODEIDS_INTERNAL_IEC pfopcuaclient_translatebrowsepathstonodeids_internal;
	#define GET_opcuaclient_translatebrowsepathstonodeids_internal(fl)  s_pfCMGetAPI2( "opcuaclient_translatebrowsepathstonodeids_internal", (RTS_VOID_FCTPTR *)&pfopcuaclient_translatebrowsepathstonodeids_internal, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0xAD7C432A, 0x0EEA6B66), 0x03051000)
	#define CAL_opcuaclient_translatebrowsepathstonodeids_internal  pfopcuaclient_translatebrowsepathstonodeids_internal
	#define CHK_opcuaclient_translatebrowsepathstonodeids_internal  (pfopcuaclient_translatebrowsepathstonodeids_internal != NULL)
	#define EXP_opcuaclient_translatebrowsepathstonodeids_internal   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_translatebrowsepathstonodeids_internal", (RTS_UINTPTR)opcuaclient_translatebrowsepathstonodeids_internal, 1, RTSITF_GET_SIGNATURE(0xAD7C432A, 0x0EEA6B66), 0x03051000) 
#endif


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

void CDECL CDECL_EXT opcuaclient_unregisternodes_internal(opcuaclient_unregisternodes_internal_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUACLIENT_UNREGISTERNODES_INTERNAL_IEC) (opcuaclient_unregisternodes_internal_struct *p);
#if defined(CMPOPCUACLIENT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUACLIENT_UNREGISTERNODES_INTERNAL_NOTIMPLEMENTED)
	#define USE_opcuaclient_unregisternodes_internal
	#define EXT_opcuaclient_unregisternodes_internal
	#define GET_opcuaclient_unregisternodes_internal(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaclient_unregisternodes_internal(p0) 
	#define CHK_opcuaclient_unregisternodes_internal  FALSE
	#define EXP_opcuaclient_unregisternodes_internal  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaclient_unregisternodes_internal
	#define EXT_opcuaclient_unregisternodes_internal
	#define GET_opcuaclient_unregisternodes_internal(fl)  CAL_CMGETAPI( "opcuaclient_unregisternodes_internal" ) 
	#define CAL_opcuaclient_unregisternodes_internal  opcuaclient_unregisternodes_internal
	#define CHK_opcuaclient_unregisternodes_internal  TRUE
	#define EXP_opcuaclient_unregisternodes_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_unregisternodes_internal", (RTS_UINTPTR)opcuaclient_unregisternodes_internal, 1, RTSITF_GET_SIGNATURE(0xE6C50D5E, 0x9B084061), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaclient_unregisternodes_internal
	#define EXT_opcuaclient_unregisternodes_internal
	#define GET_opcuaclient_unregisternodes_internal(fl)  CAL_CMGETAPI( "opcuaclient_unregisternodes_internal" ) 
	#define CAL_opcuaclient_unregisternodes_internal  opcuaclient_unregisternodes_internal
	#define CHK_opcuaclient_unregisternodes_internal  TRUE
	#define EXP_opcuaclient_unregisternodes_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_unregisternodes_internal", (RTS_UINTPTR)opcuaclient_unregisternodes_internal, 1, RTSITF_GET_SIGNATURE(0xE6C50D5E, 0x9B084061), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClient_Implementationopcuaclient_unregisternodes_internal
	#define EXT_CmpOPCUAClient_Implementationopcuaclient_unregisternodes_internal
	#define GET_CmpOPCUAClient_Implementationopcuaclient_unregisternodes_internal  ERR_OK
	#define CAL_CmpOPCUAClient_Implementationopcuaclient_unregisternodes_internal  opcuaclient_unregisternodes_internal
	#define CHK_CmpOPCUAClient_Implementationopcuaclient_unregisternodes_internal  TRUE
	#define EXP_CmpOPCUAClient_Implementationopcuaclient_unregisternodes_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_unregisternodes_internal", (RTS_UINTPTR)opcuaclient_unregisternodes_internal, 1, RTSITF_GET_SIGNATURE(0xE6C50D5E, 0x9B084061), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaclient_unregisternodes_internal
	#define EXT_opcuaclient_unregisternodes_internal
	#define GET_opcuaclient_unregisternodes_internal(fl)  CAL_CMGETAPI( "opcuaclient_unregisternodes_internal" ) 
	#define CAL_opcuaclient_unregisternodes_internal  opcuaclient_unregisternodes_internal
	#define CHK_opcuaclient_unregisternodes_internal  TRUE
	#define EXP_opcuaclient_unregisternodes_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_unregisternodes_internal", (RTS_UINTPTR)opcuaclient_unregisternodes_internal, 1, RTSITF_GET_SIGNATURE(0xE6C50D5E, 0x9B084061), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaclient_unregisternodes_internal  PFOPCUACLIENT_UNREGISTERNODES_INTERNAL_IEC pfopcuaclient_unregisternodes_internal;
	#define EXT_opcuaclient_unregisternodes_internal  extern PFOPCUACLIENT_UNREGISTERNODES_INTERNAL_IEC pfopcuaclient_unregisternodes_internal;
	#define GET_opcuaclient_unregisternodes_internal(fl)  s_pfCMGetAPI2( "opcuaclient_unregisternodes_internal", (RTS_VOID_FCTPTR *)&pfopcuaclient_unregisternodes_internal, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0xE6C50D5E, 0x9B084061), 0x03051000)
	#define CAL_opcuaclient_unregisternodes_internal  pfopcuaclient_unregisternodes_internal
	#define CHK_opcuaclient_unregisternodes_internal  (pfopcuaclient_unregisternodes_internal != NULL)
	#define EXP_opcuaclient_unregisternodes_internal   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_unregisternodes_internal", (RTS_UINTPTR)opcuaclient_unregisternodes_internal, 1, RTSITF_GET_SIGNATURE(0xE6C50D5E, 0x9B084061), 0x03051000) 
#endif


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

void CDECL CDECL_EXT opcuaclient_write_internal(opcuaclient_write_internal_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUACLIENT_WRITE_INTERNAL_IEC) (opcuaclient_write_internal_struct *p);
#if defined(CMPOPCUACLIENT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUACLIENT_WRITE_INTERNAL_NOTIMPLEMENTED)
	#define USE_opcuaclient_write_internal
	#define EXT_opcuaclient_write_internal
	#define GET_opcuaclient_write_internal(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaclient_write_internal(p0) 
	#define CHK_opcuaclient_write_internal  FALSE
	#define EXP_opcuaclient_write_internal  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaclient_write_internal
	#define EXT_opcuaclient_write_internal
	#define GET_opcuaclient_write_internal(fl)  CAL_CMGETAPI( "opcuaclient_write_internal" ) 
	#define CAL_opcuaclient_write_internal  opcuaclient_write_internal
	#define CHK_opcuaclient_write_internal  TRUE
	#define EXP_opcuaclient_write_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_write_internal", (RTS_UINTPTR)opcuaclient_write_internal, 1, RTSITF_GET_SIGNATURE(0x3300C94E, 0x231AEA7F), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUACLIENT_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaclient_write_internal
	#define EXT_opcuaclient_write_internal
	#define GET_opcuaclient_write_internal(fl)  CAL_CMGETAPI( "opcuaclient_write_internal" ) 
	#define CAL_opcuaclient_write_internal  opcuaclient_write_internal
	#define CHK_opcuaclient_write_internal  TRUE
	#define EXP_opcuaclient_write_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_write_internal", (RTS_UINTPTR)opcuaclient_write_internal, 1, RTSITF_GET_SIGNATURE(0x3300C94E, 0x231AEA7F), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAClient_Implementationopcuaclient_write_internal
	#define EXT_CmpOPCUAClient_Implementationopcuaclient_write_internal
	#define GET_CmpOPCUAClient_Implementationopcuaclient_write_internal  ERR_OK
	#define CAL_CmpOPCUAClient_Implementationopcuaclient_write_internal  opcuaclient_write_internal
	#define CHK_CmpOPCUAClient_Implementationopcuaclient_write_internal  TRUE
	#define EXP_CmpOPCUAClient_Implementationopcuaclient_write_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_write_internal", (RTS_UINTPTR)opcuaclient_write_internal, 1, RTSITF_GET_SIGNATURE(0x3300C94E, 0x231AEA7F), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaclient_write_internal
	#define EXT_opcuaclient_write_internal
	#define GET_opcuaclient_write_internal(fl)  CAL_CMGETAPI( "opcuaclient_write_internal" ) 
	#define CAL_opcuaclient_write_internal  opcuaclient_write_internal
	#define CHK_opcuaclient_write_internal  TRUE
	#define EXP_opcuaclient_write_internal  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_write_internal", (RTS_UINTPTR)opcuaclient_write_internal, 1, RTSITF_GET_SIGNATURE(0x3300C94E, 0x231AEA7F), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaclient_write_internal  PFOPCUACLIENT_WRITE_INTERNAL_IEC pfopcuaclient_write_internal;
	#define EXT_opcuaclient_write_internal  extern PFOPCUACLIENT_WRITE_INTERNAL_IEC pfopcuaclient_write_internal;
	#define GET_opcuaclient_write_internal(fl)  s_pfCMGetAPI2( "opcuaclient_write_internal", (RTS_VOID_FCTPTR *)&pfopcuaclient_write_internal, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0x3300C94E, 0x231AEA7F), 0x03051000)
	#define CAL_opcuaclient_write_internal  pfopcuaclient_write_internal
	#define CHK_opcuaclient_write_internal  (pfopcuaclient_write_internal != NULL)
	#define EXP_opcuaclient_write_internal   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaclient_write_internal", (RTS_UINTPTR)opcuaclient_write_internal, 1, RTSITF_GET_SIGNATURE(0x3300C94E, 0x231AEA7F), 0x03051000) 
#endif


#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/




typedef struct
{
	IBase_C *pBase;
} ICmpOPCUAClient_Implementation_C;

#ifdef CPLUSPLUS
class ICmpOPCUAClient_Implementation : public IBase
{
	public:
};
	#ifndef ITF_CmpOPCUAClient_Implementation
		#define ITF_CmpOPCUAClient_Implementation static ICmpOPCUAClient_Implementation *pICmpOPCUAClient_Implementation = NULL;
	#endif
	#define EXTITF_CmpOPCUAClient_Implementation
#else	/*CPLUSPLUS*/
	typedef ICmpOPCUAClient_Implementation_C		ICmpOPCUAClient_Implementation;
	#ifndef ITF_CmpOPCUAClient_Implementation
		#define ITF_CmpOPCUAClient_Implementation
	#endif
	#define EXTITF_CmpOPCUAClient_Implementation
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_CMPOPCUACLIENT_IMPLEMENTATIONITF_H_*/
