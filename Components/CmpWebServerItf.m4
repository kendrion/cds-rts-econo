/**
 * <interfacename>CmpWebServer</interfacename>
 * <description> 
 *	<p>Interface of the web server component.</p>
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`CmpWebServer')

REF_ITF(`SysSocketItf.m4')

#include "CmpStd.h"
#include "SysFileItf.h"
#include "CmpSecurityManagerItf.h"

/**
 * <description>WebServer Request Flags.</description>
 */
#define WEBSERVER_GET_REQUEST				0x00000001
#define WEBSERVER_POST_REQUEST				0x00000002
#define WEBSERVER_HEAD_REQUEST				0x00000004
#define WEBSERVER_ASP_REQUEST				0x00000008
#define WEBSERVER_KEEP_ALIVE				0x00000010
#define WEBSERVER_LICENSE_EXPIRED			0x00000020
#define WEBSERVER_IS_MODIFIED_SINCE			0x00000040

/* 
	Only evaluated internally within the web-server. In fact this is an optimization that allows sending 
	small content of POST requests in a BASE64 coded way within the HTTP-header. 
*/
#define WEBSERVER_HEADERONLYCONTENT			0x00000080		
/* 
	Special flag signals from the WebServer (or a Web-server-WebserverHandlerV3 adaptation) to a Handler-Component that the feature mentioned at
	WEBSERVER_HEADERONLYCONTENT is supported. 
	The intention of this feature is to evaluate the header field "3S-Repl-Content" as a base64 coded content replacement in POST-requests.
	If this header is evaluated correctly, then this flag should be set on all requests forwarded to the handler.
*/
#define WEBSERVER_SUPPORTSHEADERONLYCONTENT	0x00010000


/**
 * <description>WebServer Socket Flags.</description>
 */
#define WEBSERVER_SOCKET_BLOCK				0x00000001
#define WEBSERVER_SOCKET_LISTENING			0x00000002
#define WEBSERVER_SOCKET_READABLE			0x00000004
#define WEBSERVER_SOCKET_WRITEABLE			0x00000008
#define WEBSERVER_SOCKET_EXCEPTION			0x00000010
#define WEBSERVER_SOCKET_CONNRESET			0x00000020
#define WEBSERVER_SOCKET_EAGAIN				0x00000040
#define WEBSERVER_SOCKET_CLOSED				0x00000080
#define WEBSERVER_SOCKET_SENDCONTENT		0x00000100
#define WEBSERVER_SOCKET_READHEADER			0x00000200
#define WEBSERVER_SOCKET_READCONTENT		0x00000400

#define MAX_TYPE_LEN						64
#define MAX_TIME_LEN						64
#ifndef MAX_QUERY_LEN
	#define MAX_QUERY_LEN						255
#endif

typedef struct
{
	RTS_SSIZE		dwSize;					/* File size, we use SSIZE because this is the type we can send directly over sockets */
	RTS_IEC_DWORD	dwTime;					/* Modification time */
} WebServerResponseInfo;

/* 
 *	Per socket connection WebServer request structure
 */
typedef struct WebServerRequest {
	char szPath[MAX_PATH_LEN];
	char szTime[MAX_TIME_LEN];
	char szQuery[MAX_QUERY_LEN];
	void* pMemRequest;
	char* pHeaderBase64Content;		/* valid only if the flag WEBSERVER_HEADERONLYCONTENT is set within dwFlags */
	RTS_SSIZE iRequestMem;
	RTS_SSIZE iRequestRead;
	RTS_SSIZE iRequestLen;
	void* pMemResponse;
	RTS_BOOL bHasResponse;
	RTS_SSIZE iResponseLen;
	RTS_IEC_UDINT udiResponseLastModified;
	RTS_SSIZE iWritten;
	void* pMemRemain;				/* Keeps the remaining content of a file which cannot be sent because of socket E_WOULDBLOCK */
	RTS_SSIZE iRemainLen;
	RTS_UI32 dwFlags;
	RTS_HANDLE				pHandler;
	RTS_HANDLE				pFile;
} WebServerRequest;

typedef struct 
{
	char					pszHostName[64];
	RTS_HANDLE				hSocket;
	CLASSID					socketClassID;
	RTS_UI32				dwStartTime;	/* The start time is used to control timeouts for client requests */
	RTS_UI32				dwFlags;		/* The socket flags and what the socket can do at the moment */
	RTS_UI32				dwHandlerFlags; /* The handler flags keeps the information what the handler wants to do with this socket */
	WebServerRequest*		pRequest;
	RTS_RESULT				LastResult;
	char					szIpAddress[16];		/* holds the ip address of a connected client; might not be assigned for server sockets; at the moment only IPv4 supported */
} WebServerSocket;

/**
 * <description>WebServer memory type - which should be used.</description>
 */
typedef enum WEBSERVER_MEM_TYPEtag
{
	SYSMEM,
	SYSMEMREUSE
} WEBSERVER_MEM_TYPE;

/**
 * <description>WebServer connection type - which should be used</description>
 * <element name="HTTP_ONLY" type="IN">Only HTTP connections supported [DEFAULT]</element>
 * <element name="HTTPS_ONLY" type="IN">Only HTTPS connections supported</element>
 * <element name="HTTP_AND_HTTPS" type="IN">HTTP and HTTPS connections supported</element>
 * <element name="REDIRECT_HTTP_TO_HTTPS" type="IN"></element>
 */
typedef enum WEBSERVER_CONNECTION_TYPEtag
{
	HTTP_ONLY,
	HTTPS_ONLY,
	HTTP_AND_HTTPS,
	REDIRECT_HTTP_TO_HTTPS
} WEBSERVER_CONNECTION_TYPE;

/**
* <category>LogFilter masks</category>
* <description>Mask to filter debug outputs module or scope specific</description>
* <element name="LFM_WEBSERVER_COMMON" type="LogFilter">Shows messages of the log level 'info' (default). Mostly: file not found messages.</element>
* <element name="LFM_WEBSERVER_DEBUG" type="LogFilter">Shows messages of the log level 'debug'. All messages including not modified and successfully requested.</element>
*/

#define LFM_WEBSERVER_MASK                                  0x000000FF

#define LFM_WEBSERVER_COMMON								0x00000001
#define LFM_WEBSERVER_DEBUG									0x00000010

/**
 * <category>SecuritySettings</category>
 * <description>All security settings of the web-server. Can be selected in CmpSecurityManager.
 *	NOTE:
 *		Security modes must be ordered in an descending sorting, that the setting with the highest security level is found at the beginning of the list!
 * </description>
 * <element name="HTTPS_ONLY" type="IN">Only HTTPS connections supported</element>
 * <element name="REDIRECT_HTTP_TO_HTTPS" type="IN"></element>
 * <element name="HTTP_AND_HTTPS" type="IN">HTTP and HTTPS connections supported</element>
 * <element name="HTTP_ONLY" type="IN">Only HTTP connections supported [DEFAULT]</element>
 */
#define CMPWEBSERVER_KEY_STRING_COMM_MODE			CMPSETTINGS_CATEGORY_SECURITY ".CommunicationMode"
#define CMPWEBSERVER_KEY_STRING_COMM_MODE_DESC		"Communication mode of the web-server."

#define CMPWEBSERVER_VALUE_COMM_MODE_HTTPS			"HTTPS"
#define CMPWEBSERVER_VALUE_COMM_MODE_HTTP_TO_HTTPS	"REDIRECT_HTTP_TO_HTTPS"
#define CMPWEBSERVER_VALUE_COMM_MODE_HTTP_HTTPS		"HTTP, HTTPS"
#define CMPWEBSERVER_VALUE_COMM_MODE_HTTP			"HTTP"

#ifndef CMPWEBSERVER_VALUE_COMM_MODE_DEFAULT
	#define CMPWEBSERVER_VALUE_COMM_MODE_DEFAULT	CMPWEBSERVER_VALUE_COMM_MODE_HTTP_HTTPS
#endif

#define CMPWEBSERVER_VALUE_COMM_MODE_LIST			{ \
														{(RTS_UI32)HTTPS_ONLY, CMPSECMAN_SFLAGS_NONE, CMPWEBSERVER_VALUE_COMM_MODE_HTTPS, "Only HTTPS connections supported"},\
														{(RTS_UI32)REDIRECT_HTTP_TO_HTTPS, CMPSECMAN_SFLAGS_NONE, CMPWEBSERVER_VALUE_COMM_MODE_HTTP_TO_HTTPS, "Redirection of HTTP to HTTPS"},\
														{(RTS_UI32)HTTP_AND_HTTPS, CMPSECMAN_SFLAGS_NONE, CMPWEBSERVER_VALUE_COMM_MODE_HTTP_HTTPS, "HTTP and HTTPS connections supported"},\
														{(RTS_UI32)HTTP_ONLY, CMPSECMAN_SFLAGS_NONE, "HTTP", "Only HTTP connections supported"}\
													}


/**
 * <category>SecuritySettings</category>
 * <description>Security setting to specify, if a self-signed cert should be created by default if not available</description>
 */
#define CMPWEBSERVER_KEY_STRING_CREATE_SELFSIGNED_CERT				SECURITY_KEY_STRING_CREATE_SELFSIGNED_CERT
#define CMPWEBSERVER_KEY_STRING_CREATE_SELFSIGNED_CERT_DESC			SECURITY_KEY_STRING_CREATE_SELFSIGNED_CERT_DESC

#ifndef CMPWEBSERVER_VALUE_CREATE_SELFSIGNED_CERT_DEFAULT
	#define CMPWEBSERVER_VALUE_CREATE_SELFSIGNED_CERT_DEFAULT		SECURITY_VALUE_CREATE_SELFSIGNED_CERT_DEFAULT
#endif

#define CMPWEBSERVER_VALUE_CREATE_SELFSIGNED_CERT_LIST				SECURITY_VALUE_CREATE_SELFSIGNED_CERT_LIST

#ifndef MAX_LEN_APPLNAME
	#define MAX_LEN_APPLNAME			60
#endif


/**
 * <category>Settings</category>
 * <description>The web-server port number</description>
 */
#define CMPWEBSERVER_KEY_PORT								"WebServerPortNr"
#ifndef CMPWEBSERVER_VALUE_PORT_DEFAULT
	#define CMPWEBSERVER_VALUE_PORT_DEFAULT					INT32_C(8080)
#endif

/**
 * <category>Settings</category>
 * <description>The web-server port number for a secure SSL/TLS connection</description>
 */
#define CMPWEBSERVER_KEY_SECUREPORT							"WebServerSecurePortNr"
#ifndef CMPWEBSERVER_VALUE_SECUREPORT_DEFAULT
	#define CMPWEBSERVER_VALUE_SECUREPORT_DEFAULT			INT32_C(443)
#endif

/**
 * <category>Settings</category>
 * <description>Should the web-server open a SSL connection</description>
 */
#define CMPWEBSERVER_CONNECTION_TYPE						"ConnectionType"
#ifndef CMPWEBSERVER_CONNECTION_TYPE_DEFAULT
	#define CMPWEBSERVER_CONNECTION_TYPE_DEFAULT			HTTP_ONLY
#endif

/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>
 *	IP address to which the sockets of the web-server will be bound. If set to a valid IP address, only connection requests received on the
 *  related adapter are accepted by the server. If you want to bind to all addresses, omit all settings named "Local...".
 * </description>
 */
#define CMPWEBSERVER_KEY_LOCALADDRESS						"LocalAddress"
#define CMPWEBSERVER_VALUE_LOCALADDRESS_DEFAULT				""

/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>URL of the web-server. This URL will be used for the certificate as common name if HTTPS is activated. If this setting is empty the host-name of the PLC will be used.</description>
 */
#define CMPWEBSERVER_KEY_URL						        "URL"
#ifndef CMPWEBSERVER_VALUE_URL_DEFAULT
    #define CMPWEBSERVER_VALUE_URL_DEFAULT				""
#endif

/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>
 *	Name of the network adapter to which the sockets of the web-server will be bound. If set to a valid name, only connection requests received on the
 *  related adapter are accepted by the server. If there is a configuration for "LocalAddress" or "LocalAdapterNameUnicode", this setting will be ignored.
 *	If you want to bind to all addresses, omit all settings named "Local...".
 * </description>
 */
#define CMPWEBSERVER_KEY_LOCALADAPTERNAME					"LocalAdapterName"
#define CMPWEBSERVER_VALUE_LOCALADAPTERNAME_DEFAULT			""

/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>
 *	Name of the network adapter to which the sockets of the web-server will be bound as a UNICODE String. If set to a valid name, only connection requests received on the
 *  related adapter are accepted by the server. If there is a configuration for "LocalAddress", this setting will be ignored.
 *	If you want to bind to all addresses, omit all settings named "Local...".
 * </description>
 */
#define CMPWEBSERVER_KEY_LOCALADAPTERNAMEUNICODE			"LocalAdapterNameUnicode"
#define CMPWEBSERVER_VALUE_LOCALADAPTERNAMEUNICODE_DEFAULT	RTS_WTEXT("")

/**
 * <category>Memory type</category>
 * <description>The web-server memory type which should be used for dynamic memory allocation.</description>
 */
#define CMPWEBSERVER_MEMORY_TYPE							"WebServerMemoryType"
#define CMPWEBSERVER_MEMORY_TYPE_DEFAULT					SYSMEMREUSE

/**
 * <category>Settings</category>
 * <description>The path to the web visualization directory</description>
 */
#define CMPWEBSERVER_KEY_FILE_UPLOAD_DIR					"FileUploadDirectory"

/**
 * <category>Settings</category>
 * <description>The task interval of the web-server task</description>
 */
#define CMPWEBSERVER_KEY_TASKINTERVAL						"TaskInterval"
#define CMPWEBSERVER_VALUE_TASKINTERVAL_DEFAULT				20

/**
 * <category>Settings</category>
 * <description>The timeout for the socket select call.</description>
 */
#define CMPWEBSERVER_KEY_SELECT_TIMEOUT						"SelectTimeout"
#define CMPWEBSERVER_VALUE_SELECT_TIMEOUT_DEFAULT			0

/**
 * <category>Settings</category>
 * <description>The task priority of the web-server task</description>
 */
#define CMPWEBSERVER_KEY_TASKPRIORITY						"TaskPriority"
#define CMPWEBSERVER_VALUE_TASKPRIORITY_DEFAULT				80

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>The startup mechanism used by the web-server. The following values are valid:
	0: The web-server will startup automatically and never shutdown
	1: The web-server will startup automatically with a reference count of 1 that means it can be shutdown by a 
		call to WebServerReleaseRunning
	2: The web-server will startup and shutdown on demand using a reference counting mechanism</description>
	3: The web-server will startup on demand but never shutdown
 */
#define CMPWEBSERVER_KEY_STARTUPTYPE						"StartupType"
#ifndef CMPWEBSERVER_VALUE_STARTUPTYPE_DEFAULT 
	#define CMPWEBSERVER_VALUE_STARTUPTYPE_DEFAULT			2
#endif


/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>
 * Setting that allows to define additional mime types for additional file extensions. Default mime type file extension pairs
 * can be overwritten if they are redefined. The pairs must be indexed, multiple pairs can be defined.
 * Example for adding the mime types file extension pairs application/postscript for .ps and application/zip for .zip:
 * AdditionalFileExtension.0=.ps
 * AdditionalMimeType.0=application/postscript
 * AdditionalFileExtension.1=.zip
 * AdditionalMimeType.1=application/zip
 * </description>
 */
#define CMPWEBSERVER_ADDITIONAL_FILE_EXTENSION				"AdditionalFileExtension"
#define	CMPWEBSERVER_ADDITIONAL_MIME_TYPE					"AdditionalMimeType"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description> V3 web server dynamic memory management. Attention use this API instead of SysMemAllocData. </description>
 * <param name="ulSize">The web-server request</param>
 * <result>The pointer to the dynamic memory</result>
 */
DEF_API(`void*', `CDECL', `WebServerGetDynamicMem', `(RTS_SIZE ulSize)')

/**
 * <description> V3 web server dynamic memory management. Attention use this API instead of SysMemFreeData. </description>
 * <param name="pMem">The pointer to the dynamic memory</param>
 */
DEF_API(`void', `CDECL', `WebServerFreeDynamicMem', `(void* pMem)')

/**
 * <description> V3 web server startup and shutdown. This function can be called to start the web-server, i.e. start listening on the
 *	configured TCP-Port. To allow multiple callers to use this API, the implementation uses a reference counting mechanism.
 *	That means that a caller that requests a start of the web-server using this function should release it using WebServerReleaseRunning
 *	when it is no longer necessary.
 *	A call to this method should not be done before the hook CH_INIT_TASKS</description>
 * <errorcode name="RTS_RESULT" type="ERR_OK">The web-server was started.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_DUPLICATE">The web-server was already running so only the reference counter was incremented.</errorcode>
 * <result></result>
 */
DEF_API(`RTS_RESULT', `CDECL', `WebServerRequestRunning', `(void)')

/**
 * <description> V3 web server startup and shutdown. This function can be called to shutdown the web-server, i.e. stop listening on the
 *	configured TCP-Port. To allow multiple callers to use this API, the implementation uses a reference counting mechanism.
 *	That means that a caller of this method should have called WebServerRequestRunning before.</description>
 * <errorcode name="RTS_RESULT" type="ERR_OK">The web-server was shutdown.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_DUPLICATE">The reference counter was correctly reduced and the web-server is still running.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">The reference counter would become negative and thus the web-server was already shutdown.</errorcode>
 * <result></result>
 */
DEF_API(`RTS_RESULT', `CDECL', `WebServerReleaseRunning', `(void)')

/**
 * <description> Sets the HTM file name to use. </description>
  * <param name="pszFileName" type="IN"> contains the HTM file name </param>
 */
DEF_API(`void', `CDECL', `WebServerSetDefaultPage', `(char* pszFileName)')

#ifdef __cplusplus
}
#endif

