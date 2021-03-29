/**
 * <name>CmpUserDBTemplate.c</name>
 * <description> 
 * <p>An example on how to implement the user, group, and object databases and their configuration for the user management.</p>
 * <p>Configuration interfaces are optional and in case they are not needed, they do not need to be initialized, registered and the whole implementation section can be removed.</p>
 * To change a password, at least CmpUserDBConfig interface must be implemented.
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */

#ifndef STATICITF_DEF
	#define STATICITF_DEF	static
#endif

#include "CmpStd.h"
#include "CmpUserDBTemplateDep.h"

#define DIM(a) (sizeof(a)/sizeof(a[0]))
#define PWFNAME SYSFILE_INVISIBLE_FILENAME_PREFIX "pwhash.dat"

#ifndef	USERDB_TEMPLATE_USERLIST
	#define USERDB_TEMPLATE_USERLIST		{\
												{ "Administrator", "Administrator" },\
												{ "Developer", "Developer"},\
												{ "Service", "Service"},\
												{ "Watch", "Watch"},\
												{NULL, NULL} \
											}
#endif

typedef struct tagUserDBEntry
{
	char* pszUser;		/* User name */
	char* pszPassword;	/* The password itself */
} UserDBEntry;

typedef struct tagGroupDBEntry
{
	char* pszGroup;			/*Group name */
	const UserDBEntry **pUserList;	/* List of all users that are needed by this group. */
} GroupDBEntry;

typedef struct tagGroupRightsEntry
{
	RTS_HANDLE hGroup; /* group handle */
	RTS_UI32 ulRights; /* granted rights */
	RTS_UI32 ulDeniedRights; /* denied rights */
} GroupRightsEntry;

typedef struct tagObjectEntry
{
	char *pszObject; /* object name */
	RTS_HANDLE hGroupRightsList; /* list of group rights (GroupRightsEntry) */
	RTS_UI32 ulID; /* object ID */
	RTS_UI32 ulUsedRights; /* rights the object uses */
	RTS_UI32 ulProperties; /* properties of the object */
} ObjectEntry;

static const UserDBEntry s_UserList[] = USERDB_TEMPLATE_USERLIST;

static RTS_UI8  s_UserPwHashPool[DIM(s_UserList)-1][CRYPTMD5_KEY_LENGTH];
static RTS_UI32 s_UserPwSaltPool[DIM(s_UserList)-1];

static const UserDBEntry* s_UserGroup_Administrator[] = {
	(const UserDBEntry*)&s_UserList[0],
	NULL
};

static const UserDBEntry* s_UserGroup_Developer[] = {
	(const UserDBEntry*)&s_UserList[1],
	NULL
};

static const UserDBEntry* s_UserGroup_Service[] = {
	(const UserDBEntry*)&s_UserList[2],
	NULL
};

static const UserDBEntry* s_UserGroup_Watch[] = {
	(const UserDBEntry*)&s_UserList[3],
	NULL
};

static const GroupDBEntry s_GroupList[] = {
	{"Administrator", s_UserGroup_Administrator},
	{"Developer", s_UserGroup_Developer},
	{"Service", s_UserGroup_Service},
	{"Watch", s_UserGroup_Watch},
	{NULL, NULL}
};

static const GroupRightsEntry s_GroupRights_Device[] = {
	{(RTS_HANDLE)&s_GroupList[0], USERDB_RIGHT_ALL, USERDB_RIGHT_NONE},
	{(RTS_HANDLE)&s_GroupList[1], USERDB_RIGHT_VIEW | USERDB_RIGHT_ADD_REMOVE, USERDB_RIGHT_ALL & ~(USERDB_RIGHT_VIEW | USERDB_RIGHT_ADD_REMOVE) },
	{(RTS_HANDLE)&s_GroupList[2], USERDB_RIGHT_VIEW | USERDB_RIGHT_ADD_REMOVE, USERDB_RIGHT_ALL & ~(USERDB_RIGHT_VIEW | USERDB_RIGHT_ADD_REMOVE)},
	{(RTS_HANDLE)&s_GroupList[3], USERDB_RIGHT_VIEW, USERDB_RIGHT_ALL & ~USERDB_RIGHT_VIEW},
	{RTS_INVALID_HANDLE, 0, 0}
};

static const GroupRightsEntry s_GroupRights_Inherited[] = {
	{ (RTS_HANDLE)&s_GroupList[0], USERDB_RIGHT_NONE, USERDB_RIGHT_NONE },
	{ (RTS_HANDLE)&s_GroupList[1], USERDB_RIGHT_NONE, USERDB_RIGHT_NONE },
	{ (RTS_HANDLE)&s_GroupList[2], USERDB_RIGHT_NONE, USERDB_RIGHT_NONE },
	{ (RTS_HANDLE)&s_GroupList[3], USERDB_RIGHT_NONE, USERDB_RIGHT_NONE },
	{ RTS_INVALID_HANDLE, 0, 0 }
};

static const GroupRightsEntry s_GroupRights_Device_PlcLogic[] = {
	{(RTS_HANDLE)&s_GroupList[0], USERDB_RIGHT_ALL, USERDB_RIGHT_NONE },
	{(RTS_HANDLE)&s_GroupList[1], USERDB_RIGHT_ALL, USERDB_RIGHT_NONE },
	{(RTS_HANDLE)&s_GroupList[2], USERDB_RIGHT_VIEW, USERDB_RIGHT_ALL & ~USERDB_RIGHT_VIEW },
	{(RTS_HANDLE)&s_GroupList[3], USERDB_RIGHT_VIEW, USERDB_RIGHT_ALL & ~USERDB_RIGHT_VIEW },
	{RTS_INVALID_HANDLE, 0, 0}
};

static const GroupRightsEntry s_GroupRights_Device_Settings[] = {
	{ (RTS_HANDLE)&s_GroupList[0], USERDB_RIGHT_ALL, USERDB_RIGHT_NONE },
	{ (RTS_HANDLE)&s_GroupList[1], USERDB_RIGHT_ALL, USERDB_RIGHT_NONE },
	{ (RTS_HANDLE)&s_GroupList[2], USERDB_RIGHT_ALL, USERDB_RIGHT_NONE },
	{ (RTS_HANDLE)&s_GroupList[3], USERDB_RIGHT_VIEW, USERDB_RIGHT_ALL & ~USERDB_RIGHT_VIEW },
	{ RTS_INVALID_HANDLE, 0, 0 }
};

static const GroupRightsEntry s_GroupRights_Device_UserMgmt[] = {
	{ (RTS_HANDLE)&s_GroupList[0], USERDB_RIGHT_ALL, USERDB_RIGHT_NONE },
	{ (RTS_HANDLE)&s_GroupList[1], USERDB_RIGHT_NONE, USERDB_RIGHT_ALL },
	{ (RTS_HANDLE)&s_GroupList[2], USERDB_RIGHT_NONE, USERDB_RIGHT_ALL },
	{ (RTS_HANDLE)&s_GroupList[3], USERDB_RIGHT_NONE, USERDB_RIGHT_ALL },
	{ RTS_INVALID_HANDLE, 0, 0 }
};

static const GroupRightsEntry s_GroupRights_FileRoot[] = {
	{ (RTS_HANDLE)&s_GroupList[0], USERDB_RIGHT_ALL, USERDB_RIGHT_NONE },
	{ (RTS_HANDLE)&s_GroupList[1], USERDB_RIGHT_ALL, USERDB_RIGHT_NONE },
	{ (RTS_HANDLE)&s_GroupList[2], USERDB_RIGHT_ALL, USERDB_RIGHT_NONE },
	{ (RTS_HANDLE)&s_GroupList[3], USERDB_RIGHT_VIEW, USERDB_RIGHT_ALL & ~USERDB_RIGHT_VIEW },
	{RTS_INVALID_HANDLE, 0, 0}
};

static const ObjectEntry s_ObjectList[] = {
	{"Device", (RTS_HANDLE)&s_GroupRights_Device[0], 0, USERDB_RIGHT_VIEW | USERDB_RIGHT_MODIFY | USERDB_RIGHT_EXECUTE | USERDB_RIGHT_ADD_REMOVE},
	{"Device.PlcLogic", (RTS_HANDLE)&s_GroupRights_Device_PlcLogic[0], 1, USERDB_RIGHT_VIEW | USERDB_RIGHT_MODIFY | USERDB_RIGHT_EXECUTE | USERDB_RIGHT_ADD_REMOVE },
	{"Device.PlcLogic.Application", (RTS_HANDLE)&s_GroupRights_Inherited[0], 2, USERDB_RIGHT_VIEW | USERDB_RIGHT_MODIFY | USERDB_RIGHT_EXECUTE | USERDB_RIGHT_ADD_REMOVE},
	{"Device.Settings", (RTS_HANDLE)&s_GroupRights_Device_Settings[0], 3, USERDB_RIGHT_VIEW | USERDB_RIGHT_MODIFY},
	{"Device.Logger", (RTS_HANDLE)&s_GroupRights_Inherited[0], 4, USERDB_RIGHT_VIEW },
	{"Device.UserManagement", (RTS_HANDLE)&s_GroupRights_Device_UserMgmt[0], 5, USERDB_RIGHT_VIEW | USERDB_RIGHT_MODIFY},
	{"/", (RTS_HANDLE)&s_GroupRights_FileRoot[0], 6, USERDB_RIGHT_VIEW | USERDB_RIGHT_MODIFY | USERDB_RIGHT_ADD_REMOVE},
	{"/Boot", (RTS_HANDLE)&s_GroupRights_Inherited[0], 7, USERDB_RIGHT_VIEW | USERDB_RIGHT_MODIFY | USERDB_RIGHT_ADD_REMOVE},
	{NULL, NULL, (RTS_UI32)-1, USERDB_RIGHT_NONE}
};


USE_STMT

static int IsAdministatorGroup(RTS_HANDLE hGroup);

#ifdef CPLUSPLUS
	static CCmpUserDBTemplate *s_pCCmpUserDBTemplate = NULL;
#endif


typedef struct
{
#ifndef CPLUSPLUS
	IBase_C base;
	ICmpUserDB_C userDB;
	ICmpUserDBConfiguration_C userDBConfig; /* optional */
	ICmpUserGroupsDB_C userGroupsDB;
	ICmpUserGroupsDBConfiguration_C userGroupsDBConfig; /* optional */
	ICmpUserObjectsDB_C userObjectsDB;
	ICmpUserObjectsDBConfiguration_C userObjectsDBConfig; /* optional */
#endif
	IBase *pIBase;
	ICmpUserDB *piUserDB;
	ICmpUserDBConfiguration *piUserDBConfig; /* optional */
	ICmpUserGroupsDB *pIUserGroupsDB;
	ICmpUserGroupsDBConfiguration *pIUserGroupsDBConfig; /* optional */
	ICmpUserObjectsDB *pIUserObjectsDB;
	ICmpUserObjectsDBConfiguration *pIUserObjectsDBConfig; /* optional */
} UserDBTemplate_C;

/* Databases to be registered at CmpUserMgr */
static UserDBTemplate_C s_UserDBTemplateInterface;
static RTS_HANDLE s_hUserDB;
static RTS_HANDLE s_hUserDBConfig; /* optional */
static RTS_HANDLE s_hUserGroupsDB;
static RTS_HANDLE s_hUserGroupsDBConfig; /* optional */
static RTS_HANDLE s_hUserObjectsDB;
static RTS_HANDLE s_hUserObjectsDBConfig; /* optional */

static RTS_HANDLE s_hEventResetOriginDevice = RTS_INVALID_HANDLE;

#if !defined(CPLUSPLUS)
IMPLEMENT_ADDREF
IMPLEMENT_RELEASE
DECLARE_QUERYINTERFACE
#endif


static IBase* CDECL CreateInstance(CLASSID cid, RTS_RESULT *pResult)
{
#ifdef CPLUSPLUS
	if (cid == CLASSID_CCmpUserDBTemplate)
	{
		if (s_pCCmpUserDBTemplate == NULL)
			s_pCCmpUserDBTemplate = static_cast<CCmpUserDBTemplate *>(new CCmpUserDBTemplate());
		return (IBase*)s_pCCmpUserDBTemplate->QueryInterface(static_cast<ICmpUserDB *>(s_pCCmpUserDBTemplate), ITFID_IBase, pResult);
	}
#else
	if (cid == CLASSID_CCmpUserDBTemplate)
	{
		IBase *pI = &s_UserDBTemplateInterface.base;

		memset(&s_UserDBTemplateInterface, 0, sizeof(s_UserDBTemplateInterface));
		s_UserDBTemplateInterface.pIBase = pI;
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
	if (pIBase->Release() == 0)
		s_pCCmpUserDBTemplate = NULL;
	return ERR_OK;
#else
	pIBase->iRefCount--;
	if (pIBase->iRefCount == 0)
		memset(&s_UserDBTemplateInterface, 0, sizeof(s_UserDBTemplateInterface));
	return ERR_OK;
#endif
}


#if !defined(CPLUSPLUS)

static void *CDECL QueryInterface(IBase *pBase, ITFID iid, RTS_RESULT *pResult)
{
	if (iid == ITFID_IBase)
	{
		/* Every interface has as first element a pointer to the IBase interface. So it doesn't matter, which interface
		is used to get the IBase pointer */
		UserDBTemplate_C *pC = (UserDBTemplate_C *)pBase;
		pC->pIBase->iRefCount++;
		RTS_SETRESULT(pResult, ERR_OK);
		return pC->pIBase;
	}
	if (iid == ITFID_ICmpUserDB)
	{
		UserDBTemplate_C *pC = (UserDBTemplate_C *)pBase;
		pC->userDB.pBase = pBase;

		pC->userDB.IUserDBAuthenticate = UserDBAuthenticate;
		pC->userDB.IUserDBGetFirstUser = UserDBGetFirstUser;
		pC->userDB.IUserDBGetNextUser = UserDBGetNextUser;

		pC->piUserDB = &pC->userDB;
		pC->base.iRefCount++;
		RTS_SETRESULT(pResult, ERR_OK);
		return pC->piUserDB;
	}
	if (iid == ITFID_ICmpUserDBConfiguration) /* optional */
	{
		UserDBTemplate_C *pC = (UserDBTemplate_C *)pBase;
		pC->userDBConfig.pBase = pBase;

		pC->userDBConfig.IUserDBConfigAddUser = UserDBConfigAddUser;
		pC->userDBConfig.IUserDBConfigExistsUser = UserDBConfigExistsUser;
		pC->userDBConfig.IUserDBConfigExport = UserDBConfigExport;
		pC->userDBConfig.IUserDBConfigGetUserProperty = UserDBConfigGetUserProperty;
		pC->userDBConfig.IUserDBConfigImport = UserDBConfigImport;
		pC->userDBConfig.IUserDBConfigRelease = UserDBConfigRelease;
		pC->userDBConfig.IUserDBConfigRemoveUser = UserDBConfigRemoveUser;
		pC->userDBConfig.IUserDBConfigSetUserCredentials = UserDBConfigSetUserCredentials;
		pC->userDBConfig.IUserDBConfigSetUserProperty = UserDBConfigSetUserProperty;

		pC->piUserDBConfig = &pC->userDBConfig;
		pC->base.iRefCount++;
		RTS_SETRESULT(pResult, ERR_OK);
		return pC->piUserDBConfig;
	}
	if (iid == ITFID_ICmpUserGroupsDB)
	{
		UserDBTemplate_C *pC = (UserDBTemplate_C *)pBase;
		pC->userGroupsDB.pBase = pBase;

		pC->userGroupsDB.IUserGroupsDBGetGroup = UserGroupsDBGetGroup;
		pC->userGroupsDB.IUserGroupsDBGetFirstGroup = UserGroupsDBGetFirstGroup;
		pC->userGroupsDB.IUserGroupsDBGetNextGroup = UserGroupsDBGetNextGroup;
		pC->userGroupsDB.IUserGroupsDBGetName = UserGroupsDBGetName;
		pC->userGroupsDB.IUserGroupsDBGetProperty = UserGroupsDBGetProperty;
		pC->userGroupsDB.IUserGroupsDBGroupHasUser = UserGroupsDBGroupHasUser;
		pC->userGroupsDB.IUserGroupsDBGroupHasMember = UserGroupsDBGroupHasMember;
		pC->userGroupsDB.IUserGroupsDBGetFirstUser = UserGroupsDBGetFirstUser;
		pC->userGroupsDB.IUserGroupsDBGetNextUser = UserGroupsDBGetNextUser;
		pC->userGroupsDB.IUserGroupsDBGetFirstGroupMember = UserGroupsDBGetFirstGroupMember;
		pC->userGroupsDB.IUserGroupsDBGetNextGroupMember = UserGroupsDBGetNextGroupMember;
		pC->pIUserGroupsDB = &pC->userGroupsDB;
		pC->base.iRefCount++;
		RTS_SETRESULT(pResult, ERR_OK);
		return pC->pIUserGroupsDB;
	}
	if (iid == ITFID_ICmpUserGroupsDBConfiguration) /* optional */
	{
		UserDBTemplate_C *pC = (UserDBTemplate_C *)pBase;
		pC->userGroupsDBConfig.pBase = pBase;

		pC->userGroupsDBConfig.IUserGroupsDBConfigRelease = UserGroupsDBConfigRelease;
		pC->userGroupsDBConfig.IUserGroupsDBConfigImport = UserGroupsDBConfigImport;
		pC->userGroupsDBConfig.IUserGroupsDBConfigExport = UserGroupsDBConfigExport;
		pC->userGroupsDBConfig.IUserGroupsDBConfigAdd = UserGroupsDBConfigAdd;
		pC->userGroupsDBConfig.IUserGroupsDBConfigRemove = UserGroupsDBConfigRemove;
		pC->userGroupsDBConfig.IUserGroupsDBConfigSetProperty = UserGroupsDBConfigSetProperty;
		pC->userGroupsDBConfig.IUserGroupsDBConfigAddUser = UserGroupsDBConfigAddUser;
		pC->userGroupsDBConfig.IUserGroupsDBConfigRemoveUser = UserGroupsDBConfigRemoveUser;
		pC->userGroupsDBConfig.IUserGroupsDBConfigAddMember = UserGroupsDBConfigAddMember;
		pC->userGroupsDBConfig.IUserGroupsDBConfigRemoveMember = UserGroupsDBConfigRemoveMember;

		pC->pIUserGroupsDBConfig = &pC->userGroupsDBConfig;
		pC->base.iRefCount++;
		RTS_SETRESULT(pResult, ERR_OK);
		return pC->pIUserGroupsDBConfig;
	}
	if (iid == ITFID_ICmpUserObjectsDB)
	{
		UserDBTemplate_C *pC = (UserDBTemplate_C *)pBase;
		pC->userObjectsDB.pBase = pBase;

		pC->userObjectsDB.IUserObjectsDBActivate = UserObjectsDBActivate;
		pC->userObjectsDB.IUserObjectsDBClose = UserObjectsDBClose;
		pC->userObjectsDB.IUserObjectsDBGetFather = UserObjectsDBGetFather;
		pC->userObjectsDB.IUserObjectsDBGetFirst = UserObjectsDBGetFirst;
		pC->userObjectsDB.IUserObjectsDBGetFirstChild = UserObjectsDBGetFirstChild;
		pC->userObjectsDB.IUserObjectsDBGetFirstGroup = UserObjectsDBGetFirstGroup;
		pC->userObjectsDB.IUserObjectsDBGetGroupRights = UserObjectsDBGetGroupRights;
		pC->userObjectsDB.IUserObjectsDBGetID = UserObjectsDBGetID;
		pC->userObjectsDB.IUserObjectsDBGetName = UserObjectsDBGetName;
		pC->userObjectsDB.IUserObjectsDBGetNext = UserObjectsDBGetNext;
		pC->userObjectsDB.IUserObjectsDBGetNextChild = UserObjectsDBGetNextChild;
		pC->userObjectsDB.IUserObjectsDBGetNextGroup = UserObjectsDBGetNextGroup;
		pC->userObjectsDB.IUserObjectsDBGetPath = UserObjectsDBGetPath;
		pC->userObjectsDB.IUserObjectsDBGetProperties = UserObjectsDBGetProperties;
		pC->userObjectsDB.IUserObjectsDBGetRights = UserObjectsDBGetRights;
		pC->userObjectsDB.IUserObjectsDBGetUsedRights = UserObjectsDBGetUsedRights;
		pC->userObjectsDB.IUserObjectsDBHasRights = UserObjectsDBHasRights;
		pC->userObjectsDB.IUserObjectsDBOpen = UserObjectsDBOpen;

		pC->pIUserObjectsDB = &pC->userObjectsDB;
		pC->base.iRefCount++;
		RTS_SETRESULT(pResult, ERR_OK);
		return pC->pIUserObjectsDB;
	}
	if (iid == ITFID_ICmpUserObjectsDBConfiguration) /* optional */
	{
		UserDBTemplate_C *pC = (UserDBTemplate_C *)pBase;
		pC->userObjectsDBConfig.pBase = pBase;

		pC->userObjectsDBConfig.IUserObjectsDBConfigLoad = UserObjectsDBConfigLoad;
		pC->userObjectsDBConfig.IUserObjectsDBConfigStore = UserObjectsDBConfigStore;
		pC->userObjectsDBConfig.IUserObjectsDBConfigReleaseRights = UserObjectsDBConfigReleaseRights;
		pC->userObjectsDBConfig.IUserObjectsDBConfigRelease = UserObjectsDBConfigRelease;
		pC->userObjectsDBConfig.IUserObjectsDBConfigAdd = UserObjectsDBConfigAdd;
		pC->userObjectsDBConfig.IUserObjectsDBConfigAdd2 = UserObjectsDBConfigAdd2;
		pC->userObjectsDBConfig.IUserObjectsDBConfigRemove = UserObjectsDBConfigRemove;
		pC->userObjectsDBConfig.IUserObjectsDBConfigAddChild = UserObjectsDBConfigAddChild;
		pC->userObjectsDBConfig.IUserObjectsDBConfigSetUsedRights = UserObjectsDBConfigSetUsedRights;
		pC->userObjectsDBConfig.IUserObjectsDBConfigSetID = UserObjectsDBConfigSetID;
		pC->userObjectsDBConfig.IUserObjectsDBConfigAddGroup = UserObjectsDBConfigAddGroup;
		pC->userObjectsDBConfig.IUserObjectsDBConfigRemoveGroup = UserObjectsDBConfigRemoveGroup;
		pC->userObjectsDBConfig.IUserObjectsDBConfigSetGroupRights = UserObjectsDBConfigSetGroupRights;
		pC->userObjectsDBConfig.IUserObjectsDBConfigSetGroupDeniedRights = UserObjectsDBConfigSetGroupDeniedRights;
		pC->userObjectsDBConfig.IUserObjectsDBConfigClearRights = UserObjectsDBConfigClearRights;

		pC->pIUserObjectsDBConfig = &pC->userObjectsDBConfig;
		pC->base.iRefCount++;
		RTS_SETRESULT(pResult, ERR_OK);
		return pC->pIUserGroupsDBConfig;
	}
	RTS_SETRESULT(pResult, ERR_FAILED);
	return NULL;
}
#endif

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
	s_pCCmpUserDBTemplate = NULL;

	pInitStruct->pfCreateInstance = CreateInstance;
	pInitStruct->pfDeleteInstance = DeleteInstance;
	if (pInitStruct->pfCMRegisterClass != NULL)
	{
		RTS_HANDLE hClass = pInitStruct->pfCMRegisterClass(COMPONENT_ID, CLASSID_CCmpUserDBTemplate);
		if (hClass == RTS_INVALID_HANDLE)
			return ERR_FAILED;
	}
#endif
	return ERR_OK;
}

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

static RTS_RESULT MakeHash(char *pszPassword, RTS_UI8 *pbyHash, RTS_SIZE iLenHash, RTS_UI32 *pulSessionId)
{
	RTS_RESULT Result = ERR_OK;
	RTS_SIZE i, sLen = strlen(pszPassword);
	char sBuf[USERMGR_MAX_PASSWORD_LEN + 8];

	memset(pbyHash, 0, iLenHash);

	/* Generate Salt */
	if (*pulSessionId == 0)
		Result = CAL_ServerGenerateSessionId(pulSessionId);
	if (Result == ERR_OK)
	{
		sprintf(sBuf, "%08x%s", *pulSessionId, pszPassword);
		sLen += 8;

		/* Generate Pepper */
		for (i = 0; i < sLen; i++)
			sBuf[i] ^= 42 + i;

		pszPassword = sBuf;
	}

	/* Generate MD5 password hash */
	Result = CAL_CryptMD5Calculate((const unsigned char *)pszPassword, (int)sLen, (char *)pbyHash, (int)iLenHash);
	if (Result == ERR_NOTIMPLEMENTED)
	{
		/* alternatively just store the salted and peppered password */
		strncpy((char*)pbyHash, pszPassword, iLenHash);
		return ERR_OK;
	}
	if (Result != ERR_OK)
		return Result;

	/* Convert to upper */
	for (i = 0; i < iLenHash; i++)
		pbyHash[i] = (RTS_UI8)toupper(pbyHash[i]);

	return ERR_OK;
}

/* Generate initial password hashes */
static void InitialHashes(void)
{
	int i;

	for (i = 0; s_UserList[i].pszPassword != NULL; i++)
	{
		s_UserPwSaltPool[i] = 0; /* Generate Salt */
		MakeHash(s_UserList[i].pszPassword, s_UserPwHashPool[i], CRYPTMD5_KEY_LENGTH, &s_UserPwSaltPool[i]);
	}
}

static void CDECL CBResetOriginDevice(EventParam *pEventParam)
{
	if (pEventParam->EventId == EVT_CmpDevice_ResetOrigin)
	{
		if (pEventParam->pParameter != NULL)
		{
			EVTPARAM_CmpDevice_ResetOrigin *pParam = (EVTPARAM_CmpDevice_ResetOrigin *)pEventParam->pParameter;
			if ((pParam->ui32ResetOriginConfig & DEV_ROC_KEEP_USERDB) == DEV_ROC_KEEP_USERDB)
				return;
		}
		CAL_SysFileDelete(PWFNAME);
		InitialHashes();
	}
}

/* Example for a Hook function */
static RTS_RESULT CDECL HookFunction(RTS_UI32 ulHook, RTS_UINTPTR ulParam1, RTS_UINTPTR ulParam2)
{
	switch (ulHook)
	{
		case CH_INIT_SYSTEM:
			break;
		case CH_INIT:
		{
			RTS_HANDLE hFile = CAL_SysFileOpen(PWFNAME, AM_READ, NULL);

			if (hFile == RTS_INVALID_HANDLE)
			{
				/* Generate initial password hashes */
				InitialHashes();
			}
			else
			{
				int i;
				RTS_RESULT Result;
				/* Read password hashes from file */
				for (i = 0; s_UserList[i].pszPassword != NULL; i++)
				{
					CAL_SysFileRead(hFile, (unsigned char*)&s_UserPwSaltPool[i], sizeof(RTS_UI32), &Result);
					CAL_SysFileRead(hFile, s_UserPwHashPool[i], CRYPTMD5_KEY_LENGTH, &Result);
				}
				CAL_SysFileClose(hFile);
			}
			break;
		}
		case CH_INIT2:
			break;
		case CH_PRE_INIT3:
		{
			IBase *pIBase = CreateInstance(CLASSID_CCmpUserDBTemplate, NULL);

			s_hUserDB = pIBase->QueryInterface(pIBase, ITFID_ICmpUserDB, NULL);
			s_hUserDBConfig = pIBase->QueryInterface(pIBase, ITFID_ICmpUserDBConfiguration, NULL); /* optional */
			s_hUserGroupsDB = pIBase->QueryInterface(pIBase, ITFID_ICmpUserGroupsDB, NULL);
			s_hUserGroupsDBConfig = pIBase->QueryInterface(pIBase, ITFID_ICmpUserGroupsDBConfiguration, NULL); /* optional */
			s_hUserObjectsDB = pIBase->QueryInterface(pIBase, ITFID_ICmpUserObjectsDB, NULL);
			s_hUserObjectsDBConfig = pIBase->QueryInterface(pIBase, ITFID_ICmpUserObjectsDBConfiguration, NULL); /* optional */
			CAL_UserMgrRegisterUserDB(s_hUserDB, UserMgrCredentials_Type_Password);
			CAL_UserMgrRegisterUserDBConfig(s_hUserDBConfig, UserMgrCredentials_Type_Password); /* optional */
			CAL_UserMgrRegisterUserGroupsDB(s_hUserGroupsDB);
			CAL_UserMgrRegisterUserGroupsDBConfig(s_hUserGroupsDBConfig); /* optional */
			CAL_UserMgrRegisterUserObjectsDB(s_hUserObjectsDB);
			CAL_UserMgrRegisterUserObjectsDBConfig(s_hUserObjectsDBConfig); /* optional */

			break;
		}
		case CH_INIT3:
			CAL_SysFileAddToBlacklist(PWFNAME); /* no online or IEC access to that file */

			if (CHK_EventOpen && CHK_EventRegisterCallbackFunction)
			{
				RTS_RESULT Result;

				s_hEventResetOriginDevice = CAL_EventOpen(EVT_CmpDevice_ResetOrigin, CMPID_CmpDevice, &Result);
				if (Result == ERR_OK)
					CAL_EventRegisterCallbackFunction(s_hEventResetOriginDevice, CBResetOriginDevice, 0);
			}
			break;
		case CH_INIT_TASKS:
			break;
		case CH_INIT_COMM:
			break;

		/* Cyclic */
		case CH_COMM_CYCLE:
			break;

		case CH_EXIT_COMM:
			break;
		case CH_EXIT_TASKS:
			break;
		case CH_EXIT3:
			if (CHK_EventUnregisterCallbackFunction && CHK_EventClose && s_hEventResetOriginDevice != RTS_INVALID_HANDLE)
			{
				CAL_EventUnregisterCallbackFunction(s_hEventResetOriginDevice, CBResetOriginDevice);
				CAL_EventClose(s_hEventResetOriginDevice);
			}
			break;
		case CH_EXIT2:
			CAL_UserMgrUnregisterUserDB(s_hUserDB);
			CAL_UserMgrUnregisterUserDBConfig(s_hUserDBConfig); /* optional */
			CAL_UserMgrUnregisterUserGroupsDB(s_hUserGroupsDB);
			CAL_UserMgrUnregisterUserGroupsDBConfig(s_hUserGroupsDBConfig); /* optional */
			CAL_UserMgrUnregisterUserObjectsDB(s_hUserObjectsDB);
			CAL_UserMgrUnregisterUserObjectsDBConfig(s_hUserObjectsDBConfig); /* optional */
			break;
		case CH_EXIT:
		{
			EXIT_STMT;
			break;
		}
		case CH_EXIT_SYSTEM:
			break;
		default:
			break;
	}
	return 0;
}

/* CmpUserDB Implementation: mandatory */
#if 1
STATICITF_DEF RTS_RESULT CDECL UserDBAuthenticate(RTS_HANDLE hDatabase, char *pszUser, UserMgrCredentials *pCredentials, RTS_UI32 *pUserProperty)
{
	int i;

	if (pCredentials == NULL || pszUser == NULL)
		return ERR_PARAMETER;

	if (pCredentials->credentialsType != UserMgrCredentials_Type_Password)
		return ERR_NOT_SUPPORTED;

	if (pCredentials->credential.pwd.pszPassword == NULL)
		return ERR_PARAMETER;

	for (i = 0; s_UserList[i].pszUser != NULL; i++)
	{
		if (strcmp(s_UserList[i].pszUser, pszUser) == 0)
		{
			RTS_UI8 abyHash[CRYPTMD5_KEY_LENGTH];
			RTS_RESULT Result = MakeHash(pCredentials->credential.pwd.pszPassword, abyHash, sizeof(abyHash), &s_UserPwSaltPool[i]);

			if (Result == ERR_OK && memcmp(abyHash, s_UserPwHashPool[i], CRYPTMD5_KEY_LENGTH) == 0)
			{
				if (pUserProperty != NULL)
					*pUserProperty = 0;
				return ERR_OK;
			}
		}
	}

	return ERR_NO_ACCESS_RIGHTS;
}

STATICITF_DEF char* CDECL UserDBGetFirstUser(RTS_HANDLE hDatabase, RTS_HANDLE *hIterator, RTS_UI32 *pUserProperty, RTS_RESULT *pResult)
{
	if (hIterator == NULL || *hIterator != RTS_INVALID_HANDLE)
	{
		RTS_SETRESULT(pResult, ERR_PARAMETER);
		return NULL;
	}

	if (s_UserList[0].pszUser == NULL)
	{
		RTS_SETRESULT(pResult, ERR_NO_OBJECT);
		return NULL;
	}
	
	if (pUserProperty != NULL)
		*pUserProperty = 0;

	*hIterator = (RTS_HANDLE)1;
	RTS_SETRESULT(pResult, ERR_OK);
	return s_UserList[0].pszUser;
}

STATICITF_DEF char* CDECL UserDBGetNextUser(RTS_HANDLE hDatabase, RTS_HANDLE *hIterator, RTS_UI32 *pUserProperty, RTS_RESULT *pResult)
{
	RTS_UI32 i = 0;


	if (hIterator == NULL || ((RTS_UI32)*hIterator < 1 || (RTS_UI32)*hIterator > DIM(s_UserList) - 1))
	{
		RTS_SETRESULT(pResult, ERR_PARAMETER);
		return NULL;
	}
	else
		i = (RTS_UI32)*hIterator;

	if(s_UserList[i].pszUser != NULL)
	{
		if (pUserProperty != NULL)
			*pUserProperty = 0;

		*hIterator = (RTS_HANDLE)(i + 1);
		RTS_SETRESULT(pResult, ERR_OK);
		return s_UserList[i].pszUser;
	}

	RTS_SETRESULT(pResult, ERR_NO_OBJECT);
	*hIterator = RTS_INVALID_HANDLE;
	return NULL;
}
#endif

/* CmpUserDBConfig Implementation: optional */
#if 1

STATICITF_DEF RTS_RESULT CDECL UserDBConfigRelease(RTS_HANDLE hDatabase)
{
	return ERR_NOTIMPLEMENTED;
}

STATICITF_DEF RTS_RESULT CDECL UserDBConfigImport(RTS_HANDLE hDatabase, RTS_UI8 *pData, RTS_SIZE dataSize)
{
	return ERR_NOTIMPLEMENTED;
}

STATICITF_DEF RTS_SIZE CDECL UserDBConfigExport(RTS_HANDLE hDatabase, RTS_UI8 *pData, RTS_SIZE maxSize, RTS_RESULT *pResult)
{
	RTS_SETRESULT(pResult, ERR_NOTIMPLEMENTED);
	return 0;
}

STATICITF_DEF RTS_RESULT CDECL UserDBConfigAddUser(RTS_HANDLE hDatabase, char *pszUser, UserMgrCredentials *pCredentials)
{
	return ERR_NOTIMPLEMENTED;
}

STATICITF_DEF RTS_BOOL CDECL UserDBConfigExistsUser(RTS_HANDLE hDatabase, char *pszUser)
{
	return 1;
}

STATICITF_DEF RTS_RESULT CDECL UserDBConfigRemoveUser(RTS_HANDLE hDatabase, char *pszUser)
{
	return ERR_NOTIMPLEMENTED;
}

STATICITF_DEF RTS_RESULT CDECL UserDBConfigSetUserCredentials(RTS_HANDLE hDatabase, char *pszUser, UserMgrCredentials *pCredentials)
{
	RTS_RESULT Result = ERR_NO_OBJECT;
	int i, k;

	if (pszUser == NULL || pCredentials == NULL)
		return ERR_PARAMETER;
	if (pCredentials->credentialsType != UserMgrCredentials_Type_Password)
		return ERR_NOT_SUPPORTED;
	if (pCredentials->credential.pwd.pszPassword == NULL)
		return ERR_PARAMETER;
	if (strlen(pCredentials->credential.pwd.pszPassword) >= USERMGR_MAX_PASSWORD_LEN)
		return ERR_BUFFERSIZE;

	for (i = 0; s_UserList[i].pszUser != NULL; i++)
	{
		if (strcmp(s_UserList[i].pszUser, pszUser) == 0)
		{
			s_UserPwSaltPool[i] = 0; /* Generate new Salt */
			Result = MakeHash(pCredentials->credential.pwd.pszPassword, s_UserPwHashPool[i], CRYPTMD5_KEY_LENGTH, &s_UserPwSaltPool[i]);
			if (Result != ERR_OK)
				return Result;
			else
			{
				RTS_RESULT Res;
				RTS_HANDLE hFile = CAL_SysFileOpen(PWFNAME, AM_WRITE, &Res);

				if (hFile != RTS_INVALID_HANDLE && Res == ERR_OK)
				{
					for (k = 0; s_UserList[k].pszPassword != NULL; k++)
					{
						CAL_SysFileWrite(hFile, (unsigned char*)&s_UserPwSaltPool[k], sizeof(RTS_UI32), &Res);
						CAL_SysFileWrite(hFile, s_UserPwHashPool[k], CRYPTMD5_KEY_LENGTH, &Res);
					}
					CAL_SysFileClose(hFile);
				}
			}
			return ERR_OK;
		}
	}

	return Result;
}

STATICITF_DEF RTS_UI32 CDECL UserDBConfigGetUserProperty(RTS_HANDLE hDatabase, char *pszUser, RTS_RESULT *pResult)
{
	return USERMGR_USER_PROP_ALLOW_CHANGE_PASSWORD;
}

STATICITF_DEF RTS_RESULT CDECL UserDBConfigSetUserProperty(RTS_HANDLE hDatabase, char *pszUser, RTS_UI32 property)
{
	return ERR_OK;
}

#endif

/* CmpUserGroupsDB Implementation: mandatory */
#if 1

STATICITF_DEF RTS_HANDLE CDECL UserGroupsDBGetGroup(RTS_HANDLE hDatabase, char *pszGroupName, RTS_RESULT *pResult)
{
	int i = 0;

	if (pszGroupName == NULL)
	{
		RTS_SETRESULT(pResult, ERR_PARAMETER);
		return RTS_INVALID_HANDLE;
	}

	while (s_GroupList[i].pszGroup != NULL)
	{
		if (strcmp(s_GroupList[i].pszGroup, pszGroupName) == 0)
		{
			RTS_SETRESULT(pResult, ERR_OK);
			return (RTS_HANDLE)&s_GroupList[i];
		}
		i++;
	}
	RTS_SETRESULT(pResult, ERR_PARAMETER);
	return RTS_INVALID_HANDLE;
}

STATICITF_DEF RTS_HANDLE CDECL UserGroupsDBGetFirstGroup(RTS_HANDLE hDatabase, RTS_RESULT *pResult)
{
	if (s_GroupList[0].pszGroup == NULL)
	{
		RTS_SETRESULT(pResult, ERR_FAILED);
		return RTS_INVALID_HANDLE;
	}
	RTS_SETRESULT(pResult, ERR_OK);
	return (RTS_HANDLE)&s_GroupList[0];
}

STATICITF_DEF RTS_HANDLE CDECL UserGroupsDBGetNextGroup(RTS_HANDLE hDatabase, RTS_HANDLE hPrevGroup, RTS_RESULT *pResult)
{
	int i = 0;

	if (hPrevGroup == RTS_INVALID_HANDLE)
	{
		RTS_SETRESULT(pResult, ERR_PARAMETER);
		return RTS_INVALID_HANDLE;
	}

	while (s_GroupList[i].pszGroup != NULL)
	{
		if ((RTS_HANDLE)&s_GroupList[i] == hPrevGroup)
		{
			if (s_GroupList[i + 1].pszGroup != NULL)
			{
				RTS_SETRESULT(pResult, ERR_OK);
				return (RTS_HANDLE)&s_GroupList[i + 1];
			}
		}
		i++;
	}
	RTS_SETRESULT(pResult, ERR_PARAMETER);
	return RTS_INVALID_HANDLE;
}

STATICITF_DEF char* CDECL UserGroupsDBGetName(RTS_HANDLE hDatabase, RTS_HANDLE hGroup, RTS_RESULT *pResult)
{
	GroupDBEntry *pGroup = (GroupDBEntry *)hGroup;

	if (hGroup == RTS_INVALID_HANDLE)
		return NULL;

	return pGroup->pszGroup;
}

STATICITF_DEF RTS_UI32 CDECL UserGroupsDBGetProperty(RTS_HANDLE hDatabase, RTS_HANDLE hGroup, RTS_RESULT *pResult)
{
	RTS_SETRESULT(pResult, ERR_NOTIMPLEMENTED);
	return 0;
}

STATICITF_DEF RTS_RESULT CDECL UserGroupsDBGroupHasUser(RTS_HANDLE hDatabase, RTS_HANDLE hGroup, char *pszUser)
{
	int i = 0;

	if (hGroup == RTS_INVALID_HANDLE || pszUser == NULL)
		return ERR_PARAMETER;

	while (s_GroupList[i].pszGroup != NULL)
	{
		if (&s_GroupList[i] == (GroupDBEntry *)hGroup)
		{
			int j = 0;

			while (s_GroupList[i].pUserList != NULL && ((UserDBEntry**)(s_GroupList[i].pUserList))[j] != NULL)
			{
				if (strcmp(((UserDBEntry**)(s_GroupList[i].pUserList))[j]->pszUser, pszUser) == 0)
				{
					return ERR_OK;
				}
				j++;
			}
			break;
		}
		i++;
	}
	return ERR_PARAMETER;
}

STATICITF_DEF RTS_RESULT CDECL UserGroupsDBGroupHasMember(RTS_HANDLE hDatabase, RTS_HANDLE hGroup, RTS_HANDLE hGroupMember)
{
	return ERR_NOTIMPLEMENTED;
}

STATICITF_DEF char* CDECL UserGroupsDBGetFirstUser(RTS_HANDLE hDatabase, RTS_HANDLE hGroup, RTS_HANDLE *phIterator, RTS_RESULT *pResult)
{
	GroupDBEntry *pGroup = (GroupDBEntry *)hGroup;
	UserDBEntry **ppUserEntry;

	if (phIterator == NULL || *phIterator != RTS_INVALID_HANDLE)
	{
		RTS_SETRESULT(pResult, ERR_PARAMETER);
		return NULL;
	}

	if (hGroup == RTS_INVALID_HANDLE)
	{
		RTS_SETRESULT(pResult, ERR_PARAMETER);
		return NULL;
	}

	ppUserEntry = (UserDBEntry **)pGroup->pUserList;
	if (ppUserEntry != NULL)
	{
		*phIterator = (*ppUserEntry);
		RTS_SETRESULT(pResult, ERR_OK);
		return (*ppUserEntry)->pszUser;
	}
	RTS_SETRESULT(pResult, ERR_NO_OBJECT);
	return NULL;
}

STATICITF_DEF char* CDECL UserGroupsDBGetNextUser(RTS_HANDLE hDatabase, RTS_HANDLE hGroup, RTS_HANDLE *phIterator, RTS_RESULT *pResult)
{
	UserDBEntry *pUserEntry;
	int i = 0;

	if (hGroup == RTS_INVALID_HANDLE)
	{
		RTS_SETRESULT(pResult, ERR_PARAMETER);
		return NULL;
	}

	pUserEntry = ((UserDBEntry**)(s_GroupList[i].pUserList))[i];
	while (pUserEntry != NULL)
	{
		if ((RTS_HANDLE)pUserEntry == *phIterator)
		{
			i++;
			pUserEntry = ((UserDBEntry**)(s_GroupList[i].pUserList))[i];
			if (pUserEntry != NULL)
			{
				*phIterator = pUserEntry;
				RTS_SETRESULT(pResult, ERR_OK);
				return pUserEntry->pszUser;
			}
			break;
		}
		i++;
		pUserEntry = ((UserDBEntry**)(s_GroupList[i].pUserList))[i];
	}
	RTS_SETRESULT(pResult, ERR_NO_OBJECT);
	return NULL;
}

STATICITF_DEF RTS_HANDLE CDECL UserGroupsDBGetFirstGroupMember(RTS_HANDLE hDatabase, RTS_HANDLE hGroup, RTS_RESULT *pResult)
{
	RTS_SETRESULT(pResult, ERR_NOTIMPLEMENTED);
	return RTS_INVALID_HANDLE;
}

STATICITF_DEF RTS_HANDLE CDECL UserGroupsDBGetNextGroupMember(RTS_HANDLE hDatabase, RTS_HANDLE hGroup, RTS_HANDLE hPrevMember, RTS_RESULT *pResult)
{
	RTS_SETRESULT(pResult, ERR_NOTIMPLEMENTED);
	return RTS_INVALID_HANDLE;
}
#endif

/* CmpUserGroupsDBConfig Implementation: optional */
#if 1

STATICITF_DEF RTS_RESULT CDECL UserGroupsDBConfigRelease(RTS_HANDLE hDatabase)
{
	return ERR_NOTIMPLEMENTED;
}

STATICITF_DEF RTS_RESULT CDECL UserGroupsDBConfigImport(RTS_HANDLE hDatabase, RTS_UI8 *pData, RTS_SIZE dataSize)
{
	return ERR_NOTIMPLEMENTED;
}

STATICITF_DEF RTS_SIZE CDECL UserGroupsDBConfigExport(RTS_HANDLE hDatabase, RTS_UI8 *pData, RTS_SIZE maxSize, RTS_RESULT *pResult)
{
	RTS_SETRESULT(pResult, ERR_NOTIMPLEMENTED);
	return 0;
}

STATICITF_DEF RTS_RESULT CDECL UserGroupsDBConfigAdd(RTS_HANDLE hDatabase, char *pszGroup)
{
	return ERR_NOTIMPLEMENTED;
}

STATICITF_DEF RTS_RESULT CDECL UserGroupsDBConfigRemove(RTS_HANDLE hDatabase, char *pszGroup)
{
	return ERR_NOTIMPLEMENTED;
}

STATICITF_DEF RTS_RESULT CDECL UserGroupsDBConfigSetProperty(RTS_HANDLE hDatabase, char *pszGroup, RTS_UI32 ulProperty)
{
	return ERR_NOTIMPLEMENTED;
}

STATICITF_DEF RTS_RESULT CDECL UserGroupsDBConfigAddUser(RTS_HANDLE hDatabase, char *pszGroup, char *pszUser)
{
	return ERR_NOTIMPLEMENTED;
}

STATICITF_DEF RTS_RESULT CDECL UserGroupsDBConfigRemoveUser(RTS_HANDLE hDatabase, char *pszGroup, char *pszUser)
{
	return ERR_NOTIMPLEMENTED;
}

STATICITF_DEF RTS_RESULT CDECL UserGroupsDBConfigAddMember(RTS_HANDLE hDatabase, char *pszGroup, char *pszGroupToAdd)
{
	return ERR_NOTIMPLEMENTED;
}

STATICITF_DEF RTS_RESULT CDECL UserGroupsDBConfigRemoveMember(RTS_HANDLE hDatabase, char *pszGroup, char *pszGroupToRemove)
{
	return ERR_NOTIMPLEMENTED;
}

#endif

/* CmpUserObjectsDB Implementation: mandatory */
#if 1

STATICITF_DEF RTS_RESULT CDECL UserDBEnforce(RTS_HANDLE hDatabase)
{
	return ERR_OK;
}

STATICITF_DEF RTS_RESULT CDECL UserObjectsDBGetUsedRights(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_UI32 *pulUsedRights)
{
	ObjectEntry *pObject = (ObjectEntry *)hObject;

	if (hObject == RTS_INVALID_HANDLE || pulUsedRights == NULL)
		return ERR_PARAMETER;

	*pulUsedRights = pObject->ulUsedRights;
	return ERR_OK;
}

STATICITF_DEF RTS_RESULT CDECL UserObjectsDBGetProperties(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_UI32 *pulProperties)
{
	ObjectEntry *pObject = (ObjectEntry *)hObject;

	if (hObject == RTS_INVALID_HANDLE || pulProperties == NULL)
		return ERR_PARAMETER;

	*pulProperties = pObject->ulProperties;
	return ERR_OK;
}

STATICITF_DEF RTS_RESULT CDECL UserObjectsDBGetID (RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_UI32 *pulID)
{
	ObjectEntry *pObject = (ObjectEntry *)hObject;
	if (hObject == RTS_INVALID_HANDLE || pulID == NULL)
		return ERR_PARAMETER;
	*pulID = pObject->ulID;
	return ERR_OK;
}

STATICITF_DEF RTS_HANDLE CDECL UserObjectsDBGetFirst(RTS_HANDLE hDatabase, RTS_RESULT *pResult)
{
	RTS_SETRESULT(pResult, ERR_OK);
	return (RTS_HANDLE)&s_ObjectList[0];
}

STATICITF_DEF RTS_HANDLE CDECL UserObjectsDBGetNext(RTS_HANDLE hDatabase, RTS_HANDLE hPrevObject, RTS_RESULT *pResult)
{
	int i = 0;

	if (hPrevObject == RTS_INVALID_HANDLE)
	{
		RTS_SETRESULT(pResult, ERR_PARAMETER);
		return RTS_INVALID_HANDLE;
	}

	while (s_ObjectList[i].pszObject != NULL)
	{
		if ((RTS_HANDLE)&s_ObjectList[i] == hPrevObject)
		{
			i++;
			if (s_ObjectList[i].pszObject != NULL)
			{
				RTS_SETRESULT(pResult, ERR_OK);
				return (RTS_HANDLE)&s_ObjectList[i];
			}
			break;
		}
		i++;
	}
	RTS_SETRESULT(pResult, ERR_PARAMETER);
	return RTS_INVALID_HANDLE;
}

STATICITF_DEF RTS_HANDLE CDECL UserObjectsDBGetFirstChild(RTS_HANDLE hDatabase, RTS_HANDLE hFatherObject, RTS_RESULT *pResult)
{
	int i = 0;
	ObjectEntry *pFatherObject = (ObjectEntry *)hFatherObject;
	if (hFatherObject == RTS_INVALID_HANDLE)
	{
		RTS_SETRESULT(pResult, ERR_PARAMETER);
		return RTS_INVALID_HANDLE;
	}

	while (s_ObjectList[i].pszObject != NULL)
	{
		if (strlen(s_ObjectList[i].pszObject) > strlen(pFatherObject->pszObject) && strncmp(s_ObjectList[i].pszObject, pFatherObject->pszObject, strlen(pFatherObject->pszObject)) == 0)
		{
			RTS_SETRESULT(pResult, ERR_OK);
			return (RTS_HANDLE)&s_ObjectList[i];
		}
		i++;
	}

	RTS_SETRESULT(pResult, ERR_NOTIMPLEMENTED);
	return RTS_INVALID_HANDLE;
}

STATICITF_DEF RTS_HANDLE CDECL UserObjectsDBGetNextChild(RTS_HANDLE hDatabase, RTS_HANDLE hFatherObject, RTS_HANDLE hPrevChildObject, RTS_RESULT *pResult)
{
	int i = 0;
	ObjectEntry *pFatherObject = (ObjectEntry *)hFatherObject;
	if (hFatherObject == RTS_INVALID_HANDLE)
	{
		RTS_SETRESULT(pResult, ERR_PARAMETER);
		return RTS_INVALID_HANDLE;
	}

	while (s_ObjectList[i].pszObject != NULL)
	{
		/*ObjectEntry *pChildObject = (ObjectEntry *)hPrevChildObject;*/
		ObjectEntry *pObject = (ObjectEntry *)&s_ObjectList[i];
		if ((RTS_HANDLE)&s_ObjectList[i] == hPrevChildObject)
		{
			i++;
			while (s_ObjectList[i].pszObject != NULL)
			{
				char *psz = strrchr(s_ObjectList[i].pszObject, '.');
				if (psz == NULL)
					psz = strrchr(s_ObjectList[i].pszObject, '/');
				if (psz != NULL)
				{
					if (strlen(s_ObjectList[i].pszObject) > strlen(pFatherObject->pszObject) &&
						strlen(pFatherObject->pszObject) == (unsigned int)(psz-s_ObjectList[i].pszObject) &&
						strncmp(s_ObjectList[i].pszObject, pFatherObject->pszObject, strlen(pFatherObject->pszObject)) == 0)
					{
						pObject = (ObjectEntry *)&s_ObjectList[i];
						RTS_SETRESULT(pResult, ERR_OK);
						return (RTS_HANDLE)pObject;
					}
				}
				i++;
			}
			break;
		}
		i++;
	}

	RTS_SETRESULT(pResult, ERR_NOTIMPLEMENTED);
	return RTS_INVALID_HANDLE;
}

STATICITF_DEF RTS_HANDLE CDECL UserObjectsDBGetFather(RTS_HANDLE hDatabase, RTS_HANDLE hChildObject, RTS_RESULT *pResult)
{
	ObjectEntry *pObject = (ObjectEntry *)hChildObject;
	char *psz;
	int i = 0;

	if (hChildObject == RTS_INVALID_HANDLE)
	{
		RTS_SETRESULT(pResult, ERR_PARAMETER);
		return RTS_INVALID_HANDLE;
	}

	psz = strrchr(pObject->pszObject, '.');
	if (psz == NULL)
		psz = strrchr(pObject->pszObject, '/');

	if (psz == NULL)
	{
		RTS_SETRESULT(pResult, ERR_OK);
		return RTS_INVALID_HANDLE;
	}

	if (*psz == '/')
	{
		if (strlen(psz) == 1)
		{
			RTS_SETRESULT(pResult, ERR_OK);
			return RTS_INVALID_HANDLE;
		}
		psz++;
	}

	while (s_ObjectList[i].pszObject != NULL)
	{
		if (strncmp(s_ObjectList[i].pszObject, pObject->pszObject, psz - pObject->pszObject) == 0)
		{
			RTS_SETRESULT(pResult, ERR_OK);
			return (RTS_HANDLE)&s_ObjectList[i];
		}
		i++;
	}
	return ERR_OK;
}

STATICITF_DEF RTS_HANDLE CDECL UserObjectsDBGetFirstGroup(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_RESULT *pResult)
{
	GroupRightsEntry *pGroupRights;
	GroupDBEntry *pGroup;
	ObjectEntry *pObject = (ObjectEntry *)hObject;

	if (hObject == RTS_INVALID_HANDLE)
	{
		RTS_SETRESULT(pResult, ERR_PARAMETER);
		return RTS_INVALID_HANDLE;
	}

	pGroupRights = (GroupRightsEntry *)pObject->hGroupRightsList;
	pGroup = (GroupDBEntry *)pGroupRights->hGroup;

	RTS_SETRESULT(pResult, ERR_OK);
	return (RTS_HANDLE)pGroup;
}

STATICITF_DEF RTS_HANDLE CDECL UserObjectsDBGetNextGroup(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_HANDLE hPrevGroup, RTS_RESULT *pResult)
{
	GroupRightsEntry *pGroupRights;
	GroupDBEntry *pGroup;
	ObjectEntry *pObject = (ObjectEntry *)hObject;

	if (hObject == RTS_INVALID_HANDLE)
	{
		RTS_SETRESULT(pResult, ERR_PARAMETER);
		return RTS_INVALID_HANDLE;
	}

	pGroupRights = (GroupRightsEntry *)pObject->hGroupRightsList;
	while (pGroupRights->hGroup != NULL)
	{
		pGroup = (GroupDBEntry *)pGroupRights->hGroup;
		if (pGroupRights->hGroup == hPrevGroup)
		{
			pGroupRights++;
			if (pGroupRights->hGroup != NULL)
			{
				RTS_SETRESULT(pResult, ERR_OK);
				return (RTS_HANDLE)pGroupRights->hGroup;
			}
			break;
		}
		pGroupRights++;
	}

	pGroupRights =	(GroupRightsEntry *)pObject->hGroupRightsList;
	pGroup = (GroupDBEntry *)pGroupRights->hGroup;
	return (RTS_HANDLE)pGroup;
}

static RTS_HANDLE FindObject(char *pszObject, int nLen, RTS_RESULT *pResult)
{
	int i = 0;

	if (pszObject == NULL)
	{
		RTS_SETRESULT(pResult, ERR_PARAMETER);
		return RTS_INVALID_HANDLE;
	}

	while (s_ObjectList[i].pszObject != NULL)
	{
		if ((int)strlen(s_ObjectList[i].pszObject) == nLen && strncmp(s_ObjectList[i].pszObject, pszObject, nLen) == 0)
		{
			RTS_SETRESULT(pResult, ERR_OK);
			return (RTS_HANDLE)&s_ObjectList[i];
		}
		i++;
	}
	RTS_SETRESULT(pResult, ERR_PARAMETER);
	return RTS_INVALID_HANDLE;
}

STATICITF_DEF RTS_HANDLE CDECL UserObjectsDBOpen(RTS_HANDLE hDatabase, char *pszObject, RTS_RESULT *pResult)
{
	char *psz;
	RTS_HANDLE hObject;
	RTS_RESULT Result;

	if (pszObject == NULL)
	{
		RTS_SETRESULT(pResult, ERR_PARAMETER);
		return RTS_INVALID_HANDLE;
	}

	hObject = FindObject(pszObject, strlen(pszObject), &Result);
	if (hObject != RTS_INVALID_HANDLE && Result == ERR_OK)
	{
		RTS_SETRESULT(pResult, Result);
		return hObject;
	}

	/* Try to find father object */
	psz = CAL_CMUtlStrRChr(pszObject, pszObject + strlen(pszObject), '.');
	while (psz != NULL)
	{
		hObject = FindObject(pszObject, psz - pszObject, &Result);
		if (hObject != RTS_INVALID_HANDLE && Result == ERR_OK)
		{
			RTS_SETRESULT(pResult, Result);
			return hObject;
		}
		psz--;
		psz = CAL_CMUtlStrRChr(pszObject, psz, '.');
	}

	/* Try to find directory father object */
	psz = CAL_CMUtlStrRChr(pszObject, pszObject + strlen(pszObject), '/');
	while (psz != NULL)
	{
		hObject = FindObject(pszObject, psz - pszObject, &Result);
		if (hObject != RTS_INVALID_HANDLE && Result == ERR_OK)
		{
			RTS_SETRESULT(pResult, Result);
			return hObject;
		}
		psz--;
		psz = CAL_CMUtlStrRChr(pszObject, psz, '/');

		/* Root directory "/" reached */
		if (psz != NULL && psz == pszObject && *psz == '/')
		{
			hObject = FindObject(pszObject, 1, &Result);
			if (hObject != RTS_INVALID_HANDLE && Result == ERR_OK)
			{
				RTS_SETRESULT(pResult, Result);
				return hObject;
			}
			break;
		}
	}

	RTS_SETRESULT(pResult, ERR_PARAMETER);
	return RTS_INVALID_HANDLE;
}

STATICITF_DEF RTS_RESULT CDECL UserObjectsDBClose(RTS_HANDLE hDatabase, RTS_HANDLE hObject)
{
	int i = 0;

	if (hObject == RTS_INVALID_HANDLE)
		return ERR_PARAMETER;

	while (s_ObjectList[i].pszObject != NULL)
	{
		if (&s_ObjectList[i] == (ObjectEntry *)hObject)
			return ERR_OK;
		i++;
	}
	return ERR_PARAMETER;
}

STATICITF_DEF RTS_RESULT CDECL UserObjectsDBGetName(RTS_HANDLE hDatabase, RTS_HANDLE hObject, char *pszObject, int *piMaxLen)
{
	ObjectEntry *pObject = (ObjectEntry *)hObject;
	char *psz;

	if (hObject == RTS_INVALID_HANDLE || piMaxLen == NULL)
		return ERR_PARAMETER;

	psz = strrchr(pObject->pszObject, '.');
	if (psz == NULL)
		psz = strrchr(pObject->pszObject, '/');
	if (psz != NULL)
	{
		if (*psz != '/' || strlen(psz) > 1)
			psz++;
	}
	else
		psz = pObject->pszObject;

	*piMaxLen = strlen(psz) + 1;
	if (pszObject != NULL)
		CAL_CMUtlSafeStrCpy(pszObject, *piMaxLen, psz);

	return ERR_OK;
}

STATICITF_DEF RTS_RESULT CDECL UserObjectsDBGetPath(RTS_HANDLE hDatabase, RTS_HANDLE hObject, char *pszObject, int *piMaxLen)
{
	ObjectEntry *pObject = (ObjectEntry *)hObject;

	if (hObject == RTS_INVALID_HANDLE || piMaxLen == NULL)
		return ERR_PARAMETER;

	*piMaxLen = strlen(pObject->pszObject) + 1;
	if (pszObject != NULL)
		CAL_CMUtlSafeStrCpy(pszObject, *piMaxLen, pObject->pszObject);
	return ERR_OK;
}

STATICITF_DEF RTS_RESULT CDECL UserObjectsDBGetGroupRights(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_HANDLE hGroup, RTS_UI32 *pulRights, RTS_UI32 *pulDeniedRights)
{
	ObjectEntry *pObject = (ObjectEntry *)hObject;
	/*GroupDBEntry *pGroup = (GroupDBEntry *)hGroup;*/
	GroupRightsEntry *pGroupRights;

	if (hObject == RTS_INVALID_HANDLE || hGroup == RTS_INVALID_HANDLE)
		return ERR_PARAMETER;

	pGroupRights = (GroupRightsEntry *)pObject->hGroupRightsList;
	while (pGroupRights->hGroup != NULL)
	{
		/*pGroup = pGroupRights->hGroup;*/
		if (pGroupRights->hGroup == hGroup)
		{
			if (pulRights != NULL)
				*pulRights = pGroupRights->ulRights;
			if (pulDeniedRights != NULL)
				*pulDeniedRights = pGroupRights->ulDeniedRights;
			return ERR_OK;
		}
		pGroupRights++;
	}
	return ERR_PARAMETER;
}

static RTS_RESULT CDECL CheckAccessRights(RTS_UI32 ulRequestedRights, RTS_UI32 ulObjectRights, RTS_UI32 ulObjectDeniedRights)
{
	if ((ulObjectDeniedRights & ulRequestedRights) != 0)
		return ERR_NO_ACCESS_RIGHTS;

	if (((ulObjectRights & ulRequestedRights) != 0))
		return ERR_OK;
	
	return ERR_FAILED;
}

STATICITF_DEF RTS_RESULT CDECL UserObjectsDBHasRights(RTS_HANDLE hDatabase, char *pszObject, RTS_HANDLE hUser, RTS_UI32 ulRights)
{
	RTS_RESULT Result;
	RTS_UI32 ulObjectRights = USERDB_RIGHT_NONE;
	RTS_UI32 ulObjectDeniedRights = USERDB_RIGHT_NONE;

	if (pszObject == NULL || hUser == RTS_INVALID_HANDLE)
		return ERR_PARAMETER;

	Result = UserObjectsDBGetRights(s_hUserObjectsDB, pszObject, hUser, &ulObjectRights, &ulObjectDeniedRights);
	if (Result != ERR_OK)
		return Result;

	return CheckAccessRights(ulRights, ulObjectRights, ulObjectDeniedRights);
}

static int IsAdministatorGroup(RTS_HANDLE hGroup)
{

	char *pszName;

	pszName = UserGroupsDBGetName(RTS_INVALID_HANDLE, hGroup, NULL);
	if (pszName != NULL)
	{
		/* Member of the owner group has all rights! */
		if (strcmp(pszName, USERDB_GROUP_ADMINISTRATOR) == 0 || strcmp(pszName, "Owner") == 0)
		{
			return 1;
		}
	}
	return 0;
}

static RTS_RESULT ObjectGetRights(RTS_HANDLE hObject, RTS_HANDLE hUser, RTS_UI32 *pulRights, RTS_UI32 *pulDeniedRights)
{
	ObjectEntry *pObject;
	GroupRightsEntry *pGroupRights;

	if (hObject == RTS_INVALID_HANDLE || hUser == RTS_INVALID_HANDLE || pulRights == NULL || pulDeniedRights == NULL)
		return ERR_PARAMETER;

	pObject = (ObjectEntry *)hObject;

	/* Check, if user is in object group list */
	pGroupRights = (GroupRightsEntry *)pObject->hGroupRightsList;
	while (pGroupRights->hGroup != RTS_INVALID_HANDLE)
	{
		if (CAL_UserMgrGroupHasUser(pGroupRights->hGroup, hUser))
		{
			*pulRights |= pGroupRights->ulRights;
			*pulDeniedRights |= pGroupRights->ulDeniedRights;
		}
		pGroupRights++;
	}

	return ERR_OK;
}

STATICITF_DEF RTS_RESULT CDECL UserObjectsDBGetRights(RTS_HANDLE hDatabase, char *pszObject, RTS_HANDLE hUser, RTS_UI32 *pulRights, RTS_UI32 *pulDeniedRights)
{
	RTS_HANDLE hObject;
	RTS_RESULT Result;
	ObjectEntry *pObject;
	RTS_UI32 ulResRights = USERDB_RIGHT_NONE;
	RTS_UI32 ulResRightsHit = USERDB_RIGHT_NONE;
	RTS_UI32 ulResDeniedRights = USERDB_RIGHT_NONE;
	RTS_UI32 ulRight;

	if (pszObject == NULL || hUser == RTS_INVALID_HANDLE || pulRights == NULL || pulDeniedRights == NULL)
		return ERR_PARAMETER;

	if (CAL_UserMgrIsAdministrator(hUser))
	{
		*pulRights = USERDB_RIGHT_ALL;
		*pulDeniedRights = USERDB_RIGHT_NONE;
		return ERR_OK;
	}

	*pulRights = USERDB_RIGHT_NONE;
	*pulDeniedRights = USERDB_RIGHT_NONE;

	hObject = UserObjectsDBOpen(s_hUserObjectsDB, pszObject, &Result);
	if (hObject == RTS_INVALID_HANDLE)
		return ERR_PARAMETER;

	pObject = (ObjectEntry *)hObject;

	/* gather all (inherited) rights by walking up the tree, checking all rights (i.e. bit by bit) */
	/* and save the first hit separately for every right */
	while (hObject != RTS_INVALID_HANDLE)
	{
		(void)ObjectGetRights(hObject, hUser, pulRights, pulDeniedRights);

		for (ulRight = USERDB_RIGHT_VIEW; ulRight != 0; ulRight <<= 1)
		{
			if ((ulResRightsHit & ulRight) == 0)
			{
				if (*pulRights & ulRight)
				{
					ulResRights |= ulRight;
					ulResRightsHit |= ulRight;
				}
				else if (*pulDeniedRights & ulRight)
				{
					ulResDeniedRights |= ulRight;
					ulResRightsHit |= ulRight;
				}
			}
		}

		hObject = UserObjectsDBGetFather(s_hUserObjectsDB, hObject, NULL);
	}

	*pulRights = ulResRights & pObject->ulUsedRights;
	*pulDeniedRights = ulResDeniedRights | ~(pObject->ulUsedRights);

	return ERR_OK;
}

STATICITF_DEF RTS_RESULT CDECL UserObjectsDBActivate(RTS_HANDLE hDatabase)
{
	return ERR_OK;
}

#endif

/* CmpUserObjectsDBConfig Implementation: optional */
#if 1

STATICITF_DEF RTS_RESULT CDECL UserObjectsDBConfigLoad(RTS_HANDLE hDatabase)
{
	return ERR_NOTIMPLEMENTED;
}

STATICITF_DEF RTS_RESULT CDECL UserObjectsDBConfigStore(RTS_HANDLE hDatabase)
{
	return ERR_NOTIMPLEMENTED;
}

STATICITF_DEF RTS_RESULT CDECL UserObjectsDBConfigReleaseRights(RTS_HANDLE hDatabase)
{
	return ERR_NOTIMPLEMENTED;
}

STATICITF_DEF RTS_RESULT CDECL UserObjectsDBConfigRelease(RTS_HANDLE hDatabase)
{
	return ERR_NOTIMPLEMENTED;
}

STATICITF_DEF RTS_HANDLE CDECL UserObjectsDBConfigAdd(RTS_HANDLE hDatabase, char *pszObject, RTS_RESULT *pResult)
{
	RTS_SETRESULT(pResult, ERR_NOTIMPLEMENTED);
	return RTS_INVALID_HANDLE;
}

STATICITF_DEF RTS_HANDLE CDECL UserObjectsDBConfigAdd2(RTS_HANDLE hDatabase, char *pszObject, RTS_UI32 properties, RTS_RESULT *pResult)
{
	RTS_SETRESULT(pResult, ERR_NOTIMPLEMENTED);
	return RTS_INVALID_HANDLE;
}

STATICITF_DEF RTS_RESULT CDECL UserObjectsDBConfigRemove(RTS_HANDLE hDatabase, RTS_HANDLE hObject)
{
	return ERR_NOTIMPLEMENTED;
}

STATICITF_DEF RTS_HANDLE CDECL UserObjectsDBConfigAddChild(RTS_HANDLE hDatabase, RTS_HANDLE hFatherObject, char *pszObject, RTS_RESULT *pResult)
{
	RTS_SETRESULT(pResult, ERR_NOTIMPLEMENTED);
	return RTS_INVALID_HANDLE;
}

STATICITF_DEF RTS_RESULT CDECL UserObjectsDBConfigSetUsedRights(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_UI32 ulUsedRights)
{
	return ERR_NOTIMPLEMENTED;
}

STATICITF_DEF RTS_RESULT CDECL UserObjectsDBConfigSetID(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_UI32 ulID)
{
	return ERR_NOTIMPLEMENTED;
}

STATICITF_DEF RTS_RESULT CDECL UserObjectsDBConfigAddGroup(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_HANDLE hGroup)
{
	return ERR_NOTIMPLEMENTED;
}

STATICITF_DEF RTS_RESULT CDECL UserObjectsDBConfigRemoveGroup(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_HANDLE hGroup)
{
	return ERR_NOTIMPLEMENTED;
}

STATICITF_DEF RTS_RESULT CDECL UserObjectsDBConfigSetGroupRights(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_HANDLE hGroup, RTS_UI32 ulRights)
{
	return ERR_NOTIMPLEMENTED;
}

STATICITF_DEF RTS_RESULT CDECL UserObjectsDBConfigSetGroupDeniedRights(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_HANDLE hGroup, RTS_UI32 ulDeniedRights)
{
	return ERR_NOTIMPLEMENTED;
}

STATICITF_DEF RTS_RESULT CDECL UserObjectsDBConfigClearRights(RTS_HANDLE hDatabase, RTS_HANDLE hObject)
{
	return ERR_NOTIMPLEMENTED;
}

#endif

