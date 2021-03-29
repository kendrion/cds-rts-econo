/**
 * <interfacename>SysSem_Implementation</interfacename>
 * <description></description>
 *
 * <copyright></copyright>
 */

SET_INTERFACE_NAME(`SysSem_Implementation')
SET_PLACEHOLDER_NAME(`SysSem Implementation')

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

DEF_API(`void',`CDECL',`syssemcreate',`(syssemcreate_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x9344C747),0x03051000)

/**
 * This function deletes the semaphore which is identified by its handle.
 * :return: Return the runtime system error code (see CmpErrors.library)
 */
typedef struct tagsyssemdelete_struct
{
	RTS_IEC_HANDLE hSem;				/* VAR_INPUT */	/* Handle of the semaphore */
	RTS_IEC_RESULT SysSemDelete;		/* VAR_OUTPUT */	
} syssemdelete_struct;

DEF_API(`void',`CDECL',`syssemdelete',`(syssemdelete_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x88B7C7F6),0x03051000)

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

DEF_API(`void',`CDECL',`syssementer',`(syssementer_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x85E1C5F9),0x03051000)

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

DEF_API(`void',`CDECL',`syssemleave',`(syssemleave_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x2AA5DCFF),0x03051000)

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

DEF_API(`void',`CDECL',`syssemtry',`(syssemtry_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x14382CB4),0x03051000)

#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/

