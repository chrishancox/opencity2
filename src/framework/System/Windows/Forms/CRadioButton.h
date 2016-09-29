/***************************************************************************
                        CRadioButton.h  -  description
							-------------------
	begin                : January 1st, 2011
	copyright            : (C) 2011 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: CRadioButton.h 460 2011-01-01 16:39:16Z neoneurone $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

#ifndef _SPF_SYSTEM_WINDOWS_FORMS_CRADIOBUTTON_H_
#define _SPF_SYSTEM_WINDOWS_FORMS_CRADIOBUTTON_H_ 1

// Framework headers
#include "AButtonBase.h"

SPF_NAMESPACE_BEGIN(System)
SPF_NAMESPACE_NESTED_BEGIN(Windows, Forms)

/**
	Represents a radio button control.
*/
class RadioButton : public ButtonBase
{
	public:
		RadioButton();
		virtual ~RadioButton();

		virtual String ToString() const;

}; // class System::Windows::Forms::RadioButton

// namespace Windows::Forms
SPF_NAMESPACE_NESTED_END

// namespace System
SPF_NAMESPACE_END

#endif
