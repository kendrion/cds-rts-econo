 /**
 * <copyright>
 * Copyright (c) 2019-2019 CODESYS Development GmbH. All rights reserved.
 * </copyright>
 */

#ifndef _SYSTARGET_H_
#define _SYSTARGET_H_

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * <description>Platform specific implementation of the generic core function SysTargetGetSerialNumber().</description>
 */
RTS_RESULT CDECL SysTargetGetSerialNumber_(char **ppszSerialNumber, RTS_I32 *pnMaxLen);

#ifdef __cplusplus
}
#endif

#endif	/*_SYSTARGET_H_*/

