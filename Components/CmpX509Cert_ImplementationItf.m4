/**
 * <interfacename>CmpX509Cert_Implementation</interfacename>
 * <description></description>
 *
 * <copyright></copyright>
 */

SET_INTERFACE_NAME(`CmpX509Cert_Implementation')
SET_PLACEHOLDER_NAME(`CmpX509Cert Implementation')
REF_ITF(`CmpX509CertItf.m4')

/** EXTERN LIB SECTION BEGIN **/
/*  Comments are ignored for m4 compiler so restructured text can be used. changecom(`/*', `*/') */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Clear an OID
 * :return: Result of the operation
 */
typedef struct tagrtsoidclear_struct
{
	RtsOID *oid;						/* VAR_INPUT */	
	RTS_IEC_RESULT RtsOIDClear;			/* VAR_OUTPUT */	
} rtsoidclear_struct;

DEF_API(`void',`CDECL',`rtsoidclear',`(rtsoidclear_struct *p)',1,0xB53A1CAF,0x03050F00)

/**
 * Create an RtsOID based on a given ID.
 * :return: Result of the operation.
 */
typedef struct tagrtsoidcreate_struct
{
	RTS_IEC_STRING *id;					/* VAR_INPUT */	/* OID as string in dottet format. E.g. (1.2.3.4.5.6.7.8.9.0) */
	RtsOID *oid;						/* VAR_INPUT */	/* Pointer to an OID to fill up. */
	RTS_IEC_RESULT RtsOIDCreate;		/* VAR_OUTPUT */	
} rtsoidcreate_struct;

DEF_API(`void',`CDECL',`rtsoidcreate',`(rtsoidcreate_struct *p)',1,0xE11A70BD,0x03050F00)

/**
 * Get the ID of an OID in dottet notation.
 * :return: Result of the operation
 */
typedef struct tagrtsoidgetid_struct
{
	RtsOID *oid;						/* VAR_INPUT */	/* OID to print. */
	RtsByteString *pBuffer;				/* VAR_INPUT */	/* Buffer where to store the ID. */
	RTS_IEC_RESULT RtsOIDGetID;			/* VAR_OUTPUT */	
} rtsoidgetid_struct;

DEF_API(`void',`CDECL',`rtsoidgetid',`(rtsoidgetid_struct *p)',1,0xB69D55FF,0x03050F00)

/**
 * Get the given name of an OID. If the OID is unknown 
 * to the system the dottet notation will be returned.
 * :return: Result of the operation.
 */
typedef struct tagrtsoidgetname_struct
{
	RtsOID *oid;						/* VAR_INPUT */	
	RtsByteString *pBuffer;				/* VAR_INPUT */	
	RTS_IEC_RESULT RtsOIDGetName;		/* VAR_OUTPUT */	
} rtsoidgetname_struct;

DEF_API(`void',`CDECL',`rtsoidgetname',`(rtsoidgetname_struct *p)',1,0xBEA6E204,0x03050F00)

/**
 * Check if a certificate is bound to a specific host name. Both subject and subject alternative names are checked.
 * :return: True if the host name is part of the certificate.
 */
typedef struct tagx509certcheckhost_struct
{
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	
	RTS_IEC_STRING *pHost;				/* VAR_INPUT */	/* Handle of to certificate. */
	RTS_IEC_DWORD flags;				/* VAR_INPUT, Enum: RTSX509CERTCHECKFLAGS */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Flags how to check for the host name. Values of the enumeration can be combined. */
	RTS_IEC_BOOL X509CertCheckHost;		/* VAR_OUTPUT */	
} x509certcheckhost_struct;

DEF_API(`void',`CDECL',`x509certcheckhost',`(x509certcheckhost_struct *p)',1,0x7EE75544,0x03050F00)

/**
 * Check if a certificate is bound to a specific IP Address.
 * :return: True if the IP is part of the certificate.
 */
typedef struct tagx509certcheckip_struct
{
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	
	INADDR *pIP;						/* VAR_INPUT */	/* Handle of to certificate. */
	RTS_IEC_DWORD flags;				/* VAR_INPUT, Enum: RTSX509CERTCHECKFLAGS */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Flags how to check for the IP address. Values of the enumeration can be combined. */
	RTS_IEC_BOOL X509CertCheckIP;		/* VAR_OUTPUT */	
} x509certcheckip_struct;

DEF_API(`void',`CDECL',`x509certcheckip',`(x509certcheckip_struct *p)',1,0x9F16A670,0x03050F00)

/**
 * Close the certificate.
 * :return: Result of the operation.
 */
typedef struct tagx509certclose_struct
{
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	/* Handle of to certificate. */
	RTS_IEC_RESULT X509CertClose;		/* VAR_OUTPUT */	
} x509certclose_struct;

DEF_API(`void',`CDECL',`x509certclose',`(x509certclose_struct *p)',1,0x150A5E6B,0x03050F00)

/**
 * <description>x509certcmsdecrypt</description>
 */
typedef struct tagx509certcmsdecrypt_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RTS_IEC_HANDLE hRecipientCert;		/* VAR_INPUT */	
	RtsByteString *pCms;				/* VAR_INPUT */	
	RTS_IEC_INT encoding;				/* VAR_INPUT, Enum: RTSCERTENCODING */
	RtsByteString *pOutData;			/* VAR_INPUT */	
	RTS_IEC_RESULT X509CertCmsDecrypt;	/* VAR_OUTPUT */	
} x509certcmsdecrypt_struct;

DEF_API(`void',`CDECL',`x509certcmsdecrypt',`(x509certcmsdecrypt_struct *p)',1,0xCCAD85D1,0x03050F00)

/**
 * <description>x509certcmsverify</description>
 */
typedef struct tagx509certcmsverify_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RtsByteString *pCms;				/* VAR_INPUT */	
	RTS_IEC_INT encoding;				/* VAR_INPUT, Enum: RTSCERTENCODING */
	RtsByteString *pInData;				/* VAR_INPUT */	
	RtsByteString *pOutData;			/* VAR_INPUT */	
	RTS_IEC_RESULT X509CertCmsVerify;	/* VAR_OUTPUT */	
} x509certcmsverify_struct;

DEF_API(`void',`CDECL',`x509certcmsverify',`(x509certcmsverify_struct *p)',1,0x73653424,0x03050F00)

/**
 * <description>x509certcreatecsr</description>
 */
typedef struct tagx509certcreatecsr_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RTS_IEC_HANDLE hBackend;			/* VAR_INPUT */	
	RtsX509CertInfo *pCertInfo;			/* VAR_INPUT */	
	RTS_IEC_UDINT ui32KeySize;			/* VAR_INPUT */	
	RTS_IEC_INT encoding;				/* VAR_INPUT, Enum: RTSCERTENCODING */
	RtsByteString *pCSR;				/* VAR_INPUT */	
	RTS_IEC_RESULT X509CertCreateCSR;	/* VAR_OUTPUT */	
} x509certcreatecsr_struct;

DEF_API(`void',`CDECL',`x509certcreatecsr',`(x509certcreatecsr_struct *p)',1,0xF64C1D04,0x03050F00)

/**
 * <description>x509certcreateselfsigned</description>
 */
typedef struct tagx509certcreateselfsigned_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RTS_IEC_HANDLE hBackend;			/* VAR_INPUT */	
	RtsX509CertInfo *pCertInfo;			/* VAR_INPUT */	
	RTS_IEC_UDINT ui32KeySize;			/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_HANDLE X509CertCreateSelfSigned;	/* VAR_OUTPUT */	
} x509certcreateselfsigned_struct;

DEF_API(`void',`CDECL',`x509certcreateselfsigned',`(x509certcreateselfsigned_struct *p)',1,0x6765E8BD,0x03050F00)

/**
 * Get the certificate in a binary encoded format. Use the encoding parameter
 * to set the needed format.
 * :return: Result of the operation.
 */
typedef struct tagx509certgetbinary_struct
{
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	/* Handle of the certificate of intrest. */
	RTS_IEC_INT encoding;				/* VAR_INPUT, Enum: RTSCERTENCODING */
	RtsByteString *pCert;				/* VAR_INPUT */	/* Buffer where to store the certificate. If the bytestring contains a NULL memory pointer the function will write the needed bufferlength to the pCert->ui32Length member. */
	RTS_IEC_RESULT X509CertGetBinary;	/* VAR_OUTPUT */	
} x509certgetbinary_struct;

DEF_API(`void',`CDECL',`x509certgetbinary',`(x509certgetbinary_struct *p)',1,0x6F7D6C42,0x03050F00)

/**
 * Get some common content from the certificate.
 * :return: Result of the operation.
 */
typedef struct tagx509certgetcontent_struct
{
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	/* Handle of the certificate of intrest. */
	RtsX509CertInfo *pCertContent;		/* VAR_INPUT */	/* Pointer where to store the information. */
	RTS_IEC_RESULT X509CertGetContent;	/* VAR_OUTPUT */	
} x509certgetcontent_struct;

DEF_API(`void',`CDECL',`x509certgetcontent',`(x509certgetcontent_struct *p)',1,0xDA69570E,0x03050F00)

/**
 * <description>x509certgetprivatekey</description>
 */
typedef struct tagx509certgetprivatekey_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	
	RtsCryptoKey *pPrivateKey;			/* VAR_INPUT */	
	RTS_IEC_RESULT X509CertGetPrivateKey;	/* VAR_OUTPUT */	
} x509certgetprivatekey_struct;

DEF_API(`void',`CDECL',`x509certgetprivatekey',`(x509certgetprivatekey_struct *p)',1,0x279C9A63,0x03050F00)

/**
 * Get the PUBLIC key FROM the certificate.
 *
 * The format of this key is an implementation detail and has to match
 * the expected format of the asymmetric functions of the CmpCrpyotItf.
 * The key data is opaque for the user of the keys. If the keys are needed in a
 * defined exchange format use the CryptoKeyExport function of the CmpCryptoItf.
 * :return: Result of the operation. 
 */
typedef struct tagx509certgetpublickey_struct
{
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	/* Handle of the certificate of intrest. */
	RtsCryptoKey *pPublicKey;			/* VAR_INPUT */	/* Pointer to the crypto key storing the public key. */
	RTS_IEC_RESULT X509CertGetPublicKey;	/* VAR_OUTPUT */	
} x509certgetpublickey_struct;

DEF_API(`void',`CDECL',`x509certgetpublickey',`(x509certgetpublickey_struct *p)',1,0x35142E48,0x03050F00)

/**
 * Generate the certificate thumbprint. The thumbprint will be just the plain bytes of the hash. 
 * The thumprint can be used to identify certificates of the local store. The thumprint may not be globally unique.
 * :return: Result of the operation.
 */
typedef struct tagx509certgetthumbprint_struct
{
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	/* Handle of the certificate of intrest. */
	RTS_IEC_UDINT *hashAlgorithm;		/* VAR_INPUT */	/* The hashing algorithmen used to generate the thumbprint. */
	RtsByteString *pThumprint;			/* VAR_INPUT */	/* Buffer to store the thumbprint. If bytestring is NULL memory ia allocated. */
	RTS_IEC_RESULT X509CertGetThumbprint;	/* VAR_OUTPUT */	
} x509certgetthumbprint_struct;

DEF_API(`void',`CDECL',`x509certgetthumbprint',`(x509certgetthumbprint_struct *p)',1,0x5B1EA1C5,0x03050F00)

/**
 * Check if the extended keyusages of the specified certificate has the specified extended keyusages
 * :return: True if all key usages are part of the certificate.
 */
typedef struct tagx509certhasextendedkeyusage_struct
{
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	
	RTS_IEC_UDINT numOfExKeyUsages;		/* VAR_INPUT */	/* Handle of to certificate. */
	RtsOID *pExKeyUsages;				/* VAR_INPUT */	/* Number of extended keyusages */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to list of extended keyusages */
	RTS_IEC_BOOL X509CertHasExtendedKeyUsage;	/* VAR_OUTPUT */	
} x509certhasextendedkeyusage_struct;

DEF_API(`void',`CDECL',`x509certhasextendedkeyusage',`(x509certhasextendedkeyusage_struct *p)',1,0xFA59BB5D,0x03050F00)

/**
 * Cleanup an RtsX509CertInfo structure. All allocated memory used by this strucutre will be release.
 * :return: Result of the operation
 */
typedef struct tagx509certinfoexit_struct
{
	RtsX509CertInfo *pCertInfo;			/* VAR_INPUT */	/* Pointer to the object to clean up. */
	RTS_IEC_RESULT X509CertInfoExit;	/* VAR_OUTPUT */	
} x509certinfoexit_struct;

DEF_API(`void',`CDECL',`x509certinfoexit',`(x509certinfoexit_struct *p)',1,0x4F4B0310,0x03050F00)

/**
 * Initialize the RtsX509CertInfo structure.
 * :return: Result of the operation
 */
typedef struct tagx509certinfoinit_struct
{
	RtsX509CertInfo *pCertInfo;			/* VAR_INPUT */	/* Pointer to the structure. */
	RTS_IEC_UDINT structSize;			/* VAR_INPUT */	/* Size of the structure. */
	RTS_IEC_RESULT X509CertInfoInit;	/* VAR_OUTPUT */	
} x509certinfoinit_struct;

DEF_API(`void',`CDECL',`x509certinfoinit',`(x509certinfoinit_struct *p)',1,0xD52F28DD,0x03050F00)

/**
 * Check if a certificate has a valid date (notbefore and notafter is in the current time period)
 */
typedef struct tagx509certisdatevalid_struct
{
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Handle of to certificate. */
	RTS_IEC_BOOL X509CertIsDateValid;	/* VAR_OUTPUT */	
} x509certisdatevalid_struct;

DEF_API(`void',`CDECL',`x509certisdatevalid',`(x509certisdatevalid_struct *p)',1,0xB5AE8B3D,0x03050F00)

/**
 * Check if a certificate is selfsigned of is signed by a CA authority
 */
typedef struct tagx509certisselfsigned_struct
{
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Handle of to certificate. */
	RTS_IEC_BOOL X509CertIsSelfSigned;	/* VAR_OUTPUT */	
} x509certisselfsigned_struct;

DEF_API(`void',`CDECL',`x509certisselfsigned',`(x509certisselfsigned_struct *p)',1,0x1B7D16BF,0x03050F00)

/**
 * Release a PRIVATE OR PUBLIC key with THIS FUNCTION. THIS FUNCTION
 * indicates that this key is not needed anymore and allows to clean up ressources
 * used by this key
 * :return: Result of the operation
 */
typedef struct tagx509certkeyclose_struct
{
	RtsCryptoKey *pKey;					/* VAR_INPUT */	/* Pointer to the key */
	RTS_IEC_RESULT X509CertKeyClose;	/* VAR_OUTPUT */	
} x509certkeyclose_struct;

DEF_API(`void',`CDECL',`x509certkeyclose',`(x509certkeyclose_struct *p)',1,0x6A598D05,0x03050F00)

/**
 * <description>x509certstoreaddcert</description>
 */
typedef struct tagx509certstoreaddcert_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RTS_IEC_HANDLE hBackend;			/* VAR_INPUT */	
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	
	RTS_IEC_INT trustLevel;				/* VAR_INPUT, Enum: RTSCERTTRUSTLEVEL */
	RTS_IEC_RESULT X509CertStoreAddCert;	/* VAR_OUTPUT */	
} x509certstoreaddcert_struct;

DEF_API(`void',`CDECL',`x509certstoreaddcert',`(x509certstoreaddcert_struct *p)',1,0x690E5D79,0x03050F00)

/**
 * <description>x509certstoreclose</description>
 */
typedef struct tagx509certstoreclose_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RTS_IEC_RESULT X509CertStoreClose;	/* VAR_OUTPUT */	
} x509certstoreclose_struct;

DEF_API(`void',`CDECL',`x509certstoreclose',`(x509certstoreclose_struct *p)',1,0x048C3968,0x03050F00)

/**
 * <description>x509certstoregetfirstcert</description>
 */
typedef struct tagx509certstoregetfirstcert_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RTS_IEC_HANDLE hBackend;			/* VAR_INPUT */	
	RTS_IEC_INT trustLevel;				/* VAR_INPUT, Enum: RTSCERTTRUSTLEVEL */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_HANDLE X509CertStoreGetFirstCert;	/* VAR_OUTPUT */	
} x509certstoregetfirstcert_struct;

DEF_API(`void',`CDECL',`x509certstoregetfirstcert',`(x509certstoregetfirstcert_struct *p)',1,0x9165907D,0x03050F00)

/**
 * <description>x509certstoregetnextcert</description>
 */
typedef struct tagx509certstoregetnextcert_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RTS_IEC_HANDLE hBackend;			/* VAR_INPUT */	
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_HANDLE X509CertStoreGetNextCert;	/* VAR_OUTPUT */	
} x509certstoregetnextcert_struct;

DEF_API(`void',`CDECL',`x509certstoregetnextcert',`(x509certstoregetnextcert_struct *p)',1,0x894377FA,0x03050F00)

/**
 * <description>x509certstoregetregisteredcert</description>
 */
typedef struct tagx509certstoregetregisteredcert_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RTS_IEC_HANDLE hUseCase;			/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_HANDLE X509CertStoreGetRegisteredCert;	/* VAR_OUTPUT */	
} x509certstoregetregisteredcert_struct;

DEF_API(`void',`CDECL',`x509certstoregetregisteredcert',`(x509certstoregetregisteredcert_struct *p)',1,0x8C0F7D34,0x03050F00)

/**
 * <description>x509certstoreopen</description>
 */
typedef struct tagx509certstoreopen_struct
{
	RTS_IEC_UDINT componentID;			/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_HANDLE X509CertStoreOpen;	/* VAR_OUTPUT */	
} x509certstoreopen_struct;

DEF_API(`void',`CDECL',`x509certstoreopen',`(x509certstoreopen_struct *p)',1,0xFE7CCE6C,0x03050F00)

/**
 * <description>x509certstoreregister</description>
 */
typedef struct tagx509certstoreregister_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RTS_IEC_UDINT cmpID;				/* VAR_INPUT */	
	RtsX509CertInfo *pCertInfo;			/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_HANDLE X509CertStoreRegister;	/* VAR_OUTPUT */	
} x509certstoreregister_struct;

DEF_API(`void',`CDECL',`x509certstoreregister',`(x509certstoreregister_struct *p)',1,0x35F7F607,0x03050F00)

/**
 * <description>x509certstoreremovecert</description>
 */
typedef struct tagx509certstoreremovecert_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RTS_IEC_HANDLE hBackend;			/* VAR_INPUT */	
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	
	RTS_IEC_BOOL xRemovePrivateKey;		/* VAR_INPUT */	
	RTS_IEC_RESULT X509CertStoreRemoveCert;	/* VAR_OUTPUT */	
} x509certstoreremovecert_struct;

DEF_API(`void',`CDECL',`x509certstoreremovecert',`(x509certstoreremovecert_struct *p)',1,0x0E795BC4,0x03050F00)

/**
 * <description>x509certstoresearchgetfirst</description>
 */
typedef struct tagx509certstoresearchgetfirst_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RtsX509CertFilter *pFilters;		/* VAR_INPUT */	
	RTS_IEC_UDINT ui32NumOfFilters;		/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_HANDLE X509CertStoreSearchGetFirst;	/* VAR_OUTPUT */	
} x509certstoresearchgetfirst_struct;

DEF_API(`void',`CDECL',`x509certstoresearchgetfirst',`(x509certstoresearchgetfirst_struct *p)',1,0,0x03050F00)

/**
 * <description>x509certstoresearchgetnext</description>
 */
typedef struct tagx509certstoresearchgetnext_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	
	RtsX509CertFilter *pFilters;		/* VAR_INPUT */	
	RTS_IEC_UDINT ui32NumOfFilters;		/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_HANDLE X509CertStoreSearchGetNext;	/* VAR_OUTPUT */	
} x509certstoresearchgetnext_struct;

DEF_API(`void',`CDECL',`x509certstoresearchgetnext',`(x509certstoresearchgetnext_struct *p)',1,0,0x03050F00)

/**
 * <description>x509certstoreunregister</description>
 */
typedef struct tagx509certstoreunregister_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RTS_IEC_HANDLE hRegisteredComponent;	/* VAR_INPUT */	
	RTS_IEC_RESULT X509CertStoreUnregister;	/* VAR_OUTPUT */	
} x509certstoreunregister_struct;

DEF_API(`void',`CDECL',`x509certstoreunregister',`(x509certstoreunregister_struct *p)',1,0xE41C13F3,0x03050F00)

/**
 * <description>x509certverify</description>
 */
typedef struct tagx509certverify_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	
	RTS_IEC_RESULT X509CertVerify;		/* VAR_OUTPUT */	
} x509certverify_struct;

DEF_API(`void',`CDECL',`x509certverify',`(x509certverify_struct *p)',1,0x9822EB29,0x03050F00)

/**
 * Parse a certificate which is located in the memory (e.g received FROM a
 * communication partner). Once parsed the certificate is stored
 * in a temporary store. Use the function X509CertClose to close the certificate.
 * :return: Handle to the parsed certificate.
 */
typedef struct tagx509parsecertificate_struct
{
	RtsByteString *pCert;				/* VAR_INPUT */	/* Binary encoded certificate. */
	RTS_IEC_INT encoding;				/* VAR_INPUT, Enum: RTSCERTENCODING */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Result of the operation */
	RTS_IEC_HANDLE X509ParseCertificate;	/* VAR_OUTPUT */	
} x509parsecertificate_struct;

DEF_API(`void',`CDECL',`x509parsecertificate',`(x509parsecertificate_struct *p)',1,0x01B27207,0x03050F00)

#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/

