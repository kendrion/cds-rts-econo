 
	
	
#ifndef _CMPTEMPLATEEMPTYITF_H_
#define _CMPTEMPLATEEMPTYITF_H_

#include "CmpStd.h"

 

 




#include "CmpItf.h"


/** EXTERN LIB SECTION BEGIN **/

/** EXTERN LIB SECTION END **/


#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif



typedef struct
{
	IBase_C *pBase;
} IIoDrvEcono_C;

#ifdef CPLUSPLUS
class IIoDrvEcono : public IBase
{
	public:
};
	#ifndef ITF_IoDrvEcono
		#define ITF_IoDrvEcono static IIoDrvEcono *pIIoDrvEcono = NULL;
	#endif
	#define EXTITF_IoDrvEcono
#else	/*CPLUSPLUS*/
	typedef IIoDrvEcono_C		IIoDrvEcono;
	#ifndef ITF_IoDrvEcono
		#define ITF_IoDrvEcono
	#endif
	#define EXTITF_IoDrvEcono
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_CMPTEMPLATEEMPTYITF_H_*/
