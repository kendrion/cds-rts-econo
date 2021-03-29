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

SET_INTERFACE_NAME(`SysProcess')

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
/*  Comments are ignored for m4 compiler so restructured text can be used. changecom(`/*', `*/') */

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
DEF_ITF_API(`RTS_I32',`CDECL',`SysProcessExecuteCommand',`(char *pszCommand, RTS_RESULT *pResult)')

/**
 * <description> Function to start a system command. The command is operating system dependent! 
 *	If Pointer to buffer is not null for StdOut or StdErr the buffer will be filled.</description>
 * <param name="pszCommand" type="IN">String with the command line</param> 
 * <param name="pszStdOut" type="IN">Buffer for StdOut string</param>
 * <param name="udiStdOutLen" type="IN">Buffer size for StdOut string buffer</param>
 * <param name="pResult" type="OUT">Pointer to runtime system error code (see CmpErrors.library)</param>
 */
DEF_ITF_API(`RTS_I32',`CDECL',`SysProcessExecuteCommand2',`(char *pszCommand, char* pszStdOut, RTS_UI32 udiStdOutLen, RTS_RESULT *pResult)')


/**
 * <description> Function to create a process. Is only valid on systems with processes! </description>
 * <param name="pszApplication" type="IN">Name of application to start as a separate process</param>
 * <param name="pszCommandLine" type="IN">String with the command line</param>
 * <param name="ulFlags" type="IN">A combination of flags like PROCESS_CREATEFLAG_HIDDEN for example.</param>
 * <param name="pResult" type="OUT">Pointer to the result</param>
 * <result>Handle to the process</result>
 */
DEF_ITF_API(`RTS_HANDLE',`CDECL',`SysProcessCreate',`(char *pszApplication, char *pszCommandLine, RTS_UI32 ulFlags, RTS_RESULT *pResult)')

/**
 * <description> Function to resume a process specified by handle. This can be used, if a process is created with PROCESS_CREATEFLAG_CREATESUSPENDED flag.</description>
 * <param name="hProcess" type="IN">Handle to the process</param>
 * <result>Error code: ERR_OK or ERR_FAILED</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysProcessResume',`(RTS_HANDLE hProcess)')

/**
 * <description> Function to terminate a process specified by handle </description>
 * <param name="hProcess" type="IN">Handle to the process</param>
 * <result>Error code: ERR_OK or ERR_FAILED</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysProcessTerminate',`(RTS_HANDLE hProcess)')

/**
 * <description> Function to get a handle to the current process </description>
 * <param name="pResult" type="OUT">Pointer to the result</param>
 * <result>The handle of the topical process</result>
 */
DEF_ITF_API(`RTS_HANDLE',`CDECL',`SysProcessGetCurrentHandle',`(RTS_RESULT* pResult)')

/**
 * <description> Function to free the process handle that is returned by SysProcessCreate or SysProcessGetCurrentHandle </description>
 * <param name="hProcess" type="IN">Handle to the process</param>
 * <result>Error code: ERR_OK or ERR_PARAMETER if handle is invalid</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysProcessFreeHandle',`(RTS_HANDLE hProcess)')

/**
 * <description> Function to get the actual state of a process </description>
 * <param name="hProcess" type="IN">Handle to the process</param>
 * <param name="piState" type="OUT">Pointer to state of the process, see the definitions above</param>
 * <result>Error code: ERR_OK or ERR_PARAMETER if handle is invalid</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysProcessGetState',`(RTS_HANDLE hProcess, RTS_I32 *piState)')

/**
 * <description> Function to set the process priority </description>
 * <param name="hProcess" type="IN">Handle to the process</param>
 * <param name="ulPriority" type="IN">Process priority</param>
 * <result>Error code: ERR_OK or ERR_FAILED</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysProcessSetPriority',`(RTS_HANDLE hProcess, RTS_UI32 ulPriority)')

/**
 * <description> Function to get the process priority </description>
 * <param name="hProcess" type="IN">Handle to the process</param>
 * <param name="pulPriority" type="OUT">Pointer to priority</param>
 * <result>Error code: ERR_OK or ERR_FAILED</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysProcessGetPriority',`(RTS_HANDLE hProcess, RTS_UI32 *pulPriority)')

/**
 * <description> Function to determine an operating system dependent identification of a process. This 
 * identification must be unique in the system at a defined time! This function will only work on processes created
 *	with SysProcessCreate or on the current process </description>
 * <param name="hProcess" type="IN">Handle to the process</param>
 * <param name="pResult" type="OUT">Pointer to the result</param>
 * <result>The OS dependent id as a DWORD</result>
 */
DEF_ITF_API(`RTS_UI32',`CDECL',`SysProcessGetOSId',`(RTS_HANDLE hProcess, RTS_RESULT* pResult)')

#ifdef __cplusplus
}
#endif
