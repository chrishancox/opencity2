/***************************************************************************
						structure.cpp  -  description
							-------------------
	begin                : june 16th, 2003
	copyright            : (C) 2003-2007 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: structure.cpp 462 2011-07-03 15:49:40Z neoneurone $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

// Useful enumerations
#include "opencity_direction.h"
#include "opencity_structure_type.h"

// OpenCity header
#include "structure.h"

// Global settings
#include "globalvar.h"
extern GlobalVar gVars;


uint Structure::uiNumberStructure = 0;		///< Number of structures created so far


   /*======================================================================*/
const uint &
Structure::GetNumber()
{
	return Structure::uiNumberStructure;
}


   /*======================================================================*/
void
Structure::SetNumber( const uint & rcuiNb )
{
	Structure::uiNumberStructure = rcuiNb;
}


   /*======================================================================*/
Structure::Structure():
_eGC( OC_EMPTY ),
_eSC( OC_STRUCTURE_UNDEFINED ),
_eType( OC_TYPE_UNDEFINED ),
_uiStatus( 0 ),
_uiLevel( OC_STRUCTURE_LEVEL_START ),
_pstructureMain( NULL )
{
	OPENCITY_DEBUG( "ctor 0" );
	uiNumberStructure++;
}


   /*======================================================================*/
Structure::Structure
(
	const OPENCITY_STRUCTURE_CODE enumStructCode
):
_eGC( OC_EMPTY ),
_eSC( enumStructCode ),
_uiStatus( 0 ),
_uiLevel( OC_STRUCTURE_LEVEL_START ),
_pstructureMain( NULL )
{
	OPENCITY_DEBUG( "ctor 1" );

	_eType = gVars.gpPropertyMgr->GetST( enumStructCode );
	uiNumberStructure++;
}


   /*======================================================================*/
Structure::Structure
(
	const OPENCITY_STRUCTURE_CODE enumStructCode,
	Structure* pMain
):
_eGC( OC_EMPTY ),
_eSC( enumStructCode ),
_uiStatus( 0 ),
_uiLevel( OC_STRUCTURE_LEVEL_START ),
_pstructureMain( pMain )
{
	OPENCITY_DEBUG( "ctor 2" );

	_eType = gVars.gpPropertyMgr->GetST( enumStructCode );
	uiNumberStructure++;
}


   /*======================================================================*/
 Structure::~Structure(  )
{
	OPENCITY_DEBUG( "Structure dtor" );

	uiNumberStructure--;
}


   /*=====================================================================*/
void
Structure::SaveTo( std::fstream& rfs )
{
	OPENCITY_DEBUG( __PRETTY_FUNCTION__ << "saving" );

	rfs << _eGC << std::ends;
	rfs << _eSC << std::ends;
	rfs << _eType << std::ends;
	rfs << _uiStatus << std::ends;
	rfs << _uiLevel << std::ends;
}


   /*=====================================================================*/
void
Structure::LoadFrom( std::fstream& rfs )
{
	OPENCITY_DEBUG( __PRETTY_FUNCTION__ << "loading" );
	uint t = 0;

	rfs >> t; rfs.ignore(); _eGC = (OPENCITY_GRAPHIC_CODE)t;
	rfs >> t; rfs.ignore(); _eSC = (OPENCITY_STRUCTURE_CODE)t;
	rfs >> t; rfs.ignore(); _eType= (OPENCITY_STRUCTURE_TYPE)t;
	rfs >> _uiStatus; rfs.ignore();
	rfs >> _uiLevel; rfs.ignore();
}


   /*======================================================================*/
void
Structure::Set(
	const uint wegBit )
{
	_uiStatus |= wegBit;
}


   /*======================================================================*/
void
Structure::Unset(
	const uint wegBit )
{
	_uiStatus &= ~wegBit;
}


   /*======================================================================*/
const bool
Structure::IsSet(
	const uint wegBit ) const
{
	if ((_uiStatus & wegBit) == wegBit)
		return true;
	else
		return false;
}


   /*======================================================================*/
const OPENCITY_GRAPHIC_CODE
Structure::GetGraphicCode() const
{
	return _eGC;
}


   /*======================================================================*/
const OPENCITY_GRAPHIC_CODE
Structure::GetBaseGraphicCode() const
{
	OPENCITY_GRAPHIC_CODE tempGC = OC_EMPTY;

	switch (_eSC) {
		case OC_STRUCTURE_RES:
			tempGC = OC_RES_ZONE0;
			break;

		case OC_STRUCTURE_COM:
			tempGC = OC_COM_ZONE0;
			break;

		case OC_STRUCTURE_IND:
			tempGC = OC_IND_ZONE0;
			break;

		default:
			OPENCITY_DEBUG("Unrecognized graphic code enumeration.");
			assert(0);
			break;
	}

	return tempGC;
}


   /*======================================================================*/
const OPENCITY_GRAPHIC_CODE
Structure::GetNextLevelGraphicCode() const
{
//	OPENCITY_DEBUG("WARNING: Inside Structure");
// WARNING: we don't have such information in a general structure
	return _eGC;
}


   /*======================================================================*/
const OPENCITY_GRAPHIC_CODE
Structure::GetPreviousLevelGraphicCode() const
{
// WARNING: we don't have such information in a general structure
	return _eGC;
}


   /*======================================================================*/
const OPENCITY_STRUCTURE_CODE
Structure::GetCode() const
{
	return _eSC;
}


   /*======================================================================*/
Structure*
Structure::GetMain() const
{
	return _pstructureMain;
}


   /*======================================================================*/
void
Structure::SetMain( Structure* const pstruct )
{
	_pstructureMain = pstruct;
}


   /*======================================================================*/
const bool
Structure::LevelUp(  )
{
//	OPENCITY_DEBUG("WARNING: Inside Structure");
	if (_uiLevel < OC_STRUCTURE_LEVEL_MAX) {
		_uiLevel++;
		return true;
	}

	return false;
}


   /*======================================================================*/
const bool
Structure::LevelDown(  )
{
	if (_uiLevel > OC_STRUCTURE_LEVEL_MIN) {
		_uiLevel--;
		return true;
	}

	return false;
}


   /*======================================================================*/
const uint
Structure::GetLevel() const
{
	return _uiLevel;
}


   /*======================================================================*/
void
Structure::SetLevel(
	const uint uiLevel )
{
	_uiLevel = uiLevel;
}


   /*======================================================================*/
const OPENCITY_STRUCTURE_TYPE
Structure::GetType() const
{
	return _eType;
}



























