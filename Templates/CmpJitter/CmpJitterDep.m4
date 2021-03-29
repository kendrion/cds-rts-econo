/**
 *  <name>Component Template</name>
 *  <description> 
 *  An example on how to implement a component.
 *  This component does no usefull work and it exports no functions
 *  which are intended to be used for anything. Use at your own risk.
 *  </description>
 *  <copyright>
 *  Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 *  </copyright>
 */
SET_COMPONENT_NAME(`CmpJitter')
COMPONENT_SOURCES(`CmpJitter.c')

COMPONENT_VERSION(`0x03051000')

/* NOTE: REPLACE 0x0001 BY YOUR VENDORID */
COMPONENT_VENDORID(`0x0001')				

#define CMPID_CmpJitter		0x2000								/* NOTE: START HERE WITH YOUR COMPONENTIDS (see CmpItf.h */
#define CLASSID_CCmpJitter	ADDVENDORID(CMP_VENDORID, 0x2000)	/* NOTE: START HERE WITH YOUR CLASSIDS (see CmpItf.h */
#define ITFID_ICmpJitter		ADDVENDORID(CMP_VENDORID, 0x2000)	/* NOTE: START HERE WITH YOUR INTERFACEIDS (see CmpItf.h */

CATEGORY(`Templates')

IMPLEMENT_ITF(`CmpEventCallbackItf.m4')

USE_ITF(`CmpSrvItf.m4')
USE_ITF(`CmpBinTagUtilItf.m4')
USE_ITF(`SysTaskItf.m4')
USE_ITF(`SysMemItf.m4')
USE_ITF(`CmpSettingsItf.m4')
USE_ITF(`CmpAppItf.m4')
USE_ITF(`CmpAppBPItf.m4')
USE_ITF(`CmpEventMgrItf.m4')
USE_ITF(`SysTimeItf.m4')
USE_ITF(`SysEventItf.m4')
USE_ITF(`CmpScheduleItf.m4')
USE_ITF(`SysCpuHandlingItf.m4')
USE_ITF(`CmpIecTaskItf.m4')
USE_ITF(`SysSocketItf.m4')
USE_ITF(`SysMsgQItf.m4')

REQUIRED_IMPORTS(
ServerRegisterServiceHandler,
ServerUnRegisterServiceHandler,
ServerFinishRequest,
SysMemAllocData,
SysMemFreeData,
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
AppGetFirstApp,
AppGetNextApp,
IecTaskGetFirst,
IecTaskGetNext,
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
SysSockPing,
SysTimeGetMs,
SysTaskCreate,
SysTaskEnter,
SysMsgQRecv,
SysTaskLeave,
SysTaskEnd,
SysTaskResume,
SysTaskExit,
SysMsgQCreate,
SysMsgQSend)

OPTIONAL_IMPORTS(
SysMemIsValidPointer)
