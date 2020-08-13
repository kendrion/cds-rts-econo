/**
* <name>RtsMemPool.c</name>
* <description>
*	Example to show different use cases of the MemPool manager.
*
*	USAGE:
*	- MemPoolExamples() can be called out of CH_COMM_CYCLE to show, how the MemPool works
* </description>
*
* <copyright>(c) 2003-2018 3S-Smart Software Solutions</copyright>
*/

#include "CmpStd.h"
#include "CmpMemPoolItf.h"
#include "CmpMemPoolHashItf.h"

typedef struct _TEST_STRUCT
{
	RTS_UI8 by;
	RTS_UI16 us;
	RTS_UI32 ul;
} TEST_STRUCT;

/*=== Declaration of static mem pools ===*/
#define TEST_NUM_OF_ELEMENTS	10
static RTS_UI8 s_TestPool1[MEM_GET_STATIC_LEN(TEST_NUM_OF_ELEMENTS, TEST_STRUCT)];
static RTS_UI8 s_TestPool2[MEM_GET_STATIC_LEN(TEST_NUM_OF_ELEMENTS, TEST_STRUCT)];

/*=== Declaration of hashed mem pool ===*/
static RTS_UI8 s_TestPoolHashed[MEM_GET_STATIC_LEN(TEST_NUM_OF_ELEMENTS, TEST_STRUCT)];
#define TEST_NUM_OF_HASHTABLE_ENTRIES	(TEST_NUM_OF_ELEMENTS + TEST_NUM_OF_ELEMENTS / 2)
static RTS_UI8 s_aHashTableBuffer[MEMPOOLHASH_GET_HASHTABLE_LEN(TEST_NUM_OF_HASHTABLE_ENTRIES)];
static RTS_HANDLE s_hMemPoolHashTable = RTS_INVALID_HANDLE;

/*=== Declaration of handles to mem pools ===*/
static RTS_HANDLE s_hStaticMemPool1 = RTS_INVALID_HANDLE;
static RTS_HANDLE s_hStaticMemPool2 = RTS_INVALID_HANDLE;
static RTS_HANDLE s_hDynamicMemPool1 = RTS_INVALID_HANDLE;
static RTS_HANDLE s_hDynamicMemPool2 = RTS_INVALID_HANDLE;
static RTS_HANDLE s_hStaticMemPoolHashed = RTS_INVALID_HANDLE;

/* Local variables */
static int s_nDeletedBlocks = 0;

/*=== Local use case functions ===*/
static RTS_RESULT CreateMemPoolsStatic(void);
static RTS_RESULT CreateMemPoolsDynamic(void);
static RTS_RESULT DeleteMemPools(void);

static void* UseCase_AllocateSingleBlock1(RTS_HANDLE hPool, RTS_RESULT *pResult);
static void* UseCase_AllocateSingleBlock2(RTS_HANDLE hPool, RTS_RESULT *pResult);

static RTS_RESULT UseCase_IterateOverAllBlocksInUse_Locking(RTS_HANDLE hPool, void **ppBlock);
static RTS_RESULT UseCase_CheckBlock_Locking(RTS_HANDLE hPool, void *pBlock);
static RTS_RESULT UseCase_IterateOverAllBlocksInUse_NearlyLockFree(RTS_HANDLE hPool, void **ppBlock);
static RTS_RESULT UseCase_CheckBlock_NearlyLockFree(RTS_HANDLE hPool, void *pBlock);

static RTS_RESULT UseCase_ReleaseSingleBlock1(void *pBlock);
static RTS_RESULT UseCase_ReleaseSingleBlock2(void *pBlock, void *pParam);

static RTS_RESULT UseCase_ReleaseAllBlocksInPool(RTS_HANDLE hPool);
static RTS_RESULT UseCase_ReleaseAllBlocksInPool2(RTS_HANDLE hPool, void *pParam);
static RTS_RESULT UseCase_ReleaseAllBlocksInPool3(RTS_HANDLE hPool, void *pParam);
static RTS_RESULT UseCase_ReleaseSingleBlockWithinIterator(RTS_HANDLE hPool, void *pBlock, void *pParam);
static RTS_RESULT UseCase_ReleaseAllDeletedBlocksInPool(RTS_HANDLE hPool, void *pParam);

/*=== Local test cases ===*/

static RTS_RESULT TestCase_DeleteBlockDuringIteration(RTS_HANDLE hPool);


/*=== Function to release content of a single block ===*/
static void CDECL BlockDelete(void *pBlock, void *pParam)
{
	/* EXIT BLOCK begin */

	/* TODO: Here you have to release the content of the block!
		 	 You can release the block because here you are in the safe state of the block! No one can allocate the same block and
			 no one see this block in an iteration sequence!
	 */

	if (pParam != NULL)
		*(int *)pParam += 1;

	/* EXIT BLOCK end */
}

/*=== Constructors of pools  ===*/
static RTS_RESULT CreateMemPoolsStatic(void)
{
	MemPoolConfiguration poolConf;
	RTS_RESULT result;

	/*=== Variant 1: Old style ===*/
	s_hStaticMemPool1 = CAL_MemPoolCreateStatic(sizeof(TEST_STRUCT), sizeof(s_TestPool1), s_TestPool1, &result);
	if (result != ERR_OK)
		return result;

	/*=== Variant 2: Recommended style ===*/
	memset(&poolConf, 0, sizeof(poolConf));

	poolConf.options = MEM_POOL_OPTION_STATIC;
	poolConf.pfDeleteFunction = BlockDelete;
	poolConf.config.stat.pMemory = s_TestPool2;
	poolConf.config.stat.ulMemSize = sizeof(s_TestPool2);
	poolConf.config.stat.ulBlockSize = sizeof(TEST_STRUCT);

	s_hStaticMemPool2 = CAL_MemPoolCreate(&poolConf, &result);
	if (result != ERR_OK)
		return result;

	return ERR_OK;
}

static RTS_RESULT CreateMemPoolsDynamic(void)
{
	MemPoolConfiguration poolConf;
	RTS_RESULT result;

	/*=== Variant 1: Old style ===*/
	s_hDynamicMemPool1 = CAL_MemPoolCreateDynamic(COMPONENT_NAME, TEST_NUM_OF_ELEMENTS, sizeof(TEST_STRUCT), &result);
	if (result != ERR_OK)
		return result;

	/*=== Variant 2: Recommended style ===*/
	memset(&poolConf, 0, sizeof(poolConf));

	poolConf.options = MEM_POOL_OPTION_DYNAMIC;
	poolConf.pfDeleteFunction = BlockDelete;
	poolConf.config.dynamic.pszComponentName = COMPONENT_NAME;
	poolConf.config.dynamic.ulBlockSize = sizeof(TEST_STRUCT);
	poolConf.config.dynamic.ulNumBlocks = TEST_NUM_OF_ELEMENTS;

	s_hDynamicMemPool2 = CAL_MemPoolCreate(&poolConf, &result);
	if (result != ERR_OK)
		return result;
	
	return ERR_OK;
}

/*=== Destructors of pools  ===*/
static RTS_RESULT DeleteMemPools(void)
{
	RTS_RESULT result;

	if (s_hStaticMemPool1 != RTS_INVALID_HANDLE)
	{
		result = CAL_MemPoolDelete(s_hStaticMemPool1, COMPONENT_NAME);
		if (result != ERR_OK)
			return result;
	}
	if (s_hStaticMemPool2 != RTS_INVALID_HANDLE)
	{
		result = CAL_MemPoolDelete(s_hStaticMemPool2, COMPONENT_NAME);
		if (result != ERR_OK)
			return result;
	}
	if (s_hDynamicMemPool1 != RTS_INVALID_HANDLE)
	{
		result = CAL_MemPoolDelete(s_hDynamicMemPool1, COMPONENT_NAME);
		if (result != ERR_OK)
			return result;
	}
	if (s_hDynamicMemPool2 != RTS_INVALID_HANDLE)
	{
		result = CAL_MemPoolDelete(s_hDynamicMemPool2, COMPONENT_NAME);
		if (result != ERR_OK)
			return result;
	}
	s_hStaticMemPool1 = RTS_INVALID_HANDLE;
	s_hStaticMemPool2 = RTS_INVALID_HANDLE;
	s_hDynamicMemPool1 = RTS_INVALID_HANDLE;
	s_hDynamicMemPool2 = RTS_INVALID_HANDLE;
	return ERR_OK;
}


/*=== Use cases ===*/

static void* UseCase_AllocateSingleBlock1(RTS_HANDLE hPool, RTS_RESULT *pResult)
{
	RTS_RESULT result;
	
	/*=== Variant 1: Here you have it in your hand, if you extend the pool dynamic with element(s) from heap or if you would like to limit the pool to the still allocated blocks! ===*/
	/* Allocate a new block */
	void *pBlock = CAL_MemPoolGetBlock(hPool, &result);
	if (pBlock == NULL || result != ERR_OK)
	{
		/* If no block is available you get an error here to extend the pool with a dynamic block element.
		   If you would like to limit the pool to the numer of preallocated blocks, you can return an error here (typically the error code ERR_NOMEMORY).
		
		   NOTE:
			If you expect that you need more than onbe additional block the next time, you can extend the pool with more than one block here! So you safe time the next time 
			you have to call CAL_MemPoolGetBlock().
		 */
		result = CAL_MemPoolExtendDynamic(hPool, COMPONENT_NAME, 1);
		if (result != ERR_OK)
		{
			RTS_SETRESULT(pResult, result);
			return NULL;
		}
		pBlock = CAL_MemPoolGetBlock(hPool, &result);
		if (pBlock == NULL || result != ERR_OK)
		{
			RTS_SETRESULT(pResult, result);
			return NULL;
		}
	}
	/* INIT BLOCK begin */

	/* TODO: 
	   Here you can initialize the content of new block before usage! You are in a safe state of the block and no one can allocate the same block and no one see
	   this block in an iteration sequence! 
	 */
	  
	/* INIT BLOCK end */

	/* Add block to used list in pool */
	if (pBlock != NULL)
	{
		/* NOTE: After calling this function, the block is visible in every iteration sequence! So before calling this function, the block must be completely initialized! */
		result = CAL_MemPoolAddUsedBlock(pBlock);
	}

	RTS_SETRESULT(pResult, result);
	return pBlock;
}

static void* UseCase_AllocateSingleBlock2(RTS_HANDLE hPool, RTS_RESULT *pResult)
{
	RTS_RESULT result;

	/*=== Variant 2: Recommended style. We extend here the pool with one additional element from heap! ===*/
	/* Allocate a new block */
	void *pBlock = (TEST_STRUCT *)CAL_MemPoolGetBlock2(hPool, TRUE, COMPONENT_NAME, &result);

	/* INIT BLOCK begin */

	/* TODO:
	   Here you can initialize the content of new block before usage! You are in a safe state of the block and no one can allocate the same block and no one see
	   this block in an iteration sequence!
	 */

	/* INIT BLOCK end */

	/* Add block to used list in pool */
	if (pBlock != NULL)
	{
		/* NOTE: After calling this function, the block is visible in every iteration sequence! So before calling this function, the block must be completely initialized! */
		result = CAL_MemPoolAddUsedBlock(pBlock);
	}
	RTS_SETRESULT(pResult, result);
	return pBlock;
}

static RTS_RESULT UseCase_ReleaseSingleBlock1(void *pBlock)
{
	RTS_RESULT result;
	
	/*=== Variant 1 ===*/

	/* Remove block from used list in pool */
	result = CAL_MemPoolRemoveUsedBlock(pBlock);
	if (result == ERR_OK)
	{
		/* EXIT BLOCK begin */
		
		/* TODO: Here you have to release the content of the block! 
		         You can release the block because here you are in the safe state of the block! No one can allocate the same block and 
				 no one see this block in an iteration sequence! 
	     */

		/* EXIT BLOCK end */

		/* Release block. Block is moved back to free objects in pool */
		result = CAL_MemPoolPutBlock(pBlock);
	}
	return result;
}

static RTS_RESULT UseCase_ReleaseSingleBlock2(void *pBlock, void *pParam)
{
	RTS_RESULT result;

	/*=== Variant 2: Recommended style ===*/
	/* Must be used, if the delete function is specified in MemPoolCreate()! */

	/* Remove block from used list in pool */
	result = CAL_MemPoolRemoveUsedBlock_LF(pBlock);
	if (result == ERR_OK)
	{
		/* NOTE:
		 * Exit of the block is done implicitly in the MemPoolPutBlock_LF() delete function, which was specified in the MemPoolCreate() function!
		 */
		result = CAL_MemPoolPutBlock_LF(pBlock, pParam);
	}
	else
	{
		/* OPTIONAL:
		   The following code is optional and can be used to wait until the iterator outside has left the iteration sequence!
		   This can be used to force releasing this block until leaving the function!
		 */
#if 0
		result = ERR_NO_CONSISTENCY;
		while (result == ERR_NO_CONSISTENCY)
		{
			result = CAL_MemPoolLockBlock(pBlock);
			if (result == ERR_OK)
				break;

			CAL_MemPoolUnlockBlock(pBlock);
			
			/* TODO: e.g. Sleep for some time */
		}
		if (result == ERR_OK)
		{
			result = CAL_MemPoolPutBlock_LF(pBlock, pParam);
			CAL_MemPoolUnlockBlock(pBlock);
		}
#endif
	}
	return result;
}

static RTS_RESULT UseCase_IterateOverAllBlocksInUse_Locking(RTS_HANDLE hPool, void **ppBlock)
{
	MemIterator m;
	TEST_STRUCT *pTest;

	/*=== Variant 1: Old style === */
	/* This uses case lock the access at iterating over the pool! So further iterators are blocked at MemPoolLock() and so this could harm the realtime! */

	CAL_MemPoolLock(hPool);
	(void)MEM_GET_FIRST(hPool, &m);
	while (MEM_GET_NEXT(&m))
	{
		pTest = (TEST_STRUCT *)MEM_GET_DATA(&m);
		if (pTest != NULL)
		{
			/* TODO: Here you can access the object in a safe way, because the pool is locked via CAL_MemPoolLock/CAL_MemPoolUnlock */

			if (ppBlock != NULL)
				*ppBlock = pTest;
		}
	}
	CAL_MemPoolUnlock(hPool);
	return ERR_OK;
}

static RTS_RESULT UseCase_CheckBlock_Locking(RTS_HANDLE hPool, void *pBlock)
{
	if (CAL_MemPoolIsValidBlock(hPool, pBlock))
	{
		/* TODO: Here the block is valid and the pool is locked! So we can use this block here. */

		CAL_MemPoolUnlock(hPool);
		return ERR_OK;
	}
	return ERR_PARAMETER;
}

static RTS_RESULT UseCase_IterateOverAllBlocksInUse_NearlyLockFree(RTS_HANDLE hPool, void **ppBlock)
{
	MemIterator m;

	/*=== Variant 2: Recommended style === */
	/* This uses case does not lock the access at iterating over the pool! So this is the recommended implementation not to disturb the realtime behaviour! */

	CAL_MemPoolAddRef_LF(hPool);
	(void)MEM_GET_FIRST(hPool, &m);
	while (MEM_GET_NEXT(&m))
	{
		TEST_STRUCT *pTest = (TEST_STRUCT *)MEM_GET_DATA_SKIP_DELETE(&m);
		/* Here you get a NULL pointer, if block was marked as deleted during we iterate over the pool */
		if (pTest != NULL)
		{
			/* TODO: Here you can access the object in a safe way, because the pool is occupied with CAL_MemPoolAddRef_LF/CAL_MemPoolReleaseRef_LF */

			if (ppBlock != NULL)
				*ppBlock = pTest;
		}

		pTest = (TEST_STRUCT *)MEM_GET_DATA(&m);
		/* Here you get a NULL pointer, if block was marked as deleted during we iterate over the pool */
		if (pTest != NULL && !MEM_IS_BLOCK_DELETED(pTest))
		{
			/* TODO: Here you can access the object in a safe way, because the pool is occupied with CAL_MemPoolAddRef_LF/CAL_MemPoolReleaseRef_LF */
		}
	}
	CAL_MemPoolReleaseRef_LF(hPool);

	return ERR_OK;
}

static RTS_RESULT UseCase_CheckBlock_NearlyLockFree(RTS_HANDLE hPool, void *pBlock)
{
	if (CAL_MemPoolIsValidBlock_LF(hPool, pBlock) == ERR_OK)
	{
		/* TODO: The pool is protected by a MemPoolAddRef_LF implicitly! So we can use this block here and have to release the pool with MemPoolReleaseRef_LF. */

		CAL_MemPoolReleaseRef_LF(hPool);
		return ERR_OK;
	}
	return ERR_PARAMETER;
}

static RTS_RESULT UseCase_ReleaseAllBlocksInPool1(RTS_HANDLE hPool)
{
	MemIterator m;
	RTS_RESULT result = ERR_NO_OBJECT;

	/*=== Variant 1: Old style ===*/
	/* DISADVANTAGE: We begin always at the beginning of the list! So if we don't delete all elements, we start always at the beginning and 
	   so we recommend Variant 2 and 3! */

	CAL_MemPoolLock(hPool);
	(void)MEM_GET_FIRST(hPool, &m);
	while (MEM_GET_NEXT(&m))
	{
		TEST_STRUCT *pTest = (TEST_STRUCT *)MEM_GET_DATA(&m);
		if (pTest != NULL)
		{
			/* Release the block */
			/* Remove block from used list in pool (see UseCase_ReleaseSingleBlock1()) */
			result = CAL_MemPoolRemoveUsedBlock(pTest);
			if (result == ERR_OK)
			{
				/* EXIT BLOCK begin */

				/* TODO: Here you have to release the content of the block!
						 You can release the block because here you are in the safe state of the block! No one can allocate the same block and
						 no one see this block in an iteration sequence!
				 */

				/* EXIT BLOCK end */

				/* Release block. Block is moved back to free objects in pool */
				result = CAL_MemPoolPutBlock(pTest);
				(void)MEM_GET_FIRST(hPool, &m);
			}
		}
	}
	CAL_MemPoolUnlock(hPool);

	return result;
}

static RTS_RESULT UseCase_ReleaseAllBlocksInPool2(RTS_HANDLE hPool, void *pParam)
{
	MemIterator m;
	RTS_RESULT result = ERR_NO_OBJECT;

	/*=== Variant 2 ===*/

	CAL_MemPoolLock_LF(hPool);
	(void)MEM_GET_FIRST(hPool, &m);
	if (MEM_GET_NEXT(&m))
	{
		TEST_STRUCT *pTest = (TEST_STRUCT *)MEM_GET_DATA(&m);
		while (pTest != NULL)
		{
			void *pToDelete = pTest;

			/* Iterate to the next block before deleteing the current block! */
			pTest = (TEST_STRUCT *)MEM_GET_NEXT_FROM_DATA(pTest);
			
			/* Release the block */
			/* Remove block from used list in pool (see UseCase_ReleaseSingleBlock2()) */
			result = CAL_MemPoolRemoveUsedBlock_LF(pToDelete);
			if (result == ERR_OK)
			{
				/* NOTE:
				 * Exit of the block is done implicitly in the MemPoolPutBlock_LF() delete function, which was specified in the MemPoolCreate() function!
				 */
				result = CAL_MemPoolPutBlock_LF(pToDelete, pParam);
			}
		}
	}
	CAL_MemPoolUnlock_LF(hPool);

	return result;
}

static RTS_RESULT UseCase_ReleaseAllBlocksInPool3(RTS_HANDLE hPool, void *pParam)
{
	/*=== Variant 3: Recommended style ===*/
	CAL_MemPoolReleaseBlocks(hPool, FALSE, pParam);
	return ERR_OK;
}

static RTS_RESULT UseCase_ReleaseSingleBlockWithinIterator(RTS_HANDLE hPool, void *pBlock, void *pParam)
{
	RTS_RESULT result;

	CAL_MemPoolAddRef_LF(hPool);
	result = UseCase_ReleaseSingleBlock2(pBlock, pParam);
	CAL_MemPoolReleaseRef_LF(hPool);
	if (result == ERR_PENDING)
		return ERR_OK;
	return result;
}

static RTS_RESULT UseCase_ReleaseAllDeletedBlocksInPool(RTS_HANDLE hPool, void *pParam)
{
	return CAL_MemPoolReleaseBlocks(hPool, TRUE, pParam);
}

static RTS_RESULT CDECL StandardUseCases(void)
{
	RTS_RESULT result = ERR_OK;
	RTS_RESULT res;
	TEST_STRUCT *pTest1, *pTest2, *pTest3, *pTest4, *pTest5;

	/*=== Use cases ===*/

	/* Create a new pool */
	res = CreateMemPoolsStatic();
	result = RTS_GETRESULT(res, result);
	res = CreateMemPoolsDynamic();
	result = RTS_GETRESULT(res, result);

	/* Allocate and initialize a new block */
	pTest1 = (TEST_STRUCT *)UseCase_AllocateSingleBlock1(s_hStaticMemPool1, &res);
	result = RTS_GETRESULT(res, result);
	pTest2 = (TEST_STRUCT *)UseCase_AllocateSingleBlock2(s_hStaticMemPool2, &res);
	result = RTS_GETRESULT(res, result);
	pTest3 = (TEST_STRUCT *)UseCase_AllocateSingleBlock1(s_hDynamicMemPool1, &res);
	result = RTS_GETRESULT(res, result);
	pTest4 = (TEST_STRUCT *)UseCase_AllocateSingleBlock2(s_hDynamicMemPool2, &res);
	result = RTS_GETRESULT(res, result);

	/* Iterate over the allocated blocks of a pool */
	res = UseCase_IterateOverAllBlocksInUse_Locking(s_hStaticMemPool1, (void**)&pTest5);
	result = RTS_GETRESULT(res, result);
	res = UseCase_CheckBlock_Locking(s_hDynamicMemPool2, (void*)pTest5);
	result = RTS_GETRESULT(res, result);

	res = UseCase_IterateOverAllBlocksInUse_NearlyLockFree(s_hDynamicMemPool2, (void**)&pTest5);
	result = RTS_GETRESULT(res, result);
	res = UseCase_CheckBlock_NearlyLockFree(s_hDynamicMemPool2, (void*)pTest5);
	result = RTS_GETRESULT(res, result);

	/* Release a block */
	res = UseCase_ReleaseSingleBlock1(pTest1);
	result = RTS_GETRESULT(res, result);
	res = UseCase_ReleaseSingleBlock2(pTest2, &s_nDeletedBlocks);
	result = RTS_GETRESULT(res, result);
	res = UseCase_ReleaseSingleBlock1(pTest3);
	result = RTS_GETRESULT(res, result);
	res = UseCase_ReleaseSingleBlock2(pTest4, &s_nDeletedBlocks);
	result = RTS_GETRESULT(res, result);

	/* Allocate and initialize a new block */
	pTest1 = (TEST_STRUCT *)UseCase_AllocateSingleBlock1(s_hStaticMemPool1, &res);
	result = RTS_GETRESULT(res, result);
	pTest2 = (TEST_STRUCT *)UseCase_AllocateSingleBlock2(s_hStaticMemPool2, &res);
	result = RTS_GETRESULT(res, result);
	pTest3 = (TEST_STRUCT *)UseCase_AllocateSingleBlock2(s_hDynamicMemPool1, &res);
	result = RTS_GETRESULT(res, result);
	pTest4 = (TEST_STRUCT *)UseCase_AllocateSingleBlock2(s_hDynamicMemPool2, &res);
	result = RTS_GETRESULT(res, result);

	/* Release all blocks in a pool */
	res = UseCase_ReleaseAllBlocksInPool1(s_hStaticMemPool1);
	result = RTS_GETRESULT(res, result);
	res = UseCase_ReleaseAllBlocksInPool2(s_hStaticMemPool2, &s_nDeletedBlocks);
	result = RTS_GETRESULT(res, result);
	res = UseCase_ReleaseAllBlocksInPool3(s_hDynamicMemPool1, &s_nDeletedBlocks);
	result = RTS_GETRESULT(res, result);

	/* Release a block while iterating over this pool (block cannot be released but is marked as to delete!) */
	res = UseCase_ReleaseSingleBlockWithinIterator(s_hDynamicMemPool2, pTest4, &s_nDeletedBlocks);
	result = RTS_GETRESULT(res, result);
	/* Release all blocks marked as to delete! */
	res = UseCase_ReleaseAllDeletedBlocksInPool(s_hDynamicMemPool2, &s_nDeletedBlocks);
	result = RTS_GETRESULT(res, result);

	/* Delete all blocks */
	res = DeleteMemPools();
	result = RTS_GETRESULT(res, result);
	return result;
}


/*=== Hash use cases ===*/
static RTS_RESULT CreateMemPoolHashed(void)
{
	MemPoolConfiguration poolConf;
	RTS_RESULT result;

	/*=== Variant 2: Recommended style ===*/
	memset(&poolConf, 0, sizeof(poolConf));

	poolConf.options = MEM_POOL_OPTION_STATIC;
	poolConf.pfDeleteFunction = BlockDelete;
	poolConf.config.stat.pMemory = s_TestPoolHashed;
	poolConf.config.stat.ulMemSize = sizeof(s_TestPoolHashed);
	poolConf.config.stat.ulBlockSize = sizeof(TEST_STRUCT);

	s_hStaticMemPoolHashed = CAL_MemPoolCreate(&poolConf, &result);
	if (result != ERR_OK)
		return result;

	if (CHK_MemPoolCreateHashTable2)
		s_hMemPoolHashTable = CAL_MemPoolCreateHashTable2(s_hStaticMemPoolHashed, TEST_NUM_OF_HASHTABLE_ENTRIES, s_aHashTableBuffer, COMPONENT_NAME, &result);
	return result;
}

static RTS_RESULT DeleteMemPoolHashed(void)
{
	RTS_RESULT result = ERR_OK;
	RTS_RESULT res;

	if (CHK_MemPoolDeleteHashTable && s_hMemPoolHashTable != RTS_INVALID_HANDLE)
	{
		res = CAL_MemPoolDeleteHashTable(s_hMemPoolHashTable);
		result = RTS_GETRESULT(res, result);
	}
	res = CAL_MemPoolDelete(s_hStaticMemPoolHashed, COMPONENT_NAME);
	result = RTS_GETRESULT(res, result);
	
	return result;
}

static RTS_HANDLE UseCase_AllocateSingleBlock_Hashed(RTS_RESULT *pResult)
{
	RTS_RESULT result = ERR_OK;
	RTS_RESULT res;
	RTS_HANDLE hMemPoolUniqueHandle = RTS_INVALID_HANDLE;

	if (CHK_MemPoolGetBlockHashed && s_hMemPoolHashTable != RTS_INVALID_HANDLE)
	{
		void *pBlock;

		hMemPoolUniqueHandle = CAL_MemPoolGetBlockHashed(s_hMemPoolHashTable, 1, &res);
		result = RTS_GETRESULT(res, result);

		pBlock = CAL_MemPoolGetBlockByHash(s_hMemPoolHashTable, hMemPoolUniqueHandle, &res);
		result = RTS_GETRESULT(res, result);

		/* INIT BLOCK begin */

		/* TODO:
		Here you can initialize the content of new block before usage! You are in a safe state of the block and no one can allocate the same block and no one see
		this block in an iteration sequence!
		*/

		/* INIT BLOCK end */

		/* Add block to used list in pool */
		if (pBlock != NULL)
		{
			/* NOTE: After calling this function, the block is visible in every iteration sequence! So before calling this function, the block must be completely initialized! */
			result = CAL_MemPoolAddUsedBlock(pBlock);
		}
	}
	return hMemPoolUniqueHandle;
}

static RTS_RESULT UseCase_ReleaseSingleBlock_Hashed(RTS_HANDLE hMemPoolUniqueHandle)
{
	RTS_RESULT result = ERR_OK;
	RTS_RESULT res;

	if (CHK_MemPoolRemoveBlockHashed && s_hMemPoolHashTable != RTS_INVALID_HANDLE)
	{
		void *pBlock;

		CAL_MemPoolLock(s_hStaticMemPoolHashed);

		pBlock = CAL_MemPoolGetBlockByHash(s_hMemPoolHashTable, hMemPoolUniqueHandle, &res);
		result = RTS_GETRESULT(res, result);
		if (pBlock == NULL)
		{
			CAL_MemPoolUnlock(s_hStaticMemPoolHashed);
			return ERR_NO_OBJECT;
		}

		res = CAL_MemPoolRemoveBlockHashed(s_hMemPoolHashTable, hMemPoolUniqueHandle);
		result = RTS_GETRESULT(res, result);

		res = CAL_MemPoolPutBlock(pBlock);
		result = RTS_GETRESULT(res, result);
		
		CAL_MemPoolLock(s_hStaticMemPoolHashed);
	}
	return result;
}

/*
	You have to use a mempool hash around a standard mempool to get always a unique handle on every memory block!
	REASON:
	Typically if you alloc a mempool block and if you release it, you get back the same pointer/ handle if you try to alloc a new block the second time afterwards!
	This can cause problems, if the handle to the old block is still in use an cannot recognize the reusage of the block. 
*/
static RTS_RESULT CDECL HashUseCases(void)
{
	RTS_RESULT result = ERR_OK;
	RTS_RESULT res;
	TEST_STRUCT *pTest1, *pTest2, *pTest;
	RTS_HANDLE hMemPoolUniqueHandle1, hMemPoolUniqueHandle2;
	
	/* Create a static mempool with a static hashtable around */
	res = CreateMemPoolHashed();
	result = RTS_GETRESULT(res, result);

	/* Allocate a single block with a unique handle:
	   hMemPoolUniqueHandle1 is the handle that can be returned to the caller as unique handle to the block! */
	hMemPoolUniqueHandle1 = UseCase_AllocateSingleBlock_Hashed(&res);
	result = RTS_GETRESULT(res, result);

	/* With this call you can convert a hashed handle back to the data of the mempool block and can use the content */
	pTest1 = (TEST_STRUCT *)CAL_MemPoolGetBlockByHash(s_hMemPoolHashTable, hMemPoolUniqueHandle1, &res);

	/* Release mempool block specified by its handle 
	   After this call hMemPoolUniqueHandle1 is not valid anymore!
	*/
	res = UseCase_ReleaseSingleBlock_Hashed(hMemPoolUniqueHandle1);
	result = RTS_GETRESULT(res, result);


	/* Allocate a single block with a unique handle once more:
	   hMemPoolUniqueHandle2 is the handle that can be returned to the caller as unique handle to the block! Is different to hMemPoolUniqueHandle1.
	*/
	hMemPoolUniqueHandle2 = UseCase_AllocateSingleBlock_Hashed(&res);
	result = RTS_GETRESULT(res, result);

	if (hMemPoolUniqueHandle1 == hMemPoolUniqueHandle2)
		result = RTS_GETRESULT(ERR_FAILED, result);

	/* With this call you can convert a hashed handle back to the data of the mempool block and can use the content */
	pTest2 = (TEST_STRUCT *)CAL_MemPoolGetBlockByHash(s_hMemPoolHashTable, hMemPoolUniqueHandle2, &res);

	/* hMemPoolUniqueHandle1 is not valid anymore and this can be checked here */
	pTest = (TEST_STRUCT *)CAL_MemPoolGetBlockByHash(s_hMemPoolHashTable, hMemPoolUniqueHandle1, &res);
	if (pTest != NULL)
		result = RTS_GETRESULT(ERR_FAILED, result);

	res = UseCase_ReleaseSingleBlock_Hashed(hMemPoolUniqueHandle2);
	result = RTS_GETRESULT(res, result);

	res = DeleteMemPoolHashed();
	result = RTS_GETRESULT(res, result);
	return result;
}


/*=== Test cases ===*/
static RTS_RESULT TestCase_InsertAddAppend(RTS_HANDLE hPool)
{
	int i;
	MemIterator m;
	RTS_RESULT result;
	TEST_STRUCT *pTest1, *pTest2, *pTest3, *pTest4, *pTest5, *pTest;

	pTest1 = (TEST_STRUCT *)CAL_MemPoolGetBlock2(hPool, 1, COMPONENT_NAME, &result);
	pTest1->ul = 1;
	result = CAL_MemPoolAppendUsedBlock(pTest1);

	pTest2 = (TEST_STRUCT *)CAL_MemPoolGetBlock2(hPool, 1, COMPONENT_NAME, &result);
	pTest2->ul = 2;
	result = CAL_MemPoolAppendUsedBlock(pTest2);

	pTest3 = (TEST_STRUCT *)CAL_MemPoolGetBlock2(hPool, 1, COMPONENT_NAME, &result);
	pTest3->ul = 3;
	result = CAL_MemPoolInsertUsedBlock(NULL, pTest3);

	pTest4 = (TEST_STRUCT *)CAL_MemPoolGetBlock2(hPool, 1, COMPONENT_NAME, &result);
	pTest4->ul = 4;
	result = CAL_MemPoolInsertUsedBlock(pTest1, pTest4);

	pTest5 = (TEST_STRUCT *)CAL_MemPoolGetBlock2(hPool, 1, COMPONENT_NAME, &result);
	pTest5->ul = 5;
	result = CAL_MemPoolAddUsedBlock(pTest5);

	i = 1;
	(void)MEM_GET_FIRST(hPool, &m);
	while (MEM_GET_NEXT(&m))
	{
		pTest = (TEST_STRUCT *)MEM_GET_DATA(&m);
		switch (i)
		{
			case 1:
				if (pTest->ul != 5)
					result = ERR_FAILED;
				break;
			case 2:
				if (pTest->ul != 3)
					result = ERR_FAILED;
				break;
			case 3:
				if (pTest->ul != 1)
					result = ERR_FAILED;
				break;
			case 4:
				if (pTest->ul != 4)
					result = ERR_FAILED;
				break;
			case 5:
				if (pTest->ul != 2)
					result = ERR_FAILED;
				break;
			default:
				result = ERR_FAILED;
				break;
		}
		i++;
	}
	CAL_MemPoolReleaseBlocks(hPool, FALSE, NULL);
	return result;
}


static RTS_RESULT TestCase_DeleteBlockDuringIteration(RTS_HANDLE hPool)
{
	int i = 0;
	int nElements = 0;
	MemIterator m;
	RTS_RESULT result;
	TEST_STRUCT *pTest1, *pTest2, *pTest3, *pTest;

	s_nDeletedBlocks = 0;

	pTest1 = (TEST_STRUCT *)CAL_MemPoolGetBlock2(hPool, 1, COMPONENT_NAME, &result);
	pTest1->ul = 111;
	result = CAL_MemPoolAppendUsedBlock(pTest1);
	pTest2 = (TEST_STRUCT *)CAL_MemPoolGetBlock2(hPool, 1, COMPONENT_NAME, &result);
	pTest2->ul = 222;
	result = CAL_MemPoolAppendUsedBlock(pTest2);
	pTest3 = (TEST_STRUCT *)CAL_MemPoolGetBlock2(hPool, 1, COMPONENT_NAME, &result);
	pTest3->ul = 333;
	result = CAL_MemPoolAppendUsedBlock(pTest3);

	/*=== Add ref ===*/
	CAL_MemPoolAddRef_LF(hPool);

	(void)MEM_GET_FIRST(hPool, &m);
	while (MEM_GET_NEXT(&m))
	{
		if (i == 0)
		{
			/*=== Delete sequence ===*/
			result = CAL_MemPoolRemoveUsedBlock_LF(pTest1);
			if (result == ERR_OK)
			{
				/* Delete object */
				CAL_MemPoolPutBlock_LF(pTest1, &s_nDeletedBlocks);
			}
			/*=== Delete sequence ===*/
		}
		i++;

		pTest = (TEST_STRUCT *)MEM_GET_DATA_SKIP_DELETE(&m);	/*<== New MEM_GET_DATA operator which returns NULL for deleted objects! */
		if (pTest != NULL)
		{
			/* Valid block */
			nElements++;
		}
	}

	if (nElements != 2)
	{
		CAL_MemPoolReleaseRef_LF(hPool);
		return ERR_FAILED;
	}

	/* Only release deleted blocks! */
	result = CAL_MemPoolReleaseBlocks(hPool, TRUE, &s_nDeletedBlocks);
	if (result != ERR_PENDING)
	{
		CAL_MemPoolReleaseRef_LF(hPool);
		return ERR_FAILED;
	}

	/*=== Release ref ===*/
	CAL_MemPoolReleaseRef_LF(hPool);

	if (s_nDeletedBlocks != 0)
		return ERR_FAILED;

	/* Only release deleted blocks! */
	CAL_MemPoolReleaseBlocks(hPool, TRUE, &s_nDeletedBlocks);
	if (s_nDeletedBlocks != 1)
		return ERR_FAILED;

	/* Release all blocks! */
	CAL_MemPoolReleaseBlocks(hPool, FALSE, &s_nDeletedBlocks);
	if (s_nDeletedBlocks != 3)
		return ERR_FAILED;

	return ERR_OK;
}

static RTS_RESULT CDECL TestCases(void)
{
	RTS_RESULT result = ERR_OK;
	RTS_RESULT res;

	/*=== Test cases ===*/
	/* Create a new pool */
	res = CreateMemPoolsStatic();
	result = RTS_GETRESULT(res, result);

	res = TestCase_InsertAddAppend(s_hStaticMemPool1);
	result = RTS_GETRESULT(res, result);

	res = TestCase_DeleteBlockDuringIteration(s_hStaticMemPool2);
	result = RTS_GETRESULT(res, result);

	/* Delete all blocks */
	res = DeleteMemPools();
	result = RTS_GETRESULT(res, result);
	return result;
}

/*================== Examples ==================*/
RTS_RESULT CDECL MemPoolExamples(void)
{
	RTS_RESULT result = ERR_OK;
	static RTS_BOOL s_bFirst = TRUE;

	if (!s_bFirst)
		return ERR_OK;

	s_bFirst = FALSE;

	/*=== Mempool standard use cases ===*/
	result = RTS_GETRESULT( StandardUseCases(), result );

	/*=== Mempool hash use cases ===*/
	result = RTS_GETRESULT( HashUseCases(), result );

	/*=== Test cases ===*/
	result = RTS_GETRESULT( TestCases(), result );
		
	/* ATTENTION: This is only testcode to detect any error in the template implementation! Don't use RTS_ASSERT() in realtime controller software! */
	if (result != ERR_OK)
		RTS_ASSERT(result == ERR_OK);
	return result;
}
