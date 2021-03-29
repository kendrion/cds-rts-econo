 /**
 * <interfacename>CmpOPCUAStack_Implementation</interfacename>
 * <description></description>
 *
 * <copyright></copyright>
 */


	
	
#ifndef _CMPOPCUASTACK_IMPLEMENTATIONITF_H_
#define _CMPOPCUASTACK_IMPLEMENTATIONITF_H_

#include "CmpStd.h"

 

 



#include "CmpOPCUAStackItf.h"

/** EXTERN LIB SECTION BEGIN **/
/*  Comments are ignored for m4 compiler so restructured text can be used.  */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description>opcuaapplicationdescriptionclear</description>
 */
typedef struct tagopcuaapplicationdescriptionclear_struct
{
	OpcUa_ApplicationDescription *pValue;	/* VAR_INPUT */	
} opcuaapplicationdescriptionclear_struct;

void CDECL CDECL_EXT opcuaapplicationdescriptionclear(opcuaapplicationdescriptionclear_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAAPPLICATIONDESCRIPTIONCLEAR_IEC) (opcuaapplicationdescriptionclear_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAAPPLICATIONDESCRIPTIONCLEAR_NOTIMPLEMENTED)
	#define USE_opcuaapplicationdescriptionclear
	#define EXT_opcuaapplicationdescriptionclear
	#define GET_opcuaapplicationdescriptionclear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaapplicationdescriptionclear(p0) 
	#define CHK_opcuaapplicationdescriptionclear  FALSE
	#define EXP_opcuaapplicationdescriptionclear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaapplicationdescriptionclear
	#define EXT_opcuaapplicationdescriptionclear
	#define GET_opcuaapplicationdescriptionclear(fl)  CAL_CMGETAPI( "opcuaapplicationdescriptionclear" ) 
	#define CAL_opcuaapplicationdescriptionclear  opcuaapplicationdescriptionclear
	#define CHK_opcuaapplicationdescriptionclear  TRUE
	#define EXP_opcuaapplicationdescriptionclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaapplicationdescriptionclear", (RTS_UINTPTR)opcuaapplicationdescriptionclear, 1, 0xD8FE8740, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaapplicationdescriptionclear
	#define EXT_opcuaapplicationdescriptionclear
	#define GET_opcuaapplicationdescriptionclear(fl)  CAL_CMGETAPI( "opcuaapplicationdescriptionclear" ) 
	#define CAL_opcuaapplicationdescriptionclear  opcuaapplicationdescriptionclear
	#define CHK_opcuaapplicationdescriptionclear  TRUE
	#define EXP_opcuaapplicationdescriptionclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaapplicationdescriptionclear", (RTS_UINTPTR)opcuaapplicationdescriptionclear, 1, 0xD8FE8740, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuaapplicationdescriptionclear
	#define EXT_CmpOPCUAStack_Implementationopcuaapplicationdescriptionclear
	#define GET_CmpOPCUAStack_Implementationopcuaapplicationdescriptionclear  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuaapplicationdescriptionclear  opcuaapplicationdescriptionclear
	#define CHK_CmpOPCUAStack_Implementationopcuaapplicationdescriptionclear  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuaapplicationdescriptionclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaapplicationdescriptionclear", (RTS_UINTPTR)opcuaapplicationdescriptionclear, 1, 0xD8FE8740, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaapplicationdescriptionclear
	#define EXT_opcuaapplicationdescriptionclear
	#define GET_opcuaapplicationdescriptionclear(fl)  CAL_CMGETAPI( "opcuaapplicationdescriptionclear" ) 
	#define CAL_opcuaapplicationdescriptionclear  opcuaapplicationdescriptionclear
	#define CHK_opcuaapplicationdescriptionclear  TRUE
	#define EXP_opcuaapplicationdescriptionclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaapplicationdescriptionclear", (RTS_UINTPTR)opcuaapplicationdescriptionclear, 1, 0xD8FE8740, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaapplicationdescriptionclear  PFOPCUAAPPLICATIONDESCRIPTIONCLEAR_IEC pfopcuaapplicationdescriptionclear;
	#define EXT_opcuaapplicationdescriptionclear  extern PFOPCUAAPPLICATIONDESCRIPTIONCLEAR_IEC pfopcuaapplicationdescriptionclear;
	#define GET_opcuaapplicationdescriptionclear(fl)  s_pfCMGetAPI2( "opcuaapplicationdescriptionclear", (RTS_VOID_FCTPTR *)&pfopcuaapplicationdescriptionclear, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xD8FE8740, 0x03051000)
	#define CAL_opcuaapplicationdescriptionclear  pfopcuaapplicationdescriptionclear
	#define CHK_opcuaapplicationdescriptionclear  (pfopcuaapplicationdescriptionclear != NULL)
	#define EXP_opcuaapplicationdescriptionclear   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaapplicationdescriptionclear", (RTS_UINTPTR)opcuaapplicationdescriptionclear, 1, 0xD8FE8740, 0x03051000) 
#endif


/**
 * <description>opcuaapplicationdescriptioninitialize</description>
 */
typedef struct tagopcuaapplicationdescriptioninitialize_struct
{
	OpcUa_ApplicationDescription *pValue;	/* VAR_INPUT */	
} opcuaapplicationdescriptioninitialize_struct;

void CDECL CDECL_EXT opcuaapplicationdescriptioninitialize(opcuaapplicationdescriptioninitialize_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAAPPLICATIONDESCRIPTIONINITIALIZE_IEC) (opcuaapplicationdescriptioninitialize_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAAPPLICATIONDESCRIPTIONINITIALIZE_NOTIMPLEMENTED)
	#define USE_opcuaapplicationdescriptioninitialize
	#define EXT_opcuaapplicationdescriptioninitialize
	#define GET_opcuaapplicationdescriptioninitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaapplicationdescriptioninitialize(p0) 
	#define CHK_opcuaapplicationdescriptioninitialize  FALSE
	#define EXP_opcuaapplicationdescriptioninitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaapplicationdescriptioninitialize
	#define EXT_opcuaapplicationdescriptioninitialize
	#define GET_opcuaapplicationdescriptioninitialize(fl)  CAL_CMGETAPI( "opcuaapplicationdescriptioninitialize" ) 
	#define CAL_opcuaapplicationdescriptioninitialize  opcuaapplicationdescriptioninitialize
	#define CHK_opcuaapplicationdescriptioninitialize  TRUE
	#define EXP_opcuaapplicationdescriptioninitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaapplicationdescriptioninitialize", (RTS_UINTPTR)opcuaapplicationdescriptioninitialize, 1, 0x786640C1, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaapplicationdescriptioninitialize
	#define EXT_opcuaapplicationdescriptioninitialize
	#define GET_opcuaapplicationdescriptioninitialize(fl)  CAL_CMGETAPI( "opcuaapplicationdescriptioninitialize" ) 
	#define CAL_opcuaapplicationdescriptioninitialize  opcuaapplicationdescriptioninitialize
	#define CHK_opcuaapplicationdescriptioninitialize  TRUE
	#define EXP_opcuaapplicationdescriptioninitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaapplicationdescriptioninitialize", (RTS_UINTPTR)opcuaapplicationdescriptioninitialize, 1, 0x786640C1, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuaapplicationdescriptioninitialize
	#define EXT_CmpOPCUAStack_Implementationopcuaapplicationdescriptioninitialize
	#define GET_CmpOPCUAStack_Implementationopcuaapplicationdescriptioninitialize  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuaapplicationdescriptioninitialize  opcuaapplicationdescriptioninitialize
	#define CHK_CmpOPCUAStack_Implementationopcuaapplicationdescriptioninitialize  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuaapplicationdescriptioninitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaapplicationdescriptioninitialize", (RTS_UINTPTR)opcuaapplicationdescriptioninitialize, 1, 0x786640C1, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaapplicationdescriptioninitialize
	#define EXT_opcuaapplicationdescriptioninitialize
	#define GET_opcuaapplicationdescriptioninitialize(fl)  CAL_CMGETAPI( "opcuaapplicationdescriptioninitialize" ) 
	#define CAL_opcuaapplicationdescriptioninitialize  opcuaapplicationdescriptioninitialize
	#define CHK_opcuaapplicationdescriptioninitialize  TRUE
	#define EXP_opcuaapplicationdescriptioninitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaapplicationdescriptioninitialize", (RTS_UINTPTR)opcuaapplicationdescriptioninitialize, 1, 0x786640C1, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaapplicationdescriptioninitialize  PFOPCUAAPPLICATIONDESCRIPTIONINITIALIZE_IEC pfopcuaapplicationdescriptioninitialize;
	#define EXT_opcuaapplicationdescriptioninitialize  extern PFOPCUAAPPLICATIONDESCRIPTIONINITIALIZE_IEC pfopcuaapplicationdescriptioninitialize;
	#define GET_opcuaapplicationdescriptioninitialize(fl)  s_pfCMGetAPI2( "opcuaapplicationdescriptioninitialize", (RTS_VOID_FCTPTR *)&pfopcuaapplicationdescriptioninitialize, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x786640C1, 0x03051000)
	#define CAL_opcuaapplicationdescriptioninitialize  pfopcuaapplicationdescriptioninitialize
	#define CHK_opcuaapplicationdescriptioninitialize  (pfopcuaapplicationdescriptioninitialize != NULL)
	#define EXP_opcuaapplicationdescriptioninitialize   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaapplicationdescriptioninitialize", (RTS_UINTPTR)opcuaapplicationdescriptioninitialize, 1, 0x786640C1, 0x03051000) 
#endif


/**
 * <description>opcuabrowsepathclear</description>
 */
typedef struct tagopcuabrowsepathclear_struct
{
	OpcUa_BrowsePath *pValue;			/* VAR_INPUT */	
} opcuabrowsepathclear_struct;

void CDECL CDECL_EXT opcuabrowsepathclear(opcuabrowsepathclear_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUABROWSEPATHCLEAR_IEC) (opcuabrowsepathclear_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUABROWSEPATHCLEAR_NOTIMPLEMENTED)
	#define USE_opcuabrowsepathclear
	#define EXT_opcuabrowsepathclear
	#define GET_opcuabrowsepathclear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuabrowsepathclear(p0) 
	#define CHK_opcuabrowsepathclear  FALSE
	#define EXP_opcuabrowsepathclear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuabrowsepathclear
	#define EXT_opcuabrowsepathclear
	#define GET_opcuabrowsepathclear(fl)  CAL_CMGETAPI( "opcuabrowsepathclear" ) 
	#define CAL_opcuabrowsepathclear  opcuabrowsepathclear
	#define CHK_opcuabrowsepathclear  TRUE
	#define EXP_opcuabrowsepathclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabrowsepathclear", (RTS_UINTPTR)opcuabrowsepathclear, 1, 0xBB891AEB, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuabrowsepathclear
	#define EXT_opcuabrowsepathclear
	#define GET_opcuabrowsepathclear(fl)  CAL_CMGETAPI( "opcuabrowsepathclear" ) 
	#define CAL_opcuabrowsepathclear  opcuabrowsepathclear
	#define CHK_opcuabrowsepathclear  TRUE
	#define EXP_opcuabrowsepathclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabrowsepathclear", (RTS_UINTPTR)opcuabrowsepathclear, 1, 0xBB891AEB, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuabrowsepathclear
	#define EXT_CmpOPCUAStack_Implementationopcuabrowsepathclear
	#define GET_CmpOPCUAStack_Implementationopcuabrowsepathclear  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuabrowsepathclear  opcuabrowsepathclear
	#define CHK_CmpOPCUAStack_Implementationopcuabrowsepathclear  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuabrowsepathclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabrowsepathclear", (RTS_UINTPTR)opcuabrowsepathclear, 1, 0xBB891AEB, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuabrowsepathclear
	#define EXT_opcuabrowsepathclear
	#define GET_opcuabrowsepathclear(fl)  CAL_CMGETAPI( "opcuabrowsepathclear" ) 
	#define CAL_opcuabrowsepathclear  opcuabrowsepathclear
	#define CHK_opcuabrowsepathclear  TRUE
	#define EXP_opcuabrowsepathclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabrowsepathclear", (RTS_UINTPTR)opcuabrowsepathclear, 1, 0xBB891AEB, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuabrowsepathclear  PFOPCUABROWSEPATHCLEAR_IEC pfopcuabrowsepathclear;
	#define EXT_opcuabrowsepathclear  extern PFOPCUABROWSEPATHCLEAR_IEC pfopcuabrowsepathclear;
	#define GET_opcuabrowsepathclear(fl)  s_pfCMGetAPI2( "opcuabrowsepathclear", (RTS_VOID_FCTPTR *)&pfopcuabrowsepathclear, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xBB891AEB, 0x03051000)
	#define CAL_opcuabrowsepathclear  pfopcuabrowsepathclear
	#define CHK_opcuabrowsepathclear  (pfopcuabrowsepathclear != NULL)
	#define EXP_opcuabrowsepathclear   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabrowsepathclear", (RTS_UINTPTR)opcuabrowsepathclear, 1, 0xBB891AEB, 0x03051000) 
#endif


/**
 * <description>opcuabrowsepathinitialize</description>
 */
typedef struct tagopcuabrowsepathinitialize_struct
{
	OpcUa_BrowsePath *pValue;			/* VAR_INPUT */	
} opcuabrowsepathinitialize_struct;

void CDECL CDECL_EXT opcuabrowsepathinitialize(opcuabrowsepathinitialize_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUABROWSEPATHINITIALIZE_IEC) (opcuabrowsepathinitialize_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUABROWSEPATHINITIALIZE_NOTIMPLEMENTED)
	#define USE_opcuabrowsepathinitialize
	#define EXT_opcuabrowsepathinitialize
	#define GET_opcuabrowsepathinitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuabrowsepathinitialize(p0) 
	#define CHK_opcuabrowsepathinitialize  FALSE
	#define EXP_opcuabrowsepathinitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuabrowsepathinitialize
	#define EXT_opcuabrowsepathinitialize
	#define GET_opcuabrowsepathinitialize(fl)  CAL_CMGETAPI( "opcuabrowsepathinitialize" ) 
	#define CAL_opcuabrowsepathinitialize  opcuabrowsepathinitialize
	#define CHK_opcuabrowsepathinitialize  TRUE
	#define EXP_opcuabrowsepathinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabrowsepathinitialize", (RTS_UINTPTR)opcuabrowsepathinitialize, 1, 0x3938484A, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuabrowsepathinitialize
	#define EXT_opcuabrowsepathinitialize
	#define GET_opcuabrowsepathinitialize(fl)  CAL_CMGETAPI( "opcuabrowsepathinitialize" ) 
	#define CAL_opcuabrowsepathinitialize  opcuabrowsepathinitialize
	#define CHK_opcuabrowsepathinitialize  TRUE
	#define EXP_opcuabrowsepathinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabrowsepathinitialize", (RTS_UINTPTR)opcuabrowsepathinitialize, 1, 0x3938484A, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuabrowsepathinitialize
	#define EXT_CmpOPCUAStack_Implementationopcuabrowsepathinitialize
	#define GET_CmpOPCUAStack_Implementationopcuabrowsepathinitialize  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuabrowsepathinitialize  opcuabrowsepathinitialize
	#define CHK_CmpOPCUAStack_Implementationopcuabrowsepathinitialize  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuabrowsepathinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabrowsepathinitialize", (RTS_UINTPTR)opcuabrowsepathinitialize, 1, 0x3938484A, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuabrowsepathinitialize
	#define EXT_opcuabrowsepathinitialize
	#define GET_opcuabrowsepathinitialize(fl)  CAL_CMGETAPI( "opcuabrowsepathinitialize" ) 
	#define CAL_opcuabrowsepathinitialize  opcuabrowsepathinitialize
	#define CHK_opcuabrowsepathinitialize  TRUE
	#define EXP_opcuabrowsepathinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabrowsepathinitialize", (RTS_UINTPTR)opcuabrowsepathinitialize, 1, 0x3938484A, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuabrowsepathinitialize  PFOPCUABROWSEPATHINITIALIZE_IEC pfopcuabrowsepathinitialize;
	#define EXT_opcuabrowsepathinitialize  extern PFOPCUABROWSEPATHINITIALIZE_IEC pfopcuabrowsepathinitialize;
	#define GET_opcuabrowsepathinitialize(fl)  s_pfCMGetAPI2( "opcuabrowsepathinitialize", (RTS_VOID_FCTPTR *)&pfopcuabrowsepathinitialize, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x3938484A, 0x03051000)
	#define CAL_opcuabrowsepathinitialize  pfopcuabrowsepathinitialize
	#define CHK_opcuabrowsepathinitialize  (pfopcuabrowsepathinitialize != NULL)
	#define EXP_opcuabrowsepathinitialize   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabrowsepathinitialize", (RTS_UINTPTR)opcuabrowsepathinitialize, 1, 0x3938484A, 0x03051000) 
#endif


/**
 * <description>opcuabrowsepathresultclear</description>
 */
typedef struct tagopcuabrowsepathresultclear_struct
{
	OpcUa_BrowsePathResult *pValue;		/* VAR_INPUT */	
} opcuabrowsepathresultclear_struct;

void CDECL CDECL_EXT opcuabrowsepathresultclear(opcuabrowsepathresultclear_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUABROWSEPATHRESULTCLEAR_IEC) (opcuabrowsepathresultclear_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUABROWSEPATHRESULTCLEAR_NOTIMPLEMENTED)
	#define USE_opcuabrowsepathresultclear
	#define EXT_opcuabrowsepathresultclear
	#define GET_opcuabrowsepathresultclear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuabrowsepathresultclear(p0) 
	#define CHK_opcuabrowsepathresultclear  FALSE
	#define EXP_opcuabrowsepathresultclear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuabrowsepathresultclear
	#define EXT_opcuabrowsepathresultclear
	#define GET_opcuabrowsepathresultclear(fl)  CAL_CMGETAPI( "opcuabrowsepathresultclear" ) 
	#define CAL_opcuabrowsepathresultclear  opcuabrowsepathresultclear
	#define CHK_opcuabrowsepathresultclear  TRUE
	#define EXP_opcuabrowsepathresultclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabrowsepathresultclear", (RTS_UINTPTR)opcuabrowsepathresultclear, 1, 0x8DA7753D, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuabrowsepathresultclear
	#define EXT_opcuabrowsepathresultclear
	#define GET_opcuabrowsepathresultclear(fl)  CAL_CMGETAPI( "opcuabrowsepathresultclear" ) 
	#define CAL_opcuabrowsepathresultclear  opcuabrowsepathresultclear
	#define CHK_opcuabrowsepathresultclear  TRUE
	#define EXP_opcuabrowsepathresultclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabrowsepathresultclear", (RTS_UINTPTR)opcuabrowsepathresultclear, 1, 0x8DA7753D, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuabrowsepathresultclear
	#define EXT_CmpOPCUAStack_Implementationopcuabrowsepathresultclear
	#define GET_CmpOPCUAStack_Implementationopcuabrowsepathresultclear  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuabrowsepathresultclear  opcuabrowsepathresultclear
	#define CHK_CmpOPCUAStack_Implementationopcuabrowsepathresultclear  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuabrowsepathresultclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabrowsepathresultclear", (RTS_UINTPTR)opcuabrowsepathresultclear, 1, 0x8DA7753D, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuabrowsepathresultclear
	#define EXT_opcuabrowsepathresultclear
	#define GET_opcuabrowsepathresultclear(fl)  CAL_CMGETAPI( "opcuabrowsepathresultclear" ) 
	#define CAL_opcuabrowsepathresultclear  opcuabrowsepathresultclear
	#define CHK_opcuabrowsepathresultclear  TRUE
	#define EXP_opcuabrowsepathresultclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabrowsepathresultclear", (RTS_UINTPTR)opcuabrowsepathresultclear, 1, 0x8DA7753D, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuabrowsepathresultclear  PFOPCUABROWSEPATHRESULTCLEAR_IEC pfopcuabrowsepathresultclear;
	#define EXT_opcuabrowsepathresultclear  extern PFOPCUABROWSEPATHRESULTCLEAR_IEC pfopcuabrowsepathresultclear;
	#define GET_opcuabrowsepathresultclear(fl)  s_pfCMGetAPI2( "opcuabrowsepathresultclear", (RTS_VOID_FCTPTR *)&pfopcuabrowsepathresultclear, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x8DA7753D, 0x03051000)
	#define CAL_opcuabrowsepathresultclear  pfopcuabrowsepathresultclear
	#define CHK_opcuabrowsepathresultclear  (pfopcuabrowsepathresultclear != NULL)
	#define EXP_opcuabrowsepathresultclear   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabrowsepathresultclear", (RTS_UINTPTR)opcuabrowsepathresultclear, 1, 0x8DA7753D, 0x03051000) 
#endif


/**
 * <description>opcuabrowsepathresultinitialize</description>
 */
typedef struct tagopcuabrowsepathresultinitialize_struct
{
	OpcUa_BrowsePathResult *pValue;		/* VAR_INPUT */	
} opcuabrowsepathresultinitialize_struct;

void CDECL CDECL_EXT opcuabrowsepathresultinitialize(opcuabrowsepathresultinitialize_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUABROWSEPATHRESULTINITIALIZE_IEC) (opcuabrowsepathresultinitialize_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUABROWSEPATHRESULTINITIALIZE_NOTIMPLEMENTED)
	#define USE_opcuabrowsepathresultinitialize
	#define EXT_opcuabrowsepathresultinitialize
	#define GET_opcuabrowsepathresultinitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuabrowsepathresultinitialize(p0) 
	#define CHK_opcuabrowsepathresultinitialize  FALSE
	#define EXP_opcuabrowsepathresultinitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuabrowsepathresultinitialize
	#define EXT_opcuabrowsepathresultinitialize
	#define GET_opcuabrowsepathresultinitialize(fl)  CAL_CMGETAPI( "opcuabrowsepathresultinitialize" ) 
	#define CAL_opcuabrowsepathresultinitialize  opcuabrowsepathresultinitialize
	#define CHK_opcuabrowsepathresultinitialize  TRUE
	#define EXP_opcuabrowsepathresultinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabrowsepathresultinitialize", (RTS_UINTPTR)opcuabrowsepathresultinitialize, 1, 0xAF1770C6, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuabrowsepathresultinitialize
	#define EXT_opcuabrowsepathresultinitialize
	#define GET_opcuabrowsepathresultinitialize(fl)  CAL_CMGETAPI( "opcuabrowsepathresultinitialize" ) 
	#define CAL_opcuabrowsepathresultinitialize  opcuabrowsepathresultinitialize
	#define CHK_opcuabrowsepathresultinitialize  TRUE
	#define EXP_opcuabrowsepathresultinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabrowsepathresultinitialize", (RTS_UINTPTR)opcuabrowsepathresultinitialize, 1, 0xAF1770C6, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuabrowsepathresultinitialize
	#define EXT_CmpOPCUAStack_Implementationopcuabrowsepathresultinitialize
	#define GET_CmpOPCUAStack_Implementationopcuabrowsepathresultinitialize  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuabrowsepathresultinitialize  opcuabrowsepathresultinitialize
	#define CHK_CmpOPCUAStack_Implementationopcuabrowsepathresultinitialize  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuabrowsepathresultinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabrowsepathresultinitialize", (RTS_UINTPTR)opcuabrowsepathresultinitialize, 1, 0xAF1770C6, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuabrowsepathresultinitialize
	#define EXT_opcuabrowsepathresultinitialize
	#define GET_opcuabrowsepathresultinitialize(fl)  CAL_CMGETAPI( "opcuabrowsepathresultinitialize" ) 
	#define CAL_opcuabrowsepathresultinitialize  opcuabrowsepathresultinitialize
	#define CHK_opcuabrowsepathresultinitialize  TRUE
	#define EXP_opcuabrowsepathresultinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabrowsepathresultinitialize", (RTS_UINTPTR)opcuabrowsepathresultinitialize, 1, 0xAF1770C6, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuabrowsepathresultinitialize  PFOPCUABROWSEPATHRESULTINITIALIZE_IEC pfopcuabrowsepathresultinitialize;
	#define EXT_opcuabrowsepathresultinitialize  extern PFOPCUABROWSEPATHRESULTINITIALIZE_IEC pfopcuabrowsepathresultinitialize;
	#define GET_opcuabrowsepathresultinitialize(fl)  s_pfCMGetAPI2( "opcuabrowsepathresultinitialize", (RTS_VOID_FCTPTR *)&pfopcuabrowsepathresultinitialize, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xAF1770C6, 0x03051000)
	#define CAL_opcuabrowsepathresultinitialize  pfopcuabrowsepathresultinitialize
	#define CHK_opcuabrowsepathresultinitialize  (pfopcuabrowsepathresultinitialize != NULL)
	#define EXP_opcuabrowsepathresultinitialize   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabrowsepathresultinitialize", (RTS_UINTPTR)opcuabrowsepathresultinitialize, 1, 0xAF1770C6, 0x03051000) 
#endif


/**
 * <description>opcuabrowseresultclear</description>
 */
typedef struct tagopcuabrowseresultclear_struct
{
	OpcUa_BrowseResult *pValue;			/* VAR_INPUT */	
} opcuabrowseresultclear_struct;

void CDECL CDECL_EXT opcuabrowseresultclear(opcuabrowseresultclear_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUABROWSERESULTCLEAR_IEC) (opcuabrowseresultclear_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUABROWSERESULTCLEAR_NOTIMPLEMENTED)
	#define USE_opcuabrowseresultclear
	#define EXT_opcuabrowseresultclear
	#define GET_opcuabrowseresultclear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuabrowseresultclear(p0) 
	#define CHK_opcuabrowseresultclear  FALSE
	#define EXP_opcuabrowseresultclear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuabrowseresultclear
	#define EXT_opcuabrowseresultclear
	#define GET_opcuabrowseresultclear(fl)  CAL_CMGETAPI( "opcuabrowseresultclear" ) 
	#define CAL_opcuabrowseresultclear  opcuabrowseresultclear
	#define CHK_opcuabrowseresultclear  TRUE
	#define EXP_opcuabrowseresultclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabrowseresultclear", (RTS_UINTPTR)opcuabrowseresultclear, 1, 0x6820FD5D, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuabrowseresultclear
	#define EXT_opcuabrowseresultclear
	#define GET_opcuabrowseresultclear(fl)  CAL_CMGETAPI( "opcuabrowseresultclear" ) 
	#define CAL_opcuabrowseresultclear  opcuabrowseresultclear
	#define CHK_opcuabrowseresultclear  TRUE
	#define EXP_opcuabrowseresultclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabrowseresultclear", (RTS_UINTPTR)opcuabrowseresultclear, 1, 0x6820FD5D, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuabrowseresultclear
	#define EXT_CmpOPCUAStack_Implementationopcuabrowseresultclear
	#define GET_CmpOPCUAStack_Implementationopcuabrowseresultclear  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuabrowseresultclear  opcuabrowseresultclear
	#define CHK_CmpOPCUAStack_Implementationopcuabrowseresultclear  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuabrowseresultclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabrowseresultclear", (RTS_UINTPTR)opcuabrowseresultclear, 1, 0x6820FD5D, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuabrowseresultclear
	#define EXT_opcuabrowseresultclear
	#define GET_opcuabrowseresultclear(fl)  CAL_CMGETAPI( "opcuabrowseresultclear" ) 
	#define CAL_opcuabrowseresultclear  opcuabrowseresultclear
	#define CHK_opcuabrowseresultclear  TRUE
	#define EXP_opcuabrowseresultclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabrowseresultclear", (RTS_UINTPTR)opcuabrowseresultclear, 1, 0x6820FD5D, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuabrowseresultclear  PFOPCUABROWSERESULTCLEAR_IEC pfopcuabrowseresultclear;
	#define EXT_opcuabrowseresultclear  extern PFOPCUABROWSERESULTCLEAR_IEC pfopcuabrowseresultclear;
	#define GET_opcuabrowseresultclear(fl)  s_pfCMGetAPI2( "opcuabrowseresultclear", (RTS_VOID_FCTPTR *)&pfopcuabrowseresultclear, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x6820FD5D, 0x03051000)
	#define CAL_opcuabrowseresultclear  pfopcuabrowseresultclear
	#define CHK_opcuabrowseresultclear  (pfopcuabrowseresultclear != NULL)
	#define EXP_opcuabrowseresultclear   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabrowseresultclear", (RTS_UINTPTR)opcuabrowseresultclear, 1, 0x6820FD5D, 0x03051000) 
#endif


/**
 * <description>opcuabrowseresultinitialize</description>
 */
typedef struct tagopcuabrowseresultinitialize_struct
{
	OpcUa_BrowseResult *pValue;			/* VAR_INPUT */	
} opcuabrowseresultinitialize_struct;

void CDECL CDECL_EXT opcuabrowseresultinitialize(opcuabrowseresultinitialize_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUABROWSERESULTINITIALIZE_IEC) (opcuabrowseresultinitialize_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUABROWSERESULTINITIALIZE_NOTIMPLEMENTED)
	#define USE_opcuabrowseresultinitialize
	#define EXT_opcuabrowseresultinitialize
	#define GET_opcuabrowseresultinitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuabrowseresultinitialize(p0) 
	#define CHK_opcuabrowseresultinitialize  FALSE
	#define EXP_opcuabrowseresultinitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuabrowseresultinitialize
	#define EXT_opcuabrowseresultinitialize
	#define GET_opcuabrowseresultinitialize(fl)  CAL_CMGETAPI( "opcuabrowseresultinitialize" ) 
	#define CAL_opcuabrowseresultinitialize  opcuabrowseresultinitialize
	#define CHK_opcuabrowseresultinitialize  TRUE
	#define EXP_opcuabrowseresultinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabrowseresultinitialize", (RTS_UINTPTR)opcuabrowseresultinitialize, 1, 0x5DC17EFF, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuabrowseresultinitialize
	#define EXT_opcuabrowseresultinitialize
	#define GET_opcuabrowseresultinitialize(fl)  CAL_CMGETAPI( "opcuabrowseresultinitialize" ) 
	#define CAL_opcuabrowseresultinitialize  opcuabrowseresultinitialize
	#define CHK_opcuabrowseresultinitialize  TRUE
	#define EXP_opcuabrowseresultinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabrowseresultinitialize", (RTS_UINTPTR)opcuabrowseresultinitialize, 1, 0x5DC17EFF, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuabrowseresultinitialize
	#define EXT_CmpOPCUAStack_Implementationopcuabrowseresultinitialize
	#define GET_CmpOPCUAStack_Implementationopcuabrowseresultinitialize  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuabrowseresultinitialize  opcuabrowseresultinitialize
	#define CHK_CmpOPCUAStack_Implementationopcuabrowseresultinitialize  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuabrowseresultinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabrowseresultinitialize", (RTS_UINTPTR)opcuabrowseresultinitialize, 1, 0x5DC17EFF, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuabrowseresultinitialize
	#define EXT_opcuabrowseresultinitialize
	#define GET_opcuabrowseresultinitialize(fl)  CAL_CMGETAPI( "opcuabrowseresultinitialize" ) 
	#define CAL_opcuabrowseresultinitialize  opcuabrowseresultinitialize
	#define CHK_opcuabrowseresultinitialize  TRUE
	#define EXP_opcuabrowseresultinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabrowseresultinitialize", (RTS_UINTPTR)opcuabrowseresultinitialize, 1, 0x5DC17EFF, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuabrowseresultinitialize  PFOPCUABROWSERESULTINITIALIZE_IEC pfopcuabrowseresultinitialize;
	#define EXT_opcuabrowseresultinitialize  extern PFOPCUABROWSERESULTINITIALIZE_IEC pfopcuabrowseresultinitialize;
	#define GET_opcuabrowseresultinitialize(fl)  s_pfCMGetAPI2( "opcuabrowseresultinitialize", (RTS_VOID_FCTPTR *)&pfopcuabrowseresultinitialize, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x5DC17EFF, 0x03051000)
	#define CAL_opcuabrowseresultinitialize  pfopcuabrowseresultinitialize
	#define CHK_opcuabrowseresultinitialize  (pfopcuabrowseresultinitialize != NULL)
	#define EXP_opcuabrowseresultinitialize   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabrowseresultinitialize", (RTS_UINTPTR)opcuabrowseresultinitialize, 1, 0x5DC17EFF, 0x03051000) 
#endif


/**
 * <description>opcuabytestringclear</description>
 */
typedef struct tagopcuabytestringclear_struct
{
	OpcUa_ByteString *value;			/* VAR_INPUT */	
} opcuabytestringclear_struct;

void CDECL CDECL_EXT opcuabytestringclear(opcuabytestringclear_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUABYTESTRINGCLEAR_IEC) (opcuabytestringclear_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUABYTESTRINGCLEAR_NOTIMPLEMENTED)
	#define USE_opcuabytestringclear
	#define EXT_opcuabytestringclear
	#define GET_opcuabytestringclear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuabytestringclear(p0) 
	#define CHK_opcuabytestringclear  FALSE
	#define EXP_opcuabytestringclear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuabytestringclear
	#define EXT_opcuabytestringclear
	#define GET_opcuabytestringclear(fl)  CAL_CMGETAPI( "opcuabytestringclear" ) 
	#define CAL_opcuabytestringclear  opcuabytestringclear
	#define CHK_opcuabytestringclear  TRUE
	#define EXP_opcuabytestringclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabytestringclear", (RTS_UINTPTR)opcuabytestringclear, 1, 0x775210EC, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuabytestringclear
	#define EXT_opcuabytestringclear
	#define GET_opcuabytestringclear(fl)  CAL_CMGETAPI( "opcuabytestringclear" ) 
	#define CAL_opcuabytestringclear  opcuabytestringclear
	#define CHK_opcuabytestringclear  TRUE
	#define EXP_opcuabytestringclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabytestringclear", (RTS_UINTPTR)opcuabytestringclear, 1, 0x775210EC, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuabytestringclear
	#define EXT_CmpOPCUAStack_Implementationopcuabytestringclear
	#define GET_CmpOPCUAStack_Implementationopcuabytestringclear  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuabytestringclear  opcuabytestringclear
	#define CHK_CmpOPCUAStack_Implementationopcuabytestringclear  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuabytestringclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabytestringclear", (RTS_UINTPTR)opcuabytestringclear, 1, 0x775210EC, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuabytestringclear
	#define EXT_opcuabytestringclear
	#define GET_opcuabytestringclear(fl)  CAL_CMGETAPI( "opcuabytestringclear" ) 
	#define CAL_opcuabytestringclear  opcuabytestringclear
	#define CHK_opcuabytestringclear  TRUE
	#define EXP_opcuabytestringclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabytestringclear", (RTS_UINTPTR)opcuabytestringclear, 1, 0x775210EC, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuabytestringclear  PFOPCUABYTESTRINGCLEAR_IEC pfopcuabytestringclear;
	#define EXT_opcuabytestringclear  extern PFOPCUABYTESTRINGCLEAR_IEC pfopcuabytestringclear;
	#define GET_opcuabytestringclear(fl)  s_pfCMGetAPI2( "opcuabytestringclear", (RTS_VOID_FCTPTR *)&pfopcuabytestringclear, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x775210EC, 0x03051000)
	#define CAL_opcuabytestringclear  pfopcuabytestringclear
	#define CHK_opcuabytestringclear  (pfopcuabytestringclear != NULL)
	#define EXP_opcuabytestringclear   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabytestringclear", (RTS_UINTPTR)opcuabytestringclear, 1, 0x775210EC, 0x03051000) 
#endif


/**
 * <description>opcuabytestringcompare</description>
 */
typedef struct tagopcuabytestringcompare_struct
{
	OpcUa_ByteString *value1;			/* VAR_INPUT */	
	OpcUa_ByteString *value2;			/* VAR_INPUT */	
	RTS_IEC_DINT OpcUaByteStringCompare;	/* VAR_OUTPUT */	
} opcuabytestringcompare_struct;

void CDECL CDECL_EXT opcuabytestringcompare(opcuabytestringcompare_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUABYTESTRINGCOMPARE_IEC) (opcuabytestringcompare_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUABYTESTRINGCOMPARE_NOTIMPLEMENTED)
	#define USE_opcuabytestringcompare
	#define EXT_opcuabytestringcompare
	#define GET_opcuabytestringcompare(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuabytestringcompare(p0) 
	#define CHK_opcuabytestringcompare  FALSE
	#define EXP_opcuabytestringcompare  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuabytestringcompare
	#define EXT_opcuabytestringcompare
	#define GET_opcuabytestringcompare(fl)  CAL_CMGETAPI( "opcuabytestringcompare" ) 
	#define CAL_opcuabytestringcompare  opcuabytestringcompare
	#define CHK_opcuabytestringcompare  TRUE
	#define EXP_opcuabytestringcompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabytestringcompare", (RTS_UINTPTR)opcuabytestringcompare, 1, 0x7FCDF593, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuabytestringcompare
	#define EXT_opcuabytestringcompare
	#define GET_opcuabytestringcompare(fl)  CAL_CMGETAPI( "opcuabytestringcompare" ) 
	#define CAL_opcuabytestringcompare  opcuabytestringcompare
	#define CHK_opcuabytestringcompare  TRUE
	#define EXP_opcuabytestringcompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabytestringcompare", (RTS_UINTPTR)opcuabytestringcompare, 1, 0x7FCDF593, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuabytestringcompare
	#define EXT_CmpOPCUAStack_Implementationopcuabytestringcompare
	#define GET_CmpOPCUAStack_Implementationopcuabytestringcompare  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuabytestringcompare  opcuabytestringcompare
	#define CHK_CmpOPCUAStack_Implementationopcuabytestringcompare  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuabytestringcompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabytestringcompare", (RTS_UINTPTR)opcuabytestringcompare, 1, 0x7FCDF593, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuabytestringcompare
	#define EXT_opcuabytestringcompare
	#define GET_opcuabytestringcompare(fl)  CAL_CMGETAPI( "opcuabytestringcompare" ) 
	#define CAL_opcuabytestringcompare  opcuabytestringcompare
	#define CHK_opcuabytestringcompare  TRUE
	#define EXP_opcuabytestringcompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabytestringcompare", (RTS_UINTPTR)opcuabytestringcompare, 1, 0x7FCDF593, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuabytestringcompare  PFOPCUABYTESTRINGCOMPARE_IEC pfopcuabytestringcompare;
	#define EXT_opcuabytestringcompare  extern PFOPCUABYTESTRINGCOMPARE_IEC pfopcuabytestringcompare;
	#define GET_opcuabytestringcompare(fl)  s_pfCMGetAPI2( "opcuabytestringcompare", (RTS_VOID_FCTPTR *)&pfopcuabytestringcompare, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x7FCDF593, 0x03051000)
	#define CAL_opcuabytestringcompare  pfopcuabytestringcompare
	#define CHK_opcuabytestringcompare  (pfopcuabytestringcompare != NULL)
	#define EXP_opcuabytestringcompare   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabytestringcompare", (RTS_UINTPTR)opcuabytestringcompare, 1, 0x7FCDF593, 0x03051000) 
#endif


/**
 * <description>opcuabytestringconcatenate</description>
 */
typedef struct tagopcuabytestringconcatenate_struct
{
	OpcUa_ByteString *source;			/* VAR_INPUT */	
	OpcUa_ByteString *destination;		/* VAR_INPUT */	
	RTS_IEC_DINT len;					/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaByteStringConcatenate;	/* VAR_OUTPUT */	
} opcuabytestringconcatenate_struct;

void CDECL CDECL_EXT opcuabytestringconcatenate(opcuabytestringconcatenate_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUABYTESTRINGCONCATENATE_IEC) (opcuabytestringconcatenate_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUABYTESTRINGCONCATENATE_NOTIMPLEMENTED)
	#define USE_opcuabytestringconcatenate
	#define EXT_opcuabytestringconcatenate
	#define GET_opcuabytestringconcatenate(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuabytestringconcatenate(p0) 
	#define CHK_opcuabytestringconcatenate  FALSE
	#define EXP_opcuabytestringconcatenate  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuabytestringconcatenate
	#define EXT_opcuabytestringconcatenate
	#define GET_opcuabytestringconcatenate(fl)  CAL_CMGETAPI( "opcuabytestringconcatenate" ) 
	#define CAL_opcuabytestringconcatenate  opcuabytestringconcatenate
	#define CHK_opcuabytestringconcatenate  TRUE
	#define EXP_opcuabytestringconcatenate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabytestringconcatenate", (RTS_UINTPTR)opcuabytestringconcatenate, 1, 0x8D27CB64, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuabytestringconcatenate
	#define EXT_opcuabytestringconcatenate
	#define GET_opcuabytestringconcatenate(fl)  CAL_CMGETAPI( "opcuabytestringconcatenate" ) 
	#define CAL_opcuabytestringconcatenate  opcuabytestringconcatenate
	#define CHK_opcuabytestringconcatenate  TRUE
	#define EXP_opcuabytestringconcatenate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabytestringconcatenate", (RTS_UINTPTR)opcuabytestringconcatenate, 1, 0x8D27CB64, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuabytestringconcatenate
	#define EXT_CmpOPCUAStack_Implementationopcuabytestringconcatenate
	#define GET_CmpOPCUAStack_Implementationopcuabytestringconcatenate  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuabytestringconcatenate  opcuabytestringconcatenate
	#define CHK_CmpOPCUAStack_Implementationopcuabytestringconcatenate  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuabytestringconcatenate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabytestringconcatenate", (RTS_UINTPTR)opcuabytestringconcatenate, 1, 0x8D27CB64, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuabytestringconcatenate
	#define EXT_opcuabytestringconcatenate
	#define GET_opcuabytestringconcatenate(fl)  CAL_CMGETAPI( "opcuabytestringconcatenate" ) 
	#define CAL_opcuabytestringconcatenate  opcuabytestringconcatenate
	#define CHK_opcuabytestringconcatenate  TRUE
	#define EXP_opcuabytestringconcatenate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabytestringconcatenate", (RTS_UINTPTR)opcuabytestringconcatenate, 1, 0x8D27CB64, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuabytestringconcatenate  PFOPCUABYTESTRINGCONCATENATE_IEC pfopcuabytestringconcatenate;
	#define EXT_opcuabytestringconcatenate  extern PFOPCUABYTESTRINGCONCATENATE_IEC pfopcuabytestringconcatenate;
	#define GET_opcuabytestringconcatenate(fl)  s_pfCMGetAPI2( "opcuabytestringconcatenate", (RTS_VOID_FCTPTR *)&pfopcuabytestringconcatenate, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x8D27CB64, 0x03051000)
	#define CAL_opcuabytestringconcatenate  pfopcuabytestringconcatenate
	#define CHK_opcuabytestringconcatenate  (pfopcuabytestringconcatenate != NULL)
	#define EXP_opcuabytestringconcatenate   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabytestringconcatenate", (RTS_UINTPTR)opcuabytestringconcatenate, 1, 0x8D27CB64, 0x03051000) 
#endif


/**
 * <description>opcuabytestringcopyto</description>
 */
typedef struct tagopcuabytestringcopyto_struct
{
	OpcUa_ByteString *source;			/* VAR_INPUT */	
	OpcUa_ByteString *destination;		/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaByteStringCopyTo;	/* VAR_OUTPUT */	
} opcuabytestringcopyto_struct;

void CDECL CDECL_EXT opcuabytestringcopyto(opcuabytestringcopyto_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUABYTESTRINGCOPYTO_IEC) (opcuabytestringcopyto_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUABYTESTRINGCOPYTO_NOTIMPLEMENTED)
	#define USE_opcuabytestringcopyto
	#define EXT_opcuabytestringcopyto
	#define GET_opcuabytestringcopyto(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuabytestringcopyto(p0) 
	#define CHK_opcuabytestringcopyto  FALSE
	#define EXP_opcuabytestringcopyto  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuabytestringcopyto
	#define EXT_opcuabytestringcopyto
	#define GET_opcuabytestringcopyto(fl)  CAL_CMGETAPI( "opcuabytestringcopyto" ) 
	#define CAL_opcuabytestringcopyto  opcuabytestringcopyto
	#define CHK_opcuabytestringcopyto  TRUE
	#define EXP_opcuabytestringcopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabytestringcopyto", (RTS_UINTPTR)opcuabytestringcopyto, 1, 0x09BC6CF9, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuabytestringcopyto
	#define EXT_opcuabytestringcopyto
	#define GET_opcuabytestringcopyto(fl)  CAL_CMGETAPI( "opcuabytestringcopyto" ) 
	#define CAL_opcuabytestringcopyto  opcuabytestringcopyto
	#define CHK_opcuabytestringcopyto  TRUE
	#define EXP_opcuabytestringcopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabytestringcopyto", (RTS_UINTPTR)opcuabytestringcopyto, 1, 0x09BC6CF9, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuabytestringcopyto
	#define EXT_CmpOPCUAStack_Implementationopcuabytestringcopyto
	#define GET_CmpOPCUAStack_Implementationopcuabytestringcopyto  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuabytestringcopyto  opcuabytestringcopyto
	#define CHK_CmpOPCUAStack_Implementationopcuabytestringcopyto  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuabytestringcopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabytestringcopyto", (RTS_UINTPTR)opcuabytestringcopyto, 1, 0x09BC6CF9, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuabytestringcopyto
	#define EXT_opcuabytestringcopyto
	#define GET_opcuabytestringcopyto(fl)  CAL_CMGETAPI( "opcuabytestringcopyto" ) 
	#define CAL_opcuabytestringcopyto  opcuabytestringcopyto
	#define CHK_opcuabytestringcopyto  TRUE
	#define EXP_opcuabytestringcopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabytestringcopyto", (RTS_UINTPTR)opcuabytestringcopyto, 1, 0x09BC6CF9, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuabytestringcopyto  PFOPCUABYTESTRINGCOPYTO_IEC pfopcuabytestringcopyto;
	#define EXT_opcuabytestringcopyto  extern PFOPCUABYTESTRINGCOPYTO_IEC pfopcuabytestringcopyto;
	#define GET_opcuabytestringcopyto(fl)  s_pfCMGetAPI2( "opcuabytestringcopyto", (RTS_VOID_FCTPTR *)&pfopcuabytestringcopyto, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x09BC6CF9, 0x03051000)
	#define CAL_opcuabytestringcopyto  pfopcuabytestringcopyto
	#define CHK_opcuabytestringcopyto  (pfopcuabytestringcopyto != NULL)
	#define EXP_opcuabytestringcopyto   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabytestringcopyto", (RTS_UINTPTR)opcuabytestringcopyto, 1, 0x09BC6CF9, 0x03051000) 
#endif


/**
 * <description>opcuabytestringinitialize</description>
 */
typedef struct tagopcuabytestringinitialize_struct
{
	OpcUa_ByteString *value;			/* VAR_INPUT */	
} opcuabytestringinitialize_struct;

void CDECL CDECL_EXT opcuabytestringinitialize(opcuabytestringinitialize_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUABYTESTRINGINITIALIZE_IEC) (opcuabytestringinitialize_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUABYTESTRINGINITIALIZE_NOTIMPLEMENTED)
	#define USE_opcuabytestringinitialize
	#define EXT_opcuabytestringinitialize
	#define GET_opcuabytestringinitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuabytestringinitialize(p0) 
	#define CHK_opcuabytestringinitialize  FALSE
	#define EXP_opcuabytestringinitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuabytestringinitialize
	#define EXT_opcuabytestringinitialize
	#define GET_opcuabytestringinitialize(fl)  CAL_CMGETAPI( "opcuabytestringinitialize" ) 
	#define CAL_opcuabytestringinitialize  opcuabytestringinitialize
	#define CHK_opcuabytestringinitialize  TRUE
	#define EXP_opcuabytestringinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabytestringinitialize", (RTS_UINTPTR)opcuabytestringinitialize, 1, 0xF04115F1, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuabytestringinitialize
	#define EXT_opcuabytestringinitialize
	#define GET_opcuabytestringinitialize(fl)  CAL_CMGETAPI( "opcuabytestringinitialize" ) 
	#define CAL_opcuabytestringinitialize  opcuabytestringinitialize
	#define CHK_opcuabytestringinitialize  TRUE
	#define EXP_opcuabytestringinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabytestringinitialize", (RTS_UINTPTR)opcuabytestringinitialize, 1, 0xF04115F1, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuabytestringinitialize
	#define EXT_CmpOPCUAStack_Implementationopcuabytestringinitialize
	#define GET_CmpOPCUAStack_Implementationopcuabytestringinitialize  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuabytestringinitialize  opcuabytestringinitialize
	#define CHK_CmpOPCUAStack_Implementationopcuabytestringinitialize  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuabytestringinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabytestringinitialize", (RTS_UINTPTR)opcuabytestringinitialize, 1, 0xF04115F1, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuabytestringinitialize
	#define EXT_opcuabytestringinitialize
	#define GET_opcuabytestringinitialize(fl)  CAL_CMGETAPI( "opcuabytestringinitialize" ) 
	#define CAL_opcuabytestringinitialize  opcuabytestringinitialize
	#define CHK_opcuabytestringinitialize  TRUE
	#define EXP_opcuabytestringinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabytestringinitialize", (RTS_UINTPTR)opcuabytestringinitialize, 1, 0xF04115F1, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuabytestringinitialize  PFOPCUABYTESTRINGINITIALIZE_IEC pfopcuabytestringinitialize;
	#define EXT_opcuabytestringinitialize  extern PFOPCUABYTESTRINGINITIALIZE_IEC pfopcuabytestringinitialize;
	#define GET_opcuabytestringinitialize(fl)  s_pfCMGetAPI2( "opcuabytestringinitialize", (RTS_VOID_FCTPTR *)&pfopcuabytestringinitialize, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xF04115F1, 0x03051000)
	#define CAL_opcuabytestringinitialize  pfopcuabytestringinitialize
	#define CHK_opcuabytestringinitialize  (pfopcuabytestringinitialize != NULL)
	#define EXP_opcuabytestringinitialize   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuabytestringinitialize", (RTS_UINTPTR)opcuabytestringinitialize, 1, 0xF04115F1, 0x03051000) 
#endif


/**
 * <description>opcuadatavalueclear</description>
 */
typedef struct tagopcuadatavalueclear_struct
{
	OpcUa_DataValue *pValue;			/* VAR_INPUT */	
} opcuadatavalueclear_struct;

void CDECL CDECL_EXT opcuadatavalueclear(opcuadatavalueclear_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUADATAVALUECLEAR_IEC) (opcuadatavalueclear_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUADATAVALUECLEAR_NOTIMPLEMENTED)
	#define USE_opcuadatavalueclear
	#define EXT_opcuadatavalueclear
	#define GET_opcuadatavalueclear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuadatavalueclear(p0) 
	#define CHK_opcuadatavalueclear  FALSE
	#define EXP_opcuadatavalueclear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuadatavalueclear
	#define EXT_opcuadatavalueclear
	#define GET_opcuadatavalueclear(fl)  CAL_CMGETAPI( "opcuadatavalueclear" ) 
	#define CAL_opcuadatavalueclear  opcuadatavalueclear
	#define CHK_opcuadatavalueclear  TRUE
	#define EXP_opcuadatavalueclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuadatavalueclear", (RTS_UINTPTR)opcuadatavalueclear, 1, 0xBAC7D1A8, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuadatavalueclear
	#define EXT_opcuadatavalueclear
	#define GET_opcuadatavalueclear(fl)  CAL_CMGETAPI( "opcuadatavalueclear" ) 
	#define CAL_opcuadatavalueclear  opcuadatavalueclear
	#define CHK_opcuadatavalueclear  TRUE
	#define EXP_opcuadatavalueclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuadatavalueclear", (RTS_UINTPTR)opcuadatavalueclear, 1, 0xBAC7D1A8, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuadatavalueclear
	#define EXT_CmpOPCUAStack_Implementationopcuadatavalueclear
	#define GET_CmpOPCUAStack_Implementationopcuadatavalueclear  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuadatavalueclear  opcuadatavalueclear
	#define CHK_CmpOPCUAStack_Implementationopcuadatavalueclear  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuadatavalueclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuadatavalueclear", (RTS_UINTPTR)opcuadatavalueclear, 1, 0xBAC7D1A8, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuadatavalueclear
	#define EXT_opcuadatavalueclear
	#define GET_opcuadatavalueclear(fl)  CAL_CMGETAPI( "opcuadatavalueclear" ) 
	#define CAL_opcuadatavalueclear  opcuadatavalueclear
	#define CHK_opcuadatavalueclear  TRUE
	#define EXP_opcuadatavalueclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuadatavalueclear", (RTS_UINTPTR)opcuadatavalueclear, 1, 0xBAC7D1A8, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuadatavalueclear  PFOPCUADATAVALUECLEAR_IEC pfopcuadatavalueclear;
	#define EXT_opcuadatavalueclear  extern PFOPCUADATAVALUECLEAR_IEC pfopcuadatavalueclear;
	#define GET_opcuadatavalueclear(fl)  s_pfCMGetAPI2( "opcuadatavalueclear", (RTS_VOID_FCTPTR *)&pfopcuadatavalueclear, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xBAC7D1A8, 0x03051000)
	#define CAL_opcuadatavalueclear  pfopcuadatavalueclear
	#define CHK_opcuadatavalueclear  (pfopcuadatavalueclear != NULL)
	#define EXP_opcuadatavalueclear   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuadatavalueclear", (RTS_UINTPTR)opcuadatavalueclear, 1, 0xBAC7D1A8, 0x03051000) 
#endif


/**
 * <description>opcuadatavaluecompare</description>
 */
typedef struct tagopcuadatavaluecompare_struct
{
	OpcUa_DataValue *pValue1;			/* VAR_INPUT */	
	OpcUa_DataValue *pValue2;			/* VAR_INPUT */	
	RTS_IEC_DINT OpcUaDataValueCompare;	/* VAR_OUTPUT */	
} opcuadatavaluecompare_struct;

void CDECL CDECL_EXT opcuadatavaluecompare(opcuadatavaluecompare_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUADATAVALUECOMPARE_IEC) (opcuadatavaluecompare_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUADATAVALUECOMPARE_NOTIMPLEMENTED)
	#define USE_opcuadatavaluecompare
	#define EXT_opcuadatavaluecompare
	#define GET_opcuadatavaluecompare(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuadatavaluecompare(p0) 
	#define CHK_opcuadatavaluecompare  FALSE
	#define EXP_opcuadatavaluecompare  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuadatavaluecompare
	#define EXT_opcuadatavaluecompare
	#define GET_opcuadatavaluecompare(fl)  CAL_CMGETAPI( "opcuadatavaluecompare" ) 
	#define CAL_opcuadatavaluecompare  opcuadatavaluecompare
	#define CHK_opcuadatavaluecompare  TRUE
	#define EXP_opcuadatavaluecompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuadatavaluecompare", (RTS_UINTPTR)opcuadatavaluecompare, 1, 0xF578EE57, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuadatavaluecompare
	#define EXT_opcuadatavaluecompare
	#define GET_opcuadatavaluecompare(fl)  CAL_CMGETAPI( "opcuadatavaluecompare" ) 
	#define CAL_opcuadatavaluecompare  opcuadatavaluecompare
	#define CHK_opcuadatavaluecompare  TRUE
	#define EXP_opcuadatavaluecompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuadatavaluecompare", (RTS_UINTPTR)opcuadatavaluecompare, 1, 0xF578EE57, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuadatavaluecompare
	#define EXT_CmpOPCUAStack_Implementationopcuadatavaluecompare
	#define GET_CmpOPCUAStack_Implementationopcuadatavaluecompare  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuadatavaluecompare  opcuadatavaluecompare
	#define CHK_CmpOPCUAStack_Implementationopcuadatavaluecompare  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuadatavaluecompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuadatavaluecompare", (RTS_UINTPTR)opcuadatavaluecompare, 1, 0xF578EE57, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuadatavaluecompare
	#define EXT_opcuadatavaluecompare
	#define GET_opcuadatavaluecompare(fl)  CAL_CMGETAPI( "opcuadatavaluecompare" ) 
	#define CAL_opcuadatavaluecompare  opcuadatavaluecompare
	#define CHK_opcuadatavaluecompare  TRUE
	#define EXP_opcuadatavaluecompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuadatavaluecompare", (RTS_UINTPTR)opcuadatavaluecompare, 1, 0xF578EE57, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuadatavaluecompare  PFOPCUADATAVALUECOMPARE_IEC pfopcuadatavaluecompare;
	#define EXT_opcuadatavaluecompare  extern PFOPCUADATAVALUECOMPARE_IEC pfopcuadatavaluecompare;
	#define GET_opcuadatavaluecompare(fl)  s_pfCMGetAPI2( "opcuadatavaluecompare", (RTS_VOID_FCTPTR *)&pfopcuadatavaluecompare, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xF578EE57, 0x03051000)
	#define CAL_opcuadatavaluecompare  pfopcuadatavaluecompare
	#define CHK_opcuadatavaluecompare  (pfopcuadatavaluecompare != NULL)
	#define EXP_opcuadatavaluecompare   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuadatavaluecompare", (RTS_UINTPTR)opcuadatavaluecompare, 1, 0xF578EE57, 0x03051000) 
#endif


/**
 * <description>opcuadatavaluecopyto</description>
 */
typedef struct tagopcuadatavaluecopyto_struct
{
	OpcUa_DataValue *pSource;			/* VAR_INPUT */	
	OpcUa_DataValue *pDestination;		/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaDataValueCopyTo;	/* VAR_OUTPUT */	
} opcuadatavaluecopyto_struct;

void CDECL CDECL_EXT opcuadatavaluecopyto(opcuadatavaluecopyto_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUADATAVALUECOPYTO_IEC) (opcuadatavaluecopyto_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUADATAVALUECOPYTO_NOTIMPLEMENTED)
	#define USE_opcuadatavaluecopyto
	#define EXT_opcuadatavaluecopyto
	#define GET_opcuadatavaluecopyto(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuadatavaluecopyto(p0) 
	#define CHK_opcuadatavaluecopyto  FALSE
	#define EXP_opcuadatavaluecopyto  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuadatavaluecopyto
	#define EXT_opcuadatavaluecopyto
	#define GET_opcuadatavaluecopyto(fl)  CAL_CMGETAPI( "opcuadatavaluecopyto" ) 
	#define CAL_opcuadatavaluecopyto  opcuadatavaluecopyto
	#define CHK_opcuadatavaluecopyto  TRUE
	#define EXP_opcuadatavaluecopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuadatavaluecopyto", (RTS_UINTPTR)opcuadatavaluecopyto, 1, 0xEF1AC2F9, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuadatavaluecopyto
	#define EXT_opcuadatavaluecopyto
	#define GET_opcuadatavaluecopyto(fl)  CAL_CMGETAPI( "opcuadatavaluecopyto" ) 
	#define CAL_opcuadatavaluecopyto  opcuadatavaluecopyto
	#define CHK_opcuadatavaluecopyto  TRUE
	#define EXP_opcuadatavaluecopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuadatavaluecopyto", (RTS_UINTPTR)opcuadatavaluecopyto, 1, 0xEF1AC2F9, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuadatavaluecopyto
	#define EXT_CmpOPCUAStack_Implementationopcuadatavaluecopyto
	#define GET_CmpOPCUAStack_Implementationopcuadatavaluecopyto  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuadatavaluecopyto  opcuadatavaluecopyto
	#define CHK_CmpOPCUAStack_Implementationopcuadatavaluecopyto  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuadatavaluecopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuadatavaluecopyto", (RTS_UINTPTR)opcuadatavaluecopyto, 1, 0xEF1AC2F9, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuadatavaluecopyto
	#define EXT_opcuadatavaluecopyto
	#define GET_opcuadatavaluecopyto(fl)  CAL_CMGETAPI( "opcuadatavaluecopyto" ) 
	#define CAL_opcuadatavaluecopyto  opcuadatavaluecopyto
	#define CHK_opcuadatavaluecopyto  TRUE
	#define EXP_opcuadatavaluecopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuadatavaluecopyto", (RTS_UINTPTR)opcuadatavaluecopyto, 1, 0xEF1AC2F9, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuadatavaluecopyto  PFOPCUADATAVALUECOPYTO_IEC pfopcuadatavaluecopyto;
	#define EXT_opcuadatavaluecopyto  extern PFOPCUADATAVALUECOPYTO_IEC pfopcuadatavaluecopyto;
	#define GET_opcuadatavaluecopyto(fl)  s_pfCMGetAPI2( "opcuadatavaluecopyto", (RTS_VOID_FCTPTR *)&pfopcuadatavaluecopyto, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xEF1AC2F9, 0x03051000)
	#define CAL_opcuadatavaluecopyto  pfopcuadatavaluecopyto
	#define CHK_opcuadatavaluecopyto  (pfopcuadatavaluecopyto != NULL)
	#define EXP_opcuadatavaluecopyto   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuadatavaluecopyto", (RTS_UINTPTR)opcuadatavaluecopyto, 1, 0xEF1AC2F9, 0x03051000) 
#endif


/**
 * <description>opcuadatavalueinitialize</description>
 */
typedef struct tagopcuadatavalueinitialize_struct
{
	OpcUa_DataValue *pValue;			/* VAR_INPUT */	
} opcuadatavalueinitialize_struct;

void CDECL CDECL_EXT opcuadatavalueinitialize(opcuadatavalueinitialize_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUADATAVALUEINITIALIZE_IEC) (opcuadatavalueinitialize_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUADATAVALUEINITIALIZE_NOTIMPLEMENTED)
	#define USE_opcuadatavalueinitialize
	#define EXT_opcuadatavalueinitialize
	#define GET_opcuadatavalueinitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuadatavalueinitialize(p0) 
	#define CHK_opcuadatavalueinitialize  FALSE
	#define EXP_opcuadatavalueinitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuadatavalueinitialize
	#define EXT_opcuadatavalueinitialize
	#define GET_opcuadatavalueinitialize(fl)  CAL_CMGETAPI( "opcuadatavalueinitialize" ) 
	#define CAL_opcuadatavalueinitialize  opcuadatavalueinitialize
	#define CHK_opcuadatavalueinitialize  TRUE
	#define EXP_opcuadatavalueinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuadatavalueinitialize", (RTS_UINTPTR)opcuadatavalueinitialize, 1, 0x67F48E71, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuadatavalueinitialize
	#define EXT_opcuadatavalueinitialize
	#define GET_opcuadatavalueinitialize(fl)  CAL_CMGETAPI( "opcuadatavalueinitialize" ) 
	#define CAL_opcuadatavalueinitialize  opcuadatavalueinitialize
	#define CHK_opcuadatavalueinitialize  TRUE
	#define EXP_opcuadatavalueinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuadatavalueinitialize", (RTS_UINTPTR)opcuadatavalueinitialize, 1, 0x67F48E71, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuadatavalueinitialize
	#define EXT_CmpOPCUAStack_Implementationopcuadatavalueinitialize
	#define GET_CmpOPCUAStack_Implementationopcuadatavalueinitialize  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuadatavalueinitialize  opcuadatavalueinitialize
	#define CHK_CmpOPCUAStack_Implementationopcuadatavalueinitialize  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuadatavalueinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuadatavalueinitialize", (RTS_UINTPTR)opcuadatavalueinitialize, 1, 0x67F48E71, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuadatavalueinitialize
	#define EXT_opcuadatavalueinitialize
	#define GET_opcuadatavalueinitialize(fl)  CAL_CMGETAPI( "opcuadatavalueinitialize" ) 
	#define CAL_opcuadatavalueinitialize  opcuadatavalueinitialize
	#define CHK_opcuadatavalueinitialize  TRUE
	#define EXP_opcuadatavalueinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuadatavalueinitialize", (RTS_UINTPTR)opcuadatavalueinitialize, 1, 0x67F48E71, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuadatavalueinitialize  PFOPCUADATAVALUEINITIALIZE_IEC pfopcuadatavalueinitialize;
	#define EXT_opcuadatavalueinitialize  extern PFOPCUADATAVALUEINITIALIZE_IEC pfopcuadatavalueinitialize;
	#define GET_opcuadatavalueinitialize(fl)  s_pfCMGetAPI2( "opcuadatavalueinitialize", (RTS_VOID_FCTPTR *)&pfopcuadatavalueinitialize, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x67F48E71, 0x03051000)
	#define CAL_opcuadatavalueinitialize  pfopcuadatavalueinitialize
	#define CHK_opcuadatavalueinitialize  (pfopcuadatavalueinitialize != NULL)
	#define EXP_opcuadatavalueinitialize   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuadatavalueinitialize", (RTS_UINTPTR)opcuadatavalueinitialize, 1, 0x67F48E71, 0x03051000) 
#endif


/**
 * <description>opcuadatetimeutcnow</description>
 */
typedef struct tagopcuadatetimeutcnow_struct
{
	RTS_IEC_LINT OpcUaDateTimeUtcNow;	/* VAR_OUTPUT */	
} opcuadatetimeutcnow_struct;

void CDECL CDECL_EXT opcuadatetimeutcnow(opcuadatetimeutcnow_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUADATETIMEUTCNOW_IEC) (opcuadatetimeutcnow_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUADATETIMEUTCNOW_NOTIMPLEMENTED)
	#define USE_opcuadatetimeutcnow
	#define EXT_opcuadatetimeutcnow
	#define GET_opcuadatetimeutcnow(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuadatetimeutcnow(p0) 
	#define CHK_opcuadatetimeutcnow  FALSE
	#define EXP_opcuadatetimeutcnow  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuadatetimeutcnow
	#define EXT_opcuadatetimeutcnow
	#define GET_opcuadatetimeutcnow(fl)  CAL_CMGETAPI( "opcuadatetimeutcnow" ) 
	#define CAL_opcuadatetimeutcnow  opcuadatetimeutcnow
	#define CHK_opcuadatetimeutcnow  TRUE
	#define EXP_opcuadatetimeutcnow  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuadatetimeutcnow", (RTS_UINTPTR)opcuadatetimeutcnow, 1, 0x68CBAE05, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuadatetimeutcnow
	#define EXT_opcuadatetimeutcnow
	#define GET_opcuadatetimeutcnow(fl)  CAL_CMGETAPI( "opcuadatetimeutcnow" ) 
	#define CAL_opcuadatetimeutcnow  opcuadatetimeutcnow
	#define CHK_opcuadatetimeutcnow  TRUE
	#define EXP_opcuadatetimeutcnow  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuadatetimeutcnow", (RTS_UINTPTR)opcuadatetimeutcnow, 1, 0x68CBAE05, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuadatetimeutcnow
	#define EXT_CmpOPCUAStack_Implementationopcuadatetimeutcnow
	#define GET_CmpOPCUAStack_Implementationopcuadatetimeutcnow  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuadatetimeutcnow  opcuadatetimeutcnow
	#define CHK_CmpOPCUAStack_Implementationopcuadatetimeutcnow  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuadatetimeutcnow  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuadatetimeutcnow", (RTS_UINTPTR)opcuadatetimeutcnow, 1, 0x68CBAE05, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuadatetimeutcnow
	#define EXT_opcuadatetimeutcnow
	#define GET_opcuadatetimeutcnow(fl)  CAL_CMGETAPI( "opcuadatetimeutcnow" ) 
	#define CAL_opcuadatetimeutcnow  opcuadatetimeutcnow
	#define CHK_opcuadatetimeutcnow  TRUE
	#define EXP_opcuadatetimeutcnow  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuadatetimeutcnow", (RTS_UINTPTR)opcuadatetimeutcnow, 1, 0x68CBAE05, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuadatetimeutcnow  PFOPCUADATETIMEUTCNOW_IEC pfopcuadatetimeutcnow;
	#define EXT_opcuadatetimeutcnow  extern PFOPCUADATETIMEUTCNOW_IEC pfopcuadatetimeutcnow;
	#define GET_opcuadatetimeutcnow(fl)  s_pfCMGetAPI2( "opcuadatetimeutcnow", (RTS_VOID_FCTPTR *)&pfopcuadatetimeutcnow, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x68CBAE05, 0x03051000)
	#define CAL_opcuadatetimeutcnow  pfopcuadatetimeutcnow
	#define CHK_opcuadatetimeutcnow  (pfopcuadatetimeutcnow != NULL)
	#define EXP_opcuadatetimeutcnow   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuadatetimeutcnow", (RTS_UINTPTR)opcuadatetimeutcnow, 1, 0x68CBAE05, 0x03051000) 
#endif


/**
 * <description>opcuaendpointdescriptionclear</description>
 */
typedef struct tagopcuaendpointdescriptionclear_struct
{
	OpcUa_EndpointDescription *pValue;	/* VAR_INPUT */	
} opcuaendpointdescriptionclear_struct;

void CDECL CDECL_EXT opcuaendpointdescriptionclear(opcuaendpointdescriptionclear_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAENDPOINTDESCRIPTIONCLEAR_IEC) (opcuaendpointdescriptionclear_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAENDPOINTDESCRIPTIONCLEAR_NOTIMPLEMENTED)
	#define USE_opcuaendpointdescriptionclear
	#define EXT_opcuaendpointdescriptionclear
	#define GET_opcuaendpointdescriptionclear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaendpointdescriptionclear(p0) 
	#define CHK_opcuaendpointdescriptionclear  FALSE
	#define EXP_opcuaendpointdescriptionclear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaendpointdescriptionclear
	#define EXT_opcuaendpointdescriptionclear
	#define GET_opcuaendpointdescriptionclear(fl)  CAL_CMGETAPI( "opcuaendpointdescriptionclear" ) 
	#define CAL_opcuaendpointdescriptionclear  opcuaendpointdescriptionclear
	#define CHK_opcuaendpointdescriptionclear  TRUE
	#define EXP_opcuaendpointdescriptionclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaendpointdescriptionclear", (RTS_UINTPTR)opcuaendpointdescriptionclear, 1, 0x7BC3E11A, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaendpointdescriptionclear
	#define EXT_opcuaendpointdescriptionclear
	#define GET_opcuaendpointdescriptionclear(fl)  CAL_CMGETAPI( "opcuaendpointdescriptionclear" ) 
	#define CAL_opcuaendpointdescriptionclear  opcuaendpointdescriptionclear
	#define CHK_opcuaendpointdescriptionclear  TRUE
	#define EXP_opcuaendpointdescriptionclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaendpointdescriptionclear", (RTS_UINTPTR)opcuaendpointdescriptionclear, 1, 0x7BC3E11A, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuaendpointdescriptionclear
	#define EXT_CmpOPCUAStack_Implementationopcuaendpointdescriptionclear
	#define GET_CmpOPCUAStack_Implementationopcuaendpointdescriptionclear  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuaendpointdescriptionclear  opcuaendpointdescriptionclear
	#define CHK_CmpOPCUAStack_Implementationopcuaendpointdescriptionclear  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuaendpointdescriptionclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaendpointdescriptionclear", (RTS_UINTPTR)opcuaendpointdescriptionclear, 1, 0x7BC3E11A, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaendpointdescriptionclear
	#define EXT_opcuaendpointdescriptionclear
	#define GET_opcuaendpointdescriptionclear(fl)  CAL_CMGETAPI( "opcuaendpointdescriptionclear" ) 
	#define CAL_opcuaendpointdescriptionclear  opcuaendpointdescriptionclear
	#define CHK_opcuaendpointdescriptionclear  TRUE
	#define EXP_opcuaendpointdescriptionclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaendpointdescriptionclear", (RTS_UINTPTR)opcuaendpointdescriptionclear, 1, 0x7BC3E11A, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaendpointdescriptionclear  PFOPCUAENDPOINTDESCRIPTIONCLEAR_IEC pfopcuaendpointdescriptionclear;
	#define EXT_opcuaendpointdescriptionclear  extern PFOPCUAENDPOINTDESCRIPTIONCLEAR_IEC pfopcuaendpointdescriptionclear;
	#define GET_opcuaendpointdescriptionclear(fl)  s_pfCMGetAPI2( "opcuaendpointdescriptionclear", (RTS_VOID_FCTPTR *)&pfopcuaendpointdescriptionclear, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x7BC3E11A, 0x03051000)
	#define CAL_opcuaendpointdescriptionclear  pfopcuaendpointdescriptionclear
	#define CHK_opcuaendpointdescriptionclear  (pfopcuaendpointdescriptionclear != NULL)
	#define EXP_opcuaendpointdescriptionclear   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaendpointdescriptionclear", (RTS_UINTPTR)opcuaendpointdescriptionclear, 1, 0x7BC3E11A, 0x03051000) 
#endif


/**
 * <description>opcuaendpointdescriptioninitialize</description>
 */
typedef struct tagopcuaendpointdescriptioninitialize_struct
{
	OpcUa_EndpointDescription *pValue;	/* VAR_INPUT */	
} opcuaendpointdescriptioninitialize_struct;

void CDECL CDECL_EXT opcuaendpointdescriptioninitialize(opcuaendpointdescriptioninitialize_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAENDPOINTDESCRIPTIONINITIALIZE_IEC) (opcuaendpointdescriptioninitialize_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAENDPOINTDESCRIPTIONINITIALIZE_NOTIMPLEMENTED)
	#define USE_opcuaendpointdescriptioninitialize
	#define EXT_opcuaendpointdescriptioninitialize
	#define GET_opcuaendpointdescriptioninitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaendpointdescriptioninitialize(p0) 
	#define CHK_opcuaendpointdescriptioninitialize  FALSE
	#define EXP_opcuaendpointdescriptioninitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaendpointdescriptioninitialize
	#define EXT_opcuaendpointdescriptioninitialize
	#define GET_opcuaendpointdescriptioninitialize(fl)  CAL_CMGETAPI( "opcuaendpointdescriptioninitialize" ) 
	#define CAL_opcuaendpointdescriptioninitialize  opcuaendpointdescriptioninitialize
	#define CHK_opcuaendpointdescriptioninitialize  TRUE
	#define EXP_opcuaendpointdescriptioninitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaendpointdescriptioninitialize", (RTS_UINTPTR)opcuaendpointdescriptioninitialize, 1, 0x02E855C1, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaendpointdescriptioninitialize
	#define EXT_opcuaendpointdescriptioninitialize
	#define GET_opcuaendpointdescriptioninitialize(fl)  CAL_CMGETAPI( "opcuaendpointdescriptioninitialize" ) 
	#define CAL_opcuaendpointdescriptioninitialize  opcuaendpointdescriptioninitialize
	#define CHK_opcuaendpointdescriptioninitialize  TRUE
	#define EXP_opcuaendpointdescriptioninitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaendpointdescriptioninitialize", (RTS_UINTPTR)opcuaendpointdescriptioninitialize, 1, 0x02E855C1, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuaendpointdescriptioninitialize
	#define EXT_CmpOPCUAStack_Implementationopcuaendpointdescriptioninitialize
	#define GET_CmpOPCUAStack_Implementationopcuaendpointdescriptioninitialize  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuaendpointdescriptioninitialize  opcuaendpointdescriptioninitialize
	#define CHK_CmpOPCUAStack_Implementationopcuaendpointdescriptioninitialize  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuaendpointdescriptioninitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaendpointdescriptioninitialize", (RTS_UINTPTR)opcuaendpointdescriptioninitialize, 1, 0x02E855C1, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaendpointdescriptioninitialize
	#define EXT_opcuaendpointdescriptioninitialize
	#define GET_opcuaendpointdescriptioninitialize(fl)  CAL_CMGETAPI( "opcuaendpointdescriptioninitialize" ) 
	#define CAL_opcuaendpointdescriptioninitialize  opcuaendpointdescriptioninitialize
	#define CHK_opcuaendpointdescriptioninitialize  TRUE
	#define EXP_opcuaendpointdescriptioninitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaendpointdescriptioninitialize", (RTS_UINTPTR)opcuaendpointdescriptioninitialize, 1, 0x02E855C1, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaendpointdescriptioninitialize  PFOPCUAENDPOINTDESCRIPTIONINITIALIZE_IEC pfopcuaendpointdescriptioninitialize;
	#define EXT_opcuaendpointdescriptioninitialize  extern PFOPCUAENDPOINTDESCRIPTIONINITIALIZE_IEC pfopcuaendpointdescriptioninitialize;
	#define GET_opcuaendpointdescriptioninitialize(fl)  s_pfCMGetAPI2( "opcuaendpointdescriptioninitialize", (RTS_VOID_FCTPTR *)&pfopcuaendpointdescriptioninitialize, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x02E855C1, 0x03051000)
	#define CAL_opcuaendpointdescriptioninitialize  pfopcuaendpointdescriptioninitialize
	#define CHK_opcuaendpointdescriptioninitialize  (pfopcuaendpointdescriptioninitialize != NULL)
	#define EXP_opcuaendpointdescriptioninitialize   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaendpointdescriptioninitialize", (RTS_UINTPTR)opcuaendpointdescriptioninitialize, 1, 0x02E855C1, 0x03051000) 
#endif


/**
 * <description>opcuaeventfieldlistclear</description>
 */
typedef struct tagopcuaeventfieldlistclear_struct
{
	OpcUa_EventFieldList *pValue;		/* VAR_INPUT */	
} opcuaeventfieldlistclear_struct;

void CDECL CDECL_EXT opcuaeventfieldlistclear(opcuaeventfieldlistclear_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAEVENTFIELDLISTCLEAR_IEC) (opcuaeventfieldlistclear_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAEVENTFIELDLISTCLEAR_NOTIMPLEMENTED)
	#define USE_opcuaeventfieldlistclear
	#define EXT_opcuaeventfieldlistclear
	#define GET_opcuaeventfieldlistclear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaeventfieldlistclear(p0) 
	#define CHK_opcuaeventfieldlistclear  FALSE
	#define EXP_opcuaeventfieldlistclear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaeventfieldlistclear
	#define EXT_opcuaeventfieldlistclear
	#define GET_opcuaeventfieldlistclear(fl)  CAL_CMGETAPI( "opcuaeventfieldlistclear" ) 
	#define CAL_opcuaeventfieldlistclear  opcuaeventfieldlistclear
	#define CHK_opcuaeventfieldlistclear  TRUE
	#define EXP_opcuaeventfieldlistclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaeventfieldlistclear", (RTS_UINTPTR)opcuaeventfieldlistclear, 1, 0xEC6DF17F, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaeventfieldlistclear
	#define EXT_opcuaeventfieldlistclear
	#define GET_opcuaeventfieldlistclear(fl)  CAL_CMGETAPI( "opcuaeventfieldlistclear" ) 
	#define CAL_opcuaeventfieldlistclear  opcuaeventfieldlistclear
	#define CHK_opcuaeventfieldlistclear  TRUE
	#define EXP_opcuaeventfieldlistclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaeventfieldlistclear", (RTS_UINTPTR)opcuaeventfieldlistclear, 1, 0xEC6DF17F, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuaeventfieldlistclear
	#define EXT_CmpOPCUAStack_Implementationopcuaeventfieldlistclear
	#define GET_CmpOPCUAStack_Implementationopcuaeventfieldlistclear  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuaeventfieldlistclear  opcuaeventfieldlistclear
	#define CHK_CmpOPCUAStack_Implementationopcuaeventfieldlistclear  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuaeventfieldlistclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaeventfieldlistclear", (RTS_UINTPTR)opcuaeventfieldlistclear, 1, 0xEC6DF17F, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaeventfieldlistclear
	#define EXT_opcuaeventfieldlistclear
	#define GET_opcuaeventfieldlistclear(fl)  CAL_CMGETAPI( "opcuaeventfieldlistclear" ) 
	#define CAL_opcuaeventfieldlistclear  opcuaeventfieldlistclear
	#define CHK_opcuaeventfieldlistclear  TRUE
	#define EXP_opcuaeventfieldlistclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaeventfieldlistclear", (RTS_UINTPTR)opcuaeventfieldlistclear, 1, 0xEC6DF17F, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaeventfieldlistclear  PFOPCUAEVENTFIELDLISTCLEAR_IEC pfopcuaeventfieldlistclear;
	#define EXT_opcuaeventfieldlistclear  extern PFOPCUAEVENTFIELDLISTCLEAR_IEC pfopcuaeventfieldlistclear;
	#define GET_opcuaeventfieldlistclear(fl)  s_pfCMGetAPI2( "opcuaeventfieldlistclear", (RTS_VOID_FCTPTR *)&pfopcuaeventfieldlistclear, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xEC6DF17F, 0x03051000)
	#define CAL_opcuaeventfieldlistclear  pfopcuaeventfieldlistclear
	#define CHK_opcuaeventfieldlistclear  (pfopcuaeventfieldlistclear != NULL)
	#define EXP_opcuaeventfieldlistclear   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaeventfieldlistclear", (RTS_UINTPTR)opcuaeventfieldlistclear, 1, 0xEC6DF17F, 0x03051000) 
#endif


/**
 * <description>opcuaeventfieldlistinitialize</description>
 */
typedef struct tagopcuaeventfieldlistinitialize_struct
{
	OpcUa_EventFieldList *pValue;		/* VAR_INPUT */	
} opcuaeventfieldlistinitialize_struct;

void CDECL CDECL_EXT opcuaeventfieldlistinitialize(opcuaeventfieldlistinitialize_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAEVENTFIELDLISTINITIALIZE_IEC) (opcuaeventfieldlistinitialize_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAEVENTFIELDLISTINITIALIZE_NOTIMPLEMENTED)
	#define USE_opcuaeventfieldlistinitialize
	#define EXT_opcuaeventfieldlistinitialize
	#define GET_opcuaeventfieldlistinitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaeventfieldlistinitialize(p0) 
	#define CHK_opcuaeventfieldlistinitialize  FALSE
	#define EXP_opcuaeventfieldlistinitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaeventfieldlistinitialize
	#define EXT_opcuaeventfieldlistinitialize
	#define GET_opcuaeventfieldlistinitialize(fl)  CAL_CMGETAPI( "opcuaeventfieldlistinitialize" ) 
	#define CAL_opcuaeventfieldlistinitialize  opcuaeventfieldlistinitialize
	#define CHK_opcuaeventfieldlistinitialize  TRUE
	#define EXP_opcuaeventfieldlistinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaeventfieldlistinitialize", (RTS_UINTPTR)opcuaeventfieldlistinitialize, 1, 0x55E16C82, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaeventfieldlistinitialize
	#define EXT_opcuaeventfieldlistinitialize
	#define GET_opcuaeventfieldlistinitialize(fl)  CAL_CMGETAPI( "opcuaeventfieldlistinitialize" ) 
	#define CAL_opcuaeventfieldlistinitialize  opcuaeventfieldlistinitialize
	#define CHK_opcuaeventfieldlistinitialize  TRUE
	#define EXP_opcuaeventfieldlistinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaeventfieldlistinitialize", (RTS_UINTPTR)opcuaeventfieldlistinitialize, 1, 0x55E16C82, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuaeventfieldlistinitialize
	#define EXT_CmpOPCUAStack_Implementationopcuaeventfieldlistinitialize
	#define GET_CmpOPCUAStack_Implementationopcuaeventfieldlistinitialize  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuaeventfieldlistinitialize  opcuaeventfieldlistinitialize
	#define CHK_CmpOPCUAStack_Implementationopcuaeventfieldlistinitialize  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuaeventfieldlistinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaeventfieldlistinitialize", (RTS_UINTPTR)opcuaeventfieldlistinitialize, 1, 0x55E16C82, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaeventfieldlistinitialize
	#define EXT_opcuaeventfieldlistinitialize
	#define GET_opcuaeventfieldlistinitialize(fl)  CAL_CMGETAPI( "opcuaeventfieldlistinitialize" ) 
	#define CAL_opcuaeventfieldlistinitialize  opcuaeventfieldlistinitialize
	#define CHK_opcuaeventfieldlistinitialize  TRUE
	#define EXP_opcuaeventfieldlistinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaeventfieldlistinitialize", (RTS_UINTPTR)opcuaeventfieldlistinitialize, 1, 0x55E16C82, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaeventfieldlistinitialize  PFOPCUAEVENTFIELDLISTINITIALIZE_IEC pfopcuaeventfieldlistinitialize;
	#define EXT_opcuaeventfieldlistinitialize  extern PFOPCUAEVENTFIELDLISTINITIALIZE_IEC pfopcuaeventfieldlistinitialize;
	#define GET_opcuaeventfieldlistinitialize(fl)  s_pfCMGetAPI2( "opcuaeventfieldlistinitialize", (RTS_VOID_FCTPTR *)&pfopcuaeventfieldlistinitialize, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x55E16C82, 0x03051000)
	#define CAL_opcuaeventfieldlistinitialize  pfopcuaeventfieldlistinitialize
	#define CHK_opcuaeventfieldlistinitialize  (pfopcuaeventfieldlistinitialize != NULL)
	#define EXP_opcuaeventfieldlistinitialize   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaeventfieldlistinitialize", (RTS_UINTPTR)opcuaeventfieldlistinitialize, 1, 0x55E16C82, 0x03051000) 
#endif


/**
 * <description>opcuaeventnotificationlistclear</description>
 */
typedef struct tagopcuaeventnotificationlistclear_struct
{
	OpcUa_EventNotificationList *pValue;	/* VAR_INPUT */	
} opcuaeventnotificationlistclear_struct;

void CDECL CDECL_EXT opcuaeventnotificationlistclear(opcuaeventnotificationlistclear_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAEVENTNOTIFICATIONLISTCLEAR_IEC) (opcuaeventnotificationlistclear_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAEVENTNOTIFICATIONLISTCLEAR_NOTIMPLEMENTED)
	#define USE_opcuaeventnotificationlistclear
	#define EXT_opcuaeventnotificationlistclear
	#define GET_opcuaeventnotificationlistclear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaeventnotificationlistclear(p0) 
	#define CHK_opcuaeventnotificationlistclear  FALSE
	#define EXP_opcuaeventnotificationlistclear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaeventnotificationlistclear
	#define EXT_opcuaeventnotificationlistclear
	#define GET_opcuaeventnotificationlistclear(fl)  CAL_CMGETAPI( "opcuaeventnotificationlistclear" ) 
	#define CAL_opcuaeventnotificationlistclear  opcuaeventnotificationlistclear
	#define CHK_opcuaeventnotificationlistclear  TRUE
	#define EXP_opcuaeventnotificationlistclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaeventnotificationlistclear", (RTS_UINTPTR)opcuaeventnotificationlistclear, 1, 0x11D76705, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaeventnotificationlistclear
	#define EXT_opcuaeventnotificationlistclear
	#define GET_opcuaeventnotificationlistclear(fl)  CAL_CMGETAPI( "opcuaeventnotificationlistclear" ) 
	#define CAL_opcuaeventnotificationlistclear  opcuaeventnotificationlistclear
	#define CHK_opcuaeventnotificationlistclear  TRUE
	#define EXP_opcuaeventnotificationlistclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaeventnotificationlistclear", (RTS_UINTPTR)opcuaeventnotificationlistclear, 1, 0x11D76705, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuaeventnotificationlistclear
	#define EXT_CmpOPCUAStack_Implementationopcuaeventnotificationlistclear
	#define GET_CmpOPCUAStack_Implementationopcuaeventnotificationlistclear  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuaeventnotificationlistclear  opcuaeventnotificationlistclear
	#define CHK_CmpOPCUAStack_Implementationopcuaeventnotificationlistclear  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuaeventnotificationlistclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaeventnotificationlistclear", (RTS_UINTPTR)opcuaeventnotificationlistclear, 1, 0x11D76705, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaeventnotificationlistclear
	#define EXT_opcuaeventnotificationlistclear
	#define GET_opcuaeventnotificationlistclear(fl)  CAL_CMGETAPI( "opcuaeventnotificationlistclear" ) 
	#define CAL_opcuaeventnotificationlistclear  opcuaeventnotificationlistclear
	#define CHK_opcuaeventnotificationlistclear  TRUE
	#define EXP_opcuaeventnotificationlistclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaeventnotificationlistclear", (RTS_UINTPTR)opcuaeventnotificationlistclear, 1, 0x11D76705, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaeventnotificationlistclear  PFOPCUAEVENTNOTIFICATIONLISTCLEAR_IEC pfopcuaeventnotificationlistclear;
	#define EXT_opcuaeventnotificationlistclear  extern PFOPCUAEVENTNOTIFICATIONLISTCLEAR_IEC pfopcuaeventnotificationlistclear;
	#define GET_opcuaeventnotificationlistclear(fl)  s_pfCMGetAPI2( "opcuaeventnotificationlistclear", (RTS_VOID_FCTPTR *)&pfopcuaeventnotificationlistclear, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x11D76705, 0x03051000)
	#define CAL_opcuaeventnotificationlistclear  pfopcuaeventnotificationlistclear
	#define CHK_opcuaeventnotificationlistclear  (pfopcuaeventnotificationlistclear != NULL)
	#define EXP_opcuaeventnotificationlistclear   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaeventnotificationlistclear", (RTS_UINTPTR)opcuaeventnotificationlistclear, 1, 0x11D76705, 0x03051000) 
#endif


/**
 * <description>opcuaeventnotificationlistinitialize</description>
 */
typedef struct tagopcuaeventnotificationlistinitialize_struct
{
	OpcUa_EventNotificationList *pValue;	/* VAR_INPUT */	
} opcuaeventnotificationlistinitialize_struct;

void CDECL CDECL_EXT opcuaeventnotificationlistinitialize(opcuaeventnotificationlistinitialize_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAEVENTNOTIFICATIONLISTINITIALIZE_IEC) (opcuaeventnotificationlistinitialize_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAEVENTNOTIFICATIONLISTINITIALIZE_NOTIMPLEMENTED)
	#define USE_opcuaeventnotificationlistinitialize
	#define EXT_opcuaeventnotificationlistinitialize
	#define GET_opcuaeventnotificationlistinitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaeventnotificationlistinitialize(p0) 
	#define CHK_opcuaeventnotificationlistinitialize  FALSE
	#define EXP_opcuaeventnotificationlistinitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaeventnotificationlistinitialize
	#define EXT_opcuaeventnotificationlistinitialize
	#define GET_opcuaeventnotificationlistinitialize(fl)  CAL_CMGETAPI( "opcuaeventnotificationlistinitialize" ) 
	#define CAL_opcuaeventnotificationlistinitialize  opcuaeventnotificationlistinitialize
	#define CHK_opcuaeventnotificationlistinitialize  TRUE
	#define EXP_opcuaeventnotificationlistinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaeventnotificationlistinitialize", (RTS_UINTPTR)opcuaeventnotificationlistinitialize, 1, 0xFD48AECC, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaeventnotificationlistinitialize
	#define EXT_opcuaeventnotificationlistinitialize
	#define GET_opcuaeventnotificationlistinitialize(fl)  CAL_CMGETAPI( "opcuaeventnotificationlistinitialize" ) 
	#define CAL_opcuaeventnotificationlistinitialize  opcuaeventnotificationlistinitialize
	#define CHK_opcuaeventnotificationlistinitialize  TRUE
	#define EXP_opcuaeventnotificationlistinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaeventnotificationlistinitialize", (RTS_UINTPTR)opcuaeventnotificationlistinitialize, 1, 0xFD48AECC, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuaeventnotificationlistinitialize
	#define EXT_CmpOPCUAStack_Implementationopcuaeventnotificationlistinitialize
	#define GET_CmpOPCUAStack_Implementationopcuaeventnotificationlistinitialize  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuaeventnotificationlistinitialize  opcuaeventnotificationlistinitialize
	#define CHK_CmpOPCUAStack_Implementationopcuaeventnotificationlistinitialize  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuaeventnotificationlistinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaeventnotificationlistinitialize", (RTS_UINTPTR)opcuaeventnotificationlistinitialize, 1, 0xFD48AECC, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaeventnotificationlistinitialize
	#define EXT_opcuaeventnotificationlistinitialize
	#define GET_opcuaeventnotificationlistinitialize(fl)  CAL_CMGETAPI( "opcuaeventnotificationlistinitialize" ) 
	#define CAL_opcuaeventnotificationlistinitialize  opcuaeventnotificationlistinitialize
	#define CHK_opcuaeventnotificationlistinitialize  TRUE
	#define EXP_opcuaeventnotificationlistinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaeventnotificationlistinitialize", (RTS_UINTPTR)opcuaeventnotificationlistinitialize, 1, 0xFD48AECC, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaeventnotificationlistinitialize  PFOPCUAEVENTNOTIFICATIONLISTINITIALIZE_IEC pfopcuaeventnotificationlistinitialize;
	#define EXT_opcuaeventnotificationlistinitialize  extern PFOPCUAEVENTNOTIFICATIONLISTINITIALIZE_IEC pfopcuaeventnotificationlistinitialize;
	#define GET_opcuaeventnotificationlistinitialize(fl)  s_pfCMGetAPI2( "opcuaeventnotificationlistinitialize", (RTS_VOID_FCTPTR *)&pfopcuaeventnotificationlistinitialize, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xFD48AECC, 0x03051000)
	#define CAL_opcuaeventnotificationlistinitialize  pfopcuaeventnotificationlistinitialize
	#define CHK_opcuaeventnotificationlistinitialize  (pfopcuaeventnotificationlistinitialize != NULL)
	#define EXP_opcuaeventnotificationlistinitialize   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaeventnotificationlistinitialize", (RTS_UINTPTR)opcuaeventnotificationlistinitialize, 1, 0xFD48AECC, 0x03051000) 
#endif


/**
 * <description>opcuaexpandednodeidclear</description>
 */
typedef struct tagopcuaexpandednodeidclear_struct
{
	OpcUa_ExpandedNodeId *pValue;		/* VAR_INPUT */	
} opcuaexpandednodeidclear_struct;

void CDECL CDECL_EXT opcuaexpandednodeidclear(opcuaexpandednodeidclear_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAEXPANDEDNODEIDCLEAR_IEC) (opcuaexpandednodeidclear_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAEXPANDEDNODEIDCLEAR_NOTIMPLEMENTED)
	#define USE_opcuaexpandednodeidclear
	#define EXT_opcuaexpandednodeidclear
	#define GET_opcuaexpandednodeidclear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaexpandednodeidclear(p0) 
	#define CHK_opcuaexpandednodeidclear  FALSE
	#define EXP_opcuaexpandednodeidclear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaexpandednodeidclear
	#define EXT_opcuaexpandednodeidclear
	#define GET_opcuaexpandednodeidclear(fl)  CAL_CMGETAPI( "opcuaexpandednodeidclear" ) 
	#define CAL_opcuaexpandednodeidclear  opcuaexpandednodeidclear
	#define CHK_opcuaexpandednodeidclear  TRUE
	#define EXP_opcuaexpandednodeidclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaexpandednodeidclear", (RTS_UINTPTR)opcuaexpandednodeidclear, 1, 0xEC899BC1, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaexpandednodeidclear
	#define EXT_opcuaexpandednodeidclear
	#define GET_opcuaexpandednodeidclear(fl)  CAL_CMGETAPI( "opcuaexpandednodeidclear" ) 
	#define CAL_opcuaexpandednodeidclear  opcuaexpandednodeidclear
	#define CHK_opcuaexpandednodeidclear  TRUE
	#define EXP_opcuaexpandednodeidclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaexpandednodeidclear", (RTS_UINTPTR)opcuaexpandednodeidclear, 1, 0xEC899BC1, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuaexpandednodeidclear
	#define EXT_CmpOPCUAStack_Implementationopcuaexpandednodeidclear
	#define GET_CmpOPCUAStack_Implementationopcuaexpandednodeidclear  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuaexpandednodeidclear  opcuaexpandednodeidclear
	#define CHK_CmpOPCUAStack_Implementationopcuaexpandednodeidclear  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuaexpandednodeidclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaexpandednodeidclear", (RTS_UINTPTR)opcuaexpandednodeidclear, 1, 0xEC899BC1, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaexpandednodeidclear
	#define EXT_opcuaexpandednodeidclear
	#define GET_opcuaexpandednodeidclear(fl)  CAL_CMGETAPI( "opcuaexpandednodeidclear" ) 
	#define CAL_opcuaexpandednodeidclear  opcuaexpandednodeidclear
	#define CHK_opcuaexpandednodeidclear  TRUE
	#define EXP_opcuaexpandednodeidclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaexpandednodeidclear", (RTS_UINTPTR)opcuaexpandednodeidclear, 1, 0xEC899BC1, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaexpandednodeidclear  PFOPCUAEXPANDEDNODEIDCLEAR_IEC pfopcuaexpandednodeidclear;
	#define EXT_opcuaexpandednodeidclear  extern PFOPCUAEXPANDEDNODEIDCLEAR_IEC pfopcuaexpandednodeidclear;
	#define GET_opcuaexpandednodeidclear(fl)  s_pfCMGetAPI2( "opcuaexpandednodeidclear", (RTS_VOID_FCTPTR *)&pfopcuaexpandednodeidclear, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xEC899BC1, 0x03051000)
	#define CAL_opcuaexpandednodeidclear  pfopcuaexpandednodeidclear
	#define CHK_opcuaexpandednodeidclear  (pfopcuaexpandednodeidclear != NULL)
	#define EXP_opcuaexpandednodeidclear   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaexpandednodeidclear", (RTS_UINTPTR)opcuaexpandednodeidclear, 1, 0xEC899BC1, 0x03051000) 
#endif


/**
 * <description>opcuaexpandednodeidcompare</description>
 */
typedef struct tagopcuaexpandednodeidcompare_struct
{
	OpcUa_ExpandedNodeId *pValue1;		/* VAR_INPUT */	
	OpcUa_ExpandedNodeId *pValue2;		/* VAR_INPUT */	
	RTS_IEC_DINT OpcUaExpandedNodeIdCompare;	/* VAR_OUTPUT */	
} opcuaexpandednodeidcompare_struct;

void CDECL CDECL_EXT opcuaexpandednodeidcompare(opcuaexpandednodeidcompare_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAEXPANDEDNODEIDCOMPARE_IEC) (opcuaexpandednodeidcompare_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAEXPANDEDNODEIDCOMPARE_NOTIMPLEMENTED)
	#define USE_opcuaexpandednodeidcompare
	#define EXT_opcuaexpandednodeidcompare
	#define GET_opcuaexpandednodeidcompare(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaexpandednodeidcompare(p0) 
	#define CHK_opcuaexpandednodeidcompare  FALSE
	#define EXP_opcuaexpandednodeidcompare  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaexpandednodeidcompare
	#define EXT_opcuaexpandednodeidcompare
	#define GET_opcuaexpandednodeidcompare(fl)  CAL_CMGETAPI( "opcuaexpandednodeidcompare" ) 
	#define CAL_opcuaexpandednodeidcompare  opcuaexpandednodeidcompare
	#define CHK_opcuaexpandednodeidcompare  TRUE
	#define EXP_opcuaexpandednodeidcompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaexpandednodeidcompare", (RTS_UINTPTR)opcuaexpandednodeidcompare, 1, 0xDECACF50, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaexpandednodeidcompare
	#define EXT_opcuaexpandednodeidcompare
	#define GET_opcuaexpandednodeidcompare(fl)  CAL_CMGETAPI( "opcuaexpandednodeidcompare" ) 
	#define CAL_opcuaexpandednodeidcompare  opcuaexpandednodeidcompare
	#define CHK_opcuaexpandednodeidcompare  TRUE
	#define EXP_opcuaexpandednodeidcompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaexpandednodeidcompare", (RTS_UINTPTR)opcuaexpandednodeidcompare, 1, 0xDECACF50, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuaexpandednodeidcompare
	#define EXT_CmpOPCUAStack_Implementationopcuaexpandednodeidcompare
	#define GET_CmpOPCUAStack_Implementationopcuaexpandednodeidcompare  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuaexpandednodeidcompare  opcuaexpandednodeidcompare
	#define CHK_CmpOPCUAStack_Implementationopcuaexpandednodeidcompare  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuaexpandednodeidcompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaexpandednodeidcompare", (RTS_UINTPTR)opcuaexpandednodeidcompare, 1, 0xDECACF50, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaexpandednodeidcompare
	#define EXT_opcuaexpandednodeidcompare
	#define GET_opcuaexpandednodeidcompare(fl)  CAL_CMGETAPI( "opcuaexpandednodeidcompare" ) 
	#define CAL_opcuaexpandednodeidcompare  opcuaexpandednodeidcompare
	#define CHK_opcuaexpandednodeidcompare  TRUE
	#define EXP_opcuaexpandednodeidcompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaexpandednodeidcompare", (RTS_UINTPTR)opcuaexpandednodeidcompare, 1, 0xDECACF50, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaexpandednodeidcompare  PFOPCUAEXPANDEDNODEIDCOMPARE_IEC pfopcuaexpandednodeidcompare;
	#define EXT_opcuaexpandednodeidcompare  extern PFOPCUAEXPANDEDNODEIDCOMPARE_IEC pfopcuaexpandednodeidcompare;
	#define GET_opcuaexpandednodeidcompare(fl)  s_pfCMGetAPI2( "opcuaexpandednodeidcompare", (RTS_VOID_FCTPTR *)&pfopcuaexpandednodeidcompare, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xDECACF50, 0x03051000)
	#define CAL_opcuaexpandednodeidcompare  pfopcuaexpandednodeidcompare
	#define CHK_opcuaexpandednodeidcompare  (pfopcuaexpandednodeidcompare != NULL)
	#define EXP_opcuaexpandednodeidcompare   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaexpandednodeidcompare", (RTS_UINTPTR)opcuaexpandednodeidcompare, 1, 0xDECACF50, 0x03051000) 
#endif


/**
 * <description>opcuaexpandednodeidcopyto</description>
 */
typedef struct tagopcuaexpandednodeidcopyto_struct
{
	OpcUa_ExpandedNodeId *pSource;		/* VAR_INPUT */	
	OpcUa_ExpandedNodeId *pDestination;	/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaExpandedNodeIdCopyTo;	/* VAR_OUTPUT */	
} opcuaexpandednodeidcopyto_struct;

void CDECL CDECL_EXT opcuaexpandednodeidcopyto(opcuaexpandednodeidcopyto_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAEXPANDEDNODEIDCOPYTO_IEC) (opcuaexpandednodeidcopyto_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAEXPANDEDNODEIDCOPYTO_NOTIMPLEMENTED)
	#define USE_opcuaexpandednodeidcopyto
	#define EXT_opcuaexpandednodeidcopyto
	#define GET_opcuaexpandednodeidcopyto(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaexpandednodeidcopyto(p0) 
	#define CHK_opcuaexpandednodeidcopyto  FALSE
	#define EXP_opcuaexpandednodeidcopyto  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaexpandednodeidcopyto
	#define EXT_opcuaexpandednodeidcopyto
	#define GET_opcuaexpandednodeidcopyto(fl)  CAL_CMGETAPI( "opcuaexpandednodeidcopyto" ) 
	#define CAL_opcuaexpandednodeidcopyto  opcuaexpandednodeidcopyto
	#define CHK_opcuaexpandednodeidcopyto  TRUE
	#define EXP_opcuaexpandednodeidcopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaexpandednodeidcopyto", (RTS_UINTPTR)opcuaexpandednodeidcopyto, 1, 0x02B0E657, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaexpandednodeidcopyto
	#define EXT_opcuaexpandednodeidcopyto
	#define GET_opcuaexpandednodeidcopyto(fl)  CAL_CMGETAPI( "opcuaexpandednodeidcopyto" ) 
	#define CAL_opcuaexpandednodeidcopyto  opcuaexpandednodeidcopyto
	#define CHK_opcuaexpandednodeidcopyto  TRUE
	#define EXP_opcuaexpandednodeidcopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaexpandednodeidcopyto", (RTS_UINTPTR)opcuaexpandednodeidcopyto, 1, 0x02B0E657, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuaexpandednodeidcopyto
	#define EXT_CmpOPCUAStack_Implementationopcuaexpandednodeidcopyto
	#define GET_CmpOPCUAStack_Implementationopcuaexpandednodeidcopyto  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuaexpandednodeidcopyto  opcuaexpandednodeidcopyto
	#define CHK_CmpOPCUAStack_Implementationopcuaexpandednodeidcopyto  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuaexpandednodeidcopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaexpandednodeidcopyto", (RTS_UINTPTR)opcuaexpandednodeidcopyto, 1, 0x02B0E657, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaexpandednodeidcopyto
	#define EXT_opcuaexpandednodeidcopyto
	#define GET_opcuaexpandednodeidcopyto(fl)  CAL_CMGETAPI( "opcuaexpandednodeidcopyto" ) 
	#define CAL_opcuaexpandednodeidcopyto  opcuaexpandednodeidcopyto
	#define CHK_opcuaexpandednodeidcopyto  TRUE
	#define EXP_opcuaexpandednodeidcopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaexpandednodeidcopyto", (RTS_UINTPTR)opcuaexpandednodeidcopyto, 1, 0x02B0E657, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaexpandednodeidcopyto  PFOPCUAEXPANDEDNODEIDCOPYTO_IEC pfopcuaexpandednodeidcopyto;
	#define EXT_opcuaexpandednodeidcopyto  extern PFOPCUAEXPANDEDNODEIDCOPYTO_IEC pfopcuaexpandednodeidcopyto;
	#define GET_opcuaexpandednodeidcopyto(fl)  s_pfCMGetAPI2( "opcuaexpandednodeidcopyto", (RTS_VOID_FCTPTR *)&pfopcuaexpandednodeidcopyto, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x02B0E657, 0x03051000)
	#define CAL_opcuaexpandednodeidcopyto  pfopcuaexpandednodeidcopyto
	#define CHK_opcuaexpandednodeidcopyto  (pfopcuaexpandednodeidcopyto != NULL)
	#define EXP_opcuaexpandednodeidcopyto   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaexpandednodeidcopyto", (RTS_UINTPTR)opcuaexpandednodeidcopyto, 1, 0x02B0E657, 0x03051000) 
#endif


/**
 * <description>opcuaexpandednodeidinitialize</description>
 */
typedef struct tagopcuaexpandednodeidinitialize_struct
{
	OpcUa_ExpandedNodeId *pValue;		/* VAR_INPUT */	
} opcuaexpandednodeidinitialize_struct;

void CDECL CDECL_EXT opcuaexpandednodeidinitialize(opcuaexpandednodeidinitialize_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAEXPANDEDNODEIDINITIALIZE_IEC) (opcuaexpandednodeidinitialize_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAEXPANDEDNODEIDINITIALIZE_NOTIMPLEMENTED)
	#define USE_opcuaexpandednodeidinitialize
	#define EXT_opcuaexpandednodeidinitialize
	#define GET_opcuaexpandednodeidinitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaexpandednodeidinitialize(p0) 
	#define CHK_opcuaexpandednodeidinitialize  FALSE
	#define EXP_opcuaexpandednodeidinitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaexpandednodeidinitialize
	#define EXT_opcuaexpandednodeidinitialize
	#define GET_opcuaexpandednodeidinitialize(fl)  CAL_CMGETAPI( "opcuaexpandednodeidinitialize" ) 
	#define CAL_opcuaexpandednodeidinitialize  opcuaexpandednodeidinitialize
	#define CHK_opcuaexpandednodeidinitialize  TRUE
	#define EXP_opcuaexpandednodeidinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaexpandednodeidinitialize", (RTS_UINTPTR)opcuaexpandednodeidinitialize, 1, 0x171CB10B, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaexpandednodeidinitialize
	#define EXT_opcuaexpandednodeidinitialize
	#define GET_opcuaexpandednodeidinitialize(fl)  CAL_CMGETAPI( "opcuaexpandednodeidinitialize" ) 
	#define CAL_opcuaexpandednodeidinitialize  opcuaexpandednodeidinitialize
	#define CHK_opcuaexpandednodeidinitialize  TRUE
	#define EXP_opcuaexpandednodeidinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaexpandednodeidinitialize", (RTS_UINTPTR)opcuaexpandednodeidinitialize, 1, 0x171CB10B, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuaexpandednodeidinitialize
	#define EXT_CmpOPCUAStack_Implementationopcuaexpandednodeidinitialize
	#define GET_CmpOPCUAStack_Implementationopcuaexpandednodeidinitialize  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuaexpandednodeidinitialize  opcuaexpandednodeidinitialize
	#define CHK_CmpOPCUAStack_Implementationopcuaexpandednodeidinitialize  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuaexpandednodeidinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaexpandednodeidinitialize", (RTS_UINTPTR)opcuaexpandednodeidinitialize, 1, 0x171CB10B, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaexpandednodeidinitialize
	#define EXT_opcuaexpandednodeidinitialize
	#define GET_opcuaexpandednodeidinitialize(fl)  CAL_CMGETAPI( "opcuaexpandednodeidinitialize" ) 
	#define CAL_opcuaexpandednodeidinitialize  opcuaexpandednodeidinitialize
	#define CHK_opcuaexpandednodeidinitialize  TRUE
	#define EXP_opcuaexpandednodeidinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaexpandednodeidinitialize", (RTS_UINTPTR)opcuaexpandednodeidinitialize, 1, 0x171CB10B, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaexpandednodeidinitialize  PFOPCUAEXPANDEDNODEIDINITIALIZE_IEC pfopcuaexpandednodeidinitialize;
	#define EXT_opcuaexpandednodeidinitialize  extern PFOPCUAEXPANDEDNODEIDINITIALIZE_IEC pfopcuaexpandednodeidinitialize;
	#define GET_opcuaexpandednodeidinitialize(fl)  s_pfCMGetAPI2( "opcuaexpandednodeidinitialize", (RTS_VOID_FCTPTR *)&pfopcuaexpandednodeidinitialize, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x171CB10B, 0x03051000)
	#define CAL_opcuaexpandednodeidinitialize  pfopcuaexpandednodeidinitialize
	#define CHK_opcuaexpandednodeidinitialize  (pfopcuaexpandednodeidinitialize != NULL)
	#define EXP_opcuaexpandednodeidinitialize   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaexpandednodeidinitialize", (RTS_UINTPTR)opcuaexpandednodeidinitialize, 1, 0x171CB10B, 0x03051000) 
#endif


/**
 * <description>opcuaexpandednodeidisnull</description>
 */
typedef struct tagopcuaexpandednodeidisnull_struct
{
	OpcUa_ExpandedNodeId *pValue;		/* VAR_INPUT */	
	RTS_IEC_BYTE OpcUaExpandedNodeIdIsNull;	/* VAR_OUTPUT */	
} opcuaexpandednodeidisnull_struct;

void CDECL CDECL_EXT opcuaexpandednodeidisnull(opcuaexpandednodeidisnull_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAEXPANDEDNODEIDISNULL_IEC) (opcuaexpandednodeidisnull_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAEXPANDEDNODEIDISNULL_NOTIMPLEMENTED)
	#define USE_opcuaexpandednodeidisnull
	#define EXT_opcuaexpandednodeidisnull
	#define GET_opcuaexpandednodeidisnull(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaexpandednodeidisnull(p0) 
	#define CHK_opcuaexpandednodeidisnull  FALSE
	#define EXP_opcuaexpandednodeidisnull  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaexpandednodeidisnull
	#define EXT_opcuaexpandednodeidisnull
	#define GET_opcuaexpandednodeidisnull(fl)  CAL_CMGETAPI( "opcuaexpandednodeidisnull" ) 
	#define CAL_opcuaexpandednodeidisnull  opcuaexpandednodeidisnull
	#define CHK_opcuaexpandednodeidisnull  TRUE
	#define EXP_opcuaexpandednodeidisnull  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaexpandednodeidisnull", (RTS_UINTPTR)opcuaexpandednodeidisnull, 1, 0xF5A208FC, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaexpandednodeidisnull
	#define EXT_opcuaexpandednodeidisnull
	#define GET_opcuaexpandednodeidisnull(fl)  CAL_CMGETAPI( "opcuaexpandednodeidisnull" ) 
	#define CAL_opcuaexpandednodeidisnull  opcuaexpandednodeidisnull
	#define CHK_opcuaexpandednodeidisnull  TRUE
	#define EXP_opcuaexpandednodeidisnull  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaexpandednodeidisnull", (RTS_UINTPTR)opcuaexpandednodeidisnull, 1, 0xF5A208FC, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuaexpandednodeidisnull
	#define EXT_CmpOPCUAStack_Implementationopcuaexpandednodeidisnull
	#define GET_CmpOPCUAStack_Implementationopcuaexpandednodeidisnull  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuaexpandednodeidisnull  opcuaexpandednodeidisnull
	#define CHK_CmpOPCUAStack_Implementationopcuaexpandednodeidisnull  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuaexpandednodeidisnull  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaexpandednodeidisnull", (RTS_UINTPTR)opcuaexpandednodeidisnull, 1, 0xF5A208FC, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaexpandednodeidisnull
	#define EXT_opcuaexpandednodeidisnull
	#define GET_opcuaexpandednodeidisnull(fl)  CAL_CMGETAPI( "opcuaexpandednodeidisnull" ) 
	#define CAL_opcuaexpandednodeidisnull  opcuaexpandednodeidisnull
	#define CHK_opcuaexpandednodeidisnull  TRUE
	#define EXP_opcuaexpandednodeidisnull  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaexpandednodeidisnull", (RTS_UINTPTR)opcuaexpandednodeidisnull, 1, 0xF5A208FC, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaexpandednodeidisnull  PFOPCUAEXPANDEDNODEIDISNULL_IEC pfopcuaexpandednodeidisnull;
	#define EXT_opcuaexpandednodeidisnull  extern PFOPCUAEXPANDEDNODEIDISNULL_IEC pfopcuaexpandednodeidisnull;
	#define GET_opcuaexpandednodeidisnull(fl)  s_pfCMGetAPI2( "opcuaexpandednodeidisnull", (RTS_VOID_FCTPTR *)&pfopcuaexpandednodeidisnull, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xF5A208FC, 0x03051000)
	#define CAL_opcuaexpandednodeidisnull  pfopcuaexpandednodeidisnull
	#define CHK_opcuaexpandednodeidisnull  (pfopcuaexpandednodeidisnull != NULL)
	#define EXP_opcuaexpandednodeidisnull   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaexpandednodeidisnull", (RTS_UINTPTR)opcuaexpandednodeidisnull, 1, 0xF5A208FC, 0x03051000) 
#endif


/**
 * <description>opcuaextensionobjectclear</description>
 */
typedef struct tagopcuaextensionobjectclear_struct
{
	OpcUa_ExtensionObject *pValue;		/* VAR_INPUT */	
} opcuaextensionobjectclear_struct;

void CDECL CDECL_EXT opcuaextensionobjectclear(opcuaextensionobjectclear_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAEXTENSIONOBJECTCLEAR_IEC) (opcuaextensionobjectclear_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAEXTENSIONOBJECTCLEAR_NOTIMPLEMENTED)
	#define USE_opcuaextensionobjectclear
	#define EXT_opcuaextensionobjectclear
	#define GET_opcuaextensionobjectclear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaextensionobjectclear(p0) 
	#define CHK_opcuaextensionobjectclear  FALSE
	#define EXP_opcuaextensionobjectclear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaextensionobjectclear
	#define EXT_opcuaextensionobjectclear
	#define GET_opcuaextensionobjectclear(fl)  CAL_CMGETAPI( "opcuaextensionobjectclear" ) 
	#define CAL_opcuaextensionobjectclear  opcuaextensionobjectclear
	#define CHK_opcuaextensionobjectclear  TRUE
	#define EXP_opcuaextensionobjectclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaextensionobjectclear", (RTS_UINTPTR)opcuaextensionobjectclear, 1, 0xA67258F0, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaextensionobjectclear
	#define EXT_opcuaextensionobjectclear
	#define GET_opcuaextensionobjectclear(fl)  CAL_CMGETAPI( "opcuaextensionobjectclear" ) 
	#define CAL_opcuaextensionobjectclear  opcuaextensionobjectclear
	#define CHK_opcuaextensionobjectclear  TRUE
	#define EXP_opcuaextensionobjectclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaextensionobjectclear", (RTS_UINTPTR)opcuaextensionobjectclear, 1, 0xA67258F0, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuaextensionobjectclear
	#define EXT_CmpOPCUAStack_Implementationopcuaextensionobjectclear
	#define GET_CmpOPCUAStack_Implementationopcuaextensionobjectclear  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuaextensionobjectclear  opcuaextensionobjectclear
	#define CHK_CmpOPCUAStack_Implementationopcuaextensionobjectclear  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuaextensionobjectclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaextensionobjectclear", (RTS_UINTPTR)opcuaextensionobjectclear, 1, 0xA67258F0, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaextensionobjectclear
	#define EXT_opcuaextensionobjectclear
	#define GET_opcuaextensionobjectclear(fl)  CAL_CMGETAPI( "opcuaextensionobjectclear" ) 
	#define CAL_opcuaextensionobjectclear  opcuaextensionobjectclear
	#define CHK_opcuaextensionobjectclear  TRUE
	#define EXP_opcuaextensionobjectclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaextensionobjectclear", (RTS_UINTPTR)opcuaextensionobjectclear, 1, 0xA67258F0, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaextensionobjectclear  PFOPCUAEXTENSIONOBJECTCLEAR_IEC pfopcuaextensionobjectclear;
	#define EXT_opcuaextensionobjectclear  extern PFOPCUAEXTENSIONOBJECTCLEAR_IEC pfopcuaextensionobjectclear;
	#define GET_opcuaextensionobjectclear(fl)  s_pfCMGetAPI2( "opcuaextensionobjectclear", (RTS_VOID_FCTPTR *)&pfopcuaextensionobjectclear, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xA67258F0, 0x03051000)
	#define CAL_opcuaextensionobjectclear  pfopcuaextensionobjectclear
	#define CHK_opcuaextensionobjectclear  (pfopcuaextensionobjectclear != NULL)
	#define EXP_opcuaextensionobjectclear   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaextensionobjectclear", (RTS_UINTPTR)opcuaextensionobjectclear, 1, 0xA67258F0, 0x03051000) 
#endif


/**
 * <description>opcuaextensionobjectcompare</description>
 */
typedef struct tagopcuaextensionobjectcompare_struct
{
	OpcUa_ExtensionObject *pValue1;		/* VAR_INPUT */	
	OpcUa_ExtensionObject *pValue2;		/* VAR_INPUT */	
	RTS_IEC_DINT OpcUaExtensionObjectCompare;	/* VAR_OUTPUT */	
} opcuaextensionobjectcompare_struct;

void CDECL CDECL_EXT opcuaextensionobjectcompare(opcuaextensionobjectcompare_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAEXTENSIONOBJECTCOMPARE_IEC) (opcuaextensionobjectcompare_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAEXTENSIONOBJECTCOMPARE_NOTIMPLEMENTED)
	#define USE_opcuaextensionobjectcompare
	#define EXT_opcuaextensionobjectcompare
	#define GET_opcuaextensionobjectcompare(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaextensionobjectcompare(p0) 
	#define CHK_opcuaextensionobjectcompare  FALSE
	#define EXP_opcuaextensionobjectcompare  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaextensionobjectcompare
	#define EXT_opcuaextensionobjectcompare
	#define GET_opcuaextensionobjectcompare(fl)  CAL_CMGETAPI( "opcuaextensionobjectcompare" ) 
	#define CAL_opcuaextensionobjectcompare  opcuaextensionobjectcompare
	#define CHK_opcuaextensionobjectcompare  TRUE
	#define EXP_opcuaextensionobjectcompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaextensionobjectcompare", (RTS_UINTPTR)opcuaextensionobjectcompare, 1, 0xB81C626F, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaextensionobjectcompare
	#define EXT_opcuaextensionobjectcompare
	#define GET_opcuaextensionobjectcompare(fl)  CAL_CMGETAPI( "opcuaextensionobjectcompare" ) 
	#define CAL_opcuaextensionobjectcompare  opcuaextensionobjectcompare
	#define CHK_opcuaextensionobjectcompare  TRUE
	#define EXP_opcuaextensionobjectcompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaextensionobjectcompare", (RTS_UINTPTR)opcuaextensionobjectcompare, 1, 0xB81C626F, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuaextensionobjectcompare
	#define EXT_CmpOPCUAStack_Implementationopcuaextensionobjectcompare
	#define GET_CmpOPCUAStack_Implementationopcuaextensionobjectcompare  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuaextensionobjectcompare  opcuaextensionobjectcompare
	#define CHK_CmpOPCUAStack_Implementationopcuaextensionobjectcompare  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuaextensionobjectcompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaextensionobjectcompare", (RTS_UINTPTR)opcuaextensionobjectcompare, 1, 0xB81C626F, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaextensionobjectcompare
	#define EXT_opcuaextensionobjectcompare
	#define GET_opcuaextensionobjectcompare(fl)  CAL_CMGETAPI( "opcuaextensionobjectcompare" ) 
	#define CAL_opcuaextensionobjectcompare  opcuaextensionobjectcompare
	#define CHK_opcuaextensionobjectcompare  TRUE
	#define EXP_opcuaextensionobjectcompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaextensionobjectcompare", (RTS_UINTPTR)opcuaextensionobjectcompare, 1, 0xB81C626F, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaextensionobjectcompare  PFOPCUAEXTENSIONOBJECTCOMPARE_IEC pfopcuaextensionobjectcompare;
	#define EXT_opcuaextensionobjectcompare  extern PFOPCUAEXTENSIONOBJECTCOMPARE_IEC pfopcuaextensionobjectcompare;
	#define GET_opcuaextensionobjectcompare(fl)  s_pfCMGetAPI2( "opcuaextensionobjectcompare", (RTS_VOID_FCTPTR *)&pfopcuaextensionobjectcompare, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xB81C626F, 0x03051000)
	#define CAL_opcuaextensionobjectcompare  pfopcuaextensionobjectcompare
	#define CHK_opcuaextensionobjectcompare  (pfopcuaextensionobjectcompare != NULL)
	#define EXP_opcuaextensionobjectcompare   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaextensionobjectcompare", (RTS_UINTPTR)opcuaextensionobjectcompare, 1, 0xB81C626F, 0x03051000) 
#endif


/**
 * <description>opcuaextensionobjectcopyto</description>
 */
typedef struct tagopcuaextensionobjectcopyto_struct
{
	OpcUa_ExtensionObject *pSource;		/* VAR_INPUT */	
	OpcUa_ExtensionObject *pDestination;	/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaExtensionObjectCopyTo;	/* VAR_OUTPUT */	
} opcuaextensionobjectcopyto_struct;

void CDECL CDECL_EXT opcuaextensionobjectcopyto(opcuaextensionobjectcopyto_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAEXTENSIONOBJECTCOPYTO_IEC) (opcuaextensionobjectcopyto_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAEXTENSIONOBJECTCOPYTO_NOTIMPLEMENTED)
	#define USE_opcuaextensionobjectcopyto
	#define EXT_opcuaextensionobjectcopyto
	#define GET_opcuaextensionobjectcopyto(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaextensionobjectcopyto(p0) 
	#define CHK_opcuaextensionobjectcopyto  FALSE
	#define EXP_opcuaextensionobjectcopyto  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaextensionobjectcopyto
	#define EXT_opcuaextensionobjectcopyto
	#define GET_opcuaextensionobjectcopyto(fl)  CAL_CMGETAPI( "opcuaextensionobjectcopyto" ) 
	#define CAL_opcuaextensionobjectcopyto  opcuaextensionobjectcopyto
	#define CHK_opcuaextensionobjectcopyto  TRUE
	#define EXP_opcuaextensionobjectcopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaextensionobjectcopyto", (RTS_UINTPTR)opcuaextensionobjectcopyto, 1, 0x9C91E51C, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaextensionobjectcopyto
	#define EXT_opcuaextensionobjectcopyto
	#define GET_opcuaextensionobjectcopyto(fl)  CAL_CMGETAPI( "opcuaextensionobjectcopyto" ) 
	#define CAL_opcuaextensionobjectcopyto  opcuaextensionobjectcopyto
	#define CHK_opcuaextensionobjectcopyto  TRUE
	#define EXP_opcuaextensionobjectcopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaextensionobjectcopyto", (RTS_UINTPTR)opcuaextensionobjectcopyto, 1, 0x9C91E51C, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuaextensionobjectcopyto
	#define EXT_CmpOPCUAStack_Implementationopcuaextensionobjectcopyto
	#define GET_CmpOPCUAStack_Implementationopcuaextensionobjectcopyto  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuaextensionobjectcopyto  opcuaextensionobjectcopyto
	#define CHK_CmpOPCUAStack_Implementationopcuaextensionobjectcopyto  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuaextensionobjectcopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaextensionobjectcopyto", (RTS_UINTPTR)opcuaextensionobjectcopyto, 1, 0x9C91E51C, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaextensionobjectcopyto
	#define EXT_opcuaextensionobjectcopyto
	#define GET_opcuaextensionobjectcopyto(fl)  CAL_CMGETAPI( "opcuaextensionobjectcopyto" ) 
	#define CAL_opcuaextensionobjectcopyto  opcuaextensionobjectcopyto
	#define CHK_opcuaextensionobjectcopyto  TRUE
	#define EXP_opcuaextensionobjectcopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaextensionobjectcopyto", (RTS_UINTPTR)opcuaextensionobjectcopyto, 1, 0x9C91E51C, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaextensionobjectcopyto  PFOPCUAEXTENSIONOBJECTCOPYTO_IEC pfopcuaextensionobjectcopyto;
	#define EXT_opcuaextensionobjectcopyto  extern PFOPCUAEXTENSIONOBJECTCOPYTO_IEC pfopcuaextensionobjectcopyto;
	#define GET_opcuaextensionobjectcopyto(fl)  s_pfCMGetAPI2( "opcuaextensionobjectcopyto", (RTS_VOID_FCTPTR *)&pfopcuaextensionobjectcopyto, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x9C91E51C, 0x03051000)
	#define CAL_opcuaextensionobjectcopyto  pfopcuaextensionobjectcopyto
	#define CHK_opcuaextensionobjectcopyto  (pfopcuaextensionobjectcopyto != NULL)
	#define EXP_opcuaextensionobjectcopyto   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaextensionobjectcopyto", (RTS_UINTPTR)opcuaextensionobjectcopyto, 1, 0x9C91E51C, 0x03051000) 
#endif


/**
 * <description>opcuaextensionobjectcreate</description>
 */
typedef struct tagopcuaextensionobjectcreate_struct
{
	OpcUa_ExtensionObject **ppValue;	/* VAR_INPUT */	
} opcuaextensionobjectcreate_struct;

void CDECL CDECL_EXT opcuaextensionobjectcreate(opcuaextensionobjectcreate_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAEXTENSIONOBJECTCREATE_IEC) (opcuaextensionobjectcreate_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAEXTENSIONOBJECTCREATE_NOTIMPLEMENTED)
	#define USE_opcuaextensionobjectcreate
	#define EXT_opcuaextensionobjectcreate
	#define GET_opcuaextensionobjectcreate(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaextensionobjectcreate(p0) 
	#define CHK_opcuaextensionobjectcreate  FALSE
	#define EXP_opcuaextensionobjectcreate  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaextensionobjectcreate
	#define EXT_opcuaextensionobjectcreate
	#define GET_opcuaextensionobjectcreate(fl)  CAL_CMGETAPI( "opcuaextensionobjectcreate" ) 
	#define CAL_opcuaextensionobjectcreate  opcuaextensionobjectcreate
	#define CHK_opcuaextensionobjectcreate  TRUE
	#define EXP_opcuaextensionobjectcreate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaextensionobjectcreate", (RTS_UINTPTR)opcuaextensionobjectcreate, 1, 0xF0BFB81C, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaextensionobjectcreate
	#define EXT_opcuaextensionobjectcreate
	#define GET_opcuaextensionobjectcreate(fl)  CAL_CMGETAPI( "opcuaextensionobjectcreate" ) 
	#define CAL_opcuaextensionobjectcreate  opcuaextensionobjectcreate
	#define CHK_opcuaextensionobjectcreate  TRUE
	#define EXP_opcuaextensionobjectcreate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaextensionobjectcreate", (RTS_UINTPTR)opcuaextensionobjectcreate, 1, 0xF0BFB81C, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuaextensionobjectcreate
	#define EXT_CmpOPCUAStack_Implementationopcuaextensionobjectcreate
	#define GET_CmpOPCUAStack_Implementationopcuaextensionobjectcreate  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuaextensionobjectcreate  opcuaextensionobjectcreate
	#define CHK_CmpOPCUAStack_Implementationopcuaextensionobjectcreate  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuaextensionobjectcreate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaextensionobjectcreate", (RTS_UINTPTR)opcuaextensionobjectcreate, 1, 0xF0BFB81C, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaextensionobjectcreate
	#define EXT_opcuaextensionobjectcreate
	#define GET_opcuaextensionobjectcreate(fl)  CAL_CMGETAPI( "opcuaextensionobjectcreate" ) 
	#define CAL_opcuaextensionobjectcreate  opcuaextensionobjectcreate
	#define CHK_opcuaextensionobjectcreate  TRUE
	#define EXP_opcuaextensionobjectcreate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaextensionobjectcreate", (RTS_UINTPTR)opcuaextensionobjectcreate, 1, 0xF0BFB81C, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaextensionobjectcreate  PFOPCUAEXTENSIONOBJECTCREATE_IEC pfopcuaextensionobjectcreate;
	#define EXT_opcuaextensionobjectcreate  extern PFOPCUAEXTENSIONOBJECTCREATE_IEC pfopcuaextensionobjectcreate;
	#define GET_opcuaextensionobjectcreate(fl)  s_pfCMGetAPI2( "opcuaextensionobjectcreate", (RTS_VOID_FCTPTR *)&pfopcuaextensionobjectcreate, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xF0BFB81C, 0x03051000)
	#define CAL_opcuaextensionobjectcreate  pfopcuaextensionobjectcreate
	#define CHK_opcuaextensionobjectcreate  (pfopcuaextensionobjectcreate != NULL)
	#define EXP_opcuaextensionobjectcreate   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaextensionobjectcreate", (RTS_UINTPTR)opcuaextensionobjectcreate, 1, 0xF0BFB81C, 0x03051000) 
#endif


/**
 * <description>opcuaextensionobjectdelete</description>
 */
typedef struct tagopcuaextensionobjectdelete_struct
{
	OpcUa_ExtensionObject **ppValue;	/* VAR_INPUT */	
} opcuaextensionobjectdelete_struct;

void CDECL CDECL_EXT opcuaextensionobjectdelete(opcuaextensionobjectdelete_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAEXTENSIONOBJECTDELETE_IEC) (opcuaextensionobjectdelete_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAEXTENSIONOBJECTDELETE_NOTIMPLEMENTED)
	#define USE_opcuaextensionobjectdelete
	#define EXT_opcuaextensionobjectdelete
	#define GET_opcuaextensionobjectdelete(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaextensionobjectdelete(p0) 
	#define CHK_opcuaextensionobjectdelete  FALSE
	#define EXP_opcuaextensionobjectdelete  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaextensionobjectdelete
	#define EXT_opcuaextensionobjectdelete
	#define GET_opcuaextensionobjectdelete(fl)  CAL_CMGETAPI( "opcuaextensionobjectdelete" ) 
	#define CAL_opcuaextensionobjectdelete  opcuaextensionobjectdelete
	#define CHK_opcuaextensionobjectdelete  TRUE
	#define EXP_opcuaextensionobjectdelete  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaextensionobjectdelete", (RTS_UINTPTR)opcuaextensionobjectdelete, 1, 0x995BD981, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaextensionobjectdelete
	#define EXT_opcuaextensionobjectdelete
	#define GET_opcuaextensionobjectdelete(fl)  CAL_CMGETAPI( "opcuaextensionobjectdelete" ) 
	#define CAL_opcuaextensionobjectdelete  opcuaextensionobjectdelete
	#define CHK_opcuaextensionobjectdelete  TRUE
	#define EXP_opcuaextensionobjectdelete  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaextensionobjectdelete", (RTS_UINTPTR)opcuaextensionobjectdelete, 1, 0x995BD981, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuaextensionobjectdelete
	#define EXT_CmpOPCUAStack_Implementationopcuaextensionobjectdelete
	#define GET_CmpOPCUAStack_Implementationopcuaextensionobjectdelete  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuaextensionobjectdelete  opcuaextensionobjectdelete
	#define CHK_CmpOPCUAStack_Implementationopcuaextensionobjectdelete  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuaextensionobjectdelete  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaextensionobjectdelete", (RTS_UINTPTR)opcuaextensionobjectdelete, 1, 0x995BD981, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaextensionobjectdelete
	#define EXT_opcuaextensionobjectdelete
	#define GET_opcuaextensionobjectdelete(fl)  CAL_CMGETAPI( "opcuaextensionobjectdelete" ) 
	#define CAL_opcuaextensionobjectdelete  opcuaextensionobjectdelete
	#define CHK_opcuaextensionobjectdelete  TRUE
	#define EXP_opcuaextensionobjectdelete  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaextensionobjectdelete", (RTS_UINTPTR)opcuaextensionobjectdelete, 1, 0x995BD981, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaextensionobjectdelete  PFOPCUAEXTENSIONOBJECTDELETE_IEC pfopcuaextensionobjectdelete;
	#define EXT_opcuaextensionobjectdelete  extern PFOPCUAEXTENSIONOBJECTDELETE_IEC pfopcuaextensionobjectdelete;
	#define GET_opcuaextensionobjectdelete(fl)  s_pfCMGetAPI2( "opcuaextensionobjectdelete", (RTS_VOID_FCTPTR *)&pfopcuaextensionobjectdelete, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x995BD981, 0x03051000)
	#define CAL_opcuaextensionobjectdelete  pfopcuaextensionobjectdelete
	#define CHK_opcuaextensionobjectdelete  (pfopcuaextensionobjectdelete != NULL)
	#define EXP_opcuaextensionobjectdelete   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaextensionobjectdelete", (RTS_UINTPTR)opcuaextensionobjectdelete, 1, 0x995BD981, 0x03051000) 
#endif


/**
 * <description>opcuaextensionobjectinitialize</description>
 */
typedef struct tagopcuaextensionobjectinitialize_struct
{
	OpcUa_ExtensionObject *pValue;		/* VAR_INPUT */	
} opcuaextensionobjectinitialize_struct;

void CDECL CDECL_EXT opcuaextensionobjectinitialize(opcuaextensionobjectinitialize_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAEXTENSIONOBJECTINITIALIZE_IEC) (opcuaextensionobjectinitialize_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAEXTENSIONOBJECTINITIALIZE_NOTIMPLEMENTED)
	#define USE_opcuaextensionobjectinitialize
	#define EXT_opcuaextensionobjectinitialize
	#define GET_opcuaextensionobjectinitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaextensionobjectinitialize(p0) 
	#define CHK_opcuaextensionobjectinitialize  FALSE
	#define EXP_opcuaextensionobjectinitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaextensionobjectinitialize
	#define EXT_opcuaextensionobjectinitialize
	#define GET_opcuaextensionobjectinitialize(fl)  CAL_CMGETAPI( "opcuaextensionobjectinitialize" ) 
	#define CAL_opcuaextensionobjectinitialize  opcuaextensionobjectinitialize
	#define CHK_opcuaextensionobjectinitialize  TRUE
	#define EXP_opcuaextensionobjectinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaextensionobjectinitialize", (RTS_UINTPTR)opcuaextensionobjectinitialize, 1, 0xDF8AB6E4, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaextensionobjectinitialize
	#define EXT_opcuaextensionobjectinitialize
	#define GET_opcuaextensionobjectinitialize(fl)  CAL_CMGETAPI( "opcuaextensionobjectinitialize" ) 
	#define CAL_opcuaextensionobjectinitialize  opcuaextensionobjectinitialize
	#define CHK_opcuaextensionobjectinitialize  TRUE
	#define EXP_opcuaextensionobjectinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaextensionobjectinitialize", (RTS_UINTPTR)opcuaextensionobjectinitialize, 1, 0xDF8AB6E4, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuaextensionobjectinitialize
	#define EXT_CmpOPCUAStack_Implementationopcuaextensionobjectinitialize
	#define GET_CmpOPCUAStack_Implementationopcuaextensionobjectinitialize  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuaextensionobjectinitialize  opcuaextensionobjectinitialize
	#define CHK_CmpOPCUAStack_Implementationopcuaextensionobjectinitialize  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuaextensionobjectinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaextensionobjectinitialize", (RTS_UINTPTR)opcuaextensionobjectinitialize, 1, 0xDF8AB6E4, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaextensionobjectinitialize
	#define EXT_opcuaextensionobjectinitialize
	#define GET_opcuaextensionobjectinitialize(fl)  CAL_CMGETAPI( "opcuaextensionobjectinitialize" ) 
	#define CAL_opcuaextensionobjectinitialize  opcuaextensionobjectinitialize
	#define CHK_opcuaextensionobjectinitialize  TRUE
	#define EXP_opcuaextensionobjectinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaextensionobjectinitialize", (RTS_UINTPTR)opcuaextensionobjectinitialize, 1, 0xDF8AB6E4, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaextensionobjectinitialize  PFOPCUAEXTENSIONOBJECTINITIALIZE_IEC pfopcuaextensionobjectinitialize;
	#define EXT_opcuaextensionobjectinitialize  extern PFOPCUAEXTENSIONOBJECTINITIALIZE_IEC pfopcuaextensionobjectinitialize;
	#define GET_opcuaextensionobjectinitialize(fl)  s_pfCMGetAPI2( "opcuaextensionobjectinitialize", (RTS_VOID_FCTPTR *)&pfopcuaextensionobjectinitialize, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xDF8AB6E4, 0x03051000)
	#define CAL_opcuaextensionobjectinitialize  pfopcuaextensionobjectinitialize
	#define CHK_opcuaextensionobjectinitialize  (pfopcuaextensionobjectinitialize != NULL)
	#define EXP_opcuaextensionobjectinitialize   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaextensionobjectinitialize", (RTS_UINTPTR)opcuaextensionobjectinitialize, 1, 0xDF8AB6E4, 0x03051000) 
#endif


/**
 * <description>opcualocalizedtextclear</description>
 */
typedef struct tagopcualocalizedtextclear_struct
{
	OpcUa_LocalizedText *pValue;		/* VAR_INPUT */	
} opcualocalizedtextclear_struct;

void CDECL CDECL_EXT opcualocalizedtextclear(opcualocalizedtextclear_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUALOCALIZEDTEXTCLEAR_IEC) (opcualocalizedtextclear_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUALOCALIZEDTEXTCLEAR_NOTIMPLEMENTED)
	#define USE_opcualocalizedtextclear
	#define EXT_opcualocalizedtextclear
	#define GET_opcualocalizedtextclear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcualocalizedtextclear(p0) 
	#define CHK_opcualocalizedtextclear  FALSE
	#define EXP_opcualocalizedtextclear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcualocalizedtextclear
	#define EXT_opcualocalizedtextclear
	#define GET_opcualocalizedtextclear(fl)  CAL_CMGETAPI( "opcualocalizedtextclear" ) 
	#define CAL_opcualocalizedtextclear  opcualocalizedtextclear
	#define CHK_opcualocalizedtextclear  TRUE
	#define EXP_opcualocalizedtextclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcualocalizedtextclear", (RTS_UINTPTR)opcualocalizedtextclear, 1, 0xA85C9B89, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcualocalizedtextclear
	#define EXT_opcualocalizedtextclear
	#define GET_opcualocalizedtextclear(fl)  CAL_CMGETAPI( "opcualocalizedtextclear" ) 
	#define CAL_opcualocalizedtextclear  opcualocalizedtextclear
	#define CHK_opcualocalizedtextclear  TRUE
	#define EXP_opcualocalizedtextclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcualocalizedtextclear", (RTS_UINTPTR)opcualocalizedtextclear, 1, 0xA85C9B89, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcualocalizedtextclear
	#define EXT_CmpOPCUAStack_Implementationopcualocalizedtextclear
	#define GET_CmpOPCUAStack_Implementationopcualocalizedtextclear  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcualocalizedtextclear  opcualocalizedtextclear
	#define CHK_CmpOPCUAStack_Implementationopcualocalizedtextclear  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcualocalizedtextclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcualocalizedtextclear", (RTS_UINTPTR)opcualocalizedtextclear, 1, 0xA85C9B89, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcualocalizedtextclear
	#define EXT_opcualocalizedtextclear
	#define GET_opcualocalizedtextclear(fl)  CAL_CMGETAPI( "opcualocalizedtextclear" ) 
	#define CAL_opcualocalizedtextclear  opcualocalizedtextclear
	#define CHK_opcualocalizedtextclear  TRUE
	#define EXP_opcualocalizedtextclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcualocalizedtextclear", (RTS_UINTPTR)opcualocalizedtextclear, 1, 0xA85C9B89, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcualocalizedtextclear  PFOPCUALOCALIZEDTEXTCLEAR_IEC pfopcualocalizedtextclear;
	#define EXT_opcualocalizedtextclear  extern PFOPCUALOCALIZEDTEXTCLEAR_IEC pfopcualocalizedtextclear;
	#define GET_opcualocalizedtextclear(fl)  s_pfCMGetAPI2( "opcualocalizedtextclear", (RTS_VOID_FCTPTR *)&pfopcualocalizedtextclear, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xA85C9B89, 0x03051000)
	#define CAL_opcualocalizedtextclear  pfopcualocalizedtextclear
	#define CHK_opcualocalizedtextclear  (pfopcualocalizedtextclear != NULL)
	#define EXP_opcualocalizedtextclear   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcualocalizedtextclear", (RTS_UINTPTR)opcualocalizedtextclear, 1, 0xA85C9B89, 0x03051000) 
#endif


/**
 * <description>opcualocalizedtextcompare</description>
 */
typedef struct tagopcualocalizedtextcompare_struct
{
	OpcUa_LocalizedText *pValue1;		/* VAR_INPUT */	
	OpcUa_LocalizedText *pValue2;		/* VAR_INPUT */	
	RTS_IEC_DINT OpcUaLocalizedTextCompare;	/* VAR_OUTPUT */	
} opcualocalizedtextcompare_struct;

void CDECL CDECL_EXT opcualocalizedtextcompare(opcualocalizedtextcompare_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUALOCALIZEDTEXTCOMPARE_IEC) (opcualocalizedtextcompare_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUALOCALIZEDTEXTCOMPARE_NOTIMPLEMENTED)
	#define USE_opcualocalizedtextcompare
	#define EXT_opcualocalizedtextcompare
	#define GET_opcualocalizedtextcompare(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcualocalizedtextcompare(p0) 
	#define CHK_opcualocalizedtextcompare  FALSE
	#define EXP_opcualocalizedtextcompare  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcualocalizedtextcompare
	#define EXT_opcualocalizedtextcompare
	#define GET_opcualocalizedtextcompare(fl)  CAL_CMGETAPI( "opcualocalizedtextcompare" ) 
	#define CAL_opcualocalizedtextcompare  opcualocalizedtextcompare
	#define CHK_opcualocalizedtextcompare  TRUE
	#define EXP_opcualocalizedtextcompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcualocalizedtextcompare", (RTS_UINTPTR)opcualocalizedtextcompare, 1, 0x827CDA98, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcualocalizedtextcompare
	#define EXT_opcualocalizedtextcompare
	#define GET_opcualocalizedtextcompare(fl)  CAL_CMGETAPI( "opcualocalizedtextcompare" ) 
	#define CAL_opcualocalizedtextcompare  opcualocalizedtextcompare
	#define CHK_opcualocalizedtextcompare  TRUE
	#define EXP_opcualocalizedtextcompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcualocalizedtextcompare", (RTS_UINTPTR)opcualocalizedtextcompare, 1, 0x827CDA98, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcualocalizedtextcompare
	#define EXT_CmpOPCUAStack_Implementationopcualocalizedtextcompare
	#define GET_CmpOPCUAStack_Implementationopcualocalizedtextcompare  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcualocalizedtextcompare  opcualocalizedtextcompare
	#define CHK_CmpOPCUAStack_Implementationopcualocalizedtextcompare  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcualocalizedtextcompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcualocalizedtextcompare", (RTS_UINTPTR)opcualocalizedtextcompare, 1, 0x827CDA98, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcualocalizedtextcompare
	#define EXT_opcualocalizedtextcompare
	#define GET_opcualocalizedtextcompare(fl)  CAL_CMGETAPI( "opcualocalizedtextcompare" ) 
	#define CAL_opcualocalizedtextcompare  opcualocalizedtextcompare
	#define CHK_opcualocalizedtextcompare  TRUE
	#define EXP_opcualocalizedtextcompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcualocalizedtextcompare", (RTS_UINTPTR)opcualocalizedtextcompare, 1, 0x827CDA98, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcualocalizedtextcompare  PFOPCUALOCALIZEDTEXTCOMPARE_IEC pfopcualocalizedtextcompare;
	#define EXT_opcualocalizedtextcompare  extern PFOPCUALOCALIZEDTEXTCOMPARE_IEC pfopcualocalizedtextcompare;
	#define GET_opcualocalizedtextcompare(fl)  s_pfCMGetAPI2( "opcualocalizedtextcompare", (RTS_VOID_FCTPTR *)&pfopcualocalizedtextcompare, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x827CDA98, 0x03051000)
	#define CAL_opcualocalizedtextcompare  pfopcualocalizedtextcompare
	#define CHK_opcualocalizedtextcompare  (pfopcualocalizedtextcompare != NULL)
	#define EXP_opcualocalizedtextcompare   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcualocalizedtextcompare", (RTS_UINTPTR)opcualocalizedtextcompare, 1, 0x827CDA98, 0x03051000) 
#endif


/**
 * <description>opcualocalizedtextcopyto</description>
 */
typedef struct tagopcualocalizedtextcopyto_struct
{
	OpcUa_LocalizedText *pSource;		/* VAR_INPUT */	
	OpcUa_LocalizedText *pDestination;	/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaLocalizedTextCopyTo;	/* VAR_OUTPUT */	
} opcualocalizedtextcopyto_struct;

void CDECL CDECL_EXT opcualocalizedtextcopyto(opcualocalizedtextcopyto_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUALOCALIZEDTEXTCOPYTO_IEC) (opcualocalizedtextcopyto_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUALOCALIZEDTEXTCOPYTO_NOTIMPLEMENTED)
	#define USE_opcualocalizedtextcopyto
	#define EXT_opcualocalizedtextcopyto
	#define GET_opcualocalizedtextcopyto(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcualocalizedtextcopyto(p0) 
	#define CHK_opcualocalizedtextcopyto  FALSE
	#define EXP_opcualocalizedtextcopyto  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcualocalizedtextcopyto
	#define EXT_opcualocalizedtextcopyto
	#define GET_opcualocalizedtextcopyto(fl)  CAL_CMGETAPI( "opcualocalizedtextcopyto" ) 
	#define CAL_opcualocalizedtextcopyto  opcualocalizedtextcopyto
	#define CHK_opcualocalizedtextcopyto  TRUE
	#define EXP_opcualocalizedtextcopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcualocalizedtextcopyto", (RTS_UINTPTR)opcualocalizedtextcopyto, 1, 0x30D97055, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcualocalizedtextcopyto
	#define EXT_opcualocalizedtextcopyto
	#define GET_opcualocalizedtextcopyto(fl)  CAL_CMGETAPI( "opcualocalizedtextcopyto" ) 
	#define CAL_opcualocalizedtextcopyto  opcualocalizedtextcopyto
	#define CHK_opcualocalizedtextcopyto  TRUE
	#define EXP_opcualocalizedtextcopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcualocalizedtextcopyto", (RTS_UINTPTR)opcualocalizedtextcopyto, 1, 0x30D97055, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcualocalizedtextcopyto
	#define EXT_CmpOPCUAStack_Implementationopcualocalizedtextcopyto
	#define GET_CmpOPCUAStack_Implementationopcualocalizedtextcopyto  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcualocalizedtextcopyto  opcualocalizedtextcopyto
	#define CHK_CmpOPCUAStack_Implementationopcualocalizedtextcopyto  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcualocalizedtextcopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcualocalizedtextcopyto", (RTS_UINTPTR)opcualocalizedtextcopyto, 1, 0x30D97055, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcualocalizedtextcopyto
	#define EXT_opcualocalizedtextcopyto
	#define GET_opcualocalizedtextcopyto(fl)  CAL_CMGETAPI( "opcualocalizedtextcopyto" ) 
	#define CAL_opcualocalizedtextcopyto  opcualocalizedtextcopyto
	#define CHK_opcualocalizedtextcopyto  TRUE
	#define EXP_opcualocalizedtextcopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcualocalizedtextcopyto", (RTS_UINTPTR)opcualocalizedtextcopyto, 1, 0x30D97055, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcualocalizedtextcopyto  PFOPCUALOCALIZEDTEXTCOPYTO_IEC pfopcualocalizedtextcopyto;
	#define EXT_opcualocalizedtextcopyto  extern PFOPCUALOCALIZEDTEXTCOPYTO_IEC pfopcualocalizedtextcopyto;
	#define GET_opcualocalizedtextcopyto(fl)  s_pfCMGetAPI2( "opcualocalizedtextcopyto", (RTS_VOID_FCTPTR *)&pfopcualocalizedtextcopyto, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x30D97055, 0x03051000)
	#define CAL_opcualocalizedtextcopyto  pfopcualocalizedtextcopyto
	#define CHK_opcualocalizedtextcopyto  (pfopcualocalizedtextcopyto != NULL)
	#define EXP_opcualocalizedtextcopyto   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcualocalizedtextcopyto", (RTS_UINTPTR)opcualocalizedtextcopyto, 1, 0x30D97055, 0x03051000) 
#endif


/**
 * <description>opcualocalizedtextinitialize</description>
 */
typedef struct tagopcualocalizedtextinitialize_struct
{
	OpcUa_LocalizedText *pValue;		/* VAR_INPUT */	
} opcualocalizedtextinitialize_struct;

void CDECL CDECL_EXT opcualocalizedtextinitialize(opcualocalizedtextinitialize_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUALOCALIZEDTEXTINITIALIZE_IEC) (opcualocalizedtextinitialize_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUALOCALIZEDTEXTINITIALIZE_NOTIMPLEMENTED)
	#define USE_opcualocalizedtextinitialize
	#define EXT_opcualocalizedtextinitialize
	#define GET_opcualocalizedtextinitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcualocalizedtextinitialize(p0) 
	#define CHK_opcualocalizedtextinitialize  FALSE
	#define EXP_opcualocalizedtextinitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcualocalizedtextinitialize
	#define EXT_opcualocalizedtextinitialize
	#define GET_opcualocalizedtextinitialize(fl)  CAL_CMGETAPI( "opcualocalizedtextinitialize" ) 
	#define CAL_opcualocalizedtextinitialize  opcualocalizedtextinitialize
	#define CHK_opcualocalizedtextinitialize  TRUE
	#define EXP_opcualocalizedtextinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcualocalizedtextinitialize", (RTS_UINTPTR)opcualocalizedtextinitialize, 1, 0xC1C96077, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcualocalizedtextinitialize
	#define EXT_opcualocalizedtextinitialize
	#define GET_opcualocalizedtextinitialize(fl)  CAL_CMGETAPI( "opcualocalizedtextinitialize" ) 
	#define CAL_opcualocalizedtextinitialize  opcualocalizedtextinitialize
	#define CHK_opcualocalizedtextinitialize  TRUE
	#define EXP_opcualocalizedtextinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcualocalizedtextinitialize", (RTS_UINTPTR)opcualocalizedtextinitialize, 1, 0xC1C96077, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcualocalizedtextinitialize
	#define EXT_CmpOPCUAStack_Implementationopcualocalizedtextinitialize
	#define GET_CmpOPCUAStack_Implementationopcualocalizedtextinitialize  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcualocalizedtextinitialize  opcualocalizedtextinitialize
	#define CHK_CmpOPCUAStack_Implementationopcualocalizedtextinitialize  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcualocalizedtextinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcualocalizedtextinitialize", (RTS_UINTPTR)opcualocalizedtextinitialize, 1, 0xC1C96077, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcualocalizedtextinitialize
	#define EXT_opcualocalizedtextinitialize
	#define GET_opcualocalizedtextinitialize(fl)  CAL_CMGETAPI( "opcualocalizedtextinitialize" ) 
	#define CAL_opcualocalizedtextinitialize  opcualocalizedtextinitialize
	#define CHK_opcualocalizedtextinitialize  TRUE
	#define EXP_opcualocalizedtextinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcualocalizedtextinitialize", (RTS_UINTPTR)opcualocalizedtextinitialize, 1, 0xC1C96077, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcualocalizedtextinitialize  PFOPCUALOCALIZEDTEXTINITIALIZE_IEC pfopcualocalizedtextinitialize;
	#define EXT_opcualocalizedtextinitialize  extern PFOPCUALOCALIZEDTEXTINITIALIZE_IEC pfopcualocalizedtextinitialize;
	#define GET_opcualocalizedtextinitialize(fl)  s_pfCMGetAPI2( "opcualocalizedtextinitialize", (RTS_VOID_FCTPTR *)&pfopcualocalizedtextinitialize, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xC1C96077, 0x03051000)
	#define CAL_opcualocalizedtextinitialize  pfopcualocalizedtextinitialize
	#define CHK_opcualocalizedtextinitialize  (pfopcualocalizedtextinitialize != NULL)
	#define EXP_opcualocalizedtextinitialize   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcualocalizedtextinitialize", (RTS_UINTPTR)opcualocalizedtextinitialize, 1, 0xC1C96077, 0x03051000) 
#endif


/**
 * <description>opcuanodeidclear</description>
 */
typedef struct tagopcuanodeidclear_struct
{
	OpcUa_NodeId *pValue;				/* VAR_INPUT */	
} opcuanodeidclear_struct;

void CDECL CDECL_EXT opcuanodeidclear(opcuanodeidclear_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUANODEIDCLEAR_IEC) (opcuanodeidclear_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUANODEIDCLEAR_NOTIMPLEMENTED)
	#define USE_opcuanodeidclear
	#define EXT_opcuanodeidclear
	#define GET_opcuanodeidclear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuanodeidclear(p0) 
	#define CHK_opcuanodeidclear  FALSE
	#define EXP_opcuanodeidclear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuanodeidclear
	#define EXT_opcuanodeidclear
	#define GET_opcuanodeidclear(fl)  CAL_CMGETAPI( "opcuanodeidclear" ) 
	#define CAL_opcuanodeidclear  opcuanodeidclear
	#define CHK_opcuanodeidclear  TRUE
	#define EXP_opcuanodeidclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuanodeidclear", (RTS_UINTPTR)opcuanodeidclear, 1, 0x025A3E11, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuanodeidclear
	#define EXT_opcuanodeidclear
	#define GET_opcuanodeidclear(fl)  CAL_CMGETAPI( "opcuanodeidclear" ) 
	#define CAL_opcuanodeidclear  opcuanodeidclear
	#define CHK_opcuanodeidclear  TRUE
	#define EXP_opcuanodeidclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuanodeidclear", (RTS_UINTPTR)opcuanodeidclear, 1, 0x025A3E11, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuanodeidclear
	#define EXT_CmpOPCUAStack_Implementationopcuanodeidclear
	#define GET_CmpOPCUAStack_Implementationopcuanodeidclear  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuanodeidclear  opcuanodeidclear
	#define CHK_CmpOPCUAStack_Implementationopcuanodeidclear  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuanodeidclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuanodeidclear", (RTS_UINTPTR)opcuanodeidclear, 1, 0x025A3E11, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuanodeidclear
	#define EXT_opcuanodeidclear
	#define GET_opcuanodeidclear(fl)  CAL_CMGETAPI( "opcuanodeidclear" ) 
	#define CAL_opcuanodeidclear  opcuanodeidclear
	#define CHK_opcuanodeidclear  TRUE
	#define EXP_opcuanodeidclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuanodeidclear", (RTS_UINTPTR)opcuanodeidclear, 1, 0x025A3E11, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuanodeidclear  PFOPCUANODEIDCLEAR_IEC pfopcuanodeidclear;
	#define EXT_opcuanodeidclear  extern PFOPCUANODEIDCLEAR_IEC pfopcuanodeidclear;
	#define GET_opcuanodeidclear(fl)  s_pfCMGetAPI2( "opcuanodeidclear", (RTS_VOID_FCTPTR *)&pfopcuanodeidclear, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x025A3E11, 0x03051000)
	#define CAL_opcuanodeidclear  pfopcuanodeidclear
	#define CHK_opcuanodeidclear  (pfopcuanodeidclear != NULL)
	#define EXP_opcuanodeidclear   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuanodeidclear", (RTS_UINTPTR)opcuanodeidclear, 1, 0x025A3E11, 0x03051000) 
#endif


/**
 * <description>opcuanodeidcompare</description>
 */
typedef struct tagopcuanodeidcompare_struct
{
	OpcUa_NodeId *pValue1;				/* VAR_INPUT */	
	OpcUa_NodeId *pValue2;				/* VAR_INPUT */	
	RTS_IEC_DINT OpcUaNodeIdCompare;	/* VAR_OUTPUT */	
} opcuanodeidcompare_struct;

void CDECL CDECL_EXT opcuanodeidcompare(opcuanodeidcompare_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUANODEIDCOMPARE_IEC) (opcuanodeidcompare_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUANODEIDCOMPARE_NOTIMPLEMENTED)
	#define USE_opcuanodeidcompare
	#define EXT_opcuanodeidcompare
	#define GET_opcuanodeidcompare(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuanodeidcompare(p0) 
	#define CHK_opcuanodeidcompare  FALSE
	#define EXP_opcuanodeidcompare  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuanodeidcompare
	#define EXT_opcuanodeidcompare
	#define GET_opcuanodeidcompare(fl)  CAL_CMGETAPI( "opcuanodeidcompare" ) 
	#define CAL_opcuanodeidcompare  opcuanodeidcompare
	#define CHK_opcuanodeidcompare  TRUE
	#define EXP_opcuanodeidcompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuanodeidcompare", (RTS_UINTPTR)opcuanodeidcompare, 1, 0x33441B4B, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuanodeidcompare
	#define EXT_opcuanodeidcompare
	#define GET_opcuanodeidcompare(fl)  CAL_CMGETAPI( "opcuanodeidcompare" ) 
	#define CAL_opcuanodeidcompare  opcuanodeidcompare
	#define CHK_opcuanodeidcompare  TRUE
	#define EXP_opcuanodeidcompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuanodeidcompare", (RTS_UINTPTR)opcuanodeidcompare, 1, 0x33441B4B, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuanodeidcompare
	#define EXT_CmpOPCUAStack_Implementationopcuanodeidcompare
	#define GET_CmpOPCUAStack_Implementationopcuanodeidcompare  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuanodeidcompare  opcuanodeidcompare
	#define CHK_CmpOPCUAStack_Implementationopcuanodeidcompare  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuanodeidcompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuanodeidcompare", (RTS_UINTPTR)opcuanodeidcompare, 1, 0x33441B4B, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuanodeidcompare
	#define EXT_opcuanodeidcompare
	#define GET_opcuanodeidcompare(fl)  CAL_CMGETAPI( "opcuanodeidcompare" ) 
	#define CAL_opcuanodeidcompare  opcuanodeidcompare
	#define CHK_opcuanodeidcompare  TRUE
	#define EXP_opcuanodeidcompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuanodeidcompare", (RTS_UINTPTR)opcuanodeidcompare, 1, 0x33441B4B, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuanodeidcompare  PFOPCUANODEIDCOMPARE_IEC pfopcuanodeidcompare;
	#define EXT_opcuanodeidcompare  extern PFOPCUANODEIDCOMPARE_IEC pfopcuanodeidcompare;
	#define GET_opcuanodeidcompare(fl)  s_pfCMGetAPI2( "opcuanodeidcompare", (RTS_VOID_FCTPTR *)&pfopcuanodeidcompare, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x33441B4B, 0x03051000)
	#define CAL_opcuanodeidcompare  pfopcuanodeidcompare
	#define CHK_opcuanodeidcompare  (pfopcuanodeidcompare != NULL)
	#define EXP_opcuanodeidcompare   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuanodeidcompare", (RTS_UINTPTR)opcuanodeidcompare, 1, 0x33441B4B, 0x03051000) 
#endif


/**
 * <description>opcuanodeidcopyto</description>
 */
typedef struct tagopcuanodeidcopyto_struct
{
	OpcUa_NodeId *pSource;				/* VAR_INPUT */	
	OpcUa_NodeId *pDestination;			/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaNodeIdCopyTo;	/* VAR_OUTPUT */	
} opcuanodeidcopyto_struct;

void CDECL CDECL_EXT opcuanodeidcopyto(opcuanodeidcopyto_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUANODEIDCOPYTO_IEC) (opcuanodeidcopyto_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUANODEIDCOPYTO_NOTIMPLEMENTED)
	#define USE_opcuanodeidcopyto
	#define EXT_opcuanodeidcopyto
	#define GET_opcuanodeidcopyto(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuanodeidcopyto(p0) 
	#define CHK_opcuanodeidcopyto  FALSE
	#define EXP_opcuanodeidcopyto  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuanodeidcopyto
	#define EXT_opcuanodeidcopyto
	#define GET_opcuanodeidcopyto(fl)  CAL_CMGETAPI( "opcuanodeidcopyto" ) 
	#define CAL_opcuanodeidcopyto  opcuanodeidcopyto
	#define CHK_opcuanodeidcopyto  TRUE
	#define EXP_opcuanodeidcopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuanodeidcopyto", (RTS_UINTPTR)opcuanodeidcopyto, 1, 0xEC6C4C52, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuanodeidcopyto
	#define EXT_opcuanodeidcopyto
	#define GET_opcuanodeidcopyto(fl)  CAL_CMGETAPI( "opcuanodeidcopyto" ) 
	#define CAL_opcuanodeidcopyto  opcuanodeidcopyto
	#define CHK_opcuanodeidcopyto  TRUE
	#define EXP_opcuanodeidcopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuanodeidcopyto", (RTS_UINTPTR)opcuanodeidcopyto, 1, 0xEC6C4C52, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuanodeidcopyto
	#define EXT_CmpOPCUAStack_Implementationopcuanodeidcopyto
	#define GET_CmpOPCUAStack_Implementationopcuanodeidcopyto  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuanodeidcopyto  opcuanodeidcopyto
	#define CHK_CmpOPCUAStack_Implementationopcuanodeidcopyto  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuanodeidcopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuanodeidcopyto", (RTS_UINTPTR)opcuanodeidcopyto, 1, 0xEC6C4C52, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuanodeidcopyto
	#define EXT_opcuanodeidcopyto
	#define GET_opcuanodeidcopyto(fl)  CAL_CMGETAPI( "opcuanodeidcopyto" ) 
	#define CAL_opcuanodeidcopyto  opcuanodeidcopyto
	#define CHK_opcuanodeidcopyto  TRUE
	#define EXP_opcuanodeidcopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuanodeidcopyto", (RTS_UINTPTR)opcuanodeidcopyto, 1, 0xEC6C4C52, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuanodeidcopyto  PFOPCUANODEIDCOPYTO_IEC pfopcuanodeidcopyto;
	#define EXT_opcuanodeidcopyto  extern PFOPCUANODEIDCOPYTO_IEC pfopcuanodeidcopyto;
	#define GET_opcuanodeidcopyto(fl)  s_pfCMGetAPI2( "opcuanodeidcopyto", (RTS_VOID_FCTPTR *)&pfopcuanodeidcopyto, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xEC6C4C52, 0x03051000)
	#define CAL_opcuanodeidcopyto  pfopcuanodeidcopyto
	#define CHK_opcuanodeidcopyto  (pfopcuanodeidcopyto != NULL)
	#define EXP_opcuanodeidcopyto   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuanodeidcopyto", (RTS_UINTPTR)opcuanodeidcopyto, 1, 0xEC6C4C52, 0x03051000) 
#endif


/**
 * <description>opcuanodeidinitialize</description>
 */
typedef struct tagopcuanodeidinitialize_struct
{
	OpcUa_NodeId *pValue;				/* VAR_INPUT */	
} opcuanodeidinitialize_struct;

void CDECL CDECL_EXT opcuanodeidinitialize(opcuanodeidinitialize_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUANODEIDINITIALIZE_IEC) (opcuanodeidinitialize_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUANODEIDINITIALIZE_NOTIMPLEMENTED)
	#define USE_opcuanodeidinitialize
	#define EXT_opcuanodeidinitialize
	#define GET_opcuanodeidinitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuanodeidinitialize(p0) 
	#define CHK_opcuanodeidinitialize  FALSE
	#define EXP_opcuanodeidinitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuanodeidinitialize
	#define EXT_opcuanodeidinitialize
	#define GET_opcuanodeidinitialize(fl)  CAL_CMGETAPI( "opcuanodeidinitialize" ) 
	#define CAL_opcuanodeidinitialize  opcuanodeidinitialize
	#define CHK_opcuanodeidinitialize  TRUE
	#define EXP_opcuanodeidinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuanodeidinitialize", (RTS_UINTPTR)opcuanodeidinitialize, 1, 0x776DA0A9, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuanodeidinitialize
	#define EXT_opcuanodeidinitialize
	#define GET_opcuanodeidinitialize(fl)  CAL_CMGETAPI( "opcuanodeidinitialize" ) 
	#define CAL_opcuanodeidinitialize  opcuanodeidinitialize
	#define CHK_opcuanodeidinitialize  TRUE
	#define EXP_opcuanodeidinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuanodeidinitialize", (RTS_UINTPTR)opcuanodeidinitialize, 1, 0x776DA0A9, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuanodeidinitialize
	#define EXT_CmpOPCUAStack_Implementationopcuanodeidinitialize
	#define GET_CmpOPCUAStack_Implementationopcuanodeidinitialize  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuanodeidinitialize  opcuanodeidinitialize
	#define CHK_CmpOPCUAStack_Implementationopcuanodeidinitialize  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuanodeidinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuanodeidinitialize", (RTS_UINTPTR)opcuanodeidinitialize, 1, 0x776DA0A9, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuanodeidinitialize
	#define EXT_opcuanodeidinitialize
	#define GET_opcuanodeidinitialize(fl)  CAL_CMGETAPI( "opcuanodeidinitialize" ) 
	#define CAL_opcuanodeidinitialize  opcuanodeidinitialize
	#define CHK_opcuanodeidinitialize  TRUE
	#define EXP_opcuanodeidinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuanodeidinitialize", (RTS_UINTPTR)opcuanodeidinitialize, 1, 0x776DA0A9, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuanodeidinitialize  PFOPCUANODEIDINITIALIZE_IEC pfopcuanodeidinitialize;
	#define EXT_opcuanodeidinitialize  extern PFOPCUANODEIDINITIALIZE_IEC pfopcuanodeidinitialize;
	#define GET_opcuanodeidinitialize(fl)  s_pfCMGetAPI2( "opcuanodeidinitialize", (RTS_VOID_FCTPTR *)&pfopcuanodeidinitialize, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x776DA0A9, 0x03051000)
	#define CAL_opcuanodeidinitialize  pfopcuanodeidinitialize
	#define CHK_opcuanodeidinitialize  (pfopcuanodeidinitialize != NULL)
	#define EXP_opcuanodeidinitialize   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuanodeidinitialize", (RTS_UINTPTR)opcuanodeidinitialize, 1, 0x776DA0A9, 0x03051000) 
#endif


/**
 * <description>opcuanodeidisnull</description>
 */
typedef struct tagopcuanodeidisnull_struct
{
	OpcUa_NodeId *pValue;				/* VAR_INPUT */	
	RTS_IEC_BYTE OpcUaNodeIdIsNull;		/* VAR_OUTPUT */	
} opcuanodeidisnull_struct;

void CDECL CDECL_EXT opcuanodeidisnull(opcuanodeidisnull_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUANODEIDISNULL_IEC) (opcuanodeidisnull_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUANODEIDISNULL_NOTIMPLEMENTED)
	#define USE_opcuanodeidisnull
	#define EXT_opcuanodeidisnull
	#define GET_opcuanodeidisnull(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuanodeidisnull(p0) 
	#define CHK_opcuanodeidisnull  FALSE
	#define EXP_opcuanodeidisnull  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuanodeidisnull
	#define EXT_opcuanodeidisnull
	#define GET_opcuanodeidisnull(fl)  CAL_CMGETAPI( "opcuanodeidisnull" ) 
	#define CAL_opcuanodeidisnull  opcuanodeidisnull
	#define CHK_opcuanodeidisnull  TRUE
	#define EXP_opcuanodeidisnull  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuanodeidisnull", (RTS_UINTPTR)opcuanodeidisnull, 1, 0x1519DE92, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuanodeidisnull
	#define EXT_opcuanodeidisnull
	#define GET_opcuanodeidisnull(fl)  CAL_CMGETAPI( "opcuanodeidisnull" ) 
	#define CAL_opcuanodeidisnull  opcuanodeidisnull
	#define CHK_opcuanodeidisnull  TRUE
	#define EXP_opcuanodeidisnull  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuanodeidisnull", (RTS_UINTPTR)opcuanodeidisnull, 1, 0x1519DE92, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuanodeidisnull
	#define EXT_CmpOPCUAStack_Implementationopcuanodeidisnull
	#define GET_CmpOPCUAStack_Implementationopcuanodeidisnull  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuanodeidisnull  opcuanodeidisnull
	#define CHK_CmpOPCUAStack_Implementationopcuanodeidisnull  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuanodeidisnull  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuanodeidisnull", (RTS_UINTPTR)opcuanodeidisnull, 1, 0x1519DE92, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuanodeidisnull
	#define EXT_opcuanodeidisnull
	#define GET_opcuanodeidisnull(fl)  CAL_CMGETAPI( "opcuanodeidisnull" ) 
	#define CAL_opcuanodeidisnull  opcuanodeidisnull
	#define CHK_opcuanodeidisnull  TRUE
	#define EXP_opcuanodeidisnull  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuanodeidisnull", (RTS_UINTPTR)opcuanodeidisnull, 1, 0x1519DE92, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuanodeidisnull  PFOPCUANODEIDISNULL_IEC pfopcuanodeidisnull;
	#define EXT_opcuanodeidisnull  extern PFOPCUANODEIDISNULL_IEC pfopcuanodeidisnull;
	#define GET_opcuanodeidisnull(fl)  s_pfCMGetAPI2( "opcuanodeidisnull", (RTS_VOID_FCTPTR *)&pfopcuanodeidisnull, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x1519DE92, 0x03051000)
	#define CAL_opcuanodeidisnull  pfopcuanodeidisnull
	#define CHK_opcuanodeidisnull  (pfopcuanodeidisnull != NULL)
	#define EXP_opcuanodeidisnull   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuanodeidisnull", (RTS_UINTPTR)opcuanodeidisnull, 1, 0x1519DE92, 0x03051000) 
#endif


/**
 * <description>opcuaqualifiednameclear</description>
 */
typedef struct tagopcuaqualifiednameclear_struct
{
	OpcUa_QualifiedName *pValue;		/* VAR_INPUT */	
} opcuaqualifiednameclear_struct;

void CDECL CDECL_EXT opcuaqualifiednameclear(opcuaqualifiednameclear_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAQUALIFIEDNAMECLEAR_IEC) (opcuaqualifiednameclear_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAQUALIFIEDNAMECLEAR_NOTIMPLEMENTED)
	#define USE_opcuaqualifiednameclear
	#define EXT_opcuaqualifiednameclear
	#define GET_opcuaqualifiednameclear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaqualifiednameclear(p0) 
	#define CHK_opcuaqualifiednameclear  FALSE
	#define EXP_opcuaqualifiednameclear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaqualifiednameclear
	#define EXT_opcuaqualifiednameclear
	#define GET_opcuaqualifiednameclear(fl)  CAL_CMGETAPI( "opcuaqualifiednameclear" ) 
	#define CAL_opcuaqualifiednameclear  opcuaqualifiednameclear
	#define CHK_opcuaqualifiednameclear  TRUE
	#define EXP_opcuaqualifiednameclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaqualifiednameclear", (RTS_UINTPTR)opcuaqualifiednameclear, 1, 0xAAADFAAB, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaqualifiednameclear
	#define EXT_opcuaqualifiednameclear
	#define GET_opcuaqualifiednameclear(fl)  CAL_CMGETAPI( "opcuaqualifiednameclear" ) 
	#define CAL_opcuaqualifiednameclear  opcuaqualifiednameclear
	#define CHK_opcuaqualifiednameclear  TRUE
	#define EXP_opcuaqualifiednameclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaqualifiednameclear", (RTS_UINTPTR)opcuaqualifiednameclear, 1, 0xAAADFAAB, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuaqualifiednameclear
	#define EXT_CmpOPCUAStack_Implementationopcuaqualifiednameclear
	#define GET_CmpOPCUAStack_Implementationopcuaqualifiednameclear  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuaqualifiednameclear  opcuaqualifiednameclear
	#define CHK_CmpOPCUAStack_Implementationopcuaqualifiednameclear  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuaqualifiednameclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaqualifiednameclear", (RTS_UINTPTR)opcuaqualifiednameclear, 1, 0xAAADFAAB, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaqualifiednameclear
	#define EXT_opcuaqualifiednameclear
	#define GET_opcuaqualifiednameclear(fl)  CAL_CMGETAPI( "opcuaqualifiednameclear" ) 
	#define CAL_opcuaqualifiednameclear  opcuaqualifiednameclear
	#define CHK_opcuaqualifiednameclear  TRUE
	#define EXP_opcuaqualifiednameclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaqualifiednameclear", (RTS_UINTPTR)opcuaqualifiednameclear, 1, 0xAAADFAAB, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaqualifiednameclear  PFOPCUAQUALIFIEDNAMECLEAR_IEC pfopcuaqualifiednameclear;
	#define EXT_opcuaqualifiednameclear  extern PFOPCUAQUALIFIEDNAMECLEAR_IEC pfopcuaqualifiednameclear;
	#define GET_opcuaqualifiednameclear(fl)  s_pfCMGetAPI2( "opcuaqualifiednameclear", (RTS_VOID_FCTPTR *)&pfopcuaqualifiednameclear, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xAAADFAAB, 0x03051000)
	#define CAL_opcuaqualifiednameclear  pfopcuaqualifiednameclear
	#define CHK_opcuaqualifiednameclear  (pfopcuaqualifiednameclear != NULL)
	#define EXP_opcuaqualifiednameclear   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaqualifiednameclear", (RTS_UINTPTR)opcuaqualifiednameclear, 1, 0xAAADFAAB, 0x03051000) 
#endif


/**
 * <description>opcuaqualifiednamecompare</description>
 */
typedef struct tagopcuaqualifiednamecompare_struct
{
	OpcUa_QualifiedName *pValue1;		/* VAR_INPUT */	
	OpcUa_QualifiedName *pValue2;		/* VAR_INPUT */	
	RTS_IEC_DINT OpcUaQualifiedNameCompare;	/* VAR_OUTPUT */	
} opcuaqualifiednamecompare_struct;

void CDECL CDECL_EXT opcuaqualifiednamecompare(opcuaqualifiednamecompare_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAQUALIFIEDNAMECOMPARE_IEC) (opcuaqualifiednamecompare_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAQUALIFIEDNAMECOMPARE_NOTIMPLEMENTED)
	#define USE_opcuaqualifiednamecompare
	#define EXT_opcuaqualifiednamecompare
	#define GET_opcuaqualifiednamecompare(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaqualifiednamecompare(p0) 
	#define CHK_opcuaqualifiednamecompare  FALSE
	#define EXP_opcuaqualifiednamecompare  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaqualifiednamecompare
	#define EXT_opcuaqualifiednamecompare
	#define GET_opcuaqualifiednamecompare(fl)  CAL_CMGETAPI( "opcuaqualifiednamecompare" ) 
	#define CAL_opcuaqualifiednamecompare  opcuaqualifiednamecompare
	#define CHK_opcuaqualifiednamecompare  TRUE
	#define EXP_opcuaqualifiednamecompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaqualifiednamecompare", (RTS_UINTPTR)opcuaqualifiednamecompare, 1, 0xAFF540F5, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaqualifiednamecompare
	#define EXT_opcuaqualifiednamecompare
	#define GET_opcuaqualifiednamecompare(fl)  CAL_CMGETAPI( "opcuaqualifiednamecompare" ) 
	#define CAL_opcuaqualifiednamecompare  opcuaqualifiednamecompare
	#define CHK_opcuaqualifiednamecompare  TRUE
	#define EXP_opcuaqualifiednamecompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaqualifiednamecompare", (RTS_UINTPTR)opcuaqualifiednamecompare, 1, 0xAFF540F5, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuaqualifiednamecompare
	#define EXT_CmpOPCUAStack_Implementationopcuaqualifiednamecompare
	#define GET_CmpOPCUAStack_Implementationopcuaqualifiednamecompare  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuaqualifiednamecompare  opcuaqualifiednamecompare
	#define CHK_CmpOPCUAStack_Implementationopcuaqualifiednamecompare  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuaqualifiednamecompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaqualifiednamecompare", (RTS_UINTPTR)opcuaqualifiednamecompare, 1, 0xAFF540F5, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaqualifiednamecompare
	#define EXT_opcuaqualifiednamecompare
	#define GET_opcuaqualifiednamecompare(fl)  CAL_CMGETAPI( "opcuaqualifiednamecompare" ) 
	#define CAL_opcuaqualifiednamecompare  opcuaqualifiednamecompare
	#define CHK_opcuaqualifiednamecompare  TRUE
	#define EXP_opcuaqualifiednamecompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaqualifiednamecompare", (RTS_UINTPTR)opcuaqualifiednamecompare, 1, 0xAFF540F5, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaqualifiednamecompare  PFOPCUAQUALIFIEDNAMECOMPARE_IEC pfopcuaqualifiednamecompare;
	#define EXT_opcuaqualifiednamecompare  extern PFOPCUAQUALIFIEDNAMECOMPARE_IEC pfopcuaqualifiednamecompare;
	#define GET_opcuaqualifiednamecompare(fl)  s_pfCMGetAPI2( "opcuaqualifiednamecompare", (RTS_VOID_FCTPTR *)&pfopcuaqualifiednamecompare, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xAFF540F5, 0x03051000)
	#define CAL_opcuaqualifiednamecompare  pfopcuaqualifiednamecompare
	#define CHK_opcuaqualifiednamecompare  (pfopcuaqualifiednamecompare != NULL)
	#define EXP_opcuaqualifiednamecompare   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaqualifiednamecompare", (RTS_UINTPTR)opcuaqualifiednamecompare, 1, 0xAFF540F5, 0x03051000) 
#endif


/**
 * <description>opcuaqualifiednamecopyto</description>
 */
typedef struct tagopcuaqualifiednamecopyto_struct
{
	OpcUa_QualifiedName *pSource;		/* VAR_INPUT */	
	OpcUa_QualifiedName *pDestination;	/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaQualifiedNameCopyTo;	/* VAR_OUTPUT */	
} opcuaqualifiednamecopyto_struct;

void CDECL CDECL_EXT opcuaqualifiednamecopyto(opcuaqualifiednamecopyto_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAQUALIFIEDNAMECOPYTO_IEC) (opcuaqualifiednamecopyto_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAQUALIFIEDNAMECOPYTO_NOTIMPLEMENTED)
	#define USE_opcuaqualifiednamecopyto
	#define EXT_opcuaqualifiednamecopyto
	#define GET_opcuaqualifiednamecopyto(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaqualifiednamecopyto(p0) 
	#define CHK_opcuaqualifiednamecopyto  FALSE
	#define EXP_opcuaqualifiednamecopyto  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaqualifiednamecopyto
	#define EXT_opcuaqualifiednamecopyto
	#define GET_opcuaqualifiednamecopyto(fl)  CAL_CMGETAPI( "opcuaqualifiednamecopyto" ) 
	#define CAL_opcuaqualifiednamecopyto  opcuaqualifiednamecopyto
	#define CHK_opcuaqualifiednamecopyto  TRUE
	#define EXP_opcuaqualifiednamecopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaqualifiednamecopyto", (RTS_UINTPTR)opcuaqualifiednamecopyto, 1, 0xFA67B572, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaqualifiednamecopyto
	#define EXT_opcuaqualifiednamecopyto
	#define GET_opcuaqualifiednamecopyto(fl)  CAL_CMGETAPI( "opcuaqualifiednamecopyto" ) 
	#define CAL_opcuaqualifiednamecopyto  opcuaqualifiednamecopyto
	#define CHK_opcuaqualifiednamecopyto  TRUE
	#define EXP_opcuaqualifiednamecopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaqualifiednamecopyto", (RTS_UINTPTR)opcuaqualifiednamecopyto, 1, 0xFA67B572, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuaqualifiednamecopyto
	#define EXT_CmpOPCUAStack_Implementationopcuaqualifiednamecopyto
	#define GET_CmpOPCUAStack_Implementationopcuaqualifiednamecopyto  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuaqualifiednamecopyto  opcuaqualifiednamecopyto
	#define CHK_CmpOPCUAStack_Implementationopcuaqualifiednamecopyto  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuaqualifiednamecopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaqualifiednamecopyto", (RTS_UINTPTR)opcuaqualifiednamecopyto, 1, 0xFA67B572, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaqualifiednamecopyto
	#define EXT_opcuaqualifiednamecopyto
	#define GET_opcuaqualifiednamecopyto(fl)  CAL_CMGETAPI( "opcuaqualifiednamecopyto" ) 
	#define CAL_opcuaqualifiednamecopyto  opcuaqualifiednamecopyto
	#define CHK_opcuaqualifiednamecopyto  TRUE
	#define EXP_opcuaqualifiednamecopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaqualifiednamecopyto", (RTS_UINTPTR)opcuaqualifiednamecopyto, 1, 0xFA67B572, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaqualifiednamecopyto  PFOPCUAQUALIFIEDNAMECOPYTO_IEC pfopcuaqualifiednamecopyto;
	#define EXT_opcuaqualifiednamecopyto  extern PFOPCUAQUALIFIEDNAMECOPYTO_IEC pfopcuaqualifiednamecopyto;
	#define GET_opcuaqualifiednamecopyto(fl)  s_pfCMGetAPI2( "opcuaqualifiednamecopyto", (RTS_VOID_FCTPTR *)&pfopcuaqualifiednamecopyto, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xFA67B572, 0x03051000)
	#define CAL_opcuaqualifiednamecopyto  pfopcuaqualifiednamecopyto
	#define CHK_opcuaqualifiednamecopyto  (pfopcuaqualifiednamecopyto != NULL)
	#define EXP_opcuaqualifiednamecopyto   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaqualifiednamecopyto", (RTS_UINTPTR)opcuaqualifiednamecopyto, 1, 0xFA67B572, 0x03051000) 
#endif


/**
 * <description>opcuaqualifiednameinitialize</description>
 */
typedef struct tagopcuaqualifiednameinitialize_struct
{
	OpcUa_QualifiedName *pValue;		/* VAR_INPUT */	
} opcuaqualifiednameinitialize_struct;

void CDECL CDECL_EXT opcuaqualifiednameinitialize(opcuaqualifiednameinitialize_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAQUALIFIEDNAMEINITIALIZE_IEC) (opcuaqualifiednameinitialize_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAQUALIFIEDNAMEINITIALIZE_NOTIMPLEMENTED)
	#define USE_opcuaqualifiednameinitialize
	#define EXT_opcuaqualifiednameinitialize
	#define GET_opcuaqualifiednameinitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaqualifiednameinitialize(p0) 
	#define CHK_opcuaqualifiednameinitialize  FALSE
	#define EXP_opcuaqualifiednameinitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaqualifiednameinitialize
	#define EXT_opcuaqualifiednameinitialize
	#define GET_opcuaqualifiednameinitialize(fl)  CAL_CMGETAPI( "opcuaqualifiednameinitialize" ) 
	#define CAL_opcuaqualifiednameinitialize  opcuaqualifiednameinitialize
	#define CHK_opcuaqualifiednameinitialize  TRUE
	#define EXP_opcuaqualifiednameinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaqualifiednameinitialize", (RTS_UINTPTR)opcuaqualifiednameinitialize, 1, 0x4DE39903, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaqualifiednameinitialize
	#define EXT_opcuaqualifiednameinitialize
	#define GET_opcuaqualifiednameinitialize(fl)  CAL_CMGETAPI( "opcuaqualifiednameinitialize" ) 
	#define CAL_opcuaqualifiednameinitialize  opcuaqualifiednameinitialize
	#define CHK_opcuaqualifiednameinitialize  TRUE
	#define EXP_opcuaqualifiednameinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaqualifiednameinitialize", (RTS_UINTPTR)opcuaqualifiednameinitialize, 1, 0x4DE39903, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuaqualifiednameinitialize
	#define EXT_CmpOPCUAStack_Implementationopcuaqualifiednameinitialize
	#define GET_CmpOPCUAStack_Implementationopcuaqualifiednameinitialize  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuaqualifiednameinitialize  opcuaqualifiednameinitialize
	#define CHK_CmpOPCUAStack_Implementationopcuaqualifiednameinitialize  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuaqualifiednameinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaqualifiednameinitialize", (RTS_UINTPTR)opcuaqualifiednameinitialize, 1, 0x4DE39903, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaqualifiednameinitialize
	#define EXT_opcuaqualifiednameinitialize
	#define GET_opcuaqualifiednameinitialize(fl)  CAL_CMGETAPI( "opcuaqualifiednameinitialize" ) 
	#define CAL_opcuaqualifiednameinitialize  opcuaqualifiednameinitialize
	#define CHK_opcuaqualifiednameinitialize  TRUE
	#define EXP_opcuaqualifiednameinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaqualifiednameinitialize", (RTS_UINTPTR)opcuaqualifiednameinitialize, 1, 0x4DE39903, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaqualifiednameinitialize  PFOPCUAQUALIFIEDNAMEINITIALIZE_IEC pfopcuaqualifiednameinitialize;
	#define EXT_opcuaqualifiednameinitialize  extern PFOPCUAQUALIFIEDNAMEINITIALIZE_IEC pfopcuaqualifiednameinitialize;
	#define GET_opcuaqualifiednameinitialize(fl)  s_pfCMGetAPI2( "opcuaqualifiednameinitialize", (RTS_VOID_FCTPTR *)&pfopcuaqualifiednameinitialize, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x4DE39903, 0x03051000)
	#define CAL_opcuaqualifiednameinitialize  pfopcuaqualifiednameinitialize
	#define CHK_opcuaqualifiednameinitialize  (pfopcuaqualifiednameinitialize != NULL)
	#define EXP_opcuaqualifiednameinitialize   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaqualifiednameinitialize", (RTS_UINTPTR)opcuaqualifiednameinitialize, 1, 0x4DE39903, 0x03051000) 
#endif


/**
 * <description>opcuareadvalueidclear</description>
 */
typedef struct tagopcuareadvalueidclear_struct
{
	OpcUa_ReadValueId *pValue;			/* VAR_INPUT */	
} opcuareadvalueidclear_struct;

void CDECL CDECL_EXT opcuareadvalueidclear(opcuareadvalueidclear_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAREADVALUEIDCLEAR_IEC) (opcuareadvalueidclear_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAREADVALUEIDCLEAR_NOTIMPLEMENTED)
	#define USE_opcuareadvalueidclear
	#define EXT_opcuareadvalueidclear
	#define GET_opcuareadvalueidclear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuareadvalueidclear(p0) 
	#define CHK_opcuareadvalueidclear  FALSE
	#define EXP_opcuareadvalueidclear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuareadvalueidclear
	#define EXT_opcuareadvalueidclear
	#define GET_opcuareadvalueidclear(fl)  CAL_CMGETAPI( "opcuareadvalueidclear" ) 
	#define CAL_opcuareadvalueidclear  opcuareadvalueidclear
	#define CHK_opcuareadvalueidclear  TRUE
	#define EXP_opcuareadvalueidclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuareadvalueidclear", (RTS_UINTPTR)opcuareadvalueidclear, 1, 0x5E9470F8, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuareadvalueidclear
	#define EXT_opcuareadvalueidclear
	#define GET_opcuareadvalueidclear(fl)  CAL_CMGETAPI( "opcuareadvalueidclear" ) 
	#define CAL_opcuareadvalueidclear  opcuareadvalueidclear
	#define CHK_opcuareadvalueidclear  TRUE
	#define EXP_opcuareadvalueidclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuareadvalueidclear", (RTS_UINTPTR)opcuareadvalueidclear, 1, 0x5E9470F8, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuareadvalueidclear
	#define EXT_CmpOPCUAStack_Implementationopcuareadvalueidclear
	#define GET_CmpOPCUAStack_Implementationopcuareadvalueidclear  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuareadvalueidclear  opcuareadvalueidclear
	#define CHK_CmpOPCUAStack_Implementationopcuareadvalueidclear  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuareadvalueidclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuareadvalueidclear", (RTS_UINTPTR)opcuareadvalueidclear, 1, 0x5E9470F8, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuareadvalueidclear
	#define EXT_opcuareadvalueidclear
	#define GET_opcuareadvalueidclear(fl)  CAL_CMGETAPI( "opcuareadvalueidclear" ) 
	#define CAL_opcuareadvalueidclear  opcuareadvalueidclear
	#define CHK_opcuareadvalueidclear  TRUE
	#define EXP_opcuareadvalueidclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuareadvalueidclear", (RTS_UINTPTR)opcuareadvalueidclear, 1, 0x5E9470F8, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuareadvalueidclear  PFOPCUAREADVALUEIDCLEAR_IEC pfopcuareadvalueidclear;
	#define EXT_opcuareadvalueidclear  extern PFOPCUAREADVALUEIDCLEAR_IEC pfopcuareadvalueidclear;
	#define GET_opcuareadvalueidclear(fl)  s_pfCMGetAPI2( "opcuareadvalueidclear", (RTS_VOID_FCTPTR *)&pfopcuareadvalueidclear, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x5E9470F8, 0x03051000)
	#define CAL_opcuareadvalueidclear  pfopcuareadvalueidclear
	#define CHK_opcuareadvalueidclear  (pfopcuareadvalueidclear != NULL)
	#define EXP_opcuareadvalueidclear   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuareadvalueidclear", (RTS_UINTPTR)opcuareadvalueidclear, 1, 0x5E9470F8, 0x03051000) 
#endif


/**
 * <description>opcuareadvalueidinitialize</description>
 */
typedef struct tagopcuareadvalueidinitialize_struct
{
	OpcUa_ReadValueId *pValue;			/* VAR_INPUT */	
} opcuareadvalueidinitialize_struct;

void CDECL CDECL_EXT opcuareadvalueidinitialize(opcuareadvalueidinitialize_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAREADVALUEIDINITIALIZE_IEC) (opcuareadvalueidinitialize_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAREADVALUEIDINITIALIZE_NOTIMPLEMENTED)
	#define USE_opcuareadvalueidinitialize
	#define EXT_opcuareadvalueidinitialize
	#define GET_opcuareadvalueidinitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuareadvalueidinitialize(p0) 
	#define CHK_opcuareadvalueidinitialize  FALSE
	#define EXP_opcuareadvalueidinitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuareadvalueidinitialize
	#define EXT_opcuareadvalueidinitialize
	#define GET_opcuareadvalueidinitialize(fl)  CAL_CMGETAPI( "opcuareadvalueidinitialize" ) 
	#define CAL_opcuareadvalueidinitialize  opcuareadvalueidinitialize
	#define CHK_opcuareadvalueidinitialize  TRUE
	#define EXP_opcuareadvalueidinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuareadvalueidinitialize", (RTS_UINTPTR)opcuareadvalueidinitialize, 1, 0x35E54342, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuareadvalueidinitialize
	#define EXT_opcuareadvalueidinitialize
	#define GET_opcuareadvalueidinitialize(fl)  CAL_CMGETAPI( "opcuareadvalueidinitialize" ) 
	#define CAL_opcuareadvalueidinitialize  opcuareadvalueidinitialize
	#define CHK_opcuareadvalueidinitialize  TRUE
	#define EXP_opcuareadvalueidinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuareadvalueidinitialize", (RTS_UINTPTR)opcuareadvalueidinitialize, 1, 0x35E54342, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuareadvalueidinitialize
	#define EXT_CmpOPCUAStack_Implementationopcuareadvalueidinitialize
	#define GET_CmpOPCUAStack_Implementationopcuareadvalueidinitialize  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuareadvalueidinitialize  opcuareadvalueidinitialize
	#define CHK_CmpOPCUAStack_Implementationopcuareadvalueidinitialize  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuareadvalueidinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuareadvalueidinitialize", (RTS_UINTPTR)opcuareadvalueidinitialize, 1, 0x35E54342, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuareadvalueidinitialize
	#define EXT_opcuareadvalueidinitialize
	#define GET_opcuareadvalueidinitialize(fl)  CAL_CMGETAPI( "opcuareadvalueidinitialize" ) 
	#define CAL_opcuareadvalueidinitialize  opcuareadvalueidinitialize
	#define CHK_opcuareadvalueidinitialize  TRUE
	#define EXP_opcuareadvalueidinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuareadvalueidinitialize", (RTS_UINTPTR)opcuareadvalueidinitialize, 1, 0x35E54342, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuareadvalueidinitialize  PFOPCUAREADVALUEIDINITIALIZE_IEC pfopcuareadvalueidinitialize;
	#define EXT_opcuareadvalueidinitialize  extern PFOPCUAREADVALUEIDINITIALIZE_IEC pfopcuareadvalueidinitialize;
	#define GET_opcuareadvalueidinitialize(fl)  s_pfCMGetAPI2( "opcuareadvalueidinitialize", (RTS_VOID_FCTPTR *)&pfopcuareadvalueidinitialize, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x35E54342, 0x03051000)
	#define CAL_opcuareadvalueidinitialize  pfopcuareadvalueidinitialize
	#define CHK_opcuareadvalueidinitialize  (pfopcuareadvalueidinitialize != NULL)
	#define EXP_opcuareadvalueidinitialize   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuareadvalueidinitialize", (RTS_UINTPTR)opcuareadvalueidinitialize, 1, 0x35E54342, 0x03051000) 
#endif


/**
 * <description>opcuareferencedescriptionclear</description>
 */
typedef struct tagopcuareferencedescriptionclear_struct
{
	OpcUa_ReferenceDescription *pValue;	/* VAR_INPUT */	
} opcuareferencedescriptionclear_struct;

void CDECL CDECL_EXT opcuareferencedescriptionclear(opcuareferencedescriptionclear_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAREFERENCEDESCRIPTIONCLEAR_IEC) (opcuareferencedescriptionclear_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAREFERENCEDESCRIPTIONCLEAR_NOTIMPLEMENTED)
	#define USE_opcuareferencedescriptionclear
	#define EXT_opcuareferencedescriptionclear
	#define GET_opcuareferencedescriptionclear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuareferencedescriptionclear(p0) 
	#define CHK_opcuareferencedescriptionclear  FALSE
	#define EXP_opcuareferencedescriptionclear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuareferencedescriptionclear
	#define EXT_opcuareferencedescriptionclear
	#define GET_opcuareferencedescriptionclear(fl)  CAL_CMGETAPI( "opcuareferencedescriptionclear" ) 
	#define CAL_opcuareferencedescriptionclear  opcuareferencedescriptionclear
	#define CHK_opcuareferencedescriptionclear  TRUE
	#define EXP_opcuareferencedescriptionclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuareferencedescriptionclear", (RTS_UINTPTR)opcuareferencedescriptionclear, 1, 0xAEB1E23C, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuareferencedescriptionclear
	#define EXT_opcuareferencedescriptionclear
	#define GET_opcuareferencedescriptionclear(fl)  CAL_CMGETAPI( "opcuareferencedescriptionclear" ) 
	#define CAL_opcuareferencedescriptionclear  opcuareferencedescriptionclear
	#define CHK_opcuareferencedescriptionclear  TRUE
	#define EXP_opcuareferencedescriptionclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuareferencedescriptionclear", (RTS_UINTPTR)opcuareferencedescriptionclear, 1, 0xAEB1E23C, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuareferencedescriptionclear
	#define EXT_CmpOPCUAStack_Implementationopcuareferencedescriptionclear
	#define GET_CmpOPCUAStack_Implementationopcuareferencedescriptionclear  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuareferencedescriptionclear  opcuareferencedescriptionclear
	#define CHK_CmpOPCUAStack_Implementationopcuareferencedescriptionclear  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuareferencedescriptionclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuareferencedescriptionclear", (RTS_UINTPTR)opcuareferencedescriptionclear, 1, 0xAEB1E23C, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuareferencedescriptionclear
	#define EXT_opcuareferencedescriptionclear
	#define GET_opcuareferencedescriptionclear(fl)  CAL_CMGETAPI( "opcuareferencedescriptionclear" ) 
	#define CAL_opcuareferencedescriptionclear  opcuareferencedescriptionclear
	#define CHK_opcuareferencedescriptionclear  TRUE
	#define EXP_opcuareferencedescriptionclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuareferencedescriptionclear", (RTS_UINTPTR)opcuareferencedescriptionclear, 1, 0xAEB1E23C, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuareferencedescriptionclear  PFOPCUAREFERENCEDESCRIPTIONCLEAR_IEC pfopcuareferencedescriptionclear;
	#define EXT_opcuareferencedescriptionclear  extern PFOPCUAREFERENCEDESCRIPTIONCLEAR_IEC pfopcuareferencedescriptionclear;
	#define GET_opcuareferencedescriptionclear(fl)  s_pfCMGetAPI2( "opcuareferencedescriptionclear", (RTS_VOID_FCTPTR *)&pfopcuareferencedescriptionclear, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xAEB1E23C, 0x03051000)
	#define CAL_opcuareferencedescriptionclear  pfopcuareferencedescriptionclear
	#define CHK_opcuareferencedescriptionclear  (pfopcuareferencedescriptionclear != NULL)
	#define EXP_opcuareferencedescriptionclear   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuareferencedescriptionclear", (RTS_UINTPTR)opcuareferencedescriptionclear, 1, 0xAEB1E23C, 0x03051000) 
#endif


/**
 * <description>opcuareferencedescriptioninitialize</description>
 */
typedef struct tagopcuareferencedescriptioninitialize_struct
{
	OpcUa_ReferenceDescription *pValue;	/* VAR_INPUT */	
} opcuareferencedescriptioninitialize_struct;

void CDECL CDECL_EXT opcuareferencedescriptioninitialize(opcuareferencedescriptioninitialize_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAREFERENCEDESCRIPTIONINITIALIZE_IEC) (opcuareferencedescriptioninitialize_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAREFERENCEDESCRIPTIONINITIALIZE_NOTIMPLEMENTED)
	#define USE_opcuareferencedescriptioninitialize
	#define EXT_opcuareferencedescriptioninitialize
	#define GET_opcuareferencedescriptioninitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuareferencedescriptioninitialize(p0) 
	#define CHK_opcuareferencedescriptioninitialize  FALSE
	#define EXP_opcuareferencedescriptioninitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuareferencedescriptioninitialize
	#define EXT_opcuareferencedescriptioninitialize
	#define GET_opcuareferencedescriptioninitialize(fl)  CAL_CMGETAPI( "opcuareferencedescriptioninitialize" ) 
	#define CAL_opcuareferencedescriptioninitialize  opcuareferencedescriptioninitialize
	#define CHK_opcuareferencedescriptioninitialize  TRUE
	#define EXP_opcuareferencedescriptioninitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuareferencedescriptioninitialize", (RTS_UINTPTR)opcuareferencedescriptioninitialize, 1, 0xD23622BE, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuareferencedescriptioninitialize
	#define EXT_opcuareferencedescriptioninitialize
	#define GET_opcuareferencedescriptioninitialize(fl)  CAL_CMGETAPI( "opcuareferencedescriptioninitialize" ) 
	#define CAL_opcuareferencedescriptioninitialize  opcuareferencedescriptioninitialize
	#define CHK_opcuareferencedescriptioninitialize  TRUE
	#define EXP_opcuareferencedescriptioninitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuareferencedescriptioninitialize", (RTS_UINTPTR)opcuareferencedescriptioninitialize, 1, 0xD23622BE, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuareferencedescriptioninitialize
	#define EXT_CmpOPCUAStack_Implementationopcuareferencedescriptioninitialize
	#define GET_CmpOPCUAStack_Implementationopcuareferencedescriptioninitialize  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuareferencedescriptioninitialize  opcuareferencedescriptioninitialize
	#define CHK_CmpOPCUAStack_Implementationopcuareferencedescriptioninitialize  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuareferencedescriptioninitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuareferencedescriptioninitialize", (RTS_UINTPTR)opcuareferencedescriptioninitialize, 1, 0xD23622BE, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuareferencedescriptioninitialize
	#define EXT_opcuareferencedescriptioninitialize
	#define GET_opcuareferencedescriptioninitialize(fl)  CAL_CMGETAPI( "opcuareferencedescriptioninitialize" ) 
	#define CAL_opcuareferencedescriptioninitialize  opcuareferencedescriptioninitialize
	#define CHK_opcuareferencedescriptioninitialize  TRUE
	#define EXP_opcuareferencedescriptioninitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuareferencedescriptioninitialize", (RTS_UINTPTR)opcuareferencedescriptioninitialize, 1, 0xD23622BE, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuareferencedescriptioninitialize  PFOPCUAREFERENCEDESCRIPTIONINITIALIZE_IEC pfopcuareferencedescriptioninitialize;
	#define EXT_opcuareferencedescriptioninitialize  extern PFOPCUAREFERENCEDESCRIPTIONINITIALIZE_IEC pfopcuareferencedescriptioninitialize;
	#define GET_opcuareferencedescriptioninitialize(fl)  s_pfCMGetAPI2( "opcuareferencedescriptioninitialize", (RTS_VOID_FCTPTR *)&pfopcuareferencedescriptioninitialize, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xD23622BE, 0x03051000)
	#define CAL_opcuareferencedescriptioninitialize  pfopcuareferencedescriptioninitialize
	#define CHK_opcuareferencedescriptioninitialize  (pfopcuareferencedescriptioninitialize != NULL)
	#define EXP_opcuareferencedescriptioninitialize   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuareferencedescriptioninitialize", (RTS_UINTPTR)opcuareferencedescriptioninitialize, 1, 0xD23622BE, 0x03051000) 
#endif


/**
 * <description>opcuaserveronnetworkclear</description>
 */
typedef struct tagopcuaserveronnetworkclear_struct
{
	OpcUa_ServerOnNetwork *pValue;		/* VAR_INPUT */	
} opcuaserveronnetworkclear_struct;

void CDECL CDECL_EXT opcuaserveronnetworkclear(opcuaserveronnetworkclear_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUASERVERONNETWORKCLEAR_IEC) (opcuaserveronnetworkclear_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUASERVERONNETWORKCLEAR_NOTIMPLEMENTED)
	#define USE_opcuaserveronnetworkclear
	#define EXT_opcuaserveronnetworkclear
	#define GET_opcuaserveronnetworkclear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaserveronnetworkclear(p0) 
	#define CHK_opcuaserveronnetworkclear  FALSE
	#define EXP_opcuaserveronnetworkclear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaserveronnetworkclear
	#define EXT_opcuaserveronnetworkclear
	#define GET_opcuaserveronnetworkclear(fl)  CAL_CMGETAPI( "opcuaserveronnetworkclear" ) 
	#define CAL_opcuaserveronnetworkclear  opcuaserveronnetworkclear
	#define CHK_opcuaserveronnetworkclear  TRUE
	#define EXP_opcuaserveronnetworkclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaserveronnetworkclear", (RTS_UINTPTR)opcuaserveronnetworkclear, 1, 0xC1857568, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaserveronnetworkclear
	#define EXT_opcuaserveronnetworkclear
	#define GET_opcuaserveronnetworkclear(fl)  CAL_CMGETAPI( "opcuaserveronnetworkclear" ) 
	#define CAL_opcuaserveronnetworkclear  opcuaserveronnetworkclear
	#define CHK_opcuaserveronnetworkclear  TRUE
	#define EXP_opcuaserveronnetworkclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaserveronnetworkclear", (RTS_UINTPTR)opcuaserveronnetworkclear, 1, 0xC1857568, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuaserveronnetworkclear
	#define EXT_CmpOPCUAStack_Implementationopcuaserveronnetworkclear
	#define GET_CmpOPCUAStack_Implementationopcuaserveronnetworkclear  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuaserveronnetworkclear  opcuaserveronnetworkclear
	#define CHK_CmpOPCUAStack_Implementationopcuaserveronnetworkclear  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuaserveronnetworkclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaserveronnetworkclear", (RTS_UINTPTR)opcuaserveronnetworkclear, 1, 0xC1857568, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaserveronnetworkclear
	#define EXT_opcuaserveronnetworkclear
	#define GET_opcuaserveronnetworkclear(fl)  CAL_CMGETAPI( "opcuaserveronnetworkclear" ) 
	#define CAL_opcuaserveronnetworkclear  opcuaserveronnetworkclear
	#define CHK_opcuaserveronnetworkclear  TRUE
	#define EXP_opcuaserveronnetworkclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaserveronnetworkclear", (RTS_UINTPTR)opcuaserveronnetworkclear, 1, 0xC1857568, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaserveronnetworkclear  PFOPCUASERVERONNETWORKCLEAR_IEC pfopcuaserveronnetworkclear;
	#define EXT_opcuaserveronnetworkclear  extern PFOPCUASERVERONNETWORKCLEAR_IEC pfopcuaserveronnetworkclear;
	#define GET_opcuaserveronnetworkclear(fl)  s_pfCMGetAPI2( "opcuaserveronnetworkclear", (RTS_VOID_FCTPTR *)&pfopcuaserveronnetworkclear, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xC1857568, 0x03051000)
	#define CAL_opcuaserveronnetworkclear  pfopcuaserveronnetworkclear
	#define CHK_opcuaserveronnetworkclear  (pfopcuaserveronnetworkclear != NULL)
	#define EXP_opcuaserveronnetworkclear   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaserveronnetworkclear", (RTS_UINTPTR)opcuaserveronnetworkclear, 1, 0xC1857568, 0x03051000) 
#endif


/**
 * <description>opcuaserveronnetworkinitialize</description>
 */
typedef struct tagopcuaserveronnetworkinitialize_struct
{
	OpcUa_ServerOnNetwork *pValue;		/* VAR_INPUT */	
} opcuaserveronnetworkinitialize_struct;

void CDECL CDECL_EXT opcuaserveronnetworkinitialize(opcuaserveronnetworkinitialize_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUASERVERONNETWORKINITIALIZE_IEC) (opcuaserveronnetworkinitialize_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUASERVERONNETWORKINITIALIZE_NOTIMPLEMENTED)
	#define USE_opcuaserveronnetworkinitialize
	#define EXT_opcuaserveronnetworkinitialize
	#define GET_opcuaserveronnetworkinitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuaserveronnetworkinitialize(p0) 
	#define CHK_opcuaserveronnetworkinitialize  FALSE
	#define EXP_opcuaserveronnetworkinitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuaserveronnetworkinitialize
	#define EXT_opcuaserveronnetworkinitialize
	#define GET_opcuaserveronnetworkinitialize(fl)  CAL_CMGETAPI( "opcuaserveronnetworkinitialize" ) 
	#define CAL_opcuaserveronnetworkinitialize  opcuaserveronnetworkinitialize
	#define CHK_opcuaserveronnetworkinitialize  TRUE
	#define EXP_opcuaserveronnetworkinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaserveronnetworkinitialize", (RTS_UINTPTR)opcuaserveronnetworkinitialize, 1, 0x75110575, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuaserveronnetworkinitialize
	#define EXT_opcuaserveronnetworkinitialize
	#define GET_opcuaserveronnetworkinitialize(fl)  CAL_CMGETAPI( "opcuaserveronnetworkinitialize" ) 
	#define CAL_opcuaserveronnetworkinitialize  opcuaserveronnetworkinitialize
	#define CHK_opcuaserveronnetworkinitialize  TRUE
	#define EXP_opcuaserveronnetworkinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaserveronnetworkinitialize", (RTS_UINTPTR)opcuaserveronnetworkinitialize, 1, 0x75110575, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuaserveronnetworkinitialize
	#define EXT_CmpOPCUAStack_Implementationopcuaserveronnetworkinitialize
	#define GET_CmpOPCUAStack_Implementationopcuaserveronnetworkinitialize  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuaserveronnetworkinitialize  opcuaserveronnetworkinitialize
	#define CHK_CmpOPCUAStack_Implementationopcuaserveronnetworkinitialize  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuaserveronnetworkinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaserveronnetworkinitialize", (RTS_UINTPTR)opcuaserveronnetworkinitialize, 1, 0x75110575, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuaserveronnetworkinitialize
	#define EXT_opcuaserveronnetworkinitialize
	#define GET_opcuaserveronnetworkinitialize(fl)  CAL_CMGETAPI( "opcuaserveronnetworkinitialize" ) 
	#define CAL_opcuaserveronnetworkinitialize  opcuaserveronnetworkinitialize
	#define CHK_opcuaserveronnetworkinitialize  TRUE
	#define EXP_opcuaserveronnetworkinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaserveronnetworkinitialize", (RTS_UINTPTR)opcuaserveronnetworkinitialize, 1, 0x75110575, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuaserveronnetworkinitialize  PFOPCUASERVERONNETWORKINITIALIZE_IEC pfopcuaserveronnetworkinitialize;
	#define EXT_opcuaserveronnetworkinitialize  extern PFOPCUASERVERONNETWORKINITIALIZE_IEC pfopcuaserveronnetworkinitialize;
	#define GET_opcuaserveronnetworkinitialize(fl)  s_pfCMGetAPI2( "opcuaserveronnetworkinitialize", (RTS_VOID_FCTPTR *)&pfopcuaserveronnetworkinitialize, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x75110575, 0x03051000)
	#define CAL_opcuaserveronnetworkinitialize  pfopcuaserveronnetworkinitialize
	#define CHK_opcuaserveronnetworkinitialize  (pfopcuaserveronnetworkinitialize != NULL)
	#define EXP_opcuaserveronnetworkinitialize   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuaserveronnetworkinitialize", (RTS_UINTPTR)opcuaserveronnetworkinitialize, 1, 0x75110575, 0x03051000) 
#endif


/**
 * <description>opcuasimpleattributeoperandclear</description>
 */
typedef struct tagopcuasimpleattributeoperandclear_struct
{
	OpcUa_SimpleAttributeOperand *pValue;	/* VAR_INPUT */	
} opcuasimpleattributeoperandclear_struct;

void CDECL CDECL_EXT opcuasimpleattributeoperandclear(opcuasimpleattributeoperandclear_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUASIMPLEATTRIBUTEOPERANDCLEAR_IEC) (opcuasimpleattributeoperandclear_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUASIMPLEATTRIBUTEOPERANDCLEAR_NOTIMPLEMENTED)
	#define USE_opcuasimpleattributeoperandclear
	#define EXT_opcuasimpleattributeoperandclear
	#define GET_opcuasimpleattributeoperandclear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuasimpleattributeoperandclear(p0) 
	#define CHK_opcuasimpleattributeoperandclear  FALSE
	#define EXP_opcuasimpleattributeoperandclear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuasimpleattributeoperandclear
	#define EXT_opcuasimpleattributeoperandclear
	#define GET_opcuasimpleattributeoperandclear(fl)  CAL_CMGETAPI( "opcuasimpleattributeoperandclear" ) 
	#define CAL_opcuasimpleattributeoperandclear  opcuasimpleattributeoperandclear
	#define CHK_opcuasimpleattributeoperandclear  TRUE
	#define EXP_opcuasimpleattributeoperandclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuasimpleattributeoperandclear", (RTS_UINTPTR)opcuasimpleattributeoperandclear, 1, 0xED624E6B, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuasimpleattributeoperandclear
	#define EXT_opcuasimpleattributeoperandclear
	#define GET_opcuasimpleattributeoperandclear(fl)  CAL_CMGETAPI( "opcuasimpleattributeoperandclear" ) 
	#define CAL_opcuasimpleattributeoperandclear  opcuasimpleattributeoperandclear
	#define CHK_opcuasimpleattributeoperandclear  TRUE
	#define EXP_opcuasimpleattributeoperandclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuasimpleattributeoperandclear", (RTS_UINTPTR)opcuasimpleattributeoperandclear, 1, 0xED624E6B, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuasimpleattributeoperandclear
	#define EXT_CmpOPCUAStack_Implementationopcuasimpleattributeoperandclear
	#define GET_CmpOPCUAStack_Implementationopcuasimpleattributeoperandclear  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuasimpleattributeoperandclear  opcuasimpleattributeoperandclear
	#define CHK_CmpOPCUAStack_Implementationopcuasimpleattributeoperandclear  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuasimpleattributeoperandclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuasimpleattributeoperandclear", (RTS_UINTPTR)opcuasimpleattributeoperandclear, 1, 0xED624E6B, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuasimpleattributeoperandclear
	#define EXT_opcuasimpleattributeoperandclear
	#define GET_opcuasimpleattributeoperandclear(fl)  CAL_CMGETAPI( "opcuasimpleattributeoperandclear" ) 
	#define CAL_opcuasimpleattributeoperandclear  opcuasimpleattributeoperandclear
	#define CHK_opcuasimpleattributeoperandclear  TRUE
	#define EXP_opcuasimpleattributeoperandclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuasimpleattributeoperandclear", (RTS_UINTPTR)opcuasimpleattributeoperandclear, 1, 0xED624E6B, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuasimpleattributeoperandclear  PFOPCUASIMPLEATTRIBUTEOPERANDCLEAR_IEC pfopcuasimpleattributeoperandclear;
	#define EXT_opcuasimpleattributeoperandclear  extern PFOPCUASIMPLEATTRIBUTEOPERANDCLEAR_IEC pfopcuasimpleattributeoperandclear;
	#define GET_opcuasimpleattributeoperandclear(fl)  s_pfCMGetAPI2( "opcuasimpleattributeoperandclear", (RTS_VOID_FCTPTR *)&pfopcuasimpleattributeoperandclear, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xED624E6B, 0x03051000)
	#define CAL_opcuasimpleattributeoperandclear  pfopcuasimpleattributeoperandclear
	#define CHK_opcuasimpleattributeoperandclear  (pfopcuasimpleattributeoperandclear != NULL)
	#define EXP_opcuasimpleattributeoperandclear   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuasimpleattributeoperandclear", (RTS_UINTPTR)opcuasimpleattributeoperandclear, 1, 0xED624E6B, 0x03051000) 
#endif


/**
 * <description>opcuasimpleattributeoperandinitialize</description>
 */
typedef struct tagopcuasimpleattributeoperandinitialize_struct
{
	OpcUa_SimpleAttributeOperand *pValue;	/* VAR_INPUT */	
} opcuasimpleattributeoperandinitialize_struct;

void CDECL CDECL_EXT opcuasimpleattributeoperandinitialize(opcuasimpleattributeoperandinitialize_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUASIMPLEATTRIBUTEOPERANDINITIALIZE_IEC) (opcuasimpleattributeoperandinitialize_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUASIMPLEATTRIBUTEOPERANDINITIALIZE_NOTIMPLEMENTED)
	#define USE_opcuasimpleattributeoperandinitialize
	#define EXT_opcuasimpleattributeoperandinitialize
	#define GET_opcuasimpleattributeoperandinitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuasimpleattributeoperandinitialize(p0) 
	#define CHK_opcuasimpleattributeoperandinitialize  FALSE
	#define EXP_opcuasimpleattributeoperandinitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuasimpleattributeoperandinitialize
	#define EXT_opcuasimpleattributeoperandinitialize
	#define GET_opcuasimpleattributeoperandinitialize(fl)  CAL_CMGETAPI( "opcuasimpleattributeoperandinitialize" ) 
	#define CAL_opcuasimpleattributeoperandinitialize  opcuasimpleattributeoperandinitialize
	#define CHK_opcuasimpleattributeoperandinitialize  TRUE
	#define EXP_opcuasimpleattributeoperandinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuasimpleattributeoperandinitialize", (RTS_UINTPTR)opcuasimpleattributeoperandinitialize, 1, 0x81CA1989, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuasimpleattributeoperandinitialize
	#define EXT_opcuasimpleattributeoperandinitialize
	#define GET_opcuasimpleattributeoperandinitialize(fl)  CAL_CMGETAPI( "opcuasimpleattributeoperandinitialize" ) 
	#define CAL_opcuasimpleattributeoperandinitialize  opcuasimpleattributeoperandinitialize
	#define CHK_opcuasimpleattributeoperandinitialize  TRUE
	#define EXP_opcuasimpleattributeoperandinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuasimpleattributeoperandinitialize", (RTS_UINTPTR)opcuasimpleattributeoperandinitialize, 1, 0x81CA1989, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuasimpleattributeoperandinitialize
	#define EXT_CmpOPCUAStack_Implementationopcuasimpleattributeoperandinitialize
	#define GET_CmpOPCUAStack_Implementationopcuasimpleattributeoperandinitialize  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuasimpleattributeoperandinitialize  opcuasimpleattributeoperandinitialize
	#define CHK_CmpOPCUAStack_Implementationopcuasimpleattributeoperandinitialize  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuasimpleattributeoperandinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuasimpleattributeoperandinitialize", (RTS_UINTPTR)opcuasimpleattributeoperandinitialize, 1, 0x81CA1989, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuasimpleattributeoperandinitialize
	#define EXT_opcuasimpleattributeoperandinitialize
	#define GET_opcuasimpleattributeoperandinitialize(fl)  CAL_CMGETAPI( "opcuasimpleattributeoperandinitialize" ) 
	#define CAL_opcuasimpleattributeoperandinitialize  opcuasimpleattributeoperandinitialize
	#define CHK_opcuasimpleattributeoperandinitialize  TRUE
	#define EXP_opcuasimpleattributeoperandinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuasimpleattributeoperandinitialize", (RTS_UINTPTR)opcuasimpleattributeoperandinitialize, 1, 0x81CA1989, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuasimpleattributeoperandinitialize  PFOPCUASIMPLEATTRIBUTEOPERANDINITIALIZE_IEC pfopcuasimpleattributeoperandinitialize;
	#define EXT_opcuasimpleattributeoperandinitialize  extern PFOPCUASIMPLEATTRIBUTEOPERANDINITIALIZE_IEC pfopcuasimpleattributeoperandinitialize;
	#define GET_opcuasimpleattributeoperandinitialize(fl)  s_pfCMGetAPI2( "opcuasimpleattributeoperandinitialize", (RTS_VOID_FCTPTR *)&pfopcuasimpleattributeoperandinitialize, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x81CA1989, 0x03051000)
	#define CAL_opcuasimpleattributeoperandinitialize  pfopcuasimpleattributeoperandinitialize
	#define CHK_opcuasimpleattributeoperandinitialize  (pfopcuasimpleattributeoperandinitialize != NULL)
	#define EXP_opcuasimpleattributeoperandinitialize   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuasimpleattributeoperandinitialize", (RTS_UINTPTR)opcuasimpleattributeoperandinitialize, 1, 0x81CA1989, 0x03051000) 
#endif


/**
 * <description>opcuastatuschangenotificationclear</description>
 */
typedef struct tagopcuastatuschangenotificationclear_struct
{
	OpcUa_StatusChangeNotification *pValue;	/* VAR_INPUT */	
} opcuastatuschangenotificationclear_struct;

void CDECL CDECL_EXT opcuastatuschangenotificationclear(opcuastatuschangenotificationclear_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUASTATUSCHANGENOTIFICATIONCLEAR_IEC) (opcuastatuschangenotificationclear_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUASTATUSCHANGENOTIFICATIONCLEAR_NOTIMPLEMENTED)
	#define USE_opcuastatuschangenotificationclear
	#define EXT_opcuastatuschangenotificationclear
	#define GET_opcuastatuschangenotificationclear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuastatuschangenotificationclear(p0) 
	#define CHK_opcuastatuschangenotificationclear  FALSE
	#define EXP_opcuastatuschangenotificationclear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuastatuschangenotificationclear
	#define EXT_opcuastatuschangenotificationclear
	#define GET_opcuastatuschangenotificationclear(fl)  CAL_CMGETAPI( "opcuastatuschangenotificationclear" ) 
	#define CAL_opcuastatuschangenotificationclear  opcuastatuschangenotificationclear
	#define CHK_opcuastatuschangenotificationclear  TRUE
	#define EXP_opcuastatuschangenotificationclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastatuschangenotificationclear", (RTS_UINTPTR)opcuastatuschangenotificationclear, 1, 0xE76BFA42, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuastatuschangenotificationclear
	#define EXT_opcuastatuschangenotificationclear
	#define GET_opcuastatuschangenotificationclear(fl)  CAL_CMGETAPI( "opcuastatuschangenotificationclear" ) 
	#define CAL_opcuastatuschangenotificationclear  opcuastatuschangenotificationclear
	#define CHK_opcuastatuschangenotificationclear  TRUE
	#define EXP_opcuastatuschangenotificationclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastatuschangenotificationclear", (RTS_UINTPTR)opcuastatuschangenotificationclear, 1, 0xE76BFA42, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuastatuschangenotificationclear
	#define EXT_CmpOPCUAStack_Implementationopcuastatuschangenotificationclear
	#define GET_CmpOPCUAStack_Implementationopcuastatuschangenotificationclear  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuastatuschangenotificationclear  opcuastatuschangenotificationclear
	#define CHK_CmpOPCUAStack_Implementationopcuastatuschangenotificationclear  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuastatuschangenotificationclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastatuschangenotificationclear", (RTS_UINTPTR)opcuastatuschangenotificationclear, 1, 0xE76BFA42, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuastatuschangenotificationclear
	#define EXT_opcuastatuschangenotificationclear
	#define GET_opcuastatuschangenotificationclear(fl)  CAL_CMGETAPI( "opcuastatuschangenotificationclear" ) 
	#define CAL_opcuastatuschangenotificationclear  opcuastatuschangenotificationclear
	#define CHK_opcuastatuschangenotificationclear  TRUE
	#define EXP_opcuastatuschangenotificationclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastatuschangenotificationclear", (RTS_UINTPTR)opcuastatuschangenotificationclear, 1, 0xE76BFA42, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuastatuschangenotificationclear  PFOPCUASTATUSCHANGENOTIFICATIONCLEAR_IEC pfopcuastatuschangenotificationclear;
	#define EXT_opcuastatuschangenotificationclear  extern PFOPCUASTATUSCHANGENOTIFICATIONCLEAR_IEC pfopcuastatuschangenotificationclear;
	#define GET_opcuastatuschangenotificationclear(fl)  s_pfCMGetAPI2( "opcuastatuschangenotificationclear", (RTS_VOID_FCTPTR *)&pfopcuastatuschangenotificationclear, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xE76BFA42, 0x03051000)
	#define CAL_opcuastatuschangenotificationclear  pfopcuastatuschangenotificationclear
	#define CHK_opcuastatuschangenotificationclear  (pfopcuastatuschangenotificationclear != NULL)
	#define EXP_opcuastatuschangenotificationclear   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastatuschangenotificationclear", (RTS_UINTPTR)opcuastatuschangenotificationclear, 1, 0xE76BFA42, 0x03051000) 
#endif


/**
 * <description>opcuastatuschangenotificationinitialize</description>
 */
typedef struct tagopcuastatuschangenotificationinitialize_struct
{
	OpcUa_StatusChangeNotification *pValue;	/* VAR_INPUT */	
} opcuastatuschangenotificationinitialize_struct;

void CDECL CDECL_EXT opcuastatuschangenotificationinitialize(opcuastatuschangenotificationinitialize_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUASTATUSCHANGENOTIFICATIONINITIALIZE_IEC) (opcuastatuschangenotificationinitialize_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUASTATUSCHANGENOTIFICATIONINITIALIZE_NOTIMPLEMENTED)
	#define USE_opcuastatuschangenotificationinitialize
	#define EXT_opcuastatuschangenotificationinitialize
	#define GET_opcuastatuschangenotificationinitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuastatuschangenotificationinitialize(p0) 
	#define CHK_opcuastatuschangenotificationinitialize  FALSE
	#define EXP_opcuastatuschangenotificationinitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuastatuschangenotificationinitialize
	#define EXT_opcuastatuschangenotificationinitialize
	#define GET_opcuastatuschangenotificationinitialize(fl)  CAL_CMGETAPI( "opcuastatuschangenotificationinitialize" ) 
	#define CAL_opcuastatuschangenotificationinitialize  opcuastatuschangenotificationinitialize
	#define CHK_opcuastatuschangenotificationinitialize  TRUE
	#define EXP_opcuastatuschangenotificationinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastatuschangenotificationinitialize", (RTS_UINTPTR)opcuastatuschangenotificationinitialize, 1, 0x32A3D102, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuastatuschangenotificationinitialize
	#define EXT_opcuastatuschangenotificationinitialize
	#define GET_opcuastatuschangenotificationinitialize(fl)  CAL_CMGETAPI( "opcuastatuschangenotificationinitialize" ) 
	#define CAL_opcuastatuschangenotificationinitialize  opcuastatuschangenotificationinitialize
	#define CHK_opcuastatuschangenotificationinitialize  TRUE
	#define EXP_opcuastatuschangenotificationinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastatuschangenotificationinitialize", (RTS_UINTPTR)opcuastatuschangenotificationinitialize, 1, 0x32A3D102, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuastatuschangenotificationinitialize
	#define EXT_CmpOPCUAStack_Implementationopcuastatuschangenotificationinitialize
	#define GET_CmpOPCUAStack_Implementationopcuastatuschangenotificationinitialize  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuastatuschangenotificationinitialize  opcuastatuschangenotificationinitialize
	#define CHK_CmpOPCUAStack_Implementationopcuastatuschangenotificationinitialize  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuastatuschangenotificationinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastatuschangenotificationinitialize", (RTS_UINTPTR)opcuastatuschangenotificationinitialize, 1, 0x32A3D102, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuastatuschangenotificationinitialize
	#define EXT_opcuastatuschangenotificationinitialize
	#define GET_opcuastatuschangenotificationinitialize(fl)  CAL_CMGETAPI( "opcuastatuschangenotificationinitialize" ) 
	#define CAL_opcuastatuschangenotificationinitialize  opcuastatuschangenotificationinitialize
	#define CHK_opcuastatuschangenotificationinitialize  TRUE
	#define EXP_opcuastatuschangenotificationinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastatuschangenotificationinitialize", (RTS_UINTPTR)opcuastatuschangenotificationinitialize, 1, 0x32A3D102, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuastatuschangenotificationinitialize  PFOPCUASTATUSCHANGENOTIFICATIONINITIALIZE_IEC pfopcuastatuschangenotificationinitialize;
	#define EXT_opcuastatuschangenotificationinitialize  extern PFOPCUASTATUSCHANGENOTIFICATIONINITIALIZE_IEC pfopcuastatuschangenotificationinitialize;
	#define GET_opcuastatuschangenotificationinitialize(fl)  s_pfCMGetAPI2( "opcuastatuschangenotificationinitialize", (RTS_VOID_FCTPTR *)&pfopcuastatuschangenotificationinitialize, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x32A3D102, 0x03051000)
	#define CAL_opcuastatuschangenotificationinitialize  pfopcuastatuschangenotificationinitialize
	#define CHK_opcuastatuschangenotificationinitialize  (pfopcuastatuschangenotificationinitialize != NULL)
	#define EXP_opcuastatuschangenotificationinitialize   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastatuschangenotificationinitialize", (RTS_UINTPTR)opcuastatuschangenotificationinitialize, 1, 0x32A3D102, 0x03051000) 
#endif


/**
 * <description>opcuastringattachcopy</description>
 */
typedef struct tagopcuastringattachcopy_struct
{
	OpcUa_String *pDst;					/* VAR_INPUT */	
	RTS_IEC_SINT *pSrc;					/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaStringAttachCopy;	/* VAR_OUTPUT */	
} opcuastringattachcopy_struct;

void CDECL CDECL_EXT opcuastringattachcopy(opcuastringattachcopy_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUASTRINGATTACHCOPY_IEC) (opcuastringattachcopy_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUASTRINGATTACHCOPY_NOTIMPLEMENTED)
	#define USE_opcuastringattachcopy
	#define EXT_opcuastringattachcopy
	#define GET_opcuastringattachcopy(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuastringattachcopy(p0) 
	#define CHK_opcuastringattachcopy  FALSE
	#define EXP_opcuastringattachcopy  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuastringattachcopy
	#define EXT_opcuastringattachcopy
	#define GET_opcuastringattachcopy(fl)  CAL_CMGETAPI( "opcuastringattachcopy" ) 
	#define CAL_opcuastringattachcopy  opcuastringattachcopy
	#define CHK_opcuastringattachcopy  TRUE
	#define EXP_opcuastringattachcopy  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringattachcopy", (RTS_UINTPTR)opcuastringattachcopy, 1, 0x309DD3C4, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuastringattachcopy
	#define EXT_opcuastringattachcopy
	#define GET_opcuastringattachcopy(fl)  CAL_CMGETAPI( "opcuastringattachcopy" ) 
	#define CAL_opcuastringattachcopy  opcuastringattachcopy
	#define CHK_opcuastringattachcopy  TRUE
	#define EXP_opcuastringattachcopy  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringattachcopy", (RTS_UINTPTR)opcuastringattachcopy, 1, 0x309DD3C4, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuastringattachcopy
	#define EXT_CmpOPCUAStack_Implementationopcuastringattachcopy
	#define GET_CmpOPCUAStack_Implementationopcuastringattachcopy  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuastringattachcopy  opcuastringattachcopy
	#define CHK_CmpOPCUAStack_Implementationopcuastringattachcopy  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuastringattachcopy  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringattachcopy", (RTS_UINTPTR)opcuastringattachcopy, 1, 0x309DD3C4, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuastringattachcopy
	#define EXT_opcuastringattachcopy
	#define GET_opcuastringattachcopy(fl)  CAL_CMGETAPI( "opcuastringattachcopy" ) 
	#define CAL_opcuastringattachcopy  opcuastringattachcopy
	#define CHK_opcuastringattachcopy  TRUE
	#define EXP_opcuastringattachcopy  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringattachcopy", (RTS_UINTPTR)opcuastringattachcopy, 1, 0x309DD3C4, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuastringattachcopy  PFOPCUASTRINGATTACHCOPY_IEC pfopcuastringattachcopy;
	#define EXT_opcuastringattachcopy  extern PFOPCUASTRINGATTACHCOPY_IEC pfopcuastringattachcopy;
	#define GET_opcuastringattachcopy(fl)  s_pfCMGetAPI2( "opcuastringattachcopy", (RTS_VOID_FCTPTR *)&pfopcuastringattachcopy, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x309DD3C4, 0x03051000)
	#define CAL_opcuastringattachcopy  pfopcuastringattachcopy
	#define CHK_opcuastringattachcopy  (pfopcuastringattachcopy != NULL)
	#define EXP_opcuastringattachcopy   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringattachcopy", (RTS_UINTPTR)opcuastringattachcopy, 1, 0x309DD3C4, 0x03051000) 
#endif


/**
 * <description>opcuastringattachreadonly</description>
 */
typedef struct tagopcuastringattachreadonly_struct
{
	OpcUa_String *pDst;					/* VAR_INPUT */	
	RTS_IEC_SINT *pSrc;					/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaStringAttachReadOnly;	/* VAR_OUTPUT */	
} opcuastringattachreadonly_struct;

void CDECL CDECL_EXT opcuastringattachreadonly(opcuastringattachreadonly_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUASTRINGATTACHREADONLY_IEC) (opcuastringattachreadonly_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUASTRINGATTACHREADONLY_NOTIMPLEMENTED)
	#define USE_opcuastringattachreadonly
	#define EXT_opcuastringattachreadonly
	#define GET_opcuastringattachreadonly(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuastringattachreadonly(p0) 
	#define CHK_opcuastringattachreadonly  FALSE
	#define EXP_opcuastringattachreadonly  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuastringattachreadonly
	#define EXT_opcuastringattachreadonly
	#define GET_opcuastringattachreadonly(fl)  CAL_CMGETAPI( "opcuastringattachreadonly" ) 
	#define CAL_opcuastringattachreadonly  opcuastringattachreadonly
	#define CHK_opcuastringattachreadonly  TRUE
	#define EXP_opcuastringattachreadonly  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringattachreadonly", (RTS_UINTPTR)opcuastringattachreadonly, 1, 0x108C50FB, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuastringattachreadonly
	#define EXT_opcuastringattachreadonly
	#define GET_opcuastringattachreadonly(fl)  CAL_CMGETAPI( "opcuastringattachreadonly" ) 
	#define CAL_opcuastringattachreadonly  opcuastringattachreadonly
	#define CHK_opcuastringattachreadonly  TRUE
	#define EXP_opcuastringattachreadonly  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringattachreadonly", (RTS_UINTPTR)opcuastringattachreadonly, 1, 0x108C50FB, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuastringattachreadonly
	#define EXT_CmpOPCUAStack_Implementationopcuastringattachreadonly
	#define GET_CmpOPCUAStack_Implementationopcuastringattachreadonly  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuastringattachreadonly  opcuastringattachreadonly
	#define CHK_CmpOPCUAStack_Implementationopcuastringattachreadonly  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuastringattachreadonly  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringattachreadonly", (RTS_UINTPTR)opcuastringattachreadonly, 1, 0x108C50FB, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuastringattachreadonly
	#define EXT_opcuastringattachreadonly
	#define GET_opcuastringattachreadonly(fl)  CAL_CMGETAPI( "opcuastringattachreadonly" ) 
	#define CAL_opcuastringattachreadonly  opcuastringattachreadonly
	#define CHK_opcuastringattachreadonly  TRUE
	#define EXP_opcuastringattachreadonly  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringattachreadonly", (RTS_UINTPTR)opcuastringattachreadonly, 1, 0x108C50FB, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuastringattachreadonly  PFOPCUASTRINGATTACHREADONLY_IEC pfopcuastringattachreadonly;
	#define EXT_opcuastringattachreadonly  extern PFOPCUASTRINGATTACHREADONLY_IEC pfopcuastringattachreadonly;
	#define GET_opcuastringattachreadonly(fl)  s_pfCMGetAPI2( "opcuastringattachreadonly", (RTS_VOID_FCTPTR *)&pfopcuastringattachreadonly, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x108C50FB, 0x03051000)
	#define CAL_opcuastringattachreadonly  pfopcuastringattachreadonly
	#define CHK_opcuastringattachreadonly  (pfopcuastringattachreadonly != NULL)
	#define EXP_opcuastringattachreadonly   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringattachreadonly", (RTS_UINTPTR)opcuastringattachreadonly, 1, 0x108C50FB, 0x03051000) 
#endif


/**
 * <description>opcuastringattachtostring</description>
 */
typedef struct tagopcuastringattachtostring_struct
{
	RTS_IEC_BYTE *strSource;			/* VAR_INPUT */	
	RTS_IEC_UDINT uLength;				/* VAR_INPUT */	
	RTS_IEC_UDINT uBufferSize;			/* VAR_INPUT */	
	RTS_IEC_BYTE bDoCopy;				/* VAR_INPUT */	
	RTS_IEC_BYTE bFreeOnClear;			/* VAR_INPUT */	
	OpcUa_String *pString;				/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaStringAttachToString;	/* VAR_OUTPUT */	
} opcuastringattachtostring_struct;

void CDECL CDECL_EXT opcuastringattachtostring(opcuastringattachtostring_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUASTRINGATTACHTOSTRING_IEC) (opcuastringattachtostring_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUASTRINGATTACHTOSTRING_NOTIMPLEMENTED)
	#define USE_opcuastringattachtostring
	#define EXT_opcuastringattachtostring
	#define GET_opcuastringattachtostring(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuastringattachtostring(p0) 
	#define CHK_opcuastringattachtostring  FALSE
	#define EXP_opcuastringattachtostring  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuastringattachtostring
	#define EXT_opcuastringattachtostring
	#define GET_opcuastringattachtostring(fl)  CAL_CMGETAPI( "opcuastringattachtostring" ) 
	#define CAL_opcuastringattachtostring  opcuastringattachtostring
	#define CHK_opcuastringattachtostring  TRUE
	#define EXP_opcuastringattachtostring  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringattachtostring", (RTS_UINTPTR)opcuastringattachtostring, 1, 0xB95D79B1, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuastringattachtostring
	#define EXT_opcuastringattachtostring
	#define GET_opcuastringattachtostring(fl)  CAL_CMGETAPI( "opcuastringattachtostring" ) 
	#define CAL_opcuastringattachtostring  opcuastringattachtostring
	#define CHK_opcuastringattachtostring  TRUE
	#define EXP_opcuastringattachtostring  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringattachtostring", (RTS_UINTPTR)opcuastringattachtostring, 1, 0xB95D79B1, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuastringattachtostring
	#define EXT_CmpOPCUAStack_Implementationopcuastringattachtostring
	#define GET_CmpOPCUAStack_Implementationopcuastringattachtostring  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuastringattachtostring  opcuastringattachtostring
	#define CHK_CmpOPCUAStack_Implementationopcuastringattachtostring  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuastringattachtostring  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringattachtostring", (RTS_UINTPTR)opcuastringattachtostring, 1, 0xB95D79B1, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuastringattachtostring
	#define EXT_opcuastringattachtostring
	#define GET_opcuastringattachtostring(fl)  CAL_CMGETAPI( "opcuastringattachtostring" ) 
	#define CAL_opcuastringattachtostring  opcuastringattachtostring
	#define CHK_opcuastringattachtostring  TRUE
	#define EXP_opcuastringattachtostring  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringattachtostring", (RTS_UINTPTR)opcuastringattachtostring, 1, 0xB95D79B1, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuastringattachtostring  PFOPCUASTRINGATTACHTOSTRING_IEC pfopcuastringattachtostring;
	#define EXT_opcuastringattachtostring  extern PFOPCUASTRINGATTACHTOSTRING_IEC pfopcuastringattachtostring;
	#define GET_opcuastringattachtostring(fl)  s_pfCMGetAPI2( "opcuastringattachtostring", (RTS_VOID_FCTPTR *)&pfopcuastringattachtostring, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xB95D79B1, 0x03051000)
	#define CAL_opcuastringattachtostring  pfopcuastringattachtostring
	#define CHK_opcuastringattachtostring  (pfopcuastringattachtostring != NULL)
	#define EXP_opcuastringattachtostring   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringattachtostring", (RTS_UINTPTR)opcuastringattachtostring, 1, 0xB95D79B1, 0x03051000) 
#endif


/**
 * <description>opcuastringclear</description>
 */
typedef struct tagopcuastringclear_struct
{
	OpcUa_String *pString;				/* VAR_INPUT */	
} opcuastringclear_struct;

void CDECL CDECL_EXT opcuastringclear(opcuastringclear_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUASTRINGCLEAR_IEC) (opcuastringclear_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUASTRINGCLEAR_NOTIMPLEMENTED)
	#define USE_opcuastringclear
	#define EXT_opcuastringclear
	#define GET_opcuastringclear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuastringclear(p0) 
	#define CHK_opcuastringclear  FALSE
	#define EXP_opcuastringclear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuastringclear
	#define EXT_opcuastringclear
	#define GET_opcuastringclear(fl)  CAL_CMGETAPI( "opcuastringclear" ) 
	#define CAL_opcuastringclear  opcuastringclear
	#define CHK_opcuastringclear  TRUE
	#define EXP_opcuastringclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringclear", (RTS_UINTPTR)opcuastringclear, 1, 0xB79012EE, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuastringclear
	#define EXT_opcuastringclear
	#define GET_opcuastringclear(fl)  CAL_CMGETAPI( "opcuastringclear" ) 
	#define CAL_opcuastringclear  opcuastringclear
	#define CHK_opcuastringclear  TRUE
	#define EXP_opcuastringclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringclear", (RTS_UINTPTR)opcuastringclear, 1, 0xB79012EE, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuastringclear
	#define EXT_CmpOPCUAStack_Implementationopcuastringclear
	#define GET_CmpOPCUAStack_Implementationopcuastringclear  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuastringclear  opcuastringclear
	#define CHK_CmpOPCUAStack_Implementationopcuastringclear  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuastringclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringclear", (RTS_UINTPTR)opcuastringclear, 1, 0xB79012EE, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuastringclear
	#define EXT_opcuastringclear
	#define GET_opcuastringclear(fl)  CAL_CMGETAPI( "opcuastringclear" ) 
	#define CAL_opcuastringclear  opcuastringclear
	#define CHK_opcuastringclear  TRUE
	#define EXP_opcuastringclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringclear", (RTS_UINTPTR)opcuastringclear, 1, 0xB79012EE, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuastringclear  PFOPCUASTRINGCLEAR_IEC pfopcuastringclear;
	#define EXT_opcuastringclear  extern PFOPCUASTRINGCLEAR_IEC pfopcuastringclear;
	#define GET_opcuastringclear(fl)  s_pfCMGetAPI2( "opcuastringclear", (RTS_VOID_FCTPTR *)&pfopcuastringclear, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xB79012EE, 0x03051000)
	#define CAL_opcuastringclear  pfopcuastringclear
	#define CHK_opcuastringclear  (pfopcuastringclear != NULL)
	#define EXP_opcuastringclear   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringclear", (RTS_UINTPTR)opcuastringclear, 1, 0xB79012EE, 0x03051000) 
#endif


/**
 * <description>opcuastringgetrawstring</description>
 */
typedef struct tagopcuastringgetrawstring_struct
{
	OpcUa_String *pString;				/* VAR_INPUT */	
	RTS_IEC_SINT *OpcUaStringGetRawString;	/* VAR_OUTPUT */	
} opcuastringgetrawstring_struct;

void CDECL CDECL_EXT opcuastringgetrawstring(opcuastringgetrawstring_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUASTRINGGETRAWSTRING_IEC) (opcuastringgetrawstring_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUASTRINGGETRAWSTRING_NOTIMPLEMENTED)
	#define USE_opcuastringgetrawstring
	#define EXT_opcuastringgetrawstring
	#define GET_opcuastringgetrawstring(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuastringgetrawstring(p0) 
	#define CHK_opcuastringgetrawstring  FALSE
	#define EXP_opcuastringgetrawstring  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuastringgetrawstring
	#define EXT_opcuastringgetrawstring
	#define GET_opcuastringgetrawstring(fl)  CAL_CMGETAPI( "opcuastringgetrawstring" ) 
	#define CAL_opcuastringgetrawstring  opcuastringgetrawstring
	#define CHK_opcuastringgetrawstring  TRUE
	#define EXP_opcuastringgetrawstring  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringgetrawstring", (RTS_UINTPTR)opcuastringgetrawstring, 1, 0x34BB5D5D, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuastringgetrawstring
	#define EXT_opcuastringgetrawstring
	#define GET_opcuastringgetrawstring(fl)  CAL_CMGETAPI( "opcuastringgetrawstring" ) 
	#define CAL_opcuastringgetrawstring  opcuastringgetrawstring
	#define CHK_opcuastringgetrawstring  TRUE
	#define EXP_opcuastringgetrawstring  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringgetrawstring", (RTS_UINTPTR)opcuastringgetrawstring, 1, 0x34BB5D5D, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuastringgetrawstring
	#define EXT_CmpOPCUAStack_Implementationopcuastringgetrawstring
	#define GET_CmpOPCUAStack_Implementationopcuastringgetrawstring  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuastringgetrawstring  opcuastringgetrawstring
	#define CHK_CmpOPCUAStack_Implementationopcuastringgetrawstring  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuastringgetrawstring  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringgetrawstring", (RTS_UINTPTR)opcuastringgetrawstring, 1, 0x34BB5D5D, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuastringgetrawstring
	#define EXT_opcuastringgetrawstring
	#define GET_opcuastringgetrawstring(fl)  CAL_CMGETAPI( "opcuastringgetrawstring" ) 
	#define CAL_opcuastringgetrawstring  opcuastringgetrawstring
	#define CHK_opcuastringgetrawstring  TRUE
	#define EXP_opcuastringgetrawstring  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringgetrawstring", (RTS_UINTPTR)opcuastringgetrawstring, 1, 0x34BB5D5D, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuastringgetrawstring  PFOPCUASTRINGGETRAWSTRING_IEC pfopcuastringgetrawstring;
	#define EXT_opcuastringgetrawstring  extern PFOPCUASTRINGGETRAWSTRING_IEC pfopcuastringgetrawstring;
	#define GET_opcuastringgetrawstring(fl)  s_pfCMGetAPI2( "opcuastringgetrawstring", (RTS_VOID_FCTPTR *)&pfopcuastringgetrawstring, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x34BB5D5D, 0x03051000)
	#define CAL_opcuastringgetrawstring  pfopcuastringgetrawstring
	#define CHK_opcuastringgetrawstring  (pfopcuastringgetrawstring != NULL)
	#define EXP_opcuastringgetrawstring   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringgetrawstring", (RTS_UINTPTR)opcuastringgetrawstring, 1, 0x34BB5D5D, 0x03051000) 
#endif


/**
 * <description>opcuastringinitialize</description>
 */
typedef struct tagopcuastringinitialize_struct
{
	OpcUa_String *pString;				/* VAR_INPUT */	
} opcuastringinitialize_struct;

void CDECL CDECL_EXT opcuastringinitialize(opcuastringinitialize_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUASTRINGINITIALIZE_IEC) (opcuastringinitialize_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUASTRINGINITIALIZE_NOTIMPLEMENTED)
	#define USE_opcuastringinitialize
	#define EXT_opcuastringinitialize
	#define GET_opcuastringinitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuastringinitialize(p0) 
	#define CHK_opcuastringinitialize  FALSE
	#define EXP_opcuastringinitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuastringinitialize
	#define EXT_opcuastringinitialize
	#define GET_opcuastringinitialize(fl)  CAL_CMGETAPI( "opcuastringinitialize" ) 
	#define CAL_opcuastringinitialize  opcuastringinitialize
	#define CHK_opcuastringinitialize  TRUE
	#define EXP_opcuastringinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringinitialize", (RTS_UINTPTR)opcuastringinitialize, 1, 0xA2ED3883, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuastringinitialize
	#define EXT_opcuastringinitialize
	#define GET_opcuastringinitialize(fl)  CAL_CMGETAPI( "opcuastringinitialize" ) 
	#define CAL_opcuastringinitialize  opcuastringinitialize
	#define CHK_opcuastringinitialize  TRUE
	#define EXP_opcuastringinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringinitialize", (RTS_UINTPTR)opcuastringinitialize, 1, 0xA2ED3883, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuastringinitialize
	#define EXT_CmpOPCUAStack_Implementationopcuastringinitialize
	#define GET_CmpOPCUAStack_Implementationopcuastringinitialize  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuastringinitialize  opcuastringinitialize
	#define CHK_CmpOPCUAStack_Implementationopcuastringinitialize  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuastringinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringinitialize", (RTS_UINTPTR)opcuastringinitialize, 1, 0xA2ED3883, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuastringinitialize
	#define EXT_opcuastringinitialize
	#define GET_opcuastringinitialize(fl)  CAL_CMGETAPI( "opcuastringinitialize" ) 
	#define CAL_opcuastringinitialize  opcuastringinitialize
	#define CHK_opcuastringinitialize  TRUE
	#define EXP_opcuastringinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringinitialize", (RTS_UINTPTR)opcuastringinitialize, 1, 0xA2ED3883, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuastringinitialize  PFOPCUASTRINGINITIALIZE_IEC pfopcuastringinitialize;
	#define EXT_opcuastringinitialize  extern PFOPCUASTRINGINITIALIZE_IEC pfopcuastringinitialize;
	#define GET_opcuastringinitialize(fl)  s_pfCMGetAPI2( "opcuastringinitialize", (RTS_VOID_FCTPTR *)&pfopcuastringinitialize, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xA2ED3883, 0x03051000)
	#define CAL_opcuastringinitialize  pfopcuastringinitialize
	#define CHK_opcuastringinitialize  (pfopcuastringinitialize != NULL)
	#define EXP_opcuastringinitialize   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringinitialize", (RTS_UINTPTR)opcuastringinitialize, 1, 0xA2ED3883, 0x03051000) 
#endif


/**
 * <description>opcuastringisempty</description>
 */
typedef struct tagopcuastringisempty_struct
{
	OpcUa_String *pString;				/* VAR_INPUT */	
	RTS_IEC_BYTE OpcUaStringIsEmpty;	/* VAR_OUTPUT */	
} opcuastringisempty_struct;

void CDECL CDECL_EXT opcuastringisempty(opcuastringisempty_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUASTRINGISEMPTY_IEC) (opcuastringisempty_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUASTRINGISEMPTY_NOTIMPLEMENTED)
	#define USE_opcuastringisempty
	#define EXT_opcuastringisempty
	#define GET_opcuastringisempty(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuastringisempty(p0) 
	#define CHK_opcuastringisempty  FALSE
	#define EXP_opcuastringisempty  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuastringisempty
	#define EXT_opcuastringisempty
	#define GET_opcuastringisempty(fl)  CAL_CMGETAPI( "opcuastringisempty" ) 
	#define CAL_opcuastringisempty  opcuastringisempty
	#define CHK_opcuastringisempty  TRUE
	#define EXP_opcuastringisempty  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringisempty", (RTS_UINTPTR)opcuastringisempty, 1, 0xE17DA026, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuastringisempty
	#define EXT_opcuastringisempty
	#define GET_opcuastringisempty(fl)  CAL_CMGETAPI( "opcuastringisempty" ) 
	#define CAL_opcuastringisempty  opcuastringisempty
	#define CHK_opcuastringisempty  TRUE
	#define EXP_opcuastringisempty  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringisempty", (RTS_UINTPTR)opcuastringisempty, 1, 0xE17DA026, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuastringisempty
	#define EXT_CmpOPCUAStack_Implementationopcuastringisempty
	#define GET_CmpOPCUAStack_Implementationopcuastringisempty  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuastringisempty  opcuastringisempty
	#define CHK_CmpOPCUAStack_Implementationopcuastringisempty  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuastringisempty  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringisempty", (RTS_UINTPTR)opcuastringisempty, 1, 0xE17DA026, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuastringisempty
	#define EXT_opcuastringisempty
	#define GET_opcuastringisempty(fl)  CAL_CMGETAPI( "opcuastringisempty" ) 
	#define CAL_opcuastringisempty  opcuastringisempty
	#define CHK_opcuastringisempty  TRUE
	#define EXP_opcuastringisempty  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringisempty", (RTS_UINTPTR)opcuastringisempty, 1, 0xE17DA026, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuastringisempty  PFOPCUASTRINGISEMPTY_IEC pfopcuastringisempty;
	#define EXT_opcuastringisempty  extern PFOPCUASTRINGISEMPTY_IEC pfopcuastringisempty;
	#define GET_opcuastringisempty(fl)  s_pfCMGetAPI2( "opcuastringisempty", (RTS_VOID_FCTPTR *)&pfopcuastringisempty, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xE17DA026, 0x03051000)
	#define CAL_opcuastringisempty  pfopcuastringisempty
	#define CHK_opcuastringisempty  (pfopcuastringisempty != NULL)
	#define EXP_opcuastringisempty   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringisempty", (RTS_UINTPTR)opcuastringisempty, 1, 0xE17DA026, 0x03051000) 
#endif


/**
 * <description>opcuastringisnull</description>
 */
typedef struct tagopcuastringisnull_struct
{
	OpcUa_String *pString;				/* VAR_INPUT */	
	RTS_IEC_BYTE OpcUaStringIsNull;		/* VAR_OUTPUT */	
} opcuastringisnull_struct;

void CDECL CDECL_EXT opcuastringisnull(opcuastringisnull_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUASTRINGISNULL_IEC) (opcuastringisnull_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUASTRINGISNULL_NOTIMPLEMENTED)
	#define USE_opcuastringisnull
	#define EXT_opcuastringisnull
	#define GET_opcuastringisnull(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuastringisnull(p0) 
	#define CHK_opcuastringisnull  FALSE
	#define EXP_opcuastringisnull  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuastringisnull
	#define EXT_opcuastringisnull
	#define GET_opcuastringisnull(fl)  CAL_CMGETAPI( "opcuastringisnull" ) 
	#define CAL_opcuastringisnull  opcuastringisnull
	#define CHK_opcuastringisnull  TRUE
	#define EXP_opcuastringisnull  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringisnull", (RTS_UINTPTR)opcuastringisnull, 1, 0x9C5B676C, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuastringisnull
	#define EXT_opcuastringisnull
	#define GET_opcuastringisnull(fl)  CAL_CMGETAPI( "opcuastringisnull" ) 
	#define CAL_opcuastringisnull  opcuastringisnull
	#define CHK_opcuastringisnull  TRUE
	#define EXP_opcuastringisnull  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringisnull", (RTS_UINTPTR)opcuastringisnull, 1, 0x9C5B676C, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuastringisnull
	#define EXT_CmpOPCUAStack_Implementationopcuastringisnull
	#define GET_CmpOPCUAStack_Implementationopcuastringisnull  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuastringisnull  opcuastringisnull
	#define CHK_CmpOPCUAStack_Implementationopcuastringisnull  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuastringisnull  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringisnull", (RTS_UINTPTR)opcuastringisnull, 1, 0x9C5B676C, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuastringisnull
	#define EXT_opcuastringisnull
	#define GET_opcuastringisnull(fl)  CAL_CMGETAPI( "opcuastringisnull" ) 
	#define CAL_opcuastringisnull  opcuastringisnull
	#define CHK_opcuastringisnull  TRUE
	#define EXP_opcuastringisnull  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringisnull", (RTS_UINTPTR)opcuastringisnull, 1, 0x9C5B676C, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuastringisnull  PFOPCUASTRINGISNULL_IEC pfopcuastringisnull;
	#define EXT_opcuastringisnull  extern PFOPCUASTRINGISNULL_IEC pfopcuastringisnull;
	#define GET_opcuastringisnull(fl)  s_pfCMGetAPI2( "opcuastringisnull", (RTS_VOID_FCTPTR *)&pfopcuastringisnull, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x9C5B676C, 0x03051000)
	#define CAL_opcuastringisnull  pfopcuastringisnull
	#define CHK_opcuastringisnull  (pfopcuastringisnull != NULL)
	#define EXP_opcuastringisnull   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringisnull", (RTS_UINTPTR)opcuastringisnull, 1, 0x9C5B676C, 0x03051000) 
#endif


/**
 * <description>opcuastringstrlen</description>
 */
typedef struct tagopcuastringstrlen_struct
{
	OpcUa_String *pString;				/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaStringStrLen;	/* VAR_OUTPUT */	
} opcuastringstrlen_struct;

void CDECL CDECL_EXT opcuastringstrlen(opcuastringstrlen_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUASTRINGSTRLEN_IEC) (opcuastringstrlen_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUASTRINGSTRLEN_NOTIMPLEMENTED)
	#define USE_opcuastringstrlen
	#define EXT_opcuastringstrlen
	#define GET_opcuastringstrlen(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuastringstrlen(p0) 
	#define CHK_opcuastringstrlen  FALSE
	#define EXP_opcuastringstrlen  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuastringstrlen
	#define EXT_opcuastringstrlen
	#define GET_opcuastringstrlen(fl)  CAL_CMGETAPI( "opcuastringstrlen" ) 
	#define CAL_opcuastringstrlen  opcuastringstrlen
	#define CHK_opcuastringstrlen  TRUE
	#define EXP_opcuastringstrlen  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringstrlen", (RTS_UINTPTR)opcuastringstrlen, 1, 0xE08C44DF, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuastringstrlen
	#define EXT_opcuastringstrlen
	#define GET_opcuastringstrlen(fl)  CAL_CMGETAPI( "opcuastringstrlen" ) 
	#define CAL_opcuastringstrlen  opcuastringstrlen
	#define CHK_opcuastringstrlen  TRUE
	#define EXP_opcuastringstrlen  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringstrlen", (RTS_UINTPTR)opcuastringstrlen, 1, 0xE08C44DF, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuastringstrlen
	#define EXT_CmpOPCUAStack_Implementationopcuastringstrlen
	#define GET_CmpOPCUAStack_Implementationopcuastringstrlen  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuastringstrlen  opcuastringstrlen
	#define CHK_CmpOPCUAStack_Implementationopcuastringstrlen  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuastringstrlen  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringstrlen", (RTS_UINTPTR)opcuastringstrlen, 1, 0xE08C44DF, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuastringstrlen
	#define EXT_opcuastringstrlen
	#define GET_opcuastringstrlen(fl)  CAL_CMGETAPI( "opcuastringstrlen" ) 
	#define CAL_opcuastringstrlen  opcuastringstrlen
	#define CHK_opcuastringstrlen  TRUE
	#define EXP_opcuastringstrlen  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringstrlen", (RTS_UINTPTR)opcuastringstrlen, 1, 0xE08C44DF, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuastringstrlen  PFOPCUASTRINGSTRLEN_IEC pfopcuastringstrlen;
	#define EXT_opcuastringstrlen  extern PFOPCUASTRINGSTRLEN_IEC pfopcuastringstrlen;
	#define GET_opcuastringstrlen(fl)  s_pfCMGetAPI2( "opcuastringstrlen", (RTS_VOID_FCTPTR *)&pfopcuastringstrlen, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xE08C44DF, 0x03051000)
	#define CAL_opcuastringstrlen  pfopcuastringstrlen
	#define CHK_opcuastringstrlen  (pfopcuastringstrlen != NULL)
	#define EXP_opcuastringstrlen   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringstrlen", (RTS_UINTPTR)opcuastringstrlen, 1, 0xE08C44DF, 0x03051000) 
#endif


/**
 * <description>opcuastringstrncat</description>
 */
typedef struct tagopcuastringstrncat_struct
{
	OpcUa_String *pDestString;			/* VAR_INPUT */	
	OpcUa_String *pSrcString;			/* VAR_INPUT */	
	RTS_IEC_UDINT uLength;				/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaStringStrnCat;	/* VAR_OUTPUT */	
} opcuastringstrncat_struct;

void CDECL CDECL_EXT opcuastringstrncat(opcuastringstrncat_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUASTRINGSTRNCAT_IEC) (opcuastringstrncat_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUASTRINGSTRNCAT_NOTIMPLEMENTED)
	#define USE_opcuastringstrncat
	#define EXT_opcuastringstrncat
	#define GET_opcuastringstrncat(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuastringstrncat(p0) 
	#define CHK_opcuastringstrncat  FALSE
	#define EXP_opcuastringstrncat  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuastringstrncat
	#define EXT_opcuastringstrncat
	#define GET_opcuastringstrncat(fl)  CAL_CMGETAPI( "opcuastringstrncat" ) 
	#define CAL_opcuastringstrncat  opcuastringstrncat
	#define CHK_opcuastringstrncat  TRUE
	#define EXP_opcuastringstrncat  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringstrncat", (RTS_UINTPTR)opcuastringstrncat, 1, 0x5F9D7E9F, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuastringstrncat
	#define EXT_opcuastringstrncat
	#define GET_opcuastringstrncat(fl)  CAL_CMGETAPI( "opcuastringstrncat" ) 
	#define CAL_opcuastringstrncat  opcuastringstrncat
	#define CHK_opcuastringstrncat  TRUE
	#define EXP_opcuastringstrncat  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringstrncat", (RTS_UINTPTR)opcuastringstrncat, 1, 0x5F9D7E9F, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuastringstrncat
	#define EXT_CmpOPCUAStack_Implementationopcuastringstrncat
	#define GET_CmpOPCUAStack_Implementationopcuastringstrncat  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuastringstrncat  opcuastringstrncat
	#define CHK_CmpOPCUAStack_Implementationopcuastringstrncat  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuastringstrncat  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringstrncat", (RTS_UINTPTR)opcuastringstrncat, 1, 0x5F9D7E9F, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuastringstrncat
	#define EXT_opcuastringstrncat
	#define GET_opcuastringstrncat(fl)  CAL_CMGETAPI( "opcuastringstrncat" ) 
	#define CAL_opcuastringstrncat  opcuastringstrncat
	#define CHK_opcuastringstrncat  TRUE
	#define EXP_opcuastringstrncat  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringstrncat", (RTS_UINTPTR)opcuastringstrncat, 1, 0x5F9D7E9F, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuastringstrncat  PFOPCUASTRINGSTRNCAT_IEC pfopcuastringstrncat;
	#define EXT_opcuastringstrncat  extern PFOPCUASTRINGSTRNCAT_IEC pfopcuastringstrncat;
	#define GET_opcuastringstrncat(fl)  s_pfCMGetAPI2( "opcuastringstrncat", (RTS_VOID_FCTPTR *)&pfopcuastringstrncat, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x5F9D7E9F, 0x03051000)
	#define CAL_opcuastringstrncat  pfopcuastringstrncat
	#define CHK_opcuastringstrncat  (pfopcuastringstrncat != NULL)
	#define EXP_opcuastringstrncat   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringstrncat", (RTS_UINTPTR)opcuastringstrncat, 1, 0x5F9D7E9F, 0x03051000) 
#endif


/**
 * <description>opcuastringstrncmp</description>
 */
typedef struct tagopcuastringstrncmp_struct
{
	OpcUa_String *pLeftString;			/* VAR_INPUT */	
	OpcUa_String *pRightString;			/* VAR_INPUT */	
	RTS_IEC_UDINT uLength;				/* VAR_INPUT */	
	RTS_IEC_BYTE bIgnoreCase;			/* VAR_INPUT */	
	RTS_IEC_DINT OpcUaStringStrnCmp;	/* VAR_OUTPUT */	
} opcuastringstrncmp_struct;

void CDECL CDECL_EXT opcuastringstrncmp(opcuastringstrncmp_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUASTRINGSTRNCMP_IEC) (opcuastringstrncmp_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUASTRINGSTRNCMP_NOTIMPLEMENTED)
	#define USE_opcuastringstrncmp
	#define EXT_opcuastringstrncmp
	#define GET_opcuastringstrncmp(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuastringstrncmp(p0) 
	#define CHK_opcuastringstrncmp  FALSE
	#define EXP_opcuastringstrncmp  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuastringstrncmp
	#define EXT_opcuastringstrncmp
	#define GET_opcuastringstrncmp(fl)  CAL_CMGETAPI( "opcuastringstrncmp" ) 
	#define CAL_opcuastringstrncmp  opcuastringstrncmp
	#define CHK_opcuastringstrncmp  TRUE
	#define EXP_opcuastringstrncmp  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringstrncmp", (RTS_UINTPTR)opcuastringstrncmp, 1, 0x53DB5D7B, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuastringstrncmp
	#define EXT_opcuastringstrncmp
	#define GET_opcuastringstrncmp(fl)  CAL_CMGETAPI( "opcuastringstrncmp" ) 
	#define CAL_opcuastringstrncmp  opcuastringstrncmp
	#define CHK_opcuastringstrncmp  TRUE
	#define EXP_opcuastringstrncmp  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringstrncmp", (RTS_UINTPTR)opcuastringstrncmp, 1, 0x53DB5D7B, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuastringstrncmp
	#define EXT_CmpOPCUAStack_Implementationopcuastringstrncmp
	#define GET_CmpOPCUAStack_Implementationopcuastringstrncmp  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuastringstrncmp  opcuastringstrncmp
	#define CHK_CmpOPCUAStack_Implementationopcuastringstrncmp  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuastringstrncmp  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringstrncmp", (RTS_UINTPTR)opcuastringstrncmp, 1, 0x53DB5D7B, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuastringstrncmp
	#define EXT_opcuastringstrncmp
	#define GET_opcuastringstrncmp(fl)  CAL_CMGETAPI( "opcuastringstrncmp" ) 
	#define CAL_opcuastringstrncmp  opcuastringstrncmp
	#define CHK_opcuastringstrncmp  TRUE
	#define EXP_opcuastringstrncmp  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringstrncmp", (RTS_UINTPTR)opcuastringstrncmp, 1, 0x53DB5D7B, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuastringstrncmp  PFOPCUASTRINGSTRNCMP_IEC pfopcuastringstrncmp;
	#define EXT_opcuastringstrncmp  extern PFOPCUASTRINGSTRNCMP_IEC pfopcuastringstrncmp;
	#define GET_opcuastringstrncmp(fl)  s_pfCMGetAPI2( "opcuastringstrncmp", (RTS_VOID_FCTPTR *)&pfopcuastringstrncmp, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x53DB5D7B, 0x03051000)
	#define CAL_opcuastringstrncmp  pfopcuastringstrncmp
	#define CHK_opcuastringstrncmp  (pfopcuastringstrncmp != NULL)
	#define EXP_opcuastringstrncmp   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringstrncmp", (RTS_UINTPTR)opcuastringstrncmp, 1, 0x53DB5D7B, 0x03051000) 
#endif


/**
 * <description>opcuastringstrncpy</description>
 */
typedef struct tagopcuastringstrncpy_struct
{
	OpcUa_String *pDestString;			/* VAR_INPUT */	
	OpcUa_String *pSrcString;			/* VAR_INPUT */	
	RTS_IEC_UDINT uLength;				/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaStringStrnCpy;	/* VAR_OUTPUT */	
} opcuastringstrncpy_struct;

void CDECL CDECL_EXT opcuastringstrncpy(opcuastringstrncpy_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUASTRINGSTRNCPY_IEC) (opcuastringstrncpy_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUASTRINGSTRNCPY_NOTIMPLEMENTED)
	#define USE_opcuastringstrncpy
	#define EXT_opcuastringstrncpy
	#define GET_opcuastringstrncpy(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuastringstrncpy(p0) 
	#define CHK_opcuastringstrncpy  FALSE
	#define EXP_opcuastringstrncpy  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuastringstrncpy
	#define EXT_opcuastringstrncpy
	#define GET_opcuastringstrncpy(fl)  CAL_CMGETAPI( "opcuastringstrncpy" ) 
	#define CAL_opcuastringstrncpy  opcuastringstrncpy
	#define CHK_opcuastringstrncpy  TRUE
	#define EXP_opcuastringstrncpy  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringstrncpy", (RTS_UINTPTR)opcuastringstrncpy, 1, 0x35071283, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuastringstrncpy
	#define EXT_opcuastringstrncpy
	#define GET_opcuastringstrncpy(fl)  CAL_CMGETAPI( "opcuastringstrncpy" ) 
	#define CAL_opcuastringstrncpy  opcuastringstrncpy
	#define CHK_opcuastringstrncpy  TRUE
	#define EXP_opcuastringstrncpy  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringstrncpy", (RTS_UINTPTR)opcuastringstrncpy, 1, 0x35071283, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuastringstrncpy
	#define EXT_CmpOPCUAStack_Implementationopcuastringstrncpy
	#define GET_CmpOPCUAStack_Implementationopcuastringstrncpy  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuastringstrncpy  opcuastringstrncpy
	#define CHK_CmpOPCUAStack_Implementationopcuastringstrncpy  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuastringstrncpy  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringstrncpy", (RTS_UINTPTR)opcuastringstrncpy, 1, 0x35071283, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuastringstrncpy
	#define EXT_opcuastringstrncpy
	#define GET_opcuastringstrncpy(fl)  CAL_CMGETAPI( "opcuastringstrncpy" ) 
	#define CAL_opcuastringstrncpy  opcuastringstrncpy
	#define CHK_opcuastringstrncpy  TRUE
	#define EXP_opcuastringstrncpy  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringstrncpy", (RTS_UINTPTR)opcuastringstrncpy, 1, 0x35071283, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuastringstrncpy  PFOPCUASTRINGSTRNCPY_IEC pfopcuastringstrncpy;
	#define EXT_opcuastringstrncpy  extern PFOPCUASTRINGSTRNCPY_IEC pfopcuastringstrncpy;
	#define GET_opcuastringstrncpy(fl)  s_pfCMGetAPI2( "opcuastringstrncpy", (RTS_VOID_FCTPTR *)&pfopcuastringstrncpy, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x35071283, 0x03051000)
	#define CAL_opcuastringstrncpy  pfopcuastringstrncpy
	#define CHK_opcuastringstrncpy  (pfopcuastringstrncpy != NULL)
	#define EXP_opcuastringstrncpy   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringstrncpy", (RTS_UINTPTR)opcuastringstrncpy, 1, 0x35071283, 0x03051000) 
#endif


/**
 * <description>opcuastringstrsize</description>
 */
typedef struct tagopcuastringstrsize_struct
{
	OpcUa_String *pString;				/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaStringStrSize;	/* VAR_OUTPUT */	
} opcuastringstrsize_struct;

void CDECL CDECL_EXT opcuastringstrsize(opcuastringstrsize_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUASTRINGSTRSIZE_IEC) (opcuastringstrsize_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUASTRINGSTRSIZE_NOTIMPLEMENTED)
	#define USE_opcuastringstrsize
	#define EXT_opcuastringstrsize
	#define GET_opcuastringstrsize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuastringstrsize(p0) 
	#define CHK_opcuastringstrsize  FALSE
	#define EXP_opcuastringstrsize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuastringstrsize
	#define EXT_opcuastringstrsize
	#define GET_opcuastringstrsize(fl)  CAL_CMGETAPI( "opcuastringstrsize" ) 
	#define CAL_opcuastringstrsize  opcuastringstrsize
	#define CHK_opcuastringstrsize  TRUE
	#define EXP_opcuastringstrsize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringstrsize", (RTS_UINTPTR)opcuastringstrsize, 1, 0xF9B1AC55, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuastringstrsize
	#define EXT_opcuastringstrsize
	#define GET_opcuastringstrsize(fl)  CAL_CMGETAPI( "opcuastringstrsize" ) 
	#define CAL_opcuastringstrsize  opcuastringstrsize
	#define CHK_opcuastringstrsize  TRUE
	#define EXP_opcuastringstrsize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringstrsize", (RTS_UINTPTR)opcuastringstrsize, 1, 0xF9B1AC55, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuastringstrsize
	#define EXT_CmpOPCUAStack_Implementationopcuastringstrsize
	#define GET_CmpOPCUAStack_Implementationopcuastringstrsize  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuastringstrsize  opcuastringstrsize
	#define CHK_CmpOPCUAStack_Implementationopcuastringstrsize  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuastringstrsize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringstrsize", (RTS_UINTPTR)opcuastringstrsize, 1, 0xF9B1AC55, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuastringstrsize
	#define EXT_opcuastringstrsize
	#define GET_opcuastringstrsize(fl)  CAL_CMGETAPI( "opcuastringstrsize" ) 
	#define CAL_opcuastringstrsize  opcuastringstrsize
	#define CHK_opcuastringstrsize  TRUE
	#define EXP_opcuastringstrsize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringstrsize", (RTS_UINTPTR)opcuastringstrsize, 1, 0xF9B1AC55, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuastringstrsize  PFOPCUASTRINGSTRSIZE_IEC pfopcuastringstrsize;
	#define EXT_opcuastringstrsize  extern PFOPCUASTRINGSTRSIZE_IEC pfopcuastringstrsize;
	#define GET_opcuastringstrsize(fl)  s_pfCMGetAPI2( "opcuastringstrsize", (RTS_VOID_FCTPTR *)&pfopcuastringstrsize, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xF9B1AC55, 0x03051000)
	#define CAL_opcuastringstrsize  pfopcuastringstrsize
	#define CHK_opcuastringstrsize  (pfopcuastringstrsize != NULL)
	#define EXP_opcuastringstrsize   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuastringstrsize", (RTS_UINTPTR)opcuastringstrsize, 1, 0xF9B1AC55, 0x03051000) 
#endif


/**
 * <description>opcuavariantclear</description>
 */
typedef struct tagopcuavariantclear_struct
{
	OpcUa_Variant *value;				/* VAR_INPUT */	
} opcuavariantclear_struct;

void CDECL CDECL_EXT opcuavariantclear(opcuavariantclear_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAVARIANTCLEAR_IEC) (opcuavariantclear_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAVARIANTCLEAR_NOTIMPLEMENTED)
	#define USE_opcuavariantclear
	#define EXT_opcuavariantclear
	#define GET_opcuavariantclear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuavariantclear(p0) 
	#define CHK_opcuavariantclear  FALSE
	#define EXP_opcuavariantclear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuavariantclear
	#define EXT_opcuavariantclear
	#define GET_opcuavariantclear(fl)  CAL_CMGETAPI( "opcuavariantclear" ) 
	#define CAL_opcuavariantclear  opcuavariantclear
	#define CHK_opcuavariantclear  TRUE
	#define EXP_opcuavariantclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuavariantclear", (RTS_UINTPTR)opcuavariantclear, 1, 0xF92D0208, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuavariantclear
	#define EXT_opcuavariantclear
	#define GET_opcuavariantclear(fl)  CAL_CMGETAPI( "opcuavariantclear" ) 
	#define CAL_opcuavariantclear  opcuavariantclear
	#define CHK_opcuavariantclear  TRUE
	#define EXP_opcuavariantclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuavariantclear", (RTS_UINTPTR)opcuavariantclear, 1, 0xF92D0208, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuavariantclear
	#define EXT_CmpOPCUAStack_Implementationopcuavariantclear
	#define GET_CmpOPCUAStack_Implementationopcuavariantclear  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuavariantclear  opcuavariantclear
	#define CHK_CmpOPCUAStack_Implementationopcuavariantclear  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuavariantclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuavariantclear", (RTS_UINTPTR)opcuavariantclear, 1, 0xF92D0208, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuavariantclear
	#define EXT_opcuavariantclear
	#define GET_opcuavariantclear(fl)  CAL_CMGETAPI( "opcuavariantclear" ) 
	#define CAL_opcuavariantclear  opcuavariantclear
	#define CHK_opcuavariantclear  TRUE
	#define EXP_opcuavariantclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuavariantclear", (RTS_UINTPTR)opcuavariantclear, 1, 0xF92D0208, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuavariantclear  PFOPCUAVARIANTCLEAR_IEC pfopcuavariantclear;
	#define EXT_opcuavariantclear  extern PFOPCUAVARIANTCLEAR_IEC pfopcuavariantclear;
	#define GET_opcuavariantclear(fl)  s_pfCMGetAPI2( "opcuavariantclear", (RTS_VOID_FCTPTR *)&pfopcuavariantclear, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xF92D0208, 0x03051000)
	#define CAL_opcuavariantclear  pfopcuavariantclear
	#define CHK_opcuavariantclear  (pfopcuavariantclear != NULL)
	#define EXP_opcuavariantclear   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuavariantclear", (RTS_UINTPTR)opcuavariantclear, 1, 0xF92D0208, 0x03051000) 
#endif


/**
 * <description>opcuavariantcompare</description>
 */
typedef struct tagopcuavariantcompare_struct
{
	OpcUa_Variant *pValue1;				/* VAR_INPUT */	
	OpcUa_Variant *pValue2;				/* VAR_INPUT */	
	RTS_IEC_DINT OpcUaVariantCompare;	/* VAR_OUTPUT */	
} opcuavariantcompare_struct;

void CDECL CDECL_EXT opcuavariantcompare(opcuavariantcompare_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAVARIANTCOMPARE_IEC) (opcuavariantcompare_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAVARIANTCOMPARE_NOTIMPLEMENTED)
	#define USE_opcuavariantcompare
	#define EXT_opcuavariantcompare
	#define GET_opcuavariantcompare(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuavariantcompare(p0) 
	#define CHK_opcuavariantcompare  FALSE
	#define EXP_opcuavariantcompare  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuavariantcompare
	#define EXT_opcuavariantcompare
	#define GET_opcuavariantcompare(fl)  CAL_CMGETAPI( "opcuavariantcompare" ) 
	#define CAL_opcuavariantcompare  opcuavariantcompare
	#define CHK_opcuavariantcompare  TRUE
	#define EXP_opcuavariantcompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuavariantcompare", (RTS_UINTPTR)opcuavariantcompare, 1, 0xDE73CC0D, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuavariantcompare
	#define EXT_opcuavariantcompare
	#define GET_opcuavariantcompare(fl)  CAL_CMGETAPI( "opcuavariantcompare" ) 
	#define CAL_opcuavariantcompare  opcuavariantcompare
	#define CHK_opcuavariantcompare  TRUE
	#define EXP_opcuavariantcompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuavariantcompare", (RTS_UINTPTR)opcuavariantcompare, 1, 0xDE73CC0D, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuavariantcompare
	#define EXT_CmpOPCUAStack_Implementationopcuavariantcompare
	#define GET_CmpOPCUAStack_Implementationopcuavariantcompare  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuavariantcompare  opcuavariantcompare
	#define CHK_CmpOPCUAStack_Implementationopcuavariantcompare  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuavariantcompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuavariantcompare", (RTS_UINTPTR)opcuavariantcompare, 1, 0xDE73CC0D, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuavariantcompare
	#define EXT_opcuavariantcompare
	#define GET_opcuavariantcompare(fl)  CAL_CMGETAPI( "opcuavariantcompare" ) 
	#define CAL_opcuavariantcompare  opcuavariantcompare
	#define CHK_opcuavariantcompare  TRUE
	#define EXP_opcuavariantcompare  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuavariantcompare", (RTS_UINTPTR)opcuavariantcompare, 1, 0xDE73CC0D, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuavariantcompare  PFOPCUAVARIANTCOMPARE_IEC pfopcuavariantcompare;
	#define EXT_opcuavariantcompare  extern PFOPCUAVARIANTCOMPARE_IEC pfopcuavariantcompare;
	#define GET_opcuavariantcompare(fl)  s_pfCMGetAPI2( "opcuavariantcompare", (RTS_VOID_FCTPTR *)&pfopcuavariantcompare, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xDE73CC0D, 0x03051000)
	#define CAL_opcuavariantcompare  pfopcuavariantcompare
	#define CHK_opcuavariantcompare  (pfopcuavariantcompare != NULL)
	#define EXP_opcuavariantcompare   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuavariantcompare", (RTS_UINTPTR)opcuavariantcompare, 1, 0xDE73CC0D, 0x03051000) 
#endif


/**
 * <description>opcuavariantcopyto</description>
 */
typedef struct tagopcuavariantcopyto_struct
{
	OpcUa_Variant *pSource;				/* VAR_INPUT */	
	OpcUa_Variant *pDestination;		/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaVariantCopyTo;	/* VAR_OUTPUT */	
} opcuavariantcopyto_struct;

void CDECL CDECL_EXT opcuavariantcopyto(opcuavariantcopyto_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAVARIANTCOPYTO_IEC) (opcuavariantcopyto_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAVARIANTCOPYTO_NOTIMPLEMENTED)
	#define USE_opcuavariantcopyto
	#define EXT_opcuavariantcopyto
	#define GET_opcuavariantcopyto(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuavariantcopyto(p0) 
	#define CHK_opcuavariantcopyto  FALSE
	#define EXP_opcuavariantcopyto  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuavariantcopyto
	#define EXT_opcuavariantcopyto
	#define GET_opcuavariantcopyto(fl)  CAL_CMGETAPI( "opcuavariantcopyto" ) 
	#define CAL_opcuavariantcopyto  opcuavariantcopyto
	#define CHK_opcuavariantcopyto  TRUE
	#define EXP_opcuavariantcopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuavariantcopyto", (RTS_UINTPTR)opcuavariantcopyto, 1, 0x06DA6455, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuavariantcopyto
	#define EXT_opcuavariantcopyto
	#define GET_opcuavariantcopyto(fl)  CAL_CMGETAPI( "opcuavariantcopyto" ) 
	#define CAL_opcuavariantcopyto  opcuavariantcopyto
	#define CHK_opcuavariantcopyto  TRUE
	#define EXP_opcuavariantcopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuavariantcopyto", (RTS_UINTPTR)opcuavariantcopyto, 1, 0x06DA6455, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuavariantcopyto
	#define EXT_CmpOPCUAStack_Implementationopcuavariantcopyto
	#define GET_CmpOPCUAStack_Implementationopcuavariantcopyto  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuavariantcopyto  opcuavariantcopyto
	#define CHK_CmpOPCUAStack_Implementationopcuavariantcopyto  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuavariantcopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuavariantcopyto", (RTS_UINTPTR)opcuavariantcopyto, 1, 0x06DA6455, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuavariantcopyto
	#define EXT_opcuavariantcopyto
	#define GET_opcuavariantcopyto(fl)  CAL_CMGETAPI( "opcuavariantcopyto" ) 
	#define CAL_opcuavariantcopyto  opcuavariantcopyto
	#define CHK_opcuavariantcopyto  TRUE
	#define EXP_opcuavariantcopyto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuavariantcopyto", (RTS_UINTPTR)opcuavariantcopyto, 1, 0x06DA6455, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuavariantcopyto  PFOPCUAVARIANTCOPYTO_IEC pfopcuavariantcopyto;
	#define EXT_opcuavariantcopyto  extern PFOPCUAVARIANTCOPYTO_IEC pfopcuavariantcopyto;
	#define GET_opcuavariantcopyto(fl)  s_pfCMGetAPI2( "opcuavariantcopyto", (RTS_VOID_FCTPTR *)&pfopcuavariantcopyto, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x06DA6455, 0x03051000)
	#define CAL_opcuavariantcopyto  pfopcuavariantcopyto
	#define CHK_opcuavariantcopyto  (pfopcuavariantcopyto != NULL)
	#define EXP_opcuavariantcopyto   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuavariantcopyto", (RTS_UINTPTR)opcuavariantcopyto, 1, 0x06DA6455, 0x03051000) 
#endif


/**
 * <description>opcuavariantinitialize</description>
 */
typedef struct tagopcuavariantinitialize_struct
{
	OpcUa_Variant *value;				/* VAR_INPUT */	
} opcuavariantinitialize_struct;

void CDECL CDECL_EXT opcuavariantinitialize(opcuavariantinitialize_struct *p);
typedef void (CDECL CDECL_EXT* PFOPCUAVARIANTINITIALIZE_IEC) (opcuavariantinitialize_struct *p);
#if defined(CMPOPCUASTACK_IMPLEMENTATION_NOTIMPLEMENTED) || defined(OPCUAVARIANTINITIALIZE_NOTIMPLEMENTED)
	#define USE_opcuavariantinitialize
	#define EXT_opcuavariantinitialize
	#define GET_opcuavariantinitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_opcuavariantinitialize(p0) 
	#define CHK_opcuavariantinitialize  FALSE
	#define EXP_opcuavariantinitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_opcuavariantinitialize
	#define EXT_opcuavariantinitialize
	#define GET_opcuavariantinitialize(fl)  CAL_CMGETAPI( "opcuavariantinitialize" ) 
	#define CAL_opcuavariantinitialize  opcuavariantinitialize
	#define CHK_opcuavariantinitialize  TRUE
	#define EXP_opcuavariantinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuavariantinitialize", (RTS_UINTPTR)opcuavariantinitialize, 1, 0xEA98C1BA, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_IMPLEMENTATION_EXTERNAL)
	#define USE_opcuavariantinitialize
	#define EXT_opcuavariantinitialize
	#define GET_opcuavariantinitialize(fl)  CAL_CMGETAPI( "opcuavariantinitialize" ) 
	#define CAL_opcuavariantinitialize  opcuavariantinitialize
	#define CHK_opcuavariantinitialize  TRUE
	#define EXP_opcuavariantinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuavariantinitialize", (RTS_UINTPTR)opcuavariantinitialize, 1, 0xEA98C1BA, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStack_Implementationopcuavariantinitialize
	#define EXT_CmpOPCUAStack_Implementationopcuavariantinitialize
	#define GET_CmpOPCUAStack_Implementationopcuavariantinitialize  ERR_OK
	#define CAL_CmpOPCUAStack_Implementationopcuavariantinitialize  opcuavariantinitialize
	#define CHK_CmpOPCUAStack_Implementationopcuavariantinitialize  TRUE
	#define EXP_CmpOPCUAStack_Implementationopcuavariantinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuavariantinitialize", (RTS_UINTPTR)opcuavariantinitialize, 1, 0xEA98C1BA, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_opcuavariantinitialize
	#define EXT_opcuavariantinitialize
	#define GET_opcuavariantinitialize(fl)  CAL_CMGETAPI( "opcuavariantinitialize" ) 
	#define CAL_opcuavariantinitialize  opcuavariantinitialize
	#define CHK_opcuavariantinitialize  TRUE
	#define EXP_opcuavariantinitialize  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuavariantinitialize", (RTS_UINTPTR)opcuavariantinitialize, 1, 0xEA98C1BA, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_opcuavariantinitialize  PFOPCUAVARIANTINITIALIZE_IEC pfopcuavariantinitialize;
	#define EXT_opcuavariantinitialize  extern PFOPCUAVARIANTINITIALIZE_IEC pfopcuavariantinitialize;
	#define GET_opcuavariantinitialize(fl)  s_pfCMGetAPI2( "opcuavariantinitialize", (RTS_VOID_FCTPTR *)&pfopcuavariantinitialize, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xEA98C1BA, 0x03051000)
	#define CAL_opcuavariantinitialize  pfopcuavariantinitialize
	#define CHK_opcuavariantinitialize  (pfopcuavariantinitialize != NULL)
	#define EXP_opcuavariantinitialize   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"opcuavariantinitialize", (RTS_UINTPTR)opcuavariantinitialize, 1, 0xEA98C1BA, 0x03051000) 
#endif


#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/




typedef struct
{
	IBase_C *pBase;
} ICmpOPCUAStack_Implementation_C;

#ifdef CPLUSPLUS
class ICmpOPCUAStack_Implementation : public IBase
{
	public:
};
	#ifndef ITF_CmpOPCUAStack_Implementation
		#define ITF_CmpOPCUAStack_Implementation static ICmpOPCUAStack_Implementation *pICmpOPCUAStack_Implementation = NULL;
	#endif
	#define EXTITF_CmpOPCUAStack_Implementation
#else	/*CPLUSPLUS*/
	typedef ICmpOPCUAStack_Implementation_C		ICmpOPCUAStack_Implementation;
	#ifndef ITF_CmpOPCUAStack_Implementation
		#define ITF_CmpOPCUAStack_Implementation
	#endif
	#define EXTITF_CmpOPCUAStack_Implementation
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_CMPOPCUASTACK_IMPLEMENTATIONITF_H_*/
