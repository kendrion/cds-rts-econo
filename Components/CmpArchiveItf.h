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


	
	
#ifndef _CMPARCHIVEITF_H_
#define _CMPARCHIVEITF_H_

#include "CmpStd.h"

 

 




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
RTS_HANDLE CDECL ArchOpen(RTS_UTF8STRING *pName, RTS_UTF8STRING *pPath, RTS_UI32 accessMode, RTS_UI32 format, RTS_UI32 compress, RTS_RESULT *pResult);
typedef RTS_HANDLE (CDECL * PFARCHOPEN) (RTS_UTF8STRING *pName, RTS_UTF8STRING *pPath, RTS_UI32 accessMode, RTS_UI32 format, RTS_UI32 compress, RTS_RESULT *pResult);
#if defined(CMPARCHIVE_NOTIMPLEMENTED) || defined(ARCHOPEN_NOTIMPLEMENTED)
	#define USE_ArchOpen
	#define EXT_ArchOpen
	#define GET_ArchOpen(fl)  ERR_NOTIMPLEMENTED
	#define CAL_ArchOpen(p0,p1,p2,p3,p4,p5)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_ArchOpen  FALSE
	#define EXP_ArchOpen  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_ArchOpen
	#define EXT_ArchOpen
	#define GET_ArchOpen(fl)  CAL_CMGETAPI( "ArchOpen" ) 
	#define CAL_ArchOpen  ArchOpen
	#define CHK_ArchOpen  TRUE
	#define EXP_ArchOpen  CAL_CMEXPAPI( "ArchOpen" ) 
#elif defined(MIXED_LINK) && !defined(CMPARCHIVE_EXTERNAL)
	#define USE_ArchOpen
	#define EXT_ArchOpen
	#define GET_ArchOpen(fl)  CAL_CMGETAPI( "ArchOpen" ) 
	#define CAL_ArchOpen  ArchOpen
	#define CHK_ArchOpen  TRUE
	#define EXP_ArchOpen  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"ArchOpen", (RTS_UINTPTR)ArchOpen, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpArchiveArchOpen
	#define EXT_CmpArchiveArchOpen
	#define GET_CmpArchiveArchOpen  ERR_OK
	#define CAL_CmpArchiveArchOpen pICmpArchive->IArchOpen
	#define CHK_CmpArchiveArchOpen (pICmpArchive != NULL)
	#define EXP_CmpArchiveArchOpen  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_ArchOpen
	#define EXT_ArchOpen
	#define GET_ArchOpen(fl)  CAL_CMGETAPI( "ArchOpen" ) 
	#define CAL_ArchOpen pICmpArchive->IArchOpen
	#define CHK_ArchOpen (pICmpArchive != NULL)
	#define EXP_ArchOpen  CAL_CMEXPAPI( "ArchOpen" ) 
#else /* DYNAMIC_LINK */
	#define USE_ArchOpen  PFARCHOPEN pfArchOpen;
	#define EXT_ArchOpen  extern PFARCHOPEN pfArchOpen;
	#define GET_ArchOpen(fl)  s_pfCMGetAPI2( "ArchOpen", (RTS_VOID_FCTPTR *)&pfArchOpen, (fl), 0, 0)
	#define CAL_ArchOpen  pfArchOpen
	#define CHK_ArchOpen  (pfArchOpen != NULL)
	#define EXP_ArchOpen  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"ArchOpen", (RTS_UINTPTR)ArchOpen, 0, 0) 
#endif




/**
 * <description>
 * </description>
 * <result></result>
 */
RTS_RESULT CDECL ArchWrite(RTS_HANDLE hArch, RTS_ARCH_ENTRY *pEntry, RTS_UI8 *pData, RTS_SIZE len);
typedef RTS_RESULT (CDECL * PFARCHWRITE) (RTS_HANDLE hArch, RTS_ARCH_ENTRY *pEntry, RTS_UI8 *pData, RTS_SIZE len);
#if defined(CMPARCHIVE_NOTIMPLEMENTED) || defined(ARCHWRITE_NOTIMPLEMENTED)
	#define USE_ArchWrite
	#define EXT_ArchWrite
	#define GET_ArchWrite(fl)  ERR_NOTIMPLEMENTED
	#define CAL_ArchWrite(p0,p1,p2,p3)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_ArchWrite  FALSE
	#define EXP_ArchWrite  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_ArchWrite
	#define EXT_ArchWrite
	#define GET_ArchWrite(fl)  CAL_CMGETAPI( "ArchWrite" ) 
	#define CAL_ArchWrite  ArchWrite
	#define CHK_ArchWrite  TRUE
	#define EXP_ArchWrite  CAL_CMEXPAPI( "ArchWrite" ) 
#elif defined(MIXED_LINK) && !defined(CMPARCHIVE_EXTERNAL)
	#define USE_ArchWrite
	#define EXT_ArchWrite
	#define GET_ArchWrite(fl)  CAL_CMGETAPI( "ArchWrite" ) 
	#define CAL_ArchWrite  ArchWrite
	#define CHK_ArchWrite  TRUE
	#define EXP_ArchWrite  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"ArchWrite", (RTS_UINTPTR)ArchWrite, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpArchiveArchWrite
	#define EXT_CmpArchiveArchWrite
	#define GET_CmpArchiveArchWrite  ERR_OK
	#define CAL_CmpArchiveArchWrite pICmpArchive->IArchWrite
	#define CHK_CmpArchiveArchWrite (pICmpArchive != NULL)
	#define EXP_CmpArchiveArchWrite  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_ArchWrite
	#define EXT_ArchWrite
	#define GET_ArchWrite(fl)  CAL_CMGETAPI( "ArchWrite" ) 
	#define CAL_ArchWrite pICmpArchive->IArchWrite
	#define CHK_ArchWrite (pICmpArchive != NULL)
	#define EXP_ArchWrite  CAL_CMEXPAPI( "ArchWrite" ) 
#else /* DYNAMIC_LINK */
	#define USE_ArchWrite  PFARCHWRITE pfArchWrite;
	#define EXT_ArchWrite  extern PFARCHWRITE pfArchWrite;
	#define GET_ArchWrite(fl)  s_pfCMGetAPI2( "ArchWrite", (RTS_VOID_FCTPTR *)&pfArchWrite, (fl), 0, 0)
	#define CAL_ArchWrite  pfArchWrite
	#define CHK_ArchWrite  (pfArchWrite != NULL)
	#define EXP_ArchWrite  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"ArchWrite", (RTS_UINTPTR)ArchWrite, 0, 0) 
#endif




/**
 * <description>
 * </description>
 * <result></result>
 */
RTS_RESULT CDECL ArchWriteFile(RTS_HANDLE hArch, RTS_ARCH_ENTRY *pEntry, RTS_HANDLE hFile);
typedef RTS_RESULT (CDECL * PFARCHWRITEFILE) (RTS_HANDLE hArch, RTS_ARCH_ENTRY *pEntry, RTS_HANDLE hFile);
#if defined(CMPARCHIVE_NOTIMPLEMENTED) || defined(ARCHWRITEFILE_NOTIMPLEMENTED)
	#define USE_ArchWriteFile
	#define EXT_ArchWriteFile
	#define GET_ArchWriteFile(fl)  ERR_NOTIMPLEMENTED
	#define CAL_ArchWriteFile(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_ArchWriteFile  FALSE
	#define EXP_ArchWriteFile  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_ArchWriteFile
	#define EXT_ArchWriteFile
	#define GET_ArchWriteFile(fl)  CAL_CMGETAPI( "ArchWriteFile" ) 
	#define CAL_ArchWriteFile  ArchWriteFile
	#define CHK_ArchWriteFile  TRUE
	#define EXP_ArchWriteFile  CAL_CMEXPAPI( "ArchWriteFile" ) 
#elif defined(MIXED_LINK) && !defined(CMPARCHIVE_EXTERNAL)
	#define USE_ArchWriteFile
	#define EXT_ArchWriteFile
	#define GET_ArchWriteFile(fl)  CAL_CMGETAPI( "ArchWriteFile" ) 
	#define CAL_ArchWriteFile  ArchWriteFile
	#define CHK_ArchWriteFile  TRUE
	#define EXP_ArchWriteFile  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"ArchWriteFile", (RTS_UINTPTR)ArchWriteFile, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpArchiveArchWriteFile
	#define EXT_CmpArchiveArchWriteFile
	#define GET_CmpArchiveArchWriteFile  ERR_OK
	#define CAL_CmpArchiveArchWriteFile pICmpArchive->IArchWriteFile
	#define CHK_CmpArchiveArchWriteFile (pICmpArchive != NULL)
	#define EXP_CmpArchiveArchWriteFile  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_ArchWriteFile
	#define EXT_ArchWriteFile
	#define GET_ArchWriteFile(fl)  CAL_CMGETAPI( "ArchWriteFile" ) 
	#define CAL_ArchWriteFile pICmpArchive->IArchWriteFile
	#define CHK_ArchWriteFile (pICmpArchive != NULL)
	#define EXP_ArchWriteFile  CAL_CMEXPAPI( "ArchWriteFile" ) 
#else /* DYNAMIC_LINK */
	#define USE_ArchWriteFile  PFARCHWRITEFILE pfArchWriteFile;
	#define EXT_ArchWriteFile  extern PFARCHWRITEFILE pfArchWriteFile;
	#define GET_ArchWriteFile(fl)  s_pfCMGetAPI2( "ArchWriteFile", (RTS_VOID_FCTPTR *)&pfArchWriteFile, (fl), 0, 0)
	#define CAL_ArchWriteFile  pfArchWriteFile
	#define CHK_ArchWriteFile  (pfArchWriteFile != NULL)
	#define EXP_ArchWriteFile  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"ArchWriteFile", (RTS_UINTPTR)ArchWriteFile, 0, 0) 
#endif




/**
 * <description>
 * </description>
 * <result></result>
 */
RTS_RESULT CDECL ArchRead(RTS_HANDLE hArch, PFARCHIVE_CALLBACK_READ pfReadCallback, void *pUserParameter);
typedef RTS_RESULT (CDECL * PFARCHREAD) (RTS_HANDLE hArch, PFARCHIVE_CALLBACK_READ pfReadCallback, void *pUserParameter);
#if defined(CMPARCHIVE_NOTIMPLEMENTED) || defined(ARCHREAD_NOTIMPLEMENTED)
	#define USE_ArchRead
	#define EXT_ArchRead
	#define GET_ArchRead(fl)  ERR_NOTIMPLEMENTED
	#define CAL_ArchRead(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_ArchRead  FALSE
	#define EXP_ArchRead  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_ArchRead
	#define EXT_ArchRead
	#define GET_ArchRead(fl)  CAL_CMGETAPI( "ArchRead" ) 
	#define CAL_ArchRead  ArchRead
	#define CHK_ArchRead  TRUE
	#define EXP_ArchRead  CAL_CMEXPAPI( "ArchRead" ) 
#elif defined(MIXED_LINK) && !defined(CMPARCHIVE_EXTERNAL)
	#define USE_ArchRead
	#define EXT_ArchRead
	#define GET_ArchRead(fl)  CAL_CMGETAPI( "ArchRead" ) 
	#define CAL_ArchRead  ArchRead
	#define CHK_ArchRead  TRUE
	#define EXP_ArchRead  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"ArchRead", (RTS_UINTPTR)ArchRead, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpArchiveArchRead
	#define EXT_CmpArchiveArchRead
	#define GET_CmpArchiveArchRead  ERR_OK
	#define CAL_CmpArchiveArchRead pICmpArchive->IArchRead
	#define CHK_CmpArchiveArchRead (pICmpArchive != NULL)
	#define EXP_CmpArchiveArchRead  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_ArchRead
	#define EXT_ArchRead
	#define GET_ArchRead(fl)  CAL_CMGETAPI( "ArchRead" ) 
	#define CAL_ArchRead pICmpArchive->IArchRead
	#define CHK_ArchRead (pICmpArchive != NULL)
	#define EXP_ArchRead  CAL_CMEXPAPI( "ArchRead" ) 
#else /* DYNAMIC_LINK */
	#define USE_ArchRead  PFARCHREAD pfArchRead;
	#define EXT_ArchRead  extern PFARCHREAD pfArchRead;
	#define GET_ArchRead(fl)  s_pfCMGetAPI2( "ArchRead", (RTS_VOID_FCTPTR *)&pfArchRead, (fl), 0, 0)
	#define CAL_ArchRead  pfArchRead
	#define CHK_ArchRead  (pfArchRead != NULL)
	#define EXP_ArchRead  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"ArchRead", (RTS_UINTPTR)ArchRead, 0, 0) 
#endif




/**
 * <description>
 * </description>
 * <result></result>
 */
RTS_RESULT CDECL ArchClose(RTS_HANDLE hArch);
typedef RTS_RESULT (CDECL * PFARCHCLOSE) (RTS_HANDLE hArch);
#if defined(CMPARCHIVE_NOTIMPLEMENTED) || defined(ARCHCLOSE_NOTIMPLEMENTED)
	#define USE_ArchClose
	#define EXT_ArchClose
	#define GET_ArchClose(fl)  ERR_NOTIMPLEMENTED
	#define CAL_ArchClose(p0)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_ArchClose  FALSE
	#define EXP_ArchClose  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_ArchClose
	#define EXT_ArchClose
	#define GET_ArchClose(fl)  CAL_CMGETAPI( "ArchClose" ) 
	#define CAL_ArchClose  ArchClose
	#define CHK_ArchClose  TRUE
	#define EXP_ArchClose  CAL_CMEXPAPI( "ArchClose" ) 
#elif defined(MIXED_LINK) && !defined(CMPARCHIVE_EXTERNAL)
	#define USE_ArchClose
	#define EXT_ArchClose
	#define GET_ArchClose(fl)  CAL_CMGETAPI( "ArchClose" ) 
	#define CAL_ArchClose  ArchClose
	#define CHK_ArchClose  TRUE
	#define EXP_ArchClose  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"ArchClose", (RTS_UINTPTR)ArchClose, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpArchiveArchClose
	#define EXT_CmpArchiveArchClose
	#define GET_CmpArchiveArchClose  ERR_OK
	#define CAL_CmpArchiveArchClose pICmpArchive->IArchClose
	#define CHK_CmpArchiveArchClose (pICmpArchive != NULL)
	#define EXP_CmpArchiveArchClose  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_ArchClose
	#define EXT_ArchClose
	#define GET_ArchClose(fl)  CAL_CMGETAPI( "ArchClose" ) 
	#define CAL_ArchClose pICmpArchive->IArchClose
	#define CHK_ArchClose (pICmpArchive != NULL)
	#define EXP_ArchClose  CAL_CMEXPAPI( "ArchClose" ) 
#else /* DYNAMIC_LINK */
	#define USE_ArchClose  PFARCHCLOSE pfArchClose;
	#define EXT_ArchClose  extern PFARCHCLOSE pfArchClose;
	#define GET_ArchClose(fl)  s_pfCMGetAPI2( "ArchClose", (RTS_VOID_FCTPTR *)&pfArchClose, (fl), 0, 0)
	#define CAL_ArchClose  pfArchClose
	#define CHK_ArchClose  (pfArchClose != NULL)
	#define EXP_ArchClose  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"ArchClose", (RTS_UINTPTR)ArchClose, 0, 0) 
#endif




/**
 * <description>
 * </description>
 * <result></result>
 */
RTS_UTF8STRING * CDECL ArchGetPath(RTS_HANDLE hArch, RTS_RESULT *pResult);
typedef RTS_UTF8STRING * (CDECL * PFARCHGETPATH) (RTS_HANDLE hArch, RTS_RESULT *pResult);
#if defined(CMPARCHIVE_NOTIMPLEMENTED) || defined(ARCHGETPATH_NOTIMPLEMENTED)
	#define USE_ArchGetPath
	#define EXT_ArchGetPath
	#define GET_ArchGetPath(fl)  ERR_NOTIMPLEMENTED
	#define CAL_ArchGetPath(p0,p1)  (RTS_UTF8STRING *)ERR_NOTIMPLEMENTED
	#define CHK_ArchGetPath  FALSE
	#define EXP_ArchGetPath  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_ArchGetPath
	#define EXT_ArchGetPath
	#define GET_ArchGetPath(fl)  CAL_CMGETAPI( "ArchGetPath" ) 
	#define CAL_ArchGetPath  ArchGetPath
	#define CHK_ArchGetPath  TRUE
	#define EXP_ArchGetPath  CAL_CMEXPAPI( "ArchGetPath" ) 
#elif defined(MIXED_LINK) && !defined(CMPARCHIVE_EXTERNAL)
	#define USE_ArchGetPath
	#define EXT_ArchGetPath
	#define GET_ArchGetPath(fl)  CAL_CMGETAPI( "ArchGetPath" ) 
	#define CAL_ArchGetPath  ArchGetPath
	#define CHK_ArchGetPath  TRUE
	#define EXP_ArchGetPath  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"ArchGetPath", (RTS_UINTPTR)ArchGetPath, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpArchiveArchGetPath
	#define EXT_CmpArchiveArchGetPath
	#define GET_CmpArchiveArchGetPath  ERR_OK
	#define CAL_CmpArchiveArchGetPath pICmpArchive->IArchGetPath
	#define CHK_CmpArchiveArchGetPath (pICmpArchive != NULL)
	#define EXP_CmpArchiveArchGetPath  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_ArchGetPath
	#define EXT_ArchGetPath
	#define GET_ArchGetPath(fl)  CAL_CMGETAPI( "ArchGetPath" ) 
	#define CAL_ArchGetPath pICmpArchive->IArchGetPath
	#define CHK_ArchGetPath (pICmpArchive != NULL)
	#define EXP_ArchGetPath  CAL_CMEXPAPI( "ArchGetPath" ) 
#else /* DYNAMIC_LINK */
	#define USE_ArchGetPath  PFARCHGETPATH pfArchGetPath;
	#define EXT_ArchGetPath  extern PFARCHGETPATH pfArchGetPath;
	#define GET_ArchGetPath(fl)  s_pfCMGetAPI2( "ArchGetPath", (RTS_VOID_FCTPTR *)&pfArchGetPath, (fl), 0, 0)
	#define CAL_ArchGetPath  pfArchGetPath
	#define CHK_ArchGetPath  (pfArchGetPath != NULL)
	#define EXP_ArchGetPath  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"ArchGetPath", (RTS_UINTPTR)ArchGetPath, 0, 0) 
#endif




#ifdef __cplusplus
}
#endif



typedef struct
{
	IBase_C *pBase;
	PFARCHOPEN IArchOpen;
 	PFARCHWRITE IArchWrite;
 	PFARCHWRITEFILE IArchWriteFile;
 	PFARCHREAD IArchRead;
 	PFARCHCLOSE IArchClose;
 	PFARCHGETPATH IArchGetPath;
 } ICmpArchive_C;

#ifdef CPLUSPLUS
class ICmpArchive : public IBase
{
	public:
		virtual RTS_HANDLE CDECL IArchOpen(RTS_UTF8STRING *pName, RTS_UTF8STRING *pPath, RTS_UI32 accessMode, RTS_UI32 format, RTS_UI32 compress, RTS_RESULT *pResult) =0;
		virtual RTS_RESULT CDECL IArchWrite(RTS_HANDLE hArch, RTS_ARCH_ENTRY *pEntry, RTS_UI8 *pData, RTS_SIZE len) =0;
		virtual RTS_RESULT CDECL IArchWriteFile(RTS_HANDLE hArch, RTS_ARCH_ENTRY *pEntry, RTS_HANDLE hFile) =0;
		virtual RTS_RESULT CDECL IArchRead(RTS_HANDLE hArch, PFARCHIVE_CALLBACK_READ pfReadCallback, void *pUserParameter) =0;
		virtual RTS_RESULT CDECL IArchClose(RTS_HANDLE hArch) =0;
		virtual RTS_UTF8STRING * CDECL IArchGetPath(RTS_HANDLE hArch, RTS_RESULT *pResult) =0;
};
	#ifndef ITF_CmpArchive
		#define ITF_CmpArchive static ICmpArchive *pICmpArchive = NULL;
	#endif
	#define EXTITF_CmpArchive
#else	/*CPLUSPLUS*/
	typedef ICmpArchive_C		ICmpArchive;
	#ifndef ITF_CmpArchive
		#define ITF_CmpArchive
	#endif
	#define EXTITF_CmpArchive
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_CMPARCHIVEITF_H_*/
