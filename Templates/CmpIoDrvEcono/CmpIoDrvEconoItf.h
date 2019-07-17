 
	
	
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
} ICmpIoDrvEcono_C;

#ifdef CPLUSPLUS
class ICmpIoDrvEcono : public IBase
{
	public:
};
	#ifndef ITF_CmpIoDrvEcono
		#define ITF_CmpIoDrvEcono static ICmpIoDrvEcono *pICmpIoDrvEcono = NULL;
	#endif
	#define EXTITF_CmpIoDrvEcono
#else	/*CPLUSPLUS*/
	typedef ICmpIoDrvEcono_C		ICmpIoDrvEcono;
	#ifndef ITF_CmpIoDrvEcono
		#define ITF_CmpIoDrvEcono
	#endif
	#define EXTITF_CmpIoDrvEcono
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_CMPTEMPLATEEMPTYITF_H_*/
