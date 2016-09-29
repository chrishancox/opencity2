/***************************************************************************
                        CXmlNode.cpp  -  description
							-------------------
	begin                : December 29th, 2008
	copyright            : (C) 2008 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: CXmlNode.cpp 420 2009-09-13 16:34:19Z neoneurone $
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
#include "CXmlNode.h"


SPF_NAMESPACE_NESTED_BEGIN(System, Xml)


   /*=====================================================================*/
XmlNode::XmlNode() {}


XmlNode::XmlNode
(
	const String& prefix, const String& localName, const String& namespaceURI,
	XmlDocument& doc
) :
msPrefix( prefix ),
msLocalName( localName ),
msNamespaceURI( namespaceURI ),
poOwnerDocument( &doc )
{
}


XmlNode::~XmlNode() {}


   /*=====================================================================*/
const String& XmlNode::GetLocalName() const
{
	return msLocalName;
}


String XmlNode::GetName() const
{
	return (msPrefix.GetLength() > 0) ? msPrefix + ":" + msLocalName : msLocalName ;
}


const String& XmlNode::GetNamespaceURI() const
{
	return msNamespaceURI;
}


const String XmlNode::GetOuterXml() const
{
	return String::Empty;
}


const XmlDocument& XmlNode::GetOwnerDocument() const
{
	return *poOwnerDocument;
}


const String& XmlNode::GetPrefix() const
{
	return msPrefix;
}


void XmlNode::SetPrefix(const String& value)
{
	msPrefix = value;
}


   /*=====================================================================*/
String XmlNode::ToString() const
{
	return String("System::Xml::XmlNode");
}


SPF_NAMESPACE_NESTED_END
