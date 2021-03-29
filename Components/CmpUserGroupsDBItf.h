 /**
 * <interfacename>CmpUserGroupsDB</interfacename>
 * <description> 
 *	This interface provides the minimal set of functions that must be implemented to replace the default CODESYS user database. 
 *	
 *  All user groups and their assigned users are managed and stored here.
 * </description>
 *
 * <copyright>
 * Copyright (c) 2019 CODESYS Development GmbH. All rights reserved.
 * </copyright>
 */


	
	
#ifndef _CMPUSERGROUPSDBITF_H_
#define _CMPUSERGROUPSDBITF_H_

#include "CmpStd.h"

 

 




STATICITF_DEF RTS_HANDLE CDECL UserGroupsDBGetGroup(RTS_HANDLE hDatabase, char *pszGroupName, RTS_RESULT *pResult);
typedef RTS_HANDLE (CDECL * PFUSERGROUPSDBGETGROUP) (RTS_HANDLE hDatabase, char *pszGroupName, RTS_RESULT *pResult);
#if defined(CMPUSERGROUPSDB_NOTIMPLEMENTED) || defined(USERGROUPSDBGETGROUP_NOTIMPLEMENTED)
	#define USE_UserGroupsDBGetGroup
	#define EXT_UserGroupsDBGetGroup
	#define GET_UserGroupsDBGetGroup(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserGroupsDBGetGroup(p0,p1,p2)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_UserGroupsDBGetGroup  FALSE
	#define EXP_UserGroupsDBGetGroup  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserGroupsDBGetGroup
	#define EXT_UserGroupsDBGetGroup
	#define GET_UserGroupsDBGetGroup(fl)  ERR_OK
	#define CAL_UserGroupsDBGetGroup(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetGroup(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBGetGroup  TRUE
	#define EXP_UserGroupsDBGetGroup  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSERGROUPSDB_EXTERNAL)
	#define USE_UserGroupsDBGetGroup
	#define EXT_UserGroupsDBGetGroup
	#define GET_UserGroupsDBGetGroup(fl)  ERR_OK
	#define CAL_UserGroupsDBGetGroup(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetGroup(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBGetGroup  TRUE
	#define EXP_UserGroupsDBGetGroup  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserGroupsDBUserGroupsDBGetGroup
	#define EXT_CmpUserGroupsDBUserGroupsDBGetGroup
	#define GET_CmpUserGroupsDBUserGroupsDBGetGroup  ERR_OK
	#define CAL_CmpUserGroupsDBUserGroupsDBGetGroup(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetGroup(p1,p2))
	#define CHK_CmpUserGroupsDBUserGroupsDBGetGroup  TRUE
	#define EXP_CmpUserGroupsDBUserGroupsDBGetGroup  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserGroupsDBGetGroup
	#define EXT_UserGroupsDBGetGroup
	#define GET_UserGroupsDBGetGroup(fl)  ERR_OK
	#define CAL_UserGroupsDBGetGroup(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetGroup(p1,p2))
	#define CHK_UserGroupsDBGetGroup  TRUE
	#define EXP_UserGroupsDBGetGroup  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserGroupsDBGetGroup
	#define EXT_UserGroupsDBGetGroup
	#define GET_UserGroupsDBGetGroup(fl)  ERR_OK
	#define CAL_UserGroupsDBGetGroup(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetGroup(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBGetGroup  TRUE
	#define EXP_UserGroupsDBGetGroup  ERR_OK
#endif




/**
 * <description>Iteration interface to get the first group to which the user is assigned
 * NOTE: The required user handle is not compatible with a handle from the UserMgr, and these handles must not be mixed.
 * A UserMgr handle can be converted to a UserDB handle by using UserMgrGetUserDBHandle().
 * </description>
 * <param name="hUser" type="IN">Handle to the user</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">First user group available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid user handle</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">No user group configured</errorcode>
 * <result>Handle to the first user group or RTS_INVALID_HANDLE if failed</result>
 */
STATICITF_DEF RTS_HANDLE CDECL UserGroupsDBGetFirstGroup(RTS_HANDLE hDatabase, RTS_RESULT *pResult);
typedef RTS_HANDLE (CDECL * PFUSERGROUPSDBGETFIRSTGROUP) (RTS_HANDLE hDatabase, RTS_RESULT *pResult);
#if defined(CMPUSERGROUPSDB_NOTIMPLEMENTED) || defined(USERGROUPSDBGETFIRSTGROUP_NOTIMPLEMENTED)
	#define USE_UserGroupsDBGetFirstGroup
	#define EXT_UserGroupsDBGetFirstGroup
	#define GET_UserGroupsDBGetFirstGroup(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserGroupsDBGetFirstGroup(p0,p1)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_UserGroupsDBGetFirstGroup  FALSE
	#define EXP_UserGroupsDBGetFirstGroup  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserGroupsDBGetFirstGroup
	#define EXT_UserGroupsDBGetFirstGroup
	#define GET_UserGroupsDBGetFirstGroup(fl)  ERR_OK
	#define CAL_UserGroupsDBGetFirstGroup(p0,p1) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetFirstGroup(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1))
	#define CHK_UserGroupsDBGetFirstGroup  TRUE
	#define EXP_UserGroupsDBGetFirstGroup  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSERGROUPSDB_EXTERNAL)
	#define USE_UserGroupsDBGetFirstGroup
	#define EXT_UserGroupsDBGetFirstGroup
	#define GET_UserGroupsDBGetFirstGroup(fl)  ERR_OK
	#define CAL_UserGroupsDBGetFirstGroup(p0,p1) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetFirstGroup(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1))
	#define CHK_UserGroupsDBGetFirstGroup  TRUE
	#define EXP_UserGroupsDBGetFirstGroup  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserGroupsDBUserGroupsDBGetFirstGroup
	#define EXT_CmpUserGroupsDBUserGroupsDBGetFirstGroup
	#define GET_CmpUserGroupsDBUserGroupsDBGetFirstGroup  ERR_OK
	#define CAL_CmpUserGroupsDBUserGroupsDBGetFirstGroup(p0,p1)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetFirstGroup(p1))
	#define CHK_CmpUserGroupsDBUserGroupsDBGetFirstGroup  TRUE
	#define EXP_CmpUserGroupsDBUserGroupsDBGetFirstGroup  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserGroupsDBGetFirstGroup
	#define EXT_UserGroupsDBGetFirstGroup
	#define GET_UserGroupsDBGetFirstGroup(fl)  ERR_OK
	#define CAL_UserGroupsDBGetFirstGroup(p0,p1)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetFirstGroup(p1))
	#define CHK_UserGroupsDBGetFirstGroup  TRUE
	#define EXP_UserGroupsDBGetFirstGroup  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserGroupsDBGetFirstGroup
	#define EXT_UserGroupsDBGetFirstGroup
	#define GET_UserGroupsDBGetFirstGroup(fl)  ERR_OK
	#define CAL_UserGroupsDBGetFirstGroup(p0,p1) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetFirstGroup(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1))
	#define CHK_UserGroupsDBGetFirstGroup  TRUE
	#define EXP_UserGroupsDBGetFirstGroup  ERR_OK
#endif




/**
 * <description>Iteration interface to get next configured user group to which the user is assigned. Must be started with UserDBGetFirstGroup()
 * NOTE: The required user handle is not compatible with a handle from the UserMgr, and these handles must not be mixed.
 * A UserMgr handle can be converted to a UserDB handle by using UserMgrGetUserDBHandle().
 * </description>
 * <param name="hUser" type="IN">Handle to the user</param>
 * <param name="hPrevGroup" type="IN">Handle to the previous user group retrieved via UserDBGetFirstGroup() or subsequent calls of UserDBGetNextGroup()</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Next user group available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">No next user group available</errorcode>
 * <result>Handle to the next user group or RTS_INVALID_HANDLE if failed</result>
 */
STATICITF_DEF RTS_HANDLE CDECL UserGroupsDBGetNextGroup(RTS_HANDLE hDatabase, RTS_HANDLE hPrevGroup, RTS_RESULT *pResult);
typedef RTS_HANDLE (CDECL * PFUSERGROUPSDBGETNEXTGROUP) (RTS_HANDLE hDatabase, RTS_HANDLE hPrevGroup, RTS_RESULT *pResult);
#if defined(CMPUSERGROUPSDB_NOTIMPLEMENTED) || defined(USERGROUPSDBGETNEXTGROUP_NOTIMPLEMENTED)
	#define USE_UserGroupsDBGetNextGroup
	#define EXT_UserGroupsDBGetNextGroup
	#define GET_UserGroupsDBGetNextGroup(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserGroupsDBGetNextGroup(p0,p1,p2)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_UserGroupsDBGetNextGroup  FALSE
	#define EXP_UserGroupsDBGetNextGroup  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserGroupsDBGetNextGroup
	#define EXT_UserGroupsDBGetNextGroup
	#define GET_UserGroupsDBGetNextGroup(fl)  ERR_OK
	#define CAL_UserGroupsDBGetNextGroup(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetNextGroup(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBGetNextGroup  TRUE
	#define EXP_UserGroupsDBGetNextGroup  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSERGROUPSDB_EXTERNAL)
	#define USE_UserGroupsDBGetNextGroup
	#define EXT_UserGroupsDBGetNextGroup
	#define GET_UserGroupsDBGetNextGroup(fl)  ERR_OK
	#define CAL_UserGroupsDBGetNextGroup(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetNextGroup(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBGetNextGroup  TRUE
	#define EXP_UserGroupsDBGetNextGroup  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserGroupsDBUserGroupsDBGetNextGroup
	#define EXT_CmpUserGroupsDBUserGroupsDBGetNextGroup
	#define GET_CmpUserGroupsDBUserGroupsDBGetNextGroup  ERR_OK
	#define CAL_CmpUserGroupsDBUserGroupsDBGetNextGroup(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetNextGroup(p1,p2))
	#define CHK_CmpUserGroupsDBUserGroupsDBGetNextGroup  TRUE
	#define EXP_CmpUserGroupsDBUserGroupsDBGetNextGroup  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserGroupsDBGetNextGroup
	#define EXT_UserGroupsDBGetNextGroup
	#define GET_UserGroupsDBGetNextGroup(fl)  ERR_OK
	#define CAL_UserGroupsDBGetNextGroup(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetNextGroup(p1,p2))
	#define CHK_UserGroupsDBGetNextGroup  TRUE
	#define EXP_UserGroupsDBGetNextGroup  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserGroupsDBGetNextGroup
	#define EXT_UserGroupsDBGetNextGroup
	#define GET_UserGroupsDBGetNextGroup(fl)  ERR_OK
	#define CAL_UserGroupsDBGetNextGroup(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetNextGroup(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBGetNextGroup  TRUE
	#define EXP_UserGroupsDBGetNextGroup  ERR_OK
#endif






STATICITF_DEF char* CDECL UserGroupsDBGetName(RTS_HANDLE hDatabase, RTS_HANDLE hGroup, RTS_RESULT *pResult);
typedef char* (CDECL * PFUSERGROUPSDBGETNAME) (RTS_HANDLE hDatabase, RTS_HANDLE hGroup, RTS_RESULT *pResult);
#if defined(CMPUSERGROUPSDB_NOTIMPLEMENTED) || defined(USERGROUPSDBGETNAME_NOTIMPLEMENTED)
	#define USE_UserGroupsDBGetName
	#define EXT_UserGroupsDBGetName
	#define GET_UserGroupsDBGetName(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserGroupsDBGetName(p0,p1,p2)  (char*)ERR_NOTIMPLEMENTED
	#define CHK_UserGroupsDBGetName  FALSE
	#define EXP_UserGroupsDBGetName  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserGroupsDBGetName
	#define EXT_UserGroupsDBGetName
	#define GET_UserGroupsDBGetName(fl)  ERR_OK
	#define CAL_UserGroupsDBGetName(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetName(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBGetName  TRUE
	#define EXP_UserGroupsDBGetName  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSERGROUPSDB_EXTERNAL)
	#define USE_UserGroupsDBGetName
	#define EXT_UserGroupsDBGetName
	#define GET_UserGroupsDBGetName(fl)  ERR_OK
	#define CAL_UserGroupsDBGetName(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetName(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBGetName  TRUE
	#define EXP_UserGroupsDBGetName  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserGroupsDBUserGroupsDBGetName
	#define EXT_CmpUserGroupsDBUserGroupsDBGetName
	#define GET_CmpUserGroupsDBUserGroupsDBGetName  ERR_OK
	#define CAL_CmpUserGroupsDBUserGroupsDBGetName(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetName(p1,p2))
	#define CHK_CmpUserGroupsDBUserGroupsDBGetName  TRUE
	#define EXP_CmpUserGroupsDBUserGroupsDBGetName  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserGroupsDBGetName
	#define EXT_UserGroupsDBGetName
	#define GET_UserGroupsDBGetName(fl)  ERR_OK
	#define CAL_UserGroupsDBGetName(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetName(p1,p2))
	#define CHK_UserGroupsDBGetName  TRUE
	#define EXP_UserGroupsDBGetName  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserGroupsDBGetName
	#define EXT_UserGroupsDBGetName
	#define GET_UserGroupsDBGetName(fl)  ERR_OK
	#define CAL_UserGroupsDBGetName(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetName(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBGetName  TRUE
	#define EXP_UserGroupsDBGetName  ERR_OK
#endif




STATICITF_DEF RTS_UI32 CDECL UserGroupsDBGetProperty(RTS_HANDLE hDatabase, RTS_HANDLE hGroup, RTS_RESULT *pResult);
typedef RTS_UI32 (CDECL * PFUSERGROUPSDBGETPROPERTY) (RTS_HANDLE hDatabase, RTS_HANDLE hGroup, RTS_RESULT *pResult);
#if defined(CMPUSERGROUPSDB_NOTIMPLEMENTED) || defined(USERGROUPSDBGETPROPERTY_NOTIMPLEMENTED)
	#define USE_UserGroupsDBGetProperty
	#define EXT_UserGroupsDBGetProperty
	#define GET_UserGroupsDBGetProperty(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserGroupsDBGetProperty(p0,p1,p2)  (RTS_UI32)ERR_NOTIMPLEMENTED
	#define CHK_UserGroupsDBGetProperty  FALSE
	#define EXP_UserGroupsDBGetProperty  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserGroupsDBGetProperty
	#define EXT_UserGroupsDBGetProperty
	#define GET_UserGroupsDBGetProperty(fl)  ERR_OK
	#define CAL_UserGroupsDBGetProperty(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetProperty(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBGetProperty  TRUE
	#define EXP_UserGroupsDBGetProperty  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSERGROUPSDB_EXTERNAL)
	#define USE_UserGroupsDBGetProperty
	#define EXT_UserGroupsDBGetProperty
	#define GET_UserGroupsDBGetProperty(fl)  ERR_OK
	#define CAL_UserGroupsDBGetProperty(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetProperty(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBGetProperty  TRUE
	#define EXP_UserGroupsDBGetProperty  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserGroupsDBUserGroupsDBGetProperty
	#define EXT_CmpUserGroupsDBUserGroupsDBGetProperty
	#define GET_CmpUserGroupsDBUserGroupsDBGetProperty  ERR_OK
	#define CAL_CmpUserGroupsDBUserGroupsDBGetProperty(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetProperty(p1,p2))
	#define CHK_CmpUserGroupsDBUserGroupsDBGetProperty  TRUE
	#define EXP_CmpUserGroupsDBUserGroupsDBGetProperty  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserGroupsDBGetProperty
	#define EXT_UserGroupsDBGetProperty
	#define GET_UserGroupsDBGetProperty(fl)  ERR_OK
	#define CAL_UserGroupsDBGetProperty(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetProperty(p1,p2))
	#define CHK_UserGroupsDBGetProperty  TRUE
	#define EXP_UserGroupsDBGetProperty  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserGroupsDBGetProperty
	#define EXT_UserGroupsDBGetProperty
	#define GET_UserGroupsDBGetProperty(fl)  ERR_OK
	#define CAL_UserGroupsDBGetProperty(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetProperty(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBGetProperty  TRUE
	#define EXP_UserGroupsDBGetProperty  ERR_OK
#endif




/**
 * <description>Check if the user is a member of the group
 * NOTE: The required user handle is not compatible with a handle from the UserMgr, and these handles must not be mixed.
 * A UserMgr handle can be converted to a UserDB handle by using UserMgrGetUserDBHandle().
 * </description>
 * <param name="hGroup" type="IN">Handle to the user group</param>
 * <param name="hUser" type="IN">Handle to the user</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">User is a member of the group</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid user or user group handle</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">User is no member of the specified user group</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserGroupsDBGroupHasUser(RTS_HANDLE hDatabase, RTS_HANDLE hGroup, char *pszUser);
typedef RTS_RESULT (CDECL * PFUSERGROUPSDBGROUPHASUSER) (RTS_HANDLE hDatabase, RTS_HANDLE hGroup, char *pszUser);
#if defined(CMPUSERGROUPSDB_NOTIMPLEMENTED) || defined(USERGROUPSDBGROUPHASUSER_NOTIMPLEMENTED)
	#define USE_UserGroupsDBGroupHasUser
	#define EXT_UserGroupsDBGroupHasUser
	#define GET_UserGroupsDBGroupHasUser(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserGroupsDBGroupHasUser(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserGroupsDBGroupHasUser  FALSE
	#define EXP_UserGroupsDBGroupHasUser  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserGroupsDBGroupHasUser
	#define EXT_UserGroupsDBGroupHasUser
	#define GET_UserGroupsDBGroupHasUser(fl)  ERR_OK
	#define CAL_UserGroupsDBGroupHasUser(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGroupHasUser(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBGroupHasUser  TRUE
	#define EXP_UserGroupsDBGroupHasUser  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSERGROUPSDB_EXTERNAL)
	#define USE_UserGroupsDBGroupHasUser
	#define EXT_UserGroupsDBGroupHasUser
	#define GET_UserGroupsDBGroupHasUser(fl)  ERR_OK
	#define CAL_UserGroupsDBGroupHasUser(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGroupHasUser(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBGroupHasUser  TRUE
	#define EXP_UserGroupsDBGroupHasUser  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserGroupsDBUserGroupsDBGroupHasUser
	#define EXT_CmpUserGroupsDBUserGroupsDBGroupHasUser
	#define GET_CmpUserGroupsDBUserGroupsDBGroupHasUser  ERR_OK
	#define CAL_CmpUserGroupsDBUserGroupsDBGroupHasUser(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGroupHasUser(p1,p2))
	#define CHK_CmpUserGroupsDBUserGroupsDBGroupHasUser  TRUE
	#define EXP_CmpUserGroupsDBUserGroupsDBGroupHasUser  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserGroupsDBGroupHasUser
	#define EXT_UserGroupsDBGroupHasUser
	#define GET_UserGroupsDBGroupHasUser(fl)  ERR_OK
	#define CAL_UserGroupsDBGroupHasUser(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGroupHasUser(p1,p2))
	#define CHK_UserGroupsDBGroupHasUser  TRUE
	#define EXP_UserGroupsDBGroupHasUser  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserGroupsDBGroupHasUser
	#define EXT_UserGroupsDBGroupHasUser
	#define GET_UserGroupsDBGroupHasUser(fl)  ERR_OK
	#define CAL_UserGroupsDBGroupHasUser(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGroupHasUser(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBGroupHasUser  TRUE
	#define EXP_UserGroupsDBGroupHasUser  ERR_OK
#endif




/**
 * <description>Check if a user group is a member of the first specified group</description>
 * <param name="hGroup" type="IN">Handle to the first user group</param>
 * <param name="hGroupMember" type="IN">Handle to the user group to check if it is a member of hGroup</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">User group is a member of the first group</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid user group handles</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_FAILED">User group is no member of the specified user group</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserGroupsDBGroupHasMember(RTS_HANDLE hDatabase, RTS_HANDLE hGroup, RTS_HANDLE hGroupMember);
typedef RTS_RESULT (CDECL * PFUSERGROUPSDBGROUPHASMEMBER) (RTS_HANDLE hDatabase, RTS_HANDLE hGroup, RTS_HANDLE hGroupMember);
#if defined(CMPUSERGROUPSDB_NOTIMPLEMENTED) || defined(USERGROUPSDBGROUPHASMEMBER_NOTIMPLEMENTED)
	#define USE_UserGroupsDBGroupHasMember
	#define EXT_UserGroupsDBGroupHasMember
	#define GET_UserGroupsDBGroupHasMember(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserGroupsDBGroupHasMember(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserGroupsDBGroupHasMember  FALSE
	#define EXP_UserGroupsDBGroupHasMember  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserGroupsDBGroupHasMember
	#define EXT_UserGroupsDBGroupHasMember
	#define GET_UserGroupsDBGroupHasMember(fl)  ERR_OK
	#define CAL_UserGroupsDBGroupHasMember(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGroupHasMember(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBGroupHasMember  TRUE
	#define EXP_UserGroupsDBGroupHasMember  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSERGROUPSDB_EXTERNAL)
	#define USE_UserGroupsDBGroupHasMember
	#define EXT_UserGroupsDBGroupHasMember
	#define GET_UserGroupsDBGroupHasMember(fl)  ERR_OK
	#define CAL_UserGroupsDBGroupHasMember(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGroupHasMember(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBGroupHasMember  TRUE
	#define EXP_UserGroupsDBGroupHasMember  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserGroupsDBUserGroupsDBGroupHasMember
	#define EXT_CmpUserGroupsDBUserGroupsDBGroupHasMember
	#define GET_CmpUserGroupsDBUserGroupsDBGroupHasMember  ERR_OK
	#define CAL_CmpUserGroupsDBUserGroupsDBGroupHasMember(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGroupHasMember(p1,p2))
	#define CHK_CmpUserGroupsDBUserGroupsDBGroupHasMember  TRUE
	#define EXP_CmpUserGroupsDBUserGroupsDBGroupHasMember  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserGroupsDBGroupHasMember
	#define EXT_UserGroupsDBGroupHasMember
	#define GET_UserGroupsDBGroupHasMember(fl)  ERR_OK
	#define CAL_UserGroupsDBGroupHasMember(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGroupHasMember(p1,p2))
	#define CHK_UserGroupsDBGroupHasMember  TRUE
	#define EXP_UserGroupsDBGroupHasMember  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserGroupsDBGroupHasMember
	#define EXT_UserGroupsDBGroupHasMember
	#define GET_UserGroupsDBGroupHasMember(fl)  ERR_OK
	#define CAL_UserGroupsDBGroupHasMember(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGroupHasMember(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBGroupHasMember  TRUE
	#define EXP_UserGroupsDBGroupHasMember  ERR_OK
#endif




/**
 * <description>Iteration interface to get the first user of the user group</description>
 * <param name="hGroup" type="IN">Handle to the user group</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">First user in the group available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">No user configured in the user group</errorcode>
 * <result>Handle to the first user in the user group or RTS_INVALID_HANDLE if failed</result>
 */
STATICITF_DEF char* CDECL UserGroupsDBGetFirstUser(RTS_HANDLE hDatabase, RTS_HANDLE hGroup, RTS_HANDLE *phIterator, RTS_RESULT *pResult);
typedef char* (CDECL * PFUSERGROUPSDBGETFIRSTUSER) (RTS_HANDLE hDatabase, RTS_HANDLE hGroup, RTS_HANDLE *phIterator, RTS_RESULT *pResult);
#if defined(CMPUSERGROUPSDB_NOTIMPLEMENTED) || defined(USERGROUPSDBGETFIRSTUSER_NOTIMPLEMENTED)
	#define USE_UserGroupsDBGetFirstUser
	#define EXT_UserGroupsDBGetFirstUser
	#define GET_UserGroupsDBGetFirstUser(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserGroupsDBGetFirstUser(p0,p1,p2,p3)  (char*)ERR_NOTIMPLEMENTED
	#define CHK_UserGroupsDBGetFirstUser  FALSE
	#define EXP_UserGroupsDBGetFirstUser  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserGroupsDBGetFirstUser
	#define EXT_UserGroupsDBGetFirstUser
	#define GET_UserGroupsDBGetFirstUser(fl)  ERR_OK
	#define CAL_UserGroupsDBGetFirstUser(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetFirstUser(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserGroupsDBGetFirstUser  TRUE
	#define EXP_UserGroupsDBGetFirstUser  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSERGROUPSDB_EXTERNAL)
	#define USE_UserGroupsDBGetFirstUser
	#define EXT_UserGroupsDBGetFirstUser
	#define GET_UserGroupsDBGetFirstUser(fl)  ERR_OK
	#define CAL_UserGroupsDBGetFirstUser(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetFirstUser(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserGroupsDBGetFirstUser  TRUE
	#define EXP_UserGroupsDBGetFirstUser  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserGroupsDBUserGroupsDBGetFirstUser
	#define EXT_CmpUserGroupsDBUserGroupsDBGetFirstUser
	#define GET_CmpUserGroupsDBUserGroupsDBGetFirstUser  ERR_OK
	#define CAL_CmpUserGroupsDBUserGroupsDBGetFirstUser(p0,p1,p2,p3)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetFirstUser(p1,p2,p3))
	#define CHK_CmpUserGroupsDBUserGroupsDBGetFirstUser  TRUE
	#define EXP_CmpUserGroupsDBUserGroupsDBGetFirstUser  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserGroupsDBGetFirstUser
	#define EXT_UserGroupsDBGetFirstUser
	#define GET_UserGroupsDBGetFirstUser(fl)  ERR_OK
	#define CAL_UserGroupsDBGetFirstUser(p0,p1,p2,p3)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetFirstUser(p1,p2,p3))
	#define CHK_UserGroupsDBGetFirstUser  TRUE
	#define EXP_UserGroupsDBGetFirstUser  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserGroupsDBGetFirstUser
	#define EXT_UserGroupsDBGetFirstUser
	#define GET_UserGroupsDBGetFirstUser(fl)  ERR_OK
	#define CAL_UserGroupsDBGetFirstUser(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetFirstUser(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserGroupsDBGetFirstUser  TRUE
	#define EXP_UserGroupsDBGetFirstUser  ERR_OK
#endif




/**
 * <description>Iteration interface to get next configured user of the user group. Must be started with UserDBGroupGetFirstUser()</description>
 * <param name="hGroup" type="IN">Handle to the user group</param>
 * <param name="hPrevUser" type="IN">Handle to the previous user retrieved via UserDBGroupGetFirstUser() or subsequent calls of UserDBGroupGetNextUser()</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Next user available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid handles</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">No next user available</errorcode>
 * <result>Handle to the next user or RTS_INVALID_HANDLE if failed</result>
 */
STATICITF_DEF char* CDECL UserGroupsDBGetNextUser(RTS_HANDLE hDatabase, RTS_HANDLE hGroup, RTS_HANDLE *phIterator, RTS_RESULT *pResult);
typedef char* (CDECL * PFUSERGROUPSDBGETNEXTUSER) (RTS_HANDLE hDatabase, RTS_HANDLE hGroup, RTS_HANDLE *phIterator, RTS_RESULT *pResult);
#if defined(CMPUSERGROUPSDB_NOTIMPLEMENTED) || defined(USERGROUPSDBGETNEXTUSER_NOTIMPLEMENTED)
	#define USE_UserGroupsDBGetNextUser
	#define EXT_UserGroupsDBGetNextUser
	#define GET_UserGroupsDBGetNextUser(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserGroupsDBGetNextUser(p0,p1,p2,p3)  (char*)ERR_NOTIMPLEMENTED
	#define CHK_UserGroupsDBGetNextUser  FALSE
	#define EXP_UserGroupsDBGetNextUser  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserGroupsDBGetNextUser
	#define EXT_UserGroupsDBGetNextUser
	#define GET_UserGroupsDBGetNextUser(fl)  ERR_OK
	#define CAL_UserGroupsDBGetNextUser(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetNextUser(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserGroupsDBGetNextUser  TRUE
	#define EXP_UserGroupsDBGetNextUser  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSERGROUPSDB_EXTERNAL)
	#define USE_UserGroupsDBGetNextUser
	#define EXT_UserGroupsDBGetNextUser
	#define GET_UserGroupsDBGetNextUser(fl)  ERR_OK
	#define CAL_UserGroupsDBGetNextUser(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetNextUser(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserGroupsDBGetNextUser  TRUE
	#define EXP_UserGroupsDBGetNextUser  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserGroupsDBUserGroupsDBGetNextUser
	#define EXT_CmpUserGroupsDBUserGroupsDBGetNextUser
	#define GET_CmpUserGroupsDBUserGroupsDBGetNextUser  ERR_OK
	#define CAL_CmpUserGroupsDBUserGroupsDBGetNextUser(p0,p1,p2,p3)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetNextUser(p1,p2,p3))
	#define CHK_CmpUserGroupsDBUserGroupsDBGetNextUser  TRUE
	#define EXP_CmpUserGroupsDBUserGroupsDBGetNextUser  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserGroupsDBGetNextUser
	#define EXT_UserGroupsDBGetNextUser
	#define GET_UserGroupsDBGetNextUser(fl)  ERR_OK
	#define CAL_UserGroupsDBGetNextUser(p0,p1,p2,p3)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetNextUser(p1,p2,p3))
	#define CHK_UserGroupsDBGetNextUser  TRUE
	#define EXP_UserGroupsDBGetNextUser  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserGroupsDBGetNextUser
	#define EXT_UserGroupsDBGetNextUser
	#define GET_UserGroupsDBGetNextUser(fl)  ERR_OK
	#define CAL_UserGroupsDBGetNextUser(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? 0 : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetNextUser(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserGroupsDBGetNextUser  TRUE
	#define EXP_UserGroupsDBGetNextUser  ERR_OK
#endif




/**
 * <description>Iteration interface to get the first user group as member of the specified group</description>
 * <param name="hGroup" type="IN">Handle to the user group</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">First user group member available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid user group handle</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">No user group configured</errorcode>
 * <result>Handle to the first user group member or RTS_INVALID_HANDLE if failed</result>
 */
STATICITF_DEF RTS_HANDLE CDECL UserGroupsDBGetFirstGroupMember(RTS_HANDLE hDatabase, RTS_HANDLE hGroup, RTS_RESULT *pResult);
typedef RTS_HANDLE (CDECL * PFUSERGROUPSDBGETFIRSTGROUPMEMBER) (RTS_HANDLE hDatabase, RTS_HANDLE hGroup, RTS_RESULT *pResult);
#if defined(CMPUSERGROUPSDB_NOTIMPLEMENTED) || defined(USERGROUPSDBGETFIRSTGROUPMEMBER_NOTIMPLEMENTED)
	#define USE_UserGroupsDBGetFirstGroupMember
	#define EXT_UserGroupsDBGetFirstGroupMember
	#define GET_UserGroupsDBGetFirstGroupMember(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserGroupsDBGetFirstGroupMember(p0,p1,p2)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_UserGroupsDBGetFirstGroupMember  FALSE
	#define EXP_UserGroupsDBGetFirstGroupMember  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserGroupsDBGetFirstGroupMember
	#define EXT_UserGroupsDBGetFirstGroupMember
	#define GET_UserGroupsDBGetFirstGroupMember(fl)  ERR_OK
	#define CAL_UserGroupsDBGetFirstGroupMember(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetFirstGroupMember(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBGetFirstGroupMember  TRUE
	#define EXP_UserGroupsDBGetFirstGroupMember  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSERGROUPSDB_EXTERNAL)
	#define USE_UserGroupsDBGetFirstGroupMember
	#define EXT_UserGroupsDBGetFirstGroupMember
	#define GET_UserGroupsDBGetFirstGroupMember(fl)  ERR_OK
	#define CAL_UserGroupsDBGetFirstGroupMember(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetFirstGroupMember(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBGetFirstGroupMember  TRUE
	#define EXP_UserGroupsDBGetFirstGroupMember  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserGroupsDBUserGroupsDBGetFirstGroupMember
	#define EXT_CmpUserGroupsDBUserGroupsDBGetFirstGroupMember
	#define GET_CmpUserGroupsDBUserGroupsDBGetFirstGroupMember  ERR_OK
	#define CAL_CmpUserGroupsDBUserGroupsDBGetFirstGroupMember(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetFirstGroupMember(p1,p2))
	#define CHK_CmpUserGroupsDBUserGroupsDBGetFirstGroupMember  TRUE
	#define EXP_CmpUserGroupsDBUserGroupsDBGetFirstGroupMember  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserGroupsDBGetFirstGroupMember
	#define EXT_UserGroupsDBGetFirstGroupMember
	#define GET_UserGroupsDBGetFirstGroupMember(fl)  ERR_OK
	#define CAL_UserGroupsDBGetFirstGroupMember(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetFirstGroupMember(p1,p2))
	#define CHK_UserGroupsDBGetFirstGroupMember  TRUE
	#define EXP_UserGroupsDBGetFirstGroupMember  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserGroupsDBGetFirstGroupMember
	#define EXT_UserGroupsDBGetFirstGroupMember
	#define GET_UserGroupsDBGetFirstGroupMember(fl)  ERR_OK
	#define CAL_UserGroupsDBGetFirstGroupMember(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetFirstGroupMember(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserGroupsDBGetFirstGroupMember  TRUE
	#define EXP_UserGroupsDBGetFirstGroupMember  ERR_OK
#endif




/**
 * <description>Iteration interface to get next configured user group as member of the specified group. Must be started with UserDBGroupGetFirstMember()</description>
 * <param name="hGroup" type="IN">Handle to the user group</param>
 * <param name="hPrevGroupMember" type="IN">Handle to the previous user group retrieved via UserDBGroupGetFirstMember() or subsequent calls of UserDBGroupGetNextMember()</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Next user group member available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">No next user group member available</errorcode>
 * <result>Handle to the next user group member or RTS_INVALID_HANDLE if failed</result>
 */
STATICITF_DEF RTS_HANDLE CDECL UserGroupsDBGetNextGroupMember(RTS_HANDLE hDatabase, RTS_HANDLE hGroup, RTS_HANDLE hPrevMember, RTS_RESULT *pResult);
typedef RTS_HANDLE (CDECL * PFUSERGROUPSDBGETNEXTGROUPMEMBER) (RTS_HANDLE hDatabase, RTS_HANDLE hGroup, RTS_HANDLE hPrevMember, RTS_RESULT *pResult);
#if defined(CMPUSERGROUPSDB_NOTIMPLEMENTED) || defined(USERGROUPSDBGETNEXTGROUPMEMBER_NOTIMPLEMENTED)
	#define USE_UserGroupsDBGetNextGroupMember
	#define EXT_UserGroupsDBGetNextGroupMember
	#define GET_UserGroupsDBGetNextGroupMember(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserGroupsDBGetNextGroupMember(p0,p1,p2,p3)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_UserGroupsDBGetNextGroupMember  FALSE
	#define EXP_UserGroupsDBGetNextGroupMember  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserGroupsDBGetNextGroupMember
	#define EXT_UserGroupsDBGetNextGroupMember
	#define GET_UserGroupsDBGetNextGroupMember(fl)  ERR_OK
	#define CAL_UserGroupsDBGetNextGroupMember(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetNextGroupMember(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserGroupsDBGetNextGroupMember  TRUE
	#define EXP_UserGroupsDBGetNextGroupMember  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSERGROUPSDB_EXTERNAL)
	#define USE_UserGroupsDBGetNextGroupMember
	#define EXT_UserGroupsDBGetNextGroupMember
	#define GET_UserGroupsDBGetNextGroupMember(fl)  ERR_OK
	#define CAL_UserGroupsDBGetNextGroupMember(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetNextGroupMember(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserGroupsDBGetNextGroupMember  TRUE
	#define EXP_UserGroupsDBGetNextGroupMember  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserGroupsDBUserGroupsDBGetNextGroupMember
	#define EXT_CmpUserGroupsDBUserGroupsDBGetNextGroupMember
	#define GET_CmpUserGroupsDBUserGroupsDBGetNextGroupMember  ERR_OK
	#define CAL_CmpUserGroupsDBUserGroupsDBGetNextGroupMember(p0,p1,p2,p3)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetNextGroupMember(p1,p2,p3))
	#define CHK_CmpUserGroupsDBUserGroupsDBGetNextGroupMember  TRUE
	#define EXP_CmpUserGroupsDBUserGroupsDBGetNextGroupMember  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserGroupsDBGetNextGroupMember
	#define EXT_UserGroupsDBGetNextGroupMember
	#define GET_UserGroupsDBGetNextGroupMember(fl)  ERR_OK
	#define CAL_UserGroupsDBGetNextGroupMember(p0,p1,p2,p3)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetNextGroupMember(p1,p2,p3))
	#define CHK_UserGroupsDBGetNextGroupMember  TRUE
	#define EXP_UserGroupsDBGetNextGroupMember  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserGroupsDBGetNextGroupMember
	#define EXT_UserGroupsDBGetNextGroupMember
	#define GET_UserGroupsDBGetNextGroupMember(fl)  ERR_OK
	#define CAL_UserGroupsDBGetNextGroupMember(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserGroupsDB*)p0)->IUserGroupsDBGetNextGroupMember(((ICmpUserGroupsDB*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserGroupsDBGetNextGroupMember  TRUE
	#define EXP_UserGroupsDBGetNextGroupMember  ERR_OK
#endif





typedef struct
{
	IBase_C *pBase;
	PFUSERGROUPSDBGETGROUP IUserGroupsDBGetGroup;
 	PFUSERGROUPSDBGETFIRSTGROUP IUserGroupsDBGetFirstGroup;
 	PFUSERGROUPSDBGETNEXTGROUP IUserGroupsDBGetNextGroup;
 	PFUSERGROUPSDBGETNAME IUserGroupsDBGetName;
 	PFUSERGROUPSDBGETPROPERTY IUserGroupsDBGetProperty;
 	PFUSERGROUPSDBGROUPHASUSER IUserGroupsDBGroupHasUser;
 	PFUSERGROUPSDBGROUPHASMEMBER IUserGroupsDBGroupHasMember;
 	PFUSERGROUPSDBGETFIRSTUSER IUserGroupsDBGetFirstUser;
 	PFUSERGROUPSDBGETNEXTUSER IUserGroupsDBGetNextUser;
 	PFUSERGROUPSDBGETFIRSTGROUPMEMBER IUserGroupsDBGetFirstGroupMember;
 	PFUSERGROUPSDBGETNEXTGROUPMEMBER IUserGroupsDBGetNextGroupMember;
 } ICmpUserGroupsDB_C;

#ifdef CPLUSPLUS
class ICmpUserGroupsDB : public IBase
{
	public:
		virtual RTS_HANDLE CDECL IUserGroupsDBGetGroup(char *pszGroupName, RTS_RESULT *pResult) =0;
		virtual RTS_HANDLE CDECL IUserGroupsDBGetFirstGroup(RTS_RESULT *pResult) =0;
		virtual RTS_HANDLE CDECL IUserGroupsDBGetNextGroup(RTS_HANDLE hPrevGroup, RTS_RESULT *pResult) =0;
		virtual char* CDECL IUserGroupsDBGetName(RTS_HANDLE hGroup, RTS_RESULT *pResult) =0;
		virtual RTS_UI32 CDECL IUserGroupsDBGetProperty(RTS_HANDLE hGroup, RTS_RESULT *pResult) =0;
		virtual RTS_RESULT CDECL IUserGroupsDBGroupHasUser(RTS_HANDLE hGroup, char *pszUser) =0;
		virtual RTS_RESULT CDECL IUserGroupsDBGroupHasMember(RTS_HANDLE hGroup, RTS_HANDLE hGroupMember) =0;
		virtual char* CDECL IUserGroupsDBGetFirstUser(RTS_HANDLE hGroup, RTS_HANDLE *phIterator, RTS_RESULT *pResult) =0;
		virtual char* CDECL IUserGroupsDBGetNextUser(RTS_HANDLE hGroup, RTS_HANDLE *phIterator, RTS_RESULT *pResult) =0;
		virtual RTS_HANDLE CDECL IUserGroupsDBGetFirstGroupMember(RTS_HANDLE hGroup, RTS_RESULT *pResult) =0;
		virtual RTS_HANDLE CDECL IUserGroupsDBGetNextGroupMember(RTS_HANDLE hGroup, RTS_HANDLE hPrevMember, RTS_RESULT *pResult) =0;
};
	#ifndef ITF_CmpUserGroupsDB
		#define ITF_CmpUserGroupsDB static ICmpUserGroupsDB *pICmpUserGroupsDB = NULL;
	#endif
	#define EXTITF_CmpUserGroupsDB
#else	/*CPLUSPLUS*/
	typedef ICmpUserGroupsDB_C		ICmpUserGroupsDB;
	#ifndef ITF_CmpUserGroupsDB
		#define ITF_CmpUserGroupsDB
	#endif
	#define EXTITF_CmpUserGroupsDB
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_CMPUSERGROUPSDBITF_H_*/
