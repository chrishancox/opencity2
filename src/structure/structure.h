/***************************************************************************
						structure.h  -  description
							-------------------
	begin                : june 16th, 2003
	copyright            : (C) 2003-2007 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: structure.h 375 2008-10-28 14:47:15Z neoneurone $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

#ifndef _OPENCITY_STRUCTURE_H_
#define _OPENCITY_STRUCTURE_H_ 1

#include "main.h"
#include "persistence.h"


// Structure relative attributes
#define OC_STRUCTURE_X		0x00	// Unknown
#define OC_STRUCTURE_R		0x01
#define OC_STRUCTURE_C		0x02
#define OC_STRUCTURE_I		0x04
#define OC_STRUCTURE_W		0x08
#define OC_STRUCTURE_E		0x10
#define OC_STRUCTURE_G		0x20
#define OC_STRUCTURE_P		0x40
#define OC_STRUCTURE_MARK	0x80

// Do _not_ change the values below if you don't know what you are doing
#define OC_STRUCTURE_LEVEL_START	0
#define OC_STRUCTURE_LEVEL_MAX		99
#define OC_STRUCTURE_LEVEL_MIN		0
#define OC_STRUCTURE_LEVEL_RATIO	10


/** The base class for all stuctures including roads, rails, buildings, etc ...
*/
class Structure : public Persistence  {
public:
   //========================================================================
   //                              STATIC  METHODS
   //========================================================================
//========================================================================
/** Return the number of structures created so far
	\return The number of structures created
*/
	static const uint &
	GetNumber();

//========================================================================
/** Set the number of created structures
	\param rcuiNb Number of structures
*/
	static void
	SetNumber( const uint & rcuiNb );


	Structure(  );
	Structure( const OPENCITY_STRUCTURE_CODE enumStructCode );
	Structure(
		const OPENCITY_STRUCTURE_CODE enumStructCode,
		Structure* pMain
	);


	virtual ~Structure(  );


//========================================================================
/** Save the data to the specified fstream
	\note The pointer to the main structured is _not_ saved. It's up to the
user to remap the pointer to the main structured correctly.
	\param rfs A reference to a file stream which is ready for writing
	\see Persistence
*/
	void
	SaveTo( std::fstream& rfs );


//========================================================================
/** Load the data from the specified stream
	\note The pointer to the main structured is _not_ loaded. It's up to the
user to remap the pointer to the main structured correctly.
	\param rfs A reference to a file stream which is ready for reading
	\see Persistence
*/
	void
	LoadFrom( std::fstream& rfs );


//========================================================================
/** Set the properties of the structure to wegBit
\param wegBit The desired properties. You can combine them by using the OR
	operator.
*/
	void
	Set( const uint wegBit );

	void
	Unset( const uint wegBit );

	const bool
	IsSet( const uint wegBit ) const;


//========================================================================
/** Returns the current GRAPHIC_CODE of the structure
*/
	const OPENCITY_GRAPHIC_CODE
	GetGraphicCode() const;


//========================================================================
/** Returns the first base GRAPHIC_CODE of the structure depending on its
structure type
*/
	const OPENCITY_GRAPHIC_CODE
	GetBaseGraphicCode() const;


//========================================================================
/** Returns the GRAPHIC_CODE of the next level
*/
	virtual const OPENCITY_GRAPHIC_CODE
	GetNextLevelGraphicCode() const;


//========================================================================
/** Returns the GRAPHIC_CODE of the previous level
*/
	virtual const OPENCITY_GRAPHIC_CODE
	GetPreviousLevelGraphicCode() const;


//========================================================================
/** Returns the current STRUCTURE_CODE of the structure. This is
	different from the GRAPHIC_CODE. The structure code is the _type_ of
	the structure where as the graphic code defines the model which is
	displayed by the renderer.
*/
	const OPENCITY_STRUCTURE_CODE
	GetCode() const;


//========================================================================
/** Get the pointer to main structure. NULL if unavailable
*/
	Structure*
	GetMain() const;


	void
	SetMain( Structure* const pstruct );


	virtual const bool
	LevelUp();

	virtual const bool
	LevelDown();


	const uint
	GetLevel() const;

	void
	SetLevel( const uint uiLevel );


//========================================================================
/** The type of the structure is useful for un/serialization
*/
	const OPENCITY_STRUCTURE_TYPE
	GetType() const;


protected:
	OPENCITY_GRAPHIC_CODE	_eGC;			///< Graphic code
	OPENCITY_STRUCTURE_CODE	_eSC;			///< Structure code
	OPENCITY_STRUCTURE_TYPE _eType;			///< Structure type
	uint _uiStatus;
	uint _uiLevel;

/** Pointer of the main structure
	IF this is just a part of a bigger structure
	ELSE equal to NULL
*/
	Structure* _pstructureMain;


private:
/// The total of the structures created so far
	static uint uiNumberStructure;

};

#endif





























