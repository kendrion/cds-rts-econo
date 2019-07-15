/**
 * <interfacename>CmpSecureChannel</interfacename>
 * <description> 
 *	Interface for a secure channel implementation to provide a secure (TLS based) channel on top of a communication channel.
 *  In the communication stack of the CODESYS runtime system the implementation of this interface
 *  can be optionally called between CmpChannelServer and CmpSrv.
 * </description>
 *
 *  SECURITY-NOTE:
 *           The security manager must be linked statically to the runtime system core to prevent, that it cannot be removed or replaced by a malware!
 *
 * <copyright>
 * Copyright (c) 2017-2018 CODESYS GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`CmpSecureChannel')

REF_ITF(`CmpCommunicationLibItf.m4')
REF_ITF(`CmpSecurityManagerItf.m4')

#ifndef PLC_HANDLER
	#ifdef CMPSECURECHANNEL_EXTERNAL
		#error CmpSecureChannel must not be overloadable so defining CMPSECURECHANNEL_EXTERNAL is forbidden because of security requirements!
	#endif
#endif
	
/*
 * Header used for transmitting TLS related packets on the channel
 */

typedef struct
{
	RTS_UI16		ui16HeaderTag;		/* Header indicating protocol type */
	RTS_UI16		ui16HeaderLength;	/* Length of the header beginning at ulServiceLength */
	RTS_UI16		ui16ServiceGroup;	/* Not Used -> Set to 0 */
	RTS_UI16		ui16Service;		/* Not Used -> Set to 0 */
	RTS_UI32		ui32SessionID;		/* Not Used -> Set to 0 */
	RTS_UI32		ui32ServiceLength;	/* Length of the data following after this hader */
	RTS_UI32		ui32NumBlocks;		/* Number of TLS record protocol blocks following in this message */
	RTS_UI8			ui8MajorVersion;	/* Major Version of TLS protocol inside CDS */
	RTS_UI8			ui8MinorVersion;	/* Minor version of TLS protocol inside CDS */
	RTS_UI16		ui16Reserved;		/* Reserved have to be 0 */
} HEADER_TAG_CRYPT;


/**
 * <category>SecuritySettings</category>
 * <type>String</type>
 * <description>Communication mode to select, which kind of communication is possible.
 *	NOTE:
 *		Security modes must be ordered in an descending sorting, that the setting with the highest security level is found at the beginning of the list!
 * </description>
 */
#define CMPSECCHANNEL_KEY_STRING_ONLINECOMMMODE						CMPSETTINGS_CATEGORY_SECURITY ".CommunicationMode"
#define CMPSECCHANNEL_KEY_STRING_ONLINECOMMMODE_DESC				"Communication mode for online communication"

#define CMPSECCHANNEL_VALUE_ONLINECOMMMODE_ONLY_ENCRYPTED			"ONLY_ENCRYPTED"
#define CMPSECCHANNEL_VALUE_ONLINECOMMMODE_PLAIN_AND_ENCRYPTED		"PLAIN_AND_ENCRYPTED"
#define CMPSECCHANNEL_VALUE_ONLINECOMMMODE_ONLY_PLAIN				"ONLY_PLAIN"

#ifndef CMPSECCHANNEL_VALUE_ONLINECOMMMODE_DEFAULT
	#define CMPSECCHANNEL_VALUE_ONLINECOMMMODE_DEFAULT				CMPSECCHANNEL_VALUE_ONLINECOMMMODE_PLAIN_AND_ENCRYPTED
#endif

/**
 * <description>Security level for the programming system communication</description>
 * <element name="OnlineCommMode_ONLY_PLAIN" type="OUT">Only unencrypted communication supported</element>
 * <element name="OnlineCommMode_PLAIN_AND_ENCRYPTED" type="OUT">Encrypted and unencrypted communication supported. Can be decided by the online user</element>
 * <element name="OnlineCommMode_ONLY_ENCRYPTED" type="OUT">Only encrypted communication allowed</element>
 */
typedef enum
{
	OnlineCommMode_ONLY_PLAIN,
	OnlineCommMode_PLAIN_AND_ENCRYPTED,
	OnlineCommMode_ONLY_ENCRYPTED
} CMPSECURECHANNEL_ONLINECOMMMODE_IDS;

#define CMPSECCHANNEL_VALUE_ONLINECOMMMODE_LIST		{\
														{(RTS_I32)OnlineCommMode_ONLY_PLAIN, CMPSECMAN_SFLAGS_NONE, CMPSECCHANNEL_VALUE_ONLINECOMMMODE_ONLY_PLAIN, "Only encrypted communication allowed"},\
														{(RTS_I32)OnlineCommMode_PLAIN_AND_ENCRYPTED, CMPSECMAN_SFLAGS_NONE, CMPSECCHANNEL_VALUE_ONLINECOMMMODE_PLAIN_AND_ENCRYPTED, "Encrypted and unencrypted communication supported. Can be decided by the online user"},\
														{(RTS_I32)OnlineCommMode_ONLY_ENCRYPTED, CMPSECMAN_SFLAGS_NONE, CMPSECCHANNEL_VALUE_ONLINECOMMMODE_ONLY_ENCRYPTED, "Only unencrypted communication supported"}\
													}

			
/**
 * <category>SecuritySettings</category>
 * <description>Security setting to specify, if a selfsigned cert should be created by default if not available</description>
 */
#define CMPSECCHANNEL_KEY_STRING_CREATE_SELFSIGNED_CERT				SECURITY_KEY_STRING_CREATE_SELFSIGNED_CERT
#define CMPSECCHANNEL_KEY_STRING_CREATE_SELFSIGNED_CERT_DESC		SECURITY_KEY_STRING_CREATE_SELFSIGNED_CERT_DESC

#ifndef CMPSECCHANNEL_VALUE_CREATE_SELFSIGNED_CERT_DEFAULT
	#define CMPSECCHANNEL_VALUE_CREATE_SELFSIGNED_CERT_DEFAULT		SECURITY_VALUE_CREATE_SELFSIGNED_CERT_YES
#endif

#define CMPSECCHANNEL_VALUE_CREATE_SELFSIGNED_CERT_LIST				SECURITY_VALUE_CREATE_SELFSIGNED_CERT_LIST
																
/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>Hash of the last used certificate. This is used to restore an expired certificate after the systems reboot.
 * This setting is managed by the CmpSecureChannel and must not be set by hand.</description>
 */
#define CMPSECCHANNEL_KEY_STRING_CERTHASH			"CertificateHash"
#ifndef CMPSECCHANNEL_VALUE_CERTHASH_DEFAULT	
	#define CMPSECCHANNEL_VALUE_CERTHASH_DEFAULT	""
#endif

#ifdef __cplusplus
extern "C" {
#endif


/* -- Functions exported to the layer 4 network component. Only to be called by CmpChannelServer. -- */

/**
 * <description>Handle one sevice request from the communication layer below (channel server)</description>
 * <param name="ui32ChannelHandle" type="IN">Id of the channel on which the request arrived</param>
 * <param name="pduRequest" type="IN">Pointer to the request</param>
 * <param name="pduReply" type="OUT">Pointer to the request reply buffer</param>
 * <param name="bFirstCall" type="IN">0: Tells the function, if it was already called for the same request before (0) or not (1).</param>
 * <errorcode name="RTS_RESULT Result" type="ERR_OK">Received service was completely handeled.</errorcode>
 * <errorcode name="RTS_RESULT Result" type="ERR_PENDING">Received service will be handled asynchronously, 
 * but the caller has not to take care about this anymore.</errorcode>
 * <errorcode name="RTS_RESULT Result" type="ERR_CALL_AGAIN">Received service will be handled asynchronously. 
 * To progress this function have to be called again for the same received service data with bFirstCall=0.</errorcode>
 * <errorcode name="RTS_RESULT Result" type="ERR_...">Another error occured, channel should be closed.</errorcode>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SecChServerHandleRequest',`(RTS_UI32 ui32ChannelHandle, PROTOCOL_DATA_UNIT pduRequest, PROTOCOL_DATA_UNIT pduReply, RTS_UI32 bFirstCall)')



/* -- Functions exported to the layer 6 network component. Only to be called by CmpSrv. -- */

/**
* <description>
*   Retrieves the number of available server channels.
*   This is equal to the max. number of clients, which can be connected at the same time.
* </description>
* <param name="pui16MaxChannels" type="OUT">Number of of channels.</param>
* <result>error code</result>
*/
DEF_ITF_API(`RTS_RESULT',`CDECL', `SecChServerGetMaxChannels',`(RTS_UI16 *pui16MaxChannels)')

/**
* <description>
*   Retrieves general information for the specified server channel. This function is intended for information purpoeses only.
* </description>
* <param name="ui16ChannelIndex" type="IN">Index of the channel. Allowed range: 0..MaxChannels-1.</param>
* <param name="pui32ServerState" type="OUT">State of the server channel, see category "channel server state" for CSSTATE_ values in CmpCommunicationLibItf.</param>
* <param name="pChInfoBuffer" type="INOUT">Caller allocated buffer, which is filled by the CHANNELINFO structure. If the the state is CSSTATE_FREE, no structure is returned.</param>
* <param name="psiBufferLen" type="INOUT">Pointer to the size of the buffer in bytes, returns the number of copied bytes.</param>
* <result>error code</result>
*/
DEF_ITF_API(`RTS_RESULT',`CDECL', `SecChServerGetChannelInfoByIndex',`(RTS_UI16 ui16ChannelIndex, RTS_UI32 *pui32ServerState, CHANNELINFO *pChInfoBuffer, RTS_SIZE *psiBufferLen)')

/**
*	<description>
*		Get the current status of an active channel.
*	</description>
*	<param name="ui32ChannelHandle" type="IN">
*		Id of the channel
*	</param>
*	<param name="pui16Status" type="OUT">
*		Is set to the current progress state. The PROGRESS_xxx constants define valied values.
*	</param>
*  <param name="pui8ScalingFactor" type="OUT">
*		Provides the scaling factor for pnItemsComplete and pnTotalItems. These values have been scaled
*		down by dividing them through 2^ScalingFactor
*		(i.e. they have been right shifted by ScalingFactor bits).
*  </param>
*	<param name="pi32ItemsComplete" type="OUT">
*		Number of items completed (eg. the number of bytes transfered).
*  </param>
* 	<param name="pi32TotalItems" type="OUT">
*		Total number of item. Is set to -1 if unknown.
*  </param>
*  <result>error code</result>
*/
DEF_ITF_API(`RTS_RESULT',`CDECL',`SecChServerGetStatus',`(RTS_UI32 ui32ChannelHandle, RTS_UI16 *pui16Status, RTS_UI8 *pui8ScalingFactor, RTS_I32 *pi32ItemsComplete, RTS_I32 *pi32TotalItems)')

/**
* <description>
*   Retrieves the current request and reply buffer.
* </description>
* <param name="ui32ChannelHandle" type="IN">Id of the channel for which the session id should be read.</param>
* <param name="ppduRequest" type="INOUT">Caller allocated PDU to be filled with pointer and length of the received request.</param>
* <param name="ppduReplyBuffer" type="INOUT">Caller allocated PDU to be filled with pointer and length of the reply.</param>
* <result>error code</result>
*/
DEF_ITF_API(`RTS_RESULT',`CDECL', `SecChServerGetRequest',`(RTS_UI32 ui32ChannelHandle, PROTOCOL_DATA_UNIT *ppduRequest, PROTOCOL_DATA_UNIT *ppduReplyBuffer)')

/**
* <description>
*   Commits the filled reply buffer to the channel and triggers sending the reply.
* </description>
* <param name="ui32ChannelHandle" type="IN">Id of the channel for which the session id should be read.</param>
* <param name="pduData" type="IN">Pointer to the reply buffer</param>
* <result>error code</result>
*/
DEF_ITF_API(`RTS_RESULT',`CDECL', `SecChServerFinishRequest',`(RTS_UI32 ui32ChannelHandle, PROTOCOL_DATA_UNIT pduData)')

/**
* <description>
*   Stores the session id in the channel server status structure.
* </description>
* <param name="ui32ChannelHandle" type="IN">Id of the channel for which the session id should be set.</param>
* <param name="ui32SessionId" type="IN">New session id fo the channel.</param>
* <result>error code</result>
*/
DEF_ITF_API(`RTS_RESULT',`CDECL', `SecChServerSetSessionId',`(RTS_UI32 ui32ChannelHandle, RTS_UI32 ui32SessionId)')

/**
* <description>
*   Retrieves the stored session id from the channel server status structure.
* </description>
* <param name="ui32ChannelHandle" type="IN">Id of the channel for which the session id should be read.</param>
* <param name="pui32SessionId" type="OUT">Pointer to return the session id.</param>
* <result>error code</result>
*/
DEF_ITF_API(`RTS_RESULT',`CDECL', `SecChServerGetSessionId',`(RTS_UI32 ui32ChannelHandle, RTS_UI32 *pui32SessionId)')

/**
 * <description>
 *  Called by the CmpSecureChannel if data needs to be sent to the network.
 * </description>
 * <param name="pduData" type="IN">Data that has to be sent by the transport layer.</param>
 * <param name="pSendUserData" type="IN">User data given by SecChClientInit.</param>
 */
typedef RTS_RESULT(CDECL *PFSENDDATA)(PROTOCOL_DATA_UNIT pduData, void* pSendUserData);

/**
 * <description>
 *  Called by the CmpSecureChannel if decrypted data is available for processing.
 * </description>
 * <param name="pduData" type="IN">Decrypted data to be processed by the client.</param>
 * <param name="pReceiveUserData" type="IN">User data given by SecChClientInit.</param>
 */
typedef RTS_RESULT(CDECL *PFDATARECEIVED)(PROTOCOL_DATA_UNIT pduData, void* pReceiveUserData);

/**
 * <description>Initialize a new secure channel.</description>
 * <param name="pSendPDU" type="IN">Function used by the secure channel to send data.</param>
 * <param name="pSendUserData" type="IN">Parameter passed by the secure channel to the send function.</param>
 * <param name="pfDataReceived" type="IN">Function used by the secure channel to send decrypted data to the client.</param>
 * <param name="pReceiveUserData" type="IN">Parameter passed by the secure channel to the client when data was decrypted.</param>
 * <param name="hTlsContext" type="IN">TLS Context used to establish the TLS connection. See CmpTlsCreateContext.</param>
 * <param name="ui32ChannelSize" type="IN">Size of the communication channel</param>
 * <param name="bPLCBigEndian" type="IN">Flag whether the PLC has Motorola byte order or not.</param>
 * <param name="pResult" type="OUT">error code</param>
 */
DEF_CREATEITF_API(`RTS_HANDLE',`CDECL', `SecChClientInit',`(PFSENDDATA pSendPDU, void *pSendUserData, PFDATARECEIVED pfDataReceived, void *pReceiveUserData, RTS_HANDLE hTlsContext, RTS_UI32 ui32ChannelSize, RTS_BOOL bPLCBigEndian, RTS_RESULT *pResult)')

/**
 * <description>Cleanup the SecureChannel Client.</description>
 * <param name="hSecureChannel" type="IN">Id of the channel.</param>
 */
DEF_DELETEITF_API(`RTS_RESULT',`CDECL', `SecChClientCleanup',`(RTS_HANDLE hSecureChannel)')

/**
 * <description>Send a complete L7 service.</description>
 * <param name="hSecureChannel" type="IN">Id of the channel.</param>
 * <param name="pduData" type="IN">Service to send. Must be a complete L7 service.</param>
 */
DEF_HANDLEITF_API(`RTS_RESULT',`CDECL', `SecChClientSendData',`(RTS_HANDLE hSecureChannel, PROTOCOL_DATA_UNIT pduData)')

/**
 * <description>Function that is called when a new response arrived. This function will decrypt the data an then call pfDataReceived.
 * If there is the need to do some handshaking within the TLS connection this will be handled by this function. The data is sent
 * using pSendPDU in this case.</description>
 * <param name="hSecureChannel" type="IN">Id of the channel.</param>
 * <param name="pduData" type="IN">Service received from the network.</param>
 */
DEF_HANDLEITF_API(`RTS_RESULT',`CDECL', `SecChClientDataReceived',`(RTS_HANDLE hSecureChannel, PROTOCOL_DATA_UNIT pduData)')

/**
 * <description>This function calculates the maximum secure channel size from the network channel size.</description>
 * <param name="ui32ChannelSize" type="IN">Size of the network channel.</param>
 */
DEF_ITF_API(`RTS_UI32',`CDECL', `SecChGetSecureChannelSize',`(RTS_UI32 ui32ChannelSize)')


#ifdef __cplusplus
}
#endif

