 /**
 * <interfacename>SysSocket_Implementation</interfacename>
 * <description></description>
 *
 * <copyright></copyright>
 */


	
	
#ifndef _SYSSOCKET_IMPLEMENTATIONITF_H_
#define _SYSSOCKET_IMPLEMENTATIONITF_H_

#include "CmpStd.h"

 

 



#include "SysSocketItf.h"

/** EXTERN LIB SECTION BEGIN **/
/*  Comments are ignored for m4 compiler so restructured text can be used.  */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * | Accept the next incoming TCP connection.
 * | This functions calls the function accept of the operating system, which can accept a request to connect
 *   to a socket. A new descriptor (handle) for the socket is returned. The original socket is reset to the
 *   "listening" state (see SysSockListen).
 *
 * :return: Handle to the new accepted socket or RTS_INVALID_HANDLE if failed.
 */
typedef struct tagsyssockaccept_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Handle to the socket */
	SOCKADDRESS *pSockAddr;				/* VAR_INPUT */	/* Socket address of the client, who is connected */
	RTS_IEC_DINT *pdiSockAddrSize;		/* VAR_INPUT */	/* Pointer to size of socket address structure */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_HANDLE SysSockAccept;		/* VAR_OUTPUT */	
} syssockaccept_struct;

void CDECL CDECL_EXT syssockaccept(syssockaccept_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKACCEPT_IEC) (syssockaccept_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKACCEPT_NOTIMPLEMENTED)
	#define USE_syssockaccept
	#define EXT_syssockaccept
	#define GET_syssockaccept(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockaccept(p0) 
	#define CHK_syssockaccept  FALSE
	#define EXP_syssockaccept  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockaccept
	#define EXT_syssockaccept
	#define GET_syssockaccept(fl)  CAL_CMGETAPI( "syssockaccept" ) 
	#define CAL_syssockaccept  syssockaccept
	#define CHK_syssockaccept  TRUE
	#define EXP_syssockaccept  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockaccept", (RTS_UINTPTR)syssockaccept, 1, RTSITF_GET_SIGNATURE(0, 0xCA6B3076), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockaccept
	#define EXT_syssockaccept
	#define GET_syssockaccept(fl)  CAL_CMGETAPI( "syssockaccept" ) 
	#define CAL_syssockaccept  syssockaccept
	#define CHK_syssockaccept  TRUE
	#define EXP_syssockaccept  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockaccept", (RTS_UINTPTR)syssockaccept, 1, RTSITF_GET_SIGNATURE(0, 0xCA6B3076), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockaccept
	#define EXT_SysSocket_Implementationsyssockaccept
	#define GET_SysSocket_Implementationsyssockaccept  ERR_OK
	#define CAL_SysSocket_Implementationsyssockaccept  syssockaccept
	#define CHK_SysSocket_Implementationsyssockaccept  TRUE
	#define EXP_SysSocket_Implementationsyssockaccept  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockaccept", (RTS_UINTPTR)syssockaccept, 1, RTSITF_GET_SIGNATURE(0, 0xCA6B3076), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockaccept
	#define EXT_syssockaccept
	#define GET_syssockaccept(fl)  CAL_CMGETAPI( "syssockaccept" ) 
	#define CAL_syssockaccept  syssockaccept
	#define CHK_syssockaccept  TRUE
	#define EXP_syssockaccept  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockaccept", (RTS_UINTPTR)syssockaccept, 1, RTSITF_GET_SIGNATURE(0, 0xCA6B3076), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockaccept  PFSYSSOCKACCEPT_IEC pfsyssockaccept;
	#define EXT_syssockaccept  extern PFSYSSOCKACCEPT_IEC pfsyssockaccept;
	#define GET_syssockaccept(fl)  s_pfCMGetAPI2( "syssockaccept", (RTS_VOID_FCTPTR *)&pfsyssockaccept, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xCA6B3076), 0x03050F00)
	#define CAL_syssockaccept  pfsyssockaccept
	#define CHK_syssockaccept  (pfsyssockaccept != NULL)
	#define EXP_syssockaccept   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockaccept", (RTS_UINTPTR)syssockaccept, 1, RTSITF_GET_SIGNATURE(0, 0xCA6B3076), 0x03050F00) 
#endif


/**
 * | Bind a socket to a socket address and port number.
 * | This functions calls the function bind of the operating system, which will assign a local address
 *   to a socket that has already been allocated to an address by |SysSockCreate|, but not yet fixed uniquely.
 *   This is usually done previous to a call to functions like |SysSockListen| or |SysSockAccept|.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockbind_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Handle to the socket */
	SOCKADDRESS *pSockAddr;				/* VAR_INPUT */	/* Spcket address */
	RTS_IEC_DINT diSockAddrSize;		/* VAR_INPUT */	/* Size of the socket address structure */
	RTS_IEC_RESULT SysSockBind;			/* VAR_OUTPUT */	
} syssockbind_struct;

void CDECL CDECL_EXT syssockbind(syssockbind_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKBIND_IEC) (syssockbind_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKBIND_NOTIMPLEMENTED)
	#define USE_syssockbind
	#define EXT_syssockbind
	#define GET_syssockbind(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockbind(p0) 
	#define CHK_syssockbind  FALSE
	#define EXP_syssockbind  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockbind
	#define EXT_syssockbind
	#define GET_syssockbind(fl)  CAL_CMGETAPI( "syssockbind" ) 
	#define CAL_syssockbind  syssockbind
	#define CHK_syssockbind  TRUE
	#define EXP_syssockbind  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockbind", (RTS_UINTPTR)syssockbind, 1, RTSITF_GET_SIGNATURE(0, 0xCF23D531), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockbind
	#define EXT_syssockbind
	#define GET_syssockbind(fl)  CAL_CMGETAPI( "syssockbind" ) 
	#define CAL_syssockbind  syssockbind
	#define CHK_syssockbind  TRUE
	#define EXP_syssockbind  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockbind", (RTS_UINTPTR)syssockbind, 1, RTSITF_GET_SIGNATURE(0, 0xCF23D531), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockbind
	#define EXT_SysSocket_Implementationsyssockbind
	#define GET_SysSocket_Implementationsyssockbind  ERR_OK
	#define CAL_SysSocket_Implementationsyssockbind  syssockbind
	#define CHK_SysSocket_Implementationsyssockbind  TRUE
	#define EXP_SysSocket_Implementationsyssockbind  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockbind", (RTS_UINTPTR)syssockbind, 1, RTSITF_GET_SIGNATURE(0, 0xCF23D531), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockbind
	#define EXT_syssockbind
	#define GET_syssockbind(fl)  CAL_CMGETAPI( "syssockbind" ) 
	#define CAL_syssockbind  syssockbind
	#define CHK_syssockbind  TRUE
	#define EXP_syssockbind  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockbind", (RTS_UINTPTR)syssockbind, 1, RTSITF_GET_SIGNATURE(0, 0xCF23D531), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockbind  PFSYSSOCKBIND_IEC pfsyssockbind;
	#define EXT_syssockbind  extern PFSYSSOCKBIND_IEC pfsyssockbind;
	#define GET_syssockbind(fl)  s_pfCMGetAPI2( "syssockbind", (RTS_VOID_FCTPTR *)&pfsyssockbind, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xCF23D531), 0x03050F00)
	#define CAL_syssockbind  pfsyssockbind
	#define CHK_syssockbind  (pfsyssockbind != NULL)
	#define EXP_syssockbind   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockbind", (RTS_UINTPTR)syssockbind, 1, RTSITF_GET_SIGNATURE(0, 0xCF23D531), 0x03050F00) 
#endif


/**
 *  | Close a socket.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockclose_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Handle to the socket */
	RTS_IEC_RESULT SysSockClose;		/* VAR_OUTPUT */	
} syssockclose_struct;

void CDECL CDECL_EXT syssockclose(syssockclose_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKCLOSE_IEC) (syssockclose_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKCLOSE_NOTIMPLEMENTED)
	#define USE_syssockclose
	#define EXT_syssockclose
	#define GET_syssockclose(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockclose(p0) 
	#define CHK_syssockclose  FALSE
	#define EXP_syssockclose  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockclose
	#define EXT_syssockclose
	#define GET_syssockclose(fl)  CAL_CMGETAPI( "syssockclose" ) 
	#define CAL_syssockclose  syssockclose
	#define CHK_syssockclose  TRUE
	#define EXP_syssockclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockclose", (RTS_UINTPTR)syssockclose, 1, RTSITF_GET_SIGNATURE(0, 0xF72471AA), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockclose
	#define EXT_syssockclose
	#define GET_syssockclose(fl)  CAL_CMGETAPI( "syssockclose" ) 
	#define CAL_syssockclose  syssockclose
	#define CHK_syssockclose  TRUE
	#define EXP_syssockclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockclose", (RTS_UINTPTR)syssockclose, 1, RTSITF_GET_SIGNATURE(0, 0xF72471AA), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockclose
	#define EXT_SysSocket_Implementationsyssockclose
	#define GET_SysSocket_Implementationsyssockclose  ERR_OK
	#define CAL_SysSocket_Implementationsyssockclose  syssockclose
	#define CHK_SysSocket_Implementationsyssockclose  TRUE
	#define EXP_SysSocket_Implementationsyssockclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockclose", (RTS_UINTPTR)syssockclose, 1, RTSITF_GET_SIGNATURE(0, 0xF72471AA), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockclose
	#define EXT_syssockclose
	#define GET_syssockclose(fl)  CAL_CMGETAPI( "syssockclose" ) 
	#define CAL_syssockclose  syssockclose
	#define CHK_syssockclose  TRUE
	#define EXP_syssockclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockclose", (RTS_UINTPTR)syssockclose, 1, RTSITF_GET_SIGNATURE(0, 0xF72471AA), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockclose  PFSYSSOCKCLOSE_IEC pfsyssockclose;
	#define EXT_syssockclose  extern PFSYSSOCKCLOSE_IEC pfsyssockclose;
	#define GET_syssockclose(fl)  s_pfCMGetAPI2( "syssockclose", (RTS_VOID_FCTPTR *)&pfsyssockclose, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xF72471AA), 0x03050F00)
	#define CAL_syssockclose  pfsyssockclose
	#define CHK_syssockclose  (pfsyssockclose != NULL)
	#define EXP_syssockclose   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockclose", (RTS_UINTPTR)syssockclose, 1, RTSITF_GET_SIGNATURE(0, 0xF72471AA), 0x03050F00) 
#endif


/**
 * | Close a UDP socket. Handle must be retrieved by |SysSockCreateUdp| !
 * | This function calls the function closesocket of the operating system to close a socket
 *   working with the user datagram protocol UDP.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockcloseudp_struct
{
	RTS_IEC_HANDLE hSocketUdp;			/* VAR_INPUT */	/* Handle to the UDP socket. Must be opened with |SysSockCreateUdp| ! */
	RTS_IEC_RESULT SysSockCloseUdp;		/* VAR_OUTPUT */	
} syssockcloseudp_struct;

void CDECL CDECL_EXT syssockcloseudp(syssockcloseudp_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKCLOSEUDP_IEC) (syssockcloseudp_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKCLOSEUDP_NOTIMPLEMENTED)
	#define USE_syssockcloseudp
	#define EXT_syssockcloseudp
	#define GET_syssockcloseudp(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockcloseudp(p0) 
	#define CHK_syssockcloseudp  FALSE
	#define EXP_syssockcloseudp  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockcloseudp
	#define EXT_syssockcloseudp
	#define GET_syssockcloseudp(fl)  CAL_CMGETAPI( "syssockcloseudp" ) 
	#define CAL_syssockcloseudp  syssockcloseudp
	#define CHK_syssockcloseudp  TRUE
	#define EXP_syssockcloseudp  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockcloseudp", (RTS_UINTPTR)syssockcloseudp, 1, RTSITF_GET_SIGNATURE(0, 0x6978E3CC), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockcloseudp
	#define EXT_syssockcloseudp
	#define GET_syssockcloseudp(fl)  CAL_CMGETAPI( "syssockcloseudp" ) 
	#define CAL_syssockcloseudp  syssockcloseudp
	#define CHK_syssockcloseudp  TRUE
	#define EXP_syssockcloseudp  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockcloseudp", (RTS_UINTPTR)syssockcloseudp, 1, RTSITF_GET_SIGNATURE(0, 0x6978E3CC), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockcloseudp
	#define EXT_SysSocket_Implementationsyssockcloseudp
	#define GET_SysSocket_Implementationsyssockcloseudp  ERR_OK
	#define CAL_SysSocket_Implementationsyssockcloseudp  syssockcloseudp
	#define CHK_SysSocket_Implementationsyssockcloseudp  TRUE
	#define EXP_SysSocket_Implementationsyssockcloseudp  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockcloseudp", (RTS_UINTPTR)syssockcloseudp, 1, RTSITF_GET_SIGNATURE(0, 0x6978E3CC), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockcloseudp
	#define EXT_syssockcloseudp
	#define GET_syssockcloseudp(fl)  CAL_CMGETAPI( "syssockcloseudp" ) 
	#define CAL_syssockcloseudp  syssockcloseudp
	#define CHK_syssockcloseudp  TRUE
	#define EXP_syssockcloseudp  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockcloseudp", (RTS_UINTPTR)syssockcloseudp, 1, RTSITF_GET_SIGNATURE(0, 0x6978E3CC), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockcloseudp  PFSYSSOCKCLOSEUDP_IEC pfsyssockcloseudp;
	#define EXT_syssockcloseudp  extern PFSYSSOCKCLOSEUDP_IEC pfsyssockcloseudp;
	#define GET_syssockcloseudp(fl)  s_pfCMGetAPI2( "syssockcloseudp", (RTS_VOID_FCTPTR *)&pfsyssockcloseudp, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x6978E3CC), 0x03050F00)
	#define CAL_syssockcloseudp  pfsyssockcloseudp
	#define CHK_syssockcloseudp  (pfsyssockcloseudp != NULL)
	#define EXP_syssockcloseudp   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockcloseudp", (RTS_UINTPTR)syssockcloseudp, 1, RTSITF_GET_SIGNATURE(0, 0x6978E3CC), 0x03050F00) 
#endif


/**
 * | Connect as a client to a TCP server.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockconnect_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Handle to the socket */
	SOCKADDRESS *pSockAddr;				/* VAR_INPUT */	/* Socket address of the server to connect to */
	RTS_IEC_DINT diSockAddrSize;		/* VAR_INPUT */	/* Size of socket address structure */
	RTS_IEC_RESULT SysSockConnect;		/* VAR_OUTPUT */	
} syssockconnect_struct;

void CDECL CDECL_EXT syssockconnect(syssockconnect_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKCONNECT_IEC) (syssockconnect_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKCONNECT_NOTIMPLEMENTED)
	#define USE_syssockconnect
	#define EXT_syssockconnect
	#define GET_syssockconnect(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockconnect(p0) 
	#define CHK_syssockconnect  FALSE
	#define EXP_syssockconnect  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockconnect
	#define EXT_syssockconnect
	#define GET_syssockconnect(fl)  CAL_CMGETAPI( "syssockconnect" ) 
	#define CAL_syssockconnect  syssockconnect
	#define CHK_syssockconnect  TRUE
	#define EXP_syssockconnect  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockconnect", (RTS_UINTPTR)syssockconnect, 1, RTSITF_GET_SIGNATURE(0, 0x765FD3AB), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockconnect
	#define EXT_syssockconnect
	#define GET_syssockconnect(fl)  CAL_CMGETAPI( "syssockconnect" ) 
	#define CAL_syssockconnect  syssockconnect
	#define CHK_syssockconnect  TRUE
	#define EXP_syssockconnect  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockconnect", (RTS_UINTPTR)syssockconnect, 1, RTSITF_GET_SIGNATURE(0, 0x765FD3AB), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockconnect
	#define EXT_SysSocket_Implementationsyssockconnect
	#define GET_SysSocket_Implementationsyssockconnect  ERR_OK
	#define CAL_SysSocket_Implementationsyssockconnect  syssockconnect
	#define CHK_SysSocket_Implementationsyssockconnect  TRUE
	#define EXP_SysSocket_Implementationsyssockconnect  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockconnect", (RTS_UINTPTR)syssockconnect, 1, RTSITF_GET_SIGNATURE(0, 0x765FD3AB), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockconnect
	#define EXT_syssockconnect
	#define GET_syssockconnect(fl)  CAL_CMGETAPI( "syssockconnect" ) 
	#define CAL_syssockconnect  syssockconnect
	#define CHK_syssockconnect  TRUE
	#define EXP_syssockconnect  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockconnect", (RTS_UINTPTR)syssockconnect, 1, RTSITF_GET_SIGNATURE(0, 0x765FD3AB), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockconnect  PFSYSSOCKCONNECT_IEC pfsyssockconnect;
	#define EXT_syssockconnect  extern PFSYSSOCKCONNECT_IEC pfsyssockconnect;
	#define GET_syssockconnect(fl)  s_pfCMGetAPI2( "syssockconnect", (RTS_VOID_FCTPTR *)&pfsyssockconnect, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x765FD3AB), 0x03050F00)
	#define CAL_syssockconnect  pfsyssockconnect
	#define CHK_syssockconnect  (pfsyssockconnect != NULL)
	#define EXP_syssockconnect   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockconnect", (RTS_UINTPTR)syssockconnect, 1, RTSITF_GET_SIGNATURE(0, 0x765FD3AB), 0x03050F00) 
#endif


/**
 * Create a new socket and return the socket handle.
 * :return: Handle to the new socket. The return is a descriptor (handle) of the new socket,
 * which is required as input parameter by other library functions like |SysSockBind|, |SysSockConnect| etc.
 */
typedef struct tagsyssockcreate_struct
{
	RTS_IEC_INT iAddressFamily;			/* VAR_INPUT */	/* Socket address family */
	RTS_IEC_DINT diType;				/* VAR_INPUT */	/* Socket type */
	RTS_IEC_DINT diProtocol;			/* VAR_INPUT */	/* Socket protocol */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_HANDLE SysSockCreate;		/* VAR_OUTPUT */	
} syssockcreate_struct;

void CDECL CDECL_EXT syssockcreate(syssockcreate_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKCREATE_IEC) (syssockcreate_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKCREATE_NOTIMPLEMENTED)
	#define USE_syssockcreate
	#define EXT_syssockcreate
	#define GET_syssockcreate(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockcreate(p0) 
	#define CHK_syssockcreate  FALSE
	#define EXP_syssockcreate  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockcreate
	#define EXT_syssockcreate
	#define GET_syssockcreate(fl)  CAL_CMGETAPI( "syssockcreate" ) 
	#define CAL_syssockcreate  syssockcreate
	#define CHK_syssockcreate  TRUE
	#define EXP_syssockcreate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockcreate", (RTS_UINTPTR)syssockcreate, 1, RTSITF_GET_SIGNATURE(0, 0xE8829CB3), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockcreate
	#define EXT_syssockcreate
	#define GET_syssockcreate(fl)  CAL_CMGETAPI( "syssockcreate" ) 
	#define CAL_syssockcreate  syssockcreate
	#define CHK_syssockcreate  TRUE
	#define EXP_syssockcreate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockcreate", (RTS_UINTPTR)syssockcreate, 1, RTSITF_GET_SIGNATURE(0, 0xE8829CB3), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockcreate
	#define EXT_SysSocket_Implementationsyssockcreate
	#define GET_SysSocket_Implementationsyssockcreate  ERR_OK
	#define CAL_SysSocket_Implementationsyssockcreate  syssockcreate
	#define CHK_SysSocket_Implementationsyssockcreate  TRUE
	#define EXP_SysSocket_Implementationsyssockcreate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockcreate", (RTS_UINTPTR)syssockcreate, 1, RTSITF_GET_SIGNATURE(0, 0xE8829CB3), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockcreate
	#define EXT_syssockcreate
	#define GET_syssockcreate(fl)  CAL_CMGETAPI( "syssockcreate" ) 
	#define CAL_syssockcreate  syssockcreate
	#define CHK_syssockcreate  TRUE
	#define EXP_syssockcreate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockcreate", (RTS_UINTPTR)syssockcreate, 1, RTSITF_GET_SIGNATURE(0, 0xE8829CB3), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockcreate  PFSYSSOCKCREATE_IEC pfsyssockcreate;
	#define EXT_syssockcreate  extern PFSYSSOCKCREATE_IEC pfsyssockcreate;
	#define GET_syssockcreate(fl)  s_pfCMGetAPI2( "syssockcreate", (RTS_VOID_FCTPTR *)&pfsyssockcreate, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xE8829CB3), 0x03050F00)
	#define CAL_syssockcreate  pfsyssockcreate
	#define CHK_syssockcreate  (pfsyssockcreate != NULL)
	#define EXP_syssockcreate   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockcreate", (RTS_UINTPTR)syssockcreate, 1, RTSITF_GET_SIGNATURE(0, 0xE8829CB3), 0x03050F00) 
#endif


/**
 * | Higher level function, to create a complete UDP socket.
 * | The socket will make use of the user data protocol UDP.
 * :return: Handle to the UDP socket
 */
typedef struct tagsyssockcreateudp_struct
{
	RTS_IEC_DINT diSendPort;			/* VAR_INPUT */	/* Port number to send (host byte order) */
	RTS_IEC_DINT diRecvPort;			/* VAR_INPUT */	/* Port number to receive (host byte order) */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_HANDLE SysSockCreateUdp;	/* VAR_OUTPUT */	
} syssockcreateudp_struct;

void CDECL CDECL_EXT syssockcreateudp(syssockcreateudp_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKCREATEUDP_IEC) (syssockcreateudp_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKCREATEUDP_NOTIMPLEMENTED)
	#define USE_syssockcreateudp
	#define EXT_syssockcreateudp
	#define GET_syssockcreateudp(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockcreateudp(p0) 
	#define CHK_syssockcreateudp  FALSE
	#define EXP_syssockcreateudp  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockcreateudp
	#define EXT_syssockcreateudp
	#define GET_syssockcreateudp(fl)  CAL_CMGETAPI( "syssockcreateudp" ) 
	#define CAL_syssockcreateudp  syssockcreateudp
	#define CHK_syssockcreateudp  TRUE
	#define EXP_syssockcreateudp  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockcreateudp", (RTS_UINTPTR)syssockcreateudp, 1, RTSITF_GET_SIGNATURE(0, 0x4A894324), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockcreateudp
	#define EXT_syssockcreateudp
	#define GET_syssockcreateudp(fl)  CAL_CMGETAPI( "syssockcreateudp" ) 
	#define CAL_syssockcreateudp  syssockcreateudp
	#define CHK_syssockcreateudp  TRUE
	#define EXP_syssockcreateudp  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockcreateudp", (RTS_UINTPTR)syssockcreateudp, 1, RTSITF_GET_SIGNATURE(0, 0x4A894324), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockcreateudp
	#define EXT_SysSocket_Implementationsyssockcreateudp
	#define GET_SysSocket_Implementationsyssockcreateudp  ERR_OK
	#define CAL_SysSocket_Implementationsyssockcreateudp  syssockcreateudp
	#define CHK_SysSocket_Implementationsyssockcreateudp  TRUE
	#define EXP_SysSocket_Implementationsyssockcreateudp  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockcreateudp", (RTS_UINTPTR)syssockcreateudp, 1, RTSITF_GET_SIGNATURE(0, 0x4A894324), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockcreateudp
	#define EXT_syssockcreateudp
	#define GET_syssockcreateudp(fl)  CAL_CMGETAPI( "syssockcreateudp" ) 
	#define CAL_syssockcreateudp  syssockcreateudp
	#define CHK_syssockcreateudp  TRUE
	#define EXP_syssockcreateudp  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockcreateudp", (RTS_UINTPTR)syssockcreateudp, 1, RTSITF_GET_SIGNATURE(0, 0x4A894324), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockcreateudp  PFSYSSOCKCREATEUDP_IEC pfsyssockcreateudp;
	#define EXT_syssockcreateudp  extern PFSYSSOCKCREATEUDP_IEC pfsyssockcreateudp;
	#define GET_syssockcreateudp(fl)  s_pfCMGetAPI2( "syssockcreateudp", (RTS_VOID_FCTPTR *)&pfsyssockcreateudp, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x4A894324), 0x03050F00)
	#define CAL_syssockcreateudp  pfsyssockcreateudp
	#define CHK_syssockcreateudp  (pfsyssockcreateudp != NULL)
	#define EXP_syssockcreateudp   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockcreateudp", (RTS_UINTPTR)syssockcreateudp, 1, RTSITF_GET_SIGNATURE(0, 0x4A894324), 0x03050F00) 
#endif


/**
 * | Add a socket to a socket set.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockfdinit_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Socket to add */
	SOCKET_FD_SET *pfs;					/* VAR_INPUT */	/* Socket Set */
	RTS_IEC_RESULT SysSockFdInit;		/* VAR_OUTPUT */	
} syssockfdinit_struct;

void CDECL CDECL_EXT syssockfdinit(syssockfdinit_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKFDINIT_IEC) (syssockfdinit_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKFDINIT_NOTIMPLEMENTED)
	#define USE_syssockfdinit
	#define EXT_syssockfdinit
	#define GET_syssockfdinit(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockfdinit(p0) 
	#define CHK_syssockfdinit  FALSE
	#define EXP_syssockfdinit  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockfdinit
	#define EXT_syssockfdinit
	#define GET_syssockfdinit(fl)  CAL_CMGETAPI( "syssockfdinit" ) 
	#define CAL_syssockfdinit  syssockfdinit
	#define CHK_syssockfdinit  TRUE
	#define EXP_syssockfdinit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockfdinit", (RTS_UINTPTR)syssockfdinit, 1, 0x09C72D7D, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockfdinit
	#define EXT_syssockfdinit
	#define GET_syssockfdinit(fl)  CAL_CMGETAPI( "syssockfdinit" ) 
	#define CAL_syssockfdinit  syssockfdinit
	#define CHK_syssockfdinit  TRUE
	#define EXP_syssockfdinit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockfdinit", (RTS_UINTPTR)syssockfdinit, 1, 0x09C72D7D, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockfdinit
	#define EXT_SysSocket_Implementationsyssockfdinit
	#define GET_SysSocket_Implementationsyssockfdinit  ERR_OK
	#define CAL_SysSocket_Implementationsyssockfdinit  syssockfdinit
	#define CHK_SysSocket_Implementationsyssockfdinit  TRUE
	#define EXP_SysSocket_Implementationsyssockfdinit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockfdinit", (RTS_UINTPTR)syssockfdinit, 1, 0x09C72D7D, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockfdinit
	#define EXT_syssockfdinit
	#define GET_syssockfdinit(fl)  CAL_CMGETAPI( "syssockfdinit" ) 
	#define CAL_syssockfdinit  syssockfdinit
	#define CHK_syssockfdinit  TRUE
	#define EXP_syssockfdinit  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockfdinit", (RTS_UINTPTR)syssockfdinit, 1, 0x09C72D7D, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockfdinit  PFSYSSOCKFDINIT_IEC pfsyssockfdinit;
	#define EXT_syssockfdinit  extern PFSYSSOCKFDINIT_IEC pfsyssockfdinit;
	#define GET_syssockfdinit(fl)  s_pfCMGetAPI2( "syssockfdinit", (RTS_VOID_FCTPTR *)&pfsyssockfdinit, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x09C72D7D, 0x03050F00)
	#define CAL_syssockfdinit  pfsyssockfdinit
	#define CHK_syssockfdinit  (pfsyssockfdinit != NULL)
	#define EXP_syssockfdinit   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockfdinit", (RTS_UINTPTR)syssockfdinit, 1, 0x09C72D7D, 0x03050F00) 
#endif


/**
 * | Check if a socket is inside of a set.
 * :return: TRUE if it is inside the set, FALSE if not.
 */
typedef struct tagsyssockfdisset_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Socket to check */
	SOCKET_FD_SET *pfs;					/* VAR_INPUT */	/* Socket Set */
	RTS_IEC_BOOL SysSockFdIsset;		/* VAR_OUTPUT */	
} syssockfdisset_struct;

void CDECL CDECL_EXT syssockfdisset(syssockfdisset_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKFDISSET_IEC) (syssockfdisset_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKFDISSET_NOTIMPLEMENTED)
	#define USE_syssockfdisset
	#define EXT_syssockfdisset
	#define GET_syssockfdisset(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockfdisset(p0) 
	#define CHK_syssockfdisset  FALSE
	#define EXP_syssockfdisset  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockfdisset
	#define EXT_syssockfdisset
	#define GET_syssockfdisset(fl)  CAL_CMGETAPI( "syssockfdisset" ) 
	#define CAL_syssockfdisset  syssockfdisset
	#define CHK_syssockfdisset  TRUE
	#define EXP_syssockfdisset  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockfdisset", (RTS_UINTPTR)syssockfdisset, 1, 0x25248CA6, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockfdisset
	#define EXT_syssockfdisset
	#define GET_syssockfdisset(fl)  CAL_CMGETAPI( "syssockfdisset" ) 
	#define CAL_syssockfdisset  syssockfdisset
	#define CHK_syssockfdisset  TRUE
	#define EXP_syssockfdisset  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockfdisset", (RTS_UINTPTR)syssockfdisset, 1, 0x25248CA6, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockfdisset
	#define EXT_SysSocket_Implementationsyssockfdisset
	#define GET_SysSocket_Implementationsyssockfdisset  ERR_OK
	#define CAL_SysSocket_Implementationsyssockfdisset  syssockfdisset
	#define CHK_SysSocket_Implementationsyssockfdisset  TRUE
	#define EXP_SysSocket_Implementationsyssockfdisset  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockfdisset", (RTS_UINTPTR)syssockfdisset, 1, 0x25248CA6, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockfdisset
	#define EXT_syssockfdisset
	#define GET_syssockfdisset(fl)  CAL_CMGETAPI( "syssockfdisset" ) 
	#define CAL_syssockfdisset  syssockfdisset
	#define CHK_syssockfdisset  TRUE
	#define EXP_syssockfdisset  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockfdisset", (RTS_UINTPTR)syssockfdisset, 1, 0x25248CA6, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockfdisset  PFSYSSOCKFDISSET_IEC pfsyssockfdisset;
	#define EXT_syssockfdisset  extern PFSYSSOCKFDISSET_IEC pfsyssockfdisset;
	#define GET_syssockfdisset(fl)  s_pfCMGetAPI2( "syssockfdisset", (RTS_VOID_FCTPTR *)&pfsyssockfdisset, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x25248CA6, 0x03050F00)
	#define CAL_syssockfdisset  pfsyssockfdisset
	#define CHK_syssockfdisset  (pfsyssockfdisset != NULL)
	#define EXP_syssockfdisset   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockfdisset", (RTS_UINTPTR)syssockfdisset, 1, 0x25248CA6, 0x03050F00) 
#endif


/**
 * | Clear a Socket set.
 * :return: Returns the runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockfdzero_struct
{
	SOCKET_FD_SET *pfs;					/* VAR_INPUT */	/* Socket Set */
	RTS_IEC_RESULT SysSockFdZero;		/* VAR_OUTPUT */	
} syssockfdzero_struct;

void CDECL CDECL_EXT syssockfdzero(syssockfdzero_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKFDZERO_IEC) (syssockfdzero_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKFDZERO_NOTIMPLEMENTED)
	#define USE_syssockfdzero
	#define EXT_syssockfdzero
	#define GET_syssockfdzero(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockfdzero(p0) 
	#define CHK_syssockfdzero  FALSE
	#define EXP_syssockfdzero  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockfdzero
	#define EXT_syssockfdzero
	#define GET_syssockfdzero(fl)  CAL_CMGETAPI( "syssockfdzero" ) 
	#define CAL_syssockfdzero  syssockfdzero
	#define CHK_syssockfdzero  TRUE
	#define EXP_syssockfdzero  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockfdzero", (RTS_UINTPTR)syssockfdzero, 1, 0xD6D9FDA1, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockfdzero
	#define EXT_syssockfdzero
	#define GET_syssockfdzero(fl)  CAL_CMGETAPI( "syssockfdzero" ) 
	#define CAL_syssockfdzero  syssockfdzero
	#define CHK_syssockfdzero  TRUE
	#define EXP_syssockfdzero  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockfdzero", (RTS_UINTPTR)syssockfdzero, 1, 0xD6D9FDA1, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockfdzero
	#define EXT_SysSocket_Implementationsyssockfdzero
	#define GET_SysSocket_Implementationsyssockfdzero  ERR_OK
	#define CAL_SysSocket_Implementationsyssockfdzero  syssockfdzero
	#define CHK_SysSocket_Implementationsyssockfdzero  TRUE
	#define EXP_SysSocket_Implementationsyssockfdzero  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockfdzero", (RTS_UINTPTR)syssockfdzero, 1, 0xD6D9FDA1, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockfdzero
	#define EXT_syssockfdzero
	#define GET_syssockfdzero(fl)  CAL_CMGETAPI( "syssockfdzero" ) 
	#define CAL_syssockfdzero  syssockfdzero
	#define CHK_syssockfdzero  TRUE
	#define EXP_syssockfdzero  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockfdzero", (RTS_UINTPTR)syssockfdzero, 1, 0xD6D9FDA1, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockfdzero  PFSYSSOCKFDZERO_IEC pfsyssockfdzero;
	#define EXT_syssockfdzero  extern PFSYSSOCKFDZERO_IEC pfsyssockfdzero;
	#define GET_syssockfdzero(fl)  s_pfCMGetAPI2( "syssockfdzero", (RTS_VOID_FCTPTR *)&pfsyssockfdzero, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xD6D9FDA1, 0x03050F00)
	#define CAL_syssockfdzero  pfsyssockfdzero
	#define CHK_syssockfdzero  (pfsyssockfdzero != NULL)
	#define EXP_syssockfdzero   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockfdzero", (RTS_UINTPTR)syssockfdzero, 1, 0xD6D9FDA1, 0x03050F00) 
#endif


/**
 * | Get adapter information struct of the first network adapter.
 * | Note: It may took a while until a change of the adapter configuration is reflected here.
 * :return: Handle to be passed to SysSockGetNextAdapter() to retrieve the next adapter information.
 */
typedef struct tagsyssockgetfirstadapterinfo_struct
{
	SOCK_ADAPTER_INFORMATION *pAdapterInfo;	/* VAR_INPUT */	/* Network adapter information structure */
	RTS_IEC_UXINT *puxiAdapterInfoSize;	/* VAR_INPUT */	/* Size in bytes of |SOCK_ADAPTER_INFORMATION|; returns structure size from external implementation */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_HANDLE SysSockGetFirstAdapterInfo;	/* VAR_OUTPUT */	
} syssockgetfirstadapterinfo_struct;

void CDECL CDECL_EXT syssockgetfirstadapterinfo(syssockgetfirstadapterinfo_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKGETFIRSTADAPTERINFO_IEC) (syssockgetfirstadapterinfo_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKGETFIRSTADAPTERINFO_NOTIMPLEMENTED)
	#define USE_syssockgetfirstadapterinfo
	#define EXT_syssockgetfirstadapterinfo
	#define GET_syssockgetfirstadapterinfo(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockgetfirstadapterinfo(p0) 
	#define CHK_syssockgetfirstadapterinfo  FALSE
	#define EXP_syssockgetfirstadapterinfo  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockgetfirstadapterinfo
	#define EXT_syssockgetfirstadapterinfo
	#define GET_syssockgetfirstadapterinfo(fl)  CAL_CMGETAPI( "syssockgetfirstadapterinfo" ) 
	#define CAL_syssockgetfirstadapterinfo  syssockgetfirstadapterinfo
	#define CHK_syssockgetfirstadapterinfo  TRUE
	#define EXP_syssockgetfirstadapterinfo  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetfirstadapterinfo", (RTS_UINTPTR)syssockgetfirstadapterinfo, 1, RTSITF_GET_SIGNATURE(0x0FE33BC1, 0xF08189B5), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockgetfirstadapterinfo
	#define EXT_syssockgetfirstadapterinfo
	#define GET_syssockgetfirstadapterinfo(fl)  CAL_CMGETAPI( "syssockgetfirstadapterinfo" ) 
	#define CAL_syssockgetfirstadapterinfo  syssockgetfirstadapterinfo
	#define CHK_syssockgetfirstadapterinfo  TRUE
	#define EXP_syssockgetfirstadapterinfo  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetfirstadapterinfo", (RTS_UINTPTR)syssockgetfirstadapterinfo, 1, RTSITF_GET_SIGNATURE(0x0FE33BC1, 0xF08189B5), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockgetfirstadapterinfo
	#define EXT_SysSocket_Implementationsyssockgetfirstadapterinfo
	#define GET_SysSocket_Implementationsyssockgetfirstadapterinfo  ERR_OK
	#define CAL_SysSocket_Implementationsyssockgetfirstadapterinfo  syssockgetfirstadapterinfo
	#define CHK_SysSocket_Implementationsyssockgetfirstadapterinfo  TRUE
	#define EXP_SysSocket_Implementationsyssockgetfirstadapterinfo  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetfirstadapterinfo", (RTS_UINTPTR)syssockgetfirstadapterinfo, 1, RTSITF_GET_SIGNATURE(0x0FE33BC1, 0xF08189B5), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockgetfirstadapterinfo
	#define EXT_syssockgetfirstadapterinfo
	#define GET_syssockgetfirstadapterinfo(fl)  CAL_CMGETAPI( "syssockgetfirstadapterinfo" ) 
	#define CAL_syssockgetfirstadapterinfo  syssockgetfirstadapterinfo
	#define CHK_syssockgetfirstadapterinfo  TRUE
	#define EXP_syssockgetfirstadapterinfo  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetfirstadapterinfo", (RTS_UINTPTR)syssockgetfirstadapterinfo, 1, RTSITF_GET_SIGNATURE(0x0FE33BC1, 0xF08189B5), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockgetfirstadapterinfo  PFSYSSOCKGETFIRSTADAPTERINFO_IEC pfsyssockgetfirstadapterinfo;
	#define EXT_syssockgetfirstadapterinfo  extern PFSYSSOCKGETFIRSTADAPTERINFO_IEC pfsyssockgetfirstadapterinfo;
	#define GET_syssockgetfirstadapterinfo(fl)  s_pfCMGetAPI2( "syssockgetfirstadapterinfo", (RTS_VOID_FCTPTR *)&pfsyssockgetfirstadapterinfo, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0x0FE33BC1, 0xF08189B5), 0x03050F00)
	#define CAL_syssockgetfirstadapterinfo  pfsyssockgetfirstadapterinfo
	#define CHK_syssockgetfirstadapterinfo  (pfsyssockgetfirstadapterinfo != NULL)
	#define EXP_syssockgetfirstadapterinfo   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetfirstadapterinfo", (RTS_UINTPTR)syssockgetfirstadapterinfo, 1, RTSITF_GET_SIGNATURE(0x0FE33BC1, 0xF08189B5), 0x03050F00) 
#endif


/**
 * | Get host description specified by host name.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockgethostbyname_struct
{
	RTS_IEC_STRING *szHostName;			/* VAR_INPUT */	/* Reference to host name */
	SOCK_HOSTENT *pHost;				/* VAR_INPUT */	/* Pointer to host description */
	RTS_IEC_RESULT SysSockGetHostByName;	/* VAR_OUTPUT */	
} syssockgethostbyname_struct;

void CDECL CDECL_EXT syssockgethostbyname(syssockgethostbyname_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKGETHOSTBYNAME_IEC) (syssockgethostbyname_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKGETHOSTBYNAME_NOTIMPLEMENTED)
	#define USE_syssockgethostbyname
	#define EXT_syssockgethostbyname
	#define GET_syssockgethostbyname(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockgethostbyname(p0) 
	#define CHK_syssockgethostbyname  FALSE
	#define EXP_syssockgethostbyname  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockgethostbyname
	#define EXT_syssockgethostbyname
	#define GET_syssockgethostbyname(fl)  CAL_CMGETAPI( "syssockgethostbyname" ) 
	#define CAL_syssockgethostbyname  syssockgethostbyname
	#define CHK_syssockgethostbyname  TRUE
	#define EXP_syssockgethostbyname  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgethostbyname", (RTS_UINTPTR)syssockgethostbyname, 1, RTSITF_GET_SIGNATURE(0, 0x05667F90), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockgethostbyname
	#define EXT_syssockgethostbyname
	#define GET_syssockgethostbyname(fl)  CAL_CMGETAPI( "syssockgethostbyname" ) 
	#define CAL_syssockgethostbyname  syssockgethostbyname
	#define CHK_syssockgethostbyname  TRUE
	#define EXP_syssockgethostbyname  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgethostbyname", (RTS_UINTPTR)syssockgethostbyname, 1, RTSITF_GET_SIGNATURE(0, 0x05667F90), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockgethostbyname
	#define EXT_SysSocket_Implementationsyssockgethostbyname
	#define GET_SysSocket_Implementationsyssockgethostbyname  ERR_OK
	#define CAL_SysSocket_Implementationsyssockgethostbyname  syssockgethostbyname
	#define CHK_SysSocket_Implementationsyssockgethostbyname  TRUE
	#define EXP_SysSocket_Implementationsyssockgethostbyname  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgethostbyname", (RTS_UINTPTR)syssockgethostbyname, 1, RTSITF_GET_SIGNATURE(0, 0x05667F90), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockgethostbyname
	#define EXT_syssockgethostbyname
	#define GET_syssockgethostbyname(fl)  CAL_CMGETAPI( "syssockgethostbyname" ) 
	#define CAL_syssockgethostbyname  syssockgethostbyname
	#define CHK_syssockgethostbyname  TRUE
	#define EXP_syssockgethostbyname  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgethostbyname", (RTS_UINTPTR)syssockgethostbyname, 1, RTSITF_GET_SIGNATURE(0, 0x05667F90), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockgethostbyname  PFSYSSOCKGETHOSTBYNAME_IEC pfsyssockgethostbyname;
	#define EXT_syssockgethostbyname  extern PFSYSSOCKGETHOSTBYNAME_IEC pfsyssockgethostbyname;
	#define GET_syssockgethostbyname(fl)  s_pfCMGetAPI2( "syssockgethostbyname", (RTS_VOID_FCTPTR *)&pfsyssockgethostbyname, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x05667F90), 0x03050F00)
	#define CAL_syssockgethostbyname  pfsyssockgethostbyname
	#define CHK_syssockgethostbyname  (pfsyssockgethostbyname != NULL)
	#define EXP_syssockgethostbyname   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgethostbyname", (RTS_UINTPTR)syssockgethostbyname, 1, RTSITF_GET_SIGNATURE(0, 0x05667F90), 0x03050F00) 
#endif


/**
 * | Get host name of the target.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockgethostname_struct
{
	RTS_IEC_STRING *szHostName;			/* VAR_INPUT */	/* Reference to get host name */
	RTS_IEC_DINT diNameLen;				/* VAR_INPUT */	/* Maximum length of hostname */
	RTS_IEC_RESULT SysSockGetHostName;	/* VAR_OUTPUT */	
} syssockgethostname_struct;

void CDECL CDECL_EXT syssockgethostname(syssockgethostname_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKGETHOSTNAME_IEC) (syssockgethostname_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKGETHOSTNAME_NOTIMPLEMENTED)
	#define USE_syssockgethostname
	#define EXT_syssockgethostname
	#define GET_syssockgethostname(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockgethostname(p0) 
	#define CHK_syssockgethostname  FALSE
	#define EXP_syssockgethostname  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockgethostname
	#define EXT_syssockgethostname
	#define GET_syssockgethostname(fl)  CAL_CMGETAPI( "syssockgethostname" ) 
	#define CAL_syssockgethostname  syssockgethostname
	#define CHK_syssockgethostname  TRUE
	#define EXP_syssockgethostname  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgethostname", (RTS_UINTPTR)syssockgethostname, 1, RTSITF_GET_SIGNATURE(0, 0x68CAC03B), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockgethostname
	#define EXT_syssockgethostname
	#define GET_syssockgethostname(fl)  CAL_CMGETAPI( "syssockgethostname" ) 
	#define CAL_syssockgethostname  syssockgethostname
	#define CHK_syssockgethostname  TRUE
	#define EXP_syssockgethostname  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgethostname", (RTS_UINTPTR)syssockgethostname, 1, RTSITF_GET_SIGNATURE(0, 0x68CAC03B), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockgethostname
	#define EXT_SysSocket_Implementationsyssockgethostname
	#define GET_SysSocket_Implementationsyssockgethostname  ERR_OK
	#define CAL_SysSocket_Implementationsyssockgethostname  syssockgethostname
	#define CHK_SysSocket_Implementationsyssockgethostname  TRUE
	#define EXP_SysSocket_Implementationsyssockgethostname  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgethostname", (RTS_UINTPTR)syssockgethostname, 1, RTSITF_GET_SIGNATURE(0, 0x68CAC03B), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockgethostname
	#define EXT_syssockgethostname
	#define GET_syssockgethostname(fl)  CAL_CMGETAPI( "syssockgethostname" ) 
	#define CAL_syssockgethostname  syssockgethostname
	#define CHK_syssockgethostname  TRUE
	#define EXP_syssockgethostname  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgethostname", (RTS_UINTPTR)syssockgethostname, 1, RTSITF_GET_SIGNATURE(0, 0x68CAC03B), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockgethostname  PFSYSSOCKGETHOSTNAME_IEC pfsyssockgethostname;
	#define EXT_syssockgethostname  extern PFSYSSOCKGETHOSTNAME_IEC pfsyssockgethostname;
	#define GET_syssockgethostname(fl)  s_pfCMGetAPI2( "syssockgethostname", (RTS_VOID_FCTPTR *)&pfsyssockgethostname, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x68CAC03B), 0x03050F00)
	#define CAL_syssockgethostname  pfsyssockgethostname
	#define CHK_syssockgethostname  (pfsyssockgethostname != NULL)
	#define EXP_syssockgethostname   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgethostname", (RTS_UINTPTR)syssockgethostname, 1, RTSITF_GET_SIGNATURE(0, 0x68CAC03B), 0x03050F00) 
#endif


/**
 * | Get adapter information struct of the next network adapter from the adapter list.
 * | Note: It may took a while until a change of the adapter configuration is reflected here.
 * :return: Handle to be passed to SysSockGetNextAdapter() to retrieve the next adapter information.
 */
typedef struct tagsyssockgetnextadapterinfo_struct
{
	RTS_IEC_HANDLE hPrevAdapter;		/* VAR_INPUT */	/* Handle returned by SysSockGetFirstAdapter() or by previous call of SysSockGetNextAdapter() */
	SOCK_ADAPTER_INFORMATION *pAdapterInfo;	/* VAR_INPUT */	/* Network adapter information structure */
	RTS_IEC_UXINT *puxiAdapterInfoSize;	/* VAR_INPUT */	/* Size in bytes of SOCK_ADAPTER_INFORMATION; returns structure size from external implementation */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_HANDLE SysSockGetNextAdapterInfo;	/* VAR_OUTPUT */	
} syssockgetnextadapterinfo_struct;

void CDECL CDECL_EXT syssockgetnextadapterinfo(syssockgetnextadapterinfo_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKGETNEXTADAPTERINFO_IEC) (syssockgetnextadapterinfo_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKGETNEXTADAPTERINFO_NOTIMPLEMENTED)
	#define USE_syssockgetnextadapterinfo
	#define EXT_syssockgetnextadapterinfo
	#define GET_syssockgetnextadapterinfo(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockgetnextadapterinfo(p0) 
	#define CHK_syssockgetnextadapterinfo  FALSE
	#define EXP_syssockgetnextadapterinfo  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockgetnextadapterinfo
	#define EXT_syssockgetnextadapterinfo
	#define GET_syssockgetnextadapterinfo(fl)  CAL_CMGETAPI( "syssockgetnextadapterinfo" ) 
	#define CAL_syssockgetnextadapterinfo  syssockgetnextadapterinfo
	#define CHK_syssockgetnextadapterinfo  TRUE
	#define EXP_syssockgetnextadapterinfo  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetnextadapterinfo", (RTS_UINTPTR)syssockgetnextadapterinfo, 1, RTSITF_GET_SIGNATURE(0x1BE45D9D, 0x8EB7E5E3), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockgetnextadapterinfo
	#define EXT_syssockgetnextadapterinfo
	#define GET_syssockgetnextadapterinfo(fl)  CAL_CMGETAPI( "syssockgetnextadapterinfo" ) 
	#define CAL_syssockgetnextadapterinfo  syssockgetnextadapterinfo
	#define CHK_syssockgetnextadapterinfo  TRUE
	#define EXP_syssockgetnextadapterinfo  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetnextadapterinfo", (RTS_UINTPTR)syssockgetnextadapterinfo, 1, RTSITF_GET_SIGNATURE(0x1BE45D9D, 0x8EB7E5E3), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockgetnextadapterinfo
	#define EXT_SysSocket_Implementationsyssockgetnextadapterinfo
	#define GET_SysSocket_Implementationsyssockgetnextadapterinfo  ERR_OK
	#define CAL_SysSocket_Implementationsyssockgetnextadapterinfo  syssockgetnextadapterinfo
	#define CHK_SysSocket_Implementationsyssockgetnextadapterinfo  TRUE
	#define EXP_SysSocket_Implementationsyssockgetnextadapterinfo  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetnextadapterinfo", (RTS_UINTPTR)syssockgetnextadapterinfo, 1, RTSITF_GET_SIGNATURE(0x1BE45D9D, 0x8EB7E5E3), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockgetnextadapterinfo
	#define EXT_syssockgetnextadapterinfo
	#define GET_syssockgetnextadapterinfo(fl)  CAL_CMGETAPI( "syssockgetnextadapterinfo" ) 
	#define CAL_syssockgetnextadapterinfo  syssockgetnextadapterinfo
	#define CHK_syssockgetnextadapterinfo  TRUE
	#define EXP_syssockgetnextadapterinfo  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetnextadapterinfo", (RTS_UINTPTR)syssockgetnextadapterinfo, 1, RTSITF_GET_SIGNATURE(0x1BE45D9D, 0x8EB7E5E3), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockgetnextadapterinfo  PFSYSSOCKGETNEXTADAPTERINFO_IEC pfsyssockgetnextadapterinfo;
	#define EXT_syssockgetnextadapterinfo  extern PFSYSSOCKGETNEXTADAPTERINFO_IEC pfsyssockgetnextadapterinfo;
	#define GET_syssockgetnextadapterinfo(fl)  s_pfCMGetAPI2( "syssockgetnextadapterinfo", (RTS_VOID_FCTPTR *)&pfsyssockgetnextadapterinfo, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0x1BE45D9D, 0x8EB7E5E3), 0x03050F00)
	#define CAL_syssockgetnextadapterinfo  pfsyssockgetnextadapterinfo
	#define CHK_syssockgetnextadapterinfo  (pfsyssockgetnextadapterinfo != NULL)
	#define EXP_syssockgetnextadapterinfo   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetnextadapterinfo", (RTS_UINTPTR)syssockgetnextadapterinfo, 1, RTSITF_GET_SIGNATURE(0x1BE45D9D, 0x8EB7E5E3), 0x03050F00) 
#endif


/**
 * | Set options of a specified socket.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockgetoption_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Handle to the socket */
	RTS_IEC_DINT diLevel;				/* VAR_INPUT */	/* Level of the socket */
	RTS_IEC_DINT diOption;				/* VAR_INPUT */	/* Socket option command */
	RTS_IEC_DINT *pdiOptionValue;		/* VAR_INPUT */	/* Pointer to the option value */
	RTS_IEC_DINT *pdiOptionLen;			/* VAR_INPUT */	/* Lenght of option value */
	RTS_IEC_RESULT SysSockGetOption;	/* VAR_OUTPUT */	
} syssockgetoption_struct;

void CDECL CDECL_EXT syssockgetoption(syssockgetoption_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKGETOPTION_IEC) (syssockgetoption_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKGETOPTION_NOTIMPLEMENTED)
	#define USE_syssockgetoption
	#define EXT_syssockgetoption
	#define GET_syssockgetoption(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockgetoption(p0) 
	#define CHK_syssockgetoption  FALSE
	#define EXP_syssockgetoption  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockgetoption
	#define EXT_syssockgetoption
	#define GET_syssockgetoption(fl)  CAL_CMGETAPI( "syssockgetoption" ) 
	#define CAL_syssockgetoption  syssockgetoption
	#define CHK_syssockgetoption  TRUE
	#define EXP_syssockgetoption  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetoption", (RTS_UINTPTR)syssockgetoption, 1, RTSITF_GET_SIGNATURE(0, 0xB7ABC5B8), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockgetoption
	#define EXT_syssockgetoption
	#define GET_syssockgetoption(fl)  CAL_CMGETAPI( "syssockgetoption" ) 
	#define CAL_syssockgetoption  syssockgetoption
	#define CHK_syssockgetoption  TRUE
	#define EXP_syssockgetoption  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetoption", (RTS_UINTPTR)syssockgetoption, 1, RTSITF_GET_SIGNATURE(0, 0xB7ABC5B8), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockgetoption
	#define EXT_SysSocket_Implementationsyssockgetoption
	#define GET_SysSocket_Implementationsyssockgetoption  ERR_OK
	#define CAL_SysSocket_Implementationsyssockgetoption  syssockgetoption
	#define CHK_SysSocket_Implementationsyssockgetoption  TRUE
	#define EXP_SysSocket_Implementationsyssockgetoption  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetoption", (RTS_UINTPTR)syssockgetoption, 1, RTSITF_GET_SIGNATURE(0, 0xB7ABC5B8), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockgetoption
	#define EXT_syssockgetoption
	#define GET_syssockgetoption(fl)  CAL_CMGETAPI( "syssockgetoption" ) 
	#define CAL_syssockgetoption  syssockgetoption
	#define CHK_syssockgetoption  TRUE
	#define EXP_syssockgetoption  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetoption", (RTS_UINTPTR)syssockgetoption, 1, RTSITF_GET_SIGNATURE(0, 0xB7ABC5B8), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockgetoption  PFSYSSOCKGETOPTION_IEC pfsyssockgetoption;
	#define EXT_syssockgetoption  extern PFSYSSOCKGETOPTION_IEC pfsyssockgetoption;
	#define GET_syssockgetoption(fl)  s_pfCMGetAPI2( "syssockgetoption", (RTS_VOID_FCTPTR *)&pfsyssockgetoption, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xB7ABC5B8), 0x03050F00)
	#define CAL_syssockgetoption  pfsyssockgetoption
	#define CHK_syssockgetoption  (pfsyssockgetoption != NULL)
	#define EXP_syssockgetoption   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetoption", (RTS_UINTPTR)syssockgetoption, 1, RTSITF_GET_SIGNATURE(0, 0xB7ABC5B8), 0x03050F00) 
#endif


/**
 * | Get operating system handle of the UDP socket.
 * :return: Operating system handle
 */
typedef struct tagsyssockgetoshandle_struct
{
	RTS_IEC_HANDLE hSocketUdp;			/* VAR_INPUT */	/* Handle to the UDP socket */
	RTS_IEC_HANDLE SysSockGetOSHandle;	/* VAR_OUTPUT */	
} syssockgetoshandle_struct;

void CDECL CDECL_EXT syssockgetoshandle(syssockgetoshandle_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKGETOSHANDLE_IEC) (syssockgetoshandle_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKGETOSHANDLE_NOTIMPLEMENTED)
	#define USE_syssockgetoshandle
	#define EXT_syssockgetoshandle
	#define GET_syssockgetoshandle(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockgetoshandle(p0) 
	#define CHK_syssockgetoshandle  FALSE
	#define EXP_syssockgetoshandle  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockgetoshandle
	#define EXT_syssockgetoshandle
	#define GET_syssockgetoshandle(fl)  CAL_CMGETAPI( "syssockgetoshandle" ) 
	#define CAL_syssockgetoshandle  syssockgetoshandle
	#define CHK_syssockgetoshandle  TRUE
	#define EXP_syssockgetoshandle  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetoshandle", (RTS_UINTPTR)syssockgetoshandle, 1, RTSITF_GET_SIGNATURE(0, 0x784811EB), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockgetoshandle
	#define EXT_syssockgetoshandle
	#define GET_syssockgetoshandle(fl)  CAL_CMGETAPI( "syssockgetoshandle" ) 
	#define CAL_syssockgetoshandle  syssockgetoshandle
	#define CHK_syssockgetoshandle  TRUE
	#define EXP_syssockgetoshandle  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetoshandle", (RTS_UINTPTR)syssockgetoshandle, 1, RTSITF_GET_SIGNATURE(0, 0x784811EB), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockgetoshandle
	#define EXT_SysSocket_Implementationsyssockgetoshandle
	#define GET_SysSocket_Implementationsyssockgetoshandle  ERR_OK
	#define CAL_SysSocket_Implementationsyssockgetoshandle  syssockgetoshandle
	#define CHK_SysSocket_Implementationsyssockgetoshandle  TRUE
	#define EXP_SysSocket_Implementationsyssockgetoshandle  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetoshandle", (RTS_UINTPTR)syssockgetoshandle, 1, RTSITF_GET_SIGNATURE(0, 0x784811EB), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockgetoshandle
	#define EXT_syssockgetoshandle
	#define GET_syssockgetoshandle(fl)  CAL_CMGETAPI( "syssockgetoshandle" ) 
	#define CAL_syssockgetoshandle  syssockgetoshandle
	#define CHK_syssockgetoshandle  TRUE
	#define EXP_syssockgetoshandle  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetoshandle", (RTS_UINTPTR)syssockgetoshandle, 1, RTSITF_GET_SIGNATURE(0, 0x784811EB), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockgetoshandle  PFSYSSOCKGETOSHANDLE_IEC pfsyssockgetoshandle;
	#define EXT_syssockgetoshandle  extern PFSYSSOCKGETOSHANDLE_IEC pfsyssockgetoshandle;
	#define GET_syssockgetoshandle(fl)  s_pfCMGetAPI2( "syssockgetoshandle", (RTS_VOID_FCTPTR *)&pfsyssockgetoshandle, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x784811EB), 0x03050F00)
	#define CAL_syssockgetoshandle  pfsyssockgetoshandle
	#define CHK_syssockgetoshandle  (pfsyssockgetoshandle != NULL)
	#define EXP_syssockgetoshandle   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetoshandle", (RTS_UINTPTR)syssockgetoshandle, 1, RTSITF_GET_SIGNATURE(0, 0x784811EB), 0x03050F00) 
#endif


/**
 * | Returns the socket address of the peer to which a socket is connected.
 * | The SysSockGetPeerName function can be used only on a connected socket. 
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockgetpeername_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Handle to the socket */
	SOCKADDRESS *pSockAddr;				/* VAR_INPUT */	/* Socket address of the peer */
	RTS_IEC_DINT *pdiSockAddrSize;		/* VAR_INPUT */	/* Pointer to size of socket address structure */
	RTS_IEC_RESULT SysSockGetPeerName;	/* VAR_OUTPUT */	
} syssockgetpeername_struct;

void CDECL CDECL_EXT syssockgetpeername(syssockgetpeername_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKGETPEERNAME_IEC) (syssockgetpeername_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKGETPEERNAME_NOTIMPLEMENTED)
	#define USE_syssockgetpeername
	#define EXT_syssockgetpeername
	#define GET_syssockgetpeername(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockgetpeername(p0) 
	#define CHK_syssockgetpeername  FALSE
	#define EXP_syssockgetpeername  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockgetpeername
	#define EXT_syssockgetpeername
	#define GET_syssockgetpeername(fl)  CAL_CMGETAPI( "syssockgetpeername" ) 
	#define CAL_syssockgetpeername  syssockgetpeername
	#define CHK_syssockgetpeername  TRUE
	#define EXP_syssockgetpeername  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetpeername", (RTS_UINTPTR)syssockgetpeername, 1, 0xE0A45F4A, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockgetpeername
	#define EXT_syssockgetpeername
	#define GET_syssockgetpeername(fl)  CAL_CMGETAPI( "syssockgetpeername" ) 
	#define CAL_syssockgetpeername  syssockgetpeername
	#define CHK_syssockgetpeername  TRUE
	#define EXP_syssockgetpeername  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetpeername", (RTS_UINTPTR)syssockgetpeername, 1, 0xE0A45F4A, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockgetpeername
	#define EXT_SysSocket_Implementationsyssockgetpeername
	#define GET_SysSocket_Implementationsyssockgetpeername  ERR_OK
	#define CAL_SysSocket_Implementationsyssockgetpeername  syssockgetpeername
	#define CHK_SysSocket_Implementationsyssockgetpeername  TRUE
	#define EXP_SysSocket_Implementationsyssockgetpeername  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetpeername", (RTS_UINTPTR)syssockgetpeername, 1, 0xE0A45F4A, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockgetpeername
	#define EXT_syssockgetpeername
	#define GET_syssockgetpeername(fl)  CAL_CMGETAPI( "syssockgetpeername" ) 
	#define CAL_syssockgetpeername  syssockgetpeername
	#define CHK_syssockgetpeername  TRUE
	#define EXP_syssockgetpeername  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetpeername", (RTS_UINTPTR)syssockgetpeername, 1, 0xE0A45F4A, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockgetpeername  PFSYSSOCKGETPEERNAME_IEC pfsyssockgetpeername;
	#define EXT_syssockgetpeername  extern PFSYSSOCKGETPEERNAME_IEC pfsyssockgetpeername;
	#define GET_syssockgetpeername(fl)  s_pfCMGetAPI2( "syssockgetpeername", (RTS_VOID_FCTPTR *)&pfsyssockgetpeername, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xE0A45F4A, 0x03050F00)
	#define CAL_syssockgetpeername  pfsyssockgetpeername
	#define CHK_syssockgetpeername  (pfsyssockgetpeername != NULL)
	#define EXP_syssockgetpeername   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetpeername", (RTS_UINTPTR)syssockgetpeername, 1, 0xE0A45F4A, 0x03050F00) 
#endif


/**
 * Check actual received data on the UDP socket.
 * :return: Number of bytes actual available in the socket
 */
typedef struct tagsyssockgetrecvsizeudp_struct
{
	RTS_IEC_HANDLE hSocketUdp;			/* VAR_INPUT */	/* Handle to the UDP socket */
	RTS_IEC_DINT diTimeout;				/* VAR_INPUT */	/* Timeout to wait for received data.

 - -1 = Infinite wait
 -  0 = no wait */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_XINT SysSockGetRecvSizeUdp;	/* VAR_OUTPUT */	
} syssockgetrecvsizeudp_struct;

void CDECL CDECL_EXT syssockgetrecvsizeudp(syssockgetrecvsizeudp_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKGETRECVSIZEUDP_IEC) (syssockgetrecvsizeudp_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKGETRECVSIZEUDP_NOTIMPLEMENTED)
	#define USE_syssockgetrecvsizeudp
	#define EXT_syssockgetrecvsizeudp
	#define GET_syssockgetrecvsizeudp(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockgetrecvsizeudp(p0) 
	#define CHK_syssockgetrecvsizeudp  FALSE
	#define EXP_syssockgetrecvsizeudp  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockgetrecvsizeudp
	#define EXT_syssockgetrecvsizeudp
	#define GET_syssockgetrecvsizeudp(fl)  CAL_CMGETAPI( "syssockgetrecvsizeudp" ) 
	#define CAL_syssockgetrecvsizeudp  syssockgetrecvsizeudp
	#define CHK_syssockgetrecvsizeudp  TRUE
	#define EXP_syssockgetrecvsizeudp  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetrecvsizeudp", (RTS_UINTPTR)syssockgetrecvsizeudp, 1, RTSITF_GET_SIGNATURE(0, 0xDBEEF58B), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockgetrecvsizeudp
	#define EXT_syssockgetrecvsizeudp
	#define GET_syssockgetrecvsizeudp(fl)  CAL_CMGETAPI( "syssockgetrecvsizeudp" ) 
	#define CAL_syssockgetrecvsizeudp  syssockgetrecvsizeudp
	#define CHK_syssockgetrecvsizeudp  TRUE
	#define EXP_syssockgetrecvsizeudp  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetrecvsizeudp", (RTS_UINTPTR)syssockgetrecvsizeudp, 1, RTSITF_GET_SIGNATURE(0, 0xDBEEF58B), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockgetrecvsizeudp
	#define EXT_SysSocket_Implementationsyssockgetrecvsizeudp
	#define GET_SysSocket_Implementationsyssockgetrecvsizeudp  ERR_OK
	#define CAL_SysSocket_Implementationsyssockgetrecvsizeudp  syssockgetrecvsizeudp
	#define CHK_SysSocket_Implementationsyssockgetrecvsizeudp  TRUE
	#define EXP_SysSocket_Implementationsyssockgetrecvsizeudp  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetrecvsizeudp", (RTS_UINTPTR)syssockgetrecvsizeudp, 1, RTSITF_GET_SIGNATURE(0, 0xDBEEF58B), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockgetrecvsizeudp
	#define EXT_syssockgetrecvsizeudp
	#define GET_syssockgetrecvsizeudp(fl)  CAL_CMGETAPI( "syssockgetrecvsizeudp" ) 
	#define CAL_syssockgetrecvsizeudp  syssockgetrecvsizeudp
	#define CHK_syssockgetrecvsizeudp  TRUE
	#define EXP_syssockgetrecvsizeudp  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetrecvsizeudp", (RTS_UINTPTR)syssockgetrecvsizeudp, 1, RTSITF_GET_SIGNATURE(0, 0xDBEEF58B), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockgetrecvsizeudp  PFSYSSOCKGETRECVSIZEUDP_IEC pfsyssockgetrecvsizeudp;
	#define EXT_syssockgetrecvsizeudp  extern PFSYSSOCKGETRECVSIZEUDP_IEC pfsyssockgetrecvsizeudp;
	#define GET_syssockgetrecvsizeudp(fl)  s_pfCMGetAPI2( "syssockgetrecvsizeudp", (RTS_VOID_FCTPTR *)&pfsyssockgetrecvsizeudp, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xDBEEF58B), 0x03050F00)
	#define CAL_syssockgetrecvsizeudp  pfsyssockgetrecvsizeudp
	#define CHK_syssockgetrecvsizeudp  (pfsyssockgetrecvsizeudp != NULL)
	#define EXP_syssockgetrecvsizeudp   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetrecvsizeudp", (RTS_UINTPTR)syssockgetrecvsizeudp, 1, RTSITF_GET_SIGNATURE(0, 0xDBEEF58B), 0x03050F00) 
#endif


/**
 * | Returns the socket address of the local socket.
 * | Usally this function is called to retrieve the local socket address on multihomed hosts or to get 
 *   the local port number in client implemntations. If the socket is neither connected nor locally bound to an address,
 *   the result of the function and the value stored in the object pointed to by pSockAddress is unspecified. 
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockgetsockname_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Handle to the socket */
	SOCKADDRESS *pSockAddr;				/* VAR_INPUT */	/* Socket address of the local socket */
	RTS_IEC_DINT *pdiSockAddrSize;		/* VAR_INPUT */	/* Pointer to size of socket address structure */
	RTS_IEC_RESULT SysSockGetSockName;	/* VAR_OUTPUT */	
} syssockgetsockname_struct;

void CDECL CDECL_EXT syssockgetsockname(syssockgetsockname_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKGETSOCKNAME_IEC) (syssockgetsockname_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKGETSOCKNAME_NOTIMPLEMENTED)
	#define USE_syssockgetsockname
	#define EXT_syssockgetsockname
	#define GET_syssockgetsockname(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockgetsockname(p0) 
	#define CHK_syssockgetsockname  FALSE
	#define EXP_syssockgetsockname  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockgetsockname
	#define EXT_syssockgetsockname
	#define GET_syssockgetsockname(fl)  CAL_CMGETAPI( "syssockgetsockname" ) 
	#define CAL_syssockgetsockname  syssockgetsockname
	#define CHK_syssockgetsockname  TRUE
	#define EXP_syssockgetsockname  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetsockname", (RTS_UINTPTR)syssockgetsockname, 1, 0x7EE86135, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockgetsockname
	#define EXT_syssockgetsockname
	#define GET_syssockgetsockname(fl)  CAL_CMGETAPI( "syssockgetsockname" ) 
	#define CAL_syssockgetsockname  syssockgetsockname
	#define CHK_syssockgetsockname  TRUE
	#define EXP_syssockgetsockname  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetsockname", (RTS_UINTPTR)syssockgetsockname, 1, 0x7EE86135, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockgetsockname
	#define EXT_SysSocket_Implementationsyssockgetsockname
	#define GET_SysSocket_Implementationsyssockgetsockname  ERR_OK
	#define CAL_SysSocket_Implementationsyssockgetsockname  syssockgetsockname
	#define CHK_SysSocket_Implementationsyssockgetsockname  TRUE
	#define EXP_SysSocket_Implementationsyssockgetsockname  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetsockname", (RTS_UINTPTR)syssockgetsockname, 1, 0x7EE86135, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockgetsockname
	#define EXT_syssockgetsockname
	#define GET_syssockgetsockname(fl)  CAL_CMGETAPI( "syssockgetsockname" ) 
	#define CAL_syssockgetsockname  syssockgetsockname
	#define CHK_syssockgetsockname  TRUE
	#define EXP_syssockgetsockname  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetsockname", (RTS_UINTPTR)syssockgetsockname, 1, 0x7EE86135, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockgetsockname  PFSYSSOCKGETSOCKNAME_IEC pfsyssockgetsockname;
	#define EXT_syssockgetsockname  extern PFSYSSOCKGETSOCKNAME_IEC pfsyssockgetsockname;
	#define GET_syssockgetsockname(fl)  s_pfCMGetAPI2( "syssockgetsockname", (RTS_VOID_FCTPTR *)&pfsyssockgetsockname, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x7EE86135, 0x03050F00)
	#define CAL_syssockgetsockname  pfsyssockgetsockname
	#define CHK_syssockgetsockname  (pfsyssockgetsockname != NULL)
	#define EXP_syssockgetsockname   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetsockname", (RTS_UINTPTR)syssockgetsockname, 1, 0x7EE86135, 0x03050F00) 
#endif


/**
 * | Get subnetmask of a specified IP address adapter.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockgetsubnetmask_struct
{
	RTS_IEC_STRING *szIPAddress;		/* VAR_INPUT */	/* IP address of the communication partner as string */
	RTS_IEC_STRING *szSubnetMask;		/* VAR_INPUT */	/* Subnet mask as string */
	RTS_IEC_DINT diMaxSugnetMask;		/* VAR_INPUT */	/* Maximum length of the subnet mask string */
	RTS_IEC_RESULT SysSockGetSubnetMask;	/* VAR_OUTPUT */	
} syssockgetsubnetmask_struct;

void CDECL CDECL_EXT syssockgetsubnetmask(syssockgetsubnetmask_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKGETSUBNETMASK_IEC) (syssockgetsubnetmask_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKGETSUBNETMASK_NOTIMPLEMENTED)
	#define USE_syssockgetsubnetmask
	#define EXT_syssockgetsubnetmask
	#define GET_syssockgetsubnetmask(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockgetsubnetmask(p0) 
	#define CHK_syssockgetsubnetmask  FALSE
	#define EXP_syssockgetsubnetmask  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockgetsubnetmask
	#define EXT_syssockgetsubnetmask
	#define GET_syssockgetsubnetmask(fl)  CAL_CMGETAPI( "syssockgetsubnetmask" ) 
	#define CAL_syssockgetsubnetmask  syssockgetsubnetmask
	#define CHK_syssockgetsubnetmask  TRUE
	#define EXP_syssockgetsubnetmask  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetsubnetmask", (RTS_UINTPTR)syssockgetsubnetmask, 1, RTSITF_GET_SIGNATURE(0, 0x972C29B9), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockgetsubnetmask
	#define EXT_syssockgetsubnetmask
	#define GET_syssockgetsubnetmask(fl)  CAL_CMGETAPI( "syssockgetsubnetmask" ) 
	#define CAL_syssockgetsubnetmask  syssockgetsubnetmask
	#define CHK_syssockgetsubnetmask  TRUE
	#define EXP_syssockgetsubnetmask  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetsubnetmask", (RTS_UINTPTR)syssockgetsubnetmask, 1, RTSITF_GET_SIGNATURE(0, 0x972C29B9), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockgetsubnetmask
	#define EXT_SysSocket_Implementationsyssockgetsubnetmask
	#define GET_SysSocket_Implementationsyssockgetsubnetmask  ERR_OK
	#define CAL_SysSocket_Implementationsyssockgetsubnetmask  syssockgetsubnetmask
	#define CHK_SysSocket_Implementationsyssockgetsubnetmask  TRUE
	#define EXP_SysSocket_Implementationsyssockgetsubnetmask  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetsubnetmask", (RTS_UINTPTR)syssockgetsubnetmask, 1, RTSITF_GET_SIGNATURE(0, 0x972C29B9), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockgetsubnetmask
	#define EXT_syssockgetsubnetmask
	#define GET_syssockgetsubnetmask(fl)  CAL_CMGETAPI( "syssockgetsubnetmask" ) 
	#define CAL_syssockgetsubnetmask  syssockgetsubnetmask
	#define CHK_syssockgetsubnetmask  TRUE
	#define EXP_syssockgetsubnetmask  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetsubnetmask", (RTS_UINTPTR)syssockgetsubnetmask, 1, RTSITF_GET_SIGNATURE(0, 0x972C29B9), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockgetsubnetmask  PFSYSSOCKGETSUBNETMASK_IEC pfsyssockgetsubnetmask;
	#define EXT_syssockgetsubnetmask  extern PFSYSSOCKGETSUBNETMASK_IEC pfsyssockgetsubnetmask;
	#define GET_syssockgetsubnetmask(fl)  s_pfCMGetAPI2( "syssockgetsubnetmask", (RTS_VOID_FCTPTR *)&pfsyssockgetsubnetmask, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x972C29B9), 0x03050F00)
	#define CAL_syssockgetsubnetmask  pfsyssockgetsubnetmask
	#define CHK_syssockgetsubnetmask  (pfsyssockgetsubnetmask != NULL)
	#define EXP_syssockgetsubnetmask   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockgetsubnetmask", (RTS_UINTPTR)syssockgetsubnetmask, 1, RTSITF_GET_SIGNATURE(0, 0x972C29B9), 0x03050F00) 
#endif


/**
 * | Converts a value of type UDINT from host byte order to the order of the TCP/IP network.
 * :return: Converted UDINT value
 */
typedef struct tagsyssockhtonl_struct
{
	RTS_IEC_UDINT ulHost;				/* VAR_INPUT */	/* Host value */
	RTS_IEC_UDINT SysSockHtonl;			/* VAR_OUTPUT */	
} syssockhtonl_struct;

void CDECL CDECL_EXT syssockhtonl(syssockhtonl_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKHTONL_IEC) (syssockhtonl_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKHTONL_NOTIMPLEMENTED)
	#define USE_syssockhtonl
	#define EXT_syssockhtonl
	#define GET_syssockhtonl(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockhtonl(p0) 
	#define CHK_syssockhtonl  FALSE
	#define EXP_syssockhtonl  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockhtonl
	#define EXT_syssockhtonl
	#define GET_syssockhtonl(fl)  CAL_CMGETAPI( "syssockhtonl" ) 
	#define CAL_syssockhtonl  syssockhtonl
	#define CHK_syssockhtonl  TRUE
	#define EXP_syssockhtonl  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockhtonl", (RTS_UINTPTR)syssockhtonl, 1, RTSITF_GET_SIGNATURE(0, 0x72F6021A), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockhtonl
	#define EXT_syssockhtonl
	#define GET_syssockhtonl(fl)  CAL_CMGETAPI( "syssockhtonl" ) 
	#define CAL_syssockhtonl  syssockhtonl
	#define CHK_syssockhtonl  TRUE
	#define EXP_syssockhtonl  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockhtonl", (RTS_UINTPTR)syssockhtonl, 1, RTSITF_GET_SIGNATURE(0, 0x72F6021A), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockhtonl
	#define EXT_SysSocket_Implementationsyssockhtonl
	#define GET_SysSocket_Implementationsyssockhtonl  ERR_OK
	#define CAL_SysSocket_Implementationsyssockhtonl  syssockhtonl
	#define CHK_SysSocket_Implementationsyssockhtonl  TRUE
	#define EXP_SysSocket_Implementationsyssockhtonl  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockhtonl", (RTS_UINTPTR)syssockhtonl, 1, RTSITF_GET_SIGNATURE(0, 0x72F6021A), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockhtonl
	#define EXT_syssockhtonl
	#define GET_syssockhtonl(fl)  CAL_CMGETAPI( "syssockhtonl" ) 
	#define CAL_syssockhtonl  syssockhtonl
	#define CHK_syssockhtonl  TRUE
	#define EXP_syssockhtonl  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockhtonl", (RTS_UINTPTR)syssockhtonl, 1, RTSITF_GET_SIGNATURE(0, 0x72F6021A), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockhtonl  PFSYSSOCKHTONL_IEC pfsyssockhtonl;
	#define EXT_syssockhtonl  extern PFSYSSOCKHTONL_IEC pfsyssockhtonl;
	#define GET_syssockhtonl(fl)  s_pfCMGetAPI2( "syssockhtonl", (RTS_VOID_FCTPTR *)&pfsyssockhtonl, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x72F6021A), 0x03050F00)
	#define CAL_syssockhtonl  pfsyssockhtonl
	#define CHK_syssockhtonl  (pfsyssockhtonl != NULL)
	#define EXP_syssockhtonl   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockhtonl", (RTS_UINTPTR)syssockhtonl, 1, RTSITF_GET_SIGNATURE(0, 0x72F6021A), 0x03050F00) 
#endif


/**
 * | Converts a value of type short from order of the TCP/IP network to the host byte order.
 * :return: Converted WORD value
 */
typedef struct tagsyssockhtons_struct
{
	RTS_IEC_WORD usHost;				/* VAR_INPUT */	/* Ethernet value */
	RTS_IEC_WORD SysSockHtons;			/* VAR_OUTPUT */	
} syssockhtons_struct;

void CDECL CDECL_EXT syssockhtons(syssockhtons_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKHTONS_IEC) (syssockhtons_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKHTONS_NOTIMPLEMENTED)
	#define USE_syssockhtons
	#define EXT_syssockhtons
	#define GET_syssockhtons(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockhtons(p0) 
	#define CHK_syssockhtons  FALSE
	#define EXP_syssockhtons  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockhtons
	#define EXT_syssockhtons
	#define GET_syssockhtons(fl)  CAL_CMGETAPI( "syssockhtons" ) 
	#define CAL_syssockhtons  syssockhtons
	#define CHK_syssockhtons  TRUE
	#define EXP_syssockhtons  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockhtons", (RTS_UINTPTR)syssockhtons, 1, RTSITF_GET_SIGNATURE(0, 0xD258956A), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockhtons
	#define EXT_syssockhtons
	#define GET_syssockhtons(fl)  CAL_CMGETAPI( "syssockhtons" ) 
	#define CAL_syssockhtons  syssockhtons
	#define CHK_syssockhtons  TRUE
	#define EXP_syssockhtons  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockhtons", (RTS_UINTPTR)syssockhtons, 1, RTSITF_GET_SIGNATURE(0, 0xD258956A), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockhtons
	#define EXT_SysSocket_Implementationsyssockhtons
	#define GET_SysSocket_Implementationsyssockhtons  ERR_OK
	#define CAL_SysSocket_Implementationsyssockhtons  syssockhtons
	#define CHK_SysSocket_Implementationsyssockhtons  TRUE
	#define EXP_SysSocket_Implementationsyssockhtons  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockhtons", (RTS_UINTPTR)syssockhtons, 1, RTSITF_GET_SIGNATURE(0, 0xD258956A), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockhtons
	#define EXT_syssockhtons
	#define GET_syssockhtons(fl)  CAL_CMGETAPI( "syssockhtons" ) 
	#define CAL_syssockhtons  syssockhtons
	#define CHK_syssockhtons  TRUE
	#define EXP_syssockhtons  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockhtons", (RTS_UINTPTR)syssockhtons, 1, RTSITF_GET_SIGNATURE(0, 0xD258956A), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockhtons  PFSYSSOCKHTONS_IEC pfsyssockhtons;
	#define EXT_syssockhtons  extern PFSYSSOCKHTONS_IEC pfsyssockhtons;
	#define GET_syssockhtons(fl)  s_pfCMGetAPI2( "syssockhtons", (RTS_VOID_FCTPTR *)&pfsyssockhtons, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xD258956A), 0x03050F00)
	#define CAL_syssockhtons  pfsyssockhtons
	#define CHK_syssockhtons  (pfsyssockhtons != NULL)
	#define EXP_syssockhtons   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockhtons", (RTS_UINTPTR)syssockhtons, 1, RTSITF_GET_SIGNATURE(0, 0xD258956A), 0x03050F00) 
#endif


/**
 * | Convert an IP address string into an IP address.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockinetaddr_struct
{
	RTS_IEC_STRING *szIPAddress;		/* VAR_INPUT */	/* Pointer to get IP address string (must be at least 16 bytes long) */
	RTS_IEC_UDINT *pInAddr;				/* VAR_INPUT */	/* Pointer to IP address description */
	RTS_IEC_RESULT SysSockInetAddr;		/* VAR_OUTPUT */	
} syssockinetaddr_struct;

void CDECL CDECL_EXT syssockinetaddr(syssockinetaddr_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKINETADDR_IEC) (syssockinetaddr_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKINETADDR_NOTIMPLEMENTED)
	#define USE_syssockinetaddr
	#define EXT_syssockinetaddr
	#define GET_syssockinetaddr(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockinetaddr(p0) 
	#define CHK_syssockinetaddr  FALSE
	#define EXP_syssockinetaddr  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockinetaddr
	#define EXT_syssockinetaddr
	#define GET_syssockinetaddr(fl)  CAL_CMGETAPI( "syssockinetaddr" ) 
	#define CAL_syssockinetaddr  syssockinetaddr
	#define CHK_syssockinetaddr  TRUE
	#define EXP_syssockinetaddr  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockinetaddr", (RTS_UINTPTR)syssockinetaddr, 1, RTSITF_GET_SIGNATURE(0, 0xB8198B8F), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockinetaddr
	#define EXT_syssockinetaddr
	#define GET_syssockinetaddr(fl)  CAL_CMGETAPI( "syssockinetaddr" ) 
	#define CAL_syssockinetaddr  syssockinetaddr
	#define CHK_syssockinetaddr  TRUE
	#define EXP_syssockinetaddr  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockinetaddr", (RTS_UINTPTR)syssockinetaddr, 1, RTSITF_GET_SIGNATURE(0, 0xB8198B8F), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockinetaddr
	#define EXT_SysSocket_Implementationsyssockinetaddr
	#define GET_SysSocket_Implementationsyssockinetaddr  ERR_OK
	#define CAL_SysSocket_Implementationsyssockinetaddr  syssockinetaddr
	#define CHK_SysSocket_Implementationsyssockinetaddr  TRUE
	#define EXP_SysSocket_Implementationsyssockinetaddr  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockinetaddr", (RTS_UINTPTR)syssockinetaddr, 1, RTSITF_GET_SIGNATURE(0, 0xB8198B8F), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockinetaddr
	#define EXT_syssockinetaddr
	#define GET_syssockinetaddr(fl)  CAL_CMGETAPI( "syssockinetaddr" ) 
	#define CAL_syssockinetaddr  syssockinetaddr
	#define CHK_syssockinetaddr  TRUE
	#define EXP_syssockinetaddr  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockinetaddr", (RTS_UINTPTR)syssockinetaddr, 1, RTSITF_GET_SIGNATURE(0, 0xB8198B8F), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockinetaddr  PFSYSSOCKINETADDR_IEC pfsyssockinetaddr;
	#define EXT_syssockinetaddr  extern PFSYSSOCKINETADDR_IEC pfsyssockinetaddr;
	#define GET_syssockinetaddr(fl)  s_pfCMGetAPI2( "syssockinetaddr", (RTS_VOID_FCTPTR *)&pfsyssockinetaddr, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xB8198B8F), 0x03050F00)
	#define CAL_syssockinetaddr  pfsyssockinetaddr
	#define CHK_syssockinetaddr  (pfsyssockinetaddr != NULL)
	#define EXP_syssockinetaddr   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockinetaddr", (RTS_UINTPTR)syssockinetaddr, 1, RTSITF_GET_SIGNATURE(0, 0xB8198B8F), 0x03050F00) 
#endif


/**
 * | Convert IP address to a string.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockinetntoa_struct
{
	INADDR *pInAddr;					/* VAR_INPUT */	/* Pointer to IP address description */
	RTS_IEC_STRING *szIPADDR;			/* VAR_INPUT */	/* Pointer to get IP address string (must be at least 16 bytes long) */
	RTS_IEC_DINT diIPAddrSize;			/* VAR_INPUT */	/* Maximum length of szIPAddr */
	RTS_IEC_RESULT SysSockInetNtoa;		/* VAR_OUTPUT */	
} syssockinetntoa_struct;

void CDECL CDECL_EXT syssockinetntoa(syssockinetntoa_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKINETNTOA_IEC) (syssockinetntoa_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKINETNTOA_NOTIMPLEMENTED)
	#define USE_syssockinetntoa
	#define EXT_syssockinetntoa
	#define GET_syssockinetntoa(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockinetntoa(p0) 
	#define CHK_syssockinetntoa  FALSE
	#define EXP_syssockinetntoa  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockinetntoa
	#define EXT_syssockinetntoa
	#define GET_syssockinetntoa(fl)  CAL_CMGETAPI( "syssockinetntoa" ) 
	#define CAL_syssockinetntoa  syssockinetntoa
	#define CHK_syssockinetntoa  TRUE
	#define EXP_syssockinetntoa  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockinetntoa", (RTS_UINTPTR)syssockinetntoa, 1, RTSITF_GET_SIGNATURE(0, 0x5CE722B2), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockinetntoa
	#define EXT_syssockinetntoa
	#define GET_syssockinetntoa(fl)  CAL_CMGETAPI( "syssockinetntoa" ) 
	#define CAL_syssockinetntoa  syssockinetntoa
	#define CHK_syssockinetntoa  TRUE
	#define EXP_syssockinetntoa  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockinetntoa", (RTS_UINTPTR)syssockinetntoa, 1, RTSITF_GET_SIGNATURE(0, 0x5CE722B2), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockinetntoa
	#define EXT_SysSocket_Implementationsyssockinetntoa
	#define GET_SysSocket_Implementationsyssockinetntoa  ERR_OK
	#define CAL_SysSocket_Implementationsyssockinetntoa  syssockinetntoa
	#define CHK_SysSocket_Implementationsyssockinetntoa  TRUE
	#define EXP_SysSocket_Implementationsyssockinetntoa  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockinetntoa", (RTS_UINTPTR)syssockinetntoa, 1, RTSITF_GET_SIGNATURE(0, 0x5CE722B2), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockinetntoa
	#define EXT_syssockinetntoa
	#define GET_syssockinetntoa(fl)  CAL_CMGETAPI( "syssockinetntoa" ) 
	#define CAL_syssockinetntoa  syssockinetntoa
	#define CHK_syssockinetntoa  TRUE
	#define EXP_syssockinetntoa  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockinetntoa", (RTS_UINTPTR)syssockinetntoa, 1, RTSITF_GET_SIGNATURE(0, 0x5CE722B2), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockinetntoa  PFSYSSOCKINETNTOA_IEC pfsyssockinetntoa;
	#define EXT_syssockinetntoa  extern PFSYSSOCKINETNTOA_IEC pfsyssockinetntoa;
	#define GET_syssockinetntoa(fl)  s_pfCMGetAPI2( "syssockinetntoa", (RTS_VOID_FCTPTR *)&pfsyssockinetntoa, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x5CE722B2), 0x03050F00)
	#define CAL_syssockinetntoa  pfsyssockinetntoa
	#define CHK_syssockinetntoa  (pfsyssockinetntoa != NULL)
	#define EXP_syssockinetntoa   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockinetntoa", (RTS_UINTPTR)syssockinetntoa, 1, RTSITF_GET_SIGNATURE(0, 0x5CE722B2), 0x03050F00) 
#endif


/**
 * | Io-control of a socket.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockioctl_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Handle to the socket */
	RTS_IEC_DINT diCommand;				/* VAR_INPUT */	/* Io-control command */
	RTS_IEC_DINT *pdiParameter;			/* VAR_INPUT */	/* Parameter value of the command */
	RTS_IEC_RESULT SysSockIoctl;		/* VAR_OUTPUT */	
} syssockioctl_struct;

void CDECL CDECL_EXT syssockioctl(syssockioctl_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKIOCTL_IEC) (syssockioctl_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKIOCTL_NOTIMPLEMENTED)
	#define USE_syssockioctl
	#define EXT_syssockioctl
	#define GET_syssockioctl(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockioctl(p0) 
	#define CHK_syssockioctl  FALSE
	#define EXP_syssockioctl  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockioctl
	#define EXT_syssockioctl
	#define GET_syssockioctl(fl)  CAL_CMGETAPI( "syssockioctl" ) 
	#define CAL_syssockioctl  syssockioctl
	#define CHK_syssockioctl  TRUE
	#define EXP_syssockioctl  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockioctl", (RTS_UINTPTR)syssockioctl, 1, RTSITF_GET_SIGNATURE(0, 0x408480FB), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockioctl
	#define EXT_syssockioctl
	#define GET_syssockioctl(fl)  CAL_CMGETAPI( "syssockioctl" ) 
	#define CAL_syssockioctl  syssockioctl
	#define CHK_syssockioctl  TRUE
	#define EXP_syssockioctl  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockioctl", (RTS_UINTPTR)syssockioctl, 1, RTSITF_GET_SIGNATURE(0, 0x408480FB), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockioctl
	#define EXT_SysSocket_Implementationsyssockioctl
	#define GET_SysSocket_Implementationsyssockioctl  ERR_OK
	#define CAL_SysSocket_Implementationsyssockioctl  syssockioctl
	#define CHK_SysSocket_Implementationsyssockioctl  TRUE
	#define EXP_SysSocket_Implementationsyssockioctl  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockioctl", (RTS_UINTPTR)syssockioctl, 1, RTSITF_GET_SIGNATURE(0, 0x408480FB), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockioctl
	#define EXT_syssockioctl
	#define GET_syssockioctl(fl)  CAL_CMGETAPI( "syssockioctl" ) 
	#define CAL_syssockioctl  syssockioctl
	#define CHK_syssockioctl  TRUE
	#define EXP_syssockioctl  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockioctl", (RTS_UINTPTR)syssockioctl, 1, RTSITF_GET_SIGNATURE(0, 0x408480FB), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockioctl  PFSYSSOCKIOCTL_IEC pfsyssockioctl;
	#define EXT_syssockioctl  extern PFSYSSOCKIOCTL_IEC pfsyssockioctl;
	#define GET_syssockioctl(fl)  s_pfCMGetAPI2( "syssockioctl", (RTS_VOID_FCTPTR *)&pfsyssockioctl, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x408480FB), 0x03050F00)
	#define CAL_syssockioctl  pfsyssockioctl
	#define CHK_syssockioctl  (pfsyssockioctl != NULL)
	#define EXP_syssockioctl   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockioctl", (RTS_UINTPTR)syssockioctl, 1, RTSITF_GET_SIGNATURE(0, 0x408480FB), 0x03050F00) 
#endif


/**
 * | Listen on a TCP server socket for new connection.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssocklisten_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Handle to the socket */
	RTS_IEC_DINT diMaxConnections;		/* VAR_INPUT */	/* Maximum number of connections allowed */
	RTS_IEC_RESULT SysSockListen;		/* VAR_OUTPUT */	
} syssocklisten_struct;

void CDECL CDECL_EXT syssocklisten(syssocklisten_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKLISTEN_IEC) (syssocklisten_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKLISTEN_NOTIMPLEMENTED)
	#define USE_syssocklisten
	#define EXT_syssocklisten
	#define GET_syssocklisten(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssocklisten(p0) 
	#define CHK_syssocklisten  FALSE
	#define EXP_syssocklisten  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssocklisten
	#define EXT_syssocklisten
	#define GET_syssocklisten(fl)  CAL_CMGETAPI( "syssocklisten" ) 
	#define CAL_syssocklisten  syssocklisten
	#define CHK_syssocklisten  TRUE
	#define EXP_syssocklisten  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocklisten", (RTS_UINTPTR)syssocklisten, 1, RTSITF_GET_SIGNATURE(0, 0x30FE27C1), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssocklisten
	#define EXT_syssocklisten
	#define GET_syssocklisten(fl)  CAL_CMGETAPI( "syssocklisten" ) 
	#define CAL_syssocklisten  syssocklisten
	#define CHK_syssocklisten  TRUE
	#define EXP_syssocklisten  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocklisten", (RTS_UINTPTR)syssocklisten, 1, RTSITF_GET_SIGNATURE(0, 0x30FE27C1), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssocklisten
	#define EXT_SysSocket_Implementationsyssocklisten
	#define GET_SysSocket_Implementationsyssocklisten  ERR_OK
	#define CAL_SysSocket_Implementationsyssocklisten  syssocklisten
	#define CHK_SysSocket_Implementationsyssocklisten  TRUE
	#define EXP_SysSocket_Implementationsyssocklisten  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocklisten", (RTS_UINTPTR)syssocklisten, 1, RTSITF_GET_SIGNATURE(0, 0x30FE27C1), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssocklisten
	#define EXT_syssocklisten
	#define GET_syssocklisten(fl)  CAL_CMGETAPI( "syssocklisten" ) 
	#define CAL_syssocklisten  syssocklisten
	#define CHK_syssocklisten  TRUE
	#define EXP_syssocklisten  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocklisten", (RTS_UINTPTR)syssocklisten, 1, RTSITF_GET_SIGNATURE(0, 0x30FE27C1), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssocklisten  PFSYSSOCKLISTEN_IEC pfsyssocklisten;
	#define EXT_syssocklisten  extern PFSYSSOCKLISTEN_IEC pfsyssocklisten;
	#define GET_syssocklisten(fl)  s_pfCMGetAPI2( "syssocklisten", (RTS_VOID_FCTPTR *)&pfsyssocklisten, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x30FE27C1), 0x03050F00)
	#define CAL_syssocklisten  pfsyssocklisten
	#define CHK_syssocklisten  (pfsyssocklisten != NULL)
	#define EXP_syssocklisten   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocklisten", (RTS_UINTPTR)syssocklisten, 1, RTSITF_GET_SIGNATURE(0, 0x30FE27C1), 0x03050F00) 
#endif


/**
 * | Convert a UDINT value from ethernet byte order into host format.
 * :return: Converted UDINT value
 */
typedef struct tagsyssockntohl_struct
{
	RTS_IEC_UDINT ulNet;				/* VAR_INPUT */	/* Ethernet value */
	RTS_IEC_UDINT SysSockNtohl;			/* VAR_OUTPUT */	
} syssockntohl_struct;

void CDECL CDECL_EXT syssockntohl(syssockntohl_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKNTOHL_IEC) (syssockntohl_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKNTOHL_NOTIMPLEMENTED)
	#define USE_syssockntohl
	#define EXT_syssockntohl
	#define GET_syssockntohl(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockntohl(p0) 
	#define CHK_syssockntohl  FALSE
	#define EXP_syssockntohl  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockntohl
	#define EXT_syssockntohl
	#define GET_syssockntohl(fl)  CAL_CMGETAPI( "syssockntohl" ) 
	#define CAL_syssockntohl  syssockntohl
	#define CHK_syssockntohl  TRUE
	#define EXP_syssockntohl  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockntohl", (RTS_UINTPTR)syssockntohl, 1, RTSITF_GET_SIGNATURE(0, 0x05B31DF1), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockntohl
	#define EXT_syssockntohl
	#define GET_syssockntohl(fl)  CAL_CMGETAPI( "syssockntohl" ) 
	#define CAL_syssockntohl  syssockntohl
	#define CHK_syssockntohl  TRUE
	#define EXP_syssockntohl  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockntohl", (RTS_UINTPTR)syssockntohl, 1, RTSITF_GET_SIGNATURE(0, 0x05B31DF1), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockntohl
	#define EXT_SysSocket_Implementationsyssockntohl
	#define GET_SysSocket_Implementationsyssockntohl  ERR_OK
	#define CAL_SysSocket_Implementationsyssockntohl  syssockntohl
	#define CHK_SysSocket_Implementationsyssockntohl  TRUE
	#define EXP_SysSocket_Implementationsyssockntohl  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockntohl", (RTS_UINTPTR)syssockntohl, 1, RTSITF_GET_SIGNATURE(0, 0x05B31DF1), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockntohl
	#define EXT_syssockntohl
	#define GET_syssockntohl(fl)  CAL_CMGETAPI( "syssockntohl" ) 
	#define CAL_syssockntohl  syssockntohl
	#define CHK_syssockntohl  TRUE
	#define EXP_syssockntohl  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockntohl", (RTS_UINTPTR)syssockntohl, 1, RTSITF_GET_SIGNATURE(0, 0x05B31DF1), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockntohl  PFSYSSOCKNTOHL_IEC pfsyssockntohl;
	#define EXT_syssockntohl  extern PFSYSSOCKNTOHL_IEC pfsyssockntohl;
	#define GET_syssockntohl(fl)  s_pfCMGetAPI2( "syssockntohl", (RTS_VOID_FCTPTR *)&pfsyssockntohl, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x05B31DF1), 0x03050F00)
	#define CAL_syssockntohl  pfsyssockntohl
	#define CHK_syssockntohl  (pfsyssockntohl != NULL)
	#define EXP_syssockntohl   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockntohl", (RTS_UINTPTR)syssockntohl, 1, RTSITF_GET_SIGNATURE(0, 0x05B31DF1), 0x03050F00) 
#endif


/**
 * | Convert a WORD value from ethernet byte order into host format.
 * :return:Converted WORD value
 */
typedef struct tagsyssockntohs_struct
{
	RTS_IEC_WORD usNet;					/* VAR_INPUT */	/* Ethernet value */
	RTS_IEC_WORD SysSockNtohs;			/* VAR_OUTPUT */	
} syssockntohs_struct;

void CDECL CDECL_EXT syssockntohs(syssockntohs_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKNTOHS_IEC) (syssockntohs_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKNTOHS_NOTIMPLEMENTED)
	#define USE_syssockntohs
	#define EXT_syssockntohs
	#define GET_syssockntohs(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockntohs(p0) 
	#define CHK_syssockntohs  FALSE
	#define EXP_syssockntohs  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockntohs
	#define EXT_syssockntohs
	#define GET_syssockntohs(fl)  CAL_CMGETAPI( "syssockntohs" ) 
	#define CAL_syssockntohs  syssockntohs
	#define CHK_syssockntohs  TRUE
	#define EXP_syssockntohs  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockntohs", (RTS_UINTPTR)syssockntohs, 1, RTSITF_GET_SIGNATURE(0, 0x100E0417), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockntohs
	#define EXT_syssockntohs
	#define GET_syssockntohs(fl)  CAL_CMGETAPI( "syssockntohs" ) 
	#define CAL_syssockntohs  syssockntohs
	#define CHK_syssockntohs  TRUE
	#define EXP_syssockntohs  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockntohs", (RTS_UINTPTR)syssockntohs, 1, RTSITF_GET_SIGNATURE(0, 0x100E0417), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockntohs
	#define EXT_SysSocket_Implementationsyssockntohs
	#define GET_SysSocket_Implementationsyssockntohs  ERR_OK
	#define CAL_SysSocket_Implementationsyssockntohs  syssockntohs
	#define CHK_SysSocket_Implementationsyssockntohs  TRUE
	#define EXP_SysSocket_Implementationsyssockntohs  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockntohs", (RTS_UINTPTR)syssockntohs, 1, RTSITF_GET_SIGNATURE(0, 0x100E0417), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockntohs
	#define EXT_syssockntohs
	#define GET_syssockntohs(fl)  CAL_CMGETAPI( "syssockntohs" ) 
	#define CAL_syssockntohs  syssockntohs
	#define CHK_syssockntohs  TRUE
	#define EXP_syssockntohs  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockntohs", (RTS_UINTPTR)syssockntohs, 1, RTSITF_GET_SIGNATURE(0, 0x100E0417), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockntohs  PFSYSSOCKNTOHS_IEC pfsyssockntohs;
	#define EXT_syssockntohs  extern PFSYSSOCKNTOHS_IEC pfsyssockntohs;
	#define GET_syssockntohs(fl)  s_pfCMGetAPI2( "syssockntohs", (RTS_VOID_FCTPTR *)&pfsyssockntohs, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x100E0417), 0x03050F00)
	#define CAL_syssockntohs  pfsyssockntohs
	#define CHK_syssockntohs  (pfsyssockntohs != NULL)
	#define EXP_syssockntohs   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockntohs", (RTS_UINTPTR)syssockntohs, 1, RTSITF_GET_SIGNATURE(0, 0x100E0417), 0x03050F00) 
#endif


/**
 * | Check the availability of the communication partner with a ping request.
 * :return: Runtime system error code (see CmpErrors.library): 
 *		| ERR_OK:            Partner available
 *		| ERR_FAILED:        Partner cannot be reached
 *		| All other results: Ping could not be sent because of other errors, so we don't know, if the partner is available.
 */
typedef struct tagsyssockping_struct
{
	RTS_IEC_STRING *szIPAddress;		/* VAR_INPUT */	/* IP address of the communication partner as string */
	RTS_IEC_UDINT ulTimeout;			/* VAR_INPUT */	/* Timeout in milliseconds to wait until reply */
	RTS_IEC_UDINT *pulReplyTime;		/* VAR_INPUT */	/* Pointer to get average reply time of the ping request in milliseconds */
	RTS_IEC_RESULT SysSockPing;			/* VAR_OUTPUT */	
} syssockping_struct;

void CDECL CDECL_EXT syssockping(syssockping_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKPING_IEC) (syssockping_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKPING_NOTIMPLEMENTED)
	#define USE_syssockping
	#define EXT_syssockping
	#define GET_syssockping(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockping(p0) 
	#define CHK_syssockping  FALSE
	#define EXP_syssockping  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockping
	#define EXT_syssockping
	#define GET_syssockping(fl)  CAL_CMGETAPI( "syssockping" ) 
	#define CAL_syssockping  syssockping
	#define CHK_syssockping  TRUE
	#define EXP_syssockping  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockping", (RTS_UINTPTR)syssockping, 1, RTSITF_GET_SIGNATURE(0, 0xB3610A39), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockping
	#define EXT_syssockping
	#define GET_syssockping(fl)  CAL_CMGETAPI( "syssockping" ) 
	#define CAL_syssockping  syssockping
	#define CHK_syssockping  TRUE
	#define EXP_syssockping  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockping", (RTS_UINTPTR)syssockping, 1, RTSITF_GET_SIGNATURE(0, 0xB3610A39), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockping
	#define EXT_SysSocket_Implementationsyssockping
	#define GET_SysSocket_Implementationsyssockping  ERR_OK
	#define CAL_SysSocket_Implementationsyssockping  syssockping
	#define CHK_SysSocket_Implementationsyssockping  TRUE
	#define EXP_SysSocket_Implementationsyssockping  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockping", (RTS_UINTPTR)syssockping, 1, RTSITF_GET_SIGNATURE(0, 0xB3610A39), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockping
	#define EXT_syssockping
	#define GET_syssockping(fl)  CAL_CMGETAPI( "syssockping" ) 
	#define CAL_syssockping  syssockping
	#define CHK_syssockping  TRUE
	#define EXP_syssockping  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockping", (RTS_UINTPTR)syssockping, 1, RTSITF_GET_SIGNATURE(0, 0xB3610A39), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockping  PFSYSSOCKPING_IEC pfsyssockping;
	#define EXT_syssockping  extern PFSYSSOCKPING_IEC pfsyssockping;
	#define GET_syssockping(fl)  s_pfCMGetAPI2( "syssockping", (RTS_VOID_FCTPTR *)&pfsyssockping, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xB3610A39), 0x03050F00)
	#define CAL_syssockping  pfsyssockping
	#define CHK_syssockping  (pfsyssockping != NULL)
	#define EXP_syssockping   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockping", (RTS_UINTPTR)syssockping, 1, RTSITF_GET_SIGNATURE(0, 0xB3610A39), 0x03050F00) 
#endif


/**
 * | Receive data from a TCP socket.
 * :return: Number of bytes received. 0 if failed.
 */
typedef struct tagsyssockrecv_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Handle to the socket */
	RTS_IEC_BYTE *pbyBuffer;			/* VAR_INPUT */	/* Buffer to read data from the socket */
	RTS_IEC_XINT diBufferSize;			/* VAR_INPUT */	/* Maximum length of the buffer */
	RTS_IEC_DINT diFlags;				/* VAR_INPUT */	/* | The flags parameter can be used to influence the behavior of the 
	  function beyond the options specified for the associated socket. The semantics of this function 
	  are determined by the socket options and the flags parameter. The latter is constructed by using the
	  bitwise OR operator with any of the SOCKET_MSG values. See category TCP flags. */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_XINT SysSockRecv;			/* VAR_OUTPUT */	
} syssockrecv_struct;

void CDECL CDECL_EXT syssockrecv(syssockrecv_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKRECV_IEC) (syssockrecv_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKRECV_NOTIMPLEMENTED)
	#define USE_syssockrecv
	#define EXT_syssockrecv
	#define GET_syssockrecv(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockrecv(p0) 
	#define CHK_syssockrecv  FALSE
	#define EXP_syssockrecv  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockrecv
	#define EXT_syssockrecv
	#define GET_syssockrecv(fl)  CAL_CMGETAPI( "syssockrecv" ) 
	#define CAL_syssockrecv  syssockrecv
	#define CHK_syssockrecv  TRUE
	#define EXP_syssockrecv  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockrecv", (RTS_UINTPTR)syssockrecv, 1, RTSITF_GET_SIGNATURE(0, 0x887FBA6B), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockrecv
	#define EXT_syssockrecv
	#define GET_syssockrecv(fl)  CAL_CMGETAPI( "syssockrecv" ) 
	#define CAL_syssockrecv  syssockrecv
	#define CHK_syssockrecv  TRUE
	#define EXP_syssockrecv  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockrecv", (RTS_UINTPTR)syssockrecv, 1, RTSITF_GET_SIGNATURE(0, 0x887FBA6B), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockrecv
	#define EXT_SysSocket_Implementationsyssockrecv
	#define GET_SysSocket_Implementationsyssockrecv  ERR_OK
	#define CAL_SysSocket_Implementationsyssockrecv  syssockrecv
	#define CHK_SysSocket_Implementationsyssockrecv  TRUE
	#define EXP_SysSocket_Implementationsyssockrecv  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockrecv", (RTS_UINTPTR)syssockrecv, 1, RTSITF_GET_SIGNATURE(0, 0x887FBA6B), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockrecv
	#define EXT_syssockrecv
	#define GET_syssockrecv(fl)  CAL_CMGETAPI( "syssockrecv" ) 
	#define CAL_syssockrecv  syssockrecv
	#define CHK_syssockrecv  TRUE
	#define EXP_syssockrecv  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockrecv", (RTS_UINTPTR)syssockrecv, 1, RTSITF_GET_SIGNATURE(0, 0x887FBA6B), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockrecv  PFSYSSOCKRECV_IEC pfsyssockrecv;
	#define EXT_syssockrecv  extern PFSYSSOCKRECV_IEC pfsyssockrecv;
	#define GET_syssockrecv(fl)  s_pfCMGetAPI2( "syssockrecv", (RTS_VOID_FCTPTR *)&pfsyssockrecv, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x887FBA6B), 0x03050F00)
	#define CAL_syssockrecv  pfsyssockrecv
	#define CHK_syssockrecv  (pfsyssockrecv != NULL)
	#define EXP_syssockrecv   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockrecv", (RTS_UINTPTR)syssockrecv, 1, RTSITF_GET_SIGNATURE(0, 0x887FBA6B), 0x03050F00) 
#endif


/**
 * | Receive a message from a connectionless socket (UDP).
 * :return: Number of bytes received
 */
typedef struct tagsyssockrecvfrom_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Handle to the socket */
	RTS_IEC_BYTE *pbyBuffer;			/* VAR_INPUT */	/* Buffer to read data from the socket */
	RTS_IEC_XINT diBufferSize;			/* VAR_INPUT */	/* Maximum length of the buffer */
	RTS_IEC_DINT diFlags;				/* VAR_INPUT */	/* | The flags parameter can be used to influence the behavior of the 
	  function beyond the options specified for the associated socket. The semantics of this function 
	  are determined by the socket options and the flags parameter. The latter is constructed by using the
	  bitwise OR operator with any of the SOCKET_MSG values. */
	SOCKADDRESS *pSockAddr;				/* VAR_INPUT */	/* Socket address and port to receive data from */
	RTS_IEC_DINT diSockAddrSize;		/* VAR_INPUT */	/* Size of socket address structure */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_XINT SysSockRecvFrom;		/* VAR_OUTPUT */	
} syssockrecvfrom_struct;

void CDECL CDECL_EXT syssockrecvfrom(syssockrecvfrom_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKRECVFROM_IEC) (syssockrecvfrom_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKRECVFROM_NOTIMPLEMENTED)
	#define USE_syssockrecvfrom
	#define EXT_syssockrecvfrom
	#define GET_syssockrecvfrom(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockrecvfrom(p0) 
	#define CHK_syssockrecvfrom  FALSE
	#define EXP_syssockrecvfrom  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockrecvfrom
	#define EXT_syssockrecvfrom
	#define GET_syssockrecvfrom(fl)  CAL_CMGETAPI( "syssockrecvfrom" ) 
	#define CAL_syssockrecvfrom  syssockrecvfrom
	#define CHK_syssockrecvfrom  TRUE
	#define EXP_syssockrecvfrom  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockrecvfrom", (RTS_UINTPTR)syssockrecvfrom, 1, RTSITF_GET_SIGNATURE(0, 0x26DF0362), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockrecvfrom
	#define EXT_syssockrecvfrom
	#define GET_syssockrecvfrom(fl)  CAL_CMGETAPI( "syssockrecvfrom" ) 
	#define CAL_syssockrecvfrom  syssockrecvfrom
	#define CHK_syssockrecvfrom  TRUE
	#define EXP_syssockrecvfrom  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockrecvfrom", (RTS_UINTPTR)syssockrecvfrom, 1, RTSITF_GET_SIGNATURE(0, 0x26DF0362), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockrecvfrom
	#define EXT_SysSocket_Implementationsyssockrecvfrom
	#define GET_SysSocket_Implementationsyssockrecvfrom  ERR_OK
	#define CAL_SysSocket_Implementationsyssockrecvfrom  syssockrecvfrom
	#define CHK_SysSocket_Implementationsyssockrecvfrom  TRUE
	#define EXP_SysSocket_Implementationsyssockrecvfrom  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockrecvfrom", (RTS_UINTPTR)syssockrecvfrom, 1, RTSITF_GET_SIGNATURE(0, 0x26DF0362), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockrecvfrom
	#define EXT_syssockrecvfrom
	#define GET_syssockrecvfrom(fl)  CAL_CMGETAPI( "syssockrecvfrom" ) 
	#define CAL_syssockrecvfrom  syssockrecvfrom
	#define CHK_syssockrecvfrom  TRUE
	#define EXP_syssockrecvfrom  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockrecvfrom", (RTS_UINTPTR)syssockrecvfrom, 1, RTSITF_GET_SIGNATURE(0, 0x26DF0362), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockrecvfrom  PFSYSSOCKRECVFROM_IEC pfsyssockrecvfrom;
	#define EXT_syssockrecvfrom  extern PFSYSSOCKRECVFROM_IEC pfsyssockrecvfrom;
	#define GET_syssockrecvfrom(fl)  s_pfCMGetAPI2( "syssockrecvfrom", (RTS_VOID_FCTPTR *)&pfsyssockrecvfrom, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x26DF0362), 0x03050F00)
	#define CAL_syssockrecvfrom  pfsyssockrecvfrom
	#define CHK_syssockrecvfrom  (pfsyssockrecvfrom != NULL)
	#define EXP_syssockrecvfrom   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockrecvfrom", (RTS_UINTPTR)syssockrecvfrom, 1, RTSITF_GET_SIGNATURE(0, 0x26DF0362), 0x03050F00) 
#endif


/**
 * | Receive a paket from a UDP socket.
 * :return: Number of bytes received
 */
typedef struct tagsyssockrecvfromudp_struct
{
	RTS_IEC_HANDLE hSocketUdp;			/* VAR_INPUT */	/* Handle to the UDP socket */
	RTS_IEC_BYTE *pbyData;				/* VAR_INPUT */	/* Pointer to data to receive */
	RTS_IEC_XINT diDataSize;			/* VAR_INPUT */	/* Size of data to receive */
	UDP_REPLY *pReply;					/* VAR_INPUT */	/* Description of the client that has sent this paket */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_XINT SysSockRecvFromUdp;	/* VAR_OUTPUT */	
} syssockrecvfromudp_struct;

void CDECL CDECL_EXT syssockrecvfromudp(syssockrecvfromudp_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKRECVFROMUDP_IEC) (syssockrecvfromudp_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKRECVFROMUDP_NOTIMPLEMENTED)
	#define USE_syssockrecvfromudp
	#define EXT_syssockrecvfromudp
	#define GET_syssockrecvfromudp(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockrecvfromudp(p0) 
	#define CHK_syssockrecvfromudp  FALSE
	#define EXP_syssockrecvfromudp  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockrecvfromudp
	#define EXT_syssockrecvfromudp
	#define GET_syssockrecvfromudp(fl)  CAL_CMGETAPI( "syssockrecvfromudp" ) 
	#define CAL_syssockrecvfromudp  syssockrecvfromudp
	#define CHK_syssockrecvfromudp  TRUE
	#define EXP_syssockrecvfromudp  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockrecvfromudp", (RTS_UINTPTR)syssockrecvfromudp, 1, RTSITF_GET_SIGNATURE(0, 0x86A63EF8), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockrecvfromudp
	#define EXT_syssockrecvfromudp
	#define GET_syssockrecvfromudp(fl)  CAL_CMGETAPI( "syssockrecvfromudp" ) 
	#define CAL_syssockrecvfromudp  syssockrecvfromudp
	#define CHK_syssockrecvfromudp  TRUE
	#define EXP_syssockrecvfromudp  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockrecvfromudp", (RTS_UINTPTR)syssockrecvfromudp, 1, RTSITF_GET_SIGNATURE(0, 0x86A63EF8), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockrecvfromudp
	#define EXT_SysSocket_Implementationsyssockrecvfromudp
	#define GET_SysSocket_Implementationsyssockrecvfromudp  ERR_OK
	#define CAL_SysSocket_Implementationsyssockrecvfromudp  syssockrecvfromudp
	#define CHK_SysSocket_Implementationsyssockrecvfromudp  TRUE
	#define EXP_SysSocket_Implementationsyssockrecvfromudp  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockrecvfromudp", (RTS_UINTPTR)syssockrecvfromudp, 1, RTSITF_GET_SIGNATURE(0, 0x86A63EF8), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockrecvfromudp
	#define EXT_syssockrecvfromudp
	#define GET_syssockrecvfromudp(fl)  CAL_CMGETAPI( "syssockrecvfromudp" ) 
	#define CAL_syssockrecvfromudp  syssockrecvfromudp
	#define CHK_syssockrecvfromudp  TRUE
	#define EXP_syssockrecvfromudp  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockrecvfromudp", (RTS_UINTPTR)syssockrecvfromudp, 1, RTSITF_GET_SIGNATURE(0, 0x86A63EF8), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockrecvfromudp  PFSYSSOCKRECVFROMUDP_IEC pfsyssockrecvfromudp;
	#define EXT_syssockrecvfromudp  extern PFSYSSOCKRECVFROMUDP_IEC pfsyssockrecvfromudp;
	#define GET_syssockrecvfromudp(fl)  s_pfCMGetAPI2( "syssockrecvfromudp", (RTS_VOID_FCTPTR *)&pfsyssockrecvfromudp, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x86A63EF8), 0x03050F00)
	#define CAL_syssockrecvfromudp  pfsyssockrecvfromudp
	#define CHK_syssockrecvfromudp  (pfsyssockrecvfromudp != NULL)
	#define EXP_syssockrecvfromudp   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockrecvfromudp", (RTS_UINTPTR)syssockrecvfromudp, 1, RTSITF_GET_SIGNATURE(0, 0x86A63EF8), 0x03050F00) 
#endif


/**
 * | Receive a paket from a UDP socket.
 * :return: Number of bytes received
 */
typedef struct tagsyssockrecvfromudp2_struct
{
	RTS_IEC_HANDLE hSocketUdp;			/* VAR_INPUT */	/* Handle to the UDP socket */
	RTS_IEC_BYTE *pbyData;				/* VAR_INPUT */	/* Pointer to data to receive */
	RTS_IEC_XINT diDataSize;			/* VAR_INPUT */	/* Size of data to receive */
	UDP_REPLY2 *pReply;					/* VAR_INPUT */	/* Description of the client that has sent this paket */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_XINT SysSockRecvFromUdp2;	/* VAR_OUTPUT */	
} syssockrecvfromudp2_struct;

void CDECL CDECL_EXT syssockrecvfromudp2(syssockrecvfromudp2_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKRECVFROMUDP2_IEC) (syssockrecvfromudp2_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKRECVFROMUDP2_NOTIMPLEMENTED)
	#define USE_syssockrecvfromudp2
	#define EXT_syssockrecvfromudp2
	#define GET_syssockrecvfromudp2(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockrecvfromudp2(p0) 
	#define CHK_syssockrecvfromudp2  FALSE
	#define EXP_syssockrecvfromudp2  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockrecvfromudp2
	#define EXT_syssockrecvfromudp2
	#define GET_syssockrecvfromudp2(fl)  CAL_CMGETAPI( "syssockrecvfromudp2" ) 
	#define CAL_syssockrecvfromudp2  syssockrecvfromudp2
	#define CHK_syssockrecvfromudp2  TRUE
	#define EXP_syssockrecvfromudp2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockrecvfromudp2", (RTS_UINTPTR)syssockrecvfromudp2, 1, RTSITF_GET_SIGNATURE(0, 0xBA3470D3), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockrecvfromudp2
	#define EXT_syssockrecvfromudp2
	#define GET_syssockrecvfromudp2(fl)  CAL_CMGETAPI( "syssockrecvfromudp2" ) 
	#define CAL_syssockrecvfromudp2  syssockrecvfromudp2
	#define CHK_syssockrecvfromudp2  TRUE
	#define EXP_syssockrecvfromudp2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockrecvfromudp2", (RTS_UINTPTR)syssockrecvfromudp2, 1, RTSITF_GET_SIGNATURE(0, 0xBA3470D3), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockrecvfromudp2
	#define EXT_SysSocket_Implementationsyssockrecvfromudp2
	#define GET_SysSocket_Implementationsyssockrecvfromudp2  ERR_OK
	#define CAL_SysSocket_Implementationsyssockrecvfromudp2  syssockrecvfromudp2
	#define CHK_SysSocket_Implementationsyssockrecvfromudp2  TRUE
	#define EXP_SysSocket_Implementationsyssockrecvfromudp2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockrecvfromudp2", (RTS_UINTPTR)syssockrecvfromudp2, 1, RTSITF_GET_SIGNATURE(0, 0xBA3470D3), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockrecvfromudp2
	#define EXT_syssockrecvfromudp2
	#define GET_syssockrecvfromudp2(fl)  CAL_CMGETAPI( "syssockrecvfromudp2" ) 
	#define CAL_syssockrecvfromudp2  syssockrecvfromudp2
	#define CHK_syssockrecvfromudp2  TRUE
	#define EXP_syssockrecvfromudp2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockrecvfromudp2", (RTS_UINTPTR)syssockrecvfromudp2, 1, RTSITF_GET_SIGNATURE(0, 0xBA3470D3), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockrecvfromudp2  PFSYSSOCKRECVFROMUDP2_IEC pfsyssockrecvfromudp2;
	#define EXT_syssockrecvfromudp2  extern PFSYSSOCKRECVFROMUDP2_IEC pfsyssockrecvfromudp2;
	#define GET_syssockrecvfromudp2(fl)  s_pfCMGetAPI2( "syssockrecvfromudp2", (RTS_VOID_FCTPTR *)&pfsyssockrecvfromudp2, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xBA3470D3), 0x03050F00)
	#define CAL_syssockrecvfromudp2  pfsyssockrecvfromudp2
	#define CHK_syssockrecvfromudp2  (pfsyssockrecvfromudp2 != NULL)
	#define EXP_syssockrecvfromudp2   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockrecvfromudp2", (RTS_UINTPTR)syssockrecvfromudp2, 1, RTSITF_GET_SIGNATURE(0, 0xBA3470D3), 0x03050F00) 
#endif


/**
 * | Check a number of sockets for activity.
 * :return: Runtime system error code (see CmpErrors.library):
 *		| ERR_OK
 *		| ERR_SOCK_TIMEDOUT, if timeout expired
 */
typedef struct tagsyssockselect_struct
{
	RTS_IEC_DINT diWidth;				/* VAR_INPUT */	/* Number of sockets in the |SOCKET_FD_SET| structure, so |SOCKET_FD_SETSIZE| must be used here. */
	SOCKET_FD_SET *pfdRead;				/* VAR_INPUT */	/* Optional pointer to the structure |SOCKET_FD_SET| defining the socket set
 to be checked for reading. It is also possible to set this parameter to 0. */
	SOCKET_FD_SET *pfdWrite;			/* VAR_INPUT */	/* Optional pointer to the structure |SOCKET_FD_SET| defining the socket set
 to be checked for writing. It is also possible to set this parameter to 0. */
	SOCKET_FD_SET *pfdExcept;			/* VAR_INPUT */	/* Optional pointer to structure |SOCKET_FD_SET| that defines the socket set
 the error state has to be checked. It is also possible to set this parameter to 0. */
	SOCKET_TIMEVAL *ptvTimeout;			/* VAR_INPUT */	/* Pointer to maximum timespan which the function SysSockSelect waits for a response:
 	| ptvTimeout=NULL:	Infinite wait
 	| ptvTimeout->tv_sec=-1, ptvTimeout->tv_usec=-1:	Infinite wait
 	| ptvTimeout->tv_sec=0, ptvTimeout->tv_usec=0:	No wait */
	RTS_IEC_DINT *pdiReady;				/* VAR_INPUT */	/* Number of sockets that are ready for IO */
	RTS_IEC_RESULT SysSockSelect;		/* VAR_OUTPUT */	
} syssockselect_struct;

void CDECL CDECL_EXT syssockselect(syssockselect_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKSELECT_IEC) (syssockselect_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKSELECT_NOTIMPLEMENTED)
	#define USE_syssockselect
	#define EXT_syssockselect
	#define GET_syssockselect(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockselect(p0) 
	#define CHK_syssockselect  FALSE
	#define EXP_syssockselect  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockselect
	#define EXT_syssockselect
	#define GET_syssockselect(fl)  CAL_CMGETAPI( "syssockselect" ) 
	#define CAL_syssockselect  syssockselect
	#define CHK_syssockselect  TRUE
	#define EXP_syssockselect  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockselect", (RTS_UINTPTR)syssockselect, 1, RTSITF_GET_SIGNATURE(0, 0x59125CA7), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockselect
	#define EXT_syssockselect
	#define GET_syssockselect(fl)  CAL_CMGETAPI( "syssockselect" ) 
	#define CAL_syssockselect  syssockselect
	#define CHK_syssockselect  TRUE
	#define EXP_syssockselect  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockselect", (RTS_UINTPTR)syssockselect, 1, RTSITF_GET_SIGNATURE(0, 0x59125CA7), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockselect
	#define EXT_SysSocket_Implementationsyssockselect
	#define GET_SysSocket_Implementationsyssockselect  ERR_OK
	#define CAL_SysSocket_Implementationsyssockselect  syssockselect
	#define CHK_SysSocket_Implementationsyssockselect  TRUE
	#define EXP_SysSocket_Implementationsyssockselect  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockselect", (RTS_UINTPTR)syssockselect, 1, RTSITF_GET_SIGNATURE(0, 0x59125CA7), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockselect
	#define EXT_syssockselect
	#define GET_syssockselect(fl)  CAL_CMGETAPI( "syssockselect" ) 
	#define CAL_syssockselect  syssockselect
	#define CHK_syssockselect  TRUE
	#define EXP_syssockselect  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockselect", (RTS_UINTPTR)syssockselect, 1, RTSITF_GET_SIGNATURE(0, 0x59125CA7), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockselect  PFSYSSOCKSELECT_IEC pfsyssockselect;
	#define EXT_syssockselect  extern PFSYSSOCKSELECT_IEC pfsyssockselect;
	#define GET_syssockselect(fl)  s_pfCMGetAPI2( "syssockselect", (RTS_VOID_FCTPTR *)&pfsyssockselect, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x59125CA7), 0x03050F00)
	#define CAL_syssockselect  pfsyssockselect
	#define CHK_syssockselect  (pfsyssockselect != NULL)
	#define EXP_syssockselect   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockselect", (RTS_UINTPTR)syssockselect, 1, RTSITF_GET_SIGNATURE(0, 0x59125CA7), 0x03050F00) 
#endif


/**
 * | Sent data to a TCP socket.
 * :return: Number of sent bytes. 0 if failed.
 */
typedef struct tagsyssocksend_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Handle to the socket */
	RTS_IEC_BYTE *pbyBuffer;			/* VAR_INPUT */	/* Buffer with data to sent */
	RTS_IEC_XINT diBufferSize;			/* VAR_INPUT */	/* Maximum length of the buffer */
	RTS_IEC_DINT diFlags;				/* VAR_INPUT */	/* | The flags parameter can be used to influence the behavior of the 
	  function beyond the options specified for the associated socket. The semantics of this function 
	  are determined by the socket options and the flags parameter. The latter is constructed by using the
	  bitwise OR operator with any of the SOCKET_MSG values. */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_XINT SysSockSend;			/* VAR_OUTPUT */	
} syssocksend_struct;

void CDECL CDECL_EXT syssocksend(syssocksend_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKSEND_IEC) (syssocksend_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKSEND_NOTIMPLEMENTED)
	#define USE_syssocksend
	#define EXT_syssocksend
	#define GET_syssocksend(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssocksend(p0) 
	#define CHK_syssocksend  FALSE
	#define EXP_syssocksend  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssocksend
	#define EXT_syssocksend
	#define GET_syssocksend(fl)  CAL_CMGETAPI( "syssocksend" ) 
	#define CAL_syssocksend  syssocksend
	#define CHK_syssocksend  TRUE
	#define EXP_syssocksend  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksend", (RTS_UINTPTR)syssocksend, 1, RTSITF_GET_SIGNATURE(0, 0xA73C5F51), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssocksend
	#define EXT_syssocksend
	#define GET_syssocksend(fl)  CAL_CMGETAPI( "syssocksend" ) 
	#define CAL_syssocksend  syssocksend
	#define CHK_syssocksend  TRUE
	#define EXP_syssocksend  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksend", (RTS_UINTPTR)syssocksend, 1, RTSITF_GET_SIGNATURE(0, 0xA73C5F51), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssocksend
	#define EXT_SysSocket_Implementationsyssocksend
	#define GET_SysSocket_Implementationsyssocksend  ERR_OK
	#define CAL_SysSocket_Implementationsyssocksend  syssocksend
	#define CHK_SysSocket_Implementationsyssocksend  TRUE
	#define EXP_SysSocket_Implementationsyssocksend  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksend", (RTS_UINTPTR)syssocksend, 1, RTSITF_GET_SIGNATURE(0, 0xA73C5F51), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssocksend
	#define EXT_syssocksend
	#define GET_syssocksend(fl)  CAL_CMGETAPI( "syssocksend" ) 
	#define CAL_syssocksend  syssocksend
	#define CHK_syssocksend  TRUE
	#define EXP_syssocksend  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksend", (RTS_UINTPTR)syssocksend, 1, RTSITF_GET_SIGNATURE(0, 0xA73C5F51), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssocksend  PFSYSSOCKSEND_IEC pfsyssocksend;
	#define EXT_syssocksend  extern PFSYSSOCKSEND_IEC pfsyssocksend;
	#define GET_syssocksend(fl)  s_pfCMGetAPI2( "syssocksend", (RTS_VOID_FCTPTR *)&pfsyssocksend, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xA73C5F51), 0x03050F00)
	#define CAL_syssocksend  pfsyssocksend
	#define CHK_syssocksend  (pfsyssocksend != NULL)
	#define EXP_syssocksend   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksend", (RTS_UINTPTR)syssocksend, 1, RTSITF_GET_SIGNATURE(0, 0xA73C5F51), 0x03050F00) 
#endif


/**
 * | Send a message over a connectionless socket (UDP).
 * :return: Number of bytes received.
 */
typedef struct tagsyssocksendto_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Handle to the socket */
	RTS_IEC_BYTE *pbyBuffer;			/* VAR_INPUT */	/* Buffer with send data */
	RTS_IEC_XINT diBufferSize;			/* VAR_INPUT */	/* Length of data to send. If diBufferSize = 0 ERR_PARAMETER is returned */
	RTS_IEC_DINT diFlags;				/* VAR_INPUT */	/* | The flags parameter can be used to influence the behavior of the 
	  function beyond the options specified for the associated socket. The semantics of this function 
	  are determined by the socket options and the flags parameter. The latter is constructed by using the
	  bitwise OR operator with any of the SOCKET_MSG values. */
	SOCKADDRESS *pSockAddr;				/* VAR_INPUT */	/* Socket address and port to sent data to */
	RTS_IEC_DINT diSockAddrSize;		/* VAR_INPUT */	/* Size of socket address structure */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_XINT SysSockSendTo;			/* VAR_OUTPUT */	
} syssocksendto_struct;

void CDECL CDECL_EXT syssocksendto(syssocksendto_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKSENDTO_IEC) (syssocksendto_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKSENDTO_NOTIMPLEMENTED)
	#define USE_syssocksendto
	#define EXT_syssocksendto
	#define GET_syssocksendto(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssocksendto(p0) 
	#define CHK_syssocksendto  FALSE
	#define EXP_syssocksendto  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssocksendto
	#define EXT_syssocksendto
	#define GET_syssocksendto(fl)  CAL_CMGETAPI( "syssocksendto" ) 
	#define CAL_syssocksendto  syssocksendto
	#define CHK_syssocksendto  TRUE
	#define EXP_syssocksendto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksendto", (RTS_UINTPTR)syssocksendto, 1, RTSITF_GET_SIGNATURE(0, 0xEE37CAFA), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssocksendto
	#define EXT_syssocksendto
	#define GET_syssocksendto(fl)  CAL_CMGETAPI( "syssocksendto" ) 
	#define CAL_syssocksendto  syssocksendto
	#define CHK_syssocksendto  TRUE
	#define EXP_syssocksendto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksendto", (RTS_UINTPTR)syssocksendto, 1, RTSITF_GET_SIGNATURE(0, 0xEE37CAFA), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssocksendto
	#define EXT_SysSocket_Implementationsyssocksendto
	#define GET_SysSocket_Implementationsyssocksendto  ERR_OK
	#define CAL_SysSocket_Implementationsyssocksendto  syssocksendto
	#define CHK_SysSocket_Implementationsyssocksendto  TRUE
	#define EXP_SysSocket_Implementationsyssocksendto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksendto", (RTS_UINTPTR)syssocksendto, 1, RTSITF_GET_SIGNATURE(0, 0xEE37CAFA), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssocksendto
	#define EXT_syssocksendto
	#define GET_syssocksendto(fl)  CAL_CMGETAPI( "syssocksendto" ) 
	#define CAL_syssocksendto  syssocksendto
	#define CHK_syssocksendto  TRUE
	#define EXP_syssocksendto  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksendto", (RTS_UINTPTR)syssocksendto, 1, RTSITF_GET_SIGNATURE(0, 0xEE37CAFA), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssocksendto  PFSYSSOCKSENDTO_IEC pfsyssocksendto;
	#define EXT_syssocksendto  extern PFSYSSOCKSENDTO_IEC pfsyssocksendto;
	#define GET_syssocksendto(fl)  s_pfCMGetAPI2( "syssocksendto", (RTS_VOID_FCTPTR *)&pfsyssocksendto, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xEE37CAFA), 0x03050F00)
	#define CAL_syssocksendto  pfsyssocksendto
	#define CHK_syssocksendto  (pfsyssocksendto != NULL)
	#define EXP_syssocksendto   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksendto", (RTS_UINTPTR)syssocksendto, 1, RTSITF_GET_SIGNATURE(0, 0xEE37CAFA), 0x03050F00) 
#endif


/**
 * | Send a paket to a UDP socket.
 * :return: Number of bytes sent
 */
typedef struct tagsyssocksendtoudp_struct
{
	RTS_IEC_HANDLE hSocketUdp;			/* VAR_INPUT */	/* Handle to the UDP socket */
	RTS_IEC_DINT diPort;				/* VAR_INPUT */	/* Port number ot send data to */
	RTS_IEC_STRING *szDestAddress;		/* VAR_INPUT */	/* Destination IP address ot send data to */
	RTS_IEC_BYTE *pbyData;				/* VAR_INPUT */	/* Pointer to data to send */
	RTS_IEC_XINT diDataSize;			/* VAR_INPUT */	/* Size of data to send. If diDataSize = 0 ERR_PARAMETER is returned. */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_XINT SysSockSendToUdp;		/* VAR_OUTPUT */	
} syssocksendtoudp_struct;

void CDECL CDECL_EXT syssocksendtoudp(syssocksendtoudp_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKSENDTOUDP_IEC) (syssocksendtoudp_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKSENDTOUDP_NOTIMPLEMENTED)
	#define USE_syssocksendtoudp
	#define EXT_syssocksendtoudp
	#define GET_syssocksendtoudp(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssocksendtoudp(p0) 
	#define CHK_syssocksendtoudp  FALSE
	#define EXP_syssocksendtoudp  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssocksendtoudp
	#define EXT_syssocksendtoudp
	#define GET_syssocksendtoudp(fl)  CAL_CMGETAPI( "syssocksendtoudp" ) 
	#define CAL_syssocksendtoudp  syssocksendtoudp
	#define CHK_syssocksendtoudp  TRUE
	#define EXP_syssocksendtoudp  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksendtoudp", (RTS_UINTPTR)syssocksendtoudp, 1, RTSITF_GET_SIGNATURE(0, 0x81DCE32E), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssocksendtoudp
	#define EXT_syssocksendtoudp
	#define GET_syssocksendtoudp(fl)  CAL_CMGETAPI( "syssocksendtoudp" ) 
	#define CAL_syssocksendtoudp  syssocksendtoudp
	#define CHK_syssocksendtoudp  TRUE
	#define EXP_syssocksendtoudp  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksendtoudp", (RTS_UINTPTR)syssocksendtoudp, 1, RTSITF_GET_SIGNATURE(0, 0x81DCE32E), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssocksendtoudp
	#define EXT_SysSocket_Implementationsyssocksendtoudp
	#define GET_SysSocket_Implementationsyssocksendtoudp  ERR_OK
	#define CAL_SysSocket_Implementationsyssocksendtoudp  syssocksendtoudp
	#define CHK_SysSocket_Implementationsyssocksendtoudp  TRUE
	#define EXP_SysSocket_Implementationsyssocksendtoudp  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksendtoudp", (RTS_UINTPTR)syssocksendtoudp, 1, RTSITF_GET_SIGNATURE(0, 0x81DCE32E), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssocksendtoudp
	#define EXT_syssocksendtoudp
	#define GET_syssocksendtoudp(fl)  CAL_CMGETAPI( "syssocksendtoudp" ) 
	#define CAL_syssocksendtoudp  syssocksendtoudp
	#define CHK_syssocksendtoudp  TRUE
	#define EXP_syssocksendtoudp  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksendtoudp", (RTS_UINTPTR)syssocksendtoudp, 1, RTSITF_GET_SIGNATURE(0, 0x81DCE32E), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssocksendtoudp  PFSYSSOCKSENDTOUDP_IEC pfsyssocksendtoudp;
	#define EXT_syssocksendtoudp  extern PFSYSSOCKSENDTOUDP_IEC pfsyssocksendtoudp;
	#define GET_syssocksendtoudp(fl)  s_pfCMGetAPI2( "syssocksendtoudp", (RTS_VOID_FCTPTR *)&pfsyssocksendtoudp, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x81DCE32E), 0x03050F00)
	#define CAL_syssocksendtoudp  pfsyssocksendtoudp
	#define CHK_syssocksendtoudp  (pfsyssocksendtoudp != NULL)
	#define EXP_syssocksendtoudp   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksendtoudp", (RTS_UINTPTR)syssocksendtoudp, 1, RTSITF_GET_SIGNATURE(0, 0x81DCE32E), 0x03050F00) 
#endif


/**
 * Set default gateway address an adapter. 
 * It depends on the device, whether the new gateway address is reset during reboot or
 * if it is retained. In general the caller should consider this as volatile. The 
 * gateway address = 0.0.0.0 can be used to remove the gateway address from the adapter. 
 * After this there is not routing to other subnets possible.
 * 
 * .. note::
 *     The default gateway can only be changed if the adapter containing
 *     the current default gateway is whitelisted in the CODESYSControl.cfg. This function
 *     will not change the default gateway of any other adapter.
 *
 * :return: Returns the runtime system error code (see CmpErrors.library):
 *     - ERR_PARAMETER: At least one of the passed pointers is NULL.
 *	    - ERR_OPERATION_DENIED: Adapter is not in white list or the operation was denied by the event EVT_SysSocket_BeforeSetGateway.
 *	    - ERR_NO_OBJECT: Adapter with the specified name does not exist.
 *	    - ERR_NO_CHANGE: There is a default gateway set on an adapter that is not whitelisted.
 *	    - ERR_FAILED: Default gateway could not be set.
 *	    - ERR_OK: Default gateway was set successfully.
 */
typedef struct tagsyssocksetdefaultgateway_struct
{
	RTS_IEC_WSTRING *wsAdapterName;		/* VAR_INPUT */	/* Adapter name provided by SysSockGetFirstAdapter() / SysSockGetNextAdapter() */
	INADDR *GatewayAddr;				/* VAR_INPUT */	/* Ip address of the gateway to set in network byte order. */
	RTS_IEC_RESULT SysSockSetDefaultGateway;	/* VAR_OUTPUT */	
} syssocksetdefaultgateway_struct;

void CDECL CDECL_EXT syssocksetdefaultgateway(syssocksetdefaultgateway_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKSETDEFAULTGATEWAY_IEC) (syssocksetdefaultgateway_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKSETDEFAULTGATEWAY_NOTIMPLEMENTED)
	#define USE_syssocksetdefaultgateway
	#define EXT_syssocksetdefaultgateway
	#define GET_syssocksetdefaultgateway(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssocksetdefaultgateway(p0) 
	#define CHK_syssocksetdefaultgateway  FALSE
	#define EXP_syssocksetdefaultgateway  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssocksetdefaultgateway
	#define EXT_syssocksetdefaultgateway
	#define GET_syssocksetdefaultgateway(fl)  CAL_CMGETAPI( "syssocksetdefaultgateway" ) 
	#define CAL_syssocksetdefaultgateway  syssocksetdefaultgateway
	#define CHK_syssocksetdefaultgateway  TRUE
	#define EXP_syssocksetdefaultgateway  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksetdefaultgateway", (RTS_UINTPTR)syssocksetdefaultgateway, 1, 0xB87B1303, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssocksetdefaultgateway
	#define EXT_syssocksetdefaultgateway
	#define GET_syssocksetdefaultgateway(fl)  CAL_CMGETAPI( "syssocksetdefaultgateway" ) 
	#define CAL_syssocksetdefaultgateway  syssocksetdefaultgateway
	#define CHK_syssocksetdefaultgateway  TRUE
	#define EXP_syssocksetdefaultgateway  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksetdefaultgateway", (RTS_UINTPTR)syssocksetdefaultgateway, 1, 0xB87B1303, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssocksetdefaultgateway
	#define EXT_SysSocket_Implementationsyssocksetdefaultgateway
	#define GET_SysSocket_Implementationsyssocksetdefaultgateway  ERR_OK
	#define CAL_SysSocket_Implementationsyssocksetdefaultgateway  syssocksetdefaultgateway
	#define CHK_SysSocket_Implementationsyssocksetdefaultgateway  TRUE
	#define EXP_SysSocket_Implementationsyssocksetdefaultgateway  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksetdefaultgateway", (RTS_UINTPTR)syssocksetdefaultgateway, 1, 0xB87B1303, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssocksetdefaultgateway
	#define EXT_syssocksetdefaultgateway
	#define GET_syssocksetdefaultgateway(fl)  CAL_CMGETAPI( "syssocksetdefaultgateway" ) 
	#define CAL_syssocksetdefaultgateway  syssocksetdefaultgateway
	#define CHK_syssocksetdefaultgateway  TRUE
	#define EXP_syssocksetdefaultgateway  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksetdefaultgateway", (RTS_UINTPTR)syssocksetdefaultgateway, 1, 0xB87B1303, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssocksetdefaultgateway  PFSYSSOCKSETDEFAULTGATEWAY_IEC pfsyssocksetdefaultgateway;
	#define EXT_syssocksetdefaultgateway  extern PFSYSSOCKSETDEFAULTGATEWAY_IEC pfsyssocksetdefaultgateway;
	#define GET_syssocksetdefaultgateway(fl)  s_pfCMGetAPI2( "syssocksetdefaultgateway", (RTS_VOID_FCTPTR *)&pfsyssocksetdefaultgateway, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xB87B1303, 0x03050F00)
	#define CAL_syssocksetdefaultgateway  pfsyssocksetdefaultgateway
	#define CHK_syssocksetdefaultgateway  (pfsyssocksetdefaultgateway != NULL)
	#define EXP_syssocksetdefaultgateway   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksetdefaultgateway", (RTS_UINTPTR)syssocksetdefaultgateway, 1, 0xB87B1303, 0x03050F00) 
#endif


/**
 * | Set IP address of the specified ethernet device. Is not available on all platforms! 
 * | Use SysSockSetIpAddressAndNetMask() instead.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssocksetipaddress_struct
{
	RTS_IEC_STRING *szCard;				/* VAR_INPUT */	/* Name of the ethernet card (aka adapter name) */
	RTS_IEC_STRING *szIPAddress;		/* VAR_INPUT */	/* IP address to set as string */
	RTS_IEC_RESULT SysSockSetIPAddress;	/* VAR_OUTPUT */	
} syssocksetipaddress_struct;

void CDECL CDECL_EXT syssocksetipaddress(syssocksetipaddress_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKSETIPADDRESS_IEC) (syssocksetipaddress_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKSETIPADDRESS_NOTIMPLEMENTED)
	#define USE_syssocksetipaddress
	#define EXT_syssocksetipaddress
	#define GET_syssocksetipaddress(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssocksetipaddress(p0) 
	#define CHK_syssocksetipaddress  FALSE
	#define EXP_syssocksetipaddress  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssocksetipaddress
	#define EXT_syssocksetipaddress
	#define GET_syssocksetipaddress(fl)  CAL_CMGETAPI( "syssocksetipaddress" ) 
	#define CAL_syssocksetipaddress  syssocksetipaddress
	#define CHK_syssocksetipaddress  TRUE
	#define EXP_syssocksetipaddress  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksetipaddress", (RTS_UINTPTR)syssocksetipaddress, 1, RTSITF_GET_SIGNATURE(0, 0x955CE64B), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssocksetipaddress
	#define EXT_syssocksetipaddress
	#define GET_syssocksetipaddress(fl)  CAL_CMGETAPI( "syssocksetipaddress" ) 
	#define CAL_syssocksetipaddress  syssocksetipaddress
	#define CHK_syssocksetipaddress  TRUE
	#define EXP_syssocksetipaddress  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksetipaddress", (RTS_UINTPTR)syssocksetipaddress, 1, RTSITF_GET_SIGNATURE(0, 0x955CE64B), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssocksetipaddress
	#define EXT_SysSocket_Implementationsyssocksetipaddress
	#define GET_SysSocket_Implementationsyssocksetipaddress  ERR_OK
	#define CAL_SysSocket_Implementationsyssocksetipaddress  syssocksetipaddress
	#define CHK_SysSocket_Implementationsyssocksetipaddress  TRUE
	#define EXP_SysSocket_Implementationsyssocksetipaddress  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksetipaddress", (RTS_UINTPTR)syssocksetipaddress, 1, RTSITF_GET_SIGNATURE(0, 0x955CE64B), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssocksetipaddress
	#define EXT_syssocksetipaddress
	#define GET_syssocksetipaddress(fl)  CAL_CMGETAPI( "syssocksetipaddress" ) 
	#define CAL_syssocksetipaddress  syssocksetipaddress
	#define CHK_syssocksetipaddress  TRUE
	#define EXP_syssocksetipaddress  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksetipaddress", (RTS_UINTPTR)syssocksetipaddress, 1, RTSITF_GET_SIGNATURE(0, 0x955CE64B), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssocksetipaddress  PFSYSSOCKSETIPADDRESS_IEC pfsyssocksetipaddress;
	#define EXT_syssocksetipaddress  extern PFSYSSOCKSETIPADDRESS_IEC pfsyssocksetipaddress;
	#define GET_syssocksetipaddress(fl)  s_pfCMGetAPI2( "syssocksetipaddress", (RTS_VOID_FCTPTR *)&pfsyssocksetipaddress, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x955CE64B), 0x03050F00)
	#define CAL_syssocksetipaddress  pfsyssocksetipaddress
	#define CHK_syssocksetipaddress  (pfsyssocksetipaddress != NULL)
	#define EXP_syssocksetipaddress   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksetipaddress", (RTS_UINTPTR)syssocksetipaddress, 1, RTSITF_GET_SIGNATURE(0, 0x955CE64B), 0x03050F00) 
#endif


/**
 * | Set IP address and subnet mask of an adapter. 
 * | It depends on the device, whether the new ip address and subnet mask is reset during reboot or
 *   if it is retained. In general the caller should consider these as volatile. The combination 
 *   IP address = 0.0.0.0 and subnet mask = 0.0.0.0 can be used to remove the IP address from the adapter.
 *   After this there is no IP based communication possible anymore, until a new IP address is set.
 *   Replaces the functions SysSockSetIPAddress() and SysSockSetSubnetMask().
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssocksetipaddressandnetmask_struct
{
	RTS_IEC_WSTRING *wsAdapterName;		/* VAR_INPUT */	/* Adapter name provided by SysSockGetFirstAdapter() / SysSockGetNextAdapter() */
	INADDR *IpAddr;						/* VAR_INPUT */	/* Ip address to set in network byte order */
	INADDR *NetMask;					/* VAR_INPUT */	/* Subnet mask to set in network byte order */
	RTS_IEC_RESULT SysSockSetIpAddressAndNetMask;	/* VAR_OUTPUT */	
} syssocksetipaddressandnetmask_struct;

void CDECL CDECL_EXT syssocksetipaddressandnetmask(syssocksetipaddressandnetmask_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKSETIPADDRESSANDNETMASK_IEC) (syssocksetipaddressandnetmask_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKSETIPADDRESSANDNETMASK_NOTIMPLEMENTED)
	#define USE_syssocksetipaddressandnetmask
	#define EXT_syssocksetipaddressandnetmask
	#define GET_syssocksetipaddressandnetmask(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssocksetipaddressandnetmask(p0) 
	#define CHK_syssocksetipaddressandnetmask  FALSE
	#define EXP_syssocksetipaddressandnetmask  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssocksetipaddressandnetmask
	#define EXT_syssocksetipaddressandnetmask
	#define GET_syssocksetipaddressandnetmask(fl)  CAL_CMGETAPI( "syssocksetipaddressandnetmask" ) 
	#define CAL_syssocksetipaddressandnetmask  syssocksetipaddressandnetmask
	#define CHK_syssocksetipaddressandnetmask  TRUE
	#define EXP_syssocksetipaddressandnetmask  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksetipaddressandnetmask", (RTS_UINTPTR)syssocksetipaddressandnetmask, 1, 0x01D16C55, 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssocksetipaddressandnetmask
	#define EXT_syssocksetipaddressandnetmask
	#define GET_syssocksetipaddressandnetmask(fl)  CAL_CMGETAPI( "syssocksetipaddressandnetmask" ) 
	#define CAL_syssocksetipaddressandnetmask  syssocksetipaddressandnetmask
	#define CHK_syssocksetipaddressandnetmask  TRUE
	#define EXP_syssocksetipaddressandnetmask  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksetipaddressandnetmask", (RTS_UINTPTR)syssocksetipaddressandnetmask, 1, 0x01D16C55, 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssocksetipaddressandnetmask
	#define EXT_SysSocket_Implementationsyssocksetipaddressandnetmask
	#define GET_SysSocket_Implementationsyssocksetipaddressandnetmask  ERR_OK
	#define CAL_SysSocket_Implementationsyssocksetipaddressandnetmask  syssocksetipaddressandnetmask
	#define CHK_SysSocket_Implementationsyssocksetipaddressandnetmask  TRUE
	#define EXP_SysSocket_Implementationsyssocksetipaddressandnetmask  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksetipaddressandnetmask", (RTS_UINTPTR)syssocksetipaddressandnetmask, 1, 0x01D16C55, 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssocksetipaddressandnetmask
	#define EXT_syssocksetipaddressandnetmask
	#define GET_syssocksetipaddressandnetmask(fl)  CAL_CMGETAPI( "syssocksetipaddressandnetmask" ) 
	#define CAL_syssocksetipaddressandnetmask  syssocksetipaddressandnetmask
	#define CHK_syssocksetipaddressandnetmask  TRUE
	#define EXP_syssocksetipaddressandnetmask  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksetipaddressandnetmask", (RTS_UINTPTR)syssocksetipaddressandnetmask, 1, 0x01D16C55, 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssocksetipaddressandnetmask  PFSYSSOCKSETIPADDRESSANDNETMASK_IEC pfsyssocksetipaddressandnetmask;
	#define EXT_syssocksetipaddressandnetmask  extern PFSYSSOCKSETIPADDRESSANDNETMASK_IEC pfsyssocksetipaddressandnetmask;
	#define GET_syssocksetipaddressandnetmask(fl)  s_pfCMGetAPI2( "syssocksetipaddressandnetmask", (RTS_VOID_FCTPTR *)&pfsyssocksetipaddressandnetmask, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x01D16C55, 0x03050F00)
	#define CAL_syssocksetipaddressandnetmask  pfsyssocksetipaddressandnetmask
	#define CHK_syssocksetipaddressandnetmask  (pfsyssocksetipaddressandnetmask != NULL)
	#define EXP_syssocksetipaddressandnetmask   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksetipaddressandnetmask", (RTS_UINTPTR)syssocksetipaddressandnetmask, 1, 0x01D16C55, 0x03050F00) 
#endif


/**
 * | Set options of a specified socket.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssocksetoption_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Handle to the socket */
	RTS_IEC_DINT diLevel;				/* VAR_INPUT */	/* Level of the socket */
	RTS_IEC_DINT diOption;				/* VAR_INPUT */	/* Socket option command */
	RTS_IEC_DINT *pdiOptionValue;		/* VAR_INPUT */	/* Pointer to the option value */
	RTS_IEC_DINT diOptionLen;			/* VAR_INPUT */	/* Lenght of option value */
	RTS_IEC_RESULT SysSockSetOption;	/* VAR_OUTPUT */	
} syssocksetoption_struct;

void CDECL CDECL_EXT syssocksetoption(syssocksetoption_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKSETOPTION_IEC) (syssocksetoption_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKSETOPTION_NOTIMPLEMENTED)
	#define USE_syssocksetoption
	#define EXT_syssocksetoption
	#define GET_syssocksetoption(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssocksetoption(p0) 
	#define CHK_syssocksetoption  FALSE
	#define EXP_syssocksetoption  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssocksetoption
	#define EXT_syssocksetoption
	#define GET_syssocksetoption(fl)  CAL_CMGETAPI( "syssocksetoption" ) 
	#define CAL_syssocksetoption  syssocksetoption
	#define CHK_syssocksetoption  TRUE
	#define EXP_syssocksetoption  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksetoption", (RTS_UINTPTR)syssocksetoption, 1, RTSITF_GET_SIGNATURE(0, 0xFBCD9B23), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssocksetoption
	#define EXT_syssocksetoption
	#define GET_syssocksetoption(fl)  CAL_CMGETAPI( "syssocksetoption" ) 
	#define CAL_syssocksetoption  syssocksetoption
	#define CHK_syssocksetoption  TRUE
	#define EXP_syssocksetoption  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksetoption", (RTS_UINTPTR)syssocksetoption, 1, RTSITF_GET_SIGNATURE(0, 0xFBCD9B23), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssocksetoption
	#define EXT_SysSocket_Implementationsyssocksetoption
	#define GET_SysSocket_Implementationsyssocksetoption  ERR_OK
	#define CAL_SysSocket_Implementationsyssocksetoption  syssocksetoption
	#define CHK_SysSocket_Implementationsyssocksetoption  TRUE
	#define EXP_SysSocket_Implementationsyssocksetoption  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksetoption", (RTS_UINTPTR)syssocksetoption, 1, RTSITF_GET_SIGNATURE(0, 0xFBCD9B23), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssocksetoption
	#define EXT_syssocksetoption
	#define GET_syssocksetoption(fl)  CAL_CMGETAPI( "syssocksetoption" ) 
	#define CAL_syssocksetoption  syssocksetoption
	#define CHK_syssocksetoption  TRUE
	#define EXP_syssocksetoption  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksetoption", (RTS_UINTPTR)syssocksetoption, 1, RTSITF_GET_SIGNATURE(0, 0xFBCD9B23), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssocksetoption  PFSYSSOCKSETOPTION_IEC pfsyssocksetoption;
	#define EXT_syssocksetoption  extern PFSYSSOCKSETOPTION_IEC pfsyssocksetoption;
	#define GET_syssocksetoption(fl)  s_pfCMGetAPI2( "syssocksetoption", (RTS_VOID_FCTPTR *)&pfsyssocksetoption, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xFBCD9B23), 0x03050F00)
	#define CAL_syssocksetoption  pfsyssocksetoption
	#define CHK_syssocksetoption  (pfsyssocksetoption != NULL)
	#define EXP_syssocksetoption   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksetoption", (RTS_UINTPTR)syssocksetoption, 1, RTSITF_GET_SIGNATURE(0, 0xFBCD9B23), 0x03050F00) 
#endif


/**
 * | Set subnetmask of an adapter, specified by IP address. Is not available on all platforms!
 * | Use SysSockSetIpAddressAndNetMask() instead.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssocksetsubnetmask_struct
{
	RTS_IEC_STRING *szIPAddress;		/* VAR_INPUT */	/* IP address of the communication partner as string */
	RTS_IEC_STRING *szSubnetMask;		/* VAR_INPUT */	/* Subnet mask as string */
	RTS_IEC_RESULT SysSockSetSubnetMask;	/* VAR_OUTPUT */	
} syssocksetsubnetmask_struct;

void CDECL CDECL_EXT syssocksetsubnetmask(syssocksetsubnetmask_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKSETSUBNETMASK_IEC) (syssocksetsubnetmask_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKSETSUBNETMASK_NOTIMPLEMENTED)
	#define USE_syssocksetsubnetmask
	#define EXT_syssocksetsubnetmask
	#define GET_syssocksetsubnetmask(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssocksetsubnetmask(p0) 
	#define CHK_syssocksetsubnetmask  FALSE
	#define EXP_syssocksetsubnetmask  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssocksetsubnetmask
	#define EXT_syssocksetsubnetmask
	#define GET_syssocksetsubnetmask(fl)  CAL_CMGETAPI( "syssocksetsubnetmask" ) 
	#define CAL_syssocksetsubnetmask  syssocksetsubnetmask
	#define CHK_syssocksetsubnetmask  TRUE
	#define EXP_syssocksetsubnetmask  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksetsubnetmask", (RTS_UINTPTR)syssocksetsubnetmask, 1, RTSITF_GET_SIGNATURE(0, 0x0185BC67), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssocksetsubnetmask
	#define EXT_syssocksetsubnetmask
	#define GET_syssocksetsubnetmask(fl)  CAL_CMGETAPI( "syssocksetsubnetmask" ) 
	#define CAL_syssocksetsubnetmask  syssocksetsubnetmask
	#define CHK_syssocksetsubnetmask  TRUE
	#define EXP_syssocksetsubnetmask  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksetsubnetmask", (RTS_UINTPTR)syssocksetsubnetmask, 1, RTSITF_GET_SIGNATURE(0, 0x0185BC67), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssocksetsubnetmask
	#define EXT_SysSocket_Implementationsyssocksetsubnetmask
	#define GET_SysSocket_Implementationsyssocksetsubnetmask  ERR_OK
	#define CAL_SysSocket_Implementationsyssocksetsubnetmask  syssocksetsubnetmask
	#define CHK_SysSocket_Implementationsyssocksetsubnetmask  TRUE
	#define EXP_SysSocket_Implementationsyssocksetsubnetmask  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksetsubnetmask", (RTS_UINTPTR)syssocksetsubnetmask, 1, RTSITF_GET_SIGNATURE(0, 0x0185BC67), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssocksetsubnetmask
	#define EXT_syssocksetsubnetmask
	#define GET_syssocksetsubnetmask(fl)  CAL_CMGETAPI( "syssocksetsubnetmask" ) 
	#define CAL_syssocksetsubnetmask  syssocksetsubnetmask
	#define CHK_syssocksetsubnetmask  TRUE
	#define EXP_syssocksetsubnetmask  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksetsubnetmask", (RTS_UINTPTR)syssocksetsubnetmask, 1, RTSITF_GET_SIGNATURE(0, 0x0185BC67), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssocksetsubnetmask  PFSYSSOCKSETSUBNETMASK_IEC pfsyssocksetsubnetmask;
	#define EXT_syssocksetsubnetmask  extern PFSYSSOCKSETSUBNETMASK_IEC pfsyssocksetsubnetmask;
	#define GET_syssocksetsubnetmask(fl)  s_pfCMGetAPI2( "syssocksetsubnetmask", (RTS_VOID_FCTPTR *)&pfsyssocksetsubnetmask, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x0185BC67), 0x03050F00)
	#define CAL_syssocksetsubnetmask  pfsyssocksetsubnetmask
	#define CHK_syssocksetsubnetmask  (pfsyssocksetsubnetmask != NULL)
	#define EXP_syssocksetsubnetmask   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssocksetsubnetmask", (RTS_UINTPTR)syssocksetsubnetmask, 1, RTSITF_GET_SIGNATURE(0, 0x0185BC67), 0x03050F00) 
#endif


/**
 * | Shutdown a socket.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockshutdown_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Handle to the socket */
	RTS_IEC_DINT diHow;					/* VAR_INPUT */	/* Specifies, which operations are no longer be allowed. See shutdown flags. */
	RTS_IEC_RESULT SysSockShutdown;		/* VAR_OUTPUT */	
} syssockshutdown_struct;

void CDECL CDECL_EXT syssockshutdown(syssockshutdown_struct *p);
typedef void (CDECL CDECL_EXT* PFSYSSOCKSHUTDOWN_IEC) (syssockshutdown_struct *p);
#if defined(SYSSOCKET_IMPLEMENTATION_NOTIMPLEMENTED) || defined(SYSSOCKSHUTDOWN_NOTIMPLEMENTED)
	#define USE_syssockshutdown
	#define EXT_syssockshutdown
	#define GET_syssockshutdown(fl)  ERR_NOTIMPLEMENTED
	#define CAL_syssockshutdown(p0) 
	#define CHK_syssockshutdown  FALSE
	#define EXP_syssockshutdown  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_syssockshutdown
	#define EXT_syssockshutdown
	#define GET_syssockshutdown(fl)  CAL_CMGETAPI( "syssockshutdown" ) 
	#define CAL_syssockshutdown  syssockshutdown
	#define CHK_syssockshutdown  TRUE
	#define EXP_syssockshutdown  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockshutdown", (RTS_UINTPTR)syssockshutdown, 1, RTSITF_GET_SIGNATURE(0, 0xCB0E612E), 0x03050F00) 
#elif defined(MIXED_LINK) && !defined(SYSSOCKET_IMPLEMENTATION_EXTERNAL)
	#define USE_syssockshutdown
	#define EXT_syssockshutdown
	#define GET_syssockshutdown(fl)  CAL_CMGETAPI( "syssockshutdown" ) 
	#define CAL_syssockshutdown  syssockshutdown
	#define CHK_syssockshutdown  TRUE
	#define EXP_syssockshutdown  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockshutdown", (RTS_UINTPTR)syssockshutdown, 1, RTSITF_GET_SIGNATURE(0, 0xCB0E612E), 0x03050F00) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysSocket_Implementationsyssockshutdown
	#define EXT_SysSocket_Implementationsyssockshutdown
	#define GET_SysSocket_Implementationsyssockshutdown  ERR_OK
	#define CAL_SysSocket_Implementationsyssockshutdown  syssockshutdown
	#define CHK_SysSocket_Implementationsyssockshutdown  TRUE
	#define EXP_SysSocket_Implementationsyssockshutdown  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockshutdown", (RTS_UINTPTR)syssockshutdown, 1, RTSITF_GET_SIGNATURE(0, 0xCB0E612E), 0x03050F00) 
#elif defined(CPLUSPLUS)
	#define USE_syssockshutdown
	#define EXT_syssockshutdown
	#define GET_syssockshutdown(fl)  CAL_CMGETAPI( "syssockshutdown" ) 
	#define CAL_syssockshutdown  syssockshutdown
	#define CHK_syssockshutdown  TRUE
	#define EXP_syssockshutdown  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockshutdown", (RTS_UINTPTR)syssockshutdown, 1, RTSITF_GET_SIGNATURE(0, 0xCB0E612E), 0x03050F00) 
#else /* DYNAMIC_LINK */
	#define USE_syssockshutdown  PFSYSSOCKSHUTDOWN_IEC pfsyssockshutdown;
	#define EXT_syssockshutdown  extern PFSYSSOCKSHUTDOWN_IEC pfsyssockshutdown;
	#define GET_syssockshutdown(fl)  s_pfCMGetAPI2( "syssockshutdown", (RTS_VOID_FCTPTR *)&pfsyssockshutdown, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xCB0E612E), 0x03050F00)
	#define CAL_syssockshutdown  pfsyssockshutdown
	#define CHK_syssockshutdown  (pfsyssockshutdown != NULL)
	#define EXP_syssockshutdown   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"syssockshutdown", (RTS_UINTPTR)syssockshutdown, 1, RTSITF_GET_SIGNATURE(0, 0xCB0E612E), 0x03050F00) 
#endif


#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/




typedef struct
{
	IBase_C *pBase;
} ISysSocket_Implementation_C;

#ifdef CPLUSPLUS
class ISysSocket_Implementation : public IBase
{
	public:
};
	#ifndef ITF_SysSocket_Implementation
		#define ITF_SysSocket_Implementation static ISysSocket_Implementation *pISysSocket_Implementation = NULL;
	#endif
	#define EXTITF_SysSocket_Implementation
#else	/*CPLUSPLUS*/
	typedef ISysSocket_Implementation_C		ISysSocket_Implementation;
	#ifndef ITF_SysSocket_Implementation
		#define ITF_SysSocket_Implementation
	#endif
	#define EXTITF_SysSocket_Implementation
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_SYSSOCKET_IMPLEMENTATIONITF_H_*/
