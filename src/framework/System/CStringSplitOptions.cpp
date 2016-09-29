/***************************************************************************
                  CStringSplitOptions.cpp  -  description
							-------------------
	begin                : January 2nd, 2009
	copyright            : (C) 2009 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: CStringSplitOptions.cpp 403 2009-01-02 20:56:03Z neoneurone $
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
#include "CStringSplitOptions.h"		// System::StringSplitOptions class
#include "CString.h"					// System::String class


SPF_NAMESPACE_BEGIN(System)


   /*=====================================================================*/
StringSplitOptions::StringSplitOptions() {}


StringSplitOptions::~StringSplitOptions() {}


   /*=====================================================================*/
String StringSplitOptions::ToString() const
{
	return String("System::StringSplitOptions");
}


SPF_NAMESPACE_END
