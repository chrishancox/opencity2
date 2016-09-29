/***************************************************************************
                        CXmlNodeList.h  -  description
							-------------------
	begin                : December 29th, 2008
	copyright            : (C) 2008 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: CXmlNodeList.h 426 2009-11-22 17:42:38Z neoneurone $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

#ifndef _SPF_XML_CXMLNODELIST_H_
#define _SPF_XML_CXMLNODELIST_H_ 1

// Framework headers
#include "System/CObject.h"
#include "CXmlNode.h"

// Standard C++ headers
#include <vector>

SPF_NAMESPACE_NESTED_BEGIN(System, Xml)

using namespace System;


class XmlNodeList : public Object
{
	public:
		XmlNodeList();
		virtual ~XmlNodeList();

		// Inherited from System::Object
		virtual String ToString() const;

	private:
		std::vector<XmlNode> mvNode;

}; // class System::Xml::XmlNodeList

// namespace System::Xml
SPF_NAMESPACE_NESTED_END

#endif
