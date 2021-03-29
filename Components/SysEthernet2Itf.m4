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

SET_INTERFACE_NAME(`SysEthernet2')

/* Possible values for the flags in the EthernetframeAddInfo structure are: */
#define EAI_FLG_QUALITY_GOOD	0x00000001
#define EAI_FLG_CRC_ERROR		0x00000002
#define EAI_FLG_ALIGNMENT_ERROR	0x00000004
#define EAI_FLG_OTHER_ERROR		0x00000008

typedef struct
{
	unsigned long ulFlags;
	unsigned long ulDummy;
	unsigned __int64 liTimestamp;
	unsigned __int64 liTimestampHR;
	void* pHWInfo; /*Used to pass information about the adapter that received the frame, for now the MAC. */ 
}EthernetframeAddInfo;


typedef struct
{
	long iMasterNum;
	unsigned char **ppFrame;
	long* pnSize;
	EthernetframeAddInfo** ppAddInfo;  
	long nReturnVal;
}GetEthernetInterfaceEx;

typedef struct
{
	long iMasterNum;
	long nReturnVal;
}ResetAdapter;

typedef struct
{
	long iMasterNum;
	short PciVendorID;
	short PciDeviceID;
	void* pHWRegs;
}EthernetAdapterDesc;

typedef struct
{
	long iMasterNum;
	EthernetAdapterDesc** ppAdapterDesc;
	long nReturnVal;
}GetAdapterDescription;

typedef struct
{
	long iMasterNum;
	unsigned char **ppFrame;
	RTS_I32* pnSize;
	RTS_I32 nReturnVal;
}GetIPEthernetInterface2;

typedef struct
{
	long iMasterNum;
	Ethernetframe *pFrame;
	RTS_I32 nSize;
	RTS_I32 nReturnVal;
}SendIPEthernetInterface2;

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  <description>Get info about specified network adapters</description>
 * <param name="paiei" type="IN">Pointer to parameters</param>
 * <result>error code</result>
 */
DEF_API(`void',`CDECL',`resetadapter',`(ResetAdapter* pra)',1)

/**
 *  <description>same as getethernet, but with additional info.</description>
 * <param name="pgeiex" type="IN">Pointer to parameters</param>
 * <result>error code</result>
 */
DEF_API(`void',`CDECL',`getethframeex',`(GetEthernetInterfaceEx* pgeiex)',1)

/**
 *  <description>An interface function to get some information about the NIC's hardware.</description>
 * <param name="pgad" type="IN">Pointer to a GetAdapterDescription structure.</param>
 * <result>error code</result>
 */
DEF_API(`void',`CDECL',`getadapterdescription',`(GetAdapterDescription* pgad)',1)


/**
 * <description>Send IP etherpacket (EoE)</description>
 * <param name="psfi" type="IN">Pointer to parameters</param>
 * <result>error code</result>
 */
DEF_ITF_API(`void',`CDECL',`sendIPethframe2',`(SendIPEthernetInterface2* psfi)',1)

/**
 * <description>Get IP ethernet packet</description>
 * <param name="pgei" type="IN">Pointer to parameters</param>
 * <result>error code</result>
 */
DEF_ITF_API(`void',`CDECL',`getIPethframe2',`(GetIPEthernetInterface2* pgei)',1)

typedef void (CDECL * PFETHFRAMERECEIVED)(unsigned char* pFrameData, unsigned long ulSize, RTS_UINTPTR pAddInfo);

#define PURPOSE_IS_GETMEDIACOUNTERS 1
#define PURPOSE_IS_GETINTERFACECOUNTERS 2
#define PURPOSE_IS_CLEARMEDIACOUNTERS 3
#define PURPOSE_IS_CLEARINTERFACECOUNTERS 4
typedef RTS_RESULT (CDECL * PFMULTIPURPOSEFUNKTION)(int iPurpose, unsigned char* pMacAddr, size_t sMacAddr, void* pParam, size_t sParam);

typedef struct _EthernetAdapterDescription
{
	unsigned char aucMacAddress[6];
	int iAdapterNum;
	int iMasterNum;
	int bAdapterOpen; /*bit 0: opened by AdapterOpen, bit 1: opened by AdapterOpenComm.*/
	PFGETIPETHFRAME pfgetIPethframe;
	PFSENDIPETHFRAME pfsendIPethframe;
	PFGETADAPTERINFO pfgetadapterinfo;
	PFGETNUMBEROFADAPTERS pfgetnumberofadapters;
	PFCLOSEETHERNET pfcloseethernet;
	PFGETETHFRAME pfgetethframe;
	PFSENDETHFRAME pfsendethframe;
	PFOPENETHERNET pfopenethernet;
	PFGETADAPTERDESCRIPTION pfgetadapterdescription;
	PFGETETHFRAMEEX pfgetethframeex;
	PFRESETADAPTER pfresetadapter;
	PFETHFRAMERECEIVED pfEthFrameReceived;
	char szDriverName[32];
	PFGETIPETHFRAME2 pfgetIPethframe2;
	PFSENDIPETHFRAME2 pfsendIPethframe2;
	PFOPENETHERNET pfopenethernetcomm;
	PFMULTIPURPOSEFUNKTION pfMultiPurposeFunktion;
}EthernetAdapterDescription;

DEF_API(`RTS_RESULT',`CDECL',`SysEthernetRegisterEthernetAdapter',`(EthernetAdapterDescription* pAdapterDesc, int bUnregister)',1)


#ifdef __cplusplus
}
#endif
