/*
*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2004 The International Cooperation for the Integration of 
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
//////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2001
//      ALL RIGHTS RESERVED 
//
//  Authors: Dr. Rainer Prosi, Elena Skobchenko
// 
// Revision history:
// created  28.01.2004
//
// JDFEnumerationState.cpp: implementation of the JDFEnumerationState 
//
//////////////////////////////////////////////////////////////////////

#include "JDFState.h"
#include "JDFEnumerationState.h"


using namespace std;
namespace JDF{
	
	
	//////////////////////////////////////////////////////////////////////
	
	JDFEnumerationState& JDFEnumerationState::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFEnumerationState: "+other.GetNodeName()); 
		return *this;
	};
	
	//////////////////////////////////////////////////////////////////////
		
	WString JDFEnumerationState::ValidNodeNames()const{
		return L"*:,EnumerationState";
	};
	//////////////////////////////////////////////////////////////////////

	WString JDFEnumerationState::OptionalElements()const{
		return JDFStateBase::OptionalElements()+L",ValueLoc";
	};
	//////////////////////////////////////////////////////////////////////

	vWString JDFEnumerationState::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFStateBase::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		
		nElem=NumChildElements(elm_ValueLoc);
		for(i=0;i<nElem;i++){
			JDFValueLoc child=GetElement(elm_ValueLoc,WString::emptyStr,i);
			if (!child.IsValid(level)) {
				vElem.push_back(elm_ValueLoc);
				if (++n>=nMax) 
					return vElem;
				break;
			};
		}
		return vElem;
	};
	
	//////////////////////////////////////////////////////////////////////
	WString JDFEnumerationState::OptionalAttributes()const{
		return JDFStateBase::OptionalAttributes()+L",AllowedValueList,PresentValueList";
	};
	
	//////////////////////////////////////////////////////////////////////

	vWString JDFEnumerationState::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFStateBase::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=0;
		if(!ValidAllowedValueList(level)) {
			vAtts.push_back(atr_AllowedValueList);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidPresentValueList(level)) {
			vAtts.push_back(atr_PresentValueList);
			if(++n>=nMax) 
				return vAtts;
		};
		return vAtts;
	};

	//////////////////////////////////////////////////////////////////////
	bool JDFEnumerationState::ValidAllowedValueList(EnumValidationLevel level) const {
		return ValidAttribute(atr_AllowedValueList,AttributeType_NMTOKENS,false);
	};

	//////////////////////////////////////////////////////////////////////
	bool JDFEnumerationState::ValidPresentValueList(EnumValidationLevel level) const {
		return ValidAttribute(atr_PresentValueList,AttributeType_NMTOKENS,false);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	bool JDFEnumerationState::FitsValue(const WString& value, EnumFitsValue testlist) const{
		
		if (FitsListType(value))
			return (FitsValueList(value,testlist));
		return false;
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFEnumerationState::FitsValueList(const WString& value, EnumFitsValue valuelist) const{
		
		vWString vs=value.Tokenize();
		
		vWString list;
		if (valuelist==FitsValue_Allowed) 
		{
			list = GetAllowedValueList();
		} else 	{
			list = GetPresentValueList();
		}
		if(list.empty())
			return true; // if AllowedValueList is not specified return true 

		if (GetListType()==ListType_CompleteList){
			return FitsCompleteList(vs,list);
		}
		else if (GetListType()==ListType_CompleteOrderedList){ 
			return FitsCompleteOrderedList(vs,list);
		}
		else if (GetListType()==ListType_ContainedList){
			return FitsContainedList(vs,list);
		}

		int v_size=vs.size();
		int l_size = list.size();
		
		for (int i=0; i<v_size; i++) // test every token, that 'value' consists of
		{
			bool bFound = false;
			for (int j=0; j<l_size; j++)
			{
				if (!vs[i].compare(list[j])) {
					bFound=true;  
					break;
				}
			}
			if (!bFound)
				return false; // no such value in the 'list'
		}
		return true;
	}
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	bool JDFEnumerationState::FitsListType(const WString& value) const {

		if (!value.isNMTOKENS()) 
			return false;
		
		EnumListType listtype=GetListType();

		switch (listtype) {
	
			case ListType_CompleteList:// if it is comlete list or not will be tested in FitsValueList->FitsCompleteList
			case ListType_CompleteOrderedList: // if it is comlete ordered list or not will be tested in FitsValueList->FitsCompleteOrderedList
			case ListType_ContainedList: // if it is contained list or not will be tested in FitsValueList->FitsContainedList
			case ListType_List:
			case ListType_Span:
			{
				return true;
			}
			case ListType_UniqueList:
			{
				return (IsUnique(value.Tokenize()));
			}
			case ListType_SingleValue:
			case ListType_Unknown: // default ListType = SingleValue
			{
				return value.isNMTOKEN();
			}
			case ListType_OrderedList:
			case ListType_UniqueOrderedList:
			case ListType_RangeList:
			case ListType_OrderedRangeList:
			case ListType_UniqueRangeList:
			case ListType_UniqueOrderedRangeList:
			default:
			{
				throw JDFException (L"JDFEnumerationState::FitsListType illegal ListType attribute"); 
			}
		}
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	bool JDFEnumerationState::FitsCompleteList(const vWString& value, const vWString& list) const{

		int v_size=value.size();
		int l_size=list.size();
		
		if (v_size!=l_size) {
			return false; 
		}

		if (!IsUnique(value)) {
			return false;
		}

		vWString valueList = value;
		
		bool bFound;
		for (int i=l_size-1; i>=0; i--)
		{
			bFound=false;
			for (int j=valueList.size()-1; j>=0; j--)
			{
				if (!list[i].compare(valueList[j]))
				{
					valueList.erase(valueList.begin()+j);
					bFound=true;
					break;
				}
			}
			if (bFound==false) {
				return false;
			}
		}
		return true;
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFEnumerationState::FitsCompleteOrderedList(const vWString& value, const vWString& list) const{

		int v_size=value.size();
		int l_size=list.size();
		
		if (v_size!=l_size) {
			return false; 
		}

		if (!IsUnique(value)) {
			return false;
		}
		for (int i=0; i<l_size; i++)
		{
			if ( list[i].compare(value[i]) ) {
				return false;
			}
		}
		return true;		
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFEnumerationState::FitsContainedList(const vWString& value, const vWString& list) const{

		int v_size=value.size();
		int l_size=list.size();
	
		for (int i=0; i<v_size; i++)
		{
			for (int j=0; j<l_size; j++)
			{
				if (!value[i].compare(list[j])) 
					return true;
			}
		}
		return false;
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFEnumerationState::IsUnique(const vWString& value) const{

		int size=value.size();
		for (int i=0; i<size; i++)
		{
			for (int j=0; j<size; j++)
			{
				if ((j!=i)&&(!value[i].compare(value[j]))) 
					return false;
			}
		}
		return true;
	}
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	/* ******************************************************
	// Attribute Getter / Setter
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	vWString JDFEnumerationState::GetAllowedValueList()const{
		return GetAttribute(atr_AllowedValueList);
	}
	//////////////////////////////////////////////////////////////////////
	void JDFEnumerationState::SetAllowedValueList(const vWString& vs){
		SetAttribute(atr_AllowedValueList,vs);
	}
	//////////////////////////////////////////////////////////////////////
	vWString JDFEnumerationState::GetPresentValueList()const{
		if(HasAttribute(atr_PresentValueList))
			return GetAttribute(atr_PresentValueList);
		return GetAllowedValueList();
	}
	//////////////////////////////////////////////////////////////////////
	void JDFEnumerationState::SetPresentValueList(const vWString& vs){
		SetAttribute(atr_PresentValueList,vs);
	}
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	/* ******************************************************
	// Element Getter / Setter
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	JDFValueLoc JDFEnumerationState::GetValueLoc(int iSkip)const{
		JDFValueLoc e=GetElement(elm_ValueLoc,WString::emptyStr,iSkip);
		return e;
	};
	
	/////////////////////////////////////////////////////////////////////

	JDFValueLoc JDFEnumerationState::AppendValueLoc(){
		JDFValueLoc e=AppendElement(elm_ValueLoc);
		e.init();
		return e;
	};
	
	
}