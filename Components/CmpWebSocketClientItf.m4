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

SET_INTERFACE_NAME(`CmpWebSocketClient')

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
DEF_ITF_API(`RTS_HANDLE',`CDECL',`WsClientCreate',`(RTS_SIZE bufferSize, char* pszUrl, char* pszProto, RTS_HANDLE hTlsContext, void* pUserData, PFDATARECEIVEDCALLBACK pfDataReceivedCallback, PFSTATECHANGECLALLBACK pfStateChangeCallback, RTS_RESULT *pResult)')

/**
 * <description>
 *	Delete a WebSocket client.
 * </description>
 * <param name="hSocket" type="IN">Handle to the WebSocket</param>
 * <result>Either ERR_OK or ERR_INVALID_HANDLE in case hClient is unknown.</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`WsClientDelete',`(RTS_HANDLE hClient)')

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
DEF_ITF_API(`RTS_RESULT',`CDECL',`WsClientConnect',`(RTS_HANDLE hClient)')

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
DEF_ITF_API(`RTS_RESULT',`CDECL',`WsClientDisconnect',`(RTS_HANDLE hClient, WebSocketStatus statusCode)')

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
DEF_ITF_API(`RTS_RESULT',`CDECL',`WsClientSend',`(RTS_HANDLE hClient, RTS_UI8* pSendData, RTS_SIZE dataSize, RTS_BOOL bBinaryMode, RTS_BOOL bFinalFragmet)')

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
DEF_ITF_API(`RTS_RESULT',`CDECL',`WsClientProcess',`(RTS_HANDLE hClient, RTS_UI32 ui32Timeout)')

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
DEF_ITF_API(`RTS_RESULT',`CDECL',`WsClientGetHttpHeader',`(RTS_HANDLE hClient, RTS_UI8 **ppHeader)')

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
DEF_ITF_API(`RTS_RESULT',`CDECL',`WsClientSetCookie',`(RTS_HANDLE hClient, RTS_UI8 *pCookieName, RTS_UI8 *pCookieValue)')

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
DEF_ITF_API(`RTS_RESULT',`CDECL',`WsClientSetProxy',`(RTS_HANDLE hClient, WsClientProxy *pProxy)')

#ifdef __cplusplus
}
#endif
