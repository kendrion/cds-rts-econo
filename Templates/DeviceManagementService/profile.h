/* the following components are not necessary and thus marked as not implemented */
#define SYSINT_NOTIMPLEMENTED
#define SYSTIMER_NOTIMPLEMENTED
#define SYSTIMER_NOTIMPLEMENTED
#define SYSWINDOWNATIVE_NOTIMPLEMENTED
#define SYSGRAPHICNATIVE_NOTIMPLEMENTED
#define SYSREADWRITELOCK_NOTIMPLEMENTED
#define SYSCPUMULTICORE_NOTIMPLEMENTED


#define CMPCHANNELCLIENT_NOTIMPLEMENTED
#define CMPNAMESERVICECLIENT_NOTIMPLEMENTED
#define CMPAPP_NOTIMPLEMENTED
#define CMPSCHEDULE_NOTIMPLEMENTED
#define CMPMEMGC_NOTIMPLEMENTED
#define CMPVISUCLIENTCONTROLLERHOST_NOTIMPLEMENTED
#define CMPSCHEDULE_NOTIMPLEMENTED
#define CMPCRYPTO_NOTIMPLEMENTED
#define CMPSECURECHANNEL_NOTIMPLEMENTED
#define CMPSECURITYMANAGER_NOTIMPLEMENTED
#define CMPIECTASK_NOTIMPLEMENTED
#define CMPEDGEGATEWAY_NOTIMPLEMENTED
#define CMPUSERMGR_NOTIMPLEMENTED
#define CMPTRACEMGR_NOTIMPLEMENTED
#define CMPMONITOR_NOTIMPLEMENTED
#define CMPMONITOR2_NOTIMPLEMENTED
#define CMPASYNCMGR_NOTIMPLEMENTED
#define CMPCRYPTMD5_NOTIMPLEMENTED
#define CMPSESSIONINFORMATION_NOTIMPLEMENTED
#define CMPCODEMETER_NOTIMPLEMENTED
#define CMPCHANNELSERVER_NOTIMPLEMENTED
#define CMPCHANNELMGR_NOTIMPLEMENTED
#define CMPBLKDRVUDP_NOTIMPLEMENTED
#define CMPBLKDRVTCP_NOTIMPLEMENTED
#define CMPSRV_NOTIMPLEMENTED
#define CMPROUTER_NOTIMPLEMENTED
#define CMPPLCSHELL_NOTIMPLEMENTED
#define CMPFILETRANSFER_NOTIMPLEMENTED
#define SYSSOCKET_NOTIMPLEMENTED
#define CMPBINTAGUTIL_NOTIMPLEMENTED
#define CMPSETTINGSSRV_NOTIMPLEMENTED

#define CMPPLCSHELL_DISABLE_STANDARD_COMMANDS

#define COMPO_INIT_DECLS \
int SysServices__Entry(INIT_STRUCT *pInitStruct); \
int SysTimeRtc__Entry(INIT_STRUCT *pInitStruct); \
int SysTime__Entry(INIT_STRUCT *pInitStruct); \
int SysTask__Entry(INIT_STRUCT *pInitStruct); \
int SysTarget__Entry(INIT_STRUCT *pInitStruct); \
int SysShm__Entry(INIT_STRUCT *pInitStruct); \
int SysSem__Entry(INIT_STRUCT *pInitStruct); \
int SysProcess__Entry(INIT_STRUCT *pInitStruct); \
int SysOut__Entry(INIT_STRUCT *pInitStruct); \
int SysMem__Entry(INIT_STRUCT *pInitStruct); \
int SysFile__Entry(INIT_STRUCT *pInitStruct); \
int SysExcept__Entry(INIT_STRUCT *pInitStruct); \
int SysEvent__Entry(INIT_STRUCT *pInitStruct); \
int SysDir__Entry(INIT_STRUCT *pInitStruct); \
int SysCpuHandling__Entry(INIT_STRUCT *pInitStruct); \
int CmpSettings__Entry(INIT_STRUCT *pInitStruct); \
int CmpMemPool__Entry(INIT_STRUCT *pInitStruct); \
int CmpLog__Entry(INIT_STRUCT *pInitStruct); \
int CmpIpc__Entry(INIT_STRUCT *pInitStruct); \
int CmpEventMgr__Entry(INIT_STRUCT *pInitStruct); \
int CmpDevice__Entry(INIT_STRUCT *pInitStruct); \
int CmpChecksum__Entry(INIT_STRUCT *pInitStruct); \
int CmpDeviceManagement__Entry(INIT_STRUCT *pInitStruct);

#define COMPO_INIT_LIST \
{"SysServices", SysServices__Entry, 0}, \
{"SysTimeRtc", SysTimeRtc__Entry, 0}, \
{"SysTime", SysTime__Entry, 0}, \
{"SysTask", SysTask__Entry, 0}, \
{"SysTarget", SysTarget__Entry, 0}, \
{"SysShm", SysShm__Entry, 0}, \
{"SysSem", SysSem__Entry, 0}, \
{"SysProcess", SysProcess__Entry, 0}, \
{"SysOut", SysOut__Entry, 0}, \
{"SysMem", SysMem__Entry, 0}, \
{"SysFile", SysFile__Entry, 0}, \
{"SysExcept", SysExcept__Entry, 0}, \
{"SysEvent", SysEvent__Entry, 0}, \
{"SysDir", SysDir__Entry, 0}, \
{"SysCpuHandling", SysCpuHandling__Entry, 0}, \
{"CmpSettings", CmpSettings__Entry, 0}, \
{"CmpMemPool", CmpMemPool__Entry, 0}, \
{"CmpLog", CmpLog__Entry, 0}, \
{"CmpIpc", CmpIpc__Entry, 0}, \
{"CmpEventMgr", CmpEventMgr__Entry, 0}, \
{"CmpDevice", CmpDevice__Entry, 0}, \
{"CmpChecksum", CmpChecksum__Entry, 0}, \
{"CmpDeviceManagement", CmpDeviceManagement__Entry, 0}, \
{"", NULL, 0}


#define RTS_MAX_PATH_LEN						512
