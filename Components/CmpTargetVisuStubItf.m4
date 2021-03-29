/**
 * <interfacename>CmpTargetVisuStub</interfacename>
 * <description> 
 *	Interface for the target visualization stub.
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`CmpTargetVisuStub')

/**
 * <category>Settings</category>
 * <description>Setting that decides about the path of the program that will start the process containing the target-visualization.
 * </description>
 */
#define CMPTARGETVISUSTUB_KEY_TARGETVISUPROCESS_PROGRAM				"Program"
#define CMPTARGETVISUSTUB_KEY_TARGETVISUPROCESS_PROGRAM_DEFAULT		"codesyscontrolservice.exe"

/**
 * <category>Settings</category>
 * <description>Setting that decides about the path of the command-line used as parameter to start the program
 *	containing the target-visualization.
 * </description>
 */
#define CMPTARGETVISUSTUB_KEY_TARGETVISUPROCESS_CMDLINE				"CommandLine"
#define CMPTARGETVISUSTUB_KEY_TARGETVISUPROCESS_CMDLINE_DEFAULT		"-r targetvisuextern.cfg"

/**
 * <category>Settings</category>
 * <description>Setting that decides about the rate at which the target-visualization checks for updates of the
 * content of the display. This value in ms is no real-time value, so there can be quite some jitter on this value.
 * IMPORTANT: The according visualization handler stub must have configured the same base name ! </description>
 */
#define CMPTARGETVISUSTUB_KEY_TARGETVISUPROCESS_IPCBASENAME				"IpcBasename"
#define CMPTARGETVISUSTUB_KEY_TARGETVISUPROCESS_IPCBASENAME_DEFAULT		"Ipc__Targetvisu__"

/**
 * <category>Settings</category>
 * <description>Setting that decides about the timeout that is used for single IPC calls </description>
 */
#define CMPTARGETVISUSTUB_KEY_IPCTIMEOUT							"IpcTimeoutMs"
#define CMPTARGETVISUSTUB_KEY_IPCTIMEOUT_DEFAULT					500

