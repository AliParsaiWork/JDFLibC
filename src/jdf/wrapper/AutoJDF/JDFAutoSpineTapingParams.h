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

 
#if !defined _JDFAutoSpineTapingParams_H_
#define _JDFAutoSpineTapingParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFGlueApplication;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoSpineTapingParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoSpineTapingParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFSpineTapingParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoSpineTapingParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoSpineTapingParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoSpineTapingParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoSpineTapingParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoSpineTapingParams(){};
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
 * Typesafe attribute validation of Class
* @return true if class is valid
*/
virtual bool ValidClass(EnumValidationLevel level) const;

/** 
 * Typesafe initialization
 * @return true if succcessful
*/
virtual bool init();

/**
* Enumeration for attribute StripMaterial
*/

	enum EnumStripMaterial{StripMaterial_Unknown,StripMaterial_Calico,StripMaterial_Cardboard,StripMaterial_CrepePaper,StripMaterial_Gauze,StripMaterial_Paper,StripMaterial_PaperlinedMules,StripMaterial_Tape};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute TopExcess
*@param double value: the value to set the attribute to
*/
	virtual void SetTopExcess(double value);
/**
* Get double attribute TopExcess
* @return double the vaue of the attribute ; defaults to 0.0
*/
	virtual double GetTopExcess() const;
/**
* Typesafe attribute validation of TopExcess
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTopExcess(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute HorizontalExcess
*@param double value: the value to set the attribute to
*/
	virtual void SetHorizontalExcess(double value);
/**
* Get double attribute HorizontalExcess
* @return double the vaue of the attribute 
*/
	virtual double GetHorizontalExcess() const;
/**
* Typesafe attribute validation of HorizontalExcess
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidHorizontalExcess(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute HorizontalExcessBack
*@param double value: the value to set the attribute to
*/
	virtual void SetHorizontalExcessBack(double value);
/**
* Get double attribute HorizontalExcessBack
* @return double the vaue of the attribute 
*/
	virtual double GetHorizontalExcessBack() const;
/**
* Typesafe attribute validation of HorizontalExcessBack
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidHorizontalExcessBack(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute StripBrand
*@param WString value: the value to set the attribute to
*/
	virtual void SetStripBrand(const WString& value);
/**
* Get string attribute StripBrand
* @return WString the vaue of the attribute 
*/
	virtual WString GetStripBrand() const;
/**
* Typesafe attribute validation of StripBrand
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidStripBrand(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute StripColor
* @param EnumNamedColor value the value to set the attribute to
*/
	virtual void SetStripColor( EnumNamedColor value);

/**
* Typesafe enumerated attribute StripColor
* @return EnumStripColorthe enumeration value of the attribute
*/
	virtual EnumNamedColor GetStripColor() const;

/**
* Typesafe attribute validation of StripColor
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidStripColor(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute StripColorDetails
*@param WString value: the value to set the attribute to
*/
	virtual void SetStripColorDetails(const WString& value);
/**
* Get string attribute StripColorDetails
* @return WString the vaue of the attribute 
*/
	virtual WString GetStripColorDetails() const;
/**
* Typesafe attribute validation of StripColorDetails
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidStripColorDetails(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute StripLength
*@param double value: the value to set the attribute to
*/
	virtual void SetStripLength(double value);
/**
* Get double attribute StripLength
* @return double the vaue of the attribute 
*/
	virtual double GetStripLength() const;
/**
* Typesafe attribute validation of StripLength
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidStripLength(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for StripMaterial
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& StripMaterialString();
/**
* Enumeration string for enum value
* @param EnumStripMaterial value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString StripMaterialString(EnumStripMaterial value);
/**
* Set attribute StripMaterial
* @param EnumStripMaterial value the value to set the attribute to
*/
	virtual void SetStripMaterial( EnumStripMaterial value);

/**
* Typesafe enumerated attribute StripMaterial
* @return EnumStripMaterialthe enumeration value of the attribute
*/
	virtual EnumStripMaterial GetStripMaterial() const;

/**
* Typesafe attribute validation of StripMaterial
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidStripMaterial(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element GlueApplication
* 
* @param int iSkip number of elements to skip
* @return JDFGlueApplication The element
*/
	JDFGlueApplication GetCreateGlueApplication(int iSkip=0);

/**
* const get element GlueApplication
* @param int iSkip number of elements to skip
* @return JDFGlueApplication The element
*/
	JDFGlueApplication GetGlueApplication(int iSkip=0)const;
/**
* Append element GlueApplication
 */
	JDFGlueApplication AppendGlueApplication();
/**
* create inter-resource link to refTarget
* @param JDFGlueApplication& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefGlueApplication(JDFGlueApplication& refTarget);

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoSpineTapingParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoSpineTapingParams_H_
