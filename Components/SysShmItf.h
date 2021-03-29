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


	
	
#ifndef _SYSSHMITF_H_
#define _SYSSHMITF_H_

#include "CmpStd.h"

 

 




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
RTS_HANDLE CDECL SysSharedMemoryCreate(char *pszName, RTS_UINTPTR ulPhysicalAddress, RTS_SIZE *puiSize, RTS_RESULT *pResult);
typedef RTS_HANDLE (CDECL * PFSYSSHAREDMEMORYCREATE) (char *pszName, RTS_UINTPTR ulPhysicalAddress, RTS_SIZE *puiSize, RTS_RESULT *pResult);
#if defined(SYSSHM_NOTIMPLEMENTED) || defined(SYSSHAREDMEMORYCREATE_NOTIMPLEMENTED)
	#define USE_SysSharedMemoryCreate
	#define EXT_SysSharedMemoryCreate
	#define GET_SysSharedMemoryCreate(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysSharedMemoryCreate(p0,p1,p2,p3)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_SysSharedMemoryCreate  FALSE
	#define EXP_SysSharedMemoryCreate  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysSharedMemoryCreate
	#define EXT_SysSharedMemoryCreate
	#define GET_SysSharedMemoryCreate(fl)  CAL_CMGETAPI( "SysSharedMemoryCreate" ) 
	#define CAL_SysSharedMemoryCreate  SysSharedMemoryCreate
	#define CHK_SysSharedMemoryCreate  TRUE
	#define EXP_SysSharedMemoryCreate  CAL_CMEXPAPI( "SysSharedMemoryCreate" ) 
#elif defined(MIXED_LINK) && !defined(SYSSHM_EXTERNAL)
	#define USE_SysSharedMemoryCreate
	#define EXT_SysSharedMemoryCreate
	#define GET_SysSharedMemoryCreate(fl)  CAL_CMGETAPI( "SysSharedMemoryCreate" ) 
	#define CAL_SysSharedMemoryCreate  SysSharedMemoryCreate
	#define CHK_SysSharedMemoryCreate  TRUE
	#define EXP_SysSharedMemoryCreate  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysSharedMemoryCreate", (RTS_UINTPTR)SysSharedMemoryCreate, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysShmSysSharedMemoryCreate
	#define EXT_SysShmSysSharedMemoryCreate
	#define GET_SysShmSysSharedMemoryCreate  ERR_OK
	#define CAL_SysShmSysSharedMemoryCreate  ((ISysShm*)s_pfCMCreateInstance(CLASSID_CSysShm, NULL))->ISysSharedMemoryCreate
	#define CHK_SysShmSysSharedMemoryCreate	(s_pfCMCreateInstance != NULL && pISysShm != NULL)
	#define EXP_SysShmSysSharedMemoryCreate  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysSharedMemoryCreate
	#define EXT_SysSharedMemoryCreate
	#define GET_SysSharedMemoryCreate(fl)  CAL_CMGETAPI( "SysSharedMemoryCreate" ) 
	#define CAL_SysSharedMemoryCreate  ((ISysShm*)s_pfCMCreateInstance(CLASSID_CSysShm, NULL))->ISysSharedMemoryCreate
	#define CHK_SysSharedMemoryCreate	(s_pfCMCreateInstance != NULL && pISysShm != NULL)
	#define EXP_SysSharedMemoryCreate  CAL_CMEXPAPI( "SysSharedMemoryCreate" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysSharedMemoryCreate  PFSYSSHAREDMEMORYCREATE pfSysSharedMemoryCreate;
	#define EXT_SysSharedMemoryCreate  extern PFSYSSHAREDMEMORYCREATE pfSysSharedMemoryCreate;
	#define GET_SysSharedMemoryCreate(fl)  s_pfCMGetAPI2( "SysSharedMemoryCreate", (RTS_VOID_FCTPTR *)&pfSysSharedMemoryCreate, (fl), 0, 0)
	#define CAL_SysSharedMemoryCreate  pfSysSharedMemoryCreate
	#define CHK_SysSharedMemoryCreate  (pfSysSharedMemoryCreate != NULL)
	#define EXP_SysSharedMemoryCreate  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysSharedMemoryCreate", (RTS_UINTPTR)SysSharedMemoryCreate, 0, 0) 
#endif




/**
 * <description>
 *  Delete a shared memory object specified by handle
 * </description>
 * <param name="hShm" type="IN">Handle to the shared memory</param>
 * <result>error code</result>
 */
RTS_RESULT CDECL SysSharedMemoryDelete(RTS_HANDLE hShm);
typedef RTS_RESULT (CDECL * PFSYSSHAREDMEMORYDELETE) (RTS_HANDLE hShm);
#if defined(SYSSHM_NOTIMPLEMENTED) || defined(SYSSHAREDMEMORYDELETE_NOTIMPLEMENTED)
	#define USE_SysSharedMemoryDelete
	#define EXT_SysSharedMemoryDelete
	#define GET_SysSharedMemoryDelete(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysSharedMemoryDelete(p0)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_SysSharedMemoryDelete  FALSE
	#define EXP_SysSharedMemoryDelete  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysSharedMemoryDelete
	#define EXT_SysSharedMemoryDelete
	#define GET_SysSharedMemoryDelete(fl)  CAL_CMGETAPI( "SysSharedMemoryDelete" ) 
	#define CAL_SysSharedMemoryDelete  SysSharedMemoryDelete
	#define CHK_SysSharedMemoryDelete  TRUE
	#define EXP_SysSharedMemoryDelete  CAL_CMEXPAPI( "SysSharedMemoryDelete" ) 
#elif defined(MIXED_LINK) && !defined(SYSSHM_EXTERNAL)
	#define USE_SysSharedMemoryDelete
	#define EXT_SysSharedMemoryDelete
	#define GET_SysSharedMemoryDelete(fl)  CAL_CMGETAPI( "SysSharedMemoryDelete" ) 
	#define CAL_SysSharedMemoryDelete  SysSharedMemoryDelete
	#define CHK_SysSharedMemoryDelete  TRUE
	#define EXP_SysSharedMemoryDelete  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysSharedMemoryDelete", (RTS_UINTPTR)SysSharedMemoryDelete, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysShmSysSharedMemoryDelete
	#define EXT_SysShmSysSharedMemoryDelete
	#define GET_SysShmSysSharedMemoryDelete  ERR_OK
	#define CAL_SysShmSysSharedMemoryDelete(p0) (((RTS_HANDLE)p0 == NULL || (RTS_HANDLE)p0 == RTS_INVALID_HANDLE) ? ERR_PARAMETER : ((ISysShm*)p0)->ISysSharedMemoryDelete())
	#define CHK_SysShmSysSharedMemoryDelete  TRUE
	#define EXP_SysShmSysSharedMemoryDelete  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysSharedMemoryDelete
	#define EXT_SysSharedMemoryDelete
	#define GET_SysSharedMemoryDelete(fl)  CAL_CMGETAPI( "SysSharedMemoryDelete" ) 
	#define CAL_SysSharedMemoryDelete(p0) (((RTS_HANDLE)p0 == NULL || (RTS_HANDLE)p0 == RTS_INVALID_HANDLE) ? ERR_PARAMETER : ((ISysShm*)p0)->ISysSharedMemoryDelete())
	#define CHK_SysSharedMemoryDelete  TRUE
	#define EXP_SysSharedMemoryDelete  CAL_CMEXPAPI( "SysSharedMemoryDelete" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysSharedMemoryDelete  PFSYSSHAREDMEMORYDELETE pfSysSharedMemoryDelete;
	#define EXT_SysSharedMemoryDelete  extern PFSYSSHAREDMEMORYDELETE pfSysSharedMemoryDelete;
	#define GET_SysSharedMemoryDelete(fl)  s_pfCMGetAPI2( "SysSharedMemoryDelete", (RTS_VOID_FCTPTR *)&pfSysSharedMemoryDelete, (fl), 0, 0)
	#define CAL_SysSharedMemoryDelete  pfSysSharedMemoryDelete
	#define CHK_SysSharedMemoryDelete  (pfSysSharedMemoryDelete != NULL)
	#define EXP_SysSharedMemoryDelete  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysSharedMemoryDelete", (RTS_UINTPTR)SysSharedMemoryDelete, 0, 0) 
#endif




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
RTS_HANDLE CDECL SysSharedMemoryOpen(char *pszName, RTS_UINTPTR ulPhysicalAddress, RTS_SIZE *puiSize, RTS_RESULT *pResult);
typedef RTS_HANDLE (CDECL * PFSYSSHAREDMEMORYOPEN) (char *pszName, RTS_UINTPTR ulPhysicalAddress, RTS_SIZE *puiSize, RTS_RESULT *pResult);
#if defined(SYSSHM_NOTIMPLEMENTED) || defined(SYSSHAREDMEMORYOPEN_NOTIMPLEMENTED)
	#define USE_SysSharedMemoryOpen
	#define EXT_SysSharedMemoryOpen
	#define GET_SysSharedMemoryOpen(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysSharedMemoryOpen(p0,p1,p2,p3)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_SysSharedMemoryOpen  FALSE
	#define EXP_SysSharedMemoryOpen  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysSharedMemoryOpen
	#define EXT_SysSharedMemoryOpen
	#define GET_SysSharedMemoryOpen(fl)  CAL_CMGETAPI( "SysSharedMemoryOpen" ) 
	#define CAL_SysSharedMemoryOpen  SysSharedMemoryOpen
	#define CHK_SysSharedMemoryOpen  TRUE
	#define EXP_SysSharedMemoryOpen  CAL_CMEXPAPI( "SysSharedMemoryOpen" ) 
#elif defined(MIXED_LINK) && !defined(SYSSHM_EXTERNAL)
	#define USE_SysSharedMemoryOpen
	#define EXT_SysSharedMemoryOpen
	#define GET_SysSharedMemoryOpen(fl)  CAL_CMGETAPI( "SysSharedMemoryOpen" ) 
	#define CAL_SysSharedMemoryOpen  SysSharedMemoryOpen
	#define CHK_SysSharedMemoryOpen  TRUE
	#define EXP_SysSharedMemoryOpen  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysSharedMemoryOpen", (RTS_UINTPTR)SysSharedMemoryOpen, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysShmSysSharedMemoryOpen
	#define EXT_SysShmSysSharedMemoryOpen
	#define GET_SysShmSysSharedMemoryOpen  ERR_OK
	#define CAL_SysShmSysSharedMemoryOpen  ((ISysShm*)s_pfCMCreateInstance(CLASSID_CSysShm, NULL))->ISysSharedMemoryOpen
	#define CHK_SysShmSysSharedMemoryOpen	(s_pfCMCreateInstance != NULL && pISysShm != NULL)
	#define EXP_SysShmSysSharedMemoryOpen  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysSharedMemoryOpen
	#define EXT_SysSharedMemoryOpen
	#define GET_SysSharedMemoryOpen(fl)  CAL_CMGETAPI( "SysSharedMemoryOpen" ) 
	#define CAL_SysSharedMemoryOpen  ((ISysShm*)s_pfCMCreateInstance(CLASSID_CSysShm, NULL))->ISysSharedMemoryOpen
	#define CHK_SysSharedMemoryOpen	(s_pfCMCreateInstance != NULL && pISysShm != NULL)
	#define EXP_SysSharedMemoryOpen  CAL_CMEXPAPI( "SysSharedMemoryOpen" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysSharedMemoryOpen  PFSYSSHAREDMEMORYOPEN pfSysSharedMemoryOpen;
	#define EXT_SysSharedMemoryOpen  extern PFSYSSHAREDMEMORYOPEN pfSysSharedMemoryOpen;
	#define GET_SysSharedMemoryOpen(fl)  s_pfCMGetAPI2( "SysSharedMemoryOpen", (RTS_VOID_FCTPTR *)&pfSysSharedMemoryOpen, (fl), 0, 0)
	#define CAL_SysSharedMemoryOpen  pfSysSharedMemoryOpen
	#define CHK_SysSharedMemoryOpen  (pfSysSharedMemoryOpen != NULL)
	#define EXP_SysSharedMemoryOpen  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysSharedMemoryOpen", (RTS_UINTPTR)SysSharedMemoryOpen, 0, 0) 
#endif




/**
 * <description>
 *  Close a shared memory object specified by handle
 * </description>
 * <param name="hShm" type="IN">Handle to the shared memory</param>
 * <result>error code</result>
 */
RTS_RESULT CDECL SysSharedMemoryClose(RTS_HANDLE hShm);
typedef RTS_RESULT (CDECL * PFSYSSHAREDMEMORYCLOSE) (RTS_HANDLE hShm);
#if defined(SYSSHM_NOTIMPLEMENTED) || defined(SYSSHAREDMEMORYCLOSE_NOTIMPLEMENTED)
	#define USE_SysSharedMemoryClose
	#define EXT_SysSharedMemoryClose
	#define GET_SysSharedMemoryClose(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysSharedMemoryClose(p0)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_SysSharedMemoryClose  FALSE
	#define EXP_SysSharedMemoryClose  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysSharedMemoryClose
	#define EXT_SysSharedMemoryClose
	#define GET_SysSharedMemoryClose(fl)  CAL_CMGETAPI( "SysSharedMemoryClose" ) 
	#define CAL_SysSharedMemoryClose  SysSharedMemoryClose
	#define CHK_SysSharedMemoryClose  TRUE
	#define EXP_SysSharedMemoryClose  CAL_CMEXPAPI( "SysSharedMemoryClose" ) 
#elif defined(MIXED_LINK) && !defined(SYSSHM_EXTERNAL)
	#define USE_SysSharedMemoryClose
	#define EXT_SysSharedMemoryClose
	#define GET_SysSharedMemoryClose(fl)  CAL_CMGETAPI( "SysSharedMemoryClose" ) 
	#define CAL_SysSharedMemoryClose  SysSharedMemoryClose
	#define CHK_SysSharedMemoryClose  TRUE
	#define EXP_SysSharedMemoryClose  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysSharedMemoryClose", (RTS_UINTPTR)SysSharedMemoryClose, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysShmSysSharedMemoryClose
	#define EXT_SysShmSysSharedMemoryClose
	#define GET_SysShmSysSharedMemoryClose  ERR_OK
	#define CAL_SysShmSysSharedMemoryClose(p0) (((RTS_HANDLE)p0 == NULL || (RTS_HANDLE)p0 == RTS_INVALID_HANDLE) ? ERR_PARAMETER : ((ISysShm*)p0)->ISysSharedMemoryClose())
	#define CHK_SysShmSysSharedMemoryClose  TRUE
	#define EXP_SysShmSysSharedMemoryClose  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysSharedMemoryClose
	#define EXT_SysSharedMemoryClose
	#define GET_SysSharedMemoryClose(fl)  CAL_CMGETAPI( "SysSharedMemoryClose" ) 
	#define CAL_SysSharedMemoryClose(p0) (((RTS_HANDLE)p0 == NULL || (RTS_HANDLE)p0 == RTS_INVALID_HANDLE) ? ERR_PARAMETER : ((ISysShm*)p0)->ISysSharedMemoryClose())
	#define CHK_SysSharedMemoryClose  TRUE
	#define EXP_SysSharedMemoryClose  CAL_CMEXPAPI( "SysSharedMemoryClose" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysSharedMemoryClose  PFSYSSHAREDMEMORYCLOSE pfSysSharedMemoryClose;
	#define EXT_SysSharedMemoryClose  extern PFSYSSHAREDMEMORYCLOSE pfSysSharedMemoryClose;
	#define GET_SysSharedMemoryClose(fl)  s_pfCMGetAPI2( "SysSharedMemoryClose", (RTS_VOID_FCTPTR *)&pfSysSharedMemoryClose, (fl), 0, 0)
	#define CAL_SysSharedMemoryClose  pfSysSharedMemoryClose
	#define CHK_SysSharedMemoryClose  (pfSysSharedMemoryClose != NULL)
	#define EXP_SysSharedMemoryClose  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysSharedMemoryClose", (RTS_UINTPTR)SysSharedMemoryClose, 0, 0) 
#endif




/**
 * <description>
 *  Get the pointer to the shared memory
 * </description>
 * <param name="hShm" type="IN">Handle to the shared memory</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <result>Pointer to the shared memory for data access</result>
 */
void * CDECL SysSharedMemoryGetPointer(RTS_HANDLE hShm, RTS_RESULT *pResult);
typedef void * (CDECL * PFSYSSHAREDMEMORYGETPOINTER) (RTS_HANDLE hShm, RTS_RESULT *pResult);
#if defined(SYSSHM_NOTIMPLEMENTED) || defined(SYSSHAREDMEMORYGETPOINTER_NOTIMPLEMENTED)
	#define USE_SysSharedMemoryGetPointer
	#define EXT_SysSharedMemoryGetPointer
	#define GET_SysSharedMemoryGetPointer(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysSharedMemoryGetPointer(p0,p1)  (void *)ERR_NOTIMPLEMENTED
	#define CHK_SysSharedMemoryGetPointer  FALSE
	#define EXP_SysSharedMemoryGetPointer  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysSharedMemoryGetPointer
	#define EXT_SysSharedMemoryGetPointer
	#define GET_SysSharedMemoryGetPointer(fl)  CAL_CMGETAPI( "SysSharedMemoryGetPointer" ) 
	#define CAL_SysSharedMemoryGetPointer  SysSharedMemoryGetPointer
	#define CHK_SysSharedMemoryGetPointer  TRUE
	#define EXP_SysSharedMemoryGetPointer  CAL_CMEXPAPI( "SysSharedMemoryGetPointer" ) 
#elif defined(MIXED_LINK) && !defined(SYSSHM_EXTERNAL)
	#define USE_SysSharedMemoryGetPointer
	#define EXT_SysSharedMemoryGetPointer
	#define GET_SysSharedMemoryGetPointer(fl)  CAL_CMGETAPI( "SysSharedMemoryGetPointer" ) 
	#define CAL_SysSharedMemoryGetPointer  SysSharedMemoryGetPointer
	#define CHK_SysSharedMemoryGetPointer  TRUE
	#define EXP_SysSharedMemoryGetPointer  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysSharedMemoryGetPointer", (RTS_UINTPTR)SysSharedMemoryGetPointer, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysShmSysSharedMemoryGetPointer
	#define EXT_SysShmSysSharedMemoryGetPointer
	#define GET_SysShmSysSharedMemoryGetPointer  ERR_OK
	#define CAL_SysShmSysSharedMemoryGetPointer(p0,p1)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? pISysShm->ISysSharedMemoryGetPointer(p1) : ((ISysShm*)p0)->ISysSharedMemoryGetPointer(p1))
	#define CHK_SysShmSysSharedMemoryGetPointer  (pISysShm != NULL)
	#define EXP_SysShmSysSharedMemoryGetPointer  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysSharedMemoryGetPointer
	#define EXT_SysSharedMemoryGetPointer
	#define GET_SysSharedMemoryGetPointer(fl)  CAL_CMGETAPI( "SysSharedMemoryGetPointer" ) 
	#define CAL_SysSharedMemoryGetPointer(p0,p1)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? pISysShm->ISysSharedMemoryGetPointer(p1) : ((ISysShm*)p0)->ISysSharedMemoryGetPointer(p1))
	#define CHK_SysSharedMemoryGetPointer  (pISysShm != NULL)
	#define EXP_SysSharedMemoryGetPointer  CAL_CMEXPAPI( "SysSharedMemoryGetPointer" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysSharedMemoryGetPointer  PFSYSSHAREDMEMORYGETPOINTER pfSysSharedMemoryGetPointer;
	#define EXT_SysSharedMemoryGetPointer  extern PFSYSSHAREDMEMORYGETPOINTER pfSysSharedMemoryGetPointer;
	#define GET_SysSharedMemoryGetPointer(fl)  s_pfCMGetAPI2( "SysSharedMemoryGetPointer", (RTS_VOID_FCTPTR *)&pfSysSharedMemoryGetPointer, (fl), 0, 0)
	#define CAL_SysSharedMemoryGetPointer  pfSysSharedMemoryGetPointer
	#define CHK_SysSharedMemoryGetPointer  (pfSysSharedMemoryGetPointer != NULL)
	#define EXP_SysSharedMemoryGetPointer  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysSharedMemoryGetPointer", (RTS_UINTPTR)SysSharedMemoryGetPointer, 0, 0) 
#endif




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
RTS_SIZE CDECL SysSharedMemoryRead(RTS_HANDLE hShm, RTS_SIZE ulOffset, unsigned char *pbyData, RTS_SIZE uiSize, RTS_RESULT *pResult);
typedef RTS_SIZE (CDECL * PFSYSSHAREDMEMORYREAD) (RTS_HANDLE hShm, RTS_SIZE ulOffset, unsigned char *pbyData, RTS_SIZE uiSize, RTS_RESULT *pResult);
#if defined(SYSSHM_NOTIMPLEMENTED) || defined(SYSSHAREDMEMORYREAD_NOTIMPLEMENTED)
	#define USE_SysSharedMemoryRead
	#define EXT_SysSharedMemoryRead
	#define GET_SysSharedMemoryRead(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysSharedMemoryRead(p0,p1,p2,p3,p4)  (RTS_SIZE)ERR_NOTIMPLEMENTED
	#define CHK_SysSharedMemoryRead  FALSE
	#define EXP_SysSharedMemoryRead  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysSharedMemoryRead
	#define EXT_SysSharedMemoryRead
	#define GET_SysSharedMemoryRead(fl)  CAL_CMGETAPI( "SysSharedMemoryRead" ) 
	#define CAL_SysSharedMemoryRead  SysSharedMemoryRead
	#define CHK_SysSharedMemoryRead  TRUE
	#define EXP_SysSharedMemoryRead  CAL_CMEXPAPI( "SysSharedMemoryRead" ) 
#elif defined(MIXED_LINK) && !defined(SYSSHM_EXTERNAL)
	#define USE_SysSharedMemoryRead
	#define EXT_SysSharedMemoryRead
	#define GET_SysSharedMemoryRead(fl)  CAL_CMGETAPI( "SysSharedMemoryRead" ) 
	#define CAL_SysSharedMemoryRead  SysSharedMemoryRead
	#define CHK_SysSharedMemoryRead  TRUE
	#define EXP_SysSharedMemoryRead  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysSharedMemoryRead", (RTS_UINTPTR)SysSharedMemoryRead, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysShmSysSharedMemoryRead
	#define EXT_SysShmSysSharedMemoryRead
	#define GET_SysShmSysSharedMemoryRead  ERR_OK
	#define CAL_SysShmSysSharedMemoryRead(p0,p1,p2,p3,p4)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? pISysShm->ISysSharedMemoryRead(p1,p2,p3,p4) : ((ISysShm*)p0)->ISysSharedMemoryRead(p1,p2,p3,p4))
	#define CHK_SysShmSysSharedMemoryRead  (pISysShm != NULL)
	#define EXP_SysShmSysSharedMemoryRead  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysSharedMemoryRead
	#define EXT_SysSharedMemoryRead
	#define GET_SysSharedMemoryRead(fl)  CAL_CMGETAPI( "SysSharedMemoryRead" ) 
	#define CAL_SysSharedMemoryRead(p0,p1,p2,p3,p4)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? pISysShm->ISysSharedMemoryRead(p1,p2,p3,p4) : ((ISysShm*)p0)->ISysSharedMemoryRead(p1,p2,p3,p4))
	#define CHK_SysSharedMemoryRead  (pISysShm != NULL)
	#define EXP_SysSharedMemoryRead  CAL_CMEXPAPI( "SysSharedMemoryRead" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysSharedMemoryRead  PFSYSSHAREDMEMORYREAD pfSysSharedMemoryRead;
	#define EXT_SysSharedMemoryRead  extern PFSYSSHAREDMEMORYREAD pfSysSharedMemoryRead;
	#define GET_SysSharedMemoryRead(fl)  s_pfCMGetAPI2( "SysSharedMemoryRead", (RTS_VOID_FCTPTR *)&pfSysSharedMemoryRead, (fl), 0, 0)
	#define CAL_SysSharedMemoryRead  pfSysSharedMemoryRead
	#define CHK_SysSharedMemoryRead  (pfSysSharedMemoryRead != NULL)
	#define EXP_SysSharedMemoryRead  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysSharedMemoryRead", (RTS_UINTPTR)SysSharedMemoryRead, 0, 0) 
#endif




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
RTS_SIZE CDECL SysSharedMemoryReadByte(RTS_HANDLE hShm, RTS_SIZE ulOffset, unsigned char *pbyData, RTS_SIZE uiSize, RTS_RESULT *pResult);
typedef RTS_SIZE (CDECL * PFSYSSHAREDMEMORYREADBYTE) (RTS_HANDLE hShm, RTS_SIZE ulOffset, unsigned char *pbyData, RTS_SIZE uiSize, RTS_RESULT *pResult);
#if defined(SYSSHM_NOTIMPLEMENTED) || defined(SYSSHAREDMEMORYREADBYTE_NOTIMPLEMENTED)
	#define USE_SysSharedMemoryReadByte
	#define EXT_SysSharedMemoryReadByte
	#define GET_SysSharedMemoryReadByte(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysSharedMemoryReadByte(p0,p1,p2,p3,p4)  (RTS_SIZE)ERR_NOTIMPLEMENTED
	#define CHK_SysSharedMemoryReadByte  FALSE
	#define EXP_SysSharedMemoryReadByte  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysSharedMemoryReadByte
	#define EXT_SysSharedMemoryReadByte
	#define GET_SysSharedMemoryReadByte(fl)  CAL_CMGETAPI( "SysSharedMemoryReadByte" ) 
	#define CAL_SysSharedMemoryReadByte  SysSharedMemoryReadByte
	#define CHK_SysSharedMemoryReadByte  TRUE
	#define EXP_SysSharedMemoryReadByte  CAL_CMEXPAPI( "SysSharedMemoryReadByte" ) 
#elif defined(MIXED_LINK) && !defined(SYSSHM_EXTERNAL)
	#define USE_SysSharedMemoryReadByte
	#define EXT_SysSharedMemoryReadByte
	#define GET_SysSharedMemoryReadByte(fl)  CAL_CMGETAPI( "SysSharedMemoryReadByte" ) 
	#define CAL_SysSharedMemoryReadByte  SysSharedMemoryReadByte
	#define CHK_SysSharedMemoryReadByte  TRUE
	#define EXP_SysSharedMemoryReadByte  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysSharedMemoryReadByte", (RTS_UINTPTR)SysSharedMemoryReadByte, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysShmSysSharedMemoryReadByte
	#define EXT_SysShmSysSharedMemoryReadByte
	#define GET_SysShmSysSharedMemoryReadByte  ERR_OK
	#define CAL_SysShmSysSharedMemoryReadByte(p0,p1,p2,p3,p4)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? pISysShm->ISysSharedMemoryReadByte(p1,p2,p3,p4) : ((ISysShm*)p0)->ISysSharedMemoryReadByte(p1,p2,p3,p4))
	#define CHK_SysShmSysSharedMemoryReadByte  (pISysShm != NULL)
	#define EXP_SysShmSysSharedMemoryReadByte  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysSharedMemoryReadByte
	#define EXT_SysSharedMemoryReadByte
	#define GET_SysSharedMemoryReadByte(fl)  CAL_CMGETAPI( "SysSharedMemoryReadByte" ) 
	#define CAL_SysSharedMemoryReadByte(p0,p1,p2,p3,p4)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? pISysShm->ISysSharedMemoryReadByte(p1,p2,p3,p4) : ((ISysShm*)p0)->ISysSharedMemoryReadByte(p1,p2,p3,p4))
	#define CHK_SysSharedMemoryReadByte  (pISysShm != NULL)
	#define EXP_SysSharedMemoryReadByte  CAL_CMEXPAPI( "SysSharedMemoryReadByte" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysSharedMemoryReadByte  PFSYSSHAREDMEMORYREADBYTE pfSysSharedMemoryReadByte;
	#define EXT_SysSharedMemoryReadByte  extern PFSYSSHAREDMEMORYREADBYTE pfSysSharedMemoryReadByte;
	#define GET_SysSharedMemoryReadByte(fl)  s_pfCMGetAPI2( "SysSharedMemoryReadByte", (RTS_VOID_FCTPTR *)&pfSysSharedMemoryReadByte, (fl), 0, 0)
	#define CAL_SysSharedMemoryReadByte  pfSysSharedMemoryReadByte
	#define CHK_SysSharedMemoryReadByte  (pfSysSharedMemoryReadByte != NULL)
	#define EXP_SysSharedMemoryReadByte  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysSharedMemoryReadByte", (RTS_UINTPTR)SysSharedMemoryReadByte, 0, 0) 
#endif




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
RTS_SIZE CDECL SysSharedMemoryWrite(RTS_HANDLE hShm, RTS_SIZE ulOffset, unsigned char *pbyData, RTS_SIZE uiSize, RTS_RESULT *pResult);
typedef RTS_SIZE (CDECL * PFSYSSHAREDMEMORYWRITE) (RTS_HANDLE hShm, RTS_SIZE ulOffset, unsigned char *pbyData, RTS_SIZE uiSize, RTS_RESULT *pResult);
#if defined(SYSSHM_NOTIMPLEMENTED) || defined(SYSSHAREDMEMORYWRITE_NOTIMPLEMENTED)
	#define USE_SysSharedMemoryWrite
	#define EXT_SysSharedMemoryWrite
	#define GET_SysSharedMemoryWrite(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysSharedMemoryWrite(p0,p1,p2,p3,p4)  (RTS_SIZE)ERR_NOTIMPLEMENTED
	#define CHK_SysSharedMemoryWrite  FALSE
	#define EXP_SysSharedMemoryWrite  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysSharedMemoryWrite
	#define EXT_SysSharedMemoryWrite
	#define GET_SysSharedMemoryWrite(fl)  CAL_CMGETAPI( "SysSharedMemoryWrite" ) 
	#define CAL_SysSharedMemoryWrite  SysSharedMemoryWrite
	#define CHK_SysSharedMemoryWrite  TRUE
	#define EXP_SysSharedMemoryWrite  CAL_CMEXPAPI( "SysSharedMemoryWrite" ) 
#elif defined(MIXED_LINK) && !defined(SYSSHM_EXTERNAL)
	#define USE_SysSharedMemoryWrite
	#define EXT_SysSharedMemoryWrite
	#define GET_SysSharedMemoryWrite(fl)  CAL_CMGETAPI( "SysSharedMemoryWrite" ) 
	#define CAL_SysSharedMemoryWrite  SysSharedMemoryWrite
	#define CHK_SysSharedMemoryWrite  TRUE
	#define EXP_SysSharedMemoryWrite  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysSharedMemoryWrite", (RTS_UINTPTR)SysSharedMemoryWrite, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysShmSysSharedMemoryWrite
	#define EXT_SysShmSysSharedMemoryWrite
	#define GET_SysShmSysSharedMemoryWrite  ERR_OK
	#define CAL_SysShmSysSharedMemoryWrite(p0,p1,p2,p3,p4)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? pISysShm->ISysSharedMemoryWrite(p1,p2,p3,p4) : ((ISysShm*)p0)->ISysSharedMemoryWrite(p1,p2,p3,p4))
	#define CHK_SysShmSysSharedMemoryWrite  (pISysShm != NULL)
	#define EXP_SysShmSysSharedMemoryWrite  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysSharedMemoryWrite
	#define EXT_SysSharedMemoryWrite
	#define GET_SysSharedMemoryWrite(fl)  CAL_CMGETAPI( "SysSharedMemoryWrite" ) 
	#define CAL_SysSharedMemoryWrite(p0,p1,p2,p3,p4)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? pISysShm->ISysSharedMemoryWrite(p1,p2,p3,p4) : ((ISysShm*)p0)->ISysSharedMemoryWrite(p1,p2,p3,p4))
	#define CHK_SysSharedMemoryWrite  (pISysShm != NULL)
	#define EXP_SysSharedMemoryWrite  CAL_CMEXPAPI( "SysSharedMemoryWrite" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysSharedMemoryWrite  PFSYSSHAREDMEMORYWRITE pfSysSharedMemoryWrite;
	#define EXT_SysSharedMemoryWrite  extern PFSYSSHAREDMEMORYWRITE pfSysSharedMemoryWrite;
	#define GET_SysSharedMemoryWrite(fl)  s_pfCMGetAPI2( "SysSharedMemoryWrite", (RTS_VOID_FCTPTR *)&pfSysSharedMemoryWrite, (fl), 0, 0)
	#define CAL_SysSharedMemoryWrite  pfSysSharedMemoryWrite
	#define CHK_SysSharedMemoryWrite  (pfSysSharedMemoryWrite != NULL)
	#define EXP_SysSharedMemoryWrite  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysSharedMemoryWrite", (RTS_UINTPTR)SysSharedMemoryWrite, 0, 0) 
#endif




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
RTS_SIZE CDECL SysSharedMemoryWriteByte(RTS_HANDLE hShm, RTS_SIZE ulOffset, unsigned char *pbyData, RTS_SIZE uiSize, RTS_RESULT *pResult);
typedef RTS_SIZE (CDECL * PFSYSSHAREDMEMORYWRITEBYTE) (RTS_HANDLE hShm, RTS_SIZE ulOffset, unsigned char *pbyData, RTS_SIZE uiSize, RTS_RESULT *pResult);
#if defined(SYSSHM_NOTIMPLEMENTED) || defined(SYSSHAREDMEMORYWRITEBYTE_NOTIMPLEMENTED)
	#define USE_SysSharedMemoryWriteByte
	#define EXT_SysSharedMemoryWriteByte
	#define GET_SysSharedMemoryWriteByte(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysSharedMemoryWriteByte(p0,p1,p2,p3,p4)  (RTS_SIZE)ERR_NOTIMPLEMENTED
	#define CHK_SysSharedMemoryWriteByte  FALSE
	#define EXP_SysSharedMemoryWriteByte  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysSharedMemoryWriteByte
	#define EXT_SysSharedMemoryWriteByte
	#define GET_SysSharedMemoryWriteByte(fl)  CAL_CMGETAPI( "SysSharedMemoryWriteByte" ) 
	#define CAL_SysSharedMemoryWriteByte  SysSharedMemoryWriteByte
	#define CHK_SysSharedMemoryWriteByte  TRUE
	#define EXP_SysSharedMemoryWriteByte  CAL_CMEXPAPI( "SysSharedMemoryWriteByte" ) 
#elif defined(MIXED_LINK) && !defined(SYSSHM_EXTERNAL)
	#define USE_SysSharedMemoryWriteByte
	#define EXT_SysSharedMemoryWriteByte
	#define GET_SysSharedMemoryWriteByte(fl)  CAL_CMGETAPI( "SysSharedMemoryWriteByte" ) 
	#define CAL_SysSharedMemoryWriteByte  SysSharedMemoryWriteByte
	#define CHK_SysSharedMemoryWriteByte  TRUE
	#define EXP_SysSharedMemoryWriteByte  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysSharedMemoryWriteByte", (RTS_UINTPTR)SysSharedMemoryWriteByte, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysShmSysSharedMemoryWriteByte
	#define EXT_SysShmSysSharedMemoryWriteByte
	#define GET_SysShmSysSharedMemoryWriteByte  ERR_OK
	#define CAL_SysShmSysSharedMemoryWriteByte(p0,p1,p2,p3,p4)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? pISysShm->ISysSharedMemoryWriteByte(p1,p2,p3,p4) : ((ISysShm*)p0)->ISysSharedMemoryWriteByte(p1,p2,p3,p4))
	#define CHK_SysShmSysSharedMemoryWriteByte  (pISysShm != NULL)
	#define EXP_SysShmSysSharedMemoryWriteByte  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysSharedMemoryWriteByte
	#define EXT_SysSharedMemoryWriteByte
	#define GET_SysSharedMemoryWriteByte(fl)  CAL_CMGETAPI( "SysSharedMemoryWriteByte" ) 
	#define CAL_SysSharedMemoryWriteByte(p0,p1,p2,p3,p4)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? pISysShm->ISysSharedMemoryWriteByte(p1,p2,p3,p4) : ((ISysShm*)p0)->ISysSharedMemoryWriteByte(p1,p2,p3,p4))
	#define CHK_SysSharedMemoryWriteByte  (pISysShm != NULL)
	#define EXP_SysSharedMemoryWriteByte  CAL_CMEXPAPI( "SysSharedMemoryWriteByte" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysSharedMemoryWriteByte  PFSYSSHAREDMEMORYWRITEBYTE pfSysSharedMemoryWriteByte;
	#define EXT_SysSharedMemoryWriteByte  extern PFSYSSHAREDMEMORYWRITEBYTE pfSysSharedMemoryWriteByte;
	#define GET_SysSharedMemoryWriteByte(fl)  s_pfCMGetAPI2( "SysSharedMemoryWriteByte", (RTS_VOID_FCTPTR *)&pfSysSharedMemoryWriteByte, (fl), 0, 0)
	#define CAL_SysSharedMemoryWriteByte  pfSysSharedMemoryWriteByte
	#define CHK_SysSharedMemoryWriteByte  (pfSysSharedMemoryWriteByte != NULL)
	#define EXP_SysSharedMemoryWriteByte  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysSharedMemoryWriteByte", (RTS_UINTPTR)SysSharedMemoryWriteByte, 0, 0) 
#endif




#ifdef __cplusplus
}
#endif



typedef struct
{
	IBase_C *pBase;
	PFSYSSHAREDMEMORYCREATE ISysSharedMemoryCreate;
 	PFSYSSHAREDMEMORYDELETE ISysSharedMemoryDelete;
 	PFSYSSHAREDMEMORYOPEN ISysSharedMemoryOpen;
 	PFSYSSHAREDMEMORYCLOSE ISysSharedMemoryClose;
 	PFSYSSHAREDMEMORYGETPOINTER ISysSharedMemoryGetPointer;
 	PFSYSSHAREDMEMORYREAD ISysSharedMemoryRead;
 	PFSYSSHAREDMEMORYREADBYTE ISysSharedMemoryReadByte;
 	PFSYSSHAREDMEMORYWRITE ISysSharedMemoryWrite;
 	PFSYSSHAREDMEMORYWRITEBYTE ISysSharedMemoryWriteByte;
 } ISysShm_C;

#ifdef CPLUSPLUS
class ISysShm : public IBase
{
	public:
		virtual RTS_HANDLE CDECL ISysSharedMemoryCreate(char *pszName, RTS_UINTPTR ulPhysicalAddress, RTS_SIZE *puiSize, RTS_RESULT *pResult) =0;
		virtual RTS_RESULT CDECL ISysSharedMemoryDelete(void) =0;
		virtual RTS_HANDLE CDECL ISysSharedMemoryOpen(char *pszName, RTS_UINTPTR ulPhysicalAddress, RTS_SIZE *puiSize, RTS_RESULT *pResult) =0;
		virtual RTS_RESULT CDECL ISysSharedMemoryClose(void) =0;
		virtual void * CDECL ISysSharedMemoryGetPointer(RTS_RESULT *pResult) =0;
		virtual RTS_SIZE CDECL ISysSharedMemoryRead(RTS_SIZE ulOffset, unsigned char *pbyData, RTS_SIZE uiSize, RTS_RESULT *pResult) =0;
		virtual RTS_SIZE CDECL ISysSharedMemoryReadByte(RTS_SIZE ulOffset, unsigned char *pbyData, RTS_SIZE uiSize, RTS_RESULT *pResult) =0;
		virtual RTS_SIZE CDECL ISysSharedMemoryWrite(RTS_SIZE ulOffset, unsigned char *pbyData, RTS_SIZE uiSize, RTS_RESULT *pResult) =0;
		virtual RTS_SIZE CDECL ISysSharedMemoryWriteByte(RTS_SIZE ulOffset, unsigned char *pbyData, RTS_SIZE uiSize, RTS_RESULT *pResult) =0;
};
	#ifndef ITF_SysShm
		#define ITF_SysShm static ISysShm *pISysShm = NULL;
	#endif
	#define EXTITF_SysShm
#else	/*CPLUSPLUS*/
	typedef ISysShm_C		ISysShm;
	#ifndef ITF_SysShm
		#define ITF_SysShm
	#endif
	#define EXTITF_SysShm
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_SYSSHMITF_H_*/
