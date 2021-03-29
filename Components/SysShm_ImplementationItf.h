 /**
 * <interfacename>SysShm_Implementation</interfacename>
 * <description></description>
 *
 * <copyright></copyright>
 */


	
	
#ifndef _SYSSHM_IMPLEMENTATIONITF_H_
#define _SYSSHM_IMPLEMENTATIONITF_H_

#include "CmpStd.h"

 

 




/** EXTERN LIB SECTION BEGIN **/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Close a shared memory object specified by handle.
 * RETURN: Returns the runtime system error code (see CmpErrors_Itfs.library):
 */
typedef struct tagsyssharedmemoryclose_struct
{
	RTS_IEC_HANDLE hShm;				/* VAR_INPUT */	/* Handle to the shared memory */
	RTS_IEC_RESULT SysSharedMemoryClose;	/* VAR_OUTPUT */	
} syssharedmemoryclose_struct;

void CDECL CDECL_EXT syssharedmemoryclose(syssharedmemoryclose_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSHAREDMEMORYCLOSE_IEC) (syssharedmemoryclose_struct *p);
#if defined(SYSSHM_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSHAREDMEMORYCLOSE_NOTIMPLEMENTED)
	#define USE_syssharedmemoryclose
	#define EXT_syssharedmemoryclose
	#define GET_syssharedmemoryclose(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssharedmemoryclose(p0) 
	#define CHK_syssharedmemoryclose  FALSE
	#define EXP_syssharedmemoryclose  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssharedmemoryclose
	#define EXT_syssharedmemoryclose
	#define GET_syssharedmemoryclose(fl)  CAL_CMGETAPI( "syssharedmemoryclose" ) 
	#define CAL_syssharedmemoryclose  syssharedmemoryclose
	#define CHK_syssharedmemoryclose  TRUE
	#define EXP_syssharedmemoryclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemoryclose", (RTS_UINTPTR)syssharedmemoryclose, 1, RTSITF_GET_SIGNATURE(0, 0x93F75F86), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(SYSSHM_IMPLEMENTATION_EXTERNAL)
	#define USE_syssharedmemoryclose
	#define EXT_syssharedmemoryclose
	#define GET_syssharedmemoryclose(fl)  CAL_CMGETAPI( "syssharedmemoryclose" ) 
	#define CAL_syssharedmemoryclose  syssharedmemoryclose
	#define CHK_syssharedmemoryclose  TRUE
	#define EXP_syssharedmemoryclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemoryclose", (RTS_UINTPTR)syssharedmemoryclose, 1, RTSITF_GET_SIGNATURE(0, 0x93F75F86), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysShm_Implementationsyssharedmemoryclose
	#define EXT_SysShm_Implementationsyssharedmemoryclose
	#define GET_SysShm_Implementationsyssharedmemoryclose  ERR_OK
	#define CAL_SysShm_Implementationsyssharedmemoryclose  syssharedmemoryclose
	#define CHK_SysShm_Implementationsyssharedmemoryclose  TRUE
	#define EXP_SysShm_Implementationsyssharedmemoryclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemoryclose", (RTS_UINTPTR)syssharedmemoryclose, 1, RTSITF_GET_SIGNATURE(0, 0x93F75F86), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_syssharedmemoryclose
	#define EXT_syssharedmemoryclose
	#define GET_syssharedmemoryclose(fl)  CAL_CMGETAPI( "syssharedmemoryclose" ) 
	#define CAL_syssharedmemoryclose  syssharedmemoryclose
	#define CHK_syssharedmemoryclose  TRUE
	#define EXP_syssharedmemoryclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemoryclose", (RTS_UINTPTR)syssharedmemoryclose, 1, RTSITF_GET_SIGNATURE(0, 0x93F75F86), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_syssharedmemoryclose  PFSYSSHAREDMEMORYCLOSE_IEC pfsyssharedmemoryclose;
	#define EXT_syssharedmemoryclose  extern PFSYSSHAREDMEMORYCLOSE_IEC pfsyssharedmemoryclose;
	#define GET_syssharedmemoryclose(fl)  s_pfCMGetAPI2( "syssharedmemoryclose", (RTS_VOID_FCTPTR *)&pfsyssharedmemoryclose, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x93F75F86), 0x03051000)
	#define CAL_syssharedmemoryclose  pfsyssharedmemoryclose
	#define CHK_syssharedmemoryclose  (pfsyssharedmemoryclose != NULL)
	#define EXP_syssharedmemoryclose   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemoryclose", (RTS_UINTPTR)syssharedmemoryclose, 1, RTSITF_GET_SIGNATURE(0, 0x93F75F86), 0x03051000) 
#endif


/**
 * Create a new shared memory object specified by name.
 * NOTE:
 * If the shared memory object still exists, a valid handle is returned, but with the error code ERR_DUPLICATE.
 * RETURN: Handle to the shared memory object or RTS_INVALID_HANDLE if failed
 */
typedef struct tagsyssharedmemorycreate_struct
{
	RTS_IEC_STRING *pszName;			/* VAR_IN_OUT */	/* Name of the shared memory */
	RTS_IEC_UXINT ulPhysicalAddress;	/* VAR_INPUT */	/* Optional physical address. */
	RTS_IEC_UXINT *pulSize;				/* VAR_INPUT */	/* Pointer to requested size of the shared memory. */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library): */
	RTS_IEC_HANDLE SysSharedMemoryCreate;	/* VAR_OUTPUT */	
} syssharedmemorycreate_struct;

void CDECL CDECL_EXT syssharedmemorycreate(syssharedmemorycreate_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSHAREDMEMORYCREATE_IEC) (syssharedmemorycreate_struct *p);
#if defined(SYSSHM_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSHAREDMEMORYCREATE_NOTIMPLEMENTED)
	#define USE_syssharedmemorycreate
	#define EXT_syssharedmemorycreate
	#define GET_syssharedmemorycreate(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssharedmemorycreate(p0) 
	#define CHK_syssharedmemorycreate  FALSE
	#define EXP_syssharedmemorycreate  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssharedmemorycreate
	#define EXT_syssharedmemorycreate
	#define GET_syssharedmemorycreate(fl)  CAL_CMGETAPI( "syssharedmemorycreate" ) 
	#define CAL_syssharedmemorycreate  syssharedmemorycreate
	#define CHK_syssharedmemorycreate  TRUE
	#define EXP_syssharedmemorycreate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemorycreate", (RTS_UINTPTR)syssharedmemorycreate, 1, RTSITF_GET_SIGNATURE(0, 0x9DA848E2), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(SYSSHM_IMPLEMENTATION_EXTERNAL)
	#define USE_syssharedmemorycreate
	#define EXT_syssharedmemorycreate
	#define GET_syssharedmemorycreate(fl)  CAL_CMGETAPI( "syssharedmemorycreate" ) 
	#define CAL_syssharedmemorycreate  syssharedmemorycreate
	#define CHK_syssharedmemorycreate  TRUE
	#define EXP_syssharedmemorycreate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemorycreate", (RTS_UINTPTR)syssharedmemorycreate, 1, RTSITF_GET_SIGNATURE(0, 0x9DA848E2), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysShm_Implementationsyssharedmemorycreate
	#define EXT_SysShm_Implementationsyssharedmemorycreate
	#define GET_SysShm_Implementationsyssharedmemorycreate  ERR_OK
	#define CAL_SysShm_Implementationsyssharedmemorycreate  syssharedmemorycreate
	#define CHK_SysShm_Implementationsyssharedmemorycreate  TRUE
	#define EXP_SysShm_Implementationsyssharedmemorycreate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemorycreate", (RTS_UINTPTR)syssharedmemorycreate, 1, RTSITF_GET_SIGNATURE(0, 0x9DA848E2), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_syssharedmemorycreate
	#define EXT_syssharedmemorycreate
	#define GET_syssharedmemorycreate(fl)  CAL_CMGETAPI( "syssharedmemorycreate" ) 
	#define CAL_syssharedmemorycreate  syssharedmemorycreate
	#define CHK_syssharedmemorycreate  TRUE
	#define EXP_syssharedmemorycreate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemorycreate", (RTS_UINTPTR)syssharedmemorycreate, 1, RTSITF_GET_SIGNATURE(0, 0x9DA848E2), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_syssharedmemorycreate  PFSYSSHAREDMEMORYCREATE_IEC pfsyssharedmemorycreate;
	#define EXT_syssharedmemorycreate  extern PFSYSSHAREDMEMORYCREATE_IEC pfsyssharedmemorycreate;
	#define GET_syssharedmemorycreate(fl)  s_pfCMGetAPI2( "syssharedmemorycreate", (RTS_VOID_FCTPTR *)&pfsyssharedmemorycreate, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x9DA848E2), 0x03051000)
	#define CAL_syssharedmemorycreate  pfsyssharedmemorycreate
	#define CHK_syssharedmemorycreate  (pfsyssharedmemorycreate != NULL)
	#define EXP_syssharedmemorycreate   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemorycreate", (RTS_UINTPTR)syssharedmemorycreate, 1, RTSITF_GET_SIGNATURE(0, 0x9DA848E2), 0x03051000) 
#endif


/**
 * Delete a shared memory object specified by handle
 * RETURN: Returns the runtime system error code (see CmpErrors.library)
 */
typedef struct tagsyssharedmemorydelete_struct
{
	RTS_IEC_HANDLE hShm;				/* VAR_INPUT */	/* Handle to the shared memory */
	RTS_IEC_RESULT SysSharedMemoryDelete;	/* VAR_OUTPUT */	
} syssharedmemorydelete_struct;

void CDECL CDECL_EXT syssharedmemorydelete(syssharedmemorydelete_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSHAREDMEMORYDELETE_IEC) (syssharedmemorydelete_struct *p);
#if defined(SYSSHM_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSHAREDMEMORYDELETE_NOTIMPLEMENTED)
	#define USE_syssharedmemorydelete
	#define EXT_syssharedmemorydelete
	#define GET_syssharedmemorydelete(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssharedmemorydelete(p0) 
	#define CHK_syssharedmemorydelete  FALSE
	#define EXP_syssharedmemorydelete  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssharedmemorydelete
	#define EXT_syssharedmemorydelete
	#define GET_syssharedmemorydelete(fl)  CAL_CMGETAPI( "syssharedmemorydelete" ) 
	#define CAL_syssharedmemorydelete  syssharedmemorydelete
	#define CHK_syssharedmemorydelete  TRUE
	#define EXP_syssharedmemorydelete  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemorydelete", (RTS_UINTPTR)syssharedmemorydelete, 1, RTSITF_GET_SIGNATURE(0, 0x83C20043), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(SYSSHM_IMPLEMENTATION_EXTERNAL)
	#define USE_syssharedmemorydelete
	#define EXT_syssharedmemorydelete
	#define GET_syssharedmemorydelete(fl)  CAL_CMGETAPI( "syssharedmemorydelete" ) 
	#define CAL_syssharedmemorydelete  syssharedmemorydelete
	#define CHK_syssharedmemorydelete  TRUE
	#define EXP_syssharedmemorydelete  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemorydelete", (RTS_UINTPTR)syssharedmemorydelete, 1, RTSITF_GET_SIGNATURE(0, 0x83C20043), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysShm_Implementationsyssharedmemorydelete
	#define EXT_SysShm_Implementationsyssharedmemorydelete
	#define GET_SysShm_Implementationsyssharedmemorydelete  ERR_OK
	#define CAL_SysShm_Implementationsyssharedmemorydelete  syssharedmemorydelete
	#define CHK_SysShm_Implementationsyssharedmemorydelete  TRUE
	#define EXP_SysShm_Implementationsyssharedmemorydelete  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemorydelete", (RTS_UINTPTR)syssharedmemorydelete, 1, RTSITF_GET_SIGNATURE(0, 0x83C20043), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_syssharedmemorydelete
	#define EXT_syssharedmemorydelete
	#define GET_syssharedmemorydelete(fl)  CAL_CMGETAPI( "syssharedmemorydelete" ) 
	#define CAL_syssharedmemorydelete  syssharedmemorydelete
	#define CHK_syssharedmemorydelete  TRUE
	#define EXP_syssharedmemorydelete  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemorydelete", (RTS_UINTPTR)syssharedmemorydelete, 1, RTSITF_GET_SIGNATURE(0, 0x83C20043), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_syssharedmemorydelete  PFSYSSHAREDMEMORYDELETE_IEC pfsyssharedmemorydelete;
	#define EXT_syssharedmemorydelete  extern PFSYSSHAREDMEMORYDELETE_IEC pfsyssharedmemorydelete;
	#define GET_syssharedmemorydelete(fl)  s_pfCMGetAPI2( "syssharedmemorydelete", (RTS_VOID_FCTPTR *)&pfsyssharedmemorydelete, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x83C20043), 0x03051000)
	#define CAL_syssharedmemorydelete  pfsyssharedmemorydelete
	#define CHK_syssharedmemorydelete  (pfsyssharedmemorydelete != NULL)
	#define EXP_syssharedmemorydelete   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemorydelete", (RTS_UINTPTR)syssharedmemorydelete, 1, RTSITF_GET_SIGNATURE(0, 0x83C20043), 0x03051000) 
#endif


/**
 * Get the pointer to the shared memory
 * RETURN: Returns the runtime system error code (see CmpErrors.library)
 */
typedef struct tagsyssharedmemorygetpointer_struct
{
	RTS_IEC_HANDLE hShm;				/* VAR_INPUT */	/* Handle to the shared memory */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_BYTE *SysSharedMemoryGetPointer;	/* VAR_OUTPUT */	
} syssharedmemorygetpointer_struct;

void CDECL CDECL_EXT syssharedmemorygetpointer(syssharedmemorygetpointer_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSHAREDMEMORYGETPOINTER_IEC) (syssharedmemorygetpointer_struct *p);
#if defined(SYSSHM_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSHAREDMEMORYGETPOINTER_NOTIMPLEMENTED)
	#define USE_syssharedmemorygetpointer
	#define EXT_syssharedmemorygetpointer
	#define GET_syssharedmemorygetpointer(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssharedmemorygetpointer(p0) 
	#define CHK_syssharedmemorygetpointer  FALSE
	#define EXP_syssharedmemorygetpointer  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssharedmemorygetpointer
	#define EXT_syssharedmemorygetpointer
	#define GET_syssharedmemorygetpointer(fl)  CAL_CMGETAPI( "syssharedmemorygetpointer" ) 
	#define CAL_syssharedmemorygetpointer  syssharedmemorygetpointer
	#define CHK_syssharedmemorygetpointer  TRUE
	#define EXP_syssharedmemorygetpointer  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemorygetpointer", (RTS_UINTPTR)syssharedmemorygetpointer, 1, RTSITF_GET_SIGNATURE(0, 0x94066BAD), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(SYSSHM_IMPLEMENTATION_EXTERNAL)
	#define USE_syssharedmemorygetpointer
	#define EXT_syssharedmemorygetpointer
	#define GET_syssharedmemorygetpointer(fl)  CAL_CMGETAPI( "syssharedmemorygetpointer" ) 
	#define CAL_syssharedmemorygetpointer  syssharedmemorygetpointer
	#define CHK_syssharedmemorygetpointer  TRUE
	#define EXP_syssharedmemorygetpointer  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemorygetpointer", (RTS_UINTPTR)syssharedmemorygetpointer, 1, RTSITF_GET_SIGNATURE(0, 0x94066BAD), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysShm_Implementationsyssharedmemorygetpointer
	#define EXT_SysShm_Implementationsyssharedmemorygetpointer
	#define GET_SysShm_Implementationsyssharedmemorygetpointer  ERR_OK
	#define CAL_SysShm_Implementationsyssharedmemorygetpointer  syssharedmemorygetpointer
	#define CHK_SysShm_Implementationsyssharedmemorygetpointer  TRUE
	#define EXP_SysShm_Implementationsyssharedmemorygetpointer  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemorygetpointer", (RTS_UINTPTR)syssharedmemorygetpointer, 1, RTSITF_GET_SIGNATURE(0, 0x94066BAD), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_syssharedmemorygetpointer
	#define EXT_syssharedmemorygetpointer
	#define GET_syssharedmemorygetpointer(fl)  CAL_CMGETAPI( "syssharedmemorygetpointer" ) 
	#define CAL_syssharedmemorygetpointer  syssharedmemorygetpointer
	#define CHK_syssharedmemorygetpointer  TRUE
	#define EXP_syssharedmemorygetpointer  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemorygetpointer", (RTS_UINTPTR)syssharedmemorygetpointer, 1, RTSITF_GET_SIGNATURE(0, 0x94066BAD), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_syssharedmemorygetpointer  PFSYSSHAREDMEMORYGETPOINTER_IEC pfsyssharedmemorygetpointer;
	#define EXT_syssharedmemorygetpointer  extern PFSYSSHAREDMEMORYGETPOINTER_IEC pfsyssharedmemorygetpointer;
	#define GET_syssharedmemorygetpointer(fl)  s_pfCMGetAPI2( "syssharedmemorygetpointer", (RTS_VOID_FCTPTR *)&pfsyssharedmemorygetpointer, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x94066BAD), 0x03051000)
	#define CAL_syssharedmemorygetpointer  pfsyssharedmemorygetpointer
	#define CHK_syssharedmemorygetpointer  (pfsyssharedmemorygetpointer != NULL)
	#define EXP_syssharedmemorygetpointer   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemorygetpointer", (RTS_UINTPTR)syssharedmemorygetpointer, 1, RTSITF_GET_SIGNATURE(0, 0x94066BAD), 0x03051000) 
#endif


/**
 * *OBSOLETE FUNCTION*
 *  Opens an existing shared memory object specified by name. If shared memory does not exist, a new shared memory object is
 *	 created (backward compatibility)!
 */
typedef struct tagsyssharedmemoryopen_struct
{
	RTS_IEC_STRING *pszName;			/* VAR_IN_OUT */	/* Name of the shared memory */
	RTS_IEC_UXINT ulPhysicalAddress;	/* VAR_INPUT */	/* Optional physical address. */
	RTS_IEC_UXINT *pulSize;				/* VAR_INPUT */	/* Pointer to requested size of the shared memory. */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library): */
	RTS_IEC_HANDLE SysSharedMemoryOpen;	/* VAR_OUTPUT */	
} syssharedmemoryopen_struct;

void CDECL CDECL_EXT syssharedmemoryopen(syssharedmemoryopen_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSHAREDMEMORYOPEN_IEC) (syssharedmemoryopen_struct *p);
#if defined(SYSSHM_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSHAREDMEMORYOPEN_NOTIMPLEMENTED)
	#define USE_syssharedmemoryopen
	#define EXT_syssharedmemoryopen
	#define GET_syssharedmemoryopen(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssharedmemoryopen(p0) 
	#define CHK_syssharedmemoryopen  FALSE
	#define EXP_syssharedmemoryopen  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssharedmemoryopen
	#define EXT_syssharedmemoryopen
	#define GET_syssharedmemoryopen(fl)  CAL_CMGETAPI( "syssharedmemoryopen" ) 
	#define CAL_syssharedmemoryopen  syssharedmemoryopen
	#define CHK_syssharedmemoryopen  TRUE
	#define EXP_syssharedmemoryopen  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemoryopen", (RTS_UINTPTR)syssharedmemoryopen, 1, RTSITF_GET_SIGNATURE(0, 0x41FB9CC1), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(SYSSHM_IMPLEMENTATION_EXTERNAL)
	#define USE_syssharedmemoryopen
	#define EXT_syssharedmemoryopen
	#define GET_syssharedmemoryopen(fl)  CAL_CMGETAPI( "syssharedmemoryopen" ) 
	#define CAL_syssharedmemoryopen  syssharedmemoryopen
	#define CHK_syssharedmemoryopen  TRUE
	#define EXP_syssharedmemoryopen  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemoryopen", (RTS_UINTPTR)syssharedmemoryopen, 1, RTSITF_GET_SIGNATURE(0, 0x41FB9CC1), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysShm_Implementationsyssharedmemoryopen
	#define EXT_SysShm_Implementationsyssharedmemoryopen
	#define GET_SysShm_Implementationsyssharedmemoryopen  ERR_OK
	#define CAL_SysShm_Implementationsyssharedmemoryopen  syssharedmemoryopen
	#define CHK_SysShm_Implementationsyssharedmemoryopen  TRUE
	#define EXP_SysShm_Implementationsyssharedmemoryopen  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemoryopen", (RTS_UINTPTR)syssharedmemoryopen, 1, RTSITF_GET_SIGNATURE(0, 0x41FB9CC1), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_syssharedmemoryopen
	#define EXT_syssharedmemoryopen
	#define GET_syssharedmemoryopen(fl)  CAL_CMGETAPI( "syssharedmemoryopen" ) 
	#define CAL_syssharedmemoryopen  syssharedmemoryopen
	#define CHK_syssharedmemoryopen  TRUE
	#define EXP_syssharedmemoryopen  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemoryopen", (RTS_UINTPTR)syssharedmemoryopen, 1, RTSITF_GET_SIGNATURE(0, 0x41FB9CC1), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_syssharedmemoryopen  PFSYSSHAREDMEMORYOPEN_IEC pfsyssharedmemoryopen;
	#define EXT_syssharedmemoryopen  extern PFSYSSHAREDMEMORYOPEN_IEC pfsyssharedmemoryopen;
	#define GET_syssharedmemoryopen(fl)  s_pfCMGetAPI2( "syssharedmemoryopen", (RTS_VOID_FCTPTR *)&pfsyssharedmemoryopen, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x41FB9CC1), 0x03051000)
	#define CAL_syssharedmemoryopen  pfsyssharedmemoryopen
	#define CHK_syssharedmemoryopen  (pfsyssharedmemoryopen != NULL)
	#define EXP_syssharedmemoryopen   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemoryopen", (RTS_UINTPTR)syssharedmemoryopen, 1, RTSITF_GET_SIGNATURE(0, 0x41FB9CC1), 0x03051000) 
#endif


/**
 * Opens an existing shared memory object specified by name.
 *	NOTE:
 *	If shared memory object not exists, an error code is returned an it is not created!
 * RETURN: Handle to the shared memory object or RTS_INVALID_HANDLE if failed
 */
typedef struct tagsyssharedmemoryopen2_struct
{
	RTS_IEC_STRING *pszName;			/* VAR_IN_OUT */	/* Name of the shared memory */
	RTS_IEC_UXINT ulPhysicalAddress;	/* VAR_INPUT */	/* Optional physical address: */
	RTS_IEC_UXINT *pulSize;				/* VAR_INPUT */	/* Pointer to requested size of the shared memory. */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library): */
	RTS_IEC_HANDLE SysSharedMemoryOpen2;	/* VAR_OUTPUT */	
} syssharedmemoryopen2_struct;

void CDECL CDECL_EXT syssharedmemoryopen2(syssharedmemoryopen2_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSHAREDMEMORYOPEN2_IEC) (syssharedmemoryopen2_struct *p);
#if defined(SYSSHM_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSHAREDMEMORYOPEN2_NOTIMPLEMENTED)
	#define USE_syssharedmemoryopen2
	#define EXT_syssharedmemoryopen2
	#define GET_syssharedmemoryopen2(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssharedmemoryopen2(p0) 
	#define CHK_syssharedmemoryopen2  FALSE
	#define EXP_syssharedmemoryopen2  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssharedmemoryopen2
	#define EXT_syssharedmemoryopen2
	#define GET_syssharedmemoryopen2(fl)  CAL_CMGETAPI( "syssharedmemoryopen2" ) 
	#define CAL_syssharedmemoryopen2  syssharedmemoryopen2
	#define CHK_syssharedmemoryopen2  TRUE
	#define EXP_syssharedmemoryopen2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemoryopen2", (RTS_UINTPTR)syssharedmemoryopen2, 1, RTSITF_GET_SIGNATURE(0, 0x69CA7C0D), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(SYSSHM_IMPLEMENTATION_EXTERNAL)
	#define USE_syssharedmemoryopen2
	#define EXT_syssharedmemoryopen2
	#define GET_syssharedmemoryopen2(fl)  CAL_CMGETAPI( "syssharedmemoryopen2" ) 
	#define CAL_syssharedmemoryopen2  syssharedmemoryopen2
	#define CHK_syssharedmemoryopen2  TRUE
	#define EXP_syssharedmemoryopen2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemoryopen2", (RTS_UINTPTR)syssharedmemoryopen2, 1, RTSITF_GET_SIGNATURE(0, 0x69CA7C0D), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysShm_Implementationsyssharedmemoryopen2
	#define EXT_SysShm_Implementationsyssharedmemoryopen2
	#define GET_SysShm_Implementationsyssharedmemoryopen2  ERR_OK
	#define CAL_SysShm_Implementationsyssharedmemoryopen2  syssharedmemoryopen2
	#define CHK_SysShm_Implementationsyssharedmemoryopen2  TRUE
	#define EXP_SysShm_Implementationsyssharedmemoryopen2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemoryopen2", (RTS_UINTPTR)syssharedmemoryopen2, 1, RTSITF_GET_SIGNATURE(0, 0x69CA7C0D), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_syssharedmemoryopen2
	#define EXT_syssharedmemoryopen2
	#define GET_syssharedmemoryopen2(fl)  CAL_CMGETAPI( "syssharedmemoryopen2" ) 
	#define CAL_syssharedmemoryopen2  syssharedmemoryopen2
	#define CHK_syssharedmemoryopen2  TRUE
	#define EXP_syssharedmemoryopen2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemoryopen2", (RTS_UINTPTR)syssharedmemoryopen2, 1, RTSITF_GET_SIGNATURE(0, 0x69CA7C0D), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_syssharedmemoryopen2  PFSYSSHAREDMEMORYOPEN2_IEC pfsyssharedmemoryopen2;
	#define EXT_syssharedmemoryopen2  extern PFSYSSHAREDMEMORYOPEN2_IEC pfsyssharedmemoryopen2;
	#define GET_syssharedmemoryopen2(fl)  s_pfCMGetAPI2( "syssharedmemoryopen2", (RTS_VOID_FCTPTR *)&pfsyssharedmemoryopen2, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x69CA7C0D), 0x03051000)
	#define CAL_syssharedmemoryopen2  pfsyssharedmemoryopen2
	#define CHK_syssharedmemoryopen2  (pfsyssharedmemoryopen2 != NULL)
	#define EXP_syssharedmemoryopen2   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemoryopen2", (RTS_UINTPTR)syssharedmemoryopen2, 1, RTSITF_GET_SIGNATURE(0, 0x69CA7C0D), 0x03051000) 
#endif


/**
 * This function can be used to read a defined number of bytes from a Shared Memory, starting at a certain offset.
 * RETURN: Number of bytes read from the shared memory
 */
typedef struct tagsyssharedmemoryread_struct
{
	RTS_IEC_HANDLE hShm;				/* VAR_INPUT */	/* Handle to the shared memory */
	RTS_IEC_UXINT ulOffset;				/* VAR_INPUT */	/* Offset in the shared memory, where reading should start */
	RTS_IEC_BYTE *pbyData;				/* VAR_INPUT */	/* Pointer to buffer to read in data */
	RTS_IEC_UXINT ulSize;				/* VAR_INPUT */	/* Number of bytes to read */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_UXINT SysSharedMemoryRead;	/* VAR_OUTPUT */	
} syssharedmemoryread_struct;

void CDECL CDECL_EXT syssharedmemoryread(syssharedmemoryread_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSHAREDMEMORYREAD_IEC) (syssharedmemoryread_struct *p);
#if defined(SYSSHM_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSHAREDMEMORYREAD_NOTIMPLEMENTED)
	#define USE_syssharedmemoryread
	#define EXT_syssharedmemoryread
	#define GET_syssharedmemoryread(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssharedmemoryread(p0) 
	#define CHK_syssharedmemoryread  FALSE
	#define EXP_syssharedmemoryread  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssharedmemoryread
	#define EXT_syssharedmemoryread
	#define GET_syssharedmemoryread(fl)  CAL_CMGETAPI( "syssharedmemoryread" ) 
	#define CAL_syssharedmemoryread  syssharedmemoryread
	#define CHK_syssharedmemoryread  TRUE
	#define EXP_syssharedmemoryread  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemoryread", (RTS_UINTPTR)syssharedmemoryread, 1, RTSITF_GET_SIGNATURE(0, 0x67AB02BB), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(SYSSHM_IMPLEMENTATION_EXTERNAL)
	#define USE_syssharedmemoryread
	#define EXT_syssharedmemoryread
	#define GET_syssharedmemoryread(fl)  CAL_CMGETAPI( "syssharedmemoryread" ) 
	#define CAL_syssharedmemoryread  syssharedmemoryread
	#define CHK_syssharedmemoryread  TRUE
	#define EXP_syssharedmemoryread  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemoryread", (RTS_UINTPTR)syssharedmemoryread, 1, RTSITF_GET_SIGNATURE(0, 0x67AB02BB), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysShm_Implementationsyssharedmemoryread
	#define EXT_SysShm_Implementationsyssharedmemoryread
	#define GET_SysShm_Implementationsyssharedmemoryread  ERR_OK
	#define CAL_SysShm_Implementationsyssharedmemoryread  syssharedmemoryread
	#define CHK_SysShm_Implementationsyssharedmemoryread  TRUE
	#define EXP_SysShm_Implementationsyssharedmemoryread  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemoryread", (RTS_UINTPTR)syssharedmemoryread, 1, RTSITF_GET_SIGNATURE(0, 0x67AB02BB), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_syssharedmemoryread
	#define EXT_syssharedmemoryread
	#define GET_syssharedmemoryread(fl)  CAL_CMGETAPI( "syssharedmemoryread" ) 
	#define CAL_syssharedmemoryread  syssharedmemoryread
	#define CHK_syssharedmemoryread  TRUE
	#define EXP_syssharedmemoryread  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemoryread", (RTS_UINTPTR)syssharedmemoryread, 1, RTSITF_GET_SIGNATURE(0, 0x67AB02BB), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_syssharedmemoryread  PFSYSSHAREDMEMORYREAD_IEC pfsyssharedmemoryread;
	#define EXT_syssharedmemoryread  extern PFSYSSHAREDMEMORYREAD_IEC pfsyssharedmemoryread;
	#define GET_syssharedmemoryread(fl)  s_pfCMGetAPI2( "syssharedmemoryread", (RTS_VOID_FCTPTR *)&pfsyssharedmemoryread, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x67AB02BB), 0x03051000)
	#define CAL_syssharedmemoryread  pfsyssharedmemoryread
	#define CHK_syssharedmemoryread  (pfsyssharedmemoryread != NULL)
	#define EXP_syssharedmemoryread   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemoryread", (RTS_UINTPTR)syssharedmemoryread, 1, RTSITF_GET_SIGNATURE(0, 0x67AB02BB), 0x03051000) 
#endif


/**
 * This function can be used to read "byte-wise" a defined number of bytes, starting at a certain offset.
 * RETURN: Number of bytes read from the shared memory
 */
typedef struct tagsyssharedmemoryreadbyte_struct
{
	RTS_IEC_HANDLE hShm;				/* VAR_INPUT */	/* Handle to the shared memory */
	RTS_IEC_UXINT ulOffset;				/* VAR_INPUT */	/* Offset in the shared memory, where reading should start */
	RTS_IEC_BYTE *pbyData;				/* VAR_INPUT */	/* Pointer to buffer to read in data */
	RTS_IEC_UXINT ulSize;				/* VAR_INPUT */	/* Number of bytes to read */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_UXINT SysSharedMemoryReadByte;	/* VAR_OUTPUT */	
} syssharedmemoryreadbyte_struct;

void CDECL CDECL_EXT syssharedmemoryreadbyte(syssharedmemoryreadbyte_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSHAREDMEMORYREADBYTE_IEC) (syssharedmemoryreadbyte_struct *p);
#if defined(SYSSHM_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSHAREDMEMORYREADBYTE_NOTIMPLEMENTED)
	#define USE_syssharedmemoryreadbyte
	#define EXT_syssharedmemoryreadbyte
	#define GET_syssharedmemoryreadbyte(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssharedmemoryreadbyte(p0) 
	#define CHK_syssharedmemoryreadbyte  FALSE
	#define EXP_syssharedmemoryreadbyte  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssharedmemoryreadbyte
	#define EXT_syssharedmemoryreadbyte
	#define GET_syssharedmemoryreadbyte(fl)  CAL_CMGETAPI( "syssharedmemoryreadbyte" ) 
	#define CAL_syssharedmemoryreadbyte  syssharedmemoryreadbyte
	#define CHK_syssharedmemoryreadbyte  TRUE
	#define EXP_syssharedmemoryreadbyte  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemoryreadbyte", (RTS_UINTPTR)syssharedmemoryreadbyte, 1, RTSITF_GET_SIGNATURE(0, 0x0E49748E), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(SYSSHM_IMPLEMENTATION_EXTERNAL)
	#define USE_syssharedmemoryreadbyte
	#define EXT_syssharedmemoryreadbyte
	#define GET_syssharedmemoryreadbyte(fl)  CAL_CMGETAPI( "syssharedmemoryreadbyte" ) 
	#define CAL_syssharedmemoryreadbyte  syssharedmemoryreadbyte
	#define CHK_syssharedmemoryreadbyte  TRUE
	#define EXP_syssharedmemoryreadbyte  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemoryreadbyte", (RTS_UINTPTR)syssharedmemoryreadbyte, 1, RTSITF_GET_SIGNATURE(0, 0x0E49748E), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysShm_Implementationsyssharedmemoryreadbyte
	#define EXT_SysShm_Implementationsyssharedmemoryreadbyte
	#define GET_SysShm_Implementationsyssharedmemoryreadbyte  ERR_OK
	#define CAL_SysShm_Implementationsyssharedmemoryreadbyte  syssharedmemoryreadbyte
	#define CHK_SysShm_Implementationsyssharedmemoryreadbyte  TRUE
	#define EXP_SysShm_Implementationsyssharedmemoryreadbyte  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemoryreadbyte", (RTS_UINTPTR)syssharedmemoryreadbyte, 1, RTSITF_GET_SIGNATURE(0, 0x0E49748E), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_syssharedmemoryreadbyte
	#define EXT_syssharedmemoryreadbyte
	#define GET_syssharedmemoryreadbyte(fl)  CAL_CMGETAPI( "syssharedmemoryreadbyte" ) 
	#define CAL_syssharedmemoryreadbyte  syssharedmemoryreadbyte
	#define CHK_syssharedmemoryreadbyte  TRUE
	#define EXP_syssharedmemoryreadbyte  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemoryreadbyte", (RTS_UINTPTR)syssharedmemoryreadbyte, 1, RTSITF_GET_SIGNATURE(0, 0x0E49748E), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_syssharedmemoryreadbyte  PFSYSSHAREDMEMORYREADBYTE_IEC pfsyssharedmemoryreadbyte;
	#define EXT_syssharedmemoryreadbyte  extern PFSYSSHAREDMEMORYREADBYTE_IEC pfsyssharedmemoryreadbyte;
	#define GET_syssharedmemoryreadbyte(fl)  s_pfCMGetAPI2( "syssharedmemoryreadbyte", (RTS_VOID_FCTPTR *)&pfsyssharedmemoryreadbyte, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x0E49748E), 0x03051000)
	#define CAL_syssharedmemoryreadbyte  pfsyssharedmemoryreadbyte
	#define CHK_syssharedmemoryreadbyte  (pfsyssharedmemoryreadbyte != NULL)
	#define EXP_syssharedmemoryreadbyte   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemoryreadbyte", (RTS_UINTPTR)syssharedmemoryreadbyte, 1, RTSITF_GET_SIGNATURE(0, 0x0E49748E), 0x03051000) 
#endif


/**
 * This function can be used to write a defined number of bytes to a Shared Memory area, starting at a certain offset address.
 * RETURN: Number of bytes written to the shared memory
 */
typedef struct tagsyssharedmemorywrite_struct
{
	RTS_IEC_HANDLE hShm;				/* VAR_INPUT */	/* Handle to the shared memory */
	RTS_IEC_UXINT ulOffset;				/* VAR_INPUT */	/* Offset in the shared memory */
	RTS_IEC_BYTE *pbyData;				/* VAR_INPUT */	/* Pointer to buffer with write data */
	RTS_IEC_UXINT ulSize;				/* VAR_INPUT */	/* Number of bytes to write */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_UXINT SysSharedMemoryWrite;	/* VAR_OUTPUT */	
} syssharedmemorywrite_struct;

void CDECL CDECL_EXT syssharedmemorywrite(syssharedmemorywrite_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSHAREDMEMORYWRITE_IEC) (syssharedmemorywrite_struct *p);
#if defined(SYSSHM_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSHAREDMEMORYWRITE_NOTIMPLEMENTED)
	#define USE_syssharedmemorywrite
	#define EXT_syssharedmemorywrite
	#define GET_syssharedmemorywrite(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssharedmemorywrite(p0) 
	#define CHK_syssharedmemorywrite  FALSE
	#define EXP_syssharedmemorywrite  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssharedmemorywrite
	#define EXT_syssharedmemorywrite
	#define GET_syssharedmemorywrite(fl)  CAL_CMGETAPI( "syssharedmemorywrite" ) 
	#define CAL_syssharedmemorywrite  syssharedmemorywrite
	#define CHK_syssharedmemorywrite  TRUE
	#define EXP_syssharedmemorywrite  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemorywrite", (RTS_UINTPTR)syssharedmemorywrite, 1, RTSITF_GET_SIGNATURE(0, 0xE23019DB), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(SYSSHM_IMPLEMENTATION_EXTERNAL)
	#define USE_syssharedmemorywrite
	#define EXT_syssharedmemorywrite
	#define GET_syssharedmemorywrite(fl)  CAL_CMGETAPI( "syssharedmemorywrite" ) 
	#define CAL_syssharedmemorywrite  syssharedmemorywrite
	#define CHK_syssharedmemorywrite  TRUE
	#define EXP_syssharedmemorywrite  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemorywrite", (RTS_UINTPTR)syssharedmemorywrite, 1, RTSITF_GET_SIGNATURE(0, 0xE23019DB), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysShm_Implementationsyssharedmemorywrite
	#define EXT_SysShm_Implementationsyssharedmemorywrite
	#define GET_SysShm_Implementationsyssharedmemorywrite  ERR_OK
	#define CAL_SysShm_Implementationsyssharedmemorywrite  syssharedmemorywrite
	#define CHK_SysShm_Implementationsyssharedmemorywrite  TRUE
	#define EXP_SysShm_Implementationsyssharedmemorywrite  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemorywrite", (RTS_UINTPTR)syssharedmemorywrite, 1, RTSITF_GET_SIGNATURE(0, 0xE23019DB), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_syssharedmemorywrite
	#define EXT_syssharedmemorywrite
	#define GET_syssharedmemorywrite(fl)  CAL_CMGETAPI( "syssharedmemorywrite" ) 
	#define CAL_syssharedmemorywrite  syssharedmemorywrite
	#define CHK_syssharedmemorywrite  TRUE
	#define EXP_syssharedmemorywrite  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemorywrite", (RTS_UINTPTR)syssharedmemorywrite, 1, RTSITF_GET_SIGNATURE(0, 0xE23019DB), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_syssharedmemorywrite  PFSYSSHAREDMEMORYWRITE_IEC pfsyssharedmemorywrite;
	#define EXT_syssharedmemorywrite  extern PFSYSSHAREDMEMORYWRITE_IEC pfsyssharedmemorywrite;
	#define GET_syssharedmemorywrite(fl)  s_pfCMGetAPI2( "syssharedmemorywrite", (RTS_VOID_FCTPTR *)&pfsyssharedmemorywrite, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xE23019DB), 0x03051000)
	#define CAL_syssharedmemorywrite  pfsyssharedmemorywrite
	#define CHK_syssharedmemorywrite  (pfsyssharedmemorywrite != NULL)
	#define EXP_syssharedmemorywrite   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemorywrite", (RTS_UINTPTR)syssharedmemorywrite, 1, RTSITF_GET_SIGNATURE(0, 0xE23019DB), 0x03051000) 
#endif


/**
 * This function can be used to write a defined number of bytes in "byte-wise" manner to a Shared Memory area, starting at a certain offset address.
 * RETURN: Number of bytes written to the shared memory
 */
typedef struct tagsyssharedmemorywritebyte_struct
{
	RTS_IEC_HANDLE hShm;				/* VAR_INPUT */	/* Handle to the shared memory */
	RTS_IEC_UXINT ulOffset;				/* VAR_INPUT */	/* Offset in the shared memory */
	RTS_IEC_BYTE *pbyData;				/* VAR_INPUT */	/* Pointer to buffer with write data */
	RTS_IEC_UXINT ulSize;				/* VAR_INPUT */	/* Number of bytes to write */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_UXINT SysSharedMemoryWriteByte;	/* VAR_OUTPUT */	
} syssharedmemorywritebyte_struct;

void CDECL CDECL_EXT syssharedmemorywritebyte(syssharedmemorywritebyte_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSHAREDMEMORYWRITEBYTE_IEC) (syssharedmemorywritebyte_struct *p);
#if defined(SYSSHM_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSHAREDMEMORYWRITEBYTE_NOTIMPLEMENTED)
	#define USE_syssharedmemorywritebyte
	#define EXT_syssharedmemorywritebyte
	#define GET_syssharedmemorywritebyte(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssharedmemorywritebyte(p0) 
	#define CHK_syssharedmemorywritebyte  FALSE
	#define EXP_syssharedmemorywritebyte  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssharedmemorywritebyte
	#define EXT_syssharedmemorywritebyte
	#define GET_syssharedmemorywritebyte(fl)  CAL_CMGETAPI( "syssharedmemorywritebyte" ) 
	#define CAL_syssharedmemorywritebyte  syssharedmemorywritebyte
	#define CHK_syssharedmemorywritebyte  TRUE
	#define EXP_syssharedmemorywritebyte  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemorywritebyte", (RTS_UINTPTR)syssharedmemorywritebyte, 1, RTSITF_GET_SIGNATURE(0, 0xF3240E6E), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(SYSSHM_IMPLEMENTATION_EXTERNAL)
	#define USE_syssharedmemorywritebyte
	#define EXT_syssharedmemorywritebyte
	#define GET_syssharedmemorywritebyte(fl)  CAL_CMGETAPI( "syssharedmemorywritebyte" ) 
	#define CAL_syssharedmemorywritebyte  syssharedmemorywritebyte
	#define CHK_syssharedmemorywritebyte  TRUE
	#define EXP_syssharedmemorywritebyte  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemorywritebyte", (RTS_UINTPTR)syssharedmemorywritebyte, 1, RTSITF_GET_SIGNATURE(0, 0xF3240E6E), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysShm_Implementationsyssharedmemorywritebyte
	#define EXT_SysShm_Implementationsyssharedmemorywritebyte
	#define GET_SysShm_Implementationsyssharedmemorywritebyte  ERR_OK
	#define CAL_SysShm_Implementationsyssharedmemorywritebyte  syssharedmemorywritebyte
	#define CHK_SysShm_Implementationsyssharedmemorywritebyte  TRUE
	#define EXP_SysShm_Implementationsyssharedmemorywritebyte  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemorywritebyte", (RTS_UINTPTR)syssharedmemorywritebyte, 1, RTSITF_GET_SIGNATURE(0, 0xF3240E6E), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_syssharedmemorywritebyte
	#define EXT_syssharedmemorywritebyte
	#define GET_syssharedmemorywritebyte(fl)  CAL_CMGETAPI( "syssharedmemorywritebyte" ) 
	#define CAL_syssharedmemorywritebyte  syssharedmemorywritebyte
	#define CHK_syssharedmemorywritebyte  TRUE
	#define EXP_syssharedmemorywritebyte  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemorywritebyte", (RTS_UINTPTR)syssharedmemorywritebyte, 1, RTSITF_GET_SIGNATURE(0, 0xF3240E6E), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_syssharedmemorywritebyte  PFSYSSHAREDMEMORYWRITEBYTE_IEC pfsyssharedmemorywritebyte;
	#define EXT_syssharedmemorywritebyte  extern PFSYSSHAREDMEMORYWRITEBYTE_IEC pfsyssharedmemorywritebyte;
	#define GET_syssharedmemorywritebyte(fl)  s_pfCMGetAPI2( "syssharedmemorywritebyte", (RTS_VOID_FCTPTR *)&pfsyssharedmemorywritebyte, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xF3240E6E), 0x03051000)
	#define CAL_syssharedmemorywritebyte  pfsyssharedmemorywritebyte
	#define CHK_syssharedmemorywritebyte  (pfsyssharedmemorywritebyte != NULL)
	#define EXP_syssharedmemorywritebyte   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssharedmemorywritebyte", (RTS_UINTPTR)syssharedmemorywritebyte, 1, RTSITF_GET_SIGNATURE(0, 0xF3240E6E), 0x03051000) 
#endif


#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/




typedef struct
{
	IBase_C *pBase;
} ISysShm_Implementation_C;

#ifdef CPLUSPLUS
class ISysShm_Implementation : public IBase
{
	public:
};
	#ifndef ITF_SysShm_Implementation
		#define ITF_SysShm_Implementation static ISysShm_Implementation *pISysShm_Implementation = NULL;
	#endif
	#define EXTITF_SysShm_Implementation
#else	/*CPLUSPLUS*/
	typedef ISysShm_Implementation_C		ISysShm_Implementation;
	#ifndef ITF_SysShm_Implementation
		#define ITF_SysShm_Implementation
	#endif
	#define EXTITF_SysShm_Implementation
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_SYSSHM_IMPLEMENTATIONITF_H_*/
