/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2002 The International Cooperation for the Integration of 
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

 
#if !defined _JDFImageReplacementParams_H_
#define _JDFImageReplacementParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "AutoJDF/JDFAutoImageReplacementParams.h"
namespace JDF{
/*
*********************************************************************
class JDFImageReplacementParams : public JDFAutoImageReplacementParams

*********************************************************************
*/
/**
* Typesafe resource wrapper class JDFImageReplacementParams 
*
* This file is hand edited and will not be regenerated
*/
class JDF_WRAPPERCORE_EXPORT JDFImageReplacementParams : public JDFAutoImageReplacementParams{
public:


// Constructors / Destructors  


/**
* null ctor
*/
	inline JDFImageReplacementParams():JDFAutoImageReplacementParams(){};
/**
* copy ctor
*/
	inline JDFImageReplacementParams(const KElement & other):JDFAutoImageReplacementParams(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFImageReplacementParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFImageReplacementParams(){};

	/**
	* typesafe validator
	*
	* @param EnumValidationLevel level: validation level
	* @param bIgnorePrivate: if true, do not worry about elements in other namespaces
	* @param int nMax: maximum size of the returned vector
	* @return vWString: a vector of invalid element names
	*/
	vWString GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const;

	//@{
	/**
	* Gets of 'this' an existing child FileSpec(SearchPath) element  
	*
	* @param int iSkip: number of FileSpec(SearchPath) to skip
	* @return JDFFileSpec: the matching SearchPath element
	*/
	JDFFileSpec GetSearchPath(int iSkip=0) const;

	/** 
	* Gets of 'this' child FileSpec(SearchPath) element, 
	* optionally creates it, if it doesn't exist.
	* 
	* @param int iSkip: number of FileSpec(SearchPath) to skip
	* @return JDFFileSpec: the matching SearchPath element
	*/
	JDFFileSpec GetCreateSearchPath(int iSkip=0);

	/**
	* Appends new FileSpec(SearchPath) element to the end of 'this'  
	*
	* @return JDFFileSpec: newly created child SearchPath element
	*/
	JDFFileSpec AppendSearchPath();
	//@}


}; // endJDFImageReplacementParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFImageReplacementParams_H_
