/***************************************************************************
                  CNotImplementedException.h  -  description
							-------------------
	begin                : February 7th, 2010
	copyright            : (C) 2010 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: CNotImplementedException.h 435 2010-02-16 19:56:59Z neoneurone $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

#ifndef _SPF_SYSTEM_CNOTIMPLEMENTEDEXCEPTION_H_
#define _SPF_SYSTEM_CNOTIMPLEMENTEDEXCEPTION_H_ 1

// Framework headers
#include "CSystemException.h"			// System::SystemException class


SPF_NAMESPACE_BEGIN(System)


/**
	The exception that is thrown when a requested method or operation is not
implemented.
*/
class NotImplementedException : public SystemException
{
	public:
/**
	Initializes a new instance of the NotImplementedException class with
default properties.
*/
		NotImplementedException();
		NotImplementedException(const String& message);
		virtual ~NotImplementedException();

}; // class System::NotImplementedException

SPF_NAMESPACE_END

#endif
