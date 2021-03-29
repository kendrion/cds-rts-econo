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
 
SET_INTERFACE_NAME(`CmpDeviceManagement')

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
DEF_ITF_API(`RTS_HANDLE', `CDECL', `DMContainerCreate', `(RTS_UTF8STRING *pName, RTS_UTF8STRING *pFilePath, RTS_RESULT *pResult)')

/**
 * <description>
 * </description>
 * <result></result>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `DMContainerClose', `(RTS_HANDLE hContainer)')

/**
 * <description>
 * </description>
 * <result></result>
 */
DEF_ITF_API(`RTS_UTF8STRING *', `CDECL', `DMContainerGetPath', `(RTS_HANDLE hContainer, RTS_RESULT *pResult)')

/**
 * <description>
 * </description>
 * <result></result>
 */
DEF_ITF_API(`RTS_HANDLE', `CDECL', `DMPackageCreate', `(RTS_HANDLE hContainer, RTS_UTF8STRING *pName, RTS_RESULT *pResult)')

/**
 * <description>
 * </description>
 * <result></result>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `DMPackageClose', `(RTS_HANDLE hPackage)')

/**
 * <description>
 * </description>
 * <result></result>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `DMPackageSetConfiguration', `(RTS_HANDLE hPackage, DM_PACKAGE_CONFIGURATION *pConfiguration)')

/**
 * <description>
 * </description>
 * <result></result>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `DMPackageAddFile', `(RTS_HANDLE hPackage, RTS_UTF8STRING *pFilePath, RTS_UTF8STRING *pPackageFilePath)')

/**
 * <description>
 * </description>
 * <result></result>
 */
DEF_ITF_API(`RTS_HANDLE', `CDECL', `DMPackageGetFirst', `(RTS_HANDLE hContainer, RTS_RESULT *pResult)')

/**
 * <description>
 * </description>
 * <result></result>
 */
DEF_ITF_API(`RTS_HANDLE', `CDECL', `DMPackageGetNext', `(RTS_HANDLE hContainer, RTS_HANDLE hPackage, RTS_RESULT *pResult)')

#ifdef __cplusplus
}
#endif
