 
	
	
#ifndef _CMPECONOIECSTATUSCONTROLITF_H_
#define _CMPECONOIECSTATUSCONTROLITF_H_

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
} ICmpEconoIECStatusControl_C;

#ifdef CPLUSPLUS
class ICmpEconoIECStatusControl : public IBase
{
	public:
};
	#ifndef ITF_CmpEconoIECStatusControl
		#define ITF_CmpEconoIECStatusControl static ICmpEconoIECStatusControl *pICmpEconoIECStatusControl = NULL;
	#endif
	#define EXTITF_CmpEconoIECStatusControl
#else	/*CPLUSPLUS*/
	typedef ICmpEconoIECStatusControl_C		ICmpEconoIECStatusControl;
	#ifndef ITF_CmpEconoIECStatusControl
		#define ITF_CmpEconoIECStatusControl
	#endif
	#define EXTITF_CmpEconoIECStatusControl
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_CMPECONOIECSTATUSCONTROLITF_H_*/
