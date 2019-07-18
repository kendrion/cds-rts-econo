 
	
	
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
} ICmpEconoTemplate_C;

#ifdef CPLUSPLUS
class ICmpEconoTemplate : public IBase
{
	public:
};
	#ifndef ITF_CmpEconoTemplate
		#define ITF_CmpEconoTemplate static ICmpEconoTemplate *pICmpEconoTemplate = NULL;
	#endif
	#define EXTITF_CmpEconoTemplate
#else	/*CPLUSPLUS*/
	typedef ICmpEconoTemplate_C		ICmpEconoTemplate;
	#ifndef ITF_CmpEconoTemplate
		#define ITF_CmpEconoTemplate
	#endif
	#define EXTITF_CmpEconoTemplate
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_CMPTEMPLATEEMPTYITF_H_*/
