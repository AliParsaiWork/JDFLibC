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

 
#include "jdf/wrapper/AutoJDF/JDFAutoResourceDefinitionParams.h"
#include "jdf/wrapper/JDFResourceParam.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoResourceDefinitionParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoResourceDefinitionParams& JDFAutoResourceDefinitionParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoResourceDefinitionParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoResourceDefinitionParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoResourceDefinitionParams::ValidNodeNames()const{
	return L"*:,ResourceDefinitionParams";
};

bool JDFAutoResourceDefinitionParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoResourceDefinitionParams::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Parameter);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoResourceDefinitionParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",DefaultPriority,DefaultID,DefaultJDF");
};

/**
 typesafe validator
*/
	vWString JDFAutoResourceDefinitionParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidDefaultPriority(level)) {
			vAtts.push_back(atr_DefaultPriority);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDefaultID(level)) {
			vAtts.push_back(atr_DefaultID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDefaultJDF(level)) {
			vAtts.push_back(atr_DefaultJDF);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoResourceDefinitionParams::DefaultPriorityString(){
		static const WString enums=WString(L"Unknown,Application,DefaultJDF");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoResourceDefinitionParams::DefaultPriorityString(EnumDefaultPriority value){
		return DefaultPriorityString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoResourceDefinitionParams::SetDefaultPriority( EnumDefaultPriority value){
	SetEnumAttribute(atr_DefaultPriority,value,DefaultPriorityString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoResourceDefinitionParams::EnumDefaultPriority JDFAutoResourceDefinitionParams:: GetDefaultPriority() const {
	return (EnumDefaultPriority) GetEnumAttribute(atr_DefaultPriority,DefaultPriorityString(),WString::emptyStr,DefaultPriority_DefaultJDF);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceDefinitionParams::ValidDefaultPriority(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_DefaultPriority,DefaultPriorityString(),false);
	};
/**
* Set attribute DefaultID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoResourceDefinitionParams::SetDefaultID(const WString& value){
	SetAttribute(atr_DefaultID,value);
};
/**
* Get string attribute DefaultID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoResourceDefinitionParams::GetDefaultID() const {
	return GetAttribute(atr_DefaultID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceDefinitionParams::ValidDefaultID(EnumValidationLevel level) const {
		return ValidAttribute(atr_DefaultID,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute DefaultJDF
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoResourceDefinitionParams::SetDefaultJDF(const WString& value){
	SetAttribute(atr_DefaultJDF,value);
};
/**
* Get string attribute DefaultJDF
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoResourceDefinitionParams::GetDefaultJDF() const {
	return GetAttribute(atr_DefaultJDF,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceDefinitionParams::ValidDefaultJDF(EnumValidationLevel level) const {
		return ValidAttribute(atr_DefaultJDF,AttributeType_URL,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFResourceParam JDFAutoResourceDefinitionParams::GetResourceParam(int iSkip)const{
	JDFResourceParam e=GetElement(elm_ResourceParam,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFResourceParam JDFAutoResourceDefinitionParams::GetCreateResourceParam(int iSkip){
	JDFResourceParam e=GetCreateElement(elm_ResourceParam,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFResourceParam JDFAutoResourceDefinitionParams::AppendResourceParam(){
	JDFResourceParam e=AppendElement(elm_ResourceParam);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoResourceDefinitionParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ResourceParam);

		for(i=0;i<nElem;i++){
			if (!GetResourceParam(i).IsValid(level)) {
				vElem.AppendUnique(elm_ResourceParam);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		return vElem;
	};


/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoResourceDefinitionParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",ResourceParam";
	};
}; // end namespace JDF
