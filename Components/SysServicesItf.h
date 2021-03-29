 /**
 * <interfacename>SysServices</interfacename>
 * <description> 
 *	Interface to manage runtime services.
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */


	
	
#ifndef _SYSSERVICESITF_H_
#define _SYSSERVICESITF_H_

#include "CmpStd.h"

 

 




/**
 * <category>Service states</category>
 * <description>Service status definitions</description>
 */
#define SYSSERVICE_STATUS_UNKNOWN	0
#define SYSSERVICE_STATUS_STOP		1
#define SYSSERVICE_STATUS_RUN		2

#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description>Function to start the specified service</description>
 * <param name="puServiceName" type="IN">Name of the service</param>
 * <result>error code</result>
 */
RTS_RESULT CDECL SysServiceStart(RTS_UTF8STRING *puServiceName);
typedef RTS_RESULT (CDECL * PFSYSSERVICESTART) (RTS_UTF8STRING *puServiceName);
#if defined(SYSSERVICES_NOTIMPLEMENTED) || defined(SYSSERVICESTART_NOTIMPLEMENTED)
	#define USE_SysServiceStart
	#define EXT_SysServiceStart
	#define GET_SysServiceStart(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysServiceStart(p0)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_SysServiceStart  FALSE
	#define EXP_SysServiceStart  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysServiceStart
	#define EXT_SysServiceStart
	#define GET_SysServiceStart(fl)  CAL_CMGETAPI( "SysServiceStart" ) 
	#define CAL_SysServiceStart  SysServiceStart
	#define CHK_SysServiceStart  TRUE
	#define EXP_SysServiceStart  CAL_CMEXPAPI( "SysServiceStart" ) 
#elif defined(MIXED_LINK) && !defined(SYSSERVICES_EXTERNAL)
	#define USE_SysServiceStart
	#define EXT_SysServiceStart
	#define GET_SysServiceStart(fl)  CAL_CMGETAPI( "SysServiceStart" ) 
	#define CAL_SysServiceStart  SysServiceStart
	#define CHK_SysServiceStart  TRUE
	#define EXP_SysServiceStart  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysServiceStart", (RTS_UINTPTR)SysServiceStart, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysServicesSysServiceStart
	#define EXT_SysServicesSysServiceStart
	#define GET_SysServicesSysServiceStart  ERR_OK
	#define CAL_SysServicesSysServiceStart pISysServices->ISysServiceStart
	#define CHK_SysServicesSysServiceStart (pISysServices != NULL)
	#define EXP_SysServicesSysServiceStart  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysServiceStart
	#define EXT_SysServiceStart
	#define GET_SysServiceStart(fl)  CAL_CMGETAPI( "SysServiceStart" ) 
	#define CAL_SysServiceStart pISysServices->ISysServiceStart
	#define CHK_SysServiceStart (pISysServices != NULL)
	#define EXP_SysServiceStart  CAL_CMEXPAPI( "SysServiceStart" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysServiceStart  PFSYSSERVICESTART pfSysServiceStart;
	#define EXT_SysServiceStart  extern PFSYSSERVICESTART pfSysServiceStart;
	#define GET_SysServiceStart(fl)  s_pfCMGetAPI2( "SysServiceStart", (RTS_VOID_FCTPTR *)&pfSysServiceStart, (fl), 0, 0)
	#define CAL_SysServiceStart  pfSysServiceStart
	#define CHK_SysServiceStart  (pfSysServiceStart != NULL)
	#define EXP_SysServiceStart  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysServiceStart", (RTS_UINTPTR)SysServiceStart, 0, 0) 
#endif




/**
 * <description>Function to stop the specified service</description>
 * <param name="puServiceName" type="IN">Name of the service</param>
 * <result>error code</result>
 */
RTS_RESULT CDECL SysServiceStop(RTS_UTF8STRING *puServiceName);
typedef RTS_RESULT (CDECL * PFSYSSERVICESTOP) (RTS_UTF8STRING *puServiceName);
#if defined(SYSSERVICES_NOTIMPLEMENTED) || defined(SYSSERVICESTOP_NOTIMPLEMENTED)
	#define USE_SysServiceStop
	#define EXT_SysServiceStop
	#define GET_SysServiceStop(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysServiceStop(p0)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_SysServiceStop  FALSE
	#define EXP_SysServiceStop  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysServiceStop
	#define EXT_SysServiceStop
	#define GET_SysServiceStop(fl)  CAL_CMGETAPI( "SysServiceStop" ) 
	#define CAL_SysServiceStop  SysServiceStop
	#define CHK_SysServiceStop  TRUE
	#define EXP_SysServiceStop  CAL_CMEXPAPI( "SysServiceStop" ) 
#elif defined(MIXED_LINK) && !defined(SYSSERVICES_EXTERNAL)
	#define USE_SysServiceStop
	#define EXT_SysServiceStop
	#define GET_SysServiceStop(fl)  CAL_CMGETAPI( "SysServiceStop" ) 
	#define CAL_SysServiceStop  SysServiceStop
	#define CHK_SysServiceStop  TRUE
	#define EXP_SysServiceStop  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysServiceStop", (RTS_UINTPTR)SysServiceStop, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysServicesSysServiceStop
	#define EXT_SysServicesSysServiceStop
	#define GET_SysServicesSysServiceStop  ERR_OK
	#define CAL_SysServicesSysServiceStop pISysServices->ISysServiceStop
	#define CHK_SysServicesSysServiceStop (pISysServices != NULL)
	#define EXP_SysServicesSysServiceStop  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysServiceStop
	#define EXT_SysServiceStop
	#define GET_SysServiceStop(fl)  CAL_CMGETAPI( "SysServiceStop" ) 
	#define CAL_SysServiceStop pISysServices->ISysServiceStop
	#define CHK_SysServiceStop (pISysServices != NULL)
	#define EXP_SysServiceStop  CAL_CMEXPAPI( "SysServiceStop" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysServiceStop  PFSYSSERVICESTOP pfSysServiceStop;
	#define EXT_SysServiceStop  extern PFSYSSERVICESTOP pfSysServiceStop;
	#define GET_SysServiceStop(fl)  s_pfCMGetAPI2( "SysServiceStop", (RTS_VOID_FCTPTR *)&pfSysServiceStop, (fl), 0, 0)
	#define CAL_SysServiceStop  pfSysServiceStop
	#define CHK_SysServiceStop  (pfSysServiceStop != NULL)
	#define EXP_SysServiceStop  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysServiceStop", (RTS_UINTPTR)SysServiceStop, 0, 0) 
#endif




/**
 * <description>Function to get the current status of the specified service</description>
 * <param name="puServiceName" type="IN">Name of the service</param>
 * <param name="pStatus" type="OUT">Pointer to get the service status. See "Service states" for details.</param>
 * <result>error code</result>
 */
RTS_RESULT CDECL SysServiceGetStatus(RTS_UTF8STRING *puServiceName, RTS_UI32 *pStatus);
typedef RTS_RESULT (CDECL * PFSYSSERVICEGETSTATUS) (RTS_UTF8STRING *puServiceName, RTS_UI32 *pStatus);
#if defined(SYSSERVICES_NOTIMPLEMENTED) || defined(SYSSERVICEGETSTATUS_NOTIMPLEMENTED)
	#define USE_SysServiceGetStatus
	#define EXT_SysServiceGetStatus
	#define GET_SysServiceGetStatus(fl)  ERR_NOTIMPLEMENTED
	#define CAL_SysServiceGetStatus(p0,p1)  (RTS_RESULT)ERR_NOTIMPLEMENTED
	#define CHK_SysServiceGetStatus  FALSE
	#define EXP_SysServiceGetStatus  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_SysServiceGetStatus
	#define EXT_SysServiceGetStatus
	#define GET_SysServiceGetStatus(fl)  CAL_CMGETAPI( "SysServiceGetStatus" ) 
	#define CAL_SysServiceGetStatus  SysServiceGetStatus
	#define CHK_SysServiceGetStatus  TRUE
	#define EXP_SysServiceGetStatus  CAL_CMEXPAPI( "SysServiceGetStatus" ) 
#elif defined(MIXED_LINK) && !defined(SYSSERVICES_EXTERNAL)
	#define USE_SysServiceGetStatus
	#define EXT_SysServiceGetStatus
	#define GET_SysServiceGetStatus(fl)  CAL_CMGETAPI( "SysServiceGetStatus" ) 
	#define CAL_SysServiceGetStatus  SysServiceGetStatus
	#define CHK_SysServiceGetStatus  TRUE
	#define EXP_SysServiceGetStatus  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysServiceGetStatus", (RTS_UINTPTR)SysServiceGetStatus, 0, 0) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_SysServicesSysServiceGetStatus
	#define EXT_SysServicesSysServiceGetStatus
	#define GET_SysServicesSysServiceGetStatus  ERR_OK
	#define CAL_SysServicesSysServiceGetStatus pISysServices->ISysServiceGetStatus
	#define CHK_SysServicesSysServiceGetStatus (pISysServices != NULL)
	#define EXP_SysServicesSysServiceGetStatus  ERR_OK
#elif defined(CPLUSPLUS)
	#define USE_SysServiceGetStatus
	#define EXT_SysServiceGetStatus
	#define GET_SysServiceGetStatus(fl)  CAL_CMGETAPI( "SysServiceGetStatus" ) 
	#define CAL_SysServiceGetStatus pISysServices->ISysServiceGetStatus
	#define CHK_SysServiceGetStatus (pISysServices != NULL)
	#define EXP_SysServiceGetStatus  CAL_CMEXPAPI( "SysServiceGetStatus" ) 
#else /* DYNAMIC_LINK */
	#define USE_SysServiceGetStatus  PFSYSSERVICEGETSTATUS pfSysServiceGetStatus;
	#define EXT_SysServiceGetStatus  extern PFSYSSERVICEGETSTATUS pfSysServiceGetStatus;
	#define GET_SysServiceGetStatus(fl)  s_pfCMGetAPI2( "SysServiceGetStatus", (RTS_VOID_FCTPTR *)&pfSysServiceGetStatus, (fl), 0, 0)
	#define CAL_SysServiceGetStatus  pfSysServiceGetStatus
	#define CHK_SysServiceGetStatus  (pfSysServiceGetStatus != NULL)
	#define EXP_SysServiceGetStatus  s_pfCMRegisterAPI( (const CMP_EXT_FUNCTION_REF*)"SysServiceGetStatus", (RTS_UINTPTR)SysServiceGetStatus, 0, 0) 
#endif




#ifdef __cplusplus
}
#endif



typedef struct
{
	IBase_C *pBase;
	PFSYSSERVICESTART ISysServiceStart;
 	PFSYSSERVICESTOP ISysServiceStop;
 	PFSYSSERVICEGETSTATUS ISysServiceGetStatus;
 } ISysServices_C;

#ifdef CPLUSPLUS
class ISysServices : public IBase
{
	public:
		virtual RTS_RESULT CDECL ISysServiceStart(RTS_UTF8STRING *puServiceName) =0;
		virtual RTS_RESULT CDECL ISysServiceStop(RTS_UTF8STRING *puServiceName) =0;
		virtual RTS_RESULT CDECL ISysServiceGetStatus(RTS_UTF8STRING *puServiceName, RTS_UI32 *pStatus) =0;
};
	#ifndef ITF_SysServices
		#define ITF_SysServices static ISysServices *pISysServices = NULL;
	#endif
	#define EXTITF_SysServices
#else	/*CPLUSPLUS*/
	typedef ISysServices_C		ISysServices;
	#ifndef ITF_SysServices
		#define ITF_SysServices
	#endif
	#define EXTITF_SysServices
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_SYSSERVICESITF_H_*/
