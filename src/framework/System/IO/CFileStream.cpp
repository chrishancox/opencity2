/***************************************************************************
                      CFileStream.cpp  -  description
							-------------------
	begin                : January 11th, 2009
	copyright            : (C) 2009 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: CFileStream.cpp 426 2009-11-22 17:42:38Z neoneurone $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

// Framework headers
#include "CFileStream.h"			// System::IO::FileStream class
#include "System/CString.h"			// System::String class


SPF_NAMESPACE_NESTED_BEGIN(System, IO)


   /*=====================================================================*/
FileStream::FileStream() {}


FileStream::~FileStream() {}


   /*=====================================================================*/
String FileStream::ToString() const
{
	return String("System::IO::FileStream");
}


SPF_NAMESPACE_NESTED_END
