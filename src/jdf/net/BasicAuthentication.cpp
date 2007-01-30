/*
 * The CIP4 Software License, Version 0.1
 *
 *
 * Copyright (c) 2001 The International Cooperation for the Integration of 
 * Processes in  Prepress, Press and Postpress (CIP4).  All rights 
 * reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer. 
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. The end-user documentation included with the redistribution,
 *    if any, must include the following acknowledgment:  
 *       "This product includes software developed by the
 *        The International Cooperation for the Integration of 
 *        Processes in  Prepress, Press and Postpress (www.cip4.org)"
 *    Alternately, this acknowledgment may appear in the software itself,
 *    if and wherever such third-party acknowledgments normally appear.
 *
 * 4. The names "CIP4" and "The International Cooperation for the Integration of 
 *    Processes in  Prepress, Press and Postpress" must
 *    not be used to endorse or promote products derived from this
 *    software without prior written permission. For written 
 *    permission, please contact info@cip4.org.
 *
 * 5. Products derived from this software may not be called "CIP4",
 *    nor may "CIP4" appear in their name, without prior written
 *    permission of the CIP4 organization
 *
 * Usage of this software in commercial products is subject to restrictions. For
 * details please consult info@cip4.org.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE INTERNATIONAL COOPERATION FOR
 * THE INTEGRATION OF PROCESSES IN PREPRESS, PRESS AND POSTPRESS OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * ====================================================================
 *
 * This software consists of voluntary contributions made by many
 * individuals on behalf of the The International Cooperation for the Integration 
 * of Processes in Prepress, Press and Postpress and was
 * originally based on software 
 * copyright (c) 1999-2001, Heidelberger Druckmaschinen AG 
 * copyright (c) 1999-2001, Agfa-Gevaert N.V. 
 *  
 * For more information on The International Cooperation for the 
 * Integration of Processes in  Prepress, Press and Postpress , please see
 * <http://www.cip4.org/>.
 *  
 * 
 */
/******************************************************************************
 *                     Copyright 1998 Agfa-Gevaert N.V.                       *
 *                           All rights reserved                              *
 *                                                                            *
 * The material contained herein may not be reproduced in whole or in part,   *
 *        without the prior written consent of Agfa-Gevaert N.V.              *
 *                                                                            *
 ******************************************************************************/

/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include "BasicAuthentication.h"

#include "PasswordAuthentication.h"

#include <jdf/io/BASE64Encoder.h>

#include <jdf/lang/ByteBuffer.h>
#include <jdf/lang/Janitor.h>


namespace JDF
{

/******************************************************************************
 *	Forward declarations
 ******************************************************************************/ 


/******************************************************************************
 *	Defines and constants
 ******************************************************************************/ 


/******************************************************************************
 *	Typedefs
 ******************************************************************************/ 


/******************************************************************************
 *	Classes
 ******************************************************************************/ 

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

BasicAuthentication::BasicAuthentication(bool isProxy, WString host, int port,
										 WString realm, PasswordAuthentication* pw) :
	AuthenticationInfo(isProxy? PROXY_AUTHENTICATION : SERVER_AUTHENTICATION, host, port, realm)
{
	WString userName = pw->getUserName() + JDFStrL(":");

	char* plain = userName.getBytes();
	int len = strlen(plain);
	ByteBuffer buf(plain,len,false); // buf becomes owner of plain
	
	// get password bytes
	WString& passwd = pw->getPassword();
	char* passwdBytes = new char[passwd.length()];
	ArrayJanitor<char> passwdBytesJanitor(passwdBytes);
	for (unsigned int i=0; i<passwd.length(); i++)
	    passwdBytes[i] = (char)passwd[i];

	buf.append(passwdBytes,passwd.length());
	
	BASE64Encoder enc;
	this->auth = WString(JDFStrL("Basic ")) + enc.encode((char*) buf.bytes(), buf.size());
}

BasicAuthentication::BasicAuthentication(bool isProxy,WString host, int port,
								 WString realm, WString auth) :
	AuthenticationInfo(isProxy? PROXY_AUTHENTICATION : SERVER_AUTHENTICATION, host, port, realm)
{
	this->auth = JDFStrL("Basic ") + auth;
}


BasicAuthentication::BasicAuthentication(bool isProxy, const URL& url, WString realm,
					PasswordAuthentication* pw) :
	AuthenticationInfo(isProxy? PROXY_AUTHENTICATION : SERVER_AUTHENTICATION, url, realm)
{
	WString userName = pw->getUserName() + JDFStrL(":");

	char* plain = userName.getBytes();
	int len = strlen(plain);
	ByteBuffer buf(plain,len,false); // buf becomes owner of plain
	
	// get password bytes
	WString& passwd = pw->getPassword();
	char* passwdBytes = new char[passwd.length()];
	ArrayJanitor<char> passwdBytesJanitor(passwdBytes);

	for (unsigned int i=0; i<passwd.length(); i++)
	    passwdBytes[i] = (char)passwd[i];

	buf.append(passwdBytes,passwd.length());
	passwd="";
	BASE64Encoder enc;
	this->auth = WString(JDFStrL("Basic ")) + enc.encode((char*) buf.bytes(), buf.size());
	
}

BasicAuthentication::BasicAuthentication(bool isProxy, const URL& url, WString realm,
										 WString auth):
	AuthenticationInfo(isProxy? PROXY_AUTHENTICATION : SERVER_AUTHENTICATION, url, realm)
{
	this->auth = "Basic " + auth;
}

WString BasicAuthentication::getHeaderName() 
{
	if (type == SERVER_AUTHENTICATION) 
	{
	    return JDFStrL("Authorization");
	} 
	else 
	{
	    return JDFStrL("Proxy-Authorization");
	}
}

WString BasicAuthentication::getHeaderValue() 
{
	return auth;
}

AuthenticationInfo* BasicAuthentication::copy()
{
	BasicAuthentication* a = new BasicAuthentication();
	a->auth = auth;
	a->type = type;
	a->host = host;
	a->port = port;
	a->realm = realm;
	a->path = path;
	return a;
}


} // namespace JDF
