SET_INTERFACE_NAME(`CmpMmapRetains')

#include "CmpItf.h"


/** EXTERN LIB SECTION BEGIN **/

/** EXTERN LIB SECTION END **/


/**
 *  <category>Static defines</category>
 *  <description>
 *    Defines the config section name for this component
 *  </description>
 */
#ifndef CMPMMAPRETAINS_SECTION_NAME
	#define CMPMMAPRETAINS_SECTION_NAME						"CmpMmapRetains"
#endif

/**
 *  <category>Settings</category>
 *  <type>String</type>
 *  <description>
 *    Setting to configure the file that should be used for mmap'ed retains
 *  </description>
 */
#define CMPMMAPRETAINS_KEY_STRING_FILEPATH					"FilePath"
#ifndef CMPMMAPRETAINS_VALUE_STRING_FILEPATH_DEFAULT
	#define CMPMMAPRETAINS_VALUE_STRING_FILEPATH_DEFAULT	"MmapRetains.mem"
#endif

/**
 *  <category>Settings</category>
 *  <type>String</type>
 *  <description>
 *    Setting to configure the maximum file size in bytes for mmap'ed retains
 *  </description>
 */
#define CMPMMAPRETAINS_KEY_INT_MAXSIZE_BYTES				"MaxFileSize"
#ifndef CMPMMAPRETAINS_VALUE_INT_MAXSIZE_BYTES_DEFAULT
	#define CMPMMAPRETAINS_VALUE_INT_MAXSIZE_BYTES_DEFAULT	65536
#endif

/**
 *  <category>Settings</category>
 *  <type>Int</type>
 *  <description>
 *    Setting to configure automatic flush for mmap'ed retains. If AutoFlush is not set, two retain buffers of the
 *	  same size are allocated. One is mapped to the underlying retain file, one is mapped to a location in RAM. The
 *	  event EVT_FlushRetains will sync the buffers and synchronously flush the content to disk. Disable this setting
 *	  to guarantee consistent data in the underlying retain file. NOTE: If AutoFlush is disabled, retain content will
 *	  never be automatically synced to the underlying retain file except when downloading a new application. Retain
 *	  data will be lost if this event is never manually triggered.
 *  </description>
 */
#define CMPMMAPRETAINS_KEY_INT_AUTOFLUSH					"AutoFlush"
#ifndef CMPMMAPRETAINS_KEY_INT_AUTOFLUSH_DEFAULT
	#define CMPMMAPRETAINS_KEY_INT_AUTOFLUSH_DEFAULT		1
#endif

typedef struct EVTPARAM_FlushRetains
{
	RTS_BOOL bBackground;
} EVTPARAM_FlushRetains;
#define EVTPARAMID_FlushRetains								0x0001
#define EVTVERSION_FlushRetains								0x0001
#define EVT_FlushRetains									MAKE_EVENTID(EVTCLASS_INFO, 1)

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif
