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

 
#include "jdf/wrapper/AutoJDF/JDFAutoSeparationControlParams.h"
#include "jdf/wrapper/JDFAutomatedOverPrintParams.h"
#include "jdf/wrapper/JDFTransferFunctionControl.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoSeparationControlParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoSeparationControlParams& JDFAutoSeparationControlParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoSeparationControlParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoSeparationControlParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoSeparationControlParams::ValidNodeNames()const{
	return L"*:,SeparationControlParams";
};

bool JDFAutoSeparationControlParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoSeparationControlParams::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Parameter);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 typesafe validator
*/
	vWString JDFAutoSeparationControlParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		return vAtts;
	};


/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFAutomatedOverPrintParams JDFAutoSeparationControlParams::GetAutomatedOverPrintParams()const{
	JDFAutomatedOverPrintParams e=GetElement(elm_AutomatedOverPrintParams);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAutomatedOverPrintParams JDFAutoSeparationControlParams::GetCreateAutomatedOverPrintParams(){
	JDFAutomatedOverPrintParams e=GetCreateElement(elm_AutomatedOverPrintParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAutomatedOverPrintParams JDFAutoSeparationControlParams::AppendAutomatedOverPrintParams(){
	JDFAutomatedOverPrintParams e=AppendElementN(elm_AutomatedOverPrintParams,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTransferFunctionControl JDFAutoSeparationControlParams::GetTransferFunctionControl()const{
	JDFTransferFunctionControl e=GetElement(elm_TransferFunctionControl);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTransferFunctionControl JDFAutoSeparationControlParams::GetCreateTransferFunctionControl(){
	JDFTransferFunctionControl e=GetCreateElement(elm_TransferFunctionControl);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTransferFunctionControl JDFAutoSeparationControlParams::AppendTransferFunctionControl(){
	JDFTransferFunctionControl e=AppendElementN(elm_TransferFunctionControl,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoSeparationControlParams::RefTransferFunctionControl(JDFTransferFunctionControl& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoSeparationControlParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_AutomatedOverPrintParams);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_AutomatedOverPrintParams);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetAutomatedOverPrintParams().IsValid(level)) {
				vElem.AppendUnique(elm_AutomatedOverPrintParams);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_TransferFunctionControl);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_TransferFunctionControl);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetTransferFunctionControl().IsValid(level)) {
				vElem.AppendUnique(elm_TransferFunctionControl);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoSeparationControlParams::UniqueElements()const{
		return JDFResource::UniqueElements()+L",AutomatedOverPrintParams,TransferFunctionControl";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoSeparationControlParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",AutomatedOverPrintParams,TransferFunctionControl";
	};
}; // end namespace JDF
