/**
 * <name>RtsExternalIECEventTasks.c</name>
 * <description> 
 *	Example to provide external IEC events / external IEC event triggered tasks.
 *
 *	USAGE:
 *	- InitExternalIECEventTasks(CH_INIT3) must be called out of CH_INIT3 hook	
 *	- InitExternalIECEventTasks(CH_INIT_TASKS) must be called out of CH_INIT_TASKS hook
 *	- ExitExternalIECEventTasks(CH_EXIT_TASKS) must be called out of CH_EXIT_TASKS hook	
 *	- ExitExternalIECEventTasks(CH_EXIT3) must be called out of CH_EXIT3 hook
 *
 *  Snipped for the device description to specify the external event:
 *
 *		<DeviceDescription xmlns="http://www.3s-software.com/schemas/DeviceDescription-1.0.xsd">
 *			<Device>
 *				<ExtendedSettings>
 *					<ts:TargetSettings xmlns:ts="http://www.3s-software.com/schemas/TargetSettings-0.1.xsd">
 *						<ts:section name="taskconfiguration">
 *							<ts:setting name="supportexternal" type="boolean" access="visible">
 *								<ts:value>1</ts:value>
 *							</ts:setting>
 *							<ts:setting name="maxexternalevents" type="integer" access="visible">
 *								<ts:value>1</ts:value>
 *							</ts:setting>
 *							<ts:setting name="externalevents" type="cdata" access="hidden">
 *								<ts:value><![CDATA[
 *								  <externalevents>
 *									  <externalevent>
 *										  <name>MyEvent</name>
 *									  </externalevent>
 *								  </externalevents>
 *								]]></ts:value>
 *							</ts:setting>
 *						</ts:section>
 *					</ts:TargetSettings>
 *				</ExtendedSettings>
 *			</Device>
 *		</DeviceDescription>
 *
 * </description>
 *
 * <copyright>(c) 2003-2019 3S-Smart Software Solutions</copyright>
 */
#include "CmpStd.h"
#include "CmpTemplateDep.h"

/* TODO: Compiler define to enable synchronization against IEC tasks: */
/* #define CMPTEMPLATE_SYNCHRONIZE_WITH_EXTERNAL_TASK */

static RTS_HANDLE s_hExternalEventTask = RTS_INVALID_HANDLE; 
static RTS_HANDLE s_hMyEventTask = RTS_INVALID_HANDLE;
static RTS_HANDLE s_hEventAfterReadingInputs = RTS_INVALID_HANDLE;
static RTS_HANDLE s_hEventBeforeWritingOutputs = RTS_INVALID_HANDLE;
#ifdef CMPTEMPLATE_SYNCHRONIZE_WITH_EXTERNAL_TASK
	static RTS_HANDLE s_hEvent = RTS_INVALID_HANDLE;
	static RTS_HANDLE s_hSem = RTS_INVALID_HANDLE;
#endif

static void CDECL MyEventTask(SYS_TASK_PARAM *ptp);
static void CDECL CBEventIecTasks(EventParam *pEventParam);

#define MY_EXTERNAL_EVENT_NAME		"MyEvent"

/**
 * <description>Function to register the external event by name.
 *	USAGE:
 *	- Must be called in CH_INIT3 and CH_INIT_TASKS out of component HookFunction()!
 * </description>
 * <result>error code</result>
 */
static RTS_RESULT CDECL InitExternalIECEventTasks(RTS_UI32 ulHook)
{
	RTS_RESULT result;

	if (ulHook == CH_INIT3)
	{
		/* TODO: Here the external event(s) are registered.
				 Specify the name(s) of the external event(s). */
		s_hExternalEventTask = CAL_SchedRegisterExternalEvent(MY_EXTERNAL_EVENT_NAME, NULL);

		/* TODO: This is optional and an example to get a callback in "our" external event task after reading inputs and before writing outputs! */
		s_hEventAfterReadingInputs = CAL_EventOpen(EVT_AfterReadingInputs, CMPID_CmpIecTask, NULL);
		s_hEventBeforeWritingOutputs = CAL_EventOpen(EVT_BeforeWritingOutputs, CMPID_CmpIecTask, NULL);
		CAL_EventRegisterCallbackFunction(s_hEventAfterReadingInputs, CBEventIecTasks, 0);
		CAL_EventRegisterCallbackFunction(s_hEventBeforeWritingOutputs, CBEventIecTasks, 0);

#ifdef CMPTEMPLATE_SYNCHRONIZE_WITH_EXTERNAL_TASK
		if (CHK_SysEventCreate && CHK_SysSemCreate)
		{
			s_hEvent = CAL_SysEventCreate(NULL, NULL);
			s_hSem = CAL_SysSemCreate(NULL);
		}
#endif
	}
	else if (ulHook == CH_INIT_TASKS)
	{
		/* TODO: Here we setup a task to simulate the external event trigger */
		s_hMyEventTask = CAL_SysTaskCreate(MY_EXTERNAL_EVENT_NAME "Task", MyEventTask, NULL, TASKPRIO_REALTIME_BASE, 0, 0, 0, &result);
		result = CAL_SysTaskResume(s_hMyEventTask);
	}
	return ERR_OK;
}

/**
 * <description>Function to unregister the external event
 *	USAGE:
 *	- Must be called in CH_EXIT3 and CH_EXIT_TASKS out of component HookFunction()!
 * </description> 
 * <result>error code</result>
 */
static RTS_RESULT CDECL ExitExternalIECEventTasks(RTS_UI32 ulHook)
{
	if (ulHook == CH_EXIT_TASKS)
	{
		if (s_hMyEventTask != RTS_INVALID_HANDLE)
		{
			/* TODO: Here we shutdown the task to simulate the external event trigger */
			CAL_SysTaskSetExit(s_hMyEventTask);
			CAL_SysTaskExit(s_hMyEventTask, 1000);
			s_hMyEventTask = RTS_INVALID_HANDLE;
		}
	}
	else if(ulHook == CH_EXIT3)
	{
#ifdef CMPTEMPLATE_SYNCHRONIZE_WITH_EXTERNAL_TASK
		if (CHK_SysEventDelete && CHK_SysSemDelete)
		{
			CAL_SysEventDelete(s_hEvent);
			CAL_SysSemDelete(s_hSem);
		}
#endif

		/* TODO: Here the external event(s) are unregistered. */
		CAL_SchedUnregisterExternalEvent(s_hExternalEventTask);
		s_hExternalEventTask = RTS_INVALID_HANDLE;

		/* TODO: This is optional and an example to get a callback in "our" external event task after reading inputs and before writing outputs! */
		CAL_EventUnregisterCallbackFunction(s_hEventAfterReadingInputs, CBEventIecTasks);
		CAL_EventUnregisterCallbackFunction(s_hEventBeforeWritingOutputs, CBEventIecTasks);
		s_hEventAfterReadingInputs = RTS_INVALID_HANDLE;
		s_hEventBeforeWritingOutputs = RTS_INVALID_HANDLE;
	}
	return ERR_OK;
}

/**
 * <description>Function to post/trigger the external event.
 *	USAGE:
 *	- Must be called out of your external event context (interrupt, system task, etc.).
 * </description> 
 */
static void CDECL MyEventTask(SYS_TASK_PARAM *ptp)
{
	RTS_RESULT result;

	CAL_SysTaskEnter(ptp->hTask);

	while (!ptp->bExit)
	{
		result = CAL_SchedPostExternalEvent(s_hExternalEventTask);
		if (result == ERR_OK)
		{
#ifdef CMPTEMPLATE_SYNCHRONIZE_WITH_EXTERNAL_TASK
			if (s_hSem != RTS_INVALID_HANDLE && s_hEvent != RTS_INVALID_HANDLE)
			{
				/* TODO: Synchronization against IEC task can be done here: */
				CAL_SysSemEnter(s_hSem);
				if (CAL_SysEventWait(s_hEvent, 1000) == ERR_OK)
				{
					/* TODO: Add synchronized code here */
				}
				CAL_SysSemLeave(s_hSem);
			}
#endif
		}
		CAL_SysTaskWaitSleep(ptp->hTask, 10);
	}

	CAL_SysTaskLeave(ptp->hTask);
	CAL_SysTaskEnd(ptp->hTask, 0);
}


/**
 * <description>
 *	Callback: This is optional and an example to get a callback in the external event task after reading inputs and before writing outputs!
 * </description> 
 */
static void CDECL CBEventIecTasks(EventParam *pEventParam)
{
	EVTPARAM_CmpIecTask *pParam = (EVTPARAM_CmpIecTask *)pEventParam->pParameter;

	switch (pEventParam->EventId)
	{
		case EVT_AfterReadingInputs:
		{
			if (pParam->pTaskDesc->pInfo->KindOfTask == TaskExternal && 
				pParam->pTaskDesc->pInfo->pszExternalEvent != NULL && 
				strcmp(pParam->pTaskDesc->pInfo->pszExternalEvent, MY_EXTERNAL_EVENT_NAME) == 0)
			{
				/* TODO: This is the IEC task which is triggered by our external event! */
			}
			break;
		}
		case EVT_BeforeWritingOutputs:
		{
			if (pParam->pTaskDesc->pInfo->KindOfTask == TaskExternal &&
				pParam->pTaskDesc->pInfo->pszExternalEvent != NULL &&
				strcmp(pParam->pTaskDesc->pInfo->pszExternalEvent, MY_EXTERNAL_EVENT_NAME) == 0)
			{			
#ifdef CMPTEMPLATE_SYNCHRONIZE_WITH_EXTERNAL_TASK
				/* TODO: This is the IEC task which is triggered by our external event! */
				if (s_hSem != RTS_INVALID_HANDLE && s_hEvent != RTS_INVALID_HANDLE)
				{
					CAL_SysEventSet(s_hEvent);
					CAL_SysSemEnter(s_hSem);
					CAL_SysSemLeave(s_hSem);
				}
#endif
			}
			break;
		}
		default:
			break;
	}
}
