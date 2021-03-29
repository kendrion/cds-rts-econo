/**
 * <name>CmpSysLog</name>
 * <description> 
 *	logger backend for linux syslog.
 * </description>
 *
 * <copyright>(c) 2003-2020 3S-Smart Software Solutions</copyright>
 */
SET_COMPONENT_NAME(`CmpSysLog')
COMPONENT_SOURCES(`CmpSysLog.c')

COMPONENT_VERSION(`0x03051000')

/* NOTE: REPLACE 0x0001 BY YOUR VENDORID */
COMPONENT_VENDORID(`0x0001')				

#define CMPID_CmpSysLog		0x2000								/* NOTE: START HERE WITH YOUR COMPONENTIDS (see CmpItf.h */
#define CLASSID_CCmpSysLog	ADDVENDORID(CMP_VENDORID, 0x2000)	/* NOTE: START HERE WITH YOUR CLASSIDS (see CmpItf.h */
#define ITFID_ICmpSysLog		ADDVENDORID(CMP_VENDORID, 0x2000)	/* NOTE: START HERE WITH YOUR INTERFACEIDS (see CmpItf.h */

CATEGORY(`System')

USE_ITF(`CMItf.m4')
USE_ITF(`CMUtilsItf.m4')

IMPLEMENT_ITF(`CmpLogBackendItf.m4')

REQUIRED_IMPORTS(
CMGetCmpName,
CMRegisterInstance,
CMUtlSafeStrCpy,
CMUtlsnprintf)

