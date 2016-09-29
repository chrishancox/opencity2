/***************************************************************************
                        CBoolean.h  -  description
							-------------------
	begin                : January 4th, 2009
	copyright            : (C) 2009 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: CBoolean.h 444 2010-04-26 21:18:59Z neoneurone $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

#ifndef _SPF_SYSTEM_CBOOLEAN_H_
#define _SPF_SYSTEM_CBOOLEAN_H_ 1

// Framework headers
#include "CObject.h"


SPF_NAMESPACE_BEGIN(System)

/**
	Represents a Boolean value.
*/
class Boolean : public Object
{
	public:
		Boolean();
		explicit Boolean(bool value);
		virtual ~Boolean();

		virtual String ToString() const;

		operator bool() const;

		Boolean& operator=(const bool& value);

		bool operator==(const Boolean& value) const;
		virtual bool operator==(const Object& obj) const;

		bool operator!=(const Boolean& value) const;
		virtual bool operator!=(const Object& obj) const;

		bool operator==(const bool& value) const;
		bool operator!=(const bool& value) const;

		Boolean& operator=(const NullValue& null);

	private:
		bool mbValue;
}; // class System::Boolean

SPF_NAMESPACE_END

#endif
