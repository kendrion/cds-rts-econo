 /**
 * <interfacename>CmpX509Cert_Implementation</interfacename>
 * <description></description>
 *
 * <copyright></copyright>
 */


	
	
#ifndef _CMPX509CERT_IMPLEMENTATIONITF_H_
#define _CMPX509CERT_IMPLEMENTATIONITF_H_

#include "CmpStd.h"

 

 



#include "CmpX509CertItf.h"

/** EXTERN LIB SECTION BEGIN **/
/*  Comments are ignored for m4 compiler so restructured text can be used.  */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Clear an OID
 * :return: Result of the operation
 */
typedef struct tagrtsoidclear_struct
{
	RtsOID *oid;						/* VAR_INPUT */	
	RTS_IEC_RESULT RtsOIDClear;			/* VAR_OUTPUT */	
} rtsoidclear_struct;

void CDECL CDECL_EXT rtsoidclear(rtsoidclear_struct *p);
typedef void (CDECL CDECL_EXT* PFRTSOIDCLEAR_IEC) (rtsoidclear_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(RTSOIDCLEAR_NOTIMPLEMENTED)
	#define USE_rtsoidclear
	#define EXT_rtsoidclear
	#define GET_rtsoidclear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_rtsoidclear(p0) 
	#define CHK_rtsoidclear  FALSE
	#define EXP_rtsoidclear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_rtsoidclear
	#define EXT_rtsoidclear
	#define GET_rtsoidclear(fl)  CAL_CMGETAPI( "rtsoidclear" ) 
	#define CAL_rtsoidclear  rtsoidclear
	#define CHK_rtsoidclear  TRUE
	#define EXP_rtsoidclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"rtsoidclear", (RTS_UINTPTR)rtsoidclear, 1, 0xB53A1CAF, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_rtsoidclear
	#define EXT_rtsoidclear
	#define GET_rtsoidclear(fl)  CAL_CMGETAPI( "rtsoidclear" ) 
	#define CAL_rtsoidclear  rtsoidclear
	#define CHK_rtsoidclear  TRUE
	#define EXP_rtsoidclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"rtsoidclear", (RTS_UINTPTR)rtsoidclear, 1, 0xB53A1CAF, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationrtsoidclear
	#define EXT_CmpX509Cert_Implementationrtsoidclear
	#define GET_CmpX509Cert_Implementationrtsoidclear  ERR_OK
	#define CAL_CmpX509Cert_Implementationrtsoidclear  rtsoidclear
	#define CHK_CmpX509Cert_Implementationrtsoidclear  TRUE
	#define EXP_CmpX509Cert_Implementationrtsoidclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"rtsoidclear", (RTS_UINTPTR)rtsoidclear, 1, 0xB53A1CAF, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_rtsoidclear
	#define EXT_rtsoidclear
	#define GET_rtsoidclear(fl)  CAL_CMGETAPI( "rtsoidclear" ) 
	#define CAL_rtsoidclear  rtsoidclear
	#define CHK_rtsoidclear  TRUE
	#define EXP_rtsoidclear  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"rtsoidclear", (RTS_UINTPTR)rtsoidclear, 1, 0xB53A1CAF, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_rtsoidclear  PFRTSOIDCLEAR_IEC pfrtsoidclear;
	#define EXT_rtsoidclear  extern PFRTSOIDCLEAR_IEC pfrtsoidclear;
	#define GET_rtsoidclear(fl)  s_pfCMGetAPI2( "rtsoidclear", (RTS_VOID_FCTPTR *)&pfrtsoidclear, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xB53A1CAF, 0x03050F00)
	#define CAL_rtsoidclear  pfrtsoidclear
	#define CHK_rtsoidclear  (pfrtsoidclear != NULL)
	#define EXP_rtsoidclear   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"rtsoidclear", (RTS_UINTPTR)rtsoidclear, 1, 0xB53A1CAF, 0x03050F00) 
#endif


/**
 * Create an RtsOID based on a given ID.
 * :return: Result of the operation.
 */
typedef struct tagrtsoidcreate_struct
{
	RTS_IEC_STRING *id;					/* VAR_INPUT */	/* OID as string in dottet format. E.g. (1.2.3.4.5.6.7.8.9.0) */
	RtsOID *oid;						/* VAR_INPUT */	/* Pointer to an OID to fill up. */
	RTS_IEC_RESULT RtsOIDCreate;		/* VAR_OUTPUT */	
} rtsoidcreate_struct;

void CDECL CDECL_EXT rtsoidcreate(rtsoidcreate_struct *p);
typedef void (CDECL CDECL_EXT* PFRTSOIDCREATE_IEC) (rtsoidcreate_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(RTSOIDCREATE_NOTIMPLEMENTED)
	#define USE_rtsoidcreate
	#define EXT_rtsoidcreate
	#define GET_rtsoidcreate(fl)  ERR_NOTIMPLEMENTED
	#define CAL_rtsoidcreate(p0) 
	#define CHK_rtsoidcreate  FALSE
	#define EXP_rtsoidcreate  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_rtsoidcreate
	#define EXT_rtsoidcreate
	#define GET_rtsoidcreate(fl)  CAL_CMGETAPI( "rtsoidcreate" ) 
	#define CAL_rtsoidcreate  rtsoidcreate
	#define CHK_rtsoidcreate  TRUE
	#define EXP_rtsoidcreate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"rtsoidcreate", (RTS_UINTPTR)rtsoidcreate, 1, 0xE11A70BD, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_rtsoidcreate
	#define EXT_rtsoidcreate
	#define GET_rtsoidcreate(fl)  CAL_CMGETAPI( "rtsoidcreate" ) 
	#define CAL_rtsoidcreate  rtsoidcreate
	#define CHK_rtsoidcreate  TRUE
	#define EXP_rtsoidcreate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"rtsoidcreate", (RTS_UINTPTR)rtsoidcreate, 1, 0xE11A70BD, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationrtsoidcreate
	#define EXT_CmpX509Cert_Implementationrtsoidcreate
	#define GET_CmpX509Cert_Implementationrtsoidcreate  ERR_OK
	#define CAL_CmpX509Cert_Implementationrtsoidcreate  rtsoidcreate
	#define CHK_CmpX509Cert_Implementationrtsoidcreate  TRUE
	#define EXP_CmpX509Cert_Implementationrtsoidcreate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"rtsoidcreate", (RTS_UINTPTR)rtsoidcreate, 1, 0xE11A70BD, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_rtsoidcreate
	#define EXT_rtsoidcreate
	#define GET_rtsoidcreate(fl)  CAL_CMGETAPI( "rtsoidcreate" ) 
	#define CAL_rtsoidcreate  rtsoidcreate
	#define CHK_rtsoidcreate  TRUE
	#define EXP_rtsoidcreate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"rtsoidcreate", (RTS_UINTPTR)rtsoidcreate, 1, 0xE11A70BD, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_rtsoidcreate  PFRTSOIDCREATE_IEC pfrtsoidcreate;
	#define EXT_rtsoidcreate  extern PFRTSOIDCREATE_IEC pfrtsoidcreate;
	#define GET_rtsoidcreate(fl)  s_pfCMGetAPI2( "rtsoidcreate", (RTS_VOID_FCTPTR *)&pfrtsoidcreate, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xE11A70BD, 0x03050F00)
	#define CAL_rtsoidcreate  pfrtsoidcreate
	#define CHK_rtsoidcreate  (pfrtsoidcreate != NULL)
	#define EXP_rtsoidcreate   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"rtsoidcreate", (RTS_UINTPTR)rtsoidcreate, 1, 0xE11A70BD, 0x03050F00) 
#endif


/**
 * Get the ID of an OID in dottet notation.
 * :return: Result of the operation
 */
typedef struct tagrtsoidgetid_struct
{
	RtsOID *oid;						/* VAR_INPUT */	/* OID to print. */
	RtsByteString *pBuffer;				/* VAR_INPUT */	/* Buffer where to store the ID. */
	RTS_IEC_RESULT RtsOIDGetID;			/* VAR_OUTPUT */	
} rtsoidgetid_struct;

void CDECL CDECL_EXT rtsoidgetid(rtsoidgetid_struct *p);
typedef void (CDECL CDECL_EXT* PFRTSOIDGETID_IEC) (rtsoidgetid_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(RTSOIDGETID_NOTIMPLEMENTED)
	#define USE_rtsoidgetid
	#define EXT_rtsoidgetid
	#define GET_rtsoidgetid(fl)  ERR_NOTIMPLEMENTED
	#define CAL_rtsoidgetid(p0) 
	#define CHK_rtsoidgetid  FALSE
	#define EXP_rtsoidgetid  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_rtsoidgetid
	#define EXT_rtsoidgetid
	#define GET_rtsoidgetid(fl)  CAL_CMGETAPI( "rtsoidgetid" ) 
	#define CAL_rtsoidgetid  rtsoidgetid
	#define CHK_rtsoidgetid  TRUE
	#define EXP_rtsoidgetid  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"rtsoidgetid", (RTS_UINTPTR)rtsoidgetid, 1, 0xB69D55FF, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_rtsoidgetid
	#define EXT_rtsoidgetid
	#define GET_rtsoidgetid(fl)  CAL_CMGETAPI( "rtsoidgetid" ) 
	#define CAL_rtsoidgetid  rtsoidgetid
	#define CHK_rtsoidgetid  TRUE
	#define EXP_rtsoidgetid  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"rtsoidgetid", (RTS_UINTPTR)rtsoidgetid, 1, 0xB69D55FF, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationrtsoidgetid
	#define EXT_CmpX509Cert_Implementationrtsoidgetid
	#define GET_CmpX509Cert_Implementationrtsoidgetid  ERR_OK
	#define CAL_CmpX509Cert_Implementationrtsoidgetid  rtsoidgetid
	#define CHK_CmpX509Cert_Implementationrtsoidgetid  TRUE
	#define EXP_CmpX509Cert_Implementationrtsoidgetid  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"rtsoidgetid", (RTS_UINTPTR)rtsoidgetid, 1, 0xB69D55FF, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_rtsoidgetid
	#define EXT_rtsoidgetid
	#define GET_rtsoidgetid(fl)  CAL_CMGETAPI( "rtsoidgetid" ) 
	#define CAL_rtsoidgetid  rtsoidgetid
	#define CHK_rtsoidgetid  TRUE
	#define EXP_rtsoidgetid  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"rtsoidgetid", (RTS_UINTPTR)rtsoidgetid, 1, 0xB69D55FF, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_rtsoidgetid  PFRTSOIDGETID_IEC pfrtsoidgetid;
	#define EXT_rtsoidgetid  extern PFRTSOIDGETID_IEC pfrtsoidgetid;
	#define GET_rtsoidgetid(fl)  s_pfCMGetAPI2( "rtsoidgetid", (RTS_VOID_FCTPTR *)&pfrtsoidgetid, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xB69D55FF, 0x03050F00)
	#define CAL_rtsoidgetid  pfrtsoidgetid
	#define CHK_rtsoidgetid  (pfrtsoidgetid != NULL)
	#define EXP_rtsoidgetid   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"rtsoidgetid", (RTS_UINTPTR)rtsoidgetid, 1, 0xB69D55FF, 0x03050F00) 
#endif


/**
 * Get the given name of an OID. If the OID is unknown 
 * to the system the dottet notation will be returned.
 * :return: Result of the operation.
 */
typedef struct tagrtsoidgetname_struct
{
	RtsOID *oid;						/* VAR_INPUT */	
	RtsByteString *pBuffer;				/* VAR_INPUT */	
	RTS_IEC_RESULT RtsOIDGetName;		/* VAR_OUTPUT */	
} rtsoidgetname_struct;

void CDECL CDECL_EXT rtsoidgetname(rtsoidgetname_struct *p);
typedef void (CDECL CDECL_EXT* PFRTSOIDGETNAME_IEC) (rtsoidgetname_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(RTSOIDGETNAME_NOTIMPLEMENTED)
	#define USE_rtsoidgetname
	#define EXT_rtsoidgetname
	#define GET_rtsoidgetname(fl)  ERR_NOTIMPLEMENTED
	#define CAL_rtsoidgetname(p0) 
	#define CHK_rtsoidgetname  FALSE
	#define EXP_rtsoidgetname  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_rtsoidgetname
	#define EXT_rtsoidgetname
	#define GET_rtsoidgetname(fl)  CAL_CMGETAPI( "rtsoidgetname" ) 
	#define CAL_rtsoidgetname  rtsoidgetname
	#define CHK_rtsoidgetname  TRUE
	#define EXP_rtsoidgetname  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"rtsoidgetname", (RTS_UINTPTR)rtsoidgetname, 1, 0xBEA6E204, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_rtsoidgetname
	#define EXT_rtsoidgetname
	#define GET_rtsoidgetname(fl)  CAL_CMGETAPI( "rtsoidgetname" ) 
	#define CAL_rtsoidgetname  rtsoidgetname
	#define CHK_rtsoidgetname  TRUE
	#define EXP_rtsoidgetname  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"rtsoidgetname", (RTS_UINTPTR)rtsoidgetname, 1, 0xBEA6E204, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationrtsoidgetname
	#define EXT_CmpX509Cert_Implementationrtsoidgetname
	#define GET_CmpX509Cert_Implementationrtsoidgetname  ERR_OK
	#define CAL_CmpX509Cert_Implementationrtsoidgetname  rtsoidgetname
	#define CHK_CmpX509Cert_Implementationrtsoidgetname  TRUE
	#define EXP_CmpX509Cert_Implementationrtsoidgetname  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"rtsoidgetname", (RTS_UINTPTR)rtsoidgetname, 1, 0xBEA6E204, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_rtsoidgetname
	#define EXT_rtsoidgetname
	#define GET_rtsoidgetname(fl)  CAL_CMGETAPI( "rtsoidgetname" ) 
	#define CAL_rtsoidgetname  rtsoidgetname
	#define CHK_rtsoidgetname  TRUE
	#define EXP_rtsoidgetname  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"rtsoidgetname", (RTS_UINTPTR)rtsoidgetname, 1, 0xBEA6E204, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_rtsoidgetname  PFRTSOIDGETNAME_IEC pfrtsoidgetname;
	#define EXT_rtsoidgetname  extern PFRTSOIDGETNAME_IEC pfrtsoidgetname;
	#define GET_rtsoidgetname(fl)  s_pfCMGetAPI2( "rtsoidgetname", (RTS_VOID_FCTPTR *)&pfrtsoidgetname, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xBEA6E204, 0x03050F00)
	#define CAL_rtsoidgetname  pfrtsoidgetname
	#define CHK_rtsoidgetname  (pfrtsoidgetname != NULL)
	#define EXP_rtsoidgetname   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"rtsoidgetname", (RTS_UINTPTR)rtsoidgetname, 1, 0xBEA6E204, 0x03050F00) 
#endif


/**
 * Check if a certificate is bound to a specific host name. Both subject and subject alternative names are checked.
 * :return: True if the host name is part of the certificate.
 */
typedef struct tagx509certcheckhost_struct
{
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	
	RTS_IEC_STRING *pHost;				/* VAR_INPUT */	/* Handle of to certificate. */
	RTS_IEC_DWORD flags;				/* VAR_INPUT, Enum: RTSX509CERTCHECKFLAGS */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Flags how to check for the host name. Values of the enumeration can be combined. */
	RTS_IEC_BOOL X509CertCheckHost;		/* VAR_OUTPUT */	
} x509certcheckhost_struct;

void CDECL CDECL_EXT x509certcheckhost(x509certcheckhost_struct *p);
typedef void (CDECL CDECL_EXT* PFX509CERTCHECKHOST_IEC) (x509certcheckhost_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509CERTCHECKHOST_NOTIMPLEMENTED)
	#define USE_x509certcheckhost
	#define EXT_x509certcheckhost
	#define GET_x509certcheckhost(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509certcheckhost(p0) 
	#define CHK_x509certcheckhost  FALSE
	#define EXP_x509certcheckhost  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509certcheckhost
	#define EXT_x509certcheckhost
	#define GET_x509certcheckhost(fl)  CAL_CMGETAPI( "x509certcheckhost" ) 
	#define CAL_x509certcheckhost  x509certcheckhost
	#define CHK_x509certcheckhost  TRUE
	#define EXP_x509certcheckhost  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certcheckhost", (RTS_UINTPTR)x509certcheckhost, 1, 0x7EE75544, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509certcheckhost
	#define EXT_x509certcheckhost
	#define GET_x509certcheckhost(fl)  CAL_CMGETAPI( "x509certcheckhost" ) 
	#define CAL_x509certcheckhost  x509certcheckhost
	#define CHK_x509certcheckhost  TRUE
	#define EXP_x509certcheckhost  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certcheckhost", (RTS_UINTPTR)x509certcheckhost, 1, 0x7EE75544, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509certcheckhost
	#define EXT_CmpX509Cert_Implementationx509certcheckhost
	#define GET_CmpX509Cert_Implementationx509certcheckhost  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509certcheckhost  x509certcheckhost
	#define CHK_CmpX509Cert_Implementationx509certcheckhost  TRUE
	#define EXP_CmpX509Cert_Implementationx509certcheckhost  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certcheckhost", (RTS_UINTPTR)x509certcheckhost, 1, 0x7EE75544, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509certcheckhost
	#define EXT_x509certcheckhost
	#define GET_x509certcheckhost(fl)  CAL_CMGETAPI( "x509certcheckhost" ) 
	#define CAL_x509certcheckhost  x509certcheckhost
	#define CHK_x509certcheckhost  TRUE
	#define EXP_x509certcheckhost  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certcheckhost", (RTS_UINTPTR)x509certcheckhost, 1, 0x7EE75544, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509certcheckhost  PFX509CERTCHECKHOST_IEC pfx509certcheckhost;
	#define EXT_x509certcheckhost  extern PFX509CERTCHECKHOST_IEC pfx509certcheckhost;
	#define GET_x509certcheckhost(fl)  s_pfCMGetAPI2( "x509certcheckhost", (RTS_VOID_FCTPTR *)&pfx509certcheckhost, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x7EE75544, 0x03050F00)
	#define CAL_x509certcheckhost  pfx509certcheckhost
	#define CHK_x509certcheckhost  (pfx509certcheckhost != NULL)
	#define EXP_x509certcheckhost   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certcheckhost", (RTS_UINTPTR)x509certcheckhost, 1, 0x7EE75544, 0x03050F00) 
#endif


/**
 * Check if a certificate is bound to a specific IP Address.
 * :return: True if the IP is part of the certificate.
 */
typedef struct tagx509certcheckip_struct
{
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	
	INADDR *pIP;						/* VAR_INPUT */	/* Handle of to certificate. */
	RTS_IEC_DWORD flags;				/* VAR_INPUT, Enum: RTSX509CERTCHECKFLAGS */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Flags how to check for the IP address. Values of the enumeration can be combined. */
	RTS_IEC_BOOL X509CertCheckIP;		/* VAR_OUTPUT */	
} x509certcheckip_struct;

void CDECL CDECL_EXT x509certcheckip(x509certcheckip_struct *p);
typedef void (CDECL CDECL_EXT* PFX509CERTCHECKIP_IEC) (x509certcheckip_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509CERTCHECKIP_NOTIMPLEMENTED)
	#define USE_x509certcheckip
	#define EXT_x509certcheckip
	#define GET_x509certcheckip(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509certcheckip(p0) 
	#define CHK_x509certcheckip  FALSE
	#define EXP_x509certcheckip  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509certcheckip
	#define EXT_x509certcheckip
	#define GET_x509certcheckip(fl)  CAL_CMGETAPI( "x509certcheckip" ) 
	#define CAL_x509certcheckip  x509certcheckip
	#define CHK_x509certcheckip  TRUE
	#define EXP_x509certcheckip  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certcheckip", (RTS_UINTPTR)x509certcheckip, 1, 0x9F16A670, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509certcheckip
	#define EXT_x509certcheckip
	#define GET_x509certcheckip(fl)  CAL_CMGETAPI( "x509certcheckip" ) 
	#define CAL_x509certcheckip  x509certcheckip
	#define CHK_x509certcheckip  TRUE
	#define EXP_x509certcheckip  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certcheckip", (RTS_UINTPTR)x509certcheckip, 1, 0x9F16A670, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509certcheckip
	#define EXT_CmpX509Cert_Implementationx509certcheckip
	#define GET_CmpX509Cert_Implementationx509certcheckip  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509certcheckip  x509certcheckip
	#define CHK_CmpX509Cert_Implementationx509certcheckip  TRUE
	#define EXP_CmpX509Cert_Implementationx509certcheckip  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certcheckip", (RTS_UINTPTR)x509certcheckip, 1, 0x9F16A670, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509certcheckip
	#define EXT_x509certcheckip
	#define GET_x509certcheckip(fl)  CAL_CMGETAPI( "x509certcheckip" ) 
	#define CAL_x509certcheckip  x509certcheckip
	#define CHK_x509certcheckip  TRUE
	#define EXP_x509certcheckip  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certcheckip", (RTS_UINTPTR)x509certcheckip, 1, 0x9F16A670, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509certcheckip  PFX509CERTCHECKIP_IEC pfx509certcheckip;
	#define EXT_x509certcheckip  extern PFX509CERTCHECKIP_IEC pfx509certcheckip;
	#define GET_x509certcheckip(fl)  s_pfCMGetAPI2( "x509certcheckip", (RTS_VOID_FCTPTR *)&pfx509certcheckip, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x9F16A670, 0x03050F00)
	#define CAL_x509certcheckip  pfx509certcheckip
	#define CHK_x509certcheckip  (pfx509certcheckip != NULL)
	#define EXP_x509certcheckip   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certcheckip", (RTS_UINTPTR)x509certcheckip, 1, 0x9F16A670, 0x03050F00) 
#endif


/**
 * Close the certificate.
 * :return: Result of the operation.
 */
typedef struct tagx509certclose_struct
{
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	/* Handle of to certificate. */
	RTS_IEC_RESULT X509CertClose;		/* VAR_OUTPUT */	
} x509certclose_struct;

void CDECL CDECL_EXT x509certclose(x509certclose_struct *p);
typedef void (CDECL CDECL_EXT* PFX509CERTCLOSE_IEC) (x509certclose_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509CERTCLOSE_NOTIMPLEMENTED)
	#define USE_x509certclose
	#define EXT_x509certclose
	#define GET_x509certclose(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509certclose(p0) 
	#define CHK_x509certclose  FALSE
	#define EXP_x509certclose  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509certclose
	#define EXT_x509certclose
	#define GET_x509certclose(fl)  CAL_CMGETAPI( "x509certclose" ) 
	#define CAL_x509certclose  x509certclose
	#define CHK_x509certclose  TRUE
	#define EXP_x509certclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certclose", (RTS_UINTPTR)x509certclose, 1, 0x150A5E6B, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509certclose
	#define EXT_x509certclose
	#define GET_x509certclose(fl)  CAL_CMGETAPI( "x509certclose" ) 
	#define CAL_x509certclose  x509certclose
	#define CHK_x509certclose  TRUE
	#define EXP_x509certclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certclose", (RTS_UINTPTR)x509certclose, 1, 0x150A5E6B, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509certclose
	#define EXT_CmpX509Cert_Implementationx509certclose
	#define GET_CmpX509Cert_Implementationx509certclose  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509certclose  x509certclose
	#define CHK_CmpX509Cert_Implementationx509certclose  TRUE
	#define EXP_CmpX509Cert_Implementationx509certclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certclose", (RTS_UINTPTR)x509certclose, 1, 0x150A5E6B, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509certclose
	#define EXT_x509certclose
	#define GET_x509certclose(fl)  CAL_CMGETAPI( "x509certclose" ) 
	#define CAL_x509certclose  x509certclose
	#define CHK_x509certclose  TRUE
	#define EXP_x509certclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certclose", (RTS_UINTPTR)x509certclose, 1, 0x150A5E6B, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509certclose  PFX509CERTCLOSE_IEC pfx509certclose;
	#define EXT_x509certclose  extern PFX509CERTCLOSE_IEC pfx509certclose;
	#define GET_x509certclose(fl)  s_pfCMGetAPI2( "x509certclose", (RTS_VOID_FCTPTR *)&pfx509certclose, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x150A5E6B, 0x03050F00)
	#define CAL_x509certclose  pfx509certclose
	#define CHK_x509certclose  (pfx509certclose != NULL)
	#define EXP_x509certclose   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certclose", (RTS_UINTPTR)x509certclose, 1, 0x150A5E6B, 0x03050F00) 
#endif


/**
 * <description>x509certcmsdecrypt</description>
 */
typedef struct tagx509certcmsdecrypt_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RTS_IEC_HANDLE hRecipientCert;		/* VAR_INPUT */	
	RtsByteString *pCms;				/* VAR_INPUT */	
	RTS_IEC_INT encoding;				/* VAR_INPUT, Enum: RTSCERTENCODING */
	RtsByteString *pOutData;			/* VAR_INPUT */	
	RTS_IEC_RESULT X509CertCmsDecrypt;	/* VAR_OUTPUT */	
} x509certcmsdecrypt_struct;

void CDECL CDECL_EXT x509certcmsdecrypt(x509certcmsdecrypt_struct *p);
typedef void (CDECL CDECL_EXT* PFX509CERTCMSDECRYPT_IEC) (x509certcmsdecrypt_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509CERTCMSDECRYPT_NOTIMPLEMENTED)
	#define USE_x509certcmsdecrypt
	#define EXT_x509certcmsdecrypt
	#define GET_x509certcmsdecrypt(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509certcmsdecrypt(p0) 
	#define CHK_x509certcmsdecrypt  FALSE
	#define EXP_x509certcmsdecrypt  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509certcmsdecrypt
	#define EXT_x509certcmsdecrypt
	#define GET_x509certcmsdecrypt(fl)  CAL_CMGETAPI( "x509certcmsdecrypt" ) 
	#define CAL_x509certcmsdecrypt  x509certcmsdecrypt
	#define CHK_x509certcmsdecrypt  TRUE
	#define EXP_x509certcmsdecrypt  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certcmsdecrypt", (RTS_UINTPTR)x509certcmsdecrypt, 1, 0xCCAD85D1, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509certcmsdecrypt
	#define EXT_x509certcmsdecrypt
	#define GET_x509certcmsdecrypt(fl)  CAL_CMGETAPI( "x509certcmsdecrypt" ) 
	#define CAL_x509certcmsdecrypt  x509certcmsdecrypt
	#define CHK_x509certcmsdecrypt  TRUE
	#define EXP_x509certcmsdecrypt  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certcmsdecrypt", (RTS_UINTPTR)x509certcmsdecrypt, 1, 0xCCAD85D1, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509certcmsdecrypt
	#define EXT_CmpX509Cert_Implementationx509certcmsdecrypt
	#define GET_CmpX509Cert_Implementationx509certcmsdecrypt  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509certcmsdecrypt  x509certcmsdecrypt
	#define CHK_CmpX509Cert_Implementationx509certcmsdecrypt  TRUE
	#define EXP_CmpX509Cert_Implementationx509certcmsdecrypt  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certcmsdecrypt", (RTS_UINTPTR)x509certcmsdecrypt, 1, 0xCCAD85D1, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509certcmsdecrypt
	#define EXT_x509certcmsdecrypt
	#define GET_x509certcmsdecrypt(fl)  CAL_CMGETAPI( "x509certcmsdecrypt" ) 
	#define CAL_x509certcmsdecrypt  x509certcmsdecrypt
	#define CHK_x509certcmsdecrypt  TRUE
	#define EXP_x509certcmsdecrypt  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certcmsdecrypt", (RTS_UINTPTR)x509certcmsdecrypt, 1, 0xCCAD85D1, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509certcmsdecrypt  PFX509CERTCMSDECRYPT_IEC pfx509certcmsdecrypt;
	#define EXT_x509certcmsdecrypt  extern PFX509CERTCMSDECRYPT_IEC pfx509certcmsdecrypt;
	#define GET_x509certcmsdecrypt(fl)  s_pfCMGetAPI2( "x509certcmsdecrypt", (RTS_VOID_FCTPTR *)&pfx509certcmsdecrypt, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xCCAD85D1, 0x03050F00)
	#define CAL_x509certcmsdecrypt  pfx509certcmsdecrypt
	#define CHK_x509certcmsdecrypt  (pfx509certcmsdecrypt != NULL)
	#define EXP_x509certcmsdecrypt   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certcmsdecrypt", (RTS_UINTPTR)x509certcmsdecrypt, 1, 0xCCAD85D1, 0x03050F00) 
#endif


/**
 * <description>x509certcmsverify</description>
 */
typedef struct tagx509certcmsverify_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RtsByteString *pCms;				/* VAR_INPUT */	
	RTS_IEC_INT encoding;				/* VAR_INPUT, Enum: RTSCERTENCODING */
	RtsByteString *pInData;				/* VAR_INPUT */	
	RtsByteString *pOutData;			/* VAR_INPUT */	
	RTS_IEC_RESULT X509CertCmsVerify;	/* VAR_OUTPUT */	
} x509certcmsverify_struct;

void CDECL CDECL_EXT x509certcmsverify(x509certcmsverify_struct *p);
typedef void (CDECL CDECL_EXT* PFX509CERTCMSVERIFY_IEC) (x509certcmsverify_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509CERTCMSVERIFY_NOTIMPLEMENTED)
	#define USE_x509certcmsverify
	#define EXT_x509certcmsverify
	#define GET_x509certcmsverify(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509certcmsverify(p0) 
	#define CHK_x509certcmsverify  FALSE
	#define EXP_x509certcmsverify  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509certcmsverify
	#define EXT_x509certcmsverify
	#define GET_x509certcmsverify(fl)  CAL_CMGETAPI( "x509certcmsverify" ) 
	#define CAL_x509certcmsverify  x509certcmsverify
	#define CHK_x509certcmsverify  TRUE
	#define EXP_x509certcmsverify  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certcmsverify", (RTS_UINTPTR)x509certcmsverify, 1, 0x73653424, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509certcmsverify
	#define EXT_x509certcmsverify
	#define GET_x509certcmsverify(fl)  CAL_CMGETAPI( "x509certcmsverify" ) 
	#define CAL_x509certcmsverify  x509certcmsverify
	#define CHK_x509certcmsverify  TRUE
	#define EXP_x509certcmsverify  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certcmsverify", (RTS_UINTPTR)x509certcmsverify, 1, 0x73653424, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509certcmsverify
	#define EXT_CmpX509Cert_Implementationx509certcmsverify
	#define GET_CmpX509Cert_Implementationx509certcmsverify  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509certcmsverify  x509certcmsverify
	#define CHK_CmpX509Cert_Implementationx509certcmsverify  TRUE
	#define EXP_CmpX509Cert_Implementationx509certcmsverify  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certcmsverify", (RTS_UINTPTR)x509certcmsverify, 1, 0x73653424, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509certcmsverify
	#define EXT_x509certcmsverify
	#define GET_x509certcmsverify(fl)  CAL_CMGETAPI( "x509certcmsverify" ) 
	#define CAL_x509certcmsverify  x509certcmsverify
	#define CHK_x509certcmsverify  TRUE
	#define EXP_x509certcmsverify  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certcmsverify", (RTS_UINTPTR)x509certcmsverify, 1, 0x73653424, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509certcmsverify  PFX509CERTCMSVERIFY_IEC pfx509certcmsverify;
	#define EXT_x509certcmsverify  extern PFX509CERTCMSVERIFY_IEC pfx509certcmsverify;
	#define GET_x509certcmsverify(fl)  s_pfCMGetAPI2( "x509certcmsverify", (RTS_VOID_FCTPTR *)&pfx509certcmsverify, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x73653424, 0x03050F00)
	#define CAL_x509certcmsverify  pfx509certcmsverify
	#define CHK_x509certcmsverify  (pfx509certcmsverify != NULL)
	#define EXP_x509certcmsverify   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certcmsverify", (RTS_UINTPTR)x509certcmsverify, 1, 0x73653424, 0x03050F00) 
#endif


/**
 * <description>x509certcreatecsr</description>
 */
typedef struct tagx509certcreatecsr_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RTS_IEC_HANDLE hBackend;			/* VAR_INPUT */	
	RtsX509CertInfo *pCertInfo;			/* VAR_INPUT */	
	RTS_IEC_UDINT ui32KeySize;			/* VAR_INPUT */	
	RTS_IEC_INT encoding;				/* VAR_INPUT, Enum: RTSCERTENCODING */
	RtsByteString *pCSR;				/* VAR_INPUT */	
	RTS_IEC_RESULT X509CertCreateCSR;	/* VAR_OUTPUT */	
} x509certcreatecsr_struct;

void CDECL CDECL_EXT x509certcreatecsr(x509certcreatecsr_struct *p);
typedef void (CDECL CDECL_EXT* PFX509CERTCREATECSR_IEC) (x509certcreatecsr_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509CERTCREATECSR_NOTIMPLEMENTED)
	#define USE_x509certcreatecsr
	#define EXT_x509certcreatecsr
	#define GET_x509certcreatecsr(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509certcreatecsr(p0) 
	#define CHK_x509certcreatecsr  FALSE
	#define EXP_x509certcreatecsr  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509certcreatecsr
	#define EXT_x509certcreatecsr
	#define GET_x509certcreatecsr(fl)  CAL_CMGETAPI( "x509certcreatecsr" ) 
	#define CAL_x509certcreatecsr  x509certcreatecsr
	#define CHK_x509certcreatecsr  TRUE
	#define EXP_x509certcreatecsr  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certcreatecsr", (RTS_UINTPTR)x509certcreatecsr, 1, 0xF64C1D04, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509certcreatecsr
	#define EXT_x509certcreatecsr
	#define GET_x509certcreatecsr(fl)  CAL_CMGETAPI( "x509certcreatecsr" ) 
	#define CAL_x509certcreatecsr  x509certcreatecsr
	#define CHK_x509certcreatecsr  TRUE
	#define EXP_x509certcreatecsr  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certcreatecsr", (RTS_UINTPTR)x509certcreatecsr, 1, 0xF64C1D04, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509certcreatecsr
	#define EXT_CmpX509Cert_Implementationx509certcreatecsr
	#define GET_CmpX509Cert_Implementationx509certcreatecsr  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509certcreatecsr  x509certcreatecsr
	#define CHK_CmpX509Cert_Implementationx509certcreatecsr  TRUE
	#define EXP_CmpX509Cert_Implementationx509certcreatecsr  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certcreatecsr", (RTS_UINTPTR)x509certcreatecsr, 1, 0xF64C1D04, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509certcreatecsr
	#define EXT_x509certcreatecsr
	#define GET_x509certcreatecsr(fl)  CAL_CMGETAPI( "x509certcreatecsr" ) 
	#define CAL_x509certcreatecsr  x509certcreatecsr
	#define CHK_x509certcreatecsr  TRUE
	#define EXP_x509certcreatecsr  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certcreatecsr", (RTS_UINTPTR)x509certcreatecsr, 1, 0xF64C1D04, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509certcreatecsr  PFX509CERTCREATECSR_IEC pfx509certcreatecsr;
	#define EXT_x509certcreatecsr  extern PFX509CERTCREATECSR_IEC pfx509certcreatecsr;
	#define GET_x509certcreatecsr(fl)  s_pfCMGetAPI2( "x509certcreatecsr", (RTS_VOID_FCTPTR *)&pfx509certcreatecsr, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xF64C1D04, 0x03050F00)
	#define CAL_x509certcreatecsr  pfx509certcreatecsr
	#define CHK_x509certcreatecsr  (pfx509certcreatecsr != NULL)
	#define EXP_x509certcreatecsr   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certcreatecsr", (RTS_UINTPTR)x509certcreatecsr, 1, 0xF64C1D04, 0x03050F00) 
#endif


/**
 * <description>x509certcreateselfsigned</description>
 */
typedef struct tagx509certcreateselfsigned_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RTS_IEC_HANDLE hBackend;			/* VAR_INPUT */	
	RtsX509CertInfo *pCertInfo;			/* VAR_INPUT */	
	RTS_IEC_UDINT ui32KeySize;			/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_HANDLE X509CertCreateSelfSigned;	/* VAR_OUTPUT */	
} x509certcreateselfsigned_struct;

void CDECL CDECL_EXT x509certcreateselfsigned(x509certcreateselfsigned_struct *p);
typedef void (CDECL CDECL_EXT* PFX509CERTCREATESELFSIGNED_IEC) (x509certcreateselfsigned_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509CERTCREATESELFSIGNED_NOTIMPLEMENTED)
	#define USE_x509certcreateselfsigned
	#define EXT_x509certcreateselfsigned
	#define GET_x509certcreateselfsigned(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509certcreateselfsigned(p0) 
	#define CHK_x509certcreateselfsigned  FALSE
	#define EXP_x509certcreateselfsigned  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509certcreateselfsigned
	#define EXT_x509certcreateselfsigned
	#define GET_x509certcreateselfsigned(fl)  CAL_CMGETAPI( "x509certcreateselfsigned" ) 
	#define CAL_x509certcreateselfsigned  x509certcreateselfsigned
	#define CHK_x509certcreateselfsigned  TRUE
	#define EXP_x509certcreateselfsigned  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certcreateselfsigned", (RTS_UINTPTR)x509certcreateselfsigned, 1, 0x6765E8BD, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509certcreateselfsigned
	#define EXT_x509certcreateselfsigned
	#define GET_x509certcreateselfsigned(fl)  CAL_CMGETAPI( "x509certcreateselfsigned" ) 
	#define CAL_x509certcreateselfsigned  x509certcreateselfsigned
	#define CHK_x509certcreateselfsigned  TRUE
	#define EXP_x509certcreateselfsigned  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certcreateselfsigned", (RTS_UINTPTR)x509certcreateselfsigned, 1, 0x6765E8BD, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509certcreateselfsigned
	#define EXT_CmpX509Cert_Implementationx509certcreateselfsigned
	#define GET_CmpX509Cert_Implementationx509certcreateselfsigned  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509certcreateselfsigned  x509certcreateselfsigned
	#define CHK_CmpX509Cert_Implementationx509certcreateselfsigned  TRUE
	#define EXP_CmpX509Cert_Implementationx509certcreateselfsigned  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certcreateselfsigned", (RTS_UINTPTR)x509certcreateselfsigned, 1, 0x6765E8BD, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509certcreateselfsigned
	#define EXT_x509certcreateselfsigned
	#define GET_x509certcreateselfsigned(fl)  CAL_CMGETAPI( "x509certcreateselfsigned" ) 
	#define CAL_x509certcreateselfsigned  x509certcreateselfsigned
	#define CHK_x509certcreateselfsigned  TRUE
	#define EXP_x509certcreateselfsigned  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certcreateselfsigned", (RTS_UINTPTR)x509certcreateselfsigned, 1, 0x6765E8BD, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509certcreateselfsigned  PFX509CERTCREATESELFSIGNED_IEC pfx509certcreateselfsigned;
	#define EXT_x509certcreateselfsigned  extern PFX509CERTCREATESELFSIGNED_IEC pfx509certcreateselfsigned;
	#define GET_x509certcreateselfsigned(fl)  s_pfCMGetAPI2( "x509certcreateselfsigned", (RTS_VOID_FCTPTR *)&pfx509certcreateselfsigned, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x6765E8BD, 0x03050F00)
	#define CAL_x509certcreateselfsigned  pfx509certcreateselfsigned
	#define CHK_x509certcreateselfsigned  (pfx509certcreateselfsigned != NULL)
	#define EXP_x509certcreateselfsigned   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certcreateselfsigned", (RTS_UINTPTR)x509certcreateselfsigned, 1, 0x6765E8BD, 0x03050F00) 
#endif


/**
 * Get the certificate in a binary encoded format. Use the encoding parameter
 * to set the needed format.
 * :return: Result of the operation.
 */
typedef struct tagx509certgetbinary_struct
{
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	/* Handle of the certificate of intrest. */
	RTS_IEC_INT encoding;				/* VAR_INPUT, Enum: RTSCERTENCODING */
	RtsByteString *pCert;				/* VAR_INPUT */	/* Buffer where to store the certificate. If the bytestring contains a NULL memory pointer the function will write the needed bufferlength to the pCert->ui32Length member. */
	RTS_IEC_RESULT X509CertGetBinary;	/* VAR_OUTPUT */	
} x509certgetbinary_struct;

void CDECL CDECL_EXT x509certgetbinary(x509certgetbinary_struct *p);
typedef void (CDECL CDECL_EXT* PFX509CERTGETBINARY_IEC) (x509certgetbinary_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509CERTGETBINARY_NOTIMPLEMENTED)
	#define USE_x509certgetbinary
	#define EXT_x509certgetbinary
	#define GET_x509certgetbinary(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509certgetbinary(p0) 
	#define CHK_x509certgetbinary  FALSE
	#define EXP_x509certgetbinary  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509certgetbinary
	#define EXT_x509certgetbinary
	#define GET_x509certgetbinary(fl)  CAL_CMGETAPI( "x509certgetbinary" ) 
	#define CAL_x509certgetbinary  x509certgetbinary
	#define CHK_x509certgetbinary  TRUE
	#define EXP_x509certgetbinary  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certgetbinary", (RTS_UINTPTR)x509certgetbinary, 1, 0x6F7D6C42, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509certgetbinary
	#define EXT_x509certgetbinary
	#define GET_x509certgetbinary(fl)  CAL_CMGETAPI( "x509certgetbinary" ) 
	#define CAL_x509certgetbinary  x509certgetbinary
	#define CHK_x509certgetbinary  TRUE
	#define EXP_x509certgetbinary  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certgetbinary", (RTS_UINTPTR)x509certgetbinary, 1, 0x6F7D6C42, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509certgetbinary
	#define EXT_CmpX509Cert_Implementationx509certgetbinary
	#define GET_CmpX509Cert_Implementationx509certgetbinary  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509certgetbinary  x509certgetbinary
	#define CHK_CmpX509Cert_Implementationx509certgetbinary  TRUE
	#define EXP_CmpX509Cert_Implementationx509certgetbinary  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certgetbinary", (RTS_UINTPTR)x509certgetbinary, 1, 0x6F7D6C42, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509certgetbinary
	#define EXT_x509certgetbinary
	#define GET_x509certgetbinary(fl)  CAL_CMGETAPI( "x509certgetbinary" ) 
	#define CAL_x509certgetbinary  x509certgetbinary
	#define CHK_x509certgetbinary  TRUE
	#define EXP_x509certgetbinary  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certgetbinary", (RTS_UINTPTR)x509certgetbinary, 1, 0x6F7D6C42, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509certgetbinary  PFX509CERTGETBINARY_IEC pfx509certgetbinary;
	#define EXT_x509certgetbinary  extern PFX509CERTGETBINARY_IEC pfx509certgetbinary;
	#define GET_x509certgetbinary(fl)  s_pfCMGetAPI2( "x509certgetbinary", (RTS_VOID_FCTPTR *)&pfx509certgetbinary, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x6F7D6C42, 0x03050F00)
	#define CAL_x509certgetbinary  pfx509certgetbinary
	#define CHK_x509certgetbinary  (pfx509certgetbinary != NULL)
	#define EXP_x509certgetbinary   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certgetbinary", (RTS_UINTPTR)x509certgetbinary, 1, 0x6F7D6C42, 0x03050F00) 
#endif


/**
 * Get some common content from the certificate.
 * :return: Result of the operation.
 */
typedef struct tagx509certgetcontent_struct
{
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	/* Handle of the certificate of intrest. */
	RtsX509CertInfo *pCertContent;		/* VAR_INPUT */	/* Pointer where to store the information. */
	RTS_IEC_RESULT X509CertGetContent;	/* VAR_OUTPUT */	
} x509certgetcontent_struct;

void CDECL CDECL_EXT x509certgetcontent(x509certgetcontent_struct *p);
typedef void (CDECL CDECL_EXT* PFX509CERTGETCONTENT_IEC) (x509certgetcontent_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509CERTGETCONTENT_NOTIMPLEMENTED)
	#define USE_x509certgetcontent
	#define EXT_x509certgetcontent
	#define GET_x509certgetcontent(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509certgetcontent(p0) 
	#define CHK_x509certgetcontent  FALSE
	#define EXP_x509certgetcontent  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509certgetcontent
	#define EXT_x509certgetcontent
	#define GET_x509certgetcontent(fl)  CAL_CMGETAPI( "x509certgetcontent" ) 
	#define CAL_x509certgetcontent  x509certgetcontent
	#define CHK_x509certgetcontent  TRUE
	#define EXP_x509certgetcontent  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certgetcontent", (RTS_UINTPTR)x509certgetcontent, 1, 0xDA69570E, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509certgetcontent
	#define EXT_x509certgetcontent
	#define GET_x509certgetcontent(fl)  CAL_CMGETAPI( "x509certgetcontent" ) 
	#define CAL_x509certgetcontent  x509certgetcontent
	#define CHK_x509certgetcontent  TRUE
	#define EXP_x509certgetcontent  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certgetcontent", (RTS_UINTPTR)x509certgetcontent, 1, 0xDA69570E, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509certgetcontent
	#define EXT_CmpX509Cert_Implementationx509certgetcontent
	#define GET_CmpX509Cert_Implementationx509certgetcontent  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509certgetcontent  x509certgetcontent
	#define CHK_CmpX509Cert_Implementationx509certgetcontent  TRUE
	#define EXP_CmpX509Cert_Implementationx509certgetcontent  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certgetcontent", (RTS_UINTPTR)x509certgetcontent, 1, 0xDA69570E, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509certgetcontent
	#define EXT_x509certgetcontent
	#define GET_x509certgetcontent(fl)  CAL_CMGETAPI( "x509certgetcontent" ) 
	#define CAL_x509certgetcontent  x509certgetcontent
	#define CHK_x509certgetcontent  TRUE
	#define EXP_x509certgetcontent  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certgetcontent", (RTS_UINTPTR)x509certgetcontent, 1, 0xDA69570E, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509certgetcontent  PFX509CERTGETCONTENT_IEC pfx509certgetcontent;
	#define EXT_x509certgetcontent  extern PFX509CERTGETCONTENT_IEC pfx509certgetcontent;
	#define GET_x509certgetcontent(fl)  s_pfCMGetAPI2( "x509certgetcontent", (RTS_VOID_FCTPTR *)&pfx509certgetcontent, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xDA69570E, 0x03050F00)
	#define CAL_x509certgetcontent  pfx509certgetcontent
	#define CHK_x509certgetcontent  (pfx509certgetcontent != NULL)
	#define EXP_x509certgetcontent   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certgetcontent", (RTS_UINTPTR)x509certgetcontent, 1, 0xDA69570E, 0x03050F00) 
#endif


/**
 * <description>x509certgetprivatekey</description>
 */
typedef struct tagx509certgetprivatekey_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	
	RtsCryptoKey *pPrivateKey;			/* VAR_INPUT */	
	RTS_IEC_RESULT X509CertGetPrivateKey;	/* VAR_OUTPUT */	
} x509certgetprivatekey_struct;

void CDECL CDECL_EXT x509certgetprivatekey(x509certgetprivatekey_struct *p);
typedef void (CDECL CDECL_EXT* PFX509CERTGETPRIVATEKEY_IEC) (x509certgetprivatekey_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509CERTGETPRIVATEKEY_NOTIMPLEMENTED)
	#define USE_x509certgetprivatekey
	#define EXT_x509certgetprivatekey
	#define GET_x509certgetprivatekey(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509certgetprivatekey(p0) 
	#define CHK_x509certgetprivatekey  FALSE
	#define EXP_x509certgetprivatekey  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509certgetprivatekey
	#define EXT_x509certgetprivatekey
	#define GET_x509certgetprivatekey(fl)  CAL_CMGETAPI( "x509certgetprivatekey" ) 
	#define CAL_x509certgetprivatekey  x509certgetprivatekey
	#define CHK_x509certgetprivatekey  TRUE
	#define EXP_x509certgetprivatekey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certgetprivatekey", (RTS_UINTPTR)x509certgetprivatekey, 1, 0x279C9A63, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509certgetprivatekey
	#define EXT_x509certgetprivatekey
	#define GET_x509certgetprivatekey(fl)  CAL_CMGETAPI( "x509certgetprivatekey" ) 
	#define CAL_x509certgetprivatekey  x509certgetprivatekey
	#define CHK_x509certgetprivatekey  TRUE
	#define EXP_x509certgetprivatekey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certgetprivatekey", (RTS_UINTPTR)x509certgetprivatekey, 1, 0x279C9A63, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509certgetprivatekey
	#define EXT_CmpX509Cert_Implementationx509certgetprivatekey
	#define GET_CmpX509Cert_Implementationx509certgetprivatekey  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509certgetprivatekey  x509certgetprivatekey
	#define CHK_CmpX509Cert_Implementationx509certgetprivatekey  TRUE
	#define EXP_CmpX509Cert_Implementationx509certgetprivatekey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certgetprivatekey", (RTS_UINTPTR)x509certgetprivatekey, 1, 0x279C9A63, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509certgetprivatekey
	#define EXT_x509certgetprivatekey
	#define GET_x509certgetprivatekey(fl)  CAL_CMGETAPI( "x509certgetprivatekey" ) 
	#define CAL_x509certgetprivatekey  x509certgetprivatekey
	#define CHK_x509certgetprivatekey  TRUE
	#define EXP_x509certgetprivatekey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certgetprivatekey", (RTS_UINTPTR)x509certgetprivatekey, 1, 0x279C9A63, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509certgetprivatekey  PFX509CERTGETPRIVATEKEY_IEC pfx509certgetprivatekey;
	#define EXT_x509certgetprivatekey  extern PFX509CERTGETPRIVATEKEY_IEC pfx509certgetprivatekey;
	#define GET_x509certgetprivatekey(fl)  s_pfCMGetAPI2( "x509certgetprivatekey", (RTS_VOID_FCTPTR *)&pfx509certgetprivatekey, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x279C9A63, 0x03050F00)
	#define CAL_x509certgetprivatekey  pfx509certgetprivatekey
	#define CHK_x509certgetprivatekey  (pfx509certgetprivatekey != NULL)
	#define EXP_x509certgetprivatekey   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certgetprivatekey", (RTS_UINTPTR)x509certgetprivatekey, 1, 0x279C9A63, 0x03050F00) 
#endif


/**
 * Get the PUBLIC key FROM the certificate.
 *
 * The format of this key is an implementation detail and has to match
 * the expected format of the asymmetric functions of the CmpCrpyotItf.
 * The key data is opaque for the user of the keys. If the keys are needed in a
 * defined exchange format use the CryptoKeyExport function of the CmpCryptoItf.
 * :return: Result of the operation. 
 */
typedef struct tagx509certgetpublickey_struct
{
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	/* Handle of the certificate of intrest. */
	RtsCryptoKey *pPublicKey;			/* VAR_INPUT */	/* Pointer to the crypto key storing the public key. */
	RTS_IEC_RESULT X509CertGetPublicKey;	/* VAR_OUTPUT */	
} x509certgetpublickey_struct;

void CDECL CDECL_EXT x509certgetpublickey(x509certgetpublickey_struct *p);
typedef void (CDECL CDECL_EXT* PFX509CERTGETPUBLICKEY_IEC) (x509certgetpublickey_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509CERTGETPUBLICKEY_NOTIMPLEMENTED)
	#define USE_x509certgetpublickey
	#define EXT_x509certgetpublickey
	#define GET_x509certgetpublickey(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509certgetpublickey(p0) 
	#define CHK_x509certgetpublickey  FALSE
	#define EXP_x509certgetpublickey  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509certgetpublickey
	#define EXT_x509certgetpublickey
	#define GET_x509certgetpublickey(fl)  CAL_CMGETAPI( "x509certgetpublickey" ) 
	#define CAL_x509certgetpublickey  x509certgetpublickey
	#define CHK_x509certgetpublickey  TRUE
	#define EXP_x509certgetpublickey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certgetpublickey", (RTS_UINTPTR)x509certgetpublickey, 1, 0x35142E48, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509certgetpublickey
	#define EXT_x509certgetpublickey
	#define GET_x509certgetpublickey(fl)  CAL_CMGETAPI( "x509certgetpublickey" ) 
	#define CAL_x509certgetpublickey  x509certgetpublickey
	#define CHK_x509certgetpublickey  TRUE
	#define EXP_x509certgetpublickey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certgetpublickey", (RTS_UINTPTR)x509certgetpublickey, 1, 0x35142E48, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509certgetpublickey
	#define EXT_CmpX509Cert_Implementationx509certgetpublickey
	#define GET_CmpX509Cert_Implementationx509certgetpublickey  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509certgetpublickey  x509certgetpublickey
	#define CHK_CmpX509Cert_Implementationx509certgetpublickey  TRUE
	#define EXP_CmpX509Cert_Implementationx509certgetpublickey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certgetpublickey", (RTS_UINTPTR)x509certgetpublickey, 1, 0x35142E48, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509certgetpublickey
	#define EXT_x509certgetpublickey
	#define GET_x509certgetpublickey(fl)  CAL_CMGETAPI( "x509certgetpublickey" ) 
	#define CAL_x509certgetpublickey  x509certgetpublickey
	#define CHK_x509certgetpublickey  TRUE
	#define EXP_x509certgetpublickey  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certgetpublickey", (RTS_UINTPTR)x509certgetpublickey, 1, 0x35142E48, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509certgetpublickey  PFX509CERTGETPUBLICKEY_IEC pfx509certgetpublickey;
	#define EXT_x509certgetpublickey  extern PFX509CERTGETPUBLICKEY_IEC pfx509certgetpublickey;
	#define GET_x509certgetpublickey(fl)  s_pfCMGetAPI2( "x509certgetpublickey", (RTS_VOID_FCTPTR *)&pfx509certgetpublickey, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x35142E48, 0x03050F00)
	#define CAL_x509certgetpublickey  pfx509certgetpublickey
	#define CHK_x509certgetpublickey  (pfx509certgetpublickey != NULL)
	#define EXP_x509certgetpublickey   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certgetpublickey", (RTS_UINTPTR)x509certgetpublickey, 1, 0x35142E48, 0x03050F00) 
#endif


/**
 * Generate the certificate thumbprint. The thumbprint will be just the plain bytes of the hash. 
 * The thumprint can be used to identify certificates of the local store. The thumprint may not be globally unique.
 * :return: Result of the operation.
 */
typedef struct tagx509certgetthumbprint_struct
{
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	/* Handle of the certificate of intrest. */
	RTS_IEC_UDINT *hashAlgorithm;		/* VAR_INPUT */	/* The hashing algorithmen used to generate the thumbprint. */
	RtsByteString *pThumprint;			/* VAR_INPUT */	/* Buffer to store the thumbprint. If bytestring is NULL memory ia allocated. */
	RTS_IEC_RESULT X509CertGetThumbprint;	/* VAR_OUTPUT */	
} x509certgetthumbprint_struct;

void CDECL CDECL_EXT x509certgetthumbprint(x509certgetthumbprint_struct *p);
typedef void (CDECL CDECL_EXT* PFX509CERTGETTHUMBPRINT_IEC) (x509certgetthumbprint_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509CERTGETTHUMBPRINT_NOTIMPLEMENTED)
	#define USE_x509certgetthumbprint
	#define EXT_x509certgetthumbprint
	#define GET_x509certgetthumbprint(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509certgetthumbprint(p0) 
	#define CHK_x509certgetthumbprint  FALSE
	#define EXP_x509certgetthumbprint  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509certgetthumbprint
	#define EXT_x509certgetthumbprint
	#define GET_x509certgetthumbprint(fl)  CAL_CMGETAPI( "x509certgetthumbprint" ) 
	#define CAL_x509certgetthumbprint  x509certgetthumbprint
	#define CHK_x509certgetthumbprint  TRUE
	#define EXP_x509certgetthumbprint  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certgetthumbprint", (RTS_UINTPTR)x509certgetthumbprint, 1, 0x5B1EA1C5, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509certgetthumbprint
	#define EXT_x509certgetthumbprint
	#define GET_x509certgetthumbprint(fl)  CAL_CMGETAPI( "x509certgetthumbprint" ) 
	#define CAL_x509certgetthumbprint  x509certgetthumbprint
	#define CHK_x509certgetthumbprint  TRUE
	#define EXP_x509certgetthumbprint  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certgetthumbprint", (RTS_UINTPTR)x509certgetthumbprint, 1, 0x5B1EA1C5, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509certgetthumbprint
	#define EXT_CmpX509Cert_Implementationx509certgetthumbprint
	#define GET_CmpX509Cert_Implementationx509certgetthumbprint  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509certgetthumbprint  x509certgetthumbprint
	#define CHK_CmpX509Cert_Implementationx509certgetthumbprint  TRUE
	#define EXP_CmpX509Cert_Implementationx509certgetthumbprint  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certgetthumbprint", (RTS_UINTPTR)x509certgetthumbprint, 1, 0x5B1EA1C5, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509certgetthumbprint
	#define EXT_x509certgetthumbprint
	#define GET_x509certgetthumbprint(fl)  CAL_CMGETAPI( "x509certgetthumbprint" ) 
	#define CAL_x509certgetthumbprint  x509certgetthumbprint
	#define CHK_x509certgetthumbprint  TRUE
	#define EXP_x509certgetthumbprint  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certgetthumbprint", (RTS_UINTPTR)x509certgetthumbprint, 1, 0x5B1EA1C5, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509certgetthumbprint  PFX509CERTGETTHUMBPRINT_IEC pfx509certgetthumbprint;
	#define EXT_x509certgetthumbprint  extern PFX509CERTGETTHUMBPRINT_IEC pfx509certgetthumbprint;
	#define GET_x509certgetthumbprint(fl)  s_pfCMGetAPI2( "x509certgetthumbprint", (RTS_VOID_FCTPTR *)&pfx509certgetthumbprint, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x5B1EA1C5, 0x03050F00)
	#define CAL_x509certgetthumbprint  pfx509certgetthumbprint
	#define CHK_x509certgetthumbprint  (pfx509certgetthumbprint != NULL)
	#define EXP_x509certgetthumbprint   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certgetthumbprint", (RTS_UINTPTR)x509certgetthumbprint, 1, 0x5B1EA1C5, 0x03050F00) 
#endif


/**
 * Check if the extended keyusages of the specified certificate has the specified extended keyusages
 * :return: True if all key usages are part of the certificate.
 */
typedef struct tagx509certhasextendedkeyusage_struct
{
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	
	RTS_IEC_UDINT numOfExKeyUsages;		/* VAR_INPUT */	/* Handle of to certificate. */
	RtsOID *pExKeyUsages;				/* VAR_INPUT */	/* Number of extended keyusages */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to list of extended keyusages */
	RTS_IEC_BOOL X509CertHasExtendedKeyUsage;	/* VAR_OUTPUT */	
} x509certhasextendedkeyusage_struct;

void CDECL CDECL_EXT x509certhasextendedkeyusage(x509certhasextendedkeyusage_struct *p);
typedef void (CDECL CDECL_EXT* PFX509CERTHASEXTENDEDKEYUSAGE_IEC) (x509certhasextendedkeyusage_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509CERTHASEXTENDEDKEYUSAGE_NOTIMPLEMENTED)
	#define USE_x509certhasextendedkeyusage
	#define EXT_x509certhasextendedkeyusage
	#define GET_x509certhasextendedkeyusage(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509certhasextendedkeyusage(p0) 
	#define CHK_x509certhasextendedkeyusage  FALSE
	#define EXP_x509certhasextendedkeyusage  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509certhasextendedkeyusage
	#define EXT_x509certhasextendedkeyusage
	#define GET_x509certhasextendedkeyusage(fl)  CAL_CMGETAPI( "x509certhasextendedkeyusage" ) 
	#define CAL_x509certhasextendedkeyusage  x509certhasextendedkeyusage
	#define CHK_x509certhasextendedkeyusage  TRUE
	#define EXP_x509certhasextendedkeyusage  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certhasextendedkeyusage", (RTS_UINTPTR)x509certhasextendedkeyusage, 1, 0xFA59BB5D, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509certhasextendedkeyusage
	#define EXT_x509certhasextendedkeyusage
	#define GET_x509certhasextendedkeyusage(fl)  CAL_CMGETAPI( "x509certhasextendedkeyusage" ) 
	#define CAL_x509certhasextendedkeyusage  x509certhasextendedkeyusage
	#define CHK_x509certhasextendedkeyusage  TRUE
	#define EXP_x509certhasextendedkeyusage  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certhasextendedkeyusage", (RTS_UINTPTR)x509certhasextendedkeyusage, 1, 0xFA59BB5D, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509certhasextendedkeyusage
	#define EXT_CmpX509Cert_Implementationx509certhasextendedkeyusage
	#define GET_CmpX509Cert_Implementationx509certhasextendedkeyusage  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509certhasextendedkeyusage  x509certhasextendedkeyusage
	#define CHK_CmpX509Cert_Implementationx509certhasextendedkeyusage  TRUE
	#define EXP_CmpX509Cert_Implementationx509certhasextendedkeyusage  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certhasextendedkeyusage", (RTS_UINTPTR)x509certhasextendedkeyusage, 1, 0xFA59BB5D, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509certhasextendedkeyusage
	#define EXT_x509certhasextendedkeyusage
	#define GET_x509certhasextendedkeyusage(fl)  CAL_CMGETAPI( "x509certhasextendedkeyusage" ) 
	#define CAL_x509certhasextendedkeyusage  x509certhasextendedkeyusage
	#define CHK_x509certhasextendedkeyusage  TRUE
	#define EXP_x509certhasextendedkeyusage  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certhasextendedkeyusage", (RTS_UINTPTR)x509certhasextendedkeyusage, 1, 0xFA59BB5D, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509certhasextendedkeyusage  PFX509CERTHASEXTENDEDKEYUSAGE_IEC pfx509certhasextendedkeyusage;
	#define EXT_x509certhasextendedkeyusage  extern PFX509CERTHASEXTENDEDKEYUSAGE_IEC pfx509certhasextendedkeyusage;
	#define GET_x509certhasextendedkeyusage(fl)  s_pfCMGetAPI2( "x509certhasextendedkeyusage", (RTS_VOID_FCTPTR *)&pfx509certhasextendedkeyusage, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xFA59BB5D, 0x03050F00)
	#define CAL_x509certhasextendedkeyusage  pfx509certhasextendedkeyusage
	#define CHK_x509certhasextendedkeyusage  (pfx509certhasextendedkeyusage != NULL)
	#define EXP_x509certhasextendedkeyusage   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certhasextendedkeyusage", (RTS_UINTPTR)x509certhasextendedkeyusage, 1, 0xFA59BB5D, 0x03050F00) 
#endif


/**
 * Cleanup an RtsX509CertInfo structure. All allocated memory used by this strucutre will be release.
 * :return: Result of the operation
 */
typedef struct tagx509certinfoexit_struct
{
	RtsX509CertInfo *pCertInfo;			/* VAR_INPUT */	/* Pointer to the object to clean up. */
	RTS_IEC_RESULT X509CertInfoExit;	/* VAR_OUTPUT */	
} x509certinfoexit_struct;

void CDECL CDECL_EXT x509certinfoexit(x509certinfoexit_struct *p);
typedef void (CDECL CDECL_EXT* PFX509CERTINFOEXIT_IEC) (x509certinfoexit_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509CERTINFOEXIT_NOTIMPLEMENTED)
	#define USE_x509certinfoexit
	#define EXT_x509certinfoexit
	#define GET_x509certinfoexit(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509certinfoexit(p0) 
	#define CHK_x509certinfoexit  FALSE
	#define EXP_x509certinfoexit  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509certinfoexit
	#define EXT_x509certinfoexit
	#define GET_x509certinfoexit(fl)  CAL_CMGETAPI( "x509certinfoexit" ) 
	#define CAL_x509certinfoexit  x509certinfoexit
	#define CHK_x509certinfoexit  TRUE
	#define EXP_x509certinfoexit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certinfoexit", (RTS_UINTPTR)x509certinfoexit, 1, 0x4F4B0310, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509certinfoexit
	#define EXT_x509certinfoexit
	#define GET_x509certinfoexit(fl)  CAL_CMGETAPI( "x509certinfoexit" ) 
	#define CAL_x509certinfoexit  x509certinfoexit
	#define CHK_x509certinfoexit  TRUE
	#define EXP_x509certinfoexit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certinfoexit", (RTS_UINTPTR)x509certinfoexit, 1, 0x4F4B0310, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509certinfoexit
	#define EXT_CmpX509Cert_Implementationx509certinfoexit
	#define GET_CmpX509Cert_Implementationx509certinfoexit  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509certinfoexit  x509certinfoexit
	#define CHK_CmpX509Cert_Implementationx509certinfoexit  TRUE
	#define EXP_CmpX509Cert_Implementationx509certinfoexit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certinfoexit", (RTS_UINTPTR)x509certinfoexit, 1, 0x4F4B0310, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509certinfoexit
	#define EXT_x509certinfoexit
	#define GET_x509certinfoexit(fl)  CAL_CMGETAPI( "x509certinfoexit" ) 
	#define CAL_x509certinfoexit  x509certinfoexit
	#define CHK_x509certinfoexit  TRUE
	#define EXP_x509certinfoexit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certinfoexit", (RTS_UINTPTR)x509certinfoexit, 1, 0x4F4B0310, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509certinfoexit  PFX509CERTINFOEXIT_IEC pfx509certinfoexit;
	#define EXT_x509certinfoexit  extern PFX509CERTINFOEXIT_IEC pfx509certinfoexit;
	#define GET_x509certinfoexit(fl)  s_pfCMGetAPI2( "x509certinfoexit", (RTS_VOID_FCTPTR *)&pfx509certinfoexit, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x4F4B0310, 0x03050F00)
	#define CAL_x509certinfoexit  pfx509certinfoexit
	#define CHK_x509certinfoexit  (pfx509certinfoexit != NULL)
	#define EXP_x509certinfoexit   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certinfoexit", (RTS_UINTPTR)x509certinfoexit, 1, 0x4F4B0310, 0x03050F00) 
#endif


/**
 * Initialize the RtsX509CertInfo structure.
 * :return: Result of the operation
 */
typedef struct tagx509certinfoinit_struct
{
	RtsX509CertInfo *pCertInfo;			/* VAR_INPUT */	/* Pointer to the structure. */
	RTS_IEC_UDINT structSize;			/* VAR_INPUT */	/* Size of the structure. */
	RTS_IEC_RESULT X509CertInfoInit;	/* VAR_OUTPUT */	
} x509certinfoinit_struct;

void CDECL CDECL_EXT x509certinfoinit(x509certinfoinit_struct *p);
typedef void (CDECL CDECL_EXT* PFX509CERTINFOINIT_IEC) (x509certinfoinit_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509CERTINFOINIT_NOTIMPLEMENTED)
	#define USE_x509certinfoinit
	#define EXT_x509certinfoinit
	#define GET_x509certinfoinit(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509certinfoinit(p0) 
	#define CHK_x509certinfoinit  FALSE
	#define EXP_x509certinfoinit  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509certinfoinit
	#define EXT_x509certinfoinit
	#define GET_x509certinfoinit(fl)  CAL_CMGETAPI( "x509certinfoinit" ) 
	#define CAL_x509certinfoinit  x509certinfoinit
	#define CHK_x509certinfoinit  TRUE
	#define EXP_x509certinfoinit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certinfoinit", (RTS_UINTPTR)x509certinfoinit, 1, 0xD52F28DD, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509certinfoinit
	#define EXT_x509certinfoinit
	#define GET_x509certinfoinit(fl)  CAL_CMGETAPI( "x509certinfoinit" ) 
	#define CAL_x509certinfoinit  x509certinfoinit
	#define CHK_x509certinfoinit  TRUE
	#define EXP_x509certinfoinit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certinfoinit", (RTS_UINTPTR)x509certinfoinit, 1, 0xD52F28DD, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509certinfoinit
	#define EXT_CmpX509Cert_Implementationx509certinfoinit
	#define GET_CmpX509Cert_Implementationx509certinfoinit  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509certinfoinit  x509certinfoinit
	#define CHK_CmpX509Cert_Implementationx509certinfoinit  TRUE
	#define EXP_CmpX509Cert_Implementationx509certinfoinit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certinfoinit", (RTS_UINTPTR)x509certinfoinit, 1, 0xD52F28DD, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509certinfoinit
	#define EXT_x509certinfoinit
	#define GET_x509certinfoinit(fl)  CAL_CMGETAPI( "x509certinfoinit" ) 
	#define CAL_x509certinfoinit  x509certinfoinit
	#define CHK_x509certinfoinit  TRUE
	#define EXP_x509certinfoinit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certinfoinit", (RTS_UINTPTR)x509certinfoinit, 1, 0xD52F28DD, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509certinfoinit  PFX509CERTINFOINIT_IEC pfx509certinfoinit;
	#define EXT_x509certinfoinit  extern PFX509CERTINFOINIT_IEC pfx509certinfoinit;
	#define GET_x509certinfoinit(fl)  s_pfCMGetAPI2( "x509certinfoinit", (RTS_VOID_FCTPTR *)&pfx509certinfoinit, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xD52F28DD, 0x03050F00)
	#define CAL_x509certinfoinit  pfx509certinfoinit
	#define CHK_x509certinfoinit  (pfx509certinfoinit != NULL)
	#define EXP_x509certinfoinit   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certinfoinit", (RTS_UINTPTR)x509certinfoinit, 1, 0xD52F28DD, 0x03050F00) 
#endif


/**
 * Check if a certificate has a valid date (notbefore and notafter is in the current time period)
 */
typedef struct tagx509certisdatevalid_struct
{
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Handle of to certificate. */
	RTS_IEC_BOOL X509CertIsDateValid;	/* VAR_OUTPUT */	
} x509certisdatevalid_struct;

void CDECL CDECL_EXT x509certisdatevalid(x509certisdatevalid_struct *p);
typedef void (CDECL CDECL_EXT* PFX509CERTISDATEVALID_IEC) (x509certisdatevalid_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509CERTISDATEVALID_NOTIMPLEMENTED)
	#define USE_x509certisdatevalid
	#define EXT_x509certisdatevalid
	#define GET_x509certisdatevalid(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509certisdatevalid(p0) 
	#define CHK_x509certisdatevalid  FALSE
	#define EXP_x509certisdatevalid  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509certisdatevalid
	#define EXT_x509certisdatevalid
	#define GET_x509certisdatevalid(fl)  CAL_CMGETAPI( "x509certisdatevalid" ) 
	#define CAL_x509certisdatevalid  x509certisdatevalid
	#define CHK_x509certisdatevalid  TRUE
	#define EXP_x509certisdatevalid  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certisdatevalid", (RTS_UINTPTR)x509certisdatevalid, 1, 0xB5AE8B3D, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509certisdatevalid
	#define EXT_x509certisdatevalid
	#define GET_x509certisdatevalid(fl)  CAL_CMGETAPI( "x509certisdatevalid" ) 
	#define CAL_x509certisdatevalid  x509certisdatevalid
	#define CHK_x509certisdatevalid  TRUE
	#define EXP_x509certisdatevalid  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certisdatevalid", (RTS_UINTPTR)x509certisdatevalid, 1, 0xB5AE8B3D, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509certisdatevalid
	#define EXT_CmpX509Cert_Implementationx509certisdatevalid
	#define GET_CmpX509Cert_Implementationx509certisdatevalid  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509certisdatevalid  x509certisdatevalid
	#define CHK_CmpX509Cert_Implementationx509certisdatevalid  TRUE
	#define EXP_CmpX509Cert_Implementationx509certisdatevalid  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certisdatevalid", (RTS_UINTPTR)x509certisdatevalid, 1, 0xB5AE8B3D, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509certisdatevalid
	#define EXT_x509certisdatevalid
	#define GET_x509certisdatevalid(fl)  CAL_CMGETAPI( "x509certisdatevalid" ) 
	#define CAL_x509certisdatevalid  x509certisdatevalid
	#define CHK_x509certisdatevalid  TRUE
	#define EXP_x509certisdatevalid  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certisdatevalid", (RTS_UINTPTR)x509certisdatevalid, 1, 0xB5AE8B3D, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509certisdatevalid  PFX509CERTISDATEVALID_IEC pfx509certisdatevalid;
	#define EXT_x509certisdatevalid  extern PFX509CERTISDATEVALID_IEC pfx509certisdatevalid;
	#define GET_x509certisdatevalid(fl)  s_pfCMGetAPI2( "x509certisdatevalid", (RTS_VOID_FCTPTR *)&pfx509certisdatevalid, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xB5AE8B3D, 0x03050F00)
	#define CAL_x509certisdatevalid  pfx509certisdatevalid
	#define CHK_x509certisdatevalid  (pfx509certisdatevalid != NULL)
	#define EXP_x509certisdatevalid   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certisdatevalid", (RTS_UINTPTR)x509certisdatevalid, 1, 0xB5AE8B3D, 0x03050F00) 
#endif


/**
 * Check if a certificate is selfsigned of is signed by a CA authority
 */
typedef struct tagx509certisselfsigned_struct
{
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Handle of to certificate. */
	RTS_IEC_BOOL X509CertIsSelfSigned;	/* VAR_OUTPUT */	
} x509certisselfsigned_struct;

void CDECL CDECL_EXT x509certisselfsigned(x509certisselfsigned_struct *p);
typedef void (CDECL CDECL_EXT* PFX509CERTISSELFSIGNED_IEC) (x509certisselfsigned_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509CERTISSELFSIGNED_NOTIMPLEMENTED)
	#define USE_x509certisselfsigned
	#define EXT_x509certisselfsigned
	#define GET_x509certisselfsigned(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509certisselfsigned(p0) 
	#define CHK_x509certisselfsigned  FALSE
	#define EXP_x509certisselfsigned  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509certisselfsigned
	#define EXT_x509certisselfsigned
	#define GET_x509certisselfsigned(fl)  CAL_CMGETAPI( "x509certisselfsigned" ) 
	#define CAL_x509certisselfsigned  x509certisselfsigned
	#define CHK_x509certisselfsigned  TRUE
	#define EXP_x509certisselfsigned  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certisselfsigned", (RTS_UINTPTR)x509certisselfsigned, 1, 0x1B7D16BF, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509certisselfsigned
	#define EXT_x509certisselfsigned
	#define GET_x509certisselfsigned(fl)  CAL_CMGETAPI( "x509certisselfsigned" ) 
	#define CAL_x509certisselfsigned  x509certisselfsigned
	#define CHK_x509certisselfsigned  TRUE
	#define EXP_x509certisselfsigned  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certisselfsigned", (RTS_UINTPTR)x509certisselfsigned, 1, 0x1B7D16BF, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509certisselfsigned
	#define EXT_CmpX509Cert_Implementationx509certisselfsigned
	#define GET_CmpX509Cert_Implementationx509certisselfsigned  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509certisselfsigned  x509certisselfsigned
	#define CHK_CmpX509Cert_Implementationx509certisselfsigned  TRUE
	#define EXP_CmpX509Cert_Implementationx509certisselfsigned  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certisselfsigned", (RTS_UINTPTR)x509certisselfsigned, 1, 0x1B7D16BF, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509certisselfsigned
	#define EXT_x509certisselfsigned
	#define GET_x509certisselfsigned(fl)  CAL_CMGETAPI( "x509certisselfsigned" ) 
	#define CAL_x509certisselfsigned  x509certisselfsigned
	#define CHK_x509certisselfsigned  TRUE
	#define EXP_x509certisselfsigned  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certisselfsigned", (RTS_UINTPTR)x509certisselfsigned, 1, 0x1B7D16BF, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509certisselfsigned  PFX509CERTISSELFSIGNED_IEC pfx509certisselfsigned;
	#define EXT_x509certisselfsigned  extern PFX509CERTISSELFSIGNED_IEC pfx509certisselfsigned;
	#define GET_x509certisselfsigned(fl)  s_pfCMGetAPI2( "x509certisselfsigned", (RTS_VOID_FCTPTR *)&pfx509certisselfsigned, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x1B7D16BF, 0x03050F00)
	#define CAL_x509certisselfsigned  pfx509certisselfsigned
	#define CHK_x509certisselfsigned  (pfx509certisselfsigned != NULL)
	#define EXP_x509certisselfsigned   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certisselfsigned", (RTS_UINTPTR)x509certisselfsigned, 1, 0x1B7D16BF, 0x03050F00) 
#endif


/**
 * Release a PRIVATE OR PUBLIC key with THIS FUNCTION. THIS FUNCTION
 * indicates that this key is not needed anymore and allows to clean up ressources
 * used by this key
 * :return: Result of the operation
 */
typedef struct tagx509certkeyclose_struct
{
	RtsCryptoKey *pKey;					/* VAR_INPUT */	/* Pointer to the key */
	RTS_IEC_RESULT X509CertKeyClose;	/* VAR_OUTPUT */	
} x509certkeyclose_struct;

void CDECL CDECL_EXT x509certkeyclose(x509certkeyclose_struct *p);
typedef void (CDECL CDECL_EXT* PFX509CERTKEYCLOSE_IEC) (x509certkeyclose_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509CERTKEYCLOSE_NOTIMPLEMENTED)
	#define USE_x509certkeyclose
	#define EXT_x509certkeyclose
	#define GET_x509certkeyclose(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509certkeyclose(p0) 
	#define CHK_x509certkeyclose  FALSE
	#define EXP_x509certkeyclose  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509certkeyclose
	#define EXT_x509certkeyclose
	#define GET_x509certkeyclose(fl)  CAL_CMGETAPI( "x509certkeyclose" ) 
	#define CAL_x509certkeyclose  x509certkeyclose
	#define CHK_x509certkeyclose  TRUE
	#define EXP_x509certkeyclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certkeyclose", (RTS_UINTPTR)x509certkeyclose, 1, 0x6A598D05, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509certkeyclose
	#define EXT_x509certkeyclose
	#define GET_x509certkeyclose(fl)  CAL_CMGETAPI( "x509certkeyclose" ) 
	#define CAL_x509certkeyclose  x509certkeyclose
	#define CHK_x509certkeyclose  TRUE
	#define EXP_x509certkeyclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certkeyclose", (RTS_UINTPTR)x509certkeyclose, 1, 0x6A598D05, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509certkeyclose
	#define EXT_CmpX509Cert_Implementationx509certkeyclose
	#define GET_CmpX509Cert_Implementationx509certkeyclose  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509certkeyclose  x509certkeyclose
	#define CHK_CmpX509Cert_Implementationx509certkeyclose  TRUE
	#define EXP_CmpX509Cert_Implementationx509certkeyclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certkeyclose", (RTS_UINTPTR)x509certkeyclose, 1, 0x6A598D05, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509certkeyclose
	#define EXT_x509certkeyclose
	#define GET_x509certkeyclose(fl)  CAL_CMGETAPI( "x509certkeyclose" ) 
	#define CAL_x509certkeyclose  x509certkeyclose
	#define CHK_x509certkeyclose  TRUE
	#define EXP_x509certkeyclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certkeyclose", (RTS_UINTPTR)x509certkeyclose, 1, 0x6A598D05, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509certkeyclose  PFX509CERTKEYCLOSE_IEC pfx509certkeyclose;
	#define EXT_x509certkeyclose  extern PFX509CERTKEYCLOSE_IEC pfx509certkeyclose;
	#define GET_x509certkeyclose(fl)  s_pfCMGetAPI2( "x509certkeyclose", (RTS_VOID_FCTPTR *)&pfx509certkeyclose, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x6A598D05, 0x03050F00)
	#define CAL_x509certkeyclose  pfx509certkeyclose
	#define CHK_x509certkeyclose  (pfx509certkeyclose != NULL)
	#define EXP_x509certkeyclose   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certkeyclose", (RTS_UINTPTR)x509certkeyclose, 1, 0x6A598D05, 0x03050F00) 
#endif


/**
 * <description>x509certstoreaddcert</description>
 */
typedef struct tagx509certstoreaddcert_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RTS_IEC_HANDLE hBackend;			/* VAR_INPUT */	
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	
	RTS_IEC_INT trustLevel;				/* VAR_INPUT, Enum: RTSCERTTRUSTLEVEL */
	RTS_IEC_RESULT X509CertStoreAddCert;	/* VAR_OUTPUT */	
} x509certstoreaddcert_struct;

void CDECL CDECL_EXT x509certstoreaddcert(x509certstoreaddcert_struct *p);
typedef void (CDECL CDECL_EXT* PFX509CERTSTOREADDCERT_IEC) (x509certstoreaddcert_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509CERTSTOREADDCERT_NOTIMPLEMENTED)
	#define USE_x509certstoreaddcert
	#define EXT_x509certstoreaddcert
	#define GET_x509certstoreaddcert(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509certstoreaddcert(p0) 
	#define CHK_x509certstoreaddcert  FALSE
	#define EXP_x509certstoreaddcert  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509certstoreaddcert
	#define EXT_x509certstoreaddcert
	#define GET_x509certstoreaddcert(fl)  CAL_CMGETAPI( "x509certstoreaddcert" ) 
	#define CAL_x509certstoreaddcert  x509certstoreaddcert
	#define CHK_x509certstoreaddcert  TRUE
	#define EXP_x509certstoreaddcert  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoreaddcert", (RTS_UINTPTR)x509certstoreaddcert, 1, 0x690E5D79, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509certstoreaddcert
	#define EXT_x509certstoreaddcert
	#define GET_x509certstoreaddcert(fl)  CAL_CMGETAPI( "x509certstoreaddcert" ) 
	#define CAL_x509certstoreaddcert  x509certstoreaddcert
	#define CHK_x509certstoreaddcert  TRUE
	#define EXP_x509certstoreaddcert  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoreaddcert", (RTS_UINTPTR)x509certstoreaddcert, 1, 0x690E5D79, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509certstoreaddcert
	#define EXT_CmpX509Cert_Implementationx509certstoreaddcert
	#define GET_CmpX509Cert_Implementationx509certstoreaddcert  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509certstoreaddcert  x509certstoreaddcert
	#define CHK_CmpX509Cert_Implementationx509certstoreaddcert  TRUE
	#define EXP_CmpX509Cert_Implementationx509certstoreaddcert  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoreaddcert", (RTS_UINTPTR)x509certstoreaddcert, 1, 0x690E5D79, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509certstoreaddcert
	#define EXT_x509certstoreaddcert
	#define GET_x509certstoreaddcert(fl)  CAL_CMGETAPI( "x509certstoreaddcert" ) 
	#define CAL_x509certstoreaddcert  x509certstoreaddcert
	#define CHK_x509certstoreaddcert  TRUE
	#define EXP_x509certstoreaddcert  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoreaddcert", (RTS_UINTPTR)x509certstoreaddcert, 1, 0x690E5D79, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509certstoreaddcert  PFX509CERTSTOREADDCERT_IEC pfx509certstoreaddcert;
	#define EXT_x509certstoreaddcert  extern PFX509CERTSTOREADDCERT_IEC pfx509certstoreaddcert;
	#define GET_x509certstoreaddcert(fl)  s_pfCMGetAPI2( "x509certstoreaddcert", (RTS_VOID_FCTPTR *)&pfx509certstoreaddcert, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x690E5D79, 0x03050F00)
	#define CAL_x509certstoreaddcert  pfx509certstoreaddcert
	#define CHK_x509certstoreaddcert  (pfx509certstoreaddcert != NULL)
	#define EXP_x509certstoreaddcert   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoreaddcert", (RTS_UINTPTR)x509certstoreaddcert, 1, 0x690E5D79, 0x03050F00) 
#endif


/**
 * <description>x509certstoreclose</description>
 */
typedef struct tagx509certstoreclose_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RTS_IEC_RESULT X509CertStoreClose;	/* VAR_OUTPUT */	
} x509certstoreclose_struct;

void CDECL CDECL_EXT x509certstoreclose(x509certstoreclose_struct *p);
typedef void (CDECL CDECL_EXT* PFX509CERTSTORECLOSE_IEC) (x509certstoreclose_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509CERTSTORECLOSE_NOTIMPLEMENTED)
	#define USE_x509certstoreclose
	#define EXT_x509certstoreclose
	#define GET_x509certstoreclose(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509certstoreclose(p0) 
	#define CHK_x509certstoreclose  FALSE
	#define EXP_x509certstoreclose  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509certstoreclose
	#define EXT_x509certstoreclose
	#define GET_x509certstoreclose(fl)  CAL_CMGETAPI( "x509certstoreclose" ) 
	#define CAL_x509certstoreclose  x509certstoreclose
	#define CHK_x509certstoreclose  TRUE
	#define EXP_x509certstoreclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoreclose", (RTS_UINTPTR)x509certstoreclose, 1, 0x048C3968, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509certstoreclose
	#define EXT_x509certstoreclose
	#define GET_x509certstoreclose(fl)  CAL_CMGETAPI( "x509certstoreclose" ) 
	#define CAL_x509certstoreclose  x509certstoreclose
	#define CHK_x509certstoreclose  TRUE
	#define EXP_x509certstoreclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoreclose", (RTS_UINTPTR)x509certstoreclose, 1, 0x048C3968, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509certstoreclose
	#define EXT_CmpX509Cert_Implementationx509certstoreclose
	#define GET_CmpX509Cert_Implementationx509certstoreclose  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509certstoreclose  x509certstoreclose
	#define CHK_CmpX509Cert_Implementationx509certstoreclose  TRUE
	#define EXP_CmpX509Cert_Implementationx509certstoreclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoreclose", (RTS_UINTPTR)x509certstoreclose, 1, 0x048C3968, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509certstoreclose
	#define EXT_x509certstoreclose
	#define GET_x509certstoreclose(fl)  CAL_CMGETAPI( "x509certstoreclose" ) 
	#define CAL_x509certstoreclose  x509certstoreclose
	#define CHK_x509certstoreclose  TRUE
	#define EXP_x509certstoreclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoreclose", (RTS_UINTPTR)x509certstoreclose, 1, 0x048C3968, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509certstoreclose  PFX509CERTSTORECLOSE_IEC pfx509certstoreclose;
	#define EXT_x509certstoreclose  extern PFX509CERTSTORECLOSE_IEC pfx509certstoreclose;
	#define GET_x509certstoreclose(fl)  s_pfCMGetAPI2( "x509certstoreclose", (RTS_VOID_FCTPTR *)&pfx509certstoreclose, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x048C3968, 0x03050F00)
	#define CAL_x509certstoreclose  pfx509certstoreclose
	#define CHK_x509certstoreclose  (pfx509certstoreclose != NULL)
	#define EXP_x509certstoreclose   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoreclose", (RTS_UINTPTR)x509certstoreclose, 1, 0x048C3968, 0x03050F00) 
#endif


/**
 * <description>x509certstoregetfirstcert</description>
 */
typedef struct tagx509certstoregetfirstcert_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RTS_IEC_HANDLE hBackend;			/* VAR_INPUT */	
	RTS_IEC_INT trustLevel;				/* VAR_INPUT, Enum: RTSCERTTRUSTLEVEL */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_HANDLE X509CertStoreGetFirstCert;	/* VAR_OUTPUT */	
} x509certstoregetfirstcert_struct;

void CDECL CDECL_EXT x509certstoregetfirstcert(x509certstoregetfirstcert_struct *p);
typedef void (CDECL CDECL_EXT* PFX509CERTSTOREGETFIRSTCERT_IEC) (x509certstoregetfirstcert_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509CERTSTOREGETFIRSTCERT_NOTIMPLEMENTED)
	#define USE_x509certstoregetfirstcert
	#define EXT_x509certstoregetfirstcert
	#define GET_x509certstoregetfirstcert(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509certstoregetfirstcert(p0) 
	#define CHK_x509certstoregetfirstcert  FALSE
	#define EXP_x509certstoregetfirstcert  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509certstoregetfirstcert
	#define EXT_x509certstoregetfirstcert
	#define GET_x509certstoregetfirstcert(fl)  CAL_CMGETAPI( "x509certstoregetfirstcert" ) 
	#define CAL_x509certstoregetfirstcert  x509certstoregetfirstcert
	#define CHK_x509certstoregetfirstcert  TRUE
	#define EXP_x509certstoregetfirstcert  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoregetfirstcert", (RTS_UINTPTR)x509certstoregetfirstcert, 1, 0x9165907D, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509certstoregetfirstcert
	#define EXT_x509certstoregetfirstcert
	#define GET_x509certstoregetfirstcert(fl)  CAL_CMGETAPI( "x509certstoregetfirstcert" ) 
	#define CAL_x509certstoregetfirstcert  x509certstoregetfirstcert
	#define CHK_x509certstoregetfirstcert  TRUE
	#define EXP_x509certstoregetfirstcert  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoregetfirstcert", (RTS_UINTPTR)x509certstoregetfirstcert, 1, 0x9165907D, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509certstoregetfirstcert
	#define EXT_CmpX509Cert_Implementationx509certstoregetfirstcert
	#define GET_CmpX509Cert_Implementationx509certstoregetfirstcert  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509certstoregetfirstcert  x509certstoregetfirstcert
	#define CHK_CmpX509Cert_Implementationx509certstoregetfirstcert  TRUE
	#define EXP_CmpX509Cert_Implementationx509certstoregetfirstcert  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoregetfirstcert", (RTS_UINTPTR)x509certstoregetfirstcert, 1, 0x9165907D, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509certstoregetfirstcert
	#define EXT_x509certstoregetfirstcert
	#define GET_x509certstoregetfirstcert(fl)  CAL_CMGETAPI( "x509certstoregetfirstcert" ) 
	#define CAL_x509certstoregetfirstcert  x509certstoregetfirstcert
	#define CHK_x509certstoregetfirstcert  TRUE
	#define EXP_x509certstoregetfirstcert  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoregetfirstcert", (RTS_UINTPTR)x509certstoregetfirstcert, 1, 0x9165907D, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509certstoregetfirstcert  PFX509CERTSTOREGETFIRSTCERT_IEC pfx509certstoregetfirstcert;
	#define EXT_x509certstoregetfirstcert  extern PFX509CERTSTOREGETFIRSTCERT_IEC pfx509certstoregetfirstcert;
	#define GET_x509certstoregetfirstcert(fl)  s_pfCMGetAPI2( "x509certstoregetfirstcert", (RTS_VOID_FCTPTR *)&pfx509certstoregetfirstcert, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x9165907D, 0x03050F00)
	#define CAL_x509certstoregetfirstcert  pfx509certstoregetfirstcert
	#define CHK_x509certstoregetfirstcert  (pfx509certstoregetfirstcert != NULL)
	#define EXP_x509certstoregetfirstcert   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoregetfirstcert", (RTS_UINTPTR)x509certstoregetfirstcert, 1, 0x9165907D, 0x03050F00) 
#endif


/**
 * <description>x509certstoregetnextcert</description>
 */
typedef struct tagx509certstoregetnextcert_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RTS_IEC_HANDLE hBackend;			/* VAR_INPUT */	
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_HANDLE X509CertStoreGetNextCert;	/* VAR_OUTPUT */	
} x509certstoregetnextcert_struct;

void CDECL CDECL_EXT x509certstoregetnextcert(x509certstoregetnextcert_struct *p);
typedef void (CDECL CDECL_EXT* PFX509CERTSTOREGETNEXTCERT_IEC) (x509certstoregetnextcert_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509CERTSTOREGETNEXTCERT_NOTIMPLEMENTED)
	#define USE_x509certstoregetnextcert
	#define EXT_x509certstoregetnextcert
	#define GET_x509certstoregetnextcert(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509certstoregetnextcert(p0) 
	#define CHK_x509certstoregetnextcert  FALSE
	#define EXP_x509certstoregetnextcert  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509certstoregetnextcert
	#define EXT_x509certstoregetnextcert
	#define GET_x509certstoregetnextcert(fl)  CAL_CMGETAPI( "x509certstoregetnextcert" ) 
	#define CAL_x509certstoregetnextcert  x509certstoregetnextcert
	#define CHK_x509certstoregetnextcert  TRUE
	#define EXP_x509certstoregetnextcert  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoregetnextcert", (RTS_UINTPTR)x509certstoregetnextcert, 1, 0x894377FA, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509certstoregetnextcert
	#define EXT_x509certstoregetnextcert
	#define GET_x509certstoregetnextcert(fl)  CAL_CMGETAPI( "x509certstoregetnextcert" ) 
	#define CAL_x509certstoregetnextcert  x509certstoregetnextcert
	#define CHK_x509certstoregetnextcert  TRUE
	#define EXP_x509certstoregetnextcert  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoregetnextcert", (RTS_UINTPTR)x509certstoregetnextcert, 1, 0x894377FA, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509certstoregetnextcert
	#define EXT_CmpX509Cert_Implementationx509certstoregetnextcert
	#define GET_CmpX509Cert_Implementationx509certstoregetnextcert  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509certstoregetnextcert  x509certstoregetnextcert
	#define CHK_CmpX509Cert_Implementationx509certstoregetnextcert  TRUE
	#define EXP_CmpX509Cert_Implementationx509certstoregetnextcert  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoregetnextcert", (RTS_UINTPTR)x509certstoregetnextcert, 1, 0x894377FA, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509certstoregetnextcert
	#define EXT_x509certstoregetnextcert
	#define GET_x509certstoregetnextcert(fl)  CAL_CMGETAPI( "x509certstoregetnextcert" ) 
	#define CAL_x509certstoregetnextcert  x509certstoregetnextcert
	#define CHK_x509certstoregetnextcert  TRUE
	#define EXP_x509certstoregetnextcert  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoregetnextcert", (RTS_UINTPTR)x509certstoregetnextcert, 1, 0x894377FA, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509certstoregetnextcert  PFX509CERTSTOREGETNEXTCERT_IEC pfx509certstoregetnextcert;
	#define EXT_x509certstoregetnextcert  extern PFX509CERTSTOREGETNEXTCERT_IEC pfx509certstoregetnextcert;
	#define GET_x509certstoregetnextcert(fl)  s_pfCMGetAPI2( "x509certstoregetnextcert", (RTS_VOID_FCTPTR *)&pfx509certstoregetnextcert, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x894377FA, 0x03050F00)
	#define CAL_x509certstoregetnextcert  pfx509certstoregetnextcert
	#define CHK_x509certstoregetnextcert  (pfx509certstoregetnextcert != NULL)
	#define EXP_x509certstoregetnextcert   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoregetnextcert", (RTS_UINTPTR)x509certstoregetnextcert, 1, 0x894377FA, 0x03050F00) 
#endif


/**
 * <description>x509certstoregetregisteredcert</description>
 */
typedef struct tagx509certstoregetregisteredcert_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RTS_IEC_HANDLE hUseCase;			/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_HANDLE X509CertStoreGetRegisteredCert;	/* VAR_OUTPUT */	
} x509certstoregetregisteredcert_struct;

void CDECL CDECL_EXT x509certstoregetregisteredcert(x509certstoregetregisteredcert_struct *p);
typedef void (CDECL CDECL_EXT* PFX509CERTSTOREGETREGISTEREDCERT_IEC) (x509certstoregetregisteredcert_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509CERTSTOREGETREGISTEREDCERT_NOTIMPLEMENTED)
	#define USE_x509certstoregetregisteredcert
	#define EXT_x509certstoregetregisteredcert
	#define GET_x509certstoregetregisteredcert(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509certstoregetregisteredcert(p0) 
	#define CHK_x509certstoregetregisteredcert  FALSE
	#define EXP_x509certstoregetregisteredcert  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509certstoregetregisteredcert
	#define EXT_x509certstoregetregisteredcert
	#define GET_x509certstoregetregisteredcert(fl)  CAL_CMGETAPI( "x509certstoregetregisteredcert" ) 
	#define CAL_x509certstoregetregisteredcert  x509certstoregetregisteredcert
	#define CHK_x509certstoregetregisteredcert  TRUE
	#define EXP_x509certstoregetregisteredcert  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoregetregisteredcert", (RTS_UINTPTR)x509certstoregetregisteredcert, 1, 0x8C0F7D34, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509certstoregetregisteredcert
	#define EXT_x509certstoregetregisteredcert
	#define GET_x509certstoregetregisteredcert(fl)  CAL_CMGETAPI( "x509certstoregetregisteredcert" ) 
	#define CAL_x509certstoregetregisteredcert  x509certstoregetregisteredcert
	#define CHK_x509certstoregetregisteredcert  TRUE
	#define EXP_x509certstoregetregisteredcert  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoregetregisteredcert", (RTS_UINTPTR)x509certstoregetregisteredcert, 1, 0x8C0F7D34, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509certstoregetregisteredcert
	#define EXT_CmpX509Cert_Implementationx509certstoregetregisteredcert
	#define GET_CmpX509Cert_Implementationx509certstoregetregisteredcert  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509certstoregetregisteredcert  x509certstoregetregisteredcert
	#define CHK_CmpX509Cert_Implementationx509certstoregetregisteredcert  TRUE
	#define EXP_CmpX509Cert_Implementationx509certstoregetregisteredcert  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoregetregisteredcert", (RTS_UINTPTR)x509certstoregetregisteredcert, 1, 0x8C0F7D34, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509certstoregetregisteredcert
	#define EXT_x509certstoregetregisteredcert
	#define GET_x509certstoregetregisteredcert(fl)  CAL_CMGETAPI( "x509certstoregetregisteredcert" ) 
	#define CAL_x509certstoregetregisteredcert  x509certstoregetregisteredcert
	#define CHK_x509certstoregetregisteredcert  TRUE
	#define EXP_x509certstoregetregisteredcert  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoregetregisteredcert", (RTS_UINTPTR)x509certstoregetregisteredcert, 1, 0x8C0F7D34, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509certstoregetregisteredcert  PFX509CERTSTOREGETREGISTEREDCERT_IEC pfx509certstoregetregisteredcert;
	#define EXT_x509certstoregetregisteredcert  extern PFX509CERTSTOREGETREGISTEREDCERT_IEC pfx509certstoregetregisteredcert;
	#define GET_x509certstoregetregisteredcert(fl)  s_pfCMGetAPI2( "x509certstoregetregisteredcert", (RTS_VOID_FCTPTR *)&pfx509certstoregetregisteredcert, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x8C0F7D34, 0x03050F00)
	#define CAL_x509certstoregetregisteredcert  pfx509certstoregetregisteredcert
	#define CHK_x509certstoregetregisteredcert  (pfx509certstoregetregisteredcert != NULL)
	#define EXP_x509certstoregetregisteredcert   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoregetregisteredcert", (RTS_UINTPTR)x509certstoregetregisteredcert, 1, 0x8C0F7D34, 0x03050F00) 
#endif


/**
 * <description>x509certstoreopen</description>
 */
typedef struct tagx509certstoreopen_struct
{
	RTS_IEC_UDINT componentID;			/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_HANDLE X509CertStoreOpen;	/* VAR_OUTPUT */	
} x509certstoreopen_struct;

void CDECL CDECL_EXT x509certstoreopen(x509certstoreopen_struct *p);
typedef void (CDECL CDECL_EXT* PFX509CERTSTOREOPEN_IEC) (x509certstoreopen_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509CERTSTOREOPEN_NOTIMPLEMENTED)
	#define USE_x509certstoreopen
	#define EXT_x509certstoreopen
	#define GET_x509certstoreopen(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509certstoreopen(p0) 
	#define CHK_x509certstoreopen  FALSE
	#define EXP_x509certstoreopen  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509certstoreopen
	#define EXT_x509certstoreopen
	#define GET_x509certstoreopen(fl)  CAL_CMGETAPI( "x509certstoreopen" ) 
	#define CAL_x509certstoreopen  x509certstoreopen
	#define CHK_x509certstoreopen  TRUE
	#define EXP_x509certstoreopen  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoreopen", (RTS_UINTPTR)x509certstoreopen, 1, 0xFE7CCE6C, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509certstoreopen
	#define EXT_x509certstoreopen
	#define GET_x509certstoreopen(fl)  CAL_CMGETAPI( "x509certstoreopen" ) 
	#define CAL_x509certstoreopen  x509certstoreopen
	#define CHK_x509certstoreopen  TRUE
	#define EXP_x509certstoreopen  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoreopen", (RTS_UINTPTR)x509certstoreopen, 1, 0xFE7CCE6C, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509certstoreopen
	#define EXT_CmpX509Cert_Implementationx509certstoreopen
	#define GET_CmpX509Cert_Implementationx509certstoreopen  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509certstoreopen  x509certstoreopen
	#define CHK_CmpX509Cert_Implementationx509certstoreopen  TRUE
	#define EXP_CmpX509Cert_Implementationx509certstoreopen  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoreopen", (RTS_UINTPTR)x509certstoreopen, 1, 0xFE7CCE6C, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509certstoreopen
	#define EXT_x509certstoreopen
	#define GET_x509certstoreopen(fl)  CAL_CMGETAPI( "x509certstoreopen" ) 
	#define CAL_x509certstoreopen  x509certstoreopen
	#define CHK_x509certstoreopen  TRUE
	#define EXP_x509certstoreopen  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoreopen", (RTS_UINTPTR)x509certstoreopen, 1, 0xFE7CCE6C, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509certstoreopen  PFX509CERTSTOREOPEN_IEC pfx509certstoreopen;
	#define EXT_x509certstoreopen  extern PFX509CERTSTOREOPEN_IEC pfx509certstoreopen;
	#define GET_x509certstoreopen(fl)  s_pfCMGetAPI2( "x509certstoreopen", (RTS_VOID_FCTPTR *)&pfx509certstoreopen, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xFE7CCE6C, 0x03050F00)
	#define CAL_x509certstoreopen  pfx509certstoreopen
	#define CHK_x509certstoreopen  (pfx509certstoreopen != NULL)
	#define EXP_x509certstoreopen   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoreopen", (RTS_UINTPTR)x509certstoreopen, 1, 0xFE7CCE6C, 0x03050F00) 
#endif


/**
 * <description>x509certstoreregister</description>
 */
typedef struct tagx509certstoreregister_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RTS_IEC_UDINT cmpID;				/* VAR_INPUT */	
	RtsX509CertInfo *pCertInfo;			/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_HANDLE X509CertStoreRegister;	/* VAR_OUTPUT */	
} x509certstoreregister_struct;

void CDECL CDECL_EXT x509certstoreregister(x509certstoreregister_struct *p);
typedef void (CDECL CDECL_EXT* PFX509CERTSTOREREGISTER_IEC) (x509certstoreregister_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509CERTSTOREREGISTER_NOTIMPLEMENTED)
	#define USE_x509certstoreregister
	#define EXT_x509certstoreregister
	#define GET_x509certstoreregister(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509certstoreregister(p0) 
	#define CHK_x509certstoreregister  FALSE
	#define EXP_x509certstoreregister  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509certstoreregister
	#define EXT_x509certstoreregister
	#define GET_x509certstoreregister(fl)  CAL_CMGETAPI( "x509certstoreregister" ) 
	#define CAL_x509certstoreregister  x509certstoreregister
	#define CHK_x509certstoreregister  TRUE
	#define EXP_x509certstoreregister  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoreregister", (RTS_UINTPTR)x509certstoreregister, 1, 0x35F7F607, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509certstoreregister
	#define EXT_x509certstoreregister
	#define GET_x509certstoreregister(fl)  CAL_CMGETAPI( "x509certstoreregister" ) 
	#define CAL_x509certstoreregister  x509certstoreregister
	#define CHK_x509certstoreregister  TRUE
	#define EXP_x509certstoreregister  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoreregister", (RTS_UINTPTR)x509certstoreregister, 1, 0x35F7F607, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509certstoreregister
	#define EXT_CmpX509Cert_Implementationx509certstoreregister
	#define GET_CmpX509Cert_Implementationx509certstoreregister  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509certstoreregister  x509certstoreregister
	#define CHK_CmpX509Cert_Implementationx509certstoreregister  TRUE
	#define EXP_CmpX509Cert_Implementationx509certstoreregister  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoreregister", (RTS_UINTPTR)x509certstoreregister, 1, 0x35F7F607, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509certstoreregister
	#define EXT_x509certstoreregister
	#define GET_x509certstoreregister(fl)  CAL_CMGETAPI( "x509certstoreregister" ) 
	#define CAL_x509certstoreregister  x509certstoreregister
	#define CHK_x509certstoreregister  TRUE
	#define EXP_x509certstoreregister  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoreregister", (RTS_UINTPTR)x509certstoreregister, 1, 0x35F7F607, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509certstoreregister  PFX509CERTSTOREREGISTER_IEC pfx509certstoreregister;
	#define EXT_x509certstoreregister  extern PFX509CERTSTOREREGISTER_IEC pfx509certstoreregister;
	#define GET_x509certstoreregister(fl)  s_pfCMGetAPI2( "x509certstoreregister", (RTS_VOID_FCTPTR *)&pfx509certstoreregister, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x35F7F607, 0x03050F00)
	#define CAL_x509certstoreregister  pfx509certstoreregister
	#define CHK_x509certstoreregister  (pfx509certstoreregister != NULL)
	#define EXP_x509certstoreregister   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoreregister", (RTS_UINTPTR)x509certstoreregister, 1, 0x35F7F607, 0x03050F00) 
#endif


/**
 * <description>x509certstoreremovecert</description>
 */
typedef struct tagx509certstoreremovecert_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RTS_IEC_HANDLE hBackend;			/* VAR_INPUT */	
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	
	RTS_IEC_BOOL xRemovePrivateKey;		/* VAR_INPUT */	
	RTS_IEC_RESULT X509CertStoreRemoveCert;	/* VAR_OUTPUT */	
} x509certstoreremovecert_struct;

void CDECL CDECL_EXT x509certstoreremovecert(x509certstoreremovecert_struct *p);
typedef void (CDECL CDECL_EXT* PFX509CERTSTOREREMOVECERT_IEC) (x509certstoreremovecert_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509CERTSTOREREMOVECERT_NOTIMPLEMENTED)
	#define USE_x509certstoreremovecert
	#define EXT_x509certstoreremovecert
	#define GET_x509certstoreremovecert(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509certstoreremovecert(p0) 
	#define CHK_x509certstoreremovecert  FALSE
	#define EXP_x509certstoreremovecert  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509certstoreremovecert
	#define EXT_x509certstoreremovecert
	#define GET_x509certstoreremovecert(fl)  CAL_CMGETAPI( "x509certstoreremovecert" ) 
	#define CAL_x509certstoreremovecert  x509certstoreremovecert
	#define CHK_x509certstoreremovecert  TRUE
	#define EXP_x509certstoreremovecert  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoreremovecert", (RTS_UINTPTR)x509certstoreremovecert, 1, 0x0E795BC4, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509certstoreremovecert
	#define EXT_x509certstoreremovecert
	#define GET_x509certstoreremovecert(fl)  CAL_CMGETAPI( "x509certstoreremovecert" ) 
	#define CAL_x509certstoreremovecert  x509certstoreremovecert
	#define CHK_x509certstoreremovecert  TRUE
	#define EXP_x509certstoreremovecert  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoreremovecert", (RTS_UINTPTR)x509certstoreremovecert, 1, 0x0E795BC4, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509certstoreremovecert
	#define EXT_CmpX509Cert_Implementationx509certstoreremovecert
	#define GET_CmpX509Cert_Implementationx509certstoreremovecert  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509certstoreremovecert  x509certstoreremovecert
	#define CHK_CmpX509Cert_Implementationx509certstoreremovecert  TRUE
	#define EXP_CmpX509Cert_Implementationx509certstoreremovecert  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoreremovecert", (RTS_UINTPTR)x509certstoreremovecert, 1, 0x0E795BC4, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509certstoreremovecert
	#define EXT_x509certstoreremovecert
	#define GET_x509certstoreremovecert(fl)  CAL_CMGETAPI( "x509certstoreremovecert" ) 
	#define CAL_x509certstoreremovecert  x509certstoreremovecert
	#define CHK_x509certstoreremovecert  TRUE
	#define EXP_x509certstoreremovecert  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoreremovecert", (RTS_UINTPTR)x509certstoreremovecert, 1, 0x0E795BC4, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509certstoreremovecert  PFX509CERTSTOREREMOVECERT_IEC pfx509certstoreremovecert;
	#define EXT_x509certstoreremovecert  extern PFX509CERTSTOREREMOVECERT_IEC pfx509certstoreremovecert;
	#define GET_x509certstoreremovecert(fl)  s_pfCMGetAPI2( "x509certstoreremovecert", (RTS_VOID_FCTPTR *)&pfx509certstoreremovecert, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x0E795BC4, 0x03050F00)
	#define CAL_x509certstoreremovecert  pfx509certstoreremovecert
	#define CHK_x509certstoreremovecert  (pfx509certstoreremovecert != NULL)
	#define EXP_x509certstoreremovecert   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoreremovecert", (RTS_UINTPTR)x509certstoreremovecert, 1, 0x0E795BC4, 0x03050F00) 
#endif


/**
 * <description>x509certstoresearchgetfirst</description>
 */
typedef struct tagx509certstoresearchgetfirst_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RtsX509CertFilter *pFilters;		/* VAR_INPUT */	
	RTS_IEC_UDINT ui32NumOfFilters;		/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_HANDLE X509CertStoreSearchGetFirst;	/* VAR_OUTPUT */	
} x509certstoresearchgetfirst_struct;

void CDECL CDECL_EXT x509certstoresearchgetfirst(x509certstoresearchgetfirst_struct *p);
typedef void (CDECL CDECL_EXT* PFX509CERTSTORESEARCHGETFIRST_IEC) (x509certstoresearchgetfirst_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509CERTSTORESEARCHGETFIRST_NOTIMPLEMENTED)
	#define USE_x509certstoresearchgetfirst
	#define EXT_x509certstoresearchgetfirst
	#define GET_x509certstoresearchgetfirst(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509certstoresearchgetfirst(p0) 
	#define CHK_x509certstoresearchgetfirst  FALSE
	#define EXP_x509certstoresearchgetfirst  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509certstoresearchgetfirst
	#define EXT_x509certstoresearchgetfirst
	#define GET_x509certstoresearchgetfirst(fl)  CAL_CMGETAPI( "x509certstoresearchgetfirst" ) 
	#define CAL_x509certstoresearchgetfirst  x509certstoresearchgetfirst
	#define CHK_x509certstoresearchgetfirst  TRUE
	#define EXP_x509certstoresearchgetfirst  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoresearchgetfirst", (RTS_UINTPTR)x509certstoresearchgetfirst, 1, 0, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509certstoresearchgetfirst
	#define EXT_x509certstoresearchgetfirst
	#define GET_x509certstoresearchgetfirst(fl)  CAL_CMGETAPI( "x509certstoresearchgetfirst" ) 
	#define CAL_x509certstoresearchgetfirst  x509certstoresearchgetfirst
	#define CHK_x509certstoresearchgetfirst  TRUE
	#define EXP_x509certstoresearchgetfirst  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoresearchgetfirst", (RTS_UINTPTR)x509certstoresearchgetfirst, 1, 0, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509certstoresearchgetfirst
	#define EXT_CmpX509Cert_Implementationx509certstoresearchgetfirst
	#define GET_CmpX509Cert_Implementationx509certstoresearchgetfirst  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509certstoresearchgetfirst  x509certstoresearchgetfirst
	#define CHK_CmpX509Cert_Implementationx509certstoresearchgetfirst  TRUE
	#define EXP_CmpX509Cert_Implementationx509certstoresearchgetfirst  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoresearchgetfirst", (RTS_UINTPTR)x509certstoresearchgetfirst, 1, 0, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509certstoresearchgetfirst
	#define EXT_x509certstoresearchgetfirst
	#define GET_x509certstoresearchgetfirst(fl)  CAL_CMGETAPI( "x509certstoresearchgetfirst" ) 
	#define CAL_x509certstoresearchgetfirst  x509certstoresearchgetfirst
	#define CHK_x509certstoresearchgetfirst  TRUE
	#define EXP_x509certstoresearchgetfirst  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoresearchgetfirst", (RTS_UINTPTR)x509certstoresearchgetfirst, 1, 0, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509certstoresearchgetfirst  PFX509CERTSTORESEARCHGETFIRST_IEC pfx509certstoresearchgetfirst;
	#define EXT_x509certstoresearchgetfirst  extern PFX509CERTSTORESEARCHGETFIRST_IEC pfx509certstoresearchgetfirst;
	#define GET_x509certstoresearchgetfirst(fl)  s_pfCMGetAPI2( "x509certstoresearchgetfirst", (RTS_VOID_FCTPTR *)&pfx509certstoresearchgetfirst, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0, 0x03050F00)
	#define CAL_x509certstoresearchgetfirst  pfx509certstoresearchgetfirst
	#define CHK_x509certstoresearchgetfirst  (pfx509certstoresearchgetfirst != NULL)
	#define EXP_x509certstoresearchgetfirst   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoresearchgetfirst", (RTS_UINTPTR)x509certstoresearchgetfirst, 1, 0, 0x03050F00) 
#endif


/**
 * <description>x509certstoresearchgetnext</description>
 */
typedef struct tagx509certstoresearchgetnext_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	
	RtsX509CertFilter *pFilters;		/* VAR_INPUT */	
	RTS_IEC_UDINT ui32NumOfFilters;		/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_HANDLE X509CertStoreSearchGetNext;	/* VAR_OUTPUT */	
} x509certstoresearchgetnext_struct;

void CDECL CDECL_EXT x509certstoresearchgetnext(x509certstoresearchgetnext_struct *p);
typedef void (CDECL CDECL_EXT* PFX509CERTSTORESEARCHGETNEXT_IEC) (x509certstoresearchgetnext_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509CERTSTORESEARCHGETNEXT_NOTIMPLEMENTED)
	#define USE_x509certstoresearchgetnext
	#define EXT_x509certstoresearchgetnext
	#define GET_x509certstoresearchgetnext(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509certstoresearchgetnext(p0) 
	#define CHK_x509certstoresearchgetnext  FALSE
	#define EXP_x509certstoresearchgetnext  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509certstoresearchgetnext
	#define EXT_x509certstoresearchgetnext
	#define GET_x509certstoresearchgetnext(fl)  CAL_CMGETAPI( "x509certstoresearchgetnext" ) 
	#define CAL_x509certstoresearchgetnext  x509certstoresearchgetnext
	#define CHK_x509certstoresearchgetnext  TRUE
	#define EXP_x509certstoresearchgetnext  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoresearchgetnext", (RTS_UINTPTR)x509certstoresearchgetnext, 1, 0, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509certstoresearchgetnext
	#define EXT_x509certstoresearchgetnext
	#define GET_x509certstoresearchgetnext(fl)  CAL_CMGETAPI( "x509certstoresearchgetnext" ) 
	#define CAL_x509certstoresearchgetnext  x509certstoresearchgetnext
	#define CHK_x509certstoresearchgetnext  TRUE
	#define EXP_x509certstoresearchgetnext  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoresearchgetnext", (RTS_UINTPTR)x509certstoresearchgetnext, 1, 0, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509certstoresearchgetnext
	#define EXT_CmpX509Cert_Implementationx509certstoresearchgetnext
	#define GET_CmpX509Cert_Implementationx509certstoresearchgetnext  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509certstoresearchgetnext  x509certstoresearchgetnext
	#define CHK_CmpX509Cert_Implementationx509certstoresearchgetnext  TRUE
	#define EXP_CmpX509Cert_Implementationx509certstoresearchgetnext  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoresearchgetnext", (RTS_UINTPTR)x509certstoresearchgetnext, 1, 0, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509certstoresearchgetnext
	#define EXT_x509certstoresearchgetnext
	#define GET_x509certstoresearchgetnext(fl)  CAL_CMGETAPI( "x509certstoresearchgetnext" ) 
	#define CAL_x509certstoresearchgetnext  x509certstoresearchgetnext
	#define CHK_x509certstoresearchgetnext  TRUE
	#define EXP_x509certstoresearchgetnext  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoresearchgetnext", (RTS_UINTPTR)x509certstoresearchgetnext, 1, 0, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509certstoresearchgetnext  PFX509CERTSTORESEARCHGETNEXT_IEC pfx509certstoresearchgetnext;
	#define EXT_x509certstoresearchgetnext  extern PFX509CERTSTORESEARCHGETNEXT_IEC pfx509certstoresearchgetnext;
	#define GET_x509certstoresearchgetnext(fl)  s_pfCMGetAPI2( "x509certstoresearchgetnext", (RTS_VOID_FCTPTR *)&pfx509certstoresearchgetnext, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0, 0x03050F00)
	#define CAL_x509certstoresearchgetnext  pfx509certstoresearchgetnext
	#define CHK_x509certstoresearchgetnext  (pfx509certstoresearchgetnext != NULL)
	#define EXP_x509certstoresearchgetnext   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoresearchgetnext", (RTS_UINTPTR)x509certstoresearchgetnext, 1, 0, 0x03050F00) 
#endif


/**
 * <description>x509certstoreunregister</description>
 */
typedef struct tagx509certstoreunregister_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RTS_IEC_HANDLE hRegisteredComponent;	/* VAR_INPUT */	
	RTS_IEC_RESULT X509CertStoreUnregister;	/* VAR_OUTPUT */	
} x509certstoreunregister_struct;

void CDECL CDECL_EXT x509certstoreunregister(x509certstoreunregister_struct *p);
typedef void (CDECL CDECL_EXT* PFX509CERTSTOREUNREGISTER_IEC) (x509certstoreunregister_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509CERTSTOREUNREGISTER_NOTIMPLEMENTED)
	#define USE_x509certstoreunregister
	#define EXT_x509certstoreunregister
	#define GET_x509certstoreunregister(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509certstoreunregister(p0) 
	#define CHK_x509certstoreunregister  FALSE
	#define EXP_x509certstoreunregister  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509certstoreunregister
	#define EXT_x509certstoreunregister
	#define GET_x509certstoreunregister(fl)  CAL_CMGETAPI( "x509certstoreunregister" ) 
	#define CAL_x509certstoreunregister  x509certstoreunregister
	#define CHK_x509certstoreunregister  TRUE
	#define EXP_x509certstoreunregister  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoreunregister", (RTS_UINTPTR)x509certstoreunregister, 1, 0xE41C13F3, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509certstoreunregister
	#define EXT_x509certstoreunregister
	#define GET_x509certstoreunregister(fl)  CAL_CMGETAPI( "x509certstoreunregister" ) 
	#define CAL_x509certstoreunregister  x509certstoreunregister
	#define CHK_x509certstoreunregister  TRUE
	#define EXP_x509certstoreunregister  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoreunregister", (RTS_UINTPTR)x509certstoreunregister, 1, 0xE41C13F3, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509certstoreunregister
	#define EXT_CmpX509Cert_Implementationx509certstoreunregister
	#define GET_CmpX509Cert_Implementationx509certstoreunregister  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509certstoreunregister  x509certstoreunregister
	#define CHK_CmpX509Cert_Implementationx509certstoreunregister  TRUE
	#define EXP_CmpX509Cert_Implementationx509certstoreunregister  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoreunregister", (RTS_UINTPTR)x509certstoreunregister, 1, 0xE41C13F3, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509certstoreunregister
	#define EXT_x509certstoreunregister
	#define GET_x509certstoreunregister(fl)  CAL_CMGETAPI( "x509certstoreunregister" ) 
	#define CAL_x509certstoreunregister  x509certstoreunregister
	#define CHK_x509certstoreunregister  TRUE
	#define EXP_x509certstoreunregister  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoreunregister", (RTS_UINTPTR)x509certstoreunregister, 1, 0xE41C13F3, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509certstoreunregister  PFX509CERTSTOREUNREGISTER_IEC pfx509certstoreunregister;
	#define EXT_x509certstoreunregister  extern PFX509CERTSTOREUNREGISTER_IEC pfx509certstoreunregister;
	#define GET_x509certstoreunregister(fl)  s_pfCMGetAPI2( "x509certstoreunregister", (RTS_VOID_FCTPTR *)&pfx509certstoreunregister, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xE41C13F3, 0x03050F00)
	#define CAL_x509certstoreunregister  pfx509certstoreunregister
	#define CHK_x509certstoreunregister  (pfx509certstoreunregister != NULL)
	#define EXP_x509certstoreunregister   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certstoreunregister", (RTS_UINTPTR)x509certstoreunregister, 1, 0xE41C13F3, 0x03050F00) 
#endif


/**
 * <description>x509certverify</description>
 */
typedef struct tagx509certverify_struct
{
	RTS_IEC_HANDLE hCertStore;			/* VAR_INPUT */	
	RTS_IEC_HANDLE hCert;				/* VAR_INPUT */	
	RTS_IEC_RESULT X509CertVerify;		/* VAR_OUTPUT */	
} x509certverify_struct;

void CDECL CDECL_EXT x509certverify(x509certverify_struct *p);
typedef void (CDECL CDECL_EXT* PFX509CERTVERIFY_IEC) (x509certverify_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509CERTVERIFY_NOTIMPLEMENTED)
	#define USE_x509certverify
	#define EXT_x509certverify
	#define GET_x509certverify(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509certverify(p0) 
	#define CHK_x509certverify  FALSE
	#define EXP_x509certverify  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509certverify
	#define EXT_x509certverify
	#define GET_x509certverify(fl)  CAL_CMGETAPI( "x509certverify" ) 
	#define CAL_x509certverify  x509certverify
	#define CHK_x509certverify  TRUE
	#define EXP_x509certverify  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certverify", (RTS_UINTPTR)x509certverify, 1, 0x9822EB29, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509certverify
	#define EXT_x509certverify
	#define GET_x509certverify(fl)  CAL_CMGETAPI( "x509certverify" ) 
	#define CAL_x509certverify  x509certverify
	#define CHK_x509certverify  TRUE
	#define EXP_x509certverify  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certverify", (RTS_UINTPTR)x509certverify, 1, 0x9822EB29, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509certverify
	#define EXT_CmpX509Cert_Implementationx509certverify
	#define GET_CmpX509Cert_Implementationx509certverify  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509certverify  x509certverify
	#define CHK_CmpX509Cert_Implementationx509certverify  TRUE
	#define EXP_CmpX509Cert_Implementationx509certverify  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certverify", (RTS_UINTPTR)x509certverify, 1, 0x9822EB29, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509certverify
	#define EXT_x509certverify
	#define GET_x509certverify(fl)  CAL_CMGETAPI( "x509certverify" ) 
	#define CAL_x509certverify  x509certverify
	#define CHK_x509certverify  TRUE
	#define EXP_x509certverify  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certverify", (RTS_UINTPTR)x509certverify, 1, 0x9822EB29, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509certverify  PFX509CERTVERIFY_IEC pfx509certverify;
	#define EXT_x509certverify  extern PFX509CERTVERIFY_IEC pfx509certverify;
	#define GET_x509certverify(fl)  s_pfCMGetAPI2( "x509certverify", (RTS_VOID_FCTPTR *)&pfx509certverify, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x9822EB29, 0x03050F00)
	#define CAL_x509certverify  pfx509certverify
	#define CHK_x509certverify  (pfx509certverify != NULL)
	#define EXP_x509certverify   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509certverify", (RTS_UINTPTR)x509certverify, 1, 0x9822EB29, 0x03050F00) 
#endif


/**
 * Parse a certificate which is located in the memory (e.g received FROM a
 * communication partner). Once parsed the certificate is stored
 * in a temporary store. Use the function X509CertClose to close the certificate.
 * :return: Handle to the parsed certificate.
 */
typedef struct tagx509parsecertificate_struct
{
	RtsByteString *pCert;				/* VAR_INPUT */	/* Binary encoded certificate. */
	RTS_IEC_INT encoding;				/* VAR_INPUT, Enum: RTSCERTENCODING */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Result of the operation */
	RTS_IEC_HANDLE X509ParseCertificate;	/* VAR_OUTPUT */	
} x509parsecertificate_struct;

void CDECL CDECL_EXT x509parsecertificate(x509parsecertificate_struct *p);
typedef void (CDECL CDECL_EXT* PFX509PARSECERTIFICATE_IEC) (x509parsecertificate_struct *p);
#if defined(CMPX509CERT_IMPLEMENTATION_NOTIMPLEMENTED) || defined(X509PARSECERTIFICATE_NOTIMPLEMENTED)
	#define USE_x509parsecertificate
	#define EXT_x509parsecertificate
	#define GET_x509parsecertificate(fl)  ERR_NOTIMPLEMENTED
	#define CAL_x509parsecertificate(p0) 
	#define CHK_x509parsecertificate  FALSE
	#define EXP_x509parsecertificate  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_x509parsecertificate
	#define EXT_x509parsecertificate
	#define GET_x509parsecertificate(fl)  CAL_CMGETAPI( "x509parsecertificate" ) 
	#define CAL_x509parsecertificate  x509parsecertificate
	#define CHK_x509parsecertificate  TRUE
	#define EXP_x509parsecertificate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509parsecertificate", (RTS_UINTPTR)x509parsecertificate, 1, 0x01B27207, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(CMPX509CERT_IMPLEMENTATION_EXTERNAL)
	#define USE_x509parsecertificate
	#define EXT_x509parsecertificate
	#define GET_x509parsecertificate(fl)  CAL_CMGETAPI( "x509parsecertificate" ) 
	#define CAL_x509parsecertificate  x509parsecertificate
	#define CHK_x509parsecertificate  TRUE
	#define EXP_x509parsecertificate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509parsecertificate", (RTS_UINTPTR)x509parsecertificate, 1, 0x01B27207, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpX509Cert_Implementationx509parsecertificate
	#define EXT_CmpX509Cert_Implementationx509parsecertificate
	#define GET_CmpX509Cert_Implementationx509parsecertificate  ERR_OK
	#define CAL_CmpX509Cert_Implementationx509parsecertificate  x509parsecertificate
	#define CHK_CmpX509Cert_Implementationx509parsecertificate  TRUE
	#define EXP_CmpX509Cert_Implementationx509parsecertificate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509parsecertificate", (RTS_UINTPTR)x509parsecertificate, 1, 0x01B27207, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_x509parsecertificate
	#define EXT_x509parsecertificate
	#define GET_x509parsecertificate(fl)  CAL_CMGETAPI( "x509parsecertificate" ) 
	#define CAL_x509parsecertificate  x509parsecertificate
	#define CHK_x509parsecertificate  TRUE
	#define EXP_x509parsecertificate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509parsecertificate", (RTS_UINTPTR)x509parsecertificate, 1, 0x01B27207, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_x509parsecertificate  PFX509PARSECERTIFICATE_IEC pfx509parsecertificate;
	#define EXT_x509parsecertificate  extern PFX509PARSECERTIFICATE_IEC pfx509parsecertificate;
	#define GET_x509parsecertificate(fl)  s_pfCMGetAPI2( "x509parsecertificate", (RTS_VOID_FCTPTR *)&pfx509parsecertificate, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x01B27207, 0x03050F00)
	#define CAL_x509parsecertificate  pfx509parsecertificate
	#define CHK_x509parsecertificate  (pfx509parsecertificate != NULL)
	#define EXP_x509parsecertificate   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"x509parsecertificate", (RTS_UINTPTR)x509parsecertificate, 1, 0x01B27207, 0x03050F00) 
#endif


#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/




typedef struct
{
	IBase_C *pBase;
} ICmpX509Cert_Implementation_C;

#ifdef CPLUSPLUS
class ICmpX509Cert_Implementation : public IBase
{
	public:
};
	#ifndef ITF_CmpX509Cert_Implementation
		#define ITF_CmpX509Cert_Implementation static ICmpX509Cert_Implementation *pICmpX509Cert_Implementation = NULL;
	#endif
	#define EXTITF_CmpX509Cert_Implementation
#else	/*CPLUSPLUS*/
	typedef ICmpX509Cert_Implementation_C		ICmpX509Cert_Implementation;
	#ifndef ITF_CmpX509Cert_Implementation
		#define ITF_CmpX509Cert_Implementation
	#endif
	#define EXTITF_CmpX509Cert_Implementation
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_CMPX509CERT_IMPLEMENTATIONITF_H_*/
