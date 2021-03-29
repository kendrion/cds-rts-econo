/**
 * <interfacename>CmpMemPool</interfacename>
 * <description>
 *  <p>Interface of the memory pool manager to handle static and dynamic memory blocks</p>
 *
 *  <p>A MemPool has the following structure:</p>
 *  <pre>
 *  
 *  -------------- Pool Control Block                -------------- Block Control Block
 *  |nRefCount   |  Reference Counter                |pBCB        |  Pointer to next BCB
 *  |Blocksize   |  data size of single block        |pPCB        |  Pointer to PCB
 *  |pBlocksInUse|  List of used blocks              `------------'
 *  |pBCB        |  List of free blocks              
 *  |...         |
 *  `-------------
 * 
 *                       provided
 *                       Memory Area
 *                       .--------------------------.
 *                       | PCB                      |
 *    List of free Blocks|  Blocksize               |      List of used Blocks
 *                       |  pBlocksInUse            |===========.
 *          .=========== |  pBCB                    |           |
 *          |            |......................... |           |
 *          |            | BCB                      | &lt;========='
 *          |            |                          | ---.
 *          |            |......................... |    |
 *          |            | DATA                     |    |
 *          |            |                          |    |
 *          |            |......................... |    |
 *          |            | BCB                      | &lt;--'
 *          |            |                          | ---.
 *          |            |......................... |    |
 *          |            | DATA                     |    |
 *          |            |                          |    |
 *          |            |......................... |    |
 *          |            |                          | &lt;--'
 *          |           ~~~                        ~~~
 *          |
 *          |           ~~~                        ~~~
 *          '=========&gt;  |......................... |
 *                       | BCB                      | ---.
 *                       |                          |    |
 *                       |......................... |    |
 *                       | DATA                     |    |
 *                       |                          |    |
 *                       |......................... | &lt;--'
 *                       | BCB                      | ---.
 *                       |                          |    |
 *                      ~~~                        ~~   ~~~
 * 
 *                      ~~~                        ~~~
 *                       |                          |
 *                       |                          |
 *                       .--------------------------.
 *                       End of Memory Area
 * 
 * 
 * </pre>
 * 
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`CmpMemPool')

/**
 * <category>Compiler switch</category>
 * <description>
 *	Compiler switches configure the behavior of the memory pool.
 * </description>
 * <element name="MEMPOOL_DISABLE_HEAP_MEMORY">Switch to disable dynamic memory</element>
 * <element name="MEMPOOL_8BYTE_ALIGNED">Force 8 byte alignment of blocks. Note, that this doesn't affect the alignment of the header.</element>
 */

#ifdef RTS_MEMPOOL_VER2
	#error RTS_MEMPOOL_VER2 no longer supported!
#endif


#if !defined(MEMPOOL_8BYTE_ALIGNED) && !defined(RTS_DISABLE_64BIT_SUPPORT)
	#define MEMPOOL_8BYTE_ALIGNED
#endif

#ifndef MEMPOOL_HEADER_ALIGNMENT
	#define MEMPOOL_HEADER_ALIGNMENT 4
#endif
#ifdef MEMPOOL_8BYTE_ALIGNED
	#define MEMPOOL_BLOCK_ALIGNMENT  8
#else
	#define MEMPOOL_BLOCK_ALIGNMENT			sizeof(void*)
#endif

/* Init value to write over a deleted object */
#ifndef MEMPOOL_INIT_VALUE
	#define MEMPOOL_INIT_VALUE		0xAA
#endif


/**
 * <category>Macros</category>
 * <description>Macros to handle static size of a MemPool</description>
 * <element name="MEM_GET_STATIC_LEN" type="IN">Can be use to calculate the gross size of a static MemPool by specifying the structure of one element.
 *  Usage:
 *		#define NUM_OF_STATIC_ELEMENTS		10
 *		typedef struct
 *		{
 *			...
 *		} StructNameOfOneElement;
 *		static RTS_UI8 s_StaticMemPool[MEM_GET_STATIC_LEN(NUM_OF_STATIC_ELEMENTS, StructNameOfOneElement)];
 * </element>
 * <element name="MEM_GET_STATIC_LEN_" type="IN">Can be use to calculate the gross size of a static MemPool by specifying the size of one element.
 *  Usage:
 *		#define NUM_OF_STATIC_ELEMENTS		10
 *		typedef struct
 *		{
 *			...
 *		} StructNameOfOneElement;
 *		static RTS_UI8 s_StaticMemPool[MEM_GET_STATIC_LEN_(NUM_OF_STATIC_ELEMENTS, sizeof(StructNameOfOneElement))];
 * </element>
 */
#define MEM_GET_STATIC_LEN(Num, Struct)				(sizeof(RTS_PCB) + 2 * MEMPOOL_BLOCK_ALIGNMENT + (Num) * ALIGN_SIZE(sizeof(Struct), MEMPOOL_BLOCK_ALIGNMENT) + (Num) * sizeof(RTS_BCB))
#define MEM_GET_STATIC_LEN_(Num, Size)				(sizeof(RTS_PCB) + 2 * MEMPOOL_BLOCK_ALIGNMENT + (Num) * ALIGN_SIZE(Size, MEMPOOL_BLOCK_ALIGNMENT) + (Num) * sizeof(RTS_BCB))
#define MEM_GET_STATIC_LEN2(Num, Size, HeaderType)	(sizeof(HeaderType) + 2 * MEMPOOL_BLOCK_ALIGNMENT + (Num) * ALIGN_SIZE(Size, MEMPOOL_BLOCK_ALIGNMENT) + (Num) * sizeof(RTS_BCB))

/**
 * <category>Static defines</category>
 * <description>Flags for a single MemPool block</description>
 * <element name="MEM_POOL_FLAGS_BLOCK_NONE" type="IN">No flag specified</element>
 * <element name="MEM_POOL_FLAGS_BLOCK_DELETE" type="IN">Block is marked to delete at the next possible moment, if nobody is using the MemPool!</element>
 */
#define MEM_POOL_FLAGS_BLOCK_NONE			0x00000000
#define MEM_POOL_FLAGS_BLOCK_DELETE			0x00000001

#define MEM_POOL_FLAGS_BLOCK_IS_DELETE(pBCB) ((pBCB->flags & MEM_POOL_FLAGS_BLOCK_DELETE) != 0)

/*
 * <SIL2/>
 * <description>Block Control Block</description>
 */
typedef struct RTS_BCBtag
{
	struct RTS_BCBtag *pBCB;	/* Pointer to next free or used block control block */
	struct RTS_PCBtag *pPCB;	/* Pointer to pool control block */
	RTS_UI32 flags;
#if defined(MEMPOOL_8BYTE_ALIGNED)
	RTS_UI32 alignment;
#endif
} RTS_BCB;

/**
 * <category>MemPool types</category>
 * <description>Type of a MemPool</description>
 */

/**
 * <category>MemPool options</category>
 * <description>MemPool options</description>
 * <element name="MEM_POOL_OPTION_STATIC" type="IN">MemPool based on a static array</element>
 * <element name="MEM_POOL_OPTION_DYNAMIC" type="IN">MemPool based on a dynamic allocated heap block</element>
 * <element name="MEM_POOL_OPTION_NOSYNC" type="IN">No synchronization necessary within the MemPool</element>
 * <element name="MEM_POOL_OPTION_UNALIGNED" type="IN">Marks the MemPool as unaligned, if the beginning of the aligned pPool is not identical to the pHeapMemory pointer!</element>
 */
#define MEM_POOL_OPTION_STATIC				0x00000001
#define MEM_POOL_OPTION_DYNAMIC				0x00000002
#define MEM_POOL_OPTION_NOSYNC				0x00000010		
#define MEM_POOL_OPTION_UNALIGNED			0x00000100


/**
 * The following macros can be used with a pointer to a PEB, PCB or MemPoolConfiguraion structure.
 * They all have the same ->options member, on which we are operating.
 */
#define MEM_POOL_OPTION_IS_STATIC(pConfiguration)  ((pConfiguration->options & MEM_POOL_OPTION_STATIC) != 0)
#define MEM_POOL_OPTION_IS_DYNAMIC(pConfiguration) ((pConfiguration->options & MEM_POOL_OPTION_DYNAMIC) != 0)
#define MEM_POOL_OPTION_IS_NOSYNC(pConfiguration)  ((pConfiguration->options & MEM_POOL_OPTION_NOSYNC) != 0)

#define MEM_POOL_OPTION_SET_STATIC(pConfiguration)  do { pConfiguration->options |= MEM_POOL_OPTION_STATIC;  } while(0)
#define MEM_POOL_OPTION_SET_DYNAMIC(pConfiguration) do { pConfiguration->options |= MEM_POOL_OPTION_DYNAMIC; } while(0)
#define MEM_POOL_OPTION_SET_NOSYNC(pConfiguration)  do { pConfiguration->options |= MEM_POOL_OPTION_NOSYNC;  } while(0)

#define MEM_POOL_OPTION_RESET_STATIC(pConfiguration)  do { pConfiguration->options &= ~MEM_POOL_OPTION_STATIC;  } while(0)
#define MEM_POOL_OPTION_RESET_DYNAMIC(pConfiguration) do { pConfiguration->options &= ~MEM_POOL_OPTION_DYNAMIC; } while(0)
#define MEM_POOL_OPTION_RESET_NOSYNC(pConfiguration)  do { pConfiguration->options &= ~MEM_POOL_OPTION_NOSYNC;  } while(0)

/**
 * <SIL2/> 
 * <category>Extension block</category>
 * <description>Pool Extension Block</description>
 * <element name="options" type="IN">Flags for internal usage of the MemPool. See the category "MemPool options" for detailed information</element>
 * <element name="pPEB" type="IN">Pointer to the extension block (heap/dynamic) or NULL</element>
 */
typedef struct RTS_PEBtag
{
	RTS_UI32 options;
#if defined(MEMPOOL_8BYTE_ALIGNED) && defined(TRG_64BIT)
	RTS_UI32 alignment;
#endif
	struct RTS_PEBtag *pPEB;
} RTS_PEB;

/**
 * <category>Static defines</category>
 * <description>Delete function pointer definition which is called optional to delete a MemPool block. Can be specified in MemPoolCreate().</description>
 * <param name="pBlock" type="IN">Pointer to the MemPool block</param>
 * <param name="pParam" type="IN">Pointer to a parameter which can be specified in MemPoolPutBlock_LF() as second parameter!</param>
 */
typedef void (CDECL *PF_MEMBLOCK_DELETEFUNCTION)(void *pBlock, void *pParam);

/**
 * <SIL2/>
 * <category>MemPool definition</category>
 * <description>Pool Control Block. This is the header within a MemPool to manage it.
 *	ATTENTION:
 *	- This structure members are managed by the CmpMemPool and so don't modify these entries directly!!!!!
 * </description>
 * <element name="ulBlockSize" type="IN">Block size of each pool block</element>
 * <element name="pfDeleteFunction" type="IN">Delete function pointer which is called optional to delete a MemPool block</element>
 * <element name="nRefCount" type="IN">Reference counter which is incremented with MemPoolAddRef_LF() and is decremented with MemPoolReleaseRef_LF() to prevent, that the chain of used
 *	blocks is not changed during iteration over all elements.
 * </element>
 * <element name="options" type="IN">Options of the MemPool. See the category "MemPool options" for detailed information</element>
 * <element name="lock" type="IN">Is used to hold the specified locking primitive resource</element>
 * <element name="pPEB" type="IN">Pointer to next extension block</element>
 * <element name="pBCB" type="IN">Pointer to free block list</element>
 * <element name="pBlocksInUse" type="IN">Pointer to first block in use resp. the linked chain of used blocks!</element>
 * <element name="pTail" type="IN">Pointer to tail block in chain of used blocks!</element>
 */
typedef struct RTS_PCBtag
{
	RTS_SIZE ulBlockSize;
	PF_MEMBLOCK_DELETEFUNCTION pfDeleteFunction;
	RTS_I32 nRefCount;
	RTS_UI32 options;
	
	union
	{
		RTS_HANDLE	hSem;
		RTS_UINTPTR	mask;
	} lock;

	struct RTS_PEBtag *pPEB;
	struct RTS_BCBtag *pBCB;
	struct RTS_BCBtag *pBlocksInUse;
	struct RTS_BCBtag *pTail;

#if defined(MEMPOOL_8BYTE_ALIGNED) && !defined(TRG_64BIT)
	RTS_UI32 alignment;
#endif
} RTS_PCB;

/**
 * <SIL2/>
 * <category>MemPool iterator</category>
 * <description>Object to iterate of used blocks of a MemPool.
 *	ATTENTION:
 *	- This structure members are managed by the CmpMemPool and so don't modify these entries directly!!!!!
 * </description>
 * <element name="pHead" type="IN">Points to the head element of the chain list</element>
 * <element name="pNext" type="IN">Points to the next element in the chain list</element>
 */
typedef struct
{
	RTS_BCB *pHead;
	RTS_BCB *pNext;
} MemIterator;


/**
 * <category>Static defines</category>
 * <description>Macros to check MemPool contents</description>
 * <element name="MEMPOOL_IS_NOT_EMPTY" type="IN">Macro to check if a MemPool is _not_ empty</element>
 * <element name="MEMPOOL_IS_EMPTY" type="IN">Macro to check if a MemPool is empty</element>
 * <element name="MEMPOOL_HAS_FREE_BLOCKS" type="IN">Macro to check if a MemPool has free block that can be used</element>
 */
#define MEMPOOL_IS_NOT_EMPTY(pPool)		((((RTS_PCB *)pPool)->pBlocksInUse) != NULL)
#define MEMPOOL_IS_EMPTY(pPool)			((((RTS_PCB *)pPool)->pBlocksInUse) == NULL)
#define MEMPOOL_HAS_FREE_BLOCKS(pPool)	(((RTS_PCB *)pPool)->pPEB) != NULL || ((RTS_PCB *)pPool)->pBCB) != NULL)

/**
 * <category>Static defines</category>
 * <description>Macros to iterate over a MemPool</description>
 * <element name="MEM_GET_FIRST" type="IN">Get first block element of a MemPool</element>
 * <element name="MEM_GET_NEXT" type="IN">Get next block element of a MemPool</element>
 * <element name="MEM_GET_DATA" type="IN">Get data pointer of a MemPool block _including_ blocks which are still marked as deleted!</element>
 * <element name="MEM_GET_DATA_SKIP_DELETE" type="IN">Get data pointer of a MemPool block _without_ a block marked as "to delete"!
 *		A block is marked as "to delete", if MemPoolRemoveUsedBlock() was called during somebody else iterated over the pool. And so the block is only marked as "to delete" and should be deleted in the next 
 *		suitable moment.
 *
 *		NOTE:
 *		For blocks which are still marked as deleted, you get a NULL pointer here!</element>
 */
#define MEM_GET_BCB_FROM_BLOCK(pBlock)		((RTS_BCB*)((RTS_UI8*)pBlock - sizeof(RTS_BCB)))
#define MEM_GET_BLOCK_FROM_BCB(pBCB)		(void *)(((RTS_BCB*)pBCB) + 1)

#ifdef MEMPOOL_FUNCTIONS
	static int MEM_GET_FIRST(RTS_HANDLE hPool, MemIterator *pIt)
	{
		RTS_PCB *pPool = (RTS_PCB *)hPool;
		
		pIt->pNext = NULL;
		pIt->pHead = NULL;

		if (hPool != RTS_INVALID_HANDLE && pPool->pBlocksInUse != NULL)
		{
			pIt->pHead = pPool->pBlocksInUse;	
			return 1;
		}
		return 0;
	}
	static int MEM_GET_NEXT(MemIterator *pIt)
	{
		pIt->pNext = (NULL != pIt->pNext) ? pIt->pNext->pBCB : pIt->pHead;

		return pIt->pNext != NULL;
	}
	static void *MEM_GET_DATA(MemIterator *pIt)
	{
		return (pIt->pNext + 1);
	}	
	static void *MEM_GET_DATA_SKIP_DELETE(MemIterator *pIt)
	{
		if (pIt->pNext->flags & MEM_POOL_FLAGS_BLOCK_DELETE)
			return NULL;
		return (pIt->pNext + 1);
	}	
	static void *MEM_GET_NEXT_FROM_DATA(void *pData)
	{
		RTS_BCB *pBCB = ((RTS_BCB*)((unsigned char *)pData - sizeof(RTS_BCB)))->pBCB;
		
		return (NULL != pBCB) ? pBCB + 1 : NULL;
	}
#elif defined(RTS_COMPACT_MICRO)
	int MemPoolIteratorGetFirst(RTS_HANDLE hPool, MemIterator *pIt);
	int MemPoolIteratorGetNext(MemIterator *pIt);
	void* MemPoolIteratorGetNextFromData(void *pData);

	#define MEM_GET_FIRST(ppool, pit)		MemPoolIteratorGetFirst((ppool), (pit))
	#define MEM_GET_NEXT(pit)				MemPoolIteratorGetNext((pit))
	#define MEM_IS_BLOCK_DELETED(pBlock)	((MEM_GET_BCB_FROM_BLOCK(pBlock)->flags & MEM_POOL_FLAGS_BLOCK_DELETE) != 0)
	#define MEM_GET_DATA(pit)				(((MemIterator*)(pit))->pNext + 1)
	#define MEM_GET_DATA_SKIP_DELETE(pIt)	( (((RTS_BCB *)((MemIterator*)(pIt)->pNext)->flags & MEM_POOL_FLAGS_BLOCK_DELETE) == 0 ? (((MemIterator*)(pit))->pNext + 1) + 1 : NULL )
	#define MEM_GET_NEXT_FROM_DATA(pdata)	MemPoolIteratorGetNextFromData((pdata))
#else
	#define __MEM_GET_ITERATOR_NEXT(pIt)	((MemIterator*)pIt)->pNext
	#define __MEM_GET_ITERATOR_HEAD(pIt)	((MemIterator*)pIt)->pHead

	#define MEM_IS_BLOCK_DELETED(pBlock)	((MEM_GET_BCB_FROM_BLOCK(pBlock)->flags & MEM_POOL_FLAGS_BLOCK_DELETE) != 0)
	#define MEM_GET_FIRST(pPool,pIt)		/*lint -e{506,522} */((__MEM_GET_ITERATOR_HEAD(pIt) = ((RTS_PCB *)pPool)->pBlocksInUse) != NULL ? ((__MEM_GET_ITERATOR_NEXT(pIt) = NULL) != NULL ? 0 : 1) : ((__MEM_GET_ITERATOR_NEXT(pIt) = NULL) != NULL ? 1 : 0))
	#define MEM_GET_NEXT(pIt)				/*lint -e{506} */((__MEM_GET_ITERATOR_NEXT(pIt) == NULL) ? (__MEM_GET_ITERATOR_NEXT(pIt) = __MEM_GET_ITERATOR_HEAD(pIt)) : (__MEM_GET_ITERATOR_NEXT(pIt) = __MEM_GET_ITERATOR_NEXT(pIt)->pBCB))
	#define MEM_GET_DATA(pIt)				( __MEM_GET_ITERATOR_NEXT(pIt) + 1 )
	#define MEM_GET_DATA_SKIP_DELETE(pIt)	( (((RTS_BCB *)__MEM_GET_ITERATOR_NEXT(pIt))->flags & MEM_POOL_FLAGS_BLOCK_DELETE) == 0 ? __MEM_GET_ITERATOR_NEXT(pIt) + 1 : NULL )
	#define MEM_GET_NEXT_FROM_DATA(pData)	/*lint -e{506} */(((RTS_BCB*)((unsigned char *)pData - sizeof(RTS_BCB)))->pBCB == NULL ? NULL : ((RTS_BCB*)((unsigned char *)pData - sizeof(RTS_BCB)))->pBCB + 1)
#endif


/**
 * <category>Static MemPool configuration</category>
 * <description>Structure to configure a static MemPool</description>
 * <element name="ulBlockSize" type="IN">Block size of each pool block in bytes</element>
 * <element name="ulMemSize" type="IN">Size of the static memory in bytes</element>
 * <element name="pMemory" type="IN">Pointer to static memory</element>
 */
typedef struct MemPoolConfigurationStatic_
{
	RTS_SIZE ulBlockSize;
	RTS_SIZE ulMemSize;
	void* pMemory;
} MemPoolConfigurationStatic;

/**
 * <category>Dynamic MemPool configuration</category>
 * <description>Structure to configure a dynamic/heap MemPool</description>
 * <element name="pszComponentName" type="IN">Name of the component, which allocates this MemPool</element>
 * <element name="ulNumBlocks" type="IN">Number of blocks which should be allocated directly at creating this MemPool</element>
 * <element name="ulBlockSize" type="IN">Block size of each pool block in bytes</element>
 */
typedef struct MemPoolConfigurationDynamic_
{
	char *pszComponentName;
	RTS_SIZE ulNumBlocks;
	RTS_SIZE ulBlockSize;
} MemPoolConfigurationDynamic;

/**
 * <category>Generic MemPool configuration</category>
 * <description>Structure to configure a MemPool with MemPoolCreate()</description>
 * <element name="options" type="IN">Options of a MemPool. See category "MemPool options" for detail information</element>
 * <element name="pfDeleteFunction" type="IN">Delete function to release resources within a block. Is called in MemPoolPutBlock() and MemPoolPutBlock_LF() implicitly.</element>
 * <element name="config" type="IN">Union to configure a static or dynamic MemPool. Which one is used is specified in options field.</element>
 */
typedef struct MemPoolConfiguration_
{
	RTS_UI32 options;
	PF_MEMBLOCK_DELETEFUNCTION pfDeleteFunction;

	union
	{
		MemPoolConfigurationStatic stat;
		MemPoolConfigurationDynamic dynamic;
	} config;
} MemPoolConfiguration;


#ifdef __cplusplus
extern "C" {
#endif


/**
 * <description>
 *	Create a new MemPool (dynamic or static)
 * </description>
 * <param name="pConfiguration" type="IN">Pointer to configuration</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <result>Handle to the memory pool</result>
 */
DEF_ITF_API(`RTS_HANDLE',`CDECL',`MemPoolCreate',`(MemPoolConfiguration *pConfiguration, RTS_RESULT *pResult)')

/**
 * <description>
 *	Create a dynamic pool (consists of heap memory)
 * </description>
 * <param name="pszComponentName" type="IN">Component name</param>
 * <param name="ulBlockSize" type="IN">Size of each memory block in the pool</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT pResult" type="ERR_OK">MemPool created successfully</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_NOMEMORY">No memory available</errorcode>
 * <result>Handle to the memory pool</result>
 */
DEF_ITF_API(`RTS_HANDLE',`CDECL',`MemPoolCreateDynamic',`(char *pszComponentName, RTS_SIZE ulNumBlocks, RTS_SIZE ulBlockSize, RTS_RESULT *pResult)')

/** 
 * <description>
 * <p>Create a memory pool from a static memory buffer.</p>
 * <p>The memory buffer don't has to be aligned in a specific way. Therefore,
 * not all of the memory in the buffer might be used. To get the appropriate
 * additional buffer, the caller is recommended to use the macro
 * MEM_GET_STATIC_LEN(Num, Struct) to get the size of the buffer</p>
 * <p>For example:</p>
 * <pre>
 * typedef struct
 * {
 *     ...
 * } myStruct_s;
 *
 * #define NUM_OF_STATIC_ELEMENTS 0x100
 *
 * RTS_UI8 s_byMyStaticPool[MEM_GET_STATIC_LEN(NUM_OF_STATIC_ELEMENTS, myStruct_s);
 * </pre>
 * </description>
 * <param name="ulBlockSize" type="IN" range="[BLOCKSIZE_ALIGNED1,BLOCKSIZE_ALIGNED2,BLOCKSIZE_ALIGNED4,BLOCKSIZE_ALIGNED8]">Size of each memory block in the pool, misaligned to 1, 2, 4 or 8 bytes</param>
 * <param name="ulMemSize" type="IN" range="[MEMSIZE_INVALID,MEMSIZE_ALIGNED1,MEMSIZE_ALIGNED2,MEMSIZE_ALIGNED4,MEMSIZE_ALIGNED8]">Complete size of the static memory, misaligned to 1, 2, 4 or 8 bytes</param>
 * <param name="pMemory" type="IN" range="[NULL,VALID_MEM]">Pointer to the static memory</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT pResult" type="ERR_OK">MemPool created successfully</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_PARAMETER">Invalid parameter(e.g. pMemory = NULL)</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_NOMEMORY">ulMemSize was not large enough, to hold at least one block</errorcode>
 * <result>Handle to the memory pool</result>
 */
DEF_ITF_API(`RTS_HANDLE',`CDECL',`MemPoolCreateStatic',`(RTS_SIZE ulBlockSize, RTS_SIZE ulMemSize, void* pMemory, RTS_RESULT *pResult)')

/**
 * <description>
 *	Extend dynamically an existing pool
 * </description>
 * <param name="hMemPool" type="IN">Handle to the pool</param>
 * <param name="pszComponentName" type="IN">Component name</param>
 * <param name="ulNumBlocks" type="IN">Number of blocks to extend</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT pResult" type="ERR_OK">MemPool extended successfully</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_PARAMETER">ulNumBlocks was 0</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_INVALID_HANDLE">hMemPool was RTS_INVALID_HANDLE</errorcode>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`MemPoolExtendDynamic',`(RTS_HANDLE hMemPool, char *pszComponentName, RTS_SIZE ulNumBlocks)')

/**
 * <description>
 *	Extend an existing pool with a static array
 * </description>
 * <param name="hMemPool" type="IN">Handle to the pool</param>
 * <param name="ulMemSize" type="IN">Complete size of the static memory</param>
 * <param name="pMemory" type="IN">Pointer to the static memory</param>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`MemPoolExtendStatic',`(RTS_HANDLE hMemPool, RTS_SIZE ulMemSize, void* pMemory)')

/**
 * <description>
 *	Create the internal sync object for synchronizing the pool.
 * </description>
 * <param name="hMemPool" type="IN">Handle to the pool</param>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`MemPoolCreateSyncObject',`(RTS_HANDLE hMemPool)')

/**
 * <description>
 *	Delete the internal sync object for synchronizing the pool.
 * </description>
 * <param name="hMemPool" type="IN">Handle to the pool</param>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`MemPoolDeleteSyncObject',`(RTS_HANDLE hMemPool)')

/**
 * <description>
 *	Delete an existing pool
 * </description>
 * <param name="hMemPool" type="IN">Handle to the pool</param>
 * <param name="pszComponentName" type="IN">Component name</param>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`MemPoolDelete',`(RTS_HANDLE hMemPool, char *pszComponentName)')

/**
 * <description>
 *	Cleanup the pool (delete all allocated heap pool objects)
 * </description>
 * <param name="hMemPool" type="IN">Handle to the pool</param>
 * <param name="pszComponentName" type="IN">Component name</param>
 * <param name="bReleaseSemaphore" type="IN">1=Pool semaphore is released, 0=Only cleanup</param>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`MemPoolCleanup',`(RTS_HANDLE hMemPool, char *pszComponentName, int bReleaseSemaphore)')



/** 
 * <description>
 * <p>Get one memory block out of the pool.</p>
 * <p>SIL2 Implementation: If pPCB is wrong, an Exception is generated!</p>
 * </description>
 * <param name="hMemPool" type="IN" range="[RTS_INVALID_HANDLE,VALID_MEMPOOLHANDLE,INVALID_MEMPOOLHANDLE]">Handle to the pool</param>
 * <parampseudo name="hMemPool.NumEntries" type="IN" range="[0..NUM_OF_STATIC_ELEMENTS-1,NUM_OF_STATIC_ELEMENTS..INT_MAX]">Number of already allocated entries from the pool</parampseudo>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <parampseudo name="bExceptionGenerated" type="OUT" range="[TRUE,FALSE]">specifies, if an exception was generated or not</parampseudo>
 * <errorcode name="RTS_RESULT pResult" type="ERR_OK">Retrieved free block from MemPool</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_INVALID_HANDLE">No free block found</errorcode> 
 * <result>Pointer to the memory block</result>
 */
DEF_ITF_API(`void*',`CDECL',`MemPoolGetBlock',`(RTS_HANDLE hMemPool, RTS_RESULT *pResult)')

/**
 * <description>
 *	Get one memory block out of the pool
 * </description>
 * <param name="hMemPool" type="IN">Handle to the pool</param>
 * <param name="bDynamic" type="IN">1=Block is created dynamically, if the pool is empty, 0=Only use of static pool memory</param>
 * <param name="pszComponentName" type="IN">Pointer to the component name for dynamic memory allocation</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <result>Pointer to the memory block</result>
 */
DEF_ITF_API(`void*',`CDECL',`MemPoolGetBlock2',`(RTS_HANDLE hMemPool, int bDynamic, char *pszComponentName, RTS_RESULT *pResult)')

/**
 * <description>
 *	Get one the pool control block of a specified pool
 * </description>
 * <param name="hMemPool" type="IN">Handle to the pool</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <result>Pointer to the pool control block</result>
 */
DEF_ITF_API(`RTS_PCB*',`CDECL',`MemPoolGetPCB',`(RTS_HANDLE hMemPool, RTS_RESULT *pResult)')

/**
 * <description>
 *	Put a memory block back into the pool (release). Now, the block is in the chain list of free blocks again. 
 * </description>
 * <param name="pBlock" type="IN" range="[NULL,VALID_BLOCK,INVALID_BLOCK]">Pointer to the memory block</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Successfully added block to MemPool</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Could not add block to MemPool, wrong pBlock</errorcode> 
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`MemPoolPutBlock',`(void* pBlock)')

/**
 * <description>
 *	Add used block at the beginning of the pool. Now, the block is in the chain list of used blocks.
 * </description>
 * <param name="pBlock" type="IN" range="[NULL,VALID_BLOCK]">Pointer to the memory block</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Successfully added block to MemPool</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Could not add block to MemPool, wrong pBlock</errorcode> 
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`MemPoolAddUsedBlock',`(void* pBlock)')

/**
 * <description>
 *	Add used block at the end of the pool. Now, the block is in the chain list of used blocks.
 * </description>
 * <param name="pBlock" type="IN" range="[NULL,VALID_BLOCK]">Pointer to the memory block</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Successfully added block to MemPool</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Could not add block to MemPool, wrong pBlock</errorcode> 
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`MemPoolAppendUsedBlock',`(void* pBlock)')

/**
 * <description>
 *	Insert used block right after the specified block or as a head element of an internal used blocks list.
 * </description>
 * <param name="pPrevBlock" type="IN" range="[NULL,VALID_PREVBLOCK,INVALID_PREVBLOCK]">Pointer to the predecessor block</param>
 * <param name="pBlock" type="IN" range="[NULL,VALID_BLOCK]">Pointer to the memory block</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Successfully inserted block to MemPool</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Could not insert block to MemPool because pBlock is NULL or pPrevBlock belongs to a different pool than pBlock</errorcode> 
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`MemPoolInsertUsedBlock',`(void* pPrevBlock, void* pBlock)')

/**
 * <description>
 *	Remove used block from the pool. If this function succeeds, the block could not be recognized anymore by any iterator on the pool!
 * </description>
 * <param name="pBlock" type="IN" range="[NULL,VALID_BLOCK,VALID_BLOCK_MID,VALID_BLOCK_LAST]">Pointer to the memory block</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Successfully removed block from MemPool</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Could not remove block from MemPool, wrong pBlock</errorcode> 
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`MemPoolRemoveUsedBlock',`(void* pBlock)')

/**
 * <description>
 *	Add used block the beginning of the specified pool. Now, the block is in the chain list of used blocks.
 * </description>
 * <param name="pBlock" type="IN">Pointer to the memory block</param>
 * <param name="hPool" type="IN">Handle to the pool</param>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`MemPoolAddUsedBlockToPool',`(void* pBlock, RTS_HANDLE hPool)')

/**
 * <description>
 *	Add the block to the end of the used block list of hPool
 * </description>
 * <param name="pBlock" type="IN">Pointer to the memory block</param>
 * <param name="hPool" type="IN">Handle to the pool</param>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`MemPoolAppendUsedBlockToPool',`(void* pBlock, RTS_HANDLE hPool)')

/**
 * <description>
 *	Remove used block from the specified pool. Now, the block is removed from the chain list of used blocks.
 * </description>
 * <param name="pBlock" type="IN">Pointer to the memory block</param>
 * <param name="hPool" type="IN">Handle to the pool</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Successfully removed block from MemPool</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Could not remove block from MemPool, wrong pBlock</errorcode> 
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`MemPoolRemoveUsedBlockFromPool',`(void* pBlock, RTS_HANDLE hPool)')

/**
 * <description>
 *	Lock the access to a pool to be thread safe.
 * </description>
 * <param name="pBlock" type="IN">Pointer to the memory block</param>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`MemPoolLockBlock',`(void* pBlock)')

/**
 * <description>
 *	Unlock the access to a pool.
 * </description>
 * <param name="pBlock" type="IN">Pointer to the memory block</param>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`MemPoolUnlockBlock',`(void* pBlock)')

/**
 * <description>
 *	Function to release all blocks within a pool or only the blocks that are marked as "to delete". This behavior can be controlled with the parameter bOnlyDeletedBlocks.
 *  If a delete function was specified in MemPoolCreate(), this function is called at deleting the appropriate block and the delete function gets the pParam parameter!
 * </description>
 * <param name="hMemPool" type="IN" range="[VALID_MEMPOOLHANDLE,NULL]">Handle to the memory pool</param>
 * <param name="bOnlyDeletedBlocks" type="IN" range="[TRUE,FALSE]">TRUE=Release only blocks, which are marked as to delete. FALSE=Release all blocks within a pool</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Blocks in the MemPool are successfully release</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Pool handle is invalid</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PENDING">Not all blocks could be deleted because the pool is still occupied by another iterator!</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">Release the pool could not be done before CH_INIT_SYSTEM. Not relevant for SIL2</errorcode>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`MemPoolReleaseBlocks',`(RTS_HANDLE hMemPool, RTS_BOOL bOnlyDeletedBlocks, void *pParam)')

/**
 * <description>
 *	Lock the access to the complete pool. SIL2 Implementation is using INT Locks.
 * </description>
 * <param name="hMemPool" type="IN" range="[VALID_MEMPOOLHANDLE,NULL]">Handle to the memory pool</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Pool was successfully locked</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Parameter is wrong</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Pool could not be locked, SysInt or SysSem had problems</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTIMPLEMENTED">SysInt or SysSem are not implemented</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">Lock cannot be done before CH_INIT_SYSTEM, not relevant for SIL2</errorcode>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`MemPoolLock',`(RTS_HANDLE hMemPool)')

/**
 * <description>
 *	Unlock the access to the complete pool. SIL2 Implementation is using INT Locks.
 * </description>
 * <param name="hMemPool" type="IN" range="[VALID_MEMPOOLHANDLE,NULL]">Handle to the memory pool</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Pool was successfully unlocked</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Parameter is wrong</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Pool could not be unlocked, SysInt or SysSem had problems</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTIMPLEMENTED">SysInt or SysSem are not implemented</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">Unlock cannot be done before CH_INIT_SYSTEM, not relevant for SIL2</errorcode>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`MemPoolUnlock',`(RTS_HANDLE hMemPool)')

/**
 * <description>
 *	Find a block specified by a value, that is stored in the block.
 *  NOTE:
 *	Please use MemPoolLock or MemPoolAddRef_LF before calling this function, because block is returned unsynchronized against the pool!
 * </description>
 * <param name="hMemPool" type="IN">Handle to the memory pool</param>
 * <param name="ulOffset" type="IN">Byte offset of the value in the block to find</param>
 * <param name="ulSize" type="IN">Size in bytes of the value to find in the block</param>
 * <param name="pToFind" type="IN">Pointer to the value to find in the block</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <result>Pointer to the memory block</result>
 */
DEF_ITF_API(`void *',`CDECL',`MemPoolFindBlock',`(RTS_HANDLE hMemPool, RTS_SIZE ulOffset, RTS_SIZE ulSize, void *pToFind, RTS_RESULT *pResult)')

/**
 * <description>
 *	Check a pool memory block, if it is still valid and is not released.
 *	NOTE:
 *	If the check is successful, a lock is done on this pool!!! So you have to unlock this reference at the end of the usage with MemPoolUnlock()!
 * </description>
 * <param name="hMemPool" type="IN">Handle to the memory pool</param>
 * <param name="pBlock" type="IN">Pointer to the memory block</param>
 * <result>Error code</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`MemPoolIsValidBlock',`(RTS_HANDLE hMemPool, void *pBlock)')

/**
 * <description>
 *	Get the first memory block out of the pool. Can be used for explicit iteration routines.
 * </description>
 * <param name="hMemPool" type="IN">Handle to the memory pool</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <result>Pointer to first memory block</result>
 */
DEF_ITF_API(`void*',`CDECL',`MemPoolGetFirstBlock',`(RTS_HANDLE hMemPool, RTS_RESULT *pResult)')

/**
 * <description>
 *	Get the next memory block out of the pool. Can be used for explicit iteration routines.
 * </description>
 * <param name="hMemPool" type="IN">Handle to the memory pool</param>
 * <param name="pPrevBlock" type="IN">Pointer to previous memory block</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <result>Pointer to next memory block</result>
 */
DEF_ITF_API(`void*',`CDECL',`MemPoolGetNextBlock',`(RTS_HANDLE hMemPool, void *pPrevBlock, RTS_RESULT *pResult)')


/*==== MemPool operations based on reference counter on the memory pool to realize nearly locking free iterators (function postfix "_LF") ===========================*/

/**
 * <description>
 *	To have a locking free iteration over a MemPool, you can use this AddRef function to occupy a MemPool!
 *	After calling this function, no element can be deleted out of the list of the MemPool!
 *
 *  NOTES:
 *	1. Please use the appropriate macro MEM_GET_DATA_SKIP_DELETE() to get the data of all blocks, which are not marked as deleted! So you can skip this block and you should 
 *	   iterate to the next blocks.
 *	2. Be aware, that a block cannot be removed from pool (via CAL_MemPoolRemoveUsedBlock_LF() after calling CAL_MemPoolAddRef_LF()!
 *	   You have call CAL_MemPoolReleaseRef_LF() first and then you are able to remove the block or use CAL_MemPoolRemoveUsedBlock() alternatively!
 *
 * </description>
 * <param name="hMemPool" type="IN" range="[VALID_MEMPOOLHANDLE,NULL]">Handle to the memory pool</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Pool was successfully occupied</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Pool handle is invalid</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">Occupying the pool could not be done before CH_INIT_SYSTEM. Not relevant for SIL2</errorcode>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`MemPoolAddRef_LF',`(RTS_HANDLE hMemPool)')

/**
 * <description>
 *	To have a locking free iteration over a MemPool, you can use this release function to free a MemPool, which was occupied previously with MemPoolAddRef_LF()!
 * </description>
 * <param name="hMemPool" type="IN" range="[VALID_MEMPOOLHANDLE,NULL]">Handle to the memory pool</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Pool was successfully freed</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Pool handle is invalid</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">Free the pool could not be done before CH_INIT_SYSTEM. Not relevant for SIL2</errorcode>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`MemPoolReleaseRef_LF',`(RTS_HANDLE hMemPool)')

/**
 * <description>
 *	Lock the access to the complete pool. SIL2 Implementation is using INT Locks.
 *
 *	NOTE:
 *  - Function can return ERR_NO_CONSISTENCY to signalize, that the reference counter in the pool is >0 and so someone is still in an iteration loop after MemPoolAddRef_LF()! 
 * </description>
 * <param name="hMemPool" type="IN" range="[VALID_MEMPOOLHANDLE,NULL]">Handle to the memory pool</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Pool was successfully locked</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Parameter is wrong</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Pool could not be locked, SysInt or SysSem had problems</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTIMPLEMENTED">SysInt or SysSem are not implemented</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">Lock cannot be done before CH_INIT_SYSTEM, not relevant for SIL2</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_CONSISTENCY">Lock is done, but the reference counter in the pool is >0 and so someone is still in an iteration loop after MemPoolAddRef()!</errorcode>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`MemPoolLock_LF',`(RTS_HANDLE hMemPool)')

/**
 * <description>
 *	Unlock the access to the complete pool. SIL2 Implementation is using INT Locks.
 * </description>
 * <param name="hMemPool" type="IN" range="[VALID_MEMPOOLHANDLE,NULL]">Handle to the memory pool</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Pool was successfully unlocked</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Parameter is wrong</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Pool could not be unlocked, SysInt or SysSem had problems</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTIMPLEMENTED">SysInt or SysSem are not implemented</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">Unlock cannot be done before CH_INIT_SYSTEM, not relevant for SIL2</errorcode>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`MemPoolUnlock_LF',`(RTS_HANDLE hMemPool)')

/**
 * <description>
 *	Remove used block from the pool. If this function succeeds, the block could not be recognized anymore by any iterator on the pool!
 *	NOTE:
 *  Please note the return codes of this function, especially ERR_PENDING! 
 * </description>
 * <param name="pBlock" type="IN" range="[NULL,VALID_BLOCK]">Pointer to the memory block</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Successfully removed block from MemPool</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Could not remove block from MemPool, wrong pBlock</errorcode> 
 * <errorcode name="RTS_RESULT" type="ERR_PENDING">Could not remove block from MemPool because the pool is currently under usage by another iterator which used MemPoolAddRef_LF()! 
 *												   But the block is still marked to delete and can be deleted later on by calling CAL_MemPoolReleaseBlocks(hPool, TRUE, pParam)!
 * </errorcode> 
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`MemPoolRemoveUsedBlock_LF',`(void* pBlock)')

/**
 * <description>
 *	Remove used block from the specified pool. Now, the block is removed from the chain list of used blocks.
 * </description>
 * <param name="pBlock" type="IN">Pointer to the memory block</param>
 * <param name="hPool" type="IN">Handle to the pool</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Successfully removed block from MemPool</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Could not remove block from MemPool, wrong pBlock</errorcode> 
 * <errorcode name="RTS_RESULT" type="ERR_PENDING">Could not remove block from MemPool because the pool is currently under usage by another iterator which used MemPoolAddRef_LF()! 
 *												   But the block is still marked to delete and can be deleted later on by calling CAL_MemPoolReleaseBlocks(hPool, TRUE, pParam)!
 * </errorcode> 
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`MemPoolRemoveUsedBlockFromPool_LF',`(void* pBlock, RTS_HANDLE hPool)')

/**
 * <description>
 *	Put a memory block back into the pool (release). The content of the block is released with the corresponding delete function, which was specified as a parameter in the MemPoolCreate() function.
 * </description>
 * <param name="pBlock" type="IN">Pointer to the memory block</param>
 * <param name="pParam" type="IN">Optional parameter for the delete function. Can be NULL.</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Successfully added block to MemPool</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Could not add block to MemPool, wrong pBlock</errorcode> 
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`MemPoolPutBlock_LF',`(void* pBlock, void *pParam)')

/**
 * <description>
 *	Check a pool memory block, if it is still valid and is not released.
 *	NOTE:
 *	If the check is successful, a MemPoolAddRef done on this pool!!! So you have to release this reference at the end of the usage with MemPoolReleaseRef_LF()!
 * </description>
 * <param name="hMemPool" type="IN">Handle to the memory pool</param>
 * <param name="pBlock" type="IN">Pointer to the memory block</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Succeeded</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Pool or block handle is invalid</errorcode>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`MemPoolIsValidBlock_LF',`(RTS_HANDLE hMemPool, void *pBlock)')

#ifdef __cplusplus
}
#endif
