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

 
#if !defined _JDFAutoPricing_H_
#define _JDFAutoPricing_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFPayment;
class JDFPricing;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoPricing : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoPricing class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFPricing should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoPricing : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoPricing():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoPricing(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoPricing &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoPricing(){};
public:

/**
* typesafe validator utility
* @param EnumValidationLevel level validation level
* @param bool bIgnorePrivate ignore objects in foreign namespaces
* @param int nMax size of the returned vector
* @return vWString vector of invalid attribute names
*/
	virtual vWString GetInvalidAttributes(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999)const;

/**
* typesafe validator utility
* @param EnumValidationLevel level validation level
* @param bool bIgnorePrivate ignore objects in foreign namespaces
* @param int nMax size of the returned vector
* @return vWString vector of invalid element names
*/
	virtual vWString GetInvalidElements(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999) const;

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
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute AdditionalPrice
*@param double value: the value to set the attribute to
*/
	virtual void SetAdditionalPrice(double value);
/**
* Get double attribute AdditionalPrice
* @return double the vaue of the attribute 
*/
	virtual double GetAdditionalPrice() const;
/**
* Typesafe attribute validation of AdditionalPrice
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAdditionalPrice(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Currency
*@param WString value: the value to set the attribute to
*/
	virtual void SetCurrency(const WString& value);
/**
* Get string attribute Currency
* @return WString the vaue of the attribute 
*/
	virtual WString GetCurrency() const;
/**
* Typesafe attribute validation of Currency
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCurrency(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute HasPrice
*@param bool value: the value to set the attribute to
*/
	virtual void SetHasPrice(bool value);
/**
* Get bool attribute HasPrice
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetHasPrice() const;
/**
* Typesafe attribute validation of HasPrice
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidHasPrice(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Item
*@param WString value: the value to set the attribute to
*/
	virtual void SetItem(const WString& value);
/**
* Get string attribute Item
* @return WString the vaue of the attribute 
*/
	virtual WString GetItem() const;
/**
* Typesafe attribute validation of Item
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidItem(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Price
*@param double value: the value to set the attribute to
*/
	virtual void SetPrice(double value);
/**
* Get double attribute Price
* @return double the vaue of the attribute 
*/
	virtual double GetPrice() const;
/**
* Typesafe attribute validation of Price
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPrice(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element Payment
* 
* @param int iSkip number of elements to skip
* @return JDFPayment The element
*/
	JDFPayment GetCreatePayment(int iSkip=0);

/**
* const get element Payment
* @param int iSkip number of elements to skip
* @return JDFPayment The element
*/
	JDFPayment GetPayment(int iSkip=0)const;
/**
* Append element Payment
 */
	JDFPayment AppendPayment();

/** Get Element Pricing
* 
* @param int iSkip number of elements to skip
* @return JDFPricing The element
*/
	JDFPricing GetCreatePricing(int iSkip=0);

/**
* const get element Pricing
* @param int iSkip number of elements to skip
* @return JDFPricing The element
*/
	JDFPricing GetPricing(int iSkip=0)const;
/**
* Append element Pricing
 */
	JDFPricing AppendPricing();

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoPricing

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoPricing_H_
