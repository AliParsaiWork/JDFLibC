/*
 * The CIP4 Software License, Version 0.1
 *
 *
 * Copyright (c) 2001 The International Cooperation for the Integration of 
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

/******************************************************************************
 *                     Copyright 2001 Agfa-Gevaert N.V.                       *
 *                           All rights reserved                              *
 *                                                                            *
 * The material contained herein may not be reproduced in whole or in part,   *
 *        without the prior written consent of Agfa-Gevaert N.V.              *
 *                                                                            *
 ******************************************************************************/


/*******************************************************************************
 * 
 * Description:
 *
 *
 ******************************************************************************/

#ifndef I_JDF_REGISTERCLEANUP_H
#define I_JDF_REGISTERCLEANUP_H

/******************************************************************************
 *	Includes
 ******************************************************************************/ 


#include <jdf/lang/Synchronized.h>


namespace JDF
{	
	class Mutex;
	class RegisterCleanup;

/******************************************************************************
 *	Defines and constants
 ******************************************************************************/ 


// This is a mutex for exclusive use by this class
extern Mutex* gJDFCleanupListMutex;

// This is the head of a list of XMLRegisterCleanup objects that
// is used during XMLPlatformUtils::Terminate() to find objects to
// clean up
extern RegisterCleanup* gJDFCleanupList;

/******************************************************************************
 *	Classes
 ******************************************************************************/ 


// 
//  For internal use only.
//
//  This class is used by the platform utilities class to support 
//  reinitialisation of global/static data which is lazily created. 
//  Since that data is widely spread out the platform utilities
//  class cannot know about them directly. So, the code that creates such
//  objects creates an registers a cleanup for the object. The platform
//  termination call will iterate the list and delete the objects.
//
//  N.B. These objects need to be statically allocated.  I couldn't think
//  of a neat way of ensuring this - can anyone else?

class RegisterCleanup
{
public :
	// The cleanup function to be called on XMLPlatformUtils::Terminate()
	typedef void (*CleanupFn)();
	
	void doCleanup() {
		// When performing cleanup, we only do this once, but we can
		// cope if somehow we have been called twice.
		if (m_cleanupFn) 
            m_cleanupFn();

        // We need to remove "this" from the list
        // irregardless of the cleanup Function
        unregisterCleanup();
	}

	// This function is called during initialisation of static data to
	// register a function to be called on XMLPlatformUtils::Terminate.
	// It gives an object that uses static data an opportunity to reset
	// such data.
	void registerCleanup(CleanupFn cleanupFn) {
		// Store the cleanup function
		m_cleanupFn = cleanupFn;
		
		// Add this object to the list head, if it is not already 
		// present - which it shouldn't be.
		// This is done under a mutex to ensure thread safety.
		Synchronized sync(*gJDFCleanupListMutex);
		if (!m_nextCleanup && !m_prevCleanup) {
			m_nextCleanup = gJDFCleanupList;
			gJDFCleanupList = this;

			if (m_nextCleanup) 
				m_nextCleanup->m_prevCleanup = this;
		}
	}

	// This function can be called either from XMLPlatformUtils::Terminate
	// to state that the cleanup has been performed and should not be
	// performed again, or from code that you have written that determines
	// that cleanup is no longer necessary.
	void unregisterCleanup() {

		Synchronized sync(*gJDFCleanupListMutex);

        //
        // To protect against some compiler's (eg hp11) optimization
        // to change "this" as they update gJDFCleanupList
        //
        // refer to 
        // void PlatformUtils::Terminate()
        //       ... 
        //       while (gJDFCleanupList)
		//            gJDFCleanupList->doCleanup();
        //

        RegisterCleanup *tmpThis = (RegisterCleanup*) this;

        // Unlink this object from the cleanup list
		if (m_nextCleanup) m_nextCleanup->m_prevCleanup = m_prevCleanup;
		
		if (!m_prevCleanup) gJDFCleanupList = m_nextCleanup;
		else m_prevCleanup->m_nextCleanup = m_nextCleanup;

		// Reset the object to the default state
		tmpThis->resetCleanup();
	}

	// The default constructor sets a state that ensures that this object
	// will do nothing
	RegisterCleanup()
	{
		resetCleanup();
	}

private:

    //
    // unsupported ctor and operator
    //
	RegisterCleanup(const RegisterCleanup&)
	{}

	// This is the cleanup function to be called
	CleanupFn m_cleanupFn;

	// These are list pointers to the next/prev cleanup function to be called
	RegisterCleanup *m_nextCleanup, *m_prevCleanup;

	// This function reinitialises the object to the default state
	void resetCleanup() {
		m_nextCleanup = 0;
		m_prevCleanup = 0;
		m_cleanupFn = 0;
	}
};

} // namespace JDF

#endif /* I_JDF_REGISTERCLEANUP_H */
