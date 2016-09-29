/***************************************************************************
                        CBoolean.cpp  -  description
							-------------------
	begin                : January 4th, 2009
	copyright            : (C) 2009 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: CBoolean.cpp 447 2010-05-03 20:10:03Z neoneurone $
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
#include "CBoolean.h"			// System::Boolean class
#include "CNullValue.h"			// System::NullValue class
#include "CString.h"			// System::String class


SPF_NAMESPACE_BEGIN(System)


   /*=====================================================================*/
Boolean::Boolean():
	mbValue(false)
{}


Boolean::Boolean(bool value):
	mbValue(value)
{}


Boolean::~Boolean() {}


   /*=====================================================================*/
String Boolean::ToString() const
{
	return mbValue ? String("true") : String("false");
}


Boolean::operator bool() const
{
	return mbValue;
}


   /*=====================================================================*/
Boolean& Boolean::operator=(const bool& value)
{
	mbValue = value;
	return *this;
}


bool Boolean::operator==(const Boolean& value) const
{
	return (bool)(mbValue == value.mbValue);
}


bool Boolean::operator==(const Object& obj) const
{
	// FIXME: type checking
	Object& constlessObj = const_cast<Object&>(obj);
	const Boolean& booleanRef = dynamic_cast<Boolean&>(constlessObj);

	return (bool)(*this == booleanRef);
}


bool Boolean::operator!=(const Boolean& value) const
{
	return (bool)(mbValue != value.mbValue);
}


bool Boolean::operator!=(const Object& obj) const
{
	// FIXME: type checking
	Object& constlessObj = const_cast<Object&>(obj);
	const Boolean& booleanRef = dynamic_cast<Boolean&>(constlessObj);

	return (bool)(*this != booleanRef);
}


   /*=====================================================================*/
bool Boolean::operator==(const bool& value) const
{
	return (bool)(mbValue == value);
}


bool Boolean::operator!=(const bool& value) const
{
	return (bool)(mbValue != value);
}


   /*=====================================================================*/
Boolean& Boolean::operator=(const NullValue& null)
{
	mbIsNull = null.IsNull();
	return *this;
}


   /*=====================================================================*/


SPF_NAMESPACE_END
