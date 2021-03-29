SET_INTERFACE_NAME(`CmpSocketCanDrv')

/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>
 * Devicefile for CAN interface.
 * </description>
 */
#define SOCKETCAN_STRING_INTERFACENAME "InterfaceName"
#define SOCKETCAN_STRING_INTERFACENAME_DEFAULT "can" //could be e.g. vcan

/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>
 * Path to baudrate script (rts_set_baud.sh).
 * </description>
 */
#define SOCKETCAN_STRING_SCRIPTPATH "ScriptPath"
#define SOCKETCAN_STRING_SCRIPTPATH_DEFAULT "./" //e.g. /opt/codesys/scripts/

/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>
 * Name of script to set the CAN baudrate.
 * </description>
 */
#define SOCKETCAN_STRING_SCRIPTNAME "ScriptName"
#define SOCKETCAN_STRING_SCRIPTNAME_DEFAULT "rts_set_baud.sh"

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>add a timestamp on sending/receiving to every Tx/Rx Message</description>
 */
#define SOCKETCAN_INT_TIMESTAMPS "Timestamps"
#define SOCKETCAN_INT_TIMESTAMPS_DEFAULT 0

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>set the socketoption CAN_RAW_LOOPBACK for Tx Messages</description>
 */
#define SOCKETCAN_INT_LOOPBACK "Loopback"
#define SOCKETCAN_INT_LOOPBACK_DEFAULT 0

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>set the socketoption CAN_RAW_RECV_OWN_MSGS for Rx Messages</description>
 */
#define SOCKETCAN_INT_RECV_OWN_MSGS "RecvOwnMsgs"
#define SOCKETCAN_INT_RECV_OWN_MSGS_DEFAULT 1

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>value of socketoption CAN_RAW_ERR_FILTER</description>
 */
#define SOCKETCAN_INT_ERRMASK "ErrorMask"
/* all known errors without "bus error" (may flood!) and "controller restarted" */
#define SOCKETCAN_INT_ERRMASK_DEFAULT 0x7F

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>value 0: All CAN messages are sent synchronously in the context of the thread calling CL2_Write
 * value 1: All CAN messages are sent asynchronously in a dedicated CanTxThread. CL2_Write returns immediately
 * </description>
 */
#define SOCKETCAN_INT_ASYNCSEND "AsyncSend"
#define SOCKETCAN_INT_ASYNCSEND_DEFAULT 0

/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>
 * Name of command that is executed to Reset a Busalarm.
 * Default is "ip link canX type can restart".
 * </description>
 */
#define SOCKETCAN_STRING_RESETCOMMAND "ResetCommand"
#define SOCKETCAN_STRING_RESETCOMMAND_DEFAULT ""



