/**
 * <interfacename>CmpCrypto_Implementation</interfacename>
 * <description></description>
 *
 * <copyright></copyright>
 */

SET_INTERFACE_NAME(`CmpCrypto_Implementation')
SET_PLACEHOLDER_NAME(`CmpCrypto Implementation')

/** EXTERN LIB SECTION BEGIN **/
/*  Comments are ignored for m4 compiler so restructured text can be used. changecom(`/*', `*/') */

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

DEF_API(`void',`CDECL',`cryptoasymmetricdecrypt',`(cryptoasymmetricdecrypt_struct *p)',1,0x126B86CC,0x03051000)

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

DEF_API(`void',`CDECL',`cryptoasymmetricencrypt',`(cryptoasymmetricencrypt_struct *p)',1,0xC14613D0,0x03051000)

/**
 * This function can be used to delete a private key from the components internal data store.
 * :return: Result of the operation
 */
typedef struct tagcryptodeleteprivatekey_struct
{
	RtsByteString keyIdentifier;		/* VAR_INPUT */	/* The identifier of the key got from CryptoStorePrivateKey. */
	RTS_IEC_RESULT CryptoDeletePrivateKey;	/* VAR_OUTPUT */	
} cryptodeleteprivatekey_struct;

DEF_API(`void',`CDECL',`cryptodeleteprivatekey',`(cryptodeleteprivatekey_struct *p)',1,0xDE36F1DF,0x03051000)

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

DEF_API(`void',`CDECL',`cryptoderivekey',`(cryptoderivekey_struct *p)',1,0x31C54B5F,0x03051000)

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

DEF_API(`void',`CDECL',`cryptoexportasymmetrickey',`(cryptoexportasymmetrickey_struct *p)',1,0x4628FE5D,0x03051000)

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

DEF_API(`void',`CDECL',`cryptogenerateasymmetrickeypair',`(cryptogenerateasymmetrickeypair_struct *p)',1,0x0AF43BA3,0x03051000)

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

DEF_API(`void',`CDECL',`cryptogeneratehash',`(cryptogeneratehash_struct *p)',1,0x34E1A812,0x03051000)

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

DEF_API(`void',`CDECL',`cryptogeneraterandomnumber',`(cryptogeneraterandomnumber_struct *p)',1,0xF9FC5437,0x03051000)

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

DEF_API(`void',`CDECL',`cryptogetalgorithmbyid',`(cryptogetalgorithmbyid_struct *p)',1,0x3D0776D3,0x03051000)

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

DEF_API(`void',`CDECL',`cryptogetasymmetrickeylength',`(cryptogetasymmetrickeylength_struct *p)',1,0,0x03051000)

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

DEF_API(`void',`CDECL',`cryptogetfirstalgorithm',`(cryptogetfirstalgorithm_struct *p)',1,0xC8A4A345,0x03051000)

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

DEF_API(`void',`CDECL',`cryptogetnextalgorithm',`(cryptogetnextalgorithm_struct *p)',1,0x79EC29C8,0x03051000)

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

DEF_API(`void',`CDECL',`cryptohmacsign',`(cryptohmacsign_struct *p)',1,0x931A9470,0x03051000)

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

DEF_API(`void',`CDECL',`cryptohmacverify',`(cryptohmacverify_struct *p)',1,0x49EEB4A9,0x03051000)

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

DEF_API(`void',`CDECL',`cryptoimportasymmetrickey',`(cryptoimportasymmetrickey_struct *p)',1,0x73EB2A6A,0x03051000)

/**
 * <description>cryptokeyexit</description>
 */
typedef struct tagcryptokeyexit_struct
{
	RtsCryptoKey *pKey;					/* VAR_INPUT */	
	RTS_IEC_RESULT CryptoKeyExit;		/* VAR_OUTPUT */	
} cryptokeyexit_struct;

DEF_API(`void',`CDECL',`cryptokeyexit',`(cryptokeyexit_struct *p)',1,0xD71ED5F3,0x03051000)

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

DEF_API(`void',`CDECL',`cryptokeyinit',`(cryptokeyinit_struct *p)',1,0xE8E228B3,0x03051000)

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

DEF_API(`void',`CDECL',`cryptoloadprivatekey',`(cryptoloadprivatekey_struct *p)',1,0xCFC27A76,0x03051000)

/**
 * <description>cryptortsbytestringexit</description>
 */
typedef struct tagcryptortsbytestringexit_struct
{
	RtsByteString *pByteString;			/* VAR_INPUT */	
	RTS_IEC_RESULT CryptoRtsByteStringExit;	/* VAR_OUTPUT */	
} cryptortsbytestringexit_struct;

DEF_API(`void',`CDECL',`cryptortsbytestringexit',`(cryptortsbytestringexit_struct *p)',1,0x16B297C5,0x03051000)

/**
 * <description>cryptortsbytestringinit</description>
 */
typedef struct tagcryptortsbytestringinit_struct
{
	RtsByteString *pByteString;			/* VAR_INPUT */	
	RTS_IEC_RESULT CryptoRtsByteStringInit;	/* VAR_OUTPUT */	
} cryptortsbytestringinit_struct;

DEF_API(`void',`CDECL',`cryptortsbytestringinit',`(cryptortsbytestringinit_struct *p)',1,0xC1B4C2F9,0x03051000)

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

DEF_API(`void',`CDECL',`cryptortsbytestringinit2',`(cryptortsbytestringinit2_struct *p)',1,0xE2AA0F02,0x03051000)

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

DEF_API(`void',`CDECL',`cryptosignaturegenerate',`(cryptosignaturegenerate_struct *p)',1,0x0C2FBF80,0x03051000)

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

DEF_API(`void',`CDECL',`cryptosignatureverify',`(cryptosignatureverify_struct *p)',1,0x3F425BB9,0x03051000)

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

DEF_API(`void',`CDECL',`cryptostoreprivatekey',`(cryptostoreprivatekey_struct *p)',1,0x348144FC,0x03051000)

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

DEF_API(`void',`CDECL',`cryptosymmetricdecrypt',`(cryptosymmetricdecrypt_struct *p)',1,0xF3963545,0x03051000)

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

DEF_API(`void',`CDECL',`cryptosymmetricencrypt',`(cryptosymmetricencrypt_struct *p)',1,0x8D659084,0x03051000)

#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/

