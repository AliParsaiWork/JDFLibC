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

 
#include "jdf/wrapper/AutoJDF/JDFAutoTransferFunctionControl.h"
#include "jdf/wrapper/JDFTransferCurvePool.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoTransferFunctionControl : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoTransferFunctionControl& JDFAutoTransferFunctionControl::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoTransferFunctionControl: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoTransferFunctionControl::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoTransferFunctionControl::ValidNodeNames()const{
	return L"*:,TransferFunctionControl";
};

bool JDFAutoTransferFunctionControl::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoTransferFunctionControl::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Parameter);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoTransferFunctionControl::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",TransferFunctionSource";
};

/**
 typesafe validator
*/
	vWString JDFAutoTransferFunctionControl::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidTransferFunctionSource(level)) {
			vAtts.push_back(atr_TransferFunctionSource);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoTransferFunctionControl::TransferFunctionSourceString(){
		static const WString enums=WString(L"Unknown,Document,Device,Custom");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoTransferFunctionControl::TransferFunctionSourceString(EnumTransferFunctionSource value){
		return TransferFunctionSourceString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoTransferFunctionControl::SetTransferFunctionSource( EnumTransferFunctionSource value){
	SetEnumAttribute(atr_TransferFunctionSource,value,TransferFunctionSourceString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoTransferFunctionControl::EnumTransferFunctionSource JDFAutoTransferFunctionControl:: GetTransferFunctionSource() const {
	return (EnumTransferFunctionSource) GetEnumAttribute(atr_TransferFunctionSource,TransferFunctionSourceString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTransferFunctionControl::ValidTransferFunctionSource(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_TransferFunctionSource,TransferFunctionSourceString(),RequiredLevel(level));
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFTransferCurvePool JDFAutoTransferFunctionControl::GetTransferCurvePool()const{
	JDFTransferCurvePool e=GetElement(elm_TransferCurvePool);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTransferCurvePool JDFAutoTransferFunctionControl::GetCreateTransferCurvePool(){
	JDFTransferCurvePool e=GetCreateElement(elm_TransferCurvePool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTransferCurvePool JDFAutoTransferFunctionControl::AppendTransferCurvePool(){
	JDFTransferCurvePool e=AppendElementN(elm_TransferCurvePool,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoTransferFunctionControl::RefTransferCurvePool(JDFTransferCurvePool& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoTransferFunctionControl::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_TransferCurvePool);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_TransferCurvePool);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetTransferCurvePool().IsValid(level)) {
				vElem.AppendUnique(elm_TransferCurvePool);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoTransferFunctionControl::UniqueElements()const{
		return JDFResource::UniqueElements()+L",TransferCurvePool";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoTransferFunctionControl::OptionalElements()const{
		return JDFResource::OptionalElements()+L",TransferCurvePool";
	};
}; // end namespace JDF
