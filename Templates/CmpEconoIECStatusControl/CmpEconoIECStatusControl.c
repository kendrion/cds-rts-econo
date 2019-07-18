/**
 * <name>CmpEconoIECStatusControl.c</name>
 * <description> 
 *  Component controls states of IEC application Run, Stop, Breakpoint.
 *	
 *	LEDS:
 *	Green: CODESYS Application is running.
 *	Red: CODESYS Application is stopped
 *	Yellow: CODESYS Application is stopped on breakpoint.
 * 	
 *	Start/Stop button switches application to Run/Stop mode.
 * </description>
 *
 * <copyright>(c) 2019 Kendrion</copyright>
 *
 *	Code styling rules: 
 *	https://www.kernel.org/doc/html/latest/process/coding-style.html
 */

#include "CmpStd.h"
#include "CmpEconoIECStatusControlDep.h"

USE_STMT

static RTS_I32 s_bRun = 1;
static RTS_HANDLE s_hEventRSSDenyStart = RTS_INVALID_HANDLE;

static RTS_RESULT CDECL InitRunStopSwitch(void);
static RTS_RESULT CDECL ExitRunStopSwitch(void);
static RTS_RESULT CDECL CyclicRunStopSwitch(void);
static void CDECL CBDenyStart(EventParam *pEventParam);
static RTS_I32 PollRunStopSwitch(void);

/**
 * <description>Entry function of the component. Called at startup for each
 * component. Used to exchange function pointers with the component manager.
 * For more information look at CmpTemplate.
 * </description>
 * <result>ERR_OK if component could be initialized, else error code.</result>
 */
DLL_DECL int CDECL ComponentEntry(INIT_STRUCT *pInitStruct)
{
	pInitStruct->CmpId = COMPONENT_ID;
	pInitStruct->pfExportFunctions = ExportFunctions;
	pInitStruct->pfImportFunctions = ImportFunctions;
	pInitStruct->pfGetVersion = CmpGetVersion;
	pInitStruct->pfHookFunction = HookFunction;
	pInitStruct->pfCreateInstance = NULL;
	pInitStruct->pfDeleteInstance = NULL;

	s_pfCMRegisterAPI = pInitStruct->pfCMRegisterAPI;
	s_pfCMRegisterAPI2 = pInitStruct->pfCMRegisterAPI2;
	s_pfCMGetAPI = pInitStruct->pfCMGetAPI;
	s_pfCMGetAPI2 = pInitStruct->pfCMGetAPI2;
	s_pfCMCallHook = pInitStruct->pfCMCallHook;
	s_pfCMRegisterClass = pInitStruct->pfCMRegisterClass;
	s_pfCMCreateInstance = pInitStruct->pfCMCreateInstance;
	return ERR_OK;
}

/**
 * <description>Publish exported functions to the component manager, to make
 * them available for other components.
 * Use generated macro EXPORT_STMT.</description>
 * <result>ERR_OK or error code in case of error</result>
 */
static int CDECL ExportFunctions(void)
{
	/* Macro to export functions */
	EXPORT_STMT;
	return ERR_OK;
}

/**
 * <description>Import function pointers from other components. Use generated
 * macro IMPORT_STMT.</description>
 * <result>ERR_OK or error code if function name could not be resolved</result>
 */
static int CDECL ImportFunctions(void)
{
	/* Macro to import functions */
	IMPORT_STMT;
	return ERR_OK;
}

/**
 * <description>Return the version of our component.</description>
 * <result>Version as defined in dep file</result>
 */
static RTS_UI32 CDECL CmpGetVersion(void)
{
	return CMP_VERSION;
}


/**
 * <description>Hook function to get all broadcast hooks of the component
 * manager. All init and exit stuff must be implemented here!</description>
 * <param name="ulHook" type="IN">Kind of hook. See CH_ definitions in CmpItf.h
 * for details.</param> 
 * <param name="ulParam1" type="IN">Hook specific first parameter. See
 * definitions in CmpItf.h for details.</param> 
 * <param name="ulParam2" type="IN">Hook specific second parameter. See
 * definitions in CmpItf.h for details.</param>  
 * <result>Error code</result>
 */
static RTS_RESULT CDECL HookFunction(RTS_UI32 ulHook, RTS_UINTPTR ulParam1,
					RTS_UINTPTR ulParam2)
{
	switch (ulHook) {
	case CH_INIT:
		break;
	case CH_INIT2:
		break;
	case CH_INIT3:
		InitRunStopSwitch();
		break;
	case CH_INIT_TASKS:
		break;
	case CH_INIT_COMM:
		break;
	case CH_INIT_FINISHED:
		break;

	/* Cyclic */
	case CH_COMM_CYCLE:
		CyclicRunStopSwitch();
		break;

	case CH_EXIT_COMM:
		break;
	case CH_EXIT_TASKS:
		break;
	case CH_EXIT3:
		ExitRunStopSwitch();
		break;
	case CH_EXIT2:
		break;
	case CH_EXIT:
		EXIT_STMT;
		break;


	default:
		break;
	}
	return ERR_OK;
}

/**
 * <description>Function to init Run/Stop functionality at startup of the
 * runtime system.
 *	USAGE:
 *	- Must be called in CH_INIT3 out of component HookFunction()!
 * </description>
 * <result>error code</result>
 */
static RTS_RESULT CDECL InitRunStopSwitch(void)
{

	RTS_RESULT Result;

	s_hEventRSSDenyStart = CAL_EventOpen(EVT_DenyStart, CMPID_CmpApp,
					     &Result);
	CAL_EventRegisterCallbackFunction(s_hEventRSSDenyStart, CBDenyStart, 0);
	return ERR_OK;
}

/**
 * <description>
 * Function to exit Run/Stop functionality code at shutdown of the runtime
 * system.
 *	USAGE:
 *	- Must be called in CH_EXIT3 out of component HookFunction()!
 * </description> 
 * <result>error code</result>
 */
static RTS_RESULT CDECL ExitRunStopSwitch(void)
{

	CAL_EventUnregisterCallbackFunction(s_hEventRSSDenyStart, CBDenyStart);
	CAL_EventClose(s_hEventRSSDenyStart);
	s_hEventRSSDenyStart = RTS_INVALID_HANDLE;
	return ERR_OK;
}

/**
 * <description>
 * Function to poll cyclically the state of the run/stop switch and to react
 * correctly.
 *	USAGE:
 *	- Must be cyclically. Can be called e.g. from CH_COMM_CYCLE.
 * </description> 
 * <result>error code</result>
 */
static RTS_RESULT CDECL CyclicRunStopSwitch(void)
{
	RTS_I32 state = PollRunStopSwitch();
	if (state != s_bRun) {
		if (state)
			CAL_AppStartApplications();
		else
			CAL_AppStopApplications(RTS_TIMEOUT_DEFAULT,
						APP_STOP_REASON_RUNSTOP_SWITCH);
	}
	s_bRun = state;
	return ERR_OK;
}

/**
 * <description>
 * Callback function to prevent from starting applications, if switch is in STOP
 * position!
 * <param name="pEventParam" type="IN">Pointer to event parameter set.</param>  
 * <result></result>
 */
static void CDECL CBDenyStart(EventParam *pEventParam)
{
	EVTPARAM_CmpAppDenyStart *pParam;
	if (pEventParam->CmpIdProvider == CMPID_CmpApp) {
		switch (pEventParam->EventId) {
		case EVT_DenyStart:
			pParam =
			    (EVTPARAM_CmpAppDenyStart *)pEventParam->pParameter;
			
			if (!PollRunStopSwitch())
				pParam->bDeny = 1;
			break;
		default:
			break;
		}
	}
}

/**
 * <description>
 * Function to get the actual state of the run/stop switch. Is called cyclically
 * from CyclicRunStopSwitch().
 * </description> 
 * <result>
 *  0 = switch is in stop state
 *  1 = switch is in run state
 * </result>
 */
static RTS_I32 PollRunStopSwitch(void)
{
	/*
	* Poll the state of the run stop switch:
	* return 1: switch is in run
	* return 0: switch is in stop
	*/	
	
	static RTS_I32 s_bRunStopSwitch = 1;
	/* Here you can simulate the state of the RunStop switch by writing the
	value of s_bRunStopSwitch in debugger. */
	return s_bRunStopSwitch;
}

