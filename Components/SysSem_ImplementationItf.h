 /**
 * <interfacename>SysSem_Implementation</interfacename>
 * <description></description>
 *
 * <copyright></copyright>
 */


	
	
#ifndef _SYSSEM_IMPLEMENTATIONITF_H_
#define _SYSSEM_IMPLEMENTATIONITF_H_

#include "CmpStd.h"

 

 




/** EXTERN LIB SECTION BEGIN **/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * This function can be used to create a semaphore (synchronization object).
 * :return: Handle to the semaphore or RTS_INVALID_HANDLE if failed.
 */
typedef struct tagsyssemcreate_struct
{
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_HANDLE SysSemCreate;		/* VAR_OUTPUT */	
} syssemcreate_struct;

void CDECL CDECL_EXT syssemcreate(syssemcreate_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSEMCREATE_IEC) (syssemcreate_struct *p);
#if defined(SYSSEM_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSEMCREATE_NOTIMPLEMENTED)
	#define USE_syssemcreate
	#define EXT_syssemcreate
	#define GET_syssemcreate(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssemcreate(p0) 
	#define CHK_syssemcreate  FALSE
	#define EXP_syssemcreate  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssemcreate
	#define EXT_syssemcreate
	#define GET_syssemcreate(fl)  CAL_CMGETAPI( "syssemcreate" ) 
	#define CAL_syssemcreate  syssemcreate
	#define CHK_syssemcreate  TRUE
	#define EXP_syssemcreate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssemcreate", (RTS_UINTPTR)syssemcreate, 1, RTSITF_GET_SIGNATURE(0, 0x9344C747), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(SYSSEM_IMPLEMENTATION_EXTERNAL)
	#define USE_syssemcreate
	#define EXT_syssemcreate
	#define GET_syssemcreate(fl)  CAL_CMGETAPI( "syssemcreate" ) 
	#define CAL_syssemcreate  syssemcreate
	#define CHK_syssemcreate  TRUE
	#define EXP_syssemcreate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssemcreate", (RTS_UINTPTR)syssemcreate, 1, RTSITF_GET_SIGNATURE(0, 0x9344C747), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSem_Implementationsyssemcreate
	#define EXT_SysSem_Implementationsyssemcreate
	#define GET_SysSem_Implementationsyssemcreate  ERR_OK
	#define CAL_SysSem_Implementationsyssemcreate  syssemcreate
	#define CHK_SysSem_Implementationsyssemcreate  TRUE
	#define EXP_SysSem_Implementationsyssemcreate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssemcreate", (RTS_UINTPTR)syssemcreate, 1, RTSITF_GET_SIGNATURE(0, 0x9344C747), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_syssemcreate
	#define EXT_syssemcreate
	#define GET_syssemcreate(fl)  CAL_CMGETAPI( "syssemcreate" ) 
	#define CAL_syssemcreate  syssemcreate
	#define CHK_syssemcreate  TRUE
	#define EXP_syssemcreate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssemcreate", (RTS_UINTPTR)syssemcreate, 1, RTSITF_GET_SIGNATURE(0, 0x9344C747), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_syssemcreate  PFSYSSEMCREATE_IEC pfsyssemcreate;
	#define EXT_syssemcreate  extern PFSYSSEMCREATE_IEC pfsyssemcreate;
	#define GET_syssemcreate(fl)  s_pfCMGetAPI2( "syssemcreate", (RTS_VOID_FCTPTR *)&pfsyssemcreate, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x9344C747), 0x03051000)
	#define CAL_syssemcreate  pfsyssemcreate
	#define CHK_syssemcreate  (pfsyssemcreate != NULL)
	#define EXP_syssemcreate   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssemcreate", (RTS_UINTPTR)syssemcreate, 1, RTSITF_GET_SIGNATURE(0, 0x9344C747), 0x03051000) 
#endif


/**
 * This function deletes the semaphore which is identified by its handle.
 * :return: Return the runtime system error code (see CmpErrors.library)
 */
typedef struct tagsyssemdelete_struct
{
	RTS_IEC_HANDLE hSem;				/* VAR_INPUT */	/* Handle of the semaphore */
	RTS_IEC_RESULT SysSemDelete;		/* VAR_OUTPUT */	
} syssemdelete_struct;

void CDECL CDECL_EXT syssemdelete(syssemdelete_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSEMDELETE_IEC) (syssemdelete_struct *p);
#if defined(SYSSEM_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSEMDELETE_NOTIMPLEMENTED)
	#define USE_syssemdelete
	#define EXT_syssemdelete
	#define GET_syssemdelete(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssemdelete(p0) 
	#define CHK_syssemdelete  FALSE
	#define EXP_syssemdelete  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssemdelete
	#define EXT_syssemdelete
	#define GET_syssemdelete(fl)  CAL_CMGETAPI( "syssemdelete" ) 
	#define CAL_syssemdelete  syssemdelete
	#define CHK_syssemdelete  TRUE
	#define EXP_syssemdelete  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssemdelete", (RTS_UINTPTR)syssemdelete, 1, RTSITF_GET_SIGNATURE(0, 0x88B7C7F6), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(SYSSEM_IMPLEMENTATION_EXTERNAL)
	#define USE_syssemdelete
	#define EXT_syssemdelete
	#define GET_syssemdelete(fl)  CAL_CMGETAPI( "syssemdelete" ) 
	#define CAL_syssemdelete  syssemdelete
	#define CHK_syssemdelete  TRUE
	#define EXP_syssemdelete  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssemdelete", (RTS_UINTPTR)syssemdelete, 1, RTSITF_GET_SIGNATURE(0, 0x88B7C7F6), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSem_Implementationsyssemdelete
	#define EXT_SysSem_Implementationsyssemdelete
	#define GET_SysSem_Implementationsyssemdelete  ERR_OK
	#define CAL_SysSem_Implementationsyssemdelete  syssemdelete
	#define CHK_SysSem_Implementationsyssemdelete  TRUE
	#define EXP_SysSem_Implementationsyssemdelete  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssemdelete", (RTS_UINTPTR)syssemdelete, 1, RTSITF_GET_SIGNATURE(0, 0x88B7C7F6), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_syssemdelete
	#define EXT_syssemdelete
	#define GET_syssemdelete(fl)  CAL_CMGETAPI( "syssemdelete" ) 
	#define CAL_syssemdelete  syssemdelete
	#define CHK_syssemdelete  TRUE
	#define EXP_syssemdelete  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssemdelete", (RTS_UINTPTR)syssemdelete, 1, RTSITF_GET_SIGNATURE(0, 0x88B7C7F6), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_syssemdelete  PFSYSSEMDELETE_IEC pfsyssemdelete;
	#define EXT_syssemdelete  extern PFSYSSEMDELETE_IEC pfsyssemdelete;
	#define GET_syssemdelete(fl)  s_pfCMGetAPI2( "syssemdelete", (RTS_VOID_FCTPTR *)&pfsyssemdelete, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x88B7C7F6), 0x03051000)
	#define CAL_syssemdelete  pfsyssemdelete
	#define CHK_syssemdelete  (pfsyssemdelete != NULL)
	#define EXP_syssemdelete   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssemdelete", (RTS_UINTPTR)syssemdelete, 1, RTSITF_GET_SIGNATURE(0, 0x88B7C7F6), 0x03051000) 
#endif


/**
 * This function must be called before a task accesses data which also are used by other tasks.
 * Thus the data will be bocked for other tasks, which also use SysSemEnter until by function SysSemLeave the semaphore
 * will be set free again. The semaphore is identified by its handle.
 * :return: Returns the runtime system error code (see CmpErrors.library)
 */
typedef struct tagsyssementer_struct
{
	RTS_IEC_HANDLE hSem;				/* VAR_INPUT */	/* Handle of the semaphore */
	RTS_IEC_RESULT SysSemEnter;			/* VAR_OUTPUT */	
} syssementer_struct;

void CDECL CDECL_EXT syssementer(syssementer_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSEMENTER_IEC) (syssementer_struct *p);
#if defined(SYSSEM_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSEMENTER_NOTIMPLEMENTED)
	#define USE_syssementer
	#define EXT_syssementer
	#define GET_syssementer(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssementer(p0) 
	#define CHK_syssementer  FALSE
	#define EXP_syssementer  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssementer
	#define EXT_syssementer
	#define GET_syssementer(fl)  CAL_CMGETAPI( "syssementer" ) 
	#define CAL_syssementer  syssementer
	#define CHK_syssementer  TRUE
	#define EXP_syssementer  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssementer", (RTS_UINTPTR)syssementer, 1, RTSITF_GET_SIGNATURE(0, 0x85E1C5F9), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(SYSSEM_IMPLEMENTATION_EXTERNAL)
	#define USE_syssementer
	#define EXT_syssementer
	#define GET_syssementer(fl)  CAL_CMGETAPI( "syssementer" ) 
	#define CAL_syssementer  syssementer
	#define CHK_syssementer  TRUE
	#define EXP_syssementer  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssementer", (RTS_UINTPTR)syssementer, 1, RTSITF_GET_SIGNATURE(0, 0x85E1C5F9), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSem_Implementationsyssementer
	#define EXT_SysSem_Implementationsyssementer
	#define GET_SysSem_Implementationsyssementer  ERR_OK
	#define CAL_SysSem_Implementationsyssementer  syssementer
	#define CHK_SysSem_Implementationsyssementer  TRUE
	#define EXP_SysSem_Implementationsyssementer  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssementer", (RTS_UINTPTR)syssementer, 1, RTSITF_GET_SIGNATURE(0, 0x85E1C5F9), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_syssementer
	#define EXT_syssementer
	#define GET_syssementer(fl)  CAL_CMGETAPI( "syssementer" ) 
	#define CAL_syssementer  syssementer
	#define CHK_syssementer  TRUE
	#define EXP_syssementer  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssementer", (RTS_UINTPTR)syssementer, 1, RTSITF_GET_SIGNATURE(0, 0x85E1C5F9), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_syssementer  PFSYSSEMENTER_IEC pfsyssementer;
	#define EXT_syssementer  extern PFSYSSEMENTER_IEC pfsyssementer;
	#define GET_syssementer(fl)  s_pfCMGetAPI2( "syssementer", (RTS_VOID_FCTPTR *)&pfsyssementer, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x85E1C5F9), 0x03051000)
	#define CAL_syssementer  pfsyssementer
	#define CHK_syssementer  (pfsyssementer != NULL)
	#define EXP_syssementer   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssementer", (RTS_UINTPTR)syssementer, 1, RTSITF_GET_SIGNATURE(0, 0x85E1C5F9), 0x03051000) 
#endif


/**
 * This function must be called after an access on data which are also used by other tasks.
 * This is necessary to release the semaphore, which has been blocked before the access by function SysSemEnter.
 * The semaphore is identified by its handle.
 * :return: Returns the runtime system error code (see CmpErrors.library)
 */
typedef struct tagsyssemleave_struct
{
	RTS_IEC_HANDLE hSem;				/* VAR_INPUT */	/* Handle of the semaphore */
	RTS_IEC_RESULT SysSemLeave;			/* VAR_OUTPUT */	
} syssemleave_struct;

void CDECL CDECL_EXT syssemleave(syssemleave_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSEMLEAVE_IEC) (syssemleave_struct *p);
#if defined(SYSSEM_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSEMLEAVE_NOTIMPLEMENTED)
	#define USE_syssemleave
	#define EXT_syssemleave
	#define GET_syssemleave(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssemleave(p0) 
	#define CHK_syssemleave  FALSE
	#define EXP_syssemleave  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssemleave
	#define EXT_syssemleave
	#define GET_syssemleave(fl)  CAL_CMGETAPI( "syssemleave" ) 
	#define CAL_syssemleave  syssemleave
	#define CHK_syssemleave  TRUE
	#define EXP_syssemleave  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssemleave", (RTS_UINTPTR)syssemleave, 1, RTSITF_GET_SIGNATURE(0, 0x2AA5DCFF), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(SYSSEM_IMPLEMENTATION_EXTERNAL)
	#define USE_syssemleave
	#define EXT_syssemleave
	#define GET_syssemleave(fl)  CAL_CMGETAPI( "syssemleave" ) 
	#define CAL_syssemleave  syssemleave
	#define CHK_syssemleave  TRUE
	#define EXP_syssemleave  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssemleave", (RTS_UINTPTR)syssemleave, 1, RTSITF_GET_SIGNATURE(0, 0x2AA5DCFF), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSem_Implementationsyssemleave
	#define EXT_SysSem_Implementationsyssemleave
	#define GET_SysSem_Implementationsyssemleave  ERR_OK
	#define CAL_SysSem_Implementationsyssemleave  syssemleave
	#define CHK_SysSem_Implementationsyssemleave  TRUE
	#define EXP_SysSem_Implementationsyssemleave  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssemleave", (RTS_UINTPTR)syssemleave, 1, RTSITF_GET_SIGNATURE(0, 0x2AA5DCFF), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_syssemleave
	#define EXT_syssemleave
	#define GET_syssemleave(fl)  CAL_CMGETAPI( "syssemleave" ) 
	#define CAL_syssemleave  syssemleave
	#define CHK_syssemleave  TRUE
	#define EXP_syssemleave  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssemleave", (RTS_UINTPTR)syssemleave, 1, RTSITF_GET_SIGNATURE(0, 0x2AA5DCFF), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_syssemleave  PFSYSSEMLEAVE_IEC pfsyssemleave;
	#define EXT_syssemleave  extern PFSYSSEMLEAVE_IEC pfsyssemleave;
	#define GET_syssemleave(fl)  s_pfCMGetAPI2( "syssemleave", (RTS_VOID_FCTPTR *)&pfsyssemleave, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x2AA5DCFF), 0x03051000)
	#define CAL_syssemleave  pfsyssemleave
	#define CHK_syssemleave  (pfsyssemleave != NULL)
	#define EXP_syssemleave   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssemleave", (RTS_UINTPTR)syssemleave, 1, RTSITF_GET_SIGNATURE(0, 0x2AA5DCFF), 0x03051000) 
#endif


/**
 * Try to enter the semaphore. If semaphore is available, the function 
 * entered the semaphore and returned ERR_OK. If semaphore is not available, ERR_FAILED is returned. 
 * The semaphore is identified by its handle.
 *
 *
 * .. note::
 * 		Function is not blocking instead of SysSemEnter! Function returns immediate with an entered lock (ERR_OK) or without having the lock (ERR_FAILED)!
 *
 * :return: Returns the runtime system error code (see CmpErrors.library)
 */
typedef struct tagsyssemtry_struct
{
	RTS_IEC_HANDLE hSem;				/* VAR_INPUT */	/* Handle of the semaphore */
	RTS_IEC_RESULT SysSemTry;			/* VAR_OUTPUT */	
} syssemtry_struct;

void CDECL CDECL_EXT syssemtry(syssemtry_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSEMTRY_IEC) (syssemtry_struct *p);
#if defined(SYSSEM_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSEMTRY_NOTIMPLEMENTED)
	#define USE_syssemtry
	#define EXT_syssemtry
	#define GET_syssemtry(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssemtry(p0) 
	#define CHK_syssemtry  FALSE
	#define EXP_syssemtry  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssemtry
	#define EXT_syssemtry
	#define GET_syssemtry(fl)  CAL_CMGETAPI( "syssemtry" ) 
	#define CAL_syssemtry  syssemtry
	#define CHK_syssemtry  TRUE
	#define EXP_syssemtry  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssemtry", (RTS_UINTPTR)syssemtry, 1, RTSITF_GET_SIGNATURE(0, 0x14382CB4), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(SYSSEM_IMPLEMENTATION_EXTERNAL)
	#define USE_syssemtry
	#define EXT_syssemtry
	#define GET_syssemtry(fl)  CAL_CMGETAPI( "syssemtry" ) 
	#define CAL_syssemtry  syssemtry
	#define CHK_syssemtry  TRUE
	#define EXP_syssemtry  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssemtry", (RTS_UINTPTR)syssemtry, 1, RTSITF_GET_SIGNATURE(0, 0x14382CB4), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSem_Implementationsyssemtry
	#define EXT_SysSem_Implementationsyssemtry
	#define GET_SysSem_Implementationsyssemtry  ERR_OK
	#define CAL_SysSem_Implementationsyssemtry  syssemtry
	#define CHK_SysSem_Implementationsyssemtry  TRUE
	#define EXP_SysSem_Implementationsyssemtry  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssemtry", (RTS_UINTPTR)syssemtry, 1, RTSITF_GET_SIGNATURE(0, 0x14382CB4), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_syssemtry
	#define EXT_syssemtry
	#define GET_syssemtry(fl)  CAL_CMGETAPI( "syssemtry" ) 
	#define CAL_syssemtry  syssemtry
	#define CHK_syssemtry  TRUE
	#define EXP_syssemtry  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssemtry", (RTS_UINTPTR)syssemtry, 1, RTSITF_GET_SIGNATURE(0, 0x14382CB4), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_syssemtry  PFSYSSEMTRY_IEC pfsyssemtry;
	#define EXT_syssemtry  extern PFSYSSEMTRY_IEC pfsyssemtry;
	#define GET_syssemtry(fl)  s_pfCMGetAPI2( "syssemtry", (RTS_VOID_FCTPTR *)&pfsyssemtry, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x14382CB4), 0x03051000)
	#define CAL_syssemtry  pfsyssemtry
	#define CHK_syssemtry  (pfsyssemtry != NULL)
	#define EXP_syssemtry   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssemtry", (RTS_UINTPTR)syssemtry, 1, RTSITF_GET_SIGNATURE(0, 0x14382CB4), 0x03051000) 
#endif


#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/




typedef struct
{
	IBase_C *pBase;
} ISysSem_Implementation_C;

#ifdef CPLUSPLUS
class ISysSem_Implementation : public IBase
{
	public:
};
	#ifndef ITF_SysSem_Implementation
		#define ITF_SysSem_Implementation static ISysSem_Implementation *pISysSem_Implementation = NULL;
	#endif
	#define EXTITF_SysSem_Implementation
#else	/*CPLUSPLUS*/
	typedef ISysSem_Implementation_C		ISysSem_Implementation;
	#ifndef ITF_SysSem_Implementation
		#define ITF_SysSem_Implementation
	#endif
	#define EXTITF_SysSem_Implementation
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_SYSSEM_IMPLEMENTATIONITF_H_*/
