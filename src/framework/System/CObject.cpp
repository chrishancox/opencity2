/***************************************************************************
                        CObject.cpp  -  description
							-------------------
	begin                : December 29th, 2008
	copyright            : (C) 2008 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: CObject.cpp 449 2010-05-20 18:46:59Z neoneurone $
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
#include "CNullValue.h"			// System::NullValue class
#include "CObject.h"			// System::Object class
#include "CString.h"			// System::String class
#include "CType.h"				// System::Type class


SPF_NAMESPACE_BEGIN(System)


   /*=====================================================================*/
Object::Object():
	mbIsNull(false)
{
}


Object::Object(const NullValue& null)
{
	mbIsNull = null.IsNull();
}


Object::~Object()
{
}


   /*=====================================================================*/
bool Object::IsNull() const
{
	return mbIsNull;
}


   /*=====================================================================*/
bool Object::Equals(const Object& obj) const
{
	return (this == &obj);
}


   /*=====================================================================*/
String Object::ToString() const
{
	return String("System::Object");
}


   /*=====================================================================*/
Type Object::GetType() const
{
	return typeid(*this);
}


   /*=====================================================================*/
Object& Object::operator=(const NullValue& null)
{
	mbIsNull = null.IsNull();
	return *this;
}


bool Object::operator==(const Object& obj) const
{
	return (this == &obj);
}


bool Object::operator!=(const Object& obj) const
{
	return (this != &obj);
}


   /*=====================================================================*/


SPF_NAMESPACE_END
