/**
 * <interfacename>CmpMgrBasicChecks</interfacename>
 * <description>
 *	<p>Interface to check the runtime environment. Here things like data type size and
 *	byte order are checked, before the runtime system was started.</p>
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`CmpMgrBasicChecks')

#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description> 
 *	Checks to environment and the compiled runtime system for consistency.
 *	- Checks the real size of all data types
 *	- Checks, if swapping must be done and if swapping is done correctly
 * </description>
 * <result>TRUE if successful, FALSE if error occurred</result>
 */
DEF_STATICITF_API(`int', `CDECL', `CMBasicChecks', `(void)')

#ifdef __cplusplus
}
#endif
