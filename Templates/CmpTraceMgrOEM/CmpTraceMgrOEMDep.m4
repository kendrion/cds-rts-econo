/**
 *  <name>Component Template for the TraceManager</name>
 *  <description> 
 *  An example on how to implement an own component that uses the CmpTraceMgr.
 *  Here an own system variable is handled.
 *  </description>
 *  <copyright>
 *  Copyright (c) 2017-2018 CODESYS GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 *  </copyright>
 */
SET_COMPONENT_NAME(`CmpTraceMgrOEM')
COMPONENT_SOURCES(`CmpTraceMgrOEM.c')

COMPONENT_VERSION(`0x03050E00')

/* NOTE: REPLACE 0x0001 BY YOUR VENDORID */
COMPONENT_VENDORID(`0x0001')				

#define CMPID_CmpTraceMgrOEM		0x200A								/* NOTE: START HERE WITH YOUR COMPONENTIDS (see CmpItf.h */
#define CLASSID_CCmpTraceMgrOEM	ADDVENDORID(CMP_VENDORID, 0x200A)	/* NOTE: START HERE WITH YOUR CLASSIDS (see CmpItf.h */
#define ITFID_ICmpTraceMgrOEM		ADDVENDORID(CMP_VENDORID, 0x200A)	/* NOTE: START HERE WITH YOUR INTERFACEIDS (see CmpItf.h */

CATEGORY(`Templates.TraceMgr')

IMPLEMENT_ITF(`CmpTraceMgrOEMItf.m4',`CmpEventCallbackItf.m4')

USE_ITF(`CmpEventMgrItf.m4')
USE_ITF(`CmpTraceMgrItf.m4')

REQUIRED_IMPORTS(
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
TraceMgrPacketCreate,
TraceMgrPacketDelete,
TraceMgrRecordAdd,
TraceMgrRecordRemove,
TraceMgrPacketComplete,
TraceMgrPacketStart,
TraceMgrRecordUpdate2,
TraceMgrRecordUpdate3,
TraceMgrPacketGetState,
TraceMgrRecordGetConfig)

OPTIONAL_IMPORTS(
EventOpen,
EventClose,
EventRegisterCallbackFunction,
EventUnregisterCallbackFunction)

