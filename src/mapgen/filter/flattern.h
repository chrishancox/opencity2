/***************************************************************************
						flattern.h  -  description
							-------------------
	begin                : july 2nd, 2006
	copyright            : (C) 2006 by Fr�d�ric RODRIGO
	email                : f.rodrigo free.fr
	
	$Id: flattern.h 373 2008-10-11 21:32:54Z neoneurone $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

#ifndef _OPENCITY_FLATTERN_H_
#define _OPENCITY_FLATTERN_H_ 1

#include "filter.h"

namespace MapGen
{


//========================================================================
/** Use a x^power function to resample the map
*/
class Flattern: public Filter {
public:
	Flattern( const float power );
	~Flattern();

	void apply( Map* map );

private:
	float	_power;

};


}

#endif
