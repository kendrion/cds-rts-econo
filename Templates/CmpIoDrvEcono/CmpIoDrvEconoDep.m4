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
SET_COMPONENT_NAME(`CmpIoDrvEcono')
COMPONENT_SOURCES(`CmpIoDrvEcono.c')

COMPONENT_VERSION(`0x03050E00')

/* NOTE: REPLACE 0x0001 BY YOUR VENDORID */
COMPONENT_VENDORID(`0x0001')				

#define CMPID_CmpIoDrvEcono		0x2000								/* NOTE: START HERE WITH YOUR COMPONENTIDS (see CmpItf.h */
#define CLASSID_CCmpIoDrvEcono	ADDVENDORID(CMP_VENDORID, 0x2000)	/* NOTE: START HERE WITH YOUR CLASSIDS (see CmpItf.h */
#define ITFID_ICmpIoDrvEcono		ADDVENDORID(CMP_VENDORID, 0x2000)	/* NOTE: START HERE WITH YOUR INTERFACEIDS (see CmpItf.h */

CATEGORY(`Templates')

USE_ITF(`CMUtilsItf.m4')
USE_ITF(`SysFileItf.m4')

IMPLEMENT_ITF(`CmpIoDrvEconoItf.m4')

REQUIRED_IMPORTS(
CMUtlSafeStrCpy)

OPTIONAL_IMPORTS(
SysFileOpen,
SysFileClose,
SysFileRead,
SysFileWrite)
