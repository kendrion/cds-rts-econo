/**
 * <interfacename>CmpIniFile</interfacename>
 * <description> 
 * </description>
 * Interface to parse and manage ini-files.
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`CmpIniFile')

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
DEF_ITF_API(`RTS_HANDLE',`CDECL',`IniOpen',`(const char *pszFileName, RTS_UI32 options, RTS_RESULT *pResult)')

/**
 * <description>Function to close an ini-file opened via IniOpen()</description>
 * <param name="hIniFile" type="IN">Handle to the ini file</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Ini file can be closed</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter</errorcode>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`IniClose',`(RTS_HANDLE hIniFile)')

/**
 * <description>Function to delete an ini-file opened via IniOpen()</description>
 * <param name="hIniFile" type="IN">Handle to the ini file</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Ini file can be deleted</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter</errorcode>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`IniDelete',`(RTS_HANDLE hIniFile)')

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
DEF_ITF_API(`RTS_RESULT',`CDECL',`IniReadValue',`(RTS_HANDLE hIniFile, const char *pszSection, char *pszKey, char *pszValue, RTS_I32 *piMaxLen)')

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
DEF_ITF_API(`RTS_RESULT',`CDECL',`IniWriteValue',`(RTS_HANDLE hIniFile, const char *pszSection, char *pszKey, char *pszValue, RTS_I32 iLen)')

/**
 * <description>Function to remove an entry from ini file</description>
 * <param name="hIniFile" type="IN">Handle to the ini file</param>
 * <param name="pszSection" type="IN">Section name</param>
 * <param name="pszKey" type="IN">Key name</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Ini file entry can be removed</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter</errorcode>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`IniRemoveKey',`(RTS_HANDLE hIniFile, const char *pszSection, const char *pszKey)')

/**
 * <description>Function to remove all key from the specified section</description>
 * <param name="hIniFile" type="IN">Handle to the ini file</param>
 * <param name="pszSection" type="IN">Section name</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Ini file entries can be removed</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter</errorcode>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`IniRemoveAllKeys',`(RTS_HANDLE hIniFile, const char *pszSection)')

/**
 * <description>Function to check, if ini file is write protected</description>
 * <param name="hIniFile" type="IN">Handle to the ini file</param>
 * <param name="pszSection" type="IN">Section name</param>
 * <result>BOOL return value</result>
 * <errorcode name="RTS_BOOL" type="TRUE">Ini file is write protected</errorcode>
 * <errorcode name="RTS_BOOL" type="FALSE">Ini file is not write protected</errorcode>
 */
DEF_ITF_API(`RTS_BOOL',`CDECL',`IniIsWriteProtected',`(RTS_HANDLE hIniFile, RTS_RESULT *pResult)')

/**
 * <description>Function to set a filter/section list for the ini file! If such a filter list is specified, only these sections can be stored in the ini file!</description>
 * <param name="hIniFile" type="IN">Handle to the ini file</param>
 * <param name="pszFilter" type="IN">List of sections with a comma separated list:
 *                                  Example: "[CmpApp], [CmpDevice]"</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Ini file filter can be set</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter</errorcode>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`IniSetFilter',`(RTS_HANDLE hIniFile, char *pszFilter)')

/**
 * <description>Function to set check, if a filter of the specified section is set for this ini file!</description>
 * <param name="hIniFile" type="IN">Handle to the ini file</param>
 * <param name="pszSection" type="IN">Section name</param>
 * <result>error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Ini file filter for the section is valid</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">Ini file filter for the section is not valid!</errorcode>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`IniCheckFilter',`(RTS_HANDLE hIniFile, const char *pszSection)')

#ifdef __cplusplus
}
#endif
