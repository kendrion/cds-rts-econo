/**
 * <name>RtsAsyncOperation.c</name>
 * <description> 
 *	Example to execute a job asynchronously.
 *
 *	USAGE:
 *		- CH_COMM_CYCLE: call CyclicAsyncOperation(void)() from your component hook function
 * </description>
 *
 *  Copyright (c) 2017-2019 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 */

#include "CmpStd.h"
#include "CmpAsyncMgrItf.h"


typedef struct
{
	RTS_HANDLE hJob;
	ASYNCJOB_PARAM *pAsyncMgrJobParams;
	RTS_UI32 *pState;
	RTS_RESULT Result;
} AsyncStruct;

static RTS_UI32 s_state = ASYNCSTATE_INVALID;
static AsyncStruct *s_pParameter = NULL;

static void CDECL AsyncHandler(RTS_HANDLE hParam)
{
	AsyncStruct *pParameter = (AsyncStruct *)hParam;
	pParameter->Result = ERR_OK;

	CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_DEBUG, ERR_OK, 0, "RtsAsyncOperation: Async job executed!");
}

static RTS_RESULT CDECL CreateAsyncJob(AsyncStruct *pParameter)
{
	RTS_RESULT Result = ERR_OK;
	if (CHK_AsyncAdd2)
	{
		ASYNCJOB_PARAM *pjobParams;
		ASYNCJOB_INFO2 job;

		pjobParams = (ASYNCJOB_PARAM *)CAL_SysMemAllocData(COMPONENT_NAME, sizeof(ASYNCJOB_PARAM), NULL);
		pjobParams->tTaskParam.pszTaskname = "AsyncTask";
		pjobParams->tTaskParam.ulTaskpriority = TASKPRIO_MIN;
		pjobParams->tTaskParam.ulTaskSleepTime = 0;
		pjobParams->tTaskParam.hTaskHandle = RTS_INVALID_HANDLE;
		pjobParams->tTaskParam.bEndTaskAfterJob = 1;

		memset(&job, 0, sizeof(job));
		job.pfJob = AsyncHandler;
		job.pParam = pParameter;
		job.pInstance = 0;
		job.pulState = pParameter->pState;
		job.bIecFunc = 0;
		job.ulType = ASYNCJOB_TASK;
		job.ulTimeout = 0;
		job.pJobParam = pjobParams;
		job.pfExceptionHandler = NULL;
		job.phJob = &pParameter->hJob;

		pParameter->Result = ERR_PENDING;
		pParameter->pAsyncMgrJobParams = pjobParams;

		Result = CAL_AsyncAdd2(&job);
		if (Result != ERR_OK)
			return Result;
		return ERR_PENDING;
	}
	return ERR_NOT_SUPPORTED;
}

/**
 * <description>Function to poll cyclically the state of the run/stop switch and to react correctly.
 *	USAGE:
 *	- Must be cyclically. Can be called e.g. from CH_COMM_CYCLE.
 * </description> 
 * <result>error code</result>
 */
static RTS_RESULT CDECL CyclicAsyncOperation(void)
{
	switch (s_state)
	{
		case ASYNCSTATE_INVALID:
		{
			static RTS_BOOL s_bDoOnlyOnce = TRUE;
			if (s_bDoOnlyOnce)
			{
				s_bDoOnlyOnce = FALSE;

				s_pParameter = (AsyncStruct *)CAL_SysMemAllocData(COMPONENT_NAME, sizeof(AsyncStruct), NULL);
				memset(s_pParameter, 0, sizeof(s_pParameter));
				s_pParameter->pState = &s_state;

				CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_DEBUG, ERR_OK, 0, "RtsAsyncOperation: Async job start...");
				CreateAsyncJob(s_pParameter);
			}
			break;
		}
		case ASYNCSTATE_READY:
		{
			CAL_SysMemFreeData(COMPONENT_NAME, s_pParameter->pAsyncMgrJobParams);
			CAL_SysMemFreeData(COMPONENT_NAME, s_pParameter);

			CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_DEBUG, ERR_OK, 0, "RtsAsyncOperation: Async job done");

			s_state = ASYNCSTATE_INVALID;
			break;
		}
		default:
			break;
	}
	return ERR_OK;
}

