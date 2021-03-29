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

SET_INTERFACE_NAME(`CmpOPCUAStack')
REF_ITF(`CmpCryptoItf.m4')

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

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaByteStringInitialize',`(OpcUa_ByteString* value)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaByteStringClear',`(OpcUa_ByteString* value)')
DEF_ITF_API(`OpcUa_Int',`CDECL',`OpcUaByteStringCompare',`(const OpcUa_ByteString* value1, const OpcUa_ByteString* value2)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaByteStringCopyTo',`(const OpcUa_ByteString* source, OpcUa_ByteString* destination)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaByteStringConcatenate',`(const OpcUa_ByteString* source, OpcUa_ByteString* destination, OpcUa_Int len)')

DEF_ITF_API(`OpcUa_DateTime',`CDECL',`OpcUaDateTimeUtcNow',`(void)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaEncodeableObjectCreate',`(OpcUa_EncodeableType* pType, OpcUa_Void** ppEncodeable)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaEncodeableObjectDelete',`(OpcUa_EncodeableType* pType, OpcUa_Void** ppEncodeable)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaEncodeableObjectCreateExtension',`(OpcUa_EncodeableType* pType, OpcUa_ExtensionObject* pExtension, OpcUa_Void** ppEncodeableObject)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaLocalizedTextInitialize',`(OpcUa_LocalizedText* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaLocalizedTextClear',`(OpcUa_LocalizedText* pValue)')
DEF_ITF_API(`OpcUa_Int',`CDECL',`OpcUaLocalizedTextCompare',`(const OpcUa_LocalizedText* pValue1, const OpcUa_LocalizedText* pValue2)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaLocalizedTextCopyTo',`(const OpcUa_LocalizedText* pSource, OpcUa_LocalizedText* pDestination)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaNodeIdInitialize',`(OpcUa_NodeId* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaNodeIdClear',`(OpcUa_NodeId* pValue)')
DEF_ITF_API(`OpcUa_Int',`CDECL',`OpcUaNodeIdCompare',`(const OpcUa_NodeId* pValue1, const OpcUa_NodeId* pValue2)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaNodeIdCopyTo',`(const OpcUa_NodeId* pSource, OpcUa_NodeId* pDestination)')
DEF_ITF_API(`OpcUa_Boolean',`CDECL',`OpcUaNodeIdIsNull',`(OpcUa_NodeId* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaExpandedNodeIdInitialize',`(OpcUa_ExpandedNodeId* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaExpandedNodeIdClear',`(OpcUa_ExpandedNodeId* pValue)')
DEF_ITF_API(`OpcUa_Int',`CDECL',`OpcUaExpandedNodeIdCompare',`(const OpcUa_ExpandedNodeId* pValue1, const OpcUa_ExpandedNodeId* pValue2)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaExpandedNodeIdCopyTo',`(const OpcUa_ExpandedNodeId* pSource, OpcUa_ExpandedNodeId* pDestination)')
DEF_ITF_API(`OpcUa_Boolean',`CDECL',`OpcUaExpandedNodeIdIsNull',`(OpcUa_ExpandedNodeId* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaQualifiedNameInitialize',`(OpcUa_QualifiedName* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaQualifiedNameClear',`(OpcUa_QualifiedName* pValue)')
DEF_ITF_API(`OpcUa_Int',`CDECL',`OpcUaQualifiedNameCompare',`(const OpcUa_QualifiedName* pValue1, const OpcUa_QualifiedName* pValue2)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaQualifiedNameCopyTo',`(const OpcUa_QualifiedName* pSource, OpcUa_QualifiedName* pDestination)')

DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaStringAttachCopy',`(OpcUa_String* pDst, const OpcUa_CharA* pSrc)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaStringAttachReadOnly',`(OpcUa_String* a_pDst, const OpcUa_CharA* a_pSrc)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaStringAttachToString',`(OpcUa_StringA strSource, OpcUa_UInt32  uLength, OpcUa_UInt32  uBufferSize, OpcUa_Boolean bDoCopy, OpcUa_Boolean bFreeOnClear, OpcUa_String* pString)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaStringClear',`(OpcUa_String* pString)')
DEF_ITF_API(`OpcUa_CharA*',`CDECL',`OpcUaStringGetRawString',`(const OpcUa_String* pString)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaStringInitialize',`(OpcUa_String* pString)')
DEF_ITF_API(`OpcUa_Boolean',`CDECL',`OpcUaStringIsEmpty',`(const OpcUa_String* pString)')
DEF_ITF_API(`OpcUa_Boolean',`CDECL',`OpcUaStringIsNull',`(const OpcUa_String* pString)')
DEF_ITF_API(`OpcUa_UInt32',`CDECL',`OpcUaStringStrLen',`(const OpcUa_String* pString)')
DEF_ITF_API(`OpcUa_UInt32',`CDECL',`OpcUaStringStrSize',`(const OpcUa_String* pString)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaStringStrnCat',`(OpcUa_String* pDestString, const OpcUa_String* pSrcString, OpcUa_UInt32 uLength)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaStringStrnCpy',`(OpcUa_String* pDestString, const OpcUa_String* pSrcString, OpcUa_UInt32 uLength)')
DEF_ITF_API(`OpcUa_Int32',`CDECL',`OpcUaStringStrnCmp',`(const OpcUa_String* a_pLeftString, const OpcUa_String* a_pRightString,OpcUa_UInt32 a_uLength, OpcUa_Boolean a_bIgnoreCase)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaVariantInitialize',`(OpcUa_Variant* value)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaVariantClear',`(OpcUa_Variant* value)')
DEF_ITF_API(`OpcUa_Int',`CDECL',`OpcUaVariantCompare',`(const OpcUa_Variant* pValue1, const OpcUa_Variant* pValue2)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaVariantCopyTo',`(const OpcUa_Variant* pSource, OpcUa_Variant* pDestination)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaDataValueInitialize',`(OpcUa_DataValue* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaDataValueClear',`(OpcUa_DataValue* pValue)')
DEF_ITF_API(`OpcUa_Int',`CDECL',`OpcUaDataValueCompare',`(const OpcUa_DataValue* pValue1, const OpcUa_DataValue* pValue2)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaDataValueCopyTo',`(const OpcUa_DataValue* pSource, OpcUa_DataValue* pDestination)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaExtensionObjectCreate',`(OpcUa_ExtensionObject** ppValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaExtensionObjectInitialize',`(OpcUa_ExtensionObject* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaExtensionObjectClear',`(OpcUa_ExtensionObject* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaExtensionObjectDelete',`(OpcUa_ExtensionObject** ppValue)')
DEF_ITF_API(`OpcUa_Int',`CDECL',`OpcUaExtensionObjectCompare',`(const OpcUa_ExtensionObject* pValue1, const OpcUa_ExtensionObject* pValue2)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaExtensionObjectCopyTo',`(const OpcUa_ExtensionObject* pSource, OpcUa_ExtensionObject* pDestination)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaReadValueIdInitialize',`(OpcUa_ReadValueId* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaReadValueIdClear',`(OpcUa_ReadValueId* pValue)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaReadValueIdCopyTo',`(const OpcUa_ReadValueId* pSource, OpcUa_ReadValueId* pDestination)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaBrowseDescriptionInitialize',`(OpcUa_BrowseDescription* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaBrowseDescriptionClear',`(OpcUa_BrowseDescription* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaBrowsePathInitialize',`(OpcUa_BrowsePath* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaBrowsePathClear',`(OpcUa_BrowsePath* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaStatusChangeNotificationInitialize',`(OpcUa_StatusChangeNotification* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaStatusChangeNotificationClear',`(OpcUa_StatusChangeNotification* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaNotificationMessageInitialize',`(OpcUa_NotificationMessage* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaNotificationMessageClear',`(OpcUa_NotificationMessage* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaPublishResponseInitialize',`(OpcUa_PublishResponse* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaPublishResponseClear',`(OpcUa_PublishResponse* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaDataChangeNotificationInitialize',`(OpcUa_DataChangeNotification* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaDataChangeNotificationClear',`(OpcUa_DataChangeNotification* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaBrowseResultInitialize',`(OpcUa_BrowseResult* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaBrowseResultClear',`(OpcUa_BrowseResult* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaBrowsePathResultInitialize',`(OpcUa_BrowsePathResult* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaBrowsePathResultClear',`(OpcUa_BrowsePathResult* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaReferenceDescriptionInitialize',`(OpcUa_ReferenceDescription* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaReferenceDescriptionClear',`(OpcUa_ReferenceDescription* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaUserTokenPolicyInitialize',`(OpcUa_UserTokenPolicy* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaUserTokenPolicyClear',`(OpcUa_UserTokenPolicy* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaSignatureDataInitialize',`(OpcUa_SignatureData* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaSignatureDataClear',`(OpcUa_SignatureData* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaApplicationDescriptionInitialize',`(OpcUa_ApplicationDescription* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaApplicationDescriptionClear',`(OpcUa_ApplicationDescription* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaServerOnNetworkInitialize',`(OpcUa_ServerOnNetwork* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaServerOnNetworkClear',`(OpcUa_ServerOnNetwork* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaEventNotificationListInitialize',`(OpcUa_EventNotificationList* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaEventNotificationListClear',`(OpcUa_EventNotificationList* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaEventFieldListInitialize',`(OpcUa_EventFieldList* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaEventFieldListClear',`(OpcUa_EventFieldList* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaSimpleAttributeOperandInitialize',`(OpcUa_SimpleAttributeOperand* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaSimpleAttributeOperandClear',`(OpcUa_SimpleAttributeOperand* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaFindServersRequestInitialize',`(OpcUa_FindServersRequest* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaFindServersRequestClear',`(OpcUa_FindServersRequest* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaFindServersResponseInitialize',`(OpcUa_FindServersResponse* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaFindServersResponseClear',`(OpcUa_FindServersResponse* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaFindServersOnNetworkRequestInitialize',`(OpcUa_FindServersOnNetworkRequest* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaFindServersOnNetworkRequestClear',`(OpcUa_FindServersOnNetworkRequest* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaFindServersOnNetworkResponseInitialize',`(OpcUa_FindServersOnNetworkResponse* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaFindServersOnNetworkResponseClear',`(OpcUa_FindServersOnNetworkResponse* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaGetEndpointsRequestInitialize',`(OpcUa_GetEndpointsRequest* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaGetEndpointsRequestClear',`(OpcUa_GetEndpointsRequest* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaGetEndpointsResponseInitialize',`(OpcUa_GetEndpointsResponse* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaGetEndpointsResponseClear',`(OpcUa_GetEndpointsResponse* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaCreateSessionRequestInitialize',`(OpcUa_CreateSessionRequest* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaCreateSessionRequestClear',`(OpcUa_CreateSessionRequest* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaCreateSessionResponseInitialize',`(OpcUa_CreateSessionResponse* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaCreateSessionResponseClear',`(OpcUa_CreateSessionResponse* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaActivateSessionRequestInitialize',`(OpcUa_ActivateSessionRequest* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaActivateSessionRequestClear',`(OpcUa_ActivateSessionRequest* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaActivateSessionResponseInitialize',`(OpcUa_ActivateSessionResponse* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaActivateSessionResponseClear',`(OpcUa_ActivateSessionResponse* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaCloseSessionRequestInitialize',`(OpcUa_CloseSessionRequest* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaCloseSessionRequestClear',`(OpcUa_CloseSessionRequest* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaCloseSessionResponseInitialize',`(OpcUa_CloseSessionResponse* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaCloseSessionResponseClear',`(OpcUa_CloseSessionResponse* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaReadRequestInitialize',`(OpcUa_ReadRequest* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaReadRequestClear',`(OpcUa_ReadRequest* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaReadResponseInitialize',`(OpcUa_ReadResponse* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaReadResponseClear',`(OpcUa_ReadResponse* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaWriteRequestInitialize',`(OpcUa_WriteRequest* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaWriteRequestClear',`(OpcUa_WriteRequest* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaWriteResponseInitialize',`(OpcUa_WriteResponse* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaWriteResponseClear',`(OpcUa_WriteResponse* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaCreateSubscriptionRequestInitialize',`(OpcUa_CreateSubscriptionRequest* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaCreateSubscriptionRequestClear',`(OpcUa_CreateSubscriptionRequest* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaModifySubscriptionRequestInitialize',`(OpcUa_ModifySubscriptionRequest* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaModifySubscriptionRequestClear',`(OpcUa_ModifySubscriptionRequest* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaPublishRequestInitialize',`(OpcUa_PublishRequest* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaPublishRequestClear',`(OpcUa_PublishRequest* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaRepublishRequestInitialize',`(OpcUa_RepublishRequest* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaRepublishRequestClear',`(OpcUa_RepublishRequest* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaSetPublishingModeRequestInitialize',`(OpcUa_SetPublishingModeRequest* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaSetPublishingModeRequestClear',`(OpcUa_SetPublishingModeRequest* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaDeleteSubscriptionsRequestInitialize',`(OpcUa_DeleteSubscriptionsRequest* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaDeleteSubscriptionsRequestClear',`(OpcUa_DeleteSubscriptionsRequest* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaTransferSubscriptionsRequestInitialize',`(OpcUa_TransferSubscriptionsRequest* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaTransferSubscriptionsRequestClear',`(OpcUa_TransferSubscriptionsRequest* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaCreateSubscriptionResponseInitialize',`(OpcUa_CreateSubscriptionResponse* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaCreateSubscriptionResponseClear',`(OpcUa_CreateSubscriptionResponse* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaModifySubscriptionResponseInitialize',`(OpcUa_ModifySubscriptionResponse* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaModifySubscriptionResponseClear',`(OpcUa_ModifySubscriptionResponse* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaRepublishResponseInitialize',`(OpcUa_RepublishResponse* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaRepublishResponseClear',`(OpcUa_RepublishResponse* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaSetPublishingModeResponseInitialize',`(OpcUa_SetPublishingModeResponse* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaSetPublishingModeResponseClear',`(OpcUa_SetPublishingModeResponse* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaDeleteSubscriptionsResponseInitialize',`(OpcUa_DeleteSubscriptionsResponse* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaDeleteSubscriptionsResponseClear',`(OpcUa_DeleteSubscriptionsResponse* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaTransferSubscriptionsResponseInitialize',`(OpcUa_TransferSubscriptionsResponse* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaTransferSubscriptionsResponseClear',`(OpcUa_TransferSubscriptionsResponse* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaCreateMonitoredItemsRequestInitialize',`(OpcUa_CreateMonitoredItemsRequest* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaCreateMonitoredItemsRequestClear',`(OpcUa_CreateMonitoredItemsRequest* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaCreateMonitoredItemsResponseInitialize',`(OpcUa_CreateMonitoredItemsResponse* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaCreateMonitoredItemsResponseClear',`(OpcUa_CreateMonitoredItemsResponse* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaModifyMonitoredItemsRequestInitialize',`(OpcUa_ModifyMonitoredItemsRequest* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaModifyMonitoredItemsRequestClear',`(OpcUa_ModifyMonitoredItemsRequest* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaModifyMonitoredItemsResponseInitialize',`(OpcUa_ModifyMonitoredItemsResponse* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaModifyMonitoredItemsResponseClear',`(OpcUa_ModifyMonitoredItemsResponse* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaSetMonitoringModeRequestInitialize',`(OpcUa_SetMonitoringModeRequest* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaSetMonitoringModeRequestClear',`(OpcUa_SetMonitoringModeRequest* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaSetMonitoringModeResponseInitialize',`(OpcUa_SetMonitoringModeResponse* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaSetMonitoringModeResponseClear',`(OpcUa_SetMonitoringModeResponse* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaDeleteMonitoredItemsRequestInitialize',`(OpcUa_DeleteMonitoredItemsRequest* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaDeleteMonitoredItemsRequestClear',`(OpcUa_DeleteMonitoredItemsRequest* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaDeleteMonitoredItemsResponseInitialize',`(OpcUa_DeleteMonitoredItemsResponse* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaDeleteMonitoredItemsResponseClear',`(OpcUa_DeleteMonitoredItemsResponse* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaBrowseRequestInitialize',`(OpcUa_BrowseRequest* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaBrowseRequestClear',`(OpcUa_BrowseRequest* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaBrowseResponseInitialize',`(OpcUa_BrowseResponse* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaBrowseResponseClear',`(OpcUa_BrowseResponse* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaBrowseNextRequestInitialize',`(OpcUa_BrowseNextRequest* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaBrowseNextRequestClear',`(OpcUa_BrowseNextRequest* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaBrowseNextResponseInitialize',`(OpcUa_BrowseNextResponse* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaBrowseNextResponseClear',`(OpcUa_BrowseNextResponse* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaTranslateBrowsePathsToNodeIdsRequestInitialize',`(OpcUa_TranslateBrowsePathsToNodeIdsRequest* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaTranslateBrowsePathsToNodeIdsRequestClear',`(OpcUa_TranslateBrowsePathsToNodeIdsRequest* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaTranslateBrowsePathsToNodeIdsResponseInitialize',`(OpcUa_TranslateBrowsePathsToNodeIdsResponse* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaTranslateBrowsePathsToNodeIdsResponseClear',`(OpcUa_TranslateBrowsePathsToNodeIdsResponse* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaRegisterNodesRequestInitialize',`(OpcUa_RegisterNodesRequest* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaRegisterNodesRequestClear',`(OpcUa_RegisterNodesRequest* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaRegisterNodesResponseInitialize',`(OpcUa_RegisterNodesResponse* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaRegisterNodesResponseClear',`(OpcUa_RegisterNodesResponse* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaUnregisterNodesRequestInitialize',`(OpcUa_UnregisterNodesRequest* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaUnregisterNodesRequestClear',`(OpcUa_UnregisterNodesRequest* pValue)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaUnregisterNodesResponseInitialize',`(OpcUa_UnregisterNodesResponse* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaUnregisterNodesResponseClear',`(OpcUa_UnregisterNodesResponse* pValue)')

DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaListCreate',`(OpcUa_List** ppList)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaListInitialize',`(OpcUa_List* pList)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaListClear',`(OpcUa_List* pList)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaListDelete',`(OpcUa_List** ppList)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaListEnter',`(OpcUa_List* pList)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaListLeave',`(OpcUa_List* pList)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaListAddElement',`(OpcUa_List* pList, OpcUa_Void* pElementData)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaListAddElementToEnd',`(OpcUa_List* pList, OpcUa_Void* pElementData)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaListInsertElement',`(OpcUa_List* pList, OpcUa_Void* pElementData)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaListResetCurrent',`(OpcUa_List* pList)')
DEF_ITF_API(`OpcUa_Void*',`CDECL',`OpcUaListGetNextElement',`(OpcUa_List* pList)')
DEF_ITF_API(`OpcUa_Void*',`CDECL',`OpcUaListGetCurrentElement',`(OpcUa_List* pList)')
DEF_ITF_API(`OpcUa_Void*',`CDECL',`OpcUaListGetPrevElement',`(OpcUa_List* pList)')
DEF_ITF_API(`OpcUa_Void*',`CDECL',`OpcUaListGetElement',`(OpcUa_List* pList, OpcUa_Void* pElementData)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaListDeleteCurrentElement',`(OpcUa_List* pList)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaListDeleteElement',`(OpcUa_List* pList, OpcUa_Void* pElementData)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaListGetNumberOfElements',`(OpcUa_List* pList, OpcUa_UInt32* uintElementCount)')
DEF_ITF_API(`OpcUa_Void*',`CDECL',`OpcUaListRemoveFirstElement',`(OpcUa_List* pList)')

DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaEndpointDescriptionInitialize',`(OpcUa_EndpointDescription* pValue)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaEndpointDescriptionClear',`(OpcUa_EndpointDescription* pValue)')

DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaEndpointBeginSendResponse',`(OpcUa_Endpoint hEndpoint, OpcUa_Handle hContext, OpcUa_Void** ppResponse, OpcUa_EncodeableType** ppResponseType)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaEndpointCancelSendResponse',`(OpcUa_Endpoint hEndpoint, OpcUa_StatusCode uStatus, OpcUa_String* psReason, OpcUa_Handle* hContext)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaEndpointClose',`(OpcUa_Endpoint hEndpoint)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaEndpointCreate',`(OpcUa_Endpoint* phEndpoint, OpcUa_Endpoint_SerializerType eSerializerType, OpcUa_ServiceType** pSupportedServices)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaEndpointDelete',`(OpcUa_Endpoint* phEndpoint)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaEndpointEndSendResponse',`(OpcUa_Endpoint hEndpoint, OpcUa_Handle* hContext, OpcUa_StatusCode uStatusCode, OpcUa_Void* pResponse, OpcUa_EncodeableType* pResponseType)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaEndpointGetMessageSecureChannelId',`(OpcUa_Endpoint hEndpoint, OpcUa_Handle hContext, OpcUa_UInt32* pSecureChannelId)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaEndpointGetMessageSecureChannelSecurityPolicy',`(OpcUa_Endpoint hEndpoint, OpcUa_Handle hContext, OpcUa_Endpoint_SecurityPolicyConfiguration* pSecurityPolicy)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaEndpointOpen',`(OpcUa_Endpoint hEndpoint, OpcUa_StringA sUrl, OpcUa_StringA sTransportProfileUri, OpcUa_Endpoint_PfnEndpointCallback* pfEndpointCallback, OpcUa_Void* pvEndpointCallbackData, OpcUa_ByteString* pServerCertificate, OpcUa_Key* pServerPrivateKey, OpcUa_Void* pPKIConfig, OpcUa_UInt32 nNoOfSecurityPolicies, OpcUa_Endpoint_SecurityPolicyConfiguration* pSecurityPolicies, OpcUa_SocketManager hSocketManager)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaEndpointSendErrorResponse',`(OpcUa_Endpoint hEndpoint, OpcUa_Handle hContext, OpcUa_StatusCode uStatus)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaEndpointGetServiceFunction',`(OpcUa_Endpoint hEndpoint, OpcUa_Handle hContext, OpcUa_PfnInvokeService** ppInvoke)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaEndpointUpdateServiceFunctions',`(OpcUa_Endpoint hEndpoint, OpcUa_UInt32 uRequestTypeId, OpcUa_PfnBeginInvokeService* pBeginInvoke, OpcUa_PfnInvokeService* pInvoke)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaEndpointGetCallbackData',`(OpcUa_Endpoint hEndpoint, OpcUa_Void** ppvCallbackData)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaEndpointGetPeerInfoFromContext',`(OpcUa_Endpoint hEndpoint, OpcUa_Handle hContext, OpcUa_String* psPeerInfo)')

DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaTimerCreate',`(OpcUa_Timer* hTimer, OpcUa_UInt32 msecInterval, OpcUa_Timer_Callback* fpTimerCallback, OpcUa_Timer_Callback* fpKillCallback, OpcUa_Void* pvCallbackData)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaTimerDelete',`(OpcUa_Timer* phTimer)')

DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaSocketManagerLoop',`(OpcUa_SocketManager pSocketManager, OpcUa_UInt32 msecTimeout, OpcUa_Boolean bRunOnce)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaSocketManagerCreate',`(OpcUa_SocketManager* pSocketManager, OpcUa_UInt32 nSockets,	OpcUa_UInt32 nFlags)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaSocketManagerDelete',`(OpcUa_SocketManager* pSocketManager)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaServerApiCreateFault',`(OpcUa_RequestHeader* pRequestHeader, OpcUa_StatusCode uServiceResult, OpcUa_DiagnosticInfo* pServiceDiagnostics, OpcUa_Int32* pNoOfStringTable, OpcUa_String** ppStringTable, OpcUa_Void** ppFault, OpcUa_EncodeableType** ppFaultType)')

/**
 * <description>Get the adress of an encodable object type description. This adress can be passed directly to OpcUaEncodableObjectCreate or OpcUaEncodableObjectCreateExtension.
 * As ui32TypeId use the OpcUaId_... Macros. If the type is not available the function will return NULL.</description>
 */
DEF_ITF_API(`OpcUa_EncodeableType*',`CDECL',`OpcUaGetEncodableObjectType',`(OpcUa_UInt32 ui32TypeId)')
DEF_ITF_API(`OpcUa_PfnBeginInvokeService*',`CDECL',`OpcUaGetBeginServiceFunction',`(OpcUa_UInt32 ui32ServiceId)')

/* OPC UA Crypto interface */
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaStackConvertAsymmetricKey',`(RtsCryptoKey* rtsKey, OpcUa_Boolean bPrivateKey, OpcUa_Key* opcuaKey)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaSignatureInitialize',`(OpcUa_Signature* pSignature)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaSignatureClear',`(OpcUa_Signature* pSignature)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaKeyInitialize',`(OpcUa_Key* pKey)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaKeyClear',`(OpcUa_Key* pKey)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaCryptoGenerateKey',`(OpcUa_CryptoProvider* pProvider, OpcUa_Int32 keyLen, OpcUa_Key* pKey)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaCryptoDeriveKey',`(OpcUa_CryptoProvider* pProvider, OpcUa_ByteString secret, OpcUa_ByteString seed, OpcUa_Int32 keyLen, OpcUa_Key* pKey)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaCryptoAsymmetricSign',`(OpcUa_CryptoProvider* pProvider, OpcUa_ByteString data, OpcUa_Key* privateKey, OpcUa_ByteString* pSignature)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaCryptoAsymmetricVerify',`(OpcUa_CryptoProvider* pProvider, OpcUa_ByteString data, OpcUa_Key* publicKey, OpcUa_ByteString* pSignature)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaCryptoAsymmetricDecrypt',`(OpcUa_CryptoProvider* pProvider, OpcUa_Byte* pCipherText, OpcUa_UInt32 cipherTextLen, OpcUa_Key* privateKey, OpcUa_Byte* pPlainText, OpcUa_UInt32* pPlainTextLen)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaCryptoAsymmetricEncrypt',`(OpcUa_CryptoProvider* pProvider, OpcUa_Byte* pPlainText, OpcUa_UInt32 plainTextLen, OpcUa_Key* publicKey, OpcUa_Byte* pCipherText, OpcUa_UInt32* pCipherTextLen)')
DEF_ITF_API(`OpcUa_CharA*',`CDECL',`OpcUaCryptoGetSignatureAlgorithmUri',`(OpcUa_CryptoProvider* pProvider)')
DEF_ITF_API(`OpcUa_CharA*',`CDECL',`OpcUaCryptoGetAsymmetricEncryptionAlgorithmUri',`(OpcUa_CryptoProvider* pProvider)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaCryptoGetAsymmetricKeyLength',`(OpcUa_CryptoProvider* a_pProvider, OpcUa_Key a_publicKey, OpcUa_UInt32* a_pBits)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaCryptoProviderCreate',`(OpcUa_StringA a_psSecurityProfileUri, OpcUa_CryptoProvider* a_pProvider)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaCryptoProviderDelete',`(OpcUa_CryptoProvider* a_pProvider)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaStackGenerateApplicationSignature',`(const OpcUa_StringA pszSecurityPolicyUri, const OpcUa_ByteString *pPeerCert, const OpcUa_ByteString *pPeerNonce, const OpcUa_Key *pMyPrivateKey, OpcUa_SignatureData *pSignature)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaStackVerifyApplicationSignature',`(const OpcUa_StringA pszSecurityPolicyUri, const OpcUa_SignatureData *pSignature, const OpcUa_ByteString *pMyCert, const OpcUa_ByteString *pMyNonce, RTS_HANDLE hPeerCert)')

/* Client Interface */
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaChannelCreate',`(OpcUa_Channel* a_phChannel, OpcUa_Channel_SerializerType a_eSerializerType)')
DEF_ITF_API(`OpcUa_Void',`CDECL',`OpcUaChannelDelete',`(OpcUa_Channel* a_phChannel)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaChannelBeginConnect',`(OpcUa_Channel pChannel, OpcUa_StringA sUrl, OpcUa_ByteString* pClientCertificate, OpcUa_Key* pClientPrivateKey, OpcUa_ByteString* pServerCertificate, OpcUa_Void* pPKIConfig, OpcUa_String* pRequestedSecurityPolicyUri, OpcUa_Int32 nRequestedLifetime, OpcUa_MessageSecurityMode messageSecurityMode, OpcUa_UInt32 nNetworkTimeout, OpcUa_Channel_PfnConnectionStateChanged* pfCallback, OpcUa_Void* pCallbackData, OpcUa_SocketManager hSocketManager)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaChannelBeginDisconnect',`(OpcUa_Channel a_pChannel, OpcUa_Channel_PfnConnectionStateChanged* a_pfCallback, OpcUa_Void* a_pCallbackData)')
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaChannelBeginInvokeService',`(OpcUa_Channel a_hChannel, OpcUa_StringA a_sName, OpcUa_Void* a_pRequest, OpcUa_EncodeableType* a_pRequestType, OpcUa_Channel_PfnRequestComplete* a_pCallback, OpcUa_Void* a_pCallbackData)')

/* Helpers */
DEF_ITF_API(`OpcUa_StatusCode',`CDECL',`OpcUaDateTimeGetStringFromDateTime',`(const OpcUa_DateTime dateTime, OpcUa_StringA pBuffer, OpcUa_UInt32 uLength)')
