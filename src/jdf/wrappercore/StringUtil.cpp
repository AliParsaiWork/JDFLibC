/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2009 The International Cooperation for the Integration of 
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
//EndCopyRight
// ////////////////////////////////////////////////////////////////////
//
//  Author: Dr. Rainer Prosi (JDFLib-J), ported to JDFLIB-C by Niels Boeger
// 
// Revision history:
// created before 07.Sep.2006
//
// StringUtil.cpp: implementation the StringUtil class. Contains various methods
//               for string manipulation and comparison.
//
// ////////////////////////////////////////////////////////////////////

#include "StringUtil.h"
#include "jdf/lang/WString.h"
#include "jdf/io/File.h"
#include "jdf/wrapper/JDFRange.h"
#include "jdf/wrapper/JDFNumTypeList.h"
#include "jdf/wrapper/JDFNumberRangeList.h"
#include "jdf/wrapper/JDFIntegerRangeList.h"
#include "jdf/wrapper/JDFXYPairRangeList.h"

namespace JDF{
	const WString StringUtil::m_URIEscape = L"%?@&=+$,[]";

	bool StringUtil::matchesAttribute(const WString& smallAtt, const WString& bigAtt, KElement::EnumAttributeType dataType)
	{
		if(dataType==KElement::AttributeType_Unknown || dataType == KElement::AttributeType_Any)
			return bigAtt.equals(smallAtt);

		if ((dataType==KElement::AttributeType_NMTOKENS) || 
			(dataType==KElement::AttributeType_enumerations) ||
			(dataType==KElement::AttributeType_IDREFS))
		{           
			// check for matching individual NMTOKEN
			vWString vSmall=smallAtt.Tokenize(WString::blank);
			for(int i=0;i<vSmall.size();i++)
			{
				if (!bigAtt.HasToken(vSmall.stringAt(i), WString::blank, 0))
				{
					return false;
				}
			}
			return true;
		}

		if (dataType==KElement::AttributeType_NumberRange)
		{
			try
			{
				NumberRange r(bigAtt);
				if (r.InRange(double(smallAtt)))
				{ 
					return true;
				}
			}
			catch(std::exception&)
			{
				//do nothing
			}
		}

		if (dataType==KElement::AttributeType_NumberRangeList)
		{
			try
			{
				JDFNumberRangeList r(bigAtt);
				if (r.InRange(double(smallAtt)))
				{
					return true;
				}
			}
			catch(std::exception&)
			{
				//do nothing
			}
		}

		if (dataType==KElement::AttributeType_IntegerList)
		{       
			try
			{
				JDFIntegerList rBig(bigAtt);
				if (rBig.GetString().HasToken(smallAtt))
				{
					return true;
				}
			}
			catch(std::exception&)
			{
				//do nothing
			}
		}

		if (dataType==KElement::AttributeType_IntegerRange)
		{       
			try
			{
				JDFIntegerRange rBig(bigAtt, WString::pINF);
				JDFIntegerRange rSmal(smallAtt, WString::pINF);
				if (rBig.IsPartOfRange(rSmal)) 
				{
					return true;
				}
			}
			catch(std::exception&)
			{
				//do nothing
			}
		}

		if (dataType==KElement::AttributeType_IntegerRangeList)
		{       
			try
			{
				JDFIntegerRangeList rBig(bigAtt, WString::pINF);
				JDFIntegerRangeList rSmal(smallAtt, WString::pINF);
				if (rBig.IsPartOfRange(rSmal)) 
				{
					return true;
				}
			}
			catch(std::exception&)
			{
				//do nothing
			}
		}

		if (dataType==KElement::AttributeType_XYPairRange)
		{
			try
			{
				JDFXYPair xypair(smallAtt);
				JDFXYPairRange r(bigAtt);
				if (r.InRange(xypair))
				{    
					return true; 
				} 
			}
			catch(std::exception&)
			{
				//do nothing
			}
		}

		if (dataType==KElement::AttributeType_XYPairRangeList)
		{
			try
			{
				JDFXYPair xypair(smallAtt);
				JDFXYPairRangeList r(bigAtt);
				if (r.InRange(xypair))
				{    
					return true; 
				} 
			}
			catch(std::exception&)
			{
				//do nothing
			}
		}

		return false;
	}

	WString StringUtil::formatInteger(int i)
	{
		WString s;

		if(i==WString::pINF)
		{
			s=WString::pINFstr;
		}
		else if(i==WString::nINF)
		{
			s=WString::nINFstr;
		}
		else
		{
			s=WString::valueOf(i);
		}
		return s;
	}

	WString StringUtil::formatDouble(double d)
	{
		WString s;
		if(d==WString::pDINF)
		{
			s=WString::pDINFstr;
		}
		else if(d==-WString::pDINF)
		{
			s=WString::nINFstr;
		}
		else
		{
			s=WString::valueOf(d);
			if(s.endsWith(".0"))
				s=s.substring(0,s.length()-2);

			if(s.indexOf("E")>=0)
			{
				char buf[20];
				s=sprintf(buf,"%10.10f", d);
				s=buf;
			}

			if(s.length()>8)
			{
				int posDot=s.indexOf(WString::dot);
				if(posDot>=0)
				{
					int l=s.length();
					if(l-posDot>8)
					{
						l=posDot+9;
						s=s.substring(0,l);
						if(s.endsWith("999"))
							return formatDouble(d+0.000000004);

						int n;
						for(n=l;n>posDot;n--)
						{
							if(!s.substring(n-1,n).equals("0"))
								break;
						}
						s=s.substring(0,n);
					}
				}                
			}
			if(s.endsWith("."))
			{
				s=s.leftStr(-1);                
			}
			if(s=="-0")
				s="0";
		}
		return s;
	}

	/**
	* replace a character in a given String
	* <p>
	* default: replaceChar(strWork, c, s, 0)
	* 
	* @param strIn String to work on
	* @param toReplace       character to replace
	* @param replaceBy       String to insert for c
	* @return the String with replaced characters
	*/
	WString StringUtil::replaceString(const WString& strIn, const WString& toReplace, const WString& replaceBy)
	{
		int indexOf = strIn.indexOf(toReplace);
		if( indexOf<0)
			return strIn;

		WString strWork=strIn;
		int len = toReplace.length();
		WString r;
		do
		{
			r+=strWork.substring(0,indexOf);
			r+=replaceBy;
			strWork=strWork.substring(indexOf+len);
			indexOf = strWork.indexOf(toReplace);
		}
		while(indexOf>=0);
		r+=strWork;

		return r;
	}

	/**
	* get a single token from a String
	* <p>
	* default: Token(strWork, index," \t\n")
	* 
	* @param strWork the String to work on
	* @param index   index of the token to return<br>
	*                if<0 return from end (e.g. -1 is the last token)
	* @param delim   the delimiter
	* @return the single token (<code>null</code> if no token found)
	*/
	WString StringUtil::token(const WString& strWork, int index, const WString &delim)
	{
		return strWork.Token(index,delim);
	}
	/**
	* Retrieve a file for a relative or absolute file url
	* 
	* @param urlString the file url to retrieve a file for
	* @return the file located at url
	*/
	WString StringUtil::urlToFile(WString urlString)
	{
		if (urlString.empty())
			return WString::emptyStr;

		if (urlString.toLowerCase().startsWith("file:"))
			urlString = urlString.substring(5); // remove "file:"

		File f(urlString);
		if (f.canRead())
			return urlString;

		if (File::separator().equals(L"\\")) // on windows
		{
			if (urlString.startsWith("///") && urlString.length() > 6 && urlString.charAt(4) == ':'&& urlString.charAt(5) == '/')
			{
				urlString = urlString.charAt(3) + urlString.substring(4);
			}
			else if (urlString.startsWith("/") && urlString.length() > 3 && urlString.charAt(2) == '/' && urlString.charAt(1) != '/')
			{
				urlString = urlString.charAt(1) + WString::colon + urlString.substring(2);
			}
			else if (urlString.startsWith("///"))
				urlString = urlString.substring(2);
		}

		urlString.SetRawBytes(urlString.GetUTF8Bytes()); // ensure that any non-utf8 gets encoded to utf-8
		urlString = urlString.UnEscape('%', 16, 2);
		urlString.SetUTF8Bytes(urlString.GetRawBytes());

		return urlString;
	}

	/**
	* Convert a File to a valid file URL or IRL<br>
	* note that some internal functions use network protocol and therefor performance may be non-optimal
	* 
	* @param f the File to parse,
	* @param bEscape128 if true, escape non -ascii chars (URI), if false, don't (IRI)
	* @return the URL string
	*/
	WString StringUtil::fileToUrl(const WString& f, bool bEscape128)
	{
		if (f.empty())
			return WString::emptyStr;
		WString s=f;
		if (File::separator().equals(L"\\"))
			s = s.replaceChar('\\', '/');
		if (bEscape128)
		{
			s.SetRawBytes(s.GetUTF8Bytes()); // ensure that any non-utf8 gets encoded to utf-8
			s=s.Escape(m_URIEscape, "%", 16, 2, 0x21, 127);
		}
		else
		{
			s=s.Escape(m_URIEscape, "%", 16, 2, 0x21, 0x7fffffff);
		}
		// if(s.length()>2 && s.charAt(1)==':' && File.separator.equals("\\"))
		// s=s.charAt(0)+s.substring(2);
		if (s.charAt(0) != '/')
			s = "///" + s;

		return "file:" + s;
	}
}; // namespace JDF
