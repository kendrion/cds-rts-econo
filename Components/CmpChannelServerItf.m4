/**
 * <interfacename>CmpChannelServer</interfacename>
 * <description>
 *	Interface for the channel server.
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`CmpChannelServer')

REF_ITF(`CmpChannelMgrItf.m4')
REF_ITF(`CmpEventMgrItf.m4')


/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>
 *	Defines the available overall amount of memory to be used by all channels.
 *	Since each channel needs separate send and receive buffers for each channel the available 
 *  communication buffer per channel is BUFFERSIZE / (2*MAXCHANNELS).
 * </description>
 */
#define CHANNELSERVERKEY_INT_BUFFERSIZE								"BufferSize"
#ifndef CHANNELSERVERVALUE_INT_BUFFERSIZE_DEFAULT		
	#define CHANNELSERVERVALUE_INT_BUFFERSIZE_DEFAULT					NETSERVER_BUFFERSIZE
#endif

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>
 *	Number of communication channels (concurrently client connections).  
 * </description>
 */
#define CHANNELSERVERKEY_INT_MAXCHANNELS							"MaxChannels"
#ifndef CHANNELSERVERVALUE_INT_MAXCHANNELS_DEFAULT		
	#define CHANNELSERVERVALUE_INT_MAXCHANNELS_DEFAULT					NETSERVER_MAXCHANNELS
#endif

 /**
 * <category>Static defines</category>
 * <description>Special channel numbers.</description>
 */
#define CHANNELSERVER_INVALID_CHANNEL_ID							RTS_UI16_MAX
#define CHANNELSERVER_WEBSERVER_STATIC_CHANNEL_ID					(RTS_UI16_MAX-1)
#define CHANNELSERVER_REDUNDANCY_STATIC_CHANNEL_ID					(RTS_UI16_MAX-2)
#define CHANNELSERVER_MAX_DYNAMIC_CHANNEL_ID						(RTS_UI16_MAX-3)


/* -- Events triggered by the channel server. -- */

/**
 * <category>Event parameter</category>
 * <element name="ulChannelHandle" type="IN">
 *   The channel handle is always a combination of two words (16 bit).
 *   The low word (ulChannelHandle masked with 0xFFFF) is the id of 
 *   the "physical" channel. The highword is the id of the client using this channel
 *   (multiple clients may use the same channel in a round robin manner).
 *   A highword of 0xFFFF indicates, that the channel is completely closed
 *   and all clients have disconnected. In all other cases the channel is still
 *   open, only that client has disconnected.
 *   When attaching any resources to a specific channel (e.g. open files, logins, ...)
 *   the component should release the resource when the client detaches as
 *   well as release all clients resources when the channel is completely closed.
 * </element>
 * <element name="errReason" type="IN">
 *	  An error code describing the reason for closing the channel 
 * </element>
 */
typedef struct
{
	RTS_UI32   ulChannelHandle;
	RTS_RESULT  errReason;
} EVTPARAM_CmpChS_ChannelClosed;
#define EVTPARAMID_CmpChS_ChannelClosed 0x0001
#define EVTVERSION_CmpChS_ChannelClosed 0x0001

/* Used for compatibility reasons */
typedef EVTPARAM_CmpChS_ChannelClosed EVTPARAM_ChannelClosed;
#define EVTPARAMID_CmpChannelServer EVTPARAMID_CmpChS_ChannelClosed
#define EVTVERSION_CmpChannelServer EVTVERSION_CmpChS_ChannelClosed

/**
 * <category>Event parameter</category>
 * <element name="ulChannelHandle" type="IN">
 *   The channel handle is always a combination of two words (16 bit).
 *   The low word (ulChannelHandle masked with 0xFFFF) is the id of 
 *   the "physical" channel. The highword is the id of the client using this channel
 *   (multiple clients may use the same channel in a round robin manner).
 *   A highword of 0xFFFF indicates, that the channel is completely closed
 *   and all clients have disconnected. In all other cases the channel is still
 *   open, only that client has disconnected.
 *   When attaching any resources to a specific channel (e.g. open files, logins, ...)
 *   the component should release the resource when the client detaches as
 *   well as release all clients resources when the channel is completely closed.
 * </element>
 */
typedef struct
{
	RTS_UI32   ulChannelHandle;
} EVTPARAM_CmpChS_ChannelOpened;
#define EVTPARAMID_CmpChS_ChannelOpened 0x0002
#define EVTVERSION_CmpChS_ChannelOpened 0x0001

/**
 * <category>Events</category>
 * <description>Event is sent when a channel is closed.</description>
 * <param name="pEventParam" type="IN">EVTPARAM_CmpChS_ChannelClosed</param>
 */
#define EVT_ChSChannelClosed	MAKE_EVENTID(EVTCLASS_INFO, 1)

/**
 * <category>Events</category>
 * <description>Event is sent when a channel is closed.</description>
 * <param name="pEventParam" type="IN">EVTPARAM_CmpChS_ChannelOpened</param>
 */
#define EVT_ChSChannelOpened	MAKE_EVENTID(EVTCLASS_INFO, 2)

/**
 * <category>Events</category>
 * <description> Event is sent after the EVT_ChSChannelClosed has been sent. Is only used internal by CmpDevice 
 *   and must not be used by any other component (use EVT_ChSChannelClosed instead).</description>
 * <param name="pEventParam" type="IN">EVTPARAM_CmpChS_ChannelClosed</param>
 */
#define EVT_ChSChannelClosedDone	MAKE_EVENTID(EVTCLASS_INFO, 3)

/* -- Functions exported to the runtime system -- */

#ifdef __cplusplus
extern "C" {
#endif

/** 
 * <description>
 *   Retrieves the number of available server channels. 
 *   This is equal to the max. number of clients, which can be connected at the same time.  
 * </description>
 * <param name="pwMaxChannels" type="OUT">Number of of channels.</param>
 * <result>error code</result>
*/
DEF_ITF_API(`RTS_RESULT',`CDECL', `NetServerGetMaxChannels',`(RTS_UI16 *pwMaxChannels)')

/**
* <description>
*   Retrieves the max. size of the send and receive buffer of the communication channels. 
*   This size cannot be exceeded by any online service or service reply.
* </description>
* <param name="pi32MaxChannelBufferSize" type="OUT">Max. size of each communication buffer.</param>
* <result>error code</result>
*/
DEF_ITF_API(`RTS_RESULT',`CDECL', `NetServerGetMaxChannelBufferSize',`(RTS_I32 *pi32MaxChannelBufferSize)')

/** 
 * <description>
 *   OBSOLETE: Function will be removed in future versions!!! Use NetServerGetChannelInfoByIndex2 instead. 
 *   Retrieves general information for the specified server channel. This function is intended for information purposes only.
 * </description>
 * <param name="ui16ChannelIndex" type="IN">Index of the channel. Allowed range: 0..MaxChannels-1.</param>
 * <param name="pui32ServerState" type="OUT">State of the server channel, see category "channel server state" for CSSTATE_ values in CmpCommunicationLibItf.</param>
 * <param name="pChInfoBuffer" type="INOUT">Caller allocated buffer, to which the content of the internal channel buffer structure is copied to.</param>
 * <param name="psiBufferLen" type="INOUT">Pointer to the size of the buffer in bytes, returns the number of copied bytes.</param>
 * <result>error code</result>
*/
DEF_ITF_API(`RTS_RESULT',`CDECL', `NetServerGetChannelInfoByIndex',`(RTS_UI16 ui16ChannelIndex, RTS_UI32 *pui32ServerState, CHANNELBUFFER *pChInfoBuffer, RTS_SIZE *psiBufferLen)')

/**
* <description>
*   Retrieves general information for the specified server channel. This function is intended for information purposes only.
* </description>
* <param name="ui16ChannelIndex" type="IN">Index of the channel. Allowed range: 0..MaxChannels-1.</param>
* <param name="pui32ServerState" type="OUT">State of the server channel, see category "channel server state" for CSSTATE_ values in CmpCommunicationLibItf.</param>
* <param name="pChInfoBuffer" type="INOUT">Caller allocated buffer, which is filled by the CHANNELINFO structure. If the the state is CSSTATE_FREE, no structure is returned.</param>
* <param name="psiBufferLen" type="INOUT">Pointer to the size of the buffer in bytes, returns the number of copied bytes.</param>
* <result>error code</result>
*/
DEF_ITF_API(`RTS_RESULT',`CDECL', `NetServerGetChannelInfoByIndex2',`(RTS_UI16 ui16ChannelIndex, RTS_UI32 *pui32ServerState, CHANNELINFO *pChInfoBuffer, RTS_SIZE *psiBufferLen)')

/**
 *	<description>
 *		Get the current status of an active channel.
 *	</description>
 *	<param name="wChannelHandle" type="IN"> 
 *		Id of the channel
 *	</param>
 *	<param name="pusStatus" type="OUT">
 *		Is set to the current progress state. The PROGRESS_xxx constants define valid values.
 *	</param>
 *  <param name="pbyScalingFactor" type="OUT">
 *		Provides the scaling factor for pnItemsComplete and pnTotalItems. These values have been scaled
 *		down by dividing them through 2^ScalingFactor 
 *		(i.e. they have been right shifted by ScalingFactor bits).
 *  </param>
 *	<param name="pnItemsComplete" type="OUT">
 *		Number of items completed (eg. the number of bytes transfered).
 *  </param>
 * 	<param name="pnTotalItems" type="OUT">
 *		Total number of item. Is set to -1 if unknown.
 *  </param> 
 *  <result>error code</result>
 */ 
DEF_ITF_API(`RTS_RESULT',`CDECL',`NetServerGetStatus',`(RTS_UI32 ulChannelHandle, RTS_UI16 *pusStatus, RTS_UI8 *pbyScalingFactor, RTS_I32 *pnItemsComplete, RTS_I32 *pnTotalItems)')

/**
* <description>
*   Retrieves the current request and reply buffer.
* </description>
* <param name="ulChannelHandle" type="IN">Id of the channel for which the session id should be read.</param>
* <param name="ppduRequest" type="INOUT">Caller allocated PDU to be filled with pointer and length of the received request.</param>
* <param name="ppduReplyBuffer" type="INOUT">Caller allocated PDU to be filled with pointer and length of the reply.</param>
* <result>error code</result>
*/
DEF_ITF_API(`RTS_RESULT',`CDECL', `NetServerGetRequest',`(RTS_UI32 ulChannelHandle, PROTOCOL_DATA_UNIT * ppduRequest, PROTOCOL_DATA_UNIT * ppduReplyBuffer)')

/**
* <description>
*   Commits the filled reply buffer to the channel and triggers sending the reply.
* </description>
* <param name="ulChannelHandle" type="IN">Id of the channel for which the session id should be read.</param>
* <param name="pduData" type="IN">Pointer to the reply buffer</param>
* <result>error code</result>
*/
DEF_ITF_API(`RTS_RESULT',`CDECL', `NetServerFinishRequest',`(RTS_UI32 ulChannelHandle, PROTOCOL_DATA_UNIT pduData)')


/* -- Functions exported to the L4Base network component -- */

/** 
 * <description>
 *   Get the buffer for the specified channel id. 
 *
 *  NOTE:
 *  After usage the channel buffer MUST be released by
 *  calling NetServerReleaseChannel. Failing to do so will prevent the channel
 *  from being closed and the server will eventually run out of channels.
 *  Nevertheless, this function DOES NOT provide exclusive access to the channel.
 *  The L4Base component must use appropriate semaphores to ensure exclusive access.
 * </description>
 * <param name = "addrPeer" type="IN">The second endpoint of the channel</param>
 *  <param name="wChannelId" type = "IN">The id of the channel.</param>
 *  <param name="ppChBuffer" type = "OUT">Is set to the channel buffer, if the channel exists.</param>
*/
DEF_ITF_API(`int',`CDECL',`NetServerGetChannel',`(PEERADDRESS addrPeer, unsigned short wChannelId, CHANNELBUFFER **ppChBuffer)')

/**
 * <description>
 *   Release a channel buffer returned by NetServerGetChannel. This buffer may not be used
 *   after calling this function. Use NetServerGetChannel to acquire access to this channel again.
 * </description>
 * <param name="pChBuffer" type = "IN">The channel buffer to release</param>
*/
DEF_ITF_API(`int',`CDECL',`NetServerReleaseChannel',`(CHANNELBUFFER *pChBuffer)')

/* Called by the L4Base component each time a meta-request arrives. The server is
   responsible for handling all meta-requests. 
   addrSender IN  The sender of the request
   pduData    IN  The request itself
*/
DEF_ITF_API(`int',`CDECL',`NetServerHandleMetaRequest',`(RTS_HANDLE hRouter, PEERADDRESS addrSender, PROTOCOL_DATA_UNIT pduData)')

/* Calls the pfChannelHandler once for each active server channel 
   pfChannelHandler IN     Function to be called for each channel
   pParam           IN/OUT This parameter is passed to pfChannelHandler.
*/
DEF_ITF_API(`void',`CDECL',`NetServerForEachChannel',`(PFCHANNELHANDLER pfChannelHandler, void * pParam)')

/**
 * <description>Obsolete: Use NetServerMessageReceived3 instead. Will be removed in future versions!</description>
 */
DEF_ITF_API(`int',`CDECL',`NetServerMessageReceived',`(CHANNELBUFFER *pChBuffer, PROTOCOL_DATA_UNIT pduData)')

/**
 * <description>Obsolete: Use NetServerMessageReceived3 instead. Will be removed in future versions!</description>
 */
DEF_ITF_API(`int',`CDECL',`NetServerMessageReceived2',`(RTS_HANDLE hRouter, CHANNELBUFFER *pChBuffer, PROTOCOL_DATA_UNIT pduData)')

/**
 * <description>Called by the L4Base component whenever a complete L7 message arrived on a server channel</description>
 * <param name="pChBuffer" type="IN">Pointer to the channel buffer</param>
 * <param name="pduData" type="IN">Content of the message. The data pointed to by will be valid only until 
 *  the reply has been passed to channel manager or the channel is closed.</param>
 * <param name="bFirstCall" type="IN">0: Tells the function, if it was already called for the same request before (0) or not (1).</param>
 * <errorcode name="RTS_RESULT Result" type="ERR_OK">Received service was completely handled.</errorcode>
 * <errorcode name="RTS_RESULT Result" type="ERR_PENDING">Received service will be handled asynchronously by the higher layers, 
 * but the caller has not to take care about this.</errorcode>
 * <errorcode name="RTS_RESULT Result" type="ERR_CALL_AGAIN">Received service will be handled asynchronously. 
 * To progress this function have to be called again for the same received service data with bFirstCall=0.</errorcode>
 * <errorcode name="RTS_RESULT Result" type="ERR_FAILED">Error occurred, channel close has been triggered.</errorcode>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`NetServerMessageReceived3',`(CHANNELBUFFER *pChBuffer, PROTOCOL_DATA_UNIT pduData, RTS_UI32 bFirstCall)')

/* Called when a unrecoverable error occurs for pfChBuffer, eg. ERR_CHANNEL_BROKEN.
   The channel must be closed by the net server.
	pChBuffer  IN
	nError     IN  The error 
*/
DEF_ITF_API(`int',`CDECL',`NetServerChannelError',`(CHANNELBUFFER *pChBuffer, int nError)')

#ifdef __cplusplus
}
#endif
