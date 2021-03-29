/**
 * <interfacename>SysCpuHandling</interfacename>
 * <description> 
 *	<p>The SysCpuHandling interface contains all CPU specific routines.</p>
 *	<p>To detect, for which platform the component is compiled, there are special defines that must be set
 *	in sysdefines.h dependent of the compiler specific options (see category "Processor ID" in SysTargetItf.h)</p>
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`SysCpuHandling')

REF_ITF(`SysExceptItf.m4')

/**
 * <category>Settings</category>
 * <description>Obsolete: detection is done automatically by checking the generated code.</description>
 */
#define SYSCPUHANDLING_WINCE7_ARM_SEH				"EnableWinCE7ArmSEH"
#define SYSCPUHANDLING_WINCE7_ARM_SEH_DEFAULT		0

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>for real-time requirements. opens /dev/cpu_dma_latency and writes a zero to it. This will prevent transitions to deep sleep states. Additionally it emulates the idle=poll behavior</description>
 */
#define SYSCPUHANDLINGKEY_INT_LINUX_DISABLE_CPU_DMA_LATENCY				"Linux.DisableCpuDmaLatency"
#define SYSCPUHANDLINGKEY_INT_LINUX_DISABLE_CPU_DMA_LATENCY_DEFAULT		0

/**
 * <category>Static defines</category>
 * <description>Definition of the stack marker to locate the caller of an external library function on the stack</description>
 */
#ifdef TRG_64BIT
	#define SYSCPU_STACK_MARKER		0xCDE1F2CDCDE1F2CD
#else
	#define SYSCPU_STACK_MARKER		0xCDE1F2CD
#endif


/**
 * <category>Platform defines - IEC code-generator specific!</category>
 * <description>
 *	Stack alignment.
 *	NOTE:
 *	Must match to the following code-generator TargetSetting in the DeviceDescription of the target:
 *		<ts:section name="codegenerator">
 *			<ts:section name="memory-layout">
 *				<ts:setting name="stack-alignment" type="integer" access="visible">
 *					<ts:value>4</ts:value>
 *				</ts:setting>
 *			</ts:section>
 *		</ts:section>
 * </description>
 */
#ifndef SYSCPU_STACK_ALIGNMENT
	#if defined(TRG_64BIT)
		#define SYSCPU_STACK_ALIGNMENT					16
	#elif defined(TRG_ARM)
		/* Can be 4 or 8 */
		#define SYSCPU_STACK_ALIGNMENT					4
	#elif defined(TRG_CORTEX)
		/* Can be 4 or 8 */
		#define SYSCPU_STACK_ALIGNMENT					4
	#elif defined(TRG_PPC)
		/* Can be 4 or 8 */
		#define SYSCPU_STACK_ALIGNMENT					4
	#elif defined(TRG_MIPS)
		/* Can be 4 or 8 */
		#define SYSCPU_STACK_ALIGNMENT					4
	#elif defined(TRG_SH)
		#define SYSCPU_STACK_ALIGNMENT					4
	#else
		#define SYSCPU_STACK_ALIGNMENT					4
	#endif
#endif


/**
 * <category>Platform defines - IEC code-generator specific!</category>
 * <description>
 *	Size of the register save area in number of saved registers! Is used for locating the return address
 *	of an external library call in SysCpuGetCallstackEntry2().
 * </description>
 */
#ifndef SYSCPU_EXTLIBCALL_REGISTER_SAVE_AREA
	#if defined(TRG_X86)
		#define SYSCPU_EXTLIBCALL_REGISTER_SAVE_AREA	4
	#elif defined(TRG_ARM)
		#define SYSCPU_EXTLIBCALL_REGISTER_SAVE_AREA	1
	#elif defined(TRG_CORTEX)
		#define SYSCPU_EXTLIBCALL_REGISTER_SAVE_AREA	0
	#elif defined(TRG_PPC)
		#define SYSCPU_EXTLIBCALL_REGISTER_SAVE_AREA	8
	#elif defined(TRG_MIPS)
		#define SYSCPU_EXTLIBCALL_REGISTER_SAVE_AREA	4
	#elif defined(TRG_SH)
		#define SYSCPU_EXTLIBCALL_REGISTER_SAVE_AREA	2
	#else
		#define SYSCPU_EXTLIBCALL_REGISTER_SAVE_AREA	0
	#endif
#endif


/**
 * <category>Platform defines - IEC code-generator specific!</category>
 * <description>
 *	Processor specific adjustment of offset for stack examination. 
 *  Is used for locating the return address of an external library 
 *  call in SysCpuGetCallstackEntry2().
 * </description>
 */
#ifndef SYSCPU_EXTLIBCALL_ADJUST_OFFSET
		#define SYSCPU_EXTLIBCALL_ADJUST_OFFSET(offset) 	(offset)
#endif


/**
 * <category>Platform defines</category>
 * <description>NOP opcode definitions. Is used by CmpSchedule to detect the breakpoint position after external library call to suspend task!</description>							  
 */
#ifndef SYSCPU_NOP_OPCODE
	#if defined(TRG_X86)
		/* x86: 0x90 */
		#define SYSCPU_NOP_OPCODE			{0x90}
		#define SYSCPU_NOP_OPCODE_SIZE		1
	#elif defined(TRG_ARM)
		/* ARM: 0x60000000 */
		#define SYSCPU_NOP_OPCODE			{0x00,0x00,0x00,0x60}
		#define SYSCPU_NOP_OPCODE_SIZE		4
	#elif defined(TRG_CORTEX)
		/* CortexM3:  0xBF00 */
		#define SYSCPU_NOP_OPCODE			{0x00,0xBF}
		#define SYSCPU_NOP_OPCODE_SIZE		2
	#elif defined(TRG_PPC)
		/* PPC: 0x60000000 */
		#define SYSCPU_NOP_OPCODE			{0x60,0x00,0x00,0x00}
		#define SYSCPU_NOP_OPCODE_SIZE		4
	#elif defined(TRG_MIPS)
		/* PPC: 0x00000000 */
		#define SYSCPU_NOP_OPCODE			{0x00,0x00,0x00,0x60}
		#define SYSCPU_NOP_OPCODE_SIZE		4
	#elif defined(TRG_SH)
		/* SH: 0x0009 */
		#define SYSCPU_NOP_OPCODE			{0x09,0x00}
		#define SYSCPU_NOP_OPCODE_SIZE		2
	#else
		#define SYSCPU_NOP_OPCODE			{0x00}
		#define SYSCPU_NOP_OPCODE_SIZE		0
	#endif
#endif


/**
 * <category>Platform defines</category>	
 * <description>
 *	Alignment of 2-byte data types will be checked and handled according to this define.
 * </description> 					  
 */
#ifndef SYSCPU_ALIGNMENT_CHECK_16
	#ifdef TRG_X86
		#define SYSCPU_ALIGNMENT_CHECK_16 1
	#else
		#define SYSCPU_ALIGNMENT_CHECK_16 2
	#endif
#endif


/**
 * <category>Platform defines</category>	
 * <description>
 *	Alignment of 4-byte data types will be checked and handled according to this define.
 * </description> 					  
 */
#ifndef SYSCPU_ALIGNMENT_CHECK_32
	#ifdef TRG_X86
		#define SYSCPU_ALIGNMENT_CHECK_32 1
	#else
		#define SYSCPU_ALIGNMENT_CHECK_32 4
	#endif
#endif


/**
 * <category>Platform defines</category>	
 * <description>
 *	Alignment of 8-byte data types will be checked and handled according to this define.
 * </description> 					  
 */
#ifndef SYSCPU_ALIGNMENT_CHECK_64
	#ifdef TRG_X86
		#define SYSCPU_ALIGNMENT_CHECK_64 1
	#else
		#define SYSCPU_ALIGNMENT_CHECK_64 8
	#endif
#endif


/**
 * <category>Register Offsets</category>
 * <description>
 *	The syscpudebughandler function stores the register context to stack on entry and calls
 *	AppDebugHandler2() function with the register context, which is system specific.
 *	According to the currently used CPU one of those stored registers, which is addressed
 *	by register number, is tried to be set in the SysCpuSetRegisterValue() function.
 *	Depending to the system adaptation and the syscpudebughandler implementation, the 
 *	register context may have different layouts and the offset to the given register number
 *	may vary and this macro may be used to specify the pointer size wide offset to the 
 *	given register number in the stored register context. 
 * </description>
 */
#ifndef SYSCPU_REGISTER_OFFSET
	#define SYSCPU_REGISTER_OFFSET(regNumber)	(regNumber)
#endif

/** EXTERN LIB SECTION BEGIN **/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description>
 *  Function to increment the content of the given pointer by nSum in one atomic operation (task safe).
 *  IMPLEMENTATION NOTE:
 *  - Add/Sub the value to the content of the pointer
 *  - Return the value after the Add/Sub operation
 *  Both things must be done atomic!
 * </description>
 * <result><p>RESULT: Returns the value after the increment operation in an atomic way!
 * </p></result>
 * <SIL2/>
 */
typedef struct tagsyscpuatomicadd_struct
{
	RTS_IEC_DINT *piValue;				/* VAR_INPUT */	/* <param name="piValue" type="INOUT">Pointer to the value to increment</param> */
	RTS_IEC_DINT nSum;					/* VAR_INPUT */	/* <param name="nSum" type="IN">Summand for the operation. &gt;0 to increment, &lt;0 to decrement</param> */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* <param name="pResult" type="OUT">Pointer to runtime system error code (see CmpErrors.library)</param> */
	RTS_IEC_DINT SysCpuAtomicAdd;		/* VAR_OUTPUT */	
} syscpuatomicadd_struct;

DEF_API(`void',`CDECL',`syscpuatomicadd',`(syscpuatomicadd_struct *p)',1,0x414E4706,0x03050D00)

/**
 * <description>
 *  Function to increment the content of the given pointer by nSum in one atomic operation (task safe).
 *  IMPLEMENTATION NOTE:
 *  - Add/Sub the value to the content of the pointer
 *  - Return the value after the Add/Sub operation
 *  Both things must be done atomic!
 * </description>
 * <result><p>RESULT: Returns the value after the increment operation in an atomic way!
 * </p></result>
 * <SIL2/>
 */
typedef struct tagsyscpuatomicadd64_struct
{
	RTS_IEC_LINT *piValue;				/* VAR_INPUT */	/* <param name="piValue" type="INOUT">Pointer to the value to increment</param> */
	RTS_IEC_LINT nSum;					/* VAR_INPUT */	/* <param name="nSum" type="IN">Summand for the operation. &gt;0 to increment, &lt;0 to decrement</param> */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* <param name="pResult" type="OUT">Pointer to runtime system error code (see CmpErrors.library)</param> */
	RTS_IEC_LINT SysCpuAtomicAdd64;		/* VAR_OUTPUT */	
} syscpuatomicadd64_struct;

DEF_API(`void',`CDECL',`syscpuatomicadd64',`(syscpuatomicadd64_struct *p)',1,0xA535E8A0,0x03050D00)

/**
 * <description>
 * Function for compare-and-swap in one atomic operation (task safe).
 * Supports only 32- and 64-bit types 
 * </description>
 * <result><p>RESULT: Returns ERR_OK if the swap was successful
 * </p></result>
 * <SIL2/>
 */
typedef struct tagsyscpuatomiccompareandswap_struct
{
	RTS_IEC_BYTE *pAddress;				/* VAR_INPUT */	/* pointer to the value to test */
	RTS_IEC_BYTE *pSwapValue;			/* VAR_INPUT */	/* pointer to new valid */
	RTS_IEC_BYTE *pCompareValue;		/* VAR_INPUT */	/* pointer to compare value */
	RTS_IEC_USINT valueSize;			/* VAR_INPUT */	/* size of the value */
	RTS_IEC_RESULT SysCpuAtomicCompareAndSwap;	/* VAR_OUTPUT */	
} syscpuatomiccompareandswap_struct;

DEF_API(`void',`CDECL',`syscpuatomiccompareandswap',`(syscpuatomiccompareandswap_struct *p)',1,0xCBB4ED00,0x03050D00)

/**
 * Call an IEC function from plain C code.
 * Since different CPU's/systems use different calling conventions, this function 
 * should be used as a wrapper.
 * IEC functions or methods of function block use all the same calling convention:
 * They have no return value and exactly one parameter, which is a pointer to a structure that contains all required
 * IN and OUT parameters.
 * RETURN: Returns the runtime system error code (see CmpErrors.library)
 * <SIL2/>
 */
typedef struct tagsyscpucalliecfuncwithparams_struct
{
	RTS_IEC_BYTE *pfIECFunc;			/* VAR_INPUT */	/* Pointer to the IEC function that should be called */
	RTS_IEC_BYTE *pParam;				/* VAR_INPUT */	/* Pointer to the parameter structure that contains the function parameters. Can be 0 if not used. */
	RTS_IEC_UDINT ulSize;				/* VAR_INPUT */	/* Size of the parameter structure to copy the content on stack. Can be 0. */
	RTS_IEC_RESULT SysCpuCallIecFuncWithParams;	/* VAR_OUTPUT */	
} syscpucalliecfuncwithparams_struct;

DEF_API(`void',`CDECL',`syscpucalliecfuncwithparams',`(syscpucalliecfuncwithparams_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x837FB349),0x03050500)

/**
 * <description>
 *  Test and reset a bit in an ULONG variable in one processor step. This operation is to provide
 *	 a multitasking save operation.
 * </description>
 * <result><p>RESULT: Returns the runtime system error code (see CmpErrors.library).
 *	ERR_OK: If bit could be reset and was set before,
 *	ERR_FAILED: If bit is still reset
 * </p></result>
 */
typedef struct tagsyscputestandreset_struct
{
	RTS_IEC_UDINT *pulValue;			/* VAR_INPUT */	/* <param name="pulValue" type="IN">Pointer to the unsigned value to test and reset a bit inside in one atomic
	processor step</param> */
	RTS_IEC_UDINT ulBit;				/* VAR_INPUT */	/* <param name="ulBit" type="IN">Bit number inside the variable to test and reset. 0=first bit, 31=last bit</param> */
	RTS_IEC_RESULT SysCpuTestAndReset;	/* VAR_OUTPUT */	
} syscputestandreset_struct;

DEF_API(`void',`CDECL',`syscputestandreset',`(syscputestandreset_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xCD8E165F),0x03050500)

/**
 * <description>
 *  Test and set a bit in an ULONG variable in one processor step. This operation is to provide
 *	 a multitasking save operation.
 * </description>
 * <result><p>RESULT: Returns the runtime system error code (see CmpErrors.library).
 *	ERR_OK: If bit could be set and was set before,
 *	ERR_FAILED: If bit is still set
 * </p></result>
 */
typedef struct tagsyscputestandset_struct
{
	RTS_IEC_UDINT *pulValue;			/* VAR_INPUT */	/* <param name="pulValue" type="IN">Pointer to the unsigned value to test and set a bit inside in one atomic
	processor step</param> */
	RTS_IEC_UDINT ulBit;				/* VAR_INPUT */	/* <param name="ulBit" type="IN">Bit number inside the variable to test and set. 0=first bit, 31=last bit</param> */
	RTS_IEC_RESULT SysCpuTestAndSet;	/* VAR_OUTPUT */	
} syscputestandset_struct;

DEF_API(`void',`CDECL',`syscputestandset',`(syscputestandset_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xC50F8C00),0x03050500)

/**
 * <description>
 *  <p>The function test and set or clear a bit in a variable in one processor step. This operation must be atomic to provide a multitasking save operation.</p>
 *	<p>IMPLEMENTATION NOTE: Try to use a processor opcode, that provides this operation. If such an opcode
 *	is not available, use SysCpuTestAndSetBitBase in your platform adaptation.</p>
 * </description>
 * <result><p>RESULT: Returns the runtime system error code (see CmpErrors.library).</p>
 *	<ul>
 *		<li>ERR_OK: bSet=1: If bit could be set and was not set before
 *					bSet=0: If bit could be cleared and was set before</li>
 *		<li>ERR_FAILED: bSet=1: If bit is still set
 *						bSet=0: If bit is still cleared</li>
 *		<li>ERR_PARAMETER: If pAddress=NULL or pAddress is unaligned or iBit is out nSize range</li>
 *		<li>ERR_NOT_SUPPORTED: If function is not available because of missing components (e.g. SysInt for locking bit access)</li>
 *		<li>ERR_NOTIMPLEMENTED: If function is not implemented on this platform</li>
 *	</ul>
 * </result>
 * <SIL2/>
 */
typedef struct tagsyscputestandsetbit_struct
{
	RTS_IEC_BYTE *pAddress;				/* VAR_INPUT */	/* <param name="pAddress" type="IN">Pointer to test and set or clear a bit inside in one atomic processor step.
									NOTE: The pointer must be natural aligned! nLen=2: pAddress must be 2Byte aligned; nLen=4: pAddress must be 4Byte aligned</param> */
	RTS_IEC_UDINT nLen;					/* VAR_INPUT */	/* <param name="nLen" type="IN">Size of the value behind the address. Can only be 1 (unsigned char), 2 (unsigned short) or 4 (unsigned long)</param> */
	RTS_IEC_DINT iBit;					/* VAR_INPUT */	/* <param name="iBit" type="IN">Bit number inside the variable to test and set or clear:
	<ul>
		<li>nLen = 1: iBit 0..7</li>
		<li>nLen = 2: iBit 0..15</li>
		<li>nLen = 4: iBit 0..31</li>
	</ul>
 </param> */
	RTS_IEC_DINT bSet;					/* VAR_INPUT */	/* <param name="bSet" type="IN">1=Set bit, 0=Clear bit</param> */
	RTS_IEC_RESULT SysCpuTestAndSetBit;	/* VAR_OUTPUT */	
} syscputestandsetbit_struct;

DEF_API(`void',`CDECL',`syscputestandsetbit',`(syscputestandsetbit_struct *p)',1,0x6A76133F,0x03050D00)

#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/


#ifdef __cplusplus
extern "C" {
#endif

/* Init routines for OS specific modules */
RTS_RESULT CDECL SysCpuHandlingOSInit(INIT_STRUCT *pInit);
RTS_RESULT CDECL SysCpuHandlingOSHookFunction(RTS_UI32 ulHook, RTS_UINTPTR ulParam1, RTS_UINTPTR ulParam2);

/**
 * <description>
 *   On some processors/operating systems this function must be called after code 
 *   has been changed, so that the CPU is notified about the change.
 * </description>
 * <param name="pBaseAddress" type="IN">Start address of the region to be flushed. Set to NULL to flush the
 *	complete instruction cache.</param>
 * <param name="ulSize" type="IN">Length of the region to be flushed. This parameter is ignored if 
 *	pBaseAddress is NULL.</param>
 * <result>error code</result>
 */
DEF_ITF_API(`int', `CDECL', `SysCpuFlushInstructionCache', `(void * pBaseAddress, unsigned long ulSize)')

/**
 * <description>
 *	<p>Call an IEC function from plain C code.
 *	Since different CPU's/systems use different calling conventions, this function 
 *	should be used as a wrapper. But this function respectively the IEC callback code is not synchronized against an OnlineChange of the corresponding application!</p>
 *
 *  <p>ATTENTION: To be safe on multitasking and multicore systems you have to use IecTaskCallIecFuncWithParams() instead (see CmpIecTaskItf.h)!</p>
 *
 *  <p>IEC functions or methods of function block use all the same calling convention:
 *	They have no return value and exactly one parameter, which is a pointer to a structure that contains all required
 *  IN and OUT parameters.</p>
 *
 *	<p>IMPLEMENTATION NOTE: The content of the parameter structure must be copied completely on the stack as 
 *	an input parameter! Don't copy only the pointer! Because of this, the size of the structure is provided as a 
 *	separate parameter to this function. Additionally, the structure of the IEC function must be copied back into the
 *	give parameter to return result values of the IEC function! For all this operations you have to ensure the stack
 *  alignment, but avoid copying more bytes than iSize</p>
 *
 *	<p>IMPLEMENTATION NOTE:
 *	Unused parameter pParam can be NULL, if function has no argument and no result (e.g. CodeInit)!
 *	</p>
 * </description>
 * <param name="pfIECFunc" type="IN" range="[NULL,VALID_IEC_FUNC,INVALID_IEC_FUNC]">Pointer to the IEC function that should be called</param>
 * <param name="pParam" type="INOUT" range="[NULL,VALID_PARAMETER]">Pointer to the parameter structure that contains the function parameters. ATTENTION: Can be NULL!</param>
 * <param name="iSize" type="IN" range="[0,VALID_SIZE]">Size of the parameter structure to copy the content on stack. ATTENTION: Can be 0!</param>
 * <errorcode name="RTS_RESULT Result" type="ERR_OK">Parameter check was successful and pfIECFunc was called</errorcode>
 * <errorcode name="RTS_RESULT Result" type="ERR_PARAMETER">pfIECFunc is NULL or for a parameter size > 0 pParam is NULL</errorcode>
 * <errorcode name="RTS_RESULT Result" type="ERR_NOTIMPLEMENTED">Function is not implemented</errorcode>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `SysCpuCallIecFuncWithParams', `(RTS_VOID_FCTPTR pfIECFunc, void* pParam, int iSize)')

/**
 * <description>
 *	Sets the specified register to the given value inside the 'syscpudebughandler'
 * </description>
 * <param name="pRegBuff" type="IN">Pointer to start of saved registers</param>
 * <param name="nRegisterNumber" type="IN">Register number to be set. See category "Register offsets" for details</param>
 * <param name="newValue" type="IN">The new value</param>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysCpuSetRegisterValue',`(RTS_UINTPTR *pRegBuff, RTS_I32 nRegisterNumber, RTS_UINTPTR newValue)')

/**
 * <description>
 *	<p>Routine is the entry of the IEC code debugger. Is called out of the IEC task if breakpoint is reached.</p>
 *	<p>IMPLEMENTATION NOTE: In this routine, the AppDebugHandler() function of CmpApp must be called with
 *	the appropriate parameters. See CmpAppItf.h for detailed information. The return value of
 *	AppDebugHandler() must be used to set the return address in the IEC code. To this address we will return
 *	when leaving syscpudebughandler().</p>
 * <p>SIL2 IMPLEMENTATION NOTE: This routine may never be reached within safety mode. If it is called in safety mode 
 * an Exception must be generated immediately! The Execution may not proceed to further debug mechanism!</p>
 * </description>
 * <parampseudo name="OperationMode" type="IN" range="[RTS_SIL2_OPMODE_SAFE,RTS_SIL2_OPMODE_DEBUG]">Specifies only that the function should be called</parampseudo>
 * <parampseudo name="bExceptionOccured" type="OUT" range="[TRUE,FALSE]">Specifies, if an exception should occur or not</parampseudo>
 * <result>no return value</result>
 */
DEF_API(`void',`CDECL',`syscpudebughandler',`(void)',1,0)

/**
 * <description>
 *	Routine retrieves the breakpoint opcode for IEC code debugging.
 *	This is CPU dependent and depends additionally on the 
 *	CoDeSys code-generator.
 * </description>
 * <param name="pbyAreaStart" type="IN">Pointer to start of the area.</param>
 * <param name="pbyBPAddress" type="IN">Pointer to breakpoint address (where the breakpoint will be set).
 *	This parameter is used for breakpoints that uses absolute jumps.</param>
 * <param name="pbyOpCode" type="OUT">Pointer to get opcode</param>
 * <param name="piOpcodeSize" type="INOUT">Pointer to maximum size of opcode buffer and return the real size
 *	of the opcode</param>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysCpuGetBreakpointCode',`(unsigned char* pbyAreaStart, unsigned char* pbyBPAddress, unsigned char* pbyOpCode, int *piOpcodeSize)')

/**
 * <description>
 * <p>Routine retrieves an IEC call-stack entry, if the IEC code execution is stopped in the
 * IEC code (breakpoint, exception, etc.). The call-stack can be investigated out of the stack frames of each
 * entered nested function. The first call-stack entry is calculated outside this routine from the 
 * instruction pointer address (IP) that is provided for the AppDebugHandler() routine from syscpudebughandler().
 * All further entries are called from this routine.</p>
 * <p>IMPLEMENTATION NOTE: The stack frame has typically the following structure:</p>
 *  <pre>
 * .         STACK                        CODE
 * .         -----                        ----
 * .
 * .         BP0 /--------|               Fct0:
 * .                      |                    ...
 * .         Return Fct0  |                    Call Fct1
 * .    |--\ BP1 ---------|                    Return Fct0
 * .    |
 * .    |    Return Fct1                  Fct1:
 * .    |--- BP2 /--------|                    ...
 * .         ...          |                    Call Fct2
 * .         Stop         |                    Return Fct1
 * .                      |-- pulBP
 * .                                      Fct2:
 * .                                        ...
 * .                           IP --------/    Stop
 *  </pre>
 * <p>In this example, Fct0 calls Fct1 and Fct1 calls Fct2. This is a nested call with 3 Functions.
 * Inside Fct2 we do a halt (e.g. stop on breakpoint). If we take a look on the stack, we see the return 
 * addresses from Fct0 and Fct1 on the stack. At the entry of each function, the base- (or frame-) pointer
 * is pushed on the stack with the previous content. So you can see, the BP entries on the stack
 * are organized as a chained list from stack-frame to stack frame.</p>
 * <p>The first stack entry is the current position. This is calculated out of the IP address and cannot be 
 * investigated from stack.</p>
 * <p>The pulBP Parameter is a pointer, thats content is the address of the stack, where the BP entry resides.</p>
 * </description>
 * <param name="pBP" type="INOUT">Pointer to last base pointer entry (or frame pointer) and returns
 * the pointer to the next base pointer in the stack frame</param>
 * <param name="ppAddress" type="OUT">Pointer to pointer to return address in the code of the caller</param>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysCpuGetCallstackEntry',`(RTS_UINTPTR *pBP, void **ppAddress)')

/**
 * <description>Routine to retrieve a call-stack entry. The additional parameter bIecCode specifies, if the call-stack
 *	should be retrieved in IEC-code (bIecCode = 1) or in C-code of the runtime system (bIecCode = 0).
 *	IMPLEMENTATION NOTE:
 *	The call-stack in C-code is sometimes compiler dependent and must be implemented here specific to the compiler.
 *  If ERR_NOTIMPLEMENTED is returned, the generic linear back-trace on stack is done in SysCpuHandling.c.
 * </description>
 * <param name="bIecCode" type="IN">Is call-stack expected in IEC- or in runtime-code:
 *		bIecCode=1: Expected in IEC-code
 *		bIecCode=0: Expected in runtime-code (external library call)
 * </param>
 * <param name="pBP" type="INOUT">Pointer to last base pointer entry (or frame pointer) and returns
 *	the pointer to the next base pointer in the stack frame</param>
 * <param name="ppAddress" type="OUT">Pointer to pointer to return address in the code of the caller</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_NOTIMPLEMENTED">If ERR_NOTIMPLEMENTED is returned, the generic linear back-trace on stack is done in SysCpuHandling.c</errorcode>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysCpuGetCallstackEntry2',`(RTS_I32 bIecCode, RTS_UINTPTR *pBP, void **ppAddress)')

/**
 * <description>Routine to retrieve a call-stack entry. The additional parameter bIecCode specifies, if the call-stack
 *	should be retrieved in IEC-code (bIecCode = 1) or in C-code of the runtime system (bIecCode = 0).
 *  We use here first SysCpuGetCallstackEntry2() of the platform adaptation. If it is not implemented, we do a generic
 *	back-trace on the stack.
 * </description>
 * <param name="bIecCode" type="IN">Is call-stack expected in IEC- or in runtime-code:
 *		bIecCode=1: Expected in IEC-code
 *		bIecCode=0: Expected in runtime-code (external library call)
 * </param>
 * <param name="pContext" type="INOUT">Pointer to last base context entry and returns
 *	the pointer to the next context of the stack frame</param>
 * <param name="ppAddress" type="OUT">Pointer to pointer to return address in the code corresponding to the call-stack entry</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Call-stack entry resp. the IEC caller could be detected</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Something failed during detecting the call-stack</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOMEMORY">Call-stack entry resp. the IEC caller could _not_ be detected. Perhaps there is no IEC caller or
 *	the necessary setting in the DeviceDescription is not set for the platform:
 *		 ARM, CortexM3, MIPS, PPC, SH, x86-64 and x86/WindowsCE
 *
 *		 &lt;ts:section name=&quot;codegenerator&quot;&gt;
 *				&lt;ts:setting name=&quot;compiler-defines&quot; type=&quot;string&quot; access=&quot;visible&quot;&gt;
 *					   &lt;ts:value&gt;generate_exceptioninfo&lt;/ts:value&gt;
 *				&lt;/ts:setting&gt;
 *		 &lt;/ts:section&gt; corresponding
 * </errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOT_SUPPORTED">A necessary interface function is not available (CmpApp::AppGetApplicationByAreaAddress)</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">If one of the parameters is invalid</errorcode>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysCpuGetCallstackEntry3',`(RTS_I32 bIecCode, RegContext *pContext, void **ppAddress)')

/**
 * <description>Routine to find pattern on stack</description>
 * <param name="pSP" type="IN">Pointer to stack to start search</param>
 * <param name="pattern" type="IN">Pattern to search for on the stack</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <result>Pointer to the stack, where the pattern was found or NULL if failed</result>
 */
DEF_ITF_API(`RTS_UINTPTR *',`CDECL',`SysCpuSearchOnStack_',`(RTS_UINTPTR *pSP, RTS_UINTPTR pattern, RTS_RESULT *pResult)')

/**
 * <description>Routine to retrieve the instance pointer of an FB. Is used to get an instance specific call-stack.
 *	The position of the instance pointer depends on the CoDeSys code-generator and is CPU dependent.</description>
 * <param name="pBP" type="IN">Pointer to base pointer entry (or frame pointer) </param>
 * <param name="ppInstancePointer" type="OUT">Pointer to pointer to the instance pointer of an FB</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">An instance pointer could be extracted</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">In case of invalid parameters, e.g. NULL pointers</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">In case the instance pointer could not be retrieved</errorcode>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysCpuGetInstancePointer',`(RTS_UINTPTR *pBP, void** ppInstancePointer)')

/**
 * <description>Routine to retrieve the frame pointer for monitoring data access.</description>
 * <param name="pBP" type="INOUT">Pointer to last base pointer entry (or frame pointer) and returns
 *	the pointer on the stack for monitoring data access</param>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysCpuGetMonitoringBase',`(RTS_UINTPTR *pBP)')

/**
 * <description>Obsolete: Use SysCpuTestAndSetBit instead!
 * <p>OBSOLETE function to test and set a bit in an ULONG variable in one processor step. This operation must be atomic to provide
 *	a multitasking save operation.</p>
 *	<p>IMPLEMENTATION NOTE: Try to use a processor opcode, that provides this operation. If such an opcode
 *	is not available, use SysCpuTestAndSetBase in your platform adaptation.</p>
 * </description>
 * <param name="pul" type="IN">Pointer to the unsigned value to test an set a bit inside in one atomic
 *	processor step</param>
 * <parampseudo name="iBitOut" type="OUT">Bit that was really set</parampseudo>
 * <result>Error code:
 *	<ul>
 *		<li>ERR_OK: If bit could be set and was not set before</li>
 *		<li>ERR_FAILED: If bit is still set</li>
 *	</ul>
 * </result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysCpuTestAndSet',`(RTS_UI32* pul, int iBit)')

/**
 * <description>Obsolete: Use SysCpuTestAndSetBit instead!
 * <p>OBSOLETE function to reset a bit in an ULONG variable in one processor step. This operation must be atomic to provide
 *	a multitasking save operation.</p>
 *	<p>IMPLEMENTATION NOTE: Try to use a processor opcode, that provides this operation. If such an opcode
 *	is not available, use SysCpuTestAndResetBase in your platform adaptation.</p>
 * </description>
 * <param name="pul" type="IN">Pointer to the unsigned value to test an reset a bit inside in one atomic
 *	processor step</param>
 * <param name="iBit" type="IN">Bit number inside the variable to test and reset. 0=first bit, 31=last bit</param>
 * <result>
 *	<ul>
 *		<li>ERR_OK: If bit could be reset</li>
 *		<li>ERR_FAILED: If bit reset failed</li>
 *	</ul>
 * </result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysCpuTestAndReset',`(RTS_UI32* pul, int iBit)')

/**
 * <description>
 *  <p>The function tests and sets or clears a bit in a variable in one processor step.
 *  This operation must be atomic to provide a multitasking save operation.
 *  The function returns ERR_FAILED if the bit was already set or reset.</p>
 *  <p>This function is more efficient than the function SysCpuTestAndSetBit2 because it doesn't take care of the memory alignment,
*   but rather expects that the memory pAddress points to is sizeof(int) aligned.</p>
 *	<p>IMPLEMENTATION NOTE: Try to use a processor opcode, that provides this operation. If such an opcode
 *	is not available, use SysCpuTestAndSetBitBase in your platform adaptation.</p>
 * </description>
 * <param name="pAddress" type="IN" range="[NULL,ADDR_ALIGN0,ADDR_ALIGN1,ADDR_ALIGN2,ADDR_ALIGN3]">Pointer to the memory to test and set or clear a bit inside in one atomic processor step.
 *                                                                                                 NOTE: The memory pAddress points to must be sizeof(int) aligned!</param>
 * <param name="nLen" type="IN" range="[1,2,4,INVALID_LEN]">Size of the value behind the address in chars. Can only be 1, 2, or 4.</param>
 * <param name="iBit" type="IN" range="[INT_MIN..0,0..7,8..15,16..31,32..INT_MAX]">Zero-based position of the bit to test within the memory pointed to by pAddress (0=first bit, 31=last bit):
 *	<ul>
 *		<li>nLen = 1: iBit 0..(CHAR_BIT-1)</li>
 *		<li>nLen = 2: iBit 0..(2*CHAR_BIT-1)</li>
 *		<li>nLen = 4: iBit 0..(4*CHAR_BIT-1)</li>
 *	</ul>
 * </param>
 * <param name="bSet" type="IN" range="[0,1]">1=Set bit, 0=Clear bit</param>
 * <errorcode name="RTS_RESULT pResult" type="ERR_OK">Bit could be set/reset successfully</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_FAILED">Bit could not be set/reset successfully, perhaps it already was set/reset</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_PARAMETER">pAddress may not be null and has to be sizeof(int) aligned, nLen may only be 1,2,4, iBit must be in correct range</errorcode>
 * <result>Error code: returns if Bit could be set/reset successfully, or if any  problem occurred</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysCpuTestAndSetBit',`(void* pAddress, int nLen, int iBit, int bSet)')

/**
 * <description>
 *  <p>The function tests and sets or clears a bit in a variable in one processor step.
 *  This operation must be atomic to provide a multitasking save operation.
 *  The function returns ERR_FAILED if the bit was already set or reset.</p>
 *  <p>This function is less efficient than the function SysCpuTestAndSetBit because it doesn't expect that the memory pMemory points to is sizeof(int) aligned
 *  and takes care of the memory alignment.</p>
 *  <p>This function doesn't do any parameter checking.
 *  It expects that the parameter pMemory is not NULL and that the parameter siBit is less than (siLen * CHAR_BIT).</p>
 *	<p>IMPLEMENTATION NOTE: Handle memory alignment and call the function SysCpuTestAndSetBit.</p>
 * </description>
 * <param name="pMemory" type="IN">Pointer to the memory to test and set or clear a bit inside in one atomic processor step.
 *                                    NOTE: There are no alignment requirements for the memory pMemory points to. SysCpuTestAndSetBit2 takes care of this itself. </param>
 * <param name="siLen" type="IN">Size of the value behind the address in chars. Can only be 1, 2, or 4.</param>
 * <param name="siBit" type="IN">Zero-based position of the bit to test within the memory pointed to by pMemory (0=first bit, 31=last bit):
 *	<ul>
 *		<li>nLen = 1: iBit 0..(CHAR_BIT-1)</li>
 *		<li>nLen = 2: iBit 0..(2*CHAR_BIT-1)</li>
 *		<li>nLen = 4: iBit 0..(4*CHAR_BIT-1)</li>
 *	</ul>
 * </param>
 * <param name="bSet" type="IN">TRUE=Set bit, FALSE=Clear bit</param>
 * <errorcode name="RTS_RESULT pResult" type="ERR_OK">Bit could be set/reset successfully</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_FAILED">Bit could not be set/reset successfully, perhaps it already was set/reset</errorcode>
 * <result>Error code: returns if Bit could be set/reset successfully, or if any  problem occurred</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysCpuTestAndSetBit2',`(void *pMemory, RTS_SIZE siLen, RTS_SIZE siBit, RTS_BOOL bSet)')

/**
 * <description>
 *	Get the actual register context.
 * </description>
 * <param name="pContext" type="OUT">Actual register context</param>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysCpuGetContext',`(RegContext *pContext)')

/**
 * <description>
 * <p>Function to increment the content of the given pointer by nSum in one atomic operation (task safe).</p>
 * <p>IMPLEMENTATION NOTE: Add or subtract the value to/from the content of the pointer,
 * and return the value after this operation atomically.</p>
 * </description>
 * <param name="piValue" type="INOUT" range="[NULL,VALID_ATOMICADD_ADDR]">Pointer to the value to increment</param>
 * <param name="nSum" type="IN" range="[RTS_RANGE_OF_RTS_I32]">Summand for the operation. greater 0 to increment, lower 0 to decrement</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT pResult" type="ERR_OK">Call was successful</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_PARAMETER">piValue was NULL</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_NOTIMPLEMENTED">Function is not supported</errorcode>
 * <result>Returns the value after the increment operation in an atomic way!</result>
 */
DEF_ITF_API(`RTS_I32',`CDECL',`SysCpuAtomicAdd',`(RTS_I32 *piValue, RTS_I32 nSum, RTS_RESULT *pResult)')

/**
 * <description>
 * <p>Function to increment the content of the given pointer by nSum in one atomic operation (task safe).</p>
 * <p>IMPLEMENTATION NOTE: Add or subtract the value to/from the content of the pointer,
 * and return the value after this operation atomically.</p>
 * </description>
 * <param name="pi64Value" type="INOUT">Pointer to the value to increment</param>
 * <param name="nSum" type="IN">Summand for the operation. greater 0 to increment, lower 0 to decrement</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT pResult" type="ERR_OK">Call was successful</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_PARAMETER">pi64Value was NULL</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_NOT_SUPPORTED">Function is not supported</errorcode>
 * <result>Returns the value after the increment operation in an atomic way!</result>
 */
DEF_ITF_API(`RTS_I64',`CDECL',`SysCpuAtomicAdd64',`(RTS_I64 *pi64Value, RTS_I64 nSum, RTS_RESULT *pResult)')

/**
 * <description>
 * Function for compare-and-swap in one atomic operation (task safe).
 * Supports only 32- and 64-bit types (i.e. a valid valueSize is 4 or 8)
 * </description>
 * <param name="pAddress" type="INOUT">Pointer to the value to handle</param>
 * <param name="pSwapValue" type="IN">Pointer to the swap value</param>
 * <param name="pCompareValue" type="IN">Pointer to the compare value</param>
 * <param name="valueSize" type="IN">Size of the value in bytes (a valid valueSize is 4 or 8)</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Swap was successful</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Swap was not successful</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">At least one of the pointers was NULL</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOT_SUPPORTED">Swap not supported for this byte size or on this platform</errorcode>
 * <result>Returns error code</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysCpuAtomicCompareAndSwap',`(void *pAddress, void *pSwapValue, void *pCompareValue, RTS_UI8 valueSize)')

/**
 * <description>
 * Function to read a 64bit integer value atomic / consistent.
 * </description>
 * <param name="pSrc" type="IN">Pointer to the value to read</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT pResult" type="ERR_OK">Call was successful</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_PARAMETER">pSrc is NULL</errorcode> 
 * <errorcode name="RTS_RESULT pResult" type="ERR_NOT_SUPPORTED">Atomic function is not supported!</errorcode>
 * <result>Returns the read value</result>
 */
DEF_ITF_API(`RTS_I64',`CDECL',`SysCpuReadInt64',`(RTS_I64 *pSrc, RTS_RESULT *pResult)')

/**
 * <description>
 * Function to write a 64bit integer value atomic / consistent.
 * </description>
 * <param name="pDest" type="IN">Pointer to the value to write</param>
 * <param name="i64Value" type="IN">Value to write</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Call was successful</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">pDest is NULL</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOT_SUPPORTED">Atomic function is not supported!</errorcode>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysCpuWriteInt64',`(RTS_I64 *pDest, RTS_I64 i64Value)')

/**
 * <description>
 * Function to read a 64bit real value atomic / consistent.
 * </description>
 * <param name="pSrc" type="IN">Pointer to the value to read</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT pResult" type="ERR_OK">Call was successful</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_PARAMETER">pSrc is NULL</errorcode> 
 * <errorcode name="RTS_RESULT pResult" type="ERR_NOT_SUPPORTED">Atomic function is not supported!</errorcode>
 * <result>Returns the read value</result>
 */
DEF_ITF_API(`RTS_REAL64',`CDECL',`SysCpuReadReal64',`(RTS_REAL64 *pSrc, RTS_RESULT *pResult)')

/**
 * <description>
 * Function to write a 64bit real value atomic / consistent.
 * </description>
 * <param name="pDest" type="IN">Pointer to the value to write</param>
 * <param name="r64Value" type="IN">Value to write</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Call was successful</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">pDest is NULL</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOT_SUPPORTED">Atomic function is not supported!</errorcode>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysCpuWriteReal64',`(RTS_REAL64 *pDest, RTS_REAL64 r64Value)')

/**
 * <description>
 * This function will write values with 1, 2, 4 or 8 byte size as an atomic operation.
 * Note: pDest has to be aligned according to the nLen parameter. If the alignment isn't correct the function will fail.
 * </description>
 * <param name="pDest" type="IN">Pointer to the destination address. The value will be written to this address. The write operation to this address will be atomic.</param>
 * <param name="pSrc" type="IN">Pointer to the source address. The value will be read from this address.</param>
 * <param name="nLen" type="IN">Size of the value to be written. 1, 2, 4 and 8 will be accepted.</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Call was successful</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">pDest, pSrc is NULL or nLen isn't supported.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOT_SUPPORTED">Atomic function is not supported!</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_ALIGNMENT">pDest was not aligned according to nLen.</errorcode>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysCpuWriteValueAtomic',`(void* pDest, void* pSrc, RTS_UI32 nLen)')

/**
 * <description>
 * This function will read values with 1, 2, 4 or 8 byte size as an atomic operation.
 * Note: pSrc has to be aligned according to the nLen parameter. If the alignment isn't correct the function will fail.
 * </description>
 * <param name="pSrc" type="IN">Pointer to the source address. The value will be read from this address. The read operation from this address will be atomic.</param>
 * <param name="pDst" type="IN">Pointer to the destination address. The value will be written to this address.</param>
 * <param name="nLen" type="IN">Size of the value to be read. 1, 2, 4 and 8 will be accepted.</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Call was successful</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">pSrc or pDest is NULL or nLen isn't supported.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOT_SUPPORTED">Atomic function is not supported!</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_ALIGNMENT">pSrc was not aligned according to nLen.</errorcode>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysCpuReadValueAtomic',`(void* pSrc, void* pDest, RTS_UI32 nLen)')

#ifdef __cplusplus
}
#endif

