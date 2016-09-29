/***************************************************************************
                        CXmlLinkedNode.cpp  -  description
							-------------------
	begin                : December 29th, 2008
	copyright            : (C) 2008 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: CXmlLinkedNode.cpp 414 2009-01-18 15:04:29Z neoneurone $
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
#include "CXmlLinkedNode.h"


SPF_NAMESPACE_NESTED_BEGIN(System, Xml)


   /*=====================================================================*/
XmlLinkedNode::XmlLinkedNode() {}


XmlLinkedNode::XmlLinkedNode
(
	const String& prefix, const String& localName, const String& namespaceURI,
	XmlDocument& doc
) :
XmlNode( prefix, localName, namespaceURI, doc )
{
}


XmlLinkedNode::~XmlLinkedNode() {}


String XmlLinkedNode::ToString() const
{
	return String("System::Xml::XmlLinkedNode");
}


SPF_NAMESPACE_NESTED_END
