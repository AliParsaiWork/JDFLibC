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

 
#include "jdf/wrapper/AutoJDF/JDFAutoLayoutElementProductionParams.h"
#include "jdf/wrapper/JDFActionPool.h"
#include "jdf/wrapper/JDFFileSpec.h"
#include "jdf/wrapper/JDFLayoutElementPart.h"
#include "jdf/wrapper/JDFShapeDef.h"
#include "jdf/wrapper/JDFTestPool.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoLayoutElementProductionParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoLayoutElementProductionParams& JDFAutoLayoutElementProductionParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoLayoutElementProductionParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoLayoutElementProductionParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoLayoutElementProductionParams::ValidNodeNames()const{
	return L"*:,LayoutElementProductionParams";
};

bool JDFAutoLayoutElementProductionParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoLayoutElementProductionParams::init(){
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
	vWString JDFAutoLayoutElementProductionParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		return vAtts;
	};


/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFActionPool JDFAutoLayoutElementProductionParams::GetActionPool()const{
	JDFActionPool e=GetElement(elm_ActionPool);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFActionPool JDFAutoLayoutElementProductionParams::GetCreateActionPool(){
	JDFActionPool e=GetCreateElement(elm_ActionPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFActionPool JDFAutoLayoutElementProductionParams::AppendActionPool(){
	JDFActionPool e=AppendElementN(elm_ActionPool,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoLayoutElementProductionParams::GetFileSpec()const{
	JDFFileSpec e=GetElement(elm_FileSpec);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoLayoutElementProductionParams::GetCreateFileSpec(){
	JDFFileSpec e=GetCreateElement(elm_FileSpec);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoLayoutElementProductionParams::AppendFileSpec(){
	JDFFileSpec e=AppendElementN(elm_FileSpec,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoLayoutElementProductionParams::RefFileSpec(JDFFileSpec& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFLayoutElementPart JDFAutoLayoutElementProductionParams::GetLayoutElementPart(int iSkip)const{
	JDFLayoutElementPart e=GetElement(elm_LayoutElementPart,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLayoutElementPart JDFAutoLayoutElementProductionParams::GetCreateLayoutElementPart(int iSkip){
	JDFLayoutElementPart e=GetCreateElement(elm_LayoutElementPart,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLayoutElementPart JDFAutoLayoutElementProductionParams::AppendLayoutElementPart(){
	JDFLayoutElementPart e=AppendElement(elm_LayoutElementPart);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeDef JDFAutoLayoutElementProductionParams::GetShapeDef()const{
	JDFShapeDef e=GetElement(elm_ShapeDef);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeDef JDFAutoLayoutElementProductionParams::GetCreateShapeDef(){
	JDFShapeDef e=GetCreateElement(elm_ShapeDef);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeDef JDFAutoLayoutElementProductionParams::AppendShapeDef(){
	JDFShapeDef e=AppendElementN(elm_ShapeDef,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoLayoutElementProductionParams::RefShapeDef(JDFShapeDef& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFTestPool JDFAutoLayoutElementProductionParams::GetTestPool()const{
	JDFTestPool e=GetElement(elm_TestPool);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTestPool JDFAutoLayoutElementProductionParams::GetCreateTestPool(){
	JDFTestPool e=GetCreateElement(elm_TestPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTestPool JDFAutoLayoutElementProductionParams::AppendTestPool(){
	JDFTestPool e=AppendElementN(elm_TestPool,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoLayoutElementProductionParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ActionPool);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ActionPool);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetActionPool().IsValid(level)) {
				vElem.AppendUnique(elm_ActionPool);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_FileSpec);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_FileSpec);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetFileSpec().IsValid(level)) {
				vElem.AppendUnique(elm_FileSpec);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_LayoutElementPart);

		for(i=0;i<nElem;i++){
			if (!GetLayoutElementPart(i).IsValid(level)) {
				vElem.AppendUnique(elm_LayoutElementPart);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ShapeDef);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ShapeDef);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetShapeDef().IsValid(level)) {
				vElem.AppendUnique(elm_ShapeDef);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_TestPool);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_TestPool);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetTestPool().IsValid(level)) {
				vElem.AppendUnique(elm_TestPool);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoLayoutElementProductionParams::UniqueElements()const{
		return JDFResource::UniqueElements()+L",ActionPool,FileSpec,ShapeDef,TestPool";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoLayoutElementProductionParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",ActionPool,FileSpec,LayoutElementPart,ShapeDef,TestPool";
	};
}; // end namespace JDF
