/***************************************************************************
                    AMarshalByRefObject.cpp  -  description
							-------------------
	begin                : January 11th, 2009
	copyright            : (C) 2009 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: AMarshalByRefObject.cpp 434 2010-02-09 22:44:28Z neoneurone $
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
#include "AMarshalByRefObject.h"	// System::MarshalByRefObject abstract class
#include "CString.h"				// System::String class


SPF_NAMESPACE_BEGIN(System)


   /*=====================================================================*/
MarshalByRefObject::MarshalByRefObject() {}


MarshalByRefObject::~MarshalByRefObject() {}


String MarshalByRefObject::ToString() const
{
	return String("System::MarshalByRefObject");
}


   /*=====================================================================*/


SPF_NAMESPACE_END
