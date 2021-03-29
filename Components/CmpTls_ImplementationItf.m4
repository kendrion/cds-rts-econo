/**
 * <interfacename>CmpTls Implementation</interfacename>
 * <description></description>
 *
 * <copyright></copyright>
 */

SET_INTERFACE_NAME(`CmpTls_Implementation')
SET_PLACEHOLDER_NAME(`CmpTls Implementation')
REF_ITF(`CmpTlsItf.m4')

/* Disable this wrapper. Just the parameter structure is needed to call the IEC callback */
#define VERIFYCALLBACKWRAPPER_NOTIMPLEMENTED

/*
 * <description>verifycallbackwrapper</description>
 * NOTE: This function must match the VerifyCallbackWrapper signature of the CmpTls Implementation.
 */
typedef struct tagverifycallbackwrapper_struct
{
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	
	RTS_IEC_RESULT verifyResult;		/* VAR_INPUT */	
	RTS_IEC_XWORD pUserParameter;		/* VAR_INPUT */	
	RTS_IEC_RESULT VerifyCallbackWrapper;	/* VAR_OUTPUT */	
} verifycallbackwrapper_struct;

/** EXTERN LIB SECTION BEGIN **/
/*  Comments are ignored for m4 compiler so restructured text can be used. changecom(`/*', `*/') */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Starts handshaking on the server side. The client has to initiate the handshaking.
 * This is the first function call on the serverside after establishing the unterlaying connection.
 * Data has to be received first. This function will is likley to read and write data.
 *
 * :return: Result of this operation. May be one of these values:
 *		- ERR_OK: No error. Everything worked as expected.
 *		- ERR_NOTINITIALIZED: The TLS component was not initialized proberly.
 *		- ERR_TLS_CONNECTION_CLOSED: The TLS connection is closed. Use TlsShutdown to shutdown locally.
 *     - ERR_TLS_WANT_READ: The operation needs TO read data FROM the IO system. There is no data available.
 *     - ERR_TLS_WANT_WRITE: The operation needs to write data to the IO system. This is not possible.
 *		- ERR_TLS_RETRY_OPERATION: Something went wrong. Try the same function call again
 *		- ERR_TLS_IO_SYSTEM: An error in the unterlaying IO system.
 *		- ERR_TLS_INTERNAL: An internal Error of the TLS Component
 *		- ERR_FAILED: Unknown error.
 */
typedef struct tagcmptlsaccept_struct
{
	RTS_IEC_HANDLE hTlsConn;			/* VAR_INPUT */	/* Handle of the TLS connection, created with one of the TLSxxxOpen functions */
	RTS_IEC_RESULT CmpTlsAccept;		/* VAR_OUTPUT */	
} cmptlsaccept_struct;

DEF_API(`void',`CDECL',`cmptlsaccept',`(cmptlsaccept_struct *p)',1,0xE5016190,0x03050F00)

/**
 * This function is used to indicate that the Rx buffer contains new TLS data. Call this function is new data have arrived. All data of the 
 * buffer has to be consumed by the TLS implementation before overwritting the existing data and calling this funciton. Call TlsRead until the corresponding 
 * error code is returned. If not all data is consumed the TLS stream will be broken and the data can't be decrypted anymore. The Rx buffer will not be changed.
 */
typedef struct tagcmptlsbufferdatareceived_struct
{
	RTS_IEC_HANDLE hTlsConn;			/* VAR_INPUT */	/* Handle to the TLS connection. Must have been created with CmpTlsBufferOpen */
	RTS_IEC_RESULT CmpTlsBufferDataReceived;	/* VAR_OUTPUT */	
} cmptlsbufferdatareceived_struct;

DEF_API(`void',`CDECL',`cmptlsbufferdatareceived',`(cmptlsbufferdatareceived_struct *p)',1,0x613BC278,0x03050F00)

/**
 * This function is used to indicate that the data written by the TLS implementation has been sent to the peer. If this function
 * is called the TLS implementation will start writing it's output at the beginning of the Tx buffer again. Call this function if the data of 
 * the Tx buffer has been sent. The length parameter of the Tx buffer will be set to 0.
 */
typedef struct tagcmptlsbufferdatasent_struct
{
	RTS_IEC_HANDLE hTlsConn;			/* VAR_INPUT */	/* Handle to the TLS connection. Must have been created with CmpTlsBufferOpen */
	RTS_IEC_RESULT CmpTlsBufferDataSent;	/* VAR_OUTPUT */	
} cmptlsbufferdatasent_struct;

DEF_API(`void',`CDECL',`cmptlsbufferdatasent',`(cmptlsbufferdatasent_struct *p)',1,0xA15919C8,0x03050F00)

/**
 * This function is called to determine if the tx buffer contains data which should be sent to the peer.
 */
typedef struct tagcmptlsbufferdatatosendavailable_struct
{
	RTS_IEC_HANDLE hTlsConn;			/* VAR_INPUT */	/* Handle to the TLS connection. Must have been created with CmpTlsBufferOpen */
	RTS_IEC_BOOL CmpTlsBufferDataToSendAvailable;	/* VAR_OUTPUT */	
} cmptlsbufferdatatosendavailable_struct;

DEF_API(`void',`CDECL',`cmptlsbufferdatatosendavailable',`(cmptlsbufferdatatosendavailable_struct *p)',1,0xFC0521B2,0x03050F00)

/**
 * Create a TLS connection around any existing transport media. There are two buffers needed: a send and a receive buffer. 
 * Put the data received from the peer to the Rx buffer. The data written by the TLS implementation 
 * will be put to the Tx buffer. This buffer has to be sent to the peer after calling the connect, accept or write functions. Maybe
 * after calling the read function the buffer has to be sent too. This depends on internal TLS protocol stuff (change of 
 * session keys etc) which may occur at any time. This will be indicated throuth the corresponding returned flag.
 * The TLS connection will be established explicit by calling TSLConnect, or on the server side by calling the Accept function.
 * If the handshaking hasn't finished the read and write functions will internally finish the handshaking until the connection is
 * established. The implementation will start writing at the beginning at each call. If the function indicated that the
 * the data must be sent the next call will overwrite the data in the Tx buffer. So the caller must handle the data before calling
 * the next TLS function. The buffers given here contain raw TLS protocol data. This data has to be transferred to the peer using
 * a reliable way. The packages have to arrive completely and in the right order. Otherwise TLS won't work. 
 * To read or to write the corresponding plaintext data use the TlsRead and TlsWrite functions.
 * Handling is done as follows:
 *    Received data: 
 *		- The bytestrings pointer will point to the beginning of the data.
 *     - The bytestrings max length will hold the buffers size
 *     - The bytestrings length will hold the current available amount of data.
 *     - The function ResetRx will not change any of the byte string. Only the internal read position will be set to the beginning of the buffer
 *
 *    Transmit data: 
 *		- The bytestrings pointer will point to the of the empty writing buffer.
 *     - The bytestrings max length will hold the buffer size
 *     - The bytestrings length will contain the amount of data written by the TLS implementation.
 *     - The function ResetTx will reset the internal write position. The length of the bytestring will be set to 0.
 *
 * :return: The handle to the created TLS connection, or RTS_INVALID_HANDLE, if operation failed.
 */
typedef struct tagcmptlsbufferopen_struct
{
	RTS_IEC_HANDLE hTlsContext;			/* VAR_INPUT */	/* Handle to the TLS configuration context. Create by CmpTlsCreateContext */
	RtsByteString *pRxBuffer;			/* VAR_INPUT */	/* Pointer to the buffer containing the data received from the peer. */
	RtsByteString *pTxBuffer;			/* VAR_INPUT */	/* Pointer to the buffer containing the data to be sent to the peer. */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Result of this operation. Possible values:
   - ERR_OK: The TLS connection was created successful.
   - ERR_NOMEMORY: The TLS connection could not be created. No memory available
   - ERR_INVALID_HANDLE: The TLS connection could not be created. The given context handle is invalid.
   - ERR_PARAMETER: Some parameters where inconsistent or wrong. */
	RTS_IEC_HANDLE CmpTlsBufferOpen;	/* VAR_OUTPUT */	
} cmptlsbufferopen_struct;

DEF_API(`void',`CDECL',`cmptlsbufferopen',`(cmptlsbufferopen_struct *p)',1,0x205777BB,0x03050F00)

/**
 * lose the TLS connection. All data will be cleand up. The handle used for creating the connection will
 * be closed too. No shutdown is done here. This is allowed by the TLS protocol.
 *
 * :return: Result of this operation. May be one of these values:
 * 	- ERR_OK: No error. Everything worked as expected.
 * 	- ERR_FAILED: Unknown error.
 */
typedef struct tagcmptlsclose_struct
{
	RTS_IEC_HANDLE hTlsConn;			/* VAR_INPUT */	/* Handle of the TLS connection, created with one of the TLSxxxOpen functions */
	RTS_IEC_RESULT CmpTlsClose;			/* VAR_OUTPUT */	
} cmptlsclose_struct;

DEF_API(`void',`CDECL',`cmptlsclose',`(cmptlsclose_struct *p)',1,0xBD50D496,0x03050F00)

/**
 * Starts handshaking on the client side. This data is likley to read and write data.
 *
 * :return: Result of this operation. May be one of these values:
 *		- ERR_OK: No error. Everything worked as expected.
 *		- ERR_NOTINITIALIZED: The TLS component was not initialized proberly.
 *		- ERR_TLS_CONNECTION_CLOSED: The TLS connection is closed. Use TlsShutdown to shutdown locally.
 *     - ERR_TLS_WANT_READ: The operation needs TO read data FROM the IO system. There is no data available.
 *     - ERR_TLS_WANT_WRITE: The operation needs to write data to the IO system. This is not possible.
 *		- ERR_TLS_RETRY_OPERATION: Something went wrong. Try the same function call again
 *		- ERR_TLS_IO_SYSTEM: An error in the unterlaying IO system.
 *		- ERR_TLS_INTERNAL: An internal Error of the TLS Component
 *		- ERR_FAILED: Unknown error.
 */
typedef struct tagcmptlsconnect_struct
{
	RTS_IEC_HANDLE hTlsConn;			/* VAR_INPUT */	/* Handle of the TLS connection, created with one of the TLSNewConn functions */
	RTS_IEC_RESULT CmpTlsConnect;		/* VAR_OUTPUT */	
} cmptlsconnect_struct;

DEF_API(`void',`CDECL',`cmptlsconnect',`(cmptlsconnect_struct *p)',1,0xE8789C31,0x03050F00)

/**
 * This function create a TLS context. This context is needed to perform TLS communication
 * using the SysSocket2 library. The context contains all informaiton how to handle this
 * TLS connection.
 *
 *
 * :return: Handle to the new accepted socket or RTS_INVALID_HANDLE if failed.
 */
typedef struct tagcmptlscreatecontext_struct
{
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	/* Handle to a certificate. The private key of this certificate has to be available. 
 Can be RTS_INVALID_HANDLE for client connections. If the server requires a client
 certificate the connection will fail in these case. */
	RTS_IEC_INT tlsMethod;				/* VAR_INPUT, Enum: CMPTLSMETHOD */
	RTS_IEC_STRING *cipherList;			/* VAR_INPUT */	/* Allowed chipers used by this connection. Leave 0 to get default. Default will result in 
 ciphers with HIGH encryption strength and Diffie Hellman key exchange. */
	RTS_IEC_DWORD verifyMode;			/* VAR_INPUT */	/* Set up how to verify the peer. The settings differ between client and server.
 See CmpTlsVerifyMode for details. Default results in: Client -> Verify the peer. Server -> Do not Verify Peer
 The options of CmpTlsConstans can be combined by adding them. */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Operations Result */
	RTS_IEC_HANDLE CmpTlsCreateContext;	/* VAR_OUTPUT */	
} cmptlscreatecontext_struct;

DEF_API(`void',`CDECL',`cmptlscreatecontext',`(cmptlscreatecontext_struct *p)',1,0x9BD4354C,0x03050F00)

/**
 * This function create a TLS context. This context is needed to perform TLS communication
 * using the SysSocket2 library. The context contains all informaiton how to handle this
 * TLS connection.
 *
 *
 * :return: Handle to the new accepted socket or RTS_INVALID_HANDLE if failed.
 */
typedef struct tagcmptlscreatecontext2_intern_struct
{
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	/* Handle to a certificate. The private key of this certificate has to be available. 
 Can be RTS_INVALID_HANDLE for client connections. If the server requires a client
 certificate the connection will fail in these case. */
	RTS_IEC_INT tlsMethod;				/* VAR_INPUT, Enum: CMPTLSMETHOD */
	RTS_IEC_STRING *cipherList;			/* VAR_INPUT */	/* Allowed chipers used by this connection. Leave 0 to get default. Default will result in 
 ciphers with HIGH encryption strength and Diffie Hellman key exchange. */
	RTS_IEC_DWORD verifyMode;			/* VAR_INPUT */	/* Set up how to verify the peer. The settings differ between client and server.
 See CmpTlsVerifyMode for details. Default results in: Client -> Verify the peer. Server -> Do not Verify Peer
 The options of CmpTlsConstans can be combined by adding them. */
	RTS_IEC_BYTE *pfVerifyCallback;		/* VAR_INPUT */	/* Callback that is called to allow an application level verification of the peers certificate. */
	RTS_IEC_XWORD pUserData;			/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Operations Result */
	RTS_IEC_HANDLE CmpTlsCreateContext2_intern;	/* VAR_OUTPUT */	
} cmptlscreatecontext2_intern_struct;

DEF_API(`void',`CDECL',`cmptlscreatecontext2_intern',`(cmptlscreatecontext2_intern_struct *p)',1,RTSITF_GET_SIGNATURE(0x7D8F2FBA, 0xBDD64420),0x03050F00)

/**
 * This function cleans up the TLS context created with CmpTlsCreateContext.
 */
typedef struct tagcmptlsfreecontext_struct
{
	RTS_IEC_HANDLE hTlsContext;			/* VAR_INPUT */	/* Handle to the context to clean up */
	RTS_IEC_RESULT CmpTlsFreeContext;	/* VAR_OUTPUT */	
} cmptlsfreecontext_struct;

DEF_API(`void',`CDECL',`cmptlsfreecontext',`(cmptlsfreecontext_struct *p)',1,0x4FCCCE44,0x03050F00)

/**
 * Receive data from the encrypted channel. If the connection is not established yet, this will be done
 * transparent in the background. Normally only data is of the encrypted channel is consumed. In some cases (Handshaking has
 * not finished or renegotiation of the session keys) this function will also write data. If the unterlaying IO doens't write
 * automatically the need to send data will be indicated using the corresponding error code.
 *
 * :return: Number of bytes received. 0 if an error occured.
 */
typedef struct tagcmptlsread_struct
{
	RTS_IEC_HANDLE hTlsConn;			/* VAR_INPUT */	/* Handle of the TLS connection, created with one of the TLSxxxOpen functions */
	RTS_IEC_BYTE *pbyBuffer;			/* VAR_INPUT */	/* Pointer to a databuffer, where the received decrypted data should be written to. */
	RTS_IEC_XINT xiBufferSize;			/* VAR_INPUT */	/* Size of pbyData. Maximum number of bytes, that could be received from the TLS connection. */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Result OF THIS operation. May be one OF these values:
 	- ERR_OK: No error. Everything worked as expected.
 	- ERR_NOTINITIALIZED: The TLS component was not initialized proberly.
 	- ERR_TLS_CONNECTION_CLOSED: The TLS connection is closed. Use TlsShutdown to shutdown locally.
     - ERR_TLS_WANT_READ: The operation needs TO read data FROM the IO system. There is no data available.
     - ERR_TLS_WANT_WRITE: The operation needs to write data to the IO system. This is not possible.
 	- ERR_TLS_RETRY_OPERATION: Something went wrong. Try the same function call again
 	- ERR_TLS_IO_SYSTEM: An error in the unterlaying IO system.
 	- ERR_TLS_INTERNAL: An internal Error of the TLS Component
 	- ERR_FAILED: Unknown error. */
	RTS_IEC_XINT CmpTlsRead;			/* VAR_OUTPUT */	
} cmptlsread_struct;

DEF_API(`void',`CDECL',`cmptlsread',`(cmptlsread_struct *p)',1,RTSITF_GET_SIGNATURE(0x7869515D, 0xC50DA073),0x03050F00)

/**
 * There are two ways to shutdown the TLS connection:
 * bidirectional: The first call of TlsShutdown will send the shutdown message. The operation will return ERR_TLS_RETRY_OPERATION.
 *             Then the function has to be called again. If the acknowledge of the peer was received ERR_OK will be returned. If the
 *             acknowledge was not received yet the function will return ERR_TLS_WANT_READ.
 * unidirectional: The first call of TlsShutdown will send the shutdown message. The operation will return ERR_TLS_RETRY_OPERATION.
 *             Close the IO channel and clean up. Don't wait for the acknowledge of the peer.
 *
 * :return: Result of this operation. May be one of these values:
 *		- ERR_OK: No error. Everything worked as expected.
 *		- ERR_NOTINITIALIZED: The TLS component was not initialized proberly.
 *		- ERR_TLS_CONNECTION_CLOSED: The TLS connection is closed.
 *     - ERR_TLS_WANT_READ: The operation needs TO read data FROM the IO system. There is no data available.
 *     - ERR_TLS_WANT_WRITE: The operation needs to write data to the IO system. This is not possible.
 *		- ERR_TLS_RETRY_OPERATION: Something went wrong. Try the same function call again
 *		- ERR_TLS_IO_SYSTEM: An error in the unterlaying IO system.
 *		- ERR_TLS_INTERNAL: An internal Error of the TLS Component
 *		- ERR_FAILED: Unknown error.
 */
typedef struct tagcmptlsshutdown_struct
{
	RTS_IEC_HANDLE hTlsConn;			/* VAR_INPUT */	/* Handle of the TLS connection, created with one of the TLSxxxOpen functions */
	RTS_IEC_RESULT CmpTlsShutdown;		/* VAR_OUTPUT */	
} cmptlsshutdown_struct;

DEF_API(`void',`CDECL',`cmptlsshutdown',`(cmptlsshutdown_struct *p)',1,0x2AA5307D,0x03050F00)

/**
 * Send data over the encrypted channel. If the connection is not established yet, this will be done
 * transparent in the background. Normally only data is written to the unterlaying IO. In some cases data have to be read
 * (Handshaking has not finished or renegotiation of the session keys). If not data is for reading is available this will
 * be indicated through the corresponding error code.
 *
 * :return: Number of bytes sent. 0 if an error occured.
 */
typedef struct tagcmptlswrite_struct
{
	RTS_IEC_HANDLE hTlsConn;			/* VAR_INPUT */	/* Handle of the TLS connection, created with one of the TLSxxxOpen functions */
	RTS_IEC_BYTE *pbyData;				/* VAR_INPUT */	/* Pointer to data, that should be sent over the TLS connection */
	RTS_IEC_XINT xiDataSize;			/* VAR_INPUT */	/* Size of pbyData. Number of bytes that should be sent over the TLS connection */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Result OF THIS operation. May be one OF these values:
 	- ERR_OK: No error. Everything worked as expected.
 	- ERR_NOTINITIALIZED: The TLS component was not initialized proberly.
 	- ERR_TLS_CONNECTION_CLOSED: The TLS connection is closed. Use TlsShutdown to shutdown locally.
     - ERR_TLS_WANT_READ: The operation needs TO read data FROM the IO system. There is no data available.
     - ERR_TLS_WANT_WRITE: The operation needs to write data to the IO system. This is not possible.
 	- ERR_TLS_RETRY_OPERATION: Something went wrong. Try the same function call again
 	- ERR_TLS_IO_SYSTEM: An error in the unterlaying IO system.
 	- ERR_TLS_INTERNAL: An internal Error of the TLS Component
 	- ERR_FAILED: Unknown error. */
	RTS_IEC_XINT CmpTlsWrite;			/* VAR_OUTPUT */	
} cmptlswrite_struct;

DEF_API(`void',`CDECL',`cmptlswrite',`(cmptlswrite_struct *p)',1,RTSITF_GET_SIGNATURE(0xA1D9E8A7, 0xF01B2E0C),0x03050F00)

#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/

