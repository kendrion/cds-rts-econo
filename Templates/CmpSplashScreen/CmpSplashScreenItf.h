 
	
	
#ifndef _CMPSPLASHSCREENITF_H_
#define _CMPSPLASHSCREENITF_H_

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
} ICmpSplashScreen_C;

#ifdef CPLUSPLUS
class ICmpSplashScreen : public IBase
{
	public:
};
	#ifndef ITF_CmpSplashScreen
		#define ITF_CmpSplashScreen static ICmpSplashScreen *pICmpSplashScreen = NULL;
	#endif
	#define EXTITF_CmpSplashScreen
#else	/*CPLUSPLUS*/
	typedef ICmpSplashScreen_C		ICmpSplashScreen;
	#ifndef ITF_CmpSplashScreen
		#define ITF_CmpSplashScreen
	#endif
	#define EXTITF_CmpSplashScreen
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_CMPSPLASHSCREENITF_H_*/
