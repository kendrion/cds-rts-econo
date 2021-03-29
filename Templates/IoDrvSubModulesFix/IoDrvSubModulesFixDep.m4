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
SET_COMPONENT_NAME(`IoDrvSubModulesFix')
COMPONENT_SOURCES(`IoDrvSubModulesFix.c')

COMPONENT_VERSION(`0x03051000')

/* NOTE: REPLACE 0x0001 BY YOUR VENDORID */
COMPONENT_VENDORID(`0x0001')				

#define CMPID_IoDrvSubModulesFix		0x2000		/* NOTE: START HERE WITH YOUR COMPONENTIDS (see CmpItf.h */
#define CLASSID_CIoDrvSubModulesFix	0x2000		/* NOTE: START HERE WITH YOUR CLASSIDS (see CmpItf.h */
#define ITFID_IIoDrvVErySimple		0x2000		/* NOTE: START HERE WITH YOUR INTERFACEIDS (see CmpItf.h */

CATEGORY(`Customer')

IMPLEMENT_ITF(`CmpIoDrvItf.m4')

USE_ITF(`CmpIoMgrItf.m4')

REQUIRED_IMPORTS(
IoMgrConfigGetParameter,
IoMgrConfigGetFirstConnector,
IoMgrConfigGetNextConnector,
IoMgrConfigGetFirstChild,
IoMgrConfigGetNextChild,
IoMgrConfigGetParameterValueWord,
IoMgrConfigSetDiagnosis,
IoMgrConfigResetDiagnosis,
IoMgrRegisterInstance,
IoMgrUnregisterInstance,
IoMgrSetDriverProperties,
IoDrvCreate,
IoDrvDelete,
IoMgrCopyInputLE,
IoMgrCopyOutputLE)

