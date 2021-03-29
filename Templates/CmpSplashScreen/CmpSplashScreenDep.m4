SET_COMPONENT_NAME(`CmpSplashScreen')
COMPONENT_SOURCES(`CmpSplashScreen.c')

COMPONENT_VERSION(`0x03050F00')

/* NOTE: REPLACE 0x0001 BY YOUR VENDORID */
COMPONENT_VENDORID(`0x0001')

#define CMPID_CmpSplashScreen       0x9000
#define CLASSID_CCmpSplashScreen    ADDVENDORID(CMP_VENDORID, CMPID_CmpSplashScreen)
#define ITFID_ICmpSplashScreen      ADDVENDORID(CMP_VENDORID, CMPID_CmpSplashScreen)

CATEGORY(`Templates')

USE_ITF(`CMUtilsItf.m4')
USE_ITF(`CmpAppItf.m4')
USE_ITF(`CmpEventMgrItf.m4')
USE_ITF(`SysTargetItf.m4')

IMPLEMENT_ITF(`CmpSplashScreenItf.m4')

REQUIRED_IMPORTS(
CMUtlVersionToString,
CMUtlWToUtf8,
EventOpen,
EventClose,
EventRegisterCallbackFunction,
EventUnregisterCallbackFunction,
SysTargetGetNodeName,
SysTargetGetVersion)
