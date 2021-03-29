 /**
 * <interfacename>CmpIxxatCANDrv</interfacename>
 * <description> 
 *	Interface of the Ixxat CAN driver.
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */


	
	
#ifndef _CMPIXXATCANDRVITF_H_
#define _CMPIXXATCANDRVITF_H_

#include "CmpStd.h"

 

 




#include "CmpItf.h"
#include "CAATypes.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif



typedef struct
{
	IBase_C *pBase;
} ICmpIxxatCANDrv_C;

#ifdef CPLUSPLUS
class ICmpIxxatCANDrv : public IBase
{
	public:
};
	#ifndef ITF_CmpIxxatCANDrv
		#define ITF_CmpIxxatCANDrv static ICmpIxxatCANDrv *pICmpIxxatCANDrv = NULL;
	#endif
	#define EXTITF_CmpIxxatCANDrv
#else	/*CPLUSPLUS*/
	typedef ICmpIxxatCANDrv_C		ICmpIxxatCANDrv;
	#ifndef ITF_CmpIxxatCANDrv
		#define ITF_CmpIxxatCANDrv
	#endif
	#define EXTITF_CmpIxxatCANDrv
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_CMPIXXATCANDRVITF_H_*/
