/***************************************************************************
						destination.cpp  -  description
							-------------------
	begin                : may 16th, 2004
	copyright            : (C) 2004-2007 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: destination.cpp 375 2008-10-28 14:47:15Z neoneurone $
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

// OpenCity header
#include "destination.h"


   /*=====================================================================*/
Destination::Destination():
_eDir( OC_DIR_O_S ),
_uiW( 0 ), _uiL( 0 ),
_iHMin( 0 ), _iHMax( 0 ),
_uiTime( 0 ),
_ubTraffic( 0 )
{
	// OPENCITY_DEBUG( "ctor" );
}


   /*=====================================================================*/
Destination::~Destination()
{
	// OPENCITY_DEBUG( "dtor" );
}


   /*=====================================================================*/
OPENCITY_DIRECTION
Destination::GetDir(
	const Destination & rcA,
	const Destination & rcB)
{
// W tests
	if ((rcA._uiW == rcB._uiW) and (rcA._uiL == rcB._uiL)) {
		return rcA._eDir;
	}

	if (rcA._uiW < rcB._uiW) {
		return OC_DIR_O_E;
	}

	if (rcA._uiW > rcB._uiW) {
		return OC_DIR_O_W;
	}

// L tests
	if (rcA._uiL < rcB._uiL) {
		return OC_DIR_O_S;
	}

	if (rcA._uiL > rcB._uiL) {
		return OC_DIR_O_N;
	}

	OPENCITY_DEBUG( "Game design error" );
	assert( 0 );
	return OC_DIR_O_S;
}



