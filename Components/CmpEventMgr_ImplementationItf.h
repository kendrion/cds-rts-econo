 /**
 * <interfacename>CmpEventMgr_Implementation</interfacename>
 * <description></description>
 *
 * <copyright></copyright>
 */


	
	
#ifndef _CMPEVENTMGR_IMPLEMENTATIONITF_H_
#define _CMPEVENTMGR_IMPLEMENTATIONITF_H_

#include "CmpStd.h"

 

 




/** EXTERN LIB SECTION BEGIN **/
/*  Comments are ignored for m4 compiler so restructured text can be used.  */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Close an event specified by handle 
 */
typedef struct tageventclose_struct
{
	RTS_IEC_HANDLE hEvent;				/* VAR_INPUT */	/* Event handle */
	RTS_IEC_RESULT EventClose;			/* VAR_OUTPUT */	/* Error code */
} eventclose_struct;

void CDECL CDECL_EXT eventclose(eventclose_struct *p);
typedef void (CDECL CDECL_EXT* PFEVENTCLOSE_IEC) (eventclose_struct *p);
#if defined(CMPEVENTMGR_IMPLEMENTATION_NOTIMPLEMENTED) || defined(EVENTCLOSE_NOTIMPLEMENTED)
	#define USE_eventclose
	#define EXT_eventclose
	#define GET_eventclose(fl)  ERR_NOTIMPLEMENTED
	#define CAL_eventclose(p0) 
	#define CHK_eventclose  FALSE
	#define EXP_eventclose  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_eventclose
	#define EXT_eventclose
	#define GET_eventclose(fl)  CAL_CMGETAPI( "eventclose" ) 
	#define CAL_eventclose  eventclose
	#define CHK_eventclose  TRUE
	#define EXP_eventclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventclose", (RTS_UINTPTR)eventclose, 1, RTSITF_GET_SIGNATURE(0, 0x4668EEC1), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPEVENTMGR_IMPLEMENTATION_EXTERNAL)
	#define USE_eventclose
	#define EXT_eventclose
	#define GET_eventclose(fl)  CAL_CMGETAPI( "eventclose" ) 
	#define CAL_eventclose  eventclose
	#define CHK_eventclose  TRUE
	#define EXP_eventclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventclose", (RTS_UINTPTR)eventclose, 1, RTSITF_GET_SIGNATURE(0, 0x4668EEC1), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpEventMgr_Implementationeventclose
	#define EXT_CmpEventMgr_Implementationeventclose
	#define GET_CmpEventMgr_Implementationeventclose  ERR_OK
	#define CAL_CmpEventMgr_Implementationeventclose  eventclose
	#define CHK_CmpEventMgr_Implementationeventclose  TRUE
	#define EXP_CmpEventMgr_Implementationeventclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventclose", (RTS_UINTPTR)eventclose, 1, RTSITF_GET_SIGNATURE(0, 0x4668EEC1), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_eventclose
	#define EXT_eventclose
	#define GET_eventclose(fl)  CAL_CMGETAPI( "eventclose" ) 
	#define CAL_eventclose  eventclose
	#define CHK_eventclose  TRUE
	#define EXP_eventclose  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventclose", (RTS_UINTPTR)eventclose, 1, RTSITF_GET_SIGNATURE(0, 0x4668EEC1), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_eventclose  PFEVENTCLOSE_IEC pfeventclose;
	#define EXT_eventclose  extern PFEVENTCLOSE_IEC pfeventclose;
	#define GET_eventclose(fl)  s_pfCMGetAPI2( "eventclose", (RTS_VOID_FCTPTR *)&pfeventclose, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x4668EEC1), 0x03051000)
	#define CAL_eventclose  pfeventclose
	#define CHK_eventclose  (pfeventclose != NULL)
	#define EXP_eventclose   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventclose", (RTS_UINTPTR)eventclose, 1, RTSITF_GET_SIGNATURE(0, 0x4668EEC1), 0x03051000) 
#endif


/**
 * Creates a new event object. If event still exists, a handle to this object will be returned.
 *   An IEC event is typically created by the provider in FB_Init of a function block 
 */
typedef struct tageventcreate_struct
{
	RTS_IEC_UDINT EventId;				/* VAR_INPUT */	/* Event ID of the event. Contains the class and the event */
	RTS_IEC_UDINT CmpIdProvider;		/* VAR_INPUT */	/* Component ID of the provider */
	RTS_IEC_RESULT *Result;	/* VAR_IN_OUT */	/* Error code */
	RTS_IEC_HANDLE EventCreate;			/* VAR_OUTPUT */	/* Handle to created event */
} eventcreate_struct;

void CDECL CDECL_EXT eventcreate(eventcreate_struct *p);
typedef void (CDECL CDECL_EXT* PFEVENTCREATE_IEC) (eventcreate_struct *p);
#if defined(CMPEVENTMGR_IMPLEMENTATION_NOTIMPLEMENTED) || defined(EVENTCREATE_NOTIMPLEMENTED)
	#define USE_eventcreate
	#define EXT_eventcreate
	#define GET_eventcreate(fl)  ERR_NOTIMPLEMENTED
	#define CAL_eventcreate(p0) 
	#define CHK_eventcreate  FALSE
	#define EXP_eventcreate  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_eventcreate
	#define EXT_eventcreate
	#define GET_eventcreate(fl)  CAL_CMGETAPI( "eventcreate" ) 
	#define CAL_eventcreate  eventcreate
	#define CHK_eventcreate  TRUE
	#define EXP_eventcreate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventcreate", (RTS_UINTPTR)eventcreate, 1, RTSITF_GET_SIGNATURE(0, 0xAC9E014A), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPEVENTMGR_IMPLEMENTATION_EXTERNAL)
	#define USE_eventcreate
	#define EXT_eventcreate
	#define GET_eventcreate(fl)  CAL_CMGETAPI( "eventcreate" ) 
	#define CAL_eventcreate  eventcreate
	#define CHK_eventcreate  TRUE
	#define EXP_eventcreate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventcreate", (RTS_UINTPTR)eventcreate, 1, RTSITF_GET_SIGNATURE(0, 0xAC9E014A), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpEventMgr_Implementationeventcreate
	#define EXT_CmpEventMgr_Implementationeventcreate
	#define GET_CmpEventMgr_Implementationeventcreate  ERR_OK
	#define CAL_CmpEventMgr_Implementationeventcreate  eventcreate
	#define CHK_CmpEventMgr_Implementationeventcreate  TRUE
	#define EXP_CmpEventMgr_Implementationeventcreate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventcreate", (RTS_UINTPTR)eventcreate, 1, RTSITF_GET_SIGNATURE(0, 0xAC9E014A), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_eventcreate
	#define EXT_eventcreate
	#define GET_eventcreate(fl)  CAL_CMGETAPI( "eventcreate" ) 
	#define CAL_eventcreate  eventcreate
	#define CHK_eventcreate  TRUE
	#define EXP_eventcreate  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventcreate", (RTS_UINTPTR)eventcreate, 1, RTSITF_GET_SIGNATURE(0, 0xAC9E014A), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_eventcreate  PFEVENTCREATE_IEC pfeventcreate;
	#define EXT_eventcreate  extern PFEVENTCREATE_IEC pfeventcreate;
	#define GET_eventcreate(fl)  s_pfCMGetAPI2( "eventcreate", (RTS_VOID_FCTPTR *)&pfeventcreate, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xAC9E014A), 0x03051000)
	#define CAL_eventcreate  pfeventcreate
	#define CHK_eventcreate  (pfeventcreate != NULL)
	#define EXP_eventcreate   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventcreate", (RTS_UINTPTR)eventcreate, 1, RTSITF_GET_SIGNATURE(0, 0xAC9E014A), 0x03051000) 
#endif


/**
 * Creates a new event object. If event still exists, a handle to this object will be returned.
 *   An IEC event is typically created by the provider in FB_Init of a function block 
 */
typedef struct tageventcreate2_struct
{
	RTS_IEC_UDINT EventId;				/* VAR_INPUT */	/* Event ID of the event. Contains the class and the event */
	RTS_IEC_UDINT CmpIdProvider;		/* VAR_INPUT */	/* Component ID of the provider */
	RTS_IEC_UDINT nCallbacksPossible;	/* VAR_INPUT */	/* Maximum number of callbacks possible on this event or EVENT_CALLBACKS_NO_LIMIT for no limit */
	RTS_IEC_RESULT *Result;	/* VAR_IN_OUT */	/* Error code */
	RTS_IEC_HANDLE EventCreate2;		/* VAR_OUTPUT */	/* Handle to created event */
} eventcreate2_struct;

void CDECL CDECL_EXT eventcreate2(eventcreate2_struct *p);
typedef void (CDECL CDECL_EXT* PFEVENTCREATE2_IEC) (eventcreate2_struct *p);
#if defined(CMPEVENTMGR_IMPLEMENTATION_NOTIMPLEMENTED) || defined(EVENTCREATE2_NOTIMPLEMENTED)
	#define USE_eventcreate2
	#define EXT_eventcreate2
	#define GET_eventcreate2(fl)  ERR_NOTIMPLEMENTED
	#define CAL_eventcreate2(p0) 
	#define CHK_eventcreate2  FALSE
	#define EXP_eventcreate2  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_eventcreate2
	#define EXT_eventcreate2
	#define GET_eventcreate2(fl)  CAL_CMGETAPI( "eventcreate2" ) 
	#define CAL_eventcreate2  eventcreate2
	#define CHK_eventcreate2  TRUE
	#define EXP_eventcreate2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventcreate2", (RTS_UINTPTR)eventcreate2, 1, RTSITF_GET_SIGNATURE(0, 0xD6BF4CE8), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPEVENTMGR_IMPLEMENTATION_EXTERNAL)
	#define USE_eventcreate2
	#define EXT_eventcreate2
	#define GET_eventcreate2(fl)  CAL_CMGETAPI( "eventcreate2" ) 
	#define CAL_eventcreate2  eventcreate2
	#define CHK_eventcreate2  TRUE
	#define EXP_eventcreate2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventcreate2", (RTS_UINTPTR)eventcreate2, 1, RTSITF_GET_SIGNATURE(0, 0xD6BF4CE8), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpEventMgr_Implementationeventcreate2
	#define EXT_CmpEventMgr_Implementationeventcreate2
	#define GET_CmpEventMgr_Implementationeventcreate2  ERR_OK
	#define CAL_CmpEventMgr_Implementationeventcreate2  eventcreate2
	#define CHK_CmpEventMgr_Implementationeventcreate2  TRUE
	#define EXP_CmpEventMgr_Implementationeventcreate2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventcreate2", (RTS_UINTPTR)eventcreate2, 1, RTSITF_GET_SIGNATURE(0, 0xD6BF4CE8), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_eventcreate2
	#define EXT_eventcreate2
	#define GET_eventcreate2(fl)  CAL_CMGETAPI( "eventcreate2" ) 
	#define CAL_eventcreate2  eventcreate2
	#define CHK_eventcreate2  TRUE
	#define EXP_eventcreate2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventcreate2", (RTS_UINTPTR)eventcreate2, 1, RTSITF_GET_SIGNATURE(0, 0xD6BF4CE8), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_eventcreate2  PFEVENTCREATE2_IEC pfeventcreate2;
	#define EXT_eventcreate2  extern PFEVENTCREATE2_IEC pfeventcreate2;
	#define GET_eventcreate2(fl)  s_pfCMGetAPI2( "eventcreate2", (RTS_VOID_FCTPTR *)&pfeventcreate2, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xD6BF4CE8), 0x03051000)
	#define CAL_eventcreate2  pfeventcreate2
	#define CHK_eventcreate2  (pfeventcreate2 != NULL)
	#define EXP_eventcreate2   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventcreate2", (RTS_UINTPTR)eventcreate2, 1, RTSITF_GET_SIGNATURE(0, 0xD6BF4CE8), 0x03051000) 
#endif


/**
 * Deletes an event specified by handle. 
 */
typedef struct tageventdelete_struct
{
	RTS_IEC_HANDLE hEvent;				/* VAR_INPUT */	/* Event handle */
	RTS_IEC_RESULT EventDelete;			/* VAR_OUTPUT */	/* Error code */
} eventdelete_struct;

void CDECL CDECL_EXT eventdelete(eventdelete_struct *p);
typedef void (CDECL CDECL_EXT* PFEVENTDELETE_IEC) (eventdelete_struct *p);
#if defined(CMPEVENTMGR_IMPLEMENTATION_NOTIMPLEMENTED) || defined(EVENTDELETE_NOTIMPLEMENTED)
	#define USE_eventdelete
	#define EXT_eventdelete
	#define GET_eventdelete(fl)  ERR_NOTIMPLEMENTED
	#define CAL_eventdelete(p0) 
	#define CHK_eventdelete  FALSE
	#define EXP_eventdelete  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_eventdelete
	#define EXT_eventdelete
	#define GET_eventdelete(fl)  CAL_CMGETAPI( "eventdelete" ) 
	#define CAL_eventdelete  eventdelete
	#define CHK_eventdelete  TRUE
	#define EXP_eventdelete  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventdelete", (RTS_UINTPTR)eventdelete, 1, RTSITF_GET_SIGNATURE(0, 0x0794C5F5), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPEVENTMGR_IMPLEMENTATION_EXTERNAL)
	#define USE_eventdelete
	#define EXT_eventdelete
	#define GET_eventdelete(fl)  CAL_CMGETAPI( "eventdelete" ) 
	#define CAL_eventdelete  eventdelete
	#define CHK_eventdelete  TRUE
	#define EXP_eventdelete  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventdelete", (RTS_UINTPTR)eventdelete, 1, RTSITF_GET_SIGNATURE(0, 0x0794C5F5), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpEventMgr_Implementationeventdelete
	#define EXT_CmpEventMgr_Implementationeventdelete
	#define GET_CmpEventMgr_Implementationeventdelete  ERR_OK
	#define CAL_CmpEventMgr_Implementationeventdelete  eventdelete
	#define CHK_CmpEventMgr_Implementationeventdelete  TRUE
	#define EXP_CmpEventMgr_Implementationeventdelete  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventdelete", (RTS_UINTPTR)eventdelete, 1, RTSITF_GET_SIGNATURE(0, 0x0794C5F5), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_eventdelete
	#define EXT_eventdelete
	#define GET_eventdelete(fl)  CAL_CMGETAPI( "eventdelete" ) 
	#define CAL_eventdelete  eventdelete
	#define CHK_eventdelete  TRUE
	#define EXP_eventdelete  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventdelete", (RTS_UINTPTR)eventdelete, 1, RTSITF_GET_SIGNATURE(0, 0x0794C5F5), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_eventdelete  PFEVENTDELETE_IEC pfeventdelete;
	#define EXT_eventdelete  extern PFEVENTDELETE_IEC pfeventdelete;
	#define GET_eventdelete(fl)  s_pfCMGetAPI2( "eventdelete", (RTS_VOID_FCTPTR *)&pfeventdelete, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x0794C5F5), 0x03051000)
	#define CAL_eventdelete  pfeventdelete
	#define CHK_eventdelete  (pfeventdelete != NULL)
	#define EXP_eventdelete   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventdelete", (RTS_UINTPTR)eventdelete, 1, RTSITF_GET_SIGNATURE(0, 0x0794C5F5), 0x03051000) 
#endif


/**
 * Extract the event class from eventid. Return value is the event class 
 */
typedef struct tageventgetclass_struct
{
	RTS_IEC_UDINT EventId;				/* VAR_INPUT */	/* Event id */
	RTS_IEC_UINT EventGetClass;			/* VAR_OUTPUT */	/* Class of the event. See EventClass for details */
} eventgetclass_struct;

void CDECL CDECL_EXT eventgetclass(eventgetclass_struct *p);
typedef void (CDECL CDECL_EXT* PFEVENTGETCLASS_IEC) (eventgetclass_struct *p);
#if defined(CMPEVENTMGR_IMPLEMENTATION_NOTIMPLEMENTED) || defined(EVENTGETCLASS_NOTIMPLEMENTED)
	#define USE_eventgetclass
	#define EXT_eventgetclass
	#define GET_eventgetclass(fl)  ERR_NOTIMPLEMENTED
	#define CAL_eventgetclass(p0) 
	#define CHK_eventgetclass  FALSE
	#define EXP_eventgetclass  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_eventgetclass
	#define EXT_eventgetclass
	#define GET_eventgetclass(fl)  CAL_CMGETAPI( "eventgetclass" ) 
	#define CAL_eventgetclass  eventgetclass
	#define CHK_eventgetclass  TRUE
	#define EXP_eventgetclass  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventgetclass", (RTS_UINTPTR)eventgetclass, 1, RTSITF_GET_SIGNATURE(0, 0xB0745754), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPEVENTMGR_IMPLEMENTATION_EXTERNAL)
	#define USE_eventgetclass
	#define EXT_eventgetclass
	#define GET_eventgetclass(fl)  CAL_CMGETAPI( "eventgetclass" ) 
	#define CAL_eventgetclass  eventgetclass
	#define CHK_eventgetclass  TRUE
	#define EXP_eventgetclass  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventgetclass", (RTS_UINTPTR)eventgetclass, 1, RTSITF_GET_SIGNATURE(0, 0xB0745754), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpEventMgr_Implementationeventgetclass
	#define EXT_CmpEventMgr_Implementationeventgetclass
	#define GET_CmpEventMgr_Implementationeventgetclass  ERR_OK
	#define CAL_CmpEventMgr_Implementationeventgetclass  eventgetclass
	#define CHK_CmpEventMgr_Implementationeventgetclass  TRUE
	#define EXP_CmpEventMgr_Implementationeventgetclass  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventgetclass", (RTS_UINTPTR)eventgetclass, 1, RTSITF_GET_SIGNATURE(0, 0xB0745754), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_eventgetclass
	#define EXT_eventgetclass
	#define GET_eventgetclass(fl)  CAL_CMGETAPI( "eventgetclass" ) 
	#define CAL_eventgetclass  eventgetclass
	#define CHK_eventgetclass  TRUE
	#define EXP_eventgetclass  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventgetclass", (RTS_UINTPTR)eventgetclass, 1, RTSITF_GET_SIGNATURE(0, 0xB0745754), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_eventgetclass  PFEVENTGETCLASS_IEC pfeventgetclass;
	#define EXT_eventgetclass  extern PFEVENTGETCLASS_IEC pfeventgetclass;
	#define GET_eventgetclass(fl)  s_pfCMGetAPI2( "eventgetclass", (RTS_VOID_FCTPTR *)&pfeventgetclass, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xB0745754), 0x03051000)
	#define CAL_eventgetclass  pfeventgetclass
	#define CHK_eventgetclass  (pfeventgetclass != NULL)
	#define EXP_eventgetclass   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventgetclass", (RTS_UINTPTR)eventgetclass, 1, RTSITF_GET_SIGNATURE(0, 0xB0745754), 0x03051000) 
#endif


/**
 * Extract the event from eventid. Return value ist the event 
 */
typedef struct tageventgetevent_struct
{
	RTS_IEC_UDINT EventId;				/* VAR_INPUT */	/* Event ID */
	RTS_IEC_UINT EventGetEvent;			/* VAR_OUTPUT */	/* Extracted event from the eventid */
} eventgetevent_struct;

void CDECL CDECL_EXT eventgetevent(eventgetevent_struct *p);
typedef void (CDECL CDECL_EXT* PFEVENTGETEVENT_IEC) (eventgetevent_struct *p);
#if defined(CMPEVENTMGR_IMPLEMENTATION_NOTIMPLEMENTED) || defined(EVENTGETEVENT_NOTIMPLEMENTED)
	#define USE_eventgetevent
	#define EXT_eventgetevent
	#define GET_eventgetevent(fl)  ERR_NOTIMPLEMENTED
	#define CAL_eventgetevent(p0) 
	#define CHK_eventgetevent  FALSE
	#define EXP_eventgetevent  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_eventgetevent
	#define EXT_eventgetevent
	#define GET_eventgetevent(fl)  CAL_CMGETAPI( "eventgetevent" ) 
	#define CAL_eventgetevent  eventgetevent
	#define CHK_eventgetevent  TRUE
	#define EXP_eventgetevent  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventgetevent", (RTS_UINTPTR)eventgetevent, 1, RTSITF_GET_SIGNATURE(0, 0x0E7E3D61), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPEVENTMGR_IMPLEMENTATION_EXTERNAL)
	#define USE_eventgetevent
	#define EXT_eventgetevent
	#define GET_eventgetevent(fl)  CAL_CMGETAPI( "eventgetevent" ) 
	#define CAL_eventgetevent  eventgetevent
	#define CHK_eventgetevent  TRUE
	#define EXP_eventgetevent  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventgetevent", (RTS_UINTPTR)eventgetevent, 1, RTSITF_GET_SIGNATURE(0, 0x0E7E3D61), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpEventMgr_Implementationeventgetevent
	#define EXT_CmpEventMgr_Implementationeventgetevent
	#define GET_CmpEventMgr_Implementationeventgetevent  ERR_OK
	#define CAL_CmpEventMgr_Implementationeventgetevent  eventgetevent
	#define CHK_CmpEventMgr_Implementationeventgetevent  TRUE
	#define EXP_CmpEventMgr_Implementationeventgetevent  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventgetevent", (RTS_UINTPTR)eventgetevent, 1, RTSITF_GET_SIGNATURE(0, 0x0E7E3D61), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_eventgetevent
	#define EXT_eventgetevent
	#define GET_eventgetevent(fl)  CAL_CMGETAPI( "eventgetevent" ) 
	#define CAL_eventgetevent  eventgetevent
	#define CHK_eventgetevent  TRUE
	#define EXP_eventgetevent  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventgetevent", (RTS_UINTPTR)eventgetevent, 1, RTSITF_GET_SIGNATURE(0, 0x0E7E3D61), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_eventgetevent  PFEVENTGETEVENT_IEC pfeventgetevent;
	#define EXT_eventgetevent  extern PFEVENTGETEVENT_IEC pfeventgetevent;
	#define GET_eventgetevent(fl)  s_pfCMGetAPI2( "eventgetevent", (RTS_VOID_FCTPTR *)&pfeventgetevent, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x0E7E3D61), 0x03051000)
	#define CAL_eventgetevent  pfeventgetevent
	#define CHK_eventgetevent  (pfeventgetevent != NULL)
	#define EXP_eventgetevent   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventgetevent", (RTS_UINTPTR)eventgetevent, 1, RTSITF_GET_SIGNATURE(0, 0x0E7E3D61), 0x03051000) 
#endif


/**
 * Opens an existing event object. Can be used to check, if the event was created by the provider.
 *   If the event does not exist, an error code is returned. 
 */
typedef struct tageventopen_struct
{
	RTS_IEC_UDINT EventId;				/* VAR_INPUT */	/* EventID of the event. Contains the class and the event */
	RTS_IEC_UDINT CmpIdProvider;		/* VAR_INPUT */	/* Component ID of the provider */
	RTS_IEC_RESULT *Result;	/* VAR_IN_OUT */	/* Error code */
	RTS_IEC_HANDLE EventOpen;			/* VAR_OUTPUT */	/* Handle to opened event */
} eventopen_struct;

void CDECL CDECL_EXT eventopen(eventopen_struct *p);
typedef void (CDECL CDECL_EXT* PFEVENTOPEN_IEC) (eventopen_struct *p);
#if defined(CMPEVENTMGR_IMPLEMENTATION_NOTIMPLEMENTED) || defined(EVENTOPEN_NOTIMPLEMENTED)
	#define USE_eventopen
	#define EXT_eventopen
	#define GET_eventopen(fl)  ERR_NOTIMPLEMENTED
	#define CAL_eventopen(p0) 
	#define CHK_eventopen  FALSE
	#define EXP_eventopen  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_eventopen
	#define EXT_eventopen
	#define GET_eventopen(fl)  CAL_CMGETAPI( "eventopen" ) 
	#define CAL_eventopen  eventopen
	#define CHK_eventopen  TRUE
	#define EXP_eventopen  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventopen", (RTS_UINTPTR)eventopen, 1, RTSITF_GET_SIGNATURE(0, 0xBC5AE4E1), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPEVENTMGR_IMPLEMENTATION_EXTERNAL)
	#define USE_eventopen
	#define EXT_eventopen
	#define GET_eventopen(fl)  CAL_CMGETAPI( "eventopen" ) 
	#define CAL_eventopen  eventopen
	#define CHK_eventopen  TRUE
	#define EXP_eventopen  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventopen", (RTS_UINTPTR)eventopen, 1, RTSITF_GET_SIGNATURE(0, 0xBC5AE4E1), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpEventMgr_Implementationeventopen
	#define EXT_CmpEventMgr_Implementationeventopen
	#define GET_CmpEventMgr_Implementationeventopen  ERR_OK
	#define CAL_CmpEventMgr_Implementationeventopen  eventopen
	#define CHK_CmpEventMgr_Implementationeventopen  TRUE
	#define EXP_CmpEventMgr_Implementationeventopen  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventopen", (RTS_UINTPTR)eventopen, 1, RTSITF_GET_SIGNATURE(0, 0xBC5AE4E1), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_eventopen
	#define EXT_eventopen
	#define GET_eventopen(fl)  CAL_CMGETAPI( "eventopen" ) 
	#define CAL_eventopen  eventopen
	#define CHK_eventopen  TRUE
	#define EXP_eventopen  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventopen", (RTS_UINTPTR)eventopen, 1, RTSITF_GET_SIGNATURE(0, 0xBC5AE4E1), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_eventopen  PFEVENTOPEN_IEC pfeventopen;
	#define EXT_eventopen  extern PFEVENTOPEN_IEC pfeventopen;
	#define GET_eventopen(fl)  s_pfCMGetAPI2( "eventopen", (RTS_VOID_FCTPTR *)&pfeventopen, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xBC5AE4E1), 0x03051000)
	#define CAL_eventopen  pfeventopen
	#define CHK_eventopen  (pfeventopen != NULL)
	#define EXP_eventopen   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventopen", (RTS_UINTPTR)eventopen, 1, RTSITF_GET_SIGNATURE(0, 0xBC5AE4E1), 0x03051000) 
#endif


/**
 * Post or sent an event 
 */
typedef struct tageventpost_struct
{
	RTS_IEC_HANDLE hEvent;				/* VAR_INPUT */	/* Event handle */
	EventParam *pEventParam;			/* VAR_INPUT */	/* Pointer to the event parameters */
	RTS_IEC_RESULT EventPost;			/* VAR_OUTPUT */	/* Error code */
} eventpost_struct;

void CDECL CDECL_EXT eventpost(eventpost_struct *p);
typedef void (CDECL CDECL_EXT* PFEVENTPOST_IEC) (eventpost_struct *p);
#if defined(CMPEVENTMGR_IMPLEMENTATION_NOTIMPLEMENTED) || defined(EVENTPOST_NOTIMPLEMENTED)
	#define USE_eventpost
	#define EXT_eventpost
	#define GET_eventpost(fl)  ERR_NOTIMPLEMENTED
	#define CAL_eventpost(p0) 
	#define CHK_eventpost  FALSE
	#define EXP_eventpost  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_eventpost
	#define EXT_eventpost
	#define GET_eventpost(fl)  CAL_CMGETAPI( "eventpost" ) 
	#define CAL_eventpost  eventpost
	#define CHK_eventpost  TRUE
	#define EXP_eventpost  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventpost", (RTS_UINTPTR)eventpost, 1, RTSITF_GET_SIGNATURE(0, 0x9FDEA762), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPEVENTMGR_IMPLEMENTATION_EXTERNAL)
	#define USE_eventpost
	#define EXT_eventpost
	#define GET_eventpost(fl)  CAL_CMGETAPI( "eventpost" ) 
	#define CAL_eventpost  eventpost
	#define CHK_eventpost  TRUE
	#define EXP_eventpost  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventpost", (RTS_UINTPTR)eventpost, 1, RTSITF_GET_SIGNATURE(0, 0x9FDEA762), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpEventMgr_Implementationeventpost
	#define EXT_CmpEventMgr_Implementationeventpost
	#define GET_CmpEventMgr_Implementationeventpost  ERR_OK
	#define CAL_CmpEventMgr_Implementationeventpost  eventpost
	#define CHK_CmpEventMgr_Implementationeventpost  TRUE
	#define EXP_CmpEventMgr_Implementationeventpost  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventpost", (RTS_UINTPTR)eventpost, 1, RTSITF_GET_SIGNATURE(0, 0x9FDEA762), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_eventpost
	#define EXT_eventpost
	#define GET_eventpost(fl)  CAL_CMGETAPI( "eventpost" ) 
	#define CAL_eventpost  eventpost
	#define CHK_eventpost  TRUE
	#define EXP_eventpost  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventpost", (RTS_UINTPTR)eventpost, 1, RTSITF_GET_SIGNATURE(0, 0x9FDEA762), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_eventpost  PFEVENTPOST_IEC pfeventpost;
	#define EXT_eventpost  extern PFEVENTPOST_IEC pfeventpost;
	#define GET_eventpost(fl)  s_pfCMGetAPI2( "eventpost", (RTS_VOID_FCTPTR *)&pfeventpost, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x9FDEA762), 0x03051000)
	#define CAL_eventpost  pfeventpost
	#define CHK_eventpost  (pfeventpost != NULL)
	#define EXP_eventpost   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventpost", (RTS_UINTPTR)eventpost, 1, RTSITF_GET_SIGNATURE(0, 0x9FDEA762), 0x03051000) 
#endif


/**
 * Post or sent an event 
 */
typedef struct tageventpost2_struct
{
	RTS_IEC_HANDLE hEvent;				/* VAR_INPUT */	/* Event handle */
	EventParam2 *pEventParam;			/* VAR_INPUT */	/* Pointer to the event parameters */
	RTS_IEC_RESULT EventPost2;			/* VAR_OUTPUT */	/* Error code */
} eventpost2_struct;

void CDECL CDECL_EXT eventpost2(eventpost2_struct *p);
typedef void (CDECL CDECL_EXT* PFEVENTPOST2_IEC) (eventpost2_struct *p);
#if defined(CMPEVENTMGR_IMPLEMENTATION_NOTIMPLEMENTED) || defined(EVENTPOST2_NOTIMPLEMENTED)
	#define USE_eventpost2
	#define EXT_eventpost2
	#define GET_eventpost2(fl)  ERR_NOTIMPLEMENTED
	#define CAL_eventpost2(p0) 
	#define CHK_eventpost2  FALSE
	#define EXP_eventpost2  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_eventpost2
	#define EXT_eventpost2
	#define GET_eventpost2(fl)  CAL_CMGETAPI( "eventpost2" ) 
	#define CAL_eventpost2  eventpost2
	#define CHK_eventpost2  TRUE
	#define EXP_eventpost2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventpost2", (RTS_UINTPTR)eventpost2, 1, 0xCE90F5F0, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPEVENTMGR_IMPLEMENTATION_EXTERNAL)
	#define USE_eventpost2
	#define EXT_eventpost2
	#define GET_eventpost2(fl)  CAL_CMGETAPI( "eventpost2" ) 
	#define CAL_eventpost2  eventpost2
	#define CHK_eventpost2  TRUE
	#define EXP_eventpost2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventpost2", (RTS_UINTPTR)eventpost2, 1, 0xCE90F5F0, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpEventMgr_Implementationeventpost2
	#define EXT_CmpEventMgr_Implementationeventpost2
	#define GET_CmpEventMgr_Implementationeventpost2  ERR_OK
	#define CAL_CmpEventMgr_Implementationeventpost2  eventpost2
	#define CHK_CmpEventMgr_Implementationeventpost2  TRUE
	#define EXP_CmpEventMgr_Implementationeventpost2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventpost2", (RTS_UINTPTR)eventpost2, 1, 0xCE90F5F0, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_eventpost2
	#define EXT_eventpost2
	#define GET_eventpost2(fl)  CAL_CMGETAPI( "eventpost2" ) 
	#define CAL_eventpost2  eventpost2
	#define CHK_eventpost2  TRUE
	#define EXP_eventpost2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventpost2", (RTS_UINTPTR)eventpost2, 1, 0xCE90F5F0, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_eventpost2  PFEVENTPOST2_IEC pfeventpost2;
	#define EXT_eventpost2  extern PFEVENTPOST2_IEC pfeventpost2;
	#define GET_eventpost2(fl)  s_pfCMGetAPI2( "eventpost2", (RTS_VOID_FCTPTR *)&pfeventpost2, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0xCE90F5F0, 0x03051000)
	#define CAL_eventpost2  pfeventpost2
	#define CHK_eventpost2  (pfeventpost2 != NULL)
	#define EXP_eventpost2   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventpost2", (RTS_UINTPTR)eventpost2, 1, 0xCE90F5F0, 0x03051000) 
#endif


/**
 * Post an event direct without the event handle 
 */
typedef struct tageventpostbyevent_struct
{
	RTS_IEC_UDINT EventId;				/* VAR_INPUT */	/* Event ID of the event. Contains the class and the event */
	RTS_IEC_UDINT CmpIdProvider;		/* VAR_INPUT */	/* Component ID of the provider */
	EventParam *pEventParam;			/* VAR_INPUT */	/* Pointer to the event parameters */
	RTS_IEC_RESULT EventPostByEvent;	/* VAR_OUTPUT */	/* Error code */
} eventpostbyevent_struct;

void CDECL CDECL_EXT eventpostbyevent(eventpostbyevent_struct *p);
typedef void (CDECL CDECL_EXT* PFEVENTPOSTBYEVENT_IEC) (eventpostbyevent_struct *p);
#if defined(CMPEVENTMGR_IMPLEMENTATION_NOTIMPLEMENTED) || defined(EVENTPOSTBYEVENT_NOTIMPLEMENTED)
	#define USE_eventpostbyevent
	#define EXT_eventpostbyevent
	#define GET_eventpostbyevent(fl)  ERR_NOTIMPLEMENTED
	#define CAL_eventpostbyevent(p0) 
	#define CHK_eventpostbyevent  FALSE
	#define EXP_eventpostbyevent  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_eventpostbyevent
	#define EXT_eventpostbyevent
	#define GET_eventpostbyevent(fl)  CAL_CMGETAPI( "eventpostbyevent" ) 
	#define CAL_eventpostbyevent  eventpostbyevent
	#define CHK_eventpostbyevent  TRUE
	#define EXP_eventpostbyevent  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventpostbyevent", (RTS_UINTPTR)eventpostbyevent, 1, RTSITF_GET_SIGNATURE(0, 0xA33BD23D), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPEVENTMGR_IMPLEMENTATION_EXTERNAL)
	#define USE_eventpostbyevent
	#define EXT_eventpostbyevent
	#define GET_eventpostbyevent(fl)  CAL_CMGETAPI( "eventpostbyevent" ) 
	#define CAL_eventpostbyevent  eventpostbyevent
	#define CHK_eventpostbyevent  TRUE
	#define EXP_eventpostbyevent  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventpostbyevent", (RTS_UINTPTR)eventpostbyevent, 1, RTSITF_GET_SIGNATURE(0, 0xA33BD23D), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpEventMgr_Implementationeventpostbyevent
	#define EXT_CmpEventMgr_Implementationeventpostbyevent
	#define GET_CmpEventMgr_Implementationeventpostbyevent  ERR_OK
	#define CAL_CmpEventMgr_Implementationeventpostbyevent  eventpostbyevent
	#define CHK_CmpEventMgr_Implementationeventpostbyevent  TRUE
	#define EXP_CmpEventMgr_Implementationeventpostbyevent  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventpostbyevent", (RTS_UINTPTR)eventpostbyevent, 1, RTSITF_GET_SIGNATURE(0, 0xA33BD23D), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_eventpostbyevent
	#define EXT_eventpostbyevent
	#define GET_eventpostbyevent(fl)  CAL_CMGETAPI( "eventpostbyevent" ) 
	#define CAL_eventpostbyevent  eventpostbyevent
	#define CHK_eventpostbyevent  TRUE
	#define EXP_eventpostbyevent  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventpostbyevent", (RTS_UINTPTR)eventpostbyevent, 1, RTSITF_GET_SIGNATURE(0, 0xA33BD23D), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_eventpostbyevent  PFEVENTPOSTBYEVENT_IEC pfeventpostbyevent;
	#define EXT_eventpostbyevent  extern PFEVENTPOSTBYEVENT_IEC pfeventpostbyevent;
	#define GET_eventpostbyevent(fl)  s_pfCMGetAPI2( "eventpostbyevent", (RTS_VOID_FCTPTR *)&pfeventpostbyevent, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xA33BD23D), 0x03051000)
	#define CAL_eventpostbyevent  pfeventpostbyevent
	#define CHK_eventpostbyevent  (pfeventpostbyevent != NULL)
	#define EXP_eventpostbyevent   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventpostbyevent", (RTS_UINTPTR)eventpostbyevent, 1, RTSITF_GET_SIGNATURE(0, 0xA33BD23D), 0x03051000) 
#endif


/**
 * Post an event direct without the event handle 
 */
typedef struct tageventpostbyevent2_struct
{
	RTS_IEC_UDINT EventId;				/* VAR_INPUT */	/* Event ID of the event. Contains the class and the event */
	RTS_IEC_UDINT CmpIdProvider;		/* VAR_INPUT */	/* Component ID of the provider */
	EventParam2 *pEventParam;			/* VAR_INPUT */	/* Pointer to the event parameters */
	RTS_IEC_RESULT EventPostByEvent2;	/* VAR_OUTPUT */	/* Error code */
} eventpostbyevent2_struct;

void CDECL CDECL_EXT eventpostbyevent2(eventpostbyevent2_struct *p);
typedef void (CDECL CDECL_EXT* PFEVENTPOSTBYEVENT2_IEC) (eventpostbyevent2_struct *p);
#if defined(CMPEVENTMGR_IMPLEMENTATION_NOTIMPLEMENTED) || defined(EVENTPOSTBYEVENT2_NOTIMPLEMENTED)
	#define USE_eventpostbyevent2
	#define EXT_eventpostbyevent2
	#define GET_eventpostbyevent2(fl)  ERR_NOTIMPLEMENTED
	#define CAL_eventpostbyevent2(p0) 
	#define CHK_eventpostbyevent2  FALSE
	#define EXP_eventpostbyevent2  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_eventpostbyevent2
	#define EXT_eventpostbyevent2
	#define GET_eventpostbyevent2(fl)  CAL_CMGETAPI( "eventpostbyevent2" ) 
	#define CAL_eventpostbyevent2  eventpostbyevent2
	#define CHK_eventpostbyevent2  TRUE
	#define EXP_eventpostbyevent2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventpostbyevent2", (RTS_UINTPTR)eventpostbyevent2, 1, 0x61F1EA28, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPEVENTMGR_IMPLEMENTATION_EXTERNAL)
	#define USE_eventpostbyevent2
	#define EXT_eventpostbyevent2
	#define GET_eventpostbyevent2(fl)  CAL_CMGETAPI( "eventpostbyevent2" ) 
	#define CAL_eventpostbyevent2  eventpostbyevent2
	#define CHK_eventpostbyevent2  TRUE
	#define EXP_eventpostbyevent2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventpostbyevent2", (RTS_UINTPTR)eventpostbyevent2, 1, 0x61F1EA28, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpEventMgr_Implementationeventpostbyevent2
	#define EXT_CmpEventMgr_Implementationeventpostbyevent2
	#define GET_CmpEventMgr_Implementationeventpostbyevent2  ERR_OK
	#define CAL_CmpEventMgr_Implementationeventpostbyevent2  eventpostbyevent2
	#define CHK_CmpEventMgr_Implementationeventpostbyevent2  TRUE
	#define EXP_CmpEventMgr_Implementationeventpostbyevent2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventpostbyevent2", (RTS_UINTPTR)eventpostbyevent2, 1, 0x61F1EA28, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_eventpostbyevent2
	#define EXT_eventpostbyevent2
	#define GET_eventpostbyevent2(fl)  CAL_CMGETAPI( "eventpostbyevent2" ) 
	#define CAL_eventpostbyevent2  eventpostbyevent2
	#define CHK_eventpostbyevent2  TRUE
	#define EXP_eventpostbyevent2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventpostbyevent2", (RTS_UINTPTR)eventpostbyevent2, 1, 0x61F1EA28, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_eventpostbyevent2  PFEVENTPOSTBYEVENT2_IEC pfeventpostbyevent2;
	#define EXT_eventpostbyevent2  extern PFEVENTPOSTBYEVENT2_IEC pfeventpostbyevent2;
	#define GET_eventpostbyevent2(fl)  s_pfCMGetAPI2( "eventpostbyevent2", (RTS_VOID_FCTPTR *)&pfeventpostbyevent2, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x61F1EA28, 0x03051000)
	#define CAL_eventpostbyevent2  pfeventpostbyevent2
	#define CHK_eventpostbyevent2  (pfeventpostbyevent2 != NULL)
	#define EXP_eventpostbyevent2   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventpostbyevent2", (RTS_UINTPTR)eventpostbyevent2, 1, 0x61F1EA28, 0x03051000) 
#endif


/**
 * Register an callback method to an event.
 * The callback must be an interface from an Iec function block!
 * Result will be set to ERR_DUPLICATE if pICallback is already registered. 
 */
typedef struct tageventregistercallback_struct
{
	RTS_IEC_HANDLE hEvent;				/* VAR_INPUT */	/* Handle to event */
	ICmpEventCallback *pICallback;		/* VAR_INPUT */	/* Interface ICmpEventCallback */
	RTS_IEC_RESULT *Result;	/* VAR_IN_OUT */	/* Error code */
	RTS_IEC_HANDLE EventRegisterCallback;	/* VAR_OUTPUT */	/* Handle to the callback that must be used to unregister with EventUnregisterCallback! */
} eventregistercallback_struct;

void CDECL CDECL_EXT eventregistercallback(eventregistercallback_struct *p);
typedef void (CDECL CDECL_EXT* PFEVENTREGISTERCALLBACK_IEC) (eventregistercallback_struct *p);
#if defined(CMPEVENTMGR_IMPLEMENTATION_NOTIMPLEMENTED) || defined(EVENTREGISTERCALLBACK_NOTIMPLEMENTED)
	#define USE_eventregistercallback
	#define EXT_eventregistercallback
	#define GET_eventregistercallback(fl)  ERR_NOTIMPLEMENTED
	#define CAL_eventregistercallback(p0) 
	#define CHK_eventregistercallback  FALSE
	#define EXP_eventregistercallback  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_eventregistercallback
	#define EXT_eventregistercallback
	#define GET_eventregistercallback(fl)  CAL_CMGETAPI( "eventregistercallback" ) 
	#define CAL_eventregistercallback  eventregistercallback
	#define CHK_eventregistercallback  TRUE
	#define EXP_eventregistercallback  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventregistercallback", (RTS_UINTPTR)eventregistercallback, 1, RTSITF_GET_SIGNATURE(0, 0x5EF9AC91), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPEVENTMGR_IMPLEMENTATION_EXTERNAL)
	#define USE_eventregistercallback
	#define EXT_eventregistercallback
	#define GET_eventregistercallback(fl)  CAL_CMGETAPI( "eventregistercallback" ) 
	#define CAL_eventregistercallback  eventregistercallback
	#define CHK_eventregistercallback  TRUE
	#define EXP_eventregistercallback  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventregistercallback", (RTS_UINTPTR)eventregistercallback, 1, RTSITF_GET_SIGNATURE(0, 0x5EF9AC91), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpEventMgr_Implementationeventregistercallback
	#define EXT_CmpEventMgr_Implementationeventregistercallback
	#define GET_CmpEventMgr_Implementationeventregistercallback  ERR_OK
	#define CAL_CmpEventMgr_Implementationeventregistercallback  eventregistercallback
	#define CHK_CmpEventMgr_Implementationeventregistercallback  TRUE
	#define EXP_CmpEventMgr_Implementationeventregistercallback  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventregistercallback", (RTS_UINTPTR)eventregistercallback, 1, RTSITF_GET_SIGNATURE(0, 0x5EF9AC91), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_eventregistercallback
	#define EXT_eventregistercallback
	#define GET_eventregistercallback(fl)  CAL_CMGETAPI( "eventregistercallback" ) 
	#define CAL_eventregistercallback  eventregistercallback
	#define CHK_eventregistercallback  TRUE
	#define EXP_eventregistercallback  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventregistercallback", (RTS_UINTPTR)eventregistercallback, 1, RTSITF_GET_SIGNATURE(0, 0x5EF9AC91), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_eventregistercallback  PFEVENTREGISTERCALLBACK_IEC pfeventregistercallback;
	#define EXT_eventregistercallback  extern PFEVENTREGISTERCALLBACK_IEC pfeventregistercallback;
	#define GET_eventregistercallback(fl)  s_pfCMGetAPI2( "eventregistercallback", (RTS_VOID_FCTPTR *)&pfeventregistercallback, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x5EF9AC91), 0x03051000)
	#define CAL_eventregistercallback  pfeventregistercallback
	#define CHK_eventregistercallback  (pfeventregistercallback != NULL)
	#define EXP_eventregistercallback   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventregistercallback", (RTS_UINTPTR)eventregistercallback, 1, RTSITF_GET_SIGNATURE(0, 0x5EF9AC91), 0x03051000) 
#endif


/**
 * Register an callback method to an event.
 * The callback must be an interface from an Iec function block!
 * Result will be set to ERR_DUPLICATE if the combination of pICallback and pUserParameter is already registered. 
 */
typedef struct tageventregistercallback2_struct
{
	RTS_IEC_HANDLE hEvent;				/* VAR_INPUT */	/* Handle to event */
	ICmpEventCallback *pICallback;		/* VAR_INPUT */	/* Interface ICmpEventCallback */
	RTS_IEC_BYTE *pUserParameter;		/* VAR_INPUT */	/* Pointer to user parameter, that is transmitted to the callback (see EventParam) */
	RTS_IEC_RESULT *Result;	/* VAR_IN_OUT */	/* Error code */
	RTS_IEC_HANDLE EventRegisterCallback2;	/* VAR_OUTPUT */	/* Handle to the callback that must be used to unregister with EventUnregisterCallback! */
} eventregistercallback2_struct;

void CDECL CDECL_EXT eventregistercallback2(eventregistercallback2_struct *p);
typedef void (CDECL CDECL_EXT* PFEVENTREGISTERCALLBACK2_IEC) (eventregistercallback2_struct *p);
#if defined(CMPEVENTMGR_IMPLEMENTATION_NOTIMPLEMENTED) || defined(EVENTREGISTERCALLBACK2_NOTIMPLEMENTED)
	#define USE_eventregistercallback2
	#define EXT_eventregistercallback2
	#define GET_eventregistercallback2(fl)  ERR_NOTIMPLEMENTED
	#define CAL_eventregistercallback2(p0) 
	#define CHK_eventregistercallback2  FALSE
	#define EXP_eventregistercallback2  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_eventregistercallback2
	#define EXT_eventregistercallback2
	#define GET_eventregistercallback2(fl)  CAL_CMGETAPI( "eventregistercallback2" ) 
	#define CAL_eventregistercallback2  eventregistercallback2
	#define CHK_eventregistercallback2  TRUE
	#define EXP_eventregistercallback2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventregistercallback2", (RTS_UINTPTR)eventregistercallback2, 1, RTSITF_GET_SIGNATURE(0, 0x95D8F44C), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPEVENTMGR_IMPLEMENTATION_EXTERNAL)
	#define USE_eventregistercallback2
	#define EXT_eventregistercallback2
	#define GET_eventregistercallback2(fl)  CAL_CMGETAPI( "eventregistercallback2" ) 
	#define CAL_eventregistercallback2  eventregistercallback2
	#define CHK_eventregistercallback2  TRUE
	#define EXP_eventregistercallback2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventregistercallback2", (RTS_UINTPTR)eventregistercallback2, 1, RTSITF_GET_SIGNATURE(0, 0x95D8F44C), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpEventMgr_Implementationeventregistercallback2
	#define EXT_CmpEventMgr_Implementationeventregistercallback2
	#define GET_CmpEventMgr_Implementationeventregistercallback2  ERR_OK
	#define CAL_CmpEventMgr_Implementationeventregistercallback2  eventregistercallback2
	#define CHK_CmpEventMgr_Implementationeventregistercallback2  TRUE
	#define EXP_CmpEventMgr_Implementationeventregistercallback2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventregistercallback2", (RTS_UINTPTR)eventregistercallback2, 1, RTSITF_GET_SIGNATURE(0, 0x95D8F44C), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_eventregistercallback2
	#define EXT_eventregistercallback2
	#define GET_eventregistercallback2(fl)  CAL_CMGETAPI( "eventregistercallback2" ) 
	#define CAL_eventregistercallback2  eventregistercallback2
	#define CHK_eventregistercallback2  TRUE
	#define EXP_eventregistercallback2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventregistercallback2", (RTS_UINTPTR)eventregistercallback2, 1, RTSITF_GET_SIGNATURE(0, 0x95D8F44C), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_eventregistercallback2  PFEVENTREGISTERCALLBACK2_IEC pfeventregistercallback2;
	#define EXT_eventregistercallback2  extern PFEVENTREGISTERCALLBACK2_IEC pfeventregistercallback2;
	#define GET_eventregistercallback2(fl)  s_pfCMGetAPI2( "eventregistercallback2", (RTS_VOID_FCTPTR *)&pfeventregistercallback2, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x95D8F44C), 0x03051000)
	#define CAL_eventregistercallback2  pfeventregistercallback2
	#define CHK_eventregistercallback2  (pfeventregistercallback2 != NULL)
	#define EXP_eventregistercallback2   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventregistercallback2", (RTS_UINTPTR)eventregistercallback2, 1, RTSITF_GET_SIGNATURE(0, 0x95D8F44C), 0x03051000) 
#endif


/**
 * Register a callback function to an event. Callback is the address of an Iec function: ADR(function) 
 */
typedef struct tageventregistercallbackfunction_struct
{
	RTS_IEC_HANDLE hEvent;				/* VAR_INPUT */	/* Handle to event */
	RTS_IEC_BYTE *pfCallbackFunction;	/* VAR_INPUT */	/* Address of callback function. Prototype: same as ICmpEventCallback::EventCallback method
															  Function pointer is retrieved by the ADR operator: ADR(function) */
	RTS_IEC_RESULT EventRegisterCallbackFunction;	/* VAR_OUTPUT */	/* Error code */
} eventregistercallbackfunction_struct;

void CDECL CDECL_EXT eventregistercallbackfunction(eventregistercallbackfunction_struct *p);
typedef void (CDECL CDECL_EXT* PFEVENTREGISTERCALLBACKFUNCTION_IEC) (eventregistercallbackfunction_struct *p);
#if defined(CMPEVENTMGR_IMPLEMENTATION_NOTIMPLEMENTED) || defined(EVENTREGISTERCALLBACKFUNCTION_NOTIMPLEMENTED)
	#define USE_eventregistercallbackfunction
	#define EXT_eventregistercallbackfunction
	#define GET_eventregistercallbackfunction(fl)  ERR_NOTIMPLEMENTED
	#define CAL_eventregistercallbackfunction(p0) 
	#define CHK_eventregistercallbackfunction  FALSE
	#define EXP_eventregistercallbackfunction  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_eventregistercallbackfunction
	#define EXT_eventregistercallbackfunction
	#define GET_eventregistercallbackfunction(fl)  CAL_CMGETAPI( "eventregistercallbackfunction" ) 
	#define CAL_eventregistercallbackfunction  eventregistercallbackfunction
	#define CHK_eventregistercallbackfunction  TRUE
	#define EXP_eventregistercallbackfunction  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventregistercallbackfunction", (RTS_UINTPTR)eventregistercallbackfunction, 1, RTSITF_GET_SIGNATURE(0, 0x989C8BB3), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPEVENTMGR_IMPLEMENTATION_EXTERNAL)
	#define USE_eventregistercallbackfunction
	#define EXT_eventregistercallbackfunction
	#define GET_eventregistercallbackfunction(fl)  CAL_CMGETAPI( "eventregistercallbackfunction" ) 
	#define CAL_eventregistercallbackfunction  eventregistercallbackfunction
	#define CHK_eventregistercallbackfunction  TRUE
	#define EXP_eventregistercallbackfunction  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventregistercallbackfunction", (RTS_UINTPTR)eventregistercallbackfunction, 1, RTSITF_GET_SIGNATURE(0, 0x989C8BB3), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpEventMgr_Implementationeventregistercallbackfunction
	#define EXT_CmpEventMgr_Implementationeventregistercallbackfunction
	#define GET_CmpEventMgr_Implementationeventregistercallbackfunction  ERR_OK
	#define CAL_CmpEventMgr_Implementationeventregistercallbackfunction  eventregistercallbackfunction
	#define CHK_CmpEventMgr_Implementationeventregistercallbackfunction  TRUE
	#define EXP_CmpEventMgr_Implementationeventregistercallbackfunction  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventregistercallbackfunction", (RTS_UINTPTR)eventregistercallbackfunction, 1, RTSITF_GET_SIGNATURE(0, 0x989C8BB3), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_eventregistercallbackfunction
	#define EXT_eventregistercallbackfunction
	#define GET_eventregistercallbackfunction(fl)  CAL_CMGETAPI( "eventregistercallbackfunction" ) 
	#define CAL_eventregistercallbackfunction  eventregistercallbackfunction
	#define CHK_eventregistercallbackfunction  TRUE
	#define EXP_eventregistercallbackfunction  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventregistercallbackfunction", (RTS_UINTPTR)eventregistercallbackfunction, 1, RTSITF_GET_SIGNATURE(0, 0x989C8BB3), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_eventregistercallbackfunction  PFEVENTREGISTERCALLBACKFUNCTION_IEC pfeventregistercallbackfunction;
	#define EXT_eventregistercallbackfunction  extern PFEVENTREGISTERCALLBACKFUNCTION_IEC pfeventregistercallbackfunction;
	#define GET_eventregistercallbackfunction(fl)  s_pfCMGetAPI2( "eventregistercallbackfunction", (RTS_VOID_FCTPTR *)&pfeventregistercallbackfunction, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x989C8BB3), 0x03051000)
	#define CAL_eventregistercallbackfunction  pfeventregistercallbackfunction
	#define CHK_eventregistercallbackfunction  (pfeventregistercallbackfunction != NULL)
	#define EXP_eventregistercallbackfunction   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventregistercallbackfunction", (RTS_UINTPTR)eventregistercallbackfunction, 1, RTSITF_GET_SIGNATURE(0, 0x989C8BB3), 0x03051000) 
#endif


/**
 * Register a callback function to an event. Callback is the address of an Iec function: ADR(function) 
 */
typedef struct tageventregistercallbackfunction2_struct
{
	RTS_IEC_HANDLE hEvent;				/* VAR_INPUT */	/* Handle to event */
	RTS_IEC_BYTE *pfCallbackFunction;	/* VAR_INPUT */	/* Address of callback function. Prototype: same as ICmpEventCallback::EventCallback method
															  Function pointer is retrieved by the ADR operator: ADR(function) */
	RTS_IEC_BYTE *pUserParameter;		/* VAR_INPUT */	/* Pointer to user parameter, that is transmitted optional to the callback (see EventParam) */
	RTS_IEC_RESULT EventRegisterCallbackFunction2;	/* VAR_OUTPUT */	/* Error code */
} eventregistercallbackfunction2_struct;

void CDECL CDECL_EXT eventregistercallbackfunction2(eventregistercallbackfunction2_struct *p);
typedef void (CDECL CDECL_EXT* PFEVENTREGISTERCALLBACKFUNCTION2_IEC) (eventregistercallbackfunction2_struct *p);
#if defined(CMPEVENTMGR_IMPLEMENTATION_NOTIMPLEMENTED) || defined(EVENTREGISTERCALLBACKFUNCTION2_NOTIMPLEMENTED)
	#define USE_eventregistercallbackfunction2
	#define EXT_eventregistercallbackfunction2
	#define GET_eventregistercallbackfunction2(fl)  ERR_NOTIMPLEMENTED
	#define CAL_eventregistercallbackfunction2(p0) 
	#define CHK_eventregistercallbackfunction2  FALSE
	#define EXP_eventregistercallbackfunction2  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_eventregistercallbackfunction2
	#define EXT_eventregistercallbackfunction2
	#define GET_eventregistercallbackfunction2(fl)  CAL_CMGETAPI( "eventregistercallbackfunction2" ) 
	#define CAL_eventregistercallbackfunction2  eventregistercallbackfunction2
	#define CHK_eventregistercallbackfunction2  TRUE
	#define EXP_eventregistercallbackfunction2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventregistercallbackfunction2", (RTS_UINTPTR)eventregistercallbackfunction2, 1, RTSITF_GET_SIGNATURE(0, 0xBD946DD7), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPEVENTMGR_IMPLEMENTATION_EXTERNAL)
	#define USE_eventregistercallbackfunction2
	#define EXT_eventregistercallbackfunction2
	#define GET_eventregistercallbackfunction2(fl)  CAL_CMGETAPI( "eventregistercallbackfunction2" ) 
	#define CAL_eventregistercallbackfunction2  eventregistercallbackfunction2
	#define CHK_eventregistercallbackfunction2  TRUE
	#define EXP_eventregistercallbackfunction2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventregistercallbackfunction2", (RTS_UINTPTR)eventregistercallbackfunction2, 1, RTSITF_GET_SIGNATURE(0, 0xBD946DD7), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpEventMgr_Implementationeventregistercallbackfunction2
	#define EXT_CmpEventMgr_Implementationeventregistercallbackfunction2
	#define GET_CmpEventMgr_Implementationeventregistercallbackfunction2  ERR_OK
	#define CAL_CmpEventMgr_Implementationeventregistercallbackfunction2  eventregistercallbackfunction2
	#define CHK_CmpEventMgr_Implementationeventregistercallbackfunction2  TRUE
	#define EXP_CmpEventMgr_Implementationeventregistercallbackfunction2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventregistercallbackfunction2", (RTS_UINTPTR)eventregistercallbackfunction2, 1, RTSITF_GET_SIGNATURE(0, 0xBD946DD7), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_eventregistercallbackfunction2
	#define EXT_eventregistercallbackfunction2
	#define GET_eventregistercallbackfunction2(fl)  CAL_CMGETAPI( "eventregistercallbackfunction2" ) 
	#define CAL_eventregistercallbackfunction2  eventregistercallbackfunction2
	#define CHK_eventregistercallbackfunction2  TRUE
	#define EXP_eventregistercallbackfunction2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventregistercallbackfunction2", (RTS_UINTPTR)eventregistercallbackfunction2, 1, RTSITF_GET_SIGNATURE(0, 0xBD946DD7), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_eventregistercallbackfunction2  PFEVENTREGISTERCALLBACKFUNCTION2_IEC pfeventregistercallbackfunction2;
	#define EXT_eventregistercallbackfunction2  extern PFEVENTREGISTERCALLBACKFUNCTION2_IEC pfeventregistercallbackfunction2;
	#define GET_eventregistercallbackfunction2(fl)  s_pfCMGetAPI2( "eventregistercallbackfunction2", (RTS_VOID_FCTPTR *)&pfeventregistercallbackfunction2, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xBD946DD7), 0x03051000)
	#define CAL_eventregistercallbackfunction2  pfeventregistercallbackfunction2
	#define CHK_eventregistercallbackfunction2  (pfeventregistercallbackfunction2 != NULL)
	#define EXP_eventregistercallbackfunction2   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventregistercallbackfunction2", (RTS_UINTPTR)eventregistercallbackfunction2, 1, RTSITF_GET_SIGNATURE(0, 0xBD946DD7), 0x03051000) 
#endif


/**
 * Returns the number of registered callbacks on the event 
 */
typedef struct tageventregisteredcallbacks_struct
{
	RTS_IEC_HANDLE hEvent;				/* VAR_INPUT */	/* Event handle */
	RTS_IEC_RESULT *Result;	/* VAR_IN_OUT */	/* Error code */
	RTS_IEC_UDINT EventRegisteredCallbacks;	/* VAR_OUTPUT */	/* Returns the number of registered callbacks on the event */
} eventregisteredcallbacks_struct;

void CDECL CDECL_EXT eventregisteredcallbacks(eventregisteredcallbacks_struct *p);
typedef void (CDECL CDECL_EXT* PFEVENTREGISTEREDCALLBACKS_IEC) (eventregisteredcallbacks_struct *p);
#if defined(CMPEVENTMGR_IMPLEMENTATION_NOTIMPLEMENTED) || defined(EVENTREGISTEREDCALLBACKS_NOTIMPLEMENTED)
	#define USE_eventregisteredcallbacks
	#define EXT_eventregisteredcallbacks
	#define GET_eventregisteredcallbacks(fl)  ERR_NOTIMPLEMENTED
	#define CAL_eventregisteredcallbacks(p0) 
	#define CHK_eventregisteredcallbacks  FALSE
	#define EXP_eventregisteredcallbacks  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_eventregisteredcallbacks
	#define EXT_eventregisteredcallbacks
	#define GET_eventregisteredcallbacks(fl)  CAL_CMGETAPI( "eventregisteredcallbacks" ) 
	#define CAL_eventregisteredcallbacks  eventregisteredcallbacks
	#define CHK_eventregisteredcallbacks  TRUE
	#define EXP_eventregisteredcallbacks  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventregisteredcallbacks", (RTS_UINTPTR)eventregisteredcallbacks, 1, RTSITF_GET_SIGNATURE(0, 0xC4EA0B3B), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPEVENTMGR_IMPLEMENTATION_EXTERNAL)
	#define USE_eventregisteredcallbacks
	#define EXT_eventregisteredcallbacks
	#define GET_eventregisteredcallbacks(fl)  CAL_CMGETAPI( "eventregisteredcallbacks" ) 
	#define CAL_eventregisteredcallbacks  eventregisteredcallbacks
	#define CHK_eventregisteredcallbacks  TRUE
	#define EXP_eventregisteredcallbacks  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventregisteredcallbacks", (RTS_UINTPTR)eventregisteredcallbacks, 1, RTSITF_GET_SIGNATURE(0, 0xC4EA0B3B), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpEventMgr_Implementationeventregisteredcallbacks
	#define EXT_CmpEventMgr_Implementationeventregisteredcallbacks
	#define GET_CmpEventMgr_Implementationeventregisteredcallbacks  ERR_OK
	#define CAL_CmpEventMgr_Implementationeventregisteredcallbacks  eventregisteredcallbacks
	#define CHK_CmpEventMgr_Implementationeventregisteredcallbacks  TRUE
	#define EXP_CmpEventMgr_Implementationeventregisteredcallbacks  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventregisteredcallbacks", (RTS_UINTPTR)eventregisteredcallbacks, 1, RTSITF_GET_SIGNATURE(0, 0xC4EA0B3B), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_eventregisteredcallbacks
	#define EXT_eventregisteredcallbacks
	#define GET_eventregisteredcallbacks(fl)  CAL_CMGETAPI( "eventregisteredcallbacks" ) 
	#define CAL_eventregisteredcallbacks  eventregisteredcallbacks
	#define CHK_eventregisteredcallbacks  TRUE
	#define EXP_eventregisteredcallbacks  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventregisteredcallbacks", (RTS_UINTPTR)eventregisteredcallbacks, 1, RTSITF_GET_SIGNATURE(0, 0xC4EA0B3B), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_eventregisteredcallbacks  PFEVENTREGISTEREDCALLBACKS_IEC pfeventregisteredcallbacks;
	#define EXT_eventregisteredcallbacks  extern PFEVENTREGISTEREDCALLBACKS_IEC pfeventregisteredcallbacks;
	#define GET_eventregisteredcallbacks(fl)  s_pfCMGetAPI2( "eventregisteredcallbacks", (RTS_VOID_FCTPTR *)&pfeventregisteredcallbacks, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0xC4EA0B3B), 0x03051000)
	#define CAL_eventregisteredcallbacks  pfeventregisteredcallbacks
	#define CHK_eventregisteredcallbacks  (pfeventregisteredcallbacks != NULL)
	#define EXP_eventregisteredcallbacks   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventregisteredcallbacks", (RTS_UINTPTR)eventregisteredcallbacks, 1, RTSITF_GET_SIGNATURE(0, 0xC4EA0B3B), 0x03051000) 
#endif


/**
 * Unregister a callback interface from an event specified by handle and callback interface 
 */
typedef struct tageventunregistercallback_struct
{
	RTS_IEC_HANDLE hEvent;				/* VAR_INPUT */	/* Event handle */
	RTS_IEC_HANDLE hInterface;			/* VAR_INPUT */	/* Callback handle is returned by EventRegisterCallback() or EventRegisterCallback2()!!! */
	RTS_IEC_RESULT EventUnregisterCallback;	/* VAR_OUTPUT */	/* Error code */
} eventunregistercallback_struct;

void CDECL CDECL_EXT eventunregistercallback(eventunregistercallback_struct *p);
typedef void (CDECL CDECL_EXT* PFEVENTUNREGISTERCALLBACK_IEC) (eventunregistercallback_struct *p);
#if defined(CMPEVENTMGR_IMPLEMENTATION_NOTIMPLEMENTED) || defined(EVENTUNREGISTERCALLBACK_NOTIMPLEMENTED)
	#define USE_eventunregistercallback
	#define EXT_eventunregistercallback
	#define GET_eventunregistercallback(fl)  ERR_NOTIMPLEMENTED
	#define CAL_eventunregistercallback(p0) 
	#define CHK_eventunregistercallback  FALSE
	#define EXP_eventunregistercallback  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_eventunregistercallback
	#define EXT_eventunregistercallback
	#define GET_eventunregistercallback(fl)  CAL_CMGETAPI( "eventunregistercallback" ) 
	#define CAL_eventunregistercallback  eventunregistercallback
	#define CHK_eventunregistercallback  TRUE
	#define EXP_eventunregistercallback  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventunregistercallback", (RTS_UINTPTR)eventunregistercallback, 1, RTSITF_GET_SIGNATURE(0, 0x80238B4F), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPEVENTMGR_IMPLEMENTATION_EXTERNAL)
	#define USE_eventunregistercallback
	#define EXT_eventunregistercallback
	#define GET_eventunregistercallback(fl)  CAL_CMGETAPI( "eventunregistercallback" ) 
	#define CAL_eventunregistercallback  eventunregistercallback
	#define CHK_eventunregistercallback  TRUE
	#define EXP_eventunregistercallback  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventunregistercallback", (RTS_UINTPTR)eventunregistercallback, 1, RTSITF_GET_SIGNATURE(0, 0x80238B4F), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpEventMgr_Implementationeventunregistercallback
	#define EXT_CmpEventMgr_Implementationeventunregistercallback
	#define GET_CmpEventMgr_Implementationeventunregistercallback  ERR_OK
	#define CAL_CmpEventMgr_Implementationeventunregistercallback  eventunregistercallback
	#define CHK_CmpEventMgr_Implementationeventunregistercallback  TRUE
	#define EXP_CmpEventMgr_Implementationeventunregistercallback  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventunregistercallback", (RTS_UINTPTR)eventunregistercallback, 1, RTSITF_GET_SIGNATURE(0, 0x80238B4F), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_eventunregistercallback
	#define EXT_eventunregistercallback
	#define GET_eventunregistercallback(fl)  CAL_CMGETAPI( "eventunregistercallback" ) 
	#define CAL_eventunregistercallback  eventunregistercallback
	#define CHK_eventunregistercallback  TRUE
	#define EXP_eventunregistercallback  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventunregistercallback", (RTS_UINTPTR)eventunregistercallback, 1, RTSITF_GET_SIGNATURE(0, 0x80238B4F), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_eventunregistercallback  PFEVENTUNREGISTERCALLBACK_IEC pfeventunregistercallback;
	#define EXT_eventunregistercallback  extern PFEVENTUNREGISTERCALLBACK_IEC pfeventunregistercallback;
	#define GET_eventunregistercallback(fl)  s_pfCMGetAPI2( "eventunregistercallback", (RTS_VOID_FCTPTR *)&pfeventunregistercallback, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x80238B4F), 0x03051000)
	#define CAL_eventunregistercallback  pfeventunregistercallback
	#define CHK_eventunregistercallback  (pfeventunregistercallback != NULL)
	#define EXP_eventunregistercallback   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventunregistercallback", (RTS_UINTPTR)eventunregistercallback, 1, RTSITF_GET_SIGNATURE(0, 0x80238B4F), 0x03051000) 
#endif


/**
 * Unregister a callback function from an event specified by handle and callback 
 */
typedef struct tageventunregistercallbackfunction_struct
{
	RTS_IEC_HANDLE hEvent;				/* VAR_INPUT */	/* Handle to event */
	RTS_IEC_BYTE *pfCallbackFunction;	/* VAR_INPUT */	/* Address of callback function. Function pointer is retrieved by the ADR operator: ADR(function) */
	RTS_IEC_RESULT EventUnregisterCallbackFunction;	/* VAR_OUTPUT */	/* Error code */
} eventunregistercallbackfunction_struct;

void CDECL CDECL_EXT eventunregistercallbackfunction(eventunregistercallbackfunction_struct *p);
typedef void (CDECL CDECL_EXT* PFEVENTUNREGISTERCALLBACKFUNCTION_IEC) (eventunregistercallbackfunction_struct *p);
#if defined(CMPEVENTMGR_IMPLEMENTATION_NOTIMPLEMENTED) || defined(EVENTUNREGISTERCALLBACKFUNCTION_NOTIMPLEMENTED)
	#define USE_eventunregistercallbackfunction
	#define EXT_eventunregistercallbackfunction
	#define GET_eventunregistercallbackfunction(fl)  ERR_NOTIMPLEMENTED
	#define CAL_eventunregistercallbackfunction(p0) 
	#define CHK_eventunregistercallbackfunction  FALSE
	#define EXP_eventunregistercallbackfunction  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_eventunregistercallbackfunction
	#define EXT_eventunregistercallbackfunction
	#define GET_eventunregistercallbackfunction(fl)  CAL_CMGETAPI( "eventunregistercallbackfunction" ) 
	#define CAL_eventunregistercallbackfunction  eventunregistercallbackfunction
	#define CHK_eventunregistercallbackfunction  TRUE
	#define EXP_eventunregistercallbackfunction  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventunregistercallbackfunction", (RTS_UINTPTR)eventunregistercallbackfunction, 1, RTSITF_GET_SIGNATURE(0, 0x5E0DD5BD), 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPEVENTMGR_IMPLEMENTATION_EXTERNAL)
	#define USE_eventunregistercallbackfunction
	#define EXT_eventunregistercallbackfunction
	#define GET_eventunregistercallbackfunction(fl)  CAL_CMGETAPI( "eventunregistercallbackfunction" ) 
	#define CAL_eventunregistercallbackfunction  eventunregistercallbackfunction
	#define CHK_eventunregistercallbackfunction  TRUE
	#define EXP_eventunregistercallbackfunction  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventunregistercallbackfunction", (RTS_UINTPTR)eventunregistercallbackfunction, 1, RTSITF_GET_SIGNATURE(0, 0x5E0DD5BD), 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpEventMgr_Implementationeventunregistercallbackfunction
	#define EXT_CmpEventMgr_Implementationeventunregistercallbackfunction
	#define GET_CmpEventMgr_Implementationeventunregistercallbackfunction  ERR_OK
	#define CAL_CmpEventMgr_Implementationeventunregistercallbackfunction  eventunregistercallbackfunction
	#define CHK_CmpEventMgr_Implementationeventunregistercallbackfunction  TRUE
	#define EXP_CmpEventMgr_Implementationeventunregistercallbackfunction  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventunregistercallbackfunction", (RTS_UINTPTR)eventunregistercallbackfunction, 1, RTSITF_GET_SIGNATURE(0, 0x5E0DD5BD), 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_eventunregistercallbackfunction
	#define EXT_eventunregistercallbackfunction
	#define GET_eventunregistercallbackfunction(fl)  CAL_CMGETAPI( "eventunregistercallbackfunction" ) 
	#define CAL_eventunregistercallbackfunction  eventunregistercallbackfunction
	#define CHK_eventunregistercallbackfunction  TRUE
	#define EXP_eventunregistercallbackfunction  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventunregistercallbackfunction", (RTS_UINTPTR)eventunregistercallbackfunction, 1, RTSITF_GET_SIGNATURE(0, 0x5E0DD5BD), 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_eventunregistercallbackfunction  PFEVENTUNREGISTERCALLBACKFUNCTION_IEC pfeventunregistercallbackfunction;
	#define EXT_eventunregistercallbackfunction  extern PFEVENTUNREGISTERCALLBACKFUNCTION_IEC pfeventunregistercallbackfunction;
	#define GET_eventunregistercallbackfunction(fl)  s_pfCMGetAPI2( "eventunregistercallbackfunction", (RTS_VOID_FCTPTR *)&pfeventunregistercallbackfunction, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, RTSITF_GET_SIGNATURE(0, 0x5E0DD5BD), 0x03051000)
	#define CAL_eventunregistercallbackfunction  pfeventunregistercallbackfunction
	#define CHK_eventunregistercallbackfunction  (pfeventunregistercallbackfunction != NULL)
	#define EXP_eventunregistercallbackfunction   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventunregistercallbackfunction", (RTS_UINTPTR)eventunregistercallbackfunction, 1, RTSITF_GET_SIGNATURE(0, 0x5E0DD5BD), 0x03051000) 
#endif


/**
 * Unregister a callback function with a specific user parameter from an event specified by handle and callback and parameter 
 */
typedef struct tageventunregistercallbackfunction2_struct
{
	RTS_IEC_HANDLE hEvent;				/* VAR_INPUT */	/* Handle to event */
	RTS_IEC_BYTE *pfCallbackFunction;	/* VAR_INPUT */	/* Address of callback function. Function pointer is retrieved by the ADR operator: ADR(function) */
	RTS_IEC_BYTE *pUserParameter;		/* VAR_INPUT */	/* Pointer to user parameter, that was specified as a parameter at EventRegisterCallback2() */
	RTS_IEC_RESULT EventUnregisterCallbackFunction2;	/* VAR_OUTPUT */	/* Error code */
} eventunregistercallbackfunction2_struct;

void CDECL CDECL_EXT eventunregistercallbackfunction2(eventunregistercallbackfunction2_struct *p);
typedef void (CDECL CDECL_EXT* PFEVENTUNREGISTERCALLBACKFUNCTION2_IEC) (eventunregistercallbackfunction2_struct *p);
#if defined(CMPEVENTMGR_IMPLEMENTATION_NOTIMPLEMENTED) || defined(EVENTUNREGISTERCALLBACKFUNCTION2_NOTIMPLEMENTED)
	#define USE_eventunregistercallbackfunction2
	#define EXT_eventunregistercallbackfunction2
	#define GET_eventunregistercallbackfunction2(fl)  ERR_NOTIMPLEMENTED
	#define CAL_eventunregistercallbackfunction2(p0) 
	#define CHK_eventunregistercallbackfunction2  FALSE
	#define EXP_eventunregistercallbackfunction2  ERR_OK
#elif defined(STATIC_LINK)
	#define USE_eventunregistercallbackfunction2
	#define EXT_eventunregistercallbackfunction2
	#define GET_eventunregistercallbackfunction2(fl)  CAL_CMGETAPI( "eventunregistercallbackfunction2" ) 
	#define CAL_eventunregistercallbackfunction2  eventunregistercallbackfunction2
	#define CHK_eventunregistercallbackfunction2  TRUE
	#define EXP_eventunregistercallbackfunction2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventunregistercallbackfunction2", (RTS_UINTPTR)eventunregistercallbackfunction2, 1, 0x779853A9, 0x03051000) 
#elif defined(MIXED_LINK) && !defined(CMPEVENTMGR_IMPLEMENTATION_EXTERNAL)
	#define USE_eventunregistercallbackfunction2
	#define EXT_eventunregistercallbackfunction2
	#define GET_eventunregistercallbackfunction2(fl)  CAL_CMGETAPI( "eventunregistercallbackfunction2" ) 
	#define CAL_eventunregistercallbackfunction2  eventunregistercallbackfunction2
	#define CHK_eventunregistercallbackfunction2  TRUE
	#define EXP_eventunregistercallbackfunction2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventunregistercallbackfunction2", (RTS_UINTPTR)eventunregistercallbackfunction2, 1, 0x779853A9, 0x03051000) 
#elif defined(CPLUSPLUS_ONLY)
	#define USE_CmpEventMgr_Implementationeventunregistercallbackfunction2
	#define EXT_CmpEventMgr_Implementationeventunregistercallbackfunction2
	#define GET_CmpEventMgr_Implementationeventunregistercallbackfunction2  ERR_OK
	#define CAL_CmpEventMgr_Implementationeventunregistercallbackfunction2  eventunregistercallbackfunction2
	#define CHK_CmpEventMgr_Implementationeventunregistercallbackfunction2  TRUE
	#define EXP_CmpEventMgr_Implementationeventunregistercallbackfunction2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventunregistercallbackfunction2", (RTS_UINTPTR)eventunregistercallbackfunction2, 1, 0x779853A9, 0x03051000) 
#elif defined(CPLUSPLUS)
	#define USE_eventunregistercallbackfunction2
	#define EXT_eventunregistercallbackfunction2
	#define GET_eventunregistercallbackfunction2(fl)  CAL_CMGETAPI( "eventunregistercallbackfunction2" ) 
	#define CAL_eventunregistercallbackfunction2  eventunregistercallbackfunction2
	#define CHK_eventunregistercallbackfunction2  TRUE
	#define EXP_eventunregistercallbackfunction2  s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventunregistercallbackfunction2", (RTS_UINTPTR)eventunregistercallbackfunction2, 1, 0x779853A9, 0x03051000) 
#else /* DYNAMIC_LINK */
	#define USE_eventunregistercallbackfunction2  PFEVENTUNREGISTERCALLBACKFUNCTION2_IEC pfeventunregistercallbackfunction2;
	#define EXT_eventunregistercallbackfunction2  extern PFEVENTUNREGISTERCALLBACKFUNCTION2_IEC pfeventunregistercallbackfunction2;
	#define GET_eventunregistercallbackfunction2(fl)  s_pfCMGetAPI2( "eventunregistercallbackfunction2", (RTS_VOID_FCTPTR *)&pfeventunregistercallbackfunction2, (fl) | CM_IMPORT_EXTERNAL_LIB_FUNCTION, 0x779853A9, 0x03051000)
	#define CAL_eventunregistercallbackfunction2  pfeventunregistercallbackfunction2
	#define CHK_eventunregistercallbackfunction2  (pfeventunregistercallbackfunction2 != NULL)
	#define EXP_eventunregistercallbackfunction2   s_pfCMRegisterAPI2( (const CMP_EXT_FUNCTION_REF*)"eventunregistercallbackfunction2", (RTS_UINTPTR)eventunregistercallbackfunction2, 1, 0x779853A9, 0x03051000) 
#endif


#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/




typedef struct
{
	IBase_C *pBase;
} ICmpEventMgr_Implementation_C;

#ifdef CPLUSPLUS
class ICmpEventMgr_Implementation : public IBase
{
	public:
};
	#ifndef ITF_CmpEventMgr_Implementation
		#define ITF_CmpEventMgr_Implementation static ICmpEventMgr_Implementation *pICmpEventMgr_Implementation = NULL;
	#endif
	#define EXTITF_CmpEventMgr_Implementation
#else	/*CPLUSPLUS*/
	typedef ICmpEventMgr_Implementation_C		ICmpEventMgr_Implementation;
	#ifndef ITF_CmpEventMgr_Implementation
		#define ITF_CmpEventMgr_Implementation
	#endif
	#define EXTITF_CmpEventMgr_Implementation
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_CMPEVENTMGR_IMPLEMENTATIONITF_H_*/
