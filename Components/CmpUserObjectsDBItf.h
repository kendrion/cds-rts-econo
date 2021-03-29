 /**
 * <interfacename>CmpUserObjectsDB</interfacename>
 * <description> 
 *	Interface for the user rights management database.
 *
 *	   Here you have to store the tree of all objects of the runtime system with their assigned user-groups and the configured rights on it.
 *
 *	   Example:
 *			- Object: Name = "Device"; UserGroup = "Administrator" | Rights = USERDB_RIGHT_ALL | DeniedRights = USERDB_RIGHT_NONE; 
 *									   UserGroup = "..." | Rights = ... | DeniedRights = ...;
 *									   ...
 *			- Object: Name = "Device.MyObject"; UserGroup = "Administrator" | Rights = USERDB_RIGHT_ALL | DeniedRights = USERDB_RIGHT_NONE; 
 *												UserGroup = "..." | Rights = ... | DeniedRights = ...;
 *												...
 *
 *	For details see CmpUserMgrItf.h.
 *
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved. GmbH
 * </copyright>
 */


	
	
#ifndef _CMPUSEROBJECTSDBITF_H_
#define _CMPUSEROBJECTSDBITF_H_

#include "CmpStd.h"

 

 



#include "CmpMemPoolItf.h"
#include "CmpItf.h"

/**
 * <category>Static defines</category>
 * <description>Number of objects at startup</description>
 */
#ifndef USERDB_NUM_OF_STATIC_OBJECTS
	#define USERDB_NUM_OF_STATIC_OBJECTS		6
#endif

/**
 * <category>Static defines</category>
 * <description>Number of user-group specific rights at startup</description>
 */
#ifndef USERDB_NUM_OF_STATIC_GROUPRIGHTS
	#define USERDB_NUM_OF_STATIC_GROUPRIGHTS	10
#endif

/**
 * <category>Properties</category>
 * <description>These defines are used as properties of the UserDB Objects. Use as bit-mask.</description>
 * <element name="USERDB_HIDE_OBJECT">Hides the object from being uploaded to the IDE.</element>
 * <element name="USERDB_EXPLICIT_RIGHTS">Evaluates only the explicit configured rights on that object. Don't check the parent 
 *	objects if no rights are configured. If no explicit rights are found access is denied.</element>
 */
#define USERDB_HIDE_OBJECT             1
#define USERDB_EXPLICIT_RIGHTS         2

#ifdef __cplusplus
extern "C" {
#endif

/* --------- Objects and Rights management --------------------- */

/**
 * <description>
 *	Get the used access rights for the object specified by handle.
 *	NOTE: In case the used rights are not set the function returns USERDB_RIGHT_ALL.
 * </description>
 * <param name="hObject" type="IN">Handle to the object</param>
 * <param name="pulUsedRights" type="OUT">Pointer to used access rights</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Rights are successfully set</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid object handle or invalid pointer</errorcode>
 * <result>Error code</result>
 */
STATICITF_DEF RTS_RESULT CDECL UserObjectsDBGetUsedRights(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_UI32 *pulUsedRights);
typedef RTS_RESULT (CDECL * PFUSEROBJECTSDBGETUSEDRIGHTS) (RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_UI32 *pulUsedRights);
#if defined(CMPUSEROBJECTSDB_NOTIMPLEMENTED) || defined(USEROBJECTSDBGETUSEDRIGHTS_NOTIMPLEMENTED)
	#define USE_UserObjectsDBGetUsedRights
	#define EXT_UserObjectsDBGetUsedRights
	#define GET_UserObjectsDBGetUsedRights(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBGetUsedRights(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserObjectsDBGetUsedRights  FALSE
	#define EXP_UserObjectsDBGetUsedRights  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBGetUsedRights
	#define EXT_UserObjectsDBGetUsedRights
	#define GET_UserObjectsDBGetUsedRights(fl)  ERR_OK
	#define CAL_UserObjectsDBGetUsedRights(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetUsedRights(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBGetUsedRights  TRUE
	#define EXP_UserObjectsDBGetUsedRights  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDB_EXTERNAL)
	#define USE_UserObjectsDBGetUsedRights
	#define EXT_UserObjectsDBGetUsedRights
	#define GET_UserObjectsDBGetUsedRights(fl)  ERR_OK
	#define CAL_UserObjectsDBGetUsedRights(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetUsedRights(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBGetUsedRights  TRUE
	#define EXP_UserObjectsDBGetUsedRights  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBUserObjectsDBGetUsedRights
	#define EXT_CmpUserObjectsDBUserObjectsDBGetUsedRights
	#define GET_CmpUserObjectsDBUserObjectsDBGetUsedRights  ERR_OK
	#define CAL_CmpUserObjectsDBUserObjectsDBGetUsedRights(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetUsedRights(p1,p2))
	#define CHK_CmpUserObjectsDBUserObjectsDBGetUsedRights  TRUE
	#define EXP_CmpUserObjectsDBUserObjectsDBGetUsedRights  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBGetUsedRights
	#define EXT_UserObjectsDBGetUsedRights
	#define GET_UserObjectsDBGetUsedRights(fl)  ERR_OK
	#define CAL_UserObjectsDBGetUsedRights(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetUsedRights(p1,p2))
	#define CHK_UserObjectsDBGetUsedRights  TRUE
	#define EXP_UserObjectsDBGetUsedRights  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBGetUsedRights
	#define EXT_UserObjectsDBGetUsedRights
	#define GET_UserObjectsDBGetUsedRights(fl)  ERR_OK
	#define CAL_UserObjectsDBGetUsedRights(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetUsedRights(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBGetUsedRights  TRUE
	#define EXP_UserObjectsDBGetUsedRights  ERR_OK
#endif




/**
 * <description>Get the properties for the object specified by handle.</description>
 * <param name="hObject" type="IN">Handle to the object</param>
 * <param name="pulProperties" type="OUT">Pointer to properties</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Rights are successfully set</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid object handle or invalid pointer</errorcode>
 * <result>Error code</result>
 */
STATICITF_DEF RTS_RESULT CDECL UserObjectsDBGetProperties(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_UI32 *pulProperties);
typedef RTS_RESULT (CDECL * PFUSEROBJECTSDBGETPROPERTIES) (RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_UI32 *pulProperties);
#if defined(CMPUSEROBJECTSDB_NOTIMPLEMENTED) || defined(USEROBJECTSDBGETPROPERTIES_NOTIMPLEMENTED)
	#define USE_UserObjectsDBGetProperties
	#define EXT_UserObjectsDBGetProperties
	#define GET_UserObjectsDBGetProperties(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBGetProperties(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserObjectsDBGetProperties  FALSE
	#define EXP_UserObjectsDBGetProperties  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBGetProperties
	#define EXT_UserObjectsDBGetProperties
	#define GET_UserObjectsDBGetProperties(fl)  ERR_OK
	#define CAL_UserObjectsDBGetProperties(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetProperties(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBGetProperties  TRUE
	#define EXP_UserObjectsDBGetProperties  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDB_EXTERNAL)
	#define USE_UserObjectsDBGetProperties
	#define EXT_UserObjectsDBGetProperties
	#define GET_UserObjectsDBGetProperties(fl)  ERR_OK
	#define CAL_UserObjectsDBGetProperties(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetProperties(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBGetProperties  TRUE
	#define EXP_UserObjectsDBGetProperties  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBUserObjectsDBGetProperties
	#define EXT_CmpUserObjectsDBUserObjectsDBGetProperties
	#define GET_CmpUserObjectsDBUserObjectsDBGetProperties  ERR_OK
	#define CAL_CmpUserObjectsDBUserObjectsDBGetProperties(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetProperties(p1,p2))
	#define CHK_CmpUserObjectsDBUserObjectsDBGetProperties  TRUE
	#define EXP_CmpUserObjectsDBUserObjectsDBGetProperties  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBGetProperties
	#define EXT_UserObjectsDBGetProperties
	#define GET_UserObjectsDBGetProperties(fl)  ERR_OK
	#define CAL_UserObjectsDBGetProperties(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetProperties(p1,p2))
	#define CHK_UserObjectsDBGetProperties  TRUE
	#define EXP_UserObjectsDBGetProperties  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBGetProperties
	#define EXT_UserObjectsDBGetProperties
	#define GET_UserObjectsDBGetProperties(fl)  ERR_OK
	#define CAL_UserObjectsDBGetProperties(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetProperties(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBGetProperties  TRUE
	#define EXP_UserObjectsDBGetProperties  ERR_OK
#endif




/**
 * <description>Get a unique identifier of an object</description>
 * <param name="hObject" type="IN">Handle to object</param>
 * <param name="pulID" type="OUT">Pointer to get the ObjectID</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">ObjectID could be retrieved</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid object handle</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserObjectsDBGetID(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_UI32 *pulID);
typedef RTS_RESULT (CDECL * PFUSEROBJECTSDBGETID) (RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_UI32 *pulID);
#if defined(CMPUSEROBJECTSDB_NOTIMPLEMENTED) || defined(USEROBJECTSDBGETID_NOTIMPLEMENTED)
	#define USE_UserObjectsDBGetID
	#define EXT_UserObjectsDBGetID
	#define GET_UserObjectsDBGetID(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBGetID(p0,p1,p2)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserObjectsDBGetID  FALSE
	#define EXP_UserObjectsDBGetID  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBGetID
	#define EXT_UserObjectsDBGetID
	#define GET_UserObjectsDBGetID(fl)  ERR_OK
	#define CAL_UserObjectsDBGetID(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetID(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBGetID  TRUE
	#define EXP_UserObjectsDBGetID  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDB_EXTERNAL)
	#define USE_UserObjectsDBGetID
	#define EXT_UserObjectsDBGetID
	#define GET_UserObjectsDBGetID(fl)  ERR_OK
	#define CAL_UserObjectsDBGetID(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetID(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBGetID  TRUE
	#define EXP_UserObjectsDBGetID  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBUserObjectsDBGetID
	#define EXT_CmpUserObjectsDBUserObjectsDBGetID
	#define GET_CmpUserObjectsDBUserObjectsDBGetID  ERR_OK
	#define CAL_CmpUserObjectsDBUserObjectsDBGetID(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetID(p1,p2))
	#define CHK_CmpUserObjectsDBUserObjectsDBGetID  TRUE
	#define EXP_CmpUserObjectsDBUserObjectsDBGetID  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBGetID
	#define EXT_UserObjectsDBGetID
	#define GET_UserObjectsDBGetID(fl)  ERR_OK
	#define CAL_UserObjectsDBGetID(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetID(p1,p2))
	#define CHK_UserObjectsDBGetID  TRUE
	#define EXP_UserObjectsDBGetID  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBGetID
	#define EXT_UserObjectsDBGetID
	#define GET_UserObjectsDBGetID(fl)  ERR_OK
	#define CAL_UserObjectsDBGetID(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetID(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBGetID  TRUE
	#define EXP_UserObjectsDBGetID  ERR_OK
#endif




/* Object iteration */

/**
 * <description>Iteration interface to get the first object of the user rights management</description>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">First object of the user rights management available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">No object available</errorcode>
 * <result>Handle to the first object in the user rights management or RTS_INVALID_HANDLE if failed</result>
 */
STATICITF_DEF RTS_HANDLE CDECL UserObjectsDBGetFirst(RTS_HANDLE hDatabase, RTS_RESULT *pResult);
typedef RTS_HANDLE (CDECL * PFUSEROBJECTSDBGETFIRST) (RTS_HANDLE hDatabase, RTS_RESULT *pResult);
#if defined(CMPUSEROBJECTSDB_NOTIMPLEMENTED) || defined(USEROBJECTSDBGETFIRST_NOTIMPLEMENTED)
	#define USE_UserObjectsDBGetFirst
	#define EXT_UserObjectsDBGetFirst
	#define GET_UserObjectsDBGetFirst(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBGetFirst(p0,p1)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_UserObjectsDBGetFirst  FALSE
	#define EXP_UserObjectsDBGetFirst  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBGetFirst
	#define EXT_UserObjectsDBGetFirst
	#define GET_UserObjectsDBGetFirst(fl)  ERR_OK
	#define CAL_UserObjectsDBGetFirst(p0,p1) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetFirst(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1))
	#define CHK_UserObjectsDBGetFirst  TRUE
	#define EXP_UserObjectsDBGetFirst  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDB_EXTERNAL)
	#define USE_UserObjectsDBGetFirst
	#define EXT_UserObjectsDBGetFirst
	#define GET_UserObjectsDBGetFirst(fl)  ERR_OK
	#define CAL_UserObjectsDBGetFirst(p0,p1) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetFirst(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1))
	#define CHK_UserObjectsDBGetFirst  TRUE
	#define EXP_UserObjectsDBGetFirst  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBUserObjectsDBGetFirst
	#define EXT_CmpUserObjectsDBUserObjectsDBGetFirst
	#define GET_CmpUserObjectsDBUserObjectsDBGetFirst  ERR_OK
	#define CAL_CmpUserObjectsDBUserObjectsDBGetFirst(p0,p1)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetFirst(p1))
	#define CHK_CmpUserObjectsDBUserObjectsDBGetFirst  TRUE
	#define EXP_CmpUserObjectsDBUserObjectsDBGetFirst  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBGetFirst
	#define EXT_UserObjectsDBGetFirst
	#define GET_UserObjectsDBGetFirst(fl)  ERR_OK
	#define CAL_UserObjectsDBGetFirst(p0,p1)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetFirst(p1))
	#define CHK_UserObjectsDBGetFirst  TRUE
	#define EXP_UserObjectsDBGetFirst  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBGetFirst
	#define EXT_UserObjectsDBGetFirst
	#define GET_UserObjectsDBGetFirst(fl)  ERR_OK
	#define CAL_UserObjectsDBGetFirst(p0,p1) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetFirst(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1))
	#define CHK_UserObjectsDBGetFirst  TRUE
	#define EXP_UserObjectsDBGetFirst  ERR_OK
#endif




/**
 * <description>Iteration interface to get next object of the user rights management. Must be started with UserObjectsDBGetFirst()</description>
 * <param name="hPrevObject" type="IN">Handle to the previous object retrieved via UserObjectsDBGetFirst() or subsequent calls of UserObjectsDBGetNext()</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Next object available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid handles</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">No next object available</errorcode>
 * <result>Handle to the next object in the user rights management or RTS_INVALID_HANDLE if failed</result>
 */
STATICITF_DEF RTS_HANDLE CDECL UserObjectsDBGetNext(RTS_HANDLE hDatabase, RTS_HANDLE hPrevObject, RTS_RESULT *pResult);
typedef RTS_HANDLE (CDECL * PFUSEROBJECTSDBGETNEXT) (RTS_HANDLE hDatabase, RTS_HANDLE hPrevObject, RTS_RESULT *pResult);
#if defined(CMPUSEROBJECTSDB_NOTIMPLEMENTED) || defined(USEROBJECTSDBGETNEXT_NOTIMPLEMENTED)
	#define USE_UserObjectsDBGetNext
	#define EXT_UserObjectsDBGetNext
	#define GET_UserObjectsDBGetNext(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBGetNext(p0,p1,p2)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_UserObjectsDBGetNext  FALSE
	#define EXP_UserObjectsDBGetNext  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBGetNext
	#define EXT_UserObjectsDBGetNext
	#define GET_UserObjectsDBGetNext(fl)  ERR_OK
	#define CAL_UserObjectsDBGetNext(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetNext(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBGetNext  TRUE
	#define EXP_UserObjectsDBGetNext  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDB_EXTERNAL)
	#define USE_UserObjectsDBGetNext
	#define EXT_UserObjectsDBGetNext
	#define GET_UserObjectsDBGetNext(fl)  ERR_OK
	#define CAL_UserObjectsDBGetNext(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetNext(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBGetNext  TRUE
	#define EXP_UserObjectsDBGetNext  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBUserObjectsDBGetNext
	#define EXT_CmpUserObjectsDBUserObjectsDBGetNext
	#define GET_CmpUserObjectsDBUserObjectsDBGetNext  ERR_OK
	#define CAL_CmpUserObjectsDBUserObjectsDBGetNext(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetNext(p1,p2))
	#define CHK_CmpUserObjectsDBUserObjectsDBGetNext  TRUE
	#define EXP_CmpUserObjectsDBUserObjectsDBGetNext  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBGetNext
	#define EXT_UserObjectsDBGetNext
	#define GET_UserObjectsDBGetNext(fl)  ERR_OK
	#define CAL_UserObjectsDBGetNext(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetNext(p1,p2))
	#define CHK_UserObjectsDBGetNext  TRUE
	#define EXP_UserObjectsDBGetNext  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBGetNext
	#define EXT_UserObjectsDBGetNext
	#define GET_UserObjectsDBGetNext(fl)  ERR_OK
	#define CAL_UserObjectsDBGetNext(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetNext(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBGetNext  TRUE
	#define EXP_UserObjectsDBGetNext  ERR_OK
#endif




/* Single object access */

/**
 * <description>Open object specified by its name</description>
 * <param name="pszObject" type="IN">Full object name (see object tree)</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Object could be opened</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter. pszObject = NULL or empty</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">The user management is not initialized or it is not loaded yet</errorcode>
 * <result>Handle to the object or RTS_INVALID_HANDLE if failed</result>
 */
STATICITF_DEF RTS_HANDLE CDECL UserObjectsDBOpen(RTS_HANDLE hDatabase, char *pszObject, RTS_RESULT *pResult);
typedef RTS_HANDLE (CDECL * PFUSEROBJECTSDBOPEN) (RTS_HANDLE hDatabase, char *pszObject, RTS_RESULT *pResult);
#if defined(CMPUSEROBJECTSDB_NOTIMPLEMENTED) || defined(USEROBJECTSDBOPEN_NOTIMPLEMENTED)
	#define USE_UserObjectsDBOpen
	#define EXT_UserObjectsDBOpen
	#define GET_UserObjectsDBOpen(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBOpen(p0,p1,p2)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_UserObjectsDBOpen  FALSE
	#define EXP_UserObjectsDBOpen  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBOpen
	#define EXT_UserObjectsDBOpen
	#define GET_UserObjectsDBOpen(fl)  ERR_OK
	#define CAL_UserObjectsDBOpen(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBOpen(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBOpen  TRUE
	#define EXP_UserObjectsDBOpen  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDB_EXTERNAL)
	#define USE_UserObjectsDBOpen
	#define EXT_UserObjectsDBOpen
	#define GET_UserObjectsDBOpen(fl)  ERR_OK
	#define CAL_UserObjectsDBOpen(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBOpen(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBOpen  TRUE
	#define EXP_UserObjectsDBOpen  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBUserObjectsDBOpen
	#define EXT_CmpUserObjectsDBUserObjectsDBOpen
	#define GET_CmpUserObjectsDBUserObjectsDBOpen  ERR_OK
	#define CAL_CmpUserObjectsDBUserObjectsDBOpen(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBOpen(p1,p2))
	#define CHK_CmpUserObjectsDBUserObjectsDBOpen  TRUE
	#define EXP_CmpUserObjectsDBUserObjectsDBOpen  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBOpen
	#define EXT_UserObjectsDBOpen
	#define GET_UserObjectsDBOpen(fl)  ERR_OK
	#define CAL_UserObjectsDBOpen(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBOpen(p1,p2))
	#define CHK_UserObjectsDBOpen  TRUE
	#define EXP_UserObjectsDBOpen  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBOpen
	#define EXT_UserObjectsDBOpen
	#define GET_UserObjectsDBOpen(fl)  ERR_OK
	#define CAL_UserObjectsDBOpen(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBOpen(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBOpen  TRUE
	#define EXP_UserObjectsDBOpen  ERR_OK
#endif




/**
 * <description>Close an object</description>
 * <param name="hObject" type="IN">Handle to the object</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Object could be closed</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid object handle</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserObjectsDBClose(RTS_HANDLE hDatabase, RTS_HANDLE hObject);
typedef RTS_RESULT (CDECL * PFUSEROBJECTSDBCLOSE) (RTS_HANDLE hDatabase, RTS_HANDLE hObject);
#if defined(CMPUSEROBJECTSDB_NOTIMPLEMENTED) || defined(USEROBJECTSDBCLOSE_NOTIMPLEMENTED)
	#define USE_UserObjectsDBClose
	#define EXT_UserObjectsDBClose
	#define GET_UserObjectsDBClose(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBClose(p0,p1)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserObjectsDBClose  FALSE
	#define EXP_UserObjectsDBClose  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBClose
	#define EXT_UserObjectsDBClose
	#define GET_UserObjectsDBClose(fl)  ERR_OK
	#define CAL_UserObjectsDBClose(p0,p1) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBClose(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1))
	#define CHK_UserObjectsDBClose  TRUE
	#define EXP_UserObjectsDBClose  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDB_EXTERNAL)
	#define USE_UserObjectsDBClose
	#define EXT_UserObjectsDBClose
	#define GET_UserObjectsDBClose(fl)  ERR_OK
	#define CAL_UserObjectsDBClose(p0,p1) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBClose(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1))
	#define CHK_UserObjectsDBClose  TRUE
	#define EXP_UserObjectsDBClose  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBUserObjectsDBClose
	#define EXT_CmpUserObjectsDBUserObjectsDBClose
	#define GET_CmpUserObjectsDBUserObjectsDBClose  ERR_OK
	#define CAL_CmpUserObjectsDBUserObjectsDBClose(p0,p1)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBClose(p1))
	#define CHK_CmpUserObjectsDBUserObjectsDBClose  TRUE
	#define EXP_CmpUserObjectsDBUserObjectsDBClose  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBClose
	#define EXT_UserObjectsDBClose
	#define GET_UserObjectsDBClose(fl)  ERR_OK
	#define CAL_UserObjectsDBClose(p0,p1)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBClose(p1))
	#define CHK_UserObjectsDBClose  TRUE
	#define EXP_UserObjectsDBClose  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBClose
	#define EXT_UserObjectsDBClose
	#define GET_UserObjectsDBClose(fl)  ERR_OK
	#define CAL_UserObjectsDBClose(p0,p1) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBClose(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1))
	#define CHK_UserObjectsDBClose  TRUE
	#define EXP_UserObjectsDBClose  ERR_OK
#endif




/**
 * <description>Get object name</description>
 * <param name="hObject" type="IN">Handle to the object</param>
 * <param name="pszObject" type="OUT">Pointer to get object name</param>
 * <param name="piMaxLen" type="INOUT">Pointer to length of buffer in pszObject. If pszObject = NULL, only the length of the object name is returned in *piMaxLen</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Object name is returned</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid object handle or pszObject = NULL and piMaxLen = NULL</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserObjectsDBGetName(RTS_HANDLE hDatabase, RTS_HANDLE hObject, char *pszObject, int *piMaxLen);
typedef RTS_RESULT (CDECL * PFUSEROBJECTSDBGETNAME) (RTS_HANDLE hDatabase, RTS_HANDLE hObject, char *pszObject, int *piMaxLen);
#if defined(CMPUSEROBJECTSDB_NOTIMPLEMENTED) || defined(USEROBJECTSDBGETNAME_NOTIMPLEMENTED)
	#define USE_UserObjectsDBGetName
	#define EXT_UserObjectsDBGetName
	#define GET_UserObjectsDBGetName(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBGetName(p0,p1,p2,p3)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserObjectsDBGetName  FALSE
	#define EXP_UserObjectsDBGetName  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBGetName
	#define EXT_UserObjectsDBGetName
	#define GET_UserObjectsDBGetName(fl)  ERR_OK
	#define CAL_UserObjectsDBGetName(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetName(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserObjectsDBGetName  TRUE
	#define EXP_UserObjectsDBGetName  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDB_EXTERNAL)
	#define USE_UserObjectsDBGetName
	#define EXT_UserObjectsDBGetName
	#define GET_UserObjectsDBGetName(fl)  ERR_OK
	#define CAL_UserObjectsDBGetName(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetName(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserObjectsDBGetName  TRUE
	#define EXP_UserObjectsDBGetName  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBUserObjectsDBGetName
	#define EXT_CmpUserObjectsDBUserObjectsDBGetName
	#define GET_CmpUserObjectsDBUserObjectsDBGetName  ERR_OK
	#define CAL_CmpUserObjectsDBUserObjectsDBGetName(p0,p1,p2,p3)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetName(p1,p2,p3))
	#define CHK_CmpUserObjectsDBUserObjectsDBGetName  TRUE
	#define EXP_CmpUserObjectsDBUserObjectsDBGetName  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBGetName
	#define EXT_UserObjectsDBGetName
	#define GET_UserObjectsDBGetName(fl)  ERR_OK
	#define CAL_UserObjectsDBGetName(p0,p1,p2,p3)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetName(p1,p2,p3))
	#define CHK_UserObjectsDBGetName  TRUE
	#define EXP_UserObjectsDBGetName  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBGetName
	#define EXT_UserObjectsDBGetName
	#define GET_UserObjectsDBGetName(fl)  ERR_OK
	#define CAL_UserObjectsDBGetName(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetName(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserObjectsDBGetName  TRUE
	#define EXP_UserObjectsDBGetName  ERR_OK
#endif




/**
 * <description>Get the complete object path name</description>
 * <param name="hObject" type="IN">Handle to the object</param>
 * <param name="pszObject" type="IN">Full object path name (see object tree)</param>
 * <param name="piMaxLen" type="INOUT">Pointer to length of buffer in pszObject. If pszObject = NULL, only the length of the object name is returned in *piMaxLen</param>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Object name is returned</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid object handle or pszObject = NULL and piMaxLen = NULL</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserObjectsDBGetPath(RTS_HANDLE hDatabase, RTS_HANDLE hObject, char *pszObject, int *piMaxLen);
typedef RTS_RESULT (CDECL * PFUSEROBJECTSDBGETPATH) (RTS_HANDLE hDatabase, RTS_HANDLE hObject, char *pszObject, int *piMaxLen);
#if defined(CMPUSEROBJECTSDB_NOTIMPLEMENTED) || defined(USEROBJECTSDBGETPATH_NOTIMPLEMENTED)
	#define USE_UserObjectsDBGetPath
	#define EXT_UserObjectsDBGetPath
	#define GET_UserObjectsDBGetPath(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBGetPath(p0,p1,p2,p3)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserObjectsDBGetPath  FALSE
	#define EXP_UserObjectsDBGetPath  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBGetPath
	#define EXT_UserObjectsDBGetPath
	#define GET_UserObjectsDBGetPath(fl)  ERR_OK
	#define CAL_UserObjectsDBGetPath(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetPath(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserObjectsDBGetPath  TRUE
	#define EXP_UserObjectsDBGetPath  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDB_EXTERNAL)
	#define USE_UserObjectsDBGetPath
	#define EXT_UserObjectsDBGetPath
	#define GET_UserObjectsDBGetPath(fl)  ERR_OK
	#define CAL_UserObjectsDBGetPath(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetPath(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserObjectsDBGetPath  TRUE
	#define EXP_UserObjectsDBGetPath  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBUserObjectsDBGetPath
	#define EXT_CmpUserObjectsDBUserObjectsDBGetPath
	#define GET_CmpUserObjectsDBUserObjectsDBGetPath  ERR_OK
	#define CAL_CmpUserObjectsDBUserObjectsDBGetPath(p0,p1,p2,p3)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetPath(p1,p2,p3))
	#define CHK_CmpUserObjectsDBUserObjectsDBGetPath  TRUE
	#define EXP_CmpUserObjectsDBUserObjectsDBGetPath  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBGetPath
	#define EXT_UserObjectsDBGetPath
	#define GET_UserObjectsDBGetPath(fl)  ERR_OK
	#define CAL_UserObjectsDBGetPath(p0,p1,p2,p3)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetPath(p1,p2,p3))
	#define CHK_UserObjectsDBGetPath  TRUE
	#define EXP_UserObjectsDBGetPath  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBGetPath
	#define EXT_UserObjectsDBGetPath
	#define GET_UserObjectsDBGetPath(fl)  ERR_OK
	#define CAL_UserObjectsDBGetPath(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetPath(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserObjectsDBGetPath  TRUE
	#define EXP_UserObjectsDBGetPath  ERR_OK
#endif




/**
 * <description>Get first child object in object tree of the specified father object</description>
 * <param name="hFatherObject" type="IN">Handle to the father object</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">First child object available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter hFatherObject</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">The user management is not initialized or it is not loaded yet</errorcode>
 * <result>Handle to the child object or RTS_INVALID_HANDLE if failed</result>
 */
STATICITF_DEF RTS_HANDLE CDECL UserObjectsDBGetFirstChild(RTS_HANDLE hDatabase, RTS_HANDLE hFatherObject, RTS_RESULT *pResult);
typedef RTS_HANDLE (CDECL * PFUSEROBJECTSDBGETFIRSTCHILD) (RTS_HANDLE hDatabase, RTS_HANDLE hFatherObject, RTS_RESULT *pResult);
#if defined(CMPUSEROBJECTSDB_NOTIMPLEMENTED) || defined(USEROBJECTSDBGETFIRSTCHILD_NOTIMPLEMENTED)
	#define USE_UserObjectsDBGetFirstChild
	#define EXT_UserObjectsDBGetFirstChild
	#define GET_UserObjectsDBGetFirstChild(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBGetFirstChild(p0,p1,p2)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_UserObjectsDBGetFirstChild  FALSE
	#define EXP_UserObjectsDBGetFirstChild  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBGetFirstChild
	#define EXT_UserObjectsDBGetFirstChild
	#define GET_UserObjectsDBGetFirstChild(fl)  ERR_OK
	#define CAL_UserObjectsDBGetFirstChild(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetFirstChild(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBGetFirstChild  TRUE
	#define EXP_UserObjectsDBGetFirstChild  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDB_EXTERNAL)
	#define USE_UserObjectsDBGetFirstChild
	#define EXT_UserObjectsDBGetFirstChild
	#define GET_UserObjectsDBGetFirstChild(fl)  ERR_OK
	#define CAL_UserObjectsDBGetFirstChild(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetFirstChild(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBGetFirstChild  TRUE
	#define EXP_UserObjectsDBGetFirstChild  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBUserObjectsDBGetFirstChild
	#define EXT_CmpUserObjectsDBUserObjectsDBGetFirstChild
	#define GET_CmpUserObjectsDBUserObjectsDBGetFirstChild  ERR_OK
	#define CAL_CmpUserObjectsDBUserObjectsDBGetFirstChild(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetFirstChild(p1,p2))
	#define CHK_CmpUserObjectsDBUserObjectsDBGetFirstChild  TRUE
	#define EXP_CmpUserObjectsDBUserObjectsDBGetFirstChild  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBGetFirstChild
	#define EXT_UserObjectsDBGetFirstChild
	#define GET_UserObjectsDBGetFirstChild(fl)  ERR_OK
	#define CAL_UserObjectsDBGetFirstChild(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetFirstChild(p1,p2))
	#define CHK_UserObjectsDBGetFirstChild  TRUE
	#define EXP_UserObjectsDBGetFirstChild  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBGetFirstChild
	#define EXT_UserObjectsDBGetFirstChild
	#define GET_UserObjectsDBGetFirstChild(fl)  ERR_OK
	#define CAL_UserObjectsDBGetFirstChild(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetFirstChild(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBGetFirstChild  TRUE
	#define EXP_UserObjectsDBGetFirstChild  ERR_OK
#endif




/**
 * <description>Get next child object in object tree of the specified father object. Must be started with UserObjectsDBGetFirstChild()</description>
 * <param name="hFatherObject" type="IN">Handle to the father object</param>
 * <param name="hPrevChildObject" type="IN">Handle to the previous child object retrieved by UserObjectsDBGetFirstChild() or subsequent calls of UserObjectsDBGetNextChild()</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Next child object available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter hFatherObject or hPrevChildObject</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">The user management is not initialized or it is not loaded yet</errorcode>
 * <result>Handle to the next child object or RTS_INVALID_HANDLE if failed</result>
 */
STATICITF_DEF RTS_HANDLE CDECL UserObjectsDBGetNextChild(RTS_HANDLE hDatabase, RTS_HANDLE hFatherObject, RTS_HANDLE hPrevChildObject, RTS_RESULT *pResult);
typedef RTS_HANDLE (CDECL * PFUSEROBJECTSDBGETNEXTCHILD) (RTS_HANDLE hDatabase, RTS_HANDLE hFatherObject, RTS_HANDLE hPrevChildObject, RTS_RESULT *pResult);
#if defined(CMPUSEROBJECTSDB_NOTIMPLEMENTED) || defined(USEROBJECTSDBGETNEXTCHILD_NOTIMPLEMENTED)
	#define USE_UserObjectsDBGetNextChild
	#define EXT_UserObjectsDBGetNextChild
	#define GET_UserObjectsDBGetNextChild(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBGetNextChild(p0,p1,p2,p3)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_UserObjectsDBGetNextChild  FALSE
	#define EXP_UserObjectsDBGetNextChild  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBGetNextChild
	#define EXT_UserObjectsDBGetNextChild
	#define GET_UserObjectsDBGetNextChild(fl)  ERR_OK
	#define CAL_UserObjectsDBGetNextChild(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetNextChild(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserObjectsDBGetNextChild  TRUE
	#define EXP_UserObjectsDBGetNextChild  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDB_EXTERNAL)
	#define USE_UserObjectsDBGetNextChild
	#define EXT_UserObjectsDBGetNextChild
	#define GET_UserObjectsDBGetNextChild(fl)  ERR_OK
	#define CAL_UserObjectsDBGetNextChild(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetNextChild(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserObjectsDBGetNextChild  TRUE
	#define EXP_UserObjectsDBGetNextChild  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBUserObjectsDBGetNextChild
	#define EXT_CmpUserObjectsDBUserObjectsDBGetNextChild
	#define GET_CmpUserObjectsDBUserObjectsDBGetNextChild  ERR_OK
	#define CAL_CmpUserObjectsDBUserObjectsDBGetNextChild(p0,p1,p2,p3)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetNextChild(p1,p2,p3))
	#define CHK_CmpUserObjectsDBUserObjectsDBGetNextChild  TRUE
	#define EXP_CmpUserObjectsDBUserObjectsDBGetNextChild  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBGetNextChild
	#define EXT_UserObjectsDBGetNextChild
	#define GET_UserObjectsDBGetNextChild(fl)  ERR_OK
	#define CAL_UserObjectsDBGetNextChild(p0,p1,p2,p3)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetNextChild(p1,p2,p3))
	#define CHK_UserObjectsDBGetNextChild  TRUE
	#define EXP_UserObjectsDBGetNextChild  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBGetNextChild
	#define EXT_UserObjectsDBGetNextChild
	#define GET_UserObjectsDBGetNextChild(fl)  ERR_OK
	#define CAL_UserObjectsDBGetNextChild(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetNextChild(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserObjectsDBGetNextChild  TRUE
	#define EXP_UserObjectsDBGetNextChild  ERR_OK
#endif




/**
 * <description>Get the father object in object tree of the specified child object</description>
 * <param name="hChildObject" type="IN">Handle to the child object</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Father object could be retrieved</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid parameter hChildObject</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">The user management is not initialized or it is not loaded yet</errorcode>
 * <result>Handle to the father/parent object or RTS_INVALID_HANDLE if failed</result>
 */
STATICITF_DEF RTS_HANDLE CDECL UserObjectsDBGetFather(RTS_HANDLE hDatabase, RTS_HANDLE hChildObject, RTS_RESULT *pResult);
typedef RTS_HANDLE (CDECL * PFUSEROBJECTSDBGETFATHER) (RTS_HANDLE hDatabase, RTS_HANDLE hChildObject, RTS_RESULT *pResult);
#if defined(CMPUSEROBJECTSDB_NOTIMPLEMENTED) || defined(USEROBJECTSDBGETFATHER_NOTIMPLEMENTED)
	#define USE_UserObjectsDBGetFather
	#define EXT_UserObjectsDBGetFather
	#define GET_UserObjectsDBGetFather(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBGetFather(p0,p1,p2)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_UserObjectsDBGetFather  FALSE
	#define EXP_UserObjectsDBGetFather  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBGetFather
	#define EXT_UserObjectsDBGetFather
	#define GET_UserObjectsDBGetFather(fl)  ERR_OK
	#define CAL_UserObjectsDBGetFather(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetFather(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBGetFather  TRUE
	#define EXP_UserObjectsDBGetFather  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDB_EXTERNAL)
	#define USE_UserObjectsDBGetFather
	#define EXT_UserObjectsDBGetFather
	#define GET_UserObjectsDBGetFather(fl)  ERR_OK
	#define CAL_UserObjectsDBGetFather(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetFather(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBGetFather  TRUE
	#define EXP_UserObjectsDBGetFather  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBUserObjectsDBGetFather
	#define EXT_CmpUserObjectsDBUserObjectsDBGetFather
	#define GET_CmpUserObjectsDBUserObjectsDBGetFather  ERR_OK
	#define CAL_CmpUserObjectsDBUserObjectsDBGetFather(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetFather(p1,p2))
	#define CHK_CmpUserObjectsDBUserObjectsDBGetFather  TRUE
	#define EXP_CmpUserObjectsDBUserObjectsDBGetFather  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBGetFather
	#define EXT_UserObjectsDBGetFather
	#define GET_UserObjectsDBGetFather(fl)  ERR_OK
	#define CAL_UserObjectsDBGetFather(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetFather(p1,p2))
	#define CHK_UserObjectsDBGetFather  TRUE
	#define EXP_UserObjectsDBGetFather  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBGetFather
	#define EXT_UserObjectsDBGetFather
	#define GET_UserObjectsDBGetFather(fl)  ERR_OK
	#define CAL_UserObjectsDBGetFather(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetFather(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBGetFather  TRUE
	#define EXP_UserObjectsDBGetFather  ERR_OK
#endif




/* Iteration over all groups that are assigned to the object */

/**
 * <description>Iteration interface to get the first group in the user rights management of the specified object</description>
 * <param name="hObject" type="IN">Handle to the object</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">First group available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">No group available</errorcode>
 * <result>Handle to the first group of the object in the user rights management or RTS_INVALID_HANDLE if failed</result>
 */
STATICITF_DEF RTS_HANDLE CDECL UserObjectsDBGetFirstGroup(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_RESULT *pResult);
typedef RTS_HANDLE (CDECL * PFUSEROBJECTSDBGETFIRSTGROUP) (RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_RESULT *pResult);
#if defined(CMPUSEROBJECTSDB_NOTIMPLEMENTED) || defined(USEROBJECTSDBGETFIRSTGROUP_NOTIMPLEMENTED)
	#define USE_UserObjectsDBGetFirstGroup
	#define EXT_UserObjectsDBGetFirstGroup
	#define GET_UserObjectsDBGetFirstGroup(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBGetFirstGroup(p0,p1,p2)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_UserObjectsDBGetFirstGroup  FALSE
	#define EXP_UserObjectsDBGetFirstGroup  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBGetFirstGroup
	#define EXT_UserObjectsDBGetFirstGroup
	#define GET_UserObjectsDBGetFirstGroup(fl)  ERR_OK
	#define CAL_UserObjectsDBGetFirstGroup(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetFirstGroup(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBGetFirstGroup  TRUE
	#define EXP_UserObjectsDBGetFirstGroup  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDB_EXTERNAL)
	#define USE_UserObjectsDBGetFirstGroup
	#define EXT_UserObjectsDBGetFirstGroup
	#define GET_UserObjectsDBGetFirstGroup(fl)  ERR_OK
	#define CAL_UserObjectsDBGetFirstGroup(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetFirstGroup(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBGetFirstGroup  TRUE
	#define EXP_UserObjectsDBGetFirstGroup  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBUserObjectsDBGetFirstGroup
	#define EXT_CmpUserObjectsDBUserObjectsDBGetFirstGroup
	#define GET_CmpUserObjectsDBUserObjectsDBGetFirstGroup  ERR_OK
	#define CAL_CmpUserObjectsDBUserObjectsDBGetFirstGroup(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetFirstGroup(p1,p2))
	#define CHK_CmpUserObjectsDBUserObjectsDBGetFirstGroup  TRUE
	#define EXP_CmpUserObjectsDBUserObjectsDBGetFirstGroup  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBGetFirstGroup
	#define EXT_UserObjectsDBGetFirstGroup
	#define GET_UserObjectsDBGetFirstGroup(fl)  ERR_OK
	#define CAL_UserObjectsDBGetFirstGroup(p0,p1,p2)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetFirstGroup(p1,p2))
	#define CHK_UserObjectsDBGetFirstGroup  TRUE
	#define EXP_UserObjectsDBGetFirstGroup  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBGetFirstGroup
	#define EXT_UserObjectsDBGetFirstGroup
	#define GET_UserObjectsDBGetFirstGroup(fl)  ERR_OK
	#define CAL_UserObjectsDBGetFirstGroup(p0,p1,p2) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetFirstGroup(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2))
	#define CHK_UserObjectsDBGetFirstGroup  TRUE
	#define EXP_UserObjectsDBGetFirstGroup  ERR_OK
#endif




/**
 * <description>Iteration interface to get next group in the user rights management of the specified object. Must be started with UserObjectsDBGetFirstGroup()</description>
 * <param name="hObject" type="IN">Handle to the object</param>
 * <param name="hPrevGroup" type="IN">Handle to the previous group retrieved via UserObjectsDBGetFirstGroup() or subsequent calls of UserObjectsDBGetNextGroup()</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Next group available</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid handles</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_OBJECT">No next group available</errorcode>
 * <result>Handle to the next group of the object in the user rights management or RTS_INVALID_HANDLE if failed</result>
 */
STATICITF_DEF RTS_HANDLE CDECL UserObjectsDBGetNextGroup(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_HANDLE hPrevGroup, RTS_RESULT *pResult);
typedef RTS_HANDLE (CDECL * PFUSEROBJECTSDBGETNEXTGROUP) (RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_HANDLE hPrevGroup, RTS_RESULT *pResult);
#if defined(CMPUSEROBJECTSDB_NOTIMPLEMENTED) || defined(USEROBJECTSDBGETNEXTGROUP_NOTIMPLEMENTED)
	#define USE_UserObjectsDBGetNextGroup
	#define EXT_UserObjectsDBGetNextGroup
	#define GET_UserObjectsDBGetNextGroup(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBGetNextGroup(p0,p1,p2,p3)  (RTS_HANDLE)RTS_INVALID_HANDLE
	#define CHK_UserObjectsDBGetNextGroup  FALSE
	#define EXP_UserObjectsDBGetNextGroup  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBGetNextGroup
	#define EXT_UserObjectsDBGetNextGroup
	#define GET_UserObjectsDBGetNextGroup(fl)  ERR_OK
	#define CAL_UserObjectsDBGetNextGroup(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetNextGroup(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserObjectsDBGetNextGroup  TRUE
	#define EXP_UserObjectsDBGetNextGroup  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDB_EXTERNAL)
	#define USE_UserObjectsDBGetNextGroup
	#define EXT_UserObjectsDBGetNextGroup
	#define GET_UserObjectsDBGetNextGroup(fl)  ERR_OK
	#define CAL_UserObjectsDBGetNextGroup(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetNextGroup(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserObjectsDBGetNextGroup  TRUE
	#define EXP_UserObjectsDBGetNextGroup  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBUserObjectsDBGetNextGroup
	#define EXT_CmpUserObjectsDBUserObjectsDBGetNextGroup
	#define GET_CmpUserObjectsDBUserObjectsDBGetNextGroup  ERR_OK
	#define CAL_CmpUserObjectsDBUserObjectsDBGetNextGroup(p0,p1,p2,p3)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetNextGroup(p1,p2,p3))
	#define CHK_CmpUserObjectsDBUserObjectsDBGetNextGroup  TRUE
	#define EXP_CmpUserObjectsDBUserObjectsDBGetNextGroup  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBGetNextGroup
	#define EXT_UserObjectsDBGetNextGroup
	#define GET_UserObjectsDBGetNextGroup(fl)  ERR_OK
	#define CAL_UserObjectsDBGetNextGroup(p0,p1,p2,p3)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetNextGroup(p1,p2,p3))
	#define CHK_UserObjectsDBGetNextGroup  TRUE
	#define EXP_UserObjectsDBGetNextGroup  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBGetNextGroup
	#define EXT_UserObjectsDBGetNextGroup
	#define GET_UserObjectsDBGetNextGroup(fl)  ERR_OK
	#define CAL_UserObjectsDBGetNextGroup(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_HANDLE)RTS_INVALID_HANDLE : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetNextGroup(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserObjectsDBGetNextGroup  TRUE
	#define EXP_UserObjectsDBGetNextGroup  ERR_OK
#endif




/* Get rights */

/**
 * <description>Get the rights and the denied rights of a group on a specified object</description>
 * <param name="hObject" type="IN">Handle to object</param>
 * <param name="hGroup" type="IN">Handle to the group which access rights are requested</param>
 * <element name="pulRights" type="IN">Pointer to get rights of the group. See category "User rights" for details</element>
 * <element name="pulDeniedRights" type="IN">Pointer to get denied rights of the group. See category "User rights" for details</element>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Access rights could be retrieved</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid handles</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserObjectsDBGetGroupRights(RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_HANDLE hGroup, RTS_UI32 *pulRights, RTS_UI32 *pulDeniedRights);
typedef RTS_RESULT (CDECL * PFUSEROBJECTSDBGETGROUPRIGHTS) (RTS_HANDLE hDatabase, RTS_HANDLE hObject, RTS_HANDLE hGroup, RTS_UI32 *pulRights, RTS_UI32 *pulDeniedRights);
#if defined(CMPUSEROBJECTSDB_NOTIMPLEMENTED) || defined(USEROBJECTSDBGETGROUPRIGHTS_NOTIMPLEMENTED)
	#define USE_UserObjectsDBGetGroupRights
	#define EXT_UserObjectsDBGetGroupRights
	#define GET_UserObjectsDBGetGroupRights(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBGetGroupRights(p0,p1,p2,p3,p4)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserObjectsDBGetGroupRights  FALSE
	#define EXP_UserObjectsDBGetGroupRights  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBGetGroupRights
	#define EXT_UserObjectsDBGetGroupRights
	#define GET_UserObjectsDBGetGroupRights(fl)  ERR_OK
	#define CAL_UserObjectsDBGetGroupRights(p0,p1,p2,p3,p4) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetGroupRights(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2,p3,p4))
	#define CHK_UserObjectsDBGetGroupRights  TRUE
	#define EXP_UserObjectsDBGetGroupRights  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDB_EXTERNAL)
	#define USE_UserObjectsDBGetGroupRights
	#define EXT_UserObjectsDBGetGroupRights
	#define GET_UserObjectsDBGetGroupRights(fl)  ERR_OK
	#define CAL_UserObjectsDBGetGroupRights(p0,p1,p2,p3,p4) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetGroupRights(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2,p3,p4))
	#define CHK_UserObjectsDBGetGroupRights  TRUE
	#define EXP_UserObjectsDBGetGroupRights  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBUserObjectsDBGetGroupRights
	#define EXT_CmpUserObjectsDBUserObjectsDBGetGroupRights
	#define GET_CmpUserObjectsDBUserObjectsDBGetGroupRights  ERR_OK
	#define CAL_CmpUserObjectsDBUserObjectsDBGetGroupRights(p0,p1,p2,p3,p4)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetGroupRights(p1,p2,p3,p4))
	#define CHK_CmpUserObjectsDBUserObjectsDBGetGroupRights  TRUE
	#define EXP_CmpUserObjectsDBUserObjectsDBGetGroupRights  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBGetGroupRights
	#define EXT_UserObjectsDBGetGroupRights
	#define GET_UserObjectsDBGetGroupRights(fl)  ERR_OK
	#define CAL_UserObjectsDBGetGroupRights(p0,p1,p2,p3,p4)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetGroupRights(p1,p2,p3,p4))
	#define CHK_UserObjectsDBGetGroupRights  TRUE
	#define EXP_UserObjectsDBGetGroupRights  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBGetGroupRights
	#define EXT_UserObjectsDBGetGroupRights
	#define GET_UserObjectsDBGetGroupRights(fl)  ERR_OK
	#define CAL_UserObjectsDBGetGroupRights(p0,p1,p2,p3,p4) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetGroupRights(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2,p3,p4))
	#define CHK_UserObjectsDBGetGroupRights  TRUE
	#define EXP_UserObjectsDBGetGroupRights  ERR_OK
#endif




/**
 * <description>Check access rights of a user on an object (authorization)</description>
 * <param name="pszObject" type="IN">Full object name (see object tree)</param>
 * <param name="hUser" type="IN">Handle to the user which access rights are checked</param>
 * <element name="ulRequestedRights" type="IN">Requested access rights. See category "User rights" for details</element>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Access permitted</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Access rights could not be retrieved, so no access rights!</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NO_ACCESS_RIGHTS">No access rights!</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserObjectsDBHasRights(RTS_HANDLE hDatabase, char *pszObject, RTS_HANDLE hUser, RTS_UI32 ulRequestedRights);
typedef RTS_RESULT (CDECL * PFUSEROBJECTSDBHASRIGHTS) (RTS_HANDLE hDatabase, char *pszObject, RTS_HANDLE hUser, RTS_UI32 ulRequestedRights);
#if defined(CMPUSEROBJECTSDB_NOTIMPLEMENTED) || defined(USEROBJECTSDBHASRIGHTS_NOTIMPLEMENTED)
	#define USE_UserObjectsDBHasRights
	#define EXT_UserObjectsDBHasRights
	#define GET_UserObjectsDBHasRights(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBHasRights(p0,p1,p2,p3)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserObjectsDBHasRights  FALSE
	#define EXP_UserObjectsDBHasRights  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBHasRights
	#define EXT_UserObjectsDBHasRights
	#define GET_UserObjectsDBHasRights(fl)  ERR_OK
	#define CAL_UserObjectsDBHasRights(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBHasRights(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserObjectsDBHasRights  TRUE
	#define EXP_UserObjectsDBHasRights  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDB_EXTERNAL)
	#define USE_UserObjectsDBHasRights
	#define EXT_UserObjectsDBHasRights
	#define GET_UserObjectsDBHasRights(fl)  ERR_OK
	#define CAL_UserObjectsDBHasRights(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBHasRights(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserObjectsDBHasRights  TRUE
	#define EXP_UserObjectsDBHasRights  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBUserObjectsDBHasRights
	#define EXT_CmpUserObjectsDBUserObjectsDBHasRights
	#define GET_CmpUserObjectsDBUserObjectsDBHasRights  ERR_OK
	#define CAL_CmpUserObjectsDBUserObjectsDBHasRights(p0,p1,p2,p3)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBHasRights(p1,p2,p3))
	#define CHK_CmpUserObjectsDBUserObjectsDBHasRights  TRUE
	#define EXP_CmpUserObjectsDBUserObjectsDBHasRights  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBHasRights
	#define EXT_UserObjectsDBHasRights
	#define GET_UserObjectsDBHasRights(fl)  ERR_OK
	#define CAL_UserObjectsDBHasRights(p0,p1,p2,p3)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBHasRights(p1,p2,p3))
	#define CHK_UserObjectsDBHasRights  TRUE
	#define EXP_UserObjectsDBHasRights  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBHasRights
	#define EXT_UserObjectsDBHasRights
	#define GET_UserObjectsDBHasRights(fl)  ERR_OK
	#define CAL_UserObjectsDBHasRights(p0,p1,p2,p3) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBHasRights(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2,p3))
	#define CHK_UserObjectsDBHasRights  TRUE
	#define EXP_UserObjectsDBHasRights  ERR_OK
#endif




/**
 * <description>Get the rights and the denied rights of a user on a specified object</description>
 * <param name="pszObject" type="IN">Full object name (see object tree)</param>
 * <param name="hUser" type="IN">Handle to the user which access rights are requested</param>
 * <element name="pulRights" type="IN">Pointer to get rights of the user. See category "User rights" for details</element>
 * <element name="pulDeniedRights" type="IN">Pointer to get denied rights of the user. See category "User rights" for details</element>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Access rights could be retrieved</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">Invalid handles</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserObjectsDBGetRights(RTS_HANDLE hDatabase, char *pszObject, RTS_HANDLE hUser, RTS_UI32 *pulRights, RTS_UI32 *pulDeniedRights);
typedef RTS_RESULT (CDECL * PFUSEROBJECTSDBGETRIGHTS) (RTS_HANDLE hDatabase, char *pszObject, RTS_HANDLE hUser, RTS_UI32 *pulRights, RTS_UI32 *pulDeniedRights);
#if defined(CMPUSEROBJECTSDB_NOTIMPLEMENTED) || defined(USEROBJECTSDBGETRIGHTS_NOTIMPLEMENTED)
	#define USE_UserObjectsDBGetRights
	#define EXT_UserObjectsDBGetRights
	#define GET_UserObjectsDBGetRights(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBGetRights(p0,p1,p2,p3,p4)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserObjectsDBGetRights  FALSE
	#define EXP_UserObjectsDBGetRights  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBGetRights
	#define EXT_UserObjectsDBGetRights
	#define GET_UserObjectsDBGetRights(fl)  ERR_OK
	#define CAL_UserObjectsDBGetRights(p0,p1,p2,p3,p4) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetRights(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2,p3,p4))
	#define CHK_UserObjectsDBGetRights  TRUE
	#define EXP_UserObjectsDBGetRights  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDB_EXTERNAL)
	#define USE_UserObjectsDBGetRights
	#define EXT_UserObjectsDBGetRights
	#define GET_UserObjectsDBGetRights(fl)  ERR_OK
	#define CAL_UserObjectsDBGetRights(p0,p1,p2,p3,p4) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetRights(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2,p3,p4))
	#define CHK_UserObjectsDBGetRights  TRUE
	#define EXP_UserObjectsDBGetRights  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBUserObjectsDBGetRights
	#define EXT_CmpUserObjectsDBUserObjectsDBGetRights
	#define GET_CmpUserObjectsDBUserObjectsDBGetRights  ERR_OK
	#define CAL_CmpUserObjectsDBUserObjectsDBGetRights(p0,p1,p2,p3,p4)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetRights(p1,p2,p3,p4))
	#define CHK_CmpUserObjectsDBUserObjectsDBGetRights  TRUE
	#define EXP_CmpUserObjectsDBUserObjectsDBGetRights  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBGetRights
	#define EXT_UserObjectsDBGetRights
	#define GET_UserObjectsDBGetRights(fl)  ERR_OK
	#define CAL_UserObjectsDBGetRights(p0,p1,p2,p3,p4)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetRights(p1,p2,p3,p4))
	#define CHK_UserObjectsDBGetRights  TRUE
	#define EXP_UserObjectsDBGetRights  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBGetRights
	#define EXT_UserObjectsDBGetRights
	#define GET_UserObjectsDBGetRights(fl)  ERR_OK
	#define CAL_UserObjectsDBGetRights(p0,p1,p2,p3,p4) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBGetRights(((ICmpUserObjectsDB*)p0)->pBase->hInstance,p1,p2,p3,p4))
	#define CHK_UserObjectsDBGetRights  TRUE
	#define EXP_UserObjectsDBGetRights  ERR_OK
#endif




/**
 * <description>Explicitly activate the usage of user authentication: no assuming of administrator rights
 * NOTE: The UserObjectsDB is activated implicitly when a DB file is loaded or configured via CODESYS.
 * </description>
 * <result>Error code</result>
 * <errorcode name="RTS_RESULT" type="ERR_OK">Activation was successful</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_NOTINITIALIZED">The user management is not initialized or it is not loaded yet</errorcode>
 */
STATICITF_DEF RTS_RESULT CDECL UserObjectsDBActivate(RTS_HANDLE hDatabase);
typedef RTS_RESULT (CDECL * PFUSEROBJECTSDBACTIVATE) (RTS_HANDLE hDatabase);
#if defined(CMPUSEROBJECTSDB_NOTIMPLEMENTED) || defined(USEROBJECTSDBACTIVATE_NOTIMPLEMENTED)
	#define USE_UserObjectsDBActivate
	#define EXT_UserObjectsDBActivate
	#define GET_UserObjectsDBActivate(fl)  ERR_NOTIMPLEMENTED
	#define CAL_UserObjectsDBActivate(p0)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_UserObjectsDBActivate  FALSE
	#define EXP_UserObjectsDBActivate  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_UserObjectsDBActivate
	#define EXT_UserObjectsDBActivate
	#define GET_UserObjectsDBActivate(fl)  ERR_OK
	#define CAL_UserObjectsDBActivate(p0) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBActivate(((ICmpUserObjectsDB*)p0)->pBase->hInstance))
	#define CHK_UserObjectsDBActivate  TRUE
	#define EXP_UserObjectsDBActivate  ERR_OK
#elif defined(MIXED_LINK) && !defined(CMPUSEROBJECTSDB_EXTERNAL)
	#define USE_UserObjectsDBActivate
	#define EXT_UserObjectsDBActivate
	#define GET_UserObjectsDBActivate(fl)  ERR_OK
	#define CAL_UserObjectsDBActivate(p0) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBActivate(((ICmpUserObjectsDB*)p0)->pBase->hInstance))
	#define CHK_UserObjectsDBActivate  TRUE
	#define EXP_UserObjectsDBActivate  ERR_OK
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpUserObjectsDBUserObjectsDBActivate
	#define EXT_CmpUserObjectsDBUserObjectsDBActivate
	#define GET_CmpUserObjectsDBUserObjectsDBActivate  ERR_OK
	#define CAL_CmpUserObjectsDBUserObjectsDBActivate(p0)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBActivate())
	#define CHK_CmpUserObjectsDBUserObjectsDBActivate  TRUE
	#define EXP_CmpUserObjectsDBUserObjectsDBActivate  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_UserObjectsDBActivate
	#define EXT_UserObjectsDBActivate
	#define GET_UserObjectsDBActivate(fl)  ERR_OK
	#define CAL_UserObjectsDBActivate(p0)		(p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBActivate())
	#define CHK_UserObjectsDBActivate  TRUE
	#define EXP_UserObjectsDBActivate  ERR_OK
#else /* DYNAMIC_LINK */
	#define USE_UserObjectsDBActivate
	#define EXT_UserObjectsDBActivate
	#define GET_UserObjectsDBActivate(fl)  ERR_OK
	#define CAL_UserObjectsDBActivate(p0) (p0 == RTS_INVALID_HANDLE || p0 == NULL ? (RTS_RESULT)ERR_PARAMETER : ((ICmpUserObjectsDB*)p0)->IUserObjectsDBActivate(((ICmpUserObjectsDB*)p0)->pBase->hInstance))
	#define CHK_UserObjectsDBActivate  TRUE
	#define EXP_UserObjectsDBActivate  ERR_OK
#endif




#ifdef __cplusplus
}
#endif



typedef struct
{
	IBase_C *pBase;
	PFUSEROBJECTSDBGETUSEDRIGHTS IUserObjectsDBGetUsedRights;
 	PFUSEROBJECTSDBGETPROPERTIES IUserObjectsDBGetProperties;
 	PFUSEROBJECTSDBGETID IUserObjectsDBGetID;
 	PFUSEROBJECTSDBGETFIRST IUserObjectsDBGetFirst;
 	PFUSEROBJECTSDBGETNEXT IUserObjectsDBGetNext;
 	PFUSEROBJECTSDBOPEN IUserObjectsDBOpen;
 	PFUSEROBJECTSDBCLOSE IUserObjectsDBClose;
 	PFUSEROBJECTSDBGETNAME IUserObjectsDBGetName;
 	PFUSEROBJECTSDBGETPATH IUserObjectsDBGetPath;
 	PFUSEROBJECTSDBGETFIRSTCHILD IUserObjectsDBGetFirstChild;
 	PFUSEROBJECTSDBGETNEXTCHILD IUserObjectsDBGetNextChild;
 	PFUSEROBJECTSDBGETFATHER IUserObjectsDBGetFather;
 	PFUSEROBJECTSDBGETFIRSTGROUP IUserObjectsDBGetFirstGroup;
 	PFUSEROBJECTSDBGETNEXTGROUP IUserObjectsDBGetNextGroup;
 	PFUSEROBJECTSDBGETGROUPRIGHTS IUserObjectsDBGetGroupRights;
 	PFUSEROBJECTSDBHASRIGHTS IUserObjectsDBHasRights;
 	PFUSEROBJECTSDBGETRIGHTS IUserObjectsDBGetRights;
 	PFUSEROBJECTSDBACTIVATE IUserObjectsDBActivate;
 } ICmpUserObjectsDB_C;

#ifdef CPLUSPLUS
class ICmpUserObjectsDB : public IBase
{
	public:
		virtual RTS_RESULT CDECL IUserObjectsDBGetUsedRights(RTS_HANDLE hObject, RTS_UI32 *pulUsedRights) =0;
		virtual RTS_RESULT CDECL IUserObjectsDBGetProperties(RTS_HANDLE hObject, RTS_UI32 *pulProperties) =0;
		virtual RTS_RESULT CDECL IUserObjectsDBGetID(RTS_HANDLE hObject, RTS_UI32 *pulID) =0;
		virtual RTS_HANDLE CDECL IUserObjectsDBGetFirst(RTS_RESULT *pResult) =0;
		virtual RTS_HANDLE CDECL IUserObjectsDBGetNext(RTS_HANDLE hPrevObject, RTS_RESULT *pResult) =0;
		virtual RTS_HANDLE CDECL IUserObjectsDBOpen(char *pszObject, RTS_RESULT *pResult) =0;
		virtual RTS_RESULT CDECL IUserObjectsDBClose(RTS_HANDLE hObject) =0;
		virtual RTS_RESULT CDECL IUserObjectsDBGetName(RTS_HANDLE hObject, char *pszObject, int *piMaxLen) =0;
		virtual RTS_RESULT CDECL IUserObjectsDBGetPath(RTS_HANDLE hObject, char *pszObject, int *piMaxLen) =0;
		virtual RTS_HANDLE CDECL IUserObjectsDBGetFirstChild(RTS_HANDLE hFatherObject, RTS_RESULT *pResult) =0;
		virtual RTS_HANDLE CDECL IUserObjectsDBGetNextChild(RTS_HANDLE hFatherObject, RTS_HANDLE hPrevChildObject, RTS_RESULT *pResult) =0;
		virtual RTS_HANDLE CDECL IUserObjectsDBGetFather(RTS_HANDLE hChildObject, RTS_RESULT *pResult) =0;
		virtual RTS_HANDLE CDECL IUserObjectsDBGetFirstGroup(RTS_HANDLE hObject, RTS_RESULT *pResult) =0;
		virtual RTS_HANDLE CDECL IUserObjectsDBGetNextGroup(RTS_HANDLE hObject, RTS_HANDLE hPrevGroup, RTS_RESULT *pResult) =0;
		virtual RTS_RESULT CDECL IUserObjectsDBGetGroupRights(RTS_HANDLE hObject, RTS_HANDLE hGroup, RTS_UI32 *pulRights, RTS_UI32 *pulDeniedRights) =0;
		virtual RTS_RESULT CDECL IUserObjectsDBHasRights(char *pszObject, RTS_HANDLE hUser, RTS_UI32 ulRequestedRights) =0;
		virtual RTS_RESULT CDECL IUserObjectsDBGetRights(char *pszObject, RTS_HANDLE hUser, RTS_UI32 *pulRights, RTS_UI32 *pulDeniedRights) =0;
		virtual RTS_RESULT CDECL IUserObjectsDBActivate(void) =0;
};
	#ifndef ITF_CmpUserObjectsDB
		#define ITF_CmpUserObjectsDB static ICmpUserObjectsDB *pICmpUserObjectsDB = NULL;
	#endif
	#define EXTITF_CmpUserObjectsDB
#else	/*CPLUSPLUS*/
	typedef ICmpUserObjectsDB_C		ICmpUserObjectsDB;
	#ifndef ITF_CmpUserObjectsDB
		#define ITF_CmpUserObjectsDB
	#endif
	#define EXTITF_CmpUserObjectsDB
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_CMPUSEROBJECTSDBITF_H_*/
