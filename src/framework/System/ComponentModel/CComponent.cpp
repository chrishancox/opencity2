/***************************************************************************
                        CComponent.cpp  -  description
							-------------------
	begin                : February 9th, 2010
	copyright            : (C) 2010 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: CComponent.cpp 434 2010-02-09 22:44:28Z neoneurone $
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
#include "CComponent.h"			// System::ComponentModel::Component class
#include "System/CString.h"		// System::String class


SPF_NAMESPACE_NESTED_BEGIN(System, ComponentModel)


   /*=====================================================================*/
Component::Component() {}


Component::~Component() {}


   /*=====================================================================*/
String Component::ToString() const
{
	return String("System::ComponentModel::Component");
}


SPF_NAMESPACE_NESTED_END
