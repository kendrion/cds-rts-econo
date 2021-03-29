/**
 * <interfacename>CmpCrypto</interfacename>
 * <description> 
 *	<p>This interface provides access to different cryptographic algorithms:</p>
 *	<ul>
 *		<li>Symmetric ciphers</li>
 *		<li>Asymmetric ciphers</li>
 *		<li>Message digest algorithms</li>
 *		<li>Hashed message authentication codes (HMAC)</li>
 *		<li>Signature algorithms</li>
 *		<li>Random number generation</li>
 *	</ul>
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */
SET_INTERFACE_NAME(`CmpCrypto')

/** EXTERN LIB SECTION BEGIN **/
/*  Comments are ignored for m4 compiler so restructured text can be used. changecom(`/*', `*/') */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description>Enum: RtsCryptoID</description>
 */
#define RTSCRYPTOID_AES_128_CBC    RTS_IEC_UDINT_C(0x1001)	/* AES 128 bit key in CBC mode */
#define RTSCRYPTOID_AES_128_CFB    RTS_IEC_UDINT_C(0x1002)	/* AES 128 bit key in CFB mode */
#define RTSCRYPTOID_AES_256_CBC    RTS_IEC_UDINT_C(0x1003)	/* AES 256 bit key in CBC mode */
#define RTSCRYPTOID_DES_CBC    RTS_IEC_UDINT_C(0x1004)	/* DES 64 bit key in CBC mode */
#define RTSCRYPTOID_AES_256_CTR    RTS_IEC_UDINT_C(0x1005)	/* AES 256 bit key in CTR mode */
#define RTSCRYPTOID_RSA    RTS_IEC_UDINT_C(0x2001)	/* Plain RSA asymmetric encryption. Not recommended. */
#define RTSCRYPTOID_RSA_OAEP_PADDING    RTS_IEC_UDINT_C(0x2002)	/* RSA asymmetric encryption with OAEP (SHA1) padding. */
#define RTSCRYPTOID_RSA_PKCS1_V15_PADDING    RTS_IEC_UDINT_C(0x2003)	/* RSA asymmetric encryption with #PKCS1 v1.5 padding. Not recommended. */
#define RTSCRYPTOID_RSA_OAEP_SHA256_PADDING    RTS_IEC_UDINT_C(0x2004)	/* RSA asymmetric encryption with OAEP (SHA-256) padding. */
#define RTSCRYPTOID_HASH_MD5    RTS_IEC_UDINT_C(0x3001)	/* MD5 checksum. Not cryptographically safe. */
#define RTSCRYPTOID_HASH_SHA1    RTS_IEC_UDINT_C(0x3002)	/* SHA1 checksum. Not cryptographically safe. */
#define RTSCRYPTOID_HASH_SHA224    RTS_IEC_UDINT_C(0x3003)	/* SHA-224 checksum. */
#define RTSCRYPTOID_HASH_SHA256    RTS_IEC_UDINT_C(0x3004)	/* SHA-256 checksum. */
#define RTSCRYPTOID_HASH_SHA384    RTS_IEC_UDINT_C(0x3005)	/* SHA-384 checksum. */
#define RTSCRYPTOID_HASH_SHA512    RTS_IEC_UDINT_C(0x3006)	/* SHA-512 checksum. */
#define RTSCRYPTOID_HMAC_MD5    RTS_IEC_UDINT_C(0x4001)	/* HMAC based on MD5. Not cryptographically safe. */
#define RTSCRYPTOID_HMAC_SHA1    RTS_IEC_UDINT_C(0x4002)	/* HMAC based on SHA1. Not cryptographically safe. */
#define RTSCRYPTOID_HMAC_SHA224    RTS_IEC_UDINT_C(0x4003)	/* HMAC based on SHA-224. */
#define RTSCRYPTOID_HMAC_SHA256    RTS_IEC_UDINT_C(0x4004)	/* HMAC based on SHA-256. */
#define RTSCRYPTOID_HMAC_SHA384    RTS_IEC_UDINT_C(0x4005)	/* HMAC based on SHA-384. */
#define RTSCRYPTOID_HMAC_SHA512    RTS_IEC_UDINT_C(0x4006)	/* HMAC based on SHA-512. */
#define RTSCRYPTOID_RSA_PKCS1_V15_SHA1    RTS_IEC_UDINT_C(0x5001)	/* Asymmetric signature based on RSA, SHA1 and #PKCS1 v1.5 padding. Not recommended. */
#define RTSCRYPTOID_RSA_PKCS1_V15_SHA256    RTS_IEC_UDINT_C(0x5002)	/* Asymmetric signature based on RSA, SHA-256 and #PKCS1 v1.5 padding. Not recommended. */
#define RTSCRYPTOID_RSA_OAEP_SHA1    RTS_IEC_UDINT_C(0x5003)	/* Not supported. */
#define RTSCRYPTOID_RSA_OAEP_SHA256    RTS_IEC_UDINT_C(0x5004)	/* Not supported. */
#define RTSCRYPTOID_RSA_PSS_SHA256    RTS_IEC_UDINT_C(0x5005)	/* Asymmetric signature based on RSA, SHA-256 and PSS padding. Not recommended. */
#define RTSCRYPTOID_KDF_PSHA1    RTS_IEC_UDINT_C(0x6001)	/* TLS key derivation function based on SHA1. Not recommeded for key generation based on passwords. */
#define RTSCRYPTOID_KDF_PSHA256    RTS_IEC_UDINT_C(0x6002)	/* TLS key derivation function based on SHA-256. Not recommeded for key generation based on passwords. */
#define RTSCRYPTOID_KDF_SCRYPT    RTS_IEC_UDINT_C(0x6003)	/* Scrypt key derivation function. Recommeded to expand passwords into cryptographic keys, or to hash passwords. */
/* Typed enum definition */
#define RTSCRYPTOID    RTS_IEC_UDINT

/**
 * <description>Enum: RtsCryptoKeyType</description>
 */
#define KEYTYPE_KEY    RTS_IEC_DINT_C(0x0)	/* The key is directly available. Stored in a RTS_BYTESTRING. */
#define KEYTYPE_CERTHANDLE    RTS_IEC_DINT_C(0x1)	/* The key is identified by a handle to the certificat. Only used for asymmetric keys. */
#define KEYTYPE_CERTCONTENT    RTS_IEC_DINT_C(0x2)	/* The key is identified by the certificate context. Only used for asymmetric keys. */
/* Typed enum definition */
#define RTSCRYPTOKEYTYPE    RTS_IEC_DINT

/**
 * <description>Enum: RtsCryptoType</description>
 */
#define RTSCRYPTOTYPE_SYMMETRIC    RTS_IEC_UDINT_C(0x1000)	
#define RTSCRYPTOTYPE_ASYMMETRIC    RTS_IEC_UDINT_C(0x2000)	
#define RTSCRYPTOTYPE_HASH    RTS_IEC_UDINT_C(0x3000)	
#define RTSCRYPTOTYPE_HMAC    RTS_IEC_UDINT_C(0x4000)	
#define RTSCRYPTOTYPE_SIGNATURE    RTS_IEC_UDINT_C(0x5000)	
#define RTSCRYPTOTYPE_KEYDERIVE    RTS_IEC_UDINT_C(0x6000)	
/* Typed enum definition */
#define RTSCRYPTOTYPE    RTS_IEC_UDINT

/**
 * <description>Enum: RtsCryptoKeyType</description>
 */
#define KEYTYPE_KEY    RTS_IEC_DINT_C(0x0)	/* The key is directly available. Stored in a RTS_BYTESTRING. */
#define KEYTYPE_CERTHANDLE    RTS_IEC_DINT_C(0x1)	/* The key is identified by a handle to the certificat. Only used for asymmetric keys. */
#define KEYTYPE_CERTCONTENT    RTS_IEC_DINT_C(0x2)	/* The key is identified by the certificate context. Only used for asymmetric keys. */
/* Typed enum definition */
#define RTSCRYPTOKEYTYPE    RTS_IEC_DINT

/**
 * This a representation of a byte string.
 */
typedef struct tagRtsByteString
{
	RTS_IEC_UDINT ui32Len;		/* Current length of data stored in the buffer. */
	RTS_IEC_UDINT ui32MaxLen;		/* The allocated size of the buffer. */
	RTS_IEC_BYTE *pByData;		/* Pointer to buffer */
	RTS_IEC_BOOL xDynamic;		/* Indicates if the data was allocated dynamically */
} RtsByteString;

/**
 * Storage of a crypto key.
 */
typedef union
{
	RtsByteString byteString;		/* Key is stored using the byte string. */
	RTS_IEC_HANDLE hCert;		/* Key is identified by this handle. */
} RtsCryptoKeyStorage;

/**
 * A cryptographic key.
 */
typedef struct tagRtsCryptoKey
{
	RTS_IEC_DINT keyType;		/* The type of the key. */
	RtsCryptoKeyStorage key;		/* Information of the key. Actually only the KeyType_Key is supported. */
} RtsCryptoKey;

/**
 * <description>RtsScryptParameter</description>
 */
typedef struct tagRtsScryptParameter
{
	RTS_IEC_UDINT iterations;		
	RTS_IEC_UDINT blockSize;		/* How many iterations are done. Affects CPU and RAM usage. */
	RTS_IEC_UDINT parallelismFactor;		/* The block size affects memory an CPU usage. */
} RtsScryptParameter;

/**
 * <description>RtsKdfParameter</description>
 */
typedef union
{
	RtsScryptParameter scrypt;		
} RtsKdfParameter;

#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/

/**
 * <category>SecuritySettings</category>
 * <description>Editable security setting: Minumum asymmetric RSA key length
 * </description>
 */
#define CMPCRYPTO_KEY_INT_MINRSALEN					CMPSETTINGS_CATEGORY_SECURITY ".RSAMinKeyLen"
#define CMPCRYPTO_KEY_INT_MINRSALEN_DESC			"Mininmal key length for RSA keys."

#ifndef CMPCRYPTO_VALUE_MINRSALEN_DEFAULT
	#define CMPCRYPTO_VALUE_MINRSALEN_DEFAULT		2048
#endif

/**
 * <description>Information of symmetric ciphers.</description>
 * <param name="ui32KeyLen">The length of the key id bytes.</param>
 * <param name="ui32BlockSize">Block size of the cipher in bytes.</param>
 * <param name="ui32InitVLen">Initialization vector size in bytes.</param>
 */
typedef struct
{
	RTS_UI32	ui32KeyLen;
	RTS_UI32	ui32BlockSize;
	RTS_UI32	ui32InitVLen;
}RtsSymmetricCipherInfo;

/**
 * <description>Information of message digests.</description>
 * <param name="ui32DigestLen">The length generated message digest in bytes..</param>
 */
typedef struct
{
	RTS_UI32	ui32DigestLen;
}RtsDigestInfo;


/**
 * <description>Information of a specific cryptographic algorithm.</description>
 * <param name="ui32CryptoType">Type of the algorithm. See: Crypto Types</param>
 * <param name="ui32CryptoId">ID of the algorithm.</param>
 * <param name="pszCryptoName">Name of the algorithm.</param>
 * <param name="info">algorithm specific information.</param>
 */
typedef struct
{
	RTS_UI32	ui32CryptoType;
	RTS_UI32	ui32CryptoId;
	const char*		pszCryptoName;
	union
	{
		RtsSymmetricCipherInfo symmetric;
		RtsDigestInfo digest;
		RtsDigestInfo HMAC;

	}info;
}RtsCryptoInfo;


#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description>Get a handle to the algorithm using a specific ID</description>
 * <param name="ui32CryptoID" type="IN">ID of the algorithm</param>
 * <param name="pResult" type="IN">Error code: Result of the operation. Can be NULL.</param>
 * <result>Handle to the cryptographic algorithm</result>
 */
DEF_ITF_API(`RTS_HANDLE',`CDECL',`CryptoGetAlgorithmById',`(RTS_UI32 ui32CryptoID, RTS_RESULT* pResult)')

/**
 * <description>Get the first algorithm matching the type given. Use this with the 
 * GetNext function to iterate over algorithms of a specific type.</description>
 * <param name="ui32CryptoType" type="IN">Type of the algorithm. See: Crypto Types</param>
 * <param name="pszName" type="OUT">Name of the algorithm. Can be NULL.</param>
 * <param name="i32MaxNameLen" type="OUT">Maximum length of the name buffer</param>
 * <param name="pui32CryptoID" type="OUT">ID of the algorithm.</param>
 * <param name="pResult" type="IN">Error code: Result of the operation. Can be NULL.</param>
 * <result>Handle to the cryptographic algorithm</result>
 */
DEF_ITF_API(`RTS_HANDLE',`CDECL',`CryptoGetFirstAlgorithm',`(RTS_UI32 ui32CryptoType, char *pszName, RTS_I32 i32MaxNameLen, RTS_UI32 *pui32CryptoID, RTS_RESULT *pResult)')

/**
 * <description>Get the next algorithm matching the type given.</description>
 * <param name="hCrypto" type="IN">Handle to the last algorithm.</param>
 * <param name="ui32CryptoType" type="IN">Handle to the last algorithm.</param>
 * <param name="pszName" type="OUT">Name of the algorithm. Can be NULL.</param>
 * <param name="i32MaxNameLen" type="OUT">Maximum length of the name buffer</param>
 * <param name="pui32CryptoID" type="OUT">ID of the algorithm.</param>
 * <param name="pResult" type="IN">Error code: Result of the operation. Can be NULL.</param>
 * <result>Handle to the cryptographic algorithm</result>
 */
DEF_ITF_API(`RTS_HANDLE',`CDECL',`CryptoGetNextAlgorithm',`(RTS_HANDLE hCrypto, RTS_UI32 ui32CryptoType, char *pszName, RTS_I32 i32MaxNameLen, RTS_UI32 *pui32CryptoID, RTS_RESULT *pResult)')

/**
 * <description>Get information of the algorithm. Don't free or modify the CryptoInfo.</description>
 * <param name="hCrypto" type="IN">Handle to the algorithm.</param>
 * <param name="pResult" type="IN">Error code: Result of the operation. Can be NULL.</param>
 * <result>Pointer to the information structure.</result>
 */
DEF_ITF_API(`RtsCryptoInfo*',`CDECL',`CryptoGetAlgorithmInfo',`(RTS_HANDLE hCrypto, RTS_RESULT* pCryptoInfo)')

/**
 * <description>Perform a symmetric encryption using the algorithm handle.</description>
 * <param name="hAlgo" type="IN">Handle to the algorithm.</param>
 * <param name="pPlainText" type="IN">Data to be encrypted</param>
 * <param name="key" type="IN">Key to encrypt the data. Has to be a KeyType_Key key.</param>
 * <param name="pInitVector" type="IN">Initialization vector of the encryption</param>
 * <param name="bEnablePadding" type="IN">Enables the padding of the algorithm. If padding is not enabled the plain text length has to match a multiple of the cipher block length</param>
 * <param name="pCipherText" type="OUT">Encrypted data.</param>
 * <result>Error code: Result of the operation</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`CryptoSymmetricEncrypt',`(RTS_HANDLE hAlgo, RtsByteString* pPlainText, RtsCryptoKey key, RtsByteString* pInitVector, RTS_BOOL bEnablePadding, RtsByteString* pCipherText)')

/**
 * <description>Perform a symmetric decryption using the algorithm handle.</description>
 * <param name="hAlgo" type="IN">Handle to the algorithm.</param>
 * <param name="pCipherText" type="IN">Data to be decrypted</param>
 * <param name="key" type="IN">Key to decrypt the data. Has to be a KeyType_Key key.</param>
 * <param name="pInitVector" type="IN">Initialization vector of the decrypt.</param>
 * <param name="bEnablePadding" type="IN">Enables the padding of the algorithm. If padding is not enabled the plain text length has to match a multiple of the cipher block length</param>
 * <param name="pCipherText" type="OUT">Decrypted data.</param>
 * <result>Error code: Result of the operation</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`CryptoSymmetricDecrypt',`(RTS_HANDLE hAlgo, RtsByteString* pCipherText, RtsCryptoKey key, RtsByteString* pInitVector, RTS_BOOL bEnablePadding, RtsByteString* pPlainText)')

/**
 * <description>Perform an asymmetric encryption using the algorithm handle.</description>
 * <param name="hAlgo" type="IN">Handle to the algorithm.</param>
 * <param name="pPlainText" type="IN">Data to be encrypted</param>
 * <param name="publicKey" type="IN">Public key used to encrypt the data. Use X509CertGetPublicKey to get the public key form an certificate.</param>
 * <param name="pCipherText" type="OUT">Encrypted data.</param>
 * <result>Error code: Result of the operation</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`CryptoAsymmetricEncrypt',`(RTS_HANDLE hAlgo, RtsByteString* pPlainText, RtsCryptoKey publicKey, RtsByteString* pCipherText)')

/**
 * <description>Perform an asymmetric decryption using the algorithm handle.</description>
 * <param name="hAlgo" type="IN">Handle to the algorithm.</param>
 * <param name="pCiperText" type="IN">Data to be decrypted</param>
 * <param name="privateKey" type="IN">Private key used to decrypt the data. Use X509CertGetPrivateKey to get the private key from an certificate.</param>
 * <param name="pCipherText" type="OUT">Decrypted data.</param>
 * <result>Error code: Result of the operation</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`CryptoAsymmetricDecrypt',`(RTS_HANDLE hAlgo, RtsByteString* pCipherText, RtsCryptoKey privateKey, RtsByteString* pPlainText)')

/**
 * <description>Get the private key size in bits.</description>
 * <param name="priavteKey" type="IN">Asymmetric key of interest. Use X509CertGetPublicKey or X509CertGetPrivateKey to get the asymmetric key.</param>
 * <param name="pResult" type="OUT">Error code: Operation Result</param>
 * <result>Size of the private key in bits</result>
 */
DEF_ITF_API(`RTS_UI32',`CDECL',`CryptoGetAsymmetricKeyLength',`(RtsCryptoKey asymmetricKey, RTS_RESULT* pResult)')

/**
 * <description>Generate an asymmetric key pair that can be used by the specified algorithm.</description>
 * <param name="hAlgo" type="IN">Handle to the algorithm.</param>
 * <param name="ui32KeyLen" type="IN">Length of the key in bits. If 0, the configured minimal key length is used. May be omitted on ECC keys.</param>
 * <param name="pKeyPair" type="OUT">The generated key pair. Can be used for public or private key operations.</param>
 * <param name="pPublicKey" type="OUT">The corresponding public key. May be used for any suitable operation.</param>
 * <result>Operation result.
 *		- ERR_OK: KeyPair generated.
 *		- ERR_INVALID_HANDLE: hAlgo was not a valid handle.
 *		- ERR_PARAMETER: pKeyPair was NULL
 *		- ERR_SIZE_MISMATCH: ui32KeyLen did not meet the minimal required key length.
 *		- ERR_NOT_SUPPORTED: The algorithm passed with hAlgo does not support key generation.
 *		- ERR_FAILED: Some internal error happened.
 * </result>
 */	
DEF_ITF_API(`RTS_RESULT',`CDECL',`CryptoGenerateAsymmetricKeyPair',`(RTS_IEC_HANDLE hAlgo, RTS_IEC_UDINT ui32KeyLen, RtsCryptoKey *pKeyPair, RTS_BOOL bPrivateKeyExportable)')

/**
 * <description>This function can be used to export asymmetric keys.</description>
 * <param name="key" type="IN">The key to be exported.</param>
 * <param name="bBase64" type="IN">Export the key in BASE64 encoding. Otherwise ASN.1 will be used.</param>
 * <param name="bPrivateKey" type="IN">TRUE: Export the private key. FALSE: Export the public key.</param>
 * <param name="pData" type="OUT">Pointer to the buffer where to store the key. Note: 
 *		If pData->pByData == NULL, the needed length to store the key wil be returned in ui32Len;
 *		If pData->pByData != NULL, the data will be written. A Maximum of ui32MaxLen will be written. The written lenth is stored within ui32Len.</param>
 * <result>Operation result. 
 *		- ERR_OK: Key exported successfully or lenght returned.
 *		- ERR_PARAMETER: key was invalid or pData was NULL.
 *		- ERR_NOT_SUPPORTED: It is not allowed to export this private key.</result>
 *		- ERR_FAILED: The key was not exported.
 * </result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`CryptoExportAsymmetricKey',`(RtsCryptoKey key, RTS_BOOL bBase64, RTS_BOOL bPrivateKey, RtsByteString *pData)')

/**
 * <description>This function can be used to import asymmetric keys.</description>
 * <param name="data" type="IN">The data to be imported.</param>
 * <param name="bBase64" type="IN">TRUE: Import the key in BASE64 encoding. FALSE: Import the key in ASN.1 encoding.</param>
 * <param name="bPrivateKey" type="IN">TRUE: Import a private key. FALSE:  Import a public key.</param>
 * <param name="pKey" type="IN">The key generated from the imported data.</param>
 * <result>Operation result.
 *		- ERR_OK: The key was imported successfully.
 *		- ERR_PARAMETER: pKey was NULL or data was invalid.
 * 		- ERR_FAILED: The key was not imported successfully.
 * </result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`CryptoImportAsymmetricKey',`(RtsByteString data, RTS_BOOL bBase64, RTS_BOOL bPrivateKey, RtsCryptoKey *pKey)')

/**
 * <description>This function can be used to store a private key that was imported or generated within the components internal data store.</description>
 * <param name="key" type="IN">The private key stored.</param>
 * <param name="pKeyIdentifier" type="OUT">A bytestring where the key identifier is stored. This identifier can be used to access 
 *	the key later. The identifier does not contain any sensitive data.</param>
 * <result>Operation result.
 *		- ERR_OK: The key was stored successfully.
 *		- ERR_PARAMETER: key was not valid or pKeyIdentifier is invalid.
 * 		- ERR_NOT_SUPPORTED: The key is not a private key that can be stored.
 *		- ERR_FAILED: Some internal error happened.
 * </result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`CryptoStorePrivateKey',`(RtsCryptoKey key, RtsByteString *pKeyIdentifier)')

/**
 * <description>This function can be used to load a private key from the components internal data store.</description>
 * <param name="keyIdentifier" type="IN">The identifier of the key got from CryptoStorePrivateKey.</param>
 * <param name="pKey" type="OUT">The private key retrieved from the internal storage.</param>
 * <result>Operation result.
 *		- ERR_OK: The key was stored successfully.
 *		- ERR_PARAMETER: keyIdentifier was not valid or pKey == NULL.
 * 		- ERR_NO_OBJECT: No key matching the identifier is available.
 *		- ERR_FAILED: Some internal error happened.
 * </result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`CryptoLoadPrivateKey',`(RtsByteString keyIdentifier, RtsCryptoKey *pKey)')

/**
 * <description>This function can be used to delete a private key from the components internal data store.</description>
 * <param name="keyIdentifier" type="IN">The identifier of the key got from CryptoStorePrivateKey.</param>
 * <result>Operation result.
 *		- ERR_OK: The key was stored successfully.
 *		- ERR_PARAMETER: keyIdentifier was not valid or pKey == NULL.
 * 		- ERR_NO_OBJECT: No key matching the identifier is available.
 *		- ERR_FAILED: Some internal error happened.
 * </result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`CryptoDeletePrivateKey',`(RtsByteString keyIdentifier)')

/**
 * <description>Calculate the message digest of the given data.</description>
 * <param name="hAlgo" type="IN">Handle to the algorithm.</param>
 * <param name="pData" type="IN">Data to calculate the message digest.</param>
 * <param name="pHash" type="OUT">Calculated message digest.</param>
 * <result>Result of the operation</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`CryptoGenerateHash',`(RTS_HANDLE hAlgo, RtsByteString* pData, RtsByteString* pHash)')

/**
 * <description>This function derives a new key from an existing secret (key) and an corresponding salt. 
 * The functions generates keys of the requested size which is given in pDerivedKey->ui32MaxLen. If setup 
 * properly this function provides a secure way to store passwords within the file system. By now two
 * classes of algorithms can be use:
 *	1. P_SHA(1, 256): This algorithm can be used to derive session keys from some kind of secret data. 
 *		If this algorithm is used the pSpecificParameters is not evaluated an should be NULL. This algorithm is quite fast.
 *	2. SCRYPT: This algorithm can be used to generate strong keys from weak passwords, or to store passwords 
 *		in a secure way within the file system. This algorithm makes use of the pSpecificParameters and requires this parameter.
 * 		Depending on the configuration given in pSpecificParameters this algorithm is time and memory consuming.
 *		For details see RFC-7914.
 * </description>
 * <param name="hAlgo" type="IN">Handle of the used algoritm. Should be one of RTSCRYPTOID_KDF_* algorithms.</param>
 * <param name="pKey" type="IN">The key that should be derived. The function reads pKey->ui32Len bytes of the given buffer.</param>
 * <param name="pSalt" type="IN">The SALT that should be used to derive the key. The function reads pSalt->ui32Len bytes of the given buffer.</param>
 * <param name="pSpecificParameters" type="IN">Some additional algorithm specific parameters. By now only used for scrypt.</param>
 * <param name="pDerivedKey" type="IN">Destination where to store the derived key. The function generates a key with the size of pDerivedKey->ui32MaxLen.
 *	 The size of the derived key will be stored in pDerivedKey->ui32Len.</param>
 * <result>Operation result.
 *		- ERR_OK: The key was derived successfully.
 *		- ERR_INVALID_HANDLE: hAlgo was not a valid handle to derive keys.
 *		- ERR_PARAMETER: One of the other parameters was invalid.
 * 		- ERR_FAILED: some internal error happened.
 * </result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`CryptoDeriveKey',`(RTS_HANDLE hAlgo, RtsByteString *pKey, RtsByteString *pSalt, RtsKdfParameter* pSpecificParameters, RtsByteString *pDerivedKey)')

/**
 * <description>Generate a hashed message authentication code (HMAC) of the given data and key.</description>
 * <param name="hAlgo" type="IN">Handle to the algorithm.</param>
 * <param name="pData" type="IN">Data to calculate the HMAC.</param>
 * <param name="key" type="IN">Key to be used for the HMAC calculation</param>
 * <param name="pSignature" type="OUT">Calculated HMAC</param>
 * <result>Error code Result of the operation</result>
 **/
DEF_ITF_API(`RTS_RESULT',`CDECL',`CryptoHMACSign',`(RTS_HANDLE hAlgo, RtsByteString* pData, RtsCryptoKey key, RtsByteString* pSignature)')

/**
 * <description>Verify a received hashed message authentication code (HMAC).</description>
 * <param name="hAlgo" type="IN">Handle to the algorithm.</param>
 * <param name="pData" type="IN">Data to calculate the HMAC.</param>
 * <param name="key" type="IN">Key to be used for the HMAC calculation</param>
 * <param name="pSignature" type="IN">Received HMAC</param>
 * <result>Error Code Function returns ERR_OK if the HMAC is valid.</result>
 **/
DEF_ITF_API(`RTS_RESULT',`CDECL',`CryptoHMACVerify',`(RTS_HANDLE hAlgo, RtsByteString* pData, RtsCryptoKey key, RtsByteString* pSignature)')

/**
 * <description>Sign the data using a specific message digest and the private key.</description>
 * <param name="hAlgo" type="IN">Handle to the algorithm.</param>
 * <param name="pData" type="IN">Data to be signed.</param>
 * <param name="privateKey" type="IN">Key to be used signing. Has to be a private key. Use X509CertGetPrivateKey to get the private key.</param>
 * <param name="pSignature" type="IN">Calculated signature of the data.</param>
 * <result>Error code: Result of the operation.</result>
 **/
DEF_ITF_API(`RTS_RESULT',`CDECL',`CryptoSignatureGenerate',`(RTS_HANDLE hAlgo, RtsByteString* pData, RtsCryptoKey privateKey, RtsByteString* pSignature)')

/**
 * <description>Verify a received signature</description>
 * <param name="hAlgo" type="IN">Handle to the algorithm.</param>
 * <param name="pData" type="IN">Data to verify.</param>
 * <param name="publicKey" type="IN">Public key of the sender. X509CertGetPublicKey to get the key.</param>
 * <param name="pSignature" type="IN">Received signature.</param>
 * <result>Error code: Function returns ERR_OK if the signature is valid.</result>
 **/
DEF_ITF_API(`RTS_RESULT',`CDECL',`CryptoSignatureVerify',`(RTS_HANDLE hAlgo, RtsByteString* pData, RtsCryptoKey publicKey, RtsByteString* pSignature)')

/**
 * <description>Generate a number of cryptographic strong bytes.</description>
 * <param name="ui32NumOfRandomBytes" type="IN">Number of bytes needed.</param>
 * <param name="pRandom" type="IN">Buffer to store the bytes.</param>
 * <result>Error code: Function returns ERR_OK if the bytes could be generated</result>
 **/
DEF_ITF_API(`RTS_RESULT',`CDECL',`CryptoGenerateRandomNumber',`(RTS_UI32 ui32NumOfRandomBytes, RtsByteString* pRandom)')

/**
 * <description>Initialize a cryptographic key.</description>
 * <param name="pKey" type="IN">Pointer to the key to be initialized.</param>
 * <param name="key" type="IN">Content of the key.</param>
 * <param name="type" type="IN">Type of the key.</param>
 * <result>Operation result.</result>
 **/
DEF_ITF_API(`RTS_RESULT',`CDECL',`CryptoKeyInit',`(RtsCryptoKey* pKey, RtsCryptoKeyStorage key, RTSCRYPTOKEYTYPE keyType)')

/**
 * <description>Clean up a cryptographic key.</description>
 * <param name="pKey" type="IN">Key to be clean up.</param>
 * <result>Operation result.</result>
 **/
DEF_ITF_API(`RTS_RESULT',`CDECL',`CryptoKeyExit',`(RtsCryptoKey* pKey)')

/**
 * <description>Initialize a RtsByteString string.</description>
 * <param name="pByteString" type="IN">Pointer to the RtsByteString to be initialized.</param>
 * <result>Operation result.</result>
 **/
DEF_ITF_API(`RTS_RESULT',`CDECL',`CryptoRtsByteStringInit',`(RtsByteString* pByteString)')

/**
 * <description>Initialize a byte string.</description>
 * <param name="pByteString" type="IN">Pointer to the RtsByteString to be initialized.</param>
 * <param name="ui32BufferSize" type="IN">Buffersize needed for this byte string.</param>
 * <param name="pBuffer" type="IN">Pointer to a optional static buffer. If NULL is passed the function will allocated ui32BufferSize bytes from the heap.</param>
 * <result>Operation result.</result>
 **/
DEF_ITF_API(`RTS_RESULT',`CDECL',`CryptoRtsByteStringInit2',`(RtsByteString* pByteString, RTS_UI32 ui32BufferSize, RTS_UI8* pBuffer)')

/**
 * <description>Initialize a byte string.</description>
 * <param name="pByteString" type="IN">Pointer to the RtsByteString to be initialized.</param>
 * <param name="ui32BufferSize" type="IN">Buffersize needed for this byte string.</param>
 * <param name="pBuffer" type="IN">Pointer to a optional static buffer. If NULL is passed the function will allocated ui32BufferSize bytes from the heap.</param>
 * <param name="bEmptyBuffer" type="IN">Used for static buffers. If FALSE pByteString->ui32Lenght will be set to ui32BufferSize. Must be TRUE if pBuffer == NULL</param>
 * <result>Operation result.</result>
 **/
DEF_ITF_API(`RTS_RESULT',`CDECL',`CryptoRtsByteStringInit3',`(RtsByteString* pByteString, RTS_UI32 ui32BufferSize, RTS_UI8* pBuffer, RTS_BOOL bEmptyBuffer)')

/**
 * <description>Clean up a byte string.</description>
 * <param name="pByteString" type="IN">Byte string to be clean up.</param>
 * <result>Operation result.</result>
 **/
DEF_ITF_API(`RTS_RESULT',`CDECL',`CryptoRtsByteStringExit',`(RtsByteString* pByteString)')

/**
 * <description>Converts an binary blob into an BASE64 encoded block.
 * 	Note: The size of the BASE64 output must be at least CEIL(inputSize / 3) * 4 bytes.
 * </description>
 * <param name="input" type="IN">Input to be encoded in BASE64</param>
 * <param name="base64Output" type="IN">Buffer to store the BASE64 data</param>
 * <result>Error Code:
 *		- ERR_OK: Encoding successful.
 *		- ERR_PARAMETER: Invalid parameter given.
 *		- ERR_BUFFERSIZE: The base64Output was too small.
 * </result>
 **/
DEF_ITF_API(`RTS_RESULT',`CDECL',`CryptoBase64Encode',`(RtsByteString *input, RtsByteString* base64Output)')

/**
 * <description>DEcodes an BASE64 block into an binary blob.
 * 	Note: The size of the output must be at least CEIL(base64InputSize / 4) * 3 bytes.
 * </description>
 * <param name="base64Input" type="IN">Input of BASE64 encoded data.</param>
 * <param name="output" type="IN">Buffer to store the decoded data</param>
 * <result>Error Code:
 *		- ERR_OK: Decoding successful.
 *		- ERR_PARAMETER: Invalid parameter given.
 *		- ERR_BUFFERSIZE: The base64Output was too small.
 * </result>
 **/
DEF_ITF_API(`RTS_RESULT',`CDECL',`CryptoBase64Decode',`(RtsByteString *base64Input, RtsByteString *output)')

#ifdef __cplusplus
}
#endif
