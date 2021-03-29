 /**
 * <interfacename>CmpCrypto_Implementation</interfacename>
 * <description></description>
 *
 * <copyright></copyright>
 */


	
	
#ifndef _CMPCRYPTO_IMPLEMENTATIONITF_H_
#define _CMPCRYPTO_IMPLEMENTATIONITF_H_

#include "CmpStd.h"

 

 




/** EXTERN LIB SECTION BEGIN **/
/*  Comments are ignored for m4 compiler so restructured text can be used.  */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Perform a asymmetric decryption using the algorithm handle.
 * :return: Result of the operation
 */
typedef struct tagcryptoasymmetricdecrypt_struct
{
	RTS_IEC_HANDLE hAlgo;				/* VAR_INPUT */	/* Handle to the algorithm. */
	RtsByteString *pCipherText;			/* VAR_INPUT */	/* Data to be decrypted */
	RtsCryptoKey privateKey;			/* VAR_INPUT */	/* Private key used to decrypt the data. */
	RtsByteString *pPlainText;			/* VAR_INPUT */	/* Decrypted data. */
	RTS_IEC_RESULT CryptoAsymmetricDecrypt;	/* VAR_OUTPUT */	
} cryptoasymmetricdecrypt_struct;

void CDECL CDECL_EXT cryptoasymmetricdecrypt(cryptoasymmetricdecrypt_struct *p);
typedef void (CDECL CDECL_EXT* PFCRYPTOASYMMETRICDECRYPT_IEC) (cryptoasymmetricdecrypt_struct *p);
#if defined(CMPCRYPTO_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CRYPTOASYMMETRICDECRYPT_NOTIMPLEMENTED)
	#define USE_cryptoasymmetricdecrypt
	#define EXT_cryptoasymmetricdecrypt
	#define GET_cryptoasymmetricdecrypt(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cryptoasymmetricdecrypt(p0) 
	#define CHK_cryptoasymmetricdecrypt  FALSE
	#define EXP_cryptoasymmetricdecrypt  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cryptoasymmetricdecrypt
	#define EXT_cryptoasymmetricdecrypt
	#define GET_cryptoasymmetricdecrypt(fl)  CAL_CMGETAPI( "cryptoasymmetricdecrypt" ) 
	#define CAL_cryptoasymmetricdecrypt  cryptoasymmetricdecrypt
	#define CHK_cryptoasymmetricdecrypt  TRUE
	#define EXP_cryptoasymmetricdecrypt  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptoasymmetricdecrypt", (RTS_UINTPTR)cryptoasymmetricdecrypt, 1, 0x126B86CC, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPCRYPTO_IMPLEMENTATION_EXTERNAL)
	#define USE_cryptoasymmetricdecrypt
	#define EXT_cryptoasymmetricdecrypt
	#define GET_cryptoasymmetricdecrypt(fl)  CAL_CMGETAPI( "cryptoasymmetricdecrypt" ) 
	#define CAL_cryptoasymmetricdecrypt  cryptoasymmetricdecrypt
	#define CHK_cryptoasymmetricdecrypt  TRUE
	#define EXP_cryptoasymmetricdecrypt  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptoasymmetricdecrypt", (RTS_UINTPTR)cryptoasymmetricdecrypt, 1, 0x126B86CC, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpCrypto_Implementationcryptoasymmetricdecrypt
	#define EXT_CmpCrypto_Implementationcryptoasymmetricdecrypt
	#define GET_CmpCrypto_Implementationcryptoasymmetricdecrypt  ERR_OK
	#define CAL_CmpCrypto_Implementationcryptoasymmetricdecrypt  cryptoasymmetricdecrypt
	#define CHK_CmpCrypto_Implementationcryptoasymmetricdecrypt  TRUE
	#define EXP_CmpCrypto_Implementationcryptoasymmetricdecrypt  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptoasymmetricdecrypt", (RTS_UINTPTR)cryptoasymmetricdecrypt, 1, 0x126B86CC, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_cryptoasymmetricdecrypt
	#define EXT_cryptoasymmetricdecrypt
	#define GET_cryptoasymmetricdecrypt(fl)  CAL_CMGETAPI( "cryptoasymmetricdecrypt" ) 
	#define CAL_cryptoasymmetricdecrypt  cryptoasymmetricdecrypt
	#define CHK_cryptoasymmetricdecrypt  TRUE
	#define EXP_cryptoasymmetricdecrypt  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptoasymmetricdecrypt", (RTS_UINTPTR)cryptoasymmetricdecrypt, 1, 0x126B86CC, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_cryptoasymmetricdecrypt  PFCRYPTOASYMMETRICDECRYPT_IEC pfcryptoasymmetricdecrypt;
	#define EXT_cryptoasymmetricdecrypt  extern PFCRYPTOASYMMETRICDECRYPT_IEC pfcryptoasymmetricdecrypt;
	#define GET_cryptoasymmetricdecrypt(fl)  s_pfCMGetAPI2( "cryptoasymmetricdecrypt", (RTS_VOID_FCTPTR *)&pfcryptoasymmetricdecrypt, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x126B86CC, 0x03051000)
	#define CAL_cryptoasymmetricdecrypt  pfcryptoasymmetricdecrypt
	#define CHK_cryptoasymmetricdecrypt  (pfcryptoasymmetricdecrypt != NULL)
	#define EXP_cryptoasymmetricdecrypt   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptoasymmetricdecrypt", (RTS_UINTPTR)cryptoasymmetricdecrypt, 1, 0x126B86CC, 0x03051000) 
#endif


/**
 * Perform a asymmetric encryption using the algorithm handle.
 * :return: Result of the operation
 */
typedef struct tagcryptoasymmetricencrypt_struct
{
	RTS_IEC_HANDLE hAlgo;				/* VAR_INPUT */	/* Handle to the algorithm. */
	RtsByteString *pPlainText;			/* VAR_INPUT */	/* Data to be encrypted */
	RtsCryptoKey publicKey;				/* VAR_INPUT */	/* Public key used to encrypt the data. */
	RtsByteString *pCipherText;			/* VAR_INPUT */	/* Encrypted data. */
	RTS_IEC_RESULT CryptoAsymmetricEncrypt;	/* VAR_OUTPUT */	
} cryptoasymmetricencrypt_struct;

void CDECL CDECL_EXT cryptoasymmetricencrypt(cryptoasymmetricencrypt_struct *p);
typedef void (CDECL CDECL_EXT* PFCRYPTOASYMMETRICENCRYPT_IEC) (cryptoasymmetricencrypt_struct *p);
#if defined(CMPCRYPTO_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CRYPTOASYMMETRICENCRYPT_NOTIMPLEMENTED)
	#define USE_cryptoasymmetricencrypt
	#define EXT_cryptoasymmetricencrypt
	#define GET_cryptoasymmetricencrypt(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cryptoasymmetricencrypt(p0) 
	#define CHK_cryptoasymmetricencrypt  FALSE
	#define EXP_cryptoasymmetricencrypt  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cryptoasymmetricencrypt
	#define EXT_cryptoasymmetricencrypt
	#define GET_cryptoasymmetricencrypt(fl)  CAL_CMGETAPI( "cryptoasymmetricencrypt" ) 
	#define CAL_cryptoasymmetricencrypt  cryptoasymmetricencrypt
	#define CHK_cryptoasymmetricencrypt  TRUE
	#define EXP_cryptoasymmetricencrypt  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptoasymmetricencrypt", (RTS_UINTPTR)cryptoasymmetricencrypt, 1, 0xC14613D0, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPCRYPTO_IMPLEMENTATION_EXTERNAL)
	#define USE_cryptoasymmetricencrypt
	#define EXT_cryptoasymmetricencrypt
	#define GET_cryptoasymmetricencrypt(fl)  CAL_CMGETAPI( "cryptoasymmetricencrypt" ) 
	#define CAL_cryptoasymmetricencrypt  cryptoasymmetricencrypt
	#define CHK_cryptoasymmetricencrypt  TRUE
	#define EXP_cryptoasymmetricencrypt  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptoasymmetricencrypt", (RTS_UINTPTR)cryptoasymmetricencrypt, 1, 0xC14613D0, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpCrypto_Implementationcryptoasymmetricencrypt
	#define EXT_CmpCrypto_Implementationcryptoasymmetricencrypt
	#define GET_CmpCrypto_Implementationcryptoasymmetricencrypt  ERR_OK
	#define CAL_CmpCrypto_Implementationcryptoasymmetricencrypt  cryptoasymmetricencrypt
	#define CHK_CmpCrypto_Implementationcryptoasymmetricencrypt  TRUE
	#define EXP_CmpCrypto_Implementationcryptoasymmetricencrypt  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptoasymmetricencrypt", (RTS_UINTPTR)cryptoasymmetricencrypt, 1, 0xC14613D0, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_cryptoasymmetricencrypt
	#define EXT_cryptoasymmetricencrypt
	#define GET_cryptoasymmetricencrypt(fl)  CAL_CMGETAPI( "cryptoasymmetricencrypt" ) 
	#define CAL_cryptoasymmetricencrypt  cryptoasymmetricencrypt
	#define CHK_cryptoasymmetricencrypt  TRUE
	#define EXP_cryptoasymmetricencrypt  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptoasymmetricencrypt", (RTS_UINTPTR)cryptoasymmetricencrypt, 1, 0xC14613D0, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_cryptoasymmetricencrypt  PFCRYPTOASYMMETRICENCRYPT_IEC pfcryptoasymmetricencrypt;
	#define EXT_cryptoasymmetricencrypt  extern PFCRYPTOASYMMETRICENCRYPT_IEC pfcryptoasymmetricencrypt;
	#define GET_cryptoasymmetricencrypt(fl)  s_pfCMGetAPI2( "cryptoasymmetricencrypt", (RTS_VOID_FCTPTR *)&pfcryptoasymmetricencrypt, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xC14613D0, 0x03051000)
	#define CAL_cryptoasymmetricencrypt  pfcryptoasymmetricencrypt
	#define CHK_cryptoasymmetricencrypt  (pfcryptoasymmetricencrypt != NULL)
	#define EXP_cryptoasymmetricencrypt   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptoasymmetricencrypt", (RTS_UINTPTR)cryptoasymmetricencrypt, 1, 0xC14613D0, 0x03051000) 
#endif


/**
 * This function can be used to delete a private key from the components internal data store.
 * :return: Result of the operation
 */
typedef struct tagcryptodeleteprivatekey_struct
{
	RtsByteString keyIdentifier;		/* VAR_INPUT */	/* The identifier of the key got from CryptoStorePrivateKey. */
	RTS_IEC_RESULT CryptoDeletePrivateKey;	/* VAR_OUTPUT */	
} cryptodeleteprivatekey_struct;

void CDECL CDECL_EXT cryptodeleteprivatekey(cryptodeleteprivatekey_struct *p);
typedef void (CDECL CDECL_EXT* PFCRYPTODELETEPRIVATEKEY_IEC) (cryptodeleteprivatekey_struct *p);
#if defined(CMPCRYPTO_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CRYPTODELETEPRIVATEKEY_NOTIMPLEMENTED)
	#define USE_cryptodeleteprivatekey
	#define EXT_cryptodeleteprivatekey
	#define GET_cryptodeleteprivatekey(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cryptodeleteprivatekey(p0) 
	#define CHK_cryptodeleteprivatekey  FALSE
	#define EXP_cryptodeleteprivatekey  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cryptodeleteprivatekey
	#define EXT_cryptodeleteprivatekey
	#define GET_cryptodeleteprivatekey(fl)  CAL_CMGETAPI( "cryptodeleteprivatekey" ) 
	#define CAL_cryptodeleteprivatekey  cryptodeleteprivatekey
	#define CHK_cryptodeleteprivatekey  TRUE
	#define EXP_cryptodeleteprivatekey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptodeleteprivatekey", (RTS_UINTPTR)cryptodeleteprivatekey, 1, 0xDE36F1DF, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPCRYPTO_IMPLEMENTATION_EXTERNAL)
	#define USE_cryptodeleteprivatekey
	#define EXT_cryptodeleteprivatekey
	#define GET_cryptodeleteprivatekey(fl)  CAL_CMGETAPI( "cryptodeleteprivatekey" ) 
	#define CAL_cryptodeleteprivatekey  cryptodeleteprivatekey
	#define CHK_cryptodeleteprivatekey  TRUE
	#define EXP_cryptodeleteprivatekey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptodeleteprivatekey", (RTS_UINTPTR)cryptodeleteprivatekey, 1, 0xDE36F1DF, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpCrypto_Implementationcryptodeleteprivatekey
	#define EXT_CmpCrypto_Implementationcryptodeleteprivatekey
	#define GET_CmpCrypto_Implementationcryptodeleteprivatekey  ERR_OK
	#define CAL_CmpCrypto_Implementationcryptodeleteprivatekey  cryptodeleteprivatekey
	#define CHK_CmpCrypto_Implementationcryptodeleteprivatekey  TRUE
	#define EXP_CmpCrypto_Implementationcryptodeleteprivatekey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptodeleteprivatekey", (RTS_UINTPTR)cryptodeleteprivatekey, 1, 0xDE36F1DF, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_cryptodeleteprivatekey
	#define EXT_cryptodeleteprivatekey
	#define GET_cryptodeleteprivatekey(fl)  CAL_CMGETAPI( "cryptodeleteprivatekey" ) 
	#define CAL_cryptodeleteprivatekey  cryptodeleteprivatekey
	#define CHK_cryptodeleteprivatekey  TRUE
	#define EXP_cryptodeleteprivatekey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptodeleteprivatekey", (RTS_UINTPTR)cryptodeleteprivatekey, 1, 0xDE36F1DF, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_cryptodeleteprivatekey  PFCRYPTODELETEPRIVATEKEY_IEC pfcryptodeleteprivatekey;
	#define EXT_cryptodeleteprivatekey  extern PFCRYPTODELETEPRIVATEKEY_IEC pfcryptodeleteprivatekey;
	#define GET_cryptodeleteprivatekey(fl)  s_pfCMGetAPI2( "cryptodeleteprivatekey", (RTS_VOID_FCTPTR *)&pfcryptodeleteprivatekey, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xDE36F1DF, 0x03051000)
	#define CAL_cryptodeleteprivatekey  pfcryptodeleteprivatekey
	#define CHK_cryptodeleteprivatekey  (pfcryptodeleteprivatekey != NULL)
	#define EXP_cryptodeleteprivatekey   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptodeleteprivatekey", (RTS_UINTPTR)cryptodeleteprivatekey, 1, 0xDE36F1DF, 0x03051000) 
#endif


/**
 * This Function derives a new key FROM an existing secret (key) AND an corresponding salt. 
 * The functions generates keys of the requested size which is given in pDerivedKey->ui32MaxLen. If setup 
 * properly this function provides a secure way to store passwords within the file system. By now two
 * classes of algorithms can be use:
 *
 *	    1. P_SHA(1, 256): This algorithm can be used to derive session keys from some kind of secret data. 
 *        If this algorithm is used the pSpecificParameters is not evaluated an should be NULL. This 
 *        algorithm is quite fast.
 *
 *	    2. SCRYPT: This algorithm can be used to generate strong keys from weak passwords, or to store passwords 
 *        in a secure way within the file system. This algorithm makes use of the pSpecificParameters and 
 *        requires this parameter. Depending on the configuration given in pSpecificParameters this algorithm 
 *        is time and memory consuming. For details see RFC-7914.
 * :return: Result of the operation.
 *    - ERR_OK: The key was derived successfully.
 *    - ERR_INVALID_HANDLE: hAlgo was not a valid handle to derive keys.
 *    - ERR_PARAMETER: One of the other parameters was invalid.
 *    - ERR_FAILED: some internal error happened.
 */
typedef struct tagcryptoderivekey_struct
{
	RTS_IEC_HANDLE hAlgo;				/* VAR_INPUT */	/* Handle of the used algorithm. Should be one of RTSCRYPTOID_KDF_* algorithms. */
	RtsByteString *pKey;				/* VAR_INPUT */	/* The key that should be derived. The function reads pKey->ui32Len bytes of the given buffer. */
	RtsByteString *pSalt;				/* VAR_INPUT */	/* The SALT that should be used to derive the key. The function reads pSalt->ui32Len bytes of the given buffer. */
	RtsKdfParameter *pSpecificParameters;	/* VAR_INPUT */	/* Some additional algorithm specific parameters. By now only used for scrypt. */
	RtsByteString *pDerivedKey;			/* VAR_INPUT */	/* Destination where to store the derived key. The function generates a key with the size of pDerivedKey->ui32MaxLen. The size of the derived key will be stored in pDerivedKey->ui32Len. */
	RTS_IEC_RESULT CryptoDeriveKey;		/* VAR_OUTPUT */	
} cryptoderivekey_struct;

void CDECL CDECL_EXT cryptoderivekey(cryptoderivekey_struct *p);
typedef void (CDECL CDECL_EXT* PFCRYPTODERIVEKEY_IEC) (cryptoderivekey_struct *p);
#if defined(CMPCRYPTO_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CRYPTODERIVEKEY_NOTIMPLEMENTED)
	#define USE_cryptoderivekey
	#define EXT_cryptoderivekey
	#define GET_cryptoderivekey(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cryptoderivekey(p0) 
	#define CHK_cryptoderivekey  FALSE
	#define EXP_cryptoderivekey  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cryptoderivekey
	#define EXT_cryptoderivekey
	#define GET_cryptoderivekey(fl)  CAL_CMGETAPI( "cryptoderivekey" ) 
	#define CAL_cryptoderivekey  cryptoderivekey
	#define CHK_cryptoderivekey  TRUE
	#define EXP_cryptoderivekey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptoderivekey", (RTS_UINTPTR)cryptoderivekey, 1, 0x31C54B5F, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPCRYPTO_IMPLEMENTATION_EXTERNAL)
	#define USE_cryptoderivekey
	#define EXT_cryptoderivekey
	#define GET_cryptoderivekey(fl)  CAL_CMGETAPI( "cryptoderivekey" ) 
	#define CAL_cryptoderivekey  cryptoderivekey
	#define CHK_cryptoderivekey  TRUE
	#define EXP_cryptoderivekey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptoderivekey", (RTS_UINTPTR)cryptoderivekey, 1, 0x31C54B5F, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpCrypto_Implementationcryptoderivekey
	#define EXT_CmpCrypto_Implementationcryptoderivekey
	#define GET_CmpCrypto_Implementationcryptoderivekey  ERR_OK
	#define CAL_CmpCrypto_Implementationcryptoderivekey  cryptoderivekey
	#define CHK_CmpCrypto_Implementationcryptoderivekey  TRUE
	#define EXP_CmpCrypto_Implementationcryptoderivekey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptoderivekey", (RTS_UINTPTR)cryptoderivekey, 1, 0x31C54B5F, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_cryptoderivekey
	#define EXT_cryptoderivekey
	#define GET_cryptoderivekey(fl)  CAL_CMGETAPI( "cryptoderivekey" ) 
	#define CAL_cryptoderivekey  cryptoderivekey
	#define CHK_cryptoderivekey  TRUE
	#define EXP_cryptoderivekey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptoderivekey", (RTS_UINTPTR)cryptoderivekey, 1, 0x31C54B5F, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_cryptoderivekey  PFCRYPTODERIVEKEY_IEC pfcryptoderivekey;
	#define EXT_cryptoderivekey  extern PFCRYPTODERIVEKEY_IEC pfcryptoderivekey;
	#define GET_cryptoderivekey(fl)  s_pfCMGetAPI2( "cryptoderivekey", (RTS_VOID_FCTPTR *)&pfcryptoderivekey, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x31C54B5F, 0x03051000)
	#define CAL_cryptoderivekey  pfcryptoderivekey
	#define CHK_cryptoderivekey  (pfcryptoderivekey != NULL)
	#define EXP_cryptoderivekey   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptoderivekey", (RTS_UINTPTR)cryptoderivekey, 1, 0x31C54B5F, 0x03051000) 
#endif


/**
 * This function can be used to export asymmetric keys
 * :return: Result of the operation. ERR_NOT_SUPPORTED if the key does not support exporting.
 */
typedef struct tagcryptoexportasymmetrickey_struct
{
	RtsCryptoKey key;					/* VAR_INPUT */	/* The key to be exported. */
	RTS_IEC_BOOL xBase64;				/* VAR_INPUT */	/* Export the key in BASE64 encoding. Otherwise ASN.1 will be used. */
	RTS_IEC_BOOL xPrivateKey;			/* VAR_INPUT */	/* FALSE: Export the public key. TRUE: Export the private key. */
	RtsByteString *pData;				/* VAR_INPUT */	/* Pointer to the buffer where to store the key. */
	RTS_IEC_RESULT CryptoExportAsymmetricKey;	/* VAR_OUTPUT */	
} cryptoexportasymmetrickey_struct;

void CDECL CDECL_EXT cryptoexportasymmetrickey(cryptoexportasymmetrickey_struct *p);
typedef void (CDECL CDECL_EXT* PFCRYPTOEXPORTASYMMETRICKEY_IEC) (cryptoexportasymmetrickey_struct *p);
#if defined(CMPCRYPTO_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CRYPTOEXPORTASYMMETRICKEY_NOTIMPLEMENTED)
	#define USE_cryptoexportasymmetrickey
	#define EXT_cryptoexportasymmetrickey
	#define GET_cryptoexportasymmetrickey(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cryptoexportasymmetrickey(p0) 
	#define CHK_cryptoexportasymmetrickey  FALSE
	#define EXP_cryptoexportasymmetrickey  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cryptoexportasymmetrickey
	#define EXT_cryptoexportasymmetrickey
	#define GET_cryptoexportasymmetrickey(fl)  CAL_CMGETAPI( "cryptoexportasymmetrickey" ) 
	#define CAL_cryptoexportasymmetrickey  cryptoexportasymmetrickey
	#define CHK_cryptoexportasymmetrickey  TRUE
	#define EXP_cryptoexportasymmetrickey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptoexportasymmetrickey", (RTS_UINTPTR)cryptoexportasymmetrickey, 1, 0x4628FE5D, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPCRYPTO_IMPLEMENTATION_EXTERNAL)
	#define USE_cryptoexportasymmetrickey
	#define EXT_cryptoexportasymmetrickey
	#define GET_cryptoexportasymmetrickey(fl)  CAL_CMGETAPI( "cryptoexportasymmetrickey" ) 
	#define CAL_cryptoexportasymmetrickey  cryptoexportasymmetrickey
	#define CHK_cryptoexportasymmetrickey  TRUE
	#define EXP_cryptoexportasymmetrickey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptoexportasymmetrickey", (RTS_UINTPTR)cryptoexportasymmetrickey, 1, 0x4628FE5D, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpCrypto_Implementationcryptoexportasymmetrickey
	#define EXT_CmpCrypto_Implementationcryptoexportasymmetrickey
	#define GET_CmpCrypto_Implementationcryptoexportasymmetrickey  ERR_OK
	#define CAL_CmpCrypto_Implementationcryptoexportasymmetrickey  cryptoexportasymmetrickey
	#define CHK_CmpCrypto_Implementationcryptoexportasymmetrickey  TRUE
	#define EXP_CmpCrypto_Implementationcryptoexportasymmetrickey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptoexportasymmetrickey", (RTS_UINTPTR)cryptoexportasymmetrickey, 1, 0x4628FE5D, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_cryptoexportasymmetrickey
	#define EXT_cryptoexportasymmetrickey
	#define GET_cryptoexportasymmetrickey(fl)  CAL_CMGETAPI( "cryptoexportasymmetrickey" ) 
	#define CAL_cryptoexportasymmetrickey  cryptoexportasymmetrickey
	#define CHK_cryptoexportasymmetrickey  TRUE
	#define EXP_cryptoexportasymmetrickey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptoexportasymmetrickey", (RTS_UINTPTR)cryptoexportasymmetrickey, 1, 0x4628FE5D, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_cryptoexportasymmetrickey  PFCRYPTOEXPORTASYMMETRICKEY_IEC pfcryptoexportasymmetrickey;
	#define EXT_cryptoexportasymmetrickey  extern PFCRYPTOEXPORTASYMMETRICKEY_IEC pfcryptoexportasymmetrickey;
	#define GET_cryptoexportasymmetrickey(fl)  s_pfCMGetAPI2( "cryptoexportasymmetrickey", (RTS_VOID_FCTPTR *)&pfcryptoexportasymmetrickey, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x4628FE5D, 0x03051000)
	#define CAL_cryptoexportasymmetrickey  pfcryptoexportasymmetrickey
	#define CHK_cryptoexportasymmetrickey  (pfcryptoexportasymmetrickey != NULL)
	#define EXP_cryptoexportasymmetrickey   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptoexportasymmetrickey", (RTS_UINTPTR)cryptoexportasymmetrickey, 1, 0x4628FE5D, 0x03051000) 
#endif


/**
 * Generate an asymmetric key pair that can be used by the specivied algorithm. 
 * :return: Result of the operation
 */
typedef struct tagcryptogenerateasymmetrickeypair_struct
{
	RTS_IEC_HANDLE hAlgo;				/* VAR_INPUT */	/* Handle to the algorithm. */
	RTS_IEC_UDINT ui32KeyLen;			/* VAR_INPUT */	/* Lenght of the key in bytes. May be omitted on ECC keys. */
	RtsCryptoKey *pKeyPair;				/* VAR_INPUT */	/* The generated key pair. Can be used for public or private key operations. */
	RTS_IEC_BOOL xPrivateKeyExportable;	/* VAR_INPUT */	/* Define if the private key should be exportable using CrpyotExportAsymmetricKey */
	RTS_IEC_RESULT CryptoGenerateAsymmetricKeyPair;	/* VAR_OUTPUT */	
} cryptogenerateasymmetrickeypair_struct;

void CDECL CDECL_EXT cryptogenerateasymmetrickeypair(cryptogenerateasymmetrickeypair_struct *p);
typedef void (CDECL CDECL_EXT* PFCRYPTOGENERATEASYMMETRICKEYPAIR_IEC) (cryptogenerateasymmetrickeypair_struct *p);
#if defined(CMPCRYPTO_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CRYPTOGENERATEASYMMETRICKEYPAIR_NOTIMPLEMENTED)
	#define USE_cryptogenerateasymmetrickeypair
	#define EXT_cryptogenerateasymmetrickeypair
	#define GET_cryptogenerateasymmetrickeypair(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cryptogenerateasymmetrickeypair(p0) 
	#define CHK_cryptogenerateasymmetrickeypair  FALSE
	#define EXP_cryptogenerateasymmetrickeypair  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cryptogenerateasymmetrickeypair
	#define EXT_cryptogenerateasymmetrickeypair
	#define GET_cryptogenerateasymmetrickeypair(fl)  CAL_CMGETAPI( "cryptogenerateasymmetrickeypair" ) 
	#define CAL_cryptogenerateasymmetrickeypair  cryptogenerateasymmetrickeypair
	#define CHK_cryptogenerateasymmetrickeypair  TRUE
	#define EXP_cryptogenerateasymmetrickeypair  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogenerateasymmetrickeypair", (RTS_UINTPTR)cryptogenerateasymmetrickeypair, 1, 0x0AF43BA3, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPCRYPTO_IMPLEMENTATION_EXTERNAL)
	#define USE_cryptogenerateasymmetrickeypair
	#define EXT_cryptogenerateasymmetrickeypair
	#define GET_cryptogenerateasymmetrickeypair(fl)  CAL_CMGETAPI( "cryptogenerateasymmetrickeypair" ) 
	#define CAL_cryptogenerateasymmetrickeypair  cryptogenerateasymmetrickeypair
	#define CHK_cryptogenerateasymmetrickeypair  TRUE
	#define EXP_cryptogenerateasymmetrickeypair  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogenerateasymmetrickeypair", (RTS_UINTPTR)cryptogenerateasymmetrickeypair, 1, 0x0AF43BA3, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpCrypto_Implementationcryptogenerateasymmetrickeypair
	#define EXT_CmpCrypto_Implementationcryptogenerateasymmetrickeypair
	#define GET_CmpCrypto_Implementationcryptogenerateasymmetrickeypair  ERR_OK
	#define CAL_CmpCrypto_Implementationcryptogenerateasymmetrickeypair  cryptogenerateasymmetrickeypair
	#define CHK_CmpCrypto_Implementationcryptogenerateasymmetrickeypair  TRUE
	#define EXP_CmpCrypto_Implementationcryptogenerateasymmetrickeypair  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogenerateasymmetrickeypair", (RTS_UINTPTR)cryptogenerateasymmetrickeypair, 1, 0x0AF43BA3, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_cryptogenerateasymmetrickeypair
	#define EXT_cryptogenerateasymmetrickeypair
	#define GET_cryptogenerateasymmetrickeypair(fl)  CAL_CMGETAPI( "cryptogenerateasymmetrickeypair" ) 
	#define CAL_cryptogenerateasymmetrickeypair  cryptogenerateasymmetrickeypair
	#define CHK_cryptogenerateasymmetrickeypair  TRUE
	#define EXP_cryptogenerateasymmetrickeypair  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogenerateasymmetrickeypair", (RTS_UINTPTR)cryptogenerateasymmetrickeypair, 1, 0x0AF43BA3, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_cryptogenerateasymmetrickeypair  PFCRYPTOGENERATEASYMMETRICKEYPAIR_IEC pfcryptogenerateasymmetrickeypair;
	#define EXT_cryptogenerateasymmetrickeypair  extern PFCRYPTOGENERATEASYMMETRICKEYPAIR_IEC pfcryptogenerateasymmetrickeypair;
	#define GET_cryptogenerateasymmetrickeypair(fl)  s_pfCMGetAPI2( "cryptogenerateasymmetrickeypair", (RTS_VOID_FCTPTR *)&pfcryptogenerateasymmetrickeypair, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x0AF43BA3, 0x03051000)
	#define CAL_cryptogenerateasymmetrickeypair  pfcryptogenerateasymmetrickeypair
	#define CHK_cryptogenerateasymmetrickeypair  (pfcryptogenerateasymmetrickeypair != NULL)
	#define EXP_cryptogenerateasymmetrickeypair   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogenerateasymmetrickeypair", (RTS_UINTPTR)cryptogenerateasymmetrickeypair, 1, 0x0AF43BA3, 0x03051000) 
#endif


/**
 * Calculate the message digest of the given data.
 * :return: Result of the operation
 */
typedef struct tagcryptogeneratehash_struct
{
	RTS_IEC_HANDLE hAlgo;				/* VAR_INPUT */	/* Handle to the algorithm. */
	RtsByteString *pData;				/* VAR_INPUT */	/* Data to calculate the message digest. */
	RtsByteString *pHash;				/* VAR_INPUT */	/* Calculated message digest. */
	RTS_IEC_RESULT CryptoGenerateHash;	/* VAR_OUTPUT */	
} cryptogeneratehash_struct;

void CDECL CDECL_EXT cryptogeneratehash(cryptogeneratehash_struct *p);
typedef void (CDECL CDECL_EXT* PFCRYPTOGENERATEHASH_IEC) (cryptogeneratehash_struct *p);
#if defined(CMPCRYPTO_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CRYPTOGENERATEHASH_NOTIMPLEMENTED)
	#define USE_cryptogeneratehash
	#define EXT_cryptogeneratehash
	#define GET_cryptogeneratehash(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cryptogeneratehash(p0) 
	#define CHK_cryptogeneratehash  FALSE
	#define EXP_cryptogeneratehash  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cryptogeneratehash
	#define EXT_cryptogeneratehash
	#define GET_cryptogeneratehash(fl)  CAL_CMGETAPI( "cryptogeneratehash" ) 
	#define CAL_cryptogeneratehash  cryptogeneratehash
	#define CHK_cryptogeneratehash  TRUE
	#define EXP_cryptogeneratehash  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogeneratehash", (RTS_UINTPTR)cryptogeneratehash, 1, 0x34E1A812, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPCRYPTO_IMPLEMENTATION_EXTERNAL)
	#define USE_cryptogeneratehash
	#define EXT_cryptogeneratehash
	#define GET_cryptogeneratehash(fl)  CAL_CMGETAPI( "cryptogeneratehash" ) 
	#define CAL_cryptogeneratehash  cryptogeneratehash
	#define CHK_cryptogeneratehash  TRUE
	#define EXP_cryptogeneratehash  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogeneratehash", (RTS_UINTPTR)cryptogeneratehash, 1, 0x34E1A812, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpCrypto_Implementationcryptogeneratehash
	#define EXT_CmpCrypto_Implementationcryptogeneratehash
	#define GET_CmpCrypto_Implementationcryptogeneratehash  ERR_OK
	#define CAL_CmpCrypto_Implementationcryptogeneratehash  cryptogeneratehash
	#define CHK_CmpCrypto_Implementationcryptogeneratehash  TRUE
	#define EXP_CmpCrypto_Implementationcryptogeneratehash  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogeneratehash", (RTS_UINTPTR)cryptogeneratehash, 1, 0x34E1A812, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_cryptogeneratehash
	#define EXT_cryptogeneratehash
	#define GET_cryptogeneratehash(fl)  CAL_CMGETAPI( "cryptogeneratehash" ) 
	#define CAL_cryptogeneratehash  cryptogeneratehash
	#define CHK_cryptogeneratehash  TRUE
	#define EXP_cryptogeneratehash  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogeneratehash", (RTS_UINTPTR)cryptogeneratehash, 1, 0x34E1A812, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_cryptogeneratehash  PFCRYPTOGENERATEHASH_IEC pfcryptogeneratehash;
	#define EXT_cryptogeneratehash  extern PFCRYPTOGENERATEHASH_IEC pfcryptogeneratehash;
	#define GET_cryptogeneratehash(fl)  s_pfCMGetAPI2( "cryptogeneratehash", (RTS_VOID_FCTPTR *)&pfcryptogeneratehash, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x34E1A812, 0x03051000)
	#define CAL_cryptogeneratehash  pfcryptogeneratehash
	#define CHK_cryptogeneratehash  (pfcryptogeneratehash != NULL)
	#define EXP_cryptogeneratehash   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogeneratehash", (RTS_UINTPTR)cryptogeneratehash, 1, 0x34E1A812, 0x03051000) 
#endif


/**
 * Generate a number of cryptographic strong bytes.
 * :return: Function returns ERR_OK if the bytes could be generated
 */
typedef struct tagcryptogeneraterandomnumber_struct
{
	RTS_IEC_UDINT ui32NumOfRandomBytes;	/* VAR_INPUT */	/* Number of bytes needed. */
	RtsByteString *pRandom;				/* VAR_INPUT */	/* Buffer to store the bytes. */
	RTS_IEC_RESULT CryptoGenerateRandomNumber;	/* VAR_OUTPUT */	
} cryptogeneraterandomnumber_struct;

void CDECL CDECL_EXT cryptogeneraterandomnumber(cryptogeneraterandomnumber_struct *p);
typedef void (CDECL CDECL_EXT* PFCRYPTOGENERATERANDOMNUMBER_IEC) (cryptogeneraterandomnumber_struct *p);
#if defined(CMPCRYPTO_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CRYPTOGENERATERANDOMNUMBER_NOTIMPLEMENTED)
	#define USE_cryptogeneraterandomnumber
	#define EXT_cryptogeneraterandomnumber
	#define GET_cryptogeneraterandomnumber(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cryptogeneraterandomnumber(p0) 
	#define CHK_cryptogeneraterandomnumber  FALSE
	#define EXP_cryptogeneraterandomnumber  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cryptogeneraterandomnumber
	#define EXT_cryptogeneraterandomnumber
	#define GET_cryptogeneraterandomnumber(fl)  CAL_CMGETAPI( "cryptogeneraterandomnumber" ) 
	#define CAL_cryptogeneraterandomnumber  cryptogeneraterandomnumber
	#define CHK_cryptogeneraterandomnumber  TRUE
	#define EXP_cryptogeneraterandomnumber  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogeneraterandomnumber", (RTS_UINTPTR)cryptogeneraterandomnumber, 1, 0xF9FC5437, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPCRYPTO_IMPLEMENTATION_EXTERNAL)
	#define USE_cryptogeneraterandomnumber
	#define EXT_cryptogeneraterandomnumber
	#define GET_cryptogeneraterandomnumber(fl)  CAL_CMGETAPI( "cryptogeneraterandomnumber" ) 
	#define CAL_cryptogeneraterandomnumber  cryptogeneraterandomnumber
	#define CHK_cryptogeneraterandomnumber  TRUE
	#define EXP_cryptogeneraterandomnumber  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogeneraterandomnumber", (RTS_UINTPTR)cryptogeneraterandomnumber, 1, 0xF9FC5437, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpCrypto_Implementationcryptogeneraterandomnumber
	#define EXT_CmpCrypto_Implementationcryptogeneraterandomnumber
	#define GET_CmpCrypto_Implementationcryptogeneraterandomnumber  ERR_OK
	#define CAL_CmpCrypto_Implementationcryptogeneraterandomnumber  cryptogeneraterandomnumber
	#define CHK_CmpCrypto_Implementationcryptogeneraterandomnumber  TRUE
	#define EXP_CmpCrypto_Implementationcryptogeneraterandomnumber  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogeneraterandomnumber", (RTS_UINTPTR)cryptogeneraterandomnumber, 1, 0xF9FC5437, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_cryptogeneraterandomnumber
	#define EXT_cryptogeneraterandomnumber
	#define GET_cryptogeneraterandomnumber(fl)  CAL_CMGETAPI( "cryptogeneraterandomnumber" ) 
	#define CAL_cryptogeneraterandomnumber  cryptogeneraterandomnumber
	#define CHK_cryptogeneraterandomnumber  TRUE
	#define EXP_cryptogeneraterandomnumber  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogeneraterandomnumber", (RTS_UINTPTR)cryptogeneraterandomnumber, 1, 0xF9FC5437, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_cryptogeneraterandomnumber  PFCRYPTOGENERATERANDOMNUMBER_IEC pfcryptogeneraterandomnumber;
	#define EXT_cryptogeneraterandomnumber  extern PFCRYPTOGENERATERANDOMNUMBER_IEC pfcryptogeneraterandomnumber;
	#define GET_cryptogeneraterandomnumber(fl)  s_pfCMGetAPI2( "cryptogeneraterandomnumber", (RTS_VOID_FCTPTR *)&pfcryptogeneraterandomnumber, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xF9FC5437, 0x03051000)
	#define CAL_cryptogeneraterandomnumber  pfcryptogeneraterandomnumber
	#define CHK_cryptogeneraterandomnumber  (pfcryptogeneraterandomnumber != NULL)
	#define EXP_cryptogeneraterandomnumber   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogeneraterandomnumber", (RTS_UINTPTR)cryptogeneraterandomnumber, 1, 0xF9FC5437, 0x03051000) 
#endif


/**
 * Get a handle to the algorithm using a specific ID
 * :return: Handle to the crypto algorithm
 */
typedef struct tagcryptogetalgorithmbyid_struct
{
	RTS_IEC_UDINT ui32CryptoID;			/* VAR_INPUT, Enum: RTSCRYPTOID */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Result of the operation. Can be NULL. */
	RTS_IEC_HANDLE CryptoGetAlgorithmById;	/* VAR_OUTPUT */	
} cryptogetalgorithmbyid_struct;

void CDECL CDECL_EXT cryptogetalgorithmbyid(cryptogetalgorithmbyid_struct *p);
typedef void (CDECL CDECL_EXT* PFCRYPTOGETALGORITHMBYID_IEC) (cryptogetalgorithmbyid_struct *p);
#if defined(CMPCRYPTO_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CRYPTOGETALGORITHMBYID_NOTIMPLEMENTED)
	#define USE_cryptogetalgorithmbyid
	#define EXT_cryptogetalgorithmbyid
	#define GET_cryptogetalgorithmbyid(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cryptogetalgorithmbyid(p0) 
	#define CHK_cryptogetalgorithmbyid  FALSE
	#define EXP_cryptogetalgorithmbyid  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cryptogetalgorithmbyid
	#define EXT_cryptogetalgorithmbyid
	#define GET_cryptogetalgorithmbyid(fl)  CAL_CMGETAPI( "cryptogetalgorithmbyid" ) 
	#define CAL_cryptogetalgorithmbyid  cryptogetalgorithmbyid
	#define CHK_cryptogetalgorithmbyid  TRUE
	#define EXP_cryptogetalgorithmbyid  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogetalgorithmbyid", (RTS_UINTPTR)cryptogetalgorithmbyid, 1, 0x3D0776D3, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPCRYPTO_IMPLEMENTATION_EXTERNAL)
	#define USE_cryptogetalgorithmbyid
	#define EXT_cryptogetalgorithmbyid
	#define GET_cryptogetalgorithmbyid(fl)  CAL_CMGETAPI( "cryptogetalgorithmbyid" ) 
	#define CAL_cryptogetalgorithmbyid  cryptogetalgorithmbyid
	#define CHK_cryptogetalgorithmbyid  TRUE
	#define EXP_cryptogetalgorithmbyid  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogetalgorithmbyid", (RTS_UINTPTR)cryptogetalgorithmbyid, 1, 0x3D0776D3, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpCrypto_Implementationcryptogetalgorithmbyid
	#define EXT_CmpCrypto_Implementationcryptogetalgorithmbyid
	#define GET_CmpCrypto_Implementationcryptogetalgorithmbyid  ERR_OK
	#define CAL_CmpCrypto_Implementationcryptogetalgorithmbyid  cryptogetalgorithmbyid
	#define CHK_CmpCrypto_Implementationcryptogetalgorithmbyid  TRUE
	#define EXP_CmpCrypto_Implementationcryptogetalgorithmbyid  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogetalgorithmbyid", (RTS_UINTPTR)cryptogetalgorithmbyid, 1, 0x3D0776D3, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_cryptogetalgorithmbyid
	#define EXT_cryptogetalgorithmbyid
	#define GET_cryptogetalgorithmbyid(fl)  CAL_CMGETAPI( "cryptogetalgorithmbyid" ) 
	#define CAL_cryptogetalgorithmbyid  cryptogetalgorithmbyid
	#define CHK_cryptogetalgorithmbyid  TRUE
	#define EXP_cryptogetalgorithmbyid  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogetalgorithmbyid", (RTS_UINTPTR)cryptogetalgorithmbyid, 1, 0x3D0776D3, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_cryptogetalgorithmbyid  PFCRYPTOGETALGORITHMBYID_IEC pfcryptogetalgorithmbyid;
	#define EXT_cryptogetalgorithmbyid  extern PFCRYPTOGETALGORITHMBYID_IEC pfcryptogetalgorithmbyid;
	#define GET_cryptogetalgorithmbyid(fl)  s_pfCMGetAPI2( "cryptogetalgorithmbyid", (RTS_VOID_FCTPTR *)&pfcryptogetalgorithmbyid, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x3D0776D3, 0x03051000)
	#define CAL_cryptogetalgorithmbyid  pfcryptogetalgorithmbyid
	#define CHK_cryptogetalgorithmbyid  (pfcryptogetalgorithmbyid != NULL)
	#define EXP_cryptogetalgorithmbyid   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogetalgorithmbyid", (RTS_UINTPTR)cryptogetalgorithmbyid, 1, 0x3D0776D3, 0x03051000) 
#endif


/**
 * Get the asymmetric key size in bits.
 * :return: Size of the asymmetric key in bits
 */
typedef struct tagcryptogetasymmetrickeylength_struct
{
	RtsCryptoKey asymmetricKey;			/* VAR_INPUT */	/* Asymmetric key of intrest. */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Operation Result */
	RTS_IEC_UDINT CryptoGetAsymmetricKeyLength;	/* VAR_OUTPUT */	
} cryptogetasymmetrickeylength_struct;

void CDECL CDECL_EXT cryptogetasymmetrickeylength(cryptogetasymmetrickeylength_struct *p);
typedef void (CDECL CDECL_EXT* PFCRYPTOGETASYMMETRICKEYLENGTH_IEC) (cryptogetasymmetrickeylength_struct *p);
#if defined(CMPCRYPTO_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CRYPTOGETASYMMETRICKEYLENGTH_NOTIMPLEMENTED)
	#define USE_cryptogetasymmetrickeylength
	#define EXT_cryptogetasymmetrickeylength
	#define GET_cryptogetasymmetrickeylength(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cryptogetasymmetrickeylength(p0) 
	#define CHK_cryptogetasymmetrickeylength  FALSE
	#define EXP_cryptogetasymmetrickeylength  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cryptogetasymmetrickeylength
	#define EXT_cryptogetasymmetrickeylength
	#define GET_cryptogetasymmetrickeylength(fl)  CAL_CMGETAPI( "cryptogetasymmetrickeylength" ) 
	#define CAL_cryptogetasymmetrickeylength  cryptogetasymmetrickeylength
	#define CHK_cryptogetasymmetrickeylength  TRUE
	#define EXP_cryptogetasymmetrickeylength  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogetasymmetrickeylength", (RTS_UINTPTR)cryptogetasymmetrickeylength, 1, 0, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPCRYPTO_IMPLEMENTATION_EXTERNAL)
	#define USE_cryptogetasymmetrickeylength
	#define EXT_cryptogetasymmetrickeylength
	#define GET_cryptogetasymmetrickeylength(fl)  CAL_CMGETAPI( "cryptogetasymmetrickeylength" ) 
	#define CAL_cryptogetasymmetrickeylength  cryptogetasymmetrickeylength
	#define CHK_cryptogetasymmetrickeylength  TRUE
	#define EXP_cryptogetasymmetrickeylength  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogetasymmetrickeylength", (RTS_UINTPTR)cryptogetasymmetrickeylength, 1, 0, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpCrypto_Implementationcryptogetasymmetrickeylength
	#define EXT_CmpCrypto_Implementationcryptogetasymmetrickeylength
	#define GET_CmpCrypto_Implementationcryptogetasymmetrickeylength  ERR_OK
	#define CAL_CmpCrypto_Implementationcryptogetasymmetrickeylength  cryptogetasymmetrickeylength
	#define CHK_CmpCrypto_Implementationcryptogetasymmetrickeylength  TRUE
	#define EXP_CmpCrypto_Implementationcryptogetasymmetrickeylength  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogetasymmetrickeylength", (RTS_UINTPTR)cryptogetasymmetrickeylength, 1, 0, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_cryptogetasymmetrickeylength
	#define EXT_cryptogetasymmetrickeylength
	#define GET_cryptogetasymmetrickeylength(fl)  CAL_CMGETAPI( "cryptogetasymmetrickeylength" ) 
	#define CAL_cryptogetasymmetrickeylength  cryptogetasymmetrickeylength
	#define CHK_cryptogetasymmetrickeylength  TRUE
	#define EXP_cryptogetasymmetrickeylength  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogetasymmetrickeylength", (RTS_UINTPTR)cryptogetasymmetrickeylength, 1, 0, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_cryptogetasymmetrickeylength  PFCRYPTOGETASYMMETRICKEYLENGTH_IEC pfcryptogetasymmetrickeylength;
	#define EXT_cryptogetasymmetrickeylength  extern PFCRYPTOGETASYMMETRICKEYLENGTH_IEC pfcryptogetasymmetrickeylength;
	#define GET_cryptogetasymmetrickeylength(fl)  s_pfCMGetAPI2( "cryptogetasymmetrickeylength", (RTS_VOID_FCTPTR *)&pfcryptogetasymmetrickeylength, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0, 0x03051000)
	#define CAL_cryptogetasymmetrickeylength  pfcryptogetasymmetrickeylength
	#define CHK_cryptogetasymmetrickeylength  (pfcryptogetasymmetrickeylength != NULL)
	#define EXP_cryptogetasymmetrickeylength   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogetasymmetrickeylength", (RTS_UINTPTR)cryptogetasymmetrickeylength, 1, 0, 0x03051000) 
#endif


/**
 * Get the first algorthm matching the type given. Use this with the GetNext function to iterate over algorthmes of a specific type.
 * :return: Handle to the crypto algorithm
 */
typedef struct tagcryptogetfirstalgorithm_struct
{
	RTS_IEC_UDINT ui32CryptoType;		/* VAR_INPUT, Enum: RTSCRYPTOTYPE */
	RTS_IEC_STRING *pszName;			/* VAR_INPUT */	/* Name of the algorthm. Can be NULL. */
	RTS_IEC_DINT i32MaxNameLen;			/* VAR_INPUT */	/* Maximum length of the name buffer */
	RTS_IEC_UDINT *pui32CryptoID;		/* VAR_INPUT */	/* ID of the algorithm. */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Result of the operation. Can be NULL. */
	RTS_IEC_HANDLE CryptoGetFirstAlgorithm;	/* VAR_OUTPUT */	
} cryptogetfirstalgorithm_struct;

void CDECL CDECL_EXT cryptogetfirstalgorithm(cryptogetfirstalgorithm_struct *p);
typedef void (CDECL CDECL_EXT* PFCRYPTOGETFIRSTALGORITHM_IEC) (cryptogetfirstalgorithm_struct *p);
#if defined(CMPCRYPTO_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CRYPTOGETFIRSTALGORITHM_NOTIMPLEMENTED)
	#define USE_cryptogetfirstalgorithm
	#define EXT_cryptogetfirstalgorithm
	#define GET_cryptogetfirstalgorithm(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cryptogetfirstalgorithm(p0) 
	#define CHK_cryptogetfirstalgorithm  FALSE
	#define EXP_cryptogetfirstalgorithm  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cryptogetfirstalgorithm
	#define EXT_cryptogetfirstalgorithm
	#define GET_cryptogetfirstalgorithm(fl)  CAL_CMGETAPI( "cryptogetfirstalgorithm" ) 
	#define CAL_cryptogetfirstalgorithm  cryptogetfirstalgorithm
	#define CHK_cryptogetfirstalgorithm  TRUE
	#define EXP_cryptogetfirstalgorithm  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogetfirstalgorithm", (RTS_UINTPTR)cryptogetfirstalgorithm, 1, 0xC8A4A345, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPCRYPTO_IMPLEMENTATION_EXTERNAL)
	#define USE_cryptogetfirstalgorithm
	#define EXT_cryptogetfirstalgorithm
	#define GET_cryptogetfirstalgorithm(fl)  CAL_CMGETAPI( "cryptogetfirstalgorithm" ) 
	#define CAL_cryptogetfirstalgorithm  cryptogetfirstalgorithm
	#define CHK_cryptogetfirstalgorithm  TRUE
	#define EXP_cryptogetfirstalgorithm  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogetfirstalgorithm", (RTS_UINTPTR)cryptogetfirstalgorithm, 1, 0xC8A4A345, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpCrypto_Implementationcryptogetfirstalgorithm
	#define EXT_CmpCrypto_Implementationcryptogetfirstalgorithm
	#define GET_CmpCrypto_Implementationcryptogetfirstalgorithm  ERR_OK
	#define CAL_CmpCrypto_Implementationcryptogetfirstalgorithm  cryptogetfirstalgorithm
	#define CHK_CmpCrypto_Implementationcryptogetfirstalgorithm  TRUE
	#define EXP_CmpCrypto_Implementationcryptogetfirstalgorithm  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogetfirstalgorithm", (RTS_UINTPTR)cryptogetfirstalgorithm, 1, 0xC8A4A345, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_cryptogetfirstalgorithm
	#define EXT_cryptogetfirstalgorithm
	#define GET_cryptogetfirstalgorithm(fl)  CAL_CMGETAPI( "cryptogetfirstalgorithm" ) 
	#define CAL_cryptogetfirstalgorithm  cryptogetfirstalgorithm
	#define CHK_cryptogetfirstalgorithm  TRUE
	#define EXP_cryptogetfirstalgorithm  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogetfirstalgorithm", (RTS_UINTPTR)cryptogetfirstalgorithm, 1, 0xC8A4A345, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_cryptogetfirstalgorithm  PFCRYPTOGETFIRSTALGORITHM_IEC pfcryptogetfirstalgorithm;
	#define EXT_cryptogetfirstalgorithm  extern PFCRYPTOGETFIRSTALGORITHM_IEC pfcryptogetfirstalgorithm;
	#define GET_cryptogetfirstalgorithm(fl)  s_pfCMGetAPI2( "cryptogetfirstalgorithm", (RTS_VOID_FCTPTR *)&pfcryptogetfirstalgorithm, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xC8A4A345, 0x03051000)
	#define CAL_cryptogetfirstalgorithm  pfcryptogetfirstalgorithm
	#define CHK_cryptogetfirstalgorithm  (pfcryptogetfirstalgorithm != NULL)
	#define EXP_cryptogetfirstalgorithm   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogetfirstalgorithm", (RTS_UINTPTR)cryptogetfirstalgorithm, 1, 0xC8A4A345, 0x03051000) 
#endif


/**
 * Get the next algorthm matching the type given.
 * :return:  Handle to the crypto algorithm
 */
typedef struct tagcryptogetnextalgorithm_struct
{
	RTS_IEC_HANDLE hCrypto;				/* VAR_INPUT */	/* Handle to the last algorithem. */
	RTS_IEC_UDINT ui32CryptoType;		/* VAR_INPUT, Enum: RTSCRYPTOTYPE */
	RTS_IEC_STRING *pszName;			/* VAR_INPUT */	/* Name of the agorithm. Can be NULL. */
	RTS_IEC_DINT i32MaxNameLen;			/* VAR_INPUT */	/* Maximum length of the name buffer */
	RTS_IEC_UDINT *pui32CryptoID;		/* VAR_INPUT */	/* ID of the agorithm. */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Result of the operation. Can be NULL. */
	RTS_IEC_HANDLE CryptoGetNextAlgorithm;	/* VAR_OUTPUT */	
} cryptogetnextalgorithm_struct;

void CDECL CDECL_EXT cryptogetnextalgorithm(cryptogetnextalgorithm_struct *p);
typedef void (CDECL CDECL_EXT* PFCRYPTOGETNEXTALGORITHM_IEC) (cryptogetnextalgorithm_struct *p);
#if defined(CMPCRYPTO_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CRYPTOGETNEXTALGORITHM_NOTIMPLEMENTED)
	#define USE_cryptogetnextalgorithm
	#define EXT_cryptogetnextalgorithm
	#define GET_cryptogetnextalgorithm(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cryptogetnextalgorithm(p0) 
	#define CHK_cryptogetnextalgorithm  FALSE
	#define EXP_cryptogetnextalgorithm  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cryptogetnextalgorithm
	#define EXT_cryptogetnextalgorithm
	#define GET_cryptogetnextalgorithm(fl)  CAL_CMGETAPI( "cryptogetnextalgorithm" ) 
	#define CAL_cryptogetnextalgorithm  cryptogetnextalgorithm
	#define CHK_cryptogetnextalgorithm  TRUE
	#define EXP_cryptogetnextalgorithm  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogetnextalgorithm", (RTS_UINTPTR)cryptogetnextalgorithm, 1, 0x79EC29C8, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPCRYPTO_IMPLEMENTATION_EXTERNAL)
	#define USE_cryptogetnextalgorithm
	#define EXT_cryptogetnextalgorithm
	#define GET_cryptogetnextalgorithm(fl)  CAL_CMGETAPI( "cryptogetnextalgorithm" ) 
	#define CAL_cryptogetnextalgorithm  cryptogetnextalgorithm
	#define CHK_cryptogetnextalgorithm  TRUE
	#define EXP_cryptogetnextalgorithm  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogetnextalgorithm", (RTS_UINTPTR)cryptogetnextalgorithm, 1, 0x79EC29C8, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpCrypto_Implementationcryptogetnextalgorithm
	#define EXT_CmpCrypto_Implementationcryptogetnextalgorithm
	#define GET_CmpCrypto_Implementationcryptogetnextalgorithm  ERR_OK
	#define CAL_CmpCrypto_Implementationcryptogetnextalgorithm  cryptogetnextalgorithm
	#define CHK_CmpCrypto_Implementationcryptogetnextalgorithm  TRUE
	#define EXP_CmpCrypto_Implementationcryptogetnextalgorithm  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogetnextalgorithm", (RTS_UINTPTR)cryptogetnextalgorithm, 1, 0x79EC29C8, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_cryptogetnextalgorithm
	#define EXT_cryptogetnextalgorithm
	#define GET_cryptogetnextalgorithm(fl)  CAL_CMGETAPI( "cryptogetnextalgorithm" ) 
	#define CAL_cryptogetnextalgorithm  cryptogetnextalgorithm
	#define CHK_cryptogetnextalgorithm  TRUE
	#define EXP_cryptogetnextalgorithm  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogetnextalgorithm", (RTS_UINTPTR)cryptogetnextalgorithm, 1, 0x79EC29C8, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_cryptogetnextalgorithm  PFCRYPTOGETNEXTALGORITHM_IEC pfcryptogetnextalgorithm;
	#define EXT_cryptogetnextalgorithm  extern PFCRYPTOGETNEXTALGORITHM_IEC pfcryptogetnextalgorithm;
	#define GET_cryptogetnextalgorithm(fl)  s_pfCMGetAPI2( "cryptogetnextalgorithm", (RTS_VOID_FCTPTR *)&pfcryptogetnextalgorithm, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x79EC29C8, 0x03051000)
	#define CAL_cryptogetnextalgorithm  pfcryptogetnextalgorithm
	#define CHK_cryptogetnextalgorithm  (pfcryptogetnextalgorithm != NULL)
	#define EXP_cryptogetnextalgorithm   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptogetnextalgorithm", (RTS_UINTPTR)cryptogetnextalgorithm, 1, 0x79EC29C8, 0x03051000) 
#endif


/**
 *Generate a hashed message authentication code (HMAC) OF the given data AND key.
 * :return: Result of the operation
 */
typedef struct tagcryptohmacsign_struct
{
	RTS_IEC_HANDLE hAlgo;				/* VAR_INPUT */	/* Handle to the algorithm. */
	RtsByteString *pData;				/* VAR_INPUT */	/* Data to calculate the HMAC. */
	RtsCryptoKey key;					/* VAR_INPUT */	/* Key to be used for the HMAC calcuation */
	RtsByteString *pSignature;			/* VAR_INPUT */	/* Calculated HMAC */
	RTS_IEC_RESULT CryptoHMACSign;		/* VAR_OUTPUT */	
} cryptohmacsign_struct;

void CDECL CDECL_EXT cryptohmacsign(cryptohmacsign_struct *p);
typedef void (CDECL CDECL_EXT* PFCRYPTOHMACSIGN_IEC) (cryptohmacsign_struct *p);
#if defined(CMPCRYPTO_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CRYPTOHMACSIGN_NOTIMPLEMENTED)
	#define USE_cryptohmacsign
	#define EXT_cryptohmacsign
	#define GET_cryptohmacsign(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cryptohmacsign(p0) 
	#define CHK_cryptohmacsign  FALSE
	#define EXP_cryptohmacsign  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cryptohmacsign
	#define EXT_cryptohmacsign
	#define GET_cryptohmacsign(fl)  CAL_CMGETAPI( "cryptohmacsign" ) 
	#define CAL_cryptohmacsign  cryptohmacsign
	#define CHK_cryptohmacsign  TRUE
	#define EXP_cryptohmacsign  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptohmacsign", (RTS_UINTPTR)cryptohmacsign, 1, 0x931A9470, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPCRYPTO_IMPLEMENTATION_EXTERNAL)
	#define USE_cryptohmacsign
	#define EXT_cryptohmacsign
	#define GET_cryptohmacsign(fl)  CAL_CMGETAPI( "cryptohmacsign" ) 
	#define CAL_cryptohmacsign  cryptohmacsign
	#define CHK_cryptohmacsign  TRUE
	#define EXP_cryptohmacsign  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptohmacsign", (RTS_UINTPTR)cryptohmacsign, 1, 0x931A9470, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpCrypto_Implementationcryptohmacsign
	#define EXT_CmpCrypto_Implementationcryptohmacsign
	#define GET_CmpCrypto_Implementationcryptohmacsign  ERR_OK
	#define CAL_CmpCrypto_Implementationcryptohmacsign  cryptohmacsign
	#define CHK_CmpCrypto_Implementationcryptohmacsign  TRUE
	#define EXP_CmpCrypto_Implementationcryptohmacsign  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptohmacsign", (RTS_UINTPTR)cryptohmacsign, 1, 0x931A9470, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_cryptohmacsign
	#define EXT_cryptohmacsign
	#define GET_cryptohmacsign(fl)  CAL_CMGETAPI( "cryptohmacsign" ) 
	#define CAL_cryptohmacsign  cryptohmacsign
	#define CHK_cryptohmacsign  TRUE
	#define EXP_cryptohmacsign  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptohmacsign", (RTS_UINTPTR)cryptohmacsign, 1, 0x931A9470, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_cryptohmacsign  PFCRYPTOHMACSIGN_IEC pfcryptohmacsign;
	#define EXT_cryptohmacsign  extern PFCRYPTOHMACSIGN_IEC pfcryptohmacsign;
	#define GET_cryptohmacsign(fl)  s_pfCMGetAPI2( "cryptohmacsign", (RTS_VOID_FCTPTR *)&pfcryptohmacsign, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x931A9470, 0x03051000)
	#define CAL_cryptohmacsign  pfcryptohmacsign
	#define CHK_cryptohmacsign  (pfcryptohmacsign != NULL)
	#define EXP_cryptohmacsign   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptohmacsign", (RTS_UINTPTR)cryptohmacsign, 1, 0x931A9470, 0x03051000) 
#endif


/**
 * Verify a recieved hashed message authentication code (HMAC).
 * :return: Function returns ERR_OK if the HMAC is valid.
 */
typedef struct tagcryptohmacverify_struct
{
	RTS_IEC_HANDLE hAlgo;				/* VAR_INPUT */	/* Handle to the algorithm. */
	RtsByteString *pData;				/* VAR_INPUT */	/* Data to calculate the HMAC. */
	RtsCryptoKey key;					/* VAR_INPUT */	/* Key to be used for the HMAC calcuation */
	RtsByteString *pSignature;			/* VAR_INPUT */	/* Recieved HMAC */
	RTS_IEC_RESULT CryptoHMACVerify;	/* VAR_OUTPUT */	
} cryptohmacverify_struct;

void CDECL CDECL_EXT cryptohmacverify(cryptohmacverify_struct *p);
typedef void (CDECL CDECL_EXT* PFCRYPTOHMACVERIFY_IEC) (cryptohmacverify_struct *p);
#if defined(CMPCRYPTO_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CRYPTOHMACVERIFY_NOTIMPLEMENTED)
	#define USE_cryptohmacverify
	#define EXT_cryptohmacverify
	#define GET_cryptohmacverify(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cryptohmacverify(p0) 
	#define CHK_cryptohmacverify  FALSE
	#define EXP_cryptohmacverify  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cryptohmacverify
	#define EXT_cryptohmacverify
	#define GET_cryptohmacverify(fl)  CAL_CMGETAPI( "cryptohmacverify" ) 
	#define CAL_cryptohmacverify  cryptohmacverify
	#define CHK_cryptohmacverify  TRUE
	#define EXP_cryptohmacverify  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptohmacverify", (RTS_UINTPTR)cryptohmacverify, 1, 0x49EEB4A9, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPCRYPTO_IMPLEMENTATION_EXTERNAL)
	#define USE_cryptohmacverify
	#define EXT_cryptohmacverify
	#define GET_cryptohmacverify(fl)  CAL_CMGETAPI( "cryptohmacverify" ) 
	#define CAL_cryptohmacverify  cryptohmacverify
	#define CHK_cryptohmacverify  TRUE
	#define EXP_cryptohmacverify  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptohmacverify", (RTS_UINTPTR)cryptohmacverify, 1, 0x49EEB4A9, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpCrypto_Implementationcryptohmacverify
	#define EXT_CmpCrypto_Implementationcryptohmacverify
	#define GET_CmpCrypto_Implementationcryptohmacverify  ERR_OK
	#define CAL_CmpCrypto_Implementationcryptohmacverify  cryptohmacverify
	#define CHK_CmpCrypto_Implementationcryptohmacverify  TRUE
	#define EXP_CmpCrypto_Implementationcryptohmacverify  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptohmacverify", (RTS_UINTPTR)cryptohmacverify, 1, 0x49EEB4A9, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_cryptohmacverify
	#define EXT_cryptohmacverify
	#define GET_cryptohmacverify(fl)  CAL_CMGETAPI( "cryptohmacverify" ) 
	#define CAL_cryptohmacverify  cryptohmacverify
	#define CHK_cryptohmacverify  TRUE
	#define EXP_cryptohmacverify  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptohmacverify", (RTS_UINTPTR)cryptohmacverify, 1, 0x49EEB4A9, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_cryptohmacverify  PFCRYPTOHMACVERIFY_IEC pfcryptohmacverify;
	#define EXT_cryptohmacverify  extern PFCRYPTOHMACVERIFY_IEC pfcryptohmacverify;
	#define GET_cryptohmacverify(fl)  s_pfCMGetAPI2( "cryptohmacverify", (RTS_VOID_FCTPTR *)&pfcryptohmacverify, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x49EEB4A9, 0x03051000)
	#define CAL_cryptohmacverify  pfcryptohmacverify
	#define CHK_cryptohmacverify  (pfcryptohmacverify != NULL)
	#define EXP_cryptohmacverify   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptohmacverify", (RTS_UINTPTR)cryptohmacverify, 1, 0x49EEB4A9, 0x03051000) 
#endif


/**
 * This function can be used to import asymmtric keys from different formats.
 * :return: Result of the operation
 */
typedef struct tagcryptoimportasymmetrickey_struct
{
	RtsByteString data;					/* VAR_INPUT */	/* The buffer to be imported. */
	RTS_IEC_BOOL xBase64;				/* VAR_INPUT */	/* Import the key in BASE64 encoding. Otherwise ASN.1 will be used. */
	RTS_IEC_BOOL xPrivateKey;			/* VAR_INPUT */	/* TRUE: Import a private key. FLASE: Import a public key. */
	RtsCryptoKey *pKey;					/* VAR_INPUT */	/* The imported public key. */
	RTS_IEC_RESULT CryptoImportAsymmetricKey;	/* VAR_OUTPUT */	
} cryptoimportasymmetrickey_struct;

void CDECL CDECL_EXT cryptoimportasymmetrickey(cryptoimportasymmetrickey_struct *p);
typedef void (CDECL CDECL_EXT* PFCRYPTOIMPORTASYMMETRICKEY_IEC) (cryptoimportasymmetrickey_struct *p);
#if defined(CMPCRYPTO_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CRYPTOIMPORTASYMMETRICKEY_NOTIMPLEMENTED)
	#define USE_cryptoimportasymmetrickey
	#define EXT_cryptoimportasymmetrickey
	#define GET_cryptoimportasymmetrickey(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cryptoimportasymmetrickey(p0) 
	#define CHK_cryptoimportasymmetrickey  FALSE
	#define EXP_cryptoimportasymmetrickey  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cryptoimportasymmetrickey
	#define EXT_cryptoimportasymmetrickey
	#define GET_cryptoimportasymmetrickey(fl)  CAL_CMGETAPI( "cryptoimportasymmetrickey" ) 
	#define CAL_cryptoimportasymmetrickey  cryptoimportasymmetrickey
	#define CHK_cryptoimportasymmetrickey  TRUE
	#define EXP_cryptoimportasymmetrickey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptoimportasymmetrickey", (RTS_UINTPTR)cryptoimportasymmetrickey, 1, 0x73EB2A6A, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPCRYPTO_IMPLEMENTATION_EXTERNAL)
	#define USE_cryptoimportasymmetrickey
	#define EXT_cryptoimportasymmetrickey
	#define GET_cryptoimportasymmetrickey(fl)  CAL_CMGETAPI( "cryptoimportasymmetrickey" ) 
	#define CAL_cryptoimportasymmetrickey  cryptoimportasymmetrickey
	#define CHK_cryptoimportasymmetrickey  TRUE
	#define EXP_cryptoimportasymmetrickey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptoimportasymmetrickey", (RTS_UINTPTR)cryptoimportasymmetrickey, 1, 0x73EB2A6A, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpCrypto_Implementationcryptoimportasymmetrickey
	#define EXT_CmpCrypto_Implementationcryptoimportasymmetrickey
	#define GET_CmpCrypto_Implementationcryptoimportasymmetrickey  ERR_OK
	#define CAL_CmpCrypto_Implementationcryptoimportasymmetrickey  cryptoimportasymmetrickey
	#define CHK_CmpCrypto_Implementationcryptoimportasymmetrickey  TRUE
	#define EXP_CmpCrypto_Implementationcryptoimportasymmetrickey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptoimportasymmetrickey", (RTS_UINTPTR)cryptoimportasymmetrickey, 1, 0x73EB2A6A, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_cryptoimportasymmetrickey
	#define EXT_cryptoimportasymmetrickey
	#define GET_cryptoimportasymmetrickey(fl)  CAL_CMGETAPI( "cryptoimportasymmetrickey" ) 
	#define CAL_cryptoimportasymmetrickey  cryptoimportasymmetrickey
	#define CHK_cryptoimportasymmetrickey  TRUE
	#define EXP_cryptoimportasymmetrickey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptoimportasymmetrickey", (RTS_UINTPTR)cryptoimportasymmetrickey, 1, 0x73EB2A6A, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_cryptoimportasymmetrickey  PFCRYPTOIMPORTASYMMETRICKEY_IEC pfcryptoimportasymmetrickey;
	#define EXT_cryptoimportasymmetrickey  extern PFCRYPTOIMPORTASYMMETRICKEY_IEC pfcryptoimportasymmetrickey;
	#define GET_cryptoimportasymmetrickey(fl)  s_pfCMGetAPI2( "cryptoimportasymmetrickey", (RTS_VOID_FCTPTR *)&pfcryptoimportasymmetrickey, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x73EB2A6A, 0x03051000)
	#define CAL_cryptoimportasymmetrickey  pfcryptoimportasymmetrickey
	#define CHK_cryptoimportasymmetrickey  (pfcryptoimportasymmetrickey != NULL)
	#define EXP_cryptoimportasymmetrickey   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptoimportasymmetrickey", (RTS_UINTPTR)cryptoimportasymmetrickey, 1, 0x73EB2A6A, 0x03051000) 
#endif


/**
 * <description>cryptokeyexit</description>
 */
typedef struct tagcryptokeyexit_struct
{
	RtsCryptoKey *pKey;					/* VAR_INPUT */	
	RTS_IEC_RESULT CryptoKeyExit;		/* VAR_OUTPUT */	
} cryptokeyexit_struct;

void CDECL CDECL_EXT cryptokeyexit(cryptokeyexit_struct *p);
typedef void (CDECL CDECL_EXT* PFCRYPTOKEYEXIT_IEC) (cryptokeyexit_struct *p);
#if defined(CMPCRYPTO_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CRYPTOKEYEXIT_NOTIMPLEMENTED)
	#define USE_cryptokeyexit
	#define EXT_cryptokeyexit
	#define GET_cryptokeyexit(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cryptokeyexit(p0) 
	#define CHK_cryptokeyexit  FALSE
	#define EXP_cryptokeyexit  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cryptokeyexit
	#define EXT_cryptokeyexit
	#define GET_cryptokeyexit(fl)  CAL_CMGETAPI( "cryptokeyexit" ) 
	#define CAL_cryptokeyexit  cryptokeyexit
	#define CHK_cryptokeyexit  TRUE
	#define EXP_cryptokeyexit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptokeyexit", (RTS_UINTPTR)cryptokeyexit, 1, 0xD71ED5F3, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPCRYPTO_IMPLEMENTATION_EXTERNAL)
	#define USE_cryptokeyexit
	#define EXT_cryptokeyexit
	#define GET_cryptokeyexit(fl)  CAL_CMGETAPI( "cryptokeyexit" ) 
	#define CAL_cryptokeyexit  cryptokeyexit
	#define CHK_cryptokeyexit  TRUE
	#define EXP_cryptokeyexit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptokeyexit", (RTS_UINTPTR)cryptokeyexit, 1, 0xD71ED5F3, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpCrypto_Implementationcryptokeyexit
	#define EXT_CmpCrypto_Implementationcryptokeyexit
	#define GET_CmpCrypto_Implementationcryptokeyexit  ERR_OK
	#define CAL_CmpCrypto_Implementationcryptokeyexit  cryptokeyexit
	#define CHK_CmpCrypto_Implementationcryptokeyexit  TRUE
	#define EXP_CmpCrypto_Implementationcryptokeyexit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptokeyexit", (RTS_UINTPTR)cryptokeyexit, 1, 0xD71ED5F3, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_cryptokeyexit
	#define EXT_cryptokeyexit
	#define GET_cryptokeyexit(fl)  CAL_CMGETAPI( "cryptokeyexit" ) 
	#define CAL_cryptokeyexit  cryptokeyexit
	#define CHK_cryptokeyexit  TRUE
	#define EXP_cryptokeyexit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptokeyexit", (RTS_UINTPTR)cryptokeyexit, 1, 0xD71ED5F3, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_cryptokeyexit  PFCRYPTOKEYEXIT_IEC pfcryptokeyexit;
	#define EXT_cryptokeyexit  extern PFCRYPTOKEYEXIT_IEC pfcryptokeyexit;
	#define GET_cryptokeyexit(fl)  s_pfCMGetAPI2( "cryptokeyexit", (RTS_VOID_FCTPTR *)&pfcryptokeyexit, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xD71ED5F3, 0x03051000)
	#define CAL_cryptokeyexit  pfcryptokeyexit
	#define CHK_cryptokeyexit  (pfcryptokeyexit != NULL)
	#define EXP_cryptokeyexit   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptokeyexit", (RTS_UINTPTR)cryptokeyexit, 1, 0xD71ED5F3, 0x03051000) 
#endif


/**
 * <description>cryptokeyinit</description>
 */
typedef struct tagcryptokeyinit_struct
{
	RtsCryptoKey *pKey;					/* VAR_INPUT */	
	RtsCryptoKeyStorage key;			/* VAR_INPUT */	
	RTS_IEC_DINT keyType;				/* VAR_INPUT, Enum: RTSCRYPTOKEYTYPE */
	RTS_IEC_RESULT CryptoKeyInit;		/* VAR_OUTPUT */	
} cryptokeyinit_struct;

void CDECL CDECL_EXT cryptokeyinit(cryptokeyinit_struct *p);
typedef void (CDECL CDECL_EXT* PFCRYPTOKEYINIT_IEC) (cryptokeyinit_struct *p);
#if defined(CMPCRYPTO_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CRYPTOKEYINIT_NOTIMPLEMENTED)
	#define USE_cryptokeyinit
	#define EXT_cryptokeyinit
	#define GET_cryptokeyinit(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cryptokeyinit(p0) 
	#define CHK_cryptokeyinit  FALSE
	#define EXP_cryptokeyinit  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cryptokeyinit
	#define EXT_cryptokeyinit
	#define GET_cryptokeyinit(fl)  CAL_CMGETAPI( "cryptokeyinit" ) 
	#define CAL_cryptokeyinit  cryptokeyinit
	#define CHK_cryptokeyinit  TRUE
	#define EXP_cryptokeyinit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptokeyinit", (RTS_UINTPTR)cryptokeyinit, 1, 0xE8E228B3, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPCRYPTO_IMPLEMENTATION_EXTERNAL)
	#define USE_cryptokeyinit
	#define EXT_cryptokeyinit
	#define GET_cryptokeyinit(fl)  CAL_CMGETAPI( "cryptokeyinit" ) 
	#define CAL_cryptokeyinit  cryptokeyinit
	#define CHK_cryptokeyinit  TRUE
	#define EXP_cryptokeyinit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptokeyinit", (RTS_UINTPTR)cryptokeyinit, 1, 0xE8E228B3, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpCrypto_Implementationcryptokeyinit
	#define EXT_CmpCrypto_Implementationcryptokeyinit
	#define GET_CmpCrypto_Implementationcryptokeyinit  ERR_OK
	#define CAL_CmpCrypto_Implementationcryptokeyinit  cryptokeyinit
	#define CHK_CmpCrypto_Implementationcryptokeyinit  TRUE
	#define EXP_CmpCrypto_Implementationcryptokeyinit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptokeyinit", (RTS_UINTPTR)cryptokeyinit, 1, 0xE8E228B3, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_cryptokeyinit
	#define EXT_cryptokeyinit
	#define GET_cryptokeyinit(fl)  CAL_CMGETAPI( "cryptokeyinit" ) 
	#define CAL_cryptokeyinit  cryptokeyinit
	#define CHK_cryptokeyinit  TRUE
	#define EXP_cryptokeyinit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptokeyinit", (RTS_UINTPTR)cryptokeyinit, 1, 0xE8E228B3, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_cryptokeyinit  PFCRYPTOKEYINIT_IEC pfcryptokeyinit;
	#define EXT_cryptokeyinit  extern PFCRYPTOKEYINIT_IEC pfcryptokeyinit;
	#define GET_cryptokeyinit(fl)  s_pfCMGetAPI2( "cryptokeyinit", (RTS_VOID_FCTPTR *)&pfcryptokeyinit, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xE8E228B3, 0x03051000)
	#define CAL_cryptokeyinit  pfcryptokeyinit
	#define CHK_cryptokeyinit  (pfcryptokeyinit != NULL)
	#define EXP_cryptokeyinit   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptokeyinit", (RTS_UINTPTR)cryptokeyinit, 1, 0xE8E228B3, 0x03051000) 
#endif


/**
 * This function can be used to load a private key from the components internal data store.
 * :return: Result of the operation
 */
typedef struct tagcryptoloadprivatekey_struct
{
	RtsByteString keyIdentifier;		/* VAR_INPUT */	/* The identifier of the key got from CryptoStorePrivateKey. */
	RtsCryptoKey *pKey;					/* VAR_INPUT */	/* The private key retrieved from the internal storage. */
	RTS_IEC_RESULT CryptoLoadPrivateKey;	/* VAR_OUTPUT */	
} cryptoloadprivatekey_struct;

void CDECL CDECL_EXT cryptoloadprivatekey(cryptoloadprivatekey_struct *p);
typedef void (CDECL CDECL_EXT* PFCRYPTOLOADPRIVATEKEY_IEC) (cryptoloadprivatekey_struct *p);
#if defined(CMPCRYPTO_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CRYPTOLOADPRIVATEKEY_NOTIMPLEMENTED)
	#define USE_cryptoloadprivatekey
	#define EXT_cryptoloadprivatekey
	#define GET_cryptoloadprivatekey(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cryptoloadprivatekey(p0) 
	#define CHK_cryptoloadprivatekey  FALSE
	#define EXP_cryptoloadprivatekey  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cryptoloadprivatekey
	#define EXT_cryptoloadprivatekey
	#define GET_cryptoloadprivatekey(fl)  CAL_CMGETAPI( "cryptoloadprivatekey" ) 
	#define CAL_cryptoloadprivatekey  cryptoloadprivatekey
	#define CHK_cryptoloadprivatekey  TRUE
	#define EXP_cryptoloadprivatekey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptoloadprivatekey", (RTS_UINTPTR)cryptoloadprivatekey, 1, 0xCFC27A76, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPCRYPTO_IMPLEMENTATION_EXTERNAL)
	#define USE_cryptoloadprivatekey
	#define EXT_cryptoloadprivatekey
	#define GET_cryptoloadprivatekey(fl)  CAL_CMGETAPI( "cryptoloadprivatekey" ) 
	#define CAL_cryptoloadprivatekey  cryptoloadprivatekey
	#define CHK_cryptoloadprivatekey  TRUE
	#define EXP_cryptoloadprivatekey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptoloadprivatekey", (RTS_UINTPTR)cryptoloadprivatekey, 1, 0xCFC27A76, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpCrypto_Implementationcryptoloadprivatekey
	#define EXT_CmpCrypto_Implementationcryptoloadprivatekey
	#define GET_CmpCrypto_Implementationcryptoloadprivatekey  ERR_OK
	#define CAL_CmpCrypto_Implementationcryptoloadprivatekey  cryptoloadprivatekey
	#define CHK_CmpCrypto_Implementationcryptoloadprivatekey  TRUE
	#define EXP_CmpCrypto_Implementationcryptoloadprivatekey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptoloadprivatekey", (RTS_UINTPTR)cryptoloadprivatekey, 1, 0xCFC27A76, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_cryptoloadprivatekey
	#define EXT_cryptoloadprivatekey
	#define GET_cryptoloadprivatekey(fl)  CAL_CMGETAPI( "cryptoloadprivatekey" ) 
	#define CAL_cryptoloadprivatekey  cryptoloadprivatekey
	#define CHK_cryptoloadprivatekey  TRUE
	#define EXP_cryptoloadprivatekey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptoloadprivatekey", (RTS_UINTPTR)cryptoloadprivatekey, 1, 0xCFC27A76, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_cryptoloadprivatekey  PFCRYPTOLOADPRIVATEKEY_IEC pfcryptoloadprivatekey;
	#define EXT_cryptoloadprivatekey  extern PFCRYPTOLOADPRIVATEKEY_IEC pfcryptoloadprivatekey;
	#define GET_cryptoloadprivatekey(fl)  s_pfCMGetAPI2( "cryptoloadprivatekey", (RTS_VOID_FCTPTR *)&pfcryptoloadprivatekey, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xCFC27A76, 0x03051000)
	#define CAL_cryptoloadprivatekey  pfcryptoloadprivatekey
	#define CHK_cryptoloadprivatekey  (pfcryptoloadprivatekey != NULL)
	#define EXP_cryptoloadprivatekey   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptoloadprivatekey", (RTS_UINTPTR)cryptoloadprivatekey, 1, 0xCFC27A76, 0x03051000) 
#endif


/**
 * <description>cryptortsbytestringexit</description>
 */
typedef struct tagcryptortsbytestringexit_struct
{
	RtsByteString *pByteString;			/* VAR_INPUT */	
	RTS_IEC_RESULT CryptoRtsByteStringExit;	/* VAR_OUTPUT */	
} cryptortsbytestringexit_struct;

void CDECL CDECL_EXT cryptortsbytestringexit(cryptortsbytestringexit_struct *p);
typedef void (CDECL CDECL_EXT* PFCRYPTORTSBYTESTRINGEXIT_IEC) (cryptortsbytestringexit_struct *p);
#if defined(CMPCRYPTO_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CRYPTORTSBYTESTRINGEXIT_NOTIMPLEMENTED)
	#define USE_cryptortsbytestringexit
	#define EXT_cryptortsbytestringexit
	#define GET_cryptortsbytestringexit(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cryptortsbytestringexit(p0) 
	#define CHK_cryptortsbytestringexit  FALSE
	#define EXP_cryptortsbytestringexit  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cryptortsbytestringexit
	#define EXT_cryptortsbytestringexit
	#define GET_cryptortsbytestringexit(fl)  CAL_CMGETAPI( "cryptortsbytestringexit" ) 
	#define CAL_cryptortsbytestringexit  cryptortsbytestringexit
	#define CHK_cryptortsbytestringexit  TRUE
	#define EXP_cryptortsbytestringexit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptortsbytestringexit", (RTS_UINTPTR)cryptortsbytestringexit, 1, 0x16B297C5, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPCRYPTO_IMPLEMENTATION_EXTERNAL)
	#define USE_cryptortsbytestringexit
	#define EXT_cryptortsbytestringexit
	#define GET_cryptortsbytestringexit(fl)  CAL_CMGETAPI( "cryptortsbytestringexit" ) 
	#define CAL_cryptortsbytestringexit  cryptortsbytestringexit
	#define CHK_cryptortsbytestringexit  TRUE
	#define EXP_cryptortsbytestringexit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptortsbytestringexit", (RTS_UINTPTR)cryptortsbytestringexit, 1, 0x16B297C5, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpCrypto_Implementationcryptortsbytestringexit
	#define EXT_CmpCrypto_Implementationcryptortsbytestringexit
	#define GET_CmpCrypto_Implementationcryptortsbytestringexit  ERR_OK
	#define CAL_CmpCrypto_Implementationcryptortsbytestringexit  cryptortsbytestringexit
	#define CHK_CmpCrypto_Implementationcryptortsbytestringexit  TRUE
	#define EXP_CmpCrypto_Implementationcryptortsbytestringexit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptortsbytestringexit", (RTS_UINTPTR)cryptortsbytestringexit, 1, 0x16B297C5, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_cryptortsbytestringexit
	#define EXT_cryptortsbytestringexit
	#define GET_cryptortsbytestringexit(fl)  CAL_CMGETAPI( "cryptortsbytestringexit" ) 
	#define CAL_cryptortsbytestringexit  cryptortsbytestringexit
	#define CHK_cryptortsbytestringexit  TRUE
	#define EXP_cryptortsbytestringexit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptortsbytestringexit", (RTS_UINTPTR)cryptortsbytestringexit, 1, 0x16B297C5, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_cryptortsbytestringexit  PFCRYPTORTSBYTESTRINGEXIT_IEC pfcryptortsbytestringexit;
	#define EXT_cryptortsbytestringexit  extern PFCRYPTORTSBYTESTRINGEXIT_IEC pfcryptortsbytestringexit;
	#define GET_cryptortsbytestringexit(fl)  s_pfCMGetAPI2( "cryptortsbytestringexit", (RTS_VOID_FCTPTR *)&pfcryptortsbytestringexit, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x16B297C5, 0x03051000)
	#define CAL_cryptortsbytestringexit  pfcryptortsbytestringexit
	#define CHK_cryptortsbytestringexit  (pfcryptortsbytestringexit != NULL)
	#define EXP_cryptortsbytestringexit   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptortsbytestringexit", (RTS_UINTPTR)cryptortsbytestringexit, 1, 0x16B297C5, 0x03051000) 
#endif


/**
 * <description>cryptortsbytestringinit</description>
 */
typedef struct tagcryptortsbytestringinit_struct
{
	RtsByteString *pByteString;			/* VAR_INPUT */	
	RTS_IEC_RESULT CryptoRtsByteStringInit;	/* VAR_OUTPUT */	
} cryptortsbytestringinit_struct;

void CDECL CDECL_EXT cryptortsbytestringinit(cryptortsbytestringinit_struct *p);
typedef void (CDECL CDECL_EXT* PFCRYPTORTSBYTESTRINGINIT_IEC) (cryptortsbytestringinit_struct *p);
#if defined(CMPCRYPTO_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CRYPTORTSBYTESTRINGINIT_NOTIMPLEMENTED)
	#define USE_cryptortsbytestringinit
	#define EXT_cryptortsbytestringinit
	#define GET_cryptortsbytestringinit(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cryptortsbytestringinit(p0) 
	#define CHK_cryptortsbytestringinit  FALSE
	#define EXP_cryptortsbytestringinit  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cryptortsbytestringinit
	#define EXT_cryptortsbytestringinit
	#define GET_cryptortsbytestringinit(fl)  CAL_CMGETAPI( "cryptortsbytestringinit" ) 
	#define CAL_cryptortsbytestringinit  cryptortsbytestringinit
	#define CHK_cryptortsbytestringinit  TRUE
	#define EXP_cryptortsbytestringinit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptortsbytestringinit", (RTS_UINTPTR)cryptortsbytestringinit, 1, 0xC1B4C2F9, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPCRYPTO_IMPLEMENTATION_EXTERNAL)
	#define USE_cryptortsbytestringinit
	#define EXT_cryptortsbytestringinit
	#define GET_cryptortsbytestringinit(fl)  CAL_CMGETAPI( "cryptortsbytestringinit" ) 
	#define CAL_cryptortsbytestringinit  cryptortsbytestringinit
	#define CHK_cryptortsbytestringinit  TRUE
	#define EXP_cryptortsbytestringinit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptortsbytestringinit", (RTS_UINTPTR)cryptortsbytestringinit, 1, 0xC1B4C2F9, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpCrypto_Implementationcryptortsbytestringinit
	#define EXT_CmpCrypto_Implementationcryptortsbytestringinit
	#define GET_CmpCrypto_Implementationcryptortsbytestringinit  ERR_OK
	#define CAL_CmpCrypto_Implementationcryptortsbytestringinit  cryptortsbytestringinit
	#define CHK_CmpCrypto_Implementationcryptortsbytestringinit  TRUE
	#define EXP_CmpCrypto_Implementationcryptortsbytestringinit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptortsbytestringinit", (RTS_UINTPTR)cryptortsbytestringinit, 1, 0xC1B4C2F9, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_cryptortsbytestringinit
	#define EXT_cryptortsbytestringinit
	#define GET_cryptortsbytestringinit(fl)  CAL_CMGETAPI( "cryptortsbytestringinit" ) 
	#define CAL_cryptortsbytestringinit  cryptortsbytestringinit
	#define CHK_cryptortsbytestringinit  TRUE
	#define EXP_cryptortsbytestringinit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptortsbytestringinit", (RTS_UINTPTR)cryptortsbytestringinit, 1, 0xC1B4C2F9, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_cryptortsbytestringinit  PFCRYPTORTSBYTESTRINGINIT_IEC pfcryptortsbytestringinit;
	#define EXT_cryptortsbytestringinit  extern PFCRYPTORTSBYTESTRINGINIT_IEC pfcryptortsbytestringinit;
	#define GET_cryptortsbytestringinit(fl)  s_pfCMGetAPI2( "cryptortsbytestringinit", (RTS_VOID_FCTPTR *)&pfcryptortsbytestringinit, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xC1B4C2F9, 0x03051000)
	#define CAL_cryptortsbytestringinit  pfcryptortsbytestringinit
	#define CHK_cryptortsbytestringinit  (pfcryptortsbytestringinit != NULL)
	#define EXP_cryptortsbytestringinit   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptortsbytestringinit", (RTS_UINTPTR)cryptortsbytestringinit, 1, 0xC1B4C2F9, 0x03051000) 
#endif


/**
 * Initialize a byte string.
 */
typedef struct tagcryptortsbytestringinit2_struct
{
	RtsByteString *pByteString;			/* VAR_INPUT */	/* Pointer to the RtsByteString to be initialized. */
	RTS_IEC_UDINT ui32BufferSize;		/* VAR_INPUT */	/* Buffersize needed for this byte string. */
	RTS_IEC_BYTE *pBuffer;				/* VAR_INPUT */	/* Pointer to a optional static buffer. If NULL is passed the function will allocated ui32BufferSize bytes from the heap. */
	RTS_IEC_BOOL xEmptyBuffer;			/* VAR_INPUT */	/* Used for static buffers. If FALSE pByteString->ui32Lenght will be set to ui32BufferSize. Must be TRUE if pBuffer == NULL */
	RTS_IEC_RESULT CryptoRtsByteStringInit2;	/* VAR_OUTPUT */	
} cryptortsbytestringinit2_struct;

void CDECL CDECL_EXT cryptortsbytestringinit2(cryptortsbytestringinit2_struct *p);
typedef void (CDECL CDECL_EXT* PFCRYPTORTSBYTESTRINGINIT2_IEC) (cryptortsbytestringinit2_struct *p);
#if defined(CMPCRYPTO_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CRYPTORTSBYTESTRINGINIT2_NOTIMPLEMENTED)
	#define USE_cryptortsbytestringinit2
	#define EXT_cryptortsbytestringinit2
	#define GET_cryptortsbytestringinit2(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cryptortsbytestringinit2(p0) 
	#define CHK_cryptortsbytestringinit2  FALSE
	#define EXP_cryptortsbytestringinit2  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cryptortsbytestringinit2
	#define EXT_cryptortsbytestringinit2
	#define GET_cryptortsbytestringinit2(fl)  CAL_CMGETAPI( "cryptortsbytestringinit2" ) 
	#define CAL_cryptortsbytestringinit2  cryptortsbytestringinit2
	#define CHK_cryptortsbytestringinit2  TRUE
	#define EXP_cryptortsbytestringinit2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptortsbytestringinit2", (RTS_UINTPTR)cryptortsbytestringinit2, 1, 0xE2AA0F02, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPCRYPTO_IMPLEMENTATION_EXTERNAL)
	#define USE_cryptortsbytestringinit2
	#define EXT_cryptortsbytestringinit2
	#define GET_cryptortsbytestringinit2(fl)  CAL_CMGETAPI( "cryptortsbytestringinit2" ) 
	#define CAL_cryptortsbytestringinit2  cryptortsbytestringinit2
	#define CHK_cryptortsbytestringinit2  TRUE
	#define EXP_cryptortsbytestringinit2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptortsbytestringinit2", (RTS_UINTPTR)cryptortsbytestringinit2, 1, 0xE2AA0F02, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpCrypto_Implementationcryptortsbytestringinit2
	#define EXT_CmpCrypto_Implementationcryptortsbytestringinit2
	#define GET_CmpCrypto_Implementationcryptortsbytestringinit2  ERR_OK
	#define CAL_CmpCrypto_Implementationcryptortsbytestringinit2  cryptortsbytestringinit2
	#define CHK_CmpCrypto_Implementationcryptortsbytestringinit2  TRUE
	#define EXP_CmpCrypto_Implementationcryptortsbytestringinit2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptortsbytestringinit2", (RTS_UINTPTR)cryptortsbytestringinit2, 1, 0xE2AA0F02, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_cryptortsbytestringinit2
	#define EXT_cryptortsbytestringinit2
	#define GET_cryptortsbytestringinit2(fl)  CAL_CMGETAPI( "cryptortsbytestringinit2" ) 
	#define CAL_cryptortsbytestringinit2  cryptortsbytestringinit2
	#define CHK_cryptortsbytestringinit2  TRUE
	#define EXP_cryptortsbytestringinit2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptortsbytestringinit2", (RTS_UINTPTR)cryptortsbytestringinit2, 1, 0xE2AA0F02, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_cryptortsbytestringinit2  PFCRYPTORTSBYTESTRINGINIT2_IEC pfcryptortsbytestringinit2;
	#define EXT_cryptortsbytestringinit2  extern PFCRYPTORTSBYTESTRINGINIT2_IEC pfcryptortsbytestringinit2;
	#define GET_cryptortsbytestringinit2(fl)  s_pfCMGetAPI2( "cryptortsbytestringinit2", (RTS_VOID_FCTPTR *)&pfcryptortsbytestringinit2, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xE2AA0F02, 0x03051000)
	#define CAL_cryptortsbytestringinit2  pfcryptortsbytestringinit2
	#define CHK_cryptortsbytestringinit2  (pfcryptortsbytestringinit2 != NULL)
	#define EXP_cryptortsbytestringinit2   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptortsbytestringinit2", (RTS_UINTPTR)cryptortsbytestringinit2, 1, 0xE2AA0F02, 0x03051000) 
#endif


/**
 * Sign the data using a specific message digest and the private key.
 * :return: Result of the operation.
 */
typedef struct tagcryptosignaturegenerate_struct
{
	RTS_IEC_HANDLE hAlgo;				/* VAR_INPUT */	/* Handle to the algorithm. */
	RtsByteString *pData;				/* VAR_INPUT */	/* Data to be signed. */
	RtsCryptoKey privateKey;			/* VAR_INPUT */	/* Key to be used signing. Has to be a private key. */
	RtsByteString *pSignature;			/* VAR_INPUT */	/* Calculated signature of the data. */
	RTS_IEC_RESULT CryptoSignatureGenerate;	/* VAR_OUTPUT */	
} cryptosignaturegenerate_struct;

void CDECL CDECL_EXT cryptosignaturegenerate(cryptosignaturegenerate_struct *p);
typedef void (CDECL CDECL_EXT* PFCRYPTOSIGNATUREGENERATE_IEC) (cryptosignaturegenerate_struct *p);
#if defined(CMPCRYPTO_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CRYPTOSIGNATUREGENERATE_NOTIMPLEMENTED)
	#define USE_cryptosignaturegenerate
	#define EXT_cryptosignaturegenerate
	#define GET_cryptosignaturegenerate(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cryptosignaturegenerate(p0) 
	#define CHK_cryptosignaturegenerate  FALSE
	#define EXP_cryptosignaturegenerate  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cryptosignaturegenerate
	#define EXT_cryptosignaturegenerate
	#define GET_cryptosignaturegenerate(fl)  CAL_CMGETAPI( "cryptosignaturegenerate" ) 
	#define CAL_cryptosignaturegenerate  cryptosignaturegenerate
	#define CHK_cryptosignaturegenerate  TRUE
	#define EXP_cryptosignaturegenerate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptosignaturegenerate", (RTS_UINTPTR)cryptosignaturegenerate, 1, 0x0C2FBF80, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPCRYPTO_IMPLEMENTATION_EXTERNAL)
	#define USE_cryptosignaturegenerate
	#define EXT_cryptosignaturegenerate
	#define GET_cryptosignaturegenerate(fl)  CAL_CMGETAPI( "cryptosignaturegenerate" ) 
	#define CAL_cryptosignaturegenerate  cryptosignaturegenerate
	#define CHK_cryptosignaturegenerate  TRUE
	#define EXP_cryptosignaturegenerate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptosignaturegenerate", (RTS_UINTPTR)cryptosignaturegenerate, 1, 0x0C2FBF80, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpCrypto_Implementationcryptosignaturegenerate
	#define EXT_CmpCrypto_Implementationcryptosignaturegenerate
	#define GET_CmpCrypto_Implementationcryptosignaturegenerate  ERR_OK
	#define CAL_CmpCrypto_Implementationcryptosignaturegenerate  cryptosignaturegenerate
	#define CHK_CmpCrypto_Implementationcryptosignaturegenerate  TRUE
	#define EXP_CmpCrypto_Implementationcryptosignaturegenerate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptosignaturegenerate", (RTS_UINTPTR)cryptosignaturegenerate, 1, 0x0C2FBF80, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_cryptosignaturegenerate
	#define EXT_cryptosignaturegenerate
	#define GET_cryptosignaturegenerate(fl)  CAL_CMGETAPI( "cryptosignaturegenerate" ) 
	#define CAL_cryptosignaturegenerate  cryptosignaturegenerate
	#define CHK_cryptosignaturegenerate  TRUE
	#define EXP_cryptosignaturegenerate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptosignaturegenerate", (RTS_UINTPTR)cryptosignaturegenerate, 1, 0x0C2FBF80, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_cryptosignaturegenerate  PFCRYPTOSIGNATUREGENERATE_IEC pfcryptosignaturegenerate;
	#define EXT_cryptosignaturegenerate  extern PFCRYPTOSIGNATUREGENERATE_IEC pfcryptosignaturegenerate;
	#define GET_cryptosignaturegenerate(fl)  s_pfCMGetAPI2( "cryptosignaturegenerate", (RTS_VOID_FCTPTR *)&pfcryptosignaturegenerate, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x0C2FBF80, 0x03051000)
	#define CAL_cryptosignaturegenerate  pfcryptosignaturegenerate
	#define CHK_cryptosignaturegenerate  (pfcryptosignaturegenerate != NULL)
	#define EXP_cryptosignaturegenerate   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptosignaturegenerate", (RTS_UINTPTR)cryptosignaturegenerate, 1, 0x0C2FBF80, 0x03051000) 
#endif


/**
 * Verify a recieved signature
 * :return: unction returns ERR_OK if the signature is valid.
 */
typedef struct tagcryptosignatureverify_struct
{
	RTS_IEC_HANDLE hAlgo;				/* VAR_INPUT */	/* Handle to the algorithm. */
	RtsByteString *pData;				/* VAR_INPUT */	/* Data to verify. */
	RtsCryptoKey publicKey;				/* VAR_INPUT */	/* Public key of the sender. */
	RtsByteString *pSignature;			/* VAR_INPUT */	/* Received signature. */
	RTS_IEC_RESULT CryptoSignatureVerify;	/* VAR_OUTPUT */	
} cryptosignatureverify_struct;

void CDECL CDECL_EXT cryptosignatureverify(cryptosignatureverify_struct *p);
typedef void (CDECL CDECL_EXT* PFCRYPTOSIGNATUREVERIFY_IEC) (cryptosignatureverify_struct *p);
#if defined(CMPCRYPTO_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CRYPTOSIGNATUREVERIFY_NOTIMPLEMENTED)
	#define USE_cryptosignatureverify
	#define EXT_cryptosignatureverify
	#define GET_cryptosignatureverify(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cryptosignatureverify(p0) 
	#define CHK_cryptosignatureverify  FALSE
	#define EXP_cryptosignatureverify  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cryptosignatureverify
	#define EXT_cryptosignatureverify
	#define GET_cryptosignatureverify(fl)  CAL_CMGETAPI( "cryptosignatureverify" ) 
	#define CAL_cryptosignatureverify  cryptosignatureverify
	#define CHK_cryptosignatureverify  TRUE
	#define EXP_cryptosignatureverify  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptosignatureverify", (RTS_UINTPTR)cryptosignatureverify, 1, 0x3F425BB9, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPCRYPTO_IMPLEMENTATION_EXTERNAL)
	#define USE_cryptosignatureverify
	#define EXT_cryptosignatureverify
	#define GET_cryptosignatureverify(fl)  CAL_CMGETAPI( "cryptosignatureverify" ) 
	#define CAL_cryptosignatureverify  cryptosignatureverify
	#define CHK_cryptosignatureverify  TRUE
	#define EXP_cryptosignatureverify  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptosignatureverify", (RTS_UINTPTR)cryptosignatureverify, 1, 0x3F425BB9, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpCrypto_Implementationcryptosignatureverify
	#define EXT_CmpCrypto_Implementationcryptosignatureverify
	#define GET_CmpCrypto_Implementationcryptosignatureverify  ERR_OK
	#define CAL_CmpCrypto_Implementationcryptosignatureverify  cryptosignatureverify
	#define CHK_CmpCrypto_Implementationcryptosignatureverify  TRUE
	#define EXP_CmpCrypto_Implementationcryptosignatureverify  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptosignatureverify", (RTS_UINTPTR)cryptosignatureverify, 1, 0x3F425BB9, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_cryptosignatureverify
	#define EXT_cryptosignatureverify
	#define GET_cryptosignatureverify(fl)  CAL_CMGETAPI( "cryptosignatureverify" ) 
	#define CAL_cryptosignatureverify  cryptosignatureverify
	#define CHK_cryptosignatureverify  TRUE
	#define EXP_cryptosignatureverify  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptosignatureverify", (RTS_UINTPTR)cryptosignatureverify, 1, 0x3F425BB9, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_cryptosignatureverify  PFCRYPTOSIGNATUREVERIFY_IEC pfcryptosignatureverify;
	#define EXT_cryptosignatureverify  extern PFCRYPTOSIGNATUREVERIFY_IEC pfcryptosignatureverify;
	#define GET_cryptosignatureverify(fl)  s_pfCMGetAPI2( "cryptosignatureverify", (RTS_VOID_FCTPTR *)&pfcryptosignatureverify, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x3F425BB9, 0x03051000)
	#define CAL_cryptosignatureverify  pfcryptosignatureverify
	#define CHK_cryptosignatureverify  (pfcryptosignatureverify != NULL)
	#define EXP_cryptosignatureverify   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptosignatureverify", (RTS_UINTPTR)cryptosignatureverify, 1, 0x3F425BB9, 0x03051000) 
#endif


/**
 * This function can be used to store a private key that was imported or generated within the components internal data store.
 * :return: Result of the operation
 */
typedef struct tagcryptostoreprivatekey_struct
{
	RtsCryptoKey key;					/* VAR_INPUT */	/* The private key to be stored. */
	RtsByteString *pKeyIdentifier;		/* VAR_INPUT */	/* A bytestring where the key identifier is stored. This identifier can be used to access the key later. The identifier does not contain any sensitive data. */
	RTS_IEC_RESULT CryptoStorePrivateKey;	/* VAR_OUTPUT */	
} cryptostoreprivatekey_struct;

void CDECL CDECL_EXT cryptostoreprivatekey(cryptostoreprivatekey_struct *p);
typedef void (CDECL CDECL_EXT* PFCRYPTOSTOREPRIVATEKEY_IEC) (cryptostoreprivatekey_struct *p);
#if defined(CMPCRYPTO_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CRYPTOSTOREPRIVATEKEY_NOTIMPLEMENTED)
	#define USE_cryptostoreprivatekey
	#define EXT_cryptostoreprivatekey
	#define GET_cryptostoreprivatekey(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cryptostoreprivatekey(p0) 
	#define CHK_cryptostoreprivatekey  FALSE
	#define EXP_cryptostoreprivatekey  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cryptostoreprivatekey
	#define EXT_cryptostoreprivatekey
	#define GET_cryptostoreprivatekey(fl)  CAL_CMGETAPI( "cryptostoreprivatekey" ) 
	#define CAL_cryptostoreprivatekey  cryptostoreprivatekey
	#define CHK_cryptostoreprivatekey  TRUE
	#define EXP_cryptostoreprivatekey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptostoreprivatekey", (RTS_UINTPTR)cryptostoreprivatekey, 1, 0x348144FC, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPCRYPTO_IMPLEMENTATION_EXTERNAL)
	#define USE_cryptostoreprivatekey
	#define EXT_cryptostoreprivatekey
	#define GET_cryptostoreprivatekey(fl)  CAL_CMGETAPI( "cryptostoreprivatekey" ) 
	#define CAL_cryptostoreprivatekey  cryptostoreprivatekey
	#define CHK_cryptostoreprivatekey  TRUE
	#define EXP_cryptostoreprivatekey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptostoreprivatekey", (RTS_UINTPTR)cryptostoreprivatekey, 1, 0x348144FC, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpCrypto_Implementationcryptostoreprivatekey
	#define EXT_CmpCrypto_Implementationcryptostoreprivatekey
	#define GET_CmpCrypto_Implementationcryptostoreprivatekey  ERR_OK
	#define CAL_CmpCrypto_Implementationcryptostoreprivatekey  cryptostoreprivatekey
	#define CHK_CmpCrypto_Implementationcryptostoreprivatekey  TRUE
	#define EXP_CmpCrypto_Implementationcryptostoreprivatekey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptostoreprivatekey", (RTS_UINTPTR)cryptostoreprivatekey, 1, 0x348144FC, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_cryptostoreprivatekey
	#define EXT_cryptostoreprivatekey
	#define GET_cryptostoreprivatekey(fl)  CAL_CMGETAPI( "cryptostoreprivatekey" ) 
	#define CAL_cryptostoreprivatekey  cryptostoreprivatekey
	#define CHK_cryptostoreprivatekey  TRUE
	#define EXP_cryptostoreprivatekey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptostoreprivatekey", (RTS_UINTPTR)cryptostoreprivatekey, 1, 0x348144FC, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_cryptostoreprivatekey  PFCRYPTOSTOREPRIVATEKEY_IEC pfcryptostoreprivatekey;
	#define EXT_cryptostoreprivatekey  extern PFCRYPTOSTOREPRIVATEKEY_IEC pfcryptostoreprivatekey;
	#define GET_cryptostoreprivatekey(fl)  s_pfCMGetAPI2( "cryptostoreprivatekey", (RTS_VOID_FCTPTR *)&pfcryptostoreprivatekey, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x348144FC, 0x03051000)
	#define CAL_cryptostoreprivatekey  pfcryptostoreprivatekey
	#define CHK_cryptostoreprivatekey  (pfcryptostoreprivatekey != NULL)
	#define EXP_cryptostoreprivatekey   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptostoreprivatekey", (RTS_UINTPTR)cryptostoreprivatekey, 1, 0x348144FC, 0x03051000) 
#endif


/**
 * Perform a symmetric decryption using the algorithm handle.
 * :return: Result of the operation
 */
typedef struct tagcryptosymmetricdecrypt_struct
{
	RTS_IEC_HANDLE hAlgo;				/* VAR_INPUT */	/* Handle to the algorithm. */
	RtsByteString *pCipherText;			/* VAR_INPUT */	/* Data to be decrypted */
	RtsCryptoKey key;					/* VAR_INPUT */	/* Key to decrypt the data. Has to be a KeyType_Key key. */
	RtsByteString *pInitVector;			/* VAR_INPUT */	/* Init vector of the decrypt. */
	RTS_IEC_BOOL xEnablePadding;		/* VAR_INPUT */	/* Enables padding. If this is not enabled the ciphertext length has to match a multiple of the block length. */
	RtsByteString *pPlainText;			/* VAR_INPUT */	/* Decrypted data. */
	RTS_IEC_RESULT CryptoSymmetricDecrypt;	/* VAR_OUTPUT */	
} cryptosymmetricdecrypt_struct;

void CDECL CDECL_EXT cryptosymmetricdecrypt(cryptosymmetricdecrypt_struct *p);
typedef void (CDECL CDECL_EXT* PFCRYPTOSYMMETRICDECRYPT_IEC) (cryptosymmetricdecrypt_struct *p);
#if defined(CMPCRYPTO_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CRYPTOSYMMETRICDECRYPT_NOTIMPLEMENTED)
	#define USE_cryptosymmetricdecrypt
	#define EXT_cryptosymmetricdecrypt
	#define GET_cryptosymmetricdecrypt(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cryptosymmetricdecrypt(p0) 
	#define CHK_cryptosymmetricdecrypt  FALSE
	#define EXP_cryptosymmetricdecrypt  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cryptosymmetricdecrypt
	#define EXT_cryptosymmetricdecrypt
	#define GET_cryptosymmetricdecrypt(fl)  CAL_CMGETAPI( "cryptosymmetricdecrypt" ) 
	#define CAL_cryptosymmetricdecrypt  cryptosymmetricdecrypt
	#define CHK_cryptosymmetricdecrypt  TRUE
	#define EXP_cryptosymmetricdecrypt  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptosymmetricdecrypt", (RTS_UINTPTR)cryptosymmetricdecrypt, 1, 0xF3963545, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPCRYPTO_IMPLEMENTATION_EXTERNAL)
	#define USE_cryptosymmetricdecrypt
	#define EXT_cryptosymmetricdecrypt
	#define GET_cryptosymmetricdecrypt(fl)  CAL_CMGETAPI( "cryptosymmetricdecrypt" ) 
	#define CAL_cryptosymmetricdecrypt  cryptosymmetricdecrypt
	#define CHK_cryptosymmetricdecrypt  TRUE
	#define EXP_cryptosymmetricdecrypt  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptosymmetricdecrypt", (RTS_UINTPTR)cryptosymmetricdecrypt, 1, 0xF3963545, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpCrypto_Implementationcryptosymmetricdecrypt
	#define EXT_CmpCrypto_Implementationcryptosymmetricdecrypt
	#define GET_CmpCrypto_Implementationcryptosymmetricdecrypt  ERR_OK
	#define CAL_CmpCrypto_Implementationcryptosymmetricdecrypt  cryptosymmetricdecrypt
	#define CHK_CmpCrypto_Implementationcryptosymmetricdecrypt  TRUE
	#define EXP_CmpCrypto_Implementationcryptosymmetricdecrypt  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptosymmetricdecrypt", (RTS_UINTPTR)cryptosymmetricdecrypt, 1, 0xF3963545, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_cryptosymmetricdecrypt
	#define EXT_cryptosymmetricdecrypt
	#define GET_cryptosymmetricdecrypt(fl)  CAL_CMGETAPI( "cryptosymmetricdecrypt" ) 
	#define CAL_cryptosymmetricdecrypt  cryptosymmetricdecrypt
	#define CHK_cryptosymmetricdecrypt  TRUE
	#define EXP_cryptosymmetricdecrypt  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptosymmetricdecrypt", (RTS_UINTPTR)cryptosymmetricdecrypt, 1, 0xF3963545, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_cryptosymmetricdecrypt  PFCRYPTOSYMMETRICDECRYPT_IEC pfcryptosymmetricdecrypt;
	#define EXT_cryptosymmetricdecrypt  extern PFCRYPTOSYMMETRICDECRYPT_IEC pfcryptosymmetricdecrypt;
	#define GET_cryptosymmetricdecrypt(fl)  s_pfCMGetAPI2( "cryptosymmetricdecrypt", (RTS_VOID_FCTPTR *)&pfcryptosymmetricdecrypt, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xF3963545, 0x03051000)
	#define CAL_cryptosymmetricdecrypt  pfcryptosymmetricdecrypt
	#define CHK_cryptosymmetricdecrypt  (pfcryptosymmetricdecrypt != NULL)
	#define EXP_cryptosymmetricdecrypt   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptosymmetricdecrypt", (RTS_UINTPTR)cryptosymmetricdecrypt, 1, 0xF3963545, 0x03051000) 
#endif


/**
 * Perform a symmetric encryption using the algorithm handle.
 * :return: Result of the operation
 */
typedef struct tagcryptosymmetricencrypt_struct
{
	RTS_IEC_HANDLE hAlgo;				/* VAR_INPUT */	/* Handle to the algorithm. */
	RtsByteString *pPlainText;			/* VAR_INPUT */	/* Data to be encrypted */
	RtsCryptoKey key;					/* VAR_INPUT */	/* Key to encrypt the data. Has to be a KeyType_Key key. */
	RtsByteString *pInitVector;			/* VAR_INPUT */	/* Init vector of the ecryption */
	RTS_IEC_BOOL xEnablePadding;		/* VAR_INPUT */	/* Enables padding. If this is not enabled the plaintext length has to match a multiple of the block length. */
	RtsByteString *pCipherText;			/* VAR_INPUT */	/* Encrypted data. */
	RTS_IEC_RESULT CryptoSymmetricEncrypt;	/* VAR_OUTPUT */	
} cryptosymmetricencrypt_struct;

void CDECL CDECL_EXT cryptosymmetricencrypt(cryptosymmetricencrypt_struct *p);
typedef void (CDECL CDECL_EXT* PFCRYPTOSYMMETRICENCRYPT_IEC) (cryptosymmetricencrypt_struct *p);
#if defined(CMPCRYPTO_IMPLEMENTATION_NOTIMPLEMENTED) || defined(CRYPTOSYMMETRICENCRYPT_NOTIMPLEMENTED)
	#define USE_cryptosymmetricencrypt
	#define EXT_cryptosymmetricencrypt
	#define GET_cryptosymmetricencrypt(fl)  ERR_NOTIMPLEMENTED
	#define CAL_cryptosymmetricencrypt(p0) 
	#define CHK_cryptosymmetricencrypt  FALSE
	#define EXP_cryptosymmetricencrypt  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_cryptosymmetricencrypt
	#define EXT_cryptosymmetricencrypt
	#define GET_cryptosymmetricencrypt(fl)  CAL_CMGETAPI( "cryptosymmetricencrypt" ) 
	#define CAL_cryptosymmetricencrypt  cryptosymmetricencrypt
	#define CHK_cryptosymmetricencrypt  TRUE
	#define EXP_cryptosymmetricencrypt  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptosymmetricencrypt", (RTS_UINTPTR)cryptosymmetricencrypt, 1, 0x8D659084, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPCRYPTO_IMPLEMENTATION_EXTERNAL)
	#define USE_cryptosymmetricencrypt
	#define EXT_cryptosymmetricencrypt
	#define GET_cryptosymmetricencrypt(fl)  CAL_CMGETAPI( "cryptosymmetricencrypt" ) 
	#define CAL_cryptosymmetricencrypt  cryptosymmetricencrypt
	#define CHK_cryptosymmetricencrypt  TRUE
	#define EXP_cryptosymmetricencrypt  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptosymmetricencrypt", (RTS_UINTPTR)cryptosymmetricencrypt, 1, 0x8D659084, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpCrypto_Implementationcryptosymmetricencrypt
	#define EXT_CmpCrypto_Implementationcryptosymmetricencrypt
	#define GET_CmpCrypto_Implementationcryptosymmetricencrypt  ERR_OK
	#define CAL_CmpCrypto_Implementationcryptosymmetricencrypt  cryptosymmetricencrypt
	#define CHK_CmpCrypto_Implementationcryptosymmetricencrypt  TRUE
	#define EXP_CmpCrypto_Implementationcryptosymmetricencrypt  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptosymmetricencrypt", (RTS_UINTPTR)cryptosymmetricencrypt, 1, 0x8D659084, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_cryptosymmetricencrypt
	#define EXT_cryptosymmetricencrypt
	#define GET_cryptosymmetricencrypt(fl)  CAL_CMGETAPI( "cryptosymmetricencrypt" ) 
	#define CAL_cryptosymmetricencrypt  cryptosymmetricencrypt
	#define CHK_cryptosymmetricencrypt  TRUE
	#define EXP_cryptosymmetricencrypt  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptosymmetricencrypt", (RTS_UINTPTR)cryptosymmetricencrypt, 1, 0x8D659084, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_cryptosymmetricencrypt  PFCRYPTOSYMMETRICENCRYPT_IEC pfcryptosymmetricencrypt;
	#define EXT_cryptosymmetricencrypt  extern PFCRYPTOSYMMETRICENCRYPT_IEC pfcryptosymmetricencrypt;
	#define GET_cryptosymmetricencrypt(fl)  s_pfCMGetAPI2( "cryptosymmetricencrypt", (RTS_VOID_FCTPTR *)&pfcryptosymmetricencrypt, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x8D659084, 0x03051000)
	#define CAL_cryptosymmetricencrypt  pfcryptosymmetricencrypt
	#define CHK_cryptosymmetricencrypt  (pfcryptosymmetricencrypt != NULL)
	#define EXP_cryptosymmetricencrypt   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"cryptosymmetricencrypt", (RTS_UINTPTR)cryptosymmetricencrypt, 1, 0x8D659084, 0x03051000) 
#endif


#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/




typedef struct
{
	IBase_C *pBase;
} ICmpCrypto_Implementation_C;

#ifdef CPLUSPLUS
class ICmpCrypto_Implementation : public IBase
{
	public:
};
	#ifndef ITF_CmpCrypto_Implementation
		#define ITF_CmpCrypto_Implementation static ICmpCrypto_Implementation *pICmpCrypto_Implementation = NULL;
	#endif
	#define EXTITF_CmpCrypto_Implementation
#else	/*CPLUSPLUS*/
	typedef ICmpCrypto_Implementation_C		ICmpCrypto_Implementation;
	#ifndef ITF_CmpCrypto_Implementation
		#define ITF_CmpCrypto_Implementation
	#endif
	#define EXTITF_CmpCrypto_Implementation
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_CMPCRYPTO_IMPLEMENTATIONITF_H_*/
