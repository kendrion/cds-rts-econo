 /**
 * <interfacename>CmpUserMgr_Implementation</interfacename>
 * <description>External implementation of CmpUserMgr functions for authentication, authorization, and uesrobject handling</description>
 *
 * <copyright>
 * Copyright (c) 2020 CODESYS Development GmbH. All rights reserved.
 * </copyright>
 */


	
	
#ifndef _CMPUSERMGR_IMPLEMENTATIONITF_H_
#define _CMPUSERMGR_IMPLEMENTATIONITF_H_

#include "CmpStd.h"

 

 




/** EXTERN LIB SECTION BEGIN **/
/*  Comments are ignored for m4 compiler so restructured text can be used.  */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Changes the users password
 * :return: Error code
 * 	 + ERR_OK: Password changed successfully
 * 	 + ERR_NOTINITIALIZED: The user management is not initialized or it is not loaded yet
 * 	 + ERR_OPERATION_DENIED: Password change is either not supported or not allowed
 * 	 + ERR_USER_MISMATCH: User name does not match
 * 	 + ERR_INVALID_HANDLE: hUser is invalid or unknown
 */
typedef struct tagusermgrchangemypassword_struct
{
	RTS_IEC_HANDLE hUser;				/* VAR_INPUT */	/* Handle to the user */
	RTS_IEC_STRING *pszUser;			/* VAR_INPUT */	/* Name of the user, limited to 59 chars */
	RTS_IEC_STRING *pszOldPassword;		/* VAR_INPUT */	/* Old password (plain text), limited to 59 chars */
	RTS_IEC_STRING *pszNewPassword;		/* VAR_INPUT */	/* New password (plain text), limited to 59 chars */
	RTS_IEC_RESULT UserMgrChangeMyPassword;	/* VAR_OUTPUT */	
} usermgrchangemypassword_struct;

void CDECL CDECL_EXT usermgrchangemypassword(usermgrchangemypassword_struct *p);
typedef void (CDECL CDECL_EXT* PFUSERMGRCHANGEMYPASSWORD_IEC) (usermgrchangemypassword_struct *p);
#if defined(CMPUSERMGR_IMPLEMENTATION_NOTIMPLEMENTED) || defined(USERMGRCHANGEMYPASSWORD_NOTIMPLEMENTED)
	#define USE_usermgrchangemypassword
	#define EXT_usermgrchangemypassword
	#define GET_usermgrchangemypassword(fl)  ERR_NOTIMPLEMENTED
	#define CAL_usermgrchangemypassword(p0) 
	#define CHK_usermgrchangemypassword  FALSE
	#define EXP_usermgrchangemypassword  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_usermgrchangemypassword
	#define EXT_usermgrchangemypassword
	#define GET_usermgrchangemypassword(fl)  CAL_CMGETAPI( "usermgrchangemypassword" ) 
	#define CAL_usermgrchangemypassword  usermgrchangemypassword
	#define CHK_usermgrchangemypassword  TRUE
	#define EXP_usermgrchangemypassword  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrchangemypassword", (RTS_UINTPTR)usermgrchangemypassword, 1, 0x25575868, 0x03051100) 
#elif defined(MIXED_LINK) && !defined(CMPUSERMGR_IMPLEMENTATION_EXTERNAL)
	#define USE_usermgrchangemypassword
	#define EXT_usermgrchangemypassword
	#define GET_usermgrchangemypassword(fl)  CAL_CMGETAPI( "usermgrchangemypassword" ) 
	#define CAL_usermgrchangemypassword  usermgrchangemypassword
	#define CHK_usermgrchangemypassword  TRUE
	#define EXP_usermgrchangemypassword  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrchangemypassword", (RTS_UINTPTR)usermgrchangemypassword, 1, 0x25575868, 0x03051100) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserMgr_Implementationusermgrchangemypassword
	#define EXT_CmpUserMgr_Implementationusermgrchangemypassword
	#define GET_CmpUserMgr_Implementationusermgrchangemypassword  ERR_OK
	#define CAL_CmpUserMgr_Implementationusermgrchangemypassword  usermgrchangemypassword
	#define CHK_CmpUserMgr_Implementationusermgrchangemypassword  TRUE
	#define EXP_CmpUserMgr_Implementationusermgrchangemypassword  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrchangemypassword", (RTS_UINTPTR)usermgrchangemypassword, 1, 0x25575868, 0x03051100) 
#elif defined(CPLUSPLUS)
	#define USE_usermgrchangemypassword
	#define EXT_usermgrchangemypassword
	#define GET_usermgrchangemypassword(fl)  CAL_CMGETAPI( "usermgrchangemypassword" ) 
	#define CAL_usermgrchangemypassword  usermgrchangemypassword
	#define CHK_usermgrchangemypassword  TRUE
	#define EXP_usermgrchangemypassword  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrchangemypassword", (RTS_UINTPTR)usermgrchangemypassword, 1, 0x25575868, 0x03051100) 
#else /* DYNAMIC_LINK */
	#define USE_usermgrchangemypassword  PFUSERMGRCHANGEMYPASSWORD_IEC pfusermgrchangemypassword;
	#define EXT_usermgrchangemypassword  extern PFUSERMGRCHANGEMYPASSWORD_IEC pfusermgrchangemypassword;
	#define GET_usermgrchangemypassword(fl)  s_pfCMGetAPI2( "usermgrchangemypassword", (RTS_VOID_FCTPTR *)&pfusermgrchangemypassword, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x25575868, 0x03051100)
	#define CAL_usermgrchangemypassword  pfusermgrchangemypassword
	#define CHK_usermgrchangemypassword  (pfusermgrchangemypassword != NULL)
	#define EXP_usermgrchangemypassword   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrchangemypassword", (RTS_UINTPTR)usermgrchangemypassword, 1, 0x25575868, 0x03051100) 
#endif


/**
 * Gets user access rights on the specified object (authorization)!
 * :return: Error code
 * 	 + ERR_OK: If user has the requested rights on the object or if no user management is configured
 * 	 + ERR_PARAMETER: If user is not available or the object does not exist
 * 	 + ERR_FAILED: If something failed retrieving the access rights
 * 	 + ERR_NO_ACCESS_RIGHTS: Explicitly denied rights
 * 	 + ERR_INVALID_HANDLE: hUser is invalid or unknown
 */
typedef struct tagusermgrgetuseraccessrights_struct
{
	RTS_IEC_STRING *pszObject;			/* VAR_INPUT */	/* Full object name (see object tree) */
	RTS_IEC_HANDLE hUser;				/* VAR_INPUT */	/* Handle to the user */
	RTS_IEC_DWORD *pulRights;			/* VAR_INPUT */	/* Pointer to get admitted rights */
	RTS_IEC_DWORD *pulDeniedRights;		/* VAR_INPUT */	/* Pointer to get denied rights.

 .. note:: If the required right is denied _and_ admitted on the specified object, the denied right is more significant and so the access must be denied !! */
	RTS_IEC_RESULT UserMgrGetUserAccessRights;	/* VAR_OUTPUT */	
} usermgrgetuseraccessrights_struct;

void CDECL CDECL_EXT usermgrgetuseraccessrights(usermgrgetuseraccessrights_struct *p);
typedef void (CDECL CDECL_EXT* PFUSERMGRGETUSERACCESSRIGHTS_IEC) (usermgrgetuseraccessrights_struct *p);
#if defined(CMPUSERMGR_IMPLEMENTATION_NOTIMPLEMENTED) || defined(USERMGRGETUSERACCESSRIGHTS_NOTIMPLEMENTED)
	#define USE_usermgrgetuseraccessrights
	#define EXT_usermgrgetuseraccessrights
	#define GET_usermgrgetuseraccessrights(fl)  ERR_NOTIMPLEMENTED
	#define CAL_usermgrgetuseraccessrights(p0) 
	#define CHK_usermgrgetuseraccessrights  FALSE
	#define EXP_usermgrgetuseraccessrights  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_usermgrgetuseraccessrights
	#define EXT_usermgrgetuseraccessrights
	#define GET_usermgrgetuseraccessrights(fl)  CAL_CMGETAPI( "usermgrgetuseraccessrights" ) 
	#define CAL_usermgrgetuseraccessrights  usermgrgetuseraccessrights
	#define CHK_usermgrgetuseraccessrights  TRUE
	#define EXP_usermgrgetuseraccessrights  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrgetuseraccessrights", (RTS_UINTPTR)usermgrgetuseraccessrights, 1, 0xB30BF82F, 0x03051100) 
#elif defined(MIXED_LINK) && !defined(CMPUSERMGR_IMPLEMENTATION_EXTERNAL)
	#define USE_usermgrgetuseraccessrights
	#define EXT_usermgrgetuseraccessrights
	#define GET_usermgrgetuseraccessrights(fl)  CAL_CMGETAPI( "usermgrgetuseraccessrights" ) 
	#define CAL_usermgrgetuseraccessrights  usermgrgetuseraccessrights
	#define CHK_usermgrgetuseraccessrights  TRUE
	#define EXP_usermgrgetuseraccessrights  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrgetuseraccessrights", (RTS_UINTPTR)usermgrgetuseraccessrights, 1, 0xB30BF82F, 0x03051100) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserMgr_Implementationusermgrgetuseraccessrights
	#define EXT_CmpUserMgr_Implementationusermgrgetuseraccessrights
	#define GET_CmpUserMgr_Implementationusermgrgetuseraccessrights  ERR_OK
	#define CAL_CmpUserMgr_Implementationusermgrgetuseraccessrights  usermgrgetuseraccessrights
	#define CHK_CmpUserMgr_Implementationusermgrgetuseraccessrights  TRUE
	#define EXP_CmpUserMgr_Implementationusermgrgetuseraccessrights  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrgetuseraccessrights", (RTS_UINTPTR)usermgrgetuseraccessrights, 1, 0xB30BF82F, 0x03051100) 
#elif defined(CPLUSPLUS)
	#define USE_usermgrgetuseraccessrights
	#define EXT_usermgrgetuseraccessrights
	#define GET_usermgrgetuseraccessrights(fl)  CAL_CMGETAPI( "usermgrgetuseraccessrights" ) 
	#define CAL_usermgrgetuseraccessrights  usermgrgetuseraccessrights
	#define CHK_usermgrgetuseraccessrights  TRUE
	#define EXP_usermgrgetuseraccessrights  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrgetuseraccessrights", (RTS_UINTPTR)usermgrgetuseraccessrights, 1, 0xB30BF82F, 0x03051100) 
#else /* DYNAMIC_LINK */
	#define USE_usermgrgetuseraccessrights  PFUSERMGRGETUSERACCESSRIGHTS_IEC pfusermgrgetuseraccessrights;
	#define EXT_usermgrgetuseraccessrights  extern PFUSERMGRGETUSERACCESSRIGHTS_IEC pfusermgrgetuseraccessrights;
	#define GET_usermgrgetuseraccessrights(fl)  s_pfCMGetAPI2( "usermgrgetuseraccessrights", (RTS_VOID_FCTPTR *)&pfusermgrgetuseraccessrights, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xB30BF82F, 0x03051100)
	#define CAL_usermgrgetuseraccessrights  pfusermgrgetuseraccessrights
	#define CHK_usermgrgetuseraccessrights  (pfusermgrgetuseraccessrights != NULL)
	#define EXP_usermgrgetuseraccessrights   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrgetuseraccessrights", (RTS_UINTPTR)usermgrgetuseraccessrights, 1, 0xB30BF82F, 0x03051100) 
#endif


/**
 * Checks user access rights on the specified object (authorization)!
 * :return: Error code
 * 	 + ERR_OK: If user has the requested rights on the object or if no user management is configured
 * 	 + ERR_PARAMETER: If user is not available or the object does not exist
 * 	 + ERR_FAILED: If something failed retrieving the access rights
 * 	 + ERR_NO_ACCESS_RIGHTS: Explicitly denied rights
 * 	 + ERR_INVALID_HANDLE: hUser is invalid or unknown
 */
typedef struct tagusermgrhasuseraccessrights_struct
{
	RTS_IEC_STRING *pszObject;			/* VAR_INPUT */	/* Full object name (see object tree) */
	RTS_IEC_HANDLE hUser;				/* VAR_INPUT */	/* Handle to the user */
	RTS_IEC_DWORD ulRequestedRights;	/* VAR_INPUT */	/* Requested rights on that object */
	RTS_IEC_RESULT UserMgrHasUserAccessRights;	/* VAR_OUTPUT */	
} usermgrhasuseraccessrights_struct;

void CDECL CDECL_EXT usermgrhasuseraccessrights(usermgrhasuseraccessrights_struct *p);
typedef void (CDECL CDECL_EXT* PFUSERMGRHASUSERACCESSRIGHTS_IEC) (usermgrhasuseraccessrights_struct *p);
#if defined(CMPUSERMGR_IMPLEMENTATION_NOTIMPLEMENTED) || defined(USERMGRHASUSERACCESSRIGHTS_NOTIMPLEMENTED)
	#define USE_usermgrhasuseraccessrights
	#define EXT_usermgrhasuseraccessrights
	#define GET_usermgrhasuseraccessrights(fl)  ERR_NOTIMPLEMENTED
	#define CAL_usermgrhasuseraccessrights(p0) 
	#define CHK_usermgrhasuseraccessrights  FALSE
	#define EXP_usermgrhasuseraccessrights  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_usermgrhasuseraccessrights
	#define EXT_usermgrhasuseraccessrights
	#define GET_usermgrhasuseraccessrights(fl)  CAL_CMGETAPI( "usermgrhasuseraccessrights" ) 
	#define CAL_usermgrhasuseraccessrights  usermgrhasuseraccessrights
	#define CHK_usermgrhasuseraccessrights  TRUE
	#define EXP_usermgrhasuseraccessrights  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrhasuseraccessrights", (RTS_UINTPTR)usermgrhasuseraccessrights, 1, 0xB4009E6D, 0x03051100) 
#elif defined(MIXED_LINK) && !defined(CMPUSERMGR_IMPLEMENTATION_EXTERNAL)
	#define USE_usermgrhasuseraccessrights
	#define EXT_usermgrhasuseraccessrights
	#define GET_usermgrhasuseraccessrights(fl)  CAL_CMGETAPI( "usermgrhasuseraccessrights" ) 
	#define CAL_usermgrhasuseraccessrights  usermgrhasuseraccessrights
	#define CHK_usermgrhasuseraccessrights  TRUE
	#define EXP_usermgrhasuseraccessrights  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrhasuseraccessrights", (RTS_UINTPTR)usermgrhasuseraccessrights, 1, 0xB4009E6D, 0x03051100) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserMgr_Implementationusermgrhasuseraccessrights
	#define EXT_CmpUserMgr_Implementationusermgrhasuseraccessrights
	#define GET_CmpUserMgr_Implementationusermgrhasuseraccessrights  ERR_OK
	#define CAL_CmpUserMgr_Implementationusermgrhasuseraccessrights  usermgrhasuseraccessrights
	#define CHK_CmpUserMgr_Implementationusermgrhasuseraccessrights  TRUE
	#define EXP_CmpUserMgr_Implementationusermgrhasuseraccessrights  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrhasuseraccessrights", (RTS_UINTPTR)usermgrhasuseraccessrights, 1, 0xB4009E6D, 0x03051100) 
#elif defined(CPLUSPLUS)
	#define USE_usermgrhasuseraccessrights
	#define EXT_usermgrhasuseraccessrights
	#define GET_usermgrhasuseraccessrights(fl)  CAL_CMGETAPI( "usermgrhasuseraccessrights" ) 
	#define CAL_usermgrhasuseraccessrights  usermgrhasuseraccessrights
	#define CHK_usermgrhasuseraccessrights  TRUE
	#define EXP_usermgrhasuseraccessrights  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrhasuseraccessrights", (RTS_UINTPTR)usermgrhasuseraccessrights, 1, 0xB4009E6D, 0x03051100) 
#else /* DYNAMIC_LINK */
	#define USE_usermgrhasuseraccessrights  PFUSERMGRHASUSERACCESSRIGHTS_IEC pfusermgrhasuseraccessrights;
	#define EXT_usermgrhasuseraccessrights  extern PFUSERMGRHASUSERACCESSRIGHTS_IEC pfusermgrhasuseraccessrights;
	#define GET_usermgrhasuseraccessrights(fl)  s_pfCMGetAPI2( "usermgrhasuseraccessrights", (RTS_VOID_FCTPTR *)&pfusermgrhasuseraccessrights, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xB4009E6D, 0x03051100)
	#define CAL_usermgrhasuseraccessrights  pfusermgrhasuseraccessrights
	#define CHK_usermgrhasuseraccessrights  (pfusermgrhasuseraccessrights != NULL)
	#define EXP_usermgrhasuseraccessrights   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrhasuseraccessrights", (RTS_UINTPTR)usermgrhasuseraccessrights, 1, 0xB4009E6D, 0x03051100) 
#endif


/**
 * Checks if the user management is active.
 * :return: TRUE: The user management is activated or enforced. FALSE: The user management is not activated.
 */
typedef struct tagusermgrisactive_struct
{
	RTS_IEC_BOOL UserMgrIsActive;		/* VAR_OUTPUT */	
} usermgrisactive_struct;

void CDECL CDECL_EXT usermgrisactive(usermgrisactive_struct *p);
typedef void (CDECL CDECL_EXT* PFUSERMGRISACTIVE_IEC) (usermgrisactive_struct *p);
#if defined(CMPUSERMGR_IMPLEMENTATION_NOTIMPLEMENTED) || defined(USERMGRISACTIVE_NOTIMPLEMENTED)
	#define USE_usermgrisactive
	#define EXT_usermgrisactive
	#define GET_usermgrisactive(fl)  ERR_NOTIMPLEMENTED
	#define CAL_usermgrisactive(p0) 
	#define CHK_usermgrisactive  FALSE
	#define EXP_usermgrisactive  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_usermgrisactive
	#define EXT_usermgrisactive
	#define GET_usermgrisactive(fl)  CAL_CMGETAPI( "usermgrisactive" ) 
	#define CAL_usermgrisactive  usermgrisactive
	#define CHK_usermgrisactive  TRUE
	#define EXP_usermgrisactive  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrisactive", (RTS_UINTPTR)usermgrisactive, 1, 0x29D8803F, 0x03051100) 
#elif defined(MIXED_LINK) && !defined(CMPUSERMGR_IMPLEMENTATION_EXTERNAL)
	#define USE_usermgrisactive
	#define EXT_usermgrisactive
	#define GET_usermgrisactive(fl)  CAL_CMGETAPI( "usermgrisactive" ) 
	#define CAL_usermgrisactive  usermgrisactive
	#define CHK_usermgrisactive  TRUE
	#define EXP_usermgrisactive  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrisactive", (RTS_UINTPTR)usermgrisactive, 1, 0x29D8803F, 0x03051100) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserMgr_Implementationusermgrisactive
	#define EXT_CmpUserMgr_Implementationusermgrisactive
	#define GET_CmpUserMgr_Implementationusermgrisactive  ERR_OK
	#define CAL_CmpUserMgr_Implementationusermgrisactive  usermgrisactive
	#define CHK_CmpUserMgr_Implementationusermgrisactive  TRUE
	#define EXP_CmpUserMgr_Implementationusermgrisactive  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrisactive", (RTS_UINTPTR)usermgrisactive, 1, 0x29D8803F, 0x03051100) 
#elif defined(CPLUSPLUS)
	#define USE_usermgrisactive
	#define EXT_usermgrisactive
	#define GET_usermgrisactive(fl)  CAL_CMGETAPI( "usermgrisactive" ) 
	#define CAL_usermgrisactive  usermgrisactive
	#define CHK_usermgrisactive  TRUE
	#define EXP_usermgrisactive  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrisactive", (RTS_UINTPTR)usermgrisactive, 1, 0x29D8803F, 0x03051100) 
#else /* DYNAMIC_LINK */
	#define USE_usermgrisactive  PFUSERMGRISACTIVE_IEC pfusermgrisactive;
	#define EXT_usermgrisactive  extern PFUSERMGRISACTIVE_IEC pfusermgrisactive;
	#define GET_usermgrisactive(fl)  s_pfCMGetAPI2( "usermgrisactive", (RTS_VOID_FCTPTR *)&pfusermgrisactive, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x29D8803F, 0x03051100)
	#define CAL_usermgrisactive  pfusermgrisactive
	#define CHK_usermgrisactive  (pfusermgrisactive != NULL)
	#define EXP_usermgrisactive   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrisactive", (RTS_UINTPTR)usermgrisactive, 1, 0x29D8803F, 0x03051100) 
#endif


/**
 * Logs user in to the runtime system requiring an active user management.
 * :return: Handle to the user or RTS_INVALID_HANDLE if not available
 */
typedef struct tagusermgrlogin_struct
{
	RTS_IEC_STRING *pszUser;			/* VAR_INPUT */	/* Name of the user, limited to 59 chars */
	RTS_IEC_STRING *pszPassword;		/* VAR_INPUT */	/* Password (plain text), limited to 59 chars */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to error code
 	 + ERR_OK: User/password combination is valid
 	 + ERR_ACTIVATE_USERMGMT: The login was successful. But the user management is enforced and not active. Activate the user management.
 	 + ERR_CHANGE_PASSWORD: The login was successful. But the user must change his password.
 	 + ERR_NO_USERMGMT: Login was not successful. The user management is not activated. Use empty user and password to login.
 	 + ERR_NO_ACCESS_RIGHTS: The login was not successful, because of another reason. */
	RTS_IEC_HANDLE UserMgrLogin;		/* VAR_OUTPUT */	
} usermgrlogin_struct;

void CDECL CDECL_EXT usermgrlogin(usermgrlogin_struct *p);
typedef void (CDECL CDECL_EXT* PFUSERMGRLOGIN_IEC) (usermgrlogin_struct *p);
#if defined(CMPUSERMGR_IMPLEMENTATION_NOTIMPLEMENTED) || defined(USERMGRLOGIN_NOTIMPLEMENTED)
	#define USE_usermgrlogin
	#define EXT_usermgrlogin
	#define GET_usermgrlogin(fl)  ERR_NOTIMPLEMENTED
	#define CAL_usermgrlogin(p0) 
	#define CHK_usermgrlogin  FALSE
	#define EXP_usermgrlogin  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_usermgrlogin
	#define EXT_usermgrlogin
	#define GET_usermgrlogin(fl)  CAL_CMGETAPI( "usermgrlogin" ) 
	#define CAL_usermgrlogin  usermgrlogin
	#define CHK_usermgrlogin  TRUE
	#define EXP_usermgrlogin  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrlogin", (RTS_UINTPTR)usermgrlogin, 1, 0xE7251EF7, 0x03051100) 
#elif defined(MIXED_LINK) && !defined(CMPUSERMGR_IMPLEMENTATION_EXTERNAL)
	#define USE_usermgrlogin
	#define EXT_usermgrlogin
	#define GET_usermgrlogin(fl)  CAL_CMGETAPI( "usermgrlogin" ) 
	#define CAL_usermgrlogin  usermgrlogin
	#define CHK_usermgrlogin  TRUE
	#define EXP_usermgrlogin  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrlogin", (RTS_UINTPTR)usermgrlogin, 1, 0xE7251EF7, 0x03051100) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserMgr_Implementationusermgrlogin
	#define EXT_CmpUserMgr_Implementationusermgrlogin
	#define GET_CmpUserMgr_Implementationusermgrlogin  ERR_OK
	#define CAL_CmpUserMgr_Implementationusermgrlogin  usermgrlogin
	#define CHK_CmpUserMgr_Implementationusermgrlogin  TRUE
	#define EXP_CmpUserMgr_Implementationusermgrlogin  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrlogin", (RTS_UINTPTR)usermgrlogin, 1, 0xE7251EF7, 0x03051100) 
#elif defined(CPLUSPLUS)
	#define USE_usermgrlogin
	#define EXT_usermgrlogin
	#define GET_usermgrlogin(fl)  CAL_CMGETAPI( "usermgrlogin" ) 
	#define CAL_usermgrlogin  usermgrlogin
	#define CHK_usermgrlogin  TRUE
	#define EXP_usermgrlogin  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrlogin", (RTS_UINTPTR)usermgrlogin, 1, 0xE7251EF7, 0x03051100) 
#else /* DYNAMIC_LINK */
	#define USE_usermgrlogin  PFUSERMGRLOGIN_IEC pfusermgrlogin;
	#define EXT_usermgrlogin  extern PFUSERMGRLOGIN_IEC pfusermgrlogin;
	#define GET_usermgrlogin(fl)  s_pfCMGetAPI2( "usermgrlogin", (RTS_VOID_FCTPTR *)&pfusermgrlogin, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xE7251EF7, 0x03051100)
	#define CAL_usermgrlogin  pfusermgrlogin
	#define CHK_usermgrlogin  (pfusermgrlogin != NULL)
	#define EXP_usermgrlogin   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrlogin", (RTS_UINTPTR)usermgrlogin, 1, 0xE7251EF7, 0x03051100) 
#endif


/**
 * Logout specified by the user
 * :return: Error code
 * 	 + ERR_OK: User is available and logout succeeded
 * 	 + ERR_PARAMETER: If user is not available
 * 	 + ERR_INVALID_HANDLE: hUser is invalid or unknown
 */
typedef struct tagusermgrlogout_struct
{
	RTS_IEC_HANDLE hUser;				/* VAR_INPUT */	/* Handle to the user */
	RTS_IEC_RESULT UserMgrLogout;		/* VAR_OUTPUT */	
} usermgrlogout_struct;

void CDECL CDECL_EXT usermgrlogout(usermgrlogout_struct *p);
typedef void (CDECL CDECL_EXT* PFUSERMGRLOGOUT_IEC) (usermgrlogout_struct *p);
#if defined(CMPUSERMGR_IMPLEMENTATION_NOTIMPLEMENTED) || defined(USERMGRLOGOUT_NOTIMPLEMENTED)
	#define USE_usermgrlogout
	#define EXT_usermgrlogout
	#define GET_usermgrlogout(fl)  ERR_NOTIMPLEMENTED
	#define CAL_usermgrlogout(p0) 
	#define CHK_usermgrlogout  FALSE
	#define EXP_usermgrlogout  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_usermgrlogout
	#define EXT_usermgrlogout
	#define GET_usermgrlogout(fl)  CAL_CMGETAPI( "usermgrlogout" ) 
	#define CAL_usermgrlogout  usermgrlogout
	#define CHK_usermgrlogout  TRUE
	#define EXP_usermgrlogout  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrlogout", (RTS_UINTPTR)usermgrlogout, 1, 0xC9A61E57, 0x03051100) 
#elif defined(MIXED_LINK) && !defined(CMPUSERMGR_IMPLEMENTATION_EXTERNAL)
	#define USE_usermgrlogout
	#define EXT_usermgrlogout
	#define GET_usermgrlogout(fl)  CAL_CMGETAPI( "usermgrlogout" ) 
	#define CAL_usermgrlogout  usermgrlogout
	#define CHK_usermgrlogout  TRUE
	#define EXP_usermgrlogout  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrlogout", (RTS_UINTPTR)usermgrlogout, 1, 0xC9A61E57, 0x03051100) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserMgr_Implementationusermgrlogout
	#define EXT_CmpUserMgr_Implementationusermgrlogout
	#define GET_CmpUserMgr_Implementationusermgrlogout  ERR_OK
	#define CAL_CmpUserMgr_Implementationusermgrlogout  usermgrlogout
	#define CHK_CmpUserMgr_Implementationusermgrlogout  TRUE
	#define EXP_CmpUserMgr_Implementationusermgrlogout  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrlogout", (RTS_UINTPTR)usermgrlogout, 1, 0xC9A61E57, 0x03051100) 
#elif defined(CPLUSPLUS)
	#define USE_usermgrlogout
	#define EXT_usermgrlogout
	#define GET_usermgrlogout(fl)  CAL_CMGETAPI( "usermgrlogout" ) 
	#define CAL_usermgrlogout  usermgrlogout
	#define CHK_usermgrlogout  TRUE
	#define EXP_usermgrlogout  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrlogout", (RTS_UINTPTR)usermgrlogout, 1, 0xC9A61E57, 0x03051100) 
#else /* DYNAMIC_LINK */
	#define USE_usermgrlogout  PFUSERMGRLOGOUT_IEC pfusermgrlogout;
	#define EXT_usermgrlogout  extern PFUSERMGRLOGOUT_IEC pfusermgrlogout;
	#define GET_usermgrlogout(fl)  s_pfCMGetAPI2( "usermgrlogout", (RTS_VOID_FCTPTR *)&pfusermgrlogout, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xC9A61E57, 0x03051100)
	#define CAL_usermgrlogout  pfusermgrlogout
	#define CHK_usermgrlogout  (pfusermgrlogout != NULL)
	#define EXP_usermgrlogout   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrlogout", (RTS_UINTPTR)usermgrlogout, 1, 0xC9A61E57, 0x03051100) 
#endif


/**
 * Adds a new object to the user management, so the access rights can be configured on that object.
 *
 * .. note:: The name of the object must include the full name-space with "Device" as the root node, e.g. "Device.MyObject" or if it's a file system object with "/" as the root node.
 * :return: Handle to the object or RTS_INVALID_HANDLE if it could not be added
 */
typedef struct tagusermgrobjectadd_struct
{
	RTS_IEC_STRING *pszObject;			/* VAR_INPUT */	/* Full object name (see object tree) */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to error code
 	 + ERR_OK: Object could be added
 	 + ERR_PARAMETER: Object invalid = NULL or empty
 	 + ERR_NOTINITIALIZED: The user management is not initialized or it is not loaded yet
 	 + ERR_NOMEMORY: If memory could not be allocated to store this object */
	RTS_IEC_HANDLE UserMgrObjectAdd;	/* VAR_OUTPUT */	
} usermgrobjectadd_struct;

void CDECL CDECL_EXT usermgrobjectadd(usermgrobjectadd_struct *p);
typedef void (CDECL CDECL_EXT* PFUSERMGROBJECTADD_IEC) (usermgrobjectadd_struct *p);
#if defined(CMPUSERMGR_IMPLEMENTATION_NOTIMPLEMENTED) || defined(USERMGROBJECTADD_NOTIMPLEMENTED)
	#define USE_usermgrobjectadd
	#define EXT_usermgrobjectadd
	#define GET_usermgrobjectadd(fl)  ERR_NOTIMPLEMENTED
	#define CAL_usermgrobjectadd(p0) 
	#define CHK_usermgrobjectadd  FALSE
	#define EXP_usermgrobjectadd  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_usermgrobjectadd
	#define EXT_usermgrobjectadd
	#define GET_usermgrobjectadd(fl)  CAL_CMGETAPI( "usermgrobjectadd" ) 
	#define CAL_usermgrobjectadd  usermgrobjectadd
	#define CHK_usermgrobjectadd  TRUE
	#define EXP_usermgrobjectadd  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrobjectadd", (RTS_UINTPTR)usermgrobjectadd, 1, 0xDF2F6AEC, 0x03051100) 
#elif defined(MIXED_LINK) && !defined(CMPUSERMGR_IMPLEMENTATION_EXTERNAL)
	#define USE_usermgrobjectadd
	#define EXT_usermgrobjectadd
	#define GET_usermgrobjectadd(fl)  CAL_CMGETAPI( "usermgrobjectadd" ) 
	#define CAL_usermgrobjectadd  usermgrobjectadd
	#define CHK_usermgrobjectadd  TRUE
	#define EXP_usermgrobjectadd  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrobjectadd", (RTS_UINTPTR)usermgrobjectadd, 1, 0xDF2F6AEC, 0x03051100) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserMgr_Implementationusermgrobjectadd
	#define EXT_CmpUserMgr_Implementationusermgrobjectadd
	#define GET_CmpUserMgr_Implementationusermgrobjectadd  ERR_OK
	#define CAL_CmpUserMgr_Implementationusermgrobjectadd  usermgrobjectadd
	#define CHK_CmpUserMgr_Implementationusermgrobjectadd  TRUE
	#define EXP_CmpUserMgr_Implementationusermgrobjectadd  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrobjectadd", (RTS_UINTPTR)usermgrobjectadd, 1, 0xDF2F6AEC, 0x03051100) 
#elif defined(CPLUSPLUS)
	#define USE_usermgrobjectadd
	#define EXT_usermgrobjectadd
	#define GET_usermgrobjectadd(fl)  CAL_CMGETAPI( "usermgrobjectadd" ) 
	#define CAL_usermgrobjectadd  usermgrobjectadd
	#define CHK_usermgrobjectadd  TRUE
	#define EXP_usermgrobjectadd  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrobjectadd", (RTS_UINTPTR)usermgrobjectadd, 1, 0xDF2F6AEC, 0x03051100) 
#else /* DYNAMIC_LINK */
	#define USE_usermgrobjectadd  PFUSERMGROBJECTADD_IEC pfusermgrobjectadd;
	#define EXT_usermgrobjectadd  extern PFUSERMGROBJECTADD_IEC pfusermgrobjectadd;
	#define GET_usermgrobjectadd(fl)  s_pfCMGetAPI2( "usermgrobjectadd", (RTS_VOID_FCTPTR *)&pfusermgrobjectadd, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xDF2F6AEC, 0x03051100)
	#define CAL_usermgrobjectadd  pfusermgrobjectadd
	#define CHK_usermgrobjectadd  (pfusermgrobjectadd != NULL)
	#define EXP_usermgrobjectadd   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrobjectadd", (RTS_UINTPTR)usermgrobjectadd, 1, 0xDF2F6AEC, 0x03051100) 
#endif


/**
 * Removes an object from the user management and all its children
 * :return: Error code
 * 	 + ERR_OK: Object could be removed
 * 	 + ERR_PARAMETER: Invalid object handle
 */
typedef struct tagusermgrobjectremove_struct
{
	RTS_IEC_HANDLE hObject;				/* VAR_INPUT */	/* Handle to object */
	RTS_IEC_RESULT UserMgrObjectRemove;	/* VAR_OUTPUT */	
} usermgrobjectremove_struct;

void CDECL CDECL_EXT usermgrobjectremove(usermgrobjectremove_struct *p);
typedef void (CDECL CDECL_EXT* PFUSERMGROBJECTREMOVE_IEC) (usermgrobjectremove_struct *p);
#if defined(CMPUSERMGR_IMPLEMENTATION_NOTIMPLEMENTED) || defined(USERMGROBJECTREMOVE_NOTIMPLEMENTED)
	#define USE_usermgrobjectremove
	#define EXT_usermgrobjectremove
	#define GET_usermgrobjectremove(fl)  ERR_NOTIMPLEMENTED
	#define CAL_usermgrobjectremove(p0) 
	#define CHK_usermgrobjectremove  FALSE
	#define EXP_usermgrobjectremove  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_usermgrobjectremove
	#define EXT_usermgrobjectremove
	#define GET_usermgrobjectremove(fl)  CAL_CMGETAPI( "usermgrobjectremove" ) 
	#define CAL_usermgrobjectremove  usermgrobjectremove
	#define CHK_usermgrobjectremove  TRUE
	#define EXP_usermgrobjectremove  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrobjectremove", (RTS_UINTPTR)usermgrobjectremove, 1, 0xAFB36783, 0x03051100) 
#elif defined(MIXED_LINK) && !defined(CMPUSERMGR_IMPLEMENTATION_EXTERNAL)
	#define USE_usermgrobjectremove
	#define EXT_usermgrobjectremove
	#define GET_usermgrobjectremove(fl)  CAL_CMGETAPI( "usermgrobjectremove" ) 
	#define CAL_usermgrobjectremove  usermgrobjectremove
	#define CHK_usermgrobjectremove  TRUE
	#define EXP_usermgrobjectremove  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrobjectremove", (RTS_UINTPTR)usermgrobjectremove, 1, 0xAFB36783, 0x03051100) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserMgr_Implementationusermgrobjectremove
	#define EXT_CmpUserMgr_Implementationusermgrobjectremove
	#define GET_CmpUserMgr_Implementationusermgrobjectremove  ERR_OK
	#define CAL_CmpUserMgr_Implementationusermgrobjectremove  usermgrobjectremove
	#define CHK_CmpUserMgr_Implementationusermgrobjectremove  TRUE
	#define EXP_CmpUserMgr_Implementationusermgrobjectremove  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrobjectremove", (RTS_UINTPTR)usermgrobjectremove, 1, 0xAFB36783, 0x03051100) 
#elif defined(CPLUSPLUS)
	#define USE_usermgrobjectremove
	#define EXT_usermgrobjectremove
	#define GET_usermgrobjectremove(fl)  CAL_CMGETAPI( "usermgrobjectremove" ) 
	#define CAL_usermgrobjectremove  usermgrobjectremove
	#define CHK_usermgrobjectremove  TRUE
	#define EXP_usermgrobjectremove  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrobjectremove", (RTS_UINTPTR)usermgrobjectremove, 1, 0xAFB36783, 0x03051100) 
#else /* DYNAMIC_LINK */
	#define USE_usermgrobjectremove  PFUSERMGROBJECTREMOVE_IEC pfusermgrobjectremove;
	#define EXT_usermgrobjectremove  extern PFUSERMGROBJECTREMOVE_IEC pfusermgrobjectremove;
	#define GET_usermgrobjectremove(fl)  s_pfCMGetAPI2( "usermgrobjectremove", (RTS_VOID_FCTPTR *)&pfusermgrobjectremove, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xAFB36783, 0x03051100)
	#define CAL_usermgrobjectremove  pfusermgrobjectremove
	#define CHK_usermgrobjectremove  (pfusermgrobjectremove != NULL)
	#define EXP_usermgrobjectremove   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrobjectremove", (RTS_UINTPTR)usermgrobjectremove, 1, 0xAFB36783, 0x03051100) 
#endif


/**
 * | Sets the used access rights for the object specified by handle.
 * | The rights are additionally stored in an internal list. In case USERDB_RIGHT_NONE is passed for ulUsedRights the previously stored rights are retrieved for this object.
 * :return: Error code
 * 	 + ERR_OK: Rights are successfully set
 * 	 + ERR_PARAMETER: Invalid object handle
 * 	 + ERR_NO_OBJECT: Object was not found for rights retrieval
 */
typedef struct tagusermgrobjectsetusedrights_struct
{
	RTS_IEC_HANDLE hObject;				/* VAR_INPUT */	/* Handle to the object */
	RTS_IEC_DWORD ulUsedRights;			/* VAR_INPUT */	/* Used access rights or USERDB_RIGHT_NONE for retrieval */
	RTS_IEC_RESULT UserMgrObjectSetUsedRights;	/* VAR_OUTPUT */	
} usermgrobjectsetusedrights_struct;

void CDECL CDECL_EXT usermgrobjectsetusedrights(usermgrobjectsetusedrights_struct *p);
typedef void (CDECL CDECL_EXT* PFUSERMGROBJECTSETUSEDRIGHTS_IEC) (usermgrobjectsetusedrights_struct *p);
#if defined(CMPUSERMGR_IMPLEMENTATION_NOTIMPLEMENTED) || defined(USERMGROBJECTSETUSEDRIGHTS_NOTIMPLEMENTED)
	#define USE_usermgrobjectsetusedrights
	#define EXT_usermgrobjectsetusedrights
	#define GET_usermgrobjectsetusedrights(fl)  ERR_NOTIMPLEMENTED
	#define CAL_usermgrobjectsetusedrights(p0) 
	#define CHK_usermgrobjectsetusedrights  FALSE
	#define EXP_usermgrobjectsetusedrights  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_usermgrobjectsetusedrights
	#define EXT_usermgrobjectsetusedrights
	#define GET_usermgrobjectsetusedrights(fl)  CAL_CMGETAPI( "usermgrobjectsetusedrights" ) 
	#define CAL_usermgrobjectsetusedrights  usermgrobjectsetusedrights
	#define CHK_usermgrobjectsetusedrights  TRUE
	#define EXP_usermgrobjectsetusedrights  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrobjectsetusedrights", (RTS_UINTPTR)usermgrobjectsetusedrights, 1, 0xAA821FF5, 0x03051100) 
#elif defined(MIXED_LINK) && !defined(CMPUSERMGR_IMPLEMENTATION_EXTERNAL)
	#define USE_usermgrobjectsetusedrights
	#define EXT_usermgrobjectsetusedrights
	#define GET_usermgrobjectsetusedrights(fl)  CAL_CMGETAPI( "usermgrobjectsetusedrights" ) 
	#define CAL_usermgrobjectsetusedrights  usermgrobjectsetusedrights
	#define CHK_usermgrobjectsetusedrights  TRUE
	#define EXP_usermgrobjectsetusedrights  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrobjectsetusedrights", (RTS_UINTPTR)usermgrobjectsetusedrights, 1, 0xAA821FF5, 0x03051100) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserMgr_Implementationusermgrobjectsetusedrights
	#define EXT_CmpUserMgr_Implementationusermgrobjectsetusedrights
	#define GET_CmpUserMgr_Implementationusermgrobjectsetusedrights  ERR_OK
	#define CAL_CmpUserMgr_Implementationusermgrobjectsetusedrights  usermgrobjectsetusedrights
	#define CHK_CmpUserMgr_Implementationusermgrobjectsetusedrights  TRUE
	#define EXP_CmpUserMgr_Implementationusermgrobjectsetusedrights  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrobjectsetusedrights", (RTS_UINTPTR)usermgrobjectsetusedrights, 1, 0xAA821FF5, 0x03051100) 
#elif defined(CPLUSPLUS)
	#define USE_usermgrobjectsetusedrights
	#define EXT_usermgrobjectsetusedrights
	#define GET_usermgrobjectsetusedrights(fl)  CAL_CMGETAPI( "usermgrobjectsetusedrights" ) 
	#define CAL_usermgrobjectsetusedrights  usermgrobjectsetusedrights
	#define CHK_usermgrobjectsetusedrights  TRUE
	#define EXP_usermgrobjectsetusedrights  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrobjectsetusedrights", (RTS_UINTPTR)usermgrobjectsetusedrights, 1, 0xAA821FF5, 0x03051100) 
#else /* DYNAMIC_LINK */
	#define USE_usermgrobjectsetusedrights  PFUSERMGROBJECTSETUSEDRIGHTS_IEC pfusermgrobjectsetusedrights;
	#define EXT_usermgrobjectsetusedrights  extern PFUSERMGROBJECTSETUSEDRIGHTS_IEC pfusermgrobjectsetusedrights;
	#define GET_usermgrobjectsetusedrights(fl)  s_pfCMGetAPI2( "usermgrobjectsetusedrights", (RTS_VOID_FCTPTR *)&pfusermgrobjectsetusedrights, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xAA821FF5, 0x03051100)
	#define CAL_usermgrobjectsetusedrights  pfusermgrobjectsetusedrights
	#define CHK_usermgrobjectsetusedrights  (pfusermgrobjectsetusedrights != NULL)
	#define EXP_usermgrobjectsetusedrights   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrobjectsetusedrights", (RTS_UINTPTR)usermgrobjectsetusedrights, 1, 0xAA821FF5, 0x03051100) 
#endif


/**
 * Re-logs user in to the runtime system using an active user management. The user name must match to the user name used for the initial login of the user.
 * :return: Error code
 * 	 + ERR_OK: User/password combination is valid
 * 	 + ERR_NOTINITIALIZED: The user management is not initialized or it is not loaded yet
 * 	 + ERR_RELOGIN: hUser known, but not logged in
 * 	 + ERR_FAILED: Password is wrong.
 * 	 + ERR_USER_MISMATCH: User name does not match
 * 	 + ERR_INVALID_HANDLE: hUser is invalid or unknown
 */
typedef struct tagusermgrrelogin_struct
{
	RTS_IEC_HANDLE hUser;				/* VAR_INPUT */	/* Handle to the user */
	RTS_IEC_STRING *pszUser;			/* VAR_INPUT */	/* Name of the user, limited to 59 chars */
	RTS_IEC_STRING *pszPassword;		/* VAR_INPUT */	/* Password (plain text), limited to 59 chars */
	RTS_IEC_RESULT UserMgrRelogin;		/* VAR_OUTPUT */	
} usermgrrelogin_struct;

void CDECL CDECL_EXT usermgrrelogin(usermgrrelogin_struct *p);
typedef void (CDECL CDECL_EXT* PFUSERMGRRELOGIN_IEC) (usermgrrelogin_struct *p);
#if defined(CMPUSERMGR_IMPLEMENTATION_NOTIMPLEMENTED) || defined(USERMGRRELOGIN_NOTIMPLEMENTED)
	#define USE_usermgrrelogin
	#define EXT_usermgrrelogin
	#define GET_usermgrrelogin(fl)  ERR_NOTIMPLEMENTED
	#define CAL_usermgrrelogin(p0) 
	#define CHK_usermgrrelogin  FALSE
	#define EXP_usermgrrelogin  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_usermgrrelogin
	#define EXT_usermgrrelogin
	#define GET_usermgrrelogin(fl)  CAL_CMGETAPI( "usermgrrelogin" ) 
	#define CAL_usermgrrelogin  usermgrrelogin
	#define CHK_usermgrrelogin  TRUE
	#define EXP_usermgrrelogin  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrrelogin", (RTS_UINTPTR)usermgrrelogin, 1, 0x69692107, 0x03051100) 
#elif defined(MIXED_LINK) && !defined(CMPUSERMGR_IMPLEMENTATION_EXTERNAL)
	#define USE_usermgrrelogin
	#define EXT_usermgrrelogin
	#define GET_usermgrrelogin(fl)  CAL_CMGETAPI( "usermgrrelogin" ) 
	#define CAL_usermgrrelogin  usermgrrelogin
	#define CHK_usermgrrelogin  TRUE
	#define EXP_usermgrrelogin  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrrelogin", (RTS_UINTPTR)usermgrrelogin, 1, 0x69692107, 0x03051100) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserMgr_Implementationusermgrrelogin
	#define EXT_CmpUserMgr_Implementationusermgrrelogin
	#define GET_CmpUserMgr_Implementationusermgrrelogin  ERR_OK
	#define CAL_CmpUserMgr_Implementationusermgrrelogin  usermgrrelogin
	#define CHK_CmpUserMgr_Implementationusermgrrelogin  TRUE
	#define EXP_CmpUserMgr_Implementationusermgrrelogin  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrrelogin", (RTS_UINTPTR)usermgrrelogin, 1, 0x69692107, 0x03051100) 
#elif defined(CPLUSPLUS)
	#define USE_usermgrrelogin
	#define EXT_usermgrrelogin
	#define GET_usermgrrelogin(fl)  CAL_CMGETAPI( "usermgrrelogin" ) 
	#define CAL_usermgrrelogin  usermgrrelogin
	#define CHK_usermgrrelogin  TRUE
	#define EXP_usermgrrelogin  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrrelogin", (RTS_UINTPTR)usermgrrelogin, 1, 0x69692107, 0x03051100) 
#else /* DYNAMIC_LINK */
	#define USE_usermgrrelogin  PFUSERMGRRELOGIN_IEC pfusermgrrelogin;
	#define EXT_usermgrrelogin  extern PFUSERMGRRELOGIN_IEC pfusermgrrelogin;
	#define GET_usermgrrelogin(fl)  s_pfCMGetAPI2( "usermgrrelogin", (RTS_VOID_FCTPTR *)&pfusermgrrelogin, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x69692107, 0x03051100)
	#define CAL_usermgrrelogin  pfusermgrrelogin
	#define CHK_usermgrrelogin  (pfusermgrrelogin != NULL)
	#define EXP_usermgrrelogin   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"usermgrrelogin", (RTS_UINTPTR)usermgrrelogin, 1, 0x69692107, 0x03051100) 
#endif


#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/




typedef struct
{
	IBase_C *pBase;
} ICmpUserMgr_Implementation_C;

#ifdef CPLUSPLUS
class ICmpUserMgr_Implementation : public IBase
{
	public:
};
	#ifndef ITF_CmpUserMgr_Implementation
		#define ITF_CmpUserMgr_Implementation static ICmpUserMgr_Implementation *pICmpUserMgr_Implementation = NULL;
	#endif
	#define EXTITF_CmpUserMgr_Implementation
#else	/*CPLUSPLUS*/
	typedef ICmpUserMgr_Implementation_C		ICmpUserMgr_Implementation;
	#ifndef ITF_CmpUserMgr_Implementation
		#define ITF_CmpUserMgr_Implementation
	#endif
	#define EXTITF_CmpUserMgr_Implementation
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_CMPUSERMGR_IMPLEMENTATIONITF_H_*/
