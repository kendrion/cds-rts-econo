/**
 * <interfacename>CmpEL6751CanDrv</interfacename>
 * <description></description>
 *
 * <copyright></copyright>
 */

SET_INTERFACE_NAME(`CmpEL6751CanDrv')

/** EXTERN LIB SECTION BEGIN **/
/*  Comments are ignored for m4 compiler so restructured text can be used. changecom(`/*', `*/') */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * <description>EL6751_Config</description>
 */
typedef struct tagEL6751_Config
{
	RTS_IEC_UINT *m_puiQTxCounter;		
	RTS_IEC_UINT *m_puiQRxCounter;		
	RTS_IEC_UINT *m_puiQNoTxMessages;		
	RTS_IEC_BYTE *m_pcmQTx;		
	RTS_IEC_UINT *m_puiITxCounter;		
	RTS_IEC_UINT *m_puiIRxCounter;		
	RTS_IEC_UINT *m_puiINoRxMessages;		
	RTS_IEC_UINT *m_puiITransactionNumber;		
	RTS_IEC_BYTE *m_pcmIRx;		
	RTS_IEC_UINT m_uiMaxTelegrams;		
	RTS_IEC_UINT m_uiBaudrate;		
	RTS_IEC_USINT m_usiNet;		
	RTS_IEC_DWORD m_dwLibVersion;		
	RTS_IEC_DWORD m_dwCmpVersion;		
	RTS_IEC_BOOL m_bETCDeviceOperational;		
} EL6751_Config;

/**
 * <description>el6751_afterreadinputs</description>
 */
typedef struct tagel6751_afterreadinputs_struct
{
	EL6751_Config *pcfg;				/* VAR_INPUT */	
	RTS_IEC_UINT EL6751_AfterReadInputs;	/* VAR_OUTPUT */	
} el6751_afterreadinputs_struct;

DEF_API(`void',`CDECL',`el6751_afterreadinputs',`(el6751_afterreadinputs_struct *p)',1,0x0D252201,0x03050E00)

/**
 * <description>el6751_beforewriteoutputs</description>
 */
typedef struct tagel6751_beforewriteoutputs_struct
{
	EL6751_Config *pcfg;				/* VAR_INPUT */	
	RTS_IEC_UINT EL6751_BeforeWriteOutputs;	/* VAR_OUTPUT */	
} el6751_beforewriteoutputs_struct;

DEF_API(`void',`CDECL',`el6751_beforewriteoutputs',`(el6751_beforewriteoutputs_struct *p)',1,0x76DBEC2D,0x03050E00)

/**
 * <description>el6751_killcmd</description>
 */
typedef struct tagel6751_killcmd_struct
{
	EL6751_Config *pcfg;				/* VAR_INPUT */	
	RTS_IEC_UINT EL6751_KillCMD;		/* VAR_OUTPUT */	
} el6751_killcmd_struct;

DEF_API(`void',`CDECL',`el6751_killcmd',`(el6751_killcmd_struct *p)',1,0xD3AA0B37,0x03050E00)

/**
 * <description>el6751_registercmd</description>
 */
typedef struct tagel6751_registercmd_struct
{
	EL6751_Config *pcfg;				/* VAR_INPUT */	
	RTS_IEC_UINT EL6751_RegisterCMD;	/* VAR_OUTPUT */	
} el6751_registercmd_struct;

DEF_API(`void',`CDECL',`el6751_registercmd',`(el6751_registercmd_struct *p)',1,0x1E6CBB59,0x03050E00)

#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/

