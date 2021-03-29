/**
 * <interfacename>CmpPCANBasicDrv</interfacename>
 * <description>
 *	Interface of the Peak CAN basic driver component.
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`CmpPCANBasicDrv')

#include "CmpItf.h"
#include "CAATypes.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _pcanhwinfotag_
{
	char szName[32];
	CAA_DWORD dwDeviceNumber;
	RTS_UI16 PCANHandle;
	CAA_BYTE byCANControllerNumber; /*0 for CAN0, 1 for CAN1,...*/
	CAA_BOOL xOpened;
	CAA_BOOL bTxError;
}PCAN_HW_INFO;

typedef struct _pcaninfotag_
{
	RTS_HANDLE hSem;
	PCAN_HW_INFO hwInfo;
	CAA_WORD wBaudrate;
	unsigned long reset_current;
	unsigned long reset_last;

}PCAN_INFO;

#ifdef __cplusplus
}
#endif
