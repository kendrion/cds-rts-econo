/**
 * <interfacename>SysShm</interfacename>
 * <description> 
 *	<p>The SysShm interface is projected to handle access to shared memory.
 *	Shared memory could be physical memory (e.g. IO-cards) or a memory, that can be shared
 *	between several processes or tasks.</p>
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`SysShm')

#include "CmpStd.h"

#ifndef SHM_NUM_OF_STATIC_OBJECTS		
	#define SHM_NUM_OF_STATIC_OBJECTS		5
#endif

/**
 * <category>Static defines</category>
 * <description>Text used as part of the name of a shared memory object, e.g. in IO drivers </description>
 */
#ifndef SHM_PCI_BUSNUMBER_STRING
	#define SHM_PCI_BUSNUMBER_STRING		"_PCIBusNr"
#endif

/**
 * <category>Static defines</category>
 * <description>A special text that can be used to inform that we don't have a PCI bus, 
 * but something to be mapped differently.
 * Example: non-PCI SJA1000 CAN controller under Windows CE
 * Here you have to specify 
 * [CmpSJACanDrv] 
 * 0.Name=NoPCIBus
 * </description>
 */
#ifndef SHM_NO_PCI_BUS_STRING
	#define SHM_NO_PCI_BUS_STRING		"NoPCIBus"
#endif


/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>
 * Use MapPhysical Flag for memory mapping. Only used for WinCE.
 * 0: Do not use the flag
 * 1: Use the flag
 * </description>
 */
#define	SYSSHMKEY_INT_WINCE_MAP_PHYSICAL					"WinCE.MapPhysical"
#define	SYSSHMVALUE_INT_WINCE_DEFAULT_MAP_PHYSICAL			0

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>
 * Do not use PAGE_PHYSICAL Flag for the call of VirtualAllocCopyEx in the memory mapping. Only used for WinCE.
 * 0: The PAGE_PHYSICAL Flag for VirtualAllocCopyEx is used if WinCE.MapPhysical is set
 * 1: The PAGE_PHYSICAL Flag for VirtualAllocCopyEx is not used also if WinCE.MapPhysical is set
 * </description>
 */
#define	SYSSHMKEY_INT_WINCE_DISABLE_MAP_PHYSICAL_IN_VIRTUALALLOCCOPYEX					"WinCE.DisableMapPhysicalInVirtualAllocCopyEx"
#define	SYSSHMVALUE_INT_WINCE_DEFAULT_DISABLE_MAP_PHYSICAL_IN_VIRTUALALLOCCOPYEX		0

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>
 * Do not use PAGE_PHYSICAL access protection flag for the call of VirtualAllocCopyEx and VirtualCopy in the memory mapping.
 * Default: 0.
 * Only used for WinCE.
 * 0: Use the PAGE_NOCACHE access protection flag for VirtualAllocCopyEx and VirtualCopy.
 * 1: Do not use the PAGE_NOCACHE access protection flag for VirtualAllocCopyEx and VirtualCopy.
 * </description>
 */
#define	SYSSHMKEY_INT_WINCE_CACHED_MEM_MAPPING					"WinCE.CachedMemMapping"
#define	SYSSHMVALUE_INT_WINCE_DEFAULT_CACHED_MEM_MAPPING		0

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>
 * Change the kernel memory's access permissions to "Full access" and its page attributes to "write-through/no write allocate" for direct kernel memory access from user space.
 * Default: 0.
 * Only used for WinCE.
 * 0: Do not set kernel memory attributes "full permission" and "write-through/no write-allocation".
 * 1: Set kernel memory attributes: "full permission" and "write-through/no write-allocation".
 * </description>
 */
#define	SYSSHMKEY_INT_WINCE_DIRECT_KERNELMEM_ACCESS					"WinCE.DirectKernelMemAccess"
#define	SYSSHMVALUE_INT_WINCE_DEFAULT_DIRECT_KERNELMEM_ACCESS		0

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>
 * Use an Divisor to calculate the mapping address. Only used for WinCE.
 * 1: Default. Do not use 0
 * </description>
 */
#define	SYSSHMKEY_INT_WINCE_PHYSICAL_ADDRESS_DIVISOR				"WinCE.DividePhysicalAddressBy"
#define	SYSSHMVALUE_INT_WINCE_DEFAULT_PHYSICAL_ADDRESS_DIVISOR		1

/**
 * <category>Shared memory object</category>
 * <element name="pszName" type="IN">Name of the shared memory</element>
 * <element name="ulPhysicalAddress" type="IN">Physical memory address</element>
 * <element name="pMemory" type="IN">Pointer to the shared memory</element>
 * <element name="uiSize" type="IN">Size of the shared memory</element>
 * <element name="iRefCount" type="IN">Reference counter to store number of used clients</element>
 * <element name="ulHandle" type="IN">Operating system handle to the shared memory</element>
 */
typedef struct
{
	char* pszName;
	RTS_UINTPTR ulPhysicalAddress;
	void* pMemory;
	RTS_SIZE uiSize;
	int iRefCount;
	RTS_HANDLE ulHandle;
} SHM_OBJECT;

/** EXTERN LIB SECTION BEGIN **/

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/



#ifndef CDECL
	#define CDECL
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Initialization routines for OS specific modules */
RTS_RESULT CDECL SysSharedMemoryOSInit(INIT_STRUCT *pInit);
RTS_RESULT CDECL SysSharedMemoryOSHookFunction(RTS_UI32 ulHook, RTS_UINTPTR ulParam1, RTS_UINTPTR ulParam2);

/**
 * <description>
 *  Create a new shared memory object specified by name.
 *	IMPLEMENTATION NOTE:
 *	If the shared memory object still exists, a valid handle is returned, but with the error code ERR_DUPLICATE.
 * </description>
 * <param name="pszName" type="IN">Name of the shared memory</param>
 * <param name="ulPhysicalAddress" type="IN">Optional physical address:
 *	ulPhysicalAddress > 0: The shared memory will be mapped on this physical address
 *	ulPhysicalAddress = 0: A new shared memory will created without a specified physical address</param>
 * <param name="puiSize" type="INOUT">Pointer to requested size of the shared memory</param>
 * <param name="pResult" type="OUT">Pointer to error code:
 *	ERR_OK: Succeeded
 *	ERR_DUPLICATE: Shared memory object still exists. A valid handle to this object is returned here!
 *	ERR_NOMEMORY: No memory available on the heap to allocate a management structure
 *	ERR_FAILED: Failed to open the shared memory
 *	ERR_PARAMETER: If one of the parameter is invalid (pszName = NULL or puiSize = NULL)
 *	ERR_BUFFERSIZE: If shared memory with this name exist, but the requested size is different
 *		from the available size. In this case, *puiSize returns the available size,
 *		but return handle is RTS_INVALID_HANDLE.
 * </param>
 * <result>Handle to the shared memory object or RTS_INVALID_HANDLE if failed</result>
 */
DEF_CREATEITF_API(`RTS_HANDLE',`CDECL',`SysSharedMemoryCreate',`(char *pszName, RTS_UINTPTR ulPhysicalAddress, RTS_SIZE *puiSize, RTS_RESULT *pResult)')

/**
 * <description>
 *  Delete a shared memory object specified by handle
 * </description>
 * <param name="hShm" type="IN">Handle to the shared memory</param>
 * <result>error code</result>
 */
DEF_DELETEITF_API(`RTS_RESULT',`CDECL',`SysSharedMemoryDelete',`(RTS_HANDLE hShm)')

/**
 * <description>
 *  Opens an existing shared memory object specified by name.
 *	IMPLEMENTATION NOTE:
 *	If shared memory object not exists, an error code is returned an it is not created!
 * </description>
 * <param name="pszName" type="IN">Name of the shared memory</param>
 * <param name="ulPhysicalAddress" type="IN">Optional physical address:
 *	ulPhysicalAddress > 0: The shared memory will be mapped on this physical address
 *	ulPhysicalAddress = 0: An existing shared memory will be opened without a specified physical address</param>
 * <param name="puiSize" type="INOUT">Pointer to requested size of the shared memory.
 *				Size must match to the existing shared memory object size!</param>
 * <param name="pResult" type="OUT">Pointer to error code:
 *	ERR_OK: Succeeded
 *	ERR_NO_OBJECT: If shared memory does not exist.
 *	ERR_NOMEMORY: No memory available on the heap to allocate a management structure
 *	ERR_FAILED: Failed to open the shared memory
 *	ERR_PARAMETER: If one of the parameter is invalid (pszName = NULL or puiSize = NULL)
 *	ERR_BUFFERSIZE: If shared memory with this name exist, but the requested size is different
 *		from the available size. In this case, *puiSize returns the available size,
 *		but return handle is RTS_INVALID_HANDLE.
 * </param>
 * <result>Handle to the shared memory object or RTS_INVALID_HANDLE if failed</result>
 */
DEF_CREATEITF_API(`RTS_HANDLE',`CDECL',`SysSharedMemoryOpen',`(char *pszName, RTS_UINTPTR ulPhysicalAddress, RTS_SIZE *puiSize, RTS_RESULT *pResult)')

/**
 * <description>
 *  Close a shared memory object specified by handle
 * </description>
 * <param name="hShm" type="IN">Handle to the shared memory</param>
 * <result>error code</result>
 */
DEF_DELETEITF_API(`RTS_RESULT',`CDECL',`SysSharedMemoryClose',`(RTS_HANDLE hShm)')

/**
 * <description>
 *  Get the pointer to the shared memory
 * </description>
 * <param name="hShm" type="IN">Handle to the shared memory</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <result>Pointer to the shared memory for data access</result>
 */
DEF_HANDLEITF_API(`void *',`CDECL',`SysSharedMemoryGetPointer',`(RTS_HANDLE hShm, RTS_RESULT *pResult)')

/**
 * <description>
 *	Routine to read values from shared memory,
 *	ulOffset: offset in the shared memory
 *	pbyData: Pointer to the buffer to read in values
 *	ulSize: number of bytes to read
 * </description>
 * <param name="hShm" type="IN">Handle to the shared memory</param>
 * <param name="ulOffset" type="IN">Offset in the shared memory</param>
 * <param name="pbyData" type="OUT">Pointer to buffer to read in data</param>
 * <param name="uiSize" type="IN">Number of bytes to read</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <result>Number of bytes read from the shared memory</result>
 */
DEF_HANDLEITF_API(`RTS_SIZE',`CDECL',`SysSharedMemoryRead',`(RTS_HANDLE hShm, RTS_SIZE ulOffset, unsigned char *pbyData, RTS_SIZE uiSize, RTS_RESULT *pResult)')

/**
 * <description>
 *	This function can be used to read "byte-wise" a defined number of bytes, starting at a certain offset.
 * </description>
 * <param name="hShm" type="IN">Handle to the shared memory</param>
 * <param name="ulOffset" type="IN">Offset in the shared memory</param>
 * <param name="pbyData" type="OUT">Pointer to buffer to read in data</param>
 * <param name="uiSize" type="IN">Number of bytes to read</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <result>Number of bytes read from the shared memory</result>
 */
DEF_HANDLEITF_API(`RTS_SIZE',`CDECL',`SysSharedMemoryReadByte',`(RTS_HANDLE hShm, RTS_SIZE ulOffset, unsigned char *pbyData, RTS_SIZE uiSize, RTS_RESULT *pResult)')

/**
 * <description>
 *	Routine to write values to shared memory,
 * </description>
 * <param name="hShm" type="IN">Handle to the shared memory</param>
 * <param name="ulOffset" type="IN">Offset in the shared memory</param>
 * <param name="pbyData" type="IN">Pointer to buffer with write data</param>
 * <param name="uiSize" type="IN">Number of bytes to write</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <result>Number of bytes written to the shared memory</result>
 */
DEF_HANDLEITF_API(`RTS_SIZE',`CDECL',`SysSharedMemoryWrite',`(RTS_HANDLE hShm, RTS_SIZE ulOffset, unsigned char *pbyData, RTS_SIZE uiSize, RTS_RESULT *pResult)')

/**
 * <description>
 *	This function can be used to write a defined number of bytes in "byte-wise" manner to a Shared Memory area, starting at a certain offset address.
 * </description>
 * <param name="hShm" type="IN">Handle to the shared memory</param>
 * <param name="ulOffset" type="IN">Offset in the shared memory</param>
 * <param name="pbyData" type="IN">Pointer to buffer with write data</param>
 * <param name="uiSize" type="IN">Number of bytes to write</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <result>Number of bytes written to the shared memory</result>
 */
DEF_HANDLEITF_API(`RTS_SIZE',`CDECL',`SysSharedMemoryWriteByte',`(RTS_HANDLE hShm, RTS_SIZE ulOffset, unsigned char *pbyData, RTS_SIZE uiSize, RTS_RESULT *pResult)')

#ifdef __cplusplus
}
#endif
