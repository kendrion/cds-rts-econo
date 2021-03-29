/**
 *  <name>Component Template</name>
 *  <description> 
 *  Very simple example about using runtime system events.
 *  This component does no usefull work and it exports no functions
 *  which are intended to be used for anything. Use at your own risk.
 *  </description>
 *  <copyright>
 *  Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 *  </copyright>
 */
SET_COMPONENT_NAME(`CmpTemplateEvent')
COMPONENT_SOURCES(`CmpTemplateEvent.c')

COMPONENT_VERSION(`0x03051000')

/* NOTE: REPLACE 0x0001 BY YOUR VENDORID */
COMPONENT_VENDORID(`0x0001')				

#define CMPID_CmpTemplateEvent		0x2000								/* NOTE: START HERE WITH YOUR COMPONENTIDS (see CmpItf.h */
#define CLASSID_CCmpTemplateEvent	ADDVENDORID(CMP_VENDORID, 0x2000)	/* NOTE: START HERE WITH YOUR CLASSIDS (see CmpItf.h */
#define ITFID_ICmpTemplateEvent		ADDVENDORID(CMP_VENDORID, 0x2000)	/* NOTE: START HERE WITH YOUR INTERFACEIDS (see CmpItf.h */

CATEGORY(`Templates')

USE_ITF(`CMItf.m4')
USE_ITF(`CmpAppItf.m4')
USE_ITF(`CmpMonitorItf.m4')
USE_ITF(`CmpEventMgrItf.m4')

REQUIRED_IMPORTS(
EventOpen,
EventClose,
EventPost,
EventRegisterCallbackFunction,
EventUnregisterCallbackFunction)

