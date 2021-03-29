/**
 * <interfacename>SysSem</interfacename>
 * <description> 
 *	<p>The SysSem interface is projected to handle synchronization objects for tasks and threads.
 *	The synchronization objects are called semaphores to synchronize concurrent access to single
 *	data resources.</p>
 *	<p>For example:</p>
 *	<p>	Task1:
 *			...
 *			SysSemEnter(hSem);
 *			[Here you can accessed the protected data]
 *			SysSemLeave(hSem);
 *			[After SysSemLeave() you must not access the protected data]
 *			....
 *	</p>
 *	<p>
 *		IMPLEMENTATION NOTE:
 *		The semaphores must work recursive! That means, that a multiple call out of one task
 *		must not block the execution! For each SysSemEnter() call, a corresponding SysSemLeave()
 *		must be used!
 *		For this feature, binary semaphores are typically used.
 *	</p>
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`SysSem')

#include "CmpStd.h"

/** EXTERN LIB SECTION BEGIN **/

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
RTS_RESULT CDECL SysSemOSInit(INIT_STRUCT *pInit);
RTS_RESULT CDECL SysSemOSHookFunction(RTS_UI32 ulHook, RTS_UINTPTR ulParam1, RTS_UINTPTR ulParam2);

/**
 * <description>
 *	Create a new semaphore object 
 * </description>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <result>Handle to the semaphore</result>
 */
DEF_CREATEITF_API(`RTS_HANDLE',`CDECL',`SysSemCreate',`(RTS_RESULT *pResult)')

/**
 * <description>
 *	Delete a semaphore object 
 * </description>
 * <param name="hSem" type="IN">Handle to the semaphore that is provided from SysSemCreate()</param>
 * <result>error code</result>
 */
DEF_DELETEITF_API(`RTS_RESULT',`CDECL',`SysSemDelete',`(RTS_HANDLE hSem)')

/**
 * <description>
 *  Try to enter the semaphore. If semaphore is available, the function 
 *	entered the semaphore and returned ERR_OK. If semaphore is not available, ERR_FAILED is returned. 
 * </description>
 * <param name="hSem" type="IN">Handle to the semaphore that is provided from SysSemCreate()</param>
 * <result>error code</result>
 */
DEF_HANDLEITF_API(`RTS_RESULT',`CDECL',`SysSemTry',`(RTS_HANDLE hSem)')

/**
 * <description>
 *  Enter the given semaphore. If the semaphore is still entered by another task1, the actual task2 will be blocked,
 *	until the task1 has called SysSemLeave().
 *
 *	IMPLEMENTATION NOTE:
 *		The semaphores must work recursive! That means, that a multiple call out of one task
 *		must not block the execution! For each SysSemEnter() call, a corresponding SysSemLeave()
 *		must be used!
 * </description>
 * <param name="hSem" type="IN">Handle to the semaphore that is provided from SysSemCreate()</param>
 * <result>error code</result>
 */
DEF_HANDLEITF_API(`RTS_RESULT',`CDECL',`SysSemEnter',`(RTS_HANDLE hSem)')

/**
 * <description>
 *  Leave the given semaphore.
 * </description>
 * <param name="hSem" type="IN">Handle to the semaphore that is provided from SysSemCreate()</param>
 * <result>error code</result>
 */
DEF_HANDLEITF_API(`RTS_RESULT',`CDECL',`SysSemLeave',`(RTS_HANDLE hSem)')

#ifdef __cplusplus
}
#endif
