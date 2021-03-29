 /**
 * <interfacename>SysProcess</interfacename>
 * <description> 
 *	<p>The SysProcess interface is projected to handle operating system processes. This
 *	can be implemented only on targets with an operating system with processes.</p>
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */


	
	
#ifndef _SYSPROCESSITF_H_
#define _SYSPROCESSITF_H_

#include "CmpStd.h"

 

 




#include "CmpItf.h"

/**
 * <category>Priority ranges</category>
 * <description>
 *	Process priorities can be set between 0..255.
 *	The priorities are mapped to real operating system priorities at least with the specified task segments.
 * </description>
 */
#define PROCESSPRIO_RANGE				255
#define PROCESSPRIO_SEGMENT				32

#define PROCESSPRIO_MAX					0

/* PROCESS segment 1 */
#define PROCESSPRIO_SYSTEM_BASE			0
#define PROCESSPRIO_SYSTEM_END			31

/* PROCESS segment 2 */
#define PROCESSPRIO_REALTIME_BASE		32
#define PROCESSPRIO_REALTIME_END		63

/* PROCESS segment 3 */
#define PROCESSPRIO_HIGH_BASE			64
#define PROCESSPRIO_HIGH_END			95

/* PROCESS segment 4 */
#define PROCESSPRIO_ABOVENORMAL_BASE	96
#define PROCESSPRIO_ABOVENORMAL_END		127

/* PROCESS segment 5 */
#define PROCESSPRIO_NORMAL_BASE			128
#define PROCESSPRIO_NORMAL_END			159

/* PROCESS segment 6 */
#define PROCESSPRIO_BELOWNORMAL_BASE	160
#define PROCESSPRIO_BELOWNORMAL_END		191

/* PROCESS segment 7 */
#define PROCESSPRIO_LOW_BASE			192
#define PROCESSPRIO_LOW_END				223

/* PROCESS segment 8 */
#define PROCESSPRIO_LOWEST_BASE			224
#define PROCESSPRIO_LOWEST_END			255

#define PROCESSPRIO_IDLE				255
#define PROCESSPRIO_MIN					255

/**
 * <category>Process status</category>
 * <description>Actual status of a process</description>
 */
#define PROCESS_STATUS_RUNNING			1
#define PROCESS_STATUS_TERMINATED		2

/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>Setting to get process priority. STRING type</description>
 */
#define KEY_STRING_BASEPRIORITY							"BasePriority"
#define VALUE_STRING_BASEPRIORITY_REALTIME				"Realtime"
#define VALUE_STRING_BASEPRIORITY_HIGH					"High"
#define VALUE_STRING_BASEPRIORITY_NORMAL				"Normal"
#define VALUE_STRING_BASEPRIORITY_LOW					"Low"
#ifndef VALUE_STRING_BASEPRIORITY_DEFAULT
	#define VALUE_STRING_BASEPRIORITY_DEFAULT			""
#endif

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>Setting to get process priority. INT type</description>
 */
#define KEY_INT_PROCESSORID						"ProcessorId"
#define KEY_INT_PROCESSORID_DEFAULT				1

/**
 * <category>Settings</category>
 * <type>String</type>
 * <description><p>Setting to define the allowed commands for SysExecuteCommand by a white list. 
 *	Several commands must be entered indexed, e.g.:</p>
 *	<p>Command.0=./dothis</p>
 *	<p>Command.1=./dothat</p>
 *	<p>If nothing is configured, SysExecuteCommand will always fail.</p>
 *	<p>In addition to that, it is also possible to ignore the above white list and allow all commands by:</p>
 *	<p>Command=AllowAll/p>
 *	<p>ATTENTION: If Command=AllowAll is set, there is no further verification done, before a command is executed. Please
 *	check your security requirements carefully before activating this. For the same reason you should also choose the 
 *	allowed commands in the list accurately. c</p>
 * </description>
 */
#define SYSPROCESS_KEY_STRING_COMMAND					"Command"
#ifndef SYSPROCESS_KEY_STRING_COMMAND_DEFAULT
	#define SYSPROCESS_KEY_STRING_COMMAND_DEFAULT		""
#endif
#define SYSPROCESS_KEY_STRING_COMMAND_ALLOW_ALL			"AllowAll"

/**
 * <category>Process creation flags</category>
 * <description>A combination of these flags can specify the startup of a process</description>
 * <element name="PROCESS_CREATEFLAG_HIDDEN" type="IN">Flag to create a hidden process</element>
 * <element name="PROCESS_CREATEFLAG_INTERACTIVE" type="IN">Flag to create an interactive process requiring input from the user</element>
 * <element name="PROCESS_CREATEFLAG_CREATESUSPENDED" type="IN">Flag to create a suspended process</element>
 * 
 */
#define PROCESS_CREATEFLAG_HIDDEN				1
#define PROCESS_CREATEFLAG_INTERACTIVE			2
#define PROCESS_CREATEFLAG_CREATESUSPENDED		4


/** EXTERN LIB SECTION BEGIN **/
/*  Comments are ignored for m4 compiler so restructured text can be used.  */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/


#ifdef __cplusplus
extern "C" {
#endif

/* Initialization routines for OS specific modules */
RTS_RESULT CDECL SysProcessOSInit(INIT_STRUCT *pInit);
RTS_RESULT CDECL SysProcessOSHookFunction(RTS_UI32 ulHook, RTS_UINTPTR ulParam1, RTS_UINTPTR ulParam2);

/**
 * <description> Function to start a system command. The command is operating system dependent! </description>
 * <param name="pszCommand" type="IN">String with the command line</param>
 * <result>Result after command execution</result>
 */
RTS_I32 CDECL SysProcessExecuteCommand(char *pszCommand, RTS_RESULT *pResult);
typedef RTS_I32 (CDECL * PFSYSPROCESSEXECUTECOMMAND) (char *pszCommand, RTS_RESULT *pResult);
#if defined(SYSPROCESS_NOTIMPLEMENTED) || defined(SYSPROCESSEXECUTECOMMAND_NOTIMPLEMENTED)
	#define USE_SysProcessExecuteCommand
	#define EXT_SysProcessExecuteCommand
	#define GET_SysProcessExecuteCommand(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysProcessExecuteCommand(p0,p1)  (RTS_I32)ERR_NOTIMPLEMENTED
	#define CHK_SysProcessExecuteCommand  FALSE
	#define EXP_SysProcessExecuteCommand  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysProcessExecuteCommand
	#define EXT_SysProcessExecuteCommand
	#define GET_SysProcessExecuteCommand(fl)  CAL_CMGETAPI( "SysProcessExecuteCommand" ) 
	#define CAL_SysProcessExecuteCommand  SysProcessExecuteCommand
	#define CHK_SysProcessExecuteCommand  TRUE
	#define EXP_SysProcessExecuteCommand  CAL_CMEXPAPI( "SysProcessExecuteCommand" ) 
#elif defined(MIXED_LINK) && !defined(SYSPROCESS_EXTERNAL)
	#define USE_SysProcessExecuteCommand
	#define EXT_SysProcessExecuteCommand
	#define GET_SysProcessExecuteCommand(fl)  CAL_CMGETAPI( "SysProcessExecuteCommand" ) 
	#define CAL_SysProcessExecuteCommand  SysProcessExecuteCommand
	#define CHK_SysProcessExecuteCommand  TRUE
	#define EXP_SysProcessExecuteCommand  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysProcessExecuteCommand", (RTS_UINTPTR)SysProcessExecuteCommand, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysProcessSysProcessExecuteCommand
	#define EXT_SysProcessSysProcessExecuteCommand
	#define GET_SysProcessSysProcessExecuteCommand  ERR_OK
	#define CAL_SysProcessSysProcessExecuteCommand pISysProcess->ISysProcessExecuteCommand
	#define CHK_SysProcessSysProcessExecuteCommand (pISysProcess != NULL)
	#define EXP_SysProcessSysProcessExecuteCommand  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysProcessExecuteCommand
	#define EXT_SysProcessExecuteCommand
	#define GET_SysProcessExecuteCommand(fl)  CAL_CMGETAPI( "SysProcessExecuteCommand" ) 
	#define CAL_SysProcessExecuteCommand pISysProcess->ISysProcessExecuteCommand
	#define CHK_SysProcessExecuteCommand (pISysProcess != NULL)
	#define EXP_SysProcessExecuteCommand  CAL_CMEXPAPI( "SysProcessExecuteCommand" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysProcessExecuteCommand  PFSYSPROCESSEXECUTECOMMAND pfSysProcessExecuteCommand;
	#define EXT_SysProcessExecuteCommand  extern PFSYSPROCESSEXECUTECOMMAND pfSysProcessExecuteCommand;
	#define GET_SysProcessExecuteCommand(fl)  s_pfCMGetAPI2( "SysProcessExecuteCommand", (RTS_VOID_FCTPTR *)&pfSysProcessExecuteCommand, (fl), 0, 0)
	#define CAL_SysProcessExecuteCommand  pfSysProcessExecuteCommand
	#define CHK_SysProcessExecuteCommand  (pfSysProcessExecuteCommand != NULL)
	#define EXP_SysProcessExecuteCommand  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysProcessExecuteCommand", (RTS_UINTPTR)SysProcessExecuteCommand, 0, 0) 
#endif




/**
 * <description> Function to start a system command. The command is operating system dependent! 
 *	If Pointer to buffer is not null for StdOut or StdErr the buffer will be filled.</description>
 * <param name="pszCommand" type="IN">String with the command line</param> 
 * <param name="pszStdOut" type="IN">Buffer for StdOut string</param>
 * <param name="udiStdOutLen" type="IN">Buffer size for StdOut string buffer</param>
 * <param name="pResult" type="OUT">Pointer to runtime system error code (see CmpErrors.library)</param>
 */
RTS_I32 CDECL SysProcessExecuteCommand2(char *pszCommand, char* pszStdOut, RTS_UI32 udiStdOutLen, RTS_RESULT *pResult);
typedef RTS_I32 (CDECL * PFSYSPROCESSEXECUTECOMMAND2) (char *pszCommand, char* pszStdOut, RTS_UI32 udiStdOutLen, RTS_RESULT *pResult);
#if defined(SYSPROCESS_NOTIMPLEMENTED) || defined(SYSPROCESSEXECUTECOMMAND2_NOTIMPLEMENTED)
	#define USE_SysProcessExecuteCommand2
	#define EXT_SysProcessExecuteCommand2
	#define GET_SysProcessExecuteCommand2(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysProcessExecuteCommand2(p0,p1,p2,p3)  (RTS_I32)ERR_NOTIMPLEMENTED
	#define CHK_SysProcessExecuteCommand2  FALSE
	#define EXP_SysProcessExecuteCommand2  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysProcessExecuteCommand2
	#define EXT_SysProcessExecuteCommand2
	#define GET_SysProcessExecuteCommand2(fl)  CAL_CMGETAPI( "SysProcessExecuteCommand2" ) 
	#define CAL_SysProcessExecuteCommand2  SysProcessExecuteCommand2
	#define CHK_SysProcessExecuteCommand2  TRUE
	#define EXP_SysProcessExecuteCommand2  CAL_CMEXPAPI( "SysProcessExecuteCommand2" ) 
#elif defined(MIXED_LINK) && !defined(SYSPROCESS_EXTERNAL)
	#define USE_SysProcessExecuteCommand2
	#define EXT_SysProcessExecuteCommand2
	#define GET_SysProcessExecuteCommand2(fl)  CAL_CMGETAPI( "SysProcessExecuteCommand2" ) 
	#define CAL_SysProcessExecuteCommand2  SysProcessExecuteCommand2
	#define CHK_SysProcessExecuteCommand2  TRUE
	#define EXP_SysProcessExecuteCommand2  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysProcessExecuteCommand2", (RTS_UINTPTR)SysProcessExecuteCommand2, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysProcessSysProcessExecuteCommand2
	#define EXT_SysProcessSysProcessExecuteCommand2
	#define GET_SysProcessSysProcessExecuteCommand2  ERR_OK
	#define CAL_SysProcessSysProcessExecuteCommand2 pISysProcess->ISysProcessExecuteCommand2
	#define CHK_SysProcessSysProcessExecuteCommand2 (pISysProcess != NULL)
	#define EXP_SysProcessSysProcessExecuteCommand2  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysProcessExecuteCommand2
	#define EXT_SysProcessExecuteCommand2
	#define GET_SysProcessExecuteCommand2(fl)  CAL_CMGETAPI( "SysProcessExecuteCommand2" ) 
	#define CAL_SysProcessExecuteCommand2 pISysProcess->ISysProcessExecuteCommand2
	#define CHK_SysProcessExecuteCommand2 (pISysProcess != NULL)
	#define EXP_SysProcessExecuteCommand2  CAL_CMEXPAPI( "SysProcessExecuteCommand2" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysProcessExecuteCommand2  PFSYSPROCESSEXECUTECOMMAND2 pfSysProcessExecuteCommand2;
	#define EXT_SysProcessExecuteCommand2  extern PFSYSPROCESSEXECUTECOMMAND2 pfSysProcessExecuteCommand2;
	#define GET_SysProcessExecuteCommand2(fl)  s_pfCMGetAPI2( "SysProcessExecuteCommand2", (RTS_VOID_FCTPTR *)&pfSysProcessExecuteCommand2, (fl), 0, 0)
	#define CAL_SysProcessExecuteCommand2  pfSysProcessExecuteCommand2
	#define CHK_SysProcessExecuteCommand2  (pfSysProcessExecuteCommand2 != NULL)
	#define EXP_SysProcessExecuteCommand2  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysProcessExecuteCommand2", (RTS_UINTPTR)SysProcessExecuteCommand2, 0, 0) 
#endif





/**
 * <description> Function to create a process. Is only valid on systems with processes! </description>
 * <param name="pszApplication" type="IN">Name of application to start as a separate process</param>
 * <param name="pszCommandLine" type="IN">String with the command line</param>
 * <param name="ulFlags" type="IN">A combination of flags like PROCESS_CREATEFLAG_HIDDEN for example.</param>
 * <param name="pResult" type="OUT">Pointer to the result</param>
 * <result>Handle to the process</result>
 */
RTS_HANDLE CDECL SysProcessCreate(char *pszApplication, char *pszCommandLine, RTS_UI32 ulFlags, RTS_RESULT *pResult);
typedef RTS_HANDLE (CDECL * PFSYSPROCESSCREATE) (char *pszApplication, char *pszCommandLine, RTS_UI32 ulFlags, RTS_RESULT *pResult);
#if defined(SYSPROCESS_NOTIMPLEMENTED) || defined(SYSPROCESSCREATE_NOTIMPLEMENTED)
	#define USE_SysProcessCreate
	#define EXT_SysProcessCreate
	#define GET_SysProcessCreate(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysProcessCreate(p0,p1,p2,p3)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_SysProcessCreate  FALSE
	#define EXP_SysProcessCreate  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysProcessCreate
	#define EXT_SysProcessCreate
	#define GET_SysProcessCreate(fl)  CAL_CMGETAPI( "SysProcessCreate" ) 
	#define CAL_SysProcessCreate  SysProcessCreate
	#define CHK_SysProcessCreate  TRUE
	#define EXP_SysProcessCreate  CAL_CMEXPAPI( "SysProcessCreate" ) 
#elif defined(MIXED_LINK) && !defined(SYSPROCESS_EXTERNAL)
	#define USE_SysProcessCreate
	#define EXT_SysProcessCreate
	#define GET_SysProcessCreate(fl)  CAL_CMGETAPI( "SysProcessCreate" ) 
	#define CAL_SysProcessCreate  SysProcessCreate
	#define CHK_SysProcessCreate  TRUE
	#define EXP_SysProcessCreate  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysProcessCreate", (RTS_UINTPTR)SysProcessCreate, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysProcessSysProcessCreate
	#define EXT_SysProcessSysProcessCreate
	#define GET_SysProcessSysProcessCreate  ERR_OK
	#define CAL_SysProcessSysProcessCreate pISysProcess->ISysProcessCreate
	#define CHK_SysProcessSysProcessCreate (pISysProcess != NULL)
	#define EXP_SysProcessSysProcessCreate  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysProcessCreate
	#define EXT_SysProcessCreate
	#define GET_SysProcessCreate(fl)  CAL_CMGETAPI( "SysProcessCreate" ) 
	#define CAL_SysProcessCreate pISysProcess->ISysProcessCreate
	#define CHK_SysProcessCreate (pISysProcess != NULL)
	#define EXP_SysProcessCreate  CAL_CMEXPAPI( "SysProcessCreate" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysProcessCreate  PFSYSPROCESSCREATE pfSysProcessCreate;
	#define EXT_SysProcessCreate  extern PFSYSPROCESSCREATE pfSysProcessCreate;
	#define GET_SysProcessCreate(fl)  s_pfCMGetAPI2( "SysProcessCreate", (RTS_VOID_FCTPTR *)&pfSysProcessCreate, (fl), 0, 0)
	#define CAL_SysProcessCreate  pfSysProcessCreate
	#define CHK_SysProcessCreate  (pfSysProcessCreate != NULL)
	#define EXP_SysProcessCreate  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysProcessCreate", (RTS_UINTPTR)SysProcessCreate, 0, 0) 
#endif




/**
 * <description> Function to resume a process specified by handle. This can be used, if a process is created with PROCESS_CREATEFLAG_CREATESUSPENDED flag.</description>
 * <param name="hProcess" type="IN">Handle to the process</param>
 * <result>Error code: ERR_OK or ERR_FAILED</result>
 */
RTS_RESULT CDECL SysProcessResume(RTS_HANDLE hProcess);
typedef RTS_RESULT (CDECL * PFSYSPROCESSRESUME) (RTS_HANDLE hProcess);
#if defined(SYSPROCESS_NOTIMPLEMENTED) || defined(SYSPROCESSRESUME_NOTIMPLEMENTED)
	#define USE_SysProcessResume
	#define EXT_SysProcessResume
	#define GET_SysProcessResume(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysProcessResume(p0)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_SysProcessResume  FALSE
	#define EXP_SysProcessResume  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysProcessResume
	#define EXT_SysProcessResume
	#define GET_SysProcessResume(fl)  CAL_CMGETAPI( "SysProcessResume" ) 
	#define CAL_SysProcessResume  SysProcessResume
	#define CHK_SysProcessResume  TRUE
	#define EXP_SysProcessResume  CAL_CMEXPAPI( "SysProcessResume" ) 
#elif defined(MIXED_LINK) && !defined(SYSPROCESS_EXTERNAL)
	#define USE_SysProcessResume
	#define EXT_SysProcessResume
	#define GET_SysProcessResume(fl)  CAL_CMGETAPI( "SysProcessResume" ) 
	#define CAL_SysProcessResume  SysProcessResume
	#define CHK_SysProcessResume  TRUE
	#define EXP_SysProcessResume  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysProcessResume", (RTS_UINTPTR)SysProcessResume, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysProcessSysProcessResume
	#define EXT_SysProcessSysProcessResume
	#define GET_SysProcessSysProcessResume  ERR_OK
	#define CAL_SysProcessSysProcessResume pISysProcess->ISysProcessResume
	#define CHK_SysProcessSysProcessResume (pISysProcess != NULL)
	#define EXP_SysProcessSysProcessResume  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysProcessResume
	#define EXT_SysProcessResume
	#define GET_SysProcessResume(fl)  CAL_CMGETAPI( "SysProcessResume" ) 
	#define CAL_SysProcessResume pISysProcess->ISysProcessResume
	#define CHK_SysProcessResume (pISysProcess != NULL)
	#define EXP_SysProcessResume  CAL_CMEXPAPI( "SysProcessResume" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysProcessResume  PFSYSPROCESSRESUME pfSysProcessResume;
	#define EXT_SysProcessResume  extern PFSYSPROCESSRESUME pfSysProcessResume;
	#define GET_SysProcessResume(fl)  s_pfCMGetAPI2( "SysProcessResume", (RTS_VOID_FCTPTR *)&pfSysProcessResume, (fl), 0, 0)
	#define CAL_SysProcessResume  pfSysProcessResume
	#define CHK_SysProcessResume  (pfSysProcessResume != NULL)
	#define EXP_SysProcessResume  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysProcessResume", (RTS_UINTPTR)SysProcessResume, 0, 0) 
#endif




/**
 * <description> Function to terminate a process specified by handle </description>
 * <param name="hProcess" type="IN">Handle to the process</param>
 * <result>Error code: ERR_OK or ERR_FAILED</result>
 */
RTS_RESULT CDECL SysProcessTerminate(RTS_HANDLE hProcess);
typedef RTS_RESULT (CDECL * PFSYSPROCESSTERMINATE) (RTS_HANDLE hProcess);
#if defined(SYSPROCESS_NOTIMPLEMENTED) || defined(SYSPROCESSTERMINATE_NOTIMPLEMENTED)
	#define USE_SysProcessTerminate
	#define EXT_SysProcessTerminate
	#define GET_SysProcessTerminate(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysProcessTerminate(p0)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_SysProcessTerminate  FALSE
	#define EXP_SysProcessTerminate  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysProcessTerminate
	#define EXT_SysProcessTerminate
	#define GET_SysProcessTerminate(fl)  CAL_CMGETAPI( "SysProcessTerminate" ) 
	#define CAL_SysProcessTerminate  SysProcessTerminate
	#define CHK_SysProcessTerminate  TRUE
	#define EXP_SysProcessTerminate  CAL_CMEXPAPI( "SysProcessTerminate" ) 
#elif defined(MIXED_LINK) && !defined(SYSPROCESS_EXTERNAL)
	#define USE_SysProcessTerminate
	#define EXT_SysProcessTerminate
	#define GET_SysProcessTerminate(fl)  CAL_CMGETAPI( "SysProcessTerminate" ) 
	#define CAL_SysProcessTerminate  SysProcessTerminate
	#define CHK_SysProcessTerminate  TRUE
	#define EXP_SysProcessTerminate  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysProcessTerminate", (RTS_UINTPTR)SysProcessTerminate, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysProcessSysProcessTerminate
	#define EXT_SysProcessSysProcessTerminate
	#define GET_SysProcessSysProcessTerminate  ERR_OK
	#define CAL_SysProcessSysProcessTerminate pISysProcess->ISysProcessTerminate
	#define CHK_SysProcessSysProcessTerminate (pISysProcess != NULL)
	#define EXP_SysProcessSysProcessTerminate  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysProcessTerminate
	#define EXT_SysProcessTerminate
	#define GET_SysProcessTerminate(fl)  CAL_CMGETAPI( "SysProcessTerminate" ) 
	#define CAL_SysProcessTerminate pISysProcess->ISysProcessTerminate
	#define CHK_SysProcessTerminate (pISysProcess != NULL)
	#define EXP_SysProcessTerminate  CAL_CMEXPAPI( "SysProcessTerminate" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysProcessTerminate  PFSYSPROCESSTERMINATE pfSysProcessTerminate;
	#define EXT_SysProcessTerminate  extern PFSYSPROCESSTERMINATE pfSysProcessTerminate;
	#define GET_SysProcessTerminate(fl)  s_pfCMGetAPI2( "SysProcessTerminate", (RTS_VOID_FCTPTR *)&pfSysProcessTerminate, (fl), 0, 0)
	#define CAL_SysProcessTerminate  pfSysProcessTerminate
	#define CHK_SysProcessTerminate  (pfSysProcessTerminate != NULL)
	#define EXP_SysProcessTerminate  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysProcessTerminate", (RTS_UINTPTR)SysProcessTerminate, 0, 0) 
#endif




/**
 * <description> Function to get a handle to the current process </description>
 * <param name="pResult" type="OUT">Pointer to the result</param>
 * <result>The handle of the topical process</result>
 */
RTS_HANDLE CDECL SysProcessGetCurrentHandle(RTS_RESULT* pResult);
typedef RTS_HANDLE (CDECL * PFSYSPROCESSGETCURRENTHANDLE) (RTS_RESULT* pResult);
#if defined(SYSPROCESS_NOTIMPLEMENTED) || defined(SYSPROCESSGETCURRENTHANDLE_NOTIMPLEMENTED)
	#define USE_SysProcessGetCurrentHandle
	#define EXT_SysProcessGetCurrentHandle
	#define GET_SysProcessGetCurrentHandle(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysProcessGetCurrentHandle(p0)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_SysProcessGetCurrentHandle  FALSE
	#define EXP_SysProcessGetCurrentHandle  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysProcessGetCurrentHandle
	#define EXT_SysProcessGetCurrentHandle
	#define GET_SysProcessGetCurrentHandle(fl)  CAL_CMGETAPI( "SysProcessGetCurrentHandle" ) 
	#define CAL_SysProcessGetCurrentHandle  SysProcessGetCurrentHandle
	#define CHK_SysProcessGetCurrentHandle  TRUE
	#define EXP_SysProcessGetCurrentHandle  CAL_CMEXPAPI( "SysProcessGetCurrentHandle" ) 
#elif defined(MIXED_LINK) && !defined(SYSPROCESS_EXTERNAL)
	#define USE_SysProcessGetCurrentHandle
	#define EXT_SysProcessGetCurrentHandle
	#define GET_SysProcessGetCurrentHandle(fl)  CAL_CMGETAPI( "SysProcessGetCurrentHandle" ) 
	#define CAL_SysProcessGetCurrentHandle  SysProcessGetCurrentHandle
	#define CHK_SysProcessGetCurrentHandle  TRUE
	#define EXP_SysProcessGetCurrentHandle  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysProcessGetCurrentHandle", (RTS_UINTPTR)SysProcessGetCurrentHandle, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysProcessSysProcessGetCurrentHandle
	#define EXT_SysProcessSysProcessGetCurrentHandle
	#define GET_SysProcessSysProcessGetCurrentHandle  ERR_OK
	#define CAL_SysProcessSysProcessGetCurrentHandle pISysProcess->ISysProcessGetCurrentHandle
	#define CHK_SysProcessSysProcessGetCurrentHandle (pISysProcess != NULL)
	#define EXP_SysProcessSysProcessGetCurrentHandle  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysProcessGetCurrentHandle
	#define EXT_SysProcessGetCurrentHandle
	#define GET_SysProcessGetCurrentHandle(fl)  CAL_CMGETAPI( "SysProcessGetCurrentHandle" ) 
	#define CAL_SysProcessGetCurrentHandle pISysProcess->ISysProcessGetCurrentHandle
	#define CHK_SysProcessGetCurrentHandle (pISysProcess != NULL)
	#define EXP_SysProcessGetCurrentHandle  CAL_CMEXPAPI( "SysProcessGetCurrentHandle" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysProcessGetCurrentHandle  PFSYSPROCESSGETCURRENTHANDLE pfSysProcessGetCurrentHandle;
	#define EXT_SysProcessGetCurrentHandle  extern PFSYSPROCESSGETCURRENTHANDLE pfSysProcessGetCurrentHandle;
	#define GET_SysProcessGetCurrentHandle(fl)  s_pfCMGetAPI2( "SysProcessGetCurrentHandle", (RTS_VOID_FCTPTR *)&pfSysProcessGetCurrentHandle, (fl), 0, 0)
	#define CAL_SysProcessGetCurrentHandle  pfSysProcessGetCurrentHandle
	#define CHK_SysProcessGetCurrentHandle  (pfSysProcessGetCurrentHandle != NULL)
	#define EXP_SysProcessGetCurrentHandle  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysProcessGetCurrentHandle", (RTS_UINTPTR)SysProcessGetCurrentHandle, 0, 0) 
#endif




/**
 * <description> Function to free the process handle that is returned by SysProcessCreate or SysProcessGetCurrentHandle </description>
 * <param name="hProcess" type="IN">Handle to the process</param>
 * <result>Error code: ERR_OK or ERR_PARAMETER if handle is invalid</result>
 */
RTS_RESULT CDECL SysProcessFreeHandle(RTS_HANDLE hProcess);
typedef RTS_RESULT (CDECL * PFSYSPROCESSFREEHANDLE) (RTS_HANDLE hProcess);
#if defined(SYSPROCESS_NOTIMPLEMENTED) || defined(SYSPROCESSFREEHANDLE_NOTIMPLEMENTED)
	#define USE_SysProcessFreeHandle
	#define EXT_SysProcessFreeHandle
	#define GET_SysProcessFreeHandle(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysProcessFreeHandle(p0)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_SysProcessFreeHandle  FALSE
	#define EXP_SysProcessFreeHandle  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysProcessFreeHandle
	#define EXT_SysProcessFreeHandle
	#define GET_SysProcessFreeHandle(fl)  CAL_CMGETAPI( "SysProcessFreeHandle" ) 
	#define CAL_SysProcessFreeHandle  SysProcessFreeHandle
	#define CHK_SysProcessFreeHandle  TRUE
	#define EXP_SysProcessFreeHandle  CAL_CMEXPAPI( "SysProcessFreeHandle" ) 
#elif defined(MIXED_LINK) && !defined(SYSPROCESS_EXTERNAL)
	#define USE_SysProcessFreeHandle
	#define EXT_SysProcessFreeHandle
	#define GET_SysProcessFreeHandle(fl)  CAL_CMGETAPI( "SysProcessFreeHandle" ) 
	#define CAL_SysProcessFreeHandle  SysProcessFreeHandle
	#define CHK_SysProcessFreeHandle  TRUE
	#define EXP_SysProcessFreeHandle  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysProcessFreeHandle", (RTS_UINTPTR)SysProcessFreeHandle, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysProcessSysProcessFreeHandle
	#define EXT_SysProcessSysProcessFreeHandle
	#define GET_SysProcessSysProcessFreeHandle  ERR_OK
	#define CAL_SysProcessSysProcessFreeHandle pISysProcess->ISysProcessFreeHandle
	#define CHK_SysProcessSysProcessFreeHandle (pISysProcess != NULL)
	#define EXP_SysProcessSysProcessFreeHandle  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysProcessFreeHandle
	#define EXT_SysProcessFreeHandle
	#define GET_SysProcessFreeHandle(fl)  CAL_CMGETAPI( "SysProcessFreeHandle" ) 
	#define CAL_SysProcessFreeHandle pISysProcess->ISysProcessFreeHandle
	#define CHK_SysProcessFreeHandle (pISysProcess != NULL)
	#define EXP_SysProcessFreeHandle  CAL_CMEXPAPI( "SysProcessFreeHandle" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysProcessFreeHandle  PFSYSPROCESSFREEHANDLE pfSysProcessFreeHandle;
	#define EXT_SysProcessFreeHandle  extern PFSYSPROCESSFREEHANDLE pfSysProcessFreeHandle;
	#define GET_SysProcessFreeHandle(fl)  s_pfCMGetAPI2( "SysProcessFreeHandle", (RTS_VOID_FCTPTR *)&pfSysProcessFreeHandle, (fl), 0, 0)
	#define CAL_SysProcessFreeHandle  pfSysProcessFreeHandle
	#define CHK_SysProcessFreeHandle  (pfSysProcessFreeHandle != NULL)
	#define EXP_SysProcessFreeHandle  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysProcessFreeHandle", (RTS_UINTPTR)SysProcessFreeHandle, 0, 0) 
#endif




/**
 * <description> Function to get the actual state of a process </description>
 * <param name="hProcess" type="IN">Handle to the process</param>
 * <param name="piState" type="OUT">Pointer to state of the process, see the definitions above</param>
 * <result>Error code: ERR_OK or ERR_PARAMETER if handle is invalid</result>
 */
RTS_RESULT CDECL SysProcessGetState(RTS_HANDLE hProcess, RTS_I32 *piState);
typedef RTS_RESULT (CDECL * PFSYSPROCESSGETSTATE) (RTS_HANDLE hProcess, RTS_I32 *piState);
#if defined(SYSPROCESS_NOTIMPLEMENTED) || defined(SYSPROCESSGETSTATE_NOTIMPLEMENTED)
	#define USE_SysProcessGetState
	#define EXT_SysProcessGetState
	#define GET_SysProcessGetState(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysProcessGetState(p0,p1)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_SysProcessGetState  FALSE
	#define EXP_SysProcessGetState  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysProcessGetState
	#define EXT_SysProcessGetState
	#define GET_SysProcessGetState(fl)  CAL_CMGETAPI( "SysProcessGetState" ) 
	#define CAL_SysProcessGetState  SysProcessGetState
	#define CHK_SysProcessGetState  TRUE
	#define EXP_SysProcessGetState  CAL_CMEXPAPI( "SysProcessGetState" ) 
#elif defined(MIXED_LINK) && !defined(SYSPROCESS_EXTERNAL)
	#define USE_SysProcessGetState
	#define EXT_SysProcessGetState
	#define GET_SysProcessGetState(fl)  CAL_CMGETAPI( "SysProcessGetState" ) 
	#define CAL_SysProcessGetState  SysProcessGetState
	#define CHK_SysProcessGetState  TRUE
	#define EXP_SysProcessGetState  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysProcessGetState", (RTS_UINTPTR)SysProcessGetState, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysProcessSysProcessGetState
	#define EXT_SysProcessSysProcessGetState
	#define GET_SysProcessSysProcessGetState  ERR_OK
	#define CAL_SysProcessSysProcessGetState pISysProcess->ISysProcessGetState
	#define CHK_SysProcessSysProcessGetState (pISysProcess != NULL)
	#define EXP_SysProcessSysProcessGetState  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysProcessGetState
	#define EXT_SysProcessGetState
	#define GET_SysProcessGetState(fl)  CAL_CMGETAPI( "SysProcessGetState" ) 
	#define CAL_SysProcessGetState pISysProcess->ISysProcessGetState
	#define CHK_SysProcessGetState (pISysProcess != NULL)
	#define EXP_SysProcessGetState  CAL_CMEXPAPI( "SysProcessGetState" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysProcessGetState  PFSYSPROCESSGETSTATE pfSysProcessGetState;
	#define EXT_SysProcessGetState  extern PFSYSPROCESSGETSTATE pfSysProcessGetState;
	#define GET_SysProcessGetState(fl)  s_pfCMGetAPI2( "SysProcessGetState", (RTS_VOID_FCTPTR *)&pfSysProcessGetState, (fl), 0, 0)
	#define CAL_SysProcessGetState  pfSysProcessGetState
	#define CHK_SysProcessGetState  (pfSysProcessGetState != NULL)
	#define EXP_SysProcessGetState  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysProcessGetState", (RTS_UINTPTR)SysProcessGetState, 0, 0) 
#endif




/**
 * <description> Function to set the process priority </description>
 * <param name="hProcess" type="IN">Handle to the process</param>
 * <param name="ulPriority" type="IN">Process priority</param>
 * <result>Error code: ERR_OK or ERR_FAILED</result>
 */
RTS_RESULT CDECL SysProcessSetPriority(RTS_HANDLE hProcess, RTS_UI32 ulPriority);
typedef RTS_RESULT (CDECL * PFSYSPROCESSSETPRIORITY) (RTS_HANDLE hProcess, RTS_UI32 ulPriority);
#if defined(SYSPROCESS_NOTIMPLEMENTED) || defined(SYSPROCESSSETPRIORITY_NOTIMPLEMENTED)
	#define USE_SysProcessSetPriority
	#define EXT_SysProcessSetPriority
	#define GET_SysProcessSetPriority(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysProcessSetPriority(p0,p1)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_SysProcessSetPriority  FALSE
	#define EXP_SysProcessSetPriority  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysProcessSetPriority
	#define EXT_SysProcessSetPriority
	#define GET_SysProcessSetPriority(fl)  CAL_CMGETAPI( "SysProcessSetPriority" ) 
	#define CAL_SysProcessSetPriority  SysProcessSetPriority
	#define CHK_SysProcessSetPriority  TRUE
	#define EXP_SysProcessSetPriority  CAL_CMEXPAPI( "SysProcessSetPriority" ) 
#elif defined(MIXED_LINK) && !defined(SYSPROCESS_EXTERNAL)
	#define USE_SysProcessSetPriority
	#define EXT_SysProcessSetPriority
	#define GET_SysProcessSetPriority(fl)  CAL_CMGETAPI( "SysProcessSetPriority" ) 
	#define CAL_SysProcessSetPriority  SysProcessSetPriority
	#define CHK_SysProcessSetPriority  TRUE
	#define EXP_SysProcessSetPriority  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysProcessSetPriority", (RTS_UINTPTR)SysProcessSetPriority, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysProcessSysProcessSetPriority
	#define EXT_SysProcessSysProcessSetPriority
	#define GET_SysProcessSysProcessSetPriority  ERR_OK
	#define CAL_SysProcessSysProcessSetPriority pISysProcess->ISysProcessSetPriority
	#define CHK_SysProcessSysProcessSetPriority (pISysProcess != NULL)
	#define EXP_SysProcessSysProcessSetPriority  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysProcessSetPriority
	#define EXT_SysProcessSetPriority
	#define GET_SysProcessSetPriority(fl)  CAL_CMGETAPI( "SysProcessSetPriority" ) 
	#define CAL_SysProcessSetPriority pISysProcess->ISysProcessSetPriority
	#define CHK_SysProcessSetPriority (pISysProcess != NULL)
	#define EXP_SysProcessSetPriority  CAL_CMEXPAPI( "SysProcessSetPriority" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysProcessSetPriority  PFSYSPROCESSSETPRIORITY pfSysProcessSetPriority;
	#define EXT_SysProcessSetPriority  extern PFSYSPROCESSSETPRIORITY pfSysProcessSetPriority;
	#define GET_SysProcessSetPriority(fl)  s_pfCMGetAPI2( "SysProcessSetPriority", (RTS_VOID_FCTPTR *)&pfSysProcessSetPriority, (fl), 0, 0)
	#define CAL_SysProcessSetPriority  pfSysProcessSetPriority
	#define CHK_SysProcessSetPriority  (pfSysProcessSetPriority != NULL)
	#define EXP_SysProcessSetPriority  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysProcessSetPriority", (RTS_UINTPTR)SysProcessSetPriority, 0, 0) 
#endif




/**
 * <description> Function to get the process priority </description>
 * <param name="hProcess" type="IN">Handle to the process</param>
 * <param name="pulPriority" type="OUT">Pointer to priority</param>
 * <result>Error code: ERR_OK or ERR_FAILED</result>
 */
RTS_RESULT CDECL SysProcessGetPriority(RTS_HANDLE hProcess, RTS_UI32 *pulPriority);
typedef RTS_RESULT (CDECL * PFSYSPROCESSGETPRIORITY) (RTS_HANDLE hProcess, RTS_UI32 *pulPriority);
#if defined(SYSPROCESS_NOTIMPLEMENTED) || defined(SYSPROCESSGETPRIORITY_NOTIMPLEMENTED)
	#define USE_SysProcessGetPriority
	#define EXT_SysProcessGetPriority
	#define GET_SysProcessGetPriority(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysProcessGetPriority(p0,p1)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_SysProcessGetPriority  FALSE
	#define EXP_SysProcessGetPriority  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysProcessGetPriority
	#define EXT_SysProcessGetPriority
	#define GET_SysProcessGetPriority(fl)  CAL_CMGETAPI( "SysProcessGetPriority" ) 
	#define CAL_SysProcessGetPriority  SysProcessGetPriority
	#define CHK_SysProcessGetPriority  TRUE
	#define EXP_SysProcessGetPriority  CAL_CMEXPAPI( "SysProcessGetPriority" ) 
#elif defined(MIXED_LINK) && !defined(SYSPROCESS_EXTERNAL)
	#define USE_SysProcessGetPriority
	#define EXT_SysProcessGetPriority
	#define GET_SysProcessGetPriority(fl)  CAL_CMGETAPI( "SysProcessGetPriority" ) 
	#define CAL_SysProcessGetPriority  SysProcessGetPriority
	#define CHK_SysProcessGetPriority  TRUE
	#define EXP_SysProcessGetPriority  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysProcessGetPriority", (RTS_UINTPTR)SysProcessGetPriority, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysProcessSysProcessGetPriority
	#define EXT_SysProcessSysProcessGetPriority
	#define GET_SysProcessSysProcessGetPriority  ERR_OK
	#define CAL_SysProcessSysProcessGetPriority pISysProcess->ISysProcessGetPriority
	#define CHK_SysProcessSysProcessGetPriority (pISysProcess != NULL)
	#define EXP_SysProcessSysProcessGetPriority  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysProcessGetPriority
	#define EXT_SysProcessGetPriority
	#define GET_SysProcessGetPriority(fl)  CAL_CMGETAPI( "SysProcessGetPriority" ) 
	#define CAL_SysProcessGetPriority pISysProcess->ISysProcessGetPriority
	#define CHK_SysProcessGetPriority (pISysProcess != NULL)
	#define EXP_SysProcessGetPriority  CAL_CMEXPAPI( "SysProcessGetPriority" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysProcessGetPriority  PFSYSPROCESSGETPRIORITY pfSysProcessGetPriority;
	#define EXT_SysProcessGetPriority  extern PFSYSPROCESSGETPRIORITY pfSysProcessGetPriority;
	#define GET_SysProcessGetPriority(fl)  s_pfCMGetAPI2( "SysProcessGetPriority", (RTS_VOID_FCTPTR *)&pfSysProcessGetPriority, (fl), 0, 0)
	#define CAL_SysProcessGetPriority  pfSysProcessGetPriority
	#define CHK_SysProcessGetPriority  (pfSysProcessGetPriority != NULL)
	#define EXP_SysProcessGetPriority  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysProcessGetPriority", (RTS_UINTPTR)SysProcessGetPriority, 0, 0) 
#endif




/**
 * <description> Function to determine an operating system dependent identification of a process. This 
 * identification must be unique in the system at a defined time! This function will only work on processes created
 *	with SysProcessCreate or on the current process </description>
 * <param name="hProcess" type="IN">Handle to the process</param>
 * <param name="pResult" type="OUT">Pointer to the result</param>
 * <result>The OS dependent id as a DWORD</result>
 */
RTS_UI32 CDECL SysProcessGetOSId(RTS_HANDLE hProcess, RTS_RESULT* pResult);
typedef RTS_UI32 (CDECL * PFSYSPROCESSGETOSID) (RTS_HANDLE hProcess, RTS_RESULT* pResult);
#if defined(SYSPROCESS_NOTIMPLEMENTED) || defined(SYSPROCESSGETOSID_NOTIMPLEMENTED)
	#define USE_SysProcessGetOSId
	#define EXT_SysProcessGetOSId
	#define GET_SysProcessGetOSId(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysProcessGetOSId(p0,p1)  (RTS_UI32)ERR_NOTIMPLEMENTED
	#define CHK_SysProcessGetOSId  FALSE
	#define EXP_SysProcessGetOSId  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysProcessGetOSId
	#define EXT_SysProcessGetOSId
	#define GET_SysProcessGetOSId(fl)  CAL_CMGETAPI( "SysProcessGetOSId" ) 
	#define CAL_SysProcessGetOSId  SysProcessGetOSId
	#define CHK_SysProcessGetOSId  TRUE
	#define EXP_SysProcessGetOSId  CAL_CMEXPAPI( "SysProcessGetOSId" ) 
#elif defined(MIXED_LINK) && !defined(SYSPROCESS_EXTERNAL)
	#define USE_SysProcessGetOSId
	#define EXT_SysProcessGetOSId
	#define GET_SysProcessGetOSId(fl)  CAL_CMGETAPI( "SysProcessGetOSId" ) 
	#define CAL_SysProcessGetOSId  SysProcessGetOSId
	#define CHK_SysProcessGetOSId  TRUE
	#define EXP_SysProcessGetOSId  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysProcessGetOSId", (RTS_UINTPTR)SysProcessGetOSId, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysProcessSysProcessGetOSId
	#define EXT_SysProcessSysProcessGetOSId
	#define GET_SysProcessSysProcessGetOSId  ERR_OK
	#define CAL_SysProcessSysProcessGetOSId pISysProcess->ISysProcessGetOSId
	#define CHK_SysProcessSysProcessGetOSId (pISysProcess != NULL)
	#define EXP_SysProcessSysProcessGetOSId  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysProcessGetOSId
	#define EXT_SysProcessGetOSId
	#define GET_SysProcessGetOSId(fl)  CAL_CMGETAPI( "SysProcessGetOSId" ) 
	#define CAL_SysProcessGetOSId pISysProcess->ISysProcessGetOSId
	#define CHK_SysProcessGetOSId (pISysProcess != NULL)
	#define EXP_SysProcessGetOSId  CAL_CMEXPAPI( "SysProcessGetOSId" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysProcessGetOSId  PFSYSPROCESSGETOSID pfSysProcessGetOSId;
	#define EXT_SysProcessGetOSId  extern PFSYSPROCESSGETOSID pfSysProcessGetOSId;
	#define GET_SysProcessGetOSId(fl)  s_pfCMGetAPI2( "SysProcessGetOSId", (RTS_VOID_FCTPTR *)&pfSysProcessGetOSId, (fl), 0, 0)
	#define CAL_SysProcessGetOSId  pfSysProcessGetOSId
	#define CHK_SysProcessGetOSId  (pfSysProcessGetOSId != NULL)
	#define EXP_SysProcessGetOSId  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysProcessGetOSId", (RTS_UINTPTR)SysProcessGetOSId, 0, 0) 
#endif




#ifdef __cplusplus
}
#endif



typedef struct
{
	IBase_C *pBase;
	PFSYSPROCESSEXECUTECOMMAND ISysProcessExecuteCommand;
 	PFSYSPROCESSEXECUTECOMMAND2 ISysProcessExecuteCommand2;
 	PFSYSPROCESSCREATE ISysProcessCreate;
 	PFSYSPROCESSRESUME ISysProcessResume;
 	PFSYSPROCESSTERMINATE ISysProcessTerminate;
 	PFSYSPROCESSGETCURRENTHANDLE ISysProcessGetCurrentHandle;
 	PFSYSPROCESSFREEHANDLE ISysProcessFreeHandle;
 	PFSYSPROCESSGETSTATE ISysProcessGetState;
 	PFSYSPROCESSSETPRIORITY ISysProcessSetPriority;
 	PFSYSPROCESSGETPRIORITY ISysProcessGetPriority;
 	PFSYSPROCESSGETOSID ISysProcessGetOSId;
 } ISysProcess_C;

#ifdef CPLUSPLUS
class ISysProcess : public IBase
{
	public:
		virtual RTS_I32 CDECL ISysProcessExecuteCommand(char *pszCommand, RTS_RESULT *pResult) =0;
		virtual RTS_I32 CDECL ISysProcessExecuteCommand2(char *pszCommand, char* pszStdOut, RTS_UI32 udiStdOutLen, RTS_RESULT *pResult) =0;
		virtual RTS_HANDLE CDECL ISysProcessCreate(char *pszApplication, char *pszCommandLine, RTS_UI32 ulFlags, RTS_RESULT *pResult) =0;
		virtual RTS_RESULT CDECL ISysProcessResume(RTS_HANDLE hProcess) =0;
		virtual RTS_RESULT CDECL ISysProcessTerminate(RTS_HANDLE hProcess) =0;
		virtual RTS_HANDLE CDECL ISysProcessGetCurrentHandle(RTS_RESULT* pResult) =0;
		virtual RTS_RESULT CDECL ISysProcessFreeHandle(RTS_HANDLE hProcess) =0;
		virtual RTS_RESULT CDECL ISysProcessGetState(RTS_HANDLE hProcess, RTS_I32 *piState) =0;
		virtual RTS_RESULT CDECL ISysProcessSetPriority(RTS_HANDLE hProcess, RTS_UI32 ulPriority) =0;
		virtual RTS_RESULT CDECL ISysProcessGetPriority(RTS_HANDLE hProcess, RTS_UI32 *pulPriority) =0;
		virtual RTS_UI32 CDECL ISysProcessGetOSId(RTS_HANDLE hProcess, RTS_RESULT* pResult) =0;
};
	#ifndef ITF_SysProcess
		#define ITF_SysProcess static ISysProcess *pISysProcess = NULL;
	#endif
	#define EXTITF_SysProcess
#else	/*CPLUSPLUS*/
	typedef ISysProcess_C		ISysProcess;
	#ifndef ITF_SysProcess
		#define ITF_SysProcess
	#endif
	#define EXTITF_SysProcess
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_SYSPROCESSITF_H_*/
