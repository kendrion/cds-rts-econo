 /**
 * <interfacename>test</interfacename>
 * <description></description>
 *
 * <copyright></copyright>
 */


	
	
#ifndef _IODRVSIMPLEITF_H_
#define _IODRVSIMPLEITF_H_

#include "CmpStd.h"

 

 




/** EXTERN LIB SECTION BEGIN **/

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/




typedef struct
{
	IBase_C *pBase;
} IIoDrvSimple_C;

#ifdef CPLUSPLUS
class IIoDrvSimple : public IBase
{
	public:
};
	#ifndef ITF_IoDrvSimple
		#define ITF_IoDrvSimple static IIoDrvSimple *pIIoDrvSimple = NULL;
	#endif
	#define EXTITF_IoDrvSimple
#else	/*CPLUSPLUS*/
	typedef IIoDrvSimple_C		IIoDrvSimple;
	#ifndef ITF_IoDrvSimple
		#define ITF_IoDrvSimple
	#endif
	#define EXTITF_IoDrvSimple
#endif

#ifdef CPLUSPLUS_ONLY
  #undef CPLUSPLUS_ONLY
#endif

#endif /*_IODRVSIMPLEITF_H_*/
