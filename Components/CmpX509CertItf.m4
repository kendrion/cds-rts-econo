/**
 * <interfacename>CmpX509Cert</interfacename>
 * <description> 
 *	<p>This interface provides functionality to handle and verify X.509 Certificates</p>
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */
SET_INTERFACE_NAME(`CmpX509Cert')
REF_ITF(`CmpCryptoItf.m4')
REF_ITF(`SysSocketItf.m4')

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>Enables or disables CRL checking while verifying a certificate. (DEFAULT: Disabled)</description>
 */
#define X509CERTKEY_INT_VERIFY_USE_CRL					"VerifyUseCRL"
#ifndef X509CERTVALUE_INT_VERIFY_USE_CRL
	#define X509CERTVALUE_INT_VERIFY_USE_CRL			0
#endif

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>Configures the minim allowed key size (in bits) for newly created asymmetric key. Refer to NIST or BSI suggestions.</description>
 */
#define X509CERTKEY_INT_MIN_ASYMMETRIC_KEY_SIZE			"MinAsymmetricKeySize"
#ifndef X509CERTVALUE_INT_MIN_ASYMMETRIC_KEY_SIZE
	#define X509CERTVALUE_INT_MIN_ASYMMETRIC_KEY_SIZE	2048
#endif

/**
 * <category>Static defines</category>
 * <description>This define is used for the PlcShell command "cert-genselfsigned" to specify the number of days until the certificate will expire (if no argument is specified)</description>
 */
#ifndef X509CERT_STANDARD_DAYS_FOR_CERT
	#define X509CERT_STANDARD_DAYS_FOR_CERT				365
#endif

/**
 * <category>Static defines</category>
 * <description>This define is used for the number of days until the certificate will expire for self-signed certificates</description>
 */
#ifndef X509CERT_STANDARD_DAYS_FOR_SELFIGNEDCERT
	#define X509CERT_STANDARD_DAYS_FOR_SELFIGNEDCERT	30
#endif

#define X509CERT_MILLISECONDS_PER_DAY					(24 * 60 * 60 * 1000)

/**
 * <category>SecurityIDs</category>
 * <description>Security IDs of this component</description>
 */
typedef enum
{
    CMPX509CERT_SECURITY_ID_DIFFIEHELLMANPARAMETER = 0
} CmpX509Cert_SecurityIDs;

/**
 * <category>SecuritySettings</category>
 * <description>Security settings of the X.509 certificate management to create Diffie-Hellman parameters. Can be selected in CmpSecurityManager.
 *	NOTE:
 *		Security modes must be ordered in an descending sorting, that the setting with the highest security level is found at the beginning of the list!
 * </description>
 */
#define CMPX509CERT_KEY_STRING_DIFFIEHELLMANPARAMETER			CMPSETTINGS_CATEGORY_SECURITY ".DiffieHellmanParameter_Generate"
#define CMPX509CERT_KEY_STRING_DIFFIEHELLMANPARAMETER_DESC		"Communication mode for online communication"
	
#define CMPX509CERT_VALUE_DIFFIEHELLMANPARAMETER_ON_STARTUP		"ON_STARTUP"
#define CMPX509CERT_VALUE_DIFFIEHELLMANPARAMETER_ON_REQUEST		"ON_REQUEST"

#ifndef CMPX509CERT_VALUE_DIFFIEHELLMANPARAMETER_DEFAULT
	#define CMPX509CERT_VALUE_DIFFIEHELLMANPARAMETER_DEFAULT	CMPX509CERT_VALUE_DIFFIEHELLMANPARAMETER_ON_REQUEST
#endif

#define CMPX509CERT_VALUE_DIFFIEHELLMANPARAMETER_LIST			{ \
																	{1, CMPSECMAN_SFLAGS_NONE, "ON_STARTUP", "Create Diffie-Hellman parameters on startup"},\
																	{0, CMPSECMAN_SFLAGS_NONE, "ON_REQUEST", "Create Diffie-Hellman parameters only on request"}\
																}

/**
 * <category>Static defines</category>
 * <description>This define is used to specify the default length of the Diffie-Hellmann parameters</description>
 */
#ifndef RTS_X509_DIFFIEHELLMAN_DEFAULT_LEN
	#define RTS_X509_DIFFIEHELLMAN_DEFAULT_LEN		2048
#endif

/**
 * <category>Online service tags</category>
 */
#define TAG_X509_TRUSTLEVEL		    0x01
#define TAG_X509_BACKEND            0x02
#define TAG_X509_USECASE            0x03
#define TAG_X509_THUMBPRINT         0x04
#define TAG_X509_CERT               0x05
#define TAG_X509_CSR                0x06
#define TAG_X509_DEST_TRUSTLEVEL    0x07
#define TAG_X509_DEST_BACKEND       0x08
#define TAG_X509_KEY_LENGTH         0x09
#define TAG_X509_USECASE_NAME       0x0A
#define TAG_X509_USECASE_DESC       0x0B
#define TAG_X509_SUBJECT_ID         0x0C
#define TAG_X509_SUBJECT_VALUE      0x0D
#define TAG_X509_ALT_NAME_EMAIL     0x0E
#define TAG_X509_ALT_NAME_DNSNAME   0x0F
#define TAG_X509_ALT_NAME_URI       0x10
#define TAG_X509_ALT_NAME_IPADDRESS 0x12
#define TAG_X509_ALT_NAME_REGISTEREDID 0x13
#define TAG_X509_KEYUSAGE           0x14
#define TAG_X509_EXT_KEYUSAGE       0x15
#define TAG_X509_USECASE_COMPONENT  0x16
#define TAG_X509_DELETE_PKEY        0x17
#define TAG_X509_DAYS_VALID         0x18
#define TAG_X509_GEN_SELF_SIGNED    0x19
#define TAG_X509_GEN_CSR            0x1A
#define TAG_X509_STATUS_HANDLE      0x1B
#define TAG_X509_OPERATION          0x1C
/* Leave tags 0x22 - 0x24 empty. Use for user management. */
#define TAG_X509_RESULT             TAG_ERROR

/* Complex tags */
#define TAG_X509_USECASE_DETAILS    0x81
/* Leave TAG 0x082 empty. Is used for user management. */

/**
 * <category>Online services</category>
 * <service group="SG_X509_CERT" id="SRV_X509_IMPORT_CERT" name="">
 *	<description>
 *		Import certificate service. This service imports the given certificate into the corresponding store of the PLC.
 *		Since this service changes the security configuration of the PLC administrator rights are needed to execute this service.
 *	</description>
 *	<request>
 *		<tag id="TAG_X509_TRUSTLEVEL" name="" cardinality="1..?" type="RTS_UI32"
 *		 description="Trust level where to import the certificate. See the RTSCERTTRUSTLEVEL_* defines for details."/>
 *		<tag id="TAG_X509_BACKEND" name="" cardinality="0..?" type="Type not yet defined"
 *		 description="Identifier of the back-end where to store the certificate. Not used by now."/>
 *		<tag id="TAG_X509_CERT" name="" cardinality="1..?" type=""
 *		 description="Certificate in ANS.1 encoding to import."/>
 *	</request>
 *	<response>
 *		<tag id="TAG_X509_RESULT" name="" cardinality="1..?" type="RTS_UI16"
 *		 description="Result code of online operation"/>
 *	</response>
 * </service>
 */
#define SRV_X509_IMPORT_CERT 0x01

/**
 * <category>Online services</category>
 * <service group="SG_X509_CERT" id="SRV_X509_EXPORT_CERT" name=""
 *  description="Export certificate service. This service exports a selected certificate from the PLC for use in other applications.">
 *	<request>
 *		<tag id="TAG_X509_TRUSTLEVEL" name="" cardinality="1..?" type="RTS_UI32"
 *		 description="Trust level of the certificate to export. See the RTSCERTTRUSTLEVEL_* defines for details."/>
 *		<tag id="TAG_X509_BACKEND" name="" cardinality="0..?" type="Type not yet defined"
 *		 description="Identifier of the back-end of the certificate. Not used by now."/>
 *		<tag id="TAG_X509_THUMBPRINT" name="" cardinality="1..?" type=""
 *		 description="Thumb-print of certificate calculated by the runtime system."/>
 *	</request>
 *	<response>
 *		<tag id="TAG_X509_RESULT" name="" cardinality="1..?" type="RTS_UI16"
 *		 description="Result code of online operation"/>
 *		<tag id="TAG_X509_CERT" name="" cardinality="0..?" type=""
 *		 description="Exported certificate in ASN.1 encoding if the certificate was available."/>
 *	</response>
 * </service>
 */
#define SRV_X509_EXPORT_CERT 0x02

/**
 * <category>Online services</category>
 * <service group="SG_X509_CERT" id="SRV_X509_DELETE_CERT" name="">
 *	<description>
 *		Delete certificate service. This service deletes a certificate from the PLC.
 *		Since this service changes the security configuration of the PLC administrator rights are needed to execute this service.
 *	</description>
 *	<request>
 *		<tag id="TAG_X509_TRUSTLEVEL" name="" cardinality="1..?" type="RTS_UI32"
 *		 description="Trust level of the certificate to delete. See the RTSCERTTRUSTLEVEL_* defines for details."/>
 *		<tag id="TAG_X509_BACKEND" name="" cardinality="0..?" type="Type not yet defined"
 *		 description="Identifier of the back-end of the certificate. Not used by now."/>
 *		<tag id="TAG_X509_THUMBPRINT" name="" cardinality="1..?" type=""
 *		 description="Thumb-print of certificate calculated by the runtime system."/>
 *		<tag id="TAG_X509_DELETE_PKEY" name="" cardinality="0..?" type="RTS_UI32"
 *		 description="Flag if the private key should be deleted too. This is only used for trust level &#x27;OWN&#x27;."/>
 *	</request>
 *	<response>
 *		<tag id="TAG_X509_RESULT" name="" cardinality="1..?" type="RTS_UI16"
 *		 description="Result code of online operation"/>
 *	</response>
 * </service>
 */
#define SRV_X509_DELETE_CERT 0x03

/**
 * <category>Online services</category>
 * <service group="SG_X509_CERT" id="SRV_X509_MOVE_CERT" name="">
 *	<description>
 *		Move certificate service. This service moves certificates from one place to another.
 *		Since this service changes the security configuration of the PLC administrator rights are needed to execute this service.
 *	</description>
 *	<request>
 *		<tag id="TAG_X509_TRUSTLEVEL" name="" cardinality="1..?" type="RTS_UI32"
 *		 description="Trust level of the certificate to move. See the RTSCERTTRUSTLEVEL_* defines for details."/>
 *		<tag id="TAG_X509_BACKEND" name="" cardinality="0..?" type="Type not yet defined"
 *		 description="Identifier of the back-end of the certificate. Not used by now."/>
 *		<tag id="TAG_X509_THUMBPRINT" name="" cardinality="1..?" type=""
 *		 description="Thumb-print of certificate calculated by the runtime system."/>
 *		<tag id="TAG_X509_DEST_TRUSTLEVEL" name="" cardinality="1..?" type="RTS_UI32"
 *		 description="Trust level where to move the certificate to. See the RTSCERTTRUSTLEVEL_* defines for details."/>
 *		<tag id="TAG_X509_DEST_BACKEND" name="" cardinality="0..?" type="Type not yet defined"
 *		 description="Back-end where to move the certificate to. Not used by now."/>
 *	</request>
 *	<response>
 *		<tag id="TAG_X509_RESULT" name="" cardinality="1..?" type="RTS_UI16"
 *		 description="Result code of online operation"/>
 *	</response>
 * </service>
 */
#define SRV_X509_MOVE_CERT 0x04

/**
 * <category>Online services</category>
 * <service group="SG_X509_CERT" id="SRV_X509_LIST_CERTS" name="">
 *	<description>
 *		List certificate service. This service lists all certificates from one place. Maybe not all certificates can be transmitted in one single online service.
 *		In this case the service return ERR_ENTRIES_REMAINING to indicate that more certificates are available. To get the next junk of certificates put the thumb-print of the
 *		last certificate of the last service as a starting point for the next certificates. The thumb-print tag in the response contains the thumb-print of the certificate 
 *		contained in the previous tag. These tags must always occur as a pair.
 *	</description>
 *	<request>
 *		<tag id="TAG_X509_TRUSTLEVEL" name="" cardinality="1..?" type="RTS_UI32"
 *		 description="Trust level of the certificate to list. See the RTSCERTTRUSTLEVEL_* defines for details."/>
 *		<tag id="TAG_X509_BACKEND" name="" cardinality="0..?" type="Type not yet defined"
 *		 description="Identifier of the back-end of the certificate. Not used by now."/>
 *		<tag id="TAG_X509_THUMBPRINT" name="" cardinality="0..?" type=""
 *		 description="Thumb-print of certificate calculated by the runtime system of the last received certificate."/>
 *	</request>
 *	<response>
 *		<tag id="TAG_X509_RESULT" name="" cardinality="1..?" type="RTS_UI16"
 *		 description="Result code of online operation"/>
 *		<tag id="TAG_X509_CERT" name="" cardinality="1..?" type=""
 *		 description="Certificate in ASN.1 format. This tag may occur multiple times."/>
 *		<tag id="TAG_X509_THUMBPRINT" name="" cardinality="1..?" type=""
 *		 description="Thumb-print of certificate calculated by the runtime system."/>
 *	</response>
 * </service>
 */
#define SRV_X509_LIST_CERTS 0x05

/**
 * <category>Online services</category>
 * <service group="SG_X509_CERT" id="SRV_X509_LIST_USECASES" name="">
 *	<description>
 *		List certificate use service. This service return a list of all registered servers or clients that need their own certificates. This can be used to generate the needed
 *		self signed certificates or to generate the corresponding certificate requests. If a certificate is available for a dedicated use case the thumb-print of this certificate
 *		will be put the the service response. This allows to display the corresponding certificate.
 *		If the complete list of use cases can't be transmitted in one single service it will be split up. In this case the service return ERR_ENTRIES_REMAINING to indicate that more use 
 *		cases are available. The get the next junk of use cases is identified by the last use-cases index.
 *	</description>
 *	<request>
 *		<tag id="TAG_X509_USECASE" name="" cardinality="0..?" type="RTS_UI32"
 *		 description="If the last service returned ERR_ENTRIES_REMAINING this is the ID of the last received use case."/>
 *	</request>
 *	<response>
 *		<tag id="TAG_X509_RESULT" name="" cardinality="1..?" type="RTS_UI16"
 *		 description="Result code of online operation"/>
 *		<complextag id="TAG_X509_USECASE_DETAILS" name="" cardinality="1..?"
 *		 description="">
 *			<tag id="TAG_X509_USECASE" name="" cardinality="1..?" type="RTS_UI32"
 *			 description="ID of the use case."/>
 *			<tag id="TAG_X509_USECASE_COMPONENT" name="" cardinality="1..?" type="String"
 *			 description="Component which registered the use case."/>
 *			<tag id="TAG_X509_USECASE_NAME" name="" cardinality="0..?" type="String"
 *			 description="Name of the use-case. Provided by the component."/>
 *			<tag id="TAG_X509_USECASE_DESC" name="" cardinality="0..?" type="String"
 *			 description="Description of the use case. Provided by the component."/>
 *			<tag id="TAG_X509_SUBJECT_ID" name="" cardinality="0..?" type="String"
 *			 description="OID of the current subject field. Always exists with the following TAG_X509_SUBJECT_VALUE field. Sequence is likely to be repeated"/>
 *			<tag id="TAG_X509_SUBJECT_VALUE" name="" cardinality="0..?" type="String"
 *			 description="Value of the current subject field."/>
 *			<tag id="TAG_X509_ALT_NAME_EMAIL" name="" cardinality="0..?" type="String"
 *			 description="Alternative name containing an email address."/>
 *			<tag id="TAG_X509_ALT_NAME_DNSNAME" name="" cardinality="0..?" type="String"
 *			 description="Alternative name containing the DNS name."/>
 *			<tag id="TAG_X509_ALT_NAME_URI" name="" cardinality="0..?" type="String"
 *			 description="Alternative name containing the URI"/>
 *			<tag id="TAG_X509_ALT_NAME_IPADDRESS" name="" cardinality="0..?" type="String"
 *			 description="Alternative name containing the IP-Address."/>
 *			<tag id="TAG_X509_ALT_NAME_REGISTEREDID" name="" cardinality="0..?" type="String"
 *			 description="Alternative name containing an OID in textual representation."/>
 *			<tag id="TAG_X509_KEYUSAGE" name="" cardinality="0..?" type="RTS_UI32"
 *			 description="Key usage of the certificate. See: RTS_KEY_USAGE_DIGITAL_* macros."/>
 *			<tag id="TAG_X509_EXT_KEYUSAGE" name="" cardinality="0..?" type="String"
 *			 description="Extended key usage identified by its textual representation. Can occur multiple times."/>
 *			<tag id="TAG_X509_THUMBPRINT" name="" cardinality="0..?" type=""
 *			 description="Thumb-print of the certificate available for this use case. Left out if no certificate is available."/>
 *			<tag id="TAG_X509_GEN_SELF_SIGNED" name="" cardinality="0..?" type="Empty tag"
 *			 description="A self signed certificate is being generated at the moment."/>
 *			<tag id="TAG_X509_GEN_CSR" name="" cardinality="0..?" type="Empty tag"
 *			 description="A certificate request is being generated at the moment."/>
 *		</complextag>
 *	</response>
 * </service>
 */
#define SRV_X509_LIST_USECASES 0x06

/**
 * <category>Online services</category>
 * <service group="SG_X509_CERT" id="SRV_X509_CREATE_SELFSIGNED" name="">
 *	<description>
 *		Generate self signed certificate service. This service is used to generate a self signed certificate for a registered use case. 
 *		This service will also generate the private key used by the new certificate.
 *		Since this service changes the security configuration of the PLC administrator rights are needed to execute this service.
 *		Repeat this service 
 *	</description>
 *	<request>
 *		<tag id="TAG_X509_USECASE" name="" cardinality="1..?" type="RTS_UI32"
 *		 description="Use-case ID which the certificate is generated for."/>
 *		<tag id="TAG_X509_BACKEND" name="" cardinality="0..?" type="Type not yet defined"
 *		 description="Back-end where to store the certificate. Not used by now."/>
 *		<tag id="TAG_X509_KEY_LENGTH" name="" cardinality="0..?" type="RTS_UI32"
 *		 description="The length of the asymmetric key pair in bits. If left out the default (see MinAsymmetricKeySize) will be used."/>
 *		<tag id="TAG_X509_DAYS_VALID" name="" cardinality="0..?" type="RTS_UI32"
 *		 description="Number of days the self signed certificate is valid."/>
 *	</request>
 *	<response>
 *		<tag id="TAG_X509_RESULT" name="" cardinality="1..?" type="RTS_UI16"
 *		 description="Result code of online operation"/>
 *		<tag id="TAG_X509_STATUS_HANDLE" name="" cardinality="1..?" type="RTS_UI16"
 *		 description="Result code of online operation"/>
 *	</response>
 * </service>
 */
#define SRV_X509_CREATE_SELFSIGNED 0x07

/**
 * <category>Online services</category>
 * <service group="SG_X509_CERT" id="SRV_X509_CREATE_REQUEST" name="">
 *	<description>
 *		Generate certificate signing request service. This service is used to generate a certificate signing request (CSR) for a registered use case.
 *		The private key is stored on the PLC. If the certificate has been generated by a CA this certificate has to be imported to the own store.
 *	</description>
 *	<request>
 *		<tag id="TAG_X509_USECASE" name="" cardinality="1..?" type="RTS_UI32"
 *		 description="Use-case ID which the CSR is generated for."/>
 *		<tag id="TAG_X509_BACKEND" name="" cardinality="0..?" type="Type not yet defined"
 *		 description="Back-end where to store the private key. Not used by now."/>
 *		<tag id="TAG_X509_KEY_LENGTH" name="" cardinality="0..?" type="RTS_UI32"
 *		 description="The length of the asymmetric key pair in bits. If left out the default (see MinAsymmetricKeySize) will be used."/>
 *	</request>
 *	<response>
 *		<tag id="TAG_X509_RESULT" name="" cardinality="1..?" type="RTS_UI16"
 *		 description="Result code of online operation"/>
 *		<tag id="TAG_X509_CSR" name="" cardinality="0..?" type=""
 *		 description="The generated CSR in ASN.1 encoding."/>
 *	</response>
 * </service>
 */
#define SRV_X509_CREATE_REQUEST 0x08

/**
 * <category>Online services</category>
 * <service group="SG_X509_CERT" id="SRV_X509_GET_STATUS" name=""
 *  description="Get the status of long lasting operation. Actually this is used for generating self signed certificates.">
 *	<request>
 *		<tag id="TAG_X509_OPERATION" name="" cardinality="1..?" type="RTS_UI32"
 *		 description="Identifier of the operation. Use the service waiting for as ID."/>
 *		<tag id="TAG_X509_STATUS_HANDLE" name="" cardinality="1..?" type="RTS_UI32"
 *		 description="Use-case ID which the CSR is generated for."/>
 *	</request>
 *	<response>
 *		<tag id="TAG_X509_RESULT" name="" cardinality="1..?" type="RTS_UI16">
 *			<description>
 *				Result code of online operation. 
 *				ERR_OK: Operation finished. 
 *				ERR_INVALID_HANDLE: TAG_X509_STATUS_HANDLE was invalid. 
 *				ERR_PENDING: Operations still running. 
 *				ERR_FAILED: Operations failed.
 *			</description>
 *		</tag>
 *	</response>
 * </service>
 */
#define SRV_X509_GET_STATUS 0x09
 
/**
 * <category>Static defines</category>
 * <description>Predefined objects in the runtime</description>
 */
#define USERDB_OBJECT_X509				        "Device.X509"
#define USERDB_OBJECT_X509_IMPORT_CERT          "Device.X509.ImportCertificate"
#define USERDB_OBJECT_X509_EXPORT_CERT          "Device.X509.ExportCertificate"
#define USERDB_OBJECT_X509_DELETE_CERT          "Device.X509.DeleteCertificate"
#define USERDB_OBJECT_X509_MOVE_CERT            "Device.X509.MoveCertificate"
#define USERDB_OBJECT_X509_LIST_CERTS           "Device.X509.ListCertificates"
#define USERDB_OBJECT_X509_LIST_USE_CASES       "Device.X509.ListUseCases"
#define USERDB_OBJECT_X509_CREATE_SELFSIGNED    "Device.X509.CreateSelfSignedCertificate"
#define USERDB_OBJECT_X509_CREATE_CSR           "Device.X509.CreateCertificateSigningRequest"
#define USERDB_OBJECT_X509_GET_STAUTS           "Device.X509.GetStatus"
#define USERDB_OBJECT_X509_UNKNOWN              "Device.X509.Unknown"







/** EXTERN LIB SECTION BEGIN **/
/*  Comments are ignored for m4 compiler so restructured text can be used. changecom(`/*', `*/') */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description>Enum: RtsCertEncoding</description>
 */
#define RTSCERTENCODING_ASN1    RTS_IEC_INT_C(0x0)	
#define RTSCERTENCODING_BASE64    RTS_IEC_INT_C(0x1)	
/* Typed enum definition */
#define RTSCERTENCODING    RTS_IEC_INT

/**
 * The trusted level has two main meanings:
 * 1. In opened certificates it indicates if the certificate is trusted or not
 * 2. If adding or searching certificates in the store it indicates where to add / search the certificate.
 */
#define RTSCERTTRUSTLEVEL_UNTRUSTED    RTS_IEC_INT_C(0x1)	/* This is the location for untrusted certificates. */
#define RTSCERTTRUSTLEVEL_TRUSTED    RTS_IEC_INT_C(0x2)	/* This is the location for trusted CA or self signed certificates. */
#define RTSCERTTRUSTLEVEL_OWN    RTS_IEC_INT_C(0x3)	/* This is the location for certificates used by the PLC. The private key of these certificates is available. */
#define RTSCERTTRUSTLEVEL_QUARANTINE    RTS_IEC_INT_C(0x4)	/* This location contains certificates which could not be verified because of missing chains. */
#define RTSCERTTRUSTLEVEL_UNKNOWN    RTS_IEC_INT_C(0x5)	/* This is the default for certificates which are not in one of the other stores. Usually this is set when parsing a certificate. */
#define RTSCERTTRUSTLEVEL_CHAIN    RTS_IEC_INT_C(0x6)	/* This location contains chain certificates. These certificates are not 
 trusted but used to build up a chain up to one of the certificates placed 
 in trusted. This is the only store which is local to each opened certificate 
	store. Also adding certificates to this trust level is not persistent. The 
 typical use case is to add chain-certificates received from the communication 
 peer in case of an own protocol implementation. For TLS connection this is done 
 automatically. Due this use-case, the capabilities of this store are somewhat 
 limited. It is not possible to iterate or filter certificates on this store. 
	 Explicit removal of certificates is supported with X509CertStoreRemoveCert. 
 The store is automatically clean up on X509CertStoreClose. */
/* Typed enumeration definition */
#define RTSCERTTRUSTLEVEL    RTS_IEC_INT

/**
 * <description>Enum: RtsX509AltNameType</description>
 */
#define RTSX509ALTNAMETYPE_OTHERNAME    RTS_IEC_INT_C(0x0)	/* Not supported */
#define RTSX509ALTNAMETYPE_EMAIL    RTS_IEC_INT_C(0x1)	/* Supported */
#define RTSX509ALTNAMETYPE_DNSNAME    RTS_IEC_INT_C(0x2)	/* Supported */
#define RTSX509ALTNAMETYPE_X400ADDRESS    RTS_IEC_INT_C(0x3)	/* Not supported */
#define RTSX509ALTNAMETYPE_DIRECTORYNAME    RTS_IEC_INT_C(0x4)	/* Not supported */
#define RTSX509ALTNAMETYPE_EDIPARTYNAME    RTS_IEC_INT_C(0x5)	/* Not supported */
#define RTSX509ALTNAMETYPE_URI    RTS_IEC_INT_C(0x6)	/* Supported */
#define RTSX509ALTNAMETYPE_IPADDRESS    RTS_IEC_INT_C(0x7)	/* Supported */
#define RTSX509ALTNAMETYPE_REGISTERDID    RTS_IEC_INT_C(0x8)	/* Supported */
/* Typed enumeration definition */
#define RTSX509ALTNAMETYPE    RTS_IEC_INT

/**
 * <description>Enumeration: RtsX509CertCheckFlags</description>
 */
#define RTSX509CERTCHECKFLAGS_FORCE_SUBJECT    RTS_IEC_DWORD_C(0x1)	/* Forces that the host-name / IP address is part of certificate subject. Otherwise part of subject alternative name is accepted. */
#define RTSX509CERTCHECKFLAGS_DISABLE_WILDCARDS    RTS_IEC_DWORD_C(0x2)	/* Disable support for wild-card checking. *.example.com in a certificate is NOT accepted. Only FOR X509CertCheckHost. */
#define RTSX509CERTCHECKFLAGS_DISABLE_PARTIAL_WILDCARDS    RTS_IEC_DWORD_C(0x4)	/* Disable support FOR partial wild card checking. ww*.example.com OR *ww.example.com. Only FOR X509CertCheckHost. */
#define RTSX509CERTCHECKFLAGS_ALLOW_MULTILABLE_WILDCARDS    RTS_IEC_DWORD_C(0x8)	/* Allow that wild-cards replace multiple sub domains. *.example.com will accept www.SUB.example.com. Only FOR X509CertCheckHost. */
#define RTSX509CERTCHECKFLAGS_FORCE_SINGLE_SUBDOMAIN    RTS_IEC_DWORD_C(0x10)	/* Forces that .example.com will only accept a single sub domain e.f. SUB.example.com, but NOT www.SUB.example.com. Only FOR X509CertCheckHost. */
/* Typed enumeration definition */
#define RTSX509CERTCHECKFLAGS    RTS_IEC_DWORD

/**
 * <description>Enumeration: RtsX509CertFilterType</description>
 */
#define RTSX509CERTFILTERTYPE_TRUST_LEVEL    RTS_IEC_INT_C(0x0)	
#define RTSX509CERTFILTERTYPE_SUBJECT    RTS_IEC_INT_C(0x1)	
#define RTSX509CERTFILTERTYPE_SUBJECT_MATCHALL    RTS_IEC_INT_C(0x2)	
#define RTSX509CERTFILTERTYPE_CERT_DATEVALID    RTS_IEC_INT_C(0x3)	
#define RTSX509CERTFILTERTYPE_CERT_KEYUSAGE    RTS_IEC_INT_C(0x4)	
#define RTSX509CERTFILTERTYPE_CERT_EXKEYUSAGE    RTS_IEC_INT_C(0x5)	
#define RTSX509CERTFILTERTYPE_CERT_THUMBPRINT    RTS_IEC_INT_C(0x6)	
/* Typed enum definition */
#define RTSX509CERTFILTERTYPE    RTS_IEC_INT

/**
 * <description>RtsOIDStore</description>
 */
typedef union
{
	RTS_IEC_BYTE aOID[16];		
	RTS_IEC_BYTE *pOID;		
} RtsOIDStore;

/**
 * <description>RtsOID</description>
 */
typedef struct tagRtsOID
{
	RTS_IEC_UDINT length;		/* Length of the OID in memory */
	RtsOIDStore data;		/* Storage of the OID */
	RTS_IEC_UDINT flags;		/* Internal */
} RtsOID;

/**
 * <description>RtsX509AltNameStore</description>
 */
typedef union
{
	RTS_IEC_STRING *pEmail;		
	RTS_IEC_STRING *pDnsName;		
	RTS_IEC_STRING *pUri;		
	INADDR ipAddress;		
	RtsOID registerdID;		
} RtsX509AltNameStore;

/**
 * Represents an alternative name of a certificate. The alternative 
 * name can be selected out of different meanings. E.g. E-Mail 
 * address, IP-Address, URI or a DNS name. Use the corresponding
 * fields of the union to get the values. The meaning is declared
 * in the valueType field.
 */
typedef struct tagRtsX509AltName
{
	RTS_IEC_INT valueType;		/* Type of the alternative name */
	RtsX509AltNameStore value;		
} RtsX509AltName;

/**
 * Represents an entry of the X509 Names used in the
 * subject or issuer fields in the certificate.
 * This structure contains the OID to identify the field
 * and the corresponding string as value. Use the 
 * RtsOIDGetName function to get the string
 * representations of the field.
 */
typedef struct tagRtsX509NameEntry
{
	RtsOID id;		/* ID of the entry */
	RTS_IEC_STRING *value;		/* String value of the entry */
} RtsX509NameEntry;

/**
 * <description>RtsX509CertName</description>
 */
typedef struct tagRtsX509CertName
{
	RTS_IEC_UDINT numOfEntries;		/* Number of entries in the X509 Name */
	RtsX509NameEntry *entries;		/* Pointer to a list of name entries. */
} RtsX509CertName;

/**
 * <description>RtsX509ExKeyUsage</description>
 */
typedef struct tagRtsX509ExKeyUsage
{
	RTS_IEC_UDINT numOfExKeyUsages;		/* Number of extended key usages */
	RtsOID *pExKeyUsages;		/* Pointer to a list of extended key usages. */
} RtsX509ExKeyUsage;

/**
 * <description>RtsX509CertFilterContent</description>
 */
typedef union
{
	RTS_IEC_INT trustLevel;		
	RtsX509CertName *subject;		
	RTS_IEC_UDINT keyUsage;		
	RtsX509ExKeyUsage *exKeyUsage;		
	RtsByteString *thumpbrint;		
} RtsX509CertFilterContent;

/**
 * <description>RtsX509CertFilter</description>
 */
typedef struct tagRtsX509CertFilter
{
	RTS_IEC_INT filterType;		
	RtsX509CertFilterContent filterContent;		
} RtsX509CertFilter;

/**
 * This structure contains common fields of an certificate. Most values are stored in
 * textual form if available. The alternative key usages and the signature algorithm
 * are stored as RtsOID. Use the RtsOIDGetName function to get human readable names
 * of this fields. The notBefor and notAfter fields are in UTC format and high resolution
 * timestamp.
 */
typedef struct tagRtsX509CertInfo
{
	RTS_IEC_UDINT ui32StructSize;		/* Structure size. Used if the structure is extended in the future. */
	RtsX509CertName issuer;		/* Common fields of the issuer */
	RtsX509CertName subject;		/* Common fields of the subject */
	RTS_IEC_UDINT numOfAltNames;		/* Number of stored alternative names */
	RtsX509AltName *pAltNames;		/* Pointer to a list of alternative names. */
	RTS_IEC_ULINT notBefore;		/* High resolution UTC timestamp */
	RTS_IEC_ULINT notAfter;		/* High resolution UTC timestamp */
	RTS_IEC_UDINT keyUsage;		/* Key usage field. Use the constants of X509CertKeyUsage to determine the key usages. Every value is represented by a specific bit of the value. */
	RTS_IEC_UDINT numOfExKeyUsages;		/* Number of extended key usages */
	RtsOID *pExKeyUsages;		/* Pointer to a list of extended key usages. */
	RtsOID signatureAlgorithm;		/* OID of the signature algorithm. Use the RtsOIDGetName to get a human readable string. */
} RtsX509CertInfo;

#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/

/**
 * <element name="Result" type="OUT">Result returned by X509CertCreateSelfSigned</element>
 * <element name="hCert" type="OUT">Handle of the generated certificate.</element>
 */
typedef struct
{
	RTS_RESULT Result;
	RTS_HANDLE hCert;
} X509CertCreateSelfSignedAsyncResult;

/**
 * <element name="Result" type="OUT">Result returned by X509CertCreateCSR</element>
 * <element name="hCert" type="OUT">Pointer to the RtsByteString given as parameter in X509CertCreateCSR containing the CSR.</element>
 */
typedef struct
{
	RTS_RESULT Result;
	RtsByteString* pCSR;
} X509CertCreateCSRAsyncResult;


typedef union
{
	X509CertCreateSelfSignedAsyncResult selfSigned;
	X509CertCreateCSRAsyncResult csr;
} X509AsyncOperationResult;

/**
 * <element name="ui32Operation" type="OUT">Identifier which operation was executed.</element>
 * <element name="Result" type="OUT">Result of the operation. Use the field according the ui32Operation.</element>
 * <element name="pCallbackParam" type="OUT">Pointer to callback parameter given in the X509CertCreate...Async function.</element>
 */
typedef struct
{
	RTS_UI32 ui32Operation;
	X509AsyncOperationResult Result;
	void* pCallbackParam;
} X509AsyncResult;

#define CMPX509CERT_ASYNC_FUNCTION_CREATESELFSIGNED		1
#define CMPX509CERT_ASYNC_FUNCTION_CREATECSR			2


typedef void HUGEPTR(CDECL *PFX509ASYNCCALLBACK)(X509AsyncResult *pAsyncStruct);



/* --------------------------------------------------------------------------- */
/*                             Static defines                                  */
/* --------------------------------------------------------------------------- */
/**
 * <category>Key Usage</category>
 * <description>These defines are the bits representing the key usages in the 
 * keyUsage field of the RtsX509CertInfo structure</description>
 */
#define RTS_KEY_USAGE_DIGITAL_SIGNATURE 0x1
#define RTS_KEY_USAGE_DIGITAL_SIGNATURE_STR "Digital Signature"
#define RTS_KEY_USAGE_NON_REPUDIATION 0x2
#define RTS_KEY_USAGE_NON_REPUDIATION_STR "Non Repudiation"
#define RTS_KEY_USAGE_ENCIPHERMENT 0x4
#define RTS_KEY_USAGE_ENCIPHERMENT_STR "Key Encipherment"
#define RTS_KEY_USAGE_DATA_ENCIPHERMENT 0x8
#define RTS_KEY_USAGE_DATA_ENCIPHERMENT_STR "Data Encipherment"
#define RTS_KEY_USAGE_KEY_AGREEMENT 0x10
#define RTS_KEY_USAGE_KEY_AGREEMENT_STR "Key Agreement"
#define RTS_KEY_USAGE_CERTIFICATE_SIGN 0x20
#define RTS_KEY_USAGE_CERTIFICATE_SIGN_STR "Certificate Sign"
#define RTS_KEY_USAGE_CRL_SIGN 0x40
#define RTS_KEY_USAGE_CRL_SIGN_STR "CRL Sign"
#define RTS_KEY_USAGE_ENCIPHER_ONLY 0x80
#define RTS_KEY_USAGE_ENCIPHER_ONLY_STR "Encipher Only"
#define RTS_KEY_USAGE_DECIPHER_ONLY 0x100
#define RTS_KEY_USAGE_DECIPHER_ONLY_STR "Decipher Only"

/**
 * <category>Object Identifiers</category>
 * <description>A list of well known OIDs in their string representations. Use this defines
 * with the function RtsOidCreate to generate a new OID object.</description>
 */
#define RTS_OID_COUNTRY_NAME                "2.5.4.6"
#define RTS_OID_ORGANIZATION_NAME           "2.5.4.10"
#define RTS_OID_ORGANIZATIONAL_UNIT_NAME	"2.5.4.11"
#define RTS_OID_COMMON_NAME				    "2.5.4.3"
#define RTS_OID_LOCALITY_NAME				"2.5.4.7"
#define RTS_OID_STATE_OR_PROVINCE_NAME		"2.5.4.8"
#define RTS_OID_TITLE						"2.5.4.12"
#define RTS_OID_GIVEN_NAME					"2.5.4.42"
#define RTS_OID_INITIALS					"2.5.4.43"
#define RTS_OID_SUR_NAME					"2.5.4.4"
#define RTS_OID_DOMAIN_COMPONENT			"0.9.2342.19200300.100.1.25"
#define RTS_OID_RSA_EMAILADDR				"1.2.840.113549.1.9.1"
#define RTS_OID_STREET_ADDRESS				"2.5.4.9"
#define RTS_OID_RSA_UNSTRUCTNAME			"1.2.840.113549.1.9.2"
#define RTS_OID_RSA_UNSTRUCTADDR			"1.2.840.113549.1.9.8"
#define RTS_OID_DEVICE_SERIAL_NUMBER		"2.5.4.5"
#define RTS_OID_TLS_WEBSERVER_AUTHENTICATION "1.3.6.1.5.5.7.3.1"
#define RTS_OID_TLS_WEBCLIENT_AUTHENTICATION "1.3.6.1.5.5.7.3.2"

/* --------------------------------------------------------------------------- */
/*                                  Types                                      */
/* --------------------------------------------------------------------------- */

typedef struct RtsCertBackendInfo_
{
	int dummy;
} RtsCertBackendInfo;


/* --------------------------------------------------------------------------- */
/*                                  Events                                     */
/* --------------------------------------------------------------------------- */

/**
 * <category>Events</category>
 * <description>This event is fired if the certificate store has been changed.
 * components can then update their certificates if needed.</description>
 */
#define EVT_X509CertStoreChanged		MAKE_EVENTID(EVTCLASS_INFO, 1)

/**
 * <category>Event parameter</category>
 * <element name="trustLevel" type="OUT">Trust level that has changed.</element>
 */
typedef struct
{
	RTSCERTTRUSTLEVEL trustLevel;
} EVTPARAM_X509CertStoreChanged;
#define EVTPARAMID_X509CertStoreChanged						0x0001
#define EVTVERSION_X509CertStoreChanged						0x0001


#ifdef __cplusplus
extern "C" {
#endif

/* --------------------------------------------------------------------------- */
/*                   Basic Certificate store functions                         */
/* --------------------------------------------------------------------------- */

/**
 * <description>Open the certificate store.</description>
 * <param name="componentID" type="IN">ID of the component opening the certificate store.</param>
 * <param name="pResult" type="OUT">Result of the operation.</param>
 * <result>Handle to the certificate store</result>
 */
DEF_ITF_API(`RTS_HANDLE',`CDECL',`X509CertStoreOpen',`(CMPID componentID, RTS_RESULT* pResult)')

/**
 * <description>Close the certificate store.</description>
 * <param name="hCertStore" type="IN">Handle of to certificate store.</param>
 * <result>Result of the operation.</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`X509CertStoreClose',`(RTS_HANDLE hCertStore)')

/**
 * <description>Verify the given certificate. This verify checks only if the certificate
 * itself is trusted using the certificates in the store. The verify checks
 * if the certificate was added to the untrusted certs list. No subjects, key usages
 * or other fields are verified. This has to be done by the application using this function.
 * If the verify should use CRL to verify the certificates set the setting VerifyUseCRL to 1.
 * This is disabled by default.</description>
 * <param name="hCertStore" type="IN">Handle of to certificate store.</param>
 * <param name="hCert" type="IN">Certificate to verify.</param>
 * <result>Result of the operation.</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`X509CertVerify',`(RTS_HANDLE hCertStore, RTS_HANDLE hCert)')

/**
 * <description>Search for the given certificate in the cert store.</description>
 * <param name="hCertStore" type="IN">Handle of to certificate store.</param>
 * <param name="pFilters" type="IN">Pointer to array of filters to be applied.</param>
 * <param name="ui32NumOfFilters" type="IN">Number of applied filters.</param>
 * <result>Handle to the first certificate matching the filter criteria.</result>
 */
DEF_ITF_API(`RTS_HANDLE',`CDECL',`X509CertStoreSearchGetFirst',`(RTS_HANDLE hCertStore, RtsX509CertFilter *pFilters, RTS_UI32 ui32NumOfFilters, RTS_RESULT *pResult)')

/**
 * <description>Search for the given certificate in the cert store.</description>
 * <param name="hCertStore" type="IN">Handle of to certificate store.</param>
 * <param name="hCert" type="IN">Handle of the last found certificate.</param>
 * <param name="pFilters" type="IN">Pointer to array of filters to be applied.</param>
 * <param name="ui32NumOfFilters" type="IN">Number of applied filters.</param>
 * <result>Handle to the first certificate matching the filter criteria.</result>
 */
DEF_ITF_API(`RTS_HANDLE',`CDECL',`X509CertStoreSearchGetNext',`(RTS_HANDLE hCertStore, RTS_HANDLE hCert, RtsX509CertFilter *pFilters, RTS_UI32 ui32NumOfFilters, RTS_RESULT *pResult)')


/* --------------------------------------------------------------------------- */
/*                      Handling single certificates                           */
/* --------------------------------------------------------------------------- */

/**
 * <description>Parse a certificate which is located in the memory (e.g received from a
 * communication partner). Once parsed the certificate is stored
 * in a temporary store. Use the function X509CertClose to close the certificate.
 * </description>
 * <param name="pCert" type="IN">Binary encoded certificate.</param>
 * <param name="encoding" type="IN">Encoding of the certificate.</param>
 * <param name="pResult" type="OUT">Result of the operation</param>
 * <result>Handle to the parsed certificate.</result>
 */
DEF_ITF_API(`RTS_HANDLE',`CDECL',`X509ParseCertificate',`(RtsByteString* pCert, RTSCERTENCODING encoding, RTS_RESULT* pResult)')

/**
 * <description>Get some common content from the certificate.</description>
 * <param name="hCert" type="IN">Handle of the certificate of interest.</param>
 * <param name="pCertContent" type="OUT">Pointer where to store the information.</param>
 * <result>Result of the operation.</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`X509CertGetContent',`(RTS_HANDLE hCert, RtsX509CertInfo* pCertContent)')

/**
 * <description>Get the certificate in a binary encoded format. Use the encoding parameter
 * to set the needed format.
 * </description>
 * <param name="hCert" type="IN">Handle of the certificate of interest.</param>
 * <param name="encoding" type="IN">How to encode the certificate.</param>
 * <param name="pCert" type="OUT">Buffer where to store the certificate. If the byte string contains a NULL memory pointer the function will write the needed buffer length to the pCert->ui32Length member.</param>
 * <result>Result of the operation.</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`X509CertGetBinary',`(RTS_HANDLE hCert, RTSCERTENCODING encoding, RtsByteString* pCert)')

/**
 * <description>Get the public key from the certificate.
 *
 * The format of this key is an implementation detail and has to match
 * the expected format of the asymmetric functions of the CmpCrpyotItf.
 * The key data is opaque for the user of the keys. If the keys are needed in a
 * defined exchange format use the CryptoKeyExport function of the CmpCryptoItf.
 * </description>
 * <param name="hCert" type="IN">Handle of the certificate of interest.</param>
 * <param name="pPublicKey" type="OUT">Pointer to the cryptographic key storing the public key.</param>
 * <result>Result of the operation.</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`X509CertGetPublicKey',`(RTS_HANDLE hCert, RtsCryptoKey* pPublicKey)')

/**
 * <description>Get the private key of the certificate. This is only
 * possible if the private key stored in the certificate store. 
 *
 * The format of this key is an implementation detail and has to match
 * the expected format of the asymmetric functions of the CmpCrpyotItf.
 * The key data is opaque for the user of the keys.
 * </description>
 * <param name="hCert" type="IN">Handle of the certificate of interest.</param>
 * <param name="pPublicKey" type="OUT">Pointer to the cryptographic key storing the private key.</param>
 * <result>Result of the operation.</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`X509CertGetPrivateKey',`(RTS_HANDLE hCertStore, RTS_HANDLE hCert, RtsCryptoKey* pPrivateKey)')

/**
 * <description>Generate the certificate thumb-print. The thumb-print will be just the plain bytes of the hash.
 * Set the hash algorithm to your needs.</description>
 * <param name="hCert" type="IN">Handle of the certificate of interest.</param>
 * <param name="hashAlgorithm" type="IN">The hashing algorithm used to generate the thumb-print.</param>
 * <param name="pThumbprint" type="OUT">Buffer to store the thumb-print. If byte string is NULL memory ia allocated.</param>
 * <result>Result of the operation.</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`X509CertGetThumbprint',`(RTS_HANDLE hCert,  RTSCRYPTOID* hashAlgorithm, RtsByteString* pThumbprint)')

/**
 * <description>Check if a certificate has a valid date (not-before and not-after is in the current time period)</description>
 * <param name="hCert" type="IN">Handle of the certificate</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT pResult" type="ERR_OK">hCert is valid</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_PARAMETER">hCert is invalid</errorcode>
 * <result>Result of the operation</result>
 * <errorcode name="RTS_BOOL" type="TRUE">Date of certificate is valid</errorcode>
 * <errorcode name="RTS_BOOL" type="FALSE">Date of certificate is out of current period</errorcode>
 */
DEF_ITF_API(`RTS_BOOL',`CDECL',`X509CertIsDateValid',`(RTS_HANDLE hCert, RTS_RESULT *pResult)')

/**
 * <description>Check if a certificate is self-signed of is signed by a CA authority</description>
 * <param name="hCert" type="IN">Handle of the certificate</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT pResult" type="ERR_OK">hCert is valid</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_PARAMETER">hCert is invalid</errorcode>
 * <result>Result of the operation</result>
 * <errorcode name="RTS_BOOL" type="TRUE">Certificate is self-signed</errorcode>
 * <errorcode name="RTS_BOOL" type="FALSE">Certificate is signed ba a CA authority</errorcode>
 */
DEF_ITF_API(`RTS_BOOL',`CDECL',`X509CertIsSelfSigned',`(RTS_HANDLE hCert, RTS_RESULT *pResult)')

/**
 * <description>Check if the extended key-usages of the specified certificate has the specified extended key-usages</description>
 * <param name="hCert" type="IN">Handle of the certificate</param>
 * <param name="numOfExKeyUsages" type="IN">Number of extended key-usages</param>
 * <param name="pExKeyUsages" type="IN">Pointer to list of extended key-usages</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT pResult" type="ERR_OK">hCert is valid</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_PARAMETER">hCert is invalid</errorcode>
 * <result>Result of the operation</result>
 * <errorcode name="RTS_BOOL" type="TRUE">Extended key-usages identical</errorcode>
 * <errorcode name="RTS_BOOL" type="FALSE">Extended key-usages not identical</errorcode>
 */
DEF_ITF_API(`RTS_BOOL',`CDECL',`X509CertHasExtendedKeyUsage',`(RTS_HANDLE hCert, RTS_UI32 numOfExKeyUsages, RtsOID *pExKeyUsages, RTS_RESULT *pResult)')

/**
 * <description>Check if a certificate is bound to a specific host name. Both subject and subject alternative names are checked.</description>
 * <param name="hCert" type="IN">Handle of the certificate</param>
 * <param name="pszHostName" type="IN">Host-name to check.</param>
 * <param name="flags" type="IN">Flags how to check host-name: See: Cert check host flags</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT pResult" type="ERR_OK">hCert is valid</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_PARAMETER">hCert is invalid</errorcode>
 * <result>Result of the operation</result>
 * <errorcode name="RTS_BOOL" type="TRUE">Certificate is bound to host-name.</errorcode>
 * <errorcode name="RTS_BOOL" type="FALSE">Certificate is not bound to host-name.</errorcode>
 */
DEF_ITF_API(`RTS_BOOL',`CDECL',`X509CertCheckHost',`(RTS_HANDLE hCert, char *pszHostName, RTSX509CERTCHECKFLAGS flags, RTS_RESULT *pResult)')

/**
 * <description>Check if a certificate is bound to a specific IP Address.</description>
 * <param name="hCert" type="IN">Handle of the certificate</param>
 * <param name="pIP" type="IN">IP address in network byte oder.</param>
 * <param name="flags" type="IN">Flags how to check IP address. See: Cert check host flags</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT pResult" type="ERR_OK">hCert is valid</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_PARAMETER">hCert is invalid</errorcode>
 * <result>Result of the operation</result>
 * <errorcode name="RTS_BOOL" type="TRUE">Certificate is bound to IP address.</errorcode>
 * <errorcode name="RTS_BOOL" type="FALSE">Certificate is not bound to IP address.</errorcode>
 */
DEF_ITF_API(`RTS_BOOL',`CDECL',`X509CertCheckIP',`(RTS_HANDLE hCert, INADDR *pIP, RTSX509CERTCHECKFLAGS flags, RTS_RESULT *pResult)')

/**
 * <description>Compare two certificates if they are identical.</description>
 * <param name="hCert1" type="IN">Handle to first certificate</param>
 * <param name="hCert1" type="IN">Handle to second certificate</param>
 * <result>TRUE if they are identical, FALSE if not.</result>
 */
DEF_ITF_API(`RTS_BOOL',`CDECL',`X509CertCompare',`(RTS_HANDLE hCert1, RTS_HANDLE hCert2)')

/**
 * <description>Release a private or public key with this function. This function
 * indicates that this key is not needed anymore and allows to clean up resources
 * used by this key</description>
 * <para name="pKey" type="IN">Pointer to the key</param>
 * <result>Result of the operation</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`X509CertKeyClose',`(RtsCryptoKey* pKey)')

/**
 * <description>Close the certificate.</description>
 * <param name="hCert" type="IN">Handle of to certificate.</param>
 * <result>Result of the operation.</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`X509CertClose',`(RTS_HANDLE hCert)')

/* --------------------------------------------------------------------------- */
/*                       Handling CMS containers                               */
/* --------------------------------------------------------------------------- */

/**
 * <description>Verifies a CMS signature. This function can handle both (detached and attached) signatures.
 * The signers certificate has to be located in the CMS container. Otherwise the verify will fail.
 * The signers certificate is always verified against the trusted certificate store on the PLC.</description>
 * <param name="hCertStore" type="IN">Handle to the certificate store.</param>
 * <param name="pCms" type="IN">Pointer to a byte string storing the CMS container.</param>
 * <param name="encoding" type="IN">Encoding of the CMS container.</param>
 * <param name="pInData" type="IN">Used only if the signature is detached. In this case this byte string has to store the data to be verified</param>
 * <param name="pOutData" type="IN">Pointer to a byte string where to store the extracted data.</param>
 * <result>ERR_OK if the signature is valid and the signer was trustworthy.
 * ERR_SIGNATURE_MISMATCH if the signature is invalid and / or the signer was not trustworthy.
 * ERR_PARAMETER if the given parameters are not consistent.</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`X509CertCmsVerify',`(RTS_HANDLE hCertStore, RtsByteString* pCms, RTSCERTENCODING encoding, RtsByteString* pInData, RtsByteString* pOutData)')

/**
 * <description>The description of X509CertCmsVerify applies here too. Additional this interface returns a handle to the signers certificate.</description>
 * <param name="hCertStore" type="IN">Handle to the certificate store.</param>
 * <param name="pCms" type="IN">Pointer to a byte string storing the CMS container.</param>
 * <param name="encoding" type="IN">Encoding of the CMS container.</param>
 * <param name="pInData" type="IN">Used only if the signature is detached. In this case this bytes tring has to store the data to be verified</param>
 * <param name="pOutData" type="IN">Pointer to a byte string where to store the extracted data.</param>
 * <param name="phSignerCert" type="IN">Pointer to a handle where to store the signers certificate. 
 *  This handle is only returned if the verification was successful. If the container was signed multiple times this handle contains the first valid certificate. 
 *  Can be NULL.
 * </param>
 * <result>ERR_OK if the signature is valid and the signer was trustworthy.
 * ERR_SIGNATURE_MISMATCH if the signature is invalid and / or the signer was not trustworthy.
 * ERR_PARAMETER if the given parameters are not consistent.</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`X509CertCmsVerify2',`(RTS_HANDLE hCertStore, RtsByteString* pCms, RTSCERTENCODING encoding, RtsByteString* pInData, RtsByteString* pOutData, RTS_HANDLE* phSignerCert)')

/**
 * <description>Decrypt a CMS container.</description>
 * <param name="hCertStore" type="IN">Handle to the certificate store.</param>
 * <param name="hRecipientCert" type="IN">Handle to the recipients certificate. A private key of the certificate has to be available. Though the certificate has to be located in the "own" store.</param>
 * <param name="pCms" type="IN">Pointer to a byte string storing the CMS container.</param>
 * <param name="encoding" type="IN">Encoding of the CMS container.</param>
 * <param name="pOutData" type="IN">Pointer to a byte string where to store the extracted data.</param>
 * <result>ERR_OK if the container was successfully decrypted.
 * ERR_PARAMETER if the given parameters are not consistent.</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`X509CertCmsDecrypt',`(RTS_HANDLE hCertStore, RTS_HANDLE hRecipientCert, RtsByteString* pCms, RTSCERTENCODING encoding, RtsByteString* pOutData)')

/* --------------------------------------------------------------------------- */
/*                             Utility functions                               */
/* --------------------------------------------------------------------------- */

/**
 * <description>Create an RtsOID based on a given ID.</description>
 * <param name="id" type="IN">OID as string in dotted format. E.g. (1.2.3.4.5.6.7.8.9.0)</param>
 * <param name="oid" type="OUT">Pointer to an OID to fill up.</param>
 * <result>Result of the operation.</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`RtsOIDCreate',`(char* id, RtsOID* oid)')

/**
 * <description>Get the ID of an OID in dotted notation.</description>
 * <param name="oid" type="IN">OID to print.</param>
 * <param name="pBuffer" type="OUT">Buffer where to store the name.</param>
 * <result>Result of the operation.</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`RtsOIDGetID',`(RtsOID* oid, RtsByteString* pBuffer)')

/**
 * <description>Get the given name of an OID. If the OID is unknown to the system the number.number.number... notation will be returned.</description>
 * <param name="oid" type="IN">OID to print.</param>
 * <param name="pBuffer" type="OUT">Buffer where to store the name.</param>
 * <result>Result of the operation.</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`RtsOIDGetName',`(RtsOID* oid, RtsByteString* pBuffer)')

/**
 * <description>Clear an OID</description>
 * <result>Result of the operation.</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`RtsOIDClear',`(RtsOID* oid)')

/**
 * <description>Initialize the RtsX509CertInfo structure.</description>
 * <param name="pCertInfo" type="IN">Pointer to the structure.</param>
 * <param name="structSize" type="IN">Size of the structure.</param>
 * <result>Result of the operation.</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`X509CertInfoInit',`(RtsX509CertInfo* pCertInfo, RTS_UI32 structSize)')

/**
 * <description>Cleanup an RtsX509CertInfo structure. All allocated memory used by this structure will be release.</description>
 * <param name="hCert" type="IN">Pointer to the object to clean up.</param>
 * <result>Result of the operation.</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`X509CertInfoExit',`(RtsX509CertInfo* pCertInfo)')


/* --------------------------------------------------------------------------- */
/*                   Organizing the certificate store                          */
/*                                                                             */
/* The following functions are needed to manage the certificate store. If this */
/* management is not implemented by the component the functions should return  */
/* invalid handles and ERR_NOTIMPLEMENTED                                      */
/* --------------------------------------------------------------------------- */


/**
 * <description>Get the first registered back-end of the certificate store.</description> 
 * <param name="hCertStore" type="IN">Handle to the certificate store</param>
 * <param name="pInfo" type="OUT">Pointer to back-end info. Filled up by the function.</param>
 * <param name="pResult" type="OUT">Result of the operation.</param>
 * <result>Handle of the first back-end.</result>
 */
DEF_ITF_API(`RTS_HANDLE',`CDECL',`X509CertStoreGetFirstBackend',`(RTS_HANDLE hCertStore, RtsCertBackendInfo* pInfo, RTS_RESULT* pResult)')

/**
 * <description>Get the next registered back-end of the certificate store.</description>
 * <param name="hCertStore" type="IN">Handle to the certificate store</param>
 * <param name="hBackend" type="IN">Handle to the previous back-end.</param>
 * <param name="pInfo" type="OUT">Pointer to back-end info. Filled up by the function.</param>
 * <param name="pResult" type="OUT">Result of the operation.</param>
 * <result>Handle of the next back-end. RTS_INVALID_HANDLE if no more back-end is available.</result>
 */
DEF_ITF_API(`RTS_HANDLE',`CDECL',`X509CertStoreGetNextBackend',`(RTS_HANDLE hCertStore, RTS_HANDLE hBackend, RtsCertBackendInfo* pInfo, RTS_RESULT* pResult)')


/**
 * <description>The information of a specific certificate back-end.</description>
 * <param name="hCertStore" type="IN">Handle to the certificate store</param>
 * <param name="hBackend" type="IN">Handle to the previous back-end.</param>
 * <param name="pInfo" type="OUT">Pointer to back-end info. Filled up by the function.</param>
 * <result>Result of the operation.</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`X509CertStorGetBackendInfo',`(RTS_HANDLE hCertStore, RTS_HANDLE hBackend, RtsCertBackendInfo* pInfo)')

/**
 * <description>Create a new self signed certificate. A private key is generated and automatically stored.</description>
 * <param name="hCertStore" type="IN">Handle to the certificate store</param>
 * <param name="hBackend" type="IN">Handle to the back-end where to store the generated certificate. RTS_INVALID_HANDLE should be used if no back-end is specified.</param>
 * <param name="pCertInfo" type="IN">Information of the certificate to be generated.</param>
 * <param name="ui32KeySize" type="IN">Size in bits of the private key.</param>
 * <param name="pResult" type="OUT">Result of the operation.
 *      - ERR_OK: Everything went fine.
 *      - ERR_INVALID_HANDLE: Some input handle is invalid.
 *      - ERR_PARAMETER: Some input parameter is invalid.
 *      - ERR_OVERFLOW: The timestamps of the certificate would overflow.
 *      - ERR_NOMEMORY: Not enough memory to perform this operation.
 *      - ERR_FAILED: Creation of self signed certificate failed. failed</param>
 * <result>Handle to the created self-signed certificate</result>
 */
DEF_ITF_API(`RTS_HANDLE',`CDECL',`X509CertCreateSelfSigned',`(RTS_HANDLE hCertStore, RTS_HANDLE hBackend, RtsX509CertInfo* pCertInfo, RTS_UI32 ui32KeySize, RTS_RESULT *pResult)')

/**
 * <description>Create a new self signed certificate, asynchronously. A private key is generated and automatically stored.</description>
 * <param name="hCertStore" type="IN">Handle to the certificate store</param>
 * <param name="hBackend" type="IN">Handle to the back-end where to store the generated certificate. RTS_INVALID_HANDLE should be used if no back-end is specified.</param>
 * <param name="pCertInfo" type="IN">Information of the certificate to be generated.</param>
 * <param name="ui32KeySize" type="IN">Size in bits of the private key.</param>
 * <param name="ui32KeySize" type="IN">Size in bits of the private key.</param>
 * <param name="pCallbackParam" type="IN">Parameter used when the callback is called when the operation has finished.</param>
 * <param name="pfCallback" type="IN">Callback function that is called at the end of the operation</param>
 * <result>Result of the operation</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`X509CertCreateSelfSignedAsync',`(RTS_HANDLE hCertStore, RTS_HANDLE hBackend, RtsX509CertInfo* pCertInfo, RTS_UI32 ui32KeySize, void* pCallbackParam, PFX509ASYNCCALLBACK pfCallback)')

/**
 * <description>Create a new certificate request. A new private key will be 
 * generated and automatically stored in the key store. The certificate request 
 * can be sent to an official CA to get a signed certificate.</description>
 * <param name="hCertStore" type="IN">Handle to the certificate store</param>
 * <param name="hBackend" type="IN">Handle to the back-end where to store the generated certificate. RTS_INVALID_HANDLE should be used if no back-end is specified.</param>
 * <param name="pCertInfo" type="IN">Information of the certificate to be generated.</param>
 * <param name="ui32KeySize" type="IN">Size in bits of the private key.</param>
 * <param name="encoding" type="IN">Encoding of the generated CSR.</param>
 * <param name="pCSR" type="OUT">The signing request in binary form.</param>
 * <result>Result of the operation</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`X509CertCreateCSR',`(RTS_HANDLE hCertStore, RTS_HANDLE hBackend, RtsX509CertInfo* pCertInfo, RTS_UI32 ui32KeySize, RTSCERTENCODING encoding, RtsByteString* pCSR)')

/**
 * <description>Create a new certificate request. A new private key will be 
 * generated and automatically stored in the key store. The certificate request 
 * can be sent to an official CA to get a signed certificate.</description>
 * <param name="hCertStore" type="IN">Handle to the certificate store</param>
 * <param name="hBackend" type="IN">Handle to the back-end where to store the generated certificate. RTS_INVALID_HANDLE should be used if no back-end is specified.</param>
 * <param name="pCertInfo" type="IN">Information of the certificate to be generated.</param>
 * <param name="cmpID" type="IN">Component ID of the component for which the CSR is created.</param>
 * <param name="ui32KeySize" type="IN">Size in bits of the private key.</param>
 * <param name="encoding" type="IN">Encoding of the generated CSR.</param>
 * <param name="pCSR" type="OUT">The signing request in binary form.</param>
 * <param name="pCallbackParam" type="IN">Parameter used when the callback is called when the operation has finished.</param>
 * <param name="pfCallback" type="IN">Callback function that is called at the end of the operation</param>
 * <result>Result of the operation</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`X509CertCreateCSRAsync',`(RTS_HANDLE hCertStore, RTS_HANDLE hBackend, RtsX509CertInfo* pCertInfo, CMPID cmpID, RTS_UI32 ui32KeySize, RTSCERTENCODING encoding, RtsByteString* pCSR, void* pCallbackParam, PFX509ASYNCCALLBACK pfCallback)')

/**
 * <description>Add the given certificate to the Certificate store</description>
 * <param name="hCertStore" type="IN">Handle of to certificate store.</param>
 * <param name="hBackend" type="IN">Handle to the back-end where to store the generated certificate. RTS_INVALID_HANDLE should be used if no back-end is specified.</param>
 * <param name="hCert" type="IN">Handle of the certificate to be imported.</param>
 * <param name="trustLevel" type="IN">The category where to store the certificate. Note: RtsTrustLevel_Own ist not selectable.</param>
 * <param name="pResult">Result of the operation.</param>
 * <result>Handle to the imported certificate.</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`X509CertStoreAddCert',`(RTS_HANDLE hCertStore, RTS_HANDLE hBackend, RTS_HANDLE hCert, RTSCERTTRUSTLEVEL trustLevel)')

/**
 * <description>Remove the certificate from the store.</description>
 * <param name="hCertStore" type="IN">Handle of to certificate store.</param>
 * <param name="hBackend" type="IN">Handle to the back-end where to store the generated certificate. RTS_INVALID_HANDLE should be used if no back-end is specified.</param>
 * <param name="hCert" type="IN">Handle of the certificate to remove.</param>
 * <param name="bRemovePrivateKey" type="IN">Select if the private key of the certificate should be deleted too. If the certificate is renewed the same private key the key shouldn't be deleted.</param>
 * <result>Result of the operation.</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`X509CertStoreRemoveCert',`(RTS_HANDLE hCertStore, RTS_HANDLE hBackend, RTS_HANDLE hCert, RTS_BOOL bRemovePrivateKey)')

/**
 * <description>Get the first certificate of the certificate store.</description>
 * <param name="hCertStore" type="IN">Handle of to certificate store.</param>
 * <param name="hBackend" type="IN">Pointer to a handle of the back-end where to iterate. RTS_INVALID_HANDLE 
 * if all back-ends should be iterated. A valid handle if only a specific back-end should be iterated.</param>
 * <param name="trustLevel" type="IN">Category of certificates to iterate.</param>
 * <param name="pResult" type="OUT">Result of the operation.</param>
 * <result>Handle to the first certificate of the given category.</param>
 */
DEF_ITF_API(`RTS_HANDLE',`CDECL',`X509CertStoreGetFirstCert',`(RTS_HANDLE hCertStore, RTS_HANDLE hBackend, RTSCERTTRUSTLEVEL trustLevel, RTS_RESULT* pResult)')

/**
 * <description>Get the next certificate of the certificate store. If all certificates
 * are read the function will return RTS_INVALID_HANDLE.</description>
 * <param name="hCertStore" type="IN">Handle of to certificate store.</param>
 * <param name="hBackend" type="IN">Pointer to a handle of the back-end where to iterate. RTS_INVALID_HANDLE 
 * if all back-ends should be iterated. A valid handle if only a specific back-end should be iterated.</param>
 * <param name="hCert" type="IN">Handle to the last certificate got by X509CertStoreGetFirst or X509CertStoreGetNext</param>
 * <param name="pResult" type="OUT">Result of the operation.</param>
 * <result>Handle to the next certificate of the given category.</param>
 */
DEF_ITF_API(`RTS_HANDLE',`CDECL',`X509CertStoreGetNextCert',`(RTS_HANDLE hCertStore, RTS_HANDLE hBackend, RTS_HANDLE hCert, RTS_RESULT* pResult)')

/**
 * <description>
 * Register your certificate at the certificate store. This has to be
 * done in order to allow the user the view the different configured certificates
 * and to generate missing certificates or to renew outdated certificates. Register the same
 * information you are using in the X509CertStoreSearch function.
 * </description>
 * <param name="hCertStore" type="IN">Handle of to certificate store.</param>
 * <param name="CmpID" type="IN">Component ID which registered the certificate</param>
 * <param name="pCertInfo" type="IN">Certificate information to be registered. Should match the information needed to use the Search function.</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <result>Handle to the entry</result>
 */
DEF_ITF_API(`RTS_HANDLE',`CDECL',`X509CertStoreRegister',`(RTS_HANDLE hCertStore, CMPID cmpID, RtsX509CertInfo* pCertInfo, RTS_RESULT* pResult)')

/**
 * <description>
 * </description>
 * <param name="hCertStore" type="IN">Handle of to certificate store</param>
 * <param name="hRegisteredComponent" type="IN">Handle to the entry retrieved by X509CertStoreRegister</param>
 * <result>Result of the operation</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`X509CertStoreUnregister',`(RTS_HANDLE hCertStore, RTS_HANDLE hRegisteredComponent)')

/**
 * <description>
 * Get the certificate available for a registered use case. If not certificate is available RTS_INVALID_HANDLE will be returned.
 * The following rules apply for selecting the certificate:
 * - Check if a certificate is configured by the user. (The thumb-print is pinned for component and index). Use this one if available, return error if not available.
 * - If no certificate is configured filter the available certificates by subject, key usage, extended key usage and a valid timestamp. Return error if list is empty.
 * - Split the available certificates by signed and self signed certificates. Prefer the signed certificates over the self signed certificates:
 * - Select the certificate with the longest period of validity.
 * - If some certificates have the same period of validity select the one with the strongest key.
 * </description>
 * <param name="hCertStore" type="IN">Handle of to certificate store.</param>
 * <param name="hUseCase" type="IN">Handle to the registered use case. Retrieved using X509CertStoreRegister.</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <result>Handle to the certificate. Use X509CertClose to close the certificate.</result>
 */
DEF_ITF_API(`RTS_HANDLE',`CDECL',`X509CertStoreGetRegisteredCert',`(RTS_HANDLE hCertStore, RTS_HANDLE hUseCase, RTS_RESULT* pResult)')

#ifdef __cplusplus
}
#endif



