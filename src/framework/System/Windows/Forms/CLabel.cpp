/***************************************************************************
                        CLabel.cpp  -  description
							-------------------
	begin                : January 1st, 2011
	copyright            : (C) 2011 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: CLabel.cpp 460 2011-01-01 16:39:16Z neoneurone $
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
#include "CLabel.h"				// System::Windows::Forms::Label class
#include "System/CString.h"		// System::String class


SPF_NAMESPACE_BEGIN(System)
SPF_NAMESPACE_NESTED_BEGIN(Windows, Forms)


   /*=====================================================================*/
Label::Label() {}


Label::~Label() {}


String Label::ToString() const
{
	return String("System::Windows::Forms::Label");
}


   /*=====================================================================*/


SPF_NAMESPACE_NESTED_END
SPF_NAMESPACE_END
