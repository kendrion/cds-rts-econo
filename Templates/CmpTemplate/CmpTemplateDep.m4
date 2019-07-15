/**
 *  <name>Component Template</name>
 *  <description> 
 *  An example on how to implement a component.
 *  This component does no usefull work and it exports no functions
 *  which are intended to be used for anything. Use at your own risk.
 *  </description>
 *  <copyright>
 *  Copyright (c) 2017-2018 CODESYS GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 *  </copyright>
 */
SET_COMPONENT_NAME(`CmpTemplate')
COMPONENT_SOURCES(`CmpTemplate.c')

COMPONENT_VERSION(`0x03050E00')

/* NOTE: REPLACE 0x0001 BY YOUR VENDORID */
COMPONENT_VENDORID(`0x0001')				

#define CMPID_CmpTemplate		0x2000								/* NOTE: START HERE WITH YOUR COMPONENTIDS (see CmpItf.h */
#define CLASSID_CCmpTemplate	ADDVENDORID(CMP_VENDORID, 0x2000)	/* NOTE: START HERE WITH YOUR CLASSIDS (see CmpItf.h */
#define ITFID_ICmpTemplate		ADDVENDORID(CMP_VENDORID, 0x2000)	/* NOTE: START HERE WITH YOUR INTERFACEIDS (see CmpItf.h */

CATEGORY(`Templates')

IMPLEMENT_ITF(`CmpTemplateItf.m4',`CmpEventCallbackItf.m4')

USE_ITF(`CMItf.m4')
USE_ITF(`CmpSrvItf.m4')
USE_ITF(`CmpBinTagUtilItf.m4')
USE_ITF(`SysTaskItf.m4')
USE_ITF(`SysMemItf.m4')
USE_ITF(`CmpSettingsItf.m4')
USE_ITF(`CmpAppItf.m4')
USE_ITF(`CmpAppBPItf.m4')
USE_ITF(`CmpIecTaskItf.m4')
USE_ITF(`CmpEventMgrItf.m4')
USE_ITF(`SysTimeItf.m4')
USE_ITF(`SysEventItf.m4')
USE_ITF(`SysExceptItf.m4')
USE_ITF(`CmpScheduleItf.m4')
USE_ITF(`SysCpuHandlingItf.m4')
USE_ITF(`CmpFileTransferItf.m4')
USE_ITF(`CmpMonitorItf.m4')
USE_ITF(`CmpIecVarAccessItf.m4')
USE_ITF(`SysTimeRtcItf.m4')
USE_ITF(`CmpUserMgrItf.m4')
USE_ITF(`CmpSupervisorItf.m4')
USE_ITF(`CMUtilsItf.m4')
USE_ITF(`CmpMemPoolItf.m4')
USE_ITF(`CmpMemPoolHashItf.m4')

REQUIRED_IMPORTS(
ServerRegisterServiceHandler,
ServerUnRegisterServiceHandler,
ServerFinishRequest,
SysMemAllocData,
SysMemFreeData,
SysMemAllocCode,
SysMemFreeCode,
SysMemAllocArea,
SysMemFreeArea,
SettgSetStringValue,
SettgGetStringValue,
SettgSetIntValue,
SettgGetIntValue,
BTagWriterInit,
BTagWriterStartTag,
BTagWriterAppendWString,
BTagWriterAppendBlob,
BTagWriterAppendFillBytes,
BTagWriterEndTag,
BTagWriterFinish,
BTagReaderInit,
BTagReaderMoveNext,
BTagReaderGetTagId,
BTagReaderGetTagLen,
BTagReaderIsDataTag,
BTagReaderGetContent,
BTagReaderSkipContent,
BTagReaderGetString,
BTagReaderPeekNext,
BTagReaderGetFirstTag,
BTagReaderGetNextTag,
BTagWriteSingleTag,
AppGetApplicationByIndex,
AppGetAreaPointerByType,
AppStartApplications,
AppStopApplications,
AppSaveAllRetainAreas,
AppExitApplications,
AppGetFirstApp,
AppGetNextApp,
IecTaskGetDesc,
IecTaskGetFirst2,
IecTaskGetNext2,
EventCreate,
EventCreate2,
EventDelete,
EventOpen,
EventClose,
EventRegisterCallbackFunction,
EventUnregisterCallbackFunction,
EventRegisterCallback,
EventUnregisterCallback,
EventPost,
EventPostByEvent,
SysCpuCallIecFuncWithParams,
SysEventSet,
IecTaskCycle,
CMExit,
SchedRegisterExternalEvent,
SchedPostExternalEvent,
SchedUnregisterExternalEvent,
CMUtlvsnprintf,
MemPoolCreateStatic,
MemPoolCreateDynamic,
MemPoolCreate,
MemPoolDelete,
MemPoolGetBlock,
MemPoolGetBlock2,
MemPoolExtendDynamic,
MemPoolPutBlock,
MemPoolPutBlock_LF,
MemPoolAddUsedBlock,
MemPoolRemoveUsedBlock,
MemPoolRemoveUsedBlock_LF,
MemPoolAddUsedBlockToPool,
MemPoolAppendUsedBlock,
MemPoolInsertUsedBlock,
MemPoolRemoveUsedBlockFromPool,
MemPoolIsValidBlock,
MemPoolLock,
MemPoolUnlock,
MemPoolLockBlock,
MemPoolUnlockBlock,
MemPoolAddRef_LF,
MemPoolReleaseRef_LF,
MemPoolLock_LF,
MemPoolUnlock_LF,
MemPoolReleaseBlocks,
MemPoolIsValidBlock_LF)

OPTIONAL_IMPORTS(
SysMemIsValidPointer,
IecVarAccGetNodeFullPath3,
SysTaskWaitSleep,
SysTaskGetByOSHandle,
SysTaskGetName,
SysTaskCreate,
SysTaskResume,
SysTaskWaitSleep,
SysTaskSetExit,
SysTaskExit,
SysTaskEnd,
SysTaskEnter,
SysTaskLeave,
SysTimeGetMs,
SysTimeRtcGet,
SysTimeRtcSet,
UserMgrObjectAdd,
UserMgrObjectRemove,
UserMgrObjectOpen,
UserMgrObjectClose,
UserMgrHasAccessRights,
UserMgrAddOnlineAccessError,
SupervisorOperationGetState2,
SupervisorOperationRegister,
SupervisorOperationUnregister,
SupervisorOperationEnable,
SupervisorOperationDisable,
SupervisorOperationAlive,
SupervisorOperationDead,
SupervisorOperationGetEntry,
SysTaskGetHandleByOSHandle,
MemPoolCreateHashTable2,
MemPoolDeleteHashTable,
MemPoolGetBlockHashed,
MemPoolGetBlockByHash,
MemPoolRemoveBlockHashed)
