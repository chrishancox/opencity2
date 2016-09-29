/***************************************************************************
						conf.h    -  description
							-------------------
	begin                : august 1st, 2004
	copyright            : (C) 2004-2010 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: conf.h 450 2010-11-21 19:11:43Z neoneurone $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

#ifndef _OPENCITY_CONF_H_
#define _OPENCITY_CONF_H_ 1

#include "main.h"

#include <map>

using std::map;

// Contain the maximum length of each line in the .conf files.
#define OC_MAX_CONF_LINE			1024

// Contain the key-value pair separator string.
#define OC_CONF_KEY_VALUE_SEPARATOR	"="

// Contain the comment start character.
#define OC_CONF_COMMENT_START		'#'

//========================================================================
/** Manage the ".conf" file. The parser automatically trim out the spaces
	around the "=" sign. A ".conf" file is a text file with things
	like following:
\li                 bla = 1
\li                 foo = coco kiki
\li                 etc...
\n
\n
	Code sample:
\code
	Conf* pConf = new Conf();
	pConf->Open("opencity.conf");
	cout << "one is : '" << pConf->GetValue("one") << "'" << endl
	<< "two is : '" << pConf->GetValue("two") << "'" << endl
	<< "three is : '" << pConf->GetValue("three") << "'" << endl
	<< "moo is : '" << pConf->GetValue("moo") << "'" << endl
	<< "coco : '" << pConf->GetValue("coco") << "'" << endl;
	pConf->Close();
	delete pConf;
\endcode
*/
class Conf
{

public:
	Conf() { OPENCITY_DEBUG("ctor"); }

	~Conf() { OPENCITY_DEBUG("dtor"); }


//========================================================================
/** Open the .conf file specified by its filename then load its content.
\param fileName The name of the .conf file that you want to open
\return the error code
\sa main.h
*/
	const OPENCITY_ERR_CODE
	Open(
		const string& fileName );

//========================================================================
/** Close the previously opened .conf file and clear its content from
	memory.
*/
	void
	Close();


//========================================================================
/** Return the string which represents the value part of the (key-value)
	pair.
\param key The key of the element that you what to retrieve the value
\param defaultValue The default value
\return the value pointed by the given "key"
*/
	const string&
	GetValue(
		const string& key,
		const string& defaultValue = "");

//========================================================================
/** Empty value causes the method to return OC_ERR_INVALID and
	the rbool variable contains an undefied value.
	The following values are interpreted as false: 0, no, n, off.
	Anything other than space is interpreted as true
\param key The key of the element that you what to retrieve the value
\param rbool The reference to the boolean variable that holds the value
\param defaultValue The default value
\return the value pointed by the given "key"
*/
	const OPENCITY_ERR_CODE
	GetBool(
		const string& key,
		bool& rbool,
		const bool defaultValue = false );


//========================================================================
/** Convert the string specified by the key "key" to long int. This method
	uses the function "strtol()"
*/
	const OPENCITY_ERR_CODE
	GetLint(
		const string& key,
		OC_LINT& rlint,
		const OC_LINT defaultValue = 0 );


//========================================================================
/** Convert the string specified by the key "key" to float. This method
	uses the function "strtol()"
*/
	const OPENCITY_ERR_CODE
	GetFloat(
		const string& key,
		float& rfloat,
		const float defaultValue = 0 );


//========================================================================
/** Static right string trim function.
*/
	static char* const
	RTrim( char* const str );

/** Static left string trim function.
*/
	static char* const
	LTrim( char* const str );


private:

/* TOKILL, kept for future reference
//========================================================================
This is our hash function. In fact, it's just a wrapper
	for the standard hash<const char*>

	struct myHash : public std::unary_function< const string &, size_t >
	{
	public:
		size_t operator()( const string & x ) const
		{
			return stdHash( x.c_str() );
		}

	private:
		__gnu_cxx::hash<const char*> stdHash;
	};


	__gnu_cxx::hash_map<string, string, myHash> mapData;
*/

	map<string, string> _mapData;
}; // class

#endif
