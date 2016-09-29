/***************************************************************************
						heightMap.h  -  description
							-------------------
	begin                : April 1st, 2007
	copyright            : (C) 2007 by Fr�d�ric RODRIGO
	email                : f.rodrigo free.fr
	
	$Id: heightMap.h 373 2008-10-11 21:32:54Z neoneurone $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

#ifndef _OPENCITY_HEIGHTMAP
#define _OPENCITY_HEIGHTMAP

#include "generator.h"

#include "SDL.h"

namespace MapGen
{


//========================================================================
/** Load heigh map from a picture file
*/
class HeightMap: public Generator {
public:
//========================================================================
	HeightMap( const string heightMapFile );
	~HeightMap();


	Map* render() const;

private:

	const string file;

	Uint32 getPixel( SDL_Surface *surf, int x, int y ) const;

};

}

#endif
