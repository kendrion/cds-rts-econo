/**
 * <interfacename>CmpGateway</interfacename>
 * <description>
 *	Interface of the gateway
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`CmpGateway')

REF_ITF(`CmpRouterItf.m4')

#ifdef __cplusplus
extern "C" {
#endif


/**
* <category>Settings</category>
* <type>Int</type>
* <description>
*	Setting to modify the client inactivity timeout in ms. 
*	If no piece of data (also no keep alive) is received or successfully sent within this time, the Gateway closes the connection to the client.
* </description>
*/
#define GATEWAYKEY_INT_INACTIVITY_TIMEOUT					"InactivityTimeoutMs"
#ifndef GATEWAYKEY_INT_INACTIVITY_TIMEOUT_DEFAULT
	#define GATEWAYKEY_INT_INACTIVITY_TIMEOUT_DEFAULT		60000
#endif

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>
 *	The port the gateway will be reachable via the CmpGwCommDrvTcp.
 * 	Note: Set this setting in section [CmpGwCommDrvTcp]
 * </description>
 */
#define GWCOMMDRVTCPKEY_INT_LOCALPORT							"ListenPort"
#ifndef GWCOMMDRVTCPVALUE_INT_LOCALPORT_DEFAULT
	#define GWCOMMDRVTCPVALUE_INT_LOCALPORT_DEFAULT				1217
#endif

/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>
 *	IP address which will be used to bind the gateway. 
 *		- Use a valid IP address (of any adapter) to allow access only from a specific subnet.
 *		- Use 0.0.0.0 to allow access from any remote computer.
 *		- User 127.0.0.1 to allow access only from the local machine.
 * Note: Set this setting in section [CmpGwCommDrvTcp]
 * Note: On windows machines setting this to 127.0.0.1 is recommended if the gateway is used as edge gatway.
 * </description>
 */
#define GWCOMMDRVTCPKEY_STRING_LOCALADDRESS						"LocalAddress"
#ifndef GWCOMMDRVTCPVALUE_STRING_LOCALADDRESS_DEFAULT
	#define GWCOMMDRVTCPVALUE_STRING_LOCALADDRESS_DEFAULT		"0.0.0.0"
#endif

/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>
 *	This setting is used to restrict the access to the Gateway via GwCommDrvTcp to a specific peer or
 *	subnet. This setting has the following behavior:
 *		1. When set to specific peer address: Allow access only to the peer that has that IP address.
 *		2. When set to the network base address: Allows access to all peers of this subnet.
 *		3. Setting not available: Allow any peer to connect.
 * Note: Set this setting in section [CmpGwCommDrvTcp]
 * </description>
 */
#define GWCOMMDRVTCPKEY_STRING_PEERADDRESS						"PeerAddress"


/* -- Functions exported by communication drivers to the Gateway -- */

/* Send data on a connection. If not all of the data could be sent, the number of bytes 
   sent is returned in pdwSent and the function has to be called again later with the remaining
   bytes. 
   NOTE: This function must not block and it must not call any functions of the 
         gateway, since this may lead to deadlocks.
   hConnHandle    IN  identifies the connection.
   data           IN  The data to be sent
   pdwSent        OUT The number of bytes the could actually be sent.

   RETURNS: 
	ERR_NOTCONNECTED if the provided connection handle is not connected.
*/
typedef RTS_RESULT (CDECL *PFCOMMDRVSEND)(RTS_HANDLE hConnHandle, PROTOCOL_DATA_UNIT data, RTS_UI32 *pdwSent);

/* Receive data from an existent connection. 
   NOTE: This function must not block and it must not call any functions of the 
         gateway, since this may lead to deadlocks.
   hConnHandle  IN    identifies the connection
   pData        INOUT 
       .pData  (IN) Provides a buffer for the received data.
	   .nCount (IN) Size of the buffer. (OUT) Number of bytes actually received.
*/
typedef RTS_RESULT (CDECL *PFCOMMDRVRECEIVE)(RTS_HANDLE hConnHandle, PROTOCOL_DATA_UNIT *pData);

/* Close a connection 
   NOTE: This function must not block and it must not call any functions of the 
         gateway, since this may lead to deadlocks.
*/
typedef RTS_RESULT (CDECL *PFCOMMDRVCLOSE)(RTS_HANDLE hConnHandle);

/* -- Functions exported to communication drivers -- */

typedef struct
{
	PFCOMMDRVSEND    pfSend;
	PFCOMMDRVRECEIVE pfReceive;
	PFCOMMDRVCLOSE   pfClose;
} COMMDRVINFO;

/* Called by a gateway communication driver to register 
   with the gateway. 
   pInfo          IN  Contains function pointers to the comm driver API.
   phDriverHandle OUT Set to a unique value for the comm driver. The driver must provide
                      the assigned value in all other calls to the gateway functions 
				      in order to identify itself.
*/
DEF_ITF_API(`RTS_RESULT',`CDECL',`GWRegisterCommDrv',`(COMMDRVINFO *pInfo, RTS_HANDLE *phDriverHandle)')

enum
{
	COMMDRV_ACTION_SEND = 0,
	COMMDRV_ACTION_RECEIVE = 1
};

/**
 * <description>
 *  May be called by a commdriver if a connection is ready to send/receive.
 *  This function shall not signal a condition more then once without the 
 *  gateway reacting to that signal.
 *  Eg. if the commdriver signals that a connection is ready to send it shall not
 *  signal this situation again before the gateway actually called "send".
 *  The gwclient must not rely on this function to be called but may use 
 *  it to increase the performance of the connection.
 * </description>
 * <param name="hDriverHandle" type="IN">
 *  The driver handle returned by GWRegisterCommDrv.
 * </param>
 * <param name="hConnHandle" type="IN">
 *  The handle to the connection.
 * </param>
 * <param name="nAction" type="IN">
 *  The action that is ready on this connection - e.g. COMMDRV_ACTION_SEND, COMMDRV_ACTION_RECEIVE
 * </param>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`GWConnectionReady',`(RTS_HANDLE hDriverHandle, RTS_HANDLE hConnHandle, RTS_I32 nAction)')

/* Called when a client connects. If anything else then ERR_OK is returned
   the communication driver should close the connection immediately.
   hDriverHandle   IN  The value assigned during GWRegisterCommDrv.
   hConnHandle     IN  A handle identifying the new connection.
*/
DEF_ITF_API(`RTS_RESULT',`CDECL',`GWClientConnect',`(RTS_HANDLE hDriverHandle, RTS_HANDLE hConnHandle)')

/* Called when a client connection has been disconnected.
   hDriverHandle   IN  The value assigned during GWRegisterCommDrv.
   hConnHandle     IN  A handle identifying the disconnected connection. 
*/
DEF_ITF_API(`RTS_RESULT',`CDECL',`GWClientDisconnect',`(RTS_HANDLE hDriverHandle, RTS_HANDLE hConnHandle)')

#ifdef __cplusplus
}
#endif
