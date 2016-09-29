/***************************************************************************
						shaper.h  -  description
							-------------------
	begin                : feb 10th, 2007
	copyright            : (C) 2006 by Fr�d�ric RODRIGO
	email                : f.rodrigo free.fr
	
	$Id: shaper.h 373 2008-10-11 21:32:54Z neoneurone $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

#ifndef _OPENCITY_SHAPER_H_
#define _OPENCITY_SHAPER_H_ 1

#include "filter.h"

#include "shape.h"

namespace MapGen
{


//========================================================================
/** Generic shaper apply
*/
class Shaper: public Filter {
public:
	Shaper( const Shape *shape );
	virtual ~Shaper();

	void apply( Map* map );

private:
	const Shape *_shape;

};


}

#endif
