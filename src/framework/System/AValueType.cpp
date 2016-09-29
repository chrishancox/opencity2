/***************************************************************************
                        AValueType.cpp  -  description
							-------------------
	begin                : January 2nd, 2009
	copyright            : (C) 2009 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: AValueType.cpp 431 2010-02-03 20:47:21Z neoneurone $
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
#include "AValueType.h"			// System::ValueType class
#include "CString.h"			// System::String class


SPF_NAMESPACE_BEGIN(System)


   /*=====================================================================*/
ValueType::ValueType() {}


ValueType::~ValueType() {}


   /*=====================================================================*/
String ValueType::ToString() const
{
	return String("System::ValueType");
}


SPF_NAMESPACE_END
