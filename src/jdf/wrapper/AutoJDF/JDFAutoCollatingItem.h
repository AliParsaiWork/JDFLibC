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

 
#if !defined _JDFAutoCollatingItem_H_
#define _JDFAutoCollatingItem_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFComponent;
class JDFMedia;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoCollatingItem : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoCollatingItem class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFCollatingItem should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoCollatingItem : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoCollatingItem():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoCollatingItem(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoCollatingItem &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoCollatingItem(){};
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
* Enumeration for attribute TransformationContext
*/

	enum EnumTransformationContext{TransformationContext_Unknown,TransformationContext_StackItem,TransformationContext_Component,TransformationContext_CollateItem};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute Amount
*@param int value: the value to set the attribute to
*/
	virtual void SetAmount(int value);
/**
* Get integer attribute Amount
* @return int the vaue of the attribute ; defaults to 1
*/
	virtual int GetAmount() const;
/**
* Typesafe attribute validation of Amount
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAmount(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BundleDepth
*@param int value: the value to set the attribute to
*/
	virtual void SetBundleDepth(int value);
/**
* Get integer attribute BundleDepth
* @return int the vaue of the attribute 
*/
	virtual int GetBundleDepth() const;
/**
* Typesafe attribute validation of BundleDepth
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBundleDepth(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Orientation
* @param EnumOrientation value the value to set the attribute to
*/
	virtual void SetOrientation( EnumOrientation value);

/**
* Typesafe enumerated attribute Orientation
* @return EnumOrientationthe enumeration value of the attribute
*/
	virtual EnumOrientation GetOrientation() const;

/**
* Typesafe attribute validation of Orientation
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidOrientation(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Transformation
*@param JDFMatrix value: the value to set the attribute to
*/
	virtual void SetTransformation(const JDFMatrix& value);
/**
* Get string attribute Transformation
* @return JDFMatrix the vaue of the attribute 
*/
	virtual JDFMatrix GetTransformation() const;
/**
* Typesafe attribute validation of Transformation
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTransformation(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for TransformationContext
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& TransformationContextString();
/**
* Enumeration string for enum value
* @param EnumTransformationContext value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString TransformationContextString(EnumTransformationContext value);
/**
* Set attribute TransformationContext
* @param EnumTransformationContext value the value to set the attribute to
*/
	virtual void SetTransformationContext( EnumTransformationContext value);

/**
* Typesafe enumerated attribute TransformationContext; defaults to StackItem
* @return EnumTransformationContextthe enumeration value of the attribute
*/
	virtual EnumTransformationContext GetTransformationContext() const;

/**
* Typesafe attribute validation of TransformationContext
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidTransformationContext(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element Component
* 
* @param int iSkip number of elements to skip
* @return JDFComponent The element
*/
	JDFComponent GetCreateComponent(int iSkip=0);

/**
* const get element Component
* @param int iSkip number of elements to skip
* @return JDFComponent The element
*/
	JDFComponent GetComponent(int iSkip=0)const;
/**
* Append element Component
 */
	JDFComponent AppendComponent();
/**
* create inter-resource link to refTarget
* @param JDFComponent& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefComponent(JDFComponent& refTarget);

/** Get Element Media
* 
* @param int iSkip number of elements to skip
* @return JDFMedia The element
*/
	JDFMedia GetCreateMedia(int iSkip=0);

/**
* const get element Media
* @param int iSkip number of elements to skip
* @return JDFMedia The element
*/
	JDFMedia GetMedia(int iSkip=0)const;
/**
* Append element Media
 */
	JDFMedia AppendMedia();
/**
* create inter-resource link to refTarget
* @param JDFMedia& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefMedia(JDFMedia& refTarget);

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoCollatingItem

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoCollatingItem_H_
