/**
 * <interfacename>CmpCodeMeter</interfacename>
 * <description></description>
 *
 * <copyright>
 *  Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`CmpCodeMeter')

#define RTS_CM_PUBLIC_KEY_LEN					64

/**
 * <category>CodeMeter Versions</category>
 * <description>
 *	CodeMeter version numbers checked by this CODESYS Control RTS component.
 * </description>
 * <element name="RTS_CM_RUNTIME_MIN_MAJOR_VER">Minimum major version number of the CodeMeter runtime</element>
 * <element name="RTS_CM_RUNTIME_MIN_MINOR_VER">Minimum minor version number of the CodeMeter runtime</element>
 * <element name="RTS_CM_RUNTIME_MIN_BUILD">Minimum build number of the CodeMeter runtime</element>
 */

/* CodeMeter Runtime version 7.10a corresponds to major ver. 7, minor ver. 10, and build 4196. */
#define RTS_CM_RUNTIME_MIN_MAJOR_VER (7)
#define RTS_CM_RUNTIME_MIN_MINOR_VER (10)
#define RTS_CM_RUNTIME_MIN_BUILD (4196)


/**
 * <category>Compiler switch</category>
 * <description>
 *	Compiler switches to enable/disable single features in the component.
 * </description>
 * <element name="RTS_CODEMETER_EMBEDDED">Switch to enable CmCompact on an embedded device.
 *	- WIBU USB Dongles are supported, if they are implemented in the platform specific part (actually VxWorks, Linux and WIndows CE
 *	
 *		NOTE:
 *		This switch must be set on targets on which no WIBU CodeMeter Runtime is available!</element>
 * <element name="RTS_CODEMETER_SOFTLICENSING">Switch to enable CmActLicense / SoftLicense based on the binding value from SysTargetGetSerialNumber_Secure().
 *		NOTE:
 *		This switch must only be set if the target supports a secure serial number that is appropriate for single target licensing!!!
 * </element>
 * <element name="RTS_CODEMETER_DISABLE_USB">Switch to disable WIBU USB dongle support</element>
 * <element name="RTS_CODEMETER_DISABLE_CMCARD">Switch to disable WIBU CF/SD card support</element>
 * <element name="RTS_CODEMETER_DISABLE_LICENSE_CACHE">Switch to disable WIBU license cache feature</element>
 */


/**
 * <description>3S firm codes</description>
 * <element name="RTS_CODEMETER_UNIVERSAL_FIRMCODE" type="IN">Firm code for universal firmcode licenses</element>
 * <element name="RTS_CODEMETER_SOFTLICENSES_FIRMCODE" type="IN">Firm code for softkey licenses (CmActLicenses)</element>
 * <element name="RTS_CODEMETER_LICENSES_FIRMCODE" type="IN">Firm code for hardkey licenses (CmDongle)</element>
 * <element name="RTS_CODEMETER_ACCESS_PROT_FIRMCODE" type="IN">Firm code for access protection</element>
 * <element name="RTS_CODEMETER_ENCRYPTION_FIRMCODE" type="IN">Firm code for encryption of the boot application</element>
 */
#ifndef RTS_CODEMETER_UNIVERSAL_FIRMCODE
	#define RTS_CODEMETER_UNIVERSAL_FIRMCODE		6000437
#endif
#ifndef RTS_CODEMETER_SOFTLICENSES_FIRMCODE
	#define RTS_CODEMETER_SOFTLICENSES_FIRMCODE		5000304
#endif
#ifndef RTS_CODEMETER_LICENSES_FIRMCODE
	#define RTS_CODEMETER_LICENSES_FIRMCODE			101597
#endif
#ifndef RTS_CODEMETER_ACCESS_PROT_FIRMCODE
	#define RTS_CODEMETER_ACCESS_PROT_FIRMCODE		101598
#endif
#ifndef RTS_CODEMETER_ENCRYPTION_FIRMCODE
	#define RTS_CODEMETER_ENCRYPTION_FIRMCODE		101599
#endif


/**
 * <category>Static defines</category>
 * <description>Predefined objects in the runtime</description>
 */
#define USERDB_OBJECT_CODEMETER				        "Device.CodeMeter"


/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>List of wbb files to create empty CmActLicense containers. List of files must be indexed starting with 1.
 *	NOTE:
 *  - Every license vendor must create its own wbb-file with the containing firm code! And so for every license vendor an empty CmAct license container is created
 *	  as a file on the target!
 *
 * Example:
 *	[CmpCodeMeter]
 *	InitLicenseFile.1=[vendor].wbb
 *	...
 * </description>
 */
#define CODEMKEY_STRING_INIT_LICENSE_FILE					"InitLicenseFile."

/**
 * <description>
 *	This is the name of the 3S-wbb file to create an empty soft container!
 * </description>
 */
#ifndef CODEM_3S_INIT_LICENSE_FILE
	#define CODEM_3S_INIT_LICENSE_FILE						"3SLicense.wbb"
#endif

/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>Setting to specify the directory for all act license files.
 * </description>
 */
#define CODEMKEY_STRING_ACTLICENSE_DIRECTORY				"ActLicenseDirectory"
#ifndef CODEMVALUE_STRING_ACTLICENSE_DIRECTORY_DEFAULT
	#define CODEMVALUE_STRING_ACTLICENSE_DIRECTORY_DEFAULT	"./cmact_licenses"
#endif

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>Setting to activate installing license container. The wbb-files(s) must be registered for that (see setting "InitLicenseFile").
 *	NOTE:
 *	The key is deleted after installing the container!
 * </description>
 */
#define CODEMKEY_INT_INSTALL_CMACT_CONTAINER				"InstallCmActContainer"
#ifndef CODEMVALUE_INT_CMACT_CONTAINER
	#define CODEMVALUE_INT_CMACT_CONTAINER					0
#endif

/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>Setting to specify the license server.
 * </description>
 */
#define CODEMKEY_STRING_LICENSE_SERVER				"LicenseServer"
#ifndef CODEMVALUE_STRING_LICENSE_SERVER_DEFAULT
	#define CODEMVALUE_STRING_LICENSE_SERVER_DEFAULT					""
#endif

/**
 * <category>Online services</category>
 * <service group="SG_CMPCODEMETER" id="SRV_CODEMETER_READ_DONGLE_LIST" name=""
 *  description="Generate list of connected WIBU-Boxes">
 *	<request/>
 *	<response>
 *		<tag id="TAG_CM_NUM_OF_DONGLES" name="Number of dongles" cardinality="1..?" type="RTS_UI16"
 *		 description="Number of dongles in the reply"/>
 *		<complextag id="TAG_CM_CMPLX_DONGLE" name="" cardinality="1..?"
 *		 description="Complex tag for dongle entry">
 *			<tag id="TAG_CM_DONGLE_HANDLE" name="Dongle handle" cardinality="1..?" type="char*"
 *			 description="Dongle handle. Here we use the serial number as string"/>
 *			<tag id="TAG_CM_DONGLE_INFOSTRING" name="" cardinality="1..?" type="char*"
 *			 description="Infos string of the dongle"/>
 *		</complextag>
 *	</response>
 * </service>
 */
#define SRV_CODEMETER_READ_DONGLE_LIST 0x01

#define TAG_CM_NUM_OF_DONGLES 0x01
#define TAG_CM_CMPLX_DONGLE 0x81
#define TAG_CM_DONGLE_HANDLE 0x01
#define TAG_CM_DONGLE_INFOSTRING 0x02

/**
 * <category>Online services</category>
 * <service group="SG_CMPCODEMETER" id="SRV_CODEMETER_READ_LIC_PER_DONGLE" name=""
 *  description="Generate license information of a WIBU-Box">
 *	<request/>
 *	<response>
 *		<tag id="TAG_CM_NUM_OF_LICS" name="Number of licenses" cardinality="1..?" type="RTS_UI16"
 *		 description="Number of licenses"/>
 *		<complextag id="TAG_CM_CMPLX_LICDESC" name="" cardinality="1..?"
 *		 description="Complex tag for license entry">
 *			<tag id="TAG_CM_LIC_NAME" name="License name" cardinality="1..?" type="char*"
 *			 description="License name"/>
 *			<tag id="TAG_CM_LIC_COMPANY" name="Company name" cardinality="1..?" type="char*"
 *			 description="Company name"/>
 *			<tag id="TAG_CM_LIC_FIRMCODE" name="Firm code" cardinality="1..?" type="RTS_UI32"
 *			 description="Firm code"/>
 *			<tag id="TAG_CM_LIC_PRODUCTCODE" name="Product code" cardinality="1..?" type="RTS_UI32"
 *			 description="Product code"/>
 *			<tag id="TAG_CM_LIC_FEATUREMAP" name="Feature map" cardinality="1..?" type="RTS_UI32"
 *			 description="Feature map"/>
 *			<tag id="TAG_CM_LIC_LICSTATE" name="License state" cardinality="1..?" type="RTS_UI32"
 *			 description="License state (active/inactive)"/>
 *			<tag id="TAG_CM_LIC_ACTIVATIONURL" name="Activation URL" cardinality="1..?" type="char*"
 *			 description="Activation URL"/>
 *			<tag id="TAG_CM_LIC_DESCRIPTION" name="Description" cardinality="1..?" type="char*"
 *			 description="Description"/>
 *		</complextag>
 *	</response>
 * </service>
 */
#define SRV_CODEMETER_READ_LIC_PER_DONGLE 0x02

#define TAG_CMREQ_DONGLE_HANDLE 0x01
#define TAG_CM_NUM_OF_LICS 0x01
#define TAG_CM_CMPLX_LICDESC 0x81
#define TAG_CM_LIC_NAME 0x01
#define TAG_CM_LIC_COMPANY 0x02
#define TAG_CM_LIC_FIRMCODE 0x03
#define TAG_CM_LIC_PRODUCTCODE 0x04
#define TAG_CM_LIC_FEATUREMAP 0x05
#define TAG_CM_LIC_LICSTATE 0x06
#define TAG_CM_LIC_ACTIVATIONURL 0x07
#define TAG_CM_LIC_DESCRIPTION 0x08

/**
 * <category>Online services</category>
 * <service group="SG_CMPCODEMETER" id="SRV_CODEMETER_CREATE_CONTEXT_FILE" name=""
 *  description="Generate license information of a WIBU-Box">
 *	<request>
 *		<tag id="TAG_CMREQ_DONGLE_HANDLE" name="Dongle handle" cardinality="1..?" type=""
 *		 description="Dongle handle. Here we use the serial number as string"/>
 *		<tag id="TAG_CMREQ_NUM_FIRMCODE" name="Number of firm codes" cardinality="1..?" type="RTS_UI32"
 *		 description="Number of firm codes"/>
 *		<tag id="TAG_CMREQ_FIRMCODE" name="Firm code" cardinality="0..?" type="RTS_UI32"
 *		 description="Requested firm code"/>
 *	</request>
 *	<response>
 *		<tag id="TAG_CM_CONTEXT_FILE_NAME" name="" cardinality="1..?" type="char*"
 *		 description="Name of the generated context file"/>
 *	</response>
 * </service>
 */
#define SRV_CODEMETER_CREATE_CONTEXT_FILE 0x03

#define TAG_CMREQ_NUM_FIRMCODE 0x02
#define TAG_CMREQ_FIRMCODE 0x03
#define TAG_CM_CONTEXT_FILE_NAME 0x01

/**
 * <category>Online services</category>
 * <service group="SG_CMPCODEMETER" id="SRV_CODEMETER_ACTIVATE_UPD_CTXT_FILE" name=""
 *  description="Activate an updated context file">
 *	<request>
 *		<tag id="TAG_CMREQ_CTXT_FILENAME" name="" cardinality="1..?" type=""
 *		 description="TODO"/>
 *		<tag id="TAG_CMREQ_CTXT_DONGLEHANDLE" name="Dongle handle" cardinality="1..?" type="char*"
 *		 description="Dongle handle. Here we use the serial number as string"/>
 *	</request>
 *	<response/>
 * </service>
 */
#define SRV_CODEMETER_ACTIVATE_UPD_CTXT_FILE 0x04

#define TAG_CMREQ_CTXT_FILENAME 0x01
#define TAG_CMREQ_CTXT_DONGLEHANDLE 0x02
#define TAG_CM_ERROR_RTS_ERROR 0x01
#define TAG_CM_ERROR_CM_ERROR 0x02
#define TAG_CM_ERROR_CM_ERROR_TEXT 0x03

/** EXTERN LIB SECTION BEGIN **/
/*  Comments are ignored for m4 compiler so restructured text can be used. changecom(`/*', `*/') */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description>RTS_CODEMETER_INFO</description>
 */
typedef struct tagRTS_CODEMETER_INFO
{
	RTS_IEC_BYTE byMajorVersion;		
	RTS_IEC_BYTE byMinorVersion;		
	RTS_IEC_WORD wBoxMask;		
	RTS_IEC_DWORD dwSerialNumber;		
	RTS_IEC_WORD wChipType;		
	RTS_IEC_WORD wSiliconRevision;		
} RTS_CODEMETER_INFO;

/**
 * <description>RTS_CMBOXENTRY</description>
 */
typedef struct tagRTS_CMBOXENTRY
{
	RTS_IEC_WORD musBoxMask;		
	RTS_IEC_UDINT mulBoxSerial;		
	RTS_IEC_UDINT mflFiCtrl;		
	RTS_IEC_UDINT mulFirmCode;		
	RTS_IEC_WORD musFirmAccessCounter;		
	RTS_IEC_WORD musFirmItemRef;		
	RTS_IEC_UDINT mulFirmUpdateCounter;		
	RTS_IEC_UDINT mulFirmPreciseTime;		
	RTS_IEC_WSTRING mausFirmItemText[256];		
	RTS_IEC_UDINT mulProductCode;		
	RTS_IEC_UDINT mulFeatureMap;		
	RTS_IEC_UDINT mulUnitCounter;		
	RTS_IEC_UDINT mulLicenseQuantity;		
	RTS_IEC_WORD musProductItemRef;		
} RTS_CMBOXENTRY;

/**
 * <description>codemclose</description>
 */
typedef struct tagcodemclose_struct
{
	RTS_IEC_HANDLE hCodeMeter;			/* VAR_INPUT */	
	RTS_IEC_RESULT CodeMClose;			/* VAR_OUTPUT */	
} codemclose_struct;

DEF_API(`void',`CDECL',`codemclose',`(codemclose_struct *p)',1,0x3CEA9D8D,0x03050500)

/**
 * <description>codemdecrypt</description>
 */
typedef struct tagcodemdecrypt_struct
{
	RTS_IEC_HANDLE hCodeMeter;			/* VAR_INPUT */	
	RTS_IEC_UDINT udiEncryptionCode;	/* VAR_INPUT */	
	RTS_IEC_UDINT ulCRC;				/* VAR_INPUT */	
	RTS_IEC_BYTE *pbyData;				/* VAR_INPUT */	
	RTS_IEC_XWORD nDataLen;				/* VAR_INPUT */	
	RTS_IEC_RESULT CodeMDecrypt;		/* VAR_OUTPUT */	
} codemdecrypt_struct;

DEF_API(`void',`CDECL',`codemdecrypt',`(codemdecrypt_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xBB35024D),0x03050500)

/**
 * <description>codemencrypt</description>
 */
typedef struct tagcodemencrypt_struct
{
	RTS_IEC_HANDLE hCodeMeter;			/* VAR_INPUT */	
	RTS_IEC_UDINT udiEncryptionCode;	/* VAR_INPUT */	
	RTS_IEC_BYTE *pbyData;				/* VAR_INPUT */	
	RTS_IEC_XWORD nDataLen;				/* VAR_INPUT */	
	RTS_IEC_UDINT *ulCRC;				/* VAR_IN_OUT */	
	RTS_IEC_RESULT CodeMEncrypt;		/* VAR_OUTPUT */	
} codemencrypt_struct;

DEF_API(`void',`CDECL',`codemencrypt',`(codemencrypt_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x33A9B633),0x03050500)

/**
 * <description>codemgetcontentbyfirmcode2</description>
 */
typedef struct tagcodemgetcontentbyfirmcode2_struct
{
	RTS_IEC_UDINT duiFirmcode;			/* VAR_INPUT */	
	RTS_IEC_UDINT duiProductcode;		/* VAR_INPUT */	
	RTS_CMBOXENTRY *licenseEntry;		/* VAR_IN_OUT */	
	RTS_IEC_RESULT CodeMGetContentByFirmcode2;	/* VAR_OUTPUT */	
} codemgetcontentbyfirmcode2_struct;

DEF_API(`void',`CDECL',`codemgetcontentbyfirmcode2',`(codemgetcontentbyfirmcode2_struct *p)',1,0xDCB38C4D,0x03050500)

/**
 * <description>codemgetexpirationtime</description>
 */
typedef struct tagcodemgetexpirationtime_struct
{
	RTS_IEC_HANDLE hCodeMeter;			/* VAR_INPUT */	
	RTS_IEC_DATE_AND_TIME *dtExpiration;	/* VAR_IN_OUT */	
	RTS_IEC_RESULT CodeMGetExpirationTime;	/* VAR_OUTPUT */	
} codemgetexpirationtime_struct;

DEF_API(`void',`CDECL',`codemgetexpirationtime',`(codemgetexpirationtime_struct *p)',1,0x9CC99260,0x03050500)

/**
 * <description>codemgetfirst</description>
 */
typedef struct tagcodemgetfirst_struct
{
	RTS_IEC_RESULT *Result;				/* VAR_IN_OUT */	
	RTS_IEC_HANDLE CodeMGetFirst;		/* VAR_OUTPUT */	
} codemgetfirst_struct;

DEF_API(`void',`CDECL',`codemgetfirst',`(codemgetfirst_struct *p)',1,0x0276119A,0x03050500)

/**
 * <description>codemgetinfo</description>
 */
typedef struct tagcodemgetinfo_struct
{
	RTS_IEC_HANDLE hCodeMeter;			/* VAR_INPUT */	
	RTS_CODEMETER_INFO *info;			/* VAR_IN_OUT */	
	RTS_IEC_RESULT CodeMGetInfo;		/* VAR_OUTPUT */	
} codemgetinfo_struct;

DEF_API(`void',`CDECL',`codemgetinfo',`(codemgetinfo_struct *p)',1,0x1CD05996,0x03050500)

/**
 * <description>codemgetname</description>
 */
typedef struct tagcodemgetname_struct
{
	RTS_IEC_HANDLE hCodeMeter;			/* VAR_INPUT */	
	RTS_IEC_WSTRING *wstName;			/* VAR_IN_OUT */	
	RTS_IEC_UDINT nLenBytes;			/* VAR_INPUT */	
	RTS_IEC_RESULT CodeMGetName;		/* VAR_OUTPUT */	
} codemgetname_struct;

DEF_API(`void',`CDECL',`codemgetname',`(codemgetname_struct *p)',1,0xC0E6AE1E,0x03050500)

/**
 * <description>codemgetnext</description>
 */
typedef struct tagcodemgetnext_struct
{
	RTS_IEC_HANDLE hPrevCodeMeter;		/* VAR_INPUT */	
	RTS_IEC_RESULT *Result;				/* VAR_IN_OUT */	
	RTS_IEC_HANDLE CodeMGetNext;		/* VAR_OUTPUT */	
} codemgetnext_struct;

DEF_API(`void',`CDECL',`codemgetnext',`(codemgetnext_struct *p)',1,0x1E179338,0x03050500)

/**
 * <description>codemgetquantity</description>
 */
typedef struct tagcodemgetquantity_struct
{
	RTS_IEC_HANDLE hCodeMeter;			/* VAR_INPUT */	
	RTS_IEC_UDINT *udiQuantity;			/* VAR_IN_OUT */	
	RTS_IEC_RESULT CodeMGetQuantity;	/* VAR_OUTPUT */	
} codemgetquantity_struct;

DEF_API(`void',`CDECL',`codemgetquantity',`(codemgetquantity_struct *p)',1,0x82616ACF,0x03050500)

/**
 * <description>codemgetunitcounter</description>
 */
typedef struct tagcodemgetunitcounter_struct
{
	RTS_IEC_HANDLE hCodeMeter;			/* VAR_INPUT */	
	RTS_IEC_UDINT *udiUnitCount;		/* VAR_IN_OUT */	
	RTS_IEC_RESULT CodeMGetUnitCounter;	/* VAR_OUTPUT */	
} codemgetunitcounter_struct;

DEF_API(`void',`CDECL',`codemgetunitcounter',`(codemgetunitcounter_struct *p)',1,0xEDA602B2,0x03050500)

/**
 * <description>codemopen</description>
 */
typedef struct tagcodemopen_struct
{
	RTS_IEC_UDINT udiFirmCode;			/* VAR_INPUT */	
	RTS_IEC_UDINT udiProductCode;		/* VAR_INPUT */	
	RTS_IEC_UDINT udiFeatureCode;		/* VAR_INPUT */	
	RTS_IEC_RESULT *Result;				/* VAR_IN_OUT */	
	RTS_IEC_HANDLE CodeMOpen;			/* VAR_OUTPUT */	
} codemopen_struct;

DEF_API(`void',`CDECL',`codemopen',`(codemopen_struct *p)',1,0x290D791C,0x03050500)

#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/


#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description>
 *	Open the first attached CodeMeter device
 * </description>
 * <param name="pResult" type="OUT">Pointer to error code:
 *   <ul>
 *     <li>ERR_OK: Device found</li>
 *     <li>ERR_NO_OBJECT: No device found</li>
 *   </ul>
 * </param>
 * <result>Returns a handle to the first CodeMeter device or RTS_INVALID_HANDLE if failed</result>
 */
DEF_ITF_API(`RTS_HANDLE',`CDECL',`CodeMGetFirst',`(RTS_RESULT *pResult)')

/**
 * <description>
 *	Open the next attached CodeMeter device
 * </description>
 * <param name="hPrevCodeMeter" type="IN">Handle of the previous device</param>
 * <param name="pResult" type="OUT">Pointer to error code:
 *   <ul>
 *     <li>ERR_OK: Device found</li>
 *     <li>ERR_NO_OBJECT: No device found</li>
 *     <li>ERR_PARAMETER: If handle is invalid</li>
 *   </ul>
 * </param>
 * <result>Returns a handle to the next CodeMeter device or RTS_INVALID_HANDLE if failed</result>
 */
DEF_ITF_API(`RTS_HANDLE',`CDECL',`CodeMGetNext',`(RTS_HANDLE hPrevCodeMeter, RTS_RESULT *pResult)')

/**
 * <description>
 *	Open the communication to a the CodeMeter device
 * </description>
 * <param name="ulFirmCode" type="IN">Firm code of the vendor</param>
 * <param name="ulProductCode" type="IN">Product code</param>
 * <param name="ulFeatureCode" type="IN">Feature code</param>
 * <param name="pResult" type="OUT">Pointer to error code:
 *   <ul>
 *     <li>ERR_OK: Device found</li>
 *     <li>ERR_NO_OBJECT: No device found</li>
 *     <li>ERR_PARAMETER: If one of the parameter is invalid</li>
 *   </ul>
 * </param>
 * <result>Handle to the CodeMeter device</result>
 */
DEF_ITF_API(`RTS_HANDLE',`CDECL',`CodeMOpen',`(RTS_UI32 ulFirmCode, RTS_UI32 ulProductCode, RTS_UI32 ulFeatureCode, RTS_RESULT *pResult)')

/**
 * <description>
 *	Close the communication to a the CodeMeter device
 * </description>
 * <param name="hCodeMeter" type="IN">Handle to the CodeMeter device</param>
 * <result>Error code:
 *   <ul>
 *     <li>ERR_OK: Successful</li>
 *     <li>ERR_PARAMETER: If handle is invalid</li>
 *   </ul>
 * </result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`CodeMClose',`(RTS_HANDLE hCodeMeter)')

/**
 * <description>
 *	Get information of the opened CodeMeter device
 * </description>
 * <param name="hCodeMeter" type="IN">Handle to the CodeMeter device</param>
 * <param name="pInfo" type="OUT">Pointer to get the information of a device</param>
 * <result>Error code:
 *   <ul>
 *     <li>ERR_OK: Successful</li>
 *     <li>ERR_PARAMETER: If handle is invalid</li>
 *   </ul>
 * </result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`CodeMGetInfo',`(RTS_HANDLE hCodeMeter, RTS_CODEMETER_INFO *pInfo)')

/**
 * <description>
 *	Get the expiration date
 * </description>
 * <param name="hCodeMeter" type="IN">Handle to the CodeMeter device</param>
 * <param name="ptExpirationTime" type="OUT">Pointer to get the expiration date</param>
 * <result>Error code:
 *   <ul>
 *     <li>ERR_OK: Successful</li>
 *     <li>ERR_PARAMETER: If one of the parameter is invalid</li>
 *   </ul>
 * </result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`CodeMGetExpirationTime',`(RTS_HANDLE hCodeMeter, RTS_UI32 *ptExpirationTime)')

/**
 * <description>
 *	Get the device name
 * </description>
 * <param name="hCodeMeter" type="IN">Handle to the CodeMeter device</param>
 * <param name="pwszName" type="OUT">Pointer to get the name of the device</param>
 * <param name="nLenBytes" type="IN">Maximum name length in bytes</param>
 * <result>Error code:
 *   <ul>
 *     <li>ERR_OK: Successful</li>
 *     <li>ERR_PARAMETER: If one of the parameter is invalid</li>
 *   </ul>
 * </result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`CodeMGetName',`(RTS_HANDLE hCodeMeter, RTS_WCHAR *pwszName, RTS_UI32 nLenBytes)')

/**
 * <description>
 *	Get the unit count
 * </description>
 * <param name="hCodeMeter" type="IN">Handle to the CodeMeter device</param>
 * <param name="pulUnitCount" type="OUT">Pointer to get the unit count</param>
 * <result>Error code:
 *   <ul>
 *     <li>ERR_OK: Successful</li>
 *     <li>ERR_PARAMETER: If one of the parameter is invalid</li>
 *   </ul>
 * </result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`CodeMGetUnitCounter',`(RTS_HANDLE hCodeMeter, RTS_UI32 *pulUnitCount)')

/**
 * <description>
 *	Function to encrypt data with the support of the CodeMeter device
 * </description>
 * <param name="hCodeMeter" type="IN">Handle to the CodeMeter device</param>
 * <param name="ulEncryptionCode" type="IN">Encryption code</param>
 * <param name="pulCRC" type="OUT">Return the CRC of the encrypted data</param>
 * <param name="pbyData" type="IN">Pointer to data to encrypt</param>
 * <param name="ulDataLen" type="IN">Length of data to encrypt</param>
 * <result>Error code:
 *   <ul>
 *     <li>ERR_OK: Successful</li>
 *     <li>ERR_PARAMETER: If one of the parameter is invalid</li>
 *   </ul>
 * </result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`CodeMEncrypt',`(RTS_HANDLE hCodeMeter, RTS_UI32 ulEncryptionCode, RTS_UI32 *pulCRC, RTS_UI8 *pbyData, RTS_SIZE ulDataLen)')

/**
 * <description>
 *	Function to decrypt data with the support of the CodeMeter device
 * </description>
 * <param name="hCodeMeter" type="IN">Handle to the CodeMeter device</param>
 * <param name="ulEncryptionCode" type="IN">Encryption code</param>
 * <param name="ulCRC" type="IN">CRC of the encrypted data</param>
 * <param name="pbyData" type="IN">Pointer to data to decrypt</param>
 * <param name="ulDataLen" type="IN">Length of data to decrypt</param>
 * <result>Error code:
 *   <ul>
 *     <li>ERR_OK: Successful</li>
 *     <li>ERR_PARAMETER: If one of the parameter is invalid</li>
 *   </ul>
 * </result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`CodeMDecrypt',`(RTS_HANDLE hCodeMeter, RTS_UI32 ulEncryptionCode, RTS_UI32 ulCRC, RTS_UI8 *pbyData, RTS_SIZE ulDataLen)')

/**
 * <description>
 *	Function to encrypt data without the support of the CodeMeter device
 * </description>
 * <param name="pKey" type="IN">Pointer to the key</param>
 * <param name="ulLeyLen" type="IN">Length of the key</param>
 * <param name="pbyData" type="IN">Pointer to data to encrypt</param>
 * <param name="ulDataLen" type="IN">Length of data to encrypt</param>
 * <result>Error code:
 *   <ul>
 *     <li>ERR_OK: Successful</li>
 *     <li>ERR_PARAMETER: If one of the parameter is invalid</li>
 *   </ul>
 * </result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`CodeMEncryptDirect',`(RTS_UI8 *pKey, RTS_UI32 ulLeyLen, RTS_UI8 *pbyData, RTS_UI32 ulDataLen)')

/**
 * <description>
 *	Function to decrypt data without the support of the CodeMeter device
 * </description>
 * <param name="pKey" type="IN">Pointer to the key</param>
 * <param name="ulLeyLen" type="IN">Length of the key</param>
 * <param name="pbyData" type="IN">Pointer to data to decrypt</param>
 * <param name="ulDataLen" type="IN">Length of data to decrypt</param>
 * <result>Error code:
 *   <ul>
 *     <li>ERR_OK: Successful</li>
 *     <li>ERR_PARAMETER: If one of the parameter is invalid</li>
 *   </ul>
 * </result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`CodeMDecryptDirect',`(RTS_UI8 *pKey, RTS_UI32 ulLeyLen, RTS_UI8 *pbyData, RTS_UI32 ulDataLen)')

/**
 * <description>
 *	Function to generate the export license file for the specified firm codes
 * </description>
 * <param name="containerSerialNumber" type="IN">Serial number of the specified container from which the context file should be retrieved</param>
 * <param name="paulFirmCodes" type="IN">Pointer to array of firm codes</param>
 * <param name="ulFirmCodes" type="IN">Number of firm codes in the array</param>
 * <param name="pszLicenseFile" type="IN">License file to store license information</param>
 * <result>Error code:
 *   <ul>
 *     <li>ERR_OK: Successful</li>
 *     <li>ERR_PARAMETER: If one of the parameter is invalid</li>
 *     <li>ERR_FAILED: License file could not be generated</li>
 *   </ul>
 * </result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`CodeMGenerateLicenseFile',`(RTS_UI32 ui32SerialNumber, RTS_UI32 *paulFirmCodes, RTS_UI32 ulFirmCodes, const char *pszLicenseFile)')

/**
 * <description>
 *	Function to write new licenses on the CodeMeter device
 * </description>
 * <param name="ui32SerialNumber" type="IN">Serial number of the adapter to write license file. 0 to write to any matching adapter.</param>
 * <param name="pszLicenseFile" type="IN">License file with new licenses</param>
 * <result>Error code:
 *   <ul>
 *     <li>ERR_OK: Successful</li>
 *     <li>ERR_PARAMETER: If one of the parameter is invalid</li>
 *     <li>ERR_FAILED: License file could not be written</li>
 *   </ul>
 * </result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`CodeMWriteLicenseFile',`(RTS_UI32 ui32SerialNumber, const char *pszLicenseFile)')

/**
 * <description>
 *	Function to read all licenses for a specific firm code. 
 * </description>
 * <param name="ulFirmcode" type="IN">Firm code to enumerate.</param>
 * <param name="paEntry" type="OUT">Array of RTS_CMBOXENTRY-structures to receive the box entries.</param>
 * <param name="pnEntries" type="IN OUT">Pointer to an initialized variable. Initial value is number of structs in paEntry.</param>
 * <result>Error code:
 *   <ul>
 *     <li>ERR_OK: Successful</li>
 *     <li>ERR_PARAMETER: License entry pointer is NULL</li>
 *     <li>ERR_NOT_SUPPORTED: License entry not found</li> 
 *     <li>ERR_NOBUFFER: Buffer is too small, check output of pnEntries for required number of structs in paEntry.</li> 
 *   </ul>
 * </result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`CodeMGetContentByFirmcode',`(RTS_UI32 ulFirmcode, RTS_CMBOXENTRY *paEntry, RTS_UI32 *pnEntries)')

/**
 * <description>
 *	Function to read a license entry specified by firm code and product code. 
 * </description>
 * <param name="ulFirmcode" type="IN">Firm code of the license entry</param>
 * <param name="ulProductcode" type="IN">Product code of the license entry</param>
 * <param name="paEntry" type="OUT">Pointer to RTS_CMBOXENTRY to get the license entry</param>
 * <result>Error code:
 *   <ul>
 *     <li>ERR_OK: Successful</li>
 *     <li>ERR_PARAMETER: License entry pointer is NULL</li>
 *     <li>ERR_NOT_SUPPORTED: License entry not found</li> 
 *   </ul>
 * </result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`CodeMGetContentByFirmcode2',`(RTS_UI32 ulFirmcode, RTS_UI32 ulProductcode, RTS_CMBOXENTRY *paEntry)')

/**
 * <description>
 *	Function to read a license entry specified by firm code and product code. 
 * </description>
 * <param name="ulFirmcode" type="IN">Firm code of the license entry</param>
 * <param name="ulProductcode" type="IN">Product code of the license entry</param>
 * <param name="bReleaseLicense" type="IN">
 *   <ul>
 *		<li>TRUE:	Release license so it can be used several from several instances</li>
 *		<li>FALSE:	Don't release license so it remains occupied and cannot be used by another instance!</li>
 *   </ul>
 * </param>
 * <param name="paEntry" type="OUT">Pointer to RTS_CMBOXENTRY to get the license entry</param>
 * <result>Error code:
 *   <ul>
 *     <li>ERR_OK: Successful</li>
 *     <li>ERR_PARAMETER: License entry pointer is NULL</li>
 *     <li>ERR_NOT_SUPPORTED: License entry not found or occupied by another instance!</li> 
 *   </ul>
 * </result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`CodeMGetContentByFirmcode3',`(RTS_UI32 ulFirmcode, RTS_UI32 ulProductcode, RTS_BOOL bReleaseLicense, RTS_CMBOXENTRY *paEntry)')

/**
 * <description>
 *	Function to read a license entry specified by firm code and product code from a network server. 
 * </description>
 * <param name="ulFirmcode" type="IN">Firm code of the license entry</param>
 * <param name="ulProductcode" type="IN">Product code of the license entry</param>
 * <param name="pszServer" type="IN">Server name or IP-Address (dotted string format)</param>
 * <param name="paEntry" type="OUT">Pointer to RTS_CMBOXENTRY to get the license entry</param>
 * <param name="bNoRelease" type="IN">Determines if the function calls CmRelease. 1= CmRelease not called.</param>
 * <param name="phEntry" type="IN">In case CmRelease is not called, the resulting entry handle is returned to the caller here.</param>
 * <result>Error code:
 *   <ul>
 *     <li>ERR_OK: Successful</li>
 *     <li>ERR_PARAMETER: License entry pointer is NULL</li>
 *     <li>ERR_NOT_SUPPORTED: License entry not found</li> 
 *   </ul>
 * </result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`CodeMGetContentByFirmcodeNet',`(RTS_UI32 ulFirmcode,RTS_UI32 ulProductcode, RTS_CMBOXENTRY *paEntry, char* pszServer, int bNoRelease, RTS_HANDLE* phEntry)')

#ifdef __cplusplus
}
#endif
