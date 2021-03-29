/**
 * <interfacename>CmpIecVarAccess_Implementation</interfacename>
 * <description></description>
 *
 * <copyright></copyright>
 */

SET_INTERFACE_NAME(`CmpIecVarAccess_Implementation')
SET_PLACEHOLDER_NAME(`CmpIecVarAccess Implementation')

REF_ITF(`CmpIecVarAccessItf.m4')

/** EXTERN LIB SECTION BEGIN **/
/*  Comments are ignored for m4 compiler so restructured text can be used. changecom(`/*', `*/') */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description>iecvaraccbrowsedown2</description>
 */
typedef struct tagiecvaraccbrowsedown2_struct
{
	RTS_IEC_HANDLE hInterface;			/* VAR_INPUT */	
	IBaseTreeNode *hNode;				/* VAR_INPUT */	
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	IBaseTreeNode *IecVarAccBrowseDown2;	/* VAR_OUTPUT */	
} iecvaraccbrowsedown2_struct;

DEF_API(`void',`CDECL',`iecvaraccbrowsedown2',`(iecvaraccbrowsedown2_struct *p)',1,0,0x03050F00)

/**
 * <description>iecvaraccbrowsegetnext2</description>
 */
typedef struct tagiecvaraccbrowsegetnext2_struct
{
	RTS_IEC_HANDLE hInterface;			/* VAR_INPUT */	
	IBaseTreeNode *hNode;				/* VAR_INPUT */	
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	IBaseTreeNode *IecVarAccBrowseGetNext2;	/* VAR_OUTPUT */	
} iecvaraccbrowsegetnext2_struct;

DEF_API(`void',`CDECL',`iecvaraccbrowsegetnext2',`(iecvaraccbrowsegetnext2_struct *p)',1,0,0x03050F00)

/**
 * <description>iecvaraccbrowserecursive</description>
 */
typedef struct tagiecvaraccbrowserecursive_struct
{
	RTS_IEC_HANDLE hInterface;			/* VAR_INPUT */	
	IBaseTreeNode *hNode;				/* VAR_INPUT */	
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	
	RTS_IEC_BYTE *pfBrowseCallback;		/* VAR_INPUT */	
	RTS_IEC_BYTE *pUserParameter;		/* VAR_INPUT */	
	RTS_IEC_RESULT IecVarAccBrowseRecursive;	/* VAR_OUTPUT */	
} iecvaraccbrowserecursive_struct;

DEF_API(`void',`CDECL',`iecvaraccbrowserecursive',`(iecvaraccbrowserecursive_struct *p)',1,0,0x03050F00)

/**
 * <description>iecvaraccbrowseup2</description>
 */
typedef struct tagiecvaraccbrowseup2_struct
{
	RTS_IEC_HANDLE hInterface;			/* VAR_INPUT */	
	IBaseTreeNode *hNode;				/* VAR_INPUT */	
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	IBaseTreeNode *IecVarAccBrowseUp2;	/* VAR_OUTPUT */	
} iecvaraccbrowseup2_struct;

DEF_API(`void',`CDECL',`iecvaraccbrowseup2',`(iecvaraccbrowseup2_struct *p)',1,0,0x03050F00)

/**
 * <description>iecvaraccexitvarinfo</description>
 */
typedef struct tagiecvaraccexitvarinfo_struct
{
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	
	RTS_IEC_RESULT IecVarAccExitVarInfo;	/* VAR_OUTPUT */	
} iecvaraccexitvarinfo_struct;

DEF_API(`void',`CDECL',`iecvaraccexitvarinfo',`(iecvaraccexitvarinfo_struct *p)',1,0,0x03050F00)

/**
 * <description>iecvaraccgetfirstinterface</description>
 */
typedef struct tagiecvaraccgetfirstinterface_struct
{
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	IIecVarAccess3 *IecVarAccGetFirstInterface;	/* VAR_OUTPUT */	
} iecvaraccgetfirstinterface_struct;

DEF_API(`void',`CDECL',`iecvaraccgetfirstinterface',`(iecvaraccgetfirstinterface_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xDAF18C6C),0x03050F00)

/**
 * <description>iecvaraccgetfirstinterface2</description>
 */
typedef struct tagiecvaraccgetfirstinterface2_struct
{
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	IBase *IecVarAccGetFirstInterface2;	/* VAR_OUTPUT */	
} iecvaraccgetfirstinterface2_struct;

DEF_API(`void',`CDECL',`iecvaraccgetfirstinterface2',`(iecvaraccgetfirstinterface2_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x35A559A4),0x03050F00)

/**
 * <description>iecvaraccgetnextinterface</description>
 */
typedef struct tagiecvaraccgetnextinterface_struct
{
	IIecVarAccess3 *pIPrev;				/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	IIecVarAccess3 *IecVarAccGetNextInterface;	/* VAR_OUTPUT */	
} iecvaraccgetnextinterface_struct;

DEF_API(`void',`CDECL',`iecvaraccgetnextinterface',`(iecvaraccgetnextinterface_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x7143BBE4),0x03050F00)

/**
 * <description>iecvaraccgetnextinterface2</description>
 */
typedef struct tagiecvaraccgetnextinterface2_struct
{
	IBase *pIPrev;						/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	IBase *IecVarAccGetNextInterface2;	/* VAR_OUTPUT */	
} iecvaraccgetnextinterface2_struct;

DEF_API(`void',`CDECL',`iecvaraccgetnextinterface2',`(iecvaraccgetnextinterface2_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xDCA77F90),0x03050F00)

/**
 * <description>iecvaraccgetnode4</description>
 */
typedef struct tagiecvaraccgetnode4_struct
{
	RTS_IEC_STRING *pszPath;			/* VAR_INPUT */	
	RTS_IEC_HANDLE *phInterface;		/* VAR_INPUT */	
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	IBaseTreeNode *IecVarAccGetNode4;	/* VAR_OUTPUT */	
} iecvaraccgetnode4_struct;

DEF_API(`void',`CDECL',`iecvaraccgetnode4',`(iecvaraccgetnode4_struct *p)',1,0,0x03050F00)

/**
 * <description>iecvaraccgetnodefullpath4</description>
 */
typedef struct tagiecvaraccgetnodefullpath4_struct
{
	RTS_IEC_HANDLE hInterface;			/* VAR_INPUT */	
	IBaseTreeNode *hNode;				/* VAR_INPUT */	
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	
	RTS_IEC_STRING *pszPath;			/* VAR_INPUT */	
	RTS_IEC_DINT iMaxPath;				/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_DINT IecVarAccGetNodeFullPath4;	/* VAR_OUTPUT */	
} iecvaraccgetnodefullpath4_struct;

DEF_API(`void',`CDECL',`iecvaraccgetnodefullpath4',`(iecvaraccgetnodefullpath4_struct *p)',1,0,0x03050F00)

/**
 * <description>iecvaraccgetnodename4</description>
 */
typedef struct tagiecvaraccgetnodename4_struct
{
	RTS_IEC_HANDLE hInterface;			/* VAR_INPUT */	
	IBaseTreeNode *hNode;				/* VAR_INPUT */	
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	
	RTS_IEC_STRING *pszNodeName;		/* VAR_INPUT */	
	RTS_IEC_UDINT nNodeNameLen;			/* VAR_INPUT */	
	RTS_IEC_RESULT IecVarAccGetNodeName4;	/* VAR_OUTPUT */	
} iecvaraccgetnodename4_struct;

DEF_API(`void',`CDECL',`iecvaraccgetnodename4',`(iecvaraccgetnodename4_struct *p)',1,0,0x03050F00)

/**
 * <description>iecvaraccgetsymbolsetmask</description>
 */
typedef struct tagiecvaraccgetsymbolsetmask_struct
{
	RTS_IEC_HANDLE hUser;				/* VAR_INPUT */	
	RTS_IEC_HANDLE hInterface;			/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_DWORD IecVarAccGetSymbolSetMask;	/* VAR_OUTPUT */	
} iecvaraccgetsymbolsetmask_struct;

DEF_API(`void',`CDECL',`iecvaraccgetsymbolsetmask',`(iecvaraccgetsymbolsetmask_struct *p)',1,0xCD15F68E,0x03050F00)

/**
 * <description>iecvaraccinitvarinfo</description>
 */
typedef struct tagiecvaraccinitvarinfo_struct
{
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	/* Pointer to the variable information struct. After using this method for initialization,
 the struct also needs to be freed with IecVarAccExitVarInfo() to prevent memory leaks in
 the runtime data structures. */
	RTS_IEC_UINT nSizeOfVarInfo;		/* VAR_INPUT */	
	RTS_IEC_RESULT IecVarAccInitVarInfo;	/* VAR_OUTPUT */	
} iecvaraccinitvarinfo_struct;

DEF_API(`void',`CDECL',`iecvaraccinitvarinfo',`(iecvaraccinitvarinfo_struct *p)',1,0,0x03050F00)

/**
 * <description>iecvaraccinitvarinfo2</description>
 */
typedef struct tagiecvaraccinitvarinfo2_struct
{
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	/* Pointer to the variable information struct. After using this method for initialization,
 the struct also needs to be freed with IecVarAccExitVarInfo() to prevent memory leaks in
 the runtime data structures. */
	RTS_IEC_UINT nSizeOfVarInfo;		/* VAR_INPUT */	
	RTS_IEC_HANDLE hUser;				/* VAR_INPUT */	
	RTS_IEC_RESULT IecVarAccInitVarInfo2;	/* VAR_OUTPUT */	
} iecvaraccinitvarinfo2_struct;

DEF_API(`void',`CDECL',`iecvaraccinitvarinfo2',`(iecvaraccinitvarinfo2_struct *p)',1,RTSITF_GET_SIGNATURE(0x3533B10B, 0x07C98E8C),0x03050F00)

/**
 * <description>iecvaraccinvalidatenode</description>
 */
typedef struct tagiecvaraccinvalidatenode_struct
{
	RTS_IEC_HANDLE hNode;				/* VAR_INPUT */	
	RTS_IEC_RESULT IecVarAccInvalidateNode;	/* VAR_OUTPUT */	
} iecvaraccinvalidatenode_struct;

DEF_API(`void',`CDECL',`iecvaraccinvalidatenode',`(iecvaraccinvalidatenode_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x0C905F23),0x03050F00)

/**
 * Signature deactivated because of Interface type in RtsBrowseInfo
 */
typedef struct tagiecvaraccnodeinfoaddbrowseinfo_struct
{
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	/* Pointer to the variable information.
 Attention: This needs to be initialized with IecVarAccInitVarInfo() or the function
 will return an error code. It also needs to be freed with IecVarAccExitVarInfo() to
 prevent memory leaks. */
	RtsBrowseInfo *pBrowseInfoData;		/* VAR_INPUT */	/* If this pointer is non-null, the runtime will copy the data into the new buffer.
 If this pointer is null, the new buffer memory will be cleared to zero. */
	RTS_IEC_RESULT IecVarAccNodeInfoAddBrowseInfo;	/* VAR_OUTPUT */	
} iecvaraccnodeinfoaddbrowseinfo_struct;

DEF_API(`void',`CDECL',`iecvaraccnodeinfoaddbrowseinfo',`(iecvaraccnodeinfoaddbrowseinfo_struct *p)',1,0,0x03050F00)

/**
 * <description>iecvaraccnodeinfoaddreference</description>
 */
typedef struct tagiecvaraccnodeinfoaddreference_struct
{
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	/* Pointer to the variable information.
 Attention: This needs to be initialized with IecVarAccInitVarInfo() or the function
 will return an error code. It also needs to be freed with IecVarAccExitVarInfo() to
 prevent memory leaks. */
	RTS_IEC_BYTE *pReferenceInfoData;	/* VAR_INPUT */	/* If this pointer is non-null, the runtime will copy the data into the new buffer.
 If this pointer is null, the new buffer memory will be cleared to zero. */
	RTS_IEC_XWORD nInfoSize;			/* VAR_INPUT */	/* The size of the memory to allocate. */
	RTS_IEC_BYTE **pNewReferenceInfo;	/* VAR_INPUT */	/* If this pointer is non-null, the runtime will store the address of
 the allocated block in this pointer. (This is the same as a subsequent
 call to VarAccNodeInfoGetReference() shall return.) */
	RTS_IEC_RESULT IecVarAccNodeInfoAddReference;	/* VAR_OUTPUT */	
} iecvaraccnodeinfoaddreference_struct;

DEF_API(`void',`CDECL',`iecvaraccnodeinfoaddreference',`(iecvaraccnodeinfoaddreference_struct *p)',1,RTSITF_GET_SIGNATURE(0xB66D74DC, 0x54D1E739),0x03050F00)

/**
 * Signature deactivated because of Interface type in RtsBrowseInfo
 */
typedef struct tagiecvaraccnodeinfogetbrowseinfo_struct
{
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	
	RtsBrowseInfo *pLast;				/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RtsBrowseInfo *IecVarAccNodeInfoGetBrowseInfo;	/* VAR_OUTPUT */	
} iecvaraccnodeinfogetbrowseinfo_struct;

DEF_API(`void',`CDECL',`iecvaraccnodeinfogetbrowseinfo',`(iecvaraccnodeinfogetbrowseinfo_struct *p)',1,0,0x03050F00)

/**
 * <description>iecvaraccnodeinfogetreference</description>
 */
typedef struct tagiecvaraccnodeinfogetreference_struct
{
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_BYTE *IecVarAccNodeInfoGetReference;	/* VAR_OUTPUT */	
} iecvaraccnodeinfogetreference_struct;

DEF_API(`void',`CDECL',`iecvaraccnodeinfogetreference',`(iecvaraccnodeinfogetreference_struct *p)',1,RTSITF_GET_SIGNATURE(0x4ABE0CEB, 0x84253FCA),0x03050F00)

/**
 * <description>iecvaraccnodeinforemovebrowseinfo</description>
 */
typedef struct tagiecvaraccnodeinforemovebrowseinfo_struct
{
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	
	RTS_IEC_RESULT IecVarAccNodeInfoRemoveBrowseInfo;	/* VAR_OUTPUT */	
} iecvaraccnodeinforemovebrowseinfo_struct;

DEF_API(`void',`CDECL',`iecvaraccnodeinforemovebrowseinfo',`(iecvaraccnodeinforemovebrowseinfo_struct *p)',1,RTSITF_GET_SIGNATURE(0x43FC9F64, 0xC2D7CEF9),0x03050F00)

/**
 * <description>iecvaraccnodeinforemovereference</description>
 */
typedef struct tagiecvaraccnodeinforemovereference_struct
{
	VariableInformationStruct3 *pVariableInformation;	/* VAR_INPUT */	
	RTS_IEC_RESULT IecVarAccNodeInfoRemoveReference;	/* VAR_OUTPUT */	
} iecvaraccnodeinforemovereference_struct;

DEF_API(`void',`CDECL',`iecvaraccnodeinforemovereference',`(iecvaraccnodeinforemovereference_struct *p)',1,RTSITF_GET_SIGNATURE(0xAAD90063, 0x725A147D),0x03050F00)

/**
 * <description>iecvaraccregisterinstance</description>
 */
typedef struct tagiecvaraccregisterinstance_struct
{
	IIecVarAccess *pIIecVarAccess;		/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_HANDLE IecVarAccRegisterInstance;	/* VAR_OUTPUT */	
} iecvaraccregisterinstance_struct;

DEF_API(`void',`CDECL',`iecvaraccregisterinstance',`(iecvaraccregisterinstance_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x2838418D),0x03050F00)

/**
 * <description>iecvaraccregisterinstance2</description>
 */
typedef struct tagiecvaraccregisterinstance2_struct
{
	IIecVarAccess2 *pIIecVarAccess2;	/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_HANDLE IecVarAccRegisterInstance2;	/* VAR_OUTPUT */	
} iecvaraccregisterinstance2_struct;

DEF_API(`void',`CDECL',`iecvaraccregisterinstance2',`(iecvaraccregisterinstance2_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x12CBCF4F),0x03050F00)

/**
 * <description>iecvaraccregisterinstance3</description>
 */
typedef struct tagiecvaraccregisterinstance3_struct
{
	IIecVarAccess3 *pIIecVarAccess3;	/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_HANDLE IecVarAccRegisterInstance3;	/* VAR_OUTPUT */	
} iecvaraccregisterinstance3_struct;

DEF_API(`void',`CDECL',`iecvaraccregisterinstance3',`(iecvaraccregisterinstance3_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xC1E3F2D6),0x03050F00)

/**
 * <description>iecvaraccregisterinstancebase</description>
 */
typedef struct tagiecvaraccregisterinstancebase_struct
{
	IBase *pIBase;						/* VAR_INPUT */	
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	
	RTS_IEC_HANDLE IecVarAccRegisterInstanceBase;	/* VAR_OUTPUT */	
} iecvaraccregisterinstancebase_struct;

DEF_API(`void',`CDECL',`iecvaraccregisterinstancebase',`(iecvaraccregisterinstancebase_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xCD8685B0),0x03050F00)

/**
 * <description>iecvaraccsetsymbolconfigcrc</description>
 */
typedef struct tagiecvaraccsetsymbolconfigcrc_struct
{
	RTS_IEC_HANDLE hInstance;			/* VAR_INPUT */	
	RTS_IEC_UDINT udiCrc;				/* VAR_INPUT */	
	RTS_IEC_RESULT IecVarAccSetSymbolconfigCrc;	/* VAR_OUTPUT */	
} iecvaraccsetsymbolconfigcrc_struct;

DEF_API(`void',`CDECL',`iecvaraccsetsymbolconfigcrc',`(iecvaraccsetsymbolconfigcrc_struct *p)',1,0xFDCEC8DA,0x03050F00)

/**
 * <description>iecvaraccunregisterinstance</description>
 */
typedef struct tagiecvaraccunregisterinstance_struct
{
	RTS_IEC_HANDLE hInstance;			/* VAR_INPUT */	
	RTS_IEC_RESULT IecVarAccUnregisterInstance;	/* VAR_OUTPUT */	
} iecvaraccunregisterinstance_struct;

DEF_API(`void',`CDECL',`iecvaraccunregisterinstance',`(iecvaraccunregisterinstance_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xEDB8227D),0x03050F00)

/**
 * <description>iecvaraccupdatesymbolsets</description>
 */
typedef struct tagiecvaraccupdatesymbolsets_struct
{
	RTS_IEC_HANDLE hInterface;			/* VAR_INPUT */	
	IecVarAccSymbolSetDescription *pSymbolsSets;	/* VAR_INPUT */	
	RTS_IEC_UDINT numOfSymbolsSets;		/* VAR_INPUT */	
	RTS_IEC_RESULT IecVarAccUpdateSymbolSets;	/* VAR_OUTPUT */	
} iecvaraccupdatesymbolsets_struct;

DEF_API(`void',`CDECL',`iecvaraccupdatesymbolsets',`(iecvaraccupdatesymbolsets_struct *p)',1,0xF81481F0,0x03050F00)

#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/

