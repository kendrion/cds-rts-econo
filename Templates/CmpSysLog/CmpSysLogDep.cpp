/***********************************************************************
 * DO NOT MODIFY!
 * This is a generated file. Do not modify it's contents directly
 ***********************************************************************/






#include "CmpSysLog.c"









RTS_HANDLE CDECL CCmpSysLog::ILogBackendCreate(RTS_HANDLE hICmpLogBackend, CLASSID ClassId, struct tagLogOptions *pOptions)
{
	hCmpSysLog = LogBackendCreate(hICmpLogBackend,ClassId,pOptions);
	RTS_HANDLE h = (RTS_HANDLE)QueryInterface((IBase *)(ICmpLogBackend *)this, ITFID_ICmpLogBackend, NULL);
	Release();
	return h;
}

RTS_RESULT CDECL CCmpSysLog::ILogBackendDelete(void)
{
	RTS_RESULT Result = LogBackendDelete(hCmpSysLog);
	DeleteInstance((IBase *)(ICmpLogBackend *)this);
	return Result;
}

RTS_HANDLE CDECL CCmpSysLog::ILogBackendAdd(struct tagLogOptions *pOptions, struct tagLogEntry *pLog, RTS_RESULT *pResult)
{
	hCmpSysLog = LogBackendAdd(hCmpSysLog,pOptions,pLog,pResult);
	return hCmpSysLog;
}






