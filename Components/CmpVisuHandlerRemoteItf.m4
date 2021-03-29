/**
 * <interfacename>CmpVisuHandlerRemote</interfacename>
 * <description> 
 *	Interface for the remote visualization handler.
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`CmpVisuHandlerRemote')

REF_ITF(`CmpTlsItf.m4')

#ifndef MAX_LEN_APPLNAME
	#define MAX_LEN_APPLNAME					60
#endif	/* MAX_LEN_APPLNAME */

#ifndef MAX_LEN_USERNAME	
	#define MAX_LEN_USERNAME					30
#endif	/* MAX_LEN_USERNAME */

#ifndef MAX_LEN_PASSWORD
	#define MAX_LEN_PASSWORD					30
#endif	/* MAX_LEN_PASSWORD */

#ifndef MAX_LEN_PLCNAME
	#define MAX_LEN_PLCNAME						60
#endif /* MAX_LEN_PLCNAME */

#ifndef MAX_LEN_TCPADDR
	#define MAX_LEN_TCPADDR						60
#endif /* MAX_LEN_TCPADDR */


/**
 * <category>Compiler switch</category>
 * <description>
 *	Compiler switches to trigger special behavior of this component.
 * </description>
 * <element name="VISH_REMOTE_START_IN_COMM_CYCLE">Usually the remote target-visualization starts it's communication in the component manager hook CH_INIT_TASKS.
 *				When this define is active, then this startup is delayed until the first call of the hook CH_COMM_CYCLE.
 *				Typically this can be used if other components (or startup code) want to attach to the event <see>EVT_CmpVisuHandlerRemote_CheckAutoStartup</see>
 *				for being able to do a startup at a different point of time while having the runtime system functionality already available.
 * </element>
 */
 
/**
 * <category>Settings</category>
 * <description>The address this remote client should connect to. When an explicit communication address is
 *	assigned, then the setting <see>CMPVISUHANDLERREMOTE_KEY_VISURUNTIME_PLCNAME</see> and 
 *	<see>CMPVISUHANDLERREMOTE_KEY_VISURUNTIME_TCP_ADDRESS</see> will be ignored.</description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISURUNTIME_ADDRESS						"Communication.AddressDest"
#define CMPVISUHANDLERREMOTE_KEY_VISURUNTIME_ADDRESS_DEFAULT				""

/**
 * <category>Settings</category>
 * <description>The name of the PLC this remote client should connect to If this mode is used, then
 *	a network scan will be used for finding the according device. When an explicit communication address is
 *	assigned in <see>CMPVISUHANDLERREMOTE_KEY_VISURUNTIME_ADDRESS</see>, then this setting will be ignored.
 *	To be able to use this feature, the component CmpNameServiceClient must be available!
 *	</description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISURUNTIME_PLCNAME						"Communication.PlcNameDest"
#define CMPVISUHANDLERREMOTE_KEY_VISURUNTIME_PLCNAME_DEFAULT				""

/**
 * <category>Settings</category>
 * <description>This setting is similar than <see>CMPVISUHANDLERREMOTE_KEY_VISURUNTIME_PLCNAME</see> with the difference that 
 *	it allows an ASCII value for the PLC name. If <see>CMPVISUHANDLERREMOTE_KEY_VISURUNTIME_PLCNAME</see> is given too, that one
 *	will be preferred.
 *	</description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISURUNTIME_PLCNAMEA						"Communication.PlcNameDestA"
#define CMPVISUHANDLERREMOTE_KEY_VISURUNTIME_PLCNAMEA_DEFAULT				CMPVISUHANDLERREMOTE_KEY_VISURUNTIME_PLCNAME_DEFAULT

/**
 * <category>Settings</category>
 * <description>The IP address this remote client should connect to using CmpBlkDrvTcp. If this type of communication address
 *	is configured, then the port can be configured using <see>CMPVISUHANDLERREMOTE_KEY_VISURUNTIME_TCP_ADDRESS_PORT</see>
 *	too if it differs from the default port.</description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISURUNTIME_TCP_ADDRESS					"Communication.TcpAddressDest"
#define CMPVISUHANDLERREMOTE_KEY_VISURUNTIME_TCP_ADDRESS_DEFAULT			""

/**
 * <category>Settings</category>
 * <description>The TCP port this remote client should connect to using CmpBlkDrvTcp. Will be evaluated only when
 *	<see>CMPVISUHANDLERREMOTE_KEY_VISURUNTIME_TCP_ADDRESS</see> is configured. If nothing is configured, in fact the default value -1,
 *	then the default port of CmpBlkDrvTcp will be used.</description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISURUNTIME_TCP_ADDRESS_PORT				"Communication.TcpAddressDestPort"
#define CMPVISUHANDLERREMOTE_KEY_VISURUNTIME_TCP_ADDRESS_PORT_DEFAULT		-1

/**
 * <category>Settings</category>
 * <description>The size of the communication buffer that should be used.</description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISUCOMMBUFFER_SIZE						"Communication.BufferSize"
#define CMPVISUHANDLERREMOTE_KEY_VISUCOMMBUFFER_SIZE_DEFAULT				INT32_C(50000)

/**
 * <category>Settings</category>
 * <description>The size of the communication buffer that should be used.</description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISUCOMMTASK_INTERVAL						"Communication.TaskInterval"
#define CMPVISUHANDLERREMOTE_KEY_VISUCOMMTASK_INTERVAL_DEFAULT				50

/**
 * <category>Settings</category>
 * <description>The priority of the communication task used for the remote targetvisualization.</description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISUCOMMTASK_PRIORITY						"Communication.TaskPriority"
#define CMPVISUHANDLERREMOTE_KEY_VISUCOMMTASK_PRIORITY_DEFAULT				80

/**
 * <category>Settings</category>
 * <description>The priority of the communication task used for the encrypted communication of the remote targetvisualization.</description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISUCOMMTASK_ENCRYPTED_PRIORITY			"Communication.TaskPriorityEncryptedComm"
#ifndef CMPVISUHANDLERREMOTE_KEY_VISUCOMMTASK_ENCRYPTED_PRIORITY_DEFAULT
	#define CMPVISUHANDLERREMOTE_KEY_VISUCOMMTASK_ENCRYPTED_PRIORITY_DEFAULT	TASKPRIO_HIGH_BASE
#endif

/**
 * <category>Settings</category>
 * <description>The time that will be waited before a reconnect is done (in case of a communication error etc.). If 
 *	a value of 0 is given, there won't be a reconnect. The application will then shutdown in case of an error.</description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISUCOMM_RECONNECT_WAITTIME				"Communication.ReconnectTimeMs"
#define CMPVISUHANDLERREMOTE_KEY_VISUCOMM_RECONNECT_WAITTIME_DEFAULT		INT32_C(5000)

/**
 * <category>Settings</category>
 * <description>The time that will be waited before for the result of a network scan (in case CMPVISUHANDLERREMOTE_KEY_VISURUNTIME_PLCNAME 
 *	is used).</description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISUCOMM_NETWORKSCAN_TIME					"Communication.NetworkScanTimeMs"
#define CMPVISUHANDLERREMOTE_KEY_VISUCOMM_NETWORKSCAN_TIME_DEFAULT			INT32_C(2000)

/**
 * <category>Settings</category>
 * <description>The maximum time that will be waited for the answer to a service request that is sent to the PLC in milliseconds.
 *	A negative value will be an infinite timeout.</description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISUCOMM_SERVICE_TIMEOUT					"Communication.ServiceTimeoutMs"
#define CMPVISUHANDLERREMOTE_KEY_VISUCOMM_SERVICE_TIMEOUT_DEFAULT			INT32_C(-1)

/**
 * <category>Settings</category>
 * <description>This setting specifies whether an application login is done during connecting to the PLC. This login
 * is necessary to check for a currently executing download that might take a longer time to prevent follow up issues like
 * missing images. In case this application login is not possible (maybe due to access rights) and therefore should
 * be omitted at all, this value can be set to 0.</description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISUCOMM_EXECUTE_APPLOGIN					"Communication.ExecuteApplicationLogin"
#define CMPVISUHANDLERREMOTE_KEY_VISUCOMM_EXECUTE_APPLOGIN_DEFAULT			INT32_C(1)

/**
 * <category>Settings</category>
 * <description>This setting specifies the way the remote targetvisu communicates with the PLC. At the moment
	only the following two setting values are supported:
	0: Don't use encrypted communication.
	1: Communicate in an encrypted way. This means that the operator either has to install certificates of the PLC or accept the 
		certificate during communication setup.
	</description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISUCOMM_ENCRYPTION_MODE					"Communication.EncryptionMode"
#ifndef CMPVISUHANDLERREMOTE_KEY_VISUCOMM_ENCRYPTION_MODE_DEFAULT
	#define CMPVISUHANDLERREMOTE_KEY_VISUCOMM_ENCRYPTION_MODE_DEFAULT			INT32_C(0)
#endif

/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>This setting allows to override the ciphersuite that should be used for encrypted communication. For details of the syntax please
	refer to the description of the setting TLSKEY_STR_CTX_CIPHER_LIST
	</description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISUCOMM_ENCRYPTION_CIPHERS					"Communication.EncryptionCipherSuite"
#ifndef CMPVISUHANDLERREMOTE_KEY_VISUCOMM_ENCRYPTION_CIPHERS_DEFAULT
	#define CMPVISUHANDLERREMOTE_KEY_VISUCOMM_ENCRYPTION_CIPHERS_DEFAULT			TLSVALUE_STR_CTX_CIPHER_LIST_DEFAULT
#endif

/**
 * <category>Settings</category>
 * <description>The size of the paint-buffer for the visualization that should be used. This size should be at 
 *	least the size of the communication buffer</description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_PAINTBUFFER_SIZE				"VisuClient.PaintBufferSize"
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_PAINTBUFFER_SIZE_DEFAULT		INT32_C(50000)

/**
 * <category>Settings</category>
 * <description>The name of the visualization application on the PLC.</description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_VISUAPPNAME						"VisuClient.VisuAppName"
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_VISUAPPNAME_DEFAULT				""

/**
 * <category>Settings</category>
 * <description>The name of the start-visualization that should be displayed.</description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_STARTVISU						"VisuClient.StartVisu"
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_STARTVISU_DEFAULT				"PLC_VISU"

/**
 * <category>Settings</category>
 * <description>The setting for anti-aliasing. Currently supported are (depending on the platform) 2 for high quality, 1 for low quality and 0 for
 * no anti-aliasing</description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_ANTIALIASING					"VisuClient.AntiAliasing"
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_ANTIALIASING_DEFAULT			2

/**
 * <category>Settings</category>
 * <description>The setting for best fit. Currently supported are 1 for activate best fit mode and 0 for deactivated best fit.</description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_BESTFIT							"VisuClient.BestFit"
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_BESTFIT_DEFAULT					0

/**
 * <category>Settings</category>
 * <description>The setting best fit for dialogs. Currently supported are 1 for activate best fit for dialogs mode and 0 for deactivated best fit for dialogs. If this setting is set dialogs are scaled in the same way as top level visualizations</description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_BESTFITFORDIALOGS							"VisuClient.BestFitForDialogs"
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_BESTFITFORDIALOGS_DEFAULT					0

/**
 * <category>Settings</category>
 * <description>The setting for scale type isotropic in best fit mode. Currently supported are 1 for activate scale type isotropic mode and 0 for deactivated scale type isotropic mode.</description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_SCALETYPEISOTROPIC							"VisuClient.ScaleTypeIsotropic"
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_SCALETYPEISOTROPIC_DEFAULT					0

/**
 * <category>Settings</category>
 * <description>The setting for touch handling. Currently supported are 1 for activate touch handling mode and 0.</description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_TOUCHHANDLING					"VisuClient.Touchhandling"
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_TOUCHHANDLING_DEFAULT			0

/**
 * <category>Settings</category>
 * <description>The setting for keyboard usage. Currently supported are 1 for activating keyboard usage and 0.</description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_KEYBOARD						"VisuClient.Keyboard"
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_KEYBOARD_DEFAULT				0

/**
 * <category>Settings</category>
 * <description>The setting for benchmarking. Currently supported are 1 to activate benchmarking measurements 0 (off, default).
 *	The intention of this setting is to measure execution time of the visualization. It is not intended for use in production environments.</description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_BENCHMARKING					"VisuClient.Benchmarking"
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_BENCHMARKING_DEFAULT			0

/**
 * <category>Settings</category>
 * <description>The setting for the number of attempts to load an image.</description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_IMAGE_LOAD_ATTEMPTS				"VisuClient.ImageLoadAttempts"
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_IMAGE_LOAD_ATTEMPTS_DEFAULT		3

/**
 * <category>Settings</category>
 * <description>An optional name for the visualization name. This name can optionally be used to distinguish between different clients 
 *	within the application. Default value is the empty string.</description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_CLIENTNAME						"VisuClient.Name"
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_CLIENTNAME_DEFAULT				""

/**
 * <category>Settings</category>
 * <description>The name of the user used for logging in to the remote PLC.</description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISUCREDENTIALS_USERNAME					"Credentials.UserName"
#define CMPVISUHANDLERREMOTE_KEY_VISUCREDENTIALS_USERNAME_DEFAULT			""

/**
 * <category>Settings</category>
 * <description>The password of the user used for logging in to the remote PLC. This setting is the way for
 *	manual configuration of the password.</description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISUCREDENTIALS_PASSWORD					"Credentials.Password"
#define CMPVISUHANDLERREMOTE_KEY_VISUCREDENTIALS_PASSWORD_DEFAULT			""

/**
 * <category>Settings</category>
 * <description>The obfuscated value of the user's password.</description>
 * <remarks>As the application must be able to decrypt the password to send it to the connected PLC, we can use only
 *	a symmetric encryption algorithm. For that reason, a cryptographically secure storage of the password is not possible
 *	this way. This is merely the prevention of users having a chance of looking at the configuration file to see the 
 *	password in clear-text.
 *	This setting will be created automatically during startup of the remote target-visualization if <see>CMPVISUHANDLERREMOTE_KEY_VISUCREDENTIALS_PASSWORD</see>
 *	is found in the configuration. For that reason this is not a value that is intended to be written by the user.
 *	</remarks>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISUCREDENTIALS_PASSWORD_OBFUSCATED		"Credentials.Obfuscated"
#define CMPVISUHANDLERREMOTE_VISUCREDENTIALS_PASSWORD_OBFUSCATED_DEFAULT	""

 /**
 * <category>Settings</category>
 * <description>The time the connect cancel dialog will be visible. Set this value to 0 to disable the cancel dialog.</description>
 */
#define CMPVISUHANDLERREMOTE_SCANDIALOG_DISCONNECTWAIT					"ScanDialog.DisconnectWaitMs"
#ifndef CMPVISUHANDLERREMOTE_SCANDIALOG_DISCONNECTWAIT_DEFAULT
	#define CMPVISUHANDLERREMOTE_SCANDIALOG_DISCONNECTWAIT_DEFAULT			2000
#endif

 /**
 * <category>Settings</category>
 * <description>Setting that decides at which position and in which size
 * the scan dialog window should open.</description>
 *
 */
#define CMPVISUHANDLERREMOTE_SCANDIALOG_POSITIONX					"ScanDialog.PositionX"
#ifndef CMPVISUHANDLERREMOTE_SCANDIALOG_POSITIONX_DEFAULT
#define CMPVISUHANDLERREMOTE_SCANDIALOG_POSITIONX_DEFAULT			0
#endif
#define CMPVISUHANDLERREMOTE_SCANDIALOG_POSITIONY					"ScanDialog.PositionY"
#ifndef CMPVISUHANDLERREMOTE_SCANDIALOG_POSITIONY_DEFAULT
#define CMPVISUHANDLERREMOTE_SCANDIALOG_POSITIONY_DEFAULT			0
#endif
#define CMPVISUHANDLERREMOTE_SCANDIALOG_WIDTH						"ScanDialog.Width"
#ifndef CMPVISUHANDLERREMOTE_SCANDIALOG_WIDTH_DEFAULT
#define CMPVISUHANDLERREMOTE_SCANDIALOG_WIDTH_DEFAULT				0
#endif
#define CMPVISUHANDLERREMOTE_SCANDIALOG_HEIGHT						"ScanDialog.Height"
#ifndef CMPVISUHANDLERREMOTE_SCANDIALOG_HEIGHT_DEFAULT
#define CMPVISUHANDLERREMOTE_SCANDIALOG_HEIGHT_DEFAULT				0
#endif

/**
 * <category>Event parameter that is used before startup of the visualization.</category>
 * <element name="delayStartup" type="OUT">Set to TRUE if the remote target-visualization should not startup automatically.
 *	In this case a later on start can be triggered by calling <see>VishRemoteConnect</see>
 * </element>
 */
typedef struct
{
	RTS_BOOL delayStartup;
} EVTPARAM_CmpVisuHandlerRemoteCheckAutoStartupEventArgs;
#define EVTPARAMID_CmpVisuHandlerRemoteCheckAutoStartupEventArgs					0x0002
#define EVTVERSION_CmpVisuHandlerRemoteCheckAutoStartupEventArgs					0x0001

/**
 * <category>Events</category>
 * <description>Event is sent during startup before the remote target-visualization is becoming active or reading settings.
 *  The intention of this event is to allow components to delay the startup if necessary. By default, the visualization will start
 *	automatically.</description>
 * <param name="pEventParam" type="IN">EVTPARAM_CmpVisuHandlerRemoteEventArgs</param>
 */
#define EVT_CmpVisuHandlerRemote_CheckAutoStartup			MAKE_EVENTID(EVTCLASS_INFO, 2)

/**
 * <category>Event parameter</category>
 * <element name="hVHR_Instance" type="IN">The instance of the visualization handler remote</element>
 * <element name="hTargetVisu" type="IN">The instance of the target-visualization</element>
 * <element name="Result" type="IN">A result code</element>
 */
typedef struct
{
	RTS_HANDLE hVHR_Instance;
	RTS_HANDLE hTargetVisu;
	RTS_RESULT Result;
} EVTPARAM_CmpVisuHandlerRemoteEventArgs;
#define EVTPARAMID_CmpVisuHandlerRemoteEventArgs					0x0001
#define EVTVERSION_CmpVisuHandlerRemoteEventArgs					0x0001

/**
 * <category>Events</category>
 * <description>Event is sent when the visualization is running.</description>
 * <param name="pEventParam" type="IN">EVTPARAM_CmpVisuHandlerRemoteEventArgs</param>
 */
#define EVT_CmpVisuHandlerRemote_VisuRunning				MAKE_EVENTID(EVTCLASS_INFO, 1)

/**
 * <category>Settings</category>
 * <description>This setting is relevant for platforms, that show a system tray icon, that
 * allows access to the remote target visualization, e.g. to display the error messages.
 *  The values have the following meaning:
 *  - 0: System tray icon will be used
 *  - 1: System tray icon will be not used, a window will be displayed instead of
 * </description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_NOSYSTRAY					"VisuClient.NoSysTray"
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_NOSYSTRAY_DEFAULT			0

/**
 * <category>Settings</category>
 * <description>This setting defines the behavior, whether the wizard to configure the communication settings
 * should be displayed or not.
 *  The values have the following meaning:
 *  - 0: Wizard will be only shown if the configuration file is missing or contains no communication parameters (the default!)
 *  - 1: Wizard will be displayed and the communication settings can be saved persistently in the configuration file
 *  - 2: Wizard will be displayed and the communication settings will be not saved persistently in the configuration file,
 *       so that the wizard will be displayed again in the next program run.
 * <remarks>This setting is effective only when an according wizard functionality is implemented in the system specific part</remarks>
 * </description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_FORCEWIZARD					"VisuClient.ForceWizard"
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_FORCEWIZARD_DEFAULT			0

/**
 * <category>Settings</category>
 * <description>This setting defines the behavior of the device scan of the wizard to configure the communication settings.
 *  The values have the following meaning:
 *  - 0: No device ID specified. All found devices will be listed in the wizard (the default!)
 *  all other positive values: Will be used as filter criterion for the device type.
 * </description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_DEVICEID					"VisuClient.DeviceId"
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_DEVICEID_DEFAULT			0

/**
 * <category>Settings</category>
 * <description>This is the prefix of the keys, that are used to store the last used direct connections persistently.
 * Up to CMPVISUHANDLERREMOTE_DIRECTCONNECTION_MAXENTRIES such entries will be stored.
 * </description>
 */
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_DIRECTCONNECTION			"VisuClient.DirectConnection"
#define CMPVISUHANDLERREMOTE_KEY_VISUCLIENT_DIRECTCONNECTION_DEFAULT	""
#define CMPVISUHANDLERREMOTE_DIRECTCONNECTION_MAXENTRIES				8

/**
 * <description>
 *	This function can be called to start the remote target-visualization in a delayed way. Typically this is done when
 *	the event <see>EVT_CmpVisuHandlerRemote_CheckAutoStartup</see> is handled to delay the initial startup.
 * </description>
 * <param name="useTempSettings" type="IN">The connection relevant settings like address or name will be taken from settings prefixed
 *	with the prefix "TEMP." instead of the original name if this value is TRUE. The idea is that temporary settings can be realized
 *	without overwriting possibly existing persistent settings.</param>
 * <remarks>This call will fail if the remote target-visualization is already running.</remarks>
 * <result>error code</result>
*/
DEF_ITF_API(`RTS_RESULT', `CDECL', `VishRemoteConnect', `(RTS_BOOL useTempSettings)')

/**
 * <description>
 *	This function will be called if it is necessary to login to the PLC or a previous login attempt failed.
 * </description>
 * <param name="hCallerData" type="IN">An arbitrary object that will be forwarded to the callback functions</param>
 * <param name="pszUserBuffer" type="IN">A buffer for the user name. Will not be NULL.</param>
 * <param name="userBufferSize" type="IN">The size of <see>pszUserBuffer</see> in bytes.</param>
 * <param name="pszPasswordBuffer" type="IN">A buffer for the password. Will not be NULL.</param>
 * <param name="passwordBufferSize" type="IN">The size of <see>pszPasswordBuffer</see> in bytes.</param>
 * <result>Return FALSE to use the credentials. Return TRUE to cancel the surrounding operation.</result>
*/
typedef RTS_BOOL (CDECL *PFVishRemoteProvideCredentials)(RTS_HANDLE hCallerData, char* pszUserBuffer, RTS_SIZE userBufferSize, char* pszPasswordBuffer, RTS_SIZE passwordBufferSize);

/**
 * <description>
 *	This function will be called for each application on the PLC.
 * </description>
 * <param name="hCallerData" type="IN">An arbitrary object that will be forwarded to the callback functions</param>
 * <param name="pszApplicationName" type="IN">The name of the application on the PLC. Will not be NULL.</param>
*/
typedef void (CDECL *PFVishRemoteNotifyApplicationName)(RTS_HANDLE hCallerData, char* pszApplicationName);

/**
 * <description>
 *	This function reads the available applications from the connected PLC and returns them using the configured callback functions.
 * </description>
 * <param name="hCallerData" type="IN">An arbitrary object that will be forwarded to the callback functions</param>
 * <param name="pfProvideCredentials" type="IN">The callback function that will be called in case a login is required. Must not be NULL.</param>
 * <param name="pfAppCallback" type="IN">The callback function that will be called for each application on the connected PLC. Must not be NULL.</param>
 * <param name="bReadTempSettings" type="IN">If TRUE then temporary settings (beginning with "Temp.") are read from the configuration file are
 *             read, otherwise the "normal" settings</param>
 * <remarks>The callbacks will be called synchronously</remarks>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `VishRemoteReadApplications', `(RTS_HANDLE hCallerData, PFVishRemoteProvideCredentials pfProvideCredentials, PFVishRemoteNotifyApplicationName pfAppCallback, RTS_BOOL bReadTempSettings)')

/**
 * <description>
 *	Information representing the result of a certificate verification together with the information how to proceed.
 * </description>
 * <element name="VISH_VCRT_REJECT">The certificate was rejected by the user and therefore no encrypted communication can be setup.</element>
 * <element name="VISH_VCRT_REJECT_SHUTDOWN">The certificate was rejected by the user and therefore no encrypted communication can be setup. The application should shutdown.</element>
 * <element name="VISH_VCRT_ACCEPT_TEMP>The certificate was accepted by the user for the current session.</element>
 */
typedef enum
{
	VISH_VCRT_REJECT,
	VISH_VCRT_REJECT_SHUTDOWN,
	VISH_VCRT_ACCEPT_TEMP
} VishRemoteVertifyCertResult;

/**
 * <description>
 *	This function will be called during connection setup in case encrypted communication is used. The intention of
 *	the call is to verify the certificate that was returned by the connected PLC.
 * </description>
 * <param name="hCallerData" type="IN">The arbitrary object that was passed as hCallerData in <see>VishRemoteCertRegisterVerifyCallback</see></param>
 * <param name="hCert" type="IN">The handle to the X509 certificate that has to be verified</param>
 * <param name="preVerifyResult" type="IN">The result of the verification done by the system (like checking for known certificates, expired certificates).
 *	Depending on this first verification step and the content of the certificate the implementation of this function can decide how to proceed.
 * </param>
 * <result>One of the values from <see>VishRemoteVertifyCertResult</see> that signals how to proceed with the certificate and
 *	the according communication setup</result>
*/
typedef VishRemoteVertifyCertResult (CDECL *PFVishRemoteVerifyCertificate)(RTS_HANDLE hCallerData, RTS_HANDLE hCert, RTS_RESULT preVerifyResult);

/**
 * <description>
 *	This utility function can be used to format the contents of an X509 certificate so that the most relevant information can 
 *	be presented to the user.
 * </description>
 * <param name="hCert" type="IN">The handle to the X509 certificate that should be formatted in a textual way.</param>
 * <param name="pszBuffer" type="IN">The buffer that will be used for formatting the certificate information. Must not be NULL.</param>
 * <param name="bufferSize" type="IN">The size of the buffer (<seealso>bufferSize</seealso>) that will be used for formatting the certificate information.</param>
 * <remarks>The passed buffer should be sufficiently large (maybe ~1000 bytes) so that all relevant information of the certificate can
 *	be included.</remarks>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `VishRemoteCertFormatTextual', `(RTS_HANDLE hCert, char* pszBuffer, RTS_SIZE bufferSize)')

/**
 * <description>
 *	This function registers the given callback so that unknown certificates can be verified by the user if encrypted communication is used.
 * </description>
 * <param name="hCallerData" type="IN">An arbitrary object that will be forwarded to the callback function</param>
 * <param name="pfCallback" type="IN">The callback function that will be called in case a certificate has to be verified. Must not be NULL.</param>
 * <remarks>The callbacks will be called synchronously from an arbitrary thread.</remarks>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `VishRemoteCertRegisterVerifyCallback', `(RTS_HANDLE hCallerData, PFVishRemoteVerifyCertificate pfCallback)')

/**
 * <description>
 *	This function exports the given certificate to the default export location of certificates in BASE64 coding.
 * </description>
 * <param name="hCert" type="IN">The certificate to export.</param>
 * <param name="pszPathBuffer" type="OUT">Will be filled with the path the file was exported to. Should be big enough to hold file paths..</param>
 * <param name="bufferSize" type="IN">The size of <see>pszPathBuffer</see>.</param>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT', `CDECL', `VishRemoteCertExport', `(RTS_HANDLE hCert, char* pszPathBuffer, RTS_SIZE bufferSize)')
