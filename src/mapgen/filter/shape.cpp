/***************************************************************************
						shapeBubble.cpp  -  description
							-------------------
	begin                : feb 10th, 2007
	copyright            : (C) 2006 by Fr�d�ric RODRIGO
	email                : f.rodrigo free.fr
	
	$Id: shape.cpp 373 2008-10-11 21:32:54Z neoneurone $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

#include "shape.h"

#include <math.h>

namespace MapGen
{


   /*=====================================================================*/
Shape::Shape( const uint w, const uint h ):
_w(w),
_h(h)
{
	MAP_DEBUG( "ctor" );
}


   /*=====================================================================*/
Shape::~Shape()
{
	MAP_DEBUG( "dtor" );
}


}
