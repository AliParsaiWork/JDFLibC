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


///////////////////////////////////////////////////////////////////

 
#if !defined _JDFAutoColorIntent_H_
#define _JDFAutoColorIntent_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFIntentResource.h"
#include "jdf/wrapper/AutoJDF/JDFAutoEnumerationSpan.h"
namespace JDF{
class JDFColorPool;
class JDFSeparationList;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoColorIntent : public JDFIntentResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoColorIntent class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFColorIntent should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoColorIntent : public JDFIntentResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoColorIntent():JDFIntentResource(){};
/**
* copy ctor
*/
	inline JDFAutoColorIntent(const KElement & other):JDFIntentResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoColorIntent &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoColorIntent(){};
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


/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element Coatings
* 
* @return JDFStringSpan The element
*/
	JDFStringSpan GetCreateCoatings();

/**
* const get element Coatings
*@return  JDFStringSpan The element
*/
	JDFStringSpan GetCoatings()const;
/**
* Append element Coatings
 * 
*/
	JDFStringSpan AppendCoatings();

/** Get Element ColorStandard
* 
* @return JDFNameSpan The element
*/
	JDFNameSpan GetCreateColorStandard();

/**
* const get element ColorStandard
*@return  JDFNameSpan The element
*/
	JDFNameSpan GetColorStandard()const;
/**
* Append element ColorStandard
 * 
*/
	JDFNameSpan AppendColorStandard();

/** Get Element ColorICCStandard
* 
* @return JDFStringSpan The element
*/
	JDFStringSpan GetCreateColorICCStandard();

/**
* const get element ColorICCStandard
*@return  JDFStringSpan The element
*/
	JDFStringSpan GetColorICCStandard()const;
/**
* Append element ColorICCStandard
 * 
*/
	JDFStringSpan AppendColorICCStandard();

/** Get Element Coverage
* 
* @return JDFNumberSpan The element
*/
	JDFNumberSpan GetCreateCoverage();

/**
* const get element Coverage
*@return  JDFNumberSpan The element
*/
	JDFNumberSpan GetCoverage()const;
/**
* Append element Coverage
 * 
*/
	JDFNumberSpan AppendCoverage();

/** Get Element InkManufacturer
* 
* @return JDFNameSpan The element
*/
	JDFNameSpan GetCreateInkManufacturer();

/**
* const get element InkManufacturer
*@return  JDFNameSpan The element
*/
	JDFNameSpan GetInkManufacturer()const;
/**
* Append element InkManufacturer
 * 
*/
	JDFNameSpan AppendInkManufacturer();

/** Get Element ColorPool
* 
* @return JDFColorPool The element
*/
	JDFColorPool GetCreateColorPool();

/**
* const get element ColorPool
*@return  JDFColorPool The element
*/
	JDFColorPool GetColorPool()const;
/**
* Append element ColorPool
 * 
*/
	JDFColorPool AppendColorPool();
/**
* create inter-resource link to refTarget
* @param JDFColorPool& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefColorPool(JDFColorPool& refTarget);

/** Get Element ColorsUsed
* 
* @return JDFSeparationList The element
*/
	JDFSeparationList GetCreateColorsUsed();

/**
* const get element ColorsUsed
*@return  JDFSeparationList The element
*/
	JDFSeparationList GetColorsUsed()const;
/**
* Append element ColorsUsed
 * 
*/
	JDFSeparationList AppendColorsUsed();

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoColorIntent

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoColorIntent_H_
