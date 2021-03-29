/***********************************************************************
 * DO NOT MODIFY!
 * This is a generated file. Do not modify it's contents directly
 ***********************************************************************/








#include "CmpUserDBTemplate.c"




/* NOTE: REPLACE 0x0001 BY YOUR VENDORID */

#define CMPID_CmpUserDBTemplate		0x2000								/* NOTE: START HERE WITH YOUR COMPONENTIDS (see CmpItf.h */
#define CLASSID_CCmpUserDBTemplate	ADDVENDORID(CMP_VENDORID, 0x2000)	/* NOTE: START HERE WITH YOUR CLASSIDS (see CmpItf.h */
#define ITFID_ICmpUserDBTemplate		ADDVENDORID(CMP_VENDORID, 0x2000)	/* NOTE: START HERE WITH YOUR INTERFACEIDS (see CmpItf.h */





RTS_RESULT CDECL CCmpUserDBTemplate::IUserDBAuthenticate(char *pszUser, UserMgrCredentials *pCredentials, RTS_UI32 *pUserProperty)
{
	return UserDBAuthenticate(hCmpUserDBTemplate,pszUser,pCredentials,pUserProperty);
}

char* CDECL CCmpUserDBTemplate::IUserDBGetFirstUser(RTS_HANDLE *hIterator, RTS_UI32 *pUserProperty, RTS_RESULT *pResult)
{
	return UserDBGetFirstUser(hCmpUserDBTemplate,hIterator,pUserProperty,pResult);
}

char* CDECL CCmpUserDBTemplate::IUserDBGetNextUser(RTS_HANDLE *hIterator, RTS_UI32 *pUserProperty, RTS_RESULT *pResult)
{
	return UserDBGetNextUser(hCmpUserDBTemplate,hIterator,pUserProperty,pResult);
}





RTS_RESULT CDECL CCmpUserDBTemplate::IUserDBConfigRelease(void)
{
	return UserDBConfigRelease(hCmpUserDBTemplate);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserDBConfigImport(RTS_UI8 *pData, RTS_SIZE dataSize)
{
	return UserDBConfigImport(hCmpUserDBTemplate,pData,dataSize);
}

RTS_SIZE CDECL CCmpUserDBTemplate::IUserDBConfigExport(RTS_UI8 *pData, RTS_SIZE maxSize, RTS_RESULT *pResult)
{
	return UserDBConfigExport(hCmpUserDBTemplate,pData,maxSize,pResult);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserDBConfigAddUser(char *pszUser, UserMgrCredentials *pCredentials)
{
	return UserDBConfigAddUser(hCmpUserDBTemplate,pszUser,pCredentials);
}

RTS_BOOL CDECL CCmpUserDBTemplate::IUserDBConfigExistsUser(char *pszUser)
{
	return UserDBConfigExistsUser(hCmpUserDBTemplate,pszUser);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserDBConfigRemoveUser(char *pszUser)
{
	return UserDBConfigRemoveUser(hCmpUserDBTemplate,pszUser);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserDBConfigSetUserCredentials(char *pszUser, UserMgrCredentials *pCredentials)
{
	return UserDBConfigSetUserCredentials(hCmpUserDBTemplate,pszUser,pCredentials);
}

RTS_UI32 CDECL CCmpUserDBTemplate::IUserDBConfigGetUserProperty(char *pszUser, RTS_RESULT *pResult)
{
	return UserDBConfigGetUserProperty(hCmpUserDBTemplate,pszUser,pResult);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserDBConfigSetUserProperty(char *pszUser, RTS_UI32 property)
{
	return UserDBConfigSetUserProperty(hCmpUserDBTemplate,pszUser,property);
}





RTS_HANDLE CDECL CCmpUserDBTemplate::IUserGroupsDBGetGroup(char *pszGroupName, RTS_RESULT *pResult)
{
	return UserGroupsDBGetGroup(hCmpUserDBTemplate,pszGroupName,pResult);
}

RTS_HANDLE CDECL CCmpUserDBTemplate::IUserGroupsDBGetFirstGroup(RTS_RESULT *pResult)
{
	return UserGroupsDBGetFirstGroup(hCmpUserDBTemplate,pResult);
}

RTS_HANDLE CDECL CCmpUserDBTemplate::IUserGroupsDBGetNextGroup(RTS_HANDLE hPrevGroup, RTS_RESULT *pResult)
{
	return UserGroupsDBGetNextGroup(hCmpUserDBTemplate,hPrevGroup,pResult);
}

char* CDECL CCmpUserDBTemplate::IUserGroupsDBGetName(RTS_HANDLE hGroup, RTS_RESULT *pResult)
{
	return UserGroupsDBGetName(hCmpUserDBTemplate,hGroup,pResult);
}

RTS_UI32 CDECL CCmpUserDBTemplate::IUserGroupsDBGetProperty(RTS_HANDLE hGroup, RTS_RESULT *pResult)
{
	return UserGroupsDBGetProperty(hCmpUserDBTemplate,hGroup,pResult);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserGroupsDBGroupHasUser(RTS_HANDLE hGroup, char *pszUser)
{
	return UserGroupsDBGroupHasUser(hCmpUserDBTemplate,hGroup,pszUser);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserGroupsDBGroupHasMember(RTS_HANDLE hGroup, RTS_HANDLE hGroupMember)
{
	return UserGroupsDBGroupHasMember(hCmpUserDBTemplate,hGroup,hGroupMember);
}

char* CDECL CCmpUserDBTemplate::IUserGroupsDBGetFirstUser(RTS_HANDLE hGroup, RTS_HANDLE *phIterator, RTS_RESULT *pResult)
{
	return UserGroupsDBGetFirstUser(hCmpUserDBTemplate,hGroup,phIterator,pResult);
}

char* CDECL CCmpUserDBTemplate::IUserGroupsDBGetNextUser(RTS_HANDLE hGroup, RTS_HANDLE *phIterator, RTS_RESULT *pResult)
{
	return UserGroupsDBGetNextUser(hCmpUserDBTemplate,hGroup,phIterator,pResult);
}

RTS_HANDLE CDECL CCmpUserDBTemplate::IUserGroupsDBGetFirstGroupMember(RTS_HANDLE hGroup, RTS_RESULT *pResult)
{
	return UserGroupsDBGetFirstGroupMember(hCmpUserDBTemplate,hGroup,pResult);
}

RTS_HANDLE CDECL CCmpUserDBTemplate::IUserGroupsDBGetNextGroupMember(RTS_HANDLE hGroup, RTS_HANDLE hPrevMember, RTS_RESULT *pResult)
{
	return UserGroupsDBGetNextGroupMember(hCmpUserDBTemplate,hGroup,hPrevMember,pResult);
}





RTS_RESULT CDECL CCmpUserDBTemplate::IUserGroupsDBConfigRelease(void)
{
	return UserGroupsDBConfigRelease(hCmpUserDBTemplate);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserGroupsDBConfigImport(RTS_UI8 *pData, RTS_SIZE dataSize)
{
	return UserGroupsDBConfigImport(hCmpUserDBTemplate,pData,dataSize);
}

RTS_SIZE CDECL CCmpUserDBTemplate::IUserGroupsDBConfigExport(RTS_UI8 *pData, RTS_SIZE maxSize, RTS_RESULT *pResult)
{
	return UserGroupsDBConfigExport(hCmpUserDBTemplate,pData,maxSize,pResult);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserGroupsDBConfigAdd(char *pszGroup)
{
	return UserGroupsDBConfigAdd(hCmpUserDBTemplate,pszGroup);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserGroupsDBConfigRemove(char *pszGroup)
{
	return UserGroupsDBConfigRemove(hCmpUserDBTemplate,pszGroup);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserGroupsDBConfigSetProperty(char *pszGroup, RTS_UI32 ulProperty)
{
	return UserGroupsDBConfigSetProperty(hCmpUserDBTemplate,pszGroup,ulProperty);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserGroupsDBConfigAddUser(char *pszGroup, char *pszUser)
{
	return UserGroupsDBConfigAddUser(hCmpUserDBTemplate,pszGroup,pszUser);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserGroupsDBConfigRemoveUser(char *pszGroup, char *pszUser)
{
	return UserGroupsDBConfigRemoveUser(hCmpUserDBTemplate,pszGroup,pszUser);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserGroupsDBConfigAddMember(char *pszGroup, char *pszGroupToAdd)
{
	return UserGroupsDBConfigAddMember(hCmpUserDBTemplate,pszGroup,pszGroupToAdd);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserGroupsDBConfigRemoveMember(char *pszGroup, char *pszGroupToRemove)
{
	return UserGroupsDBConfigRemoveMember(hCmpUserDBTemplate,pszGroup,pszGroupToRemove);
}





RTS_RESULT CDECL CCmpUserDBTemplate::IUserObjectsDBGetUsedRights(RTS_HANDLE hObject, RTS_UI32 *pulUsedRights)
{
	return UserObjectsDBGetUsedRights(hCmpUserDBTemplate,hObject,pulUsedRights);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserObjectsDBGetProperties(RTS_HANDLE hObject, RTS_UI32 *pulProperties)
{
	return UserObjectsDBGetProperties(hCmpUserDBTemplate,hObject,pulProperties);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserObjectsDBGetID(RTS_HANDLE hObject, RTS_UI32 *pulID)
{
	return UserObjectsDBGetID(hCmpUserDBTemplate,hObject,pulID);
}

RTS_HANDLE CDECL CCmpUserDBTemplate::IUserObjectsDBGetFirst(RTS_RESULT *pResult)
{
	return UserObjectsDBGetFirst(hCmpUserDBTemplate,pResult);
}

RTS_HANDLE CDECL CCmpUserDBTemplate::IUserObjectsDBGetNext(RTS_HANDLE hPrevObject, RTS_RESULT *pResult)
{
	return UserObjectsDBGetNext(hCmpUserDBTemplate,hPrevObject,pResult);
}

RTS_HANDLE CDECL CCmpUserDBTemplate::IUserObjectsDBOpen(char *pszObject, RTS_RESULT *pResult)
{
	return UserObjectsDBOpen(hCmpUserDBTemplate,pszObject,pResult);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserObjectsDBClose(RTS_HANDLE hObject)
{
	return UserObjectsDBClose(hCmpUserDBTemplate,hObject);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserObjectsDBGetName(RTS_HANDLE hObject, char *pszObject, int *piMaxLen)
{
	return UserObjectsDBGetName(hCmpUserDBTemplate,hObject,pszObject,piMaxLen);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserObjectsDBGetPath(RTS_HANDLE hObject, char *pszObject, int *piMaxLen)
{
	return UserObjectsDBGetPath(hCmpUserDBTemplate,hObject,pszObject,piMaxLen);
}

RTS_HANDLE CDECL CCmpUserDBTemplate::IUserObjectsDBGetFirstChild(RTS_HANDLE hFatherObject, RTS_RESULT *pResult)
{
	return UserObjectsDBGetFirstChild(hCmpUserDBTemplate,hFatherObject,pResult);
}

RTS_HANDLE CDECL CCmpUserDBTemplate::IUserObjectsDBGetNextChild(RTS_HANDLE hFatherObject, RTS_HANDLE hPrevChildObject, RTS_RESULT *pResult)
{
	return UserObjectsDBGetNextChild(hCmpUserDBTemplate,hFatherObject,hPrevChildObject,pResult);
}

RTS_HANDLE CDECL CCmpUserDBTemplate::IUserObjectsDBGetFather(RTS_HANDLE hChildObject, RTS_RESULT *pResult)
{
	return UserObjectsDBGetFather(hCmpUserDBTemplate,hChildObject,pResult);
}

RTS_HANDLE CDECL CCmpUserDBTemplate::IUserObjectsDBGetFirstGroup(RTS_HANDLE hObject, RTS_RESULT *pResult)
{
	return UserObjectsDBGetFirstGroup(hCmpUserDBTemplate,hObject,pResult);
}

RTS_HANDLE CDECL CCmpUserDBTemplate::IUserObjectsDBGetNextGroup(RTS_HANDLE hObject, RTS_HANDLE hPrevGroup, RTS_RESULT *pResult)
{
	return UserObjectsDBGetNextGroup(hCmpUserDBTemplate,hObject,hPrevGroup,pResult);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserObjectsDBGetGroupRights(RTS_HANDLE hObject, RTS_HANDLE hGroup, RTS_UI32 *pulRights, RTS_UI32 *pulDeniedRights)
{
	return UserObjectsDBGetGroupRights(hCmpUserDBTemplate,hObject,hGroup,pulRights,pulDeniedRights);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserObjectsDBHasRights(char *pszObject, RTS_HANDLE hUser, RTS_UI32 ulRequestedRights)
{
	return UserObjectsDBHasRights(hCmpUserDBTemplate,pszObject,hUser,ulRequestedRights);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserObjectsDBGetRights(char *pszObject, RTS_HANDLE hUser, RTS_UI32 *pulRights, RTS_UI32 *pulDeniedRights)
{
	return UserObjectsDBGetRights(hCmpUserDBTemplate,pszObject,hUser,pulRights,pulDeniedRights);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserObjectsDBActivate(void)
{
	return UserObjectsDBActivate(hCmpUserDBTemplate);
}





RTS_RESULT CDECL CCmpUserDBTemplate::IUserObjectsDBConfigLoad(void)
{
	return UserObjectsDBConfigLoad(hCmpUserDBTemplate);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserObjectsDBConfigStore(void)
{
	return UserObjectsDBConfigStore(hCmpUserDBTemplate);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserObjectsDBConfigRelease(void)
{
	return UserObjectsDBConfigRelease(hCmpUserDBTemplate);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserObjectsDBConfigReleaseRights(void)
{
	return UserObjectsDBConfigReleaseRights(hCmpUserDBTemplate);
}

RTS_HANDLE CDECL CCmpUserDBTemplate::IUserObjectsDBConfigAdd(char *pszObject, RTS_RESULT *pResult)
{
	return UserObjectsDBConfigAdd(hCmpUserDBTemplate,pszObject,pResult);
}

RTS_HANDLE CDECL CCmpUserDBTemplate::IUserObjectsDBConfigAdd2(char *pszObject, RTS_UI32 properties, RTS_RESULT *pResult)
{
	return UserObjectsDBConfigAdd2(hCmpUserDBTemplate,pszObject,properties,pResult);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserObjectsDBConfigRemove(RTS_HANDLE hObject)
{
	return UserObjectsDBConfigRemove(hCmpUserDBTemplate,hObject);
}

RTS_HANDLE CDECL CCmpUserDBTemplate::IUserObjectsDBConfigAddChild(RTS_HANDLE hFatherObject, char *pszObject, RTS_RESULT *pResult)
{
	return UserObjectsDBConfigAddChild(hCmpUserDBTemplate,hFatherObject,pszObject,pResult);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserObjectsDBConfigSetUsedRights(RTS_HANDLE hObject, RTS_UI32 ulUsedRights)
{
	return UserObjectsDBConfigSetUsedRights(hCmpUserDBTemplate,hObject,ulUsedRights);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserObjectsDBConfigSetID(RTS_HANDLE hObject, RTS_UI32 ulID)
{
	return UserObjectsDBConfigSetID(hCmpUserDBTemplate,hObject,ulID);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserObjectsDBConfigAddGroup(RTS_HANDLE hObject, RTS_HANDLE hGroup)
{
	return UserObjectsDBConfigAddGroup(hCmpUserDBTemplate,hObject,hGroup);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserObjectsDBConfigRemoveGroup(RTS_HANDLE hObject, RTS_HANDLE hGroup)
{
	return UserObjectsDBConfigRemoveGroup(hCmpUserDBTemplate,hObject,hGroup);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserObjectsDBConfigSetGroupRights(RTS_HANDLE hObject, RTS_HANDLE hGroup, RTS_UI32 ulRights)
{
	return UserObjectsDBConfigSetGroupRights(hCmpUserDBTemplate,hObject,hGroup,ulRights);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserObjectsDBConfigSetGroupDeniedRights(RTS_HANDLE hObject, RTS_HANDLE hGroup, RTS_UI32 ulDeniedRights)
{
	return UserObjectsDBConfigSetGroupDeniedRights(hCmpUserDBTemplate,hObject,hGroup,ulDeniedRights);
}

RTS_RESULT CDECL CCmpUserDBTemplate::IUserObjectsDBConfigClearRights(RTS_HANDLE hObject)
{
	return UserObjectsDBConfigClearRights(hCmpUserDBTemplate,hObject);
}






