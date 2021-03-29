/**
 * <interfacename>CmpEventMgr_Implementation</interfacename>
 * <description></description>
 *
 * <copyright></copyright>
 */

SET_INTERFACE_NAME(`CmpEventMgr_Implementation')
SET_PLACEHOLDER_NAME(`CmpEventMgr Implementation')

/** EXTERN LIB SECTION BEGIN **/
/*  Comments are ignored for m4 compiler so restructured text can be used. changecom(`/*', `*/') */

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

DEF_API(`void',`CDECL',`eventclose',`(eventclose_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x4668EEC1),0x03051000)

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

DEF_API(`void',`CDECL',`eventcreate',`(eventcreate_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xAC9E014A),0x03051000)

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

DEF_API(`void',`CDECL',`eventcreate2',`(eventcreate2_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xD6BF4CE8),0x03051000)

/**
 * Deletes an event specified by handle. 
 */
typedef struct tageventdelete_struct
{
	RTS_IEC_HANDLE hEvent;				/* VAR_INPUT */	/* Event handle */
	RTS_IEC_RESULT EventDelete;			/* VAR_OUTPUT */	/* Error code */
} eventdelete_struct;

DEF_API(`void',`CDECL',`eventdelete',`(eventdelete_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x0794C5F5),0x03051000)

/**
 * Extract the event class from eventid. Return value is the event class 
 */
typedef struct tageventgetclass_struct
{
	RTS_IEC_UDINT EventId;				/* VAR_INPUT */	/* Event id */
	RTS_IEC_UINT EventGetClass;			/* VAR_OUTPUT */	/* Class of the event. See EventClass for details */
} eventgetclass_struct;

DEF_API(`void',`CDECL',`eventgetclass',`(eventgetclass_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xB0745754),0x03051000)

/**
 * Extract the event from eventid. Return value ist the event 
 */
typedef struct tageventgetevent_struct
{
	RTS_IEC_UDINT EventId;				/* VAR_INPUT */	/* Event ID */
	RTS_IEC_UINT EventGetEvent;			/* VAR_OUTPUT */	/* Extracted event from the eventid */
} eventgetevent_struct;

DEF_API(`void',`CDECL',`eventgetevent',`(eventgetevent_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x0E7E3D61),0x03051000)

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

DEF_API(`void',`CDECL',`eventopen',`(eventopen_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xBC5AE4E1),0x03051000)

/**
 * Post or sent an event 
 */
typedef struct tageventpost_struct
{
	RTS_IEC_HANDLE hEvent;				/* VAR_INPUT */	/* Event handle */
	EventParam *pEventParam;			/* VAR_INPUT */	/* Pointer to the event parameters */
	RTS_IEC_RESULT EventPost;			/* VAR_OUTPUT */	/* Error code */
} eventpost_struct;

DEF_API(`void',`CDECL',`eventpost',`(eventpost_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x9FDEA762),0x03051000)

/**
 * Post or sent an event 
 */
typedef struct tageventpost2_struct
{
	RTS_IEC_HANDLE hEvent;				/* VAR_INPUT */	/* Event handle */
	EventParam2 *pEventParam;			/* VAR_INPUT */	/* Pointer to the event parameters */
	RTS_IEC_RESULT EventPost2;			/* VAR_OUTPUT */	/* Error code */
} eventpost2_struct;

DEF_API(`void',`CDECL',`eventpost2',`(eventpost2_struct *p)',1,0xCE90F5F0,0x03051000)

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

DEF_API(`void',`CDECL',`eventpostbyevent',`(eventpostbyevent_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xA33BD23D),0x03051000)

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

DEF_API(`void',`CDECL',`eventpostbyevent2',`(eventpostbyevent2_struct *p)',1,0x61F1EA28,0x03051000)

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

DEF_API(`void',`CDECL',`eventregistercallback',`(eventregistercallback_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x5EF9AC91),0x03051000)

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

DEF_API(`void',`CDECL',`eventregistercallback2',`(eventregistercallback2_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x95D8F44C),0x03051000)

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

DEF_API(`void',`CDECL',`eventregistercallbackfunction',`(eventregistercallbackfunction_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x989C8BB3),0x03051000)

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

DEF_API(`void',`CDECL',`eventregistercallbackfunction2',`(eventregistercallbackfunction2_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xBD946DD7),0x03051000)

/**
 * Returns the number of registered callbacks on the event 
 */
typedef struct tageventregisteredcallbacks_struct
{
	RTS_IEC_HANDLE hEvent;				/* VAR_INPUT */	/* Event handle */
	RTS_IEC_RESULT *Result;	/* VAR_IN_OUT */	/* Error code */
	RTS_IEC_UDINT EventRegisteredCallbacks;	/* VAR_OUTPUT */	/* Returns the number of registered callbacks on the event */
} eventregisteredcallbacks_struct;

DEF_API(`void',`CDECL',`eventregisteredcallbacks',`(eventregisteredcallbacks_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xC4EA0B3B),0x03051000)

/**
 * Unregister a callback interface from an event specified by handle and callback interface 
 */
typedef struct tageventunregistercallback_struct
{
	RTS_IEC_HANDLE hEvent;				/* VAR_INPUT */	/* Event handle */
	RTS_IEC_HANDLE hInterface;			/* VAR_INPUT */	/* Callback handle is returned by EventRegisterCallback() or EventRegisterCallback2()!!! */
	RTS_IEC_RESULT EventUnregisterCallback;	/* VAR_OUTPUT */	/* Error code */
} eventunregistercallback_struct;

DEF_API(`void',`CDECL',`eventunregistercallback',`(eventunregistercallback_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x80238B4F),0x03051000)

/**
 * Unregister a callback function from an event specified by handle and callback 
 */
typedef struct tageventunregistercallbackfunction_struct
{
	RTS_IEC_HANDLE hEvent;				/* VAR_INPUT */	/* Handle to event */
	RTS_IEC_BYTE *pfCallbackFunction;	/* VAR_INPUT */	/* Address of callback function. Function pointer is retrieved by the ADR operator: ADR(function) */
	RTS_IEC_RESULT EventUnregisterCallbackFunction;	/* VAR_OUTPUT */	/* Error code */
} eventunregistercallbackfunction_struct;

DEF_API(`void',`CDECL',`eventunregistercallbackfunction',`(eventunregistercallbackfunction_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x5E0DD5BD),0x03051000)

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

DEF_API(`void',`CDECL',`eventunregistercallbackfunction2',`(eventunregistercallbackfunction2_struct *p)',1,0x779853A9,0x03051000)

#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/

