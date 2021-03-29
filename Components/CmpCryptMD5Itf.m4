/**
 * <interfacename>CmpCryptMD5</interfacename>
 * <description>
 *	Interface for the MD5 hash feature.
 *
 *	ATTENTION:
 *	Don't use the MD5 hash in security relevant applications. MD5 is an unsafe algorithm because of existing collision tables!!
 * </description>
 *
 * <copyright>
 *  Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`CmpCryptMD5')

#include "CmpItf.h"

/**
 * <category>Static defines</category>
 * <description>MD5 key length</description>
 */
#define	CRYPTMD5_KEY_LENGTH					33

#ifdef __cplusplus
extern "C" {
#endif

DEF_ITF_API(`RTS_RESULT',`CDECL',`CryptMD5Calculate',`(const unsigned char* pchInput, int nInputLength, char* pcResult, int iResultLen)')

#ifdef __cplusplus
}
#endif
