/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2014 The International Cooperation for the Integration of 
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


///////////////////////////////////////////////////////////////////

 
#if !defined _JDFAutoCreditCard_H_
#define _JDFAutoCreditCard_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoCreditCard : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoCreditCard class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFCreditCard should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoCreditCard : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoCreditCard():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoCreditCard(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoCreditCard &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoCreditCard(){};
public:

/**
* typesafe validator utility
* @param EnumValidationLevel level validation level
* @param bool bIgnorePrivate ignore objects in foreign namespaces
* @param int nMax size of the returned vector
* @return vWString vector of invalid attribute names
*/
	virtual vWString GetInvalidAttributes(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999)const;

protected:
/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	virtual WString ValidNodeNames()const;
public:

/**
* Checks if the node is abstract, i.e. is not completely described
* utility used by GetUnknownElements, GetUnknownAttributes
* @return boolean: true, if the node is abstract
*/
	virtual bool IsAbstract()const;


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute Authorization
*@param WString value: the value to set the attribute to
*/
	virtual void SetAuthorization(const WString& value);
/**
* Get string attribute Authorization
* @return WString the vaue of the attribute 
*/
	virtual WString GetAuthorization() const;
/**
* Typesafe attribute validation of Authorization
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAuthorization(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute AuthorizationExpires
*@param JDFDate value: the value to set the attribute to
*/
	virtual void SetAuthorizationExpires(JDFDate value=JDFDate());
/**
* Get string attribute AuthorizationExpires
* @return JDFDate the vaue of the attribute 
*/
	virtual JDFDate GetAuthorizationExpires() const;
/**
* Typesafe attribute validation of AuthorizationExpires
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAuthorizationExpires(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Expires
*@param JDFDate value: the value to set the attribute to
*/
	virtual void SetExpires(JDFDate value=JDFDate());
/**
* Get string attribute Expires
* @return JDFDate the vaue of the attribute 
*/
	virtual JDFDate GetExpires() const;
/**
* Typesafe attribute validation of Expires
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidExpires(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Number
*@param WString value: the value to set the attribute to
*/
	virtual void SetNumber(const WString& value);
/**
* Get string attribute Number
* @return WString the vaue of the attribute 
*/
	virtual WString GetNumber() const;
/**
* Typesafe attribute validation of Number
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNumber(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Type
*@param WString value: the value to set the attribute to
*/
	virtual void SetType(const WString& value);
/**
* Get string attribute Type
* @return WString the vaue of the attribute 
*/
	virtual WString GetType() const;
/**
* Typesafe attribute validation of Type
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidType(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */

}; // endJDFAutoCreditCard

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoCreditCard_H_
