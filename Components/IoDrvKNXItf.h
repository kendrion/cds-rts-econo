 /**
 * <interfacename>IoDrvKNX</interfacename>
 * <description></description>
 *
 * <copyright></copyright>
 */


	
	
#ifndef _IODRVKNXITF_H_
#define _IODRVKNXITF_H_

#include "CmpStd.h"

 

 




/** EXTERN LIB SECTION BEGIN **/
/*  Comments are ignored for m4 compiler so restructured text can be used.  */

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

void CDECL CDECL_EXT knx_cyclic(knx_cyclic_struct *p);
typedef void (CDECL CDECL_EXT* PFKNX_CYCLIC_IEC) (knx_cyclic_struct *p);
#if defined(IODRVKNX_NOTIMPLEMENTED) || defined(KNX_CYCLIC_NOTIMPLEMENTED)
	#define USE_knx_cyclic
	#define EXT_knx_cyclic
	#define GET_knx_cyclic(fl)  ERR_NOTIMPLEMENTED
	#define CAL_knx_cyclic(p0) 
	#define CHK_knx_cyclic  FALSE
	#define EXP_knx_cyclic  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_knx_cyclic
	#define EXT_knx_cyclic
	#define GET_knx_cyclic(fl)  CAL_CMGETAPI( "knx_cyclic" ) 
	#define CAL_knx_cyclic  knx_cyclic
	#define CHK_knx_cyclic  TRUE
	#define EXP_knx_cyclic  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_cyclic", (RTS_UINTPTR)knx_cyclic, 1, 0x9746D49A, 0x03050C00) 
#elif defined(MIXED_LINK) && !defined(IODRVKNX_EXTERNAL)
	#define USE_knx_cyclic
	#define EXT_knx_cyclic
	#define GET_knx_cyclic(fl)  CAL_CMGETAPI( "knx_cyclic" ) 
	#define CAL_knx_cyclic  knx_cyclic
	#define CHK_knx_cyclic  TRUE
	#define EXP_knx_cyclic  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_cyclic", (RTS_UINTPTR)knx_cyclic, 1, 0x9746D49A, 0x03050C00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_IoDrvKNXknx_cyclic
	#define EXT_IoDrvKNXknx_cyclic
	#define GET_IoDrvKNXknx_cyclic  ERR_OK
	#define CAL_IoDrvKNXknx_cyclic  knx_cyclic
	#define CHK_IoDrvKNXknx_cyclic  TRUE
	#define EXP_IoDrvKNXknx_cyclic  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_cyclic", (RTS_UINTPTR)knx_cyclic, 1, 0x9746D49A, 0x03050C00) 
#elif defined(CPLUSPLUS)
	#define USE_knx_cyclic
	#define EXT_knx_cyclic
	#define GET_knx_cyclic(fl)  CAL_CMGETAPI( "knx_cyclic" ) 
	#define CAL_knx_cyclic  knx_cyclic
	#define CHK_knx_cyclic  TRUE
	#define EXP_knx_cyclic  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_cyclic", (RTS_UINTPTR)knx_cyclic, 1, 0x9746D49A, 0x03050C00) 
#else /* DYNAMIC_LINK */
	#define USE_knx_cyclic  PFKNX_CYCLIC_IEC pfknx_cyclic;
	#define EXT_knx_cyclic  extern PFKNX_CYCLIC_IEC pfknx_cyclic;
	#define GET_knx_cyclic(fl)  s_pfCMGetAPI2( "knx_cyclic", (RTS_VOID_FCTPTR *)&pfknx_cyclic, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x9746D49A, 0x03050C00)
	#define CAL_knx_cyclic  pfknx_cyclic
	#define CHK_knx_cyclic  (pfknx_cyclic != NULL)
	#define EXP_knx_cyclic   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_cyclic", (RTS_UINTPTR)knx_cyclic, 1, 0x9746D49A, 0x03050C00) 
#endif


/**
 * <description>knx_exit</description>
 */
typedef struct tagknx_exit_struct
{
	RTS_IEC_BOOL KNX_Exit;				/* VAR_OUTPUT */	
} knx_exit_struct;

void CDECL CDECL_EXT knx_exit(knx_exit_struct *p);
typedef void (CDECL CDECL_EXT* PFKNX_EXIT_IEC) (knx_exit_struct *p);
#if defined(IODRVKNX_NOTIMPLEMENTED) || defined(KNX_EXIT_NOTIMPLEMENTED)
	#define USE_knx_exit
	#define EXT_knx_exit
	#define GET_knx_exit(fl)  ERR_NOTIMPLEMENTED
	#define CAL_knx_exit(p0) 
	#define CHK_knx_exit  FALSE
	#define EXP_knx_exit  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_knx_exit
	#define EXT_knx_exit
	#define GET_knx_exit(fl)  CAL_CMGETAPI( "knx_exit" ) 
	#define CAL_knx_exit  knx_exit
	#define CHK_knx_exit  TRUE
	#define EXP_knx_exit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_exit", (RTS_UINTPTR)knx_exit, 1, 0xF5036289, 0x03050C00) 
#elif defined(MIXED_LINK) && !defined(IODRVKNX_EXTERNAL)
	#define USE_knx_exit
	#define EXT_knx_exit
	#define GET_knx_exit(fl)  CAL_CMGETAPI( "knx_exit" ) 
	#define CAL_knx_exit  knx_exit
	#define CHK_knx_exit  TRUE
	#define EXP_knx_exit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_exit", (RTS_UINTPTR)knx_exit, 1, 0xF5036289, 0x03050C00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_IoDrvKNXknx_exit
	#define EXT_IoDrvKNXknx_exit
	#define GET_IoDrvKNXknx_exit  ERR_OK
	#define CAL_IoDrvKNXknx_exit  knx_exit
	#define CHK_IoDrvKNXknx_exit  TRUE
	#define EXP_IoDrvKNXknx_exit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_exit", (RTS_UINTPTR)knx_exit, 1, 0xF5036289, 0x03050C00) 
#elif defined(CPLUSPLUS)
	#define USE_knx_exit
	#define EXT_knx_exit
	#define GET_knx_exit(fl)  CAL_CMGETAPI( "knx_exit" ) 
	#define CAL_knx_exit  knx_exit
	#define CHK_knx_exit  TRUE
	#define EXP_knx_exit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_exit", (RTS_UINTPTR)knx_exit, 1, 0xF5036289, 0x03050C00) 
#else /* DYNAMIC_LINK */
	#define USE_knx_exit  PFKNX_EXIT_IEC pfknx_exit;
	#define EXT_knx_exit  extern PFKNX_EXIT_IEC pfknx_exit;
	#define GET_knx_exit(fl)  s_pfCMGetAPI2( "knx_exit", (RTS_VOID_FCTPTR *)&pfknx_exit, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xF5036289, 0x03050C00)
	#define CAL_knx_exit  pfknx_exit
	#define CHK_knx_exit  (pfknx_exit != NULL)
	#define EXP_knx_exit   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_exit", (RTS_UINTPTR)knx_exit, 1, 0xF5036289, 0x03050C00) 
#endif


/**
 * <description>knx_getdatapointer</description>
 */
typedef struct tagknx_getdatapointer_struct
{
	RTS_IEC_WORD wObjNbr;				/* VAR_INPUT */	
	RTS_IEC_BYTE *KNX_GetDataPointer;	/* VAR_OUTPUT */	
} knx_getdatapointer_struct;

void CDECL CDECL_EXT knx_getdatapointer(knx_getdatapointer_struct *p);
typedef void (CDECL CDECL_EXT* PFKNX_GETDATAPOINTER_IEC) (knx_getdatapointer_struct *p);
#if defined(IODRVKNX_NOTIMPLEMENTED) || defined(KNX_GETDATAPOINTER_NOTIMPLEMENTED)
	#define USE_knx_getdatapointer
	#define EXT_knx_getdatapointer
	#define GET_knx_getdatapointer(fl)  ERR_NOTIMPLEMENTED
	#define CAL_knx_getdatapointer(p0) 
	#define CHK_knx_getdatapointer  FALSE
	#define EXP_knx_getdatapointer  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_knx_getdatapointer
	#define EXT_knx_getdatapointer
	#define GET_knx_getdatapointer(fl)  CAL_CMGETAPI( "knx_getdatapointer" ) 
	#define CAL_knx_getdatapointer  knx_getdatapointer
	#define CHK_knx_getdatapointer  TRUE
	#define EXP_knx_getdatapointer  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getdatapointer", (RTS_UINTPTR)knx_getdatapointer, 1, 0x717AC7D4, 0x03050C00) 
#elif defined(MIXED_LINK) && !defined(IODRVKNX_EXTERNAL)
	#define USE_knx_getdatapointer
	#define EXT_knx_getdatapointer
	#define GET_knx_getdatapointer(fl)  CAL_CMGETAPI( "knx_getdatapointer" ) 
	#define CAL_knx_getdatapointer  knx_getdatapointer
	#define CHK_knx_getdatapointer  TRUE
	#define EXP_knx_getdatapointer  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getdatapointer", (RTS_UINTPTR)knx_getdatapointer, 1, 0x717AC7D4, 0x03050C00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_IoDrvKNXknx_getdatapointer
	#define EXT_IoDrvKNXknx_getdatapointer
	#define GET_IoDrvKNXknx_getdatapointer  ERR_OK
	#define CAL_IoDrvKNXknx_getdatapointer  knx_getdatapointer
	#define CHK_IoDrvKNXknx_getdatapointer  TRUE
	#define EXP_IoDrvKNXknx_getdatapointer  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getdatapointer", (RTS_UINTPTR)knx_getdatapointer, 1, 0x717AC7D4, 0x03050C00) 
#elif defined(CPLUSPLUS)
	#define USE_knx_getdatapointer
	#define EXT_knx_getdatapointer
	#define GET_knx_getdatapointer(fl)  CAL_CMGETAPI( "knx_getdatapointer" ) 
	#define CAL_knx_getdatapointer  knx_getdatapointer
	#define CHK_knx_getdatapointer  TRUE
	#define EXP_knx_getdatapointer  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getdatapointer", (RTS_UINTPTR)knx_getdatapointer, 1, 0x717AC7D4, 0x03050C00) 
#else /* DYNAMIC_LINK */
	#define USE_knx_getdatapointer  PFKNX_GETDATAPOINTER_IEC pfknx_getdatapointer;
	#define EXT_knx_getdatapointer  extern PFKNX_GETDATAPOINTER_IEC pfknx_getdatapointer;
	#define GET_knx_getdatapointer(fl)  s_pfCMGetAPI2( "knx_getdatapointer", (RTS_VOID_FCTPTR *)&pfknx_getdatapointer, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x717AC7D4, 0x03050C00)
	#define CAL_knx_getdatapointer  pfknx_getdatapointer
	#define CHK_knx_getdatapointer  (pfknx_getdatapointer != NULL)
	#define EXP_knx_getdatapointer   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getdatapointer", (RTS_UINTPTR)knx_getdatapointer, 1, 0x717AC7D4, 0x03050C00) 
#endif


/**
 * <description>knx_getglobalflags</description>
 */
typedef struct tagknx_getglobalflags_struct
{
	KNXGlobalFlags KNX_GetGlobalFlags;	/* VAR_OUTPUT */	
} knx_getglobalflags_struct;

void CDECL CDECL_EXT knx_getglobalflags(knx_getglobalflags_struct *p);
typedef void (CDECL CDECL_EXT* PFKNX_GETGLOBALFLAGS_IEC) (knx_getglobalflags_struct *p);
#if defined(IODRVKNX_NOTIMPLEMENTED) || defined(KNX_GETGLOBALFLAGS_NOTIMPLEMENTED)
	#define USE_knx_getglobalflags
	#define EXT_knx_getglobalflags
	#define GET_knx_getglobalflags(fl)  ERR_NOTIMPLEMENTED
	#define CAL_knx_getglobalflags(p0) 
	#define CHK_knx_getglobalflags  FALSE
	#define EXP_knx_getglobalflags  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_knx_getglobalflags
	#define EXT_knx_getglobalflags
	#define GET_knx_getglobalflags(fl)  CAL_CMGETAPI( "knx_getglobalflags" ) 
	#define CAL_knx_getglobalflags  knx_getglobalflags
	#define CHK_knx_getglobalflags  TRUE
	#define EXP_knx_getglobalflags  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getglobalflags", (RTS_UINTPTR)knx_getglobalflags, 1, 0x7F1B8997, 0x03050C00) 
#elif defined(MIXED_LINK) && !defined(IODRVKNX_EXTERNAL)
	#define USE_knx_getglobalflags
	#define EXT_knx_getglobalflags
	#define GET_knx_getglobalflags(fl)  CAL_CMGETAPI( "knx_getglobalflags" ) 
	#define CAL_knx_getglobalflags  knx_getglobalflags
	#define CHK_knx_getglobalflags  TRUE
	#define EXP_knx_getglobalflags  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getglobalflags", (RTS_UINTPTR)knx_getglobalflags, 1, 0x7F1B8997, 0x03050C00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_IoDrvKNXknx_getglobalflags
	#define EXT_IoDrvKNXknx_getglobalflags
	#define GET_IoDrvKNXknx_getglobalflags  ERR_OK
	#define CAL_IoDrvKNXknx_getglobalflags  knx_getglobalflags
	#define CHK_IoDrvKNXknx_getglobalflags  TRUE
	#define EXP_IoDrvKNXknx_getglobalflags  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getglobalflags", (RTS_UINTPTR)knx_getglobalflags, 1, 0x7F1B8997, 0x03050C00) 
#elif defined(CPLUSPLUS)
	#define USE_knx_getglobalflags
	#define EXT_knx_getglobalflags
	#define GET_knx_getglobalflags(fl)  CAL_CMGETAPI( "knx_getglobalflags" ) 
	#define CAL_knx_getglobalflags  knx_getglobalflags
	#define CHK_knx_getglobalflags  TRUE
	#define EXP_knx_getglobalflags  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getglobalflags", (RTS_UINTPTR)knx_getglobalflags, 1, 0x7F1B8997, 0x03050C00) 
#else /* DYNAMIC_LINK */
	#define USE_knx_getglobalflags  PFKNX_GETGLOBALFLAGS_IEC pfknx_getglobalflags;
	#define EXT_knx_getglobalflags  extern PFKNX_GETGLOBALFLAGS_IEC pfknx_getglobalflags;
	#define GET_knx_getglobalflags(fl)  s_pfCMGetAPI2( "knx_getglobalflags", (RTS_VOID_FCTPTR *)&pfknx_getglobalflags, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x7F1B8997, 0x03050C00)
	#define CAL_knx_getglobalflags  pfknx_getglobalflags
	#define CHK_knx_getglobalflags  (pfknx_getglobalflags != NULL)
	#define EXP_knx_getglobalflags   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getglobalflags", (RTS_UINTPTR)knx_getglobalflags, 1, 0x7F1B8997, 0x03050C00) 
#endif


/**
 * <description>knx_getledpointer</description>
 */
typedef struct tagknx_getledpointer_struct
{
	RTS_IEC_BYTE *KNX_GetLEDPointer;	/* VAR_OUTPUT */	
} knx_getledpointer_struct;

void CDECL CDECL_EXT knx_getledpointer(knx_getledpointer_struct *p);
typedef void (CDECL CDECL_EXT* PFKNX_GETLEDPOINTER_IEC) (knx_getledpointer_struct *p);
#if defined(IODRVKNX_NOTIMPLEMENTED) || defined(KNX_GETLEDPOINTER_NOTIMPLEMENTED)
	#define USE_knx_getledpointer
	#define EXT_knx_getledpointer
	#define GET_knx_getledpointer(fl)  ERR_NOTIMPLEMENTED
	#define CAL_knx_getledpointer(p0) 
	#define CHK_knx_getledpointer  FALSE
	#define EXP_knx_getledpointer  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_knx_getledpointer
	#define EXT_knx_getledpointer
	#define GET_knx_getledpointer(fl)  CAL_CMGETAPI( "knx_getledpointer" ) 
	#define CAL_knx_getledpointer  knx_getledpointer
	#define CHK_knx_getledpointer  TRUE
	#define EXP_knx_getledpointer  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getledpointer", (RTS_UINTPTR)knx_getledpointer, 1, 0xBB25E1AB, 0x03050C00) 
#elif defined(MIXED_LINK) && !defined(IODRVKNX_EXTERNAL)
	#define USE_knx_getledpointer
	#define EXT_knx_getledpointer
	#define GET_knx_getledpointer(fl)  CAL_CMGETAPI( "knx_getledpointer" ) 
	#define CAL_knx_getledpointer  knx_getledpointer
	#define CHK_knx_getledpointer  TRUE
	#define EXP_knx_getledpointer  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getledpointer", (RTS_UINTPTR)knx_getledpointer, 1, 0xBB25E1AB, 0x03050C00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_IoDrvKNXknx_getledpointer
	#define EXT_IoDrvKNXknx_getledpointer
	#define GET_IoDrvKNXknx_getledpointer  ERR_OK
	#define CAL_IoDrvKNXknx_getledpointer  knx_getledpointer
	#define CHK_IoDrvKNXknx_getledpointer  TRUE
	#define EXP_IoDrvKNXknx_getledpointer  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getledpointer", (RTS_UINTPTR)knx_getledpointer, 1, 0xBB25E1AB, 0x03050C00) 
#elif defined(CPLUSPLUS)
	#define USE_knx_getledpointer
	#define EXT_knx_getledpointer
	#define GET_knx_getledpointer(fl)  CAL_CMGETAPI( "knx_getledpointer" ) 
	#define CAL_knx_getledpointer  knx_getledpointer
	#define CHK_knx_getledpointer  TRUE
	#define EXP_knx_getledpointer  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getledpointer", (RTS_UINTPTR)knx_getledpointer, 1, 0xBB25E1AB, 0x03050C00) 
#else /* DYNAMIC_LINK */
	#define USE_knx_getledpointer  PFKNX_GETLEDPOINTER_IEC pfknx_getledpointer;
	#define EXT_knx_getledpointer  extern PFKNX_GETLEDPOINTER_IEC pfknx_getledpointer;
	#define GET_knx_getledpointer(fl)  s_pfCMGetAPI2( "knx_getledpointer", (RTS_VOID_FCTPTR *)&pfknx_getledpointer, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xBB25E1AB, 0x03050C00)
	#define CAL_knx_getledpointer  pfknx_getledpointer
	#define CHK_knx_getledpointer  (pfknx_getledpointer != NULL)
	#define EXP_knx_getledpointer   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getledpointer", (RTS_UINTPTR)knx_getledpointer, 1, 0xBB25E1AB, 0x03050C00) 
#endif


/**
 * <description>knx_getmetadata</description>
 */
typedef struct tagknx_getmetadata_struct
{
	KNXMetaData KNX_GetMetaData;		/* VAR_OUTPUT */	
} knx_getmetadata_struct;

void CDECL CDECL_EXT knx_getmetadata(knx_getmetadata_struct *p);
typedef void (CDECL CDECL_EXT* PFKNX_GETMETADATA_IEC) (knx_getmetadata_struct *p);
#if defined(IODRVKNX_NOTIMPLEMENTED) || defined(KNX_GETMETADATA_NOTIMPLEMENTED)
	#define USE_knx_getmetadata
	#define EXT_knx_getmetadata
	#define GET_knx_getmetadata(fl)  ERR_NOTIMPLEMENTED
	#define CAL_knx_getmetadata(p0) 
	#define CHK_knx_getmetadata  FALSE
	#define EXP_knx_getmetadata  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_knx_getmetadata
	#define EXT_knx_getmetadata
	#define GET_knx_getmetadata(fl)  CAL_CMGETAPI( "knx_getmetadata" ) 
	#define CAL_knx_getmetadata  knx_getmetadata
	#define CHK_knx_getmetadata  TRUE
	#define EXP_knx_getmetadata  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getmetadata", (RTS_UINTPTR)knx_getmetadata, 1, 0xB2A4EB2D, 0x03050C00) 
#elif defined(MIXED_LINK) && !defined(IODRVKNX_EXTERNAL)
	#define USE_knx_getmetadata
	#define EXT_knx_getmetadata
	#define GET_knx_getmetadata(fl)  CAL_CMGETAPI( "knx_getmetadata" ) 
	#define CAL_knx_getmetadata  knx_getmetadata
	#define CHK_knx_getmetadata  TRUE
	#define EXP_knx_getmetadata  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getmetadata", (RTS_UINTPTR)knx_getmetadata, 1, 0xB2A4EB2D, 0x03050C00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_IoDrvKNXknx_getmetadata
	#define EXT_IoDrvKNXknx_getmetadata
	#define GET_IoDrvKNXknx_getmetadata  ERR_OK
	#define CAL_IoDrvKNXknx_getmetadata  knx_getmetadata
	#define CHK_IoDrvKNXknx_getmetadata  TRUE
	#define EXP_IoDrvKNXknx_getmetadata  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getmetadata", (RTS_UINTPTR)knx_getmetadata, 1, 0xB2A4EB2D, 0x03050C00) 
#elif defined(CPLUSPLUS)
	#define USE_knx_getmetadata
	#define EXT_knx_getmetadata
	#define GET_knx_getmetadata(fl)  CAL_CMGETAPI( "knx_getmetadata" ) 
	#define CAL_knx_getmetadata  knx_getmetadata
	#define CHK_knx_getmetadata  TRUE
	#define EXP_knx_getmetadata  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getmetadata", (RTS_UINTPTR)knx_getmetadata, 1, 0xB2A4EB2D, 0x03050C00) 
#else /* DYNAMIC_LINK */
	#define USE_knx_getmetadata  PFKNX_GETMETADATA_IEC pfknx_getmetadata;
	#define EXT_knx_getmetadata  extern PFKNX_GETMETADATA_IEC pfknx_getmetadata;
	#define GET_knx_getmetadata(fl)  s_pfCMGetAPI2( "knx_getmetadata", (RTS_VOID_FCTPTR *)&pfknx_getmetadata, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xB2A4EB2D, 0x03050C00)
	#define CAL_knx_getmetadata  pfknx_getmetadata
	#define CHK_knx_getmetadata  (pfknx_getmetadata != NULL)
	#define EXP_knx_getmetadata   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getmetadata", (RTS_UINTPTR)knx_getmetadata, 1, 0xB2A4EB2D, 0x03050C00) 
#endif


/**
 * <description>knx_getobjectinstance</description>
 */
typedef struct tagknx_getobjectinstance_struct
{
	RTS_IEC_WORD wObjNbr;				/* VAR_INPUT */	
	KNXObjectDescr KNX_GetObjectInstance;	/* VAR_OUTPUT */	
} knx_getobjectinstance_struct;

void CDECL CDECL_EXT knx_getobjectinstance(knx_getobjectinstance_struct *p);
typedef void (CDECL CDECL_EXT* PFKNX_GETOBJECTINSTANCE_IEC) (knx_getobjectinstance_struct *p);
#if defined(IODRVKNX_NOTIMPLEMENTED) || defined(KNX_GETOBJECTINSTANCE_NOTIMPLEMENTED)
	#define USE_knx_getobjectinstance
	#define EXT_knx_getobjectinstance
	#define GET_knx_getobjectinstance(fl)  ERR_NOTIMPLEMENTED
	#define CAL_knx_getobjectinstance(p0) 
	#define CHK_knx_getobjectinstance  FALSE
	#define EXP_knx_getobjectinstance  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_knx_getobjectinstance
	#define EXT_knx_getobjectinstance
	#define GET_knx_getobjectinstance(fl)  CAL_CMGETAPI( "knx_getobjectinstance" ) 
	#define CAL_knx_getobjectinstance  knx_getobjectinstance
	#define CHK_knx_getobjectinstance  TRUE
	#define EXP_knx_getobjectinstance  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getobjectinstance", (RTS_UINTPTR)knx_getobjectinstance, 1, 0x634B418F, 0x03050C00) 
#elif defined(MIXED_LINK) && !defined(IODRVKNX_EXTERNAL)
	#define USE_knx_getobjectinstance
	#define EXT_knx_getobjectinstance
	#define GET_knx_getobjectinstance(fl)  CAL_CMGETAPI( "knx_getobjectinstance" ) 
	#define CAL_knx_getobjectinstance  knx_getobjectinstance
	#define CHK_knx_getobjectinstance  TRUE
	#define EXP_knx_getobjectinstance  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getobjectinstance", (RTS_UINTPTR)knx_getobjectinstance, 1, 0x634B418F, 0x03050C00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_IoDrvKNXknx_getobjectinstance
	#define EXT_IoDrvKNXknx_getobjectinstance
	#define GET_IoDrvKNXknx_getobjectinstance  ERR_OK
	#define CAL_IoDrvKNXknx_getobjectinstance  knx_getobjectinstance
	#define CHK_IoDrvKNXknx_getobjectinstance  TRUE
	#define EXP_IoDrvKNXknx_getobjectinstance  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getobjectinstance", (RTS_UINTPTR)knx_getobjectinstance, 1, 0x634B418F, 0x03050C00) 
#elif defined(CPLUSPLUS)
	#define USE_knx_getobjectinstance
	#define EXT_knx_getobjectinstance
	#define GET_knx_getobjectinstance(fl)  CAL_CMGETAPI( "knx_getobjectinstance" ) 
	#define CAL_knx_getobjectinstance  knx_getobjectinstance
	#define CHK_knx_getobjectinstance  TRUE
	#define EXP_knx_getobjectinstance  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getobjectinstance", (RTS_UINTPTR)knx_getobjectinstance, 1, 0x634B418F, 0x03050C00) 
#else /* DYNAMIC_LINK */
	#define USE_knx_getobjectinstance  PFKNX_GETOBJECTINSTANCE_IEC pfknx_getobjectinstance;
	#define EXT_knx_getobjectinstance  extern PFKNX_GETOBJECTINSTANCE_IEC pfknx_getobjectinstance;
	#define GET_knx_getobjectinstance(fl)  s_pfCMGetAPI2( "knx_getobjectinstance", (RTS_VOID_FCTPTR *)&pfknx_getobjectinstance, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x634B418F, 0x03050C00)
	#define CAL_knx_getobjectinstance  pfknx_getobjectinstance
	#define CHK_knx_getobjectinstance  (pfknx_getobjectinstance != NULL)
	#define EXP_knx_getobjectinstance   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getobjectinstance", (RTS_UINTPTR)knx_getobjectinstance, 1, 0x634B418F, 0x03050C00) 
#endif


/**
 * <description>knx_getprogrampointer</description>
 */
typedef struct tagknx_getprogrampointer_struct
{
	RTS_IEC_BYTE *KNX_GetProgramPointer;	/* VAR_OUTPUT */	
} knx_getprogrampointer_struct;

void CDECL CDECL_EXT knx_getprogrampointer(knx_getprogrampointer_struct *p);
typedef void (CDECL CDECL_EXT* PFKNX_GETPROGRAMPOINTER_IEC) (knx_getprogrampointer_struct *p);
#if defined(IODRVKNX_NOTIMPLEMENTED) || defined(KNX_GETPROGRAMPOINTER_NOTIMPLEMENTED)
	#define USE_knx_getprogrampointer
	#define EXT_knx_getprogrampointer
	#define GET_knx_getprogrampointer(fl)  ERR_NOTIMPLEMENTED
	#define CAL_knx_getprogrampointer(p0) 
	#define CHK_knx_getprogrampointer  FALSE
	#define EXP_knx_getprogrampointer  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_knx_getprogrampointer
	#define EXT_knx_getprogrampointer
	#define GET_knx_getprogrampointer(fl)  CAL_CMGETAPI( "knx_getprogrampointer" ) 
	#define CAL_knx_getprogrampointer  knx_getprogrampointer
	#define CHK_knx_getprogrampointer  TRUE
	#define EXP_knx_getprogrampointer  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getprogrampointer", (RTS_UINTPTR)knx_getprogrampointer, 1, 0x03D99FA6, 0x03050C00) 
#elif defined(MIXED_LINK) && !defined(IODRVKNX_EXTERNAL)
	#define USE_knx_getprogrampointer
	#define EXT_knx_getprogrampointer
	#define GET_knx_getprogrampointer(fl)  CAL_CMGETAPI( "knx_getprogrampointer" ) 
	#define CAL_knx_getprogrampointer  knx_getprogrampointer
	#define CHK_knx_getprogrampointer  TRUE
	#define EXP_knx_getprogrampointer  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getprogrampointer", (RTS_UINTPTR)knx_getprogrampointer, 1, 0x03D99FA6, 0x03050C00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_IoDrvKNXknx_getprogrampointer
	#define EXT_IoDrvKNXknx_getprogrampointer
	#define GET_IoDrvKNXknx_getprogrampointer  ERR_OK
	#define CAL_IoDrvKNXknx_getprogrampointer  knx_getprogrampointer
	#define CHK_IoDrvKNXknx_getprogrampointer  TRUE
	#define EXP_IoDrvKNXknx_getprogrampointer  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getprogrampointer", (RTS_UINTPTR)knx_getprogrampointer, 1, 0x03D99FA6, 0x03050C00) 
#elif defined(CPLUSPLUS)
	#define USE_knx_getprogrampointer
	#define EXT_knx_getprogrampointer
	#define GET_knx_getprogrampointer(fl)  CAL_CMGETAPI( "knx_getprogrampointer" ) 
	#define CAL_knx_getprogrampointer  knx_getprogrampointer
	#define CHK_knx_getprogrampointer  TRUE
	#define EXP_knx_getprogrampointer  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getprogrampointer", (RTS_UINTPTR)knx_getprogrampointer, 1, 0x03D99FA6, 0x03050C00) 
#else /* DYNAMIC_LINK */
	#define USE_knx_getprogrampointer  PFKNX_GETPROGRAMPOINTER_IEC pfknx_getprogrampointer;
	#define EXT_knx_getprogrampointer  extern PFKNX_GETPROGRAMPOINTER_IEC pfknx_getprogrampointer;
	#define GET_knx_getprogrampointer(fl)  s_pfCMGetAPI2( "knx_getprogrampointer", (RTS_VOID_FCTPTR *)&pfknx_getprogrampointer, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x03D99FA6, 0x03050C00)
	#define CAL_knx_getprogrampointer  pfknx_getprogrampointer
	#define CHK_knx_getprogrampointer  (pfknx_getprogrampointer != NULL)
	#define EXP_knx_getprogrampointer   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getprogrampointer", (RTS_UINTPTR)knx_getprogrampointer, 1, 0x03D99FA6, 0x03050C00) 
#endif


/**
 * <description>knx_getstatuspointer</description>
 */
typedef struct tagknx_getstatuspointer_struct
{
	RTS_IEC_WORD wObjNbr;				/* VAR_INPUT */	
	RTS_IEC_BYTE *KNX_GetStatusPointer;	/* VAR_OUTPUT */	
} knx_getstatuspointer_struct;

void CDECL CDECL_EXT knx_getstatuspointer(knx_getstatuspointer_struct *p);
typedef void (CDECL CDECL_EXT* PFKNX_GETSTATUSPOINTER_IEC) (knx_getstatuspointer_struct *p);
#if defined(IODRVKNX_NOTIMPLEMENTED) || defined(KNX_GETSTATUSPOINTER_NOTIMPLEMENTED)
	#define USE_knx_getstatuspointer
	#define EXT_knx_getstatuspointer
	#define GET_knx_getstatuspointer(fl)  ERR_NOTIMPLEMENTED
	#define CAL_knx_getstatuspointer(p0) 
	#define CHK_knx_getstatuspointer  FALSE
	#define EXP_knx_getstatuspointer  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_knx_getstatuspointer
	#define EXT_knx_getstatuspointer
	#define GET_knx_getstatuspointer(fl)  CAL_CMGETAPI( "knx_getstatuspointer" ) 
	#define CAL_knx_getstatuspointer  knx_getstatuspointer
	#define CHK_knx_getstatuspointer  TRUE
	#define EXP_knx_getstatuspointer  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getstatuspointer", (RTS_UINTPTR)knx_getstatuspointer, 1, 0x16D1AF17, 0x03050C00) 
#elif defined(MIXED_LINK) && !defined(IODRVKNX_EXTERNAL)
	#define USE_knx_getstatuspointer
	#define EXT_knx_getstatuspointer
	#define GET_knx_getstatuspointer(fl)  CAL_CMGETAPI( "knx_getstatuspointer" ) 
	#define CAL_knx_getstatuspointer  knx_getstatuspointer
	#define CHK_knx_getstatuspointer  TRUE
	#define EXP_knx_getstatuspointer  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getstatuspointer", (RTS_UINTPTR)knx_getstatuspointer, 1, 0x16D1AF17, 0x03050C00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_IoDrvKNXknx_getstatuspointer
	#define EXT_IoDrvKNXknx_getstatuspointer
	#define GET_IoDrvKNXknx_getstatuspointer  ERR_OK
	#define CAL_IoDrvKNXknx_getstatuspointer  knx_getstatuspointer
	#define CHK_IoDrvKNXknx_getstatuspointer  TRUE
	#define EXP_IoDrvKNXknx_getstatuspointer  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getstatuspointer", (RTS_UINTPTR)knx_getstatuspointer, 1, 0x16D1AF17, 0x03050C00) 
#elif defined(CPLUSPLUS)
	#define USE_knx_getstatuspointer
	#define EXT_knx_getstatuspointer
	#define GET_knx_getstatuspointer(fl)  CAL_CMGETAPI( "knx_getstatuspointer" ) 
	#define CAL_knx_getstatuspointer  knx_getstatuspointer
	#define CHK_knx_getstatuspointer  TRUE
	#define EXP_knx_getstatuspointer  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getstatuspointer", (RTS_UINTPTR)knx_getstatuspointer, 1, 0x16D1AF17, 0x03050C00) 
#else /* DYNAMIC_LINK */
	#define USE_knx_getstatuspointer  PFKNX_GETSTATUSPOINTER_IEC pfknx_getstatuspointer;
	#define EXT_knx_getstatuspointer  extern PFKNX_GETSTATUSPOINTER_IEC pfknx_getstatuspointer;
	#define GET_knx_getstatuspointer(fl)  s_pfCMGetAPI2( "knx_getstatuspointer", (RTS_VOID_FCTPTR *)&pfknx_getstatuspointer, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x16D1AF17, 0x03050C00)
	#define CAL_knx_getstatuspointer  pfknx_getstatuspointer
	#define CHK_knx_getstatuspointer  (pfknx_getstatuspointer != NULL)
	#define EXP_knx_getstatuspointer   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_getstatuspointer", (RTS_UINTPTR)knx_getstatuspointer, 1, 0x16D1AF17, 0x03050C00) 
#endif


/**
 * <description>knx_init</description>
 */
typedef struct tagknx_init_struct
{
	RTS_IEC_BOOL KNX_Init;				/* VAR_OUTPUT */	
} knx_init_struct;

void CDECL CDECL_EXT knx_init(knx_init_struct *p);
typedef void (CDECL CDECL_EXT* PFKNX_INIT_IEC) (knx_init_struct *p);
#if defined(IODRVKNX_NOTIMPLEMENTED) || defined(KNX_INIT_NOTIMPLEMENTED)
	#define USE_knx_init
	#define EXT_knx_init
	#define GET_knx_init(fl)  ERR_NOTIMPLEMENTED
	#define CAL_knx_init(p0) 
	#define CHK_knx_init  FALSE
	#define EXP_knx_init  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_knx_init
	#define EXT_knx_init
	#define GET_knx_init(fl)  CAL_CMGETAPI( "knx_init" ) 
	#define CAL_knx_init  knx_init
	#define CHK_knx_init  TRUE
	#define EXP_knx_init  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_init", (RTS_UINTPTR)knx_init, 1, 0x976AB6A9, 0x03050C00) 
#elif defined(MIXED_LINK) && !defined(IODRVKNX_EXTERNAL)
	#define USE_knx_init
	#define EXT_knx_init
	#define GET_knx_init(fl)  CAL_CMGETAPI( "knx_init" ) 
	#define CAL_knx_init  knx_init
	#define CHK_knx_init  TRUE
	#define EXP_knx_init  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_init", (RTS_UINTPTR)knx_init, 1, 0x976AB6A9, 0x03050C00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_IoDrvKNXknx_init
	#define EXT_IoDrvKNXknx_init
	#define GET_IoDrvKNXknx_init  ERR_OK
	#define CAL_IoDrvKNXknx_init  knx_init
	#define CHK_IoDrvKNXknx_init  TRUE
	#define EXP_IoDrvKNXknx_init  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_init", (RTS_UINTPTR)knx_init, 1, 0x976AB6A9, 0x03050C00) 
#elif defined(CPLUSPLUS)
	#define USE_knx_init
	#define EXT_knx_init
	#define GET_knx_init(fl)  CAL_CMGETAPI( "knx_init" ) 
	#define CAL_knx_init  knx_init
	#define CHK_knx_init  TRUE
	#define EXP_knx_init  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_init", (RTS_UINTPTR)knx_init, 1, 0x976AB6A9, 0x03050C00) 
#else /* DYNAMIC_LINK */
	#define USE_knx_init  PFKNX_INIT_IEC pfknx_init;
	#define EXT_knx_init  extern PFKNX_INIT_IEC pfknx_init;
	#define GET_knx_init(fl)  s_pfCMGetAPI2( "knx_init", (RTS_VOID_FCTPTR *)&pfknx_init, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x976AB6A9, 0x03050C00)
	#define CAL_knx_init  pfknx_init
	#define CHK_knx_init  (pfknx_init != NULL)
	#define EXP_knx_init   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_init", (RTS_UINTPTR)knx_init, 1, 0x976AB6A9, 0x03050C00) 
#endif


/**
 * <description>knx_setgateway</description>
 */
typedef struct tagknx_setgateway_struct
{
	RTS_IEC_BYTE arGateway[4];			/* VAR_INPUT */	
	RTS_IEC_BOOL KNX_SetGateway;		/* VAR_OUTPUT */	
} knx_setgateway_struct;

void CDECL CDECL_EXT knx_setgateway(knx_setgateway_struct *p);
typedef void (CDECL CDECL_EXT* PFKNX_SETGATEWAY_IEC) (knx_setgateway_struct *p);
#if defined(IODRVKNX_NOTIMPLEMENTED) || defined(KNX_SETGATEWAY_NOTIMPLEMENTED)
	#define USE_knx_setgateway
	#define EXT_knx_setgateway
	#define GET_knx_setgateway(fl)  ERR_NOTIMPLEMENTED
	#define CAL_knx_setgateway(p0) 
	#define CHK_knx_setgateway  FALSE
	#define EXP_knx_setgateway  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_knx_setgateway
	#define EXT_knx_setgateway
	#define GET_knx_setgateway(fl)  CAL_CMGETAPI( "knx_setgateway" ) 
	#define CAL_knx_setgateway  knx_setgateway
	#define CHK_knx_setgateway  TRUE
	#define EXP_knx_setgateway  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setgateway", (RTS_UINTPTR)knx_setgateway, 1, 0x8C4401C4, 0x03050C00) 
#elif defined(MIXED_LINK) && !defined(IODRVKNX_EXTERNAL)
	#define USE_knx_setgateway
	#define EXT_knx_setgateway
	#define GET_knx_setgateway(fl)  CAL_CMGETAPI( "knx_setgateway" ) 
	#define CAL_knx_setgateway  knx_setgateway
	#define CHK_knx_setgateway  TRUE
	#define EXP_knx_setgateway  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setgateway", (RTS_UINTPTR)knx_setgateway, 1, 0x8C4401C4, 0x03050C00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_IoDrvKNXknx_setgateway
	#define EXT_IoDrvKNXknx_setgateway
	#define GET_IoDrvKNXknx_setgateway  ERR_OK
	#define CAL_IoDrvKNXknx_setgateway  knx_setgateway
	#define CHK_IoDrvKNXknx_setgateway  TRUE
	#define EXP_IoDrvKNXknx_setgateway  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setgateway", (RTS_UINTPTR)knx_setgateway, 1, 0x8C4401C4, 0x03050C00) 
#elif defined(CPLUSPLUS)
	#define USE_knx_setgateway
	#define EXT_knx_setgateway
	#define GET_knx_setgateway(fl)  CAL_CMGETAPI( "knx_setgateway" ) 
	#define CAL_knx_setgateway  knx_setgateway
	#define CHK_knx_setgateway  TRUE
	#define EXP_knx_setgateway  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setgateway", (RTS_UINTPTR)knx_setgateway, 1, 0x8C4401C4, 0x03050C00) 
#else /* DYNAMIC_LINK */
	#define USE_knx_setgateway  PFKNX_SETGATEWAY_IEC pfknx_setgateway;
	#define EXT_knx_setgateway  extern PFKNX_SETGATEWAY_IEC pfknx_setgateway;
	#define GET_knx_setgateway(fl)  s_pfCMGetAPI2( "knx_setgateway", (RTS_VOID_FCTPTR *)&pfknx_setgateway, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x8C4401C4, 0x03050C00)
	#define CAL_knx_setgateway  pfknx_setgateway
	#define CHK_knx_setgateway  (pfknx_setgateway != NULL)
	#define EXP_knx_setgateway   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setgateway", (RTS_UINTPTR)knx_setgateway, 1, 0x8C4401C4, 0x03050C00) 
#endif


/**
 * <description>knx_setipaddress</description>
 */
typedef struct tagknx_setipaddress_struct
{
	RTS_IEC_BYTE arIPAddress[4];		/* VAR_INPUT */	
	RTS_IEC_BOOL KNX_SetIPAddress;		/* VAR_OUTPUT */	
} knx_setipaddress_struct;

void CDECL CDECL_EXT knx_setipaddress(knx_setipaddress_struct *p);
typedef void (CDECL CDECL_EXT* PFKNX_SETIPADDRESS_IEC) (knx_setipaddress_struct *p);
#if defined(IODRVKNX_NOTIMPLEMENTED) || defined(KNX_SETIPADDRESS_NOTIMPLEMENTED)
	#define USE_knx_setipaddress
	#define EXT_knx_setipaddress
	#define GET_knx_setipaddress(fl)  ERR_NOTIMPLEMENTED
	#define CAL_knx_setipaddress(p0) 
	#define CHK_knx_setipaddress  FALSE
	#define EXP_knx_setipaddress  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_knx_setipaddress
	#define EXT_knx_setipaddress
	#define GET_knx_setipaddress(fl)  CAL_CMGETAPI( "knx_setipaddress" ) 
	#define CAL_knx_setipaddress  knx_setipaddress
	#define CHK_knx_setipaddress  TRUE
	#define EXP_knx_setipaddress  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setipaddress", (RTS_UINTPTR)knx_setipaddress, 1, 0xA01A2C2C, 0x03050C00) 
#elif defined(MIXED_LINK) && !defined(IODRVKNX_EXTERNAL)
	#define USE_knx_setipaddress
	#define EXT_knx_setipaddress
	#define GET_knx_setipaddress(fl)  CAL_CMGETAPI( "knx_setipaddress" ) 
	#define CAL_knx_setipaddress  knx_setipaddress
	#define CHK_knx_setipaddress  TRUE
	#define EXP_knx_setipaddress  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setipaddress", (RTS_UINTPTR)knx_setipaddress, 1, 0xA01A2C2C, 0x03050C00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_IoDrvKNXknx_setipaddress
	#define EXT_IoDrvKNXknx_setipaddress
	#define GET_IoDrvKNXknx_setipaddress  ERR_OK
	#define CAL_IoDrvKNXknx_setipaddress  knx_setipaddress
	#define CHK_IoDrvKNXknx_setipaddress  TRUE
	#define EXP_IoDrvKNXknx_setipaddress  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setipaddress", (RTS_UINTPTR)knx_setipaddress, 1, 0xA01A2C2C, 0x03050C00) 
#elif defined(CPLUSPLUS)
	#define USE_knx_setipaddress
	#define EXT_knx_setipaddress
	#define GET_knx_setipaddress(fl)  CAL_CMGETAPI( "knx_setipaddress" ) 
	#define CAL_knx_setipaddress  knx_setipaddress
	#define CHK_knx_setipaddress  TRUE
	#define EXP_knx_setipaddress  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setipaddress", (RTS_UINTPTR)knx_setipaddress, 1, 0xA01A2C2C, 0x03050C00) 
#else /* DYNAMIC_LINK */
	#define USE_knx_setipaddress  PFKNX_SETIPADDRESS_IEC pfknx_setipaddress;
	#define EXT_knx_setipaddress  extern PFKNX_SETIPADDRESS_IEC pfknx_setipaddress;
	#define GET_knx_setipaddress(fl)  s_pfCMGetAPI2( "knx_setipaddress", (RTS_VOID_FCTPTR *)&pfknx_setipaddress, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xA01A2C2C, 0x03050C00)
	#define CAL_knx_setipaddress  pfknx_setipaddress
	#define CHK_knx_setipaddress  (pfknx_setipaddress != NULL)
	#define EXP_knx_setipaddress   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setipaddress", (RTS_UINTPTR)knx_setipaddress, 1, 0xA01A2C2C, 0x03050C00) 
#endif


/**
 * <description>knx_setmacaddress</description>
 */
typedef struct tagknx_setmacaddress_struct
{
	RTS_IEC_BYTE arMacAddress[6];		/* VAR_INPUT */	
	RTS_IEC_BOOL KNX_SetMacAddress;		/* VAR_OUTPUT */	
} knx_setmacaddress_struct;

void CDECL CDECL_EXT knx_setmacaddress(knx_setmacaddress_struct *p);
typedef void (CDECL CDECL_EXT* PFKNX_SETMACADDRESS_IEC) (knx_setmacaddress_struct *p);
#if defined(IODRVKNX_NOTIMPLEMENTED) || defined(KNX_SETMACADDRESS_NOTIMPLEMENTED)
	#define USE_knx_setmacaddress
	#define EXT_knx_setmacaddress
	#define GET_knx_setmacaddress(fl)  ERR_NOTIMPLEMENTED
	#define CAL_knx_setmacaddress(p0) 
	#define CHK_knx_setmacaddress  FALSE
	#define EXP_knx_setmacaddress  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_knx_setmacaddress
	#define EXT_knx_setmacaddress
	#define GET_knx_setmacaddress(fl)  CAL_CMGETAPI( "knx_setmacaddress" ) 
	#define CAL_knx_setmacaddress  knx_setmacaddress
	#define CHK_knx_setmacaddress  TRUE
	#define EXP_knx_setmacaddress  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setmacaddress", (RTS_UINTPTR)knx_setmacaddress, 1, 0x5DCC2EEF, 0x03050C00) 
#elif defined(MIXED_LINK) && !defined(IODRVKNX_EXTERNAL)
	#define USE_knx_setmacaddress
	#define EXT_knx_setmacaddress
	#define GET_knx_setmacaddress(fl)  CAL_CMGETAPI( "knx_setmacaddress" ) 
	#define CAL_knx_setmacaddress  knx_setmacaddress
	#define CHK_knx_setmacaddress  TRUE
	#define EXP_knx_setmacaddress  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setmacaddress", (RTS_UINTPTR)knx_setmacaddress, 1, 0x5DCC2EEF, 0x03050C00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_IoDrvKNXknx_setmacaddress
	#define EXT_IoDrvKNXknx_setmacaddress
	#define GET_IoDrvKNXknx_setmacaddress  ERR_OK
	#define CAL_IoDrvKNXknx_setmacaddress  knx_setmacaddress
	#define CHK_IoDrvKNXknx_setmacaddress  TRUE
	#define EXP_IoDrvKNXknx_setmacaddress  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setmacaddress", (RTS_UINTPTR)knx_setmacaddress, 1, 0x5DCC2EEF, 0x03050C00) 
#elif defined(CPLUSPLUS)
	#define USE_knx_setmacaddress
	#define EXT_knx_setmacaddress
	#define GET_knx_setmacaddress(fl)  CAL_CMGETAPI( "knx_setmacaddress" ) 
	#define CAL_knx_setmacaddress  knx_setmacaddress
	#define CHK_knx_setmacaddress  TRUE
	#define EXP_knx_setmacaddress  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setmacaddress", (RTS_UINTPTR)knx_setmacaddress, 1, 0x5DCC2EEF, 0x03050C00) 
#else /* DYNAMIC_LINK */
	#define USE_knx_setmacaddress  PFKNX_SETMACADDRESS_IEC pfknx_setmacaddress;
	#define EXT_knx_setmacaddress  extern PFKNX_SETMACADDRESS_IEC pfknx_setmacaddress;
	#define GET_knx_setmacaddress(fl)  s_pfCMGetAPI2( "knx_setmacaddress", (RTS_VOID_FCTPTR *)&pfknx_setmacaddress, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x5DCC2EEF, 0x03050C00)
	#define CAL_knx_setmacaddress  pfknx_setmacaddress
	#define CHK_knx_setmacaddress  (pfknx_setmacaddress != NULL)
	#define EXP_knx_setmacaddress   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setmacaddress", (RTS_UINTPTR)knx_setmacaddress, 1, 0x5DCC2EEF, 0x03050C00) 
#endif


/**
 * <description>knx_setmulticastaddress</description>
 */
typedef struct tagknx_setmulticastaddress_struct
{
	RTS_IEC_BYTE arIPAddress[4];		/* VAR_INPUT */	
	RTS_IEC_BOOL KNX_SetMultiCastAddress;	/* VAR_OUTPUT */	
} knx_setmulticastaddress_struct;

void CDECL CDECL_EXT knx_setmulticastaddress(knx_setmulticastaddress_struct *p);
typedef void (CDECL CDECL_EXT* PFKNX_SETMULTICASTADDRESS_IEC) (knx_setmulticastaddress_struct *p);
#if defined(IODRVKNX_NOTIMPLEMENTED) || defined(KNX_SETMULTICASTADDRESS_NOTIMPLEMENTED)
	#define USE_knx_setmulticastaddress
	#define EXT_knx_setmulticastaddress
	#define GET_knx_setmulticastaddress(fl)  ERR_NOTIMPLEMENTED
	#define CAL_knx_setmulticastaddress(p0) 
	#define CHK_knx_setmulticastaddress  FALSE
	#define EXP_knx_setmulticastaddress  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_knx_setmulticastaddress
	#define EXT_knx_setmulticastaddress
	#define GET_knx_setmulticastaddress(fl)  CAL_CMGETAPI( "knx_setmulticastaddress" ) 
	#define CAL_knx_setmulticastaddress  knx_setmulticastaddress
	#define CHK_knx_setmulticastaddress  TRUE
	#define EXP_knx_setmulticastaddress  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setmulticastaddress", (RTS_UINTPTR)knx_setmulticastaddress, 1, 0x9DC6E1C0, 0x03050C00) 
#elif defined(MIXED_LINK) && !defined(IODRVKNX_EXTERNAL)
	#define USE_knx_setmulticastaddress
	#define EXT_knx_setmulticastaddress
	#define GET_knx_setmulticastaddress(fl)  CAL_CMGETAPI( "knx_setmulticastaddress" ) 
	#define CAL_knx_setmulticastaddress  knx_setmulticastaddress
	#define CHK_knx_setmulticastaddress  TRUE
	#define EXP_knx_setmulticastaddress  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setmulticastaddress", (RTS_UINTPTR)knx_setmulticastaddress, 1, 0x9DC6E1C0, 0x03050C00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_IoDrvKNXknx_setmulticastaddress
	#define EXT_IoDrvKNXknx_setmulticastaddress
	#define GET_IoDrvKNXknx_setmulticastaddress  ERR_OK
	#define CAL_IoDrvKNXknx_setmulticastaddress  knx_setmulticastaddress
	#define CHK_IoDrvKNXknx_setmulticastaddress  TRUE
	#define EXP_IoDrvKNXknx_setmulticastaddress  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setmulticastaddress", (RTS_UINTPTR)knx_setmulticastaddress, 1, 0x9DC6E1C0, 0x03050C00) 
#elif defined(CPLUSPLUS)
	#define USE_knx_setmulticastaddress
	#define EXT_knx_setmulticastaddress
	#define GET_knx_setmulticastaddress(fl)  CAL_CMGETAPI( "knx_setmulticastaddress" ) 
	#define CAL_knx_setmulticastaddress  knx_setmulticastaddress
	#define CHK_knx_setmulticastaddress  TRUE
	#define EXP_knx_setmulticastaddress  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setmulticastaddress", (RTS_UINTPTR)knx_setmulticastaddress, 1, 0x9DC6E1C0, 0x03050C00) 
#else /* DYNAMIC_LINK */
	#define USE_knx_setmulticastaddress  PFKNX_SETMULTICASTADDRESS_IEC pfknx_setmulticastaddress;
	#define EXT_knx_setmulticastaddress  extern PFKNX_SETMULTICASTADDRESS_IEC pfknx_setmulticastaddress;
	#define GET_knx_setmulticastaddress(fl)  s_pfCMGetAPI2( "knx_setmulticastaddress", (RTS_VOID_FCTPTR *)&pfknx_setmulticastaddress, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x9DC6E1C0, 0x03050C00)
	#define CAL_knx_setmulticastaddress  pfknx_setmulticastaddress
	#define CHK_knx_setmulticastaddress  (pfknx_setmulticastaddress != NULL)
	#define EXP_knx_setmulticastaddress   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setmulticastaddress", (RTS_UINTPTR)knx_setmulticastaddress, 1, 0x9DC6E1C0, 0x03050C00) 
#endif


/**
 * <description>knx_setobjecttype</description>
 */
typedef struct tagknx_setobjecttype_struct
{
	RTS_IEC_WORD wObjNbr;				/* VAR_INPUT */	
	RTS_IEC_BYTE byDPTType;				/* VAR_INPUT */	
	RTS_IEC_BOOL KNX_SetObjectType;		/* VAR_OUTPUT */	
} knx_setobjecttype_struct;

void CDECL CDECL_EXT knx_setobjecttype(knx_setobjecttype_struct *p);
typedef void (CDECL CDECL_EXT* PFKNX_SETOBJECTTYPE_IEC) (knx_setobjecttype_struct *p);
#if defined(IODRVKNX_NOTIMPLEMENTED) || defined(KNX_SETOBJECTTYPE_NOTIMPLEMENTED)
	#define USE_knx_setobjecttype
	#define EXT_knx_setobjecttype
	#define GET_knx_setobjecttype(fl)  ERR_NOTIMPLEMENTED
	#define CAL_knx_setobjecttype(p0) 
	#define CHK_knx_setobjecttype  FALSE
	#define EXP_knx_setobjecttype  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_knx_setobjecttype
	#define EXT_knx_setobjecttype
	#define GET_knx_setobjecttype(fl)  CAL_CMGETAPI( "knx_setobjecttype" ) 
	#define CAL_knx_setobjecttype  knx_setobjecttype
	#define CHK_knx_setobjecttype  TRUE
	#define EXP_knx_setobjecttype  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setobjecttype", (RTS_UINTPTR)knx_setobjecttype, 1, 0x62B4F903, 0x03050C00) 
#elif defined(MIXED_LINK) && !defined(IODRVKNX_EXTERNAL)
	#define USE_knx_setobjecttype
	#define EXT_knx_setobjecttype
	#define GET_knx_setobjecttype(fl)  CAL_CMGETAPI( "knx_setobjecttype" ) 
	#define CAL_knx_setobjecttype  knx_setobjecttype
	#define CHK_knx_setobjecttype  TRUE
	#define EXP_knx_setobjecttype  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setobjecttype", (RTS_UINTPTR)knx_setobjecttype, 1, 0x62B4F903, 0x03050C00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_IoDrvKNXknx_setobjecttype
	#define EXT_IoDrvKNXknx_setobjecttype
	#define GET_IoDrvKNXknx_setobjecttype  ERR_OK
	#define CAL_IoDrvKNXknx_setobjecttype  knx_setobjecttype
	#define CHK_IoDrvKNXknx_setobjecttype  TRUE
	#define EXP_IoDrvKNXknx_setobjecttype  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setobjecttype", (RTS_UINTPTR)knx_setobjecttype, 1, 0x62B4F903, 0x03050C00) 
#elif defined(CPLUSPLUS)
	#define USE_knx_setobjecttype
	#define EXT_knx_setobjecttype
	#define GET_knx_setobjecttype(fl)  CAL_CMGETAPI( "knx_setobjecttype" ) 
	#define CAL_knx_setobjecttype  knx_setobjecttype
	#define CHK_knx_setobjecttype  TRUE
	#define EXP_knx_setobjecttype  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setobjecttype", (RTS_UINTPTR)knx_setobjecttype, 1, 0x62B4F903, 0x03050C00) 
#else /* DYNAMIC_LINK */
	#define USE_knx_setobjecttype  PFKNX_SETOBJECTTYPE_IEC pfknx_setobjecttype;
	#define EXT_knx_setobjecttype  extern PFKNX_SETOBJECTTYPE_IEC pfknx_setobjecttype;
	#define GET_knx_setobjecttype(fl)  s_pfCMGetAPI2( "knx_setobjecttype", (RTS_VOID_FCTPTR *)&pfknx_setobjecttype, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x62B4F903, 0x03050C00)
	#define CAL_knx_setobjecttype  pfknx_setobjecttype
	#define CHK_knx_setobjecttype  (pfknx_setobjecttype != NULL)
	#define EXP_knx_setobjecttype   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setobjecttype", (RTS_UINTPTR)knx_setobjecttype, 1, 0x62B4F903, 0x03050C00) 
#endif


/**
 * <description>knx_setserialnumber</description>
 */
typedef struct tagknx_setserialnumber_struct
{
	RTS_IEC_BYTE arSerialnumber[6];		/* VAR_INPUT */	
	RTS_IEC_BOOL KNX_SetSerialNumber;	/* VAR_OUTPUT */	
} knx_setserialnumber_struct;

void CDECL CDECL_EXT knx_setserialnumber(knx_setserialnumber_struct *p);
typedef void (CDECL CDECL_EXT* PFKNX_SETSERIALNUMBER_IEC) (knx_setserialnumber_struct *p);
#if defined(IODRVKNX_NOTIMPLEMENTED) || defined(KNX_SETSERIALNUMBER_NOTIMPLEMENTED)
	#define USE_knx_setserialnumber
	#define EXT_knx_setserialnumber
	#define GET_knx_setserialnumber(fl)  ERR_NOTIMPLEMENTED
	#define CAL_knx_setserialnumber(p0) 
	#define CHK_knx_setserialnumber  FALSE
	#define EXP_knx_setserialnumber  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_knx_setserialnumber
	#define EXT_knx_setserialnumber
	#define GET_knx_setserialnumber(fl)  CAL_CMGETAPI( "knx_setserialnumber" ) 
	#define CAL_knx_setserialnumber  knx_setserialnumber
	#define CHK_knx_setserialnumber  TRUE
	#define EXP_knx_setserialnumber  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setserialnumber", (RTS_UINTPTR)knx_setserialnumber, 1, 0x9473EF6E, 0x03050C00) 
#elif defined(MIXED_LINK) && !defined(IODRVKNX_EXTERNAL)
	#define USE_knx_setserialnumber
	#define EXT_knx_setserialnumber
	#define GET_knx_setserialnumber(fl)  CAL_CMGETAPI( "knx_setserialnumber" ) 
	#define CAL_knx_setserialnumber  knx_setserialnumber
	#define CHK_knx_setserialnumber  TRUE
	#define EXP_knx_setserialnumber  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setserialnumber", (RTS_UINTPTR)knx_setserialnumber, 1, 0x9473EF6E, 0x03050C00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_IoDrvKNXknx_setserialnumber
	#define EXT_IoDrvKNXknx_setserialnumber
	#define GET_IoDrvKNXknx_setserialnumber  ERR_OK
	#define CAL_IoDrvKNXknx_setserialnumber  knx_setserialnumber
	#define CHK_IoDrvKNXknx_setserialnumber  TRUE
	#define EXP_IoDrvKNXknx_setserialnumber  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setserialnumber", (RTS_UINTPTR)knx_setserialnumber, 1, 0x9473EF6E, 0x03050C00) 
#elif defined(CPLUSPLUS)
	#define USE_knx_setserialnumber
	#define EXT_knx_setserialnumber
	#define GET_knx_setserialnumber(fl)  CAL_CMGETAPI( "knx_setserialnumber" ) 
	#define CAL_knx_setserialnumber  knx_setserialnumber
	#define CHK_knx_setserialnumber  TRUE
	#define EXP_knx_setserialnumber  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setserialnumber", (RTS_UINTPTR)knx_setserialnumber, 1, 0x9473EF6E, 0x03050C00) 
#else /* DYNAMIC_LINK */
	#define USE_knx_setserialnumber  PFKNX_SETSERIALNUMBER_IEC pfknx_setserialnumber;
	#define EXT_knx_setserialnumber  extern PFKNX_SETSERIALNUMBER_IEC pfknx_setserialnumber;
	#define GET_knx_setserialnumber(fl)  s_pfCMGetAPI2( "knx_setserialnumber", (RTS_VOID_FCTPTR *)&pfknx_setserialnumber, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x9473EF6E, 0x03050C00)
	#define CAL_knx_setserialnumber  pfknx_setserialnumber
	#define CHK_knx_setserialnumber  (pfknx_setserialnumber != NULL)
	#define EXP_knx_setserialnumber   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setserialnumber", (RTS_UINTPTR)knx_setserialnumber, 1, 0x9473EF6E, 0x03050C00) 
#endif


/**
 * <description>knx_setsubnetmask</description>
 */
typedef struct tagknx_setsubnetmask_struct
{
	RTS_IEC_BYTE arSubnetMask[4];		/* VAR_INPUT */	
	RTS_IEC_BOOL KNX_SetSubnetMask;		/* VAR_OUTPUT */	
} knx_setsubnetmask_struct;

void CDECL CDECL_EXT knx_setsubnetmask(knx_setsubnetmask_struct *p);
typedef void (CDECL CDECL_EXT* PFKNX_SETSUBNETMASK_IEC) (knx_setsubnetmask_struct *p);
#if defined(IODRVKNX_NOTIMPLEMENTED) || defined(KNX_SETSUBNETMASK_NOTIMPLEMENTED)
	#define USE_knx_setsubnetmask
	#define EXT_knx_setsubnetmask
	#define GET_knx_setsubnetmask(fl)  ERR_NOTIMPLEMENTED
	#define CAL_knx_setsubnetmask(p0) 
	#define CHK_knx_setsubnetmask  FALSE
	#define EXP_knx_setsubnetmask  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_knx_setsubnetmask
	#define EXT_knx_setsubnetmask
	#define GET_knx_setsubnetmask(fl)  CAL_CMGETAPI( "knx_setsubnetmask" ) 
	#define CAL_knx_setsubnetmask  knx_setsubnetmask
	#define CHK_knx_setsubnetmask  TRUE
	#define EXP_knx_setsubnetmask  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setsubnetmask", (RTS_UINTPTR)knx_setsubnetmask, 1, 0xC659BE8F, 0x03050C00) 
#elif defined(MIXED_LINK) && !defined(IODRVKNX_EXTERNAL)
	#define USE_knx_setsubnetmask
	#define EXT_knx_setsubnetmask
	#define GET_knx_setsubnetmask(fl)  CAL_CMGETAPI( "knx_setsubnetmask" ) 
	#define CAL_knx_setsubnetmask  knx_setsubnetmask
	#define CHK_knx_setsubnetmask  TRUE
	#define EXP_knx_setsubnetmask  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setsubnetmask", (RTS_UINTPTR)knx_setsubnetmask, 1, 0xC659BE8F, 0x03050C00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_IoDrvKNXknx_setsubnetmask
	#define EXT_IoDrvKNXknx_setsubnetmask
	#define GET_IoDrvKNXknx_setsubnetmask  ERR_OK
	#define CAL_IoDrvKNXknx_setsubnetmask  knx_setsubnetmask
	#define CHK_IoDrvKNXknx_setsubnetmask  TRUE
	#define EXP_IoDrvKNXknx_setsubnetmask  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setsubnetmask", (RTS_UINTPTR)knx_setsubnetmask, 1, 0xC659BE8F, 0x03050C00) 
#elif defined(CPLUSPLUS)
	#define USE_knx_setsubnetmask
	#define EXT_knx_setsubnetmask
	#define GET_knx_setsubnetmask(fl)  CAL_CMGETAPI( "knx_setsubnetmask" ) 
	#define CAL_knx_setsubnetmask  knx_setsubnetmask
	#define CHK_knx_setsubnetmask  TRUE
	#define EXP_knx_setsubnetmask  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setsubnetmask", (RTS_UINTPTR)knx_setsubnetmask, 1, 0xC659BE8F, 0x03050C00) 
#else /* DYNAMIC_LINK */
	#define USE_knx_setsubnetmask  PFKNX_SETSUBNETMASK_IEC pfknx_setsubnetmask;
	#define EXT_knx_setsubnetmask  extern PFKNX_SETSUBNETMASK_IEC pfknx_setsubnetmask;
	#define GET_knx_setsubnetmask(fl)  s_pfCMGetAPI2( "knx_setsubnetmask", (RTS_VOID_FCTPTR *)&pfknx_setsubnetmask, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xC659BE8F, 0x03050C00)
	#define CAL_knx_setsubnetmask  pfknx_setsubnetmask
	#define CHK_knx_setsubnetmask  (pfknx_setsubnetmask != NULL)
	#define EXP_knx_setsubnetmask   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_setsubnetmask", (RTS_UINTPTR)knx_setsubnetmask, 1, 0xC659BE8F, 0x03050C00) 
#endif


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

void CDECL CDECL_EXT knx_transmitobject(knx_transmitobject_struct *p);
typedef void (CDECL CDECL_EXT* PFKNX_TRANSMITOBJECT_IEC) (knx_transmitobject_struct *p);
#if defined(IODRVKNX_NOTIMPLEMENTED) || defined(KNX_TRANSMITOBJECT_NOTIMPLEMENTED)
	#define USE_knx_transmitobject
	#define EXT_knx_transmitobject
	#define GET_knx_transmitobject(fl)  ERR_NOTIMPLEMENTED
	#define CAL_knx_transmitobject(p0) 
	#define CHK_knx_transmitobject  FALSE
	#define EXP_knx_transmitobject  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_knx_transmitobject
	#define EXT_knx_transmitobject
	#define GET_knx_transmitobject(fl)  CAL_CMGETAPI( "knx_transmitobject" ) 
	#define CAL_knx_transmitobject  knx_transmitobject
	#define CHK_knx_transmitobject  TRUE
	#define EXP_knx_transmitobject  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_transmitobject", (RTS_UINTPTR)knx_transmitobject, 1, 0x1438CF1F, 0x03050C00) 
#elif defined(MIXED_LINK) && !defined(IODRVKNX_EXTERNAL)
	#define USE_knx_transmitobject
	#define EXT_knx_transmitobject
	#define GET_knx_transmitobject(fl)  CAL_CMGETAPI( "knx_transmitobject" ) 
	#define CAL_knx_transmitobject  knx_transmitobject
	#define CHK_knx_transmitobject  TRUE
	#define EXP_knx_transmitobject  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_transmitobject", (RTS_UINTPTR)knx_transmitobject, 1, 0x1438CF1F, 0x03050C00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_IoDrvKNXknx_transmitobject
	#define EXT_IoDrvKNXknx_transmitobject
	#define GET_IoDrvKNXknx_transmitobject  ERR_OK
	#define CAL_IoDrvKNXknx_transmitobject  knx_transmitobject
	#define CHK_IoDrvKNXknx_transmitobject  TRUE
	#define EXP_IoDrvKNXknx_transmitobject  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_transmitobject", (RTS_UINTPTR)knx_transmitobject, 1, 0x1438CF1F, 0x03050C00) 
#elif defined(CPLUSPLUS)
	#define USE_knx_transmitobject
	#define EXT_knx_transmitobject
	#define GET_knx_transmitobject(fl)  CAL_CMGETAPI( "knx_transmitobject" ) 
	#define CAL_knx_transmitobject  knx_transmitobject
	#define CHK_knx_transmitobject  TRUE
	#define EXP_knx_transmitobject  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_transmitobject", (RTS_UINTPTR)knx_transmitobject, 1, 0x1438CF1F, 0x03050C00) 
#else /* DYNAMIC_LINK */
	#define USE_knx_transmitobject  PFKNX_TRANSMITOBJECT_IEC pfknx_transmitobject;
	#define EXT_knx_transmitobject  extern PFKNX_TRANSMITOBJECT_IEC pfknx_transmitobject;
	#define GET_knx_transmitobject(fl)  s_pfCMGetAPI2( "knx_transmitobject", (RTS_VOID_FCTPTR *)&pfknx_transmitobject, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x1438CF1F, 0x03050C00)
	#define CAL_knx_transmitobject  pfknx_transmitobject
	#define CHK_knx_transmitobject  (pfknx_transmitobject != NULL)
	#define EXP_knx_transmitobject   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"knx_transmitobject", (RTS_UINTPTR)knx_transmitobject, 1, 0x1438CF1F, 0x03050C00) 
#endif


#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/




typedef struct
{
	IBase_C *pBase;
} IIoDrvKNX_C;

#ifdef CPLUSPLUS
class IIoDrvKNX : public IBase
{
	public:
};
	#ifndef ITF_IoDrvKNX
		#define ITF_IoDrvKNX static IIoDrvKNX *pIIoDrvKNX = NULL;
	#endif
	#define EXTITF_IoDrvKNX
#else	/*CPLUSPLUS*/
	typedef IIoDrvKNX_C		IIoDrvKNX;
	#ifndef ITF_IoDrvKNX
		#define ITF_IoDrvKNX
	#endif
	#define EXTITF_IoDrvKNX
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_IODRVKNXITF_H_*/
