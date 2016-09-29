/***************************************************************************
						shape.h  -  description
							-------------------
	begin                : feb 10th, 2007
	copyright            : (C) 2006 by Fr�d�ric RODRIGO
	email                : f.rodrigo free.fr
	
	$Id: shape.h 373 2008-10-11 21:32:54Z neoneurone $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

#ifndef _OPENCITY_SHAPE_H_
#define _OPENCITY_SHAPE_H_ 1

#include "../map.h"                     // ../ because of silly DevCpp

namespace MapGen
{


//========================================================================
/** Define generic shape
*/
class Shape {
public:
	Shape( const uint w, const uint h );
	virtual ~Shape();

	virtual float value( const uint x, const uint y ) const = 0;

private:
	uint		_w;
	uint		_h;

};


}

#endif
