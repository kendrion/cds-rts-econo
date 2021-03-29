/**
 * <interfacename>CmpOPCUAStack_Implementation</interfacename>
 * <description></description>
 *
 * <copyright></copyright>
 */

SET_INTERFACE_NAME(`CmpOPCUAStack_Implementation')
SET_PLACEHOLDER_NAME(`CmpOPCUAStack Implementation')
REF_ITF(`CmpOPCUAStackItf.m4')

/** EXTERN LIB SECTION BEGIN **/
/*  Comments are ignored for m4 compiler so restructured text can be used. changecom(`/*', `*/') */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description>opcuaapplicationdescriptionclear</description>
 */
typedef struct tagopcuaapplicationdescriptionclear_struct
{
	OpcUa_ApplicationDescription *pValue;	/* VAR_INPUT */	
} opcuaapplicationdescriptionclear_struct;

DEF_API(`void',`CDECL',`opcuaapplicationdescriptionclear',`(opcuaapplicationdescriptionclear_struct *p)',1,0xD8FE8740,0x03051000)

/**
 * <description>opcuaapplicationdescriptioninitialize</description>
 */
typedef struct tagopcuaapplicationdescriptioninitialize_struct
{
	OpcUa_ApplicationDescription *pValue;	/* VAR_INPUT */	
} opcuaapplicationdescriptioninitialize_struct;

DEF_API(`void',`CDECL',`opcuaapplicationdescriptioninitialize',`(opcuaapplicationdescriptioninitialize_struct *p)',1,0x786640C1,0x03051000)

/**
 * <description>opcuabrowsepathclear</description>
 */
typedef struct tagopcuabrowsepathclear_struct
{
	OpcUa_BrowsePath *pValue;			/* VAR_INPUT */	
} opcuabrowsepathclear_struct;

DEF_API(`void',`CDECL',`opcuabrowsepathclear',`(opcuabrowsepathclear_struct *p)',1,0xBB891AEB,0x03051000)

/**
 * <description>opcuabrowsepathinitialize</description>
 */
typedef struct tagopcuabrowsepathinitialize_struct
{
	OpcUa_BrowsePath *pValue;			/* VAR_INPUT */	
} opcuabrowsepathinitialize_struct;

DEF_API(`void',`CDECL',`opcuabrowsepathinitialize',`(opcuabrowsepathinitialize_struct *p)',1,0x3938484A,0x03051000)

/**
 * <description>opcuabrowsepathresultclear</description>
 */
typedef struct tagopcuabrowsepathresultclear_struct
{
	OpcUa_BrowsePathResult *pValue;		/* VAR_INPUT */	
} opcuabrowsepathresultclear_struct;

DEF_API(`void',`CDECL',`opcuabrowsepathresultclear',`(opcuabrowsepathresultclear_struct *p)',1,0x8DA7753D,0x03051000)

/**
 * <description>opcuabrowsepathresultinitialize</description>
 */
typedef struct tagopcuabrowsepathresultinitialize_struct
{
	OpcUa_BrowsePathResult *pValue;		/* VAR_INPUT */	
} opcuabrowsepathresultinitialize_struct;

DEF_API(`void',`CDECL',`opcuabrowsepathresultinitialize',`(opcuabrowsepathresultinitialize_struct *p)',1,0xAF1770C6,0x03051000)

/**
 * <description>opcuabrowseresultclear</description>
 */
typedef struct tagopcuabrowseresultclear_struct
{
	OpcUa_BrowseResult *pValue;			/* VAR_INPUT */	
} opcuabrowseresultclear_struct;

DEF_API(`void',`CDECL',`opcuabrowseresultclear',`(opcuabrowseresultclear_struct *p)',1,0x6820FD5D,0x03051000)

/**
 * <description>opcuabrowseresultinitialize</description>
 */
typedef struct tagopcuabrowseresultinitialize_struct
{
	OpcUa_BrowseResult *pValue;			/* VAR_INPUT */	
} opcuabrowseresultinitialize_struct;

DEF_API(`void',`CDECL',`opcuabrowseresultinitialize',`(opcuabrowseresultinitialize_struct *p)',1,0x5DC17EFF,0x03051000)

/**
 * <description>opcuabytestringclear</description>
 */
typedef struct tagopcuabytestringclear_struct
{
	OpcUa_ByteString *value;			/* VAR_INPUT */	
} opcuabytestringclear_struct;

DEF_API(`void',`CDECL',`opcuabytestringclear',`(opcuabytestringclear_struct *p)',1,0x775210EC,0x03051000)

/**
 * <description>opcuabytestringcompare</description>
 */
typedef struct tagopcuabytestringcompare_struct
{
	OpcUa_ByteString *value1;			/* VAR_INPUT */	
	OpcUa_ByteString *value2;			/* VAR_INPUT */	
	RTS_IEC_DINT OpcUaByteStringCompare;	/* VAR_OUTPUT */	
} opcuabytestringcompare_struct;

DEF_API(`void',`CDECL',`opcuabytestringcompare',`(opcuabytestringcompare_struct *p)',1,0x7FCDF593,0x03051000)

/**
 * <description>opcuabytestringconcatenate</description>
 */
typedef struct tagopcuabytestringconcatenate_struct
{
	OpcUa_ByteString *source;			/* VAR_INPUT */	
	OpcUa_ByteString *destination;		/* VAR_INPUT */	
	RTS_IEC_DINT len;					/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaByteStringConcatenate;	/* VAR_OUTPUT */	
} opcuabytestringconcatenate_struct;

DEF_API(`void',`CDECL',`opcuabytestringconcatenate',`(opcuabytestringconcatenate_struct *p)',1,0x8D27CB64,0x03051000)

/**
 * <description>opcuabytestringcopyto</description>
 */
typedef struct tagopcuabytestringcopyto_struct
{
	OpcUa_ByteString *source;			/* VAR_INPUT */	
	OpcUa_ByteString *destination;		/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaByteStringCopyTo;	/* VAR_OUTPUT */	
} opcuabytestringcopyto_struct;

DEF_API(`void',`CDECL',`opcuabytestringcopyto',`(opcuabytestringcopyto_struct *p)',1,0x09BC6CF9,0x03051000)

/**
 * <description>opcuabytestringinitialize</description>
 */
typedef struct tagopcuabytestringinitialize_struct
{
	OpcUa_ByteString *value;			/* VAR_INPUT */	
} opcuabytestringinitialize_struct;

DEF_API(`void',`CDECL',`opcuabytestringinitialize',`(opcuabytestringinitialize_struct *p)',1,0xF04115F1,0x03051000)

/**
 * <description>opcuadatavalueclear</description>
 */
typedef struct tagopcuadatavalueclear_struct
{
	OpcUa_DataValue *pValue;			/* VAR_INPUT */	
} opcuadatavalueclear_struct;

DEF_API(`void',`CDECL',`opcuadatavalueclear',`(opcuadatavalueclear_struct *p)',1,0xBAC7D1A8,0x03051000)

/**
 * <description>opcuadatavaluecompare</description>
 */
typedef struct tagopcuadatavaluecompare_struct
{
	OpcUa_DataValue *pValue1;			/* VAR_INPUT */	
	OpcUa_DataValue *pValue2;			/* VAR_INPUT */	
	RTS_IEC_DINT OpcUaDataValueCompare;	/* VAR_OUTPUT */	
} opcuadatavaluecompare_struct;

DEF_API(`void',`CDECL',`opcuadatavaluecompare',`(opcuadatavaluecompare_struct *p)',1,0xF578EE57,0x03051000)

/**
 * <description>opcuadatavaluecopyto</description>
 */
typedef struct tagopcuadatavaluecopyto_struct
{
	OpcUa_DataValue *pSource;			/* VAR_INPUT */	
	OpcUa_DataValue *pDestination;		/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaDataValueCopyTo;	/* VAR_OUTPUT */	
} opcuadatavaluecopyto_struct;

DEF_API(`void',`CDECL',`opcuadatavaluecopyto',`(opcuadatavaluecopyto_struct *p)',1,0xEF1AC2F9,0x03051000)

/**
 * <description>opcuadatavalueinitialize</description>
 */
typedef struct tagopcuadatavalueinitialize_struct
{
	OpcUa_DataValue *pValue;			/* VAR_INPUT */	
} opcuadatavalueinitialize_struct;

DEF_API(`void',`CDECL',`opcuadatavalueinitialize',`(opcuadatavalueinitialize_struct *p)',1,0x67F48E71,0x03051000)

/**
 * <description>opcuadatetimeutcnow</description>
 */
typedef struct tagopcuadatetimeutcnow_struct
{
	RTS_IEC_LINT OpcUaDateTimeUtcNow;	/* VAR_OUTPUT */	
} opcuadatetimeutcnow_struct;

DEF_API(`void',`CDECL',`opcuadatetimeutcnow',`(opcuadatetimeutcnow_struct *p)',1,0x68CBAE05,0x03051000)

/**
 * <description>opcuaendpointdescriptionclear</description>
 */
typedef struct tagopcuaendpointdescriptionclear_struct
{
	OpcUa_EndpointDescription *pValue;	/* VAR_INPUT */	
} opcuaendpointdescriptionclear_struct;

DEF_API(`void',`CDECL',`opcuaendpointdescriptionclear',`(opcuaendpointdescriptionclear_struct *p)',1,0x7BC3E11A,0x03051000)

/**
 * <description>opcuaendpointdescriptioninitialize</description>
 */
typedef struct tagopcuaendpointdescriptioninitialize_struct
{
	OpcUa_EndpointDescription *pValue;	/* VAR_INPUT */	
} opcuaendpointdescriptioninitialize_struct;

DEF_API(`void',`CDECL',`opcuaendpointdescriptioninitialize',`(opcuaendpointdescriptioninitialize_struct *p)',1,0x02E855C1,0x03051000)

/**
 * <description>opcuaeventfieldlistclear</description>
 */
typedef struct tagopcuaeventfieldlistclear_struct
{
	OpcUa_EventFieldList *pValue;		/* VAR_INPUT */	
} opcuaeventfieldlistclear_struct;

DEF_API(`void',`CDECL',`opcuaeventfieldlistclear',`(opcuaeventfieldlistclear_struct *p)',1,0xEC6DF17F,0x03051000)

/**
 * <description>opcuaeventfieldlistinitialize</description>
 */
typedef struct tagopcuaeventfieldlistinitialize_struct
{
	OpcUa_EventFieldList *pValue;		/* VAR_INPUT */	
} opcuaeventfieldlistinitialize_struct;

DEF_API(`void',`CDECL',`opcuaeventfieldlistinitialize',`(opcuaeventfieldlistinitialize_struct *p)',1,0x55E16C82,0x03051000)

/**
 * <description>opcuaeventnotificationlistclear</description>
 */
typedef struct tagopcuaeventnotificationlistclear_struct
{
	OpcUa_EventNotificationList *pValue;	/* VAR_INPUT */	
} opcuaeventnotificationlistclear_struct;

DEF_API(`void',`CDECL',`opcuaeventnotificationlistclear',`(opcuaeventnotificationlistclear_struct *p)',1,0x11D76705,0x03051000)

/**
 * <description>opcuaeventnotificationlistinitialize</description>
 */
typedef struct tagopcuaeventnotificationlistinitialize_struct
{
	OpcUa_EventNotificationList *pValue;	/* VAR_INPUT */	
} opcuaeventnotificationlistinitialize_struct;

DEF_API(`void',`CDECL',`opcuaeventnotificationlistinitialize',`(opcuaeventnotificationlistinitialize_struct *p)',1,0xFD48AECC,0x03051000)

/**
 * <description>opcuaexpandednodeidclear</description>
 */
typedef struct tagopcuaexpandednodeidclear_struct
{
	OpcUa_ExpandedNodeId *pValue;		/* VAR_INPUT */	
} opcuaexpandednodeidclear_struct;

DEF_API(`void',`CDECL',`opcuaexpandednodeidclear',`(opcuaexpandednodeidclear_struct *p)',1,0xEC899BC1,0x03051000)

/**
 * <description>opcuaexpandednodeidcompare</description>
 */
typedef struct tagopcuaexpandednodeidcompare_struct
{
	OpcUa_ExpandedNodeId *pValue1;		/* VAR_INPUT */	
	OpcUa_ExpandedNodeId *pValue2;		/* VAR_INPUT */	
	RTS_IEC_DINT OpcUaExpandedNodeIdCompare;	/* VAR_OUTPUT */	
} opcuaexpandednodeidcompare_struct;

DEF_API(`void',`CDECL',`opcuaexpandednodeidcompare',`(opcuaexpandednodeidcompare_struct *p)',1,0xDECACF50,0x03051000)

/**
 * <description>opcuaexpandednodeidcopyto</description>
 */
typedef struct tagopcuaexpandednodeidcopyto_struct
{
	OpcUa_ExpandedNodeId *pSource;		/* VAR_INPUT */	
	OpcUa_ExpandedNodeId *pDestination;	/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaExpandedNodeIdCopyTo;	/* VAR_OUTPUT */	
} opcuaexpandednodeidcopyto_struct;

DEF_API(`void',`CDECL',`opcuaexpandednodeidcopyto',`(opcuaexpandednodeidcopyto_struct *p)',1,0x02B0E657,0x03051000)

/**
 * <description>opcuaexpandednodeidinitialize</description>
 */
typedef struct tagopcuaexpandednodeidinitialize_struct
{
	OpcUa_ExpandedNodeId *pValue;		/* VAR_INPUT */	
} opcuaexpandednodeidinitialize_struct;

DEF_API(`void',`CDECL',`opcuaexpandednodeidinitialize',`(opcuaexpandednodeidinitialize_struct *p)',1,0x171CB10B,0x03051000)

/**
 * <description>opcuaexpandednodeidisnull</description>
 */
typedef struct tagopcuaexpandednodeidisnull_struct
{
	OpcUa_ExpandedNodeId *pValue;		/* VAR_INPUT */	
	RTS_IEC_BYTE OpcUaExpandedNodeIdIsNull;	/* VAR_OUTPUT */	
} opcuaexpandednodeidisnull_struct;

DEF_API(`void',`CDECL',`opcuaexpandednodeidisnull',`(opcuaexpandednodeidisnull_struct *p)',1,0xF5A208FC,0x03051000)

/**
 * <description>opcuaextensionobjectclear</description>
 */
typedef struct tagopcuaextensionobjectclear_struct
{
	OpcUa_ExtensionObject *pValue;		/* VAR_INPUT */	
} opcuaextensionobjectclear_struct;

DEF_API(`void',`CDECL',`opcuaextensionobjectclear',`(opcuaextensionobjectclear_struct *p)',1,0xA67258F0,0x03051000)

/**
 * <description>opcuaextensionobjectcompare</description>
 */
typedef struct tagopcuaextensionobjectcompare_struct
{
	OpcUa_ExtensionObject *pValue1;		/* VAR_INPUT */	
	OpcUa_ExtensionObject *pValue2;		/* VAR_INPUT */	
	RTS_IEC_DINT OpcUaExtensionObjectCompare;	/* VAR_OUTPUT */	
} opcuaextensionobjectcompare_struct;

DEF_API(`void',`CDECL',`opcuaextensionobjectcompare',`(opcuaextensionobjectcompare_struct *p)',1,0xB81C626F,0x03051000)

/**
 * <description>opcuaextensionobjectcopyto</description>
 */
typedef struct tagopcuaextensionobjectcopyto_struct
{
	OpcUa_ExtensionObject *pSource;		/* VAR_INPUT */	
	OpcUa_ExtensionObject *pDestination;	/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaExtensionObjectCopyTo;	/* VAR_OUTPUT */	
} opcuaextensionobjectcopyto_struct;

DEF_API(`void',`CDECL',`opcuaextensionobjectcopyto',`(opcuaextensionobjectcopyto_struct *p)',1,0x9C91E51C,0x03051000)

/**
 * <description>opcuaextensionobjectcreate</description>
 */
typedef struct tagopcuaextensionobjectcreate_struct
{
	OpcUa_ExtensionObject **ppValue;	/* VAR_INPUT */	
} opcuaextensionobjectcreate_struct;

DEF_API(`void',`CDECL',`opcuaextensionobjectcreate',`(opcuaextensionobjectcreate_struct *p)',1,0xF0BFB81C,0x03051000)

/**
 * <description>opcuaextensionobjectdelete</description>
 */
typedef struct tagopcuaextensionobjectdelete_struct
{
	OpcUa_ExtensionObject **ppValue;	/* VAR_INPUT */	
} opcuaextensionobjectdelete_struct;

DEF_API(`void',`CDECL',`opcuaextensionobjectdelete',`(opcuaextensionobjectdelete_struct *p)',1,0x995BD981,0x03051000)

/**
 * <description>opcuaextensionobjectinitialize</description>
 */
typedef struct tagopcuaextensionobjectinitialize_struct
{
	OpcUa_ExtensionObject *pValue;		/* VAR_INPUT */	
} opcuaextensionobjectinitialize_struct;

DEF_API(`void',`CDECL',`opcuaextensionobjectinitialize',`(opcuaextensionobjectinitialize_struct *p)',1,0xDF8AB6E4,0x03051000)

/**
 * <description>opcualocalizedtextclear</description>
 */
typedef struct tagopcualocalizedtextclear_struct
{
	OpcUa_LocalizedText *pValue;		/* VAR_INPUT */	
} opcualocalizedtextclear_struct;

DEF_API(`void',`CDECL',`opcualocalizedtextclear',`(opcualocalizedtextclear_struct *p)',1,0xA85C9B89,0x03051000)

/**
 * <description>opcualocalizedtextcompare</description>
 */
typedef struct tagopcualocalizedtextcompare_struct
{
	OpcUa_LocalizedText *pValue1;		/* VAR_INPUT */	
	OpcUa_LocalizedText *pValue2;		/* VAR_INPUT */	
	RTS_IEC_DINT OpcUaLocalizedTextCompare;	/* VAR_OUTPUT */	
} opcualocalizedtextcompare_struct;

DEF_API(`void',`CDECL',`opcualocalizedtextcompare',`(opcualocalizedtextcompare_struct *p)',1,0x827CDA98,0x03051000)

/**
 * <description>opcualocalizedtextcopyto</description>
 */
typedef struct tagopcualocalizedtextcopyto_struct
{
	OpcUa_LocalizedText *pSource;		/* VAR_INPUT */	
	OpcUa_LocalizedText *pDestination;	/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaLocalizedTextCopyTo;	/* VAR_OUTPUT */	
} opcualocalizedtextcopyto_struct;

DEF_API(`void',`CDECL',`opcualocalizedtextcopyto',`(opcualocalizedtextcopyto_struct *p)',1,0x30D97055,0x03051000)

/**
 * <description>opcualocalizedtextinitialize</description>
 */
typedef struct tagopcualocalizedtextinitialize_struct
{
	OpcUa_LocalizedText *pValue;		/* VAR_INPUT */	
} opcualocalizedtextinitialize_struct;

DEF_API(`void',`CDECL',`opcualocalizedtextinitialize',`(opcualocalizedtextinitialize_struct *p)',1,0xC1C96077,0x03051000)

/**
 * <description>opcuanodeidclear</description>
 */
typedef struct tagopcuanodeidclear_struct
{
	OpcUa_NodeId *pValue;				/* VAR_INPUT */	
} opcuanodeidclear_struct;

DEF_API(`void',`CDECL',`opcuanodeidclear',`(opcuanodeidclear_struct *p)',1,0x025A3E11,0x03051000)

/**
 * <description>opcuanodeidcompare</description>
 */
typedef struct tagopcuanodeidcompare_struct
{
	OpcUa_NodeId *pValue1;				/* VAR_INPUT */	
	OpcUa_NodeId *pValue2;				/* VAR_INPUT */	
	RTS_IEC_DINT OpcUaNodeIdCompare;	/* VAR_OUTPUT */	
} opcuanodeidcompare_struct;

DEF_API(`void',`CDECL',`opcuanodeidcompare',`(opcuanodeidcompare_struct *p)',1,0x33441B4B,0x03051000)

/**
 * <description>opcuanodeidcopyto</description>
 */
typedef struct tagopcuanodeidcopyto_struct
{
	OpcUa_NodeId *pSource;				/* VAR_INPUT */	
	OpcUa_NodeId *pDestination;			/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaNodeIdCopyTo;	/* VAR_OUTPUT */	
} opcuanodeidcopyto_struct;

DEF_API(`void',`CDECL',`opcuanodeidcopyto',`(opcuanodeidcopyto_struct *p)',1,0xEC6C4C52,0x03051000)

/**
 * <description>opcuanodeidinitialize</description>
 */
typedef struct tagopcuanodeidinitialize_struct
{
	OpcUa_NodeId *pValue;				/* VAR_INPUT */	
} opcuanodeidinitialize_struct;

DEF_API(`void',`CDECL',`opcuanodeidinitialize',`(opcuanodeidinitialize_struct *p)',1,0x776DA0A9,0x03051000)

/**
 * <description>opcuanodeidisnull</description>
 */
typedef struct tagopcuanodeidisnull_struct
{
	OpcUa_NodeId *pValue;				/* VAR_INPUT */	
	RTS_IEC_BYTE OpcUaNodeIdIsNull;		/* VAR_OUTPUT */	
} opcuanodeidisnull_struct;

DEF_API(`void',`CDECL',`opcuanodeidisnull',`(opcuanodeidisnull_struct *p)',1,0x1519DE92,0x03051000)

/**
 * <description>opcuaqualifiednameclear</description>
 */
typedef struct tagopcuaqualifiednameclear_struct
{
	OpcUa_QualifiedName *pValue;		/* VAR_INPUT */	
} opcuaqualifiednameclear_struct;

DEF_API(`void',`CDECL',`opcuaqualifiednameclear',`(opcuaqualifiednameclear_struct *p)',1,0xAAADFAAB,0x03051000)

/**
 * <description>opcuaqualifiednamecompare</description>
 */
typedef struct tagopcuaqualifiednamecompare_struct
{
	OpcUa_QualifiedName *pValue1;		/* VAR_INPUT */	
	OpcUa_QualifiedName *pValue2;		/* VAR_INPUT */	
	RTS_IEC_DINT OpcUaQualifiedNameCompare;	/* VAR_OUTPUT */	
} opcuaqualifiednamecompare_struct;

DEF_API(`void',`CDECL',`opcuaqualifiednamecompare',`(opcuaqualifiednamecompare_struct *p)',1,0xAFF540F5,0x03051000)

/**
 * <description>opcuaqualifiednamecopyto</description>
 */
typedef struct tagopcuaqualifiednamecopyto_struct
{
	OpcUa_QualifiedName *pSource;		/* VAR_INPUT */	
	OpcUa_QualifiedName *pDestination;	/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaQualifiedNameCopyTo;	/* VAR_OUTPUT */	
} opcuaqualifiednamecopyto_struct;

DEF_API(`void',`CDECL',`opcuaqualifiednamecopyto',`(opcuaqualifiednamecopyto_struct *p)',1,0xFA67B572,0x03051000)

/**
 * <description>opcuaqualifiednameinitialize</description>
 */
typedef struct tagopcuaqualifiednameinitialize_struct
{
	OpcUa_QualifiedName *pValue;		/* VAR_INPUT */	
} opcuaqualifiednameinitialize_struct;

DEF_API(`void',`CDECL',`opcuaqualifiednameinitialize',`(opcuaqualifiednameinitialize_struct *p)',1,0x4DE39903,0x03051000)

/**
 * <description>opcuareadvalueidclear</description>
 */
typedef struct tagopcuareadvalueidclear_struct
{
	OpcUa_ReadValueId *pValue;			/* VAR_INPUT */	
} opcuareadvalueidclear_struct;

DEF_API(`void',`CDECL',`opcuareadvalueidclear',`(opcuareadvalueidclear_struct *p)',1,0x5E9470F8,0x03051000)

/**
 * <description>opcuareadvalueidinitialize</description>
 */
typedef struct tagopcuareadvalueidinitialize_struct
{
	OpcUa_ReadValueId *pValue;			/* VAR_INPUT */	
} opcuareadvalueidinitialize_struct;

DEF_API(`void',`CDECL',`opcuareadvalueidinitialize',`(opcuareadvalueidinitialize_struct *p)',1,0x35E54342,0x03051000)

/**
 * <description>opcuareferencedescriptionclear</description>
 */
typedef struct tagopcuareferencedescriptionclear_struct
{
	OpcUa_ReferenceDescription *pValue;	/* VAR_INPUT */	
} opcuareferencedescriptionclear_struct;

DEF_API(`void',`CDECL',`opcuareferencedescriptionclear',`(opcuareferencedescriptionclear_struct *p)',1,0xAEB1E23C,0x03051000)

/**
 * <description>opcuareferencedescriptioninitialize</description>
 */
typedef struct tagopcuareferencedescriptioninitialize_struct
{
	OpcUa_ReferenceDescription *pValue;	/* VAR_INPUT */	
} opcuareferencedescriptioninitialize_struct;

DEF_API(`void',`CDECL',`opcuareferencedescriptioninitialize',`(opcuareferencedescriptioninitialize_struct *p)',1,0xD23622BE,0x03051000)

/**
 * <description>opcuaserveronnetworkclear</description>
 */
typedef struct tagopcuaserveronnetworkclear_struct
{
	OpcUa_ServerOnNetwork *pValue;		/* VAR_INPUT */	
} opcuaserveronnetworkclear_struct;

DEF_API(`void',`CDECL',`opcuaserveronnetworkclear',`(opcuaserveronnetworkclear_struct *p)',1,0xC1857568,0x03051000)

/**
 * <description>opcuaserveronnetworkinitialize</description>
 */
typedef struct tagopcuaserveronnetworkinitialize_struct
{
	OpcUa_ServerOnNetwork *pValue;		/* VAR_INPUT */	
} opcuaserveronnetworkinitialize_struct;

DEF_API(`void',`CDECL',`opcuaserveronnetworkinitialize',`(opcuaserveronnetworkinitialize_struct *p)',1,0x75110575,0x03051000)

/**
 * <description>opcuasimpleattributeoperandclear</description>
 */
typedef struct tagopcuasimpleattributeoperandclear_struct
{
	OpcUa_SimpleAttributeOperand *pValue;	/* VAR_INPUT */	
} opcuasimpleattributeoperandclear_struct;

DEF_API(`void',`CDECL',`opcuasimpleattributeoperandclear',`(opcuasimpleattributeoperandclear_struct *p)',1,0xED624E6B,0x03051000)

/**
 * <description>opcuasimpleattributeoperandinitialize</description>
 */
typedef struct tagopcuasimpleattributeoperandinitialize_struct
{
	OpcUa_SimpleAttributeOperand *pValue;	/* VAR_INPUT */	
} opcuasimpleattributeoperandinitialize_struct;

DEF_API(`void',`CDECL',`opcuasimpleattributeoperandinitialize',`(opcuasimpleattributeoperandinitialize_struct *p)',1,0x81CA1989,0x03051000)

/**
 * <description>opcuastatuschangenotificationclear</description>
 */
typedef struct tagopcuastatuschangenotificationclear_struct
{
	OpcUa_StatusChangeNotification *pValue;	/* VAR_INPUT */	
} opcuastatuschangenotificationclear_struct;

DEF_API(`void',`CDECL',`opcuastatuschangenotificationclear',`(opcuastatuschangenotificationclear_struct *p)',1,0xE76BFA42,0x03051000)

/**
 * <description>opcuastatuschangenotificationinitialize</description>
 */
typedef struct tagopcuastatuschangenotificationinitialize_struct
{
	OpcUa_StatusChangeNotification *pValue;	/* VAR_INPUT */	
} opcuastatuschangenotificationinitialize_struct;

DEF_API(`void',`CDECL',`opcuastatuschangenotificationinitialize',`(opcuastatuschangenotificationinitialize_struct *p)',1,0x32A3D102,0x03051000)

/**
 * <description>opcuastringattachcopy</description>
 */
typedef struct tagopcuastringattachcopy_struct
{
	OpcUa_String *pDst;					/* VAR_INPUT */	
	RTS_IEC_SINT *pSrc;					/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaStringAttachCopy;	/* VAR_OUTPUT */	
} opcuastringattachcopy_struct;

DEF_API(`void',`CDECL',`opcuastringattachcopy',`(opcuastringattachcopy_struct *p)',1,0x309DD3C4,0x03051000)

/**
 * <description>opcuastringattachreadonly</description>
 */
typedef struct tagopcuastringattachreadonly_struct
{
	OpcUa_String *pDst;					/* VAR_INPUT */	
	RTS_IEC_SINT *pSrc;					/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaStringAttachReadOnly;	/* VAR_OUTPUT */	
} opcuastringattachreadonly_struct;

DEF_API(`void',`CDECL',`opcuastringattachreadonly',`(opcuastringattachreadonly_struct *p)',1,0x108C50FB,0x03051000)

/**
 * <description>opcuastringattachtostring</description>
 */
typedef struct tagopcuastringattachtostring_struct
{
	RTS_IEC_BYTE *strSource;			/* VAR_INPUT */	
	RTS_IEC_UDINT uLength;				/* VAR_INPUT */	
	RTS_IEC_UDINT uBufferSize;			/* VAR_INPUT */	
	RTS_IEC_BYTE bDoCopy;				/* VAR_INPUT */	
	RTS_IEC_BYTE bFreeOnClear;			/* VAR_INPUT */	
	OpcUa_String *pString;				/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaStringAttachToString;	/* VAR_OUTPUT */	
} opcuastringattachtostring_struct;

DEF_API(`void',`CDECL',`opcuastringattachtostring',`(opcuastringattachtostring_struct *p)',1,0xB95D79B1,0x03051000)

/**
 * <description>opcuastringclear</description>
 */
typedef struct tagopcuastringclear_struct
{
	OpcUa_String *pString;				/* VAR_INPUT */	
} opcuastringclear_struct;

DEF_API(`void',`CDECL',`opcuastringclear',`(opcuastringclear_struct *p)',1,0xB79012EE,0x03051000)

/**
 * <description>opcuastringgetrawstring</description>
 */
typedef struct tagopcuastringgetrawstring_struct
{
	OpcUa_String *pString;				/* VAR_INPUT */	
	RTS_IEC_SINT *OpcUaStringGetRawString;	/* VAR_OUTPUT */	
} opcuastringgetrawstring_struct;

DEF_API(`void',`CDECL',`opcuastringgetrawstring',`(opcuastringgetrawstring_struct *p)',1,0x34BB5D5D,0x03051000)

/**
 * <description>opcuastringinitialize</description>
 */
typedef struct tagopcuastringinitialize_struct
{
	OpcUa_String *pString;				/* VAR_INPUT */	
} opcuastringinitialize_struct;

DEF_API(`void',`CDECL',`opcuastringinitialize',`(opcuastringinitialize_struct *p)',1,0xA2ED3883,0x03051000)

/**
 * <description>opcuastringisempty</description>
 */
typedef struct tagopcuastringisempty_struct
{
	OpcUa_String *pString;				/* VAR_INPUT */	
	RTS_IEC_BYTE OpcUaStringIsEmpty;	/* VAR_OUTPUT */	
} opcuastringisempty_struct;

DEF_API(`void',`CDECL',`opcuastringisempty',`(opcuastringisempty_struct *p)',1,0xE17DA026,0x03051000)

/**
 * <description>opcuastringisnull</description>
 */
typedef struct tagopcuastringisnull_struct
{
	OpcUa_String *pString;				/* VAR_INPUT */	
	RTS_IEC_BYTE OpcUaStringIsNull;		/* VAR_OUTPUT */	
} opcuastringisnull_struct;

DEF_API(`void',`CDECL',`opcuastringisnull',`(opcuastringisnull_struct *p)',1,0x9C5B676C,0x03051000)

/**
 * <description>opcuastringstrlen</description>
 */
typedef struct tagopcuastringstrlen_struct
{
	OpcUa_String *pString;				/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaStringStrLen;	/* VAR_OUTPUT */	
} opcuastringstrlen_struct;

DEF_API(`void',`CDECL',`opcuastringstrlen',`(opcuastringstrlen_struct *p)',1,0xE08C44DF,0x03051000)

/**
 * <description>opcuastringstrncat</description>
 */
typedef struct tagopcuastringstrncat_struct
{
	OpcUa_String *pDestString;			/* VAR_INPUT */	
	OpcUa_String *pSrcString;			/* VAR_INPUT */	
	RTS_IEC_UDINT uLength;				/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaStringStrnCat;	/* VAR_OUTPUT */	
} opcuastringstrncat_struct;

DEF_API(`void',`CDECL',`opcuastringstrncat',`(opcuastringstrncat_struct *p)',1,0x5F9D7E9F,0x03051000)

/**
 * <description>opcuastringstrncmp</description>
 */
typedef struct tagopcuastringstrncmp_struct
{
	OpcUa_String *pLeftString;			/* VAR_INPUT */	
	OpcUa_String *pRightString;			/* VAR_INPUT */	
	RTS_IEC_UDINT uLength;				/* VAR_INPUT */	
	RTS_IEC_BYTE bIgnoreCase;			/* VAR_INPUT */	
	RTS_IEC_DINT OpcUaStringStrnCmp;	/* VAR_OUTPUT */	
} opcuastringstrncmp_struct;

DEF_API(`void',`CDECL',`opcuastringstrncmp',`(opcuastringstrncmp_struct *p)',1,0x53DB5D7B,0x03051000)

/**
 * <description>opcuastringstrncpy</description>
 */
typedef struct tagopcuastringstrncpy_struct
{
	OpcUa_String *pDestString;			/* VAR_INPUT */	
	OpcUa_String *pSrcString;			/* VAR_INPUT */	
	RTS_IEC_UDINT uLength;				/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaStringStrnCpy;	/* VAR_OUTPUT */	
} opcuastringstrncpy_struct;

DEF_API(`void',`CDECL',`opcuastringstrncpy',`(opcuastringstrncpy_struct *p)',1,0x35071283,0x03051000)

/**
 * <description>opcuastringstrsize</description>
 */
typedef struct tagopcuastringstrsize_struct
{
	OpcUa_String *pString;				/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaStringStrSize;	/* VAR_OUTPUT */	
} opcuastringstrsize_struct;

DEF_API(`void',`CDECL',`opcuastringstrsize',`(opcuastringstrsize_struct *p)',1,0xF9B1AC55,0x03051000)

/**
 * <description>opcuavariantclear</description>
 */
typedef struct tagopcuavariantclear_struct
{
	OpcUa_Variant *value;				/* VAR_INPUT */	
} opcuavariantclear_struct;

DEF_API(`void',`CDECL',`opcuavariantclear',`(opcuavariantclear_struct *p)',1,0xF92D0208,0x03051000)

/**
 * <description>opcuavariantcompare</description>
 */
typedef struct tagopcuavariantcompare_struct
{
	OpcUa_Variant *pValue1;				/* VAR_INPUT */	
	OpcUa_Variant *pValue2;				/* VAR_INPUT */	
	RTS_IEC_DINT OpcUaVariantCompare;	/* VAR_OUTPUT */	
} opcuavariantcompare_struct;

DEF_API(`void',`CDECL',`opcuavariantcompare',`(opcuavariantcompare_struct *p)',1,0xDE73CC0D,0x03051000)

/**
 * <description>opcuavariantcopyto</description>
 */
typedef struct tagopcuavariantcopyto_struct
{
	OpcUa_Variant *pSource;				/* VAR_INPUT */	
	OpcUa_Variant *pDestination;		/* VAR_INPUT */	
	RTS_IEC_UDINT OpcUaVariantCopyTo;	/* VAR_OUTPUT */	
} opcuavariantcopyto_struct;

DEF_API(`void',`CDECL',`opcuavariantcopyto',`(opcuavariantcopyto_struct *p)',1,0x06DA6455,0x03051000)

/**
 * <description>opcuavariantinitialize</description>
 */
typedef struct tagopcuavariantinitialize_struct
{
	OpcUa_Variant *value;				/* VAR_INPUT */	
} opcuavariantinitialize_struct;

DEF_API(`void',`CDECL',`opcuavariantinitialize',`(opcuavariantinitialize_struct *p)',1,0xEA98C1BA,0x03051000)

#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/

