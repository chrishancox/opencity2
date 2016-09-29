/***************************************************************************
                        CControl.cpp  -  description
							-------------------
	begin                : December 31th, 2010
	copyright            : (C) 2010 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: CControl.cpp 459 2010-12-31 17:05:24Z neoneurone $
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
#include "CControl.h"			// System::Windows::Forms::Control class
#include "System/CString.h"		// System::String class


SPF_NAMESPACE_BEGIN(System)
SPF_NAMESPACE_NESTED_BEGIN(Windows, Forms)


   /*=====================================================================*/
Control::Control() {}


Control::~Control() {}


String Control::ToString() const
{
	return String("System::Windows::Forms::Control");
}


   /*=====================================================================*/


SPF_NAMESPACE_NESTED_END
SPF_NAMESPACE_END
