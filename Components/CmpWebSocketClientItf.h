 /**
 * <interfacename>CmpWebSocketClient</interfacename>
 * <description>
 * 	This component contains an implementation of the WebSocket protocol
 *	on the client side. See RFC-6455 (https://tools.ietf.org/html/rfc6455)
 *	for details.
 *
 *	The following features are supported:
 *		- Connect to WebSocket server using plaintext connection. (ws:// schema)
 *		- Connect to WebSocket server using TLS connection. (wss:// schema)
 *		- Send binary and text frames.
 *		- Do a fragmented transfer. Fragmentation has to be done by using implementation.
 *		- Receive binary and text frames.
 *		- Receive a fragmented transfer. Defragmentation has to be done by using implementation;
 *		- Ping / Pong is handled by the implementation. The using implementation is notified if 
 *        a Ping or Pong was received.
 *
 *	The configuration of the TLS connection has to be done by the using implementation. A TLS 
 *	context must be configured to the needs of the application. This TLS context is passed to 
 *	the WebSocket implementation. It is used to create a secure socket. If needed a callback 
 *	for the server certificate validation can be added to this TLS context. The TLS context 
 *	must use a TLS client method.
 *
 *	The Implementation will parse the given URL and get the host (or IP-address), port (if 
 *	set) and path (if set) from that URL. If no port is given default ports will be used.
 *	(80 for ws:// schema, 443 for wss:// schema).
 *
 * </description>
 * <copyright>
 * Copyright (c) 2018 CODESYS Development GmbH. All rights reserved.
 * </copyright>
 */


	
	
#ifndef _CMPWEBSOCKETCLIENTITF_H_
#define _CMPWEBSOCKETCLIENTITF_H_

#include "CmpStd.h"

 

 




#ifndef CDECL
	#define CDECL
#endif


#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
	WebSocketStatus_Not_Relevant = 0,
	WebSocketStatus_Close_Normal = 1000,
	WebSocketStatus_Close_GoingAway = 1001,
	WebSocketStatus_Close_Protocol = 1002,
	WebSocketStatus_Close_Type = 1003,
	WebSocketStatus_Close_Inconsistent = 1007,
	WebSocketStatus_Close_Policy = 1008,
	WebSocketStatus_Close_Toobig = 1009,
	WebSocketStatus_Close_Extension = 1010,
	WebSocketStatus_Close_Unexpected = 1011
}WebSocketStatus;

typedef enum
{
	WsClientState_Initial,
	WsClientState_InConnect,
	WsClientState_InConnect_HandshakeSent,
	WsClientState_Connected,
	WsClientState_PingReceived,
	WsClientState_PongReceived,
	WsClientState_FrameSentCompletly,
	WsClientState_ConnectionClosedByServer,
	WsClientState_ConnectionClosedLocally,
	WsClientState_InConnect_InitialResponseReceived,
	WsClientState_InConnect_InProxyConnect,
	WsClientState_InConnect_ProxyConnected,
	WsClientState_InConnect_TlsStarted
}WsClientState;

typedef enum
{
	WsClientProxyType_None = 0,
	WsClientProxyType_Http
}WsClientProxyType;

typedef struct
{
	WsClientProxyType proxyType;
	char szProxy[255];
	RTS_UI16 port;
	char szProxyUser[255];
	char szProxyPassword[255];
}WsClientProxy;

/**
 * <description>
 *	Callback function if a complete frame is received from the WebSocket. A single frame is completely defragmented by the 
 *  WebSocket implementation. A fragmented transfer where multiple frames are used must be defragmented by the caller.
 * </description>
 * <param name="hClient" type="IN">Handle to the client that received the frame.</param>
 * <param name="pUserData" type="IN">Pointer to user defined data.</param>
 * <param name="pData" type="IN">Pointer to the received data.</param>
 * <param name="dataSize" type="IN">Size of available data.</param>
 * <param name="bBinaryMode" type="IN">TRUE if a binary frame is received. FALSE if a text frame is received.</param>
 * <param name="bFinalFragmet" type="IN">TRUE if this is the final fragment. This can happen for the first frame. If FALSE this is part of a fragmented transfer.</param>
 */
typedef void(CDECL *PFDATARECEIVEDCALLBACK)(RTS_HANDLE hClient, void* pUserData, RTS_UI8* pData, RTS_SIZE dataSize, RTS_BOOL bBinaryMode, RTS_BOOL bFinalFragmet);

/**
 * <description>
 *	Callback function to inform on state changes of the WebSocket connection.
 *  Note: For WsClientState_PingReceived and WsClientState_PongReceived are used informational. Internal no state is changed.
 * </description>
 * <param name="hClient" type="IN">Handle to the client that received the frame.</param>
 * <param name="pUserData" type="IN">Pointer to user defined data.</param>
 * <param name="newState" type="IN">New state of the WebSocket connection.</param>
 * <param name="statusCode" type="IN">This is used when the state changes to ConnectionClosed. This is the reason why.</param>
 */
typedef void(CDECL *PFSTATECHANGECLALLBACK)(RTS_HANDLE hClient, void* pUserData, WsClientState newState, WebSocketStatus statusCode);


/**
 * <description>
 *	Create a new WebSocket client.
 * </description>
 * <param name="bufferSize" type="IN">Set this to the maximum data size size needed.</param>
 * <param name="pszUrl" type="IN">
 *    URL to connect to. The official scheme for WebSockets ws://host[:port][/path] (plain text) or wss://[:port][/path] (TLS connection) is expected here.
 *    The parts are used in that way:
 *		host (Mandatory): Used for HOST in the HTTP GET request. Used to resolve the Server. You can use a host name or IP-address. If a host name is used and scheme is WSS a SNI will be added to the TLS handshake.
 *      port (Optional): Port to connect to.
 *      path (Optional): Path is used in the HTTP GET request. If not available a '/' will be added to the HTTP GET request.
 * </param>
 * <param name="pszProto" type="IN">Protocol used inside the websocket handshake header. May be NULL.</param>
 * <param name="hTlsContext" type="IN">The TLC context to use if a wss:// scheme is given.</param>
 * <param name="pUserData" type="IN">Pointer to a user defined value. This is passed to the two callbacks.</param>
 * <param name="pfDataReceivedCallback" type="IN">Callback function used if a data frame is received.</param>
 * <param name="pfStateChangeCallback" type="IN">Callback function used to send state changes.</param>
 * <param name="pResult" type="OUT">Error Code: 
 *		- ERR_OK: WebSocket client created successfully.
 *		- ERR_PARAMETER: One of the parameters is invalid.
 *		- ERR_INVALID_URL: The given URL is invalid.
 *		- ERR_INVALID_HANDLE: A wss:// scheme is given, but hTlsContext is invalid.
 * </param>
 * <result>Handle to the WebSocket. RTS_INVALID_HANDLE in case of an error.</result>
 */
RTS_HANDLE CDECL WsClientCreate(RTS_SIZE bufferSize, char* pszUrl, char* pszProto, RTS_HANDLE hTlsContext, void* pUserData, PFDATARECEIVEDCALLBACK pfDataReceivedCallback, PFSTATECHANGECLALLBACK pfStateChangeCallback, RTS_RESULT *pResult);
typedef RTS_HANDLE (CDECL * PFWSCLIENTCREATE) (RTS_SIZE bufferSize, char* pszUrl, char* pszProto, RTS_HANDLE hTlsContext, void* pUserData, PFDATARECEIVEDCALLBACK pfDataReceivedCallback, PFSTATECHANGECLALLBACK pfStateChangeCallback, RTS_RESULT *pResult);
#if defined(CMPWEBSOCKETCLIENT_NOTIMPLEMENTED) || defined(WSCLIENTCREATE_NOTIMPLEMENTED)
	#define USE_WsClientCreate
	#define EXT_WsClientCreate
	#define GET_WsClientCreate(fl)  ERR_NOTIMPLEMENTED
	#define CAL_WsClientCreate(p0,p1,p2,p3,p4,p5,p6,p7)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_WsClientCreate  FALSE
	#define EXP_WsClientCreate  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_WsClientCreate
	#define EXT_WsClientCreate
	#define GET_WsClientCreate(fl)  CAL_CMGETAPI( "WsClientCreate" ) 
	#define CAL_WsClientCreate  WsClientCreate
	#define CHK_WsClientCreate  TRUE
	#define EXP_WsClientCreate  CAL_CMEXPAPI( "WsClientCreate" ) 
#elif defined(MIXED_LINK) && !defined(CMPWEBSOCKETCLIENT_EXTERNAL)
	#define USE_WsClientCreate
	#define EXT_WsClientCreate
	#define GET_WsClientCreate(fl)  CAL_CMGETAPI( "WsClientCreate" ) 
	#define CAL_WsClientCreate  WsClientCreate
	#define CHK_WsClientCreate  TRUE
	#define EXP_WsClientCreate  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"WsClientCreate", (RTS_UINTPTR)WsClientCreate, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpWebSocketClientWsClientCreate
	#define EXT_CmpWebSocketClientWsClientCreate
	#define GET_CmpWebSocketClientWsClientCreate  ERR_OK
	#define CAL_CmpWebSocketClientWsClientCreate pICmpWebSocketClient->IWsClientCreate
	#define CHK_CmpWebSocketClientWsClientCreate (pICmpWebSocketClient != NULL)
	#define EXP_CmpWebSocketClientWsClientCreate  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_WsClientCreate
	#define EXT_WsClientCreate
	#define GET_WsClientCreate(fl)  CAL_CMGETAPI( "WsClientCreate" ) 
	#define CAL_WsClientCreate pICmpWebSocketClient->IWsClientCreate
	#define CHK_WsClientCreate (pICmpWebSocketClient != NULL)
	#define EXP_WsClientCreate  CAL_CMEXPAPI( "WsClientCreate" ) 
#else /* DYNAMIC_LINK */
	#define USE_WsClientCreate  PFWSCLIENTCREATE pfWsClientCreate;
	#define EXT_WsClientCreate  extern PFWSCLIENTCREATE pfWsClientCreate;
	#define GET_WsClientCreate(fl)  s_pfCMGetAPI2( "WsClientCreate", (RTS_VOID_FCTPTR *)&pfWsClientCreate, (fl), 0, 0)
	#define CAL_WsClientCreate  pfWsClientCreate
	#define CHK_WsClientCreate  (pfWsClientCreate != NULL)
	#define EXP_WsClientCreate  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"WsClientCreate", (RTS_UINTPTR)WsClientCreate, 0, 0) 
#endif




/**
 * <description>
 *	Delete a WebSocket client.
 * </description>
 * <param name="hSocket" type="IN">Handle to the WebSocket</param>
 * <result>Either ERR_OK or ERR_INVALID_HANDLE in case hClient is unknown.</result>
 */
RTS_RESULT CDECL WsClientDelete(RTS_HANDLE hClient);
typedef RTS_RESULT (CDECL * PFWSCLIENTDELETE) (RTS_HANDLE hClient);
#if defined(CMPWEBSOCKETCLIENT_NOTIMPLEMENTED) || defined(WSCLIENTDELETE_NOTIMPLEMENTED)
	#define USE_WsClientDelete
	#define EXT_WsClientDelete
	#define GET_WsClientDelete(fl)  ERR_NOTIMPLEMENTED
	#define CAL_WsClientDelete(p0)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_WsClientDelete  FALSE
	#define EXP_WsClientDelete  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_WsClientDelete
	#define EXT_WsClientDelete
	#define GET_WsClientDelete(fl)  CAL_CMGETAPI( "WsClientDelete" ) 
	#define CAL_WsClientDelete  WsClientDelete
	#define CHK_WsClientDelete  TRUE
	#define EXP_WsClientDelete  CAL_CMEXPAPI( "WsClientDelete" ) 
#elif defined(MIXED_LINK) && !defined(CMPWEBSOCKETCLIENT_EXTERNAL)
	#define USE_WsClientDelete
	#define EXT_WsClientDelete
	#define GET_WsClientDelete(fl)  CAL_CMGETAPI( "WsClientDelete" ) 
	#define CAL_WsClientDelete  WsClientDelete
	#define CHK_WsClientDelete  TRUE
	#define EXP_WsClientDelete  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"WsClientDelete", (RTS_UINTPTR)WsClientDelete, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpWebSocketClientWsClientDelete
	#define EXT_CmpWebSocketClientWsClientDelete
	#define GET_CmpWebSocketClientWsClientDelete  ERR_OK
	#define CAL_CmpWebSocketClientWsClientDelete pICmpWebSocketClient->IWsClientDelete
	#define CHK_CmpWebSocketClientWsClientDelete (pICmpWebSocketClient != NULL)
	#define EXP_CmpWebSocketClientWsClientDelete  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_WsClientDelete
	#define EXT_WsClientDelete
	#define GET_WsClientDelete(fl)  CAL_CMGETAPI( "WsClientDelete" ) 
	#define CAL_WsClientDelete pICmpWebSocketClient->IWsClientDelete
	#define CHK_WsClientDelete (pICmpWebSocketClient != NULL)
	#define EXP_WsClientDelete  CAL_CMEXPAPI( "WsClientDelete" ) 
#else /* DYNAMIC_LINK */
	#define USE_WsClientDelete  PFWSCLIENTDELETE pfWsClientDelete;
	#define EXT_WsClientDelete  extern PFWSCLIENTDELETE pfWsClientDelete;
	#define GET_WsClientDelete(fl)  s_pfCMGetAPI2( "WsClientDelete", (RTS_VOID_FCTPTR *)&pfWsClientDelete, (fl), 0, 0)
	#define CAL_WsClientDelete  pfWsClientDelete
	#define CHK_WsClientDelete  (pfWsClientDelete != NULL)
	#define EXP_WsClientDelete  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"WsClientDelete", (RTS_UINTPTR)WsClientDelete, 0, 0) 
#endif




/**
 * <description>
 *	Connects the WebSocket to the WebSocket server.
 * </description>
 * <param name="hClient" type="IN">Handle to the WebSocket</param>
 * <result>Error Code:
 *		- ERR_INVALID_HANDLE: The given hClient is unknown.
 *		- ERR_SOCK_HOSTNOTFOUND: The host of the URL could not be found.
 *		- ERR_FAILED: Some internal error occurred.
 *		- ERR_PENDING: Connection pending. Will be finished within WsClientProcess. Wait for state callback with WsClientState_Connected.
 * </result>
 */
RTS_RESULT CDECL WsClientConnect(RTS_HANDLE hClient);
typedef RTS_RESULT (CDECL * PFWSCLIENTCONNECT) (RTS_HANDLE hClient);
#if defined(CMPWEBSOCKETCLIENT_NOTIMPLEMENTED) || defined(WSCLIENTCONNECT_NOTIMPLEMENTED)
	#define USE_WsClientConnect
	#define EXT_WsClientConnect
	#define GET_WsClientConnect(fl)  ERR_NOTIMPLEMENTED
	#define CAL_WsClientConnect(p0)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_WsClientConnect  FALSE
	#define EXP_WsClientConnect  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_WsClientConnect
	#define EXT_WsClientConnect
	#define GET_WsClientConnect(fl)  CAL_CMGETAPI( "WsClientConnect" ) 
	#define CAL_WsClientConnect  WsClientConnect
	#define CHK_WsClientConnect  TRUE
	#define EXP_WsClientConnect  CAL_CMEXPAPI( "WsClientConnect" ) 
#elif defined(MIXED_LINK) && !defined(CMPWEBSOCKETCLIENT_EXTERNAL)
	#define USE_WsClientConnect
	#define EXT_WsClientConnect
	#define GET_WsClientConnect(fl)  CAL_CMGETAPI( "WsClientConnect" ) 
	#define CAL_WsClientConnect  WsClientConnect
	#define CHK_WsClientConnect  TRUE
	#define EXP_WsClientConnect  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"WsClientConnect", (RTS_UINTPTR)WsClientConnect, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpWebSocketClientWsClientConnect
	#define EXT_CmpWebSocketClientWsClientConnect
	#define GET_CmpWebSocketClientWsClientConnect  ERR_OK
	#define CAL_CmpWebSocketClientWsClientConnect pICmpWebSocketClient->IWsClientConnect
	#define CHK_CmpWebSocketClientWsClientConnect (pICmpWebSocketClient != NULL)
	#define EXP_CmpWebSocketClientWsClientConnect  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_WsClientConnect
	#define EXT_WsClientConnect
	#define GET_WsClientConnect(fl)  CAL_CMGETAPI( "WsClientConnect" ) 
	#define CAL_WsClientConnect pICmpWebSocketClient->IWsClientConnect
	#define CHK_WsClientConnect (pICmpWebSocketClient != NULL)
	#define EXP_WsClientConnect  CAL_CMEXPAPI( "WsClientConnect" ) 
#else /* DYNAMIC_LINK */
	#define USE_WsClientConnect  PFWSCLIENTCONNECT pfWsClientConnect;
	#define EXT_WsClientConnect  extern PFWSCLIENTCONNECT pfWsClientConnect;
	#define GET_WsClientConnect(fl)  s_pfCMGetAPI2( "WsClientConnect", (RTS_VOID_FCTPTR *)&pfWsClientConnect, (fl), 0, 0)
	#define CAL_WsClientConnect  pfWsClientConnect
	#define CHK_WsClientConnect  (pfWsClientConnect != NULL)
	#define EXP_WsClientConnect  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"WsClientConnect", (RTS_UINTPTR)WsClientConnect, 0, 0) 
#endif




/**
 * <description>
 *	Disconnects the WebSocket. Sends a FIN frame to the server. Use WsClientConnect to reestablish the connection the same server.
 * </description>
 * <param name="hClient" type="IN">Handle to the WebSocket.</param>
 * <param name="statusCode" type="IN">Status code why the connection is beeing closed.</param>
 * <result>Error Code:
 *		- ERR_INVALID_HANDLE: The given hClient is unknown.
 *		- ERR_OK: The connection is closed.
 * </result>
 */
RTS_RESULT CDECL WsClientDisconnect(RTS_HANDLE hClient, WebSocketStatus statusCode);
typedef RTS_RESULT (CDECL * PFWSCLIENTDISCONNECT) (RTS_HANDLE hClient, WebSocketStatus statusCode);
#if defined(CMPWEBSOCKETCLIENT_NOTIMPLEMENTED) || defined(WSCLIENTDISCONNECT_NOTIMPLEMENTED)
	#define USE_WsClientDisconnect
	#define EXT_WsClientDisconnect
	#define GET_WsClientDisconnect(fl)  ERR_NOTIMPLEMENTED
	#define CAL_WsClientDisconnect(p0,p1)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_WsClientDisconnect  FALSE
	#define EXP_WsClientDisconnect  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_WsClientDisconnect
	#define EXT_WsClientDisconnect
	#define GET_WsClientDisconnect(fl)  CAL_CMGETAPI( "WsClientDisconnect" ) 
	#define CAL_WsClientDisconnect  WsClientDisconnect
	#define CHK_WsClientDisconnect  TRUE
	#define EXP_WsClientDisconnect  CAL_CMEXPAPI( "WsClientDisconnect" ) 
#elif defined(MIXED_LINK) && !defined(CMPWEBSOCKETCLIENT_EXTERNAL)
	#define USE_WsClientDisconnect
	#define EXT_WsClientDisconnect
	#define GET_WsClientDisconnect(fl)  CAL_CMGETAPI( "WsClientDisconnect" ) 
	#define CAL_WsClientDisconnect  WsClientDisconnect
	#define CHK_WsClientDisconnect  TRUE
	#define EXP_WsClientDisconnect  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"WsClientDisconnect", (RTS_UINTPTR)WsClientDisconnect, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpWebSocketClientWsClientDisconnect
	#define EXT_CmpWebSocketClientWsClientDisconnect
	#define GET_CmpWebSocketClientWsClientDisconnect  ERR_OK
	#define CAL_CmpWebSocketClientWsClientDisconnect pICmpWebSocketClient->IWsClientDisconnect
	#define CHK_CmpWebSocketClientWsClientDisconnect (pICmpWebSocketClient != NULL)
	#define EXP_CmpWebSocketClientWsClientDisconnect  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_WsClientDisconnect
	#define EXT_WsClientDisconnect
	#define GET_WsClientDisconnect(fl)  CAL_CMGETAPI( "WsClientDisconnect" ) 
	#define CAL_WsClientDisconnect pICmpWebSocketClient->IWsClientDisconnect
	#define CHK_WsClientDisconnect (pICmpWebSocketClient != NULL)
	#define EXP_WsClientDisconnect  CAL_CMEXPAPI( "WsClientDisconnect" ) 
#else /* DYNAMIC_LINK */
	#define USE_WsClientDisconnect  PFWSCLIENTDISCONNECT pfWsClientDisconnect;
	#define EXT_WsClientDisconnect  extern PFWSCLIENTDISCONNECT pfWsClientDisconnect;
	#define GET_WsClientDisconnect(fl)  s_pfCMGetAPI2( "WsClientDisconnect", (RTS_VOID_FCTPTR *)&pfWsClientDisconnect, (fl), 0, 0)
	#define CAL_WsClientDisconnect  pfWsClientDisconnect
	#define CHK_WsClientDisconnect  (pfWsClientDisconnect != NULL)
	#define EXP_WsClientDisconnect  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"WsClientDisconnect", (RTS_UINTPTR)WsClientDisconnect, 0, 0) 
#endif




/**
 * <description>
 *	Send a data frame to the server.
 * </description>
 * <param name="hClient" type="IN">Handle to the WebSocket.</param>
 * <param name="pSendData" type="IN">Pointer to the data to send.</param>
 * <param name="dataSize" type="IN">Size of the data to send.</param>
 * <param name="bBinaryMode" type="IN">If TRUE, a binary frame will be sent. If FALSE, a text frame will be sent.</param>
 * <param name="bFinalFragmet" type="IN">Use this to signal that this is the final frame. If not set the subsequent calls will send send continuation frames until bFinalFragmet is set to TRUE.</param>
 * <result>Error Code:
 *		- ERR_OK: Frame is sent.
 *		- ERR_BUFFERSIZE: Too much data to send.
 *		- ERR_PENDING: Parts where sent. Sending is finished in WsClientProcess.
 *		- ERR_CALL_AGAIN: No data sent. Call again.
 * </result>
 */
RTS_RESULT CDECL WsClientSend(RTS_HANDLE hClient, RTS_UI8* pSendData, RTS_SIZE dataSize, RTS_BOOL bBinaryMode, RTS_BOOL bFinalFragmet);
typedef RTS_RESULT (CDECL * PFWSCLIENTSEND) (RTS_HANDLE hClient, RTS_UI8* pSendData, RTS_SIZE dataSize, RTS_BOOL bBinaryMode, RTS_BOOL bFinalFragmet);
#if defined(CMPWEBSOCKETCLIENT_NOTIMPLEMENTED) || defined(WSCLIENTSEND_NOTIMPLEMENTED)
	#define USE_WsClientSend
	#define EXT_WsClientSend
	#define GET_WsClientSend(fl)  ERR_NOTIMPLEMENTED
	#define CAL_WsClientSend(p0,p1,p2,p3,p4)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_WsClientSend  FALSE
	#define EXP_WsClientSend  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_WsClientSend
	#define EXT_WsClientSend
	#define GET_WsClientSend(fl)  CAL_CMGETAPI( "WsClientSend" ) 
	#define CAL_WsClientSend  WsClientSend
	#define CHK_WsClientSend  TRUE
	#define EXP_WsClientSend  CAL_CMEXPAPI( "WsClientSend" ) 
#elif defined(MIXED_LINK) && !defined(CMPWEBSOCKETCLIENT_EXTERNAL)
	#define USE_WsClientSend
	#define EXT_WsClientSend
	#define GET_WsClientSend(fl)  CAL_CMGETAPI( "WsClientSend" ) 
	#define CAL_WsClientSend  WsClientSend
	#define CHK_WsClientSend  TRUE
	#define EXP_WsClientSend  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"WsClientSend", (RTS_UINTPTR)WsClientSend, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpWebSocketClientWsClientSend
	#define EXT_CmpWebSocketClientWsClientSend
	#define GET_CmpWebSocketClientWsClientSend  ERR_OK
	#define CAL_CmpWebSocketClientWsClientSend pICmpWebSocketClient->IWsClientSend
	#define CHK_CmpWebSocketClientWsClientSend (pICmpWebSocketClient != NULL)
	#define EXP_CmpWebSocketClientWsClientSend  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_WsClientSend
	#define EXT_WsClientSend
	#define GET_WsClientSend(fl)  CAL_CMGETAPI( "WsClientSend" ) 
	#define CAL_WsClientSend pICmpWebSocketClient->IWsClientSend
	#define CHK_WsClientSend (pICmpWebSocketClient != NULL)
	#define EXP_WsClientSend  CAL_CMEXPAPI( "WsClientSend" ) 
#else /* DYNAMIC_LINK */
	#define USE_WsClientSend  PFWSCLIENTSEND pfWsClientSend;
	#define EXT_WsClientSend  extern PFWSCLIENTSEND pfWsClientSend;
	#define GET_WsClientSend(fl)  s_pfCMGetAPI2( "WsClientSend", (RTS_VOID_FCTPTR *)&pfWsClientSend, (fl), 0, 0)
	#define CAL_WsClientSend  pfWsClientSend
	#define CHK_WsClientSend  (pfWsClientSend != NULL)
	#define EXP_WsClientSend  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"WsClientSend", (RTS_UINTPTR)WsClientSend, 0, 0) 
#endif




/**
 * <description>
 *	Call this function cyclically in a way of your needs. This function will process incoming packets, defragment them, finishes handshaking, etc.
 * </description>
 * <param name="hClient" type="IN">Handle to the WebSocket</param>
 * <param name="ui32Timeout" type="IN">Timeout used for SysSockSelect.</param>
 * <result>Error Code:
 *		- ERR_INVALID_HANDLE: The hClient is unknown.
 *		- ERR_OK: This is returned otherwise. To signal state changes the state change callback is used.
 * </result>
 */
RTS_RESULT CDECL WsClientProcess(RTS_HANDLE hClient, RTS_UI32 ui32Timeout);
typedef RTS_RESULT (CDECL * PFWSCLIENTPROCESS) (RTS_HANDLE hClient, RTS_UI32 ui32Timeout);
#if defined(CMPWEBSOCKETCLIENT_NOTIMPLEMENTED) || defined(WSCLIENTPROCESS_NOTIMPLEMENTED)
	#define USE_WsClientProcess
	#define EXT_WsClientProcess
	#define GET_WsClientProcess(fl)  ERR_NOTIMPLEMENTED
	#define CAL_WsClientProcess(p0,p1)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_WsClientProcess  FALSE
	#define EXP_WsClientProcess  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_WsClientProcess
	#define EXT_WsClientProcess
	#define GET_WsClientProcess(fl)  CAL_CMGETAPI( "WsClientProcess" ) 
	#define CAL_WsClientProcess  WsClientProcess
	#define CHK_WsClientProcess  TRUE
	#define EXP_WsClientProcess  CAL_CMEXPAPI( "WsClientProcess" ) 
#elif defined(MIXED_LINK) && !defined(CMPWEBSOCKETCLIENT_EXTERNAL)
	#define USE_WsClientProcess
	#define EXT_WsClientProcess
	#define GET_WsClientProcess(fl)  CAL_CMGETAPI( "WsClientProcess" ) 
	#define CAL_WsClientProcess  WsClientProcess
	#define CHK_WsClientProcess  TRUE
	#define EXP_WsClientProcess  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"WsClientProcess", (RTS_UINTPTR)WsClientProcess, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpWebSocketClientWsClientProcess
	#define EXT_CmpWebSocketClientWsClientProcess
	#define GET_CmpWebSocketClientWsClientProcess  ERR_OK
	#define CAL_CmpWebSocketClientWsClientProcess pICmpWebSocketClient->IWsClientProcess
	#define CHK_CmpWebSocketClientWsClientProcess (pICmpWebSocketClient != NULL)
	#define EXP_CmpWebSocketClientWsClientProcess  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_WsClientProcess
	#define EXT_WsClientProcess
	#define GET_WsClientProcess(fl)  CAL_CMGETAPI( "WsClientProcess" ) 
	#define CAL_WsClientProcess pICmpWebSocketClient->IWsClientProcess
	#define CHK_WsClientProcess (pICmpWebSocketClient != NULL)
	#define EXP_WsClientProcess  CAL_CMEXPAPI( "WsClientProcess" ) 
#else /* DYNAMIC_LINK */
	#define USE_WsClientProcess  PFWSCLIENTPROCESS pfWsClientProcess;
	#define EXT_WsClientProcess  extern PFWSCLIENTPROCESS pfWsClientProcess;
	#define GET_WsClientProcess(fl)  s_pfCMGetAPI2( "WsClientProcess", (RTS_VOID_FCTPTR *)&pfWsClientProcess, (fl), 0, 0)
	#define CAL_WsClientProcess  pfWsClientProcess
	#define CHK_WsClientProcess  (pfWsClientProcess != NULL)
	#define EXP_WsClientProcess  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"WsClientProcess", (RTS_UINTPTR)WsClientProcess, 0, 0) 
#endif




/**
 * <description>
 *	Function to retrieve a pointer to the header of the initial HTTP response.
 *	Can only be called in the context of the callback PFSTATECHANGECLALLBACK during the state WsClientState_InConnect_InitialResponseReceived.
 * </description>
 * <param name="hClient" type="IN">Handle to the WebSocket</param>
 * <param name="ppHeader" type="OUT">Pointer to Pointer to the retrieved HTTP header</param>
 * <result>Error Code:
 *		- ERR_INVALID_HANDLE: The hClient is unknown.
 *		- ERR_PARAMETER: ppHeader is NULL.
 *		- ERR_INVALID_STATE: The client is not in the state WsClientState_InConnect_InitialResponseReceived.
 *		- ERR_OK: The HTTP header has been successfully retrieved.
 * </result>
 */
RTS_RESULT CDECL WsClientGetHttpHeader(RTS_HANDLE hClient, RTS_UI8 **ppHeader);
typedef RTS_RESULT (CDECL * PFWSCLIENTGETHTTPHEADER) (RTS_HANDLE hClient, RTS_UI8 **ppHeader);
#if defined(CMPWEBSOCKETCLIENT_NOTIMPLEMENTED) || defined(WSCLIENTGETHTTPHEADER_NOTIMPLEMENTED)
	#define USE_WsClientGetHttpHeader
	#define EXT_WsClientGetHttpHeader
	#define GET_WsClientGetHttpHeader(fl)  ERR_NOTIMPLEMENTED
	#define CAL_WsClientGetHttpHeader(p0,p1)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_WsClientGetHttpHeader  FALSE
	#define EXP_WsClientGetHttpHeader  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_WsClientGetHttpHeader
	#define EXT_WsClientGetHttpHeader
	#define GET_WsClientGetHttpHeader(fl)  CAL_CMGETAPI( "WsClientGetHttpHeader" ) 
	#define CAL_WsClientGetHttpHeader  WsClientGetHttpHeader
	#define CHK_WsClientGetHttpHeader  TRUE
	#define EXP_WsClientGetHttpHeader  CAL_CMEXPAPI( "WsClientGetHttpHeader" ) 
#elif defined(MIXED_LINK) && !defined(CMPWEBSOCKETCLIENT_EXTERNAL)
	#define USE_WsClientGetHttpHeader
	#define EXT_WsClientGetHttpHeader
	#define GET_WsClientGetHttpHeader(fl)  CAL_CMGETAPI( "WsClientGetHttpHeader" ) 
	#define CAL_WsClientGetHttpHeader  WsClientGetHttpHeader
	#define CHK_WsClientGetHttpHeader  TRUE
	#define EXP_WsClientGetHttpHeader  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"WsClientGetHttpHeader", (RTS_UINTPTR)WsClientGetHttpHeader, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpWebSocketClientWsClientGetHttpHeader
	#define EXT_CmpWebSocketClientWsClientGetHttpHeader
	#define GET_CmpWebSocketClientWsClientGetHttpHeader  ERR_OK
	#define CAL_CmpWebSocketClientWsClientGetHttpHeader pICmpWebSocketClient->IWsClientGetHttpHeader
	#define CHK_CmpWebSocketClientWsClientGetHttpHeader (pICmpWebSocketClient != NULL)
	#define EXP_CmpWebSocketClientWsClientGetHttpHeader  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_WsClientGetHttpHeader
	#define EXT_WsClientGetHttpHeader
	#define GET_WsClientGetHttpHeader(fl)  CAL_CMGETAPI( "WsClientGetHttpHeader" ) 
	#define CAL_WsClientGetHttpHeader pICmpWebSocketClient->IWsClientGetHttpHeader
	#define CHK_WsClientGetHttpHeader (pICmpWebSocketClient != NULL)
	#define EXP_WsClientGetHttpHeader  CAL_CMEXPAPI( "WsClientGetHttpHeader" ) 
#else /* DYNAMIC_LINK */
	#define USE_WsClientGetHttpHeader  PFWSCLIENTGETHTTPHEADER pfWsClientGetHttpHeader;
	#define EXT_WsClientGetHttpHeader  extern PFWSCLIENTGETHTTPHEADER pfWsClientGetHttpHeader;
	#define GET_WsClientGetHttpHeader(fl)  s_pfCMGetAPI2( "WsClientGetHttpHeader", (RTS_VOID_FCTPTR *)&pfWsClientGetHttpHeader, (fl), 0, 0)
	#define CAL_WsClientGetHttpHeader  pfWsClientGetHttpHeader
	#define CHK_WsClientGetHttpHeader  (pfWsClientGetHttpHeader != NULL)
	#define EXP_WsClientGetHttpHeader  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"WsClientGetHttpHeader", (RTS_UINTPTR)WsClientGetHttpHeader, 0, 0) 
#endif




/**
 * <description>
 *	Function to store a cookie to be sent with the initial HTTP request.
 * </description>
 * <param name="hClient" type="IN">Handle to the WebSocket</param>
 * <param name="pCookieName" type="IN">Name of the cookie</param>
 * <param name="pCookieValue" type="IN">Value of the cookie</param>
 * <result>Error Code:
 *		- ERR_INVALID_HANDLE: The hClient is unknown.
 *		- ERR_PARAMETER: pCookieName or pCookieValue is NULL.
 *		- ERR_NOMEMORY: No heap memory to store the cookie.
 *		- ERR_FAILED: An internal error occured storing the cookie into the internal websocket structure.
 *		- ERR_OK: The cookie has been successfully stored.
 * </result>
 */
RTS_RESULT CDECL WsClientSetCookie(RTS_HANDLE hClient, RTS_UI8 *pCookieName, RTS_UI8 *pCookieValue);
typedef RTS_RESULT (CDECL * PFWSCLIENTSETCOOKIE) (RTS_HANDLE hClient, RTS_UI8 *pCookieName, RTS_UI8 *pCookieValue);
#if defined(CMPWEBSOCKETCLIENT_NOTIMPLEMENTED) || defined(WSCLIENTSETCOOKIE_NOTIMPLEMENTED)
	#define USE_WsClientSetCookie
	#define EXT_WsClientSetCookie
	#define GET_WsClientSetCookie(fl)  ERR_NOTIMPLEMENTED
	#define CAL_WsClientSetCookie(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_WsClientSetCookie  FALSE
	#define EXP_WsClientSetCookie  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_WsClientSetCookie
	#define EXT_WsClientSetCookie
	#define GET_WsClientSetCookie(fl)  CAL_CMGETAPI( "WsClientSetCookie" ) 
	#define CAL_WsClientSetCookie  WsClientSetCookie
	#define CHK_WsClientSetCookie  TRUE
	#define EXP_WsClientSetCookie  CAL_CMEXPAPI( "WsClientSetCookie" ) 
#elif defined(MIXED_LINK) && !defined(CMPWEBSOCKETCLIENT_EXTERNAL)
	#define USE_WsClientSetCookie
	#define EXT_WsClientSetCookie
	#define GET_WsClientSetCookie(fl)  CAL_CMGETAPI( "WsClientSetCookie" ) 
	#define CAL_WsClientSetCookie  WsClientSetCookie
	#define CHK_WsClientSetCookie  TRUE
	#define EXP_WsClientSetCookie  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"WsClientSetCookie", (RTS_UINTPTR)WsClientSetCookie, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpWebSocketClientWsClientSetCookie
	#define EXT_CmpWebSocketClientWsClientSetCookie
	#define GET_CmpWebSocketClientWsClientSetCookie  ERR_OK
	#define CAL_CmpWebSocketClientWsClientSetCookie pICmpWebSocketClient->IWsClientSetCookie
	#define CHK_CmpWebSocketClientWsClientSetCookie (pICmpWebSocketClient != NULL)
	#define EXP_CmpWebSocketClientWsClientSetCookie  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_WsClientSetCookie
	#define EXT_WsClientSetCookie
	#define GET_WsClientSetCookie(fl)  CAL_CMGETAPI( "WsClientSetCookie" ) 
	#define CAL_WsClientSetCookie pICmpWebSocketClient->IWsClientSetCookie
	#define CHK_WsClientSetCookie (pICmpWebSocketClient != NULL)
	#define EXP_WsClientSetCookie  CAL_CMEXPAPI( "WsClientSetCookie" ) 
#else /* DYNAMIC_LINK */
	#define USE_WsClientSetCookie  PFWSCLIENTSETCOOKIE pfWsClientSetCookie;
	#define EXT_WsClientSetCookie  extern PFWSCLIENTSETCOOKIE pfWsClientSetCookie;
	#define GET_WsClientSetCookie(fl)  s_pfCMGetAPI2( "WsClientSetCookie", (RTS_VOID_FCTPTR *)&pfWsClientSetCookie, (fl), 0, 0)
	#define CAL_WsClientSetCookie  pfWsClientSetCookie
	#define CHK_WsClientSetCookie  (pfWsClientSetCookie != NULL)
	#define EXP_WsClientSetCookie  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"WsClientSetCookie", (RTS_UINTPTR)WsClientSetCookie, 0, 0) 
#endif




/**
 * <description>
 *	Function to configure a proxy server for the connection.
 * </description>
 * <param name="hClient" type="IN">Handle to the WebSocket</param>
 * <param name="pProxy" type="IN">Pointer to the proxy description (see definition of WsClientProxy)</param>
 * <result>Error Code:
 *		- ERR_INVALID_HANDLE: The hClient is unknown.
 *		- ERR_PARAMETER: pProxy is NULL.
 *		- ERR_OK: The proxy configuration has been set successfully.
 * </result>
 */
RTS_RESULT CDECL WsClientSetProxy(RTS_HANDLE hClient, WsClientProxy *pProxy);
typedef RTS_RESULT (CDECL * PFWSCLIENTSETPROXY) (RTS_HANDLE hClient, WsClientProxy *pProxy);
#if defined(CMPWEBSOCKETCLIENT_NOTIMPLEMENTED) || defined(WSCLIENTSETPROXY_NOTIMPLEMENTED)
	#define USE_WsClientSetProxy
	#define EXT_WsClientSetProxy
	#define GET_WsClientSetProxy(fl)  ERR_NOTIMPLEMENTED
	#define CAL_WsClientSetProxy(p0,p1)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_WsClientSetProxy  FALSE
	#define EXP_WsClientSetProxy  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_WsClientSetProxy
	#define EXT_WsClientSetProxy
	#define GET_WsClientSetProxy(fl)  CAL_CMGETAPI( "WsClientSetProxy" ) 
	#define CAL_WsClientSetProxy  WsClientSetProxy
	#define CHK_WsClientSetProxy  TRUE
	#define EXP_WsClientSetProxy  CAL_CMEXPAPI( "WsClientSetProxy" ) 
#elif defined(MIXED_LINK) && !defined(CMPWEBSOCKETCLIENT_EXTERNAL)
	#define USE_WsClientSetProxy
	#define EXT_WsClientSetProxy
	#define GET_WsClientSetProxy(fl)  CAL_CMGETAPI( "WsClientSetProxy" ) 
	#define CAL_WsClientSetProxy  WsClientSetProxy
	#define CHK_WsClientSetProxy  TRUE
	#define EXP_WsClientSetProxy  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"WsClientSetProxy", (RTS_UINTPTR)WsClientSetProxy, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpWebSocketClientWsClientSetProxy
	#define EXT_CmpWebSocketClientWsClientSetProxy
	#define GET_CmpWebSocketClientWsClientSetProxy  ERR_OK
	#define CAL_CmpWebSocketClientWsClientSetProxy pICmpWebSocketClient->IWsClientSetProxy
	#define CHK_CmpWebSocketClientWsClientSetProxy (pICmpWebSocketClient != NULL)
	#define EXP_CmpWebSocketClientWsClientSetProxy  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_WsClientSetProxy
	#define EXT_WsClientSetProxy
	#define GET_WsClientSetProxy(fl)  CAL_CMGETAPI( "WsClientSetProxy" ) 
	#define CAL_WsClientSetProxy pICmpWebSocketClient->IWsClientSetProxy
	#define CHK_WsClientSetProxy (pICmpWebSocketClient != NULL)
	#define EXP_WsClientSetProxy  CAL_CMEXPAPI( "WsClientSetProxy" ) 
#else /* DYNAMIC_LINK */
	#define USE_WsClientSetProxy  PFWSCLIENTSETPROXY pfWsClientSetProxy;
	#define EXT_WsClientSetProxy  extern PFWSCLIENTSETPROXY pfWsClientSetProxy;
	#define GET_WsClientSetProxy(fl)  s_pfCMGetAPI2( "WsClientSetProxy", (RTS_VOID_FCTPTR *)&pfWsClientSetProxy, (fl), 0, 0)
	#define CAL_WsClientSetProxy  pfWsClientSetProxy
	#define CHK_WsClientSetProxy  (pfWsClientSetProxy != NULL)
	#define EXP_WsClientSetProxy  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"WsClientSetProxy", (RTS_UINTPTR)WsClientSetProxy, 0, 0) 
#endif




#ifdef __cplusplus
}
#endif



typedef struct
{
	IBase_C *pBase;
	PFWSCLIENTCREATE IWsClientCreate;
 	PFWSCLIENTDELETE IWsClientDelete;
 	PFWSCLIENTCONNECT IWsClientConnect;
 	PFWSCLIENTDISCONNECT IWsClientDisconnect;
 	PFWSCLIENTSEND IWsClientSend;
 	PFWSCLIENTPROCESS IWsClientProcess;
 	PFWSCLIENTGETHTTPHEADER IWsClientGetHttpHeader;
 	PFWSCLIENTSETCOOKIE IWsClientSetCookie;
 	PFWSCLIENTSETPROXY IWsClientSetProxy;
 } ICmpWebSocketClient_C;

#ifdef CPLUSPLUS
class ICmpWebSocketClient : public IBase
{
	public:
		virtual RTS_HANDLE CDECL IWsClientCreate(RTS_SIZE bufferSize, char* pszUrl, char* pszProto, RTS_HANDLE hTlsContext, void* pUserData, PFDATARECEIVEDCALLBACK pfDataReceivedCallback, PFSTATECHANGECLALLBACK pfStateChangeCallback, RTS_RESULT *pResult) =0;
		virtual RTS_RESULT CDECL IWsClientDelete(RTS_HANDLE hClient) =0;
		virtual RTS_RESULT CDECL IWsClientConnect(RTS_HANDLE hClient) =0;
		virtual RTS_RESULT CDECL IWsClientDisconnect(RTS_HANDLE hClient, WebSocketStatus statusCode) =0;
		virtual RTS_RESULT CDECL IWsClientSend(RTS_HANDLE hClient, RTS_UI8* pSendData, RTS_SIZE dataSize, RTS_BOOL bBinaryMode, RTS_BOOL bFinalFragmet) =0;
		virtual RTS_RESULT CDECL IWsClientProcess(RTS_HANDLE hClient, RTS_UI32 ui32Timeout) =0;
		virtual RTS_RESULT CDECL IWsClientGetHttpHeader(RTS_HANDLE hClient, RTS_UI8 **ppHeader) =0;
		virtual RTS_RESULT CDECL IWsClientSetCookie(RTS_HANDLE hClient, RTS_UI8 *pCookieName, RTS_UI8 *pCookieValue) =0;
		virtual RTS_RESULT CDECL IWsClientSetProxy(RTS_HANDLE hClient, WsClientProxy *pProxy) =0;
};
	#ifndef ITF_CmpWebSocketClient
		#define ITF_CmpWebSocketClient static ICmpWebSocketClient *pICmpWebSocketClient = NULL;
	#endif
	#define EXTITF_CmpWebSocketClient
#else	/*CPLUSPLUS*/
	typedef ICmpWebSocketClient_C		ICmpWebSocketClient;
	#ifndef ITF_CmpWebSocketClient
		#define ITF_CmpWebSocketClient
	#endif
	#define EXTITF_CmpWebSocketClient
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_CMPWEBSOCKETCLIENTITF_H_*/
