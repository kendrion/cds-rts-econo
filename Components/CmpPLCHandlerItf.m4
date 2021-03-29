/**
 * <interfacename>CmpPLCHandler</interfacename>
 * <description></description>
 *
 * <copyright></copyright>
 */

SET_INTERFACE_NAME(`CmpPLCHandler')

/** EXTERN LIB SECTION BEGIN **/
/*  Comments are ignored for m4 compiler so restructured text can be used. changecom(`/*', `*/') */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * This enumeration defines all possible error codes that can be returned
 * by the functions from this library. If you need information for the purpose
 * of these error codes exceeding the name of the error itself then please have
 * a look at the PLCHandler SDK.
 */
#define PLCHANDLERIECERROR_FAILED    RTS_IEC_INT_C(0xFFFFFFFFFFFFFFFF)	
#define PLCHANDLERIECERROR_OK    RTS_IEC_INT_C(0x0)	
#define PLCHANDLERIECERROR_PLCNOTCONNECTED    RTS_IEC_INT_C(0x1)	
#define PLCHANDLERIECERROR_PLCLOGINFAILED    RTS_IEC_INT_C(0x2)	
#define PLCHANDLERIECERROR_PLCNOCYCLICLISTDEFINED    RTS_IEC_INT_C(0x3)	
#define PLCHANDLERIECERROR_PLCHANDLERINACTIVE    RTS_IEC_INT_C(0x4)	
#define PLCHANDLERIECERROR_LOADINGSYMBOLSFAILED    RTS_IEC_INT_C(0x5)	
#define PLCHANDLERIECERROR_ITFNOTSUPPORTED    RTS_IEC_INT_C(0x6)	
#define PLCHANDLERIECERROR_COMMFATAL    RTS_IEC_INT_C(0x7)	
#define PLCHANDLERIECERROR_NOCONFIGURATION    RTS_IEC_INT_C(0x8)	
#define PLCHANDLERIECERROR_INVALIDPARAMETER    RTS_IEC_INT_C(0x9)	
#define PLCHANDLERIECERROR_ITFFAILED    RTS_IEC_INT_C(0xA)	
#define PLCHANDLERIECERROR_NOTSUPPORTED    RTS_IEC_INT_C(0xB)	
#define PLCHANDLERIECERROR_EXCEPTION    RTS_IEC_INT_C(0xC)	
#define PLCHANDLERIECERROR_TIMEOUT    RTS_IEC_INT_C(0xD)	
#define PLCHANDLERIECERROR_STILLCONNECTED    RTS_IEC_INT_C(0xE)	
#define PLCHANDLERIECERROR_RECONNECTTHREADSTILLALIVE    RTS_IEC_INT_C(0xF)	
#define PLCHANDLERIECERROR_PLCNOTCONNECTEDSYMBOLSLOADED    RTS_IEC_INT_C(0x10)	
#define PLCHANDLERIECERROR_NOUPDATE    RTS_IEC_INT_C(0x11)	
#define PLCHANDLERIECERROR_OCXCONVERSIONFAILED    RTS_IEC_INT_C(0x12)	
#define PLCHANDLERIECERROR_TARGETIDMISMATCH    RTS_IEC_INT_C(0x13)	
#define PLCHANDLERIECERROR_NOOBJECT    RTS_IEC_INT_C(0x14)	
#define PLCHANDLERIECERROR_COMPONENTSNOTLOADED    RTS_IEC_INT_C(0x15)	
#define PLCHANDLERIECERROR_BUSY    RTS_IEC_INT_C(0x16)	
#define PLCHANDLERIECERROR_DISABLED    RTS_IEC_INT_C(0x17)	
#define PLCHANDLERIECERROR_PLCFAILED    RTS_IEC_INT_C(0x18)	
#define PLCHANDLERIECERROR_INVALIDSYMBOL    RTS_IEC_INT_C(0x19)	
#define PLCHANDLERIECERROR_BUFFERTOOSMALL    RTS_IEC_INT_C(0x1A)	
#define PLCHANDLERIECERROR_NOPROJECT    RTS_IEC_INT_C(0x1B)	
#define PLCHANDLERIECERROR_FILEERROR    RTS_IEC_INT_C(0x1C)	
#define PLCHANDLERIECERROR_RETAINMISMATCH    RTS_IEC_INT_C(0x1D)	
#define PLCHANDLERIECERROR_NOACCESSRIGHTS    RTS_IEC_INT_C(0x1E)	
#define PLCHANDLERIECERROR_DUPLICATEPLCNAME    RTS_IEC_INT_C(0x1F)	
#define PLCHANDLERIECERROR_SIZEMISMATCH    RTS_IEC_INT_C(0x20)	
#define PLCHANDLERIECERROR_LISTNOWRITEACCESS    RTS_IEC_INT_C(0x21)	
#define PLCHANDLERIECERROR_CONSISTENTACCESSTIMEOUT    RTS_IEC_INT_C(0x22)	
#define PLCHANDLERIECERROR_SYNCCONSISTENTACCESSDENIED    RTS_IEC_INT_C(0x23)	
#define PLCHANDLERIECERROR_INVALIDASCIISTRING    RTS_IEC_INT_C(0x24)	
#define PLCHANDLERIECERROR_INVALIDSTRINGLENGTH    RTS_IEC_INT_C(0x25)	
#define PLCHANDLERIECERROR_OUTOFMEMORY    RTS_IEC_INT_C(0x26)	
#define PLCHANDLERIECERROR_NOFILE    RTS_IEC_INT_C(0x27)	
#define PLCHANDLERIECERROR_APPLICATIONNOTINSTOP    RTS_IEC_INT_C(0x28)	
#define PLCHANDLERIECERROR_APPLICATIONNOTINRUN    RTS_IEC_INT_C(0x29)	
#define PLCHANDLERIECERROR_OPERATIONMODENOTINDEBUG    RTS_IEC_INT_C(0x2A)	
#define PLCHANDLERIECERROR_BACKUPRESTORENOTSUPPORTED    RTS_IEC_INT_C(0x2B)	
#define PLCHANDLERIECERROR_PLCINCONSISTENTSTATE    RTS_IEC_INT_C(0x2C)	
#define PLCHANDLERIECERROR_PLCINCOMPATIBLE    RTS_IEC_INT_C(0x2D)	
#define PLCHANDLERIECERROR_PLCVERSIONINCOMPATIBLE    RTS_IEC_INT_C(0x2E)	
#define PLCHANDLERIECERROR_RETAINERROR    RTS_IEC_INT_C(0x2F)	
#define PLCHANDLERIECERROR_APPLICATIONLOADERROR    RTS_IEC_INT_C(0x30)	
#define PLCHANDLERIECERROR_APPLICATIONSTARTERROR    RTS_IEC_INT_C(0x31)	
#define PLCHANDLERIECERROR_FILETRANSFERERROR    RTS_IEC_INT_C(0x32)	
#define PLCHANDLERIECERROR_OPERATIONDENIED    RTS_IEC_INT_C(0x33)	
#define PLCHANDLERIECERROR_FORCESACTIVE    RTS_IEC_INT_C(0x34)	
#define PLCHANDLERIECERROR_METAVERSIONMISMATCH    RTS_IEC_INT_C(0x35)	
#define PLCHANDLERIECERROR_PROTOCOLMISMATCH    RTS_IEC_INT_C(0x36)	
#define PLCHANDLERIECERROR_USERACCESSDENIED    RTS_IEC_INT_C(0x37)	
#define PLCHANDLERIECERROR_CALLAGAIN    RTS_IEC_INT_C(0x38)	
/* Typed enum definition */
#define PLCHANDLERIECERROR    RTS_IEC_INT

/**
 * This enumeration represents the state of the PLCHandler. 
 */
#define PLCHANDLERIECSTATE_TERMINATE    RTS_IEC_INT_C(0xFFFFFFFFFFFFFFFF)	/* PLCHandler currently is terminating */
#define PLCHANDLERIECSTATE_PLCNOTCONNECTED    RTS_IEC_INT_C(0x0)	/* PLC is not connected (init state) */
#define PLCHANDLERIECSTATE_PLCCONNECTED    RTS_IEC_INT_C(0x1)	/* PLC is connected */
#define PLCHANDLERIECSTATE_NOSYMBOLS    RTS_IEC_INT_C(0x2)	/* No symbols are available or symbol mismatch because of changed project */
#define PLCHANDLERIECSTATE_SYMBOLSLOADED    RTS_IEC_INT_C(0x3)	/* PLC is connected and symbols are loaded */
#define PLCHANDLERIECSTATE_RUNNING    RTS_IEC_INT_C(0x4)	/* PLC is connected, symbols are loaded and all of them are verified. 
 Now you can work correctly with the PLCHandler object */
#define PLCHANDLERIECSTATE_DISCONNECT    RTS_IEC_INT_C(0x5)	/* Connection is just getting terminated */
#define PLCHANDLERIECSTATE_NOCONFIGURATION    RTS_IEC_INT_C(0x6)	/* Configuration of the PLCHandler is invalid */
#define PLCHANDLERIECSTATE_NOTCONNECTEDSYMBOLSLOADED    RTS_IEC_INT_C(0x7)	/* PLC is currently not available, but the symbol information could be loaded offline. */
/* Typed enum definition */
#define PLCHANDLERIECSTATE    RTS_IEC_INT

/**
 * This enumeration defines the flags that can be used in calls to |SyncDefineVarList| for example.
 * For recent details in documentation have a look at the PLCHandler documentation. 
 */
#define PLCHANDLERVARLISTFLAGS_NONE    RTS_IEC_DWORD_C(0x0)	
#define PLCHANDLERVARLISTFLAGS_WRITEACCESS    RTS_IEC_DWORD_C(0x1)	
#define PLCHANDLERVARLISTFLAGS_CONSISTENTBACKGROUNDREAD    RTS_IEC_DWORD_C(0x2)	
#define PLCHANDLERVARLISTFLAGS_CONSISTENTSYNCHRONIZEDREAD    RTS_IEC_DWORD_C(0x4)	
#define PLCHANDLERVARLISTFLAGS_CONSISTENTSYNCHRONIZEDWRITE    RTS_IEC_DWORD_C(0x8)	
/* Typed enum definition */
#define PLCHANDLERVARLISTFLAGS    RTS_IEC_DWORD

/**
 * This enumeration defines all possible error codes that can be returned
 * by the functions from this library. If you need information for the purpose
 * of these error codes exceeding the name of the error itself then please have
 * a look at the PLCHandler SDK.
 */
#define PLCHANDLERIECERROR_FAILED    RTS_IEC_INT_C(0xFFFFFFFFFFFFFFFF)	
#define PLCHANDLERIECERROR_OK    RTS_IEC_INT_C(0x0)	
#define PLCHANDLERIECERROR_PLCNOTCONNECTED    RTS_IEC_INT_C(0x1)	
#define PLCHANDLERIECERROR_PLCLOGINFAILED    RTS_IEC_INT_C(0x2)	
#define PLCHANDLERIECERROR_PLCNOCYCLICLISTDEFINED    RTS_IEC_INT_C(0x3)	
#define PLCHANDLERIECERROR_PLCHANDLERINACTIVE    RTS_IEC_INT_C(0x4)	
#define PLCHANDLERIECERROR_LOADINGSYMBOLSFAILED    RTS_IEC_INT_C(0x5)	
#define PLCHANDLERIECERROR_ITFNOTSUPPORTED    RTS_IEC_INT_C(0x6)	
#define PLCHANDLERIECERROR_COMMFATAL    RTS_IEC_INT_C(0x7)	
#define PLCHANDLERIECERROR_NOCONFIGURATION    RTS_IEC_INT_C(0x8)	
#define PLCHANDLERIECERROR_INVALIDPARAMETER    RTS_IEC_INT_C(0x9)	
#define PLCHANDLERIECERROR_ITFFAILED    RTS_IEC_INT_C(0xA)	
#define PLCHANDLERIECERROR_NOTSUPPORTED    RTS_IEC_INT_C(0xB)	
#define PLCHANDLERIECERROR_EXCEPTION    RTS_IEC_INT_C(0xC)	
#define PLCHANDLERIECERROR_TIMEOUT    RTS_IEC_INT_C(0xD)	
#define PLCHANDLERIECERROR_STILLCONNECTED    RTS_IEC_INT_C(0xE)	
#define PLCHANDLERIECERROR_RECONNECTTHREADSTILLALIVE    RTS_IEC_INT_C(0xF)	
#define PLCHANDLERIECERROR_PLCNOTCONNECTEDSYMBOLSLOADED    RTS_IEC_INT_C(0x10)	
#define PLCHANDLERIECERROR_NOUPDATE    RTS_IEC_INT_C(0x11)	
#define PLCHANDLERIECERROR_OCXCONVERSIONFAILED    RTS_IEC_INT_C(0x12)	
#define PLCHANDLERIECERROR_TARGETIDMISMATCH    RTS_IEC_INT_C(0x13)	
#define PLCHANDLERIECERROR_NOOBJECT    RTS_IEC_INT_C(0x14)	
#define PLCHANDLERIECERROR_COMPONENTSNOTLOADED    RTS_IEC_INT_C(0x15)	
#define PLCHANDLERIECERROR_BUSY    RTS_IEC_INT_C(0x16)	
#define PLCHANDLERIECERROR_DISABLED    RTS_IEC_INT_C(0x17)	
#define PLCHANDLERIECERROR_PLCFAILED    RTS_IEC_INT_C(0x18)	
#define PLCHANDLERIECERROR_INVALIDSYMBOL    RTS_IEC_INT_C(0x19)	
#define PLCHANDLERIECERROR_BUFFERTOOSMALL    RTS_IEC_INT_C(0x1A)	
#define PLCHANDLERIECERROR_NOPROJECT    RTS_IEC_INT_C(0x1B)	
#define PLCHANDLERIECERROR_FILEERROR    RTS_IEC_INT_C(0x1C)	
#define PLCHANDLERIECERROR_RETAINMISMATCH    RTS_IEC_INT_C(0x1D)	
#define PLCHANDLERIECERROR_NOACCESSRIGHTS    RTS_IEC_INT_C(0x1E)	
#define PLCHANDLERIECERROR_DUPLICATEPLCNAME    RTS_IEC_INT_C(0x1F)	
#define PLCHANDLERIECERROR_SIZEMISMATCH    RTS_IEC_INT_C(0x20)	
#define PLCHANDLERIECERROR_LISTNOWRITEACCESS    RTS_IEC_INT_C(0x21)	
#define PLCHANDLERIECERROR_CONSISTENTACCESSTIMEOUT    RTS_IEC_INT_C(0x22)	
#define PLCHANDLERIECERROR_SYNCCONSISTENTACCESSDENIED    RTS_IEC_INT_C(0x23)	
#define PLCHANDLERIECERROR_INVALIDASCIISTRING    RTS_IEC_INT_C(0x24)	
#define PLCHANDLERIECERROR_INVALIDSTRINGLENGTH    RTS_IEC_INT_C(0x25)	
#define PLCHANDLERIECERROR_OUTOFMEMORY    RTS_IEC_INT_C(0x26)	
#define PLCHANDLERIECERROR_NOFILE    RTS_IEC_INT_C(0x27)	
#define PLCHANDLERIECERROR_APPLICATIONNOTINSTOP    RTS_IEC_INT_C(0x28)	
#define PLCHANDLERIECERROR_APPLICATIONNOTINRUN    RTS_IEC_INT_C(0x29)	
#define PLCHANDLERIECERROR_OPERATIONMODENOTINDEBUG    RTS_IEC_INT_C(0x2A)	
#define PLCHANDLERIECERROR_BACKUPRESTORENOTSUPPORTED    RTS_IEC_INT_C(0x2B)	
#define PLCHANDLERIECERROR_PLCINCONSISTENTSTATE    RTS_IEC_INT_C(0x2C)	
#define PLCHANDLERIECERROR_PLCINCOMPATIBLE    RTS_IEC_INT_C(0x2D)	
#define PLCHANDLERIECERROR_PLCVERSIONINCOMPATIBLE    RTS_IEC_INT_C(0x2E)	
#define PLCHANDLERIECERROR_RETAINERROR    RTS_IEC_INT_C(0x2F)	
#define PLCHANDLERIECERROR_APPLICATIONLOADERROR    RTS_IEC_INT_C(0x30)	
#define PLCHANDLERIECERROR_APPLICATIONSTARTERROR    RTS_IEC_INT_C(0x31)	
#define PLCHANDLERIECERROR_FILETRANSFERERROR    RTS_IEC_INT_C(0x32)	
#define PLCHANDLERIECERROR_OPERATIONDENIED    RTS_IEC_INT_C(0x33)	
#define PLCHANDLERIECERROR_FORCESACTIVE    RTS_IEC_INT_C(0x34)	
#define PLCHANDLERIECERROR_METAVERSIONMISMATCH    RTS_IEC_INT_C(0x35)	
#define PLCHANDLERIECERROR_PROTOCOLMISMATCH    RTS_IEC_INT_C(0x36)	
#define PLCHANDLERIECERROR_USERACCESSDENIED    RTS_IEC_INT_C(0x37)	
#define PLCHANDLERIECERROR_CALLAGAIN    RTS_IEC_INT_C(0x38)	
/* Typed enum definition */
#define PLCHANDLERIECERROR    RTS_IEC_INT

/**
 * This enumeration represents the state of the PLCHandler. 
 */
#define PLCHANDLERIECSTATE_TERMINATE    RTS_IEC_INT_C(0xFFFFFFFFFFFFFFFF)	/* PLCHandler currently is terminating */
#define PLCHANDLERIECSTATE_PLCNOTCONNECTED    RTS_IEC_INT_C(0x0)	/* PLC is not connected (init state) */
#define PLCHANDLERIECSTATE_PLCCONNECTED    RTS_IEC_INT_C(0x1)	/* PLC is connected */
#define PLCHANDLERIECSTATE_NOSYMBOLS    RTS_IEC_INT_C(0x2)	/* No symbols are available or symbol mismatch because of changed project */
#define PLCHANDLERIECSTATE_SYMBOLSLOADED    RTS_IEC_INT_C(0x3)	/* PLC is connected and symbols are loaded */
#define PLCHANDLERIECSTATE_RUNNING    RTS_IEC_INT_C(0x4)	/* PLC is connected, symbols are loaded and all of them are verified. 
 Now you can work correctly with the PLCHandler object */
#define PLCHANDLERIECSTATE_DISCONNECT    RTS_IEC_INT_C(0x5)	/* Connection is just getting terminated */
#define PLCHANDLERIECSTATE_NOCONFIGURATION    RTS_IEC_INT_C(0x6)	/* Configuration of the PLCHandler is invalid */
#define PLCHANDLERIECSTATE_NOTCONNECTEDSYMBOLSLOADED    RTS_IEC_INT_C(0x7)	/* PLC is currently not available, but the symbol information could be loaded offline. */
/* Typed enum definition */
#define PLCHANDLERIECSTATE    RTS_IEC_INT

/**
 * This enumeration defines the flags that can be used in calls to |SyncDefineVarList| for example.
 * For recent details in documentation have a look at the PLCHandler documentation. 
 */
#define PLCHANDLERVARLISTFLAGS_NONE    RTS_IEC_DWORD_C(0x0)	
#define PLCHANDLERVARLISTFLAGS_WRITEACCESS    RTS_IEC_DWORD_C(0x1)	
#define PLCHANDLERVARLISTFLAGS_CONSISTENTBACKGROUNDREAD    RTS_IEC_DWORD_C(0x2)	
#define PLCHANDLERVARLISTFLAGS_CONSISTENTSYNCHRONIZEDREAD    RTS_IEC_DWORD_C(0x4)	
#define PLCHANDLERVARLISTFLAGS_CONSISTENTSYNCHRONIZEDWRITE    RTS_IEC_DWORD_C(0x8)	
/* Typed enum definition */
#define PLCHANDLERVARLISTFLAGS    RTS_IEC_DWORD

/**
 * This type bundles information about the device the PLCHandler is connected to.
 *
 * .. note:: This structure is a subset (with different types) of the DeviceInfo structure from the PLCHandler SDK
 */
typedef struct tagRudimentaryDeviceInfo
{
	RTS_IEC_UDINT udiTargetId;		/* Target id of the device. */
	RTS_IEC_UDINT udiTargetType;		/* Target type of the device. */
	RTS_IEC_UDINT udiBufferSize;		/* Communication buffer size of the device. No service must exceed this size! */
	RTS_IEC_UDINT udiDeviceSessionId;		/* Session id of the current connection */
	RTS_IEC_BOOL xMotorola;		/* Byte order of the device: TRUE in case of big endian byte order, FALSE in case of little endian byte order */
} RudimentaryDeviceInfo;

/**
 * Instances of this structure represent the value and status information for a single variable
 *
 * .. note:: In fact this structure is the same than PlcVarValue from the PLCHandler SDK
 */
typedef struct tagVariableValue
{
	RTS_IEC_UDINT ulTimeStamp;		/* UTC-Timestamp of the value, is read from the PLC

 .. note:: The UTC-timestamp is not supported by all PLCs */
	RTS_IEC_BYTE quality;		/* Quality of the value
 * 1: Value was read from the PLC
 * 0: Value was not read from the PLC */
	RTS_IEC_BYTE data[1];		/* Array with the value. The concrete size of this array depends on the
 data type (byData[1] is only a placeholder with the minimum
 size). Should only be accessed, if bQuality is TRUE */
} VariableValue;

/**
 * This function checks whether the requested symbol is valid and can be monitored 
 * by calling |VarListDefine| for example.
 * :return: An error code, ERR_OK in case the symbol is valid
 */
typedef struct tagplchandlerchecksymbolvalidity_struct
{
	RTS_IEC_HANDLE hPlcHandler;			/* VAR_INPUT */	/* The instance to check the symbol on */
	RTS_IEC_BYTE *pstSymbol;			/* VAR_INPUT */	/* The symbol to check for validity */
	RTS_IEC_INT PLCHandlerCheckSymbolValidity;	/* VAR_OUTPUT, Enum: ERROR */
} plchandlerchecksymbolvalidity_struct;

DEF_API(`void',`CDECL',`plchandlerchecksymbolvalidity',`(plchandlerchecksymbolvalidity_struct *p)',1,0x35B50EAA,0x03050F00)

/**
 * Configures the given PLCHandler instance with the given string.
 * :return: An errorcode representing the result of this operation
 */
typedef struct tagplchandlerconfigurebystring_struct
{
	RTS_IEC_HANDLE hPlcHandler;			/* VAR_INPUT */	/* The instance of the PLCHandler to configured. */
	RTS_IEC_STRING *pstConfiguration;	/* VAR_INPUT */	/* A POINTER to a zero terminated ASCII STRING containing the configuration of the PLCHandler. The STRING
 is expected to contain the ini-format as defined by the PLCHandler SDK. 
 The length of the given string is not limited by 80 characters. */
	RTS_IEC_INT PLCHandlerConfigureByString;	/* VAR_OUTPUT, Enum: ERROR */
} plchandlerconfigurebystring_struct;

DEF_API(`void',`CDECL',`plchandlerconfigurebystring',`(plchandlerconfigurebystring_struct *p)',1,0x9A5EB7EA,0x03050F00)

/**
 * Attempts to connect according to the configuration of this instance.
 * This function executes a single synchronous connection attempt. There will be no automatic reconnect attempts, neither
 * for the initial connection nor after connection losses.
 *
 * .. important:: Calling this method might take some time (eg. for scanning the network etc.)
 *    so be careful when calling from an IEC-Task. Typically this method should be called in an
 *    asynchronous way. 
 *
 * :return: An errorcode representing the result of this operation
 */
typedef struct tagplchandlerconnect_struct
{
	RTS_IEC_HANDLE hPlcHandler;			/* VAR_INPUT */	/* The instance to connect. */
	RTS_IEC_INT PLCHandlerConnect;		/* VAR_OUTPUT, Enum: ERROR */
} plchandlerconnect_struct;

DEF_API(`void',`CDECL',`plchandlerconnect',`(plchandlerconnect_struct *p)',1,0xA16ECE49,0x03050F00)

/**
 * Supports the new error messages for denied user access and protocol mismatch.
 * 
 * Attempts to connect according to the configuration of this instance.
 * This function executes a single synchronous connection attempt. There will be no automatic reconnect attempts, neither
 * for the initial connection nor after connection losses.
 *
 * .. important:: Calling this method might take some time (eg. for scanning the network etc.)
 *    so be careful when calling from an IEC-Task. Typically this method should be called in an
 *    asynchronous way. 
 *
 * :return: An errorcode representing the result of this operation
 */
typedef struct tagplchandlerconnect2_struct
{
	RTS_IEC_HANDLE hPlcHandler;			/* VAR_INPUT */	/* The instance to connect. */
	RTS_IEC_INT PLCHandlerConnect2;		/* VAR_OUTPUT, Enum: ERROR */
} plchandlerconnect2_struct;

DEF_API(`void',`CDECL',`plchandlerconnect2',`(plchandlerconnect2_struct *p)',1,0x229609D6,0x03050F00)

/**
 * Creates a new PLC Handler instance.
 * 
 * .. note::The returned instance must be released by calling |DeleteInstance|
 *
 * :return: A handle to the newly created instance
 */
typedef struct tagplchandlercreateinstance_struct
{
	RTS_IEC_HANDLE PLCHandlerCreateInstance;	/* VAR_OUTPUT */	
	RTS_IEC_INT result;					/* VAR_OUTPUT, Enum: ERROR */
} plchandlercreateinstance_struct;

DEF_API(`void',`CDECL',`plchandlercreateinstance',`(plchandlercreateinstance_struct *p)',1,0xF3B6D6E9,0x03050F00)

/**
 * Deletes an instance of the PLCHandler that was previously created by |CreateInstance|
 * :return: An errorcode representing the result of this operation
 */
typedef struct tagplchandlerdeleteinstance_struct
{
	RTS_IEC_HANDLE hPlcHandler;			/* VAR_INPUT */	/* The instance to delete. */
	RTS_IEC_INT PLCHandlerDeleteInstance;	/* VAR_OUTPUT, Enum: ERROR */
} plchandlerdeleteinstance_struct;

DEF_API(`void',`CDECL',`plchandlerdeleteinstance',`(plchandlerdeleteinstance_struct *p)',1,0x62C4DDDA,0x03050F00)

/**
 * Disconnects a previously created connection of this instance.
 *
 * .. important:: Calling this method might take some time (eg. for logging out etc.)
 *    so be careful when calling from an IEC-Task. Typically this method should be called in an
 *    asynchronous way. 
 *
 * :return: An errorcode representing the result of this operation
 */
typedef struct tagplchandlerdisconnect_struct
{
	RTS_IEC_HANDLE hPlcHandler;			/* VAR_INPUT */	/* The instance to disconnect */
	RTS_IEC_INT PLCHandlerDisconnect;	/* VAR_OUTPUT, Enum: ERROR */
} plchandlerdisconnect_struct;

DEF_API(`void',`CDECL',`plchandlerdisconnect',`(plchandlerdisconnect_struct *p)',1,0xBEC54443,0x03050F00)

/**
 * This function can be used to retrieve information of the PLC to which the PLCHandler is connected to. 
 * :return: An errorcode representing the result of this operation
 */
typedef struct tagplchandlergetdeviceinfo_struct
{
	RTS_IEC_HANDLE hPlcHandler;			/* VAR_INPUT */	/* The instance of the PLCHandler to work on. */
	RudimentaryDeviceInfo *pDeviceInfo;	/* VAR_INPUT */	/* Points to a RudimentaryDeviceInfo structure, where the information will be stored */
	RTS_IEC_INT PLCHandlerGetDeviceInfo;	/* VAR_OUTPUT, Enum: ERROR */
} plchandlergetdeviceinfo_struct;

DEF_API(`void',`CDECL',`plchandlergetdeviceinfo',`(plchandlergetdeviceinfo_struct *p)',1,0x9D8B2632,0x03050F00)

/**
 * This function returns the state of a given PLCHandler instance.
 */
typedef struct tagplchandlergetstate_struct
{
	RTS_IEC_HANDLE hPlcHandler;			/* VAR_INPUT */	/* The instance to retrieve the state of. */
	RTS_IEC_INT PLCHandlerGetState;		/* VAR_OUTPUT, Enum: STATE */
	RTS_IEC_INT result;					/* VAR_OUTPUT, Enum: ERROR */
} plchandlergetstate_struct;

DEF_API(`void',`CDECL',`plchandlergetstate',`(plchandlergetstate_struct *p)',1,0x3882F552,0x03050F00)

/**
 * Configures and activates logging of PLCHandler messages into a logfile.
 * 
 * .. note:: If logging is necessary, then this method should be called immediately after the call to |CreateInstance|.  
 *
 * :return: An errorcode representing the result of this operation. If the call is not done at the correct
 * point of time, then |Error.Busy| is returned.
 */
typedef struct tagplchandlerlogginginit_struct
{
	RTS_IEC_HANDLE hPlcHandler;			/* VAR_INPUT */	/* The instance to initialize logging on */
	RTS_IEC_UDINT logFilter;			/* VAR_INPUT */	/* The active filter for log messages. For details of the messages classes have a look at the PLCHandler documentation. */
	RTS_IEC_STRING *logFile;			/* VAR_IN_OUT */	/* The path of the logfile to store the messages in */
	RTS_IEC_INT PLCHandlerLoggingInit;	/* VAR_OUTPUT, Enum: ERROR */
} plchandlerlogginginit_struct;

DEF_API(`void',`CDECL',`plchandlerlogginginit',`(plchandlerlogginginit_struct *p)',1,0xFB1F6D11,0x03050F00)

/**
 * Creates a variable list to be used lateron with |SyncReadVarListFromPlc| or |SyncWriteVarListToPlc|. The resulting variable list must be released by a followup call to 
 * |SyncDeleteVarList|.
 *
 * .. important:: As communication and symbolic resolution is involved, take care (async calls etc.) when using this method from an IEC-Task
 *
 * :return: A handle to the newly created variable list
 */
typedef struct tagplchandlersyncdefinevarlist_struct
{
	RTS_IEC_HANDLE hPlcHandler;			/* VAR_INPUT */	/* The instance of the PLCHandler to work on. */
	RTS_IEC_BYTE **ppInstPaths;			/* VAR_INPUT */	/* A POINTER to an ARRAY of POINTERs to zero terminated ASCII STRINGs representing the instance paths that should be written */
	RTS_IEC_UDINT numSymbols;			/* VAR_INPUT */	/* The number of variables to read. In fact this number represents the number of entries in ``ppInstPaths`` */
	RTS_IEC_DWORD flags;				/* VAR_INPUT, Enum: VARLISTFLAGS */
	RTS_IEC_HANDLE PLCHandlerSyncDefineVarList;	/* VAR_OUTPUT */	
	RTS_IEC_INT result;					/* VAR_OUTPUT, Enum: ERROR */
} plchandlersyncdefinevarlist_struct;

DEF_API(`void',`CDECL',`plchandlersyncdefinevarlist',`(plchandlersyncdefinevarlist_struct *p)',1,0x9C816C52,0x03050F00)

/**
 * Deletes the given variable list that was previously created by |SyncDefineVarList|
 * :return: An errorcode representing the result of this operation
 */
typedef struct tagplchandlersyncdeletevarlist_struct
{
	RTS_IEC_HANDLE hPlcHandler;			/* VAR_INPUT */	/* The instance of the PLCHandler to work on. */
	RTS_IEC_HANDLE hVarList;			/* VAR_INPUT */	/* The variable list to delete. */
	RTS_IEC_INT PLCHandlerSyncDeleteVarList;	/* VAR_OUTPUT, Enum: ERROR */
} plchandlersyncdeletevarlist_struct;

DEF_API(`void',`CDECL',`plchandlersyncdeletevarlist',`(plchandlersyncdeletevarlist_struct *p)',1,0xA82CAF19,0x03050F00)

/**
 * Reads the given variable list synchronously. The list must have been created previously by a call to |SyncReadVars|
 *
 * .. important:: As communication is involved, take care (async calls etc.) when using this method from an IEC-Task
 *
 * :return: An errorcode representing the result of this operation
 */
typedef struct tagplchandlersyncreadvarlist_struct
{
	RTS_IEC_HANDLE hPlcHandler;			/* VAR_INPUT */	/* The instance of the PLCHandler to work on. */
	RTS_IEC_HANDLE hVarList;			/* VAR_INPUT */	/* The variable list to read. */
	RTS_IEC_INT PLCHandlerSyncReadVarList;	/* VAR_OUTPUT, Enum: ERROR */
	VariableValue **ppVarInfos;			/* VAR_OUTPUT */	/* An ARRAY OF POINTERs to VarInfo instances representing each single read value */
	RTS_IEC_UDINT numVarsResult;		/* VAR_OUTPUT */	/* The size of the array of returned variables */
} plchandlersyncreadvarlist_struct;

DEF_API(`void',`CDECL',`plchandlersyncreadvarlist',`(plchandlersyncreadvarlist_struct *p)',1,0x22BA041E,0x03050F00)

/**
 * Reads the given variable list synchronously. The list must have been created previously by a call to |SyncDefineVarList|
 *
 * .. important:: As communication is involved, take care (async calls etc.) when using this method from an IEC-Task
 *
 * :return: An errorcode representing the result of this operation
 */
typedef struct tagplchandlersyncreadvarlistfromplc_struct
{
	RTS_IEC_HANDLE hPlcHandler;			/* VAR_INPUT */	/* The instance of the PLCHandler to work on. */
	RTS_IEC_HANDLE hVarList;			/* VAR_INPUT */	/* The variable list to read. */
	RTS_IEC_INT PLCHandlerSyncReadVarListFromPlc;	/* VAR_OUTPUT, Enum: ERROR */
	VariableValue **ppVarInfos;			/* VAR_OUTPUT */	/* An ARRAY OF POINTERs to VarInfo instances representing each single read value */
	RTS_IEC_UDINT numVarsResult;		/* VAR_OUTPUT */	/* The size of the array of returned variables */
} plchandlersyncreadvarlistfromplc_struct;

DEF_API(`void',`CDECL',`plchandlersyncreadvarlistfromplc',`(plchandlersyncreadvarlistfromplc_struct *p)',1,0xD0C1A01F,0x03050F00)

/**
 * Reads the given variables synchronously. The resulting variable list must be released by a followup call to 
 * |SyncReadVarsRelease|.
 *
 * .. note:: The returned variable list may be reused for further read calls (without additional symbolic resolution) by
 *    calling |SyncReadVarList|
 *
 * .. important:: As communication and symbolic resolution is involved, take care (async calls etc.) when using this method from an IEC-Task
 *
 * :return: A handle to the newly created variable list
 */
typedef struct tagplchandlersyncreadvars_struct
{
	RTS_IEC_HANDLE hPlcHandler;			/* VAR_INPUT */	/* The instance of the PLCHandler to work on. */
	RTS_IEC_BYTE **ppInstPaths;			/* VAR_INPUT */	/* A POINTER to an ARRAY of POINTERs to zero terminated ASCII STRINGs representing the instance paths that should be written */
	RTS_IEC_UDINT numSymbols;			/* VAR_INPUT */	/* The number of variables to read. In fact this number represents the number of entries in ``ppInstPaths`` */
	RTS_IEC_HANDLE PLCHandlerSyncReadVars;	/* VAR_OUTPUT */	
	VariableValue **ppVarInfos;			/* VAR_OUTPUT */	/* An ARRAY OF POINTERs to VarInfo instances representing each single read value */
	RTS_IEC_UDINT numVarsResult;		/* VAR_OUTPUT */	/* The size of the array of returned variables */
	RTS_IEC_INT result;					/* VAR_OUTPUT, Enum: ERROR */
} plchandlersyncreadvars_struct;

DEF_API(`void',`CDECL',`plchandlersyncreadvars',`(plchandlersyncreadvars_struct *p)',1,0x7F4F3550,0x03050F00)

/**
 * Releases the given variable list that was previously created by |SyncReadVars|
 * :return: An errorcode representing the result of this operation
 */
typedef struct tagplchandlersyncreadvarsrelease_struct
{
	RTS_IEC_HANDLE hPlcHandler;			/* VAR_INPUT */	/* The instance of the PLCHandler to work on. */
	RTS_IEC_HANDLE hVarList;			/* VAR_INPUT */	/* The variable list to release. */
	RTS_IEC_INT PLCHandlerSyncReadVarsRelease;	/* VAR_OUTPUT, Enum: ERROR */
} plchandlersyncreadvarsrelease_struct;

DEF_API(`void',`CDECL',`plchandlersyncreadvarsrelease',`(plchandlersyncreadvarsrelease_struct *p)',1,0xD4834060,0x03050F00)

/**
 * This function can be used to transfer any runtime system service to the PLC.
 *
 * .. important:: Before this function can be used it is necessary to call |GetDeviceInfo| to retrieve information about the PLC. 
 *
 * :return: An errorcode representing the result of this operation
 */
typedef struct tagplchandlersyncsendservice_struct
{
	RTS_IEC_HANDLE hPlcHandler;			/* VAR_INPUT */	/* The instance of the PLCHandler to work on. */
	RTS_IEC_BYTE *pbySend;				/* VAR_INPUT */	/* Pointer to the byte stream, which should be sent to the PLC */
	RTS_IEC_UDINT udiSendSize;			/* VAR_INPUT */	/* Length of the byte stream to send */
	RTS_IEC_BYTE **ppbyRecv;			/* VAR_INPUT */	/* Points to the buffer, where the result of the call is available */
	RTS_IEC_UDINT *pudiRecvSize;		/* VAR_INPUT */	/* Points to an UDINT variable, that contains the length of the PLC’s service reply */
	RTS_IEC_INT PLCHandlerSyncSendService;	/* VAR_OUTPUT, Enum: ERROR */
} plchandlersyncsendservice_struct;

DEF_API(`void',`CDECL',`plchandlersyncsendservice',`(plchandlersyncsendservice_struct *p)',1,0x303EF9A4,0x03050F00)

/**
 * Writes the given variable list synchronously. The list must have been created previously by a call to |SyncDefineVarList|
 *
 * .. important:: As communication is involved, take care (async calls etc.) when using this method from an IEC-Task
 *
 * :return: An errorcode representing the result of this operation
 */
typedef struct tagplchandlersyncwritevarlisttoplc_struct
{
	RTS_IEC_HANDLE hPlcHandler;			/* VAR_INPUT */	/* The instance of the PLCHandler to work on. */
	RTS_IEC_HANDLE hVarList;			/* VAR_INPUT */	/* The variable list to write. */
	RTS_IEC_BYTE **ppValues;			/* VAR_INPUT */	/* A POINTER to an ARRAY of POINTERs to the values that should be written. */
	RTS_IEC_UDINT *pulSizes;			/* VAR_INPUT */	/* An optional POINTER to an ARRAY of sizes of each item. If omitted, the performance of the write operation might not be optimal
 because the according information has to be derived from the internal symbol tables. */
	RTS_IEC_UDINT numVars;				/* VAR_INPUT */	/* The number of variables to write. In fact this number represents the sizes of the arrays given by ``ppValues`` and ``pulSizes`` so
 all three arrays are expected to have the same size. */
	RTS_IEC_INT PLCHandlerSyncWriteVarListToPlc;	/* VAR_OUTPUT, Enum: ERROR */
} plchandlersyncwritevarlisttoplc_struct;

DEF_API(`void',`CDECL',`plchandlersyncwritevarlisttoplc',`(plchandlersyncwritevarlisttoplc_struct *p)',1,0xA486E098,0x03050F00)

/**
 * Writes the given list of values synchronously to the given list of variables.
 *
 * .. important:: As communication and symbolic resolution is involved, take care (async calls etc.) when using this method from an IEC-Task
 *
 * :return: An errorcode representing the result of this operation
 */
typedef struct tagplchandlersyncwritevars_struct
{
	RTS_IEC_HANDLE hPlcHandler;			/* VAR_INPUT */	/* The instance of the PLCHandler to work on. */
	RTS_IEC_BYTE **ppInstPaths;			/* VAR_INPUT */	/* A POINTER to an ARRAY of POINTERs to zero terminated ASCII STRINGs representing the instance paths that should be written */
	RTS_IEC_BYTE **ppValues;			/* VAR_INPUT */	/* A POINTER to an ARRAY of POINTERs to the values that should be written. */
	RTS_IEC_UDINT *pulSizes;			/* VAR_INPUT */	/* An optional POINTER to an ARRAY of sizes of each item. If omitted, the performance of the write operation might not be optimal
 because the according information has to be derived from the internal symbol tables. */
	RTS_IEC_UDINT numVars;				/* VAR_INPUT */	/* The number of variables to write. In fact this number represents the sizes of the arrays given by ``ppInstPaths``, ``ppValues`` and ``pulSizes`` so
 all three arrays are expected to have the same size. */
	RTS_IEC_INT PLCHandlerSyncWriteVars;	/* VAR_OUTPUT, Enum: ERROR */
} plchandlersyncwritevars_struct;

DEF_API(`void',`CDECL',`plchandlersyncwritevars',`(plchandlersyncwritevars_struct *p)',1,0xDACACBAF,0x03050F00)

/**
 * Creates a new variable list that will be cyclically updated by the underlying
 * PLCHandler instance. The returned handle must be deleted by calling |VarListDelete| if no longer in use.
 *
 * .. important:: Calling this method might take some time (for registering the list in the connected PLC)
 *    so be careful when calling from an IEC-Task. Typically this method should be called in an
 *    asynchronous way.
 *
 * :return: A handle to the newly created variable list  
 */
typedef struct tagplchandlervarlistdefine_struct
{
	RTS_IEC_HANDLE hPlcHandler;			/* VAR_INPUT */	/* The instance to define the variable list on. */
	RTS_IEC_BYTE **ppInstPaths;			/* VAR_INPUT */	/* A POINTER to an ARRAY of POINTERs to zero terminated ASCII STRINGs representing the instance paths that should be monitored */
	RTS_IEC_UDINT numVars;				/* VAR_INPUT */	/* The number of variables for the new variable list as pointed to by ``ppInstPaths`` */
	RTS_IEC_UDINT updateRate;			/* VAR_INPUT */	/* The update rate for this variable list in milliseconds */
	RTS_IEC_HANDLE PLCHandlerVarListDefine;	/* VAR_OUTPUT */	
	RTS_IEC_INT result;					/* VAR_OUTPUT, Enum: ERROR */
} plchandlervarlistdefine_struct;

DEF_API(`void',`CDECL',`plchandlervarlistdefine',`(plchandlervarlistdefine_struct *p)',1,0x81C780F4,0x03050F00)

/**
 * Deletes a variable list previously created by |VarListDefine|
 *
 * .. important:: Calling this method might take some time (due to necessary communication)
 *    so be careful when calling from an IEC-Task. Typically this method should be called in an
 *    asynchronous way. 
 *
 * :return: An errorcode representing the result of this operation
 */
typedef struct tagplchandlervarlistdelete_struct
{
	RTS_IEC_HANDLE hPlcHandler;			/* VAR_INPUT */	/* The instance to delete the variable list on. */
	RTS_IEC_HANDLE hVarList;			/* VAR_INPUT */	/* The varlist to delete */
	RTS_IEC_INT PLCHandlerVarListDelete;	/* VAR_OUTPUT, Enum: ERROR */
} plchandlervarlistdelete_struct;

DEF_API(`void',`CDECL',`plchandlervarlistdelete',`(plchandlervarlistdelete_struct *p)',1,0xAD8E5D4F,0x03050F00)

/**
 * Deactivates monitoring the given variable list.
 * :return: An errorcode representing the result of this operation
 */
typedef struct tagplchandlervarlistdisable_struct
{
	RTS_IEC_HANDLE hPlcHandler;			/* VAR_INPUT */	/* The instance of the PLCHandler to work on. */
	RTS_IEC_HANDLE hVarList;			/* VAR_INPUT */	/* The varlist to disable */
	RTS_IEC_INT PLCHandlerVarListDisable;	/* VAR_OUTPUT, Enum: ERROR */
} plchandlervarlistdisable_struct;

DEF_API(`void',`CDECL',`plchandlervarlistdisable',`(plchandlervarlistdisable_struct *p)',1,0xA9F0A7EB,0x03050F00)

/**
 * Activates monitoring the given variable list.
 * :return: An errorcode representing the result of this operation
 */
typedef struct tagplchandlervarlistenable_struct
{
	RTS_IEC_HANDLE hPlcHandler;			/* VAR_INPUT */	/* The instance of the PLCHandler to work on. */
	RTS_IEC_HANDLE hVarList;			/* VAR_INPUT */	/* The varlist to enable. */
	RTS_IEC_INT PLCHandlerVarListEnable;	/* VAR_OUTPUT, Enum: ERROR */
} plchandlervarlistenable_struct;

DEF_API(`void',`CDECL',`plchandlervarlistenable',`(plchandlervarlistenable_struct *p)',1,0x5EDC0FD8,0x03050F00)

/**
 * Protects the access to the variable list so it cannot be changed by the update thread.
 * Should be used only in combination with |VarListRead|
 *
 * .. important:: After using the variable list it must be released by calling |VarListLeave| 
 *
 * :return: An errorcode representing the result of this operation
 */
typedef struct tagplchandlervarlistenter_struct
{
	RTS_IEC_HANDLE hPlcHandler;			/* VAR_INPUT */	/* The instance of the PLCHandler to work on. */
	RTS_IEC_HANDLE hVarList;			/* VAR_INPUT */	/* The varlist to lock access on. */
	RTS_IEC_INT PLCHandlerVarListEnter;	/* VAR_OUTPUT, Enum: ERROR */
} plchandlervarlistenter_struct;

DEF_API(`void',`CDECL',`plchandlervarlistenter',`(plchandlervarlistenter_struct *p)',1,0x7F252097,0x03050F00)

/**
 * Releases the access to the variable list so it can be changed again by the update thread.
 * Should be used only in combination with |VarListRead|
 *
 * .. important:: Must be called only after a previous call to |VarListEnter| 
 *
 * :return: An errorcode representing the result of this operation
 */
typedef struct tagplchandlervarlistleave_struct
{
	RTS_IEC_HANDLE hPlcHandler;			/* VAR_INPUT */	/* The instance of the PLCHandler to work on. */
	RTS_IEC_HANDLE hVarList;			/* VAR_INPUT */	/* The varlist to release access on. */
	RTS_IEC_INT PLCHandlerVarListLeave;	/* VAR_OUTPUT, Enum: ERROR */
} plchandlervarlistleave_struct;

DEF_API(`void',`CDECL',`plchandlervarlistleave',`(plchandlervarlistleave_struct *p)',1,0x6150164D,0x03050F00)

/**
 * Reads the cached (last retrieved) values from the given variable list.
 *
 * .. important:: Must be called only in code protected by |VarListEnter| and |VarListLeave| 
 *
 * :return: An errorcode representing the result of this operation
 */
typedef struct tagplchandlervarlistread_struct
{
	RTS_IEC_HANDLE hPlcHandler;			/* VAR_INPUT */	/* The instance of the PLCHandler to work on. */
	RTS_IEC_HANDLE hVarList;			/* VAR_INPUT */	/* The varlist to read the values from */
	RTS_IEC_INT PLCHandlerVarListRead;	/* VAR_OUTPUT, Enum: ERROR */
	VariableValue **ppVarInfos;			/* VAR_OUTPUT */	/* An ARRAY OF POINTERs to VarInfo instances representing each single read value */
	RTS_IEC_UDINT numVars;				/* VAR_OUTPUT */	/* The number of variables in ``ppVarInfos`` */
} plchandlervarlistread_struct;

DEF_API(`void',`CDECL',`plchandlervarlistread',`(plchandlervarlistread_struct *p)',1,0x5FFAB125,0x03050F00)

#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/


#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description>Function to create a new PLCHandler instance.
 * <p>NOTE:The returned instance must be released by calling PLCHandlerDeleteInstance</p>
 * </description>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <errorcode name="RTS_RESULT pResult" type="ERR_OK">Instance successfully created</errorcode>
 * <errorcode name="RTS_RESULT pResult" type="ERR_NO_OBJECT">Instance could not be created</errorcode>
 * <result>A handle to the newly created PLCHandler instance</result>
 */
DEF_ITF_API(`RTS_HANDLE', `CDECL', `PLCHandlerCreateInstance', `(RTS_RESULT *pResult)')

/**
 * <description>Function to delete an instance of the PLCHandler that was previously created by PLCHandlerCreateInstance.</description>
 * <param name="hPlcHandler" type="IN">Handle to the PLCHandler instance to delete</param>
 * <result>Error code:
 *		ERR_OK: PLCHandler instance successfully deleted
 *		ERR_PARAMETER: Invalid parameter
 * </result>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `PLCHandlerDeleteInstance', `(RTS_HANDLE hPlcHandler)')

#ifdef __cplusplus
}
#endif