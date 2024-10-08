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

 
#if !defined _JDFAutoPreviewGenerationParams_H_
#define _JDFAutoPreviewGenerationParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFImageSetterParams;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoPreviewGenerationParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoPreviewGenerationParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFPreviewGenerationParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoPreviewGenerationParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoPreviewGenerationParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoPreviewGenerationParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoPreviewGenerationParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoPreviewGenerationParams(){};
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
* Enumeration for attribute AspectRatio
*/

	enum EnumAspectRatio{AspectRatio_Unknown,AspectRatio_Ignore,AspectRatio_CenterMax,AspectRatio_CenterMin,AspectRatio_Crop,AspectRatio_Expand};
/**
* Enumeration for attribute PreviewFileType
*/

	enum EnumPreviewFileType{PreviewFileType_Unknown,PreviewFileType_PNG,PreviewFileType_CIP3Multiple,PreviewFileType_CIP3Single};
/**
* Enumeration for attribute PreviewUsage
*/

	enum EnumPreviewUsage{PreviewUsage_Unknown,PreviewUsage_Separation,PreviewUsage_SeparatedThumbNail,PreviewUsage_SeparationRaw,PreviewUsage_ThumbNail,PreviewUsage_Viewable};
/**
* Enumeration for attribute Compensation
*/

	enum EnumCompensation{Compensation_Unknown,Compensation_None,Compensation_Film,Compensation_Plate,Compensation_Press};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for AspectRatio
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& AspectRatioString();
/**
* Enumeration string for enum value
* @param EnumAspectRatio value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString AspectRatioString(EnumAspectRatio value);
/**
* Set attribute AspectRatio
* @param EnumAspectRatio value the value to set the attribute to
*/
	virtual void SetAspectRatio( EnumAspectRatio value);

/**
* Typesafe enumerated attribute AspectRatio; defaults to Ignore
* @return EnumAspectRatiothe enumeration value of the attribute
*/
	virtual EnumAspectRatio GetAspectRatio() const;

/**
* Typesafe attribute validation of AspectRatio
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidAspectRatio(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for PreviewFileType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& PreviewFileTypeString();
/**
* Enumeration string for enum value
* @param EnumPreviewFileType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString PreviewFileTypeString(EnumPreviewFileType value);
/**
* Set attribute PreviewFileType
* @param EnumPreviewFileType value the value to set the attribute to
*/
	virtual void SetPreviewFileType( EnumPreviewFileType value);

/**
* Typesafe enumerated attribute PreviewFileType; defaults to PNG
* @return EnumPreviewFileTypethe enumeration value of the attribute
*/
	virtual EnumPreviewFileType GetPreviewFileType() const;

/**
* Typesafe attribute validation of PreviewFileType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidPreviewFileType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for PreviewUsage
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& PreviewUsageString();
/**
* Enumeration string for enum value
* @param EnumPreviewUsage value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString PreviewUsageString(EnumPreviewUsage value);
/**
* Set attribute PreviewUsage
* @param EnumPreviewUsage value the value to set the attribute to
*/
	virtual void SetPreviewUsage( EnumPreviewUsage value);

/**
* Typesafe enumerated attribute PreviewUsage; defaults to Separation
* @return EnumPreviewUsagethe enumeration value of the attribute
*/
	virtual EnumPreviewUsage GetPreviewUsage() const;

/**
* Typesafe attribute validation of PreviewUsage
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidPreviewUsage(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Compensation
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& CompensationString();
/**
* Enumeration string for enum value
* @param EnumCompensation value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString CompensationString(EnumCompensation value);
/**
* Set attribute Compensation
* @param EnumCompensation value the value to set the attribute to
*/
	virtual void SetCompensation( EnumCompensation value);

/**
* Typesafe enumerated attribute Compensation
* @return EnumCompensationthe enumeration value of the attribute
*/
	virtual EnumCompensation GetCompensation() const;

/**
* Typesafe attribute validation of Compensation
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidCompensation(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Resolution
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetResolution(const JDFXYPair& value);
/**
* Get string attribute Resolution
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetResolution() const;
/**
* Typesafe attribute validation of Resolution
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidResolution(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Size
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetSize(const JDFXYPair& value);
/**
* Get string attribute Size
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetSize() const;
/**
* Typesafe attribute validation of Size
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSize(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element ImageSetterParams
* 
* @return JDFImageSetterParams The element
*/
	JDFImageSetterParams GetCreateImageSetterParams();

/**
* const get element ImageSetterParams
*@return  JDFImageSetterParams The element
*/
	JDFImageSetterParams GetImageSetterParams()const;
/**
* Append element ImageSetterParams
 * 
*/
	JDFImageSetterParams AppendImageSetterParams();
/**
* create inter-resource link to refTarget
* @param JDFImageSetterParams& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefImageSetterParams(JDFImageSetterParams& refTarget);

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoPreviewGenerationParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoPreviewGenerationParams_H_
