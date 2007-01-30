/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2002 The International Cooperation for the Integration of 
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
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Authors: Dr. Rainer Prosi, Elena Skobchenko
// 
// Revision history:
// created  17.03.2004
//
// JDFEnumerationEvaluation.h: interface for the JDFEnumerationEvaluation class.
// defines the EnumerationEvaluation attributes and subelements
//
// ////////////////////////////////////////////////////////////////////

 
#if !defined _JDFEnumerationEvaluation_H_
#define _JDFEnumerationEvaluation_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFEvaluation.h"

namespace JDF{
/*
*********************************************************************
class JDFEnumerationEvaluation : public JDFEvaluation

*********************************************************************
*/
/**
* Typesafe resource wrapper class JDFEnumerationEvaluation 
*
* This file is hand edited and will not be regenerated
*/
class JDF_WRAPPERCORE_EXPORT JDFEnumerationEvaluation : public JDFEvaluation{
public:

/** *****************************
* Construction / Destruction
******************************************** */  

//@{
/**
* Empty constructor
	*/
	inline JDFEnumerationEvaluation():JDFEvaluation(){};
	
	/**
	* Copy constructor
	*/
	inline JDFEnumerationEvaluation(const KElement & other):JDFEvaluation(){
		*this=other;
	};
	
	/**
	* Copy equivalance operator
	*/
	JDFEnumerationEvaluation &operator =(const KElement& other);
	
	/**
	* Destructor
	*/
	virtual ~JDFEnumerationEvaluation(){};
	//@}

	/**
	* definition of optional attributes in the JDF namespace
	*
	* @return WString: list of optional attributes
	*/
	virtual WString OptionalAttributes()const;

	/**
	* typesafe validator
	*
	* @param EnumValidationLevel level: validation level
	* @param bool bIgnorePrivate: if true, do not worry about attributes in other namespaces
	* @param int nMax: maximum size of the returned vector
	* @return vWString: a vector of invalid attribute names
	*/
	virtual vWString GetInvalidAttributes(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999)const;

	/**
	* typesafe validator utility - list of valid node names for this class 
	*
	* @return WString: comma separated list of valid node names
	*/
	virtual WString ValidNodeNames()const;

	/**
	* Checks if the node is abstract, i.e. is not completely described
	* utility used by GetUnknownElements, GetUnknownAttributes
	*
	* @return bool: true, if the node is abstract
	*/
	virtual bool IsAbstract()const;

	/**
	* Tests, if the defined value matches testlists, specified for this Evaluation
	*
	* @param WString& value: value to test
	* @return bool: true, if 'value' matches testlists or if testlists are not specified
	*/
	bool FitsValue(const WString& value) const;

	
	/* ******************************************************
	// Attribute Getter / Setter
	****************************************************** */

	/**
	* Sets attribute ValueList
	*
	* @param vWString& value: the value to set the attribute to
	*/
	virtual void SetValueList(const vWString& value);

	/**
	* Gets string attribute ValueList
	*
	* @return vWString: the value of the attribute 
	*/
	virtual vWString GetValueList() const;

	/**
	* Typesafe validation of attribute ValueList
	*
	* @param EnumValidationLevel level: level of attribute validation 
	* @return bool: true if valid
	*/
	virtual bool ValidValueList(EnumValidationLevel level=ValidationLevel_Complete) const;


private:

	/**
	* Tests, if the defined 'value' matches BasicPreflightTest/@ListType attribute,
	* specified for this Evaluation
	*
	* @param WString& value: value to test
	* @return bool: true, if 'value' matches specified value of BasicPreflightTest/@ListType
	*/
	bool FitsListType(const WString& value) const;
	
	/**
	* Tests, if the defined 'value' matches ValueList, specified for this Evaluation
	*
	* @param WString& value: string of nmtokens to test
	* @return bool: true, if 'value' matches ValueList or if ValueList is not specified
	*/
	bool FitsValueList(const WString& value) const;

	/**
	* For the case, when BasicPreflightTest/@ListType=CompleteList, tests,
	* if the defined 'value' matches ValueList, specified for this Evaluation
	*
	* @param vWString& value: value to test
	* @param vWString& list: testlist - specified ValueList
	* @return bool: true, if 'value' matches testlist
	*/
	bool FitsCompleteList(const vWString& value, const vWString& list) const;

	/**
	* For the case, when BasicPreflightTest/@ListType=CompleteOrderedList,
	* tests, if the defined 'value' matches ValueList, specified for this Evaluation
	*
	* @param vWString& value: value to test
	* @param vWString& list: testlist - specified ValueList
	* @return bool: true, if 'value' matches testlist
	*/
	bool FitsCompleteOrderedList(const vWString& value, const vWString& list) const;

	/**
	* For the case, when BasicPreflightTest/@ListType=ContainedList,
	* tests, if the defined 'value' matches ValueList, specified for this Evaluation
	*
	* @param vWString& value: value to test
	* @param vWString& list: testlist - specified ValueList
	* @return bool: true, if 'value' matches testlist
	*/
	bool FitsContainedList(const vWString& value, const vWString& list) const;

	/**
	* Tests, if 'value' string has only unique tokens
	*
	* @param vWString& value: value to test
	* @return bool: true, if 'value' has only unique tokens
	*/
	bool IsUnique(const vWString& value) const;


}; // endJDFEnumerationEvaluation

// ******************************************************
}; // end namespace JDF
#endif //_JDFEnumerationEvaluation_H_
