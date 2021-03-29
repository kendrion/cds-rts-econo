/**
 * <interfacename>SysSocket</interfacename>
 * <description> 
 *	<p>The SysSocket interface is projected to handle access to Ethernet socket layer.
 *	TCP, UDP and RAW sockets can be used.</p>
 * </description>
 *
 * <copyright>
 * Copyright (c) 2017-2020 CODESYS Development GmbH, Copyright (c) 1994-2016 3S-Smart Software Solutions GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`SysSocket')

#ifndef CDECL
	#define CDECL
#endif

/**
 * <category>AddressFamily</category>
 * <description>Socket family definitions</description>
 */
#define	SOCKET_AF_UNSPEC		0			/* unspecified */
#define	SOCKET_AF_LOCAL			1			/* local to host (pipes, portals) */
#define	SOCKET_AF_UNIX			SOCKET_AF_LOCAL	/* backward compatibility */
#define	SOCKET_AF_INET			2			/* internetwork: UDP, TCP, etc. */
#define	SOCKET_AF_IMPLINK		3			/* Arpanet imp addresses */
#define	SOCKET_AF_PUP			4			/* pup protocols: e.g. BSP */
#define	SOCKET_AF_CHAOS			5			/* MIT CHAOS protocols */
#define	SOCKET_AF_NS			6			/* XEROX NS protocols */
#define	SOCKET_AF_ISO			7			/* ISO protocols */
#define	SOCKET_AF_OSI			SOCKET_AF_ISO
#define	SOCKET_AF_ECMA			8			/* European computer manufacturers */
#define	SOCKET_AF_DATAKIT		9			/* Data kit protocols */
#define	SOCKET_AF_CCITT			10			/* CCITT protocols, X.25 etc */
#define	SOCKET_AF_SNA			11			/* IBM SNA */
#define SOCKET_AF_DECnet		12			/* DECnet */
#define SOCKET_AF_DLI			13			/* DEC Direct data link interface */
#define SOCKET_AF_LAT			14			/* LAT */
#define	SOCKET_AF_HYLINK		15			/* NSC Hyper channel */
#define	SOCKET_AF_APPLETALK		16			/* Apple Talk */
#define	SOCKET_AF_ROUTE			17			/* Internal Routing Protocol */
#define	SOCKET_AF_LINK			18			/* Link layer interface */
#define	SOCKET_pseudo_AF_XTP	19			/* eXpress Transfer Protocol (no AF) */
#define	SOCKET_AF_COIP			20			/* connection-oriented IP, aka ST II */
#define	SOCKET_AF_CNT			21			/* Computer Network Technology */
#define SOCKET_pseudo_AF_RTIP	22			/* Help Identify RTIP packets */
#define	SOCKET_AF_IPX			23			/* Novell Internet Protocol */
#define	SOCKET_AF_SIP			24			/* Simple Internet Protocol */
#define SOCKET_pseudo_AF_PIP	25			/* Help Identify PIP packets */
#define	SOCKET_AF_MAX			26
#define	SOCKET_AF_INET_BSD		100			/* BSD-specific INET */
#define	SOCKET_AF_INET_STREAMS	101			/* STREAMS-specific INET */

/**
 * <category>Socket protocols</category>
 * <description>Socket protocols for SysSockGetOption()/SysSockSetOption()</description>
 */
#define SOCKET_IPPROTO_IP                0		/* IP level */
#define SOCKET_IPPROTO_ICMP              1		/* control message protocol */
#define SOCKET_IPPROTO_IGMP              2		/* group management protocol */
#define SOCKET_IPPROTO_GGP               3		/* gateway^2 (deprecated) */
#define SOCKET_IPPROTO_TCP               6		/* TCP */
#define SOCKET_IPPROTO_PUP              12		/* pup */
#define SOCKET_IPPROTO_UDP              17		/* user datagram protocol */
#define SOCKET_IPPROTO_IDP              22		/* XNS IDP */
#define SOCKET_IPPROTO_ND               77		/* UNOFFICIAL net disk protocol */
#define SOCKET_IPPROTO_TLS             254		/* UNOFFICIAL TCP / TLS protocol */
#define SOCKET_IPPROTO_RAW             255		/* raw IP packet */
#define SOCKET_IPPROTO_MAX             256

/**
 * <category>Socket level</category>
 * <description>Level number for SysSockGetOption()/SysSockSetOption() to apply to socket itself</description>
 */
#define	SOCKET_SOL                     0xffff	/* level for socket itself in the same numbering space as IPPROTO_TCP, IPPROTO_IP, etc. */

/**
 * <category>Socket options</category>
 * <description>Socket options for SysSockGetOption()/SysSockSetOption()</description>
 */
#define	SOCKET_SO_DEBUG			0x0001		/* turn on debugging info recording */
#define	SOCKET_SO_ACCEPTCONN	0x0002		/* socket has had listen() */
#define	SOCKET_SO_REUSEADDR		0x0004		/* allow local address reuse */
#define	SOCKET_SO_KEEPALIVE		0x0008		/* keep connections alive. See category "TCP keep-alive options" for extended parameters for this option. */
#define	SOCKET_SO_DONTROUTE		0x0010		/* just use interface addresses */
#define	SOCKET_SO_BROADCAST		0x0020		/* permit sending of broadcast messages */
#define	SOCKET_SO_USELOOPBACK	0x0040		/* bypass hardware when possible */
#define	SOCKET_SO_LINGER		0x0080		/* linger on close if data present. See category "Linger on close options" for extended parameters for this option. */
#define	SOCKET_SO_OOBINLINE		0x0100		/* leave received OOB data in line */
#define	SOCKET_SO_REUSEPORT		0x0200		/* allow local address & port reuse */
#define SOCKET_SO_SNDBUF		0x1001		/* send buffer size */
#define SOCKET_SO_RCVBUF		0x1002		/* receive buffer size */
#define SOCKET_SO_SNDLOWAT		0x1003		/* send low-water mark */
#define SOCKET_SO_RCVLOWAT		0x1004		/* receive low-water mark */
#define SOCKET_SO_SNDTIMEO		0x1005		/* send timeout */
#define SOCKET_SO_RCVTIMEO		0x1006		/* receive timeout */
#define	SOCKET_SO_ERROR			0x1007		/* get error status and clear */
#define	SOCKET_SO_TYPE			0x1008		/* get socket type */
#define SOCKET_SO_PROTOTYPE		0x1009		/* get/set protocol type */
#define SOCKET_SO_HOSTNAME		0x2001		/* get/set the host-name for TLS connections. Needed for SNI support */
#define SOCKET_SO_STARTTLS		0x3001		/* Upgrade standard socket to TLS! Works only on sockets with socket type SYSSOCK_TYPE_STARTTLS! */

/**
 * <category>Socket TCP options</category>
 * <description>Socket options for SysSockGetOption()/SysSockSetOption(). Only to be used for SOCKET_IPPROTO_TCP.</description>
 */
#define	SOCKET_TCP_NODELAY		0x0001		/* don't delay send to coalesce packets */
#define	SOCKET_TCP_MAXSEG		0x0002		/* set maximum segment size */

/**
 * <category>IP multicast options</category>
 * <description>Socket options for SysSockGetOption()/SysSockSetOption(). Only to be used for SOCKET_IPPROTO_IP.</description>
 */
#define SOCKET_IP_MULTICAST_IF		0x0009		/* IP multi-cast interface */
#define	SOCKET_SO_MULTICAST_IF		SOCKET_IP_MULTICAST_IF	/* backward compatibility */
#define SOCKET_IP_MULTICAST_TTL 	0x000A		/* IP multi-cast TTL (hop limit) */
#define SOCKET_IP_MULTICAST_LOOP	0x000B		/* IP multi-cast loop-back */
#define SOCKET_IP_ADD_MEMBERSHIP	0x000C		/* Add an IP group membership. See category "IP multi-cast options" for extended parameters for this option. */
#define SOCKET_IP_DROP_MEMBERSHIP	0x000D		/* Drop an IP group membership. See category "IP multi-cast options" for extended parameters for this option. */
#define SOCKET_IP_DONTFRAGMENT		0x000E		/* Indicates that data should not be fragmented regardless of the local MTU. Valid only for message oriented protocols (UDP etc). */

/**
 * <category>Socket types</category>
 * <description>Different socket types</description>
 */
#define SOCKET_STREAM			1			/* stream socket */
#define SOCKET_DGRAM			2			/* datagram socket */
#define SOCKET_RAW				3			/* raw-protocol interface */
#define SOCKET_RDM				4			/* reliably-delivered message */
#define SOCKET_SEQPACKET		5			/* sequenced packet stream */

/**
 * <category>Socket class handling</category>
 * <description>Definitions of bits in Internet address integers.
 *	On subnets, the decomposition of addresses to host and net parts
 *	is done according to subnet mask, not the masks here.</description>
 */
#define SOCKET_IN_CLASSA(i)            (((RTS_UI32)(i) & UINT32_C(0x80000000)) == 0)
#define SOCKET_IN_CLASSA_NET           UINT32_C(0xff000000)
#define SOCKET_IN_CLASSA_NSHIFT        24
#define SOCKET_IN_CLASSA_HOST          UINT32_C(0x00ffffff)
#define SOCKET_IN_CLASSA_MAX           128

#define SOCKET_IN_CLASSB(i)            (((RTS_UI32)(i) & UINT32_C(0xc0000000)) == UINT32_C(0x80000000))
#define SOCKET_IN_CLASSB_NET           UINT32_C(0xffff0000)
#define SOCKET_IN_CLASSB_NSHIFT        16
#define SOCKET_IN_CLASSB_HOST          UINT32_C(0x0000ffff)
#define SOCKET_IN_CLASSB_MAX           65536

#define SOCKET_IN_CLASSC(i)            (((RTS_UI32)(i) & UINT32_C(0xe0000000)) == UINT32_C(0xc0000000))
#define SOCKET_IN_CLASSC_NET           UINT32_C(0xffffff00)
#define SOCKET_IN_CLASSC_NSHIFT        8
#define SOCKET_IN_CLASSC_HOST          UINT32_C(0x000000ff)

#define SOCKET_INADDR_ANY              UINT32_C(0x00000000)
#define SOCKET_INADDR_LOOPBACK         UINT32_C(0x7f000001)
#define SOCKET_INADDR_BROADCAST        UINT32_C(0xffffffff)
#define SOCKET_INADDR_NONE             UINT32_C(0xffffffff)

/**
 * <category>Ioctl commands</category>
 * <description>Control commands to set sockets to blocking or non-blocking</description>
 */
#define SOCKET_FIONREAD					1		/* use to determine the amount of data pending in the network's input buffer */
#define SOCKET_FIONBIO					2		/* set socket to non-blocking; argument must be non zero */

/**
 * <category>TCP flags</category>
 * <description></description>
 */
#define SOCKET_MSG_NONE        0x00
#define SOCKET_MSG_OOB         0x01				/* process out-of-band data */
#define SOCKET_MSG_PEEK        0x02				/* peek at incoming message */
#define SOCKET_MSG_DONTROUTE   0x04				/* send without using routing tables */
#define SOCKET_MSG_DONTWAIT	   0x08				/* send TCP frame directly without blocking */

/**
 * <category>Shutdown flags</category>
 * <description>Flags to specify, which operations are no longer be allowed</description>
 */
#define SOCKET_SD_RECEIVE	0x00
#define SOCKET_SD_SEND		0x01
#define SOCKET_SD_BOTH		0x02


/**
 * <category>INADDR</category>
 * <description>Numeric IP-Address union to access different parts of the IP-address. IP-Address in S_addr should be in Ethernet byte order</description>
 * <element name="s_b1" type="IN">1 byte of IP-address</element>
 * <element name="s_b2" type="IN">2 byte of IP-address</element>
 * <element name="s_b3" type="IN">3 byte of IP-address</element>
 * <element name="s_b4" type="IN">4 byte of IP-address</element>
 * <element name="s_w1" type="IN">Lo-word of IP-address</element>
 * <element name="s_w2" type="IN">Hi-word of IP-address</element>
 * <element name="S_addr" type="IN">DWORD of IP-address</element>
 */
typedef struct
{
	union
	{
        struct
		{
			RTS_IEC_BYTE s_b1	;
			RTS_IEC_BYTE s_b2	;
			RTS_IEC_BYTE s_b3	;
			RTS_IEC_BYTE s_b4	; 
		} S_un_b;
        struct
		{
			RTS_IEC_WORD s_w1	;
			RTS_IEC_WORD s_w2	;
		} S_un_w;
        RTS_IEC_UDINT S_addr	;
    } S_un;
} INADDR;

/**
 * <category>SOCKADDRESS</category>
 * <description>The SOCKADDRESS structure is used to define a socket address</description>
 * <element name="sin_family" type="IN">Address family</element>
 * <element name="sin_port" type="IN">Port number</element>
 * <element name="sin_addr" type="IN">Ip address</element>
 * <element name="sin_zero" type="IN">Zero bytes</element>
 */
typedef struct
{
	RTS_IEC_INT		sin_family		;
	RTS_IEC_UINT	sin_port		;
	INADDR			sin_addr		;	
	RTS_IEC_BYTE	sin_zero[8]		;
} SOCKADDRESS;

/**
 * <category>TCP keep-alive options</category>
 * <description>
 *	Parameters for the socket option SOCKET_SO_KEEPALIVE.
 *	NOTE:
 *	If one of the parameters is not supported, the result of SysSockSetOption() is ERR_NOT_SUPPORTED. In this case, the corresponding result of the option contains the error result.
 * </description>
 * <element name="bOn" type="IN">1=Enable keep-alive, 0=Disable</element>
 * <element name="probes" type="IN">the number of unacknowledged probes to send before considering the connection dead and notifying the application layer.
 *								NOTE: Is not supported by every platform!</element>
 * <element name="probesResult" type="OUT">Error code for the probes parameter. Returns ERR_NOT_SUPPORTED, if option is not available on the target</element>
 * <element name="timeout" type="IN">specifies the timeout in milliseconds with no activity until the first keep-alive packet is sent</element>
 * <element name="timeoutResult" type="OUT">Error code for the timeout parameter. Returns ERR_NOT_SUPPORTED, if option is not available on the target</element>
 * <element name="interval" type="IN">specifies the interval in milliseconds between when successive keep-alive packets are sent if no acknowledgment is received</element>
 * <element name="intervalResult" type="OUT">Error code for the interval parameter. Returns ERR_NOT_SUPPORTED, if option is not available on the target</element>
 */
typedef struct RTS_SOCKET_SO_VALUE_TCP_KEEPALIVE_T
{
	RTS_I32 bOn;
	RTS_UI32 probes;
	RTS_RESULT probesResult;
	RTS_UI32 timeout;
	RTS_RESULT timeoutResult;
	RTS_UI32 interval;
	RTS_RESULT intervalResult;
} RTS_SOCKET_SO_VALUE_TCP_KEEPALIVE;

/**
 * <category>Linger on close options</category>
 * <description>
 *	Parameters for the socket option SOCKET_SO_LINGER.
 * </description>
 * <element name="l_onoff" type="IN">Specifies whether a socket should remain open for a specified amount of time 
 *                                   after a closesocket function call to enable queued data to be sent. 0=Socket will not remain open.</element>
 * <element name="l_linger" type="IN">The linger time in seconds. This member specifies how long to remain open after a closesocket function call to enable queued data to be sent.</element>
 */
 typedef struct
{
    RTS_IEC_WORD l_onoff;
    RTS_IEC_WORD l_linger;
} SOCKOPT_LINGER;

/**
 * <category>IP multi-cast options</category>
 * <description>
 *	Parameters for the socket options SOCKET_IP_ADD_MEMBERSHIP and SOCKET_IP_DROP_MEMBERSHIP to join/leave 
 *  the socket to/from the supplied multi-cast group on the specified interface.
 * </description>
 * <element name="imr_multiaddr" type="IN">The address of the IPv4 multi-cast group.</element>
 * <element name="imr_interface" type="IN">The local address of the interface on which the multi-cast group should be joined or dropped.</element>
 */
typedef struct RTS_SOCKET_SO_VALUE_IP_MREQ_T
{
	INADDR imr_multiaddr;
	INADDR imr_interface;
} RTS_SOCKET_SO_VALUE_IP_MREQ;

#define SOCKET_FD_SETSIZE				64

typedef struct
{
	RTS_IEC_UDINT	fd_count						;	/* how many are SET? */
	RTS_HANDLE		fd_array[SOCKET_FD_SETSIZE]		;	/* an array of SOCKETs */
} SOCKET_FD_SET;

/* Compatibility Macros */
#define SOCKET_FD_INIT(fd, set)  CAL_SysSockFdInit(fd, set)
#define SOCKET_FD_ISSET(fd, set) CAL_SysSockFdIsset(fd, set)
#define SOCKET_FD_ZERO(set)      CAL_SysSockFdZero(set)
#define SOCKET_ZERO_FD(set)      CAL_SysSockFdZero(set)

typedef struct
{
	RTS_IEC_DINT tv_sec		;	/* seconds */
	RTS_IEC_DINT tv_usec	;	/* and microseconds */
} SOCKET_TIMEVAL; 

typedef struct
{
        char    * h_name;        /* official name of host */
        char    ** h_aliases;    /* alias list */
        RTS_IEC_INT	h_addrtype;      /* host address type */
        RTS_IEC_INT	h_length;        /* length of address */
        char    ** h_addr_list;  /* list of addresses, each in Ethernet byte order */
#define h_addr  h_addr_list[0]   /* address, for backward compatibility */
} SOCK_HOSTENT;


/**
 * <category>Adapter types</category>
 * <description></description>
 */
#define SOCK_AIT_ETHERNET			1	/* generic Ethernet adapter - default, if nothing else matches*/
#define SOCK_AIT_LOCALHOST			2	/* localhost adapter */
#define SOCK_AIT_PPP				3	/* PPP adapter - broadcasts are not supported */
#define SOCK_AIT_WIRELESS			4	/* wireless (e. g. WLAN) network adapter */

/**
 * <category>Adapter information flags</category>
 * <description></description>
 */
#define SOCK_AIF_NONE					UINT32_C(0x00000000)	/* no flag set */
#define SOCK_AIF_INACTIVE				UINT32_C(0x00000001)	/* interface not ready for IP communication (no driver, no IP address, no link, ...) */
#define SOCK_AIF_ALIAS_IP				UINT32_C(0x00000002)	/* further IP (aka alias address) of adapter */
#define SOCK_AIF_DYNAMIC_IP				UINT32_C(0x00000004)	/* dynamic IP address, provided by DHCP, BOOTP, etc. Cannot be changed by SysSockSetIpAddressAndNetMask() */
#define SOCK_AIF_FIX_IP					UINT32_C(0x00000008)	/* fix (e. g. hard coded) IP address. Cannot be changed by SysSockSetIpAddressAndNetMask() */
#define SOCK_AIF_IP_CHANGE_ALLOWED		UINT32_C(0x00000010)	/* adapter is white listed to allow address changes. IP address can be likely changed by SysSockSetIpAddressAndNetMask() */
#define SOCK_AIF_GATEWAY_INFO_VALID		UINT32_C(0x00000020)	/* DefaultGateway address is valid. Must not be set, if no Gateway information is provided by the system. */
#define SOCK_AIF_DNS_INFO_VALID			UINT32_C(0x00000040)	/* DNS address and suffix is valid. Is not set, if no DNS information is provided by the system. */
#define SOCK_AIF_DHCP_INFO_VALID		UINT32_C(0x00000080)	/* DHCP address is valid. Is not set, if no DHCP information is provided by the system. */
#define SOCK_AIF_INFO_VALID				UINT32_C(0x00008000)	/* Adapter is valid - only valid adapters are returned by SysSockGetFirstAdapterInfo() or SysSockGetNextAdapterInfo() */

/**
 * <category>Static defines for adapter information </category>
 * <description></description>
 */
#define ADAPTER_INFO_STRUCT_VERSION				1	/* version number of structure, to be increased on changes */
#define ADAPTER_INFO_STRUCT2_VERSION			2	/* version number of structure with DNS and DHCP info, to be increased on changes */
#define ADAPTER_INFO_MAC_ADDR_LENGTH			6	/* byte length of MAC address; fix value */
#define ADAPTER_INFO_NAME_LEN				  256	/* max. length of adapter name */ 
#define ADAPTER_INFO_DESC_LEN				  256	/* max. length of adapter description */
#define ADAPTER_INFO_DNSSUFFIX_LEN			  256	/* max. length of DNS suffix */

/**
 * <category>SysSocket adapter information</category>
 * <description>Structure to describe a network adapter on SysSocket level</description>
 * <element name="ui32StructSize" type="OUT">Size of the structure SOCK_ADAPTER_INFO</element>
 * <element name="ui32Version" type="OUT">Version number of the structure</element>
 * <element name="ui32Index" type="OUT">Index number of this adapter. Value is constant until shutdown</element>
 * <element name="ui32Reserved" type="OUT">Reserved for internal use and to align structure</element>
 * <element name="pwszName" type="OUT">Name of the network interface</element>
 * <element name="pwszDescription" type="OUT">Description text for the network interface; may be NULL</element>
 * <element name="aui8Mac" type="OUT">MAC ID (hardware address)</element>
 * <element name="ui16Type" type="OUT">Adapter type, see category "Adapter types"</element>
 * <element name="ui32Flags" type="OUT">Flags to characterize the adapter, see category "Adapter information flags"</element>
 * <element name="IpAddr" type="OUT">IP address in network byte order</element>
 * <element name="NetMask" type="OUT">Subnet mask in network byte order</element>
 * <element name="DefaultGateway" type="OUT">IP address of default gateway in network byte order; only valid if SOCK_AIF_GATEWAY_INFO_VALID is set in dwFlags</element>
 * <element name="PrimaryNameServer" type="OUT">IP address of the primary name server</element>
 * <element name="SecondaryNameServer" type="OUT">IP address of the secondary name server</element>
 * <element name="pwszDNSSuffix" type="OUT"> DNS suffix</element>
 * <element name="DHCPServer" type="OUT">IP address of the DHCP server</element>
*/
typedef struct tagSOCK_ADAPTER_INFO
{
	RTS_UI32 ui32StructSize;
	RTS_UI32 ui32Version;
	RTS_UI32 ui32Index;
	RTS_UI32 ui32Reserved;
	RTS_WCHAR *pwszName;
	RTS_WCHAR *pwszDescription;
	RTS_UI8 aui8Mac[ADAPTER_INFO_MAC_ADDR_LENGTH];
	RTS_UI16 ui16Type;
	RTS_UI32 ui32Flags;
	INADDR IpAddr;
	INADDR NetMask;
	INADDR DefaultGateway;
	INADDR PrimaryNameServer;
	INADDR SecondaryNameServer;
	RTS_WCHAR *pwszDNSSuffix;
	INADDR DHCPServer;
} SOCK_ADAPTER_INFO;

/**
 * <category>UDP reply</category>
 * <description>UDP reply information</description>
 * <element name="ulSourceAddress" type="IN">Sender IP-Address</element>
 * <element name="szSourceAddress" type="IN">Sender IP-Address as string</element>
 * <element name="iRecv" type="IN">Number of received bytes</element>
 * <element name="usRecvPort" type="IN">Received port, in host byte-order!</element>
 */
typedef struct UDP_REPLYtag
{
	RTS_IEC_DWORD ulSourceAddress;
	RTS_IEC_STRING szSourceAddress[32];
	RTS_IEC_XINT iRecv;
	RTS_IEC_WORD usRecvPort;
} UDP_REPLY;

/* For compatibility with IEC library! */
#define UDP_REPLY2	UDP_REPLY

/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>
 *	Settings prefix for network adapter list. Has to be used for all list settings.
 *  The index number, separated by dots, have to be increased by one for each configured adapter name.
 *  Adapter names can be configured by an ASCII name oder by an Unicode name. If for a index number
 *  was found a "NameUnicode" setting, the "Name" setting is ignored.
 *  Example: Adapter.0.Name=Lan1
 *           Adapter.1.Name=Lan2
 *           Adapter.2.NameUnicode="L\00a\00n\003\00"
 * </description>
 */
#define SYSSOCKET_ADAPTER_PREFIX								"Adapter"

/**
 * <category>Settings</category>
 * <type>WString</type>
. * <description>Setting for network. adapter list. Adapter name in Unicode.
 .*	Example: Adapter.0.NameUnicode="L\00a\00n\001\00"
 * </description>
 */
#define SYSSOCKETKEY_WSTRING_NAME_UNICODE						"NameUnicode"

/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>Setting for network adapter list. Adapter name in ASCII.
 *  Only evaluated, if no "NameUnicode" setting for the same adapter index exists.
 *	Example: Adapter.0.Name="Lan1"
 * </description>
 */
#define SYSSOCKETKEY_STRING_NAME								"Name"

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>Setting for network adapter list to specify, if it is allowed to set the  
 *  IP address and subnet mask for this adapter. If enabled (1) the IP address and subnet mask
 *  can be set by SysSockSetIpAddressAndNetMask(). 
 *	Example: Adapter.0.Name="Lan1"
 *           Adapter.0.EnableSetIpAndMask=1    
 * </description>
 */
#define SYSSOCKETKEY_INT_ENABLE_SETIPANDMASK					"EnableSetIpAndMask"
#ifndef SYSSOCKETVALUE_INT_ENABLE_SETIPANDMASK_DEFAULT
	#define SYSSOCKETVALUE_INT_ENABLE_SETIPANDMASK_DEFAULT			0
#endif

/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>Setting to specify the socket interface name to be used by the runtime.
 * Only for QNX. The default is "tsec0". </description>
 */
#define SYSSOCKETKEY_STRING_QNX_ITFNAME							"QNX.ItfName"

/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>Setting to specify the IP address of the target. Both settings
 *  IP-address and subnet-mask have to be configured. The combination IP-address=0.0.0.0
 *  and subnet-mask=0.0.0.0 can be used to remove the IP address from the adapter. 
 *  With this configuration is no IP based communication possible, until an IP address is set
 *  e. g. by calling SysSockSetIpAddressAndNetMask().
 *	Example: 
 *  Adapter.0.Name="Lan1"
 *  Adapter.0.ipaddress=192.168.2.1
 *  Adapter.0.subnetmask=255.255.255.0
 *  Adapter.0.gateway=192.168.2.2
 *  Runtime systems based on SysSocketEmbedded use a simplified configuration, 
 *  as these support only a single network adapter: 
 *	IP-address=192.168.2.1
 *  subnet-mask=255.255.255.1
 *  Note: On some operating systems it is necessary to store this in a non-volatile way to
 *        provide the IP address and the subnet mask for the next boot to the operating system,
 *        before the runtime systems is started. In such cases the system must be booted twice 
 *        after the setting was added or changed. The first boot is needed to read the settings
 *        by the runtime system and to store the information for the operating system. The
 *        second boot activates the setting during the operating system's startup. 
 *  OS-specific information:  
 * 	On Microsoft Windows based runtime systems the following Windows registry key will be written
 *  to disable the IP auto-configuration feature for the referenced adapter:
 *  IPAutoconfigurationEnabled = 0 (DWORD)
 *  The key is located here:
 *  HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\services\Tcpip\Parameters\Interfaces\<Guid>\
 *  Whereas <Guid> is replaced by the GUID, identifying the configured network adapter.
 * </description>
 */
#define SYSSOCKETKEY_STRING_IPADDRESS							"ipaddress"

/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>Setting to specify the subnet mask of the target. See setting ipaddress for details.</description>
 */
#define SYSSOCKETKEY_STRING_SUBNETMASK							"subnetmask"

/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>Setting to specify the default gateway of the target. See setting ipaddress for details.</description>
 */
#define SYSSOCKETKEY_STRING_GATEWAY							    "gateway"

/**
 * <category>Settings</category>
 * <type>String</type>
 * <description>Setting to specify the send IP address (destination) of the system log messages.
 *	NOTE:
 *	"255.255.255.255" is the broadcast address to send the system log message to all network members!
 * </description>
 */
#define SYSSOCKETKEY_STRING_SYSLOG_IPADDRESS					"sysLog.IPAddress"
#ifndef SYSSOCKETVALUE_STRING_SYSLOG_IPADDRESS_DEFAULT
	#define SYSSOCKETVALUE_STRING_SYSLOG_IPADDRESS_DEFAULT		"127.0.0.1"
#endif

/**
 * <category>Settings</category>
 * <type>Int</type>
 * <description>Setting to specify the UDP send port of the system log messages</description>
 */
#define SYSSOCKETKEY_INT_SYSLOG_PORT							"sysLog.Port"
#ifndef SYSSOCKETVALUE_INT_SYSLOG_PORT_DEFAULT
	#define SYSSOCKETVALUE_INT_SYSLOG_PORT_DEFAULT				514
#endif

/**
 * <category>Compiler switch</category>
 * <description>
 *	Compiler switches to enable/disable single features in the component.
 * </description>
 * <element name="SYSSOCKET_DISABLE_SYSLOG">
 *	Switch to disable the feature completely, that all logger entries are transmitted via sysLog messages. 
 *  The system log messages are based on standard RFC5424 (http://tools.ietf.org/html/rfc5424).
 *	A system log message is typically sent via UDP to "localhost" and on port 514. Both parameters can be specified (see corresponding settings).
 *	NOTE:
 *	To activate the sysLog feature, you have to specify the corresponding back-end at the assigned logger, e.g.:
 *		[CmpLog]
 *		Logger.0.Backend.0.ClassId=0x00000135
 * </element>
 */

/**
 * <category>Static defines</category>
 * <description>Number of static allocated blocks in adapter information pool.</description>
 */
#ifndef SYSSOCKET_NUM_OF_STATIC_ADAPTER_INFOS
  #define SYSSOCKET_NUM_OF_STATIC_ADAPTER_INFOS 1
#endif


/**
 * <category>Static defines</category>
 * <description>Only for SysSocketEmbedded: Set Transmit MTU size.</description>
 */
#ifndef SOCKET_MTU_SIZE
  #define SOCKET_MTU_SIZE 1500
#endif

/**
 * <category>Static defines</category>
 * <description>Only for SysSocketEmbedded: Set Receive Buffer Size.</description>
 */
#ifndef SOCKET_BUFFER_SIZE
  #define SOCKET_BUFFER_SIZE (SOCKET_MTU_SIZE*3)
#endif

/**
 * <category>Static defines</category>
 * <description>Only for SysSocketEmbedded: Number of supported sockets (one is enough for communication).</description>
 */
#ifndef SYSSOCKET_NUM_OF_STATIC_SOCKETS
  #define SYSSOCKET_NUM_OF_STATIC_SOCKETS 1
#endif

/**
 * <category>Static defines</category>
 * <description>Only for SysSocketEmbedded: Number of ARP entries in our cache.</description>
 */
#ifndef SYSSOCKET_NUM_OF_STATIC_ARP_ENTRIES
  #define SYSSOCKET_NUM_OF_STATIC_ARP_ENTRIES 5
#endif

/**
 * <category>Static defines</category>
 * <description>Only for SysSocketEmbedded: Default IP Address (can be overwritten by setting).</description>
 */
#ifndef SYSSOCKET_DEFAULT_IP
  #define SYSSOCKET_DEFAULT_IP UINT32_C(0xc0a80102) /* 192.168.1.2 */
#endif

/**
 * <category>Static defines</category>
 * <description>Only for SysSocketEmbedded: Default Subnet Mask (can be overwritten by setting).</description>
 */
#ifndef SYSSOCKET_DEFAULT_SUBNET
  #define SYSSOCKET_DEFAULT_SUBNET UINT32_C(0xFFFFFF00) /* 255.255.255.0 */
#endif

/**
 * <category>Event parameter</category>
 * <element name="pwszAdapterName" type="IN">Name of the network interface; may be NULL or an empty string, if only one adapter is available</element>
 * <element name="pIpAddr" type="IN">IP address to set in network byte order.</element>
 * <element name="pNetMask" type="IN">Subnet mask to set in network byte order.</element>
 * <element name="rResult" type="INOUT">Result</element>
 *	<ul>
 *		<li>ERR_PARAMETER: At least one of the passed pointers is NULL.</li>
 *		<li>ERR_OPERATION_DENIED: Adapter is not white listed to allow address changes or the operation was denied by the event EVT_SysSocket_BeforeSetIpAndMask.</li>
 *		<li>ERR_NOTHING_TO_DO: Only to be returned by EVT_SysSocket_BeforeSetIpAndMask (see there).</li>
 *		<li>ERR_NO_OBJECT: Adapter with the specified name does not exist.</li>
 *		<li>ERR_NO_CHANGE: Adapter have a fix (not changeable) or dynamic (DHCP) ip address.</li>
 *		<li>ERR_FAILED: IP address/subnet mask could not be set.</li>
 *		<li>ERR_OK: IP address/subnet mask was set successfully.</li>
 *	</ul>
*/
typedef struct
{
	RTS_WCHAR* pwszAdapterName; 
	INADDR* pIpAddr;
	INADDR* pNetMask;
	RTS_RESULT rResult;
} EVTPARAM_SysSocket_SetIpAndMask;
#define EVTPARAMID_SysSocket_SetIpAndMask	0x0001
#define EVTVERSION_SysSocket_SetIpAndMask	0x0001

/**
 * <category>Event parameter</category>
 * <element name="pwszAdapterName" type="IN">Name of the network interface; may be NULL or an empty string, if only one adapter is available</element>
 * <element name="pGatewayAddr" type="IN">Gateway address to set in network byte order.</element>
 * <element name="rResult" type="INOUT">Result</element>
 *	<ul>
 *		<li>ERR_PARAMETER: At least one of the passed pointers is NULL.</li>
 *		<li>ERR_OPERATION_DENIED: Adapter is not white listed to allow address changes or the operation was denied by the event EVT_SysSocket_BeforeSetIpAndMask.</li>
 *		<li>ERR_NOTHING_TO_DO: Only to be returned by EVT_SysSocket_BeforeSetIpAndMask (see there).</li>
 *		<li>ERR_NO_OBJECT: Adapter with the specified name does not exist.</li>
 *		<li>ERR_NO_CHANGE: Adapter have a fix (not changeable) or dynamic (DHCP) gateway address.</li>
 *		<li>ERR_FAILED: Gateway address could not be set.</li>
 *		<li>ERR_OK: Gateway address was set successfully.</li>
 *	</ul>
*/
typedef struct
{
	RTS_WCHAR* pwszAdapterName; 
	INADDR* pGatewayAddr;
	RTS_RESULT rResult;
} EVTPARAM_SysSocket_SetGateway;
#define EVTPARAMID_SysSocket_SetGateway	0x0002
#define EVTVERSION_SysSocket_SetGateway	0x0001

/**
 * <category>Event parameter</category>
 * <element name="pAdapter" type="INOUT">Adapter Information. Information about configuration type (static/dhcp) and DHCP server address may be added</element>
*/
typedef struct
{
	SOCK_ADAPTER_INFO *pAdapter;
} EVTPARAM_SysSocket_GetAdditionalAdapterInfo;
#define EVTPARAMID_SysSocket_GetAdditionalAdapterInfo	0x0003
#define EVTVERSION_SysSocket_GetAdditionalAdapterInfo	0x0001

/**
 * <category>Events</category>
 * <description>Event is sent in function SysSockSetIpAddressAndNetMask() before the 
 * IP address and network mask is set in the SysSocket OS layer. The following results
 * are provided to the event:
 * ERR_OPERATION_DENIED: Adapter is not white listed to allow address changes.
 * ERR_OK: Adapter is in the white lists for address changes.
 * The result codes ERR_OPERATION_DENIED and ERR_OK can be changed to the opposite 
 * to overwrite the adapter list settings. Furthermore it is possible to implement
 * the functionality to set the IP address and network mask completely in this event.
 * In this case ERR_NOTHING_TO_DO have to be returned to signal this to the internal
 * implementation. Then the internal implementation is skipped and 
 * SysSockSetIpAddressAndNetMask() will return ERR_OK.
 * The event should only be used by OEMs an not by the application.</description>
 * <param name="pEventParam" type="IN">EVTPARAM_CmpDevice_InteractiveLogin</param>
 */
#define EVT_SysSocket_BeforeSetIpAndMask			MAKE_EVENTID(EVTCLASS_INFO, 1)

/**
 * <category>Events</category>
 * <description>Event is sent in function SysSockSetIpAddressAndNetMask() after the 
 * IP address and network mask was set in the SysSocket OS layer. The event is called
 * in any case regardless, if the operation was successful or not. Typically this
 * is used to store the new IP configuration for example in a system boot up file 
 * to keep it also after a reboot.
 * The event should only be used by OEMs an not by the application.</description>
 * <param name="pEventParam" type="IN">EVTPARAM_CmpDevice_InteractiveLogin</param>
 */
#define EVT_SysSocket_AfterSetIpAndMask				MAKE_EVENTID(EVTCLASS_INFO, 2)

/**
 * <category>Events</category>
 * <description>Event is sent in function SysSockSetGateway() before the 
 * gateway address is set in the SysSocket OS layer. The following results
 * are provided to the event:
 * ERR_OPERATION_DENIED: Adapter is not white listed to allow address changes.
 * ERR_OK: Adapter is in the white lists for address changes. The result codes 
 * ERR_OPERATION_DENIED and ERR_OK can be changed to the opposite to overwrite 
 * the adapter list settings. Furthermore it is possible to implement the 
 * functionality to set the gateway address completely in this event. In this 
 * case ERR_NOTHING_TO_DO have to be returned to signal this to the internal
 * implementation. Then the internal implementation is skipped and 
 * SysSockSetGateway() will return ERR_OK.
 * The event should only be used by OEMs an not by the application.</description>
 * <param name="pEventParam" type="IN">EVTPARAM_CmpDevice_InteractiveLogin</param>
 */
#define EVT_SysSocket_BeforeSetGateway			    MAKE_EVENTID(EVTCLASS_INFO, 3)

/**
 * <category>Events</category>
 * <description>Event is sent in function SysSockSetGateway() after the gateway
 * address was set in the SysSocket OS layer. The event is called in any case 
 * regardless, if the operation was successful or not. Typically this is used to
 * store the new gateway configuration for example in a system boot up file to keep 
 * it also after a reboot.
 * The event should only be used by OEMs an not by the application.</description>
 * <param name="pEventParam" type="IN">EVTPARAM_CmpDevice_InteractiveLogin</param>
 */
#define EVT_SysSocket_AfterSetGateway				MAKE_EVENTID(EVTCLASS_INFO, 4)

/**
 * <category>Events</category>
 * <description>Event is sent in function UpdateNetworkAdapterInfo() on startup of
 * the runtime for every InetV4 network adapter. Typically this is used to
 * add the information about how the adapter was configured (static/dhcp) and the 
 * DHCP Server Address.
 * Linux Only!  
 * The event should only be used by OEMs an not by the application.</description>
 * <param name="pEventParam" type="IN">GetAdditionalAdapterInfo</param>
 */
#define EVT_SysSocket_GetAdditionalAdapterInfo				MAKE_EVENTID(EVTCLASS_INFO, 5)

/** EXTERN LIB SECTION BEGIN **/
/*  Comments are ignored for m4 compiler so restructured text can be used. changecom(`/*', `*/') */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Structure to describe a network adapter on SysSocket level
 */
typedef struct tagSOCK_ADAPTER_INFORMATION
{
	RTS_IEC_UDINT udiStructSize;		/* Size of the structure SOCK_ADAPTER_INFORMATION returned from external implementation */
	RTS_IEC_UDINT udiVersion;		/* Version number of the structure */
	RTS_IEC_UDINT udiIndex;		/* Index number of this adapter. Value is constant until shutdown */
	RTS_IEC_UDINT udiReserved;		/* Reserved for internal use */
	RTS_IEC_WSTRING wsName[256];		/* Name of the network interface */
	RTS_IEC_WSTRING wsDescription[256];		/* Description text for the network interface; may be empty */
	RTS_IEC_BYTE abyMac[ADAPTER_INFO_MAC_ADDR_LENGTH - 1 + 1];		/* MAC ID (hardware address) */
	RTS_IEC_WORD wType;		/* Adapter type, see "Adapter types" contants ``SOCK_AIT_xxx`` in |GVL| */
	RTS_IEC_DWORD dwFlags;		/* Flags to characterize the adapter, see "Adapter information flags" constants ``SOCK_AIF_xxx`` in |GVL| */
	INADDR IpAddr;		/* Ip address in network byte order */
	INADDR NetMask;		/* Subnet mask in network byte order */
	INADDR DefaultGateway;		/* Ip address of default gateway in network byte order; only valid if |SOCK_AIF_GATEWAY_INFO_VALID| is set in dwFlags in |GVL| */
} SOCK_ADAPTER_INFORMATION;

/**
 * Structure to describe a network adapter on SysSocket level, including name server and DHCP server information
 */
typedef struct tagSOCK_ADAPTER_INFORMATION2
{
	RTS_IEC_UDINT udiStructSize;		/* Size of the structure SOCK_ADAPTER_INFORMATION returned from external implementation */
	RTS_IEC_UDINT udiVersion;		/* Version number of the structure */
	RTS_IEC_UDINT udiIndex;		/* Index number of this adapter. Value is constant until shutdown */
	RTS_IEC_UDINT udiReserved;		/* Reserved for internal use */
	RTS_IEC_WSTRING wsName[256];		/* Name of the network interface */
	RTS_IEC_WSTRING wsDescription[256];		/* Description text for the network interface; may be empty */
	RTS_IEC_BYTE abyMac[ADAPTER_INFO_MAC_ADDR_LENGTH - 1 + 1];		/* MAC ID (hardware address) */
	RTS_IEC_WORD wType;		/* Adapter type, see "Adapter types" contants ``SOCK_AIT_xxx`` in |GVL| */
	RTS_IEC_DWORD dwFlags;		/* Flags to characterize the adapter, see "Adapter information flags" constants ``SOCK_AIF_xxx`` in |GVL| */
	INADDR IpAddr;		/* IP address in network byte order */
	INADDR NetMask;		/* Subnet mask in network byte order */
	INADDR DefaultGateway;		/* IP address of default gateway in network byte order; only valid if |SOCK_AIF_GATEWAY_INFO_VALID| is set in dwFlags in |GVL| */
	INADDR PrimaryNameServer;		/* Primary Name Server. Value of 0.0.0.0 indicates no name server has been configured. */
	INADDR SecondaryNameServer;		/* Secondary Name Server. Value of 0.0.0.0 indicates no secondary name server has been configured. */
	RTS_IEC_WSTRING wsDNSSuffix[256];		/* Default domain name. */
	INADDR DHCPServer;		/* IP address of DHCP server; only valid if |SOCK_AIF_DHCP_INFO_VALID| is set in dwFlags in |GVL| */
} SOCK_ADAPTER_INFORMATION2;

#ifdef __cplusplus
}
#endif

/** EXTERN LIB SECTION END **/


#ifdef __cplusplus
extern "C" {
#endif

/**
 * <category>Internal flags for adapter management</category>
 * <description></description>
 */
#define SOCK_IFLAG_AF_INETFOUND				0x00000001	/* Adapter information for AF_INET already found - to be used internally in SysSocketOS implementation */
#define SOCK_IFLAG_IN_PROGRESS				0x00000002	/* Adapter information is currently checked for update - to be used internally in SysSocketOS implementation */
#define SOCK_IFLAG_FREE_STRINGS_ON_EXIT		0x00000004	/* On shutdown SysSocket.c checks this flag and if set it frees all referenced strings by calling SysMemFree() */
#define SOCK_IFLAG_FREE_HOSSPECIFIC_ON_EXIT	0x00000008	/* On shutdown SysSocket.c checks this flag and if set it frees hOsSpecific by calling SysMemFree() */

/**
 * <category>Internal SysSocket adapter information</category>
 * <description>Internal structure to describe a network adapter on SysSocket level</description>
 * <element name="hOsSpecific">Only to be used by the OS specific part to store local data</element>
 * <element name="ui32InternalFlags">Internal used flags, see category "Internal flags for adapter management"</element>
 * <element name="Adapter">Public structure SOCK_ADAPTER_INFO</element>
*/
typedef struct tagSOCK_ADAPTER_INFO_INT
{
	RTS_HANDLE hOsSpecific;
	RTS_UI32 ui32InternalFlags;
	SOCK_ADAPTER_INFO Adapter;
} SOCK_ADAPTER_INFO_INT;

/**
 * Helper functions to fill the adapter information, only to be called by OS specific implementation of SysSocket.
 */
/* Get a new adapter internal adapter information block. */ 
SOCK_ADAPTER_INFO_INT* CDECL SysSockGetAdapterInfoBlockInternal(RTS_RESULT *pResult);

/* Append a new filled adapter information block to the adapter list. */ 
RTS_RESULT CDECL SysSockAppendAdapterInfoBlockInternal(SOCK_ADAPTER_INFO_INT* pAdapter);

/* Get the first adapter. Is used to check/change the content of the adapter information. */ 
SOCK_ADAPTER_INFO_INT* CDECL SysSockGetFirstAdapterInfoInternal(RTS_RESULT *pResult);

/* Get the next adapter. Is used to check/change the content of the adapter information. */ 
SOCK_ADAPTER_INFO_INT* CDECL SysSockGetNextAdapterInfoInternal(SOCK_ADAPTER_INFO_INT *pPrevAdapter, RTS_RESULT *pResult);

/**
 * Functions to be implemented by the OS specific implementation of SysSocket.
 */
/* SysSockOSUpdateNetworkAdapterInfo() is called on startup (typically during the CH_INIT2 hook) 
   and each time the adapter information is requested by the runtime system (e. g. by a call of 
   SysSockGetFirstAdapterInfo()). It is mandatory to fill the adapter information completely
   during the first call to have a valid SysSocket adapter list afterwards.
   
   There are several ways to keep this list updated:
   1. On small systems with a static configuration, which cannot be changed anymore after startup, all 
      further calls can directly return without touching the adapter information anymore.
   
   2. If the adapter information is easy and fast to read from the system, then on each call of 
      SysSockOSUpdateNetworkAdapterInfo() the implementation can do a check or update of the adapter information.
	  Be careful, the function is usually called by different tasks and a reentrant implementation 
	  is required. Instead of using interrupt locks or semaphores, SysCpuTestAndSetBit() on a flag should 
	  be used to skip the update when this is already executed in the context of another task.

   3. For Ethernet stacks which provide a notification/callback/event for changes of the IP configuration 
	  (e. g. add/remove adapter or IP address, change of IP address/subnet mask, change of link state), the
	  adapter information shall be updated in the first call (initialization hook) and when a change is signaled.
	  
   4. It is also possible to update the SysSocket adapter information later on cyclically in the context 
      of the HookFunction() in CH_COMM_CYCLE. In this case the check/update should be executed every
	  about 5 seconds or less.   

   General implementation notes:
	- Do not touch SOCK_ADAPTER_INFO_INT.Adapter.ui32StructSize, SOCK_ADAPTER_INFO_INT.Adapter.ui32Version
	  and SOCK_ADAPTER_INFO_INT.Adapter.ui32Index, because these are filled by SysSocket.c.
	- After calling SysSockAppendAdapterInfoBlockInternal(), do not change SOCK_ADAPTER_INFO_INT.Adapter.pwszName 
	  or SOCK_ADAPTER_INFO_INT.Adapter.pwszDescription anymore.
	- If the name of an adapter changes, add a new adapter to the SysSocket adapter list.
	- All adapters remain until shutdown in the SysSocket list (with removed flag SOCK_AIF_INFO_VALID),
	  even if an adapter is removed from the system. Adapters without SOCK_AIF_INFO_VALID are hidden for the 
	  caller of SysSockGetFirstAdapterInfo() or SysSockGetNextAdapterInfo().
	- If a removed adapter is added later on again, the old list entry can be recycled (set SOCK_AIF_INFO_VALID again).
	- Set the internal flag SOCK_IFLAG_FREE_STRINGS_ON_EXIT only, if SysSocket.c should free 
	  SOCK_ADAPTER_INFO_INT.Adapter.pwszName and SOCK_ADAPTER_INFO_INT.Adapter.pwszDescription.
	- SOCK_ADAPTER_INFO_INT.hOsSpecific can be used to store local data for the adapter. This is not 
	  evaluated/touched by SysSocket.c 
	- Inactive adapters, which are not ready for IP communication (e. g. no IP, no link) should be treated as 
	  valid ones, but marked with the flag SOCK_AIF_INACTIVE in SOCK_ADAPTER_INFO_INT.Adapter.ui32Flags.
	- Both SOCK_ADAPTER_INFO_INT.ui32InternalFlags and SOCK_ADAPTER_INFO_INT.Adapter.ui32Flags must only be
	  changed on bit level and not written as complete RTS_UI32 to keep all other flags.
	- The flag SOCK_AIF_IP_CHANGE_ALLOWED is handled by the generic part of SysSocket implementation (SysSocket.c).
	- See SysSocketItf.m4/h for more information regarding SOCK_ADAPTER_INFO and SOCK_ADAPTER_INFO_INT. 
*/
RTS_RESULT CDECL SysSockOSUpdateNetworkAdapterInfo(void);

/* Set IP address and subnet mask of an adapter. Is called by SysSockSetIpAddressAndNetMask() after reading
   the adapter list settings and sending the event EVT_SysSocket_BeforeSetIpAndMask. After return 
   SysSockSetIpAddressAndNetMask() sends the event EVT_SysSocket_AfterSetIpAndMask. 
   See declaration of SysSockSetIpAddressAndNetMask() for more information (result codes etc.). 
   The new IP address and subnet mask may or may not be retained over a reboot of the device. 
   In general the caller should consider these as volatile. 
*/ 
RTS_RESULT CDECL SysSockOSSetIpAddressAndNetMask(RTS_WCHAR *pwszAdapterName, INADDR* pIpAddr, INADDR* pNetMask);

/* Set gateway address and subnet mask of an adapter. Is called by SysSockSetGateway() after reading
   the adapter list settings and sending the event EVT_SysSocket_BeforeSetGateway. After return
   SysSockSetGateway() sends the event EVT_SysSocket_AfterSetGateway. 
   See declaration of SysSockSetGateway() for more information (result codes etc.). 
   The new gateway address and subnet mask may or may not be retained over a reboot of the device. 
   In general the caller should consider these as volatile. 
*/ 
RTS_RESULT CDECL SysSockOSSetDefaultGateway(RTS_WCHAR *pwszAdapterName, INADDR* pGatewayAddr);

/* Initialization routines for OS specific modules */
RTS_RESULT CDECL SysSockOSInit(INIT_STRUCT *pInit);
RTS_RESULT CDECL SysSockOSHookFunction(RTS_UI32 ulHook, RTS_UINTPTR ulParam1, RTS_UINTPTR ulParam2);


/*---- TCP/UDP-IP protocol routines -----------------------------------------*/
/**
 * <description>
 *	Create a new socket and return the socket handle. In case of an error, RTS_INVALID_HANDLE is returned.
 * </description>
 * <param name="iAddressFamily" type="IN">Socket address family</param>
 * <param name="iType" type="IN">Socket type</param>
 * <param name="iProtocol" type="IN">Socket protocol</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <result>Handle to the socket</result>
 */
DEF_CREATEITF_API(`RTS_HANDLE',`CDECL',`SysSockCreate',`(int iAddressFamily, int iType, int iProtocol, RTS_RESULT *pResult)')

/**
 * <description>
 *	Close a socket.
 * </description>
 * <param name="hSocket" type="IN">Handle to the socket</param>
 * <result>error code</result>
 */
DEF_DELETEITF_API(`RTS_RESULT',`CDECL',`SysSockClose',`(RTS_HANDLE hSocket)')

/**
 * <description>
 *	Set options of a specified socket
 * </description>
 * <param name="hSocket" type="IN">Handle to the socket</param>
 * <param name="iLevel" type="IN">Level of the socket</param>
 * <param name="iOption" type="IN">Socket option command</param>
 * <param name="pcOptionValue" type="IN">Pointer to the option value</param>
 * <param name="iOptionLen" type="IN">Length of option value</param>
 * <result>error code</result>
 */
DEF_HANDLEITF_API(`RTS_RESULT',`CDECL',`SysSockSetOption',`(RTS_HANDLE hSocket, int iLevel, int iOption, char *pcOptionValue, int iOptionLen)')

/**
 * <description>
 *	Get options of a specified socket
 * </description>
 * <param name="hSocket" type="IN">Handle to the socket</param>
 * <param name="iLevel" type="IN">Level of the socket</param>
 * <param name="iOption" type="IN">Socket option command</param>
 * <param name="pcOptionValue" type="OUT">Pointer to get the option value</param>
 * <param name="piOptionLen" type="OUT">Pointer to the option length. Real length is returned</param>
 * <result>error code</result>
 */
DEF_HANDLEITF_API(`RTS_RESULT',`CDECL',`SysSockGetOption',`(RTS_HANDLE hSocket, int iLevel, int iOption, char *pcOptionValue, int *piOptionLen)')

/**
 * <description>
 *	Bind a socket to a socket address and port number
 * </description>
 * <param name="hSocket" type="IN">Handle to the socket</param>
 * <param name="pSockAddr" type="IN">Socket address</param>
 * <param name="iSockAddrSize" type="IN">Size of the socket address structure</param>
 * <result>error code</result>
 */
DEF_HANDLEITF_API(`RTS_RESULT',`CDECL',`SysSockBind',`(RTS_HANDLE hSocket, SOCKADDRESS *pSockAddr, int iSockAddrSize)')

/**
 * <description>
 *	Get host name of the target
 * </description>
 * <param name="pszHostName" type="OUT">Pointer to get host name</param>
 * <param name="iNameLength" type="IN">Maximum length of host-name</param>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysSockGetHostName',`(char *pszHostName, int iNameLength)')

/**
 * <description>
 *	Get host description specified by host name
 * </description>
 * <param name="pszHostName" type="IN">Pointer to host-name</param>
 * <param name="pHost" type="OUT">Pointer to host description</param>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysSockGetHostByName',`(char *pszHostName, SOCK_HOSTENT *pHost)')

/**
 * <description>
 *	Convert IP address to a string	  
 * </description>
 * <param name="pInAddr" type="IN">Pointer to IP address description</param>
 * <param name="pszIPAddr" type="OUT">Pointer to get IP address string (must be at least 16 bytes long)</param>
 * <param name="iIPAddrSize" type="IN">Maximum length of pszIPAddr</param>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysSockInetNtoa',`(INADDR *pInAddr, char *pszIPAddr, int iIPAddrSize)')

/**
 * <description>
 *	Convert an IP address string into an IP address
 * </description>
 * <param name="pszIPAddr" type="IN">Pointer to get IP address string (must be at least 16 bytes long)</param>
 * <param name="pInAddr" type="OUT">Pointer to IP address description (in Ethernet byte order)</param>
 * <result>Error code:
 *	<ul>
 *		<li>ERR_PARAMETER: if pszIPAddress=NULL or pInAddr=NULL</li>
 *		<li>ERR_OK: IP-address could be converted
 *			IMPLEMENTATION NOTE:
 *			If pszIPAddress="255.255.255.255", the error code must be ERR_OK with *pInAddr=0xFFFFFFFF (SOCKET_INADDR_BROADCAST).</li>
 *		<li>ERR_FAILED: IP-address invalid or empty
 *			IMPLEMENTATION NOTE:
 *			If pszIPAddress="", the error code must be ERR_FAILED with *pInAddr=0xFFFFFFFF (SOCKET_INADDR_NONE).</li>
 *	</ul>
 * </result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysSockInetAddr',`(char *pszIPAddress, RTS_UI32 *pInAddr)')

/**
 * <description>
 *	Convert a host unsigned short value into the Ethernet byte order
 * </description>
 * <param name="usHost" type="IN">Host unsigned short value</param>
 * <result>Returns the converted unsigned short value</result>
 */
DEF_ITF_API(`unsigned short',`CDECL',`SysSockHtons',`(unsigned short usHost)')

/**
 * <description>
 *	Convert a host unsigned long value into the Ethernet byte order
 * </description>
 * <param name="usHost" type="IN">Host unsigned long value</param>
 * <result>Returns the converted unsigned long value</result>
 */
DEF_ITF_API(`RTS_UI32',`CDECL',`SysSockHtonl',`(RTS_UI32 ulHost)')

/**
 * <description>
 *	Convert a unsigned short value from Ethernet byte order into host format
 * </description>
 * <param name="usNet" type="IN">Ethernet unsigned short value</param>
 * <result>Returns the converted unsigned short value</result>
 */
DEF_ITF_API(`unsigned short',`CDECL',`SysSockNtohs',`(unsigned short usNet)')

/**
 * <description>
 *	Convert a unsigned long value from Ethernet byte order into host format
 * </description>
 * <param name="usNet" type="IN">Ethernet unsigned long value</param>
 * <result>Returns the converted unsigned long value</result>
 */
DEF_ITF_API(`RTS_UI32',`CDECL',`SysSockNtohl',`(RTS_UI32 ulNet)')

/**
 * <description>
 *	Listen on a TCP server socket for new connection
 * </description>
 * <param name="hSocket" type="IN">Handle to the socket</param>
 * <param name="iMaxConnections" type="IN">Maximum number of connections allowed</param>
 * <result>error code</result>
 */
DEF_HANDLEITF_API(`RTS_RESULT',`CDECL',`SysSockListen',`(RTS_HANDLE hSocket, int iMaxConnections)')

/**
 * <description>
 *	Accept the next incoming TCP connection. Returns the socket for the newly created
 *	connection or RTS_INVALID_HANDLE if failed.
 * </description>
 * <param name="hSocket" type="IN">Handle to the socket</param>
 * <param name="pSockAddr" type="OUT">Socket address of the client, who is connected</param>
 * <param name="piSockAddrSize" type="INOUT">Pointer to size of socket address structure</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <result>Handle to the new accepted socket</result>
 */
DEF_HANDLEITF_API_OWNCPP(`RTS_HANDLE',`CDECL',`SysSockAccept',`(RTS_HANDLE hSocket, SOCKADDRESS *pSockAddr, int *piSockAddrSize, RTS_RESULT *pResult)')

/**
 * <description>
 *	Set IP address of the specified Ethernet device. Is not available on all platforms!
 *  Use SysSockSetIpAddressAndNetMask() instead.
 * </description>
 * <param name="pszCard" type="IN">Name of the Ethernet card</param>
 * <param name="pszIPAddress" type="IN">IP address to set as string</param>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysSockSetIPAddress',`(char *pszCard, char *pszIPAddress)')

/**
 * <description>
 *	Connect as a client to a TCP server
 * </description>
 * <param name="hSocket" type="IN">Handle to the socket</param>
 * <param name="pSockAddr" type="IN">Socket address of the server to connect to</param>
 * <param name="iSockAddrSize" type="IN">Size of socket address structure</param>
 * <result>error code</result>
 */
DEF_HANDLEITF_API(`RTS_RESULT',`CDECL',`SysSockConnect',`(RTS_HANDLE hSocket, SOCKADDRESS *pSockAddr, int iSockAddrSize)')

/**
 * <description>
 *	Check a number of sockets for activity	
 * </description>
 * <param name="iWidth" type="IN">Number of sockets in the SOCKET_FD_SET structure, so SOCKET_FD_SETSIZE must be used here.</param>
 * <param name="fdRead" type="IN">Read socket</param>
 * <param name="fdWrite" type="IN">Write socket</param>
 * <param name="fdExcept" type="IN">Exception socket</param>
 * <param name="ptvTimeout" type="IN">Pointer to specify the timeout of the operation.
 *	ptvTimeout=NULL:	Infinite wait
 *	ptvTimeout->tv_sec=-1, ptvTimeout->tv_usec=-1:	Infinite wait
 *	ptvTimeout->tv_sec=0, ptvTimeout->tv_usec=0:	No wait</param>
 * <param name="pnReady" type="OUT">Number of sockets that are ready for IO</param>
 * <result>ERR_OK or ERR_SOCK_TIMEDOUT, if timeout expired</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysSockSelect',`(int iWidth, SOCKET_FD_SET *fdRead, SOCKET_FD_SET *fdWrite, SOCKET_FD_SET *fdExcept, SOCKET_TIMEVAL *ptvTimeout, int *pnReady)')

/**
 * <description>
 *	Shutdown a socket
 * </description>
 * <param name="hSocket" type="IN">Handle to the socket</param>
 * <param name="iHow" type="IN">Specified, which operations are no longer be allowed. See category shutdown flags</param>
 * <result>error code</result>
 */
DEF_HANDLEITF_API(`RTS_RESULT',`CDECL',`SysSockShutdown',`(RTS_HANDLE hSocket, int iHow)')

/**
 * <description>
 *	Io-control of a socket
 * </description>
 * <param name="hSocket" type="IN">Handle to the socket</param>
 * <param name="iCommand" type="IN">Io-control command</param>
 * <param name="piParameter" type="INOUT">Parameter value of the command</param>
 * <result>error code</result>
 */
DEF_HANDLEITF_API(`RTS_RESULT',`CDECL',`SysSockIoctl',`(RTS_HANDLE hSocket, int iCommand, int *piParameter)')

/* ------------ TCP specific ------------ */

/**
 * <description>
 *	Receive data from a TCP socket
 * </description>
 * <param name="hSocket" type="IN">Handle to the socket</param>
 * <param name="pbyBuffer" type="OUT">Buffer to read data from the socket</param>
 * <param name="iBufferSize" type="IN">Maximum length of the buffer</param>
 * <param name="iFlags" type="IN">The flags parameter can be used to influence the behavior of the 
 *	function beyond the options specified for the associated socket. The semantics of this function 
 *	are determined by the socket options and the flags parameter. The latter is constructed by using the
 *	bitwise OR operator with any of the SOCKET_MSG values. See category TCP flags.</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <result>Returns number of bytes received. 0 if failed.</result>
 */
DEF_HANDLEITF_API(`RTS_SSIZE',`CDECL',`SysSockRecv',`(RTS_HANDLE hSocket, char *pbyBuffer, RTS_SSIZE iBufferSize, int iFlags, RTS_RESULT *pResult)')

/**
 * <description>
 *	Sent data to a TCP socket
 * </description>
 * <param name="hSocket" type="IN">Handle to the socket</param>
 * <param name="pbyBuffer" type="IN">Buffer with data to sent</param>
 * <param name="iBufferSize" type="IN">Maximum length of the buffer</param>
 * <param name="iFlags" type="IN">The flags parameter can be used to influence the behavior of the 
 *	function beyond the options specified for the associated socket. The semantics of this function 
 *	are determined by the socket options and the flags parameter. The latter is constructed by using the
 *	bitwise OR operator with any of the SOCKET_MSG values.</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <result>Returns number of sent bytes. 0 if failed.</result>
 */
DEF_HANDLEITF_API(`RTS_SSIZE',`CDECL',`SysSockSend',`(RTS_HANDLE hSocket, char *pbyBuffer, RTS_SSIZE iBufferSize, int iFlags, RTS_RESULT *pResult)')

/* ------------ UDP specific ------------ */

/**
 * <description>
 *	Receive a message from a connectionless socket (UDP)
 * </description>
 * <param name="hSocket" type="IN">Handle to the socket</param>
 * <param name="pbyBuffer" type="OUT">Buffer to read data from the socket</param>
 * <param name="iBufferSize" type="IN">Maximum length of the buffer</param>
 * <param name="iFlags" type="IN">The flags parameter can be used to influence the behavior of the 
 *	function beyond the options specified for the associated socket. The semantics of this function 
 *	are determined by the socket options and the flags parameter. The latter is constructed by using the
 *	bitwise OR operator with any of the SOCKET_MSG values.</param>
 * <param name="pSockAddr" type="IN">Socket address and port to receive data from</param>
 * <param name="iSockAddrSize" type="IN">Size of socket address structure</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <result>Returns number of bytes received</result>
 */
DEF_HANDLEITF_API(`RTS_SSIZE',`CDECL',`SysSockRecvFrom',`(RTS_HANDLE hSocket, char *pbyBuffer, RTS_SSIZE iBufferSize, int iFlags, SOCKADDRESS *pSockAddr, int iSockAddrSize, RTS_RESULT *pResult)')

/**
 * <description>
 *	Send a message over a connectionless socket (UDP)
 * </description>
 * <param name="hSocket" type="IN">Handle to the socket</param>
 * <param name="pbyBuffer" type="IN">Buffer with send data</param>
 * <param name="iBufferSize" type="IN">Length of data to send. If iBufferSize is 0 ERR_PARAMETER is returned.</param>
 * <param name="iFlags" type="IN">The flags parameter can be used to influence the behavior of the 
 *	function beyond the options specified for the associated socket. The semantics of this function 
 *	are determined by the socket options and the flags parameter. The latter is constructed by using the
 *	bitwise OR operator with any of the SOCKET_MSG values.</param>
 * <param name="pSockAddr" type="IN">Socket address and port to sent data to</param>
 * <param name="iSockAddrSize" type="IN">Size of socket address structure</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <result>Returns number of bytes received</result>
 */
DEF_HANDLEITF_API(`RTS_SSIZE',`CDECL',`SysSockSendTo',`(RTS_HANDLE hSocket, char *pbyBuffer, RTS_SSIZE iBufferSize, int iFlags, SOCKADDRESS *pSockAddr, int iSockAddrSize, RTS_RESULT *pResult)')


/**
 * <description>
 *	Higher level function, to create a complete UDP socket
 * </description>
 * <param name="iSendPort" type="IN">Port number to send (host byte order)</param>
 * <param name="iRecvPort" type="IN">Port number to receive (host byte order)</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <result>Handle to the UDP socket</result>
 */
DEF_CREATEITF_API(`RTS_HANDLE',`CDECL',`SysSockCreateUdp',`(int iSendPort, int iRecvPort, RTS_RESULT *pResult)')

/**
 * <description>
 *	Close a UDP socket
 * </description>
 * <param name="hSocket" type="IN">Handle to the UDP socket. Must be opened with SysSockCreateUdp!</param>
 * <result>error code</result>
 */
DEF_HANDLEITF_API(`RTS_RESULT',`CDECL',`SysSockCloseUdp',`(RTS_HANDLE hSocket)')

/**
 * <description>
 *	Send a packet to a UDP socket
 * </description>
 * <param name="hSocket" type="IN">Handle to the UDP socket</param>
 * <param name="iPort" type="IN">Port number to send in host byte-order!</param>
 * <param name="pszDestAddress" type="IN">Destination IP address to send data to</param>
 * <param name="pbyData" type="IN">Pointer to data to send</param>
 * <param name="iDataSize" type="IN">Size of data to send. If iDataSize is 0 ERR_PARAMETER is returned.</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <result>Number of bytes sent</result>
 */
DEF_HANDLEITF_API(`RTS_SSIZE',`CDECL',`SysSockSendToUdp',`(RTS_HANDLE hSocket, int iPort, char *pszDestAddress, unsigned char *pbyData, RTS_SSIZE iDataSize, RTS_RESULT *pResult)')

/**
 * <description>
 *	Receive a packet from a UDP socket
 * </description>
 * <param name="hSocket" type="IN">Handle to the UDP socket</param>
 * <param name="pbyData" type="OUT">Pointer to data to receive</param>
 * <param name="iDataSize" type="IN">Size of data to receive</param>
 * <param name="pReply" type="OUT">Description of the client that has sent this packet. See category "Udp reply".</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <result>Number of bytes received</result>
 */
DEF_HANDLEITF_API(`RTS_SSIZE',`CDECL',`SysSockRecvFromUdp',`(RTS_HANDLE hSocket, unsigned char *pbyData, RTS_SSIZE iDataSize, UDP_REPLY *pReply, RTS_RESULT *pResult)')

/**
 * <description>
 *	Check actual received data on the UDP socket
 * </description>
 * <param name="hSocket" type="IN">Handle to the UDP socket</param>
 * <param name="iTimeout" type="IN">Timeout to wait for received data. -1=Infinite wait, 0=no wait</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <result>Number of bytes actual available in the socket</result>
 */
DEF_HANDLEITF_API(`RTS_SSIZE',`CDECL',`SysSockGetRecvSizeUdp',`(RTS_HANDLE hSocket, int iTimeout, RTS_RESULT *pResult)')

/**
 * <description>
 *	Get operating system handle of the UDP socket
 * </description>
 * <param name="hSocket" type="IN">Handle to the UDP socket</param>
 * <result>Operating system handle</result>
 */
DEF_HANDLEITF_API(`RTS_HANDLE',`CDECL',`SysSockGetOSHandle',`(RTS_HANDLE hSocket)')

/**
 * <description>
 *	Check the availability of the communication partner with a ping request
 * </description>
 * <param name="pszIPAddress" type="IN">IP address of the communication partner as string</param>
 * <param name="ulTimeout" type="IN">Timeout in milliseconds to wait until reply</param>
 * <param name="pulReplyTime" type="OUT">Pointer to get the reply time of the ping request in milliseconds or NULL</param>
 * <result>
 *   ERR_OK: Partner available, ERR_TIMEOUT: Partner could not be reached during the specified timeout.
 *   All other results: Ping could not be sent because of other errors, so we don't know, if the partner is available.
 * </result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysSockPing',`(char *pszIPAddress, RTS_UI32 ulTimeout, RTS_UI32 *pulReplyTime)')

/**
 * <description>
 *	Set subnet-mask of a specified IP address adapter. Is not available on all platforms!
 *  Use SysSockSetIpAddressAndNetMask() instead.
 * </description>
 * <param name="pszIPAddress" type="IN">IP address of the communication partner as string</param>
 * <param name="pszSubnetMask" type="IN">Subnet mask as string</param>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysSockSetSubnetMask',`(char *pszIPAddress, char *pszSubnetMask)')

/**
 * <description>
 *	Get subnet-mask of a specified IP address adapter
 * </description>
 * <param name="pszIPAddress" type="IN">IP address of the communication partner as string</param>
 * <param name="pszSubnetMask" type="OUT">Subnet mask as string</param>
 * <param name="iMaxSubnetMask" type="IN">Maximum length of the subnet mask string</param>
 * <result>error code</result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysSockGetSubnetMask',`(char *pszIPAddress, char *pszSubnetMask, int iMaxSubnetMask)')

/**
 * <description>
 *	Check if a socket is inside of a set.
 * </description>
 * <param name="hSocket" type="IN">Socket to check. Can be RTS_INVALID_HANDLE to check for an invalid filled set.</param>
 * <param name="pfs" type="IN">Socket Set</param>
 * <result>TRUE if the specified socket is inside the set, FALSE if not</result>
 */
DEF_HANDLEITF_API(`RTS_BOOL',`CDECL',`SysSockFdIsset',`(RTS_HANDLE hSocket, SOCKET_FD_SET *pfs)')

/**
 * <description>
 *	Add a socket to a socket set.
 * </description>
 * <param name="hSocket" type="IN">Socket to add.</param>
 * <param name="pfs" type="IN">Socket Set</param>
 * <result>error code</result>
 */
DEF_HANDLEITF_API(`RTS_RESULT',`CDECL',`SysSockFdInit',`(RTS_HANDLE hSocket, SOCKET_FD_SET *pfs)')

/**
 * <description>
 *	Clear a Socket set.
 * </description>
 * <param name="pfs" type="IN">Socket Set</param>
 */
DEF_ITF_API(`void',`CDECL',`SysSockFdZero',`(SOCKET_FD_SET *pfs)')

/**
 * <description>
 *	Get adapter information structure of the first network adapter.
 * </description>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <result>Information structure of first network adapter</result>
 */
DEF_ITF_API(`SOCK_ADAPTER_INFO*',`CDECL',`SysSockGetFirstAdapterInfo',`(RTS_RESULT *pResult)')

/**
 * <description>
 *	Get adapter information structure of the next network adapter.
 * </description>
 * <param name="pPrevAdapter" type="OUT">Pointer to adapter information structure of previous adapter.</param>
 * <param name="pResult" type="OUT">Pointer to error code</param>
 * <result>Information structure of current network adapter</result>
 */
DEF_ITF_API(`SOCK_ADAPTER_INFO*',`CDECL',`SysSockGetNextAdapterInfo',`(SOCK_ADAPTER_INFO *pPrevAdapter, RTS_RESULT *pResult)')

/**
 * <description>
 *	Set IP address and subnet mask of an adapter. 
 *  It depends on the device, whether the new IP address and subnet mask is reset during reboot or
 *  if it is retained. In general the caller should consider these as volatile. The combination 
 *  IP address = 0.0.0.0 and subnet mask = 0.0.0.0 can be used to remove the IP address from the adapter.
 *  After this there is no IP based communication possible anymore, until a new IP address is set.
 *  Replaces the functions SysSockSetIPAddress() and SysSockSetSubnetMask().
 * </description>
 * <param name="pwszAdapterName" type="IN">Adapter name provided by SysSockGetFirstAdapter() / SysSockGetNextAdapter()</param>
 * <param name="pIpAddr" type="IN">IP address to set in network byte order.</param>
 * <param name="pNetMask" type="IN">Subnet mask to set in network byte order.</param>
 * <result>Error code:
 *	<ul>
 *		<li>ERR_PARAMETER: At least one of the passed pointers is NULL.</li>
 *		<li>ERR_OPERATION_DENIED: Adapter is not in white list or the operation was denied by the event EVT_SysSocket_BeforeSetIpAndMask.</li>
 *		<li>ERR_NO_OBJECT: Adapter with the specified name does not exist.</li>
 *		<li>ERR_NO_CHANGE: Adapter have a fix (not changeable) or dynamic (DHCP) IP address.</li>
 *		<li>ERR_FAILED: IP address/subnet mask could not be set.</li>
 *		<li>ERR_OK: IP address/subnet mask was set successfully.</li>
 *	</ul>
 * </result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysSockSetIpAddressAndNetMask',`(RTS_WCHAR *pwszAdapterName, INADDR *pIpAddr, INADDR *pNetMask)')

/**
 * <description>
 *	Set default gateway address an adapter. 
 *  It depends on the device, whether the new gateway address is reset during reboot or
 *  if it is retained. In general the caller should consider this as volatile. The 
 *  gateway address = 0.0.0.0 can be used to remove the gateway address from the adapter. 
 *  After this there is not routing to other subnets possible.
 *
 *  Attention: The default gateway can only be changed if the adapter containing
 *   the current default gateway is white listed in the CODESYSControl.cfg. This function
 *   will not change the default gateway of any other adapter.
 * </description>
 * <param name="pwszAdapterName" type="IN">Adapter name provided by SysSockGetFirstAdapter() / SysSockGetNextAdapter()</param>
 * <param name="pGatewayAddr" type="IN">IP address of the gateway to set in network byte order.</param>
 * <result>Error code:
 *	<ul>
 *		<li>ERR_PARAMETER: At least one of the passed pointers is NULL.</li>
 *		<li>ERR_OPERATION_DENIED: Adapter is not in white list or the operation was denied by the event EVT_SysSocket_BeforeSetGateway.</li>
 *		<li>ERR_NO_OBJECT: Adapter with the specified name does not exist.</li>
 *		<li>ERR_NO_CHANGE: There is a default gateway set on an adapter that is not white listed.</li>
 *		<li>ERR_FAILED: Default gateway could not be set.</li>
 *		<li>ERR_OK: Default gateway was set successfully.</li>
 *	</ul>
 * </result>
 */
DEF_ITF_API(`RTS_RESULT',`CDECL',`SysSockSetDefaultGateway',`(RTS_WCHAR *pwszAdapterName, INADDR *pGatewayAddr)')

/**
 * <description>
 *	Returns the socket address of the peer to which a socket is connected.
 *  The SysSockGetPeerName function can be used only on a connected socket. 
 * </description>
 * <param name="hSocket" type="IN">Handle to the socket</param>
 * <param name="pSockAddr" type="OUT">Socket address of the peer</param>
 * <param name="piSockAddrSize" type="INOUT">Pointer to size of socket address structure</param>
 * <result>error code</result>
 */
DEF_HANDLEITF_API(`RTS_RESULT',`CDECL',`SysSockGetPeerName',`(RTS_HANDLE hSocket, SOCKADDRESS *pSockAddr, RTS_I32 *piSockAddrSize)')

/**
 * <description>
 *	Returns the socket address of the local socket.
 *  Usually this function is called to retrieve the local socket address on multi-homed hosts or to get 
 *  the local port number in client implementations. If the socket is neither connected nor locally bound to an address,
 *  the result of the function and the value stored in the object pointed to by pSockAddress is unspecified.
 * </description>
 * <param name="hSocket" type="IN">Handle to the socket</param>
 * <param name="pSockAddr" type="OUT">Socket address of the local socket</param>
 * <param name="piSockAddrSize" type="INOUT">Pointer to size of socket address structure</param>
 * <result>error code</result>
 */
DEF_HANDLEITF_API(`RTS_RESULT',`CDECL',`SysSockGetSockName',`(RTS_HANDLE hSocket, SOCKADDRESS *pSockAddr, RTS_I32 *piSockAddrSize)')

#ifdef __cplusplus
}
#endif
