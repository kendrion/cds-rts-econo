/**
 * <interfacename>CmpUserDB</interfacename>
 * <description> 
 *	<p>This interface provides the minimal set of functions that must be implemented to replace the default CODESYS user database. 
 *  The main part is the possibility to authenticate users with different protocols. There may be several components
 *	that implement this interface. A component which implements this interface has to register
 *	at the CmpUserMgr to be called during the login process.</p>
 *
 *	<p>Calls to AuthenticateUser grant or deny access of a user within the login process.</p>
 *	<p>IMPLEMENTATION NOTE: The implementation of AuthenticateUser affects the security of the login process itself. 
 *		Pay attention to the following aspects:
 *		1. The result of the Login process should not allow any hints if the user identifier or the credentials are wrong.
 *			Just return a binary result.
 *		2. The complete protocol must be done even if a user does not exist. Fill the protocol with random data if a user
 *			does not exist to prevent timing based side channel attacks. E.g. do not immediately return ERR_ACCESS_DENIED if a user does not exist.
 *	</p>
 * </description>
 *
 * <copyright>
 * Copyright (c) 2019 CODESYS Development GmbH. All rights reserved.
 * </copyright>
 */

SET_INTERFACE_NAME(`CmpUserDB')
REF_ITF(`CmpUserMgrItf.m4')


/**
 * <description>Authenticates a user. Depending the protocol implementation this function must be called several times to finish the login process. Pay attention to pass the same
 * data structure to all these calles.</description>
 * <param name="pLoginContext" type="INOUT">Context of the current login process.</param>
 * <param name="pUserProperty" type="OUT">The properites of the user.</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">The login process has finished without an error. Authentication successful.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_ACCESS_DENIED">The login process has finished without an error. Authentication not successful.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PENDING">The login process has not finished yet.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">pLoginContext was NULL, or the login type can not be handled by this implementation.</errorcode>
 */
DEF_CLASSITF_API(`RTS_RESULT',`CDECL',`UserDBAuthenticate',`(RTS_HANDLE hDatabase, char *pszUser, UserMgrCredentials *pCredentials, RTS_UI32 *pUserProperty)')


/**
 * <description>Authenticates a user. Depending the protocol implementation this function must be called several times to finish the login process. Pay attention to pass the same
 * data structure to all these calles.</description>
 * <param name="pLoginContext" type="INOUT">Context of the current login process.</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">The login process has finished without an error. Check pLoginContext->bAccessGranted of access is granted.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PENDING">The login process has not finished yet. Is equal to pLoginContext->bProtocolFinished</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">pLoginContext was NULL, or the login type can not be handled by this implementation.</errorcode>
 */
DEF_CLASSITF_API(`char*',`CDECL',`UserDBGetFirstUser',`(RTS_HANDLE hDatabase, RTS_HANDLE *hIterator, RTS_UI32 *pUserProperty, RTS_RESULT *pResult)')


/**
 * <description>Authenticates a user. Depending the protocol implementation this function must be called several times to finish the login process. Pay attention to pass the same
 * data structure to all these calles.</description>
 * <param name="pLoginContext" type="INOUT">Context of the current login process.</param>
 * <errorcode name="RTS_RESULT" type="ERR_OK">The login process has finished without an error. Check pLoginContext->bAccessGranted of access is granted.</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PENDING">The login process has not finished yet. Is equal to pLoginContext->bProtocolFinished</errorcode>
 * <errorcode name="RTS_RESULT" type="ERR_PARAMETER">pLoginContext was NULL, or the login type can not be handled by this implementation.</errorcode>
 */
DEF_CLASSITF_API(`char*',`CDECL',`UserDBGetNextUser',`(RTS_HANDLE hDatabase, RTS_HANDLE *hIterator, RTS_UI32 *pUserProperty, RTS_RESULT *pResult)')

