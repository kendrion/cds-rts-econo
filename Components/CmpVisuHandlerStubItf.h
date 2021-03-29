 /**
 * <interfacename>CmpVisuHandlerStub</interfacename>
 * <description> 
 *	Interface for the visualization handler stub.
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */


	
	
#ifndef _CMPVISUHANDLERSTUBITF_H_
#define _CMPVISUHANDLERSTUBITF_H_

#include "CmpStd.h"

 

 




/**
 * <category>Settings</category>
 * <description>The base name for the IPC channel.
 *	IMPORTANT: The according target-visualization stub must have configured the same base name ! </description>
 */
#define CMPVISUHANDLERSTUB_KEY_TARGETVISUPROCESS_IPCBASENAME				"IpcBasename"
#define CMPVISUHANDLERSTUB_KEY_TARGETVISUPROCESS_IPCBASENAME_DEFAULT		"Ipc__Targetvisu__"

/**
 * <category>Settings</category>
 * <description>Setting that decides about the timeout that is used for single IPC calls </description>
 */
#define CMPVISUHANDLERSTUB_KEY_IPCTIMEOUT				"IpcTimeoutMs"
#define CMPVISUHANDLERSTUB_KEY_IPCTIMEOUT_DEFAULT		5000

/**
 * <category>Settings</category>
 * <description>The base name of the shared memory. Will be followed by the external id of the specific client.
 * IMPORTANT: The according visualization must have configured the same base name ! </description>
 */
#define CMPVISUHANDLERSTUB_KEY_TARGETVISUPROCESS_SHMBASENAME				"SharedMemoryBasename"
#define CMPVISUHANDLERSTUB_KEY_TARGETVISUPROCESS_SHMBASENAME_DEFAULT		"SHM_EXTERN_TARGETVISU_"




typedef struct
{
	IBase_C *pBase;
} ICmpVisuHandlerStub_C;

#ifdef CPLUSPLUS
class ICmpVisuHandlerStub : public IBase
{
	public:
};
	#ifndef ITF_CmpVisuHandlerStub
		#define ITF_CmpVisuHandlerStub static ICmpVisuHandlerStub *pICmpVisuHandlerStub = NULL;
	#endif
	#define EXTITF_CmpVisuHandlerStub
#else	/*CPLUSPLUS*/
	typedef ICmpVisuHandlerStub_C		ICmpVisuHandlerStub;
	#ifndef ITF_CmpVisuHandlerStub
		#define ITF_CmpVisuHandlerStub
	#endif
	#define EXTITF_CmpVisuHandlerStub
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_CMPVISUHANDLERSTUBITF_H_*/
