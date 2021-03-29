/**
 * <interfacename>SysProcess_Implementation</interfacename>
 * <description></description>
 *
 * <copyright></copyright>
 */

SET_INTERFACE_NAME(`SysProcess_Implementation')
SET_PLACEHOLDER_NAME(`SysProcess Implementation')

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

DEF_API(`void',`CDECL',`sysprocesscreate',`(sysprocesscreate_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xB8C769CB),0x03051000)

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

DEF_API(`void',`CDECL',`sysprocesscreate2',`(sysprocesscreate2_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x053781FD),0x03051000)

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

DEF_API(`void',`CDECL',`sysprocessexecutecommand',`(sysprocessexecutecommand_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xE26B1ECD),0x03051000)

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

DEF_API(`void',`CDECL',`sysprocessexecutecommand2',`(sysprocessexecutecommand2_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x827A1263),0x03051000)

/**
 * <description>Function to release the process handle that is returned by SysProcessCreate or SysProcessGetCurrentHandle.</description>
 * <result><p>RESULT: Returns the runtime system error code (see CmpErrors.library).</p></result>
 */
typedef struct tagsysprocessfreehandle_struct
{
	RTS_IEC_HANDLE hProcess;			/* VAR_INPUT */	/* <param name="hProcess" type="IN">Handle of the process</param> */
	RTS_IEC_RESULT SysProcessFreeHandle;	/* VAR_OUTPUT */	
} sysprocessfreehandle_struct;

DEF_API(`void',`CDECL',`sysprocessfreehandle',`(sysprocessfreehandle_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xD81A18BC),0x03051000)

/**
 * <description>Function to get a handle to the current process</description>
 * <result><p>RESULT: Returns the handle of the process actually running by the processor or RTS_INVALID_HANDLE if failed.</p></result>
 */
typedef struct tagsysprocessgetcurrenthandle_struct
{
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* <param name="pResult" type="OUT">Pointer to runtime system error code (see CmpErrors.library)</param> */
	RTS_IEC_HANDLE SysProcessGetCurrentHandle;	/* VAR_OUTPUT */	
} sysprocessgetcurrenthandle_struct;

DEF_API(`void',`CDECL',`sysprocessgetcurrenthandle',`(sysprocessgetcurrenthandle_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xF293D47C),0x03051000)

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

DEF_API(`void',`CDECL',`sysprocessgetosid',`(sysprocessgetosid_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x946F8470),0x03051000)

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

DEF_API(`void',`CDECL',`sysprocessgetpriority',`(sysprocessgetpriority_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xCEA416D5),0x03051000)

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

DEF_API(`void',`CDECL',`sysprocessgetstate',`(sysprocessgetstate_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xB65EA319),0x03051000)

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

DEF_API(`void',`CDECL',`sysprocessresume',`(sysprocessresume_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x1587F094),0x03051000)

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

DEF_API(`void',`CDECL',`sysprocesssetpriority',`(sysprocesssetpriority_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xCB07213F),0x03051000)

/**
 * <description>This function terminates the process specified by its handle.</description>
 * <result><p>RESULT: Returns the runtime system error code (see CmpErrors.library).</p></result>
 */
typedef struct tagsysprocessterminate_struct
{
	RTS_IEC_HANDLE hProcess;			/* VAR_INPUT */	/* <param name="hProcess" type="IN">Handle of the process</param> */
	RTS_IEC_RESULT SysProcessTerminate;	/* VAR_OUTPUT */	
} sysprocessterminate_struct;

DEF_API(`void',`CDECL',`sysprocessterminate',`(sysprocessterminate_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x498BEF7C),0x03051000)

#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/

