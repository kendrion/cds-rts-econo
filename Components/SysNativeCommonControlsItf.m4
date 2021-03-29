/**
 * <interfacename>SysNativeCommonControls</interfacename>
 * <description></description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`SysNativeCommonControls')

#include "CmpItf.h"

/**
 * <category>Static defines</category>
 * <description>Number of static SysNativeControlCustom instances</description>
 */
#ifndef NUM_OF_STATIC_CUSTOM_CONTROLS
	#define NUM_OF_STATIC_CUSTOM_CONTROLS	4
#endif

/**
 * <category>Settings</category>
 * <description>Setting defining whether on certain platforms (e.g. Linux/QT) plug-ins displaying
 * special web content are enabled (value 1) or not (value 0). For security reasons plug-ins are
 * disabled by default.
 * </description>
 */
#define SYSNATIVECOMMONCONTROLS_KEY_PLUGINS_ENABLED						"PluginsEnabled"
#ifndef SYSNATIVECOMMONCONTROLS_KEY_PLUGINS_ENABLED_DEFAULT
	#define SYSNATIVECOMMONCONTROLS_KEY_PLUGINS_ENABLED_DEFAULT			0
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif
