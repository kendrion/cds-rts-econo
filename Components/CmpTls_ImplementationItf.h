 /**
 * <interfacename>CmpTls Implementation</interfacename>
 * <description></description>
 *
 * <copyright></copyright>
 */


	
	
#ifndef _CMPTLS_IMPLEMENTATIONITF_H_
#define _CMPTLS_IMPLEMENTATIONITF_H_

#include "CmpStd.h"

 

 



#include "CmpTlsItf.h"

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
/*  Comments are ignored for m4 compiler so restructured text can be used.  */

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

void CDECL CDECL_EXT cmptlsaccept(cmptlsaccept_struct *p);
typedef void (CDECL CDECL_EXT* PFCMPTLSACCEPT_IEC) (cmptlsaccept_struct *p);
#if defined(CMPTLS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CMPTLSACCEPT_NOTIMPLEMENTED)
	#define USE_cmptlsaccept
	#define EXT_cmptlsaccept
	#define GET_cmptlsaccept(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cmptlsaccept(p0) 
	#define CHK_cmptlsaccept  FALSE
	#define EXP_cmptlsaccept  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cmptlsaccept
	#define EXT_cmptlsaccept
	#define GET_cmptlsaccept(fl)  CAL_CMGETAPI( "cmptlsaccept" ) 
	#define CAL_cmptlsaccept  cmptlsaccept
	#define CHK_cmptlsaccept  TRUE
	#define EXP_cmptlsaccept  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsaccept", (RTS_UINTPTR)cmptlsaccept, 1, 0xE5016190, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPTLS_IMPLEMENTATION_EXTERNAL)
	#define USE_cmptlsaccept
	#define EXT_cmptlsaccept
	#define GET_cmptlsaccept(fl)  CAL_CMGETAPI( "cmptlsaccept" ) 
	#define CAL_cmptlsaccept  cmptlsaccept
	#define CHK_cmptlsaccept  TRUE
	#define EXP_cmptlsaccept  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsaccept", (RTS_UINTPTR)cmptlsaccept, 1, 0xE5016190, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpTls_Implementationcmptlsaccept
	#define EXT_CmpTls_Implementationcmptlsaccept
	#define GET_CmpTls_Implementationcmptlsaccept  ERR_OK
	#define CAL_CmpTls_Implementationcmptlsaccept  cmptlsaccept
	#define CHK_CmpTls_Implementationcmptlsaccept  TRUE
	#define EXP_CmpTls_Implementationcmptlsaccept  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsaccept", (RTS_UINTPTR)cmptlsaccept, 1, 0xE5016190, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_cmptlsaccept
	#define EXT_cmptlsaccept
	#define GET_cmptlsaccept(fl)  CAL_CMGETAPI( "cmptlsaccept" ) 
	#define CAL_cmptlsaccept  cmptlsaccept
	#define CHK_cmptlsaccept  TRUE
	#define EXP_cmptlsaccept  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsaccept", (RTS_UINTPTR)cmptlsaccept, 1, 0xE5016190, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_cmptlsaccept  PFCMPTLSACCEPT_IEC pfcmptlsaccept;
	#define EXT_cmptlsaccept  extern PFCMPTLSACCEPT_IEC pfcmptlsaccept;
	#define GET_cmptlsaccept(fl)  s_pfCMGetAPI2( "cmptlsaccept", (RTS_VOID_FCTPTR *)&pfcmptlsaccept, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xE5016190, 0x03050F00)
	#define CAL_cmptlsaccept  pfcmptlsaccept
	#define CHK_cmptlsaccept  (pfcmptlsaccept != NULL)
	#define EXP_cmptlsaccept   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsaccept", (RTS_UINTPTR)cmptlsaccept, 1, 0xE5016190, 0x03050F00) 
#endif


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

void CDECL CDECL_EXT cmptlsbufferdatareceived(cmptlsbufferdatareceived_struct *p);
typedef void (CDECL CDECL_EXT* PFCMPTLSBUFFERDATARECEIVED_IEC) (cmptlsbufferdatareceived_struct *p);
#if defined(CMPTLS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CMPTLSBUFFERDATARECEIVED_NOTIMPLEMENTED)
	#define USE_cmptlsbufferdatareceived
	#define EXT_cmptlsbufferdatareceived
	#define GET_cmptlsbufferdatareceived(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cmptlsbufferdatareceived(p0) 
	#define CHK_cmptlsbufferdatareceived  FALSE
	#define EXP_cmptlsbufferdatareceived  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cmptlsbufferdatareceived
	#define EXT_cmptlsbufferdatareceived
	#define GET_cmptlsbufferdatareceived(fl)  CAL_CMGETAPI( "cmptlsbufferdatareceived" ) 
	#define CAL_cmptlsbufferdatareceived  cmptlsbufferdatareceived
	#define CHK_cmptlsbufferdatareceived  TRUE
	#define EXP_cmptlsbufferdatareceived  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsbufferdatareceived", (RTS_UINTPTR)cmptlsbufferdatareceived, 1, 0x613BC278, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPTLS_IMPLEMENTATION_EXTERNAL)
	#define USE_cmptlsbufferdatareceived
	#define EXT_cmptlsbufferdatareceived
	#define GET_cmptlsbufferdatareceived(fl)  CAL_CMGETAPI( "cmptlsbufferdatareceived" ) 
	#define CAL_cmptlsbufferdatareceived  cmptlsbufferdatareceived
	#define CHK_cmptlsbufferdatareceived  TRUE
	#define EXP_cmptlsbufferdatareceived  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsbufferdatareceived", (RTS_UINTPTR)cmptlsbufferdatareceived, 1, 0x613BC278, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpTls_Implementationcmptlsbufferdatareceived
	#define EXT_CmpTls_Implementationcmptlsbufferdatareceived
	#define GET_CmpTls_Implementationcmptlsbufferdatareceived  ERR_OK
	#define CAL_CmpTls_Implementationcmptlsbufferdatareceived  cmptlsbufferdatareceived
	#define CHK_CmpTls_Implementationcmptlsbufferdatareceived  TRUE
	#define EXP_CmpTls_Implementationcmptlsbufferdatareceived  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsbufferdatareceived", (RTS_UINTPTR)cmptlsbufferdatareceived, 1, 0x613BC278, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_cmptlsbufferdatareceived
	#define EXT_cmptlsbufferdatareceived
	#define GET_cmptlsbufferdatareceived(fl)  CAL_CMGETAPI( "cmptlsbufferdatareceived" ) 
	#define CAL_cmptlsbufferdatareceived  cmptlsbufferdatareceived
	#define CHK_cmptlsbufferdatareceived  TRUE
	#define EXP_cmptlsbufferdatareceived  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsbufferdatareceived", (RTS_UINTPTR)cmptlsbufferdatareceived, 1, 0x613BC278, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_cmptlsbufferdatareceived  PFCMPTLSBUFFERDATARECEIVED_IEC pfcmptlsbufferdatareceived;
	#define EXT_cmptlsbufferdatareceived  extern PFCMPTLSBUFFERDATARECEIVED_IEC pfcmptlsbufferdatareceived;
	#define GET_cmptlsbufferdatareceived(fl)  s_pfCMGetAPI2( "cmptlsbufferdatareceived", (RTS_VOID_FCTPTR *)&pfcmptlsbufferdatareceived, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x613BC278, 0x03050F00)
	#define CAL_cmptlsbufferdatareceived  pfcmptlsbufferdatareceived
	#define CHK_cmptlsbufferdatareceived  (pfcmptlsbufferdatareceived != NULL)
	#define EXP_cmptlsbufferdatareceived   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsbufferdatareceived", (RTS_UINTPTR)cmptlsbufferdatareceived, 1, 0x613BC278, 0x03050F00) 
#endif


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

void CDECL CDECL_EXT cmptlsbufferdatasent(cmptlsbufferdatasent_struct *p);
typedef void (CDECL CDECL_EXT* PFCMPTLSBUFFERDATASENT_IEC) (cmptlsbufferdatasent_struct *p);
#if defined(CMPTLS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CMPTLSBUFFERDATASENT_NOTIMPLEMENTED)
	#define USE_cmptlsbufferdatasent
	#define EXT_cmptlsbufferdatasent
	#define GET_cmptlsbufferdatasent(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cmptlsbufferdatasent(p0) 
	#define CHK_cmptlsbufferdatasent  FALSE
	#define EXP_cmptlsbufferdatasent  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cmptlsbufferdatasent
	#define EXT_cmptlsbufferdatasent
	#define GET_cmptlsbufferdatasent(fl)  CAL_CMGETAPI( "cmptlsbufferdatasent" ) 
	#define CAL_cmptlsbufferdatasent  cmptlsbufferdatasent
	#define CHK_cmptlsbufferdatasent  TRUE
	#define EXP_cmptlsbufferdatasent  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsbufferdatasent", (RTS_UINTPTR)cmptlsbufferdatasent, 1, 0xA15919C8, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPTLS_IMPLEMENTATION_EXTERNAL)
	#define USE_cmptlsbufferdatasent
	#define EXT_cmptlsbufferdatasent
	#define GET_cmptlsbufferdatasent(fl)  CAL_CMGETAPI( "cmptlsbufferdatasent" ) 
	#define CAL_cmptlsbufferdatasent  cmptlsbufferdatasent
	#define CHK_cmptlsbufferdatasent  TRUE
	#define EXP_cmptlsbufferdatasent  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsbufferdatasent", (RTS_UINTPTR)cmptlsbufferdatasent, 1, 0xA15919C8, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpTls_Implementationcmptlsbufferdatasent
	#define EXT_CmpTls_Implementationcmptlsbufferdatasent
	#define GET_CmpTls_Implementationcmptlsbufferdatasent  ERR_OK
	#define CAL_CmpTls_Implementationcmptlsbufferdatasent  cmptlsbufferdatasent
	#define CHK_CmpTls_Implementationcmptlsbufferdatasent  TRUE
	#define EXP_CmpTls_Implementationcmptlsbufferdatasent  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsbufferdatasent", (RTS_UINTPTR)cmptlsbufferdatasent, 1, 0xA15919C8, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_cmptlsbufferdatasent
	#define EXT_cmptlsbufferdatasent
	#define GET_cmptlsbufferdatasent(fl)  CAL_CMGETAPI( "cmptlsbufferdatasent" ) 
	#define CAL_cmptlsbufferdatasent  cmptlsbufferdatasent
	#define CHK_cmptlsbufferdatasent  TRUE
	#define EXP_cmptlsbufferdatasent  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsbufferdatasent", (RTS_UINTPTR)cmptlsbufferdatasent, 1, 0xA15919C8, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_cmptlsbufferdatasent  PFCMPTLSBUFFERDATASENT_IEC pfcmptlsbufferdatasent;
	#define EXT_cmptlsbufferdatasent  extern PFCMPTLSBUFFERDATASENT_IEC pfcmptlsbufferdatasent;
	#define GET_cmptlsbufferdatasent(fl)  s_pfCMGetAPI2( "cmptlsbufferdatasent", (RTS_VOID_FCTPTR *)&pfcmptlsbufferdatasent, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xA15919C8, 0x03050F00)
	#define CAL_cmptlsbufferdatasent  pfcmptlsbufferdatasent
	#define CHK_cmptlsbufferdatasent  (pfcmptlsbufferdatasent != NULL)
	#define EXP_cmptlsbufferdatasent   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsbufferdatasent", (RTS_UINTPTR)cmptlsbufferdatasent, 1, 0xA15919C8, 0x03050F00) 
#endif


/**
 * This function is called to determine if the tx buffer contains data which should be sent to the peer.
 */
typedef struct tagcmptlsbufferdatatosendavailable_struct
{
	RTS_IEC_HANDLE hTlsConn;			/* VAR_INPUT */	/* Handle to the TLS connection. Must have been created with CmpTlsBufferOpen */
	RTS_IEC_BOOL CmpTlsBufferDataToSendAvailable;	/* VAR_OUTPUT */	
} cmptlsbufferdatatosendavailable_struct;

void CDECL CDECL_EXT cmptlsbufferdatatosendavailable(cmptlsbufferdatatosendavailable_struct *p);
typedef void (CDECL CDECL_EXT* PFCMPTLSBUFFERDATATOSENDAVAILABLE_IEC) (cmptlsbufferdatatosendavailable_struct *p);
#if defined(CMPTLS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CMPTLSBUFFERDATATOSENDAVAILABLE_NOTIMPLEMENTED)
	#define USE_cmptlsbufferdatatosendavailable
	#define EXT_cmptlsbufferdatatosendavailable
	#define GET_cmptlsbufferdatatosendavailable(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cmptlsbufferdatatosendavailable(p0) 
	#define CHK_cmptlsbufferdatatosendavailable  FALSE
	#define EXP_cmptlsbufferdatatosendavailable  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cmptlsbufferdatatosendavailable
	#define EXT_cmptlsbufferdatatosendavailable
	#define GET_cmptlsbufferdatatosendavailable(fl)  CAL_CMGETAPI( "cmptlsbufferdatatosendavailable" ) 
	#define CAL_cmptlsbufferdatatosendavailable  cmptlsbufferdatatosendavailable
	#define CHK_cmptlsbufferdatatosendavailable  TRUE
	#define EXP_cmptlsbufferdatatosendavailable  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsbufferdatatosendavailable", (RTS_UINTPTR)cmptlsbufferdatatosendavailable, 1, 0xFC0521B2, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPTLS_IMPLEMENTATION_EXTERNAL)
	#define USE_cmptlsbufferdatatosendavailable
	#define EXT_cmptlsbufferdatatosendavailable
	#define GET_cmptlsbufferdatatosendavailable(fl)  CAL_CMGETAPI( "cmptlsbufferdatatosendavailable" ) 
	#define CAL_cmptlsbufferdatatosendavailable  cmptlsbufferdatatosendavailable
	#define CHK_cmptlsbufferdatatosendavailable  TRUE
	#define EXP_cmptlsbufferdatatosendavailable  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsbufferdatatosendavailable", (RTS_UINTPTR)cmptlsbufferdatatosendavailable, 1, 0xFC0521B2, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpTls_Implementationcmptlsbufferdatatosendavailable
	#define EXT_CmpTls_Implementationcmptlsbufferdatatosendavailable
	#define GET_CmpTls_Implementationcmptlsbufferdatatosendavailable  ERR_OK
	#define CAL_CmpTls_Implementationcmptlsbufferdatatosendavailable  cmptlsbufferdatatosendavailable
	#define CHK_CmpTls_Implementationcmptlsbufferdatatosendavailable  TRUE
	#define EXP_CmpTls_Implementationcmptlsbufferdatatosendavailable  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsbufferdatatosendavailable", (RTS_UINTPTR)cmptlsbufferdatatosendavailable, 1, 0xFC0521B2, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_cmptlsbufferdatatosendavailable
	#define EXT_cmptlsbufferdatatosendavailable
	#define GET_cmptlsbufferdatatosendavailable(fl)  CAL_CMGETAPI( "cmptlsbufferdatatosendavailable" ) 
	#define CAL_cmptlsbufferdatatosendavailable  cmptlsbufferdatatosendavailable
	#define CHK_cmptlsbufferdatatosendavailable  TRUE
	#define EXP_cmptlsbufferdatatosendavailable  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsbufferdatatosendavailable", (RTS_UINTPTR)cmptlsbufferdatatosendavailable, 1, 0xFC0521B2, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_cmptlsbufferdatatosendavailable  PFCMPTLSBUFFERDATATOSENDAVAILABLE_IEC pfcmptlsbufferdatatosendavailable;
	#define EXT_cmptlsbufferdatatosendavailable  extern PFCMPTLSBUFFERDATATOSENDAVAILABLE_IEC pfcmptlsbufferdatatosendavailable;
	#define GET_cmptlsbufferdatatosendavailable(fl)  s_pfCMGetAPI2( "cmptlsbufferdatatosendavailable", (RTS_VOID_FCTPTR *)&pfcmptlsbufferdatatosendavailable, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xFC0521B2, 0x03050F00)
	#define CAL_cmptlsbufferdatatosendavailable  pfcmptlsbufferdatatosendavailable
	#define CHK_cmptlsbufferdatatosendavailable  (pfcmptlsbufferdatatosendavailable != NULL)
	#define EXP_cmptlsbufferdatatosendavailable   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsbufferdatatosendavailable", (RTS_UINTPTR)cmptlsbufferdatatosendavailable, 1, 0xFC0521B2, 0x03050F00) 
#endif


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

void CDECL CDECL_EXT cmptlsbufferopen(cmptlsbufferopen_struct *p);
typedef void (CDECL CDECL_EXT* PFCMPTLSBUFFEROPEN_IEC) (cmptlsbufferopen_struct *p);
#if defined(CMPTLS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CMPTLSBUFFEROPEN_NOTIMPLEMENTED)
	#define USE_cmptlsbufferopen
	#define EXT_cmptlsbufferopen
	#define GET_cmptlsbufferopen(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cmptlsbufferopen(p0) 
	#define CHK_cmptlsbufferopen  FALSE
	#define EXP_cmptlsbufferopen  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cmptlsbufferopen
	#define EXT_cmptlsbufferopen
	#define GET_cmptlsbufferopen(fl)  CAL_CMGETAPI( "cmptlsbufferopen" ) 
	#define CAL_cmptlsbufferopen  cmptlsbufferopen
	#define CHK_cmptlsbufferopen  TRUE
	#define EXP_cmptlsbufferopen  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsbufferopen", (RTS_UINTPTR)cmptlsbufferopen, 1, 0x205777BB, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPTLS_IMPLEMENTATION_EXTERNAL)
	#define USE_cmptlsbufferopen
	#define EXT_cmptlsbufferopen
	#define GET_cmptlsbufferopen(fl)  CAL_CMGETAPI( "cmptlsbufferopen" ) 
	#define CAL_cmptlsbufferopen  cmptlsbufferopen
	#define CHK_cmptlsbufferopen  TRUE
	#define EXP_cmptlsbufferopen  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsbufferopen", (RTS_UINTPTR)cmptlsbufferopen, 1, 0x205777BB, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpTls_Implementationcmptlsbufferopen
	#define EXT_CmpTls_Implementationcmptlsbufferopen
	#define GET_CmpTls_Implementationcmptlsbufferopen  ERR_OK
	#define CAL_CmpTls_Implementationcmptlsbufferopen  cmptlsbufferopen
	#define CHK_CmpTls_Implementationcmptlsbufferopen  TRUE
	#define EXP_CmpTls_Implementationcmptlsbufferopen  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsbufferopen", (RTS_UINTPTR)cmptlsbufferopen, 1, 0x205777BB, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_cmptlsbufferopen
	#define EXT_cmptlsbufferopen
	#define GET_cmptlsbufferopen(fl)  CAL_CMGETAPI( "cmptlsbufferopen" ) 
	#define CAL_cmptlsbufferopen  cmptlsbufferopen
	#define CHK_cmptlsbufferopen  TRUE
	#define EXP_cmptlsbufferopen  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsbufferopen", (RTS_UINTPTR)cmptlsbufferopen, 1, 0x205777BB, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_cmptlsbufferopen  PFCMPTLSBUFFEROPEN_IEC pfcmptlsbufferopen;
	#define EXT_cmptlsbufferopen  extern PFCMPTLSBUFFEROPEN_IEC pfcmptlsbufferopen;
	#define GET_cmptlsbufferopen(fl)  s_pfCMGetAPI2( "cmptlsbufferopen", (RTS_VOID_FCTPTR *)&pfcmptlsbufferopen, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x205777BB, 0x03050F00)
	#define CAL_cmptlsbufferopen  pfcmptlsbufferopen
	#define CHK_cmptlsbufferopen  (pfcmptlsbufferopen != NULL)
	#define EXP_cmptlsbufferopen   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsbufferopen", (RTS_UINTPTR)cmptlsbufferopen, 1, 0x205777BB, 0x03050F00) 
#endif


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

void CDECL CDECL_EXT cmptlsclose(cmptlsclose_struct *p);
typedef void (CDECL CDECL_EXT* PFCMPTLSCLOSE_IEC) (cmptlsclose_struct *p);
#if defined(CMPTLS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CMPTLSCLOSE_NOTIMPLEMENTED)
	#define USE_cmptlsclose
	#define EXT_cmptlsclose
	#define GET_cmptlsclose(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cmptlsclose(p0) 
	#define CHK_cmptlsclose  FALSE
	#define EXP_cmptlsclose  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cmptlsclose
	#define EXT_cmptlsclose
	#define GET_cmptlsclose(fl)  CAL_CMGETAPI( "cmptlsclose" ) 
	#define CAL_cmptlsclose  cmptlsclose
	#define CHK_cmptlsclose  TRUE
	#define EXP_cmptlsclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsclose", (RTS_UINTPTR)cmptlsclose, 1, 0xBD50D496, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPTLS_IMPLEMENTATION_EXTERNAL)
	#define USE_cmptlsclose
	#define EXT_cmptlsclose
	#define GET_cmptlsclose(fl)  CAL_CMGETAPI( "cmptlsclose" ) 
	#define CAL_cmptlsclose  cmptlsclose
	#define CHK_cmptlsclose  TRUE
	#define EXP_cmptlsclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsclose", (RTS_UINTPTR)cmptlsclose, 1, 0xBD50D496, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpTls_Implementationcmptlsclose
	#define EXT_CmpTls_Implementationcmptlsclose
	#define GET_CmpTls_Implementationcmptlsclose  ERR_OK
	#define CAL_CmpTls_Implementationcmptlsclose  cmptlsclose
	#define CHK_CmpTls_Implementationcmptlsclose  TRUE
	#define EXP_CmpTls_Implementationcmptlsclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsclose", (RTS_UINTPTR)cmptlsclose, 1, 0xBD50D496, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_cmptlsclose
	#define EXT_cmptlsclose
	#define GET_cmptlsclose(fl)  CAL_CMGETAPI( "cmptlsclose" ) 
	#define CAL_cmptlsclose  cmptlsclose
	#define CHK_cmptlsclose  TRUE
	#define EXP_cmptlsclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsclose", (RTS_UINTPTR)cmptlsclose, 1, 0xBD50D496, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_cmptlsclose  PFCMPTLSCLOSE_IEC pfcmptlsclose;
	#define EXT_cmptlsclose  extern PFCMPTLSCLOSE_IEC pfcmptlsclose;
	#define GET_cmptlsclose(fl)  s_pfCMGetAPI2( "cmptlsclose", (RTS_VOID_FCTPTR *)&pfcmptlsclose, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xBD50D496, 0x03050F00)
	#define CAL_cmptlsclose  pfcmptlsclose
	#define CHK_cmptlsclose  (pfcmptlsclose != NULL)
	#define EXP_cmptlsclose   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsclose", (RTS_UINTPTR)cmptlsclose, 1, 0xBD50D496, 0x03050F00) 
#endif


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

void CDECL CDECL_EXT cmptlsconnect(cmptlsconnect_struct *p);
typedef void (CDECL CDECL_EXT* PFCMPTLSCONNECT_IEC) (cmptlsconnect_struct *p);
#if defined(CMPTLS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CMPTLSCONNECT_NOTIMPLEMENTED)
	#define USE_cmptlsconnect
	#define EXT_cmptlsconnect
	#define GET_cmptlsconnect(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cmptlsconnect(p0) 
	#define CHK_cmptlsconnect  FALSE
	#define EXP_cmptlsconnect  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cmptlsconnect
	#define EXT_cmptlsconnect
	#define GET_cmptlsconnect(fl)  CAL_CMGETAPI( "cmptlsconnect" ) 
	#define CAL_cmptlsconnect  cmptlsconnect
	#define CHK_cmptlsconnect  TRUE
	#define EXP_cmptlsconnect  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsconnect", (RTS_UINTPTR)cmptlsconnect, 1, 0xE8789C31, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPTLS_IMPLEMENTATION_EXTERNAL)
	#define USE_cmptlsconnect
	#define EXT_cmptlsconnect
	#define GET_cmptlsconnect(fl)  CAL_CMGETAPI( "cmptlsconnect" ) 
	#define CAL_cmptlsconnect  cmptlsconnect
	#define CHK_cmptlsconnect  TRUE
	#define EXP_cmptlsconnect  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsconnect", (RTS_UINTPTR)cmptlsconnect, 1, 0xE8789C31, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpTls_Implementationcmptlsconnect
	#define EXT_CmpTls_Implementationcmptlsconnect
	#define GET_CmpTls_Implementationcmptlsconnect  ERR_OK
	#define CAL_CmpTls_Implementationcmptlsconnect  cmptlsconnect
	#define CHK_CmpTls_Implementationcmptlsconnect  TRUE
	#define EXP_CmpTls_Implementationcmptlsconnect  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsconnect", (RTS_UINTPTR)cmptlsconnect, 1, 0xE8789C31, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_cmptlsconnect
	#define EXT_cmptlsconnect
	#define GET_cmptlsconnect(fl)  CAL_CMGETAPI( "cmptlsconnect" ) 
	#define CAL_cmptlsconnect  cmptlsconnect
	#define CHK_cmptlsconnect  TRUE
	#define EXP_cmptlsconnect  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsconnect", (RTS_UINTPTR)cmptlsconnect, 1, 0xE8789C31, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_cmptlsconnect  PFCMPTLSCONNECT_IEC pfcmptlsconnect;
	#define EXT_cmptlsconnect  extern PFCMPTLSCONNECT_IEC pfcmptlsconnect;
	#define GET_cmptlsconnect(fl)  s_pfCMGetAPI2( "cmptlsconnect", (RTS_VOID_FCTPTR *)&pfcmptlsconnect, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xE8789C31, 0x03050F00)
	#define CAL_cmptlsconnect  pfcmptlsconnect
	#define CHK_cmptlsconnect  (pfcmptlsconnect != NULL)
	#define EXP_cmptlsconnect   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsconnect", (RTS_UINTPTR)cmptlsconnect, 1, 0xE8789C31, 0x03050F00) 
#endif


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

void CDECL CDECL_EXT cmptlscreatecontext(cmptlscreatecontext_struct *p);
typedef void (CDECL CDECL_EXT* PFCMPTLSCREATECONTEXT_IEC) (cmptlscreatecontext_struct *p);
#if defined(CMPTLS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CMPTLSCREATECONTEXT_NOTIMPLEMENTED)
	#define USE_cmptlscreatecontext
	#define EXT_cmptlscreatecontext
	#define GET_cmptlscreatecontext(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cmptlscreatecontext(p0) 
	#define CHK_cmptlscreatecontext  FALSE
	#define EXP_cmptlscreatecontext  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cmptlscreatecontext
	#define EXT_cmptlscreatecontext
	#define GET_cmptlscreatecontext(fl)  CAL_CMGETAPI( "cmptlscreatecontext" ) 
	#define CAL_cmptlscreatecontext  cmptlscreatecontext
	#define CHK_cmptlscreatecontext  TRUE
	#define EXP_cmptlscreatecontext  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlscreatecontext", (RTS_UINTPTR)cmptlscreatecontext, 1, 0x9BD4354C, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPTLS_IMPLEMENTATION_EXTERNAL)
	#define USE_cmptlscreatecontext
	#define EXT_cmptlscreatecontext
	#define GET_cmptlscreatecontext(fl)  CAL_CMGETAPI( "cmptlscreatecontext" ) 
	#define CAL_cmptlscreatecontext  cmptlscreatecontext
	#define CHK_cmptlscreatecontext  TRUE
	#define EXP_cmptlscreatecontext  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlscreatecontext", (RTS_UINTPTR)cmptlscreatecontext, 1, 0x9BD4354C, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpTls_Implementationcmptlscreatecontext
	#define EXT_CmpTls_Implementationcmptlscreatecontext
	#define GET_CmpTls_Implementationcmptlscreatecontext  ERR_OK
	#define CAL_CmpTls_Implementationcmptlscreatecontext  cmptlscreatecontext
	#define CHK_CmpTls_Implementationcmptlscreatecontext  TRUE
	#define EXP_CmpTls_Implementationcmptlscreatecontext  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlscreatecontext", (RTS_UINTPTR)cmptlscreatecontext, 1, 0x9BD4354C, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_cmptlscreatecontext
	#define EXT_cmptlscreatecontext
	#define GET_cmptlscreatecontext(fl)  CAL_CMGETAPI( "cmptlscreatecontext" ) 
	#define CAL_cmptlscreatecontext  cmptlscreatecontext
	#define CHK_cmptlscreatecontext  TRUE
	#define EXP_cmptlscreatecontext  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlscreatecontext", (RTS_UINTPTR)cmptlscreatecontext, 1, 0x9BD4354C, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_cmptlscreatecontext  PFCMPTLSCREATECONTEXT_IEC pfcmptlscreatecontext;
	#define EXT_cmptlscreatecontext  extern PFCMPTLSCREATECONTEXT_IEC pfcmptlscreatecontext;
	#define GET_cmptlscreatecontext(fl)  s_pfCMGetAPI2( "cmptlscreatecontext", (RTS_VOID_FCTPTR *)&pfcmptlscreatecontext, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x9BD4354C, 0x03050F00)
	#define CAL_cmptlscreatecontext  pfcmptlscreatecontext
	#define CHK_cmptlscreatecontext  (pfcmptlscreatecontext != NULL)
	#define EXP_cmptlscreatecontext   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlscreatecontext", (RTS_UINTPTR)cmptlscreatecontext, 1, 0x9BD4354C, 0x03050F00) 
#endif


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

void CDECL CDECL_EXT cmptlscreatecontext2_intern(cmptlscreatecontext2_intern_struct *p);
typedef void (CDECL CDECL_EXT* PFCMPTLSCREATECONTEXT2_INTERN_IEC) (cmptlscreatecontext2_intern_struct *p);
#if defined(CMPTLS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CMPTLSCREATECONTEXT2_INTERN_NOTIMPLEMENTED)
	#define USE_cmptlscreatecontext2_intern
	#define EXT_cmptlscreatecontext2_intern
	#define GET_cmptlscreatecontext2_intern(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cmptlscreatecontext2_intern(p0) 
	#define CHK_cmptlscreatecontext2_intern  FALSE
	#define EXP_cmptlscreatecontext2_intern  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cmptlscreatecontext2_intern
	#define EXT_cmptlscreatecontext2_intern
	#define GET_cmptlscreatecontext2_intern(fl)  CAL_CMGETAPI( "cmptlscreatecontext2_intern" ) 
	#define CAL_cmptlscreatecontext2_intern  cmptlscreatecontext2_intern
	#define CHK_cmptlscreatecontext2_intern  TRUE
	#define EXP_cmptlscreatecontext2_intern  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlscreatecontext2_intern", (RTS_UINTPTR)cmptlscreatecontext2_intern, 1, RTSITF_GET_SIGNATURE(0x7D8F2FBA, 0xBDD64420), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPTLS_IMPLEMENTATION_EXTERNAL)
	#define USE_cmptlscreatecontext2_intern
	#define EXT_cmptlscreatecontext2_intern
	#define GET_cmptlscreatecontext2_intern(fl)  CAL_CMGETAPI( "cmptlscreatecontext2_intern" ) 
	#define CAL_cmptlscreatecontext2_intern  cmptlscreatecontext2_intern
	#define CHK_cmptlscreatecontext2_intern  TRUE
	#define EXP_cmptlscreatecontext2_intern  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlscreatecontext2_intern", (RTS_UINTPTR)cmptlscreatecontext2_intern, 1, RTSITF_GET_SIGNATURE(0x7D8F2FBA, 0xBDD64420), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpTls_Implementationcmptlscreatecontext2_intern
	#define EXT_CmpTls_Implementationcmptlscreatecontext2_intern
	#define GET_CmpTls_Implementationcmptlscreatecontext2_intern  ERR_OK
	#define CAL_CmpTls_Implementationcmptlscreatecontext2_intern  cmptlscreatecontext2_intern
	#define CHK_CmpTls_Implementationcmptlscreatecontext2_intern  TRUE
	#define EXP_CmpTls_Implementationcmptlscreatecontext2_intern  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlscreatecontext2_intern", (RTS_UINTPTR)cmptlscreatecontext2_intern, 1, RTSITF_GET_SIGNATURE(0x7D8F2FBA, 0xBDD64420), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_cmptlscreatecontext2_intern
	#define EXT_cmptlscreatecontext2_intern
	#define GET_cmptlscreatecontext2_intern(fl)  CAL_CMGETAPI( "cmptlscreatecontext2_intern" ) 
	#define CAL_cmptlscreatecontext2_intern  cmptlscreatecontext2_intern
	#define CHK_cmptlscreatecontext2_intern  TRUE
	#define EXP_cmptlscreatecontext2_intern  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlscreatecontext2_intern", (RTS_UINTPTR)cmptlscreatecontext2_intern, 1, RTSITF_GET_SIGNATURE(0x7D8F2FBA, 0xBDD64420), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_cmptlscreatecontext2_intern  PFCMPTLSCREATECONTEXT2_INTERN_IEC pfcmptlscreatecontext2_intern;
	#define EXT_cmptlscreatecontext2_intern  extern PFCMPTLSCREATECONTEXT2_INTERN_IEC pfcmptlscreatecontext2_intern;
	#define GET_cmptlscreatecontext2_intern(fl)  s_pfCMGetAPI2( "cmptlscreatecontext2_intern", (RTS_VOID_FCTPTR *)&pfcmptlscreatecontext2_intern, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0x7D8F2FBA, 0xBDD64420), 0x03050F00)
	#define CAL_cmptlscreatecontext2_intern  pfcmptlscreatecontext2_intern
	#define CHK_cmptlscreatecontext2_intern  (pfcmptlscreatecontext2_intern != NULL)
	#define EXP_cmptlscreatecontext2_intern   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlscreatecontext2_intern", (RTS_UINTPTR)cmptlscreatecontext2_intern, 1, RTSITF_GET_SIGNATURE(0x7D8F2FBA, 0xBDD64420), 0x03050F00) 
#endif


/**
 * This function cleans up the TLS context created with CmpTlsCreateContext.
 */
typedef struct tagcmptlsfreecontext_struct
{
	RTS_IEC_HANDLE hTlsContext;			/* VAR_INPUT */	/* Handle to the context to clean up */
	RTS_IEC_RESULT CmpTlsFreeContext;	/* VAR_OUTPUT */	
} cmptlsfreecontext_struct;

void CDECL CDECL_EXT cmptlsfreecontext(cmptlsfreecontext_struct *p);
typedef void (CDECL CDECL_EXT* PFCMPTLSFREECONTEXT_IEC) (cmptlsfreecontext_struct *p);
#if defined(CMPTLS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CMPTLSFREECONTEXT_NOTIMPLEMENTED)
	#define USE_cmptlsfreecontext
	#define EXT_cmptlsfreecontext
	#define GET_cmptlsfreecontext(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cmptlsfreecontext(p0) 
	#define CHK_cmptlsfreecontext  FALSE
	#define EXP_cmptlsfreecontext  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cmptlsfreecontext
	#define EXT_cmptlsfreecontext
	#define GET_cmptlsfreecontext(fl)  CAL_CMGETAPI( "cmptlsfreecontext" ) 
	#define CAL_cmptlsfreecontext  cmptlsfreecontext
	#define CHK_cmptlsfreecontext  TRUE
	#define EXP_cmptlsfreecontext  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsfreecontext", (RTS_UINTPTR)cmptlsfreecontext, 1, 0x4FCCCE44, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPTLS_IMPLEMENTATION_EXTERNAL)
	#define USE_cmptlsfreecontext
	#define EXT_cmptlsfreecontext
	#define GET_cmptlsfreecontext(fl)  CAL_CMGETAPI( "cmptlsfreecontext" ) 
	#define CAL_cmptlsfreecontext  cmptlsfreecontext
	#define CHK_cmptlsfreecontext  TRUE
	#define EXP_cmptlsfreecontext  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsfreecontext", (RTS_UINTPTR)cmptlsfreecontext, 1, 0x4FCCCE44, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpTls_Implementationcmptlsfreecontext
	#define EXT_CmpTls_Implementationcmptlsfreecontext
	#define GET_CmpTls_Implementationcmptlsfreecontext  ERR_OK
	#define CAL_CmpTls_Implementationcmptlsfreecontext  cmptlsfreecontext
	#define CHK_CmpTls_Implementationcmptlsfreecontext  TRUE
	#define EXP_CmpTls_Implementationcmptlsfreecontext  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsfreecontext", (RTS_UINTPTR)cmptlsfreecontext, 1, 0x4FCCCE44, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_cmptlsfreecontext
	#define EXT_cmptlsfreecontext
	#define GET_cmptlsfreecontext(fl)  CAL_CMGETAPI( "cmptlsfreecontext" ) 
	#define CAL_cmptlsfreecontext  cmptlsfreecontext
	#define CHK_cmptlsfreecontext  TRUE
	#define EXP_cmptlsfreecontext  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsfreecontext", (RTS_UINTPTR)cmptlsfreecontext, 1, 0x4FCCCE44, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_cmptlsfreecontext  PFCMPTLSFREECONTEXT_IEC pfcmptlsfreecontext;
	#define EXT_cmptlsfreecontext  extern PFCMPTLSFREECONTEXT_IEC pfcmptlsfreecontext;
	#define GET_cmptlsfreecontext(fl)  s_pfCMGetAPI2( "cmptlsfreecontext", (RTS_VOID_FCTPTR *)&pfcmptlsfreecontext, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x4FCCCE44, 0x03050F00)
	#define CAL_cmptlsfreecontext  pfcmptlsfreecontext
	#define CHK_cmptlsfreecontext  (pfcmptlsfreecontext != NULL)
	#define EXP_cmptlsfreecontext   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsfreecontext", (RTS_UINTPTR)cmptlsfreecontext, 1, 0x4FCCCE44, 0x03050F00) 
#endif


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

void CDECL CDECL_EXT cmptlsread(cmptlsread_struct *p);
typedef void (CDECL CDECL_EXT* PFCMPTLSREAD_IEC) (cmptlsread_struct *p);
#if defined(CMPTLS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CMPTLSREAD_NOTIMPLEMENTED)
	#define USE_cmptlsread
	#define EXT_cmptlsread
	#define GET_cmptlsread(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cmptlsread(p0) 
	#define CHK_cmptlsread  FALSE
	#define EXP_cmptlsread  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cmptlsread
	#define EXT_cmptlsread
	#define GET_cmptlsread(fl)  CAL_CMGETAPI( "cmptlsread" ) 
	#define CAL_cmptlsread  cmptlsread
	#define CHK_cmptlsread  TRUE
	#define EXP_cmptlsread  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsread", (RTS_UINTPTR)cmptlsread, 1, RTSITF_GET_SIGNATURE(0x7869515D, 0xC50DA073), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPTLS_IMPLEMENTATION_EXTERNAL)
	#define USE_cmptlsread
	#define EXT_cmptlsread
	#define GET_cmptlsread(fl)  CAL_CMGETAPI( "cmptlsread" ) 
	#define CAL_cmptlsread  cmptlsread
	#define CHK_cmptlsread  TRUE
	#define EXP_cmptlsread  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsread", (RTS_UINTPTR)cmptlsread, 1, RTSITF_GET_SIGNATURE(0x7869515D, 0xC50DA073), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpTls_Implementationcmptlsread
	#define EXT_CmpTls_Implementationcmptlsread
	#define GET_CmpTls_Implementationcmptlsread  ERR_OK
	#define CAL_CmpTls_Implementationcmptlsread  cmptlsread
	#define CHK_CmpTls_Implementationcmptlsread  TRUE
	#define EXP_CmpTls_Implementationcmptlsread  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsread", (RTS_UINTPTR)cmptlsread, 1, RTSITF_GET_SIGNATURE(0x7869515D, 0xC50DA073), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_cmptlsread
	#define EXT_cmptlsread
	#define GET_cmptlsread(fl)  CAL_CMGETAPI( "cmptlsread" ) 
	#define CAL_cmptlsread  cmptlsread
	#define CHK_cmptlsread  TRUE
	#define EXP_cmptlsread  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsread", (RTS_UINTPTR)cmptlsread, 1, RTSITF_GET_SIGNATURE(0x7869515D, 0xC50DA073), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_cmptlsread  PFCMPTLSREAD_IEC pfcmptlsread;
	#define EXT_cmptlsread  extern PFCMPTLSREAD_IEC pfcmptlsread;
	#define GET_cmptlsread(fl)  s_pfCMGetAPI2( "cmptlsread", (RTS_VOID_FCTPTR *)&pfcmptlsread, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0x7869515D, 0xC50DA073), 0x03050F00)
	#define CAL_cmptlsread  pfcmptlsread
	#define CHK_cmptlsread  (pfcmptlsread != NULL)
	#define EXP_cmptlsread   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsread", (RTS_UINTPTR)cmptlsread, 1, RTSITF_GET_SIGNATURE(0x7869515D, 0xC50DA073), 0x03050F00) 
#endif


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

void CDECL CDECL_EXT cmptlsshutdown(cmptlsshutdown_struct *p);
typedef void (CDECL CDECL_EXT* PFCMPTLSSHUTDOWN_IEC) (cmptlsshutdown_struct *p);
#if defined(CMPTLS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CMPTLSSHUTDOWN_NOTIMPLEMENTED)
	#define USE_cmptlsshutdown
	#define EXT_cmptlsshutdown
	#define GET_cmptlsshutdown(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cmptlsshutdown(p0) 
	#define CHK_cmptlsshutdown  FALSE
	#define EXP_cmptlsshutdown  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cmptlsshutdown
	#define EXT_cmptlsshutdown
	#define GET_cmptlsshutdown(fl)  CAL_CMGETAPI( "cmptlsshutdown" ) 
	#define CAL_cmptlsshutdown  cmptlsshutdown
	#define CHK_cmptlsshutdown  TRUE
	#define EXP_cmptlsshutdown  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsshutdown", (RTS_UINTPTR)cmptlsshutdown, 1, 0x2AA5307D, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPTLS_IMPLEMENTATION_EXTERNAL)
	#define USE_cmptlsshutdown
	#define EXT_cmptlsshutdown
	#define GET_cmptlsshutdown(fl)  CAL_CMGETAPI( "cmptlsshutdown" ) 
	#define CAL_cmptlsshutdown  cmptlsshutdown
	#define CHK_cmptlsshutdown  TRUE
	#define EXP_cmptlsshutdown  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsshutdown", (RTS_UINTPTR)cmptlsshutdown, 1, 0x2AA5307D, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpTls_Implementationcmptlsshutdown
	#define EXT_CmpTls_Implementationcmptlsshutdown
	#define GET_CmpTls_Implementationcmptlsshutdown  ERR_OK
	#define CAL_CmpTls_Implementationcmptlsshutdown  cmptlsshutdown
	#define CHK_CmpTls_Implementationcmptlsshutdown  TRUE
	#define EXP_CmpTls_Implementationcmptlsshutdown  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsshutdown", (RTS_UINTPTR)cmptlsshutdown, 1, 0x2AA5307D, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_cmptlsshutdown
	#define EXT_cmptlsshutdown
	#define GET_cmptlsshutdown(fl)  CAL_CMGETAPI( "cmptlsshutdown" ) 
	#define CAL_cmptlsshutdown  cmptlsshutdown
	#define CHK_cmptlsshutdown  TRUE
	#define EXP_cmptlsshutdown  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsshutdown", (RTS_UINTPTR)cmptlsshutdown, 1, 0x2AA5307D, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_cmptlsshutdown  PFCMPTLSSHUTDOWN_IEC pfcmptlsshutdown;
	#define EXT_cmptlsshutdown  extern PFCMPTLSSHUTDOWN_IEC pfcmptlsshutdown;
	#define GET_cmptlsshutdown(fl)  s_pfCMGetAPI2( "cmptlsshutdown", (RTS_VOID_FCTPTR *)&pfcmptlsshutdown, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x2AA5307D, 0x03050F00)
	#define CAL_cmptlsshutdown  pfcmptlsshutdown
	#define CHK_cmptlsshutdown  (pfcmptlsshutdown != NULL)
	#define EXP_cmptlsshutdown   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlsshutdown", (RTS_UINTPTR)cmptlsshutdown, 1, 0x2AA5307D, 0x03050F00) 
#endif


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

void CDECL CDECL_EXT cmptlswrite(cmptlswrite_struct *p);
typedef void (CDECL CDECL_EXT* PFCMPTLSWRITE_IEC) (cmptlswrite_struct *p);
#if defined(CMPTLS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CMPTLSWRITE_NOTIMPLEMENTED)
	#define USE_cmptlswrite
	#define EXT_cmptlswrite
	#define GET_cmptlswrite(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cmptlswrite(p0) 
	#define CHK_cmptlswrite  FALSE
	#define EXP_cmptlswrite  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cmptlswrite
	#define EXT_cmptlswrite
	#define GET_cmptlswrite(fl)  CAL_CMGETAPI( "cmptlswrite" ) 
	#define CAL_cmptlswrite  cmptlswrite
	#define CHK_cmptlswrite  TRUE
	#define EXP_cmptlswrite  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlswrite", (RTS_UINTPTR)cmptlswrite, 1, RTSITF_GET_SIGNATURE(0xA1D9E8A7, 0xF01B2E0C), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPTLS_IMPLEMENTATION_EXTERNAL)
	#define USE_cmptlswrite
	#define EXT_cmptlswrite
	#define GET_cmptlswrite(fl)  CAL_CMGETAPI( "cmptlswrite" ) 
	#define CAL_cmptlswrite  cmptlswrite
	#define CHK_cmptlswrite  TRUE
	#define EXP_cmptlswrite  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlswrite", (RTS_UINTPTR)cmptlswrite, 1, RTSITF_GET_SIGNATURE(0xA1D9E8A7, 0xF01B2E0C), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpTls_Implementationcmptlswrite
	#define EXT_CmpTls_Implementationcmptlswrite
	#define GET_CmpTls_Implementationcmptlswrite  ERR_OK
	#define CAL_CmpTls_Implementationcmptlswrite  cmptlswrite
	#define CHK_CmpTls_Implementationcmptlswrite  TRUE
	#define EXP_CmpTls_Implementationcmptlswrite  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlswrite", (RTS_UINTPTR)cmptlswrite, 1, RTSITF_GET_SIGNATURE(0xA1D9E8A7, 0xF01B2E0C), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_cmptlswrite
	#define EXT_cmptlswrite
	#define GET_cmptlswrite(fl)  CAL_CMGETAPI( "cmptlswrite" ) 
	#define CAL_cmptlswrite  cmptlswrite
	#define CHK_cmptlswrite  TRUE
	#define EXP_cmptlswrite  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlswrite", (RTS_UINTPTR)cmptlswrite, 1, RTSITF_GET_SIGNATURE(0xA1D9E8A7, 0xF01B2E0C), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_cmptlswrite  PFCMPTLSWRITE_IEC pfcmptlswrite;
	#define EXT_cmptlswrite  extern PFCMPTLSWRITE_IEC pfcmptlswrite;
	#define GET_cmptlswrite(fl)  s_pfCMGetAPI2( "cmptlswrite", (RTS_VOID_FCTPTR *)&pfcmptlswrite, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0xA1D9E8A7, 0xF01B2E0C), 0x03050F00)
	#define CAL_cmptlswrite  pfcmptlswrite
	#define CHK_cmptlswrite  (pfcmptlswrite != NULL)
	#define EXP_cmptlswrite   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cmptlswrite", (RTS_UINTPTR)cmptlswrite, 1, RTSITF_GET_SIGNATURE(0xA1D9E8A7, 0xF01B2E0C), 0x03050F00) 
#endif


#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/




typedef struct
{
	IBase_C *pBase;
} ICmpTls_Implementation_C;

#ifdef CPLUSPLUS
class ICmpTls_Implementation : public IBase
{
	public:
};
	#ifndef ITF_CmpTls_Implementation
		#define ITF_CmpTls_Implementation static ICmpTls_Implementation *pICmpTls_Implementation = NULL;
	#endif
	#define EXTITF_CmpTls_Implementation
#else	/*CPLUSPLUS*/
	typedef ICmpTls_Implementation_C		ICmpTls_Implementation;
	#ifndef ITF_CmpTls_Implementation
		#define ITF_CmpTls_Implementation
	#endif
	#define EXTITF_CmpTls_Implementation
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_CMPTLS_IMPLEMENTATIONITF_H_*/
