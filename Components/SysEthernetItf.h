 /**
 * <interfacename>SysEthernet</interfacename>
 * <description> 
 *	<p>The SysEthernet interface contains low level routines for a direct access to an Ethernet controller.
 *	This interface is typically used by an EtherCAT driver.</p>
 *	<p>All other Ethernet communication components use higher level routines (see SysSocket interface).</p>
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */


	
	
#ifndef _SYSETHERNETITF_H_
#define _SYSETHERNETITF_H_

#include "CmpStd.h"

 

 




/**
 * <category>Static defines</category>
 * <description>Maximum number of supported adapters</description>
 */
#ifndef	MAX_NUM_ADAPTERS
	#define MAX_NUM_ADAPTERS 15
#endif

/**
 * <category>Static defines</category>
 * <description>Maximum mac address length</description>
 */
#define MAX_MAC_ADDR_LENGTH 8

/**
 * <category>Static defines</category>
 * <description>Maximum packet size</description>
 */
#define MAX_PACKET_SIZE 1514

/**
 * <category>Static defines</category>
 * <description>Maximum queue size</description>
 */
#define MAX_QUEUE_SIZE 15000

/**
 * <category>Static defines</category>
 * <description></description>
 */
#define DEFAULT_ADAPTER_NAMELIST 1000

/**
 * <category>Static defines</category>
 * <description>Ethercat protocol type</description>
 */
#define PROTO_ECAT 0x88A4

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>filter for incoming packets by protocol type. Default is EtherCAT
 * Set Linux.ProtocolFilter=3 for no filtering at all(for ProfiNet or ethnetIP). See Linux/if_ether.h for valid filter values</description>
 */
#define SYSETHERNETKEY_INT_LINUX_PROTOCOLFILTER			"Linux.ProtocolFilter"
#define SYSETHERNETKEY_INT_LINUX_PROTOCOLFILTER_DEFAULT	PROTO_ECAT

/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>Interface names which are allowed for SysEthernet.
 *  If applied, no other names are accepted.
 *	Interface name list must be indexed, started with 0, e.g.:
 *	Linux.InterfaceFilter.0=eth0
 *	Linux.InterfaceFilter.1=eth1</description>
 */
#define SYSETHERNETKEY_INT_LINUX_INTERFACE_FILTER			"Linux.InterfaceFilter"

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>use socket-option PACKET_QDISC_BYPASS for SysEthernet sockets. Default is no</description>
 */
#define SYSETHERNETKEY_INT_LINUX_QDISC_BYPASS			"Linux.PACKET_QDISC_BYPASS"
#define SYSETHERNETKEY_INT_LINUX_QDISC_BYPASS_DEFAULT	0

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>DSA tag mode for Ethernet frames. See Distributed Switch Architecture (DSA) for details.
 * Setting can be evaluated by Ethernet based stacks to be able to use DSA tail tagging.
 * 0 - not active
 * 1 - DSA
 * 2 - TRAILER
 * 3 - EDSA
 * 4 - BRCM
 * </description>
 */
#define SYSETHERNETKEY_INT_DSA_TAG_MODE					"DSATagMode"
#define SYSETHERNETKEY_INT_DSA_TAG_DEFAULT				0

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>DSA tag port for Ethernet frames. See Distributed Switch Architecture (DSA) for details.
 * Setting can be evaluated by Ethernet based stacks to set the port via DSA tail tagging.
 * 0 - not active
 * 1 - 1st port
 * 2 - 2nd port
 * ...</description>
 */
#define SYSETHERNETKEY_INT_DSA_TAG_PORT					"DSATagPort"
#define SYSETHERNETKEY_INT_DSA_TAG_PORT_DEFAULT			0


/**
 * <category>Event parameter</category>
 * <element name="pFrame" type="IN">Pointer to one Ethernet frame</element>
 */
typedef struct
{
	unsigned char* pFrame;
} EVTPARAM_SysEthernet;
#define EVTPARAMID_SysEthernet		0x0001
#define EVTVERSION_SysEthernet		0x0001

/**
 * <category>Events</category>
 * <description>Event is sent when Ethernet packet has arrived</description>
 * <param name="pEventParam" type="IN">EVTPARAM_SysEthernet</param>
 */
#define EVT_EthPacketArrived					MAKE_EVENTID(EVTCLASS_INFO, 1)

/**
 * <category>Events</category>
 * <description>Event is sent when Ethernet packet was sent</description>
 * <param name="pEventParam" type="IN">EVTPARAM_SysEthernet</param>
 */
#define EVT_EthPacketSent						MAKE_EVENTID(EVTCLASS_INFO, 2)

/**
 * <category>Events</category>
 * <description>Event is created by the platform specific adaptation of SysEthernet, in case there are parameters, that are designed to be changed by the application.
 * This way it is possible for the application to check if there are such possibilities and to get some parameters by calling "EventPost"</description>
 * <param name="pEventParam" type="IN">EVTPARAM_SysEthernet</param>
 */
#define EVT_EthGetParameterValue						MAKE_EVENTID(EVTCLASS_INFO, 3)

/**
 * <category>Events</category>
 * <description>Event is created by the platform specific adaptation of SysEthernet, in case there are parameters, that are designed to be changed by the application.
 * This way it is possible for the application to check if there are such possibilities and to set some parameters by calling "EventPost"</description>
 * <param name="pEventParam" type="IN">EVTPARAM_SysEthernet</param>
 */
#define EVT_EthSetParameterValue						MAKE_EVENTID(EVTCLASS_INFO, 4)

/**
 * <category>Event parameter</category>
 * <element name="ulLength" type="IN">Length of the parameter data.</element>
 * <element name="ulID" type="IN">A 32 bit value that identifies the parameter.</element>
 * <element name="pData" type="IN">A pointer to the value data of the parameter.</element>
 */
typedef struct
{
	unsigned long ulID;
	int iMasterNum;
	unsigned long ulLength;
	void* pData;
} EVTPARAM_SysEthernetSetGetParameter;
#define EVTPARAM_SysEthernetSetGetParameterID_NoPollingInGetEthframe	0x0001
#define EVTPARAM_SysEthernetSetGetParameterID_PollingOnlyNoInterrupts	0x0002
#define EVTPARAMID_SysEthernetParameter		0x0002


/**
 * <category>Online services</category>
 */

#define SRV_ETC_GETADAPTERINFO				0x77

/**
 * <category>Online service tags</category>
 */
#define TAG_ETC_MASTERLIST					0x81
#define TAG_ETC_MASTERNAME					0x02
#define TAG_ETC_MASTERDESC					0x03
#define TAG_ETC_MASTERMAC					0x04

#define TAG_ETC_SOCKADAPTER					0x11
#define TAG_ETC_SOCKADAPTER_NEXT_INDEX		0x12

/**
 * <category>Online services</category>
 * <service group="SG_ETHERCAT" id="SRV_ETC_GETSOCKADAPTERINFO" name="">
 *	<description>
 *		Service to retrieve the adapter info on SysSocket level. Should be polled until the content of TAG_SERVICE_RESULT is 
 *		different from ERR_ENTRIES_REMAINING to get all adapters. 
 *	</description>
 *	<request>
 *		<tag id="TAG_ETC_SOCKADAPTER_NEXT_INDEX" name="" cardinality="0..?" type="RTS_UI32"
 *		 description="Index of first adapter, which should be read. Default is 0, if tag is omitted."/>
 *	</request>
 *	<response>
 *		<tag id="TAG_ETC_SOCKADAPTER" name="" cardinality="0..?" type="SOCK_ADAPTER_INFORMATION">
 *			<description>
 *				Adapter information for one network adapter. 
 *				For each adapter one tag of this type is added. Layout of IEC structure SOCK_ADAPTER_INFORMATION is used.
 *				Is not returned, if no adapter is available.
 *			</description>
 *		</tag>
 *		<tag id="TAG_ETC_SOCKADAPTER_NEXT_INDEX" name="" cardinality="0..?" type="RTS_UI32">
 *			<description>
 *				Index of next adapter, which should be requested by next service
 *				Only returned, if not all adapter informations fits into the communication buffer.
 *			</description>
 *		</tag>
 *		<tag id="TAG_SERVICE_RESULT" name="" cardinality="1..?" type="RTS_UI16">
 *			<description>
 *				Result code of online service: 
 *				ERR_OK (all adapters have been read), 
 *				ERR_NOTIMPLEMENTED (SysSocket does not provide the functionality to read the adapter information),
 *				ERR_NOT_SUPPORTED (SysSockGetFirstAdapterInfo or SysSockGetFirstAdapterInfo are not available),
 *				ERR_FAILED (no adapter information available, e. g. no adapter present), 
 *				ERR_ENTRIES_REMAINING (not all adapter informations fits into the communication buffer).
 *			</description>
 *		</tag>
 *	</response>
 * </service>
 */
#define SRV_ETC_GETSOCKADAPTERINFO 0x76

typedef struct
{
	RTS_UI32 MacAddressLen;					/* Length of the link layer address */
	unsigned char MacAddress[MAX_MAC_ADDR_LENGTH];	/* Link layer address */
}MacAdr;

typedef struct
{
	unsigned char dest_mac[6];
	unsigned char source_mac[6];
	unsigned short eth_type;
	unsigned char head_length;
	unsigned char service;
	unsigned char firsttel[1500];
}Ethernetframe;


typedef struct
{
	RTS_I32 iMasterNum;
	MacAdr MacAddress;
	RTS_I32 nReturnVal;
}OpenEthernetInterface;

typedef struct
{
	RTS_I32 iMasterNum;
	RTS_I32 nReturnVal;
}CloseEthernetInterface;


typedef struct
{
	RTS_I32 iMasterNum;
	Ethernetframe *pFrame;
	RTS_I32 nSize;
	RTS_I32 nReturnVal;
}SendEthernetInterface;

typedef struct
{
	RTS_I32 iMasterNum;
	unsigned char **ppFrame;
	RTS_I32* pnSize;
	RTS_I32 nReturnVal;
}GetEthernetInterface;

typedef struct
{
	unsigned char **ppFrame;
	RTS_I32* pnSize;
	RTS_I32 nReturnVal;
}GetIPEthernetInterface;

typedef struct
{
	Ethernetframe *pFrame;
	RTS_I32 nSize;
	RTS_I32 nReturnVal;
}SendIPEthernetInterface;

typedef struct
{
	RTS_I32* piAdapterCnt;
	RTS_I32 nReturnVal;
}GetNumberOfEthernetInterface;

typedef struct
{
	int iAdapterNum;
	char *pszName;
	char *pszDescription;
	int iBuffersize;
	int iMacLength;
	char* MacAddress;
	RTS_I32 nReturnVal;
}GetAdapterInfoEthernetInterface;

#ifdef __cplusplus
extern "C" {
#endif

/* Init routines for OS specific modules */
RTS_RESULT CDECL SysEthernetOSInit(INIT_STRUCT *pInit);
RTS_RESULT CDECL SysEthernetOSHookFunction(RTS_UI32 ulHook, RTS_UINTPTR ulParam1, RTS_UINTPTR ulParam2);

/**
 * <description>Open a network adapter</description>
 * <param name="poei" type="IN">pointer to parameters</param>
 * <result>error code</result>
 */
void CDECL CDECL_EXT openethernet(OpenEthernetInterface* poei);
typedef void (CDECL * PFOPENETHERNET) (OpenEthernetInterface* poei);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(OPENETHERNET_NOTIMPLEMENTED)
	#define USE_openethernet
	#define EXT_openethernet
	#define GET_openethernet(fl)  ERR_NOTIMPLEMENTED
	#define CAL_openethernet(p0)  
	#define CHK_openethernet  FALSE
	#define EXP_openethernet  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_openethernet
	#define EXT_openethernet
	#define GET_openethernet(fl)  CAL_CMGETAPI( "openethernet" ) 
	#define CAL_openethernet  openethernet
	#define CHK_openethernet  TRUE
	#define EXP_openethernet  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"openethernet", (RTS_UINTPTR)openethernet, 1, 0) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_openethernet
	#define EXT_openethernet
	#define GET_openethernet(fl)  CAL_CMGETAPI( "openethernet" ) 
	#define CAL_openethernet  openethernet
	#define CHK_openethernet  TRUE
	#define EXP_openethernet  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"openethernet", (RTS_UINTPTR)openethernet, 1, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetopenethernet
	#define EXT_SysEthernetopenethernet
	#define GET_SysEthernetopenethernet  ERR_OK
	#define CAL_SysEthernetopenethernet pISysEthernet->Iopenethernet
	#define CHK_SysEthernetopenethernet (pISysEthernet != NULL)
	#define EXP_SysEthernetopenethernet  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_openethernet
	#define EXT_openethernet
	#define GET_openethernet(fl)  CAL_CMGETAPI( "openethernet" ) 
	#define CAL_openethernet pISysEthernet->Iopenethernet
	#define CHK_openethernet (pISysEthernet != NULL)
	#define EXP_openethernet  CAL_CMEXPAPI( "openethernet" ) 
#else /* DYNAMIC_LINK */
	#define USE_openethernet  PFOPENETHERNET pfopenethernet;
	#define EXT_openethernet  extern PFOPENETHERNET pfopenethernet;
	#define GET_openethernet(fl)  s_pfCMGetAPI2( "openethernet", (RTS_VOID_FCTPTR *)&pfopenethernet, (fl), 0, 0)
	#define CAL_openethernet  pfopenethernet
	#define CHK_openethernet  (pfopenethernet != NULL)
	#define EXP_openethernet  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"openethernet", (RTS_UINTPTR)openethernet, 1, 0) 
#endif




/**
 * <description>Send etherpacket</description>
 * <param name="psfi" type="IN">Pointer to parameters</param>
 * <result>error code</result>
 */
void CDECL CDECL_EXT sendethframe(SendEthernetInterface* psfi);
typedef void (CDECL * PFSENDETHFRAME) (SendEthernetInterface* psfi);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(SENDETHFRAME_NOTIMPLEMENTED)
	#define USE_sendethframe
	#define EXT_sendethframe
	#define GET_sendethframe(fl)  ERR_NOTIMPLEMENTED
	#define CAL_sendethframe(p0)  
	#define CHK_sendethframe  FALSE
	#define EXP_sendethframe  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_sendethframe
	#define EXT_sendethframe
	#define GET_sendethframe(fl)  CAL_CMGETAPI( "sendethframe" ) 
	#define CAL_sendethframe  sendethframe
	#define CHK_sendethframe  TRUE
	#define EXP_sendethframe  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"sendethframe", (RTS_UINTPTR)sendethframe, 1, 0) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_sendethframe
	#define EXT_sendethframe
	#define GET_sendethframe(fl)  CAL_CMGETAPI( "sendethframe" ) 
	#define CAL_sendethframe  sendethframe
	#define CHK_sendethframe  TRUE
	#define EXP_sendethframe  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"sendethframe", (RTS_UINTPTR)sendethframe, 1, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetsendethframe
	#define EXT_SysEthernetsendethframe
	#define GET_SysEthernetsendethframe  ERR_OK
	#define CAL_SysEthernetsendethframe pISysEthernet->Isendethframe
	#define CHK_SysEthernetsendethframe (pISysEthernet != NULL)
	#define EXP_SysEthernetsendethframe  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_sendethframe
	#define EXT_sendethframe
	#define GET_sendethframe(fl)  CAL_CMGETAPI( "sendethframe" ) 
	#define CAL_sendethframe pISysEthernet->Isendethframe
	#define CHK_sendethframe (pISysEthernet != NULL)
	#define EXP_sendethframe  CAL_CMEXPAPI( "sendethframe" ) 
#else /* DYNAMIC_LINK */
	#define USE_sendethframe  PFSENDETHFRAME pfsendethframe;
	#define EXT_sendethframe  extern PFSENDETHFRAME pfsendethframe;
	#define GET_sendethframe(fl)  s_pfCMGetAPI2( "sendethframe", (RTS_VOID_FCTPTR *)&pfsendethframe, (fl), 0, 0)
	#define CAL_sendethframe  pfsendethframe
	#define CHK_sendethframe  (pfsendethframe != NULL)
	#define EXP_sendethframe  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"sendethframe", (RTS_UINTPTR)sendethframe, 1, 0) 
#endif




/**
 * <description>Get Ethernet packet</description>
 * <param name="pgei" type="IN">Pointer to parameters</param>
 * <result>error code</result>
 */
void CDECL CDECL_EXT getethframe(GetEthernetInterface* pgei);
typedef void (CDECL * PFGETETHFRAME) (GetEthernetInterface* pgei);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(GETETHFRAME_NOTIMPLEMENTED)
	#define USE_getethframe
	#define EXT_getethframe
	#define GET_getethframe(fl)  ERR_NOTIMPLEMENTED
	#define CAL_getethframe(p0)  
	#define CHK_getethframe  FALSE
	#define EXP_getethframe  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_getethframe
	#define EXT_getethframe
	#define GET_getethframe(fl)  CAL_CMGETAPI( "getethframe" ) 
	#define CAL_getethframe  getethframe
	#define CHK_getethframe  TRUE
	#define EXP_getethframe  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"getethframe", (RTS_UINTPTR)getethframe, 1, 0) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_getethframe
	#define EXT_getethframe
	#define GET_getethframe(fl)  CAL_CMGETAPI( "getethframe" ) 
	#define CAL_getethframe  getethframe
	#define CHK_getethframe  TRUE
	#define EXP_getethframe  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"getethframe", (RTS_UINTPTR)getethframe, 1, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetgetethframe
	#define EXT_SysEthernetgetethframe
	#define GET_SysEthernetgetethframe  ERR_OK
	#define CAL_SysEthernetgetethframe pISysEthernet->Igetethframe
	#define CHK_SysEthernetgetethframe (pISysEthernet != NULL)
	#define EXP_SysEthernetgetethframe  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_getethframe
	#define EXT_getethframe
	#define GET_getethframe(fl)  CAL_CMGETAPI( "getethframe" ) 
	#define CAL_getethframe pISysEthernet->Igetethframe
	#define CHK_getethframe (pISysEthernet != NULL)
	#define EXP_getethframe  CAL_CMEXPAPI( "getethframe" ) 
#else /* DYNAMIC_LINK */
	#define USE_getethframe  PFGETETHFRAME pfgetethframe;
	#define EXT_getethframe  extern PFGETETHFRAME pfgetethframe;
	#define GET_getethframe(fl)  s_pfCMGetAPI2( "getethframe", (RTS_VOID_FCTPTR *)&pfgetethframe, (fl), 0, 0)
	#define CAL_getethframe  pfgetethframe
	#define CHK_getethframe  (pfgetethframe != NULL)
	#define EXP_getethframe  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"getethframe", (RTS_UINTPTR)getethframe, 1, 0) 
#endif




/**
 * <description>Close network adapter</description>
 * <param name="pcei" type="IN">Pointer to parameters</param>
 * <result>error code</result>
 */
void CDECL CDECL_EXT closeethernet(CloseEthernetInterface* pcei);
typedef void (CDECL * PFCLOSEETHERNET) (CloseEthernetInterface* pcei);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(CLOSEETHERNET_NOTIMPLEMENTED)
	#define USE_closeethernet
	#define EXT_closeethernet
	#define GET_closeethernet(fl)  ERR_NOTIMPLEMENTED
	#define CAL_closeethernet(p0)  
	#define CHK_closeethernet  FALSE
	#define EXP_closeethernet  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_closeethernet
	#define EXT_closeethernet
	#define GET_closeethernet(fl)  CAL_CMGETAPI( "closeethernet" ) 
	#define CAL_closeethernet  closeethernet
	#define CHK_closeethernet  TRUE
	#define EXP_closeethernet  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"closeethernet", (RTS_UINTPTR)closeethernet, 1, 0) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_closeethernet
	#define EXT_closeethernet
	#define GET_closeethernet(fl)  CAL_CMGETAPI( "closeethernet" ) 
	#define CAL_closeethernet  closeethernet
	#define CHK_closeethernet  TRUE
	#define EXP_closeethernet  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"closeethernet", (RTS_UINTPTR)closeethernet, 1, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetcloseethernet
	#define EXT_SysEthernetcloseethernet
	#define GET_SysEthernetcloseethernet  ERR_OK
	#define CAL_SysEthernetcloseethernet pISysEthernet->Icloseethernet
	#define CHK_SysEthernetcloseethernet (pISysEthernet != NULL)
	#define EXP_SysEthernetcloseethernet  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_closeethernet
	#define EXT_closeethernet
	#define GET_closeethernet(fl)  CAL_CMGETAPI( "closeethernet" ) 
	#define CAL_closeethernet pISysEthernet->Icloseethernet
	#define CHK_closeethernet (pISysEthernet != NULL)
	#define EXP_closeethernet  CAL_CMEXPAPI( "closeethernet" ) 
#else /* DYNAMIC_LINK */
	#define USE_closeethernet  PFCLOSEETHERNET pfcloseethernet;
	#define EXT_closeethernet  extern PFCLOSEETHERNET pfcloseethernet;
	#define GET_closeethernet(fl)  s_pfCMGetAPI2( "closeethernet", (RTS_VOID_FCTPTR *)&pfcloseethernet, (fl), 0, 0)
	#define CAL_closeethernet  pfcloseethernet
	#define CHK_closeethernet  (pfcloseethernet != NULL)
	#define EXP_closeethernet  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"closeethernet", (RTS_UINTPTR)closeethernet, 1, 0) 
#endif




/**
 * <description>Get number of network adapters</description>
 * <param name="pnoei" type="IN">Pointer to parameters</param>
 * <result>error code</result>
 */
void CDECL CDECL_EXT getnumberofadapters(GetNumberOfEthernetInterface* pnoei);
typedef void (CDECL * PFGETNUMBEROFADAPTERS) (GetNumberOfEthernetInterface* pnoei);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(GETNUMBEROFADAPTERS_NOTIMPLEMENTED)
	#define USE_getnumberofadapters
	#define EXT_getnumberofadapters
	#define GET_getnumberofadapters(fl)  ERR_NOTIMPLEMENTED
	#define CAL_getnumberofadapters(p0) 
	#define CHK_getnumberofadapters  FALSE
	#define EXP_getnumberofadapters  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_getnumberofadapters
	#define EXT_getnumberofadapters
	#define GET_getnumberofadapters(fl)  CAL_CMGETAPI( "getnumberofadapters" ) 
	#define CAL_getnumberofadapters  getnumberofadapters
	#define CHK_getnumberofadapters  TRUE
	#define EXP_getnumberofadapters  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"getnumberofadapters", (RTS_UINTPTR)getnumberofadapters, 1, 0) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_getnumberofadapters
	#define EXT_getnumberofadapters
	#define GET_getnumberofadapters(fl)  CAL_CMGETAPI( "getnumberofadapters" ) 
	#define CAL_getnumberofadapters  getnumberofadapters
	#define CHK_getnumberofadapters  TRUE
	#define EXP_getnumberofadapters  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"getnumberofadapters", (RTS_UINTPTR)getnumberofadapters, 1, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetgetnumberofadapters
	#define EXT_SysEthernetgetnumberofadapters
	#define GET_SysEthernetgetnumberofadapters  ERR_OK
	#define CAL_SysEthernetgetnumberofadapters  getnumberofadapters
	#define CHK_SysEthernetgetnumberofadapters  TRUE
	#define EXP_SysEthernetgetnumberofadapters  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"getnumberofadapters", (RTS_UINTPTR)getnumberofadapters, 1, 0) 
#elif defined(CPLUSPLUS)
	#define USE_getnumberofadapters
	#define EXT_getnumberofadapters
	#define GET_getnumberofadapters(fl)  CAL_CMGETAPI( "getnumberofadapters" ) 
	#define CAL_getnumberofadapters  getnumberofadapters
	#define CHK_getnumberofadapters  TRUE
	#define EXP_getnumberofadapters  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"getnumberofadapters", (RTS_UINTPTR)getnumberofadapters, 1, 0) 
#else /* DYNAMIC_LINK */
	#define USE_getnumberofadapters  PFGETNUMBEROFADAPTERS pfgetnumberofadapters;
	#define EXT_getnumberofadapters  extern PFGETNUMBEROFADAPTERS pfgetnumberofadapters;
	#define GET_getnumberofadapters(fl)  s_pfCMGetAPI2( "getnumberofadapters", (RTS_VOID_FCTPTR *)&pfgetnumberofadapters, (fl), 0, 0)
	#define CAL_getnumberofadapters  pfgetnumberofadapters
	#define CHK_getnumberofadapters  (pfgetnumberofadapters != NULL)
	#define EXP_getnumberofadapters   s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"getnumberofadapters", (RTS_UINTPTR)getnumberofadapters, 1, 0) 
#endif


/**
 *  <description>Get info about specified network adapters</description>
 * <param name="paiei" type="IN">Pointer to parameters</param>
 * <result>error code</result>
 */
void CDECL CDECL_EXT getadapterinfo(GetAdapterInfoEthernetInterface* paiei);
typedef void (CDECL * PFGETADAPTERINFO) (GetAdapterInfoEthernetInterface* paiei);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(GETADAPTERINFO_NOTIMPLEMENTED)
	#define USE_getadapterinfo
	#define EXT_getadapterinfo
	#define GET_getadapterinfo(fl)  ERR_NOTIMPLEMENTED
	#define CAL_getadapterinfo(p0) 
	#define CHK_getadapterinfo  FALSE
	#define EXP_getadapterinfo  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_getadapterinfo
	#define EXT_getadapterinfo
	#define GET_getadapterinfo(fl)  CAL_CMGETAPI( "getadapterinfo" ) 
	#define CAL_getadapterinfo  getadapterinfo
	#define CHK_getadapterinfo  TRUE
	#define EXP_getadapterinfo  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"getadapterinfo", (RTS_UINTPTR)getadapterinfo, 1, 0) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_getadapterinfo
	#define EXT_getadapterinfo
	#define GET_getadapterinfo(fl)  CAL_CMGETAPI( "getadapterinfo" ) 
	#define CAL_getadapterinfo  getadapterinfo
	#define CHK_getadapterinfo  TRUE
	#define EXP_getadapterinfo  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"getadapterinfo", (RTS_UINTPTR)getadapterinfo, 1, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetgetadapterinfo
	#define EXT_SysEthernetgetadapterinfo
	#define GET_SysEthernetgetadapterinfo  ERR_OK
	#define CAL_SysEthernetgetadapterinfo  getadapterinfo
	#define CHK_SysEthernetgetadapterinfo  TRUE
	#define EXP_SysEthernetgetadapterinfo  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"getadapterinfo", (RTS_UINTPTR)getadapterinfo, 1, 0) 
#elif defined(CPLUSPLUS)
	#define USE_getadapterinfo
	#define EXT_getadapterinfo
	#define GET_getadapterinfo(fl)  CAL_CMGETAPI( "getadapterinfo" ) 
	#define CAL_getadapterinfo  getadapterinfo
	#define CHK_getadapterinfo  TRUE
	#define EXP_getadapterinfo  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"getadapterinfo", (RTS_UINTPTR)getadapterinfo, 1, 0) 
#else /* DYNAMIC_LINK */
	#define USE_getadapterinfo  PFGETADAPTERINFO pfgetadapterinfo;
	#define EXT_getadapterinfo  extern PFGETADAPTERINFO pfgetadapterinfo;
	#define GET_getadapterinfo(fl)  s_pfCMGetAPI2( "getadapterinfo", (RTS_VOID_FCTPTR *)&pfgetadapterinfo, (fl), 0, 0)
	#define CAL_getadapterinfo  pfgetadapterinfo
	#define CHK_getadapterinfo  (pfgetadapterinfo != NULL)
	#define EXP_getadapterinfo   s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"getadapterinfo", (RTS_UINTPTR)getadapterinfo, 1, 0) 
#endif



/**
 * <description>Send IP Ethernet packet (EoE)</description>
 * <param name="psfi" type="IN">Pointer to parameters</param>
 * <result>error code</result>
 */
void CDECL CDECL_EXT sendIPethframe(SendIPEthernetInterface* psfi);
typedef void (CDECL * PFSENDIPETHFRAME) (SendIPEthernetInterface* psfi);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(SENDIPETHFRAME_NOTIMPLEMENTED)
	#define USE_sendIPethframe
	#define EXT_sendIPethframe
	#define GET_sendIPethframe(fl)  ERR_NOTIMPLEMENTED
	#define CAL_sendIPethframe(p0)  
	#define CHK_sendIPethframe  FALSE
	#define EXP_sendIPethframe  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_sendIPethframe
	#define EXT_sendIPethframe
	#define GET_sendIPethframe(fl)  CAL_CMGETAPI( "sendIPethframe" ) 
	#define CAL_sendIPethframe  sendIPethframe
	#define CHK_sendIPethframe  TRUE
	#define EXP_sendIPethframe  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"sendIPethframe", (RTS_UINTPTR)sendIPethframe, 1, 0) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_sendIPethframe
	#define EXT_sendIPethframe
	#define GET_sendIPethframe(fl)  CAL_CMGETAPI( "sendIPethframe" ) 
	#define CAL_sendIPethframe  sendIPethframe
	#define CHK_sendIPethframe  TRUE
	#define EXP_sendIPethframe  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"sendIPethframe", (RTS_UINTPTR)sendIPethframe, 1, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetsendIPethframe
	#define EXT_SysEthernetsendIPethframe
	#define GET_SysEthernetsendIPethframe  ERR_OK
	#define CAL_SysEthernetsendIPethframe pISysEthernet->IsendIPethframe
	#define CHK_SysEthernetsendIPethframe (pISysEthernet != NULL)
	#define EXP_SysEthernetsendIPethframe  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_sendIPethframe
	#define EXT_sendIPethframe
	#define GET_sendIPethframe(fl)  CAL_CMGETAPI( "sendIPethframe" ) 
	#define CAL_sendIPethframe pISysEthernet->IsendIPethframe
	#define CHK_sendIPethframe (pISysEthernet != NULL)
	#define EXP_sendIPethframe  CAL_CMEXPAPI( "sendIPethframe" ) 
#else /* DYNAMIC_LINK */
	#define USE_sendIPethframe  PFSENDIPETHFRAME pfsendIPethframe;
	#define EXT_sendIPethframe  extern PFSENDIPETHFRAME pfsendIPethframe;
	#define GET_sendIPethframe(fl)  s_pfCMGetAPI2( "sendIPethframe", (RTS_VOID_FCTPTR *)&pfsendIPethframe, (fl), 0, 0)
	#define CAL_sendIPethframe  pfsendIPethframe
	#define CHK_sendIPethframe  (pfsendIPethframe != NULL)
	#define EXP_sendIPethframe  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"sendIPethframe", (RTS_UINTPTR)sendIPethframe, 1, 0) 
#endif




/**
 * <description>Get IP Ethernet packet</description>
 * <param name="pgei" type="IN">Pointer to parameters</param>
 * <result>error code</result>
 */
void CDECL CDECL_EXT getIPethframe(GetIPEthernetInterface* pgei);
typedef void (CDECL * PFGETIPETHFRAME) (GetIPEthernetInterface* pgei);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(GETIPETHFRAME_NOTIMPLEMENTED)
	#define USE_getIPethframe
	#define EXT_getIPethframe
	#define GET_getIPethframe(fl)  ERR_NOTIMPLEMENTED
	#define CAL_getIPethframe(p0)  
	#define CHK_getIPethframe  FALSE
	#define EXP_getIPethframe  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_getIPethframe
	#define EXT_getIPethframe
	#define GET_getIPethframe(fl)  CAL_CMGETAPI( "getIPethframe" ) 
	#define CAL_getIPethframe  getIPethframe
	#define CHK_getIPethframe  TRUE
	#define EXP_getIPethframe  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"getIPethframe", (RTS_UINTPTR)getIPethframe, 1, 0) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_getIPethframe
	#define EXT_getIPethframe
	#define GET_getIPethframe(fl)  CAL_CMGETAPI( "getIPethframe" ) 
	#define CAL_getIPethframe  getIPethframe
	#define CHK_getIPethframe  TRUE
	#define EXP_getIPethframe  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"getIPethframe", (RTS_UINTPTR)getIPethframe, 1, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetgetIPethframe
	#define EXT_SysEthernetgetIPethframe
	#define GET_SysEthernetgetIPethframe  ERR_OK
	#define CAL_SysEthernetgetIPethframe pISysEthernet->IgetIPethframe
	#define CHK_SysEthernetgetIPethframe (pISysEthernet != NULL)
	#define EXP_SysEthernetgetIPethframe  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_getIPethframe
	#define EXT_getIPethframe
	#define GET_getIPethframe(fl)  CAL_CMGETAPI( "getIPethframe" ) 
	#define CAL_getIPethframe pISysEthernet->IgetIPethframe
	#define CHK_getIPethframe (pISysEthernet != NULL)
	#define EXP_getIPethframe  CAL_CMEXPAPI( "getIPethframe" ) 
#else /* DYNAMIC_LINK */
	#define USE_getIPethframe  PFGETIPETHFRAME pfgetIPethframe;
	#define EXT_getIPethframe  extern PFGETIPETHFRAME pfgetIPethframe;
	#define GET_getIPethframe(fl)  s_pfCMGetAPI2( "getIPethframe", (RTS_VOID_FCTPTR *)&pfgetIPethframe, (fl), 0, 0)
	#define CAL_getIPethframe  pfgetIPethframe
	#define CHK_getIPethframe  (pfgetIPethframe != NULL)
	#define EXP_getIPethframe  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"getIPethframe", (RTS_UINTPTR)getIPethframe, 1, 0) 
#endif




#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION BEGIN **/
/*  Comments are ignored for m4 compiler so restructured text can be used.  */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description>AutoNegCaps</description>
 */
#define SYSETH_AUTONEGCAP_OTHERORUNKNOWN		RTS_IEC_ULINT_C(0x1)	/* other or unknown */
#define SYSETH_AUTONEGCAP_10BASET		RTS_IEC_ULINT_C(0x2)	/* 10BASE-T  half duplex mode */
#define SYSETH_AUTONEGCAP_10BASETFD		RTS_IEC_ULINT_C(0x4)	/* 10BASE-T  full duplex mode */
#define SYSETH_AUTONEGCAP_100BASET4		RTS_IEC_ULINT_C(0x8)	/* 100BASE-T4 */
#define SYSETH_AUTONEGCAP_100BASETX		RTS_IEC_ULINT_C(0x10)	/* 100BASE-TX half duplex mode */
#define SYSETH_AUTONEGCAP_100BASETXFD		RTS_IEC_ULINT_C(0x20)	/* 100BASE-TX full duplex mode */
#define SYSETH_AUTONEGCAP_100BASET2		RTS_IEC_ULINT_C(0x40)	/* 100BASE-T2 half duplex mode */
#define SYSETH_AUTONEGCAP_100BASET2FD		RTS_IEC_ULINT_C(0x80)	/* 100BASE-T2 full duplex mode */
#define SYSETH_AUTONEGCAP_FDXPAUSE		RTS_IEC_ULINT_C(0x100)	/* PAUSE for full-duplex links */
#define SYSETH_AUTONEGCAP_FDXAPAUSE		RTS_IEC_ULINT_C(0x200)	/* Asymmetric PAUSE for full-duplex links */
#define SYSETH_AUTONEGCAP_FDXSPAUSE		RTS_IEC_ULINT_C(0x400)	/* Symmetric PAUSE for full-duplex links */
#define SYSETH_AUTONEGCAP_FDXBPAUSE		RTS_IEC_ULINT_C(0x800)	/* Asymmetric and Symmetric PAUSE for full-duplex links */
#define SYSETH_AUTONEGCAP_1000BASEX		RTS_IEC_ULINT_C(0x1000)	/* 1000BASE-X, -LX, -SX, -CX half duplex mode */
#define SYSETH_AUTONEGCAP_1000BASEXFD		RTS_IEC_ULINT_C(0x2000)	/* 1000BASE-X, -LX, -SX, -CX full duplex mode */
#define SYSETH_AUTONEGCAP_1000BASET		RTS_IEC_ULINT_C(0x4000)	/* 1000BASE-T half duplex mode */
#define SYSETH_AUTONEGCAP_1000BASETFD		RTS_IEC_ULINT_C(0x8000)	/* 1000BASE-T full duplex mode */
#define SYSETH_AUTONEGCAP_10GBASET		RTS_IEC_ULINT_C(0x10000)	/* 10GBASE-T */
#define SYSETH_AUTONEGCAP_1000BASEKX		RTS_IEC_ULINT_C(0x20000)	/* 1000BASE-KX */
#define SYSETH_AUTONEGCAP_10GBASEKX4		RTS_IEC_ULINT_C(0x40000)	/* 10GBASE-KX4 */
#define SYSETH_AUTONEGCAP_10GBASEKR		RTS_IEC_ULINT_C(0x80000)	/* 10GBASE-KR */
#define SYSETH_AUTONEGCAP_40GBASEKR4		RTS_IEC_ULINT_C(0x100000)	/* 40GBASE-KR4 */
#define SYSETH_AUTONEGCAP_40GBASECR4		RTS_IEC_ULINT_C(0x200000)	/* 40GBASE-CR4 */
#define SYSETH_AUTONEGCAP_100GBASECR10		RTS_IEC_ULINT_C(0x400000)	/* 100GBASE-CR10 */
#define SYSETH_AUTONEGCAP_1000BASET1		RTS_IEC_ULINT_C(0x800000)	/* 1000BASE-T1 */
#define SYSETH_AUTONEGCAP_25GBASERS		RTS_IEC_ULINT_C(0x1000000)	/* 25GBASE-CR-S or 25GBASE-KR-S */
#define SYSETH_AUTONEGCAP_25GBASER		RTS_IEC_ULINT_C(0x2000000)	/* 25GBASE-CR or 25GBASE-KR */
#define SYSETH_AUTONEGCAP_RSFEC25GREQ		RTS_IEC_ULINT_C(0x4000000)	/* 25Gb/s RS-FEC */
#define SYSETH_AUTONEGCAP_BASEFEC25GREQ		RTS_IEC_ULINT_C(0x8000000)	/* 25Gb/s BASE-R FEC */
#define SYSETH_AUTONEGCAP_25GBASET		RTS_IEC_ULINT_C(0x10000000)	/* 25GBASE-T */
#define SYSETH_AUTONEGCAP_40GBASET		RTS_IEC_ULINT_C(0x20000000)	/* 40GBASE-T */
#define SYSETH_AUTONEGCAP_100GBASECR4		RTS_IEC_ULINT_C(0x40000000)	/* 100GBASE-CR4 */
#define SYSETH_AUTONEGCAP_100GBASEKR4		RTS_IEC_ULINT_C(0x80000000)	/* 100GBASE-KR4 */
#define SYSETH_AUTONEGCAP_100GBASEKP4		RTS_IEC_ULINT_C(0x100000000)	/* 100GBASE-KP4 */
#define SYSETH_AUTONEGCAP_FORCEMS		RTS_IEC_ULINT_C(0x200000000)	/* 1000BASE-T1 Force MS */

/**
 * <description>AutoNegMode</description>
 */
#define SYSETH_AUTONEGMODE_DISABLED		RTS_IEC_USINT_C(0x0)	
#define SYSETH_AUTONEGMODE_ENABLED		RTS_IEC_USINT_C(0x1)	
#define SYSETH_AUTONEGMODE_UNKNOWN		RTS_IEC_USINT_C(0xFF)	

/**
 * <description>AutoNegSupport</description>
 */
#define SYSETH_AUTONEGSUP_NOTSUPPORTED		RTS_IEC_USINT_C(0x0)	
#define SYSETH_AUTONEGSUP_SUPPORTED		RTS_IEC_USINT_C(0x1)	
#define SYSETH_AUTONEGSUP_UNKNOWN		RTS_IEC_USINT_C(0xFF)	

/**
 * <description>MauType</description>
 */
#define SYSETH_MAUTYPE_OTHERORUNKNOWN		RTS_IEC_UDINT_C(0x0)	/* other or unknown */
#define SYSETH_MAUTYPE_AUI		RTS_IEC_UDINT_C(0x1)	/* AUI */
#define SYSETH_MAUTYPE_10BASE5		RTS_IEC_UDINT_C(0x2)	/* 10BASE-5 */
#define SYSETH_MAUTYPE_FOIRL		RTS_IEC_UDINT_C(0x3)	/* FOIRL */
#define SYSETH_MAUTYPE_10BASE2		RTS_IEC_UDINT_C(0x4)	/* 10BASE-2 */
#define SYSETH_MAUTYPE_10BASET		RTS_IEC_UDINT_C(0x5)	/* 10BASE-T duplex mode unknown */
#define SYSETH_MAUTYPE_10BASEFP		RTS_IEC_UDINT_C(0x6)	/* 10BASE-FP */
#define SYSETH_MAUTYPE_10BASEFB		RTS_IEC_UDINT_C(0x7)	/* 10BASE-FB */
#define SYSETH_MAUTYPE_10BASEFL		RTS_IEC_UDINT_C(0x8)	/* 10BASE-FL duplex mode unknown */
#define SYSETH_MAUTYPE_10BROAD36		RTS_IEC_UDINT_C(0x9)	/* 10BROAD36 */
#define SYSETH_MAUTYPE_10BASETHD		RTS_IEC_UDINT_C(0xA)	/* 10BASE-T  half duplex mode */
#define SYSETH_MAUTYPE_10BASETFD		RTS_IEC_UDINT_C(0xB)	/* 10BASE-T  full duplex mode */
#define SYSETH_MAUTYPE_10BASEFLHD		RTS_IEC_UDINT_C(0xC)	/* 10BASE-FL half duplex mode */
#define SYSETH_MAUTYPE_10BASEFLFD		RTS_IEC_UDINT_C(0xD)	/* 10BASE-FL full duplex mode */
#define SYSETH_MAUTYPE_100BASET4		RTS_IEC_UDINT_C(0xE)	/* 100BASE-T4 */
#define SYSETH_MAUTYPE_100BASETXHD		RTS_IEC_UDINT_C(0xF)	/* 100BASE-TX half duplex mode */
#define SYSETH_MAUTYPE_100BASETXFD		RTS_IEC_UDINT_C(0x10)	/* 100BASE-TX full duplex mode */
#define SYSETH_MAUTYPE_100BASEFXHD		RTS_IEC_UDINT_C(0x11)	/* 100BASE-FX half duplex mode */
#define SYSETH_MAUTYPE_100BASEFXFD		RTS_IEC_UDINT_C(0x12)	/* 100BASE-FX full duplex mode */
#define SYSETH_MAUTYPE_100BASET2HD		RTS_IEC_UDINT_C(0x13)	/* 100BASE-T2 half duplex mode */
#define SYSETH_MAUTYPE_100BASET2FD		RTS_IEC_UDINT_C(0x14)	/* 100BASE-T2 full duplex mode */
#define SYSETH_MAUTYPE_1000BASEXHD		RTS_IEC_UDINT_C(0x15)	/* 1000BASE-X half duplex mode */
#define SYSETH_MAUTYPE_1000BASEXFD		RTS_IEC_UDINT_C(0x16)	/* 1000BASE-X full duplex mode */
#define SYSETH_MAUTYPE_1000BASELXHD		RTS_IEC_UDINT_C(0x17)	/* 1000BASE-LX half duplex mode */
#define SYSETH_MAUTYPE_1000BASELXFD		RTS_IEC_UDINT_C(0x18)	/* 1000BASE-LX full duplex mode */
#define SYSETH_MAUTYPE_1000BASESXHD		RTS_IEC_UDINT_C(0x19)	/* 1000BASE-SX half duplex mode */
#define SYSETH_MAUTYPE_1000BASESXFD		RTS_IEC_UDINT_C(0x1A)	/* 1000BASE-SX full duplex mode */
#define SYSETH_MAUTYPE_1000BASECXHD		RTS_IEC_UDINT_C(0x1B)	/* 1000BASE-CX half duplex mode */
#define SYSETH_MAUTYPE_1000BASECXFD		RTS_IEC_UDINT_C(0x1C)	/* 1000BASE-CX full duplex mode */
#define SYSETH_MAUTYPE_1000BASETHD		RTS_IEC_UDINT_C(0x1D)	/* 1000BASE-T half duplex mode */
#define SYSETH_MAUTYPE_1000BASETFD		RTS_IEC_UDINT_C(0x1E)	/* 1000BASE-T full duplex mode */
#define SYSETH_MAUTYPE_10GBASEX		RTS_IEC_UDINT_C(0x1F)	/* 10GBASE-X */
#define SYSETH_MAUTYPE_10GBASELX4		RTS_IEC_UDINT_C(0x20)	/* 10GBASE-LX4 */
#define SYSETH_MAUTYPE_10GBASER		RTS_IEC_UDINT_C(0x21)	/* 10GBASE-R */
#define SYSETH_MAUTYPE_10GBASEER		RTS_IEC_UDINT_C(0x22)	/* 10GBASE-ER */
#define SYSETH_MAUTYPE_10GBASELR		RTS_IEC_UDINT_C(0x23)	/* 10GBASE-LR */
#define SYSETH_MAUTYPE_10GBASESR		RTS_IEC_UDINT_C(0x24)	/* 10GBASE-SR */
#define SYSETH_MAUTYPE_10GBASEW		RTS_IEC_UDINT_C(0x25)	/* 10GBASE-W */
#define SYSETH_MAUTYPE_10GBASEEW		RTS_IEC_UDINT_C(0x26)	/* 10GBASE-EW */
#define SYSETH_MAUTYPE_10GBASELW		RTS_IEC_UDINT_C(0x27)	/* 10GBASE-LW */
#define SYSETH_MAUTYPE_10GBASESW		RTS_IEC_UDINT_C(0x28)	/* 10GBASE-SW */
#define SYSETH_MAUTYPE_10GBASECX4		RTS_IEC_UDINT_C(0x29)	/* 10GBASE-CX4 */
#define SYSETH_MAUTYPE_2BASETL		RTS_IEC_UDINT_C(0x2A)	/* 2BASE-TL */
#define SYSETH_MAUTYPE_10PASSTS		RTS_IEC_UDINT_C(0x2B)	/* 10PASS-TS */
#define SYSETH_MAUTYPE_100BASEBX10D		RTS_IEC_UDINT_C(0x2C)	/* 100BASE-BX10D */
#define SYSETH_MAUTYPE_100BASEBX10U		RTS_IEC_UDINT_C(0x2D)	/* 100BASE-BX10U */
#define SYSETH_MAUTYPE_100BASELX10		RTS_IEC_UDINT_C(0x2E)	/* 100BASE-LX10 */
#define SYSETH_MAUTYPE_1000BASEBX10D		RTS_IEC_UDINT_C(0x2F)	/* 1000BASE-BX10D */
#define SYSETH_MAUTYPE_1000BASEBX10U		RTS_IEC_UDINT_C(0x30)	/* 1000BASE-BX10U */
#define SYSETH_MAUTYPE_1000BASELX10		RTS_IEC_UDINT_C(0x31)	/* 1000BASE-LX10 */
#define SYSETH_MAUTYPE_1000BASEPX10D		RTS_IEC_UDINT_C(0x32)	/* 1000BASE-PX10D */
#define SYSETH_MAUTYPE_1000BASEPX10U		RTS_IEC_UDINT_C(0x33)	/* 1000BASE-PX10U */
#define SYSETH_MAUTYPE_1000BASEPX20D		RTS_IEC_UDINT_C(0x34)	/* 1000BASE-PX20D */
#define SYSETH_MAUTYPE_1000BASEPX20U		RTS_IEC_UDINT_C(0x35)	/* 1000BASE-PX20U */
#define SYSETH_MAUTYPE_10GBASET		RTS_IEC_UDINT_C(0x36)	/* 10GBASE-T */
#define SYSETH_MAUTYPE_10GBASELRM		RTS_IEC_UDINT_C(0x37)	/* 10GBASE-LRM */
#define SYSETH_MAUTYPE_1000BASEKX		RTS_IEC_UDINT_C(0x38)	/* 1000BASE-KX */
#define SYSETH_MAUTYPE_10GBASEKX4		RTS_IEC_UDINT_C(0x39)	/* 10GBASE-KX4 */
#define SYSETH_MAUTYPE_10GBASEKR		RTS_IEC_UDINT_C(0x3A)	/* 10GBASE-KR */
#define SYSETH_MAUTYPE_10G1GBASEPRXD1		RTS_IEC_UDINT_C(0x3B)	/* 10/1GBASE-PRX-D1 */
#define SYSETH_MAUTYPE_10G1GBASEPRXD2		RTS_IEC_UDINT_C(0x3C)	/* 10/1GBASE-PRX-D2 */
#define SYSETH_MAUTYPE_10G1GBASEPRXD3		RTS_IEC_UDINT_C(0x3D)	/* 10/1GBASE-PRX-D3 */
#define SYSETH_MAUTYPE_10G1GBASEPRXU1		RTS_IEC_UDINT_C(0x3E)	/* 10/1GBASE-PRX-U1 */
#define SYSETH_MAUTYPE_10G1GBASEPRXU2		RTS_IEC_UDINT_C(0x3F)	/* 10/1GBASE-PRX-U2 */
#define SYSETH_MAUTYPE_10G1GBASEPRXU3		RTS_IEC_UDINT_C(0x40)	/* 10/1GBASE-PRX-U3 */
#define SYSETH_MAUTYPE_10GBASEPRD1		RTS_IEC_UDINT_C(0x41)	/* 10GBASE-PR-D1 */
#define SYSETH_MAUTYPE_10GBASEPRD2		RTS_IEC_UDINT_C(0x42)	/* 10GBASE-PR-D2 */
#define SYSETH_MAUTYPE_10GBASEPRD3		RTS_IEC_UDINT_C(0x43)	/* 10GBASE-PR-D3 */
#define SYSETH_MAUTYPE_10GBASEPRU1		RTS_IEC_UDINT_C(0x44)	/* 10GBASE-PR-U1 */
#define SYSETH_MAUTYPE_10GBASEPRU3		RTS_IEC_UDINT_C(0x45)	/* 10GBASE-PR-U3 */
#define SYSETH_MAUTYPE_40GBASEKR4		RTS_IEC_UDINT_C(0x46)	/* 40GBASE-KR4 */
#define SYSETH_MAUTYPE_40GBASECR4		RTS_IEC_UDINT_C(0x47)	/* 40GBASE-CR4 */
#define SYSETH_MAUTYPE_40GBASESR4		RTS_IEC_UDINT_C(0x48)	/* 40GBASE-SR4 */
#define SYSETH_MAUTYPE_40GBASEFR		RTS_IEC_UDINT_C(0x49)	/* 40GBASE-FR */
#define SYSETH_MAUTYPE_40GBASELR4		RTS_IEC_UDINT_C(0x4A)	/* 40GBASE-LR4 */
#define SYSETH_MAUTYPE_100GBASECR10		RTS_IEC_UDINT_C(0x4B)	/* 100GBASE-CR10 */
#define SYSETH_MAUTYPE_100GBASESR10		RTS_IEC_UDINT_C(0x4C)	/* 100GBASE-SR10 */
#define SYSETH_MAUTYPE_100GBASELR4		RTS_IEC_UDINT_C(0x4D)	/* 100GBASE-LR4 */
#define SYSETH_MAUTYPE_100GBASEER4		RTS_IEC_UDINT_C(0x4E)	/* 100GBASE-ER4 */
#define SYSETH_MAUTYPE_1000BASET1		RTS_IEC_UDINT_C(0x4F)	/* 1000BASE-T1 */
#define SYSETH_MAUTYPE_1000BASEPX30D		RTS_IEC_UDINT_C(0x50)	/* 1000BASE-PX30D */
#define SYSETH_MAUTYPE_1000BASEPX30U		RTS_IEC_UDINT_C(0x51)	/* 1000BASE-PX30U */
#define SYSETH_MAUTYPE_1000BASEPX40D		RTS_IEC_UDINT_C(0x52)	/* 1000BASE-PX40D */
#define SYSETH_MAUTYPE_1000BASEPX40U		RTS_IEC_UDINT_C(0x53)	/* 1000BASE-PX40U */
#define SYSETH_MAUTYPE_10G1GBASEPRXD4		RTS_IEC_UDINT_C(0x54)	/* 10/1GBASE-PRX-D4 */
#define SYSETH_MAUTYPE_10G1GBASEPRXU4		RTS_IEC_UDINT_C(0x55)	/* 10/1GBASE-PRX-U4 */
#define SYSETH_MAUTYPE_10GBASEPRD4		RTS_IEC_UDINT_C(0x56)	/* 10GBASE-PRD4 */
#define SYSETH_MAUTYPE_10GBASEPRU4		RTS_IEC_UDINT_C(0x57)	/* 10GBASE-PRU4 */
#define SYSETH_MAUTYPE_25GBASECR		RTS_IEC_UDINT_C(0x58)	/* 25GBASE-CR */
#define SYSETH_MAUTYPE_25GBASECRS		RTS_IEC_UDINT_C(0x59)	/* 25GBASE-CR-S */
#define SYSETH_MAUTYPE_25GBASEKR		RTS_IEC_UDINT_C(0x5A)	/* 25GBASE-KR */
#define SYSETH_MAUTYPE_25GBASEKRS		RTS_IEC_UDINT_C(0x5B)	/* 25GBASE-KR-S */
#define SYSETH_MAUTYPE_25GBASER		RTS_IEC_UDINT_C(0x5C)	/* 25GBASE-R */
#define SYSETH_MAUTYPE_25GBASESR		RTS_IEC_UDINT_C(0x5D)	/* 25GBASE-SR */
#define SYSETH_MAUTYPE_25GBASET		RTS_IEC_UDINT_C(0x5E)	/* 25GBASE-T */
#define SYSETH_MAUTYPE_40GBASEER4		RTS_IEC_UDINT_C(0x5F)	/* 40GBASE-ER4 */
#define SYSETH_MAUTYPE_40GBASER		RTS_IEC_UDINT_C(0x60)	/* 40GBASE-R */
#define SYSETH_MAUTYPE_40GBASET		RTS_IEC_UDINT_C(0x61)	/* 40GBASE-T */
#define SYSETH_MAUTYPE_100GBASECR4		RTS_IEC_UDINT_C(0x62)	/* 100GBASE-CR4 */
#define SYSETH_MAUTYPE_100GBASEKR4		RTS_IEC_UDINT_C(0x63)	/* 100GBASE-KR4 */
#define SYSETH_MAUTYPE_100GBASEKP4		RTS_IEC_UDINT_C(0x64)	/* 100GBASE-KP4 */
#define SYSETH_MAUTYPE_100GBASER		RTS_IEC_UDINT_C(0x65)	/* 100GBASE-R */
#define SYSETH_MAUTYPE_100GBASESR4		RTS_IEC_UDINT_C(0x66)	/* 100GBASE-SR4 */

/**
 * <description>OperStatus</description>
 */
#define SYSETH_OPERSTAT_UP		RTS_IEC_UINT_C(0x1)	/* ready to pass packets */
#define SYSETH_OPERSTAT_DOWN		RTS_IEC_UINT_C(0x2)	/* down and not in a condition to pass packets */
#define SYSETH_OPERSTAT_TESTING		RTS_IEC_UINT_C(0x3)	/* in some test mode */
#define SYSETH_OPERSTAT_UNKNOWN		RTS_IEC_UINT_C(0x4)	/* status can not be determined for some reason */
#define SYSETH_OPERSTAT_DORMANT		RTS_IEC_UINT_C(0x5)	/* not up, pending state */
#define SYSETH_OPERSTAT_NOTPRESENT		RTS_IEC_UINT_C(0x6)	/* some component e. g. a hardware device is missing */
#define SYSETH_OPERSTAT_LOWERLAYERDOWN		RTS_IEC_UINT_C(0x7)	/* down due to state of lower-layer interface(s) */

/**
 * <description>ETCStructCommand</description>
 */
typedef struct tagETCStructCommand
{
	RTS_IEC_BYTE byCmd;		
	RTS_IEC_BYTE byIdx;		
	RTS_IEC_WORD wAddress1;		
	RTS_IEC_WORD wAddress2;		/* is offset, when not part of logical address */
	RTS_IEC_WORD wLength;		/* top 11 bit are length, bit 15 is follow indication */
	RTS_IEC_WORD wIrq;		/* reserved */
	RTS_IEC_BYTE abyData[1488];		
	RTS_IEC_WORD wWctr;		/* working counter may be found earlier in packet - valid only  for maximum size */
} ETCStructCommand;

/**
 * <description>StructEthernetframe</description>
 */
typedef struct tagStructEthernetframe
{
	RTS_IEC_BYTE dest_mac[6];		
	RTS_IEC_BYTE source_mac[6];		
	RTS_IEC_WORD ethtype;		
	RTS_IEC_BYTE ethlength;		
	RTS_IEC_BYTE ethservice;		
	ETCStructCommand first;		
} StructEthernetframe;

/**
 * The "Capability Bits" of EIP 
 * plus a quality flag for each value and a struct version.
 * 
 * Quality Flags used in the runtime interface for reading the Ethernet interface settings.
 * 
 * These quality flags are not from the EIP specification, but were added by CODESYS.
 * The idea behind this is
 * to be able to say for each individual value of the respective STRUCT
 * whether it has been filled correctly by the platform implementation.
 * 
 * Possible quality flags are:
 * - ERR_OK: Value could be determined without errors
 * - ERR_NOTIMPLEMENTED: Not implemented by this platform implementation
 * - ERR_NOT_SUPPORTED: Not supported by this platform implementation
 * - ERR_FAILED: Error: Value could not be determined
 */
typedef struct tagSysEthernetCapabilities
{
	RTS_IEC_DWORD structVersion;		/* Version number of this struct. This is version 1. To be increased on changes. */
	RTS_IEC_BOOL manualSettingRequiresReset;		/* Indicates whether or not the device requires a reset to apply changes made to the Interface Control attribute (#6). 
 0 = Indicates that the device automatically applies changes made to the Interface Control attribute (#6) and, therefore, does not require a reset in order for changes to take effect.  This is the value this bit shall have when the Interface Control attribute (#6) is not implemented. 
 1 = Indicates that the device does not automatically apply changes made to the Interface Control attribute (#6) and, therefore, will require a reset in order for changes to take effect. Note: this bit shall also be replicated in the Interface Flags attribute (#2) in order to retain backwards compatibility with previous object revisions. */
	RTS_IEC_BOOL autoNegotiate;		/* 0 = Indicates that the interface does not support link auto-negotiation 
 1 = Indicates that the interface supports link auto-negotiation */
	RTS_IEC_BOOL autoMdix;		/* 0 = Indicates that the interface does not support auto MDIX operation 
 1 = Indicates that the interface supports auto MDIX operation */
	RTS_IEC_BOOL manualSpeedDuplex;		/* 0 = Indicates that the interface does not support manual setting of speed/duplex. The Interface Control attribute (#6) shall not be supported.  
 1 = Indicates that the interface supports manual setting of speed/duplex via the Interface Control attribute (#6) */
	RTS_IEC_RESULT manualSettingRequiresResetQuality;		
	RTS_IEC_RESULT autoNegotiateQuality;		
	RTS_IEC_RESULT autoMdixQuality;		
	RTS_IEC_RESULT manualSpeedDuplexQuality;		
} SysEthernetCapabilities;

/**
 * <description>SysEthernetFrame</description>
 */
typedef struct tagSysEthernetFrame
{
	RTS_IEC_UDINT udFrameLen;		
	RTS_IEC_BYTE ethData[1522];		
} SysEthernetFrame;

/**
 * The "HC Interface Counters" and the "Interface Counters" of EIP 
 * plus a quality flag for each value and a struct version.
 * 
 * Quality Flags used in the runtime interface for reading the Ethernet interface settings.
 * 
 * These quality flags are not from the EIP specification, but were added by CODESYS.
 * The idea behind this is
 * to be able to say for each individual value of the respective STRUCT
 * whether it has been filled correctly by the platform implementation.
 * 
 * Possible quality flags are:
 * - ERR_OK: Value could be determined without errors
 * - ERR_NOTIMPLEMENTED: Not implemented by this platform implementation
 * - ERR_NOT_SUPPORTED: Not supported by this platform implementation
 * - ERR_FAILED: Error: Value could not be determined
 */
typedef struct tagSysEthernetInterfaceCounters
{
	RTS_IEC_DWORD structVersion;		/* Version number of this struct. This is version 1. To be increased on changes. */
	RTS_IEC_DWORD ifInNUcastPkts;		/* RFC 2863  InNUcastPackets:
	The number of packets, delivered by this sub-layer to a
	higher (sub-)layer, which were addressed to a multicast or
	broadcast address at this sub-layer. */
	RTS_IEC_DWORD ifInDiscards;		/* RFC 2863  InDiscards:
	The number of inbound packets which were chosen to be
	discarded even though no errors had been detected to prevent
	their being deliverable to a higher-layer protocol. One
	possible reason for discarding such a packet could be to
	free up buffer space. */
	RTS_IEC_DWORD ifInErrors;		/* RFC 2863  InErrors:
	For packet-oriented interfaces, the number of inbound
	packets that contained errors preventing them from being
	deliverable to a higher-layer protocol. For character-
	oriented or fixed-length interfaces, the number of inbound
	transmission units that contained errors preventing them
	from being deliverable to a higher-layer protocol. */
	RTS_IEC_DWORD ifInUnknownProtos;		/* RFC 2863  InUnknownProtos:
	For packet-oriented interfaces, the number of packets
	received via the interface which were discarded because of
	an unknown or unsupported protocol. For character-oriented
	or fixed-length interfaces that support protocol
	multiplexing the number of transmission units received via
	the interface which were discarded because of an unknown or
	unsupported protocol. For any interface that does not
	support protocol multiplexing, this counter will always be
	0. */
	RTS_IEC_DWORD ifOutNUcastPkts;		/* RFC 2863  OutNUcastPkts:
	The total number of packets that higher-level protocols
	requested be transmitted, and which were addressed to a
	multicast or broadcast address at this sub-layer, including
	those that were discarded or not sent. */
	RTS_IEC_DWORD ifOutDiscards;		/* RFC 2863  OutDiscards:
	The number of outbound packets which were chosen to be
	discarded even though no errors had been detected to prevent
	their being transmitted. One possible reason for discarding
	such a packet could be to free up buffer space. */
	RTS_IEC_DWORD ifOutErrors;		/* RFC 2863  OutErrors:
	For packet-oriented interfaces, the number of outbound
	packets that could not be transmitted because of errors.
	For character-oriented or fixed-length interfaces, the
	number of outbound transmission units that could not be
	transmitted because of errors. */
	RTS_IEC_LWORD hcInOctets;		/* The total number of octets received on the interface. This counter is a 64-bit version of In Octets. */
	RTS_IEC_LWORD hcInUcastPkts;		/* Unicast packets received on the interface. This counter is a 64-bit version of In Ucast Packets. */
	RTS_IEC_LWORD hcInMulticastPkts;		/* Multicast packets received on the interface. */
	RTS_IEC_LWORD hcInBroadcastPkts;		/* Broadcast packets received on the interface. */
	RTS_IEC_LWORD hcOutOctets;		/* Octets sent on the interface. This counter is a 64-bit version of Out Octets. */
	RTS_IEC_LWORD hcOutUcastPkts;		/* Unicast packets sent on the interface.  This counter is a 64-bit version of Out Ucast Packets. */
	RTS_IEC_LWORD hcOutMulticastPkts;		/* Multicast packets sent on the interface. */
	RTS_IEC_LWORD hcOutBroadcastPkts;		/* Broadcast packets sent on the interface. */
	RTS_IEC_RESULT ifInNUcastPktsQuality;		
	RTS_IEC_RESULT ifInDiscardsQuality;		
	RTS_IEC_RESULT ifInErrorsQuality;		
	RTS_IEC_RESULT ifInUnknownProtosQuality;		
	RTS_IEC_RESULT ifOutNUcastPktsQuality;		
	RTS_IEC_RESULT ifOutDiscardsQuality;		
	RTS_IEC_RESULT ifOutErrorsQuality;		
	RTS_IEC_RESULT hcInOctetsQuality;		
	RTS_IEC_RESULT hcInUcastPktsQuality;		
	RTS_IEC_RESULT hcInMulticastPktsQuality;		
	RTS_IEC_RESULT hcInBroadcastPktsQuality;		
	RTS_IEC_RESULT hcOutOctetsQuality;		
	RTS_IEC_RESULT hcOutUcastPktsQuality;		
	RTS_IEC_RESULT hcOutMulticastPktsQuality;		
	RTS_IEC_RESULT hcOutBroadcastPktsQuality;		
} SysEthernetInterfaceCounters;

/**
 * The "HC Media Counters" and the "Media Counters" of EIP 
 * plus a quality flag for each value and a struct version.
 * 
 * Quality Flags used in the runtime interface for reading the Ethernet interface settings.
 * 
 * These quality flags are not from the EIP specification, but were added by CODESYS.
 * The idea behind this is
 * to be able to say for each individual value of the respective STRUCT
 * whether it has been filled correctly by the platform implementation.
 * 
 * Possible quality flags are:
 * - ERR_OK: Value could be determined without errors
 * - ERR_NOTIMPLEMENTED: Not implemented by this platform implementation
 * - ERR_NOT_SUPPORTED: Not supported by this platform implementation
 * - ERR_FAILED: Error: Value could not be determined
 */
typedef struct tagSysEthernetMediaCounters
{
	RTS_IEC_DWORD structVersion;		/* Version number of this struct. This is version 1. To be increased on changes. */
	RTS_IEC_DWORD dot3StatsSingleCollisionFrames;		/* RFC 3635  Single Collisions:
	A count of frames that are involved in a single
    collision, and are subsequently transmitted
    successfully.
    A frame that is counted by an instance of this
    object is also counted by the corresponding
    instance of either the ifOutUcastPkts,
    ifOutMulticastPkts, or ifOutBroadcastPkts,
    and is not counted by the corresponding
    instance of the dot3StatsMultipleCollisionFrames
    object.
    This counter does not increment when the
    interface is operating in full-duplex mode. */
	RTS_IEC_DWORD dot3StatsMultipleCollisionFrames;		/* RFC 3635  Multiple Collisions:
	A count of frames that are involved in more
	than one collision and are subsequently
    transmitted successfully.
    A frame that is counted by an instance of this
    object is also counted by the corresponding
    instance of either the ifOutUcastPkts,
    ifOutMulticastPkts, or ifOutBroadcastPkts,
    and is not counted by the corresponding
    instance of the dot3StatsSingleCollisionFrames
    object.
    This counter does not increment when the
    interface is operating in full-duplex mode. */
	RTS_IEC_DWORD dot3StatsSQETestErrors;		/* RFC 3635  SQE Test Errors:
	A count of times that the SQE TEST ERROR
    is received on a particular interface. The
    SQE TEST ERROR is set in accordance with the
    rules for verification of the SQE detection
    mechanism in the PLS Carrier Sense Function as
    described in IEEE Std. 802.3, 2000 Edition,
    section 7.2.4.6.
    This counter does not increment on interfaces
    operating at speeds greater than 10 Mb/s, or on
    interfaces operating in full-duplex mode. */
	RTS_IEC_DWORD dot3StatsDeferredTransmissions;		/* RFC 3635  Deferred Transmissions:
	A count of frames for which the first
    transmission attempt on a particular interface
    is delayed because the medium is busy.
    The count represented by an instance of this
    object does not include frames involved in
    collisions.
    This counter does not increment when the
    interface is operating in full-duplex mode. */
	RTS_IEC_DWORD dot3StatsLateCollisions;		/* RFC 3635  Late Collisions:
	The number of times that a collision is
    detected on a particular interface later than
    one slotTime into the transmission of a packet.
    A (late) collision included in a count
    represented by an instance of this object is
    also considered as a (generic) collision for
    purposes of other collision-related
    statistics.
    This counter does not increment when the
    interface is operating in full-duplex mode. */
	RTS_IEC_DWORD dot3StatsExcessiveCollisions;		/* RFC 3635  Excessive Collisions:
	A count of frames for which transmission on a
    particular interface fails due to excessive
    collisions.
    This counter does not increment when the
    interface is operating in full-duplex mode. */
	RTS_IEC_DWORD dot3StatsCarrierSenseErrors;		/* RFC 3635  Carrier Sense Errors:
	The number of times that the carrier sense
    condition was lost or never asserted when
    attempting to transmit a frame on a particular
    interface.
    The count represented by an instance of this
    object is incremented at most once per
    transmission attempt, even if the carrier sense
    condition fluctuates during a transmission
    attempt.
    This counter does not increment when the
    interface is operating in full-duplex mode. */
	RTS_IEC_LWORD hcStatsAlignmentErrors;		/* Frames received that are not an integral number of octets in length and do not pass the FCS check. This counter is a 64-bit version of Alignment Errors. */
	RTS_IEC_LWORD hcStatsFCSErrors;		/* Frames received that are an integral number of octets in length but do not pass the FCS check.  This counter is a 64-bit version of FCS Errors. */
	RTS_IEC_LWORD hcStatsInternalMacTransmitErrors;		/* Frames for which transmission fails due to an internal MAC sublayer transmit error.  This counter is a 64-bit version of MAC Transmit Errors. */
	RTS_IEC_LWORD hcStatsFrameTooLongs;		/* Frames received that exceed the maximum permitted frame size.  This counter is a 64-bit version of Frame Too Long Errors. */
	RTS_IEC_LWORD hcStatsInternalMacReceiveErrors;		/* Frames for which reception on an interface fails due to an internal MAC sublayer receive error.  This counter is a 64-bit version of MAC Receive Errors. */
	RTS_IEC_LWORD hcStatsSymbolErrors;		/* Number of times there was an invalid data symbol on the media when a valid carrier was present. */
	RTS_IEC_RESULT dot3StatsAlignmentErrorsQuality;		
	RTS_IEC_RESULT dot3StatsFCSErrorsQuality;		
	RTS_IEC_RESULT dot3StatsSingleCollisionFramesQuality;		
	RTS_IEC_RESULT dot3StatsMultipleCollisionFramesQuality;		
	RTS_IEC_RESULT dot3StatsSQETestErrorsQuality;		
	RTS_IEC_RESULT dot3StatsDeferredTransmissionsQuality;		
	RTS_IEC_RESULT dot3StatsLateCollisionsQuality;		
	RTS_IEC_RESULT dot3StatsExcessiveCollisionsQuality;		
	RTS_IEC_RESULT dot3StatsInternalMacTransmitErrorsQuality;		
	RTS_IEC_RESULT dot3StatsCarrierSenseErrorsQuality;		
	RTS_IEC_RESULT dot3StatsFrameTooLongsQuality;		
	RTS_IEC_RESULT dot3StatsInternalMacReceiveErrorsQuality;		
	RTS_IEC_RESULT hcStatsAlignmentErrorsQuality;		
	RTS_IEC_RESULT hcStatsFCSErrorsQuality;		
	RTS_IEC_RESULT hcStatsInternalMacTransmitErrorsQuality;		
	RTS_IEC_RESULT hcStatsFrameTooLongsQuality;		
	RTS_IEC_RESULT hcStatsInternalMacReceiveErrorsQuality;		
	RTS_IEC_RESULT hcStatsSymbolErrorsQuality;		
} SysEthernetMediaCounters;

/**
 * Structure containing the Ethernet port configuration and status
 */
typedef struct tagSysEthernetPortConfigAndStatus
{
	RTS_IEC_UDINT udiStructSize;		/* Size of the structure SysEthernetPortConfigAndStatus returned from external implementation */
	RTS_IEC_UDINT udiVersion;		/* Version number of the structure */
	RTS_IEC_UDINT udiMauType;		/* Media Access Unit (MAU) type, see MauType constants SYSETH_MAUTYPE_... */
	RTS_IEC_UINT uiOperStatus;		/* Link state of Ethernet port, see OperStatus constants SYSETH_OPERSTAT_... */
	RTS_IEC_USINT usiAutoNegSupport;		/* Auto-negotiation support of MAU, see AutoNegSupport constants SYSETH_AUTONEGSUP_... */
	RTS_IEC_USINT usiAutoNegMode;		/* Auto-negotiation mode of MAU, see AutoNegMode constants SYSETH_AUTONEGMODE_... */
	RTS_IEC_ULINT uliAutoNegSupportedCap;		/* Supported auto-negotiation capabilities of MAU, see AutoNegCaps constants SYSETH_AUTONEGCAP_... */
	RTS_IEC_ULINT uliAutoNegAdvertisedCap;		/* Advertised auto-negotiation capabilities of MAU, see AutoNegCaps constants SYSETH_AUTONEGCAP_... */
} SysEthernetPortConfigAndStatus;

/**
 * Close a Ethernet adapter.
 */
typedef struct tagsysethernetadapterclose_struct
{
	RTS_IEC_HANDLE hAdapter;			/* VAR_INPUT */	/* Handle to the opened Ethernet adapter. Retrieved using SysEthernetAdapterOpen() */
	RTS_IEC_RESULT SysEthernetAdapterClose;	/* VAR_OUTPUT */	
} sysethernetadapterclose_struct;

void CDECL CDECL_EXT sysethernetadapterclose(sysethernetadapterclose_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSETHERNETADAPTERCLOSE_IEC) (sysethernetadapterclose_struct *p);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(SYSETHERNETADAPTERCLOSE_NOTIMPLEMENTED)
	#define USE_sysethernetadapterclose
	#define EXT_sysethernetadapterclose
	#define GET_sysethernetadapterclose(fl)  ERR_NOTIMPLEMENTED
	#define CAL_sysethernetadapterclose(p0) 
	#define CHK_sysethernetadapterclose  FALSE
	#define EXP_sysethernetadapterclose  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_sysethernetadapterclose
	#define EXT_sysethernetadapterclose
	#define GET_sysethernetadapterclose(fl)  CAL_CMGETAPI( "sysethernetadapterclose" ) 
	#define CAL_sysethernetadapterclose  sysethernetadapterclose
	#define CHK_sysethernetadapterclose  TRUE
	#define EXP_sysethernetadapterclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetadapterclose", (RTS_UINTPTR)sysethernetadapterclose, 1, 0x3AF33BA1, 0x03051100) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_sysethernetadapterclose
	#define EXT_sysethernetadapterclose
	#define GET_sysethernetadapterclose(fl)  CAL_CMGETAPI( "sysethernetadapterclose" ) 
	#define CAL_sysethernetadapterclose  sysethernetadapterclose
	#define CHK_sysethernetadapterclose  TRUE
	#define EXP_sysethernetadapterclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetadapterclose", (RTS_UINTPTR)sysethernetadapterclose, 1, 0x3AF33BA1, 0x03051100) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetsysethernetadapterclose
	#define EXT_SysEthernetsysethernetadapterclose
	#define GET_SysEthernetsysethernetadapterclose  ERR_OK
	#define CAL_SysEthernetsysethernetadapterclose  sysethernetadapterclose
	#define CHK_SysEthernetsysethernetadapterclose  TRUE
	#define EXP_SysEthernetsysethernetadapterclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetadapterclose", (RTS_UINTPTR)sysethernetadapterclose, 1, 0x3AF33BA1, 0x03051100) 
#elif defined(CPLUSPLUS)
	#define USE_sysethernetadapterclose
	#define EXT_sysethernetadapterclose
	#define GET_sysethernetadapterclose(fl)  CAL_CMGETAPI( "sysethernetadapterclose" ) 
	#define CAL_sysethernetadapterclose  sysethernetadapterclose
	#define CHK_sysethernetadapterclose  TRUE
	#define EXP_sysethernetadapterclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetadapterclose", (RTS_UINTPTR)sysethernetadapterclose, 1, 0x3AF33BA1, 0x03051100) 
#else /* DYNAMIC_LINK */
	#define USE_sysethernetadapterclose  PFSYSETHERNETADAPTERCLOSE_IEC pfsysethernetadapterclose;
	#define EXT_sysethernetadapterclose  extern PFSYSETHERNETADAPTERCLOSE_IEC pfsysethernetadapterclose;
	#define GET_sysethernetadapterclose(fl)  s_pfCMGetAPI2( "sysethernetadapterclose", (RTS_VOID_FCTPTR *)&pfsysethernetadapterclose, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x3AF33BA1, 0x03051100)
	#define CAL_sysethernetadapterclose  pfsysethernetadapterclose
	#define CHK_sysethernetadapterclose  (pfsysethernetadapterclose != NULL)
	#define EXP_sysethernetadapterclose   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetadapterclose", (RTS_UINTPTR)sysethernetadapterclose, 1, 0x3AF33BA1, 0x03051100) 
#endif


/**
 * Open an Ethernet adapter by its MAC address.
 * .. note::
 *    Each adapter can only be opened once.
 * :return: Returns a handle to the opened adapter. SysTypes.RTS_INVALID_HANDLE is returned if the operation failed.
 */
typedef struct tagsysethernetadapteropen_struct
{
	RTS_IEC_BYTE macAddress[6];			/* VAR_INPUT */	/* MAC address of the adapter to be opened. */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Result of the operation */
	RTS_IEC_HANDLE SysEthernetAdapterOpen;	/* VAR_OUTPUT */	
} sysethernetadapteropen_struct;

void CDECL CDECL_EXT sysethernetadapteropen(sysethernetadapteropen_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSETHERNETADAPTEROPEN_IEC) (sysethernetadapteropen_struct *p);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(SYSETHERNETADAPTEROPEN_NOTIMPLEMENTED)
	#define USE_sysethernetadapteropen
	#define EXT_sysethernetadapteropen
	#define GET_sysethernetadapteropen(fl)  ERR_NOTIMPLEMENTED
	#define CAL_sysethernetadapteropen(p0) 
	#define CHK_sysethernetadapteropen  FALSE
	#define EXP_sysethernetadapteropen  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_sysethernetadapteropen
	#define EXT_sysethernetadapteropen
	#define GET_sysethernetadapteropen(fl)  CAL_CMGETAPI( "sysethernetadapteropen" ) 
	#define CAL_sysethernetadapteropen  sysethernetadapteropen
	#define CHK_sysethernetadapteropen  TRUE
	#define EXP_sysethernetadapteropen  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetadapteropen", (RTS_UINTPTR)sysethernetadapteropen, 1, 0x7E26ED8D, 0x03051100) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_sysethernetadapteropen
	#define EXT_sysethernetadapteropen
	#define GET_sysethernetadapteropen(fl)  CAL_CMGETAPI( "sysethernetadapteropen" ) 
	#define CAL_sysethernetadapteropen  sysethernetadapteropen
	#define CHK_sysethernetadapteropen  TRUE
	#define EXP_sysethernetadapteropen  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetadapteropen", (RTS_UINTPTR)sysethernetadapteropen, 1, 0x7E26ED8D, 0x03051100) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetsysethernetadapteropen
	#define EXT_SysEthernetsysethernetadapteropen
	#define GET_SysEthernetsysethernetadapteropen  ERR_OK
	#define CAL_SysEthernetsysethernetadapteropen  sysethernetadapteropen
	#define CHK_SysEthernetsysethernetadapteropen  TRUE
	#define EXP_SysEthernetsysethernetadapteropen  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetadapteropen", (RTS_UINTPTR)sysethernetadapteropen, 1, 0x7E26ED8D, 0x03051100) 
#elif defined(CPLUSPLUS)
	#define USE_sysethernetadapteropen
	#define EXT_sysethernetadapteropen
	#define GET_sysethernetadapteropen(fl)  CAL_CMGETAPI( "sysethernetadapteropen" ) 
	#define CAL_sysethernetadapteropen  sysethernetadapteropen
	#define CHK_sysethernetadapteropen  TRUE
	#define EXP_sysethernetadapteropen  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetadapteropen", (RTS_UINTPTR)sysethernetadapteropen, 1, 0x7E26ED8D, 0x03051100) 
#else /* DYNAMIC_LINK */
	#define USE_sysethernetadapteropen  PFSYSETHERNETADAPTEROPEN_IEC pfsysethernetadapteropen;
	#define EXT_sysethernetadapteropen  extern PFSYSETHERNETADAPTEROPEN_IEC pfsysethernetadapteropen;
	#define GET_sysethernetadapteropen(fl)  s_pfCMGetAPI2( "sysethernetadapteropen", (RTS_VOID_FCTPTR *)&pfsysethernetadapteropen, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x7E26ED8D, 0x03051100)
	#define CAL_sysethernetadapteropen  pfsysethernetadapteropen
	#define CHK_sysethernetadapteropen  (pfsysethernetadapteropen != NULL)
	#define EXP_sysethernetadapteropen   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetadapteropen", (RTS_UINTPTR)sysethernetadapteropen, 1, 0x7E26ED8D, 0x03051100) 
#endif


/**
 * This function receives the next Ethernet frame from the Ethernet adapter. A pointer to this frame
 * is returned.
 * ..note::
 *   The frame returned has to be released using the SysEthernetEthFrameRelease() function.
 *   The frame will only be overwritten if the frame is released. As frames are reused when
 *   released pay attention to call this function if processing of the frame has finished.
 * :return: Pointer to the Ethernet frame
 */
typedef struct tagsysethernetethframereceive_struct
{
	RTS_IEC_HANDLE hAdapter;			/* VAR_INPUT */	/* Ethernet adapter where to receive the frame. */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Result of the operation. */
	SysEthernetFrame *SysEthernetEthFrameReceive;	/* VAR_OUTPUT */	
} sysethernetethframereceive_struct;

void CDECL CDECL_EXT sysethernetethframereceive(sysethernetethframereceive_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSETHERNETETHFRAMERECEIVE_IEC) (sysethernetethframereceive_struct *p);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(SYSETHERNETETHFRAMERECEIVE_NOTIMPLEMENTED)
	#define USE_sysethernetethframereceive
	#define EXT_sysethernetethframereceive
	#define GET_sysethernetethframereceive(fl)  ERR_NOTIMPLEMENTED
	#define CAL_sysethernetethframereceive(p0) 
	#define CHK_sysethernetethframereceive  FALSE
	#define EXP_sysethernetethframereceive  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_sysethernetethframereceive
	#define EXT_sysethernetethframereceive
	#define GET_sysethernetethframereceive(fl)  CAL_CMGETAPI( "sysethernetethframereceive" ) 
	#define CAL_sysethernetethframereceive  sysethernetethframereceive
	#define CHK_sysethernetethframereceive  TRUE
	#define EXP_sysethernetethframereceive  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetethframereceive", (RTS_UINTPTR)sysethernetethframereceive, 1, 0xAA2055F3, 0x03051100) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_sysethernetethframereceive
	#define EXT_sysethernetethframereceive
	#define GET_sysethernetethframereceive(fl)  CAL_CMGETAPI( "sysethernetethframereceive" ) 
	#define CAL_sysethernetethframereceive  sysethernetethframereceive
	#define CHK_sysethernetethframereceive  TRUE
	#define EXP_sysethernetethframereceive  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetethframereceive", (RTS_UINTPTR)sysethernetethframereceive, 1, 0xAA2055F3, 0x03051100) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetsysethernetethframereceive
	#define EXT_SysEthernetsysethernetethframereceive
	#define GET_SysEthernetsysethernetethframereceive  ERR_OK
	#define CAL_SysEthernetsysethernetethframereceive  sysethernetethframereceive
	#define CHK_SysEthernetsysethernetethframereceive  TRUE
	#define EXP_SysEthernetsysethernetethframereceive  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetethframereceive", (RTS_UINTPTR)sysethernetethframereceive, 1, 0xAA2055F3, 0x03051100) 
#elif defined(CPLUSPLUS)
	#define USE_sysethernetethframereceive
	#define EXT_sysethernetethframereceive
	#define GET_sysethernetethframereceive(fl)  CAL_CMGETAPI( "sysethernetethframereceive" ) 
	#define CAL_sysethernetethframereceive  sysethernetethframereceive
	#define CHK_sysethernetethframereceive  TRUE
	#define EXP_sysethernetethframereceive  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetethframereceive", (RTS_UINTPTR)sysethernetethframereceive, 1, 0xAA2055F3, 0x03051100) 
#else /* DYNAMIC_LINK */
	#define USE_sysethernetethframereceive  PFSYSETHERNETETHFRAMERECEIVE_IEC pfsysethernetethframereceive;
	#define EXT_sysethernetethframereceive  extern PFSYSETHERNETETHFRAMERECEIVE_IEC pfsysethernetethframereceive;
	#define GET_sysethernetethframereceive(fl)  s_pfCMGetAPI2( "sysethernetethframereceive", (RTS_VOID_FCTPTR *)&pfsysethernetethframereceive, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xAA2055F3, 0x03051100)
	#define CAL_sysethernetethframereceive  pfsysethernetethframereceive
	#define CHK_sysethernetethframereceive  (pfsysethernetethframereceive != NULL)
	#define EXP_sysethernetethframereceive   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetethframereceive", (RTS_UINTPTR)sysethernetethframereceive, 1, 0xAA2055F3, 0x03051100) 
#endif


/**
 * This function sends an ethernetframe to the given adapter.
 * The data of the frame is copied to the adapter. When this function
 * returns the frame can be overwritten without any problems.
 */
typedef struct tagsysethernetethframesend_struct
{
	RTS_IEC_HANDLE hAdapter;			/* VAR_INPUT */	/* Ethernet adapter where to send the frame. */
	SysEthernetFrame *pFrame;			/* VAR_INPUT */	/* Pointer to the frame to send. */
	RTS_IEC_RESULT SysEthernetEthFrameSend;	/* VAR_OUTPUT */	
} sysethernetethframesend_struct;

void CDECL CDECL_EXT sysethernetethframesend(sysethernetethframesend_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSETHERNETETHFRAMESEND_IEC) (sysethernetethframesend_struct *p);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(SYSETHERNETETHFRAMESEND_NOTIMPLEMENTED)
	#define USE_sysethernetethframesend
	#define EXT_sysethernetethframesend
	#define GET_sysethernetethframesend(fl)  ERR_NOTIMPLEMENTED
	#define CAL_sysethernetethframesend(p0) 
	#define CHK_sysethernetethframesend  FALSE
	#define EXP_sysethernetethframesend  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_sysethernetethframesend
	#define EXT_sysethernetethframesend
	#define GET_sysethernetethframesend(fl)  CAL_CMGETAPI( "sysethernetethframesend" ) 
	#define CAL_sysethernetethframesend  sysethernetethframesend
	#define CHK_sysethernetethframesend  TRUE
	#define EXP_sysethernetethframesend  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetethframesend", (RTS_UINTPTR)sysethernetethframesend, 1, 0x9145ED7E, 0x03051100) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_sysethernetethframesend
	#define EXT_sysethernetethframesend
	#define GET_sysethernetethframesend(fl)  CAL_CMGETAPI( "sysethernetethframesend" ) 
	#define CAL_sysethernetethframesend  sysethernetethframesend
	#define CHK_sysethernetethframesend  TRUE
	#define EXP_sysethernetethframesend  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetethframesend", (RTS_UINTPTR)sysethernetethframesend, 1, 0x9145ED7E, 0x03051100) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetsysethernetethframesend
	#define EXT_SysEthernetsysethernetethframesend
	#define GET_SysEthernetsysethernetethframesend  ERR_OK
	#define CAL_SysEthernetsysethernetethframesend  sysethernetethframesend
	#define CHK_SysEthernetsysethernetethframesend  TRUE
	#define EXP_SysEthernetsysethernetethframesend  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetethframesend", (RTS_UINTPTR)sysethernetethframesend, 1, 0x9145ED7E, 0x03051100) 
#elif defined(CPLUSPLUS)
	#define USE_sysethernetethframesend
	#define EXT_sysethernetethframesend
	#define GET_sysethernetethframesend(fl)  CAL_CMGETAPI( "sysethernetethframesend" ) 
	#define CAL_sysethernetethframesend  sysethernetethframesend
	#define CHK_sysethernetethframesend  TRUE
	#define EXP_sysethernetethframesend  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetethframesend", (RTS_UINTPTR)sysethernetethframesend, 1, 0x9145ED7E, 0x03051100) 
#else /* DYNAMIC_LINK */
	#define USE_sysethernetethframesend  PFSYSETHERNETETHFRAMESEND_IEC pfsysethernetethframesend;
	#define EXT_sysethernetethframesend  extern PFSYSETHERNETETHFRAMESEND_IEC pfsysethernetethframesend;
	#define GET_sysethernetethframesend(fl)  s_pfCMGetAPI2( "sysethernetethframesend", (RTS_VOID_FCTPTR *)&pfsysethernetethframesend, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x9145ED7E, 0x03051100)
	#define CAL_sysethernetethframesend  pfsysethernetethframesend
	#define CHK_sysethernetethframesend  (pfsysethernetethframesend != NULL)
	#define EXP_sysethernetethframesend   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetethframesend", (RTS_UINTPTR)sysethernetethframesend, 1, 0x9145ED7E, 0x03051100) 
#endif


/**
 * Release a received frame to indicate that the frame can be reused.
 */
typedef struct tagsysethernetframerelease_struct
{
	SysEthernetFrame *pFrame;			/* VAR_INPUT */	/* Pointer to the frame to release */
	RTS_IEC_RESULT SysEthernetFrameRelease;	/* VAR_OUTPUT */	
} sysethernetframerelease_struct;

void CDECL CDECL_EXT sysethernetframerelease(sysethernetframerelease_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSETHERNETFRAMERELEASE_IEC) (sysethernetframerelease_struct *p);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(SYSETHERNETFRAMERELEASE_NOTIMPLEMENTED)
	#define USE_sysethernetframerelease
	#define EXT_sysethernetframerelease
	#define GET_sysethernetframerelease(fl)  ERR_NOTIMPLEMENTED
	#define CAL_sysethernetframerelease(p0) 
	#define CHK_sysethernetframerelease  FALSE
	#define EXP_sysethernetframerelease  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_sysethernetframerelease
	#define EXT_sysethernetframerelease
	#define GET_sysethernetframerelease(fl)  CAL_CMGETAPI( "sysethernetframerelease" ) 
	#define CAL_sysethernetframerelease  sysethernetframerelease
	#define CHK_sysethernetframerelease  TRUE
	#define EXP_sysethernetframerelease  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetframerelease", (RTS_UINTPTR)sysethernetframerelease, 1, 0xDF7EE900, 0x03051100) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_sysethernetframerelease
	#define EXT_sysethernetframerelease
	#define GET_sysethernetframerelease(fl)  CAL_CMGETAPI( "sysethernetframerelease" ) 
	#define CAL_sysethernetframerelease  sysethernetframerelease
	#define CHK_sysethernetframerelease  TRUE
	#define EXP_sysethernetframerelease  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetframerelease", (RTS_UINTPTR)sysethernetframerelease, 1, 0xDF7EE900, 0x03051100) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetsysethernetframerelease
	#define EXT_SysEthernetsysethernetframerelease
	#define GET_SysEthernetsysethernetframerelease  ERR_OK
	#define CAL_SysEthernetsysethernetframerelease  sysethernetframerelease
	#define CHK_SysEthernetsysethernetframerelease  TRUE
	#define EXP_SysEthernetsysethernetframerelease  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetframerelease", (RTS_UINTPTR)sysethernetframerelease, 1, 0xDF7EE900, 0x03051100) 
#elif defined(CPLUSPLUS)
	#define USE_sysethernetframerelease
	#define EXT_sysethernetframerelease
	#define GET_sysethernetframerelease(fl)  CAL_CMGETAPI( "sysethernetframerelease" ) 
	#define CAL_sysethernetframerelease  sysethernetframerelease
	#define CHK_sysethernetframerelease  TRUE
	#define EXP_sysethernetframerelease  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetframerelease", (RTS_UINTPTR)sysethernetframerelease, 1, 0xDF7EE900, 0x03051100) 
#else /* DYNAMIC_LINK */
	#define USE_sysethernetframerelease  PFSYSETHERNETFRAMERELEASE_IEC pfsysethernetframerelease;
	#define EXT_sysethernetframerelease  extern PFSYSETHERNETFRAMERELEASE_IEC pfsysethernetframerelease;
	#define GET_sysethernetframerelease(fl)  s_pfCMGetAPI2( "sysethernetframerelease", (RTS_VOID_FCTPTR *)&pfsysethernetframerelease, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xDF7EE900, 0x03051100)
	#define CAL_sysethernetframerelease  pfsysethernetframerelease
	#define CHK_sysethernetframerelease  (pfsysethernetframerelease != NULL)
	#define EXP_sysethernetframerelease   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetframerelease", (RTS_UINTPTR)sysethernetframerelease, 1, 0xDF7EE900, 0x03051100) 
#endif


/**
 * Get EIP Interface Capability of an adapter identified by its MAC address.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsysethernetgetcapabilities_struct
{
	RTS_IEC_BYTE macAddress[6];			/* VAR_INPUT */	/* MAC address of the adapter to get information from */
	SysEthernetCapabilities *pSysEthernetCapabilities;	/* VAR_INPUT */	/* EIP Interface Capability structure */
	RTS_IEC_RESULT SysEthernetGetCapabilities;	/* VAR_OUTPUT */	
} sysethernetgetcapabilities_struct;

void CDECL CDECL_EXT sysethernetgetcapabilities(sysethernetgetcapabilities_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSETHERNETGETCAPABILITIES_IEC) (sysethernetgetcapabilities_struct *p);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(SYSETHERNETGETCAPABILITIES_NOTIMPLEMENTED)
	#define USE_sysethernetgetcapabilities
	#define EXT_sysethernetgetcapabilities
	#define GET_sysethernetgetcapabilities(fl)  ERR_NOTIMPLEMENTED
	#define CAL_sysethernetgetcapabilities(p0) 
	#define CHK_sysethernetgetcapabilities  FALSE
	#define EXP_sysethernetgetcapabilities  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_sysethernetgetcapabilities
	#define EXT_sysethernetgetcapabilities
	#define GET_sysethernetgetcapabilities(fl)  CAL_CMGETAPI( "sysethernetgetcapabilities" ) 
	#define CAL_sysethernetgetcapabilities  sysethernetgetcapabilities
	#define CHK_sysethernetgetcapabilities  TRUE
	#define EXP_sysethernetgetcapabilities  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetgetcapabilities", (RTS_UINTPTR)sysethernetgetcapabilities, 1, 0x7DDC367B, 0x03051100) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_sysethernetgetcapabilities
	#define EXT_sysethernetgetcapabilities
	#define GET_sysethernetgetcapabilities(fl)  CAL_CMGETAPI( "sysethernetgetcapabilities" ) 
	#define CAL_sysethernetgetcapabilities  sysethernetgetcapabilities
	#define CHK_sysethernetgetcapabilities  TRUE
	#define EXP_sysethernetgetcapabilities  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetgetcapabilities", (RTS_UINTPTR)sysethernetgetcapabilities, 1, 0x7DDC367B, 0x03051100) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetsysethernetgetcapabilities
	#define EXT_SysEthernetsysethernetgetcapabilities
	#define GET_SysEthernetsysethernetgetcapabilities  ERR_OK
	#define CAL_SysEthernetsysethernetgetcapabilities  sysethernetgetcapabilities
	#define CHK_SysEthernetsysethernetgetcapabilities  TRUE
	#define EXP_SysEthernetsysethernetgetcapabilities  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetgetcapabilities", (RTS_UINTPTR)sysethernetgetcapabilities, 1, 0x7DDC367B, 0x03051100) 
#elif defined(CPLUSPLUS)
	#define USE_sysethernetgetcapabilities
	#define EXT_sysethernetgetcapabilities
	#define GET_sysethernetgetcapabilities(fl)  CAL_CMGETAPI( "sysethernetgetcapabilities" ) 
	#define CAL_sysethernetgetcapabilities  sysethernetgetcapabilities
	#define CHK_sysethernetgetcapabilities  TRUE
	#define EXP_sysethernetgetcapabilities  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetgetcapabilities", (RTS_UINTPTR)sysethernetgetcapabilities, 1, 0x7DDC367B, 0x03051100) 
#else /* DYNAMIC_LINK */
	#define USE_sysethernetgetcapabilities  PFSYSETHERNETGETCAPABILITIES_IEC pfsysethernetgetcapabilities;
	#define EXT_sysethernetgetcapabilities  extern PFSYSETHERNETGETCAPABILITIES_IEC pfsysethernetgetcapabilities;
	#define GET_sysethernetgetcapabilities(fl)  s_pfCMGetAPI2( "sysethernetgetcapabilities", (RTS_VOID_FCTPTR *)&pfsysethernetgetcapabilities, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x7DDC367B, 0x03051100)
	#define CAL_sysethernetgetcapabilities  pfsysethernetgetcapabilities
	#define CHK_sysethernetgetcapabilities  (pfsysethernetgetcapabilities != NULL)
	#define EXP_sysethernetgetcapabilities   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetgetcapabilities", (RTS_UINTPTR)sysethernetgetcapabilities, 1, 0x7DDC367B, 0x03051100) 
#endif


/**
 * Get EIP Interface Counters of an adapter identified by its MAC address.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsysethernetgetinterfacecounters_struct
{
	RTS_IEC_BYTE macAddress[6];			/* VAR_INPUT */	/* MAC address of the adapter to get information from */
	SysEthernetInterfaceCounters *pSysEthernetInterfaceCounters;	/* VAR_INPUT */	/* EIP Interface Counters structure */
	RTS_IEC_BOOL xGetAndClear;			/* VAR_INPUT */	/* Set the counters to zero after the response is built. */
	RTS_IEC_RESULT SysEthernetGetInterfaceCounters;	/* VAR_OUTPUT */	
} sysethernetgetinterfacecounters_struct;

void CDECL CDECL_EXT sysethernetgetinterfacecounters(sysethernetgetinterfacecounters_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSETHERNETGETINTERFACECOUNTERS_IEC) (sysethernetgetinterfacecounters_struct *p);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(SYSETHERNETGETINTERFACECOUNTERS_NOTIMPLEMENTED)
	#define USE_sysethernetgetinterfacecounters
	#define EXT_sysethernetgetinterfacecounters
	#define GET_sysethernetgetinterfacecounters(fl)  ERR_NOTIMPLEMENTED
	#define CAL_sysethernetgetinterfacecounters(p0) 
	#define CHK_sysethernetgetinterfacecounters  FALSE
	#define EXP_sysethernetgetinterfacecounters  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_sysethernetgetinterfacecounters
	#define EXT_sysethernetgetinterfacecounters
	#define GET_sysethernetgetinterfacecounters(fl)  CAL_CMGETAPI( "sysethernetgetinterfacecounters" ) 
	#define CAL_sysethernetgetinterfacecounters  sysethernetgetinterfacecounters
	#define CHK_sysethernetgetinterfacecounters  TRUE
	#define EXP_sysethernetgetinterfacecounters  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetgetinterfacecounters", (RTS_UINTPTR)sysethernetgetinterfacecounters, 1, 0x0C75E324, 0x03051100) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_sysethernetgetinterfacecounters
	#define EXT_sysethernetgetinterfacecounters
	#define GET_sysethernetgetinterfacecounters(fl)  CAL_CMGETAPI( "sysethernetgetinterfacecounters" ) 
	#define CAL_sysethernetgetinterfacecounters  sysethernetgetinterfacecounters
	#define CHK_sysethernetgetinterfacecounters  TRUE
	#define EXP_sysethernetgetinterfacecounters  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetgetinterfacecounters", (RTS_UINTPTR)sysethernetgetinterfacecounters, 1, 0x0C75E324, 0x03051100) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetsysethernetgetinterfacecounters
	#define EXT_SysEthernetsysethernetgetinterfacecounters
	#define GET_SysEthernetsysethernetgetinterfacecounters  ERR_OK
	#define CAL_SysEthernetsysethernetgetinterfacecounters  sysethernetgetinterfacecounters
	#define CHK_SysEthernetsysethernetgetinterfacecounters  TRUE
	#define EXP_SysEthernetsysethernetgetinterfacecounters  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetgetinterfacecounters", (RTS_UINTPTR)sysethernetgetinterfacecounters, 1, 0x0C75E324, 0x03051100) 
#elif defined(CPLUSPLUS)
	#define USE_sysethernetgetinterfacecounters
	#define EXT_sysethernetgetinterfacecounters
	#define GET_sysethernetgetinterfacecounters(fl)  CAL_CMGETAPI( "sysethernetgetinterfacecounters" ) 
	#define CAL_sysethernetgetinterfacecounters  sysethernetgetinterfacecounters
	#define CHK_sysethernetgetinterfacecounters  TRUE
	#define EXP_sysethernetgetinterfacecounters  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetgetinterfacecounters", (RTS_UINTPTR)sysethernetgetinterfacecounters, 1, 0x0C75E324, 0x03051100) 
#else /* DYNAMIC_LINK */
	#define USE_sysethernetgetinterfacecounters  PFSYSETHERNETGETINTERFACECOUNTERS_IEC pfsysethernetgetinterfacecounters;
	#define EXT_sysethernetgetinterfacecounters  extern PFSYSETHERNETGETINTERFACECOUNTERS_IEC pfsysethernetgetinterfacecounters;
	#define GET_sysethernetgetinterfacecounters(fl)  s_pfCMGetAPI2( "sysethernetgetinterfacecounters", (RTS_VOID_FCTPTR *)&pfsysethernetgetinterfacecounters, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x0C75E324, 0x03051100)
	#define CAL_sysethernetgetinterfacecounters  pfsysethernetgetinterfacecounters
	#define CHK_sysethernetgetinterfacecounters  (pfsysethernetgetinterfacecounters != NULL)
	#define EXP_sysethernetgetinterfacecounters   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetgetinterfacecounters", (RTS_UINTPTR)sysethernetgetinterfacecounters, 1, 0x0C75E324, 0x03051100) 
#endif


/**
 * Get EIP Media Counters of an adapter identified by its MAC address.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsysethernetgetmediacounters_struct
{
	RTS_IEC_BYTE macAddress[6];			/* VAR_INPUT */	/* MAC address of the adapter to get information from */
	SysEthernetMediaCounters *pSysEthernetMediaCounters;	/* VAR_INPUT */	/* EIP Media Counters structure */
	RTS_IEC_BOOL xGetAndClear;			/* VAR_INPUT */	/* Set the counters to zero after the response is built. */
	RTS_IEC_RESULT SysEthernetGetMediaCounters;	/* VAR_OUTPUT */	
} sysethernetgetmediacounters_struct;

void CDECL CDECL_EXT sysethernetgetmediacounters(sysethernetgetmediacounters_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSETHERNETGETMEDIACOUNTERS_IEC) (sysethernetgetmediacounters_struct *p);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(SYSETHERNETGETMEDIACOUNTERS_NOTIMPLEMENTED)
	#define USE_sysethernetgetmediacounters
	#define EXT_sysethernetgetmediacounters
	#define GET_sysethernetgetmediacounters(fl)  ERR_NOTIMPLEMENTED
	#define CAL_sysethernetgetmediacounters(p0) 
	#define CHK_sysethernetgetmediacounters  FALSE
	#define EXP_sysethernetgetmediacounters  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_sysethernetgetmediacounters
	#define EXT_sysethernetgetmediacounters
	#define GET_sysethernetgetmediacounters(fl)  CAL_CMGETAPI( "sysethernetgetmediacounters" ) 
	#define CAL_sysethernetgetmediacounters  sysethernetgetmediacounters
	#define CHK_sysethernetgetmediacounters  TRUE
	#define EXP_sysethernetgetmediacounters  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetgetmediacounters", (RTS_UINTPTR)sysethernetgetmediacounters, 1, 0x1D87744E, 0x03051100) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_sysethernetgetmediacounters
	#define EXT_sysethernetgetmediacounters
	#define GET_sysethernetgetmediacounters(fl)  CAL_CMGETAPI( "sysethernetgetmediacounters" ) 
	#define CAL_sysethernetgetmediacounters  sysethernetgetmediacounters
	#define CHK_sysethernetgetmediacounters  TRUE
	#define EXP_sysethernetgetmediacounters  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetgetmediacounters", (RTS_UINTPTR)sysethernetgetmediacounters, 1, 0x1D87744E, 0x03051100) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetsysethernetgetmediacounters
	#define EXT_SysEthernetsysethernetgetmediacounters
	#define GET_SysEthernetsysethernetgetmediacounters  ERR_OK
	#define CAL_SysEthernetsysethernetgetmediacounters  sysethernetgetmediacounters
	#define CHK_SysEthernetsysethernetgetmediacounters  TRUE
	#define EXP_SysEthernetsysethernetgetmediacounters  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetgetmediacounters", (RTS_UINTPTR)sysethernetgetmediacounters, 1, 0x1D87744E, 0x03051100) 
#elif defined(CPLUSPLUS)
	#define USE_sysethernetgetmediacounters
	#define EXT_sysethernetgetmediacounters
	#define GET_sysethernetgetmediacounters(fl)  CAL_CMGETAPI( "sysethernetgetmediacounters" ) 
	#define CAL_sysethernetgetmediacounters  sysethernetgetmediacounters
	#define CHK_sysethernetgetmediacounters  TRUE
	#define EXP_sysethernetgetmediacounters  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetgetmediacounters", (RTS_UINTPTR)sysethernetgetmediacounters, 1, 0x1D87744E, 0x03051100) 
#else /* DYNAMIC_LINK */
	#define USE_sysethernetgetmediacounters  PFSYSETHERNETGETMEDIACOUNTERS_IEC pfsysethernetgetmediacounters;
	#define EXT_sysethernetgetmediacounters  extern PFSYSETHERNETGETMEDIACOUNTERS_IEC pfsysethernetgetmediacounters;
	#define GET_sysethernetgetmediacounters(fl)  s_pfCMGetAPI2( "sysethernetgetmediacounters", (RTS_VOID_FCTPTR *)&pfsysethernetgetmediacounters, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x1D87744E, 0x03051100)
	#define CAL_sysethernetgetmediacounters  pfsysethernetgetmediacounters
	#define CHK_sysethernetgetmediacounters  (pfsysethernetgetmediacounters != NULL)
	#define EXP_sysethernetgetmediacounters   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetgetmediacounters", (RTS_UINTPTR)sysethernetgetmediacounters, 1, 0x1D87744E, 0x03051100) 
#endif


/**
 * Get Ethernet port configuration and status of an adapter identified by its MAC address.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsysethernetgetportconfigandstatus_struct
{
	RTS_IEC_BYTE macAddress[6];			/* VAR_INPUT */	/* MAC address of the adapter to get information from */
	SysEthernetPortConfigAndStatus *pPortConfigAndStatus;	/* VAR_INPUT */	/* Port configuration and status structure */
	RTS_IEC_UXINT *puxiPortConfigAndDataSize;	/* VAR_INPUT */	/* Size in bytes of |SysEthernetPortConfigAndStatus|; returns structure size from external implementation */
	RTS_IEC_RESULT SysEthernetGetPortConfigAndStatus;	/* VAR_OUTPUT */	
} sysethernetgetportconfigandstatus_struct;

void CDECL CDECL_EXT sysethernetgetportconfigandstatus(sysethernetgetportconfigandstatus_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSETHERNETGETPORTCONFIGANDSTATUS_IEC) (sysethernetgetportconfigandstatus_struct *p);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(SYSETHERNETGETPORTCONFIGANDSTATUS_NOTIMPLEMENTED)
	#define USE_sysethernetgetportconfigandstatus
	#define EXT_sysethernetgetportconfigandstatus
	#define GET_sysethernetgetportconfigandstatus(fl)  ERR_NOTIMPLEMENTED
	#define CAL_sysethernetgetportconfigandstatus(p0) 
	#define CHK_sysethernetgetportconfigandstatus  FALSE
	#define EXP_sysethernetgetportconfigandstatus  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_sysethernetgetportconfigandstatus
	#define EXT_sysethernetgetportconfigandstatus
	#define GET_sysethernetgetportconfigandstatus(fl)  CAL_CMGETAPI( "sysethernetgetportconfigandstatus" ) 
	#define CAL_sysethernetgetportconfigandstatus  sysethernetgetportconfigandstatus
	#define CHK_sysethernetgetportconfigandstatus  TRUE
	#define EXP_sysethernetgetportconfigandstatus  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetgetportconfigandstatus", (RTS_UINTPTR)sysethernetgetportconfigandstatus, 1, RTSITF_GET_SIGNATURE(0xE8D0BEEB, 0x21B15FAE), 0x03051100) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_sysethernetgetportconfigandstatus
	#define EXT_sysethernetgetportconfigandstatus
	#define GET_sysethernetgetportconfigandstatus(fl)  CAL_CMGETAPI( "sysethernetgetportconfigandstatus" ) 
	#define CAL_sysethernetgetportconfigandstatus  sysethernetgetportconfigandstatus
	#define CHK_sysethernetgetportconfigandstatus  TRUE
	#define EXP_sysethernetgetportconfigandstatus  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetgetportconfigandstatus", (RTS_UINTPTR)sysethernetgetportconfigandstatus, 1, RTSITF_GET_SIGNATURE(0xE8D0BEEB, 0x21B15FAE), 0x03051100) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetsysethernetgetportconfigandstatus
	#define EXT_SysEthernetsysethernetgetportconfigandstatus
	#define GET_SysEthernetsysethernetgetportconfigandstatus  ERR_OK
	#define CAL_SysEthernetsysethernetgetportconfigandstatus  sysethernetgetportconfigandstatus
	#define CHK_SysEthernetsysethernetgetportconfigandstatus  TRUE
	#define EXP_SysEthernetsysethernetgetportconfigandstatus  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetgetportconfigandstatus", (RTS_UINTPTR)sysethernetgetportconfigandstatus, 1, RTSITF_GET_SIGNATURE(0xE8D0BEEB, 0x21B15FAE), 0x03051100) 
#elif defined(CPLUSPLUS)
	#define USE_sysethernetgetportconfigandstatus
	#define EXT_sysethernetgetportconfigandstatus
	#define GET_sysethernetgetportconfigandstatus(fl)  CAL_CMGETAPI( "sysethernetgetportconfigandstatus" ) 
	#define CAL_sysethernetgetportconfigandstatus  sysethernetgetportconfigandstatus
	#define CHK_sysethernetgetportconfigandstatus  TRUE
	#define EXP_sysethernetgetportconfigandstatus  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetgetportconfigandstatus", (RTS_UINTPTR)sysethernetgetportconfigandstatus, 1, RTSITF_GET_SIGNATURE(0xE8D0BEEB, 0x21B15FAE), 0x03051100) 
#else /* DYNAMIC_LINK */
	#define USE_sysethernetgetportconfigandstatus  PFSYSETHERNETGETPORTCONFIGANDSTATUS_IEC pfsysethernetgetportconfigandstatus;
	#define EXT_sysethernetgetportconfigandstatus  extern PFSYSETHERNETGETPORTCONFIGANDSTATUS_IEC pfsysethernetgetportconfigandstatus;
	#define GET_sysethernetgetportconfigandstatus(fl)  s_pfCMGetAPI2( "sysethernetgetportconfigandstatus", (RTS_VOID_FCTPTR *)&pfsysethernetgetportconfigandstatus, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0xE8D0BEEB, 0x21B15FAE), 0x03051100)
	#define CAL_sysethernetgetportconfigandstatus  pfsysethernetgetportconfigandstatus
	#define CHK_sysethernetgetportconfigandstatus  (pfsysethernetgetportconfigandstatus != NULL)
	#define EXP_sysethernetgetportconfigandstatus   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetgetportconfigandstatus", (RTS_UINTPTR)sysethernetgetportconfigandstatus, 1, RTSITF_GET_SIGNATURE(0xE8D0BEEB, 0x21B15FAE), 0x03051100) 
#endif


/**
 * This function receives an IP frame from the systems IP Stack.
 * This frame has to be packed into an EtherCAT frame and sent to
 * this adapter.
 * ..note::
 *   Special function for Ethernet over EtherCAT (EoE) 
 */
typedef struct tagsysethernetipframereceive_struct
{
	RTS_IEC_HANDLE hAdapter;			/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	SysEthernetFrame *SysEthernetIpFrameReceive;	/* VAR_OUTPUT */	
} sysethernetipframereceive_struct;

void CDECL CDECL_EXT sysethernetipframereceive(sysethernetipframereceive_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSETHERNETIPFRAMERECEIVE_IEC) (sysethernetipframereceive_struct *p);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(SYSETHERNETIPFRAMERECEIVE_NOTIMPLEMENTED)
	#define USE_sysethernetipframereceive
	#define EXT_sysethernetipframereceive
	#define GET_sysethernetipframereceive(fl)  ERR_NOTIMPLEMENTED
	#define CAL_sysethernetipframereceive(p0) 
	#define CHK_sysethernetipframereceive  FALSE
	#define EXP_sysethernetipframereceive  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_sysethernetipframereceive
	#define EXT_sysethernetipframereceive
	#define GET_sysethernetipframereceive(fl)  CAL_CMGETAPI( "sysethernetipframereceive" ) 
	#define CAL_sysethernetipframereceive  sysethernetipframereceive
	#define CHK_sysethernetipframereceive  TRUE
	#define EXP_sysethernetipframereceive  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetipframereceive", (RTS_UINTPTR)sysethernetipframereceive, 1, 0x3794F2CE, 0x03051100) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_sysethernetipframereceive
	#define EXT_sysethernetipframereceive
	#define GET_sysethernetipframereceive(fl)  CAL_CMGETAPI( "sysethernetipframereceive" ) 
	#define CAL_sysethernetipframereceive  sysethernetipframereceive
	#define CHK_sysethernetipframereceive  TRUE
	#define EXP_sysethernetipframereceive  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetipframereceive", (RTS_UINTPTR)sysethernetipframereceive, 1, 0x3794F2CE, 0x03051100) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetsysethernetipframereceive
	#define EXT_SysEthernetsysethernetipframereceive
	#define GET_SysEthernetsysethernetipframereceive  ERR_OK
	#define CAL_SysEthernetsysethernetipframereceive  sysethernetipframereceive
	#define CHK_SysEthernetsysethernetipframereceive  TRUE
	#define EXP_SysEthernetsysethernetipframereceive  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetipframereceive", (RTS_UINTPTR)sysethernetipframereceive, 1, 0x3794F2CE, 0x03051100) 
#elif defined(CPLUSPLUS)
	#define USE_sysethernetipframereceive
	#define EXT_sysethernetipframereceive
	#define GET_sysethernetipframereceive(fl)  CAL_CMGETAPI( "sysethernetipframereceive" ) 
	#define CAL_sysethernetipframereceive  sysethernetipframereceive
	#define CHK_sysethernetipframereceive  TRUE
	#define EXP_sysethernetipframereceive  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetipframereceive", (RTS_UINTPTR)sysethernetipframereceive, 1, 0x3794F2CE, 0x03051100) 
#else /* DYNAMIC_LINK */
	#define USE_sysethernetipframereceive  PFSYSETHERNETIPFRAMERECEIVE_IEC pfsysethernetipframereceive;
	#define EXT_sysethernetipframereceive  extern PFSYSETHERNETIPFRAMERECEIVE_IEC pfsysethernetipframereceive;
	#define GET_sysethernetipframereceive(fl)  s_pfCMGetAPI2( "sysethernetipframereceive", (RTS_VOID_FCTPTR *)&pfsysethernetipframereceive, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x3794F2CE, 0x03051100)
	#define CAL_sysethernetipframereceive  pfsysethernetipframereceive
	#define CHK_sysethernetipframereceive  (pfsysethernetipframereceive != NULL)
	#define EXP_sysethernetipframereceive   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetipframereceive", (RTS_UINTPTR)sysethernetipframereceive, 1, 0x3794F2CE, 0x03051100) 
#endif


/**
 * This functions sends an Ethernet frame to the local IP Stack for processing.
 * The frame can be safely reused when this function has returned.
 * ..note::
 *   Special function for Ethernet over EtherCAT (EoE) 
 */
typedef struct tagsysethernetipframesend_struct
{
	RTS_IEC_HANDLE hAdapter;			/* VAR_INPUT */	
	SysEthernetFrame *pFrame;			/* VAR_INPUT */	
	RTS_IEC_RESULT SysEthernetIpFrameSend;	/* VAR_OUTPUT */	
} sysethernetipframesend_struct;

void CDECL CDECL_EXT sysethernetipframesend(sysethernetipframesend_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSETHERNETIPFRAMESEND_IEC) (sysethernetipframesend_struct *p);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(SYSETHERNETIPFRAMESEND_NOTIMPLEMENTED)
	#define USE_sysethernetipframesend
	#define EXT_sysethernetipframesend
	#define GET_sysethernetipframesend(fl)  ERR_NOTIMPLEMENTED
	#define CAL_sysethernetipframesend(p0) 
	#define CHK_sysethernetipframesend  FALSE
	#define EXP_sysethernetipframesend  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_sysethernetipframesend
	#define EXT_sysethernetipframesend
	#define GET_sysethernetipframesend(fl)  CAL_CMGETAPI( "sysethernetipframesend" ) 
	#define CAL_sysethernetipframesend  sysethernetipframesend
	#define CHK_sysethernetipframesend  TRUE
	#define EXP_sysethernetipframesend  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetipframesend", (RTS_UINTPTR)sysethernetipframesend, 1, 0x02F5C5D2, 0x03051100) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_sysethernetipframesend
	#define EXT_sysethernetipframesend
	#define GET_sysethernetipframesend(fl)  CAL_CMGETAPI( "sysethernetipframesend" ) 
	#define CAL_sysethernetipframesend  sysethernetipframesend
	#define CHK_sysethernetipframesend  TRUE
	#define EXP_sysethernetipframesend  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetipframesend", (RTS_UINTPTR)sysethernetipframesend, 1, 0x02F5C5D2, 0x03051100) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetsysethernetipframesend
	#define EXT_SysEthernetsysethernetipframesend
	#define GET_SysEthernetsysethernetipframesend  ERR_OK
	#define CAL_SysEthernetsysethernetipframesend  sysethernetipframesend
	#define CHK_SysEthernetsysethernetipframesend  TRUE
	#define EXP_SysEthernetsysethernetipframesend  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetipframesend", (RTS_UINTPTR)sysethernetipframesend, 1, 0x02F5C5D2, 0x03051100) 
#elif defined(CPLUSPLUS)
	#define USE_sysethernetipframesend
	#define EXT_sysethernetipframesend
	#define GET_sysethernetipframesend(fl)  CAL_CMGETAPI( "sysethernetipframesend" ) 
	#define CAL_sysethernetipframesend  sysethernetipframesend
	#define CHK_sysethernetipframesend  TRUE
	#define EXP_sysethernetipframesend  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetipframesend", (RTS_UINTPTR)sysethernetipframesend, 1, 0x02F5C5D2, 0x03051100) 
#else /* DYNAMIC_LINK */
	#define USE_sysethernetipframesend  PFSYSETHERNETIPFRAMESEND_IEC pfsysethernetipframesend;
	#define EXT_sysethernetipframesend  extern PFSYSETHERNETIPFRAMESEND_IEC pfsysethernetipframesend;
	#define GET_sysethernetipframesend(fl)  s_pfCMGetAPI2( "sysethernetipframesend", (RTS_VOID_FCTPTR *)&pfsysethernetipframesend, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x02F5C5D2, 0x03051100)
	#define CAL_sysethernetipframesend  pfsysethernetipframesend
	#define CHK_sysethernetipframesend  (pfsysethernetipframesend != NULL)
	#define EXP_sysethernetipframesend   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetipframesend", (RTS_UINTPTR)sysethernetipframesend, 1, 0x02F5C5D2, 0x03051100) 
#endif


/**
 * Set advertised auto-negotiation capabilities for an adapter identified by its MAC address.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsysethernetsetautonegadvertisedcap_struct
{
	RTS_IEC_BYTE macAddress[6];			/* VAR_INPUT */	/* MAC address of the adapter */
	RTS_IEC_ULINT uliAutoNegAdvertisedCap;	/* VAR_INPUT */	/* Advertised auto-negotiation capabilities of MAU, see AutoNegCaps constants SYSETH_AUTONEGCAP_... */
	RTS_IEC_RESULT SysEthernetSetAutoNegAdvertisedCap;	/* VAR_OUTPUT */	
} sysethernetsetautonegadvertisedcap_struct;

void CDECL CDECL_EXT sysethernetsetautonegadvertisedcap(sysethernetsetautonegadvertisedcap_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSETHERNETSETAUTONEGADVERTISEDCAP_IEC) (sysethernetsetautonegadvertisedcap_struct *p);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(SYSETHERNETSETAUTONEGADVERTISEDCAP_NOTIMPLEMENTED)
	#define USE_sysethernetsetautonegadvertisedcap
	#define EXT_sysethernetsetautonegadvertisedcap
	#define GET_sysethernetsetautonegadvertisedcap(fl)  ERR_NOTIMPLEMENTED
	#define CAL_sysethernetsetautonegadvertisedcap(p0) 
	#define CHK_sysethernetsetautonegadvertisedcap  FALSE
	#define EXP_sysethernetsetautonegadvertisedcap  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_sysethernetsetautonegadvertisedcap
	#define EXT_sysethernetsetautonegadvertisedcap
	#define GET_sysethernetsetautonegadvertisedcap(fl)  CAL_CMGETAPI( "sysethernetsetautonegadvertisedcap" ) 
	#define CAL_sysethernetsetautonegadvertisedcap  sysethernetsetautonegadvertisedcap
	#define CHK_sysethernetsetautonegadvertisedcap  TRUE
	#define EXP_sysethernetsetautonegadvertisedcap  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetsetautonegadvertisedcap", (RTS_UINTPTR)sysethernetsetautonegadvertisedcap, 1, 0xBC4E06DB, 0x03051100) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_sysethernetsetautonegadvertisedcap
	#define EXT_sysethernetsetautonegadvertisedcap
	#define GET_sysethernetsetautonegadvertisedcap(fl)  CAL_CMGETAPI( "sysethernetsetautonegadvertisedcap" ) 
	#define CAL_sysethernetsetautonegadvertisedcap  sysethernetsetautonegadvertisedcap
	#define CHK_sysethernetsetautonegadvertisedcap  TRUE
	#define EXP_sysethernetsetautonegadvertisedcap  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetsetautonegadvertisedcap", (RTS_UINTPTR)sysethernetsetautonegadvertisedcap, 1, 0xBC4E06DB, 0x03051100) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetsysethernetsetautonegadvertisedcap
	#define EXT_SysEthernetsysethernetsetautonegadvertisedcap
	#define GET_SysEthernetsysethernetsetautonegadvertisedcap  ERR_OK
	#define CAL_SysEthernetsysethernetsetautonegadvertisedcap  sysethernetsetautonegadvertisedcap
	#define CHK_SysEthernetsysethernetsetautonegadvertisedcap  TRUE
	#define EXP_SysEthernetsysethernetsetautonegadvertisedcap  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetsetautonegadvertisedcap", (RTS_UINTPTR)sysethernetsetautonegadvertisedcap, 1, 0xBC4E06DB, 0x03051100) 
#elif defined(CPLUSPLUS)
	#define USE_sysethernetsetautonegadvertisedcap
	#define EXT_sysethernetsetautonegadvertisedcap
	#define GET_sysethernetsetautonegadvertisedcap(fl)  CAL_CMGETAPI( "sysethernetsetautonegadvertisedcap" ) 
	#define CAL_sysethernetsetautonegadvertisedcap  sysethernetsetautonegadvertisedcap
	#define CHK_sysethernetsetautonegadvertisedcap  TRUE
	#define EXP_sysethernetsetautonegadvertisedcap  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetsetautonegadvertisedcap", (RTS_UINTPTR)sysethernetsetautonegadvertisedcap, 1, 0xBC4E06DB, 0x03051100) 
#else /* DYNAMIC_LINK */
	#define USE_sysethernetsetautonegadvertisedcap  PFSYSETHERNETSETAUTONEGADVERTISEDCAP_IEC pfsysethernetsetautonegadvertisedcap;
	#define EXT_sysethernetsetautonegadvertisedcap  extern PFSYSETHERNETSETAUTONEGADVERTISEDCAP_IEC pfsysethernetsetautonegadvertisedcap;
	#define GET_sysethernetsetautonegadvertisedcap(fl)  s_pfCMGetAPI2( "sysethernetsetautonegadvertisedcap", (RTS_VOID_FCTPTR *)&pfsysethernetsetautonegadvertisedcap, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xBC4E06DB, 0x03051100)
	#define CAL_sysethernetsetautonegadvertisedcap  pfsysethernetsetautonegadvertisedcap
	#define CHK_sysethernetsetautonegadvertisedcap  (pfsysethernetsetautonegadvertisedcap != NULL)
	#define EXP_sysethernetsetautonegadvertisedcap   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetsetautonegadvertisedcap", (RTS_UINTPTR)sysethernetsetautonegadvertisedcap, 1, 0xBC4E06DB, 0x03051100) 
#endif


/**
 * Set auto-negotiation mode for an adapter identified by its MAC address.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsysethernetsetautonegmode_struct
{
	RTS_IEC_BYTE macAddress[6];			/* VAR_INPUT */	/* MAC address of the adapter */
	RTS_IEC_USINT usiAutoNegMode;		/* VAR_INPUT */	/* Auto-negotiation mode of MAU, see AutoNegMode constants SYSETH_AUTONEGMODE_... */
	RTS_IEC_RESULT SysEthernetSetAutoNegMode;	/* VAR_OUTPUT */	
} sysethernetsetautonegmode_struct;

void CDECL CDECL_EXT sysethernetsetautonegmode(sysethernetsetautonegmode_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSETHERNETSETAUTONEGMODE_IEC) (sysethernetsetautonegmode_struct *p);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(SYSETHERNETSETAUTONEGMODE_NOTIMPLEMENTED)
	#define USE_sysethernetsetautonegmode
	#define EXT_sysethernetsetautonegmode
	#define GET_sysethernetsetautonegmode(fl)  ERR_NOTIMPLEMENTED
	#define CAL_sysethernetsetautonegmode(p0) 
	#define CHK_sysethernetsetautonegmode  FALSE
	#define EXP_sysethernetsetautonegmode  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_sysethernetsetautonegmode
	#define EXT_sysethernetsetautonegmode
	#define GET_sysethernetsetautonegmode(fl)  CAL_CMGETAPI( "sysethernetsetautonegmode" ) 
	#define CAL_sysethernetsetautonegmode  sysethernetsetautonegmode
	#define CHK_sysethernetsetautonegmode  TRUE
	#define EXP_sysethernetsetautonegmode  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetsetautonegmode", (RTS_UINTPTR)sysethernetsetautonegmode, 1, 0xCDFED6BF, 0x03051100) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_sysethernetsetautonegmode
	#define EXT_sysethernetsetautonegmode
	#define GET_sysethernetsetautonegmode(fl)  CAL_CMGETAPI( "sysethernetsetautonegmode" ) 
	#define CAL_sysethernetsetautonegmode  sysethernetsetautonegmode
	#define CHK_sysethernetsetautonegmode  TRUE
	#define EXP_sysethernetsetautonegmode  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetsetautonegmode", (RTS_UINTPTR)sysethernetsetautonegmode, 1, 0xCDFED6BF, 0x03051100) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetsysethernetsetautonegmode
	#define EXT_SysEthernetsysethernetsetautonegmode
	#define GET_SysEthernetsysethernetsetautonegmode  ERR_OK
	#define CAL_SysEthernetsysethernetsetautonegmode  sysethernetsetautonegmode
	#define CHK_SysEthernetsysethernetsetautonegmode  TRUE
	#define EXP_SysEthernetsysethernetsetautonegmode  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetsetautonegmode", (RTS_UINTPTR)sysethernetsetautonegmode, 1, 0xCDFED6BF, 0x03051100) 
#elif defined(CPLUSPLUS)
	#define USE_sysethernetsetautonegmode
	#define EXT_sysethernetsetautonegmode
	#define GET_sysethernetsetautonegmode(fl)  CAL_CMGETAPI( "sysethernetsetautonegmode" ) 
	#define CAL_sysethernetsetautonegmode  sysethernetsetautonegmode
	#define CHK_sysethernetsetautonegmode  TRUE
	#define EXP_sysethernetsetautonegmode  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetsetautonegmode", (RTS_UINTPTR)sysethernetsetautonegmode, 1, 0xCDFED6BF, 0x03051100) 
#else /* DYNAMIC_LINK */
	#define USE_sysethernetsetautonegmode  PFSYSETHERNETSETAUTONEGMODE_IEC pfsysethernetsetautonegmode;
	#define EXT_sysethernetsetautonegmode  extern PFSYSETHERNETSETAUTONEGMODE_IEC pfsysethernetsetautonegmode;
	#define GET_sysethernetsetautonegmode(fl)  s_pfCMGetAPI2( "sysethernetsetautonegmode", (RTS_VOID_FCTPTR *)&pfsysethernetsetautonegmode, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xCDFED6BF, 0x03051100)
	#define CAL_sysethernetsetautonegmode  pfsysethernetsetautonegmode
	#define CHK_sysethernetsetautonegmode  (pfsysethernetsetautonegmode != NULL)
	#define EXP_sysethernetsetautonegmode   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetsetautonegmode", (RTS_UINTPTR)sysethernetsetautonegmode, 1, 0xCDFED6BF, 0x03051100) 
#endif


/**
 * Set Media Access Unit (MAU) type for an adapter identified by its MAC address.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsysethernetsetmautype_struct
{
	RTS_IEC_BYTE macAddress[6];			/* VAR_INPUT */	/* MAC address of the adapter */
	RTS_IEC_UDINT udiMauType;			/* VAR_INPUT */	/* Media Access Unit (MAU) type, see MauType constants SYSETH_MAUTYPE_... */
	RTS_IEC_RESULT SysEthernetSetMauType;	/* VAR_OUTPUT */	
} sysethernetsetmautype_struct;

void CDECL CDECL_EXT sysethernetsetmautype(sysethernetsetmautype_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSETHERNETSETMAUTYPE_IEC) (sysethernetsetmautype_struct *p);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(SYSETHERNETSETMAUTYPE_NOTIMPLEMENTED)
	#define USE_sysethernetsetmautype
	#define EXT_sysethernetsetmautype
	#define GET_sysethernetsetmautype(fl)  ERR_NOTIMPLEMENTED
	#define CAL_sysethernetsetmautype(p0) 
	#define CHK_sysethernetsetmautype  FALSE
	#define EXP_sysethernetsetmautype  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_sysethernetsetmautype
	#define EXT_sysethernetsetmautype
	#define GET_sysethernetsetmautype(fl)  CAL_CMGETAPI( "sysethernetsetmautype" ) 
	#define CAL_sysethernetsetmautype  sysethernetsetmautype
	#define CHK_sysethernetsetmautype  TRUE
	#define EXP_sysethernetsetmautype  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetsetmautype", (RTS_UINTPTR)sysethernetsetmautype, 1, 0x06B2A7F6, 0x03051100) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_sysethernetsetmautype
	#define EXT_sysethernetsetmautype
	#define GET_sysethernetsetmautype(fl)  CAL_CMGETAPI( "sysethernetsetmautype" ) 
	#define CAL_sysethernetsetmautype  sysethernetsetmautype
	#define CHK_sysethernetsetmautype  TRUE
	#define EXP_sysethernetsetmautype  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetsetmautype", (RTS_UINTPTR)sysethernetsetmautype, 1, 0x06B2A7F6, 0x03051100) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetsysethernetsetmautype
	#define EXT_SysEthernetsysethernetsetmautype
	#define GET_SysEthernetsysethernetsetmautype  ERR_OK
	#define CAL_SysEthernetsysethernetsetmautype  sysethernetsetmautype
	#define CHK_SysEthernetsysethernetsetmautype  TRUE
	#define EXP_SysEthernetsysethernetsetmautype  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetsetmautype", (RTS_UINTPTR)sysethernetsetmautype, 1, 0x06B2A7F6, 0x03051100) 
#elif defined(CPLUSPLUS)
	#define USE_sysethernetsetmautype
	#define EXT_sysethernetsetmautype
	#define GET_sysethernetsetmautype(fl)  CAL_CMGETAPI( "sysethernetsetmautype" ) 
	#define CAL_sysethernetsetmautype  sysethernetsetmautype
	#define CHK_sysethernetsetmautype  TRUE
	#define EXP_sysethernetsetmautype  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetsetmautype", (RTS_UINTPTR)sysethernetsetmautype, 1, 0x06B2A7F6, 0x03051100) 
#else /* DYNAMIC_LINK */
	#define USE_sysethernetsetmautype  PFSYSETHERNETSETMAUTYPE_IEC pfsysethernetsetmautype;
	#define EXT_sysethernetsetmautype  extern PFSYSETHERNETSETMAUTYPE_IEC pfsysethernetsetmautype;
	#define GET_sysethernetsetmautype(fl)  s_pfCMGetAPI2( "sysethernetsetmautype", (RTS_VOID_FCTPTR *)&pfsysethernetsetmautype, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x06B2A7F6, 0x03051100)
	#define CAL_sysethernetsetmautype  pfsysethernetsetmautype
	#define CHK_sysethernetsetmautype  (pfsysethernetsetmautype != NULL)
	#define EXP_sysethernetsetmautype   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysethernetsetmautype", (RTS_UINTPTR)sysethernetsetmautype, 1, 0x06B2A7F6, 0x03051100) 
#endif


#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Open and Close Ethernet adapters 
 */
/**
 * <description>Open an Ethernet adapter by its MAC address.
 *  Note: Each adapter can only be opened once.
 * </description>
 * <return>Returns a handle to the opened adapter. SysTypes.RTS_INVALID_HANDLE is returned if the operation failed.</return>
 * <param name="pMacAddress" type="IN">Pointer to the MAC address of the adapter to be opened.</param>
 * <param name="macSize" type="IN">Size of the MAC address. This is usually 6 bytes.</param>
 * <param name="pResult" type="OUT">Result of the operation. On of ERR_FAILED or ERR_OK</param>
 */
RTS_HANDLE CDECL SysEthernetAdapterOpen(RTS_UI8* pMacAddress, RTS_SIZE macSize, RTS_RESULT* pResult);
typedef RTS_HANDLE (CDECL * PFSYSETHERNETADAPTEROPEN) (RTS_UI8* pMacAddress, RTS_SIZE macSize, RTS_RESULT* pResult);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(SYSETHERNETADAPTEROPEN_NOTIMPLEMENTED)
	#define USE_SysEthernetAdapterOpen
	#define EXT_SysEthernetAdapterOpen
	#define GET_SysEthernetAdapterOpen(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysEthernetAdapterOpen(p0,p1,p2)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_SysEthernetAdapterOpen  FALSE
	#define EXP_SysEthernetAdapterOpen  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysEthernetAdapterOpen
	#define EXT_SysEthernetAdapterOpen
	#define GET_SysEthernetAdapterOpen(fl)  CAL_CMGETAPI( "SysEthernetAdapterOpen" ) 
	#define CAL_SysEthernetAdapterOpen  SysEthernetAdapterOpen
	#define CHK_SysEthernetAdapterOpen  TRUE
	#define EXP_SysEthernetAdapterOpen  CAL_CMEXPAPI( "SysEthernetAdapterOpen" ) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_SysEthernetAdapterOpen
	#define EXT_SysEthernetAdapterOpen
	#define GET_SysEthernetAdapterOpen(fl)  CAL_CMGETAPI( "SysEthernetAdapterOpen" ) 
	#define CAL_SysEthernetAdapterOpen  SysEthernetAdapterOpen
	#define CHK_SysEthernetAdapterOpen  TRUE
	#define EXP_SysEthernetAdapterOpen  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysEthernetAdapterOpen", (RTS_UINTPTR)SysEthernetAdapterOpen, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetSysEthernetAdapterOpen
	#define EXT_SysEthernetSysEthernetAdapterOpen
	#define GET_SysEthernetSysEthernetAdapterOpen  ERR_OK
	#define CAL_SysEthernetSysEthernetAdapterOpen pISysEthernet->ISysEthernetAdapterOpen
	#define CHK_SysEthernetSysEthernetAdapterOpen (pISysEthernet != NULL)
	#define EXP_SysEthernetSysEthernetAdapterOpen  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysEthernetAdapterOpen
	#define EXT_SysEthernetAdapterOpen
	#define GET_SysEthernetAdapterOpen(fl)  CAL_CMGETAPI( "SysEthernetAdapterOpen" ) 
	#define CAL_SysEthernetAdapterOpen pISysEthernet->ISysEthernetAdapterOpen
	#define CHK_SysEthernetAdapterOpen (pISysEthernet != NULL)
	#define EXP_SysEthernetAdapterOpen  CAL_CMEXPAPI( "SysEthernetAdapterOpen" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysEthernetAdapterOpen  PFSYSETHERNETADAPTEROPEN pfSysEthernetAdapterOpen;
	#define EXT_SysEthernetAdapterOpen  extern PFSYSETHERNETADAPTEROPEN pfSysEthernetAdapterOpen;
	#define GET_SysEthernetAdapterOpen(fl)  s_pfCMGetAPI2( "SysEthernetAdapterOpen", (RTS_VOID_FCTPTR *)&pfSysEthernetAdapterOpen, (fl), 0, 0)
	#define CAL_SysEthernetAdapterOpen  pfSysEthernetAdapterOpen
	#define CHK_SysEthernetAdapterOpen  (pfSysEthernetAdapterOpen != NULL)
	#define EXP_SysEthernetAdapterOpen  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysEthernetAdapterOpen", (RTS_UINTPTR)SysEthernetAdapterOpen, 0, 0) 
#endif




/**
 * <description>Close an Ethernet adapter.</description>
 * <return>Result of the operation. ERR_INVALID_HANDLE if the handle was invalid. ERR_OK if operation was successful.</return>
 * <param name="hAdapter" type="IN">Adapter to close.</param>
 */
RTS_RESULT CDECL SysEthernetAdapterClose(RTS_HANDLE hAdapter);
typedef RTS_RESULT (CDECL * PFSYSETHERNETADAPTERCLOSE) (RTS_HANDLE hAdapter);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(SYSETHERNETADAPTERCLOSE_NOTIMPLEMENTED)
	#define USE_SysEthernetAdapterClose
	#define EXT_SysEthernetAdapterClose
	#define GET_SysEthernetAdapterClose(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysEthernetAdapterClose(p0)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_SysEthernetAdapterClose  FALSE
	#define EXP_SysEthernetAdapterClose  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysEthernetAdapterClose
	#define EXT_SysEthernetAdapterClose
	#define GET_SysEthernetAdapterClose(fl)  CAL_CMGETAPI( "SysEthernetAdapterClose" ) 
	#define CAL_SysEthernetAdapterClose  SysEthernetAdapterClose
	#define CHK_SysEthernetAdapterClose  TRUE
	#define EXP_SysEthernetAdapterClose  CAL_CMEXPAPI( "SysEthernetAdapterClose" ) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_SysEthernetAdapterClose
	#define EXT_SysEthernetAdapterClose
	#define GET_SysEthernetAdapterClose(fl)  CAL_CMGETAPI( "SysEthernetAdapterClose" ) 
	#define CAL_SysEthernetAdapterClose  SysEthernetAdapterClose
	#define CHK_SysEthernetAdapterClose  TRUE
	#define EXP_SysEthernetAdapterClose  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysEthernetAdapterClose", (RTS_UINTPTR)SysEthernetAdapterClose, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetSysEthernetAdapterClose
	#define EXT_SysEthernetSysEthernetAdapterClose
	#define GET_SysEthernetSysEthernetAdapterClose  ERR_OK
	#define CAL_SysEthernetSysEthernetAdapterClose pISysEthernet->ISysEthernetAdapterClose
	#define CHK_SysEthernetSysEthernetAdapterClose (pISysEthernet != NULL)
	#define EXP_SysEthernetSysEthernetAdapterClose  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysEthernetAdapterClose
	#define EXT_SysEthernetAdapterClose
	#define GET_SysEthernetAdapterClose(fl)  CAL_CMGETAPI( "SysEthernetAdapterClose" ) 
	#define CAL_SysEthernetAdapterClose pISysEthernet->ISysEthernetAdapterClose
	#define CHK_SysEthernetAdapterClose (pISysEthernet != NULL)
	#define EXP_SysEthernetAdapterClose  CAL_CMEXPAPI( "SysEthernetAdapterClose" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysEthernetAdapterClose  PFSYSETHERNETADAPTERCLOSE pfSysEthernetAdapterClose;
	#define EXT_SysEthernetAdapterClose  extern PFSYSETHERNETADAPTERCLOSE pfSysEthernetAdapterClose;
	#define GET_SysEthernetAdapterClose(fl)  s_pfCMGetAPI2( "SysEthernetAdapterClose", (RTS_VOID_FCTPTR *)&pfSysEthernetAdapterClose, (fl), 0, 0)
	#define CAL_SysEthernetAdapterClose  pfSysEthernetAdapterClose
	#define CHK_SysEthernetAdapterClose  (pfSysEthernetAdapterClose != NULL)
	#define EXP_SysEthernetAdapterClose  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysEthernetAdapterClose", (RTS_UINTPTR)SysEthernetAdapterClose, 0, 0) 
#endif




/*
 * Send and receive data
 */
/**
 * <description>Send an Ethernet frame to the adapter. The data of the frame is copied to the adapter. When this function
 * returns the frame can be overwritten without any problems.
 * <return>Result of the operation. ERR_OK if successful. ERR_INVALID_HANDLE if the handle was invalid.</return>
 * <param name="hAdapter" type="IN">Adapter where to send the frame.</param>
 * <param name="pFrame" type="IN">Pointer to frame to send.</param>
 */
RTS_RESULT CDECL SysEthernetEthFrameSend(RTS_HANDLE hAdapter, SysEthernetFrame* pFrame);
typedef RTS_RESULT (CDECL * PFSYSETHERNETETHFRAMESEND) (RTS_HANDLE hAdapter, SysEthernetFrame* pFrame);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(SYSETHERNETETHFRAMESEND_NOTIMPLEMENTED)
	#define USE_SysEthernetEthFrameSend
	#define EXT_SysEthernetEthFrameSend
	#define GET_SysEthernetEthFrameSend(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysEthernetEthFrameSend(p0,p1)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_SysEthernetEthFrameSend  FALSE
	#define EXP_SysEthernetEthFrameSend  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysEthernetEthFrameSend
	#define EXT_SysEthernetEthFrameSend
	#define GET_SysEthernetEthFrameSend(fl)  CAL_CMGETAPI( "SysEthernetEthFrameSend" ) 
	#define CAL_SysEthernetEthFrameSend  SysEthernetEthFrameSend
	#define CHK_SysEthernetEthFrameSend  TRUE
	#define EXP_SysEthernetEthFrameSend  CAL_CMEXPAPI( "SysEthernetEthFrameSend" ) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_SysEthernetEthFrameSend
	#define EXT_SysEthernetEthFrameSend
	#define GET_SysEthernetEthFrameSend(fl)  CAL_CMGETAPI( "SysEthernetEthFrameSend" ) 
	#define CAL_SysEthernetEthFrameSend  SysEthernetEthFrameSend
	#define CHK_SysEthernetEthFrameSend  TRUE
	#define EXP_SysEthernetEthFrameSend  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysEthernetEthFrameSend", (RTS_UINTPTR)SysEthernetEthFrameSend, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetSysEthernetEthFrameSend
	#define EXT_SysEthernetSysEthernetEthFrameSend
	#define GET_SysEthernetSysEthernetEthFrameSend  ERR_OK
	#define CAL_SysEthernetSysEthernetEthFrameSend pISysEthernet->ISysEthernetEthFrameSend
	#define CHK_SysEthernetSysEthernetEthFrameSend (pISysEthernet != NULL)
	#define EXP_SysEthernetSysEthernetEthFrameSend  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysEthernetEthFrameSend
	#define EXT_SysEthernetEthFrameSend
	#define GET_SysEthernetEthFrameSend(fl)  CAL_CMGETAPI( "SysEthernetEthFrameSend" ) 
	#define CAL_SysEthernetEthFrameSend pISysEthernet->ISysEthernetEthFrameSend
	#define CHK_SysEthernetEthFrameSend (pISysEthernet != NULL)
	#define EXP_SysEthernetEthFrameSend  CAL_CMEXPAPI( "SysEthernetEthFrameSend" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysEthernetEthFrameSend  PFSYSETHERNETETHFRAMESEND pfSysEthernetEthFrameSend;
	#define EXT_SysEthernetEthFrameSend  extern PFSYSETHERNETETHFRAMESEND pfSysEthernetEthFrameSend;
	#define GET_SysEthernetEthFrameSend(fl)  s_pfCMGetAPI2( "SysEthernetEthFrameSend", (RTS_VOID_FCTPTR *)&pfSysEthernetEthFrameSend, (fl), 0, 0)
	#define CAL_SysEthernetEthFrameSend  pfSysEthernetEthFrameSend
	#define CHK_SysEthernetEthFrameSend  (pfSysEthernetEthFrameSend != NULL)
	#define EXP_SysEthernetEthFrameSend  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysEthernetEthFrameSend", (RTS_UINTPTR)SysEthernetEthFrameSend, 0, 0) 
#endif




/**
 * <description>Receive an Ethernet frame for the Ethernet adapter.
 * Note: 
 *   The frame returned has to be released using the SysEthernetEthFrameRelease() function.
 *   The frame will only be overwritten if the frame is released. As frames are reused when
 *   released pay attention to call this function if processing of the frame has finished.</description>
 * <return>Pointer to the received frame. NULL if failed.</return>
 * <param name="hAdapter" type="IN">Adapter where to receive.</param>
 * <param name="pResult" type="OUT">Result of the operation.</param>
 */
SysEthernetFrame* CDECL SysEthernetEthFrameReceive(RTS_HANDLE hAdapter, RTS_RESULT* pResult);
typedef SysEthernetFrame* (CDECL * PFSYSETHERNETETHFRAMERECEIVE) (RTS_HANDLE hAdapter, RTS_RESULT* pResult);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(SYSETHERNETETHFRAMERECEIVE_NOTIMPLEMENTED)
	#define USE_SysEthernetEthFrameReceive
	#define EXT_SysEthernetEthFrameReceive
	#define GET_SysEthernetEthFrameReceive(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysEthernetEthFrameReceive(p0,p1)  (SysEthernetFrame*)ERR_NOTIMPLEMENTED
	#define CHK_SysEthernetEthFrameReceive  FALSE
	#define EXP_SysEthernetEthFrameReceive  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysEthernetEthFrameReceive
	#define EXT_SysEthernetEthFrameReceive
	#define GET_SysEthernetEthFrameReceive(fl)  CAL_CMGETAPI( "SysEthernetEthFrameReceive" ) 
	#define CAL_SysEthernetEthFrameReceive  SysEthernetEthFrameReceive
	#define CHK_SysEthernetEthFrameReceive  TRUE
	#define EXP_SysEthernetEthFrameReceive  CAL_CMEXPAPI( "SysEthernetEthFrameReceive" ) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_SysEthernetEthFrameReceive
	#define EXT_SysEthernetEthFrameReceive
	#define GET_SysEthernetEthFrameReceive(fl)  CAL_CMGETAPI( "SysEthernetEthFrameReceive" ) 
	#define CAL_SysEthernetEthFrameReceive  SysEthernetEthFrameReceive
	#define CHK_SysEthernetEthFrameReceive  TRUE
	#define EXP_SysEthernetEthFrameReceive  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysEthernetEthFrameReceive", (RTS_UINTPTR)SysEthernetEthFrameReceive, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetSysEthernetEthFrameReceive
	#define EXT_SysEthernetSysEthernetEthFrameReceive
	#define GET_SysEthernetSysEthernetEthFrameReceive  ERR_OK
	#define CAL_SysEthernetSysEthernetEthFrameReceive pISysEthernet->ISysEthernetEthFrameReceive
	#define CHK_SysEthernetSysEthernetEthFrameReceive (pISysEthernet != NULL)
	#define EXP_SysEthernetSysEthernetEthFrameReceive  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysEthernetEthFrameReceive
	#define EXT_SysEthernetEthFrameReceive
	#define GET_SysEthernetEthFrameReceive(fl)  CAL_CMGETAPI( "SysEthernetEthFrameReceive" ) 
	#define CAL_SysEthernetEthFrameReceive pISysEthernet->ISysEthernetEthFrameReceive
	#define CHK_SysEthernetEthFrameReceive (pISysEthernet != NULL)
	#define EXP_SysEthernetEthFrameReceive  CAL_CMEXPAPI( "SysEthernetEthFrameReceive" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysEthernetEthFrameReceive  PFSYSETHERNETETHFRAMERECEIVE pfSysEthernetEthFrameReceive;
	#define EXT_SysEthernetEthFrameReceive  extern PFSYSETHERNETETHFRAMERECEIVE pfSysEthernetEthFrameReceive;
	#define GET_SysEthernetEthFrameReceive(fl)  s_pfCMGetAPI2( "SysEthernetEthFrameReceive", (RTS_VOID_FCTPTR *)&pfSysEthernetEthFrameReceive, (fl), 0, 0)
	#define CAL_SysEthernetEthFrameReceive  pfSysEthernetEthFrameReceive
	#define CHK_SysEthernetEthFrameReceive  (pfSysEthernetEthFrameReceive != NULL)
	#define EXP_SysEthernetEthFrameReceive  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysEthernetEthFrameReceive", (RTS_UINTPTR)SysEthernetEthFrameReceive, 0, 0) 
#endif




/*
 * Functions for Ethernet over EtherCAT (EoE)
 */
/**
 * <description>This functions sends an Ethernet frame to the local IP Stack for processing.
 * The frame can be safely reused when this function has returned.
 * Note: Special function for Ethernet over EtherCAT (EoE)</description>
 * <return>Pointer to the received frame. NULL if failed.</return>
 * <param name="hAdapter" type="IN">Adapter where to send the IP Frame.</param>
 * <param name="pResult" type="OUT">Result of the operation.</param>
 */
RTS_RESULT CDECL SysEthernetIpFrameSend(RTS_HANDLE hAdapter, SysEthernetFrame* pFrame);
typedef RTS_RESULT (CDECL * PFSYSETHERNETIPFRAMESEND) (RTS_HANDLE hAdapter, SysEthernetFrame* pFrame);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(SYSETHERNETIPFRAMESEND_NOTIMPLEMENTED)
	#define USE_SysEthernetIpFrameSend
	#define EXT_SysEthernetIpFrameSend
	#define GET_SysEthernetIpFrameSend(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysEthernetIpFrameSend(p0,p1)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_SysEthernetIpFrameSend  FALSE
	#define EXP_SysEthernetIpFrameSend  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysEthernetIpFrameSend
	#define EXT_SysEthernetIpFrameSend
	#define GET_SysEthernetIpFrameSend(fl)  CAL_CMGETAPI( "SysEthernetIpFrameSend" ) 
	#define CAL_SysEthernetIpFrameSend  SysEthernetIpFrameSend
	#define CHK_SysEthernetIpFrameSend  TRUE
	#define EXP_SysEthernetIpFrameSend  CAL_CMEXPAPI( "SysEthernetIpFrameSend" ) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_SysEthernetIpFrameSend
	#define EXT_SysEthernetIpFrameSend
	#define GET_SysEthernetIpFrameSend(fl)  CAL_CMGETAPI( "SysEthernetIpFrameSend" ) 
	#define CAL_SysEthernetIpFrameSend  SysEthernetIpFrameSend
	#define CHK_SysEthernetIpFrameSend  TRUE
	#define EXP_SysEthernetIpFrameSend  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysEthernetIpFrameSend", (RTS_UINTPTR)SysEthernetIpFrameSend, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetSysEthernetIpFrameSend
	#define EXT_SysEthernetSysEthernetIpFrameSend
	#define GET_SysEthernetSysEthernetIpFrameSend  ERR_OK
	#define CAL_SysEthernetSysEthernetIpFrameSend pISysEthernet->ISysEthernetIpFrameSend
	#define CHK_SysEthernetSysEthernetIpFrameSend (pISysEthernet != NULL)
	#define EXP_SysEthernetSysEthernetIpFrameSend  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysEthernetIpFrameSend
	#define EXT_SysEthernetIpFrameSend
	#define GET_SysEthernetIpFrameSend(fl)  CAL_CMGETAPI( "SysEthernetIpFrameSend" ) 
	#define CAL_SysEthernetIpFrameSend pISysEthernet->ISysEthernetIpFrameSend
	#define CHK_SysEthernetIpFrameSend (pISysEthernet != NULL)
	#define EXP_SysEthernetIpFrameSend  CAL_CMEXPAPI( "SysEthernetIpFrameSend" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysEthernetIpFrameSend  PFSYSETHERNETIPFRAMESEND pfSysEthernetIpFrameSend;
	#define EXT_SysEthernetIpFrameSend  extern PFSYSETHERNETIPFRAMESEND pfSysEthernetIpFrameSend;
	#define GET_SysEthernetIpFrameSend(fl)  s_pfCMGetAPI2( "SysEthernetIpFrameSend", (RTS_VOID_FCTPTR *)&pfSysEthernetIpFrameSend, (fl), 0, 0)
	#define CAL_SysEthernetIpFrameSend  pfSysEthernetIpFrameSend
	#define CHK_SysEthernetIpFrameSend  (pfSysEthernetIpFrameSend != NULL)
	#define EXP_SysEthernetIpFrameSend  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysEthernetIpFrameSend", (RTS_UINTPTR)SysEthernetIpFrameSend, 0, 0) 
#endif




/**
 * <description>This function receives an IP frame from the systems IP Stack.
 * This frame has to be packed into an EtherCAT frame and sent to
 * this adapter.
 * Note: Special function for Ethernet over EtherCAT (EoE) </description>
 * <return>Pointer to the received frame. NULL if failed.</return>
 * <param name="hAdapter" type="IN">Adapter where to receive the IP Frame.</param>
 * <param name="pResult" type="OUT">Result of the operation.</param>
 */
SysEthernetFrame* CDECL SysEthernetIpFrameReceive(RTS_HANDLE hAdapter, RTS_RESULT* pResult);
typedef SysEthernetFrame* (CDECL * PFSYSETHERNETIPFRAMERECEIVE) (RTS_HANDLE hAdapter, RTS_RESULT* pResult);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(SYSETHERNETIPFRAMERECEIVE_NOTIMPLEMENTED)
	#define USE_SysEthernetIpFrameReceive
	#define EXT_SysEthernetIpFrameReceive
	#define GET_SysEthernetIpFrameReceive(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysEthernetIpFrameReceive(p0,p1)  (SysEthernetFrame*)ERR_NOTIMPLEMENTED
	#define CHK_SysEthernetIpFrameReceive  FALSE
	#define EXP_SysEthernetIpFrameReceive  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysEthernetIpFrameReceive
	#define EXT_SysEthernetIpFrameReceive
	#define GET_SysEthernetIpFrameReceive(fl)  CAL_CMGETAPI( "SysEthernetIpFrameReceive" ) 
	#define CAL_SysEthernetIpFrameReceive  SysEthernetIpFrameReceive
	#define CHK_SysEthernetIpFrameReceive  TRUE
	#define EXP_SysEthernetIpFrameReceive  CAL_CMEXPAPI( "SysEthernetIpFrameReceive" ) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_SysEthernetIpFrameReceive
	#define EXT_SysEthernetIpFrameReceive
	#define GET_SysEthernetIpFrameReceive(fl)  CAL_CMGETAPI( "SysEthernetIpFrameReceive" ) 
	#define CAL_SysEthernetIpFrameReceive  SysEthernetIpFrameReceive
	#define CHK_SysEthernetIpFrameReceive  TRUE
	#define EXP_SysEthernetIpFrameReceive  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysEthernetIpFrameReceive", (RTS_UINTPTR)SysEthernetIpFrameReceive, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetSysEthernetIpFrameReceive
	#define EXT_SysEthernetSysEthernetIpFrameReceive
	#define GET_SysEthernetSysEthernetIpFrameReceive  ERR_OK
	#define CAL_SysEthernetSysEthernetIpFrameReceive pISysEthernet->ISysEthernetIpFrameReceive
	#define CHK_SysEthernetSysEthernetIpFrameReceive (pISysEthernet != NULL)
	#define EXP_SysEthernetSysEthernetIpFrameReceive  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysEthernetIpFrameReceive
	#define EXT_SysEthernetIpFrameReceive
	#define GET_SysEthernetIpFrameReceive(fl)  CAL_CMGETAPI( "SysEthernetIpFrameReceive" ) 
	#define CAL_SysEthernetIpFrameReceive pISysEthernet->ISysEthernetIpFrameReceive
	#define CHK_SysEthernetIpFrameReceive (pISysEthernet != NULL)
	#define EXP_SysEthernetIpFrameReceive  CAL_CMEXPAPI( "SysEthernetIpFrameReceive" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysEthernetIpFrameReceive  PFSYSETHERNETIPFRAMERECEIVE pfSysEthernetIpFrameReceive;
	#define EXT_SysEthernetIpFrameReceive  extern PFSYSETHERNETIPFRAMERECEIVE pfSysEthernetIpFrameReceive;
	#define GET_SysEthernetIpFrameReceive(fl)  s_pfCMGetAPI2( "SysEthernetIpFrameReceive", (RTS_VOID_FCTPTR *)&pfSysEthernetIpFrameReceive, (fl), 0, 0)
	#define CAL_SysEthernetIpFrameReceive  pfSysEthernetIpFrameReceive
	#define CHK_SysEthernetIpFrameReceive  (pfSysEthernetIpFrameReceive != NULL)
	#define EXP_SysEthernetIpFrameReceive  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysEthernetIpFrameReceive", (RTS_UINTPTR)SysEthernetIpFrameReceive, 0, 0) 
#endif




/*
 * Helper functions
 */
 /**
 * <description>Release a received frame to indicate that the frame can be reused.</description>
 * <param name="pFrame" type="IN">Pointer to the frame to release</param>
 */
RTS_RESULT CDECL SysEthernetFrameRelease(SysEthernetFrame* pFrame);
typedef RTS_RESULT (CDECL * PFSYSETHERNETFRAMERELEASE) (SysEthernetFrame* pFrame);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(SYSETHERNETFRAMERELEASE_NOTIMPLEMENTED)
	#define USE_SysEthernetFrameRelease
	#define EXT_SysEthernetFrameRelease
	#define GET_SysEthernetFrameRelease(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysEthernetFrameRelease(p0)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_SysEthernetFrameRelease  FALSE
	#define EXP_SysEthernetFrameRelease  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysEthernetFrameRelease
	#define EXT_SysEthernetFrameRelease
	#define GET_SysEthernetFrameRelease(fl)  CAL_CMGETAPI( "SysEthernetFrameRelease" ) 
	#define CAL_SysEthernetFrameRelease  SysEthernetFrameRelease
	#define CHK_SysEthernetFrameRelease  TRUE
	#define EXP_SysEthernetFrameRelease  CAL_CMEXPAPI( "SysEthernetFrameRelease" ) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_SysEthernetFrameRelease
	#define EXT_SysEthernetFrameRelease
	#define GET_SysEthernetFrameRelease(fl)  CAL_CMGETAPI( "SysEthernetFrameRelease" ) 
	#define CAL_SysEthernetFrameRelease  SysEthernetFrameRelease
	#define CHK_SysEthernetFrameRelease  TRUE
	#define EXP_SysEthernetFrameRelease  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysEthernetFrameRelease", (RTS_UINTPTR)SysEthernetFrameRelease, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetSysEthernetFrameRelease
	#define EXT_SysEthernetSysEthernetFrameRelease
	#define GET_SysEthernetSysEthernetFrameRelease  ERR_OK
	#define CAL_SysEthernetSysEthernetFrameRelease pISysEthernet->ISysEthernetFrameRelease
	#define CHK_SysEthernetSysEthernetFrameRelease (pISysEthernet != NULL)
	#define EXP_SysEthernetSysEthernetFrameRelease  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysEthernetFrameRelease
	#define EXT_SysEthernetFrameRelease
	#define GET_SysEthernetFrameRelease(fl)  CAL_CMGETAPI( "SysEthernetFrameRelease" ) 
	#define CAL_SysEthernetFrameRelease pISysEthernet->ISysEthernetFrameRelease
	#define CHK_SysEthernetFrameRelease (pISysEthernet != NULL)
	#define EXP_SysEthernetFrameRelease  CAL_CMEXPAPI( "SysEthernetFrameRelease" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysEthernetFrameRelease  PFSYSETHERNETFRAMERELEASE pfSysEthernetFrameRelease;
	#define EXT_SysEthernetFrameRelease  extern PFSYSETHERNETFRAMERELEASE pfSysEthernetFrameRelease;
	#define GET_SysEthernetFrameRelease(fl)  s_pfCMGetAPI2( "SysEthernetFrameRelease", (RTS_VOID_FCTPTR *)&pfSysEthernetFrameRelease, (fl), 0, 0)
	#define CAL_SysEthernetFrameRelease  pfSysEthernetFrameRelease
	#define CHK_SysEthernetFrameRelease  (pfSysEthernetFrameRelease != NULL)
	#define EXP_SysEthernetFrameRelease  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysEthernetFrameRelease", (RTS_UINTPTR)SysEthernetFrameRelease, 0, 0) 
#endif





/*
* Functions for accessing the MAU type etc.
*/

#define SYSETH_CONFIG_AND_STATUS_STRUCT_VERSION		1	/* version number of structure, to be increased on changes */

/**
* <description>Get Ethernet port configuration and status of an adapter identified by its MAC address.</description>
* <param name="pMacAddress" type="IN">Pointer to the MAC address of the adapter to get information from.</param>
* <param name="macSize" type="IN">Size of the MAC address. This is usually 6 bytes.</param>
* <param name="pPortConfigAndStatus" type="IN">Structure to be filled with the configuration and status data. The structure element udiStructSize must contain a valid size for the structure.</param>
* <result>Runtime system error code</result>
* <errorcode name="RTS_RESULT" type="ERR_OK">Information is available</errorcode>
* <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Parameter error</errorcode>
* <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">No adapter with the provided MAC address could be found</errorcode>
* <errorcode name="RTS_RESULT" type="ERR_FAILED">Generic error, typically occurred in lower layer</errorcode>
* <errorcode name="RTS_RESULT" type="ERR_NOTIMPLEMENTED">Function is not implemented/error code>
*/
RTS_RESULT CDECL SysEthernetGetPortConfigAndStatus(RTS_UI8* pMacAddress, RTS_SIZE macSize, SysEthernetPortConfigAndStatus* pPortConfigAndStatus);
typedef RTS_RESULT (CDECL * PFSYSETHERNETGETPORTCONFIGANDSTATUS) (RTS_UI8* pMacAddress, RTS_SIZE macSize, SysEthernetPortConfigAndStatus* pPortConfigAndStatus);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(SYSETHERNETGETPORTCONFIGANDSTATUS_NOTIMPLEMENTED)
	#define USE_SysEthernetGetPortConfigAndStatus
	#define EXT_SysEthernetGetPortConfigAndStatus
	#define GET_SysEthernetGetPortConfigAndStatus(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysEthernetGetPortConfigAndStatus(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_SysEthernetGetPortConfigAndStatus  FALSE
	#define EXP_SysEthernetGetPortConfigAndStatus  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysEthernetGetPortConfigAndStatus
	#define EXT_SysEthernetGetPortConfigAndStatus
	#define GET_SysEthernetGetPortConfigAndStatus(fl)  CAL_CMGETAPI( "SysEthernetGetPortConfigAndStatus" ) 
	#define CAL_SysEthernetGetPortConfigAndStatus  SysEthernetGetPortConfigAndStatus
	#define CHK_SysEthernetGetPortConfigAndStatus  TRUE
	#define EXP_SysEthernetGetPortConfigAndStatus  CAL_CMEXPAPI( "SysEthernetGetPortConfigAndStatus" ) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_SysEthernetGetPortConfigAndStatus
	#define EXT_SysEthernetGetPortConfigAndStatus
	#define GET_SysEthernetGetPortConfigAndStatus(fl)  CAL_CMGETAPI( "SysEthernetGetPortConfigAndStatus" ) 
	#define CAL_SysEthernetGetPortConfigAndStatus  SysEthernetGetPortConfigAndStatus
	#define CHK_SysEthernetGetPortConfigAndStatus  TRUE
	#define EXP_SysEthernetGetPortConfigAndStatus  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysEthernetGetPortConfigAndStatus", (RTS_UINTPTR)SysEthernetGetPortConfigAndStatus, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetSysEthernetGetPortConfigAndStatus
	#define EXT_SysEthernetSysEthernetGetPortConfigAndStatus
	#define GET_SysEthernetSysEthernetGetPortConfigAndStatus  ERR_OK
	#define CAL_SysEthernetSysEthernetGetPortConfigAndStatus pISysEthernet->ISysEthernetGetPortConfigAndStatus
	#define CHK_SysEthernetSysEthernetGetPortConfigAndStatus (pISysEthernet != NULL)
	#define EXP_SysEthernetSysEthernetGetPortConfigAndStatus  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysEthernetGetPortConfigAndStatus
	#define EXT_SysEthernetGetPortConfigAndStatus
	#define GET_SysEthernetGetPortConfigAndStatus(fl)  CAL_CMGETAPI( "SysEthernetGetPortConfigAndStatus" ) 
	#define CAL_SysEthernetGetPortConfigAndStatus pISysEthernet->ISysEthernetGetPortConfigAndStatus
	#define CHK_SysEthernetGetPortConfigAndStatus (pISysEthernet != NULL)
	#define EXP_SysEthernetGetPortConfigAndStatus  CAL_CMEXPAPI( "SysEthernetGetPortConfigAndStatus" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysEthernetGetPortConfigAndStatus  PFSYSETHERNETGETPORTCONFIGANDSTATUS pfSysEthernetGetPortConfigAndStatus;
	#define EXT_SysEthernetGetPortConfigAndStatus  extern PFSYSETHERNETGETPORTCONFIGANDSTATUS pfSysEthernetGetPortConfigAndStatus;
	#define GET_SysEthernetGetPortConfigAndStatus(fl)  s_pfCMGetAPI2( "SysEthernetGetPortConfigAndStatus", (RTS_VOID_FCTPTR *)&pfSysEthernetGetPortConfigAndStatus, (fl), 0, 0)
	#define CAL_SysEthernetGetPortConfigAndStatus  pfSysEthernetGetPortConfigAndStatus
	#define CHK_SysEthernetGetPortConfigAndStatus  (pfSysEthernetGetPortConfigAndStatus != NULL)
	#define EXP_SysEthernetGetPortConfigAndStatus  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysEthernetGetPortConfigAndStatus", (RTS_UINTPTR)SysEthernetGetPortConfigAndStatus, 0, 0) 
#endif




/**
* <description>Set advertised auto-negotiation capabilities for an adapter identified by its MAC address.</description>
* <param name="pMacAddress" type="IN">Pointer to the MAC address of the adapter.</param>
* <param name="macSize" type="IN">Size of the MAC address. This is usually 6 bytes.</param>
* <param name="ui64AutoNegAdvertisedCap" type="IN">Advertised auto-negotiation capabilities of MAU, see AutoNegCaps constants SYSETH_AUTONEGCAP_...</param>
* <result>Runtime system error code</result>
*/
RTS_RESULT CDECL SysEthernetSetAutoNegAdvertisedCap(RTS_UI8* pMacAddress, RTS_SIZE macSize, RTS_UI64 ui64AutoNegAdvertisedCap);
typedef RTS_RESULT (CDECL * PFSYSETHERNETSETAUTONEGADVERTISEDCAP) (RTS_UI8* pMacAddress, RTS_SIZE macSize, RTS_UI64 ui64AutoNegAdvertisedCap);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(SYSETHERNETSETAUTONEGADVERTISEDCAP_NOTIMPLEMENTED)
	#define USE_SysEthernetSetAutoNegAdvertisedCap
	#define EXT_SysEthernetSetAutoNegAdvertisedCap
	#define GET_SysEthernetSetAutoNegAdvertisedCap(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysEthernetSetAutoNegAdvertisedCap(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_SysEthernetSetAutoNegAdvertisedCap  FALSE
	#define EXP_SysEthernetSetAutoNegAdvertisedCap  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysEthernetSetAutoNegAdvertisedCap
	#define EXT_SysEthernetSetAutoNegAdvertisedCap
	#define GET_SysEthernetSetAutoNegAdvertisedCap(fl)  CAL_CMGETAPI( "SysEthernetSetAutoNegAdvertisedCap" ) 
	#define CAL_SysEthernetSetAutoNegAdvertisedCap  SysEthernetSetAutoNegAdvertisedCap
	#define CHK_SysEthernetSetAutoNegAdvertisedCap  TRUE
	#define EXP_SysEthernetSetAutoNegAdvertisedCap  CAL_CMEXPAPI( "SysEthernetSetAutoNegAdvertisedCap" ) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_SysEthernetSetAutoNegAdvertisedCap
	#define EXT_SysEthernetSetAutoNegAdvertisedCap
	#define GET_SysEthernetSetAutoNegAdvertisedCap(fl)  CAL_CMGETAPI( "SysEthernetSetAutoNegAdvertisedCap" ) 
	#define CAL_SysEthernetSetAutoNegAdvertisedCap  SysEthernetSetAutoNegAdvertisedCap
	#define CHK_SysEthernetSetAutoNegAdvertisedCap  TRUE
	#define EXP_SysEthernetSetAutoNegAdvertisedCap  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysEthernetSetAutoNegAdvertisedCap", (RTS_UINTPTR)SysEthernetSetAutoNegAdvertisedCap, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetSysEthernetSetAutoNegAdvertisedCap
	#define EXT_SysEthernetSysEthernetSetAutoNegAdvertisedCap
	#define GET_SysEthernetSysEthernetSetAutoNegAdvertisedCap  ERR_OK
	#define CAL_SysEthernetSysEthernetSetAutoNegAdvertisedCap pISysEthernet->ISysEthernetSetAutoNegAdvertisedCap
	#define CHK_SysEthernetSysEthernetSetAutoNegAdvertisedCap (pISysEthernet != NULL)
	#define EXP_SysEthernetSysEthernetSetAutoNegAdvertisedCap  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysEthernetSetAutoNegAdvertisedCap
	#define EXT_SysEthernetSetAutoNegAdvertisedCap
	#define GET_SysEthernetSetAutoNegAdvertisedCap(fl)  CAL_CMGETAPI( "SysEthernetSetAutoNegAdvertisedCap" ) 
	#define CAL_SysEthernetSetAutoNegAdvertisedCap pISysEthernet->ISysEthernetSetAutoNegAdvertisedCap
	#define CHK_SysEthernetSetAutoNegAdvertisedCap (pISysEthernet != NULL)
	#define EXP_SysEthernetSetAutoNegAdvertisedCap  CAL_CMEXPAPI( "SysEthernetSetAutoNegAdvertisedCap" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysEthernetSetAutoNegAdvertisedCap  PFSYSETHERNETSETAUTONEGADVERTISEDCAP pfSysEthernetSetAutoNegAdvertisedCap;
	#define EXT_SysEthernetSetAutoNegAdvertisedCap  extern PFSYSETHERNETSETAUTONEGADVERTISEDCAP pfSysEthernetSetAutoNegAdvertisedCap;
	#define GET_SysEthernetSetAutoNegAdvertisedCap(fl)  s_pfCMGetAPI2( "SysEthernetSetAutoNegAdvertisedCap", (RTS_VOID_FCTPTR *)&pfSysEthernetSetAutoNegAdvertisedCap, (fl), 0, 0)
	#define CAL_SysEthernetSetAutoNegAdvertisedCap  pfSysEthernetSetAutoNegAdvertisedCap
	#define CHK_SysEthernetSetAutoNegAdvertisedCap  (pfSysEthernetSetAutoNegAdvertisedCap != NULL)
	#define EXP_SysEthernetSetAutoNegAdvertisedCap  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysEthernetSetAutoNegAdvertisedCap", (RTS_UINTPTR)SysEthernetSetAutoNegAdvertisedCap, 0, 0) 
#endif




/**
* <description>Set auto-negotiation mode for an adapter identified by its MAC address.</description>
* <param name="pMacAddress" type="IN">Pointer to the MAC address of the adapter.</param>
* <param name="macSize" type="IN">Size of the MAC address. This is usually 6 bytes.</param>
* <param name="ui8AutoNegMode" type="IN">Auto-negotiation mode of MAU, see AutoNegMode constants SYSETH_AUTONEGMODE_...</param>
* <result>Runtime system error code</result>
*/
RTS_RESULT CDECL SysEthernetSetAutoNegMode(RTS_UI8* pMacAddress, RTS_SIZE macSize, RTS_UI8 ui8AutoNegMode);
typedef RTS_RESULT (CDECL * PFSYSETHERNETSETAUTONEGMODE) (RTS_UI8* pMacAddress, RTS_SIZE macSize, RTS_UI8 ui8AutoNegMode);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(SYSETHERNETSETAUTONEGMODE_NOTIMPLEMENTED)
	#define USE_SysEthernetSetAutoNegMode
	#define EXT_SysEthernetSetAutoNegMode
	#define GET_SysEthernetSetAutoNegMode(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysEthernetSetAutoNegMode(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_SysEthernetSetAutoNegMode  FALSE
	#define EXP_SysEthernetSetAutoNegMode  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysEthernetSetAutoNegMode
	#define EXT_SysEthernetSetAutoNegMode
	#define GET_SysEthernetSetAutoNegMode(fl)  CAL_CMGETAPI( "SysEthernetSetAutoNegMode" ) 
	#define CAL_SysEthernetSetAutoNegMode  SysEthernetSetAutoNegMode
	#define CHK_SysEthernetSetAutoNegMode  TRUE
	#define EXP_SysEthernetSetAutoNegMode  CAL_CMEXPAPI( "SysEthernetSetAutoNegMode" ) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_SysEthernetSetAutoNegMode
	#define EXT_SysEthernetSetAutoNegMode
	#define GET_SysEthernetSetAutoNegMode(fl)  CAL_CMGETAPI( "SysEthernetSetAutoNegMode" ) 
	#define CAL_SysEthernetSetAutoNegMode  SysEthernetSetAutoNegMode
	#define CHK_SysEthernetSetAutoNegMode  TRUE
	#define EXP_SysEthernetSetAutoNegMode  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysEthernetSetAutoNegMode", (RTS_UINTPTR)SysEthernetSetAutoNegMode, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetSysEthernetSetAutoNegMode
	#define EXT_SysEthernetSysEthernetSetAutoNegMode
	#define GET_SysEthernetSysEthernetSetAutoNegMode  ERR_OK
	#define CAL_SysEthernetSysEthernetSetAutoNegMode pISysEthernet->ISysEthernetSetAutoNegMode
	#define CHK_SysEthernetSysEthernetSetAutoNegMode (pISysEthernet != NULL)
	#define EXP_SysEthernetSysEthernetSetAutoNegMode  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysEthernetSetAutoNegMode
	#define EXT_SysEthernetSetAutoNegMode
	#define GET_SysEthernetSetAutoNegMode(fl)  CAL_CMGETAPI( "SysEthernetSetAutoNegMode" ) 
	#define CAL_SysEthernetSetAutoNegMode pISysEthernet->ISysEthernetSetAutoNegMode
	#define CHK_SysEthernetSetAutoNegMode (pISysEthernet != NULL)
	#define EXP_SysEthernetSetAutoNegMode  CAL_CMEXPAPI( "SysEthernetSetAutoNegMode" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysEthernetSetAutoNegMode  PFSYSETHERNETSETAUTONEGMODE pfSysEthernetSetAutoNegMode;
	#define EXT_SysEthernetSetAutoNegMode  extern PFSYSETHERNETSETAUTONEGMODE pfSysEthernetSetAutoNegMode;
	#define GET_SysEthernetSetAutoNegMode(fl)  s_pfCMGetAPI2( "SysEthernetSetAutoNegMode", (RTS_VOID_FCTPTR *)&pfSysEthernetSetAutoNegMode, (fl), 0, 0)
	#define CAL_SysEthernetSetAutoNegMode  pfSysEthernetSetAutoNegMode
	#define CHK_SysEthernetSetAutoNegMode  (pfSysEthernetSetAutoNegMode != NULL)
	#define EXP_SysEthernetSetAutoNegMode  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysEthernetSetAutoNegMode", (RTS_UINTPTR)SysEthernetSetAutoNegMode, 0, 0) 
#endif




/**
* <description>Set Media Access Unit (MAU) type for an adapter identified by its MAC address.</description>
* <param name="pMacAddress" type="IN">Pointer to the MAC address of the adapter.</param>
* <param name="macSize" type="IN">Size of the MAC address. This is usually 6 bytes.</param>
* <param name="ui32MauType" type="IN">Media Access Unit (MAU) type, see MauType constants SYSETH_MAUTYPE_...</param>
* <result>Runtime system error code</result>
*/
RTS_RESULT CDECL SysEthernetSetMauType(RTS_UI8* pMacAddress, RTS_SIZE macSize, RTS_UI32 ui32MauType);
typedef RTS_RESULT (CDECL * PFSYSETHERNETSETMAUTYPE) (RTS_UI8* pMacAddress, RTS_SIZE macSize, RTS_UI32 ui32MauType);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(SYSETHERNETSETMAUTYPE_NOTIMPLEMENTED)
	#define USE_SysEthernetSetMauType
	#define EXT_SysEthernetSetMauType
	#define GET_SysEthernetSetMauType(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysEthernetSetMauType(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_SysEthernetSetMauType  FALSE
	#define EXP_SysEthernetSetMauType  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysEthernetSetMauType
	#define EXT_SysEthernetSetMauType
	#define GET_SysEthernetSetMauType(fl)  CAL_CMGETAPI( "SysEthernetSetMauType" ) 
	#define CAL_SysEthernetSetMauType  SysEthernetSetMauType
	#define CHK_SysEthernetSetMauType  TRUE
	#define EXP_SysEthernetSetMauType  CAL_CMEXPAPI( "SysEthernetSetMauType" ) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_SysEthernetSetMauType
	#define EXT_SysEthernetSetMauType
	#define GET_SysEthernetSetMauType(fl)  CAL_CMGETAPI( "SysEthernetSetMauType" ) 
	#define CAL_SysEthernetSetMauType  SysEthernetSetMauType
	#define CHK_SysEthernetSetMauType  TRUE
	#define EXP_SysEthernetSetMauType  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysEthernetSetMauType", (RTS_UINTPTR)SysEthernetSetMauType, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetSysEthernetSetMauType
	#define EXT_SysEthernetSysEthernetSetMauType
	#define GET_SysEthernetSysEthernetSetMauType  ERR_OK
	#define CAL_SysEthernetSysEthernetSetMauType pISysEthernet->ISysEthernetSetMauType
	#define CHK_SysEthernetSysEthernetSetMauType (pISysEthernet != NULL)
	#define EXP_SysEthernetSysEthernetSetMauType  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysEthernetSetMauType
	#define EXT_SysEthernetSetMauType
	#define GET_SysEthernetSetMauType(fl)  CAL_CMGETAPI( "SysEthernetSetMauType" ) 
	#define CAL_SysEthernetSetMauType pISysEthernet->ISysEthernetSetMauType
	#define CHK_SysEthernetSetMauType (pISysEthernet != NULL)
	#define EXP_SysEthernetSetMauType  CAL_CMEXPAPI( "SysEthernetSetMauType" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysEthernetSetMauType  PFSYSETHERNETSETMAUTYPE pfSysEthernetSetMauType;
	#define EXT_SysEthernetSetMauType  extern PFSYSETHERNETSETMAUTYPE pfSysEthernetSetMauType;
	#define GET_SysEthernetSetMauType(fl)  s_pfCMGetAPI2( "SysEthernetSetMauType", (RTS_VOID_FCTPTR *)&pfSysEthernetSetMauType, (fl), 0, 0)
	#define CAL_SysEthernetSetMauType  pfSysEthernetSetMauType
	#define CHK_SysEthernetSetMauType  (pfSysEthernetSetMauType != NULL)
	#define EXP_SysEthernetSetMauType  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysEthernetSetMauType", (RTS_UINTPTR)SysEthernetSetMauType, 0, 0) 
#endif




/**
* <description>Get EIP Interface Counters of an adapter identified by its MAC address.</description>
* <param name="pMacAddress" type="IN">Pointer to the MAC address of the adapter to get information from.</param>
* <param name="macSize" type="IN">Size of the MAC address. This is usually 6 bytes.</param>
* <param name="pSysEthernetInterfaceCounters" type="IN">EIP Interface Counters structure</param>
* <param name="getAndClear" type="IN">Set the counters to zero after the response is built.</param>
* <result>Runtime system error code</result>
* <errorcode name="RTS_RESULT" type="ERR_OK">Information is available</errorcode>
* <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Parameter error</errorcode>
* <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">No adapter with the provided MAC address could be found</errorcode>
* <errorcode name="RTS_RESULT" type="ERR_FAILED">Generic error, typically occurred in lower layer</errorcode>
* <errorcode name="RTS_RESULT" type="ERR_NOTIMPLEMENTED">Function is not implemented/error code>
*/
RTS_RESULT CDECL SysEthernetGetInterfaceCounters(RTS_UI8* pMacAddress, RTS_SIZE macSize, SysEthernetInterfaceCounters* pSysEthernetInterfaceCounters, RTS_BOOL getAndClear);
typedef RTS_RESULT (CDECL * PFSYSETHERNETGETINTERFACECOUNTERS) (RTS_UI8* pMacAddress, RTS_SIZE macSize, SysEthernetInterfaceCounters* pSysEthernetInterfaceCounters, RTS_BOOL getAndClear);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(SYSETHERNETGETINTERFACECOUNTERS_NOTIMPLEMENTED)
	#define USE_SysEthernetGetInterfaceCounters
	#define EXT_SysEthernetGetInterfaceCounters
	#define GET_SysEthernetGetInterfaceCounters(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysEthernetGetInterfaceCounters(p0,p1,p2,p3)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_SysEthernetGetInterfaceCounters  FALSE
	#define EXP_SysEthernetGetInterfaceCounters  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysEthernetGetInterfaceCounters
	#define EXT_SysEthernetGetInterfaceCounters
	#define GET_SysEthernetGetInterfaceCounters(fl)  CAL_CMGETAPI( "SysEthernetGetInterfaceCounters" ) 
	#define CAL_SysEthernetGetInterfaceCounters  SysEthernetGetInterfaceCounters
	#define CHK_SysEthernetGetInterfaceCounters  TRUE
	#define EXP_SysEthernetGetInterfaceCounters  CAL_CMEXPAPI( "SysEthernetGetInterfaceCounters" ) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_SysEthernetGetInterfaceCounters
	#define EXT_SysEthernetGetInterfaceCounters
	#define GET_SysEthernetGetInterfaceCounters(fl)  CAL_CMGETAPI( "SysEthernetGetInterfaceCounters" ) 
	#define CAL_SysEthernetGetInterfaceCounters  SysEthernetGetInterfaceCounters
	#define CHK_SysEthernetGetInterfaceCounters  TRUE
	#define EXP_SysEthernetGetInterfaceCounters  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysEthernetGetInterfaceCounters", (RTS_UINTPTR)SysEthernetGetInterfaceCounters, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetSysEthernetGetInterfaceCounters
	#define EXT_SysEthernetSysEthernetGetInterfaceCounters
	#define GET_SysEthernetSysEthernetGetInterfaceCounters  ERR_OK
	#define CAL_SysEthernetSysEthernetGetInterfaceCounters pISysEthernet->ISysEthernetGetInterfaceCounters
	#define CHK_SysEthernetSysEthernetGetInterfaceCounters (pISysEthernet != NULL)
	#define EXP_SysEthernetSysEthernetGetInterfaceCounters  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysEthernetGetInterfaceCounters
	#define EXT_SysEthernetGetInterfaceCounters
	#define GET_SysEthernetGetInterfaceCounters(fl)  CAL_CMGETAPI( "SysEthernetGetInterfaceCounters" ) 
	#define CAL_SysEthernetGetInterfaceCounters pISysEthernet->ISysEthernetGetInterfaceCounters
	#define CHK_SysEthernetGetInterfaceCounters (pISysEthernet != NULL)
	#define EXP_SysEthernetGetInterfaceCounters  CAL_CMEXPAPI( "SysEthernetGetInterfaceCounters" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysEthernetGetInterfaceCounters  PFSYSETHERNETGETINTERFACECOUNTERS pfSysEthernetGetInterfaceCounters;
	#define EXT_SysEthernetGetInterfaceCounters  extern PFSYSETHERNETGETINTERFACECOUNTERS pfSysEthernetGetInterfaceCounters;
	#define GET_SysEthernetGetInterfaceCounters(fl)  s_pfCMGetAPI2( "SysEthernetGetInterfaceCounters", (RTS_VOID_FCTPTR *)&pfSysEthernetGetInterfaceCounters, (fl), 0, 0)
	#define CAL_SysEthernetGetInterfaceCounters  pfSysEthernetGetInterfaceCounters
	#define CHK_SysEthernetGetInterfaceCounters  (pfSysEthernetGetInterfaceCounters != NULL)
	#define EXP_SysEthernetGetInterfaceCounters  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysEthernetGetInterfaceCounters", (RTS_UINTPTR)SysEthernetGetInterfaceCounters, 0, 0) 
#endif




/**
* <description>Get EIP Media Counters of an adapter identified by its MAC address.</description>
* <param name="pMacAddress" type="IN">Pointer to the MAC address of the adapter to get information from.</param>
* <param name="macSize" type="IN">Size of the MAC address. This is usually 6 bytes.</param>
* <param name="pSysEthernetMediaCounters" type="IN">EIP Media Counters structure</param>
* <param name="getAndClear" type="IN">Set the counters to zero after the response is built.</param>
* <result>Runtime system error code</result>
* <errorcode name="RTS_RESULT" type="ERR_OK">Information is available</errorcode>
* <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Parameter error</errorcode>
* <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">No adapter with the provided MAC address could be found</errorcode>
* <errorcode name="RTS_RESULT" type="ERR_FAILED">Generic error, typically occurred in lower layer</errorcode>
* <errorcode name="RTS_RESULT" type="ERR_NOTIMPLEMENTED">Function is not implemented/error code>
*/
RTS_RESULT CDECL SysEthernetGetMediaCounters(RTS_UI8* pMacAddress, RTS_SIZE macSize, SysEthernetMediaCounters* pSysEthernetMediaCounters, RTS_BOOL getAndClear);
typedef RTS_RESULT (CDECL * PFSYSETHERNETGETMEDIACOUNTERS) (RTS_UI8* pMacAddress, RTS_SIZE macSize, SysEthernetMediaCounters* pSysEthernetMediaCounters, RTS_BOOL getAndClear);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(SYSETHERNETGETMEDIACOUNTERS_NOTIMPLEMENTED)
	#define USE_SysEthernetGetMediaCounters
	#define EXT_SysEthernetGetMediaCounters
	#define GET_SysEthernetGetMediaCounters(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysEthernetGetMediaCounters(p0,p1,p2,p3)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_SysEthernetGetMediaCounters  FALSE
	#define EXP_SysEthernetGetMediaCounters  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysEthernetGetMediaCounters
	#define EXT_SysEthernetGetMediaCounters
	#define GET_SysEthernetGetMediaCounters(fl)  CAL_CMGETAPI( "SysEthernetGetMediaCounters" ) 
	#define CAL_SysEthernetGetMediaCounters  SysEthernetGetMediaCounters
	#define CHK_SysEthernetGetMediaCounters  TRUE
	#define EXP_SysEthernetGetMediaCounters  CAL_CMEXPAPI( "SysEthernetGetMediaCounters" ) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_SysEthernetGetMediaCounters
	#define EXT_SysEthernetGetMediaCounters
	#define GET_SysEthernetGetMediaCounters(fl)  CAL_CMGETAPI( "SysEthernetGetMediaCounters" ) 
	#define CAL_SysEthernetGetMediaCounters  SysEthernetGetMediaCounters
	#define CHK_SysEthernetGetMediaCounters  TRUE
	#define EXP_SysEthernetGetMediaCounters  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysEthernetGetMediaCounters", (RTS_UINTPTR)SysEthernetGetMediaCounters, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetSysEthernetGetMediaCounters
	#define EXT_SysEthernetSysEthernetGetMediaCounters
	#define GET_SysEthernetSysEthernetGetMediaCounters  ERR_OK
	#define CAL_SysEthernetSysEthernetGetMediaCounters pISysEthernet->ISysEthernetGetMediaCounters
	#define CHK_SysEthernetSysEthernetGetMediaCounters (pISysEthernet != NULL)
	#define EXP_SysEthernetSysEthernetGetMediaCounters  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysEthernetGetMediaCounters
	#define EXT_SysEthernetGetMediaCounters
	#define GET_SysEthernetGetMediaCounters(fl)  CAL_CMGETAPI( "SysEthernetGetMediaCounters" ) 
	#define CAL_SysEthernetGetMediaCounters pISysEthernet->ISysEthernetGetMediaCounters
	#define CHK_SysEthernetGetMediaCounters (pISysEthernet != NULL)
	#define EXP_SysEthernetGetMediaCounters  CAL_CMEXPAPI( "SysEthernetGetMediaCounters" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysEthernetGetMediaCounters  PFSYSETHERNETGETMEDIACOUNTERS pfSysEthernetGetMediaCounters;
	#define EXT_SysEthernetGetMediaCounters  extern PFSYSETHERNETGETMEDIACOUNTERS pfSysEthernetGetMediaCounters;
	#define GET_SysEthernetGetMediaCounters(fl)  s_pfCMGetAPI2( "SysEthernetGetMediaCounters", (RTS_VOID_FCTPTR *)&pfSysEthernetGetMediaCounters, (fl), 0, 0)
	#define CAL_SysEthernetGetMediaCounters  pfSysEthernetGetMediaCounters
	#define CHK_SysEthernetGetMediaCounters  (pfSysEthernetGetMediaCounters != NULL)
	#define EXP_SysEthernetGetMediaCounters  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysEthernetGetMediaCounters", (RTS_UINTPTR)SysEthernetGetMediaCounters, 0, 0) 
#endif




/**
* <description>Get EIP Interface Capabilities of an adapter identified by its MAC address.</description>
* <param name="pMacAddress" type="IN">Pointer to the MAC address of the adapter to get information from.</param>
* <param name="macSize" type="IN">Size of the MAC address. This is usually 6 bytes.</param>
* <param name="pSysEthernetCapabilities" type="IN">EIP Interface Capability structure</param>
* <result>Runtime system error code</result>
* <errorcode name="RTS_RESULT" type="ERR_OK">Information is available</errorcode>
* <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Parameter error</errorcode>
* <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">No adapter with the provided MAC address could be found</errorcode>
* <errorcode name="RTS_RESULT" type="ERR_FAILED">Generic error, typically occurred in lower layer</errorcode>
* <errorcode name="RTS_RESULT" type="ERR_NOTIMPLEMENTED">Function is not implemented/error code>
*/
RTS_RESULT CDECL SysEthernetGetCapabilities(RTS_UI8* pMacAddress, RTS_SIZE macSize, SysEthernetCapabilities* pSysEthernetCapabilities);
typedef RTS_RESULT (CDECL * PFSYSETHERNETGETCAPABILITIES) (RTS_UI8* pMacAddress, RTS_SIZE macSize, SysEthernetCapabilities* pSysEthernetCapabilities);
#if defined(SYSETHERNET_NOTIMPLEMENTED) || defined(SYSETHERNETGETCAPABILITIES_NOTIMPLEMENTED)
	#define USE_SysEthernetGetCapabilities
	#define EXT_SysEthernetGetCapabilities
	#define GET_SysEthernetGetCapabilities(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysEthernetGetCapabilities(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_SysEthernetGetCapabilities  FALSE
	#define EXP_SysEthernetGetCapabilities  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysEthernetGetCapabilities
	#define EXT_SysEthernetGetCapabilities
	#define GET_SysEthernetGetCapabilities(fl)  CAL_CMGETAPI( "SysEthernetGetCapabilities" ) 
	#define CAL_SysEthernetGetCapabilities  SysEthernetGetCapabilities
	#define CHK_SysEthernetGetCapabilities  TRUE
	#define EXP_SysEthernetGetCapabilities  CAL_CMEXPAPI( "SysEthernetGetCapabilities" ) 
#elif defined(MIXED_LINK) && !defined(SYSETHERNET_EXTERNAL)
	#define USE_SysEthernetGetCapabilities
	#define EXT_SysEthernetGetCapabilities
	#define GET_SysEthernetGetCapabilities(fl)  CAL_CMGETAPI( "SysEthernetGetCapabilities" ) 
	#define CAL_SysEthernetGetCapabilities  SysEthernetGetCapabilities
	#define CHK_SysEthernetGetCapabilities  TRUE
	#define EXP_SysEthernetGetCapabilities  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysEthernetGetCapabilities", (RTS_UINTPTR)SysEthernetGetCapabilities, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysEthernetSysEthernetGetCapabilities
	#define EXT_SysEthernetSysEthernetGetCapabilities
	#define GET_SysEthernetSysEthernetGetCapabilities  ERR_OK
	#define CAL_SysEthernetSysEthernetGetCapabilities pISysEthernet->ISysEthernetGetCapabilities
	#define CHK_SysEthernetSysEthernetGetCapabilities (pISysEthernet != NULL)
	#define EXP_SysEthernetSysEthernetGetCapabilities  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysEthernetGetCapabilities
	#define EXT_SysEthernetGetCapabilities
	#define GET_SysEthernetGetCapabilities(fl)  CAL_CMGETAPI( "SysEthernetGetCapabilities" ) 
	#define CAL_SysEthernetGetCapabilities pISysEthernet->ISysEthernetGetCapabilities
	#define CHK_SysEthernetGetCapabilities (pISysEthernet != NULL)
	#define EXP_SysEthernetGetCapabilities  CAL_CMEXPAPI( "SysEthernetGetCapabilities" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysEthernetGetCapabilities  PFSYSETHERNETGETCAPABILITIES pfSysEthernetGetCapabilities;
	#define EXT_SysEthernetGetCapabilities  extern PFSYSETHERNETGETCAPABILITIES pfSysEthernetGetCapabilities;
	#define GET_SysEthernetGetCapabilities(fl)  s_pfCMGetAPI2( "SysEthernetGetCapabilities", (RTS_VOID_FCTPTR *)&pfSysEthernetGetCapabilities, (fl), 0, 0)
	#define CAL_SysEthernetGetCapabilities  pfSysEthernetGetCapabilities
	#define CHK_SysEthernetGetCapabilities  (pfSysEthernetGetCapabilities != NULL)
	#define EXP_SysEthernetGetCapabilities  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysEthernetGetCapabilities", (RTS_UINTPTR)SysEthernetGetCapabilities, 0, 0) 
#endif




#ifdef __cplusplus
}
#endif





typedef struct
{
	IBase_C *pBase;
	PFOPENETHERNET Iopenethernet;
 	PFSENDETHFRAME Isendethframe;
 	PFGETETHFRAME Igetethframe;
 	PFCLOSEETHERNET Icloseethernet;
 	PFSENDIPETHFRAME IsendIPethframe;
 	PFGETIPETHFRAME IgetIPethframe;
 	PFSYSETHERNETADAPTEROPEN ISysEthernetAdapterOpen;
 	PFSYSETHERNETADAPTERCLOSE ISysEthernetAdapterClose;
 	PFSYSETHERNETETHFRAMESEND ISysEthernetEthFrameSend;
 	PFSYSETHERNETETHFRAMERECEIVE ISysEthernetEthFrameReceive;
 	PFSYSETHERNETIPFRAMESEND ISysEthernetIpFrameSend;
 	PFSYSETHERNETIPFRAMERECEIVE ISysEthernetIpFrameReceive;
 	PFSYSETHERNETFRAMERELEASE ISysEthernetFrameRelease;
 	PFSYSETHERNETGETPORTCONFIGANDSTATUS ISysEthernetGetPortConfigAndStatus;
 	PFSYSETHERNETSETAUTONEGADVERTISEDCAP ISysEthernetSetAutoNegAdvertisedCap;
 	PFSYSETHERNETSETAUTONEGMODE ISysEthernetSetAutoNegMode;
 	PFSYSETHERNETSETMAUTYPE ISysEthernetSetMauType;
 	PFSYSETHERNETGETINTERFACECOUNTERS ISysEthernetGetInterfaceCounters;
 	PFSYSETHERNETGETMEDIACOUNTERS ISysEthernetGetMediaCounters;
 	PFSYSETHERNETGETCAPABILITIES ISysEthernetGetCapabilities;
 } ISysEthernet_C;

#ifdef CPLUSPLUS
class ISysEthernet : public IBase
{
	public:
		virtual void CDECL Iopenethernet(OpenEthernetInterface* poei) =0;
		virtual void CDECL Isendethframe(SendEthernetInterface* psfi) =0;
		virtual void CDECL Igetethframe(GetEthernetInterface* pgei) =0;
		virtual void CDECL Icloseethernet(CloseEthernetInterface* pcei) =0;
		virtual void CDECL IsendIPethframe(SendIPEthernetInterface* psfi) =0;
		virtual void CDECL IgetIPethframe(GetIPEthernetInterface* pgei) =0;
		virtual RTS_HANDLE CDECL ISysEthernetAdapterOpen(RTS_UI8* pMacAddress, RTS_SIZE macSize, RTS_RESULT* pResult) =0;
		virtual RTS_RESULT CDECL ISysEthernetAdapterClose(RTS_HANDLE hAdapter) =0;
		virtual RTS_RESULT CDECL ISysEthernetEthFrameSend(RTS_HANDLE hAdapter, SysEthernetFrame* pFrame) =0;
		virtual SysEthernetFrame* CDECL ISysEthernetEthFrameReceive(RTS_HANDLE hAdapter, RTS_RESULT* pResult) =0;
		virtual RTS_RESULT CDECL ISysEthernetIpFrameSend(RTS_HANDLE hAdapter, SysEthernetFrame* pFrame) =0;
		virtual SysEthernetFrame* CDECL ISysEthernetIpFrameReceive(RTS_HANDLE hAdapter, RTS_RESULT* pResult) =0;
		virtual RTS_RESULT CDECL ISysEthernetFrameRelease(SysEthernetFrame* pFrame) =0;
		virtual RTS_RESULT CDECL ISysEthernetGetPortConfigAndStatus(RTS_UI8* pMacAddress, RTS_SIZE macSize, SysEthernetPortConfigAndStatus* pPortConfigAndStatus) =0;
		virtual RTS_RESULT CDECL ISysEthernetSetAutoNegAdvertisedCap(RTS_UI8* pMacAddress, RTS_SIZE macSize, RTS_UI64 ui64AutoNegAdvertisedCap) =0;
		virtual RTS_RESULT CDECL ISysEthernetSetAutoNegMode(RTS_UI8* pMacAddress, RTS_SIZE macSize, RTS_UI8 ui8AutoNegMode) =0;
		virtual RTS_RESULT CDECL ISysEthernetSetMauType(RTS_UI8* pMacAddress, RTS_SIZE macSize, RTS_UI32 ui32MauType) =0;
		virtual RTS_RESULT CDECL ISysEthernetGetInterfaceCounters(RTS_UI8* pMacAddress, RTS_SIZE macSize, SysEthernetInterfaceCounters* pSysEthernetInterfaceCounters, RTS_BOOL getAndClear) =0;
		virtual RTS_RESULT CDECL ISysEthernetGetMediaCounters(RTS_UI8* pMacAddress, RTS_SIZE macSize, SysEthernetMediaCounters* pSysEthernetMediaCounters, RTS_BOOL getAndClear) =0;
		virtual RTS_RESULT CDECL ISysEthernetGetCapabilities(RTS_UI8* pMacAddress, RTS_SIZE macSize, SysEthernetCapabilities* pSysEthernetCapabilities) =0;
};
	#ifndef ITF_SysEthernet
		#define ITF_SysEthernet static ISysEthernet *pISysEthernet = NULL;
	#endif
	#define EXTITF_SysEthernet
#else	/*CPLUSPLUS*/
	typedef ISysEthernet_C		ISysEthernet;
	#ifndef ITF_SysEthernet
		#define ITF_SysEthernet
	#endif
	#define EXTITF_SysEthernet
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_SYSETHERNETITF_H_*/
