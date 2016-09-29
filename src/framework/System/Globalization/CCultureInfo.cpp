/***************************************************************************
                        CCultureInfo.cpp  -  description
							-------------------
	begin                : April 28th, 2010
	copyright            : (C) 2010 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: CCultureInfo.cpp 450 2010-11-21 19:11:43Z neoneurone $
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
#include "CCultureInfo.h"		// System::Globalization::CultureInfo class
#include "System/CString.h"		// System::String class


SPF_NAMESPACE_NESTED_BEGIN(System, Globalization)


   /*=====================================================================*/
CultureInfo::CultureInfo(const int culture):
	miLCID(culture)
{
}


CultureInfo::~CultureInfo() {}


   /*=====================================================================*/
const int CultureInfo::GetLCID() const
{
	return miLCID;
}


   /*=====================================================================*/
String CultureInfo::ToString() const
{
	return String("System::Globalization::CultureInfo");
}


SPF_NAMESPACE_NESTED_END
