/**
 * <interfacename>CmpArchive</interfacename>
 * <description> 
 *  === PROTOTYPE: DONT USE YET! ===
 *  Interface to handle different archive formats and compress algorithms.
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`CmpArchive')

#include <sys/types.h>
#include <sys/stat.h>

/**
 * <category>Static defines</category>
 * <description>Max buffer length to handle archive</description>
 */
#define CMPARCHIVE_MAX_BUFFER_LEN       10240

/**
 * <category>Archive access modes</category>
 * <description></description>
 */
#define RTS_ARCH_ACCESSMODE_READ        0x00000001
#define RTS_ARCH_ACCESSMODE_WRITE       0x00000002

/**
 * <category>Archive formats</category>
 * <description>Supported archive formats</description>
 */
#define RTS_ARCH_FORMAT_ALL         0x00000001
#define RTS_ARCH_FORMAT_TAR         0x00000002

/**
 * <category>Archive compress algorithms</category>
 * <description>Supported archive compress algorithms</description>
 */
#define RTS_ARCH_COMPRESS_NONE      0x00000000
#define RTS_ARCH_COMPRESS_ALL       0x00000001
#define RTS_ARCH_COMPRESS_GZIP      0x00000002


/**
 * <category>Archive entry</category>
 * <description></description>
 * <element name="pName" type="IN">Name of the archive entry/file</element>
 * <element name="st" type="IN">File stat which is filled by standard C-library stat()</element> 
 */
typedef struct
{
    RTS_UTF8STRING *pName;
    struct stat st;
} RTS_ARCH_ENTRY;

/**
 * <category>Archive entry</category>
 * <description></description>
 * <element name="pName" type="IN">Name of the archive entry/file</element>
 * <element name="st" type="IN">File stat which is filled by standard C-library stat()</element> 
 */
typedef struct
{
    RTS_UTF8STRING *pName;
    struct stat st;
    RTS_UI8 *pData;
    RTS_SIZE len;
    void *pUserParameter;
    RTS_BOOL bEndOfRead;
} RTS_ARCH_READ_ENTRY;

/**
 * <description> Callback function </description>
 * <param name="pEntry" type="IN">Pointer to archive read entry.
 *                                NOTE: Is called several times for each entry segment!</param>
 * <result></result>
 */
typedef void (CDECL *PFARCHIVE_CALLBACK_READ)(RTS_ARCH_READ_ENTRY *pEntry);


#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description>
 * </description>
 * <result></result>
 */
DEF_ITF_API(`RTS_HANDLE', `CDECL', `ArchOpen', `(RTS_UTF8STRING *pName, RTS_UTF8STRING *pPath, RTS_UI32 accessMode, RTS_UI32 format, RTS_UI32 compress, RTS_RESULT *pResult)')

/**
 * <description>
 * </description>
 * <result></result>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `ArchWrite', `(RTS_HANDLE hArch, RTS_ARCH_ENTRY *pEntry, RTS_UI8 *pData, RTS_SIZE len)')

/**
 * <description>
 * </description>
 * <result></result>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `ArchWriteFile', `(RTS_HANDLE hArch, RTS_ARCH_ENTRY *pEntry, RTS_HANDLE hFile)')

/**
 * <description>
 * </description>
 * <result></result>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `ArchRead', `(RTS_HANDLE hArch, PFARCHIVE_CALLBACK_READ pfReadCallback, void *pUserParameter)')

/**
 * <description>
 * </description>
 * <result></result>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `ArchClose', `(RTS_HANDLE hArch)')

/**
 * <description>
 * </description>
 * <result></result>
 */
DEF_ITF_API(`RTS_UTF8STRING *', `CDECL', `ArchGetPath', `(RTS_HANDLE hArch, RTS_RESULT *pResult)')

#ifdef __cplusplus
}
#endif
