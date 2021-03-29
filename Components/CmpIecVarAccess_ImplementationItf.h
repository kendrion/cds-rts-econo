 /**
 * <interfacename>CmpIecVarAccess_Implementation</interfacename>
 * <description></description>
 *
 * <copyright></copyright>
 */


	
	
#ifndef _CMPIECVARACCESS_IMPLEMENTATIONITF_H_
#define _CMPIECVARACCESS_IMPLEMENTATIONITF_H_

#include "CmpStd.h"

 

 




#include "CmpIecVarAccessItf.h"

/** EXTERN LIB SECTION BEGIN **/
/*  Comments are ignored for m4 compiler so restructured text can be used.  */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description>iecvaraccbrowsedown2</description>
 */
typedef struct tagiecvaraccbrowsedown2_struct
{
	RTS_IEC_HANDLE hInterface;			/* VAR_INPUT */	
	IBaseTreeNode *hNode;				/* VAR_INPUT */	
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	IBaseTreeNode *IecVarAccBrowseDown2;	/* VAR_OUTPUT */	
} iecvaraccbrowsedown2_struct;

void CDECL CDECL_EXT iecvaraccbrowsedown2(iecvaraccbrowsedown2_struct *p);
typedef void (CDECL CDECL_EXT* PFIECVARACCBROWSEDOWN2_IEC) (iecvaraccbrowsedown2_struct *p);
#if defined(CMPIECVARACCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(IECVARACCBROWSEDOWN2_NOTIMPLEMENTED)
	#define USE_iecvaraccbrowsedown2
	#define EXT_iecvaraccbrowsedown2
	#define GET_iecvaraccbrowsedown2(fl)  ERR_NOTIMPLEMENTED
	#define CAL_iecvaraccbrowsedown2(p0) 
	#define CHK_iecvaraccbrowsedown2  FALSE
	#define EXP_iecvaraccbrowsedown2  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_iecvaraccbrowsedown2
	#define EXT_iecvaraccbrowsedown2
	#define GET_iecvaraccbrowsedown2(fl)  CAL_CMGETAPI( "iecvaraccbrowsedown2" ) 
	#define CAL_iecvaraccbrowsedown2  iecvaraccbrowsedown2
	#define CHK_iecvaraccbrowsedown2  TRUE
	#define EXP_iecvaraccbrowsedown2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccbrowsedown2", (RTS_UINTPTR)iecvaraccbrowsedown2, 1, 0, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPIECVARACCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_iecvaraccbrowsedown2
	#define EXT_iecvaraccbrowsedown2
	#define GET_iecvaraccbrowsedown2(fl)  CAL_CMGETAPI( "iecvaraccbrowsedown2" ) 
	#define CAL_iecvaraccbrowsedown2  iecvaraccbrowsedown2
	#define CHK_iecvaraccbrowsedown2  TRUE
	#define EXP_iecvaraccbrowsedown2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccbrowsedown2", (RTS_UINTPTR)iecvaraccbrowsedown2, 1, 0, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIecVarAccess_Implementationiecvaraccbrowsedown2
	#define EXT_CmpIecVarAccess_Implementationiecvaraccbrowsedown2
	#define GET_CmpIecVarAccess_Implementationiecvaraccbrowsedown2  ERR_OK
	#define CAL_CmpIecVarAccess_Implementationiecvaraccbrowsedown2  iecvaraccbrowsedown2
	#define CHK_CmpIecVarAccess_Implementationiecvaraccbrowsedown2  TRUE
	#define EXP_CmpIecVarAccess_Implementationiecvaraccbrowsedown2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccbrowsedown2", (RTS_UINTPTR)iecvaraccbrowsedown2, 1, 0, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_iecvaraccbrowsedown2
	#define EXT_iecvaraccbrowsedown2
	#define GET_iecvaraccbrowsedown2(fl)  CAL_CMGETAPI( "iecvaraccbrowsedown2" ) 
	#define CAL_iecvaraccbrowsedown2  iecvaraccbrowsedown2
	#define CHK_iecvaraccbrowsedown2  TRUE
	#define EXP_iecvaraccbrowsedown2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccbrowsedown2", (RTS_UINTPTR)iecvaraccbrowsedown2, 1, 0, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_iecvaraccbrowsedown2  PFIECVARACCBROWSEDOWN2_IEC pfiecvaraccbrowsedown2;
	#define EXT_iecvaraccbrowsedown2  extern PFIECVARACCBROWSEDOWN2_IEC pfiecvaraccbrowsedown2;
	#define GET_iecvaraccbrowsedown2(fl)  s_pfCMGetAPI2( "iecvaraccbrowsedown2", (RTS_VOID_FCTPTR *)&pfiecvaraccbrowsedown2, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0, 0x03050F00)
	#define CAL_iecvaraccbrowsedown2  pfiecvaraccbrowsedown2
	#define CHK_iecvaraccbrowsedown2  (pfiecvaraccbrowsedown2 != NULL)
	#define EXP_iecvaraccbrowsedown2   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccbrowsedown2", (RTS_UINTPTR)iecvaraccbrowsedown2, 1, 0, 0x03050F00) 
#endif


/**
 * <description>iecvaraccbrowsegetnext2</description>
 */
typedef struct tagiecvaraccbrowsegetnext2_struct
{
	RTS_IEC_HANDLE hInterface;			/* VAR_INPUT */	
	IBaseTreeNode *hNode;				/* VAR_INPUT */	
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	IBaseTreeNode *IecVarAccBrowseGetNext2;	/* VAR_OUTPUT */	
} iecvaraccbrowsegetnext2_struct;

void CDECL CDECL_EXT iecvaraccbrowsegetnext2(iecvaraccbrowsegetnext2_struct *p);
typedef void (CDECL CDECL_EXT* PFIECVARACCBROWSEGETNEXT2_IEC) (iecvaraccbrowsegetnext2_struct *p);
#if defined(CMPIECVARACCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(IECVARACCBROWSEGETNEXT2_NOTIMPLEMENTED)
	#define USE_iecvaraccbrowsegetnext2
	#define EXT_iecvaraccbrowsegetnext2
	#define GET_iecvaraccbrowsegetnext2(fl)  ERR_NOTIMPLEMENTED
	#define CAL_iecvaraccbrowsegetnext2(p0) 
	#define CHK_iecvaraccbrowsegetnext2  FALSE
	#define EXP_iecvaraccbrowsegetnext2  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_iecvaraccbrowsegetnext2
	#define EXT_iecvaraccbrowsegetnext2
	#define GET_iecvaraccbrowsegetnext2(fl)  CAL_CMGETAPI( "iecvaraccbrowsegetnext2" ) 
	#define CAL_iecvaraccbrowsegetnext2  iecvaraccbrowsegetnext2
	#define CHK_iecvaraccbrowsegetnext2  TRUE
	#define EXP_iecvaraccbrowsegetnext2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccbrowsegetnext2", (RTS_UINTPTR)iecvaraccbrowsegetnext2, 1, 0, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPIECVARACCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_iecvaraccbrowsegetnext2
	#define EXT_iecvaraccbrowsegetnext2
	#define GET_iecvaraccbrowsegetnext2(fl)  CAL_CMGETAPI( "iecvaraccbrowsegetnext2" ) 
	#define CAL_iecvaraccbrowsegetnext2  iecvaraccbrowsegetnext2
	#define CHK_iecvaraccbrowsegetnext2  TRUE
	#define EXP_iecvaraccbrowsegetnext2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccbrowsegetnext2", (RTS_UINTPTR)iecvaraccbrowsegetnext2, 1, 0, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIecVarAccess_Implementationiecvaraccbrowsegetnext2
	#define EXT_CmpIecVarAccess_Implementationiecvaraccbrowsegetnext2
	#define GET_CmpIecVarAccess_Implementationiecvaraccbrowsegetnext2  ERR_OK
	#define CAL_CmpIecVarAccess_Implementationiecvaraccbrowsegetnext2  iecvaraccbrowsegetnext2
	#define CHK_CmpIecVarAccess_Implementationiecvaraccbrowsegetnext2  TRUE
	#define EXP_CmpIecVarAccess_Implementationiecvaraccbrowsegetnext2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccbrowsegetnext2", (RTS_UINTPTR)iecvaraccbrowsegetnext2, 1, 0, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_iecvaraccbrowsegetnext2
	#define EXT_iecvaraccbrowsegetnext2
	#define GET_iecvaraccbrowsegetnext2(fl)  CAL_CMGETAPI( "iecvaraccbrowsegetnext2" ) 
	#define CAL_iecvaraccbrowsegetnext2  iecvaraccbrowsegetnext2
	#define CHK_iecvaraccbrowsegetnext2  TRUE
	#define EXP_iecvaraccbrowsegetnext2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccbrowsegetnext2", (RTS_UINTPTR)iecvaraccbrowsegetnext2, 1, 0, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_iecvaraccbrowsegetnext2  PFIECVARACCBROWSEGETNEXT2_IEC pfiecvaraccbrowsegetnext2;
	#define EXT_iecvaraccbrowsegetnext2  extern PFIECVARACCBROWSEGETNEXT2_IEC pfiecvaraccbrowsegetnext2;
	#define GET_iecvaraccbrowsegetnext2(fl)  s_pfCMGetAPI2( "iecvaraccbrowsegetnext2", (RTS_VOID_FCTPTR *)&pfiecvaraccbrowsegetnext2, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0, 0x03050F00)
	#define CAL_iecvaraccbrowsegetnext2  pfiecvaraccbrowsegetnext2
	#define CHK_iecvaraccbrowsegetnext2  (pfiecvaraccbrowsegetnext2 != NULL)
	#define EXP_iecvaraccbrowsegetnext2   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccbrowsegetnext2", (RTS_UINTPTR)iecvaraccbrowsegetnext2, 1, 0, 0x03050F00) 
#endif


/**
 * <description>iecvaraccbrowserecursive</description>
 */
typedef struct tagiecvaraccbrowserecursive_struct
{
	RTS_IEC_HANDLE hInterface;			/* VAR_INPUT */	
	IBaseTreeNode *hNode;				/* VAR_INPUT */	
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	
	RTS_IEC_BYTE *pfBrowseCallback;		/* VAR_INPUT */	
	RTS_IEC_BYTE *pUserParameter;		/* VAR_INPUT */	
	RTS_IEC_RESULT IecVarAccBrowseRecursive;	/* VAR_OUTPUT */	
} iecvaraccbrowserecursive_struct;

void CDECL CDECL_EXT iecvaraccbrowserecursive(iecvaraccbrowserecursive_struct *p);
typedef void (CDECL CDECL_EXT* PFIECVARACCBROWSERECURSIVE_IEC) (iecvaraccbrowserecursive_struct *p);
#if defined(CMPIECVARACCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(IECVARACCBROWSERECURSIVE_NOTIMPLEMENTED)
	#define USE_iecvaraccbrowserecursive
	#define EXT_iecvaraccbrowserecursive
	#define GET_iecvaraccbrowserecursive(fl)  ERR_NOTIMPLEMENTED
	#define CAL_iecvaraccbrowserecursive(p0) 
	#define CHK_iecvaraccbrowserecursive  FALSE
	#define EXP_iecvaraccbrowserecursive  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_iecvaraccbrowserecursive
	#define EXT_iecvaraccbrowserecursive
	#define GET_iecvaraccbrowserecursive(fl)  CAL_CMGETAPI( "iecvaraccbrowserecursive" ) 
	#define CAL_iecvaraccbrowserecursive  iecvaraccbrowserecursive
	#define CHK_iecvaraccbrowserecursive  TRUE
	#define EXP_iecvaraccbrowserecursive  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccbrowserecursive", (RTS_UINTPTR)iecvaraccbrowserecursive, 1, 0, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPIECVARACCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_iecvaraccbrowserecursive
	#define EXT_iecvaraccbrowserecursive
	#define GET_iecvaraccbrowserecursive(fl)  CAL_CMGETAPI( "iecvaraccbrowserecursive" ) 
	#define CAL_iecvaraccbrowserecursive  iecvaraccbrowserecursive
	#define CHK_iecvaraccbrowserecursive  TRUE
	#define EXP_iecvaraccbrowserecursive  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccbrowserecursive", (RTS_UINTPTR)iecvaraccbrowserecursive, 1, 0, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIecVarAccess_Implementationiecvaraccbrowserecursive
	#define EXT_CmpIecVarAccess_Implementationiecvaraccbrowserecursive
	#define GET_CmpIecVarAccess_Implementationiecvaraccbrowserecursive  ERR_OK
	#define CAL_CmpIecVarAccess_Implementationiecvaraccbrowserecursive  iecvaraccbrowserecursive
	#define CHK_CmpIecVarAccess_Implementationiecvaraccbrowserecursive  TRUE
	#define EXP_CmpIecVarAccess_Implementationiecvaraccbrowserecursive  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccbrowserecursive", (RTS_UINTPTR)iecvaraccbrowserecursive, 1, 0, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_iecvaraccbrowserecursive
	#define EXT_iecvaraccbrowserecursive
	#define GET_iecvaraccbrowserecursive(fl)  CAL_CMGETAPI( "iecvaraccbrowserecursive" ) 
	#define CAL_iecvaraccbrowserecursive  iecvaraccbrowserecursive
	#define CHK_iecvaraccbrowserecursive  TRUE
	#define EXP_iecvaraccbrowserecursive  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccbrowserecursive", (RTS_UINTPTR)iecvaraccbrowserecursive, 1, 0, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_iecvaraccbrowserecursive  PFIECVARACCBROWSERECURSIVE_IEC pfiecvaraccbrowserecursive;
	#define EXT_iecvaraccbrowserecursive  extern PFIECVARACCBROWSERECURSIVE_IEC pfiecvaraccbrowserecursive;
	#define GET_iecvaraccbrowserecursive(fl)  s_pfCMGetAPI2( "iecvaraccbrowserecursive", (RTS_VOID_FCTPTR *)&pfiecvaraccbrowserecursive, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0, 0x03050F00)
	#define CAL_iecvaraccbrowserecursive  pfiecvaraccbrowserecursive
	#define CHK_iecvaraccbrowserecursive  (pfiecvaraccbrowserecursive != NULL)
	#define EXP_iecvaraccbrowserecursive   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccbrowserecursive", (RTS_UINTPTR)iecvaraccbrowserecursive, 1, 0, 0x03050F00) 
#endif


/**
 * <description>iecvaraccbrowseup2</description>
 */
typedef struct tagiecvaraccbrowseup2_struct
{
	RTS_IEC_HANDLE hInterface;			/* VAR_INPUT */	
	IBaseTreeNode *hNode;				/* VAR_INPUT */	
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	IBaseTreeNode *IecVarAccBrowseUp2;	/* VAR_OUTPUT */	
} iecvaraccbrowseup2_struct;

void CDECL CDECL_EXT iecvaraccbrowseup2(iecvaraccbrowseup2_struct *p);
typedef void (CDECL CDECL_EXT* PFIECVARACCBROWSEUP2_IEC) (iecvaraccbrowseup2_struct *p);
#if defined(CMPIECVARACCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(IECVARACCBROWSEUP2_NOTIMPLEMENTED)
	#define USE_iecvaraccbrowseup2
	#define EXT_iecvaraccbrowseup2
	#define GET_iecvaraccbrowseup2(fl)  ERR_NOTIMPLEMENTED
	#define CAL_iecvaraccbrowseup2(p0) 
	#define CHK_iecvaraccbrowseup2  FALSE
	#define EXP_iecvaraccbrowseup2  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_iecvaraccbrowseup2
	#define EXT_iecvaraccbrowseup2
	#define GET_iecvaraccbrowseup2(fl)  CAL_CMGETAPI( "iecvaraccbrowseup2" ) 
	#define CAL_iecvaraccbrowseup2  iecvaraccbrowseup2
	#define CHK_iecvaraccbrowseup2  TRUE
	#define EXP_iecvaraccbrowseup2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccbrowseup2", (RTS_UINTPTR)iecvaraccbrowseup2, 1, 0, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPIECVARACCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_iecvaraccbrowseup2
	#define EXT_iecvaraccbrowseup2
	#define GET_iecvaraccbrowseup2(fl)  CAL_CMGETAPI( "iecvaraccbrowseup2" ) 
	#define CAL_iecvaraccbrowseup2  iecvaraccbrowseup2
	#define CHK_iecvaraccbrowseup2  TRUE
	#define EXP_iecvaraccbrowseup2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccbrowseup2", (RTS_UINTPTR)iecvaraccbrowseup2, 1, 0, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIecVarAccess_Implementationiecvaraccbrowseup2
	#define EXT_CmpIecVarAccess_Implementationiecvaraccbrowseup2
	#define GET_CmpIecVarAccess_Implementationiecvaraccbrowseup2  ERR_OK
	#define CAL_CmpIecVarAccess_Implementationiecvaraccbrowseup2  iecvaraccbrowseup2
	#define CHK_CmpIecVarAccess_Implementationiecvaraccbrowseup2  TRUE
	#define EXP_CmpIecVarAccess_Implementationiecvaraccbrowseup2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccbrowseup2", (RTS_UINTPTR)iecvaraccbrowseup2, 1, 0, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_iecvaraccbrowseup2
	#define EXT_iecvaraccbrowseup2
	#define GET_iecvaraccbrowseup2(fl)  CAL_CMGETAPI( "iecvaraccbrowseup2" ) 
	#define CAL_iecvaraccbrowseup2  iecvaraccbrowseup2
	#define CHK_iecvaraccbrowseup2  TRUE
	#define EXP_iecvaraccbrowseup2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccbrowseup2", (RTS_UINTPTR)iecvaraccbrowseup2, 1, 0, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_iecvaraccbrowseup2  PFIECVARACCBROWSEUP2_IEC pfiecvaraccbrowseup2;
	#define EXT_iecvaraccbrowseup2  extern PFIECVARACCBROWSEUP2_IEC pfiecvaraccbrowseup2;
	#define GET_iecvaraccbrowseup2(fl)  s_pfCMGetAPI2( "iecvaraccbrowseup2", (RTS_VOID_FCTPTR *)&pfiecvaraccbrowseup2, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0, 0x03050F00)
	#define CAL_iecvaraccbrowseup2  pfiecvaraccbrowseup2
	#define CHK_iecvaraccbrowseup2  (pfiecvaraccbrowseup2 != NULL)
	#define EXP_iecvaraccbrowseup2   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccbrowseup2", (RTS_UINTPTR)iecvaraccbrowseup2, 1, 0, 0x03050F00) 
#endif


/**
 * <description>iecvaraccexitvarinfo</description>
 */
typedef struct tagiecvaraccexitvarinfo_struct
{
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	
	RTS_IEC_RESULT IecVarAccExitVarInfo;	/* VAR_OUTPUT */	
} iecvaraccexitvarinfo_struct;

void CDECL CDECL_EXT iecvaraccexitvarinfo(iecvaraccexitvarinfo_struct *p);
typedef void (CDECL CDECL_EXT* PFIECVARACCEXITVARINFO_IEC) (iecvaraccexitvarinfo_struct *p);
#if defined(CMPIECVARACCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(IECVARACCEXITVARINFO_NOTIMPLEMENTED)
	#define USE_iecvaraccexitvarinfo
	#define EXT_iecvaraccexitvarinfo
	#define GET_iecvaraccexitvarinfo(fl)  ERR_NOTIMPLEMENTED
	#define CAL_iecvaraccexitvarinfo(p0) 
	#define CHK_iecvaraccexitvarinfo  FALSE
	#define EXP_iecvaraccexitvarinfo  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_iecvaraccexitvarinfo
	#define EXT_iecvaraccexitvarinfo
	#define GET_iecvaraccexitvarinfo(fl)  CAL_CMGETAPI( "iecvaraccexitvarinfo" ) 
	#define CAL_iecvaraccexitvarinfo  iecvaraccexitvarinfo
	#define CHK_iecvaraccexitvarinfo  TRUE
	#define EXP_iecvaraccexitvarinfo  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccexitvarinfo", (RTS_UINTPTR)iecvaraccexitvarinfo, 1, 0, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPIECVARACCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_iecvaraccexitvarinfo
	#define EXT_iecvaraccexitvarinfo
	#define GET_iecvaraccexitvarinfo(fl)  CAL_CMGETAPI( "iecvaraccexitvarinfo" ) 
	#define CAL_iecvaraccexitvarinfo  iecvaraccexitvarinfo
	#define CHK_iecvaraccexitvarinfo  TRUE
	#define EXP_iecvaraccexitvarinfo  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccexitvarinfo", (RTS_UINTPTR)iecvaraccexitvarinfo, 1, 0, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIecVarAccess_Implementationiecvaraccexitvarinfo
	#define EXT_CmpIecVarAccess_Implementationiecvaraccexitvarinfo
	#define GET_CmpIecVarAccess_Implementationiecvaraccexitvarinfo  ERR_OK
	#define CAL_CmpIecVarAccess_Implementationiecvaraccexitvarinfo  iecvaraccexitvarinfo
	#define CHK_CmpIecVarAccess_Implementationiecvaraccexitvarinfo  TRUE
	#define EXP_CmpIecVarAccess_Implementationiecvaraccexitvarinfo  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccexitvarinfo", (RTS_UINTPTR)iecvaraccexitvarinfo, 1, 0, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_iecvaraccexitvarinfo
	#define EXT_iecvaraccexitvarinfo
	#define GET_iecvaraccexitvarinfo(fl)  CAL_CMGETAPI( "iecvaraccexitvarinfo" ) 
	#define CAL_iecvaraccexitvarinfo  iecvaraccexitvarinfo
	#define CHK_iecvaraccexitvarinfo  TRUE
	#define EXP_iecvaraccexitvarinfo  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccexitvarinfo", (RTS_UINTPTR)iecvaraccexitvarinfo, 1, 0, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_iecvaraccexitvarinfo  PFIECVARACCEXITVARINFO_IEC pfiecvaraccexitvarinfo;
	#define EXT_iecvaraccexitvarinfo  extern PFIECVARACCEXITVARINFO_IEC pfiecvaraccexitvarinfo;
	#define GET_iecvaraccexitvarinfo(fl)  s_pfCMGetAPI2( "iecvaraccexitvarinfo", (RTS_VOID_FCTPTR *)&pfiecvaraccexitvarinfo, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0, 0x03050F00)
	#define CAL_iecvaraccexitvarinfo  pfiecvaraccexitvarinfo
	#define CHK_iecvaraccexitvarinfo  (pfiecvaraccexitvarinfo != NULL)
	#define EXP_iecvaraccexitvarinfo   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccexitvarinfo", (RTS_UINTPTR)iecvaraccexitvarinfo, 1, 0, 0x03050F00) 
#endif


/**
 * <description>iecvaraccgetfirstinterface</description>
 */
typedef struct tagiecvaraccgetfirstinterface_struct
{
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	IIecVarAccess3 *IecVarAccGetFirstInterface;	/* VAR_OUTPUT */	
} iecvaraccgetfirstinterface_struct;

void CDECL CDECL_EXT iecvaraccgetfirstinterface(iecvaraccgetfirstinterface_struct *p);
typedef void (CDECL CDECL_EXT* PFIECVARACCGETFIRSTINTERFACE_IEC) (iecvaraccgetfirstinterface_struct *p);
#if defined(CMPIECVARACCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(IECVARACCGETFIRSTINTERFACE_NOTIMPLEMENTED)
	#define USE_iecvaraccgetfirstinterface
	#define EXT_iecvaraccgetfirstinterface
	#define GET_iecvaraccgetfirstinterface(fl)  ERR_NOTIMPLEMENTED
	#define CAL_iecvaraccgetfirstinterface(p0) 
	#define CHK_iecvaraccgetfirstinterface  FALSE
	#define EXP_iecvaraccgetfirstinterface  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_iecvaraccgetfirstinterface
	#define EXT_iecvaraccgetfirstinterface
	#define GET_iecvaraccgetfirstinterface(fl)  CAL_CMGETAPI( "iecvaraccgetfirstinterface" ) 
	#define CAL_iecvaraccgetfirstinterface  iecvaraccgetfirstinterface
	#define CHK_iecvaraccgetfirstinterface  TRUE
	#define EXP_iecvaraccgetfirstinterface  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetfirstinterface", (RTS_UINTPTR)iecvaraccgetfirstinterface, 1, RTSITF_GET_SIGNATURE(0, 0xDAF18C6C), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPIECVARACCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_iecvaraccgetfirstinterface
	#define EXT_iecvaraccgetfirstinterface
	#define GET_iecvaraccgetfirstinterface(fl)  CAL_CMGETAPI( "iecvaraccgetfirstinterface" ) 
	#define CAL_iecvaraccgetfirstinterface  iecvaraccgetfirstinterface
	#define CHK_iecvaraccgetfirstinterface  TRUE
	#define EXP_iecvaraccgetfirstinterface  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetfirstinterface", (RTS_UINTPTR)iecvaraccgetfirstinterface, 1, RTSITF_GET_SIGNATURE(0, 0xDAF18C6C), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIecVarAccess_Implementationiecvaraccgetfirstinterface
	#define EXT_CmpIecVarAccess_Implementationiecvaraccgetfirstinterface
	#define GET_CmpIecVarAccess_Implementationiecvaraccgetfirstinterface  ERR_OK
	#define CAL_CmpIecVarAccess_Implementationiecvaraccgetfirstinterface  iecvaraccgetfirstinterface
	#define CHK_CmpIecVarAccess_Implementationiecvaraccgetfirstinterface  TRUE
	#define EXP_CmpIecVarAccess_Implementationiecvaraccgetfirstinterface  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetfirstinterface", (RTS_UINTPTR)iecvaraccgetfirstinterface, 1, RTSITF_GET_SIGNATURE(0, 0xDAF18C6C), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_iecvaraccgetfirstinterface
	#define EXT_iecvaraccgetfirstinterface
	#define GET_iecvaraccgetfirstinterface(fl)  CAL_CMGETAPI( "iecvaraccgetfirstinterface" ) 
	#define CAL_iecvaraccgetfirstinterface  iecvaraccgetfirstinterface
	#define CHK_iecvaraccgetfirstinterface  TRUE
	#define EXP_iecvaraccgetfirstinterface  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetfirstinterface", (RTS_UINTPTR)iecvaraccgetfirstinterface, 1, RTSITF_GET_SIGNATURE(0, 0xDAF18C6C), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_iecvaraccgetfirstinterface  PFIECVARACCGETFIRSTINTERFACE_IEC pfiecvaraccgetfirstinterface;
	#define EXT_iecvaraccgetfirstinterface  extern PFIECVARACCGETFIRSTINTERFACE_IEC pfiecvaraccgetfirstinterface;
	#define GET_iecvaraccgetfirstinterface(fl)  s_pfCMGetAPI2( "iecvaraccgetfirstinterface", (RTS_VOID_FCTPTR *)&pfiecvaraccgetfirstinterface, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xDAF18C6C), 0x03050F00)
	#define CAL_iecvaraccgetfirstinterface  pfiecvaraccgetfirstinterface
	#define CHK_iecvaraccgetfirstinterface  (pfiecvaraccgetfirstinterface != NULL)
	#define EXP_iecvaraccgetfirstinterface   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetfirstinterface", (RTS_UINTPTR)iecvaraccgetfirstinterface, 1, RTSITF_GET_SIGNATURE(0, 0xDAF18C6C), 0x03050F00) 
#endif


/**
 * <description>iecvaraccgetfirstinterface2</description>
 */
typedef struct tagiecvaraccgetfirstinterface2_struct
{
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	IBase *IecVarAccGetFirstInterface2;	/* VAR_OUTPUT */	
} iecvaraccgetfirstinterface2_struct;

void CDECL CDECL_EXT iecvaraccgetfirstinterface2(iecvaraccgetfirstinterface2_struct *p);
typedef void (CDECL CDECL_EXT* PFIECVARACCGETFIRSTINTERFACE2_IEC) (iecvaraccgetfirstinterface2_struct *p);
#if defined(CMPIECVARACCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(IECVARACCGETFIRSTINTERFACE2_NOTIMPLEMENTED)
	#define USE_iecvaraccgetfirstinterface2
	#define EXT_iecvaraccgetfirstinterface2
	#define GET_iecvaraccgetfirstinterface2(fl)  ERR_NOTIMPLEMENTED
	#define CAL_iecvaraccgetfirstinterface2(p0) 
	#define CHK_iecvaraccgetfirstinterface2  FALSE
	#define EXP_iecvaraccgetfirstinterface2  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_iecvaraccgetfirstinterface2
	#define EXT_iecvaraccgetfirstinterface2
	#define GET_iecvaraccgetfirstinterface2(fl)  CAL_CMGETAPI( "iecvaraccgetfirstinterface2" ) 
	#define CAL_iecvaraccgetfirstinterface2  iecvaraccgetfirstinterface2
	#define CHK_iecvaraccgetfirstinterface2  TRUE
	#define EXP_iecvaraccgetfirstinterface2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetfirstinterface2", (RTS_UINTPTR)iecvaraccgetfirstinterface2, 1, RTSITF_GET_SIGNATURE(0, 0x35A559A4), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPIECVARACCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_iecvaraccgetfirstinterface2
	#define EXT_iecvaraccgetfirstinterface2
	#define GET_iecvaraccgetfirstinterface2(fl)  CAL_CMGETAPI( "iecvaraccgetfirstinterface2" ) 
	#define CAL_iecvaraccgetfirstinterface2  iecvaraccgetfirstinterface2
	#define CHK_iecvaraccgetfirstinterface2  TRUE
	#define EXP_iecvaraccgetfirstinterface2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetfirstinterface2", (RTS_UINTPTR)iecvaraccgetfirstinterface2, 1, RTSITF_GET_SIGNATURE(0, 0x35A559A4), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIecVarAccess_Implementationiecvaraccgetfirstinterface2
	#define EXT_CmpIecVarAccess_Implementationiecvaraccgetfirstinterface2
	#define GET_CmpIecVarAccess_Implementationiecvaraccgetfirstinterface2  ERR_OK
	#define CAL_CmpIecVarAccess_Implementationiecvaraccgetfirstinterface2  iecvaraccgetfirstinterface2
	#define CHK_CmpIecVarAccess_Implementationiecvaraccgetfirstinterface2  TRUE
	#define EXP_CmpIecVarAccess_Implementationiecvaraccgetfirstinterface2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetfirstinterface2", (RTS_UINTPTR)iecvaraccgetfirstinterface2, 1, RTSITF_GET_SIGNATURE(0, 0x35A559A4), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_iecvaraccgetfirstinterface2
	#define EXT_iecvaraccgetfirstinterface2
	#define GET_iecvaraccgetfirstinterface2(fl)  CAL_CMGETAPI( "iecvaraccgetfirstinterface2" ) 
	#define CAL_iecvaraccgetfirstinterface2  iecvaraccgetfirstinterface2
	#define CHK_iecvaraccgetfirstinterface2  TRUE
	#define EXP_iecvaraccgetfirstinterface2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetfirstinterface2", (RTS_UINTPTR)iecvaraccgetfirstinterface2, 1, RTSITF_GET_SIGNATURE(0, 0x35A559A4), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_iecvaraccgetfirstinterface2  PFIECVARACCGETFIRSTINTERFACE2_IEC pfiecvaraccgetfirstinterface2;
	#define EXT_iecvaraccgetfirstinterface2  extern PFIECVARACCGETFIRSTINTERFACE2_IEC pfiecvaraccgetfirstinterface2;
	#define GET_iecvaraccgetfirstinterface2(fl)  s_pfCMGetAPI2( "iecvaraccgetfirstinterface2", (RTS_VOID_FCTPTR *)&pfiecvaraccgetfirstinterface2, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x35A559A4), 0x03050F00)
	#define CAL_iecvaraccgetfirstinterface2  pfiecvaraccgetfirstinterface2
	#define CHK_iecvaraccgetfirstinterface2  (pfiecvaraccgetfirstinterface2 != NULL)
	#define EXP_iecvaraccgetfirstinterface2   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetfirstinterface2", (RTS_UINTPTR)iecvaraccgetfirstinterface2, 1, RTSITF_GET_SIGNATURE(0, 0x35A559A4), 0x03050F00) 
#endif


/**
 * <description>iecvaraccgetnextinterface</description>
 */
typedef struct tagiecvaraccgetnextinterface_struct
{
	IIecVarAccess3 *pIPrev;				/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	IIecVarAccess3 *IecVarAccGetNextInterface;	/* VAR_OUTPUT */	
} iecvaraccgetnextinterface_struct;

void CDECL CDECL_EXT iecvaraccgetnextinterface(iecvaraccgetnextinterface_struct *p);
typedef void (CDECL CDECL_EXT* PFIECVARACCGETNEXTINTERFACE_IEC) (iecvaraccgetnextinterface_struct *p);
#if defined(CMPIECVARACCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(IECVARACCGETNEXTINTERFACE_NOTIMPLEMENTED)
	#define USE_iecvaraccgetnextinterface
	#define EXT_iecvaraccgetnextinterface
	#define GET_iecvaraccgetnextinterface(fl)  ERR_NOTIMPLEMENTED
	#define CAL_iecvaraccgetnextinterface(p0) 
	#define CHK_iecvaraccgetnextinterface  FALSE
	#define EXP_iecvaraccgetnextinterface  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_iecvaraccgetnextinterface
	#define EXT_iecvaraccgetnextinterface
	#define GET_iecvaraccgetnextinterface(fl)  CAL_CMGETAPI( "iecvaraccgetnextinterface" ) 
	#define CAL_iecvaraccgetnextinterface  iecvaraccgetnextinterface
	#define CHK_iecvaraccgetnextinterface  TRUE
	#define EXP_iecvaraccgetnextinterface  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetnextinterface", (RTS_UINTPTR)iecvaraccgetnextinterface, 1, RTSITF_GET_SIGNATURE(0, 0x7143BBE4), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPIECVARACCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_iecvaraccgetnextinterface
	#define EXT_iecvaraccgetnextinterface
	#define GET_iecvaraccgetnextinterface(fl)  CAL_CMGETAPI( "iecvaraccgetnextinterface" ) 
	#define CAL_iecvaraccgetnextinterface  iecvaraccgetnextinterface
	#define CHK_iecvaraccgetnextinterface  TRUE
	#define EXP_iecvaraccgetnextinterface  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetnextinterface", (RTS_UINTPTR)iecvaraccgetnextinterface, 1, RTSITF_GET_SIGNATURE(0, 0x7143BBE4), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIecVarAccess_Implementationiecvaraccgetnextinterface
	#define EXT_CmpIecVarAccess_Implementationiecvaraccgetnextinterface
	#define GET_CmpIecVarAccess_Implementationiecvaraccgetnextinterface  ERR_OK
	#define CAL_CmpIecVarAccess_Implementationiecvaraccgetnextinterface  iecvaraccgetnextinterface
	#define CHK_CmpIecVarAccess_Implementationiecvaraccgetnextinterface  TRUE
	#define EXP_CmpIecVarAccess_Implementationiecvaraccgetnextinterface  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetnextinterface", (RTS_UINTPTR)iecvaraccgetnextinterface, 1, RTSITF_GET_SIGNATURE(0, 0x7143BBE4), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_iecvaraccgetnextinterface
	#define EXT_iecvaraccgetnextinterface
	#define GET_iecvaraccgetnextinterface(fl)  CAL_CMGETAPI( "iecvaraccgetnextinterface" ) 
	#define CAL_iecvaraccgetnextinterface  iecvaraccgetnextinterface
	#define CHK_iecvaraccgetnextinterface  TRUE
	#define EXP_iecvaraccgetnextinterface  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetnextinterface", (RTS_UINTPTR)iecvaraccgetnextinterface, 1, RTSITF_GET_SIGNATURE(0, 0x7143BBE4), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_iecvaraccgetnextinterface  PFIECVARACCGETNEXTINTERFACE_IEC pfiecvaraccgetnextinterface;
	#define EXT_iecvaraccgetnextinterface  extern PFIECVARACCGETNEXTINTERFACE_IEC pfiecvaraccgetnextinterface;
	#define GET_iecvaraccgetnextinterface(fl)  s_pfCMGetAPI2( "iecvaraccgetnextinterface", (RTS_VOID_FCTPTR *)&pfiecvaraccgetnextinterface, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x7143BBE4), 0x03050F00)
	#define CAL_iecvaraccgetnextinterface  pfiecvaraccgetnextinterface
	#define CHK_iecvaraccgetnextinterface  (pfiecvaraccgetnextinterface != NULL)
	#define EXP_iecvaraccgetnextinterface   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetnextinterface", (RTS_UINTPTR)iecvaraccgetnextinterface, 1, RTSITF_GET_SIGNATURE(0, 0x7143BBE4), 0x03050F00) 
#endif


/**
 * <description>iecvaraccgetnextinterface2</description>
 */
typedef struct tagiecvaraccgetnextinterface2_struct
{
	IBase *pIPrev;						/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	IBase *IecVarAccGetNextInterface2;	/* VAR_OUTPUT */	
} iecvaraccgetnextinterface2_struct;

void CDECL CDECL_EXT iecvaraccgetnextinterface2(iecvaraccgetnextinterface2_struct *p);
typedef void (CDECL CDECL_EXT* PFIECVARACCGETNEXTINTERFACE2_IEC) (iecvaraccgetnextinterface2_struct *p);
#if defined(CMPIECVARACCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(IECVARACCGETNEXTINTERFACE2_NOTIMPLEMENTED)
	#define USE_iecvaraccgetnextinterface2
	#define EXT_iecvaraccgetnextinterface2
	#define GET_iecvaraccgetnextinterface2(fl)  ERR_NOTIMPLEMENTED
	#define CAL_iecvaraccgetnextinterface2(p0) 
	#define CHK_iecvaraccgetnextinterface2  FALSE
	#define EXP_iecvaraccgetnextinterface2  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_iecvaraccgetnextinterface2
	#define EXT_iecvaraccgetnextinterface2
	#define GET_iecvaraccgetnextinterface2(fl)  CAL_CMGETAPI( "iecvaraccgetnextinterface2" ) 
	#define CAL_iecvaraccgetnextinterface2  iecvaraccgetnextinterface2
	#define CHK_iecvaraccgetnextinterface2  TRUE
	#define EXP_iecvaraccgetnextinterface2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetnextinterface2", (RTS_UINTPTR)iecvaraccgetnextinterface2, 1, RTSITF_GET_SIGNATURE(0, 0xDCA77F90), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPIECVARACCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_iecvaraccgetnextinterface2
	#define EXT_iecvaraccgetnextinterface2
	#define GET_iecvaraccgetnextinterface2(fl)  CAL_CMGETAPI( "iecvaraccgetnextinterface2" ) 
	#define CAL_iecvaraccgetnextinterface2  iecvaraccgetnextinterface2
	#define CHK_iecvaraccgetnextinterface2  TRUE
	#define EXP_iecvaraccgetnextinterface2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetnextinterface2", (RTS_UINTPTR)iecvaraccgetnextinterface2, 1, RTSITF_GET_SIGNATURE(0, 0xDCA77F90), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIecVarAccess_Implementationiecvaraccgetnextinterface2
	#define EXT_CmpIecVarAccess_Implementationiecvaraccgetnextinterface2
	#define GET_CmpIecVarAccess_Implementationiecvaraccgetnextinterface2  ERR_OK
	#define CAL_CmpIecVarAccess_Implementationiecvaraccgetnextinterface2  iecvaraccgetnextinterface2
	#define CHK_CmpIecVarAccess_Implementationiecvaraccgetnextinterface2  TRUE
	#define EXP_CmpIecVarAccess_Implementationiecvaraccgetnextinterface2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetnextinterface2", (RTS_UINTPTR)iecvaraccgetnextinterface2, 1, RTSITF_GET_SIGNATURE(0, 0xDCA77F90), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_iecvaraccgetnextinterface2
	#define EXT_iecvaraccgetnextinterface2
	#define GET_iecvaraccgetnextinterface2(fl)  CAL_CMGETAPI( "iecvaraccgetnextinterface2" ) 
	#define CAL_iecvaraccgetnextinterface2  iecvaraccgetnextinterface2
	#define CHK_iecvaraccgetnextinterface2  TRUE
	#define EXP_iecvaraccgetnextinterface2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetnextinterface2", (RTS_UINTPTR)iecvaraccgetnextinterface2, 1, RTSITF_GET_SIGNATURE(0, 0xDCA77F90), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_iecvaraccgetnextinterface2  PFIECVARACCGETNEXTINTERFACE2_IEC pfiecvaraccgetnextinterface2;
	#define EXT_iecvaraccgetnextinterface2  extern PFIECVARACCGETNEXTINTERFACE2_IEC pfiecvaraccgetnextinterface2;
	#define GET_iecvaraccgetnextinterface2(fl)  s_pfCMGetAPI2( "iecvaraccgetnextinterface2", (RTS_VOID_FCTPTR *)&pfiecvaraccgetnextinterface2, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xDCA77F90), 0x03050F00)
	#define CAL_iecvaraccgetnextinterface2  pfiecvaraccgetnextinterface2
	#define CHK_iecvaraccgetnextinterface2  (pfiecvaraccgetnextinterface2 != NULL)
	#define EXP_iecvaraccgetnextinterface2   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetnextinterface2", (RTS_UINTPTR)iecvaraccgetnextinterface2, 1, RTSITF_GET_SIGNATURE(0, 0xDCA77F90), 0x03050F00) 
#endif


/**
 * <description>iecvaraccgetnode4</description>
 */
typedef struct tagiecvaraccgetnode4_struct
{
	RTS_IEC_STRING *pszPath;			/* VAR_INPUT */	
	RTS_IEC_HANDLE *phInterface;		/* VAR_INPUT */	
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	IBaseTreeNode *IecVarAccGetNode4;	/* VAR_OUTPUT */	
} iecvaraccgetnode4_struct;

void CDECL CDECL_EXT iecvaraccgetnode4(iecvaraccgetnode4_struct *p);
typedef void (CDECL CDECL_EXT* PFIECVARACCGETNODE4_IEC) (iecvaraccgetnode4_struct *p);
#if defined(CMPIECVARACCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(IECVARACCGETNODE4_NOTIMPLEMENTED)
	#define USE_iecvaraccgetnode4
	#define EXT_iecvaraccgetnode4
	#define GET_iecvaraccgetnode4(fl)  ERR_NOTIMPLEMENTED
	#define CAL_iecvaraccgetnode4(p0) 
	#define CHK_iecvaraccgetnode4  FALSE
	#define EXP_iecvaraccgetnode4  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_iecvaraccgetnode4
	#define EXT_iecvaraccgetnode4
	#define GET_iecvaraccgetnode4(fl)  CAL_CMGETAPI( "iecvaraccgetnode4" ) 
	#define CAL_iecvaraccgetnode4  iecvaraccgetnode4
	#define CHK_iecvaraccgetnode4  TRUE
	#define EXP_iecvaraccgetnode4  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetnode4", (RTS_UINTPTR)iecvaraccgetnode4, 1, 0, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPIECVARACCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_iecvaraccgetnode4
	#define EXT_iecvaraccgetnode4
	#define GET_iecvaraccgetnode4(fl)  CAL_CMGETAPI( "iecvaraccgetnode4" ) 
	#define CAL_iecvaraccgetnode4  iecvaraccgetnode4
	#define CHK_iecvaraccgetnode4  TRUE
	#define EXP_iecvaraccgetnode4  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetnode4", (RTS_UINTPTR)iecvaraccgetnode4, 1, 0, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIecVarAccess_Implementationiecvaraccgetnode4
	#define EXT_CmpIecVarAccess_Implementationiecvaraccgetnode4
	#define GET_CmpIecVarAccess_Implementationiecvaraccgetnode4  ERR_OK
	#define CAL_CmpIecVarAccess_Implementationiecvaraccgetnode4  iecvaraccgetnode4
	#define CHK_CmpIecVarAccess_Implementationiecvaraccgetnode4  TRUE
	#define EXP_CmpIecVarAccess_Implementationiecvaraccgetnode4  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetnode4", (RTS_UINTPTR)iecvaraccgetnode4, 1, 0, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_iecvaraccgetnode4
	#define EXT_iecvaraccgetnode4
	#define GET_iecvaraccgetnode4(fl)  CAL_CMGETAPI( "iecvaraccgetnode4" ) 
	#define CAL_iecvaraccgetnode4  iecvaraccgetnode4
	#define CHK_iecvaraccgetnode4  TRUE
	#define EXP_iecvaraccgetnode4  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetnode4", (RTS_UINTPTR)iecvaraccgetnode4, 1, 0, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_iecvaraccgetnode4  PFIECVARACCGETNODE4_IEC pfiecvaraccgetnode4;
	#define EXT_iecvaraccgetnode4  extern PFIECVARACCGETNODE4_IEC pfiecvaraccgetnode4;
	#define GET_iecvaraccgetnode4(fl)  s_pfCMGetAPI2( "iecvaraccgetnode4", (RTS_VOID_FCTPTR *)&pfiecvaraccgetnode4, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0, 0x03050F00)
	#define CAL_iecvaraccgetnode4  pfiecvaraccgetnode4
	#define CHK_iecvaraccgetnode4  (pfiecvaraccgetnode4 != NULL)
	#define EXP_iecvaraccgetnode4   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetnode4", (RTS_UINTPTR)iecvaraccgetnode4, 1, 0, 0x03050F00) 
#endif


/**
 * <description>iecvaraccgetnodefullpath4</description>
 */
typedef struct tagiecvaraccgetnodefullpath4_struct
{
	RTS_IEC_HANDLE hInterface;			/* VAR_INPUT */	
	IBaseTreeNode *hNode;				/* VAR_INPUT */	
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	
	RTS_IEC_STRING *pszPath;			/* VAR_INPUT */	
	RTS_IEC_DINT iMaxPath;				/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_DINT IecVarAccGetNodeFullPath4;	/* VAR_OUTPUT */	
} iecvaraccgetnodefullpath4_struct;

void CDECL CDECL_EXT iecvaraccgetnodefullpath4(iecvaraccgetnodefullpath4_struct *p);
typedef void (CDECL CDECL_EXT* PFIECVARACCGETNODEFULLPATH4_IEC) (iecvaraccgetnodefullpath4_struct *p);
#if defined(CMPIECVARACCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(IECVARACCGETNODEFULLPATH4_NOTIMPLEMENTED)
	#define USE_iecvaraccgetnodefullpath4
	#define EXT_iecvaraccgetnodefullpath4
	#define GET_iecvaraccgetnodefullpath4(fl)  ERR_NOTIMPLEMENTED
	#define CAL_iecvaraccgetnodefullpath4(p0) 
	#define CHK_iecvaraccgetnodefullpath4  FALSE
	#define EXP_iecvaraccgetnodefullpath4  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_iecvaraccgetnodefullpath4
	#define EXT_iecvaraccgetnodefullpath4
	#define GET_iecvaraccgetnodefullpath4(fl)  CAL_CMGETAPI( "iecvaraccgetnodefullpath4" ) 
	#define CAL_iecvaraccgetnodefullpath4  iecvaraccgetnodefullpath4
	#define CHK_iecvaraccgetnodefullpath4  TRUE
	#define EXP_iecvaraccgetnodefullpath4  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetnodefullpath4", (RTS_UINTPTR)iecvaraccgetnodefullpath4, 1, 0, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPIECVARACCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_iecvaraccgetnodefullpath4
	#define EXT_iecvaraccgetnodefullpath4
	#define GET_iecvaraccgetnodefullpath4(fl)  CAL_CMGETAPI( "iecvaraccgetnodefullpath4" ) 
	#define CAL_iecvaraccgetnodefullpath4  iecvaraccgetnodefullpath4
	#define CHK_iecvaraccgetnodefullpath4  TRUE
	#define EXP_iecvaraccgetnodefullpath4  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetnodefullpath4", (RTS_UINTPTR)iecvaraccgetnodefullpath4, 1, 0, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIecVarAccess_Implementationiecvaraccgetnodefullpath4
	#define EXT_CmpIecVarAccess_Implementationiecvaraccgetnodefullpath4
	#define GET_CmpIecVarAccess_Implementationiecvaraccgetnodefullpath4  ERR_OK
	#define CAL_CmpIecVarAccess_Implementationiecvaraccgetnodefullpath4  iecvaraccgetnodefullpath4
	#define CHK_CmpIecVarAccess_Implementationiecvaraccgetnodefullpath4  TRUE
	#define EXP_CmpIecVarAccess_Implementationiecvaraccgetnodefullpath4  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetnodefullpath4", (RTS_UINTPTR)iecvaraccgetnodefullpath4, 1, 0, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_iecvaraccgetnodefullpath4
	#define EXT_iecvaraccgetnodefullpath4
	#define GET_iecvaraccgetnodefullpath4(fl)  CAL_CMGETAPI( "iecvaraccgetnodefullpath4" ) 
	#define CAL_iecvaraccgetnodefullpath4  iecvaraccgetnodefullpath4
	#define CHK_iecvaraccgetnodefullpath4  TRUE
	#define EXP_iecvaraccgetnodefullpath4  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetnodefullpath4", (RTS_UINTPTR)iecvaraccgetnodefullpath4, 1, 0, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_iecvaraccgetnodefullpath4  PFIECVARACCGETNODEFULLPATH4_IEC pfiecvaraccgetnodefullpath4;
	#define EXT_iecvaraccgetnodefullpath4  extern PFIECVARACCGETNODEFULLPATH4_IEC pfiecvaraccgetnodefullpath4;
	#define GET_iecvaraccgetnodefullpath4(fl)  s_pfCMGetAPI2( "iecvaraccgetnodefullpath4", (RTS_VOID_FCTPTR *)&pfiecvaraccgetnodefullpath4, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0, 0x03050F00)
	#define CAL_iecvaraccgetnodefullpath4  pfiecvaraccgetnodefullpath4
	#define CHK_iecvaraccgetnodefullpath4  (pfiecvaraccgetnodefullpath4 != NULL)
	#define EXP_iecvaraccgetnodefullpath4   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetnodefullpath4", (RTS_UINTPTR)iecvaraccgetnodefullpath4, 1, 0, 0x03050F00) 
#endif


/**
 * <description>iecvaraccgetnodename4</description>
 */
typedef struct tagiecvaraccgetnodename4_struct
{
	RTS_IEC_HANDLE hInterface;			/* VAR_INPUT */	
	IBaseTreeNode *hNode;				/* VAR_INPUT */	
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	
	RTS_IEC_STRING *pszNodeName;		/* VAR_INPUT */	
	RTS_IEC_UDINT nNodeNameLen;			/* VAR_INPUT */	
	RTS_IEC_RESULT IecVarAccGetNodeName4;	/* VAR_OUTPUT */	
} iecvaraccgetnodename4_struct;

void CDECL CDECL_EXT iecvaraccgetnodename4(iecvaraccgetnodename4_struct *p);
typedef void (CDECL CDECL_EXT* PFIECVARACCGETNODENAME4_IEC) (iecvaraccgetnodename4_struct *p);
#if defined(CMPIECVARACCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(IECVARACCGETNODENAME4_NOTIMPLEMENTED)
	#define USE_iecvaraccgetnodename4
	#define EXT_iecvaraccgetnodename4
	#define GET_iecvaraccgetnodename4(fl)  ERR_NOTIMPLEMENTED
	#define CAL_iecvaraccgetnodename4(p0) 
	#define CHK_iecvaraccgetnodename4  FALSE
	#define EXP_iecvaraccgetnodename4  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_iecvaraccgetnodename4
	#define EXT_iecvaraccgetnodename4
	#define GET_iecvaraccgetnodename4(fl)  CAL_CMGETAPI( "iecvaraccgetnodename4" ) 
	#define CAL_iecvaraccgetnodename4  iecvaraccgetnodename4
	#define CHK_iecvaraccgetnodename4  TRUE
	#define EXP_iecvaraccgetnodename4  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetnodename4", (RTS_UINTPTR)iecvaraccgetnodename4, 1, 0, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPIECVARACCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_iecvaraccgetnodename4
	#define EXT_iecvaraccgetnodename4
	#define GET_iecvaraccgetnodename4(fl)  CAL_CMGETAPI( "iecvaraccgetnodename4" ) 
	#define CAL_iecvaraccgetnodename4  iecvaraccgetnodename4
	#define CHK_iecvaraccgetnodename4  TRUE
	#define EXP_iecvaraccgetnodename4  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetnodename4", (RTS_UINTPTR)iecvaraccgetnodename4, 1, 0, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIecVarAccess_Implementationiecvaraccgetnodename4
	#define EXT_CmpIecVarAccess_Implementationiecvaraccgetnodename4
	#define GET_CmpIecVarAccess_Implementationiecvaraccgetnodename4  ERR_OK
	#define CAL_CmpIecVarAccess_Implementationiecvaraccgetnodename4  iecvaraccgetnodename4
	#define CHK_CmpIecVarAccess_Implementationiecvaraccgetnodename4  TRUE
	#define EXP_CmpIecVarAccess_Implementationiecvaraccgetnodename4  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetnodename4", (RTS_UINTPTR)iecvaraccgetnodename4, 1, 0, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_iecvaraccgetnodename4
	#define EXT_iecvaraccgetnodename4
	#define GET_iecvaraccgetnodename4(fl)  CAL_CMGETAPI( "iecvaraccgetnodename4" ) 
	#define CAL_iecvaraccgetnodename4  iecvaraccgetnodename4
	#define CHK_iecvaraccgetnodename4  TRUE
	#define EXP_iecvaraccgetnodename4  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetnodename4", (RTS_UINTPTR)iecvaraccgetnodename4, 1, 0, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_iecvaraccgetnodename4  PFIECVARACCGETNODENAME4_IEC pfiecvaraccgetnodename4;
	#define EXT_iecvaraccgetnodename4  extern PFIECVARACCGETNODENAME4_IEC pfiecvaraccgetnodename4;
	#define GET_iecvaraccgetnodename4(fl)  s_pfCMGetAPI2( "iecvaraccgetnodename4", (RTS_VOID_FCTPTR *)&pfiecvaraccgetnodename4, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0, 0x03050F00)
	#define CAL_iecvaraccgetnodename4  pfiecvaraccgetnodename4
	#define CHK_iecvaraccgetnodename4  (pfiecvaraccgetnodename4 != NULL)
	#define EXP_iecvaraccgetnodename4   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetnodename4", (RTS_UINTPTR)iecvaraccgetnodename4, 1, 0, 0x03050F00) 
#endif


/**
 * <description>iecvaraccgetsymbolsetmask</description>
 */
typedef struct tagiecvaraccgetsymbolsetmask_struct
{
	RTS_IEC_HANDLE hUser;				/* VAR_INPUT */	
	RTS_IEC_HANDLE hInterface;			/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_DWORD IecVarAccGetSymbolSetMask;	/* VAR_OUTPUT */	
} iecvaraccgetsymbolsetmask_struct;

void CDECL CDECL_EXT iecvaraccgetsymbolsetmask(iecvaraccgetsymbolsetmask_struct *p);
typedef void (CDECL CDECL_EXT* PFIECVARACCGETSYMBOLSETMASK_IEC) (iecvaraccgetsymbolsetmask_struct *p);
#if defined(CMPIECVARACCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(IECVARACCGETSYMBOLSETMASK_NOTIMPLEMENTED)
	#define USE_iecvaraccgetsymbolsetmask
	#define EXT_iecvaraccgetsymbolsetmask
	#define GET_iecvaraccgetsymbolsetmask(fl)  ERR_NOTIMPLEMENTED
	#define CAL_iecvaraccgetsymbolsetmask(p0) 
	#define CHK_iecvaraccgetsymbolsetmask  FALSE
	#define EXP_iecvaraccgetsymbolsetmask  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_iecvaraccgetsymbolsetmask
	#define EXT_iecvaraccgetsymbolsetmask
	#define GET_iecvaraccgetsymbolsetmask(fl)  CAL_CMGETAPI( "iecvaraccgetsymbolsetmask" ) 
	#define CAL_iecvaraccgetsymbolsetmask  iecvaraccgetsymbolsetmask
	#define CHK_iecvaraccgetsymbolsetmask  TRUE
	#define EXP_iecvaraccgetsymbolsetmask  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetsymbolsetmask", (RTS_UINTPTR)iecvaraccgetsymbolsetmask, 1, 0xCD15F68E, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPIECVARACCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_iecvaraccgetsymbolsetmask
	#define EXT_iecvaraccgetsymbolsetmask
	#define GET_iecvaraccgetsymbolsetmask(fl)  CAL_CMGETAPI( "iecvaraccgetsymbolsetmask" ) 
	#define CAL_iecvaraccgetsymbolsetmask  iecvaraccgetsymbolsetmask
	#define CHK_iecvaraccgetsymbolsetmask  TRUE
	#define EXP_iecvaraccgetsymbolsetmask  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetsymbolsetmask", (RTS_UINTPTR)iecvaraccgetsymbolsetmask, 1, 0xCD15F68E, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIecVarAccess_Implementationiecvaraccgetsymbolsetmask
	#define EXT_CmpIecVarAccess_Implementationiecvaraccgetsymbolsetmask
	#define GET_CmpIecVarAccess_Implementationiecvaraccgetsymbolsetmask  ERR_OK
	#define CAL_CmpIecVarAccess_Implementationiecvaraccgetsymbolsetmask  iecvaraccgetsymbolsetmask
	#define CHK_CmpIecVarAccess_Implementationiecvaraccgetsymbolsetmask  TRUE
	#define EXP_CmpIecVarAccess_Implementationiecvaraccgetsymbolsetmask  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetsymbolsetmask", (RTS_UINTPTR)iecvaraccgetsymbolsetmask, 1, 0xCD15F68E, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_iecvaraccgetsymbolsetmask
	#define EXT_iecvaraccgetsymbolsetmask
	#define GET_iecvaraccgetsymbolsetmask(fl)  CAL_CMGETAPI( "iecvaraccgetsymbolsetmask" ) 
	#define CAL_iecvaraccgetsymbolsetmask  iecvaraccgetsymbolsetmask
	#define CHK_iecvaraccgetsymbolsetmask  TRUE
	#define EXP_iecvaraccgetsymbolsetmask  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetsymbolsetmask", (RTS_UINTPTR)iecvaraccgetsymbolsetmask, 1, 0xCD15F68E, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_iecvaraccgetsymbolsetmask  PFIECVARACCGETSYMBOLSETMASK_IEC pfiecvaraccgetsymbolsetmask;
	#define EXT_iecvaraccgetsymbolsetmask  extern PFIECVARACCGETSYMBOLSETMASK_IEC pfiecvaraccgetsymbolsetmask;
	#define GET_iecvaraccgetsymbolsetmask(fl)  s_pfCMGetAPI2( "iecvaraccgetsymbolsetmask", (RTS_VOID_FCTPTR *)&pfiecvaraccgetsymbolsetmask, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xCD15F68E, 0x03050F00)
	#define CAL_iecvaraccgetsymbolsetmask  pfiecvaraccgetsymbolsetmask
	#define CHK_iecvaraccgetsymbolsetmask  (pfiecvaraccgetsymbolsetmask != NULL)
	#define EXP_iecvaraccgetsymbolsetmask   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccgetsymbolsetmask", (RTS_UINTPTR)iecvaraccgetsymbolsetmask, 1, 0xCD15F68E, 0x03050F00) 
#endif


/**
 * <description>iecvaraccinitvarinfo</description>
 */
typedef struct tagiecvaraccinitvarinfo_struct
{
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	/* Pointer to the variable information struct. After using this method for initialization,
 the struct also needs to be freed with IecVarAccExitVarInfo() to prevent memory leaks in
 the runtime data structures. */
	RTS_IEC_UINT nSizeOfVarInfo;		/* VAR_INPUT */	
	RTS_IEC_RESULT IecVarAccInitVarInfo;	/* VAR_OUTPUT */	
} iecvaraccinitvarinfo_struct;

void CDECL CDECL_EXT iecvaraccinitvarinfo(iecvaraccinitvarinfo_struct *p);
typedef void (CDECL CDECL_EXT* PFIECVARACCINITVARINFO_IEC) (iecvaraccinitvarinfo_struct *p);
#if defined(CMPIECVARACCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(IECVARACCINITVARINFO_NOTIMPLEMENTED)
	#define USE_iecvaraccinitvarinfo
	#define EXT_iecvaraccinitvarinfo
	#define GET_iecvaraccinitvarinfo(fl)  ERR_NOTIMPLEMENTED
	#define CAL_iecvaraccinitvarinfo(p0) 
	#define CHK_iecvaraccinitvarinfo  FALSE
	#define EXP_iecvaraccinitvarinfo  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_iecvaraccinitvarinfo
	#define EXT_iecvaraccinitvarinfo
	#define GET_iecvaraccinitvarinfo(fl)  CAL_CMGETAPI( "iecvaraccinitvarinfo" ) 
	#define CAL_iecvaraccinitvarinfo  iecvaraccinitvarinfo
	#define CHK_iecvaraccinitvarinfo  TRUE
	#define EXP_iecvaraccinitvarinfo  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccinitvarinfo", (RTS_UINTPTR)iecvaraccinitvarinfo, 1, 0, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPIECVARACCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_iecvaraccinitvarinfo
	#define EXT_iecvaraccinitvarinfo
	#define GET_iecvaraccinitvarinfo(fl)  CAL_CMGETAPI( "iecvaraccinitvarinfo" ) 
	#define CAL_iecvaraccinitvarinfo  iecvaraccinitvarinfo
	#define CHK_iecvaraccinitvarinfo  TRUE
	#define EXP_iecvaraccinitvarinfo  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccinitvarinfo", (RTS_UINTPTR)iecvaraccinitvarinfo, 1, 0, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIecVarAccess_Implementationiecvaraccinitvarinfo
	#define EXT_CmpIecVarAccess_Implementationiecvaraccinitvarinfo
	#define GET_CmpIecVarAccess_Implementationiecvaraccinitvarinfo  ERR_OK
	#define CAL_CmpIecVarAccess_Implementationiecvaraccinitvarinfo  iecvaraccinitvarinfo
	#define CHK_CmpIecVarAccess_Implementationiecvaraccinitvarinfo  TRUE
	#define EXP_CmpIecVarAccess_Implementationiecvaraccinitvarinfo  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccinitvarinfo", (RTS_UINTPTR)iecvaraccinitvarinfo, 1, 0, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_iecvaraccinitvarinfo
	#define EXT_iecvaraccinitvarinfo
	#define GET_iecvaraccinitvarinfo(fl)  CAL_CMGETAPI( "iecvaraccinitvarinfo" ) 
	#define CAL_iecvaraccinitvarinfo  iecvaraccinitvarinfo
	#define CHK_iecvaraccinitvarinfo  TRUE
	#define EXP_iecvaraccinitvarinfo  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccinitvarinfo", (RTS_UINTPTR)iecvaraccinitvarinfo, 1, 0, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_iecvaraccinitvarinfo  PFIECVARACCINITVARINFO_IEC pfiecvaraccinitvarinfo;
	#define EXT_iecvaraccinitvarinfo  extern PFIECVARACCINITVARINFO_IEC pfiecvaraccinitvarinfo;
	#define GET_iecvaraccinitvarinfo(fl)  s_pfCMGetAPI2( "iecvaraccinitvarinfo", (RTS_VOID_FCTPTR *)&pfiecvaraccinitvarinfo, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0, 0x03050F00)
	#define CAL_iecvaraccinitvarinfo  pfiecvaraccinitvarinfo
	#define CHK_iecvaraccinitvarinfo  (pfiecvaraccinitvarinfo != NULL)
	#define EXP_iecvaraccinitvarinfo   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccinitvarinfo", (RTS_UINTPTR)iecvaraccinitvarinfo, 1, 0, 0x03050F00) 
#endif


/**
 * <description>iecvaraccinitvarinfo2</description>
 */
typedef struct tagiecvaraccinitvarinfo2_struct
{
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	/* Pointer to the variable information struct. After using this method for initialization,
 the struct also needs to be freed with IecVarAccExitVarInfo() to prevent memory leaks in
 the runtime data structures. */
	RTS_IEC_UINT nSizeOfVarInfo;		/* VAR_INPUT */	
	RTS_IEC_HANDLE hUser;				/* VAR_INPUT */	
	RTS_IEC_RESULT IecVarAccInitVarInfo2;	/* VAR_OUTPUT */	
} iecvaraccinitvarinfo2_struct;

void CDECL CDECL_EXT iecvaraccinitvarinfo2(iecvaraccinitvarinfo2_struct *p);
typedef void (CDECL CDECL_EXT* PFIECVARACCINITVARINFO2_IEC) (iecvaraccinitvarinfo2_struct *p);
#if defined(CMPIECVARACCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(IECVARACCINITVARINFO2_NOTIMPLEMENTED)
	#define USE_iecvaraccinitvarinfo2
	#define EXT_iecvaraccinitvarinfo2
	#define GET_iecvaraccinitvarinfo2(fl)  ERR_NOTIMPLEMENTED
	#define CAL_iecvaraccinitvarinfo2(p0) 
	#define CHK_iecvaraccinitvarinfo2  FALSE
	#define EXP_iecvaraccinitvarinfo2  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_iecvaraccinitvarinfo2
	#define EXT_iecvaraccinitvarinfo2
	#define GET_iecvaraccinitvarinfo2(fl)  CAL_CMGETAPI( "iecvaraccinitvarinfo2" ) 
	#define CAL_iecvaraccinitvarinfo2  iecvaraccinitvarinfo2
	#define CHK_iecvaraccinitvarinfo2  TRUE
	#define EXP_iecvaraccinitvarinfo2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccinitvarinfo2", (RTS_UINTPTR)iecvaraccinitvarinfo2, 1, RTSITF_GET_SIGNATURE(0x3533B10B, 0x07C98E8C), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPIECVARACCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_iecvaraccinitvarinfo2
	#define EXT_iecvaraccinitvarinfo2
	#define GET_iecvaraccinitvarinfo2(fl)  CAL_CMGETAPI( "iecvaraccinitvarinfo2" ) 
	#define CAL_iecvaraccinitvarinfo2  iecvaraccinitvarinfo2
	#define CHK_iecvaraccinitvarinfo2  TRUE
	#define EXP_iecvaraccinitvarinfo2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccinitvarinfo2", (RTS_UINTPTR)iecvaraccinitvarinfo2, 1, RTSITF_GET_SIGNATURE(0x3533B10B, 0x07C98E8C), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIecVarAccess_Implementationiecvaraccinitvarinfo2
	#define EXT_CmpIecVarAccess_Implementationiecvaraccinitvarinfo2
	#define GET_CmpIecVarAccess_Implementationiecvaraccinitvarinfo2  ERR_OK
	#define CAL_CmpIecVarAccess_Implementationiecvaraccinitvarinfo2  iecvaraccinitvarinfo2
	#define CHK_CmpIecVarAccess_Implementationiecvaraccinitvarinfo2  TRUE
	#define EXP_CmpIecVarAccess_Implementationiecvaraccinitvarinfo2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccinitvarinfo2", (RTS_UINTPTR)iecvaraccinitvarinfo2, 1, RTSITF_GET_SIGNATURE(0x3533B10B, 0x07C98E8C), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_iecvaraccinitvarinfo2
	#define EXT_iecvaraccinitvarinfo2
	#define GET_iecvaraccinitvarinfo2(fl)  CAL_CMGETAPI( "iecvaraccinitvarinfo2" ) 
	#define CAL_iecvaraccinitvarinfo2  iecvaraccinitvarinfo2
	#define CHK_iecvaraccinitvarinfo2  TRUE
	#define EXP_iecvaraccinitvarinfo2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccinitvarinfo2", (RTS_UINTPTR)iecvaraccinitvarinfo2, 1, RTSITF_GET_SIGNATURE(0x3533B10B, 0x07C98E8C), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_iecvaraccinitvarinfo2  PFIECVARACCINITVARINFO2_IEC pfiecvaraccinitvarinfo2;
	#define EXT_iecvaraccinitvarinfo2  extern PFIECVARACCINITVARINFO2_IEC pfiecvaraccinitvarinfo2;
	#define GET_iecvaraccinitvarinfo2(fl)  s_pfCMGetAPI2( "iecvaraccinitvarinfo2", (RTS_VOID_FCTPTR *)&pfiecvaraccinitvarinfo2, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0x3533B10B, 0x07C98E8C), 0x03050F00)
	#define CAL_iecvaraccinitvarinfo2  pfiecvaraccinitvarinfo2
	#define CHK_iecvaraccinitvarinfo2  (pfiecvaraccinitvarinfo2 != NULL)
	#define EXP_iecvaraccinitvarinfo2   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccinitvarinfo2", (RTS_UINTPTR)iecvaraccinitvarinfo2, 1, RTSITF_GET_SIGNATURE(0x3533B10B, 0x07C98E8C), 0x03050F00) 
#endif


/**
 * <description>iecvaraccinvalidatenode</description>
 */
typedef struct tagiecvaraccinvalidatenode_struct
{
	RTS_IEC_HANDLE hNode;				/* VAR_INPUT */	
	RTS_IEC_RESULT IecVarAccInvalidateNode;	/* VAR_OUTPUT */	
} iecvaraccinvalidatenode_struct;

void CDECL CDECL_EXT iecvaraccinvalidatenode(iecvaraccinvalidatenode_struct *p);
typedef void (CDECL CDECL_EXT* PFIECVARACCINVALIDATENODE_IEC) (iecvaraccinvalidatenode_struct *p);
#if defined(CMPIECVARACCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(IECVARACCINVALIDATENODE_NOTIMPLEMENTED)
	#define USE_iecvaraccinvalidatenode
	#define EXT_iecvaraccinvalidatenode
	#define GET_iecvaraccinvalidatenode(fl)  ERR_NOTIMPLEMENTED
	#define CAL_iecvaraccinvalidatenode(p0) 
	#define CHK_iecvaraccinvalidatenode  FALSE
	#define EXP_iecvaraccinvalidatenode  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_iecvaraccinvalidatenode
	#define EXT_iecvaraccinvalidatenode
	#define GET_iecvaraccinvalidatenode(fl)  CAL_CMGETAPI( "iecvaraccinvalidatenode" ) 
	#define CAL_iecvaraccinvalidatenode  iecvaraccinvalidatenode
	#define CHK_iecvaraccinvalidatenode  TRUE
	#define EXP_iecvaraccinvalidatenode  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccinvalidatenode", (RTS_UINTPTR)iecvaraccinvalidatenode, 1, RTSITF_GET_SIGNATURE(0, 0x0C905F23), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPIECVARACCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_iecvaraccinvalidatenode
	#define EXT_iecvaraccinvalidatenode
	#define GET_iecvaraccinvalidatenode(fl)  CAL_CMGETAPI( "iecvaraccinvalidatenode" ) 
	#define CAL_iecvaraccinvalidatenode  iecvaraccinvalidatenode
	#define CHK_iecvaraccinvalidatenode  TRUE
	#define EXP_iecvaraccinvalidatenode  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccinvalidatenode", (RTS_UINTPTR)iecvaraccinvalidatenode, 1, RTSITF_GET_SIGNATURE(0, 0x0C905F23), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIecVarAccess_Implementationiecvaraccinvalidatenode
	#define EXT_CmpIecVarAccess_Implementationiecvaraccinvalidatenode
	#define GET_CmpIecVarAccess_Implementationiecvaraccinvalidatenode  ERR_OK
	#define CAL_CmpIecVarAccess_Implementationiecvaraccinvalidatenode  iecvaraccinvalidatenode
	#define CHK_CmpIecVarAccess_Implementationiecvaraccinvalidatenode  TRUE
	#define EXP_CmpIecVarAccess_Implementationiecvaraccinvalidatenode  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccinvalidatenode", (RTS_UINTPTR)iecvaraccinvalidatenode, 1, RTSITF_GET_SIGNATURE(0, 0x0C905F23), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_iecvaraccinvalidatenode
	#define EXT_iecvaraccinvalidatenode
	#define GET_iecvaraccinvalidatenode(fl)  CAL_CMGETAPI( "iecvaraccinvalidatenode" ) 
	#define CAL_iecvaraccinvalidatenode  iecvaraccinvalidatenode
	#define CHK_iecvaraccinvalidatenode  TRUE
	#define EXP_iecvaraccinvalidatenode  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccinvalidatenode", (RTS_UINTPTR)iecvaraccinvalidatenode, 1, RTSITF_GET_SIGNATURE(0, 0x0C905F23), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_iecvaraccinvalidatenode  PFIECVARACCINVALIDATENODE_IEC pfiecvaraccinvalidatenode;
	#define EXT_iecvaraccinvalidatenode  extern PFIECVARACCINVALIDATENODE_IEC pfiecvaraccinvalidatenode;
	#define GET_iecvaraccinvalidatenode(fl)  s_pfCMGetAPI2( "iecvaraccinvalidatenode", (RTS_VOID_FCTPTR *)&pfiecvaraccinvalidatenode, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x0C905F23), 0x03050F00)
	#define CAL_iecvaraccinvalidatenode  pfiecvaraccinvalidatenode
	#define CHK_iecvaraccinvalidatenode  (pfiecvaraccinvalidatenode != NULL)
	#define EXP_iecvaraccinvalidatenode   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccinvalidatenode", (RTS_UINTPTR)iecvaraccinvalidatenode, 1, RTSITF_GET_SIGNATURE(0, 0x0C905F23), 0x03050F00) 
#endif


/**
 * Signature deactivated because of Interface type in RtsBrowseInfo
 */
typedef struct tagiecvaraccnodeinfoaddbrowseinfo_struct
{
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	/* Pointer to the variable information.
 Attention: This needs to be initialized with IecVarAccInitVarInfo() or the function
 will return an error code. It also needs to be freed with IecVarAccExitVarInfo() to
 prevent memory leaks. */
	RtsBrowseInfo *pBrowseInfoData;		/* VAR_INPUT */	/* If this pointer is non-null, the runtime will copy the data into the new buffer.
 If this pointer is null, the new buffer memory will be cleared to zero. */
	RTS_IEC_RESULT IecVarAccNodeInfoAddBrowseInfo;	/* VAR_OUTPUT */	
} iecvaraccnodeinfoaddbrowseinfo_struct;

void CDECL CDECL_EXT iecvaraccnodeinfoaddbrowseinfo(iecvaraccnodeinfoaddbrowseinfo_struct *p);
typedef void (CDECL CDECL_EXT* PFIECVARACCNODEINFOADDBROWSEINFO_IEC) (iecvaraccnodeinfoaddbrowseinfo_struct *p);
#if defined(CMPIECVARACCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(IECVARACCNODEINFOADDBROWSEINFO_NOTIMPLEMENTED)
	#define USE_iecvaraccnodeinfoaddbrowseinfo
	#define EXT_iecvaraccnodeinfoaddbrowseinfo
	#define GET_iecvaraccnodeinfoaddbrowseinfo(fl)  ERR_NOTIMPLEMENTED
	#define CAL_iecvaraccnodeinfoaddbrowseinfo(p0) 
	#define CHK_iecvaraccnodeinfoaddbrowseinfo  FALSE
	#define EXP_iecvaraccnodeinfoaddbrowseinfo  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_iecvaraccnodeinfoaddbrowseinfo
	#define EXT_iecvaraccnodeinfoaddbrowseinfo
	#define GET_iecvaraccnodeinfoaddbrowseinfo(fl)  CAL_CMGETAPI( "iecvaraccnodeinfoaddbrowseinfo" ) 
	#define CAL_iecvaraccnodeinfoaddbrowseinfo  iecvaraccnodeinfoaddbrowseinfo
	#define CHK_iecvaraccnodeinfoaddbrowseinfo  TRUE
	#define EXP_iecvaraccnodeinfoaddbrowseinfo  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccnodeinfoaddbrowseinfo", (RTS_UINTPTR)iecvaraccnodeinfoaddbrowseinfo, 1, 0, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPIECVARACCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_iecvaraccnodeinfoaddbrowseinfo
	#define EXT_iecvaraccnodeinfoaddbrowseinfo
	#define GET_iecvaraccnodeinfoaddbrowseinfo(fl)  CAL_CMGETAPI( "iecvaraccnodeinfoaddbrowseinfo" ) 
	#define CAL_iecvaraccnodeinfoaddbrowseinfo  iecvaraccnodeinfoaddbrowseinfo
	#define CHK_iecvaraccnodeinfoaddbrowseinfo  TRUE
	#define EXP_iecvaraccnodeinfoaddbrowseinfo  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccnodeinfoaddbrowseinfo", (RTS_UINTPTR)iecvaraccnodeinfoaddbrowseinfo, 1, 0, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIecVarAccess_Implementationiecvaraccnodeinfoaddbrowseinfo
	#define EXT_CmpIecVarAccess_Implementationiecvaraccnodeinfoaddbrowseinfo
	#define GET_CmpIecVarAccess_Implementationiecvaraccnodeinfoaddbrowseinfo  ERR_OK
	#define CAL_CmpIecVarAccess_Implementationiecvaraccnodeinfoaddbrowseinfo  iecvaraccnodeinfoaddbrowseinfo
	#define CHK_CmpIecVarAccess_Implementationiecvaraccnodeinfoaddbrowseinfo  TRUE
	#define EXP_CmpIecVarAccess_Implementationiecvaraccnodeinfoaddbrowseinfo  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccnodeinfoaddbrowseinfo", (RTS_UINTPTR)iecvaraccnodeinfoaddbrowseinfo, 1, 0, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_iecvaraccnodeinfoaddbrowseinfo
	#define EXT_iecvaraccnodeinfoaddbrowseinfo
	#define GET_iecvaraccnodeinfoaddbrowseinfo(fl)  CAL_CMGETAPI( "iecvaraccnodeinfoaddbrowseinfo" ) 
	#define CAL_iecvaraccnodeinfoaddbrowseinfo  iecvaraccnodeinfoaddbrowseinfo
	#define CHK_iecvaraccnodeinfoaddbrowseinfo  TRUE
	#define EXP_iecvaraccnodeinfoaddbrowseinfo  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccnodeinfoaddbrowseinfo", (RTS_UINTPTR)iecvaraccnodeinfoaddbrowseinfo, 1, 0, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_iecvaraccnodeinfoaddbrowseinfo  PFIECVARACCNODEINFOADDBROWSEINFO_IEC pfiecvaraccnodeinfoaddbrowseinfo;
	#define EXT_iecvaraccnodeinfoaddbrowseinfo  extern PFIECVARACCNODEINFOADDBROWSEINFO_IEC pfiecvaraccnodeinfoaddbrowseinfo;
	#define GET_iecvaraccnodeinfoaddbrowseinfo(fl)  s_pfCMGetAPI2( "iecvaraccnodeinfoaddbrowseinfo", (RTS_VOID_FCTPTR *)&pfiecvaraccnodeinfoaddbrowseinfo, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0, 0x03050F00)
	#define CAL_iecvaraccnodeinfoaddbrowseinfo  pfiecvaraccnodeinfoaddbrowseinfo
	#define CHK_iecvaraccnodeinfoaddbrowseinfo  (pfiecvaraccnodeinfoaddbrowseinfo != NULL)
	#define EXP_iecvaraccnodeinfoaddbrowseinfo   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccnodeinfoaddbrowseinfo", (RTS_UINTPTR)iecvaraccnodeinfoaddbrowseinfo, 1, 0, 0x03050F00) 
#endif


/**
 * <description>iecvaraccnodeinfoaddreference</description>
 */
typedef struct tagiecvaraccnodeinfoaddreference_struct
{
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	/* Pointer to the variable information.
 Attention: This needs to be initialized with IecVarAccInitVarInfo() or the function
 will return an error code. It also needs to be freed with IecVarAccExitVarInfo() to
 prevent memory leaks. */
	RTS_IEC_BYTE *pReferenceInfoData;	/* VAR_INPUT */	/* If this pointer is non-null, the runtime will copy the data into the new buffer.
 If this pointer is null, the new buffer memory will be cleared to zero. */
	RTS_IEC_XWORD nInfoSize;			/* VAR_INPUT */	/* The size of the memory to allocate. */
	RTS_IEC_BYTE **pNewReferenceInfo;	/* VAR_INPUT */	/* If this pointer is non-null, the runtime will store the address of
 the allocated block in this pointer. (This is the same as a subsequent
 call to VarAccNodeInfoGetReference() shall return.) */
	RTS_IEC_RESULT IecVarAccNodeInfoAddReference;	/* VAR_OUTPUT */	
} iecvaraccnodeinfoaddreference_struct;

void CDECL CDECL_EXT iecvaraccnodeinfoaddreference(iecvaraccnodeinfoaddreference_struct *p);
typedef void (CDECL CDECL_EXT* PFIECVARACCNODEINFOADDREFERENCE_IEC) (iecvaraccnodeinfoaddreference_struct *p);
#if defined(CMPIECVARACCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(IECVARACCNODEINFOADDREFERENCE_NOTIMPLEMENTED)
	#define USE_iecvaraccnodeinfoaddreference
	#define EXT_iecvaraccnodeinfoaddreference
	#define GET_iecvaraccnodeinfoaddreference(fl)  ERR_NOTIMPLEMENTED
	#define CAL_iecvaraccnodeinfoaddreference(p0) 
	#define CHK_iecvaraccnodeinfoaddreference  FALSE
	#define EXP_iecvaraccnodeinfoaddreference  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_iecvaraccnodeinfoaddreference
	#define EXT_iecvaraccnodeinfoaddreference
	#define GET_iecvaraccnodeinfoaddreference(fl)  CAL_CMGETAPI( "iecvaraccnodeinfoaddreference" ) 
	#define CAL_iecvaraccnodeinfoaddreference  iecvaraccnodeinfoaddreference
	#define CHK_iecvaraccnodeinfoaddreference  TRUE
	#define EXP_iecvaraccnodeinfoaddreference  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccnodeinfoaddreference", (RTS_UINTPTR)iecvaraccnodeinfoaddreference, 1, RTSITF_GET_SIGNATURE(0xB66D74DC, 0x54D1E739), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPIECVARACCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_iecvaraccnodeinfoaddreference
	#define EXT_iecvaraccnodeinfoaddreference
	#define GET_iecvaraccnodeinfoaddreference(fl)  CAL_CMGETAPI( "iecvaraccnodeinfoaddreference" ) 
	#define CAL_iecvaraccnodeinfoaddreference  iecvaraccnodeinfoaddreference
	#define CHK_iecvaraccnodeinfoaddreference  TRUE
	#define EXP_iecvaraccnodeinfoaddreference  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccnodeinfoaddreference", (RTS_UINTPTR)iecvaraccnodeinfoaddreference, 1, RTSITF_GET_SIGNATURE(0xB66D74DC, 0x54D1E739), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIecVarAccess_Implementationiecvaraccnodeinfoaddreference
	#define EXT_CmpIecVarAccess_Implementationiecvaraccnodeinfoaddreference
	#define GET_CmpIecVarAccess_Implementationiecvaraccnodeinfoaddreference  ERR_OK
	#define CAL_CmpIecVarAccess_Implementationiecvaraccnodeinfoaddreference  iecvaraccnodeinfoaddreference
	#define CHK_CmpIecVarAccess_Implementationiecvaraccnodeinfoaddreference  TRUE
	#define EXP_CmpIecVarAccess_Implementationiecvaraccnodeinfoaddreference  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccnodeinfoaddreference", (RTS_UINTPTR)iecvaraccnodeinfoaddreference, 1, RTSITF_GET_SIGNATURE(0xB66D74DC, 0x54D1E739), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_iecvaraccnodeinfoaddreference
	#define EXT_iecvaraccnodeinfoaddreference
	#define GET_iecvaraccnodeinfoaddreference(fl)  CAL_CMGETAPI( "iecvaraccnodeinfoaddreference" ) 
	#define CAL_iecvaraccnodeinfoaddreference  iecvaraccnodeinfoaddreference
	#define CHK_iecvaraccnodeinfoaddreference  TRUE
	#define EXP_iecvaraccnodeinfoaddreference  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccnodeinfoaddreference", (RTS_UINTPTR)iecvaraccnodeinfoaddreference, 1, RTSITF_GET_SIGNATURE(0xB66D74DC, 0x54D1E739), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_iecvaraccnodeinfoaddreference  PFIECVARACCNODEINFOADDREFERENCE_IEC pfiecvaraccnodeinfoaddreference;
	#define EXT_iecvaraccnodeinfoaddreference  extern PFIECVARACCNODEINFOADDREFERENCE_IEC pfiecvaraccnodeinfoaddreference;
	#define GET_iecvaraccnodeinfoaddreference(fl)  s_pfCMGetAPI2( "iecvaraccnodeinfoaddreference", (RTS_VOID_FCTPTR *)&pfiecvaraccnodeinfoaddreference, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0xB66D74DC, 0x54D1E739), 0x03050F00)
	#define CAL_iecvaraccnodeinfoaddreference  pfiecvaraccnodeinfoaddreference
	#define CHK_iecvaraccnodeinfoaddreference  (pfiecvaraccnodeinfoaddreference != NULL)
	#define EXP_iecvaraccnodeinfoaddreference   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccnodeinfoaddreference", (RTS_UINTPTR)iecvaraccnodeinfoaddreference, 1, RTSITF_GET_SIGNATURE(0xB66D74DC, 0x54D1E739), 0x03050F00) 
#endif


/**
 * Signature deactivated because of Interface type in RtsBrowseInfo
 */
typedef struct tagiecvaraccnodeinfogetbrowseinfo_struct
{
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	
	RtsBrowseInfo *pLast;				/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RtsBrowseInfo *IecVarAccNodeInfoGetBrowseInfo;	/* VAR_OUTPUT */	
} iecvaraccnodeinfogetbrowseinfo_struct;

void CDECL CDECL_EXT iecvaraccnodeinfogetbrowseinfo(iecvaraccnodeinfogetbrowseinfo_struct *p);
typedef void (CDECL CDECL_EXT* PFIECVARACCNODEINFOGETBROWSEINFO_IEC) (iecvaraccnodeinfogetbrowseinfo_struct *p);
#if defined(CMPIECVARACCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(IECVARACCNODEINFOGETBROWSEINFO_NOTIMPLEMENTED)
	#define USE_iecvaraccnodeinfogetbrowseinfo
	#define EXT_iecvaraccnodeinfogetbrowseinfo
	#define GET_iecvaraccnodeinfogetbrowseinfo(fl)  ERR_NOTIMPLEMENTED
	#define CAL_iecvaraccnodeinfogetbrowseinfo(p0) 
	#define CHK_iecvaraccnodeinfogetbrowseinfo  FALSE
	#define EXP_iecvaraccnodeinfogetbrowseinfo  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_iecvaraccnodeinfogetbrowseinfo
	#define EXT_iecvaraccnodeinfogetbrowseinfo
	#define GET_iecvaraccnodeinfogetbrowseinfo(fl)  CAL_CMGETAPI( "iecvaraccnodeinfogetbrowseinfo" ) 
	#define CAL_iecvaraccnodeinfogetbrowseinfo  iecvaraccnodeinfogetbrowseinfo
	#define CHK_iecvaraccnodeinfogetbrowseinfo  TRUE
	#define EXP_iecvaraccnodeinfogetbrowseinfo  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccnodeinfogetbrowseinfo", (RTS_UINTPTR)iecvaraccnodeinfogetbrowseinfo, 1, 0, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPIECVARACCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_iecvaraccnodeinfogetbrowseinfo
	#define EXT_iecvaraccnodeinfogetbrowseinfo
	#define GET_iecvaraccnodeinfogetbrowseinfo(fl)  CAL_CMGETAPI( "iecvaraccnodeinfogetbrowseinfo" ) 
	#define CAL_iecvaraccnodeinfogetbrowseinfo  iecvaraccnodeinfogetbrowseinfo
	#define CHK_iecvaraccnodeinfogetbrowseinfo  TRUE
	#define EXP_iecvaraccnodeinfogetbrowseinfo  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccnodeinfogetbrowseinfo", (RTS_UINTPTR)iecvaraccnodeinfogetbrowseinfo, 1, 0, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIecVarAccess_Implementationiecvaraccnodeinfogetbrowseinfo
	#define EXT_CmpIecVarAccess_Implementationiecvaraccnodeinfogetbrowseinfo
	#define GET_CmpIecVarAccess_Implementationiecvaraccnodeinfogetbrowseinfo  ERR_OK
	#define CAL_CmpIecVarAccess_Implementationiecvaraccnodeinfogetbrowseinfo  iecvaraccnodeinfogetbrowseinfo
	#define CHK_CmpIecVarAccess_Implementationiecvaraccnodeinfogetbrowseinfo  TRUE
	#define EXP_CmpIecVarAccess_Implementationiecvaraccnodeinfogetbrowseinfo  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccnodeinfogetbrowseinfo", (RTS_UINTPTR)iecvaraccnodeinfogetbrowseinfo, 1, 0, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_iecvaraccnodeinfogetbrowseinfo
	#define EXT_iecvaraccnodeinfogetbrowseinfo
	#define GET_iecvaraccnodeinfogetbrowseinfo(fl)  CAL_CMGETAPI( "iecvaraccnodeinfogetbrowseinfo" ) 
	#define CAL_iecvaraccnodeinfogetbrowseinfo  iecvaraccnodeinfogetbrowseinfo
	#define CHK_iecvaraccnodeinfogetbrowseinfo  TRUE
	#define EXP_iecvaraccnodeinfogetbrowseinfo  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccnodeinfogetbrowseinfo", (RTS_UINTPTR)iecvaraccnodeinfogetbrowseinfo, 1, 0, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_iecvaraccnodeinfogetbrowseinfo  PFIECVARACCNODEINFOGETBROWSEINFO_IEC pfiecvaraccnodeinfogetbrowseinfo;
	#define EXT_iecvaraccnodeinfogetbrowseinfo  extern PFIECVARACCNODEINFOGETBROWSEINFO_IEC pfiecvaraccnodeinfogetbrowseinfo;
	#define GET_iecvaraccnodeinfogetbrowseinfo(fl)  s_pfCMGetAPI2( "iecvaraccnodeinfogetbrowseinfo", (RTS_VOID_FCTPTR *)&pfiecvaraccnodeinfogetbrowseinfo, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0, 0x03050F00)
	#define CAL_iecvaraccnodeinfogetbrowseinfo  pfiecvaraccnodeinfogetbrowseinfo
	#define CHK_iecvaraccnodeinfogetbrowseinfo  (pfiecvaraccnodeinfogetbrowseinfo != NULL)
	#define EXP_iecvaraccnodeinfogetbrowseinfo   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccnodeinfogetbrowseinfo", (RTS_UINTPTR)iecvaraccnodeinfogetbrowseinfo, 1, 0, 0x03050F00) 
#endif


/**
 * <description>iecvaraccnodeinfogetreference</description>
 */
typedef struct tagiecvaraccnodeinfogetreference_struct
{
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_BYTE *IecVarAccNodeInfoGetReference;	/* VAR_OUTPUT */	
} iecvaraccnodeinfogetreference_struct;

void CDECL CDECL_EXT iecvaraccnodeinfogetreference(iecvaraccnodeinfogetreference_struct *p);
typedef void (CDECL CDECL_EXT* PFIECVARACCNODEINFOGETREFERENCE_IEC) (iecvaraccnodeinfogetreference_struct *p);
#if defined(CMPIECVARACCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(IECVARACCNODEINFOGETREFERENCE_NOTIMPLEMENTED)
	#define USE_iecvaraccnodeinfogetreference
	#define EXT_iecvaraccnodeinfogetreference
	#define GET_iecvaraccnodeinfogetreference(fl)  ERR_NOTIMPLEMENTED
	#define CAL_iecvaraccnodeinfogetreference(p0) 
	#define CHK_iecvaraccnodeinfogetreference  FALSE
	#define EXP_iecvaraccnodeinfogetreference  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_iecvaraccnodeinfogetreference
	#define EXT_iecvaraccnodeinfogetreference
	#define GET_iecvaraccnodeinfogetreference(fl)  CAL_CMGETAPI( "iecvaraccnodeinfogetreference" ) 
	#define CAL_iecvaraccnodeinfogetreference  iecvaraccnodeinfogetreference
	#define CHK_iecvaraccnodeinfogetreference  TRUE
	#define EXP_iecvaraccnodeinfogetreference  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccnodeinfogetreference", (RTS_UINTPTR)iecvaraccnodeinfogetreference, 1, RTSITF_GET_SIGNATURE(0x4ABE0CEB, 0x84253FCA), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPIECVARACCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_iecvaraccnodeinfogetreference
	#define EXT_iecvaraccnodeinfogetreference
	#define GET_iecvaraccnodeinfogetreference(fl)  CAL_CMGETAPI( "iecvaraccnodeinfogetreference" ) 
	#define CAL_iecvaraccnodeinfogetreference  iecvaraccnodeinfogetreference
	#define CHK_iecvaraccnodeinfogetreference  TRUE
	#define EXP_iecvaraccnodeinfogetreference  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccnodeinfogetreference", (RTS_UINTPTR)iecvaraccnodeinfogetreference, 1, RTSITF_GET_SIGNATURE(0x4ABE0CEB, 0x84253FCA), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIecVarAccess_Implementationiecvaraccnodeinfogetreference
	#define EXT_CmpIecVarAccess_Implementationiecvaraccnodeinfogetreference
	#define GET_CmpIecVarAccess_Implementationiecvaraccnodeinfogetreference  ERR_OK
	#define CAL_CmpIecVarAccess_Implementationiecvaraccnodeinfogetreference  iecvaraccnodeinfogetreference
	#define CHK_CmpIecVarAccess_Implementationiecvaraccnodeinfogetreference  TRUE
	#define EXP_CmpIecVarAccess_Implementationiecvaraccnodeinfogetreference  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccnodeinfogetreference", (RTS_UINTPTR)iecvaraccnodeinfogetreference, 1, RTSITF_GET_SIGNATURE(0x4ABE0CEB, 0x84253FCA), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_iecvaraccnodeinfogetreference
	#define EXT_iecvaraccnodeinfogetreference
	#define GET_iecvaraccnodeinfogetreference(fl)  CAL_CMGETAPI( "iecvaraccnodeinfogetreference" ) 
	#define CAL_iecvaraccnodeinfogetreference  iecvaraccnodeinfogetreference
	#define CHK_iecvaraccnodeinfogetreference  TRUE
	#define EXP_iecvaraccnodeinfogetreference  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccnodeinfogetreference", (RTS_UINTPTR)iecvaraccnodeinfogetreference, 1, RTSITF_GET_SIGNATURE(0x4ABE0CEB, 0x84253FCA), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_iecvaraccnodeinfogetreference  PFIECVARACCNODEINFOGETREFERENCE_IEC pfiecvaraccnodeinfogetreference;
	#define EXT_iecvaraccnodeinfogetreference  extern PFIECVARACCNODEINFOGETREFERENCE_IEC pfiecvaraccnodeinfogetreference;
	#define GET_iecvaraccnodeinfogetreference(fl)  s_pfCMGetAPI2( "iecvaraccnodeinfogetreference", (RTS_VOID_FCTPTR *)&pfiecvaraccnodeinfogetreference, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0x4ABE0CEB, 0x84253FCA), 0x03050F00)
	#define CAL_iecvaraccnodeinfogetreference  pfiecvaraccnodeinfogetreference
	#define CHK_iecvaraccnodeinfogetreference  (pfiecvaraccnodeinfogetreference != NULL)
	#define EXP_iecvaraccnodeinfogetreference   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccnodeinfogetreference", (RTS_UINTPTR)iecvaraccnodeinfogetreference, 1, RTSITF_GET_SIGNATURE(0x4ABE0CEB, 0x84253FCA), 0x03050F00) 
#endif


/**
 * <description>iecvaraccnodeinforemovebrowseinfo</description>
 */
typedef struct tagiecvaraccnodeinforemovebrowseinfo_struct
{
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	
	RTS_IEC_RESULT IecVarAccNodeInfoRemoveBrowseInfo;	/* VAR_OUTPUT */	
} iecvaraccnodeinforemovebrowseinfo_struct;

void CDECL CDECL_EXT iecvaraccnodeinforemovebrowseinfo(iecvaraccnodeinforemovebrowseinfo_struct *p);
typedef void (CDECL CDECL_EXT* PFIECVARACCNODEINFOREMOVEBROWSEINFO_IEC) (iecvaraccnodeinforemovebrowseinfo_struct *p);
#if defined(CMPIECVARACCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(IECVARACCNODEINFOREMOVEBROWSEINFO_NOTIMPLEMENTED)
	#define USE_iecvaraccnodeinforemovebrowseinfo
	#define EXT_iecvaraccnodeinforemovebrowseinfo
	#define GET_iecvaraccnodeinforemovebrowseinfo(fl)  ERR_NOTIMPLEMENTED
	#define CAL_iecvaraccnodeinforemovebrowseinfo(p0) 
	#define CHK_iecvaraccnodeinforemovebrowseinfo  FALSE
	#define EXP_iecvaraccnodeinforemovebrowseinfo  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_iecvaraccnodeinforemovebrowseinfo
	#define EXT_iecvaraccnodeinforemovebrowseinfo
	#define GET_iecvaraccnodeinforemovebrowseinfo(fl)  CAL_CMGETAPI( "iecvaraccnodeinforemovebrowseinfo" ) 
	#define CAL_iecvaraccnodeinforemovebrowseinfo  iecvaraccnodeinforemovebrowseinfo
	#define CHK_iecvaraccnodeinforemovebrowseinfo  TRUE
	#define EXP_iecvaraccnodeinforemovebrowseinfo  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccnodeinforemovebrowseinfo", (RTS_UINTPTR)iecvaraccnodeinforemovebrowseinfo, 1, RTSITF_GET_SIGNATURE(0x43FC9F64, 0xC2D7CEF9), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPIECVARACCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_iecvaraccnodeinforemovebrowseinfo
	#define EXT_iecvaraccnodeinforemovebrowseinfo
	#define GET_iecvaraccnodeinforemovebrowseinfo(fl)  CAL_CMGETAPI( "iecvaraccnodeinforemovebrowseinfo" ) 
	#define CAL_iecvaraccnodeinforemovebrowseinfo  iecvaraccnodeinforemovebrowseinfo
	#define CHK_iecvaraccnodeinforemovebrowseinfo  TRUE
	#define EXP_iecvaraccnodeinforemovebrowseinfo  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccnodeinforemovebrowseinfo", (RTS_UINTPTR)iecvaraccnodeinforemovebrowseinfo, 1, RTSITF_GET_SIGNATURE(0x43FC9F64, 0xC2D7CEF9), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIecVarAccess_Implementationiecvaraccnodeinforemovebrowseinfo
	#define EXT_CmpIecVarAccess_Implementationiecvaraccnodeinforemovebrowseinfo
	#define GET_CmpIecVarAccess_Implementationiecvaraccnodeinforemovebrowseinfo  ERR_OK
	#define CAL_CmpIecVarAccess_Implementationiecvaraccnodeinforemovebrowseinfo  iecvaraccnodeinforemovebrowseinfo
	#define CHK_CmpIecVarAccess_Implementationiecvaraccnodeinforemovebrowseinfo  TRUE
	#define EXP_CmpIecVarAccess_Implementationiecvaraccnodeinforemovebrowseinfo  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccnodeinforemovebrowseinfo", (RTS_UINTPTR)iecvaraccnodeinforemovebrowseinfo, 1, RTSITF_GET_SIGNATURE(0x43FC9F64, 0xC2D7CEF9), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_iecvaraccnodeinforemovebrowseinfo
	#define EXT_iecvaraccnodeinforemovebrowseinfo
	#define GET_iecvaraccnodeinforemovebrowseinfo(fl)  CAL_CMGETAPI( "iecvaraccnodeinforemovebrowseinfo" ) 
	#define CAL_iecvaraccnodeinforemovebrowseinfo  iecvaraccnodeinforemovebrowseinfo
	#define CHK_iecvaraccnodeinforemovebrowseinfo  TRUE
	#define EXP_iecvaraccnodeinforemovebrowseinfo  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccnodeinforemovebrowseinfo", (RTS_UINTPTR)iecvaraccnodeinforemovebrowseinfo, 1, RTSITF_GET_SIGNATURE(0x43FC9F64, 0xC2D7CEF9), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_iecvaraccnodeinforemovebrowseinfo  PFIECVARACCNODEINFOREMOVEBROWSEINFO_IEC pfiecvaraccnodeinforemovebrowseinfo;
	#define EXT_iecvaraccnodeinforemovebrowseinfo  extern PFIECVARACCNODEINFOREMOVEBROWSEINFO_IEC pfiecvaraccnodeinforemovebrowseinfo;
	#define GET_iecvaraccnodeinforemovebrowseinfo(fl)  s_pfCMGetAPI2( "iecvaraccnodeinforemovebrowseinfo", (RTS_VOID_FCTPTR *)&pfiecvaraccnodeinforemovebrowseinfo, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0x43FC9F64, 0xC2D7CEF9), 0x03050F00)
	#define CAL_iecvaraccnodeinforemovebrowseinfo  pfiecvaraccnodeinforemovebrowseinfo
	#define CHK_iecvaraccnodeinforemovebrowseinfo  (pfiecvaraccnodeinforemovebrowseinfo != NULL)
	#define EXP_iecvaraccnodeinforemovebrowseinfo   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccnodeinforemovebrowseinfo", (RTS_UINTPTR)iecvaraccnodeinforemovebrowseinfo, 1, RTSITF_GET_SIGNATURE(0x43FC9F64, 0xC2D7CEF9), 0x03050F00) 
#endif


/**
 * <description>iecvaraccnodeinforemovereference</description>
 */
typedef struct tagiecvaraccnodeinforemovereference_struct
{
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	
	RTS_IEC_RESULT IecVarAccNodeInfoRemoveReference;	/* VAR_OUTPUT */	
} iecvaraccnodeinforemovereference_struct;

void CDECL CDECL_EXT iecvaraccnodeinforemovereference(iecvaraccnodeinforemovereference_struct *p);
typedef void (CDECL CDECL_EXT* PFIECVARACCNODEINFOREMOVEREFERENCE_IEC) (iecvaraccnodeinforemovereference_struct *p);
#if defined(CMPIECVARACCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(IECVARACCNODEINFOREMOVEREFERENCE_NOTIMPLEMENTED)
	#define USE_iecvaraccnodeinforemovereference
	#define EXT_iecvaraccnodeinforemovereference
	#define GET_iecvaraccnodeinforemovereference(fl)  ERR_NOTIMPLEMENTED
	#define CAL_iecvaraccnodeinforemovereference(p0) 
	#define CHK_iecvaraccnodeinforemovereference  FALSE
	#define EXP_iecvaraccnodeinforemovereference  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_iecvaraccnodeinforemovereference
	#define EXT_iecvaraccnodeinforemovereference
	#define GET_iecvaraccnodeinforemovereference(fl)  CAL_CMGETAPI( "iecvaraccnodeinforemovereference" ) 
	#define CAL_iecvaraccnodeinforemovereference  iecvaraccnodeinforemovereference
	#define CHK_iecvaraccnodeinforemovereference  TRUE
	#define EXP_iecvaraccnodeinforemovereference  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccnodeinforemovereference", (RTS_UINTPTR)iecvaraccnodeinforemovereference, 1, RTSITF_GET_SIGNATURE(0xAAD90063, 0x725A147D), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPIECVARACCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_iecvaraccnodeinforemovereference
	#define EXT_iecvaraccnodeinforemovereference
	#define GET_iecvaraccnodeinforemovereference(fl)  CAL_CMGETAPI( "iecvaraccnodeinforemovereference" ) 
	#define CAL_iecvaraccnodeinforemovereference  iecvaraccnodeinforemovereference
	#define CHK_iecvaraccnodeinforemovereference  TRUE
	#define EXP_iecvaraccnodeinforemovereference  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccnodeinforemovereference", (RTS_UINTPTR)iecvaraccnodeinforemovereference, 1, RTSITF_GET_SIGNATURE(0xAAD90063, 0x725A147D), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIecVarAccess_Implementationiecvaraccnodeinforemovereference
	#define EXT_CmpIecVarAccess_Implementationiecvaraccnodeinforemovereference
	#define GET_CmpIecVarAccess_Implementationiecvaraccnodeinforemovereference  ERR_OK
	#define CAL_CmpIecVarAccess_Implementationiecvaraccnodeinforemovereference  iecvaraccnodeinforemovereference
	#define CHK_CmpIecVarAccess_Implementationiecvaraccnodeinforemovereference  TRUE
	#define EXP_CmpIecVarAccess_Implementationiecvaraccnodeinforemovereference  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccnodeinforemovereference", (RTS_UINTPTR)iecvaraccnodeinforemovereference, 1, RTSITF_GET_SIGNATURE(0xAAD90063, 0x725A147D), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_iecvaraccnodeinforemovereference
	#define EXT_iecvaraccnodeinforemovereference
	#define GET_iecvaraccnodeinforemovereference(fl)  CAL_CMGETAPI( "iecvaraccnodeinforemovereference" ) 
	#define CAL_iecvaraccnodeinforemovereference  iecvaraccnodeinforemovereference
	#define CHK_iecvaraccnodeinforemovereference  TRUE
	#define EXP_iecvaraccnodeinforemovereference  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccnodeinforemovereference", (RTS_UINTPTR)iecvaraccnodeinforemovereference, 1, RTSITF_GET_SIGNATURE(0xAAD90063, 0x725A147D), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_iecvaraccnodeinforemovereference  PFIECVARACCNODEINFOREMOVEREFERENCE_IEC pfiecvaraccnodeinforemovereference;
	#define EXT_iecvaraccnodeinforemovereference  extern PFIECVARACCNODEINFOREMOVEREFERENCE_IEC pfiecvaraccnodeinforemovereference;
	#define GET_iecvaraccnodeinforemovereference(fl)  s_pfCMGetAPI2( "iecvaraccnodeinforemovereference", (RTS_VOID_FCTPTR *)&pfiecvaraccnodeinforemovereference, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0xAAD90063, 0x725A147D), 0x03050F00)
	#define CAL_iecvaraccnodeinforemovereference  pfiecvaraccnodeinforemovereference
	#define CHK_iecvaraccnodeinforemovereference  (pfiecvaraccnodeinforemovereference != NULL)
	#define EXP_iecvaraccnodeinforemovereference   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccnodeinforemovereference", (RTS_UINTPTR)iecvaraccnodeinforemovereference, 1, RTSITF_GET_SIGNATURE(0xAAD90063, 0x725A147D), 0x03050F00) 
#endif


/**
 * <description>iecvaraccregisterinstance</description>
 */
typedef struct tagiecvaraccregisterinstance_struct
{
	IIecVarAccess *pIIecVarAccess;		/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_HANDLE IecVarAccRegisterInstance;	/* VAR_OUTPUT */	
} iecvaraccregisterinstance_struct;

void CDECL CDECL_EXT iecvaraccregisterinstance(iecvaraccregisterinstance_struct *p);
typedef void (CDECL CDECL_EXT* PFIECVARACCREGISTERINSTANCE_IEC) (iecvaraccregisterinstance_struct *p);
#if defined(CMPIECVARACCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(IECVARACCREGISTERINSTANCE_NOTIMPLEMENTED)
	#define USE_iecvaraccregisterinstance
	#define EXT_iecvaraccregisterinstance
	#define GET_iecvaraccregisterinstance(fl)  ERR_NOTIMPLEMENTED
	#define CAL_iecvaraccregisterinstance(p0) 
	#define CHK_iecvaraccregisterinstance  FALSE
	#define EXP_iecvaraccregisterinstance  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_iecvaraccregisterinstance
	#define EXT_iecvaraccregisterinstance
	#define GET_iecvaraccregisterinstance(fl)  CAL_CMGETAPI( "iecvaraccregisterinstance" ) 
	#define CAL_iecvaraccregisterinstance  iecvaraccregisterinstance
	#define CHK_iecvaraccregisterinstance  TRUE
	#define EXP_iecvaraccregisterinstance  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccregisterinstance", (RTS_UINTPTR)iecvaraccregisterinstance, 1, RTSITF_GET_SIGNATURE(0, 0x2838418D), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPIECVARACCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_iecvaraccregisterinstance
	#define EXT_iecvaraccregisterinstance
	#define GET_iecvaraccregisterinstance(fl)  CAL_CMGETAPI( "iecvaraccregisterinstance" ) 
	#define CAL_iecvaraccregisterinstance  iecvaraccregisterinstance
	#define CHK_iecvaraccregisterinstance  TRUE
	#define EXP_iecvaraccregisterinstance  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccregisterinstance", (RTS_UINTPTR)iecvaraccregisterinstance, 1, RTSITF_GET_SIGNATURE(0, 0x2838418D), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIecVarAccess_Implementationiecvaraccregisterinstance
	#define EXT_CmpIecVarAccess_Implementationiecvaraccregisterinstance
	#define GET_CmpIecVarAccess_Implementationiecvaraccregisterinstance  ERR_OK
	#define CAL_CmpIecVarAccess_Implementationiecvaraccregisterinstance  iecvaraccregisterinstance
	#define CHK_CmpIecVarAccess_Implementationiecvaraccregisterinstance  TRUE
	#define EXP_CmpIecVarAccess_Implementationiecvaraccregisterinstance  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccregisterinstance", (RTS_UINTPTR)iecvaraccregisterinstance, 1, RTSITF_GET_SIGNATURE(0, 0x2838418D), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_iecvaraccregisterinstance
	#define EXT_iecvaraccregisterinstance
	#define GET_iecvaraccregisterinstance(fl)  CAL_CMGETAPI( "iecvaraccregisterinstance" ) 
	#define CAL_iecvaraccregisterinstance  iecvaraccregisterinstance
	#define CHK_iecvaraccregisterinstance  TRUE
	#define EXP_iecvaraccregisterinstance  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccregisterinstance", (RTS_UINTPTR)iecvaraccregisterinstance, 1, RTSITF_GET_SIGNATURE(0, 0x2838418D), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_iecvaraccregisterinstance  PFIECVARACCREGISTERINSTANCE_IEC pfiecvaraccregisterinstance;
	#define EXT_iecvaraccregisterinstance  extern PFIECVARACCREGISTERINSTANCE_IEC pfiecvaraccregisterinstance;
	#define GET_iecvaraccregisterinstance(fl)  s_pfCMGetAPI2( "iecvaraccregisterinstance", (RTS_VOID_FCTPTR *)&pfiecvaraccregisterinstance, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x2838418D), 0x03050F00)
	#define CAL_iecvaraccregisterinstance  pfiecvaraccregisterinstance
	#define CHK_iecvaraccregisterinstance  (pfiecvaraccregisterinstance != NULL)
	#define EXP_iecvaraccregisterinstance   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccregisterinstance", (RTS_UINTPTR)iecvaraccregisterinstance, 1, RTSITF_GET_SIGNATURE(0, 0x2838418D), 0x03050F00) 
#endif


/**
 * <description>iecvaraccregisterinstance2</description>
 */
typedef struct tagiecvaraccregisterinstance2_struct
{
	IIecVarAccess2 *pIIecVarAccess2;	/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_HANDLE IecVarAccRegisterInstance2;	/* VAR_OUTPUT */	
} iecvaraccregisterinstance2_struct;

void CDECL CDECL_EXT iecvaraccregisterinstance2(iecvaraccregisterinstance2_struct *p);
typedef void (CDECL CDECL_EXT* PFIECVARACCREGISTERINSTANCE2_IEC) (iecvaraccregisterinstance2_struct *p);
#if defined(CMPIECVARACCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(IECVARACCREGISTERINSTANCE2_NOTIMPLEMENTED)
	#define USE_iecvaraccregisterinstance2
	#define EXT_iecvaraccregisterinstance2
	#define GET_iecvaraccregisterinstance2(fl)  ERR_NOTIMPLEMENTED
	#define CAL_iecvaraccregisterinstance2(p0) 
	#define CHK_iecvaraccregisterinstance2  FALSE
	#define EXP_iecvaraccregisterinstance2  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_iecvaraccregisterinstance2
	#define EXT_iecvaraccregisterinstance2
	#define GET_iecvaraccregisterinstance2(fl)  CAL_CMGETAPI( "iecvaraccregisterinstance2" ) 
	#define CAL_iecvaraccregisterinstance2  iecvaraccregisterinstance2
	#define CHK_iecvaraccregisterinstance2  TRUE
	#define EXP_iecvaraccregisterinstance2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccregisterinstance2", (RTS_UINTPTR)iecvaraccregisterinstance2, 1, RTSITF_GET_SIGNATURE(0, 0x12CBCF4F), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPIECVARACCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_iecvaraccregisterinstance2
	#define EXT_iecvaraccregisterinstance2
	#define GET_iecvaraccregisterinstance2(fl)  CAL_CMGETAPI( "iecvaraccregisterinstance2" ) 
	#define CAL_iecvaraccregisterinstance2  iecvaraccregisterinstance2
	#define CHK_iecvaraccregisterinstance2  TRUE
	#define EXP_iecvaraccregisterinstance2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccregisterinstance2", (RTS_UINTPTR)iecvaraccregisterinstance2, 1, RTSITF_GET_SIGNATURE(0, 0x12CBCF4F), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIecVarAccess_Implementationiecvaraccregisterinstance2
	#define EXT_CmpIecVarAccess_Implementationiecvaraccregisterinstance2
	#define GET_CmpIecVarAccess_Implementationiecvaraccregisterinstance2  ERR_OK
	#define CAL_CmpIecVarAccess_Implementationiecvaraccregisterinstance2  iecvaraccregisterinstance2
	#define CHK_CmpIecVarAccess_Implementationiecvaraccregisterinstance2  TRUE
	#define EXP_CmpIecVarAccess_Implementationiecvaraccregisterinstance2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccregisterinstance2", (RTS_UINTPTR)iecvaraccregisterinstance2, 1, RTSITF_GET_SIGNATURE(0, 0x12CBCF4F), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_iecvaraccregisterinstance2
	#define EXT_iecvaraccregisterinstance2
	#define GET_iecvaraccregisterinstance2(fl)  CAL_CMGETAPI( "iecvaraccregisterinstance2" ) 
	#define CAL_iecvaraccregisterinstance2  iecvaraccregisterinstance2
	#define CHK_iecvaraccregisterinstance2  TRUE
	#define EXP_iecvaraccregisterinstance2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccregisterinstance2", (RTS_UINTPTR)iecvaraccregisterinstance2, 1, RTSITF_GET_SIGNATURE(0, 0x12CBCF4F), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_iecvaraccregisterinstance2  PFIECVARACCREGISTERINSTANCE2_IEC pfiecvaraccregisterinstance2;
	#define EXT_iecvaraccregisterinstance2  extern PFIECVARACCREGISTERINSTANCE2_IEC pfiecvaraccregisterinstance2;
	#define GET_iecvaraccregisterinstance2(fl)  s_pfCMGetAPI2( "iecvaraccregisterinstance2", (RTS_VOID_FCTPTR *)&pfiecvaraccregisterinstance2, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x12CBCF4F), 0x03050F00)
	#define CAL_iecvaraccregisterinstance2  pfiecvaraccregisterinstance2
	#define CHK_iecvaraccregisterinstance2  (pfiecvaraccregisterinstance2 != NULL)
	#define EXP_iecvaraccregisterinstance2   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccregisterinstance2", (RTS_UINTPTR)iecvaraccregisterinstance2, 1, RTSITF_GET_SIGNATURE(0, 0x12CBCF4F), 0x03050F00) 
#endif


/**
 * <description>iecvaraccregisterinstance3</description>
 */
typedef struct tagiecvaraccregisterinstance3_struct
{
	IIecVarAccess3 *pIIecVarAccess3;	/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_HANDLE IecVarAccRegisterInstance3;	/* VAR_OUTPUT */	
} iecvaraccregisterinstance3_struct;

void CDECL CDECL_EXT iecvaraccregisterinstance3(iecvaraccregisterinstance3_struct *p);
typedef void (CDECL CDECL_EXT* PFIECVARACCREGISTERINSTANCE3_IEC) (iecvaraccregisterinstance3_struct *p);
#if defined(CMPIECVARACCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(IECVARACCREGISTERINSTANCE3_NOTIMPLEMENTED)
	#define USE_iecvaraccregisterinstance3
	#define EXT_iecvaraccregisterinstance3
	#define GET_iecvaraccregisterinstance3(fl)  ERR_NOTIMPLEMENTED
	#define CAL_iecvaraccregisterinstance3(p0) 
	#define CHK_iecvaraccregisterinstance3  FALSE
	#define EXP_iecvaraccregisterinstance3  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_iecvaraccregisterinstance3
	#define EXT_iecvaraccregisterinstance3
	#define GET_iecvaraccregisterinstance3(fl)  CAL_CMGETAPI( "iecvaraccregisterinstance3" ) 
	#define CAL_iecvaraccregisterinstance3  iecvaraccregisterinstance3
	#define CHK_iecvaraccregisterinstance3  TRUE
	#define EXP_iecvaraccregisterinstance3  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccregisterinstance3", (RTS_UINTPTR)iecvaraccregisterinstance3, 1, RTSITF_GET_SIGNATURE(0, 0xC1E3F2D6), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPIECVARACCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_iecvaraccregisterinstance3
	#define EXT_iecvaraccregisterinstance3
	#define GET_iecvaraccregisterinstance3(fl)  CAL_CMGETAPI( "iecvaraccregisterinstance3" ) 
	#define CAL_iecvaraccregisterinstance3  iecvaraccregisterinstance3
	#define CHK_iecvaraccregisterinstance3  TRUE
	#define EXP_iecvaraccregisterinstance3  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccregisterinstance3", (RTS_UINTPTR)iecvaraccregisterinstance3, 1, RTSITF_GET_SIGNATURE(0, 0xC1E3F2D6), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIecVarAccess_Implementationiecvaraccregisterinstance3
	#define EXT_CmpIecVarAccess_Implementationiecvaraccregisterinstance3
	#define GET_CmpIecVarAccess_Implementationiecvaraccregisterinstance3  ERR_OK
	#define CAL_CmpIecVarAccess_Implementationiecvaraccregisterinstance3  iecvaraccregisterinstance3
	#define CHK_CmpIecVarAccess_Implementationiecvaraccregisterinstance3  TRUE
	#define EXP_CmpIecVarAccess_Implementationiecvaraccregisterinstance3  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccregisterinstance3", (RTS_UINTPTR)iecvaraccregisterinstance3, 1, RTSITF_GET_SIGNATURE(0, 0xC1E3F2D6), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_iecvaraccregisterinstance3
	#define EXT_iecvaraccregisterinstance3
	#define GET_iecvaraccregisterinstance3(fl)  CAL_CMGETAPI( "iecvaraccregisterinstance3" ) 
	#define CAL_iecvaraccregisterinstance3  iecvaraccregisterinstance3
	#define CHK_iecvaraccregisterinstance3  TRUE
	#define EXP_iecvaraccregisterinstance3  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccregisterinstance3", (RTS_UINTPTR)iecvaraccregisterinstance3, 1, RTSITF_GET_SIGNATURE(0, 0xC1E3F2D6), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_iecvaraccregisterinstance3  PFIECVARACCREGISTERINSTANCE3_IEC pfiecvaraccregisterinstance3;
	#define EXT_iecvaraccregisterinstance3  extern PFIECVARACCREGISTERINSTANCE3_IEC pfiecvaraccregisterinstance3;
	#define GET_iecvaraccregisterinstance3(fl)  s_pfCMGetAPI2( "iecvaraccregisterinstance3", (RTS_VOID_FCTPTR *)&pfiecvaraccregisterinstance3, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xC1E3F2D6), 0x03050F00)
	#define CAL_iecvaraccregisterinstance3  pfiecvaraccregisterinstance3
	#define CHK_iecvaraccregisterinstance3  (pfiecvaraccregisterinstance3 != NULL)
	#define EXP_iecvaraccregisterinstance3   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccregisterinstance3", (RTS_UINTPTR)iecvaraccregisterinstance3, 1, RTSITF_GET_SIGNATURE(0, 0xC1E3F2D6), 0x03050F00) 
#endif


/**
 * <description>iecvaraccregisterinstancebase</description>
 */
typedef struct tagiecvaraccregisterinstancebase_struct
{
	IBase *pIBase;						/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_HANDLE IecVarAccRegisterInstanceBase;	/* VAR_OUTPUT */	
} iecvaraccregisterinstancebase_struct;

void CDECL CDECL_EXT iecvaraccregisterinstancebase(iecvaraccregisterinstancebase_struct *p);
typedef void (CDECL CDECL_EXT* PFIECVARACCREGISTERINSTANCEBASE_IEC) (iecvaraccregisterinstancebase_struct *p);
#if defined(CMPIECVARACCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(IECVARACCREGISTERINSTANCEBASE_NOTIMPLEMENTED)
	#define USE_iecvaraccregisterinstancebase
	#define EXT_iecvaraccregisterinstancebase
	#define GET_iecvaraccregisterinstancebase(fl)  ERR_NOTIMPLEMENTED
	#define CAL_iecvaraccregisterinstancebase(p0) 
	#define CHK_iecvaraccregisterinstancebase  FALSE
	#define EXP_iecvaraccregisterinstancebase  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_iecvaraccregisterinstancebase
	#define EXT_iecvaraccregisterinstancebase
	#define GET_iecvaraccregisterinstancebase(fl)  CAL_CMGETAPI( "iecvaraccregisterinstancebase" ) 
	#define CAL_iecvaraccregisterinstancebase  iecvaraccregisterinstancebase
	#define CHK_iecvaraccregisterinstancebase  TRUE
	#define EXP_iecvaraccregisterinstancebase  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccregisterinstancebase", (RTS_UINTPTR)iecvaraccregisterinstancebase, 1, RTSITF_GET_SIGNATURE(0, 0xCD8685B0), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPIECVARACCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_iecvaraccregisterinstancebase
	#define EXT_iecvaraccregisterinstancebase
	#define GET_iecvaraccregisterinstancebase(fl)  CAL_CMGETAPI( "iecvaraccregisterinstancebase" ) 
	#define CAL_iecvaraccregisterinstancebase  iecvaraccregisterinstancebase
	#define CHK_iecvaraccregisterinstancebase  TRUE
	#define EXP_iecvaraccregisterinstancebase  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccregisterinstancebase", (RTS_UINTPTR)iecvaraccregisterinstancebase, 1, RTSITF_GET_SIGNATURE(0, 0xCD8685B0), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIecVarAccess_Implementationiecvaraccregisterinstancebase
	#define EXT_CmpIecVarAccess_Implementationiecvaraccregisterinstancebase
	#define GET_CmpIecVarAccess_Implementationiecvaraccregisterinstancebase  ERR_OK
	#define CAL_CmpIecVarAccess_Implementationiecvaraccregisterinstancebase  iecvaraccregisterinstancebase
	#define CHK_CmpIecVarAccess_Implementationiecvaraccregisterinstancebase  TRUE
	#define EXP_CmpIecVarAccess_Implementationiecvaraccregisterinstancebase  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccregisterinstancebase", (RTS_UINTPTR)iecvaraccregisterinstancebase, 1, RTSITF_GET_SIGNATURE(0, 0xCD8685B0), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_iecvaraccregisterinstancebase
	#define EXT_iecvaraccregisterinstancebase
	#define GET_iecvaraccregisterinstancebase(fl)  CAL_CMGETAPI( "iecvaraccregisterinstancebase" ) 
	#define CAL_iecvaraccregisterinstancebase  iecvaraccregisterinstancebase
	#define CHK_iecvaraccregisterinstancebase  TRUE
	#define EXP_iecvaraccregisterinstancebase  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccregisterinstancebase", (RTS_UINTPTR)iecvaraccregisterinstancebase, 1, RTSITF_GET_SIGNATURE(0, 0xCD8685B0), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_iecvaraccregisterinstancebase  PFIECVARACCREGISTERINSTANCEBASE_IEC pfiecvaraccregisterinstancebase;
	#define EXT_iecvaraccregisterinstancebase  extern PFIECVARACCREGISTERINSTANCEBASE_IEC pfiecvaraccregisterinstancebase;
	#define GET_iecvaraccregisterinstancebase(fl)  s_pfCMGetAPI2( "iecvaraccregisterinstancebase", (RTS_VOID_FCTPTR *)&pfiecvaraccregisterinstancebase, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xCD8685B0), 0x03050F00)
	#define CAL_iecvaraccregisterinstancebase  pfiecvaraccregisterinstancebase
	#define CHK_iecvaraccregisterinstancebase  (pfiecvaraccregisterinstancebase != NULL)
	#define EXP_iecvaraccregisterinstancebase   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccregisterinstancebase", (RTS_UINTPTR)iecvaraccregisterinstancebase, 1, RTSITF_GET_SIGNATURE(0, 0xCD8685B0), 0x03050F00) 
#endif


/**
 * <description>iecvaraccsetsymbolconfigcrc</description>
 */
typedef struct tagiecvaraccsetsymbolconfigcrc_struct
{
	RTS_IEC_HANDLE hInstance;			/* VAR_INPUT */	
	RTS_IEC_UDINT udiCrc;				/* VAR_INPUT */	
	RTS_IEC_RESULT IecVarAccSetSymbolconfigCrc;	/* VAR_OUTPUT */	
} iecvaraccsetsymbolconfigcrc_struct;

void CDECL CDECL_EXT iecvaraccsetsymbolconfigcrc(iecvaraccsetsymbolconfigcrc_struct *p);
typedef void (CDECL CDECL_EXT* PFIECVARACCSETSYMBOLCONFIGCRC_IEC) (iecvaraccsetsymbolconfigcrc_struct *p);
#if defined(CMPIECVARACCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(IECVARACCSETSYMBOLCONFIGCRC_NOTIMPLEMENTED)
	#define USE_iecvaraccsetsymbolconfigcrc
	#define EXT_iecvaraccsetsymbolconfigcrc
	#define GET_iecvaraccsetsymbolconfigcrc(fl)  ERR_NOTIMPLEMENTED
	#define CAL_iecvaraccsetsymbolconfigcrc(p0) 
	#define CHK_iecvaraccsetsymbolconfigcrc  FALSE
	#define EXP_iecvaraccsetsymbolconfigcrc  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_iecvaraccsetsymbolconfigcrc
	#define EXT_iecvaraccsetsymbolconfigcrc
	#define GET_iecvaraccsetsymbolconfigcrc(fl)  CAL_CMGETAPI( "iecvaraccsetsymbolconfigcrc" ) 
	#define CAL_iecvaraccsetsymbolconfigcrc  iecvaraccsetsymbolconfigcrc
	#define CHK_iecvaraccsetsymbolconfigcrc  TRUE
	#define EXP_iecvaraccsetsymbolconfigcrc  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccsetsymbolconfigcrc", (RTS_UINTPTR)iecvaraccsetsymbolconfigcrc, 1, 0xFDCEC8DA, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPIECVARACCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_iecvaraccsetsymbolconfigcrc
	#define EXT_iecvaraccsetsymbolconfigcrc
	#define GET_iecvaraccsetsymbolconfigcrc(fl)  CAL_CMGETAPI( "iecvaraccsetsymbolconfigcrc" ) 
	#define CAL_iecvaraccsetsymbolconfigcrc  iecvaraccsetsymbolconfigcrc
	#define CHK_iecvaraccsetsymbolconfigcrc  TRUE
	#define EXP_iecvaraccsetsymbolconfigcrc  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccsetsymbolconfigcrc", (RTS_UINTPTR)iecvaraccsetsymbolconfigcrc, 1, 0xFDCEC8DA, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIecVarAccess_Implementationiecvaraccsetsymbolconfigcrc
	#define EXT_CmpIecVarAccess_Implementationiecvaraccsetsymbolconfigcrc
	#define GET_CmpIecVarAccess_Implementationiecvaraccsetsymbolconfigcrc  ERR_OK
	#define CAL_CmpIecVarAccess_Implementationiecvaraccsetsymbolconfigcrc  iecvaraccsetsymbolconfigcrc
	#define CHK_CmpIecVarAccess_Implementationiecvaraccsetsymbolconfigcrc  TRUE
	#define EXP_CmpIecVarAccess_Implementationiecvaraccsetsymbolconfigcrc  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccsetsymbolconfigcrc", (RTS_UINTPTR)iecvaraccsetsymbolconfigcrc, 1, 0xFDCEC8DA, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_iecvaraccsetsymbolconfigcrc
	#define EXT_iecvaraccsetsymbolconfigcrc
	#define GET_iecvaraccsetsymbolconfigcrc(fl)  CAL_CMGETAPI( "iecvaraccsetsymbolconfigcrc" ) 
	#define CAL_iecvaraccsetsymbolconfigcrc  iecvaraccsetsymbolconfigcrc
	#define CHK_iecvaraccsetsymbolconfigcrc  TRUE
	#define EXP_iecvaraccsetsymbolconfigcrc  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccsetsymbolconfigcrc", (RTS_UINTPTR)iecvaraccsetsymbolconfigcrc, 1, 0xFDCEC8DA, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_iecvaraccsetsymbolconfigcrc  PFIECVARACCSETSYMBOLCONFIGCRC_IEC pfiecvaraccsetsymbolconfigcrc;
	#define EXT_iecvaraccsetsymbolconfigcrc  extern PFIECVARACCSETSYMBOLCONFIGCRC_IEC pfiecvaraccsetsymbolconfigcrc;
	#define GET_iecvaraccsetsymbolconfigcrc(fl)  s_pfCMGetAPI2( "iecvaraccsetsymbolconfigcrc", (RTS_VOID_FCTPTR *)&pfiecvaraccsetsymbolconfigcrc, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xFDCEC8DA, 0x03050F00)
	#define CAL_iecvaraccsetsymbolconfigcrc  pfiecvaraccsetsymbolconfigcrc
	#define CHK_iecvaraccsetsymbolconfigcrc  (pfiecvaraccsetsymbolconfigcrc != NULL)
	#define EXP_iecvaraccsetsymbolconfigcrc   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccsetsymbolconfigcrc", (RTS_UINTPTR)iecvaraccsetsymbolconfigcrc, 1, 0xFDCEC8DA, 0x03050F00) 
#endif


/**
 * <description>iecvaraccunregisterinstance</description>
 */
typedef struct tagiecvaraccunregisterinstance_struct
{
	RTS_IEC_HANDLE hInstance;			/* VAR_INPUT */	
	RTS_IEC_RESULT IecVarAccUnregisterInstance;	/* VAR_OUTPUT */	
} iecvaraccunregisterinstance_struct;

void CDECL CDECL_EXT iecvaraccunregisterinstance(iecvaraccunregisterinstance_struct *p);
typedef void (CDECL CDECL_EXT* PFIECVARACCUNREGISTERINSTANCE_IEC) (iecvaraccunregisterinstance_struct *p);
#if defined(CMPIECVARACCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(IECVARACCUNREGISTERINSTANCE_NOTIMPLEMENTED)
	#define USE_iecvaraccunregisterinstance
	#define EXT_iecvaraccunregisterinstance
	#define GET_iecvaraccunregisterinstance(fl)  ERR_NOTIMPLEMENTED
	#define CAL_iecvaraccunregisterinstance(p0) 
	#define CHK_iecvaraccunregisterinstance  FALSE
	#define EXP_iecvaraccunregisterinstance  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_iecvaraccunregisterinstance
	#define EXT_iecvaraccunregisterinstance
	#define GET_iecvaraccunregisterinstance(fl)  CAL_CMGETAPI( "iecvaraccunregisterinstance" ) 
	#define CAL_iecvaraccunregisterinstance  iecvaraccunregisterinstance
	#define CHK_iecvaraccunregisterinstance  TRUE
	#define EXP_iecvaraccunregisterinstance  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccunregisterinstance", (RTS_UINTPTR)iecvaraccunregisterinstance, 1, RTSITF_GET_SIGNATURE(0, 0xEDB8227D), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPIECVARACCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_iecvaraccunregisterinstance
	#define EXT_iecvaraccunregisterinstance
	#define GET_iecvaraccunregisterinstance(fl)  CAL_CMGETAPI( "iecvaraccunregisterinstance" ) 
	#define CAL_iecvaraccunregisterinstance  iecvaraccunregisterinstance
	#define CHK_iecvaraccunregisterinstance  TRUE
	#define EXP_iecvaraccunregisterinstance  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccunregisterinstance", (RTS_UINTPTR)iecvaraccunregisterinstance, 1, RTSITF_GET_SIGNATURE(0, 0xEDB8227D), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIecVarAccess_Implementationiecvaraccunregisterinstance
	#define EXT_CmpIecVarAccess_Implementationiecvaraccunregisterinstance
	#define GET_CmpIecVarAccess_Implementationiecvaraccunregisterinstance  ERR_OK
	#define CAL_CmpIecVarAccess_Implementationiecvaraccunregisterinstance  iecvaraccunregisterinstance
	#define CHK_CmpIecVarAccess_Implementationiecvaraccunregisterinstance  TRUE
	#define EXP_CmpIecVarAccess_Implementationiecvaraccunregisterinstance  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccunregisterinstance", (RTS_UINTPTR)iecvaraccunregisterinstance, 1, RTSITF_GET_SIGNATURE(0, 0xEDB8227D), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_iecvaraccunregisterinstance
	#define EXT_iecvaraccunregisterinstance
	#define GET_iecvaraccunregisterinstance(fl)  CAL_CMGETAPI( "iecvaraccunregisterinstance" ) 
	#define CAL_iecvaraccunregisterinstance  iecvaraccunregisterinstance
	#define CHK_iecvaraccunregisterinstance  TRUE
	#define EXP_iecvaraccunregisterinstance  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccunregisterinstance", (RTS_UINTPTR)iecvaraccunregisterinstance, 1, RTSITF_GET_SIGNATURE(0, 0xEDB8227D), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_iecvaraccunregisterinstance  PFIECVARACCUNREGISTERINSTANCE_IEC pfiecvaraccunregisterinstance;
	#define EXT_iecvaraccunregisterinstance  extern PFIECVARACCUNREGISTERINSTANCE_IEC pfiecvaraccunregisterinstance;
	#define GET_iecvaraccunregisterinstance(fl)  s_pfCMGetAPI2( "iecvaraccunregisterinstance", (RTS_VOID_FCTPTR *)&pfiecvaraccunregisterinstance, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xEDB8227D), 0x03050F00)
	#define CAL_iecvaraccunregisterinstance  pfiecvaraccunregisterinstance
	#define CHK_iecvaraccunregisterinstance  (pfiecvaraccunregisterinstance != NULL)
	#define EXP_iecvaraccunregisterinstance   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccunregisterinstance", (RTS_UINTPTR)iecvaraccunregisterinstance, 1, RTSITF_GET_SIGNATURE(0, 0xEDB8227D), 0x03050F00) 
#endif


/**
 * <description>iecvaraccupdatesymbolsets</description>
 */
typedef struct tagiecvaraccupdatesymbolsets_struct
{
	RTS_IEC_HANDLE hInterface;			/* VAR_INPUT */	
	IecVarAccSymbolSetDescription *pSymbolsSets;	/* VAR_INPUT */	
	RTS_IEC_UDINT numOfSymbolsSets;		/* VAR_INPUT */	
	RTS_IEC_RESULT IecVarAccUpdateSymbolSets;	/* VAR_OUTPUT */	
} iecvaraccupdatesymbolsets_struct;

void CDECL CDECL_EXT iecvaraccupdatesymbolsets(iecvaraccupdatesymbolsets_struct *p);
typedef void (CDECL CDECL_EXT* PFIECVARACCUPDATESYMBOLSETS_IEC) (iecvaraccupdatesymbolsets_struct *p);
#if defined(CMPIECVARACCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(IECVARACCUPDATESYMBOLSETS_NOTIMPLEMENTED)
	#define USE_iecvaraccupdatesymbolsets
	#define EXT_iecvaraccupdatesymbolsets
	#define GET_iecvaraccupdatesymbolsets(fl)  ERR_NOTIMPLEMENTED
	#define CAL_iecvaraccupdatesymbolsets(p0) 
	#define CHK_iecvaraccupdatesymbolsets  FALSE
	#define EXP_iecvaraccupdatesymbolsets  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_iecvaraccupdatesymbolsets
	#define EXT_iecvaraccupdatesymbolsets
	#define GET_iecvaraccupdatesymbolsets(fl)  CAL_CMGETAPI( "iecvaraccupdatesymbolsets" ) 
	#define CAL_iecvaraccupdatesymbolsets  iecvaraccupdatesymbolsets
	#define CHK_iecvaraccupdatesymbolsets  TRUE
	#define EXP_iecvaraccupdatesymbolsets  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccupdatesymbolsets", (RTS_UINTPTR)iecvaraccupdatesymbolsets, 1, 0xF81481F0, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPIECVARACCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_iecvaraccupdatesymbolsets
	#define EXT_iecvaraccupdatesymbolsets
	#define GET_iecvaraccupdatesymbolsets(fl)  CAL_CMGETAPI( "iecvaraccupdatesymbolsets" ) 
	#define CAL_iecvaraccupdatesymbolsets  iecvaraccupdatesymbolsets
	#define CHK_iecvaraccupdatesymbolsets  TRUE
	#define EXP_iecvaraccupdatesymbolsets  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccupdatesymbolsets", (RTS_UINTPTR)iecvaraccupdatesymbolsets, 1, 0xF81481F0, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIecVarAccess_Implementationiecvaraccupdatesymbolsets
	#define EXT_CmpIecVarAccess_Implementationiecvaraccupdatesymbolsets
	#define GET_CmpIecVarAccess_Implementationiecvaraccupdatesymbolsets  ERR_OK
	#define CAL_CmpIecVarAccess_Implementationiecvaraccupdatesymbolsets  iecvaraccupdatesymbolsets
	#define CHK_CmpIecVarAccess_Implementationiecvaraccupdatesymbolsets  TRUE
	#define EXP_CmpIecVarAccess_Implementationiecvaraccupdatesymbolsets  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccupdatesymbolsets", (RTS_UINTPTR)iecvaraccupdatesymbolsets, 1, 0xF81481F0, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_iecvaraccupdatesymbolsets
	#define EXT_iecvaraccupdatesymbolsets
	#define GET_iecvaraccupdatesymbolsets(fl)  CAL_CMGETAPI( "iecvaraccupdatesymbolsets" ) 
	#define CAL_iecvaraccupdatesymbolsets  iecvaraccupdatesymbolsets
	#define CHK_iecvaraccupdatesymbolsets  TRUE
	#define EXP_iecvaraccupdatesymbolsets  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccupdatesymbolsets", (RTS_UINTPTR)iecvaraccupdatesymbolsets, 1, 0xF81481F0, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_iecvaraccupdatesymbolsets  PFIECVARACCUPDATESYMBOLSETS_IEC pfiecvaraccupdatesymbolsets;
	#define EXT_iecvaraccupdatesymbolsets  extern PFIECVARACCUPDATESYMBOLSETS_IEC pfiecvaraccupdatesymbolsets;
	#define GET_iecvaraccupdatesymbolsets(fl)  s_pfCMGetAPI2( "iecvaraccupdatesymbolsets", (RTS_VOID_FCTPTR *)&pfiecvaraccupdatesymbolsets, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xF81481F0, 0x03050F00)
	#define CAL_iecvaraccupdatesymbolsets  pfiecvaraccupdatesymbolsets
	#define CHK_iecvaraccupdatesymbolsets  (pfiecvaraccupdatesymbolsets != NULL)
	#define EXP_iecvaraccupdatesymbolsets   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"iecvaraccupdatesymbolsets", (RTS_UINTPTR)iecvaraccupdatesymbolsets, 1, 0xF81481F0, 0x03050F00) 
#endif


#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/




typedef struct
{
	IBase_C *pBase;
} ICmpIecVarAccess_Implementation_C;

#ifdef CPLUSPLUS
class ICmpIecVarAccess_Implementation : public IBase
{
	public:
};
	#ifndef ITF_CmpIecVarAccess_Implementation
		#define ITF_CmpIecVarAccess_Implementation static ICmpIecVarAccess_Implementation *pICmpIecVarAccess_Implementation = NULL;
	#endif
	#define EXTITF_CmpIecVarAccess_Implementation
#else	/*CPLUSPLUS*/
	typedef ICmpIecVarAccess_Implementation_C		ICmpIecVarAccess_Implementation;
	#ifndef ITF_CmpIecVarAccess_Implementation
		#define ITF_CmpIecVarAccess_Implementation
	#endif
	#define EXTITF_CmpIecVarAccess_Implementation
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_CMPIECVARACCESS_IMPLEMENTATIONITF_H_*/
