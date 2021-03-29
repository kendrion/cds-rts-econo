/*****************************************************************************
*
*	Copyright:		© 3S - Smart Software Solutions GmbH, Kempten
*	Program:		Runtime System for the CoDeSys Soft-Plc
*	Component: 		Main.c
*	Version:
*	Description:
******************************************************************************/

#include "CmpStd.h"
#include "CMItf.h"
#include "CmpErrors.h"
#include "CmpItf.h"
#include "SysTaskItf.h"

COMPO_INIT_DECLS

#ifndef RTS_SLEEP_MS
	#define RTS_SLEEP_MS	Sleep
#endif

static StaticComponent s_ComponentList[] = {
	COMPO_INIT_LIST
};

static int s_bExitLoop;
static char s_szComponentFile[256];

int main(void)
{
	RTS_RESULT Result;

	strncpy(s_szComponentFile, RTS_CONFIGURATION_FILE, MIN(sizeof(s_szComponentFile), strlen(RTS_CONFIGURATION_FILE) + 1));
	s_szComponentFile[sizeof(s_szComponentFile) - 1] = '\0';

	s_bExitLoop = 0;

    /* With the option RTS_CMINIT_OPTION_STD you can specify, that all CH_INIT_XXX, CH_EXIT_XXX and CH_COMM_CYCLE hooks are called out of a SysTask! */
    Result = CMInit3(s_szComponentFile, s_ComponentList, 0);

	if (Result == ERR_OK || (Result != ERR_ID_MISMATCH && Result != ERR_LICENSE_MISSING))
	{
		while (!RTS_OS_KEYPRESSED && !s_bExitLoop && !CMGetExit())
		{           
            if (CMIsOptionSupported(RTS_CMINIT_OPTION_COMMCYCLETASK) != ERR_OK)
                CMCallHook(CH_COMM_CYCLE, 0, 0, FALSE);

			RTS_SLEEP_MS(100);
		}
	}
	else
	{
		if (Result == ERR_ID_MISMATCH)
			printf("*** ERROR: CMInit() returns %ld: Detected a signature mismatch for the SysTarget IDs!\n", Result);
		else
			printf("*** ERROR: CMInit() returns %ld!\n", Result);
	}

	printf("MainLoop exit received...\n");

	CMExit();

#ifdef RTS_DEBUG
	getchar();
	getchar();
#endif

	printf("MainLoop exit done\n");
	return 0;
}

int PlcExit(void)
{
	s_bExitLoop = 1;
	return ERR_OK;
}

int MainExitLoop(RTS_UINTPTR ulPar)
{
	s_bExitLoop = 1;
	return ERR_OK;
}

RTS_RESULT CDECL MainLoadComponent(char *pszName, char *pszPath, RTS_HANDLE *phModule, PF_COMPONENT_ENTRY* ppfComponentEntry)
{
	return ERR_FAILED;
}

RTS_RESULT CDECL MainUnloadComponent(char *pszName, RTS_HANDLE hModule)
{
	return ERR_FAILED;
}
