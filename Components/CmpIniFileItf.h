 /**
 * <interfacename>CmpIniFile</interfacename>
 * <description> 
 * </description>
 * Interface to parse and manage ini-files.
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */


	
	
#ifndef _CMPINIFILEITF_H_
#define _CMPINIFILEITF_H_

#include "CmpStd.h"

 

 




#include "CmpStd.h"

/**
 * <category>Ini-file options</category>
 * <description></description>
 * <param name="INI_OPTION_NONE" type="IN">No option set</param>
 * <param name="INI_OPTION_CREATE" type="IN">Create ini-file</param>
 * <param name="INI_OPTION_OVERWRITE_EXISTING" type="IN">Overwrite existing ini-file, if INI_OPTION_CREATE is specified</param>
 */
#define INI_OPTION_NONE					0
#define INI_OPTION_CREATE				1
#define INI_OPTION_OVERWRITE_EXISTING	2

#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description>Function to open an ini-file</description>
 * <param name="pszFileName" type="IN">Name and path of the ini-file</param>
 * <param name="options" type="IN">Options to open ini-file. See category "Ini-file options"</param>
 * <param name="pResult" type="OUT">Error code</param> 
 * <errorcode name="RTS_RESULT *pResult" type="ERR_OK">Ini file can be opened</errorcode>
 * <errorcode name="RTS_RESULT *pResult" type="ERR_NO_OBJECT">Ini file cannot be opened (not existing, see INI_OPTION_NONE)</errorcode> 
 * <errorcode name="RTS_RESULT *pResult" type="ERR_FAILED">Ini file cannot be created (see INI_OPTION_CREATE or INI_OPTION_OVERWRITE_EXISTING)</errorcode>
 * <result>Handle to the opened ini-file or RTS_INVALID_HANDLE if failed</result>
 */
RTS_HANDLE CDECL IniOpen(const char *pszFileName, RTS_UI32 options, RTS_RESULT *pResult);
typedef RTS_HANDLE (CDECL * PFINIOPEN) (const char *pszFileName, RTS_UI32 options, RTS_RESULT *pResult);
#if defined(CMPINIFILE_NOTIMPLEMENTED) || defined(INIOPEN_NOTIMPLEMENTED)
	#define USE_IniOpen
	#define EXT_IniOpen
	#define GET_IniOpen(fl)  ERR_NOTIMPLEMENTED
	#define CAL_IniOpen(p0,p1,p2)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_IniOpen  FALSE
	#define EXP_IniOpen  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_IniOpen
	#define EXT_IniOpen
	#define GET_IniOpen(fl)  CAL_CMGETAPI( "IniOpen" ) 
	#define CAL_IniOpen  IniOpen
	#define CHK_IniOpen  TRUE
	#define EXP_IniOpen  CAL_CMEXPAPI( "IniOpen" ) 
#elif defined(MIXED_LINK) && !defined(CMPINIFILE_EXTERNAL)
	#define USE_IniOpen
	#define EXT_IniOpen
	#define GET_IniOpen(fl)  CAL_CMGETAPI( "IniOpen" ) 
	#define CAL_IniOpen  IniOpen
	#define CHK_IniOpen  TRUE
	#define EXP_IniOpen  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"IniOpen", (RTS_UINTPTR)IniOpen, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIniFileIniOpen
	#define EXT_CmpIniFileIniOpen
	#define GET_CmpIniFileIniOpen  ERR_OK
	#define CAL_CmpIniFileIniOpen pICmpIniFile->IIniOpen
	#define CHK_CmpIniFileIniOpen (pICmpIniFile != NULL)
	#define EXP_CmpIniFileIniOpen  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_IniOpen
	#define EXT_IniOpen
	#define GET_IniOpen(fl)  CAL_CMGETAPI( "IniOpen" ) 
	#define CAL_IniOpen pICmpIniFile->IIniOpen
	#define CHK_IniOpen (pICmpIniFile != NULL)
	#define EXP_IniOpen  CAL_CMEXPAPI( "IniOpen" ) 
#else /* DYNAMIC_LINK */
	#define USE_IniOpen  PFINIOPEN pfIniOpen;
	#define EXT_IniOpen  extern PFINIOPEN pfIniOpen;
	#define GET_IniOpen(fl)  s_pfCMGetAPI2( "IniOpen", (RTS_VOID_FCTPTR *)&pfIniOpen, (fl), 0, 0)
	#define CAL_IniOpen  pfIniOpen
	#define CHK_IniOpen  (pfIniOpen != NULL)
	#define EXP_IniOpen  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"IniOpen", (RTS_UINTPTR)IniOpen, 0, 0) 
#endif




/**
 * <description>Function to close an ini-file opened via IniOpen()</description>
 * <param name="hIniFile" type="IN">Handle to the ini file</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Ini file can be closed</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter</errorcode>
 */
RTS_RESULT CDECL IniClose(RTS_HANDLE hIniFile);
typedef RTS_RESULT (CDECL * PFINICLOSE) (RTS_HANDLE hIniFile);
#if defined(CMPINIFILE_NOTIMPLEMENTED) || defined(INICLOSE_NOTIMPLEMENTED)
	#define USE_IniClose
	#define EXT_IniClose
	#define GET_IniClose(fl)  ERR_NOTIMPLEMENTED
	#define CAL_IniClose(p0)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_IniClose  FALSE
	#define EXP_IniClose  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_IniClose
	#define EXT_IniClose
	#define GET_IniClose(fl)  CAL_CMGETAPI( "IniClose" ) 
	#define CAL_IniClose  IniClose
	#define CHK_IniClose  TRUE
	#define EXP_IniClose  CAL_CMEXPAPI( "IniClose" ) 
#elif defined(MIXED_LINK) && !defined(CMPINIFILE_EXTERNAL)
	#define USE_IniClose
	#define EXT_IniClose
	#define GET_IniClose(fl)  CAL_CMGETAPI( "IniClose" ) 
	#define CAL_IniClose  IniClose
	#define CHK_IniClose  TRUE
	#define EXP_IniClose  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"IniClose", (RTS_UINTPTR)IniClose, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIniFileIniClose
	#define EXT_CmpIniFileIniClose
	#define GET_CmpIniFileIniClose  ERR_OK
	#define CAL_CmpIniFileIniClose pICmpIniFile->IIniClose
	#define CHK_CmpIniFileIniClose (pICmpIniFile != NULL)
	#define EXP_CmpIniFileIniClose  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_IniClose
	#define EXT_IniClose
	#define GET_IniClose(fl)  CAL_CMGETAPI( "IniClose" ) 
	#define CAL_IniClose pICmpIniFile->IIniClose
	#define CHK_IniClose (pICmpIniFile != NULL)
	#define EXP_IniClose  CAL_CMEXPAPI( "IniClose" ) 
#else /* DYNAMIC_LINK */
	#define USE_IniClose  PFINICLOSE pfIniClose;
	#define EXT_IniClose  extern PFINICLOSE pfIniClose;
	#define GET_IniClose(fl)  s_pfCMGetAPI2( "IniClose", (RTS_VOID_FCTPTR *)&pfIniClose, (fl), 0, 0)
	#define CAL_IniClose  pfIniClose
	#define CHK_IniClose  (pfIniClose != NULL)
	#define EXP_IniClose  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"IniClose", (RTS_UINTPTR)IniClose, 0, 0) 
#endif




/**
 * <description>Function to delete an ini-file opened via IniOpen()</description>
 * <param name="hIniFile" type="IN">Handle to the ini file</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Ini file can be deleted</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter</errorcode>
 */
RTS_RESULT CDECL IniDelete(RTS_HANDLE hIniFile);
typedef RTS_RESULT (CDECL * PFINIDELETE) (RTS_HANDLE hIniFile);
#if defined(CMPINIFILE_NOTIMPLEMENTED) || defined(INIDELETE_NOTIMPLEMENTED)
	#define USE_IniDelete
	#define EXT_IniDelete
	#define GET_IniDelete(fl)  ERR_NOTIMPLEMENTED
	#define CAL_IniDelete(p0)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_IniDelete  FALSE
	#define EXP_IniDelete  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_IniDelete
	#define EXT_IniDelete
	#define GET_IniDelete(fl)  CAL_CMGETAPI( "IniDelete" ) 
	#define CAL_IniDelete  IniDelete
	#define CHK_IniDelete  TRUE
	#define EXP_IniDelete  CAL_CMEXPAPI( "IniDelete" ) 
#elif defined(MIXED_LINK) && !defined(CMPINIFILE_EXTERNAL)
	#define USE_IniDelete
	#define EXT_IniDelete
	#define GET_IniDelete(fl)  CAL_CMGETAPI( "IniDelete" ) 
	#define CAL_IniDelete  IniDelete
	#define CHK_IniDelete  TRUE
	#define EXP_IniDelete  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"IniDelete", (RTS_UINTPTR)IniDelete, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIniFileIniDelete
	#define EXT_CmpIniFileIniDelete
	#define GET_CmpIniFileIniDelete  ERR_OK
	#define CAL_CmpIniFileIniDelete pICmpIniFile->IIniDelete
	#define CHK_CmpIniFileIniDelete (pICmpIniFile != NULL)
	#define EXP_CmpIniFileIniDelete  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_IniDelete
	#define EXT_IniDelete
	#define GET_IniDelete(fl)  CAL_CMGETAPI( "IniDelete" ) 
	#define CAL_IniDelete pICmpIniFile->IIniDelete
	#define CHK_IniDelete (pICmpIniFile != NULL)
	#define EXP_IniDelete  CAL_CMEXPAPI( "IniDelete" ) 
#else /* DYNAMIC_LINK */
	#define USE_IniDelete  PFINIDELETE pfIniDelete;
	#define EXT_IniDelete  extern PFINIDELETE pfIniDelete;
	#define GET_IniDelete(fl)  s_pfCMGetAPI2( "IniDelete", (RTS_VOID_FCTPTR *)&pfIniDelete, (fl), 0, 0)
	#define CAL_IniDelete  pfIniDelete
	#define CHK_IniDelete  (pfIniDelete != NULL)
	#define EXP_IniDelete  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"IniDelete", (RTS_UINTPTR)IniDelete, 0, 0) 
#endif




/**
 * <description>Function to read an entry from ini file</description>
 * <param name="hIniFile" type="IN">Handle to the ini file</param>
 * <param name="pszSection" type="IN">Section name</param>
 * <param name="pszKey" type="IN">Key name</param>
 * <param name="pszValue" type="OUT">Pointer to value string to get value</param> 
 * <param name="piMaxLen" type="INOUT">Pointer to max length of string. Length read is returned.</param>  
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Ini file entry can be read</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter</errorcode>
 */
RTS_RESULT CDECL IniReadValue(RTS_HANDLE hIniFile, const char *pszSection, char *pszKey, char *pszValue, RTS_I32 *piMaxLen);
typedef RTS_RESULT (CDECL * PFINIREADVALUE) (RTS_HANDLE hIniFile, const char *pszSection, char *pszKey, char *pszValue, RTS_I32 *piMaxLen);
#if defined(CMPINIFILE_NOTIMPLEMENTED) || defined(INIREADVALUE_NOTIMPLEMENTED)
	#define USE_IniReadValue
	#define EXT_IniReadValue
	#define GET_IniReadValue(fl)  ERR_NOTIMPLEMENTED
	#define CAL_IniReadValue(p0,p1,p2,p3,p4)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_IniReadValue  FALSE
	#define EXP_IniReadValue  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_IniReadValue
	#define EXT_IniReadValue
	#define GET_IniReadValue(fl)  CAL_CMGETAPI( "IniReadValue" ) 
	#define CAL_IniReadValue  IniReadValue
	#define CHK_IniReadValue  TRUE
	#define EXP_IniReadValue  CAL_CMEXPAPI( "IniReadValue" ) 
#elif defined(MIXED_LINK) && !defined(CMPINIFILE_EXTERNAL)
	#define USE_IniReadValue
	#define EXT_IniReadValue
	#define GET_IniReadValue(fl)  CAL_CMGETAPI( "IniReadValue" ) 
	#define CAL_IniReadValue  IniReadValue
	#define CHK_IniReadValue  TRUE
	#define EXP_IniReadValue  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"IniReadValue", (RTS_UINTPTR)IniReadValue, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIniFileIniReadValue
	#define EXT_CmpIniFileIniReadValue
	#define GET_CmpIniFileIniReadValue  ERR_OK
	#define CAL_CmpIniFileIniReadValue pICmpIniFile->IIniReadValue
	#define CHK_CmpIniFileIniReadValue (pICmpIniFile != NULL)
	#define EXP_CmpIniFileIniReadValue  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_IniReadValue
	#define EXT_IniReadValue
	#define GET_IniReadValue(fl)  CAL_CMGETAPI( "IniReadValue" ) 
	#define CAL_IniReadValue pICmpIniFile->IIniReadValue
	#define CHK_IniReadValue (pICmpIniFile != NULL)
	#define EXP_IniReadValue  CAL_CMEXPAPI( "IniReadValue" ) 
#else /* DYNAMIC_LINK */
	#define USE_IniReadValue  PFINIREADVALUE pfIniReadValue;
	#define EXT_IniReadValue  extern PFINIREADVALUE pfIniReadValue;
	#define GET_IniReadValue(fl)  s_pfCMGetAPI2( "IniReadValue", (RTS_VOID_FCTPTR *)&pfIniReadValue, (fl), 0, 0)
	#define CAL_IniReadValue  pfIniReadValue
	#define CHK_IniReadValue  (pfIniReadValue != NULL)
	#define EXP_IniReadValue  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"IniReadValue", (RTS_UINTPTR)IniReadValue, 0, 0) 
#endif




/**
 * <description>Function to write an entry to ini file</description>
 * <param name="hIniFile" type="IN">Handle to the ini file</param>
 * <param name="pszSection" type="IN">Section name</param>
 * <param name="pszKey" type="IN">Key name</param>
 * <param name="pszValue" type="OUT">Pointer to value string that should be written</param> 
 * <param name="iLen" type="INOUT">Length of value string to write</param>  
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Ini file entry can be written</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter</errorcode>
 */
RTS_RESULT CDECL IniWriteValue(RTS_HANDLE hIniFile, const char *pszSection, char *pszKey, char *pszValue, RTS_I32 iLen);
typedef RTS_RESULT (CDECL * PFINIWRITEVALUE) (RTS_HANDLE hIniFile, const char *pszSection, char *pszKey, char *pszValue, RTS_I32 iLen);
#if defined(CMPINIFILE_NOTIMPLEMENTED) || defined(INIWRITEVALUE_NOTIMPLEMENTED)
	#define USE_IniWriteValue
	#define EXT_IniWriteValue
	#define GET_IniWriteValue(fl)  ERR_NOTIMPLEMENTED
	#define CAL_IniWriteValue(p0,p1,p2,p3,p4)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_IniWriteValue  FALSE
	#define EXP_IniWriteValue  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_IniWriteValue
	#define EXT_IniWriteValue
	#define GET_IniWriteValue(fl)  CAL_CMGETAPI( "IniWriteValue" ) 
	#define CAL_IniWriteValue  IniWriteValue
	#define CHK_IniWriteValue  TRUE
	#define EXP_IniWriteValue  CAL_CMEXPAPI( "IniWriteValue" ) 
#elif defined(MIXED_LINK) && !defined(CMPINIFILE_EXTERNAL)
	#define USE_IniWriteValue
	#define EXT_IniWriteValue
	#define GET_IniWriteValue(fl)  CAL_CMGETAPI( "IniWriteValue" ) 
	#define CAL_IniWriteValue  IniWriteValue
	#define CHK_IniWriteValue  TRUE
	#define EXP_IniWriteValue  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"IniWriteValue", (RTS_UINTPTR)IniWriteValue, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIniFileIniWriteValue
	#define EXT_CmpIniFileIniWriteValue
	#define GET_CmpIniFileIniWriteValue  ERR_OK
	#define CAL_CmpIniFileIniWriteValue pICmpIniFile->IIniWriteValue
	#define CHK_CmpIniFileIniWriteValue (pICmpIniFile != NULL)
	#define EXP_CmpIniFileIniWriteValue  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_IniWriteValue
	#define EXT_IniWriteValue
	#define GET_IniWriteValue(fl)  CAL_CMGETAPI( "IniWriteValue" ) 
	#define CAL_IniWriteValue pICmpIniFile->IIniWriteValue
	#define CHK_IniWriteValue (pICmpIniFile != NULL)
	#define EXP_IniWriteValue  CAL_CMEXPAPI( "IniWriteValue" ) 
#else /* DYNAMIC_LINK */
	#define USE_IniWriteValue  PFINIWRITEVALUE pfIniWriteValue;
	#define EXT_IniWriteValue  extern PFINIWRITEVALUE pfIniWriteValue;
	#define GET_IniWriteValue(fl)  s_pfCMGetAPI2( "IniWriteValue", (RTS_VOID_FCTPTR *)&pfIniWriteValue, (fl), 0, 0)
	#define CAL_IniWriteValue  pfIniWriteValue
	#define CHK_IniWriteValue  (pfIniWriteValue != NULL)
	#define EXP_IniWriteValue  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"IniWriteValue", (RTS_UINTPTR)IniWriteValue, 0, 0) 
#endif




/**
 * <description>Function to remove an entry from ini file</description>
 * <param name="hIniFile" type="IN">Handle to the ini file</param>
 * <param name="pszSection" type="IN">Section name</param>
 * <param name="pszKey" type="IN">Key name</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Ini file entry can be removed</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter</errorcode>
 */
RTS_RESULT CDECL IniRemoveKey(RTS_HANDLE hIniFile, const char *pszSection, const char *pszKey);
typedef RTS_RESULT (CDECL * PFINIREMOVEKEY) (RTS_HANDLE hIniFile, const char *pszSection, const char *pszKey);
#if defined(CMPINIFILE_NOTIMPLEMENTED) || defined(INIREMOVEKEY_NOTIMPLEMENTED)
	#define USE_IniRemoveKey
	#define EXT_IniRemoveKey
	#define GET_IniRemoveKey(fl)  ERR_NOTIMPLEMENTED
	#define CAL_IniRemoveKey(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_IniRemoveKey  FALSE
	#define EXP_IniRemoveKey  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_IniRemoveKey
	#define EXT_IniRemoveKey
	#define GET_IniRemoveKey(fl)  CAL_CMGETAPI( "IniRemoveKey" ) 
	#define CAL_IniRemoveKey  IniRemoveKey
	#define CHK_IniRemoveKey  TRUE
	#define EXP_IniRemoveKey  CAL_CMEXPAPI( "IniRemoveKey" ) 
#elif defined(MIXED_LINK) && !defined(CMPINIFILE_EXTERNAL)
	#define USE_IniRemoveKey
	#define EXT_IniRemoveKey
	#define GET_IniRemoveKey(fl)  CAL_CMGETAPI( "IniRemoveKey" ) 
	#define CAL_IniRemoveKey  IniRemoveKey
	#define CHK_IniRemoveKey  TRUE
	#define EXP_IniRemoveKey  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"IniRemoveKey", (RTS_UINTPTR)IniRemoveKey, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIniFileIniRemoveKey
	#define EXT_CmpIniFileIniRemoveKey
	#define GET_CmpIniFileIniRemoveKey  ERR_OK
	#define CAL_CmpIniFileIniRemoveKey pICmpIniFile->IIniRemoveKey
	#define CHK_CmpIniFileIniRemoveKey (pICmpIniFile != NULL)
	#define EXP_CmpIniFileIniRemoveKey  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_IniRemoveKey
	#define EXT_IniRemoveKey
	#define GET_IniRemoveKey(fl)  CAL_CMGETAPI( "IniRemoveKey" ) 
	#define CAL_IniRemoveKey pICmpIniFile->IIniRemoveKey
	#define CHK_IniRemoveKey (pICmpIniFile != NULL)
	#define EXP_IniRemoveKey  CAL_CMEXPAPI( "IniRemoveKey" ) 
#else /* DYNAMIC_LINK */
	#define USE_IniRemoveKey  PFINIREMOVEKEY pfIniRemoveKey;
	#define EXT_IniRemoveKey  extern PFINIREMOVEKEY pfIniRemoveKey;
	#define GET_IniRemoveKey(fl)  s_pfCMGetAPI2( "IniRemoveKey", (RTS_VOID_FCTPTR *)&pfIniRemoveKey, (fl), 0, 0)
	#define CAL_IniRemoveKey  pfIniRemoveKey
	#define CHK_IniRemoveKey  (pfIniRemoveKey != NULL)
	#define EXP_IniRemoveKey  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"IniRemoveKey", (RTS_UINTPTR)IniRemoveKey, 0, 0) 
#endif




/**
 * <description>Function to remove all key from the specified section</description>
 * <param name="hIniFile" type="IN">Handle to the ini file</param>
 * <param name="pszSection" type="IN">Section name</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Ini file entries can be removed</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter</errorcode>
 */
RTS_RESULT CDECL IniRemoveAllKeys(RTS_HANDLE hIniFile, const char *pszSection);
typedef RTS_RESULT (CDECL * PFINIREMOVEALLKEYS) (RTS_HANDLE hIniFile, const char *pszSection);
#if defined(CMPINIFILE_NOTIMPLEMENTED) || defined(INIREMOVEALLKEYS_NOTIMPLEMENTED)
	#define USE_IniRemoveAllKeys
	#define EXT_IniRemoveAllKeys
	#define GET_IniRemoveAllKeys(fl)  ERR_NOTIMPLEMENTED
	#define CAL_IniRemoveAllKeys(p0,p1)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_IniRemoveAllKeys  FALSE
	#define EXP_IniRemoveAllKeys  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_IniRemoveAllKeys
	#define EXT_IniRemoveAllKeys
	#define GET_IniRemoveAllKeys(fl)  CAL_CMGETAPI( "IniRemoveAllKeys" ) 
	#define CAL_IniRemoveAllKeys  IniRemoveAllKeys
	#define CHK_IniRemoveAllKeys  TRUE
	#define EXP_IniRemoveAllKeys  CAL_CMEXPAPI( "IniRemoveAllKeys" ) 
#elif defined(MIXED_LINK) && !defined(CMPINIFILE_EXTERNAL)
	#define USE_IniRemoveAllKeys
	#define EXT_IniRemoveAllKeys
	#define GET_IniRemoveAllKeys(fl)  CAL_CMGETAPI( "IniRemoveAllKeys" ) 
	#define CAL_IniRemoveAllKeys  IniRemoveAllKeys
	#define CHK_IniRemoveAllKeys  TRUE
	#define EXP_IniRemoveAllKeys  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"IniRemoveAllKeys", (RTS_UINTPTR)IniRemoveAllKeys, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIniFileIniRemoveAllKeys
	#define EXT_CmpIniFileIniRemoveAllKeys
	#define GET_CmpIniFileIniRemoveAllKeys  ERR_OK
	#define CAL_CmpIniFileIniRemoveAllKeys pICmpIniFile->IIniRemoveAllKeys
	#define CHK_CmpIniFileIniRemoveAllKeys (pICmpIniFile != NULL)
	#define EXP_CmpIniFileIniRemoveAllKeys  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_IniRemoveAllKeys
	#define EXT_IniRemoveAllKeys
	#define GET_IniRemoveAllKeys(fl)  CAL_CMGETAPI( "IniRemoveAllKeys" ) 
	#define CAL_IniRemoveAllKeys pICmpIniFile->IIniRemoveAllKeys
	#define CHK_IniRemoveAllKeys (pICmpIniFile != NULL)
	#define EXP_IniRemoveAllKeys  CAL_CMEXPAPI( "IniRemoveAllKeys" ) 
#else /* DYNAMIC_LINK */
	#define USE_IniRemoveAllKeys  PFINIREMOVEALLKEYS pfIniRemoveAllKeys;
	#define EXT_IniRemoveAllKeys  extern PFINIREMOVEALLKEYS pfIniRemoveAllKeys;
	#define GET_IniRemoveAllKeys(fl)  s_pfCMGetAPI2( "IniRemoveAllKeys", (RTS_VOID_FCTPTR *)&pfIniRemoveAllKeys, (fl), 0, 0)
	#define CAL_IniRemoveAllKeys  pfIniRemoveAllKeys
	#define CHK_IniRemoveAllKeys  (pfIniRemoveAllKeys != NULL)
	#define EXP_IniRemoveAllKeys  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"IniRemoveAllKeys", (RTS_UINTPTR)IniRemoveAllKeys, 0, 0) 
#endif




/**
 * <description>Function to check, if ini file is write protected</description>
 * <param name="hIniFile" type="IN">Handle to the ini file</param>
 * <param name="pszSection" type="IN">Section name</param>
 * <result>BOOL return value</result>
 * <errorcode name="RTS_BOOL" type="TRUE">Ini file is write protected</errorcode>
 * <errorcode name="RTS_BOOL" type="FALSE">Ini file is not write protected</errorcode>
 */
RTS_BOOL CDECL IniIsWriteProtected(RTS_HANDLE hIniFile, RTS_RESULT *pResult);
typedef RTS_BOOL (CDECL * PFINIISWRITEPROTECTED) (RTS_HANDLE hIniFile, RTS_RESULT *pResult);
#if defined(CMPINIFILE_NOTIMPLEMENTED) || defined(INIISWRITEPROTECTED_NOTIMPLEMENTED)
	#define USE_IniIsWriteProtected
	#define EXT_IniIsWriteProtected
	#define GET_IniIsWriteProtected(fl)  ERR_NOTIMPLEMENTED
	#define CAL_IniIsWriteProtected(p0,p1)  (RTS_BOOL)ERR_NOTIMPLEMENTED
	#define CHK_IniIsWriteProtected  FALSE
	#define EXP_IniIsWriteProtected  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_IniIsWriteProtected
	#define EXT_IniIsWriteProtected
	#define GET_IniIsWriteProtected(fl)  CAL_CMGETAPI( "IniIsWriteProtected" ) 
	#define CAL_IniIsWriteProtected  IniIsWriteProtected
	#define CHK_IniIsWriteProtected  TRUE
	#define EXP_IniIsWriteProtected  CAL_CMEXPAPI( "IniIsWriteProtected" ) 
#elif defined(MIXED_LINK) && !defined(CMPINIFILE_EXTERNAL)
	#define USE_IniIsWriteProtected
	#define EXT_IniIsWriteProtected
	#define GET_IniIsWriteProtected(fl)  CAL_CMGETAPI( "IniIsWriteProtected" ) 
	#define CAL_IniIsWriteProtected  IniIsWriteProtected
	#define CHK_IniIsWriteProtected  TRUE
	#define EXP_IniIsWriteProtected  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"IniIsWriteProtected", (RTS_UINTPTR)IniIsWriteProtected, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIniFileIniIsWriteProtected
	#define EXT_CmpIniFileIniIsWriteProtected
	#define GET_CmpIniFileIniIsWriteProtected  ERR_OK
	#define CAL_CmpIniFileIniIsWriteProtected pICmpIniFile->IIniIsWriteProtected
	#define CHK_CmpIniFileIniIsWriteProtected (pICmpIniFile != NULL)
	#define EXP_CmpIniFileIniIsWriteProtected  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_IniIsWriteProtected
	#define EXT_IniIsWriteProtected
	#define GET_IniIsWriteProtected(fl)  CAL_CMGETAPI( "IniIsWriteProtected" ) 
	#define CAL_IniIsWriteProtected pICmpIniFile->IIniIsWriteProtected
	#define CHK_IniIsWriteProtected (pICmpIniFile != NULL)
	#define EXP_IniIsWriteProtected  CAL_CMEXPAPI( "IniIsWriteProtected" ) 
#else /* DYNAMIC_LINK */
	#define USE_IniIsWriteProtected  PFINIISWRITEPROTECTED pfIniIsWriteProtected;
	#define EXT_IniIsWriteProtected  extern PFINIISWRITEPROTECTED pfIniIsWriteProtected;
	#define GET_IniIsWriteProtected(fl)  s_pfCMGetAPI2( "IniIsWriteProtected", (RTS_VOID_FCTPTR *)&pfIniIsWriteProtected, (fl), 0, 0)
	#define CAL_IniIsWriteProtected  pfIniIsWriteProtected
	#define CHK_IniIsWriteProtected  (pfIniIsWriteProtected != NULL)
	#define EXP_IniIsWriteProtected  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"IniIsWriteProtected", (RTS_UINTPTR)IniIsWriteProtected, 0, 0) 
#endif




/**
 * <description>Function to set a filter/section list for the ini file! If such a filter list is specified, only these sections can be stored in the ini file!</description>
 * <param name="hIniFile" type="IN">Handle to the ini file</param>
 * <param name="pszFilter" type="IN">List of sections with a comma separated list:
 *                                  Example: "[CmpApp], [CmpDevice]"</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Ini file filter can be set</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter</errorcode>
 */
RTS_RESULT CDECL IniSetFilter(RTS_HANDLE hIniFile, char *pszFilter);
typedef RTS_RESULT (CDECL * PFINISETFILTER) (RTS_HANDLE hIniFile, char *pszFilter);
#if defined(CMPINIFILE_NOTIMPLEMENTED) || defined(INISETFILTER_NOTIMPLEMENTED)
	#define USE_IniSetFilter
	#define EXT_IniSetFilter
	#define GET_IniSetFilter(fl)  ERR_NOTIMPLEMENTED
	#define CAL_IniSetFilter(p0,p1)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_IniSetFilter  FALSE
	#define EXP_IniSetFilter  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_IniSetFilter
	#define EXT_IniSetFilter
	#define GET_IniSetFilter(fl)  CAL_CMGETAPI( "IniSetFilter" ) 
	#define CAL_IniSetFilter  IniSetFilter
	#define CHK_IniSetFilter  TRUE
	#define EXP_IniSetFilter  CAL_CMEXPAPI( "IniSetFilter" ) 
#elif defined(MIXED_LINK) && !defined(CMPINIFILE_EXTERNAL)
	#define USE_IniSetFilter
	#define EXT_IniSetFilter
	#define GET_IniSetFilter(fl)  CAL_CMGETAPI( "IniSetFilter" ) 
	#define CAL_IniSetFilter  IniSetFilter
	#define CHK_IniSetFilter  TRUE
	#define EXP_IniSetFilter  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"IniSetFilter", (RTS_UINTPTR)IniSetFilter, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIniFileIniSetFilter
	#define EXT_CmpIniFileIniSetFilter
	#define GET_CmpIniFileIniSetFilter  ERR_OK
	#define CAL_CmpIniFileIniSetFilter pICmpIniFile->IIniSetFilter
	#define CHK_CmpIniFileIniSetFilter (pICmpIniFile != NULL)
	#define EXP_CmpIniFileIniSetFilter  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_IniSetFilter
	#define EXT_IniSetFilter
	#define GET_IniSetFilter(fl)  CAL_CMGETAPI( "IniSetFilter" ) 
	#define CAL_IniSetFilter pICmpIniFile->IIniSetFilter
	#define CHK_IniSetFilter (pICmpIniFile != NULL)
	#define EXP_IniSetFilter  CAL_CMEXPAPI( "IniSetFilter" ) 
#else /* DYNAMIC_LINK */
	#define USE_IniSetFilter  PFINISETFILTER pfIniSetFilter;
	#define EXT_IniSetFilter  extern PFINISETFILTER pfIniSetFilter;
	#define GET_IniSetFilter(fl)  s_pfCMGetAPI2( "IniSetFilter", (RTS_VOID_FCTPTR *)&pfIniSetFilter, (fl), 0, 0)
	#define CAL_IniSetFilter  pfIniSetFilter
	#define CHK_IniSetFilter  (pfIniSetFilter != NULL)
	#define EXP_IniSetFilter  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"IniSetFilter", (RTS_UINTPTR)IniSetFilter, 0, 0) 
#endif




/**
 * <description>Function to set check, if a filter of the specified section is set for this ini file!</description>
 * <param name="hIniFile" type="IN">Handle to the ini file</param>
 * <param name="pszSection" type="IN">Section name</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Ini file filter for the section is valid</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Ini file filter for the section is not valid!</errorcode>
 */
RTS_RESULT CDECL IniCheckFilter(RTS_HANDLE hIniFile, const char *pszSection);
typedef RTS_RESULT (CDECL * PFINICHECKFILTER) (RTS_HANDLE hIniFile, const char *pszSection);
#if defined(CMPINIFILE_NOTIMPLEMENTED) || defined(INICHECKFILTER_NOTIMPLEMENTED)
	#define USE_IniCheckFilter
	#define EXT_IniCheckFilter
	#define GET_IniCheckFilter(fl)  ERR_NOTIMPLEMENTED
	#define CAL_IniCheckFilter(p0,p1)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_IniCheckFilter  FALSE
	#define EXP_IniCheckFilter  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_IniCheckFilter
	#define EXT_IniCheckFilter
	#define GET_IniCheckFilter(fl)  CAL_CMGETAPI( "IniCheckFilter" ) 
	#define CAL_IniCheckFilter  IniCheckFilter
	#define CHK_IniCheckFilter  TRUE
	#define EXP_IniCheckFilter  CAL_CMEXPAPI( "IniCheckFilter" ) 
#elif defined(MIXED_LINK) && !defined(CMPINIFILE_EXTERNAL)
	#define USE_IniCheckFilter
	#define EXT_IniCheckFilter
	#define GET_IniCheckFilter(fl)  CAL_CMGETAPI( "IniCheckFilter" ) 
	#define CAL_IniCheckFilter  IniCheckFilter
	#define CHK_IniCheckFilter  TRUE
	#define EXP_IniCheckFilter  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"IniCheckFilter", (RTS_UINTPTR)IniCheckFilter, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpIniFileIniCheckFilter
	#define EXT_CmpIniFileIniCheckFilter
	#define GET_CmpIniFileIniCheckFilter  ERR_OK
	#define CAL_CmpIniFileIniCheckFilter pICmpIniFile->IIniCheckFilter
	#define CHK_CmpIniFileIniCheckFilter (pICmpIniFile != NULL)
	#define EXP_CmpIniFileIniCheckFilter  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_IniCheckFilter
	#define EXT_IniCheckFilter
	#define GET_IniCheckFilter(fl)  CAL_CMGETAPI( "IniCheckFilter" ) 
	#define CAL_IniCheckFilter pICmpIniFile->IIniCheckFilter
	#define CHK_IniCheckFilter (pICmpIniFile != NULL)
	#define EXP_IniCheckFilter  CAL_CMEXPAPI( "IniCheckFilter" ) 
#else /* DYNAMIC_LINK */
	#define USE_IniCheckFilter  PFINICHECKFILTER pfIniCheckFilter;
	#define EXT_IniCheckFilter  extern PFINICHECKFILTER pfIniCheckFilter;
	#define GET_IniCheckFilter(fl)  s_pfCMGetAPI2( "IniCheckFilter", (RTS_VOID_FCTPTR *)&pfIniCheckFilter, (fl), 0, 0)
	#define CAL_IniCheckFilter  pfIniCheckFilter
	#define CHK_IniCheckFilter  (pfIniCheckFilter != NULL)
	#define EXP_IniCheckFilter  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"IniCheckFilter", (RTS_UINTPTR)IniCheckFilter, 0, 0) 
#endif




#ifdef __cplusplus
}
#endif



typedef struct
{
	IBase_C *pBase;
	PFINIOPEN IIniOpen;
 	PFINICLOSE IIniClose;
 	PFINIDELETE IIniDelete;
 	PFINIREADVALUE IIniReadValue;
 	PFINIWRITEVALUE IIniWriteValue;
 	PFINIREMOVEKEY IIniRemoveKey;
 	PFINIREMOVEALLKEYS IIniRemoveAllKeys;
 	PFINIISWRITEPROTECTED IIniIsWriteProtected;
 	PFINISETFILTER IIniSetFilter;
 	PFINICHECKFILTER IIniCheckFilter;
 } ICmpIniFile_C;

#ifdef CPLUSPLUS
class ICmpIniFile : public IBase
{
	public:
		virtual RTS_HANDLE CDECL IIniOpen(const char *pszFileName, RTS_UI32 options, RTS_RESULT *pResult) =0;
		virtual RTS_RESULT CDECL IIniClose(RTS_HANDLE hIniFile) =0;
		virtual RTS_RESULT CDECL IIniDelete(RTS_HANDLE hIniFile) =0;
		virtual RTS_RESULT CDECL IIniReadValue(RTS_HANDLE hIniFile, const char *pszSection, char *pszKey, char *pszValue, RTS_I32 *piMaxLen) =0;
		virtual RTS_RESULT CDECL IIniWriteValue(RTS_HANDLE hIniFile, const char *pszSection, char *pszKey, char *pszValue, RTS_I32 iLen) =0;
		virtual RTS_RESULT CDECL IIniRemoveKey(RTS_HANDLE hIniFile, const char *pszSection, const char *pszKey) =0;
		virtual RTS_RESULT CDECL IIniRemoveAllKeys(RTS_HANDLE hIniFile, const char *pszSection) =0;
		virtual RTS_BOOL CDECL IIniIsWriteProtected(RTS_HANDLE hIniFile, RTS_RESULT *pResult) =0;
		virtual RTS_RESULT CDECL IIniSetFilter(RTS_HANDLE hIniFile, char *pszFilter) =0;
		virtual RTS_RESULT CDECL IIniCheckFilter(RTS_HANDLE hIniFile, const char *pszSection) =0;
};
	#ifndef ITF_CmpIniFile
		#define ITF_CmpIniFile static ICmpIniFile *pICmpIniFile = NULL;
	#endif
	#define EXTITF_CmpIniFile
#else	/*CPLUSPLUS*/
	typedef ICmpIniFile_C		ICmpIniFile;
	#ifndef ITF_CmpIniFile
		#define ITF_CmpIniFile
	#endif
	#define EXTITF_CmpIniFile
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_CMPINIFILEITF_H_*/
