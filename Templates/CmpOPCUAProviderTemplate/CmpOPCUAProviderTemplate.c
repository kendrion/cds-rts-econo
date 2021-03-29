/*****************************************************************************
*
*	Copyright:		© 3S - Smart Software Solutions GmbH, Kempten
*	Program:		Runtime System for the CoDeSys Soft-Plc
*	Module: 		
*	Version:
*	Description:
******************************************************************************/

#ifndef STATICITF_DEF
#define STATICITF_DEF	static
#endif

#include "CmpTemplateIDs.h"
#include "CmpStd.h"
#include "CmpOpcUaProviderTemplateDep.h"

#define CLASSID_CCmpOpcUaProviderTemplate		ADDVENDORID(CMP_VENDORID, 1234)

typedef struct
{
	RTS_UI32 valueA;
	RTS_UI32 valueB;
	RTS_UI32 valueC;
	RTS_UI64 valueD;
	RTS_REAL32 valueE;
}MyComplexStruct;
static OpcUa_String sMyCompleyStruct = OPCUA_STRING_STATICINITIALIZEWITH("MyComplexStruct", sizeof("MyComplexStruct"));

char szTypeDict[] = "<opc:TypeDictionary xmlns:xsi='http://www.w3.org/2001/XMLSchema-instance' xmlns:tns='MyNewProvider' DefaultByteOrder='LittleEndian' xmlns:opc='http://opcfoundation.org/BinarySchema/' xmlns:ua='http://opcfoundation.org/UA/' TargetNamespace='MyNewProvider'><opc:Import Namespace='http://opcfoundation.org/UA/'/><opc:StructuredType opc:BaseType='ua:ExtensionObject' opc:Name='MyComplexStruct'><opc:Field opc:TypeName='opc:UInt32' opc:Name='valueA'/><opc:Field opc:TypeName='opc:UInt32' opc:Name='valueB'/><opc:Field opc:TypeName='opc:UInt32' opc:Name='valueC'/><opc:Field opc:TypeName='opc:UInt64' opc:Name='valueD'/><opc:Field opc:TypeName='opc:Float' opc:Name='valueE'/></opc:StructuredType></opc:TypeDictionary>";

/* Variables */
#define ProviderID_ValueA 0
#define ProviderID_ValueB 1
#define ProviderID_ValueMyComplexStruct 2

/* Objects */
#define ProviderID_MyFolder 1001

/* Methods */
#define ProviderID_MyFunction 2000
#define ProivderID_MyFunction_InputArguments 2001
#define ProivderID_MyFunction_OutputArguments 2002


#define ProviderID_DataTypeDictionary 10001
#define ProviderID_DataTypeDictionary_NamespaceURI 10002
#define ProviderID_DataTypeDescription_MyComplexStruct 10501
#define ProviderID_DataType_MyComplexStruct 10601
#define ProviderID_DataType_MyComplexStruct_Encoding 10701

USE_STMT

static OpcUa_Int16 s_NamespaceIndex;
static OpcUa_String s_Namespace = OPCUA_STRING_STATICINITIALIZEWITH("MyNewProvider", sizeof("MyNewProvider"));
static OpcUa_String s_ApplicationLocal = OPCUA_STRING_STATICINITIALIZEWITH("en - Us", sizeof("en-Us"));
static RTS_HANDLE s_hEventNotifier = RTS_INVALID_HANDLE;
static RTS_HANDLE s_hEvent = RTS_INVALID_HANDLE;

/* Values to sample */
OpcUa_UInt32 values[2];
static OpcUa_UInt32* valueA = &values[0];
static OpcUa_UInt32* valueB = &values[1];
static MyComplexStruct valueMyComplexStruct = { 0, 0x84746B8E, 0xC6AEA155, RTS_UI64_CONST(0x3DADD6ACAF11C71C), 5.0};

typedef struct
{
	OpcUa_TimestampsToReturn eTimestamps;
	OpcUa_UInt32 id;
}SamplingInfo;


static OpcUa_Boolean BrowseContextCheckAddNodes(OpcUaProvider_BrowseContext *pContext, OpcUa_UInt32 ui32NumToAdd);
static OpcUa_Boolean BrowseContextCheckNodes(OpcUaProvider_BrowseContext* pContext, OpcUa_UInt32 ui32NumOfNodes);
static OpcUa_Void BrowseContextSetUnfinishedFlag(OpcUaProvider_BrowseContext* pContext);
static OpcUa_ReferenceDescription* BrowseContextGetNextRefDesc(OpcUaProvider_BrowseContext* pContext);

#ifdef CPLUSPLUS
	static CCmpOpcUaProviderTemplate *s_pCCmpOpcUaProviderTemplate;
#endif

typedef struct
{
#ifndef CPLUSPLUS
	IBase_C base;
	ICmpOPCUAProvider_C provider;
#endif
	IBase *pIBase;
	ICmpOPCUAProvider *pIOpcUaProvider;

} OpcUaProvider_C;

static OpcUaProvider_C s_OpcUaProviderInterface;

static OpcUaProvider_Info s_OpcUaProviderInfo = {
	sizeof(s_OpcUaProviderInfo),
	sizeof(ICmpOPCUAProvider_C),
	CMP_VERSION, /* Provider version*/
	OPCUA_STRING_STATICINITIALIZEWITH(COMPONENT_NAME, sizeof(COMPONENT_NAME)),
	RTS_INVALID_HANDLE,
	COMPONENT_ID
};


DLL_DECL int CDECL ComponentEntry(INIT_STRUCT *pInitStruct)
/*	Used to exchange function pointers between component manager and components.
	Called at startup for each component.
	pInitStruct:			IN	Pointer to structure with:
		pfExportFunctions	OUT Pointer to function that exports component functions
		pfImportFunctions	OUT Pointer to function that imports functions from other components
		pfGetVersion		OUT Pointer to function to get component version
		pfRegisterAPI		IN	Pointer to component manager function to register a API function
		pfGetAPI			IN	Pointer to component manager function to get a API function
		pfCallHook			IN	Pointer to component manager function to call a hook function
	Return					ERR_OK if library could be initialized, else error code
*/
{
	pInitStruct->CmpId = COMPONENT_ID;
	pInitStruct->pfExportFunctions = ExportFunctions;
	pInitStruct->pfImportFunctions = ImportFunctions;
	pInitStruct->pfGetVersion = CmpGetVersion;
	pInitStruct->pfHookFunction = HookFunction;
	pInitStruct->pfCreateInstance = CreateInstance;
	pInitStruct->pfDeleteInstance = DeleteInstance;

	s_pfCMRegisterAPI = pInitStruct->pfCMRegisterAPI;
	s_pfCMRegisterAPI2 = pInitStruct->pfCMRegisterAPI2;
	s_pfCMGetAPI = pInitStruct->pfCMGetAPI;
	s_pfCMGetAPI2 = pInitStruct->pfCMGetAPI2;
	s_pfCMCallHook = pInitStruct->pfCMCallHook;
	s_pfCMRegisterClass = pInitStruct->pfCMRegisterClass;
	s_pfCMCreateInstance = pInitStruct->pfCMCreateInstance;

#ifdef CPLUSPLUS
	INIT_LOCALS_STMT;
#endif
	if (pInitStruct->pfCMRegisterClass != NULL)
		pInitStruct->pfCMRegisterClass(COMPONENT_ID, CLASSID_CCmpOpcUaProviderTemplate);

	return ERR_OK;
}


#ifndef CPLUSPLUS

DECLARE_ADDREF
DECLARE_RELEASE
DECLARE_QUERYINTERFACE

#endif

static IBase* CDECL CreateInstance(CLASSID cid, RTS_RESULT *pResult)
{
#ifdef CPLUSPLUS
	if (cid == CLASSID_CCmpOpcUaProviderTemplate)
	{
		CCmpOpcUaProviderTemplate *pCCmpOpcUaProviderTemplate = static_cast<CCmpOpcUaProviderTemplate *>(new CCmpOpcUaProviderTemplate());
		IBase *pIBase = (IBase *)pCCmpOpcUaProviderTemplate->QueryInterface(pCCmpOpcUaProviderTemplate, ITFID_IBase, pResult);
		RTS_SETRESULT(pResult, ERR_OK);
		return pIBase;
	}
#else
	if (cid == CLASSID_CCmpOpcUaProviderTemplate)
	{
		IBase *pI = &s_OpcUaProviderInterface.base;
		
		memset(&s_OpcUaProviderInterface, 0, sizeof(s_OpcUaProviderInterface));
		s_OpcUaProviderInterface.pIBase = pI;
		pI->bIEC = 0;
		pI->AddRef = AddRef;
		pI->Release = Release;
		pI->QueryInterface = QueryInterface;
		pI->iRefCount++;
		RTS_SETRESULT(pResult, ERR_OK);
		return pI;
	}
#endif
	RTS_SETRESULT(pResult, ERR_FAILED);
	return NULL;
}

static RTS_RESULT CDECL DeleteInstance(IBase *pIBase)
{
#ifdef CPLUSPLUS
	pIBase->Release();
	return ERR_OK;
#else
	pIBase->iRefCount--;
	if (pIBase->iRefCount == 0)
		memset(&s_OpcUaProviderInterface, 0, sizeof(s_OpcUaProviderInterface));
	return ERR_OK;
#endif
}

#if !defined(CPLUSPLUS)
IMPLEMENT_ADDREF
IMPLEMENT_RELEASE

static void *CDECL QueryInterface(IBase *pBase, ITFID iid, RTS_RESULT *pResult)
{
	if (iid == ITFID_IBase)
	{
		/* Every interface has as first element a pointer to the IBase interface. So it doesn't matter, which interface
		is used to get the IBase pointer */
		OpcUaProvider_C *pC = (OpcUaProvider_C *)pBase;
		pC->pIBase->iRefCount++;
		RTS_SETRESULT(pResult, ERR_OK);
		return pC->pIBase;
	}
	if (iid == ITFID_ICmpOPCUAProvider)
	{
		OpcUaProvider_C *pC = (OpcUaProvider_C *)pBase;
		pC->provider.pBase = pBase;
		
		pC->provider.IOpcUaProviderCreate = OpcUaProviderCreate;
		pC->provider.IOpcUaProviderDelete = OpcUaProviderDelete;
		pC->provider.IOpcUaProviderBrowse = OpcUaProviderBrowse;
		pC->provider.IOpcUaProviderCreateMonitoredItem = OpcUaProviderCreateMonitoredItem;
		pC->provider.IOpcUaProviderDeleteMonitoredItem = OpcUaProviderDeleteMonitoredItem;
		pC->provider.IOpcUaProviderSampleMonitoredItem = OpcUaProviderSampleMonitoredItem;
		pC->provider.IOpcUaProviderInitialize = OpcUaProviderInitialize;
		pC->provider.IOpcUaProviderCleanup = OpcUaProviderCleanup;
		pC->provider.IOpcUaProviderRead = OpcUaProviderRead;
		pC->provider.IOpcUaProviderWrite = OpcUaProviderWrite;
		//pC->provider.IOpcUaProviderMethodCall = OpcUaProviderMethodCall;

		pC->pIOpcUaProvider = &pC->provider;
		pC->base.iRefCount++;
		RTS_SETRESULT(pResult, ERR_OK);
		return &pC->provider;
	}
	RTS_SETRESULT(pResult, ERR_FAILED);
	return NULL;
}
#endif


static int CDECL ExportFunctions(void)
/*	Export function pointers as api */
{
	/* Macro to export functions */
	EXPORT_STMT;
	return ERR_OK;
}

static int CDECL ImportFunctions(void)
/*	Get function pointers of other components */
{
	/* Macro to import functions */
	IMPORT_STMT;
	return ERR_OK;
}

static RTS_UI32 CDECL CmpGetVersion(void)
{
	return CMP_VERSION;
}

static RTS_RESULT CDECL HookFunction(RTS_UI32 ulHook, RTS_UINTPTR ulParam1, RTS_UINTPTR ulParam2)
{
	RTS_RESULT result = ERR_OK;

	switch (ulHook)
	{
		case CH_INIT_COMM:
		{
			/* Register Provider at the OPC UA server */
			IBase *pIBase = NULL;

			CAL_OpcUaProviderCreate(pIBase, CLASSID_CCmpOpcUaProviderTemplate, 0, &result);
			s_OpcUaProviderInfo.hProvider = pIBase->QueryInterface(pIBase, ITFID_ICmpOPCUAProvider, &result);

			result = CAL_OpcUaServerRegisterProvider(&s_OpcUaProviderInfo);
			if (result != ERR_OK)
			{
				CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_ERROR, result, 0, "The registration of the OPC UA Template provider failed!");
			}
			break;
		}
		case CH_COMM_CYCLE:
		{
			(*valueB)++;
			if ((*valueB % 100) == 0)
			{
				OpcUa_Variant evt_values[6];
				OpcUa_ByteString EventId;
				OpcUa_NodeId SourceNode;
				OpcUa_LocalizedText Message;
				OpcUa_String SourceName;
				OpcUa_DateTime Time = CAL_OpcUaDateTimeUtcNow();
				OpcUa_UInt16 Severity = (*valueB % 1000 ) + 1; /* Apply severity range between 1 and 1000 */

				/*
				 *  1. EventId: Unique Id of the event : Datatype : OpcUa_ByteString
				 *  2. SourceNode : NodeId of the event source node.Datatype : OpcUa_NodeId
				 *  3. SourceName : Name of the event source.Datatype : OpcUa_String
				 *  4. Time : UtcTimestamp when the event occured.Datatype : OpcUa_UtcTime
				 *  5. Message : Message of the event.Datatype : OpcUa_LocalizedText
				 *  6. Severity : Severity of the event.Datatype : OpcUa_UInt16.Range from 1 to 1000 is allowed< / param>
				 */
				memset(evt_values, 0, sizeof(evt_values));
				memset(&EventId, 0, sizeof(EventId));
				memset(&SourceNode, 0, sizeof(SourceNode));
				memset(&Message, 0, sizeof(Message));
				memset(&SourceName, 0, sizeof(SourceName));

				EventId.Data = (OpcUa_Byte*)valueB;
				EventId.Length = sizeof(*valueB);

				SourceNode.Identifier.Numeric = ProviderID_MyFolder;
				SourceNode.NamespaceIndex = s_NamespaceIndex;

				CAL_OpcUaStringAttachReadOnly(&Message.Locale, "en-Us");
				switch ((*valueB % 1000) / 100)
				{
					case 0:
						CAL_OpcUaStringAttachReadOnly(&Message.Text, "Sample event provided by MyFolder of CmpOpcUaProviderTemplate!!!");
						break;
					case 1:
						CAL_OpcUaStringAttachReadOnly(&Message.Text, "Sample event provided by MyFolder of CmpOpcUaProviderTemplate!!!\r\n Has multiple Lines...");
						break;
					case 2:
						CAL_OpcUaStringAttachReadOnly(&Message.Text, "Another eventmessage provided by MyFolder of CmpOpcUaProviderTemplate.");
						break;
					case 3:
						CAL_OpcUaStringAttachReadOnly(&Message.Text, "Ein Ereignis auf deutsch...");
						break;
					case 4:
						CAL_OpcUaStringAttachReadOnly(&Message.Text, "Noch ein mal...");
						break;
					case 5:
						CAL_OpcUaStringAttachReadOnly(&Message.Text, "Nachfolgend ein wenig Unicode...");
						break;
					case 6:
					{
						char chiniseUtf8[359] = {
							0x43, 0x68, 0x69, 0x6E, 0x65, 0x73, 0x69, 0x73, 0x63, 0x68, 0x3A, 0x20,
							0xE6, 0x98, 0xAF, 0xE4, 0xB8, 0x80, 0xE4, 0xB8, 0xAA, 0xE4, 0xB8, 0x93,
							0xE4, 0xB8, 0xBA, 0xE8, 0xAF, 0xAD, 0xE6, 0x96, 0x87, 0xE6, 0x95, 0x99,
							0xE5, 0xAD, 0xA6, 0xE8, 0x80, 0x8C, 0xE8, 0xAE, 0xBE, 0xE8, 0xAE, 0xA1,
							0xE7, 0x9A, 0x84, 0xE7, 0x94, 0xB5, 0xE8, 0x84, 0x91, 0xE8, 0xBD, 0xAF,
							0xE4, 0xBB, 0xB6, 0xE3, 0x80, 0x82, 0xE5, 0x9C, 0xA8, 0xE5, 0xBD, 0x93,
							0xE4, 0xBB, 0x8A, 0xE8, 0xBF, 0x99, 0xE4, 0xB8, 0xAA, 0xE7, 0x94, 0xB5,
							0xE8, 0x84, 0x91, 0xE6, 0x97, 0xB6, 0xE4, 0xBB, 0xA3, 0xEF, 0xBC, 0x8C,
							0xEF, 0xBC, 0x82, 0xE7, 0x94, 0xB5, 0xE8, 0x84, 0x91, 0xE8, 0xBE, 0x85,
							0xE5, 0x8A, 0xA9, 0xE6, 0x95, 0x99, 0xE5, 0xAD, 0xA6, 0xEF, 0xBC, 0x82,
							0xE6, 0x98, 0xAF, 0xE4, 0xB8, 0x80, 0xE4, 0xB8, 0xAA, 0xE6, 0x9E, 0x81,
							0xE4, 0xB8, 0xBA, 0xE6, 0x95, 0x99, 0xE5, 0xB8, 0x88, 0xE4, 0xB8, 0x8E,
							0xE5, 0xAD, 0xA6, 0xE7, 0x94, 0x9F, 0xE6, 0x89, 0x80, 0xE5, 0x96, 0x9C,
							0xE6, 0xAC, 0xA2, 0xE7, 0x9A, 0x84, 0xE6, 0x95, 0x99, 0xE5, 0xAD, 0xA6,
							0xE5, 0xAA, 0x92, 0xE4, 0xBD, 0x93, 0xE3, 0x80, 0x82, 0x20, 0xE5, 0x9B,
							0xA0, 0xE4, 0xB8, 0xBA, 0xE6, 0x95, 0x99, 0xE5, 0xAD, 0xA6, 0xE9, 0xA1,
							0xBB, 0xE8, 0xA6, 0x81, 0xE6, 0xB3, 0xA8, 0xE9, 0x87, 0x8D, 0xE4, 0xB8,
							0xAA, 0xE5, 0x88, 0xAB, 0xE5, 0x8C, 0x96, 0xEF, 0xBC, 0x8C, 0xE6, 0xAF,
							0x8F, 0xE4, 0xB8, 0x80, 0xE4, 0xB8, 0xAA, 0xE5, 0xAD, 0xA6, 0xE7, 0x94,
							0x9F, 0xE6, 0x9C, 0x89, 0xE5, 0x85, 0xB6, 0xE4, 0xB8, 0x8D, 0xE5, 0x90,
							0x8C, 0xE7, 0x9A, 0x84, 0xE7, 0xA8, 0x8B, 0xE5, 0xBA, 0xA6, 0xEF, 0xBC,
							0x8C, 0xE5, 0xA6, 0x82, 0xE4, 0xBD, 0x95, 0xE6, 0x9C, 0x89, 0xE6, 0x95,
							0x88, 0xE5, 0x9C, 0xB0, 0xE9, 0x92, 0x88, 0xE5, 0xAF, 0xB9, 0xE6, 0xAF,
							0x8F, 0xE4, 0xB8, 0x80, 0xE4, 0xB8, 0xAA, 0xE5, 0xAD, 0xA6, 0xE7, 0x94,
							0x9F, 0xE7, 0xBB, 0x99, 0xE4, 0xBA, 0x88, 0xE4, 0xB8, 0x8D, 0xE5, 0x90,
							0x8C, 0xE7, 0x9A, 0x84, 0xE5, 0x8F, 0x8D, 0xE5, 0xBA, 0x94, 0xE5, 0x8F,
							0x8A, 0xE7, 0xAB, 0x8B, 0xE5, 0x88, 0xBB, 0xE7, 0x9A, 0x84, 0xE6, 0x8C,
							0x87, 0xE6, 0xAD, 0xA3, 0xEF, 0xBC, 0x8C, 0xE4, 0xBB, 0xA5, 0xE5, 0x8F,
							0x8A, 0xE6, 0x9C, 0x80, 0xE5, 0x90, 0x8E, 0xE4, 0xB8, 0x8D, 0xE5, 0x90,
							0x8C, 0xE7, 0x9A, 0x84, 0xE8, 0xAE, 0xB0, 0xE5, 0x88, 0x86, 0x00
						};
						CAL_OpcUaStringAttachReadOnly(&Message.Text, chiniseUtf8);
						break;
					}
					case 7:
					{
						char emojiUtf8[336] = {
							0x45, 0x6D, 0x6F, 0x6A, 0x69, 0x3A, 0x20, 0xF0, 0x9F, 0x98, 0x83, 0x20,
							0xF0, 0x9F, 0x98, 0x84, 0x20, 0xF0, 0x9F, 0x98, 0x81, 0x20, 0xF0, 0x9F,
							0x98, 0x86, 0x20, 0xF0, 0x9F, 0x98, 0x85, 0x20, 0xF0, 0x9F, 0x98, 0x82,
							0x20, 0x20, 0xF0, 0x9F, 0x98, 0x8A, 0x20, 0xF0, 0x9F, 0x98, 0x87, 0x20,
							0xF0, 0x9F, 0x98, 0x89, 0x20, 0xF0, 0x9F, 0x98, 0x8C, 0x20, 0xF0, 0x9F,
							0x98, 0x8D, 0x20, 0xF0, 0x9F, 0x98, 0x98, 0x20, 0xF0, 0x9F, 0x98, 0x9A,
							0x20, 0xF0, 0x9F, 0x98, 0x8B, 0x20, 0xF0, 0x9F, 0x98, 0x9C, 0x20, 0xF0,
							0x9F, 0x98, 0x9D, 0x20, 0xF0, 0x9F, 0x98, 0x8E, 0x20, 0xF0, 0x9F, 0x98,
							0x8F, 0x20, 0xF0, 0x9F, 0x98, 0x92, 0x20, 0xF0, 0x9F, 0x98, 0x9E, 0x20,
							0xF0, 0x9F, 0x98, 0x94, 0x20, 0xE2, 0x98, 0xB9, 0x20, 0xEF, 0xB8, 0x8F,
							0xF0, 0x9F, 0x98, 0xA3, 0x20, 0xF0, 0x9F, 0x98, 0x96, 0x20, 0xF0, 0x9F,
							0x98, 0xAB, 0x20, 0xF0, 0x9F, 0x98, 0xA9, 0x20, 0xF0, 0x9F, 0x98, 0xA4,
							0x20, 0xF0, 0x9F, 0x98, 0xA0, 0x20, 0xF0, 0x9F, 0x98, 0xA1, 0x20, 0xF0,
							0x9F, 0x98, 0xB6, 0x20, 0xF0, 0x9F, 0x98, 0x90, 0x20, 0xF0, 0x9F, 0x98,
							0xB2, 0x20, 0xF0, 0x9F, 0x98, 0xB5, 0x20, 0xF0, 0x9F, 0x98, 0xB3, 0x20,
							0xF0, 0x9F, 0x98, 0xB1, 0x20, 0xF0, 0x9F, 0x98, 0xA8, 0x20, 0xF0, 0x9F,
							0x98, 0xB0, 0x20, 0xF0, 0x9F, 0x98, 0x88, 0x20, 0xF0, 0x9F, 0x91, 0xBF,
							0x20, 0xF0, 0x9F, 0x91, 0xB9, 0x20, 0xF0, 0x9F, 0x91, 0xBA, 0x20, 0xF0,
							0x9F, 0x92, 0xA9, 0x20, 0xF0, 0x9F, 0x91, 0xBB, 0x20, 0xF0, 0x9F, 0x92,
							0x80, 0x20, 0xE2, 0x98, 0xA0, 0xEF, 0xB8, 0x8F, 0x20, 0xF0, 0x9F, 0x91,
							0xBD, 0x20, 0xF0, 0x9F, 0x91, 0xBE, 0x20, 0xF0, 0x9F, 0x8E, 0x83, 0x20,
							0xF0, 0x9F, 0x98, 0xBA, 0x20, 0xF0, 0x9F, 0x98, 0xB8, 0x20, 0xF0, 0x9F,
							0x98, 0xB9, 0x20, 0xF0, 0x9F, 0x98, 0xBB, 0x20, 0xF0, 0x9F, 0x98, 0xBC,
							0x20, 0xF0, 0x9F, 0x98, 0xBD, 0x20, 0xF0, 0x9F, 0x99, 0x80, 0x20, 0xF0,
							0x9F, 0x98, 0xBF, 0x20, 0xF0, 0x9F, 0x98, 0xBE, 0x20, 0xF0, 0x9F, 0x91,
							0x90, 0x20, 0xF0, 0x9F, 0x99, 0x8C, 0x20, 0xF0, 0x9F, 0x91, 0x8F, 0x20,
							0xF0, 0x9F, 0x99, 0x8F, 0x20, 0xF0, 0x9F, 0x91, 0x8D, 0x20, 0xF0, 0x9F,
							0x91, 0x8E, 0x20, 0xF0, 0x9F, 0x91, 0x8A, 0x20, 0xE2, 0x9C, 0x8A, 0x00
						};
						CAL_OpcUaStringAttachReadOnly(&Message.Text, emojiUtf8);
						break;
					}
					case 8:
					{
						char deutschUtf8[147] = {
							0x44, 0x65, 0x75, 0x74, 0x73, 0x63, 0x68, 0x20, 0x6D, 0x69, 0x74, 0x20,
							0x53, 0x6F, 0x6E, 0x64, 0x65, 0x72, 0x7A, 0x65, 0x69, 0x63, 0x68, 0x65,
							0x6E, 0x3A, 0x20, 0x57, 0xC3, 0xA4, 0x68, 0x72, 0x65, 0x6E, 0x64, 0x20,
							0x41, 0x64, 0x61, 0x6D, 0x20, 0x6C, 0x61, 0x63, 0x68, 0x74, 0x2C, 0x20,
							0x6A, 0x61, 0x67, 0x65, 0x6E, 0x20, 0x7A, 0x77, 0xC3, 0xB6, 0x6C, 0x66,
							0x20, 0x42, 0x6F, 0x78, 0x6B, 0xC3, 0xA4, 0x6D, 0x70, 0x66, 0x65, 0x72,
							0x20, 0x45, 0x76, 0x61, 0x20, 0x71, 0x75, 0x65, 0x72, 0x20, 0xC3, 0xBC,
							0x62, 0x65, 0x72, 0x20, 0x64, 0x65, 0x6E, 0x20, 0x67, 0x72, 0x6F, 0xC3,
							0x9F, 0x65, 0x6E, 0x20, 0x53, 0x79, 0x6C, 0x74, 0x65, 0x72, 0x20, 0x44,
							0x65, 0x69, 0x63, 0x68, 0x20, 0x2D, 0x20, 0x66, 0xC3, 0xBC, 0x72, 0x20,
							0x73, 0x61, 0x74, 0x74, 0x65, 0x20, 0x31, 0x32, 0x2E, 0x33, 0x34, 0x35,
							0x2E, 0x36, 0x36, 0x37, 0x2C, 0x38, 0x39, 0x20, 0xE2, 0x82, 0xAC, 0x75,
							0x72, 0x6F, 0x00
						};
						CAL_OpcUaStringAttachReadOnly(&Message.Text, deutschUtf8);
						break;
					}
					case 9:
						CAL_OpcUaStringAttachReadOnly(&Message.Text, "Now everything starts over...");
						break;
					default:
						CAL_OpcUaStringAttachReadOnly(&Message.Text, "Sample event provided by MyFolder of CmpOpcUaProviderTemplate!!!");
						break;
				}
				CAL_OpcUaStringAttachReadOnly(&SourceName, "MyFolder");

				evt_values[0].Datatype = (OpcUa_Byte)OpcUaType_ByteString;
				evt_values[0].Value.ByteString = EventId;

				evt_values[1].Datatype = (OpcUa_Byte)OpcUaType_NodeId;
				evt_values[1].Value.NodeId = &SourceNode;

				evt_values[2].Datatype = (OpcUa_Byte)OpcUaType_String;
				evt_values[2].Value.String = SourceName;

				evt_values[3].Datatype = (OpcUa_Byte)OpcUaType_DateTime;
				evt_values[3].Value.DateTime = Time;

				evt_values[4].Datatype = (OpcUa_Byte)OpcUaType_LocalizedText;
				evt_values[4].Value.LocalizedText = &Message;


				evt_values[5].Datatype = (OpcUa_Byte)OpcUaType_UInt16;
				evt_values[5].Value.UInt16 = Severity;



				CAL_OpcUaServerFireEvent(s_hEventNotifier, s_hEvent, evt_values);

				valueMyComplexStruct.valueA++;
			}
			break;
		}
		case CH_EXIT3:
		{
			/* Unregister Provider at the OPC UA server */
			CAL_OpcUaServerUnRegisterProvider(&s_OpcUaProviderInfo);
			CAL_OpcUaProviderDelete(s_OpcUaProviderInfo.hProvider);
			break;
		}
		default:
			break;
	}
	return ERR_OK;
}


/******************************************************************************
 * Implementation of OPC UA Provider
 ******************************************************************************/

STATICITF RTS_HANDLE CDECL OpcUaProviderCreate(RTS_HANDLE hIOpcUaProvider, CLASSID ClassId, int iId, RTS_RESULT *pResult)
{
	return hIOpcUaProvider;
}

STATICITF RTS_RESULT CDECL OpcUaProviderDelete(RTS_HANDLE hOpcUaProvider)
{
	return ERR_OK;
}

void BuildCompleyTypeSystem(void)
{
	OpcUaServerNodeDescription typeSystem[5];
	OpcUaServerReferenceDescription references[6];

	memset(typeSystem, 0, sizeof(typeSystem));
	memset(references, 0, sizeof(references));

	typeSystem[0].nodeId.Identifier.Numeric = ProviderID_DataTypeDictionary; typeSystem[0].nodeId.NamespaceIndex = s_NamespaceIndex;
	typeSystem[0].nodeClass = OpcUa_NodeClass_Variable;
	typeSystem[0].browseName.NamespaceIndex = s_NamespaceIndex; typeSystem[0].browseName.Name = s_Namespace;
	typeSystem[0].displayName.Locale = s_ApplicationLocal; typeSystem[0].displayName.Text = s_Namespace;
	typeSystem[0].typeDefinition.Identifier.Numeric = OpcUaId_DataTypeDictionaryType;
	typeSystem[0].elementDescription.variable.bValueAvailable = OpcUa_True;
	typeSystem[0].elementDescription.variable.value.Datatype = OpcUaType_ByteString;
	typeSystem[0].elementDescription.variable.value.Value.ByteString.Data = (OpcUa_Byte*)szTypeDict; typeSystem[0].elementDescription.variable.value.Value.ByteString.Length = sizeof(szTypeDict);
	typeSystem[0].elementDescription.variable.dataType.Identifier.Numeric = OpcUaId_ByteString;
	typeSystem[0].elementDescription.variable.i32ValueRank = OpcUa_ValueRanks_Scalar;
	typeSystem[0].elementDescription.variable.accessLevel = OpcUa_AccessLevels_CurrentRead;
	typeSystem[0].elementDescription.variable.useraccesslevel = OpcUa_AccessLevels_CurrentRead;
	typeSystem[0].elementDescription.variable.historizing = OpcUa_False;

	typeSystem[1].nodeId.Identifier.Numeric = ProviderID_DataTypeDictionary_NamespaceURI; typeSystem[1].nodeId.NamespaceIndex = s_NamespaceIndex;
	typeSystem[1].nodeClass = OpcUa_NodeClass_Variable;
	typeSystem[1].browseName.NamespaceIndex = 0; CAL_OpcUaStringAttachReadOnly(&typeSystem[1].browseName.Name, OpcUa_BrowseName_NamespaceUri);
	typeSystem[1].displayName.Locale = s_ApplicationLocal; CAL_OpcUaStringAttachReadOnly(&typeSystem[1].displayName.Text, OpcUa_BrowseName_NamespaceUri);
	typeSystem[1].typeDefinition.Identifier.Numeric = OpcUaId_PropertyType;
	typeSystem[1].elementDescription.variable.bValueAvailable = OpcUa_True;
	typeSystem[1].elementDescription.variable.value.Datatype = OpcUaType_String;
	CAL_OpcUaStringAttachReadOnly(&typeSystem[1].elementDescription.variable.value.Value.String, CAL_OpcUaStringGetRawString(&s_Namespace));
	typeSystem[1].elementDescription.variable.dataType.Identifier.Numeric = OpcUaId_String;
	typeSystem[1].elementDescription.variable.i32ValueRank = OpcUa_ValueRanks_Scalar;
	typeSystem[1].elementDescription.variable.accessLevel = OpcUa_AccessLevels_CurrentRead;
	typeSystem[1].elementDescription.variable.useraccesslevel = OpcUa_AccessLevels_CurrentRead;
	typeSystem[1].elementDescription.variable.historizing = OpcUa_False;

	typeSystem[2].nodeId.Identifier.Numeric = ProviderID_DataTypeDescription_MyComplexStruct; typeSystem[2].nodeId.NamespaceIndex = s_NamespaceIndex;
	typeSystem[2].nodeClass = OpcUa_NodeClass_Variable;
	typeSystem[2].browseName.NamespaceIndex = s_NamespaceIndex; typeSystem[2].browseName.Name = sMyCompleyStruct;
	typeSystem[2].displayName.Locale = s_ApplicationLocal; typeSystem[2].displayName.Text = sMyCompleyStruct;
	typeSystem[2].typeDefinition.Identifier.Numeric = OpcUaId_DataTypeDescriptionType;
	typeSystem[2].elementDescription.variable.bValueAvailable = OpcUa_True;
	typeSystem[2].elementDescription.variable.value.Datatype = OpcUaType_String;
	typeSystem[2].elementDescription.variable.value.Value.String = sMyCompleyStruct;
	typeSystem[2].elementDescription.variable.dataType.Identifier.Numeric = OpcUaId_String;
	typeSystem[2].elementDescription.variable.i32ValueRank = OpcUa_ValueRanks_Scalar;
	typeSystem[2].elementDescription.variable.accessLevel = OpcUa_AccessLevels_CurrentRead;
	typeSystem[2].elementDescription.variable.useraccesslevel = OpcUa_AccessLevels_CurrentRead;
	typeSystem[2].elementDescription.variable.historizing = OpcUa_False;

	typeSystem[3].nodeId.Identifier.Numeric = ProviderID_DataType_MyComplexStruct; typeSystem[3].nodeId.NamespaceIndex = s_NamespaceIndex;
	typeSystem[3].nodeClass = OpcUa_NodeClass_DataType;
	typeSystem[3].browseName.NamespaceIndex = s_NamespaceIndex; typeSystem[3].browseName.Name = sMyCompleyStruct;
	typeSystem[3].displayName.Locale = s_ApplicationLocal; typeSystem[3].displayName.Text = sMyCompleyStruct;
	typeSystem[3].elementDescription.dataType.isAbstract = OpcUa_False;

	typeSystem[4].nodeId.Identifier.Numeric = ProviderID_DataType_MyComplexStruct_Encoding; typeSystem[4].nodeId.NamespaceIndex = s_NamespaceIndex;
	typeSystem[4].nodeClass = OpcUa_NodeClass_Object;
	typeSystem[4].browseName.NamespaceIndex = 0; CAL_OpcUaStringAttachReadOnly(&typeSystem[4].browseName.Name, OpcUa_BrowseName_DefaultBinary);
	typeSystem[4].displayName.Locale = s_ApplicationLocal; CAL_OpcUaStringAttachReadOnly(&typeSystem[4].displayName.Text, OpcUa_BrowseName_DefaultBinary);
	typeSystem[4].typeDefinition.Identifier.Numeric = OpcUaId_DataTypeEncodingType;
	typeSystem[4].elementDescription.object.eventNotifier = OpcUa_EventNotifiers_None;


	/* Start */
	references[0].startNode.NamespaceIndex = 0; references[0].startNode.Identifier.Numeric = OpcUaId_OPCBinarySchema_TypeSystem;
	references[0].destinationNode.NamespaceIndex = s_NamespaceIndex; references[0].destinationNode.Identifier.Numeric = ProviderID_DataTypeDictionary;
	references[0].referenceType.Identifier.Numeric = OpcUaId_HasComponent;
	references[0].bBidirectional = OpcUa_True;

	/* Type Dictionary */
	references[1].startNode.NamespaceIndex = s_NamespaceIndex; references[1].startNode.Identifier.Numeric = ProviderID_DataTypeDictionary;
	references[1].destinationNode.NamespaceIndex = s_NamespaceIndex; references[1].destinationNode.Identifier.Numeric = ProviderID_DataTypeDescription_MyComplexStruct;
	references[1].referenceType.Identifier.Numeric = OpcUaId_HasComponent;
	references[1].bBidirectional = OpcUa_True;

	references[2].startNode.NamespaceIndex = s_NamespaceIndex; references[2].startNode.Identifier.Numeric = ProviderID_DataTypeDictionary;
	references[2].destinationNode.NamespaceIndex = s_NamespaceIndex; references[2].destinationNode.Identifier.Numeric = ProviderID_DataTypeDictionary_NamespaceURI;
	references[2].referenceType.Identifier.Numeric = OpcUaId_HasProperty;
	references[2].bBidirectional = OpcUa_True;
	
	/* Data Type */
	references[3].startNode.NamespaceIndex = 0; references[3].startNode.Identifier.Numeric = OpcUaId_Structure;
	references[3].destinationNode.NamespaceIndex = s_NamespaceIndex; references[3].destinationNode.Identifier.Numeric = ProviderID_DataType_MyComplexStruct;
	references[3].referenceType.Identifier.Numeric = OpcUaId_HasSubtype;
	references[3].bBidirectional = OpcUa_True;

	/* Encoding */
	references[4].startNode.NamespaceIndex = s_NamespaceIndex; references[4].startNode.Identifier.Numeric = ProviderID_DataType_MyComplexStruct;
	references[4].destinationNode.NamespaceIndex = s_NamespaceIndex; references[4].destinationNode.Identifier.Numeric = ProviderID_DataType_MyComplexStruct_Encoding;
	references[4].referenceType.Identifier.Numeric = OpcUaId_HasEncoding;
	references[4].bBidirectional = OpcUa_True;

	references[5].startNode.NamespaceIndex = s_NamespaceIndex; references[5].startNode.Identifier.Numeric = ProviderID_DataType_MyComplexStruct_Encoding;
	references[5].destinationNode.NamespaceIndex = s_NamespaceIndex; references[5].destinationNode.Identifier.Numeric = ProviderID_DataTypeDescription_MyComplexStruct;
	references[5].referenceType.Identifier.Numeric = OpcUaId_HasDescription;
	references[5].bBidirectional = OpcUa_True;

	
	CAL_OpcUaServerAddNodes(&s_OpcUaProviderInfo, typeSystem, sizeof(typeSystem) / sizeof(typeSystem[0]));
	CAL_OpcUaServerAddReferences(references, sizeof(references) / sizeof(references[0]));
}

STATICITF OpcUa_StatusCode CDECL OpcUaProviderInitialize(RTS_HANDLE hProvider)
{
	RTS_RESULT Result = ERR_OK;
	s_NamespaceIndex = CAL_OpcUaServerRegisterNamespace(&s_Namespace);
	OpcUa_NodeId nodeId;
	OpcUa_NodeId serverNode;
	OpcUa_NodeId baseEventType;

	memset(&nodeId, 0, sizeof(nodeId));
	memset(&serverNode, 0, sizeof(serverNode));
	memset(&baseEventType, 0, sizeof(baseEventType));

	nodeId.IdentifierType = OpcUa_IdentifierType_Numeric;
	nodeId.NamespaceIndex = s_NamespaceIndex;
	nodeId.Identifier.Numeric = ProviderID_MyFolder;

	serverNode.IdentifierType = OpcUa_IdentifierType_Numeric;
	serverNode.NamespaceIndex = 0;
	serverNode.Identifier.Numeric = OpcUaId_Server;

	baseEventType.IdentifierType = OpcUa_IdentifierType_Numeric;
	baseEventType.NamespaceIndex = 0;
	baseEventType.Identifier.Numeric = OpcUaId_BaseEventType;

	s_hEventNotifier = CAL_OpcUaServerRegisterEventNotifier(&nodeId, &serverNode, &Result);
	s_hEvent = CAL_OpcUaServerRegisterEvent(&s_OpcUaProviderInfo, &baseEventType, 0, NULL, &Result);

	BuildCompleyTypeSystem();
	return OpcUa_Good;
}

STATICITF OpcUa_StatusCode CDECL OpcUaProviderCleanup(RTS_HANDLE hProvider)
{
	CAL_OpcUaServerUnregisterEvent(s_hEvent);
	CAL_OpcUaServerUnregisterEventNotifier(s_hEventNotifier);
	return OpcUa_Good;
}

static OpcUa_StatusCode BrowseAddNode(OpcUaProvider_BrowseContext* pContext, OpcUa_BrowseDirection direction, OpcUa_Int16 namespaceIndex, OpcUa_UInt32 nodeId, OpcUa_Int16 browseNameID, OpcUa_String name, OpcUa_NodeClass nodeClass, OpcUa_NodeId reftypeid, OpcUa_NodeId typedefid)
{
	OpcUa_StatusCode uStatus = OpcUa_Good;
	if (CAL_OpcUaServerCheckReferenceRecursive(&pContext->pNodeToBrowse->ReferenceTypeId, pContext->pNodeToBrowse->IncludeSubtypes, &reftypeid))
	{
		if (pContext->pReference == OpcUa_Null)
		{
			if (BrowseContextCheckAddNodes(pContext, 1) == OpcUa_False)
			{
				BrowseContextSetUnfinishedFlag(pContext);
				return uStatus;
			}
		}
		else
		{
			if (BrowseContextCheckNodes(pContext, 1) == OpcUa_True)
			{
				OpcUa_ReferenceDescription* pRefDesc = OpcUa_Null;
				const OpcUa_BrowseDescription* pBrowseDesc = pContext->pNodeToBrowse;

				pRefDesc = BrowseContextGetNextRefDesc(pContext);
				if (pRefDesc != OpcUa_Null)
				{
					/* Set forward flag */
					if (direction == OpcUa_BrowseDirection_Forward)
					{
						if (pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_IsForward)
							pRefDesc->IsForward = OpcUa_True;
					}

					/* Set Node id */
					pRefDesc->NodeId.NodeId.NamespaceIndex = namespaceIndex;
					pRefDesc->NodeId.NodeId.IdentifierType = (OpcUa_UInt16)OpcUa_IdentifierType_Numeric;
					pRefDesc->NodeId.NodeId.Identifier.Numeric = nodeId;


					/* Set browse name and display name */
					if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_BrowseName) != 0)
					{
						pRefDesc->BrowseName.NamespaceIndex = browseNameID;
						CAL_OpcUaStringCopyTo(&name, &pRefDesc->BrowseName.Name);
					}
					if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_DisplayName) != 0)
					{
						CAL_OpcUaStringCopyTo(&name, &pRefDesc->DisplayName.Text);
						CAL_OpcUaStringStrnCpy(&pRefDesc->DisplayName.Locale, &s_ApplicationLocal, OPCUA_STRING_LENDONTCARE);
					}

					/* Set reference type */
					if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_ReferenceTypeId) != 0)
					{
						CAL_OpcUaNodeIdCopyTo(&reftypeid, &pRefDesc->ReferenceTypeId);
					}

					if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_NodeClass) != 0)
						pRefDesc->NodeClass = nodeClass;

					/* Set type definition of node */
					if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_TypeDefinition) != 0)
					{
						CAL_OpcUaNodeIdCopyTo(&typedefid, &pRefDesc->TypeDefinition.NodeId);
						pRefDesc->TypeDefinition.ServerIndex = 0;
					}
				}
			}
			else
			{
				BrowseContextSetUnfinishedFlag(pContext);
			}
		}
	}
	return uStatus;
}


OpcUa_StatusCode BrowseObjectsNode(OpcUaProvider_BrowseContext *pContext)
{
	OpcUa_StatusCode uStatus = OpcUa_BadNodeIdUnknown;
	const OpcUa_BrowseDescription* pNodeToBrowse = pContext->pNodeToBrowse;
	OpcUa_NodeId reftypeid;

	CAL_OpcUaNodeIdInitialize(&reftypeid);
	reftypeid.Identifier.Numeric = OpcUaId_Organizes;
	reftypeid.NamespaceIndex = 0;
	reftypeid.IdentifierType = OpcUa_IdentifierType_Numeric;

	if (!CAL_OpcUaServerCheckReferenceRecursive(&pNodeToBrowse->ReferenceTypeId, pNodeToBrowse->IncludeSubtypes, &reftypeid))
		return OpcUa_BadNodeIdUnknown;

	/* Check result mask */
	if ((pNodeToBrowse->NodeClassMask & OpcUa_NodeClass_Variable | OpcUa_NodeClass_Object || pNodeToBrowse->NodeClassMask == 0) == 0)
		return OpcUa_BadNodeIdUnknown;

	/* Check browse direction */
	if (pNodeToBrowse->BrowseDirection == OpcUa_BrowseDirection_Inverse)
		return OpcUa_BadNodeIdUnknown;

	/* Add variable nodes */
	if (pNodeToBrowse->NodeClassMask & OpcUa_NodeClass_Variable || pNodeToBrowse->NodeClassMask == 0)
	{		
		uStatus = OpcUa_Good;
		OpcUa_String name;
		OpcUa_NodeId typedefid;
		memset(&reftypeid, 0, sizeof(reftypeid));
		memset(&typedefid, 0, sizeof(typedefid));

		reftypeid.Identifier.Numeric = OpcUaId_Organizes;
		typedefid.Identifier.Numeric = OpcUaId_UInt32;
		CAL_OpcUaStringInitialize(&name);
		CAL_OpcUaStringAttachReadOnly(&name, "valueA");
		BrowseAddNode(pContext, OpcUa_BrowseDirection_Forward, s_NamespaceIndex, ProviderID_ValueA, s_NamespaceIndex, name, OpcUa_NodeClass_Variable, reftypeid, typedefid);
		CAL_OpcUaStringAttachReadOnly(&name, "valueB");
		BrowseAddNode(pContext, OpcUa_BrowseDirection_Forward, s_NamespaceIndex, ProviderID_ValueB, s_NamespaceIndex, name, OpcUa_NodeClass_Variable, reftypeid, typedefid);

		typedefid.NamespaceIndex = s_NamespaceIndex;
		typedefid.Identifier.Numeric = ProviderID_DataType_MyComplexStruct;
		CAL_OpcUaStringAttachReadOnly(&name, "valueMyComplexStruct");
		BrowseAddNode(pContext, OpcUa_BrowseDirection_Forward, s_NamespaceIndex, ProviderID_ValueMyComplexStruct, s_NamespaceIndex, name, OpcUa_NodeClass_Variable, reftypeid, typedefid);
	}
	/* Add object node */
	if (pNodeToBrowse->NodeClassMask & OpcUa_NodeClass_Object || pNodeToBrowse->NodeClassMask == 0)
	{
		uStatus = OpcUa_Good;
		if (pContext->pReference == OpcUa_Null)
		{
			if (BrowseContextCheckAddNodes(pContext, 1) == OpcUa_False)
			{
				BrowseContextSetUnfinishedFlag(pContext);
				return uStatus;
			}
		}
		else
		{
			if (BrowseContextCheckNodes(pContext, 1) == OpcUa_True)
			{
				OpcUa_ReferenceDescription* pRefDesc = OpcUa_Null;
				const OpcUa_BrowseDescription* pBrowseDesc = pContext->pNodeToBrowse;

				pRefDesc = BrowseContextGetNextRefDesc(pContext);
				if (pRefDesc != OpcUa_Null)
				{
					/* Set forward flag */
					if (pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_IsForward)
						pRefDesc->IsForward = OpcUa_True;

					/* Set Node id */
					pRefDesc->NodeId.NodeId.NamespaceIndex = s_NamespaceIndex;
					pRefDesc->NodeId.NodeId.IdentifierType = (OpcUa_UInt16)OpcUa_IdentifierType_Numeric;
					pRefDesc->NodeId.NodeId.Identifier.Numeric = ProviderID_MyFolder;


					/* Set browse name and display name */
					if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_BrowseName) != 0)
					{
						pRefDesc->BrowseName.NamespaceIndex = s_NamespaceIndex;
						CAL_OpcUaStringAttachCopy(&pRefDesc->BrowseName.Name, "MyFolder");
					}
					if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_DisplayName) != 0)
					{
						CAL_OpcUaStringAttachReadOnly(&pRefDesc->DisplayName.Text, "MyFolder");
						CAL_OpcUaStringStrnCpy(&pRefDesc->DisplayName.Locale, &s_ApplicationLocal, OPCUA_STRING_LENDONTCARE);
					}

					/* Set reference type */
					if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_ReferenceTypeId) != 0)
					{
						CAL_OpcUaNodeIdCopyTo(&reftypeid, &pRefDesc->ReferenceTypeId);
					}
				}
				if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_TypeDefinition) != 0)
				{
					pRefDesc->TypeDefinition.NodeId.IdentifierType = (OpcUa_UInt16)OpcUa_IdentifierType_Numeric;
					pRefDesc->TypeDefinition.NodeId.Identifier.Numeric = (OpcUa_UInt32)OpcUaId_FolderType;
					pRefDesc->TypeDefinition.NodeId.NamespaceIndex = 0;
					pRefDesc->TypeDefinition.ServerIndex = 0;
				}

				if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_NodeClass) != 0)
					pRefDesc->NodeClass = OpcUa_NodeClass_Object;
			}
			else
			{
				BrowseContextSetUnfinishedFlag(pContext);
				return uStatus;
			}
		}
	}
	
	if (pNodeToBrowse->NodeClassMask & OpcUa_NodeClass_Method || pNodeToBrowse->NodeClassMask == 0)
	{
		uStatus = OpcUa_Good;
		if (pContext->pReference == OpcUa_Null)
		{
			if (BrowseContextCheckAddNodes(pContext, 1) == OpcUa_False)
			{
				BrowseContextSetUnfinishedFlag(pContext);
				return uStatus;
			}
		}
		else
		{
			if (BrowseContextCheckNodes(pContext, 1) == OpcUa_True)
			{
				OpcUa_ReferenceDescription* pRefDesc = OpcUa_Null;
				const OpcUa_BrowseDescription* pBrowseDesc = pContext->pNodeToBrowse;

				pRefDesc = BrowseContextGetNextRefDesc(pContext);
				if (pRefDesc != OpcUa_Null)
				{
					/* Set forward flag */
					if (pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_IsForward)
						pRefDesc->IsForward = OpcUa_True;

					/* Set Node id */
					pRefDesc->NodeId.NodeId.NamespaceIndex = s_NamespaceIndex;
					pRefDesc->NodeId.NodeId.IdentifierType = (OpcUa_UInt16)OpcUa_IdentifierType_Numeric;
					pRefDesc->NodeId.NodeId.Identifier.Numeric = ProviderID_MyFunction;


					/* Set browse name and display name */
					if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_BrowseName) != 0)
					{
						pRefDesc->BrowseName.NamespaceIndex = s_NamespaceIndex;
						CAL_OpcUaStringAttachCopy(&pRefDesc->BrowseName.Name, "MyFunction");
					}
					if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_DisplayName) != 0)
					{
						CAL_OpcUaStringAttachReadOnly(&pRefDesc->DisplayName.Text, "MyFunction");
						CAL_OpcUaStringStrnCpy(&pRefDesc->DisplayName.Locale, &s_ApplicationLocal, OPCUA_STRING_LENDONTCARE);
					}

					/* Set reference type */
					if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_ReferenceTypeId) != 0)
					{
						CAL_OpcUaNodeIdCopyTo(&reftypeid, &pRefDesc->ReferenceTypeId);
					}
				}
				if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_TypeDefinition) != 0)
				{
					pRefDesc->TypeDefinition.NodeId.IdentifierType = (OpcUa_UInt16)OpcUa_IdentifierType_Numeric;
					pRefDesc->TypeDefinition.NodeId.Identifier.Numeric = 0; (OpcUa_UInt32)OpcUaId_FolderType;
					pRefDesc->TypeDefinition.NodeId.NamespaceIndex = 0;
					pRefDesc->TypeDefinition.ServerIndex = 0;
				}

				if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_NodeClass) != 0)
					pRefDesc->NodeClass = OpcUa_NodeClass_Method;
			}
			else
			{
				BrowseContextSetUnfinishedFlag(pContext);
				return uStatus;
			}
		}
	}
	return uStatus;
}

OpcUa_StatusCode BrowseServerNode(OpcUaProvider_BrowseContext *pContext)
{
	OpcUa_StatusCode uStatus = OpcUa_BadNodeIdUnknown;
	const OpcUa_BrowseDescription* pNodeToBrowse = pContext->pNodeToBrowse;
	OpcUa_NodeId reftypeid;

	CAL_OpcUaNodeIdInitialize(&reftypeid);
	reftypeid.Identifier.Numeric = OpcUaId_HasNotifier;
	reftypeid.NamespaceIndex = 0;
	reftypeid.IdentifierType = OpcUa_IdentifierType_Numeric;

	if (!CAL_OpcUaServerCheckReferenceRecursive(&pNodeToBrowse->ReferenceTypeId, pNodeToBrowse->IncludeSubtypes, &reftypeid))
		return OpcUa_BadNodeIdUnknown;

	/* Check result mask */
	if ((pNodeToBrowse->NodeClassMask & OpcUa_NodeClass_Variable | OpcUa_NodeClass_Object || pNodeToBrowse->NodeClassMask == 0) == 0)
		return OpcUa_BadNodeIdUnknown;

	/* Check browse direction */
	if (pNodeToBrowse->BrowseDirection == OpcUa_BrowseDirection_Inverse)
		return OpcUa_BadNodeIdUnknown;

	/* Add object node */
	if (pNodeToBrowse->NodeClassMask & OpcUa_NodeClass_Object || pNodeToBrowse->NodeClassMask == 0)
	{
		uStatus = OpcUa_Good;
		if (pContext->pReference == OpcUa_Null)
		{
			if (BrowseContextCheckAddNodes(pContext, 1) == OpcUa_False)
			{
				BrowseContextSetUnfinishedFlag(pContext);
				return uStatus;
			}
		}
		else
		{
			if (BrowseContextCheckNodes(pContext, 1) == OpcUa_True)
			{
				OpcUa_ReferenceDescription* pRefDesc = OpcUa_Null;
				const OpcUa_BrowseDescription* pBrowseDesc = pContext->pNodeToBrowse;

				pRefDesc = BrowseContextGetNextRefDesc(pContext);
				if (pRefDesc != OpcUa_Null)
				{
					/* Set forward flag */
					if (pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_IsForward)
						pRefDesc->IsForward = OpcUa_True;

					/* Set Node id */
					pRefDesc->NodeId.NodeId.NamespaceIndex = s_NamespaceIndex;
					pRefDesc->NodeId.NodeId.IdentifierType = (OpcUa_UInt16)OpcUa_IdentifierType_Numeric;
					pRefDesc->NodeId.NodeId.Identifier.Numeric = ProviderID_MyFolder;


					/* Set browse name and display name */
					if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_BrowseName) != 0)
					{
						pRefDesc->BrowseName.NamespaceIndex = s_NamespaceIndex;
						CAL_OpcUaStringAttachCopy(&pRefDesc->BrowseName.Name, "MyFolder");
					}
					if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_DisplayName) != 0)
					{
						CAL_OpcUaStringAttachReadOnly(&pRefDesc->DisplayName.Text, "MyFolder");
						CAL_OpcUaStringStrnCpy(&pRefDesc->DisplayName.Locale, &s_ApplicationLocal, OPCUA_STRING_LENDONTCARE);
					}

					/* Set reference type */
					if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_ReferenceTypeId) != 0)
					{
						CAL_OpcUaNodeIdCopyTo(&reftypeid, &pRefDesc->ReferenceTypeId);
					}
				}
				if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_TypeDefinition) != 0)
				{
					pRefDesc->TypeDefinition.NodeId.IdentifierType = (OpcUa_UInt16)OpcUa_IdentifierType_Numeric;
					pRefDesc->TypeDefinition.NodeId.Identifier.Numeric = (OpcUa_UInt32)OpcUaId_FolderType;
					pRefDesc->TypeDefinition.NodeId.NamespaceIndex = 0;
					pRefDesc->TypeDefinition.ServerIndex = 0;
				}

				if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_NodeClass) != 0)
					pRefDesc->NodeClass = OpcUa_NodeClass_Object;
			}
			else
			{
				BrowseContextSetUnfinishedFlag(pContext);
				return uStatus;
			}
		}
	}
	return uStatus;
}

OpcUa_StatusCode BrowseMyFolder(OpcUaProvider_BrowseContext *pContext)
{
	OpcUa_StatusCode uStatus = OpcUa_BadNodeIdUnknown;
	const OpcUa_BrowseDescription* pNodeToBrowse = pContext->pNodeToBrowse;
	OpcUa_NodeId reftypeid;

	uStatus = OpcUa_Good;

	/* Fill forward references */
	if ((pNodeToBrowse->BrowseDirection == OpcUa_BrowseDirection_Forward || pNodeToBrowse->BrowseDirection == OpcUa_BrowseDirection_Both) && 
		(pNodeToBrowse->NodeClassMask == 0 || pNodeToBrowse->NodeClassMask & (OpcUa_NodeClass_VariableType| OpcUa_NodeClass_ObjectType)
		))
	{
		CAL_OpcUaNodeIdInitialize(&reftypeid);
		reftypeid.Identifier.Numeric = OpcUaId_HasTypeDefinition;
		reftypeid.NamespaceIndex = 0;
		reftypeid.IdentifierType = OpcUa_IdentifierType_Numeric;

		/* Check if the client was intrested in this reference type */
		if (CAL_OpcUaServerCheckReferenceRecursive(&pNodeToBrowse->ReferenceTypeId, pNodeToBrowse->IncludeSubtypes, &reftypeid) == OpcUa_True)
		{
			if (pContext->pReference == NULL)
			{
				if (BrowseContextCheckAddNodes(pContext, 1) == OpcUa_False)
				{
					BrowseContextSetUnfinishedFlag(pContext);
					return uStatus;
				}
			}
			else
			{
				if (BrowseContextCheckNodes(pContext, 1) == OpcUa_True)
				{
					OpcUa_ReferenceDescription* pRefDesc = OpcUa_Null;
					const OpcUa_BrowseDescription* pBrowseDesc = pContext->pNodeToBrowse;

					pRefDesc = BrowseContextGetNextRefDesc(pContext);
					if (pRefDesc != OpcUa_Null)
					{
						/* Set forward flag */
						if (pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_IsForward)
							pRefDesc->IsForward = OpcUa_True;

						/* Set Node id */
						pRefDesc->NodeId.NodeId.NamespaceIndex = 0;
						pRefDesc->NodeId.NodeId.IdentifierType = (OpcUa_UInt16)OpcUa_IdentifierType_Numeric;
						if (pNodeToBrowse->NodeId.Identifier.Numeric == 0 || pNodeToBrowse->NodeId.Identifier.Numeric == 0)
						{
							pRefDesc->NodeId.NodeId.Identifier.Numeric = OpcUaId_BaseVariableType;
						}
						if (pNodeToBrowse->NodeId.Identifier.Numeric == ProviderID_MyFolder)
						{
							pRefDesc->NodeId.NodeId.Identifier.Numeric = OpcUaId_FolderType;
						}
						


						/* Set browse name and display name */
						if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_BrowseName) != 0)
						{
							pRefDesc->BrowseName.NamespaceIndex = 0;
							if (pNodeToBrowse->NodeId.Identifier.Numeric == 0 || pNodeToBrowse->NodeId.Identifier.Numeric == 1)
							{
								CAL_OpcUaStringAttachCopy(&pRefDesc->BrowseName.Name, OpcUa_BrowseName_BaseVariableType);
							}
							if (pNodeToBrowse->NodeId.Identifier.Numeric == ProviderID_MyFolder)
							{
								CAL_OpcUaStringAttachCopy(&pRefDesc->BrowseName.Name, OpcUa_BrowseName_FolderType);
							}
						}
						if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_DisplayName) != 0)
						{
							if (pNodeToBrowse->NodeId.Identifier.Numeric == 0 || pNodeToBrowse->NodeId.Identifier.Numeric == 1)
							{
								CAL_OpcUaStringAttachReadOnly(&pRefDesc->DisplayName.Text, OpcUa_BrowseName_BaseVariableType);
							}
							if (pNodeToBrowse->NodeId.Identifier.Numeric == ProviderID_MyFolder)
							{
								CAL_OpcUaStringAttachReadOnly(&pRefDesc->DisplayName.Text, OpcUa_BrowseName_FolderType);
							}
							CAL_OpcUaStringStrnCpy(&pRefDesc->DisplayName.Locale, &s_ApplicationLocal, OPCUA_STRING_LENDONTCARE);
						}

						/* Set reference type */
						if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_ReferenceTypeId) != 0)
						{
							CAL_OpcUaNodeIdCopyTo(&reftypeid, &pRefDesc->ReferenceTypeId);
						}

						if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_NodeClass) != 0)
						{
							if (pNodeToBrowse->NodeId.Identifier.Numeric == 0 || pNodeToBrowse->NodeId.Identifier.Numeric == 1)
							{
								pRefDesc->NodeClass = OpcUa_NodeClass_VariableType;
							}
							if (pNodeToBrowse->NodeId.Identifier.Numeric == ProviderID_MyFolder)
							{
								pRefDesc->NodeClass = OpcUa_NodeClass_ObjectType;
							}
						}

					}
				}
				else
				{
					BrowseContextSetUnfinishedFlag(pContext);
					return uStatus;
				}
				
			}
		}

	}

	/* Fill backward references */
	if ((pNodeToBrowse->BrowseDirection == OpcUa_BrowseDirection_Inverse || pNodeToBrowse->BrowseDirection == OpcUa_BrowseDirection_Both) &&
		(pNodeToBrowse->NodeClassMask == 0 || pNodeToBrowse->NodeClassMask & (OpcUa_NodeClass_Object)
			))
	{

		/* Fill Reference to Objects node 
		*/
		CAL_OpcUaNodeIdInitialize(&reftypeid);
		reftypeid.Identifier.Numeric = OpcUaId_Organizes;
		reftypeid.NamespaceIndex = 0;
		reftypeid.IdentifierType = OpcUa_IdentifierType_Numeric;
		/* Check if the client was intrested in this reference type */
		if (CAL_OpcUaServerCheckReferenceRecursive(&pNodeToBrowse->ReferenceTypeId, pNodeToBrowse->IncludeSubtypes, &reftypeid))
		{
			if (pContext->pReference == NULL)
			{
				if (BrowseContextCheckAddNodes(pContext, 1) == OpcUa_False)
				{
					BrowseContextSetUnfinishedFlag(pContext);
					return uStatus;
				}
			}
			else
			{
				/* Add reference to Objects node */
				if (BrowseContextCheckNodes(pContext, 1) == OpcUa_True)
				{
					OpcUa_ReferenceDescription* pRefDesc = OpcUa_Null;
					const OpcUa_BrowseDescription* pBrowseDesc = pContext->pNodeToBrowse;

					pRefDesc = BrowseContextGetNextRefDesc(pContext);
					if (pRefDesc != OpcUa_Null)
					{
						if (pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_IsForward)
							pRefDesc->IsForward = OpcUa_False;

						/* Set Node id */
						pRefDesc->NodeId.NodeId.NamespaceIndex = 0;
						pRefDesc->NodeId.NodeId.IdentifierType = (OpcUa_UInt16)OpcUa_IdentifierType_Numeric;
						pRefDesc->NodeId.NodeId.Identifier.Numeric = OpcUaId_ObjectsFolder;



						/* Set browse name and display name */
						if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_BrowseName) != 0)
						{
							CAL_OpcUaStringAttachCopy(&pRefDesc->BrowseName.Name, OpcUa_BrowseName_ObjectsFolder);
						}
						if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_DisplayName) != 0)
						{
							CAL_OpcUaStringStrnCpy(&pRefDesc->DisplayName.Locale, &s_ApplicationLocal, OPCUA_STRING_LENDONTCARE);
							CAL_OpcUaStringAttachReadOnly(&pRefDesc->DisplayName.Text, OpcUa_BrowseName_ObjectsFolder);
						}

						/* Set reference type */
						if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_ReferenceTypeId) != 0)
						{
							CAL_OpcUaNodeIdCopyTo(&reftypeid, &pRefDesc->ReferenceTypeId);
						}

						if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_NodeClass) != 0)
						{
							pRefDesc->NodeClass = OpcUa_NodeClass_Object;
						}

					}
				}
				else
				{
					BrowseContextSetUnfinishedFlag(pContext);
					return uStatus;
				}
			}
		}

		/* Add Notifier Of Reference to Server Node */
		CAL_OpcUaNodeIdInitialize(&reftypeid);
		reftypeid.Identifier.Numeric = OpcUaId_HasNotifier;
		reftypeid.NamespaceIndex = 0;
		reftypeid.IdentifierType = OpcUa_IdentifierType_Numeric;
		/* Check if the client was intrested in this reference type */
		if (CAL_OpcUaServerCheckReferenceRecursive(&pNodeToBrowse->ReferenceTypeId, pNodeToBrowse->IncludeSubtypes, &reftypeid))
		{
			if (pContext->pReference == NULL)
			{
				if (BrowseContextCheckAddNodes(pContext, 1) == OpcUa_False)
				{
					BrowseContextSetUnfinishedFlag(pContext);
					return uStatus;
				}
			}
			else
			{
				/* Add reference to Objects node */
				if (BrowseContextCheckAddNodes(pContext, 1) == OpcUa_True)
				{
					OpcUa_ReferenceDescription* pRefDesc = OpcUa_Null;
					const OpcUa_BrowseDescription* pBrowseDesc = pContext->pNodeToBrowse;

					pRefDesc = BrowseContextGetNextRefDesc(pContext);
					if (pRefDesc != OpcUa_Null)
					{
						if (pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_IsForward)
							pRefDesc->IsForward = OpcUa_False;

						/* Set Node id */
						pRefDesc->NodeId.NodeId.NamespaceIndex = 0;
						pRefDesc->NodeId.NodeId.IdentifierType = (OpcUa_UInt16)OpcUa_IdentifierType_Numeric;
						pRefDesc->NodeId.NodeId.Identifier.Numeric = OpcUaId_Server;



						/* Set browse name and display name */
						if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_BrowseName) != 0)
						{
							CAL_OpcUaStringAttachCopy(&pRefDesc->BrowseName.Name, OpcUa_BrowseName_Server);
						}
						if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_DisplayName) != 0)
						{
							CAL_OpcUaStringStrnCpy(&pRefDesc->DisplayName.Locale, &s_ApplicationLocal, OPCUA_STRING_LENDONTCARE);
							CAL_OpcUaStringAttachReadOnly(&pRefDesc->DisplayName.Text, OpcUa_BrowseName_Server);
						}

						/* Set reference type */
						if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_ReferenceTypeId) != 0)
						{
							CAL_OpcUaNodeIdCopyTo(&reftypeid, &pRefDesc->ReferenceTypeId);
						}

						if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_NodeClass) != 0)
						{
							pRefDesc->NodeClass = OpcUa_NodeClass_Object;
						}

					}
				}
				else
				{
					BrowseContextSetUnfinishedFlag(pContext);
					return uStatus;
				}
			}
		}
	}

	return uStatus;
}

OpcUa_StatusCode BrowseMyFunction(OpcUaProvider_BrowseContext *pContext)
{
	OpcUa_StatusCode uStatus = OpcUa_BadNodeIdUnknown;
	const OpcUa_BrowseDescription* pNodeToBrowse = pContext->pNodeToBrowse;
	OpcUa_NodeId reftypeid;

	uStatus = OpcUa_Good;

	/* Fill forward references */
	if ((pNodeToBrowse->BrowseDirection == OpcUa_BrowseDirection_Forward || pNodeToBrowse->BrowseDirection == OpcUa_BrowseDirection_Both) &&
		(pNodeToBrowse->NodeClassMask == 0 || pNodeToBrowse->NodeClassMask & (OpcUa_NodeClass_Variable | OpcUa_NodeClass_Object)
			))
	{
		CAL_OpcUaNodeIdInitialize(&reftypeid);
		reftypeid.Identifier.Numeric = OpcUaId_HasProperty;
		reftypeid.NamespaceIndex = 0;
		reftypeid.IdentifierType = OpcUa_IdentifierType_Numeric;

		/* Check if the client was intrested in this reference type */
		if (CAL_OpcUaServerCheckReferenceRecursive(&pNodeToBrowse->ReferenceTypeId, pNodeToBrowse->IncludeSubtypes, &reftypeid) == OpcUa_True)
		{
			if (pContext->pReference == NULL)
			{
				if (BrowseContextCheckAddNodes(pContext, 2) == OpcUa_False)
				{
					BrowseContextSetUnfinishedFlag(pContext);
					return uStatus;
				}
			}
			else
			{
				if (BrowseContextCheckNodes(pContext, 1) == OpcUa_True)
				{
					OpcUa_ReferenceDescription* pRefDesc = OpcUa_Null;
					const OpcUa_BrowseDescription* pBrowseDesc = pContext->pNodeToBrowse;

					pRefDesc = BrowseContextGetNextRefDesc(pContext);
					if (pRefDesc != OpcUa_Null)
					{
						/* Set forward flag */
						if (pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_IsForward)
							pRefDesc->IsForward = OpcUa_True;

						/* Set Node id */
						pRefDesc->NodeId.NodeId.NamespaceIndex = s_NamespaceIndex;
						pRefDesc->NodeId.NodeId.IdentifierType = (OpcUa_UInt16)OpcUa_IdentifierType_Numeric;
						pRefDesc->NodeId.NodeId.Identifier.Numeric = ProivderID_MyFunction_InputArguments;

						/* Set browse name and display name */
						if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_BrowseName) != 0)
						{
							pRefDesc->BrowseName.NamespaceIndex = 0;
							CAL_OpcUaStringAttachCopy(&pRefDesc->BrowseName.Name, OpcUa_BrowseName_InputArguments);
						}
						if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_DisplayName) != 0)
						{
							CAL_OpcUaStringAttachReadOnly(&pRefDesc->DisplayName.Text, OpcUa_BrowseName_InputArguments);
							CAL_OpcUaStringStrnCpy(&pRefDesc->DisplayName.Locale, &s_ApplicationLocal, OPCUA_STRING_LENDONTCARE);
						}

						/* Set reference type */
						if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_ReferenceTypeId) != 0)
						{
							CAL_OpcUaNodeIdCopyTo(&reftypeid, &pRefDesc->ReferenceTypeId);
						}

						if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_NodeClass) != 0)
						{
							pRefDesc->NodeClass = OpcUa_NodeClass_Variable;
						}

						if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_TypeDefinition) != 0)
						{
							pRefDesc->TypeDefinition.NodeId.IdentifierType = (OpcUa_UInt16)OpcUa_IdentifierType_Numeric;
							pRefDesc->TypeDefinition.NodeId.Identifier.Numeric = (OpcUa_UInt32)OpcUaId_PropertyType;
							pRefDesc->TypeDefinition.NodeId.NamespaceIndex = 0;
							pRefDesc->TypeDefinition.ServerIndex = 0;
						}
						

					}
					if (BrowseContextCheckNodes(pContext, 1) == OpcUa_True)
					{
						pRefDesc = OpcUa_Null;
						pBrowseDesc = pContext->pNodeToBrowse;

						pRefDesc = BrowseContextGetNextRefDesc(pContext);
						if (pRefDesc != OpcUa_Null)
						{
							/* Set forward flag */
							if (pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_IsForward)
								pRefDesc->IsForward = OpcUa_True;

							/* Set Node id */
							pRefDesc->NodeId.NodeId.NamespaceIndex = s_NamespaceIndex;
							pRefDesc->NodeId.NodeId.IdentifierType = (OpcUa_UInt16)OpcUa_IdentifierType_Numeric;
							pRefDesc->NodeId.NodeId.Identifier.Numeric = ProivderID_MyFunction_OutputArguments;

							/* Set browse name and display name */
							if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_BrowseName) != 0)
							{
								pRefDesc->BrowseName.NamespaceIndex = 0;
								CAL_OpcUaStringAttachCopy(&pRefDesc->BrowseName.Name, OpcUa_BrowseName_OutputArguments);
							}
							if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_DisplayName) != 0)
							{
								CAL_OpcUaStringAttachReadOnly(&pRefDesc->DisplayName.Text, OpcUa_BrowseName_OutputArguments);
								CAL_OpcUaStringStrnCpy(&pRefDesc->DisplayName.Locale, &s_ApplicationLocal, OPCUA_STRING_LENDONTCARE);
							}

							/* Set reference type */
							if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_ReferenceTypeId) != 0)
							{
								CAL_OpcUaNodeIdCopyTo(&reftypeid, &pRefDesc->ReferenceTypeId);
							}

							if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_NodeClass) != 0)
							{
								pRefDesc->NodeClass = OpcUa_NodeClass_Variable;
							}

							if ((pBrowseDesc->ResultMask & (OpcUa_UInt32)OpcUa_BrowseResultMask_TypeDefinition) != 0)
							{
								pRefDesc->TypeDefinition.NodeId.IdentifierType = (OpcUa_UInt16)OpcUa_IdentifierType_Numeric;
								pRefDesc->TypeDefinition.NodeId.Identifier.Numeric = (OpcUa_UInt32)OpcUaId_PropertyType;
								pRefDesc->TypeDefinition.NodeId.NamespaceIndex = 0;
								pRefDesc->TypeDefinition.ServerIndex = 0;
							}
						}
					}
				}
				else
				{
					BrowseContextSetUnfinishedFlag(pContext);
					return uStatus;
				}

			}
		}

	}
	return uStatus;
}

OpcUa_StatusCode BrowseOwnNodes(OpcUaProvider_BrowseContext *pContext)
{
	const OpcUa_BrowseDescription* pNodeToBrowse = pContext->pNodeToBrowse;

	if (pNodeToBrowse->NodeId.NamespaceIndex != s_NamespaceIndex)
		return OpcUa_BadNodeIdUnknown;

	if (pNodeToBrowse->NodeId.Identifier.Numeric == ProviderID_MyFolder)
		return BrowseMyFolder(pContext);
	if (pNodeToBrowse->NodeId.Identifier.Numeric == ProviderID_MyFunction)
		return BrowseMyFunction(pContext);

	if (pNodeToBrowse->NodeId.Identifier.Numeric == ProviderID_ValueMyComplexStruct)
		return OpcUa_Good;

	return OpcUa_BadNodeIdUnknown;
}

STATICITF OpcUa_StatusCode OpcUaProviderBrowse(RTS_HANDLE hProvider, OpcUaProvider_BrowseContext *pContext)
{

	OpcUa_StatusCode uStatus = OpcUa_Good;
	const OpcUa_BrowseDescription* pNodeToBrowse = pContext->pNodeToBrowse;
	do
	{
		/* Only accept numeric node ids. Only these one are used in the template  */
		if (pNodeToBrowse->NodeId.IdentifierType != OpcUa_IdentifierType_Numeric)
			break;

		/* Children nodes of objects folder */
		if (pNodeToBrowse->NodeId.NamespaceIndex == 0)
		{
			switch (pNodeToBrowse->NodeId.Identifier.Numeric)
			{
				case OpcUaId_ObjectsFolder:
					uStatus = BrowseObjectsNode(pContext);
					break;
					/* Add Has EventNotifier reference */
				case OpcUaId_Server:
					uStatus = BrowseServerNode(pContext);
					break;
				default:
					break;
			}
		}


		/* Browsing the own nodes */
		if (pNodeToBrowse->NodeId.NamespaceIndex == s_NamespaceIndex)
		{
			uStatus = BrowseOwnNodes(pContext);
		}

	} while (0);
	
	return uStatus;
	
}

STATICITF OpcUa_StatusCode CDECL OpcUaProviderCreateMonitoredItem(RTS_HANDLE hProvider, OpcUaProvider_CreateMonitoredItemContext *pContext)
{
	OpcUa_StatusCode uStatus = OpcUa_BadNodeIdUnknown;
	OpcUa_UInt32 attributeId = pContext->pItemToCreate->AttributeId;
	const OpcUa_NodeId* pNodeId = &pContext->pItemToCreate->NodeId;
	OpcUaProvider_ReadContext readContext;
	if (attributeId != OpcUa_Attributes_Value)
	{
		uStatus = OpcUa_BadAttributeIdInvalid;
		return uStatus;
	}
	readContext.eTimestampsToReturn = OpcUa_TimestampsToReturn_Server;
	readContext.pNodeToRead = pContext->pItemToCreate;
	readContext.pDataValue = pContext->pValue;
	uStatus = OpcUaProviderRead(hProvider, &readContext);
	if(uStatus == OpcUa_Good)
	{
		SamplingInfo* pInfo;
		pContext->pProviderInformation = CAL_SysMemAllocData(COMPONENT_NAME, sizeof(SamplingInfo), NULL);
		pInfo = (SamplingInfo*)pContext->pProviderInformation;
		pInfo->id = pNodeId->Identifier.Numeric;


	}
	return uStatus;	
}

STATICITF OpcUa_StatusCode CDECL OpcUaProviderDeleteMonitoredItem(RTS_HANDLE hProvider, OpcUaProvider_DeleteMonitoredItemContext *pContext)
{
	CAL_SysMemFreeData(COMPONENT_NAME, pContext->pProviderInformation);
	return OpcUa_Good;
}

STATICITF OpcUa_StatusCode CDECL OpcUaProviderSampleMonitoredItem(RTS_HANDLE hProvider, OpcUaProvider_SampleMonitoredItemContext *pContext)
{
	SamplingInfo* pInfo = (SamplingInfo*)pContext->pProviderInformation;
	pContext->pDataValue->SourceTimestamp = CAL_OpcUaDateTimeUtcNow();
	if (pInfo->id == ProviderID_ValueA)
		pContext->pDataValue->Value.Value.UInt32 = *valueA;
	else if (pInfo->id == ProviderID_ValueB)
		pContext->pDataValue->Value.Value.UInt32 = *valueB;
	else if (pInfo->id == ProviderID_ValueMyComplexStruct)
	{
		OpcUa_Byte* pBuffer = pContext->pDataValue->Value.Value.ExtensionObject->Body.Binary.Data;
		OpcUa_Int32 *pSize = &pContext->pDataValue->Value.Value.ExtensionObject->Body.Binary.Length;
		*pSize = 0;
		memcpy(pBuffer, &valueMyComplexStruct.valueA, sizeof(valueMyComplexStruct.valueA)); pBuffer += sizeof(valueMyComplexStruct.valueA); *pSize += sizeof(valueMyComplexStruct.valueA);
		memcpy(pBuffer, &valueMyComplexStruct.valueB, sizeof(valueMyComplexStruct.valueB)); pBuffer += sizeof(valueMyComplexStruct.valueB); *pSize += sizeof(valueMyComplexStruct.valueB);
		memcpy(pBuffer, &valueMyComplexStruct.valueC, sizeof(valueMyComplexStruct.valueC)); pBuffer += sizeof(valueMyComplexStruct.valueC); *pSize += sizeof(valueMyComplexStruct.valueC);
		memcpy(pBuffer, &valueMyComplexStruct.valueD, sizeof(valueMyComplexStruct.valueD)); pBuffer += sizeof(valueMyComplexStruct.valueD); *pSize += sizeof(valueMyComplexStruct.valueD);
		memcpy(pBuffer, &valueMyComplexStruct.valueE, sizeof(valueMyComplexStruct.valueE)); pBuffer += sizeof(valueMyComplexStruct.valueE); *pSize += sizeof(valueMyComplexStruct.valueE);
		
	}
	return OpcUa_Good;
}

STATICITF OpcUa_StatusCode CDECL OpcUaProviderRead(RTS_HANDLE hProvider, OpcUaProvider_ReadContext *pContext)
{
	OpcUa_StatusCode uStatus = OpcUa_BadNodeIdUnknown;
	OpcUa_Variant *pValue = &pContext->pDataValue->Value;
	OpcUa_UInt32 uAttributeId = pContext->pNodeToRead->AttributeId;
	OpcUa_TimestampsToReturn eTimestampsToReturn = pContext->eTimestampsToReturn;
	const OpcUa_NodeId* pNode = &pContext->pNodeToRead->NodeId;

	do
	{
		if (pNode->IdentifierType != OpcUa_IdentifierType_Numeric)
			break;
		if (pNode->NamespaceIndex != s_NamespaceIndex)
			break;
		if (!(pNode->Identifier.Numeric == ProviderID_ValueA ||
			pNode->Identifier.Numeric == ProviderID_ValueB ||
			pNode->Identifier.Numeric == ProviderID_MyFolder ||
			pNode->Identifier.Numeric == ProviderID_MyFunction ||
			pNode->Identifier.Numeric == ProivderID_MyFunction_InputArguments ||
			pNode->Identifier.Numeric == ProivderID_MyFunction_OutputArguments ||
			pNode->Identifier.Numeric == ProviderID_ValueMyComplexStruct)
			)
			break;

		switch (uAttributeId)
		{
			/* Read attributes contained in all node classes */
			case OpcUa_Attributes_NodeId:
			{
				pValue->Datatype = (OpcUa_Byte)OpcUaType_NodeId;
				pValue->Value.NodeId = (OpcUa_NodeId*)CAL_SysMemAllocData(COMPONENT_NAME, sizeof(OpcUa_NodeId), NULL);
				CAL_OpcUaNodeIdInitialize(pValue->Value.NodeId);
				uStatus = CAL_OpcUaNodeIdCopyTo(&pContext->pNodeToRead->NodeId, pValue->Value.NodeId);
				break;
			}
			case OpcUa_Attributes_NodeClass:
			{
				pValue->Datatype = (OpcUa_Byte)OpcUaType_Int32;
				uStatus = OpcUa_Good;
				switch(pNode->Identifier.Numeric)
				{
					case ProviderID_MyFolder:
						pValue->Value.Int32 = (OpcUa_Int32)OpcUa_NodeClass_Object;
						break;
					case ProviderID_ValueA:
					case ProviderID_ValueB:
					case ProivderID_MyFunction_InputArguments:
					case ProivderID_MyFunction_OutputArguments:
					case ProviderID_ValueMyComplexStruct:
						pValue->Value.Int32 = (OpcUa_Int32)OpcUa_NodeClass_Variable;
						break;
					case ProviderID_MyFunction:
						pValue->Value.Int32 = (OpcUa_Int32)OpcUa_NodeClass_Method;
						break;
					case ProviderID_DataType_MyComplexStruct:
						pValue->Value.Int32 = (OpcUa_Int32)OpcUa_NodeClass_DataType;
						break;
					default:
						uStatus = OpcUa_BadAttributeIdInvalid;
						break;

				}
				break;
			}
			case OpcUa_Attributes_BrowseName:
			{
				pValue->Datatype = (OpcUa_Byte)OpcUaType_QualifiedName;
				pValue->Value.QualifiedName = (OpcUa_QualifiedName*)CAL_SysMemAllocData(COMPONENT_NAME, sizeof(OpcUa_QualifiedName), NULL);
				CAL_OpcUaQualifiedNameInitialize(pValue->Value.QualifiedName);
				pValue->Value.QualifiedName->NamespaceIndex = s_NamespaceIndex;
				switch (pNode->Identifier.Numeric)
				{
					case ProviderID_MyFolder:
						uStatus = CAL_OpcUaStringAttachReadOnly(&pValue->Value.QualifiedName->Name, "MyFolder");
						break;
					case ProviderID_ValueA:
						uStatus = CAL_OpcUaStringAttachReadOnly(&pValue->Value.QualifiedName->Name, "ValueA");
						break;
					case ProviderID_ValueB:
						uStatus = CAL_OpcUaStringAttachReadOnly(&pValue->Value.QualifiedName->Name, "ValueB");
						break;
					case ProivderID_MyFunction_InputArguments:
						pValue->Value.QualifiedName->NamespaceIndex = 0;
						uStatus = CAL_OpcUaStringAttachReadOnly(&pValue->Value.QualifiedName->Name, OpcUa_BrowseName_InputArguments);
						break;
					case ProivderID_MyFunction_OutputArguments:
						pValue->Value.QualifiedName->NamespaceIndex = 0;
						uStatus = CAL_OpcUaStringAttachReadOnly(&pValue->Value.QualifiedName->Name, OpcUa_BrowseName_OutputArguments);
						break;
					case ProviderID_MyFunction:
						uStatus = CAL_OpcUaStringAttachReadOnly(&pValue->Value.QualifiedName->Name, "MyFunction");
						break;
					case ProviderID_ValueMyComplexStruct:
						uStatus = CAL_OpcUaStringAttachReadOnly(&pValue->Value.QualifiedName->Name, "valueMyComplexStruct");
						break;
					default:
						pValue->Datatype = 0;
						CAL_OpcUaQualifiedNameClear(pValue->Value.QualifiedName);
						CAL_SysMemFreeData(COMPONENT_NAME, pValue->Value.QualifiedName);
						pValue->Value.QualifiedName = NULL;
						uStatus = OpcUa_BadAttributeIdInvalid;
						break;
				}
				break;
			}
			case OpcUa_Attributes_DisplayName:
			{
				pValue->Datatype = (OpcUa_Byte)OpcUaType_LocalizedText;
				pValue->Value.LocalizedText = (OpcUa_LocalizedText*)CAL_SysMemAllocData(COMPONENT_NAME, sizeof(OpcUa_LocalizedText), NULL);
				CAL_OpcUaLocalizedTextInitialize(pValue->Value.LocalizedText);
				CAL_OpcUaStringStrnCpy(&pValue->Value.LocalizedText->Locale, &s_ApplicationLocal, OPCUA_STRING_LENDONTCARE);
				switch (pNode->Identifier.Numeric)
				{
					case ProviderID_MyFolder:
						uStatus = CAL_OpcUaStringAttachReadOnly(&pValue->Value.LocalizedText->Text, "MyFolder");
						break;
					case ProviderID_ValueA:
						uStatus = CAL_OpcUaStringAttachReadOnly(&pValue->Value.LocalizedText->Text, "ValueA");
						break;
					case ProviderID_ValueB:
						uStatus = CAL_OpcUaStringAttachReadOnly(&pValue->Value.LocalizedText->Text, "ValueB");
						break;
					case ProivderID_MyFunction_InputArguments:
						uStatus = CAL_OpcUaStringAttachReadOnly(&pValue->Value.LocalizedText->Text, OpcUa_BrowseName_InputArguments);
						break;
					case ProivderID_MyFunction_OutputArguments:
						uStatus = CAL_OpcUaStringAttachReadOnly(&pValue->Value.LocalizedText->Text, OpcUa_BrowseName_OutputArguments);
						break;
					case ProviderID_MyFunction:
						uStatus = CAL_OpcUaStringAttachReadOnly(&pValue->Value.LocalizedText->Text, "MyFunction");
						break;
					case ProviderID_ValueMyComplexStruct:
						uStatus = CAL_OpcUaStringAttachReadOnly(&pValue->Value.LocalizedText->Text, "valueMyComplexStruct");
						break;
					default:
						pValue->Datatype = 0;
						CAL_OpcUaLocalizedTextClear(pValue->Value.LocalizedText);
						CAL_SysMemFreeData(COMPONENT_NAME, pValue->Value.LocalizedText);
						pValue->Value.QualifiedName = NULL;
						uStatus = OpcUa_BadAttributeIdInvalid;
						break;
				}
				break;
			}
			case OpcUa_Attributes_Description:
			{
				uStatus = OpcUa_BadAttributeIdInvalid;
				break;
			}
			case OpcUa_Attributes_WriteMask:
			{
				pValue->Datatype = (OpcUa_Byte)OpcUaType_UInt32;
				pValue->Value.UInt32 = 0;
				uStatus = OpcUa_Good;
				break;
			}
			case OpcUa_Attributes_UserWriteMask:
			{
				pValue->Datatype = (OpcUa_Byte)OpcUaType_UInt32;
				pValue->Value.UInt32 = 0;
				uStatus = OpcUa_Good;
				break;
			}
			case OpcUa_Attributes_Value:
			{
				OpcUa_Variant* pVariant = &pContext->pDataValue->Value;
				switch (pNode->Identifier.Numeric)
				{
					case ProviderID_ValueA:
						pVariant->ArrayType = OpcUa_VariantArrayType_Scalar;
						pVariant->Datatype = (OpcUa_Byte)OpcUaType_UInt32;
						pVariant->Value.UInt32 = *valueA;
						uStatus = OpcUa_Good;
						break;
					case ProviderID_ValueB:
						pVariant->ArrayType = OpcUa_VariantArrayType_Scalar;
						pVariant->Datatype = (OpcUa_Byte)OpcUaType_UInt32;
						pVariant->Value.UInt32 = *valueB;
						uStatus = OpcUa_Good;
						break;
					case ProivderID_MyFunction_InputArguments:
					{
						OpcUa_ExtensionObject* pExtValue = OpcUa_Null;

						pVariant->Value.Array.Value.ExtensionObjectArray = (OpcUa_ExtensionObject*)CAL_SysMemAllocData(COMPONENT_NAME, sizeof(OpcUa_ExtensionObject) * 2, NULL);
						if (pVariant->Value.Array.Value.ExtensionObjectArray != OpcUa_Null)
						{
							OpcUa_Argument* pArgument;
							pExtValue = pVariant->Value.Array.Value.ExtensionObjectArray;
							memset(pExtValue, 0, sizeof(OpcUa_ExtensionObject) * 2);

							pVariant->Datatype = OpcUaType_ExtensionObject;
							pVariant->ArrayType = OpcUa_VariantArrayType_Array;
							pVariant->Value.Array.Length = 2;

							uStatus = CAL_OpcUaEncodeableObjectCreateExtension(CAL_OpcUaGetEncodableObjectType(OpcUaId_Argument), &pExtValue[0], (OpcUa_Void**)&pArgument);
							if (uStatus == OpcUa_Good)
							{
								CAL_OpcUaStringAttachReadOnly(&pArgument->Name, "a");
								CAL_OpcUaStringAttachReadOnly(&pArgument->Description.Text, "First operand of addition");
								pArgument->DataType.Identifier.Numeric = OpcUaId_UInt32;
								pArgument->ValueRank = OpcUa_ValueRanks_Scalar;
								pArgument->NoOfArrayDimensions = 0;

							}

							uStatus = CAL_OpcUaEncodeableObjectCreateExtension(CAL_OpcUaGetEncodableObjectType(OpcUaId_Argument), &pExtValue[1], (OpcUa_Void**)&pArgument);
							if (uStatus == OpcUa_Good)
							{
								CAL_OpcUaStringAttachReadOnly(&pArgument->Name, "b");
								CAL_OpcUaStringAttachReadOnly(&pArgument->Description.Text, "Second operand of addition");
								pArgument->DataType.Identifier.Numeric = OpcUaId_UInt32;
								pArgument->ValueRank = OpcUa_ValueRanks_Scalar;
								pArgument->NoOfArrayDimensions = 0;

							}
						}
						break;
					}
					case ProivderID_MyFunction_OutputArguments:
					{
						OpcUa_ExtensionObject* pExtValue = OpcUa_Null;

						pVariant->Value.Array.Value.ExtensionObjectArray = (OpcUa_ExtensionObject*)CAL_SysMemAllocData(COMPONENT_NAME, sizeof(OpcUa_ExtensionObject) * 1, NULL);
						if (pVariant->Value.Array.Value.ExtensionObjectArray != OpcUa_Null)
						{
							OpcUa_Argument* pArgument;
							pExtValue = pVariant->Value.Array.Value.ExtensionObjectArray;
							memset(pExtValue, 0, sizeof(OpcUa_ExtensionObject) * 1);

							pVariant->Datatype = OpcUaType_ExtensionObject;
							pVariant->ArrayType = OpcUa_VariantArrayType_Array;
							pVariant->Value.Array.Length = 1;

							uStatus = CAL_OpcUaEncodeableObjectCreateExtension(CAL_OpcUaGetEncodableObjectType(OpcUaId_Argument), &pExtValue[0], (OpcUa_Void**)&pArgument);
							if (uStatus == OpcUa_Good)
							{
								CAL_OpcUaStringAttachReadOnly(&pArgument->Name, "res");
								CAL_OpcUaStringAttachReadOnly(&pArgument->Description.Text, "Result of operation");
								pArgument->DataType.Identifier.Numeric = OpcUaId_UInt32;
								pArgument->ValueRank = OpcUa_ValueRanks_Scalar;
								pArgument->NoOfArrayDimensions = 0;

							}
						}
						break;
					}
					case ProviderID_ValueMyComplexStruct:
					{
						OpcUa_Byte* pBuffer = NULL;
						pVariant->Datatype = (OpcUa_Byte)OpcUaType_ExtensionObject;
						pVariant->ArrayType = OpcUa_VariantArrayType_Scalar;
						pVariant->Value.ExtensionObject = (OpcUa_ExtensionObject*)CAL_SysMemAllocData(COMPONENT_NAME, sizeof(OpcUa_ExtensionObject), NULL);
						pVariant->Value.ExtensionObject->TypeId.NodeId.NamespaceIndex = s_NamespaceIndex;
						pVariant->Value.ExtensionObject->TypeId.NodeId.Identifier.Numeric = ProviderID_DataType_MyComplexStruct_Encoding;
						pVariant->Value.ExtensionObject->Encoding = OpcUa_ExtensionObjectEncoding_Binary;
						pVariant->Value.ExtensionObject->Body.Binary.Length = 0;
						pVariant->Value.ExtensionObject->Body.Binary.Data = CAL_SysMemAllocData(COMPONENT_NAME, sizeof(valueMyComplexStruct), NULL);
						pBuffer = pVariant->Value.ExtensionObject->Body.Binary.Data;
						memset(pBuffer, 0, pVariant->Value.ExtensionObject->Body.Binary.Length);
						memcpy(pBuffer, &valueMyComplexStruct.valueA, sizeof(valueMyComplexStruct.valueA)); pBuffer += sizeof(valueMyComplexStruct.valueA); pVariant->Value.ExtensionObject->Body.Binary.Length += sizeof(valueMyComplexStruct.valueA);
						memcpy(pBuffer, &valueMyComplexStruct.valueB, sizeof(valueMyComplexStruct.valueB)); pBuffer += sizeof(valueMyComplexStruct.valueB); pVariant->Value.ExtensionObject->Body.Binary.Length += sizeof(valueMyComplexStruct.valueB);
						memcpy(pBuffer, &valueMyComplexStruct.valueC, sizeof(valueMyComplexStruct.valueC)); pBuffer += sizeof(valueMyComplexStruct.valueC); pVariant->Value.ExtensionObject->Body.Binary.Length += sizeof(valueMyComplexStruct.valueC);
						memcpy(pBuffer, &valueMyComplexStruct.valueD, sizeof(valueMyComplexStruct.valueD)); pBuffer += sizeof(valueMyComplexStruct.valueD); pVariant->Value.ExtensionObject->Body.Binary.Length += sizeof(valueMyComplexStruct.valueD);
						memcpy(pBuffer, &valueMyComplexStruct.valueE, sizeof(valueMyComplexStruct.valueE)); pBuffer += sizeof(valueMyComplexStruct.valueE); pVariant->Value.ExtensionObject->Body.Binary.Length += sizeof(valueMyComplexStruct.valueE);
						uStatus = OpcUa_Good;
						break;
					}
					default:
						uStatus = OpcUa_BadAttributeIdInvalid;
						break;
				}

				if (uStatus == OpcUa_Good)
				{
					if (eTimestampsToReturn == OpcUa_TimestampsToReturn_Both || eTimestampsToReturn == OpcUa_TimestampsToReturn_Server)
					{
						pContext->pDataValue->ServerTimestamp = CAL_OpcUaDateTimeUtcNow();
					}
					if (eTimestampsToReturn == OpcUa_TimestampsToReturn_Both || eTimestampsToReturn == OpcUa_TimestampsToReturn_Source)
					{
						pContext->pDataValue->SourceTimestamp = pContext->pDataValue->ServerTimestamp;
					}
				}
				break;
			}
			case OpcUa_Attributes_DataType:

				pValue->Datatype = (OpcUa_Byte)OpcUaType_NodeId;
				pValue->ArrayType = OpcUa_VariantArrayType_Scalar;
				pValue->Value.NodeId = (OpcUa_NodeId*)CAL_SysMemAllocData(COMPONENT_NAME, sizeof(OpcUa_NodeId), NULL);
				CAL_OpcUaNodeIdInitialize(pValue->Value.NodeId);
				pValue->Value.NodeId->IdentifierType = OpcUa_IdentifierType_Numeric;
				pValue->Value.NodeId->NamespaceIndex = 0;

				switch (pNode->Identifier.Numeric)
				{
					case ProviderID_ValueA:
						pValue->Value.NodeId->Identifier.Numeric = (OpcUa_UInt32)OpcUaId_UInt32;
						uStatus = OpcUa_Good;
						break;
					case ProviderID_ValueB:
						pValue->Value.NodeId->Identifier.Numeric = (OpcUa_UInt32)OpcUaId_UInt32;
						uStatus = OpcUa_Good;
						break;
					case ProivderID_MyFunction_InputArguments:
						pValue->Value.NodeId->Identifier.Numeric = (OpcUa_UInt32)OpcUaId_Argument;
						uStatus = OpcUa_Good;
						break;
					case ProivderID_MyFunction_OutputArguments:
						pValue->Value.NodeId->Identifier.Numeric = (OpcUa_UInt32)OpcUaId_Argument;
						uStatus = OpcUa_Good;
						break;
					case ProviderID_ValueMyComplexStruct:
						pValue->Value.NodeId->NamespaceIndex = s_NamespaceIndex;
						pValue->Value.NodeId->Identifier.Numeric = (OpcUa_UInt32)ProviderID_DataType_MyComplexStruct;
						uStatus = OpcUa_Good;
						break;
					default:
						pValue->Datatype = 0;
						CAL_SysMemFreeData(COMPONENT_NAME, pValue->Value.NodeId);
						pValue->Value.NodeId = NULL;
						uStatus = OpcUa_BadAttributeIdInvalid;
						break;
				}
				break;
			case OpcUa_Attributes_ValueRank:
				if (pNode->Identifier.Numeric == ProviderID_MyFolder)
				{
					uStatus = OpcUa_BadAttributeIdInvalid;
					break;
				}
				pValue->Datatype = (OpcUa_Byte)OpcUaType_Int32;
				pValue->ArrayType = OpcUa_VariantArrayType_Scalar;
				pValue->Value.Int32 = OpcUa_ValueRanks_Scalar;
				uStatus = OpcUa_Good;
				break;
			case OpcUa_Attributes_AccessLevel:
				if (pNode->Identifier.Numeric == ProviderID_MyFolder)
				{
					uStatus = OpcUa_BadAttributeIdInvalid;
					break;
				}
				pValue->Datatype = (OpcUa_Byte)OpcUaType_Byte;
				pValue->ArrayType = OpcUa_VariantArrayType_Scalar;
				pValue->Value.Byte = OpcUa_AccessLevels_CurrentRead | OpcUa_AccessLevels_CurrentWrite;
				uStatus = OpcUa_Good;
				break;
			case OpcUa_Attributes_UserAccessLevel:
				if (pNode->Identifier.Numeric == ProviderID_MyFolder)
				{
					uStatus = OpcUa_BadAttributeIdInvalid;
					break;
				}
				pValue->Datatype = (OpcUa_Byte)OpcUaType_Byte;
				pValue->ArrayType = OpcUa_VariantArrayType_Scalar;
				pValue->Value.Byte = OpcUa_AccessLevels_CurrentRead | OpcUa_AccessLevels_CurrentWrite;
				uStatus = OpcUa_Good;
				break;
			case OpcUa_Attributes_Historizing:
				if (pNode->Identifier.Numeric == ProviderID_MyFolder)
				{
					uStatus = OpcUa_BadAttributeIdInvalid;
					break;
				}
				pValue->Datatype = (OpcUa_Byte)OpcUaType_Boolean;
				pValue->ArrayType = OpcUa_VariantArrayType_Scalar;
				pValue->Value.Boolean = OpcUa_False;
				uStatus = OpcUa_Good;
				break;
			case OpcUa_Attributes_EventNotifier:
				pValue->Datatype = (OpcUa_Byte)OpcUaType_Byte;
				pValue->ArrayType = OpcUa_VariantArrayType_Scalar;
				if (pNode->Identifier.Numeric == ProviderID_MyFolder)
					pValue->Value.Byte = OpcUa_EventNotifiers_SubscribeToEvents;
				else
					pValue->Value.Byte = OpcUa_EventNotifiers_None;
				uStatus = OpcUa_Good;
				break;
			case OpcUa_Attributes_Executable:
			case OpcUa_Attributes_UserExecutable:
				if (pNode->Identifier.Numeric == ProviderID_MyFunction)
				{
					pValue->Datatype = (OpcUa_Byte)OpcUaType_Boolean;
					pValue->ArrayType = OpcUa_VariantArrayType_Scalar;
					pValue->Value.Byte = OpcUa_True;
					uStatus = OpcUa_Good;
					break;
				}
			case OpcUa_Attributes_IsAbstract:
				pValue->Datatype = (OpcUa_Byte)OpcUaType_Boolean;
				pValue->ArrayType = OpcUa_VariantArrayType_Scalar;
				pValue->Value.Boolean = OpcUa_False;
				uStatus = OpcUa_Good;
				break;
			default:
				uStatus = OpcUa_BadAttributeIdInvalid;
				break;
		}
	} while (0);
	pContext->pDataValue->StatusCode = uStatus;
	return uStatus;
}

STATICITF OpcUa_StatusCode CDECL OpcUaProviderWrite(RTS_HANDLE hProvider, OpcUaProvider_WriteContext *pContext)
{
	OpcUa_StatusCode uStatus = OpcUa_BadNodeIdUnknown;
	const OpcUa_NodeId* pNode = &pContext->pNodeToWrite->NodeId;
	OpcUa_UInt32 attributeId = pContext->pNodeToWrite->AttributeId;
	const OpcUa_DataValue* pValue = &pContext->pNodeToWrite->Value;
	do
	{
		if (pNode->IdentifierType != OpcUa_IdentifierType_Numeric)
			break;
		if (pNode->NamespaceIndex != s_NamespaceIndex)
			break;
		if (pNode->Identifier.Numeric != 0 && pNode->Identifier.Numeric != 1)
			break;
		switch (attributeId)
		{
			case OpcUa_Attributes_Value:
			{
				if (pValue->Value.Datatype == (OpcUa_Byte)OpcUaType_UInt32)
				{
					if (pNode->Identifier.Numeric == 0)
						*valueA = pValue->Value.Value.UInt32;
					if (pNode->Identifier.Numeric == 1)
						*valueB = pValue->Value.Value.UInt32;
					uStatus = OpcUa_Good;
				}
				else
				{
					uStatus = OpcUa_BadNotWritable;
				}
			}
			break;
			default:
				uStatus = OpcUa_BadNotWritable;
				break;
		}
	} while (0);
	return uStatus;
}

#if 0
STATICITF_DEF OpcUa_StatusCode CDECL OpcUaProviderMethodCall(RTS_HANDLE hProvider, OpcUaProvider_MethodCallContext *pContext)
{
	OpcUa_StatusCode uStatus = OpcUa_BadNodeIdUnknown;
	OpcUa_UInt32 a = 0;
	OpcUa_UInt32 b = 0;
	OpcUa_UInt32 res = 0;
	do
	{
		if (pContext->pMethodToCall->ObjectId.NamespaceIndex != 0 || pContext->pMethodToCall->ObjectId.Identifier.Numeric != OpcUaId_ObjectsFolder)
			break;
		if (pContext->pMethodToCall->MethodId.NamespaceIndex != s_NamespaceIndex || pContext->pMethodToCall->MethodId.Identifier.Numeric != ProviderID_MyFunction)
			break;
		if (pContext->pMethodToCall->NoOfInputArguments != 2)
		{
			uStatus = OpcUa_BadInvalidArgument;
			break;
		}

		uStatus = OpcUa_Good;
		pContext->pMethodCallResult->InputArgumentResults = CAL_SysMemAllocData(COMPONENT_NAME, sizeof(OpcUa_StatusCode) * 2, NULL);
		pContext->pMethodCallResult->NoOfInputArgumentResults = 2;

		if (pContext->pMethodToCall->InputArguments[0].ArrayType != OpcUa_VariantArrayType_Scalar || pContext->pMethodToCall->InputArguments[0].Datatype != OpcUaType_UInt32)
		{
			pContext->pMethodCallResult->InputArgumentResults[0] = OpcUa_BadInvalidArgument;
			uStatus = OpcUa_BadInvalidArgument;
		}
			
		if (pContext->pMethodToCall->InputArguments[1].ArrayType != OpcUa_VariantArrayType_Scalar || pContext->pMethodToCall->InputArguments[1].Datatype != OpcUaType_UInt32)
		{
			pContext->pMethodCallResult->InputArgumentResults[1] = OpcUa_BadInvalidArgument;
			uStatus = OpcUa_BadInvalidArgument;
		}
		if (uStatus != OpcUa_Good)
			break;

		a = pContext->pMethodToCall->InputArguments[0].Value.UInt32;
		b = pContext->pMethodToCall->InputArguments[1].Value.UInt32;
		res = a + b;

		pContext->pMethodCallResult->StatusCode = OpcUa_Good;
		pContext->pMethodCallResult->NoOfOutputArguments = 1;
		pContext->pMethodCallResult->OutputArguments = CAL_SysMemAllocData(COMPONENT_NAME, sizeof(OpcUa_Variant), NULL);
		pContext->pMethodCallResult->OutputArguments[0].ArrayType = OpcUa_VariantArrayType_Scalar;
		pContext->pMethodCallResult->OutputArguments[0].Datatype = OpcUaType_UInt32;
		pContext->pMethodCallResult->OutputArguments[0].Value.UInt32 = res;
		uStatus = OpcUa_Good;



	} while (0);
	
	return uStatus;
}
#endif


/* Checks if the needed amount of nodes can be added and adds them to the result.*/
static OpcUa_Boolean BrowseContextCheckAddNodes(OpcUaProvider_BrowseContext *pContext, OpcUa_UInt32 ui32NumToAdd)
{
	if ((pContext->ui32NumNodes + ui32NumToAdd) <= pContext->ui32MaxNumOfResults)
	{
		pContext->ui32NumNodes += ui32NumToAdd;
		return OpcUa_True;
	}
	else
	{
		return OpcUa_False;
	}
}

/* Checks if the needed amount of nodes can be added to the result. */
static OpcUa_Boolean BrowseContextCheckNodes(OpcUaProvider_BrowseContext* pContext, OpcUa_UInt32 ui32NumOfNodes)
{
	if ((pContext->ui32CurrentNode + ui32NumOfNodes) <= pContext->ui32MaxNumOfResults)
	{
		return OpcUa_True;
	}
	else
	{
		return OpcUa_False;
	}
}

static OpcUa_Void BrowseContextSetUnfinishedFlag(OpcUaProvider_BrowseContext* pContext)
{
	pContext->bFinished = OpcUa_False;
	pContext->hProviderContinueInfo = NULL;
}

static OpcUa_ReferenceDescription* BrowseContextGetNextRefDesc(OpcUaProvider_BrowseContext* pContext)
{
	OpcUa_ReferenceDescription* pResult = OpcUa_Null;
	if (pContext->ui32CurrentNode <= pContext->ui32NumNodes)
	{
		pResult = &pContext->pReference[pContext->ui32CurrentNode];
		pContext->ui32CurrentNode++;
	}
	return pResult;
}
