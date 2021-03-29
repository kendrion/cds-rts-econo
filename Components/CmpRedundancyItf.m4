/**
 * <interfacename>CmpRedundancy</interfacename>
 * <description>
 *	Interface of the redundancy component.
 * </description>
 *
 * <copyright></copyright>
 */

SET_INTERFACE_NAME(`CmpRedundancy')
SET_PLACEHOLDER_NAME(`Redundancy Implementation')

#include "CmpItf.h"

/**
 * <description>Redundancy service Ids</description>
 */
#define RDCY_SRV_WRITESETT				0x01
#define RDCY_SRV_READSETT				0x02
#define RDCY_SRV_READETHERCATNICSETTING 0x03
#define RDCY_SRV_READRDCYSTATE			0x04
#define RDCY_SRV_SWITCHOVER				0x05
#define RDCY_SRV_SYNCHRONIZE			0x06
#define RDCY_SRV_SETSIMULATIONMODE		0x07
#define RDCY_SRV_SWITCHTOSTANDALONE		0x08
#define RDCY_SRV_SWITCHTOACTIVE			0x09

/**
 * <description>Redundancy service tag Ids</description>
 */
#define TAG_SESSION_ID						0x10
#define TAG_SETT_IPADDRESSLOCAL_FIRSTLINK	0x11
#define TAG_SETT_IPADDRESSPEER_FIRSTLINK	0x12
#define TAG_SETT_PORT_FIRSTLINK				0x13
#define TAG_SETT_USESECONDLINK				0x14
#define TAG_SETT_IPADDRESSLOCAL_SECONDLINK	0x15
#define TAG_SETT_IPADDRESSPEER_SECONDLINK	0x16
#define TAG_SETT_PORT_SECONDLINK			0x17
#define TAG_SETT_BOOTUPWAITTIME				0x18
#define TAG_SETT_TCPWAITTIME				0x19
#define TAG_SETT_STANDBYWAITTIME			0x1A
#define TAG_SETT_LOCKTIMEOUT				0x1B
#define TAG_SETT_BOOTPROJECTNAME			0x1C
#define TAG_SETT_REDUNDANCYTASKNAME			0x1D
#define TAG_SETT_SERVICEWAITTIME			0x1E
#define TAG_SETT_SERVICE					0x1F
#define TAG_SETT_FIELDBUSES					0x20
#define TAG_SETT_ETHERCATNICSETTING			0x21
#define TAG_SETT_MACADDRESSLOCAL_FIRSTLINK	0x22
#define TAG_SETT_REDUNDANCYFRAMEWAITTIME	0x23
#define TAG_SETT_GETFRAMESLEEPTIME			0x24
#define TAG_SETT_DATAVIASYNCWAITTIME		0x25
#define TAG_SETT_DATAVIASYNCLEEPTIME		0x26
#define TAG_SETT_ETHERCATNICSETTINGREDUNDANCY	0x27
#define RDCY_ACK							0x81
#define TAG_SETT_RDCYCONNECTION				0x82
#define TAG_RDCY_SUCCESS					0x2A
#define TAG_RDCY_ERROR						0x2B
#define TAG_RDCY_STATE						0x2C
#define TAG_SETT_SYNCWAITTIME				0x2D

/**
 * <category>Static defines</category>
 * <description> Size of list for file names to be transmitted to second controller. </description>
 */
#ifndef MAX_REDU_SYNC_FILES
	#define MAX_REDU_SYNC_FILES 100
#endif

/**
 * <description>Redundancy settings names and default values</description>
 */
#define RDCYKEY_INT_BOOTUPWAITTIME							"BootupWaitTime"
#define RDCYVALUE_INT_BOOTUPWAITTIME_DEFAULT				5000

#define RDCYKEY_INT_TCPWAITTIME								"TcpWaitTime"
#define RDCYVALUE_INT_TCPWAITTIME_DEFAULT					2000

#define RDCYKEY_INT_RECONNECTWAITTIME						"ReconnectWaitTime"
#define RDCYVALUE_INT_RECONNECTWAITTIME_DEFAULT				5000

#define RDCYKEY_INT_STANDBYWAITTIME							"StandbyWaitTime"
#define RDCYVALUE_INT_STANDBYWAITTIME_DEFAULT				30

#define RDCYKEY_INT_SYNCWAITTIME							"SyncWaitTime"

#define RDCYKEY_INT_LOCKTIMEOUT								"LockTimeout"
#define RDCYVALUE_INT_LOCKTIMEOUT_DEFAULT					50

#define RDCYKEY_STRING_BOOTPROJECTNAME						"Bootproject"
#define RDCYVALUE_STRING_BOOTPROJECTNAME_DEFAULT			""

#define RDCYKEY_STRING_REDUNDANCYMAINTASKNAME				"RedundancyTaskName"
#define RDCYVALUE_STRING_REDUNDANCYMAINTASKNAME_DEFAULT		""

#define RDCYKEY_INT_SERVICEWAITTIME							"Service.WaitTime"
#define RDCYVALUE_INT_SERVICEWAITTIME_DEFAULT				1000

#define RDCYKEY_INT_EVTTRGSTARTENDCALL						"EvtTrgStartEndCall"
#define RDCYVALUE_INT_EVTTRGSTARTENDCALL_DEFAULT			TRUE

#define RDCYKEY_INT_PROFIBUS								"Profibus"
#define RDCYKEY_INT_PROFIBUSCIF50							"ProfibusCIF50"
#define RDCYVALUE_INT_PROFIBUS_DEFAULT						FALSE

#define RDCYKEY_INT_ETHERCAT								"Ethercat"
#define RDCYVALUE_INT_ETHERCAT_DEFAULT						FALSE

#define RDCYKEY_INT_DEBUGMESSAGES							"DebugMessages"
#define RDCYVALUE_INT_DEBUGMESSAGES_DEFAULT					FALSE

#define RDCYKEY_INT_DEBUGMESSAGESTASKTIME					"DebugMessagesTaskTime"
#define RDCYVALUE_INT_DEBUGMESSAGESTASKTIME_DEFAULT			FALSE

#define RDCYKEY_INT_CALLVFINIT								"CallVfInit"
#define RDCYVALUE_INT_CALLVFINIT_DEFAULT					TRUE

#define RDCYKEY_INT_SIMULATION								"Simulation"
#define RDCYVALUE_INT_SIMULATION_DEFAULT					FALSE

#define RDCYKEY_INT_SYNCHROPHASELENGTH						"SynchroPhaseLength"
#define RDCYVALUE_INT_SYNCHROPHASELENGTH_DEFAULT			0

#define RDCYKEY_INT_EXTRASTANDBYWAITTIME					"ExtraStandbyWaitTime"
#define RDCYVALUE_INT_EXTRASTANDBYWAITTIME_DEFAULT			0

#define RDCYKEY_INT_STANDALONEAFTERSTANDBY					"StandaloneAfterStandby"
#define RDCYVALUE_INT_STANDALONEAFTERSTANDBY_DEFAULT		2

#define RDCYKEY_INT_INPUTAREACRCCHECK						"InputAreaCrcCheck"
#define RDCYVALUE_INT_INPUTAREACRCCHECK_DEFAULT				FALSE

#define RDCYKEY_INT_AREASYNCTLGCRCCHECK						"AreaSyncTelegramCrcCheck"
#define RDCYVALUE_INT_AREASYNCTLGCRCCHECK_DEFAULT				FALSE

#define RDCYKEY_INT_CMPSRV_SERVICEWAITTIME					"Service.WaitTime"
#define RDCYVALUE_INT_CMPSRV_SERVICEWAITTIME_DEFAULT		1000

#define RDCYKEY_INT_PLCIDENT								"PlcIdent"
#define RDCYVALUE_INT_PLCIDENT_DEFAULT						0

#define RDCYKEY_INT_SYNCBEFORETASKCYCLE						"SyncBeforeTaskCycle"
#define RDCYVALUE_INT_SYNCBEFORETASKCYCLE_DEFAULT			FALSE

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description> Set to 1 to enable data sync in every cycle.
 *  (data sync is copying the values of global variables registered in redundancy configuration)
 *  By default, data sync is done at startup of plc2 only. During operation, data sync is not performed.
 *  Please note, dependant on the size of data and speed of communication, task cycle time can be increased. 
 *  .
 * </description>
 */
#define RDCYKEY_INT_DATASYNCALWAYS							"DataSyncAlways"
#define RDCYVALUE_INT_DATASYNCALWAYS_DEFAULT				FALSE

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description> Set to 1 to enable check of boot application GUID. 
 *  In case this setting is activated, boot application GUIDs of plc1 and plc are compared at startup of plc2.
 *  If they are equal, projects are considered as equal, so application files are not transmitted to plc2. This reduces the time needed for synchronization.
 *  Please not other files are not checked, so they are not transmitted even they are different.
 *  In case this setting is not activated, all application and visu files are always transmitted to plc2 at startup.
 * </description>
 */
#define RDCYKEY_INT_CHECKBOOTAPPGUID						"CheckBootApplicationGuid"
#define RDCYVALUE_INT_CHECKBOOTAPPGUID_DEFAULT				FALSE

#define EVTPARAMID_CmpRedundancy_vfInit		0x0001
#define EVTVERSION_CmpRedundancy_vfInit		0x0001
#define EVT_CmpRedundancy_vfInit			MAKE_EVENTID(EVTCLASS_INFO, 1)

/** EXTERN LIB SECTION BEGIN **/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description>Typedef for redundancy state</description>
 */
typedef enum
{
	RS_START = 0,
	RS_SYNCHRO = 1,
	RS_CYCLE_ACTIVE = 2,
	RS_CYCLE_STANDBY = 3,
	RS_CYCLE_STANDALONE = 4,
	RS_CYCLE_ERROR = 5,
	RS_SIMULATION = 6,
	RS_BOOTUP_ERROR = 7,
	RS_SHUTDOWN_ACTIVE = 8,
	RS_SHUTDOWN_STANDBY = 9,
	RS_SYNCHRO_ERROR = 10,
	RS_SIMULATION_START = 11,
	RS_NO_LICENSE = 12
} RDCY_STATE;

/**
 * <description>Typedef for redundancy error</description>
 */
typedef enum
{
	RDCY_NO_ERROR = 0,
	RDCY_ERR_FAILED = 1,
	RDCY_BOOTUP_ERROR = 2,
	RDCY_SYNCHRO_ERROR = 3,
	RDCY_CYCLE_ERROR = 4,
	RDCY_LINK_ERROR = 5,
	RDCY_FIELDBUS_ERROR = 6,
	RDCY_RECEIVEMESSAGE_ERROR = 7,
	RDCY_NOMESSAGE_ERROR = 8,
	RDCY_WRONGMESSAGE_ERROR = 9,
	RDCY_CONFIG_ERROR = 10,
	RDCY_INPUTAREACRC_ERROR = 11,
	RDCY_NO_LICENSE_ERROR = 12
} RDCY_ERROR;

/**
 * <description>Typedef for redundancy area type</description>
 */
typedef enum
{
	AREA_NONE = 0,
	AREA_INPUT = 1,
	AREA_SYNCHRO = 2,
	AREA_OUTPUT = 3,
	AREA_PASSIVEACTIVE = 4
} RDCY_AREA_TYPE;

/**
 * <description>Typedef for redundancy state information</description>
 */
typedef struct tagRedundancyState
{
	RDCY_STATE eRedundancyState;
	RDCY_ERROR eRedundancyError;
	RTS_IEC_STRING stRedundancyError[81];
} RedundancyState;

/**
 * <description>SYNC_INFO</description>
 */
typedef struct tagSYNC_INFO
{
	RTS_IEC_UDINT ulCycle;		
	RTS_IEC_UDINT ulWaitTimeActive;		/* in ms. Valid in active and standby state. */
	RTS_IEC_UDINT ulWaitTimePassive;		/* In ms. Valid in standby state. Always 0 in active plc. */
	RTS_IEC_UDINT ulWaitTimeMax;		/* In ms. Maximum wait time of active PLC. */
	RTS_IEC_UDINT ulWaitTime;		/* In ms. Value configured in runtime CFG file. Other controller will be considered as failed if exceeded */
	RTS_IEC_UDINT ulTaskInterval;		/* In ms. Modified if WaitTimeActive or WaitTimePassive to big, to compensate clock drift. */
	RTS_IEC_TIME tSinceLastSync;		
} SYNC_INFO;

/**
 * <description>Enum: PLC_IDENT</description>
 */
#define PLC_IDENT_PLC_ID_NONE    RTS_IEC_INT_C(0x0)	/* Not specified */
#define PLC_IDENT_PLC_ID_1    RTS_IEC_INT_C(0x1)	/* PLC 1 */
#define PLC_IDENT_PLC_ID_2    RTS_IEC_INT_C(0x2)	/* PLC 2 */
/* Typed enum definition */
#define PLC_IDENT    RTS_IEC_INT

typedef struct tagRedundancyTlgHeader
{
	RTS_UI32 dwIdentity; /* Telegram identity */
	RTS_UI16 wID; /* Redundancy message id */
	RTS_UI16 wFlags; /* Message flag (FLAG_FIRST_MESSAGE/FLAG_LAST_MESSAGE) */
	RTS_UI32 dwOwnIpAddress; /* Sender IP address */
	RTS_UI32 dwCRC; /* CRCs of input/output data areas */
	RTS_BOOL bCrcMismatch; /* CRC mismatch flag */
	RTS_UI32 dwTick; /* Tick */
	RTS_UI32 dwLen; /* Telegram length -> Header + Data */
} RedundancyTlgHeader;

/**
 * <description>Typedef for redundancy communication modes</description>
 */
typedef enum
{
	RCOM_SyncReceive = 0,	/* Sync messages (UDP) */
	RCOM_SyncSend = 1,		/* Sync messages (UDP) */
	RCOM_DataClient = 2,	/* Data messages (TCP) */
	RCOM_DataServer = 3,	/* Data messages (TCP) */
	RCOM_DataWork = 4,		/* Data messages (TCP), special mode to re-initialize server */
} REDUNDANCY_COMM_MODE;

/**
 * <description>Typedef for client reply</description>
 */
typedef struct tagCLIENT_REPLY
{
	RTS_UI32 dwBytesReceived;
	RTS_UI32 dwIPAddress;
	char stIPAddressTransmitter[21];
} CLIENT_REPLY;

/**
 * <description>arearegister</description>
 */
typedef struct tagarearegister_struct
{
	RTS_IEC_BYTE *pArea;				/* VAR_INPUT */
	RTS_IEC_UDINT udiSize;				/* VAR_INPUT */
	RDCY_AREA_TYPE eType;				/* VAR_INPUT */
	RTS_IEC_BOOL AreaRegister;			/* VAR_OUTPUT */
} arearegister_struct;

DEF_API(`void',`CDECL',`arearegister',`(arearegister_struct *p)',1,0x0,0x0)

/**
 * <description>arearegistersegment</description>
 */
typedef struct tagarearegistersegment_struct
{
	RTS_IEC_UINT usSegment;					/* VAR_INPUT */
	RDCY_AREA_TYPE eType;				/* VAR_INPUT */
	RTS_IEC_BOOL AreaRegisterSegment;	/* VAR_OUTPUT */
} arearegistersegment_struct;

DEF_API(`void',`CDECL',`arearegistersegment',`(arearegistersegment_struct *p)',1,0x0,0x0)

/**
 * <description>redundancycycleend</description>
 */
typedef struct tagredundancycycleend_struct
{
	RTS_IEC_BOOL RedundancyCycleEnd;	/* VAR_OUTPUT */
} redundancycycleend_struct;

/**
 * <description>unregisterareas</description>
 */
typedef struct tagunregisterareas_struct
{
	RTS_IEC_BOOL UnregisterAreas;		/* VAR_OUTPUT */
} unregisterareas_struct;

DEF_API(`void',`CDECL',`unregisterareas',`(unregisterareas_struct *p)',1,0x0,0x0)

DEF_API(`void',`CDECL',`redundancycycleend',`(redundancycycleend_struct *p)',1,0x0,0x0)

/**
 * <description>redundancycyclestart</description>
 */
typedef struct tagredundancycyclestart_struct
{
	RTS_IEC_BOOL RedundancyCycleStart;	/* VAR_OUTPUT */
} redundancycyclestart_struct;

DEF_API(`void',`CDECL',`redundancycyclestart',`(redundancycyclestart_struct *p)',1,0x0,0x0)

/**
 * <description>getredundancystate</description>
 */
typedef struct taggetredundancystate_struct
{
	RedundancyState *pState;			/* VAR_INPUT */
	RTS_IEC_BOOL GetRedundancyState;	/* VAR_OUTPUT */
} getredundancystate_struct;

DEF_API(`void',`CDECL',`getredundancystate',`(getredundancystate_struct *p)',1,0x0,0x0)

/**
 * <description>getsyncinformation</description>
 */
typedef struct taggetsyncinformation_struct
{
	SYNC_INFO *pSyncInfo;				/* VAR_INPUT */	
	RTS_IEC_RESULT GetSyncInformation;	/* VAR_OUTPUT */	
} getsyncinformation_struct;

DEF_API(`void',`CDECL',`getsyncinformation',`(getsyncinformation_struct *p)',1,0x7312487E,0x03050F00)

/**
 * <description>switchtosimulation</description>
 */
typedef struct tagswitchtosimulation_struct
{
	RTS_IEC_BOOL SwitchToSimulation;	/* VAR_OUTPUT */
} switchtosimulation_struct;

DEF_API(`void',`CDECL',`switchtosimulation',`(switchtosimulation_struct *p)',1,0x0,0x0)

/**
 * <description>switchtostandalone</description>
 */
typedef struct tagswitchtostandalone_struct
{
	RTS_IEC_BOOL SwitchToStandalone;	/* VAR_OUTPUT */
} switchtostandalone_struct;

DEF_API(`void',`CDECL',`switchtostandalone',`(switchtostandalone_struct *p)',1,0x0,0x0)

/**
 * <description>switchtostandby</description>
 */
typedef struct tagswitchtostandby_struct
{
	RTS_IEC_BOOL SwitchToStandby;		/* VAR_OUTPUT */
} switchtostandby_struct;

DEF_API(`void',`CDECL',`switchtostandby',`(switchtostandby_struct *p)',1,0x0,0x0)

/**
 * <description>switchtoactive</description>
 */
typedef struct tagswitchtoactive_struct
{
	RTS_IEC_BOOL SwitchToActive;		/* VAR_OUTPUT */
} switchtoactive_struct;

DEF_API(`void',`CDECL',`switchtoactive',`(switchtoactive_struct *p)',1,0x0,0x0)

/**
 * <description>synchronize</description>
 */
typedef struct tagsynchronize_struct
{
	RTS_IEC_BOOL Synchronize;			/* VAR_OUTPUT */
} synchronize_struct;

DEF_API(`void',`CDECL',`synchronize',`(synchronize_struct *p)',1,0x0,0x0)

/**
 * <description>getplcident</description>
 */
typedef struct taggetplcident_struct
{
	RTS_IEC_INT GetPlcIdent;			/* VAR_OUTPUT, Enum: PLC_IDENT */
} getplcident_struct;

DEF_API(`void',`CDECL',`getplcident',`(getplcident_struct *p)',1,0xE8999A90,0x03050E00)

/**
 * Synchronze global data once. This includes the areas registered in redundancy.
 *Can be called from active or standby controller. 
 */
typedef struct tagredundancysynchronizedata_struct
{
	RTS_IEC_BOOL RedundancySynchronizeData;	/* VAR_OUTPUT */	
} redundancysynchronizedata_struct;

DEF_API(`void',`CDECL',`redundancysynchronizedata',`(redundancysynchronizedata_struct *p)',1,0xBF757A6F,0x03051000)

/**
 * In standalone state: Returns TRUE if other plc can be connected and answers to redundancy messages. There is a chance that a call to Syncrnonize() will succeed.
 */
typedef struct taggetconnectionstate_struct
{
	RTS_IEC_BOOL GetConnectionState;	/* VAR_OUTPUT */	
} getconnectionstate_struct;

DEF_API(`void',`CDECL',`getconnectionstate',`(getconnectionstate_struct *p)',1,0x5802A20A,0x03051000)


/**
 * <description>This function registers the memory area as redundant area</description>
 * <param name="pbyArea" type="IN">Start address</param>
 * <param name="ulSize" type="IN">Size</param>
 * <param name="eType" type="IN">Redundancy area type</param>
 * <result>TRUE in case of success, otherwise FALSE</result>
 */
DEF_ITF_API(`RTS_IEC_BOOL',`CDECL',`RedundancyAreaRegister',`(unsigned char *pbyArea, RTS_UI32 ulSize, RDCY_AREA_TYPE eType)')

/**
 * <description>This function registers a memory area segment as redundant area</description>
 * <param name="usSegment" type="IN">Segment type</param>
 * <param name="eType" type="IN">Redundancy area type</param>
 * <result>TRUE in case of success, otherwise FALSE</result>
 */
DEF_ITF_API(`RTS_IEC_BOOL',`CDECL',`RedundancyAreaRegisterSegment',`(RTS_UI16 usSegment, RDCY_AREA_TYPE eType)')

/**
 * <description>This function unregisters all redundancy areas</description>
 * <result>TRUE in case of success, otherwise FALSE</result>
 */
DEF_ITF_API(`RTS_IEC_BOOL',`CDECL',`RedundancyUnregisterAreas',`(void)')

/**
 * <description>This function is called at end of a cycle of the redundancy task</description>
 * <result>TRUE in case of success, otherwise FALSE</result>
 */
DEF_ITF_API(`RTS_IEC_BOOL',`CDECL',`RedundancyCycleEnd',`(void)')

/**
 * <description>This function is called at beginning of a cycle of the redundancy task</description>
 * <result>TRUE in case of success, otherwise FALSE</result>
 */
DEF_ITF_API(`RTS_IEC_BOOL',`CDECL',`RedundancyCycleStart',`(void)')

/**
 * <description>This function returns the current redundancy state</description>
 * <param name="pState" type="OUT">Pointer to redundancy state structure to return the redundancy state.</param>
 * <result>TRUE in case of success, otherwise FALSE</result>
 */
DEF_ITF_API(`RTS_IEC_BOOL',`CDECL',`RedundancyGetState',`(RedundancyState *pState)')

/**
 * <description>This function switches a PLC in redundancy state RS_CYCLE_STANDBY to RS_SIMULATION</description>
 * <result>TRUE in case of success, otherwise FALSE</result>
 */
DEF_ITF_API(`RTS_IEC_BOOL',`CDECL',`RedundancySwitchToSimulation',`(void)')

/**
 * <description>This function switches a PLC in redundancy state RS_SIMULATION_START to RS_CYLCE_STANDALONE</description>
 * <result>TRUE in case of success, otherwise FALSE</result>
 */
DEF_ITF_API(`RTS_IEC_BOOL',`CDECL',`RedundancySwitchToStandalone',`(void)')

/**
 * <description>This function switches a PLC in redundancy state RS_CYCLE_ACTIVE to RS_CYCLE_STANDBY</description>
 * <result>TRUE in case of success, otherwise FALSE</result>
 */
DEF_ITF_API(`RTS_IEC_BOOL',`CDECL',`RedundancySwitchToStandby',`(void)')

/**
 * <description>This function switches a PLC in redundancy state RS_SIMULATION to RS_CYCLE_ACTIVE (if the second redundancy PLC is running) or RS_CYCLE_STANDALONE (if the second redundancy PLC is not running)</description>
 * <result>TRUE in case of success, otherwise FALSE</result>
 */
DEF_ITF_API(`RTS_IEC_BOOL',`CDECL',`RedundancySwitchToActive',`(void)')

/**
 * <description>This function synchronizes a PLC in redundancy state RS_START, RS_BOOTUP_ERROR, RS_SYNCHRO_ERROR, RS_CYCLE_ERROR, RS_CYCLE_STANDALONE, RS_SIMULATION or RS_SIMULATION_START</description>
 * <result>TRUE in case of success, otherwise FALSE</result>
 */
DEF_ITF_API(`RTS_IEC_BOOL',`CDECL',`RedundancySynchronize',`(void)')

#ifdef __cplusplus
}
#endif
