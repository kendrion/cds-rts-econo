/**
 * <interfacename>IoDrvKNX</interfacename>
 * <description></description>
 *
 * <copyright></copyright>
 */

SET_INTERFACE_NAME(`IoDrvKNX')

/** EXTERN LIB SECTION BEGIN **/
/*  Comments are ignored for m4 compiler so restructured text can be used. changecom(`/*', `*/') */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description>Enum: EAccessType</description>
 */
#define EACCESSTYPE_AT_EREAD    RTS_IEC_INT_C(0x1)	
#define EACCESSTYPE_AT_EWRITE    RTS_IEC_INT_C(0x2)	
#define EACCESSTYPE_AT_EREADWRITE    RTS_IEC_INT_C(0x3)	
/* Typed enum definition */
#define EACCESSTYPE    RTS_IEC_INT

/**
 * <description>Enum: EKnxType</description>
 */
#define EKNXTYPE_KNX_ENOT_USED    RTS_IEC_INT_C(0x0)	
#define EKNXTYPE_KNX_EDPT1    RTS_IEC_INT_C(0x1)	/* 1 bit */
#define EKNXTYPE_KNX_EDPT2    RTS_IEC_INT_C(0x2)	/* 2 bit control */
#define EKNXTYPE_KNX_EDPT3    RTS_IEC_INT_C(0x3)	/* 4 bit dimming control */
#define EKNXTYPE_KNX_EDPT4    RTS_IEC_INT_C(0x4)	/* char */
#define EKNXTYPE_KNX_EDPT5_100    RTS_IEC_INT_C(0x105)	/* DPT5.001 - value (0..100) */
#define EKNXTYPE_KNX_EDPT5_360    RTS_IEC_INT_C(0x305)	/* DPT5.003 - angle 0..360° */
#define EKNXTYPE_KNX_EDPT5_255    RTS_IEC_INT_C(0x405)	/* DPT5.004 - relative Position (0..255) */
#define EKNXTYPE_KNX_EDPT6    RTS_IEC_INT_C(0x6)	/* Signed Relative Value (-128 ... +127) */
#define EKNXTYPE_KNX_EDPT7    RTS_IEC_INT_C(0x7)	/* 2-Octet Unsigned Value */
#define EKNXTYPE_KNX_EDPT8    RTS_IEC_INT_C(0x8)	/* 2-Octet signed Value */
#define EKNXTYPE_KNX_EDPT9    RTS_IEC_INT_C(0x9)	/* 2-Octet float Value */
#define EKNXTYPE_KNX_EDPT10    RTS_IEC_INT_C(0xA)	/* time */
#define EKNXTYPE_KNX_EDPT11    RTS_IEC_INT_C(0xB)	/* date */
#define EKNXTYPE_KNX_EDPT12    RTS_IEC_INT_C(0xC)	/* 4 octet unsigned value */
#define EKNXTYPE_KNX_EDPT13    RTS_IEC_INT_C(0xD)	/* 4 octet signed value */
#define EKNXTYPE_KNX_EDPT14    RTS_IEC_INT_C(0xE)	/* 4 octet float value */
#define EKNXTYPE_KNX_EDPT16    RTS_IEC_INT_C(0x10)	/* string */
#define EKNXTYPE_KNX_EDPT17    RTS_IEC_INT_C(0x11)	/* scene */
#define EKNXTYPE_KNX_EDPT18    RTS_IEC_INT_C(0x12)	/* sceneControl */
#define EKNXTYPE_KNX_EDPT19    RTS_IEC_INT_C(0x13)	/* date time */
#define EKNXTYPE_KNX_EDPT20    RTS_IEC_INT_C(0x14)	/* n8 */
#define EKNXTYPE_KNX_EDPT232    RTS_IEC_INT_C(0xE8)	/* RGB - color */
/* Typed enum definition */
#define EKNXTYPE    RTS_IEC_INT

/**
 * <description>Enum: ESendingFlag</description>
 */
#define ESENDINGFLAG_SF_NOAUTOMATICSEND    RTS_IEC_INT_C(0x0)	
#define ESENDINGFLAG_SF_SENDONCHANGE    RTS_IEC_INT_C(0x1)	
#define ESENDINGFLAG_SF_SENDONDIFFERENCE    RTS_IEC_INT_C(0x2)	
/* Typed enum definition */
#define ESENDINGFLAG    RTS_IEC_INT

/**
 * <description>KNXGlobalFlags</description>
 */
typedef struct tagKNXGlobalFlags
{
	RTS_IEC_BOOL xObjectUpdated;		
	RTS_IEC_BOOL xApplRestart;		
} KNXGlobalFlags;

/**
 * <description>KNXMetaData</description>
 */
typedef struct tagKNXMetaData
{
	RTS_IEC_STRING stIdentifier[10];		
	RTS_IEC_STRING stDateTime[10];		
	RTS_IEC_BYTE abyVersion[4];		
	RTS_IEC_BYTE byReleasedFlag;		
	RTS_IEC_BYTE byAlignment;		
	RTS_IEC_BYTE abyDummy[10];		
} KNXMetaData;

/**
 * <description>KNXObjectDescr</description>
 */
typedef struct tagKNXObjectDescr
{
	RTS_IEC_BOOL xObjectUpdated;		
	RTS_IEC_BOOL xObjectValueChanged;		
	RTS_IEC_USINT usiDataSize;		
	RTS_IEC_BYTE *pbyObjectValue;		
	RTS_IEC_INT knxType;		
	RTS_IEC_INT accessType;		
	RTS_IEC_INT sendingFlag;		
	RTS_IEC_UINT uiIntervalCyclicSend;		
	RTS_IEC_REAL rSendingDifference;		
} KNXObjectDescr;

/**
 * <description>KNXConfigObject</description>
 */
typedef struct tagKNXConfigObject
{
	RTS_IEC_WORD wObjectNumber;		
	RTS_IEC_BYTE byDataPointType;		
	RTS_IEC_BYTE byDataPointSubType;		
	RTS_IEC_BOOL xSendOnChange;		
	RTS_IEC_REAL rHysteresis;		
	RTS_IEC_BOOL xSendCyclically;		
	RTS_IEC_WORD wCycleTime;		
	RTS_IEC_BYTE *dataPointer;		
	RTS_IEC_BYTE *statusPointer;		
	RTS_IEC_BYTE byLastStatus;		
	RTS_IEC_UDINT udiLastTime;		
	RTS_IEC_BYTE abyLastData[14];		
	RTS_IEC_BOOL xFirstSent;		
} KNXConfigObject;

/**
 * <description>knx_cyclic</description>
 */
typedef struct tagknx_cyclic_struct
{
	RTS_IEC_BOOL KNX_Cyclic;			/* VAR_OUTPUT */	
} knx_cyclic_struct;

DEF_API(`void',`CDECL',`knx_cyclic',`(knx_cyclic_struct *p)',1,0x9746D49A,0x03050C00)

/**
 * <description>knx_exit</description>
 */
typedef struct tagknx_exit_struct
{
	RTS_IEC_BOOL KNX_Exit;				/* VAR_OUTPUT */	
} knx_exit_struct;

DEF_API(`void',`CDECL',`knx_exit',`(knx_exit_struct *p)',1,0xF5036289,0x03050C00)

/**
 * <description>knx_getdatapointer</description>
 */
typedef struct tagknx_getdatapointer_struct
{
	RTS_IEC_WORD wObjNbr;				/* VAR_INPUT */	
	RTS_IEC_BYTE *KNX_GetDataPointer;	/* VAR_OUTPUT */	
} knx_getdatapointer_struct;

DEF_API(`void',`CDECL',`knx_getdatapointer',`(knx_getdatapointer_struct *p)',1,0x717AC7D4,0x03050C00)

/**
 * <description>knx_getglobalflags</description>
 */
typedef struct tagknx_getglobalflags_struct
{
	KNXGlobalFlags KNX_GetGlobalFlags;	/* VAR_OUTPUT */	
} knx_getglobalflags_struct;

DEF_API(`void',`CDECL',`knx_getglobalflags',`(knx_getglobalflags_struct *p)',1,0x7F1B8997,0x03050C00)

/**
 * <description>knx_getledpointer</description>
 */
typedef struct tagknx_getledpointer_struct
{
	RTS_IEC_BYTE *KNX_GetLEDPointer;	/* VAR_OUTPUT */	
} knx_getledpointer_struct;

DEF_API(`void',`CDECL',`knx_getledpointer',`(knx_getledpointer_struct *p)',1,0xBB25E1AB,0x03050C00)

/**
 * <description>knx_getmetadata</description>
 */
typedef struct tagknx_getmetadata_struct
{
	KNXMetaData KNX_GetMetaData;		/* VAR_OUTPUT */	
} knx_getmetadata_struct;

DEF_API(`void',`CDECL',`knx_getmetadata',`(knx_getmetadata_struct *p)',1,0xB2A4EB2D,0x03050C00)

/**
 * <description>knx_getobjectinstance</description>
 */
typedef struct tagknx_getobjectinstance_struct
{
	RTS_IEC_WORD wObjNbr;				/* VAR_INPUT */	
	KNXObjectDescr KNX_GetObjectInstance;	/* VAR_OUTPUT */	
} knx_getobjectinstance_struct;

DEF_API(`void',`CDECL',`knx_getobjectinstance',`(knx_getobjectinstance_struct *p)',1,0x634B418F,0x03050C00)

/**
 * <description>knx_getprogrampointer</description>
 */
typedef struct tagknx_getprogrampointer_struct
{
	RTS_IEC_BYTE *KNX_GetProgramPointer;	/* VAR_OUTPUT */	
} knx_getprogrampointer_struct;

DEF_API(`void',`CDECL',`knx_getprogrampointer',`(knx_getprogrampointer_struct *p)',1,0x03D99FA6,0x03050C00)

/**
 * <description>knx_getstatuspointer</description>
 */
typedef struct tagknx_getstatuspointer_struct
{
	RTS_IEC_WORD wObjNbr;				/* VAR_INPUT */	
	RTS_IEC_BYTE *KNX_GetStatusPointer;	/* VAR_OUTPUT */	
} knx_getstatuspointer_struct;

DEF_API(`void',`CDECL',`knx_getstatuspointer',`(knx_getstatuspointer_struct *p)',1,0x16D1AF17,0x03050C00)

/**
 * <description>knx_init</description>
 */
typedef struct tagknx_init_struct
{
	RTS_IEC_BOOL KNX_Init;				/* VAR_OUTPUT */	
} knx_init_struct;

DEF_API(`void',`CDECL',`knx_init',`(knx_init_struct *p)',1,0x976AB6A9,0x03050C00)

/**
 * <description>knx_setgateway</description>
 */
typedef struct tagknx_setgateway_struct
{
	RTS_IEC_BYTE arGateway[4];			/* VAR_INPUT */	
	RTS_IEC_BOOL KNX_SetGateway;		/* VAR_OUTPUT */	
} knx_setgateway_struct;

DEF_API(`void',`CDECL',`knx_setgateway',`(knx_setgateway_struct *p)',1,0x8C4401C4,0x03050C00)

/**
 * <description>knx_setipaddress</description>
 */
typedef struct tagknx_setipaddress_struct
{
	RTS_IEC_BYTE arIPAddress[4];		/* VAR_INPUT */	
	RTS_IEC_BOOL KNX_SetIPAddress;		/* VAR_OUTPUT */	
} knx_setipaddress_struct;

DEF_API(`void',`CDECL',`knx_setipaddress',`(knx_setipaddress_struct *p)',1,0xA01A2C2C,0x03050C00)

/**
 * <description>knx_setmacaddress</description>
 */
typedef struct tagknx_setmacaddress_struct
{
	RTS_IEC_BYTE arMacAddress[6];		/* VAR_INPUT */	
	RTS_IEC_BOOL KNX_SetMacAddress;		/* VAR_OUTPUT */	
} knx_setmacaddress_struct;

DEF_API(`void',`CDECL',`knx_setmacaddress',`(knx_setmacaddress_struct *p)',1,0x5DCC2EEF,0x03050C00)

/**
 * <description>knx_setmulticastaddress</description>
 */
typedef struct tagknx_setmulticastaddress_struct
{
	RTS_IEC_BYTE arIPAddress[4];		/* VAR_INPUT */	
	RTS_IEC_BOOL KNX_SetMultiCastAddress;	/* VAR_OUTPUT */	
} knx_setmulticastaddress_struct;

DEF_API(`void',`CDECL',`knx_setmulticastaddress',`(knx_setmulticastaddress_struct *p)',1,0x9DC6E1C0,0x03050C00)

/**
 * <description>knx_setobjecttype</description>
 */
typedef struct tagknx_setobjecttype_struct
{
	RTS_IEC_WORD wObjNbr;				/* VAR_INPUT */	
	RTS_IEC_BYTE byDPTType;				/* VAR_INPUT */	
	RTS_IEC_BOOL KNX_SetObjectType;		/* VAR_OUTPUT */	
} knx_setobjecttype_struct;

DEF_API(`void',`CDECL',`knx_setobjecttype',`(knx_setobjecttype_struct *p)',1,0x62B4F903,0x03050C00)

/**
 * <description>knx_setserialnumber</description>
 */
typedef struct tagknx_setserialnumber_struct
{
	RTS_IEC_BYTE arSerialnumber[6];		/* VAR_INPUT */	
	RTS_IEC_BOOL KNX_SetSerialNumber;	/* VAR_OUTPUT */	
} knx_setserialnumber_struct;

DEF_API(`void',`CDECL',`knx_setserialnumber',`(knx_setserialnumber_struct *p)',1,0x9473EF6E,0x03050C00)

/**
 * <description>knx_setsubnetmask</description>
 */
typedef struct tagknx_setsubnetmask_struct
{
	RTS_IEC_BYTE arSubnetMask[4];		/* VAR_INPUT */	
	RTS_IEC_BOOL KNX_SetSubnetMask;		/* VAR_OUTPUT */	
} knx_setsubnetmask_struct;

DEF_API(`void',`CDECL',`knx_setsubnetmask',`(knx_setsubnetmask_struct *p)',1,0xC659BE8F,0x03050C00)

/**
 * <description>knx_transmitobject</description>
 */
typedef struct tagknx_transmitobject_struct
{
	RTS_IEC_WORD wObjNbr;				/* VAR_INPUT */	
	RTS_IEC_BOOL xRead;					/* VAR_INPUT */	
	RTS_IEC_BOOL xForced;				/* VAR_INPUT */	
	RTS_IEC_BOOL KNX_TransmitObject;	/* VAR_OUTPUT */	
} knx_transmitobject_struct;

DEF_API(`void',`CDECL',`knx_transmitobject',`(knx_transmitobject_struct *p)',1,0x1438CF1F,0x03050C00)

#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/

