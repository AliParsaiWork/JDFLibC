/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2008 The International Cooperation for the Integration of 
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

 
#include "jdf/wrapper/AutoJDF/JDFAutoBoxToBoxDifference.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoBoxToBoxDifference : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoBoxToBoxDifference& JDFAutoBoxToBoxDifference::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoBoxToBoxDifference: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoBoxToBoxDifference::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoBoxToBoxDifference::ValidNodeNames()const{
	return L"*:,BoxToBoxDifference";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoBoxToBoxDifference::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",FromBox,ToBox");
};

/**
 typesafe validator
*/
	vWString JDFAutoBoxToBoxDifference::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidFromBox(level)) {
			vAtts.push_back(atr_FromBox);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidToBox(level)) {
			vAtts.push_back(atr_ToBox);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoBoxToBoxDifference::FromBoxString(){
		static const WString enums=WString(L"Unknown,ArtBox,BleedBox,CropBox,MarginsBox,MediaBox,SlugBox,TrimBox");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoBoxToBoxDifference::FromBoxString(EnumFromBox value){
		return FromBoxString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoBoxToBoxDifference::SetFromBox( EnumFromBox value){
	SetEnumAttribute(atr_FromBox,value,FromBoxString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoBoxToBoxDifference::EnumFromBox JDFAutoBoxToBoxDifference:: GetFromBox() const {
	return (EnumFromBox) GetEnumAttribute(atr_FromBox,FromBoxString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBoxToBoxDifference::ValidFromBox(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_FromBox,FromBoxString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoBoxToBoxDifference::ToBoxString(){
		static const WString enums=WString(L"Unknown,ArtBox,BleedBox,CropBox,MarginsBox,MediaBox,SlugBox,TrimBox");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoBoxToBoxDifference::ToBoxString(EnumToBox value){
		return ToBoxString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoBoxToBoxDifference::SetToBox( EnumToBox value){
	SetEnumAttribute(atr_ToBox,value,ToBoxString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoBoxToBoxDifference::EnumToBox JDFAutoBoxToBoxDifference:: GetToBox() const {
	return (EnumToBox) GetEnumAttribute(atr_ToBox,ToBoxString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBoxToBoxDifference::ValidToBox(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ToBox,ToBoxString(),false);
	};
}; // end namespace JDF
