/**
 * <interfacename>SysShm_Implementation</interfacename>
 * <description></description>
 *
 * <copyright></copyright>
 */

SET_INTERFACE_NAME(`SysShm_Implementation')
SET_PLACEHOLDER_NAME(`SysShm Implementation')

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

DEF_API(`void',`CDECL',`syssharedmemoryclose',`(syssharedmemoryclose_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x93F75F86),0x03051000)

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

DEF_API(`void',`CDECL',`syssharedmemorycreate',`(syssharedmemorycreate_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x9DA848E2),0x03051000)

/**
 * Delete a shared memory object specified by handle
 * RETURN: Returns the runtime system error code (see CmpErrors.library)
 */
typedef struct tagsyssharedmemorydelete_struct
{
	RTS_IEC_HANDLE hShm;				/* VAR_INPUT */	/* Handle to the shared memory */
	RTS_IEC_RESULT SysSharedMemoryDelete;	/* VAR_OUTPUT */	
} syssharedmemorydelete_struct;

DEF_API(`void',`CDECL',`syssharedmemorydelete',`(syssharedmemorydelete_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x83C20043),0x03051000)

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

DEF_API(`void',`CDECL',`syssharedmemorygetpointer',`(syssharedmemorygetpointer_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x94066BAD),0x03051000)

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

DEF_API(`void',`CDECL',`syssharedmemoryopen',`(syssharedmemoryopen_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x41FB9CC1),0x03051000)

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

DEF_API(`void',`CDECL',`syssharedmemoryopen2',`(syssharedmemoryopen2_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x69CA7C0D),0x03051000)

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

DEF_API(`void',`CDECL',`syssharedmemoryread',`(syssharedmemoryread_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x67AB02BB),0x03051000)

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

DEF_API(`void',`CDECL',`syssharedmemoryreadbyte',`(syssharedmemoryreadbyte_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x0E49748E),0x03051000)

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

DEF_API(`void',`CDECL',`syssharedmemorywrite',`(syssharedmemorywrite_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xE23019DB),0x03051000)

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

DEF_API(`void',`CDECL',`syssharedmemorywritebyte',`(syssharedmemorywritebyte_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xF3240E6E),0x03051000)

#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/

