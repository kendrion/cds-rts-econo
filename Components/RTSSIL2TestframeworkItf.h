/**
 * <copyright>
 * Copyright (c) 2019-2019 CODESYS Development GmbH. All rights reserved.
 * </copyright>
 *
 * <interfacename>RTSSIL2Testframework</interfacename>
 * <description> 
 * <p>Interface for SIL2 moduletest framework</p>
 * </description>
 *
 */

#ifndef _RTSSIL2TESTFRAMEWORK_H_
#define _RTSSIL2TESTFRAMEWORK_H_


/* --------------------------------------
 * Module includes
 * -------------------------------------- */

//CmpStd required for return types etc.
#include "CmpStd.h"

//SysTimerItf required for PFTIMERCALLBACK
#include "SysTimerItf.h"

/* --------------------------------------
 * Macros and constants
 * -------------------------------------- */

/* Exception codes to differentiate between:
 * SIL2-Safe Mode, Generic Soft Exceptions and CPU Exceptions.
 */
#define RTS_TEST_EXCEPT_SAFE 0x0001
#define RTS_TEST_EXCEPT_SOFT 0x0002
#define RTS_TEST_EXCEPT_CPU  0x0003


/* --------------------------------------
 * Types
 * -------------------------------------- */

/*	framework typedefinitions	*/
typedef RTS_RESULT (CDECL *PF_TESTENTRY)(unsigned int uiTestcase);

typedef struct Test_s {
	const char * pszName;
	int iCriticality;
	PF_TESTENTRY pfEntry;
} Test_t;

typedef struct Testset_s {
	const char * pszName;
} Testset_t;

 
/* --------------------------------------
 * Function prototypes
 * -------------------------------------- */

RTS_RESULT CDECL CDSTestFrameworkStart(Testset_t *pTestset);
RTS_RESULT CDECL CDSTestFrameworkRun(const Test_t *pTest, unsigned int uiTestCnt);
RTS_RESULT CDECL CDSTestFrameworkRunSingleTest(const Test_t *pTest);
RTS_RESULT CDECL CDSTryFunc(PFTIMERCALLBACK pfTimerCallback, RTS_HANDLE hParam);
RTS_RESULT CDECL CDSTestFrameworkExit(Testset_t* pTestset);

void CDECL CDSTestFrameworkMarkTestsetFail(void);

RTS_RESULT CDECL CDSTestFrameworkLogAddEntry(const char* pszInfo,...);
RTS_RESULT CDECL CDSTestFrameworkLogAddError(const char* pszInfo,...);
RTS_RESULT CDECL CDSTestFrameworkLogAddData(unsigned int iTag, const char *pszInfo, ...);

RTS_RESULT CDECL CDSTestFrameworkOut(const char *pbyBuffer);
RTS_RESULT CDECL CDSTestFrameworkOutFlush(const char *pszName);
RTS_RESULT CDECL CDSTestFrameworkOutData(const char *pbyBuffer, int iLen);

RTS_RESULT CDECL CDSTestFrameworkException(RTS_UI32 uiExceptionCode);
RTS_UI32   CDECL CDSTestFrameworkGetLastException(void);

#endif /* _RTSSIL2TESTFRAMEWORK_H_ */
