/**
 * <interfacename>SysServices</interfacename>
 * <description> 
 *	Interface to manage runtime services.
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`SysServices')

/**
 * <category>Service states</category>
 * <description>Service status definitions</description>
 */
#define SYSSERVICE_STATUS_UNKNOWN	0
#define SYSSERVICE_STATUS_STOP		1
#define SYSSERVICE_STATUS_RUN		2

#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description>Function to start the specified service</description>
 * <param name="puServiceName" type="IN">Name of the service</param>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `SysServiceStart', `(RTS_UTF8STRING *puServiceName)')

/**
 * <description>Function to stop the specified service</description>
 * <param name="puServiceName" type="IN">Name of the service</param>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `SysServiceStop', `(RTS_UTF8STRING *puServiceName)')

/**
 * <description>Function to get the current status of the specified service</description>
 * <param name="puServiceName" type="IN">Name of the service</param>
 * <param name="pStatus" type="OUT">Pointer to get the service status. See "Service states" for details.</param>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `SysServiceGetStatus', `(RTS_UTF8STRING *puServiceName, RTS_UI32 *pStatus)')

#ifdef __cplusplus
}
#endif
