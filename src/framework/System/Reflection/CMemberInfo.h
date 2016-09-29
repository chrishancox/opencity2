/***************************************************************************
                        CMemberInfo.h  -  description
							-------------------
	begin                : January 1st, 2009
	copyright            : (C) 2009 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: CMemberInfo.h 449 2010-05-20 18:46:59Z neoneurone $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

#ifndef _SPF_SYSTEM_REFLECTION_CMEMBERINFO_H_
#define _SPF_SYSTEM_REFLECTION_CMEMBERINFO_H_ 1

// Framework headers
#include "System/CObject.h"			// System::Object class
#include "System/CString.h"			// System::String class

SPF_NAMESPACE_NESTED_BEGIN(System, Reflection)


class MemberInfo : public Object
{
	public:
		MemberInfo();
		MemberInfo(const NullValue& null);
		MemberInfo(const String& name);
		virtual ~MemberInfo();

		/**
			Gets the name of the current member.
			\return A System::String containing the name of this member.
		*/
		const String& GetName() const;

		virtual String ToString() const;

	protected:
		String msName;
}; // class System::Reflection::MemberInfo

SPF_NAMESPACE_NESTED_END

#endif
