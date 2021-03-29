/***********************************************************************
 * DO NOT MODIFY!
 * This is a generated file. Do not modify it's contents directly
 ***********************************************************************/

/**
 * <name>CmpUserDBTemplate</name>
 * <description> 
 *	<p>An example on how to implement the user, group, and object databases and their configuration for the user management.</p>
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */
#ifndef _CMPUSERDBTEMPLATEDEP_H_
#define _CMPUSERDBTEMPLATEDEP_H_

#define COMPONENT_NAME "CmpUserDBTemplate" COMPONENT_NAME_POSTFIX
#define COMPONENT_ID    ADDVENDORID(CMP_VENDORID, CMPID_CmpUserDBTemplate)
#define COMPONENT_NAME_UNQUOTED CmpUserDBTemplate






#define CMP_VERSION         UINT32_C(0x0305100A)
#define CMP_VERSION_STRING "3.5.16.10"
#define CMP_VERSION_RC      3,5,16,10

/* NOTE: REPLACE 0x0001 BY YOUR VENDORID */
#define CMP_VENDORID       0x0001

#ifndef WIN32_RESOURCES

#include "CmpLogItf.h"
#include "CMUtilsItf.h"

#define CMPID_CmpUserDBTemplate		0x2000								/* NOTE: START HERE WITH YOUR COMPONENTIDS (see CmpItf.h */
#define CLASSID_CCmpUserDBTemplate	ADDVENDORID(CMP_VENDORID, 0x2000)	/* NOTE: START HERE WITH YOUR CLASSIDS (see CmpItf.h */
#define ITFID_ICmpUserDBTemplate		ADDVENDORID(CMP_VENDORID, 0x2000)	/* NOTE: START HERE WITH YOUR INTERFACEIDS (see CmpItf.h */







/**
 * \file CmpUserDBItf.h
 */
#include "CmpUserDBItf.h"

/**
 * \file CmpUserDBConfigurationItf.h
 */
#include "CmpUserDBConfigurationItf.h"

/**
 * \file CmpUserGroupsDBItf.h
 */
#include "CmpUserGroupsDBItf.h"

/**
 * \file CmpUserGroupsDBConfigurationItf.h
 */
#include "CmpUserGroupsDBConfigurationItf.h"

/**
 * \file CmpUserObjectsDBItf.h
 */
#include "CmpUserObjectsDBItf.h"

/**
 * \file CmpUserObjectsDBConfigurationItf.h
 */
#include "CmpUserObjectsDBConfigurationItf.h"

















/*Obsolete include: CMUtilsItf.m4*/


#include "CmpUserMgrItf.h"


#include "CmpCryptMD5Itf.h"


#include "CmpSrvItf.h"


#include "SysFileItf.h"


#include "CmpEventMgrItf.h"


#include "CmpDeviceItf.h"



    



























     






























#ifdef CPLUSPLUS
    #define INIT_STMT \
    {\
        IBase *pIBase;\
        RTS_RESULT initResult;\
        if (pICmpLog == NULL && s_pfCMCreateInstance != NULL) \
        { \
            pIBase = (IBase *)s_pfCMCreateInstance(CLASSID_CCmpLog, &initResult); \
            if (pIBase != NULL) \
            { \
                pICmpLog = (ICmpLog *)pIBase->QueryInterface(pIBase, ITFID_ICmpLog, &initResult); \
                pIBase->Release(pIBase); \
            } \
        } \
        if (pICMUtils == NULL && s_pfCMCreateInstance != NULL) \
        { \
            pIBase = (IBase *)s_pfCMCreateInstance(CLASSID_CCMUtils, &initResult); \
            if (pIBase != NULL) \
            { \
                pICMUtils = (ICMUtils *)pIBase->QueryInterface(pIBase, ITFID_ICMUtils, &initResult); \
                pIBase->Release(pIBase); \
            } \
        } \
        if (pICmpDevice == NULL && s_pfCMCreateInstance != NULL) \
        { \
            pIBase = (IBase *)s_pfCMCreateInstance(CLASSID_CCmpDevice, &initResult); \
            if (pIBase != NULL) \
            { \
                pICmpDevice = (ICmpDevice *)pIBase->QueryInterface(pIBase, ITFID_ICmpDevice, &initResult); \
                pIBase->Release(pIBase); \
            } \
        } \
          if (pICmpEventMgr == NULL && s_pfCMCreateInstance != NULL) \
        { \
            pIBase = (IBase *)s_pfCMCreateInstance(CLASSID_CCmpEventMgr, &initResult); \
            if (pIBase != NULL) \
            { \
                pICmpEventMgr = (ICmpEventMgr *)pIBase->QueryInterface(pIBase, ITFID_ICmpEventMgr, &initResult); \
                pIBase->Release(pIBase); \
            } \
        } \
          if (pISysFile == NULL && s_pfCMCreateInstance != NULL) \
        { \
            pIBase = (IBase *)s_pfCMCreateInstance(CLASSID_CSysFile, &initResult); \
            if (pIBase != NULL) \
            { \
                pISysFile = (ISysFile *)pIBase->QueryInterface(pIBase, ITFID_ISysFile, &initResult); \
                pIBase->Release(pIBase); \
            } \
        } \
          if (pICmpSrv == NULL && s_pfCMCreateInstance != NULL) \
        { \
            pIBase = (IBase *)s_pfCMCreateInstance(CLASSID_CCmpSrv, &initResult); \
            if (pIBase != NULL) \
            { \
                pICmpSrv = (ICmpSrv *)pIBase->QueryInterface(pIBase, ITFID_ICmpSrv, &initResult); \
                pIBase->Release(pIBase); \
            } \
        } \
          if (pICmpCryptMD5 == NULL && s_pfCMCreateInstance != NULL) \
        { \
            pIBase = (IBase *)s_pfCMCreateInstance(CLASSID_CCmpCryptMD5, &initResult); \
            if (pIBase != NULL) \
            { \
                pICmpCryptMD5 = (ICmpCryptMD5 *)pIBase->QueryInterface(pIBase, ITFID_ICmpCryptMD5, &initResult); \
                pIBase->Release(pIBase); \
            } \
        } \
          if (pICmpUserMgr == NULL && s_pfCMCreateInstance != NULL) \
        { \
            pIBase = (IBase *)s_pfCMCreateInstance(CLASSID_CCmpUserMgr, &initResult); \
            if (pIBase != NULL) \
            { \
                pICmpUserMgr = (ICmpUserMgr *)pIBase->QueryInterface(pIBase, ITFID_ICmpUserMgr, &initResult); \
                pIBase->Release(pIBase); \
            } \
        } \
          /*Obsolete include CMUtils*/ \
		   \
    }
    #define INIT_LOCALS_STMT \
    {\
        pICmpLog = NULL; \
        pICMUtils = NULL; \
        pICmpDevice = NULL; \
          pICmpEventMgr = NULL; \
          pISysFile = NULL; \
          pICmpSrv = NULL; \
          pICmpCryptMD5 = NULL; \
          pICmpUserMgr = NULL; \
          /*Obsolete include CMUtils*/ \
		   \
    }
    #define EXIT_STMT \
    {\
        IBase *pIBase;\
        RTS_RESULT exitResult;\
        if (pICmpLog != NULL) \
        { \
            pIBase = (IBase *)pICmpLog->QueryInterface(pICmpLog, ITFID_IBase, &exitResult); \
            if (pIBase != NULL) \
            { \
                 pIBase->Release(pIBase); \
                 if (pIBase->Release(pIBase) == 0) /* The object will be deleted here! */ \
                    pICmpLog = NULL; \
            } \
        } \
        if (pICMUtils != NULL) \
        { \
            pIBase = (IBase *)pICMUtils->QueryInterface(pICMUtils, ITFID_IBase, &exitResult); \
            if (pIBase != NULL) \
            { \
                 pIBase->Release(pIBase); \
                 if (pIBase->Release(pIBase) == 0) /* The object will be deleted here! */ \
                    pICMUtils = NULL; \
            } \
        } \
        if (pICmpDevice != NULL) \
        { \
            pIBase = (IBase *)pICmpDevice->QueryInterface(pICmpDevice, ITFID_IBase, &exitResult); \
            if (pIBase != NULL) \
            { \
                 pIBase->Release(pIBase); \
                 if (pIBase->Release(pIBase) == 0) /* The object will be deleted here! */ \
                    pICmpDevice = NULL; \
            } \
        } \
          if (pICmpEventMgr != NULL) \
        { \
            pIBase = (IBase *)pICmpEventMgr->QueryInterface(pICmpEventMgr, ITFID_IBase, &exitResult); \
            if (pIBase != NULL) \
            { \
                 pIBase->Release(pIBase); \
                 if (pIBase->Release(pIBase) == 0) /* The object will be deleted here! */ \
                    pICmpEventMgr = NULL; \
            } \
        } \
          if (pISysFile != NULL) \
        { \
            pIBase = (IBase *)pISysFile->QueryInterface(pISysFile, ITFID_IBase, &exitResult); \
            if (pIBase != NULL) \
            { \
                 pIBase->Release(pIBase); \
                 if (pIBase->Release(pIBase) == 0) /* The object will be deleted here! */ \
                    pISysFile = NULL; \
            } \
        } \
          if (pICmpSrv != NULL) \
        { \
            pIBase = (IBase *)pICmpSrv->QueryInterface(pICmpSrv, ITFID_IBase, &exitResult); \
            if (pIBase != NULL) \
            { \
                 pIBase->Release(pIBase); \
                 if (pIBase->Release(pIBase) == 0) /* The object will be deleted here! */ \
                    pICmpSrv = NULL; \
            } \
        } \
          if (pICmpCryptMD5 != NULL) \
        { \
            pIBase = (IBase *)pICmpCryptMD5->QueryInterface(pICmpCryptMD5, ITFID_IBase, &exitResult); \
            if (pIBase != NULL) \
            { \
                 pIBase->Release(pIBase); \
                 if (pIBase->Release(pIBase) == 0) /* The object will be deleted here! */ \
                    pICmpCryptMD5 = NULL; \
            } \
        } \
          if (pICmpUserMgr != NULL) \
        { \
            pIBase = (IBase *)pICmpUserMgr->QueryInterface(pICmpUserMgr, ITFID_IBase, &exitResult); \
            if (pIBase != NULL) \
            { \
                 pIBase->Release(pIBase); \
                 if (pIBase->Release(pIBase) == 0) /* The object will be deleted here! */ \
                    pICmpUserMgr = NULL; \
            } \
        } \
          /*Obsolete include CMUtils*/ \
		   \
    }
#else
    #define INIT_STMT
    #define INIT_LOCALS_STMT
    #define EXIT_STMT
#endif



#if defined(STATIC_LINK)
    #define IMPORT_STMT
#else
    #define IMPORT_STMT \
    {\
        RTS_RESULT importResult = ERR_OK;\
        RTS_RESULT TempResult = ERR_OK;\
        INIT_STMT   \
        TempResult = GET_LogAdd(CM_IMPORT_OPTIONAL_FUNCTION); \
        TempResult = GET_CMUtlMemCpy(CM_IMPORT_OPTIONAL_FUNCTION); \
        if (ERR_OK == importResult ) importResult = GET_EventClose(0);\
          if (ERR_OK == importResult ) importResult = GET_EventUnregisterCallbackFunction(0);\
          if (ERR_OK == importResult ) importResult = GET_EventRegisterCallbackFunction(0);\
          if (ERR_OK == importResult ) importResult = GET_EventOpen(0);\
          if (ERR_OK == importResult ) importResult = GET_SysFileAddToBlacklist(0);\
          if (ERR_OK == importResult ) importResult = GET_SysFileDelete(0);\
          if (ERR_OK == importResult ) importResult = GET_SysFileRead(0);\
          if (ERR_OK == importResult ) importResult = GET_SysFileWrite(0);\
          if (ERR_OK == importResult ) importResult = GET_SysFileClose(0);\
          if (ERR_OK == importResult ) importResult = GET_SysFileOpen(0);\
          if (ERR_OK == importResult ) importResult = GET_ServerGenerateSessionId(0);\
          if (ERR_OK == importResult ) importResult = GET_CryptMD5Calculate(0);\
          if (ERR_OK == importResult ) importResult = GET_UserMgrUnregisterUserObjectsDBConfig(0);\
          if (ERR_OK == importResult ) importResult = GET_UserMgrUnregisterUserObjectsDB(0);\
          if (ERR_OK == importResult ) importResult = GET_UserMgrUnregisterUserGroupsDBConfig(0);\
          if (ERR_OK == importResult ) importResult = GET_UserMgrUnregisterUserGroupsDB(0);\
          if (ERR_OK == importResult ) importResult = GET_UserMgrUnregisterUserDBConfig(0);\
          if (ERR_OK == importResult ) importResult = GET_UserMgrUnregisterUserDB(0);\
          if (ERR_OK == importResult ) importResult = GET_UserMgrRegisterUserObjectsDBConfig(0);\
          if (ERR_OK == importResult ) importResult = GET_UserMgrRegisterUserObjectsDB(0);\
          if (ERR_OK == importResult ) importResult = GET_UserMgrRegisterUserGroupsDBConfig(0);\
          if (ERR_OK == importResult ) importResult = GET_UserMgrRegisterUserGroupsDB(0);\
          if (ERR_OK == importResult ) importResult = GET_UserMgrRegisterUserDBConfig(0);\
          if (ERR_OK == importResult ) importResult = GET_UserMgrRegisterUserDB(0);\
          if (ERR_OK == importResult ) importResult = GET_UserMgrIsAdministrator(0);\
          if (ERR_OK == importResult ) importResult = GET_UserMgrGroupHasUser(0);\
          if (ERR_OK == importResult ) importResult = GET_CMUtlStrRChr(0);\
          if (ERR_OK == importResult ) importResult = GET_CMUtlSafeStrCpy(0);\
           \
        /* To make LINT happy */\
        TempResult = TempResult;\
        if (ERR_OK != importResult) return importResult;\
    }
#endif



#ifndef CMPUSERDBTEMPLATE_DISABLE_EXTREF
#define EXPORT_EXTREF_STMT \
                                                                                                                                            
#else
#define EXPORT_EXTREF_STMT
#endif
#ifndef CMPUSERDBTEMPLATE_DISABLE_EXTREF2
#define EXPORT_EXTREF2_STMT \
                                                                                                                                            
#else
#define EXPORT_EXTREF2_STMT
#endif
#if !defined(CMPUSERDBTEMPLATE_DISABLE_CMPITF) && !defined(STATIC_LINK) && !defined(CPLUSPLUS) && !defined(CPLUSPLUS_ONLY)
#define EXPORT_CMPITF_STMT \
    {\
                                                                                                                                            \
        { ((RTS_VOID_FCTPTR)(void *)0), "", 0, 0 }\
    }
#else
#define EXPORT_CMPITF_STMT \
    {\
        { ((RTS_VOID_FCTPTR)(void *)0), "", 0, 0 }\
    }
#endif
#define EXPORT_CPP_STMT


#if defined(STATIC_LINK)
    #define EXPORT_STMT\
    {\
        RTS_RESULT ExpResult;\
        if (NULL == s_pfCMRegisterAPI)\
            return ERR_NOTINITIALIZED;\
        ExpResult = s_pfCMRegisterAPI(s_ExternalsTable, 0, 1, COMPONENT_ID);\
        if (ERR_OK != ExpResult)\
            return ExpResult;\
    }
#else
    #define EXPORT_STMT\
    {\
        RTS_RESULT ExpResult;\
        if (NULL == s_pfCMRegisterAPI)\
            return ERR_NOTINITIALIZED;\
        ExpResult = s_pfCMRegisterAPI(s_ExternalsTable, 0, 1, COMPONENT_ID);\
        if (ERR_OK != ExpResult)\
            return ExpResult;\
        ExpResult = s_pfCMRegisterAPI(s_ItfTable, 0, 0, COMPONENT_ID);\
        if (ERR_OK != ExpResult)\
            return ExpResult;\
    }
#endif

#define USE_STMT \
    /*lint -save --e{528} --e{551} */ \
    static volatile PF_REGISTER_API s_pfCMRegisterAPI; \
    static volatile PF_REGISTER_API2 s_pfCMRegisterAPI2; \
    static volatile PF_GET_API s_pfCMGetAPI; \
    static volatile PF_GET_API2 s_pfCMGetAPI2; \
    static volatile PF_REGISTER_CLASS s_pfCMRegisterClass; \
    static volatile PF_CREATEINSTANCE s_pfCMCreateInstance; \
    static volatile PF_CALL_HOOK s_pfCMCallHook; \
    static const CMP_EXT_FUNCTION_REF s_ExternalsTable[] =\
    {\
        EXPORT_EXTREF_STMT\
        EXPORT_EXTREF2_STMT\
        { ((RTS_VOID_FCTPTR)(void *)0), "", 0, 0 }\
    };\
    static const CMP_EXT_FUNCTION_REF s_ItfTable[] = EXPORT_CMPITF_STMT; \
    /*lint -restore */  \
    static int CDECL ExportFunctions(void); \
    static int CDECL ImportFunctions(void); \
    static IBase* CDECL CreateInstance(CLASSID cid, RTS_RESULT *pResult); \
    static RTS_RESULT CDECL DeleteInstance(IBase *pIBase); \
    static RTS_UI32 CDECL CmpGetVersion(void); \
    static RTS_RESULT CDECL HookFunction(RTS_UI32 ulHook, RTS_UINTPTR ulParam1, RTS_UINTPTR ulParam2); \
    ITF_CmpLog   \
    ITF_CMUtils  \
    USE_CMUtlMemCpy  \
    USE_LogAdd \
	/*obsolete entry ITF_CMUtils*/      \
	ITF_CmpUserMgr     \
	ITF_CmpCryptMD5     \
	ITF_CmpSrv     \
	ITF_SysFile     \
	ITF_CmpEventMgr     \
	ITF_CmpDevice      \
    USE_CMUtlSafeStrCpy      \
    USE_CMUtlStrRChr      \
    USE_UserMgrGroupHasUser      \
    USE_UserMgrIsAdministrator      \
    USE_UserMgrRegisterUserDB      \
    USE_UserMgrRegisterUserDBConfig      \
    USE_UserMgrRegisterUserGroupsDB      \
    USE_UserMgrRegisterUserGroupsDBConfig      \
    USE_UserMgrRegisterUserObjectsDB      \
    USE_UserMgrRegisterUserObjectsDBConfig      \
    USE_UserMgrUnregisterUserDB      \
    USE_UserMgrUnregisterUserDBConfig      \
    USE_UserMgrUnregisterUserGroupsDB      \
    USE_UserMgrUnregisterUserGroupsDBConfig      \
    USE_UserMgrUnregisterUserObjectsDB      \
    USE_UserMgrUnregisterUserObjectsDBConfig      \
    USE_CryptMD5Calculate      \
    USE_ServerGenerateSessionId      \
    USE_SysFileOpen      \
    USE_SysFileClose      \
    USE_SysFileWrite      \
    USE_SysFileRead      \
    USE_SysFileDelete      \
    USE_SysFileAddToBlacklist      \
    USE_EventOpen      \
    USE_EventRegisterCallbackFunction      \
    USE_EventUnregisterCallbackFunction      \
    USE_EventClose     
#define USEIMPORT_STMT \
    /*lint -save --e{551} */ \
    static volatile PF_REGISTER_API s_pfCMRegisterAPI; \
    static volatile PF_REGISTER_API2 s_pfCMRegisterAPI2; \
    static volatile PF_GET_API s_pfCMGetAPI; \
    static volatile PF_GET_API2 s_pfCMGetAPI2; \
    static volatile PF_REGISTER_CLASS s_pfCMRegisterClass; \
    static volatile PF_CREATEINSTANCE s_pfCMCreateInstance; \
    static volatile PF_CALL_HOOK s_pfCMCallHook; \
    /*lint -restore */  \
    ITF_CmpLog   \
    ITF_CMUtils  \
    USE_CMUtlMemCpy  \
    USE_LogAdd \
	/*obsolete entry ITF_CMUtils*/     \
	ITF_CmpUserMgr    \
	ITF_CmpCryptMD5    \
	ITF_CmpSrv    \
	ITF_SysFile    \
	ITF_CmpEventMgr    \
	ITF_CmpDevice     \
    USE_CMUtlSafeStrCpy      \
    USE_CMUtlStrRChr      \
    USE_UserMgrGroupHasUser      \
    USE_UserMgrIsAdministrator      \
    USE_UserMgrRegisterUserDB      \
    USE_UserMgrRegisterUserDBConfig      \
    USE_UserMgrRegisterUserGroupsDB      \
    USE_UserMgrRegisterUserGroupsDBConfig      \
    USE_UserMgrRegisterUserObjectsDB      \
    USE_UserMgrRegisterUserObjectsDBConfig      \
    USE_UserMgrUnregisterUserDB      \
    USE_UserMgrUnregisterUserDBConfig      \
    USE_UserMgrUnregisterUserGroupsDB      \
    USE_UserMgrUnregisterUserGroupsDBConfig      \
    USE_UserMgrUnregisterUserObjectsDB      \
    USE_UserMgrUnregisterUserObjectsDBConfig      \
    USE_CryptMD5Calculate      \
    USE_ServerGenerateSessionId      \
    USE_SysFileOpen      \
    USE_SysFileClose      \
    USE_SysFileWrite      \
    USE_SysFileRead      \
    USE_SysFileDelete      \
    USE_SysFileAddToBlacklist      \
    USE_EventOpen      \
    USE_EventRegisterCallbackFunction      \
    USE_EventUnregisterCallbackFunction      \
    USE_EventClose     
#define USEEXTERN_STMT \
    EXT_CMUtlMemCpy  \
    EXT_LogAdd \
	/*obsolete entry EXTITF_CMUtils*/     \
	EXTITF_CmpUserMgr    \
	EXTITF_CmpCryptMD5    \
	EXTITF_CmpSrv    \
	EXTITF_SysFile    \
	EXTITF_CmpEventMgr    \
	EXTITF_CmpDevice     \
    EXT_CMUtlSafeStrCpy  \
    EXT_CMUtlStrRChr  \
    EXT_UserMgrGroupHasUser  \
    EXT_UserMgrIsAdministrator  \
    EXT_UserMgrRegisterUserDB  \
    EXT_UserMgrRegisterUserDBConfig  \
    EXT_UserMgrRegisterUserGroupsDB  \
    EXT_UserMgrRegisterUserGroupsDBConfig  \
    EXT_UserMgrRegisterUserObjectsDB  \
    EXT_UserMgrRegisterUserObjectsDBConfig  \
    EXT_UserMgrUnregisterUserDB  \
    EXT_UserMgrUnregisterUserDBConfig  \
    EXT_UserMgrUnregisterUserGroupsDB  \
    EXT_UserMgrUnregisterUserGroupsDBConfig  \
    EXT_UserMgrUnregisterUserObjectsDB  \
    EXT_UserMgrUnregisterUserObjectsDBConfig  \
    EXT_CryptMD5Calculate  \
    EXT_ServerGenerateSessionId  \
    EXT_SysFileOpen  \
    EXT_SysFileClose  \
    EXT_SysFileWrite  \
    EXT_SysFileRead  \
    EXT_SysFileDelete  \
    EXT_SysFileAddToBlacklist  \
    EXT_EventOpen  \
    EXT_EventRegisterCallbackFunction  \
    EXT_EventUnregisterCallbackFunction  \
    EXT_EventClose 
#ifndef COMPONENT_NAME
    #error COMPONENT_NAME is not defined. This prevents the component from being linked statically. Use SET_COMPONENT_NAME(<name_of_your_component>) to set the name of the component in your .m4 component description.
#endif




#if defined(STATIC_LINK) || defined(MIXED_LINK) || defined(DYNAMIC_LINK) || defined(CPLUSPLUS_STATIC_LINK)
    #define ComponentEntry CmpUserDBTemplate__Entry
#endif


#ifdef CPLUSPLUS

class CCmpUserDBTemplate : public ICmpUserDB , public ICmpUserDBConfiguration , public ICmpUserGroupsDB , public ICmpUserGroupsDBConfiguration , public ICmpUserObjectsDB , public ICmpUserObjectsDBConfiguration 
{
    public:
        CCmpUserDBTemplate() : hCmpUserDBTemplate(RTS_INVALID_HANDLE), iRefCount(0)
        {
        }
        virtual ~CCmpUserDBTemplate()
        {
        }
        virtual unsigned long AddRef(IBase *pIBase = NULL)
        {
            iRefCount++;
            return iRefCount;
        }
        virtual unsigned long Release(IBase *pIBase = NULL)
        {
            iRefCount--;
            if (iRefCount == 0)
            {
                delete this;
                return 0;
            }
            return iRefCount;
        }

        
        virtual void* QueryInterface(IBase *pIBase, ITFID iid, RTS_RESULT *pResult)
        {
            void *pItf;
            if (iid == ITFID_IBase)
                pItf = dynamic_cast<IBase *>((ICmpUserDB *)this);            
            else if (iid == ITFID_ICmpUserDB)
                pItf = dynamic_cast<ICmpUserDB *>(this); 
            else if (iid == ITFID_ICmpUserDBConfiguration)
                pItf = dynamic_cast<ICmpUserDBConfiguration *>(this); 
            else if (iid == ITFID_ICmpUserGroupsDB)
                pItf = dynamic_cast<ICmpUserGroupsDB *>(this); 
            else if (iid == ITFID_ICmpUserGroupsDBConfiguration)
                pItf = dynamic_cast<ICmpUserGroupsDBConfiguration *>(this); 
            else if (iid == ITFID_ICmpUserObjectsDB)
                pItf = dynamic_cast<ICmpUserObjectsDB *>(this); 
            else if (iid == ITFID_ICmpUserObjectsDBConfiguration)
                pItf = dynamic_cast<ICmpUserObjectsDBConfiguration *>(this); 
            else
            {
                if (pResult != NULL)
                    *pResult = ERR_NOTIMPLEMENTED;
                return NULL;
            }
            if (pResult != (RTS_RESULT *)1)
                (reinterpret_cast<IBase *>(pItf))->AddRef();
            if (pResult != NULL && pResult != (RTS_RESULT *)1)
                *pResult = ERR_OK;
            return pItf;
        }
        virtual RTS_RESULT CDECL IUserObjectsDBConfigLoad(void);
        virtual RTS_RESULT CDECL IUserObjectsDBConfigStore(void);
        virtual RTS_RESULT CDECL IUserObjectsDBConfigRelease(void);
        virtual RTS_RESULT CDECL IUserObjectsDBConfigReleaseRights(void);
        virtual RTS_HANDLE CDECL IUserObjectsDBConfigAdd(char *pszObject, RTS_RESULT *pResult);
        virtual RTS_HANDLE CDECL IUserObjectsDBConfigAdd2(char *pszObject, RTS_UI32 properties, RTS_RESULT *pResult);
        virtual RTS_RESULT CDECL IUserObjectsDBConfigRemove(RTS_HANDLE hObject);
        virtual RTS_HANDLE CDECL IUserObjectsDBConfigAddChild(RTS_HANDLE hFatherObject, char *pszObject, RTS_RESULT *pResult);
        virtual RTS_RESULT CDECL IUserObjectsDBConfigSetUsedRights(RTS_HANDLE hObject, RTS_UI32 ulUsedRights);
        virtual RTS_RESULT CDECL IUserObjectsDBConfigSetID(RTS_HANDLE hObject, RTS_UI32 ulID);
        virtual RTS_RESULT CDECL IUserObjectsDBConfigAddGroup(RTS_HANDLE hObject, RTS_HANDLE hGroup);
        virtual RTS_RESULT CDECL IUserObjectsDBConfigRemoveGroup(RTS_HANDLE hObject, RTS_HANDLE hGroup);
        virtual RTS_RESULT CDECL IUserObjectsDBConfigSetGroupRights(RTS_HANDLE hObject, RTS_HANDLE hGroup, RTS_UI32 ulRights);
        virtual RTS_RESULT CDECL IUserObjectsDBConfigSetGroupDeniedRights(RTS_HANDLE hObject, RTS_HANDLE hGroup, RTS_UI32 ulDeniedRights);
        virtual RTS_RESULT CDECL IUserObjectsDBConfigClearRights(RTS_HANDLE hObject);
        virtual RTS_RESULT CDECL IUserObjectsDBGetUsedRights(RTS_HANDLE hObject, RTS_UI32 *pulUsedRights);
        virtual RTS_RESULT CDECL IUserObjectsDBGetProperties(RTS_HANDLE hObject, RTS_UI32 *pulProperties);
        virtual RTS_RESULT CDECL IUserObjectsDBGetID(RTS_HANDLE hObject, RTS_UI32 *pulID);
        virtual RTS_HANDLE CDECL IUserObjectsDBGetFirst(RTS_RESULT *pResult);
        virtual RTS_HANDLE CDECL IUserObjectsDBGetNext(RTS_HANDLE hPrevObject, RTS_RESULT *pResult);
        virtual RTS_HANDLE CDECL IUserObjectsDBOpen(char *pszObject, RTS_RESULT *pResult);
        virtual RTS_RESULT CDECL IUserObjectsDBClose(RTS_HANDLE hObject);
        virtual RTS_RESULT CDECL IUserObjectsDBGetName(RTS_HANDLE hObject, char *pszObject, int *piMaxLen);
        virtual RTS_RESULT CDECL IUserObjectsDBGetPath(RTS_HANDLE hObject, char *pszObject, int *piMaxLen);
        virtual RTS_HANDLE CDECL IUserObjectsDBGetFirstChild(RTS_HANDLE hFatherObject, RTS_RESULT *pResult);
        virtual RTS_HANDLE CDECL IUserObjectsDBGetNextChild(RTS_HANDLE hFatherObject, RTS_HANDLE hPrevChildObject, RTS_RESULT *pResult);
        virtual RTS_HANDLE CDECL IUserObjectsDBGetFather(RTS_HANDLE hChildObject, RTS_RESULT *pResult);
        virtual RTS_HANDLE CDECL IUserObjectsDBGetFirstGroup(RTS_HANDLE hObject, RTS_RESULT *pResult);
        virtual RTS_HANDLE CDECL IUserObjectsDBGetNextGroup(RTS_HANDLE hObject, RTS_HANDLE hPrevGroup, RTS_RESULT *pResult);
        virtual RTS_RESULT CDECL IUserObjectsDBGetGroupRights(RTS_HANDLE hObject, RTS_HANDLE hGroup, RTS_UI32 *pulRights, RTS_UI32 *pulDeniedRights);
        virtual RTS_RESULT CDECL IUserObjectsDBHasRights(char *pszObject, RTS_HANDLE hUser, RTS_UI32 ulRequestedRights);
        virtual RTS_RESULT CDECL IUserObjectsDBGetRights(char *pszObject, RTS_HANDLE hUser, RTS_UI32 *pulRights, RTS_UI32 *pulDeniedRights);
        virtual RTS_RESULT CDECL IUserObjectsDBActivate(void);
        virtual RTS_RESULT CDECL IUserGroupsDBConfigRelease(void);
        virtual RTS_RESULT CDECL IUserGroupsDBConfigImport(RTS_UI8 *pData, RTS_SIZE dataSize);
        virtual RTS_SIZE CDECL IUserGroupsDBConfigExport(RTS_UI8 *pData, RTS_SIZE maxSize, RTS_RESULT *pResult);
        virtual RTS_RESULT CDECL IUserGroupsDBConfigAdd(char *pszGroup);
        virtual RTS_RESULT CDECL IUserGroupsDBConfigRemove(char *pszGroup);
        virtual RTS_RESULT CDECL IUserGroupsDBConfigSetProperty(char *pszGroup, RTS_UI32 ulProperty);
        virtual RTS_RESULT CDECL IUserGroupsDBConfigAddUser(char *pszGroup, char *pszUser);
        virtual RTS_RESULT CDECL IUserGroupsDBConfigRemoveUser(char *pszGroup, char *pszUser);
        virtual RTS_RESULT CDECL IUserGroupsDBConfigAddMember(char *pszGroup, char *pszGroupToAdd);
        virtual RTS_RESULT CDECL IUserGroupsDBConfigRemoveMember(char *pszGroup, char *pszGroupToRemove);
        virtual RTS_HANDLE CDECL IUserGroupsDBGetGroup(char *pszGroupName, RTS_RESULT *pResult);
        virtual RTS_HANDLE CDECL IUserGroupsDBGetFirstGroup(RTS_RESULT *pResult);
        virtual RTS_HANDLE CDECL IUserGroupsDBGetNextGroup(RTS_HANDLE hPrevGroup, RTS_RESULT *pResult);
        virtual char* CDECL IUserGroupsDBGetName(RTS_HANDLE hGroup, RTS_RESULT *pResult);
        virtual RTS_UI32 CDECL IUserGroupsDBGetProperty(RTS_HANDLE hGroup, RTS_RESULT *pResult);
        virtual RTS_RESULT CDECL IUserGroupsDBGroupHasUser(RTS_HANDLE hGroup, char *pszUser);
        virtual RTS_RESULT CDECL IUserGroupsDBGroupHasMember(RTS_HANDLE hGroup, RTS_HANDLE hGroupMember);
        virtual char* CDECL IUserGroupsDBGetFirstUser(RTS_HANDLE hGroup, RTS_HANDLE *phIterator, RTS_RESULT *pResult);
        virtual char* CDECL IUserGroupsDBGetNextUser(RTS_HANDLE hGroup, RTS_HANDLE *phIterator, RTS_RESULT *pResult);
        virtual RTS_HANDLE CDECL IUserGroupsDBGetFirstGroupMember(RTS_HANDLE hGroup, RTS_RESULT *pResult);
        virtual RTS_HANDLE CDECL IUserGroupsDBGetNextGroupMember(RTS_HANDLE hGroup, RTS_HANDLE hPrevMember, RTS_RESULT *pResult);
        virtual RTS_RESULT CDECL IUserDBConfigRelease(void);
        virtual RTS_RESULT CDECL IUserDBConfigImport(RTS_UI8 *pData, RTS_SIZE dataSize);
        virtual RTS_SIZE CDECL IUserDBConfigExport(RTS_UI8 *pData, RTS_SIZE maxSize, RTS_RESULT *pResult);
        virtual RTS_RESULT CDECL IUserDBConfigAddUser(char *pszUser, UserMgrCredentials *pCredentials);
        virtual RTS_BOOL CDECL IUserDBConfigExistsUser(char *pszUser);
        virtual RTS_RESULT CDECL IUserDBConfigRemoveUser(char *pszUser);
        virtual RTS_RESULT CDECL IUserDBConfigSetUserCredentials(char *pszUser, UserMgrCredentials *pCredentials);
        virtual RTS_UI32 CDECL IUserDBConfigGetUserProperty(char *pszUser, RTS_RESULT *pResult);
        virtual RTS_RESULT CDECL IUserDBConfigSetUserProperty(char *pszUser, RTS_UI32 property);
        virtual RTS_RESULT CDECL IUserDBAuthenticate(char *pszUser, UserMgrCredentials *pCredentials, RTS_UI32 *pUserProperty);
        virtual char* CDECL IUserDBGetFirstUser(RTS_HANDLE *hIterator, RTS_UI32 *pUserProperty, RTS_RESULT *pResult);
        virtual char* CDECL IUserDBGetNextUser(RTS_HANDLE *hIterator, RTS_UI32 *pUserProperty, RTS_RESULT *pResult);

    public:
        RTS_HANDLE hCmpUserDBTemplate;
        int iRefCount;
};

#endif /*CPLUSPLUS*/
#ifdef RTS_COMPACT_MICRO
/* CmpUserDBTemplate Declarations for uRTS */
/* This header is included only to have the CMP_EXT_FUNCTION_REF type definition. */
/* In final version this type could be moved to CmpItf.h, if we will use */
/* the same structure for representing an export entry. */
#include <_OptionalIncludes/Profiles/uRTS/CMMicro.h>

/* Undefine these macros if they were previously defined */

#ifdef USE_HOOK_FUNCTION
#undef USE_HOOK_FUNCTION
#endif

#ifdef USE_CMEXPORTFUNCTIONS
#undef USE_CMEXPORTFUNCTIONS
#endif

#ifdef USE_EXPORT_EXTREF
#undef USE_EXPORT_EXTREF
#endif

#ifdef USE_EXPORT_CMPITF
#undef USE_EXPORT_CMPITF
#endif

#ifdef USE_ENTRY_LINKAGE
#undef USE_ENTRY_LINKAGE
#endif

#ifdef IMPLEMENT_EXPORT_FUNCTIONS
#undef IMPLEMENT_EXPORT_FUNCTIONS
#endif

#ifdef IMPLEMENT_IMPORT_FUNCTIONS
#undef IMPLEMENT_IMPORT_FUNCTIONS
#endif

#ifdef IMPLEMENT_GETVERSION_FUNCTIONS
#undef IMPLEMENT_GETVERSION_FUNCTIONS
#endif

#ifdef EXPORT_STMT
#undef EXPORT_STMT
#endif

#ifdef USEEXTERN_STMT
#undef USEEXTERN_STMT
#endif

#ifdef USE_STMT
#undef USE_STMT
#endif

#ifdef USEIMPORT_STMT
#undef USEIMPORT_STMT
#endif

/* This wrapper is only required in uRTS */
#define USE_HOOK_FUNCTION	RTS_RESULT CmpUserDBTemplate_HookFunction(RTS_UI32 ulHook, RTS_UINTPTR ulParam1, RTS_UINTPTR ulParam2)\
{\
	return HookFunction(ulHook, ulParam1, ulParam2);\
}

/******************************************************************************/
/* No s_pfCMExportFunctions in uRTS */
#define USE_CMEXPORTFUNCTIONS

/* Exports table to IEC */
#define USE_EXPORT_EXTREF const CMP_EXT_FUNCTION_REF CmpUserDBTemplate_ExternalsTable[] = \
	{\
		EXPORT_EXTREF_STMT\
		EXPORT_EXTREF2_STMT\
		{ ((RTS_VOID_FCTPTR)(void *)0), "", 0 }\
	};

/* No component interface exports in uRTS */
#define USE_EXPORT_CMPITF

/* No dynamic linkage in uRTS */
#define USE_ENTRY_LINKAGE

/* No ExportFunctions() routine in uRTS */
#define IMPLEMENT_EXPORT_FUNCTIONS

/* No ImportFunctions() routine in uRTS */
#define IMPLEMENT_IMPORT_FUNCTIONS

/* No CmpGetVersion() routine in uRTS */
#define IMPLEMENT_GETVERSION_FUNCTIONS

/* No usage of externals from the component secondary C-modules in uRTS */
#define USEEXTERN_STMT

/* No need for export calling to the Component Manager in uRTS */
#define EXPORT_STMT

/* No need for importing from secondary C-modules */
#define USEIMPORT_STMT

/* Instantiation macro for a root component C-module */
#define USE_STMT\
	static RTS_RESULT CDECL HookFunction(RTS_UI32 ulHook, RTS_UINTPTR ulParam1, RTS_UINTPTR ulParam2);\
		USE_EXPORT_EXTREF;\
		USE_EXPORT_CMPITF;\
		USE_HOOK_FUNCTION;\
		USE_CMEXPORTFUNCTIONS;\


/******************************************************************************/
#endif

#endif /*WIN32_RESOURCES*/
#endif /*_DEP_H_*/
