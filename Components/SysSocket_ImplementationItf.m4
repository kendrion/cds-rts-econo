/**
 * <interfacename>SysSocket_Implementation</interfacename>
 * <description></description>
 *
 * <copyright></copyright>
 */

SET_INTERFACE_NAME(`SysSocket_Implementation')
REF_ITF(`SysSocketItf.m4')

/** EXTERN LIB SECTION BEGIN **/
/*  Comments are ignored for m4 compiler so restructured text can be used. changecom(`/*', `*/') */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * | Accept the next incoming TCP connection.
 * | This functions calls the function accept of the operating system, which can accept a request to connect
 *   to a socket. A new descriptor (handle) for the socket is returned. The original socket is reset to the
 *   "listening" state (see SysSockListen).
 *
 * :return: Handle to the new accepted socket or RTS_INVALID_HANDLE if failed.
 */
typedef struct tagsyssockaccept_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Handle to the socket */
	SOCKADDRESS *pSockAddr;				/* VAR_INPUT */	/* Socket address of the client, who is connected */
	RTS_IEC_DINT *pdiSockAddrSize;		/* VAR_INPUT */	/* Pointer to size of socket address structure */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_HANDLE SysSockAccept;		/* VAR_OUTPUT */	
} syssockaccept_struct;

DEF_API(`void',`CDECL',`syssockaccept',`(syssockaccept_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xCA6B3076),0x03050F00)

/**
 * | Bind a socket to a socket address and port number.
 * | This functions calls the function bind of the operating system, which will assign a local address
 *   to a socket that has already been allocated to an address by |SysSockCreate|, but not yet fixed uniquely.
 *   This is usually done previous to a call to functions like |SysSockListen| or |SysSockAccept|.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockbind_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Handle to the socket */
	SOCKADDRESS *pSockAddr;				/* VAR_INPUT */	/* Spcket address */
	RTS_IEC_DINT diSockAddrSize;		/* VAR_INPUT */	/* Size of the socket address structure */
	RTS_IEC_RESULT SysSockBind;			/* VAR_OUTPUT */	
} syssockbind_struct;

DEF_API(`void',`CDECL',`syssockbind',`(syssockbind_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xCF23D531),0x03050F00)

/**
 *  | Close a socket.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockclose_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Handle to the socket */
	RTS_IEC_RESULT SysSockClose;		/* VAR_OUTPUT */	
} syssockclose_struct;

DEF_API(`void',`CDECL',`syssockclose',`(syssockclose_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xF72471AA),0x03050F00)

/**
 * | Close a UDP socket. Handle must be retrieved by |SysSockCreateUdp| !
 * | This function calls the function closesocket of the operating system to close a socket
 *   working with the user datagram protocol UDP.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockcloseudp_struct
{
	RTS_IEC_HANDLE hSocketUdp;			/* VAR_INPUT */	/* Handle to the UDP socket. Must be opened with |SysSockCreateUdp| ! */
	RTS_IEC_RESULT SysSockCloseUdp;		/* VAR_OUTPUT */	
} syssockcloseudp_struct;

DEF_API(`void',`CDECL',`syssockcloseudp',`(syssockcloseudp_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x6978E3CC),0x03050F00)

/**
 * | Connect as a client to a TCP server.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockconnect_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Handle to the socket */
	SOCKADDRESS *pSockAddr;				/* VAR_INPUT */	/* Socket address of the server to connect to */
	RTS_IEC_DINT diSockAddrSize;		/* VAR_INPUT */	/* Size of socket address structure */
	RTS_IEC_RESULT SysSockConnect;		/* VAR_OUTPUT */	
} syssockconnect_struct;

DEF_API(`void',`CDECL',`syssockconnect',`(syssockconnect_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x765FD3AB),0x03050F00)

/**
 * Create a new socket and return the socket handle.
 * :return: Handle to the new socket. The return is a descriptor (handle) of the new socket,
 * which is required as input parameter by other library functions like |SysSockBind|, |SysSockConnect| etc.
 */
typedef struct tagsyssockcreate_struct
{
	RTS_IEC_INT iAddressFamily;			/* VAR_INPUT */	/* Socket address family */
	RTS_IEC_DINT diType;				/* VAR_INPUT */	/* Socket type */
	RTS_IEC_DINT diProtocol;			/* VAR_INPUT */	/* Socket protocol */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_HANDLE SysSockCreate;		/* VAR_OUTPUT */	
} syssockcreate_struct;

DEF_API(`void',`CDECL',`syssockcreate',`(syssockcreate_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xE8829CB3),0x03050F00)

/**
 * | Higher level function, to create a complete UDP socket.
 * | The socket will make use of the user data protocol UDP.
 * :return: Handle to the UDP socket
 */
typedef struct tagsyssockcreateudp_struct
{
	RTS_IEC_DINT diSendPort;			/* VAR_INPUT */	/* Port number to send (host byte order) */
	RTS_IEC_DINT diRecvPort;			/* VAR_INPUT */	/* Port number to receive (host byte order) */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_HANDLE SysSockCreateUdp;	/* VAR_OUTPUT */	
} syssockcreateudp_struct;

DEF_API(`void',`CDECL',`syssockcreateudp',`(syssockcreateudp_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x4A894324),0x03050F00)

/**
 * | Add a socket to a socket set.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockfdinit_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Socket to add */
	SOCKET_FD_SET *pfs;					/* VAR_INPUT */	/* Socket Set */
	RTS_IEC_RESULT SysSockFdInit;		/* VAR_OUTPUT */	
} syssockfdinit_struct;

DEF_API(`void',`CDECL',`syssockfdinit',`(syssockfdinit_struct *p)',1,0x09C72D7D,0x03050F00)

/**
 * | Check if a socket is inside of a set.
 * :return: TRUE if it is inside the set, FALSE if not.
 */
typedef struct tagsyssockfdisset_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Socket to check */
	SOCKET_FD_SET *pfs;					/* VAR_INPUT */	/* Socket Set */
	RTS_IEC_BOOL SysSockFdIsset;		/* VAR_OUTPUT */	
} syssockfdisset_struct;

DEF_API(`void',`CDECL',`syssockfdisset',`(syssockfdisset_struct *p)',1,0x25248CA6,0x03050F00)

/**
 * | Clear a Socket set.
 * :return: Returns the runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockfdzero_struct
{
	SOCKET_FD_SET *pfs;					/* VAR_INPUT */	/* Socket Set */
	RTS_IEC_RESULT SysSockFdZero;		/* VAR_OUTPUT */	
} syssockfdzero_struct;

DEF_API(`void',`CDECL',`syssockfdzero',`(syssockfdzero_struct *p)',1,0xD6D9FDA1,0x03050F00)

/**
 * | Get adapter information struct of the first network adapter.
 * | Note: It may took a while until a change of the adapter configuration is reflected here.
 * :return: Handle to be passed to SysSockGetNextAdapter() to retrieve the next adapter information.
 */
typedef struct tagsyssockgetfirstadapterinfo_struct
{
	SOCK_ADAPTER_INFORMATION *pAdapterInfo;	/* VAR_INPUT */	/* Network adapter information structure */
	RTS_IEC_UXINT *puxiAdapterInfoSize;	/* VAR_INPUT */	/* Size in bytes of |SOCK_ADAPTER_INFORMATION|; returns structure size from external implementation */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_HANDLE SysSockGetFirstAdapterInfo;	/* VAR_OUTPUT */	
} syssockgetfirstadapterinfo_struct;

DEF_API(`void',`CDECL',`syssockgetfirstadapterinfo',`(syssockgetfirstadapterinfo_struct *p)',1,RTSITF_GET_SIGNATURE(0x0FE33BC1, 0xF08189B5),0x03050F00)

/**
 * | Get host description specified by host name.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockgethostbyname_struct
{
	RTS_IEC_STRING *szHostName;			/* VAR_INPUT */	/* Reference to host name */
	SOCK_HOSTENT *pHost;				/* VAR_INPUT */	/* Pointer to host description */
	RTS_IEC_RESULT SysSockGetHostByName;	/* VAR_OUTPUT */	
} syssockgethostbyname_struct;

DEF_API(`void',`CDECL',`syssockgethostbyname',`(syssockgethostbyname_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x05667F90),0x03050F00)

/**
 * | Get host name of the target.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockgethostname_struct
{
	RTS_IEC_STRING *szHostName;			/* VAR_INPUT */	/* Reference to get host name */
	RTS_IEC_DINT diNameLen;				/* VAR_INPUT */	/* Maximum length of hostname */
	RTS_IEC_RESULT SysSockGetHostName;	/* VAR_OUTPUT */	
} syssockgethostname_struct;

DEF_API(`void',`CDECL',`syssockgethostname',`(syssockgethostname_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x68CAC03B),0x03050F00)

/**
 * | Get adapter information struct of the next network adapter from the adapter list.
 * | Note: It may took a while until a change of the adapter configuration is reflected here.
 * :return: Handle to be passed to SysSockGetNextAdapter() to retrieve the next adapter information.
 */
typedef struct tagsyssockgetnextadapterinfo_struct
{
	RTS_IEC_HANDLE hPrevAdapter;		/* VAR_INPUT */	/* Handle returned by SysSockGetFirstAdapter() or by previous call of SysSockGetNextAdapter() */
	SOCK_ADAPTER_INFORMATION *pAdapterInfo;	/* VAR_INPUT */	/* Network adapter information structure */
	RTS_IEC_UXINT *puxiAdapterInfoSize;	/* VAR_INPUT */	/* Size in bytes of SOCK_ADAPTER_INFORMATION; returns structure size from external implementation */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_HANDLE SysSockGetNextAdapterInfo;	/* VAR_OUTPUT */	
} syssockgetnextadapterinfo_struct;

DEF_API(`void',`CDECL',`syssockgetnextadapterinfo',`(syssockgetnextadapterinfo_struct *p)',1,RTSITF_GET_SIGNATURE(0x1BE45D9D, 0x8EB7E5E3),0x03050F00)

/**
 * | Set options of a specified socket.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockgetoption_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Handle to the socket */
	RTS_IEC_DINT diLevel;				/* VAR_INPUT */	/* Level of the socket */
	RTS_IEC_DINT diOption;				/* VAR_INPUT */	/* Socket option command */
	RTS_IEC_DINT *pdiOptionValue;		/* VAR_INPUT */	/* Pointer to the option value */
	RTS_IEC_DINT *pdiOptionLen;			/* VAR_INPUT */	/* Lenght of option value */
	RTS_IEC_RESULT SysSockGetOption;	/* VAR_OUTPUT */	
} syssockgetoption_struct;

DEF_API(`void',`CDECL',`syssockgetoption',`(syssockgetoption_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xB7ABC5B8),0x03050F00)

/**
 * | Get operating system handle of the UDP socket.
 * :return: Operating system handle
 */
typedef struct tagsyssockgetoshandle_struct
{
	RTS_IEC_HANDLE hSocketUdp;			/* VAR_INPUT */	/* Handle to the UDP socket */
	RTS_IEC_HANDLE SysSockGetOSHandle;	/* VAR_OUTPUT */	
} syssockgetoshandle_struct;

DEF_API(`void',`CDECL',`syssockgetoshandle',`(syssockgetoshandle_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x784811EB),0x03050F00)

/**
 * | Returns the socket address of the peer to which a socket is connected.
 * | The SysSockGetPeerName function can be used only on a connected socket. 
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockgetpeername_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Handle to the socket */
	SOCKADDRESS *pSockAddr;				/* VAR_INPUT */	/* Socket address of the peer */
	RTS_IEC_DINT *pdiSockAddrSize;		/* VAR_INPUT */	/* Pointer to size of socket address structure */
	RTS_IEC_RESULT SysSockGetPeerName;	/* VAR_OUTPUT */	
} syssockgetpeername_struct;

DEF_API(`void',`CDECL',`syssockgetpeername',`(syssockgetpeername_struct *p)',1,0xE0A45F4A,0x03050F00)

/**
 * Check actual received data on the UDP socket.
 * :return: Number of bytes actual available in the socket
 */
typedef struct tagsyssockgetrecvsizeudp_struct
{
	RTS_IEC_HANDLE hSocketUdp;			/* VAR_INPUT */	/* Handle to the UDP socket */
	RTS_IEC_DINT diTimeout;				/* VAR_INPUT */	/* Timeout to wait for received data.

 - -1 = Infinite wait
 -  0 = no wait */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_XINT SysSockGetRecvSizeUdp;	/* VAR_OUTPUT */	
} syssockgetrecvsizeudp_struct;

DEF_API(`void',`CDECL',`syssockgetrecvsizeudp',`(syssockgetrecvsizeudp_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xDBEEF58B),0x03050F00)

/**
 * | Returns the socket address of the local socket.
 * | Usally this function is called to retrieve the local socket address on multihomed hosts or to get 
 *   the local port number in client implemntations. If the socket is neither connected nor locally bound to an address,
 *   the result of the function and the value stored in the object pointed to by pSockAddress is unspecified. 
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockgetsockname_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Handle to the socket */
	SOCKADDRESS *pSockAddr;				/* VAR_INPUT */	/* Socket address of the local socket */
	RTS_IEC_DINT *pdiSockAddrSize;		/* VAR_INPUT */	/* Pointer to size of socket address structure */
	RTS_IEC_RESULT SysSockGetSockName;	/* VAR_OUTPUT */	
} syssockgetsockname_struct;

DEF_API(`void',`CDECL',`syssockgetsockname',`(syssockgetsockname_struct *p)',1,0x7EE86135,0x03050F00)

/**
 * | Get subnetmask of a specified IP address adapter.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockgetsubnetmask_struct
{
	RTS_IEC_STRING *szIPAddress;		/* VAR_INPUT */	/* IP address of the communication partner as string */
	RTS_IEC_STRING *szSubnetMask;		/* VAR_INPUT */	/* Subnet mask as string */
	RTS_IEC_DINT diMaxSugnetMask;		/* VAR_INPUT */	/* Maximum length of the subnet mask string */
	RTS_IEC_RESULT SysSockGetSubnetMask;	/* VAR_OUTPUT */	
} syssockgetsubnetmask_struct;

DEF_API(`void',`CDECL',`syssockgetsubnetmask',`(syssockgetsubnetmask_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x972C29B9),0x03050F00)

/**
 * | Converts a value of type UDINT from host byte order to the order of the TCP/IP network.
 * :return: Converted UDINT value
 */
typedef struct tagsyssockhtonl_struct
{
	RTS_IEC_UDINT ulHost;				/* VAR_INPUT */	/* Host value */
	RTS_IEC_UDINT SysSockHtonl;			/* VAR_OUTPUT */	
} syssockhtonl_struct;

DEF_API(`void',`CDECL',`syssockhtonl',`(syssockhtonl_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x72F6021A),0x03050F00)

/**
 * | Converts a value of type short from order of the TCP/IP network to the host byte order.
 * :return: Converted WORD value
 */
typedef struct tagsyssockhtons_struct
{
	RTS_IEC_WORD usHost;				/* VAR_INPUT */	/* Ethernet value */
	RTS_IEC_WORD SysSockHtons;			/* VAR_OUTPUT */	
} syssockhtons_struct;

DEF_API(`void',`CDECL',`syssockhtons',`(syssockhtons_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xD258956A),0x03050F00)

/**
 * | Convert an IP address string into an IP address.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockinetaddr_struct
{
	RTS_IEC_STRING *szIPAddress;		/* VAR_INPUT */	/* Pointer to get IP address string (must be at least 16 bytes long) */
	RTS_IEC_UDINT *pInAddr;				/* VAR_INPUT */	/* Pointer to IP address description */
	RTS_IEC_RESULT SysSockInetAddr;		/* VAR_OUTPUT */	
} syssockinetaddr_struct;

DEF_API(`void',`CDECL',`syssockinetaddr',`(syssockinetaddr_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xB8198B8F),0x03050F00)

/**
 * | Convert IP address to a string.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockinetntoa_struct
{
	INADDR *pInAddr;					/* VAR_INPUT */	/* Pointer to IP address description */
	RTS_IEC_STRING *szIPADDR;			/* VAR_INPUT */	/* Pointer to get IP address string (must be at least 16 bytes long) */
	RTS_IEC_DINT diIPAddrSize;			/* VAR_INPUT */	/* Maximum length of szIPAddr */
	RTS_IEC_RESULT SysSockInetNtoa;		/* VAR_OUTPUT */	
} syssockinetntoa_struct;

DEF_API(`void',`CDECL',`syssockinetntoa',`(syssockinetntoa_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x5CE722B2),0x03050F00)

/**
 * | Io-control of a socket.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockioctl_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Handle to the socket */
	RTS_IEC_DINT diCommand;				/* VAR_INPUT */	/* Io-control command */
	RTS_IEC_DINT *pdiParameter;			/* VAR_INPUT */	/* Parameter value of the command */
	RTS_IEC_RESULT SysSockIoctl;		/* VAR_OUTPUT */	
} syssockioctl_struct;

DEF_API(`void',`CDECL',`syssockioctl',`(syssockioctl_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x408480FB),0x03050F00)

/**
 * | Listen on a TCP server socket for new connection.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssocklisten_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Handle to the socket */
	RTS_IEC_DINT diMaxConnections;		/* VAR_INPUT */	/* Maximum number of connections allowed */
	RTS_IEC_RESULT SysSockListen;		/* VAR_OUTPUT */	
} syssocklisten_struct;

DEF_API(`void',`CDECL',`syssocklisten',`(syssocklisten_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x30FE27C1),0x03050F00)

/**
 * | Convert a UDINT value from ethernet byte order into host format.
 * :return: Converted UDINT value
 */
typedef struct tagsyssockntohl_struct
{
	RTS_IEC_UDINT ulNet;				/* VAR_INPUT */	/* Ethernet value */
	RTS_IEC_UDINT SysSockNtohl;			/* VAR_OUTPUT */	
} syssockntohl_struct;

DEF_API(`void',`CDECL',`syssockntohl',`(syssockntohl_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x05B31DF1),0x03050F00)

/**
 * | Convert a WORD value from ethernet byte order into host format.
 * :return:Converted WORD value
 */
typedef struct tagsyssockntohs_struct
{
	RTS_IEC_WORD usNet;					/* VAR_INPUT */	/* Ethernet value */
	RTS_IEC_WORD SysSockNtohs;			/* VAR_OUTPUT */	
} syssockntohs_struct;

DEF_API(`void',`CDECL',`syssockntohs',`(syssockntohs_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x100E0417),0x03050F00)

/**
 * | Check the availability of the communication partner with a ping request.
 * :return: Runtime system error code (see CmpErrors.library): 
 *		| ERR_OK:            Partner available
 *		| ERR_FAILED:        Partner cannot be reached
 *		| All other results: Ping could not be sent because of other errors, so we don't know, if the partner is available.
 */
typedef struct tagsyssockping_struct
{
	RTS_IEC_STRING *szIPAddress;		/* VAR_INPUT */	/* IP address of the communication partner as string */
	RTS_IEC_UDINT ulTimeout;			/* VAR_INPUT */	/* Timeout in milliseconds to wait until reply */
	RTS_IEC_UDINT *pulReplyTime;		/* VAR_INPUT */	/* Pointer to get average reply time of the ping request in milliseconds */
	RTS_IEC_RESULT SysSockPing;			/* VAR_OUTPUT */	
} syssockping_struct;

DEF_API(`void',`CDECL',`syssockping',`(syssockping_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xB3610A39),0x03050F00)

/**
 * | Receive data from a TCP socket.
 * :return: Number of bytes received. 0 if failed.
 */
typedef struct tagsyssockrecv_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Handle to the socket */
	RTS_IEC_BYTE *pbyBuffer;			/* VAR_INPUT */	/* Buffer to read data from the socket */
	RTS_IEC_XINT diBufferSize;			/* VAR_INPUT */	/* Maximum length of the buffer */
	RTS_IEC_DINT diFlags;				/* VAR_INPUT */	/* | The flags parameter can be used to influence the behavior of the 
	  function beyond the options specified for the associated socket. The semantics of this function 
	  are determined by the socket options and the flags parameter. The latter is constructed by using the
	  bitwise OR operator with any of the SOCKET_MSG values. See category TCP flags. */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_XINT SysSockRecv;			/* VAR_OUTPUT */	
} syssockrecv_struct;

DEF_API(`void',`CDECL',`syssockrecv',`(syssockrecv_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x887FBA6B),0x03050F00)

/**
 * | Receive a message from a connectionless socket (UDP).
 * :return: Number of bytes received
 */
typedef struct tagsyssockrecvfrom_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Handle to the socket */
	RTS_IEC_BYTE *pbyBuffer;			/* VAR_INPUT */	/* Buffer to read data from the socket */
	RTS_IEC_XINT diBufferSize;			/* VAR_INPUT */	/* Maximum length of the buffer */
	RTS_IEC_DINT diFlags;				/* VAR_INPUT */	/* | The flags parameter can be used to influence the behavior of the 
	  function beyond the options specified for the associated socket. The semantics of this function 
	  are determined by the socket options and the flags parameter. The latter is constructed by using the
	  bitwise OR operator with any of the SOCKET_MSG values. */
	SOCKADDRESS *pSockAddr;				/* VAR_INPUT */	/* Socket address and port to receive data from */
	RTS_IEC_DINT diSockAddrSize;		/* VAR_INPUT */	/* Size of socket address structure */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_XINT SysSockRecvFrom;		/* VAR_OUTPUT */	
} syssockrecvfrom_struct;

DEF_API(`void',`CDECL',`syssockrecvfrom',`(syssockrecvfrom_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x26DF0362),0x03050F00)

/**
 * | Receive a paket from a UDP socket.
 * :return: Number of bytes received
 */
typedef struct tagsyssockrecvfromudp_struct
{
	RTS_IEC_HANDLE hSocketUdp;			/* VAR_INPUT */	/* Handle to the UDP socket */
	RTS_IEC_BYTE *pbyData;				/* VAR_INPUT */	/* Pointer to data to receive */
	RTS_IEC_XINT diDataSize;			/* VAR_INPUT */	/* Size of data to receive */
	UDP_REPLY *pReply;					/* VAR_INPUT */	/* Description of the client that has sent this paket */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_XINT SysSockRecvFromUdp;	/* VAR_OUTPUT */	
} syssockrecvfromudp_struct;

DEF_API(`void',`CDECL',`syssockrecvfromudp',`(syssockrecvfromudp_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x86A63EF8),0x03050F00)

/**
 * | Receive a paket from a UDP socket.
 * :return: Number of bytes received
 */
typedef struct tagsyssockrecvfromudp2_struct
{
	RTS_IEC_HANDLE hSocketUdp;			/* VAR_INPUT */	/* Handle to the UDP socket */
	RTS_IEC_BYTE *pbyData;				/* VAR_INPUT */	/* Pointer to data to receive */
	RTS_IEC_XINT diDataSize;			/* VAR_INPUT */	/* Size of data to receive */
	UDP_REPLY2 *pReply;					/* VAR_INPUT */	/* Description of the client that has sent this paket */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_XINT SysSockRecvFromUdp2;	/* VAR_OUTPUT */	
} syssockrecvfromudp2_struct;

DEF_API(`void',`CDECL',`syssockrecvfromudp2',`(syssockrecvfromudp2_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xBA3470D3),0x03050F00)

/**
 * | Check a number of sockets for activity.
 * :return: Runtime system error code (see CmpErrors.library):
 *		| ERR_OK
 *		| ERR_SOCK_TIMEDOUT, if timeout expired
 */
typedef struct tagsyssockselect_struct
{
	RTS_IEC_DINT diWidth;				/* VAR_INPUT */	/* Number of sockets in the |SOCKET_FD_SET| structure, so |SOCKET_FD_SETSIZE| must be used here. */
	SOCKET_FD_SET *pfdRead;				/* VAR_INPUT */	/* Optional pointer to the structure |SOCKET_FD_SET| defining the socket set
 to be checked for reading. It is also possible to set this parameter to 0. */
	SOCKET_FD_SET *pfdWrite;			/* VAR_INPUT */	/* Optional pointer to the structure |SOCKET_FD_SET| defining the socket set
 to be checked for writing. It is also possible to set this parameter to 0. */
	SOCKET_FD_SET *pfdExcept;			/* VAR_INPUT */	/* Optional pointer to structure |SOCKET_FD_SET| that defines the socket set
 the error state has to be checked. It is also possible to set this parameter to 0. */
	SOCKET_TIMEVAL *ptvTimeout;			/* VAR_INPUT */	/* Pointer to maximum timespan which the function SysSockSelect waits for a response:
 	| ptvTimeout=NULL:	Infinite wait
 	| ptvTimeout->tv_sec=-1, ptvTimeout->tv_usec=-1:	Infinite wait
 	| ptvTimeout->tv_sec=0, ptvTimeout->tv_usec=0:	No wait */
	RTS_IEC_DINT *pdiReady;				/* VAR_INPUT */	/* Number of sockets that are ready for IO */
	RTS_IEC_RESULT SysSockSelect;		/* VAR_OUTPUT */	
} syssockselect_struct;

DEF_API(`void',`CDECL',`syssockselect',`(syssockselect_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x59125CA7),0x03050F00)

/**
 * | Sent data to a TCP socket.
 * :return: Number of sent bytes. 0 if failed.
 */
typedef struct tagsyssocksend_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Handle to the socket */
	RTS_IEC_BYTE *pbyBuffer;			/* VAR_INPUT */	/* Buffer with data to sent */
	RTS_IEC_XINT diBufferSize;			/* VAR_INPUT */	/* Maximum length of the buffer */
	RTS_IEC_DINT diFlags;				/* VAR_INPUT */	/* | The flags parameter can be used to influence the behavior of the 
	  function beyond the options specified for the associated socket. The semantics of this function 
	  are determined by the socket options and the flags parameter. The latter is constructed by using the
	  bitwise OR operator with any of the SOCKET_MSG values. */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_XINT SysSockSend;			/* VAR_OUTPUT */	
} syssocksend_struct;

DEF_API(`void',`CDECL',`syssocksend',`(syssocksend_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xA73C5F51),0x03050F00)

/**
 * | Send a message over a connectionless socket (UDP).
 * :return: Number of bytes received.
 */
typedef struct tagsyssocksendto_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Handle to the socket */
	RTS_IEC_BYTE *pbyBuffer;			/* VAR_INPUT */	/* Buffer with send data */
	RTS_IEC_XINT diBufferSize;			/* VAR_INPUT */	/* Length of data to send. If diBufferSize = 0 ERR_PARAMETER is returned */
	RTS_IEC_DINT diFlags;				/* VAR_INPUT */	/* | The flags parameter can be used to influence the behavior of the 
	  function beyond the options specified for the associated socket. The semantics of this function 
	  are determined by the socket options and the flags parameter. The latter is constructed by using the
	  bitwise OR operator with any of the SOCKET_MSG values. */
	SOCKADDRESS *pSockAddr;				/* VAR_INPUT */	/* Socket address and port to sent data to */
	RTS_IEC_DINT diSockAddrSize;		/* VAR_INPUT */	/* Size of socket address structure */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_XINT SysSockSendTo;			/* VAR_OUTPUT */	
} syssocksendto_struct;

DEF_API(`void',`CDECL',`syssocksendto',`(syssocksendto_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xEE37CAFA),0x03050F00)

/**
 * | Send a paket to a UDP socket.
 * :return: Number of bytes sent
 */
typedef struct tagsyssocksendtoudp_struct
{
	RTS_IEC_HANDLE hSocketUdp;			/* VAR_INPUT */	/* Handle to the UDP socket */
	RTS_IEC_DINT diPort;				/* VAR_INPUT */	/* Port number ot send data to */
	RTS_IEC_STRING *szDestAddress;		/* VAR_INPUT */	/* Destination IP address ot send data to */
	RTS_IEC_BYTE *pbyData;				/* VAR_INPUT */	/* Pointer to data to send */
	RTS_IEC_XINT diDataSize;			/* VAR_INPUT */	/* Size of data to send. If diDataSize = 0 ERR_PARAMETER is returned. */
	RTS_IEC_RESULT *pResult;			/* VAR_INPUT */	/* Pointer to runtime system error code (see CmpErrors.library) */
	RTS_IEC_XINT SysSockSendToUdp;		/* VAR_OUTPUT */	
} syssocksendtoudp_struct;

DEF_API(`void',`CDECL',`syssocksendtoudp',`(syssocksendtoudp_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x81DCE32E),0x03050F00)

/**
 * Set default gateway address an adapter. 
 * It depends on the device, whether the new gateway address is reset during reboot or
 * if it is retained. In general the caller should consider this as volatile. The 
 * gateway address = 0.0.0.0 can be used to remove the gateway address from the adapter. 
 * After this there is not routing to other subnets possible.
 * 
 * .. note::
 *     The default gateway can only be changed if the adapter containing
 *     the current default gateway is whitelisted in the CODESYSControl.cfg. This function
 *     will not change the default gateway of any other adapter.
 *
 * :return: Returns the runtime system error code (see CmpErrors.library):
 *     - ERR_PARAMETER: At least one of the passed pointers is NULL.
 *	    - ERR_OPERATION_DENIED: Adapter is not in white list or the operation was denied by the event EVT_SysSocket_BeforeSetGateway.
 *	    - ERR_NO_OBJECT: Adapter with the specified name does not exist.
 *	    - ERR_NO_CHANGE: There is a default gateway set on an adapter that is not whitelisted.
 *	    - ERR_FAILED: Default gateway could not be set.
 *	    - ERR_OK: Default gateway was set successfully.
 */
typedef struct tagsyssocksetdefaultgateway_struct
{
	RTS_IEC_WSTRING *wsAdapterName;		/* VAR_INPUT */	/* Adapter name provided by SysSockGetFirstAdapter() / SysSockGetNextAdapter() */
	INADDR *GatewayAddr;				/* VAR_INPUT */	/* Ip address of the gateway to set in network byte order. */
	RTS_IEC_RESULT SysSockSetDefaultGateway;	/* VAR_OUTPUT */	
} syssocksetdefaultgateway_struct;

DEF_API(`void',`CDECL',`syssocksetdefaultgateway',`(syssocksetdefaultgateway_struct *p)',1,0xB87B1303,0x03050F00)

/**
 * | Set IP address of the specified ethernet device. Is not available on all platforms! 
 * | Use SysSockSetIpAddressAndNetMask() instead.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssocksetipaddress_struct
{
	RTS_IEC_STRING *szCard;				/* VAR_INPUT */	/* Name of the ethernet card (aka adapter name) */
	RTS_IEC_STRING *szIPAddress;		/* VAR_INPUT */	/* IP address to set as string */
	RTS_IEC_RESULT SysSockSetIPAddress;	/* VAR_OUTPUT */	
} syssocksetipaddress_struct;

DEF_API(`void',`CDECL',`syssocksetipaddress',`(syssocksetipaddress_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x955CE64B),0x03050F00)

/**
 * | Set IP address and subnet mask of an adapter. 
 * | It depends on the device, whether the new ip address and subnet mask is reset during reboot or
 *   if it is retained. In general the caller should consider these as volatile. The combination 
 *   IP address = 0.0.0.0 and subnet mask = 0.0.0.0 can be used to remove the IP address from the adapter.
 *   After this there is no IP based communication possible anymore, until a new IP address is set.
 *   Replaces the functions SysSockSetIPAddress() and SysSockSetSubnetMask().
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssocksetipaddressandnetmask_struct
{
	RTS_IEC_WSTRING *wsAdapterName;		/* VAR_INPUT */	/* Adapter name provided by SysSockGetFirstAdapter() / SysSockGetNextAdapter() */
	INADDR *IpAddr;						/* VAR_INPUT */	/* Ip address to set in network byte order */
	INADDR *NetMask;					/* VAR_INPUT */	/* Subnet mask to set in network byte order */
	RTS_IEC_RESULT SysSockSetIpAddressAndNetMask;	/* VAR_OUTPUT */	
} syssocksetipaddressandnetmask_struct;

DEF_API(`void',`CDECL',`syssocksetipaddressandnetmask',`(syssocksetipaddressandnetmask_struct *p)',1,0x01D16C55,0x03050F00)

/**
 * | Set options of a specified socket.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssocksetoption_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Handle to the socket */
	RTS_IEC_DINT diLevel;				/* VAR_INPUT */	/* Level of the socket */
	RTS_IEC_DINT diOption;				/* VAR_INPUT */	/* Socket option command */
	RTS_IEC_DINT *pdiOptionValue;		/* VAR_INPUT */	/* Pointer to the option value */
	RTS_IEC_DINT diOptionLen;			/* VAR_INPUT */	/* Lenght of option value */
	RTS_IEC_RESULT SysSockSetOption;	/* VAR_OUTPUT */	
} syssocksetoption_struct;

DEF_API(`void',`CDECL',`syssocksetoption',`(syssocksetoption_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xFBCD9B23),0x03050F00)

/**
 * | Set subnetmask of an adapter, specified by IP address. Is not available on all platforms!
 * | Use SysSockSetIpAddressAndNetMask() instead.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssocksetsubnetmask_struct
{
	RTS_IEC_STRING *szIPAddress;		/* VAR_INPUT */	/* IP address of the communication partner as string */
	RTS_IEC_STRING *szSubnetMask;		/* VAR_INPUT */	/* Subnet mask as string */
	RTS_IEC_RESULT SysSockSetSubnetMask;	/* VAR_OUTPUT */	
} syssocksetsubnetmask_struct;

DEF_API(`void',`CDECL',`syssocksetsubnetmask',`(syssocksetsubnetmask_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0x0185BC67),0x03050F00)

/**
 * | Shutdown a socket.
 * :return: Runtime system error code (see CmpErrors.library).
 */
typedef struct tagsyssockshutdown_struct
{
	RTS_IEC_HANDLE hSocket;				/* VAR_INPUT */	/* Handle to the socket */
	RTS_IEC_DINT diHow;					/* VAR_INPUT */	/* Specifies, which operations are no longer be allowed. See shutdown flags. */
	RTS_IEC_RESULT SysSockShutdown;		/* VAR_OUTPUT */	
} syssockshutdown_struct;

DEF_API(`void',`CDECL',`syssockshutdown',`(syssockshutdown_struct *p)',1,RTSITF_GET_SIGNATURE(0, 0xCB0E612E),0x03050F00)

#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/

