/**
 * <interfacename>CmpSessionInformation</interfacename>
 *
 * <description> 
 *	 
 *	<p>Interface of the session information management. In order to store and handle information about the connected clients,
 *	the session information is collected during the login process. It is used as part of the client identification management
 *	to identify all connected clients with corresponding information.</p>	 
 *	
 * </description>
 *
 * <copyright>
 * Copyright (c) 2019-2020 CODESYS Development GmbH. All rights reserved.
 * </copyright>
 */
 
 /* Change the default char type from signed char to unsigned char */
 #define _CHAR_UNSIGNED

SET_INTERFACE_NAME(`CmpSessionInformation')

#include "CmpItf.h"

/**
 * <category>String Memory Sizes</category>
 * <description>Number of bytes of stings including the \0 terminator.</description>
 * <element name="SESS_INFO_MEMSIZE_USER_NAME">Memory size of the string for the user logged in on the session.</element>
 * <element name="SESS_INFO_MEMSIZE_CLIENT_NAME">Memory size of the string for the name of the client application that created that session.</element>
 * <element name="SESS_INFO_MEMSIZE_CLIENT_VENDOR_NAME">Memory size of the string for the name of the client application's vendor.</element>
 * <element name="SESS_INFO_MEMSIZE_CLIENT_HOST_NAME">Memory size of the string for the host name where client is running.</element>
 * <element name="SESS_INFO_MEMSIZE_CLIENT_VERSION">Memory size of the string for the client version.</element>
 * <element name="SESS_INFO_MEMSIZE_CLIENT_CDS_VERSION">Memory size of the string for the CODESYS version the client is based on.</element>
 */
#define SESS_INFO_MEMSIZE_USER_NAME					UINT16_C(64)
#define SESS_INFO_MEMSIZE_CLIENT_NAME				UINT16_C(256)
#define SESS_INFO_MEMSIZE_CLIENT_VENDOR_NAME		UINT16_C(256)
#define SESS_INFO_MEMSIZE_CLIENT_HOST_NAME			UINT16_C(256)
#define SESS_INFO_MEMSIZE_CLIENT_VERSION			UINT16_C(256)
#define SESS_INFO_MEMSIZE_CLIENT_CDS_VERSION		UINT16_C(256)

/**
 * <category>Client types</category>
 * <description>These are different types of clients that can be connected to a Runtime system.</description>
 * <element name="SESS_INFO_CLIENT_TYPE_NO_INFO">This is an old fashioned client that does not provide any useful information.</element>
 * <element name="SESS_INFO_CLIENT_TYPE_PROGRAMMING_SYSTEM">This client is used to program the PLC.</element>
 * <element name="SESS_INFO_CLIENT_TYPE_PROG_SYSTEM_VIA_CAS">Programming System connected via CODESYS Automation Server.</element>
 * <element name="SESS_INFO_CLIENT_TYPE_OPCUA_CLIENT">This is OPC UA client connected to the PLC.</element>
 * <element name="SESS_INFO_CLIENT_TYPE_WEBVISU">Web visu - CODESYS HMI for web browser.</element>
 * <element name="SESS_INFO_CLIENT_TYPE_REMOTE_TARGET_VISU">This is remote target visu connected to the PLC.</element>
 * <element name="SESS_INFO_CLIENT_TYPE_DATA_SOURCES">Datasources using the ChannelClient for PLC communication.</element>
 * <element name="SESS_INFO_CLIENT_TYPE_DATA_SERVER">Legacy Dataserver or other client based on PlcServices.library.</element>
 * <element name="SESS_INFO_CLIENT_TYPE_PLCHANDLER">This is a unspecific PLCHandler based client, most likely a customer product.</element>
 * <element name="SESS_INFO_CLIENT_TYPE_PLCH_OPC">CODESY OPC Server V3 based on the PLCHandler.</element>
 * <element name="SESS_INFO_CLIENT_TYPE_PLCH_EDGE">CODESYS Edge Gateway based on PLCHandler.</element>
 * <element name="SESS_INFO_CLIENT_TYPE_PLCH_DATA_SOURCES">Datasources using PLCHandler for PLC communication.</element>
 * <element name="SESS_INFO_CLIENT_TYPE_PLCH_IECVARACC_BROWSE">CODESYS IecVarAccessClient based on PLCHandler.</element>
 * <element name="SESS_INFO_CLIENT_TYPE_LEGACY_PROGRAMMING_SYSTEM">Probably CODESYS before version V3.5.16.0.</element>
 * <element name="SESS_INFO_CLIENT_TYPE_LEGACY_WEBVISU">Probably WebVisualization before version V3.5.16.0.</element>
 * <element name="SESS_INFO_CLIENT_TYPE_LEGACY_REMOTE_TARGET_VISU">Probably Remote TargetVisu before version V3.5.16.0.</element>
 * <element name="SESS_INFO_CLIENT_TYPE_LEGACY_PLCHANDLER">Probably PLCHandler or similar before version V3.5.16.0.</element>
 */
#define SESS_INFO_CLIENT_TYPE_NO_INFO						0x00000000
#define SESS_INFO_CLIENT_TYPE_PROGRAMMING_SYSTEM			0xC0DE5150
#define SESS_INFO_CLIENT_TYPE_PROG_SYSTEM_VIA_CAS			0xC0DE0CA5
#define SESS_INFO_CLIENT_TYPE_OPC_UA_CLIENT					0x09C02000
#define SESS_INFO_CLIENT_TYPE_WEBVISU						0xABCDABCD
#define SESS_INFO_CLIENT_TYPE_REMOTE_TARGET_VISU			0x08150815
#define SESS_INFO_CLIENT_TYPE_DATA_SOURCES					0xD520D520
#define SESS_INFO_CLIENT_TYPE_DATA_SERVER					0xD510D510
#define SESS_INFO_CLIENT_TYPE_PLCHANDLER					0x59500000
#define SESS_INFO_CLIENT_TYPE_PLCH_OPC						(SESS_INFO_CLIENT_TYPE_PLCHANDLER + 0x09C0)
#define SESS_INFO_CLIENT_TYPE_PLCH_EDGE						(SESS_INFO_CLIENT_TYPE_PLCHANDLER + 0xED6E)
#define SESS_INFO_CLIENT_TYPE_PLCH_DATA_SOURCES				(SESS_INFO_CLIENT_TYPE_PLCHANDLER + 0xD520)
#define SESS_INFO_CLIENT_TYPE_PLCH_IECVARACC_BROWSE			(SESS_INFO_CLIENT_TYPE_PLCHANDLER + 0x1ECB)
#define SESS_INFO_CLIENT_TYPE_LEGACY_PROGRAMMING_SYSTEM		0x01D0C0DE
#define SESS_INFO_CLIENT_TYPE_LEGACY_WEBVISU				0x01D0ABCD
#define SESS_INFO_CLIENT_TYPE_LEGACY_REMOTE_TARGET_VISU		0x01D00815
#define SESS_INFO_CLIENT_TYPE_LEGACY_PLCHANDLER				0x01D05950

/**
 * <category>Session information structure</category>
 * <description>This structure holds the information that is stored for each client. See description of SessionInfoAddSession for element descriptions.</description>
 */
typedef struct SessionInfo_
{
	RTS_UI32		ui32SessionId;
	RTS_UI32		ui32ChannelId;
	RTS_UI32		ui32ClientType;
	RTS_UTF8STRING	szUserName[SESS_INFO_MEMSIZE_USER_NAME];
	RTS_UTF8STRING	szClientName[SESS_INFO_MEMSIZE_CLIENT_NAME];
	RTS_UTF8STRING	szClientVendorName[SESS_INFO_MEMSIZE_CLIENT_VENDOR_NAME];
	RTS_UTF8STRING	szClientHostName[SESS_INFO_MEMSIZE_CLIENT_HOST_NAME];
	RTS_UTF8STRING	szClientVersion[SESS_INFO_MEMSIZE_CLIENT_VERSION];
	RTS_UTF8STRING	szClientCdsVersion[SESS_INFO_MEMSIZE_CLIENT_CDS_VERSION];
} SessionInfo;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description>
 * Add a session information record to the session info pool.
 * All String contents are copied into the own memory of the CmpSessionInformation module and therefore do not have to be retained by the caller afterwards.  
 * </description>
 * <param name="ui32ClientType" type="IN">The type of the client that created this session. See Client types.</param>
 * <param name="ui32SessionId" type="IN">SessionId used for the CODESYS online communication, not used for OPC UA clients.</param>
 * <param name="ui32ChannelId" type="IN">ChannelId used for the CODESYS online communication, not used for OPC UA clients.</param>
 * <param name="pszUserName" type="IN">UTF-8 encoded user name known by the user management. Max. mem. size: SESS_INFO_MEMSIZE_USER_NAME.</param>
 * <param name="pszClientName" type="IN">UTF-8 encoded name of the client application that created that session. Max. mem. size: SESS_INFO_MEMSIZE_CLIENT_NAME.</param>
 * <param name="pszClientVendorName" type="IN">UTF-8 encoded name of the client application's vendor. Max. mem. size: SESS_INFO_MEMSIZE_CLIENT_VENDOR_NAME.</param>
 * <param name="pszClientHostName" type="IN">UTF-8 encoded host name where client is running. Max. mem. size: SESS_INFO_MEMSIZE_CLIENT_HOST_NAME.</param>
 * <param name="pszClientVersion" type="IN">UTF-8 encoded client version. Max. mem. size: SESS_INFO_MEMSIZE_CLIENT_VERSION.</param>
 * <param name="pszClientCdsVersion" type="IN">UTF-8 encoded CODESYS version the client is based on. Max. mem. size: SESS_INFO_MEMSIZE_CLIENT_CDS_VERSION.</param>
 * <param name="prResult" type="OUT">Result of the operation.</param>
 * <result>Handle to the session information.</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Session info successfully stored.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_MEMORY">No more memory to store the session info.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Something else went wrong.</errorcode>
 */
DEF_ITF_API(`RTS_HANDLE', `CDECL', `SessionInfoAddSession', `(RTS_UI32 ui32ClientType, RTS_UI32 ui32SessionId, RTS_UI32 ui32ChannelId, RTS_UTF8STRING const* pszUserName, RTS_UTF8STRING const* pszClientName, RTS_UTF8STRING const* pszClientVendorName, RTS_UTF8STRING const* pszClientHostName, RTS_UTF8STRING const* pszClientVersion, RTS_UTF8STRING const* pszClientCdsVersion, RTS_RESULT * prResult)')

/**
 * <description>Update the user handle of an existing session information record. This must be called after 
 * 	a user has upgraded the credentials to handle specific operations.</description>
 * <param name="hSessionInfo" type="IN">Handle to the session information.</param>
 * <param name="pszUserName" type="IN">UTF-8 encoded user name known by the user management. Max. mem. size: SESS_INFO_MEMSIZE_USER_NAME.</param>
 * <result>Error Code.</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Session info successfully updated.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_INVALID_HANDLE">hSessionInfo was invalid.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Something else went wrong.</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `SessionInfoUpdateUser', `(RTS_HANDLE hSessionInfo, RTS_UTF8STRING const* pszUserName)')

/**
 * <description>Delete the session information. Used when a client closes the session.</description>
 * <param name="hSessionInfo" type="IN">Handle to the session information.</param>
 * <result>Error Code.</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Session info successfully removed.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_INVALID_HANDLE">hSessionInfo was invalid.</errorcode>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `SessionInfoRemoveSession', `(RTS_HANDLE hSessionInfo)')

/**
 * <description>
 * <description>Retrieves the session information for a given session Id.</description>
 * <param name="ui32SessionId" type="IN">Session Id for which the session information is requested.</param>
 * <param name="pResult" type="OUT">Pointer to error code.</param>
 * <errorcode name="RTS_RESULT Result" type="ERR_OK">Session information retrieved successfully.</errorcode>
 * <errorcode name="RTS_RESULT Result" type="ERR_NO_OBJECT">No session information found for the given session Id.</errorcode>
 * <result>Pointer to the session information.</result>
 */
DEF_ITF_API(`SessionInfo*', `CDECL', `SessionInfoGetById', `(RTS_UI32 ui32SessionId, RTS_RESULT *pResult)')

#ifdef __cplusplus
}
#endif
