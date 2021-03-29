 /**
 * <interfacename>CmpDeviceManagement</interfacename>
 * <description> 
 *  === PROTOTYPE: DONT USE YET! ===
 *  Component which implements the device management functions like install/update/backup/restore of the complete firmware.
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */
 

	
	
#ifndef _CMPDEVICEMANAGEMENTITF_H_
#define _CMPDEVICEMANAGEMENTITF_H_

#include "CmpStd.h"

 

 




#include "CmpItf.h"

/**
 * <category>Static defines</category>
 * <description>Default number of static containers</description>
 */
#ifndef DM_NUM_OF_STATIC_CONTAINERS
	#define DM_NUM_OF_STATIC_CONTAINERS		1
#endif

/**
 * <category>Static defines</category>
 * <description>Default number of static packages</description>
 */
#ifndef DM_NUM_OF_STATIC_PACKAGES
	#define DM_NUM_OF_STATIC_PACKAGES		5
#endif

/**
 * <category>Static defines</category>
 * <description>Placeholder for the firmware folder</description>
 */
#define DMS_BACKUP_SOURCE_DIR				"$Firmware$"

/**
 * <category>Static defines</category>
 * <description>Placeholder to write backup packages to or to install update/installation packages from</description>
 */
#define DMS_BACKUP_DESTINATION_DIR			"$FWPackage$"

/**
 * <category>Compiler switch</category>
 * <description>
 *	Compiler switches to enable/disable single features in the component.
 * </description>
 * <element name="CMPDEVICEMANAGEMENT_STANDALONE">Component is included in a standalone runtime</element>
 * <element name="CMPDEVICEMANAGEMENT_CLIENT">Runtime is one client of the DeviceManagementService!
 *                                            NOTE:
 *                                            DeviceManagementService must be compiled without any compiler switch!</element>
 */


/**
 * <category>Event parameter</category>
 * <element name="pApp" type="IN">Pointer to application description</element>
 * <element name="bDeny" type="OUT">1=Download is denied, 0=download is executed</element>
 */
typedef struct
{
	RTS_UTF8STRING *psuDestPath;
	RTS_RESULT Result;
} EVTPARAM_CmpDeviceManagement_Backup;
#define EVTPARAMID_CmpDeviceManagement_PrepareBackup		0x0001
#define EVTVERSION_CmpDeviceManagement_PrepareBackup		0x0001


/**
 * <category>Events</category>
 * <description>Event is sent before backup the firmware</description>
 * <param name="pEventParam" type="IN">EVTPARAM_CmpApp</param>
 */
#define EVT_DEVICEMANAGEMENT_PREPARE_BACKUP					MAKE_EVENTID(EVTCLASS_INFO, 1)

typedef struct DM_PACKAGE_CONFIGURATION_
{
	RTS_UTF8STRING *pDescription;
	RTS_UTF8STRING *pVersion;
	RTS_UTF8STRING *pBinding;
	RTS_UTF8STRING *pSecrets;
	RTS_UTF8STRING *pPackageDependency;
	RTS_UTF8STRING *pSrcDir;
	RTS_UTF8STRING *pDestDir;
	RTS_UTF8STRING *pPreInstallCommand;
	RTS_UTF8STRING *pInstallCommand;
	RTS_UTF8STRING *pPostInstallCommand;
	RTS_UTF8STRING *pPreRemoveCommand;
	RTS_UTF8STRING *pPostRemoveCommand;
} DM_PACKAGE_CONFIGURATION;

/** EXTERN LIB SECTION BEGIN **/
/** EXTERN LIB SECTION END **/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description>
 * </description>
 * <result></result>
 */
RTS_HANDLE CDECL DMContainerCreate(RTS_UTF8STRING *pName, RTS_UTF8STRING *pFilePath, RTS_RESULT *pResult);
typedef RTS_HANDLE (CDECL * PFDMCONTAINERCREATE) (RTS_UTF8STRING *pName, RTS_UTF8STRING *pFilePath, RTS_RESULT *pResult);
#if defined(CMPDEVICEMANAGEMENT_NOTIMPLEMENTED) || defined(DMCONTAINERCREATE_NOTIMPLEMENTED)
	#define USE_DMContainerCreate
	#define EXT_DMContainerCreate
	#define GET_DMContainerCreate(fl)  ERR_NOTIMPLEMENTED
	#define CAL_DMContainerCreate(p0,p1,p2)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_DMContainerCreate  FALSE
	#define EXP_DMContainerCreate  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_DMContainerCreate
	#define EXT_DMContainerCreate
	#define GET_DMContainerCreate(fl)  CAL_CMGETAPI( "DMContainerCreate" ) 
	#define CAL_DMContainerCreate  DMContainerCreate
	#define CHK_DMContainerCreate  TRUE
	#define EXP_DMContainerCreate  CAL_CMEXPAPI( "DMContainerCreate" ) 
#elif defined(MIXED_LINK) && !defined(CMPDEVICEMANAGEMENT_EXTERNAL)
	#define USE_DMContainerCreate
	#define EXT_DMContainerCreate
	#define GET_DMContainerCreate(fl)  CAL_CMGETAPI( "DMContainerCreate" ) 
	#define CAL_DMContainerCreate  DMContainerCreate
	#define CHK_DMContainerCreate  TRUE
	#define EXP_DMContainerCreate  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"DMContainerCreate", (RTS_UINTPTR)DMContainerCreate, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpDeviceManagementDMContainerCreate
	#define EXT_CmpDeviceManagementDMContainerCreate
	#define GET_CmpDeviceManagementDMContainerCreate  ERR_OK
	#define CAL_CmpDeviceManagementDMContainerCreate pICmpDeviceManagement->IDMContainerCreate
	#define CHK_CmpDeviceManagementDMContainerCreate (pICmpDeviceManagement != NULL)
	#define EXP_CmpDeviceManagementDMContainerCreate  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_DMContainerCreate
	#define EXT_DMContainerCreate
	#define GET_DMContainerCreate(fl)  CAL_CMGETAPI( "DMContainerCreate" ) 
	#define CAL_DMContainerCreate pICmpDeviceManagement->IDMContainerCreate
	#define CHK_DMContainerCreate (pICmpDeviceManagement != NULL)
	#define EXP_DMContainerCreate  CAL_CMEXPAPI( "DMContainerCreate" ) 
#else /* DYNAMIC_LINK */
	#define USE_DMContainerCreate  PFDMCONTAINERCREATE pfDMContainerCreate;
	#define EXT_DMContainerCreate  extern PFDMCONTAINERCREATE pfDMContainerCreate;
	#define GET_DMContainerCreate(fl)  s_pfCMGetAPI2( "DMContainerCreate", (RTS_VOID_FCTPTR *)&pfDMContainerCreate, (fl), 0, 0)
	#define CAL_DMContainerCreate  pfDMContainerCreate
	#define CHK_DMContainerCreate  (pfDMContainerCreate != NULL)
	#define EXP_DMContainerCreate  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"DMContainerCreate", (RTS_UINTPTR)DMContainerCreate, 0, 0) 
#endif




/**
 * <description>
 * </description>
 * <result></result>
 */
RTS_RESULT CDECL DMContainerClose(RTS_HANDLE hContainer);
typedef RTS_RESULT (CDECL * PFDMCONTAINERCLOSE) (RTS_HANDLE hContainer);
#if defined(CMPDEVICEMANAGEMENT_NOTIMPLEMENTED) || defined(DMCONTAINERCLOSE_NOTIMPLEMENTED)
	#define USE_DMContainerClose
	#define EXT_DMContainerClose
	#define GET_DMContainerClose(fl)  ERR_NOTIMPLEMENTED
	#define CAL_DMContainerClose(p0)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_DMContainerClose  FALSE
	#define EXP_DMContainerClose  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_DMContainerClose
	#define EXT_DMContainerClose
	#define GET_DMContainerClose(fl)  CAL_CMGETAPI( "DMContainerClose" ) 
	#define CAL_DMContainerClose  DMContainerClose
	#define CHK_DMContainerClose  TRUE
	#define EXP_DMContainerClose  CAL_CMEXPAPI( "DMContainerClose" ) 
#elif defined(MIXED_LINK) && !defined(CMPDEVICEMANAGEMENT_EXTERNAL)
	#define USE_DMContainerClose
	#define EXT_DMContainerClose
	#define GET_DMContainerClose(fl)  CAL_CMGETAPI( "DMContainerClose" ) 
	#define CAL_DMContainerClose  DMContainerClose
	#define CHK_DMContainerClose  TRUE
	#define EXP_DMContainerClose  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"DMContainerClose", (RTS_UINTPTR)DMContainerClose, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpDeviceManagementDMContainerClose
	#define EXT_CmpDeviceManagementDMContainerClose
	#define GET_CmpDeviceManagementDMContainerClose  ERR_OK
	#define CAL_CmpDeviceManagementDMContainerClose pICmpDeviceManagement->IDMContainerClose
	#define CHK_CmpDeviceManagementDMContainerClose (pICmpDeviceManagement != NULL)
	#define EXP_CmpDeviceManagementDMContainerClose  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_DMContainerClose
	#define EXT_DMContainerClose
	#define GET_DMContainerClose(fl)  CAL_CMGETAPI( "DMContainerClose" ) 
	#define CAL_DMContainerClose pICmpDeviceManagement->IDMContainerClose
	#define CHK_DMContainerClose (pICmpDeviceManagement != NULL)
	#define EXP_DMContainerClose  CAL_CMEXPAPI( "DMContainerClose" ) 
#else /* DYNAMIC_LINK */
	#define USE_DMContainerClose  PFDMCONTAINERCLOSE pfDMContainerClose;
	#define EXT_DMContainerClose  extern PFDMCONTAINERCLOSE pfDMContainerClose;
	#define GET_DMContainerClose(fl)  s_pfCMGetAPI2( "DMContainerClose", (RTS_VOID_FCTPTR *)&pfDMContainerClose, (fl), 0, 0)
	#define CAL_DMContainerClose  pfDMContainerClose
	#define CHK_DMContainerClose  (pfDMContainerClose != NULL)
	#define EXP_DMContainerClose  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"DMContainerClose", (RTS_UINTPTR)DMContainerClose, 0, 0) 
#endif




/**
 * <description>
 * </description>
 * <result></result>
 */
RTS_UTF8STRING * CDECL DMContainerGetPath(RTS_HANDLE hContainer, RTS_RESULT *pResult);
typedef RTS_UTF8STRING * (CDECL * PFDMCONTAINERGETPATH) (RTS_HANDLE hContainer, RTS_RESULT *pResult);
#if defined(CMPDEVICEMANAGEMENT_NOTIMPLEMENTED) || defined(DMCONTAINERGETPATH_NOTIMPLEMENTED)
	#define USE_DMContainerGetPath
	#define EXT_DMContainerGetPath
	#define GET_DMContainerGetPath(fl)  ERR_NOTIMPLEMENTED
	#define CAL_DMContainerGetPath(p0,p1)  (RTS_UTF8STRING *)ERR_NOTIMPLEMENTED
	#define CHK_DMContainerGetPath  FALSE
	#define EXP_DMContainerGetPath  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_DMContainerGetPath
	#define EXT_DMContainerGetPath
	#define GET_DMContainerGetPath(fl)  CAL_CMGETAPI( "DMContainerGetPath" ) 
	#define CAL_DMContainerGetPath  DMContainerGetPath
	#define CHK_DMContainerGetPath  TRUE
	#define EXP_DMContainerGetPath  CAL_CMEXPAPI( "DMContainerGetPath" ) 
#elif defined(MIXED_LINK) && !defined(CMPDEVICEMANAGEMENT_EXTERNAL)
	#define USE_DMContainerGetPath
	#define EXT_DMContainerGetPath
	#define GET_DMContainerGetPath(fl)  CAL_CMGETAPI( "DMContainerGetPath" ) 
	#define CAL_DMContainerGetPath  DMContainerGetPath
	#define CHK_DMContainerGetPath  TRUE
	#define EXP_DMContainerGetPath  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"DMContainerGetPath", (RTS_UINTPTR)DMContainerGetPath, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpDeviceManagementDMContainerGetPath
	#define EXT_CmpDeviceManagementDMContainerGetPath
	#define GET_CmpDeviceManagementDMContainerGetPath  ERR_OK
	#define CAL_CmpDeviceManagementDMContainerGetPath pICmpDeviceManagement->IDMContainerGetPath
	#define CHK_CmpDeviceManagementDMContainerGetPath (pICmpDeviceManagement != NULL)
	#define EXP_CmpDeviceManagementDMContainerGetPath  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_DMContainerGetPath
	#define EXT_DMContainerGetPath
	#define GET_DMContainerGetPath(fl)  CAL_CMGETAPI( "DMContainerGetPath" ) 
	#define CAL_DMContainerGetPath pICmpDeviceManagement->IDMContainerGetPath
	#define CHK_DMContainerGetPath (pICmpDeviceManagement != NULL)
	#define EXP_DMContainerGetPath  CAL_CMEXPAPI( "DMContainerGetPath" ) 
#else /* DYNAMIC_LINK */
	#define USE_DMContainerGetPath  PFDMCONTAINERGETPATH pfDMContainerGetPath;
	#define EXT_DMContainerGetPath  extern PFDMCONTAINERGETPATH pfDMContainerGetPath;
	#define GET_DMContainerGetPath(fl)  s_pfCMGetAPI2( "DMContainerGetPath", (RTS_VOID_FCTPTR *)&pfDMContainerGetPath, (fl), 0, 0)
	#define CAL_DMContainerGetPath  pfDMContainerGetPath
	#define CHK_DMContainerGetPath  (pfDMContainerGetPath != NULL)
	#define EXP_DMContainerGetPath  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"DMContainerGetPath", (RTS_UINTPTR)DMContainerGetPath, 0, 0) 
#endif




/**
 * <description>
 * </description>
 * <result></result>
 */
RTS_HANDLE CDECL DMPackageCreate(RTS_HANDLE hContainer, RTS_UTF8STRING *pName, RTS_RESULT *pResult);
typedef RTS_HANDLE (CDECL * PFDMPACKAGECREATE) (RTS_HANDLE hContainer, RTS_UTF8STRING *pName, RTS_RESULT *pResult);
#if defined(CMPDEVICEMANAGEMENT_NOTIMPLEMENTED) || defined(DMPACKAGECREATE_NOTIMPLEMENTED)
	#define USE_DMPackageCreate
	#define EXT_DMPackageCreate
	#define GET_DMPackageCreate(fl)  ERR_NOTIMPLEMENTED
	#define CAL_DMPackageCreate(p0,p1,p2)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_DMPackageCreate  FALSE
	#define EXP_DMPackageCreate  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_DMPackageCreate
	#define EXT_DMPackageCreate
	#define GET_DMPackageCreate(fl)  CAL_CMGETAPI( "DMPackageCreate" ) 
	#define CAL_DMPackageCreate  DMPackageCreate
	#define CHK_DMPackageCreate  TRUE
	#define EXP_DMPackageCreate  CAL_CMEXPAPI( "DMPackageCreate" ) 
#elif defined(MIXED_LINK) && !defined(CMPDEVICEMANAGEMENT_EXTERNAL)
	#define USE_DMPackageCreate
	#define EXT_DMPackageCreate
	#define GET_DMPackageCreate(fl)  CAL_CMGETAPI( "DMPackageCreate" ) 
	#define CAL_DMPackageCreate  DMPackageCreate
	#define CHK_DMPackageCreate  TRUE
	#define EXP_DMPackageCreate  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"DMPackageCreate", (RTS_UINTPTR)DMPackageCreate, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpDeviceManagementDMPackageCreate
	#define EXT_CmpDeviceManagementDMPackageCreate
	#define GET_CmpDeviceManagementDMPackageCreate  ERR_OK
	#define CAL_CmpDeviceManagementDMPackageCreate pICmpDeviceManagement->IDMPackageCreate
	#define CHK_CmpDeviceManagementDMPackageCreate (pICmpDeviceManagement != NULL)
	#define EXP_CmpDeviceManagementDMPackageCreate  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_DMPackageCreate
	#define EXT_DMPackageCreate
	#define GET_DMPackageCreate(fl)  CAL_CMGETAPI( "DMPackageCreate" ) 
	#define CAL_DMPackageCreate pICmpDeviceManagement->IDMPackageCreate
	#define CHK_DMPackageCreate (pICmpDeviceManagement != NULL)
	#define EXP_DMPackageCreate  CAL_CMEXPAPI( "DMPackageCreate" ) 
#else /* DYNAMIC_LINK */
	#define USE_DMPackageCreate  PFDMPACKAGECREATE pfDMPackageCreate;
	#define EXT_DMPackageCreate  extern PFDMPACKAGECREATE pfDMPackageCreate;
	#define GET_DMPackageCreate(fl)  s_pfCMGetAPI2( "DMPackageCreate", (RTS_VOID_FCTPTR *)&pfDMPackageCreate, (fl), 0, 0)
	#define CAL_DMPackageCreate  pfDMPackageCreate
	#define CHK_DMPackageCreate  (pfDMPackageCreate != NULL)
	#define EXP_DMPackageCreate  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"DMPackageCreate", (RTS_UINTPTR)DMPackageCreate, 0, 0) 
#endif




/**
 * <description>
 * </description>
 * <result></result>
 */
RTS_RESULT CDECL DMPackageClose(RTS_HANDLE hPackage);
typedef RTS_RESULT (CDECL * PFDMPACKAGECLOSE) (RTS_HANDLE hPackage);
#if defined(CMPDEVICEMANAGEMENT_NOTIMPLEMENTED) || defined(DMPACKAGECLOSE_NOTIMPLEMENTED)
	#define USE_DMPackageClose
	#define EXT_DMPackageClose
	#define GET_DMPackageClose(fl)  ERR_NOTIMPLEMENTED
	#define CAL_DMPackageClose(p0)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_DMPackageClose  FALSE
	#define EXP_DMPackageClose  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_DMPackageClose
	#define EXT_DMPackageClose
	#define GET_DMPackageClose(fl)  CAL_CMGETAPI( "DMPackageClose" ) 
	#define CAL_DMPackageClose  DMPackageClose
	#define CHK_DMPackageClose  TRUE
	#define EXP_DMPackageClose  CAL_CMEXPAPI( "DMPackageClose" ) 
#elif defined(MIXED_LINK) && !defined(CMPDEVICEMANAGEMENT_EXTERNAL)
	#define USE_DMPackageClose
	#define EXT_DMPackageClose
	#define GET_DMPackageClose(fl)  CAL_CMGETAPI( "DMPackageClose" ) 
	#define CAL_DMPackageClose  DMPackageClose
	#define CHK_DMPackageClose  TRUE
	#define EXP_DMPackageClose  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"DMPackageClose", (RTS_UINTPTR)DMPackageClose, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpDeviceManagementDMPackageClose
	#define EXT_CmpDeviceManagementDMPackageClose
	#define GET_CmpDeviceManagementDMPackageClose  ERR_OK
	#define CAL_CmpDeviceManagementDMPackageClose pICmpDeviceManagement->IDMPackageClose
	#define CHK_CmpDeviceManagementDMPackageClose (pICmpDeviceManagement != NULL)
	#define EXP_CmpDeviceManagementDMPackageClose  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_DMPackageClose
	#define EXT_DMPackageClose
	#define GET_DMPackageClose(fl)  CAL_CMGETAPI( "DMPackageClose" ) 
	#define CAL_DMPackageClose pICmpDeviceManagement->IDMPackageClose
	#define CHK_DMPackageClose (pICmpDeviceManagement != NULL)
	#define EXP_DMPackageClose  CAL_CMEXPAPI( "DMPackageClose" ) 
#else /* DYNAMIC_LINK */
	#define USE_DMPackageClose  PFDMPACKAGECLOSE pfDMPackageClose;
	#define EXT_DMPackageClose  extern PFDMPACKAGECLOSE pfDMPackageClose;
	#define GET_DMPackageClose(fl)  s_pfCMGetAPI2( "DMPackageClose", (RTS_VOID_FCTPTR *)&pfDMPackageClose, (fl), 0, 0)
	#define CAL_DMPackageClose  pfDMPackageClose
	#define CHK_DMPackageClose  (pfDMPackageClose != NULL)
	#define EXP_DMPackageClose  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"DMPackageClose", (RTS_UINTPTR)DMPackageClose, 0, 0) 
#endif




/**
 * <description>
 * </description>
 * <result></result>
 */
RTS_RESULT CDECL DMPackageSetConfiguration(RTS_HANDLE hPackage, DM_PACKAGE_CONFIGURATION *pConfiguration);
typedef RTS_RESULT (CDECL * PFDMPACKAGESETCONFIGURATION) (RTS_HANDLE hPackage, DM_PACKAGE_CONFIGURATION *pConfiguration);
#if defined(CMPDEVICEMANAGEMENT_NOTIMPLEMENTED) || defined(DMPACKAGESETCONFIGURATION_NOTIMPLEMENTED)
	#define USE_DMPackageSetConfiguration
	#define EXT_DMPackageSetConfiguration
	#define GET_DMPackageSetConfiguration(fl)  ERR_NOTIMPLEMENTED
	#define CAL_DMPackageSetConfiguration(p0,p1)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_DMPackageSetConfiguration  FALSE
	#define EXP_DMPackageSetConfiguration  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_DMPackageSetConfiguration
	#define EXT_DMPackageSetConfiguration
	#define GET_DMPackageSetConfiguration(fl)  CAL_CMGETAPI( "DMPackageSetConfiguration" ) 
	#define CAL_DMPackageSetConfiguration  DMPackageSetConfiguration
	#define CHK_DMPackageSetConfiguration  TRUE
	#define EXP_DMPackageSetConfiguration  CAL_CMEXPAPI( "DMPackageSetConfiguration" ) 
#elif defined(MIXED_LINK) && !defined(CMPDEVICEMANAGEMENT_EXTERNAL)
	#define USE_DMPackageSetConfiguration
	#define EXT_DMPackageSetConfiguration
	#define GET_DMPackageSetConfiguration(fl)  CAL_CMGETAPI( "DMPackageSetConfiguration" ) 
	#define CAL_DMPackageSetConfiguration  DMPackageSetConfiguration
	#define CHK_DMPackageSetConfiguration  TRUE
	#define EXP_DMPackageSetConfiguration  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"DMPackageSetConfiguration", (RTS_UINTPTR)DMPackageSetConfiguration, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpDeviceManagementDMPackageSetConfiguration
	#define EXT_CmpDeviceManagementDMPackageSetConfiguration
	#define GET_CmpDeviceManagementDMPackageSetConfiguration  ERR_OK
	#define CAL_CmpDeviceManagementDMPackageSetConfiguration pICmpDeviceManagement->IDMPackageSetConfiguration
	#define CHK_CmpDeviceManagementDMPackageSetConfiguration (pICmpDeviceManagement != NULL)
	#define EXP_CmpDeviceManagementDMPackageSetConfiguration  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_DMPackageSetConfiguration
	#define EXT_DMPackageSetConfiguration
	#define GET_DMPackageSetConfiguration(fl)  CAL_CMGETAPI( "DMPackageSetConfiguration" ) 
	#define CAL_DMPackageSetConfiguration pICmpDeviceManagement->IDMPackageSetConfiguration
	#define CHK_DMPackageSetConfiguration (pICmpDeviceManagement != NULL)
	#define EXP_DMPackageSetConfiguration  CAL_CMEXPAPI( "DMPackageSetConfiguration" ) 
#else /* DYNAMIC_LINK */
	#define USE_DMPackageSetConfiguration  PFDMPACKAGESETCONFIGURATION pfDMPackageSetConfiguration;
	#define EXT_DMPackageSetConfiguration  extern PFDMPACKAGESETCONFIGURATION pfDMPackageSetConfiguration;
	#define GET_DMPackageSetConfiguration(fl)  s_pfCMGetAPI2( "DMPackageSetConfiguration", (RTS_VOID_FCTPTR *)&pfDMPackageSetConfiguration, (fl), 0, 0)
	#define CAL_DMPackageSetConfiguration  pfDMPackageSetConfiguration
	#define CHK_DMPackageSetConfiguration  (pfDMPackageSetConfiguration != NULL)
	#define EXP_DMPackageSetConfiguration  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"DMPackageSetConfiguration", (RTS_UINTPTR)DMPackageSetConfiguration, 0, 0) 
#endif




/**
 * <description>
 * </description>
 * <result></result>
 */
RTS_RESULT CDECL DMPackageAddFile(RTS_HANDLE hPackage, RTS_UTF8STRING *pFilePath, RTS_UTF8STRING *pPackageFilePath);
typedef RTS_RESULT (CDECL * PFDMPACKAGEADDFILE) (RTS_HANDLE hPackage, RTS_UTF8STRING *pFilePath, RTS_UTF8STRING *pPackageFilePath);
#if defined(CMPDEVICEMANAGEMENT_NOTIMPLEMENTED) || defined(DMPACKAGEADDFILE_NOTIMPLEMENTED)
	#define USE_DMPackageAddFile
	#define EXT_DMPackageAddFile
	#define GET_DMPackageAddFile(fl)  ERR_NOTIMPLEMENTED
	#define CAL_DMPackageAddFile(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_DMPackageAddFile  FALSE
	#define EXP_DMPackageAddFile  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_DMPackageAddFile
	#define EXT_DMPackageAddFile
	#define GET_DMPackageAddFile(fl)  CAL_CMGETAPI( "DMPackageAddFile" ) 
	#define CAL_DMPackageAddFile  DMPackageAddFile
	#define CHK_DMPackageAddFile  TRUE
	#define EXP_DMPackageAddFile  CAL_CMEXPAPI( "DMPackageAddFile" ) 
#elif defined(MIXED_LINK) && !defined(CMPDEVICEMANAGEMENT_EXTERNAL)
	#define USE_DMPackageAddFile
	#define EXT_DMPackageAddFile
	#define GET_DMPackageAddFile(fl)  CAL_CMGETAPI( "DMPackageAddFile" ) 
	#define CAL_DMPackageAddFile  DMPackageAddFile
	#define CHK_DMPackageAddFile  TRUE
	#define EXP_DMPackageAddFile  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"DMPackageAddFile", (RTS_UINTPTR)DMPackageAddFile, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpDeviceManagementDMPackageAddFile
	#define EXT_CmpDeviceManagementDMPackageAddFile
	#define GET_CmpDeviceManagementDMPackageAddFile  ERR_OK
	#define CAL_CmpDeviceManagementDMPackageAddFile pICmpDeviceManagement->IDMPackageAddFile
	#define CHK_CmpDeviceManagementDMPackageAddFile (pICmpDeviceManagement != NULL)
	#define EXP_CmpDeviceManagementDMPackageAddFile  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_DMPackageAddFile
	#define EXT_DMPackageAddFile
	#define GET_DMPackageAddFile(fl)  CAL_CMGETAPI( "DMPackageAddFile" ) 
	#define CAL_DMPackageAddFile pICmpDeviceManagement->IDMPackageAddFile
	#define CHK_DMPackageAddFile (pICmpDeviceManagement != NULL)
	#define EXP_DMPackageAddFile  CAL_CMEXPAPI( "DMPackageAddFile" ) 
#else /* DYNAMIC_LINK */
	#define USE_DMPackageAddFile  PFDMPACKAGEADDFILE pfDMPackageAddFile;
	#define EXT_DMPackageAddFile  extern PFDMPACKAGEADDFILE pfDMPackageAddFile;
	#define GET_DMPackageAddFile(fl)  s_pfCMGetAPI2( "DMPackageAddFile", (RTS_VOID_FCTPTR *)&pfDMPackageAddFile, (fl), 0, 0)
	#define CAL_DMPackageAddFile  pfDMPackageAddFile
	#define CHK_DMPackageAddFile  (pfDMPackageAddFile != NULL)
	#define EXP_DMPackageAddFile  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"DMPackageAddFile", (RTS_UINTPTR)DMPackageAddFile, 0, 0) 
#endif




/**
 * <description>
 * </description>
 * <result></result>
 */
RTS_HANDLE CDECL DMPackageGetFirst(RTS_HANDLE hContainer, RTS_RESULT *pResult);
typedef RTS_HANDLE (CDECL * PFDMPACKAGEGETFIRST) (RTS_HANDLE hContainer, RTS_RESULT *pResult);
#if defined(CMPDEVICEMANAGEMENT_NOTIMPLEMENTED) || defined(DMPACKAGEGETFIRST_NOTIMPLEMENTED)
	#define USE_DMPackageGetFirst
	#define EXT_DMPackageGetFirst
	#define GET_DMPackageGetFirst(fl)  ERR_NOTIMPLEMENTED
	#define CAL_DMPackageGetFirst(p0,p1)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_DMPackageGetFirst  FALSE
	#define EXP_DMPackageGetFirst  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_DMPackageGetFirst
	#define EXT_DMPackageGetFirst
	#define GET_DMPackageGetFirst(fl)  CAL_CMGETAPI( "DMPackageGetFirst" ) 
	#define CAL_DMPackageGetFirst  DMPackageGetFirst
	#define CHK_DMPackageGetFirst  TRUE
	#define EXP_DMPackageGetFirst  CAL_CMEXPAPI( "DMPackageGetFirst" ) 
#elif defined(MIXED_LINK) && !defined(CMPDEVICEMANAGEMENT_EXTERNAL)
	#define USE_DMPackageGetFirst
	#define EXT_DMPackageGetFirst
	#define GET_DMPackageGetFirst(fl)  CAL_CMGETAPI( "DMPackageGetFirst" ) 
	#define CAL_DMPackageGetFirst  DMPackageGetFirst
	#define CHK_DMPackageGetFirst  TRUE
	#define EXP_DMPackageGetFirst  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"DMPackageGetFirst", (RTS_UINTPTR)DMPackageGetFirst, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpDeviceManagementDMPackageGetFirst
	#define EXT_CmpDeviceManagementDMPackageGetFirst
	#define GET_CmpDeviceManagementDMPackageGetFirst  ERR_OK
	#define CAL_CmpDeviceManagementDMPackageGetFirst pICmpDeviceManagement->IDMPackageGetFirst
	#define CHK_CmpDeviceManagementDMPackageGetFirst (pICmpDeviceManagement != NULL)
	#define EXP_CmpDeviceManagementDMPackageGetFirst  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_DMPackageGetFirst
	#define EXT_DMPackageGetFirst
	#define GET_DMPackageGetFirst(fl)  CAL_CMGETAPI( "DMPackageGetFirst" ) 
	#define CAL_DMPackageGetFirst pICmpDeviceManagement->IDMPackageGetFirst
	#define CHK_DMPackageGetFirst (pICmpDeviceManagement != NULL)
	#define EXP_DMPackageGetFirst  CAL_CMEXPAPI( "DMPackageGetFirst" ) 
#else /* DYNAMIC_LINK */
	#define USE_DMPackageGetFirst  PFDMPACKAGEGETFIRST pfDMPackageGetFirst;
	#define EXT_DMPackageGetFirst  extern PFDMPACKAGEGETFIRST pfDMPackageGetFirst;
	#define GET_DMPackageGetFirst(fl)  s_pfCMGetAPI2( "DMPackageGetFirst", (RTS_VOID_FCTPTR *)&pfDMPackageGetFirst, (fl), 0, 0)
	#define CAL_DMPackageGetFirst  pfDMPackageGetFirst
	#define CHK_DMPackageGetFirst  (pfDMPackageGetFirst != NULL)
	#define EXP_DMPackageGetFirst  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"DMPackageGetFirst", (RTS_UINTPTR)DMPackageGetFirst, 0, 0) 
#endif




/**
 * <description>
 * </description>
 * <result></result>
 */
RTS_HANDLE CDECL DMPackageGetNext(RTS_HANDLE hContainer, RTS_HANDLE hPackage, RTS_RESULT *pResult);
typedef RTS_HANDLE (CDECL * PFDMPACKAGEGETNEXT) (RTS_HANDLE hContainer, RTS_HANDLE hPackage, RTS_RESULT *pResult);
#if defined(CMPDEVICEMANAGEMENT_NOTIMPLEMENTED) || defined(DMPACKAGEGETNEXT_NOTIMPLEMENTED)
	#define USE_DMPackageGetNext
	#define EXT_DMPackageGetNext
	#define GET_DMPackageGetNext(fl)  ERR_NOTIMPLEMENTED
	#define CAL_DMPackageGetNext(p0,p1,p2)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_DMPackageGetNext  FALSE
	#define EXP_DMPackageGetNext  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_DMPackageGetNext
	#define EXT_DMPackageGetNext
	#define GET_DMPackageGetNext(fl)  CAL_CMGETAPI( "DMPackageGetNext" ) 
	#define CAL_DMPackageGetNext  DMPackageGetNext
	#define CHK_DMPackageGetNext  TRUE
	#define EXP_DMPackageGetNext  CAL_CMEXPAPI( "DMPackageGetNext" ) 
#elif defined(MIXED_LINK) && !defined(CMPDEVICEMANAGEMENT_EXTERNAL)
	#define USE_DMPackageGetNext
	#define EXT_DMPackageGetNext
	#define GET_DMPackageGetNext(fl)  CAL_CMGETAPI( "DMPackageGetNext" ) 
	#define CAL_DMPackageGetNext  DMPackageGetNext
	#define CHK_DMPackageGetNext  TRUE
	#define EXP_DMPackageGetNext  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"DMPackageGetNext", (RTS_UINTPTR)DMPackageGetNext, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpDeviceManagementDMPackageGetNext
	#define EXT_CmpDeviceManagementDMPackageGetNext
	#define GET_CmpDeviceManagementDMPackageGetNext  ERR_OK
	#define CAL_CmpDeviceManagementDMPackageGetNext pICmpDeviceManagement->IDMPackageGetNext
	#define CHK_CmpDeviceManagementDMPackageGetNext (pICmpDeviceManagement != NULL)
	#define EXP_CmpDeviceManagementDMPackageGetNext  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_DMPackageGetNext
	#define EXT_DMPackageGetNext
	#define GET_DMPackageGetNext(fl)  CAL_CMGETAPI( "DMPackageGetNext" ) 
	#define CAL_DMPackageGetNext pICmpDeviceManagement->IDMPackageGetNext
	#define CHK_DMPackageGetNext (pICmpDeviceManagement != NULL)
	#define EXP_DMPackageGetNext  CAL_CMEXPAPI( "DMPackageGetNext" ) 
#else /* DYNAMIC_LINK */
	#define USE_DMPackageGetNext  PFDMPACKAGEGETNEXT pfDMPackageGetNext;
	#define EXT_DMPackageGetNext  extern PFDMPACKAGEGETNEXT pfDMPackageGetNext;
	#define GET_DMPackageGetNext(fl)  s_pfCMGetAPI2( "DMPackageGetNext", (RTS_VOID_FCTPTR *)&pfDMPackageGetNext, (fl), 0, 0)
	#define CAL_DMPackageGetNext  pfDMPackageGetNext
	#define CHK_DMPackageGetNext  (pfDMPackageGetNext != NULL)
	#define EXP_DMPackageGetNext  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"DMPackageGetNext", (RTS_UINTPTR)DMPackageGetNext, 0, 0) 
#endif




#ifdef __cplusplus
}
#endif



typedef struct
{
	IBase_C *pBase;
	PFDMCONTAINERCREATE IDMContainerCreate;
 	PFDMCONTAINERCLOSE IDMContainerClose;
 	PFDMCONTAINERGETPATH IDMContainerGetPath;
 	PFDMPACKAGECREATE IDMPackageCreate;
 	PFDMPACKAGECLOSE IDMPackageClose;
 	PFDMPACKAGESETCONFIGURATION IDMPackageSetConfiguration;
 	PFDMPACKAGEADDFILE IDMPackageAddFile;
 	PFDMPACKAGEGETFIRST IDMPackageGetFirst;
 	PFDMPACKAGEGETNEXT IDMPackageGetNext;
 } ICmpDeviceManagement_C;

#ifdef CPLUSPLUS
class ICmpDeviceManagement : public IBase
{
	public:
		virtual RTS_HANDLE CDECL IDMContainerCreate(RTS_UTF8STRING *pName, RTS_UTF8STRING *pFilePath, RTS_RESULT *pResult) =0;
		virtual RTS_RESULT CDECL IDMContainerClose(RTS_HANDLE hContainer) =0;
		virtual RTS_UTF8STRING * CDECL IDMContainerGetPath(RTS_HANDLE hContainer, RTS_RESULT *pResult) =0;
		virtual RTS_HANDLE CDECL IDMPackageCreate(RTS_HANDLE hContainer, RTS_UTF8STRING *pName, RTS_RESULT *pResult) =0;
		virtual RTS_RESULT CDECL IDMPackageClose(RTS_HANDLE hPackage) =0;
		virtual RTS_RESULT CDECL IDMPackageSetConfiguration(RTS_HANDLE hPackage, DM_PACKAGE_CONFIGURATION *pConfiguration) =0;
		virtual RTS_RESULT CDECL IDMPackageAddFile(RTS_HANDLE hPackage, RTS_UTF8STRING *pFilePath, RTS_UTF8STRING *pPackageFilePath) =0;
		virtual RTS_HANDLE CDECL IDMPackageGetFirst(RTS_HANDLE hContainer, RTS_RESULT *pResult) =0;
		virtual RTS_HANDLE CDECL IDMPackageGetNext(RTS_HANDLE hContainer, RTS_HANDLE hPackage, RTS_RESULT *pResult) =0;
};
	#ifndef ITF_CmpDeviceManagement
		#define ITF_CmpDeviceManagement static ICmpDeviceManagement *pICmpDeviceManagement = NULL;
	#endif
	#define EXTITF_CmpDeviceManagement
#else	/*CPLUSPLUS*/
	typedef ICmpDeviceManagement_C		ICmpDeviceManagement;
	#ifndef ITF_CmpDeviceManagement
		#define ITF_CmpDeviceManagement
	#endif
	#define EXTITF_CmpDeviceManagement
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_CMPDEVICEMANAGEMENTITF_H_*/
