/***************************************************************************
						generator.h  -  description
							-------------------
	begin                : july 2nd, 2006
	copyright            : (C) 2006 by Fr�d�ric RODRIGO
	email                : f.rodrigo free.fr
	
	$Id: generator.h 373 2008-10-11 21:32:54Z neoneurone $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

#ifndef _OPENCITY_GENERATOR_H_
#define _OPENCITY_GENERATOR_H_ 1

#include "../map.h"			// ../ because of silly DevCpp

namespace MapGen
{


//========================================================================
/** Generator virtual class/interface
*/
class Generator {
public:
	Generator( const uint seed );
	virtual ~Generator();

	virtual Map* render() const = 0;

private:

};


}

#endif
