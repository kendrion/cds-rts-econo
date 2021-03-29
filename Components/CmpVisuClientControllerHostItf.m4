/**
 * <interfacename>CmpVisuClientControllerHost</interfacename>
 * <description> 
 *	Interface for the visualization client controller host.
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`CmpVisuClientControllerHost')


/**
 * <category>Settings</category>
 * <description> The IPC base name of the visualization client controller
 * IMPORTANT: The according visualization client controller must have configured the same base name ! </description>
 */
#define CMPVISUCLIENTCONTROLLERSTUB_KEY_IPCBASENAME				"IpcBasename"
#define CMPVISUCLIENTCONTROLLERSTUB_KEY_IPCBASENAME_DEFAULT		"Ipc__VisuClientController__"

/**
 * <description> Function to register the visualization client controller host. </description>
 * <param name="pszApplication" type="IN">The target visualization application</param>
 * <param name="pHandleRet" type="OUT">The created handle.</param>
 * <result>error code</result>
 */	
DEF_API(`RTS_RESULT', `CDECL', `VisuClientControllerHostCreateInstance', `(char* pszApplication, RTS_HANDLE* pHandleRet)')

/**
 * <description> Function to release a formerly registered visualization client controller host. </description>
 * <param name="hInstance" type="IN">The instance that should be released.</param>
 * <result>error code</result>
 */	
DEF_API(`RTS_RESULT', `CDECL', `VisuClientControllerHostDestroyInstance', `(RTS_HANDLE hInstance)')

