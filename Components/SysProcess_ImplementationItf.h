 /**
 * <interfacename>SysProcess_Implementation</interfacename>
 * <description></description>
 *
 * <copyright></copyright>
 */


	
	
#ifndef _SYSPROCESS_IMPLEMENTATIONITF_H_
#define _SYSPROCESS_IMPLEMENTATIONITF_H_

#include "CmpStd.h"

 

 




/** EXTERN LIB SECTION BEGIN **/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description>Function to create a process. NOTE: Is only available on systems with processes!
 * This function starts the specified application as new process, optionally either in the fore- or in the background.
 * </description>
 * <result><p>RESULT: Handle to the created process or RTS_INVALID_HANDLE if failed.</p></result>
 */
typedef struct tagsysprocesscreate_struct
{
	RTS_IEC_STRING *pszApplication;		/* VAR_INPUT */	/* <param name="pszApplication" type="IN">Name of application to start as a separate process</param> */
	RTS_IEC_STRING *pszCommandLine;		/* VAR_INPUT */	/* <param name="pszCommandLine" type="IN">String with the command line</param> */
	RTS_IEC_UDINT ulHide;				/* VAR_INPUT */	/* <param name="ulHide" type="IN">The application runs in the background for ulHide=1, else in the foreground.</param> */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* <param name="pResult" type="OUT">Pointer to runtime system error code (see CmpErrors.library)</param> */
	RTS_IEC_HANDLE SysProcessCreate;	/* VAR_OUTPUT */	
} sysprocesscreate_struct;

void CDECL CDECL_EXT sysprocesscreate(sysprocesscreate_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSPROCESSCREATE_IEC) (sysprocesscreate_struct *p);
#if defined(SYSPROCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSPROCESSCREATE_NOTIMPLEMENTED)
	#define USE_sysprocesscreate
	#define EXT_sysprocesscreate
	#define GET_sysprocesscreate(fl)  ERR_NOTIMPLEMENTED
	#define CAL_sysprocesscreate(p0) 
	#define CHK_sysprocesscreate  FALSE
	#define EXP_sysprocesscreate  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_sysprocesscreate
	#define EXT_sysprocesscreate
	#define GET_sysprocesscreate(fl)  CAL_CMGETAPI( "sysprocesscreate" ) 
	#define CAL_sysprocesscreate  sysprocesscreate
	#define CHK_sysprocesscreate  TRUE
	#define EXP_sysprocesscreate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocesscreate", (RTS_UINTPTR)sysprocesscreate, 1, RTSITF_GET_SIGNATURE(0, 0xB8C769CB), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(SYSPROCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_sysprocesscreate
	#define EXT_sysprocesscreate
	#define GET_sysprocesscreate(fl)  CAL_CMGETAPI( "sysprocesscreate" ) 
	#define CAL_sysprocesscreate  sysprocesscreate
	#define CHK_sysprocesscreate  TRUE
	#define EXP_sysprocesscreate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocesscreate", (RTS_UINTPTR)sysprocesscreate, 1, RTSITF_GET_SIGNATURE(0, 0xB8C769CB), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysProcess_Implementationsysprocesscreate
	#define EXT_SysProcess_Implementationsysprocesscreate
	#define GET_SysProcess_Implementationsysprocesscreate  ERR_OK
	#define CAL_SysProcess_Implementationsysprocesscreate  sysprocesscreate
	#define CHK_SysProcess_Implementationsysprocesscreate  TRUE
	#define EXP_SysProcess_Implementationsysprocesscreate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocesscreate", (RTS_UINTPTR)sysprocesscreate, 1, RTSITF_GET_SIGNATURE(0, 0xB8C769CB), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_sysprocesscreate
	#define EXT_sysprocesscreate
	#define GET_sysprocesscreate(fl)  CAL_CMGETAPI( "sysprocesscreate" ) 
	#define CAL_sysprocesscreate  sysprocesscreate
	#define CHK_sysprocesscreate  TRUE
	#define EXP_sysprocesscreate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocesscreate", (RTS_UINTPTR)sysprocesscreate, 1, RTSITF_GET_SIGNATURE(0, 0xB8C769CB), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_sysprocesscreate  PFSYSPROCESSCREATE_IEC pfsysprocesscreate;
	#define EXT_sysprocesscreate  extern PFSYSPROCESSCREATE_IEC pfsysprocesscreate;
	#define GET_sysprocesscreate(fl)  s_pfCMGetAPI2( "sysprocesscreate", (RTS_VOID_FCTPTR *)&pfsysprocesscreate, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xB8C769CB), 0x03051000)
	#define CAL_sysprocesscreate  pfsysprocesscreate
	#define CHK_sysprocesscreate  (pfsysprocesscreate != NULL)
	#define EXP_sysprocesscreate   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocesscreate", (RTS_UINTPTR)sysprocesscreate, 1, RTSITF_GET_SIGNATURE(0, 0xB8C769CB), 0x03051000) 
#endif


/**
 * <description>Function to create a process. NOTE: Is only available on systems with processes!
 * This functions creates and eventually starts a new process for the specified application. The properties of the
 * created process can be defined by appropriate flags.</description>
 * <result><p>RESULT: Handle to the created process or RTS_INVALID_HANDLE if failed.</p></result>
 */
typedef struct tagsysprocesscreate2_struct
{
	RTS_IEC_STRING *pszApplication;		/* VAR_INPUT */	/* <param name="pszApplication" type="IN">Name of application to start as a separate process</param> */
	RTS_IEC_STRING *pszCommandLine;		/* VAR_INPUT */	/* <param name="pszCommandLine" type="IN">String with the command line</param> */
	RTS_IEC_UDINT ulFlags;				/* VAR_INPUT */	/* <param name="ulFlags" type="IN">A combination of the process flags SYSPROCESS_CREATEFLAG_XXX.</param> */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* <param name="pResult" type="OUT">Pointer to runtime system error code (see CmpErrors.library)</param> */
	RTS_IEC_HANDLE SysProcessCreate2;	/* VAR_OUTPUT */	
} sysprocesscreate2_struct;

void CDECL CDECL_EXT sysprocesscreate2(sysprocesscreate2_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSPROCESSCREATE2_IEC) (sysprocesscreate2_struct *p);
#if defined(SYSPROCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSPROCESSCREATE2_NOTIMPLEMENTED)
	#define USE_sysprocesscreate2
	#define EXT_sysprocesscreate2
	#define GET_sysprocesscreate2(fl)  ERR_NOTIMPLEMENTED
	#define CAL_sysprocesscreate2(p0) 
	#define CHK_sysprocesscreate2  FALSE
	#define EXP_sysprocesscreate2  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_sysprocesscreate2
	#define EXT_sysprocesscreate2
	#define GET_sysprocesscreate2(fl)  CAL_CMGETAPI( "sysprocesscreate2" ) 
	#define CAL_sysprocesscreate2  sysprocesscreate2
	#define CHK_sysprocesscreate2  TRUE
	#define EXP_sysprocesscreate2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocesscreate2", (RTS_UINTPTR)sysprocesscreate2, 1, RTSITF_GET_SIGNATURE(0, 0x053781FD), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(SYSPROCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_sysprocesscreate2
	#define EXT_sysprocesscreate2
	#define GET_sysprocesscreate2(fl)  CAL_CMGETAPI( "sysprocesscreate2" ) 
	#define CAL_sysprocesscreate2  sysprocesscreate2
	#define CHK_sysprocesscreate2  TRUE
	#define EXP_sysprocesscreate2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocesscreate2", (RTS_UINTPTR)sysprocesscreate2, 1, RTSITF_GET_SIGNATURE(0, 0x053781FD), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysProcess_Implementationsysprocesscreate2
	#define EXT_SysProcess_Implementationsysprocesscreate2
	#define GET_SysProcess_Implementationsysprocesscreate2  ERR_OK
	#define CAL_SysProcess_Implementationsysprocesscreate2  sysprocesscreate2
	#define CHK_SysProcess_Implementationsysprocesscreate2  TRUE
	#define EXP_SysProcess_Implementationsysprocesscreate2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocesscreate2", (RTS_UINTPTR)sysprocesscreate2, 1, RTSITF_GET_SIGNATURE(0, 0x053781FD), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_sysprocesscreate2
	#define EXT_sysprocesscreate2
	#define GET_sysprocesscreate2(fl)  CAL_CMGETAPI( "sysprocesscreate2" ) 
	#define CAL_sysprocesscreate2  sysprocesscreate2
	#define CHK_sysprocesscreate2  TRUE
	#define EXP_sysprocesscreate2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocesscreate2", (RTS_UINTPTR)sysprocesscreate2, 1, RTSITF_GET_SIGNATURE(0, 0x053781FD), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_sysprocesscreate2  PFSYSPROCESSCREATE2_IEC pfsysprocesscreate2;
	#define EXT_sysprocesscreate2  extern PFSYSPROCESSCREATE2_IEC pfsysprocesscreate2;
	#define GET_sysprocesscreate2(fl)  s_pfCMGetAPI2( "sysprocesscreate2", (RTS_VOID_FCTPTR *)&pfsysprocesscreate2, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x053781FD), 0x03051000)
	#define CAL_sysprocesscreate2  pfsysprocesscreate2
	#define CHK_sysprocesscreate2  (pfsysprocesscreate2 != NULL)
	#define EXP_sysprocesscreate2   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocesscreate2", (RTS_UINTPTR)sysprocesscreate2, 1, RTSITF_GET_SIGNATURE(0, 0x053781FD), 0x03051000) 
#endif


/**
 * <description>Function to start a system command. The command is operating system dependent!</description>
 * <result><p>RESULT: Result of command after execution</p></result>
 */
typedef struct tagsysprocessexecutecommand_struct
{
	RTS_IEC_STRING *pszComand;			/* VAR_INPUT */	/* <param name="pszCommand" type="IN">Command line parameters to be transmitted to application at execution</param> */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* <param name="pResult" type="OUT">Pointer to runtime system error code (see CmpErrors.library)</param> */
	RTS_IEC_DINT SysProcessExecuteCommand;	/* VAR_OUTPUT */	
} sysprocessexecutecommand_struct;

void CDECL CDECL_EXT sysprocessexecutecommand(sysprocessexecutecommand_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSPROCESSEXECUTECOMMAND_IEC) (sysprocessexecutecommand_struct *p);
#if defined(SYSPROCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSPROCESSEXECUTECOMMAND_NOTIMPLEMENTED)
	#define USE_sysprocessexecutecommand
	#define EXT_sysprocessexecutecommand
	#define GET_sysprocessexecutecommand(fl)  ERR_NOTIMPLEMENTED
	#define CAL_sysprocessexecutecommand(p0) 
	#define CHK_sysprocessexecutecommand  FALSE
	#define EXP_sysprocessexecutecommand  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_sysprocessexecutecommand
	#define EXT_sysprocessexecutecommand
	#define GET_sysprocessexecutecommand(fl)  CAL_CMGETAPI( "sysprocessexecutecommand" ) 
	#define CAL_sysprocessexecutecommand  sysprocessexecutecommand
	#define CHK_sysprocessexecutecommand  TRUE
	#define EXP_sysprocessexecutecommand  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessexecutecommand", (RTS_UINTPTR)sysprocessexecutecommand, 1, RTSITF_GET_SIGNATURE(0, 0xE26B1ECD), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(SYSPROCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_sysprocessexecutecommand
	#define EXT_sysprocessexecutecommand
	#define GET_sysprocessexecutecommand(fl)  CAL_CMGETAPI( "sysprocessexecutecommand" ) 
	#define CAL_sysprocessexecutecommand  sysprocessexecutecommand
	#define CHK_sysprocessexecutecommand  TRUE
	#define EXP_sysprocessexecutecommand  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessexecutecommand", (RTS_UINTPTR)sysprocessexecutecommand, 1, RTSITF_GET_SIGNATURE(0, 0xE26B1ECD), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysProcess_Implementationsysprocessexecutecommand
	#define EXT_SysProcess_Implementationsysprocessexecutecommand
	#define GET_SysProcess_Implementationsysprocessexecutecommand  ERR_OK
	#define CAL_SysProcess_Implementationsysprocessexecutecommand  sysprocessexecutecommand
	#define CHK_SysProcess_Implementationsysprocessexecutecommand  TRUE
	#define EXP_SysProcess_Implementationsysprocessexecutecommand  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessexecutecommand", (RTS_UINTPTR)sysprocessexecutecommand, 1, RTSITF_GET_SIGNATURE(0, 0xE26B1ECD), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_sysprocessexecutecommand
	#define EXT_sysprocessexecutecommand
	#define GET_sysprocessexecutecommand(fl)  CAL_CMGETAPI( "sysprocessexecutecommand" ) 
	#define CAL_sysprocessexecutecommand  sysprocessexecutecommand
	#define CHK_sysprocessexecutecommand  TRUE
	#define EXP_sysprocessexecutecommand  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessexecutecommand", (RTS_UINTPTR)sysprocessexecutecommand, 1, RTSITF_GET_SIGNATURE(0, 0xE26B1ECD), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_sysprocessexecutecommand  PFSYSPROCESSEXECUTECOMMAND_IEC pfsysprocessexecutecommand;
	#define EXT_sysprocessexecutecommand  extern PFSYSPROCESSEXECUTECOMMAND_IEC pfsysprocessexecutecommand;
	#define GET_sysprocessexecutecommand(fl)  s_pfCMGetAPI2( "sysprocessexecutecommand", (RTS_VOID_FCTPTR *)&pfsysprocessexecutecommand, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xE26B1ECD), 0x03051000)
	#define CAL_sysprocessexecutecommand  pfsysprocessexecutecommand
	#define CHK_sysprocessexecutecommand  (pfsysprocessexecutecommand != NULL)
	#define EXP_sysprocessexecutecommand   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessexecutecommand", (RTS_UINTPTR)sysprocessexecutecommand, 1, RTSITF_GET_SIGNATURE(0, 0xE26B1ECD), 0x03051000) 
#endif


/**
 * <description>Function to start a system command. The command is operating system dependent! 
 *	Command will be executed, only if allowed (see settings for details). Output of the executed command will be filled into pszStdOut.
 * </description>
 * <result><p>RESULT: Number of bytes, read from the commands output.</p></result>
 */
typedef struct tagsysprocessexecutecommand2_struct
{
	RTS_IEC_STRING *pszCommand;			/* VAR_INPUT */	/* <param name="pszCommand" type="IN">Command line parameters to be transmitted to application at execution</param> */
	RTS_IEC_STRING *pszStdOut;			/* VAR_INPUT */	/* <param name="pszStdOut" type="IN">Buffer for StdOut string</param> */
	RTS_IEC_UDINT udiStdOutLen;			/* VAR_INPUT */	/* <param name="udiStdOutLen" type="IN">Buffersize for StdOut string buffer</param> */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* <param name="pResult" type="OUT">Pointer to runtime system error code. ERR_PARAMETER: if pszCommand, pszStdOut or udiStdOutLen is null, ERR_NO_ACCESS_RIGHTS: if command is not allowed</param> */
	RTS_IEC_DINT SysProcessExecuteCommand2;	/* VAR_OUTPUT */	
} sysprocessexecutecommand2_struct;

void CDECL CDECL_EXT sysprocessexecutecommand2(sysprocessexecutecommand2_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSPROCESSEXECUTECOMMAND2_IEC) (sysprocessexecutecommand2_struct *p);
#if defined(SYSPROCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSPROCESSEXECUTECOMMAND2_NOTIMPLEMENTED)
	#define USE_sysprocessexecutecommand2
	#define EXT_sysprocessexecutecommand2
	#define GET_sysprocessexecutecommand2(fl)  ERR_NOTIMPLEMENTED
	#define CAL_sysprocessexecutecommand2(p0) 
	#define CHK_sysprocessexecutecommand2  FALSE
	#define EXP_sysprocessexecutecommand2  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_sysprocessexecutecommand2
	#define EXT_sysprocessexecutecommand2
	#define GET_sysprocessexecutecommand2(fl)  CAL_CMGETAPI( "sysprocessexecutecommand2" ) 
	#define CAL_sysprocessexecutecommand2  sysprocessexecutecommand2
	#define CHK_sysprocessexecutecommand2  TRUE
	#define EXP_sysprocessexecutecommand2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessexecutecommand2", (RTS_UINTPTR)sysprocessexecutecommand2, 1, RTSITF_GET_SIGNATURE(0, 0x827A1263), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(SYSPROCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_sysprocessexecutecommand2
	#define EXT_sysprocessexecutecommand2
	#define GET_sysprocessexecutecommand2(fl)  CAL_CMGETAPI( "sysprocessexecutecommand2" ) 
	#define CAL_sysprocessexecutecommand2  sysprocessexecutecommand2
	#define CHK_sysprocessexecutecommand2  TRUE
	#define EXP_sysprocessexecutecommand2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessexecutecommand2", (RTS_UINTPTR)sysprocessexecutecommand2, 1, RTSITF_GET_SIGNATURE(0, 0x827A1263), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysProcess_Implementationsysprocessexecutecommand2
	#define EXT_SysProcess_Implementationsysprocessexecutecommand2
	#define GET_SysProcess_Implementationsysprocessexecutecommand2  ERR_OK
	#define CAL_SysProcess_Implementationsysprocessexecutecommand2  sysprocessexecutecommand2
	#define CHK_SysProcess_Implementationsysprocessexecutecommand2  TRUE
	#define EXP_SysProcess_Implementationsysprocessexecutecommand2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessexecutecommand2", (RTS_UINTPTR)sysprocessexecutecommand2, 1, RTSITF_GET_SIGNATURE(0, 0x827A1263), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_sysprocessexecutecommand2
	#define EXT_sysprocessexecutecommand2
	#define GET_sysprocessexecutecommand2(fl)  CAL_CMGETAPI( "sysprocessexecutecommand2" ) 
	#define CAL_sysprocessexecutecommand2  sysprocessexecutecommand2
	#define CHK_sysprocessexecutecommand2  TRUE
	#define EXP_sysprocessexecutecommand2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessexecutecommand2", (RTS_UINTPTR)sysprocessexecutecommand2, 1, RTSITF_GET_SIGNATURE(0, 0x827A1263), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_sysprocessexecutecommand2  PFSYSPROCESSEXECUTECOMMAND2_IEC pfsysprocessexecutecommand2;
	#define EXT_sysprocessexecutecommand2  extern PFSYSPROCESSEXECUTECOMMAND2_IEC pfsysprocessexecutecommand2;
	#define GET_sysprocessexecutecommand2(fl)  s_pfCMGetAPI2( "sysprocessexecutecommand2", (RTS_VOID_FCTPTR *)&pfsysprocessexecutecommand2, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x827A1263), 0x03051000)
	#define CAL_sysprocessexecutecommand2  pfsysprocessexecutecommand2
	#define CHK_sysprocessexecutecommand2  (pfsysprocessexecutecommand2 != NULL)
	#define EXP_sysprocessexecutecommand2   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessexecutecommand2", (RTS_UINTPTR)sysprocessexecutecommand2, 1, RTSITF_GET_SIGNATURE(0, 0x827A1263), 0x03051000) 
#endif


/**
 * <description>Function to release the process handle that is returned by SysProcessCreate or SysProcessGetCurrentHandle.</description>
 * <result><p>RESULT: Returns the runtime system error code (see CmpErrors.library).</p></result>
 */
typedef struct tagsysprocessfreehandle_struct
{
	RTS_IEC_HANDLE hProcess;			/* VAR_INPUT */	/* <param name="hProcess" type="IN">Handle of the process</param> */
	RTS_IEC_RESULT SysProcessFreeHandle;	/* VAR_OUTPUT */	
} sysprocessfreehandle_struct;

void CDECL CDECL_EXT sysprocessfreehandle(sysprocessfreehandle_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSPROCESSFREEHANDLE_IEC) (sysprocessfreehandle_struct *p);
#if defined(SYSPROCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSPROCESSFREEHANDLE_NOTIMPLEMENTED)
	#define USE_sysprocessfreehandle
	#define EXT_sysprocessfreehandle
	#define GET_sysprocessfreehandle(fl)  ERR_NOTIMPLEMENTED
	#define CAL_sysprocessfreehandle(p0) 
	#define CHK_sysprocessfreehandle  FALSE
	#define EXP_sysprocessfreehandle  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_sysprocessfreehandle
	#define EXT_sysprocessfreehandle
	#define GET_sysprocessfreehandle(fl)  CAL_CMGETAPI( "sysprocessfreehandle" ) 
	#define CAL_sysprocessfreehandle  sysprocessfreehandle
	#define CHK_sysprocessfreehandle  TRUE
	#define EXP_sysprocessfreehandle  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessfreehandle", (RTS_UINTPTR)sysprocessfreehandle, 1, RTSITF_GET_SIGNATURE(0, 0xD81A18BC), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(SYSPROCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_sysprocessfreehandle
	#define EXT_sysprocessfreehandle
	#define GET_sysprocessfreehandle(fl)  CAL_CMGETAPI( "sysprocessfreehandle" ) 
	#define CAL_sysprocessfreehandle  sysprocessfreehandle
	#define CHK_sysprocessfreehandle  TRUE
	#define EXP_sysprocessfreehandle  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessfreehandle", (RTS_UINTPTR)sysprocessfreehandle, 1, RTSITF_GET_SIGNATURE(0, 0xD81A18BC), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysProcess_Implementationsysprocessfreehandle
	#define EXT_SysProcess_Implementationsysprocessfreehandle
	#define GET_SysProcess_Implementationsysprocessfreehandle  ERR_OK
	#define CAL_SysProcess_Implementationsysprocessfreehandle  sysprocessfreehandle
	#define CHK_SysProcess_Implementationsysprocessfreehandle  TRUE
	#define EXP_SysProcess_Implementationsysprocessfreehandle  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessfreehandle", (RTS_UINTPTR)sysprocessfreehandle, 1, RTSITF_GET_SIGNATURE(0, 0xD81A18BC), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_sysprocessfreehandle
	#define EXT_sysprocessfreehandle
	#define GET_sysprocessfreehandle(fl)  CAL_CMGETAPI( "sysprocessfreehandle" ) 
	#define CAL_sysprocessfreehandle  sysprocessfreehandle
	#define CHK_sysprocessfreehandle  TRUE
	#define EXP_sysprocessfreehandle  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessfreehandle", (RTS_UINTPTR)sysprocessfreehandle, 1, RTSITF_GET_SIGNATURE(0, 0xD81A18BC), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_sysprocessfreehandle  PFSYSPROCESSFREEHANDLE_IEC pfsysprocessfreehandle;
	#define EXT_sysprocessfreehandle  extern PFSYSPROCESSFREEHANDLE_IEC pfsysprocessfreehandle;
	#define GET_sysprocessfreehandle(fl)  s_pfCMGetAPI2( "sysprocessfreehandle", (RTS_VOID_FCTPTR *)&pfsysprocessfreehandle, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xD81A18BC), 0x03051000)
	#define CAL_sysprocessfreehandle  pfsysprocessfreehandle
	#define CHK_sysprocessfreehandle  (pfsysprocessfreehandle != NULL)
	#define EXP_sysprocessfreehandle   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessfreehandle", (RTS_UINTPTR)sysprocessfreehandle, 1, RTSITF_GET_SIGNATURE(0, 0xD81A18BC), 0x03051000) 
#endif


/**
 * <description>Function to get a handle to the current process</description>
 * <result><p>RESULT: Returns the handle of the process actually running by the processor or RTS_INVALID_HANDLE if failed.</p></result>
 */
typedef struct tagsysprocessgetcurrenthandle_struct
{
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* <param name="pResult" type="OUT">Pointer to runtime system error code (see CmpErrors.library)</param> */
	RTS_IEC_HANDLE SysProcessGetCurrentHandle;	/* VAR_OUTPUT */	
} sysprocessgetcurrenthandle_struct;

void CDECL CDECL_EXT sysprocessgetcurrenthandle(sysprocessgetcurrenthandle_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSPROCESSGETCURRENTHANDLE_IEC) (sysprocessgetcurrenthandle_struct *p);
#if defined(SYSPROCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSPROCESSGETCURRENTHANDLE_NOTIMPLEMENTED)
	#define USE_sysprocessgetcurrenthandle
	#define EXT_sysprocessgetcurrenthandle
	#define GET_sysprocessgetcurrenthandle(fl)  ERR_NOTIMPLEMENTED
	#define CAL_sysprocessgetcurrenthandle(p0) 
	#define CHK_sysprocessgetcurrenthandle  FALSE
	#define EXP_sysprocessgetcurrenthandle  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_sysprocessgetcurrenthandle
	#define EXT_sysprocessgetcurrenthandle
	#define GET_sysprocessgetcurrenthandle(fl)  CAL_CMGETAPI( "sysprocessgetcurrenthandle" ) 
	#define CAL_sysprocessgetcurrenthandle  sysprocessgetcurrenthandle
	#define CHK_sysprocessgetcurrenthandle  TRUE
	#define EXP_sysprocessgetcurrenthandle  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessgetcurrenthandle", (RTS_UINTPTR)sysprocessgetcurrenthandle, 1, RTSITF_GET_SIGNATURE(0, 0xF293D47C), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(SYSPROCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_sysprocessgetcurrenthandle
	#define EXT_sysprocessgetcurrenthandle
	#define GET_sysprocessgetcurrenthandle(fl)  CAL_CMGETAPI( "sysprocessgetcurrenthandle" ) 
	#define CAL_sysprocessgetcurrenthandle  sysprocessgetcurrenthandle
	#define CHK_sysprocessgetcurrenthandle  TRUE
	#define EXP_sysprocessgetcurrenthandle  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessgetcurrenthandle", (RTS_UINTPTR)sysprocessgetcurrenthandle, 1, RTSITF_GET_SIGNATURE(0, 0xF293D47C), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysProcess_Implementationsysprocessgetcurrenthandle
	#define EXT_SysProcess_Implementationsysprocessgetcurrenthandle
	#define GET_SysProcess_Implementationsysprocessgetcurrenthandle  ERR_OK
	#define CAL_SysProcess_Implementationsysprocessgetcurrenthandle  sysprocessgetcurrenthandle
	#define CHK_SysProcess_Implementationsysprocessgetcurrenthandle  TRUE
	#define EXP_SysProcess_Implementationsysprocessgetcurrenthandle  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessgetcurrenthandle", (RTS_UINTPTR)sysprocessgetcurrenthandle, 1, RTSITF_GET_SIGNATURE(0, 0xF293D47C), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_sysprocessgetcurrenthandle
	#define EXT_sysprocessgetcurrenthandle
	#define GET_sysprocessgetcurrenthandle(fl)  CAL_CMGETAPI( "sysprocessgetcurrenthandle" ) 
	#define CAL_sysprocessgetcurrenthandle  sysprocessgetcurrenthandle
	#define CHK_sysprocessgetcurrenthandle  TRUE
	#define EXP_sysprocessgetcurrenthandle  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessgetcurrenthandle", (RTS_UINTPTR)sysprocessgetcurrenthandle, 1, RTSITF_GET_SIGNATURE(0, 0xF293D47C), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_sysprocessgetcurrenthandle  PFSYSPROCESSGETCURRENTHANDLE_IEC pfsysprocessgetcurrenthandle;
	#define EXT_sysprocessgetcurrenthandle  extern PFSYSPROCESSGETCURRENTHANDLE_IEC pfsysprocessgetcurrenthandle;
	#define GET_sysprocessgetcurrenthandle(fl)  s_pfCMGetAPI2( "sysprocessgetcurrenthandle", (RTS_VOID_FCTPTR *)&pfsysprocessgetcurrenthandle, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xF293D47C), 0x03051000)
	#define CAL_sysprocessgetcurrenthandle  pfsysprocessgetcurrenthandle
	#define CHK_sysprocessgetcurrenthandle  (pfsysprocessgetcurrenthandle != NULL)
	#define EXP_sysprocessgetcurrenthandle   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessgetcurrenthandle", (RTS_UINTPTR)sysprocessgetcurrenthandle, 1, RTSITF_GET_SIGNATURE(0, 0xF293D47C), 0x03051000) 
#endif


/**
 * <description>Function to determine an operating system dependent identification of a process. This 
 * identification must be unique in the system at a defined time! SysProcessGetOSId can only applied to 
 * the process actually executed or to processes having been generated by SysProcessCreate.</description>
 * <result><p>RESULT: Returns the operating system specific identification of the process</p></result>
 */
typedef struct tagsysprocessgetosid_struct
{
	RTS_IEC_HANDLE hProcess;			/* VAR_INPUT */	/* <param name="hProcess" type="IN">Handle of the process</param> */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* <param name="pResult" type="OUT">Pointer to runtime system error code (see CmpErrors.library)</param> */
	RTS_IEC_UDINT SysProcessGetOSId;	/* VAR_OUTPUT */	/* OSId */
} sysprocessgetosid_struct;

void CDECL CDECL_EXT sysprocessgetosid(sysprocessgetosid_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSPROCESSGETOSID_IEC) (sysprocessgetosid_struct *p);
#if defined(SYSPROCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSPROCESSGETOSID_NOTIMPLEMENTED)
	#define USE_sysprocessgetosid
	#define EXT_sysprocessgetosid
	#define GET_sysprocessgetosid(fl)  ERR_NOTIMPLEMENTED
	#define CAL_sysprocessgetosid(p0) 
	#define CHK_sysprocessgetosid  FALSE
	#define EXP_sysprocessgetosid  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_sysprocessgetosid
	#define EXT_sysprocessgetosid
	#define GET_sysprocessgetosid(fl)  CAL_CMGETAPI( "sysprocessgetosid" ) 
	#define CAL_sysprocessgetosid  sysprocessgetosid
	#define CHK_sysprocessgetosid  TRUE
	#define EXP_sysprocessgetosid  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessgetosid", (RTS_UINTPTR)sysprocessgetosid, 1, RTSITF_GET_SIGNATURE(0, 0x946F8470), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(SYSPROCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_sysprocessgetosid
	#define EXT_sysprocessgetosid
	#define GET_sysprocessgetosid(fl)  CAL_CMGETAPI( "sysprocessgetosid" ) 
	#define CAL_sysprocessgetosid  sysprocessgetosid
	#define CHK_sysprocessgetosid  TRUE
	#define EXP_sysprocessgetosid  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessgetosid", (RTS_UINTPTR)sysprocessgetosid, 1, RTSITF_GET_SIGNATURE(0, 0x946F8470), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysProcess_Implementationsysprocessgetosid
	#define EXT_SysProcess_Implementationsysprocessgetosid
	#define GET_SysProcess_Implementationsysprocessgetosid  ERR_OK
	#define CAL_SysProcess_Implementationsysprocessgetosid  sysprocessgetosid
	#define CHK_SysProcess_Implementationsysprocessgetosid  TRUE
	#define EXP_SysProcess_Implementationsysprocessgetosid  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessgetosid", (RTS_UINTPTR)sysprocessgetosid, 1, RTSITF_GET_SIGNATURE(0, 0x946F8470), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_sysprocessgetosid
	#define EXT_sysprocessgetosid
	#define GET_sysprocessgetosid(fl)  CAL_CMGETAPI( "sysprocessgetosid" ) 
	#define CAL_sysprocessgetosid  sysprocessgetosid
	#define CHK_sysprocessgetosid  TRUE
	#define EXP_sysprocessgetosid  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessgetosid", (RTS_UINTPTR)sysprocessgetosid, 1, RTSITF_GET_SIGNATURE(0, 0x946F8470), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_sysprocessgetosid  PFSYSPROCESSGETOSID_IEC pfsysprocessgetosid;
	#define EXT_sysprocessgetosid  extern PFSYSPROCESSGETOSID_IEC pfsysprocessgetosid;
	#define GET_sysprocessgetosid(fl)  s_pfCMGetAPI2( "sysprocessgetosid", (RTS_VOID_FCTPTR *)&pfsysprocessgetosid, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x946F8470), 0x03051000)
	#define CAL_sysprocessgetosid  pfsysprocessgetosid
	#define CHK_sysprocessgetosid  (pfsysprocessgetosid != NULL)
	#define EXP_sysprocessgetosid   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessgetosid", (RTS_UINTPTR)sysprocessgetosid, 1, RTSITF_GET_SIGNATURE(0, 0x946F8470), 0x03051000) 
#endif


/**
 * <description>This function retrieves the priority of the process specified by its handle.</description>
 * <result><p>RESULT: Returns the runtime system error code (see CmpErrors.library).</p></result>
 */
typedef struct tagsysprocessgetpriority_struct
{
	RTS_IEC_HANDLE hProcess;			/* VAR_INPUT */	/* <param name="hProcess" type="IN">Handle of the process</param> */
	RTS_IEC_UDINT *pulPriority;			/* VAR_INPUT */	/* <param name="pulPriority" type="OUT">Pointer to variable being assigned to priority of the process</param> */
	RTS_IEC_RESULT SysProcessGetPriority;	/* VAR_OUTPUT */	
} sysprocessgetpriority_struct;

void CDECL CDECL_EXT sysprocessgetpriority(sysprocessgetpriority_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSPROCESSGETPRIORITY_IEC) (sysprocessgetpriority_struct *p);
#if defined(SYSPROCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSPROCESSGETPRIORITY_NOTIMPLEMENTED)
	#define USE_sysprocessgetpriority
	#define EXT_sysprocessgetpriority
	#define GET_sysprocessgetpriority(fl)  ERR_NOTIMPLEMENTED
	#define CAL_sysprocessgetpriority(p0) 
	#define CHK_sysprocessgetpriority  FALSE
	#define EXP_sysprocessgetpriority  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_sysprocessgetpriority
	#define EXT_sysprocessgetpriority
	#define GET_sysprocessgetpriority(fl)  CAL_CMGETAPI( "sysprocessgetpriority" ) 
	#define CAL_sysprocessgetpriority  sysprocessgetpriority
	#define CHK_sysprocessgetpriority  TRUE
	#define EXP_sysprocessgetpriority  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessgetpriority", (RTS_UINTPTR)sysprocessgetpriority, 1, RTSITF_GET_SIGNATURE(0, 0xCEA416D5), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(SYSPROCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_sysprocessgetpriority
	#define EXT_sysprocessgetpriority
	#define GET_sysprocessgetpriority(fl)  CAL_CMGETAPI( "sysprocessgetpriority" ) 
	#define CAL_sysprocessgetpriority  sysprocessgetpriority
	#define CHK_sysprocessgetpriority  TRUE
	#define EXP_sysprocessgetpriority  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessgetpriority", (RTS_UINTPTR)sysprocessgetpriority, 1, RTSITF_GET_SIGNATURE(0, 0xCEA416D5), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysProcess_Implementationsysprocessgetpriority
	#define EXT_SysProcess_Implementationsysprocessgetpriority
	#define GET_SysProcess_Implementationsysprocessgetpriority  ERR_OK
	#define CAL_SysProcess_Implementationsysprocessgetpriority  sysprocessgetpriority
	#define CHK_SysProcess_Implementationsysprocessgetpriority  TRUE
	#define EXP_SysProcess_Implementationsysprocessgetpriority  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessgetpriority", (RTS_UINTPTR)sysprocessgetpriority, 1, RTSITF_GET_SIGNATURE(0, 0xCEA416D5), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_sysprocessgetpriority
	#define EXT_sysprocessgetpriority
	#define GET_sysprocessgetpriority(fl)  CAL_CMGETAPI( "sysprocessgetpriority" ) 
	#define CAL_sysprocessgetpriority  sysprocessgetpriority
	#define CHK_sysprocessgetpriority  TRUE
	#define EXP_sysprocessgetpriority  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessgetpriority", (RTS_UINTPTR)sysprocessgetpriority, 1, RTSITF_GET_SIGNATURE(0, 0xCEA416D5), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_sysprocessgetpriority  PFSYSPROCESSGETPRIORITY_IEC pfsysprocessgetpriority;
	#define EXT_sysprocessgetpriority  extern PFSYSPROCESSGETPRIORITY_IEC pfsysprocessgetpriority;
	#define GET_sysprocessgetpriority(fl)  s_pfCMGetAPI2( "sysprocessgetpriority", (RTS_VOID_FCTPTR *)&pfsysprocessgetpriority, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xCEA416D5), 0x03051000)
	#define CAL_sysprocessgetpriority  pfsysprocessgetpriority
	#define CHK_sysprocessgetpriority  (pfsysprocessgetpriority != NULL)
	#define EXP_sysprocessgetpriority   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessgetpriority", (RTS_UINTPTR)sysprocessgetpriority, 1, RTSITF_GET_SIGNATURE(0, 0xCEA416D5), 0x03051000) 
#endif


/**
 * <description>This function retrieves the status of the process specified by its handle.</description>
 * <result><p>RESULT: Returns the runtime system error code (see CmpErrors.library).</p></result>
 */
typedef struct tagsysprocessgetstate_struct
{
	RTS_IEC_HANDLE hProcess;			/* VAR_INPUT */	/* <param name="hProcess" type="IN">Handle of the process</param> */
	RTS_IEC_UDINT *pulState;			/* VAR_INPUT */	/* <param name="pulState" type="OUT">Pointer to variable being assigned to value 1 for running processes and value 2 for terminated processes</param> */
	RTS_IEC_RESULT SysProcessGetState;	/* VAR_OUTPUT */	
} sysprocessgetstate_struct;

void CDECL CDECL_EXT sysprocessgetstate(sysprocessgetstate_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSPROCESSGETSTATE_IEC) (sysprocessgetstate_struct *p);
#if defined(SYSPROCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSPROCESSGETSTATE_NOTIMPLEMENTED)
	#define USE_sysprocessgetstate
	#define EXT_sysprocessgetstate
	#define GET_sysprocessgetstate(fl)  ERR_NOTIMPLEMENTED
	#define CAL_sysprocessgetstate(p0) 
	#define CHK_sysprocessgetstate  FALSE
	#define EXP_sysprocessgetstate  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_sysprocessgetstate
	#define EXT_sysprocessgetstate
	#define GET_sysprocessgetstate(fl)  CAL_CMGETAPI( "sysprocessgetstate" ) 
	#define CAL_sysprocessgetstate  sysprocessgetstate
	#define CHK_sysprocessgetstate  TRUE
	#define EXP_sysprocessgetstate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessgetstate", (RTS_UINTPTR)sysprocessgetstate, 1, RTSITF_GET_SIGNATURE(0, 0xB65EA319), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(SYSPROCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_sysprocessgetstate
	#define EXT_sysprocessgetstate
	#define GET_sysprocessgetstate(fl)  CAL_CMGETAPI( "sysprocessgetstate" ) 
	#define CAL_sysprocessgetstate  sysprocessgetstate
	#define CHK_sysprocessgetstate  TRUE
	#define EXP_sysprocessgetstate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessgetstate", (RTS_UINTPTR)sysprocessgetstate, 1, RTSITF_GET_SIGNATURE(0, 0xB65EA319), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysProcess_Implementationsysprocessgetstate
	#define EXT_SysProcess_Implementationsysprocessgetstate
	#define GET_SysProcess_Implementationsysprocessgetstate  ERR_OK
	#define CAL_SysProcess_Implementationsysprocessgetstate  sysprocessgetstate
	#define CHK_SysProcess_Implementationsysprocessgetstate  TRUE
	#define EXP_SysProcess_Implementationsysprocessgetstate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessgetstate", (RTS_UINTPTR)sysprocessgetstate, 1, RTSITF_GET_SIGNATURE(0, 0xB65EA319), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_sysprocessgetstate
	#define EXT_sysprocessgetstate
	#define GET_sysprocessgetstate(fl)  CAL_CMGETAPI( "sysprocessgetstate" ) 
	#define CAL_sysprocessgetstate  sysprocessgetstate
	#define CHK_sysprocessgetstate  TRUE
	#define EXP_sysprocessgetstate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessgetstate", (RTS_UINTPTR)sysprocessgetstate, 1, RTSITF_GET_SIGNATURE(0, 0xB65EA319), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_sysprocessgetstate  PFSYSPROCESSGETSTATE_IEC pfsysprocessgetstate;
	#define EXT_sysprocessgetstate  extern PFSYSPROCESSGETSTATE_IEC pfsysprocessgetstate;
	#define GET_sysprocessgetstate(fl)  s_pfCMGetAPI2( "sysprocessgetstate", (RTS_VOID_FCTPTR *)&pfsysprocessgetstate, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xB65EA319), 0x03051000)
	#define CAL_sysprocessgetstate  pfsysprocessgetstate
	#define CHK_sysprocessgetstate  (pfsysprocessgetstate != NULL)
	#define EXP_sysprocessgetstate   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessgetstate", (RTS_UINTPTR)sysprocessgetstate, 1, RTSITF_GET_SIGNATURE(0, 0xB65EA319), 0x03051000) 
#endif


/**
 * <description>This function starts the process specified by its handle. For example, the function can be used for
 * processes having been created in suspended mode by use of the flag SYSPROCESS_CREATEFLAG_CREATESUSPENDED.</description>
 * <result><p>RESULT: Returns the runtime system error code (see CmpErrors.library).</p></result>
 */
typedef struct tagsysprocessresume_struct
{
	RTS_IEC_HANDLE hProcess;			/* VAR_INPUT */	/* <param name="hProcess" type="IN">Handle of the process</param> */
	RTS_IEC_RESULT SysProcessResume;	/* VAR_OUTPUT */	
} sysprocessresume_struct;

void CDECL CDECL_EXT sysprocessresume(sysprocessresume_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSPROCESSRESUME_IEC) (sysprocessresume_struct *p);
#if defined(SYSPROCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSPROCESSRESUME_NOTIMPLEMENTED)
	#define USE_sysprocessresume
	#define EXT_sysprocessresume
	#define GET_sysprocessresume(fl)  ERR_NOTIMPLEMENTED
	#define CAL_sysprocessresume(p0) 
	#define CHK_sysprocessresume  FALSE
	#define EXP_sysprocessresume  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_sysprocessresume
	#define EXT_sysprocessresume
	#define GET_sysprocessresume(fl)  CAL_CMGETAPI( "sysprocessresume" ) 
	#define CAL_sysprocessresume  sysprocessresume
	#define CHK_sysprocessresume  TRUE
	#define EXP_sysprocessresume  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessresume", (RTS_UINTPTR)sysprocessresume, 1, RTSITF_GET_SIGNATURE(0, 0x1587F094), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(SYSPROCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_sysprocessresume
	#define EXT_sysprocessresume
	#define GET_sysprocessresume(fl)  CAL_CMGETAPI( "sysprocessresume" ) 
	#define CAL_sysprocessresume  sysprocessresume
	#define CHK_sysprocessresume  TRUE
	#define EXP_sysprocessresume  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessresume", (RTS_UINTPTR)sysprocessresume, 1, RTSITF_GET_SIGNATURE(0, 0x1587F094), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysProcess_Implementationsysprocessresume
	#define EXT_SysProcess_Implementationsysprocessresume
	#define GET_SysProcess_Implementationsysprocessresume  ERR_OK
	#define CAL_SysProcess_Implementationsysprocessresume  sysprocessresume
	#define CHK_SysProcess_Implementationsysprocessresume  TRUE
	#define EXP_SysProcess_Implementationsysprocessresume  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessresume", (RTS_UINTPTR)sysprocessresume, 1, RTSITF_GET_SIGNATURE(0, 0x1587F094), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_sysprocessresume
	#define EXT_sysprocessresume
	#define GET_sysprocessresume(fl)  CAL_CMGETAPI( "sysprocessresume" ) 
	#define CAL_sysprocessresume  sysprocessresume
	#define CHK_sysprocessresume  TRUE
	#define EXP_sysprocessresume  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessresume", (RTS_UINTPTR)sysprocessresume, 1, RTSITF_GET_SIGNATURE(0, 0x1587F094), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_sysprocessresume  PFSYSPROCESSRESUME_IEC pfsysprocessresume;
	#define EXT_sysprocessresume  extern PFSYSPROCESSRESUME_IEC pfsysprocessresume;
	#define GET_sysprocessresume(fl)  s_pfCMGetAPI2( "sysprocessresume", (RTS_VOID_FCTPTR *)&pfsysprocessresume, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x1587F094), 0x03051000)
	#define CAL_sysprocessresume  pfsysprocessresume
	#define CHK_sysprocessresume  (pfsysprocessresume != NULL)
	#define EXP_sysprocessresume   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessresume", (RTS_UINTPTR)sysprocessresume, 1, RTSITF_GET_SIGNATURE(0, 0x1587F094), 0x03051000) 
#endif


/**
 * <description>This function sets the priority of the process specified by its handle.</description>
 * <result><p>RESULT: Returns the runtime system error code (see CmpErrors.library).</p></result>
 */
typedef struct tagsysprocesssetpriority_struct
{
	RTS_IEC_HANDLE hProcess;			/* VAR_INPUT */	/* <param name="hProcess" type="IN">Handle of the process</param> */
	RTS_IEC_UDINT ulPriority;			/* VAR_INPUT */	/* <param name="ulPriority" type="IN">Process priority</param> */
	RTS_IEC_RESULT SysProcessSetPriority;	/* VAR_OUTPUT */	
} sysprocesssetpriority_struct;

void CDECL CDECL_EXT sysprocesssetpriority(sysprocesssetpriority_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSPROCESSSETPRIORITY_IEC) (sysprocesssetpriority_struct *p);
#if defined(SYSPROCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSPROCESSSETPRIORITY_NOTIMPLEMENTED)
	#define USE_sysprocesssetpriority
	#define EXT_sysprocesssetpriority
	#define GET_sysprocesssetpriority(fl)  ERR_NOTIMPLEMENTED
	#define CAL_sysprocesssetpriority(p0) 
	#define CHK_sysprocesssetpriority  FALSE
	#define EXP_sysprocesssetpriority  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_sysprocesssetpriority
	#define EXT_sysprocesssetpriority
	#define GET_sysprocesssetpriority(fl)  CAL_CMGETAPI( "sysprocesssetpriority" ) 
	#define CAL_sysprocesssetpriority  sysprocesssetpriority
	#define CHK_sysprocesssetpriority  TRUE
	#define EXP_sysprocesssetpriority  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocesssetpriority", (RTS_UINTPTR)sysprocesssetpriority, 1, RTSITF_GET_SIGNATURE(0, 0xCB07213F), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(SYSPROCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_sysprocesssetpriority
	#define EXT_sysprocesssetpriority
	#define GET_sysprocesssetpriority(fl)  CAL_CMGETAPI( "sysprocesssetpriority" ) 
	#define CAL_sysprocesssetpriority  sysprocesssetpriority
	#define CHK_sysprocesssetpriority  TRUE
	#define EXP_sysprocesssetpriority  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocesssetpriority", (RTS_UINTPTR)sysprocesssetpriority, 1, RTSITF_GET_SIGNATURE(0, 0xCB07213F), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysProcess_Implementationsysprocesssetpriority
	#define EXT_SysProcess_Implementationsysprocesssetpriority
	#define GET_SysProcess_Implementationsysprocesssetpriority  ERR_OK
	#define CAL_SysProcess_Implementationsysprocesssetpriority  sysprocesssetpriority
	#define CHK_SysProcess_Implementationsysprocesssetpriority  TRUE
	#define EXP_SysProcess_Implementationsysprocesssetpriority  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocesssetpriority", (RTS_UINTPTR)sysprocesssetpriority, 1, RTSITF_GET_SIGNATURE(0, 0xCB07213F), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_sysprocesssetpriority
	#define EXT_sysprocesssetpriority
	#define GET_sysprocesssetpriority(fl)  CAL_CMGETAPI( "sysprocesssetpriority" ) 
	#define CAL_sysprocesssetpriority  sysprocesssetpriority
	#define CHK_sysprocesssetpriority  TRUE
	#define EXP_sysprocesssetpriority  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocesssetpriority", (RTS_UINTPTR)sysprocesssetpriority, 1, RTSITF_GET_SIGNATURE(0, 0xCB07213F), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_sysprocesssetpriority  PFSYSPROCESSSETPRIORITY_IEC pfsysprocesssetpriority;
	#define EXT_sysprocesssetpriority  extern PFSYSPROCESSSETPRIORITY_IEC pfsysprocesssetpriority;
	#define GET_sysprocesssetpriority(fl)  s_pfCMGetAPI2( "sysprocesssetpriority", (RTS_VOID_FCTPTR *)&pfsysprocesssetpriority, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xCB07213F), 0x03051000)
	#define CAL_sysprocesssetpriority  pfsysprocesssetpriority
	#define CHK_sysprocesssetpriority  (pfsysprocesssetpriority != NULL)
	#define EXP_sysprocesssetpriority   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocesssetpriority", (RTS_UINTPTR)sysprocesssetpriority, 1, RTSITF_GET_SIGNATURE(0, 0xCB07213F), 0x03051000) 
#endif


/**
 * <description>This function terminates the process specified by its handle.</description>
 * <result><p>RESULT: Returns the runtime system error code (see CmpErrors.library).</p></result>
 */
typedef struct tagsysprocessterminate_struct
{
	RTS_IEC_HANDLE hProcess;			/* VAR_INPUT */	/* <param name="hProcess" type="IN">Handle of the process</param> */
	RTS_IEC_RESULT SysProcessTerminate;	/* VAR_OUTPUT */	
} sysprocessterminate_struct;

void CDECL CDECL_EXT sysprocessterminate(sysprocessterminate_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSPROCESSTERMINATE_IEC) (sysprocessterminate_struct *p);
#if defined(SYSPROCESS_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSPROCESSTERMINATE_NOTIMPLEMENTED)
	#define USE_sysprocessterminate
	#define EXT_sysprocessterminate
	#define GET_sysprocessterminate(fl)  ERR_NOTIMPLEMENTED
	#define CAL_sysprocessterminate(p0) 
	#define CHK_sysprocessterminate  FALSE
	#define EXP_sysprocessterminate  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_sysprocessterminate
	#define EXT_sysprocessterminate
	#define GET_sysprocessterminate(fl)  CAL_CMGETAPI( "sysprocessterminate" ) 
	#define CAL_sysprocessterminate  sysprocessterminate
	#define CHK_sysprocessterminate  TRUE
	#define EXP_sysprocessterminate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessterminate", (RTS_UINTPTR)sysprocessterminate, 1, RTSITF_GET_SIGNATURE(0, 0x498BEF7C), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(SYSPROCESS_IMPLEMENTATION_EXTERNAL)
	#define USE_sysprocessterminate
	#define EXT_sysprocessterminate
	#define GET_sysprocessterminate(fl)  CAL_CMGETAPI( "sysprocessterminate" ) 
	#define CAL_sysprocessterminate  sysprocessterminate
	#define CHK_sysprocessterminate  TRUE
	#define EXP_sysprocessterminate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessterminate", (RTS_UINTPTR)sysprocessterminate, 1, RTSITF_GET_SIGNATURE(0, 0x498BEF7C), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysProcess_Implementationsysprocessterminate
	#define EXT_SysProcess_Implementationsysprocessterminate
	#define GET_SysProcess_Implementationsysprocessterminate  ERR_OK
	#define CAL_SysProcess_Implementationsysprocessterminate  sysprocessterminate
	#define CHK_SysProcess_Implementationsysprocessterminate  TRUE
	#define EXP_SysProcess_Implementationsysprocessterminate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessterminate", (RTS_UINTPTR)sysprocessterminate, 1, RTSITF_GET_SIGNATURE(0, 0x498BEF7C), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_sysprocessterminate
	#define EXT_sysprocessterminate
	#define GET_sysprocessterminate(fl)  CAL_CMGETAPI( "sysprocessterminate" ) 
	#define CAL_sysprocessterminate  sysprocessterminate
	#define CHK_sysprocessterminate  TRUE
	#define EXP_sysprocessterminate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessterminate", (RTS_UINTPTR)sysprocessterminate, 1, RTSITF_GET_SIGNATURE(0, 0x498BEF7C), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_sysprocessterminate  PFSYSPROCESSTERMINATE_IEC pfsysprocessterminate;
	#define EXT_sysprocessterminate  extern PFSYSPROCESSTERMINATE_IEC pfsysprocessterminate;
	#define GET_sysprocessterminate(fl)  s_pfCMGetAPI2( "sysprocessterminate", (RTS_VOID_FCTPTR *)&pfsysprocessterminate, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x498BEF7C), 0x03051000)
	#define CAL_sysprocessterminate  pfsysprocessterminate
	#define CHK_sysprocessterminate  (pfsysprocessterminate != NULL)
	#define EXP_sysprocessterminate   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"sysprocessterminate", (RTS_UINTPTR)sysprocessterminate, 1, RTSITF_GET_SIGNATURE(0, 0x498BEF7C), 0x03051000) 
#endif


#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/




typedef struct
{
	IBase_C *pBase;
} ISysProcess_Implementation_C;

#ifdef CPLUSPLUS
class ISysProcess_Implementation : public IBase
{
	public:
};
	#ifndef ITF_SysProcess_Implementation
		#define ITF_SysProcess_Implementation static ISysProcess_Implementation *pISysProcess_Implementation = NULL;
	#endif
	#define EXTITF_SysProcess_Implementation
#else	/*CPLUSPLUS*/
	typedef ISysProcess_Implementation_C		ISysProcess_Implementation;
	#ifndef ITF_SysProcess_Implementation
		#define ITF_SysProcess_Implementation
	#endif
	#define EXTITF_SysProcess_Implementation
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_SYSPROCESS_IMPLEMENTATIONITF_H_*/
