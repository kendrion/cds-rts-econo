 /**
 * <interfacename>CmpOPCUAStack</interfacename>
 * <description></description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */
 
/*
 * This interface publishes the functions of the OPC UA Foundation stack that are needed by the OPC UA Providers.
 */


	
	
#ifndef _CMPOPCUASTACKITF_H_
#define _CMPOPCUASTACKITF_H_

#include "CmpStd.h"

 

 



#include "CmpCryptoItf.h"

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>Enable tracing of OPC UA component. Select 0 to disable and 1 to enable tracing</description>
 */
#define CMPOPCUAKEY_INT_TRACE_ENABLE				"EnableTrace"
#ifndef CMPOPCUAVALUE_INT_TRACE_ENABLE_DEFAULT
	#define CMPOPCUAVALUE_INT_TRACE_ENABLE_DEFAULT	1
#endif

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>Set the trace level. Select out of the following values. Add them to select multiple values.
 * Trace Content:   0x1
 * Trace Debug:     0x2
 * Trace Info:      0x4
 * Trace System:    0x8
 * Trace Warning:   0x10
 * Trace Error:     0x20
 * Trace Datetime:  0x80
 * Trace Mutex:     0x100
 * Trace Semaphore: 0x200
 * Trace Memory:    0x400
 * Trace Seocket:   0x800
 * </description>
 */
#define CMPOPCUAKEY_INT_TRACE_LEVEL					"TraceLevel"
#ifndef CMPOPCUAVALUE_INT_TRACE_LEVEL_DEFAULT
	#define CMPOPCUAVALUE_INT_TRACE_LEVEL_DEFAULT	(OPCUA_TRACE_LEVEL_ERROR | OPCUA_TRACE_LEVEL_WARNING)
#endif

#define CMPOPCUASTACK_KEY_INT_MAX_ALLOC					"Stack.MaxAlloc"
#ifndef CMPOPCUASTACK_VALUE_INT_MAX_ALLOC
	#define CMPOPCUASTACK_VALUE_INT_MAX_ALLOC			0x10000		/* 1MB */
#endif

#define CMPOPCUASTACK_KEY_INT_MAX_STRINGLEN				"Stack.MaxStringLen"
#ifndef CMPOPCUASTACK_VALUE_INT_MAX_STRINGLEN
	#define CMPOPCUASTACK_VALUE_INT_MAX_STRINGLEN		((OpcUa_UInt32)OpcUa_Int32_Max)
#endif

#define CMPOPCUASTACK_KEY_INT_MAX_BYTESTRINGLEN			"Stack.MaxByteStringLen"
#ifndef CMPOPCUASTACK_VALUE_INT_MAX_BYTESTRINGLEN
	#define CMPOPCUASTACK_VALUE_INT_MAX_BYTESTRINGLEN	((OpcUa_UInt32)OpcUa_Int32_Max)
#endif

#define CMPOPCUASTACK_KEY_INT_MAX_ARRAYLEN				"Stack.MaxArrayLenth"
#ifndef CMPOPCUASTACK_VALUE_INT_MAX_ARRAYLEN
	#define CMPOPCUASTACK_VALUE_INT_MAX_ARRAYLEN		((OpcUa_UInt32)OpcUa_Int32_Max)
#endif

#define CMPOPCUASTACK_KEY_INT_MAX_MESSAGESIZE			"Stack.MaxMaxMessageSize"
#ifndef CMPOPCUASTACK_VALUE_INT_MAX_MESSAGESIZE
	#define CMPOPCUASTACK_VALUE_INT_MAX_MESSAGESIZE		0x100000		/* 1MB */
#endif

#define CMPOPCUASTACK_KEY_INT_MAX_RECURSIONDEPTH		"Stack.MaxRecursionDepth"
#ifndef CMPOPCUASTACK_VALUE_INT_MAX_RECURSIONDEPTH
	#define CMPOPCUASTACK_VALUE_INT_MAX_RECURSIONDEPTH	100
#endif



#define CMPOPCUASTACK_KEY_INT_LISTENER_MAX_CHUNKSIZE			"Listener.MaxChukSize"
#ifndef CMPOPCUASTACK_VALUE_INT_LISTENER_MAX_CHUNKSIZE
	#define CMPOPCUASTACK_VALUE_INT_LISTENER_MAX_CHUNKSIZE		0x10000		/* 65 KB */
#endif

#define CMPOPCUASTACK_KEY_INT_CONNECTION_MAX_CHUNKSIZE			"Connection.MaxChukSize"
#ifndef CMPOPCUASTACK_VALUE_INT_CONNECTION_MAX_CHUNKSIZE
	#define CMPOPCUASTACK_VALUE_INT_CONNECTION_MAX_CHUNKSIZE	0x10000		/* 65 KB */
#endif

#define CMPOPCUASTACK_KEY_INT_TCP_MAX_MESSAGESIZE				"Transport.MaxMessageLength"
#ifndef CMPOPCUASTACK_VALUE_INT_TCP_MAX_MESSAGESIZE
	#define CMPOPCUASTACK_VALUE_INT_TCP_MAX_MESSAGESIZE			0x100000		/* 1MB */
#endif

#define CMPOPCUASTACK_KEY_INT_TCP_MAX_CHUNKCOUNT				"Transport.MaxChukCount"
#ifndef CMPOPCUASTACK_VALUE_INT_TCP_MAX_CHUNKCOUNT
	#define CMPOPCUASTACK_VALUE_INT_TCP_MAX_CHUNKCOUNT			0x10		/* Allow up to 1MB sized messages */
#endif


/**
 * <category>Compiler switches</category>
 * <description>This switch enables or disables the implementation of the OPC UA security
 * policies inside the OPC UA stack. By default the implementation will be there if the
 * required interfaces are implemented. Other components can use the switch to determine if
 * the security policies of the UA Stack are available at compile time.</description>
 */
#if !(defined CMPCRYPTO_NOTIMPLEMENTED || defined CMPX509CERT_NOTIMPLEMENTED)
    #ifndef CMPOPCUASTACK_SUPPORT_SECURE_COMMUNICATION
        #define CMPOPCUASTACK_SUPPORT_SECURE_COMMUNICATION 1
    #endif
#endif

/**
 * <category>Compiler switches</category>
 * <description>This switch enables or disables availability of SHA1 based encryption profiles
 * as defined by the OPC UA specification (Basic128Rsa15, Basic256). These profiles use SHA1 as
 * hashing algorithm. Since 2005 (https://www.schneier.com/blog/archives/2005/02/sha1_broken.html) SHA1
 * is broken. In 2017 the first collision was generated (https://shattered.io/). As a result
 * SHA1 based profiles will be disabled by default.</description>
 */
#if CMPOPCUASTACK_SUPPORT_SECURE_COMMUNICATION
    #ifndef CMPOPCUASTACK_ALLOW_SHA1_BASED_SECURITY
        #define CMPOPCUASTACK_ALLOW_SHA1_BASED_SECURITY 0
    #endif
#endif

/**
 * <category>Static defines</category>
 * <description>Stack configuration: Maximum size of one single malloc/realloc operation.</description>
 */
#ifndef RTS_OPCUA_ALLOC_SIZE_MAX
	#define RTS_OPCUA_ALLOC_SIZE_MAX 0x1000000
#endif

/* OPC UA Stack header files */
#include "opcua.h"
#include "opcua_list.h"
#include "opcua_endpoint.h"
#include "opcua_timer.h"
#include "opcua_channel.h"

#define CAL_OpcUaStringCompare(xValue1, xValue2) CAL_OpcUaStringStrnCmp(xValue1, xValue2, OPCUA_STRING_LENDONTCARE, OpcUa_False)
#define CAL_OpcUaStringCopyTo(xSource, xDestination) CAL_OpcUaStringStrnCpy(xDestination, xSource, OPCUA_STRING_LENDONTCARE)

OpcUa_Void CDECL OpcUaByteStringInitialize(OpcUa_ByteString* value);
typedef OpcUa_Void (CDECL * PFOPCUABYTESTRINGINITIALIZE) (OpcUa_ByteString* value);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUABYTESTRINGINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaByteStringInitialize
	#define EXT_OpcUaByteStringInitialize
	#define GET_OpcUaByteStringInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaByteStringInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaByteStringInitialize  FALSE
	#define EXP_OpcUaByteStringInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaByteStringInitialize
	#define EXT_OpcUaByteStringInitialize
	#define GET_OpcUaByteStringInitialize(fl)  CAL_CMGETAPI( "OpcUaByteStringInitialize" ) 
	#define CAL_OpcUaByteStringInitialize  OpcUaByteStringInitialize
	#define CHK_OpcUaByteStringInitialize  TRUE
	#define EXP_OpcUaByteStringInitialize  CAL_CMEXPAPI( "OpcUaByteStringInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaByteStringInitialize
	#define EXT_OpcUaByteStringInitialize
	#define GET_OpcUaByteStringInitialize(fl)  CAL_CMGETAPI( "OpcUaByteStringInitialize" ) 
	#define CAL_OpcUaByteStringInitialize  OpcUaByteStringInitialize
	#define CHK_OpcUaByteStringInitialize  TRUE
	#define EXP_OpcUaByteStringInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaByteStringInitialize", (RTS_UINTPTR)OpcUaByteStringInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaByteStringInitialize
	#define EXT_CmpOPCUAStackOpcUaByteStringInitialize
	#define GET_CmpOPCUAStackOpcUaByteStringInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaByteStringInitialize pICmpOPCUAStack->IOpcUaByteStringInitialize
	#define CHK_CmpOPCUAStackOpcUaByteStringInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaByteStringInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaByteStringInitialize
	#define EXT_OpcUaByteStringInitialize
	#define GET_OpcUaByteStringInitialize(fl)  CAL_CMGETAPI( "OpcUaByteStringInitialize" ) 
	#define CAL_OpcUaByteStringInitialize pICmpOPCUAStack->IOpcUaByteStringInitialize
	#define CHK_OpcUaByteStringInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaByteStringInitialize  CAL_CMEXPAPI( "OpcUaByteStringInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaByteStringInitialize  PFOPCUABYTESTRINGINITIALIZE pfOpcUaByteStringInitialize;
	#define EXT_OpcUaByteStringInitialize  extern PFOPCUABYTESTRINGINITIALIZE pfOpcUaByteStringInitialize;
	#define GET_OpcUaByteStringInitialize(fl)  s_pfCMGetAPI2( "OpcUaByteStringInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaByteStringInitialize, (fl), 0, 0)
	#define CAL_OpcUaByteStringInitialize  pfOpcUaByteStringInitialize
	#define CHK_OpcUaByteStringInitialize  (pfOpcUaByteStringInitialize != NULL)
	#define EXP_OpcUaByteStringInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaByteStringInitialize", (RTS_UINTPTR)OpcUaByteStringInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaByteStringClear(OpcUa_ByteString* value);
typedef OpcUa_Void (CDECL * PFOPCUABYTESTRINGCLEAR) (OpcUa_ByteString* value);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUABYTESTRINGCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaByteStringClear
	#define EXT_OpcUaByteStringClear
	#define GET_OpcUaByteStringClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaByteStringClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaByteStringClear  FALSE
	#define EXP_OpcUaByteStringClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaByteStringClear
	#define EXT_OpcUaByteStringClear
	#define GET_OpcUaByteStringClear(fl)  CAL_CMGETAPI( "OpcUaByteStringClear" ) 
	#define CAL_OpcUaByteStringClear  OpcUaByteStringClear
	#define CHK_OpcUaByteStringClear  TRUE
	#define EXP_OpcUaByteStringClear  CAL_CMEXPAPI( "OpcUaByteStringClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaByteStringClear
	#define EXT_OpcUaByteStringClear
	#define GET_OpcUaByteStringClear(fl)  CAL_CMGETAPI( "OpcUaByteStringClear" ) 
	#define CAL_OpcUaByteStringClear  OpcUaByteStringClear
	#define CHK_OpcUaByteStringClear  TRUE
	#define EXP_OpcUaByteStringClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaByteStringClear", (RTS_UINTPTR)OpcUaByteStringClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaByteStringClear
	#define EXT_CmpOPCUAStackOpcUaByteStringClear
	#define GET_CmpOPCUAStackOpcUaByteStringClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaByteStringClear pICmpOPCUAStack->IOpcUaByteStringClear
	#define CHK_CmpOPCUAStackOpcUaByteStringClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaByteStringClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaByteStringClear
	#define EXT_OpcUaByteStringClear
	#define GET_OpcUaByteStringClear(fl)  CAL_CMGETAPI( "OpcUaByteStringClear" ) 
	#define CAL_OpcUaByteStringClear pICmpOPCUAStack->IOpcUaByteStringClear
	#define CHK_OpcUaByteStringClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaByteStringClear  CAL_CMEXPAPI( "OpcUaByteStringClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaByteStringClear  PFOPCUABYTESTRINGCLEAR pfOpcUaByteStringClear;
	#define EXT_OpcUaByteStringClear  extern PFOPCUABYTESTRINGCLEAR pfOpcUaByteStringClear;
	#define GET_OpcUaByteStringClear(fl)  s_pfCMGetAPI2( "OpcUaByteStringClear", (RTS_VOID_FCTPTR *)&pfOpcUaByteStringClear, (fl), 0, 0)
	#define CAL_OpcUaByteStringClear  pfOpcUaByteStringClear
	#define CHK_OpcUaByteStringClear  (pfOpcUaByteStringClear != NULL)
	#define EXP_OpcUaByteStringClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaByteStringClear", (RTS_UINTPTR)OpcUaByteStringClear, 0, 0) 
#endif



OpcUa_Int CDECL OpcUaByteStringCompare(const OpcUa_ByteString* value1, const OpcUa_ByteString* value2);
typedef OpcUa_Int (CDECL * PFOPCUABYTESTRINGCOMPARE) (const OpcUa_ByteString* value1, const OpcUa_ByteString* value2);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUABYTESTRINGCOMPARE_NOTIMPLEMENTED)
	#define USE_OpcUaByteStringCompare
	#define EXT_OpcUaByteStringCompare
	#define GET_OpcUaByteStringCompare(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaByteStringCompare(p0,p1)  (OpcUa_Int)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaByteStringCompare  FALSE
	#define EXP_OpcUaByteStringCompare  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaByteStringCompare
	#define EXT_OpcUaByteStringCompare
	#define GET_OpcUaByteStringCompare(fl)  CAL_CMGETAPI( "OpcUaByteStringCompare" ) 
	#define CAL_OpcUaByteStringCompare  OpcUaByteStringCompare
	#define CHK_OpcUaByteStringCompare  TRUE
	#define EXP_OpcUaByteStringCompare  CAL_CMEXPAPI( "OpcUaByteStringCompare" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaByteStringCompare
	#define EXT_OpcUaByteStringCompare
	#define GET_OpcUaByteStringCompare(fl)  CAL_CMGETAPI( "OpcUaByteStringCompare" ) 
	#define CAL_OpcUaByteStringCompare  OpcUaByteStringCompare
	#define CHK_OpcUaByteStringCompare  TRUE
	#define EXP_OpcUaByteStringCompare  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaByteStringCompare", (RTS_UINTPTR)OpcUaByteStringCompare, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaByteStringCompare
	#define EXT_CmpOPCUAStackOpcUaByteStringCompare
	#define GET_CmpOPCUAStackOpcUaByteStringCompare  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaByteStringCompare pICmpOPCUAStack->IOpcUaByteStringCompare
	#define CHK_CmpOPCUAStackOpcUaByteStringCompare (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaByteStringCompare  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaByteStringCompare
	#define EXT_OpcUaByteStringCompare
	#define GET_OpcUaByteStringCompare(fl)  CAL_CMGETAPI( "OpcUaByteStringCompare" ) 
	#define CAL_OpcUaByteStringCompare pICmpOPCUAStack->IOpcUaByteStringCompare
	#define CHK_OpcUaByteStringCompare (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaByteStringCompare  CAL_CMEXPAPI( "OpcUaByteStringCompare" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaByteStringCompare  PFOPCUABYTESTRINGCOMPARE pfOpcUaByteStringCompare;
	#define EXT_OpcUaByteStringCompare  extern PFOPCUABYTESTRINGCOMPARE pfOpcUaByteStringCompare;
	#define GET_OpcUaByteStringCompare(fl)  s_pfCMGetAPI2( "OpcUaByteStringCompare", (RTS_VOID_FCTPTR *)&pfOpcUaByteStringCompare, (fl), 0, 0)
	#define CAL_OpcUaByteStringCompare  pfOpcUaByteStringCompare
	#define CHK_OpcUaByteStringCompare  (pfOpcUaByteStringCompare != NULL)
	#define EXP_OpcUaByteStringCompare  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaByteStringCompare", (RTS_UINTPTR)OpcUaByteStringCompare, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaByteStringCopyTo(const OpcUa_ByteString* source, OpcUa_ByteString* destination);
typedef OpcUa_StatusCode (CDECL * PFOPCUABYTESTRINGCOPYTO) (const OpcUa_ByteString* source, OpcUa_ByteString* destination);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUABYTESTRINGCOPYTO_NOTIMPLEMENTED)
	#define USE_OpcUaByteStringCopyTo
	#define EXT_OpcUaByteStringCopyTo
	#define GET_OpcUaByteStringCopyTo(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaByteStringCopyTo(p0,p1)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaByteStringCopyTo  FALSE
	#define EXP_OpcUaByteStringCopyTo  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaByteStringCopyTo
	#define EXT_OpcUaByteStringCopyTo
	#define GET_OpcUaByteStringCopyTo(fl)  CAL_CMGETAPI( "OpcUaByteStringCopyTo" ) 
	#define CAL_OpcUaByteStringCopyTo  OpcUaByteStringCopyTo
	#define CHK_OpcUaByteStringCopyTo  TRUE
	#define EXP_OpcUaByteStringCopyTo  CAL_CMEXPAPI( "OpcUaByteStringCopyTo" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaByteStringCopyTo
	#define EXT_OpcUaByteStringCopyTo
	#define GET_OpcUaByteStringCopyTo(fl)  CAL_CMGETAPI( "OpcUaByteStringCopyTo" ) 
	#define CAL_OpcUaByteStringCopyTo  OpcUaByteStringCopyTo
	#define CHK_OpcUaByteStringCopyTo  TRUE
	#define EXP_OpcUaByteStringCopyTo  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaByteStringCopyTo", (RTS_UINTPTR)OpcUaByteStringCopyTo, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaByteStringCopyTo
	#define EXT_CmpOPCUAStackOpcUaByteStringCopyTo
	#define GET_CmpOPCUAStackOpcUaByteStringCopyTo  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaByteStringCopyTo pICmpOPCUAStack->IOpcUaByteStringCopyTo
	#define CHK_CmpOPCUAStackOpcUaByteStringCopyTo (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaByteStringCopyTo  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaByteStringCopyTo
	#define EXT_OpcUaByteStringCopyTo
	#define GET_OpcUaByteStringCopyTo(fl)  CAL_CMGETAPI( "OpcUaByteStringCopyTo" ) 
	#define CAL_OpcUaByteStringCopyTo pICmpOPCUAStack->IOpcUaByteStringCopyTo
	#define CHK_OpcUaByteStringCopyTo (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaByteStringCopyTo  CAL_CMEXPAPI( "OpcUaByteStringCopyTo" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaByteStringCopyTo  PFOPCUABYTESTRINGCOPYTO pfOpcUaByteStringCopyTo;
	#define EXT_OpcUaByteStringCopyTo  extern PFOPCUABYTESTRINGCOPYTO pfOpcUaByteStringCopyTo;
	#define GET_OpcUaByteStringCopyTo(fl)  s_pfCMGetAPI2( "OpcUaByteStringCopyTo", (RTS_VOID_FCTPTR *)&pfOpcUaByteStringCopyTo, (fl), 0, 0)
	#define CAL_OpcUaByteStringCopyTo  pfOpcUaByteStringCopyTo
	#define CHK_OpcUaByteStringCopyTo  (pfOpcUaByteStringCopyTo != NULL)
	#define EXP_OpcUaByteStringCopyTo  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaByteStringCopyTo", (RTS_UINTPTR)OpcUaByteStringCopyTo, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaByteStringConcatenate(const OpcUa_ByteString* source, OpcUa_ByteString* destination, OpcUa_Int len);
typedef OpcUa_StatusCode (CDECL * PFOPCUABYTESTRINGCONCATENATE) (const OpcUa_ByteString* source, OpcUa_ByteString* destination, OpcUa_Int len);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUABYTESTRINGCONCATENATE_NOTIMPLEMENTED)
	#define USE_OpcUaByteStringConcatenate
	#define EXT_OpcUaByteStringConcatenate
	#define GET_OpcUaByteStringConcatenate(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaByteStringConcatenate(p0,p1,p2)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaByteStringConcatenate  FALSE
	#define EXP_OpcUaByteStringConcatenate  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaByteStringConcatenate
	#define EXT_OpcUaByteStringConcatenate
	#define GET_OpcUaByteStringConcatenate(fl)  CAL_CMGETAPI( "OpcUaByteStringConcatenate" ) 
	#define CAL_OpcUaByteStringConcatenate  OpcUaByteStringConcatenate
	#define CHK_OpcUaByteStringConcatenate  TRUE
	#define EXP_OpcUaByteStringConcatenate  CAL_CMEXPAPI( "OpcUaByteStringConcatenate" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaByteStringConcatenate
	#define EXT_OpcUaByteStringConcatenate
	#define GET_OpcUaByteStringConcatenate(fl)  CAL_CMGETAPI( "OpcUaByteStringConcatenate" ) 
	#define CAL_OpcUaByteStringConcatenate  OpcUaByteStringConcatenate
	#define CHK_OpcUaByteStringConcatenate  TRUE
	#define EXP_OpcUaByteStringConcatenate  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaByteStringConcatenate", (RTS_UINTPTR)OpcUaByteStringConcatenate, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaByteStringConcatenate
	#define EXT_CmpOPCUAStackOpcUaByteStringConcatenate
	#define GET_CmpOPCUAStackOpcUaByteStringConcatenate  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaByteStringConcatenate pICmpOPCUAStack->IOpcUaByteStringConcatenate
	#define CHK_CmpOPCUAStackOpcUaByteStringConcatenate (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaByteStringConcatenate  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaByteStringConcatenate
	#define EXT_OpcUaByteStringConcatenate
	#define GET_OpcUaByteStringConcatenate(fl)  CAL_CMGETAPI( "OpcUaByteStringConcatenate" ) 
	#define CAL_OpcUaByteStringConcatenate pICmpOPCUAStack->IOpcUaByteStringConcatenate
	#define CHK_OpcUaByteStringConcatenate (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaByteStringConcatenate  CAL_CMEXPAPI( "OpcUaByteStringConcatenate" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaByteStringConcatenate  PFOPCUABYTESTRINGCONCATENATE pfOpcUaByteStringConcatenate;
	#define EXT_OpcUaByteStringConcatenate  extern PFOPCUABYTESTRINGCONCATENATE pfOpcUaByteStringConcatenate;
	#define GET_OpcUaByteStringConcatenate(fl)  s_pfCMGetAPI2( "OpcUaByteStringConcatenate", (RTS_VOID_FCTPTR *)&pfOpcUaByteStringConcatenate, (fl), 0, 0)
	#define CAL_OpcUaByteStringConcatenate  pfOpcUaByteStringConcatenate
	#define CHK_OpcUaByteStringConcatenate  (pfOpcUaByteStringConcatenate != NULL)
	#define EXP_OpcUaByteStringConcatenate  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaByteStringConcatenate", (RTS_UINTPTR)OpcUaByteStringConcatenate, 0, 0) 
#endif




OpcUa_DateTime CDECL OpcUaDateTimeUtcNow(void);
typedef OpcUa_DateTime (CDECL * PFOPCUADATETIMEUTCNOW) (void);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUADATETIMEUTCNOW_NOTIMPLEMENTED)
	#define USE_OpcUaDateTimeUtcNow
	#define EXT_OpcUaDateTimeUtcNow
	#define GET_OpcUaDateTimeUtcNow(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaDateTimeUtcNow()  (OpcUa_DateTime)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaDateTimeUtcNow  FALSE
	#define EXP_OpcUaDateTimeUtcNow  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaDateTimeUtcNow
	#define EXT_OpcUaDateTimeUtcNow
	#define GET_OpcUaDateTimeUtcNow(fl)  CAL_CMGETAPI( "OpcUaDateTimeUtcNow" ) 
	#define CAL_OpcUaDateTimeUtcNow  OpcUaDateTimeUtcNow
	#define CHK_OpcUaDateTimeUtcNow  TRUE
	#define EXP_OpcUaDateTimeUtcNow  CAL_CMEXPAPI( "OpcUaDateTimeUtcNow" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaDateTimeUtcNow
	#define EXT_OpcUaDateTimeUtcNow
	#define GET_OpcUaDateTimeUtcNow(fl)  CAL_CMGETAPI( "OpcUaDateTimeUtcNow" ) 
	#define CAL_OpcUaDateTimeUtcNow  OpcUaDateTimeUtcNow
	#define CHK_OpcUaDateTimeUtcNow  TRUE
	#define EXP_OpcUaDateTimeUtcNow  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDateTimeUtcNow", (RTS_UINTPTR)OpcUaDateTimeUtcNow, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaDateTimeUtcNow
	#define EXT_CmpOPCUAStackOpcUaDateTimeUtcNow
	#define GET_CmpOPCUAStackOpcUaDateTimeUtcNow  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaDateTimeUtcNow pICmpOPCUAStack->IOpcUaDateTimeUtcNow
	#define CHK_CmpOPCUAStackOpcUaDateTimeUtcNow (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaDateTimeUtcNow  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaDateTimeUtcNow
	#define EXT_OpcUaDateTimeUtcNow
	#define GET_OpcUaDateTimeUtcNow(fl)  CAL_CMGETAPI( "OpcUaDateTimeUtcNow" ) 
	#define CAL_OpcUaDateTimeUtcNow pICmpOPCUAStack->IOpcUaDateTimeUtcNow
	#define CHK_OpcUaDateTimeUtcNow (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaDateTimeUtcNow  CAL_CMEXPAPI( "OpcUaDateTimeUtcNow" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaDateTimeUtcNow  PFOPCUADATETIMEUTCNOW pfOpcUaDateTimeUtcNow;
	#define EXT_OpcUaDateTimeUtcNow  extern PFOPCUADATETIMEUTCNOW pfOpcUaDateTimeUtcNow;
	#define GET_OpcUaDateTimeUtcNow(fl)  s_pfCMGetAPI2( "OpcUaDateTimeUtcNow", (RTS_VOID_FCTPTR *)&pfOpcUaDateTimeUtcNow, (fl), 0, 0)
	#define CAL_OpcUaDateTimeUtcNow  pfOpcUaDateTimeUtcNow
	#define CHK_OpcUaDateTimeUtcNow  (pfOpcUaDateTimeUtcNow != NULL)
	#define EXP_OpcUaDateTimeUtcNow  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDateTimeUtcNow", (RTS_UINTPTR)OpcUaDateTimeUtcNow, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaEncodeableObjectCreate(OpcUa_EncodeableType* pType, OpcUa_Void** ppEncodeable);
typedef OpcUa_StatusCode (CDECL * PFOPCUAENCODEABLEOBJECTCREATE) (OpcUa_EncodeableType* pType, OpcUa_Void** ppEncodeable);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAENCODEABLEOBJECTCREATE_NOTIMPLEMENTED)
	#define USE_OpcUaEncodeableObjectCreate
	#define EXT_OpcUaEncodeableObjectCreate
	#define GET_OpcUaEncodeableObjectCreate(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaEncodeableObjectCreate(p0,p1)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaEncodeableObjectCreate  FALSE
	#define EXP_OpcUaEncodeableObjectCreate  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaEncodeableObjectCreate
	#define EXT_OpcUaEncodeableObjectCreate
	#define GET_OpcUaEncodeableObjectCreate(fl)  CAL_CMGETAPI( "OpcUaEncodeableObjectCreate" ) 
	#define CAL_OpcUaEncodeableObjectCreate  OpcUaEncodeableObjectCreate
	#define CHK_OpcUaEncodeableObjectCreate  TRUE
	#define EXP_OpcUaEncodeableObjectCreate  CAL_CMEXPAPI( "OpcUaEncodeableObjectCreate" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaEncodeableObjectCreate
	#define EXT_OpcUaEncodeableObjectCreate
	#define GET_OpcUaEncodeableObjectCreate(fl)  CAL_CMGETAPI( "OpcUaEncodeableObjectCreate" ) 
	#define CAL_OpcUaEncodeableObjectCreate  OpcUaEncodeableObjectCreate
	#define CHK_OpcUaEncodeableObjectCreate  TRUE
	#define EXP_OpcUaEncodeableObjectCreate  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEncodeableObjectCreate", (RTS_UINTPTR)OpcUaEncodeableObjectCreate, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaEncodeableObjectCreate
	#define EXT_CmpOPCUAStackOpcUaEncodeableObjectCreate
	#define GET_CmpOPCUAStackOpcUaEncodeableObjectCreate  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaEncodeableObjectCreate pICmpOPCUAStack->IOpcUaEncodeableObjectCreate
	#define CHK_CmpOPCUAStackOpcUaEncodeableObjectCreate (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaEncodeableObjectCreate  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaEncodeableObjectCreate
	#define EXT_OpcUaEncodeableObjectCreate
	#define GET_OpcUaEncodeableObjectCreate(fl)  CAL_CMGETAPI( "OpcUaEncodeableObjectCreate" ) 
	#define CAL_OpcUaEncodeableObjectCreate pICmpOPCUAStack->IOpcUaEncodeableObjectCreate
	#define CHK_OpcUaEncodeableObjectCreate (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaEncodeableObjectCreate  CAL_CMEXPAPI( "OpcUaEncodeableObjectCreate" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaEncodeableObjectCreate  PFOPCUAENCODEABLEOBJECTCREATE pfOpcUaEncodeableObjectCreate;
	#define EXT_OpcUaEncodeableObjectCreate  extern PFOPCUAENCODEABLEOBJECTCREATE pfOpcUaEncodeableObjectCreate;
	#define GET_OpcUaEncodeableObjectCreate(fl)  s_pfCMGetAPI2( "OpcUaEncodeableObjectCreate", (RTS_VOID_FCTPTR *)&pfOpcUaEncodeableObjectCreate, (fl), 0, 0)
	#define CAL_OpcUaEncodeableObjectCreate  pfOpcUaEncodeableObjectCreate
	#define CHK_OpcUaEncodeableObjectCreate  (pfOpcUaEncodeableObjectCreate != NULL)
	#define EXP_OpcUaEncodeableObjectCreate  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEncodeableObjectCreate", (RTS_UINTPTR)OpcUaEncodeableObjectCreate, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaEncodeableObjectDelete(OpcUa_EncodeableType* pType, OpcUa_Void** ppEncodeable);
typedef OpcUa_Void (CDECL * PFOPCUAENCODEABLEOBJECTDELETE) (OpcUa_EncodeableType* pType, OpcUa_Void** ppEncodeable);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAENCODEABLEOBJECTDELETE_NOTIMPLEMENTED)
	#define USE_OpcUaEncodeableObjectDelete
	#define EXT_OpcUaEncodeableObjectDelete
	#define GET_OpcUaEncodeableObjectDelete(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaEncodeableObjectDelete(p0,p1)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaEncodeableObjectDelete  FALSE
	#define EXP_OpcUaEncodeableObjectDelete  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaEncodeableObjectDelete
	#define EXT_OpcUaEncodeableObjectDelete
	#define GET_OpcUaEncodeableObjectDelete(fl)  CAL_CMGETAPI( "OpcUaEncodeableObjectDelete" ) 
	#define CAL_OpcUaEncodeableObjectDelete  OpcUaEncodeableObjectDelete
	#define CHK_OpcUaEncodeableObjectDelete  TRUE
	#define EXP_OpcUaEncodeableObjectDelete  CAL_CMEXPAPI( "OpcUaEncodeableObjectDelete" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaEncodeableObjectDelete
	#define EXT_OpcUaEncodeableObjectDelete
	#define GET_OpcUaEncodeableObjectDelete(fl)  CAL_CMGETAPI( "OpcUaEncodeableObjectDelete" ) 
	#define CAL_OpcUaEncodeableObjectDelete  OpcUaEncodeableObjectDelete
	#define CHK_OpcUaEncodeableObjectDelete  TRUE
	#define EXP_OpcUaEncodeableObjectDelete  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEncodeableObjectDelete", (RTS_UINTPTR)OpcUaEncodeableObjectDelete, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaEncodeableObjectDelete
	#define EXT_CmpOPCUAStackOpcUaEncodeableObjectDelete
	#define GET_CmpOPCUAStackOpcUaEncodeableObjectDelete  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaEncodeableObjectDelete pICmpOPCUAStack->IOpcUaEncodeableObjectDelete
	#define CHK_CmpOPCUAStackOpcUaEncodeableObjectDelete (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaEncodeableObjectDelete  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaEncodeableObjectDelete
	#define EXT_OpcUaEncodeableObjectDelete
	#define GET_OpcUaEncodeableObjectDelete(fl)  CAL_CMGETAPI( "OpcUaEncodeableObjectDelete" ) 
	#define CAL_OpcUaEncodeableObjectDelete pICmpOPCUAStack->IOpcUaEncodeableObjectDelete
	#define CHK_OpcUaEncodeableObjectDelete (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaEncodeableObjectDelete  CAL_CMEXPAPI( "OpcUaEncodeableObjectDelete" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaEncodeableObjectDelete  PFOPCUAENCODEABLEOBJECTDELETE pfOpcUaEncodeableObjectDelete;
	#define EXT_OpcUaEncodeableObjectDelete  extern PFOPCUAENCODEABLEOBJECTDELETE pfOpcUaEncodeableObjectDelete;
	#define GET_OpcUaEncodeableObjectDelete(fl)  s_pfCMGetAPI2( "OpcUaEncodeableObjectDelete", (RTS_VOID_FCTPTR *)&pfOpcUaEncodeableObjectDelete, (fl), 0, 0)
	#define CAL_OpcUaEncodeableObjectDelete  pfOpcUaEncodeableObjectDelete
	#define CHK_OpcUaEncodeableObjectDelete  (pfOpcUaEncodeableObjectDelete != NULL)
	#define EXP_OpcUaEncodeableObjectDelete  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEncodeableObjectDelete", (RTS_UINTPTR)OpcUaEncodeableObjectDelete, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaEncodeableObjectCreateExtension(OpcUa_EncodeableType* pType, OpcUa_ExtensionObject* pExtension, OpcUa_Void** ppEncodeableObject);
typedef OpcUa_StatusCode (CDECL * PFOPCUAENCODEABLEOBJECTCREATEEXTENSION) (OpcUa_EncodeableType* pType, OpcUa_ExtensionObject* pExtension, OpcUa_Void** ppEncodeableObject);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAENCODEABLEOBJECTCREATEEXTENSION_NOTIMPLEMENTED)
	#define USE_OpcUaEncodeableObjectCreateExtension
	#define EXT_OpcUaEncodeableObjectCreateExtension
	#define GET_OpcUaEncodeableObjectCreateExtension(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaEncodeableObjectCreateExtension(p0,p1,p2)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaEncodeableObjectCreateExtension  FALSE
	#define EXP_OpcUaEncodeableObjectCreateExtension  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaEncodeableObjectCreateExtension
	#define EXT_OpcUaEncodeableObjectCreateExtension
	#define GET_OpcUaEncodeableObjectCreateExtension(fl)  CAL_CMGETAPI( "OpcUaEncodeableObjectCreateExtension" ) 
	#define CAL_OpcUaEncodeableObjectCreateExtension  OpcUaEncodeableObjectCreateExtension
	#define CHK_OpcUaEncodeableObjectCreateExtension  TRUE
	#define EXP_OpcUaEncodeableObjectCreateExtension  CAL_CMEXPAPI( "OpcUaEncodeableObjectCreateExtension" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaEncodeableObjectCreateExtension
	#define EXT_OpcUaEncodeableObjectCreateExtension
	#define GET_OpcUaEncodeableObjectCreateExtension(fl)  CAL_CMGETAPI( "OpcUaEncodeableObjectCreateExtension" ) 
	#define CAL_OpcUaEncodeableObjectCreateExtension  OpcUaEncodeableObjectCreateExtension
	#define CHK_OpcUaEncodeableObjectCreateExtension  TRUE
	#define EXP_OpcUaEncodeableObjectCreateExtension  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEncodeableObjectCreateExtension", (RTS_UINTPTR)OpcUaEncodeableObjectCreateExtension, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaEncodeableObjectCreateExtension
	#define EXT_CmpOPCUAStackOpcUaEncodeableObjectCreateExtension
	#define GET_CmpOPCUAStackOpcUaEncodeableObjectCreateExtension  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaEncodeableObjectCreateExtension pICmpOPCUAStack->IOpcUaEncodeableObjectCreateExtension
	#define CHK_CmpOPCUAStackOpcUaEncodeableObjectCreateExtension (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaEncodeableObjectCreateExtension  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaEncodeableObjectCreateExtension
	#define EXT_OpcUaEncodeableObjectCreateExtension
	#define GET_OpcUaEncodeableObjectCreateExtension(fl)  CAL_CMGETAPI( "OpcUaEncodeableObjectCreateExtension" ) 
	#define CAL_OpcUaEncodeableObjectCreateExtension pICmpOPCUAStack->IOpcUaEncodeableObjectCreateExtension
	#define CHK_OpcUaEncodeableObjectCreateExtension (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaEncodeableObjectCreateExtension  CAL_CMEXPAPI( "OpcUaEncodeableObjectCreateExtension" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaEncodeableObjectCreateExtension  PFOPCUAENCODEABLEOBJECTCREATEEXTENSION pfOpcUaEncodeableObjectCreateExtension;
	#define EXT_OpcUaEncodeableObjectCreateExtension  extern PFOPCUAENCODEABLEOBJECTCREATEEXTENSION pfOpcUaEncodeableObjectCreateExtension;
	#define GET_OpcUaEncodeableObjectCreateExtension(fl)  s_pfCMGetAPI2( "OpcUaEncodeableObjectCreateExtension", (RTS_VOID_FCTPTR *)&pfOpcUaEncodeableObjectCreateExtension, (fl), 0, 0)
	#define CAL_OpcUaEncodeableObjectCreateExtension  pfOpcUaEncodeableObjectCreateExtension
	#define CHK_OpcUaEncodeableObjectCreateExtension  (pfOpcUaEncodeableObjectCreateExtension != NULL)
	#define EXP_OpcUaEncodeableObjectCreateExtension  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEncodeableObjectCreateExtension", (RTS_UINTPTR)OpcUaEncodeableObjectCreateExtension, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaLocalizedTextInitialize(OpcUa_LocalizedText* pValue);
typedef OpcUa_Void (CDECL * PFOPCUALOCALIZEDTEXTINITIALIZE) (OpcUa_LocalizedText* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUALOCALIZEDTEXTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaLocalizedTextInitialize
	#define EXT_OpcUaLocalizedTextInitialize
	#define GET_OpcUaLocalizedTextInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaLocalizedTextInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaLocalizedTextInitialize  FALSE
	#define EXP_OpcUaLocalizedTextInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaLocalizedTextInitialize
	#define EXT_OpcUaLocalizedTextInitialize
	#define GET_OpcUaLocalizedTextInitialize(fl)  CAL_CMGETAPI( "OpcUaLocalizedTextInitialize" ) 
	#define CAL_OpcUaLocalizedTextInitialize  OpcUaLocalizedTextInitialize
	#define CHK_OpcUaLocalizedTextInitialize  TRUE
	#define EXP_OpcUaLocalizedTextInitialize  CAL_CMEXPAPI( "OpcUaLocalizedTextInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaLocalizedTextInitialize
	#define EXT_OpcUaLocalizedTextInitialize
	#define GET_OpcUaLocalizedTextInitialize(fl)  CAL_CMGETAPI( "OpcUaLocalizedTextInitialize" ) 
	#define CAL_OpcUaLocalizedTextInitialize  OpcUaLocalizedTextInitialize
	#define CHK_OpcUaLocalizedTextInitialize  TRUE
	#define EXP_OpcUaLocalizedTextInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaLocalizedTextInitialize", (RTS_UINTPTR)OpcUaLocalizedTextInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaLocalizedTextInitialize
	#define EXT_CmpOPCUAStackOpcUaLocalizedTextInitialize
	#define GET_CmpOPCUAStackOpcUaLocalizedTextInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaLocalizedTextInitialize pICmpOPCUAStack->IOpcUaLocalizedTextInitialize
	#define CHK_CmpOPCUAStackOpcUaLocalizedTextInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaLocalizedTextInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaLocalizedTextInitialize
	#define EXT_OpcUaLocalizedTextInitialize
	#define GET_OpcUaLocalizedTextInitialize(fl)  CAL_CMGETAPI( "OpcUaLocalizedTextInitialize" ) 
	#define CAL_OpcUaLocalizedTextInitialize pICmpOPCUAStack->IOpcUaLocalizedTextInitialize
	#define CHK_OpcUaLocalizedTextInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaLocalizedTextInitialize  CAL_CMEXPAPI( "OpcUaLocalizedTextInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaLocalizedTextInitialize  PFOPCUALOCALIZEDTEXTINITIALIZE pfOpcUaLocalizedTextInitialize;
	#define EXT_OpcUaLocalizedTextInitialize  extern PFOPCUALOCALIZEDTEXTINITIALIZE pfOpcUaLocalizedTextInitialize;
	#define GET_OpcUaLocalizedTextInitialize(fl)  s_pfCMGetAPI2( "OpcUaLocalizedTextInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaLocalizedTextInitialize, (fl), 0, 0)
	#define CAL_OpcUaLocalizedTextInitialize  pfOpcUaLocalizedTextInitialize
	#define CHK_OpcUaLocalizedTextInitialize  (pfOpcUaLocalizedTextInitialize != NULL)
	#define EXP_OpcUaLocalizedTextInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaLocalizedTextInitialize", (RTS_UINTPTR)OpcUaLocalizedTextInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaLocalizedTextClear(OpcUa_LocalizedText* pValue);
typedef OpcUa_Void (CDECL * PFOPCUALOCALIZEDTEXTCLEAR) (OpcUa_LocalizedText* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUALOCALIZEDTEXTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaLocalizedTextClear
	#define EXT_OpcUaLocalizedTextClear
	#define GET_OpcUaLocalizedTextClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaLocalizedTextClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaLocalizedTextClear  FALSE
	#define EXP_OpcUaLocalizedTextClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaLocalizedTextClear
	#define EXT_OpcUaLocalizedTextClear
	#define GET_OpcUaLocalizedTextClear(fl)  CAL_CMGETAPI( "OpcUaLocalizedTextClear" ) 
	#define CAL_OpcUaLocalizedTextClear  OpcUaLocalizedTextClear
	#define CHK_OpcUaLocalizedTextClear  TRUE
	#define EXP_OpcUaLocalizedTextClear  CAL_CMEXPAPI( "OpcUaLocalizedTextClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaLocalizedTextClear
	#define EXT_OpcUaLocalizedTextClear
	#define GET_OpcUaLocalizedTextClear(fl)  CAL_CMGETAPI( "OpcUaLocalizedTextClear" ) 
	#define CAL_OpcUaLocalizedTextClear  OpcUaLocalizedTextClear
	#define CHK_OpcUaLocalizedTextClear  TRUE
	#define EXP_OpcUaLocalizedTextClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaLocalizedTextClear", (RTS_UINTPTR)OpcUaLocalizedTextClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaLocalizedTextClear
	#define EXT_CmpOPCUAStackOpcUaLocalizedTextClear
	#define GET_CmpOPCUAStackOpcUaLocalizedTextClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaLocalizedTextClear pICmpOPCUAStack->IOpcUaLocalizedTextClear
	#define CHK_CmpOPCUAStackOpcUaLocalizedTextClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaLocalizedTextClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaLocalizedTextClear
	#define EXT_OpcUaLocalizedTextClear
	#define GET_OpcUaLocalizedTextClear(fl)  CAL_CMGETAPI( "OpcUaLocalizedTextClear" ) 
	#define CAL_OpcUaLocalizedTextClear pICmpOPCUAStack->IOpcUaLocalizedTextClear
	#define CHK_OpcUaLocalizedTextClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaLocalizedTextClear  CAL_CMEXPAPI( "OpcUaLocalizedTextClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaLocalizedTextClear  PFOPCUALOCALIZEDTEXTCLEAR pfOpcUaLocalizedTextClear;
	#define EXT_OpcUaLocalizedTextClear  extern PFOPCUALOCALIZEDTEXTCLEAR pfOpcUaLocalizedTextClear;
	#define GET_OpcUaLocalizedTextClear(fl)  s_pfCMGetAPI2( "OpcUaLocalizedTextClear", (RTS_VOID_FCTPTR *)&pfOpcUaLocalizedTextClear, (fl), 0, 0)
	#define CAL_OpcUaLocalizedTextClear  pfOpcUaLocalizedTextClear
	#define CHK_OpcUaLocalizedTextClear  (pfOpcUaLocalizedTextClear != NULL)
	#define EXP_OpcUaLocalizedTextClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaLocalizedTextClear", (RTS_UINTPTR)OpcUaLocalizedTextClear, 0, 0) 
#endif



OpcUa_Int CDECL OpcUaLocalizedTextCompare(const OpcUa_LocalizedText* pValue1, const OpcUa_LocalizedText* pValue2);
typedef OpcUa_Int (CDECL * PFOPCUALOCALIZEDTEXTCOMPARE) (const OpcUa_LocalizedText* pValue1, const OpcUa_LocalizedText* pValue2);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUALOCALIZEDTEXTCOMPARE_NOTIMPLEMENTED)
	#define USE_OpcUaLocalizedTextCompare
	#define EXT_OpcUaLocalizedTextCompare
	#define GET_OpcUaLocalizedTextCompare(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaLocalizedTextCompare(p0,p1)  (OpcUa_Int)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaLocalizedTextCompare  FALSE
	#define EXP_OpcUaLocalizedTextCompare  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaLocalizedTextCompare
	#define EXT_OpcUaLocalizedTextCompare
	#define GET_OpcUaLocalizedTextCompare(fl)  CAL_CMGETAPI( "OpcUaLocalizedTextCompare" ) 
	#define CAL_OpcUaLocalizedTextCompare  OpcUaLocalizedTextCompare
	#define CHK_OpcUaLocalizedTextCompare  TRUE
	#define EXP_OpcUaLocalizedTextCompare  CAL_CMEXPAPI( "OpcUaLocalizedTextCompare" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaLocalizedTextCompare
	#define EXT_OpcUaLocalizedTextCompare
	#define GET_OpcUaLocalizedTextCompare(fl)  CAL_CMGETAPI( "OpcUaLocalizedTextCompare" ) 
	#define CAL_OpcUaLocalizedTextCompare  OpcUaLocalizedTextCompare
	#define CHK_OpcUaLocalizedTextCompare  TRUE
	#define EXP_OpcUaLocalizedTextCompare  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaLocalizedTextCompare", (RTS_UINTPTR)OpcUaLocalizedTextCompare, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaLocalizedTextCompare
	#define EXT_CmpOPCUAStackOpcUaLocalizedTextCompare
	#define GET_CmpOPCUAStackOpcUaLocalizedTextCompare  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaLocalizedTextCompare pICmpOPCUAStack->IOpcUaLocalizedTextCompare
	#define CHK_CmpOPCUAStackOpcUaLocalizedTextCompare (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaLocalizedTextCompare  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaLocalizedTextCompare
	#define EXT_OpcUaLocalizedTextCompare
	#define GET_OpcUaLocalizedTextCompare(fl)  CAL_CMGETAPI( "OpcUaLocalizedTextCompare" ) 
	#define CAL_OpcUaLocalizedTextCompare pICmpOPCUAStack->IOpcUaLocalizedTextCompare
	#define CHK_OpcUaLocalizedTextCompare (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaLocalizedTextCompare  CAL_CMEXPAPI( "OpcUaLocalizedTextCompare" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaLocalizedTextCompare  PFOPCUALOCALIZEDTEXTCOMPARE pfOpcUaLocalizedTextCompare;
	#define EXT_OpcUaLocalizedTextCompare  extern PFOPCUALOCALIZEDTEXTCOMPARE pfOpcUaLocalizedTextCompare;
	#define GET_OpcUaLocalizedTextCompare(fl)  s_pfCMGetAPI2( "OpcUaLocalizedTextCompare", (RTS_VOID_FCTPTR *)&pfOpcUaLocalizedTextCompare, (fl), 0, 0)
	#define CAL_OpcUaLocalizedTextCompare  pfOpcUaLocalizedTextCompare
	#define CHK_OpcUaLocalizedTextCompare  (pfOpcUaLocalizedTextCompare != NULL)
	#define EXP_OpcUaLocalizedTextCompare  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaLocalizedTextCompare", (RTS_UINTPTR)OpcUaLocalizedTextCompare, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaLocalizedTextCopyTo(const OpcUa_LocalizedText* pSource, OpcUa_LocalizedText* pDestination);
typedef OpcUa_StatusCode (CDECL * PFOPCUALOCALIZEDTEXTCOPYTO) (const OpcUa_LocalizedText* pSource, OpcUa_LocalizedText* pDestination);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUALOCALIZEDTEXTCOPYTO_NOTIMPLEMENTED)
	#define USE_OpcUaLocalizedTextCopyTo
	#define EXT_OpcUaLocalizedTextCopyTo
	#define GET_OpcUaLocalizedTextCopyTo(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaLocalizedTextCopyTo(p0,p1)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaLocalizedTextCopyTo  FALSE
	#define EXP_OpcUaLocalizedTextCopyTo  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaLocalizedTextCopyTo
	#define EXT_OpcUaLocalizedTextCopyTo
	#define GET_OpcUaLocalizedTextCopyTo(fl)  CAL_CMGETAPI( "OpcUaLocalizedTextCopyTo" ) 
	#define CAL_OpcUaLocalizedTextCopyTo  OpcUaLocalizedTextCopyTo
	#define CHK_OpcUaLocalizedTextCopyTo  TRUE
	#define EXP_OpcUaLocalizedTextCopyTo  CAL_CMEXPAPI( "OpcUaLocalizedTextCopyTo" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaLocalizedTextCopyTo
	#define EXT_OpcUaLocalizedTextCopyTo
	#define GET_OpcUaLocalizedTextCopyTo(fl)  CAL_CMGETAPI( "OpcUaLocalizedTextCopyTo" ) 
	#define CAL_OpcUaLocalizedTextCopyTo  OpcUaLocalizedTextCopyTo
	#define CHK_OpcUaLocalizedTextCopyTo  TRUE
	#define EXP_OpcUaLocalizedTextCopyTo  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaLocalizedTextCopyTo", (RTS_UINTPTR)OpcUaLocalizedTextCopyTo, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaLocalizedTextCopyTo
	#define EXT_CmpOPCUAStackOpcUaLocalizedTextCopyTo
	#define GET_CmpOPCUAStackOpcUaLocalizedTextCopyTo  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaLocalizedTextCopyTo pICmpOPCUAStack->IOpcUaLocalizedTextCopyTo
	#define CHK_CmpOPCUAStackOpcUaLocalizedTextCopyTo (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaLocalizedTextCopyTo  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaLocalizedTextCopyTo
	#define EXT_OpcUaLocalizedTextCopyTo
	#define GET_OpcUaLocalizedTextCopyTo(fl)  CAL_CMGETAPI( "OpcUaLocalizedTextCopyTo" ) 
	#define CAL_OpcUaLocalizedTextCopyTo pICmpOPCUAStack->IOpcUaLocalizedTextCopyTo
	#define CHK_OpcUaLocalizedTextCopyTo (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaLocalizedTextCopyTo  CAL_CMEXPAPI( "OpcUaLocalizedTextCopyTo" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaLocalizedTextCopyTo  PFOPCUALOCALIZEDTEXTCOPYTO pfOpcUaLocalizedTextCopyTo;
	#define EXT_OpcUaLocalizedTextCopyTo  extern PFOPCUALOCALIZEDTEXTCOPYTO pfOpcUaLocalizedTextCopyTo;
	#define GET_OpcUaLocalizedTextCopyTo(fl)  s_pfCMGetAPI2( "OpcUaLocalizedTextCopyTo", (RTS_VOID_FCTPTR *)&pfOpcUaLocalizedTextCopyTo, (fl), 0, 0)
	#define CAL_OpcUaLocalizedTextCopyTo  pfOpcUaLocalizedTextCopyTo
	#define CHK_OpcUaLocalizedTextCopyTo  (pfOpcUaLocalizedTextCopyTo != NULL)
	#define EXP_OpcUaLocalizedTextCopyTo  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaLocalizedTextCopyTo", (RTS_UINTPTR)OpcUaLocalizedTextCopyTo, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaNodeIdInitialize(OpcUa_NodeId* pValue);
typedef OpcUa_Void (CDECL * PFOPCUANODEIDINITIALIZE) (OpcUa_NodeId* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUANODEIDINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaNodeIdInitialize
	#define EXT_OpcUaNodeIdInitialize
	#define GET_OpcUaNodeIdInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaNodeIdInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaNodeIdInitialize  FALSE
	#define EXP_OpcUaNodeIdInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaNodeIdInitialize
	#define EXT_OpcUaNodeIdInitialize
	#define GET_OpcUaNodeIdInitialize(fl)  CAL_CMGETAPI( "OpcUaNodeIdInitialize" ) 
	#define CAL_OpcUaNodeIdInitialize  OpcUaNodeIdInitialize
	#define CHK_OpcUaNodeIdInitialize  TRUE
	#define EXP_OpcUaNodeIdInitialize  CAL_CMEXPAPI( "OpcUaNodeIdInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaNodeIdInitialize
	#define EXT_OpcUaNodeIdInitialize
	#define GET_OpcUaNodeIdInitialize(fl)  CAL_CMGETAPI( "OpcUaNodeIdInitialize" ) 
	#define CAL_OpcUaNodeIdInitialize  OpcUaNodeIdInitialize
	#define CHK_OpcUaNodeIdInitialize  TRUE
	#define EXP_OpcUaNodeIdInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaNodeIdInitialize", (RTS_UINTPTR)OpcUaNodeIdInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaNodeIdInitialize
	#define EXT_CmpOPCUAStackOpcUaNodeIdInitialize
	#define GET_CmpOPCUAStackOpcUaNodeIdInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaNodeIdInitialize pICmpOPCUAStack->IOpcUaNodeIdInitialize
	#define CHK_CmpOPCUAStackOpcUaNodeIdInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaNodeIdInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaNodeIdInitialize
	#define EXT_OpcUaNodeIdInitialize
	#define GET_OpcUaNodeIdInitialize(fl)  CAL_CMGETAPI( "OpcUaNodeIdInitialize" ) 
	#define CAL_OpcUaNodeIdInitialize pICmpOPCUAStack->IOpcUaNodeIdInitialize
	#define CHK_OpcUaNodeIdInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaNodeIdInitialize  CAL_CMEXPAPI( "OpcUaNodeIdInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaNodeIdInitialize  PFOPCUANODEIDINITIALIZE pfOpcUaNodeIdInitialize;
	#define EXT_OpcUaNodeIdInitialize  extern PFOPCUANODEIDINITIALIZE pfOpcUaNodeIdInitialize;
	#define GET_OpcUaNodeIdInitialize(fl)  s_pfCMGetAPI2( "OpcUaNodeIdInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaNodeIdInitialize, (fl), 0, 0)
	#define CAL_OpcUaNodeIdInitialize  pfOpcUaNodeIdInitialize
	#define CHK_OpcUaNodeIdInitialize  (pfOpcUaNodeIdInitialize != NULL)
	#define EXP_OpcUaNodeIdInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaNodeIdInitialize", (RTS_UINTPTR)OpcUaNodeIdInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaNodeIdClear(OpcUa_NodeId* pValue);
typedef OpcUa_Void (CDECL * PFOPCUANODEIDCLEAR) (OpcUa_NodeId* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUANODEIDCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaNodeIdClear
	#define EXT_OpcUaNodeIdClear
	#define GET_OpcUaNodeIdClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaNodeIdClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaNodeIdClear  FALSE
	#define EXP_OpcUaNodeIdClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaNodeIdClear
	#define EXT_OpcUaNodeIdClear
	#define GET_OpcUaNodeIdClear(fl)  CAL_CMGETAPI( "OpcUaNodeIdClear" ) 
	#define CAL_OpcUaNodeIdClear  OpcUaNodeIdClear
	#define CHK_OpcUaNodeIdClear  TRUE
	#define EXP_OpcUaNodeIdClear  CAL_CMEXPAPI( "OpcUaNodeIdClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaNodeIdClear
	#define EXT_OpcUaNodeIdClear
	#define GET_OpcUaNodeIdClear(fl)  CAL_CMGETAPI( "OpcUaNodeIdClear" ) 
	#define CAL_OpcUaNodeIdClear  OpcUaNodeIdClear
	#define CHK_OpcUaNodeIdClear  TRUE
	#define EXP_OpcUaNodeIdClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaNodeIdClear", (RTS_UINTPTR)OpcUaNodeIdClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaNodeIdClear
	#define EXT_CmpOPCUAStackOpcUaNodeIdClear
	#define GET_CmpOPCUAStackOpcUaNodeIdClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaNodeIdClear pICmpOPCUAStack->IOpcUaNodeIdClear
	#define CHK_CmpOPCUAStackOpcUaNodeIdClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaNodeIdClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaNodeIdClear
	#define EXT_OpcUaNodeIdClear
	#define GET_OpcUaNodeIdClear(fl)  CAL_CMGETAPI( "OpcUaNodeIdClear" ) 
	#define CAL_OpcUaNodeIdClear pICmpOPCUAStack->IOpcUaNodeIdClear
	#define CHK_OpcUaNodeIdClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaNodeIdClear  CAL_CMEXPAPI( "OpcUaNodeIdClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaNodeIdClear  PFOPCUANODEIDCLEAR pfOpcUaNodeIdClear;
	#define EXT_OpcUaNodeIdClear  extern PFOPCUANODEIDCLEAR pfOpcUaNodeIdClear;
	#define GET_OpcUaNodeIdClear(fl)  s_pfCMGetAPI2( "OpcUaNodeIdClear", (RTS_VOID_FCTPTR *)&pfOpcUaNodeIdClear, (fl), 0, 0)
	#define CAL_OpcUaNodeIdClear  pfOpcUaNodeIdClear
	#define CHK_OpcUaNodeIdClear  (pfOpcUaNodeIdClear != NULL)
	#define EXP_OpcUaNodeIdClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaNodeIdClear", (RTS_UINTPTR)OpcUaNodeIdClear, 0, 0) 
#endif



OpcUa_Int CDECL OpcUaNodeIdCompare(const OpcUa_NodeId* pValue1, const OpcUa_NodeId* pValue2);
typedef OpcUa_Int (CDECL * PFOPCUANODEIDCOMPARE) (const OpcUa_NodeId* pValue1, const OpcUa_NodeId* pValue2);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUANODEIDCOMPARE_NOTIMPLEMENTED)
	#define USE_OpcUaNodeIdCompare
	#define EXT_OpcUaNodeIdCompare
	#define GET_OpcUaNodeIdCompare(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaNodeIdCompare(p0,p1)  (OpcUa_Int)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaNodeIdCompare  FALSE
	#define EXP_OpcUaNodeIdCompare  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaNodeIdCompare
	#define EXT_OpcUaNodeIdCompare
	#define GET_OpcUaNodeIdCompare(fl)  CAL_CMGETAPI( "OpcUaNodeIdCompare" ) 
	#define CAL_OpcUaNodeIdCompare  OpcUaNodeIdCompare
	#define CHK_OpcUaNodeIdCompare  TRUE
	#define EXP_OpcUaNodeIdCompare  CAL_CMEXPAPI( "OpcUaNodeIdCompare" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaNodeIdCompare
	#define EXT_OpcUaNodeIdCompare
	#define GET_OpcUaNodeIdCompare(fl)  CAL_CMGETAPI( "OpcUaNodeIdCompare" ) 
	#define CAL_OpcUaNodeIdCompare  OpcUaNodeIdCompare
	#define CHK_OpcUaNodeIdCompare  TRUE
	#define EXP_OpcUaNodeIdCompare  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaNodeIdCompare", (RTS_UINTPTR)OpcUaNodeIdCompare, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaNodeIdCompare
	#define EXT_CmpOPCUAStackOpcUaNodeIdCompare
	#define GET_CmpOPCUAStackOpcUaNodeIdCompare  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaNodeIdCompare pICmpOPCUAStack->IOpcUaNodeIdCompare
	#define CHK_CmpOPCUAStackOpcUaNodeIdCompare (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaNodeIdCompare  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaNodeIdCompare
	#define EXT_OpcUaNodeIdCompare
	#define GET_OpcUaNodeIdCompare(fl)  CAL_CMGETAPI( "OpcUaNodeIdCompare" ) 
	#define CAL_OpcUaNodeIdCompare pICmpOPCUAStack->IOpcUaNodeIdCompare
	#define CHK_OpcUaNodeIdCompare (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaNodeIdCompare  CAL_CMEXPAPI( "OpcUaNodeIdCompare" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaNodeIdCompare  PFOPCUANODEIDCOMPARE pfOpcUaNodeIdCompare;
	#define EXT_OpcUaNodeIdCompare  extern PFOPCUANODEIDCOMPARE pfOpcUaNodeIdCompare;
	#define GET_OpcUaNodeIdCompare(fl)  s_pfCMGetAPI2( "OpcUaNodeIdCompare", (RTS_VOID_FCTPTR *)&pfOpcUaNodeIdCompare, (fl), 0, 0)
	#define CAL_OpcUaNodeIdCompare  pfOpcUaNodeIdCompare
	#define CHK_OpcUaNodeIdCompare  (pfOpcUaNodeIdCompare != NULL)
	#define EXP_OpcUaNodeIdCompare  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaNodeIdCompare", (RTS_UINTPTR)OpcUaNodeIdCompare, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaNodeIdCopyTo(const OpcUa_NodeId* pSource, OpcUa_NodeId* pDestination);
typedef OpcUa_StatusCode (CDECL * PFOPCUANODEIDCOPYTO) (const OpcUa_NodeId* pSource, OpcUa_NodeId* pDestination);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUANODEIDCOPYTO_NOTIMPLEMENTED)
	#define USE_OpcUaNodeIdCopyTo
	#define EXT_OpcUaNodeIdCopyTo
	#define GET_OpcUaNodeIdCopyTo(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaNodeIdCopyTo(p0,p1)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaNodeIdCopyTo  FALSE
	#define EXP_OpcUaNodeIdCopyTo  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaNodeIdCopyTo
	#define EXT_OpcUaNodeIdCopyTo
	#define GET_OpcUaNodeIdCopyTo(fl)  CAL_CMGETAPI( "OpcUaNodeIdCopyTo" ) 
	#define CAL_OpcUaNodeIdCopyTo  OpcUaNodeIdCopyTo
	#define CHK_OpcUaNodeIdCopyTo  TRUE
	#define EXP_OpcUaNodeIdCopyTo  CAL_CMEXPAPI( "OpcUaNodeIdCopyTo" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaNodeIdCopyTo
	#define EXT_OpcUaNodeIdCopyTo
	#define GET_OpcUaNodeIdCopyTo(fl)  CAL_CMGETAPI( "OpcUaNodeIdCopyTo" ) 
	#define CAL_OpcUaNodeIdCopyTo  OpcUaNodeIdCopyTo
	#define CHK_OpcUaNodeIdCopyTo  TRUE
	#define EXP_OpcUaNodeIdCopyTo  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaNodeIdCopyTo", (RTS_UINTPTR)OpcUaNodeIdCopyTo, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaNodeIdCopyTo
	#define EXT_CmpOPCUAStackOpcUaNodeIdCopyTo
	#define GET_CmpOPCUAStackOpcUaNodeIdCopyTo  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaNodeIdCopyTo pICmpOPCUAStack->IOpcUaNodeIdCopyTo
	#define CHK_CmpOPCUAStackOpcUaNodeIdCopyTo (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaNodeIdCopyTo  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaNodeIdCopyTo
	#define EXT_OpcUaNodeIdCopyTo
	#define GET_OpcUaNodeIdCopyTo(fl)  CAL_CMGETAPI( "OpcUaNodeIdCopyTo" ) 
	#define CAL_OpcUaNodeIdCopyTo pICmpOPCUAStack->IOpcUaNodeIdCopyTo
	#define CHK_OpcUaNodeIdCopyTo (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaNodeIdCopyTo  CAL_CMEXPAPI( "OpcUaNodeIdCopyTo" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaNodeIdCopyTo  PFOPCUANODEIDCOPYTO pfOpcUaNodeIdCopyTo;
	#define EXT_OpcUaNodeIdCopyTo  extern PFOPCUANODEIDCOPYTO pfOpcUaNodeIdCopyTo;
	#define GET_OpcUaNodeIdCopyTo(fl)  s_pfCMGetAPI2( "OpcUaNodeIdCopyTo", (RTS_VOID_FCTPTR *)&pfOpcUaNodeIdCopyTo, (fl), 0, 0)
	#define CAL_OpcUaNodeIdCopyTo  pfOpcUaNodeIdCopyTo
	#define CHK_OpcUaNodeIdCopyTo  (pfOpcUaNodeIdCopyTo != NULL)
	#define EXP_OpcUaNodeIdCopyTo  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaNodeIdCopyTo", (RTS_UINTPTR)OpcUaNodeIdCopyTo, 0, 0) 
#endif



OpcUa_Boolean CDECL OpcUaNodeIdIsNull(OpcUa_NodeId* pValue);
typedef OpcUa_Boolean (CDECL * PFOPCUANODEIDISNULL) (OpcUa_NodeId* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUANODEIDISNULL_NOTIMPLEMENTED)
	#define USE_OpcUaNodeIdIsNull
	#define EXT_OpcUaNodeIdIsNull
	#define GET_OpcUaNodeIdIsNull(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaNodeIdIsNull(p0)  (OpcUa_Boolean)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaNodeIdIsNull  FALSE
	#define EXP_OpcUaNodeIdIsNull  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaNodeIdIsNull
	#define EXT_OpcUaNodeIdIsNull
	#define GET_OpcUaNodeIdIsNull(fl)  CAL_CMGETAPI( "OpcUaNodeIdIsNull" ) 
	#define CAL_OpcUaNodeIdIsNull  OpcUaNodeIdIsNull
	#define CHK_OpcUaNodeIdIsNull  TRUE
	#define EXP_OpcUaNodeIdIsNull  CAL_CMEXPAPI( "OpcUaNodeIdIsNull" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaNodeIdIsNull
	#define EXT_OpcUaNodeIdIsNull
	#define GET_OpcUaNodeIdIsNull(fl)  CAL_CMGETAPI( "OpcUaNodeIdIsNull" ) 
	#define CAL_OpcUaNodeIdIsNull  OpcUaNodeIdIsNull
	#define CHK_OpcUaNodeIdIsNull  TRUE
	#define EXP_OpcUaNodeIdIsNull  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaNodeIdIsNull", (RTS_UINTPTR)OpcUaNodeIdIsNull, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaNodeIdIsNull
	#define EXT_CmpOPCUAStackOpcUaNodeIdIsNull
	#define GET_CmpOPCUAStackOpcUaNodeIdIsNull  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaNodeIdIsNull pICmpOPCUAStack->IOpcUaNodeIdIsNull
	#define CHK_CmpOPCUAStackOpcUaNodeIdIsNull (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaNodeIdIsNull  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaNodeIdIsNull
	#define EXT_OpcUaNodeIdIsNull
	#define GET_OpcUaNodeIdIsNull(fl)  CAL_CMGETAPI( "OpcUaNodeIdIsNull" ) 
	#define CAL_OpcUaNodeIdIsNull pICmpOPCUAStack->IOpcUaNodeIdIsNull
	#define CHK_OpcUaNodeIdIsNull (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaNodeIdIsNull  CAL_CMEXPAPI( "OpcUaNodeIdIsNull" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaNodeIdIsNull  PFOPCUANODEIDISNULL pfOpcUaNodeIdIsNull;
	#define EXT_OpcUaNodeIdIsNull  extern PFOPCUANODEIDISNULL pfOpcUaNodeIdIsNull;
	#define GET_OpcUaNodeIdIsNull(fl)  s_pfCMGetAPI2( "OpcUaNodeIdIsNull", (RTS_VOID_FCTPTR *)&pfOpcUaNodeIdIsNull, (fl), 0, 0)
	#define CAL_OpcUaNodeIdIsNull  pfOpcUaNodeIdIsNull
	#define CHK_OpcUaNodeIdIsNull  (pfOpcUaNodeIdIsNull != NULL)
	#define EXP_OpcUaNodeIdIsNull  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaNodeIdIsNull", (RTS_UINTPTR)OpcUaNodeIdIsNull, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaExpandedNodeIdInitialize(OpcUa_ExpandedNodeId* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAEXPANDEDNODEIDINITIALIZE) (OpcUa_ExpandedNodeId* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAEXPANDEDNODEIDINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaExpandedNodeIdInitialize
	#define EXT_OpcUaExpandedNodeIdInitialize
	#define GET_OpcUaExpandedNodeIdInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaExpandedNodeIdInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaExpandedNodeIdInitialize  FALSE
	#define EXP_OpcUaExpandedNodeIdInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaExpandedNodeIdInitialize
	#define EXT_OpcUaExpandedNodeIdInitialize
	#define GET_OpcUaExpandedNodeIdInitialize(fl)  CAL_CMGETAPI( "OpcUaExpandedNodeIdInitialize" ) 
	#define CAL_OpcUaExpandedNodeIdInitialize  OpcUaExpandedNodeIdInitialize
	#define CHK_OpcUaExpandedNodeIdInitialize  TRUE
	#define EXP_OpcUaExpandedNodeIdInitialize  CAL_CMEXPAPI( "OpcUaExpandedNodeIdInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaExpandedNodeIdInitialize
	#define EXT_OpcUaExpandedNodeIdInitialize
	#define GET_OpcUaExpandedNodeIdInitialize(fl)  CAL_CMGETAPI( "OpcUaExpandedNodeIdInitialize" ) 
	#define CAL_OpcUaExpandedNodeIdInitialize  OpcUaExpandedNodeIdInitialize
	#define CHK_OpcUaExpandedNodeIdInitialize  TRUE
	#define EXP_OpcUaExpandedNodeIdInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaExpandedNodeIdInitialize", (RTS_UINTPTR)OpcUaExpandedNodeIdInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaExpandedNodeIdInitialize
	#define EXT_CmpOPCUAStackOpcUaExpandedNodeIdInitialize
	#define GET_CmpOPCUAStackOpcUaExpandedNodeIdInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaExpandedNodeIdInitialize pICmpOPCUAStack->IOpcUaExpandedNodeIdInitialize
	#define CHK_CmpOPCUAStackOpcUaExpandedNodeIdInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaExpandedNodeIdInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaExpandedNodeIdInitialize
	#define EXT_OpcUaExpandedNodeIdInitialize
	#define GET_OpcUaExpandedNodeIdInitialize(fl)  CAL_CMGETAPI( "OpcUaExpandedNodeIdInitialize" ) 
	#define CAL_OpcUaExpandedNodeIdInitialize pICmpOPCUAStack->IOpcUaExpandedNodeIdInitialize
	#define CHK_OpcUaExpandedNodeIdInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaExpandedNodeIdInitialize  CAL_CMEXPAPI( "OpcUaExpandedNodeIdInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaExpandedNodeIdInitialize  PFOPCUAEXPANDEDNODEIDINITIALIZE pfOpcUaExpandedNodeIdInitialize;
	#define EXT_OpcUaExpandedNodeIdInitialize  extern PFOPCUAEXPANDEDNODEIDINITIALIZE pfOpcUaExpandedNodeIdInitialize;
	#define GET_OpcUaExpandedNodeIdInitialize(fl)  s_pfCMGetAPI2( "OpcUaExpandedNodeIdInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaExpandedNodeIdInitialize, (fl), 0, 0)
	#define CAL_OpcUaExpandedNodeIdInitialize  pfOpcUaExpandedNodeIdInitialize
	#define CHK_OpcUaExpandedNodeIdInitialize  (pfOpcUaExpandedNodeIdInitialize != NULL)
	#define EXP_OpcUaExpandedNodeIdInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaExpandedNodeIdInitialize", (RTS_UINTPTR)OpcUaExpandedNodeIdInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaExpandedNodeIdClear(OpcUa_ExpandedNodeId* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAEXPANDEDNODEIDCLEAR) (OpcUa_ExpandedNodeId* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAEXPANDEDNODEIDCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaExpandedNodeIdClear
	#define EXT_OpcUaExpandedNodeIdClear
	#define GET_OpcUaExpandedNodeIdClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaExpandedNodeIdClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaExpandedNodeIdClear  FALSE
	#define EXP_OpcUaExpandedNodeIdClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaExpandedNodeIdClear
	#define EXT_OpcUaExpandedNodeIdClear
	#define GET_OpcUaExpandedNodeIdClear(fl)  CAL_CMGETAPI( "OpcUaExpandedNodeIdClear" ) 
	#define CAL_OpcUaExpandedNodeIdClear  OpcUaExpandedNodeIdClear
	#define CHK_OpcUaExpandedNodeIdClear  TRUE
	#define EXP_OpcUaExpandedNodeIdClear  CAL_CMEXPAPI( "OpcUaExpandedNodeIdClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaExpandedNodeIdClear
	#define EXT_OpcUaExpandedNodeIdClear
	#define GET_OpcUaExpandedNodeIdClear(fl)  CAL_CMGETAPI( "OpcUaExpandedNodeIdClear" ) 
	#define CAL_OpcUaExpandedNodeIdClear  OpcUaExpandedNodeIdClear
	#define CHK_OpcUaExpandedNodeIdClear  TRUE
	#define EXP_OpcUaExpandedNodeIdClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaExpandedNodeIdClear", (RTS_UINTPTR)OpcUaExpandedNodeIdClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaExpandedNodeIdClear
	#define EXT_CmpOPCUAStackOpcUaExpandedNodeIdClear
	#define GET_CmpOPCUAStackOpcUaExpandedNodeIdClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaExpandedNodeIdClear pICmpOPCUAStack->IOpcUaExpandedNodeIdClear
	#define CHK_CmpOPCUAStackOpcUaExpandedNodeIdClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaExpandedNodeIdClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaExpandedNodeIdClear
	#define EXT_OpcUaExpandedNodeIdClear
	#define GET_OpcUaExpandedNodeIdClear(fl)  CAL_CMGETAPI( "OpcUaExpandedNodeIdClear" ) 
	#define CAL_OpcUaExpandedNodeIdClear pICmpOPCUAStack->IOpcUaExpandedNodeIdClear
	#define CHK_OpcUaExpandedNodeIdClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaExpandedNodeIdClear  CAL_CMEXPAPI( "OpcUaExpandedNodeIdClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaExpandedNodeIdClear  PFOPCUAEXPANDEDNODEIDCLEAR pfOpcUaExpandedNodeIdClear;
	#define EXT_OpcUaExpandedNodeIdClear  extern PFOPCUAEXPANDEDNODEIDCLEAR pfOpcUaExpandedNodeIdClear;
	#define GET_OpcUaExpandedNodeIdClear(fl)  s_pfCMGetAPI2( "OpcUaExpandedNodeIdClear", (RTS_VOID_FCTPTR *)&pfOpcUaExpandedNodeIdClear, (fl), 0, 0)
	#define CAL_OpcUaExpandedNodeIdClear  pfOpcUaExpandedNodeIdClear
	#define CHK_OpcUaExpandedNodeIdClear  (pfOpcUaExpandedNodeIdClear != NULL)
	#define EXP_OpcUaExpandedNodeIdClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaExpandedNodeIdClear", (RTS_UINTPTR)OpcUaExpandedNodeIdClear, 0, 0) 
#endif



OpcUa_Int CDECL OpcUaExpandedNodeIdCompare(const OpcUa_ExpandedNodeId* pValue1, const OpcUa_ExpandedNodeId* pValue2);
typedef OpcUa_Int (CDECL * PFOPCUAEXPANDEDNODEIDCOMPARE) (const OpcUa_ExpandedNodeId* pValue1, const OpcUa_ExpandedNodeId* pValue2);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAEXPANDEDNODEIDCOMPARE_NOTIMPLEMENTED)
	#define USE_OpcUaExpandedNodeIdCompare
	#define EXT_OpcUaExpandedNodeIdCompare
	#define GET_OpcUaExpandedNodeIdCompare(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaExpandedNodeIdCompare(p0,p1)  (OpcUa_Int)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaExpandedNodeIdCompare  FALSE
	#define EXP_OpcUaExpandedNodeIdCompare  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaExpandedNodeIdCompare
	#define EXT_OpcUaExpandedNodeIdCompare
	#define GET_OpcUaExpandedNodeIdCompare(fl)  CAL_CMGETAPI( "OpcUaExpandedNodeIdCompare" ) 
	#define CAL_OpcUaExpandedNodeIdCompare  OpcUaExpandedNodeIdCompare
	#define CHK_OpcUaExpandedNodeIdCompare  TRUE
	#define EXP_OpcUaExpandedNodeIdCompare  CAL_CMEXPAPI( "OpcUaExpandedNodeIdCompare" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaExpandedNodeIdCompare
	#define EXT_OpcUaExpandedNodeIdCompare
	#define GET_OpcUaExpandedNodeIdCompare(fl)  CAL_CMGETAPI( "OpcUaExpandedNodeIdCompare" ) 
	#define CAL_OpcUaExpandedNodeIdCompare  OpcUaExpandedNodeIdCompare
	#define CHK_OpcUaExpandedNodeIdCompare  TRUE
	#define EXP_OpcUaExpandedNodeIdCompare  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaExpandedNodeIdCompare", (RTS_UINTPTR)OpcUaExpandedNodeIdCompare, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaExpandedNodeIdCompare
	#define EXT_CmpOPCUAStackOpcUaExpandedNodeIdCompare
	#define GET_CmpOPCUAStackOpcUaExpandedNodeIdCompare  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaExpandedNodeIdCompare pICmpOPCUAStack->IOpcUaExpandedNodeIdCompare
	#define CHK_CmpOPCUAStackOpcUaExpandedNodeIdCompare (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaExpandedNodeIdCompare  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaExpandedNodeIdCompare
	#define EXT_OpcUaExpandedNodeIdCompare
	#define GET_OpcUaExpandedNodeIdCompare(fl)  CAL_CMGETAPI( "OpcUaExpandedNodeIdCompare" ) 
	#define CAL_OpcUaExpandedNodeIdCompare pICmpOPCUAStack->IOpcUaExpandedNodeIdCompare
	#define CHK_OpcUaExpandedNodeIdCompare (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaExpandedNodeIdCompare  CAL_CMEXPAPI( "OpcUaExpandedNodeIdCompare" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaExpandedNodeIdCompare  PFOPCUAEXPANDEDNODEIDCOMPARE pfOpcUaExpandedNodeIdCompare;
	#define EXT_OpcUaExpandedNodeIdCompare  extern PFOPCUAEXPANDEDNODEIDCOMPARE pfOpcUaExpandedNodeIdCompare;
	#define GET_OpcUaExpandedNodeIdCompare(fl)  s_pfCMGetAPI2( "OpcUaExpandedNodeIdCompare", (RTS_VOID_FCTPTR *)&pfOpcUaExpandedNodeIdCompare, (fl), 0, 0)
	#define CAL_OpcUaExpandedNodeIdCompare  pfOpcUaExpandedNodeIdCompare
	#define CHK_OpcUaExpandedNodeIdCompare  (pfOpcUaExpandedNodeIdCompare != NULL)
	#define EXP_OpcUaExpandedNodeIdCompare  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaExpandedNodeIdCompare", (RTS_UINTPTR)OpcUaExpandedNodeIdCompare, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaExpandedNodeIdCopyTo(const OpcUa_ExpandedNodeId* pSource, OpcUa_ExpandedNodeId* pDestination);
typedef OpcUa_StatusCode (CDECL * PFOPCUAEXPANDEDNODEIDCOPYTO) (const OpcUa_ExpandedNodeId* pSource, OpcUa_ExpandedNodeId* pDestination);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAEXPANDEDNODEIDCOPYTO_NOTIMPLEMENTED)
	#define USE_OpcUaExpandedNodeIdCopyTo
	#define EXT_OpcUaExpandedNodeIdCopyTo
	#define GET_OpcUaExpandedNodeIdCopyTo(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaExpandedNodeIdCopyTo(p0,p1)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaExpandedNodeIdCopyTo  FALSE
	#define EXP_OpcUaExpandedNodeIdCopyTo  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaExpandedNodeIdCopyTo
	#define EXT_OpcUaExpandedNodeIdCopyTo
	#define GET_OpcUaExpandedNodeIdCopyTo(fl)  CAL_CMGETAPI( "OpcUaExpandedNodeIdCopyTo" ) 
	#define CAL_OpcUaExpandedNodeIdCopyTo  OpcUaExpandedNodeIdCopyTo
	#define CHK_OpcUaExpandedNodeIdCopyTo  TRUE
	#define EXP_OpcUaExpandedNodeIdCopyTo  CAL_CMEXPAPI( "OpcUaExpandedNodeIdCopyTo" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaExpandedNodeIdCopyTo
	#define EXT_OpcUaExpandedNodeIdCopyTo
	#define GET_OpcUaExpandedNodeIdCopyTo(fl)  CAL_CMGETAPI( "OpcUaExpandedNodeIdCopyTo" ) 
	#define CAL_OpcUaExpandedNodeIdCopyTo  OpcUaExpandedNodeIdCopyTo
	#define CHK_OpcUaExpandedNodeIdCopyTo  TRUE
	#define EXP_OpcUaExpandedNodeIdCopyTo  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaExpandedNodeIdCopyTo", (RTS_UINTPTR)OpcUaExpandedNodeIdCopyTo, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaExpandedNodeIdCopyTo
	#define EXT_CmpOPCUAStackOpcUaExpandedNodeIdCopyTo
	#define GET_CmpOPCUAStackOpcUaExpandedNodeIdCopyTo  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaExpandedNodeIdCopyTo pICmpOPCUAStack->IOpcUaExpandedNodeIdCopyTo
	#define CHK_CmpOPCUAStackOpcUaExpandedNodeIdCopyTo (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaExpandedNodeIdCopyTo  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaExpandedNodeIdCopyTo
	#define EXT_OpcUaExpandedNodeIdCopyTo
	#define GET_OpcUaExpandedNodeIdCopyTo(fl)  CAL_CMGETAPI( "OpcUaExpandedNodeIdCopyTo" ) 
	#define CAL_OpcUaExpandedNodeIdCopyTo pICmpOPCUAStack->IOpcUaExpandedNodeIdCopyTo
	#define CHK_OpcUaExpandedNodeIdCopyTo (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaExpandedNodeIdCopyTo  CAL_CMEXPAPI( "OpcUaExpandedNodeIdCopyTo" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaExpandedNodeIdCopyTo  PFOPCUAEXPANDEDNODEIDCOPYTO pfOpcUaExpandedNodeIdCopyTo;
	#define EXT_OpcUaExpandedNodeIdCopyTo  extern PFOPCUAEXPANDEDNODEIDCOPYTO pfOpcUaExpandedNodeIdCopyTo;
	#define GET_OpcUaExpandedNodeIdCopyTo(fl)  s_pfCMGetAPI2( "OpcUaExpandedNodeIdCopyTo", (RTS_VOID_FCTPTR *)&pfOpcUaExpandedNodeIdCopyTo, (fl), 0, 0)
	#define CAL_OpcUaExpandedNodeIdCopyTo  pfOpcUaExpandedNodeIdCopyTo
	#define CHK_OpcUaExpandedNodeIdCopyTo  (pfOpcUaExpandedNodeIdCopyTo != NULL)
	#define EXP_OpcUaExpandedNodeIdCopyTo  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaExpandedNodeIdCopyTo", (RTS_UINTPTR)OpcUaExpandedNodeIdCopyTo, 0, 0) 
#endif



OpcUa_Boolean CDECL OpcUaExpandedNodeIdIsNull(OpcUa_ExpandedNodeId* pValue);
typedef OpcUa_Boolean (CDECL * PFOPCUAEXPANDEDNODEIDISNULL) (OpcUa_ExpandedNodeId* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAEXPANDEDNODEIDISNULL_NOTIMPLEMENTED)
	#define USE_OpcUaExpandedNodeIdIsNull
	#define EXT_OpcUaExpandedNodeIdIsNull
	#define GET_OpcUaExpandedNodeIdIsNull(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaExpandedNodeIdIsNull(p0)  (OpcUa_Boolean)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaExpandedNodeIdIsNull  FALSE
	#define EXP_OpcUaExpandedNodeIdIsNull  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaExpandedNodeIdIsNull
	#define EXT_OpcUaExpandedNodeIdIsNull
	#define GET_OpcUaExpandedNodeIdIsNull(fl)  CAL_CMGETAPI( "OpcUaExpandedNodeIdIsNull" ) 
	#define CAL_OpcUaExpandedNodeIdIsNull  OpcUaExpandedNodeIdIsNull
	#define CHK_OpcUaExpandedNodeIdIsNull  TRUE
	#define EXP_OpcUaExpandedNodeIdIsNull  CAL_CMEXPAPI( "OpcUaExpandedNodeIdIsNull" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaExpandedNodeIdIsNull
	#define EXT_OpcUaExpandedNodeIdIsNull
	#define GET_OpcUaExpandedNodeIdIsNull(fl)  CAL_CMGETAPI( "OpcUaExpandedNodeIdIsNull" ) 
	#define CAL_OpcUaExpandedNodeIdIsNull  OpcUaExpandedNodeIdIsNull
	#define CHK_OpcUaExpandedNodeIdIsNull  TRUE
	#define EXP_OpcUaExpandedNodeIdIsNull  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaExpandedNodeIdIsNull", (RTS_UINTPTR)OpcUaExpandedNodeIdIsNull, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaExpandedNodeIdIsNull
	#define EXT_CmpOPCUAStackOpcUaExpandedNodeIdIsNull
	#define GET_CmpOPCUAStackOpcUaExpandedNodeIdIsNull  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaExpandedNodeIdIsNull pICmpOPCUAStack->IOpcUaExpandedNodeIdIsNull
	#define CHK_CmpOPCUAStackOpcUaExpandedNodeIdIsNull (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaExpandedNodeIdIsNull  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaExpandedNodeIdIsNull
	#define EXT_OpcUaExpandedNodeIdIsNull
	#define GET_OpcUaExpandedNodeIdIsNull(fl)  CAL_CMGETAPI( "OpcUaExpandedNodeIdIsNull" ) 
	#define CAL_OpcUaExpandedNodeIdIsNull pICmpOPCUAStack->IOpcUaExpandedNodeIdIsNull
	#define CHK_OpcUaExpandedNodeIdIsNull (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaExpandedNodeIdIsNull  CAL_CMEXPAPI( "OpcUaExpandedNodeIdIsNull" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaExpandedNodeIdIsNull  PFOPCUAEXPANDEDNODEIDISNULL pfOpcUaExpandedNodeIdIsNull;
	#define EXT_OpcUaExpandedNodeIdIsNull  extern PFOPCUAEXPANDEDNODEIDISNULL pfOpcUaExpandedNodeIdIsNull;
	#define GET_OpcUaExpandedNodeIdIsNull(fl)  s_pfCMGetAPI2( "OpcUaExpandedNodeIdIsNull", (RTS_VOID_FCTPTR *)&pfOpcUaExpandedNodeIdIsNull, (fl), 0, 0)
	#define CAL_OpcUaExpandedNodeIdIsNull  pfOpcUaExpandedNodeIdIsNull
	#define CHK_OpcUaExpandedNodeIdIsNull  (pfOpcUaExpandedNodeIdIsNull != NULL)
	#define EXP_OpcUaExpandedNodeIdIsNull  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaExpandedNodeIdIsNull", (RTS_UINTPTR)OpcUaExpandedNodeIdIsNull, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaQualifiedNameInitialize(OpcUa_QualifiedName* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAQUALIFIEDNAMEINITIALIZE) (OpcUa_QualifiedName* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAQUALIFIEDNAMEINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaQualifiedNameInitialize
	#define EXT_OpcUaQualifiedNameInitialize
	#define GET_OpcUaQualifiedNameInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaQualifiedNameInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaQualifiedNameInitialize  FALSE
	#define EXP_OpcUaQualifiedNameInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaQualifiedNameInitialize
	#define EXT_OpcUaQualifiedNameInitialize
	#define GET_OpcUaQualifiedNameInitialize(fl)  CAL_CMGETAPI( "OpcUaQualifiedNameInitialize" ) 
	#define CAL_OpcUaQualifiedNameInitialize  OpcUaQualifiedNameInitialize
	#define CHK_OpcUaQualifiedNameInitialize  TRUE
	#define EXP_OpcUaQualifiedNameInitialize  CAL_CMEXPAPI( "OpcUaQualifiedNameInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaQualifiedNameInitialize
	#define EXT_OpcUaQualifiedNameInitialize
	#define GET_OpcUaQualifiedNameInitialize(fl)  CAL_CMGETAPI( "OpcUaQualifiedNameInitialize" ) 
	#define CAL_OpcUaQualifiedNameInitialize  OpcUaQualifiedNameInitialize
	#define CHK_OpcUaQualifiedNameInitialize  TRUE
	#define EXP_OpcUaQualifiedNameInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaQualifiedNameInitialize", (RTS_UINTPTR)OpcUaQualifiedNameInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaQualifiedNameInitialize
	#define EXT_CmpOPCUAStackOpcUaQualifiedNameInitialize
	#define GET_CmpOPCUAStackOpcUaQualifiedNameInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaQualifiedNameInitialize pICmpOPCUAStack->IOpcUaQualifiedNameInitialize
	#define CHK_CmpOPCUAStackOpcUaQualifiedNameInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaQualifiedNameInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaQualifiedNameInitialize
	#define EXT_OpcUaQualifiedNameInitialize
	#define GET_OpcUaQualifiedNameInitialize(fl)  CAL_CMGETAPI( "OpcUaQualifiedNameInitialize" ) 
	#define CAL_OpcUaQualifiedNameInitialize pICmpOPCUAStack->IOpcUaQualifiedNameInitialize
	#define CHK_OpcUaQualifiedNameInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaQualifiedNameInitialize  CAL_CMEXPAPI( "OpcUaQualifiedNameInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaQualifiedNameInitialize  PFOPCUAQUALIFIEDNAMEINITIALIZE pfOpcUaQualifiedNameInitialize;
	#define EXT_OpcUaQualifiedNameInitialize  extern PFOPCUAQUALIFIEDNAMEINITIALIZE pfOpcUaQualifiedNameInitialize;
	#define GET_OpcUaQualifiedNameInitialize(fl)  s_pfCMGetAPI2( "OpcUaQualifiedNameInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaQualifiedNameInitialize, (fl), 0, 0)
	#define CAL_OpcUaQualifiedNameInitialize  pfOpcUaQualifiedNameInitialize
	#define CHK_OpcUaQualifiedNameInitialize  (pfOpcUaQualifiedNameInitialize != NULL)
	#define EXP_OpcUaQualifiedNameInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaQualifiedNameInitialize", (RTS_UINTPTR)OpcUaQualifiedNameInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaQualifiedNameClear(OpcUa_QualifiedName* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAQUALIFIEDNAMECLEAR) (OpcUa_QualifiedName* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAQUALIFIEDNAMECLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaQualifiedNameClear
	#define EXT_OpcUaQualifiedNameClear
	#define GET_OpcUaQualifiedNameClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaQualifiedNameClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaQualifiedNameClear  FALSE
	#define EXP_OpcUaQualifiedNameClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaQualifiedNameClear
	#define EXT_OpcUaQualifiedNameClear
	#define GET_OpcUaQualifiedNameClear(fl)  CAL_CMGETAPI( "OpcUaQualifiedNameClear" ) 
	#define CAL_OpcUaQualifiedNameClear  OpcUaQualifiedNameClear
	#define CHK_OpcUaQualifiedNameClear  TRUE
	#define EXP_OpcUaQualifiedNameClear  CAL_CMEXPAPI( "OpcUaQualifiedNameClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaQualifiedNameClear
	#define EXT_OpcUaQualifiedNameClear
	#define GET_OpcUaQualifiedNameClear(fl)  CAL_CMGETAPI( "OpcUaQualifiedNameClear" ) 
	#define CAL_OpcUaQualifiedNameClear  OpcUaQualifiedNameClear
	#define CHK_OpcUaQualifiedNameClear  TRUE
	#define EXP_OpcUaQualifiedNameClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaQualifiedNameClear", (RTS_UINTPTR)OpcUaQualifiedNameClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaQualifiedNameClear
	#define EXT_CmpOPCUAStackOpcUaQualifiedNameClear
	#define GET_CmpOPCUAStackOpcUaQualifiedNameClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaQualifiedNameClear pICmpOPCUAStack->IOpcUaQualifiedNameClear
	#define CHK_CmpOPCUAStackOpcUaQualifiedNameClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaQualifiedNameClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaQualifiedNameClear
	#define EXT_OpcUaQualifiedNameClear
	#define GET_OpcUaQualifiedNameClear(fl)  CAL_CMGETAPI( "OpcUaQualifiedNameClear" ) 
	#define CAL_OpcUaQualifiedNameClear pICmpOPCUAStack->IOpcUaQualifiedNameClear
	#define CHK_OpcUaQualifiedNameClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaQualifiedNameClear  CAL_CMEXPAPI( "OpcUaQualifiedNameClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaQualifiedNameClear  PFOPCUAQUALIFIEDNAMECLEAR pfOpcUaQualifiedNameClear;
	#define EXT_OpcUaQualifiedNameClear  extern PFOPCUAQUALIFIEDNAMECLEAR pfOpcUaQualifiedNameClear;
	#define GET_OpcUaQualifiedNameClear(fl)  s_pfCMGetAPI2( "OpcUaQualifiedNameClear", (RTS_VOID_FCTPTR *)&pfOpcUaQualifiedNameClear, (fl), 0, 0)
	#define CAL_OpcUaQualifiedNameClear  pfOpcUaQualifiedNameClear
	#define CHK_OpcUaQualifiedNameClear  (pfOpcUaQualifiedNameClear != NULL)
	#define EXP_OpcUaQualifiedNameClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaQualifiedNameClear", (RTS_UINTPTR)OpcUaQualifiedNameClear, 0, 0) 
#endif



OpcUa_Int CDECL OpcUaQualifiedNameCompare(const OpcUa_QualifiedName* pValue1, const OpcUa_QualifiedName* pValue2);
typedef OpcUa_Int (CDECL * PFOPCUAQUALIFIEDNAMECOMPARE) (const OpcUa_QualifiedName* pValue1, const OpcUa_QualifiedName* pValue2);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAQUALIFIEDNAMECOMPARE_NOTIMPLEMENTED)
	#define USE_OpcUaQualifiedNameCompare
	#define EXT_OpcUaQualifiedNameCompare
	#define GET_OpcUaQualifiedNameCompare(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaQualifiedNameCompare(p0,p1)  (OpcUa_Int)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaQualifiedNameCompare  FALSE
	#define EXP_OpcUaQualifiedNameCompare  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaQualifiedNameCompare
	#define EXT_OpcUaQualifiedNameCompare
	#define GET_OpcUaQualifiedNameCompare(fl)  CAL_CMGETAPI( "OpcUaQualifiedNameCompare" ) 
	#define CAL_OpcUaQualifiedNameCompare  OpcUaQualifiedNameCompare
	#define CHK_OpcUaQualifiedNameCompare  TRUE
	#define EXP_OpcUaQualifiedNameCompare  CAL_CMEXPAPI( "OpcUaQualifiedNameCompare" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaQualifiedNameCompare
	#define EXT_OpcUaQualifiedNameCompare
	#define GET_OpcUaQualifiedNameCompare(fl)  CAL_CMGETAPI( "OpcUaQualifiedNameCompare" ) 
	#define CAL_OpcUaQualifiedNameCompare  OpcUaQualifiedNameCompare
	#define CHK_OpcUaQualifiedNameCompare  TRUE
	#define EXP_OpcUaQualifiedNameCompare  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaQualifiedNameCompare", (RTS_UINTPTR)OpcUaQualifiedNameCompare, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaQualifiedNameCompare
	#define EXT_CmpOPCUAStackOpcUaQualifiedNameCompare
	#define GET_CmpOPCUAStackOpcUaQualifiedNameCompare  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaQualifiedNameCompare pICmpOPCUAStack->IOpcUaQualifiedNameCompare
	#define CHK_CmpOPCUAStackOpcUaQualifiedNameCompare (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaQualifiedNameCompare  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaQualifiedNameCompare
	#define EXT_OpcUaQualifiedNameCompare
	#define GET_OpcUaQualifiedNameCompare(fl)  CAL_CMGETAPI( "OpcUaQualifiedNameCompare" ) 
	#define CAL_OpcUaQualifiedNameCompare pICmpOPCUAStack->IOpcUaQualifiedNameCompare
	#define CHK_OpcUaQualifiedNameCompare (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaQualifiedNameCompare  CAL_CMEXPAPI( "OpcUaQualifiedNameCompare" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaQualifiedNameCompare  PFOPCUAQUALIFIEDNAMECOMPARE pfOpcUaQualifiedNameCompare;
	#define EXT_OpcUaQualifiedNameCompare  extern PFOPCUAQUALIFIEDNAMECOMPARE pfOpcUaQualifiedNameCompare;
	#define GET_OpcUaQualifiedNameCompare(fl)  s_pfCMGetAPI2( "OpcUaQualifiedNameCompare", (RTS_VOID_FCTPTR *)&pfOpcUaQualifiedNameCompare, (fl), 0, 0)
	#define CAL_OpcUaQualifiedNameCompare  pfOpcUaQualifiedNameCompare
	#define CHK_OpcUaQualifiedNameCompare  (pfOpcUaQualifiedNameCompare != NULL)
	#define EXP_OpcUaQualifiedNameCompare  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaQualifiedNameCompare", (RTS_UINTPTR)OpcUaQualifiedNameCompare, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaQualifiedNameCopyTo(const OpcUa_QualifiedName* pSource, OpcUa_QualifiedName* pDestination);
typedef OpcUa_StatusCode (CDECL * PFOPCUAQUALIFIEDNAMECOPYTO) (const OpcUa_QualifiedName* pSource, OpcUa_QualifiedName* pDestination);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAQUALIFIEDNAMECOPYTO_NOTIMPLEMENTED)
	#define USE_OpcUaQualifiedNameCopyTo
	#define EXT_OpcUaQualifiedNameCopyTo
	#define GET_OpcUaQualifiedNameCopyTo(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaQualifiedNameCopyTo(p0,p1)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaQualifiedNameCopyTo  FALSE
	#define EXP_OpcUaQualifiedNameCopyTo  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaQualifiedNameCopyTo
	#define EXT_OpcUaQualifiedNameCopyTo
	#define GET_OpcUaQualifiedNameCopyTo(fl)  CAL_CMGETAPI( "OpcUaQualifiedNameCopyTo" ) 
	#define CAL_OpcUaQualifiedNameCopyTo  OpcUaQualifiedNameCopyTo
	#define CHK_OpcUaQualifiedNameCopyTo  TRUE
	#define EXP_OpcUaQualifiedNameCopyTo  CAL_CMEXPAPI( "OpcUaQualifiedNameCopyTo" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaQualifiedNameCopyTo
	#define EXT_OpcUaQualifiedNameCopyTo
	#define GET_OpcUaQualifiedNameCopyTo(fl)  CAL_CMGETAPI( "OpcUaQualifiedNameCopyTo" ) 
	#define CAL_OpcUaQualifiedNameCopyTo  OpcUaQualifiedNameCopyTo
	#define CHK_OpcUaQualifiedNameCopyTo  TRUE
	#define EXP_OpcUaQualifiedNameCopyTo  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaQualifiedNameCopyTo", (RTS_UINTPTR)OpcUaQualifiedNameCopyTo, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaQualifiedNameCopyTo
	#define EXT_CmpOPCUAStackOpcUaQualifiedNameCopyTo
	#define GET_CmpOPCUAStackOpcUaQualifiedNameCopyTo  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaQualifiedNameCopyTo pICmpOPCUAStack->IOpcUaQualifiedNameCopyTo
	#define CHK_CmpOPCUAStackOpcUaQualifiedNameCopyTo (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaQualifiedNameCopyTo  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaQualifiedNameCopyTo
	#define EXT_OpcUaQualifiedNameCopyTo
	#define GET_OpcUaQualifiedNameCopyTo(fl)  CAL_CMGETAPI( "OpcUaQualifiedNameCopyTo" ) 
	#define CAL_OpcUaQualifiedNameCopyTo pICmpOPCUAStack->IOpcUaQualifiedNameCopyTo
	#define CHK_OpcUaQualifiedNameCopyTo (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaQualifiedNameCopyTo  CAL_CMEXPAPI( "OpcUaQualifiedNameCopyTo" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaQualifiedNameCopyTo  PFOPCUAQUALIFIEDNAMECOPYTO pfOpcUaQualifiedNameCopyTo;
	#define EXT_OpcUaQualifiedNameCopyTo  extern PFOPCUAQUALIFIEDNAMECOPYTO pfOpcUaQualifiedNameCopyTo;
	#define GET_OpcUaQualifiedNameCopyTo(fl)  s_pfCMGetAPI2( "OpcUaQualifiedNameCopyTo", (RTS_VOID_FCTPTR *)&pfOpcUaQualifiedNameCopyTo, (fl), 0, 0)
	#define CAL_OpcUaQualifiedNameCopyTo  pfOpcUaQualifiedNameCopyTo
	#define CHK_OpcUaQualifiedNameCopyTo  (pfOpcUaQualifiedNameCopyTo != NULL)
	#define EXP_OpcUaQualifiedNameCopyTo  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaQualifiedNameCopyTo", (RTS_UINTPTR)OpcUaQualifiedNameCopyTo, 0, 0) 
#endif




OpcUa_StatusCode CDECL OpcUaStringAttachCopy(OpcUa_String* pDst, const OpcUa_CharA* pSrc);
typedef OpcUa_StatusCode (CDECL * PFOPCUASTRINGATTACHCOPY) (OpcUa_String* pDst, const OpcUa_CharA* pSrc);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASTRINGATTACHCOPY_NOTIMPLEMENTED)
	#define USE_OpcUaStringAttachCopy
	#define EXT_OpcUaStringAttachCopy
	#define GET_OpcUaStringAttachCopy(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaStringAttachCopy(p0,p1)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaStringAttachCopy  FALSE
	#define EXP_OpcUaStringAttachCopy  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaStringAttachCopy
	#define EXT_OpcUaStringAttachCopy
	#define GET_OpcUaStringAttachCopy(fl)  CAL_CMGETAPI( "OpcUaStringAttachCopy" ) 
	#define CAL_OpcUaStringAttachCopy  OpcUaStringAttachCopy
	#define CHK_OpcUaStringAttachCopy  TRUE
	#define EXP_OpcUaStringAttachCopy  CAL_CMEXPAPI( "OpcUaStringAttachCopy" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaStringAttachCopy
	#define EXT_OpcUaStringAttachCopy
	#define GET_OpcUaStringAttachCopy(fl)  CAL_CMGETAPI( "OpcUaStringAttachCopy" ) 
	#define CAL_OpcUaStringAttachCopy  OpcUaStringAttachCopy
	#define CHK_OpcUaStringAttachCopy  TRUE
	#define EXP_OpcUaStringAttachCopy  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStringAttachCopy", (RTS_UINTPTR)OpcUaStringAttachCopy, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaStringAttachCopy
	#define EXT_CmpOPCUAStackOpcUaStringAttachCopy
	#define GET_CmpOPCUAStackOpcUaStringAttachCopy  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaStringAttachCopy pICmpOPCUAStack->IOpcUaStringAttachCopy
	#define CHK_CmpOPCUAStackOpcUaStringAttachCopy (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaStringAttachCopy  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaStringAttachCopy
	#define EXT_OpcUaStringAttachCopy
	#define GET_OpcUaStringAttachCopy(fl)  CAL_CMGETAPI( "OpcUaStringAttachCopy" ) 
	#define CAL_OpcUaStringAttachCopy pICmpOPCUAStack->IOpcUaStringAttachCopy
	#define CHK_OpcUaStringAttachCopy (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaStringAttachCopy  CAL_CMEXPAPI( "OpcUaStringAttachCopy" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaStringAttachCopy  PFOPCUASTRINGATTACHCOPY pfOpcUaStringAttachCopy;
	#define EXT_OpcUaStringAttachCopy  extern PFOPCUASTRINGATTACHCOPY pfOpcUaStringAttachCopy;
	#define GET_OpcUaStringAttachCopy(fl)  s_pfCMGetAPI2( "OpcUaStringAttachCopy", (RTS_VOID_FCTPTR *)&pfOpcUaStringAttachCopy, (fl), 0, 0)
	#define CAL_OpcUaStringAttachCopy  pfOpcUaStringAttachCopy
	#define CHK_OpcUaStringAttachCopy  (pfOpcUaStringAttachCopy != NULL)
	#define EXP_OpcUaStringAttachCopy  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStringAttachCopy", (RTS_UINTPTR)OpcUaStringAttachCopy, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaStringAttachReadOnly(OpcUa_String* a_pDst, const OpcUa_CharA* a_pSrc);
typedef OpcUa_StatusCode (CDECL * PFOPCUASTRINGATTACHREADONLY) (OpcUa_String* a_pDst, const OpcUa_CharA* a_pSrc);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASTRINGATTACHREADONLY_NOTIMPLEMENTED)
	#define USE_OpcUaStringAttachReadOnly
	#define EXT_OpcUaStringAttachReadOnly
	#define GET_OpcUaStringAttachReadOnly(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaStringAttachReadOnly(p0,p1)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaStringAttachReadOnly  FALSE
	#define EXP_OpcUaStringAttachReadOnly  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaStringAttachReadOnly
	#define EXT_OpcUaStringAttachReadOnly
	#define GET_OpcUaStringAttachReadOnly(fl)  CAL_CMGETAPI( "OpcUaStringAttachReadOnly" ) 
	#define CAL_OpcUaStringAttachReadOnly  OpcUaStringAttachReadOnly
	#define CHK_OpcUaStringAttachReadOnly  TRUE
	#define EXP_OpcUaStringAttachReadOnly  CAL_CMEXPAPI( "OpcUaStringAttachReadOnly" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaStringAttachReadOnly
	#define EXT_OpcUaStringAttachReadOnly
	#define GET_OpcUaStringAttachReadOnly(fl)  CAL_CMGETAPI( "OpcUaStringAttachReadOnly" ) 
	#define CAL_OpcUaStringAttachReadOnly  OpcUaStringAttachReadOnly
	#define CHK_OpcUaStringAttachReadOnly  TRUE
	#define EXP_OpcUaStringAttachReadOnly  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStringAttachReadOnly", (RTS_UINTPTR)OpcUaStringAttachReadOnly, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaStringAttachReadOnly
	#define EXT_CmpOPCUAStackOpcUaStringAttachReadOnly
	#define GET_CmpOPCUAStackOpcUaStringAttachReadOnly  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaStringAttachReadOnly pICmpOPCUAStack->IOpcUaStringAttachReadOnly
	#define CHK_CmpOPCUAStackOpcUaStringAttachReadOnly (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaStringAttachReadOnly  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaStringAttachReadOnly
	#define EXT_OpcUaStringAttachReadOnly
	#define GET_OpcUaStringAttachReadOnly(fl)  CAL_CMGETAPI( "OpcUaStringAttachReadOnly" ) 
	#define CAL_OpcUaStringAttachReadOnly pICmpOPCUAStack->IOpcUaStringAttachReadOnly
	#define CHK_OpcUaStringAttachReadOnly (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaStringAttachReadOnly  CAL_CMEXPAPI( "OpcUaStringAttachReadOnly" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaStringAttachReadOnly  PFOPCUASTRINGATTACHREADONLY pfOpcUaStringAttachReadOnly;
	#define EXT_OpcUaStringAttachReadOnly  extern PFOPCUASTRINGATTACHREADONLY pfOpcUaStringAttachReadOnly;
	#define GET_OpcUaStringAttachReadOnly(fl)  s_pfCMGetAPI2( "OpcUaStringAttachReadOnly", (RTS_VOID_FCTPTR *)&pfOpcUaStringAttachReadOnly, (fl), 0, 0)
	#define CAL_OpcUaStringAttachReadOnly  pfOpcUaStringAttachReadOnly
	#define CHK_OpcUaStringAttachReadOnly  (pfOpcUaStringAttachReadOnly != NULL)
	#define EXP_OpcUaStringAttachReadOnly  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStringAttachReadOnly", (RTS_UINTPTR)OpcUaStringAttachReadOnly, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaStringAttachToString(OpcUa_StringA strSource, OpcUa_UInt32  uLength, OpcUa_UInt32  uBufferSize, OpcUa_Boolean bDoCopy, OpcUa_Boolean bFreeOnClear, OpcUa_String* pString);
typedef OpcUa_StatusCode (CDECL * PFOPCUASTRINGATTACHTOSTRING) (OpcUa_StringA strSource, OpcUa_UInt32  uLength, OpcUa_UInt32  uBufferSize, OpcUa_Boolean bDoCopy, OpcUa_Boolean bFreeOnClear, OpcUa_String* pString);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASTRINGATTACHTOSTRING_NOTIMPLEMENTED)
	#define USE_OpcUaStringAttachToString
	#define EXT_OpcUaStringAttachToString
	#define GET_OpcUaStringAttachToString(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaStringAttachToString(p0,p1,p2,p3,p4,p5)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaStringAttachToString  FALSE
	#define EXP_OpcUaStringAttachToString  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaStringAttachToString
	#define EXT_OpcUaStringAttachToString
	#define GET_OpcUaStringAttachToString(fl)  CAL_CMGETAPI( "OpcUaStringAttachToString" ) 
	#define CAL_OpcUaStringAttachToString  OpcUaStringAttachToString
	#define CHK_OpcUaStringAttachToString  TRUE
	#define EXP_OpcUaStringAttachToString  CAL_CMEXPAPI( "OpcUaStringAttachToString" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaStringAttachToString
	#define EXT_OpcUaStringAttachToString
	#define GET_OpcUaStringAttachToString(fl)  CAL_CMGETAPI( "OpcUaStringAttachToString" ) 
	#define CAL_OpcUaStringAttachToString  OpcUaStringAttachToString
	#define CHK_OpcUaStringAttachToString  TRUE
	#define EXP_OpcUaStringAttachToString  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStringAttachToString", (RTS_UINTPTR)OpcUaStringAttachToString, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaStringAttachToString
	#define EXT_CmpOPCUAStackOpcUaStringAttachToString
	#define GET_CmpOPCUAStackOpcUaStringAttachToString  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaStringAttachToString pICmpOPCUAStack->IOpcUaStringAttachToString
	#define CHK_CmpOPCUAStackOpcUaStringAttachToString (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaStringAttachToString  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaStringAttachToString
	#define EXT_OpcUaStringAttachToString
	#define GET_OpcUaStringAttachToString(fl)  CAL_CMGETAPI( "OpcUaStringAttachToString" ) 
	#define CAL_OpcUaStringAttachToString pICmpOPCUAStack->IOpcUaStringAttachToString
	#define CHK_OpcUaStringAttachToString (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaStringAttachToString  CAL_CMEXPAPI( "OpcUaStringAttachToString" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaStringAttachToString  PFOPCUASTRINGATTACHTOSTRING pfOpcUaStringAttachToString;
	#define EXT_OpcUaStringAttachToString  extern PFOPCUASTRINGATTACHTOSTRING pfOpcUaStringAttachToString;
	#define GET_OpcUaStringAttachToString(fl)  s_pfCMGetAPI2( "OpcUaStringAttachToString", (RTS_VOID_FCTPTR *)&pfOpcUaStringAttachToString, (fl), 0, 0)
	#define CAL_OpcUaStringAttachToString  pfOpcUaStringAttachToString
	#define CHK_OpcUaStringAttachToString  (pfOpcUaStringAttachToString != NULL)
	#define EXP_OpcUaStringAttachToString  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStringAttachToString", (RTS_UINTPTR)OpcUaStringAttachToString, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaStringClear(OpcUa_String* pString);
typedef OpcUa_Void (CDECL * PFOPCUASTRINGCLEAR) (OpcUa_String* pString);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASTRINGCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaStringClear
	#define EXT_OpcUaStringClear
	#define GET_OpcUaStringClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaStringClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaStringClear  FALSE
	#define EXP_OpcUaStringClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaStringClear
	#define EXT_OpcUaStringClear
	#define GET_OpcUaStringClear(fl)  CAL_CMGETAPI( "OpcUaStringClear" ) 
	#define CAL_OpcUaStringClear  OpcUaStringClear
	#define CHK_OpcUaStringClear  TRUE
	#define EXP_OpcUaStringClear  CAL_CMEXPAPI( "OpcUaStringClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaStringClear
	#define EXT_OpcUaStringClear
	#define GET_OpcUaStringClear(fl)  CAL_CMGETAPI( "OpcUaStringClear" ) 
	#define CAL_OpcUaStringClear  OpcUaStringClear
	#define CHK_OpcUaStringClear  TRUE
	#define EXP_OpcUaStringClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStringClear", (RTS_UINTPTR)OpcUaStringClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaStringClear
	#define EXT_CmpOPCUAStackOpcUaStringClear
	#define GET_CmpOPCUAStackOpcUaStringClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaStringClear pICmpOPCUAStack->IOpcUaStringClear
	#define CHK_CmpOPCUAStackOpcUaStringClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaStringClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaStringClear
	#define EXT_OpcUaStringClear
	#define GET_OpcUaStringClear(fl)  CAL_CMGETAPI( "OpcUaStringClear" ) 
	#define CAL_OpcUaStringClear pICmpOPCUAStack->IOpcUaStringClear
	#define CHK_OpcUaStringClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaStringClear  CAL_CMEXPAPI( "OpcUaStringClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaStringClear  PFOPCUASTRINGCLEAR pfOpcUaStringClear;
	#define EXT_OpcUaStringClear  extern PFOPCUASTRINGCLEAR pfOpcUaStringClear;
	#define GET_OpcUaStringClear(fl)  s_pfCMGetAPI2( "OpcUaStringClear", (RTS_VOID_FCTPTR *)&pfOpcUaStringClear, (fl), 0, 0)
	#define CAL_OpcUaStringClear  pfOpcUaStringClear
	#define CHK_OpcUaStringClear  (pfOpcUaStringClear != NULL)
	#define EXP_OpcUaStringClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStringClear", (RTS_UINTPTR)OpcUaStringClear, 0, 0) 
#endif



OpcUa_CharA* CDECL OpcUaStringGetRawString(const OpcUa_String* pString);
typedef OpcUa_CharA* (CDECL * PFOPCUASTRINGGETRAWSTRING) (const OpcUa_String* pString);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASTRINGGETRAWSTRING_NOTIMPLEMENTED)
	#define USE_OpcUaStringGetRawString
	#define EXT_OpcUaStringGetRawString
	#define GET_OpcUaStringGetRawString(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaStringGetRawString(p0)  (OpcUa_CharA*)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaStringGetRawString  FALSE
	#define EXP_OpcUaStringGetRawString  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaStringGetRawString
	#define EXT_OpcUaStringGetRawString
	#define GET_OpcUaStringGetRawString(fl)  CAL_CMGETAPI( "OpcUaStringGetRawString" ) 
	#define CAL_OpcUaStringGetRawString  OpcUaStringGetRawString
	#define CHK_OpcUaStringGetRawString  TRUE
	#define EXP_OpcUaStringGetRawString  CAL_CMEXPAPI( "OpcUaStringGetRawString" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaStringGetRawString
	#define EXT_OpcUaStringGetRawString
	#define GET_OpcUaStringGetRawString(fl)  CAL_CMGETAPI( "OpcUaStringGetRawString" ) 
	#define CAL_OpcUaStringGetRawString  OpcUaStringGetRawString
	#define CHK_OpcUaStringGetRawString  TRUE
	#define EXP_OpcUaStringGetRawString  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStringGetRawString", (RTS_UINTPTR)OpcUaStringGetRawString, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaStringGetRawString
	#define EXT_CmpOPCUAStackOpcUaStringGetRawString
	#define GET_CmpOPCUAStackOpcUaStringGetRawString  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaStringGetRawString pICmpOPCUAStack->IOpcUaStringGetRawString
	#define CHK_CmpOPCUAStackOpcUaStringGetRawString (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaStringGetRawString  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaStringGetRawString
	#define EXT_OpcUaStringGetRawString
	#define GET_OpcUaStringGetRawString(fl)  CAL_CMGETAPI( "OpcUaStringGetRawString" ) 
	#define CAL_OpcUaStringGetRawString pICmpOPCUAStack->IOpcUaStringGetRawString
	#define CHK_OpcUaStringGetRawString (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaStringGetRawString  CAL_CMEXPAPI( "OpcUaStringGetRawString" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaStringGetRawString  PFOPCUASTRINGGETRAWSTRING pfOpcUaStringGetRawString;
	#define EXT_OpcUaStringGetRawString  extern PFOPCUASTRINGGETRAWSTRING pfOpcUaStringGetRawString;
	#define GET_OpcUaStringGetRawString(fl)  s_pfCMGetAPI2( "OpcUaStringGetRawString", (RTS_VOID_FCTPTR *)&pfOpcUaStringGetRawString, (fl), 0, 0)
	#define CAL_OpcUaStringGetRawString  pfOpcUaStringGetRawString
	#define CHK_OpcUaStringGetRawString  (pfOpcUaStringGetRawString != NULL)
	#define EXP_OpcUaStringGetRawString  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStringGetRawString", (RTS_UINTPTR)OpcUaStringGetRawString, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaStringInitialize(OpcUa_String* pString);
typedef OpcUa_Void (CDECL * PFOPCUASTRINGINITIALIZE) (OpcUa_String* pString);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASTRINGINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaStringInitialize
	#define EXT_OpcUaStringInitialize
	#define GET_OpcUaStringInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaStringInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaStringInitialize  FALSE
	#define EXP_OpcUaStringInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaStringInitialize
	#define EXT_OpcUaStringInitialize
	#define GET_OpcUaStringInitialize(fl)  CAL_CMGETAPI( "OpcUaStringInitialize" ) 
	#define CAL_OpcUaStringInitialize  OpcUaStringInitialize
	#define CHK_OpcUaStringInitialize  TRUE
	#define EXP_OpcUaStringInitialize  CAL_CMEXPAPI( "OpcUaStringInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaStringInitialize
	#define EXT_OpcUaStringInitialize
	#define GET_OpcUaStringInitialize(fl)  CAL_CMGETAPI( "OpcUaStringInitialize" ) 
	#define CAL_OpcUaStringInitialize  OpcUaStringInitialize
	#define CHK_OpcUaStringInitialize  TRUE
	#define EXP_OpcUaStringInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStringInitialize", (RTS_UINTPTR)OpcUaStringInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaStringInitialize
	#define EXT_CmpOPCUAStackOpcUaStringInitialize
	#define GET_CmpOPCUAStackOpcUaStringInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaStringInitialize pICmpOPCUAStack->IOpcUaStringInitialize
	#define CHK_CmpOPCUAStackOpcUaStringInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaStringInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaStringInitialize
	#define EXT_OpcUaStringInitialize
	#define GET_OpcUaStringInitialize(fl)  CAL_CMGETAPI( "OpcUaStringInitialize" ) 
	#define CAL_OpcUaStringInitialize pICmpOPCUAStack->IOpcUaStringInitialize
	#define CHK_OpcUaStringInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaStringInitialize  CAL_CMEXPAPI( "OpcUaStringInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaStringInitialize  PFOPCUASTRINGINITIALIZE pfOpcUaStringInitialize;
	#define EXT_OpcUaStringInitialize  extern PFOPCUASTRINGINITIALIZE pfOpcUaStringInitialize;
	#define GET_OpcUaStringInitialize(fl)  s_pfCMGetAPI2( "OpcUaStringInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaStringInitialize, (fl), 0, 0)
	#define CAL_OpcUaStringInitialize  pfOpcUaStringInitialize
	#define CHK_OpcUaStringInitialize  (pfOpcUaStringInitialize != NULL)
	#define EXP_OpcUaStringInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStringInitialize", (RTS_UINTPTR)OpcUaStringInitialize, 0, 0) 
#endif



OpcUa_Boolean CDECL OpcUaStringIsEmpty(const OpcUa_String* pString);
typedef OpcUa_Boolean (CDECL * PFOPCUASTRINGISEMPTY) (const OpcUa_String* pString);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASTRINGISEMPTY_NOTIMPLEMENTED)
	#define USE_OpcUaStringIsEmpty
	#define EXT_OpcUaStringIsEmpty
	#define GET_OpcUaStringIsEmpty(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaStringIsEmpty(p0)  (OpcUa_Boolean)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaStringIsEmpty  FALSE
	#define EXP_OpcUaStringIsEmpty  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaStringIsEmpty
	#define EXT_OpcUaStringIsEmpty
	#define GET_OpcUaStringIsEmpty(fl)  CAL_CMGETAPI( "OpcUaStringIsEmpty" ) 
	#define CAL_OpcUaStringIsEmpty  OpcUaStringIsEmpty
	#define CHK_OpcUaStringIsEmpty  TRUE
	#define EXP_OpcUaStringIsEmpty  CAL_CMEXPAPI( "OpcUaStringIsEmpty" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaStringIsEmpty
	#define EXT_OpcUaStringIsEmpty
	#define GET_OpcUaStringIsEmpty(fl)  CAL_CMGETAPI( "OpcUaStringIsEmpty" ) 
	#define CAL_OpcUaStringIsEmpty  OpcUaStringIsEmpty
	#define CHK_OpcUaStringIsEmpty  TRUE
	#define EXP_OpcUaStringIsEmpty  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStringIsEmpty", (RTS_UINTPTR)OpcUaStringIsEmpty, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaStringIsEmpty
	#define EXT_CmpOPCUAStackOpcUaStringIsEmpty
	#define GET_CmpOPCUAStackOpcUaStringIsEmpty  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaStringIsEmpty pICmpOPCUAStack->IOpcUaStringIsEmpty
	#define CHK_CmpOPCUAStackOpcUaStringIsEmpty (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaStringIsEmpty  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaStringIsEmpty
	#define EXT_OpcUaStringIsEmpty
	#define GET_OpcUaStringIsEmpty(fl)  CAL_CMGETAPI( "OpcUaStringIsEmpty" ) 
	#define CAL_OpcUaStringIsEmpty pICmpOPCUAStack->IOpcUaStringIsEmpty
	#define CHK_OpcUaStringIsEmpty (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaStringIsEmpty  CAL_CMEXPAPI( "OpcUaStringIsEmpty" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaStringIsEmpty  PFOPCUASTRINGISEMPTY pfOpcUaStringIsEmpty;
	#define EXT_OpcUaStringIsEmpty  extern PFOPCUASTRINGISEMPTY pfOpcUaStringIsEmpty;
	#define GET_OpcUaStringIsEmpty(fl)  s_pfCMGetAPI2( "OpcUaStringIsEmpty", (RTS_VOID_FCTPTR *)&pfOpcUaStringIsEmpty, (fl), 0, 0)
	#define CAL_OpcUaStringIsEmpty  pfOpcUaStringIsEmpty
	#define CHK_OpcUaStringIsEmpty  (pfOpcUaStringIsEmpty != NULL)
	#define EXP_OpcUaStringIsEmpty  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStringIsEmpty", (RTS_UINTPTR)OpcUaStringIsEmpty, 0, 0) 
#endif



OpcUa_Boolean CDECL OpcUaStringIsNull(const OpcUa_String* pString);
typedef OpcUa_Boolean (CDECL * PFOPCUASTRINGISNULL) (const OpcUa_String* pString);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASTRINGISNULL_NOTIMPLEMENTED)
	#define USE_OpcUaStringIsNull
	#define EXT_OpcUaStringIsNull
	#define GET_OpcUaStringIsNull(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaStringIsNull(p0)  (OpcUa_Boolean)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaStringIsNull  FALSE
	#define EXP_OpcUaStringIsNull  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaStringIsNull
	#define EXT_OpcUaStringIsNull
	#define GET_OpcUaStringIsNull(fl)  CAL_CMGETAPI( "OpcUaStringIsNull" ) 
	#define CAL_OpcUaStringIsNull  OpcUaStringIsNull
	#define CHK_OpcUaStringIsNull  TRUE
	#define EXP_OpcUaStringIsNull  CAL_CMEXPAPI( "OpcUaStringIsNull" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaStringIsNull
	#define EXT_OpcUaStringIsNull
	#define GET_OpcUaStringIsNull(fl)  CAL_CMGETAPI( "OpcUaStringIsNull" ) 
	#define CAL_OpcUaStringIsNull  OpcUaStringIsNull
	#define CHK_OpcUaStringIsNull  TRUE
	#define EXP_OpcUaStringIsNull  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStringIsNull", (RTS_UINTPTR)OpcUaStringIsNull, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaStringIsNull
	#define EXT_CmpOPCUAStackOpcUaStringIsNull
	#define GET_CmpOPCUAStackOpcUaStringIsNull  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaStringIsNull pICmpOPCUAStack->IOpcUaStringIsNull
	#define CHK_CmpOPCUAStackOpcUaStringIsNull (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaStringIsNull  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaStringIsNull
	#define EXT_OpcUaStringIsNull
	#define GET_OpcUaStringIsNull(fl)  CAL_CMGETAPI( "OpcUaStringIsNull" ) 
	#define CAL_OpcUaStringIsNull pICmpOPCUAStack->IOpcUaStringIsNull
	#define CHK_OpcUaStringIsNull (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaStringIsNull  CAL_CMEXPAPI( "OpcUaStringIsNull" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaStringIsNull  PFOPCUASTRINGISNULL pfOpcUaStringIsNull;
	#define EXT_OpcUaStringIsNull  extern PFOPCUASTRINGISNULL pfOpcUaStringIsNull;
	#define GET_OpcUaStringIsNull(fl)  s_pfCMGetAPI2( "OpcUaStringIsNull", (RTS_VOID_FCTPTR *)&pfOpcUaStringIsNull, (fl), 0, 0)
	#define CAL_OpcUaStringIsNull  pfOpcUaStringIsNull
	#define CHK_OpcUaStringIsNull  (pfOpcUaStringIsNull != NULL)
	#define EXP_OpcUaStringIsNull  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStringIsNull", (RTS_UINTPTR)OpcUaStringIsNull, 0, 0) 
#endif



OpcUa_UInt32 CDECL OpcUaStringStrLen(const OpcUa_String* pString);
typedef OpcUa_UInt32 (CDECL * PFOPCUASTRINGSTRLEN) (const OpcUa_String* pString);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASTRINGSTRLEN_NOTIMPLEMENTED)
	#define USE_OpcUaStringStrLen
	#define EXT_OpcUaStringStrLen
	#define GET_OpcUaStringStrLen(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaStringStrLen(p0)  (OpcUa_UInt32)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaStringStrLen  FALSE
	#define EXP_OpcUaStringStrLen  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaStringStrLen
	#define EXT_OpcUaStringStrLen
	#define GET_OpcUaStringStrLen(fl)  CAL_CMGETAPI( "OpcUaStringStrLen" ) 
	#define CAL_OpcUaStringStrLen  OpcUaStringStrLen
	#define CHK_OpcUaStringStrLen  TRUE
	#define EXP_OpcUaStringStrLen  CAL_CMEXPAPI( "OpcUaStringStrLen" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaStringStrLen
	#define EXT_OpcUaStringStrLen
	#define GET_OpcUaStringStrLen(fl)  CAL_CMGETAPI( "OpcUaStringStrLen" ) 
	#define CAL_OpcUaStringStrLen  OpcUaStringStrLen
	#define CHK_OpcUaStringStrLen  TRUE
	#define EXP_OpcUaStringStrLen  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStringStrLen", (RTS_UINTPTR)OpcUaStringStrLen, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaStringStrLen
	#define EXT_CmpOPCUAStackOpcUaStringStrLen
	#define GET_CmpOPCUAStackOpcUaStringStrLen  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaStringStrLen pICmpOPCUAStack->IOpcUaStringStrLen
	#define CHK_CmpOPCUAStackOpcUaStringStrLen (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaStringStrLen  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaStringStrLen
	#define EXT_OpcUaStringStrLen
	#define GET_OpcUaStringStrLen(fl)  CAL_CMGETAPI( "OpcUaStringStrLen" ) 
	#define CAL_OpcUaStringStrLen pICmpOPCUAStack->IOpcUaStringStrLen
	#define CHK_OpcUaStringStrLen (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaStringStrLen  CAL_CMEXPAPI( "OpcUaStringStrLen" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaStringStrLen  PFOPCUASTRINGSTRLEN pfOpcUaStringStrLen;
	#define EXT_OpcUaStringStrLen  extern PFOPCUASTRINGSTRLEN pfOpcUaStringStrLen;
	#define GET_OpcUaStringStrLen(fl)  s_pfCMGetAPI2( "OpcUaStringStrLen", (RTS_VOID_FCTPTR *)&pfOpcUaStringStrLen, (fl), 0, 0)
	#define CAL_OpcUaStringStrLen  pfOpcUaStringStrLen
	#define CHK_OpcUaStringStrLen  (pfOpcUaStringStrLen != NULL)
	#define EXP_OpcUaStringStrLen  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStringStrLen", (RTS_UINTPTR)OpcUaStringStrLen, 0, 0) 
#endif



OpcUa_UInt32 CDECL OpcUaStringStrSize(const OpcUa_String* pString);
typedef OpcUa_UInt32 (CDECL * PFOPCUASTRINGSTRSIZE) (const OpcUa_String* pString);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASTRINGSTRSIZE_NOTIMPLEMENTED)
	#define USE_OpcUaStringStrSize
	#define EXT_OpcUaStringStrSize
	#define GET_OpcUaStringStrSize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaStringStrSize(p0)  (OpcUa_UInt32)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaStringStrSize  FALSE
	#define EXP_OpcUaStringStrSize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaStringStrSize
	#define EXT_OpcUaStringStrSize
	#define GET_OpcUaStringStrSize(fl)  CAL_CMGETAPI( "OpcUaStringStrSize" ) 
	#define CAL_OpcUaStringStrSize  OpcUaStringStrSize
	#define CHK_OpcUaStringStrSize  TRUE
	#define EXP_OpcUaStringStrSize  CAL_CMEXPAPI( "OpcUaStringStrSize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaStringStrSize
	#define EXT_OpcUaStringStrSize
	#define GET_OpcUaStringStrSize(fl)  CAL_CMGETAPI( "OpcUaStringStrSize" ) 
	#define CAL_OpcUaStringStrSize  OpcUaStringStrSize
	#define CHK_OpcUaStringStrSize  TRUE
	#define EXP_OpcUaStringStrSize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStringStrSize", (RTS_UINTPTR)OpcUaStringStrSize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaStringStrSize
	#define EXT_CmpOPCUAStackOpcUaStringStrSize
	#define GET_CmpOPCUAStackOpcUaStringStrSize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaStringStrSize pICmpOPCUAStack->IOpcUaStringStrSize
	#define CHK_CmpOPCUAStackOpcUaStringStrSize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaStringStrSize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaStringStrSize
	#define EXT_OpcUaStringStrSize
	#define GET_OpcUaStringStrSize(fl)  CAL_CMGETAPI( "OpcUaStringStrSize" ) 
	#define CAL_OpcUaStringStrSize pICmpOPCUAStack->IOpcUaStringStrSize
	#define CHK_OpcUaStringStrSize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaStringStrSize  CAL_CMEXPAPI( "OpcUaStringStrSize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaStringStrSize  PFOPCUASTRINGSTRSIZE pfOpcUaStringStrSize;
	#define EXT_OpcUaStringStrSize  extern PFOPCUASTRINGSTRSIZE pfOpcUaStringStrSize;
	#define GET_OpcUaStringStrSize(fl)  s_pfCMGetAPI2( "OpcUaStringStrSize", (RTS_VOID_FCTPTR *)&pfOpcUaStringStrSize, (fl), 0, 0)
	#define CAL_OpcUaStringStrSize  pfOpcUaStringStrSize
	#define CHK_OpcUaStringStrSize  (pfOpcUaStringStrSize != NULL)
	#define EXP_OpcUaStringStrSize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStringStrSize", (RTS_UINTPTR)OpcUaStringStrSize, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaStringStrnCat(OpcUa_String* pDestString, const OpcUa_String* pSrcString, OpcUa_UInt32 uLength);
typedef OpcUa_StatusCode (CDECL * PFOPCUASTRINGSTRNCAT) (OpcUa_String* pDestString, const OpcUa_String* pSrcString, OpcUa_UInt32 uLength);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASTRINGSTRNCAT_NOTIMPLEMENTED)
	#define USE_OpcUaStringStrnCat
	#define EXT_OpcUaStringStrnCat
	#define GET_OpcUaStringStrnCat(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaStringStrnCat(p0,p1,p2)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaStringStrnCat  FALSE
	#define EXP_OpcUaStringStrnCat  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaStringStrnCat
	#define EXT_OpcUaStringStrnCat
	#define GET_OpcUaStringStrnCat(fl)  CAL_CMGETAPI( "OpcUaStringStrnCat" ) 
	#define CAL_OpcUaStringStrnCat  OpcUaStringStrnCat
	#define CHK_OpcUaStringStrnCat  TRUE
	#define EXP_OpcUaStringStrnCat  CAL_CMEXPAPI( "OpcUaStringStrnCat" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaStringStrnCat
	#define EXT_OpcUaStringStrnCat
	#define GET_OpcUaStringStrnCat(fl)  CAL_CMGETAPI( "OpcUaStringStrnCat" ) 
	#define CAL_OpcUaStringStrnCat  OpcUaStringStrnCat
	#define CHK_OpcUaStringStrnCat  TRUE
	#define EXP_OpcUaStringStrnCat  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStringStrnCat", (RTS_UINTPTR)OpcUaStringStrnCat, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaStringStrnCat
	#define EXT_CmpOPCUAStackOpcUaStringStrnCat
	#define GET_CmpOPCUAStackOpcUaStringStrnCat  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaStringStrnCat pICmpOPCUAStack->IOpcUaStringStrnCat
	#define CHK_CmpOPCUAStackOpcUaStringStrnCat (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaStringStrnCat  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaStringStrnCat
	#define EXT_OpcUaStringStrnCat
	#define GET_OpcUaStringStrnCat(fl)  CAL_CMGETAPI( "OpcUaStringStrnCat" ) 
	#define CAL_OpcUaStringStrnCat pICmpOPCUAStack->IOpcUaStringStrnCat
	#define CHK_OpcUaStringStrnCat (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaStringStrnCat  CAL_CMEXPAPI( "OpcUaStringStrnCat" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaStringStrnCat  PFOPCUASTRINGSTRNCAT pfOpcUaStringStrnCat;
	#define EXT_OpcUaStringStrnCat  extern PFOPCUASTRINGSTRNCAT pfOpcUaStringStrnCat;
	#define GET_OpcUaStringStrnCat(fl)  s_pfCMGetAPI2( "OpcUaStringStrnCat", (RTS_VOID_FCTPTR *)&pfOpcUaStringStrnCat, (fl), 0, 0)
	#define CAL_OpcUaStringStrnCat  pfOpcUaStringStrnCat
	#define CHK_OpcUaStringStrnCat  (pfOpcUaStringStrnCat != NULL)
	#define EXP_OpcUaStringStrnCat  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStringStrnCat", (RTS_UINTPTR)OpcUaStringStrnCat, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaStringStrnCpy(OpcUa_String* pDestString, const OpcUa_String* pSrcString, OpcUa_UInt32 uLength);
typedef OpcUa_StatusCode (CDECL * PFOPCUASTRINGSTRNCPY) (OpcUa_String* pDestString, const OpcUa_String* pSrcString, OpcUa_UInt32 uLength);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASTRINGSTRNCPY_NOTIMPLEMENTED)
	#define USE_OpcUaStringStrnCpy
	#define EXT_OpcUaStringStrnCpy
	#define GET_OpcUaStringStrnCpy(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaStringStrnCpy(p0,p1,p2)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaStringStrnCpy  FALSE
	#define EXP_OpcUaStringStrnCpy  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaStringStrnCpy
	#define EXT_OpcUaStringStrnCpy
	#define GET_OpcUaStringStrnCpy(fl)  CAL_CMGETAPI( "OpcUaStringStrnCpy" ) 
	#define CAL_OpcUaStringStrnCpy  OpcUaStringStrnCpy
	#define CHK_OpcUaStringStrnCpy  TRUE
	#define EXP_OpcUaStringStrnCpy  CAL_CMEXPAPI( "OpcUaStringStrnCpy" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaStringStrnCpy
	#define EXT_OpcUaStringStrnCpy
	#define GET_OpcUaStringStrnCpy(fl)  CAL_CMGETAPI( "OpcUaStringStrnCpy" ) 
	#define CAL_OpcUaStringStrnCpy  OpcUaStringStrnCpy
	#define CHK_OpcUaStringStrnCpy  TRUE
	#define EXP_OpcUaStringStrnCpy  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStringStrnCpy", (RTS_UINTPTR)OpcUaStringStrnCpy, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaStringStrnCpy
	#define EXT_CmpOPCUAStackOpcUaStringStrnCpy
	#define GET_CmpOPCUAStackOpcUaStringStrnCpy  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaStringStrnCpy pICmpOPCUAStack->IOpcUaStringStrnCpy
	#define CHK_CmpOPCUAStackOpcUaStringStrnCpy (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaStringStrnCpy  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaStringStrnCpy
	#define EXT_OpcUaStringStrnCpy
	#define GET_OpcUaStringStrnCpy(fl)  CAL_CMGETAPI( "OpcUaStringStrnCpy" ) 
	#define CAL_OpcUaStringStrnCpy pICmpOPCUAStack->IOpcUaStringStrnCpy
	#define CHK_OpcUaStringStrnCpy (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaStringStrnCpy  CAL_CMEXPAPI( "OpcUaStringStrnCpy" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaStringStrnCpy  PFOPCUASTRINGSTRNCPY pfOpcUaStringStrnCpy;
	#define EXT_OpcUaStringStrnCpy  extern PFOPCUASTRINGSTRNCPY pfOpcUaStringStrnCpy;
	#define GET_OpcUaStringStrnCpy(fl)  s_pfCMGetAPI2( "OpcUaStringStrnCpy", (RTS_VOID_FCTPTR *)&pfOpcUaStringStrnCpy, (fl), 0, 0)
	#define CAL_OpcUaStringStrnCpy  pfOpcUaStringStrnCpy
	#define CHK_OpcUaStringStrnCpy  (pfOpcUaStringStrnCpy != NULL)
	#define EXP_OpcUaStringStrnCpy  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStringStrnCpy", (RTS_UINTPTR)OpcUaStringStrnCpy, 0, 0) 
#endif



OpcUa_Int32 CDECL OpcUaStringStrnCmp(const OpcUa_String* a_pLeftString, const OpcUa_String* a_pRightString,OpcUa_UInt32 a_uLength, OpcUa_Boolean a_bIgnoreCase);
typedef OpcUa_Int32 (CDECL * PFOPCUASTRINGSTRNCMP) (const OpcUa_String* a_pLeftString, const OpcUa_String* a_pRightString,OpcUa_UInt32 a_uLength, OpcUa_Boolean a_bIgnoreCase);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASTRINGSTRNCMP_NOTIMPLEMENTED)
	#define USE_OpcUaStringStrnCmp
	#define EXT_OpcUaStringStrnCmp
	#define GET_OpcUaStringStrnCmp(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaStringStrnCmp(p0,p1,p2,p3)  (OpcUa_Int32)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaStringStrnCmp  FALSE
	#define EXP_OpcUaStringStrnCmp  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaStringStrnCmp
	#define EXT_OpcUaStringStrnCmp
	#define GET_OpcUaStringStrnCmp(fl)  CAL_CMGETAPI( "OpcUaStringStrnCmp" ) 
	#define CAL_OpcUaStringStrnCmp  OpcUaStringStrnCmp
	#define CHK_OpcUaStringStrnCmp  TRUE
	#define EXP_OpcUaStringStrnCmp  CAL_CMEXPAPI( "OpcUaStringStrnCmp" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaStringStrnCmp
	#define EXT_OpcUaStringStrnCmp
	#define GET_OpcUaStringStrnCmp(fl)  CAL_CMGETAPI( "OpcUaStringStrnCmp" ) 
	#define CAL_OpcUaStringStrnCmp  OpcUaStringStrnCmp
	#define CHK_OpcUaStringStrnCmp  TRUE
	#define EXP_OpcUaStringStrnCmp  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStringStrnCmp", (RTS_UINTPTR)OpcUaStringStrnCmp, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaStringStrnCmp
	#define EXT_CmpOPCUAStackOpcUaStringStrnCmp
	#define GET_CmpOPCUAStackOpcUaStringStrnCmp  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaStringStrnCmp pICmpOPCUAStack->IOpcUaStringStrnCmp
	#define CHK_CmpOPCUAStackOpcUaStringStrnCmp (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaStringStrnCmp  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaStringStrnCmp
	#define EXT_OpcUaStringStrnCmp
	#define GET_OpcUaStringStrnCmp(fl)  CAL_CMGETAPI( "OpcUaStringStrnCmp" ) 
	#define CAL_OpcUaStringStrnCmp pICmpOPCUAStack->IOpcUaStringStrnCmp
	#define CHK_OpcUaStringStrnCmp (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaStringStrnCmp  CAL_CMEXPAPI( "OpcUaStringStrnCmp" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaStringStrnCmp  PFOPCUASTRINGSTRNCMP pfOpcUaStringStrnCmp;
	#define EXT_OpcUaStringStrnCmp  extern PFOPCUASTRINGSTRNCMP pfOpcUaStringStrnCmp;
	#define GET_OpcUaStringStrnCmp(fl)  s_pfCMGetAPI2( "OpcUaStringStrnCmp", (RTS_VOID_FCTPTR *)&pfOpcUaStringStrnCmp, (fl), 0, 0)
	#define CAL_OpcUaStringStrnCmp  pfOpcUaStringStrnCmp
	#define CHK_OpcUaStringStrnCmp  (pfOpcUaStringStrnCmp != NULL)
	#define EXP_OpcUaStringStrnCmp  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStringStrnCmp", (RTS_UINTPTR)OpcUaStringStrnCmp, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaVariantInitialize(OpcUa_Variant* value);
typedef OpcUa_Void (CDECL * PFOPCUAVARIANTINITIALIZE) (OpcUa_Variant* value);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAVARIANTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaVariantInitialize
	#define EXT_OpcUaVariantInitialize
	#define GET_OpcUaVariantInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaVariantInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaVariantInitialize  FALSE
	#define EXP_OpcUaVariantInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaVariantInitialize
	#define EXT_OpcUaVariantInitialize
	#define GET_OpcUaVariantInitialize(fl)  CAL_CMGETAPI( "OpcUaVariantInitialize" ) 
	#define CAL_OpcUaVariantInitialize  OpcUaVariantInitialize
	#define CHK_OpcUaVariantInitialize  TRUE
	#define EXP_OpcUaVariantInitialize  CAL_CMEXPAPI( "OpcUaVariantInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaVariantInitialize
	#define EXT_OpcUaVariantInitialize
	#define GET_OpcUaVariantInitialize(fl)  CAL_CMGETAPI( "OpcUaVariantInitialize" ) 
	#define CAL_OpcUaVariantInitialize  OpcUaVariantInitialize
	#define CHK_OpcUaVariantInitialize  TRUE
	#define EXP_OpcUaVariantInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaVariantInitialize", (RTS_UINTPTR)OpcUaVariantInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaVariantInitialize
	#define EXT_CmpOPCUAStackOpcUaVariantInitialize
	#define GET_CmpOPCUAStackOpcUaVariantInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaVariantInitialize pICmpOPCUAStack->IOpcUaVariantInitialize
	#define CHK_CmpOPCUAStackOpcUaVariantInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaVariantInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaVariantInitialize
	#define EXT_OpcUaVariantInitialize
	#define GET_OpcUaVariantInitialize(fl)  CAL_CMGETAPI( "OpcUaVariantInitialize" ) 
	#define CAL_OpcUaVariantInitialize pICmpOPCUAStack->IOpcUaVariantInitialize
	#define CHK_OpcUaVariantInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaVariantInitialize  CAL_CMEXPAPI( "OpcUaVariantInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaVariantInitialize  PFOPCUAVARIANTINITIALIZE pfOpcUaVariantInitialize;
	#define EXT_OpcUaVariantInitialize  extern PFOPCUAVARIANTINITIALIZE pfOpcUaVariantInitialize;
	#define GET_OpcUaVariantInitialize(fl)  s_pfCMGetAPI2( "OpcUaVariantInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaVariantInitialize, (fl), 0, 0)
	#define CAL_OpcUaVariantInitialize  pfOpcUaVariantInitialize
	#define CHK_OpcUaVariantInitialize  (pfOpcUaVariantInitialize != NULL)
	#define EXP_OpcUaVariantInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaVariantInitialize", (RTS_UINTPTR)OpcUaVariantInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaVariantClear(OpcUa_Variant* value);
typedef OpcUa_Void (CDECL * PFOPCUAVARIANTCLEAR) (OpcUa_Variant* value);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAVARIANTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaVariantClear
	#define EXT_OpcUaVariantClear
	#define GET_OpcUaVariantClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaVariantClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaVariantClear  FALSE
	#define EXP_OpcUaVariantClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaVariantClear
	#define EXT_OpcUaVariantClear
	#define GET_OpcUaVariantClear(fl)  CAL_CMGETAPI( "OpcUaVariantClear" ) 
	#define CAL_OpcUaVariantClear  OpcUaVariantClear
	#define CHK_OpcUaVariantClear  TRUE
	#define EXP_OpcUaVariantClear  CAL_CMEXPAPI( "OpcUaVariantClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaVariantClear
	#define EXT_OpcUaVariantClear
	#define GET_OpcUaVariantClear(fl)  CAL_CMGETAPI( "OpcUaVariantClear" ) 
	#define CAL_OpcUaVariantClear  OpcUaVariantClear
	#define CHK_OpcUaVariantClear  TRUE
	#define EXP_OpcUaVariantClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaVariantClear", (RTS_UINTPTR)OpcUaVariantClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaVariantClear
	#define EXT_CmpOPCUAStackOpcUaVariantClear
	#define GET_CmpOPCUAStackOpcUaVariantClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaVariantClear pICmpOPCUAStack->IOpcUaVariantClear
	#define CHK_CmpOPCUAStackOpcUaVariantClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaVariantClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaVariantClear
	#define EXT_OpcUaVariantClear
	#define GET_OpcUaVariantClear(fl)  CAL_CMGETAPI( "OpcUaVariantClear" ) 
	#define CAL_OpcUaVariantClear pICmpOPCUAStack->IOpcUaVariantClear
	#define CHK_OpcUaVariantClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaVariantClear  CAL_CMEXPAPI( "OpcUaVariantClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaVariantClear  PFOPCUAVARIANTCLEAR pfOpcUaVariantClear;
	#define EXT_OpcUaVariantClear  extern PFOPCUAVARIANTCLEAR pfOpcUaVariantClear;
	#define GET_OpcUaVariantClear(fl)  s_pfCMGetAPI2( "OpcUaVariantClear", (RTS_VOID_FCTPTR *)&pfOpcUaVariantClear, (fl), 0, 0)
	#define CAL_OpcUaVariantClear  pfOpcUaVariantClear
	#define CHK_OpcUaVariantClear  (pfOpcUaVariantClear != NULL)
	#define EXP_OpcUaVariantClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaVariantClear", (RTS_UINTPTR)OpcUaVariantClear, 0, 0) 
#endif



OpcUa_Int CDECL OpcUaVariantCompare(const OpcUa_Variant* pValue1, const OpcUa_Variant* pValue2);
typedef OpcUa_Int (CDECL * PFOPCUAVARIANTCOMPARE) (const OpcUa_Variant* pValue1, const OpcUa_Variant* pValue2);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAVARIANTCOMPARE_NOTIMPLEMENTED)
	#define USE_OpcUaVariantCompare
	#define EXT_OpcUaVariantCompare
	#define GET_OpcUaVariantCompare(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaVariantCompare(p0,p1)  (OpcUa_Int)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaVariantCompare  FALSE
	#define EXP_OpcUaVariantCompare  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaVariantCompare
	#define EXT_OpcUaVariantCompare
	#define GET_OpcUaVariantCompare(fl)  CAL_CMGETAPI( "OpcUaVariantCompare" ) 
	#define CAL_OpcUaVariantCompare  OpcUaVariantCompare
	#define CHK_OpcUaVariantCompare  TRUE
	#define EXP_OpcUaVariantCompare  CAL_CMEXPAPI( "OpcUaVariantCompare" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaVariantCompare
	#define EXT_OpcUaVariantCompare
	#define GET_OpcUaVariantCompare(fl)  CAL_CMGETAPI( "OpcUaVariantCompare" ) 
	#define CAL_OpcUaVariantCompare  OpcUaVariantCompare
	#define CHK_OpcUaVariantCompare  TRUE
	#define EXP_OpcUaVariantCompare  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaVariantCompare", (RTS_UINTPTR)OpcUaVariantCompare, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaVariantCompare
	#define EXT_CmpOPCUAStackOpcUaVariantCompare
	#define GET_CmpOPCUAStackOpcUaVariantCompare  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaVariantCompare pICmpOPCUAStack->IOpcUaVariantCompare
	#define CHK_CmpOPCUAStackOpcUaVariantCompare (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaVariantCompare  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaVariantCompare
	#define EXT_OpcUaVariantCompare
	#define GET_OpcUaVariantCompare(fl)  CAL_CMGETAPI( "OpcUaVariantCompare" ) 
	#define CAL_OpcUaVariantCompare pICmpOPCUAStack->IOpcUaVariantCompare
	#define CHK_OpcUaVariantCompare (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaVariantCompare  CAL_CMEXPAPI( "OpcUaVariantCompare" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaVariantCompare  PFOPCUAVARIANTCOMPARE pfOpcUaVariantCompare;
	#define EXT_OpcUaVariantCompare  extern PFOPCUAVARIANTCOMPARE pfOpcUaVariantCompare;
	#define GET_OpcUaVariantCompare(fl)  s_pfCMGetAPI2( "OpcUaVariantCompare", (RTS_VOID_FCTPTR *)&pfOpcUaVariantCompare, (fl), 0, 0)
	#define CAL_OpcUaVariantCompare  pfOpcUaVariantCompare
	#define CHK_OpcUaVariantCompare  (pfOpcUaVariantCompare != NULL)
	#define EXP_OpcUaVariantCompare  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaVariantCompare", (RTS_UINTPTR)OpcUaVariantCompare, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaVariantCopyTo(const OpcUa_Variant* pSource, OpcUa_Variant* pDestination);
typedef OpcUa_StatusCode (CDECL * PFOPCUAVARIANTCOPYTO) (const OpcUa_Variant* pSource, OpcUa_Variant* pDestination);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAVARIANTCOPYTO_NOTIMPLEMENTED)
	#define USE_OpcUaVariantCopyTo
	#define EXT_OpcUaVariantCopyTo
	#define GET_OpcUaVariantCopyTo(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaVariantCopyTo(p0,p1)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaVariantCopyTo  FALSE
	#define EXP_OpcUaVariantCopyTo  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaVariantCopyTo
	#define EXT_OpcUaVariantCopyTo
	#define GET_OpcUaVariantCopyTo(fl)  CAL_CMGETAPI( "OpcUaVariantCopyTo" ) 
	#define CAL_OpcUaVariantCopyTo  OpcUaVariantCopyTo
	#define CHK_OpcUaVariantCopyTo  TRUE
	#define EXP_OpcUaVariantCopyTo  CAL_CMEXPAPI( "OpcUaVariantCopyTo" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaVariantCopyTo
	#define EXT_OpcUaVariantCopyTo
	#define GET_OpcUaVariantCopyTo(fl)  CAL_CMGETAPI( "OpcUaVariantCopyTo" ) 
	#define CAL_OpcUaVariantCopyTo  OpcUaVariantCopyTo
	#define CHK_OpcUaVariantCopyTo  TRUE
	#define EXP_OpcUaVariantCopyTo  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaVariantCopyTo", (RTS_UINTPTR)OpcUaVariantCopyTo, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaVariantCopyTo
	#define EXT_CmpOPCUAStackOpcUaVariantCopyTo
	#define GET_CmpOPCUAStackOpcUaVariantCopyTo  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaVariantCopyTo pICmpOPCUAStack->IOpcUaVariantCopyTo
	#define CHK_CmpOPCUAStackOpcUaVariantCopyTo (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaVariantCopyTo  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaVariantCopyTo
	#define EXT_OpcUaVariantCopyTo
	#define GET_OpcUaVariantCopyTo(fl)  CAL_CMGETAPI( "OpcUaVariantCopyTo" ) 
	#define CAL_OpcUaVariantCopyTo pICmpOPCUAStack->IOpcUaVariantCopyTo
	#define CHK_OpcUaVariantCopyTo (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaVariantCopyTo  CAL_CMEXPAPI( "OpcUaVariantCopyTo" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaVariantCopyTo  PFOPCUAVARIANTCOPYTO pfOpcUaVariantCopyTo;
	#define EXT_OpcUaVariantCopyTo  extern PFOPCUAVARIANTCOPYTO pfOpcUaVariantCopyTo;
	#define GET_OpcUaVariantCopyTo(fl)  s_pfCMGetAPI2( "OpcUaVariantCopyTo", (RTS_VOID_FCTPTR *)&pfOpcUaVariantCopyTo, (fl), 0, 0)
	#define CAL_OpcUaVariantCopyTo  pfOpcUaVariantCopyTo
	#define CHK_OpcUaVariantCopyTo  (pfOpcUaVariantCopyTo != NULL)
	#define EXP_OpcUaVariantCopyTo  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaVariantCopyTo", (RTS_UINTPTR)OpcUaVariantCopyTo, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaDataValueInitialize(OpcUa_DataValue* pValue);
typedef OpcUa_Void (CDECL * PFOPCUADATAVALUEINITIALIZE) (OpcUa_DataValue* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUADATAVALUEINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaDataValueInitialize
	#define EXT_OpcUaDataValueInitialize
	#define GET_OpcUaDataValueInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaDataValueInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaDataValueInitialize  FALSE
	#define EXP_OpcUaDataValueInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaDataValueInitialize
	#define EXT_OpcUaDataValueInitialize
	#define GET_OpcUaDataValueInitialize(fl)  CAL_CMGETAPI( "OpcUaDataValueInitialize" ) 
	#define CAL_OpcUaDataValueInitialize  OpcUaDataValueInitialize
	#define CHK_OpcUaDataValueInitialize  TRUE
	#define EXP_OpcUaDataValueInitialize  CAL_CMEXPAPI( "OpcUaDataValueInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaDataValueInitialize
	#define EXT_OpcUaDataValueInitialize
	#define GET_OpcUaDataValueInitialize(fl)  CAL_CMGETAPI( "OpcUaDataValueInitialize" ) 
	#define CAL_OpcUaDataValueInitialize  OpcUaDataValueInitialize
	#define CHK_OpcUaDataValueInitialize  TRUE
	#define EXP_OpcUaDataValueInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDataValueInitialize", (RTS_UINTPTR)OpcUaDataValueInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaDataValueInitialize
	#define EXT_CmpOPCUAStackOpcUaDataValueInitialize
	#define GET_CmpOPCUAStackOpcUaDataValueInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaDataValueInitialize pICmpOPCUAStack->IOpcUaDataValueInitialize
	#define CHK_CmpOPCUAStackOpcUaDataValueInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaDataValueInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaDataValueInitialize
	#define EXT_OpcUaDataValueInitialize
	#define GET_OpcUaDataValueInitialize(fl)  CAL_CMGETAPI( "OpcUaDataValueInitialize" ) 
	#define CAL_OpcUaDataValueInitialize pICmpOPCUAStack->IOpcUaDataValueInitialize
	#define CHK_OpcUaDataValueInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaDataValueInitialize  CAL_CMEXPAPI( "OpcUaDataValueInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaDataValueInitialize  PFOPCUADATAVALUEINITIALIZE pfOpcUaDataValueInitialize;
	#define EXT_OpcUaDataValueInitialize  extern PFOPCUADATAVALUEINITIALIZE pfOpcUaDataValueInitialize;
	#define GET_OpcUaDataValueInitialize(fl)  s_pfCMGetAPI2( "OpcUaDataValueInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaDataValueInitialize, (fl), 0, 0)
	#define CAL_OpcUaDataValueInitialize  pfOpcUaDataValueInitialize
	#define CHK_OpcUaDataValueInitialize  (pfOpcUaDataValueInitialize != NULL)
	#define EXP_OpcUaDataValueInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDataValueInitialize", (RTS_UINTPTR)OpcUaDataValueInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaDataValueClear(OpcUa_DataValue* pValue);
typedef OpcUa_Void (CDECL * PFOPCUADATAVALUECLEAR) (OpcUa_DataValue* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUADATAVALUECLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaDataValueClear
	#define EXT_OpcUaDataValueClear
	#define GET_OpcUaDataValueClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaDataValueClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaDataValueClear  FALSE
	#define EXP_OpcUaDataValueClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaDataValueClear
	#define EXT_OpcUaDataValueClear
	#define GET_OpcUaDataValueClear(fl)  CAL_CMGETAPI( "OpcUaDataValueClear" ) 
	#define CAL_OpcUaDataValueClear  OpcUaDataValueClear
	#define CHK_OpcUaDataValueClear  TRUE
	#define EXP_OpcUaDataValueClear  CAL_CMEXPAPI( "OpcUaDataValueClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaDataValueClear
	#define EXT_OpcUaDataValueClear
	#define GET_OpcUaDataValueClear(fl)  CAL_CMGETAPI( "OpcUaDataValueClear" ) 
	#define CAL_OpcUaDataValueClear  OpcUaDataValueClear
	#define CHK_OpcUaDataValueClear  TRUE
	#define EXP_OpcUaDataValueClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDataValueClear", (RTS_UINTPTR)OpcUaDataValueClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaDataValueClear
	#define EXT_CmpOPCUAStackOpcUaDataValueClear
	#define GET_CmpOPCUAStackOpcUaDataValueClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaDataValueClear pICmpOPCUAStack->IOpcUaDataValueClear
	#define CHK_CmpOPCUAStackOpcUaDataValueClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaDataValueClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaDataValueClear
	#define EXT_OpcUaDataValueClear
	#define GET_OpcUaDataValueClear(fl)  CAL_CMGETAPI( "OpcUaDataValueClear" ) 
	#define CAL_OpcUaDataValueClear pICmpOPCUAStack->IOpcUaDataValueClear
	#define CHK_OpcUaDataValueClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaDataValueClear  CAL_CMEXPAPI( "OpcUaDataValueClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaDataValueClear  PFOPCUADATAVALUECLEAR pfOpcUaDataValueClear;
	#define EXT_OpcUaDataValueClear  extern PFOPCUADATAVALUECLEAR pfOpcUaDataValueClear;
	#define GET_OpcUaDataValueClear(fl)  s_pfCMGetAPI2( "OpcUaDataValueClear", (RTS_VOID_FCTPTR *)&pfOpcUaDataValueClear, (fl), 0, 0)
	#define CAL_OpcUaDataValueClear  pfOpcUaDataValueClear
	#define CHK_OpcUaDataValueClear  (pfOpcUaDataValueClear != NULL)
	#define EXP_OpcUaDataValueClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDataValueClear", (RTS_UINTPTR)OpcUaDataValueClear, 0, 0) 
#endif



OpcUa_Int CDECL OpcUaDataValueCompare(const OpcUa_DataValue* pValue1, const OpcUa_DataValue* pValue2);
typedef OpcUa_Int (CDECL * PFOPCUADATAVALUECOMPARE) (const OpcUa_DataValue* pValue1, const OpcUa_DataValue* pValue2);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUADATAVALUECOMPARE_NOTIMPLEMENTED)
	#define USE_OpcUaDataValueCompare
	#define EXT_OpcUaDataValueCompare
	#define GET_OpcUaDataValueCompare(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaDataValueCompare(p0,p1)  (OpcUa_Int)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaDataValueCompare  FALSE
	#define EXP_OpcUaDataValueCompare  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaDataValueCompare
	#define EXT_OpcUaDataValueCompare
	#define GET_OpcUaDataValueCompare(fl)  CAL_CMGETAPI( "OpcUaDataValueCompare" ) 
	#define CAL_OpcUaDataValueCompare  OpcUaDataValueCompare
	#define CHK_OpcUaDataValueCompare  TRUE
	#define EXP_OpcUaDataValueCompare  CAL_CMEXPAPI( "OpcUaDataValueCompare" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaDataValueCompare
	#define EXT_OpcUaDataValueCompare
	#define GET_OpcUaDataValueCompare(fl)  CAL_CMGETAPI( "OpcUaDataValueCompare" ) 
	#define CAL_OpcUaDataValueCompare  OpcUaDataValueCompare
	#define CHK_OpcUaDataValueCompare  TRUE
	#define EXP_OpcUaDataValueCompare  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDataValueCompare", (RTS_UINTPTR)OpcUaDataValueCompare, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaDataValueCompare
	#define EXT_CmpOPCUAStackOpcUaDataValueCompare
	#define GET_CmpOPCUAStackOpcUaDataValueCompare  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaDataValueCompare pICmpOPCUAStack->IOpcUaDataValueCompare
	#define CHK_CmpOPCUAStackOpcUaDataValueCompare (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaDataValueCompare  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaDataValueCompare
	#define EXT_OpcUaDataValueCompare
	#define GET_OpcUaDataValueCompare(fl)  CAL_CMGETAPI( "OpcUaDataValueCompare" ) 
	#define CAL_OpcUaDataValueCompare pICmpOPCUAStack->IOpcUaDataValueCompare
	#define CHK_OpcUaDataValueCompare (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaDataValueCompare  CAL_CMEXPAPI( "OpcUaDataValueCompare" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaDataValueCompare  PFOPCUADATAVALUECOMPARE pfOpcUaDataValueCompare;
	#define EXT_OpcUaDataValueCompare  extern PFOPCUADATAVALUECOMPARE pfOpcUaDataValueCompare;
	#define GET_OpcUaDataValueCompare(fl)  s_pfCMGetAPI2( "OpcUaDataValueCompare", (RTS_VOID_FCTPTR *)&pfOpcUaDataValueCompare, (fl), 0, 0)
	#define CAL_OpcUaDataValueCompare  pfOpcUaDataValueCompare
	#define CHK_OpcUaDataValueCompare  (pfOpcUaDataValueCompare != NULL)
	#define EXP_OpcUaDataValueCompare  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDataValueCompare", (RTS_UINTPTR)OpcUaDataValueCompare, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaDataValueCopyTo(const OpcUa_DataValue* pSource, OpcUa_DataValue* pDestination);
typedef OpcUa_StatusCode (CDECL * PFOPCUADATAVALUECOPYTO) (const OpcUa_DataValue* pSource, OpcUa_DataValue* pDestination);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUADATAVALUECOPYTO_NOTIMPLEMENTED)
	#define USE_OpcUaDataValueCopyTo
	#define EXT_OpcUaDataValueCopyTo
	#define GET_OpcUaDataValueCopyTo(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaDataValueCopyTo(p0,p1)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaDataValueCopyTo  FALSE
	#define EXP_OpcUaDataValueCopyTo  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaDataValueCopyTo
	#define EXT_OpcUaDataValueCopyTo
	#define GET_OpcUaDataValueCopyTo(fl)  CAL_CMGETAPI( "OpcUaDataValueCopyTo" ) 
	#define CAL_OpcUaDataValueCopyTo  OpcUaDataValueCopyTo
	#define CHK_OpcUaDataValueCopyTo  TRUE
	#define EXP_OpcUaDataValueCopyTo  CAL_CMEXPAPI( "OpcUaDataValueCopyTo" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaDataValueCopyTo
	#define EXT_OpcUaDataValueCopyTo
	#define GET_OpcUaDataValueCopyTo(fl)  CAL_CMGETAPI( "OpcUaDataValueCopyTo" ) 
	#define CAL_OpcUaDataValueCopyTo  OpcUaDataValueCopyTo
	#define CHK_OpcUaDataValueCopyTo  TRUE
	#define EXP_OpcUaDataValueCopyTo  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDataValueCopyTo", (RTS_UINTPTR)OpcUaDataValueCopyTo, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaDataValueCopyTo
	#define EXT_CmpOPCUAStackOpcUaDataValueCopyTo
	#define GET_CmpOPCUAStackOpcUaDataValueCopyTo  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaDataValueCopyTo pICmpOPCUAStack->IOpcUaDataValueCopyTo
	#define CHK_CmpOPCUAStackOpcUaDataValueCopyTo (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaDataValueCopyTo  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaDataValueCopyTo
	#define EXT_OpcUaDataValueCopyTo
	#define GET_OpcUaDataValueCopyTo(fl)  CAL_CMGETAPI( "OpcUaDataValueCopyTo" ) 
	#define CAL_OpcUaDataValueCopyTo pICmpOPCUAStack->IOpcUaDataValueCopyTo
	#define CHK_OpcUaDataValueCopyTo (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaDataValueCopyTo  CAL_CMEXPAPI( "OpcUaDataValueCopyTo" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaDataValueCopyTo  PFOPCUADATAVALUECOPYTO pfOpcUaDataValueCopyTo;
	#define EXT_OpcUaDataValueCopyTo  extern PFOPCUADATAVALUECOPYTO pfOpcUaDataValueCopyTo;
	#define GET_OpcUaDataValueCopyTo(fl)  s_pfCMGetAPI2( "OpcUaDataValueCopyTo", (RTS_VOID_FCTPTR *)&pfOpcUaDataValueCopyTo, (fl), 0, 0)
	#define CAL_OpcUaDataValueCopyTo  pfOpcUaDataValueCopyTo
	#define CHK_OpcUaDataValueCopyTo  (pfOpcUaDataValueCopyTo != NULL)
	#define EXP_OpcUaDataValueCopyTo  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDataValueCopyTo", (RTS_UINTPTR)OpcUaDataValueCopyTo, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaExtensionObjectCreate(OpcUa_ExtensionObject** ppValue);
typedef OpcUa_Void (CDECL * PFOPCUAEXTENSIONOBJECTCREATE) (OpcUa_ExtensionObject** ppValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAEXTENSIONOBJECTCREATE_NOTIMPLEMENTED)
	#define USE_OpcUaExtensionObjectCreate
	#define EXT_OpcUaExtensionObjectCreate
	#define GET_OpcUaExtensionObjectCreate(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaExtensionObjectCreate(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaExtensionObjectCreate  FALSE
	#define EXP_OpcUaExtensionObjectCreate  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaExtensionObjectCreate
	#define EXT_OpcUaExtensionObjectCreate
	#define GET_OpcUaExtensionObjectCreate(fl)  CAL_CMGETAPI( "OpcUaExtensionObjectCreate" ) 
	#define CAL_OpcUaExtensionObjectCreate  OpcUaExtensionObjectCreate
	#define CHK_OpcUaExtensionObjectCreate  TRUE
	#define EXP_OpcUaExtensionObjectCreate  CAL_CMEXPAPI( "OpcUaExtensionObjectCreate" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaExtensionObjectCreate
	#define EXT_OpcUaExtensionObjectCreate
	#define GET_OpcUaExtensionObjectCreate(fl)  CAL_CMGETAPI( "OpcUaExtensionObjectCreate" ) 
	#define CAL_OpcUaExtensionObjectCreate  OpcUaExtensionObjectCreate
	#define CHK_OpcUaExtensionObjectCreate  TRUE
	#define EXP_OpcUaExtensionObjectCreate  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaExtensionObjectCreate", (RTS_UINTPTR)OpcUaExtensionObjectCreate, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaExtensionObjectCreate
	#define EXT_CmpOPCUAStackOpcUaExtensionObjectCreate
	#define GET_CmpOPCUAStackOpcUaExtensionObjectCreate  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaExtensionObjectCreate pICmpOPCUAStack->IOpcUaExtensionObjectCreate
	#define CHK_CmpOPCUAStackOpcUaExtensionObjectCreate (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaExtensionObjectCreate  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaExtensionObjectCreate
	#define EXT_OpcUaExtensionObjectCreate
	#define GET_OpcUaExtensionObjectCreate(fl)  CAL_CMGETAPI( "OpcUaExtensionObjectCreate" ) 
	#define CAL_OpcUaExtensionObjectCreate pICmpOPCUAStack->IOpcUaExtensionObjectCreate
	#define CHK_OpcUaExtensionObjectCreate (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaExtensionObjectCreate  CAL_CMEXPAPI( "OpcUaExtensionObjectCreate" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaExtensionObjectCreate  PFOPCUAEXTENSIONOBJECTCREATE pfOpcUaExtensionObjectCreate;
	#define EXT_OpcUaExtensionObjectCreate  extern PFOPCUAEXTENSIONOBJECTCREATE pfOpcUaExtensionObjectCreate;
	#define GET_OpcUaExtensionObjectCreate(fl)  s_pfCMGetAPI2( "OpcUaExtensionObjectCreate", (RTS_VOID_FCTPTR *)&pfOpcUaExtensionObjectCreate, (fl), 0, 0)
	#define CAL_OpcUaExtensionObjectCreate  pfOpcUaExtensionObjectCreate
	#define CHK_OpcUaExtensionObjectCreate  (pfOpcUaExtensionObjectCreate != NULL)
	#define EXP_OpcUaExtensionObjectCreate  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaExtensionObjectCreate", (RTS_UINTPTR)OpcUaExtensionObjectCreate, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaExtensionObjectInitialize(OpcUa_ExtensionObject* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAEXTENSIONOBJECTINITIALIZE) (OpcUa_ExtensionObject* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAEXTENSIONOBJECTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaExtensionObjectInitialize
	#define EXT_OpcUaExtensionObjectInitialize
	#define GET_OpcUaExtensionObjectInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaExtensionObjectInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaExtensionObjectInitialize  FALSE
	#define EXP_OpcUaExtensionObjectInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaExtensionObjectInitialize
	#define EXT_OpcUaExtensionObjectInitialize
	#define GET_OpcUaExtensionObjectInitialize(fl)  CAL_CMGETAPI( "OpcUaExtensionObjectInitialize" ) 
	#define CAL_OpcUaExtensionObjectInitialize  OpcUaExtensionObjectInitialize
	#define CHK_OpcUaExtensionObjectInitialize  TRUE
	#define EXP_OpcUaExtensionObjectInitialize  CAL_CMEXPAPI( "OpcUaExtensionObjectInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaExtensionObjectInitialize
	#define EXT_OpcUaExtensionObjectInitialize
	#define GET_OpcUaExtensionObjectInitialize(fl)  CAL_CMGETAPI( "OpcUaExtensionObjectInitialize" ) 
	#define CAL_OpcUaExtensionObjectInitialize  OpcUaExtensionObjectInitialize
	#define CHK_OpcUaExtensionObjectInitialize  TRUE
	#define EXP_OpcUaExtensionObjectInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaExtensionObjectInitialize", (RTS_UINTPTR)OpcUaExtensionObjectInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaExtensionObjectInitialize
	#define EXT_CmpOPCUAStackOpcUaExtensionObjectInitialize
	#define GET_CmpOPCUAStackOpcUaExtensionObjectInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaExtensionObjectInitialize pICmpOPCUAStack->IOpcUaExtensionObjectInitialize
	#define CHK_CmpOPCUAStackOpcUaExtensionObjectInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaExtensionObjectInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaExtensionObjectInitialize
	#define EXT_OpcUaExtensionObjectInitialize
	#define GET_OpcUaExtensionObjectInitialize(fl)  CAL_CMGETAPI( "OpcUaExtensionObjectInitialize" ) 
	#define CAL_OpcUaExtensionObjectInitialize pICmpOPCUAStack->IOpcUaExtensionObjectInitialize
	#define CHK_OpcUaExtensionObjectInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaExtensionObjectInitialize  CAL_CMEXPAPI( "OpcUaExtensionObjectInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaExtensionObjectInitialize  PFOPCUAEXTENSIONOBJECTINITIALIZE pfOpcUaExtensionObjectInitialize;
	#define EXT_OpcUaExtensionObjectInitialize  extern PFOPCUAEXTENSIONOBJECTINITIALIZE pfOpcUaExtensionObjectInitialize;
	#define GET_OpcUaExtensionObjectInitialize(fl)  s_pfCMGetAPI2( "OpcUaExtensionObjectInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaExtensionObjectInitialize, (fl), 0, 0)
	#define CAL_OpcUaExtensionObjectInitialize  pfOpcUaExtensionObjectInitialize
	#define CHK_OpcUaExtensionObjectInitialize  (pfOpcUaExtensionObjectInitialize != NULL)
	#define EXP_OpcUaExtensionObjectInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaExtensionObjectInitialize", (RTS_UINTPTR)OpcUaExtensionObjectInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaExtensionObjectClear(OpcUa_ExtensionObject* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAEXTENSIONOBJECTCLEAR) (OpcUa_ExtensionObject* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAEXTENSIONOBJECTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaExtensionObjectClear
	#define EXT_OpcUaExtensionObjectClear
	#define GET_OpcUaExtensionObjectClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaExtensionObjectClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaExtensionObjectClear  FALSE
	#define EXP_OpcUaExtensionObjectClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaExtensionObjectClear
	#define EXT_OpcUaExtensionObjectClear
	#define GET_OpcUaExtensionObjectClear(fl)  CAL_CMGETAPI( "OpcUaExtensionObjectClear" ) 
	#define CAL_OpcUaExtensionObjectClear  OpcUaExtensionObjectClear
	#define CHK_OpcUaExtensionObjectClear  TRUE
	#define EXP_OpcUaExtensionObjectClear  CAL_CMEXPAPI( "OpcUaExtensionObjectClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaExtensionObjectClear
	#define EXT_OpcUaExtensionObjectClear
	#define GET_OpcUaExtensionObjectClear(fl)  CAL_CMGETAPI( "OpcUaExtensionObjectClear" ) 
	#define CAL_OpcUaExtensionObjectClear  OpcUaExtensionObjectClear
	#define CHK_OpcUaExtensionObjectClear  TRUE
	#define EXP_OpcUaExtensionObjectClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaExtensionObjectClear", (RTS_UINTPTR)OpcUaExtensionObjectClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaExtensionObjectClear
	#define EXT_CmpOPCUAStackOpcUaExtensionObjectClear
	#define GET_CmpOPCUAStackOpcUaExtensionObjectClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaExtensionObjectClear pICmpOPCUAStack->IOpcUaExtensionObjectClear
	#define CHK_CmpOPCUAStackOpcUaExtensionObjectClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaExtensionObjectClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaExtensionObjectClear
	#define EXT_OpcUaExtensionObjectClear
	#define GET_OpcUaExtensionObjectClear(fl)  CAL_CMGETAPI( "OpcUaExtensionObjectClear" ) 
	#define CAL_OpcUaExtensionObjectClear pICmpOPCUAStack->IOpcUaExtensionObjectClear
	#define CHK_OpcUaExtensionObjectClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaExtensionObjectClear  CAL_CMEXPAPI( "OpcUaExtensionObjectClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaExtensionObjectClear  PFOPCUAEXTENSIONOBJECTCLEAR pfOpcUaExtensionObjectClear;
	#define EXT_OpcUaExtensionObjectClear  extern PFOPCUAEXTENSIONOBJECTCLEAR pfOpcUaExtensionObjectClear;
	#define GET_OpcUaExtensionObjectClear(fl)  s_pfCMGetAPI2( "OpcUaExtensionObjectClear", (RTS_VOID_FCTPTR *)&pfOpcUaExtensionObjectClear, (fl), 0, 0)
	#define CAL_OpcUaExtensionObjectClear  pfOpcUaExtensionObjectClear
	#define CHK_OpcUaExtensionObjectClear  (pfOpcUaExtensionObjectClear != NULL)
	#define EXP_OpcUaExtensionObjectClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaExtensionObjectClear", (RTS_UINTPTR)OpcUaExtensionObjectClear, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaExtensionObjectDelete(OpcUa_ExtensionObject** ppValue);
typedef OpcUa_Void (CDECL * PFOPCUAEXTENSIONOBJECTDELETE) (OpcUa_ExtensionObject** ppValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAEXTENSIONOBJECTDELETE_NOTIMPLEMENTED)
	#define USE_OpcUaExtensionObjectDelete
	#define EXT_OpcUaExtensionObjectDelete
	#define GET_OpcUaExtensionObjectDelete(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaExtensionObjectDelete(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaExtensionObjectDelete  FALSE
	#define EXP_OpcUaExtensionObjectDelete  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaExtensionObjectDelete
	#define EXT_OpcUaExtensionObjectDelete
	#define GET_OpcUaExtensionObjectDelete(fl)  CAL_CMGETAPI( "OpcUaExtensionObjectDelete" ) 
	#define CAL_OpcUaExtensionObjectDelete  OpcUaExtensionObjectDelete
	#define CHK_OpcUaExtensionObjectDelete  TRUE
	#define EXP_OpcUaExtensionObjectDelete  CAL_CMEXPAPI( "OpcUaExtensionObjectDelete" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaExtensionObjectDelete
	#define EXT_OpcUaExtensionObjectDelete
	#define GET_OpcUaExtensionObjectDelete(fl)  CAL_CMGETAPI( "OpcUaExtensionObjectDelete" ) 
	#define CAL_OpcUaExtensionObjectDelete  OpcUaExtensionObjectDelete
	#define CHK_OpcUaExtensionObjectDelete  TRUE
	#define EXP_OpcUaExtensionObjectDelete  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaExtensionObjectDelete", (RTS_UINTPTR)OpcUaExtensionObjectDelete, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaExtensionObjectDelete
	#define EXT_CmpOPCUAStackOpcUaExtensionObjectDelete
	#define GET_CmpOPCUAStackOpcUaExtensionObjectDelete  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaExtensionObjectDelete pICmpOPCUAStack->IOpcUaExtensionObjectDelete
	#define CHK_CmpOPCUAStackOpcUaExtensionObjectDelete (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaExtensionObjectDelete  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaExtensionObjectDelete
	#define EXT_OpcUaExtensionObjectDelete
	#define GET_OpcUaExtensionObjectDelete(fl)  CAL_CMGETAPI( "OpcUaExtensionObjectDelete" ) 
	#define CAL_OpcUaExtensionObjectDelete pICmpOPCUAStack->IOpcUaExtensionObjectDelete
	#define CHK_OpcUaExtensionObjectDelete (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaExtensionObjectDelete  CAL_CMEXPAPI( "OpcUaExtensionObjectDelete" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaExtensionObjectDelete  PFOPCUAEXTENSIONOBJECTDELETE pfOpcUaExtensionObjectDelete;
	#define EXT_OpcUaExtensionObjectDelete  extern PFOPCUAEXTENSIONOBJECTDELETE pfOpcUaExtensionObjectDelete;
	#define GET_OpcUaExtensionObjectDelete(fl)  s_pfCMGetAPI2( "OpcUaExtensionObjectDelete", (RTS_VOID_FCTPTR *)&pfOpcUaExtensionObjectDelete, (fl), 0, 0)
	#define CAL_OpcUaExtensionObjectDelete  pfOpcUaExtensionObjectDelete
	#define CHK_OpcUaExtensionObjectDelete  (pfOpcUaExtensionObjectDelete != NULL)
	#define EXP_OpcUaExtensionObjectDelete  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaExtensionObjectDelete", (RTS_UINTPTR)OpcUaExtensionObjectDelete, 0, 0) 
#endif



OpcUa_Int CDECL OpcUaExtensionObjectCompare(const OpcUa_ExtensionObject* pValue1, const OpcUa_ExtensionObject* pValue2);
typedef OpcUa_Int (CDECL * PFOPCUAEXTENSIONOBJECTCOMPARE) (const OpcUa_ExtensionObject* pValue1, const OpcUa_ExtensionObject* pValue2);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAEXTENSIONOBJECTCOMPARE_NOTIMPLEMENTED)
	#define USE_OpcUaExtensionObjectCompare
	#define EXT_OpcUaExtensionObjectCompare
	#define GET_OpcUaExtensionObjectCompare(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaExtensionObjectCompare(p0,p1)  (OpcUa_Int)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaExtensionObjectCompare  FALSE
	#define EXP_OpcUaExtensionObjectCompare  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaExtensionObjectCompare
	#define EXT_OpcUaExtensionObjectCompare
	#define GET_OpcUaExtensionObjectCompare(fl)  CAL_CMGETAPI( "OpcUaExtensionObjectCompare" ) 
	#define CAL_OpcUaExtensionObjectCompare  OpcUaExtensionObjectCompare
	#define CHK_OpcUaExtensionObjectCompare  TRUE
	#define EXP_OpcUaExtensionObjectCompare  CAL_CMEXPAPI( "OpcUaExtensionObjectCompare" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaExtensionObjectCompare
	#define EXT_OpcUaExtensionObjectCompare
	#define GET_OpcUaExtensionObjectCompare(fl)  CAL_CMGETAPI( "OpcUaExtensionObjectCompare" ) 
	#define CAL_OpcUaExtensionObjectCompare  OpcUaExtensionObjectCompare
	#define CHK_OpcUaExtensionObjectCompare  TRUE
	#define EXP_OpcUaExtensionObjectCompare  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaExtensionObjectCompare", (RTS_UINTPTR)OpcUaExtensionObjectCompare, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaExtensionObjectCompare
	#define EXT_CmpOPCUAStackOpcUaExtensionObjectCompare
	#define GET_CmpOPCUAStackOpcUaExtensionObjectCompare  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaExtensionObjectCompare pICmpOPCUAStack->IOpcUaExtensionObjectCompare
	#define CHK_CmpOPCUAStackOpcUaExtensionObjectCompare (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaExtensionObjectCompare  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaExtensionObjectCompare
	#define EXT_OpcUaExtensionObjectCompare
	#define GET_OpcUaExtensionObjectCompare(fl)  CAL_CMGETAPI( "OpcUaExtensionObjectCompare" ) 
	#define CAL_OpcUaExtensionObjectCompare pICmpOPCUAStack->IOpcUaExtensionObjectCompare
	#define CHK_OpcUaExtensionObjectCompare (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaExtensionObjectCompare  CAL_CMEXPAPI( "OpcUaExtensionObjectCompare" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaExtensionObjectCompare  PFOPCUAEXTENSIONOBJECTCOMPARE pfOpcUaExtensionObjectCompare;
	#define EXT_OpcUaExtensionObjectCompare  extern PFOPCUAEXTENSIONOBJECTCOMPARE pfOpcUaExtensionObjectCompare;
	#define GET_OpcUaExtensionObjectCompare(fl)  s_pfCMGetAPI2( "OpcUaExtensionObjectCompare", (RTS_VOID_FCTPTR *)&pfOpcUaExtensionObjectCompare, (fl), 0, 0)
	#define CAL_OpcUaExtensionObjectCompare  pfOpcUaExtensionObjectCompare
	#define CHK_OpcUaExtensionObjectCompare  (pfOpcUaExtensionObjectCompare != NULL)
	#define EXP_OpcUaExtensionObjectCompare  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaExtensionObjectCompare", (RTS_UINTPTR)OpcUaExtensionObjectCompare, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaExtensionObjectCopyTo(const OpcUa_ExtensionObject* pSource, OpcUa_ExtensionObject* pDestination);
typedef OpcUa_StatusCode (CDECL * PFOPCUAEXTENSIONOBJECTCOPYTO) (const OpcUa_ExtensionObject* pSource, OpcUa_ExtensionObject* pDestination);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAEXTENSIONOBJECTCOPYTO_NOTIMPLEMENTED)
	#define USE_OpcUaExtensionObjectCopyTo
	#define EXT_OpcUaExtensionObjectCopyTo
	#define GET_OpcUaExtensionObjectCopyTo(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaExtensionObjectCopyTo(p0,p1)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaExtensionObjectCopyTo  FALSE
	#define EXP_OpcUaExtensionObjectCopyTo  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaExtensionObjectCopyTo
	#define EXT_OpcUaExtensionObjectCopyTo
	#define GET_OpcUaExtensionObjectCopyTo(fl)  CAL_CMGETAPI( "OpcUaExtensionObjectCopyTo" ) 
	#define CAL_OpcUaExtensionObjectCopyTo  OpcUaExtensionObjectCopyTo
	#define CHK_OpcUaExtensionObjectCopyTo  TRUE
	#define EXP_OpcUaExtensionObjectCopyTo  CAL_CMEXPAPI( "OpcUaExtensionObjectCopyTo" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaExtensionObjectCopyTo
	#define EXT_OpcUaExtensionObjectCopyTo
	#define GET_OpcUaExtensionObjectCopyTo(fl)  CAL_CMGETAPI( "OpcUaExtensionObjectCopyTo" ) 
	#define CAL_OpcUaExtensionObjectCopyTo  OpcUaExtensionObjectCopyTo
	#define CHK_OpcUaExtensionObjectCopyTo  TRUE
	#define EXP_OpcUaExtensionObjectCopyTo  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaExtensionObjectCopyTo", (RTS_UINTPTR)OpcUaExtensionObjectCopyTo, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaExtensionObjectCopyTo
	#define EXT_CmpOPCUAStackOpcUaExtensionObjectCopyTo
	#define GET_CmpOPCUAStackOpcUaExtensionObjectCopyTo  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaExtensionObjectCopyTo pICmpOPCUAStack->IOpcUaExtensionObjectCopyTo
	#define CHK_CmpOPCUAStackOpcUaExtensionObjectCopyTo (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaExtensionObjectCopyTo  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaExtensionObjectCopyTo
	#define EXT_OpcUaExtensionObjectCopyTo
	#define GET_OpcUaExtensionObjectCopyTo(fl)  CAL_CMGETAPI( "OpcUaExtensionObjectCopyTo" ) 
	#define CAL_OpcUaExtensionObjectCopyTo pICmpOPCUAStack->IOpcUaExtensionObjectCopyTo
	#define CHK_OpcUaExtensionObjectCopyTo (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaExtensionObjectCopyTo  CAL_CMEXPAPI( "OpcUaExtensionObjectCopyTo" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaExtensionObjectCopyTo  PFOPCUAEXTENSIONOBJECTCOPYTO pfOpcUaExtensionObjectCopyTo;
	#define EXT_OpcUaExtensionObjectCopyTo  extern PFOPCUAEXTENSIONOBJECTCOPYTO pfOpcUaExtensionObjectCopyTo;
	#define GET_OpcUaExtensionObjectCopyTo(fl)  s_pfCMGetAPI2( "OpcUaExtensionObjectCopyTo", (RTS_VOID_FCTPTR *)&pfOpcUaExtensionObjectCopyTo, (fl), 0, 0)
	#define CAL_OpcUaExtensionObjectCopyTo  pfOpcUaExtensionObjectCopyTo
	#define CHK_OpcUaExtensionObjectCopyTo  (pfOpcUaExtensionObjectCopyTo != NULL)
	#define EXP_OpcUaExtensionObjectCopyTo  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaExtensionObjectCopyTo", (RTS_UINTPTR)OpcUaExtensionObjectCopyTo, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaReadValueIdInitialize(OpcUa_ReadValueId* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAREADVALUEIDINITIALIZE) (OpcUa_ReadValueId* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAREADVALUEIDINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaReadValueIdInitialize
	#define EXT_OpcUaReadValueIdInitialize
	#define GET_OpcUaReadValueIdInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaReadValueIdInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaReadValueIdInitialize  FALSE
	#define EXP_OpcUaReadValueIdInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaReadValueIdInitialize
	#define EXT_OpcUaReadValueIdInitialize
	#define GET_OpcUaReadValueIdInitialize(fl)  CAL_CMGETAPI( "OpcUaReadValueIdInitialize" ) 
	#define CAL_OpcUaReadValueIdInitialize  OpcUaReadValueIdInitialize
	#define CHK_OpcUaReadValueIdInitialize  TRUE
	#define EXP_OpcUaReadValueIdInitialize  CAL_CMEXPAPI( "OpcUaReadValueIdInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaReadValueIdInitialize
	#define EXT_OpcUaReadValueIdInitialize
	#define GET_OpcUaReadValueIdInitialize(fl)  CAL_CMGETAPI( "OpcUaReadValueIdInitialize" ) 
	#define CAL_OpcUaReadValueIdInitialize  OpcUaReadValueIdInitialize
	#define CHK_OpcUaReadValueIdInitialize  TRUE
	#define EXP_OpcUaReadValueIdInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaReadValueIdInitialize", (RTS_UINTPTR)OpcUaReadValueIdInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaReadValueIdInitialize
	#define EXT_CmpOPCUAStackOpcUaReadValueIdInitialize
	#define GET_CmpOPCUAStackOpcUaReadValueIdInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaReadValueIdInitialize pICmpOPCUAStack->IOpcUaReadValueIdInitialize
	#define CHK_CmpOPCUAStackOpcUaReadValueIdInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaReadValueIdInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaReadValueIdInitialize
	#define EXT_OpcUaReadValueIdInitialize
	#define GET_OpcUaReadValueIdInitialize(fl)  CAL_CMGETAPI( "OpcUaReadValueIdInitialize" ) 
	#define CAL_OpcUaReadValueIdInitialize pICmpOPCUAStack->IOpcUaReadValueIdInitialize
	#define CHK_OpcUaReadValueIdInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaReadValueIdInitialize  CAL_CMEXPAPI( "OpcUaReadValueIdInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaReadValueIdInitialize  PFOPCUAREADVALUEIDINITIALIZE pfOpcUaReadValueIdInitialize;
	#define EXT_OpcUaReadValueIdInitialize  extern PFOPCUAREADVALUEIDINITIALIZE pfOpcUaReadValueIdInitialize;
	#define GET_OpcUaReadValueIdInitialize(fl)  s_pfCMGetAPI2( "OpcUaReadValueIdInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaReadValueIdInitialize, (fl), 0, 0)
	#define CAL_OpcUaReadValueIdInitialize  pfOpcUaReadValueIdInitialize
	#define CHK_OpcUaReadValueIdInitialize  (pfOpcUaReadValueIdInitialize != NULL)
	#define EXP_OpcUaReadValueIdInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaReadValueIdInitialize", (RTS_UINTPTR)OpcUaReadValueIdInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaReadValueIdClear(OpcUa_ReadValueId* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAREADVALUEIDCLEAR) (OpcUa_ReadValueId* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAREADVALUEIDCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaReadValueIdClear
	#define EXT_OpcUaReadValueIdClear
	#define GET_OpcUaReadValueIdClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaReadValueIdClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaReadValueIdClear  FALSE
	#define EXP_OpcUaReadValueIdClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaReadValueIdClear
	#define EXT_OpcUaReadValueIdClear
	#define GET_OpcUaReadValueIdClear(fl)  CAL_CMGETAPI( "OpcUaReadValueIdClear" ) 
	#define CAL_OpcUaReadValueIdClear  OpcUaReadValueIdClear
	#define CHK_OpcUaReadValueIdClear  TRUE
	#define EXP_OpcUaReadValueIdClear  CAL_CMEXPAPI( "OpcUaReadValueIdClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaReadValueIdClear
	#define EXT_OpcUaReadValueIdClear
	#define GET_OpcUaReadValueIdClear(fl)  CAL_CMGETAPI( "OpcUaReadValueIdClear" ) 
	#define CAL_OpcUaReadValueIdClear  OpcUaReadValueIdClear
	#define CHK_OpcUaReadValueIdClear  TRUE
	#define EXP_OpcUaReadValueIdClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaReadValueIdClear", (RTS_UINTPTR)OpcUaReadValueIdClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaReadValueIdClear
	#define EXT_CmpOPCUAStackOpcUaReadValueIdClear
	#define GET_CmpOPCUAStackOpcUaReadValueIdClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaReadValueIdClear pICmpOPCUAStack->IOpcUaReadValueIdClear
	#define CHK_CmpOPCUAStackOpcUaReadValueIdClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaReadValueIdClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaReadValueIdClear
	#define EXT_OpcUaReadValueIdClear
	#define GET_OpcUaReadValueIdClear(fl)  CAL_CMGETAPI( "OpcUaReadValueIdClear" ) 
	#define CAL_OpcUaReadValueIdClear pICmpOPCUAStack->IOpcUaReadValueIdClear
	#define CHK_OpcUaReadValueIdClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaReadValueIdClear  CAL_CMEXPAPI( "OpcUaReadValueIdClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaReadValueIdClear  PFOPCUAREADVALUEIDCLEAR pfOpcUaReadValueIdClear;
	#define EXT_OpcUaReadValueIdClear  extern PFOPCUAREADVALUEIDCLEAR pfOpcUaReadValueIdClear;
	#define GET_OpcUaReadValueIdClear(fl)  s_pfCMGetAPI2( "OpcUaReadValueIdClear", (RTS_VOID_FCTPTR *)&pfOpcUaReadValueIdClear, (fl), 0, 0)
	#define CAL_OpcUaReadValueIdClear  pfOpcUaReadValueIdClear
	#define CHK_OpcUaReadValueIdClear  (pfOpcUaReadValueIdClear != NULL)
	#define EXP_OpcUaReadValueIdClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaReadValueIdClear", (RTS_UINTPTR)OpcUaReadValueIdClear, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaReadValueIdCopyTo(const OpcUa_ReadValueId* pSource, OpcUa_ReadValueId* pDestination);
typedef OpcUa_StatusCode (CDECL * PFOPCUAREADVALUEIDCOPYTO) (const OpcUa_ReadValueId* pSource, OpcUa_ReadValueId* pDestination);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAREADVALUEIDCOPYTO_NOTIMPLEMENTED)
	#define USE_OpcUaReadValueIdCopyTo
	#define EXT_OpcUaReadValueIdCopyTo
	#define GET_OpcUaReadValueIdCopyTo(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaReadValueIdCopyTo(p0,p1)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaReadValueIdCopyTo  FALSE
	#define EXP_OpcUaReadValueIdCopyTo  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaReadValueIdCopyTo
	#define EXT_OpcUaReadValueIdCopyTo
	#define GET_OpcUaReadValueIdCopyTo(fl)  CAL_CMGETAPI( "OpcUaReadValueIdCopyTo" ) 
	#define CAL_OpcUaReadValueIdCopyTo  OpcUaReadValueIdCopyTo
	#define CHK_OpcUaReadValueIdCopyTo  TRUE
	#define EXP_OpcUaReadValueIdCopyTo  CAL_CMEXPAPI( "OpcUaReadValueIdCopyTo" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaReadValueIdCopyTo
	#define EXT_OpcUaReadValueIdCopyTo
	#define GET_OpcUaReadValueIdCopyTo(fl)  CAL_CMGETAPI( "OpcUaReadValueIdCopyTo" ) 
	#define CAL_OpcUaReadValueIdCopyTo  OpcUaReadValueIdCopyTo
	#define CHK_OpcUaReadValueIdCopyTo  TRUE
	#define EXP_OpcUaReadValueIdCopyTo  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaReadValueIdCopyTo", (RTS_UINTPTR)OpcUaReadValueIdCopyTo, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaReadValueIdCopyTo
	#define EXT_CmpOPCUAStackOpcUaReadValueIdCopyTo
	#define GET_CmpOPCUAStackOpcUaReadValueIdCopyTo  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaReadValueIdCopyTo pICmpOPCUAStack->IOpcUaReadValueIdCopyTo
	#define CHK_CmpOPCUAStackOpcUaReadValueIdCopyTo (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaReadValueIdCopyTo  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaReadValueIdCopyTo
	#define EXT_OpcUaReadValueIdCopyTo
	#define GET_OpcUaReadValueIdCopyTo(fl)  CAL_CMGETAPI( "OpcUaReadValueIdCopyTo" ) 
	#define CAL_OpcUaReadValueIdCopyTo pICmpOPCUAStack->IOpcUaReadValueIdCopyTo
	#define CHK_OpcUaReadValueIdCopyTo (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaReadValueIdCopyTo  CAL_CMEXPAPI( "OpcUaReadValueIdCopyTo" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaReadValueIdCopyTo  PFOPCUAREADVALUEIDCOPYTO pfOpcUaReadValueIdCopyTo;
	#define EXT_OpcUaReadValueIdCopyTo  extern PFOPCUAREADVALUEIDCOPYTO pfOpcUaReadValueIdCopyTo;
	#define GET_OpcUaReadValueIdCopyTo(fl)  s_pfCMGetAPI2( "OpcUaReadValueIdCopyTo", (RTS_VOID_FCTPTR *)&pfOpcUaReadValueIdCopyTo, (fl), 0, 0)
	#define CAL_OpcUaReadValueIdCopyTo  pfOpcUaReadValueIdCopyTo
	#define CHK_OpcUaReadValueIdCopyTo  (pfOpcUaReadValueIdCopyTo != NULL)
	#define EXP_OpcUaReadValueIdCopyTo  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaReadValueIdCopyTo", (RTS_UINTPTR)OpcUaReadValueIdCopyTo, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaBrowseDescriptionInitialize(OpcUa_BrowseDescription* pValue);
typedef OpcUa_Void (CDECL * PFOPCUABROWSEDESCRIPTIONINITIALIZE) (OpcUa_BrowseDescription* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUABROWSEDESCRIPTIONINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaBrowseDescriptionInitialize
	#define EXT_OpcUaBrowseDescriptionInitialize
	#define GET_OpcUaBrowseDescriptionInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaBrowseDescriptionInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaBrowseDescriptionInitialize  FALSE
	#define EXP_OpcUaBrowseDescriptionInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaBrowseDescriptionInitialize
	#define EXT_OpcUaBrowseDescriptionInitialize
	#define GET_OpcUaBrowseDescriptionInitialize(fl)  CAL_CMGETAPI( "OpcUaBrowseDescriptionInitialize" ) 
	#define CAL_OpcUaBrowseDescriptionInitialize  OpcUaBrowseDescriptionInitialize
	#define CHK_OpcUaBrowseDescriptionInitialize  TRUE
	#define EXP_OpcUaBrowseDescriptionInitialize  CAL_CMEXPAPI( "OpcUaBrowseDescriptionInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaBrowseDescriptionInitialize
	#define EXT_OpcUaBrowseDescriptionInitialize
	#define GET_OpcUaBrowseDescriptionInitialize(fl)  CAL_CMGETAPI( "OpcUaBrowseDescriptionInitialize" ) 
	#define CAL_OpcUaBrowseDescriptionInitialize  OpcUaBrowseDescriptionInitialize
	#define CHK_OpcUaBrowseDescriptionInitialize  TRUE
	#define EXP_OpcUaBrowseDescriptionInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowseDescriptionInitialize", (RTS_UINTPTR)OpcUaBrowseDescriptionInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaBrowseDescriptionInitialize
	#define EXT_CmpOPCUAStackOpcUaBrowseDescriptionInitialize
	#define GET_CmpOPCUAStackOpcUaBrowseDescriptionInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaBrowseDescriptionInitialize pICmpOPCUAStack->IOpcUaBrowseDescriptionInitialize
	#define CHK_CmpOPCUAStackOpcUaBrowseDescriptionInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaBrowseDescriptionInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaBrowseDescriptionInitialize
	#define EXT_OpcUaBrowseDescriptionInitialize
	#define GET_OpcUaBrowseDescriptionInitialize(fl)  CAL_CMGETAPI( "OpcUaBrowseDescriptionInitialize" ) 
	#define CAL_OpcUaBrowseDescriptionInitialize pICmpOPCUAStack->IOpcUaBrowseDescriptionInitialize
	#define CHK_OpcUaBrowseDescriptionInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaBrowseDescriptionInitialize  CAL_CMEXPAPI( "OpcUaBrowseDescriptionInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaBrowseDescriptionInitialize  PFOPCUABROWSEDESCRIPTIONINITIALIZE pfOpcUaBrowseDescriptionInitialize;
	#define EXT_OpcUaBrowseDescriptionInitialize  extern PFOPCUABROWSEDESCRIPTIONINITIALIZE pfOpcUaBrowseDescriptionInitialize;
	#define GET_OpcUaBrowseDescriptionInitialize(fl)  s_pfCMGetAPI2( "OpcUaBrowseDescriptionInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaBrowseDescriptionInitialize, (fl), 0, 0)
	#define CAL_OpcUaBrowseDescriptionInitialize  pfOpcUaBrowseDescriptionInitialize
	#define CHK_OpcUaBrowseDescriptionInitialize  (pfOpcUaBrowseDescriptionInitialize != NULL)
	#define EXP_OpcUaBrowseDescriptionInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowseDescriptionInitialize", (RTS_UINTPTR)OpcUaBrowseDescriptionInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaBrowseDescriptionClear(OpcUa_BrowseDescription* pValue);
typedef OpcUa_Void (CDECL * PFOPCUABROWSEDESCRIPTIONCLEAR) (OpcUa_BrowseDescription* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUABROWSEDESCRIPTIONCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaBrowseDescriptionClear
	#define EXT_OpcUaBrowseDescriptionClear
	#define GET_OpcUaBrowseDescriptionClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaBrowseDescriptionClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaBrowseDescriptionClear  FALSE
	#define EXP_OpcUaBrowseDescriptionClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaBrowseDescriptionClear
	#define EXT_OpcUaBrowseDescriptionClear
	#define GET_OpcUaBrowseDescriptionClear(fl)  CAL_CMGETAPI( "OpcUaBrowseDescriptionClear" ) 
	#define CAL_OpcUaBrowseDescriptionClear  OpcUaBrowseDescriptionClear
	#define CHK_OpcUaBrowseDescriptionClear  TRUE
	#define EXP_OpcUaBrowseDescriptionClear  CAL_CMEXPAPI( "OpcUaBrowseDescriptionClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaBrowseDescriptionClear
	#define EXT_OpcUaBrowseDescriptionClear
	#define GET_OpcUaBrowseDescriptionClear(fl)  CAL_CMGETAPI( "OpcUaBrowseDescriptionClear" ) 
	#define CAL_OpcUaBrowseDescriptionClear  OpcUaBrowseDescriptionClear
	#define CHK_OpcUaBrowseDescriptionClear  TRUE
	#define EXP_OpcUaBrowseDescriptionClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowseDescriptionClear", (RTS_UINTPTR)OpcUaBrowseDescriptionClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaBrowseDescriptionClear
	#define EXT_CmpOPCUAStackOpcUaBrowseDescriptionClear
	#define GET_CmpOPCUAStackOpcUaBrowseDescriptionClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaBrowseDescriptionClear pICmpOPCUAStack->IOpcUaBrowseDescriptionClear
	#define CHK_CmpOPCUAStackOpcUaBrowseDescriptionClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaBrowseDescriptionClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaBrowseDescriptionClear
	#define EXT_OpcUaBrowseDescriptionClear
	#define GET_OpcUaBrowseDescriptionClear(fl)  CAL_CMGETAPI( "OpcUaBrowseDescriptionClear" ) 
	#define CAL_OpcUaBrowseDescriptionClear pICmpOPCUAStack->IOpcUaBrowseDescriptionClear
	#define CHK_OpcUaBrowseDescriptionClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaBrowseDescriptionClear  CAL_CMEXPAPI( "OpcUaBrowseDescriptionClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaBrowseDescriptionClear  PFOPCUABROWSEDESCRIPTIONCLEAR pfOpcUaBrowseDescriptionClear;
	#define EXT_OpcUaBrowseDescriptionClear  extern PFOPCUABROWSEDESCRIPTIONCLEAR pfOpcUaBrowseDescriptionClear;
	#define GET_OpcUaBrowseDescriptionClear(fl)  s_pfCMGetAPI2( "OpcUaBrowseDescriptionClear", (RTS_VOID_FCTPTR *)&pfOpcUaBrowseDescriptionClear, (fl), 0, 0)
	#define CAL_OpcUaBrowseDescriptionClear  pfOpcUaBrowseDescriptionClear
	#define CHK_OpcUaBrowseDescriptionClear  (pfOpcUaBrowseDescriptionClear != NULL)
	#define EXP_OpcUaBrowseDescriptionClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowseDescriptionClear", (RTS_UINTPTR)OpcUaBrowseDescriptionClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaBrowsePathInitialize(OpcUa_BrowsePath* pValue);
typedef OpcUa_Void (CDECL * PFOPCUABROWSEPATHINITIALIZE) (OpcUa_BrowsePath* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUABROWSEPATHINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaBrowsePathInitialize
	#define EXT_OpcUaBrowsePathInitialize
	#define GET_OpcUaBrowsePathInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaBrowsePathInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaBrowsePathInitialize  FALSE
	#define EXP_OpcUaBrowsePathInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaBrowsePathInitialize
	#define EXT_OpcUaBrowsePathInitialize
	#define GET_OpcUaBrowsePathInitialize(fl)  CAL_CMGETAPI( "OpcUaBrowsePathInitialize" ) 
	#define CAL_OpcUaBrowsePathInitialize  OpcUaBrowsePathInitialize
	#define CHK_OpcUaBrowsePathInitialize  TRUE
	#define EXP_OpcUaBrowsePathInitialize  CAL_CMEXPAPI( "OpcUaBrowsePathInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaBrowsePathInitialize
	#define EXT_OpcUaBrowsePathInitialize
	#define GET_OpcUaBrowsePathInitialize(fl)  CAL_CMGETAPI( "OpcUaBrowsePathInitialize" ) 
	#define CAL_OpcUaBrowsePathInitialize  OpcUaBrowsePathInitialize
	#define CHK_OpcUaBrowsePathInitialize  TRUE
	#define EXP_OpcUaBrowsePathInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowsePathInitialize", (RTS_UINTPTR)OpcUaBrowsePathInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaBrowsePathInitialize
	#define EXT_CmpOPCUAStackOpcUaBrowsePathInitialize
	#define GET_CmpOPCUAStackOpcUaBrowsePathInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaBrowsePathInitialize pICmpOPCUAStack->IOpcUaBrowsePathInitialize
	#define CHK_CmpOPCUAStackOpcUaBrowsePathInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaBrowsePathInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaBrowsePathInitialize
	#define EXT_OpcUaBrowsePathInitialize
	#define GET_OpcUaBrowsePathInitialize(fl)  CAL_CMGETAPI( "OpcUaBrowsePathInitialize" ) 
	#define CAL_OpcUaBrowsePathInitialize pICmpOPCUAStack->IOpcUaBrowsePathInitialize
	#define CHK_OpcUaBrowsePathInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaBrowsePathInitialize  CAL_CMEXPAPI( "OpcUaBrowsePathInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaBrowsePathInitialize  PFOPCUABROWSEPATHINITIALIZE pfOpcUaBrowsePathInitialize;
	#define EXT_OpcUaBrowsePathInitialize  extern PFOPCUABROWSEPATHINITIALIZE pfOpcUaBrowsePathInitialize;
	#define GET_OpcUaBrowsePathInitialize(fl)  s_pfCMGetAPI2( "OpcUaBrowsePathInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaBrowsePathInitialize, (fl), 0, 0)
	#define CAL_OpcUaBrowsePathInitialize  pfOpcUaBrowsePathInitialize
	#define CHK_OpcUaBrowsePathInitialize  (pfOpcUaBrowsePathInitialize != NULL)
	#define EXP_OpcUaBrowsePathInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowsePathInitialize", (RTS_UINTPTR)OpcUaBrowsePathInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaBrowsePathClear(OpcUa_BrowsePath* pValue);
typedef OpcUa_Void (CDECL * PFOPCUABROWSEPATHCLEAR) (OpcUa_BrowsePath* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUABROWSEPATHCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaBrowsePathClear
	#define EXT_OpcUaBrowsePathClear
	#define GET_OpcUaBrowsePathClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaBrowsePathClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaBrowsePathClear  FALSE
	#define EXP_OpcUaBrowsePathClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaBrowsePathClear
	#define EXT_OpcUaBrowsePathClear
	#define GET_OpcUaBrowsePathClear(fl)  CAL_CMGETAPI( "OpcUaBrowsePathClear" ) 
	#define CAL_OpcUaBrowsePathClear  OpcUaBrowsePathClear
	#define CHK_OpcUaBrowsePathClear  TRUE
	#define EXP_OpcUaBrowsePathClear  CAL_CMEXPAPI( "OpcUaBrowsePathClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaBrowsePathClear
	#define EXT_OpcUaBrowsePathClear
	#define GET_OpcUaBrowsePathClear(fl)  CAL_CMGETAPI( "OpcUaBrowsePathClear" ) 
	#define CAL_OpcUaBrowsePathClear  OpcUaBrowsePathClear
	#define CHK_OpcUaBrowsePathClear  TRUE
	#define EXP_OpcUaBrowsePathClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowsePathClear", (RTS_UINTPTR)OpcUaBrowsePathClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaBrowsePathClear
	#define EXT_CmpOPCUAStackOpcUaBrowsePathClear
	#define GET_CmpOPCUAStackOpcUaBrowsePathClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaBrowsePathClear pICmpOPCUAStack->IOpcUaBrowsePathClear
	#define CHK_CmpOPCUAStackOpcUaBrowsePathClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaBrowsePathClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaBrowsePathClear
	#define EXT_OpcUaBrowsePathClear
	#define GET_OpcUaBrowsePathClear(fl)  CAL_CMGETAPI( "OpcUaBrowsePathClear" ) 
	#define CAL_OpcUaBrowsePathClear pICmpOPCUAStack->IOpcUaBrowsePathClear
	#define CHK_OpcUaBrowsePathClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaBrowsePathClear  CAL_CMEXPAPI( "OpcUaBrowsePathClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaBrowsePathClear  PFOPCUABROWSEPATHCLEAR pfOpcUaBrowsePathClear;
	#define EXT_OpcUaBrowsePathClear  extern PFOPCUABROWSEPATHCLEAR pfOpcUaBrowsePathClear;
	#define GET_OpcUaBrowsePathClear(fl)  s_pfCMGetAPI2( "OpcUaBrowsePathClear", (RTS_VOID_FCTPTR *)&pfOpcUaBrowsePathClear, (fl), 0, 0)
	#define CAL_OpcUaBrowsePathClear  pfOpcUaBrowsePathClear
	#define CHK_OpcUaBrowsePathClear  (pfOpcUaBrowsePathClear != NULL)
	#define EXP_OpcUaBrowsePathClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowsePathClear", (RTS_UINTPTR)OpcUaBrowsePathClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaStatusChangeNotificationInitialize(OpcUa_StatusChangeNotification* pValue);
typedef OpcUa_Void (CDECL * PFOPCUASTATUSCHANGENOTIFICATIONINITIALIZE) (OpcUa_StatusChangeNotification* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASTATUSCHANGENOTIFICATIONINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaStatusChangeNotificationInitialize
	#define EXT_OpcUaStatusChangeNotificationInitialize
	#define GET_OpcUaStatusChangeNotificationInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaStatusChangeNotificationInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaStatusChangeNotificationInitialize  FALSE
	#define EXP_OpcUaStatusChangeNotificationInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaStatusChangeNotificationInitialize
	#define EXT_OpcUaStatusChangeNotificationInitialize
	#define GET_OpcUaStatusChangeNotificationInitialize(fl)  CAL_CMGETAPI( "OpcUaStatusChangeNotificationInitialize" ) 
	#define CAL_OpcUaStatusChangeNotificationInitialize  OpcUaStatusChangeNotificationInitialize
	#define CHK_OpcUaStatusChangeNotificationInitialize  TRUE
	#define EXP_OpcUaStatusChangeNotificationInitialize  CAL_CMEXPAPI( "OpcUaStatusChangeNotificationInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaStatusChangeNotificationInitialize
	#define EXT_OpcUaStatusChangeNotificationInitialize
	#define GET_OpcUaStatusChangeNotificationInitialize(fl)  CAL_CMGETAPI( "OpcUaStatusChangeNotificationInitialize" ) 
	#define CAL_OpcUaStatusChangeNotificationInitialize  OpcUaStatusChangeNotificationInitialize
	#define CHK_OpcUaStatusChangeNotificationInitialize  TRUE
	#define EXP_OpcUaStatusChangeNotificationInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStatusChangeNotificationInitialize", (RTS_UINTPTR)OpcUaStatusChangeNotificationInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaStatusChangeNotificationInitialize
	#define EXT_CmpOPCUAStackOpcUaStatusChangeNotificationInitialize
	#define GET_CmpOPCUAStackOpcUaStatusChangeNotificationInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaStatusChangeNotificationInitialize pICmpOPCUAStack->IOpcUaStatusChangeNotificationInitialize
	#define CHK_CmpOPCUAStackOpcUaStatusChangeNotificationInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaStatusChangeNotificationInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaStatusChangeNotificationInitialize
	#define EXT_OpcUaStatusChangeNotificationInitialize
	#define GET_OpcUaStatusChangeNotificationInitialize(fl)  CAL_CMGETAPI( "OpcUaStatusChangeNotificationInitialize" ) 
	#define CAL_OpcUaStatusChangeNotificationInitialize pICmpOPCUAStack->IOpcUaStatusChangeNotificationInitialize
	#define CHK_OpcUaStatusChangeNotificationInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaStatusChangeNotificationInitialize  CAL_CMEXPAPI( "OpcUaStatusChangeNotificationInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaStatusChangeNotificationInitialize  PFOPCUASTATUSCHANGENOTIFICATIONINITIALIZE pfOpcUaStatusChangeNotificationInitialize;
	#define EXT_OpcUaStatusChangeNotificationInitialize  extern PFOPCUASTATUSCHANGENOTIFICATIONINITIALIZE pfOpcUaStatusChangeNotificationInitialize;
	#define GET_OpcUaStatusChangeNotificationInitialize(fl)  s_pfCMGetAPI2( "OpcUaStatusChangeNotificationInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaStatusChangeNotificationInitialize, (fl), 0, 0)
	#define CAL_OpcUaStatusChangeNotificationInitialize  pfOpcUaStatusChangeNotificationInitialize
	#define CHK_OpcUaStatusChangeNotificationInitialize  (pfOpcUaStatusChangeNotificationInitialize != NULL)
	#define EXP_OpcUaStatusChangeNotificationInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStatusChangeNotificationInitialize", (RTS_UINTPTR)OpcUaStatusChangeNotificationInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaStatusChangeNotificationClear(OpcUa_StatusChangeNotification* pValue);
typedef OpcUa_Void (CDECL * PFOPCUASTATUSCHANGENOTIFICATIONCLEAR) (OpcUa_StatusChangeNotification* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASTATUSCHANGENOTIFICATIONCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaStatusChangeNotificationClear
	#define EXT_OpcUaStatusChangeNotificationClear
	#define GET_OpcUaStatusChangeNotificationClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaStatusChangeNotificationClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaStatusChangeNotificationClear  FALSE
	#define EXP_OpcUaStatusChangeNotificationClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaStatusChangeNotificationClear
	#define EXT_OpcUaStatusChangeNotificationClear
	#define GET_OpcUaStatusChangeNotificationClear(fl)  CAL_CMGETAPI( "OpcUaStatusChangeNotificationClear" ) 
	#define CAL_OpcUaStatusChangeNotificationClear  OpcUaStatusChangeNotificationClear
	#define CHK_OpcUaStatusChangeNotificationClear  TRUE
	#define EXP_OpcUaStatusChangeNotificationClear  CAL_CMEXPAPI( "OpcUaStatusChangeNotificationClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaStatusChangeNotificationClear
	#define EXT_OpcUaStatusChangeNotificationClear
	#define GET_OpcUaStatusChangeNotificationClear(fl)  CAL_CMGETAPI( "OpcUaStatusChangeNotificationClear" ) 
	#define CAL_OpcUaStatusChangeNotificationClear  OpcUaStatusChangeNotificationClear
	#define CHK_OpcUaStatusChangeNotificationClear  TRUE
	#define EXP_OpcUaStatusChangeNotificationClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStatusChangeNotificationClear", (RTS_UINTPTR)OpcUaStatusChangeNotificationClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaStatusChangeNotificationClear
	#define EXT_CmpOPCUAStackOpcUaStatusChangeNotificationClear
	#define GET_CmpOPCUAStackOpcUaStatusChangeNotificationClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaStatusChangeNotificationClear pICmpOPCUAStack->IOpcUaStatusChangeNotificationClear
	#define CHK_CmpOPCUAStackOpcUaStatusChangeNotificationClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaStatusChangeNotificationClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaStatusChangeNotificationClear
	#define EXT_OpcUaStatusChangeNotificationClear
	#define GET_OpcUaStatusChangeNotificationClear(fl)  CAL_CMGETAPI( "OpcUaStatusChangeNotificationClear" ) 
	#define CAL_OpcUaStatusChangeNotificationClear pICmpOPCUAStack->IOpcUaStatusChangeNotificationClear
	#define CHK_OpcUaStatusChangeNotificationClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaStatusChangeNotificationClear  CAL_CMEXPAPI( "OpcUaStatusChangeNotificationClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaStatusChangeNotificationClear  PFOPCUASTATUSCHANGENOTIFICATIONCLEAR pfOpcUaStatusChangeNotificationClear;
	#define EXT_OpcUaStatusChangeNotificationClear  extern PFOPCUASTATUSCHANGENOTIFICATIONCLEAR pfOpcUaStatusChangeNotificationClear;
	#define GET_OpcUaStatusChangeNotificationClear(fl)  s_pfCMGetAPI2( "OpcUaStatusChangeNotificationClear", (RTS_VOID_FCTPTR *)&pfOpcUaStatusChangeNotificationClear, (fl), 0, 0)
	#define CAL_OpcUaStatusChangeNotificationClear  pfOpcUaStatusChangeNotificationClear
	#define CHK_OpcUaStatusChangeNotificationClear  (pfOpcUaStatusChangeNotificationClear != NULL)
	#define EXP_OpcUaStatusChangeNotificationClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStatusChangeNotificationClear", (RTS_UINTPTR)OpcUaStatusChangeNotificationClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaNotificationMessageInitialize(OpcUa_NotificationMessage* pValue);
typedef OpcUa_Void (CDECL * PFOPCUANOTIFICATIONMESSAGEINITIALIZE) (OpcUa_NotificationMessage* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUANOTIFICATIONMESSAGEINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaNotificationMessageInitialize
	#define EXT_OpcUaNotificationMessageInitialize
	#define GET_OpcUaNotificationMessageInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaNotificationMessageInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaNotificationMessageInitialize  FALSE
	#define EXP_OpcUaNotificationMessageInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaNotificationMessageInitialize
	#define EXT_OpcUaNotificationMessageInitialize
	#define GET_OpcUaNotificationMessageInitialize(fl)  CAL_CMGETAPI( "OpcUaNotificationMessageInitialize" ) 
	#define CAL_OpcUaNotificationMessageInitialize  OpcUaNotificationMessageInitialize
	#define CHK_OpcUaNotificationMessageInitialize  TRUE
	#define EXP_OpcUaNotificationMessageInitialize  CAL_CMEXPAPI( "OpcUaNotificationMessageInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaNotificationMessageInitialize
	#define EXT_OpcUaNotificationMessageInitialize
	#define GET_OpcUaNotificationMessageInitialize(fl)  CAL_CMGETAPI( "OpcUaNotificationMessageInitialize" ) 
	#define CAL_OpcUaNotificationMessageInitialize  OpcUaNotificationMessageInitialize
	#define CHK_OpcUaNotificationMessageInitialize  TRUE
	#define EXP_OpcUaNotificationMessageInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaNotificationMessageInitialize", (RTS_UINTPTR)OpcUaNotificationMessageInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaNotificationMessageInitialize
	#define EXT_CmpOPCUAStackOpcUaNotificationMessageInitialize
	#define GET_CmpOPCUAStackOpcUaNotificationMessageInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaNotificationMessageInitialize pICmpOPCUAStack->IOpcUaNotificationMessageInitialize
	#define CHK_CmpOPCUAStackOpcUaNotificationMessageInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaNotificationMessageInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaNotificationMessageInitialize
	#define EXT_OpcUaNotificationMessageInitialize
	#define GET_OpcUaNotificationMessageInitialize(fl)  CAL_CMGETAPI( "OpcUaNotificationMessageInitialize" ) 
	#define CAL_OpcUaNotificationMessageInitialize pICmpOPCUAStack->IOpcUaNotificationMessageInitialize
	#define CHK_OpcUaNotificationMessageInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaNotificationMessageInitialize  CAL_CMEXPAPI( "OpcUaNotificationMessageInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaNotificationMessageInitialize  PFOPCUANOTIFICATIONMESSAGEINITIALIZE pfOpcUaNotificationMessageInitialize;
	#define EXT_OpcUaNotificationMessageInitialize  extern PFOPCUANOTIFICATIONMESSAGEINITIALIZE pfOpcUaNotificationMessageInitialize;
	#define GET_OpcUaNotificationMessageInitialize(fl)  s_pfCMGetAPI2( "OpcUaNotificationMessageInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaNotificationMessageInitialize, (fl), 0, 0)
	#define CAL_OpcUaNotificationMessageInitialize  pfOpcUaNotificationMessageInitialize
	#define CHK_OpcUaNotificationMessageInitialize  (pfOpcUaNotificationMessageInitialize != NULL)
	#define EXP_OpcUaNotificationMessageInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaNotificationMessageInitialize", (RTS_UINTPTR)OpcUaNotificationMessageInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaNotificationMessageClear(OpcUa_NotificationMessage* pValue);
typedef OpcUa_Void (CDECL * PFOPCUANOTIFICATIONMESSAGECLEAR) (OpcUa_NotificationMessage* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUANOTIFICATIONMESSAGECLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaNotificationMessageClear
	#define EXT_OpcUaNotificationMessageClear
	#define GET_OpcUaNotificationMessageClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaNotificationMessageClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaNotificationMessageClear  FALSE
	#define EXP_OpcUaNotificationMessageClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaNotificationMessageClear
	#define EXT_OpcUaNotificationMessageClear
	#define GET_OpcUaNotificationMessageClear(fl)  CAL_CMGETAPI( "OpcUaNotificationMessageClear" ) 
	#define CAL_OpcUaNotificationMessageClear  OpcUaNotificationMessageClear
	#define CHK_OpcUaNotificationMessageClear  TRUE
	#define EXP_OpcUaNotificationMessageClear  CAL_CMEXPAPI( "OpcUaNotificationMessageClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaNotificationMessageClear
	#define EXT_OpcUaNotificationMessageClear
	#define GET_OpcUaNotificationMessageClear(fl)  CAL_CMGETAPI( "OpcUaNotificationMessageClear" ) 
	#define CAL_OpcUaNotificationMessageClear  OpcUaNotificationMessageClear
	#define CHK_OpcUaNotificationMessageClear  TRUE
	#define EXP_OpcUaNotificationMessageClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaNotificationMessageClear", (RTS_UINTPTR)OpcUaNotificationMessageClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaNotificationMessageClear
	#define EXT_CmpOPCUAStackOpcUaNotificationMessageClear
	#define GET_CmpOPCUAStackOpcUaNotificationMessageClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaNotificationMessageClear pICmpOPCUAStack->IOpcUaNotificationMessageClear
	#define CHK_CmpOPCUAStackOpcUaNotificationMessageClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaNotificationMessageClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaNotificationMessageClear
	#define EXT_OpcUaNotificationMessageClear
	#define GET_OpcUaNotificationMessageClear(fl)  CAL_CMGETAPI( "OpcUaNotificationMessageClear" ) 
	#define CAL_OpcUaNotificationMessageClear pICmpOPCUAStack->IOpcUaNotificationMessageClear
	#define CHK_OpcUaNotificationMessageClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaNotificationMessageClear  CAL_CMEXPAPI( "OpcUaNotificationMessageClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaNotificationMessageClear  PFOPCUANOTIFICATIONMESSAGECLEAR pfOpcUaNotificationMessageClear;
	#define EXT_OpcUaNotificationMessageClear  extern PFOPCUANOTIFICATIONMESSAGECLEAR pfOpcUaNotificationMessageClear;
	#define GET_OpcUaNotificationMessageClear(fl)  s_pfCMGetAPI2( "OpcUaNotificationMessageClear", (RTS_VOID_FCTPTR *)&pfOpcUaNotificationMessageClear, (fl), 0, 0)
	#define CAL_OpcUaNotificationMessageClear  pfOpcUaNotificationMessageClear
	#define CHK_OpcUaNotificationMessageClear  (pfOpcUaNotificationMessageClear != NULL)
	#define EXP_OpcUaNotificationMessageClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaNotificationMessageClear", (RTS_UINTPTR)OpcUaNotificationMessageClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaPublishResponseInitialize(OpcUa_PublishResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAPUBLISHRESPONSEINITIALIZE) (OpcUa_PublishResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAPUBLISHRESPONSEINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaPublishResponseInitialize
	#define EXT_OpcUaPublishResponseInitialize
	#define GET_OpcUaPublishResponseInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaPublishResponseInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaPublishResponseInitialize  FALSE
	#define EXP_OpcUaPublishResponseInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaPublishResponseInitialize
	#define EXT_OpcUaPublishResponseInitialize
	#define GET_OpcUaPublishResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaPublishResponseInitialize" ) 
	#define CAL_OpcUaPublishResponseInitialize  OpcUaPublishResponseInitialize
	#define CHK_OpcUaPublishResponseInitialize  TRUE
	#define EXP_OpcUaPublishResponseInitialize  CAL_CMEXPAPI( "OpcUaPublishResponseInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaPublishResponseInitialize
	#define EXT_OpcUaPublishResponseInitialize
	#define GET_OpcUaPublishResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaPublishResponseInitialize" ) 
	#define CAL_OpcUaPublishResponseInitialize  OpcUaPublishResponseInitialize
	#define CHK_OpcUaPublishResponseInitialize  TRUE
	#define EXP_OpcUaPublishResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaPublishResponseInitialize", (RTS_UINTPTR)OpcUaPublishResponseInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaPublishResponseInitialize
	#define EXT_CmpOPCUAStackOpcUaPublishResponseInitialize
	#define GET_CmpOPCUAStackOpcUaPublishResponseInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaPublishResponseInitialize pICmpOPCUAStack->IOpcUaPublishResponseInitialize
	#define CHK_CmpOPCUAStackOpcUaPublishResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaPublishResponseInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaPublishResponseInitialize
	#define EXT_OpcUaPublishResponseInitialize
	#define GET_OpcUaPublishResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaPublishResponseInitialize" ) 
	#define CAL_OpcUaPublishResponseInitialize pICmpOPCUAStack->IOpcUaPublishResponseInitialize
	#define CHK_OpcUaPublishResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaPublishResponseInitialize  CAL_CMEXPAPI( "OpcUaPublishResponseInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaPublishResponseInitialize  PFOPCUAPUBLISHRESPONSEINITIALIZE pfOpcUaPublishResponseInitialize;
	#define EXT_OpcUaPublishResponseInitialize  extern PFOPCUAPUBLISHRESPONSEINITIALIZE pfOpcUaPublishResponseInitialize;
	#define GET_OpcUaPublishResponseInitialize(fl)  s_pfCMGetAPI2( "OpcUaPublishResponseInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaPublishResponseInitialize, (fl), 0, 0)
	#define CAL_OpcUaPublishResponseInitialize  pfOpcUaPublishResponseInitialize
	#define CHK_OpcUaPublishResponseInitialize  (pfOpcUaPublishResponseInitialize != NULL)
	#define EXP_OpcUaPublishResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaPublishResponseInitialize", (RTS_UINTPTR)OpcUaPublishResponseInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaPublishResponseClear(OpcUa_PublishResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAPUBLISHRESPONSECLEAR) (OpcUa_PublishResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAPUBLISHRESPONSECLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaPublishResponseClear
	#define EXT_OpcUaPublishResponseClear
	#define GET_OpcUaPublishResponseClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaPublishResponseClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaPublishResponseClear  FALSE
	#define EXP_OpcUaPublishResponseClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaPublishResponseClear
	#define EXT_OpcUaPublishResponseClear
	#define GET_OpcUaPublishResponseClear(fl)  CAL_CMGETAPI( "OpcUaPublishResponseClear" ) 
	#define CAL_OpcUaPublishResponseClear  OpcUaPublishResponseClear
	#define CHK_OpcUaPublishResponseClear  TRUE
	#define EXP_OpcUaPublishResponseClear  CAL_CMEXPAPI( "OpcUaPublishResponseClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaPublishResponseClear
	#define EXT_OpcUaPublishResponseClear
	#define GET_OpcUaPublishResponseClear(fl)  CAL_CMGETAPI( "OpcUaPublishResponseClear" ) 
	#define CAL_OpcUaPublishResponseClear  OpcUaPublishResponseClear
	#define CHK_OpcUaPublishResponseClear  TRUE
	#define EXP_OpcUaPublishResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaPublishResponseClear", (RTS_UINTPTR)OpcUaPublishResponseClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaPublishResponseClear
	#define EXT_CmpOPCUAStackOpcUaPublishResponseClear
	#define GET_CmpOPCUAStackOpcUaPublishResponseClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaPublishResponseClear pICmpOPCUAStack->IOpcUaPublishResponseClear
	#define CHK_CmpOPCUAStackOpcUaPublishResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaPublishResponseClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaPublishResponseClear
	#define EXT_OpcUaPublishResponseClear
	#define GET_OpcUaPublishResponseClear(fl)  CAL_CMGETAPI( "OpcUaPublishResponseClear" ) 
	#define CAL_OpcUaPublishResponseClear pICmpOPCUAStack->IOpcUaPublishResponseClear
	#define CHK_OpcUaPublishResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaPublishResponseClear  CAL_CMEXPAPI( "OpcUaPublishResponseClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaPublishResponseClear  PFOPCUAPUBLISHRESPONSECLEAR pfOpcUaPublishResponseClear;
	#define EXT_OpcUaPublishResponseClear  extern PFOPCUAPUBLISHRESPONSECLEAR pfOpcUaPublishResponseClear;
	#define GET_OpcUaPublishResponseClear(fl)  s_pfCMGetAPI2( "OpcUaPublishResponseClear", (RTS_VOID_FCTPTR *)&pfOpcUaPublishResponseClear, (fl), 0, 0)
	#define CAL_OpcUaPublishResponseClear  pfOpcUaPublishResponseClear
	#define CHK_OpcUaPublishResponseClear  (pfOpcUaPublishResponseClear != NULL)
	#define EXP_OpcUaPublishResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaPublishResponseClear", (RTS_UINTPTR)OpcUaPublishResponseClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaDataChangeNotificationInitialize(OpcUa_DataChangeNotification* pValue);
typedef OpcUa_Void (CDECL * PFOPCUADATACHANGENOTIFICATIONINITIALIZE) (OpcUa_DataChangeNotification* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUADATACHANGENOTIFICATIONINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaDataChangeNotificationInitialize
	#define EXT_OpcUaDataChangeNotificationInitialize
	#define GET_OpcUaDataChangeNotificationInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaDataChangeNotificationInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaDataChangeNotificationInitialize  FALSE
	#define EXP_OpcUaDataChangeNotificationInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaDataChangeNotificationInitialize
	#define EXT_OpcUaDataChangeNotificationInitialize
	#define GET_OpcUaDataChangeNotificationInitialize(fl)  CAL_CMGETAPI( "OpcUaDataChangeNotificationInitialize" ) 
	#define CAL_OpcUaDataChangeNotificationInitialize  OpcUaDataChangeNotificationInitialize
	#define CHK_OpcUaDataChangeNotificationInitialize  TRUE
	#define EXP_OpcUaDataChangeNotificationInitialize  CAL_CMEXPAPI( "OpcUaDataChangeNotificationInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaDataChangeNotificationInitialize
	#define EXT_OpcUaDataChangeNotificationInitialize
	#define GET_OpcUaDataChangeNotificationInitialize(fl)  CAL_CMGETAPI( "OpcUaDataChangeNotificationInitialize" ) 
	#define CAL_OpcUaDataChangeNotificationInitialize  OpcUaDataChangeNotificationInitialize
	#define CHK_OpcUaDataChangeNotificationInitialize  TRUE
	#define EXP_OpcUaDataChangeNotificationInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDataChangeNotificationInitialize", (RTS_UINTPTR)OpcUaDataChangeNotificationInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaDataChangeNotificationInitialize
	#define EXT_CmpOPCUAStackOpcUaDataChangeNotificationInitialize
	#define GET_CmpOPCUAStackOpcUaDataChangeNotificationInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaDataChangeNotificationInitialize pICmpOPCUAStack->IOpcUaDataChangeNotificationInitialize
	#define CHK_CmpOPCUAStackOpcUaDataChangeNotificationInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaDataChangeNotificationInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaDataChangeNotificationInitialize
	#define EXT_OpcUaDataChangeNotificationInitialize
	#define GET_OpcUaDataChangeNotificationInitialize(fl)  CAL_CMGETAPI( "OpcUaDataChangeNotificationInitialize" ) 
	#define CAL_OpcUaDataChangeNotificationInitialize pICmpOPCUAStack->IOpcUaDataChangeNotificationInitialize
	#define CHK_OpcUaDataChangeNotificationInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaDataChangeNotificationInitialize  CAL_CMEXPAPI( "OpcUaDataChangeNotificationInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaDataChangeNotificationInitialize  PFOPCUADATACHANGENOTIFICATIONINITIALIZE pfOpcUaDataChangeNotificationInitialize;
	#define EXT_OpcUaDataChangeNotificationInitialize  extern PFOPCUADATACHANGENOTIFICATIONINITIALIZE pfOpcUaDataChangeNotificationInitialize;
	#define GET_OpcUaDataChangeNotificationInitialize(fl)  s_pfCMGetAPI2( "OpcUaDataChangeNotificationInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaDataChangeNotificationInitialize, (fl), 0, 0)
	#define CAL_OpcUaDataChangeNotificationInitialize  pfOpcUaDataChangeNotificationInitialize
	#define CHK_OpcUaDataChangeNotificationInitialize  (pfOpcUaDataChangeNotificationInitialize != NULL)
	#define EXP_OpcUaDataChangeNotificationInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDataChangeNotificationInitialize", (RTS_UINTPTR)OpcUaDataChangeNotificationInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaDataChangeNotificationClear(OpcUa_DataChangeNotification* pValue);
typedef OpcUa_Void (CDECL * PFOPCUADATACHANGENOTIFICATIONCLEAR) (OpcUa_DataChangeNotification* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUADATACHANGENOTIFICATIONCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaDataChangeNotificationClear
	#define EXT_OpcUaDataChangeNotificationClear
	#define GET_OpcUaDataChangeNotificationClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaDataChangeNotificationClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaDataChangeNotificationClear  FALSE
	#define EXP_OpcUaDataChangeNotificationClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaDataChangeNotificationClear
	#define EXT_OpcUaDataChangeNotificationClear
	#define GET_OpcUaDataChangeNotificationClear(fl)  CAL_CMGETAPI( "OpcUaDataChangeNotificationClear" ) 
	#define CAL_OpcUaDataChangeNotificationClear  OpcUaDataChangeNotificationClear
	#define CHK_OpcUaDataChangeNotificationClear  TRUE
	#define EXP_OpcUaDataChangeNotificationClear  CAL_CMEXPAPI( "OpcUaDataChangeNotificationClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaDataChangeNotificationClear
	#define EXT_OpcUaDataChangeNotificationClear
	#define GET_OpcUaDataChangeNotificationClear(fl)  CAL_CMGETAPI( "OpcUaDataChangeNotificationClear" ) 
	#define CAL_OpcUaDataChangeNotificationClear  OpcUaDataChangeNotificationClear
	#define CHK_OpcUaDataChangeNotificationClear  TRUE
	#define EXP_OpcUaDataChangeNotificationClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDataChangeNotificationClear", (RTS_UINTPTR)OpcUaDataChangeNotificationClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaDataChangeNotificationClear
	#define EXT_CmpOPCUAStackOpcUaDataChangeNotificationClear
	#define GET_CmpOPCUAStackOpcUaDataChangeNotificationClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaDataChangeNotificationClear pICmpOPCUAStack->IOpcUaDataChangeNotificationClear
	#define CHK_CmpOPCUAStackOpcUaDataChangeNotificationClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaDataChangeNotificationClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaDataChangeNotificationClear
	#define EXT_OpcUaDataChangeNotificationClear
	#define GET_OpcUaDataChangeNotificationClear(fl)  CAL_CMGETAPI( "OpcUaDataChangeNotificationClear" ) 
	#define CAL_OpcUaDataChangeNotificationClear pICmpOPCUAStack->IOpcUaDataChangeNotificationClear
	#define CHK_OpcUaDataChangeNotificationClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaDataChangeNotificationClear  CAL_CMEXPAPI( "OpcUaDataChangeNotificationClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaDataChangeNotificationClear  PFOPCUADATACHANGENOTIFICATIONCLEAR pfOpcUaDataChangeNotificationClear;
	#define EXT_OpcUaDataChangeNotificationClear  extern PFOPCUADATACHANGENOTIFICATIONCLEAR pfOpcUaDataChangeNotificationClear;
	#define GET_OpcUaDataChangeNotificationClear(fl)  s_pfCMGetAPI2( "OpcUaDataChangeNotificationClear", (RTS_VOID_FCTPTR *)&pfOpcUaDataChangeNotificationClear, (fl), 0, 0)
	#define CAL_OpcUaDataChangeNotificationClear  pfOpcUaDataChangeNotificationClear
	#define CHK_OpcUaDataChangeNotificationClear  (pfOpcUaDataChangeNotificationClear != NULL)
	#define EXP_OpcUaDataChangeNotificationClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDataChangeNotificationClear", (RTS_UINTPTR)OpcUaDataChangeNotificationClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaBrowseResultInitialize(OpcUa_BrowseResult* pValue);
typedef OpcUa_Void (CDECL * PFOPCUABROWSERESULTINITIALIZE) (OpcUa_BrowseResult* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUABROWSERESULTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaBrowseResultInitialize
	#define EXT_OpcUaBrowseResultInitialize
	#define GET_OpcUaBrowseResultInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaBrowseResultInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaBrowseResultInitialize  FALSE
	#define EXP_OpcUaBrowseResultInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaBrowseResultInitialize
	#define EXT_OpcUaBrowseResultInitialize
	#define GET_OpcUaBrowseResultInitialize(fl)  CAL_CMGETAPI( "OpcUaBrowseResultInitialize" ) 
	#define CAL_OpcUaBrowseResultInitialize  OpcUaBrowseResultInitialize
	#define CHK_OpcUaBrowseResultInitialize  TRUE
	#define EXP_OpcUaBrowseResultInitialize  CAL_CMEXPAPI( "OpcUaBrowseResultInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaBrowseResultInitialize
	#define EXT_OpcUaBrowseResultInitialize
	#define GET_OpcUaBrowseResultInitialize(fl)  CAL_CMGETAPI( "OpcUaBrowseResultInitialize" ) 
	#define CAL_OpcUaBrowseResultInitialize  OpcUaBrowseResultInitialize
	#define CHK_OpcUaBrowseResultInitialize  TRUE
	#define EXP_OpcUaBrowseResultInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowseResultInitialize", (RTS_UINTPTR)OpcUaBrowseResultInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaBrowseResultInitialize
	#define EXT_CmpOPCUAStackOpcUaBrowseResultInitialize
	#define GET_CmpOPCUAStackOpcUaBrowseResultInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaBrowseResultInitialize pICmpOPCUAStack->IOpcUaBrowseResultInitialize
	#define CHK_CmpOPCUAStackOpcUaBrowseResultInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaBrowseResultInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaBrowseResultInitialize
	#define EXT_OpcUaBrowseResultInitialize
	#define GET_OpcUaBrowseResultInitialize(fl)  CAL_CMGETAPI( "OpcUaBrowseResultInitialize" ) 
	#define CAL_OpcUaBrowseResultInitialize pICmpOPCUAStack->IOpcUaBrowseResultInitialize
	#define CHK_OpcUaBrowseResultInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaBrowseResultInitialize  CAL_CMEXPAPI( "OpcUaBrowseResultInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaBrowseResultInitialize  PFOPCUABROWSERESULTINITIALIZE pfOpcUaBrowseResultInitialize;
	#define EXT_OpcUaBrowseResultInitialize  extern PFOPCUABROWSERESULTINITIALIZE pfOpcUaBrowseResultInitialize;
	#define GET_OpcUaBrowseResultInitialize(fl)  s_pfCMGetAPI2( "OpcUaBrowseResultInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaBrowseResultInitialize, (fl), 0, 0)
	#define CAL_OpcUaBrowseResultInitialize  pfOpcUaBrowseResultInitialize
	#define CHK_OpcUaBrowseResultInitialize  (pfOpcUaBrowseResultInitialize != NULL)
	#define EXP_OpcUaBrowseResultInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowseResultInitialize", (RTS_UINTPTR)OpcUaBrowseResultInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaBrowseResultClear(OpcUa_BrowseResult* pValue);
typedef OpcUa_Void (CDECL * PFOPCUABROWSERESULTCLEAR) (OpcUa_BrowseResult* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUABROWSERESULTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaBrowseResultClear
	#define EXT_OpcUaBrowseResultClear
	#define GET_OpcUaBrowseResultClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaBrowseResultClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaBrowseResultClear  FALSE
	#define EXP_OpcUaBrowseResultClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaBrowseResultClear
	#define EXT_OpcUaBrowseResultClear
	#define GET_OpcUaBrowseResultClear(fl)  CAL_CMGETAPI( "OpcUaBrowseResultClear" ) 
	#define CAL_OpcUaBrowseResultClear  OpcUaBrowseResultClear
	#define CHK_OpcUaBrowseResultClear  TRUE
	#define EXP_OpcUaBrowseResultClear  CAL_CMEXPAPI( "OpcUaBrowseResultClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaBrowseResultClear
	#define EXT_OpcUaBrowseResultClear
	#define GET_OpcUaBrowseResultClear(fl)  CAL_CMGETAPI( "OpcUaBrowseResultClear" ) 
	#define CAL_OpcUaBrowseResultClear  OpcUaBrowseResultClear
	#define CHK_OpcUaBrowseResultClear  TRUE
	#define EXP_OpcUaBrowseResultClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowseResultClear", (RTS_UINTPTR)OpcUaBrowseResultClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaBrowseResultClear
	#define EXT_CmpOPCUAStackOpcUaBrowseResultClear
	#define GET_CmpOPCUAStackOpcUaBrowseResultClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaBrowseResultClear pICmpOPCUAStack->IOpcUaBrowseResultClear
	#define CHK_CmpOPCUAStackOpcUaBrowseResultClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaBrowseResultClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaBrowseResultClear
	#define EXT_OpcUaBrowseResultClear
	#define GET_OpcUaBrowseResultClear(fl)  CAL_CMGETAPI( "OpcUaBrowseResultClear" ) 
	#define CAL_OpcUaBrowseResultClear pICmpOPCUAStack->IOpcUaBrowseResultClear
	#define CHK_OpcUaBrowseResultClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaBrowseResultClear  CAL_CMEXPAPI( "OpcUaBrowseResultClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaBrowseResultClear  PFOPCUABROWSERESULTCLEAR pfOpcUaBrowseResultClear;
	#define EXT_OpcUaBrowseResultClear  extern PFOPCUABROWSERESULTCLEAR pfOpcUaBrowseResultClear;
	#define GET_OpcUaBrowseResultClear(fl)  s_pfCMGetAPI2( "OpcUaBrowseResultClear", (RTS_VOID_FCTPTR *)&pfOpcUaBrowseResultClear, (fl), 0, 0)
	#define CAL_OpcUaBrowseResultClear  pfOpcUaBrowseResultClear
	#define CHK_OpcUaBrowseResultClear  (pfOpcUaBrowseResultClear != NULL)
	#define EXP_OpcUaBrowseResultClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowseResultClear", (RTS_UINTPTR)OpcUaBrowseResultClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaBrowsePathResultInitialize(OpcUa_BrowsePathResult* pValue);
typedef OpcUa_Void (CDECL * PFOPCUABROWSEPATHRESULTINITIALIZE) (OpcUa_BrowsePathResult* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUABROWSEPATHRESULTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaBrowsePathResultInitialize
	#define EXT_OpcUaBrowsePathResultInitialize
	#define GET_OpcUaBrowsePathResultInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaBrowsePathResultInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaBrowsePathResultInitialize  FALSE
	#define EXP_OpcUaBrowsePathResultInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaBrowsePathResultInitialize
	#define EXT_OpcUaBrowsePathResultInitialize
	#define GET_OpcUaBrowsePathResultInitialize(fl)  CAL_CMGETAPI( "OpcUaBrowsePathResultInitialize" ) 
	#define CAL_OpcUaBrowsePathResultInitialize  OpcUaBrowsePathResultInitialize
	#define CHK_OpcUaBrowsePathResultInitialize  TRUE
	#define EXP_OpcUaBrowsePathResultInitialize  CAL_CMEXPAPI( "OpcUaBrowsePathResultInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaBrowsePathResultInitialize
	#define EXT_OpcUaBrowsePathResultInitialize
	#define GET_OpcUaBrowsePathResultInitialize(fl)  CAL_CMGETAPI( "OpcUaBrowsePathResultInitialize" ) 
	#define CAL_OpcUaBrowsePathResultInitialize  OpcUaBrowsePathResultInitialize
	#define CHK_OpcUaBrowsePathResultInitialize  TRUE
	#define EXP_OpcUaBrowsePathResultInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowsePathResultInitialize", (RTS_UINTPTR)OpcUaBrowsePathResultInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaBrowsePathResultInitialize
	#define EXT_CmpOPCUAStackOpcUaBrowsePathResultInitialize
	#define GET_CmpOPCUAStackOpcUaBrowsePathResultInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaBrowsePathResultInitialize pICmpOPCUAStack->IOpcUaBrowsePathResultInitialize
	#define CHK_CmpOPCUAStackOpcUaBrowsePathResultInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaBrowsePathResultInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaBrowsePathResultInitialize
	#define EXT_OpcUaBrowsePathResultInitialize
	#define GET_OpcUaBrowsePathResultInitialize(fl)  CAL_CMGETAPI( "OpcUaBrowsePathResultInitialize" ) 
	#define CAL_OpcUaBrowsePathResultInitialize pICmpOPCUAStack->IOpcUaBrowsePathResultInitialize
	#define CHK_OpcUaBrowsePathResultInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaBrowsePathResultInitialize  CAL_CMEXPAPI( "OpcUaBrowsePathResultInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaBrowsePathResultInitialize  PFOPCUABROWSEPATHRESULTINITIALIZE pfOpcUaBrowsePathResultInitialize;
	#define EXT_OpcUaBrowsePathResultInitialize  extern PFOPCUABROWSEPATHRESULTINITIALIZE pfOpcUaBrowsePathResultInitialize;
	#define GET_OpcUaBrowsePathResultInitialize(fl)  s_pfCMGetAPI2( "OpcUaBrowsePathResultInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaBrowsePathResultInitialize, (fl), 0, 0)
	#define CAL_OpcUaBrowsePathResultInitialize  pfOpcUaBrowsePathResultInitialize
	#define CHK_OpcUaBrowsePathResultInitialize  (pfOpcUaBrowsePathResultInitialize != NULL)
	#define EXP_OpcUaBrowsePathResultInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowsePathResultInitialize", (RTS_UINTPTR)OpcUaBrowsePathResultInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaBrowsePathResultClear(OpcUa_BrowsePathResult* pValue);
typedef OpcUa_Void (CDECL * PFOPCUABROWSEPATHRESULTCLEAR) (OpcUa_BrowsePathResult* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUABROWSEPATHRESULTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaBrowsePathResultClear
	#define EXT_OpcUaBrowsePathResultClear
	#define GET_OpcUaBrowsePathResultClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaBrowsePathResultClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaBrowsePathResultClear  FALSE
	#define EXP_OpcUaBrowsePathResultClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaBrowsePathResultClear
	#define EXT_OpcUaBrowsePathResultClear
	#define GET_OpcUaBrowsePathResultClear(fl)  CAL_CMGETAPI( "OpcUaBrowsePathResultClear" ) 
	#define CAL_OpcUaBrowsePathResultClear  OpcUaBrowsePathResultClear
	#define CHK_OpcUaBrowsePathResultClear  TRUE
	#define EXP_OpcUaBrowsePathResultClear  CAL_CMEXPAPI( "OpcUaBrowsePathResultClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaBrowsePathResultClear
	#define EXT_OpcUaBrowsePathResultClear
	#define GET_OpcUaBrowsePathResultClear(fl)  CAL_CMGETAPI( "OpcUaBrowsePathResultClear" ) 
	#define CAL_OpcUaBrowsePathResultClear  OpcUaBrowsePathResultClear
	#define CHK_OpcUaBrowsePathResultClear  TRUE
	#define EXP_OpcUaBrowsePathResultClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowsePathResultClear", (RTS_UINTPTR)OpcUaBrowsePathResultClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaBrowsePathResultClear
	#define EXT_CmpOPCUAStackOpcUaBrowsePathResultClear
	#define GET_CmpOPCUAStackOpcUaBrowsePathResultClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaBrowsePathResultClear pICmpOPCUAStack->IOpcUaBrowsePathResultClear
	#define CHK_CmpOPCUAStackOpcUaBrowsePathResultClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaBrowsePathResultClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaBrowsePathResultClear
	#define EXT_OpcUaBrowsePathResultClear
	#define GET_OpcUaBrowsePathResultClear(fl)  CAL_CMGETAPI( "OpcUaBrowsePathResultClear" ) 
	#define CAL_OpcUaBrowsePathResultClear pICmpOPCUAStack->IOpcUaBrowsePathResultClear
	#define CHK_OpcUaBrowsePathResultClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaBrowsePathResultClear  CAL_CMEXPAPI( "OpcUaBrowsePathResultClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaBrowsePathResultClear  PFOPCUABROWSEPATHRESULTCLEAR pfOpcUaBrowsePathResultClear;
	#define EXT_OpcUaBrowsePathResultClear  extern PFOPCUABROWSEPATHRESULTCLEAR pfOpcUaBrowsePathResultClear;
	#define GET_OpcUaBrowsePathResultClear(fl)  s_pfCMGetAPI2( "OpcUaBrowsePathResultClear", (RTS_VOID_FCTPTR *)&pfOpcUaBrowsePathResultClear, (fl), 0, 0)
	#define CAL_OpcUaBrowsePathResultClear  pfOpcUaBrowsePathResultClear
	#define CHK_OpcUaBrowsePathResultClear  (pfOpcUaBrowsePathResultClear != NULL)
	#define EXP_OpcUaBrowsePathResultClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowsePathResultClear", (RTS_UINTPTR)OpcUaBrowsePathResultClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaReferenceDescriptionInitialize(OpcUa_ReferenceDescription* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAREFERENCEDESCRIPTIONINITIALIZE) (OpcUa_ReferenceDescription* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAREFERENCEDESCRIPTIONINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaReferenceDescriptionInitialize
	#define EXT_OpcUaReferenceDescriptionInitialize
	#define GET_OpcUaReferenceDescriptionInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaReferenceDescriptionInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaReferenceDescriptionInitialize  FALSE
	#define EXP_OpcUaReferenceDescriptionInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaReferenceDescriptionInitialize
	#define EXT_OpcUaReferenceDescriptionInitialize
	#define GET_OpcUaReferenceDescriptionInitialize(fl)  CAL_CMGETAPI( "OpcUaReferenceDescriptionInitialize" ) 
	#define CAL_OpcUaReferenceDescriptionInitialize  OpcUaReferenceDescriptionInitialize
	#define CHK_OpcUaReferenceDescriptionInitialize  TRUE
	#define EXP_OpcUaReferenceDescriptionInitialize  CAL_CMEXPAPI( "OpcUaReferenceDescriptionInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaReferenceDescriptionInitialize
	#define EXT_OpcUaReferenceDescriptionInitialize
	#define GET_OpcUaReferenceDescriptionInitialize(fl)  CAL_CMGETAPI( "OpcUaReferenceDescriptionInitialize" ) 
	#define CAL_OpcUaReferenceDescriptionInitialize  OpcUaReferenceDescriptionInitialize
	#define CHK_OpcUaReferenceDescriptionInitialize  TRUE
	#define EXP_OpcUaReferenceDescriptionInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaReferenceDescriptionInitialize", (RTS_UINTPTR)OpcUaReferenceDescriptionInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaReferenceDescriptionInitialize
	#define EXT_CmpOPCUAStackOpcUaReferenceDescriptionInitialize
	#define GET_CmpOPCUAStackOpcUaReferenceDescriptionInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaReferenceDescriptionInitialize pICmpOPCUAStack->IOpcUaReferenceDescriptionInitialize
	#define CHK_CmpOPCUAStackOpcUaReferenceDescriptionInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaReferenceDescriptionInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaReferenceDescriptionInitialize
	#define EXT_OpcUaReferenceDescriptionInitialize
	#define GET_OpcUaReferenceDescriptionInitialize(fl)  CAL_CMGETAPI( "OpcUaReferenceDescriptionInitialize" ) 
	#define CAL_OpcUaReferenceDescriptionInitialize pICmpOPCUAStack->IOpcUaReferenceDescriptionInitialize
	#define CHK_OpcUaReferenceDescriptionInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaReferenceDescriptionInitialize  CAL_CMEXPAPI( "OpcUaReferenceDescriptionInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaReferenceDescriptionInitialize  PFOPCUAREFERENCEDESCRIPTIONINITIALIZE pfOpcUaReferenceDescriptionInitialize;
	#define EXT_OpcUaReferenceDescriptionInitialize  extern PFOPCUAREFERENCEDESCRIPTIONINITIALIZE pfOpcUaReferenceDescriptionInitialize;
	#define GET_OpcUaReferenceDescriptionInitialize(fl)  s_pfCMGetAPI2( "OpcUaReferenceDescriptionInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaReferenceDescriptionInitialize, (fl), 0, 0)
	#define CAL_OpcUaReferenceDescriptionInitialize  pfOpcUaReferenceDescriptionInitialize
	#define CHK_OpcUaReferenceDescriptionInitialize  (pfOpcUaReferenceDescriptionInitialize != NULL)
	#define EXP_OpcUaReferenceDescriptionInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaReferenceDescriptionInitialize", (RTS_UINTPTR)OpcUaReferenceDescriptionInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaReferenceDescriptionClear(OpcUa_ReferenceDescription* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAREFERENCEDESCRIPTIONCLEAR) (OpcUa_ReferenceDescription* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAREFERENCEDESCRIPTIONCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaReferenceDescriptionClear
	#define EXT_OpcUaReferenceDescriptionClear
	#define GET_OpcUaReferenceDescriptionClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaReferenceDescriptionClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaReferenceDescriptionClear  FALSE
	#define EXP_OpcUaReferenceDescriptionClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaReferenceDescriptionClear
	#define EXT_OpcUaReferenceDescriptionClear
	#define GET_OpcUaReferenceDescriptionClear(fl)  CAL_CMGETAPI( "OpcUaReferenceDescriptionClear" ) 
	#define CAL_OpcUaReferenceDescriptionClear  OpcUaReferenceDescriptionClear
	#define CHK_OpcUaReferenceDescriptionClear  TRUE
	#define EXP_OpcUaReferenceDescriptionClear  CAL_CMEXPAPI( "OpcUaReferenceDescriptionClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaReferenceDescriptionClear
	#define EXT_OpcUaReferenceDescriptionClear
	#define GET_OpcUaReferenceDescriptionClear(fl)  CAL_CMGETAPI( "OpcUaReferenceDescriptionClear" ) 
	#define CAL_OpcUaReferenceDescriptionClear  OpcUaReferenceDescriptionClear
	#define CHK_OpcUaReferenceDescriptionClear  TRUE
	#define EXP_OpcUaReferenceDescriptionClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaReferenceDescriptionClear", (RTS_UINTPTR)OpcUaReferenceDescriptionClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaReferenceDescriptionClear
	#define EXT_CmpOPCUAStackOpcUaReferenceDescriptionClear
	#define GET_CmpOPCUAStackOpcUaReferenceDescriptionClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaReferenceDescriptionClear pICmpOPCUAStack->IOpcUaReferenceDescriptionClear
	#define CHK_CmpOPCUAStackOpcUaReferenceDescriptionClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaReferenceDescriptionClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaReferenceDescriptionClear
	#define EXT_OpcUaReferenceDescriptionClear
	#define GET_OpcUaReferenceDescriptionClear(fl)  CAL_CMGETAPI( "OpcUaReferenceDescriptionClear" ) 
	#define CAL_OpcUaReferenceDescriptionClear pICmpOPCUAStack->IOpcUaReferenceDescriptionClear
	#define CHK_OpcUaReferenceDescriptionClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaReferenceDescriptionClear  CAL_CMEXPAPI( "OpcUaReferenceDescriptionClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaReferenceDescriptionClear  PFOPCUAREFERENCEDESCRIPTIONCLEAR pfOpcUaReferenceDescriptionClear;
	#define EXT_OpcUaReferenceDescriptionClear  extern PFOPCUAREFERENCEDESCRIPTIONCLEAR pfOpcUaReferenceDescriptionClear;
	#define GET_OpcUaReferenceDescriptionClear(fl)  s_pfCMGetAPI2( "OpcUaReferenceDescriptionClear", (RTS_VOID_FCTPTR *)&pfOpcUaReferenceDescriptionClear, (fl), 0, 0)
	#define CAL_OpcUaReferenceDescriptionClear  pfOpcUaReferenceDescriptionClear
	#define CHK_OpcUaReferenceDescriptionClear  (pfOpcUaReferenceDescriptionClear != NULL)
	#define EXP_OpcUaReferenceDescriptionClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaReferenceDescriptionClear", (RTS_UINTPTR)OpcUaReferenceDescriptionClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaUserTokenPolicyInitialize(OpcUa_UserTokenPolicy* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAUSERTOKENPOLICYINITIALIZE) (OpcUa_UserTokenPolicy* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAUSERTOKENPOLICYINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaUserTokenPolicyInitialize
	#define EXT_OpcUaUserTokenPolicyInitialize
	#define GET_OpcUaUserTokenPolicyInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaUserTokenPolicyInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaUserTokenPolicyInitialize  FALSE
	#define EXP_OpcUaUserTokenPolicyInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaUserTokenPolicyInitialize
	#define EXT_OpcUaUserTokenPolicyInitialize
	#define GET_OpcUaUserTokenPolicyInitialize(fl)  CAL_CMGETAPI( "OpcUaUserTokenPolicyInitialize" ) 
	#define CAL_OpcUaUserTokenPolicyInitialize  OpcUaUserTokenPolicyInitialize
	#define CHK_OpcUaUserTokenPolicyInitialize  TRUE
	#define EXP_OpcUaUserTokenPolicyInitialize  CAL_CMEXPAPI( "OpcUaUserTokenPolicyInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaUserTokenPolicyInitialize
	#define EXT_OpcUaUserTokenPolicyInitialize
	#define GET_OpcUaUserTokenPolicyInitialize(fl)  CAL_CMGETAPI( "OpcUaUserTokenPolicyInitialize" ) 
	#define CAL_OpcUaUserTokenPolicyInitialize  OpcUaUserTokenPolicyInitialize
	#define CHK_OpcUaUserTokenPolicyInitialize  TRUE
	#define EXP_OpcUaUserTokenPolicyInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaUserTokenPolicyInitialize", (RTS_UINTPTR)OpcUaUserTokenPolicyInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaUserTokenPolicyInitialize
	#define EXT_CmpOPCUAStackOpcUaUserTokenPolicyInitialize
	#define GET_CmpOPCUAStackOpcUaUserTokenPolicyInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaUserTokenPolicyInitialize pICmpOPCUAStack->IOpcUaUserTokenPolicyInitialize
	#define CHK_CmpOPCUAStackOpcUaUserTokenPolicyInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaUserTokenPolicyInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaUserTokenPolicyInitialize
	#define EXT_OpcUaUserTokenPolicyInitialize
	#define GET_OpcUaUserTokenPolicyInitialize(fl)  CAL_CMGETAPI( "OpcUaUserTokenPolicyInitialize" ) 
	#define CAL_OpcUaUserTokenPolicyInitialize pICmpOPCUAStack->IOpcUaUserTokenPolicyInitialize
	#define CHK_OpcUaUserTokenPolicyInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaUserTokenPolicyInitialize  CAL_CMEXPAPI( "OpcUaUserTokenPolicyInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaUserTokenPolicyInitialize  PFOPCUAUSERTOKENPOLICYINITIALIZE pfOpcUaUserTokenPolicyInitialize;
	#define EXT_OpcUaUserTokenPolicyInitialize  extern PFOPCUAUSERTOKENPOLICYINITIALIZE pfOpcUaUserTokenPolicyInitialize;
	#define GET_OpcUaUserTokenPolicyInitialize(fl)  s_pfCMGetAPI2( "OpcUaUserTokenPolicyInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaUserTokenPolicyInitialize, (fl), 0, 0)
	#define CAL_OpcUaUserTokenPolicyInitialize  pfOpcUaUserTokenPolicyInitialize
	#define CHK_OpcUaUserTokenPolicyInitialize  (pfOpcUaUserTokenPolicyInitialize != NULL)
	#define EXP_OpcUaUserTokenPolicyInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaUserTokenPolicyInitialize", (RTS_UINTPTR)OpcUaUserTokenPolicyInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaUserTokenPolicyClear(OpcUa_UserTokenPolicy* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAUSERTOKENPOLICYCLEAR) (OpcUa_UserTokenPolicy* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAUSERTOKENPOLICYCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaUserTokenPolicyClear
	#define EXT_OpcUaUserTokenPolicyClear
	#define GET_OpcUaUserTokenPolicyClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaUserTokenPolicyClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaUserTokenPolicyClear  FALSE
	#define EXP_OpcUaUserTokenPolicyClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaUserTokenPolicyClear
	#define EXT_OpcUaUserTokenPolicyClear
	#define GET_OpcUaUserTokenPolicyClear(fl)  CAL_CMGETAPI( "OpcUaUserTokenPolicyClear" ) 
	#define CAL_OpcUaUserTokenPolicyClear  OpcUaUserTokenPolicyClear
	#define CHK_OpcUaUserTokenPolicyClear  TRUE
	#define EXP_OpcUaUserTokenPolicyClear  CAL_CMEXPAPI( "OpcUaUserTokenPolicyClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaUserTokenPolicyClear
	#define EXT_OpcUaUserTokenPolicyClear
	#define GET_OpcUaUserTokenPolicyClear(fl)  CAL_CMGETAPI( "OpcUaUserTokenPolicyClear" ) 
	#define CAL_OpcUaUserTokenPolicyClear  OpcUaUserTokenPolicyClear
	#define CHK_OpcUaUserTokenPolicyClear  TRUE
	#define EXP_OpcUaUserTokenPolicyClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaUserTokenPolicyClear", (RTS_UINTPTR)OpcUaUserTokenPolicyClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaUserTokenPolicyClear
	#define EXT_CmpOPCUAStackOpcUaUserTokenPolicyClear
	#define GET_CmpOPCUAStackOpcUaUserTokenPolicyClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaUserTokenPolicyClear pICmpOPCUAStack->IOpcUaUserTokenPolicyClear
	#define CHK_CmpOPCUAStackOpcUaUserTokenPolicyClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaUserTokenPolicyClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaUserTokenPolicyClear
	#define EXT_OpcUaUserTokenPolicyClear
	#define GET_OpcUaUserTokenPolicyClear(fl)  CAL_CMGETAPI( "OpcUaUserTokenPolicyClear" ) 
	#define CAL_OpcUaUserTokenPolicyClear pICmpOPCUAStack->IOpcUaUserTokenPolicyClear
	#define CHK_OpcUaUserTokenPolicyClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaUserTokenPolicyClear  CAL_CMEXPAPI( "OpcUaUserTokenPolicyClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaUserTokenPolicyClear  PFOPCUAUSERTOKENPOLICYCLEAR pfOpcUaUserTokenPolicyClear;
	#define EXT_OpcUaUserTokenPolicyClear  extern PFOPCUAUSERTOKENPOLICYCLEAR pfOpcUaUserTokenPolicyClear;
	#define GET_OpcUaUserTokenPolicyClear(fl)  s_pfCMGetAPI2( "OpcUaUserTokenPolicyClear", (RTS_VOID_FCTPTR *)&pfOpcUaUserTokenPolicyClear, (fl), 0, 0)
	#define CAL_OpcUaUserTokenPolicyClear  pfOpcUaUserTokenPolicyClear
	#define CHK_OpcUaUserTokenPolicyClear  (pfOpcUaUserTokenPolicyClear != NULL)
	#define EXP_OpcUaUserTokenPolicyClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaUserTokenPolicyClear", (RTS_UINTPTR)OpcUaUserTokenPolicyClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaSignatureDataInitialize(OpcUa_SignatureData* pValue);
typedef OpcUa_Void (CDECL * PFOPCUASIGNATUREDATAINITIALIZE) (OpcUa_SignatureData* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASIGNATUREDATAINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaSignatureDataInitialize
	#define EXT_OpcUaSignatureDataInitialize
	#define GET_OpcUaSignatureDataInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaSignatureDataInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaSignatureDataInitialize  FALSE
	#define EXP_OpcUaSignatureDataInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaSignatureDataInitialize
	#define EXT_OpcUaSignatureDataInitialize
	#define GET_OpcUaSignatureDataInitialize(fl)  CAL_CMGETAPI( "OpcUaSignatureDataInitialize" ) 
	#define CAL_OpcUaSignatureDataInitialize  OpcUaSignatureDataInitialize
	#define CHK_OpcUaSignatureDataInitialize  TRUE
	#define EXP_OpcUaSignatureDataInitialize  CAL_CMEXPAPI( "OpcUaSignatureDataInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaSignatureDataInitialize
	#define EXT_OpcUaSignatureDataInitialize
	#define GET_OpcUaSignatureDataInitialize(fl)  CAL_CMGETAPI( "OpcUaSignatureDataInitialize" ) 
	#define CAL_OpcUaSignatureDataInitialize  OpcUaSignatureDataInitialize
	#define CHK_OpcUaSignatureDataInitialize  TRUE
	#define EXP_OpcUaSignatureDataInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSignatureDataInitialize", (RTS_UINTPTR)OpcUaSignatureDataInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaSignatureDataInitialize
	#define EXT_CmpOPCUAStackOpcUaSignatureDataInitialize
	#define GET_CmpOPCUAStackOpcUaSignatureDataInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaSignatureDataInitialize pICmpOPCUAStack->IOpcUaSignatureDataInitialize
	#define CHK_CmpOPCUAStackOpcUaSignatureDataInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaSignatureDataInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaSignatureDataInitialize
	#define EXT_OpcUaSignatureDataInitialize
	#define GET_OpcUaSignatureDataInitialize(fl)  CAL_CMGETAPI( "OpcUaSignatureDataInitialize" ) 
	#define CAL_OpcUaSignatureDataInitialize pICmpOPCUAStack->IOpcUaSignatureDataInitialize
	#define CHK_OpcUaSignatureDataInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaSignatureDataInitialize  CAL_CMEXPAPI( "OpcUaSignatureDataInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaSignatureDataInitialize  PFOPCUASIGNATUREDATAINITIALIZE pfOpcUaSignatureDataInitialize;
	#define EXT_OpcUaSignatureDataInitialize  extern PFOPCUASIGNATUREDATAINITIALIZE pfOpcUaSignatureDataInitialize;
	#define GET_OpcUaSignatureDataInitialize(fl)  s_pfCMGetAPI2( "OpcUaSignatureDataInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaSignatureDataInitialize, (fl), 0, 0)
	#define CAL_OpcUaSignatureDataInitialize  pfOpcUaSignatureDataInitialize
	#define CHK_OpcUaSignatureDataInitialize  (pfOpcUaSignatureDataInitialize != NULL)
	#define EXP_OpcUaSignatureDataInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSignatureDataInitialize", (RTS_UINTPTR)OpcUaSignatureDataInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaSignatureDataClear(OpcUa_SignatureData* pValue);
typedef OpcUa_Void (CDECL * PFOPCUASIGNATUREDATACLEAR) (OpcUa_SignatureData* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASIGNATUREDATACLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaSignatureDataClear
	#define EXT_OpcUaSignatureDataClear
	#define GET_OpcUaSignatureDataClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaSignatureDataClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaSignatureDataClear  FALSE
	#define EXP_OpcUaSignatureDataClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaSignatureDataClear
	#define EXT_OpcUaSignatureDataClear
	#define GET_OpcUaSignatureDataClear(fl)  CAL_CMGETAPI( "OpcUaSignatureDataClear" ) 
	#define CAL_OpcUaSignatureDataClear  OpcUaSignatureDataClear
	#define CHK_OpcUaSignatureDataClear  TRUE
	#define EXP_OpcUaSignatureDataClear  CAL_CMEXPAPI( "OpcUaSignatureDataClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaSignatureDataClear
	#define EXT_OpcUaSignatureDataClear
	#define GET_OpcUaSignatureDataClear(fl)  CAL_CMGETAPI( "OpcUaSignatureDataClear" ) 
	#define CAL_OpcUaSignatureDataClear  OpcUaSignatureDataClear
	#define CHK_OpcUaSignatureDataClear  TRUE
	#define EXP_OpcUaSignatureDataClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSignatureDataClear", (RTS_UINTPTR)OpcUaSignatureDataClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaSignatureDataClear
	#define EXT_CmpOPCUAStackOpcUaSignatureDataClear
	#define GET_CmpOPCUAStackOpcUaSignatureDataClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaSignatureDataClear pICmpOPCUAStack->IOpcUaSignatureDataClear
	#define CHK_CmpOPCUAStackOpcUaSignatureDataClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaSignatureDataClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaSignatureDataClear
	#define EXT_OpcUaSignatureDataClear
	#define GET_OpcUaSignatureDataClear(fl)  CAL_CMGETAPI( "OpcUaSignatureDataClear" ) 
	#define CAL_OpcUaSignatureDataClear pICmpOPCUAStack->IOpcUaSignatureDataClear
	#define CHK_OpcUaSignatureDataClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaSignatureDataClear  CAL_CMEXPAPI( "OpcUaSignatureDataClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaSignatureDataClear  PFOPCUASIGNATUREDATACLEAR pfOpcUaSignatureDataClear;
	#define EXT_OpcUaSignatureDataClear  extern PFOPCUASIGNATUREDATACLEAR pfOpcUaSignatureDataClear;
	#define GET_OpcUaSignatureDataClear(fl)  s_pfCMGetAPI2( "OpcUaSignatureDataClear", (RTS_VOID_FCTPTR *)&pfOpcUaSignatureDataClear, (fl), 0, 0)
	#define CAL_OpcUaSignatureDataClear  pfOpcUaSignatureDataClear
	#define CHK_OpcUaSignatureDataClear  (pfOpcUaSignatureDataClear != NULL)
	#define EXP_OpcUaSignatureDataClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSignatureDataClear", (RTS_UINTPTR)OpcUaSignatureDataClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaApplicationDescriptionInitialize(OpcUa_ApplicationDescription* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAAPPLICATIONDESCRIPTIONINITIALIZE) (OpcUa_ApplicationDescription* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAAPPLICATIONDESCRIPTIONINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaApplicationDescriptionInitialize
	#define EXT_OpcUaApplicationDescriptionInitialize
	#define GET_OpcUaApplicationDescriptionInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaApplicationDescriptionInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaApplicationDescriptionInitialize  FALSE
	#define EXP_OpcUaApplicationDescriptionInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaApplicationDescriptionInitialize
	#define EXT_OpcUaApplicationDescriptionInitialize
	#define GET_OpcUaApplicationDescriptionInitialize(fl)  CAL_CMGETAPI( "OpcUaApplicationDescriptionInitialize" ) 
	#define CAL_OpcUaApplicationDescriptionInitialize  OpcUaApplicationDescriptionInitialize
	#define CHK_OpcUaApplicationDescriptionInitialize  TRUE
	#define EXP_OpcUaApplicationDescriptionInitialize  CAL_CMEXPAPI( "OpcUaApplicationDescriptionInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaApplicationDescriptionInitialize
	#define EXT_OpcUaApplicationDescriptionInitialize
	#define GET_OpcUaApplicationDescriptionInitialize(fl)  CAL_CMGETAPI( "OpcUaApplicationDescriptionInitialize" ) 
	#define CAL_OpcUaApplicationDescriptionInitialize  OpcUaApplicationDescriptionInitialize
	#define CHK_OpcUaApplicationDescriptionInitialize  TRUE
	#define EXP_OpcUaApplicationDescriptionInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaApplicationDescriptionInitialize", (RTS_UINTPTR)OpcUaApplicationDescriptionInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaApplicationDescriptionInitialize
	#define EXT_CmpOPCUAStackOpcUaApplicationDescriptionInitialize
	#define GET_CmpOPCUAStackOpcUaApplicationDescriptionInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaApplicationDescriptionInitialize pICmpOPCUAStack->IOpcUaApplicationDescriptionInitialize
	#define CHK_CmpOPCUAStackOpcUaApplicationDescriptionInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaApplicationDescriptionInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaApplicationDescriptionInitialize
	#define EXT_OpcUaApplicationDescriptionInitialize
	#define GET_OpcUaApplicationDescriptionInitialize(fl)  CAL_CMGETAPI( "OpcUaApplicationDescriptionInitialize" ) 
	#define CAL_OpcUaApplicationDescriptionInitialize pICmpOPCUAStack->IOpcUaApplicationDescriptionInitialize
	#define CHK_OpcUaApplicationDescriptionInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaApplicationDescriptionInitialize  CAL_CMEXPAPI( "OpcUaApplicationDescriptionInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaApplicationDescriptionInitialize  PFOPCUAAPPLICATIONDESCRIPTIONINITIALIZE pfOpcUaApplicationDescriptionInitialize;
	#define EXT_OpcUaApplicationDescriptionInitialize  extern PFOPCUAAPPLICATIONDESCRIPTIONINITIALIZE pfOpcUaApplicationDescriptionInitialize;
	#define GET_OpcUaApplicationDescriptionInitialize(fl)  s_pfCMGetAPI2( "OpcUaApplicationDescriptionInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaApplicationDescriptionInitialize, (fl), 0, 0)
	#define CAL_OpcUaApplicationDescriptionInitialize  pfOpcUaApplicationDescriptionInitialize
	#define CHK_OpcUaApplicationDescriptionInitialize  (pfOpcUaApplicationDescriptionInitialize != NULL)
	#define EXP_OpcUaApplicationDescriptionInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaApplicationDescriptionInitialize", (RTS_UINTPTR)OpcUaApplicationDescriptionInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaApplicationDescriptionClear(OpcUa_ApplicationDescription* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAAPPLICATIONDESCRIPTIONCLEAR) (OpcUa_ApplicationDescription* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAAPPLICATIONDESCRIPTIONCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaApplicationDescriptionClear
	#define EXT_OpcUaApplicationDescriptionClear
	#define GET_OpcUaApplicationDescriptionClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaApplicationDescriptionClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaApplicationDescriptionClear  FALSE
	#define EXP_OpcUaApplicationDescriptionClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaApplicationDescriptionClear
	#define EXT_OpcUaApplicationDescriptionClear
	#define GET_OpcUaApplicationDescriptionClear(fl)  CAL_CMGETAPI( "OpcUaApplicationDescriptionClear" ) 
	#define CAL_OpcUaApplicationDescriptionClear  OpcUaApplicationDescriptionClear
	#define CHK_OpcUaApplicationDescriptionClear  TRUE
	#define EXP_OpcUaApplicationDescriptionClear  CAL_CMEXPAPI( "OpcUaApplicationDescriptionClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaApplicationDescriptionClear
	#define EXT_OpcUaApplicationDescriptionClear
	#define GET_OpcUaApplicationDescriptionClear(fl)  CAL_CMGETAPI( "OpcUaApplicationDescriptionClear" ) 
	#define CAL_OpcUaApplicationDescriptionClear  OpcUaApplicationDescriptionClear
	#define CHK_OpcUaApplicationDescriptionClear  TRUE
	#define EXP_OpcUaApplicationDescriptionClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaApplicationDescriptionClear", (RTS_UINTPTR)OpcUaApplicationDescriptionClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaApplicationDescriptionClear
	#define EXT_CmpOPCUAStackOpcUaApplicationDescriptionClear
	#define GET_CmpOPCUAStackOpcUaApplicationDescriptionClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaApplicationDescriptionClear pICmpOPCUAStack->IOpcUaApplicationDescriptionClear
	#define CHK_CmpOPCUAStackOpcUaApplicationDescriptionClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaApplicationDescriptionClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaApplicationDescriptionClear
	#define EXT_OpcUaApplicationDescriptionClear
	#define GET_OpcUaApplicationDescriptionClear(fl)  CAL_CMGETAPI( "OpcUaApplicationDescriptionClear" ) 
	#define CAL_OpcUaApplicationDescriptionClear pICmpOPCUAStack->IOpcUaApplicationDescriptionClear
	#define CHK_OpcUaApplicationDescriptionClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaApplicationDescriptionClear  CAL_CMEXPAPI( "OpcUaApplicationDescriptionClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaApplicationDescriptionClear  PFOPCUAAPPLICATIONDESCRIPTIONCLEAR pfOpcUaApplicationDescriptionClear;
	#define EXT_OpcUaApplicationDescriptionClear  extern PFOPCUAAPPLICATIONDESCRIPTIONCLEAR pfOpcUaApplicationDescriptionClear;
	#define GET_OpcUaApplicationDescriptionClear(fl)  s_pfCMGetAPI2( "OpcUaApplicationDescriptionClear", (RTS_VOID_FCTPTR *)&pfOpcUaApplicationDescriptionClear, (fl), 0, 0)
	#define CAL_OpcUaApplicationDescriptionClear  pfOpcUaApplicationDescriptionClear
	#define CHK_OpcUaApplicationDescriptionClear  (pfOpcUaApplicationDescriptionClear != NULL)
	#define EXP_OpcUaApplicationDescriptionClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaApplicationDescriptionClear", (RTS_UINTPTR)OpcUaApplicationDescriptionClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaServerOnNetworkInitialize(OpcUa_ServerOnNetwork* pValue);
typedef OpcUa_Void (CDECL * PFOPCUASERVERONNETWORKINITIALIZE) (OpcUa_ServerOnNetwork* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASERVERONNETWORKINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaServerOnNetworkInitialize
	#define EXT_OpcUaServerOnNetworkInitialize
	#define GET_OpcUaServerOnNetworkInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaServerOnNetworkInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaServerOnNetworkInitialize  FALSE
	#define EXP_OpcUaServerOnNetworkInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaServerOnNetworkInitialize
	#define EXT_OpcUaServerOnNetworkInitialize
	#define GET_OpcUaServerOnNetworkInitialize(fl)  CAL_CMGETAPI( "OpcUaServerOnNetworkInitialize" ) 
	#define CAL_OpcUaServerOnNetworkInitialize  OpcUaServerOnNetworkInitialize
	#define CHK_OpcUaServerOnNetworkInitialize  TRUE
	#define EXP_OpcUaServerOnNetworkInitialize  CAL_CMEXPAPI( "OpcUaServerOnNetworkInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaServerOnNetworkInitialize
	#define EXT_OpcUaServerOnNetworkInitialize
	#define GET_OpcUaServerOnNetworkInitialize(fl)  CAL_CMGETAPI( "OpcUaServerOnNetworkInitialize" ) 
	#define CAL_OpcUaServerOnNetworkInitialize  OpcUaServerOnNetworkInitialize
	#define CHK_OpcUaServerOnNetworkInitialize  TRUE
	#define EXP_OpcUaServerOnNetworkInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaServerOnNetworkInitialize", (RTS_UINTPTR)OpcUaServerOnNetworkInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaServerOnNetworkInitialize
	#define EXT_CmpOPCUAStackOpcUaServerOnNetworkInitialize
	#define GET_CmpOPCUAStackOpcUaServerOnNetworkInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaServerOnNetworkInitialize pICmpOPCUAStack->IOpcUaServerOnNetworkInitialize
	#define CHK_CmpOPCUAStackOpcUaServerOnNetworkInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaServerOnNetworkInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaServerOnNetworkInitialize
	#define EXT_OpcUaServerOnNetworkInitialize
	#define GET_OpcUaServerOnNetworkInitialize(fl)  CAL_CMGETAPI( "OpcUaServerOnNetworkInitialize" ) 
	#define CAL_OpcUaServerOnNetworkInitialize pICmpOPCUAStack->IOpcUaServerOnNetworkInitialize
	#define CHK_OpcUaServerOnNetworkInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaServerOnNetworkInitialize  CAL_CMEXPAPI( "OpcUaServerOnNetworkInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaServerOnNetworkInitialize  PFOPCUASERVERONNETWORKINITIALIZE pfOpcUaServerOnNetworkInitialize;
	#define EXT_OpcUaServerOnNetworkInitialize  extern PFOPCUASERVERONNETWORKINITIALIZE pfOpcUaServerOnNetworkInitialize;
	#define GET_OpcUaServerOnNetworkInitialize(fl)  s_pfCMGetAPI2( "OpcUaServerOnNetworkInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaServerOnNetworkInitialize, (fl), 0, 0)
	#define CAL_OpcUaServerOnNetworkInitialize  pfOpcUaServerOnNetworkInitialize
	#define CHK_OpcUaServerOnNetworkInitialize  (pfOpcUaServerOnNetworkInitialize != NULL)
	#define EXP_OpcUaServerOnNetworkInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaServerOnNetworkInitialize", (RTS_UINTPTR)OpcUaServerOnNetworkInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaServerOnNetworkClear(OpcUa_ServerOnNetwork* pValue);
typedef OpcUa_Void (CDECL * PFOPCUASERVERONNETWORKCLEAR) (OpcUa_ServerOnNetwork* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASERVERONNETWORKCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaServerOnNetworkClear
	#define EXT_OpcUaServerOnNetworkClear
	#define GET_OpcUaServerOnNetworkClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaServerOnNetworkClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaServerOnNetworkClear  FALSE
	#define EXP_OpcUaServerOnNetworkClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaServerOnNetworkClear
	#define EXT_OpcUaServerOnNetworkClear
	#define GET_OpcUaServerOnNetworkClear(fl)  CAL_CMGETAPI( "OpcUaServerOnNetworkClear" ) 
	#define CAL_OpcUaServerOnNetworkClear  OpcUaServerOnNetworkClear
	#define CHK_OpcUaServerOnNetworkClear  TRUE
	#define EXP_OpcUaServerOnNetworkClear  CAL_CMEXPAPI( "OpcUaServerOnNetworkClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaServerOnNetworkClear
	#define EXT_OpcUaServerOnNetworkClear
	#define GET_OpcUaServerOnNetworkClear(fl)  CAL_CMGETAPI( "OpcUaServerOnNetworkClear" ) 
	#define CAL_OpcUaServerOnNetworkClear  OpcUaServerOnNetworkClear
	#define CHK_OpcUaServerOnNetworkClear  TRUE
	#define EXP_OpcUaServerOnNetworkClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaServerOnNetworkClear", (RTS_UINTPTR)OpcUaServerOnNetworkClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaServerOnNetworkClear
	#define EXT_CmpOPCUAStackOpcUaServerOnNetworkClear
	#define GET_CmpOPCUAStackOpcUaServerOnNetworkClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaServerOnNetworkClear pICmpOPCUAStack->IOpcUaServerOnNetworkClear
	#define CHK_CmpOPCUAStackOpcUaServerOnNetworkClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaServerOnNetworkClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaServerOnNetworkClear
	#define EXT_OpcUaServerOnNetworkClear
	#define GET_OpcUaServerOnNetworkClear(fl)  CAL_CMGETAPI( "OpcUaServerOnNetworkClear" ) 
	#define CAL_OpcUaServerOnNetworkClear pICmpOPCUAStack->IOpcUaServerOnNetworkClear
	#define CHK_OpcUaServerOnNetworkClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaServerOnNetworkClear  CAL_CMEXPAPI( "OpcUaServerOnNetworkClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaServerOnNetworkClear  PFOPCUASERVERONNETWORKCLEAR pfOpcUaServerOnNetworkClear;
	#define EXT_OpcUaServerOnNetworkClear  extern PFOPCUASERVERONNETWORKCLEAR pfOpcUaServerOnNetworkClear;
	#define GET_OpcUaServerOnNetworkClear(fl)  s_pfCMGetAPI2( "OpcUaServerOnNetworkClear", (RTS_VOID_FCTPTR *)&pfOpcUaServerOnNetworkClear, (fl), 0, 0)
	#define CAL_OpcUaServerOnNetworkClear  pfOpcUaServerOnNetworkClear
	#define CHK_OpcUaServerOnNetworkClear  (pfOpcUaServerOnNetworkClear != NULL)
	#define EXP_OpcUaServerOnNetworkClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaServerOnNetworkClear", (RTS_UINTPTR)OpcUaServerOnNetworkClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaEventNotificationListInitialize(OpcUa_EventNotificationList* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAEVENTNOTIFICATIONLISTINITIALIZE) (OpcUa_EventNotificationList* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAEVENTNOTIFICATIONLISTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaEventNotificationListInitialize
	#define EXT_OpcUaEventNotificationListInitialize
	#define GET_OpcUaEventNotificationListInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaEventNotificationListInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaEventNotificationListInitialize  FALSE
	#define EXP_OpcUaEventNotificationListInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaEventNotificationListInitialize
	#define EXT_OpcUaEventNotificationListInitialize
	#define GET_OpcUaEventNotificationListInitialize(fl)  CAL_CMGETAPI( "OpcUaEventNotificationListInitialize" ) 
	#define CAL_OpcUaEventNotificationListInitialize  OpcUaEventNotificationListInitialize
	#define CHK_OpcUaEventNotificationListInitialize  TRUE
	#define EXP_OpcUaEventNotificationListInitialize  CAL_CMEXPAPI( "OpcUaEventNotificationListInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaEventNotificationListInitialize
	#define EXT_OpcUaEventNotificationListInitialize
	#define GET_OpcUaEventNotificationListInitialize(fl)  CAL_CMGETAPI( "OpcUaEventNotificationListInitialize" ) 
	#define CAL_OpcUaEventNotificationListInitialize  OpcUaEventNotificationListInitialize
	#define CHK_OpcUaEventNotificationListInitialize  TRUE
	#define EXP_OpcUaEventNotificationListInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEventNotificationListInitialize", (RTS_UINTPTR)OpcUaEventNotificationListInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaEventNotificationListInitialize
	#define EXT_CmpOPCUAStackOpcUaEventNotificationListInitialize
	#define GET_CmpOPCUAStackOpcUaEventNotificationListInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaEventNotificationListInitialize pICmpOPCUAStack->IOpcUaEventNotificationListInitialize
	#define CHK_CmpOPCUAStackOpcUaEventNotificationListInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaEventNotificationListInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaEventNotificationListInitialize
	#define EXT_OpcUaEventNotificationListInitialize
	#define GET_OpcUaEventNotificationListInitialize(fl)  CAL_CMGETAPI( "OpcUaEventNotificationListInitialize" ) 
	#define CAL_OpcUaEventNotificationListInitialize pICmpOPCUAStack->IOpcUaEventNotificationListInitialize
	#define CHK_OpcUaEventNotificationListInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaEventNotificationListInitialize  CAL_CMEXPAPI( "OpcUaEventNotificationListInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaEventNotificationListInitialize  PFOPCUAEVENTNOTIFICATIONLISTINITIALIZE pfOpcUaEventNotificationListInitialize;
	#define EXT_OpcUaEventNotificationListInitialize  extern PFOPCUAEVENTNOTIFICATIONLISTINITIALIZE pfOpcUaEventNotificationListInitialize;
	#define GET_OpcUaEventNotificationListInitialize(fl)  s_pfCMGetAPI2( "OpcUaEventNotificationListInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaEventNotificationListInitialize, (fl), 0, 0)
	#define CAL_OpcUaEventNotificationListInitialize  pfOpcUaEventNotificationListInitialize
	#define CHK_OpcUaEventNotificationListInitialize  (pfOpcUaEventNotificationListInitialize != NULL)
	#define EXP_OpcUaEventNotificationListInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEventNotificationListInitialize", (RTS_UINTPTR)OpcUaEventNotificationListInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaEventNotificationListClear(OpcUa_EventNotificationList* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAEVENTNOTIFICATIONLISTCLEAR) (OpcUa_EventNotificationList* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAEVENTNOTIFICATIONLISTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaEventNotificationListClear
	#define EXT_OpcUaEventNotificationListClear
	#define GET_OpcUaEventNotificationListClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaEventNotificationListClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaEventNotificationListClear  FALSE
	#define EXP_OpcUaEventNotificationListClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaEventNotificationListClear
	#define EXT_OpcUaEventNotificationListClear
	#define GET_OpcUaEventNotificationListClear(fl)  CAL_CMGETAPI( "OpcUaEventNotificationListClear" ) 
	#define CAL_OpcUaEventNotificationListClear  OpcUaEventNotificationListClear
	#define CHK_OpcUaEventNotificationListClear  TRUE
	#define EXP_OpcUaEventNotificationListClear  CAL_CMEXPAPI( "OpcUaEventNotificationListClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaEventNotificationListClear
	#define EXT_OpcUaEventNotificationListClear
	#define GET_OpcUaEventNotificationListClear(fl)  CAL_CMGETAPI( "OpcUaEventNotificationListClear" ) 
	#define CAL_OpcUaEventNotificationListClear  OpcUaEventNotificationListClear
	#define CHK_OpcUaEventNotificationListClear  TRUE
	#define EXP_OpcUaEventNotificationListClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEventNotificationListClear", (RTS_UINTPTR)OpcUaEventNotificationListClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaEventNotificationListClear
	#define EXT_CmpOPCUAStackOpcUaEventNotificationListClear
	#define GET_CmpOPCUAStackOpcUaEventNotificationListClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaEventNotificationListClear pICmpOPCUAStack->IOpcUaEventNotificationListClear
	#define CHK_CmpOPCUAStackOpcUaEventNotificationListClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaEventNotificationListClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaEventNotificationListClear
	#define EXT_OpcUaEventNotificationListClear
	#define GET_OpcUaEventNotificationListClear(fl)  CAL_CMGETAPI( "OpcUaEventNotificationListClear" ) 
	#define CAL_OpcUaEventNotificationListClear pICmpOPCUAStack->IOpcUaEventNotificationListClear
	#define CHK_OpcUaEventNotificationListClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaEventNotificationListClear  CAL_CMEXPAPI( "OpcUaEventNotificationListClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaEventNotificationListClear  PFOPCUAEVENTNOTIFICATIONLISTCLEAR pfOpcUaEventNotificationListClear;
	#define EXT_OpcUaEventNotificationListClear  extern PFOPCUAEVENTNOTIFICATIONLISTCLEAR pfOpcUaEventNotificationListClear;
	#define GET_OpcUaEventNotificationListClear(fl)  s_pfCMGetAPI2( "OpcUaEventNotificationListClear", (RTS_VOID_FCTPTR *)&pfOpcUaEventNotificationListClear, (fl), 0, 0)
	#define CAL_OpcUaEventNotificationListClear  pfOpcUaEventNotificationListClear
	#define CHK_OpcUaEventNotificationListClear  (pfOpcUaEventNotificationListClear != NULL)
	#define EXP_OpcUaEventNotificationListClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEventNotificationListClear", (RTS_UINTPTR)OpcUaEventNotificationListClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaEventFieldListInitialize(OpcUa_EventFieldList* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAEVENTFIELDLISTINITIALIZE) (OpcUa_EventFieldList* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAEVENTFIELDLISTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaEventFieldListInitialize
	#define EXT_OpcUaEventFieldListInitialize
	#define GET_OpcUaEventFieldListInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaEventFieldListInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaEventFieldListInitialize  FALSE
	#define EXP_OpcUaEventFieldListInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaEventFieldListInitialize
	#define EXT_OpcUaEventFieldListInitialize
	#define GET_OpcUaEventFieldListInitialize(fl)  CAL_CMGETAPI( "OpcUaEventFieldListInitialize" ) 
	#define CAL_OpcUaEventFieldListInitialize  OpcUaEventFieldListInitialize
	#define CHK_OpcUaEventFieldListInitialize  TRUE
	#define EXP_OpcUaEventFieldListInitialize  CAL_CMEXPAPI( "OpcUaEventFieldListInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaEventFieldListInitialize
	#define EXT_OpcUaEventFieldListInitialize
	#define GET_OpcUaEventFieldListInitialize(fl)  CAL_CMGETAPI( "OpcUaEventFieldListInitialize" ) 
	#define CAL_OpcUaEventFieldListInitialize  OpcUaEventFieldListInitialize
	#define CHK_OpcUaEventFieldListInitialize  TRUE
	#define EXP_OpcUaEventFieldListInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEventFieldListInitialize", (RTS_UINTPTR)OpcUaEventFieldListInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaEventFieldListInitialize
	#define EXT_CmpOPCUAStackOpcUaEventFieldListInitialize
	#define GET_CmpOPCUAStackOpcUaEventFieldListInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaEventFieldListInitialize pICmpOPCUAStack->IOpcUaEventFieldListInitialize
	#define CHK_CmpOPCUAStackOpcUaEventFieldListInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaEventFieldListInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaEventFieldListInitialize
	#define EXT_OpcUaEventFieldListInitialize
	#define GET_OpcUaEventFieldListInitialize(fl)  CAL_CMGETAPI( "OpcUaEventFieldListInitialize" ) 
	#define CAL_OpcUaEventFieldListInitialize pICmpOPCUAStack->IOpcUaEventFieldListInitialize
	#define CHK_OpcUaEventFieldListInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaEventFieldListInitialize  CAL_CMEXPAPI( "OpcUaEventFieldListInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaEventFieldListInitialize  PFOPCUAEVENTFIELDLISTINITIALIZE pfOpcUaEventFieldListInitialize;
	#define EXT_OpcUaEventFieldListInitialize  extern PFOPCUAEVENTFIELDLISTINITIALIZE pfOpcUaEventFieldListInitialize;
	#define GET_OpcUaEventFieldListInitialize(fl)  s_pfCMGetAPI2( "OpcUaEventFieldListInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaEventFieldListInitialize, (fl), 0, 0)
	#define CAL_OpcUaEventFieldListInitialize  pfOpcUaEventFieldListInitialize
	#define CHK_OpcUaEventFieldListInitialize  (pfOpcUaEventFieldListInitialize != NULL)
	#define EXP_OpcUaEventFieldListInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEventFieldListInitialize", (RTS_UINTPTR)OpcUaEventFieldListInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaEventFieldListClear(OpcUa_EventFieldList* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAEVENTFIELDLISTCLEAR) (OpcUa_EventFieldList* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAEVENTFIELDLISTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaEventFieldListClear
	#define EXT_OpcUaEventFieldListClear
	#define GET_OpcUaEventFieldListClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaEventFieldListClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaEventFieldListClear  FALSE
	#define EXP_OpcUaEventFieldListClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaEventFieldListClear
	#define EXT_OpcUaEventFieldListClear
	#define GET_OpcUaEventFieldListClear(fl)  CAL_CMGETAPI( "OpcUaEventFieldListClear" ) 
	#define CAL_OpcUaEventFieldListClear  OpcUaEventFieldListClear
	#define CHK_OpcUaEventFieldListClear  TRUE
	#define EXP_OpcUaEventFieldListClear  CAL_CMEXPAPI( "OpcUaEventFieldListClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaEventFieldListClear
	#define EXT_OpcUaEventFieldListClear
	#define GET_OpcUaEventFieldListClear(fl)  CAL_CMGETAPI( "OpcUaEventFieldListClear" ) 
	#define CAL_OpcUaEventFieldListClear  OpcUaEventFieldListClear
	#define CHK_OpcUaEventFieldListClear  TRUE
	#define EXP_OpcUaEventFieldListClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEventFieldListClear", (RTS_UINTPTR)OpcUaEventFieldListClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaEventFieldListClear
	#define EXT_CmpOPCUAStackOpcUaEventFieldListClear
	#define GET_CmpOPCUAStackOpcUaEventFieldListClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaEventFieldListClear pICmpOPCUAStack->IOpcUaEventFieldListClear
	#define CHK_CmpOPCUAStackOpcUaEventFieldListClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaEventFieldListClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaEventFieldListClear
	#define EXT_OpcUaEventFieldListClear
	#define GET_OpcUaEventFieldListClear(fl)  CAL_CMGETAPI( "OpcUaEventFieldListClear" ) 
	#define CAL_OpcUaEventFieldListClear pICmpOPCUAStack->IOpcUaEventFieldListClear
	#define CHK_OpcUaEventFieldListClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaEventFieldListClear  CAL_CMEXPAPI( "OpcUaEventFieldListClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaEventFieldListClear  PFOPCUAEVENTFIELDLISTCLEAR pfOpcUaEventFieldListClear;
	#define EXT_OpcUaEventFieldListClear  extern PFOPCUAEVENTFIELDLISTCLEAR pfOpcUaEventFieldListClear;
	#define GET_OpcUaEventFieldListClear(fl)  s_pfCMGetAPI2( "OpcUaEventFieldListClear", (RTS_VOID_FCTPTR *)&pfOpcUaEventFieldListClear, (fl), 0, 0)
	#define CAL_OpcUaEventFieldListClear  pfOpcUaEventFieldListClear
	#define CHK_OpcUaEventFieldListClear  (pfOpcUaEventFieldListClear != NULL)
	#define EXP_OpcUaEventFieldListClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEventFieldListClear", (RTS_UINTPTR)OpcUaEventFieldListClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaSimpleAttributeOperandInitialize(OpcUa_SimpleAttributeOperand* pValue);
typedef OpcUa_Void (CDECL * PFOPCUASIMPLEATTRIBUTEOPERANDINITIALIZE) (OpcUa_SimpleAttributeOperand* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASIMPLEATTRIBUTEOPERANDINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaSimpleAttributeOperandInitialize
	#define EXT_OpcUaSimpleAttributeOperandInitialize
	#define GET_OpcUaSimpleAttributeOperandInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaSimpleAttributeOperandInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaSimpleAttributeOperandInitialize  FALSE
	#define EXP_OpcUaSimpleAttributeOperandInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaSimpleAttributeOperandInitialize
	#define EXT_OpcUaSimpleAttributeOperandInitialize
	#define GET_OpcUaSimpleAttributeOperandInitialize(fl)  CAL_CMGETAPI( "OpcUaSimpleAttributeOperandInitialize" ) 
	#define CAL_OpcUaSimpleAttributeOperandInitialize  OpcUaSimpleAttributeOperandInitialize
	#define CHK_OpcUaSimpleAttributeOperandInitialize  TRUE
	#define EXP_OpcUaSimpleAttributeOperandInitialize  CAL_CMEXPAPI( "OpcUaSimpleAttributeOperandInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaSimpleAttributeOperandInitialize
	#define EXT_OpcUaSimpleAttributeOperandInitialize
	#define GET_OpcUaSimpleAttributeOperandInitialize(fl)  CAL_CMGETAPI( "OpcUaSimpleAttributeOperandInitialize" ) 
	#define CAL_OpcUaSimpleAttributeOperandInitialize  OpcUaSimpleAttributeOperandInitialize
	#define CHK_OpcUaSimpleAttributeOperandInitialize  TRUE
	#define EXP_OpcUaSimpleAttributeOperandInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSimpleAttributeOperandInitialize", (RTS_UINTPTR)OpcUaSimpleAttributeOperandInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaSimpleAttributeOperandInitialize
	#define EXT_CmpOPCUAStackOpcUaSimpleAttributeOperandInitialize
	#define GET_CmpOPCUAStackOpcUaSimpleAttributeOperandInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaSimpleAttributeOperandInitialize pICmpOPCUAStack->IOpcUaSimpleAttributeOperandInitialize
	#define CHK_CmpOPCUAStackOpcUaSimpleAttributeOperandInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaSimpleAttributeOperandInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaSimpleAttributeOperandInitialize
	#define EXT_OpcUaSimpleAttributeOperandInitialize
	#define GET_OpcUaSimpleAttributeOperandInitialize(fl)  CAL_CMGETAPI( "OpcUaSimpleAttributeOperandInitialize" ) 
	#define CAL_OpcUaSimpleAttributeOperandInitialize pICmpOPCUAStack->IOpcUaSimpleAttributeOperandInitialize
	#define CHK_OpcUaSimpleAttributeOperandInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaSimpleAttributeOperandInitialize  CAL_CMEXPAPI( "OpcUaSimpleAttributeOperandInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaSimpleAttributeOperandInitialize  PFOPCUASIMPLEATTRIBUTEOPERANDINITIALIZE pfOpcUaSimpleAttributeOperandInitialize;
	#define EXT_OpcUaSimpleAttributeOperandInitialize  extern PFOPCUASIMPLEATTRIBUTEOPERANDINITIALIZE pfOpcUaSimpleAttributeOperandInitialize;
	#define GET_OpcUaSimpleAttributeOperandInitialize(fl)  s_pfCMGetAPI2( "OpcUaSimpleAttributeOperandInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaSimpleAttributeOperandInitialize, (fl), 0, 0)
	#define CAL_OpcUaSimpleAttributeOperandInitialize  pfOpcUaSimpleAttributeOperandInitialize
	#define CHK_OpcUaSimpleAttributeOperandInitialize  (pfOpcUaSimpleAttributeOperandInitialize != NULL)
	#define EXP_OpcUaSimpleAttributeOperandInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSimpleAttributeOperandInitialize", (RTS_UINTPTR)OpcUaSimpleAttributeOperandInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaSimpleAttributeOperandClear(OpcUa_SimpleAttributeOperand* pValue);
typedef OpcUa_Void (CDECL * PFOPCUASIMPLEATTRIBUTEOPERANDCLEAR) (OpcUa_SimpleAttributeOperand* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASIMPLEATTRIBUTEOPERANDCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaSimpleAttributeOperandClear
	#define EXT_OpcUaSimpleAttributeOperandClear
	#define GET_OpcUaSimpleAttributeOperandClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaSimpleAttributeOperandClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaSimpleAttributeOperandClear  FALSE
	#define EXP_OpcUaSimpleAttributeOperandClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaSimpleAttributeOperandClear
	#define EXT_OpcUaSimpleAttributeOperandClear
	#define GET_OpcUaSimpleAttributeOperandClear(fl)  CAL_CMGETAPI( "OpcUaSimpleAttributeOperandClear" ) 
	#define CAL_OpcUaSimpleAttributeOperandClear  OpcUaSimpleAttributeOperandClear
	#define CHK_OpcUaSimpleAttributeOperandClear  TRUE
	#define EXP_OpcUaSimpleAttributeOperandClear  CAL_CMEXPAPI( "OpcUaSimpleAttributeOperandClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaSimpleAttributeOperandClear
	#define EXT_OpcUaSimpleAttributeOperandClear
	#define GET_OpcUaSimpleAttributeOperandClear(fl)  CAL_CMGETAPI( "OpcUaSimpleAttributeOperandClear" ) 
	#define CAL_OpcUaSimpleAttributeOperandClear  OpcUaSimpleAttributeOperandClear
	#define CHK_OpcUaSimpleAttributeOperandClear  TRUE
	#define EXP_OpcUaSimpleAttributeOperandClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSimpleAttributeOperandClear", (RTS_UINTPTR)OpcUaSimpleAttributeOperandClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaSimpleAttributeOperandClear
	#define EXT_CmpOPCUAStackOpcUaSimpleAttributeOperandClear
	#define GET_CmpOPCUAStackOpcUaSimpleAttributeOperandClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaSimpleAttributeOperandClear pICmpOPCUAStack->IOpcUaSimpleAttributeOperandClear
	#define CHK_CmpOPCUAStackOpcUaSimpleAttributeOperandClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaSimpleAttributeOperandClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaSimpleAttributeOperandClear
	#define EXT_OpcUaSimpleAttributeOperandClear
	#define GET_OpcUaSimpleAttributeOperandClear(fl)  CAL_CMGETAPI( "OpcUaSimpleAttributeOperandClear" ) 
	#define CAL_OpcUaSimpleAttributeOperandClear pICmpOPCUAStack->IOpcUaSimpleAttributeOperandClear
	#define CHK_OpcUaSimpleAttributeOperandClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaSimpleAttributeOperandClear  CAL_CMEXPAPI( "OpcUaSimpleAttributeOperandClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaSimpleAttributeOperandClear  PFOPCUASIMPLEATTRIBUTEOPERANDCLEAR pfOpcUaSimpleAttributeOperandClear;
	#define EXT_OpcUaSimpleAttributeOperandClear  extern PFOPCUASIMPLEATTRIBUTEOPERANDCLEAR pfOpcUaSimpleAttributeOperandClear;
	#define GET_OpcUaSimpleAttributeOperandClear(fl)  s_pfCMGetAPI2( "OpcUaSimpleAttributeOperandClear", (RTS_VOID_FCTPTR *)&pfOpcUaSimpleAttributeOperandClear, (fl), 0, 0)
	#define CAL_OpcUaSimpleAttributeOperandClear  pfOpcUaSimpleAttributeOperandClear
	#define CHK_OpcUaSimpleAttributeOperandClear  (pfOpcUaSimpleAttributeOperandClear != NULL)
	#define EXP_OpcUaSimpleAttributeOperandClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSimpleAttributeOperandClear", (RTS_UINTPTR)OpcUaSimpleAttributeOperandClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaFindServersRequestInitialize(OpcUa_FindServersRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAFINDSERVERSREQUESTINITIALIZE) (OpcUa_FindServersRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAFINDSERVERSREQUESTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaFindServersRequestInitialize
	#define EXT_OpcUaFindServersRequestInitialize
	#define GET_OpcUaFindServersRequestInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaFindServersRequestInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaFindServersRequestInitialize  FALSE
	#define EXP_OpcUaFindServersRequestInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaFindServersRequestInitialize
	#define EXT_OpcUaFindServersRequestInitialize
	#define GET_OpcUaFindServersRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaFindServersRequestInitialize" ) 
	#define CAL_OpcUaFindServersRequestInitialize  OpcUaFindServersRequestInitialize
	#define CHK_OpcUaFindServersRequestInitialize  TRUE
	#define EXP_OpcUaFindServersRequestInitialize  CAL_CMEXPAPI( "OpcUaFindServersRequestInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaFindServersRequestInitialize
	#define EXT_OpcUaFindServersRequestInitialize
	#define GET_OpcUaFindServersRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaFindServersRequestInitialize" ) 
	#define CAL_OpcUaFindServersRequestInitialize  OpcUaFindServersRequestInitialize
	#define CHK_OpcUaFindServersRequestInitialize  TRUE
	#define EXP_OpcUaFindServersRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaFindServersRequestInitialize", (RTS_UINTPTR)OpcUaFindServersRequestInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaFindServersRequestInitialize
	#define EXT_CmpOPCUAStackOpcUaFindServersRequestInitialize
	#define GET_CmpOPCUAStackOpcUaFindServersRequestInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaFindServersRequestInitialize pICmpOPCUAStack->IOpcUaFindServersRequestInitialize
	#define CHK_CmpOPCUAStackOpcUaFindServersRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaFindServersRequestInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaFindServersRequestInitialize
	#define EXT_OpcUaFindServersRequestInitialize
	#define GET_OpcUaFindServersRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaFindServersRequestInitialize" ) 
	#define CAL_OpcUaFindServersRequestInitialize pICmpOPCUAStack->IOpcUaFindServersRequestInitialize
	#define CHK_OpcUaFindServersRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaFindServersRequestInitialize  CAL_CMEXPAPI( "OpcUaFindServersRequestInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaFindServersRequestInitialize  PFOPCUAFINDSERVERSREQUESTINITIALIZE pfOpcUaFindServersRequestInitialize;
	#define EXT_OpcUaFindServersRequestInitialize  extern PFOPCUAFINDSERVERSREQUESTINITIALIZE pfOpcUaFindServersRequestInitialize;
	#define GET_OpcUaFindServersRequestInitialize(fl)  s_pfCMGetAPI2( "OpcUaFindServersRequestInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaFindServersRequestInitialize, (fl), 0, 0)
	#define CAL_OpcUaFindServersRequestInitialize  pfOpcUaFindServersRequestInitialize
	#define CHK_OpcUaFindServersRequestInitialize  (pfOpcUaFindServersRequestInitialize != NULL)
	#define EXP_OpcUaFindServersRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaFindServersRequestInitialize", (RTS_UINTPTR)OpcUaFindServersRequestInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaFindServersRequestClear(OpcUa_FindServersRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAFINDSERVERSREQUESTCLEAR) (OpcUa_FindServersRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAFINDSERVERSREQUESTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaFindServersRequestClear
	#define EXT_OpcUaFindServersRequestClear
	#define GET_OpcUaFindServersRequestClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaFindServersRequestClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaFindServersRequestClear  FALSE
	#define EXP_OpcUaFindServersRequestClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaFindServersRequestClear
	#define EXT_OpcUaFindServersRequestClear
	#define GET_OpcUaFindServersRequestClear(fl)  CAL_CMGETAPI( "OpcUaFindServersRequestClear" ) 
	#define CAL_OpcUaFindServersRequestClear  OpcUaFindServersRequestClear
	#define CHK_OpcUaFindServersRequestClear  TRUE
	#define EXP_OpcUaFindServersRequestClear  CAL_CMEXPAPI( "OpcUaFindServersRequestClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaFindServersRequestClear
	#define EXT_OpcUaFindServersRequestClear
	#define GET_OpcUaFindServersRequestClear(fl)  CAL_CMGETAPI( "OpcUaFindServersRequestClear" ) 
	#define CAL_OpcUaFindServersRequestClear  OpcUaFindServersRequestClear
	#define CHK_OpcUaFindServersRequestClear  TRUE
	#define EXP_OpcUaFindServersRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaFindServersRequestClear", (RTS_UINTPTR)OpcUaFindServersRequestClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaFindServersRequestClear
	#define EXT_CmpOPCUAStackOpcUaFindServersRequestClear
	#define GET_CmpOPCUAStackOpcUaFindServersRequestClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaFindServersRequestClear pICmpOPCUAStack->IOpcUaFindServersRequestClear
	#define CHK_CmpOPCUAStackOpcUaFindServersRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaFindServersRequestClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaFindServersRequestClear
	#define EXT_OpcUaFindServersRequestClear
	#define GET_OpcUaFindServersRequestClear(fl)  CAL_CMGETAPI( "OpcUaFindServersRequestClear" ) 
	#define CAL_OpcUaFindServersRequestClear pICmpOPCUAStack->IOpcUaFindServersRequestClear
	#define CHK_OpcUaFindServersRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaFindServersRequestClear  CAL_CMEXPAPI( "OpcUaFindServersRequestClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaFindServersRequestClear  PFOPCUAFINDSERVERSREQUESTCLEAR pfOpcUaFindServersRequestClear;
	#define EXT_OpcUaFindServersRequestClear  extern PFOPCUAFINDSERVERSREQUESTCLEAR pfOpcUaFindServersRequestClear;
	#define GET_OpcUaFindServersRequestClear(fl)  s_pfCMGetAPI2( "OpcUaFindServersRequestClear", (RTS_VOID_FCTPTR *)&pfOpcUaFindServersRequestClear, (fl), 0, 0)
	#define CAL_OpcUaFindServersRequestClear  pfOpcUaFindServersRequestClear
	#define CHK_OpcUaFindServersRequestClear  (pfOpcUaFindServersRequestClear != NULL)
	#define EXP_OpcUaFindServersRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaFindServersRequestClear", (RTS_UINTPTR)OpcUaFindServersRequestClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaFindServersResponseInitialize(OpcUa_FindServersResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAFINDSERVERSRESPONSEINITIALIZE) (OpcUa_FindServersResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAFINDSERVERSRESPONSEINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaFindServersResponseInitialize
	#define EXT_OpcUaFindServersResponseInitialize
	#define GET_OpcUaFindServersResponseInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaFindServersResponseInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaFindServersResponseInitialize  FALSE
	#define EXP_OpcUaFindServersResponseInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaFindServersResponseInitialize
	#define EXT_OpcUaFindServersResponseInitialize
	#define GET_OpcUaFindServersResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaFindServersResponseInitialize" ) 
	#define CAL_OpcUaFindServersResponseInitialize  OpcUaFindServersResponseInitialize
	#define CHK_OpcUaFindServersResponseInitialize  TRUE
	#define EXP_OpcUaFindServersResponseInitialize  CAL_CMEXPAPI( "OpcUaFindServersResponseInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaFindServersResponseInitialize
	#define EXT_OpcUaFindServersResponseInitialize
	#define GET_OpcUaFindServersResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaFindServersResponseInitialize" ) 
	#define CAL_OpcUaFindServersResponseInitialize  OpcUaFindServersResponseInitialize
	#define CHK_OpcUaFindServersResponseInitialize  TRUE
	#define EXP_OpcUaFindServersResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaFindServersResponseInitialize", (RTS_UINTPTR)OpcUaFindServersResponseInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaFindServersResponseInitialize
	#define EXT_CmpOPCUAStackOpcUaFindServersResponseInitialize
	#define GET_CmpOPCUAStackOpcUaFindServersResponseInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaFindServersResponseInitialize pICmpOPCUAStack->IOpcUaFindServersResponseInitialize
	#define CHK_CmpOPCUAStackOpcUaFindServersResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaFindServersResponseInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaFindServersResponseInitialize
	#define EXT_OpcUaFindServersResponseInitialize
	#define GET_OpcUaFindServersResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaFindServersResponseInitialize" ) 
	#define CAL_OpcUaFindServersResponseInitialize pICmpOPCUAStack->IOpcUaFindServersResponseInitialize
	#define CHK_OpcUaFindServersResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaFindServersResponseInitialize  CAL_CMEXPAPI( "OpcUaFindServersResponseInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaFindServersResponseInitialize  PFOPCUAFINDSERVERSRESPONSEINITIALIZE pfOpcUaFindServersResponseInitialize;
	#define EXT_OpcUaFindServersResponseInitialize  extern PFOPCUAFINDSERVERSRESPONSEINITIALIZE pfOpcUaFindServersResponseInitialize;
	#define GET_OpcUaFindServersResponseInitialize(fl)  s_pfCMGetAPI2( "OpcUaFindServersResponseInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaFindServersResponseInitialize, (fl), 0, 0)
	#define CAL_OpcUaFindServersResponseInitialize  pfOpcUaFindServersResponseInitialize
	#define CHK_OpcUaFindServersResponseInitialize  (pfOpcUaFindServersResponseInitialize != NULL)
	#define EXP_OpcUaFindServersResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaFindServersResponseInitialize", (RTS_UINTPTR)OpcUaFindServersResponseInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaFindServersResponseClear(OpcUa_FindServersResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAFINDSERVERSRESPONSECLEAR) (OpcUa_FindServersResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAFINDSERVERSRESPONSECLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaFindServersResponseClear
	#define EXT_OpcUaFindServersResponseClear
	#define GET_OpcUaFindServersResponseClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaFindServersResponseClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaFindServersResponseClear  FALSE
	#define EXP_OpcUaFindServersResponseClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaFindServersResponseClear
	#define EXT_OpcUaFindServersResponseClear
	#define GET_OpcUaFindServersResponseClear(fl)  CAL_CMGETAPI( "OpcUaFindServersResponseClear" ) 
	#define CAL_OpcUaFindServersResponseClear  OpcUaFindServersResponseClear
	#define CHK_OpcUaFindServersResponseClear  TRUE
	#define EXP_OpcUaFindServersResponseClear  CAL_CMEXPAPI( "OpcUaFindServersResponseClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaFindServersResponseClear
	#define EXT_OpcUaFindServersResponseClear
	#define GET_OpcUaFindServersResponseClear(fl)  CAL_CMGETAPI( "OpcUaFindServersResponseClear" ) 
	#define CAL_OpcUaFindServersResponseClear  OpcUaFindServersResponseClear
	#define CHK_OpcUaFindServersResponseClear  TRUE
	#define EXP_OpcUaFindServersResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaFindServersResponseClear", (RTS_UINTPTR)OpcUaFindServersResponseClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaFindServersResponseClear
	#define EXT_CmpOPCUAStackOpcUaFindServersResponseClear
	#define GET_CmpOPCUAStackOpcUaFindServersResponseClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaFindServersResponseClear pICmpOPCUAStack->IOpcUaFindServersResponseClear
	#define CHK_CmpOPCUAStackOpcUaFindServersResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaFindServersResponseClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaFindServersResponseClear
	#define EXT_OpcUaFindServersResponseClear
	#define GET_OpcUaFindServersResponseClear(fl)  CAL_CMGETAPI( "OpcUaFindServersResponseClear" ) 
	#define CAL_OpcUaFindServersResponseClear pICmpOPCUAStack->IOpcUaFindServersResponseClear
	#define CHK_OpcUaFindServersResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaFindServersResponseClear  CAL_CMEXPAPI( "OpcUaFindServersResponseClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaFindServersResponseClear  PFOPCUAFINDSERVERSRESPONSECLEAR pfOpcUaFindServersResponseClear;
	#define EXT_OpcUaFindServersResponseClear  extern PFOPCUAFINDSERVERSRESPONSECLEAR pfOpcUaFindServersResponseClear;
	#define GET_OpcUaFindServersResponseClear(fl)  s_pfCMGetAPI2( "OpcUaFindServersResponseClear", (RTS_VOID_FCTPTR *)&pfOpcUaFindServersResponseClear, (fl), 0, 0)
	#define CAL_OpcUaFindServersResponseClear  pfOpcUaFindServersResponseClear
	#define CHK_OpcUaFindServersResponseClear  (pfOpcUaFindServersResponseClear != NULL)
	#define EXP_OpcUaFindServersResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaFindServersResponseClear", (RTS_UINTPTR)OpcUaFindServersResponseClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaFindServersOnNetworkRequestInitialize(OpcUa_FindServersOnNetworkRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAFINDSERVERSONNETWORKREQUESTINITIALIZE) (OpcUa_FindServersOnNetworkRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAFINDSERVERSONNETWORKREQUESTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaFindServersOnNetworkRequestInitialize
	#define EXT_OpcUaFindServersOnNetworkRequestInitialize
	#define GET_OpcUaFindServersOnNetworkRequestInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaFindServersOnNetworkRequestInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaFindServersOnNetworkRequestInitialize  FALSE
	#define EXP_OpcUaFindServersOnNetworkRequestInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaFindServersOnNetworkRequestInitialize
	#define EXT_OpcUaFindServersOnNetworkRequestInitialize
	#define GET_OpcUaFindServersOnNetworkRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaFindServersOnNetworkRequestInitialize" ) 
	#define CAL_OpcUaFindServersOnNetworkRequestInitialize  OpcUaFindServersOnNetworkRequestInitialize
	#define CHK_OpcUaFindServersOnNetworkRequestInitialize  TRUE
	#define EXP_OpcUaFindServersOnNetworkRequestInitialize  CAL_CMEXPAPI( "OpcUaFindServersOnNetworkRequestInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaFindServersOnNetworkRequestInitialize
	#define EXT_OpcUaFindServersOnNetworkRequestInitialize
	#define GET_OpcUaFindServersOnNetworkRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaFindServersOnNetworkRequestInitialize" ) 
	#define CAL_OpcUaFindServersOnNetworkRequestInitialize  OpcUaFindServersOnNetworkRequestInitialize
	#define CHK_OpcUaFindServersOnNetworkRequestInitialize  TRUE
	#define EXP_OpcUaFindServersOnNetworkRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaFindServersOnNetworkRequestInitialize", (RTS_UINTPTR)OpcUaFindServersOnNetworkRequestInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaFindServersOnNetworkRequestInitialize
	#define EXT_CmpOPCUAStackOpcUaFindServersOnNetworkRequestInitialize
	#define GET_CmpOPCUAStackOpcUaFindServersOnNetworkRequestInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaFindServersOnNetworkRequestInitialize pICmpOPCUAStack->IOpcUaFindServersOnNetworkRequestInitialize
	#define CHK_CmpOPCUAStackOpcUaFindServersOnNetworkRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaFindServersOnNetworkRequestInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaFindServersOnNetworkRequestInitialize
	#define EXT_OpcUaFindServersOnNetworkRequestInitialize
	#define GET_OpcUaFindServersOnNetworkRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaFindServersOnNetworkRequestInitialize" ) 
	#define CAL_OpcUaFindServersOnNetworkRequestInitialize pICmpOPCUAStack->IOpcUaFindServersOnNetworkRequestInitialize
	#define CHK_OpcUaFindServersOnNetworkRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaFindServersOnNetworkRequestInitialize  CAL_CMEXPAPI( "OpcUaFindServersOnNetworkRequestInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaFindServersOnNetworkRequestInitialize  PFOPCUAFINDSERVERSONNETWORKREQUESTINITIALIZE pfOpcUaFindServersOnNetworkRequestInitialize;
	#define EXT_OpcUaFindServersOnNetworkRequestInitialize  extern PFOPCUAFINDSERVERSONNETWORKREQUESTINITIALIZE pfOpcUaFindServersOnNetworkRequestInitialize;
	#define GET_OpcUaFindServersOnNetworkRequestInitialize(fl)  s_pfCMGetAPI2( "OpcUaFindServersOnNetworkRequestInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaFindServersOnNetworkRequestInitialize, (fl), 0, 0)
	#define CAL_OpcUaFindServersOnNetworkRequestInitialize  pfOpcUaFindServersOnNetworkRequestInitialize
	#define CHK_OpcUaFindServersOnNetworkRequestInitialize  (pfOpcUaFindServersOnNetworkRequestInitialize != NULL)
	#define EXP_OpcUaFindServersOnNetworkRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaFindServersOnNetworkRequestInitialize", (RTS_UINTPTR)OpcUaFindServersOnNetworkRequestInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaFindServersOnNetworkRequestClear(OpcUa_FindServersOnNetworkRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAFINDSERVERSONNETWORKREQUESTCLEAR) (OpcUa_FindServersOnNetworkRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAFINDSERVERSONNETWORKREQUESTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaFindServersOnNetworkRequestClear
	#define EXT_OpcUaFindServersOnNetworkRequestClear
	#define GET_OpcUaFindServersOnNetworkRequestClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaFindServersOnNetworkRequestClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaFindServersOnNetworkRequestClear  FALSE
	#define EXP_OpcUaFindServersOnNetworkRequestClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaFindServersOnNetworkRequestClear
	#define EXT_OpcUaFindServersOnNetworkRequestClear
	#define GET_OpcUaFindServersOnNetworkRequestClear(fl)  CAL_CMGETAPI( "OpcUaFindServersOnNetworkRequestClear" ) 
	#define CAL_OpcUaFindServersOnNetworkRequestClear  OpcUaFindServersOnNetworkRequestClear
	#define CHK_OpcUaFindServersOnNetworkRequestClear  TRUE
	#define EXP_OpcUaFindServersOnNetworkRequestClear  CAL_CMEXPAPI( "OpcUaFindServersOnNetworkRequestClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaFindServersOnNetworkRequestClear
	#define EXT_OpcUaFindServersOnNetworkRequestClear
	#define GET_OpcUaFindServersOnNetworkRequestClear(fl)  CAL_CMGETAPI( "OpcUaFindServersOnNetworkRequestClear" ) 
	#define CAL_OpcUaFindServersOnNetworkRequestClear  OpcUaFindServersOnNetworkRequestClear
	#define CHK_OpcUaFindServersOnNetworkRequestClear  TRUE
	#define EXP_OpcUaFindServersOnNetworkRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaFindServersOnNetworkRequestClear", (RTS_UINTPTR)OpcUaFindServersOnNetworkRequestClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaFindServersOnNetworkRequestClear
	#define EXT_CmpOPCUAStackOpcUaFindServersOnNetworkRequestClear
	#define GET_CmpOPCUAStackOpcUaFindServersOnNetworkRequestClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaFindServersOnNetworkRequestClear pICmpOPCUAStack->IOpcUaFindServersOnNetworkRequestClear
	#define CHK_CmpOPCUAStackOpcUaFindServersOnNetworkRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaFindServersOnNetworkRequestClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaFindServersOnNetworkRequestClear
	#define EXT_OpcUaFindServersOnNetworkRequestClear
	#define GET_OpcUaFindServersOnNetworkRequestClear(fl)  CAL_CMGETAPI( "OpcUaFindServersOnNetworkRequestClear" ) 
	#define CAL_OpcUaFindServersOnNetworkRequestClear pICmpOPCUAStack->IOpcUaFindServersOnNetworkRequestClear
	#define CHK_OpcUaFindServersOnNetworkRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaFindServersOnNetworkRequestClear  CAL_CMEXPAPI( "OpcUaFindServersOnNetworkRequestClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaFindServersOnNetworkRequestClear  PFOPCUAFINDSERVERSONNETWORKREQUESTCLEAR pfOpcUaFindServersOnNetworkRequestClear;
	#define EXT_OpcUaFindServersOnNetworkRequestClear  extern PFOPCUAFINDSERVERSONNETWORKREQUESTCLEAR pfOpcUaFindServersOnNetworkRequestClear;
	#define GET_OpcUaFindServersOnNetworkRequestClear(fl)  s_pfCMGetAPI2( "OpcUaFindServersOnNetworkRequestClear", (RTS_VOID_FCTPTR *)&pfOpcUaFindServersOnNetworkRequestClear, (fl), 0, 0)
	#define CAL_OpcUaFindServersOnNetworkRequestClear  pfOpcUaFindServersOnNetworkRequestClear
	#define CHK_OpcUaFindServersOnNetworkRequestClear  (pfOpcUaFindServersOnNetworkRequestClear != NULL)
	#define EXP_OpcUaFindServersOnNetworkRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaFindServersOnNetworkRequestClear", (RTS_UINTPTR)OpcUaFindServersOnNetworkRequestClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaFindServersOnNetworkResponseInitialize(OpcUa_FindServersOnNetworkResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAFINDSERVERSONNETWORKRESPONSEINITIALIZE) (OpcUa_FindServersOnNetworkResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAFINDSERVERSONNETWORKRESPONSEINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaFindServersOnNetworkResponseInitialize
	#define EXT_OpcUaFindServersOnNetworkResponseInitialize
	#define GET_OpcUaFindServersOnNetworkResponseInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaFindServersOnNetworkResponseInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaFindServersOnNetworkResponseInitialize  FALSE
	#define EXP_OpcUaFindServersOnNetworkResponseInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaFindServersOnNetworkResponseInitialize
	#define EXT_OpcUaFindServersOnNetworkResponseInitialize
	#define GET_OpcUaFindServersOnNetworkResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaFindServersOnNetworkResponseInitialize" ) 
	#define CAL_OpcUaFindServersOnNetworkResponseInitialize  OpcUaFindServersOnNetworkResponseInitialize
	#define CHK_OpcUaFindServersOnNetworkResponseInitialize  TRUE
	#define EXP_OpcUaFindServersOnNetworkResponseInitialize  CAL_CMEXPAPI( "OpcUaFindServersOnNetworkResponseInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaFindServersOnNetworkResponseInitialize
	#define EXT_OpcUaFindServersOnNetworkResponseInitialize
	#define GET_OpcUaFindServersOnNetworkResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaFindServersOnNetworkResponseInitialize" ) 
	#define CAL_OpcUaFindServersOnNetworkResponseInitialize  OpcUaFindServersOnNetworkResponseInitialize
	#define CHK_OpcUaFindServersOnNetworkResponseInitialize  TRUE
	#define EXP_OpcUaFindServersOnNetworkResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaFindServersOnNetworkResponseInitialize", (RTS_UINTPTR)OpcUaFindServersOnNetworkResponseInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaFindServersOnNetworkResponseInitialize
	#define EXT_CmpOPCUAStackOpcUaFindServersOnNetworkResponseInitialize
	#define GET_CmpOPCUAStackOpcUaFindServersOnNetworkResponseInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaFindServersOnNetworkResponseInitialize pICmpOPCUAStack->IOpcUaFindServersOnNetworkResponseInitialize
	#define CHK_CmpOPCUAStackOpcUaFindServersOnNetworkResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaFindServersOnNetworkResponseInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaFindServersOnNetworkResponseInitialize
	#define EXT_OpcUaFindServersOnNetworkResponseInitialize
	#define GET_OpcUaFindServersOnNetworkResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaFindServersOnNetworkResponseInitialize" ) 
	#define CAL_OpcUaFindServersOnNetworkResponseInitialize pICmpOPCUAStack->IOpcUaFindServersOnNetworkResponseInitialize
	#define CHK_OpcUaFindServersOnNetworkResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaFindServersOnNetworkResponseInitialize  CAL_CMEXPAPI( "OpcUaFindServersOnNetworkResponseInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaFindServersOnNetworkResponseInitialize  PFOPCUAFINDSERVERSONNETWORKRESPONSEINITIALIZE pfOpcUaFindServersOnNetworkResponseInitialize;
	#define EXT_OpcUaFindServersOnNetworkResponseInitialize  extern PFOPCUAFINDSERVERSONNETWORKRESPONSEINITIALIZE pfOpcUaFindServersOnNetworkResponseInitialize;
	#define GET_OpcUaFindServersOnNetworkResponseInitialize(fl)  s_pfCMGetAPI2( "OpcUaFindServersOnNetworkResponseInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaFindServersOnNetworkResponseInitialize, (fl), 0, 0)
	#define CAL_OpcUaFindServersOnNetworkResponseInitialize  pfOpcUaFindServersOnNetworkResponseInitialize
	#define CHK_OpcUaFindServersOnNetworkResponseInitialize  (pfOpcUaFindServersOnNetworkResponseInitialize != NULL)
	#define EXP_OpcUaFindServersOnNetworkResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaFindServersOnNetworkResponseInitialize", (RTS_UINTPTR)OpcUaFindServersOnNetworkResponseInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaFindServersOnNetworkResponseClear(OpcUa_FindServersOnNetworkResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAFINDSERVERSONNETWORKRESPONSECLEAR) (OpcUa_FindServersOnNetworkResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAFINDSERVERSONNETWORKRESPONSECLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaFindServersOnNetworkResponseClear
	#define EXT_OpcUaFindServersOnNetworkResponseClear
	#define GET_OpcUaFindServersOnNetworkResponseClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaFindServersOnNetworkResponseClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaFindServersOnNetworkResponseClear  FALSE
	#define EXP_OpcUaFindServersOnNetworkResponseClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaFindServersOnNetworkResponseClear
	#define EXT_OpcUaFindServersOnNetworkResponseClear
	#define GET_OpcUaFindServersOnNetworkResponseClear(fl)  CAL_CMGETAPI( "OpcUaFindServersOnNetworkResponseClear" ) 
	#define CAL_OpcUaFindServersOnNetworkResponseClear  OpcUaFindServersOnNetworkResponseClear
	#define CHK_OpcUaFindServersOnNetworkResponseClear  TRUE
	#define EXP_OpcUaFindServersOnNetworkResponseClear  CAL_CMEXPAPI( "OpcUaFindServersOnNetworkResponseClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaFindServersOnNetworkResponseClear
	#define EXT_OpcUaFindServersOnNetworkResponseClear
	#define GET_OpcUaFindServersOnNetworkResponseClear(fl)  CAL_CMGETAPI( "OpcUaFindServersOnNetworkResponseClear" ) 
	#define CAL_OpcUaFindServersOnNetworkResponseClear  OpcUaFindServersOnNetworkResponseClear
	#define CHK_OpcUaFindServersOnNetworkResponseClear  TRUE
	#define EXP_OpcUaFindServersOnNetworkResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaFindServersOnNetworkResponseClear", (RTS_UINTPTR)OpcUaFindServersOnNetworkResponseClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaFindServersOnNetworkResponseClear
	#define EXT_CmpOPCUAStackOpcUaFindServersOnNetworkResponseClear
	#define GET_CmpOPCUAStackOpcUaFindServersOnNetworkResponseClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaFindServersOnNetworkResponseClear pICmpOPCUAStack->IOpcUaFindServersOnNetworkResponseClear
	#define CHK_CmpOPCUAStackOpcUaFindServersOnNetworkResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaFindServersOnNetworkResponseClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaFindServersOnNetworkResponseClear
	#define EXT_OpcUaFindServersOnNetworkResponseClear
	#define GET_OpcUaFindServersOnNetworkResponseClear(fl)  CAL_CMGETAPI( "OpcUaFindServersOnNetworkResponseClear" ) 
	#define CAL_OpcUaFindServersOnNetworkResponseClear pICmpOPCUAStack->IOpcUaFindServersOnNetworkResponseClear
	#define CHK_OpcUaFindServersOnNetworkResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaFindServersOnNetworkResponseClear  CAL_CMEXPAPI( "OpcUaFindServersOnNetworkResponseClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaFindServersOnNetworkResponseClear  PFOPCUAFINDSERVERSONNETWORKRESPONSECLEAR pfOpcUaFindServersOnNetworkResponseClear;
	#define EXT_OpcUaFindServersOnNetworkResponseClear  extern PFOPCUAFINDSERVERSONNETWORKRESPONSECLEAR pfOpcUaFindServersOnNetworkResponseClear;
	#define GET_OpcUaFindServersOnNetworkResponseClear(fl)  s_pfCMGetAPI2( "OpcUaFindServersOnNetworkResponseClear", (RTS_VOID_FCTPTR *)&pfOpcUaFindServersOnNetworkResponseClear, (fl), 0, 0)
	#define CAL_OpcUaFindServersOnNetworkResponseClear  pfOpcUaFindServersOnNetworkResponseClear
	#define CHK_OpcUaFindServersOnNetworkResponseClear  (pfOpcUaFindServersOnNetworkResponseClear != NULL)
	#define EXP_OpcUaFindServersOnNetworkResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaFindServersOnNetworkResponseClear", (RTS_UINTPTR)OpcUaFindServersOnNetworkResponseClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaGetEndpointsRequestInitialize(OpcUa_GetEndpointsRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAGETENDPOINTSREQUESTINITIALIZE) (OpcUa_GetEndpointsRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAGETENDPOINTSREQUESTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaGetEndpointsRequestInitialize
	#define EXT_OpcUaGetEndpointsRequestInitialize
	#define GET_OpcUaGetEndpointsRequestInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaGetEndpointsRequestInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaGetEndpointsRequestInitialize  FALSE
	#define EXP_OpcUaGetEndpointsRequestInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaGetEndpointsRequestInitialize
	#define EXT_OpcUaGetEndpointsRequestInitialize
	#define GET_OpcUaGetEndpointsRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaGetEndpointsRequestInitialize" ) 
	#define CAL_OpcUaGetEndpointsRequestInitialize  OpcUaGetEndpointsRequestInitialize
	#define CHK_OpcUaGetEndpointsRequestInitialize  TRUE
	#define EXP_OpcUaGetEndpointsRequestInitialize  CAL_CMEXPAPI( "OpcUaGetEndpointsRequestInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaGetEndpointsRequestInitialize
	#define EXT_OpcUaGetEndpointsRequestInitialize
	#define GET_OpcUaGetEndpointsRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaGetEndpointsRequestInitialize" ) 
	#define CAL_OpcUaGetEndpointsRequestInitialize  OpcUaGetEndpointsRequestInitialize
	#define CHK_OpcUaGetEndpointsRequestInitialize  TRUE
	#define EXP_OpcUaGetEndpointsRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaGetEndpointsRequestInitialize", (RTS_UINTPTR)OpcUaGetEndpointsRequestInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaGetEndpointsRequestInitialize
	#define EXT_CmpOPCUAStackOpcUaGetEndpointsRequestInitialize
	#define GET_CmpOPCUAStackOpcUaGetEndpointsRequestInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaGetEndpointsRequestInitialize pICmpOPCUAStack->IOpcUaGetEndpointsRequestInitialize
	#define CHK_CmpOPCUAStackOpcUaGetEndpointsRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaGetEndpointsRequestInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaGetEndpointsRequestInitialize
	#define EXT_OpcUaGetEndpointsRequestInitialize
	#define GET_OpcUaGetEndpointsRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaGetEndpointsRequestInitialize" ) 
	#define CAL_OpcUaGetEndpointsRequestInitialize pICmpOPCUAStack->IOpcUaGetEndpointsRequestInitialize
	#define CHK_OpcUaGetEndpointsRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaGetEndpointsRequestInitialize  CAL_CMEXPAPI( "OpcUaGetEndpointsRequestInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaGetEndpointsRequestInitialize  PFOPCUAGETENDPOINTSREQUESTINITIALIZE pfOpcUaGetEndpointsRequestInitialize;
	#define EXT_OpcUaGetEndpointsRequestInitialize  extern PFOPCUAGETENDPOINTSREQUESTINITIALIZE pfOpcUaGetEndpointsRequestInitialize;
	#define GET_OpcUaGetEndpointsRequestInitialize(fl)  s_pfCMGetAPI2( "OpcUaGetEndpointsRequestInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaGetEndpointsRequestInitialize, (fl), 0, 0)
	#define CAL_OpcUaGetEndpointsRequestInitialize  pfOpcUaGetEndpointsRequestInitialize
	#define CHK_OpcUaGetEndpointsRequestInitialize  (pfOpcUaGetEndpointsRequestInitialize != NULL)
	#define EXP_OpcUaGetEndpointsRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaGetEndpointsRequestInitialize", (RTS_UINTPTR)OpcUaGetEndpointsRequestInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaGetEndpointsRequestClear(OpcUa_GetEndpointsRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAGETENDPOINTSREQUESTCLEAR) (OpcUa_GetEndpointsRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAGETENDPOINTSREQUESTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaGetEndpointsRequestClear
	#define EXT_OpcUaGetEndpointsRequestClear
	#define GET_OpcUaGetEndpointsRequestClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaGetEndpointsRequestClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaGetEndpointsRequestClear  FALSE
	#define EXP_OpcUaGetEndpointsRequestClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaGetEndpointsRequestClear
	#define EXT_OpcUaGetEndpointsRequestClear
	#define GET_OpcUaGetEndpointsRequestClear(fl)  CAL_CMGETAPI( "OpcUaGetEndpointsRequestClear" ) 
	#define CAL_OpcUaGetEndpointsRequestClear  OpcUaGetEndpointsRequestClear
	#define CHK_OpcUaGetEndpointsRequestClear  TRUE
	#define EXP_OpcUaGetEndpointsRequestClear  CAL_CMEXPAPI( "OpcUaGetEndpointsRequestClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaGetEndpointsRequestClear
	#define EXT_OpcUaGetEndpointsRequestClear
	#define GET_OpcUaGetEndpointsRequestClear(fl)  CAL_CMGETAPI( "OpcUaGetEndpointsRequestClear" ) 
	#define CAL_OpcUaGetEndpointsRequestClear  OpcUaGetEndpointsRequestClear
	#define CHK_OpcUaGetEndpointsRequestClear  TRUE
	#define EXP_OpcUaGetEndpointsRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaGetEndpointsRequestClear", (RTS_UINTPTR)OpcUaGetEndpointsRequestClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaGetEndpointsRequestClear
	#define EXT_CmpOPCUAStackOpcUaGetEndpointsRequestClear
	#define GET_CmpOPCUAStackOpcUaGetEndpointsRequestClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaGetEndpointsRequestClear pICmpOPCUAStack->IOpcUaGetEndpointsRequestClear
	#define CHK_CmpOPCUAStackOpcUaGetEndpointsRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaGetEndpointsRequestClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaGetEndpointsRequestClear
	#define EXT_OpcUaGetEndpointsRequestClear
	#define GET_OpcUaGetEndpointsRequestClear(fl)  CAL_CMGETAPI( "OpcUaGetEndpointsRequestClear" ) 
	#define CAL_OpcUaGetEndpointsRequestClear pICmpOPCUAStack->IOpcUaGetEndpointsRequestClear
	#define CHK_OpcUaGetEndpointsRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaGetEndpointsRequestClear  CAL_CMEXPAPI( "OpcUaGetEndpointsRequestClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaGetEndpointsRequestClear  PFOPCUAGETENDPOINTSREQUESTCLEAR pfOpcUaGetEndpointsRequestClear;
	#define EXT_OpcUaGetEndpointsRequestClear  extern PFOPCUAGETENDPOINTSREQUESTCLEAR pfOpcUaGetEndpointsRequestClear;
	#define GET_OpcUaGetEndpointsRequestClear(fl)  s_pfCMGetAPI2( "OpcUaGetEndpointsRequestClear", (RTS_VOID_FCTPTR *)&pfOpcUaGetEndpointsRequestClear, (fl), 0, 0)
	#define CAL_OpcUaGetEndpointsRequestClear  pfOpcUaGetEndpointsRequestClear
	#define CHK_OpcUaGetEndpointsRequestClear  (pfOpcUaGetEndpointsRequestClear != NULL)
	#define EXP_OpcUaGetEndpointsRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaGetEndpointsRequestClear", (RTS_UINTPTR)OpcUaGetEndpointsRequestClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaGetEndpointsResponseInitialize(OpcUa_GetEndpointsResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAGETENDPOINTSRESPONSEINITIALIZE) (OpcUa_GetEndpointsResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAGETENDPOINTSRESPONSEINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaGetEndpointsResponseInitialize
	#define EXT_OpcUaGetEndpointsResponseInitialize
	#define GET_OpcUaGetEndpointsResponseInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaGetEndpointsResponseInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaGetEndpointsResponseInitialize  FALSE
	#define EXP_OpcUaGetEndpointsResponseInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaGetEndpointsResponseInitialize
	#define EXT_OpcUaGetEndpointsResponseInitialize
	#define GET_OpcUaGetEndpointsResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaGetEndpointsResponseInitialize" ) 
	#define CAL_OpcUaGetEndpointsResponseInitialize  OpcUaGetEndpointsResponseInitialize
	#define CHK_OpcUaGetEndpointsResponseInitialize  TRUE
	#define EXP_OpcUaGetEndpointsResponseInitialize  CAL_CMEXPAPI( "OpcUaGetEndpointsResponseInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaGetEndpointsResponseInitialize
	#define EXT_OpcUaGetEndpointsResponseInitialize
	#define GET_OpcUaGetEndpointsResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaGetEndpointsResponseInitialize" ) 
	#define CAL_OpcUaGetEndpointsResponseInitialize  OpcUaGetEndpointsResponseInitialize
	#define CHK_OpcUaGetEndpointsResponseInitialize  TRUE
	#define EXP_OpcUaGetEndpointsResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaGetEndpointsResponseInitialize", (RTS_UINTPTR)OpcUaGetEndpointsResponseInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaGetEndpointsResponseInitialize
	#define EXT_CmpOPCUAStackOpcUaGetEndpointsResponseInitialize
	#define GET_CmpOPCUAStackOpcUaGetEndpointsResponseInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaGetEndpointsResponseInitialize pICmpOPCUAStack->IOpcUaGetEndpointsResponseInitialize
	#define CHK_CmpOPCUAStackOpcUaGetEndpointsResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaGetEndpointsResponseInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaGetEndpointsResponseInitialize
	#define EXT_OpcUaGetEndpointsResponseInitialize
	#define GET_OpcUaGetEndpointsResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaGetEndpointsResponseInitialize" ) 
	#define CAL_OpcUaGetEndpointsResponseInitialize pICmpOPCUAStack->IOpcUaGetEndpointsResponseInitialize
	#define CHK_OpcUaGetEndpointsResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaGetEndpointsResponseInitialize  CAL_CMEXPAPI( "OpcUaGetEndpointsResponseInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaGetEndpointsResponseInitialize  PFOPCUAGETENDPOINTSRESPONSEINITIALIZE pfOpcUaGetEndpointsResponseInitialize;
	#define EXT_OpcUaGetEndpointsResponseInitialize  extern PFOPCUAGETENDPOINTSRESPONSEINITIALIZE pfOpcUaGetEndpointsResponseInitialize;
	#define GET_OpcUaGetEndpointsResponseInitialize(fl)  s_pfCMGetAPI2( "OpcUaGetEndpointsResponseInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaGetEndpointsResponseInitialize, (fl), 0, 0)
	#define CAL_OpcUaGetEndpointsResponseInitialize  pfOpcUaGetEndpointsResponseInitialize
	#define CHK_OpcUaGetEndpointsResponseInitialize  (pfOpcUaGetEndpointsResponseInitialize != NULL)
	#define EXP_OpcUaGetEndpointsResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaGetEndpointsResponseInitialize", (RTS_UINTPTR)OpcUaGetEndpointsResponseInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaGetEndpointsResponseClear(OpcUa_GetEndpointsResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAGETENDPOINTSRESPONSECLEAR) (OpcUa_GetEndpointsResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAGETENDPOINTSRESPONSECLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaGetEndpointsResponseClear
	#define EXT_OpcUaGetEndpointsResponseClear
	#define GET_OpcUaGetEndpointsResponseClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaGetEndpointsResponseClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaGetEndpointsResponseClear  FALSE
	#define EXP_OpcUaGetEndpointsResponseClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaGetEndpointsResponseClear
	#define EXT_OpcUaGetEndpointsResponseClear
	#define GET_OpcUaGetEndpointsResponseClear(fl)  CAL_CMGETAPI( "OpcUaGetEndpointsResponseClear" ) 
	#define CAL_OpcUaGetEndpointsResponseClear  OpcUaGetEndpointsResponseClear
	#define CHK_OpcUaGetEndpointsResponseClear  TRUE
	#define EXP_OpcUaGetEndpointsResponseClear  CAL_CMEXPAPI( "OpcUaGetEndpointsResponseClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaGetEndpointsResponseClear
	#define EXT_OpcUaGetEndpointsResponseClear
	#define GET_OpcUaGetEndpointsResponseClear(fl)  CAL_CMGETAPI( "OpcUaGetEndpointsResponseClear" ) 
	#define CAL_OpcUaGetEndpointsResponseClear  OpcUaGetEndpointsResponseClear
	#define CHK_OpcUaGetEndpointsResponseClear  TRUE
	#define EXP_OpcUaGetEndpointsResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaGetEndpointsResponseClear", (RTS_UINTPTR)OpcUaGetEndpointsResponseClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaGetEndpointsResponseClear
	#define EXT_CmpOPCUAStackOpcUaGetEndpointsResponseClear
	#define GET_CmpOPCUAStackOpcUaGetEndpointsResponseClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaGetEndpointsResponseClear pICmpOPCUAStack->IOpcUaGetEndpointsResponseClear
	#define CHK_CmpOPCUAStackOpcUaGetEndpointsResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaGetEndpointsResponseClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaGetEndpointsResponseClear
	#define EXT_OpcUaGetEndpointsResponseClear
	#define GET_OpcUaGetEndpointsResponseClear(fl)  CAL_CMGETAPI( "OpcUaGetEndpointsResponseClear" ) 
	#define CAL_OpcUaGetEndpointsResponseClear pICmpOPCUAStack->IOpcUaGetEndpointsResponseClear
	#define CHK_OpcUaGetEndpointsResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaGetEndpointsResponseClear  CAL_CMEXPAPI( "OpcUaGetEndpointsResponseClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaGetEndpointsResponseClear  PFOPCUAGETENDPOINTSRESPONSECLEAR pfOpcUaGetEndpointsResponseClear;
	#define EXT_OpcUaGetEndpointsResponseClear  extern PFOPCUAGETENDPOINTSRESPONSECLEAR pfOpcUaGetEndpointsResponseClear;
	#define GET_OpcUaGetEndpointsResponseClear(fl)  s_pfCMGetAPI2( "OpcUaGetEndpointsResponseClear", (RTS_VOID_FCTPTR *)&pfOpcUaGetEndpointsResponseClear, (fl), 0, 0)
	#define CAL_OpcUaGetEndpointsResponseClear  pfOpcUaGetEndpointsResponseClear
	#define CHK_OpcUaGetEndpointsResponseClear  (pfOpcUaGetEndpointsResponseClear != NULL)
	#define EXP_OpcUaGetEndpointsResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaGetEndpointsResponseClear", (RTS_UINTPTR)OpcUaGetEndpointsResponseClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaCreateSessionRequestInitialize(OpcUa_CreateSessionRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUACREATESESSIONREQUESTINITIALIZE) (OpcUa_CreateSessionRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACREATESESSIONREQUESTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaCreateSessionRequestInitialize
	#define EXT_OpcUaCreateSessionRequestInitialize
	#define GET_OpcUaCreateSessionRequestInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaCreateSessionRequestInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaCreateSessionRequestInitialize  FALSE
	#define EXP_OpcUaCreateSessionRequestInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaCreateSessionRequestInitialize
	#define EXT_OpcUaCreateSessionRequestInitialize
	#define GET_OpcUaCreateSessionRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaCreateSessionRequestInitialize" ) 
	#define CAL_OpcUaCreateSessionRequestInitialize  OpcUaCreateSessionRequestInitialize
	#define CHK_OpcUaCreateSessionRequestInitialize  TRUE
	#define EXP_OpcUaCreateSessionRequestInitialize  CAL_CMEXPAPI( "OpcUaCreateSessionRequestInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaCreateSessionRequestInitialize
	#define EXT_OpcUaCreateSessionRequestInitialize
	#define GET_OpcUaCreateSessionRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaCreateSessionRequestInitialize" ) 
	#define CAL_OpcUaCreateSessionRequestInitialize  OpcUaCreateSessionRequestInitialize
	#define CHK_OpcUaCreateSessionRequestInitialize  TRUE
	#define EXP_OpcUaCreateSessionRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCreateSessionRequestInitialize", (RTS_UINTPTR)OpcUaCreateSessionRequestInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaCreateSessionRequestInitialize
	#define EXT_CmpOPCUAStackOpcUaCreateSessionRequestInitialize
	#define GET_CmpOPCUAStackOpcUaCreateSessionRequestInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaCreateSessionRequestInitialize pICmpOPCUAStack->IOpcUaCreateSessionRequestInitialize
	#define CHK_CmpOPCUAStackOpcUaCreateSessionRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaCreateSessionRequestInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaCreateSessionRequestInitialize
	#define EXT_OpcUaCreateSessionRequestInitialize
	#define GET_OpcUaCreateSessionRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaCreateSessionRequestInitialize" ) 
	#define CAL_OpcUaCreateSessionRequestInitialize pICmpOPCUAStack->IOpcUaCreateSessionRequestInitialize
	#define CHK_OpcUaCreateSessionRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaCreateSessionRequestInitialize  CAL_CMEXPAPI( "OpcUaCreateSessionRequestInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaCreateSessionRequestInitialize  PFOPCUACREATESESSIONREQUESTINITIALIZE pfOpcUaCreateSessionRequestInitialize;
	#define EXT_OpcUaCreateSessionRequestInitialize  extern PFOPCUACREATESESSIONREQUESTINITIALIZE pfOpcUaCreateSessionRequestInitialize;
	#define GET_OpcUaCreateSessionRequestInitialize(fl)  s_pfCMGetAPI2( "OpcUaCreateSessionRequestInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaCreateSessionRequestInitialize, (fl), 0, 0)
	#define CAL_OpcUaCreateSessionRequestInitialize  pfOpcUaCreateSessionRequestInitialize
	#define CHK_OpcUaCreateSessionRequestInitialize  (pfOpcUaCreateSessionRequestInitialize != NULL)
	#define EXP_OpcUaCreateSessionRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCreateSessionRequestInitialize", (RTS_UINTPTR)OpcUaCreateSessionRequestInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaCreateSessionRequestClear(OpcUa_CreateSessionRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUACREATESESSIONREQUESTCLEAR) (OpcUa_CreateSessionRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACREATESESSIONREQUESTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaCreateSessionRequestClear
	#define EXT_OpcUaCreateSessionRequestClear
	#define GET_OpcUaCreateSessionRequestClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaCreateSessionRequestClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaCreateSessionRequestClear  FALSE
	#define EXP_OpcUaCreateSessionRequestClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaCreateSessionRequestClear
	#define EXT_OpcUaCreateSessionRequestClear
	#define GET_OpcUaCreateSessionRequestClear(fl)  CAL_CMGETAPI( "OpcUaCreateSessionRequestClear" ) 
	#define CAL_OpcUaCreateSessionRequestClear  OpcUaCreateSessionRequestClear
	#define CHK_OpcUaCreateSessionRequestClear  TRUE
	#define EXP_OpcUaCreateSessionRequestClear  CAL_CMEXPAPI( "OpcUaCreateSessionRequestClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaCreateSessionRequestClear
	#define EXT_OpcUaCreateSessionRequestClear
	#define GET_OpcUaCreateSessionRequestClear(fl)  CAL_CMGETAPI( "OpcUaCreateSessionRequestClear" ) 
	#define CAL_OpcUaCreateSessionRequestClear  OpcUaCreateSessionRequestClear
	#define CHK_OpcUaCreateSessionRequestClear  TRUE
	#define EXP_OpcUaCreateSessionRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCreateSessionRequestClear", (RTS_UINTPTR)OpcUaCreateSessionRequestClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaCreateSessionRequestClear
	#define EXT_CmpOPCUAStackOpcUaCreateSessionRequestClear
	#define GET_CmpOPCUAStackOpcUaCreateSessionRequestClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaCreateSessionRequestClear pICmpOPCUAStack->IOpcUaCreateSessionRequestClear
	#define CHK_CmpOPCUAStackOpcUaCreateSessionRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaCreateSessionRequestClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaCreateSessionRequestClear
	#define EXT_OpcUaCreateSessionRequestClear
	#define GET_OpcUaCreateSessionRequestClear(fl)  CAL_CMGETAPI( "OpcUaCreateSessionRequestClear" ) 
	#define CAL_OpcUaCreateSessionRequestClear pICmpOPCUAStack->IOpcUaCreateSessionRequestClear
	#define CHK_OpcUaCreateSessionRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaCreateSessionRequestClear  CAL_CMEXPAPI( "OpcUaCreateSessionRequestClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaCreateSessionRequestClear  PFOPCUACREATESESSIONREQUESTCLEAR pfOpcUaCreateSessionRequestClear;
	#define EXT_OpcUaCreateSessionRequestClear  extern PFOPCUACREATESESSIONREQUESTCLEAR pfOpcUaCreateSessionRequestClear;
	#define GET_OpcUaCreateSessionRequestClear(fl)  s_pfCMGetAPI2( "OpcUaCreateSessionRequestClear", (RTS_VOID_FCTPTR *)&pfOpcUaCreateSessionRequestClear, (fl), 0, 0)
	#define CAL_OpcUaCreateSessionRequestClear  pfOpcUaCreateSessionRequestClear
	#define CHK_OpcUaCreateSessionRequestClear  (pfOpcUaCreateSessionRequestClear != NULL)
	#define EXP_OpcUaCreateSessionRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCreateSessionRequestClear", (RTS_UINTPTR)OpcUaCreateSessionRequestClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaCreateSessionResponseInitialize(OpcUa_CreateSessionResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUACREATESESSIONRESPONSEINITIALIZE) (OpcUa_CreateSessionResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACREATESESSIONRESPONSEINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaCreateSessionResponseInitialize
	#define EXT_OpcUaCreateSessionResponseInitialize
	#define GET_OpcUaCreateSessionResponseInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaCreateSessionResponseInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaCreateSessionResponseInitialize  FALSE
	#define EXP_OpcUaCreateSessionResponseInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaCreateSessionResponseInitialize
	#define EXT_OpcUaCreateSessionResponseInitialize
	#define GET_OpcUaCreateSessionResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaCreateSessionResponseInitialize" ) 
	#define CAL_OpcUaCreateSessionResponseInitialize  OpcUaCreateSessionResponseInitialize
	#define CHK_OpcUaCreateSessionResponseInitialize  TRUE
	#define EXP_OpcUaCreateSessionResponseInitialize  CAL_CMEXPAPI( "OpcUaCreateSessionResponseInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaCreateSessionResponseInitialize
	#define EXT_OpcUaCreateSessionResponseInitialize
	#define GET_OpcUaCreateSessionResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaCreateSessionResponseInitialize" ) 
	#define CAL_OpcUaCreateSessionResponseInitialize  OpcUaCreateSessionResponseInitialize
	#define CHK_OpcUaCreateSessionResponseInitialize  TRUE
	#define EXP_OpcUaCreateSessionResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCreateSessionResponseInitialize", (RTS_UINTPTR)OpcUaCreateSessionResponseInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaCreateSessionResponseInitialize
	#define EXT_CmpOPCUAStackOpcUaCreateSessionResponseInitialize
	#define GET_CmpOPCUAStackOpcUaCreateSessionResponseInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaCreateSessionResponseInitialize pICmpOPCUAStack->IOpcUaCreateSessionResponseInitialize
	#define CHK_CmpOPCUAStackOpcUaCreateSessionResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaCreateSessionResponseInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaCreateSessionResponseInitialize
	#define EXT_OpcUaCreateSessionResponseInitialize
	#define GET_OpcUaCreateSessionResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaCreateSessionResponseInitialize" ) 
	#define CAL_OpcUaCreateSessionResponseInitialize pICmpOPCUAStack->IOpcUaCreateSessionResponseInitialize
	#define CHK_OpcUaCreateSessionResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaCreateSessionResponseInitialize  CAL_CMEXPAPI( "OpcUaCreateSessionResponseInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaCreateSessionResponseInitialize  PFOPCUACREATESESSIONRESPONSEINITIALIZE pfOpcUaCreateSessionResponseInitialize;
	#define EXT_OpcUaCreateSessionResponseInitialize  extern PFOPCUACREATESESSIONRESPONSEINITIALIZE pfOpcUaCreateSessionResponseInitialize;
	#define GET_OpcUaCreateSessionResponseInitialize(fl)  s_pfCMGetAPI2( "OpcUaCreateSessionResponseInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaCreateSessionResponseInitialize, (fl), 0, 0)
	#define CAL_OpcUaCreateSessionResponseInitialize  pfOpcUaCreateSessionResponseInitialize
	#define CHK_OpcUaCreateSessionResponseInitialize  (pfOpcUaCreateSessionResponseInitialize != NULL)
	#define EXP_OpcUaCreateSessionResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCreateSessionResponseInitialize", (RTS_UINTPTR)OpcUaCreateSessionResponseInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaCreateSessionResponseClear(OpcUa_CreateSessionResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUACREATESESSIONRESPONSECLEAR) (OpcUa_CreateSessionResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACREATESESSIONRESPONSECLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaCreateSessionResponseClear
	#define EXT_OpcUaCreateSessionResponseClear
	#define GET_OpcUaCreateSessionResponseClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaCreateSessionResponseClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaCreateSessionResponseClear  FALSE
	#define EXP_OpcUaCreateSessionResponseClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaCreateSessionResponseClear
	#define EXT_OpcUaCreateSessionResponseClear
	#define GET_OpcUaCreateSessionResponseClear(fl)  CAL_CMGETAPI( "OpcUaCreateSessionResponseClear" ) 
	#define CAL_OpcUaCreateSessionResponseClear  OpcUaCreateSessionResponseClear
	#define CHK_OpcUaCreateSessionResponseClear  TRUE
	#define EXP_OpcUaCreateSessionResponseClear  CAL_CMEXPAPI( "OpcUaCreateSessionResponseClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaCreateSessionResponseClear
	#define EXT_OpcUaCreateSessionResponseClear
	#define GET_OpcUaCreateSessionResponseClear(fl)  CAL_CMGETAPI( "OpcUaCreateSessionResponseClear" ) 
	#define CAL_OpcUaCreateSessionResponseClear  OpcUaCreateSessionResponseClear
	#define CHK_OpcUaCreateSessionResponseClear  TRUE
	#define EXP_OpcUaCreateSessionResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCreateSessionResponseClear", (RTS_UINTPTR)OpcUaCreateSessionResponseClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaCreateSessionResponseClear
	#define EXT_CmpOPCUAStackOpcUaCreateSessionResponseClear
	#define GET_CmpOPCUAStackOpcUaCreateSessionResponseClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaCreateSessionResponseClear pICmpOPCUAStack->IOpcUaCreateSessionResponseClear
	#define CHK_CmpOPCUAStackOpcUaCreateSessionResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaCreateSessionResponseClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaCreateSessionResponseClear
	#define EXT_OpcUaCreateSessionResponseClear
	#define GET_OpcUaCreateSessionResponseClear(fl)  CAL_CMGETAPI( "OpcUaCreateSessionResponseClear" ) 
	#define CAL_OpcUaCreateSessionResponseClear pICmpOPCUAStack->IOpcUaCreateSessionResponseClear
	#define CHK_OpcUaCreateSessionResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaCreateSessionResponseClear  CAL_CMEXPAPI( "OpcUaCreateSessionResponseClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaCreateSessionResponseClear  PFOPCUACREATESESSIONRESPONSECLEAR pfOpcUaCreateSessionResponseClear;
	#define EXT_OpcUaCreateSessionResponseClear  extern PFOPCUACREATESESSIONRESPONSECLEAR pfOpcUaCreateSessionResponseClear;
	#define GET_OpcUaCreateSessionResponseClear(fl)  s_pfCMGetAPI2( "OpcUaCreateSessionResponseClear", (RTS_VOID_FCTPTR *)&pfOpcUaCreateSessionResponseClear, (fl), 0, 0)
	#define CAL_OpcUaCreateSessionResponseClear  pfOpcUaCreateSessionResponseClear
	#define CHK_OpcUaCreateSessionResponseClear  (pfOpcUaCreateSessionResponseClear != NULL)
	#define EXP_OpcUaCreateSessionResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCreateSessionResponseClear", (RTS_UINTPTR)OpcUaCreateSessionResponseClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaActivateSessionRequestInitialize(OpcUa_ActivateSessionRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAACTIVATESESSIONREQUESTINITIALIZE) (OpcUa_ActivateSessionRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAACTIVATESESSIONREQUESTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaActivateSessionRequestInitialize
	#define EXT_OpcUaActivateSessionRequestInitialize
	#define GET_OpcUaActivateSessionRequestInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaActivateSessionRequestInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaActivateSessionRequestInitialize  FALSE
	#define EXP_OpcUaActivateSessionRequestInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaActivateSessionRequestInitialize
	#define EXT_OpcUaActivateSessionRequestInitialize
	#define GET_OpcUaActivateSessionRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaActivateSessionRequestInitialize" ) 
	#define CAL_OpcUaActivateSessionRequestInitialize  OpcUaActivateSessionRequestInitialize
	#define CHK_OpcUaActivateSessionRequestInitialize  TRUE
	#define EXP_OpcUaActivateSessionRequestInitialize  CAL_CMEXPAPI( "OpcUaActivateSessionRequestInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaActivateSessionRequestInitialize
	#define EXT_OpcUaActivateSessionRequestInitialize
	#define GET_OpcUaActivateSessionRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaActivateSessionRequestInitialize" ) 
	#define CAL_OpcUaActivateSessionRequestInitialize  OpcUaActivateSessionRequestInitialize
	#define CHK_OpcUaActivateSessionRequestInitialize  TRUE
	#define EXP_OpcUaActivateSessionRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaActivateSessionRequestInitialize", (RTS_UINTPTR)OpcUaActivateSessionRequestInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaActivateSessionRequestInitialize
	#define EXT_CmpOPCUAStackOpcUaActivateSessionRequestInitialize
	#define GET_CmpOPCUAStackOpcUaActivateSessionRequestInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaActivateSessionRequestInitialize pICmpOPCUAStack->IOpcUaActivateSessionRequestInitialize
	#define CHK_CmpOPCUAStackOpcUaActivateSessionRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaActivateSessionRequestInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaActivateSessionRequestInitialize
	#define EXT_OpcUaActivateSessionRequestInitialize
	#define GET_OpcUaActivateSessionRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaActivateSessionRequestInitialize" ) 
	#define CAL_OpcUaActivateSessionRequestInitialize pICmpOPCUAStack->IOpcUaActivateSessionRequestInitialize
	#define CHK_OpcUaActivateSessionRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaActivateSessionRequestInitialize  CAL_CMEXPAPI( "OpcUaActivateSessionRequestInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaActivateSessionRequestInitialize  PFOPCUAACTIVATESESSIONREQUESTINITIALIZE pfOpcUaActivateSessionRequestInitialize;
	#define EXT_OpcUaActivateSessionRequestInitialize  extern PFOPCUAACTIVATESESSIONREQUESTINITIALIZE pfOpcUaActivateSessionRequestInitialize;
	#define GET_OpcUaActivateSessionRequestInitialize(fl)  s_pfCMGetAPI2( "OpcUaActivateSessionRequestInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaActivateSessionRequestInitialize, (fl), 0, 0)
	#define CAL_OpcUaActivateSessionRequestInitialize  pfOpcUaActivateSessionRequestInitialize
	#define CHK_OpcUaActivateSessionRequestInitialize  (pfOpcUaActivateSessionRequestInitialize != NULL)
	#define EXP_OpcUaActivateSessionRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaActivateSessionRequestInitialize", (RTS_UINTPTR)OpcUaActivateSessionRequestInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaActivateSessionRequestClear(OpcUa_ActivateSessionRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAACTIVATESESSIONREQUESTCLEAR) (OpcUa_ActivateSessionRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAACTIVATESESSIONREQUESTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaActivateSessionRequestClear
	#define EXT_OpcUaActivateSessionRequestClear
	#define GET_OpcUaActivateSessionRequestClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaActivateSessionRequestClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaActivateSessionRequestClear  FALSE
	#define EXP_OpcUaActivateSessionRequestClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaActivateSessionRequestClear
	#define EXT_OpcUaActivateSessionRequestClear
	#define GET_OpcUaActivateSessionRequestClear(fl)  CAL_CMGETAPI( "OpcUaActivateSessionRequestClear" ) 
	#define CAL_OpcUaActivateSessionRequestClear  OpcUaActivateSessionRequestClear
	#define CHK_OpcUaActivateSessionRequestClear  TRUE
	#define EXP_OpcUaActivateSessionRequestClear  CAL_CMEXPAPI( "OpcUaActivateSessionRequestClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaActivateSessionRequestClear
	#define EXT_OpcUaActivateSessionRequestClear
	#define GET_OpcUaActivateSessionRequestClear(fl)  CAL_CMGETAPI( "OpcUaActivateSessionRequestClear" ) 
	#define CAL_OpcUaActivateSessionRequestClear  OpcUaActivateSessionRequestClear
	#define CHK_OpcUaActivateSessionRequestClear  TRUE
	#define EXP_OpcUaActivateSessionRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaActivateSessionRequestClear", (RTS_UINTPTR)OpcUaActivateSessionRequestClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaActivateSessionRequestClear
	#define EXT_CmpOPCUAStackOpcUaActivateSessionRequestClear
	#define GET_CmpOPCUAStackOpcUaActivateSessionRequestClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaActivateSessionRequestClear pICmpOPCUAStack->IOpcUaActivateSessionRequestClear
	#define CHK_CmpOPCUAStackOpcUaActivateSessionRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaActivateSessionRequestClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaActivateSessionRequestClear
	#define EXT_OpcUaActivateSessionRequestClear
	#define GET_OpcUaActivateSessionRequestClear(fl)  CAL_CMGETAPI( "OpcUaActivateSessionRequestClear" ) 
	#define CAL_OpcUaActivateSessionRequestClear pICmpOPCUAStack->IOpcUaActivateSessionRequestClear
	#define CHK_OpcUaActivateSessionRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaActivateSessionRequestClear  CAL_CMEXPAPI( "OpcUaActivateSessionRequestClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaActivateSessionRequestClear  PFOPCUAACTIVATESESSIONREQUESTCLEAR pfOpcUaActivateSessionRequestClear;
	#define EXT_OpcUaActivateSessionRequestClear  extern PFOPCUAACTIVATESESSIONREQUESTCLEAR pfOpcUaActivateSessionRequestClear;
	#define GET_OpcUaActivateSessionRequestClear(fl)  s_pfCMGetAPI2( "OpcUaActivateSessionRequestClear", (RTS_VOID_FCTPTR *)&pfOpcUaActivateSessionRequestClear, (fl), 0, 0)
	#define CAL_OpcUaActivateSessionRequestClear  pfOpcUaActivateSessionRequestClear
	#define CHK_OpcUaActivateSessionRequestClear  (pfOpcUaActivateSessionRequestClear != NULL)
	#define EXP_OpcUaActivateSessionRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaActivateSessionRequestClear", (RTS_UINTPTR)OpcUaActivateSessionRequestClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaActivateSessionResponseInitialize(OpcUa_ActivateSessionResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAACTIVATESESSIONRESPONSEINITIALIZE) (OpcUa_ActivateSessionResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAACTIVATESESSIONRESPONSEINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaActivateSessionResponseInitialize
	#define EXT_OpcUaActivateSessionResponseInitialize
	#define GET_OpcUaActivateSessionResponseInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaActivateSessionResponseInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaActivateSessionResponseInitialize  FALSE
	#define EXP_OpcUaActivateSessionResponseInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaActivateSessionResponseInitialize
	#define EXT_OpcUaActivateSessionResponseInitialize
	#define GET_OpcUaActivateSessionResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaActivateSessionResponseInitialize" ) 
	#define CAL_OpcUaActivateSessionResponseInitialize  OpcUaActivateSessionResponseInitialize
	#define CHK_OpcUaActivateSessionResponseInitialize  TRUE
	#define EXP_OpcUaActivateSessionResponseInitialize  CAL_CMEXPAPI( "OpcUaActivateSessionResponseInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaActivateSessionResponseInitialize
	#define EXT_OpcUaActivateSessionResponseInitialize
	#define GET_OpcUaActivateSessionResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaActivateSessionResponseInitialize" ) 
	#define CAL_OpcUaActivateSessionResponseInitialize  OpcUaActivateSessionResponseInitialize
	#define CHK_OpcUaActivateSessionResponseInitialize  TRUE
	#define EXP_OpcUaActivateSessionResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaActivateSessionResponseInitialize", (RTS_UINTPTR)OpcUaActivateSessionResponseInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaActivateSessionResponseInitialize
	#define EXT_CmpOPCUAStackOpcUaActivateSessionResponseInitialize
	#define GET_CmpOPCUAStackOpcUaActivateSessionResponseInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaActivateSessionResponseInitialize pICmpOPCUAStack->IOpcUaActivateSessionResponseInitialize
	#define CHK_CmpOPCUAStackOpcUaActivateSessionResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaActivateSessionResponseInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaActivateSessionResponseInitialize
	#define EXT_OpcUaActivateSessionResponseInitialize
	#define GET_OpcUaActivateSessionResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaActivateSessionResponseInitialize" ) 
	#define CAL_OpcUaActivateSessionResponseInitialize pICmpOPCUAStack->IOpcUaActivateSessionResponseInitialize
	#define CHK_OpcUaActivateSessionResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaActivateSessionResponseInitialize  CAL_CMEXPAPI( "OpcUaActivateSessionResponseInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaActivateSessionResponseInitialize  PFOPCUAACTIVATESESSIONRESPONSEINITIALIZE pfOpcUaActivateSessionResponseInitialize;
	#define EXT_OpcUaActivateSessionResponseInitialize  extern PFOPCUAACTIVATESESSIONRESPONSEINITIALIZE pfOpcUaActivateSessionResponseInitialize;
	#define GET_OpcUaActivateSessionResponseInitialize(fl)  s_pfCMGetAPI2( "OpcUaActivateSessionResponseInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaActivateSessionResponseInitialize, (fl), 0, 0)
	#define CAL_OpcUaActivateSessionResponseInitialize  pfOpcUaActivateSessionResponseInitialize
	#define CHK_OpcUaActivateSessionResponseInitialize  (pfOpcUaActivateSessionResponseInitialize != NULL)
	#define EXP_OpcUaActivateSessionResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaActivateSessionResponseInitialize", (RTS_UINTPTR)OpcUaActivateSessionResponseInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaActivateSessionResponseClear(OpcUa_ActivateSessionResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAACTIVATESESSIONRESPONSECLEAR) (OpcUa_ActivateSessionResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAACTIVATESESSIONRESPONSECLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaActivateSessionResponseClear
	#define EXT_OpcUaActivateSessionResponseClear
	#define GET_OpcUaActivateSessionResponseClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaActivateSessionResponseClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaActivateSessionResponseClear  FALSE
	#define EXP_OpcUaActivateSessionResponseClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaActivateSessionResponseClear
	#define EXT_OpcUaActivateSessionResponseClear
	#define GET_OpcUaActivateSessionResponseClear(fl)  CAL_CMGETAPI( "OpcUaActivateSessionResponseClear" ) 
	#define CAL_OpcUaActivateSessionResponseClear  OpcUaActivateSessionResponseClear
	#define CHK_OpcUaActivateSessionResponseClear  TRUE
	#define EXP_OpcUaActivateSessionResponseClear  CAL_CMEXPAPI( "OpcUaActivateSessionResponseClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaActivateSessionResponseClear
	#define EXT_OpcUaActivateSessionResponseClear
	#define GET_OpcUaActivateSessionResponseClear(fl)  CAL_CMGETAPI( "OpcUaActivateSessionResponseClear" ) 
	#define CAL_OpcUaActivateSessionResponseClear  OpcUaActivateSessionResponseClear
	#define CHK_OpcUaActivateSessionResponseClear  TRUE
	#define EXP_OpcUaActivateSessionResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaActivateSessionResponseClear", (RTS_UINTPTR)OpcUaActivateSessionResponseClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaActivateSessionResponseClear
	#define EXT_CmpOPCUAStackOpcUaActivateSessionResponseClear
	#define GET_CmpOPCUAStackOpcUaActivateSessionResponseClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaActivateSessionResponseClear pICmpOPCUAStack->IOpcUaActivateSessionResponseClear
	#define CHK_CmpOPCUAStackOpcUaActivateSessionResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaActivateSessionResponseClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaActivateSessionResponseClear
	#define EXT_OpcUaActivateSessionResponseClear
	#define GET_OpcUaActivateSessionResponseClear(fl)  CAL_CMGETAPI( "OpcUaActivateSessionResponseClear" ) 
	#define CAL_OpcUaActivateSessionResponseClear pICmpOPCUAStack->IOpcUaActivateSessionResponseClear
	#define CHK_OpcUaActivateSessionResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaActivateSessionResponseClear  CAL_CMEXPAPI( "OpcUaActivateSessionResponseClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaActivateSessionResponseClear  PFOPCUAACTIVATESESSIONRESPONSECLEAR pfOpcUaActivateSessionResponseClear;
	#define EXT_OpcUaActivateSessionResponseClear  extern PFOPCUAACTIVATESESSIONRESPONSECLEAR pfOpcUaActivateSessionResponseClear;
	#define GET_OpcUaActivateSessionResponseClear(fl)  s_pfCMGetAPI2( "OpcUaActivateSessionResponseClear", (RTS_VOID_FCTPTR *)&pfOpcUaActivateSessionResponseClear, (fl), 0, 0)
	#define CAL_OpcUaActivateSessionResponseClear  pfOpcUaActivateSessionResponseClear
	#define CHK_OpcUaActivateSessionResponseClear  (pfOpcUaActivateSessionResponseClear != NULL)
	#define EXP_OpcUaActivateSessionResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaActivateSessionResponseClear", (RTS_UINTPTR)OpcUaActivateSessionResponseClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaCloseSessionRequestInitialize(OpcUa_CloseSessionRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUACLOSESESSIONREQUESTINITIALIZE) (OpcUa_CloseSessionRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACLOSESESSIONREQUESTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaCloseSessionRequestInitialize
	#define EXT_OpcUaCloseSessionRequestInitialize
	#define GET_OpcUaCloseSessionRequestInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaCloseSessionRequestInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaCloseSessionRequestInitialize  FALSE
	#define EXP_OpcUaCloseSessionRequestInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaCloseSessionRequestInitialize
	#define EXT_OpcUaCloseSessionRequestInitialize
	#define GET_OpcUaCloseSessionRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaCloseSessionRequestInitialize" ) 
	#define CAL_OpcUaCloseSessionRequestInitialize  OpcUaCloseSessionRequestInitialize
	#define CHK_OpcUaCloseSessionRequestInitialize  TRUE
	#define EXP_OpcUaCloseSessionRequestInitialize  CAL_CMEXPAPI( "OpcUaCloseSessionRequestInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaCloseSessionRequestInitialize
	#define EXT_OpcUaCloseSessionRequestInitialize
	#define GET_OpcUaCloseSessionRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaCloseSessionRequestInitialize" ) 
	#define CAL_OpcUaCloseSessionRequestInitialize  OpcUaCloseSessionRequestInitialize
	#define CHK_OpcUaCloseSessionRequestInitialize  TRUE
	#define EXP_OpcUaCloseSessionRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCloseSessionRequestInitialize", (RTS_UINTPTR)OpcUaCloseSessionRequestInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaCloseSessionRequestInitialize
	#define EXT_CmpOPCUAStackOpcUaCloseSessionRequestInitialize
	#define GET_CmpOPCUAStackOpcUaCloseSessionRequestInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaCloseSessionRequestInitialize pICmpOPCUAStack->IOpcUaCloseSessionRequestInitialize
	#define CHK_CmpOPCUAStackOpcUaCloseSessionRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaCloseSessionRequestInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaCloseSessionRequestInitialize
	#define EXT_OpcUaCloseSessionRequestInitialize
	#define GET_OpcUaCloseSessionRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaCloseSessionRequestInitialize" ) 
	#define CAL_OpcUaCloseSessionRequestInitialize pICmpOPCUAStack->IOpcUaCloseSessionRequestInitialize
	#define CHK_OpcUaCloseSessionRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaCloseSessionRequestInitialize  CAL_CMEXPAPI( "OpcUaCloseSessionRequestInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaCloseSessionRequestInitialize  PFOPCUACLOSESESSIONREQUESTINITIALIZE pfOpcUaCloseSessionRequestInitialize;
	#define EXT_OpcUaCloseSessionRequestInitialize  extern PFOPCUACLOSESESSIONREQUESTINITIALIZE pfOpcUaCloseSessionRequestInitialize;
	#define GET_OpcUaCloseSessionRequestInitialize(fl)  s_pfCMGetAPI2( "OpcUaCloseSessionRequestInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaCloseSessionRequestInitialize, (fl), 0, 0)
	#define CAL_OpcUaCloseSessionRequestInitialize  pfOpcUaCloseSessionRequestInitialize
	#define CHK_OpcUaCloseSessionRequestInitialize  (pfOpcUaCloseSessionRequestInitialize != NULL)
	#define EXP_OpcUaCloseSessionRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCloseSessionRequestInitialize", (RTS_UINTPTR)OpcUaCloseSessionRequestInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaCloseSessionRequestClear(OpcUa_CloseSessionRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUACLOSESESSIONREQUESTCLEAR) (OpcUa_CloseSessionRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACLOSESESSIONREQUESTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaCloseSessionRequestClear
	#define EXT_OpcUaCloseSessionRequestClear
	#define GET_OpcUaCloseSessionRequestClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaCloseSessionRequestClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaCloseSessionRequestClear  FALSE
	#define EXP_OpcUaCloseSessionRequestClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaCloseSessionRequestClear
	#define EXT_OpcUaCloseSessionRequestClear
	#define GET_OpcUaCloseSessionRequestClear(fl)  CAL_CMGETAPI( "OpcUaCloseSessionRequestClear" ) 
	#define CAL_OpcUaCloseSessionRequestClear  OpcUaCloseSessionRequestClear
	#define CHK_OpcUaCloseSessionRequestClear  TRUE
	#define EXP_OpcUaCloseSessionRequestClear  CAL_CMEXPAPI( "OpcUaCloseSessionRequestClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaCloseSessionRequestClear
	#define EXT_OpcUaCloseSessionRequestClear
	#define GET_OpcUaCloseSessionRequestClear(fl)  CAL_CMGETAPI( "OpcUaCloseSessionRequestClear" ) 
	#define CAL_OpcUaCloseSessionRequestClear  OpcUaCloseSessionRequestClear
	#define CHK_OpcUaCloseSessionRequestClear  TRUE
	#define EXP_OpcUaCloseSessionRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCloseSessionRequestClear", (RTS_UINTPTR)OpcUaCloseSessionRequestClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaCloseSessionRequestClear
	#define EXT_CmpOPCUAStackOpcUaCloseSessionRequestClear
	#define GET_CmpOPCUAStackOpcUaCloseSessionRequestClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaCloseSessionRequestClear pICmpOPCUAStack->IOpcUaCloseSessionRequestClear
	#define CHK_CmpOPCUAStackOpcUaCloseSessionRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaCloseSessionRequestClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaCloseSessionRequestClear
	#define EXT_OpcUaCloseSessionRequestClear
	#define GET_OpcUaCloseSessionRequestClear(fl)  CAL_CMGETAPI( "OpcUaCloseSessionRequestClear" ) 
	#define CAL_OpcUaCloseSessionRequestClear pICmpOPCUAStack->IOpcUaCloseSessionRequestClear
	#define CHK_OpcUaCloseSessionRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaCloseSessionRequestClear  CAL_CMEXPAPI( "OpcUaCloseSessionRequestClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaCloseSessionRequestClear  PFOPCUACLOSESESSIONREQUESTCLEAR pfOpcUaCloseSessionRequestClear;
	#define EXT_OpcUaCloseSessionRequestClear  extern PFOPCUACLOSESESSIONREQUESTCLEAR pfOpcUaCloseSessionRequestClear;
	#define GET_OpcUaCloseSessionRequestClear(fl)  s_pfCMGetAPI2( "OpcUaCloseSessionRequestClear", (RTS_VOID_FCTPTR *)&pfOpcUaCloseSessionRequestClear, (fl), 0, 0)
	#define CAL_OpcUaCloseSessionRequestClear  pfOpcUaCloseSessionRequestClear
	#define CHK_OpcUaCloseSessionRequestClear  (pfOpcUaCloseSessionRequestClear != NULL)
	#define EXP_OpcUaCloseSessionRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCloseSessionRequestClear", (RTS_UINTPTR)OpcUaCloseSessionRequestClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaCloseSessionResponseInitialize(OpcUa_CloseSessionResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUACLOSESESSIONRESPONSEINITIALIZE) (OpcUa_CloseSessionResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACLOSESESSIONRESPONSEINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaCloseSessionResponseInitialize
	#define EXT_OpcUaCloseSessionResponseInitialize
	#define GET_OpcUaCloseSessionResponseInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaCloseSessionResponseInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaCloseSessionResponseInitialize  FALSE
	#define EXP_OpcUaCloseSessionResponseInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaCloseSessionResponseInitialize
	#define EXT_OpcUaCloseSessionResponseInitialize
	#define GET_OpcUaCloseSessionResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaCloseSessionResponseInitialize" ) 
	#define CAL_OpcUaCloseSessionResponseInitialize  OpcUaCloseSessionResponseInitialize
	#define CHK_OpcUaCloseSessionResponseInitialize  TRUE
	#define EXP_OpcUaCloseSessionResponseInitialize  CAL_CMEXPAPI( "OpcUaCloseSessionResponseInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaCloseSessionResponseInitialize
	#define EXT_OpcUaCloseSessionResponseInitialize
	#define GET_OpcUaCloseSessionResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaCloseSessionResponseInitialize" ) 
	#define CAL_OpcUaCloseSessionResponseInitialize  OpcUaCloseSessionResponseInitialize
	#define CHK_OpcUaCloseSessionResponseInitialize  TRUE
	#define EXP_OpcUaCloseSessionResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCloseSessionResponseInitialize", (RTS_UINTPTR)OpcUaCloseSessionResponseInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaCloseSessionResponseInitialize
	#define EXT_CmpOPCUAStackOpcUaCloseSessionResponseInitialize
	#define GET_CmpOPCUAStackOpcUaCloseSessionResponseInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaCloseSessionResponseInitialize pICmpOPCUAStack->IOpcUaCloseSessionResponseInitialize
	#define CHK_CmpOPCUAStackOpcUaCloseSessionResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaCloseSessionResponseInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaCloseSessionResponseInitialize
	#define EXT_OpcUaCloseSessionResponseInitialize
	#define GET_OpcUaCloseSessionResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaCloseSessionResponseInitialize" ) 
	#define CAL_OpcUaCloseSessionResponseInitialize pICmpOPCUAStack->IOpcUaCloseSessionResponseInitialize
	#define CHK_OpcUaCloseSessionResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaCloseSessionResponseInitialize  CAL_CMEXPAPI( "OpcUaCloseSessionResponseInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaCloseSessionResponseInitialize  PFOPCUACLOSESESSIONRESPONSEINITIALIZE pfOpcUaCloseSessionResponseInitialize;
	#define EXT_OpcUaCloseSessionResponseInitialize  extern PFOPCUACLOSESESSIONRESPONSEINITIALIZE pfOpcUaCloseSessionResponseInitialize;
	#define GET_OpcUaCloseSessionResponseInitialize(fl)  s_pfCMGetAPI2( "OpcUaCloseSessionResponseInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaCloseSessionResponseInitialize, (fl), 0, 0)
	#define CAL_OpcUaCloseSessionResponseInitialize  pfOpcUaCloseSessionResponseInitialize
	#define CHK_OpcUaCloseSessionResponseInitialize  (pfOpcUaCloseSessionResponseInitialize != NULL)
	#define EXP_OpcUaCloseSessionResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCloseSessionResponseInitialize", (RTS_UINTPTR)OpcUaCloseSessionResponseInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaCloseSessionResponseClear(OpcUa_CloseSessionResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUACLOSESESSIONRESPONSECLEAR) (OpcUa_CloseSessionResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACLOSESESSIONRESPONSECLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaCloseSessionResponseClear
	#define EXT_OpcUaCloseSessionResponseClear
	#define GET_OpcUaCloseSessionResponseClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaCloseSessionResponseClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaCloseSessionResponseClear  FALSE
	#define EXP_OpcUaCloseSessionResponseClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaCloseSessionResponseClear
	#define EXT_OpcUaCloseSessionResponseClear
	#define GET_OpcUaCloseSessionResponseClear(fl)  CAL_CMGETAPI( "OpcUaCloseSessionResponseClear" ) 
	#define CAL_OpcUaCloseSessionResponseClear  OpcUaCloseSessionResponseClear
	#define CHK_OpcUaCloseSessionResponseClear  TRUE
	#define EXP_OpcUaCloseSessionResponseClear  CAL_CMEXPAPI( "OpcUaCloseSessionResponseClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaCloseSessionResponseClear
	#define EXT_OpcUaCloseSessionResponseClear
	#define GET_OpcUaCloseSessionResponseClear(fl)  CAL_CMGETAPI( "OpcUaCloseSessionResponseClear" ) 
	#define CAL_OpcUaCloseSessionResponseClear  OpcUaCloseSessionResponseClear
	#define CHK_OpcUaCloseSessionResponseClear  TRUE
	#define EXP_OpcUaCloseSessionResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCloseSessionResponseClear", (RTS_UINTPTR)OpcUaCloseSessionResponseClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaCloseSessionResponseClear
	#define EXT_CmpOPCUAStackOpcUaCloseSessionResponseClear
	#define GET_CmpOPCUAStackOpcUaCloseSessionResponseClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaCloseSessionResponseClear pICmpOPCUAStack->IOpcUaCloseSessionResponseClear
	#define CHK_CmpOPCUAStackOpcUaCloseSessionResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaCloseSessionResponseClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaCloseSessionResponseClear
	#define EXT_OpcUaCloseSessionResponseClear
	#define GET_OpcUaCloseSessionResponseClear(fl)  CAL_CMGETAPI( "OpcUaCloseSessionResponseClear" ) 
	#define CAL_OpcUaCloseSessionResponseClear pICmpOPCUAStack->IOpcUaCloseSessionResponseClear
	#define CHK_OpcUaCloseSessionResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaCloseSessionResponseClear  CAL_CMEXPAPI( "OpcUaCloseSessionResponseClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaCloseSessionResponseClear  PFOPCUACLOSESESSIONRESPONSECLEAR pfOpcUaCloseSessionResponseClear;
	#define EXT_OpcUaCloseSessionResponseClear  extern PFOPCUACLOSESESSIONRESPONSECLEAR pfOpcUaCloseSessionResponseClear;
	#define GET_OpcUaCloseSessionResponseClear(fl)  s_pfCMGetAPI2( "OpcUaCloseSessionResponseClear", (RTS_VOID_FCTPTR *)&pfOpcUaCloseSessionResponseClear, (fl), 0, 0)
	#define CAL_OpcUaCloseSessionResponseClear  pfOpcUaCloseSessionResponseClear
	#define CHK_OpcUaCloseSessionResponseClear  (pfOpcUaCloseSessionResponseClear != NULL)
	#define EXP_OpcUaCloseSessionResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCloseSessionResponseClear", (RTS_UINTPTR)OpcUaCloseSessionResponseClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaReadRequestInitialize(OpcUa_ReadRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAREADREQUESTINITIALIZE) (OpcUa_ReadRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAREADREQUESTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaReadRequestInitialize
	#define EXT_OpcUaReadRequestInitialize
	#define GET_OpcUaReadRequestInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaReadRequestInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaReadRequestInitialize  FALSE
	#define EXP_OpcUaReadRequestInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaReadRequestInitialize
	#define EXT_OpcUaReadRequestInitialize
	#define GET_OpcUaReadRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaReadRequestInitialize" ) 
	#define CAL_OpcUaReadRequestInitialize  OpcUaReadRequestInitialize
	#define CHK_OpcUaReadRequestInitialize  TRUE
	#define EXP_OpcUaReadRequestInitialize  CAL_CMEXPAPI( "OpcUaReadRequestInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaReadRequestInitialize
	#define EXT_OpcUaReadRequestInitialize
	#define GET_OpcUaReadRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaReadRequestInitialize" ) 
	#define CAL_OpcUaReadRequestInitialize  OpcUaReadRequestInitialize
	#define CHK_OpcUaReadRequestInitialize  TRUE
	#define EXP_OpcUaReadRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaReadRequestInitialize", (RTS_UINTPTR)OpcUaReadRequestInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaReadRequestInitialize
	#define EXT_CmpOPCUAStackOpcUaReadRequestInitialize
	#define GET_CmpOPCUAStackOpcUaReadRequestInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaReadRequestInitialize pICmpOPCUAStack->IOpcUaReadRequestInitialize
	#define CHK_CmpOPCUAStackOpcUaReadRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaReadRequestInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaReadRequestInitialize
	#define EXT_OpcUaReadRequestInitialize
	#define GET_OpcUaReadRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaReadRequestInitialize" ) 
	#define CAL_OpcUaReadRequestInitialize pICmpOPCUAStack->IOpcUaReadRequestInitialize
	#define CHK_OpcUaReadRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaReadRequestInitialize  CAL_CMEXPAPI( "OpcUaReadRequestInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaReadRequestInitialize  PFOPCUAREADREQUESTINITIALIZE pfOpcUaReadRequestInitialize;
	#define EXT_OpcUaReadRequestInitialize  extern PFOPCUAREADREQUESTINITIALIZE pfOpcUaReadRequestInitialize;
	#define GET_OpcUaReadRequestInitialize(fl)  s_pfCMGetAPI2( "OpcUaReadRequestInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaReadRequestInitialize, (fl), 0, 0)
	#define CAL_OpcUaReadRequestInitialize  pfOpcUaReadRequestInitialize
	#define CHK_OpcUaReadRequestInitialize  (pfOpcUaReadRequestInitialize != NULL)
	#define EXP_OpcUaReadRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaReadRequestInitialize", (RTS_UINTPTR)OpcUaReadRequestInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaReadRequestClear(OpcUa_ReadRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAREADREQUESTCLEAR) (OpcUa_ReadRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAREADREQUESTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaReadRequestClear
	#define EXT_OpcUaReadRequestClear
	#define GET_OpcUaReadRequestClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaReadRequestClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaReadRequestClear  FALSE
	#define EXP_OpcUaReadRequestClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaReadRequestClear
	#define EXT_OpcUaReadRequestClear
	#define GET_OpcUaReadRequestClear(fl)  CAL_CMGETAPI( "OpcUaReadRequestClear" ) 
	#define CAL_OpcUaReadRequestClear  OpcUaReadRequestClear
	#define CHK_OpcUaReadRequestClear  TRUE
	#define EXP_OpcUaReadRequestClear  CAL_CMEXPAPI( "OpcUaReadRequestClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaReadRequestClear
	#define EXT_OpcUaReadRequestClear
	#define GET_OpcUaReadRequestClear(fl)  CAL_CMGETAPI( "OpcUaReadRequestClear" ) 
	#define CAL_OpcUaReadRequestClear  OpcUaReadRequestClear
	#define CHK_OpcUaReadRequestClear  TRUE
	#define EXP_OpcUaReadRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaReadRequestClear", (RTS_UINTPTR)OpcUaReadRequestClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaReadRequestClear
	#define EXT_CmpOPCUAStackOpcUaReadRequestClear
	#define GET_CmpOPCUAStackOpcUaReadRequestClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaReadRequestClear pICmpOPCUAStack->IOpcUaReadRequestClear
	#define CHK_CmpOPCUAStackOpcUaReadRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaReadRequestClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaReadRequestClear
	#define EXT_OpcUaReadRequestClear
	#define GET_OpcUaReadRequestClear(fl)  CAL_CMGETAPI( "OpcUaReadRequestClear" ) 
	#define CAL_OpcUaReadRequestClear pICmpOPCUAStack->IOpcUaReadRequestClear
	#define CHK_OpcUaReadRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaReadRequestClear  CAL_CMEXPAPI( "OpcUaReadRequestClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaReadRequestClear  PFOPCUAREADREQUESTCLEAR pfOpcUaReadRequestClear;
	#define EXT_OpcUaReadRequestClear  extern PFOPCUAREADREQUESTCLEAR pfOpcUaReadRequestClear;
	#define GET_OpcUaReadRequestClear(fl)  s_pfCMGetAPI2( "OpcUaReadRequestClear", (RTS_VOID_FCTPTR *)&pfOpcUaReadRequestClear, (fl), 0, 0)
	#define CAL_OpcUaReadRequestClear  pfOpcUaReadRequestClear
	#define CHK_OpcUaReadRequestClear  (pfOpcUaReadRequestClear != NULL)
	#define EXP_OpcUaReadRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaReadRequestClear", (RTS_UINTPTR)OpcUaReadRequestClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaReadResponseInitialize(OpcUa_ReadResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAREADRESPONSEINITIALIZE) (OpcUa_ReadResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAREADRESPONSEINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaReadResponseInitialize
	#define EXT_OpcUaReadResponseInitialize
	#define GET_OpcUaReadResponseInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaReadResponseInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaReadResponseInitialize  FALSE
	#define EXP_OpcUaReadResponseInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaReadResponseInitialize
	#define EXT_OpcUaReadResponseInitialize
	#define GET_OpcUaReadResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaReadResponseInitialize" ) 
	#define CAL_OpcUaReadResponseInitialize  OpcUaReadResponseInitialize
	#define CHK_OpcUaReadResponseInitialize  TRUE
	#define EXP_OpcUaReadResponseInitialize  CAL_CMEXPAPI( "OpcUaReadResponseInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaReadResponseInitialize
	#define EXT_OpcUaReadResponseInitialize
	#define GET_OpcUaReadResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaReadResponseInitialize" ) 
	#define CAL_OpcUaReadResponseInitialize  OpcUaReadResponseInitialize
	#define CHK_OpcUaReadResponseInitialize  TRUE
	#define EXP_OpcUaReadResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaReadResponseInitialize", (RTS_UINTPTR)OpcUaReadResponseInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaReadResponseInitialize
	#define EXT_CmpOPCUAStackOpcUaReadResponseInitialize
	#define GET_CmpOPCUAStackOpcUaReadResponseInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaReadResponseInitialize pICmpOPCUAStack->IOpcUaReadResponseInitialize
	#define CHK_CmpOPCUAStackOpcUaReadResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaReadResponseInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaReadResponseInitialize
	#define EXT_OpcUaReadResponseInitialize
	#define GET_OpcUaReadResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaReadResponseInitialize" ) 
	#define CAL_OpcUaReadResponseInitialize pICmpOPCUAStack->IOpcUaReadResponseInitialize
	#define CHK_OpcUaReadResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaReadResponseInitialize  CAL_CMEXPAPI( "OpcUaReadResponseInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaReadResponseInitialize  PFOPCUAREADRESPONSEINITIALIZE pfOpcUaReadResponseInitialize;
	#define EXT_OpcUaReadResponseInitialize  extern PFOPCUAREADRESPONSEINITIALIZE pfOpcUaReadResponseInitialize;
	#define GET_OpcUaReadResponseInitialize(fl)  s_pfCMGetAPI2( "OpcUaReadResponseInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaReadResponseInitialize, (fl), 0, 0)
	#define CAL_OpcUaReadResponseInitialize  pfOpcUaReadResponseInitialize
	#define CHK_OpcUaReadResponseInitialize  (pfOpcUaReadResponseInitialize != NULL)
	#define EXP_OpcUaReadResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaReadResponseInitialize", (RTS_UINTPTR)OpcUaReadResponseInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaReadResponseClear(OpcUa_ReadResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAREADRESPONSECLEAR) (OpcUa_ReadResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAREADRESPONSECLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaReadResponseClear
	#define EXT_OpcUaReadResponseClear
	#define GET_OpcUaReadResponseClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaReadResponseClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaReadResponseClear  FALSE
	#define EXP_OpcUaReadResponseClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaReadResponseClear
	#define EXT_OpcUaReadResponseClear
	#define GET_OpcUaReadResponseClear(fl)  CAL_CMGETAPI( "OpcUaReadResponseClear" ) 
	#define CAL_OpcUaReadResponseClear  OpcUaReadResponseClear
	#define CHK_OpcUaReadResponseClear  TRUE
	#define EXP_OpcUaReadResponseClear  CAL_CMEXPAPI( "OpcUaReadResponseClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaReadResponseClear
	#define EXT_OpcUaReadResponseClear
	#define GET_OpcUaReadResponseClear(fl)  CAL_CMGETAPI( "OpcUaReadResponseClear" ) 
	#define CAL_OpcUaReadResponseClear  OpcUaReadResponseClear
	#define CHK_OpcUaReadResponseClear  TRUE
	#define EXP_OpcUaReadResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaReadResponseClear", (RTS_UINTPTR)OpcUaReadResponseClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaReadResponseClear
	#define EXT_CmpOPCUAStackOpcUaReadResponseClear
	#define GET_CmpOPCUAStackOpcUaReadResponseClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaReadResponseClear pICmpOPCUAStack->IOpcUaReadResponseClear
	#define CHK_CmpOPCUAStackOpcUaReadResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaReadResponseClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaReadResponseClear
	#define EXT_OpcUaReadResponseClear
	#define GET_OpcUaReadResponseClear(fl)  CAL_CMGETAPI( "OpcUaReadResponseClear" ) 
	#define CAL_OpcUaReadResponseClear pICmpOPCUAStack->IOpcUaReadResponseClear
	#define CHK_OpcUaReadResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaReadResponseClear  CAL_CMEXPAPI( "OpcUaReadResponseClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaReadResponseClear  PFOPCUAREADRESPONSECLEAR pfOpcUaReadResponseClear;
	#define EXT_OpcUaReadResponseClear  extern PFOPCUAREADRESPONSECLEAR pfOpcUaReadResponseClear;
	#define GET_OpcUaReadResponseClear(fl)  s_pfCMGetAPI2( "OpcUaReadResponseClear", (RTS_VOID_FCTPTR *)&pfOpcUaReadResponseClear, (fl), 0, 0)
	#define CAL_OpcUaReadResponseClear  pfOpcUaReadResponseClear
	#define CHK_OpcUaReadResponseClear  (pfOpcUaReadResponseClear != NULL)
	#define EXP_OpcUaReadResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaReadResponseClear", (RTS_UINTPTR)OpcUaReadResponseClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaWriteRequestInitialize(OpcUa_WriteRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAWRITEREQUESTINITIALIZE) (OpcUa_WriteRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAWRITEREQUESTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaWriteRequestInitialize
	#define EXT_OpcUaWriteRequestInitialize
	#define GET_OpcUaWriteRequestInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaWriteRequestInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaWriteRequestInitialize  FALSE
	#define EXP_OpcUaWriteRequestInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaWriteRequestInitialize
	#define EXT_OpcUaWriteRequestInitialize
	#define GET_OpcUaWriteRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaWriteRequestInitialize" ) 
	#define CAL_OpcUaWriteRequestInitialize  OpcUaWriteRequestInitialize
	#define CHK_OpcUaWriteRequestInitialize  TRUE
	#define EXP_OpcUaWriteRequestInitialize  CAL_CMEXPAPI( "OpcUaWriteRequestInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaWriteRequestInitialize
	#define EXT_OpcUaWriteRequestInitialize
	#define GET_OpcUaWriteRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaWriteRequestInitialize" ) 
	#define CAL_OpcUaWriteRequestInitialize  OpcUaWriteRequestInitialize
	#define CHK_OpcUaWriteRequestInitialize  TRUE
	#define EXP_OpcUaWriteRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaWriteRequestInitialize", (RTS_UINTPTR)OpcUaWriteRequestInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaWriteRequestInitialize
	#define EXT_CmpOPCUAStackOpcUaWriteRequestInitialize
	#define GET_CmpOPCUAStackOpcUaWriteRequestInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaWriteRequestInitialize pICmpOPCUAStack->IOpcUaWriteRequestInitialize
	#define CHK_CmpOPCUAStackOpcUaWriteRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaWriteRequestInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaWriteRequestInitialize
	#define EXT_OpcUaWriteRequestInitialize
	#define GET_OpcUaWriteRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaWriteRequestInitialize" ) 
	#define CAL_OpcUaWriteRequestInitialize pICmpOPCUAStack->IOpcUaWriteRequestInitialize
	#define CHK_OpcUaWriteRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaWriteRequestInitialize  CAL_CMEXPAPI( "OpcUaWriteRequestInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaWriteRequestInitialize  PFOPCUAWRITEREQUESTINITIALIZE pfOpcUaWriteRequestInitialize;
	#define EXT_OpcUaWriteRequestInitialize  extern PFOPCUAWRITEREQUESTINITIALIZE pfOpcUaWriteRequestInitialize;
	#define GET_OpcUaWriteRequestInitialize(fl)  s_pfCMGetAPI2( "OpcUaWriteRequestInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaWriteRequestInitialize, (fl), 0, 0)
	#define CAL_OpcUaWriteRequestInitialize  pfOpcUaWriteRequestInitialize
	#define CHK_OpcUaWriteRequestInitialize  (pfOpcUaWriteRequestInitialize != NULL)
	#define EXP_OpcUaWriteRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaWriteRequestInitialize", (RTS_UINTPTR)OpcUaWriteRequestInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaWriteRequestClear(OpcUa_WriteRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAWRITEREQUESTCLEAR) (OpcUa_WriteRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAWRITEREQUESTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaWriteRequestClear
	#define EXT_OpcUaWriteRequestClear
	#define GET_OpcUaWriteRequestClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaWriteRequestClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaWriteRequestClear  FALSE
	#define EXP_OpcUaWriteRequestClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaWriteRequestClear
	#define EXT_OpcUaWriteRequestClear
	#define GET_OpcUaWriteRequestClear(fl)  CAL_CMGETAPI( "OpcUaWriteRequestClear" ) 
	#define CAL_OpcUaWriteRequestClear  OpcUaWriteRequestClear
	#define CHK_OpcUaWriteRequestClear  TRUE
	#define EXP_OpcUaWriteRequestClear  CAL_CMEXPAPI( "OpcUaWriteRequestClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaWriteRequestClear
	#define EXT_OpcUaWriteRequestClear
	#define GET_OpcUaWriteRequestClear(fl)  CAL_CMGETAPI( "OpcUaWriteRequestClear" ) 
	#define CAL_OpcUaWriteRequestClear  OpcUaWriteRequestClear
	#define CHK_OpcUaWriteRequestClear  TRUE
	#define EXP_OpcUaWriteRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaWriteRequestClear", (RTS_UINTPTR)OpcUaWriteRequestClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaWriteRequestClear
	#define EXT_CmpOPCUAStackOpcUaWriteRequestClear
	#define GET_CmpOPCUAStackOpcUaWriteRequestClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaWriteRequestClear pICmpOPCUAStack->IOpcUaWriteRequestClear
	#define CHK_CmpOPCUAStackOpcUaWriteRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaWriteRequestClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaWriteRequestClear
	#define EXT_OpcUaWriteRequestClear
	#define GET_OpcUaWriteRequestClear(fl)  CAL_CMGETAPI( "OpcUaWriteRequestClear" ) 
	#define CAL_OpcUaWriteRequestClear pICmpOPCUAStack->IOpcUaWriteRequestClear
	#define CHK_OpcUaWriteRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaWriteRequestClear  CAL_CMEXPAPI( "OpcUaWriteRequestClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaWriteRequestClear  PFOPCUAWRITEREQUESTCLEAR pfOpcUaWriteRequestClear;
	#define EXT_OpcUaWriteRequestClear  extern PFOPCUAWRITEREQUESTCLEAR pfOpcUaWriteRequestClear;
	#define GET_OpcUaWriteRequestClear(fl)  s_pfCMGetAPI2( "OpcUaWriteRequestClear", (RTS_VOID_FCTPTR *)&pfOpcUaWriteRequestClear, (fl), 0, 0)
	#define CAL_OpcUaWriteRequestClear  pfOpcUaWriteRequestClear
	#define CHK_OpcUaWriteRequestClear  (pfOpcUaWriteRequestClear != NULL)
	#define EXP_OpcUaWriteRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaWriteRequestClear", (RTS_UINTPTR)OpcUaWriteRequestClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaWriteResponseInitialize(OpcUa_WriteResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAWRITERESPONSEINITIALIZE) (OpcUa_WriteResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAWRITERESPONSEINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaWriteResponseInitialize
	#define EXT_OpcUaWriteResponseInitialize
	#define GET_OpcUaWriteResponseInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaWriteResponseInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaWriteResponseInitialize  FALSE
	#define EXP_OpcUaWriteResponseInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaWriteResponseInitialize
	#define EXT_OpcUaWriteResponseInitialize
	#define GET_OpcUaWriteResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaWriteResponseInitialize" ) 
	#define CAL_OpcUaWriteResponseInitialize  OpcUaWriteResponseInitialize
	#define CHK_OpcUaWriteResponseInitialize  TRUE
	#define EXP_OpcUaWriteResponseInitialize  CAL_CMEXPAPI( "OpcUaWriteResponseInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaWriteResponseInitialize
	#define EXT_OpcUaWriteResponseInitialize
	#define GET_OpcUaWriteResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaWriteResponseInitialize" ) 
	#define CAL_OpcUaWriteResponseInitialize  OpcUaWriteResponseInitialize
	#define CHK_OpcUaWriteResponseInitialize  TRUE
	#define EXP_OpcUaWriteResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaWriteResponseInitialize", (RTS_UINTPTR)OpcUaWriteResponseInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaWriteResponseInitialize
	#define EXT_CmpOPCUAStackOpcUaWriteResponseInitialize
	#define GET_CmpOPCUAStackOpcUaWriteResponseInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaWriteResponseInitialize pICmpOPCUAStack->IOpcUaWriteResponseInitialize
	#define CHK_CmpOPCUAStackOpcUaWriteResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaWriteResponseInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaWriteResponseInitialize
	#define EXT_OpcUaWriteResponseInitialize
	#define GET_OpcUaWriteResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaWriteResponseInitialize" ) 
	#define CAL_OpcUaWriteResponseInitialize pICmpOPCUAStack->IOpcUaWriteResponseInitialize
	#define CHK_OpcUaWriteResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaWriteResponseInitialize  CAL_CMEXPAPI( "OpcUaWriteResponseInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaWriteResponseInitialize  PFOPCUAWRITERESPONSEINITIALIZE pfOpcUaWriteResponseInitialize;
	#define EXT_OpcUaWriteResponseInitialize  extern PFOPCUAWRITERESPONSEINITIALIZE pfOpcUaWriteResponseInitialize;
	#define GET_OpcUaWriteResponseInitialize(fl)  s_pfCMGetAPI2( "OpcUaWriteResponseInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaWriteResponseInitialize, (fl), 0, 0)
	#define CAL_OpcUaWriteResponseInitialize  pfOpcUaWriteResponseInitialize
	#define CHK_OpcUaWriteResponseInitialize  (pfOpcUaWriteResponseInitialize != NULL)
	#define EXP_OpcUaWriteResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaWriteResponseInitialize", (RTS_UINTPTR)OpcUaWriteResponseInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaWriteResponseClear(OpcUa_WriteResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAWRITERESPONSECLEAR) (OpcUa_WriteResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAWRITERESPONSECLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaWriteResponseClear
	#define EXT_OpcUaWriteResponseClear
	#define GET_OpcUaWriteResponseClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaWriteResponseClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaWriteResponseClear  FALSE
	#define EXP_OpcUaWriteResponseClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaWriteResponseClear
	#define EXT_OpcUaWriteResponseClear
	#define GET_OpcUaWriteResponseClear(fl)  CAL_CMGETAPI( "OpcUaWriteResponseClear" ) 
	#define CAL_OpcUaWriteResponseClear  OpcUaWriteResponseClear
	#define CHK_OpcUaWriteResponseClear  TRUE
	#define EXP_OpcUaWriteResponseClear  CAL_CMEXPAPI( "OpcUaWriteResponseClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaWriteResponseClear
	#define EXT_OpcUaWriteResponseClear
	#define GET_OpcUaWriteResponseClear(fl)  CAL_CMGETAPI( "OpcUaWriteResponseClear" ) 
	#define CAL_OpcUaWriteResponseClear  OpcUaWriteResponseClear
	#define CHK_OpcUaWriteResponseClear  TRUE
	#define EXP_OpcUaWriteResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaWriteResponseClear", (RTS_UINTPTR)OpcUaWriteResponseClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaWriteResponseClear
	#define EXT_CmpOPCUAStackOpcUaWriteResponseClear
	#define GET_CmpOPCUAStackOpcUaWriteResponseClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaWriteResponseClear pICmpOPCUAStack->IOpcUaWriteResponseClear
	#define CHK_CmpOPCUAStackOpcUaWriteResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaWriteResponseClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaWriteResponseClear
	#define EXT_OpcUaWriteResponseClear
	#define GET_OpcUaWriteResponseClear(fl)  CAL_CMGETAPI( "OpcUaWriteResponseClear" ) 
	#define CAL_OpcUaWriteResponseClear pICmpOPCUAStack->IOpcUaWriteResponseClear
	#define CHK_OpcUaWriteResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaWriteResponseClear  CAL_CMEXPAPI( "OpcUaWriteResponseClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaWriteResponseClear  PFOPCUAWRITERESPONSECLEAR pfOpcUaWriteResponseClear;
	#define EXT_OpcUaWriteResponseClear  extern PFOPCUAWRITERESPONSECLEAR pfOpcUaWriteResponseClear;
	#define GET_OpcUaWriteResponseClear(fl)  s_pfCMGetAPI2( "OpcUaWriteResponseClear", (RTS_VOID_FCTPTR *)&pfOpcUaWriteResponseClear, (fl), 0, 0)
	#define CAL_OpcUaWriteResponseClear  pfOpcUaWriteResponseClear
	#define CHK_OpcUaWriteResponseClear  (pfOpcUaWriteResponseClear != NULL)
	#define EXP_OpcUaWriteResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaWriteResponseClear", (RTS_UINTPTR)OpcUaWriteResponseClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaCreateSubscriptionRequestInitialize(OpcUa_CreateSubscriptionRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUACREATESUBSCRIPTIONREQUESTINITIALIZE) (OpcUa_CreateSubscriptionRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACREATESUBSCRIPTIONREQUESTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaCreateSubscriptionRequestInitialize
	#define EXT_OpcUaCreateSubscriptionRequestInitialize
	#define GET_OpcUaCreateSubscriptionRequestInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaCreateSubscriptionRequestInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaCreateSubscriptionRequestInitialize  FALSE
	#define EXP_OpcUaCreateSubscriptionRequestInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaCreateSubscriptionRequestInitialize
	#define EXT_OpcUaCreateSubscriptionRequestInitialize
	#define GET_OpcUaCreateSubscriptionRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaCreateSubscriptionRequestInitialize" ) 
	#define CAL_OpcUaCreateSubscriptionRequestInitialize  OpcUaCreateSubscriptionRequestInitialize
	#define CHK_OpcUaCreateSubscriptionRequestInitialize  TRUE
	#define EXP_OpcUaCreateSubscriptionRequestInitialize  CAL_CMEXPAPI( "OpcUaCreateSubscriptionRequestInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaCreateSubscriptionRequestInitialize
	#define EXT_OpcUaCreateSubscriptionRequestInitialize
	#define GET_OpcUaCreateSubscriptionRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaCreateSubscriptionRequestInitialize" ) 
	#define CAL_OpcUaCreateSubscriptionRequestInitialize  OpcUaCreateSubscriptionRequestInitialize
	#define CHK_OpcUaCreateSubscriptionRequestInitialize  TRUE
	#define EXP_OpcUaCreateSubscriptionRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCreateSubscriptionRequestInitialize", (RTS_UINTPTR)OpcUaCreateSubscriptionRequestInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaCreateSubscriptionRequestInitialize
	#define EXT_CmpOPCUAStackOpcUaCreateSubscriptionRequestInitialize
	#define GET_CmpOPCUAStackOpcUaCreateSubscriptionRequestInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaCreateSubscriptionRequestInitialize pICmpOPCUAStack->IOpcUaCreateSubscriptionRequestInitialize
	#define CHK_CmpOPCUAStackOpcUaCreateSubscriptionRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaCreateSubscriptionRequestInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaCreateSubscriptionRequestInitialize
	#define EXT_OpcUaCreateSubscriptionRequestInitialize
	#define GET_OpcUaCreateSubscriptionRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaCreateSubscriptionRequestInitialize" ) 
	#define CAL_OpcUaCreateSubscriptionRequestInitialize pICmpOPCUAStack->IOpcUaCreateSubscriptionRequestInitialize
	#define CHK_OpcUaCreateSubscriptionRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaCreateSubscriptionRequestInitialize  CAL_CMEXPAPI( "OpcUaCreateSubscriptionRequestInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaCreateSubscriptionRequestInitialize  PFOPCUACREATESUBSCRIPTIONREQUESTINITIALIZE pfOpcUaCreateSubscriptionRequestInitialize;
	#define EXT_OpcUaCreateSubscriptionRequestInitialize  extern PFOPCUACREATESUBSCRIPTIONREQUESTINITIALIZE pfOpcUaCreateSubscriptionRequestInitialize;
	#define GET_OpcUaCreateSubscriptionRequestInitialize(fl)  s_pfCMGetAPI2( "OpcUaCreateSubscriptionRequestInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaCreateSubscriptionRequestInitialize, (fl), 0, 0)
	#define CAL_OpcUaCreateSubscriptionRequestInitialize  pfOpcUaCreateSubscriptionRequestInitialize
	#define CHK_OpcUaCreateSubscriptionRequestInitialize  (pfOpcUaCreateSubscriptionRequestInitialize != NULL)
	#define EXP_OpcUaCreateSubscriptionRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCreateSubscriptionRequestInitialize", (RTS_UINTPTR)OpcUaCreateSubscriptionRequestInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaCreateSubscriptionRequestClear(OpcUa_CreateSubscriptionRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUACREATESUBSCRIPTIONREQUESTCLEAR) (OpcUa_CreateSubscriptionRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACREATESUBSCRIPTIONREQUESTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaCreateSubscriptionRequestClear
	#define EXT_OpcUaCreateSubscriptionRequestClear
	#define GET_OpcUaCreateSubscriptionRequestClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaCreateSubscriptionRequestClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaCreateSubscriptionRequestClear  FALSE
	#define EXP_OpcUaCreateSubscriptionRequestClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaCreateSubscriptionRequestClear
	#define EXT_OpcUaCreateSubscriptionRequestClear
	#define GET_OpcUaCreateSubscriptionRequestClear(fl)  CAL_CMGETAPI( "OpcUaCreateSubscriptionRequestClear" ) 
	#define CAL_OpcUaCreateSubscriptionRequestClear  OpcUaCreateSubscriptionRequestClear
	#define CHK_OpcUaCreateSubscriptionRequestClear  TRUE
	#define EXP_OpcUaCreateSubscriptionRequestClear  CAL_CMEXPAPI( "OpcUaCreateSubscriptionRequestClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaCreateSubscriptionRequestClear
	#define EXT_OpcUaCreateSubscriptionRequestClear
	#define GET_OpcUaCreateSubscriptionRequestClear(fl)  CAL_CMGETAPI( "OpcUaCreateSubscriptionRequestClear" ) 
	#define CAL_OpcUaCreateSubscriptionRequestClear  OpcUaCreateSubscriptionRequestClear
	#define CHK_OpcUaCreateSubscriptionRequestClear  TRUE
	#define EXP_OpcUaCreateSubscriptionRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCreateSubscriptionRequestClear", (RTS_UINTPTR)OpcUaCreateSubscriptionRequestClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaCreateSubscriptionRequestClear
	#define EXT_CmpOPCUAStackOpcUaCreateSubscriptionRequestClear
	#define GET_CmpOPCUAStackOpcUaCreateSubscriptionRequestClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaCreateSubscriptionRequestClear pICmpOPCUAStack->IOpcUaCreateSubscriptionRequestClear
	#define CHK_CmpOPCUAStackOpcUaCreateSubscriptionRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaCreateSubscriptionRequestClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaCreateSubscriptionRequestClear
	#define EXT_OpcUaCreateSubscriptionRequestClear
	#define GET_OpcUaCreateSubscriptionRequestClear(fl)  CAL_CMGETAPI( "OpcUaCreateSubscriptionRequestClear" ) 
	#define CAL_OpcUaCreateSubscriptionRequestClear pICmpOPCUAStack->IOpcUaCreateSubscriptionRequestClear
	#define CHK_OpcUaCreateSubscriptionRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaCreateSubscriptionRequestClear  CAL_CMEXPAPI( "OpcUaCreateSubscriptionRequestClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaCreateSubscriptionRequestClear  PFOPCUACREATESUBSCRIPTIONREQUESTCLEAR pfOpcUaCreateSubscriptionRequestClear;
	#define EXT_OpcUaCreateSubscriptionRequestClear  extern PFOPCUACREATESUBSCRIPTIONREQUESTCLEAR pfOpcUaCreateSubscriptionRequestClear;
	#define GET_OpcUaCreateSubscriptionRequestClear(fl)  s_pfCMGetAPI2( "OpcUaCreateSubscriptionRequestClear", (RTS_VOID_FCTPTR *)&pfOpcUaCreateSubscriptionRequestClear, (fl), 0, 0)
	#define CAL_OpcUaCreateSubscriptionRequestClear  pfOpcUaCreateSubscriptionRequestClear
	#define CHK_OpcUaCreateSubscriptionRequestClear  (pfOpcUaCreateSubscriptionRequestClear != NULL)
	#define EXP_OpcUaCreateSubscriptionRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCreateSubscriptionRequestClear", (RTS_UINTPTR)OpcUaCreateSubscriptionRequestClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaModifySubscriptionRequestInitialize(OpcUa_ModifySubscriptionRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAMODIFYSUBSCRIPTIONREQUESTINITIALIZE) (OpcUa_ModifySubscriptionRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAMODIFYSUBSCRIPTIONREQUESTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaModifySubscriptionRequestInitialize
	#define EXT_OpcUaModifySubscriptionRequestInitialize
	#define GET_OpcUaModifySubscriptionRequestInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaModifySubscriptionRequestInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaModifySubscriptionRequestInitialize  FALSE
	#define EXP_OpcUaModifySubscriptionRequestInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaModifySubscriptionRequestInitialize
	#define EXT_OpcUaModifySubscriptionRequestInitialize
	#define GET_OpcUaModifySubscriptionRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaModifySubscriptionRequestInitialize" ) 
	#define CAL_OpcUaModifySubscriptionRequestInitialize  OpcUaModifySubscriptionRequestInitialize
	#define CHK_OpcUaModifySubscriptionRequestInitialize  TRUE
	#define EXP_OpcUaModifySubscriptionRequestInitialize  CAL_CMEXPAPI( "OpcUaModifySubscriptionRequestInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaModifySubscriptionRequestInitialize
	#define EXT_OpcUaModifySubscriptionRequestInitialize
	#define GET_OpcUaModifySubscriptionRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaModifySubscriptionRequestInitialize" ) 
	#define CAL_OpcUaModifySubscriptionRequestInitialize  OpcUaModifySubscriptionRequestInitialize
	#define CHK_OpcUaModifySubscriptionRequestInitialize  TRUE
	#define EXP_OpcUaModifySubscriptionRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaModifySubscriptionRequestInitialize", (RTS_UINTPTR)OpcUaModifySubscriptionRequestInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaModifySubscriptionRequestInitialize
	#define EXT_CmpOPCUAStackOpcUaModifySubscriptionRequestInitialize
	#define GET_CmpOPCUAStackOpcUaModifySubscriptionRequestInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaModifySubscriptionRequestInitialize pICmpOPCUAStack->IOpcUaModifySubscriptionRequestInitialize
	#define CHK_CmpOPCUAStackOpcUaModifySubscriptionRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaModifySubscriptionRequestInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaModifySubscriptionRequestInitialize
	#define EXT_OpcUaModifySubscriptionRequestInitialize
	#define GET_OpcUaModifySubscriptionRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaModifySubscriptionRequestInitialize" ) 
	#define CAL_OpcUaModifySubscriptionRequestInitialize pICmpOPCUAStack->IOpcUaModifySubscriptionRequestInitialize
	#define CHK_OpcUaModifySubscriptionRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaModifySubscriptionRequestInitialize  CAL_CMEXPAPI( "OpcUaModifySubscriptionRequestInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaModifySubscriptionRequestInitialize  PFOPCUAMODIFYSUBSCRIPTIONREQUESTINITIALIZE pfOpcUaModifySubscriptionRequestInitialize;
	#define EXT_OpcUaModifySubscriptionRequestInitialize  extern PFOPCUAMODIFYSUBSCRIPTIONREQUESTINITIALIZE pfOpcUaModifySubscriptionRequestInitialize;
	#define GET_OpcUaModifySubscriptionRequestInitialize(fl)  s_pfCMGetAPI2( "OpcUaModifySubscriptionRequestInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaModifySubscriptionRequestInitialize, (fl), 0, 0)
	#define CAL_OpcUaModifySubscriptionRequestInitialize  pfOpcUaModifySubscriptionRequestInitialize
	#define CHK_OpcUaModifySubscriptionRequestInitialize  (pfOpcUaModifySubscriptionRequestInitialize != NULL)
	#define EXP_OpcUaModifySubscriptionRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaModifySubscriptionRequestInitialize", (RTS_UINTPTR)OpcUaModifySubscriptionRequestInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaModifySubscriptionRequestClear(OpcUa_ModifySubscriptionRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAMODIFYSUBSCRIPTIONREQUESTCLEAR) (OpcUa_ModifySubscriptionRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAMODIFYSUBSCRIPTIONREQUESTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaModifySubscriptionRequestClear
	#define EXT_OpcUaModifySubscriptionRequestClear
	#define GET_OpcUaModifySubscriptionRequestClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaModifySubscriptionRequestClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaModifySubscriptionRequestClear  FALSE
	#define EXP_OpcUaModifySubscriptionRequestClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaModifySubscriptionRequestClear
	#define EXT_OpcUaModifySubscriptionRequestClear
	#define GET_OpcUaModifySubscriptionRequestClear(fl)  CAL_CMGETAPI( "OpcUaModifySubscriptionRequestClear" ) 
	#define CAL_OpcUaModifySubscriptionRequestClear  OpcUaModifySubscriptionRequestClear
	#define CHK_OpcUaModifySubscriptionRequestClear  TRUE
	#define EXP_OpcUaModifySubscriptionRequestClear  CAL_CMEXPAPI( "OpcUaModifySubscriptionRequestClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaModifySubscriptionRequestClear
	#define EXT_OpcUaModifySubscriptionRequestClear
	#define GET_OpcUaModifySubscriptionRequestClear(fl)  CAL_CMGETAPI( "OpcUaModifySubscriptionRequestClear" ) 
	#define CAL_OpcUaModifySubscriptionRequestClear  OpcUaModifySubscriptionRequestClear
	#define CHK_OpcUaModifySubscriptionRequestClear  TRUE
	#define EXP_OpcUaModifySubscriptionRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaModifySubscriptionRequestClear", (RTS_UINTPTR)OpcUaModifySubscriptionRequestClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaModifySubscriptionRequestClear
	#define EXT_CmpOPCUAStackOpcUaModifySubscriptionRequestClear
	#define GET_CmpOPCUAStackOpcUaModifySubscriptionRequestClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaModifySubscriptionRequestClear pICmpOPCUAStack->IOpcUaModifySubscriptionRequestClear
	#define CHK_CmpOPCUAStackOpcUaModifySubscriptionRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaModifySubscriptionRequestClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaModifySubscriptionRequestClear
	#define EXT_OpcUaModifySubscriptionRequestClear
	#define GET_OpcUaModifySubscriptionRequestClear(fl)  CAL_CMGETAPI( "OpcUaModifySubscriptionRequestClear" ) 
	#define CAL_OpcUaModifySubscriptionRequestClear pICmpOPCUAStack->IOpcUaModifySubscriptionRequestClear
	#define CHK_OpcUaModifySubscriptionRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaModifySubscriptionRequestClear  CAL_CMEXPAPI( "OpcUaModifySubscriptionRequestClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaModifySubscriptionRequestClear  PFOPCUAMODIFYSUBSCRIPTIONREQUESTCLEAR pfOpcUaModifySubscriptionRequestClear;
	#define EXT_OpcUaModifySubscriptionRequestClear  extern PFOPCUAMODIFYSUBSCRIPTIONREQUESTCLEAR pfOpcUaModifySubscriptionRequestClear;
	#define GET_OpcUaModifySubscriptionRequestClear(fl)  s_pfCMGetAPI2( "OpcUaModifySubscriptionRequestClear", (RTS_VOID_FCTPTR *)&pfOpcUaModifySubscriptionRequestClear, (fl), 0, 0)
	#define CAL_OpcUaModifySubscriptionRequestClear  pfOpcUaModifySubscriptionRequestClear
	#define CHK_OpcUaModifySubscriptionRequestClear  (pfOpcUaModifySubscriptionRequestClear != NULL)
	#define EXP_OpcUaModifySubscriptionRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaModifySubscriptionRequestClear", (RTS_UINTPTR)OpcUaModifySubscriptionRequestClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaPublishRequestInitialize(OpcUa_PublishRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAPUBLISHREQUESTINITIALIZE) (OpcUa_PublishRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAPUBLISHREQUESTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaPublishRequestInitialize
	#define EXT_OpcUaPublishRequestInitialize
	#define GET_OpcUaPublishRequestInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaPublishRequestInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaPublishRequestInitialize  FALSE
	#define EXP_OpcUaPublishRequestInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaPublishRequestInitialize
	#define EXT_OpcUaPublishRequestInitialize
	#define GET_OpcUaPublishRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaPublishRequestInitialize" ) 
	#define CAL_OpcUaPublishRequestInitialize  OpcUaPublishRequestInitialize
	#define CHK_OpcUaPublishRequestInitialize  TRUE
	#define EXP_OpcUaPublishRequestInitialize  CAL_CMEXPAPI( "OpcUaPublishRequestInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaPublishRequestInitialize
	#define EXT_OpcUaPublishRequestInitialize
	#define GET_OpcUaPublishRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaPublishRequestInitialize" ) 
	#define CAL_OpcUaPublishRequestInitialize  OpcUaPublishRequestInitialize
	#define CHK_OpcUaPublishRequestInitialize  TRUE
	#define EXP_OpcUaPublishRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaPublishRequestInitialize", (RTS_UINTPTR)OpcUaPublishRequestInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaPublishRequestInitialize
	#define EXT_CmpOPCUAStackOpcUaPublishRequestInitialize
	#define GET_CmpOPCUAStackOpcUaPublishRequestInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaPublishRequestInitialize pICmpOPCUAStack->IOpcUaPublishRequestInitialize
	#define CHK_CmpOPCUAStackOpcUaPublishRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaPublishRequestInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaPublishRequestInitialize
	#define EXT_OpcUaPublishRequestInitialize
	#define GET_OpcUaPublishRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaPublishRequestInitialize" ) 
	#define CAL_OpcUaPublishRequestInitialize pICmpOPCUAStack->IOpcUaPublishRequestInitialize
	#define CHK_OpcUaPublishRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaPublishRequestInitialize  CAL_CMEXPAPI( "OpcUaPublishRequestInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaPublishRequestInitialize  PFOPCUAPUBLISHREQUESTINITIALIZE pfOpcUaPublishRequestInitialize;
	#define EXT_OpcUaPublishRequestInitialize  extern PFOPCUAPUBLISHREQUESTINITIALIZE pfOpcUaPublishRequestInitialize;
	#define GET_OpcUaPublishRequestInitialize(fl)  s_pfCMGetAPI2( "OpcUaPublishRequestInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaPublishRequestInitialize, (fl), 0, 0)
	#define CAL_OpcUaPublishRequestInitialize  pfOpcUaPublishRequestInitialize
	#define CHK_OpcUaPublishRequestInitialize  (pfOpcUaPublishRequestInitialize != NULL)
	#define EXP_OpcUaPublishRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaPublishRequestInitialize", (RTS_UINTPTR)OpcUaPublishRequestInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaPublishRequestClear(OpcUa_PublishRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAPUBLISHREQUESTCLEAR) (OpcUa_PublishRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAPUBLISHREQUESTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaPublishRequestClear
	#define EXT_OpcUaPublishRequestClear
	#define GET_OpcUaPublishRequestClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaPublishRequestClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaPublishRequestClear  FALSE
	#define EXP_OpcUaPublishRequestClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaPublishRequestClear
	#define EXT_OpcUaPublishRequestClear
	#define GET_OpcUaPublishRequestClear(fl)  CAL_CMGETAPI( "OpcUaPublishRequestClear" ) 
	#define CAL_OpcUaPublishRequestClear  OpcUaPublishRequestClear
	#define CHK_OpcUaPublishRequestClear  TRUE
	#define EXP_OpcUaPublishRequestClear  CAL_CMEXPAPI( "OpcUaPublishRequestClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaPublishRequestClear
	#define EXT_OpcUaPublishRequestClear
	#define GET_OpcUaPublishRequestClear(fl)  CAL_CMGETAPI( "OpcUaPublishRequestClear" ) 
	#define CAL_OpcUaPublishRequestClear  OpcUaPublishRequestClear
	#define CHK_OpcUaPublishRequestClear  TRUE
	#define EXP_OpcUaPublishRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaPublishRequestClear", (RTS_UINTPTR)OpcUaPublishRequestClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaPublishRequestClear
	#define EXT_CmpOPCUAStackOpcUaPublishRequestClear
	#define GET_CmpOPCUAStackOpcUaPublishRequestClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaPublishRequestClear pICmpOPCUAStack->IOpcUaPublishRequestClear
	#define CHK_CmpOPCUAStackOpcUaPublishRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaPublishRequestClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaPublishRequestClear
	#define EXT_OpcUaPublishRequestClear
	#define GET_OpcUaPublishRequestClear(fl)  CAL_CMGETAPI( "OpcUaPublishRequestClear" ) 
	#define CAL_OpcUaPublishRequestClear pICmpOPCUAStack->IOpcUaPublishRequestClear
	#define CHK_OpcUaPublishRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaPublishRequestClear  CAL_CMEXPAPI( "OpcUaPublishRequestClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaPublishRequestClear  PFOPCUAPUBLISHREQUESTCLEAR pfOpcUaPublishRequestClear;
	#define EXT_OpcUaPublishRequestClear  extern PFOPCUAPUBLISHREQUESTCLEAR pfOpcUaPublishRequestClear;
	#define GET_OpcUaPublishRequestClear(fl)  s_pfCMGetAPI2( "OpcUaPublishRequestClear", (RTS_VOID_FCTPTR *)&pfOpcUaPublishRequestClear, (fl), 0, 0)
	#define CAL_OpcUaPublishRequestClear  pfOpcUaPublishRequestClear
	#define CHK_OpcUaPublishRequestClear  (pfOpcUaPublishRequestClear != NULL)
	#define EXP_OpcUaPublishRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaPublishRequestClear", (RTS_UINTPTR)OpcUaPublishRequestClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaRepublishRequestInitialize(OpcUa_RepublishRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAREPUBLISHREQUESTINITIALIZE) (OpcUa_RepublishRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAREPUBLISHREQUESTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaRepublishRequestInitialize
	#define EXT_OpcUaRepublishRequestInitialize
	#define GET_OpcUaRepublishRequestInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaRepublishRequestInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaRepublishRequestInitialize  FALSE
	#define EXP_OpcUaRepublishRequestInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaRepublishRequestInitialize
	#define EXT_OpcUaRepublishRequestInitialize
	#define GET_OpcUaRepublishRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaRepublishRequestInitialize" ) 
	#define CAL_OpcUaRepublishRequestInitialize  OpcUaRepublishRequestInitialize
	#define CHK_OpcUaRepublishRequestInitialize  TRUE
	#define EXP_OpcUaRepublishRequestInitialize  CAL_CMEXPAPI( "OpcUaRepublishRequestInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaRepublishRequestInitialize
	#define EXT_OpcUaRepublishRequestInitialize
	#define GET_OpcUaRepublishRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaRepublishRequestInitialize" ) 
	#define CAL_OpcUaRepublishRequestInitialize  OpcUaRepublishRequestInitialize
	#define CHK_OpcUaRepublishRequestInitialize  TRUE
	#define EXP_OpcUaRepublishRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaRepublishRequestInitialize", (RTS_UINTPTR)OpcUaRepublishRequestInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaRepublishRequestInitialize
	#define EXT_CmpOPCUAStackOpcUaRepublishRequestInitialize
	#define GET_CmpOPCUAStackOpcUaRepublishRequestInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaRepublishRequestInitialize pICmpOPCUAStack->IOpcUaRepublishRequestInitialize
	#define CHK_CmpOPCUAStackOpcUaRepublishRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaRepublishRequestInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaRepublishRequestInitialize
	#define EXT_OpcUaRepublishRequestInitialize
	#define GET_OpcUaRepublishRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaRepublishRequestInitialize" ) 
	#define CAL_OpcUaRepublishRequestInitialize pICmpOPCUAStack->IOpcUaRepublishRequestInitialize
	#define CHK_OpcUaRepublishRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaRepublishRequestInitialize  CAL_CMEXPAPI( "OpcUaRepublishRequestInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaRepublishRequestInitialize  PFOPCUAREPUBLISHREQUESTINITIALIZE pfOpcUaRepublishRequestInitialize;
	#define EXT_OpcUaRepublishRequestInitialize  extern PFOPCUAREPUBLISHREQUESTINITIALIZE pfOpcUaRepublishRequestInitialize;
	#define GET_OpcUaRepublishRequestInitialize(fl)  s_pfCMGetAPI2( "OpcUaRepublishRequestInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaRepublishRequestInitialize, (fl), 0, 0)
	#define CAL_OpcUaRepublishRequestInitialize  pfOpcUaRepublishRequestInitialize
	#define CHK_OpcUaRepublishRequestInitialize  (pfOpcUaRepublishRequestInitialize != NULL)
	#define EXP_OpcUaRepublishRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaRepublishRequestInitialize", (RTS_UINTPTR)OpcUaRepublishRequestInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaRepublishRequestClear(OpcUa_RepublishRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAREPUBLISHREQUESTCLEAR) (OpcUa_RepublishRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAREPUBLISHREQUESTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaRepublishRequestClear
	#define EXT_OpcUaRepublishRequestClear
	#define GET_OpcUaRepublishRequestClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaRepublishRequestClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaRepublishRequestClear  FALSE
	#define EXP_OpcUaRepublishRequestClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaRepublishRequestClear
	#define EXT_OpcUaRepublishRequestClear
	#define GET_OpcUaRepublishRequestClear(fl)  CAL_CMGETAPI( "OpcUaRepublishRequestClear" ) 
	#define CAL_OpcUaRepublishRequestClear  OpcUaRepublishRequestClear
	#define CHK_OpcUaRepublishRequestClear  TRUE
	#define EXP_OpcUaRepublishRequestClear  CAL_CMEXPAPI( "OpcUaRepublishRequestClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaRepublishRequestClear
	#define EXT_OpcUaRepublishRequestClear
	#define GET_OpcUaRepublishRequestClear(fl)  CAL_CMGETAPI( "OpcUaRepublishRequestClear" ) 
	#define CAL_OpcUaRepublishRequestClear  OpcUaRepublishRequestClear
	#define CHK_OpcUaRepublishRequestClear  TRUE
	#define EXP_OpcUaRepublishRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaRepublishRequestClear", (RTS_UINTPTR)OpcUaRepublishRequestClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaRepublishRequestClear
	#define EXT_CmpOPCUAStackOpcUaRepublishRequestClear
	#define GET_CmpOPCUAStackOpcUaRepublishRequestClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaRepublishRequestClear pICmpOPCUAStack->IOpcUaRepublishRequestClear
	#define CHK_CmpOPCUAStackOpcUaRepublishRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaRepublishRequestClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaRepublishRequestClear
	#define EXT_OpcUaRepublishRequestClear
	#define GET_OpcUaRepublishRequestClear(fl)  CAL_CMGETAPI( "OpcUaRepublishRequestClear" ) 
	#define CAL_OpcUaRepublishRequestClear pICmpOPCUAStack->IOpcUaRepublishRequestClear
	#define CHK_OpcUaRepublishRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaRepublishRequestClear  CAL_CMEXPAPI( "OpcUaRepublishRequestClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaRepublishRequestClear  PFOPCUAREPUBLISHREQUESTCLEAR pfOpcUaRepublishRequestClear;
	#define EXT_OpcUaRepublishRequestClear  extern PFOPCUAREPUBLISHREQUESTCLEAR pfOpcUaRepublishRequestClear;
	#define GET_OpcUaRepublishRequestClear(fl)  s_pfCMGetAPI2( "OpcUaRepublishRequestClear", (RTS_VOID_FCTPTR *)&pfOpcUaRepublishRequestClear, (fl), 0, 0)
	#define CAL_OpcUaRepublishRequestClear  pfOpcUaRepublishRequestClear
	#define CHK_OpcUaRepublishRequestClear  (pfOpcUaRepublishRequestClear != NULL)
	#define EXP_OpcUaRepublishRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaRepublishRequestClear", (RTS_UINTPTR)OpcUaRepublishRequestClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaSetPublishingModeRequestInitialize(OpcUa_SetPublishingModeRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUASETPUBLISHINGMODEREQUESTINITIALIZE) (OpcUa_SetPublishingModeRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASETPUBLISHINGMODEREQUESTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaSetPublishingModeRequestInitialize
	#define EXT_OpcUaSetPublishingModeRequestInitialize
	#define GET_OpcUaSetPublishingModeRequestInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaSetPublishingModeRequestInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaSetPublishingModeRequestInitialize  FALSE
	#define EXP_OpcUaSetPublishingModeRequestInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaSetPublishingModeRequestInitialize
	#define EXT_OpcUaSetPublishingModeRequestInitialize
	#define GET_OpcUaSetPublishingModeRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaSetPublishingModeRequestInitialize" ) 
	#define CAL_OpcUaSetPublishingModeRequestInitialize  OpcUaSetPublishingModeRequestInitialize
	#define CHK_OpcUaSetPublishingModeRequestInitialize  TRUE
	#define EXP_OpcUaSetPublishingModeRequestInitialize  CAL_CMEXPAPI( "OpcUaSetPublishingModeRequestInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaSetPublishingModeRequestInitialize
	#define EXT_OpcUaSetPublishingModeRequestInitialize
	#define GET_OpcUaSetPublishingModeRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaSetPublishingModeRequestInitialize" ) 
	#define CAL_OpcUaSetPublishingModeRequestInitialize  OpcUaSetPublishingModeRequestInitialize
	#define CHK_OpcUaSetPublishingModeRequestInitialize  TRUE
	#define EXP_OpcUaSetPublishingModeRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSetPublishingModeRequestInitialize", (RTS_UINTPTR)OpcUaSetPublishingModeRequestInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaSetPublishingModeRequestInitialize
	#define EXT_CmpOPCUAStackOpcUaSetPublishingModeRequestInitialize
	#define GET_CmpOPCUAStackOpcUaSetPublishingModeRequestInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaSetPublishingModeRequestInitialize pICmpOPCUAStack->IOpcUaSetPublishingModeRequestInitialize
	#define CHK_CmpOPCUAStackOpcUaSetPublishingModeRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaSetPublishingModeRequestInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaSetPublishingModeRequestInitialize
	#define EXT_OpcUaSetPublishingModeRequestInitialize
	#define GET_OpcUaSetPublishingModeRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaSetPublishingModeRequestInitialize" ) 
	#define CAL_OpcUaSetPublishingModeRequestInitialize pICmpOPCUAStack->IOpcUaSetPublishingModeRequestInitialize
	#define CHK_OpcUaSetPublishingModeRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaSetPublishingModeRequestInitialize  CAL_CMEXPAPI( "OpcUaSetPublishingModeRequestInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaSetPublishingModeRequestInitialize  PFOPCUASETPUBLISHINGMODEREQUESTINITIALIZE pfOpcUaSetPublishingModeRequestInitialize;
	#define EXT_OpcUaSetPublishingModeRequestInitialize  extern PFOPCUASETPUBLISHINGMODEREQUESTINITIALIZE pfOpcUaSetPublishingModeRequestInitialize;
	#define GET_OpcUaSetPublishingModeRequestInitialize(fl)  s_pfCMGetAPI2( "OpcUaSetPublishingModeRequestInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaSetPublishingModeRequestInitialize, (fl), 0, 0)
	#define CAL_OpcUaSetPublishingModeRequestInitialize  pfOpcUaSetPublishingModeRequestInitialize
	#define CHK_OpcUaSetPublishingModeRequestInitialize  (pfOpcUaSetPublishingModeRequestInitialize != NULL)
	#define EXP_OpcUaSetPublishingModeRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSetPublishingModeRequestInitialize", (RTS_UINTPTR)OpcUaSetPublishingModeRequestInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaSetPublishingModeRequestClear(OpcUa_SetPublishingModeRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUASETPUBLISHINGMODEREQUESTCLEAR) (OpcUa_SetPublishingModeRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASETPUBLISHINGMODEREQUESTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaSetPublishingModeRequestClear
	#define EXT_OpcUaSetPublishingModeRequestClear
	#define GET_OpcUaSetPublishingModeRequestClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaSetPublishingModeRequestClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaSetPublishingModeRequestClear  FALSE
	#define EXP_OpcUaSetPublishingModeRequestClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaSetPublishingModeRequestClear
	#define EXT_OpcUaSetPublishingModeRequestClear
	#define GET_OpcUaSetPublishingModeRequestClear(fl)  CAL_CMGETAPI( "OpcUaSetPublishingModeRequestClear" ) 
	#define CAL_OpcUaSetPublishingModeRequestClear  OpcUaSetPublishingModeRequestClear
	#define CHK_OpcUaSetPublishingModeRequestClear  TRUE
	#define EXP_OpcUaSetPublishingModeRequestClear  CAL_CMEXPAPI( "OpcUaSetPublishingModeRequestClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaSetPublishingModeRequestClear
	#define EXT_OpcUaSetPublishingModeRequestClear
	#define GET_OpcUaSetPublishingModeRequestClear(fl)  CAL_CMGETAPI( "OpcUaSetPublishingModeRequestClear" ) 
	#define CAL_OpcUaSetPublishingModeRequestClear  OpcUaSetPublishingModeRequestClear
	#define CHK_OpcUaSetPublishingModeRequestClear  TRUE
	#define EXP_OpcUaSetPublishingModeRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSetPublishingModeRequestClear", (RTS_UINTPTR)OpcUaSetPublishingModeRequestClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaSetPublishingModeRequestClear
	#define EXT_CmpOPCUAStackOpcUaSetPublishingModeRequestClear
	#define GET_CmpOPCUAStackOpcUaSetPublishingModeRequestClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaSetPublishingModeRequestClear pICmpOPCUAStack->IOpcUaSetPublishingModeRequestClear
	#define CHK_CmpOPCUAStackOpcUaSetPublishingModeRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaSetPublishingModeRequestClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaSetPublishingModeRequestClear
	#define EXT_OpcUaSetPublishingModeRequestClear
	#define GET_OpcUaSetPublishingModeRequestClear(fl)  CAL_CMGETAPI( "OpcUaSetPublishingModeRequestClear" ) 
	#define CAL_OpcUaSetPublishingModeRequestClear pICmpOPCUAStack->IOpcUaSetPublishingModeRequestClear
	#define CHK_OpcUaSetPublishingModeRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaSetPublishingModeRequestClear  CAL_CMEXPAPI( "OpcUaSetPublishingModeRequestClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaSetPublishingModeRequestClear  PFOPCUASETPUBLISHINGMODEREQUESTCLEAR pfOpcUaSetPublishingModeRequestClear;
	#define EXT_OpcUaSetPublishingModeRequestClear  extern PFOPCUASETPUBLISHINGMODEREQUESTCLEAR pfOpcUaSetPublishingModeRequestClear;
	#define GET_OpcUaSetPublishingModeRequestClear(fl)  s_pfCMGetAPI2( "OpcUaSetPublishingModeRequestClear", (RTS_VOID_FCTPTR *)&pfOpcUaSetPublishingModeRequestClear, (fl), 0, 0)
	#define CAL_OpcUaSetPublishingModeRequestClear  pfOpcUaSetPublishingModeRequestClear
	#define CHK_OpcUaSetPublishingModeRequestClear  (pfOpcUaSetPublishingModeRequestClear != NULL)
	#define EXP_OpcUaSetPublishingModeRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSetPublishingModeRequestClear", (RTS_UINTPTR)OpcUaSetPublishingModeRequestClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaDeleteSubscriptionsRequestInitialize(OpcUa_DeleteSubscriptionsRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUADELETESUBSCRIPTIONSREQUESTINITIALIZE) (OpcUa_DeleteSubscriptionsRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUADELETESUBSCRIPTIONSREQUESTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaDeleteSubscriptionsRequestInitialize
	#define EXT_OpcUaDeleteSubscriptionsRequestInitialize
	#define GET_OpcUaDeleteSubscriptionsRequestInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaDeleteSubscriptionsRequestInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaDeleteSubscriptionsRequestInitialize  FALSE
	#define EXP_OpcUaDeleteSubscriptionsRequestInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaDeleteSubscriptionsRequestInitialize
	#define EXT_OpcUaDeleteSubscriptionsRequestInitialize
	#define GET_OpcUaDeleteSubscriptionsRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaDeleteSubscriptionsRequestInitialize" ) 
	#define CAL_OpcUaDeleteSubscriptionsRequestInitialize  OpcUaDeleteSubscriptionsRequestInitialize
	#define CHK_OpcUaDeleteSubscriptionsRequestInitialize  TRUE
	#define EXP_OpcUaDeleteSubscriptionsRequestInitialize  CAL_CMEXPAPI( "OpcUaDeleteSubscriptionsRequestInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaDeleteSubscriptionsRequestInitialize
	#define EXT_OpcUaDeleteSubscriptionsRequestInitialize
	#define GET_OpcUaDeleteSubscriptionsRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaDeleteSubscriptionsRequestInitialize" ) 
	#define CAL_OpcUaDeleteSubscriptionsRequestInitialize  OpcUaDeleteSubscriptionsRequestInitialize
	#define CHK_OpcUaDeleteSubscriptionsRequestInitialize  TRUE
	#define EXP_OpcUaDeleteSubscriptionsRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDeleteSubscriptionsRequestInitialize", (RTS_UINTPTR)OpcUaDeleteSubscriptionsRequestInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaDeleteSubscriptionsRequestInitialize
	#define EXT_CmpOPCUAStackOpcUaDeleteSubscriptionsRequestInitialize
	#define GET_CmpOPCUAStackOpcUaDeleteSubscriptionsRequestInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaDeleteSubscriptionsRequestInitialize pICmpOPCUAStack->IOpcUaDeleteSubscriptionsRequestInitialize
	#define CHK_CmpOPCUAStackOpcUaDeleteSubscriptionsRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaDeleteSubscriptionsRequestInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaDeleteSubscriptionsRequestInitialize
	#define EXT_OpcUaDeleteSubscriptionsRequestInitialize
	#define GET_OpcUaDeleteSubscriptionsRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaDeleteSubscriptionsRequestInitialize" ) 
	#define CAL_OpcUaDeleteSubscriptionsRequestInitialize pICmpOPCUAStack->IOpcUaDeleteSubscriptionsRequestInitialize
	#define CHK_OpcUaDeleteSubscriptionsRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaDeleteSubscriptionsRequestInitialize  CAL_CMEXPAPI( "OpcUaDeleteSubscriptionsRequestInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaDeleteSubscriptionsRequestInitialize  PFOPCUADELETESUBSCRIPTIONSREQUESTINITIALIZE pfOpcUaDeleteSubscriptionsRequestInitialize;
	#define EXT_OpcUaDeleteSubscriptionsRequestInitialize  extern PFOPCUADELETESUBSCRIPTIONSREQUESTINITIALIZE pfOpcUaDeleteSubscriptionsRequestInitialize;
	#define GET_OpcUaDeleteSubscriptionsRequestInitialize(fl)  s_pfCMGetAPI2( "OpcUaDeleteSubscriptionsRequestInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaDeleteSubscriptionsRequestInitialize, (fl), 0, 0)
	#define CAL_OpcUaDeleteSubscriptionsRequestInitialize  pfOpcUaDeleteSubscriptionsRequestInitialize
	#define CHK_OpcUaDeleteSubscriptionsRequestInitialize  (pfOpcUaDeleteSubscriptionsRequestInitialize != NULL)
	#define EXP_OpcUaDeleteSubscriptionsRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDeleteSubscriptionsRequestInitialize", (RTS_UINTPTR)OpcUaDeleteSubscriptionsRequestInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaDeleteSubscriptionsRequestClear(OpcUa_DeleteSubscriptionsRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUADELETESUBSCRIPTIONSREQUESTCLEAR) (OpcUa_DeleteSubscriptionsRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUADELETESUBSCRIPTIONSREQUESTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaDeleteSubscriptionsRequestClear
	#define EXT_OpcUaDeleteSubscriptionsRequestClear
	#define GET_OpcUaDeleteSubscriptionsRequestClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaDeleteSubscriptionsRequestClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaDeleteSubscriptionsRequestClear  FALSE
	#define EXP_OpcUaDeleteSubscriptionsRequestClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaDeleteSubscriptionsRequestClear
	#define EXT_OpcUaDeleteSubscriptionsRequestClear
	#define GET_OpcUaDeleteSubscriptionsRequestClear(fl)  CAL_CMGETAPI( "OpcUaDeleteSubscriptionsRequestClear" ) 
	#define CAL_OpcUaDeleteSubscriptionsRequestClear  OpcUaDeleteSubscriptionsRequestClear
	#define CHK_OpcUaDeleteSubscriptionsRequestClear  TRUE
	#define EXP_OpcUaDeleteSubscriptionsRequestClear  CAL_CMEXPAPI( "OpcUaDeleteSubscriptionsRequestClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaDeleteSubscriptionsRequestClear
	#define EXT_OpcUaDeleteSubscriptionsRequestClear
	#define GET_OpcUaDeleteSubscriptionsRequestClear(fl)  CAL_CMGETAPI( "OpcUaDeleteSubscriptionsRequestClear" ) 
	#define CAL_OpcUaDeleteSubscriptionsRequestClear  OpcUaDeleteSubscriptionsRequestClear
	#define CHK_OpcUaDeleteSubscriptionsRequestClear  TRUE
	#define EXP_OpcUaDeleteSubscriptionsRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDeleteSubscriptionsRequestClear", (RTS_UINTPTR)OpcUaDeleteSubscriptionsRequestClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaDeleteSubscriptionsRequestClear
	#define EXT_CmpOPCUAStackOpcUaDeleteSubscriptionsRequestClear
	#define GET_CmpOPCUAStackOpcUaDeleteSubscriptionsRequestClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaDeleteSubscriptionsRequestClear pICmpOPCUAStack->IOpcUaDeleteSubscriptionsRequestClear
	#define CHK_CmpOPCUAStackOpcUaDeleteSubscriptionsRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaDeleteSubscriptionsRequestClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaDeleteSubscriptionsRequestClear
	#define EXT_OpcUaDeleteSubscriptionsRequestClear
	#define GET_OpcUaDeleteSubscriptionsRequestClear(fl)  CAL_CMGETAPI( "OpcUaDeleteSubscriptionsRequestClear" ) 
	#define CAL_OpcUaDeleteSubscriptionsRequestClear pICmpOPCUAStack->IOpcUaDeleteSubscriptionsRequestClear
	#define CHK_OpcUaDeleteSubscriptionsRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaDeleteSubscriptionsRequestClear  CAL_CMEXPAPI( "OpcUaDeleteSubscriptionsRequestClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaDeleteSubscriptionsRequestClear  PFOPCUADELETESUBSCRIPTIONSREQUESTCLEAR pfOpcUaDeleteSubscriptionsRequestClear;
	#define EXT_OpcUaDeleteSubscriptionsRequestClear  extern PFOPCUADELETESUBSCRIPTIONSREQUESTCLEAR pfOpcUaDeleteSubscriptionsRequestClear;
	#define GET_OpcUaDeleteSubscriptionsRequestClear(fl)  s_pfCMGetAPI2( "OpcUaDeleteSubscriptionsRequestClear", (RTS_VOID_FCTPTR *)&pfOpcUaDeleteSubscriptionsRequestClear, (fl), 0, 0)
	#define CAL_OpcUaDeleteSubscriptionsRequestClear  pfOpcUaDeleteSubscriptionsRequestClear
	#define CHK_OpcUaDeleteSubscriptionsRequestClear  (pfOpcUaDeleteSubscriptionsRequestClear != NULL)
	#define EXP_OpcUaDeleteSubscriptionsRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDeleteSubscriptionsRequestClear", (RTS_UINTPTR)OpcUaDeleteSubscriptionsRequestClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaTransferSubscriptionsRequestInitialize(OpcUa_TransferSubscriptionsRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUATRANSFERSUBSCRIPTIONSREQUESTINITIALIZE) (OpcUa_TransferSubscriptionsRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUATRANSFERSUBSCRIPTIONSREQUESTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaTransferSubscriptionsRequestInitialize
	#define EXT_OpcUaTransferSubscriptionsRequestInitialize
	#define GET_OpcUaTransferSubscriptionsRequestInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaTransferSubscriptionsRequestInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaTransferSubscriptionsRequestInitialize  FALSE
	#define EXP_OpcUaTransferSubscriptionsRequestInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaTransferSubscriptionsRequestInitialize
	#define EXT_OpcUaTransferSubscriptionsRequestInitialize
	#define GET_OpcUaTransferSubscriptionsRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaTransferSubscriptionsRequestInitialize" ) 
	#define CAL_OpcUaTransferSubscriptionsRequestInitialize  OpcUaTransferSubscriptionsRequestInitialize
	#define CHK_OpcUaTransferSubscriptionsRequestInitialize  TRUE
	#define EXP_OpcUaTransferSubscriptionsRequestInitialize  CAL_CMEXPAPI( "OpcUaTransferSubscriptionsRequestInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaTransferSubscriptionsRequestInitialize
	#define EXT_OpcUaTransferSubscriptionsRequestInitialize
	#define GET_OpcUaTransferSubscriptionsRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaTransferSubscriptionsRequestInitialize" ) 
	#define CAL_OpcUaTransferSubscriptionsRequestInitialize  OpcUaTransferSubscriptionsRequestInitialize
	#define CHK_OpcUaTransferSubscriptionsRequestInitialize  TRUE
	#define EXP_OpcUaTransferSubscriptionsRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaTransferSubscriptionsRequestInitialize", (RTS_UINTPTR)OpcUaTransferSubscriptionsRequestInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaTransferSubscriptionsRequestInitialize
	#define EXT_CmpOPCUAStackOpcUaTransferSubscriptionsRequestInitialize
	#define GET_CmpOPCUAStackOpcUaTransferSubscriptionsRequestInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaTransferSubscriptionsRequestInitialize pICmpOPCUAStack->IOpcUaTransferSubscriptionsRequestInitialize
	#define CHK_CmpOPCUAStackOpcUaTransferSubscriptionsRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaTransferSubscriptionsRequestInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaTransferSubscriptionsRequestInitialize
	#define EXT_OpcUaTransferSubscriptionsRequestInitialize
	#define GET_OpcUaTransferSubscriptionsRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaTransferSubscriptionsRequestInitialize" ) 
	#define CAL_OpcUaTransferSubscriptionsRequestInitialize pICmpOPCUAStack->IOpcUaTransferSubscriptionsRequestInitialize
	#define CHK_OpcUaTransferSubscriptionsRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaTransferSubscriptionsRequestInitialize  CAL_CMEXPAPI( "OpcUaTransferSubscriptionsRequestInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaTransferSubscriptionsRequestInitialize  PFOPCUATRANSFERSUBSCRIPTIONSREQUESTINITIALIZE pfOpcUaTransferSubscriptionsRequestInitialize;
	#define EXT_OpcUaTransferSubscriptionsRequestInitialize  extern PFOPCUATRANSFERSUBSCRIPTIONSREQUESTINITIALIZE pfOpcUaTransferSubscriptionsRequestInitialize;
	#define GET_OpcUaTransferSubscriptionsRequestInitialize(fl)  s_pfCMGetAPI2( "OpcUaTransferSubscriptionsRequestInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaTransferSubscriptionsRequestInitialize, (fl), 0, 0)
	#define CAL_OpcUaTransferSubscriptionsRequestInitialize  pfOpcUaTransferSubscriptionsRequestInitialize
	#define CHK_OpcUaTransferSubscriptionsRequestInitialize  (pfOpcUaTransferSubscriptionsRequestInitialize != NULL)
	#define EXP_OpcUaTransferSubscriptionsRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaTransferSubscriptionsRequestInitialize", (RTS_UINTPTR)OpcUaTransferSubscriptionsRequestInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaTransferSubscriptionsRequestClear(OpcUa_TransferSubscriptionsRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUATRANSFERSUBSCRIPTIONSREQUESTCLEAR) (OpcUa_TransferSubscriptionsRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUATRANSFERSUBSCRIPTIONSREQUESTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaTransferSubscriptionsRequestClear
	#define EXT_OpcUaTransferSubscriptionsRequestClear
	#define GET_OpcUaTransferSubscriptionsRequestClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaTransferSubscriptionsRequestClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaTransferSubscriptionsRequestClear  FALSE
	#define EXP_OpcUaTransferSubscriptionsRequestClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaTransferSubscriptionsRequestClear
	#define EXT_OpcUaTransferSubscriptionsRequestClear
	#define GET_OpcUaTransferSubscriptionsRequestClear(fl)  CAL_CMGETAPI( "OpcUaTransferSubscriptionsRequestClear" ) 
	#define CAL_OpcUaTransferSubscriptionsRequestClear  OpcUaTransferSubscriptionsRequestClear
	#define CHK_OpcUaTransferSubscriptionsRequestClear  TRUE
	#define EXP_OpcUaTransferSubscriptionsRequestClear  CAL_CMEXPAPI( "OpcUaTransferSubscriptionsRequestClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaTransferSubscriptionsRequestClear
	#define EXT_OpcUaTransferSubscriptionsRequestClear
	#define GET_OpcUaTransferSubscriptionsRequestClear(fl)  CAL_CMGETAPI( "OpcUaTransferSubscriptionsRequestClear" ) 
	#define CAL_OpcUaTransferSubscriptionsRequestClear  OpcUaTransferSubscriptionsRequestClear
	#define CHK_OpcUaTransferSubscriptionsRequestClear  TRUE
	#define EXP_OpcUaTransferSubscriptionsRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaTransferSubscriptionsRequestClear", (RTS_UINTPTR)OpcUaTransferSubscriptionsRequestClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaTransferSubscriptionsRequestClear
	#define EXT_CmpOPCUAStackOpcUaTransferSubscriptionsRequestClear
	#define GET_CmpOPCUAStackOpcUaTransferSubscriptionsRequestClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaTransferSubscriptionsRequestClear pICmpOPCUAStack->IOpcUaTransferSubscriptionsRequestClear
	#define CHK_CmpOPCUAStackOpcUaTransferSubscriptionsRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaTransferSubscriptionsRequestClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaTransferSubscriptionsRequestClear
	#define EXT_OpcUaTransferSubscriptionsRequestClear
	#define GET_OpcUaTransferSubscriptionsRequestClear(fl)  CAL_CMGETAPI( "OpcUaTransferSubscriptionsRequestClear" ) 
	#define CAL_OpcUaTransferSubscriptionsRequestClear pICmpOPCUAStack->IOpcUaTransferSubscriptionsRequestClear
	#define CHK_OpcUaTransferSubscriptionsRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaTransferSubscriptionsRequestClear  CAL_CMEXPAPI( "OpcUaTransferSubscriptionsRequestClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaTransferSubscriptionsRequestClear  PFOPCUATRANSFERSUBSCRIPTIONSREQUESTCLEAR pfOpcUaTransferSubscriptionsRequestClear;
	#define EXT_OpcUaTransferSubscriptionsRequestClear  extern PFOPCUATRANSFERSUBSCRIPTIONSREQUESTCLEAR pfOpcUaTransferSubscriptionsRequestClear;
	#define GET_OpcUaTransferSubscriptionsRequestClear(fl)  s_pfCMGetAPI2( "OpcUaTransferSubscriptionsRequestClear", (RTS_VOID_FCTPTR *)&pfOpcUaTransferSubscriptionsRequestClear, (fl), 0, 0)
	#define CAL_OpcUaTransferSubscriptionsRequestClear  pfOpcUaTransferSubscriptionsRequestClear
	#define CHK_OpcUaTransferSubscriptionsRequestClear  (pfOpcUaTransferSubscriptionsRequestClear != NULL)
	#define EXP_OpcUaTransferSubscriptionsRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaTransferSubscriptionsRequestClear", (RTS_UINTPTR)OpcUaTransferSubscriptionsRequestClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaCreateSubscriptionResponseInitialize(OpcUa_CreateSubscriptionResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUACREATESUBSCRIPTIONRESPONSEINITIALIZE) (OpcUa_CreateSubscriptionResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACREATESUBSCRIPTIONRESPONSEINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaCreateSubscriptionResponseInitialize
	#define EXT_OpcUaCreateSubscriptionResponseInitialize
	#define GET_OpcUaCreateSubscriptionResponseInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaCreateSubscriptionResponseInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaCreateSubscriptionResponseInitialize  FALSE
	#define EXP_OpcUaCreateSubscriptionResponseInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaCreateSubscriptionResponseInitialize
	#define EXT_OpcUaCreateSubscriptionResponseInitialize
	#define GET_OpcUaCreateSubscriptionResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaCreateSubscriptionResponseInitialize" ) 
	#define CAL_OpcUaCreateSubscriptionResponseInitialize  OpcUaCreateSubscriptionResponseInitialize
	#define CHK_OpcUaCreateSubscriptionResponseInitialize  TRUE
	#define EXP_OpcUaCreateSubscriptionResponseInitialize  CAL_CMEXPAPI( "OpcUaCreateSubscriptionResponseInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaCreateSubscriptionResponseInitialize
	#define EXT_OpcUaCreateSubscriptionResponseInitialize
	#define GET_OpcUaCreateSubscriptionResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaCreateSubscriptionResponseInitialize" ) 
	#define CAL_OpcUaCreateSubscriptionResponseInitialize  OpcUaCreateSubscriptionResponseInitialize
	#define CHK_OpcUaCreateSubscriptionResponseInitialize  TRUE
	#define EXP_OpcUaCreateSubscriptionResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCreateSubscriptionResponseInitialize", (RTS_UINTPTR)OpcUaCreateSubscriptionResponseInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaCreateSubscriptionResponseInitialize
	#define EXT_CmpOPCUAStackOpcUaCreateSubscriptionResponseInitialize
	#define GET_CmpOPCUAStackOpcUaCreateSubscriptionResponseInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaCreateSubscriptionResponseInitialize pICmpOPCUAStack->IOpcUaCreateSubscriptionResponseInitialize
	#define CHK_CmpOPCUAStackOpcUaCreateSubscriptionResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaCreateSubscriptionResponseInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaCreateSubscriptionResponseInitialize
	#define EXT_OpcUaCreateSubscriptionResponseInitialize
	#define GET_OpcUaCreateSubscriptionResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaCreateSubscriptionResponseInitialize" ) 
	#define CAL_OpcUaCreateSubscriptionResponseInitialize pICmpOPCUAStack->IOpcUaCreateSubscriptionResponseInitialize
	#define CHK_OpcUaCreateSubscriptionResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaCreateSubscriptionResponseInitialize  CAL_CMEXPAPI( "OpcUaCreateSubscriptionResponseInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaCreateSubscriptionResponseInitialize  PFOPCUACREATESUBSCRIPTIONRESPONSEINITIALIZE pfOpcUaCreateSubscriptionResponseInitialize;
	#define EXT_OpcUaCreateSubscriptionResponseInitialize  extern PFOPCUACREATESUBSCRIPTIONRESPONSEINITIALIZE pfOpcUaCreateSubscriptionResponseInitialize;
	#define GET_OpcUaCreateSubscriptionResponseInitialize(fl)  s_pfCMGetAPI2( "OpcUaCreateSubscriptionResponseInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaCreateSubscriptionResponseInitialize, (fl), 0, 0)
	#define CAL_OpcUaCreateSubscriptionResponseInitialize  pfOpcUaCreateSubscriptionResponseInitialize
	#define CHK_OpcUaCreateSubscriptionResponseInitialize  (pfOpcUaCreateSubscriptionResponseInitialize != NULL)
	#define EXP_OpcUaCreateSubscriptionResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCreateSubscriptionResponseInitialize", (RTS_UINTPTR)OpcUaCreateSubscriptionResponseInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaCreateSubscriptionResponseClear(OpcUa_CreateSubscriptionResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUACREATESUBSCRIPTIONRESPONSECLEAR) (OpcUa_CreateSubscriptionResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACREATESUBSCRIPTIONRESPONSECLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaCreateSubscriptionResponseClear
	#define EXT_OpcUaCreateSubscriptionResponseClear
	#define GET_OpcUaCreateSubscriptionResponseClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaCreateSubscriptionResponseClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaCreateSubscriptionResponseClear  FALSE
	#define EXP_OpcUaCreateSubscriptionResponseClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaCreateSubscriptionResponseClear
	#define EXT_OpcUaCreateSubscriptionResponseClear
	#define GET_OpcUaCreateSubscriptionResponseClear(fl)  CAL_CMGETAPI( "OpcUaCreateSubscriptionResponseClear" ) 
	#define CAL_OpcUaCreateSubscriptionResponseClear  OpcUaCreateSubscriptionResponseClear
	#define CHK_OpcUaCreateSubscriptionResponseClear  TRUE
	#define EXP_OpcUaCreateSubscriptionResponseClear  CAL_CMEXPAPI( "OpcUaCreateSubscriptionResponseClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaCreateSubscriptionResponseClear
	#define EXT_OpcUaCreateSubscriptionResponseClear
	#define GET_OpcUaCreateSubscriptionResponseClear(fl)  CAL_CMGETAPI( "OpcUaCreateSubscriptionResponseClear" ) 
	#define CAL_OpcUaCreateSubscriptionResponseClear  OpcUaCreateSubscriptionResponseClear
	#define CHK_OpcUaCreateSubscriptionResponseClear  TRUE
	#define EXP_OpcUaCreateSubscriptionResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCreateSubscriptionResponseClear", (RTS_UINTPTR)OpcUaCreateSubscriptionResponseClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaCreateSubscriptionResponseClear
	#define EXT_CmpOPCUAStackOpcUaCreateSubscriptionResponseClear
	#define GET_CmpOPCUAStackOpcUaCreateSubscriptionResponseClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaCreateSubscriptionResponseClear pICmpOPCUAStack->IOpcUaCreateSubscriptionResponseClear
	#define CHK_CmpOPCUAStackOpcUaCreateSubscriptionResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaCreateSubscriptionResponseClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaCreateSubscriptionResponseClear
	#define EXT_OpcUaCreateSubscriptionResponseClear
	#define GET_OpcUaCreateSubscriptionResponseClear(fl)  CAL_CMGETAPI( "OpcUaCreateSubscriptionResponseClear" ) 
	#define CAL_OpcUaCreateSubscriptionResponseClear pICmpOPCUAStack->IOpcUaCreateSubscriptionResponseClear
	#define CHK_OpcUaCreateSubscriptionResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaCreateSubscriptionResponseClear  CAL_CMEXPAPI( "OpcUaCreateSubscriptionResponseClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaCreateSubscriptionResponseClear  PFOPCUACREATESUBSCRIPTIONRESPONSECLEAR pfOpcUaCreateSubscriptionResponseClear;
	#define EXT_OpcUaCreateSubscriptionResponseClear  extern PFOPCUACREATESUBSCRIPTIONRESPONSECLEAR pfOpcUaCreateSubscriptionResponseClear;
	#define GET_OpcUaCreateSubscriptionResponseClear(fl)  s_pfCMGetAPI2( "OpcUaCreateSubscriptionResponseClear", (RTS_VOID_FCTPTR *)&pfOpcUaCreateSubscriptionResponseClear, (fl), 0, 0)
	#define CAL_OpcUaCreateSubscriptionResponseClear  pfOpcUaCreateSubscriptionResponseClear
	#define CHK_OpcUaCreateSubscriptionResponseClear  (pfOpcUaCreateSubscriptionResponseClear != NULL)
	#define EXP_OpcUaCreateSubscriptionResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCreateSubscriptionResponseClear", (RTS_UINTPTR)OpcUaCreateSubscriptionResponseClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaModifySubscriptionResponseInitialize(OpcUa_ModifySubscriptionResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAMODIFYSUBSCRIPTIONRESPONSEINITIALIZE) (OpcUa_ModifySubscriptionResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAMODIFYSUBSCRIPTIONRESPONSEINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaModifySubscriptionResponseInitialize
	#define EXT_OpcUaModifySubscriptionResponseInitialize
	#define GET_OpcUaModifySubscriptionResponseInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaModifySubscriptionResponseInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaModifySubscriptionResponseInitialize  FALSE
	#define EXP_OpcUaModifySubscriptionResponseInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaModifySubscriptionResponseInitialize
	#define EXT_OpcUaModifySubscriptionResponseInitialize
	#define GET_OpcUaModifySubscriptionResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaModifySubscriptionResponseInitialize" ) 
	#define CAL_OpcUaModifySubscriptionResponseInitialize  OpcUaModifySubscriptionResponseInitialize
	#define CHK_OpcUaModifySubscriptionResponseInitialize  TRUE
	#define EXP_OpcUaModifySubscriptionResponseInitialize  CAL_CMEXPAPI( "OpcUaModifySubscriptionResponseInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaModifySubscriptionResponseInitialize
	#define EXT_OpcUaModifySubscriptionResponseInitialize
	#define GET_OpcUaModifySubscriptionResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaModifySubscriptionResponseInitialize" ) 
	#define CAL_OpcUaModifySubscriptionResponseInitialize  OpcUaModifySubscriptionResponseInitialize
	#define CHK_OpcUaModifySubscriptionResponseInitialize  TRUE
	#define EXP_OpcUaModifySubscriptionResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaModifySubscriptionResponseInitialize", (RTS_UINTPTR)OpcUaModifySubscriptionResponseInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaModifySubscriptionResponseInitialize
	#define EXT_CmpOPCUAStackOpcUaModifySubscriptionResponseInitialize
	#define GET_CmpOPCUAStackOpcUaModifySubscriptionResponseInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaModifySubscriptionResponseInitialize pICmpOPCUAStack->IOpcUaModifySubscriptionResponseInitialize
	#define CHK_CmpOPCUAStackOpcUaModifySubscriptionResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaModifySubscriptionResponseInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaModifySubscriptionResponseInitialize
	#define EXT_OpcUaModifySubscriptionResponseInitialize
	#define GET_OpcUaModifySubscriptionResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaModifySubscriptionResponseInitialize" ) 
	#define CAL_OpcUaModifySubscriptionResponseInitialize pICmpOPCUAStack->IOpcUaModifySubscriptionResponseInitialize
	#define CHK_OpcUaModifySubscriptionResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaModifySubscriptionResponseInitialize  CAL_CMEXPAPI( "OpcUaModifySubscriptionResponseInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaModifySubscriptionResponseInitialize  PFOPCUAMODIFYSUBSCRIPTIONRESPONSEINITIALIZE pfOpcUaModifySubscriptionResponseInitialize;
	#define EXT_OpcUaModifySubscriptionResponseInitialize  extern PFOPCUAMODIFYSUBSCRIPTIONRESPONSEINITIALIZE pfOpcUaModifySubscriptionResponseInitialize;
	#define GET_OpcUaModifySubscriptionResponseInitialize(fl)  s_pfCMGetAPI2( "OpcUaModifySubscriptionResponseInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaModifySubscriptionResponseInitialize, (fl), 0, 0)
	#define CAL_OpcUaModifySubscriptionResponseInitialize  pfOpcUaModifySubscriptionResponseInitialize
	#define CHK_OpcUaModifySubscriptionResponseInitialize  (pfOpcUaModifySubscriptionResponseInitialize != NULL)
	#define EXP_OpcUaModifySubscriptionResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaModifySubscriptionResponseInitialize", (RTS_UINTPTR)OpcUaModifySubscriptionResponseInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaModifySubscriptionResponseClear(OpcUa_ModifySubscriptionResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAMODIFYSUBSCRIPTIONRESPONSECLEAR) (OpcUa_ModifySubscriptionResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAMODIFYSUBSCRIPTIONRESPONSECLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaModifySubscriptionResponseClear
	#define EXT_OpcUaModifySubscriptionResponseClear
	#define GET_OpcUaModifySubscriptionResponseClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaModifySubscriptionResponseClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaModifySubscriptionResponseClear  FALSE
	#define EXP_OpcUaModifySubscriptionResponseClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaModifySubscriptionResponseClear
	#define EXT_OpcUaModifySubscriptionResponseClear
	#define GET_OpcUaModifySubscriptionResponseClear(fl)  CAL_CMGETAPI( "OpcUaModifySubscriptionResponseClear" ) 
	#define CAL_OpcUaModifySubscriptionResponseClear  OpcUaModifySubscriptionResponseClear
	#define CHK_OpcUaModifySubscriptionResponseClear  TRUE
	#define EXP_OpcUaModifySubscriptionResponseClear  CAL_CMEXPAPI( "OpcUaModifySubscriptionResponseClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaModifySubscriptionResponseClear
	#define EXT_OpcUaModifySubscriptionResponseClear
	#define GET_OpcUaModifySubscriptionResponseClear(fl)  CAL_CMGETAPI( "OpcUaModifySubscriptionResponseClear" ) 
	#define CAL_OpcUaModifySubscriptionResponseClear  OpcUaModifySubscriptionResponseClear
	#define CHK_OpcUaModifySubscriptionResponseClear  TRUE
	#define EXP_OpcUaModifySubscriptionResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaModifySubscriptionResponseClear", (RTS_UINTPTR)OpcUaModifySubscriptionResponseClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaModifySubscriptionResponseClear
	#define EXT_CmpOPCUAStackOpcUaModifySubscriptionResponseClear
	#define GET_CmpOPCUAStackOpcUaModifySubscriptionResponseClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaModifySubscriptionResponseClear pICmpOPCUAStack->IOpcUaModifySubscriptionResponseClear
	#define CHK_CmpOPCUAStackOpcUaModifySubscriptionResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaModifySubscriptionResponseClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaModifySubscriptionResponseClear
	#define EXT_OpcUaModifySubscriptionResponseClear
	#define GET_OpcUaModifySubscriptionResponseClear(fl)  CAL_CMGETAPI( "OpcUaModifySubscriptionResponseClear" ) 
	#define CAL_OpcUaModifySubscriptionResponseClear pICmpOPCUAStack->IOpcUaModifySubscriptionResponseClear
	#define CHK_OpcUaModifySubscriptionResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaModifySubscriptionResponseClear  CAL_CMEXPAPI( "OpcUaModifySubscriptionResponseClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaModifySubscriptionResponseClear  PFOPCUAMODIFYSUBSCRIPTIONRESPONSECLEAR pfOpcUaModifySubscriptionResponseClear;
	#define EXT_OpcUaModifySubscriptionResponseClear  extern PFOPCUAMODIFYSUBSCRIPTIONRESPONSECLEAR pfOpcUaModifySubscriptionResponseClear;
	#define GET_OpcUaModifySubscriptionResponseClear(fl)  s_pfCMGetAPI2( "OpcUaModifySubscriptionResponseClear", (RTS_VOID_FCTPTR *)&pfOpcUaModifySubscriptionResponseClear, (fl), 0, 0)
	#define CAL_OpcUaModifySubscriptionResponseClear  pfOpcUaModifySubscriptionResponseClear
	#define CHK_OpcUaModifySubscriptionResponseClear  (pfOpcUaModifySubscriptionResponseClear != NULL)
	#define EXP_OpcUaModifySubscriptionResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaModifySubscriptionResponseClear", (RTS_UINTPTR)OpcUaModifySubscriptionResponseClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaRepublishResponseInitialize(OpcUa_RepublishResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAREPUBLISHRESPONSEINITIALIZE) (OpcUa_RepublishResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAREPUBLISHRESPONSEINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaRepublishResponseInitialize
	#define EXT_OpcUaRepublishResponseInitialize
	#define GET_OpcUaRepublishResponseInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaRepublishResponseInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaRepublishResponseInitialize  FALSE
	#define EXP_OpcUaRepublishResponseInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaRepublishResponseInitialize
	#define EXT_OpcUaRepublishResponseInitialize
	#define GET_OpcUaRepublishResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaRepublishResponseInitialize" ) 
	#define CAL_OpcUaRepublishResponseInitialize  OpcUaRepublishResponseInitialize
	#define CHK_OpcUaRepublishResponseInitialize  TRUE
	#define EXP_OpcUaRepublishResponseInitialize  CAL_CMEXPAPI( "OpcUaRepublishResponseInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaRepublishResponseInitialize
	#define EXT_OpcUaRepublishResponseInitialize
	#define GET_OpcUaRepublishResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaRepublishResponseInitialize" ) 
	#define CAL_OpcUaRepublishResponseInitialize  OpcUaRepublishResponseInitialize
	#define CHK_OpcUaRepublishResponseInitialize  TRUE
	#define EXP_OpcUaRepublishResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaRepublishResponseInitialize", (RTS_UINTPTR)OpcUaRepublishResponseInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaRepublishResponseInitialize
	#define EXT_CmpOPCUAStackOpcUaRepublishResponseInitialize
	#define GET_CmpOPCUAStackOpcUaRepublishResponseInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaRepublishResponseInitialize pICmpOPCUAStack->IOpcUaRepublishResponseInitialize
	#define CHK_CmpOPCUAStackOpcUaRepublishResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaRepublishResponseInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaRepublishResponseInitialize
	#define EXT_OpcUaRepublishResponseInitialize
	#define GET_OpcUaRepublishResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaRepublishResponseInitialize" ) 
	#define CAL_OpcUaRepublishResponseInitialize pICmpOPCUAStack->IOpcUaRepublishResponseInitialize
	#define CHK_OpcUaRepublishResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaRepublishResponseInitialize  CAL_CMEXPAPI( "OpcUaRepublishResponseInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaRepublishResponseInitialize  PFOPCUAREPUBLISHRESPONSEINITIALIZE pfOpcUaRepublishResponseInitialize;
	#define EXT_OpcUaRepublishResponseInitialize  extern PFOPCUAREPUBLISHRESPONSEINITIALIZE pfOpcUaRepublishResponseInitialize;
	#define GET_OpcUaRepublishResponseInitialize(fl)  s_pfCMGetAPI2( "OpcUaRepublishResponseInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaRepublishResponseInitialize, (fl), 0, 0)
	#define CAL_OpcUaRepublishResponseInitialize  pfOpcUaRepublishResponseInitialize
	#define CHK_OpcUaRepublishResponseInitialize  (pfOpcUaRepublishResponseInitialize != NULL)
	#define EXP_OpcUaRepublishResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaRepublishResponseInitialize", (RTS_UINTPTR)OpcUaRepublishResponseInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaRepublishResponseClear(OpcUa_RepublishResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAREPUBLISHRESPONSECLEAR) (OpcUa_RepublishResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAREPUBLISHRESPONSECLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaRepublishResponseClear
	#define EXT_OpcUaRepublishResponseClear
	#define GET_OpcUaRepublishResponseClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaRepublishResponseClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaRepublishResponseClear  FALSE
	#define EXP_OpcUaRepublishResponseClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaRepublishResponseClear
	#define EXT_OpcUaRepublishResponseClear
	#define GET_OpcUaRepublishResponseClear(fl)  CAL_CMGETAPI( "OpcUaRepublishResponseClear" ) 
	#define CAL_OpcUaRepublishResponseClear  OpcUaRepublishResponseClear
	#define CHK_OpcUaRepublishResponseClear  TRUE
	#define EXP_OpcUaRepublishResponseClear  CAL_CMEXPAPI( "OpcUaRepublishResponseClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaRepublishResponseClear
	#define EXT_OpcUaRepublishResponseClear
	#define GET_OpcUaRepublishResponseClear(fl)  CAL_CMGETAPI( "OpcUaRepublishResponseClear" ) 
	#define CAL_OpcUaRepublishResponseClear  OpcUaRepublishResponseClear
	#define CHK_OpcUaRepublishResponseClear  TRUE
	#define EXP_OpcUaRepublishResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaRepublishResponseClear", (RTS_UINTPTR)OpcUaRepublishResponseClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaRepublishResponseClear
	#define EXT_CmpOPCUAStackOpcUaRepublishResponseClear
	#define GET_CmpOPCUAStackOpcUaRepublishResponseClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaRepublishResponseClear pICmpOPCUAStack->IOpcUaRepublishResponseClear
	#define CHK_CmpOPCUAStackOpcUaRepublishResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaRepublishResponseClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaRepublishResponseClear
	#define EXT_OpcUaRepublishResponseClear
	#define GET_OpcUaRepublishResponseClear(fl)  CAL_CMGETAPI( "OpcUaRepublishResponseClear" ) 
	#define CAL_OpcUaRepublishResponseClear pICmpOPCUAStack->IOpcUaRepublishResponseClear
	#define CHK_OpcUaRepublishResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaRepublishResponseClear  CAL_CMEXPAPI( "OpcUaRepublishResponseClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaRepublishResponseClear  PFOPCUAREPUBLISHRESPONSECLEAR pfOpcUaRepublishResponseClear;
	#define EXT_OpcUaRepublishResponseClear  extern PFOPCUAREPUBLISHRESPONSECLEAR pfOpcUaRepublishResponseClear;
	#define GET_OpcUaRepublishResponseClear(fl)  s_pfCMGetAPI2( "OpcUaRepublishResponseClear", (RTS_VOID_FCTPTR *)&pfOpcUaRepublishResponseClear, (fl), 0, 0)
	#define CAL_OpcUaRepublishResponseClear  pfOpcUaRepublishResponseClear
	#define CHK_OpcUaRepublishResponseClear  (pfOpcUaRepublishResponseClear != NULL)
	#define EXP_OpcUaRepublishResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaRepublishResponseClear", (RTS_UINTPTR)OpcUaRepublishResponseClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaSetPublishingModeResponseInitialize(OpcUa_SetPublishingModeResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUASETPUBLISHINGMODERESPONSEINITIALIZE) (OpcUa_SetPublishingModeResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASETPUBLISHINGMODERESPONSEINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaSetPublishingModeResponseInitialize
	#define EXT_OpcUaSetPublishingModeResponseInitialize
	#define GET_OpcUaSetPublishingModeResponseInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaSetPublishingModeResponseInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaSetPublishingModeResponseInitialize  FALSE
	#define EXP_OpcUaSetPublishingModeResponseInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaSetPublishingModeResponseInitialize
	#define EXT_OpcUaSetPublishingModeResponseInitialize
	#define GET_OpcUaSetPublishingModeResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaSetPublishingModeResponseInitialize" ) 
	#define CAL_OpcUaSetPublishingModeResponseInitialize  OpcUaSetPublishingModeResponseInitialize
	#define CHK_OpcUaSetPublishingModeResponseInitialize  TRUE
	#define EXP_OpcUaSetPublishingModeResponseInitialize  CAL_CMEXPAPI( "OpcUaSetPublishingModeResponseInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaSetPublishingModeResponseInitialize
	#define EXT_OpcUaSetPublishingModeResponseInitialize
	#define GET_OpcUaSetPublishingModeResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaSetPublishingModeResponseInitialize" ) 
	#define CAL_OpcUaSetPublishingModeResponseInitialize  OpcUaSetPublishingModeResponseInitialize
	#define CHK_OpcUaSetPublishingModeResponseInitialize  TRUE
	#define EXP_OpcUaSetPublishingModeResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSetPublishingModeResponseInitialize", (RTS_UINTPTR)OpcUaSetPublishingModeResponseInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaSetPublishingModeResponseInitialize
	#define EXT_CmpOPCUAStackOpcUaSetPublishingModeResponseInitialize
	#define GET_CmpOPCUAStackOpcUaSetPublishingModeResponseInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaSetPublishingModeResponseInitialize pICmpOPCUAStack->IOpcUaSetPublishingModeResponseInitialize
	#define CHK_CmpOPCUAStackOpcUaSetPublishingModeResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaSetPublishingModeResponseInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaSetPublishingModeResponseInitialize
	#define EXT_OpcUaSetPublishingModeResponseInitialize
	#define GET_OpcUaSetPublishingModeResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaSetPublishingModeResponseInitialize" ) 
	#define CAL_OpcUaSetPublishingModeResponseInitialize pICmpOPCUAStack->IOpcUaSetPublishingModeResponseInitialize
	#define CHK_OpcUaSetPublishingModeResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaSetPublishingModeResponseInitialize  CAL_CMEXPAPI( "OpcUaSetPublishingModeResponseInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaSetPublishingModeResponseInitialize  PFOPCUASETPUBLISHINGMODERESPONSEINITIALIZE pfOpcUaSetPublishingModeResponseInitialize;
	#define EXT_OpcUaSetPublishingModeResponseInitialize  extern PFOPCUASETPUBLISHINGMODERESPONSEINITIALIZE pfOpcUaSetPublishingModeResponseInitialize;
	#define GET_OpcUaSetPublishingModeResponseInitialize(fl)  s_pfCMGetAPI2( "OpcUaSetPublishingModeResponseInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaSetPublishingModeResponseInitialize, (fl), 0, 0)
	#define CAL_OpcUaSetPublishingModeResponseInitialize  pfOpcUaSetPublishingModeResponseInitialize
	#define CHK_OpcUaSetPublishingModeResponseInitialize  (pfOpcUaSetPublishingModeResponseInitialize != NULL)
	#define EXP_OpcUaSetPublishingModeResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSetPublishingModeResponseInitialize", (RTS_UINTPTR)OpcUaSetPublishingModeResponseInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaSetPublishingModeResponseClear(OpcUa_SetPublishingModeResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUASETPUBLISHINGMODERESPONSECLEAR) (OpcUa_SetPublishingModeResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASETPUBLISHINGMODERESPONSECLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaSetPublishingModeResponseClear
	#define EXT_OpcUaSetPublishingModeResponseClear
	#define GET_OpcUaSetPublishingModeResponseClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaSetPublishingModeResponseClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaSetPublishingModeResponseClear  FALSE
	#define EXP_OpcUaSetPublishingModeResponseClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaSetPublishingModeResponseClear
	#define EXT_OpcUaSetPublishingModeResponseClear
	#define GET_OpcUaSetPublishingModeResponseClear(fl)  CAL_CMGETAPI( "OpcUaSetPublishingModeResponseClear" ) 
	#define CAL_OpcUaSetPublishingModeResponseClear  OpcUaSetPublishingModeResponseClear
	#define CHK_OpcUaSetPublishingModeResponseClear  TRUE
	#define EXP_OpcUaSetPublishingModeResponseClear  CAL_CMEXPAPI( "OpcUaSetPublishingModeResponseClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaSetPublishingModeResponseClear
	#define EXT_OpcUaSetPublishingModeResponseClear
	#define GET_OpcUaSetPublishingModeResponseClear(fl)  CAL_CMGETAPI( "OpcUaSetPublishingModeResponseClear" ) 
	#define CAL_OpcUaSetPublishingModeResponseClear  OpcUaSetPublishingModeResponseClear
	#define CHK_OpcUaSetPublishingModeResponseClear  TRUE
	#define EXP_OpcUaSetPublishingModeResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSetPublishingModeResponseClear", (RTS_UINTPTR)OpcUaSetPublishingModeResponseClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaSetPublishingModeResponseClear
	#define EXT_CmpOPCUAStackOpcUaSetPublishingModeResponseClear
	#define GET_CmpOPCUAStackOpcUaSetPublishingModeResponseClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaSetPublishingModeResponseClear pICmpOPCUAStack->IOpcUaSetPublishingModeResponseClear
	#define CHK_CmpOPCUAStackOpcUaSetPublishingModeResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaSetPublishingModeResponseClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaSetPublishingModeResponseClear
	#define EXT_OpcUaSetPublishingModeResponseClear
	#define GET_OpcUaSetPublishingModeResponseClear(fl)  CAL_CMGETAPI( "OpcUaSetPublishingModeResponseClear" ) 
	#define CAL_OpcUaSetPublishingModeResponseClear pICmpOPCUAStack->IOpcUaSetPublishingModeResponseClear
	#define CHK_OpcUaSetPublishingModeResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaSetPublishingModeResponseClear  CAL_CMEXPAPI( "OpcUaSetPublishingModeResponseClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaSetPublishingModeResponseClear  PFOPCUASETPUBLISHINGMODERESPONSECLEAR pfOpcUaSetPublishingModeResponseClear;
	#define EXT_OpcUaSetPublishingModeResponseClear  extern PFOPCUASETPUBLISHINGMODERESPONSECLEAR pfOpcUaSetPublishingModeResponseClear;
	#define GET_OpcUaSetPublishingModeResponseClear(fl)  s_pfCMGetAPI2( "OpcUaSetPublishingModeResponseClear", (RTS_VOID_FCTPTR *)&pfOpcUaSetPublishingModeResponseClear, (fl), 0, 0)
	#define CAL_OpcUaSetPublishingModeResponseClear  pfOpcUaSetPublishingModeResponseClear
	#define CHK_OpcUaSetPublishingModeResponseClear  (pfOpcUaSetPublishingModeResponseClear != NULL)
	#define EXP_OpcUaSetPublishingModeResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSetPublishingModeResponseClear", (RTS_UINTPTR)OpcUaSetPublishingModeResponseClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaDeleteSubscriptionsResponseInitialize(OpcUa_DeleteSubscriptionsResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUADELETESUBSCRIPTIONSRESPONSEINITIALIZE) (OpcUa_DeleteSubscriptionsResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUADELETESUBSCRIPTIONSRESPONSEINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaDeleteSubscriptionsResponseInitialize
	#define EXT_OpcUaDeleteSubscriptionsResponseInitialize
	#define GET_OpcUaDeleteSubscriptionsResponseInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaDeleteSubscriptionsResponseInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaDeleteSubscriptionsResponseInitialize  FALSE
	#define EXP_OpcUaDeleteSubscriptionsResponseInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaDeleteSubscriptionsResponseInitialize
	#define EXT_OpcUaDeleteSubscriptionsResponseInitialize
	#define GET_OpcUaDeleteSubscriptionsResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaDeleteSubscriptionsResponseInitialize" ) 
	#define CAL_OpcUaDeleteSubscriptionsResponseInitialize  OpcUaDeleteSubscriptionsResponseInitialize
	#define CHK_OpcUaDeleteSubscriptionsResponseInitialize  TRUE
	#define EXP_OpcUaDeleteSubscriptionsResponseInitialize  CAL_CMEXPAPI( "OpcUaDeleteSubscriptionsResponseInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaDeleteSubscriptionsResponseInitialize
	#define EXT_OpcUaDeleteSubscriptionsResponseInitialize
	#define GET_OpcUaDeleteSubscriptionsResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaDeleteSubscriptionsResponseInitialize" ) 
	#define CAL_OpcUaDeleteSubscriptionsResponseInitialize  OpcUaDeleteSubscriptionsResponseInitialize
	#define CHK_OpcUaDeleteSubscriptionsResponseInitialize  TRUE
	#define EXP_OpcUaDeleteSubscriptionsResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDeleteSubscriptionsResponseInitialize", (RTS_UINTPTR)OpcUaDeleteSubscriptionsResponseInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaDeleteSubscriptionsResponseInitialize
	#define EXT_CmpOPCUAStackOpcUaDeleteSubscriptionsResponseInitialize
	#define GET_CmpOPCUAStackOpcUaDeleteSubscriptionsResponseInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaDeleteSubscriptionsResponseInitialize pICmpOPCUAStack->IOpcUaDeleteSubscriptionsResponseInitialize
	#define CHK_CmpOPCUAStackOpcUaDeleteSubscriptionsResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaDeleteSubscriptionsResponseInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaDeleteSubscriptionsResponseInitialize
	#define EXT_OpcUaDeleteSubscriptionsResponseInitialize
	#define GET_OpcUaDeleteSubscriptionsResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaDeleteSubscriptionsResponseInitialize" ) 
	#define CAL_OpcUaDeleteSubscriptionsResponseInitialize pICmpOPCUAStack->IOpcUaDeleteSubscriptionsResponseInitialize
	#define CHK_OpcUaDeleteSubscriptionsResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaDeleteSubscriptionsResponseInitialize  CAL_CMEXPAPI( "OpcUaDeleteSubscriptionsResponseInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaDeleteSubscriptionsResponseInitialize  PFOPCUADELETESUBSCRIPTIONSRESPONSEINITIALIZE pfOpcUaDeleteSubscriptionsResponseInitialize;
	#define EXT_OpcUaDeleteSubscriptionsResponseInitialize  extern PFOPCUADELETESUBSCRIPTIONSRESPONSEINITIALIZE pfOpcUaDeleteSubscriptionsResponseInitialize;
	#define GET_OpcUaDeleteSubscriptionsResponseInitialize(fl)  s_pfCMGetAPI2( "OpcUaDeleteSubscriptionsResponseInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaDeleteSubscriptionsResponseInitialize, (fl), 0, 0)
	#define CAL_OpcUaDeleteSubscriptionsResponseInitialize  pfOpcUaDeleteSubscriptionsResponseInitialize
	#define CHK_OpcUaDeleteSubscriptionsResponseInitialize  (pfOpcUaDeleteSubscriptionsResponseInitialize != NULL)
	#define EXP_OpcUaDeleteSubscriptionsResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDeleteSubscriptionsResponseInitialize", (RTS_UINTPTR)OpcUaDeleteSubscriptionsResponseInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaDeleteSubscriptionsResponseClear(OpcUa_DeleteSubscriptionsResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUADELETESUBSCRIPTIONSRESPONSECLEAR) (OpcUa_DeleteSubscriptionsResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUADELETESUBSCRIPTIONSRESPONSECLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaDeleteSubscriptionsResponseClear
	#define EXT_OpcUaDeleteSubscriptionsResponseClear
	#define GET_OpcUaDeleteSubscriptionsResponseClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaDeleteSubscriptionsResponseClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaDeleteSubscriptionsResponseClear  FALSE
	#define EXP_OpcUaDeleteSubscriptionsResponseClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaDeleteSubscriptionsResponseClear
	#define EXT_OpcUaDeleteSubscriptionsResponseClear
	#define GET_OpcUaDeleteSubscriptionsResponseClear(fl)  CAL_CMGETAPI( "OpcUaDeleteSubscriptionsResponseClear" ) 
	#define CAL_OpcUaDeleteSubscriptionsResponseClear  OpcUaDeleteSubscriptionsResponseClear
	#define CHK_OpcUaDeleteSubscriptionsResponseClear  TRUE
	#define EXP_OpcUaDeleteSubscriptionsResponseClear  CAL_CMEXPAPI( "OpcUaDeleteSubscriptionsResponseClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaDeleteSubscriptionsResponseClear
	#define EXT_OpcUaDeleteSubscriptionsResponseClear
	#define GET_OpcUaDeleteSubscriptionsResponseClear(fl)  CAL_CMGETAPI( "OpcUaDeleteSubscriptionsResponseClear" ) 
	#define CAL_OpcUaDeleteSubscriptionsResponseClear  OpcUaDeleteSubscriptionsResponseClear
	#define CHK_OpcUaDeleteSubscriptionsResponseClear  TRUE
	#define EXP_OpcUaDeleteSubscriptionsResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDeleteSubscriptionsResponseClear", (RTS_UINTPTR)OpcUaDeleteSubscriptionsResponseClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaDeleteSubscriptionsResponseClear
	#define EXT_CmpOPCUAStackOpcUaDeleteSubscriptionsResponseClear
	#define GET_CmpOPCUAStackOpcUaDeleteSubscriptionsResponseClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaDeleteSubscriptionsResponseClear pICmpOPCUAStack->IOpcUaDeleteSubscriptionsResponseClear
	#define CHK_CmpOPCUAStackOpcUaDeleteSubscriptionsResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaDeleteSubscriptionsResponseClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaDeleteSubscriptionsResponseClear
	#define EXT_OpcUaDeleteSubscriptionsResponseClear
	#define GET_OpcUaDeleteSubscriptionsResponseClear(fl)  CAL_CMGETAPI( "OpcUaDeleteSubscriptionsResponseClear" ) 
	#define CAL_OpcUaDeleteSubscriptionsResponseClear pICmpOPCUAStack->IOpcUaDeleteSubscriptionsResponseClear
	#define CHK_OpcUaDeleteSubscriptionsResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaDeleteSubscriptionsResponseClear  CAL_CMEXPAPI( "OpcUaDeleteSubscriptionsResponseClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaDeleteSubscriptionsResponseClear  PFOPCUADELETESUBSCRIPTIONSRESPONSECLEAR pfOpcUaDeleteSubscriptionsResponseClear;
	#define EXT_OpcUaDeleteSubscriptionsResponseClear  extern PFOPCUADELETESUBSCRIPTIONSRESPONSECLEAR pfOpcUaDeleteSubscriptionsResponseClear;
	#define GET_OpcUaDeleteSubscriptionsResponseClear(fl)  s_pfCMGetAPI2( "OpcUaDeleteSubscriptionsResponseClear", (RTS_VOID_FCTPTR *)&pfOpcUaDeleteSubscriptionsResponseClear, (fl), 0, 0)
	#define CAL_OpcUaDeleteSubscriptionsResponseClear  pfOpcUaDeleteSubscriptionsResponseClear
	#define CHK_OpcUaDeleteSubscriptionsResponseClear  (pfOpcUaDeleteSubscriptionsResponseClear != NULL)
	#define EXP_OpcUaDeleteSubscriptionsResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDeleteSubscriptionsResponseClear", (RTS_UINTPTR)OpcUaDeleteSubscriptionsResponseClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaTransferSubscriptionsResponseInitialize(OpcUa_TransferSubscriptionsResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUATRANSFERSUBSCRIPTIONSRESPONSEINITIALIZE) (OpcUa_TransferSubscriptionsResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUATRANSFERSUBSCRIPTIONSRESPONSEINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaTransferSubscriptionsResponseInitialize
	#define EXT_OpcUaTransferSubscriptionsResponseInitialize
	#define GET_OpcUaTransferSubscriptionsResponseInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaTransferSubscriptionsResponseInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaTransferSubscriptionsResponseInitialize  FALSE
	#define EXP_OpcUaTransferSubscriptionsResponseInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaTransferSubscriptionsResponseInitialize
	#define EXT_OpcUaTransferSubscriptionsResponseInitialize
	#define GET_OpcUaTransferSubscriptionsResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaTransferSubscriptionsResponseInitialize" ) 
	#define CAL_OpcUaTransferSubscriptionsResponseInitialize  OpcUaTransferSubscriptionsResponseInitialize
	#define CHK_OpcUaTransferSubscriptionsResponseInitialize  TRUE
	#define EXP_OpcUaTransferSubscriptionsResponseInitialize  CAL_CMEXPAPI( "OpcUaTransferSubscriptionsResponseInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaTransferSubscriptionsResponseInitialize
	#define EXT_OpcUaTransferSubscriptionsResponseInitialize
	#define GET_OpcUaTransferSubscriptionsResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaTransferSubscriptionsResponseInitialize" ) 
	#define CAL_OpcUaTransferSubscriptionsResponseInitialize  OpcUaTransferSubscriptionsResponseInitialize
	#define CHK_OpcUaTransferSubscriptionsResponseInitialize  TRUE
	#define EXP_OpcUaTransferSubscriptionsResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaTransferSubscriptionsResponseInitialize", (RTS_UINTPTR)OpcUaTransferSubscriptionsResponseInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaTransferSubscriptionsResponseInitialize
	#define EXT_CmpOPCUAStackOpcUaTransferSubscriptionsResponseInitialize
	#define GET_CmpOPCUAStackOpcUaTransferSubscriptionsResponseInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaTransferSubscriptionsResponseInitialize pICmpOPCUAStack->IOpcUaTransferSubscriptionsResponseInitialize
	#define CHK_CmpOPCUAStackOpcUaTransferSubscriptionsResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaTransferSubscriptionsResponseInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaTransferSubscriptionsResponseInitialize
	#define EXT_OpcUaTransferSubscriptionsResponseInitialize
	#define GET_OpcUaTransferSubscriptionsResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaTransferSubscriptionsResponseInitialize" ) 
	#define CAL_OpcUaTransferSubscriptionsResponseInitialize pICmpOPCUAStack->IOpcUaTransferSubscriptionsResponseInitialize
	#define CHK_OpcUaTransferSubscriptionsResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaTransferSubscriptionsResponseInitialize  CAL_CMEXPAPI( "OpcUaTransferSubscriptionsResponseInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaTransferSubscriptionsResponseInitialize  PFOPCUATRANSFERSUBSCRIPTIONSRESPONSEINITIALIZE pfOpcUaTransferSubscriptionsResponseInitialize;
	#define EXT_OpcUaTransferSubscriptionsResponseInitialize  extern PFOPCUATRANSFERSUBSCRIPTIONSRESPONSEINITIALIZE pfOpcUaTransferSubscriptionsResponseInitialize;
	#define GET_OpcUaTransferSubscriptionsResponseInitialize(fl)  s_pfCMGetAPI2( "OpcUaTransferSubscriptionsResponseInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaTransferSubscriptionsResponseInitialize, (fl), 0, 0)
	#define CAL_OpcUaTransferSubscriptionsResponseInitialize  pfOpcUaTransferSubscriptionsResponseInitialize
	#define CHK_OpcUaTransferSubscriptionsResponseInitialize  (pfOpcUaTransferSubscriptionsResponseInitialize != NULL)
	#define EXP_OpcUaTransferSubscriptionsResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaTransferSubscriptionsResponseInitialize", (RTS_UINTPTR)OpcUaTransferSubscriptionsResponseInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaTransferSubscriptionsResponseClear(OpcUa_TransferSubscriptionsResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUATRANSFERSUBSCRIPTIONSRESPONSECLEAR) (OpcUa_TransferSubscriptionsResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUATRANSFERSUBSCRIPTIONSRESPONSECLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaTransferSubscriptionsResponseClear
	#define EXT_OpcUaTransferSubscriptionsResponseClear
	#define GET_OpcUaTransferSubscriptionsResponseClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaTransferSubscriptionsResponseClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaTransferSubscriptionsResponseClear  FALSE
	#define EXP_OpcUaTransferSubscriptionsResponseClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaTransferSubscriptionsResponseClear
	#define EXT_OpcUaTransferSubscriptionsResponseClear
	#define GET_OpcUaTransferSubscriptionsResponseClear(fl)  CAL_CMGETAPI( "OpcUaTransferSubscriptionsResponseClear" ) 
	#define CAL_OpcUaTransferSubscriptionsResponseClear  OpcUaTransferSubscriptionsResponseClear
	#define CHK_OpcUaTransferSubscriptionsResponseClear  TRUE
	#define EXP_OpcUaTransferSubscriptionsResponseClear  CAL_CMEXPAPI( "OpcUaTransferSubscriptionsResponseClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaTransferSubscriptionsResponseClear
	#define EXT_OpcUaTransferSubscriptionsResponseClear
	#define GET_OpcUaTransferSubscriptionsResponseClear(fl)  CAL_CMGETAPI( "OpcUaTransferSubscriptionsResponseClear" ) 
	#define CAL_OpcUaTransferSubscriptionsResponseClear  OpcUaTransferSubscriptionsResponseClear
	#define CHK_OpcUaTransferSubscriptionsResponseClear  TRUE
	#define EXP_OpcUaTransferSubscriptionsResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaTransferSubscriptionsResponseClear", (RTS_UINTPTR)OpcUaTransferSubscriptionsResponseClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaTransferSubscriptionsResponseClear
	#define EXT_CmpOPCUAStackOpcUaTransferSubscriptionsResponseClear
	#define GET_CmpOPCUAStackOpcUaTransferSubscriptionsResponseClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaTransferSubscriptionsResponseClear pICmpOPCUAStack->IOpcUaTransferSubscriptionsResponseClear
	#define CHK_CmpOPCUAStackOpcUaTransferSubscriptionsResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaTransferSubscriptionsResponseClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaTransferSubscriptionsResponseClear
	#define EXT_OpcUaTransferSubscriptionsResponseClear
	#define GET_OpcUaTransferSubscriptionsResponseClear(fl)  CAL_CMGETAPI( "OpcUaTransferSubscriptionsResponseClear" ) 
	#define CAL_OpcUaTransferSubscriptionsResponseClear pICmpOPCUAStack->IOpcUaTransferSubscriptionsResponseClear
	#define CHK_OpcUaTransferSubscriptionsResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaTransferSubscriptionsResponseClear  CAL_CMEXPAPI( "OpcUaTransferSubscriptionsResponseClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaTransferSubscriptionsResponseClear  PFOPCUATRANSFERSUBSCRIPTIONSRESPONSECLEAR pfOpcUaTransferSubscriptionsResponseClear;
	#define EXT_OpcUaTransferSubscriptionsResponseClear  extern PFOPCUATRANSFERSUBSCRIPTIONSRESPONSECLEAR pfOpcUaTransferSubscriptionsResponseClear;
	#define GET_OpcUaTransferSubscriptionsResponseClear(fl)  s_pfCMGetAPI2( "OpcUaTransferSubscriptionsResponseClear", (RTS_VOID_FCTPTR *)&pfOpcUaTransferSubscriptionsResponseClear, (fl), 0, 0)
	#define CAL_OpcUaTransferSubscriptionsResponseClear  pfOpcUaTransferSubscriptionsResponseClear
	#define CHK_OpcUaTransferSubscriptionsResponseClear  (pfOpcUaTransferSubscriptionsResponseClear != NULL)
	#define EXP_OpcUaTransferSubscriptionsResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaTransferSubscriptionsResponseClear", (RTS_UINTPTR)OpcUaTransferSubscriptionsResponseClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaCreateMonitoredItemsRequestInitialize(OpcUa_CreateMonitoredItemsRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUACREATEMONITOREDITEMSREQUESTINITIALIZE) (OpcUa_CreateMonitoredItemsRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACREATEMONITOREDITEMSREQUESTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaCreateMonitoredItemsRequestInitialize
	#define EXT_OpcUaCreateMonitoredItemsRequestInitialize
	#define GET_OpcUaCreateMonitoredItemsRequestInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaCreateMonitoredItemsRequestInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaCreateMonitoredItemsRequestInitialize  FALSE
	#define EXP_OpcUaCreateMonitoredItemsRequestInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaCreateMonitoredItemsRequestInitialize
	#define EXT_OpcUaCreateMonitoredItemsRequestInitialize
	#define GET_OpcUaCreateMonitoredItemsRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaCreateMonitoredItemsRequestInitialize" ) 
	#define CAL_OpcUaCreateMonitoredItemsRequestInitialize  OpcUaCreateMonitoredItemsRequestInitialize
	#define CHK_OpcUaCreateMonitoredItemsRequestInitialize  TRUE
	#define EXP_OpcUaCreateMonitoredItemsRequestInitialize  CAL_CMEXPAPI( "OpcUaCreateMonitoredItemsRequestInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaCreateMonitoredItemsRequestInitialize
	#define EXT_OpcUaCreateMonitoredItemsRequestInitialize
	#define GET_OpcUaCreateMonitoredItemsRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaCreateMonitoredItemsRequestInitialize" ) 
	#define CAL_OpcUaCreateMonitoredItemsRequestInitialize  OpcUaCreateMonitoredItemsRequestInitialize
	#define CHK_OpcUaCreateMonitoredItemsRequestInitialize  TRUE
	#define EXP_OpcUaCreateMonitoredItemsRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCreateMonitoredItemsRequestInitialize", (RTS_UINTPTR)OpcUaCreateMonitoredItemsRequestInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaCreateMonitoredItemsRequestInitialize
	#define EXT_CmpOPCUAStackOpcUaCreateMonitoredItemsRequestInitialize
	#define GET_CmpOPCUAStackOpcUaCreateMonitoredItemsRequestInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaCreateMonitoredItemsRequestInitialize pICmpOPCUAStack->IOpcUaCreateMonitoredItemsRequestInitialize
	#define CHK_CmpOPCUAStackOpcUaCreateMonitoredItemsRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaCreateMonitoredItemsRequestInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaCreateMonitoredItemsRequestInitialize
	#define EXT_OpcUaCreateMonitoredItemsRequestInitialize
	#define GET_OpcUaCreateMonitoredItemsRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaCreateMonitoredItemsRequestInitialize" ) 
	#define CAL_OpcUaCreateMonitoredItemsRequestInitialize pICmpOPCUAStack->IOpcUaCreateMonitoredItemsRequestInitialize
	#define CHK_OpcUaCreateMonitoredItemsRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaCreateMonitoredItemsRequestInitialize  CAL_CMEXPAPI( "OpcUaCreateMonitoredItemsRequestInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaCreateMonitoredItemsRequestInitialize  PFOPCUACREATEMONITOREDITEMSREQUESTINITIALIZE pfOpcUaCreateMonitoredItemsRequestInitialize;
	#define EXT_OpcUaCreateMonitoredItemsRequestInitialize  extern PFOPCUACREATEMONITOREDITEMSREQUESTINITIALIZE pfOpcUaCreateMonitoredItemsRequestInitialize;
	#define GET_OpcUaCreateMonitoredItemsRequestInitialize(fl)  s_pfCMGetAPI2( "OpcUaCreateMonitoredItemsRequestInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaCreateMonitoredItemsRequestInitialize, (fl), 0, 0)
	#define CAL_OpcUaCreateMonitoredItemsRequestInitialize  pfOpcUaCreateMonitoredItemsRequestInitialize
	#define CHK_OpcUaCreateMonitoredItemsRequestInitialize  (pfOpcUaCreateMonitoredItemsRequestInitialize != NULL)
	#define EXP_OpcUaCreateMonitoredItemsRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCreateMonitoredItemsRequestInitialize", (RTS_UINTPTR)OpcUaCreateMonitoredItemsRequestInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaCreateMonitoredItemsRequestClear(OpcUa_CreateMonitoredItemsRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUACREATEMONITOREDITEMSREQUESTCLEAR) (OpcUa_CreateMonitoredItemsRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACREATEMONITOREDITEMSREQUESTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaCreateMonitoredItemsRequestClear
	#define EXT_OpcUaCreateMonitoredItemsRequestClear
	#define GET_OpcUaCreateMonitoredItemsRequestClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaCreateMonitoredItemsRequestClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaCreateMonitoredItemsRequestClear  FALSE
	#define EXP_OpcUaCreateMonitoredItemsRequestClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaCreateMonitoredItemsRequestClear
	#define EXT_OpcUaCreateMonitoredItemsRequestClear
	#define GET_OpcUaCreateMonitoredItemsRequestClear(fl)  CAL_CMGETAPI( "OpcUaCreateMonitoredItemsRequestClear" ) 
	#define CAL_OpcUaCreateMonitoredItemsRequestClear  OpcUaCreateMonitoredItemsRequestClear
	#define CHK_OpcUaCreateMonitoredItemsRequestClear  TRUE
	#define EXP_OpcUaCreateMonitoredItemsRequestClear  CAL_CMEXPAPI( "OpcUaCreateMonitoredItemsRequestClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaCreateMonitoredItemsRequestClear
	#define EXT_OpcUaCreateMonitoredItemsRequestClear
	#define GET_OpcUaCreateMonitoredItemsRequestClear(fl)  CAL_CMGETAPI( "OpcUaCreateMonitoredItemsRequestClear" ) 
	#define CAL_OpcUaCreateMonitoredItemsRequestClear  OpcUaCreateMonitoredItemsRequestClear
	#define CHK_OpcUaCreateMonitoredItemsRequestClear  TRUE
	#define EXP_OpcUaCreateMonitoredItemsRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCreateMonitoredItemsRequestClear", (RTS_UINTPTR)OpcUaCreateMonitoredItemsRequestClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaCreateMonitoredItemsRequestClear
	#define EXT_CmpOPCUAStackOpcUaCreateMonitoredItemsRequestClear
	#define GET_CmpOPCUAStackOpcUaCreateMonitoredItemsRequestClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaCreateMonitoredItemsRequestClear pICmpOPCUAStack->IOpcUaCreateMonitoredItemsRequestClear
	#define CHK_CmpOPCUAStackOpcUaCreateMonitoredItemsRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaCreateMonitoredItemsRequestClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaCreateMonitoredItemsRequestClear
	#define EXT_OpcUaCreateMonitoredItemsRequestClear
	#define GET_OpcUaCreateMonitoredItemsRequestClear(fl)  CAL_CMGETAPI( "OpcUaCreateMonitoredItemsRequestClear" ) 
	#define CAL_OpcUaCreateMonitoredItemsRequestClear pICmpOPCUAStack->IOpcUaCreateMonitoredItemsRequestClear
	#define CHK_OpcUaCreateMonitoredItemsRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaCreateMonitoredItemsRequestClear  CAL_CMEXPAPI( "OpcUaCreateMonitoredItemsRequestClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaCreateMonitoredItemsRequestClear  PFOPCUACREATEMONITOREDITEMSREQUESTCLEAR pfOpcUaCreateMonitoredItemsRequestClear;
	#define EXT_OpcUaCreateMonitoredItemsRequestClear  extern PFOPCUACREATEMONITOREDITEMSREQUESTCLEAR pfOpcUaCreateMonitoredItemsRequestClear;
	#define GET_OpcUaCreateMonitoredItemsRequestClear(fl)  s_pfCMGetAPI2( "OpcUaCreateMonitoredItemsRequestClear", (RTS_VOID_FCTPTR *)&pfOpcUaCreateMonitoredItemsRequestClear, (fl), 0, 0)
	#define CAL_OpcUaCreateMonitoredItemsRequestClear  pfOpcUaCreateMonitoredItemsRequestClear
	#define CHK_OpcUaCreateMonitoredItemsRequestClear  (pfOpcUaCreateMonitoredItemsRequestClear != NULL)
	#define EXP_OpcUaCreateMonitoredItemsRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCreateMonitoredItemsRequestClear", (RTS_UINTPTR)OpcUaCreateMonitoredItemsRequestClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaCreateMonitoredItemsResponseInitialize(OpcUa_CreateMonitoredItemsResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUACREATEMONITOREDITEMSRESPONSEINITIALIZE) (OpcUa_CreateMonitoredItemsResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACREATEMONITOREDITEMSRESPONSEINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaCreateMonitoredItemsResponseInitialize
	#define EXT_OpcUaCreateMonitoredItemsResponseInitialize
	#define GET_OpcUaCreateMonitoredItemsResponseInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaCreateMonitoredItemsResponseInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaCreateMonitoredItemsResponseInitialize  FALSE
	#define EXP_OpcUaCreateMonitoredItemsResponseInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaCreateMonitoredItemsResponseInitialize
	#define EXT_OpcUaCreateMonitoredItemsResponseInitialize
	#define GET_OpcUaCreateMonitoredItemsResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaCreateMonitoredItemsResponseInitialize" ) 
	#define CAL_OpcUaCreateMonitoredItemsResponseInitialize  OpcUaCreateMonitoredItemsResponseInitialize
	#define CHK_OpcUaCreateMonitoredItemsResponseInitialize  TRUE
	#define EXP_OpcUaCreateMonitoredItemsResponseInitialize  CAL_CMEXPAPI( "OpcUaCreateMonitoredItemsResponseInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaCreateMonitoredItemsResponseInitialize
	#define EXT_OpcUaCreateMonitoredItemsResponseInitialize
	#define GET_OpcUaCreateMonitoredItemsResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaCreateMonitoredItemsResponseInitialize" ) 
	#define CAL_OpcUaCreateMonitoredItemsResponseInitialize  OpcUaCreateMonitoredItemsResponseInitialize
	#define CHK_OpcUaCreateMonitoredItemsResponseInitialize  TRUE
	#define EXP_OpcUaCreateMonitoredItemsResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCreateMonitoredItemsResponseInitialize", (RTS_UINTPTR)OpcUaCreateMonitoredItemsResponseInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaCreateMonitoredItemsResponseInitialize
	#define EXT_CmpOPCUAStackOpcUaCreateMonitoredItemsResponseInitialize
	#define GET_CmpOPCUAStackOpcUaCreateMonitoredItemsResponseInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaCreateMonitoredItemsResponseInitialize pICmpOPCUAStack->IOpcUaCreateMonitoredItemsResponseInitialize
	#define CHK_CmpOPCUAStackOpcUaCreateMonitoredItemsResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaCreateMonitoredItemsResponseInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaCreateMonitoredItemsResponseInitialize
	#define EXT_OpcUaCreateMonitoredItemsResponseInitialize
	#define GET_OpcUaCreateMonitoredItemsResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaCreateMonitoredItemsResponseInitialize" ) 
	#define CAL_OpcUaCreateMonitoredItemsResponseInitialize pICmpOPCUAStack->IOpcUaCreateMonitoredItemsResponseInitialize
	#define CHK_OpcUaCreateMonitoredItemsResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaCreateMonitoredItemsResponseInitialize  CAL_CMEXPAPI( "OpcUaCreateMonitoredItemsResponseInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaCreateMonitoredItemsResponseInitialize  PFOPCUACREATEMONITOREDITEMSRESPONSEINITIALIZE pfOpcUaCreateMonitoredItemsResponseInitialize;
	#define EXT_OpcUaCreateMonitoredItemsResponseInitialize  extern PFOPCUACREATEMONITOREDITEMSRESPONSEINITIALIZE pfOpcUaCreateMonitoredItemsResponseInitialize;
	#define GET_OpcUaCreateMonitoredItemsResponseInitialize(fl)  s_pfCMGetAPI2( "OpcUaCreateMonitoredItemsResponseInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaCreateMonitoredItemsResponseInitialize, (fl), 0, 0)
	#define CAL_OpcUaCreateMonitoredItemsResponseInitialize  pfOpcUaCreateMonitoredItemsResponseInitialize
	#define CHK_OpcUaCreateMonitoredItemsResponseInitialize  (pfOpcUaCreateMonitoredItemsResponseInitialize != NULL)
	#define EXP_OpcUaCreateMonitoredItemsResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCreateMonitoredItemsResponseInitialize", (RTS_UINTPTR)OpcUaCreateMonitoredItemsResponseInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaCreateMonitoredItemsResponseClear(OpcUa_CreateMonitoredItemsResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUACREATEMONITOREDITEMSRESPONSECLEAR) (OpcUa_CreateMonitoredItemsResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACREATEMONITOREDITEMSRESPONSECLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaCreateMonitoredItemsResponseClear
	#define EXT_OpcUaCreateMonitoredItemsResponseClear
	#define GET_OpcUaCreateMonitoredItemsResponseClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaCreateMonitoredItemsResponseClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaCreateMonitoredItemsResponseClear  FALSE
	#define EXP_OpcUaCreateMonitoredItemsResponseClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaCreateMonitoredItemsResponseClear
	#define EXT_OpcUaCreateMonitoredItemsResponseClear
	#define GET_OpcUaCreateMonitoredItemsResponseClear(fl)  CAL_CMGETAPI( "OpcUaCreateMonitoredItemsResponseClear" ) 
	#define CAL_OpcUaCreateMonitoredItemsResponseClear  OpcUaCreateMonitoredItemsResponseClear
	#define CHK_OpcUaCreateMonitoredItemsResponseClear  TRUE
	#define EXP_OpcUaCreateMonitoredItemsResponseClear  CAL_CMEXPAPI( "OpcUaCreateMonitoredItemsResponseClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaCreateMonitoredItemsResponseClear
	#define EXT_OpcUaCreateMonitoredItemsResponseClear
	#define GET_OpcUaCreateMonitoredItemsResponseClear(fl)  CAL_CMGETAPI( "OpcUaCreateMonitoredItemsResponseClear" ) 
	#define CAL_OpcUaCreateMonitoredItemsResponseClear  OpcUaCreateMonitoredItemsResponseClear
	#define CHK_OpcUaCreateMonitoredItemsResponseClear  TRUE
	#define EXP_OpcUaCreateMonitoredItemsResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCreateMonitoredItemsResponseClear", (RTS_UINTPTR)OpcUaCreateMonitoredItemsResponseClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaCreateMonitoredItemsResponseClear
	#define EXT_CmpOPCUAStackOpcUaCreateMonitoredItemsResponseClear
	#define GET_CmpOPCUAStackOpcUaCreateMonitoredItemsResponseClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaCreateMonitoredItemsResponseClear pICmpOPCUAStack->IOpcUaCreateMonitoredItemsResponseClear
	#define CHK_CmpOPCUAStackOpcUaCreateMonitoredItemsResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaCreateMonitoredItemsResponseClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaCreateMonitoredItemsResponseClear
	#define EXT_OpcUaCreateMonitoredItemsResponseClear
	#define GET_OpcUaCreateMonitoredItemsResponseClear(fl)  CAL_CMGETAPI( "OpcUaCreateMonitoredItemsResponseClear" ) 
	#define CAL_OpcUaCreateMonitoredItemsResponseClear pICmpOPCUAStack->IOpcUaCreateMonitoredItemsResponseClear
	#define CHK_OpcUaCreateMonitoredItemsResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaCreateMonitoredItemsResponseClear  CAL_CMEXPAPI( "OpcUaCreateMonitoredItemsResponseClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaCreateMonitoredItemsResponseClear  PFOPCUACREATEMONITOREDITEMSRESPONSECLEAR pfOpcUaCreateMonitoredItemsResponseClear;
	#define EXT_OpcUaCreateMonitoredItemsResponseClear  extern PFOPCUACREATEMONITOREDITEMSRESPONSECLEAR pfOpcUaCreateMonitoredItemsResponseClear;
	#define GET_OpcUaCreateMonitoredItemsResponseClear(fl)  s_pfCMGetAPI2( "OpcUaCreateMonitoredItemsResponseClear", (RTS_VOID_FCTPTR *)&pfOpcUaCreateMonitoredItemsResponseClear, (fl), 0, 0)
	#define CAL_OpcUaCreateMonitoredItemsResponseClear  pfOpcUaCreateMonitoredItemsResponseClear
	#define CHK_OpcUaCreateMonitoredItemsResponseClear  (pfOpcUaCreateMonitoredItemsResponseClear != NULL)
	#define EXP_OpcUaCreateMonitoredItemsResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCreateMonitoredItemsResponseClear", (RTS_UINTPTR)OpcUaCreateMonitoredItemsResponseClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaModifyMonitoredItemsRequestInitialize(OpcUa_ModifyMonitoredItemsRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAMODIFYMONITOREDITEMSREQUESTINITIALIZE) (OpcUa_ModifyMonitoredItemsRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAMODIFYMONITOREDITEMSREQUESTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaModifyMonitoredItemsRequestInitialize
	#define EXT_OpcUaModifyMonitoredItemsRequestInitialize
	#define GET_OpcUaModifyMonitoredItemsRequestInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaModifyMonitoredItemsRequestInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaModifyMonitoredItemsRequestInitialize  FALSE
	#define EXP_OpcUaModifyMonitoredItemsRequestInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaModifyMonitoredItemsRequestInitialize
	#define EXT_OpcUaModifyMonitoredItemsRequestInitialize
	#define GET_OpcUaModifyMonitoredItemsRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaModifyMonitoredItemsRequestInitialize" ) 
	#define CAL_OpcUaModifyMonitoredItemsRequestInitialize  OpcUaModifyMonitoredItemsRequestInitialize
	#define CHK_OpcUaModifyMonitoredItemsRequestInitialize  TRUE
	#define EXP_OpcUaModifyMonitoredItemsRequestInitialize  CAL_CMEXPAPI( "OpcUaModifyMonitoredItemsRequestInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaModifyMonitoredItemsRequestInitialize
	#define EXT_OpcUaModifyMonitoredItemsRequestInitialize
	#define GET_OpcUaModifyMonitoredItemsRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaModifyMonitoredItemsRequestInitialize" ) 
	#define CAL_OpcUaModifyMonitoredItemsRequestInitialize  OpcUaModifyMonitoredItemsRequestInitialize
	#define CHK_OpcUaModifyMonitoredItemsRequestInitialize  TRUE
	#define EXP_OpcUaModifyMonitoredItemsRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaModifyMonitoredItemsRequestInitialize", (RTS_UINTPTR)OpcUaModifyMonitoredItemsRequestInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaModifyMonitoredItemsRequestInitialize
	#define EXT_CmpOPCUAStackOpcUaModifyMonitoredItemsRequestInitialize
	#define GET_CmpOPCUAStackOpcUaModifyMonitoredItemsRequestInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaModifyMonitoredItemsRequestInitialize pICmpOPCUAStack->IOpcUaModifyMonitoredItemsRequestInitialize
	#define CHK_CmpOPCUAStackOpcUaModifyMonitoredItemsRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaModifyMonitoredItemsRequestInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaModifyMonitoredItemsRequestInitialize
	#define EXT_OpcUaModifyMonitoredItemsRequestInitialize
	#define GET_OpcUaModifyMonitoredItemsRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaModifyMonitoredItemsRequestInitialize" ) 
	#define CAL_OpcUaModifyMonitoredItemsRequestInitialize pICmpOPCUAStack->IOpcUaModifyMonitoredItemsRequestInitialize
	#define CHK_OpcUaModifyMonitoredItemsRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaModifyMonitoredItemsRequestInitialize  CAL_CMEXPAPI( "OpcUaModifyMonitoredItemsRequestInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaModifyMonitoredItemsRequestInitialize  PFOPCUAMODIFYMONITOREDITEMSREQUESTINITIALIZE pfOpcUaModifyMonitoredItemsRequestInitialize;
	#define EXT_OpcUaModifyMonitoredItemsRequestInitialize  extern PFOPCUAMODIFYMONITOREDITEMSREQUESTINITIALIZE pfOpcUaModifyMonitoredItemsRequestInitialize;
	#define GET_OpcUaModifyMonitoredItemsRequestInitialize(fl)  s_pfCMGetAPI2( "OpcUaModifyMonitoredItemsRequestInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaModifyMonitoredItemsRequestInitialize, (fl), 0, 0)
	#define CAL_OpcUaModifyMonitoredItemsRequestInitialize  pfOpcUaModifyMonitoredItemsRequestInitialize
	#define CHK_OpcUaModifyMonitoredItemsRequestInitialize  (pfOpcUaModifyMonitoredItemsRequestInitialize != NULL)
	#define EXP_OpcUaModifyMonitoredItemsRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaModifyMonitoredItemsRequestInitialize", (RTS_UINTPTR)OpcUaModifyMonitoredItemsRequestInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaModifyMonitoredItemsRequestClear(OpcUa_ModifyMonitoredItemsRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAMODIFYMONITOREDITEMSREQUESTCLEAR) (OpcUa_ModifyMonitoredItemsRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAMODIFYMONITOREDITEMSREQUESTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaModifyMonitoredItemsRequestClear
	#define EXT_OpcUaModifyMonitoredItemsRequestClear
	#define GET_OpcUaModifyMonitoredItemsRequestClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaModifyMonitoredItemsRequestClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaModifyMonitoredItemsRequestClear  FALSE
	#define EXP_OpcUaModifyMonitoredItemsRequestClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaModifyMonitoredItemsRequestClear
	#define EXT_OpcUaModifyMonitoredItemsRequestClear
	#define GET_OpcUaModifyMonitoredItemsRequestClear(fl)  CAL_CMGETAPI( "OpcUaModifyMonitoredItemsRequestClear" ) 
	#define CAL_OpcUaModifyMonitoredItemsRequestClear  OpcUaModifyMonitoredItemsRequestClear
	#define CHK_OpcUaModifyMonitoredItemsRequestClear  TRUE
	#define EXP_OpcUaModifyMonitoredItemsRequestClear  CAL_CMEXPAPI( "OpcUaModifyMonitoredItemsRequestClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaModifyMonitoredItemsRequestClear
	#define EXT_OpcUaModifyMonitoredItemsRequestClear
	#define GET_OpcUaModifyMonitoredItemsRequestClear(fl)  CAL_CMGETAPI( "OpcUaModifyMonitoredItemsRequestClear" ) 
	#define CAL_OpcUaModifyMonitoredItemsRequestClear  OpcUaModifyMonitoredItemsRequestClear
	#define CHK_OpcUaModifyMonitoredItemsRequestClear  TRUE
	#define EXP_OpcUaModifyMonitoredItemsRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaModifyMonitoredItemsRequestClear", (RTS_UINTPTR)OpcUaModifyMonitoredItemsRequestClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaModifyMonitoredItemsRequestClear
	#define EXT_CmpOPCUAStackOpcUaModifyMonitoredItemsRequestClear
	#define GET_CmpOPCUAStackOpcUaModifyMonitoredItemsRequestClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaModifyMonitoredItemsRequestClear pICmpOPCUAStack->IOpcUaModifyMonitoredItemsRequestClear
	#define CHK_CmpOPCUAStackOpcUaModifyMonitoredItemsRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaModifyMonitoredItemsRequestClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaModifyMonitoredItemsRequestClear
	#define EXT_OpcUaModifyMonitoredItemsRequestClear
	#define GET_OpcUaModifyMonitoredItemsRequestClear(fl)  CAL_CMGETAPI( "OpcUaModifyMonitoredItemsRequestClear" ) 
	#define CAL_OpcUaModifyMonitoredItemsRequestClear pICmpOPCUAStack->IOpcUaModifyMonitoredItemsRequestClear
	#define CHK_OpcUaModifyMonitoredItemsRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaModifyMonitoredItemsRequestClear  CAL_CMEXPAPI( "OpcUaModifyMonitoredItemsRequestClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaModifyMonitoredItemsRequestClear  PFOPCUAMODIFYMONITOREDITEMSREQUESTCLEAR pfOpcUaModifyMonitoredItemsRequestClear;
	#define EXT_OpcUaModifyMonitoredItemsRequestClear  extern PFOPCUAMODIFYMONITOREDITEMSREQUESTCLEAR pfOpcUaModifyMonitoredItemsRequestClear;
	#define GET_OpcUaModifyMonitoredItemsRequestClear(fl)  s_pfCMGetAPI2( "OpcUaModifyMonitoredItemsRequestClear", (RTS_VOID_FCTPTR *)&pfOpcUaModifyMonitoredItemsRequestClear, (fl), 0, 0)
	#define CAL_OpcUaModifyMonitoredItemsRequestClear  pfOpcUaModifyMonitoredItemsRequestClear
	#define CHK_OpcUaModifyMonitoredItemsRequestClear  (pfOpcUaModifyMonitoredItemsRequestClear != NULL)
	#define EXP_OpcUaModifyMonitoredItemsRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaModifyMonitoredItemsRequestClear", (RTS_UINTPTR)OpcUaModifyMonitoredItemsRequestClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaModifyMonitoredItemsResponseInitialize(OpcUa_ModifyMonitoredItemsResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAMODIFYMONITOREDITEMSRESPONSEINITIALIZE) (OpcUa_ModifyMonitoredItemsResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAMODIFYMONITOREDITEMSRESPONSEINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaModifyMonitoredItemsResponseInitialize
	#define EXT_OpcUaModifyMonitoredItemsResponseInitialize
	#define GET_OpcUaModifyMonitoredItemsResponseInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaModifyMonitoredItemsResponseInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaModifyMonitoredItemsResponseInitialize  FALSE
	#define EXP_OpcUaModifyMonitoredItemsResponseInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaModifyMonitoredItemsResponseInitialize
	#define EXT_OpcUaModifyMonitoredItemsResponseInitialize
	#define GET_OpcUaModifyMonitoredItemsResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaModifyMonitoredItemsResponseInitialize" ) 
	#define CAL_OpcUaModifyMonitoredItemsResponseInitialize  OpcUaModifyMonitoredItemsResponseInitialize
	#define CHK_OpcUaModifyMonitoredItemsResponseInitialize  TRUE
	#define EXP_OpcUaModifyMonitoredItemsResponseInitialize  CAL_CMEXPAPI( "OpcUaModifyMonitoredItemsResponseInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaModifyMonitoredItemsResponseInitialize
	#define EXT_OpcUaModifyMonitoredItemsResponseInitialize
	#define GET_OpcUaModifyMonitoredItemsResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaModifyMonitoredItemsResponseInitialize" ) 
	#define CAL_OpcUaModifyMonitoredItemsResponseInitialize  OpcUaModifyMonitoredItemsResponseInitialize
	#define CHK_OpcUaModifyMonitoredItemsResponseInitialize  TRUE
	#define EXP_OpcUaModifyMonitoredItemsResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaModifyMonitoredItemsResponseInitialize", (RTS_UINTPTR)OpcUaModifyMonitoredItemsResponseInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaModifyMonitoredItemsResponseInitialize
	#define EXT_CmpOPCUAStackOpcUaModifyMonitoredItemsResponseInitialize
	#define GET_CmpOPCUAStackOpcUaModifyMonitoredItemsResponseInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaModifyMonitoredItemsResponseInitialize pICmpOPCUAStack->IOpcUaModifyMonitoredItemsResponseInitialize
	#define CHK_CmpOPCUAStackOpcUaModifyMonitoredItemsResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaModifyMonitoredItemsResponseInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaModifyMonitoredItemsResponseInitialize
	#define EXT_OpcUaModifyMonitoredItemsResponseInitialize
	#define GET_OpcUaModifyMonitoredItemsResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaModifyMonitoredItemsResponseInitialize" ) 
	#define CAL_OpcUaModifyMonitoredItemsResponseInitialize pICmpOPCUAStack->IOpcUaModifyMonitoredItemsResponseInitialize
	#define CHK_OpcUaModifyMonitoredItemsResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaModifyMonitoredItemsResponseInitialize  CAL_CMEXPAPI( "OpcUaModifyMonitoredItemsResponseInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaModifyMonitoredItemsResponseInitialize  PFOPCUAMODIFYMONITOREDITEMSRESPONSEINITIALIZE pfOpcUaModifyMonitoredItemsResponseInitialize;
	#define EXT_OpcUaModifyMonitoredItemsResponseInitialize  extern PFOPCUAMODIFYMONITOREDITEMSRESPONSEINITIALIZE pfOpcUaModifyMonitoredItemsResponseInitialize;
	#define GET_OpcUaModifyMonitoredItemsResponseInitialize(fl)  s_pfCMGetAPI2( "OpcUaModifyMonitoredItemsResponseInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaModifyMonitoredItemsResponseInitialize, (fl), 0, 0)
	#define CAL_OpcUaModifyMonitoredItemsResponseInitialize  pfOpcUaModifyMonitoredItemsResponseInitialize
	#define CHK_OpcUaModifyMonitoredItemsResponseInitialize  (pfOpcUaModifyMonitoredItemsResponseInitialize != NULL)
	#define EXP_OpcUaModifyMonitoredItemsResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaModifyMonitoredItemsResponseInitialize", (RTS_UINTPTR)OpcUaModifyMonitoredItemsResponseInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaModifyMonitoredItemsResponseClear(OpcUa_ModifyMonitoredItemsResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAMODIFYMONITOREDITEMSRESPONSECLEAR) (OpcUa_ModifyMonitoredItemsResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAMODIFYMONITOREDITEMSRESPONSECLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaModifyMonitoredItemsResponseClear
	#define EXT_OpcUaModifyMonitoredItemsResponseClear
	#define GET_OpcUaModifyMonitoredItemsResponseClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaModifyMonitoredItemsResponseClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaModifyMonitoredItemsResponseClear  FALSE
	#define EXP_OpcUaModifyMonitoredItemsResponseClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaModifyMonitoredItemsResponseClear
	#define EXT_OpcUaModifyMonitoredItemsResponseClear
	#define GET_OpcUaModifyMonitoredItemsResponseClear(fl)  CAL_CMGETAPI( "OpcUaModifyMonitoredItemsResponseClear" ) 
	#define CAL_OpcUaModifyMonitoredItemsResponseClear  OpcUaModifyMonitoredItemsResponseClear
	#define CHK_OpcUaModifyMonitoredItemsResponseClear  TRUE
	#define EXP_OpcUaModifyMonitoredItemsResponseClear  CAL_CMEXPAPI( "OpcUaModifyMonitoredItemsResponseClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaModifyMonitoredItemsResponseClear
	#define EXT_OpcUaModifyMonitoredItemsResponseClear
	#define GET_OpcUaModifyMonitoredItemsResponseClear(fl)  CAL_CMGETAPI( "OpcUaModifyMonitoredItemsResponseClear" ) 
	#define CAL_OpcUaModifyMonitoredItemsResponseClear  OpcUaModifyMonitoredItemsResponseClear
	#define CHK_OpcUaModifyMonitoredItemsResponseClear  TRUE
	#define EXP_OpcUaModifyMonitoredItemsResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaModifyMonitoredItemsResponseClear", (RTS_UINTPTR)OpcUaModifyMonitoredItemsResponseClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaModifyMonitoredItemsResponseClear
	#define EXT_CmpOPCUAStackOpcUaModifyMonitoredItemsResponseClear
	#define GET_CmpOPCUAStackOpcUaModifyMonitoredItemsResponseClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaModifyMonitoredItemsResponseClear pICmpOPCUAStack->IOpcUaModifyMonitoredItemsResponseClear
	#define CHK_CmpOPCUAStackOpcUaModifyMonitoredItemsResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaModifyMonitoredItemsResponseClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaModifyMonitoredItemsResponseClear
	#define EXT_OpcUaModifyMonitoredItemsResponseClear
	#define GET_OpcUaModifyMonitoredItemsResponseClear(fl)  CAL_CMGETAPI( "OpcUaModifyMonitoredItemsResponseClear" ) 
	#define CAL_OpcUaModifyMonitoredItemsResponseClear pICmpOPCUAStack->IOpcUaModifyMonitoredItemsResponseClear
	#define CHK_OpcUaModifyMonitoredItemsResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaModifyMonitoredItemsResponseClear  CAL_CMEXPAPI( "OpcUaModifyMonitoredItemsResponseClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaModifyMonitoredItemsResponseClear  PFOPCUAMODIFYMONITOREDITEMSRESPONSECLEAR pfOpcUaModifyMonitoredItemsResponseClear;
	#define EXT_OpcUaModifyMonitoredItemsResponseClear  extern PFOPCUAMODIFYMONITOREDITEMSRESPONSECLEAR pfOpcUaModifyMonitoredItemsResponseClear;
	#define GET_OpcUaModifyMonitoredItemsResponseClear(fl)  s_pfCMGetAPI2( "OpcUaModifyMonitoredItemsResponseClear", (RTS_VOID_FCTPTR *)&pfOpcUaModifyMonitoredItemsResponseClear, (fl), 0, 0)
	#define CAL_OpcUaModifyMonitoredItemsResponseClear  pfOpcUaModifyMonitoredItemsResponseClear
	#define CHK_OpcUaModifyMonitoredItemsResponseClear  (pfOpcUaModifyMonitoredItemsResponseClear != NULL)
	#define EXP_OpcUaModifyMonitoredItemsResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaModifyMonitoredItemsResponseClear", (RTS_UINTPTR)OpcUaModifyMonitoredItemsResponseClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaSetMonitoringModeRequestInitialize(OpcUa_SetMonitoringModeRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUASETMONITORINGMODEREQUESTINITIALIZE) (OpcUa_SetMonitoringModeRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASETMONITORINGMODEREQUESTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaSetMonitoringModeRequestInitialize
	#define EXT_OpcUaSetMonitoringModeRequestInitialize
	#define GET_OpcUaSetMonitoringModeRequestInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaSetMonitoringModeRequestInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaSetMonitoringModeRequestInitialize  FALSE
	#define EXP_OpcUaSetMonitoringModeRequestInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaSetMonitoringModeRequestInitialize
	#define EXT_OpcUaSetMonitoringModeRequestInitialize
	#define GET_OpcUaSetMonitoringModeRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaSetMonitoringModeRequestInitialize" ) 
	#define CAL_OpcUaSetMonitoringModeRequestInitialize  OpcUaSetMonitoringModeRequestInitialize
	#define CHK_OpcUaSetMonitoringModeRequestInitialize  TRUE
	#define EXP_OpcUaSetMonitoringModeRequestInitialize  CAL_CMEXPAPI( "OpcUaSetMonitoringModeRequestInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaSetMonitoringModeRequestInitialize
	#define EXT_OpcUaSetMonitoringModeRequestInitialize
	#define GET_OpcUaSetMonitoringModeRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaSetMonitoringModeRequestInitialize" ) 
	#define CAL_OpcUaSetMonitoringModeRequestInitialize  OpcUaSetMonitoringModeRequestInitialize
	#define CHK_OpcUaSetMonitoringModeRequestInitialize  TRUE
	#define EXP_OpcUaSetMonitoringModeRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSetMonitoringModeRequestInitialize", (RTS_UINTPTR)OpcUaSetMonitoringModeRequestInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaSetMonitoringModeRequestInitialize
	#define EXT_CmpOPCUAStackOpcUaSetMonitoringModeRequestInitialize
	#define GET_CmpOPCUAStackOpcUaSetMonitoringModeRequestInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaSetMonitoringModeRequestInitialize pICmpOPCUAStack->IOpcUaSetMonitoringModeRequestInitialize
	#define CHK_CmpOPCUAStackOpcUaSetMonitoringModeRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaSetMonitoringModeRequestInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaSetMonitoringModeRequestInitialize
	#define EXT_OpcUaSetMonitoringModeRequestInitialize
	#define GET_OpcUaSetMonitoringModeRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaSetMonitoringModeRequestInitialize" ) 
	#define CAL_OpcUaSetMonitoringModeRequestInitialize pICmpOPCUAStack->IOpcUaSetMonitoringModeRequestInitialize
	#define CHK_OpcUaSetMonitoringModeRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaSetMonitoringModeRequestInitialize  CAL_CMEXPAPI( "OpcUaSetMonitoringModeRequestInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaSetMonitoringModeRequestInitialize  PFOPCUASETMONITORINGMODEREQUESTINITIALIZE pfOpcUaSetMonitoringModeRequestInitialize;
	#define EXT_OpcUaSetMonitoringModeRequestInitialize  extern PFOPCUASETMONITORINGMODEREQUESTINITIALIZE pfOpcUaSetMonitoringModeRequestInitialize;
	#define GET_OpcUaSetMonitoringModeRequestInitialize(fl)  s_pfCMGetAPI2( "OpcUaSetMonitoringModeRequestInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaSetMonitoringModeRequestInitialize, (fl), 0, 0)
	#define CAL_OpcUaSetMonitoringModeRequestInitialize  pfOpcUaSetMonitoringModeRequestInitialize
	#define CHK_OpcUaSetMonitoringModeRequestInitialize  (pfOpcUaSetMonitoringModeRequestInitialize != NULL)
	#define EXP_OpcUaSetMonitoringModeRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSetMonitoringModeRequestInitialize", (RTS_UINTPTR)OpcUaSetMonitoringModeRequestInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaSetMonitoringModeRequestClear(OpcUa_SetMonitoringModeRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUASETMONITORINGMODEREQUESTCLEAR) (OpcUa_SetMonitoringModeRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASETMONITORINGMODEREQUESTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaSetMonitoringModeRequestClear
	#define EXT_OpcUaSetMonitoringModeRequestClear
	#define GET_OpcUaSetMonitoringModeRequestClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaSetMonitoringModeRequestClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaSetMonitoringModeRequestClear  FALSE
	#define EXP_OpcUaSetMonitoringModeRequestClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaSetMonitoringModeRequestClear
	#define EXT_OpcUaSetMonitoringModeRequestClear
	#define GET_OpcUaSetMonitoringModeRequestClear(fl)  CAL_CMGETAPI( "OpcUaSetMonitoringModeRequestClear" ) 
	#define CAL_OpcUaSetMonitoringModeRequestClear  OpcUaSetMonitoringModeRequestClear
	#define CHK_OpcUaSetMonitoringModeRequestClear  TRUE
	#define EXP_OpcUaSetMonitoringModeRequestClear  CAL_CMEXPAPI( "OpcUaSetMonitoringModeRequestClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaSetMonitoringModeRequestClear
	#define EXT_OpcUaSetMonitoringModeRequestClear
	#define GET_OpcUaSetMonitoringModeRequestClear(fl)  CAL_CMGETAPI( "OpcUaSetMonitoringModeRequestClear" ) 
	#define CAL_OpcUaSetMonitoringModeRequestClear  OpcUaSetMonitoringModeRequestClear
	#define CHK_OpcUaSetMonitoringModeRequestClear  TRUE
	#define EXP_OpcUaSetMonitoringModeRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSetMonitoringModeRequestClear", (RTS_UINTPTR)OpcUaSetMonitoringModeRequestClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaSetMonitoringModeRequestClear
	#define EXT_CmpOPCUAStackOpcUaSetMonitoringModeRequestClear
	#define GET_CmpOPCUAStackOpcUaSetMonitoringModeRequestClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaSetMonitoringModeRequestClear pICmpOPCUAStack->IOpcUaSetMonitoringModeRequestClear
	#define CHK_CmpOPCUAStackOpcUaSetMonitoringModeRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaSetMonitoringModeRequestClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaSetMonitoringModeRequestClear
	#define EXT_OpcUaSetMonitoringModeRequestClear
	#define GET_OpcUaSetMonitoringModeRequestClear(fl)  CAL_CMGETAPI( "OpcUaSetMonitoringModeRequestClear" ) 
	#define CAL_OpcUaSetMonitoringModeRequestClear pICmpOPCUAStack->IOpcUaSetMonitoringModeRequestClear
	#define CHK_OpcUaSetMonitoringModeRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaSetMonitoringModeRequestClear  CAL_CMEXPAPI( "OpcUaSetMonitoringModeRequestClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaSetMonitoringModeRequestClear  PFOPCUASETMONITORINGMODEREQUESTCLEAR pfOpcUaSetMonitoringModeRequestClear;
	#define EXT_OpcUaSetMonitoringModeRequestClear  extern PFOPCUASETMONITORINGMODEREQUESTCLEAR pfOpcUaSetMonitoringModeRequestClear;
	#define GET_OpcUaSetMonitoringModeRequestClear(fl)  s_pfCMGetAPI2( "OpcUaSetMonitoringModeRequestClear", (RTS_VOID_FCTPTR *)&pfOpcUaSetMonitoringModeRequestClear, (fl), 0, 0)
	#define CAL_OpcUaSetMonitoringModeRequestClear  pfOpcUaSetMonitoringModeRequestClear
	#define CHK_OpcUaSetMonitoringModeRequestClear  (pfOpcUaSetMonitoringModeRequestClear != NULL)
	#define EXP_OpcUaSetMonitoringModeRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSetMonitoringModeRequestClear", (RTS_UINTPTR)OpcUaSetMonitoringModeRequestClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaSetMonitoringModeResponseInitialize(OpcUa_SetMonitoringModeResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUASETMONITORINGMODERESPONSEINITIALIZE) (OpcUa_SetMonitoringModeResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASETMONITORINGMODERESPONSEINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaSetMonitoringModeResponseInitialize
	#define EXT_OpcUaSetMonitoringModeResponseInitialize
	#define GET_OpcUaSetMonitoringModeResponseInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaSetMonitoringModeResponseInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaSetMonitoringModeResponseInitialize  FALSE
	#define EXP_OpcUaSetMonitoringModeResponseInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaSetMonitoringModeResponseInitialize
	#define EXT_OpcUaSetMonitoringModeResponseInitialize
	#define GET_OpcUaSetMonitoringModeResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaSetMonitoringModeResponseInitialize" ) 
	#define CAL_OpcUaSetMonitoringModeResponseInitialize  OpcUaSetMonitoringModeResponseInitialize
	#define CHK_OpcUaSetMonitoringModeResponseInitialize  TRUE
	#define EXP_OpcUaSetMonitoringModeResponseInitialize  CAL_CMEXPAPI( "OpcUaSetMonitoringModeResponseInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaSetMonitoringModeResponseInitialize
	#define EXT_OpcUaSetMonitoringModeResponseInitialize
	#define GET_OpcUaSetMonitoringModeResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaSetMonitoringModeResponseInitialize" ) 
	#define CAL_OpcUaSetMonitoringModeResponseInitialize  OpcUaSetMonitoringModeResponseInitialize
	#define CHK_OpcUaSetMonitoringModeResponseInitialize  TRUE
	#define EXP_OpcUaSetMonitoringModeResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSetMonitoringModeResponseInitialize", (RTS_UINTPTR)OpcUaSetMonitoringModeResponseInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaSetMonitoringModeResponseInitialize
	#define EXT_CmpOPCUAStackOpcUaSetMonitoringModeResponseInitialize
	#define GET_CmpOPCUAStackOpcUaSetMonitoringModeResponseInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaSetMonitoringModeResponseInitialize pICmpOPCUAStack->IOpcUaSetMonitoringModeResponseInitialize
	#define CHK_CmpOPCUAStackOpcUaSetMonitoringModeResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaSetMonitoringModeResponseInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaSetMonitoringModeResponseInitialize
	#define EXT_OpcUaSetMonitoringModeResponseInitialize
	#define GET_OpcUaSetMonitoringModeResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaSetMonitoringModeResponseInitialize" ) 
	#define CAL_OpcUaSetMonitoringModeResponseInitialize pICmpOPCUAStack->IOpcUaSetMonitoringModeResponseInitialize
	#define CHK_OpcUaSetMonitoringModeResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaSetMonitoringModeResponseInitialize  CAL_CMEXPAPI( "OpcUaSetMonitoringModeResponseInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaSetMonitoringModeResponseInitialize  PFOPCUASETMONITORINGMODERESPONSEINITIALIZE pfOpcUaSetMonitoringModeResponseInitialize;
	#define EXT_OpcUaSetMonitoringModeResponseInitialize  extern PFOPCUASETMONITORINGMODERESPONSEINITIALIZE pfOpcUaSetMonitoringModeResponseInitialize;
	#define GET_OpcUaSetMonitoringModeResponseInitialize(fl)  s_pfCMGetAPI2( "OpcUaSetMonitoringModeResponseInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaSetMonitoringModeResponseInitialize, (fl), 0, 0)
	#define CAL_OpcUaSetMonitoringModeResponseInitialize  pfOpcUaSetMonitoringModeResponseInitialize
	#define CHK_OpcUaSetMonitoringModeResponseInitialize  (pfOpcUaSetMonitoringModeResponseInitialize != NULL)
	#define EXP_OpcUaSetMonitoringModeResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSetMonitoringModeResponseInitialize", (RTS_UINTPTR)OpcUaSetMonitoringModeResponseInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaSetMonitoringModeResponseClear(OpcUa_SetMonitoringModeResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUASETMONITORINGMODERESPONSECLEAR) (OpcUa_SetMonitoringModeResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASETMONITORINGMODERESPONSECLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaSetMonitoringModeResponseClear
	#define EXT_OpcUaSetMonitoringModeResponseClear
	#define GET_OpcUaSetMonitoringModeResponseClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaSetMonitoringModeResponseClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaSetMonitoringModeResponseClear  FALSE
	#define EXP_OpcUaSetMonitoringModeResponseClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaSetMonitoringModeResponseClear
	#define EXT_OpcUaSetMonitoringModeResponseClear
	#define GET_OpcUaSetMonitoringModeResponseClear(fl)  CAL_CMGETAPI( "OpcUaSetMonitoringModeResponseClear" ) 
	#define CAL_OpcUaSetMonitoringModeResponseClear  OpcUaSetMonitoringModeResponseClear
	#define CHK_OpcUaSetMonitoringModeResponseClear  TRUE
	#define EXP_OpcUaSetMonitoringModeResponseClear  CAL_CMEXPAPI( "OpcUaSetMonitoringModeResponseClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaSetMonitoringModeResponseClear
	#define EXT_OpcUaSetMonitoringModeResponseClear
	#define GET_OpcUaSetMonitoringModeResponseClear(fl)  CAL_CMGETAPI( "OpcUaSetMonitoringModeResponseClear" ) 
	#define CAL_OpcUaSetMonitoringModeResponseClear  OpcUaSetMonitoringModeResponseClear
	#define CHK_OpcUaSetMonitoringModeResponseClear  TRUE
	#define EXP_OpcUaSetMonitoringModeResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSetMonitoringModeResponseClear", (RTS_UINTPTR)OpcUaSetMonitoringModeResponseClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaSetMonitoringModeResponseClear
	#define EXT_CmpOPCUAStackOpcUaSetMonitoringModeResponseClear
	#define GET_CmpOPCUAStackOpcUaSetMonitoringModeResponseClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaSetMonitoringModeResponseClear pICmpOPCUAStack->IOpcUaSetMonitoringModeResponseClear
	#define CHK_CmpOPCUAStackOpcUaSetMonitoringModeResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaSetMonitoringModeResponseClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaSetMonitoringModeResponseClear
	#define EXT_OpcUaSetMonitoringModeResponseClear
	#define GET_OpcUaSetMonitoringModeResponseClear(fl)  CAL_CMGETAPI( "OpcUaSetMonitoringModeResponseClear" ) 
	#define CAL_OpcUaSetMonitoringModeResponseClear pICmpOPCUAStack->IOpcUaSetMonitoringModeResponseClear
	#define CHK_OpcUaSetMonitoringModeResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaSetMonitoringModeResponseClear  CAL_CMEXPAPI( "OpcUaSetMonitoringModeResponseClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaSetMonitoringModeResponseClear  PFOPCUASETMONITORINGMODERESPONSECLEAR pfOpcUaSetMonitoringModeResponseClear;
	#define EXT_OpcUaSetMonitoringModeResponseClear  extern PFOPCUASETMONITORINGMODERESPONSECLEAR pfOpcUaSetMonitoringModeResponseClear;
	#define GET_OpcUaSetMonitoringModeResponseClear(fl)  s_pfCMGetAPI2( "OpcUaSetMonitoringModeResponseClear", (RTS_VOID_FCTPTR *)&pfOpcUaSetMonitoringModeResponseClear, (fl), 0, 0)
	#define CAL_OpcUaSetMonitoringModeResponseClear  pfOpcUaSetMonitoringModeResponseClear
	#define CHK_OpcUaSetMonitoringModeResponseClear  (pfOpcUaSetMonitoringModeResponseClear != NULL)
	#define EXP_OpcUaSetMonitoringModeResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSetMonitoringModeResponseClear", (RTS_UINTPTR)OpcUaSetMonitoringModeResponseClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaDeleteMonitoredItemsRequestInitialize(OpcUa_DeleteMonitoredItemsRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUADELETEMONITOREDITEMSREQUESTINITIALIZE) (OpcUa_DeleteMonitoredItemsRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUADELETEMONITOREDITEMSREQUESTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaDeleteMonitoredItemsRequestInitialize
	#define EXT_OpcUaDeleteMonitoredItemsRequestInitialize
	#define GET_OpcUaDeleteMonitoredItemsRequestInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaDeleteMonitoredItemsRequestInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaDeleteMonitoredItemsRequestInitialize  FALSE
	#define EXP_OpcUaDeleteMonitoredItemsRequestInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaDeleteMonitoredItemsRequestInitialize
	#define EXT_OpcUaDeleteMonitoredItemsRequestInitialize
	#define GET_OpcUaDeleteMonitoredItemsRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaDeleteMonitoredItemsRequestInitialize" ) 
	#define CAL_OpcUaDeleteMonitoredItemsRequestInitialize  OpcUaDeleteMonitoredItemsRequestInitialize
	#define CHK_OpcUaDeleteMonitoredItemsRequestInitialize  TRUE
	#define EXP_OpcUaDeleteMonitoredItemsRequestInitialize  CAL_CMEXPAPI( "OpcUaDeleteMonitoredItemsRequestInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaDeleteMonitoredItemsRequestInitialize
	#define EXT_OpcUaDeleteMonitoredItemsRequestInitialize
	#define GET_OpcUaDeleteMonitoredItemsRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaDeleteMonitoredItemsRequestInitialize" ) 
	#define CAL_OpcUaDeleteMonitoredItemsRequestInitialize  OpcUaDeleteMonitoredItemsRequestInitialize
	#define CHK_OpcUaDeleteMonitoredItemsRequestInitialize  TRUE
	#define EXP_OpcUaDeleteMonitoredItemsRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDeleteMonitoredItemsRequestInitialize", (RTS_UINTPTR)OpcUaDeleteMonitoredItemsRequestInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaDeleteMonitoredItemsRequestInitialize
	#define EXT_CmpOPCUAStackOpcUaDeleteMonitoredItemsRequestInitialize
	#define GET_CmpOPCUAStackOpcUaDeleteMonitoredItemsRequestInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaDeleteMonitoredItemsRequestInitialize pICmpOPCUAStack->IOpcUaDeleteMonitoredItemsRequestInitialize
	#define CHK_CmpOPCUAStackOpcUaDeleteMonitoredItemsRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaDeleteMonitoredItemsRequestInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaDeleteMonitoredItemsRequestInitialize
	#define EXT_OpcUaDeleteMonitoredItemsRequestInitialize
	#define GET_OpcUaDeleteMonitoredItemsRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaDeleteMonitoredItemsRequestInitialize" ) 
	#define CAL_OpcUaDeleteMonitoredItemsRequestInitialize pICmpOPCUAStack->IOpcUaDeleteMonitoredItemsRequestInitialize
	#define CHK_OpcUaDeleteMonitoredItemsRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaDeleteMonitoredItemsRequestInitialize  CAL_CMEXPAPI( "OpcUaDeleteMonitoredItemsRequestInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaDeleteMonitoredItemsRequestInitialize  PFOPCUADELETEMONITOREDITEMSREQUESTINITIALIZE pfOpcUaDeleteMonitoredItemsRequestInitialize;
	#define EXT_OpcUaDeleteMonitoredItemsRequestInitialize  extern PFOPCUADELETEMONITOREDITEMSREQUESTINITIALIZE pfOpcUaDeleteMonitoredItemsRequestInitialize;
	#define GET_OpcUaDeleteMonitoredItemsRequestInitialize(fl)  s_pfCMGetAPI2( "OpcUaDeleteMonitoredItemsRequestInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaDeleteMonitoredItemsRequestInitialize, (fl), 0, 0)
	#define CAL_OpcUaDeleteMonitoredItemsRequestInitialize  pfOpcUaDeleteMonitoredItemsRequestInitialize
	#define CHK_OpcUaDeleteMonitoredItemsRequestInitialize  (pfOpcUaDeleteMonitoredItemsRequestInitialize != NULL)
	#define EXP_OpcUaDeleteMonitoredItemsRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDeleteMonitoredItemsRequestInitialize", (RTS_UINTPTR)OpcUaDeleteMonitoredItemsRequestInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaDeleteMonitoredItemsRequestClear(OpcUa_DeleteMonitoredItemsRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUADELETEMONITOREDITEMSREQUESTCLEAR) (OpcUa_DeleteMonitoredItemsRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUADELETEMONITOREDITEMSREQUESTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaDeleteMonitoredItemsRequestClear
	#define EXT_OpcUaDeleteMonitoredItemsRequestClear
	#define GET_OpcUaDeleteMonitoredItemsRequestClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaDeleteMonitoredItemsRequestClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaDeleteMonitoredItemsRequestClear  FALSE
	#define EXP_OpcUaDeleteMonitoredItemsRequestClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaDeleteMonitoredItemsRequestClear
	#define EXT_OpcUaDeleteMonitoredItemsRequestClear
	#define GET_OpcUaDeleteMonitoredItemsRequestClear(fl)  CAL_CMGETAPI( "OpcUaDeleteMonitoredItemsRequestClear" ) 
	#define CAL_OpcUaDeleteMonitoredItemsRequestClear  OpcUaDeleteMonitoredItemsRequestClear
	#define CHK_OpcUaDeleteMonitoredItemsRequestClear  TRUE
	#define EXP_OpcUaDeleteMonitoredItemsRequestClear  CAL_CMEXPAPI( "OpcUaDeleteMonitoredItemsRequestClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaDeleteMonitoredItemsRequestClear
	#define EXT_OpcUaDeleteMonitoredItemsRequestClear
	#define GET_OpcUaDeleteMonitoredItemsRequestClear(fl)  CAL_CMGETAPI( "OpcUaDeleteMonitoredItemsRequestClear" ) 
	#define CAL_OpcUaDeleteMonitoredItemsRequestClear  OpcUaDeleteMonitoredItemsRequestClear
	#define CHK_OpcUaDeleteMonitoredItemsRequestClear  TRUE
	#define EXP_OpcUaDeleteMonitoredItemsRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDeleteMonitoredItemsRequestClear", (RTS_UINTPTR)OpcUaDeleteMonitoredItemsRequestClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaDeleteMonitoredItemsRequestClear
	#define EXT_CmpOPCUAStackOpcUaDeleteMonitoredItemsRequestClear
	#define GET_CmpOPCUAStackOpcUaDeleteMonitoredItemsRequestClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaDeleteMonitoredItemsRequestClear pICmpOPCUAStack->IOpcUaDeleteMonitoredItemsRequestClear
	#define CHK_CmpOPCUAStackOpcUaDeleteMonitoredItemsRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaDeleteMonitoredItemsRequestClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaDeleteMonitoredItemsRequestClear
	#define EXT_OpcUaDeleteMonitoredItemsRequestClear
	#define GET_OpcUaDeleteMonitoredItemsRequestClear(fl)  CAL_CMGETAPI( "OpcUaDeleteMonitoredItemsRequestClear" ) 
	#define CAL_OpcUaDeleteMonitoredItemsRequestClear pICmpOPCUAStack->IOpcUaDeleteMonitoredItemsRequestClear
	#define CHK_OpcUaDeleteMonitoredItemsRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaDeleteMonitoredItemsRequestClear  CAL_CMEXPAPI( "OpcUaDeleteMonitoredItemsRequestClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaDeleteMonitoredItemsRequestClear  PFOPCUADELETEMONITOREDITEMSREQUESTCLEAR pfOpcUaDeleteMonitoredItemsRequestClear;
	#define EXT_OpcUaDeleteMonitoredItemsRequestClear  extern PFOPCUADELETEMONITOREDITEMSREQUESTCLEAR pfOpcUaDeleteMonitoredItemsRequestClear;
	#define GET_OpcUaDeleteMonitoredItemsRequestClear(fl)  s_pfCMGetAPI2( "OpcUaDeleteMonitoredItemsRequestClear", (RTS_VOID_FCTPTR *)&pfOpcUaDeleteMonitoredItemsRequestClear, (fl), 0, 0)
	#define CAL_OpcUaDeleteMonitoredItemsRequestClear  pfOpcUaDeleteMonitoredItemsRequestClear
	#define CHK_OpcUaDeleteMonitoredItemsRequestClear  (pfOpcUaDeleteMonitoredItemsRequestClear != NULL)
	#define EXP_OpcUaDeleteMonitoredItemsRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDeleteMonitoredItemsRequestClear", (RTS_UINTPTR)OpcUaDeleteMonitoredItemsRequestClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaDeleteMonitoredItemsResponseInitialize(OpcUa_DeleteMonitoredItemsResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUADELETEMONITOREDITEMSRESPONSEINITIALIZE) (OpcUa_DeleteMonitoredItemsResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUADELETEMONITOREDITEMSRESPONSEINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaDeleteMonitoredItemsResponseInitialize
	#define EXT_OpcUaDeleteMonitoredItemsResponseInitialize
	#define GET_OpcUaDeleteMonitoredItemsResponseInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaDeleteMonitoredItemsResponseInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaDeleteMonitoredItemsResponseInitialize  FALSE
	#define EXP_OpcUaDeleteMonitoredItemsResponseInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaDeleteMonitoredItemsResponseInitialize
	#define EXT_OpcUaDeleteMonitoredItemsResponseInitialize
	#define GET_OpcUaDeleteMonitoredItemsResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaDeleteMonitoredItemsResponseInitialize" ) 
	#define CAL_OpcUaDeleteMonitoredItemsResponseInitialize  OpcUaDeleteMonitoredItemsResponseInitialize
	#define CHK_OpcUaDeleteMonitoredItemsResponseInitialize  TRUE
	#define EXP_OpcUaDeleteMonitoredItemsResponseInitialize  CAL_CMEXPAPI( "OpcUaDeleteMonitoredItemsResponseInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaDeleteMonitoredItemsResponseInitialize
	#define EXT_OpcUaDeleteMonitoredItemsResponseInitialize
	#define GET_OpcUaDeleteMonitoredItemsResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaDeleteMonitoredItemsResponseInitialize" ) 
	#define CAL_OpcUaDeleteMonitoredItemsResponseInitialize  OpcUaDeleteMonitoredItemsResponseInitialize
	#define CHK_OpcUaDeleteMonitoredItemsResponseInitialize  TRUE
	#define EXP_OpcUaDeleteMonitoredItemsResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDeleteMonitoredItemsResponseInitialize", (RTS_UINTPTR)OpcUaDeleteMonitoredItemsResponseInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaDeleteMonitoredItemsResponseInitialize
	#define EXT_CmpOPCUAStackOpcUaDeleteMonitoredItemsResponseInitialize
	#define GET_CmpOPCUAStackOpcUaDeleteMonitoredItemsResponseInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaDeleteMonitoredItemsResponseInitialize pICmpOPCUAStack->IOpcUaDeleteMonitoredItemsResponseInitialize
	#define CHK_CmpOPCUAStackOpcUaDeleteMonitoredItemsResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaDeleteMonitoredItemsResponseInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaDeleteMonitoredItemsResponseInitialize
	#define EXT_OpcUaDeleteMonitoredItemsResponseInitialize
	#define GET_OpcUaDeleteMonitoredItemsResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaDeleteMonitoredItemsResponseInitialize" ) 
	#define CAL_OpcUaDeleteMonitoredItemsResponseInitialize pICmpOPCUAStack->IOpcUaDeleteMonitoredItemsResponseInitialize
	#define CHK_OpcUaDeleteMonitoredItemsResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaDeleteMonitoredItemsResponseInitialize  CAL_CMEXPAPI( "OpcUaDeleteMonitoredItemsResponseInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaDeleteMonitoredItemsResponseInitialize  PFOPCUADELETEMONITOREDITEMSRESPONSEINITIALIZE pfOpcUaDeleteMonitoredItemsResponseInitialize;
	#define EXT_OpcUaDeleteMonitoredItemsResponseInitialize  extern PFOPCUADELETEMONITOREDITEMSRESPONSEINITIALIZE pfOpcUaDeleteMonitoredItemsResponseInitialize;
	#define GET_OpcUaDeleteMonitoredItemsResponseInitialize(fl)  s_pfCMGetAPI2( "OpcUaDeleteMonitoredItemsResponseInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaDeleteMonitoredItemsResponseInitialize, (fl), 0, 0)
	#define CAL_OpcUaDeleteMonitoredItemsResponseInitialize  pfOpcUaDeleteMonitoredItemsResponseInitialize
	#define CHK_OpcUaDeleteMonitoredItemsResponseInitialize  (pfOpcUaDeleteMonitoredItemsResponseInitialize != NULL)
	#define EXP_OpcUaDeleteMonitoredItemsResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDeleteMonitoredItemsResponseInitialize", (RTS_UINTPTR)OpcUaDeleteMonitoredItemsResponseInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaDeleteMonitoredItemsResponseClear(OpcUa_DeleteMonitoredItemsResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUADELETEMONITOREDITEMSRESPONSECLEAR) (OpcUa_DeleteMonitoredItemsResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUADELETEMONITOREDITEMSRESPONSECLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaDeleteMonitoredItemsResponseClear
	#define EXT_OpcUaDeleteMonitoredItemsResponseClear
	#define GET_OpcUaDeleteMonitoredItemsResponseClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaDeleteMonitoredItemsResponseClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaDeleteMonitoredItemsResponseClear  FALSE
	#define EXP_OpcUaDeleteMonitoredItemsResponseClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaDeleteMonitoredItemsResponseClear
	#define EXT_OpcUaDeleteMonitoredItemsResponseClear
	#define GET_OpcUaDeleteMonitoredItemsResponseClear(fl)  CAL_CMGETAPI( "OpcUaDeleteMonitoredItemsResponseClear" ) 
	#define CAL_OpcUaDeleteMonitoredItemsResponseClear  OpcUaDeleteMonitoredItemsResponseClear
	#define CHK_OpcUaDeleteMonitoredItemsResponseClear  TRUE
	#define EXP_OpcUaDeleteMonitoredItemsResponseClear  CAL_CMEXPAPI( "OpcUaDeleteMonitoredItemsResponseClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaDeleteMonitoredItemsResponseClear
	#define EXT_OpcUaDeleteMonitoredItemsResponseClear
	#define GET_OpcUaDeleteMonitoredItemsResponseClear(fl)  CAL_CMGETAPI( "OpcUaDeleteMonitoredItemsResponseClear" ) 
	#define CAL_OpcUaDeleteMonitoredItemsResponseClear  OpcUaDeleteMonitoredItemsResponseClear
	#define CHK_OpcUaDeleteMonitoredItemsResponseClear  TRUE
	#define EXP_OpcUaDeleteMonitoredItemsResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDeleteMonitoredItemsResponseClear", (RTS_UINTPTR)OpcUaDeleteMonitoredItemsResponseClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaDeleteMonitoredItemsResponseClear
	#define EXT_CmpOPCUAStackOpcUaDeleteMonitoredItemsResponseClear
	#define GET_CmpOPCUAStackOpcUaDeleteMonitoredItemsResponseClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaDeleteMonitoredItemsResponseClear pICmpOPCUAStack->IOpcUaDeleteMonitoredItemsResponseClear
	#define CHK_CmpOPCUAStackOpcUaDeleteMonitoredItemsResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaDeleteMonitoredItemsResponseClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaDeleteMonitoredItemsResponseClear
	#define EXT_OpcUaDeleteMonitoredItemsResponseClear
	#define GET_OpcUaDeleteMonitoredItemsResponseClear(fl)  CAL_CMGETAPI( "OpcUaDeleteMonitoredItemsResponseClear" ) 
	#define CAL_OpcUaDeleteMonitoredItemsResponseClear pICmpOPCUAStack->IOpcUaDeleteMonitoredItemsResponseClear
	#define CHK_OpcUaDeleteMonitoredItemsResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaDeleteMonitoredItemsResponseClear  CAL_CMEXPAPI( "OpcUaDeleteMonitoredItemsResponseClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaDeleteMonitoredItemsResponseClear  PFOPCUADELETEMONITOREDITEMSRESPONSECLEAR pfOpcUaDeleteMonitoredItemsResponseClear;
	#define EXT_OpcUaDeleteMonitoredItemsResponseClear  extern PFOPCUADELETEMONITOREDITEMSRESPONSECLEAR pfOpcUaDeleteMonitoredItemsResponseClear;
	#define GET_OpcUaDeleteMonitoredItemsResponseClear(fl)  s_pfCMGetAPI2( "OpcUaDeleteMonitoredItemsResponseClear", (RTS_VOID_FCTPTR *)&pfOpcUaDeleteMonitoredItemsResponseClear, (fl), 0, 0)
	#define CAL_OpcUaDeleteMonitoredItemsResponseClear  pfOpcUaDeleteMonitoredItemsResponseClear
	#define CHK_OpcUaDeleteMonitoredItemsResponseClear  (pfOpcUaDeleteMonitoredItemsResponseClear != NULL)
	#define EXP_OpcUaDeleteMonitoredItemsResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDeleteMonitoredItemsResponseClear", (RTS_UINTPTR)OpcUaDeleteMonitoredItemsResponseClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaBrowseRequestInitialize(OpcUa_BrowseRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUABROWSEREQUESTINITIALIZE) (OpcUa_BrowseRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUABROWSEREQUESTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaBrowseRequestInitialize
	#define EXT_OpcUaBrowseRequestInitialize
	#define GET_OpcUaBrowseRequestInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaBrowseRequestInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaBrowseRequestInitialize  FALSE
	#define EXP_OpcUaBrowseRequestInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaBrowseRequestInitialize
	#define EXT_OpcUaBrowseRequestInitialize
	#define GET_OpcUaBrowseRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaBrowseRequestInitialize" ) 
	#define CAL_OpcUaBrowseRequestInitialize  OpcUaBrowseRequestInitialize
	#define CHK_OpcUaBrowseRequestInitialize  TRUE
	#define EXP_OpcUaBrowseRequestInitialize  CAL_CMEXPAPI( "OpcUaBrowseRequestInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaBrowseRequestInitialize
	#define EXT_OpcUaBrowseRequestInitialize
	#define GET_OpcUaBrowseRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaBrowseRequestInitialize" ) 
	#define CAL_OpcUaBrowseRequestInitialize  OpcUaBrowseRequestInitialize
	#define CHK_OpcUaBrowseRequestInitialize  TRUE
	#define EXP_OpcUaBrowseRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowseRequestInitialize", (RTS_UINTPTR)OpcUaBrowseRequestInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaBrowseRequestInitialize
	#define EXT_CmpOPCUAStackOpcUaBrowseRequestInitialize
	#define GET_CmpOPCUAStackOpcUaBrowseRequestInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaBrowseRequestInitialize pICmpOPCUAStack->IOpcUaBrowseRequestInitialize
	#define CHK_CmpOPCUAStackOpcUaBrowseRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaBrowseRequestInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaBrowseRequestInitialize
	#define EXT_OpcUaBrowseRequestInitialize
	#define GET_OpcUaBrowseRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaBrowseRequestInitialize" ) 
	#define CAL_OpcUaBrowseRequestInitialize pICmpOPCUAStack->IOpcUaBrowseRequestInitialize
	#define CHK_OpcUaBrowseRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaBrowseRequestInitialize  CAL_CMEXPAPI( "OpcUaBrowseRequestInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaBrowseRequestInitialize  PFOPCUABROWSEREQUESTINITIALIZE pfOpcUaBrowseRequestInitialize;
	#define EXT_OpcUaBrowseRequestInitialize  extern PFOPCUABROWSEREQUESTINITIALIZE pfOpcUaBrowseRequestInitialize;
	#define GET_OpcUaBrowseRequestInitialize(fl)  s_pfCMGetAPI2( "OpcUaBrowseRequestInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaBrowseRequestInitialize, (fl), 0, 0)
	#define CAL_OpcUaBrowseRequestInitialize  pfOpcUaBrowseRequestInitialize
	#define CHK_OpcUaBrowseRequestInitialize  (pfOpcUaBrowseRequestInitialize != NULL)
	#define EXP_OpcUaBrowseRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowseRequestInitialize", (RTS_UINTPTR)OpcUaBrowseRequestInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaBrowseRequestClear(OpcUa_BrowseRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUABROWSEREQUESTCLEAR) (OpcUa_BrowseRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUABROWSEREQUESTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaBrowseRequestClear
	#define EXT_OpcUaBrowseRequestClear
	#define GET_OpcUaBrowseRequestClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaBrowseRequestClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaBrowseRequestClear  FALSE
	#define EXP_OpcUaBrowseRequestClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaBrowseRequestClear
	#define EXT_OpcUaBrowseRequestClear
	#define GET_OpcUaBrowseRequestClear(fl)  CAL_CMGETAPI( "OpcUaBrowseRequestClear" ) 
	#define CAL_OpcUaBrowseRequestClear  OpcUaBrowseRequestClear
	#define CHK_OpcUaBrowseRequestClear  TRUE
	#define EXP_OpcUaBrowseRequestClear  CAL_CMEXPAPI( "OpcUaBrowseRequestClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaBrowseRequestClear
	#define EXT_OpcUaBrowseRequestClear
	#define GET_OpcUaBrowseRequestClear(fl)  CAL_CMGETAPI( "OpcUaBrowseRequestClear" ) 
	#define CAL_OpcUaBrowseRequestClear  OpcUaBrowseRequestClear
	#define CHK_OpcUaBrowseRequestClear  TRUE
	#define EXP_OpcUaBrowseRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowseRequestClear", (RTS_UINTPTR)OpcUaBrowseRequestClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaBrowseRequestClear
	#define EXT_CmpOPCUAStackOpcUaBrowseRequestClear
	#define GET_CmpOPCUAStackOpcUaBrowseRequestClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaBrowseRequestClear pICmpOPCUAStack->IOpcUaBrowseRequestClear
	#define CHK_CmpOPCUAStackOpcUaBrowseRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaBrowseRequestClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaBrowseRequestClear
	#define EXT_OpcUaBrowseRequestClear
	#define GET_OpcUaBrowseRequestClear(fl)  CAL_CMGETAPI( "OpcUaBrowseRequestClear" ) 
	#define CAL_OpcUaBrowseRequestClear pICmpOPCUAStack->IOpcUaBrowseRequestClear
	#define CHK_OpcUaBrowseRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaBrowseRequestClear  CAL_CMEXPAPI( "OpcUaBrowseRequestClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaBrowseRequestClear  PFOPCUABROWSEREQUESTCLEAR pfOpcUaBrowseRequestClear;
	#define EXT_OpcUaBrowseRequestClear  extern PFOPCUABROWSEREQUESTCLEAR pfOpcUaBrowseRequestClear;
	#define GET_OpcUaBrowseRequestClear(fl)  s_pfCMGetAPI2( "OpcUaBrowseRequestClear", (RTS_VOID_FCTPTR *)&pfOpcUaBrowseRequestClear, (fl), 0, 0)
	#define CAL_OpcUaBrowseRequestClear  pfOpcUaBrowseRequestClear
	#define CHK_OpcUaBrowseRequestClear  (pfOpcUaBrowseRequestClear != NULL)
	#define EXP_OpcUaBrowseRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowseRequestClear", (RTS_UINTPTR)OpcUaBrowseRequestClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaBrowseResponseInitialize(OpcUa_BrowseResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUABROWSERESPONSEINITIALIZE) (OpcUa_BrowseResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUABROWSERESPONSEINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaBrowseResponseInitialize
	#define EXT_OpcUaBrowseResponseInitialize
	#define GET_OpcUaBrowseResponseInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaBrowseResponseInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaBrowseResponseInitialize  FALSE
	#define EXP_OpcUaBrowseResponseInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaBrowseResponseInitialize
	#define EXT_OpcUaBrowseResponseInitialize
	#define GET_OpcUaBrowseResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaBrowseResponseInitialize" ) 
	#define CAL_OpcUaBrowseResponseInitialize  OpcUaBrowseResponseInitialize
	#define CHK_OpcUaBrowseResponseInitialize  TRUE
	#define EXP_OpcUaBrowseResponseInitialize  CAL_CMEXPAPI( "OpcUaBrowseResponseInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaBrowseResponseInitialize
	#define EXT_OpcUaBrowseResponseInitialize
	#define GET_OpcUaBrowseResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaBrowseResponseInitialize" ) 
	#define CAL_OpcUaBrowseResponseInitialize  OpcUaBrowseResponseInitialize
	#define CHK_OpcUaBrowseResponseInitialize  TRUE
	#define EXP_OpcUaBrowseResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowseResponseInitialize", (RTS_UINTPTR)OpcUaBrowseResponseInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaBrowseResponseInitialize
	#define EXT_CmpOPCUAStackOpcUaBrowseResponseInitialize
	#define GET_CmpOPCUAStackOpcUaBrowseResponseInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaBrowseResponseInitialize pICmpOPCUAStack->IOpcUaBrowseResponseInitialize
	#define CHK_CmpOPCUAStackOpcUaBrowseResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaBrowseResponseInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaBrowseResponseInitialize
	#define EXT_OpcUaBrowseResponseInitialize
	#define GET_OpcUaBrowseResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaBrowseResponseInitialize" ) 
	#define CAL_OpcUaBrowseResponseInitialize pICmpOPCUAStack->IOpcUaBrowseResponseInitialize
	#define CHK_OpcUaBrowseResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaBrowseResponseInitialize  CAL_CMEXPAPI( "OpcUaBrowseResponseInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaBrowseResponseInitialize  PFOPCUABROWSERESPONSEINITIALIZE pfOpcUaBrowseResponseInitialize;
	#define EXT_OpcUaBrowseResponseInitialize  extern PFOPCUABROWSERESPONSEINITIALIZE pfOpcUaBrowseResponseInitialize;
	#define GET_OpcUaBrowseResponseInitialize(fl)  s_pfCMGetAPI2( "OpcUaBrowseResponseInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaBrowseResponseInitialize, (fl), 0, 0)
	#define CAL_OpcUaBrowseResponseInitialize  pfOpcUaBrowseResponseInitialize
	#define CHK_OpcUaBrowseResponseInitialize  (pfOpcUaBrowseResponseInitialize != NULL)
	#define EXP_OpcUaBrowseResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowseResponseInitialize", (RTS_UINTPTR)OpcUaBrowseResponseInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaBrowseResponseClear(OpcUa_BrowseResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUABROWSERESPONSECLEAR) (OpcUa_BrowseResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUABROWSERESPONSECLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaBrowseResponseClear
	#define EXT_OpcUaBrowseResponseClear
	#define GET_OpcUaBrowseResponseClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaBrowseResponseClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaBrowseResponseClear  FALSE
	#define EXP_OpcUaBrowseResponseClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaBrowseResponseClear
	#define EXT_OpcUaBrowseResponseClear
	#define GET_OpcUaBrowseResponseClear(fl)  CAL_CMGETAPI( "OpcUaBrowseResponseClear" ) 
	#define CAL_OpcUaBrowseResponseClear  OpcUaBrowseResponseClear
	#define CHK_OpcUaBrowseResponseClear  TRUE
	#define EXP_OpcUaBrowseResponseClear  CAL_CMEXPAPI( "OpcUaBrowseResponseClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaBrowseResponseClear
	#define EXT_OpcUaBrowseResponseClear
	#define GET_OpcUaBrowseResponseClear(fl)  CAL_CMGETAPI( "OpcUaBrowseResponseClear" ) 
	#define CAL_OpcUaBrowseResponseClear  OpcUaBrowseResponseClear
	#define CHK_OpcUaBrowseResponseClear  TRUE
	#define EXP_OpcUaBrowseResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowseResponseClear", (RTS_UINTPTR)OpcUaBrowseResponseClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaBrowseResponseClear
	#define EXT_CmpOPCUAStackOpcUaBrowseResponseClear
	#define GET_CmpOPCUAStackOpcUaBrowseResponseClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaBrowseResponseClear pICmpOPCUAStack->IOpcUaBrowseResponseClear
	#define CHK_CmpOPCUAStackOpcUaBrowseResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaBrowseResponseClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaBrowseResponseClear
	#define EXT_OpcUaBrowseResponseClear
	#define GET_OpcUaBrowseResponseClear(fl)  CAL_CMGETAPI( "OpcUaBrowseResponseClear" ) 
	#define CAL_OpcUaBrowseResponseClear pICmpOPCUAStack->IOpcUaBrowseResponseClear
	#define CHK_OpcUaBrowseResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaBrowseResponseClear  CAL_CMEXPAPI( "OpcUaBrowseResponseClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaBrowseResponseClear  PFOPCUABROWSERESPONSECLEAR pfOpcUaBrowseResponseClear;
	#define EXT_OpcUaBrowseResponseClear  extern PFOPCUABROWSERESPONSECLEAR pfOpcUaBrowseResponseClear;
	#define GET_OpcUaBrowseResponseClear(fl)  s_pfCMGetAPI2( "OpcUaBrowseResponseClear", (RTS_VOID_FCTPTR *)&pfOpcUaBrowseResponseClear, (fl), 0, 0)
	#define CAL_OpcUaBrowseResponseClear  pfOpcUaBrowseResponseClear
	#define CHK_OpcUaBrowseResponseClear  (pfOpcUaBrowseResponseClear != NULL)
	#define EXP_OpcUaBrowseResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowseResponseClear", (RTS_UINTPTR)OpcUaBrowseResponseClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaBrowseNextRequestInitialize(OpcUa_BrowseNextRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUABROWSENEXTREQUESTINITIALIZE) (OpcUa_BrowseNextRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUABROWSENEXTREQUESTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaBrowseNextRequestInitialize
	#define EXT_OpcUaBrowseNextRequestInitialize
	#define GET_OpcUaBrowseNextRequestInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaBrowseNextRequestInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaBrowseNextRequestInitialize  FALSE
	#define EXP_OpcUaBrowseNextRequestInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaBrowseNextRequestInitialize
	#define EXT_OpcUaBrowseNextRequestInitialize
	#define GET_OpcUaBrowseNextRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaBrowseNextRequestInitialize" ) 
	#define CAL_OpcUaBrowseNextRequestInitialize  OpcUaBrowseNextRequestInitialize
	#define CHK_OpcUaBrowseNextRequestInitialize  TRUE
	#define EXP_OpcUaBrowseNextRequestInitialize  CAL_CMEXPAPI( "OpcUaBrowseNextRequestInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaBrowseNextRequestInitialize
	#define EXT_OpcUaBrowseNextRequestInitialize
	#define GET_OpcUaBrowseNextRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaBrowseNextRequestInitialize" ) 
	#define CAL_OpcUaBrowseNextRequestInitialize  OpcUaBrowseNextRequestInitialize
	#define CHK_OpcUaBrowseNextRequestInitialize  TRUE
	#define EXP_OpcUaBrowseNextRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowseNextRequestInitialize", (RTS_UINTPTR)OpcUaBrowseNextRequestInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaBrowseNextRequestInitialize
	#define EXT_CmpOPCUAStackOpcUaBrowseNextRequestInitialize
	#define GET_CmpOPCUAStackOpcUaBrowseNextRequestInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaBrowseNextRequestInitialize pICmpOPCUAStack->IOpcUaBrowseNextRequestInitialize
	#define CHK_CmpOPCUAStackOpcUaBrowseNextRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaBrowseNextRequestInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaBrowseNextRequestInitialize
	#define EXT_OpcUaBrowseNextRequestInitialize
	#define GET_OpcUaBrowseNextRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaBrowseNextRequestInitialize" ) 
	#define CAL_OpcUaBrowseNextRequestInitialize pICmpOPCUAStack->IOpcUaBrowseNextRequestInitialize
	#define CHK_OpcUaBrowseNextRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaBrowseNextRequestInitialize  CAL_CMEXPAPI( "OpcUaBrowseNextRequestInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaBrowseNextRequestInitialize  PFOPCUABROWSENEXTREQUESTINITIALIZE pfOpcUaBrowseNextRequestInitialize;
	#define EXT_OpcUaBrowseNextRequestInitialize  extern PFOPCUABROWSENEXTREQUESTINITIALIZE pfOpcUaBrowseNextRequestInitialize;
	#define GET_OpcUaBrowseNextRequestInitialize(fl)  s_pfCMGetAPI2( "OpcUaBrowseNextRequestInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaBrowseNextRequestInitialize, (fl), 0, 0)
	#define CAL_OpcUaBrowseNextRequestInitialize  pfOpcUaBrowseNextRequestInitialize
	#define CHK_OpcUaBrowseNextRequestInitialize  (pfOpcUaBrowseNextRequestInitialize != NULL)
	#define EXP_OpcUaBrowseNextRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowseNextRequestInitialize", (RTS_UINTPTR)OpcUaBrowseNextRequestInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaBrowseNextRequestClear(OpcUa_BrowseNextRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUABROWSENEXTREQUESTCLEAR) (OpcUa_BrowseNextRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUABROWSENEXTREQUESTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaBrowseNextRequestClear
	#define EXT_OpcUaBrowseNextRequestClear
	#define GET_OpcUaBrowseNextRequestClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaBrowseNextRequestClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaBrowseNextRequestClear  FALSE
	#define EXP_OpcUaBrowseNextRequestClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaBrowseNextRequestClear
	#define EXT_OpcUaBrowseNextRequestClear
	#define GET_OpcUaBrowseNextRequestClear(fl)  CAL_CMGETAPI( "OpcUaBrowseNextRequestClear" ) 
	#define CAL_OpcUaBrowseNextRequestClear  OpcUaBrowseNextRequestClear
	#define CHK_OpcUaBrowseNextRequestClear  TRUE
	#define EXP_OpcUaBrowseNextRequestClear  CAL_CMEXPAPI( "OpcUaBrowseNextRequestClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaBrowseNextRequestClear
	#define EXT_OpcUaBrowseNextRequestClear
	#define GET_OpcUaBrowseNextRequestClear(fl)  CAL_CMGETAPI( "OpcUaBrowseNextRequestClear" ) 
	#define CAL_OpcUaBrowseNextRequestClear  OpcUaBrowseNextRequestClear
	#define CHK_OpcUaBrowseNextRequestClear  TRUE
	#define EXP_OpcUaBrowseNextRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowseNextRequestClear", (RTS_UINTPTR)OpcUaBrowseNextRequestClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaBrowseNextRequestClear
	#define EXT_CmpOPCUAStackOpcUaBrowseNextRequestClear
	#define GET_CmpOPCUAStackOpcUaBrowseNextRequestClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaBrowseNextRequestClear pICmpOPCUAStack->IOpcUaBrowseNextRequestClear
	#define CHK_CmpOPCUAStackOpcUaBrowseNextRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaBrowseNextRequestClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaBrowseNextRequestClear
	#define EXT_OpcUaBrowseNextRequestClear
	#define GET_OpcUaBrowseNextRequestClear(fl)  CAL_CMGETAPI( "OpcUaBrowseNextRequestClear" ) 
	#define CAL_OpcUaBrowseNextRequestClear pICmpOPCUAStack->IOpcUaBrowseNextRequestClear
	#define CHK_OpcUaBrowseNextRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaBrowseNextRequestClear  CAL_CMEXPAPI( "OpcUaBrowseNextRequestClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaBrowseNextRequestClear  PFOPCUABROWSENEXTREQUESTCLEAR pfOpcUaBrowseNextRequestClear;
	#define EXT_OpcUaBrowseNextRequestClear  extern PFOPCUABROWSENEXTREQUESTCLEAR pfOpcUaBrowseNextRequestClear;
	#define GET_OpcUaBrowseNextRequestClear(fl)  s_pfCMGetAPI2( "OpcUaBrowseNextRequestClear", (RTS_VOID_FCTPTR *)&pfOpcUaBrowseNextRequestClear, (fl), 0, 0)
	#define CAL_OpcUaBrowseNextRequestClear  pfOpcUaBrowseNextRequestClear
	#define CHK_OpcUaBrowseNextRequestClear  (pfOpcUaBrowseNextRequestClear != NULL)
	#define EXP_OpcUaBrowseNextRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowseNextRequestClear", (RTS_UINTPTR)OpcUaBrowseNextRequestClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaBrowseNextResponseInitialize(OpcUa_BrowseNextResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUABROWSENEXTRESPONSEINITIALIZE) (OpcUa_BrowseNextResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUABROWSENEXTRESPONSEINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaBrowseNextResponseInitialize
	#define EXT_OpcUaBrowseNextResponseInitialize
	#define GET_OpcUaBrowseNextResponseInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaBrowseNextResponseInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaBrowseNextResponseInitialize  FALSE
	#define EXP_OpcUaBrowseNextResponseInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaBrowseNextResponseInitialize
	#define EXT_OpcUaBrowseNextResponseInitialize
	#define GET_OpcUaBrowseNextResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaBrowseNextResponseInitialize" ) 
	#define CAL_OpcUaBrowseNextResponseInitialize  OpcUaBrowseNextResponseInitialize
	#define CHK_OpcUaBrowseNextResponseInitialize  TRUE
	#define EXP_OpcUaBrowseNextResponseInitialize  CAL_CMEXPAPI( "OpcUaBrowseNextResponseInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaBrowseNextResponseInitialize
	#define EXT_OpcUaBrowseNextResponseInitialize
	#define GET_OpcUaBrowseNextResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaBrowseNextResponseInitialize" ) 
	#define CAL_OpcUaBrowseNextResponseInitialize  OpcUaBrowseNextResponseInitialize
	#define CHK_OpcUaBrowseNextResponseInitialize  TRUE
	#define EXP_OpcUaBrowseNextResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowseNextResponseInitialize", (RTS_UINTPTR)OpcUaBrowseNextResponseInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaBrowseNextResponseInitialize
	#define EXT_CmpOPCUAStackOpcUaBrowseNextResponseInitialize
	#define GET_CmpOPCUAStackOpcUaBrowseNextResponseInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaBrowseNextResponseInitialize pICmpOPCUAStack->IOpcUaBrowseNextResponseInitialize
	#define CHK_CmpOPCUAStackOpcUaBrowseNextResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaBrowseNextResponseInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaBrowseNextResponseInitialize
	#define EXT_OpcUaBrowseNextResponseInitialize
	#define GET_OpcUaBrowseNextResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaBrowseNextResponseInitialize" ) 
	#define CAL_OpcUaBrowseNextResponseInitialize pICmpOPCUAStack->IOpcUaBrowseNextResponseInitialize
	#define CHK_OpcUaBrowseNextResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaBrowseNextResponseInitialize  CAL_CMEXPAPI( "OpcUaBrowseNextResponseInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaBrowseNextResponseInitialize  PFOPCUABROWSENEXTRESPONSEINITIALIZE pfOpcUaBrowseNextResponseInitialize;
	#define EXT_OpcUaBrowseNextResponseInitialize  extern PFOPCUABROWSENEXTRESPONSEINITIALIZE pfOpcUaBrowseNextResponseInitialize;
	#define GET_OpcUaBrowseNextResponseInitialize(fl)  s_pfCMGetAPI2( "OpcUaBrowseNextResponseInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaBrowseNextResponseInitialize, (fl), 0, 0)
	#define CAL_OpcUaBrowseNextResponseInitialize  pfOpcUaBrowseNextResponseInitialize
	#define CHK_OpcUaBrowseNextResponseInitialize  (pfOpcUaBrowseNextResponseInitialize != NULL)
	#define EXP_OpcUaBrowseNextResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowseNextResponseInitialize", (RTS_UINTPTR)OpcUaBrowseNextResponseInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaBrowseNextResponseClear(OpcUa_BrowseNextResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUABROWSENEXTRESPONSECLEAR) (OpcUa_BrowseNextResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUABROWSENEXTRESPONSECLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaBrowseNextResponseClear
	#define EXT_OpcUaBrowseNextResponseClear
	#define GET_OpcUaBrowseNextResponseClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaBrowseNextResponseClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaBrowseNextResponseClear  FALSE
	#define EXP_OpcUaBrowseNextResponseClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaBrowseNextResponseClear
	#define EXT_OpcUaBrowseNextResponseClear
	#define GET_OpcUaBrowseNextResponseClear(fl)  CAL_CMGETAPI( "OpcUaBrowseNextResponseClear" ) 
	#define CAL_OpcUaBrowseNextResponseClear  OpcUaBrowseNextResponseClear
	#define CHK_OpcUaBrowseNextResponseClear  TRUE
	#define EXP_OpcUaBrowseNextResponseClear  CAL_CMEXPAPI( "OpcUaBrowseNextResponseClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaBrowseNextResponseClear
	#define EXT_OpcUaBrowseNextResponseClear
	#define GET_OpcUaBrowseNextResponseClear(fl)  CAL_CMGETAPI( "OpcUaBrowseNextResponseClear" ) 
	#define CAL_OpcUaBrowseNextResponseClear  OpcUaBrowseNextResponseClear
	#define CHK_OpcUaBrowseNextResponseClear  TRUE
	#define EXP_OpcUaBrowseNextResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowseNextResponseClear", (RTS_UINTPTR)OpcUaBrowseNextResponseClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaBrowseNextResponseClear
	#define EXT_CmpOPCUAStackOpcUaBrowseNextResponseClear
	#define GET_CmpOPCUAStackOpcUaBrowseNextResponseClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaBrowseNextResponseClear pICmpOPCUAStack->IOpcUaBrowseNextResponseClear
	#define CHK_CmpOPCUAStackOpcUaBrowseNextResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaBrowseNextResponseClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaBrowseNextResponseClear
	#define EXT_OpcUaBrowseNextResponseClear
	#define GET_OpcUaBrowseNextResponseClear(fl)  CAL_CMGETAPI( "OpcUaBrowseNextResponseClear" ) 
	#define CAL_OpcUaBrowseNextResponseClear pICmpOPCUAStack->IOpcUaBrowseNextResponseClear
	#define CHK_OpcUaBrowseNextResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaBrowseNextResponseClear  CAL_CMEXPAPI( "OpcUaBrowseNextResponseClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaBrowseNextResponseClear  PFOPCUABROWSENEXTRESPONSECLEAR pfOpcUaBrowseNextResponseClear;
	#define EXT_OpcUaBrowseNextResponseClear  extern PFOPCUABROWSENEXTRESPONSECLEAR pfOpcUaBrowseNextResponseClear;
	#define GET_OpcUaBrowseNextResponseClear(fl)  s_pfCMGetAPI2( "OpcUaBrowseNextResponseClear", (RTS_VOID_FCTPTR *)&pfOpcUaBrowseNextResponseClear, (fl), 0, 0)
	#define CAL_OpcUaBrowseNextResponseClear  pfOpcUaBrowseNextResponseClear
	#define CHK_OpcUaBrowseNextResponseClear  (pfOpcUaBrowseNextResponseClear != NULL)
	#define EXP_OpcUaBrowseNextResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaBrowseNextResponseClear", (RTS_UINTPTR)OpcUaBrowseNextResponseClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize(OpcUa_TranslateBrowsePathsToNodeIdsRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUATRANSLATEBROWSEPATHSTONODEIDSREQUESTINITIALIZE) (OpcUa_TranslateBrowsePathsToNodeIdsRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUATRANSLATEBROWSEPATHSTONODEIDSREQUESTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize
	#define EXT_OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize
	#define GET_OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize  FALSE
	#define EXP_OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize
	#define EXT_OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize
	#define GET_OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize" ) 
	#define CAL_OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize  OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize
	#define CHK_OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize  TRUE
	#define EXP_OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize  CAL_CMEXPAPI( "OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize
	#define EXT_OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize
	#define GET_OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize" ) 
	#define CAL_OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize  OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize
	#define CHK_OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize  TRUE
	#define EXP_OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize", (RTS_UINTPTR)OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaTranslateBrowsePathsToNodeIdsRequestInitialize
	#define EXT_CmpOPCUAStackOpcUaTranslateBrowsePathsToNodeIdsRequestInitialize
	#define GET_CmpOPCUAStackOpcUaTranslateBrowsePathsToNodeIdsRequestInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaTranslateBrowsePathsToNodeIdsRequestInitialize pICmpOPCUAStack->IOpcUaTranslateBrowsePathsToNodeIdsRequestInitialize
	#define CHK_CmpOPCUAStackOpcUaTranslateBrowsePathsToNodeIdsRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaTranslateBrowsePathsToNodeIdsRequestInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize
	#define EXT_OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize
	#define GET_OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize" ) 
	#define CAL_OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize pICmpOPCUAStack->IOpcUaTranslateBrowsePathsToNodeIdsRequestInitialize
	#define CHK_OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize  CAL_CMEXPAPI( "OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize  PFOPCUATRANSLATEBROWSEPATHSTONODEIDSREQUESTINITIALIZE pfOpcUaTranslateBrowsePathsToNodeIdsRequestInitialize;
	#define EXT_OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize  extern PFOPCUATRANSLATEBROWSEPATHSTONODEIDSREQUESTINITIALIZE pfOpcUaTranslateBrowsePathsToNodeIdsRequestInitialize;
	#define GET_OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize(fl)  s_pfCMGetAPI2( "OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaTranslateBrowsePathsToNodeIdsRequestInitialize, (fl), 0, 0)
	#define CAL_OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize  pfOpcUaTranslateBrowsePathsToNodeIdsRequestInitialize
	#define CHK_OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize  (pfOpcUaTranslateBrowsePathsToNodeIdsRequestInitialize != NULL)
	#define EXP_OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize", (RTS_UINTPTR)OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaTranslateBrowsePathsToNodeIdsRequestClear(OpcUa_TranslateBrowsePathsToNodeIdsRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUATRANSLATEBROWSEPATHSTONODEIDSREQUESTCLEAR) (OpcUa_TranslateBrowsePathsToNodeIdsRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUATRANSLATEBROWSEPATHSTONODEIDSREQUESTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaTranslateBrowsePathsToNodeIdsRequestClear
	#define EXT_OpcUaTranslateBrowsePathsToNodeIdsRequestClear
	#define GET_OpcUaTranslateBrowsePathsToNodeIdsRequestClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaTranslateBrowsePathsToNodeIdsRequestClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaTranslateBrowsePathsToNodeIdsRequestClear  FALSE
	#define EXP_OpcUaTranslateBrowsePathsToNodeIdsRequestClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaTranslateBrowsePathsToNodeIdsRequestClear
	#define EXT_OpcUaTranslateBrowsePathsToNodeIdsRequestClear
	#define GET_OpcUaTranslateBrowsePathsToNodeIdsRequestClear(fl)  CAL_CMGETAPI( "OpcUaTranslateBrowsePathsToNodeIdsRequestClear" ) 
	#define CAL_OpcUaTranslateBrowsePathsToNodeIdsRequestClear  OpcUaTranslateBrowsePathsToNodeIdsRequestClear
	#define CHK_OpcUaTranslateBrowsePathsToNodeIdsRequestClear  TRUE
	#define EXP_OpcUaTranslateBrowsePathsToNodeIdsRequestClear  CAL_CMEXPAPI( "OpcUaTranslateBrowsePathsToNodeIdsRequestClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaTranslateBrowsePathsToNodeIdsRequestClear
	#define EXT_OpcUaTranslateBrowsePathsToNodeIdsRequestClear
	#define GET_OpcUaTranslateBrowsePathsToNodeIdsRequestClear(fl)  CAL_CMGETAPI( "OpcUaTranslateBrowsePathsToNodeIdsRequestClear" ) 
	#define CAL_OpcUaTranslateBrowsePathsToNodeIdsRequestClear  OpcUaTranslateBrowsePathsToNodeIdsRequestClear
	#define CHK_OpcUaTranslateBrowsePathsToNodeIdsRequestClear  TRUE
	#define EXP_OpcUaTranslateBrowsePathsToNodeIdsRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaTranslateBrowsePathsToNodeIdsRequestClear", (RTS_UINTPTR)OpcUaTranslateBrowsePathsToNodeIdsRequestClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaTranslateBrowsePathsToNodeIdsRequestClear
	#define EXT_CmpOPCUAStackOpcUaTranslateBrowsePathsToNodeIdsRequestClear
	#define GET_CmpOPCUAStackOpcUaTranslateBrowsePathsToNodeIdsRequestClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaTranslateBrowsePathsToNodeIdsRequestClear pICmpOPCUAStack->IOpcUaTranslateBrowsePathsToNodeIdsRequestClear
	#define CHK_CmpOPCUAStackOpcUaTranslateBrowsePathsToNodeIdsRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaTranslateBrowsePathsToNodeIdsRequestClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaTranslateBrowsePathsToNodeIdsRequestClear
	#define EXT_OpcUaTranslateBrowsePathsToNodeIdsRequestClear
	#define GET_OpcUaTranslateBrowsePathsToNodeIdsRequestClear(fl)  CAL_CMGETAPI( "OpcUaTranslateBrowsePathsToNodeIdsRequestClear" ) 
	#define CAL_OpcUaTranslateBrowsePathsToNodeIdsRequestClear pICmpOPCUAStack->IOpcUaTranslateBrowsePathsToNodeIdsRequestClear
	#define CHK_OpcUaTranslateBrowsePathsToNodeIdsRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaTranslateBrowsePathsToNodeIdsRequestClear  CAL_CMEXPAPI( "OpcUaTranslateBrowsePathsToNodeIdsRequestClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaTranslateBrowsePathsToNodeIdsRequestClear  PFOPCUATRANSLATEBROWSEPATHSTONODEIDSREQUESTCLEAR pfOpcUaTranslateBrowsePathsToNodeIdsRequestClear;
	#define EXT_OpcUaTranslateBrowsePathsToNodeIdsRequestClear  extern PFOPCUATRANSLATEBROWSEPATHSTONODEIDSREQUESTCLEAR pfOpcUaTranslateBrowsePathsToNodeIdsRequestClear;
	#define GET_OpcUaTranslateBrowsePathsToNodeIdsRequestClear(fl)  s_pfCMGetAPI2( "OpcUaTranslateBrowsePathsToNodeIdsRequestClear", (RTS_VOID_FCTPTR *)&pfOpcUaTranslateBrowsePathsToNodeIdsRequestClear, (fl), 0, 0)
	#define CAL_OpcUaTranslateBrowsePathsToNodeIdsRequestClear  pfOpcUaTranslateBrowsePathsToNodeIdsRequestClear
	#define CHK_OpcUaTranslateBrowsePathsToNodeIdsRequestClear  (pfOpcUaTranslateBrowsePathsToNodeIdsRequestClear != NULL)
	#define EXP_OpcUaTranslateBrowsePathsToNodeIdsRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaTranslateBrowsePathsToNodeIdsRequestClear", (RTS_UINTPTR)OpcUaTranslateBrowsePathsToNodeIdsRequestClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize(OpcUa_TranslateBrowsePathsToNodeIdsResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUATRANSLATEBROWSEPATHSTONODEIDSRESPONSEINITIALIZE) (OpcUa_TranslateBrowsePathsToNodeIdsResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUATRANSLATEBROWSEPATHSTONODEIDSRESPONSEINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize
	#define EXT_OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize
	#define GET_OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize  FALSE
	#define EXP_OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize
	#define EXT_OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize
	#define GET_OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize" ) 
	#define CAL_OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize  OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize
	#define CHK_OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize  TRUE
	#define EXP_OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize  CAL_CMEXPAPI( "OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize
	#define EXT_OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize
	#define GET_OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize" ) 
	#define CAL_OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize  OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize
	#define CHK_OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize  TRUE
	#define EXP_OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize", (RTS_UINTPTR)OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaTranslateBrowsePathsToNodeIdsResponseInitialize
	#define EXT_CmpOPCUAStackOpcUaTranslateBrowsePathsToNodeIdsResponseInitialize
	#define GET_CmpOPCUAStackOpcUaTranslateBrowsePathsToNodeIdsResponseInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaTranslateBrowsePathsToNodeIdsResponseInitialize pICmpOPCUAStack->IOpcUaTranslateBrowsePathsToNodeIdsResponseInitialize
	#define CHK_CmpOPCUAStackOpcUaTranslateBrowsePathsToNodeIdsResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaTranslateBrowsePathsToNodeIdsResponseInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize
	#define EXT_OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize
	#define GET_OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize" ) 
	#define CAL_OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize pICmpOPCUAStack->IOpcUaTranslateBrowsePathsToNodeIdsResponseInitialize
	#define CHK_OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize  CAL_CMEXPAPI( "OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize  PFOPCUATRANSLATEBROWSEPATHSTONODEIDSRESPONSEINITIALIZE pfOpcUaTranslateBrowsePathsToNodeIdsResponseInitialize;
	#define EXT_OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize  extern PFOPCUATRANSLATEBROWSEPATHSTONODEIDSRESPONSEINITIALIZE pfOpcUaTranslateBrowsePathsToNodeIdsResponseInitialize;
	#define GET_OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize(fl)  s_pfCMGetAPI2( "OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaTranslateBrowsePathsToNodeIdsResponseInitialize, (fl), 0, 0)
	#define CAL_OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize  pfOpcUaTranslateBrowsePathsToNodeIdsResponseInitialize
	#define CHK_OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize  (pfOpcUaTranslateBrowsePathsToNodeIdsResponseInitialize != NULL)
	#define EXP_OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize", (RTS_UINTPTR)OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaTranslateBrowsePathsToNodeIdsResponseClear(OpcUa_TranslateBrowsePathsToNodeIdsResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUATRANSLATEBROWSEPATHSTONODEIDSRESPONSECLEAR) (OpcUa_TranslateBrowsePathsToNodeIdsResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUATRANSLATEBROWSEPATHSTONODEIDSRESPONSECLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaTranslateBrowsePathsToNodeIdsResponseClear
	#define EXT_OpcUaTranslateBrowsePathsToNodeIdsResponseClear
	#define GET_OpcUaTranslateBrowsePathsToNodeIdsResponseClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaTranslateBrowsePathsToNodeIdsResponseClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaTranslateBrowsePathsToNodeIdsResponseClear  FALSE
	#define EXP_OpcUaTranslateBrowsePathsToNodeIdsResponseClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaTranslateBrowsePathsToNodeIdsResponseClear
	#define EXT_OpcUaTranslateBrowsePathsToNodeIdsResponseClear
	#define GET_OpcUaTranslateBrowsePathsToNodeIdsResponseClear(fl)  CAL_CMGETAPI( "OpcUaTranslateBrowsePathsToNodeIdsResponseClear" ) 
	#define CAL_OpcUaTranslateBrowsePathsToNodeIdsResponseClear  OpcUaTranslateBrowsePathsToNodeIdsResponseClear
	#define CHK_OpcUaTranslateBrowsePathsToNodeIdsResponseClear  TRUE
	#define EXP_OpcUaTranslateBrowsePathsToNodeIdsResponseClear  CAL_CMEXPAPI( "OpcUaTranslateBrowsePathsToNodeIdsResponseClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaTranslateBrowsePathsToNodeIdsResponseClear
	#define EXT_OpcUaTranslateBrowsePathsToNodeIdsResponseClear
	#define GET_OpcUaTranslateBrowsePathsToNodeIdsResponseClear(fl)  CAL_CMGETAPI( "OpcUaTranslateBrowsePathsToNodeIdsResponseClear" ) 
	#define CAL_OpcUaTranslateBrowsePathsToNodeIdsResponseClear  OpcUaTranslateBrowsePathsToNodeIdsResponseClear
	#define CHK_OpcUaTranslateBrowsePathsToNodeIdsResponseClear  TRUE
	#define EXP_OpcUaTranslateBrowsePathsToNodeIdsResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaTranslateBrowsePathsToNodeIdsResponseClear", (RTS_UINTPTR)OpcUaTranslateBrowsePathsToNodeIdsResponseClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaTranslateBrowsePathsToNodeIdsResponseClear
	#define EXT_CmpOPCUAStackOpcUaTranslateBrowsePathsToNodeIdsResponseClear
	#define GET_CmpOPCUAStackOpcUaTranslateBrowsePathsToNodeIdsResponseClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaTranslateBrowsePathsToNodeIdsResponseClear pICmpOPCUAStack->IOpcUaTranslateBrowsePathsToNodeIdsResponseClear
	#define CHK_CmpOPCUAStackOpcUaTranslateBrowsePathsToNodeIdsResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaTranslateBrowsePathsToNodeIdsResponseClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaTranslateBrowsePathsToNodeIdsResponseClear
	#define EXT_OpcUaTranslateBrowsePathsToNodeIdsResponseClear
	#define GET_OpcUaTranslateBrowsePathsToNodeIdsResponseClear(fl)  CAL_CMGETAPI( "OpcUaTranslateBrowsePathsToNodeIdsResponseClear" ) 
	#define CAL_OpcUaTranslateBrowsePathsToNodeIdsResponseClear pICmpOPCUAStack->IOpcUaTranslateBrowsePathsToNodeIdsResponseClear
	#define CHK_OpcUaTranslateBrowsePathsToNodeIdsResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaTranslateBrowsePathsToNodeIdsResponseClear  CAL_CMEXPAPI( "OpcUaTranslateBrowsePathsToNodeIdsResponseClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaTranslateBrowsePathsToNodeIdsResponseClear  PFOPCUATRANSLATEBROWSEPATHSTONODEIDSRESPONSECLEAR pfOpcUaTranslateBrowsePathsToNodeIdsResponseClear;
	#define EXT_OpcUaTranslateBrowsePathsToNodeIdsResponseClear  extern PFOPCUATRANSLATEBROWSEPATHSTONODEIDSRESPONSECLEAR pfOpcUaTranslateBrowsePathsToNodeIdsResponseClear;
	#define GET_OpcUaTranslateBrowsePathsToNodeIdsResponseClear(fl)  s_pfCMGetAPI2( "OpcUaTranslateBrowsePathsToNodeIdsResponseClear", (RTS_VOID_FCTPTR *)&pfOpcUaTranslateBrowsePathsToNodeIdsResponseClear, (fl), 0, 0)
	#define CAL_OpcUaTranslateBrowsePathsToNodeIdsResponseClear  pfOpcUaTranslateBrowsePathsToNodeIdsResponseClear
	#define CHK_OpcUaTranslateBrowsePathsToNodeIdsResponseClear  (pfOpcUaTranslateBrowsePathsToNodeIdsResponseClear != NULL)
	#define EXP_OpcUaTranslateBrowsePathsToNodeIdsResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaTranslateBrowsePathsToNodeIdsResponseClear", (RTS_UINTPTR)OpcUaTranslateBrowsePathsToNodeIdsResponseClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaRegisterNodesRequestInitialize(OpcUa_RegisterNodesRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAREGISTERNODESREQUESTINITIALIZE) (OpcUa_RegisterNodesRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAREGISTERNODESREQUESTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaRegisterNodesRequestInitialize
	#define EXT_OpcUaRegisterNodesRequestInitialize
	#define GET_OpcUaRegisterNodesRequestInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaRegisterNodesRequestInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaRegisterNodesRequestInitialize  FALSE
	#define EXP_OpcUaRegisterNodesRequestInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaRegisterNodesRequestInitialize
	#define EXT_OpcUaRegisterNodesRequestInitialize
	#define GET_OpcUaRegisterNodesRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaRegisterNodesRequestInitialize" ) 
	#define CAL_OpcUaRegisterNodesRequestInitialize  OpcUaRegisterNodesRequestInitialize
	#define CHK_OpcUaRegisterNodesRequestInitialize  TRUE
	#define EXP_OpcUaRegisterNodesRequestInitialize  CAL_CMEXPAPI( "OpcUaRegisterNodesRequestInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaRegisterNodesRequestInitialize
	#define EXT_OpcUaRegisterNodesRequestInitialize
	#define GET_OpcUaRegisterNodesRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaRegisterNodesRequestInitialize" ) 
	#define CAL_OpcUaRegisterNodesRequestInitialize  OpcUaRegisterNodesRequestInitialize
	#define CHK_OpcUaRegisterNodesRequestInitialize  TRUE
	#define EXP_OpcUaRegisterNodesRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaRegisterNodesRequestInitialize", (RTS_UINTPTR)OpcUaRegisterNodesRequestInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaRegisterNodesRequestInitialize
	#define EXT_CmpOPCUAStackOpcUaRegisterNodesRequestInitialize
	#define GET_CmpOPCUAStackOpcUaRegisterNodesRequestInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaRegisterNodesRequestInitialize pICmpOPCUAStack->IOpcUaRegisterNodesRequestInitialize
	#define CHK_CmpOPCUAStackOpcUaRegisterNodesRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaRegisterNodesRequestInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaRegisterNodesRequestInitialize
	#define EXT_OpcUaRegisterNodesRequestInitialize
	#define GET_OpcUaRegisterNodesRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaRegisterNodesRequestInitialize" ) 
	#define CAL_OpcUaRegisterNodesRequestInitialize pICmpOPCUAStack->IOpcUaRegisterNodesRequestInitialize
	#define CHK_OpcUaRegisterNodesRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaRegisterNodesRequestInitialize  CAL_CMEXPAPI( "OpcUaRegisterNodesRequestInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaRegisterNodesRequestInitialize  PFOPCUAREGISTERNODESREQUESTINITIALIZE pfOpcUaRegisterNodesRequestInitialize;
	#define EXT_OpcUaRegisterNodesRequestInitialize  extern PFOPCUAREGISTERNODESREQUESTINITIALIZE pfOpcUaRegisterNodesRequestInitialize;
	#define GET_OpcUaRegisterNodesRequestInitialize(fl)  s_pfCMGetAPI2( "OpcUaRegisterNodesRequestInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaRegisterNodesRequestInitialize, (fl), 0, 0)
	#define CAL_OpcUaRegisterNodesRequestInitialize  pfOpcUaRegisterNodesRequestInitialize
	#define CHK_OpcUaRegisterNodesRequestInitialize  (pfOpcUaRegisterNodesRequestInitialize != NULL)
	#define EXP_OpcUaRegisterNodesRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaRegisterNodesRequestInitialize", (RTS_UINTPTR)OpcUaRegisterNodesRequestInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaRegisterNodesRequestClear(OpcUa_RegisterNodesRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAREGISTERNODESREQUESTCLEAR) (OpcUa_RegisterNodesRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAREGISTERNODESREQUESTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaRegisterNodesRequestClear
	#define EXT_OpcUaRegisterNodesRequestClear
	#define GET_OpcUaRegisterNodesRequestClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaRegisterNodesRequestClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaRegisterNodesRequestClear  FALSE
	#define EXP_OpcUaRegisterNodesRequestClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaRegisterNodesRequestClear
	#define EXT_OpcUaRegisterNodesRequestClear
	#define GET_OpcUaRegisterNodesRequestClear(fl)  CAL_CMGETAPI( "OpcUaRegisterNodesRequestClear" ) 
	#define CAL_OpcUaRegisterNodesRequestClear  OpcUaRegisterNodesRequestClear
	#define CHK_OpcUaRegisterNodesRequestClear  TRUE
	#define EXP_OpcUaRegisterNodesRequestClear  CAL_CMEXPAPI( "OpcUaRegisterNodesRequestClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaRegisterNodesRequestClear
	#define EXT_OpcUaRegisterNodesRequestClear
	#define GET_OpcUaRegisterNodesRequestClear(fl)  CAL_CMGETAPI( "OpcUaRegisterNodesRequestClear" ) 
	#define CAL_OpcUaRegisterNodesRequestClear  OpcUaRegisterNodesRequestClear
	#define CHK_OpcUaRegisterNodesRequestClear  TRUE
	#define EXP_OpcUaRegisterNodesRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaRegisterNodesRequestClear", (RTS_UINTPTR)OpcUaRegisterNodesRequestClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaRegisterNodesRequestClear
	#define EXT_CmpOPCUAStackOpcUaRegisterNodesRequestClear
	#define GET_CmpOPCUAStackOpcUaRegisterNodesRequestClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaRegisterNodesRequestClear pICmpOPCUAStack->IOpcUaRegisterNodesRequestClear
	#define CHK_CmpOPCUAStackOpcUaRegisterNodesRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaRegisterNodesRequestClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaRegisterNodesRequestClear
	#define EXT_OpcUaRegisterNodesRequestClear
	#define GET_OpcUaRegisterNodesRequestClear(fl)  CAL_CMGETAPI( "OpcUaRegisterNodesRequestClear" ) 
	#define CAL_OpcUaRegisterNodesRequestClear pICmpOPCUAStack->IOpcUaRegisterNodesRequestClear
	#define CHK_OpcUaRegisterNodesRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaRegisterNodesRequestClear  CAL_CMEXPAPI( "OpcUaRegisterNodesRequestClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaRegisterNodesRequestClear  PFOPCUAREGISTERNODESREQUESTCLEAR pfOpcUaRegisterNodesRequestClear;
	#define EXT_OpcUaRegisterNodesRequestClear  extern PFOPCUAREGISTERNODESREQUESTCLEAR pfOpcUaRegisterNodesRequestClear;
	#define GET_OpcUaRegisterNodesRequestClear(fl)  s_pfCMGetAPI2( "OpcUaRegisterNodesRequestClear", (RTS_VOID_FCTPTR *)&pfOpcUaRegisterNodesRequestClear, (fl), 0, 0)
	#define CAL_OpcUaRegisterNodesRequestClear  pfOpcUaRegisterNodesRequestClear
	#define CHK_OpcUaRegisterNodesRequestClear  (pfOpcUaRegisterNodesRequestClear != NULL)
	#define EXP_OpcUaRegisterNodesRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaRegisterNodesRequestClear", (RTS_UINTPTR)OpcUaRegisterNodesRequestClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaRegisterNodesResponseInitialize(OpcUa_RegisterNodesResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAREGISTERNODESRESPONSEINITIALIZE) (OpcUa_RegisterNodesResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAREGISTERNODESRESPONSEINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaRegisterNodesResponseInitialize
	#define EXT_OpcUaRegisterNodesResponseInitialize
	#define GET_OpcUaRegisterNodesResponseInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaRegisterNodesResponseInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaRegisterNodesResponseInitialize  FALSE
	#define EXP_OpcUaRegisterNodesResponseInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaRegisterNodesResponseInitialize
	#define EXT_OpcUaRegisterNodesResponseInitialize
	#define GET_OpcUaRegisterNodesResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaRegisterNodesResponseInitialize" ) 
	#define CAL_OpcUaRegisterNodesResponseInitialize  OpcUaRegisterNodesResponseInitialize
	#define CHK_OpcUaRegisterNodesResponseInitialize  TRUE
	#define EXP_OpcUaRegisterNodesResponseInitialize  CAL_CMEXPAPI( "OpcUaRegisterNodesResponseInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaRegisterNodesResponseInitialize
	#define EXT_OpcUaRegisterNodesResponseInitialize
	#define GET_OpcUaRegisterNodesResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaRegisterNodesResponseInitialize" ) 
	#define CAL_OpcUaRegisterNodesResponseInitialize  OpcUaRegisterNodesResponseInitialize
	#define CHK_OpcUaRegisterNodesResponseInitialize  TRUE
	#define EXP_OpcUaRegisterNodesResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaRegisterNodesResponseInitialize", (RTS_UINTPTR)OpcUaRegisterNodesResponseInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaRegisterNodesResponseInitialize
	#define EXT_CmpOPCUAStackOpcUaRegisterNodesResponseInitialize
	#define GET_CmpOPCUAStackOpcUaRegisterNodesResponseInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaRegisterNodesResponseInitialize pICmpOPCUAStack->IOpcUaRegisterNodesResponseInitialize
	#define CHK_CmpOPCUAStackOpcUaRegisterNodesResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaRegisterNodesResponseInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaRegisterNodesResponseInitialize
	#define EXT_OpcUaRegisterNodesResponseInitialize
	#define GET_OpcUaRegisterNodesResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaRegisterNodesResponseInitialize" ) 
	#define CAL_OpcUaRegisterNodesResponseInitialize pICmpOPCUAStack->IOpcUaRegisterNodesResponseInitialize
	#define CHK_OpcUaRegisterNodesResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaRegisterNodesResponseInitialize  CAL_CMEXPAPI( "OpcUaRegisterNodesResponseInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaRegisterNodesResponseInitialize  PFOPCUAREGISTERNODESRESPONSEINITIALIZE pfOpcUaRegisterNodesResponseInitialize;
	#define EXT_OpcUaRegisterNodesResponseInitialize  extern PFOPCUAREGISTERNODESRESPONSEINITIALIZE pfOpcUaRegisterNodesResponseInitialize;
	#define GET_OpcUaRegisterNodesResponseInitialize(fl)  s_pfCMGetAPI2( "OpcUaRegisterNodesResponseInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaRegisterNodesResponseInitialize, (fl), 0, 0)
	#define CAL_OpcUaRegisterNodesResponseInitialize  pfOpcUaRegisterNodesResponseInitialize
	#define CHK_OpcUaRegisterNodesResponseInitialize  (pfOpcUaRegisterNodesResponseInitialize != NULL)
	#define EXP_OpcUaRegisterNodesResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaRegisterNodesResponseInitialize", (RTS_UINTPTR)OpcUaRegisterNodesResponseInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaRegisterNodesResponseClear(OpcUa_RegisterNodesResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAREGISTERNODESRESPONSECLEAR) (OpcUa_RegisterNodesResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAREGISTERNODESRESPONSECLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaRegisterNodesResponseClear
	#define EXT_OpcUaRegisterNodesResponseClear
	#define GET_OpcUaRegisterNodesResponseClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaRegisterNodesResponseClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaRegisterNodesResponseClear  FALSE
	#define EXP_OpcUaRegisterNodesResponseClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaRegisterNodesResponseClear
	#define EXT_OpcUaRegisterNodesResponseClear
	#define GET_OpcUaRegisterNodesResponseClear(fl)  CAL_CMGETAPI( "OpcUaRegisterNodesResponseClear" ) 
	#define CAL_OpcUaRegisterNodesResponseClear  OpcUaRegisterNodesResponseClear
	#define CHK_OpcUaRegisterNodesResponseClear  TRUE
	#define EXP_OpcUaRegisterNodesResponseClear  CAL_CMEXPAPI( "OpcUaRegisterNodesResponseClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaRegisterNodesResponseClear
	#define EXT_OpcUaRegisterNodesResponseClear
	#define GET_OpcUaRegisterNodesResponseClear(fl)  CAL_CMGETAPI( "OpcUaRegisterNodesResponseClear" ) 
	#define CAL_OpcUaRegisterNodesResponseClear  OpcUaRegisterNodesResponseClear
	#define CHK_OpcUaRegisterNodesResponseClear  TRUE
	#define EXP_OpcUaRegisterNodesResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaRegisterNodesResponseClear", (RTS_UINTPTR)OpcUaRegisterNodesResponseClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaRegisterNodesResponseClear
	#define EXT_CmpOPCUAStackOpcUaRegisterNodesResponseClear
	#define GET_CmpOPCUAStackOpcUaRegisterNodesResponseClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaRegisterNodesResponseClear pICmpOPCUAStack->IOpcUaRegisterNodesResponseClear
	#define CHK_CmpOPCUAStackOpcUaRegisterNodesResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaRegisterNodesResponseClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaRegisterNodesResponseClear
	#define EXT_OpcUaRegisterNodesResponseClear
	#define GET_OpcUaRegisterNodesResponseClear(fl)  CAL_CMGETAPI( "OpcUaRegisterNodesResponseClear" ) 
	#define CAL_OpcUaRegisterNodesResponseClear pICmpOPCUAStack->IOpcUaRegisterNodesResponseClear
	#define CHK_OpcUaRegisterNodesResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaRegisterNodesResponseClear  CAL_CMEXPAPI( "OpcUaRegisterNodesResponseClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaRegisterNodesResponseClear  PFOPCUAREGISTERNODESRESPONSECLEAR pfOpcUaRegisterNodesResponseClear;
	#define EXT_OpcUaRegisterNodesResponseClear  extern PFOPCUAREGISTERNODESRESPONSECLEAR pfOpcUaRegisterNodesResponseClear;
	#define GET_OpcUaRegisterNodesResponseClear(fl)  s_pfCMGetAPI2( "OpcUaRegisterNodesResponseClear", (RTS_VOID_FCTPTR *)&pfOpcUaRegisterNodesResponseClear, (fl), 0, 0)
	#define CAL_OpcUaRegisterNodesResponseClear  pfOpcUaRegisterNodesResponseClear
	#define CHK_OpcUaRegisterNodesResponseClear  (pfOpcUaRegisterNodesResponseClear != NULL)
	#define EXP_OpcUaRegisterNodesResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaRegisterNodesResponseClear", (RTS_UINTPTR)OpcUaRegisterNodesResponseClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaUnregisterNodesRequestInitialize(OpcUa_UnregisterNodesRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAUNREGISTERNODESREQUESTINITIALIZE) (OpcUa_UnregisterNodesRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAUNREGISTERNODESREQUESTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaUnregisterNodesRequestInitialize
	#define EXT_OpcUaUnregisterNodesRequestInitialize
	#define GET_OpcUaUnregisterNodesRequestInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaUnregisterNodesRequestInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaUnregisterNodesRequestInitialize  FALSE
	#define EXP_OpcUaUnregisterNodesRequestInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaUnregisterNodesRequestInitialize
	#define EXT_OpcUaUnregisterNodesRequestInitialize
	#define GET_OpcUaUnregisterNodesRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaUnregisterNodesRequestInitialize" ) 
	#define CAL_OpcUaUnregisterNodesRequestInitialize  OpcUaUnregisterNodesRequestInitialize
	#define CHK_OpcUaUnregisterNodesRequestInitialize  TRUE
	#define EXP_OpcUaUnregisterNodesRequestInitialize  CAL_CMEXPAPI( "OpcUaUnregisterNodesRequestInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaUnregisterNodesRequestInitialize
	#define EXT_OpcUaUnregisterNodesRequestInitialize
	#define GET_OpcUaUnregisterNodesRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaUnregisterNodesRequestInitialize" ) 
	#define CAL_OpcUaUnregisterNodesRequestInitialize  OpcUaUnregisterNodesRequestInitialize
	#define CHK_OpcUaUnregisterNodesRequestInitialize  TRUE
	#define EXP_OpcUaUnregisterNodesRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaUnregisterNodesRequestInitialize", (RTS_UINTPTR)OpcUaUnregisterNodesRequestInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaUnregisterNodesRequestInitialize
	#define EXT_CmpOPCUAStackOpcUaUnregisterNodesRequestInitialize
	#define GET_CmpOPCUAStackOpcUaUnregisterNodesRequestInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaUnregisterNodesRequestInitialize pICmpOPCUAStack->IOpcUaUnregisterNodesRequestInitialize
	#define CHK_CmpOPCUAStackOpcUaUnregisterNodesRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaUnregisterNodesRequestInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaUnregisterNodesRequestInitialize
	#define EXT_OpcUaUnregisterNodesRequestInitialize
	#define GET_OpcUaUnregisterNodesRequestInitialize(fl)  CAL_CMGETAPI( "OpcUaUnregisterNodesRequestInitialize" ) 
	#define CAL_OpcUaUnregisterNodesRequestInitialize pICmpOPCUAStack->IOpcUaUnregisterNodesRequestInitialize
	#define CHK_OpcUaUnregisterNodesRequestInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaUnregisterNodesRequestInitialize  CAL_CMEXPAPI( "OpcUaUnregisterNodesRequestInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaUnregisterNodesRequestInitialize  PFOPCUAUNREGISTERNODESREQUESTINITIALIZE pfOpcUaUnregisterNodesRequestInitialize;
	#define EXT_OpcUaUnregisterNodesRequestInitialize  extern PFOPCUAUNREGISTERNODESREQUESTINITIALIZE pfOpcUaUnregisterNodesRequestInitialize;
	#define GET_OpcUaUnregisterNodesRequestInitialize(fl)  s_pfCMGetAPI2( "OpcUaUnregisterNodesRequestInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaUnregisterNodesRequestInitialize, (fl), 0, 0)
	#define CAL_OpcUaUnregisterNodesRequestInitialize  pfOpcUaUnregisterNodesRequestInitialize
	#define CHK_OpcUaUnregisterNodesRequestInitialize  (pfOpcUaUnregisterNodesRequestInitialize != NULL)
	#define EXP_OpcUaUnregisterNodesRequestInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaUnregisterNodesRequestInitialize", (RTS_UINTPTR)OpcUaUnregisterNodesRequestInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaUnregisterNodesRequestClear(OpcUa_UnregisterNodesRequest* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAUNREGISTERNODESREQUESTCLEAR) (OpcUa_UnregisterNodesRequest* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAUNREGISTERNODESREQUESTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaUnregisterNodesRequestClear
	#define EXT_OpcUaUnregisterNodesRequestClear
	#define GET_OpcUaUnregisterNodesRequestClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaUnregisterNodesRequestClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaUnregisterNodesRequestClear  FALSE
	#define EXP_OpcUaUnregisterNodesRequestClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaUnregisterNodesRequestClear
	#define EXT_OpcUaUnregisterNodesRequestClear
	#define GET_OpcUaUnregisterNodesRequestClear(fl)  CAL_CMGETAPI( "OpcUaUnregisterNodesRequestClear" ) 
	#define CAL_OpcUaUnregisterNodesRequestClear  OpcUaUnregisterNodesRequestClear
	#define CHK_OpcUaUnregisterNodesRequestClear  TRUE
	#define EXP_OpcUaUnregisterNodesRequestClear  CAL_CMEXPAPI( "OpcUaUnregisterNodesRequestClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaUnregisterNodesRequestClear
	#define EXT_OpcUaUnregisterNodesRequestClear
	#define GET_OpcUaUnregisterNodesRequestClear(fl)  CAL_CMGETAPI( "OpcUaUnregisterNodesRequestClear" ) 
	#define CAL_OpcUaUnregisterNodesRequestClear  OpcUaUnregisterNodesRequestClear
	#define CHK_OpcUaUnregisterNodesRequestClear  TRUE
	#define EXP_OpcUaUnregisterNodesRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaUnregisterNodesRequestClear", (RTS_UINTPTR)OpcUaUnregisterNodesRequestClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaUnregisterNodesRequestClear
	#define EXT_CmpOPCUAStackOpcUaUnregisterNodesRequestClear
	#define GET_CmpOPCUAStackOpcUaUnregisterNodesRequestClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaUnregisterNodesRequestClear pICmpOPCUAStack->IOpcUaUnregisterNodesRequestClear
	#define CHK_CmpOPCUAStackOpcUaUnregisterNodesRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaUnregisterNodesRequestClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaUnregisterNodesRequestClear
	#define EXT_OpcUaUnregisterNodesRequestClear
	#define GET_OpcUaUnregisterNodesRequestClear(fl)  CAL_CMGETAPI( "OpcUaUnregisterNodesRequestClear" ) 
	#define CAL_OpcUaUnregisterNodesRequestClear pICmpOPCUAStack->IOpcUaUnregisterNodesRequestClear
	#define CHK_OpcUaUnregisterNodesRequestClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaUnregisterNodesRequestClear  CAL_CMEXPAPI( "OpcUaUnregisterNodesRequestClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaUnregisterNodesRequestClear  PFOPCUAUNREGISTERNODESREQUESTCLEAR pfOpcUaUnregisterNodesRequestClear;
	#define EXT_OpcUaUnregisterNodesRequestClear  extern PFOPCUAUNREGISTERNODESREQUESTCLEAR pfOpcUaUnregisterNodesRequestClear;
	#define GET_OpcUaUnregisterNodesRequestClear(fl)  s_pfCMGetAPI2( "OpcUaUnregisterNodesRequestClear", (RTS_VOID_FCTPTR *)&pfOpcUaUnregisterNodesRequestClear, (fl), 0, 0)
	#define CAL_OpcUaUnregisterNodesRequestClear  pfOpcUaUnregisterNodesRequestClear
	#define CHK_OpcUaUnregisterNodesRequestClear  (pfOpcUaUnregisterNodesRequestClear != NULL)
	#define EXP_OpcUaUnregisterNodesRequestClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaUnregisterNodesRequestClear", (RTS_UINTPTR)OpcUaUnregisterNodesRequestClear, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaUnregisterNodesResponseInitialize(OpcUa_UnregisterNodesResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAUNREGISTERNODESRESPONSEINITIALIZE) (OpcUa_UnregisterNodesResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAUNREGISTERNODESRESPONSEINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaUnregisterNodesResponseInitialize
	#define EXT_OpcUaUnregisterNodesResponseInitialize
	#define GET_OpcUaUnregisterNodesResponseInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaUnregisterNodesResponseInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaUnregisterNodesResponseInitialize  FALSE
	#define EXP_OpcUaUnregisterNodesResponseInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaUnregisterNodesResponseInitialize
	#define EXT_OpcUaUnregisterNodesResponseInitialize
	#define GET_OpcUaUnregisterNodesResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaUnregisterNodesResponseInitialize" ) 
	#define CAL_OpcUaUnregisterNodesResponseInitialize  OpcUaUnregisterNodesResponseInitialize
	#define CHK_OpcUaUnregisterNodesResponseInitialize  TRUE
	#define EXP_OpcUaUnregisterNodesResponseInitialize  CAL_CMEXPAPI( "OpcUaUnregisterNodesResponseInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaUnregisterNodesResponseInitialize
	#define EXT_OpcUaUnregisterNodesResponseInitialize
	#define GET_OpcUaUnregisterNodesResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaUnregisterNodesResponseInitialize" ) 
	#define CAL_OpcUaUnregisterNodesResponseInitialize  OpcUaUnregisterNodesResponseInitialize
	#define CHK_OpcUaUnregisterNodesResponseInitialize  TRUE
	#define EXP_OpcUaUnregisterNodesResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaUnregisterNodesResponseInitialize", (RTS_UINTPTR)OpcUaUnregisterNodesResponseInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaUnregisterNodesResponseInitialize
	#define EXT_CmpOPCUAStackOpcUaUnregisterNodesResponseInitialize
	#define GET_CmpOPCUAStackOpcUaUnregisterNodesResponseInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaUnregisterNodesResponseInitialize pICmpOPCUAStack->IOpcUaUnregisterNodesResponseInitialize
	#define CHK_CmpOPCUAStackOpcUaUnregisterNodesResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaUnregisterNodesResponseInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaUnregisterNodesResponseInitialize
	#define EXT_OpcUaUnregisterNodesResponseInitialize
	#define GET_OpcUaUnregisterNodesResponseInitialize(fl)  CAL_CMGETAPI( "OpcUaUnregisterNodesResponseInitialize" ) 
	#define CAL_OpcUaUnregisterNodesResponseInitialize pICmpOPCUAStack->IOpcUaUnregisterNodesResponseInitialize
	#define CHK_OpcUaUnregisterNodesResponseInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaUnregisterNodesResponseInitialize  CAL_CMEXPAPI( "OpcUaUnregisterNodesResponseInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaUnregisterNodesResponseInitialize  PFOPCUAUNREGISTERNODESRESPONSEINITIALIZE pfOpcUaUnregisterNodesResponseInitialize;
	#define EXT_OpcUaUnregisterNodesResponseInitialize  extern PFOPCUAUNREGISTERNODESRESPONSEINITIALIZE pfOpcUaUnregisterNodesResponseInitialize;
	#define GET_OpcUaUnregisterNodesResponseInitialize(fl)  s_pfCMGetAPI2( "OpcUaUnregisterNodesResponseInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaUnregisterNodesResponseInitialize, (fl), 0, 0)
	#define CAL_OpcUaUnregisterNodesResponseInitialize  pfOpcUaUnregisterNodesResponseInitialize
	#define CHK_OpcUaUnregisterNodesResponseInitialize  (pfOpcUaUnregisterNodesResponseInitialize != NULL)
	#define EXP_OpcUaUnregisterNodesResponseInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaUnregisterNodesResponseInitialize", (RTS_UINTPTR)OpcUaUnregisterNodesResponseInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaUnregisterNodesResponseClear(OpcUa_UnregisterNodesResponse* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAUNREGISTERNODESRESPONSECLEAR) (OpcUa_UnregisterNodesResponse* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAUNREGISTERNODESRESPONSECLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaUnregisterNodesResponseClear
	#define EXT_OpcUaUnregisterNodesResponseClear
	#define GET_OpcUaUnregisterNodesResponseClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaUnregisterNodesResponseClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaUnregisterNodesResponseClear  FALSE
	#define EXP_OpcUaUnregisterNodesResponseClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaUnregisterNodesResponseClear
	#define EXT_OpcUaUnregisterNodesResponseClear
	#define GET_OpcUaUnregisterNodesResponseClear(fl)  CAL_CMGETAPI( "OpcUaUnregisterNodesResponseClear" ) 
	#define CAL_OpcUaUnregisterNodesResponseClear  OpcUaUnregisterNodesResponseClear
	#define CHK_OpcUaUnregisterNodesResponseClear  TRUE
	#define EXP_OpcUaUnregisterNodesResponseClear  CAL_CMEXPAPI( "OpcUaUnregisterNodesResponseClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaUnregisterNodesResponseClear
	#define EXT_OpcUaUnregisterNodesResponseClear
	#define GET_OpcUaUnregisterNodesResponseClear(fl)  CAL_CMGETAPI( "OpcUaUnregisterNodesResponseClear" ) 
	#define CAL_OpcUaUnregisterNodesResponseClear  OpcUaUnregisterNodesResponseClear
	#define CHK_OpcUaUnregisterNodesResponseClear  TRUE
	#define EXP_OpcUaUnregisterNodesResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaUnregisterNodesResponseClear", (RTS_UINTPTR)OpcUaUnregisterNodesResponseClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaUnregisterNodesResponseClear
	#define EXT_CmpOPCUAStackOpcUaUnregisterNodesResponseClear
	#define GET_CmpOPCUAStackOpcUaUnregisterNodesResponseClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaUnregisterNodesResponseClear pICmpOPCUAStack->IOpcUaUnregisterNodesResponseClear
	#define CHK_CmpOPCUAStackOpcUaUnregisterNodesResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaUnregisterNodesResponseClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaUnregisterNodesResponseClear
	#define EXT_OpcUaUnregisterNodesResponseClear
	#define GET_OpcUaUnregisterNodesResponseClear(fl)  CAL_CMGETAPI( "OpcUaUnregisterNodesResponseClear" ) 
	#define CAL_OpcUaUnregisterNodesResponseClear pICmpOPCUAStack->IOpcUaUnregisterNodesResponseClear
	#define CHK_OpcUaUnregisterNodesResponseClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaUnregisterNodesResponseClear  CAL_CMEXPAPI( "OpcUaUnregisterNodesResponseClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaUnregisterNodesResponseClear  PFOPCUAUNREGISTERNODESRESPONSECLEAR pfOpcUaUnregisterNodesResponseClear;
	#define EXT_OpcUaUnregisterNodesResponseClear  extern PFOPCUAUNREGISTERNODESRESPONSECLEAR pfOpcUaUnregisterNodesResponseClear;
	#define GET_OpcUaUnregisterNodesResponseClear(fl)  s_pfCMGetAPI2( "OpcUaUnregisterNodesResponseClear", (RTS_VOID_FCTPTR *)&pfOpcUaUnregisterNodesResponseClear, (fl), 0, 0)
	#define CAL_OpcUaUnregisterNodesResponseClear  pfOpcUaUnregisterNodesResponseClear
	#define CHK_OpcUaUnregisterNodesResponseClear  (pfOpcUaUnregisterNodesResponseClear != NULL)
	#define EXP_OpcUaUnregisterNodesResponseClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaUnregisterNodesResponseClear", (RTS_UINTPTR)OpcUaUnregisterNodesResponseClear, 0, 0) 
#endif




OpcUa_StatusCode CDECL OpcUaListCreate(OpcUa_List** ppList);
typedef OpcUa_StatusCode (CDECL * PFOPCUALISTCREATE) (OpcUa_List** ppList);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUALISTCREATE_NOTIMPLEMENTED)
	#define USE_OpcUaListCreate
	#define EXT_OpcUaListCreate
	#define GET_OpcUaListCreate(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaListCreate(p0)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaListCreate  FALSE
	#define EXP_OpcUaListCreate  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaListCreate
	#define EXT_OpcUaListCreate
	#define GET_OpcUaListCreate(fl)  CAL_CMGETAPI( "OpcUaListCreate" ) 
	#define CAL_OpcUaListCreate  OpcUaListCreate
	#define CHK_OpcUaListCreate  TRUE
	#define EXP_OpcUaListCreate  CAL_CMEXPAPI( "OpcUaListCreate" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaListCreate
	#define EXT_OpcUaListCreate
	#define GET_OpcUaListCreate(fl)  CAL_CMGETAPI( "OpcUaListCreate" ) 
	#define CAL_OpcUaListCreate  OpcUaListCreate
	#define CHK_OpcUaListCreate  TRUE
	#define EXP_OpcUaListCreate  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListCreate", (RTS_UINTPTR)OpcUaListCreate, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaListCreate
	#define EXT_CmpOPCUAStackOpcUaListCreate
	#define GET_CmpOPCUAStackOpcUaListCreate  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaListCreate pICmpOPCUAStack->IOpcUaListCreate
	#define CHK_CmpOPCUAStackOpcUaListCreate (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaListCreate  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaListCreate
	#define EXT_OpcUaListCreate
	#define GET_OpcUaListCreate(fl)  CAL_CMGETAPI( "OpcUaListCreate" ) 
	#define CAL_OpcUaListCreate pICmpOPCUAStack->IOpcUaListCreate
	#define CHK_OpcUaListCreate (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaListCreate  CAL_CMEXPAPI( "OpcUaListCreate" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaListCreate  PFOPCUALISTCREATE pfOpcUaListCreate;
	#define EXT_OpcUaListCreate  extern PFOPCUALISTCREATE pfOpcUaListCreate;
	#define GET_OpcUaListCreate(fl)  s_pfCMGetAPI2( "OpcUaListCreate", (RTS_VOID_FCTPTR *)&pfOpcUaListCreate, (fl), 0, 0)
	#define CAL_OpcUaListCreate  pfOpcUaListCreate
	#define CHK_OpcUaListCreate  (pfOpcUaListCreate != NULL)
	#define EXP_OpcUaListCreate  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListCreate", (RTS_UINTPTR)OpcUaListCreate, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaListInitialize(OpcUa_List* pList);
typedef OpcUa_StatusCode (CDECL * PFOPCUALISTINITIALIZE) (OpcUa_List* pList);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUALISTINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaListInitialize
	#define EXT_OpcUaListInitialize
	#define GET_OpcUaListInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaListInitialize(p0)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaListInitialize  FALSE
	#define EXP_OpcUaListInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaListInitialize
	#define EXT_OpcUaListInitialize
	#define GET_OpcUaListInitialize(fl)  CAL_CMGETAPI( "OpcUaListInitialize" ) 
	#define CAL_OpcUaListInitialize  OpcUaListInitialize
	#define CHK_OpcUaListInitialize  TRUE
	#define EXP_OpcUaListInitialize  CAL_CMEXPAPI( "OpcUaListInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaListInitialize
	#define EXT_OpcUaListInitialize
	#define GET_OpcUaListInitialize(fl)  CAL_CMGETAPI( "OpcUaListInitialize" ) 
	#define CAL_OpcUaListInitialize  OpcUaListInitialize
	#define CHK_OpcUaListInitialize  TRUE
	#define EXP_OpcUaListInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListInitialize", (RTS_UINTPTR)OpcUaListInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaListInitialize
	#define EXT_CmpOPCUAStackOpcUaListInitialize
	#define GET_CmpOPCUAStackOpcUaListInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaListInitialize pICmpOPCUAStack->IOpcUaListInitialize
	#define CHK_CmpOPCUAStackOpcUaListInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaListInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaListInitialize
	#define EXT_OpcUaListInitialize
	#define GET_OpcUaListInitialize(fl)  CAL_CMGETAPI( "OpcUaListInitialize" ) 
	#define CAL_OpcUaListInitialize pICmpOPCUAStack->IOpcUaListInitialize
	#define CHK_OpcUaListInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaListInitialize  CAL_CMEXPAPI( "OpcUaListInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaListInitialize  PFOPCUALISTINITIALIZE pfOpcUaListInitialize;
	#define EXT_OpcUaListInitialize  extern PFOPCUALISTINITIALIZE pfOpcUaListInitialize;
	#define GET_OpcUaListInitialize(fl)  s_pfCMGetAPI2( "OpcUaListInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaListInitialize, (fl), 0, 0)
	#define CAL_OpcUaListInitialize  pfOpcUaListInitialize
	#define CHK_OpcUaListInitialize  (pfOpcUaListInitialize != NULL)
	#define EXP_OpcUaListInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListInitialize", (RTS_UINTPTR)OpcUaListInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaListClear(OpcUa_List* pList);
typedef OpcUa_Void (CDECL * PFOPCUALISTCLEAR) (OpcUa_List* pList);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUALISTCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaListClear
	#define EXT_OpcUaListClear
	#define GET_OpcUaListClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaListClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaListClear  FALSE
	#define EXP_OpcUaListClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaListClear
	#define EXT_OpcUaListClear
	#define GET_OpcUaListClear(fl)  CAL_CMGETAPI( "OpcUaListClear" ) 
	#define CAL_OpcUaListClear  OpcUaListClear
	#define CHK_OpcUaListClear  TRUE
	#define EXP_OpcUaListClear  CAL_CMEXPAPI( "OpcUaListClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaListClear
	#define EXT_OpcUaListClear
	#define GET_OpcUaListClear(fl)  CAL_CMGETAPI( "OpcUaListClear" ) 
	#define CAL_OpcUaListClear  OpcUaListClear
	#define CHK_OpcUaListClear  TRUE
	#define EXP_OpcUaListClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListClear", (RTS_UINTPTR)OpcUaListClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaListClear
	#define EXT_CmpOPCUAStackOpcUaListClear
	#define GET_CmpOPCUAStackOpcUaListClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaListClear pICmpOPCUAStack->IOpcUaListClear
	#define CHK_CmpOPCUAStackOpcUaListClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaListClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaListClear
	#define EXT_OpcUaListClear
	#define GET_OpcUaListClear(fl)  CAL_CMGETAPI( "OpcUaListClear" ) 
	#define CAL_OpcUaListClear pICmpOPCUAStack->IOpcUaListClear
	#define CHK_OpcUaListClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaListClear  CAL_CMEXPAPI( "OpcUaListClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaListClear  PFOPCUALISTCLEAR pfOpcUaListClear;
	#define EXT_OpcUaListClear  extern PFOPCUALISTCLEAR pfOpcUaListClear;
	#define GET_OpcUaListClear(fl)  s_pfCMGetAPI2( "OpcUaListClear", (RTS_VOID_FCTPTR *)&pfOpcUaListClear, (fl), 0, 0)
	#define CAL_OpcUaListClear  pfOpcUaListClear
	#define CHK_OpcUaListClear  (pfOpcUaListClear != NULL)
	#define EXP_OpcUaListClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListClear", (RTS_UINTPTR)OpcUaListClear, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaListDelete(OpcUa_List** ppList);
typedef OpcUa_Void (CDECL * PFOPCUALISTDELETE) (OpcUa_List** ppList);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUALISTDELETE_NOTIMPLEMENTED)
	#define USE_OpcUaListDelete
	#define EXT_OpcUaListDelete
	#define GET_OpcUaListDelete(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaListDelete(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaListDelete  FALSE
	#define EXP_OpcUaListDelete  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaListDelete
	#define EXT_OpcUaListDelete
	#define GET_OpcUaListDelete(fl)  CAL_CMGETAPI( "OpcUaListDelete" ) 
	#define CAL_OpcUaListDelete  OpcUaListDelete
	#define CHK_OpcUaListDelete  TRUE
	#define EXP_OpcUaListDelete  CAL_CMEXPAPI( "OpcUaListDelete" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaListDelete
	#define EXT_OpcUaListDelete
	#define GET_OpcUaListDelete(fl)  CAL_CMGETAPI( "OpcUaListDelete" ) 
	#define CAL_OpcUaListDelete  OpcUaListDelete
	#define CHK_OpcUaListDelete  TRUE
	#define EXP_OpcUaListDelete  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListDelete", (RTS_UINTPTR)OpcUaListDelete, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaListDelete
	#define EXT_CmpOPCUAStackOpcUaListDelete
	#define GET_CmpOPCUAStackOpcUaListDelete  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaListDelete pICmpOPCUAStack->IOpcUaListDelete
	#define CHK_CmpOPCUAStackOpcUaListDelete (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaListDelete  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaListDelete
	#define EXT_OpcUaListDelete
	#define GET_OpcUaListDelete(fl)  CAL_CMGETAPI( "OpcUaListDelete" ) 
	#define CAL_OpcUaListDelete pICmpOPCUAStack->IOpcUaListDelete
	#define CHK_OpcUaListDelete (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaListDelete  CAL_CMEXPAPI( "OpcUaListDelete" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaListDelete  PFOPCUALISTDELETE pfOpcUaListDelete;
	#define EXT_OpcUaListDelete  extern PFOPCUALISTDELETE pfOpcUaListDelete;
	#define GET_OpcUaListDelete(fl)  s_pfCMGetAPI2( "OpcUaListDelete", (RTS_VOID_FCTPTR *)&pfOpcUaListDelete, (fl), 0, 0)
	#define CAL_OpcUaListDelete  pfOpcUaListDelete
	#define CHK_OpcUaListDelete  (pfOpcUaListDelete != NULL)
	#define EXP_OpcUaListDelete  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListDelete", (RTS_UINTPTR)OpcUaListDelete, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaListEnter(OpcUa_List* pList);
typedef OpcUa_Void (CDECL * PFOPCUALISTENTER) (OpcUa_List* pList);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUALISTENTER_NOTIMPLEMENTED)
	#define USE_OpcUaListEnter
	#define EXT_OpcUaListEnter
	#define GET_OpcUaListEnter(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaListEnter(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaListEnter  FALSE
	#define EXP_OpcUaListEnter  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaListEnter
	#define EXT_OpcUaListEnter
	#define GET_OpcUaListEnter(fl)  CAL_CMGETAPI( "OpcUaListEnter" ) 
	#define CAL_OpcUaListEnter  OpcUaListEnter
	#define CHK_OpcUaListEnter  TRUE
	#define EXP_OpcUaListEnter  CAL_CMEXPAPI( "OpcUaListEnter" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaListEnter
	#define EXT_OpcUaListEnter
	#define GET_OpcUaListEnter(fl)  CAL_CMGETAPI( "OpcUaListEnter" ) 
	#define CAL_OpcUaListEnter  OpcUaListEnter
	#define CHK_OpcUaListEnter  TRUE
	#define EXP_OpcUaListEnter  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListEnter", (RTS_UINTPTR)OpcUaListEnter, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaListEnter
	#define EXT_CmpOPCUAStackOpcUaListEnter
	#define GET_CmpOPCUAStackOpcUaListEnter  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaListEnter pICmpOPCUAStack->IOpcUaListEnter
	#define CHK_CmpOPCUAStackOpcUaListEnter (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaListEnter  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaListEnter
	#define EXT_OpcUaListEnter
	#define GET_OpcUaListEnter(fl)  CAL_CMGETAPI( "OpcUaListEnter" ) 
	#define CAL_OpcUaListEnter pICmpOPCUAStack->IOpcUaListEnter
	#define CHK_OpcUaListEnter (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaListEnter  CAL_CMEXPAPI( "OpcUaListEnter" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaListEnter  PFOPCUALISTENTER pfOpcUaListEnter;
	#define EXT_OpcUaListEnter  extern PFOPCUALISTENTER pfOpcUaListEnter;
	#define GET_OpcUaListEnter(fl)  s_pfCMGetAPI2( "OpcUaListEnter", (RTS_VOID_FCTPTR *)&pfOpcUaListEnter, (fl), 0, 0)
	#define CAL_OpcUaListEnter  pfOpcUaListEnter
	#define CHK_OpcUaListEnter  (pfOpcUaListEnter != NULL)
	#define EXP_OpcUaListEnter  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListEnter", (RTS_UINTPTR)OpcUaListEnter, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaListLeave(OpcUa_List* pList);
typedef OpcUa_Void (CDECL * PFOPCUALISTLEAVE) (OpcUa_List* pList);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUALISTLEAVE_NOTIMPLEMENTED)
	#define USE_OpcUaListLeave
	#define EXT_OpcUaListLeave
	#define GET_OpcUaListLeave(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaListLeave(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaListLeave  FALSE
	#define EXP_OpcUaListLeave  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaListLeave
	#define EXT_OpcUaListLeave
	#define GET_OpcUaListLeave(fl)  CAL_CMGETAPI( "OpcUaListLeave" ) 
	#define CAL_OpcUaListLeave  OpcUaListLeave
	#define CHK_OpcUaListLeave  TRUE
	#define EXP_OpcUaListLeave  CAL_CMEXPAPI( "OpcUaListLeave" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaListLeave
	#define EXT_OpcUaListLeave
	#define GET_OpcUaListLeave(fl)  CAL_CMGETAPI( "OpcUaListLeave" ) 
	#define CAL_OpcUaListLeave  OpcUaListLeave
	#define CHK_OpcUaListLeave  TRUE
	#define EXP_OpcUaListLeave  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListLeave", (RTS_UINTPTR)OpcUaListLeave, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaListLeave
	#define EXT_CmpOPCUAStackOpcUaListLeave
	#define GET_CmpOPCUAStackOpcUaListLeave  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaListLeave pICmpOPCUAStack->IOpcUaListLeave
	#define CHK_CmpOPCUAStackOpcUaListLeave (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaListLeave  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaListLeave
	#define EXT_OpcUaListLeave
	#define GET_OpcUaListLeave(fl)  CAL_CMGETAPI( "OpcUaListLeave" ) 
	#define CAL_OpcUaListLeave pICmpOPCUAStack->IOpcUaListLeave
	#define CHK_OpcUaListLeave (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaListLeave  CAL_CMEXPAPI( "OpcUaListLeave" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaListLeave  PFOPCUALISTLEAVE pfOpcUaListLeave;
	#define EXT_OpcUaListLeave  extern PFOPCUALISTLEAVE pfOpcUaListLeave;
	#define GET_OpcUaListLeave(fl)  s_pfCMGetAPI2( "OpcUaListLeave", (RTS_VOID_FCTPTR *)&pfOpcUaListLeave, (fl), 0, 0)
	#define CAL_OpcUaListLeave  pfOpcUaListLeave
	#define CHK_OpcUaListLeave  (pfOpcUaListLeave != NULL)
	#define EXP_OpcUaListLeave  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListLeave", (RTS_UINTPTR)OpcUaListLeave, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaListAddElement(OpcUa_List* pList, OpcUa_Void* pElementData);
typedef OpcUa_StatusCode (CDECL * PFOPCUALISTADDELEMENT) (OpcUa_List* pList, OpcUa_Void* pElementData);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUALISTADDELEMENT_NOTIMPLEMENTED)
	#define USE_OpcUaListAddElement
	#define EXT_OpcUaListAddElement
	#define GET_OpcUaListAddElement(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaListAddElement(p0,p1)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaListAddElement  FALSE
	#define EXP_OpcUaListAddElement  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaListAddElement
	#define EXT_OpcUaListAddElement
	#define GET_OpcUaListAddElement(fl)  CAL_CMGETAPI( "OpcUaListAddElement" ) 
	#define CAL_OpcUaListAddElement  OpcUaListAddElement
	#define CHK_OpcUaListAddElement  TRUE
	#define EXP_OpcUaListAddElement  CAL_CMEXPAPI( "OpcUaListAddElement" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaListAddElement
	#define EXT_OpcUaListAddElement
	#define GET_OpcUaListAddElement(fl)  CAL_CMGETAPI( "OpcUaListAddElement" ) 
	#define CAL_OpcUaListAddElement  OpcUaListAddElement
	#define CHK_OpcUaListAddElement  TRUE
	#define EXP_OpcUaListAddElement  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListAddElement", (RTS_UINTPTR)OpcUaListAddElement, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaListAddElement
	#define EXT_CmpOPCUAStackOpcUaListAddElement
	#define GET_CmpOPCUAStackOpcUaListAddElement  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaListAddElement pICmpOPCUAStack->IOpcUaListAddElement
	#define CHK_CmpOPCUAStackOpcUaListAddElement (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaListAddElement  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaListAddElement
	#define EXT_OpcUaListAddElement
	#define GET_OpcUaListAddElement(fl)  CAL_CMGETAPI( "OpcUaListAddElement" ) 
	#define CAL_OpcUaListAddElement pICmpOPCUAStack->IOpcUaListAddElement
	#define CHK_OpcUaListAddElement (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaListAddElement  CAL_CMEXPAPI( "OpcUaListAddElement" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaListAddElement  PFOPCUALISTADDELEMENT pfOpcUaListAddElement;
	#define EXT_OpcUaListAddElement  extern PFOPCUALISTADDELEMENT pfOpcUaListAddElement;
	#define GET_OpcUaListAddElement(fl)  s_pfCMGetAPI2( "OpcUaListAddElement", (RTS_VOID_FCTPTR *)&pfOpcUaListAddElement, (fl), 0, 0)
	#define CAL_OpcUaListAddElement  pfOpcUaListAddElement
	#define CHK_OpcUaListAddElement  (pfOpcUaListAddElement != NULL)
	#define EXP_OpcUaListAddElement  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListAddElement", (RTS_UINTPTR)OpcUaListAddElement, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaListAddElementToEnd(OpcUa_List* pList, OpcUa_Void* pElementData);
typedef OpcUa_StatusCode (CDECL * PFOPCUALISTADDELEMENTTOEND) (OpcUa_List* pList, OpcUa_Void* pElementData);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUALISTADDELEMENTTOEND_NOTIMPLEMENTED)
	#define USE_OpcUaListAddElementToEnd
	#define EXT_OpcUaListAddElementToEnd
	#define GET_OpcUaListAddElementToEnd(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaListAddElementToEnd(p0,p1)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaListAddElementToEnd  FALSE
	#define EXP_OpcUaListAddElementToEnd  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaListAddElementToEnd
	#define EXT_OpcUaListAddElementToEnd
	#define GET_OpcUaListAddElementToEnd(fl)  CAL_CMGETAPI( "OpcUaListAddElementToEnd" ) 
	#define CAL_OpcUaListAddElementToEnd  OpcUaListAddElementToEnd
	#define CHK_OpcUaListAddElementToEnd  TRUE
	#define EXP_OpcUaListAddElementToEnd  CAL_CMEXPAPI( "OpcUaListAddElementToEnd" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaListAddElementToEnd
	#define EXT_OpcUaListAddElementToEnd
	#define GET_OpcUaListAddElementToEnd(fl)  CAL_CMGETAPI( "OpcUaListAddElementToEnd" ) 
	#define CAL_OpcUaListAddElementToEnd  OpcUaListAddElementToEnd
	#define CHK_OpcUaListAddElementToEnd  TRUE
	#define EXP_OpcUaListAddElementToEnd  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListAddElementToEnd", (RTS_UINTPTR)OpcUaListAddElementToEnd, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaListAddElementToEnd
	#define EXT_CmpOPCUAStackOpcUaListAddElementToEnd
	#define GET_CmpOPCUAStackOpcUaListAddElementToEnd  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaListAddElementToEnd pICmpOPCUAStack->IOpcUaListAddElementToEnd
	#define CHK_CmpOPCUAStackOpcUaListAddElementToEnd (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaListAddElementToEnd  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaListAddElementToEnd
	#define EXT_OpcUaListAddElementToEnd
	#define GET_OpcUaListAddElementToEnd(fl)  CAL_CMGETAPI( "OpcUaListAddElementToEnd" ) 
	#define CAL_OpcUaListAddElementToEnd pICmpOPCUAStack->IOpcUaListAddElementToEnd
	#define CHK_OpcUaListAddElementToEnd (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaListAddElementToEnd  CAL_CMEXPAPI( "OpcUaListAddElementToEnd" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaListAddElementToEnd  PFOPCUALISTADDELEMENTTOEND pfOpcUaListAddElementToEnd;
	#define EXT_OpcUaListAddElementToEnd  extern PFOPCUALISTADDELEMENTTOEND pfOpcUaListAddElementToEnd;
	#define GET_OpcUaListAddElementToEnd(fl)  s_pfCMGetAPI2( "OpcUaListAddElementToEnd", (RTS_VOID_FCTPTR *)&pfOpcUaListAddElementToEnd, (fl), 0, 0)
	#define CAL_OpcUaListAddElementToEnd  pfOpcUaListAddElementToEnd
	#define CHK_OpcUaListAddElementToEnd  (pfOpcUaListAddElementToEnd != NULL)
	#define EXP_OpcUaListAddElementToEnd  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListAddElementToEnd", (RTS_UINTPTR)OpcUaListAddElementToEnd, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaListInsertElement(OpcUa_List* pList, OpcUa_Void* pElementData);
typedef OpcUa_StatusCode (CDECL * PFOPCUALISTINSERTELEMENT) (OpcUa_List* pList, OpcUa_Void* pElementData);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUALISTINSERTELEMENT_NOTIMPLEMENTED)
	#define USE_OpcUaListInsertElement
	#define EXT_OpcUaListInsertElement
	#define GET_OpcUaListInsertElement(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaListInsertElement(p0,p1)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaListInsertElement  FALSE
	#define EXP_OpcUaListInsertElement  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaListInsertElement
	#define EXT_OpcUaListInsertElement
	#define GET_OpcUaListInsertElement(fl)  CAL_CMGETAPI( "OpcUaListInsertElement" ) 
	#define CAL_OpcUaListInsertElement  OpcUaListInsertElement
	#define CHK_OpcUaListInsertElement  TRUE
	#define EXP_OpcUaListInsertElement  CAL_CMEXPAPI( "OpcUaListInsertElement" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaListInsertElement
	#define EXT_OpcUaListInsertElement
	#define GET_OpcUaListInsertElement(fl)  CAL_CMGETAPI( "OpcUaListInsertElement" ) 
	#define CAL_OpcUaListInsertElement  OpcUaListInsertElement
	#define CHK_OpcUaListInsertElement  TRUE
	#define EXP_OpcUaListInsertElement  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListInsertElement", (RTS_UINTPTR)OpcUaListInsertElement, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaListInsertElement
	#define EXT_CmpOPCUAStackOpcUaListInsertElement
	#define GET_CmpOPCUAStackOpcUaListInsertElement  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaListInsertElement pICmpOPCUAStack->IOpcUaListInsertElement
	#define CHK_CmpOPCUAStackOpcUaListInsertElement (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaListInsertElement  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaListInsertElement
	#define EXT_OpcUaListInsertElement
	#define GET_OpcUaListInsertElement(fl)  CAL_CMGETAPI( "OpcUaListInsertElement" ) 
	#define CAL_OpcUaListInsertElement pICmpOPCUAStack->IOpcUaListInsertElement
	#define CHK_OpcUaListInsertElement (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaListInsertElement  CAL_CMEXPAPI( "OpcUaListInsertElement" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaListInsertElement  PFOPCUALISTINSERTELEMENT pfOpcUaListInsertElement;
	#define EXT_OpcUaListInsertElement  extern PFOPCUALISTINSERTELEMENT pfOpcUaListInsertElement;
	#define GET_OpcUaListInsertElement(fl)  s_pfCMGetAPI2( "OpcUaListInsertElement", (RTS_VOID_FCTPTR *)&pfOpcUaListInsertElement, (fl), 0, 0)
	#define CAL_OpcUaListInsertElement  pfOpcUaListInsertElement
	#define CHK_OpcUaListInsertElement  (pfOpcUaListInsertElement != NULL)
	#define EXP_OpcUaListInsertElement  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListInsertElement", (RTS_UINTPTR)OpcUaListInsertElement, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaListResetCurrent(OpcUa_List* pList);
typedef OpcUa_StatusCode (CDECL * PFOPCUALISTRESETCURRENT) (OpcUa_List* pList);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUALISTRESETCURRENT_NOTIMPLEMENTED)
	#define USE_OpcUaListResetCurrent
	#define EXT_OpcUaListResetCurrent
	#define GET_OpcUaListResetCurrent(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaListResetCurrent(p0)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaListResetCurrent  FALSE
	#define EXP_OpcUaListResetCurrent  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaListResetCurrent
	#define EXT_OpcUaListResetCurrent
	#define GET_OpcUaListResetCurrent(fl)  CAL_CMGETAPI( "OpcUaListResetCurrent" ) 
	#define CAL_OpcUaListResetCurrent  OpcUaListResetCurrent
	#define CHK_OpcUaListResetCurrent  TRUE
	#define EXP_OpcUaListResetCurrent  CAL_CMEXPAPI( "OpcUaListResetCurrent" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaListResetCurrent
	#define EXT_OpcUaListResetCurrent
	#define GET_OpcUaListResetCurrent(fl)  CAL_CMGETAPI( "OpcUaListResetCurrent" ) 
	#define CAL_OpcUaListResetCurrent  OpcUaListResetCurrent
	#define CHK_OpcUaListResetCurrent  TRUE
	#define EXP_OpcUaListResetCurrent  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListResetCurrent", (RTS_UINTPTR)OpcUaListResetCurrent, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaListResetCurrent
	#define EXT_CmpOPCUAStackOpcUaListResetCurrent
	#define GET_CmpOPCUAStackOpcUaListResetCurrent  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaListResetCurrent pICmpOPCUAStack->IOpcUaListResetCurrent
	#define CHK_CmpOPCUAStackOpcUaListResetCurrent (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaListResetCurrent  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaListResetCurrent
	#define EXT_OpcUaListResetCurrent
	#define GET_OpcUaListResetCurrent(fl)  CAL_CMGETAPI( "OpcUaListResetCurrent" ) 
	#define CAL_OpcUaListResetCurrent pICmpOPCUAStack->IOpcUaListResetCurrent
	#define CHK_OpcUaListResetCurrent (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaListResetCurrent  CAL_CMEXPAPI( "OpcUaListResetCurrent" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaListResetCurrent  PFOPCUALISTRESETCURRENT pfOpcUaListResetCurrent;
	#define EXT_OpcUaListResetCurrent  extern PFOPCUALISTRESETCURRENT pfOpcUaListResetCurrent;
	#define GET_OpcUaListResetCurrent(fl)  s_pfCMGetAPI2( "OpcUaListResetCurrent", (RTS_VOID_FCTPTR *)&pfOpcUaListResetCurrent, (fl), 0, 0)
	#define CAL_OpcUaListResetCurrent  pfOpcUaListResetCurrent
	#define CHK_OpcUaListResetCurrent  (pfOpcUaListResetCurrent != NULL)
	#define EXP_OpcUaListResetCurrent  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListResetCurrent", (RTS_UINTPTR)OpcUaListResetCurrent, 0, 0) 
#endif



OpcUa_Void* CDECL OpcUaListGetNextElement(OpcUa_List* pList);
typedef OpcUa_Void* (CDECL * PFOPCUALISTGETNEXTELEMENT) (OpcUa_List* pList);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUALISTGETNEXTELEMENT_NOTIMPLEMENTED)
	#define USE_OpcUaListGetNextElement
	#define EXT_OpcUaListGetNextElement
	#define GET_OpcUaListGetNextElement(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaListGetNextElement(p0)  (OpcUa_Void*)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaListGetNextElement  FALSE
	#define EXP_OpcUaListGetNextElement  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaListGetNextElement
	#define EXT_OpcUaListGetNextElement
	#define GET_OpcUaListGetNextElement(fl)  CAL_CMGETAPI( "OpcUaListGetNextElement" ) 
	#define CAL_OpcUaListGetNextElement  OpcUaListGetNextElement
	#define CHK_OpcUaListGetNextElement  TRUE
	#define EXP_OpcUaListGetNextElement  CAL_CMEXPAPI( "OpcUaListGetNextElement" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaListGetNextElement
	#define EXT_OpcUaListGetNextElement
	#define GET_OpcUaListGetNextElement(fl)  CAL_CMGETAPI( "OpcUaListGetNextElement" ) 
	#define CAL_OpcUaListGetNextElement  OpcUaListGetNextElement
	#define CHK_OpcUaListGetNextElement  TRUE
	#define EXP_OpcUaListGetNextElement  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListGetNextElement", (RTS_UINTPTR)OpcUaListGetNextElement, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaListGetNextElement
	#define EXT_CmpOPCUAStackOpcUaListGetNextElement
	#define GET_CmpOPCUAStackOpcUaListGetNextElement  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaListGetNextElement pICmpOPCUAStack->IOpcUaListGetNextElement
	#define CHK_CmpOPCUAStackOpcUaListGetNextElement (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaListGetNextElement  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaListGetNextElement
	#define EXT_OpcUaListGetNextElement
	#define GET_OpcUaListGetNextElement(fl)  CAL_CMGETAPI( "OpcUaListGetNextElement" ) 
	#define CAL_OpcUaListGetNextElement pICmpOPCUAStack->IOpcUaListGetNextElement
	#define CHK_OpcUaListGetNextElement (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaListGetNextElement  CAL_CMEXPAPI( "OpcUaListGetNextElement" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaListGetNextElement  PFOPCUALISTGETNEXTELEMENT pfOpcUaListGetNextElement;
	#define EXT_OpcUaListGetNextElement  extern PFOPCUALISTGETNEXTELEMENT pfOpcUaListGetNextElement;
	#define GET_OpcUaListGetNextElement(fl)  s_pfCMGetAPI2( "OpcUaListGetNextElement", (RTS_VOID_FCTPTR *)&pfOpcUaListGetNextElement, (fl), 0, 0)
	#define CAL_OpcUaListGetNextElement  pfOpcUaListGetNextElement
	#define CHK_OpcUaListGetNextElement  (pfOpcUaListGetNextElement != NULL)
	#define EXP_OpcUaListGetNextElement  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListGetNextElement", (RTS_UINTPTR)OpcUaListGetNextElement, 0, 0) 
#endif



OpcUa_Void* CDECL OpcUaListGetCurrentElement(OpcUa_List* pList);
typedef OpcUa_Void* (CDECL * PFOPCUALISTGETCURRENTELEMENT) (OpcUa_List* pList);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUALISTGETCURRENTELEMENT_NOTIMPLEMENTED)
	#define USE_OpcUaListGetCurrentElement
	#define EXT_OpcUaListGetCurrentElement
	#define GET_OpcUaListGetCurrentElement(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaListGetCurrentElement(p0)  (OpcUa_Void*)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaListGetCurrentElement  FALSE
	#define EXP_OpcUaListGetCurrentElement  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaListGetCurrentElement
	#define EXT_OpcUaListGetCurrentElement
	#define GET_OpcUaListGetCurrentElement(fl)  CAL_CMGETAPI( "OpcUaListGetCurrentElement" ) 
	#define CAL_OpcUaListGetCurrentElement  OpcUaListGetCurrentElement
	#define CHK_OpcUaListGetCurrentElement  TRUE
	#define EXP_OpcUaListGetCurrentElement  CAL_CMEXPAPI( "OpcUaListGetCurrentElement" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaListGetCurrentElement
	#define EXT_OpcUaListGetCurrentElement
	#define GET_OpcUaListGetCurrentElement(fl)  CAL_CMGETAPI( "OpcUaListGetCurrentElement" ) 
	#define CAL_OpcUaListGetCurrentElement  OpcUaListGetCurrentElement
	#define CHK_OpcUaListGetCurrentElement  TRUE
	#define EXP_OpcUaListGetCurrentElement  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListGetCurrentElement", (RTS_UINTPTR)OpcUaListGetCurrentElement, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaListGetCurrentElement
	#define EXT_CmpOPCUAStackOpcUaListGetCurrentElement
	#define GET_CmpOPCUAStackOpcUaListGetCurrentElement  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaListGetCurrentElement pICmpOPCUAStack->IOpcUaListGetCurrentElement
	#define CHK_CmpOPCUAStackOpcUaListGetCurrentElement (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaListGetCurrentElement  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaListGetCurrentElement
	#define EXT_OpcUaListGetCurrentElement
	#define GET_OpcUaListGetCurrentElement(fl)  CAL_CMGETAPI( "OpcUaListGetCurrentElement" ) 
	#define CAL_OpcUaListGetCurrentElement pICmpOPCUAStack->IOpcUaListGetCurrentElement
	#define CHK_OpcUaListGetCurrentElement (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaListGetCurrentElement  CAL_CMEXPAPI( "OpcUaListGetCurrentElement" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaListGetCurrentElement  PFOPCUALISTGETCURRENTELEMENT pfOpcUaListGetCurrentElement;
	#define EXT_OpcUaListGetCurrentElement  extern PFOPCUALISTGETCURRENTELEMENT pfOpcUaListGetCurrentElement;
	#define GET_OpcUaListGetCurrentElement(fl)  s_pfCMGetAPI2( "OpcUaListGetCurrentElement", (RTS_VOID_FCTPTR *)&pfOpcUaListGetCurrentElement, (fl), 0, 0)
	#define CAL_OpcUaListGetCurrentElement  pfOpcUaListGetCurrentElement
	#define CHK_OpcUaListGetCurrentElement  (pfOpcUaListGetCurrentElement != NULL)
	#define EXP_OpcUaListGetCurrentElement  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListGetCurrentElement", (RTS_UINTPTR)OpcUaListGetCurrentElement, 0, 0) 
#endif



OpcUa_Void* CDECL OpcUaListGetPrevElement(OpcUa_List* pList);
typedef OpcUa_Void* (CDECL * PFOPCUALISTGETPREVELEMENT) (OpcUa_List* pList);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUALISTGETPREVELEMENT_NOTIMPLEMENTED)
	#define USE_OpcUaListGetPrevElement
	#define EXT_OpcUaListGetPrevElement
	#define GET_OpcUaListGetPrevElement(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaListGetPrevElement(p0)  (OpcUa_Void*)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaListGetPrevElement  FALSE
	#define EXP_OpcUaListGetPrevElement  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaListGetPrevElement
	#define EXT_OpcUaListGetPrevElement
	#define GET_OpcUaListGetPrevElement(fl)  CAL_CMGETAPI( "OpcUaListGetPrevElement" ) 
	#define CAL_OpcUaListGetPrevElement  OpcUaListGetPrevElement
	#define CHK_OpcUaListGetPrevElement  TRUE
	#define EXP_OpcUaListGetPrevElement  CAL_CMEXPAPI( "OpcUaListGetPrevElement" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaListGetPrevElement
	#define EXT_OpcUaListGetPrevElement
	#define GET_OpcUaListGetPrevElement(fl)  CAL_CMGETAPI( "OpcUaListGetPrevElement" ) 
	#define CAL_OpcUaListGetPrevElement  OpcUaListGetPrevElement
	#define CHK_OpcUaListGetPrevElement  TRUE
	#define EXP_OpcUaListGetPrevElement  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListGetPrevElement", (RTS_UINTPTR)OpcUaListGetPrevElement, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaListGetPrevElement
	#define EXT_CmpOPCUAStackOpcUaListGetPrevElement
	#define GET_CmpOPCUAStackOpcUaListGetPrevElement  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaListGetPrevElement pICmpOPCUAStack->IOpcUaListGetPrevElement
	#define CHK_CmpOPCUAStackOpcUaListGetPrevElement (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaListGetPrevElement  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaListGetPrevElement
	#define EXT_OpcUaListGetPrevElement
	#define GET_OpcUaListGetPrevElement(fl)  CAL_CMGETAPI( "OpcUaListGetPrevElement" ) 
	#define CAL_OpcUaListGetPrevElement pICmpOPCUAStack->IOpcUaListGetPrevElement
	#define CHK_OpcUaListGetPrevElement (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaListGetPrevElement  CAL_CMEXPAPI( "OpcUaListGetPrevElement" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaListGetPrevElement  PFOPCUALISTGETPREVELEMENT pfOpcUaListGetPrevElement;
	#define EXT_OpcUaListGetPrevElement  extern PFOPCUALISTGETPREVELEMENT pfOpcUaListGetPrevElement;
	#define GET_OpcUaListGetPrevElement(fl)  s_pfCMGetAPI2( "OpcUaListGetPrevElement", (RTS_VOID_FCTPTR *)&pfOpcUaListGetPrevElement, (fl), 0, 0)
	#define CAL_OpcUaListGetPrevElement  pfOpcUaListGetPrevElement
	#define CHK_OpcUaListGetPrevElement  (pfOpcUaListGetPrevElement != NULL)
	#define EXP_OpcUaListGetPrevElement  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListGetPrevElement", (RTS_UINTPTR)OpcUaListGetPrevElement, 0, 0) 
#endif



OpcUa_Void* CDECL OpcUaListGetElement(OpcUa_List* pList, OpcUa_Void* pElementData);
typedef OpcUa_Void* (CDECL * PFOPCUALISTGETELEMENT) (OpcUa_List* pList, OpcUa_Void* pElementData);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUALISTGETELEMENT_NOTIMPLEMENTED)
	#define USE_OpcUaListGetElement
	#define EXT_OpcUaListGetElement
	#define GET_OpcUaListGetElement(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaListGetElement(p0,p1)  (OpcUa_Void*)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaListGetElement  FALSE
	#define EXP_OpcUaListGetElement  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaListGetElement
	#define EXT_OpcUaListGetElement
	#define GET_OpcUaListGetElement(fl)  CAL_CMGETAPI( "OpcUaListGetElement" ) 
	#define CAL_OpcUaListGetElement  OpcUaListGetElement
	#define CHK_OpcUaListGetElement  TRUE
	#define EXP_OpcUaListGetElement  CAL_CMEXPAPI( "OpcUaListGetElement" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaListGetElement
	#define EXT_OpcUaListGetElement
	#define GET_OpcUaListGetElement(fl)  CAL_CMGETAPI( "OpcUaListGetElement" ) 
	#define CAL_OpcUaListGetElement  OpcUaListGetElement
	#define CHK_OpcUaListGetElement  TRUE
	#define EXP_OpcUaListGetElement  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListGetElement", (RTS_UINTPTR)OpcUaListGetElement, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaListGetElement
	#define EXT_CmpOPCUAStackOpcUaListGetElement
	#define GET_CmpOPCUAStackOpcUaListGetElement  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaListGetElement pICmpOPCUAStack->IOpcUaListGetElement
	#define CHK_CmpOPCUAStackOpcUaListGetElement (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaListGetElement  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaListGetElement
	#define EXT_OpcUaListGetElement
	#define GET_OpcUaListGetElement(fl)  CAL_CMGETAPI( "OpcUaListGetElement" ) 
	#define CAL_OpcUaListGetElement pICmpOPCUAStack->IOpcUaListGetElement
	#define CHK_OpcUaListGetElement (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaListGetElement  CAL_CMEXPAPI( "OpcUaListGetElement" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaListGetElement  PFOPCUALISTGETELEMENT pfOpcUaListGetElement;
	#define EXT_OpcUaListGetElement  extern PFOPCUALISTGETELEMENT pfOpcUaListGetElement;
	#define GET_OpcUaListGetElement(fl)  s_pfCMGetAPI2( "OpcUaListGetElement", (RTS_VOID_FCTPTR *)&pfOpcUaListGetElement, (fl), 0, 0)
	#define CAL_OpcUaListGetElement  pfOpcUaListGetElement
	#define CHK_OpcUaListGetElement  (pfOpcUaListGetElement != NULL)
	#define EXP_OpcUaListGetElement  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListGetElement", (RTS_UINTPTR)OpcUaListGetElement, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaListDeleteCurrentElement(OpcUa_List* pList);
typedef OpcUa_Void (CDECL * PFOPCUALISTDELETECURRENTELEMENT) (OpcUa_List* pList);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUALISTDELETECURRENTELEMENT_NOTIMPLEMENTED)
	#define USE_OpcUaListDeleteCurrentElement
	#define EXT_OpcUaListDeleteCurrentElement
	#define GET_OpcUaListDeleteCurrentElement(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaListDeleteCurrentElement(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaListDeleteCurrentElement  FALSE
	#define EXP_OpcUaListDeleteCurrentElement  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaListDeleteCurrentElement
	#define EXT_OpcUaListDeleteCurrentElement
	#define GET_OpcUaListDeleteCurrentElement(fl)  CAL_CMGETAPI( "OpcUaListDeleteCurrentElement" ) 
	#define CAL_OpcUaListDeleteCurrentElement  OpcUaListDeleteCurrentElement
	#define CHK_OpcUaListDeleteCurrentElement  TRUE
	#define EXP_OpcUaListDeleteCurrentElement  CAL_CMEXPAPI( "OpcUaListDeleteCurrentElement" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaListDeleteCurrentElement
	#define EXT_OpcUaListDeleteCurrentElement
	#define GET_OpcUaListDeleteCurrentElement(fl)  CAL_CMGETAPI( "OpcUaListDeleteCurrentElement" ) 
	#define CAL_OpcUaListDeleteCurrentElement  OpcUaListDeleteCurrentElement
	#define CHK_OpcUaListDeleteCurrentElement  TRUE
	#define EXP_OpcUaListDeleteCurrentElement  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListDeleteCurrentElement", (RTS_UINTPTR)OpcUaListDeleteCurrentElement, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaListDeleteCurrentElement
	#define EXT_CmpOPCUAStackOpcUaListDeleteCurrentElement
	#define GET_CmpOPCUAStackOpcUaListDeleteCurrentElement  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaListDeleteCurrentElement pICmpOPCUAStack->IOpcUaListDeleteCurrentElement
	#define CHK_CmpOPCUAStackOpcUaListDeleteCurrentElement (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaListDeleteCurrentElement  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaListDeleteCurrentElement
	#define EXT_OpcUaListDeleteCurrentElement
	#define GET_OpcUaListDeleteCurrentElement(fl)  CAL_CMGETAPI( "OpcUaListDeleteCurrentElement" ) 
	#define CAL_OpcUaListDeleteCurrentElement pICmpOPCUAStack->IOpcUaListDeleteCurrentElement
	#define CHK_OpcUaListDeleteCurrentElement (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaListDeleteCurrentElement  CAL_CMEXPAPI( "OpcUaListDeleteCurrentElement" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaListDeleteCurrentElement  PFOPCUALISTDELETECURRENTELEMENT pfOpcUaListDeleteCurrentElement;
	#define EXT_OpcUaListDeleteCurrentElement  extern PFOPCUALISTDELETECURRENTELEMENT pfOpcUaListDeleteCurrentElement;
	#define GET_OpcUaListDeleteCurrentElement(fl)  s_pfCMGetAPI2( "OpcUaListDeleteCurrentElement", (RTS_VOID_FCTPTR *)&pfOpcUaListDeleteCurrentElement, (fl), 0, 0)
	#define CAL_OpcUaListDeleteCurrentElement  pfOpcUaListDeleteCurrentElement
	#define CHK_OpcUaListDeleteCurrentElement  (pfOpcUaListDeleteCurrentElement != NULL)
	#define EXP_OpcUaListDeleteCurrentElement  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListDeleteCurrentElement", (RTS_UINTPTR)OpcUaListDeleteCurrentElement, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaListDeleteElement(OpcUa_List* pList, OpcUa_Void* pElementData);
typedef OpcUa_StatusCode (CDECL * PFOPCUALISTDELETEELEMENT) (OpcUa_List* pList, OpcUa_Void* pElementData);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUALISTDELETEELEMENT_NOTIMPLEMENTED)
	#define USE_OpcUaListDeleteElement
	#define EXT_OpcUaListDeleteElement
	#define GET_OpcUaListDeleteElement(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaListDeleteElement(p0,p1)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaListDeleteElement  FALSE
	#define EXP_OpcUaListDeleteElement  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaListDeleteElement
	#define EXT_OpcUaListDeleteElement
	#define GET_OpcUaListDeleteElement(fl)  CAL_CMGETAPI( "OpcUaListDeleteElement" ) 
	#define CAL_OpcUaListDeleteElement  OpcUaListDeleteElement
	#define CHK_OpcUaListDeleteElement  TRUE
	#define EXP_OpcUaListDeleteElement  CAL_CMEXPAPI( "OpcUaListDeleteElement" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaListDeleteElement
	#define EXT_OpcUaListDeleteElement
	#define GET_OpcUaListDeleteElement(fl)  CAL_CMGETAPI( "OpcUaListDeleteElement" ) 
	#define CAL_OpcUaListDeleteElement  OpcUaListDeleteElement
	#define CHK_OpcUaListDeleteElement  TRUE
	#define EXP_OpcUaListDeleteElement  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListDeleteElement", (RTS_UINTPTR)OpcUaListDeleteElement, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaListDeleteElement
	#define EXT_CmpOPCUAStackOpcUaListDeleteElement
	#define GET_CmpOPCUAStackOpcUaListDeleteElement  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaListDeleteElement pICmpOPCUAStack->IOpcUaListDeleteElement
	#define CHK_CmpOPCUAStackOpcUaListDeleteElement (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaListDeleteElement  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaListDeleteElement
	#define EXT_OpcUaListDeleteElement
	#define GET_OpcUaListDeleteElement(fl)  CAL_CMGETAPI( "OpcUaListDeleteElement" ) 
	#define CAL_OpcUaListDeleteElement pICmpOPCUAStack->IOpcUaListDeleteElement
	#define CHK_OpcUaListDeleteElement (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaListDeleteElement  CAL_CMEXPAPI( "OpcUaListDeleteElement" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaListDeleteElement  PFOPCUALISTDELETEELEMENT pfOpcUaListDeleteElement;
	#define EXT_OpcUaListDeleteElement  extern PFOPCUALISTDELETEELEMENT pfOpcUaListDeleteElement;
	#define GET_OpcUaListDeleteElement(fl)  s_pfCMGetAPI2( "OpcUaListDeleteElement", (RTS_VOID_FCTPTR *)&pfOpcUaListDeleteElement, (fl), 0, 0)
	#define CAL_OpcUaListDeleteElement  pfOpcUaListDeleteElement
	#define CHK_OpcUaListDeleteElement  (pfOpcUaListDeleteElement != NULL)
	#define EXP_OpcUaListDeleteElement  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListDeleteElement", (RTS_UINTPTR)OpcUaListDeleteElement, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaListGetNumberOfElements(OpcUa_List* pList, OpcUa_UInt32* uintElementCount);
typedef OpcUa_StatusCode (CDECL * PFOPCUALISTGETNUMBEROFELEMENTS) (OpcUa_List* pList, OpcUa_UInt32* uintElementCount);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUALISTGETNUMBEROFELEMENTS_NOTIMPLEMENTED)
	#define USE_OpcUaListGetNumberOfElements
	#define EXT_OpcUaListGetNumberOfElements
	#define GET_OpcUaListGetNumberOfElements(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaListGetNumberOfElements(p0,p1)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaListGetNumberOfElements  FALSE
	#define EXP_OpcUaListGetNumberOfElements  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaListGetNumberOfElements
	#define EXT_OpcUaListGetNumberOfElements
	#define GET_OpcUaListGetNumberOfElements(fl)  CAL_CMGETAPI( "OpcUaListGetNumberOfElements" ) 
	#define CAL_OpcUaListGetNumberOfElements  OpcUaListGetNumberOfElements
	#define CHK_OpcUaListGetNumberOfElements  TRUE
	#define EXP_OpcUaListGetNumberOfElements  CAL_CMEXPAPI( "OpcUaListGetNumberOfElements" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaListGetNumberOfElements
	#define EXT_OpcUaListGetNumberOfElements
	#define GET_OpcUaListGetNumberOfElements(fl)  CAL_CMGETAPI( "OpcUaListGetNumberOfElements" ) 
	#define CAL_OpcUaListGetNumberOfElements  OpcUaListGetNumberOfElements
	#define CHK_OpcUaListGetNumberOfElements  TRUE
	#define EXP_OpcUaListGetNumberOfElements  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListGetNumberOfElements", (RTS_UINTPTR)OpcUaListGetNumberOfElements, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaListGetNumberOfElements
	#define EXT_CmpOPCUAStackOpcUaListGetNumberOfElements
	#define GET_CmpOPCUAStackOpcUaListGetNumberOfElements  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaListGetNumberOfElements pICmpOPCUAStack->IOpcUaListGetNumberOfElements
	#define CHK_CmpOPCUAStackOpcUaListGetNumberOfElements (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaListGetNumberOfElements  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaListGetNumberOfElements
	#define EXT_OpcUaListGetNumberOfElements
	#define GET_OpcUaListGetNumberOfElements(fl)  CAL_CMGETAPI( "OpcUaListGetNumberOfElements" ) 
	#define CAL_OpcUaListGetNumberOfElements pICmpOPCUAStack->IOpcUaListGetNumberOfElements
	#define CHK_OpcUaListGetNumberOfElements (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaListGetNumberOfElements  CAL_CMEXPAPI( "OpcUaListGetNumberOfElements" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaListGetNumberOfElements  PFOPCUALISTGETNUMBEROFELEMENTS pfOpcUaListGetNumberOfElements;
	#define EXT_OpcUaListGetNumberOfElements  extern PFOPCUALISTGETNUMBEROFELEMENTS pfOpcUaListGetNumberOfElements;
	#define GET_OpcUaListGetNumberOfElements(fl)  s_pfCMGetAPI2( "OpcUaListGetNumberOfElements", (RTS_VOID_FCTPTR *)&pfOpcUaListGetNumberOfElements, (fl), 0, 0)
	#define CAL_OpcUaListGetNumberOfElements  pfOpcUaListGetNumberOfElements
	#define CHK_OpcUaListGetNumberOfElements  (pfOpcUaListGetNumberOfElements != NULL)
	#define EXP_OpcUaListGetNumberOfElements  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListGetNumberOfElements", (RTS_UINTPTR)OpcUaListGetNumberOfElements, 0, 0) 
#endif



OpcUa_Void* CDECL OpcUaListRemoveFirstElement(OpcUa_List* pList);
typedef OpcUa_Void* (CDECL * PFOPCUALISTREMOVEFIRSTELEMENT) (OpcUa_List* pList);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUALISTREMOVEFIRSTELEMENT_NOTIMPLEMENTED)
	#define USE_OpcUaListRemoveFirstElement
	#define EXT_OpcUaListRemoveFirstElement
	#define GET_OpcUaListRemoveFirstElement(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaListRemoveFirstElement(p0)  (OpcUa_Void*)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaListRemoveFirstElement  FALSE
	#define EXP_OpcUaListRemoveFirstElement  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaListRemoveFirstElement
	#define EXT_OpcUaListRemoveFirstElement
	#define GET_OpcUaListRemoveFirstElement(fl)  CAL_CMGETAPI( "OpcUaListRemoveFirstElement" ) 
	#define CAL_OpcUaListRemoveFirstElement  OpcUaListRemoveFirstElement
	#define CHK_OpcUaListRemoveFirstElement  TRUE
	#define EXP_OpcUaListRemoveFirstElement  CAL_CMEXPAPI( "OpcUaListRemoveFirstElement" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaListRemoveFirstElement
	#define EXT_OpcUaListRemoveFirstElement
	#define GET_OpcUaListRemoveFirstElement(fl)  CAL_CMGETAPI( "OpcUaListRemoveFirstElement" ) 
	#define CAL_OpcUaListRemoveFirstElement  OpcUaListRemoveFirstElement
	#define CHK_OpcUaListRemoveFirstElement  TRUE
	#define EXP_OpcUaListRemoveFirstElement  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListRemoveFirstElement", (RTS_UINTPTR)OpcUaListRemoveFirstElement, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaListRemoveFirstElement
	#define EXT_CmpOPCUAStackOpcUaListRemoveFirstElement
	#define GET_CmpOPCUAStackOpcUaListRemoveFirstElement  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaListRemoveFirstElement pICmpOPCUAStack->IOpcUaListRemoveFirstElement
	#define CHK_CmpOPCUAStackOpcUaListRemoveFirstElement (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaListRemoveFirstElement  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaListRemoveFirstElement
	#define EXT_OpcUaListRemoveFirstElement
	#define GET_OpcUaListRemoveFirstElement(fl)  CAL_CMGETAPI( "OpcUaListRemoveFirstElement" ) 
	#define CAL_OpcUaListRemoveFirstElement pICmpOPCUAStack->IOpcUaListRemoveFirstElement
	#define CHK_OpcUaListRemoveFirstElement (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaListRemoveFirstElement  CAL_CMEXPAPI( "OpcUaListRemoveFirstElement" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaListRemoveFirstElement  PFOPCUALISTREMOVEFIRSTELEMENT pfOpcUaListRemoveFirstElement;
	#define EXT_OpcUaListRemoveFirstElement  extern PFOPCUALISTREMOVEFIRSTELEMENT pfOpcUaListRemoveFirstElement;
	#define GET_OpcUaListRemoveFirstElement(fl)  s_pfCMGetAPI2( "OpcUaListRemoveFirstElement", (RTS_VOID_FCTPTR *)&pfOpcUaListRemoveFirstElement, (fl), 0, 0)
	#define CAL_OpcUaListRemoveFirstElement  pfOpcUaListRemoveFirstElement
	#define CHK_OpcUaListRemoveFirstElement  (pfOpcUaListRemoveFirstElement != NULL)
	#define EXP_OpcUaListRemoveFirstElement  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaListRemoveFirstElement", (RTS_UINTPTR)OpcUaListRemoveFirstElement, 0, 0) 
#endif




OpcUa_Void CDECL OpcUaEndpointDescriptionInitialize(OpcUa_EndpointDescription* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAENDPOINTDESCRIPTIONINITIALIZE) (OpcUa_EndpointDescription* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAENDPOINTDESCRIPTIONINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaEndpointDescriptionInitialize
	#define EXT_OpcUaEndpointDescriptionInitialize
	#define GET_OpcUaEndpointDescriptionInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaEndpointDescriptionInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaEndpointDescriptionInitialize  FALSE
	#define EXP_OpcUaEndpointDescriptionInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaEndpointDescriptionInitialize
	#define EXT_OpcUaEndpointDescriptionInitialize
	#define GET_OpcUaEndpointDescriptionInitialize(fl)  CAL_CMGETAPI( "OpcUaEndpointDescriptionInitialize" ) 
	#define CAL_OpcUaEndpointDescriptionInitialize  OpcUaEndpointDescriptionInitialize
	#define CHK_OpcUaEndpointDescriptionInitialize  TRUE
	#define EXP_OpcUaEndpointDescriptionInitialize  CAL_CMEXPAPI( "OpcUaEndpointDescriptionInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaEndpointDescriptionInitialize
	#define EXT_OpcUaEndpointDescriptionInitialize
	#define GET_OpcUaEndpointDescriptionInitialize(fl)  CAL_CMGETAPI( "OpcUaEndpointDescriptionInitialize" ) 
	#define CAL_OpcUaEndpointDescriptionInitialize  OpcUaEndpointDescriptionInitialize
	#define CHK_OpcUaEndpointDescriptionInitialize  TRUE
	#define EXP_OpcUaEndpointDescriptionInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointDescriptionInitialize", (RTS_UINTPTR)OpcUaEndpointDescriptionInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaEndpointDescriptionInitialize
	#define EXT_CmpOPCUAStackOpcUaEndpointDescriptionInitialize
	#define GET_CmpOPCUAStackOpcUaEndpointDescriptionInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaEndpointDescriptionInitialize pICmpOPCUAStack->IOpcUaEndpointDescriptionInitialize
	#define CHK_CmpOPCUAStackOpcUaEndpointDescriptionInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaEndpointDescriptionInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaEndpointDescriptionInitialize
	#define EXT_OpcUaEndpointDescriptionInitialize
	#define GET_OpcUaEndpointDescriptionInitialize(fl)  CAL_CMGETAPI( "OpcUaEndpointDescriptionInitialize" ) 
	#define CAL_OpcUaEndpointDescriptionInitialize pICmpOPCUAStack->IOpcUaEndpointDescriptionInitialize
	#define CHK_OpcUaEndpointDescriptionInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaEndpointDescriptionInitialize  CAL_CMEXPAPI( "OpcUaEndpointDescriptionInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaEndpointDescriptionInitialize  PFOPCUAENDPOINTDESCRIPTIONINITIALIZE pfOpcUaEndpointDescriptionInitialize;
	#define EXT_OpcUaEndpointDescriptionInitialize  extern PFOPCUAENDPOINTDESCRIPTIONINITIALIZE pfOpcUaEndpointDescriptionInitialize;
	#define GET_OpcUaEndpointDescriptionInitialize(fl)  s_pfCMGetAPI2( "OpcUaEndpointDescriptionInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaEndpointDescriptionInitialize, (fl), 0, 0)
	#define CAL_OpcUaEndpointDescriptionInitialize  pfOpcUaEndpointDescriptionInitialize
	#define CHK_OpcUaEndpointDescriptionInitialize  (pfOpcUaEndpointDescriptionInitialize != NULL)
	#define EXP_OpcUaEndpointDescriptionInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointDescriptionInitialize", (RTS_UINTPTR)OpcUaEndpointDescriptionInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaEndpointDescriptionClear(OpcUa_EndpointDescription* pValue);
typedef OpcUa_Void (CDECL * PFOPCUAENDPOINTDESCRIPTIONCLEAR) (OpcUa_EndpointDescription* pValue);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAENDPOINTDESCRIPTIONCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaEndpointDescriptionClear
	#define EXT_OpcUaEndpointDescriptionClear
	#define GET_OpcUaEndpointDescriptionClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaEndpointDescriptionClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaEndpointDescriptionClear  FALSE
	#define EXP_OpcUaEndpointDescriptionClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaEndpointDescriptionClear
	#define EXT_OpcUaEndpointDescriptionClear
	#define GET_OpcUaEndpointDescriptionClear(fl)  CAL_CMGETAPI( "OpcUaEndpointDescriptionClear" ) 
	#define CAL_OpcUaEndpointDescriptionClear  OpcUaEndpointDescriptionClear
	#define CHK_OpcUaEndpointDescriptionClear  TRUE
	#define EXP_OpcUaEndpointDescriptionClear  CAL_CMEXPAPI( "OpcUaEndpointDescriptionClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaEndpointDescriptionClear
	#define EXT_OpcUaEndpointDescriptionClear
	#define GET_OpcUaEndpointDescriptionClear(fl)  CAL_CMGETAPI( "OpcUaEndpointDescriptionClear" ) 
	#define CAL_OpcUaEndpointDescriptionClear  OpcUaEndpointDescriptionClear
	#define CHK_OpcUaEndpointDescriptionClear  TRUE
	#define EXP_OpcUaEndpointDescriptionClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointDescriptionClear", (RTS_UINTPTR)OpcUaEndpointDescriptionClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaEndpointDescriptionClear
	#define EXT_CmpOPCUAStackOpcUaEndpointDescriptionClear
	#define GET_CmpOPCUAStackOpcUaEndpointDescriptionClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaEndpointDescriptionClear pICmpOPCUAStack->IOpcUaEndpointDescriptionClear
	#define CHK_CmpOPCUAStackOpcUaEndpointDescriptionClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaEndpointDescriptionClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaEndpointDescriptionClear
	#define EXT_OpcUaEndpointDescriptionClear
	#define GET_OpcUaEndpointDescriptionClear(fl)  CAL_CMGETAPI( "OpcUaEndpointDescriptionClear" ) 
	#define CAL_OpcUaEndpointDescriptionClear pICmpOPCUAStack->IOpcUaEndpointDescriptionClear
	#define CHK_OpcUaEndpointDescriptionClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaEndpointDescriptionClear  CAL_CMEXPAPI( "OpcUaEndpointDescriptionClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaEndpointDescriptionClear  PFOPCUAENDPOINTDESCRIPTIONCLEAR pfOpcUaEndpointDescriptionClear;
	#define EXT_OpcUaEndpointDescriptionClear  extern PFOPCUAENDPOINTDESCRIPTIONCLEAR pfOpcUaEndpointDescriptionClear;
	#define GET_OpcUaEndpointDescriptionClear(fl)  s_pfCMGetAPI2( "OpcUaEndpointDescriptionClear", (RTS_VOID_FCTPTR *)&pfOpcUaEndpointDescriptionClear, (fl), 0, 0)
	#define CAL_OpcUaEndpointDescriptionClear  pfOpcUaEndpointDescriptionClear
	#define CHK_OpcUaEndpointDescriptionClear  (pfOpcUaEndpointDescriptionClear != NULL)
	#define EXP_OpcUaEndpointDescriptionClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointDescriptionClear", (RTS_UINTPTR)OpcUaEndpointDescriptionClear, 0, 0) 
#endif




OpcUa_StatusCode CDECL OpcUaEndpointBeginSendResponse(OpcUa_Endpoint hEndpoint, OpcUa_Handle hContext, OpcUa_Void** ppResponse, OpcUa_EncodeableType** ppResponseType);
typedef OpcUa_StatusCode (CDECL * PFOPCUAENDPOINTBEGINSENDRESPONSE) (OpcUa_Endpoint hEndpoint, OpcUa_Handle hContext, OpcUa_Void** ppResponse, OpcUa_EncodeableType** ppResponseType);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAENDPOINTBEGINSENDRESPONSE_NOTIMPLEMENTED)
	#define USE_OpcUaEndpointBeginSendResponse
	#define EXT_OpcUaEndpointBeginSendResponse
	#define GET_OpcUaEndpointBeginSendResponse(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaEndpointBeginSendResponse(p0,p1,p2,p3)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaEndpointBeginSendResponse  FALSE
	#define EXP_OpcUaEndpointBeginSendResponse  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaEndpointBeginSendResponse
	#define EXT_OpcUaEndpointBeginSendResponse
	#define GET_OpcUaEndpointBeginSendResponse(fl)  CAL_CMGETAPI( "OpcUaEndpointBeginSendResponse" ) 
	#define CAL_OpcUaEndpointBeginSendResponse  OpcUaEndpointBeginSendResponse
	#define CHK_OpcUaEndpointBeginSendResponse  TRUE
	#define EXP_OpcUaEndpointBeginSendResponse  CAL_CMEXPAPI( "OpcUaEndpointBeginSendResponse" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaEndpointBeginSendResponse
	#define EXT_OpcUaEndpointBeginSendResponse
	#define GET_OpcUaEndpointBeginSendResponse(fl)  CAL_CMGETAPI( "OpcUaEndpointBeginSendResponse" ) 
	#define CAL_OpcUaEndpointBeginSendResponse  OpcUaEndpointBeginSendResponse
	#define CHK_OpcUaEndpointBeginSendResponse  TRUE
	#define EXP_OpcUaEndpointBeginSendResponse  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointBeginSendResponse", (RTS_UINTPTR)OpcUaEndpointBeginSendResponse, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaEndpointBeginSendResponse
	#define EXT_CmpOPCUAStackOpcUaEndpointBeginSendResponse
	#define GET_CmpOPCUAStackOpcUaEndpointBeginSendResponse  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaEndpointBeginSendResponse pICmpOPCUAStack->IOpcUaEndpointBeginSendResponse
	#define CHK_CmpOPCUAStackOpcUaEndpointBeginSendResponse (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaEndpointBeginSendResponse  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaEndpointBeginSendResponse
	#define EXT_OpcUaEndpointBeginSendResponse
	#define GET_OpcUaEndpointBeginSendResponse(fl)  CAL_CMGETAPI( "OpcUaEndpointBeginSendResponse" ) 
	#define CAL_OpcUaEndpointBeginSendResponse pICmpOPCUAStack->IOpcUaEndpointBeginSendResponse
	#define CHK_OpcUaEndpointBeginSendResponse (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaEndpointBeginSendResponse  CAL_CMEXPAPI( "OpcUaEndpointBeginSendResponse" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaEndpointBeginSendResponse  PFOPCUAENDPOINTBEGINSENDRESPONSE pfOpcUaEndpointBeginSendResponse;
	#define EXT_OpcUaEndpointBeginSendResponse  extern PFOPCUAENDPOINTBEGINSENDRESPONSE pfOpcUaEndpointBeginSendResponse;
	#define GET_OpcUaEndpointBeginSendResponse(fl)  s_pfCMGetAPI2( "OpcUaEndpointBeginSendResponse", (RTS_VOID_FCTPTR *)&pfOpcUaEndpointBeginSendResponse, (fl), 0, 0)
	#define CAL_OpcUaEndpointBeginSendResponse  pfOpcUaEndpointBeginSendResponse
	#define CHK_OpcUaEndpointBeginSendResponse  (pfOpcUaEndpointBeginSendResponse != NULL)
	#define EXP_OpcUaEndpointBeginSendResponse  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointBeginSendResponse", (RTS_UINTPTR)OpcUaEndpointBeginSendResponse, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaEndpointCancelSendResponse(OpcUa_Endpoint hEndpoint, OpcUa_StatusCode uStatus, OpcUa_String* psReason, OpcUa_Handle* hContext);
typedef OpcUa_StatusCode (CDECL * PFOPCUAENDPOINTCANCELSENDRESPONSE) (OpcUa_Endpoint hEndpoint, OpcUa_StatusCode uStatus, OpcUa_String* psReason, OpcUa_Handle* hContext);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAENDPOINTCANCELSENDRESPONSE_NOTIMPLEMENTED)
	#define USE_OpcUaEndpointCancelSendResponse
	#define EXT_OpcUaEndpointCancelSendResponse
	#define GET_OpcUaEndpointCancelSendResponse(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaEndpointCancelSendResponse(p0,p1,p2,p3)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaEndpointCancelSendResponse  FALSE
	#define EXP_OpcUaEndpointCancelSendResponse  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaEndpointCancelSendResponse
	#define EXT_OpcUaEndpointCancelSendResponse
	#define GET_OpcUaEndpointCancelSendResponse(fl)  CAL_CMGETAPI( "OpcUaEndpointCancelSendResponse" ) 
	#define CAL_OpcUaEndpointCancelSendResponse  OpcUaEndpointCancelSendResponse
	#define CHK_OpcUaEndpointCancelSendResponse  TRUE
	#define EXP_OpcUaEndpointCancelSendResponse  CAL_CMEXPAPI( "OpcUaEndpointCancelSendResponse" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaEndpointCancelSendResponse
	#define EXT_OpcUaEndpointCancelSendResponse
	#define GET_OpcUaEndpointCancelSendResponse(fl)  CAL_CMGETAPI( "OpcUaEndpointCancelSendResponse" ) 
	#define CAL_OpcUaEndpointCancelSendResponse  OpcUaEndpointCancelSendResponse
	#define CHK_OpcUaEndpointCancelSendResponse  TRUE
	#define EXP_OpcUaEndpointCancelSendResponse  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointCancelSendResponse", (RTS_UINTPTR)OpcUaEndpointCancelSendResponse, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaEndpointCancelSendResponse
	#define EXT_CmpOPCUAStackOpcUaEndpointCancelSendResponse
	#define GET_CmpOPCUAStackOpcUaEndpointCancelSendResponse  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaEndpointCancelSendResponse pICmpOPCUAStack->IOpcUaEndpointCancelSendResponse
	#define CHK_CmpOPCUAStackOpcUaEndpointCancelSendResponse (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaEndpointCancelSendResponse  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaEndpointCancelSendResponse
	#define EXT_OpcUaEndpointCancelSendResponse
	#define GET_OpcUaEndpointCancelSendResponse(fl)  CAL_CMGETAPI( "OpcUaEndpointCancelSendResponse" ) 
	#define CAL_OpcUaEndpointCancelSendResponse pICmpOPCUAStack->IOpcUaEndpointCancelSendResponse
	#define CHK_OpcUaEndpointCancelSendResponse (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaEndpointCancelSendResponse  CAL_CMEXPAPI( "OpcUaEndpointCancelSendResponse" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaEndpointCancelSendResponse  PFOPCUAENDPOINTCANCELSENDRESPONSE pfOpcUaEndpointCancelSendResponse;
	#define EXT_OpcUaEndpointCancelSendResponse  extern PFOPCUAENDPOINTCANCELSENDRESPONSE pfOpcUaEndpointCancelSendResponse;
	#define GET_OpcUaEndpointCancelSendResponse(fl)  s_pfCMGetAPI2( "OpcUaEndpointCancelSendResponse", (RTS_VOID_FCTPTR *)&pfOpcUaEndpointCancelSendResponse, (fl), 0, 0)
	#define CAL_OpcUaEndpointCancelSendResponse  pfOpcUaEndpointCancelSendResponse
	#define CHK_OpcUaEndpointCancelSendResponse  (pfOpcUaEndpointCancelSendResponse != NULL)
	#define EXP_OpcUaEndpointCancelSendResponse  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointCancelSendResponse", (RTS_UINTPTR)OpcUaEndpointCancelSendResponse, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaEndpointClose(OpcUa_Endpoint hEndpoint);
typedef OpcUa_StatusCode (CDECL * PFOPCUAENDPOINTCLOSE) (OpcUa_Endpoint hEndpoint);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAENDPOINTCLOSE_NOTIMPLEMENTED)
	#define USE_OpcUaEndpointClose
	#define EXT_OpcUaEndpointClose
	#define GET_OpcUaEndpointClose(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaEndpointClose(p0)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaEndpointClose  FALSE
	#define EXP_OpcUaEndpointClose  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaEndpointClose
	#define EXT_OpcUaEndpointClose
	#define GET_OpcUaEndpointClose(fl)  CAL_CMGETAPI( "OpcUaEndpointClose" ) 
	#define CAL_OpcUaEndpointClose  OpcUaEndpointClose
	#define CHK_OpcUaEndpointClose  TRUE
	#define EXP_OpcUaEndpointClose  CAL_CMEXPAPI( "OpcUaEndpointClose" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaEndpointClose
	#define EXT_OpcUaEndpointClose
	#define GET_OpcUaEndpointClose(fl)  CAL_CMGETAPI( "OpcUaEndpointClose" ) 
	#define CAL_OpcUaEndpointClose  OpcUaEndpointClose
	#define CHK_OpcUaEndpointClose  TRUE
	#define EXP_OpcUaEndpointClose  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointClose", (RTS_UINTPTR)OpcUaEndpointClose, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaEndpointClose
	#define EXT_CmpOPCUAStackOpcUaEndpointClose
	#define GET_CmpOPCUAStackOpcUaEndpointClose  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaEndpointClose pICmpOPCUAStack->IOpcUaEndpointClose
	#define CHK_CmpOPCUAStackOpcUaEndpointClose (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaEndpointClose  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaEndpointClose
	#define EXT_OpcUaEndpointClose
	#define GET_OpcUaEndpointClose(fl)  CAL_CMGETAPI( "OpcUaEndpointClose" ) 
	#define CAL_OpcUaEndpointClose pICmpOPCUAStack->IOpcUaEndpointClose
	#define CHK_OpcUaEndpointClose (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaEndpointClose  CAL_CMEXPAPI( "OpcUaEndpointClose" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaEndpointClose  PFOPCUAENDPOINTCLOSE pfOpcUaEndpointClose;
	#define EXT_OpcUaEndpointClose  extern PFOPCUAENDPOINTCLOSE pfOpcUaEndpointClose;
	#define GET_OpcUaEndpointClose(fl)  s_pfCMGetAPI2( "OpcUaEndpointClose", (RTS_VOID_FCTPTR *)&pfOpcUaEndpointClose, (fl), 0, 0)
	#define CAL_OpcUaEndpointClose  pfOpcUaEndpointClose
	#define CHK_OpcUaEndpointClose  (pfOpcUaEndpointClose != NULL)
	#define EXP_OpcUaEndpointClose  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointClose", (RTS_UINTPTR)OpcUaEndpointClose, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaEndpointCreate(OpcUa_Endpoint* phEndpoint, OpcUa_Endpoint_SerializerType eSerializerType, OpcUa_ServiceType** pSupportedServices);
typedef OpcUa_StatusCode (CDECL * PFOPCUAENDPOINTCREATE) (OpcUa_Endpoint* phEndpoint, OpcUa_Endpoint_SerializerType eSerializerType, OpcUa_ServiceType** pSupportedServices);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAENDPOINTCREATE_NOTIMPLEMENTED)
	#define USE_OpcUaEndpointCreate
	#define EXT_OpcUaEndpointCreate
	#define GET_OpcUaEndpointCreate(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaEndpointCreate(p0,p1,p2)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaEndpointCreate  FALSE
	#define EXP_OpcUaEndpointCreate  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaEndpointCreate
	#define EXT_OpcUaEndpointCreate
	#define GET_OpcUaEndpointCreate(fl)  CAL_CMGETAPI( "OpcUaEndpointCreate" ) 
	#define CAL_OpcUaEndpointCreate  OpcUaEndpointCreate
	#define CHK_OpcUaEndpointCreate  TRUE
	#define EXP_OpcUaEndpointCreate  CAL_CMEXPAPI( "OpcUaEndpointCreate" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaEndpointCreate
	#define EXT_OpcUaEndpointCreate
	#define GET_OpcUaEndpointCreate(fl)  CAL_CMGETAPI( "OpcUaEndpointCreate" ) 
	#define CAL_OpcUaEndpointCreate  OpcUaEndpointCreate
	#define CHK_OpcUaEndpointCreate  TRUE
	#define EXP_OpcUaEndpointCreate  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointCreate", (RTS_UINTPTR)OpcUaEndpointCreate, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaEndpointCreate
	#define EXT_CmpOPCUAStackOpcUaEndpointCreate
	#define GET_CmpOPCUAStackOpcUaEndpointCreate  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaEndpointCreate pICmpOPCUAStack->IOpcUaEndpointCreate
	#define CHK_CmpOPCUAStackOpcUaEndpointCreate (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaEndpointCreate  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaEndpointCreate
	#define EXT_OpcUaEndpointCreate
	#define GET_OpcUaEndpointCreate(fl)  CAL_CMGETAPI( "OpcUaEndpointCreate" ) 
	#define CAL_OpcUaEndpointCreate pICmpOPCUAStack->IOpcUaEndpointCreate
	#define CHK_OpcUaEndpointCreate (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaEndpointCreate  CAL_CMEXPAPI( "OpcUaEndpointCreate" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaEndpointCreate  PFOPCUAENDPOINTCREATE pfOpcUaEndpointCreate;
	#define EXT_OpcUaEndpointCreate  extern PFOPCUAENDPOINTCREATE pfOpcUaEndpointCreate;
	#define GET_OpcUaEndpointCreate(fl)  s_pfCMGetAPI2( "OpcUaEndpointCreate", (RTS_VOID_FCTPTR *)&pfOpcUaEndpointCreate, (fl), 0, 0)
	#define CAL_OpcUaEndpointCreate  pfOpcUaEndpointCreate
	#define CHK_OpcUaEndpointCreate  (pfOpcUaEndpointCreate != NULL)
	#define EXP_OpcUaEndpointCreate  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointCreate", (RTS_UINTPTR)OpcUaEndpointCreate, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaEndpointDelete(OpcUa_Endpoint* phEndpoint);
typedef OpcUa_Void (CDECL * PFOPCUAENDPOINTDELETE) (OpcUa_Endpoint* phEndpoint);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAENDPOINTDELETE_NOTIMPLEMENTED)
	#define USE_OpcUaEndpointDelete
	#define EXT_OpcUaEndpointDelete
	#define GET_OpcUaEndpointDelete(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaEndpointDelete(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaEndpointDelete  FALSE
	#define EXP_OpcUaEndpointDelete  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaEndpointDelete
	#define EXT_OpcUaEndpointDelete
	#define GET_OpcUaEndpointDelete(fl)  CAL_CMGETAPI( "OpcUaEndpointDelete" ) 
	#define CAL_OpcUaEndpointDelete  OpcUaEndpointDelete
	#define CHK_OpcUaEndpointDelete  TRUE
	#define EXP_OpcUaEndpointDelete  CAL_CMEXPAPI( "OpcUaEndpointDelete" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaEndpointDelete
	#define EXT_OpcUaEndpointDelete
	#define GET_OpcUaEndpointDelete(fl)  CAL_CMGETAPI( "OpcUaEndpointDelete" ) 
	#define CAL_OpcUaEndpointDelete  OpcUaEndpointDelete
	#define CHK_OpcUaEndpointDelete  TRUE
	#define EXP_OpcUaEndpointDelete  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointDelete", (RTS_UINTPTR)OpcUaEndpointDelete, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaEndpointDelete
	#define EXT_CmpOPCUAStackOpcUaEndpointDelete
	#define GET_CmpOPCUAStackOpcUaEndpointDelete  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaEndpointDelete pICmpOPCUAStack->IOpcUaEndpointDelete
	#define CHK_CmpOPCUAStackOpcUaEndpointDelete (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaEndpointDelete  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaEndpointDelete
	#define EXT_OpcUaEndpointDelete
	#define GET_OpcUaEndpointDelete(fl)  CAL_CMGETAPI( "OpcUaEndpointDelete" ) 
	#define CAL_OpcUaEndpointDelete pICmpOPCUAStack->IOpcUaEndpointDelete
	#define CHK_OpcUaEndpointDelete (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaEndpointDelete  CAL_CMEXPAPI( "OpcUaEndpointDelete" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaEndpointDelete  PFOPCUAENDPOINTDELETE pfOpcUaEndpointDelete;
	#define EXT_OpcUaEndpointDelete  extern PFOPCUAENDPOINTDELETE pfOpcUaEndpointDelete;
	#define GET_OpcUaEndpointDelete(fl)  s_pfCMGetAPI2( "OpcUaEndpointDelete", (RTS_VOID_FCTPTR *)&pfOpcUaEndpointDelete, (fl), 0, 0)
	#define CAL_OpcUaEndpointDelete  pfOpcUaEndpointDelete
	#define CHK_OpcUaEndpointDelete  (pfOpcUaEndpointDelete != NULL)
	#define EXP_OpcUaEndpointDelete  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointDelete", (RTS_UINTPTR)OpcUaEndpointDelete, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaEndpointEndSendResponse(OpcUa_Endpoint hEndpoint, OpcUa_Handle* hContext, OpcUa_StatusCode uStatusCode, OpcUa_Void* pResponse, OpcUa_EncodeableType* pResponseType);
typedef OpcUa_StatusCode (CDECL * PFOPCUAENDPOINTENDSENDRESPONSE) (OpcUa_Endpoint hEndpoint, OpcUa_Handle* hContext, OpcUa_StatusCode uStatusCode, OpcUa_Void* pResponse, OpcUa_EncodeableType* pResponseType);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAENDPOINTENDSENDRESPONSE_NOTIMPLEMENTED)
	#define USE_OpcUaEndpointEndSendResponse
	#define EXT_OpcUaEndpointEndSendResponse
	#define GET_OpcUaEndpointEndSendResponse(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaEndpointEndSendResponse(p0,p1,p2,p3,p4)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaEndpointEndSendResponse  FALSE
	#define EXP_OpcUaEndpointEndSendResponse  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaEndpointEndSendResponse
	#define EXT_OpcUaEndpointEndSendResponse
	#define GET_OpcUaEndpointEndSendResponse(fl)  CAL_CMGETAPI( "OpcUaEndpointEndSendResponse" ) 
	#define CAL_OpcUaEndpointEndSendResponse  OpcUaEndpointEndSendResponse
	#define CHK_OpcUaEndpointEndSendResponse  TRUE
	#define EXP_OpcUaEndpointEndSendResponse  CAL_CMEXPAPI( "OpcUaEndpointEndSendResponse" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaEndpointEndSendResponse
	#define EXT_OpcUaEndpointEndSendResponse
	#define GET_OpcUaEndpointEndSendResponse(fl)  CAL_CMGETAPI( "OpcUaEndpointEndSendResponse" ) 
	#define CAL_OpcUaEndpointEndSendResponse  OpcUaEndpointEndSendResponse
	#define CHK_OpcUaEndpointEndSendResponse  TRUE
	#define EXP_OpcUaEndpointEndSendResponse  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointEndSendResponse", (RTS_UINTPTR)OpcUaEndpointEndSendResponse, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaEndpointEndSendResponse
	#define EXT_CmpOPCUAStackOpcUaEndpointEndSendResponse
	#define GET_CmpOPCUAStackOpcUaEndpointEndSendResponse  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaEndpointEndSendResponse pICmpOPCUAStack->IOpcUaEndpointEndSendResponse
	#define CHK_CmpOPCUAStackOpcUaEndpointEndSendResponse (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaEndpointEndSendResponse  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaEndpointEndSendResponse
	#define EXT_OpcUaEndpointEndSendResponse
	#define GET_OpcUaEndpointEndSendResponse(fl)  CAL_CMGETAPI( "OpcUaEndpointEndSendResponse" ) 
	#define CAL_OpcUaEndpointEndSendResponse pICmpOPCUAStack->IOpcUaEndpointEndSendResponse
	#define CHK_OpcUaEndpointEndSendResponse (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaEndpointEndSendResponse  CAL_CMEXPAPI( "OpcUaEndpointEndSendResponse" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaEndpointEndSendResponse  PFOPCUAENDPOINTENDSENDRESPONSE pfOpcUaEndpointEndSendResponse;
	#define EXT_OpcUaEndpointEndSendResponse  extern PFOPCUAENDPOINTENDSENDRESPONSE pfOpcUaEndpointEndSendResponse;
	#define GET_OpcUaEndpointEndSendResponse(fl)  s_pfCMGetAPI2( "OpcUaEndpointEndSendResponse", (RTS_VOID_FCTPTR *)&pfOpcUaEndpointEndSendResponse, (fl), 0, 0)
	#define CAL_OpcUaEndpointEndSendResponse  pfOpcUaEndpointEndSendResponse
	#define CHK_OpcUaEndpointEndSendResponse  (pfOpcUaEndpointEndSendResponse != NULL)
	#define EXP_OpcUaEndpointEndSendResponse  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointEndSendResponse", (RTS_UINTPTR)OpcUaEndpointEndSendResponse, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaEndpointGetMessageSecureChannelId(OpcUa_Endpoint hEndpoint, OpcUa_Handle hContext, OpcUa_UInt32* pSecureChannelId);
typedef OpcUa_StatusCode (CDECL * PFOPCUAENDPOINTGETMESSAGESECURECHANNELID) (OpcUa_Endpoint hEndpoint, OpcUa_Handle hContext, OpcUa_UInt32* pSecureChannelId);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAENDPOINTGETMESSAGESECURECHANNELID_NOTIMPLEMENTED)
	#define USE_OpcUaEndpointGetMessageSecureChannelId
	#define EXT_OpcUaEndpointGetMessageSecureChannelId
	#define GET_OpcUaEndpointGetMessageSecureChannelId(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaEndpointGetMessageSecureChannelId(p0,p1,p2)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaEndpointGetMessageSecureChannelId  FALSE
	#define EXP_OpcUaEndpointGetMessageSecureChannelId  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaEndpointGetMessageSecureChannelId
	#define EXT_OpcUaEndpointGetMessageSecureChannelId
	#define GET_OpcUaEndpointGetMessageSecureChannelId(fl)  CAL_CMGETAPI( "OpcUaEndpointGetMessageSecureChannelId" ) 
	#define CAL_OpcUaEndpointGetMessageSecureChannelId  OpcUaEndpointGetMessageSecureChannelId
	#define CHK_OpcUaEndpointGetMessageSecureChannelId  TRUE
	#define EXP_OpcUaEndpointGetMessageSecureChannelId  CAL_CMEXPAPI( "OpcUaEndpointGetMessageSecureChannelId" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaEndpointGetMessageSecureChannelId
	#define EXT_OpcUaEndpointGetMessageSecureChannelId
	#define GET_OpcUaEndpointGetMessageSecureChannelId(fl)  CAL_CMGETAPI( "OpcUaEndpointGetMessageSecureChannelId" ) 
	#define CAL_OpcUaEndpointGetMessageSecureChannelId  OpcUaEndpointGetMessageSecureChannelId
	#define CHK_OpcUaEndpointGetMessageSecureChannelId  TRUE
	#define EXP_OpcUaEndpointGetMessageSecureChannelId  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointGetMessageSecureChannelId", (RTS_UINTPTR)OpcUaEndpointGetMessageSecureChannelId, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaEndpointGetMessageSecureChannelId
	#define EXT_CmpOPCUAStackOpcUaEndpointGetMessageSecureChannelId
	#define GET_CmpOPCUAStackOpcUaEndpointGetMessageSecureChannelId  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaEndpointGetMessageSecureChannelId pICmpOPCUAStack->IOpcUaEndpointGetMessageSecureChannelId
	#define CHK_CmpOPCUAStackOpcUaEndpointGetMessageSecureChannelId (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaEndpointGetMessageSecureChannelId  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaEndpointGetMessageSecureChannelId
	#define EXT_OpcUaEndpointGetMessageSecureChannelId
	#define GET_OpcUaEndpointGetMessageSecureChannelId(fl)  CAL_CMGETAPI( "OpcUaEndpointGetMessageSecureChannelId" ) 
	#define CAL_OpcUaEndpointGetMessageSecureChannelId pICmpOPCUAStack->IOpcUaEndpointGetMessageSecureChannelId
	#define CHK_OpcUaEndpointGetMessageSecureChannelId (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaEndpointGetMessageSecureChannelId  CAL_CMEXPAPI( "OpcUaEndpointGetMessageSecureChannelId" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaEndpointGetMessageSecureChannelId  PFOPCUAENDPOINTGETMESSAGESECURECHANNELID pfOpcUaEndpointGetMessageSecureChannelId;
	#define EXT_OpcUaEndpointGetMessageSecureChannelId  extern PFOPCUAENDPOINTGETMESSAGESECURECHANNELID pfOpcUaEndpointGetMessageSecureChannelId;
	#define GET_OpcUaEndpointGetMessageSecureChannelId(fl)  s_pfCMGetAPI2( "OpcUaEndpointGetMessageSecureChannelId", (RTS_VOID_FCTPTR *)&pfOpcUaEndpointGetMessageSecureChannelId, (fl), 0, 0)
	#define CAL_OpcUaEndpointGetMessageSecureChannelId  pfOpcUaEndpointGetMessageSecureChannelId
	#define CHK_OpcUaEndpointGetMessageSecureChannelId  (pfOpcUaEndpointGetMessageSecureChannelId != NULL)
	#define EXP_OpcUaEndpointGetMessageSecureChannelId  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointGetMessageSecureChannelId", (RTS_UINTPTR)OpcUaEndpointGetMessageSecureChannelId, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaEndpointGetMessageSecureChannelSecurityPolicy(OpcUa_Endpoint hEndpoint, OpcUa_Handle hContext, OpcUa_Endpoint_SecurityPolicyConfiguration* pSecurityPolicy);
typedef OpcUa_StatusCode (CDECL * PFOPCUAENDPOINTGETMESSAGESECURECHANNELSECURITYPOLICY) (OpcUa_Endpoint hEndpoint, OpcUa_Handle hContext, OpcUa_Endpoint_SecurityPolicyConfiguration* pSecurityPolicy);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAENDPOINTGETMESSAGESECURECHANNELSECURITYPOLICY_NOTIMPLEMENTED)
	#define USE_OpcUaEndpointGetMessageSecureChannelSecurityPolicy
	#define EXT_OpcUaEndpointGetMessageSecureChannelSecurityPolicy
	#define GET_OpcUaEndpointGetMessageSecureChannelSecurityPolicy(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaEndpointGetMessageSecureChannelSecurityPolicy(p0,p1,p2)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaEndpointGetMessageSecureChannelSecurityPolicy  FALSE
	#define EXP_OpcUaEndpointGetMessageSecureChannelSecurityPolicy  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaEndpointGetMessageSecureChannelSecurityPolicy
	#define EXT_OpcUaEndpointGetMessageSecureChannelSecurityPolicy
	#define GET_OpcUaEndpointGetMessageSecureChannelSecurityPolicy(fl)  CAL_CMGETAPI( "OpcUaEndpointGetMessageSecureChannelSecurityPolicy" ) 
	#define CAL_OpcUaEndpointGetMessageSecureChannelSecurityPolicy  OpcUaEndpointGetMessageSecureChannelSecurityPolicy
	#define CHK_OpcUaEndpointGetMessageSecureChannelSecurityPolicy  TRUE
	#define EXP_OpcUaEndpointGetMessageSecureChannelSecurityPolicy  CAL_CMEXPAPI( "OpcUaEndpointGetMessageSecureChannelSecurityPolicy" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaEndpointGetMessageSecureChannelSecurityPolicy
	#define EXT_OpcUaEndpointGetMessageSecureChannelSecurityPolicy
	#define GET_OpcUaEndpointGetMessageSecureChannelSecurityPolicy(fl)  CAL_CMGETAPI( "OpcUaEndpointGetMessageSecureChannelSecurityPolicy" ) 
	#define CAL_OpcUaEndpointGetMessageSecureChannelSecurityPolicy  OpcUaEndpointGetMessageSecureChannelSecurityPolicy
	#define CHK_OpcUaEndpointGetMessageSecureChannelSecurityPolicy  TRUE
	#define EXP_OpcUaEndpointGetMessageSecureChannelSecurityPolicy  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointGetMessageSecureChannelSecurityPolicy", (RTS_UINTPTR)OpcUaEndpointGetMessageSecureChannelSecurityPolicy, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaEndpointGetMessageSecureChannelSecurityPolicy
	#define EXT_CmpOPCUAStackOpcUaEndpointGetMessageSecureChannelSecurityPolicy
	#define GET_CmpOPCUAStackOpcUaEndpointGetMessageSecureChannelSecurityPolicy  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaEndpointGetMessageSecureChannelSecurityPolicy pICmpOPCUAStack->IOpcUaEndpointGetMessageSecureChannelSecurityPolicy
	#define CHK_CmpOPCUAStackOpcUaEndpointGetMessageSecureChannelSecurityPolicy (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaEndpointGetMessageSecureChannelSecurityPolicy  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaEndpointGetMessageSecureChannelSecurityPolicy
	#define EXT_OpcUaEndpointGetMessageSecureChannelSecurityPolicy
	#define GET_OpcUaEndpointGetMessageSecureChannelSecurityPolicy(fl)  CAL_CMGETAPI( "OpcUaEndpointGetMessageSecureChannelSecurityPolicy" ) 
	#define CAL_OpcUaEndpointGetMessageSecureChannelSecurityPolicy pICmpOPCUAStack->IOpcUaEndpointGetMessageSecureChannelSecurityPolicy
	#define CHK_OpcUaEndpointGetMessageSecureChannelSecurityPolicy (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaEndpointGetMessageSecureChannelSecurityPolicy  CAL_CMEXPAPI( "OpcUaEndpointGetMessageSecureChannelSecurityPolicy" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaEndpointGetMessageSecureChannelSecurityPolicy  PFOPCUAENDPOINTGETMESSAGESECURECHANNELSECURITYPOLICY pfOpcUaEndpointGetMessageSecureChannelSecurityPolicy;
	#define EXT_OpcUaEndpointGetMessageSecureChannelSecurityPolicy  extern PFOPCUAENDPOINTGETMESSAGESECURECHANNELSECURITYPOLICY pfOpcUaEndpointGetMessageSecureChannelSecurityPolicy;
	#define GET_OpcUaEndpointGetMessageSecureChannelSecurityPolicy(fl)  s_pfCMGetAPI2( "OpcUaEndpointGetMessageSecureChannelSecurityPolicy", (RTS_VOID_FCTPTR *)&pfOpcUaEndpointGetMessageSecureChannelSecurityPolicy, (fl), 0, 0)
	#define CAL_OpcUaEndpointGetMessageSecureChannelSecurityPolicy  pfOpcUaEndpointGetMessageSecureChannelSecurityPolicy
	#define CHK_OpcUaEndpointGetMessageSecureChannelSecurityPolicy  (pfOpcUaEndpointGetMessageSecureChannelSecurityPolicy != NULL)
	#define EXP_OpcUaEndpointGetMessageSecureChannelSecurityPolicy  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointGetMessageSecureChannelSecurityPolicy", (RTS_UINTPTR)OpcUaEndpointGetMessageSecureChannelSecurityPolicy, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaEndpointOpen(OpcUa_Endpoint hEndpoint, OpcUa_StringA sUrl, OpcUa_StringA sTransportProfileUri, OpcUa_Endpoint_PfnEndpointCallback* pfEndpointCallback, OpcUa_Void* pvEndpointCallbackData, OpcUa_ByteString* pServerCertificate, OpcUa_Key* pServerPrivateKey, OpcUa_Void* pPKIConfig, OpcUa_UInt32 nNoOfSecurityPolicies, OpcUa_Endpoint_SecurityPolicyConfiguration* pSecurityPolicies, OpcUa_SocketManager hSocketManager);
typedef OpcUa_StatusCode (CDECL * PFOPCUAENDPOINTOPEN) (OpcUa_Endpoint hEndpoint, OpcUa_StringA sUrl, OpcUa_StringA sTransportProfileUri, OpcUa_Endpoint_PfnEndpointCallback* pfEndpointCallback, OpcUa_Void* pvEndpointCallbackData, OpcUa_ByteString* pServerCertificate, OpcUa_Key* pServerPrivateKey, OpcUa_Void* pPKIConfig, OpcUa_UInt32 nNoOfSecurityPolicies, OpcUa_Endpoint_SecurityPolicyConfiguration* pSecurityPolicies, OpcUa_SocketManager hSocketManager);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAENDPOINTOPEN_NOTIMPLEMENTED)
	#define USE_OpcUaEndpointOpen
	#define EXT_OpcUaEndpointOpen
	#define GET_OpcUaEndpointOpen(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaEndpointOpen(p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaEndpointOpen  FALSE
	#define EXP_OpcUaEndpointOpen  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaEndpointOpen
	#define EXT_OpcUaEndpointOpen
	#define GET_OpcUaEndpointOpen(fl)  CAL_CMGETAPI( "OpcUaEndpointOpen" ) 
	#define CAL_OpcUaEndpointOpen  OpcUaEndpointOpen
	#define CHK_OpcUaEndpointOpen  TRUE
	#define EXP_OpcUaEndpointOpen  CAL_CMEXPAPI( "OpcUaEndpointOpen" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaEndpointOpen
	#define EXT_OpcUaEndpointOpen
	#define GET_OpcUaEndpointOpen(fl)  CAL_CMGETAPI( "OpcUaEndpointOpen" ) 
	#define CAL_OpcUaEndpointOpen  OpcUaEndpointOpen
	#define CHK_OpcUaEndpointOpen  TRUE
	#define EXP_OpcUaEndpointOpen  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointOpen", (RTS_UINTPTR)OpcUaEndpointOpen, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaEndpointOpen
	#define EXT_CmpOPCUAStackOpcUaEndpointOpen
	#define GET_CmpOPCUAStackOpcUaEndpointOpen  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaEndpointOpen pICmpOPCUAStack->IOpcUaEndpointOpen
	#define CHK_CmpOPCUAStackOpcUaEndpointOpen (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaEndpointOpen  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaEndpointOpen
	#define EXT_OpcUaEndpointOpen
	#define GET_OpcUaEndpointOpen(fl)  CAL_CMGETAPI( "OpcUaEndpointOpen" ) 
	#define CAL_OpcUaEndpointOpen pICmpOPCUAStack->IOpcUaEndpointOpen
	#define CHK_OpcUaEndpointOpen (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaEndpointOpen  CAL_CMEXPAPI( "OpcUaEndpointOpen" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaEndpointOpen  PFOPCUAENDPOINTOPEN pfOpcUaEndpointOpen;
	#define EXT_OpcUaEndpointOpen  extern PFOPCUAENDPOINTOPEN pfOpcUaEndpointOpen;
	#define GET_OpcUaEndpointOpen(fl)  s_pfCMGetAPI2( "OpcUaEndpointOpen", (RTS_VOID_FCTPTR *)&pfOpcUaEndpointOpen, (fl), 0, 0)
	#define CAL_OpcUaEndpointOpen  pfOpcUaEndpointOpen
	#define CHK_OpcUaEndpointOpen  (pfOpcUaEndpointOpen != NULL)
	#define EXP_OpcUaEndpointOpen  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointOpen", (RTS_UINTPTR)OpcUaEndpointOpen, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaEndpointSendErrorResponse(OpcUa_Endpoint hEndpoint, OpcUa_Handle hContext, OpcUa_StatusCode uStatus);
typedef OpcUa_Void (CDECL * PFOPCUAENDPOINTSENDERRORRESPONSE) (OpcUa_Endpoint hEndpoint, OpcUa_Handle hContext, OpcUa_StatusCode uStatus);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAENDPOINTSENDERRORRESPONSE_NOTIMPLEMENTED)
	#define USE_OpcUaEndpointSendErrorResponse
	#define EXT_OpcUaEndpointSendErrorResponse
	#define GET_OpcUaEndpointSendErrorResponse(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaEndpointSendErrorResponse(p0,p1,p2)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaEndpointSendErrorResponse  FALSE
	#define EXP_OpcUaEndpointSendErrorResponse  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaEndpointSendErrorResponse
	#define EXT_OpcUaEndpointSendErrorResponse
	#define GET_OpcUaEndpointSendErrorResponse(fl)  CAL_CMGETAPI( "OpcUaEndpointSendErrorResponse" ) 
	#define CAL_OpcUaEndpointSendErrorResponse  OpcUaEndpointSendErrorResponse
	#define CHK_OpcUaEndpointSendErrorResponse  TRUE
	#define EXP_OpcUaEndpointSendErrorResponse  CAL_CMEXPAPI( "OpcUaEndpointSendErrorResponse" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaEndpointSendErrorResponse
	#define EXT_OpcUaEndpointSendErrorResponse
	#define GET_OpcUaEndpointSendErrorResponse(fl)  CAL_CMGETAPI( "OpcUaEndpointSendErrorResponse" ) 
	#define CAL_OpcUaEndpointSendErrorResponse  OpcUaEndpointSendErrorResponse
	#define CHK_OpcUaEndpointSendErrorResponse  TRUE
	#define EXP_OpcUaEndpointSendErrorResponse  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointSendErrorResponse", (RTS_UINTPTR)OpcUaEndpointSendErrorResponse, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaEndpointSendErrorResponse
	#define EXT_CmpOPCUAStackOpcUaEndpointSendErrorResponse
	#define GET_CmpOPCUAStackOpcUaEndpointSendErrorResponse  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaEndpointSendErrorResponse pICmpOPCUAStack->IOpcUaEndpointSendErrorResponse
	#define CHK_CmpOPCUAStackOpcUaEndpointSendErrorResponse (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaEndpointSendErrorResponse  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaEndpointSendErrorResponse
	#define EXT_OpcUaEndpointSendErrorResponse
	#define GET_OpcUaEndpointSendErrorResponse(fl)  CAL_CMGETAPI( "OpcUaEndpointSendErrorResponse" ) 
	#define CAL_OpcUaEndpointSendErrorResponse pICmpOPCUAStack->IOpcUaEndpointSendErrorResponse
	#define CHK_OpcUaEndpointSendErrorResponse (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaEndpointSendErrorResponse  CAL_CMEXPAPI( "OpcUaEndpointSendErrorResponse" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaEndpointSendErrorResponse  PFOPCUAENDPOINTSENDERRORRESPONSE pfOpcUaEndpointSendErrorResponse;
	#define EXT_OpcUaEndpointSendErrorResponse  extern PFOPCUAENDPOINTSENDERRORRESPONSE pfOpcUaEndpointSendErrorResponse;
	#define GET_OpcUaEndpointSendErrorResponse(fl)  s_pfCMGetAPI2( "OpcUaEndpointSendErrorResponse", (RTS_VOID_FCTPTR *)&pfOpcUaEndpointSendErrorResponse, (fl), 0, 0)
	#define CAL_OpcUaEndpointSendErrorResponse  pfOpcUaEndpointSendErrorResponse
	#define CHK_OpcUaEndpointSendErrorResponse  (pfOpcUaEndpointSendErrorResponse != NULL)
	#define EXP_OpcUaEndpointSendErrorResponse  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointSendErrorResponse", (RTS_UINTPTR)OpcUaEndpointSendErrorResponse, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaEndpointGetServiceFunction(OpcUa_Endpoint hEndpoint, OpcUa_Handle hContext, OpcUa_PfnInvokeService** ppInvoke);
typedef OpcUa_StatusCode (CDECL * PFOPCUAENDPOINTGETSERVICEFUNCTION) (OpcUa_Endpoint hEndpoint, OpcUa_Handle hContext, OpcUa_PfnInvokeService** ppInvoke);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAENDPOINTGETSERVICEFUNCTION_NOTIMPLEMENTED)
	#define USE_OpcUaEndpointGetServiceFunction
	#define EXT_OpcUaEndpointGetServiceFunction
	#define GET_OpcUaEndpointGetServiceFunction(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaEndpointGetServiceFunction(p0,p1,p2)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaEndpointGetServiceFunction  FALSE
	#define EXP_OpcUaEndpointGetServiceFunction  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaEndpointGetServiceFunction
	#define EXT_OpcUaEndpointGetServiceFunction
	#define GET_OpcUaEndpointGetServiceFunction(fl)  CAL_CMGETAPI( "OpcUaEndpointGetServiceFunction" ) 
	#define CAL_OpcUaEndpointGetServiceFunction  OpcUaEndpointGetServiceFunction
	#define CHK_OpcUaEndpointGetServiceFunction  TRUE
	#define EXP_OpcUaEndpointGetServiceFunction  CAL_CMEXPAPI( "OpcUaEndpointGetServiceFunction" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaEndpointGetServiceFunction
	#define EXT_OpcUaEndpointGetServiceFunction
	#define GET_OpcUaEndpointGetServiceFunction(fl)  CAL_CMGETAPI( "OpcUaEndpointGetServiceFunction" ) 
	#define CAL_OpcUaEndpointGetServiceFunction  OpcUaEndpointGetServiceFunction
	#define CHK_OpcUaEndpointGetServiceFunction  TRUE
	#define EXP_OpcUaEndpointGetServiceFunction  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointGetServiceFunction", (RTS_UINTPTR)OpcUaEndpointGetServiceFunction, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaEndpointGetServiceFunction
	#define EXT_CmpOPCUAStackOpcUaEndpointGetServiceFunction
	#define GET_CmpOPCUAStackOpcUaEndpointGetServiceFunction  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaEndpointGetServiceFunction pICmpOPCUAStack->IOpcUaEndpointGetServiceFunction
	#define CHK_CmpOPCUAStackOpcUaEndpointGetServiceFunction (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaEndpointGetServiceFunction  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaEndpointGetServiceFunction
	#define EXT_OpcUaEndpointGetServiceFunction
	#define GET_OpcUaEndpointGetServiceFunction(fl)  CAL_CMGETAPI( "OpcUaEndpointGetServiceFunction" ) 
	#define CAL_OpcUaEndpointGetServiceFunction pICmpOPCUAStack->IOpcUaEndpointGetServiceFunction
	#define CHK_OpcUaEndpointGetServiceFunction (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaEndpointGetServiceFunction  CAL_CMEXPAPI( "OpcUaEndpointGetServiceFunction" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaEndpointGetServiceFunction  PFOPCUAENDPOINTGETSERVICEFUNCTION pfOpcUaEndpointGetServiceFunction;
	#define EXT_OpcUaEndpointGetServiceFunction  extern PFOPCUAENDPOINTGETSERVICEFUNCTION pfOpcUaEndpointGetServiceFunction;
	#define GET_OpcUaEndpointGetServiceFunction(fl)  s_pfCMGetAPI2( "OpcUaEndpointGetServiceFunction", (RTS_VOID_FCTPTR *)&pfOpcUaEndpointGetServiceFunction, (fl), 0, 0)
	#define CAL_OpcUaEndpointGetServiceFunction  pfOpcUaEndpointGetServiceFunction
	#define CHK_OpcUaEndpointGetServiceFunction  (pfOpcUaEndpointGetServiceFunction != NULL)
	#define EXP_OpcUaEndpointGetServiceFunction  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointGetServiceFunction", (RTS_UINTPTR)OpcUaEndpointGetServiceFunction, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaEndpointUpdateServiceFunctions(OpcUa_Endpoint hEndpoint, OpcUa_UInt32 uRequestTypeId, OpcUa_PfnBeginInvokeService* pBeginInvoke, OpcUa_PfnInvokeService* pInvoke);
typedef OpcUa_StatusCode (CDECL * PFOPCUAENDPOINTUPDATESERVICEFUNCTIONS) (OpcUa_Endpoint hEndpoint, OpcUa_UInt32 uRequestTypeId, OpcUa_PfnBeginInvokeService* pBeginInvoke, OpcUa_PfnInvokeService* pInvoke);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAENDPOINTUPDATESERVICEFUNCTIONS_NOTIMPLEMENTED)
	#define USE_OpcUaEndpointUpdateServiceFunctions
	#define EXT_OpcUaEndpointUpdateServiceFunctions
	#define GET_OpcUaEndpointUpdateServiceFunctions(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaEndpointUpdateServiceFunctions(p0,p1,p2,p3)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaEndpointUpdateServiceFunctions  FALSE
	#define EXP_OpcUaEndpointUpdateServiceFunctions  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaEndpointUpdateServiceFunctions
	#define EXT_OpcUaEndpointUpdateServiceFunctions
	#define GET_OpcUaEndpointUpdateServiceFunctions(fl)  CAL_CMGETAPI( "OpcUaEndpointUpdateServiceFunctions" ) 
	#define CAL_OpcUaEndpointUpdateServiceFunctions  OpcUaEndpointUpdateServiceFunctions
	#define CHK_OpcUaEndpointUpdateServiceFunctions  TRUE
	#define EXP_OpcUaEndpointUpdateServiceFunctions  CAL_CMEXPAPI( "OpcUaEndpointUpdateServiceFunctions" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaEndpointUpdateServiceFunctions
	#define EXT_OpcUaEndpointUpdateServiceFunctions
	#define GET_OpcUaEndpointUpdateServiceFunctions(fl)  CAL_CMGETAPI( "OpcUaEndpointUpdateServiceFunctions" ) 
	#define CAL_OpcUaEndpointUpdateServiceFunctions  OpcUaEndpointUpdateServiceFunctions
	#define CHK_OpcUaEndpointUpdateServiceFunctions  TRUE
	#define EXP_OpcUaEndpointUpdateServiceFunctions  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointUpdateServiceFunctions", (RTS_UINTPTR)OpcUaEndpointUpdateServiceFunctions, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaEndpointUpdateServiceFunctions
	#define EXT_CmpOPCUAStackOpcUaEndpointUpdateServiceFunctions
	#define GET_CmpOPCUAStackOpcUaEndpointUpdateServiceFunctions  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaEndpointUpdateServiceFunctions pICmpOPCUAStack->IOpcUaEndpointUpdateServiceFunctions
	#define CHK_CmpOPCUAStackOpcUaEndpointUpdateServiceFunctions (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaEndpointUpdateServiceFunctions  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaEndpointUpdateServiceFunctions
	#define EXT_OpcUaEndpointUpdateServiceFunctions
	#define GET_OpcUaEndpointUpdateServiceFunctions(fl)  CAL_CMGETAPI( "OpcUaEndpointUpdateServiceFunctions" ) 
	#define CAL_OpcUaEndpointUpdateServiceFunctions pICmpOPCUAStack->IOpcUaEndpointUpdateServiceFunctions
	#define CHK_OpcUaEndpointUpdateServiceFunctions (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaEndpointUpdateServiceFunctions  CAL_CMEXPAPI( "OpcUaEndpointUpdateServiceFunctions" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaEndpointUpdateServiceFunctions  PFOPCUAENDPOINTUPDATESERVICEFUNCTIONS pfOpcUaEndpointUpdateServiceFunctions;
	#define EXT_OpcUaEndpointUpdateServiceFunctions  extern PFOPCUAENDPOINTUPDATESERVICEFUNCTIONS pfOpcUaEndpointUpdateServiceFunctions;
	#define GET_OpcUaEndpointUpdateServiceFunctions(fl)  s_pfCMGetAPI2( "OpcUaEndpointUpdateServiceFunctions", (RTS_VOID_FCTPTR *)&pfOpcUaEndpointUpdateServiceFunctions, (fl), 0, 0)
	#define CAL_OpcUaEndpointUpdateServiceFunctions  pfOpcUaEndpointUpdateServiceFunctions
	#define CHK_OpcUaEndpointUpdateServiceFunctions  (pfOpcUaEndpointUpdateServiceFunctions != NULL)
	#define EXP_OpcUaEndpointUpdateServiceFunctions  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointUpdateServiceFunctions", (RTS_UINTPTR)OpcUaEndpointUpdateServiceFunctions, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaEndpointGetCallbackData(OpcUa_Endpoint hEndpoint, OpcUa_Void** ppvCallbackData);
typedef OpcUa_StatusCode (CDECL * PFOPCUAENDPOINTGETCALLBACKDATA) (OpcUa_Endpoint hEndpoint, OpcUa_Void** ppvCallbackData);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAENDPOINTGETCALLBACKDATA_NOTIMPLEMENTED)
	#define USE_OpcUaEndpointGetCallbackData
	#define EXT_OpcUaEndpointGetCallbackData
	#define GET_OpcUaEndpointGetCallbackData(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaEndpointGetCallbackData(p0,p1)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaEndpointGetCallbackData  FALSE
	#define EXP_OpcUaEndpointGetCallbackData  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaEndpointGetCallbackData
	#define EXT_OpcUaEndpointGetCallbackData
	#define GET_OpcUaEndpointGetCallbackData(fl)  CAL_CMGETAPI( "OpcUaEndpointGetCallbackData" ) 
	#define CAL_OpcUaEndpointGetCallbackData  OpcUaEndpointGetCallbackData
	#define CHK_OpcUaEndpointGetCallbackData  TRUE
	#define EXP_OpcUaEndpointGetCallbackData  CAL_CMEXPAPI( "OpcUaEndpointGetCallbackData" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaEndpointGetCallbackData
	#define EXT_OpcUaEndpointGetCallbackData
	#define GET_OpcUaEndpointGetCallbackData(fl)  CAL_CMGETAPI( "OpcUaEndpointGetCallbackData" ) 
	#define CAL_OpcUaEndpointGetCallbackData  OpcUaEndpointGetCallbackData
	#define CHK_OpcUaEndpointGetCallbackData  TRUE
	#define EXP_OpcUaEndpointGetCallbackData  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointGetCallbackData", (RTS_UINTPTR)OpcUaEndpointGetCallbackData, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaEndpointGetCallbackData
	#define EXT_CmpOPCUAStackOpcUaEndpointGetCallbackData
	#define GET_CmpOPCUAStackOpcUaEndpointGetCallbackData  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaEndpointGetCallbackData pICmpOPCUAStack->IOpcUaEndpointGetCallbackData
	#define CHK_CmpOPCUAStackOpcUaEndpointGetCallbackData (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaEndpointGetCallbackData  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaEndpointGetCallbackData
	#define EXT_OpcUaEndpointGetCallbackData
	#define GET_OpcUaEndpointGetCallbackData(fl)  CAL_CMGETAPI( "OpcUaEndpointGetCallbackData" ) 
	#define CAL_OpcUaEndpointGetCallbackData pICmpOPCUAStack->IOpcUaEndpointGetCallbackData
	#define CHK_OpcUaEndpointGetCallbackData (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaEndpointGetCallbackData  CAL_CMEXPAPI( "OpcUaEndpointGetCallbackData" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaEndpointGetCallbackData  PFOPCUAENDPOINTGETCALLBACKDATA pfOpcUaEndpointGetCallbackData;
	#define EXT_OpcUaEndpointGetCallbackData  extern PFOPCUAENDPOINTGETCALLBACKDATA pfOpcUaEndpointGetCallbackData;
	#define GET_OpcUaEndpointGetCallbackData(fl)  s_pfCMGetAPI2( "OpcUaEndpointGetCallbackData", (RTS_VOID_FCTPTR *)&pfOpcUaEndpointGetCallbackData, (fl), 0, 0)
	#define CAL_OpcUaEndpointGetCallbackData  pfOpcUaEndpointGetCallbackData
	#define CHK_OpcUaEndpointGetCallbackData  (pfOpcUaEndpointGetCallbackData != NULL)
	#define EXP_OpcUaEndpointGetCallbackData  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointGetCallbackData", (RTS_UINTPTR)OpcUaEndpointGetCallbackData, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaEndpointGetPeerInfoFromContext(OpcUa_Endpoint hEndpoint, OpcUa_Handle hContext, OpcUa_String* psPeerInfo);
typedef OpcUa_StatusCode (CDECL * PFOPCUAENDPOINTGETPEERINFOFROMCONTEXT) (OpcUa_Endpoint hEndpoint, OpcUa_Handle hContext, OpcUa_String* psPeerInfo);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAENDPOINTGETPEERINFOFROMCONTEXT_NOTIMPLEMENTED)
	#define USE_OpcUaEndpointGetPeerInfoFromContext
	#define EXT_OpcUaEndpointGetPeerInfoFromContext
	#define GET_OpcUaEndpointGetPeerInfoFromContext(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaEndpointGetPeerInfoFromContext(p0,p1,p2)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaEndpointGetPeerInfoFromContext  FALSE
	#define EXP_OpcUaEndpointGetPeerInfoFromContext  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaEndpointGetPeerInfoFromContext
	#define EXT_OpcUaEndpointGetPeerInfoFromContext
	#define GET_OpcUaEndpointGetPeerInfoFromContext(fl)  CAL_CMGETAPI( "OpcUaEndpointGetPeerInfoFromContext" ) 
	#define CAL_OpcUaEndpointGetPeerInfoFromContext  OpcUaEndpointGetPeerInfoFromContext
	#define CHK_OpcUaEndpointGetPeerInfoFromContext  TRUE
	#define EXP_OpcUaEndpointGetPeerInfoFromContext  CAL_CMEXPAPI( "OpcUaEndpointGetPeerInfoFromContext" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaEndpointGetPeerInfoFromContext
	#define EXT_OpcUaEndpointGetPeerInfoFromContext
	#define GET_OpcUaEndpointGetPeerInfoFromContext(fl)  CAL_CMGETAPI( "OpcUaEndpointGetPeerInfoFromContext" ) 
	#define CAL_OpcUaEndpointGetPeerInfoFromContext  OpcUaEndpointGetPeerInfoFromContext
	#define CHK_OpcUaEndpointGetPeerInfoFromContext  TRUE
	#define EXP_OpcUaEndpointGetPeerInfoFromContext  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointGetPeerInfoFromContext", (RTS_UINTPTR)OpcUaEndpointGetPeerInfoFromContext, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaEndpointGetPeerInfoFromContext
	#define EXT_CmpOPCUAStackOpcUaEndpointGetPeerInfoFromContext
	#define GET_CmpOPCUAStackOpcUaEndpointGetPeerInfoFromContext  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaEndpointGetPeerInfoFromContext pICmpOPCUAStack->IOpcUaEndpointGetPeerInfoFromContext
	#define CHK_CmpOPCUAStackOpcUaEndpointGetPeerInfoFromContext (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaEndpointGetPeerInfoFromContext  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaEndpointGetPeerInfoFromContext
	#define EXT_OpcUaEndpointGetPeerInfoFromContext
	#define GET_OpcUaEndpointGetPeerInfoFromContext(fl)  CAL_CMGETAPI( "OpcUaEndpointGetPeerInfoFromContext" ) 
	#define CAL_OpcUaEndpointGetPeerInfoFromContext pICmpOPCUAStack->IOpcUaEndpointGetPeerInfoFromContext
	#define CHK_OpcUaEndpointGetPeerInfoFromContext (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaEndpointGetPeerInfoFromContext  CAL_CMEXPAPI( "OpcUaEndpointGetPeerInfoFromContext" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaEndpointGetPeerInfoFromContext  PFOPCUAENDPOINTGETPEERINFOFROMCONTEXT pfOpcUaEndpointGetPeerInfoFromContext;
	#define EXT_OpcUaEndpointGetPeerInfoFromContext  extern PFOPCUAENDPOINTGETPEERINFOFROMCONTEXT pfOpcUaEndpointGetPeerInfoFromContext;
	#define GET_OpcUaEndpointGetPeerInfoFromContext(fl)  s_pfCMGetAPI2( "OpcUaEndpointGetPeerInfoFromContext", (RTS_VOID_FCTPTR *)&pfOpcUaEndpointGetPeerInfoFromContext, (fl), 0, 0)
	#define CAL_OpcUaEndpointGetPeerInfoFromContext  pfOpcUaEndpointGetPeerInfoFromContext
	#define CHK_OpcUaEndpointGetPeerInfoFromContext  (pfOpcUaEndpointGetPeerInfoFromContext != NULL)
	#define EXP_OpcUaEndpointGetPeerInfoFromContext  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaEndpointGetPeerInfoFromContext", (RTS_UINTPTR)OpcUaEndpointGetPeerInfoFromContext, 0, 0) 
#endif




OpcUa_StatusCode CDECL OpcUaTimerCreate(OpcUa_Timer* hTimer, OpcUa_UInt32 msecInterval, OpcUa_Timer_Callback* fpTimerCallback, OpcUa_Timer_Callback* fpKillCallback, OpcUa_Void* pvCallbackData);
typedef OpcUa_StatusCode (CDECL * PFOPCUATIMERCREATE) (OpcUa_Timer* hTimer, OpcUa_UInt32 msecInterval, OpcUa_Timer_Callback* fpTimerCallback, OpcUa_Timer_Callback* fpKillCallback, OpcUa_Void* pvCallbackData);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUATIMERCREATE_NOTIMPLEMENTED)
	#define USE_OpcUaTimerCreate
	#define EXT_OpcUaTimerCreate
	#define GET_OpcUaTimerCreate(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaTimerCreate(p0,p1,p2,p3,p4)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaTimerCreate  FALSE
	#define EXP_OpcUaTimerCreate  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaTimerCreate
	#define EXT_OpcUaTimerCreate
	#define GET_OpcUaTimerCreate(fl)  CAL_CMGETAPI( "OpcUaTimerCreate" ) 
	#define CAL_OpcUaTimerCreate  OpcUaTimerCreate
	#define CHK_OpcUaTimerCreate  TRUE
	#define EXP_OpcUaTimerCreate  CAL_CMEXPAPI( "OpcUaTimerCreate" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaTimerCreate
	#define EXT_OpcUaTimerCreate
	#define GET_OpcUaTimerCreate(fl)  CAL_CMGETAPI( "OpcUaTimerCreate" ) 
	#define CAL_OpcUaTimerCreate  OpcUaTimerCreate
	#define CHK_OpcUaTimerCreate  TRUE
	#define EXP_OpcUaTimerCreate  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaTimerCreate", (RTS_UINTPTR)OpcUaTimerCreate, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaTimerCreate
	#define EXT_CmpOPCUAStackOpcUaTimerCreate
	#define GET_CmpOPCUAStackOpcUaTimerCreate  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaTimerCreate pICmpOPCUAStack->IOpcUaTimerCreate
	#define CHK_CmpOPCUAStackOpcUaTimerCreate (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaTimerCreate  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaTimerCreate
	#define EXT_OpcUaTimerCreate
	#define GET_OpcUaTimerCreate(fl)  CAL_CMGETAPI( "OpcUaTimerCreate" ) 
	#define CAL_OpcUaTimerCreate pICmpOPCUAStack->IOpcUaTimerCreate
	#define CHK_OpcUaTimerCreate (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaTimerCreate  CAL_CMEXPAPI( "OpcUaTimerCreate" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaTimerCreate  PFOPCUATIMERCREATE pfOpcUaTimerCreate;
	#define EXT_OpcUaTimerCreate  extern PFOPCUATIMERCREATE pfOpcUaTimerCreate;
	#define GET_OpcUaTimerCreate(fl)  s_pfCMGetAPI2( "OpcUaTimerCreate", (RTS_VOID_FCTPTR *)&pfOpcUaTimerCreate, (fl), 0, 0)
	#define CAL_OpcUaTimerCreate  pfOpcUaTimerCreate
	#define CHK_OpcUaTimerCreate  (pfOpcUaTimerCreate != NULL)
	#define EXP_OpcUaTimerCreate  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaTimerCreate", (RTS_UINTPTR)OpcUaTimerCreate, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaTimerDelete(OpcUa_Timer* phTimer);
typedef OpcUa_StatusCode (CDECL * PFOPCUATIMERDELETE) (OpcUa_Timer* phTimer);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUATIMERDELETE_NOTIMPLEMENTED)
	#define USE_OpcUaTimerDelete
	#define EXT_OpcUaTimerDelete
	#define GET_OpcUaTimerDelete(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaTimerDelete(p0)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaTimerDelete  FALSE
	#define EXP_OpcUaTimerDelete  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaTimerDelete
	#define EXT_OpcUaTimerDelete
	#define GET_OpcUaTimerDelete(fl)  CAL_CMGETAPI( "OpcUaTimerDelete" ) 
	#define CAL_OpcUaTimerDelete  OpcUaTimerDelete
	#define CHK_OpcUaTimerDelete  TRUE
	#define EXP_OpcUaTimerDelete  CAL_CMEXPAPI( "OpcUaTimerDelete" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaTimerDelete
	#define EXT_OpcUaTimerDelete
	#define GET_OpcUaTimerDelete(fl)  CAL_CMGETAPI( "OpcUaTimerDelete" ) 
	#define CAL_OpcUaTimerDelete  OpcUaTimerDelete
	#define CHK_OpcUaTimerDelete  TRUE
	#define EXP_OpcUaTimerDelete  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaTimerDelete", (RTS_UINTPTR)OpcUaTimerDelete, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaTimerDelete
	#define EXT_CmpOPCUAStackOpcUaTimerDelete
	#define GET_CmpOPCUAStackOpcUaTimerDelete  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaTimerDelete pICmpOPCUAStack->IOpcUaTimerDelete
	#define CHK_CmpOPCUAStackOpcUaTimerDelete (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaTimerDelete  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaTimerDelete
	#define EXT_OpcUaTimerDelete
	#define GET_OpcUaTimerDelete(fl)  CAL_CMGETAPI( "OpcUaTimerDelete" ) 
	#define CAL_OpcUaTimerDelete pICmpOPCUAStack->IOpcUaTimerDelete
	#define CHK_OpcUaTimerDelete (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaTimerDelete  CAL_CMEXPAPI( "OpcUaTimerDelete" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaTimerDelete  PFOPCUATIMERDELETE pfOpcUaTimerDelete;
	#define EXT_OpcUaTimerDelete  extern PFOPCUATIMERDELETE pfOpcUaTimerDelete;
	#define GET_OpcUaTimerDelete(fl)  s_pfCMGetAPI2( "OpcUaTimerDelete", (RTS_VOID_FCTPTR *)&pfOpcUaTimerDelete, (fl), 0, 0)
	#define CAL_OpcUaTimerDelete  pfOpcUaTimerDelete
	#define CHK_OpcUaTimerDelete  (pfOpcUaTimerDelete != NULL)
	#define EXP_OpcUaTimerDelete  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaTimerDelete", (RTS_UINTPTR)OpcUaTimerDelete, 0, 0) 
#endif




OpcUa_StatusCode CDECL OpcUaSocketManagerLoop(OpcUa_SocketManager pSocketManager, OpcUa_UInt32 msecTimeout, OpcUa_Boolean bRunOnce);
typedef OpcUa_StatusCode (CDECL * PFOPCUASOCKETMANAGERLOOP) (OpcUa_SocketManager pSocketManager, OpcUa_UInt32 msecTimeout, OpcUa_Boolean bRunOnce);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASOCKETMANAGERLOOP_NOTIMPLEMENTED)
	#define USE_OpcUaSocketManagerLoop
	#define EXT_OpcUaSocketManagerLoop
	#define GET_OpcUaSocketManagerLoop(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaSocketManagerLoop(p0,p1,p2)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaSocketManagerLoop  FALSE
	#define EXP_OpcUaSocketManagerLoop  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaSocketManagerLoop
	#define EXT_OpcUaSocketManagerLoop
	#define GET_OpcUaSocketManagerLoop(fl)  CAL_CMGETAPI( "OpcUaSocketManagerLoop" ) 
	#define CAL_OpcUaSocketManagerLoop  OpcUaSocketManagerLoop
	#define CHK_OpcUaSocketManagerLoop  TRUE
	#define EXP_OpcUaSocketManagerLoop  CAL_CMEXPAPI( "OpcUaSocketManagerLoop" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaSocketManagerLoop
	#define EXT_OpcUaSocketManagerLoop
	#define GET_OpcUaSocketManagerLoop(fl)  CAL_CMGETAPI( "OpcUaSocketManagerLoop" ) 
	#define CAL_OpcUaSocketManagerLoop  OpcUaSocketManagerLoop
	#define CHK_OpcUaSocketManagerLoop  TRUE
	#define EXP_OpcUaSocketManagerLoop  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSocketManagerLoop", (RTS_UINTPTR)OpcUaSocketManagerLoop, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaSocketManagerLoop
	#define EXT_CmpOPCUAStackOpcUaSocketManagerLoop
	#define GET_CmpOPCUAStackOpcUaSocketManagerLoop  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaSocketManagerLoop pICmpOPCUAStack->IOpcUaSocketManagerLoop
	#define CHK_CmpOPCUAStackOpcUaSocketManagerLoop (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaSocketManagerLoop  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaSocketManagerLoop
	#define EXT_OpcUaSocketManagerLoop
	#define GET_OpcUaSocketManagerLoop(fl)  CAL_CMGETAPI( "OpcUaSocketManagerLoop" ) 
	#define CAL_OpcUaSocketManagerLoop pICmpOPCUAStack->IOpcUaSocketManagerLoop
	#define CHK_OpcUaSocketManagerLoop (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaSocketManagerLoop  CAL_CMEXPAPI( "OpcUaSocketManagerLoop" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaSocketManagerLoop  PFOPCUASOCKETMANAGERLOOP pfOpcUaSocketManagerLoop;
	#define EXT_OpcUaSocketManagerLoop  extern PFOPCUASOCKETMANAGERLOOP pfOpcUaSocketManagerLoop;
	#define GET_OpcUaSocketManagerLoop(fl)  s_pfCMGetAPI2( "OpcUaSocketManagerLoop", (RTS_VOID_FCTPTR *)&pfOpcUaSocketManagerLoop, (fl), 0, 0)
	#define CAL_OpcUaSocketManagerLoop  pfOpcUaSocketManagerLoop
	#define CHK_OpcUaSocketManagerLoop  (pfOpcUaSocketManagerLoop != NULL)
	#define EXP_OpcUaSocketManagerLoop  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSocketManagerLoop", (RTS_UINTPTR)OpcUaSocketManagerLoop, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaSocketManagerCreate(OpcUa_SocketManager* pSocketManager, OpcUa_UInt32 nSockets,	OpcUa_UInt32 nFlags);
typedef OpcUa_StatusCode (CDECL * PFOPCUASOCKETMANAGERCREATE) (OpcUa_SocketManager* pSocketManager, OpcUa_UInt32 nSockets,	OpcUa_UInt32 nFlags);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASOCKETMANAGERCREATE_NOTIMPLEMENTED)
	#define USE_OpcUaSocketManagerCreate
	#define EXT_OpcUaSocketManagerCreate
	#define GET_OpcUaSocketManagerCreate(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaSocketManagerCreate(p0,p1,p2)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaSocketManagerCreate  FALSE
	#define EXP_OpcUaSocketManagerCreate  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaSocketManagerCreate
	#define EXT_OpcUaSocketManagerCreate
	#define GET_OpcUaSocketManagerCreate(fl)  CAL_CMGETAPI( "OpcUaSocketManagerCreate" ) 
	#define CAL_OpcUaSocketManagerCreate  OpcUaSocketManagerCreate
	#define CHK_OpcUaSocketManagerCreate  TRUE
	#define EXP_OpcUaSocketManagerCreate  CAL_CMEXPAPI( "OpcUaSocketManagerCreate" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaSocketManagerCreate
	#define EXT_OpcUaSocketManagerCreate
	#define GET_OpcUaSocketManagerCreate(fl)  CAL_CMGETAPI( "OpcUaSocketManagerCreate" ) 
	#define CAL_OpcUaSocketManagerCreate  OpcUaSocketManagerCreate
	#define CHK_OpcUaSocketManagerCreate  TRUE
	#define EXP_OpcUaSocketManagerCreate  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSocketManagerCreate", (RTS_UINTPTR)OpcUaSocketManagerCreate, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaSocketManagerCreate
	#define EXT_CmpOPCUAStackOpcUaSocketManagerCreate
	#define GET_CmpOPCUAStackOpcUaSocketManagerCreate  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaSocketManagerCreate pICmpOPCUAStack->IOpcUaSocketManagerCreate
	#define CHK_CmpOPCUAStackOpcUaSocketManagerCreate (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaSocketManagerCreate  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaSocketManagerCreate
	#define EXT_OpcUaSocketManagerCreate
	#define GET_OpcUaSocketManagerCreate(fl)  CAL_CMGETAPI( "OpcUaSocketManagerCreate" ) 
	#define CAL_OpcUaSocketManagerCreate pICmpOPCUAStack->IOpcUaSocketManagerCreate
	#define CHK_OpcUaSocketManagerCreate (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaSocketManagerCreate  CAL_CMEXPAPI( "OpcUaSocketManagerCreate" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaSocketManagerCreate  PFOPCUASOCKETMANAGERCREATE pfOpcUaSocketManagerCreate;
	#define EXT_OpcUaSocketManagerCreate  extern PFOPCUASOCKETMANAGERCREATE pfOpcUaSocketManagerCreate;
	#define GET_OpcUaSocketManagerCreate(fl)  s_pfCMGetAPI2( "OpcUaSocketManagerCreate", (RTS_VOID_FCTPTR *)&pfOpcUaSocketManagerCreate, (fl), 0, 0)
	#define CAL_OpcUaSocketManagerCreate  pfOpcUaSocketManagerCreate
	#define CHK_OpcUaSocketManagerCreate  (pfOpcUaSocketManagerCreate != NULL)
	#define EXP_OpcUaSocketManagerCreate  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSocketManagerCreate", (RTS_UINTPTR)OpcUaSocketManagerCreate, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaSocketManagerDelete(OpcUa_SocketManager* pSocketManager);
typedef OpcUa_Void (CDECL * PFOPCUASOCKETMANAGERDELETE) (OpcUa_SocketManager* pSocketManager);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASOCKETMANAGERDELETE_NOTIMPLEMENTED)
	#define USE_OpcUaSocketManagerDelete
	#define EXT_OpcUaSocketManagerDelete
	#define GET_OpcUaSocketManagerDelete(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaSocketManagerDelete(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaSocketManagerDelete  FALSE
	#define EXP_OpcUaSocketManagerDelete  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaSocketManagerDelete
	#define EXT_OpcUaSocketManagerDelete
	#define GET_OpcUaSocketManagerDelete(fl)  CAL_CMGETAPI( "OpcUaSocketManagerDelete" ) 
	#define CAL_OpcUaSocketManagerDelete  OpcUaSocketManagerDelete
	#define CHK_OpcUaSocketManagerDelete  TRUE
	#define EXP_OpcUaSocketManagerDelete  CAL_CMEXPAPI( "OpcUaSocketManagerDelete" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaSocketManagerDelete
	#define EXT_OpcUaSocketManagerDelete
	#define GET_OpcUaSocketManagerDelete(fl)  CAL_CMGETAPI( "OpcUaSocketManagerDelete" ) 
	#define CAL_OpcUaSocketManagerDelete  OpcUaSocketManagerDelete
	#define CHK_OpcUaSocketManagerDelete  TRUE
	#define EXP_OpcUaSocketManagerDelete  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSocketManagerDelete", (RTS_UINTPTR)OpcUaSocketManagerDelete, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaSocketManagerDelete
	#define EXT_CmpOPCUAStackOpcUaSocketManagerDelete
	#define GET_CmpOPCUAStackOpcUaSocketManagerDelete  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaSocketManagerDelete pICmpOPCUAStack->IOpcUaSocketManagerDelete
	#define CHK_CmpOPCUAStackOpcUaSocketManagerDelete (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaSocketManagerDelete  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaSocketManagerDelete
	#define EXT_OpcUaSocketManagerDelete
	#define GET_OpcUaSocketManagerDelete(fl)  CAL_CMGETAPI( "OpcUaSocketManagerDelete" ) 
	#define CAL_OpcUaSocketManagerDelete pICmpOPCUAStack->IOpcUaSocketManagerDelete
	#define CHK_OpcUaSocketManagerDelete (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaSocketManagerDelete  CAL_CMEXPAPI( "OpcUaSocketManagerDelete" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaSocketManagerDelete  PFOPCUASOCKETMANAGERDELETE pfOpcUaSocketManagerDelete;
	#define EXT_OpcUaSocketManagerDelete  extern PFOPCUASOCKETMANAGERDELETE pfOpcUaSocketManagerDelete;
	#define GET_OpcUaSocketManagerDelete(fl)  s_pfCMGetAPI2( "OpcUaSocketManagerDelete", (RTS_VOID_FCTPTR *)&pfOpcUaSocketManagerDelete, (fl), 0, 0)
	#define CAL_OpcUaSocketManagerDelete  pfOpcUaSocketManagerDelete
	#define CHK_OpcUaSocketManagerDelete  (pfOpcUaSocketManagerDelete != NULL)
	#define EXP_OpcUaSocketManagerDelete  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSocketManagerDelete", (RTS_UINTPTR)OpcUaSocketManagerDelete, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaServerApiCreateFault(OpcUa_RequestHeader* pRequestHeader, OpcUa_StatusCode uServiceResult, OpcUa_DiagnosticInfo* pServiceDiagnostics, OpcUa_Int32* pNoOfStringTable, OpcUa_String** ppStringTable, OpcUa_Void** ppFault, OpcUa_EncodeableType** ppFaultType);
typedef OpcUa_StatusCode (CDECL * PFOPCUASERVERAPICREATEFAULT) (OpcUa_RequestHeader* pRequestHeader, OpcUa_StatusCode uServiceResult, OpcUa_DiagnosticInfo* pServiceDiagnostics, OpcUa_Int32* pNoOfStringTable, OpcUa_String** ppStringTable, OpcUa_Void** ppFault, OpcUa_EncodeableType** ppFaultType);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASERVERAPICREATEFAULT_NOTIMPLEMENTED)
	#define USE_OpcUaServerApiCreateFault
	#define EXT_OpcUaServerApiCreateFault
	#define GET_OpcUaServerApiCreateFault(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaServerApiCreateFault(p0,p1,p2,p3,p4,p5,p6)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaServerApiCreateFault  FALSE
	#define EXP_OpcUaServerApiCreateFault  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaServerApiCreateFault
	#define EXT_OpcUaServerApiCreateFault
	#define GET_OpcUaServerApiCreateFault(fl)  CAL_CMGETAPI( "OpcUaServerApiCreateFault" ) 
	#define CAL_OpcUaServerApiCreateFault  OpcUaServerApiCreateFault
	#define CHK_OpcUaServerApiCreateFault  TRUE
	#define EXP_OpcUaServerApiCreateFault  CAL_CMEXPAPI( "OpcUaServerApiCreateFault" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaServerApiCreateFault
	#define EXT_OpcUaServerApiCreateFault
	#define GET_OpcUaServerApiCreateFault(fl)  CAL_CMGETAPI( "OpcUaServerApiCreateFault" ) 
	#define CAL_OpcUaServerApiCreateFault  OpcUaServerApiCreateFault
	#define CHK_OpcUaServerApiCreateFault  TRUE
	#define EXP_OpcUaServerApiCreateFault  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaServerApiCreateFault", (RTS_UINTPTR)OpcUaServerApiCreateFault, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaServerApiCreateFault
	#define EXT_CmpOPCUAStackOpcUaServerApiCreateFault
	#define GET_CmpOPCUAStackOpcUaServerApiCreateFault  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaServerApiCreateFault pICmpOPCUAStack->IOpcUaServerApiCreateFault
	#define CHK_CmpOPCUAStackOpcUaServerApiCreateFault (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaServerApiCreateFault  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaServerApiCreateFault
	#define EXT_OpcUaServerApiCreateFault
	#define GET_OpcUaServerApiCreateFault(fl)  CAL_CMGETAPI( "OpcUaServerApiCreateFault" ) 
	#define CAL_OpcUaServerApiCreateFault pICmpOPCUAStack->IOpcUaServerApiCreateFault
	#define CHK_OpcUaServerApiCreateFault (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaServerApiCreateFault  CAL_CMEXPAPI( "OpcUaServerApiCreateFault" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaServerApiCreateFault  PFOPCUASERVERAPICREATEFAULT pfOpcUaServerApiCreateFault;
	#define EXT_OpcUaServerApiCreateFault  extern PFOPCUASERVERAPICREATEFAULT pfOpcUaServerApiCreateFault;
	#define GET_OpcUaServerApiCreateFault(fl)  s_pfCMGetAPI2( "OpcUaServerApiCreateFault", (RTS_VOID_FCTPTR *)&pfOpcUaServerApiCreateFault, (fl), 0, 0)
	#define CAL_OpcUaServerApiCreateFault  pfOpcUaServerApiCreateFault
	#define CHK_OpcUaServerApiCreateFault  (pfOpcUaServerApiCreateFault != NULL)
	#define EXP_OpcUaServerApiCreateFault  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaServerApiCreateFault", (RTS_UINTPTR)OpcUaServerApiCreateFault, 0, 0) 
#endif




/**
 * <description>Get the adress of an encodable object type description. This adress can be passed directly to OpcUaEncodableObjectCreate or OpcUaEncodableObjectCreateExtension.
 * As ui32TypeId use the OpcUaId_... Macros. If the type is not available the function will return NULL.</description>
 */
OpcUa_EncodeableType* CDECL OpcUaGetEncodableObjectType(OpcUa_UInt32 ui32TypeId);
typedef OpcUa_EncodeableType* (CDECL * PFOPCUAGETENCODABLEOBJECTTYPE) (OpcUa_UInt32 ui32TypeId);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAGETENCODABLEOBJECTTYPE_NOTIMPLEMENTED)
	#define USE_OpcUaGetEncodableObjectType
	#define EXT_OpcUaGetEncodableObjectType
	#define GET_OpcUaGetEncodableObjectType(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaGetEncodableObjectType(p0)  (OpcUa_EncodeableType*)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaGetEncodableObjectType  FALSE
	#define EXP_OpcUaGetEncodableObjectType  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaGetEncodableObjectType
	#define EXT_OpcUaGetEncodableObjectType
	#define GET_OpcUaGetEncodableObjectType(fl)  CAL_CMGETAPI( "OpcUaGetEncodableObjectType" ) 
	#define CAL_OpcUaGetEncodableObjectType  OpcUaGetEncodableObjectType
	#define CHK_OpcUaGetEncodableObjectType  TRUE
	#define EXP_OpcUaGetEncodableObjectType  CAL_CMEXPAPI( "OpcUaGetEncodableObjectType" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaGetEncodableObjectType
	#define EXT_OpcUaGetEncodableObjectType
	#define GET_OpcUaGetEncodableObjectType(fl)  CAL_CMGETAPI( "OpcUaGetEncodableObjectType" ) 
	#define CAL_OpcUaGetEncodableObjectType  OpcUaGetEncodableObjectType
	#define CHK_OpcUaGetEncodableObjectType  TRUE
	#define EXP_OpcUaGetEncodableObjectType  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaGetEncodableObjectType", (RTS_UINTPTR)OpcUaGetEncodableObjectType, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaGetEncodableObjectType
	#define EXT_CmpOPCUAStackOpcUaGetEncodableObjectType
	#define GET_CmpOPCUAStackOpcUaGetEncodableObjectType  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaGetEncodableObjectType pICmpOPCUAStack->IOpcUaGetEncodableObjectType
	#define CHK_CmpOPCUAStackOpcUaGetEncodableObjectType (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaGetEncodableObjectType  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaGetEncodableObjectType
	#define EXT_OpcUaGetEncodableObjectType
	#define GET_OpcUaGetEncodableObjectType(fl)  CAL_CMGETAPI( "OpcUaGetEncodableObjectType" ) 
	#define CAL_OpcUaGetEncodableObjectType pICmpOPCUAStack->IOpcUaGetEncodableObjectType
	#define CHK_OpcUaGetEncodableObjectType (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaGetEncodableObjectType  CAL_CMEXPAPI( "OpcUaGetEncodableObjectType" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaGetEncodableObjectType  PFOPCUAGETENCODABLEOBJECTTYPE pfOpcUaGetEncodableObjectType;
	#define EXT_OpcUaGetEncodableObjectType  extern PFOPCUAGETENCODABLEOBJECTTYPE pfOpcUaGetEncodableObjectType;
	#define GET_OpcUaGetEncodableObjectType(fl)  s_pfCMGetAPI2( "OpcUaGetEncodableObjectType", (RTS_VOID_FCTPTR *)&pfOpcUaGetEncodableObjectType, (fl), 0, 0)
	#define CAL_OpcUaGetEncodableObjectType  pfOpcUaGetEncodableObjectType
	#define CHK_OpcUaGetEncodableObjectType  (pfOpcUaGetEncodableObjectType != NULL)
	#define EXP_OpcUaGetEncodableObjectType  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaGetEncodableObjectType", (RTS_UINTPTR)OpcUaGetEncodableObjectType, 0, 0) 
#endif



OpcUa_PfnBeginInvokeService* CDECL OpcUaGetBeginServiceFunction(OpcUa_UInt32 ui32ServiceId);
typedef OpcUa_PfnBeginInvokeService* (CDECL * PFOPCUAGETBEGINSERVICEFUNCTION) (OpcUa_UInt32 ui32ServiceId);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAGETBEGINSERVICEFUNCTION_NOTIMPLEMENTED)
	#define USE_OpcUaGetBeginServiceFunction
	#define EXT_OpcUaGetBeginServiceFunction
	#define GET_OpcUaGetBeginServiceFunction(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaGetBeginServiceFunction(p0)  (OpcUa_PfnBeginInvokeService*)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaGetBeginServiceFunction  FALSE
	#define EXP_OpcUaGetBeginServiceFunction  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaGetBeginServiceFunction
	#define EXT_OpcUaGetBeginServiceFunction
	#define GET_OpcUaGetBeginServiceFunction(fl)  CAL_CMGETAPI( "OpcUaGetBeginServiceFunction" ) 
	#define CAL_OpcUaGetBeginServiceFunction  OpcUaGetBeginServiceFunction
	#define CHK_OpcUaGetBeginServiceFunction  TRUE
	#define EXP_OpcUaGetBeginServiceFunction  CAL_CMEXPAPI( "OpcUaGetBeginServiceFunction" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaGetBeginServiceFunction
	#define EXT_OpcUaGetBeginServiceFunction
	#define GET_OpcUaGetBeginServiceFunction(fl)  CAL_CMGETAPI( "OpcUaGetBeginServiceFunction" ) 
	#define CAL_OpcUaGetBeginServiceFunction  OpcUaGetBeginServiceFunction
	#define CHK_OpcUaGetBeginServiceFunction  TRUE
	#define EXP_OpcUaGetBeginServiceFunction  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaGetBeginServiceFunction", (RTS_UINTPTR)OpcUaGetBeginServiceFunction, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaGetBeginServiceFunction
	#define EXT_CmpOPCUAStackOpcUaGetBeginServiceFunction
	#define GET_CmpOPCUAStackOpcUaGetBeginServiceFunction  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaGetBeginServiceFunction pICmpOPCUAStack->IOpcUaGetBeginServiceFunction
	#define CHK_CmpOPCUAStackOpcUaGetBeginServiceFunction (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaGetBeginServiceFunction  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaGetBeginServiceFunction
	#define EXT_OpcUaGetBeginServiceFunction
	#define GET_OpcUaGetBeginServiceFunction(fl)  CAL_CMGETAPI( "OpcUaGetBeginServiceFunction" ) 
	#define CAL_OpcUaGetBeginServiceFunction pICmpOPCUAStack->IOpcUaGetBeginServiceFunction
	#define CHK_OpcUaGetBeginServiceFunction (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaGetBeginServiceFunction  CAL_CMEXPAPI( "OpcUaGetBeginServiceFunction" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaGetBeginServiceFunction  PFOPCUAGETBEGINSERVICEFUNCTION pfOpcUaGetBeginServiceFunction;
	#define EXT_OpcUaGetBeginServiceFunction  extern PFOPCUAGETBEGINSERVICEFUNCTION pfOpcUaGetBeginServiceFunction;
	#define GET_OpcUaGetBeginServiceFunction(fl)  s_pfCMGetAPI2( "OpcUaGetBeginServiceFunction", (RTS_VOID_FCTPTR *)&pfOpcUaGetBeginServiceFunction, (fl), 0, 0)
	#define CAL_OpcUaGetBeginServiceFunction  pfOpcUaGetBeginServiceFunction
	#define CHK_OpcUaGetBeginServiceFunction  (pfOpcUaGetBeginServiceFunction != NULL)
	#define EXP_OpcUaGetBeginServiceFunction  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaGetBeginServiceFunction", (RTS_UINTPTR)OpcUaGetBeginServiceFunction, 0, 0) 
#endif




/* OPC UA Crypto interface */
OpcUa_StatusCode CDECL OpcUaStackConvertAsymmetricKey(RtsCryptoKey* rtsKey, OpcUa_Boolean bPrivateKey, OpcUa_Key* opcuaKey);
typedef OpcUa_StatusCode (CDECL * PFOPCUASTACKCONVERTASYMMETRICKEY) (RtsCryptoKey* rtsKey, OpcUa_Boolean bPrivateKey, OpcUa_Key* opcuaKey);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASTACKCONVERTASYMMETRICKEY_NOTIMPLEMENTED)
	#define USE_OpcUaStackConvertAsymmetricKey
	#define EXT_OpcUaStackConvertAsymmetricKey
	#define GET_OpcUaStackConvertAsymmetricKey(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaStackConvertAsymmetricKey(p0,p1,p2)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaStackConvertAsymmetricKey  FALSE
	#define EXP_OpcUaStackConvertAsymmetricKey  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaStackConvertAsymmetricKey
	#define EXT_OpcUaStackConvertAsymmetricKey
	#define GET_OpcUaStackConvertAsymmetricKey(fl)  CAL_CMGETAPI( "OpcUaStackConvertAsymmetricKey" ) 
	#define CAL_OpcUaStackConvertAsymmetricKey  OpcUaStackConvertAsymmetricKey
	#define CHK_OpcUaStackConvertAsymmetricKey  TRUE
	#define EXP_OpcUaStackConvertAsymmetricKey  CAL_CMEXPAPI( "OpcUaStackConvertAsymmetricKey" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaStackConvertAsymmetricKey
	#define EXT_OpcUaStackConvertAsymmetricKey
	#define GET_OpcUaStackConvertAsymmetricKey(fl)  CAL_CMGETAPI( "OpcUaStackConvertAsymmetricKey" ) 
	#define CAL_OpcUaStackConvertAsymmetricKey  OpcUaStackConvertAsymmetricKey
	#define CHK_OpcUaStackConvertAsymmetricKey  TRUE
	#define EXP_OpcUaStackConvertAsymmetricKey  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStackConvertAsymmetricKey", (RTS_UINTPTR)OpcUaStackConvertAsymmetricKey, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaStackConvertAsymmetricKey
	#define EXT_CmpOPCUAStackOpcUaStackConvertAsymmetricKey
	#define GET_CmpOPCUAStackOpcUaStackConvertAsymmetricKey  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaStackConvertAsymmetricKey pICmpOPCUAStack->IOpcUaStackConvertAsymmetricKey
	#define CHK_CmpOPCUAStackOpcUaStackConvertAsymmetricKey (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaStackConvertAsymmetricKey  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaStackConvertAsymmetricKey
	#define EXT_OpcUaStackConvertAsymmetricKey
	#define GET_OpcUaStackConvertAsymmetricKey(fl)  CAL_CMGETAPI( "OpcUaStackConvertAsymmetricKey" ) 
	#define CAL_OpcUaStackConvertAsymmetricKey pICmpOPCUAStack->IOpcUaStackConvertAsymmetricKey
	#define CHK_OpcUaStackConvertAsymmetricKey (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaStackConvertAsymmetricKey  CAL_CMEXPAPI( "OpcUaStackConvertAsymmetricKey" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaStackConvertAsymmetricKey  PFOPCUASTACKCONVERTASYMMETRICKEY pfOpcUaStackConvertAsymmetricKey;
	#define EXT_OpcUaStackConvertAsymmetricKey  extern PFOPCUASTACKCONVERTASYMMETRICKEY pfOpcUaStackConvertAsymmetricKey;
	#define GET_OpcUaStackConvertAsymmetricKey(fl)  s_pfCMGetAPI2( "OpcUaStackConvertAsymmetricKey", (RTS_VOID_FCTPTR *)&pfOpcUaStackConvertAsymmetricKey, (fl), 0, 0)
	#define CAL_OpcUaStackConvertAsymmetricKey  pfOpcUaStackConvertAsymmetricKey
	#define CHK_OpcUaStackConvertAsymmetricKey  (pfOpcUaStackConvertAsymmetricKey != NULL)
	#define EXP_OpcUaStackConvertAsymmetricKey  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStackConvertAsymmetricKey", (RTS_UINTPTR)OpcUaStackConvertAsymmetricKey, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaSignatureInitialize(OpcUa_Signature* pSignature);
typedef OpcUa_Void (CDECL * PFOPCUASIGNATUREINITIALIZE) (OpcUa_Signature* pSignature);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASIGNATUREINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaSignatureInitialize
	#define EXT_OpcUaSignatureInitialize
	#define GET_OpcUaSignatureInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaSignatureInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaSignatureInitialize  FALSE
	#define EXP_OpcUaSignatureInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaSignatureInitialize
	#define EXT_OpcUaSignatureInitialize
	#define GET_OpcUaSignatureInitialize(fl)  CAL_CMGETAPI( "OpcUaSignatureInitialize" ) 
	#define CAL_OpcUaSignatureInitialize  OpcUaSignatureInitialize
	#define CHK_OpcUaSignatureInitialize  TRUE
	#define EXP_OpcUaSignatureInitialize  CAL_CMEXPAPI( "OpcUaSignatureInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaSignatureInitialize
	#define EXT_OpcUaSignatureInitialize
	#define GET_OpcUaSignatureInitialize(fl)  CAL_CMGETAPI( "OpcUaSignatureInitialize" ) 
	#define CAL_OpcUaSignatureInitialize  OpcUaSignatureInitialize
	#define CHK_OpcUaSignatureInitialize  TRUE
	#define EXP_OpcUaSignatureInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSignatureInitialize", (RTS_UINTPTR)OpcUaSignatureInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaSignatureInitialize
	#define EXT_CmpOPCUAStackOpcUaSignatureInitialize
	#define GET_CmpOPCUAStackOpcUaSignatureInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaSignatureInitialize pICmpOPCUAStack->IOpcUaSignatureInitialize
	#define CHK_CmpOPCUAStackOpcUaSignatureInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaSignatureInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaSignatureInitialize
	#define EXT_OpcUaSignatureInitialize
	#define GET_OpcUaSignatureInitialize(fl)  CAL_CMGETAPI( "OpcUaSignatureInitialize" ) 
	#define CAL_OpcUaSignatureInitialize pICmpOPCUAStack->IOpcUaSignatureInitialize
	#define CHK_OpcUaSignatureInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaSignatureInitialize  CAL_CMEXPAPI( "OpcUaSignatureInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaSignatureInitialize  PFOPCUASIGNATUREINITIALIZE pfOpcUaSignatureInitialize;
	#define EXT_OpcUaSignatureInitialize  extern PFOPCUASIGNATUREINITIALIZE pfOpcUaSignatureInitialize;
	#define GET_OpcUaSignatureInitialize(fl)  s_pfCMGetAPI2( "OpcUaSignatureInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaSignatureInitialize, (fl), 0, 0)
	#define CAL_OpcUaSignatureInitialize  pfOpcUaSignatureInitialize
	#define CHK_OpcUaSignatureInitialize  (pfOpcUaSignatureInitialize != NULL)
	#define EXP_OpcUaSignatureInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSignatureInitialize", (RTS_UINTPTR)OpcUaSignatureInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaSignatureClear(OpcUa_Signature* pSignature);
typedef OpcUa_Void (CDECL * PFOPCUASIGNATURECLEAR) (OpcUa_Signature* pSignature);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASIGNATURECLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaSignatureClear
	#define EXT_OpcUaSignatureClear
	#define GET_OpcUaSignatureClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaSignatureClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaSignatureClear  FALSE
	#define EXP_OpcUaSignatureClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaSignatureClear
	#define EXT_OpcUaSignatureClear
	#define GET_OpcUaSignatureClear(fl)  CAL_CMGETAPI( "OpcUaSignatureClear" ) 
	#define CAL_OpcUaSignatureClear  OpcUaSignatureClear
	#define CHK_OpcUaSignatureClear  TRUE
	#define EXP_OpcUaSignatureClear  CAL_CMEXPAPI( "OpcUaSignatureClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaSignatureClear
	#define EXT_OpcUaSignatureClear
	#define GET_OpcUaSignatureClear(fl)  CAL_CMGETAPI( "OpcUaSignatureClear" ) 
	#define CAL_OpcUaSignatureClear  OpcUaSignatureClear
	#define CHK_OpcUaSignatureClear  TRUE
	#define EXP_OpcUaSignatureClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSignatureClear", (RTS_UINTPTR)OpcUaSignatureClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaSignatureClear
	#define EXT_CmpOPCUAStackOpcUaSignatureClear
	#define GET_CmpOPCUAStackOpcUaSignatureClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaSignatureClear pICmpOPCUAStack->IOpcUaSignatureClear
	#define CHK_CmpOPCUAStackOpcUaSignatureClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaSignatureClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaSignatureClear
	#define EXT_OpcUaSignatureClear
	#define GET_OpcUaSignatureClear(fl)  CAL_CMGETAPI( "OpcUaSignatureClear" ) 
	#define CAL_OpcUaSignatureClear pICmpOPCUAStack->IOpcUaSignatureClear
	#define CHK_OpcUaSignatureClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaSignatureClear  CAL_CMEXPAPI( "OpcUaSignatureClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaSignatureClear  PFOPCUASIGNATURECLEAR pfOpcUaSignatureClear;
	#define EXT_OpcUaSignatureClear  extern PFOPCUASIGNATURECLEAR pfOpcUaSignatureClear;
	#define GET_OpcUaSignatureClear(fl)  s_pfCMGetAPI2( "OpcUaSignatureClear", (RTS_VOID_FCTPTR *)&pfOpcUaSignatureClear, (fl), 0, 0)
	#define CAL_OpcUaSignatureClear  pfOpcUaSignatureClear
	#define CHK_OpcUaSignatureClear  (pfOpcUaSignatureClear != NULL)
	#define EXP_OpcUaSignatureClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaSignatureClear", (RTS_UINTPTR)OpcUaSignatureClear, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaKeyInitialize(OpcUa_Key* pKey);
typedef OpcUa_Void (CDECL * PFOPCUAKEYINITIALIZE) (OpcUa_Key* pKey);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAKEYINITIALIZE_NOTIMPLEMENTED)
	#define USE_OpcUaKeyInitialize
	#define EXT_OpcUaKeyInitialize
	#define GET_OpcUaKeyInitialize(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaKeyInitialize(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaKeyInitialize  FALSE
	#define EXP_OpcUaKeyInitialize  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaKeyInitialize
	#define EXT_OpcUaKeyInitialize
	#define GET_OpcUaKeyInitialize(fl)  CAL_CMGETAPI( "OpcUaKeyInitialize" ) 
	#define CAL_OpcUaKeyInitialize  OpcUaKeyInitialize
	#define CHK_OpcUaKeyInitialize  TRUE
	#define EXP_OpcUaKeyInitialize  CAL_CMEXPAPI( "OpcUaKeyInitialize" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaKeyInitialize
	#define EXT_OpcUaKeyInitialize
	#define GET_OpcUaKeyInitialize(fl)  CAL_CMGETAPI( "OpcUaKeyInitialize" ) 
	#define CAL_OpcUaKeyInitialize  OpcUaKeyInitialize
	#define CHK_OpcUaKeyInitialize  TRUE
	#define EXP_OpcUaKeyInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaKeyInitialize", (RTS_UINTPTR)OpcUaKeyInitialize, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaKeyInitialize
	#define EXT_CmpOPCUAStackOpcUaKeyInitialize
	#define GET_CmpOPCUAStackOpcUaKeyInitialize  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaKeyInitialize pICmpOPCUAStack->IOpcUaKeyInitialize
	#define CHK_CmpOPCUAStackOpcUaKeyInitialize (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaKeyInitialize  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaKeyInitialize
	#define EXT_OpcUaKeyInitialize
	#define GET_OpcUaKeyInitialize(fl)  CAL_CMGETAPI( "OpcUaKeyInitialize" ) 
	#define CAL_OpcUaKeyInitialize pICmpOPCUAStack->IOpcUaKeyInitialize
	#define CHK_OpcUaKeyInitialize (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaKeyInitialize  CAL_CMEXPAPI( "OpcUaKeyInitialize" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaKeyInitialize  PFOPCUAKEYINITIALIZE pfOpcUaKeyInitialize;
	#define EXT_OpcUaKeyInitialize  extern PFOPCUAKEYINITIALIZE pfOpcUaKeyInitialize;
	#define GET_OpcUaKeyInitialize(fl)  s_pfCMGetAPI2( "OpcUaKeyInitialize", (RTS_VOID_FCTPTR *)&pfOpcUaKeyInitialize, (fl), 0, 0)
	#define CAL_OpcUaKeyInitialize  pfOpcUaKeyInitialize
	#define CHK_OpcUaKeyInitialize  (pfOpcUaKeyInitialize != NULL)
	#define EXP_OpcUaKeyInitialize  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaKeyInitialize", (RTS_UINTPTR)OpcUaKeyInitialize, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaKeyClear(OpcUa_Key* pKey);
typedef OpcUa_Void (CDECL * PFOPCUAKEYCLEAR) (OpcUa_Key* pKey);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUAKEYCLEAR_NOTIMPLEMENTED)
	#define USE_OpcUaKeyClear
	#define EXT_OpcUaKeyClear
	#define GET_OpcUaKeyClear(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaKeyClear(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaKeyClear  FALSE
	#define EXP_OpcUaKeyClear  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaKeyClear
	#define EXT_OpcUaKeyClear
	#define GET_OpcUaKeyClear(fl)  CAL_CMGETAPI( "OpcUaKeyClear" ) 
	#define CAL_OpcUaKeyClear  OpcUaKeyClear
	#define CHK_OpcUaKeyClear  TRUE
	#define EXP_OpcUaKeyClear  CAL_CMEXPAPI( "OpcUaKeyClear" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaKeyClear
	#define EXT_OpcUaKeyClear
	#define GET_OpcUaKeyClear(fl)  CAL_CMGETAPI( "OpcUaKeyClear" ) 
	#define CAL_OpcUaKeyClear  OpcUaKeyClear
	#define CHK_OpcUaKeyClear  TRUE
	#define EXP_OpcUaKeyClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaKeyClear", (RTS_UINTPTR)OpcUaKeyClear, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaKeyClear
	#define EXT_CmpOPCUAStackOpcUaKeyClear
	#define GET_CmpOPCUAStackOpcUaKeyClear  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaKeyClear pICmpOPCUAStack->IOpcUaKeyClear
	#define CHK_CmpOPCUAStackOpcUaKeyClear (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaKeyClear  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaKeyClear
	#define EXT_OpcUaKeyClear
	#define GET_OpcUaKeyClear(fl)  CAL_CMGETAPI( "OpcUaKeyClear" ) 
	#define CAL_OpcUaKeyClear pICmpOPCUAStack->IOpcUaKeyClear
	#define CHK_OpcUaKeyClear (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaKeyClear  CAL_CMEXPAPI( "OpcUaKeyClear" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaKeyClear  PFOPCUAKEYCLEAR pfOpcUaKeyClear;
	#define EXT_OpcUaKeyClear  extern PFOPCUAKEYCLEAR pfOpcUaKeyClear;
	#define GET_OpcUaKeyClear(fl)  s_pfCMGetAPI2( "OpcUaKeyClear", (RTS_VOID_FCTPTR *)&pfOpcUaKeyClear, (fl), 0, 0)
	#define CAL_OpcUaKeyClear  pfOpcUaKeyClear
	#define CHK_OpcUaKeyClear  (pfOpcUaKeyClear != NULL)
	#define EXP_OpcUaKeyClear  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaKeyClear", (RTS_UINTPTR)OpcUaKeyClear, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaCryptoGenerateKey(OpcUa_CryptoProvider* pProvider, OpcUa_Int32 keyLen, OpcUa_Key* pKey);
typedef OpcUa_StatusCode (CDECL * PFOPCUACRYPTOGENERATEKEY) (OpcUa_CryptoProvider* pProvider, OpcUa_Int32 keyLen, OpcUa_Key* pKey);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACRYPTOGENERATEKEY_NOTIMPLEMENTED)
	#define USE_OpcUaCryptoGenerateKey
	#define EXT_OpcUaCryptoGenerateKey
	#define GET_OpcUaCryptoGenerateKey(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaCryptoGenerateKey(p0,p1,p2)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaCryptoGenerateKey  FALSE
	#define EXP_OpcUaCryptoGenerateKey  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaCryptoGenerateKey
	#define EXT_OpcUaCryptoGenerateKey
	#define GET_OpcUaCryptoGenerateKey(fl)  CAL_CMGETAPI( "OpcUaCryptoGenerateKey" ) 
	#define CAL_OpcUaCryptoGenerateKey  OpcUaCryptoGenerateKey
	#define CHK_OpcUaCryptoGenerateKey  TRUE
	#define EXP_OpcUaCryptoGenerateKey  CAL_CMEXPAPI( "OpcUaCryptoGenerateKey" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaCryptoGenerateKey
	#define EXT_OpcUaCryptoGenerateKey
	#define GET_OpcUaCryptoGenerateKey(fl)  CAL_CMGETAPI( "OpcUaCryptoGenerateKey" ) 
	#define CAL_OpcUaCryptoGenerateKey  OpcUaCryptoGenerateKey
	#define CHK_OpcUaCryptoGenerateKey  TRUE
	#define EXP_OpcUaCryptoGenerateKey  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCryptoGenerateKey", (RTS_UINTPTR)OpcUaCryptoGenerateKey, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaCryptoGenerateKey
	#define EXT_CmpOPCUAStackOpcUaCryptoGenerateKey
	#define GET_CmpOPCUAStackOpcUaCryptoGenerateKey  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaCryptoGenerateKey pICmpOPCUAStack->IOpcUaCryptoGenerateKey
	#define CHK_CmpOPCUAStackOpcUaCryptoGenerateKey (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaCryptoGenerateKey  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaCryptoGenerateKey
	#define EXT_OpcUaCryptoGenerateKey
	#define GET_OpcUaCryptoGenerateKey(fl)  CAL_CMGETAPI( "OpcUaCryptoGenerateKey" ) 
	#define CAL_OpcUaCryptoGenerateKey pICmpOPCUAStack->IOpcUaCryptoGenerateKey
	#define CHK_OpcUaCryptoGenerateKey (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaCryptoGenerateKey  CAL_CMEXPAPI( "OpcUaCryptoGenerateKey" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaCryptoGenerateKey  PFOPCUACRYPTOGENERATEKEY pfOpcUaCryptoGenerateKey;
	#define EXT_OpcUaCryptoGenerateKey  extern PFOPCUACRYPTOGENERATEKEY pfOpcUaCryptoGenerateKey;
	#define GET_OpcUaCryptoGenerateKey(fl)  s_pfCMGetAPI2( "OpcUaCryptoGenerateKey", (RTS_VOID_FCTPTR *)&pfOpcUaCryptoGenerateKey, (fl), 0, 0)
	#define CAL_OpcUaCryptoGenerateKey  pfOpcUaCryptoGenerateKey
	#define CHK_OpcUaCryptoGenerateKey  (pfOpcUaCryptoGenerateKey != NULL)
	#define EXP_OpcUaCryptoGenerateKey  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCryptoGenerateKey", (RTS_UINTPTR)OpcUaCryptoGenerateKey, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaCryptoDeriveKey(OpcUa_CryptoProvider* pProvider, OpcUa_ByteString secret, OpcUa_ByteString seed, OpcUa_Int32 keyLen, OpcUa_Key* pKey);
typedef OpcUa_StatusCode (CDECL * PFOPCUACRYPTODERIVEKEY) (OpcUa_CryptoProvider* pProvider, OpcUa_ByteString secret, OpcUa_ByteString seed, OpcUa_Int32 keyLen, OpcUa_Key* pKey);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACRYPTODERIVEKEY_NOTIMPLEMENTED)
	#define USE_OpcUaCryptoDeriveKey
	#define EXT_OpcUaCryptoDeriveKey
	#define GET_OpcUaCryptoDeriveKey(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaCryptoDeriveKey(p0,p1,p2,p3,p4)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaCryptoDeriveKey  FALSE
	#define EXP_OpcUaCryptoDeriveKey  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaCryptoDeriveKey
	#define EXT_OpcUaCryptoDeriveKey
	#define GET_OpcUaCryptoDeriveKey(fl)  CAL_CMGETAPI( "OpcUaCryptoDeriveKey" ) 
	#define CAL_OpcUaCryptoDeriveKey  OpcUaCryptoDeriveKey
	#define CHK_OpcUaCryptoDeriveKey  TRUE
	#define EXP_OpcUaCryptoDeriveKey  CAL_CMEXPAPI( "OpcUaCryptoDeriveKey" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaCryptoDeriveKey
	#define EXT_OpcUaCryptoDeriveKey
	#define GET_OpcUaCryptoDeriveKey(fl)  CAL_CMGETAPI( "OpcUaCryptoDeriveKey" ) 
	#define CAL_OpcUaCryptoDeriveKey  OpcUaCryptoDeriveKey
	#define CHK_OpcUaCryptoDeriveKey  TRUE
	#define EXP_OpcUaCryptoDeriveKey  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCryptoDeriveKey", (RTS_UINTPTR)OpcUaCryptoDeriveKey, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaCryptoDeriveKey
	#define EXT_CmpOPCUAStackOpcUaCryptoDeriveKey
	#define GET_CmpOPCUAStackOpcUaCryptoDeriveKey  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaCryptoDeriveKey pICmpOPCUAStack->IOpcUaCryptoDeriveKey
	#define CHK_CmpOPCUAStackOpcUaCryptoDeriveKey (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaCryptoDeriveKey  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaCryptoDeriveKey
	#define EXT_OpcUaCryptoDeriveKey
	#define GET_OpcUaCryptoDeriveKey(fl)  CAL_CMGETAPI( "OpcUaCryptoDeriveKey" ) 
	#define CAL_OpcUaCryptoDeriveKey pICmpOPCUAStack->IOpcUaCryptoDeriveKey
	#define CHK_OpcUaCryptoDeriveKey (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaCryptoDeriveKey  CAL_CMEXPAPI( "OpcUaCryptoDeriveKey" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaCryptoDeriveKey  PFOPCUACRYPTODERIVEKEY pfOpcUaCryptoDeriveKey;
	#define EXT_OpcUaCryptoDeriveKey  extern PFOPCUACRYPTODERIVEKEY pfOpcUaCryptoDeriveKey;
	#define GET_OpcUaCryptoDeriveKey(fl)  s_pfCMGetAPI2( "OpcUaCryptoDeriveKey", (RTS_VOID_FCTPTR *)&pfOpcUaCryptoDeriveKey, (fl), 0, 0)
	#define CAL_OpcUaCryptoDeriveKey  pfOpcUaCryptoDeriveKey
	#define CHK_OpcUaCryptoDeriveKey  (pfOpcUaCryptoDeriveKey != NULL)
	#define EXP_OpcUaCryptoDeriveKey  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCryptoDeriveKey", (RTS_UINTPTR)OpcUaCryptoDeriveKey, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaCryptoAsymmetricSign(OpcUa_CryptoProvider* pProvider, OpcUa_ByteString data, OpcUa_Key* privateKey, OpcUa_ByteString* pSignature);
typedef OpcUa_StatusCode (CDECL * PFOPCUACRYPTOASYMMETRICSIGN) (OpcUa_CryptoProvider* pProvider, OpcUa_ByteString data, OpcUa_Key* privateKey, OpcUa_ByteString* pSignature);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACRYPTOASYMMETRICSIGN_NOTIMPLEMENTED)
	#define USE_OpcUaCryptoAsymmetricSign
	#define EXT_OpcUaCryptoAsymmetricSign
	#define GET_OpcUaCryptoAsymmetricSign(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaCryptoAsymmetricSign(p0,p1,p2,p3)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaCryptoAsymmetricSign  FALSE
	#define EXP_OpcUaCryptoAsymmetricSign  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaCryptoAsymmetricSign
	#define EXT_OpcUaCryptoAsymmetricSign
	#define GET_OpcUaCryptoAsymmetricSign(fl)  CAL_CMGETAPI( "OpcUaCryptoAsymmetricSign" ) 
	#define CAL_OpcUaCryptoAsymmetricSign  OpcUaCryptoAsymmetricSign
	#define CHK_OpcUaCryptoAsymmetricSign  TRUE
	#define EXP_OpcUaCryptoAsymmetricSign  CAL_CMEXPAPI( "OpcUaCryptoAsymmetricSign" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaCryptoAsymmetricSign
	#define EXT_OpcUaCryptoAsymmetricSign
	#define GET_OpcUaCryptoAsymmetricSign(fl)  CAL_CMGETAPI( "OpcUaCryptoAsymmetricSign" ) 
	#define CAL_OpcUaCryptoAsymmetricSign  OpcUaCryptoAsymmetricSign
	#define CHK_OpcUaCryptoAsymmetricSign  TRUE
	#define EXP_OpcUaCryptoAsymmetricSign  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCryptoAsymmetricSign", (RTS_UINTPTR)OpcUaCryptoAsymmetricSign, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaCryptoAsymmetricSign
	#define EXT_CmpOPCUAStackOpcUaCryptoAsymmetricSign
	#define GET_CmpOPCUAStackOpcUaCryptoAsymmetricSign  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaCryptoAsymmetricSign pICmpOPCUAStack->IOpcUaCryptoAsymmetricSign
	#define CHK_CmpOPCUAStackOpcUaCryptoAsymmetricSign (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaCryptoAsymmetricSign  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaCryptoAsymmetricSign
	#define EXT_OpcUaCryptoAsymmetricSign
	#define GET_OpcUaCryptoAsymmetricSign(fl)  CAL_CMGETAPI( "OpcUaCryptoAsymmetricSign" ) 
	#define CAL_OpcUaCryptoAsymmetricSign pICmpOPCUAStack->IOpcUaCryptoAsymmetricSign
	#define CHK_OpcUaCryptoAsymmetricSign (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaCryptoAsymmetricSign  CAL_CMEXPAPI( "OpcUaCryptoAsymmetricSign" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaCryptoAsymmetricSign  PFOPCUACRYPTOASYMMETRICSIGN pfOpcUaCryptoAsymmetricSign;
	#define EXT_OpcUaCryptoAsymmetricSign  extern PFOPCUACRYPTOASYMMETRICSIGN pfOpcUaCryptoAsymmetricSign;
	#define GET_OpcUaCryptoAsymmetricSign(fl)  s_pfCMGetAPI2( "OpcUaCryptoAsymmetricSign", (RTS_VOID_FCTPTR *)&pfOpcUaCryptoAsymmetricSign, (fl), 0, 0)
	#define CAL_OpcUaCryptoAsymmetricSign  pfOpcUaCryptoAsymmetricSign
	#define CHK_OpcUaCryptoAsymmetricSign  (pfOpcUaCryptoAsymmetricSign != NULL)
	#define EXP_OpcUaCryptoAsymmetricSign  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCryptoAsymmetricSign", (RTS_UINTPTR)OpcUaCryptoAsymmetricSign, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaCryptoAsymmetricVerify(OpcUa_CryptoProvider* pProvider, OpcUa_ByteString data, OpcUa_Key* publicKey, OpcUa_ByteString* pSignature);
typedef OpcUa_StatusCode (CDECL * PFOPCUACRYPTOASYMMETRICVERIFY) (OpcUa_CryptoProvider* pProvider, OpcUa_ByteString data, OpcUa_Key* publicKey, OpcUa_ByteString* pSignature);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACRYPTOASYMMETRICVERIFY_NOTIMPLEMENTED)
	#define USE_OpcUaCryptoAsymmetricVerify
	#define EXT_OpcUaCryptoAsymmetricVerify
	#define GET_OpcUaCryptoAsymmetricVerify(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaCryptoAsymmetricVerify(p0,p1,p2,p3)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaCryptoAsymmetricVerify  FALSE
	#define EXP_OpcUaCryptoAsymmetricVerify  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaCryptoAsymmetricVerify
	#define EXT_OpcUaCryptoAsymmetricVerify
	#define GET_OpcUaCryptoAsymmetricVerify(fl)  CAL_CMGETAPI( "OpcUaCryptoAsymmetricVerify" ) 
	#define CAL_OpcUaCryptoAsymmetricVerify  OpcUaCryptoAsymmetricVerify
	#define CHK_OpcUaCryptoAsymmetricVerify  TRUE
	#define EXP_OpcUaCryptoAsymmetricVerify  CAL_CMEXPAPI( "OpcUaCryptoAsymmetricVerify" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaCryptoAsymmetricVerify
	#define EXT_OpcUaCryptoAsymmetricVerify
	#define GET_OpcUaCryptoAsymmetricVerify(fl)  CAL_CMGETAPI( "OpcUaCryptoAsymmetricVerify" ) 
	#define CAL_OpcUaCryptoAsymmetricVerify  OpcUaCryptoAsymmetricVerify
	#define CHK_OpcUaCryptoAsymmetricVerify  TRUE
	#define EXP_OpcUaCryptoAsymmetricVerify  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCryptoAsymmetricVerify", (RTS_UINTPTR)OpcUaCryptoAsymmetricVerify, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaCryptoAsymmetricVerify
	#define EXT_CmpOPCUAStackOpcUaCryptoAsymmetricVerify
	#define GET_CmpOPCUAStackOpcUaCryptoAsymmetricVerify  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaCryptoAsymmetricVerify pICmpOPCUAStack->IOpcUaCryptoAsymmetricVerify
	#define CHK_CmpOPCUAStackOpcUaCryptoAsymmetricVerify (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaCryptoAsymmetricVerify  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaCryptoAsymmetricVerify
	#define EXT_OpcUaCryptoAsymmetricVerify
	#define GET_OpcUaCryptoAsymmetricVerify(fl)  CAL_CMGETAPI( "OpcUaCryptoAsymmetricVerify" ) 
	#define CAL_OpcUaCryptoAsymmetricVerify pICmpOPCUAStack->IOpcUaCryptoAsymmetricVerify
	#define CHK_OpcUaCryptoAsymmetricVerify (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaCryptoAsymmetricVerify  CAL_CMEXPAPI( "OpcUaCryptoAsymmetricVerify" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaCryptoAsymmetricVerify  PFOPCUACRYPTOASYMMETRICVERIFY pfOpcUaCryptoAsymmetricVerify;
	#define EXT_OpcUaCryptoAsymmetricVerify  extern PFOPCUACRYPTOASYMMETRICVERIFY pfOpcUaCryptoAsymmetricVerify;
	#define GET_OpcUaCryptoAsymmetricVerify(fl)  s_pfCMGetAPI2( "OpcUaCryptoAsymmetricVerify", (RTS_VOID_FCTPTR *)&pfOpcUaCryptoAsymmetricVerify, (fl), 0, 0)
	#define CAL_OpcUaCryptoAsymmetricVerify  pfOpcUaCryptoAsymmetricVerify
	#define CHK_OpcUaCryptoAsymmetricVerify  (pfOpcUaCryptoAsymmetricVerify != NULL)
	#define EXP_OpcUaCryptoAsymmetricVerify  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCryptoAsymmetricVerify", (RTS_UINTPTR)OpcUaCryptoAsymmetricVerify, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaCryptoAsymmetricDecrypt(OpcUa_CryptoProvider* pProvider, OpcUa_Byte* pCipherText, OpcUa_UInt32 cipherTextLen, OpcUa_Key* privateKey, OpcUa_Byte* pPlainText, OpcUa_UInt32* pPlainTextLen);
typedef OpcUa_StatusCode (CDECL * PFOPCUACRYPTOASYMMETRICDECRYPT) (OpcUa_CryptoProvider* pProvider, OpcUa_Byte* pCipherText, OpcUa_UInt32 cipherTextLen, OpcUa_Key* privateKey, OpcUa_Byte* pPlainText, OpcUa_UInt32* pPlainTextLen);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACRYPTOASYMMETRICDECRYPT_NOTIMPLEMENTED)
	#define USE_OpcUaCryptoAsymmetricDecrypt
	#define EXT_OpcUaCryptoAsymmetricDecrypt
	#define GET_OpcUaCryptoAsymmetricDecrypt(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaCryptoAsymmetricDecrypt(p0,p1,p2,p3,p4,p5)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaCryptoAsymmetricDecrypt  FALSE
	#define EXP_OpcUaCryptoAsymmetricDecrypt  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaCryptoAsymmetricDecrypt
	#define EXT_OpcUaCryptoAsymmetricDecrypt
	#define GET_OpcUaCryptoAsymmetricDecrypt(fl)  CAL_CMGETAPI( "OpcUaCryptoAsymmetricDecrypt" ) 
	#define CAL_OpcUaCryptoAsymmetricDecrypt  OpcUaCryptoAsymmetricDecrypt
	#define CHK_OpcUaCryptoAsymmetricDecrypt  TRUE
	#define EXP_OpcUaCryptoAsymmetricDecrypt  CAL_CMEXPAPI( "OpcUaCryptoAsymmetricDecrypt" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaCryptoAsymmetricDecrypt
	#define EXT_OpcUaCryptoAsymmetricDecrypt
	#define GET_OpcUaCryptoAsymmetricDecrypt(fl)  CAL_CMGETAPI( "OpcUaCryptoAsymmetricDecrypt" ) 
	#define CAL_OpcUaCryptoAsymmetricDecrypt  OpcUaCryptoAsymmetricDecrypt
	#define CHK_OpcUaCryptoAsymmetricDecrypt  TRUE
	#define EXP_OpcUaCryptoAsymmetricDecrypt  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCryptoAsymmetricDecrypt", (RTS_UINTPTR)OpcUaCryptoAsymmetricDecrypt, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaCryptoAsymmetricDecrypt
	#define EXT_CmpOPCUAStackOpcUaCryptoAsymmetricDecrypt
	#define GET_CmpOPCUAStackOpcUaCryptoAsymmetricDecrypt  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaCryptoAsymmetricDecrypt pICmpOPCUAStack->IOpcUaCryptoAsymmetricDecrypt
	#define CHK_CmpOPCUAStackOpcUaCryptoAsymmetricDecrypt (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaCryptoAsymmetricDecrypt  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaCryptoAsymmetricDecrypt
	#define EXT_OpcUaCryptoAsymmetricDecrypt
	#define GET_OpcUaCryptoAsymmetricDecrypt(fl)  CAL_CMGETAPI( "OpcUaCryptoAsymmetricDecrypt" ) 
	#define CAL_OpcUaCryptoAsymmetricDecrypt pICmpOPCUAStack->IOpcUaCryptoAsymmetricDecrypt
	#define CHK_OpcUaCryptoAsymmetricDecrypt (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaCryptoAsymmetricDecrypt  CAL_CMEXPAPI( "OpcUaCryptoAsymmetricDecrypt" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaCryptoAsymmetricDecrypt  PFOPCUACRYPTOASYMMETRICDECRYPT pfOpcUaCryptoAsymmetricDecrypt;
	#define EXT_OpcUaCryptoAsymmetricDecrypt  extern PFOPCUACRYPTOASYMMETRICDECRYPT pfOpcUaCryptoAsymmetricDecrypt;
	#define GET_OpcUaCryptoAsymmetricDecrypt(fl)  s_pfCMGetAPI2( "OpcUaCryptoAsymmetricDecrypt", (RTS_VOID_FCTPTR *)&pfOpcUaCryptoAsymmetricDecrypt, (fl), 0, 0)
	#define CAL_OpcUaCryptoAsymmetricDecrypt  pfOpcUaCryptoAsymmetricDecrypt
	#define CHK_OpcUaCryptoAsymmetricDecrypt  (pfOpcUaCryptoAsymmetricDecrypt != NULL)
	#define EXP_OpcUaCryptoAsymmetricDecrypt  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCryptoAsymmetricDecrypt", (RTS_UINTPTR)OpcUaCryptoAsymmetricDecrypt, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaCryptoAsymmetricEncrypt(OpcUa_CryptoProvider* pProvider, OpcUa_Byte* pPlainText, OpcUa_UInt32 plainTextLen, OpcUa_Key* publicKey, OpcUa_Byte* pCipherText, OpcUa_UInt32* pCipherTextLen);
typedef OpcUa_StatusCode (CDECL * PFOPCUACRYPTOASYMMETRICENCRYPT) (OpcUa_CryptoProvider* pProvider, OpcUa_Byte* pPlainText, OpcUa_UInt32 plainTextLen, OpcUa_Key* publicKey, OpcUa_Byte* pCipherText, OpcUa_UInt32* pCipherTextLen);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACRYPTOASYMMETRICENCRYPT_NOTIMPLEMENTED)
	#define USE_OpcUaCryptoAsymmetricEncrypt
	#define EXT_OpcUaCryptoAsymmetricEncrypt
	#define GET_OpcUaCryptoAsymmetricEncrypt(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaCryptoAsymmetricEncrypt(p0,p1,p2,p3,p4,p5)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaCryptoAsymmetricEncrypt  FALSE
	#define EXP_OpcUaCryptoAsymmetricEncrypt  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaCryptoAsymmetricEncrypt
	#define EXT_OpcUaCryptoAsymmetricEncrypt
	#define GET_OpcUaCryptoAsymmetricEncrypt(fl)  CAL_CMGETAPI( "OpcUaCryptoAsymmetricEncrypt" ) 
	#define CAL_OpcUaCryptoAsymmetricEncrypt  OpcUaCryptoAsymmetricEncrypt
	#define CHK_OpcUaCryptoAsymmetricEncrypt  TRUE
	#define EXP_OpcUaCryptoAsymmetricEncrypt  CAL_CMEXPAPI( "OpcUaCryptoAsymmetricEncrypt" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaCryptoAsymmetricEncrypt
	#define EXT_OpcUaCryptoAsymmetricEncrypt
	#define GET_OpcUaCryptoAsymmetricEncrypt(fl)  CAL_CMGETAPI( "OpcUaCryptoAsymmetricEncrypt" ) 
	#define CAL_OpcUaCryptoAsymmetricEncrypt  OpcUaCryptoAsymmetricEncrypt
	#define CHK_OpcUaCryptoAsymmetricEncrypt  TRUE
	#define EXP_OpcUaCryptoAsymmetricEncrypt  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCryptoAsymmetricEncrypt", (RTS_UINTPTR)OpcUaCryptoAsymmetricEncrypt, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaCryptoAsymmetricEncrypt
	#define EXT_CmpOPCUAStackOpcUaCryptoAsymmetricEncrypt
	#define GET_CmpOPCUAStackOpcUaCryptoAsymmetricEncrypt  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaCryptoAsymmetricEncrypt pICmpOPCUAStack->IOpcUaCryptoAsymmetricEncrypt
	#define CHK_CmpOPCUAStackOpcUaCryptoAsymmetricEncrypt (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaCryptoAsymmetricEncrypt  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaCryptoAsymmetricEncrypt
	#define EXT_OpcUaCryptoAsymmetricEncrypt
	#define GET_OpcUaCryptoAsymmetricEncrypt(fl)  CAL_CMGETAPI( "OpcUaCryptoAsymmetricEncrypt" ) 
	#define CAL_OpcUaCryptoAsymmetricEncrypt pICmpOPCUAStack->IOpcUaCryptoAsymmetricEncrypt
	#define CHK_OpcUaCryptoAsymmetricEncrypt (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaCryptoAsymmetricEncrypt  CAL_CMEXPAPI( "OpcUaCryptoAsymmetricEncrypt" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaCryptoAsymmetricEncrypt  PFOPCUACRYPTOASYMMETRICENCRYPT pfOpcUaCryptoAsymmetricEncrypt;
	#define EXT_OpcUaCryptoAsymmetricEncrypt  extern PFOPCUACRYPTOASYMMETRICENCRYPT pfOpcUaCryptoAsymmetricEncrypt;
	#define GET_OpcUaCryptoAsymmetricEncrypt(fl)  s_pfCMGetAPI2( "OpcUaCryptoAsymmetricEncrypt", (RTS_VOID_FCTPTR *)&pfOpcUaCryptoAsymmetricEncrypt, (fl), 0, 0)
	#define CAL_OpcUaCryptoAsymmetricEncrypt  pfOpcUaCryptoAsymmetricEncrypt
	#define CHK_OpcUaCryptoAsymmetricEncrypt  (pfOpcUaCryptoAsymmetricEncrypt != NULL)
	#define EXP_OpcUaCryptoAsymmetricEncrypt  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCryptoAsymmetricEncrypt", (RTS_UINTPTR)OpcUaCryptoAsymmetricEncrypt, 0, 0) 
#endif



OpcUa_CharA* CDECL OpcUaCryptoGetSignatureAlgorithmUri(OpcUa_CryptoProvider* pProvider);
typedef OpcUa_CharA* (CDECL * PFOPCUACRYPTOGETSIGNATUREALGORITHMURI) (OpcUa_CryptoProvider* pProvider);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACRYPTOGETSIGNATUREALGORITHMURI_NOTIMPLEMENTED)
	#define USE_OpcUaCryptoGetSignatureAlgorithmUri
	#define EXT_OpcUaCryptoGetSignatureAlgorithmUri
	#define GET_OpcUaCryptoGetSignatureAlgorithmUri(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaCryptoGetSignatureAlgorithmUri(p0)  (OpcUa_CharA*)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaCryptoGetSignatureAlgorithmUri  FALSE
	#define EXP_OpcUaCryptoGetSignatureAlgorithmUri  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaCryptoGetSignatureAlgorithmUri
	#define EXT_OpcUaCryptoGetSignatureAlgorithmUri
	#define GET_OpcUaCryptoGetSignatureAlgorithmUri(fl)  CAL_CMGETAPI( "OpcUaCryptoGetSignatureAlgorithmUri" ) 
	#define CAL_OpcUaCryptoGetSignatureAlgorithmUri  OpcUaCryptoGetSignatureAlgorithmUri
	#define CHK_OpcUaCryptoGetSignatureAlgorithmUri  TRUE
	#define EXP_OpcUaCryptoGetSignatureAlgorithmUri  CAL_CMEXPAPI( "OpcUaCryptoGetSignatureAlgorithmUri" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaCryptoGetSignatureAlgorithmUri
	#define EXT_OpcUaCryptoGetSignatureAlgorithmUri
	#define GET_OpcUaCryptoGetSignatureAlgorithmUri(fl)  CAL_CMGETAPI( "OpcUaCryptoGetSignatureAlgorithmUri" ) 
	#define CAL_OpcUaCryptoGetSignatureAlgorithmUri  OpcUaCryptoGetSignatureAlgorithmUri
	#define CHK_OpcUaCryptoGetSignatureAlgorithmUri  TRUE
	#define EXP_OpcUaCryptoGetSignatureAlgorithmUri  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCryptoGetSignatureAlgorithmUri", (RTS_UINTPTR)OpcUaCryptoGetSignatureAlgorithmUri, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaCryptoGetSignatureAlgorithmUri
	#define EXT_CmpOPCUAStackOpcUaCryptoGetSignatureAlgorithmUri
	#define GET_CmpOPCUAStackOpcUaCryptoGetSignatureAlgorithmUri  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaCryptoGetSignatureAlgorithmUri pICmpOPCUAStack->IOpcUaCryptoGetSignatureAlgorithmUri
	#define CHK_CmpOPCUAStackOpcUaCryptoGetSignatureAlgorithmUri (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaCryptoGetSignatureAlgorithmUri  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaCryptoGetSignatureAlgorithmUri
	#define EXT_OpcUaCryptoGetSignatureAlgorithmUri
	#define GET_OpcUaCryptoGetSignatureAlgorithmUri(fl)  CAL_CMGETAPI( "OpcUaCryptoGetSignatureAlgorithmUri" ) 
	#define CAL_OpcUaCryptoGetSignatureAlgorithmUri pICmpOPCUAStack->IOpcUaCryptoGetSignatureAlgorithmUri
	#define CHK_OpcUaCryptoGetSignatureAlgorithmUri (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaCryptoGetSignatureAlgorithmUri  CAL_CMEXPAPI( "OpcUaCryptoGetSignatureAlgorithmUri" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaCryptoGetSignatureAlgorithmUri  PFOPCUACRYPTOGETSIGNATUREALGORITHMURI pfOpcUaCryptoGetSignatureAlgorithmUri;
	#define EXT_OpcUaCryptoGetSignatureAlgorithmUri  extern PFOPCUACRYPTOGETSIGNATUREALGORITHMURI pfOpcUaCryptoGetSignatureAlgorithmUri;
	#define GET_OpcUaCryptoGetSignatureAlgorithmUri(fl)  s_pfCMGetAPI2( "OpcUaCryptoGetSignatureAlgorithmUri", (RTS_VOID_FCTPTR *)&pfOpcUaCryptoGetSignatureAlgorithmUri, (fl), 0, 0)
	#define CAL_OpcUaCryptoGetSignatureAlgorithmUri  pfOpcUaCryptoGetSignatureAlgorithmUri
	#define CHK_OpcUaCryptoGetSignatureAlgorithmUri  (pfOpcUaCryptoGetSignatureAlgorithmUri != NULL)
	#define EXP_OpcUaCryptoGetSignatureAlgorithmUri  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCryptoGetSignatureAlgorithmUri", (RTS_UINTPTR)OpcUaCryptoGetSignatureAlgorithmUri, 0, 0) 
#endif



OpcUa_CharA* CDECL OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri(OpcUa_CryptoProvider* pProvider);
typedef OpcUa_CharA* (CDECL * PFOPCUACRYPTOGETASYMMETRICENCRYPTIONALGORITHMURI) (OpcUa_CryptoProvider* pProvider);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACRYPTOGETASYMMETRICENCRYPTIONALGORITHMURI_NOTIMPLEMENTED)
	#define USE_OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri
	#define EXT_OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri
	#define GET_OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri(p0)  (OpcUa_CharA*)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri  FALSE
	#define EXP_OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri
	#define EXT_OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri
	#define GET_OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri(fl)  CAL_CMGETAPI( "OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri" ) 
	#define CAL_OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri  OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri
	#define CHK_OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri  TRUE
	#define EXP_OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri  CAL_CMEXPAPI( "OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri
	#define EXT_OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri
	#define GET_OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri(fl)  CAL_CMGETAPI( "OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri" ) 
	#define CAL_OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri  OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri
	#define CHK_OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri  TRUE
	#define EXP_OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri", (RTS_UINTPTR)OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaCryptoGetAsymmetricEncryptionAlgorithmUri
	#define EXT_CmpOPCUAStackOpcUaCryptoGetAsymmetricEncryptionAlgorithmUri
	#define GET_CmpOPCUAStackOpcUaCryptoGetAsymmetricEncryptionAlgorithmUri  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaCryptoGetAsymmetricEncryptionAlgorithmUri pICmpOPCUAStack->IOpcUaCryptoGetAsymmetricEncryptionAlgorithmUri
	#define CHK_CmpOPCUAStackOpcUaCryptoGetAsymmetricEncryptionAlgorithmUri (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaCryptoGetAsymmetricEncryptionAlgorithmUri  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri
	#define EXT_OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri
	#define GET_OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri(fl)  CAL_CMGETAPI( "OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri" ) 
	#define CAL_OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri pICmpOPCUAStack->IOpcUaCryptoGetAsymmetricEncryptionAlgorithmUri
	#define CHK_OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri  CAL_CMEXPAPI( "OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri  PFOPCUACRYPTOGETASYMMETRICENCRYPTIONALGORITHMURI pfOpcUaCryptoGetAsymmetricEncryptionAlgorithmUri;
	#define EXT_OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri  extern PFOPCUACRYPTOGETASYMMETRICENCRYPTIONALGORITHMURI pfOpcUaCryptoGetAsymmetricEncryptionAlgorithmUri;
	#define GET_OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri(fl)  s_pfCMGetAPI2( "OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri", (RTS_VOID_FCTPTR *)&pfOpcUaCryptoGetAsymmetricEncryptionAlgorithmUri, (fl), 0, 0)
	#define CAL_OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri  pfOpcUaCryptoGetAsymmetricEncryptionAlgorithmUri
	#define CHK_OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri  (pfOpcUaCryptoGetAsymmetricEncryptionAlgorithmUri != NULL)
	#define EXP_OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri", (RTS_UINTPTR)OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaCryptoGetAsymmetricKeyLength(OpcUa_CryptoProvider* a_pProvider, OpcUa_Key a_publicKey, OpcUa_UInt32* a_pBits);
typedef OpcUa_StatusCode (CDECL * PFOPCUACRYPTOGETASYMMETRICKEYLENGTH) (OpcUa_CryptoProvider* a_pProvider, OpcUa_Key a_publicKey, OpcUa_UInt32* a_pBits);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACRYPTOGETASYMMETRICKEYLENGTH_NOTIMPLEMENTED)
	#define USE_OpcUaCryptoGetAsymmetricKeyLength
	#define EXT_OpcUaCryptoGetAsymmetricKeyLength
	#define GET_OpcUaCryptoGetAsymmetricKeyLength(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaCryptoGetAsymmetricKeyLength(p0,p1,p2)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaCryptoGetAsymmetricKeyLength  FALSE
	#define EXP_OpcUaCryptoGetAsymmetricKeyLength  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaCryptoGetAsymmetricKeyLength
	#define EXT_OpcUaCryptoGetAsymmetricKeyLength
	#define GET_OpcUaCryptoGetAsymmetricKeyLength(fl)  CAL_CMGETAPI( "OpcUaCryptoGetAsymmetricKeyLength" ) 
	#define CAL_OpcUaCryptoGetAsymmetricKeyLength  OpcUaCryptoGetAsymmetricKeyLength
	#define CHK_OpcUaCryptoGetAsymmetricKeyLength  TRUE
	#define EXP_OpcUaCryptoGetAsymmetricKeyLength  CAL_CMEXPAPI( "OpcUaCryptoGetAsymmetricKeyLength" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaCryptoGetAsymmetricKeyLength
	#define EXT_OpcUaCryptoGetAsymmetricKeyLength
	#define GET_OpcUaCryptoGetAsymmetricKeyLength(fl)  CAL_CMGETAPI( "OpcUaCryptoGetAsymmetricKeyLength" ) 
	#define CAL_OpcUaCryptoGetAsymmetricKeyLength  OpcUaCryptoGetAsymmetricKeyLength
	#define CHK_OpcUaCryptoGetAsymmetricKeyLength  TRUE
	#define EXP_OpcUaCryptoGetAsymmetricKeyLength  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCryptoGetAsymmetricKeyLength", (RTS_UINTPTR)OpcUaCryptoGetAsymmetricKeyLength, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaCryptoGetAsymmetricKeyLength
	#define EXT_CmpOPCUAStackOpcUaCryptoGetAsymmetricKeyLength
	#define GET_CmpOPCUAStackOpcUaCryptoGetAsymmetricKeyLength  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaCryptoGetAsymmetricKeyLength pICmpOPCUAStack->IOpcUaCryptoGetAsymmetricKeyLength
	#define CHK_CmpOPCUAStackOpcUaCryptoGetAsymmetricKeyLength (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaCryptoGetAsymmetricKeyLength  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaCryptoGetAsymmetricKeyLength
	#define EXT_OpcUaCryptoGetAsymmetricKeyLength
	#define GET_OpcUaCryptoGetAsymmetricKeyLength(fl)  CAL_CMGETAPI( "OpcUaCryptoGetAsymmetricKeyLength" ) 
	#define CAL_OpcUaCryptoGetAsymmetricKeyLength pICmpOPCUAStack->IOpcUaCryptoGetAsymmetricKeyLength
	#define CHK_OpcUaCryptoGetAsymmetricKeyLength (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaCryptoGetAsymmetricKeyLength  CAL_CMEXPAPI( "OpcUaCryptoGetAsymmetricKeyLength" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaCryptoGetAsymmetricKeyLength  PFOPCUACRYPTOGETASYMMETRICKEYLENGTH pfOpcUaCryptoGetAsymmetricKeyLength;
	#define EXT_OpcUaCryptoGetAsymmetricKeyLength  extern PFOPCUACRYPTOGETASYMMETRICKEYLENGTH pfOpcUaCryptoGetAsymmetricKeyLength;
	#define GET_OpcUaCryptoGetAsymmetricKeyLength(fl)  s_pfCMGetAPI2( "OpcUaCryptoGetAsymmetricKeyLength", (RTS_VOID_FCTPTR *)&pfOpcUaCryptoGetAsymmetricKeyLength, (fl), 0, 0)
	#define CAL_OpcUaCryptoGetAsymmetricKeyLength  pfOpcUaCryptoGetAsymmetricKeyLength
	#define CHK_OpcUaCryptoGetAsymmetricKeyLength  (pfOpcUaCryptoGetAsymmetricKeyLength != NULL)
	#define EXP_OpcUaCryptoGetAsymmetricKeyLength  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCryptoGetAsymmetricKeyLength", (RTS_UINTPTR)OpcUaCryptoGetAsymmetricKeyLength, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaCryptoProviderCreate(OpcUa_StringA a_psSecurityProfileUri, OpcUa_CryptoProvider* a_pProvider);
typedef OpcUa_StatusCode (CDECL * PFOPCUACRYPTOPROVIDERCREATE) (OpcUa_StringA a_psSecurityProfileUri, OpcUa_CryptoProvider* a_pProvider);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACRYPTOPROVIDERCREATE_NOTIMPLEMENTED)
	#define USE_OpcUaCryptoProviderCreate
	#define EXT_OpcUaCryptoProviderCreate
	#define GET_OpcUaCryptoProviderCreate(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaCryptoProviderCreate(p0,p1)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaCryptoProviderCreate  FALSE
	#define EXP_OpcUaCryptoProviderCreate  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaCryptoProviderCreate
	#define EXT_OpcUaCryptoProviderCreate
	#define GET_OpcUaCryptoProviderCreate(fl)  CAL_CMGETAPI( "OpcUaCryptoProviderCreate" ) 
	#define CAL_OpcUaCryptoProviderCreate  OpcUaCryptoProviderCreate
	#define CHK_OpcUaCryptoProviderCreate  TRUE
	#define EXP_OpcUaCryptoProviderCreate  CAL_CMEXPAPI( "OpcUaCryptoProviderCreate" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaCryptoProviderCreate
	#define EXT_OpcUaCryptoProviderCreate
	#define GET_OpcUaCryptoProviderCreate(fl)  CAL_CMGETAPI( "OpcUaCryptoProviderCreate" ) 
	#define CAL_OpcUaCryptoProviderCreate  OpcUaCryptoProviderCreate
	#define CHK_OpcUaCryptoProviderCreate  TRUE
	#define EXP_OpcUaCryptoProviderCreate  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCryptoProviderCreate", (RTS_UINTPTR)OpcUaCryptoProviderCreate, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaCryptoProviderCreate
	#define EXT_CmpOPCUAStackOpcUaCryptoProviderCreate
	#define GET_CmpOPCUAStackOpcUaCryptoProviderCreate  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaCryptoProviderCreate pICmpOPCUAStack->IOpcUaCryptoProviderCreate
	#define CHK_CmpOPCUAStackOpcUaCryptoProviderCreate (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaCryptoProviderCreate  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaCryptoProviderCreate
	#define EXT_OpcUaCryptoProviderCreate
	#define GET_OpcUaCryptoProviderCreate(fl)  CAL_CMGETAPI( "OpcUaCryptoProviderCreate" ) 
	#define CAL_OpcUaCryptoProviderCreate pICmpOPCUAStack->IOpcUaCryptoProviderCreate
	#define CHK_OpcUaCryptoProviderCreate (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaCryptoProviderCreate  CAL_CMEXPAPI( "OpcUaCryptoProviderCreate" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaCryptoProviderCreate  PFOPCUACRYPTOPROVIDERCREATE pfOpcUaCryptoProviderCreate;
	#define EXT_OpcUaCryptoProviderCreate  extern PFOPCUACRYPTOPROVIDERCREATE pfOpcUaCryptoProviderCreate;
	#define GET_OpcUaCryptoProviderCreate(fl)  s_pfCMGetAPI2( "OpcUaCryptoProviderCreate", (RTS_VOID_FCTPTR *)&pfOpcUaCryptoProviderCreate, (fl), 0, 0)
	#define CAL_OpcUaCryptoProviderCreate  pfOpcUaCryptoProviderCreate
	#define CHK_OpcUaCryptoProviderCreate  (pfOpcUaCryptoProviderCreate != NULL)
	#define EXP_OpcUaCryptoProviderCreate  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCryptoProviderCreate", (RTS_UINTPTR)OpcUaCryptoProviderCreate, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaCryptoProviderDelete(OpcUa_CryptoProvider* a_pProvider);
typedef OpcUa_StatusCode (CDECL * PFOPCUACRYPTOPROVIDERDELETE) (OpcUa_CryptoProvider* a_pProvider);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACRYPTOPROVIDERDELETE_NOTIMPLEMENTED)
	#define USE_OpcUaCryptoProviderDelete
	#define EXT_OpcUaCryptoProviderDelete
	#define GET_OpcUaCryptoProviderDelete(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaCryptoProviderDelete(p0)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaCryptoProviderDelete  FALSE
	#define EXP_OpcUaCryptoProviderDelete  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaCryptoProviderDelete
	#define EXT_OpcUaCryptoProviderDelete
	#define GET_OpcUaCryptoProviderDelete(fl)  CAL_CMGETAPI( "OpcUaCryptoProviderDelete" ) 
	#define CAL_OpcUaCryptoProviderDelete  OpcUaCryptoProviderDelete
	#define CHK_OpcUaCryptoProviderDelete  TRUE
	#define EXP_OpcUaCryptoProviderDelete  CAL_CMEXPAPI( "OpcUaCryptoProviderDelete" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaCryptoProviderDelete
	#define EXT_OpcUaCryptoProviderDelete
	#define GET_OpcUaCryptoProviderDelete(fl)  CAL_CMGETAPI( "OpcUaCryptoProviderDelete" ) 
	#define CAL_OpcUaCryptoProviderDelete  OpcUaCryptoProviderDelete
	#define CHK_OpcUaCryptoProviderDelete  TRUE
	#define EXP_OpcUaCryptoProviderDelete  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCryptoProviderDelete", (RTS_UINTPTR)OpcUaCryptoProviderDelete, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaCryptoProviderDelete
	#define EXT_CmpOPCUAStackOpcUaCryptoProviderDelete
	#define GET_CmpOPCUAStackOpcUaCryptoProviderDelete  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaCryptoProviderDelete pICmpOPCUAStack->IOpcUaCryptoProviderDelete
	#define CHK_CmpOPCUAStackOpcUaCryptoProviderDelete (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaCryptoProviderDelete  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaCryptoProviderDelete
	#define EXT_OpcUaCryptoProviderDelete
	#define GET_OpcUaCryptoProviderDelete(fl)  CAL_CMGETAPI( "OpcUaCryptoProviderDelete" ) 
	#define CAL_OpcUaCryptoProviderDelete pICmpOPCUAStack->IOpcUaCryptoProviderDelete
	#define CHK_OpcUaCryptoProviderDelete (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaCryptoProviderDelete  CAL_CMEXPAPI( "OpcUaCryptoProviderDelete" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaCryptoProviderDelete  PFOPCUACRYPTOPROVIDERDELETE pfOpcUaCryptoProviderDelete;
	#define EXT_OpcUaCryptoProviderDelete  extern PFOPCUACRYPTOPROVIDERDELETE pfOpcUaCryptoProviderDelete;
	#define GET_OpcUaCryptoProviderDelete(fl)  s_pfCMGetAPI2( "OpcUaCryptoProviderDelete", (RTS_VOID_FCTPTR *)&pfOpcUaCryptoProviderDelete, (fl), 0, 0)
	#define CAL_OpcUaCryptoProviderDelete  pfOpcUaCryptoProviderDelete
	#define CHK_OpcUaCryptoProviderDelete  (pfOpcUaCryptoProviderDelete != NULL)
	#define EXP_OpcUaCryptoProviderDelete  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaCryptoProviderDelete", (RTS_UINTPTR)OpcUaCryptoProviderDelete, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaStackGenerateApplicationSignature(const OpcUa_StringA pszSecurityPolicyUri, const OpcUa_ByteString *pPeerCert, const OpcUa_ByteString *pPeerNonce, const OpcUa_Key *pMyPrivateKey, OpcUa_SignatureData *pSignature);
typedef OpcUa_StatusCode (CDECL * PFOPCUASTACKGENERATEAPPLICATIONSIGNATURE) (const OpcUa_StringA pszSecurityPolicyUri, const OpcUa_ByteString *pPeerCert, const OpcUa_ByteString *pPeerNonce, const OpcUa_Key *pMyPrivateKey, OpcUa_SignatureData *pSignature);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASTACKGENERATEAPPLICATIONSIGNATURE_NOTIMPLEMENTED)
	#define USE_OpcUaStackGenerateApplicationSignature
	#define EXT_OpcUaStackGenerateApplicationSignature
	#define GET_OpcUaStackGenerateApplicationSignature(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaStackGenerateApplicationSignature(p0,p1,p2,p3,p4)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaStackGenerateApplicationSignature  FALSE
	#define EXP_OpcUaStackGenerateApplicationSignature  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaStackGenerateApplicationSignature
	#define EXT_OpcUaStackGenerateApplicationSignature
	#define GET_OpcUaStackGenerateApplicationSignature(fl)  CAL_CMGETAPI( "OpcUaStackGenerateApplicationSignature" ) 
	#define CAL_OpcUaStackGenerateApplicationSignature  OpcUaStackGenerateApplicationSignature
	#define CHK_OpcUaStackGenerateApplicationSignature  TRUE
	#define EXP_OpcUaStackGenerateApplicationSignature  CAL_CMEXPAPI( "OpcUaStackGenerateApplicationSignature" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaStackGenerateApplicationSignature
	#define EXT_OpcUaStackGenerateApplicationSignature
	#define GET_OpcUaStackGenerateApplicationSignature(fl)  CAL_CMGETAPI( "OpcUaStackGenerateApplicationSignature" ) 
	#define CAL_OpcUaStackGenerateApplicationSignature  OpcUaStackGenerateApplicationSignature
	#define CHK_OpcUaStackGenerateApplicationSignature  TRUE
	#define EXP_OpcUaStackGenerateApplicationSignature  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStackGenerateApplicationSignature", (RTS_UINTPTR)OpcUaStackGenerateApplicationSignature, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaStackGenerateApplicationSignature
	#define EXT_CmpOPCUAStackOpcUaStackGenerateApplicationSignature
	#define GET_CmpOPCUAStackOpcUaStackGenerateApplicationSignature  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaStackGenerateApplicationSignature pICmpOPCUAStack->IOpcUaStackGenerateApplicationSignature
	#define CHK_CmpOPCUAStackOpcUaStackGenerateApplicationSignature (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaStackGenerateApplicationSignature  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaStackGenerateApplicationSignature
	#define EXT_OpcUaStackGenerateApplicationSignature
	#define GET_OpcUaStackGenerateApplicationSignature(fl)  CAL_CMGETAPI( "OpcUaStackGenerateApplicationSignature" ) 
	#define CAL_OpcUaStackGenerateApplicationSignature pICmpOPCUAStack->IOpcUaStackGenerateApplicationSignature
	#define CHK_OpcUaStackGenerateApplicationSignature (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaStackGenerateApplicationSignature  CAL_CMEXPAPI( "OpcUaStackGenerateApplicationSignature" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaStackGenerateApplicationSignature  PFOPCUASTACKGENERATEAPPLICATIONSIGNATURE pfOpcUaStackGenerateApplicationSignature;
	#define EXT_OpcUaStackGenerateApplicationSignature  extern PFOPCUASTACKGENERATEAPPLICATIONSIGNATURE pfOpcUaStackGenerateApplicationSignature;
	#define GET_OpcUaStackGenerateApplicationSignature(fl)  s_pfCMGetAPI2( "OpcUaStackGenerateApplicationSignature", (RTS_VOID_FCTPTR *)&pfOpcUaStackGenerateApplicationSignature, (fl), 0, 0)
	#define CAL_OpcUaStackGenerateApplicationSignature  pfOpcUaStackGenerateApplicationSignature
	#define CHK_OpcUaStackGenerateApplicationSignature  (pfOpcUaStackGenerateApplicationSignature != NULL)
	#define EXP_OpcUaStackGenerateApplicationSignature  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStackGenerateApplicationSignature", (RTS_UINTPTR)OpcUaStackGenerateApplicationSignature, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaStackVerifyApplicationSignature(const OpcUa_StringA pszSecurityPolicyUri, const OpcUa_SignatureData *pSignature, const OpcUa_ByteString *pMyCert, const OpcUa_ByteString *pMyNonce, RTS_HANDLE hPeerCert);
typedef OpcUa_StatusCode (CDECL * PFOPCUASTACKVERIFYAPPLICATIONSIGNATURE) (const OpcUa_StringA pszSecurityPolicyUri, const OpcUa_SignatureData *pSignature, const OpcUa_ByteString *pMyCert, const OpcUa_ByteString *pMyNonce, RTS_HANDLE hPeerCert);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUASTACKVERIFYAPPLICATIONSIGNATURE_NOTIMPLEMENTED)
	#define USE_OpcUaStackVerifyApplicationSignature
	#define EXT_OpcUaStackVerifyApplicationSignature
	#define GET_OpcUaStackVerifyApplicationSignature(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaStackVerifyApplicationSignature(p0,p1,p2,p3,p4)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaStackVerifyApplicationSignature  FALSE
	#define EXP_OpcUaStackVerifyApplicationSignature  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaStackVerifyApplicationSignature
	#define EXT_OpcUaStackVerifyApplicationSignature
	#define GET_OpcUaStackVerifyApplicationSignature(fl)  CAL_CMGETAPI( "OpcUaStackVerifyApplicationSignature" ) 
	#define CAL_OpcUaStackVerifyApplicationSignature  OpcUaStackVerifyApplicationSignature
	#define CHK_OpcUaStackVerifyApplicationSignature  TRUE
	#define EXP_OpcUaStackVerifyApplicationSignature  CAL_CMEXPAPI( "OpcUaStackVerifyApplicationSignature" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaStackVerifyApplicationSignature
	#define EXT_OpcUaStackVerifyApplicationSignature
	#define GET_OpcUaStackVerifyApplicationSignature(fl)  CAL_CMGETAPI( "OpcUaStackVerifyApplicationSignature" ) 
	#define CAL_OpcUaStackVerifyApplicationSignature  OpcUaStackVerifyApplicationSignature
	#define CHK_OpcUaStackVerifyApplicationSignature  TRUE
	#define EXP_OpcUaStackVerifyApplicationSignature  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStackVerifyApplicationSignature", (RTS_UINTPTR)OpcUaStackVerifyApplicationSignature, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaStackVerifyApplicationSignature
	#define EXT_CmpOPCUAStackOpcUaStackVerifyApplicationSignature
	#define GET_CmpOPCUAStackOpcUaStackVerifyApplicationSignature  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaStackVerifyApplicationSignature pICmpOPCUAStack->IOpcUaStackVerifyApplicationSignature
	#define CHK_CmpOPCUAStackOpcUaStackVerifyApplicationSignature (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaStackVerifyApplicationSignature  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaStackVerifyApplicationSignature
	#define EXT_OpcUaStackVerifyApplicationSignature
	#define GET_OpcUaStackVerifyApplicationSignature(fl)  CAL_CMGETAPI( "OpcUaStackVerifyApplicationSignature" ) 
	#define CAL_OpcUaStackVerifyApplicationSignature pICmpOPCUAStack->IOpcUaStackVerifyApplicationSignature
	#define CHK_OpcUaStackVerifyApplicationSignature (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaStackVerifyApplicationSignature  CAL_CMEXPAPI( "OpcUaStackVerifyApplicationSignature" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaStackVerifyApplicationSignature  PFOPCUASTACKVERIFYAPPLICATIONSIGNATURE pfOpcUaStackVerifyApplicationSignature;
	#define EXT_OpcUaStackVerifyApplicationSignature  extern PFOPCUASTACKVERIFYAPPLICATIONSIGNATURE pfOpcUaStackVerifyApplicationSignature;
	#define GET_OpcUaStackVerifyApplicationSignature(fl)  s_pfCMGetAPI2( "OpcUaStackVerifyApplicationSignature", (RTS_VOID_FCTPTR *)&pfOpcUaStackVerifyApplicationSignature, (fl), 0, 0)
	#define CAL_OpcUaStackVerifyApplicationSignature  pfOpcUaStackVerifyApplicationSignature
	#define CHK_OpcUaStackVerifyApplicationSignature  (pfOpcUaStackVerifyApplicationSignature != NULL)
	#define EXP_OpcUaStackVerifyApplicationSignature  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaStackVerifyApplicationSignature", (RTS_UINTPTR)OpcUaStackVerifyApplicationSignature, 0, 0) 
#endif




/* Client Interface */
OpcUa_StatusCode CDECL OpcUaChannelCreate(OpcUa_Channel* a_phChannel, OpcUa_Channel_SerializerType a_eSerializerType);
typedef OpcUa_StatusCode (CDECL * PFOPCUACHANNELCREATE) (OpcUa_Channel* a_phChannel, OpcUa_Channel_SerializerType a_eSerializerType);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACHANNELCREATE_NOTIMPLEMENTED)
	#define USE_OpcUaChannelCreate
	#define EXT_OpcUaChannelCreate
	#define GET_OpcUaChannelCreate(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaChannelCreate(p0,p1)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaChannelCreate  FALSE
	#define EXP_OpcUaChannelCreate  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaChannelCreate
	#define EXT_OpcUaChannelCreate
	#define GET_OpcUaChannelCreate(fl)  CAL_CMGETAPI( "OpcUaChannelCreate" ) 
	#define CAL_OpcUaChannelCreate  OpcUaChannelCreate
	#define CHK_OpcUaChannelCreate  TRUE
	#define EXP_OpcUaChannelCreate  CAL_CMEXPAPI( "OpcUaChannelCreate" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaChannelCreate
	#define EXT_OpcUaChannelCreate
	#define GET_OpcUaChannelCreate(fl)  CAL_CMGETAPI( "OpcUaChannelCreate" ) 
	#define CAL_OpcUaChannelCreate  OpcUaChannelCreate
	#define CHK_OpcUaChannelCreate  TRUE
	#define EXP_OpcUaChannelCreate  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaChannelCreate", (RTS_UINTPTR)OpcUaChannelCreate, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaChannelCreate
	#define EXT_CmpOPCUAStackOpcUaChannelCreate
	#define GET_CmpOPCUAStackOpcUaChannelCreate  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaChannelCreate pICmpOPCUAStack->IOpcUaChannelCreate
	#define CHK_CmpOPCUAStackOpcUaChannelCreate (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaChannelCreate  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaChannelCreate
	#define EXT_OpcUaChannelCreate
	#define GET_OpcUaChannelCreate(fl)  CAL_CMGETAPI( "OpcUaChannelCreate" ) 
	#define CAL_OpcUaChannelCreate pICmpOPCUAStack->IOpcUaChannelCreate
	#define CHK_OpcUaChannelCreate (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaChannelCreate  CAL_CMEXPAPI( "OpcUaChannelCreate" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaChannelCreate  PFOPCUACHANNELCREATE pfOpcUaChannelCreate;
	#define EXT_OpcUaChannelCreate  extern PFOPCUACHANNELCREATE pfOpcUaChannelCreate;
	#define GET_OpcUaChannelCreate(fl)  s_pfCMGetAPI2( "OpcUaChannelCreate", (RTS_VOID_FCTPTR *)&pfOpcUaChannelCreate, (fl), 0, 0)
	#define CAL_OpcUaChannelCreate  pfOpcUaChannelCreate
	#define CHK_OpcUaChannelCreate  (pfOpcUaChannelCreate != NULL)
	#define EXP_OpcUaChannelCreate  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaChannelCreate", (RTS_UINTPTR)OpcUaChannelCreate, 0, 0) 
#endif



OpcUa_Void CDECL OpcUaChannelDelete(OpcUa_Channel* a_phChannel);
typedef OpcUa_Void (CDECL * PFOPCUACHANNELDELETE) (OpcUa_Channel* a_phChannel);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACHANNELDELETE_NOTIMPLEMENTED)
	#define USE_OpcUaChannelDelete
	#define EXT_OpcUaChannelDelete
	#define GET_OpcUaChannelDelete(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaChannelDelete(p0)  (OpcUa_Void)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaChannelDelete  FALSE
	#define EXP_OpcUaChannelDelete  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaChannelDelete
	#define EXT_OpcUaChannelDelete
	#define GET_OpcUaChannelDelete(fl)  CAL_CMGETAPI( "OpcUaChannelDelete" ) 
	#define CAL_OpcUaChannelDelete  OpcUaChannelDelete
	#define CHK_OpcUaChannelDelete  TRUE
	#define EXP_OpcUaChannelDelete  CAL_CMEXPAPI( "OpcUaChannelDelete" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaChannelDelete
	#define EXT_OpcUaChannelDelete
	#define GET_OpcUaChannelDelete(fl)  CAL_CMGETAPI( "OpcUaChannelDelete" ) 
	#define CAL_OpcUaChannelDelete  OpcUaChannelDelete
	#define CHK_OpcUaChannelDelete  TRUE
	#define EXP_OpcUaChannelDelete  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaChannelDelete", (RTS_UINTPTR)OpcUaChannelDelete, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaChannelDelete
	#define EXT_CmpOPCUAStackOpcUaChannelDelete
	#define GET_CmpOPCUAStackOpcUaChannelDelete  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaChannelDelete pICmpOPCUAStack->IOpcUaChannelDelete
	#define CHK_CmpOPCUAStackOpcUaChannelDelete (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaChannelDelete  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaChannelDelete
	#define EXT_OpcUaChannelDelete
	#define GET_OpcUaChannelDelete(fl)  CAL_CMGETAPI( "OpcUaChannelDelete" ) 
	#define CAL_OpcUaChannelDelete pICmpOPCUAStack->IOpcUaChannelDelete
	#define CHK_OpcUaChannelDelete (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaChannelDelete  CAL_CMEXPAPI( "OpcUaChannelDelete" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaChannelDelete  PFOPCUACHANNELDELETE pfOpcUaChannelDelete;
	#define EXT_OpcUaChannelDelete  extern PFOPCUACHANNELDELETE pfOpcUaChannelDelete;
	#define GET_OpcUaChannelDelete(fl)  s_pfCMGetAPI2( "OpcUaChannelDelete", (RTS_VOID_FCTPTR *)&pfOpcUaChannelDelete, (fl), 0, 0)
	#define CAL_OpcUaChannelDelete  pfOpcUaChannelDelete
	#define CHK_OpcUaChannelDelete  (pfOpcUaChannelDelete != NULL)
	#define EXP_OpcUaChannelDelete  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaChannelDelete", (RTS_UINTPTR)OpcUaChannelDelete, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaChannelBeginConnect(OpcUa_Channel pChannel, OpcUa_StringA sUrl, OpcUa_ByteString* pClientCertificate, OpcUa_Key* pClientPrivateKey, OpcUa_ByteString* pServerCertificate, OpcUa_Void* pPKIConfig, OpcUa_String* pRequestedSecurityPolicyUri, OpcUa_Int32 nRequestedLifetime, OpcUa_MessageSecurityMode messageSecurityMode, OpcUa_UInt32 nNetworkTimeout, OpcUa_Channel_PfnConnectionStateChanged* pfCallback, OpcUa_Void* pCallbackData, OpcUa_SocketManager hSocketManager);
typedef OpcUa_StatusCode (CDECL * PFOPCUACHANNELBEGINCONNECT) (OpcUa_Channel pChannel, OpcUa_StringA sUrl, OpcUa_ByteString* pClientCertificate, OpcUa_Key* pClientPrivateKey, OpcUa_ByteString* pServerCertificate, OpcUa_Void* pPKIConfig, OpcUa_String* pRequestedSecurityPolicyUri, OpcUa_Int32 nRequestedLifetime, OpcUa_MessageSecurityMode messageSecurityMode, OpcUa_UInt32 nNetworkTimeout, OpcUa_Channel_PfnConnectionStateChanged* pfCallback, OpcUa_Void* pCallbackData, OpcUa_SocketManager hSocketManager);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACHANNELBEGINCONNECT_NOTIMPLEMENTED)
	#define USE_OpcUaChannelBeginConnect
	#define EXT_OpcUaChannelBeginConnect
	#define GET_OpcUaChannelBeginConnect(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaChannelBeginConnect(p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaChannelBeginConnect  FALSE
	#define EXP_OpcUaChannelBeginConnect  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaChannelBeginConnect
	#define EXT_OpcUaChannelBeginConnect
	#define GET_OpcUaChannelBeginConnect(fl)  CAL_CMGETAPI( "OpcUaChannelBeginConnect" ) 
	#define CAL_OpcUaChannelBeginConnect  OpcUaChannelBeginConnect
	#define CHK_OpcUaChannelBeginConnect  TRUE
	#define EXP_OpcUaChannelBeginConnect  CAL_CMEXPAPI( "OpcUaChannelBeginConnect" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaChannelBeginConnect
	#define EXT_OpcUaChannelBeginConnect
	#define GET_OpcUaChannelBeginConnect(fl)  CAL_CMGETAPI( "OpcUaChannelBeginConnect" ) 
	#define CAL_OpcUaChannelBeginConnect  OpcUaChannelBeginConnect
	#define CHK_OpcUaChannelBeginConnect  TRUE
	#define EXP_OpcUaChannelBeginConnect  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaChannelBeginConnect", (RTS_UINTPTR)OpcUaChannelBeginConnect, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaChannelBeginConnect
	#define EXT_CmpOPCUAStackOpcUaChannelBeginConnect
	#define GET_CmpOPCUAStackOpcUaChannelBeginConnect  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaChannelBeginConnect pICmpOPCUAStack->IOpcUaChannelBeginConnect
	#define CHK_CmpOPCUAStackOpcUaChannelBeginConnect (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaChannelBeginConnect  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaChannelBeginConnect
	#define EXT_OpcUaChannelBeginConnect
	#define GET_OpcUaChannelBeginConnect(fl)  CAL_CMGETAPI( "OpcUaChannelBeginConnect" ) 
	#define CAL_OpcUaChannelBeginConnect pICmpOPCUAStack->IOpcUaChannelBeginConnect
	#define CHK_OpcUaChannelBeginConnect (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaChannelBeginConnect  CAL_CMEXPAPI( "OpcUaChannelBeginConnect" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaChannelBeginConnect  PFOPCUACHANNELBEGINCONNECT pfOpcUaChannelBeginConnect;
	#define EXT_OpcUaChannelBeginConnect  extern PFOPCUACHANNELBEGINCONNECT pfOpcUaChannelBeginConnect;
	#define GET_OpcUaChannelBeginConnect(fl)  s_pfCMGetAPI2( "OpcUaChannelBeginConnect", (RTS_VOID_FCTPTR *)&pfOpcUaChannelBeginConnect, (fl), 0, 0)
	#define CAL_OpcUaChannelBeginConnect  pfOpcUaChannelBeginConnect
	#define CHK_OpcUaChannelBeginConnect  (pfOpcUaChannelBeginConnect != NULL)
	#define EXP_OpcUaChannelBeginConnect  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaChannelBeginConnect", (RTS_UINTPTR)OpcUaChannelBeginConnect, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaChannelBeginDisconnect(OpcUa_Channel a_pChannel, OpcUa_Channel_PfnConnectionStateChanged* a_pfCallback, OpcUa_Void* a_pCallbackData);
typedef OpcUa_StatusCode (CDECL * PFOPCUACHANNELBEGINDISCONNECT) (OpcUa_Channel a_pChannel, OpcUa_Channel_PfnConnectionStateChanged* a_pfCallback, OpcUa_Void* a_pCallbackData);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACHANNELBEGINDISCONNECT_NOTIMPLEMENTED)
	#define USE_OpcUaChannelBeginDisconnect
	#define EXT_OpcUaChannelBeginDisconnect
	#define GET_OpcUaChannelBeginDisconnect(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaChannelBeginDisconnect(p0,p1,p2)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaChannelBeginDisconnect  FALSE
	#define EXP_OpcUaChannelBeginDisconnect  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaChannelBeginDisconnect
	#define EXT_OpcUaChannelBeginDisconnect
	#define GET_OpcUaChannelBeginDisconnect(fl)  CAL_CMGETAPI( "OpcUaChannelBeginDisconnect" ) 
	#define CAL_OpcUaChannelBeginDisconnect  OpcUaChannelBeginDisconnect
	#define CHK_OpcUaChannelBeginDisconnect  TRUE
	#define EXP_OpcUaChannelBeginDisconnect  CAL_CMEXPAPI( "OpcUaChannelBeginDisconnect" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaChannelBeginDisconnect
	#define EXT_OpcUaChannelBeginDisconnect
	#define GET_OpcUaChannelBeginDisconnect(fl)  CAL_CMGETAPI( "OpcUaChannelBeginDisconnect" ) 
	#define CAL_OpcUaChannelBeginDisconnect  OpcUaChannelBeginDisconnect
	#define CHK_OpcUaChannelBeginDisconnect  TRUE
	#define EXP_OpcUaChannelBeginDisconnect  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaChannelBeginDisconnect", (RTS_UINTPTR)OpcUaChannelBeginDisconnect, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaChannelBeginDisconnect
	#define EXT_CmpOPCUAStackOpcUaChannelBeginDisconnect
	#define GET_CmpOPCUAStackOpcUaChannelBeginDisconnect  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaChannelBeginDisconnect pICmpOPCUAStack->IOpcUaChannelBeginDisconnect
	#define CHK_CmpOPCUAStackOpcUaChannelBeginDisconnect (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaChannelBeginDisconnect  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaChannelBeginDisconnect
	#define EXT_OpcUaChannelBeginDisconnect
	#define GET_OpcUaChannelBeginDisconnect(fl)  CAL_CMGETAPI( "OpcUaChannelBeginDisconnect" ) 
	#define CAL_OpcUaChannelBeginDisconnect pICmpOPCUAStack->IOpcUaChannelBeginDisconnect
	#define CHK_OpcUaChannelBeginDisconnect (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaChannelBeginDisconnect  CAL_CMEXPAPI( "OpcUaChannelBeginDisconnect" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaChannelBeginDisconnect  PFOPCUACHANNELBEGINDISCONNECT pfOpcUaChannelBeginDisconnect;
	#define EXT_OpcUaChannelBeginDisconnect  extern PFOPCUACHANNELBEGINDISCONNECT pfOpcUaChannelBeginDisconnect;
	#define GET_OpcUaChannelBeginDisconnect(fl)  s_pfCMGetAPI2( "OpcUaChannelBeginDisconnect", (RTS_VOID_FCTPTR *)&pfOpcUaChannelBeginDisconnect, (fl), 0, 0)
	#define CAL_OpcUaChannelBeginDisconnect  pfOpcUaChannelBeginDisconnect
	#define CHK_OpcUaChannelBeginDisconnect  (pfOpcUaChannelBeginDisconnect != NULL)
	#define EXP_OpcUaChannelBeginDisconnect  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaChannelBeginDisconnect", (RTS_UINTPTR)OpcUaChannelBeginDisconnect, 0, 0) 
#endif



OpcUa_StatusCode CDECL OpcUaChannelBeginInvokeService(OpcUa_Channel a_hChannel, OpcUa_StringA a_sName, OpcUa_Void* a_pRequest, OpcUa_EncodeableType* a_pRequestType, OpcUa_Channel_PfnRequestComplete* a_pCallback, OpcUa_Void* a_pCallbackData);
typedef OpcUa_StatusCode (CDECL * PFOPCUACHANNELBEGININVOKESERVICE) (OpcUa_Channel a_hChannel, OpcUa_StringA a_sName, OpcUa_Void* a_pRequest, OpcUa_EncodeableType* a_pRequestType, OpcUa_Channel_PfnRequestComplete* a_pCallback, OpcUa_Void* a_pCallbackData);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUACHANNELBEGININVOKESERVICE_NOTIMPLEMENTED)
	#define USE_OpcUaChannelBeginInvokeService
	#define EXT_OpcUaChannelBeginInvokeService
	#define GET_OpcUaChannelBeginInvokeService(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaChannelBeginInvokeService(p0,p1,p2,p3,p4,p5)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaChannelBeginInvokeService  FALSE
	#define EXP_OpcUaChannelBeginInvokeService  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaChannelBeginInvokeService
	#define EXT_OpcUaChannelBeginInvokeService
	#define GET_OpcUaChannelBeginInvokeService(fl)  CAL_CMGETAPI( "OpcUaChannelBeginInvokeService" ) 
	#define CAL_OpcUaChannelBeginInvokeService  OpcUaChannelBeginInvokeService
	#define CHK_OpcUaChannelBeginInvokeService  TRUE
	#define EXP_OpcUaChannelBeginInvokeService  CAL_CMEXPAPI( "OpcUaChannelBeginInvokeService" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaChannelBeginInvokeService
	#define EXT_OpcUaChannelBeginInvokeService
	#define GET_OpcUaChannelBeginInvokeService(fl)  CAL_CMGETAPI( "OpcUaChannelBeginInvokeService" ) 
	#define CAL_OpcUaChannelBeginInvokeService  OpcUaChannelBeginInvokeService
	#define CHK_OpcUaChannelBeginInvokeService  TRUE
	#define EXP_OpcUaChannelBeginInvokeService  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaChannelBeginInvokeService", (RTS_UINTPTR)OpcUaChannelBeginInvokeService, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaChannelBeginInvokeService
	#define EXT_CmpOPCUAStackOpcUaChannelBeginInvokeService
	#define GET_CmpOPCUAStackOpcUaChannelBeginInvokeService  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaChannelBeginInvokeService pICmpOPCUAStack->IOpcUaChannelBeginInvokeService
	#define CHK_CmpOPCUAStackOpcUaChannelBeginInvokeService (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaChannelBeginInvokeService  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaChannelBeginInvokeService
	#define EXT_OpcUaChannelBeginInvokeService
	#define GET_OpcUaChannelBeginInvokeService(fl)  CAL_CMGETAPI( "OpcUaChannelBeginInvokeService" ) 
	#define CAL_OpcUaChannelBeginInvokeService pICmpOPCUAStack->IOpcUaChannelBeginInvokeService
	#define CHK_OpcUaChannelBeginInvokeService (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaChannelBeginInvokeService  CAL_CMEXPAPI( "OpcUaChannelBeginInvokeService" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaChannelBeginInvokeService  PFOPCUACHANNELBEGININVOKESERVICE pfOpcUaChannelBeginInvokeService;
	#define EXT_OpcUaChannelBeginInvokeService  extern PFOPCUACHANNELBEGININVOKESERVICE pfOpcUaChannelBeginInvokeService;
	#define GET_OpcUaChannelBeginInvokeService(fl)  s_pfCMGetAPI2( "OpcUaChannelBeginInvokeService", (RTS_VOID_FCTPTR *)&pfOpcUaChannelBeginInvokeService, (fl), 0, 0)
	#define CAL_OpcUaChannelBeginInvokeService  pfOpcUaChannelBeginInvokeService
	#define CHK_OpcUaChannelBeginInvokeService  (pfOpcUaChannelBeginInvokeService != NULL)
	#define EXP_OpcUaChannelBeginInvokeService  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaChannelBeginInvokeService", (RTS_UINTPTR)OpcUaChannelBeginInvokeService, 0, 0) 
#endif




/* Helpers */
OpcUa_StatusCode CDECL OpcUaDateTimeGetStringFromDateTime(const OpcUa_DateTime dateTime, OpcUa_StringA pBuffer, OpcUa_UInt32 uLength);
typedef OpcUa_StatusCode (CDECL * PFOPCUADATETIMEGETSTRINGFROMDATETIME) (const OpcUa_DateTime dateTime, OpcUa_StringA pBuffer, OpcUa_UInt32 uLength);
#if defined(CMPOPCUASTACK_NOTIMPLEMENTED) || defined(OPCUADATETIMEGETSTRINGFROMDATETIME_NOTIMPLEMENTED)
	#define USE_OpcUaDateTimeGetStringFromDateTime
	#define EXT_OpcUaDateTimeGetStringFromDateTime
	#define GET_OpcUaDateTimeGetStringFromDateTime(fl)  ERR_NOTIMPLEMENTED
	#define CAL_OpcUaDateTimeGetStringFromDateTime(p0,p1,p2)  (OpcUa_StatusCode)ERR_NOTIMPLEMENTED
	#define CHK_OpcUaDateTimeGetStringFromDateTime  FALSE
	#define EXP_OpcUaDateTimeGetStringFromDateTime  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_OpcUaDateTimeGetStringFromDateTime
	#define EXT_OpcUaDateTimeGetStringFromDateTime
	#define GET_OpcUaDateTimeGetStringFromDateTime(fl)  CAL_CMGETAPI( "OpcUaDateTimeGetStringFromDateTime" ) 
	#define CAL_OpcUaDateTimeGetStringFromDateTime  OpcUaDateTimeGetStringFromDateTime
	#define CHK_OpcUaDateTimeGetStringFromDateTime  TRUE
	#define EXP_OpcUaDateTimeGetStringFromDateTime  CAL_CMEXPAPI( "OpcUaDateTimeGetStringFromDateTime" ) 
#elif defined(MIXED_LINK) && !defined(CMPOPCUASTACK_EXTERNAL)
	#define USE_OpcUaDateTimeGetStringFromDateTime
	#define EXT_OpcUaDateTimeGetStringFromDateTime
	#define GET_OpcUaDateTimeGetStringFromDateTime(fl)  CAL_CMGETAPI( "OpcUaDateTimeGetStringFromDateTime" ) 
	#define CAL_OpcUaDateTimeGetStringFromDateTime  OpcUaDateTimeGetStringFromDateTime
	#define CHK_OpcUaDateTimeGetStringFromDateTime  TRUE
	#define EXP_OpcUaDateTimeGetStringFromDateTime  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDateTimeGetStringFromDateTime", (RTS_UINTPTR)OpcUaDateTimeGetStringFromDateTime, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpOPCUAStackOpcUaDateTimeGetStringFromDateTime
	#define EXT_CmpOPCUAStackOpcUaDateTimeGetStringFromDateTime
	#define GET_CmpOPCUAStackOpcUaDateTimeGetStringFromDateTime  ERR_OK
	#define CAL_CmpOPCUAStackOpcUaDateTimeGetStringFromDateTime pICmpOPCUAStack->IOpcUaDateTimeGetStringFromDateTime
	#define CHK_CmpOPCUAStackOpcUaDateTimeGetStringFromDateTime (pICmpOPCUAStack != NULL)
	#define EXP_CmpOPCUAStackOpcUaDateTimeGetStringFromDateTime  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_OpcUaDateTimeGetStringFromDateTime
	#define EXT_OpcUaDateTimeGetStringFromDateTime
	#define GET_OpcUaDateTimeGetStringFromDateTime(fl)  CAL_CMGETAPI( "OpcUaDateTimeGetStringFromDateTime" ) 
	#define CAL_OpcUaDateTimeGetStringFromDateTime pICmpOPCUAStack->IOpcUaDateTimeGetStringFromDateTime
	#define CHK_OpcUaDateTimeGetStringFromDateTime (pICmpOPCUAStack != NULL)
	#define EXP_OpcUaDateTimeGetStringFromDateTime  CAL_CMEXPAPI( "OpcUaDateTimeGetStringFromDateTime" ) 
#else /* DYNAMIC_LINK */
	#define USE_OpcUaDateTimeGetStringFromDateTime  PFOPCUADATETIMEGETSTRINGFROMDATETIME pfOpcUaDateTimeGetStringFromDateTime;
	#define EXT_OpcUaDateTimeGetStringFromDateTime  extern PFOPCUADATETIMEGETSTRINGFROMDATETIME pfOpcUaDateTimeGetStringFromDateTime;
	#define GET_OpcUaDateTimeGetStringFromDateTime(fl)  s_pfCMGetAPI2( "OpcUaDateTimeGetStringFromDateTime", (RTS_VOID_FCTPTR *)&pfOpcUaDateTimeGetStringFromDateTime, (fl), 0, 0)
	#define CAL_OpcUaDateTimeGetStringFromDateTime  pfOpcUaDateTimeGetStringFromDateTime
	#define CHK_OpcUaDateTimeGetStringFromDateTime  (pfOpcUaDateTimeGetStringFromDateTime != NULL)
	#define EXP_OpcUaDateTimeGetStringFromDateTime  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"OpcUaDateTimeGetStringFromDateTime", (RTS_UINTPTR)OpcUaDateTimeGetStringFromDateTime, 0, 0) 
#endif






typedef struct
{
	IBase_C *pBase;
	PFOPCUABYTESTRINGINITIALIZE IOpcUaByteStringInitialize;
 	PFOPCUABYTESTRINGCLEAR IOpcUaByteStringClear;
 	PFOPCUABYTESTRINGCOMPARE IOpcUaByteStringCompare;
 	PFOPCUABYTESTRINGCOPYTO IOpcUaByteStringCopyTo;
 	PFOPCUABYTESTRINGCONCATENATE IOpcUaByteStringConcatenate;
 	PFOPCUADATETIMEUTCNOW IOpcUaDateTimeUtcNow;
 	PFOPCUAENCODEABLEOBJECTCREATE IOpcUaEncodeableObjectCreate;
 	PFOPCUAENCODEABLEOBJECTDELETE IOpcUaEncodeableObjectDelete;
 	PFOPCUAENCODEABLEOBJECTCREATEEXTENSION IOpcUaEncodeableObjectCreateExtension;
 	PFOPCUALOCALIZEDTEXTINITIALIZE IOpcUaLocalizedTextInitialize;
 	PFOPCUALOCALIZEDTEXTCLEAR IOpcUaLocalizedTextClear;
 	PFOPCUALOCALIZEDTEXTCOMPARE IOpcUaLocalizedTextCompare;
 	PFOPCUALOCALIZEDTEXTCOPYTO IOpcUaLocalizedTextCopyTo;
 	PFOPCUANODEIDINITIALIZE IOpcUaNodeIdInitialize;
 	PFOPCUANODEIDCLEAR IOpcUaNodeIdClear;
 	PFOPCUANODEIDCOMPARE IOpcUaNodeIdCompare;
 	PFOPCUANODEIDCOPYTO IOpcUaNodeIdCopyTo;
 	PFOPCUANODEIDISNULL IOpcUaNodeIdIsNull;
 	PFOPCUAEXPANDEDNODEIDINITIALIZE IOpcUaExpandedNodeIdInitialize;
 	PFOPCUAEXPANDEDNODEIDCLEAR IOpcUaExpandedNodeIdClear;
 	PFOPCUAEXPANDEDNODEIDCOMPARE IOpcUaExpandedNodeIdCompare;
 	PFOPCUAEXPANDEDNODEIDCOPYTO IOpcUaExpandedNodeIdCopyTo;
 	PFOPCUAEXPANDEDNODEIDISNULL IOpcUaExpandedNodeIdIsNull;
 	PFOPCUAQUALIFIEDNAMEINITIALIZE IOpcUaQualifiedNameInitialize;
 	PFOPCUAQUALIFIEDNAMECLEAR IOpcUaQualifiedNameClear;
 	PFOPCUAQUALIFIEDNAMECOMPARE IOpcUaQualifiedNameCompare;
 	PFOPCUAQUALIFIEDNAMECOPYTO IOpcUaQualifiedNameCopyTo;
 	PFOPCUASTRINGATTACHCOPY IOpcUaStringAttachCopy;
 	PFOPCUASTRINGATTACHREADONLY IOpcUaStringAttachReadOnly;
 	PFOPCUASTRINGATTACHTOSTRING IOpcUaStringAttachToString;
 	PFOPCUASTRINGCLEAR IOpcUaStringClear;
 	PFOPCUASTRINGGETRAWSTRING IOpcUaStringGetRawString;
 	PFOPCUASTRINGINITIALIZE IOpcUaStringInitialize;
 	PFOPCUASTRINGISEMPTY IOpcUaStringIsEmpty;
 	PFOPCUASTRINGISNULL IOpcUaStringIsNull;
 	PFOPCUASTRINGSTRLEN IOpcUaStringStrLen;
 	PFOPCUASTRINGSTRSIZE IOpcUaStringStrSize;
 	PFOPCUASTRINGSTRNCAT IOpcUaStringStrnCat;
 	PFOPCUASTRINGSTRNCPY IOpcUaStringStrnCpy;
 	PFOPCUASTRINGSTRNCMP IOpcUaStringStrnCmp;
 	PFOPCUAVARIANTINITIALIZE IOpcUaVariantInitialize;
 	PFOPCUAVARIANTCLEAR IOpcUaVariantClear;
 	PFOPCUAVARIANTCOMPARE IOpcUaVariantCompare;
 	PFOPCUAVARIANTCOPYTO IOpcUaVariantCopyTo;
 	PFOPCUADATAVALUEINITIALIZE IOpcUaDataValueInitialize;
 	PFOPCUADATAVALUECLEAR IOpcUaDataValueClear;
 	PFOPCUADATAVALUECOMPARE IOpcUaDataValueCompare;
 	PFOPCUADATAVALUECOPYTO IOpcUaDataValueCopyTo;
 	PFOPCUAEXTENSIONOBJECTCREATE IOpcUaExtensionObjectCreate;
 	PFOPCUAEXTENSIONOBJECTINITIALIZE IOpcUaExtensionObjectInitialize;
 	PFOPCUAEXTENSIONOBJECTCLEAR IOpcUaExtensionObjectClear;
 	PFOPCUAEXTENSIONOBJECTDELETE IOpcUaExtensionObjectDelete;
 	PFOPCUAEXTENSIONOBJECTCOMPARE IOpcUaExtensionObjectCompare;
 	PFOPCUAEXTENSIONOBJECTCOPYTO IOpcUaExtensionObjectCopyTo;
 	PFOPCUAREADVALUEIDINITIALIZE IOpcUaReadValueIdInitialize;
 	PFOPCUAREADVALUEIDCLEAR IOpcUaReadValueIdClear;
 	PFOPCUAREADVALUEIDCOPYTO IOpcUaReadValueIdCopyTo;
 	PFOPCUABROWSEDESCRIPTIONINITIALIZE IOpcUaBrowseDescriptionInitialize;
 	PFOPCUABROWSEDESCRIPTIONCLEAR IOpcUaBrowseDescriptionClear;
 	PFOPCUABROWSEPATHINITIALIZE IOpcUaBrowsePathInitialize;
 	PFOPCUABROWSEPATHCLEAR IOpcUaBrowsePathClear;
 	PFOPCUASTATUSCHANGENOTIFICATIONINITIALIZE IOpcUaStatusChangeNotificationInitialize;
 	PFOPCUASTATUSCHANGENOTIFICATIONCLEAR IOpcUaStatusChangeNotificationClear;
 	PFOPCUANOTIFICATIONMESSAGEINITIALIZE IOpcUaNotificationMessageInitialize;
 	PFOPCUANOTIFICATIONMESSAGECLEAR IOpcUaNotificationMessageClear;
 	PFOPCUAPUBLISHRESPONSEINITIALIZE IOpcUaPublishResponseInitialize;
 	PFOPCUAPUBLISHRESPONSECLEAR IOpcUaPublishResponseClear;
 	PFOPCUADATACHANGENOTIFICATIONINITIALIZE IOpcUaDataChangeNotificationInitialize;
 	PFOPCUADATACHANGENOTIFICATIONCLEAR IOpcUaDataChangeNotificationClear;
 	PFOPCUABROWSERESULTINITIALIZE IOpcUaBrowseResultInitialize;
 	PFOPCUABROWSERESULTCLEAR IOpcUaBrowseResultClear;
 	PFOPCUABROWSEPATHRESULTINITIALIZE IOpcUaBrowsePathResultInitialize;
 	PFOPCUABROWSEPATHRESULTCLEAR IOpcUaBrowsePathResultClear;
 	PFOPCUAREFERENCEDESCRIPTIONINITIALIZE IOpcUaReferenceDescriptionInitialize;
 	PFOPCUAREFERENCEDESCRIPTIONCLEAR IOpcUaReferenceDescriptionClear;
 	PFOPCUAUSERTOKENPOLICYINITIALIZE IOpcUaUserTokenPolicyInitialize;
 	PFOPCUAUSERTOKENPOLICYCLEAR IOpcUaUserTokenPolicyClear;
 	PFOPCUASIGNATUREDATAINITIALIZE IOpcUaSignatureDataInitialize;
 	PFOPCUASIGNATUREDATACLEAR IOpcUaSignatureDataClear;
 	PFOPCUAAPPLICATIONDESCRIPTIONINITIALIZE IOpcUaApplicationDescriptionInitialize;
 	PFOPCUAAPPLICATIONDESCRIPTIONCLEAR IOpcUaApplicationDescriptionClear;
 	PFOPCUASERVERONNETWORKINITIALIZE IOpcUaServerOnNetworkInitialize;
 	PFOPCUASERVERONNETWORKCLEAR IOpcUaServerOnNetworkClear;
 	PFOPCUAEVENTNOTIFICATIONLISTINITIALIZE IOpcUaEventNotificationListInitialize;
 	PFOPCUAEVENTNOTIFICATIONLISTCLEAR IOpcUaEventNotificationListClear;
 	PFOPCUAEVENTFIELDLISTINITIALIZE IOpcUaEventFieldListInitialize;
 	PFOPCUAEVENTFIELDLISTCLEAR IOpcUaEventFieldListClear;
 	PFOPCUASIMPLEATTRIBUTEOPERANDINITIALIZE IOpcUaSimpleAttributeOperandInitialize;
 	PFOPCUASIMPLEATTRIBUTEOPERANDCLEAR IOpcUaSimpleAttributeOperandClear;
 	PFOPCUAFINDSERVERSREQUESTINITIALIZE IOpcUaFindServersRequestInitialize;
 	PFOPCUAFINDSERVERSREQUESTCLEAR IOpcUaFindServersRequestClear;
 	PFOPCUAFINDSERVERSRESPONSEINITIALIZE IOpcUaFindServersResponseInitialize;
 	PFOPCUAFINDSERVERSRESPONSECLEAR IOpcUaFindServersResponseClear;
 	PFOPCUAFINDSERVERSONNETWORKREQUESTINITIALIZE IOpcUaFindServersOnNetworkRequestInitialize;
 	PFOPCUAFINDSERVERSONNETWORKREQUESTCLEAR IOpcUaFindServersOnNetworkRequestClear;
 	PFOPCUAFINDSERVERSONNETWORKRESPONSEINITIALIZE IOpcUaFindServersOnNetworkResponseInitialize;
 	PFOPCUAFINDSERVERSONNETWORKRESPONSECLEAR IOpcUaFindServersOnNetworkResponseClear;
 	PFOPCUAGETENDPOINTSREQUESTINITIALIZE IOpcUaGetEndpointsRequestInitialize;
 	PFOPCUAGETENDPOINTSREQUESTCLEAR IOpcUaGetEndpointsRequestClear;
 	PFOPCUAGETENDPOINTSRESPONSEINITIALIZE IOpcUaGetEndpointsResponseInitialize;
 	PFOPCUAGETENDPOINTSRESPONSECLEAR IOpcUaGetEndpointsResponseClear;
 	PFOPCUACREATESESSIONREQUESTINITIALIZE IOpcUaCreateSessionRequestInitialize;
 	PFOPCUACREATESESSIONREQUESTCLEAR IOpcUaCreateSessionRequestClear;
 	PFOPCUACREATESESSIONRESPONSEINITIALIZE IOpcUaCreateSessionResponseInitialize;
 	PFOPCUACREATESESSIONRESPONSECLEAR IOpcUaCreateSessionResponseClear;
 	PFOPCUAACTIVATESESSIONREQUESTINITIALIZE IOpcUaActivateSessionRequestInitialize;
 	PFOPCUAACTIVATESESSIONREQUESTCLEAR IOpcUaActivateSessionRequestClear;
 	PFOPCUAACTIVATESESSIONRESPONSEINITIALIZE IOpcUaActivateSessionResponseInitialize;
 	PFOPCUAACTIVATESESSIONRESPONSECLEAR IOpcUaActivateSessionResponseClear;
 	PFOPCUACLOSESESSIONREQUESTINITIALIZE IOpcUaCloseSessionRequestInitialize;
 	PFOPCUACLOSESESSIONREQUESTCLEAR IOpcUaCloseSessionRequestClear;
 	PFOPCUACLOSESESSIONRESPONSEINITIALIZE IOpcUaCloseSessionResponseInitialize;
 	PFOPCUACLOSESESSIONRESPONSECLEAR IOpcUaCloseSessionResponseClear;
 	PFOPCUAREADREQUESTINITIALIZE IOpcUaReadRequestInitialize;
 	PFOPCUAREADREQUESTCLEAR IOpcUaReadRequestClear;
 	PFOPCUAREADRESPONSEINITIALIZE IOpcUaReadResponseInitialize;
 	PFOPCUAREADRESPONSECLEAR IOpcUaReadResponseClear;
 	PFOPCUAWRITEREQUESTINITIALIZE IOpcUaWriteRequestInitialize;
 	PFOPCUAWRITEREQUESTCLEAR IOpcUaWriteRequestClear;
 	PFOPCUAWRITERESPONSEINITIALIZE IOpcUaWriteResponseInitialize;
 	PFOPCUAWRITERESPONSECLEAR IOpcUaWriteResponseClear;
 	PFOPCUACREATESUBSCRIPTIONREQUESTINITIALIZE IOpcUaCreateSubscriptionRequestInitialize;
 	PFOPCUACREATESUBSCRIPTIONREQUESTCLEAR IOpcUaCreateSubscriptionRequestClear;
 	PFOPCUAMODIFYSUBSCRIPTIONREQUESTINITIALIZE IOpcUaModifySubscriptionRequestInitialize;
 	PFOPCUAMODIFYSUBSCRIPTIONREQUESTCLEAR IOpcUaModifySubscriptionRequestClear;
 	PFOPCUAPUBLISHREQUESTINITIALIZE IOpcUaPublishRequestInitialize;
 	PFOPCUAPUBLISHREQUESTCLEAR IOpcUaPublishRequestClear;
 	PFOPCUAREPUBLISHREQUESTINITIALIZE IOpcUaRepublishRequestInitialize;
 	PFOPCUAREPUBLISHREQUESTCLEAR IOpcUaRepublishRequestClear;
 	PFOPCUASETPUBLISHINGMODEREQUESTINITIALIZE IOpcUaSetPublishingModeRequestInitialize;
 	PFOPCUASETPUBLISHINGMODEREQUESTCLEAR IOpcUaSetPublishingModeRequestClear;
 	PFOPCUADELETESUBSCRIPTIONSREQUESTINITIALIZE IOpcUaDeleteSubscriptionsRequestInitialize;
 	PFOPCUADELETESUBSCRIPTIONSREQUESTCLEAR IOpcUaDeleteSubscriptionsRequestClear;
 	PFOPCUATRANSFERSUBSCRIPTIONSREQUESTINITIALIZE IOpcUaTransferSubscriptionsRequestInitialize;
 	PFOPCUATRANSFERSUBSCRIPTIONSREQUESTCLEAR IOpcUaTransferSubscriptionsRequestClear;
 	PFOPCUACREATESUBSCRIPTIONRESPONSEINITIALIZE IOpcUaCreateSubscriptionResponseInitialize;
 	PFOPCUACREATESUBSCRIPTIONRESPONSECLEAR IOpcUaCreateSubscriptionResponseClear;
 	PFOPCUAMODIFYSUBSCRIPTIONRESPONSEINITIALIZE IOpcUaModifySubscriptionResponseInitialize;
 	PFOPCUAMODIFYSUBSCRIPTIONRESPONSECLEAR IOpcUaModifySubscriptionResponseClear;
 	PFOPCUAREPUBLISHRESPONSEINITIALIZE IOpcUaRepublishResponseInitialize;
 	PFOPCUAREPUBLISHRESPONSECLEAR IOpcUaRepublishResponseClear;
 	PFOPCUASETPUBLISHINGMODERESPONSEINITIALIZE IOpcUaSetPublishingModeResponseInitialize;
 	PFOPCUASETPUBLISHINGMODERESPONSECLEAR IOpcUaSetPublishingModeResponseClear;
 	PFOPCUADELETESUBSCRIPTIONSRESPONSEINITIALIZE IOpcUaDeleteSubscriptionsResponseInitialize;
 	PFOPCUADELETESUBSCRIPTIONSRESPONSECLEAR IOpcUaDeleteSubscriptionsResponseClear;
 	PFOPCUATRANSFERSUBSCRIPTIONSRESPONSEINITIALIZE IOpcUaTransferSubscriptionsResponseInitialize;
 	PFOPCUATRANSFERSUBSCRIPTIONSRESPONSECLEAR IOpcUaTransferSubscriptionsResponseClear;
 	PFOPCUACREATEMONITOREDITEMSREQUESTINITIALIZE IOpcUaCreateMonitoredItemsRequestInitialize;
 	PFOPCUACREATEMONITOREDITEMSREQUESTCLEAR IOpcUaCreateMonitoredItemsRequestClear;
 	PFOPCUACREATEMONITOREDITEMSRESPONSEINITIALIZE IOpcUaCreateMonitoredItemsResponseInitialize;
 	PFOPCUACREATEMONITOREDITEMSRESPONSECLEAR IOpcUaCreateMonitoredItemsResponseClear;
 	PFOPCUAMODIFYMONITOREDITEMSREQUESTINITIALIZE IOpcUaModifyMonitoredItemsRequestInitialize;
 	PFOPCUAMODIFYMONITOREDITEMSREQUESTCLEAR IOpcUaModifyMonitoredItemsRequestClear;
 	PFOPCUAMODIFYMONITOREDITEMSRESPONSEINITIALIZE IOpcUaModifyMonitoredItemsResponseInitialize;
 	PFOPCUAMODIFYMONITOREDITEMSRESPONSECLEAR IOpcUaModifyMonitoredItemsResponseClear;
 	PFOPCUASETMONITORINGMODEREQUESTINITIALIZE IOpcUaSetMonitoringModeRequestInitialize;
 	PFOPCUASETMONITORINGMODEREQUESTCLEAR IOpcUaSetMonitoringModeRequestClear;
 	PFOPCUASETMONITORINGMODERESPONSEINITIALIZE IOpcUaSetMonitoringModeResponseInitialize;
 	PFOPCUASETMONITORINGMODERESPONSECLEAR IOpcUaSetMonitoringModeResponseClear;
 	PFOPCUADELETEMONITOREDITEMSREQUESTINITIALIZE IOpcUaDeleteMonitoredItemsRequestInitialize;
 	PFOPCUADELETEMONITOREDITEMSREQUESTCLEAR IOpcUaDeleteMonitoredItemsRequestClear;
 	PFOPCUADELETEMONITOREDITEMSRESPONSEINITIALIZE IOpcUaDeleteMonitoredItemsResponseInitialize;
 	PFOPCUADELETEMONITOREDITEMSRESPONSECLEAR IOpcUaDeleteMonitoredItemsResponseClear;
 	PFOPCUABROWSEREQUESTINITIALIZE IOpcUaBrowseRequestInitialize;
 	PFOPCUABROWSEREQUESTCLEAR IOpcUaBrowseRequestClear;
 	PFOPCUABROWSERESPONSEINITIALIZE IOpcUaBrowseResponseInitialize;
 	PFOPCUABROWSERESPONSECLEAR IOpcUaBrowseResponseClear;
 	PFOPCUABROWSENEXTREQUESTINITIALIZE IOpcUaBrowseNextRequestInitialize;
 	PFOPCUABROWSENEXTREQUESTCLEAR IOpcUaBrowseNextRequestClear;
 	PFOPCUABROWSENEXTRESPONSEINITIALIZE IOpcUaBrowseNextResponseInitialize;
 	PFOPCUABROWSENEXTRESPONSECLEAR IOpcUaBrowseNextResponseClear;
 	PFOPCUATRANSLATEBROWSEPATHSTONODEIDSREQUESTINITIALIZE IOpcUaTranslateBrowsePathsToNodeIdsRequestInitialize;
 	PFOPCUATRANSLATEBROWSEPATHSTONODEIDSREQUESTCLEAR IOpcUaTranslateBrowsePathsToNodeIdsRequestClear;
 	PFOPCUATRANSLATEBROWSEPATHSTONODEIDSRESPONSEINITIALIZE IOpcUaTranslateBrowsePathsToNodeIdsResponseInitialize;
 	PFOPCUATRANSLATEBROWSEPATHSTONODEIDSRESPONSECLEAR IOpcUaTranslateBrowsePathsToNodeIdsResponseClear;
 	PFOPCUAREGISTERNODESREQUESTINITIALIZE IOpcUaRegisterNodesRequestInitialize;
 	PFOPCUAREGISTERNODESREQUESTCLEAR IOpcUaRegisterNodesRequestClear;
 	PFOPCUAREGISTERNODESRESPONSEINITIALIZE IOpcUaRegisterNodesResponseInitialize;
 	PFOPCUAREGISTERNODESRESPONSECLEAR IOpcUaRegisterNodesResponseClear;
 	PFOPCUAUNREGISTERNODESREQUESTINITIALIZE IOpcUaUnregisterNodesRequestInitialize;
 	PFOPCUAUNREGISTERNODESREQUESTCLEAR IOpcUaUnregisterNodesRequestClear;
 	PFOPCUAUNREGISTERNODESRESPONSEINITIALIZE IOpcUaUnregisterNodesResponseInitialize;
 	PFOPCUAUNREGISTERNODESRESPONSECLEAR IOpcUaUnregisterNodesResponseClear;
 	PFOPCUALISTCREATE IOpcUaListCreate;
 	PFOPCUALISTINITIALIZE IOpcUaListInitialize;
 	PFOPCUALISTCLEAR IOpcUaListClear;
 	PFOPCUALISTDELETE IOpcUaListDelete;
 	PFOPCUALISTENTER IOpcUaListEnter;
 	PFOPCUALISTLEAVE IOpcUaListLeave;
 	PFOPCUALISTADDELEMENT IOpcUaListAddElement;
 	PFOPCUALISTADDELEMENTTOEND IOpcUaListAddElementToEnd;
 	PFOPCUALISTINSERTELEMENT IOpcUaListInsertElement;
 	PFOPCUALISTRESETCURRENT IOpcUaListResetCurrent;
 	PFOPCUALISTGETNEXTELEMENT IOpcUaListGetNextElement;
 	PFOPCUALISTGETCURRENTELEMENT IOpcUaListGetCurrentElement;
 	PFOPCUALISTGETPREVELEMENT IOpcUaListGetPrevElement;
 	PFOPCUALISTGETELEMENT IOpcUaListGetElement;
 	PFOPCUALISTDELETECURRENTELEMENT IOpcUaListDeleteCurrentElement;
 	PFOPCUALISTDELETEELEMENT IOpcUaListDeleteElement;
 	PFOPCUALISTGETNUMBEROFELEMENTS IOpcUaListGetNumberOfElements;
 	PFOPCUALISTREMOVEFIRSTELEMENT IOpcUaListRemoveFirstElement;
 	PFOPCUAENDPOINTDESCRIPTIONINITIALIZE IOpcUaEndpointDescriptionInitialize;
 	PFOPCUAENDPOINTDESCRIPTIONCLEAR IOpcUaEndpointDescriptionClear;
 	PFOPCUAENDPOINTBEGINSENDRESPONSE IOpcUaEndpointBeginSendResponse;
 	PFOPCUAENDPOINTCANCELSENDRESPONSE IOpcUaEndpointCancelSendResponse;
 	PFOPCUAENDPOINTCLOSE IOpcUaEndpointClose;
 	PFOPCUAENDPOINTCREATE IOpcUaEndpointCreate;
 	PFOPCUAENDPOINTDELETE IOpcUaEndpointDelete;
 	PFOPCUAENDPOINTENDSENDRESPONSE IOpcUaEndpointEndSendResponse;
 	PFOPCUAENDPOINTGETMESSAGESECURECHANNELID IOpcUaEndpointGetMessageSecureChannelId;
 	PFOPCUAENDPOINTGETMESSAGESECURECHANNELSECURITYPOLICY IOpcUaEndpointGetMessageSecureChannelSecurityPolicy;
 	PFOPCUAENDPOINTOPEN IOpcUaEndpointOpen;
 	PFOPCUAENDPOINTSENDERRORRESPONSE IOpcUaEndpointSendErrorResponse;
 	PFOPCUAENDPOINTGETSERVICEFUNCTION IOpcUaEndpointGetServiceFunction;
 	PFOPCUAENDPOINTUPDATESERVICEFUNCTIONS IOpcUaEndpointUpdateServiceFunctions;
 	PFOPCUAENDPOINTGETCALLBACKDATA IOpcUaEndpointGetCallbackData;
 	PFOPCUAENDPOINTGETPEERINFOFROMCONTEXT IOpcUaEndpointGetPeerInfoFromContext;
 	PFOPCUATIMERCREATE IOpcUaTimerCreate;
 	PFOPCUATIMERDELETE IOpcUaTimerDelete;
 	PFOPCUASOCKETMANAGERLOOP IOpcUaSocketManagerLoop;
 	PFOPCUASOCKETMANAGERCREATE IOpcUaSocketManagerCreate;
 	PFOPCUASOCKETMANAGERDELETE IOpcUaSocketManagerDelete;
 	PFOPCUASERVERAPICREATEFAULT IOpcUaServerApiCreateFault;
 	PFOPCUAGETENCODABLEOBJECTTYPE IOpcUaGetEncodableObjectType;
 	PFOPCUAGETBEGINSERVICEFUNCTION IOpcUaGetBeginServiceFunction;
 	PFOPCUASTACKCONVERTASYMMETRICKEY IOpcUaStackConvertAsymmetricKey;
 	PFOPCUASIGNATUREINITIALIZE IOpcUaSignatureInitialize;
 	PFOPCUASIGNATURECLEAR IOpcUaSignatureClear;
 	PFOPCUAKEYINITIALIZE IOpcUaKeyInitialize;
 	PFOPCUAKEYCLEAR IOpcUaKeyClear;
 	PFOPCUACRYPTOGENERATEKEY IOpcUaCryptoGenerateKey;
 	PFOPCUACRYPTODERIVEKEY IOpcUaCryptoDeriveKey;
 	PFOPCUACRYPTOASYMMETRICSIGN IOpcUaCryptoAsymmetricSign;
 	PFOPCUACRYPTOASYMMETRICVERIFY IOpcUaCryptoAsymmetricVerify;
 	PFOPCUACRYPTOASYMMETRICDECRYPT IOpcUaCryptoAsymmetricDecrypt;
 	PFOPCUACRYPTOASYMMETRICENCRYPT IOpcUaCryptoAsymmetricEncrypt;
 	PFOPCUACRYPTOGETSIGNATUREALGORITHMURI IOpcUaCryptoGetSignatureAlgorithmUri;
 	PFOPCUACRYPTOGETASYMMETRICENCRYPTIONALGORITHMURI IOpcUaCryptoGetAsymmetricEncryptionAlgorithmUri;
 	PFOPCUACRYPTOGETASYMMETRICKEYLENGTH IOpcUaCryptoGetAsymmetricKeyLength;
 	PFOPCUACRYPTOPROVIDERCREATE IOpcUaCryptoProviderCreate;
 	PFOPCUACRYPTOPROVIDERDELETE IOpcUaCryptoProviderDelete;
 	PFOPCUASTACKGENERATEAPPLICATIONSIGNATURE IOpcUaStackGenerateApplicationSignature;
 	PFOPCUASTACKVERIFYAPPLICATIONSIGNATURE IOpcUaStackVerifyApplicationSignature;
 	PFOPCUACHANNELCREATE IOpcUaChannelCreate;
 	PFOPCUACHANNELDELETE IOpcUaChannelDelete;
 	PFOPCUACHANNELBEGINCONNECT IOpcUaChannelBeginConnect;
 	PFOPCUACHANNELBEGINDISCONNECT IOpcUaChannelBeginDisconnect;
 	PFOPCUACHANNELBEGININVOKESERVICE IOpcUaChannelBeginInvokeService;
 	PFOPCUADATETIMEGETSTRINGFROMDATETIME IOpcUaDateTimeGetStringFromDateTime;
 } ICmpOPCUAStack_C;

#ifdef CPLUSPLUS
class ICmpOPCUAStack : public IBase
{
	public:
		virtual OpcUa_Void CDECL IOpcUaByteStringInitialize(OpcUa_ByteString* value) =0;
		virtual OpcUa_Void CDECL IOpcUaByteStringClear(OpcUa_ByteString* value) =0;
		virtual OpcUa_Int CDECL IOpcUaByteStringCompare(const OpcUa_ByteString* value1, const OpcUa_ByteString* value2) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaByteStringCopyTo(const OpcUa_ByteString* source, OpcUa_ByteString* destination) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaByteStringConcatenate(const OpcUa_ByteString* source, OpcUa_ByteString* destination, OpcUa_Int len) =0;
		virtual OpcUa_DateTime CDECL IOpcUaDateTimeUtcNow(void) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaEncodeableObjectCreate(OpcUa_EncodeableType* pType, OpcUa_Void** ppEncodeable) =0;
		virtual OpcUa_Void CDECL IOpcUaEncodeableObjectDelete(OpcUa_EncodeableType* pType, OpcUa_Void** ppEncodeable) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaEncodeableObjectCreateExtension(OpcUa_EncodeableType* pType, OpcUa_ExtensionObject* pExtension, OpcUa_Void** ppEncodeableObject) =0;
		virtual OpcUa_Void CDECL IOpcUaLocalizedTextInitialize(OpcUa_LocalizedText* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaLocalizedTextClear(OpcUa_LocalizedText* pValue) =0;
		virtual OpcUa_Int CDECL IOpcUaLocalizedTextCompare(const OpcUa_LocalizedText* pValue1, const OpcUa_LocalizedText* pValue2) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaLocalizedTextCopyTo(const OpcUa_LocalizedText* pSource, OpcUa_LocalizedText* pDestination) =0;
		virtual OpcUa_Void CDECL IOpcUaNodeIdInitialize(OpcUa_NodeId* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaNodeIdClear(OpcUa_NodeId* pValue) =0;
		virtual OpcUa_Int CDECL IOpcUaNodeIdCompare(const OpcUa_NodeId* pValue1, const OpcUa_NodeId* pValue2) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaNodeIdCopyTo(const OpcUa_NodeId* pSource, OpcUa_NodeId* pDestination) =0;
		virtual OpcUa_Boolean CDECL IOpcUaNodeIdIsNull(OpcUa_NodeId* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaExpandedNodeIdInitialize(OpcUa_ExpandedNodeId* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaExpandedNodeIdClear(OpcUa_ExpandedNodeId* pValue) =0;
		virtual OpcUa_Int CDECL IOpcUaExpandedNodeIdCompare(const OpcUa_ExpandedNodeId* pValue1, const OpcUa_ExpandedNodeId* pValue2) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaExpandedNodeIdCopyTo(const OpcUa_ExpandedNodeId* pSource, OpcUa_ExpandedNodeId* pDestination) =0;
		virtual OpcUa_Boolean CDECL IOpcUaExpandedNodeIdIsNull(OpcUa_ExpandedNodeId* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaQualifiedNameInitialize(OpcUa_QualifiedName* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaQualifiedNameClear(OpcUa_QualifiedName* pValue) =0;
		virtual OpcUa_Int CDECL IOpcUaQualifiedNameCompare(const OpcUa_QualifiedName* pValue1, const OpcUa_QualifiedName* pValue2) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaQualifiedNameCopyTo(const OpcUa_QualifiedName* pSource, OpcUa_QualifiedName* pDestination) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaStringAttachCopy(OpcUa_String* pDst, const OpcUa_CharA* pSrc) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaStringAttachReadOnly(OpcUa_String* a_pDst, const OpcUa_CharA* a_pSrc) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaStringAttachToString(OpcUa_StringA strSource, OpcUa_UInt32  uLength, OpcUa_UInt32  uBufferSize, OpcUa_Boolean bDoCopy, OpcUa_Boolean bFreeOnClear, OpcUa_String* pString) =0;
		virtual OpcUa_Void CDECL IOpcUaStringClear(OpcUa_String* pString) =0;
		virtual OpcUa_CharA* CDECL IOpcUaStringGetRawString(const OpcUa_String* pString) =0;
		virtual OpcUa_Void CDECL IOpcUaStringInitialize(OpcUa_String* pString) =0;
		virtual OpcUa_Boolean CDECL IOpcUaStringIsEmpty(const OpcUa_String* pString) =0;
		virtual OpcUa_Boolean CDECL IOpcUaStringIsNull(const OpcUa_String* pString) =0;
		virtual OpcUa_UInt32 CDECL IOpcUaStringStrLen(const OpcUa_String* pString) =0;
		virtual OpcUa_UInt32 CDECL IOpcUaStringStrSize(const OpcUa_String* pString) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaStringStrnCat(OpcUa_String* pDestString, const OpcUa_String* pSrcString, OpcUa_UInt32 uLength) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaStringStrnCpy(OpcUa_String* pDestString, const OpcUa_String* pSrcString, OpcUa_UInt32 uLength) =0;
		virtual OpcUa_Int32 CDECL IOpcUaStringStrnCmp(const OpcUa_String* a_pLeftString, const OpcUa_String* a_pRightString, OpcUa_UInt32 a_uLength, OpcUa_Boolean a_bIgnoreCase) =0;
		virtual OpcUa_Void CDECL IOpcUaVariantInitialize(OpcUa_Variant* value) =0;
		virtual OpcUa_Void CDECL IOpcUaVariantClear(OpcUa_Variant* value) =0;
		virtual OpcUa_Int CDECL IOpcUaVariantCompare(const OpcUa_Variant* pValue1, const OpcUa_Variant* pValue2) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaVariantCopyTo(const OpcUa_Variant* pSource, OpcUa_Variant* pDestination) =0;
		virtual OpcUa_Void CDECL IOpcUaDataValueInitialize(OpcUa_DataValue* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaDataValueClear(OpcUa_DataValue* pValue) =0;
		virtual OpcUa_Int CDECL IOpcUaDataValueCompare(const OpcUa_DataValue* pValue1, const OpcUa_DataValue* pValue2) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaDataValueCopyTo(const OpcUa_DataValue* pSource, OpcUa_DataValue* pDestination) =0;
		virtual OpcUa_Void CDECL IOpcUaExtensionObjectCreate(OpcUa_ExtensionObject** ppValue) =0;
		virtual OpcUa_Void CDECL IOpcUaExtensionObjectInitialize(OpcUa_ExtensionObject* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaExtensionObjectClear(OpcUa_ExtensionObject* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaExtensionObjectDelete(OpcUa_ExtensionObject** ppValue) =0;
		virtual OpcUa_Int CDECL IOpcUaExtensionObjectCompare(const OpcUa_ExtensionObject* pValue1, const OpcUa_ExtensionObject* pValue2) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaExtensionObjectCopyTo(const OpcUa_ExtensionObject* pSource, OpcUa_ExtensionObject* pDestination) =0;
		virtual OpcUa_Void CDECL IOpcUaReadValueIdInitialize(OpcUa_ReadValueId* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaReadValueIdClear(OpcUa_ReadValueId* pValue) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaReadValueIdCopyTo(const OpcUa_ReadValueId* pSource, OpcUa_ReadValueId* pDestination) =0;
		virtual OpcUa_Void CDECL IOpcUaBrowseDescriptionInitialize(OpcUa_BrowseDescription* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaBrowseDescriptionClear(OpcUa_BrowseDescription* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaBrowsePathInitialize(OpcUa_BrowsePath* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaBrowsePathClear(OpcUa_BrowsePath* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaStatusChangeNotificationInitialize(OpcUa_StatusChangeNotification* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaStatusChangeNotificationClear(OpcUa_StatusChangeNotification* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaNotificationMessageInitialize(OpcUa_NotificationMessage* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaNotificationMessageClear(OpcUa_NotificationMessage* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaPublishResponseInitialize(OpcUa_PublishResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaPublishResponseClear(OpcUa_PublishResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaDataChangeNotificationInitialize(OpcUa_DataChangeNotification* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaDataChangeNotificationClear(OpcUa_DataChangeNotification* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaBrowseResultInitialize(OpcUa_BrowseResult* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaBrowseResultClear(OpcUa_BrowseResult* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaBrowsePathResultInitialize(OpcUa_BrowsePathResult* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaBrowsePathResultClear(OpcUa_BrowsePathResult* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaReferenceDescriptionInitialize(OpcUa_ReferenceDescription* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaReferenceDescriptionClear(OpcUa_ReferenceDescription* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaUserTokenPolicyInitialize(OpcUa_UserTokenPolicy* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaUserTokenPolicyClear(OpcUa_UserTokenPolicy* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaSignatureDataInitialize(OpcUa_SignatureData* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaSignatureDataClear(OpcUa_SignatureData* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaApplicationDescriptionInitialize(OpcUa_ApplicationDescription* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaApplicationDescriptionClear(OpcUa_ApplicationDescription* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaServerOnNetworkInitialize(OpcUa_ServerOnNetwork* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaServerOnNetworkClear(OpcUa_ServerOnNetwork* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaEventNotificationListInitialize(OpcUa_EventNotificationList* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaEventNotificationListClear(OpcUa_EventNotificationList* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaEventFieldListInitialize(OpcUa_EventFieldList* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaEventFieldListClear(OpcUa_EventFieldList* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaSimpleAttributeOperandInitialize(OpcUa_SimpleAttributeOperand* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaSimpleAttributeOperandClear(OpcUa_SimpleAttributeOperand* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaFindServersRequestInitialize(OpcUa_FindServersRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaFindServersRequestClear(OpcUa_FindServersRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaFindServersResponseInitialize(OpcUa_FindServersResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaFindServersResponseClear(OpcUa_FindServersResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaFindServersOnNetworkRequestInitialize(OpcUa_FindServersOnNetworkRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaFindServersOnNetworkRequestClear(OpcUa_FindServersOnNetworkRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaFindServersOnNetworkResponseInitialize(OpcUa_FindServersOnNetworkResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaFindServersOnNetworkResponseClear(OpcUa_FindServersOnNetworkResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaGetEndpointsRequestInitialize(OpcUa_GetEndpointsRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaGetEndpointsRequestClear(OpcUa_GetEndpointsRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaGetEndpointsResponseInitialize(OpcUa_GetEndpointsResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaGetEndpointsResponseClear(OpcUa_GetEndpointsResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaCreateSessionRequestInitialize(OpcUa_CreateSessionRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaCreateSessionRequestClear(OpcUa_CreateSessionRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaCreateSessionResponseInitialize(OpcUa_CreateSessionResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaCreateSessionResponseClear(OpcUa_CreateSessionResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaActivateSessionRequestInitialize(OpcUa_ActivateSessionRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaActivateSessionRequestClear(OpcUa_ActivateSessionRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaActivateSessionResponseInitialize(OpcUa_ActivateSessionResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaActivateSessionResponseClear(OpcUa_ActivateSessionResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaCloseSessionRequestInitialize(OpcUa_CloseSessionRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaCloseSessionRequestClear(OpcUa_CloseSessionRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaCloseSessionResponseInitialize(OpcUa_CloseSessionResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaCloseSessionResponseClear(OpcUa_CloseSessionResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaReadRequestInitialize(OpcUa_ReadRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaReadRequestClear(OpcUa_ReadRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaReadResponseInitialize(OpcUa_ReadResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaReadResponseClear(OpcUa_ReadResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaWriteRequestInitialize(OpcUa_WriteRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaWriteRequestClear(OpcUa_WriteRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaWriteResponseInitialize(OpcUa_WriteResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaWriteResponseClear(OpcUa_WriteResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaCreateSubscriptionRequestInitialize(OpcUa_CreateSubscriptionRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaCreateSubscriptionRequestClear(OpcUa_CreateSubscriptionRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaModifySubscriptionRequestInitialize(OpcUa_ModifySubscriptionRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaModifySubscriptionRequestClear(OpcUa_ModifySubscriptionRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaPublishRequestInitialize(OpcUa_PublishRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaPublishRequestClear(OpcUa_PublishRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaRepublishRequestInitialize(OpcUa_RepublishRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaRepublishRequestClear(OpcUa_RepublishRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaSetPublishingModeRequestInitialize(OpcUa_SetPublishingModeRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaSetPublishingModeRequestClear(OpcUa_SetPublishingModeRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaDeleteSubscriptionsRequestInitialize(OpcUa_DeleteSubscriptionsRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaDeleteSubscriptionsRequestClear(OpcUa_DeleteSubscriptionsRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaTransferSubscriptionsRequestInitialize(OpcUa_TransferSubscriptionsRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaTransferSubscriptionsRequestClear(OpcUa_TransferSubscriptionsRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaCreateSubscriptionResponseInitialize(OpcUa_CreateSubscriptionResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaCreateSubscriptionResponseClear(OpcUa_CreateSubscriptionResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaModifySubscriptionResponseInitialize(OpcUa_ModifySubscriptionResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaModifySubscriptionResponseClear(OpcUa_ModifySubscriptionResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaRepublishResponseInitialize(OpcUa_RepublishResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaRepublishResponseClear(OpcUa_RepublishResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaSetPublishingModeResponseInitialize(OpcUa_SetPublishingModeResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaSetPublishingModeResponseClear(OpcUa_SetPublishingModeResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaDeleteSubscriptionsResponseInitialize(OpcUa_DeleteSubscriptionsResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaDeleteSubscriptionsResponseClear(OpcUa_DeleteSubscriptionsResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaTransferSubscriptionsResponseInitialize(OpcUa_TransferSubscriptionsResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaTransferSubscriptionsResponseClear(OpcUa_TransferSubscriptionsResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaCreateMonitoredItemsRequestInitialize(OpcUa_CreateMonitoredItemsRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaCreateMonitoredItemsRequestClear(OpcUa_CreateMonitoredItemsRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaCreateMonitoredItemsResponseInitialize(OpcUa_CreateMonitoredItemsResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaCreateMonitoredItemsResponseClear(OpcUa_CreateMonitoredItemsResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaModifyMonitoredItemsRequestInitialize(OpcUa_ModifyMonitoredItemsRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaModifyMonitoredItemsRequestClear(OpcUa_ModifyMonitoredItemsRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaModifyMonitoredItemsResponseInitialize(OpcUa_ModifyMonitoredItemsResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaModifyMonitoredItemsResponseClear(OpcUa_ModifyMonitoredItemsResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaSetMonitoringModeRequestInitialize(OpcUa_SetMonitoringModeRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaSetMonitoringModeRequestClear(OpcUa_SetMonitoringModeRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaSetMonitoringModeResponseInitialize(OpcUa_SetMonitoringModeResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaSetMonitoringModeResponseClear(OpcUa_SetMonitoringModeResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaDeleteMonitoredItemsRequestInitialize(OpcUa_DeleteMonitoredItemsRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaDeleteMonitoredItemsRequestClear(OpcUa_DeleteMonitoredItemsRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaDeleteMonitoredItemsResponseInitialize(OpcUa_DeleteMonitoredItemsResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaDeleteMonitoredItemsResponseClear(OpcUa_DeleteMonitoredItemsResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaBrowseRequestInitialize(OpcUa_BrowseRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaBrowseRequestClear(OpcUa_BrowseRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaBrowseResponseInitialize(OpcUa_BrowseResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaBrowseResponseClear(OpcUa_BrowseResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaBrowseNextRequestInitialize(OpcUa_BrowseNextRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaBrowseNextRequestClear(OpcUa_BrowseNextRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaBrowseNextResponseInitialize(OpcUa_BrowseNextResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaBrowseNextResponseClear(OpcUa_BrowseNextResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaTranslateBrowsePathsToNodeIdsRequestInitialize(OpcUa_TranslateBrowsePathsToNodeIdsRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaTranslateBrowsePathsToNodeIdsRequestClear(OpcUa_TranslateBrowsePathsToNodeIdsRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaTranslateBrowsePathsToNodeIdsResponseInitialize(OpcUa_TranslateBrowsePathsToNodeIdsResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaTranslateBrowsePathsToNodeIdsResponseClear(OpcUa_TranslateBrowsePathsToNodeIdsResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaRegisterNodesRequestInitialize(OpcUa_RegisterNodesRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaRegisterNodesRequestClear(OpcUa_RegisterNodesRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaRegisterNodesResponseInitialize(OpcUa_RegisterNodesResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaRegisterNodesResponseClear(OpcUa_RegisterNodesResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaUnregisterNodesRequestInitialize(OpcUa_UnregisterNodesRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaUnregisterNodesRequestClear(OpcUa_UnregisterNodesRequest* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaUnregisterNodesResponseInitialize(OpcUa_UnregisterNodesResponse* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaUnregisterNodesResponseClear(OpcUa_UnregisterNodesResponse* pValue) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaListCreate(OpcUa_List** ppList) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaListInitialize(OpcUa_List* pList) =0;
		virtual OpcUa_Void CDECL IOpcUaListClear(OpcUa_List* pList) =0;
		virtual OpcUa_Void CDECL IOpcUaListDelete(OpcUa_List** ppList) =0;
		virtual OpcUa_Void CDECL IOpcUaListEnter(OpcUa_List* pList) =0;
		virtual OpcUa_Void CDECL IOpcUaListLeave(OpcUa_List* pList) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaListAddElement(OpcUa_List* pList, OpcUa_Void* pElementData) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaListAddElementToEnd(OpcUa_List* pList, OpcUa_Void* pElementData) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaListInsertElement(OpcUa_List* pList, OpcUa_Void* pElementData) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaListResetCurrent(OpcUa_List* pList) =0;
		virtual OpcUa_Void* CDECL IOpcUaListGetNextElement(OpcUa_List* pList) =0;
		virtual OpcUa_Void* CDECL IOpcUaListGetCurrentElement(OpcUa_List* pList) =0;
		virtual OpcUa_Void* CDECL IOpcUaListGetPrevElement(OpcUa_List* pList) =0;
		virtual OpcUa_Void* CDECL IOpcUaListGetElement(OpcUa_List* pList, OpcUa_Void* pElementData) =0;
		virtual OpcUa_Void CDECL IOpcUaListDeleteCurrentElement(OpcUa_List* pList) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaListDeleteElement(OpcUa_List* pList, OpcUa_Void* pElementData) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaListGetNumberOfElements(OpcUa_List* pList, OpcUa_UInt32* uintElementCount) =0;
		virtual OpcUa_Void* CDECL IOpcUaListRemoveFirstElement(OpcUa_List* pList) =0;
		virtual OpcUa_Void CDECL IOpcUaEndpointDescriptionInitialize(OpcUa_EndpointDescription* pValue) =0;
		virtual OpcUa_Void CDECL IOpcUaEndpointDescriptionClear(OpcUa_EndpointDescription* pValue) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaEndpointBeginSendResponse(OpcUa_Endpoint hEndpoint, OpcUa_Handle hContext, OpcUa_Void** ppResponse, OpcUa_EncodeableType** ppResponseType) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaEndpointCancelSendResponse(OpcUa_Endpoint hEndpoint, OpcUa_StatusCode uStatus, OpcUa_String* psReason, OpcUa_Handle* hContext) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaEndpointClose(OpcUa_Endpoint hEndpoint) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaEndpointCreate(OpcUa_Endpoint* phEndpoint, OpcUa_Endpoint_SerializerType eSerializerType, OpcUa_ServiceType** pSupportedServices) =0;
		virtual OpcUa_Void CDECL IOpcUaEndpointDelete(OpcUa_Endpoint* phEndpoint) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaEndpointEndSendResponse(OpcUa_Endpoint hEndpoint, OpcUa_Handle* hContext, OpcUa_StatusCode uStatusCode, OpcUa_Void* pResponse, OpcUa_EncodeableType* pResponseType) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaEndpointGetMessageSecureChannelId(OpcUa_Endpoint hEndpoint, OpcUa_Handle hContext, OpcUa_UInt32* pSecureChannelId) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaEndpointGetMessageSecureChannelSecurityPolicy(OpcUa_Endpoint hEndpoint, OpcUa_Handle hContext, OpcUa_Endpoint_SecurityPolicyConfiguration* pSecurityPolicy) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaEndpointOpen(OpcUa_Endpoint hEndpoint, OpcUa_StringA sUrl, OpcUa_StringA sTransportProfileUri, OpcUa_Endpoint_PfnEndpointCallback* pfEndpointCallback, OpcUa_Void* pvEndpointCallbackData, OpcUa_ByteString* pServerCertificate, OpcUa_Key* pServerPrivateKey, OpcUa_Void* pPKIConfig, OpcUa_UInt32 nNoOfSecurityPolicies, OpcUa_Endpoint_SecurityPolicyConfiguration* pSecurityPolicies, OpcUa_SocketManager hSocketManager) =0;
		virtual OpcUa_Void CDECL IOpcUaEndpointSendErrorResponse(OpcUa_Endpoint hEndpoint, OpcUa_Handle hContext, OpcUa_StatusCode uStatus) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaEndpointGetServiceFunction(OpcUa_Endpoint hEndpoint, OpcUa_Handle hContext, OpcUa_PfnInvokeService** ppInvoke) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaEndpointUpdateServiceFunctions(OpcUa_Endpoint hEndpoint, OpcUa_UInt32 uRequestTypeId, OpcUa_PfnBeginInvokeService* pBeginInvoke, OpcUa_PfnInvokeService* pInvoke) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaEndpointGetCallbackData(OpcUa_Endpoint hEndpoint, OpcUa_Void** ppvCallbackData) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaEndpointGetPeerInfoFromContext(OpcUa_Endpoint hEndpoint, OpcUa_Handle hContext, OpcUa_String* psPeerInfo) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaTimerCreate(OpcUa_Timer* hTimer, OpcUa_UInt32 msecInterval, OpcUa_Timer_Callback* fpTimerCallback, OpcUa_Timer_Callback* fpKillCallback, OpcUa_Void* pvCallbackData) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaTimerDelete(OpcUa_Timer* phTimer) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaSocketManagerLoop(OpcUa_SocketManager pSocketManager, OpcUa_UInt32 msecTimeout, OpcUa_Boolean bRunOnce) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaSocketManagerCreate(OpcUa_SocketManager* pSocketManager, OpcUa_UInt32 nSockets, OpcUa_UInt32 nFlags) =0;
		virtual OpcUa_Void CDECL IOpcUaSocketManagerDelete(OpcUa_SocketManager* pSocketManager) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaServerApiCreateFault(OpcUa_RequestHeader* pRequestHeader, OpcUa_StatusCode uServiceResult, OpcUa_DiagnosticInfo* pServiceDiagnostics, OpcUa_Int32* pNoOfStringTable, OpcUa_String** ppStringTable, OpcUa_Void** ppFault, OpcUa_EncodeableType** ppFaultType) =0;
		virtual OpcUa_EncodeableType* CDECL IOpcUaGetEncodableObjectType(OpcUa_UInt32 ui32TypeId) =0;
		virtual OpcUa_PfnBeginInvokeService* CDECL IOpcUaGetBeginServiceFunction(OpcUa_UInt32 ui32ServiceId) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaStackConvertAsymmetricKey(RtsCryptoKey* rtsKey, OpcUa_Boolean bPrivateKey, OpcUa_Key* opcuaKey) =0;
		virtual OpcUa_Void CDECL IOpcUaSignatureInitialize(OpcUa_Signature* pSignature) =0;
		virtual OpcUa_Void CDECL IOpcUaSignatureClear(OpcUa_Signature* pSignature) =0;
		virtual OpcUa_Void CDECL IOpcUaKeyInitialize(OpcUa_Key* pKey) =0;
		virtual OpcUa_Void CDECL IOpcUaKeyClear(OpcUa_Key* pKey) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaCryptoGenerateKey(OpcUa_CryptoProvider* pProvider, OpcUa_Int32 keyLen, OpcUa_Key* pKey) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaCryptoDeriveKey(OpcUa_CryptoProvider* pProvider, OpcUa_ByteString secret, OpcUa_ByteString seed, OpcUa_Int32 keyLen, OpcUa_Key* pKey) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaCryptoAsymmetricSign(OpcUa_CryptoProvider* pProvider, OpcUa_ByteString data, OpcUa_Key* privateKey, OpcUa_ByteString* pSignature) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaCryptoAsymmetricVerify(OpcUa_CryptoProvider* pProvider, OpcUa_ByteString data, OpcUa_Key* publicKey, OpcUa_ByteString* pSignature) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaCryptoAsymmetricDecrypt(OpcUa_CryptoProvider* pProvider, OpcUa_Byte* pCipherText, OpcUa_UInt32 cipherTextLen, OpcUa_Key* privateKey, OpcUa_Byte* pPlainText, OpcUa_UInt32* pPlainTextLen) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaCryptoAsymmetricEncrypt(OpcUa_CryptoProvider* pProvider, OpcUa_Byte* pPlainText, OpcUa_UInt32 plainTextLen, OpcUa_Key* publicKey, OpcUa_Byte* pCipherText, OpcUa_UInt32* pCipherTextLen) =0;
		virtual OpcUa_CharA* CDECL IOpcUaCryptoGetSignatureAlgorithmUri(OpcUa_CryptoProvider* pProvider) =0;
		virtual OpcUa_CharA* CDECL IOpcUaCryptoGetAsymmetricEncryptionAlgorithmUri(OpcUa_CryptoProvider* pProvider) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaCryptoGetAsymmetricKeyLength(OpcUa_CryptoProvider* a_pProvider, OpcUa_Key a_publicKey, OpcUa_UInt32* a_pBits) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaCryptoProviderCreate(OpcUa_StringA a_psSecurityProfileUri, OpcUa_CryptoProvider* a_pProvider) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaCryptoProviderDelete(OpcUa_CryptoProvider* a_pProvider) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaStackGenerateApplicationSignature(const OpcUa_StringA pszSecurityPolicyUri, const OpcUa_ByteString *pPeerCert, const OpcUa_ByteString *pPeerNonce, const OpcUa_Key *pMyPrivateKey, OpcUa_SignatureData *pSignature) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaStackVerifyApplicationSignature(const OpcUa_StringA pszSecurityPolicyUri, const OpcUa_SignatureData *pSignature, const OpcUa_ByteString *pMyCert, const OpcUa_ByteString *pMyNonce, RTS_HANDLE hPeerCert) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaChannelCreate(OpcUa_Channel* a_phChannel, OpcUa_Channel_SerializerType a_eSerializerType) =0;
		virtual OpcUa_Void CDECL IOpcUaChannelDelete(OpcUa_Channel* a_phChannel) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaChannelBeginConnect(OpcUa_Channel pChannel, OpcUa_StringA sUrl, OpcUa_ByteString* pClientCertificate, OpcUa_Key* pClientPrivateKey, OpcUa_ByteString* pServerCertificate, OpcUa_Void* pPKIConfig, OpcUa_String* pRequestedSecurityPolicyUri, OpcUa_Int32 nRequestedLifetime, OpcUa_MessageSecurityMode messageSecurityMode, OpcUa_UInt32 nNetworkTimeout, OpcUa_Channel_PfnConnectionStateChanged* pfCallback, OpcUa_Void* pCallbackData, OpcUa_SocketManager hSocketManager) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaChannelBeginDisconnect(OpcUa_Channel a_pChannel, OpcUa_Channel_PfnConnectionStateChanged* a_pfCallback, OpcUa_Void* a_pCallbackData) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaChannelBeginInvokeService(OpcUa_Channel a_hChannel, OpcUa_StringA a_sName, OpcUa_Void* a_pRequest, OpcUa_EncodeableType* a_pRequestType, OpcUa_Channel_PfnRequestComplete* a_pCallback, OpcUa_Void* a_pCallbackData) =0;
		virtual OpcUa_StatusCode CDECL IOpcUaDateTimeGetStringFromDateTime(const OpcUa_DateTime dateTime, OpcUa_StringA pBuffer, OpcUa_UInt32 uLength) =0;
};
	#ifndef ITF_CmpOPCUAStack
		#define ITF_CmpOPCUAStack static ICmpOPCUAStack *pICmpOPCUAStack = NULL;
	#endif
	#define EXTITF_CmpOPCUAStack
#else	/*CPLUSPLUS*/
	typedef ICmpOPCUAStack_C		ICmpOPCUAStack;
	#ifndef ITF_CmpOPCUAStack
		#define ITF_CmpOPCUAStack
	#endif
	#define EXTITF_CmpOPCUAStack
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_CMPOPCUASTACKITF_H_*/
