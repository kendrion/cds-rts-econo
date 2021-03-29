/**
 * <interfacename>SysCom</interfacename>
 * <description> 
 *	<p>The SysCom interface is projected to connect to a serial COM port (RS232) and 
 *	to send and receive data via this port.</p>
 *	<p>IMPLEMENTATION NODE: All routines must be realized asynchronous! You have to use the FIFO of
 *	the serial device! Don't block the read and write routines, until the operations are finished.</p>
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`SysCom')

#include "CmpStd.h"

#ifndef CDECL
	#define CDECL
#endif

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>
 * Allows to specify a serial port by its Microsoft Windows friendly name instead of the COM port number.
 * The friendly name of the COM port is for example shown by the Microsoft Windows Device Manager. 
 * This feature is useful, if the port number is somehow dynamic, but if the adapter has a well defined 
 * friendly name. Typically it's used for USB devices, which provide a virtual COM port driver. If the 
 * (by SysComOpen) requested COM port number is found in the list of the configured "Windows.PortToCheck" 
 * settings, then the port is opened, which matches to the name specified by "Windows.CheckWithPortName",
 * instead of the requested port number. 
 * (Only for Windows).
 * Example:
 * Windows.PortToCheck.0=99
 * Windows.CheckWithPortName.0=My USB serial device
 * Windows.PortToCheck.1=98
 * Windows.CheckWithPortName.1=PLC USB interface
 * </description>
 */
#define SYSCOMKEY_INT_WINDOWS_PORT_TO_CHECK						"Windows.PortToCheck"
#define SYSTIMERVALUE_INT_WINDOWS_PORT_TO_CHECK_DEFAULT	        0

/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>
 * Specifies a string, which is compared to the Microsoft Windows friendly name of the available COM ports.
 * The name matches, if it starts with the provided string.  
 * See also setting PortToCheck.
 * (Only for Windows).
 * </description>
 */
#define SYSCOMKEY_STRING_WINDOWS_PORTNAME_CHECK_WITH						"Windows.CheckWithPortname"
#define SYSTIMERVALUE_STRING_WINDOWS_PORTNAME_CHECK_WITH_DEFAULT	        ""

/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>
 * Device file for serial interface (Only for Linux).
 * may also be indexed. for example: Linux.Devicefile.7=/dev/usb0 maps /dev/usb0 to COM7
 * </description>
 */
#define SYSCOMKEY_STRING_LINUX_DEVICEFILE			"Linux.Devicefile"
#define SYSCOMKEY_STRING_LINUX_DEVICEFILE_DEFAULT	"/dev/ttyS"

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>
 * Activate exclusive access to the device file (Only for Linux).
 * </description>
 */
#define SYSCOMKEY_INT_LINUX_EXCLUSIVE_ACCESS			"Linux.ExclusiveAccess"
#define SYSCOMKEY_INT_LINUX_EXCLUSIVE_ACCESS_DEFAULT	0


/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>
 *	Physical layer of the serial interface. Valid values are "rs232" and "rs485".
 * (Only for Linux).
 * </description>
 */
#define SYSCOMKEY_STRING_LINUX_PHYSICAL_LAYER						"Linux.PhysicalLayer"
#define SYSCOMKEY_STRING_LINUX_PHYSICAL_LAYER_DEFAULT	        	"rs232"

/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>
 * on_send: RTS pin is high on send, and low all other times. 
 * after_send: RTS pin is low on send. 
 * (Only for Linux).
 * </description>
 */
#define SYSCOMKEY_STRING_LINUX_RS485_RTS_PIN						"Linux.rs485.RTSPin"
#define SYSCOMKEY_STRING_LINUX_RS485_RTS_PIN_DEFAULT	        	"on_send"

/**
 * <category>Event parameter</category>
 * <element name="device" type="IN">Name of serial device</element>
 */
typedef struct
{
	unsigned char* name;
} EVTPARAM_SysComOpen;
#define EVTPARAMID_SysComOpen 0x0001
#define EVTVERSION_SysComOpen 0x0001

/**
 * <category>Events</category>
 * <description>Platform dependent event. Sent before the physical driver open.</description>
 * <param name="pEventParam" type="IN">EVTPARAM_SysComOpenBefore</param>
 */
#define EVT_SysComOpenBefore MAKE_EVENTID(EVTCLASS_INFO, 1)

/**
 * <category>Events</category>
 * <description>Platform dependent event. Sent directly after the physical driver open.</description>
 * <param name="pEventParam" type="IN">EVTPARAM_SysComOpenAfter</param>
 */
#define EVT_SysComOpenAfter MAKE_EVENTID(EVTCLASS_INFO, 2)


/** EXTERN LIB SECTION BEGIN **/
/*  Comments are ignored for m4 compiler so restructured text can be used. changecom(`/*', `*/') */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * <category>Baudrates</category>
 * <description>: Supported baudrates</description>
 */
#define SYS_BR_4800    RTS_IEC_DWORD_C(0x12C0)	
#define SYS_BR_9600    RTS_IEC_DWORD_C(0x2580)	
#define SYS_BR_19200    RTS_IEC_DWORD_C(0x4B00)	
#define SYS_BR_38400    RTS_IEC_DWORD_C(0x9600)	
#define SYS_BR_57600    RTS_IEC_DWORD_C(0xE100)	
#define SYS_BR_115200    RTS_IEC_DWORD_C(0x1C200)	
/* Typed enum definition */
#define SYS_COM_BAUDRATE    RTS_IEC_DWORD

/**
 * <category>DTR control</category>
 * <description>: DTR control configuration</description>
 */
#define SYS_DTR_CONTROL_DISABLE    RTS_IEC_BYTE_C(0x0)	/* <element name="SYS_DTR_CONTROL_DISABLE" TYPE="IN">Disables the DTR line when the device is opened and leaves it disabled.</element> */
#define SYS_DTR_CONTROL_ENABLE    RTS_IEC_BYTE_C(0x1)	/* <element name="SYS_DTR_CONTROL_ENABLE" TYPE="IN">Enables the DTR line when the device is opened and leaves it on.</element> */
#define SYS_DTR_CONTROL_HANDSHAKE    RTS_IEC_BYTE_C(0x2)	/* <element name="SYS_DTR_CONTROL_HANDSHAKE" TYPE="IN">Enables DTR handshaking.</element> */
/* Typed enumeration definition */
#define SYS_COM_DTR_CONTROL    RTS_IEC_BYTE

/**
 * <category>Parity</category>
 * <description>: Supported parity</description>
 */
#define SYS_NOPARITY    RTS_IEC_BYTE_C(0x0)	/* <element name="SYS_NOPARITY" TYPE="IN">No parity</element> */
#define SYS_ODDPARITY    RTS_IEC_BYTE_C(0x1)	/* <element name="SYS_ODDPARITY" TYPE="IN">Odd parity</element> */
#define SYS_EVENPARITY    RTS_IEC_BYTE_C(0x2)	/* <element name="SYS_EVENPARITY" TYPE="IN">Even parity</element> */
/* Typed enumeration definition */
#define SYS_COM_PARITY    RTS_IEC_BYTE

/**
 * <category>Com ports</category>
 * <description>: Supported com port numbers</description>
 */
#define SYS_COMPORT_NONE    RTS_IEC_INT_C(0x0)	
#define SYS_COMPORT1    RTS_IEC_INT_C(0x1)	
#define SYS_COMPORT2    RTS_IEC_INT_C(0x2)	
#define SYS_COMPORT3    RTS_IEC_INT_C(0x3)	
#define SYS_COMPORT4    RTS_IEC_INT_C(0x4)	
/* Typed enumeration definition */
#define SYS_COM_PORTS    RTS_IEC_INT

/**
 * <category>RTS control</category>
 * <description>: RTS control configuration</description>
 */
#define SYS_RTS_CONTROL_DISABLE    RTS_IEC_BYTE_C(0x0)	/* <element name="SYS_RTS_CONTROL_DISABLE" TYPE="IN">Disables the RTS line when the device is opened and leaves it disabled.</element> */
#define SYS_RTS_CONTROL_ENABLE    RTS_IEC_BYTE_C(0x1)	/* <element name="SYS_RTS_CONTROL_ENABLE" TYPE="IN">Enables the RTS line when the device is opened and leaves it on.</element> */
#define SYS_RTS_CONTROL_HANDSHAKE    RTS_IEC_BYTE_C(0x2)	/* <element name="SYS_RTS_CONTROL_HANDSHAKE" TYPE="IN">Enables RTS handshaking.</element> */
#define SYS_RTS_CONTROL_TOGGLE    RTS_IEC_BYTE_C(0x3)	/* <element name="SYS_RTS_CONTROL_TOGGLE" TYPE="IN">Specifies that the RTS line will be high if bytes are available for transmission. After all buffered bytes have been sent, the RTS line will be low.</element> */
/* Typed enumeration definition */
#define SYS_COM_RTS_CONTROL    RTS_IEC_BYTE

/**
 * <category>Stop bits</category>
 * <description>: Supported stop bits</description>
 */
#define SYS_ONESTOPBIT    RTS_IEC_BYTE_C(0x1)	
#define SYS_ONE5STOPBITS    RTS_IEC_BYTE_C(0x2)	
#define SYS_TWOSTOPBITS    RTS_IEC_BYTE_C(0x3)	
/* Typed enumeration definition */
#define SYS_COM_STOPBITS    RTS_IEC_BYTE

/**
 * <category>Timeouts</category>
 * <description>: Specified standard timeouts</description>
 */
#define SYS_NOWAIT    RTS_IEC_UDINT_C(0x0)	
#define SYS_INFINITE    RTS_IEC_UDINT_C(0xFFFFFFFF)	
/* Typed enumeration definition */
#define SYS_COM_TIMEOUT    RTS_IEC_UDINT

/**
 * <category>Com port settings</category>
 * <description>: Settings to open and to configure a COM interface</description>
 */
typedef struct tagSysComSettings
{
	RTS_IEC_INT sPort;		/* <element name="sPort" type="IN">Port number: 0=disabled, 1=COM1, 2=COM2, .... See SYS_COM_PORTS for predefined values.</element> */
	RTS_IEC_BYTE byStopBits;		/* <element name="byStopBits" type="IN">Stop bits. See SYS_COM_STOPBITS for details.</element> */
	RTS_IEC_BYTE byParity;		/* <element name="byParity" type="IN">Parity. See SYS_COM_PARITY for details.</element> */
	RTS_IEC_DWORD ulBaudrate;		/* <element name="ulBaudRate" type="IN">Baudrate. See SYS_COM_BAUDRATE for details.</element> */
	RTS_IEC_UDINT ulTimeout;		/* <element name="ulTimeout" TYPE="IN">Hardware timeout. The Timeout is the TIME between two received OR sent
	 	characters until the read or write operation will return.
		Typically this value should be 0 (returns immediately)
		See SYS_COM_TIMEOUT for predefined values.
 </element> */
	RTS_IEC_UDINT ulBufferSize;		/* <element name="ulBufferSize" type="IN">Buffer size of FIFO buffer</element> */
} SysComSettings;

/**
 * <category>Com port extended settings</category>
 * <description>: This structure can be used to get and set the settings of a COM port.
 *
 * NOTE:
 * The difference of this structure to SysComSettingsEx are the 2 members byDtrControl and byRtsControl! Here you can specify BYTE instead of BOOL values in SysComSettingsEx!  
 *	</description>
 */
typedef struct tagSysComSettingsEx
{
	RTS_IEC_BYTE byByteSize;		/* <element name="byByteSize" TYPE="IN">Number of bits/BYTE, 4-8</element> */
	RTS_IEC_BOOL bBinary;		/* <element name="bBinary" TYPE="IN">Binary mode, no EOF check</element> */
	RTS_IEC_BOOL bOutxCtsFlow;		/* <element name="bOutxCtsFlow" TYPE="IN">CTS handshaking on output</element> */
	RTS_IEC_BOOL bOutxDsrFlow;		/* <element name="bOutxDsrFlow" TYPE="IN">DSR handshaking on output</element> */
	RTS_IEC_BYTE byDtrControl;		/* <element name="byDtrControl" TYPE="IN">DTR (data-terminal-ready) flow control. See SYS_COM_DTR_CONTROL for possible values.</element> */
	RTS_IEC_BOOL bDsrSensitivity;		/* <element name="bDsrSensitivity" TYPE="IN">DSR Sensitivity</element> */
	RTS_IEC_BYTE byRtsControl;		/* <element name="byRtsControl" TYPE="IN">Rts (request-to-send) flow control. See SYS_COM_RTS_CONTROL for possible values.</element> */
	RTS_IEC_BOOL bTXContinueOnXoff;		/* <element name="bTXContinueOnXoff" TYPE="IN">XOFF continues Tx</element> */
	RTS_IEC_BOOL bOutX;		/* <element name="bOutX" TYPE="IN">XON/XOFF out flow control</element> */
	RTS_IEC_BOOL bInX;		/* <element name="bInX" TYPE="IN">XON/XOFF in flow control</element> */
	RTS_IEC_BYTE byXonChar;		/* <element name="XonChar" TYPE="IN">Tx AND Rx XON character</element> */
	RTS_IEC_BYTE byXoffChar;		/* <element name="XoffChar" TYPE="IN">Tx AND Rx XOFF character</element> */
	RTS_IEC_WORD wXonLim;		/* <element name="XonLim" TYPE="IN">transmit XON threshold</element> */
	RTS_IEC_WORD wXoffLim;		/* <element name="XoffLim" TYPE="IN">transmit XOFF threshold</element> */
} SysComSettingsEx;

/**
 * <description>Close a serial communication device.</description>
 * <result><p>RESULT: Returns the runtime system error code (see CmpErrors.library).</p></result>
 */
typedef struct tagsyscomclose_struct
{
	RTS_IEC_HANDLE hCom;				/* VAR_INPUT */	/* <param name="hCom" type="IN">Handle to com port to close</param> */
	RTS_IEC_RESULT SysComClose;			/* VAR_OUTPUT */	
} syscomclose_struct;

DEF_API(`void',`CDECL',`syscomclose',`(syscomclose_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xACD27C01),0x03050F00)

/**
 * <description>Get the parameter of the interface specified by handle.
 * Use SysComGetSettings2()! This function should only be used for backward compatibility!
 * </description>
 * <result><p>RESULT: Returns the runtime system error code (see CmpErrors.library).</p></result>
 */
typedef struct tagsyscomgetsettings_struct
{
	RTS_IEC_HANDLE hCom;				/* VAR_INPUT */	/* <param name="hCom" type="IN">Handle to com port</param> */
	SysComSettings *pSettings;			/* VAR_INPUT */	/* <param name="pSettings" type="IN">Pointer to get settings</param> */
	SysComSettingsEx *pSettingsEx;		/* VAR_INPUT */	/* <param name="pSettingsEx" type="IN">Pointer to get extended settings</param> */
	RTS_IEC_RESULT SysComGetSettings;	/* VAR_OUTPUT */	
} syscomgetsettings_struct;

DEF_API(`void',`CDECL',`syscomgetsettings',`(syscomgetsettings_struct *p)',1,0,0x03050F00)

/**
 * <description>Open a serial communication device.</description>
 * <result><p>RESULT: Handle to the opened com port or RTS_INVALID_HANDLE if failed</p></result>
 */
typedef struct tagsyscomopen_struct
{
	RTS_IEC_INT sPort;					/* VAR_INPUT, Enum: SYS_COM_PORTS */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* <param name="pResult" type="OUT">Pointer to runtime system error code (see CmpErrors.library)</param> */
	RTS_IEC_HANDLE SysComOpen;			/* VAR_OUTPUT */	
} syscomopen_struct;

DEF_API(`void',`CDECL',`syscomopen',`(syscomopen_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x1CE3B492),0x03050F00)

/**
 * <description>Opens a serial communication device specified by settings</description>
 * <result><p>RESULT: Handle to the opened com port or RTS_INVALID_HANDLE if failed</p></result>
 */
typedef struct tagsyscomopen2_struct
{
	SysComSettings *pSettings;			/* VAR_INPUT */	/* <param name="pSettings" type="IN">Settings for the communication device.
	See category "Com port settings" for detailed information</param> */
	SysComSettingsEx *pSettingsEx;		/* VAR_INPUT */	/* <param name="pSettingsEx" type="IN">Optional extended settings for the serial device. Can be 0.</param> */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* <param name="pResult" type="OUT">Pointer to runtime system error code (see CmpErrors.library)</param> */
	RTS_IEC_HANDLE SysComOpen2;			/* VAR_OUTPUT */	
} syscomopen2_struct;

DEF_API(`void',`CDECL',`syscomopen2',`(syscomopen2_struct *p)',1,0,0x03050F00)

/**
 * <description>Clear the fifo buffer of the serial interface</description>
 * <result><p>RESULT: Returns the runtime system error code (see CmpErrors.library).</p></result>
 */
typedef struct tagsyscompurge_struct
{
	RTS_IEC_HANDLE hCom;				/* VAR_INPUT */	/* <param name="hCom" type="IN">Handle to com port</param> */
	RTS_IEC_RESULT SysComPurge;			/* VAR_OUTPUT */	
} syscompurge_struct;

DEF_API(`void',`CDECL',`syscompurge',`(syscompurge_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xC2A013BE),0x03050F00)

/**
 * <description>Reads the number of bytes from the receive buffer of the specified device.
 * <p>IMPLEMENTATION NOTE:
 * If the timeout elapsed until the requested number of bytes are received,
 *	the function returns the number of bytes already received! This must be considered in the caller and
 *	the implementation!</p></description>
 * <result><p>RESULT: Number of actual read bytes</p></result>
 */
typedef struct tagsyscomread_struct
{
	RTS_IEC_HANDLE hCom;				/* VAR_INPUT */	/* <param name="hCom" type="IN">Handle to com port</param> */
	RTS_IEC_BYTE *pbyBuffer;			/* VAR_INPUT */	/* <param name="pbyBuffer" type="IN">Pointer to data buffer for received data</param> */
	RTS_IEC_UDINT ulSize;				/* VAR_INPUT */	/* <param name="uiSize" type="IN">Requested number of bytes to read. Must be less or equal the size
	of the receive buffer!</param> */
	RTS_IEC_UDINT ulTimeout;			/* VAR_INPUT, Enum: SYS_COM_TIMEOUT */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* <param name="pResult" type="OUT">Pointer to return the runtime system error code (see CmpErrors.library).</param> */
	RTS_IEC_UDINT SysComRead;			/* VAR_OUTPUT */	
} syscomread_struct;

DEF_API(`void',`CDECL',`syscomread',`(syscomread_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xDEDB5081),0x03050F00)

/**
 * <description>Set the parameter of the interface specified by handle.
 * Use SysComSetSettings2()! This function should only be used for backward compatibility!
 * </description>
 * <result><p>RESULT: Returns the runtime system error code (see CmpErrors.library).</p></result>
 */
typedef struct tagsyscomsetsettings_struct
{
	RTS_IEC_HANDLE hCom;				/* VAR_INPUT */	/* <param name="hCom" type="IN">Handle to com port</param> */
	SysComSettings *pSettings;			/* VAR_INPUT */	/* <param name="pSettings" type="IN">Pointer to new settings</param> */
	SysComSettingsEx *pSettingsEx;		/* VAR_INPUT */	/* <param name="pSettingsEx" type="IN">OPTIONAL: Pointer to extended settings or 0</param> */
	RTS_IEC_RESULT SysComSetSettings;	/* VAR_OUTPUT */	
} syscomsetsettings_struct;

DEF_API(`void',`CDECL',`syscomsetsettings',`(syscomsetsettings_struct *p)',1,0,0x03050F00)

/**
 * <description>Set the timeout of the specified serial interface (hardware timeout).
 *	The Timeout is the time between two received or sent characters until the read or write operation
 *	will return. Typically this value should be 0 (returns immediately)</description>
 * <result><p>RESULT: Returns the runtime system error code (see CmpErrors.library).</p></result>
 */
typedef struct tagsyscomsettimeout_struct
{
	RTS_IEC_HANDLE hCom;				/* VAR_INPUT */	/* <param name="hCom" type="IN">Handle to com port</param> */
	RTS_IEC_UDINT ulTimeout;			/* VAR_INPUT, Enum: SYS_COM_TIMEOUT */
	RTS_IEC_RESULT SysComSetTimeout;	/* VAR_OUTPUT */	
} syscomsettimeout_struct;

DEF_API(`void',`CDECL',`syscomsettimeout',`(syscomsettimeout_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x2E035E87),0x03050F00)

/**
 * <description><p>Writes the number of bytes to the send buffer of the specified device.</p>
 * <p>IMPLEMENTATION NOTE:
 * If the timeout elapsed until the requested number of bytes are sent,
 *	the function returns the number of bytes already sent! This must be considered in the caller and
 *	the implementation!</p></description>
 * <result><p>RESULT: Number of actual written bytes</p></result>
 */
typedef struct tagsyscomwrite_struct
{
	RTS_IEC_HANDLE hCom;				/* VAR_INPUT */	/* <param name="hCom" type="IN">Handle to com port</param> */
	RTS_IEC_BYTE *pbyBuffer;			/* VAR_INPUT */	/* <param name="pbyBuffer" type="IN">Pointer to data buffer for sent data</param> */
	RTS_IEC_UDINT ulSize;				/* VAR_INPUT */	/* <param name="uiSize" type="IN">Requested number of bytes to sent. Must be less or equal the size
	of the sent buffer!</param> */
	RTS_IEC_UDINT ulTimeout;			/* VAR_INPUT, Enum: SYS_COM_TIMEOUT */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* <param name="pResult" type="OUT">Pointer to return the runtime system error code (see CmpErrors.library).</param> */
	RTS_IEC_UDINT SysComWrite;			/* VAR_OUTPUT */	
} syscomwrite_struct;

DEF_API(`void',`CDECL',`syscomwrite',`(syscomwrite_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xA00AEE60),0x03050F00)

#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/


typedef SysComSettings		COMSettings;
typedef SysComSettingsEx	COMSettingsEx;
typedef SysComSettings		COM_Settings;
typedef SysComSettingsEx	COM_SettingsEx;

#ifdef __cplusplus
extern "C" {
#endif

/* Initialization routines for OS specific modules */
RTS_RESULT CDECL SysComOSInit(INIT_STRUCT *pInit);
RTS_RESULT CDECL SysComOSHookFunction(RTS_UI32 ulHook, RTS_UINTPTR ulParam1, RTS_UINTPTR ulParam2);

/**
 * <description>Open a serial communication device</description>
 * <param name="sPort" type="IN">Number of the Port to open: 1=COM1, 2=COM2, ...</param>
 * <param name="pResult" type="OUT">Pointer to error code </param>
 * <result>Handle to the interface or RTS_INVALID_HANDLE if failed</result>
 */
DEF_CREATEITF_API(`RTS_HANDLE',`CDECL',`SysComOpen',`(short sPort, RTS_RESULT *pResult)')

/**
 * <description>Opens a serial communication device specified with settings</description>
 * <param name="pSettings" type="IN">Settings for the communication device. 
 *	See category "Com port settings" for detailed information</param>
 * <param name="pSettingsEx" type="IN">Optional extended settings for the serial device. Can be NULL.</param>
 * <param name="pResult" type="OUT">Pointer to error code </param>
 * <result>Handle to the interface or RTS_INVALID_HANDLE if failed</result>
 */
DEF_CREATEITF_API(`RTS_HANDLE',`CDECL',`SysComOpen2',`(SysComSettings *pSettings, SysComSettingsEx *pSettingsEx, RTS_RESULT *pResult)')

/**
 * <description>Set the parameter of the interface specified by handle</description>
 * <param name="hCom" type="IN">Handle to Com Port</param>
 * <param name="pSettings" type="IN">Pointer to new settings</param>
 * <param name="pSettingsEx" type="IN">Pointer to extended settings</param>
 * <result>error code</result>
 */
DEF_HANDLEITF_API(`RTS_RESULT',`CDECL',`SysComSetSettings',`(RTS_HANDLE hCom, SysComSettings *pSettings, SysComSettingsEx *pSettingsEx)')

/**
 * <description>Get the parameter of the interface specified by handle</description>
 * <param name="hCom" type="IN">Handle to Com Port</param>
 * <param name="pSettings" type="IN">Pointer to new settings</param>
 * <param name="pSettingsEx" type="IN">Pointer to extended settings</param>
 * <result>error code</result>
 */
DEF_HANDLEITF_API(`RTS_RESULT',`CDECL',`SysComGetSettings',`(RTS_HANDLE hCom, SysComSettings *pSettings, SysComSettingsEx *pSettingsEx)')

/**
 * <description>Close a serial communication device</description>
 * <param name="hCom" type="IN">Handle to com port</param>
 * <result>error code</result>
 */
DEF_DELETEITF_API(`RTS_RESULT',`CDECL',`SysComClose',`(RTS_HANDLE hCom)')

/**
 * <description>Reads a number bytes from the specified device to the receive buffer.
 *
 * <p>IMPLEMENTATION NOTE: If the timeout elapsed until the requested number of bytes are received,
 *	the function returns with the bytes still received! This must be considered in the caller and
 *	the implementation!</p></description>
 *
 * <param name="hCom" type="IN">Handle to com port</param>
 * <param name="pbyBuffer" type="IN">Pointer to data buffer for received data</param>
 * <param name="uiSize" type="IN">Requested number of bytes to read. Must be less or equal the size
 *	of the receive buffer!</param>
 * <param name="ulTimeout" type="IN">Timeout to read data from the device. 0=Immediate return.
 *	If the timeout elapsed, the function returns with the still received data (could be less then the 
 *	requested number of bytes!)</param>
 * <param name="pResult" type="IN">Pointer to error code, ERR_TIMEOUT if timeout elapsed</param>
 * <result>Number of actually read bytes</result>
 */
DEF_HANDLEITF_API(`RTS_UI32',`CDECL',`SysComRead',`(RTS_HANDLE hCom, unsigned char *pbyBuffer, RTS_UI32 uiSize, RTS_UI32 ulTimeout, RTS_RESULT *pResult)')

/**
 * <description>Writes a number bytes to the specified device from the sent buffer.
 *
 * <p>IMPLEMENTATION NOTE: If the timeout elapsed until the requested number of bytes are sent,
 *	the function returns with the bytes still sent! This must be considered in the caller and
 *	the implementation!</p></description>
 *
 * <param name="hCom" type="IN">Handle to com port</param>
 * <param name="pbyBuffer" type="IN">Pointer to data buffer for sent data</param>
 * <param name="uiSize" type="IN">Requested number of bytes to sent. Must be less or equal the size
 *	of the sent buffer!</param>
 * <param name="ulTimeout" type="IN">Timeout to sent data to the device. 0=Immediate return.
 *	If the timeout elapsed, the function returns with the still sent data (could be less then the 
 *	requested number of bytes!)</param>
 * <param name="pResult" type="IN">Pointer to error code, ERR_TIMEOUT if timeout elapsed</param>
 * <result>Number of actually written bytes</result>
 */
DEF_HANDLEITF_API(`RTS_UI32',`CDECL',`SysComWrite',`(RTS_HANDLE hCom, unsigned char *pbyBuffer, RTS_UI32 uiSize, RTS_UI32 ulTimeout, RTS_RESULT *pResult)')

 /**
 * <description>Clear the FIFO buffer of the serial interface</description>
 * <param name="hCom" type="IN">Handle to com port</param>
 * <result>error code</result>
 */
DEF_HANDLEITF_API(`RTS_RESULT',`CDECL',`SysComPurge',`(RTS_HANDLE hCom)')

/**
 * <description>Set the timeout of the specified serial interface (hardware timeout).
 *	The Timeout is the time between two received or sent characters until the read or write operation
 *	will return. Typically this value should be 0 (returns immediately)</description>
 * <param name="hCom" type="IN">Handle to com port</param>
 * <param name="ulTimeout" type="IN">Timeout to set</param>
 * <result>error code</result>
 */
DEF_HANDLEITF_API(`RTS_RESULT',`CDECL',`SysComSetTimeout',`(RTS_HANDLE hCom, RTS_UI32 ulTimeout)')


#ifdef __cplusplus
}
#endif
