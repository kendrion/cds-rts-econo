/**
 * <interfacename>CmpSecurityManager</interfacename>
 * <description>
 *	The security manager interface is used to specify the level of all available security features in one central component.
 *	Additionally the X.509 certificates for servers in the runtime system can be specified here.
 *
 *	The actual available security features (for which the level can be specified) are:
 *		1. Programming system communication: encrypted / unencrypted
 *		2. IEC application code and bootproject: signed / unsigned, encrypted / unencrypted 
 *		3. WebServer: http / https
 *
 *	NOTE:
 *		This list will be extended in the future, if new security features are available and the corresponding security level must be specified!
 *
 *  SECURITY-NOTE:
 *		The security manager must be linked statically to the runtime system core to prevent, that it cannot be removed or replaced by a malware!
 *
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2018 CODESYS GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`CmpSecurityManager')

#include "CmpStd.h"
REF_ITF(`CmpX509CertItf.m4')
REF_ITF(`CmpSettingsItf.m4')

#ifdef CMPSECURITYMANAGER_EXTERNAL
	#error CmpSecurityManager must not be overloadable so defining CMPSECURITYMANAGER_EXTERNAL is forbidden because of security requirements!
#endif

/**
 * <category>Compiler switch</category>
 * <description>
 *	Compiler switches to enable/disable single features in the component.
 * </description>
 * <element name="CMPSECURITYMANAGER_SET_SECURITY_LEVEL_MAXIMUM">Set security level to maximum for all available security features!</element>
 */

 /**
 * <category>Static defines</category>
 * <description>Number of static security settings to store</description>
 */
#ifndef RTS_SECMAN_NUMOF_STATIC_SETTINGS
	#define RTS_SECMAN_NUMOF_STATIC_SETTINGS			10
#endif


/**
 * <category>Event parameter</category>
 * <element name="reserved" type="IN">Not used yet.</element>
 */
typedef struct
{
	RTS_UI8 reserved;
} EVTPARAM_CmpSecMan_ConfigChanged;
#define EVTPARAMID_CmpSecMan_ConfigChanged				0x0001
#define EVTVERSION_CmpSecMan_ConfigChanged				0x0001

/**
 * <category>Events</category>
 * <description>Event is sent before start of the specified application</description>
 * <param name="pEventParam" type="IN">EVTPARAM_CmpSecMan_ConfigChanged</param>
 */
#define EVT_CmpSecMan_ConfigurationChanged				MAKE_EVENTID(EVTCLASS_INFO, 1)

/**
 * <category>SecuritySettingFlags</category>
 * <description>
 *	Flags/options for a security setting
 * </description>
 */
#define CMPSECMAN_FLAGS_NONE							0
#define CMPSECMAN_FLAGS_SELECTABLE						CMPSETTINGS_FLAGS_SELECTABLE
#define CMPSECMAN_FLAGS_EDITABLE						CMPSETTINGS_FLAGS_EDITABLE
#define CMPSECMAN_FLAGS_SETTING_FROM_FILE				0x00000010


/**
 * <description>
 *	Entry of one security feature to be managed by the CmpSecurityManager.
 * </description>
 * <element name="pszKey" type="IN">Name of the security key/feature</element>
 * <element name="pszDescription" type="IN">Description of the security entry/feature</element>
 * <element name="pszDescription" type="IN">Description of the security entry/feature</element>
 * <element name="cmpId" type="IN">ComponentID of the component that provides security features</element>
 * <element name="flags" type="IN">Flags of the entry. See "SecuritySettingFlags" for details.</element>
 */
typedef struct _SecuritySetting
{
	const char *pszKey;
	const char *pszDescription;
	CMPID cmpId;
	RTS_UI32 flags;
} SecuritySetting;

/**
 * <category>SecuritySelectableFlags</category>
 * <description>
 *	Flags/options for a security selectable setting
 * </description>
 */
#define CMPSECMAN_SFLAGS_NONE					CMPSECMAN_FLAGS_NONE

/**
 * <description>
 *	This structure stores a single entry of a selectable setting. Each 
 *  possible selection is a single struture element when registering the setting.
 *  The registration can be done using SecManRegisterSelectableSetting function. The 
 *  selected setting can be retrieved by using SecManGetSelectableSetting.
 * </description>
 * <element name="secID" type="IN">ID of the selectable setting. Must be unique within this set of selectable settings!</element>
 * <element name="flags" type="IN">Flags of the entry. See "SecuritySettingFlags" for details.</element>
 * <element name="pszValue" type="IN">Value of the security setting</element>
 * <element name="pszDescription" type="IN">Description of the security setting</element>
 */
typedef struct _SecuritySelectableSetting
{
	RTS_I32 secID;
	RTS_UI32 flags;
	char *pszValue;
	char *pszDescription;
} SecuritySelectableSetting;

/**
 * <description>
 *	Union to store an editable integer, string or wstring value. Value can be specified in the security manager.
 * </description>
 * <element name="pStringSetting" type="IN">String value UTF8</element>
 * <element name="pWStringSetting" type="IN">String value UTF16</element>
 * <element name="intSetting" type="IN">Integer value</element>
 */
typedef union _SecuritySettingValue
{
    RTS_CSTRING *pStringSetting;
	RTS_WCHAR *pWStringSetting;
    RTS_I32 intSetting;
} SecuritySettingValue;

/**
 * <category>SecurityEditableFlags</category>
 * <description>
 *	Flags/options for a security editable setting
 * </description>
 */
#define CMPSECMAN_EFLAGS_EDITABLE_STRING			CMPSETTINGS_EFLAGS_EDITABLE_STRING
#define CMPSECMAN_EFLAGS_EDITABLE_INT				CMPSETTINGS_EFLAGS_EDITABLE_INT

/**
 * <description>
 *	This structure stores a editable setting. The setting can be registerd using
 *  SecManRegisterEditableSetting function. The default value given when registring
 *  will be returned until the setting has been changed by the someone. Then the
 *  changed value will be returned. To indicate if a string or an intager is stored
 *  use either CMPSECMAN_FLAGS_STRINGSETTING or CMPSECMAN_FLAGS_INTSETTING. The
 *  corresponding field in the secValue union is then used.
 *  Use the function SecManGetEditableSetting to retrieve the valued stored.
 * </description>
 * <element name="flags" type="IN">Flags of the entry. See "SecurityEditableFlags" for details.</element>
 * <element name="secValue" type="IN">Editable value</element>
 */
typedef struct _SecurityEditableSetting
{
	RTS_UI32 flags;
	SecuritySettingValue secValue;
} SecurityEditableSetting;


/**
 * <category>SecuritySettings</category>
 * <description>Security setting to specify, if a selfsigned certificate should be created during startup if not available</description>
 */
#define SECURITY_KEY_STRING_CREATE_SELFSIGNED_CERT			CMPSETTINGS_CATEGORY_SECURITY ".CreateSelfSignedCert"
#define SECURITY_KEY_STRING_CREATE_SELFSIGNED_CERT_DESC		"Specifies if self signed certificate should automatically be created during startup!"

#define SECURITY_VALUE_CREATE_SELFSIGNED_CERT_YES			"YES"
#define SECURITY_VALUE_CREATE_SELFSIGNED_CERT_NO			"NO"

#ifndef SECURITY_VALUE_CREATE_SELFSIGNED_CERT_DEFAULT
	#define SECURITY_VALUE_CREATE_SELFSIGNED_CERT_DEFAULT	SECURITY_VALUE_CREATE_SELFSIGNED_CERT_NO
#endif

/**
 * <description>SecurityIDs</description>
 * <element name="CREATE_SELFSIGNED_CERT_ENABLE" type="IN">Create a selfsigned certificate at startup</element>
 * <element name="CREATE_SELFSIGNED_CERT_DISABLE" type="IN">Don't create a selfsigned certificate at startup</element>
 */
typedef enum
{
	CREATE_SELFSIGNED_CERT_YES,
	CREATE_SELFSIGNED_CERT_NO
} SECURITY_CREATESELFSIGNEDCERT_IDS;

#define SECURITY_VALUE_CREATE_SELFSIGNED_CERT_LIST			{\
																{(RTS_I32)CREATE_SELFSIGNED_CERT_YES, CMPSECMAN_SFLAGS_NONE, SECURITY_VALUE_CREATE_SELFSIGNED_CERT_YES, "Create a selfsigned cert"},\
																{(RTS_I32)CREATE_SELFSIGNED_CERT_NO, CMPSECMAN_SFLAGS_NONE, SECURITY_VALUE_CREATE_SELFSIGNED_CERT_NO, "Don't create a selfsigned cert"}\
															}


/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>
 *	With this setting you can configure, if all certificates and parameter should be created automatically at startup, if a registered certificate 
 *	is not available.
 * </description>
 */
#define SECURITYMANAGER_KEY_INT_CREATE_ALL_ON_STARTUP					"CreateAllOnStartup"
#ifndef SECURITYMANAGER_VALUE_INT_CREATE_ALL_ON_STARTUP_DEFAULT
	#define SECURITYMANAGER_VALUE_INT_CREATE_ALL_ON_STARTUP_DEFAULT		0
#endif


/**
 * <category>Online services</category>
 * <description>
 *	Online service to read all security setting.
 * </description>
 * <servicegroup name="SG_SECURITY_MANAGER">0x0023</servicegroup>
 * <service name="SRV_SECMAN_READ_SETTINGS">
 *	<Request>
 *		<No further tag>
 *	</Request>
 *	<Response>
 *		<tag[] name="TAGNEST_SECURITY_ENTRY" required="mandatory">Complex tag</tag>
 *			<tag name="TAGNEST_SECURITY_ENTRY_INFO" required="mandatory">Complex tag</tag>
 *				<tag name="TAG_SECURITY_COMPONENT_ID" required="mandatory">[RTS_UI32]: TODO</tag>
 *				<tag name="TAG_SECURITY_ID" required="mandatory">[RTS_UI32]: TODO</tag>
 *				<tag name="TAG_SECURITY_NAME" required="mandatory">[RTS_CSTRING::UTF-8]: TODO</tag>
 *				<tag name="TAG_SECURITY_DESCRIPTION" required="optional">[RTS_CSTRING::UTF-8]: TODO</tag>
 *				<tag name="TAG_SECURITY_FLAGS" required="mandatory">[RTS_UI32]: TODO</tag>
 *				<tag name="TAG_SECURITY_SETTING_ID_SELECTED" required="optional">[RTS_UI32]: TODO</tag>
 *				<tag name="TAG_SECURITY_NUM_OF_SETTINGS" required="mandatory">[RTS_UI32]: TODO</tag>
 *
 *			<alternate tag[] name="TAGNEST_SECURITY_SETTING_SELECTABLE" required="optional">Complex tag</tag>
 *				<tag name="TAG_SECURITY_SETTING_ID" required="mandatory">[RTS_UI32]: TODO</tag>
 *				<tag name="TAG_SECURITY_SETTING_FLAGS" required="mandatory">[RTS_UI32]: TODO</tag>
 *				<tag name="TAG_SECURITY_SETTING_NAME" required="mandatory">[RTS_CSTRING::UTF-8]: TODO</tag>
 *				<tag name="TAG_SECURITY_SETTING_DESCRIPTION" required="optional">[RTS_CSTRING::UTF-8]: TODO</tag>
 *
 *			<alternate tag name="TAGNEST_SECURITY_SETTING_EDITABLE" required="optional">Complex tag</tag>
 *				<tag name="TAG_SECURITY_SETTING_FLAGS" required="mandatory">[RTS_UI32]: TODO</tag>
 *				<tag name="TAG_SECURITY_SETTING_NAME" required="optional">[RTS_CSTRING::UTF-8]: TODO</tag>
 *				<tag name="TAG_SECURITY_SETTING_DESCRIPTION" required="optional">[RTS_CSTRING::UTF-8]: TODO</tag>
 *				<tag name="TAG_SECURITY_SETTING_VALUE_INT" required="optional">[RTS_I32]: TODO</tag>
 *				<tag name="TAG_SECURITY_SETTING_DEFAULTVALUE_INT" required="optional">[RTS_I32]: TODO</tag>
 *				<tag name="TAG_SECURITY_SETTING_VALUE_STRING" required="optional">[RTS_CSTRING::UTF-8]: TODO</tag>
 *				<tag name="TAG_SECURITY_SETTING_DEFAULTVALUE_STRING" required="optional">[RTS_CSTRING::UTF-8]: TODO</tag>
 *
 *		<tag name="TAG_ERROR" required="mandatory">[RTS_I16]: Result code of the complete operation</tag>
 *	</Response>
 * </service>
 */
#define SRV_SECMAN_READ_SETTINGS						0x01

#define TAGNEST_SECURITY_ENTRY							0x81
#define TAGNEST_SECURITY_ENTRY_INFO						0x82
#define TAG_RESULT										0x01
#define TAG_SECURITY_COMPONENT_ID						0x10
#define TAG_SECURITY_ID									0x11
#define TAG_SECURITY_NAME								0x12
#define TAG_SECURITY_DESCRIPTION						0x13
#define TAG_SECURITY_FLAGS								0x14
#define TAG_SECURITY_SETTING_ID_SELECTED				0x15
#define TAG_SECURITY_NUM_OF_SETTINGS					0x16

#define TAGNEST_SECURITY_SETTING_SELECTABLE				0x83
#define TAG_SECURITY_SETTING_ID							0x20
#define TAG_SECURITY_SETTING_FLAGS						0x21
#define TAG_SECURITY_SETTING_NAME						0x22
#define TAG_SECURITY_SETTING_DESCRIPTION				0x23

#define TAGNEST_SECURITY_SETTING_EDITABLE				0x84
#define TAG_SECURITY_SETTING_VALUE_INT					0x30
#define TAG_SECURITY_SETTING_DEFAULTVALUE_INT			0x31
#define TAG_SECURITY_SETTING_VALUE_STRING				0x32
#define TAG_SECURITY_SETTING_DEFAULTVALUE_STRING		0x33

/**
 * <category>Online services</category>
 * <description>
 *	Online service to write changed security settings.
 * </description>
 * <servicegroup name="SG_SECURITY_MANAGER">0x0023</servicegroup>
 * <service name="SRV_SECMAN_WRITE_SETTINGS">
 *	<Request>
 *		<No further tag>
 *	</Request>
 *	<Response>
 *		<tag[] name="TAGNEST_SECURITY_ENTRY" required="mandatory">Complex tag</tag>
 *			<tag name="TAGNEST_SECURITY_ENTRY_INFO" required="mandatory">Complex tag</tag>
 *				<tag name="TAG_SECURITY_COMPONENT_ID" required="mandatory">[RTS_UI32]: TODO</tag>
 *				<tag name="TAG_SECURITY_ID" required="mandatory">[RTS_UI32]: TODO</tag>
 *				<tag name="TAG_SECURITY_SETTING_ID_SELECTED" required="optional">[RTS_UI32]: Is only sent, if it is a selectable setting!</tag>
 *
 *			<tag name="TAGNEST_SECMAN_SETTING_EDITABLE" required="optional">Complex tag</tag>
 *				<tag name="TAG_SECURITY_SETTING_VALUE_INT" required="optional">[RTS_I32]: TODO</tag>
 *				<tag name="TAG_SECURITY_SETTING_VALUE_STRING" required="optional">[RTS_CSTRING::UTF-8]: TODO</tag>
 *
 *			<tag name="TAG_ERROR" required="mandatory">[RTS_I16]: Result code of each write operation</tag>
 *	</Response>
 * </service>
 */
#define SRV_SECMAN_WRITE_SETTINGS							0x02


#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description>Function to register one security setting of a component.</description>
 * <param name="pEntry" type="IN">Pointer to description structure of the security setting</param>
 * <param name="pSettings" type="IN">Pointer to the security settings list</param>
 * <param name="ui32Settings" type="IN">Number of security settings in the list</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT pResult" type="ERR_OK">Settings could be registered</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_NOTINITIALIZED">CmpSecurityManager is not yet initialized</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_NO_MEMORY">No memory to register security settings</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_DUPLICATE">The setting was registered already. The handle of the existing is returned.</errorcode>
 * <result>Handle to the registered security settings</result>
 */
DEF_ITF_API(`RTS_HANDLE',`CDECL',`SecManRegisterSelectableSetting',`(CMPID cmpId, const char *pszKey, const char *pszDescription, const char *pszDefaultSecName, const SecuritySelectableSetting *pList, RTS_UI32 ui32Settings, RTS_RESULT *pResult)')

/**
 * <description>Function to register one security setting of a component.</description>
 * <param name="pEntry" type="IN">Pointer to description structure of the security setting</param>
 * <param name="pSetting" type="IN">Pointer to the editable security settings</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT pResult" type="ERR_OK">Settings could be registered</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_NOTINITIALIZED">CmpSecurityManager is not yet initialized</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_NO_MEMORY">No memory to register security settings</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_DUPLICATE">The setting was registered already. The handle of the existing is returned.</errorcode>
 * <result>Handle to the registered security settings</result>
 */
DEF_ITF_API(`RTS_HANDLE',`CDECL',`SecManRegisterEditableSetting',`(CMPID cmpId, const char *pszKey, const char *pszDescription, SecurityEditableSetting setting, RTS_RESULT *pResult)')

/**
 * <description>Unregister security setting</description>
 * <param name="hSecuritySetting" type="IN">Handle to the security settings returned by SecManRegisterSelectableSetting() or SecManFindSettings() or SecManRegisterEditableSetting()</param>
 * <result>Result of the operation</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Unregister succeeded</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">hSecuritySetting invalid</errorcode>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SecManUnregisterSetting',`(RTS_HANDLE hSecuritySetting)')

/**
 * <description>Find settings specified by componentID and usageID</description>
 * <param name="cmpId" type="IN">ComponentID of the server that provides security features</param>
 * <param name="pszKey" type="IN">Name of the setting</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT pResult" type="ERR_OK">Settings could be found</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_NOTINITIALIZED">CmpSecurityManager is not yet initialized</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_NO_OBJECT">No settings registered</errorcode>
 * <result>Handle to the registered security settings</result>
 */
DEF_ITF_API(`RTS_HANDLE',`CDECL',`SecManFindSetting',`(CMPID cmpId, const char *pszKey, RTS_RESULT *pResult)')

/**
 * <description>Get the selected setting because of the security policy of the target!</description>
 * <param name="hSecuritySetting" type="IN">Handle to the security settings returned by SecManRegisterSelectableSetting() or SecManFindSettings()</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT pResult" type="ERR_OK">One setting is returned</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_PARAMETER">hSecuritySetting is invalid</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_NO_OBJECT">No setting selected</errorcode>
 * <result>Pointer to the security setting which is selected on the target</result>
 */
DEF_ITF_API(`const SecuritySelectableSetting *',`CDECL',`SecManGetSelectableSetting',`(RTS_HANDLE hSecuritySetting, RTS_RESULT *pResult)')

/**
 * <description>Get the edited value setting because of the security policy of the target!</description>
 * <param name="hSecuritySetting" type="IN">Handle to the security settings returned by SecManRegisterSelectableSetting() or SecManFindSettings()</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT pResult" type="ERR_OK">One setting is returned</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_PARAMETER">hSecuritySetting is invalid</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_NO_OBJECT">No setting selected</errorcode>
 * <result>Pointer to the security setting which is selected on the target</result>
 */
DEF_ITF_API(`SecurityEditableSetting *',`CDECL',`SecManGetEditableSetting',`(RTS_HANDLE hSecuritySetting, RTS_RESULT *pResult)')

/**
 * <description>Function to overload the certificate info from a specified server resp. for a usage</description>
 * <param name="cmpId" type="IN">ComponentID of the server that provides security features</param>
 * <param name="pCertInfo" type="IN">Pointer to the preinitialized certificate info</param>
 * <result>Result of the operation</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Certificate info was overloaded</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTIMPLEMENTED">No overload done</errorcode>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SecManFillCertificateInfo',`(CMPID cmpId, RtsX509CertInfo *pCertInfo)')

/**
 * <description>This function checks a TLS context that is created via TlsCreateContext() resp. TlsCreateContext2(). Here the TlsMethod, CipherList and VerifyMethod
 * can be checked against own security policy!
 *
 * NOTE:
 *	This is only a callback function from the implementation of the CmpTlsItf! So don't us it directly!
 * </description>
 * <param name="ui32TlsMethod" type="IN">Mode of the TLS connections. See: TLS_METHOD_... macros</param>
 * <param name="szCipherList" type="IN">Cipher selection of the TLS connection. See CipherList setting for details. If NULL the default of the setting will be used.</param>
 * <param name="i32VerifyMode" type="IN">Verify mode of the TLS connection. See: TLS_VERIFY... macros. Default server: NONE; Default client: VERIFY_PEER.</param>
 * <result>Result of the operation</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">All context settings are complying the security policy</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">At least one context setting is not complying the security policy!</errorcode>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SecManCheckTlsContext',`(RTS_UI32 ui32TlsMethod, char* pszCipherList, RTS_I32 i32VerifyMode)')

#ifdef __cplusplus
}
#endif
