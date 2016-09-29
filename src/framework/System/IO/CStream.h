/***************************************************************************
                        CStream.h  -  description
							-------------------
	begin                : January 11th, 2009
	copyright            : (C) 2009 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: CStream.h 434 2010-02-09 22:44:28Z neoneurone $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

#ifndef _SPF_SYSTEM_IO_CSTREAM_H_
#define _SPF_SYSTEM_IO_CSTREAM_H_ 1

// Framework headers
#include "System/AMarshalByRefObject.h"			// System::MarshalByRefObject class

SPF_NAMESPACE_BEGIN(System)

// Forward System::String class declaration
class String;

SPF_NAMESPACE_BEGIN(IO)

/**
	Provides a generic view of a sequence of bytes.
*/
class Stream : public MarshalByRefObject
{
	public:
		Stream();
		virtual ~Stream();

		virtual String ToString() const;

}; // class System::IO::Stream

// namespace System::IO
SPF_NAMESPACE_END

// namespace System
SPF_NAMESPACE_END

#endif
