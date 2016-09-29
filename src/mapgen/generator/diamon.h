/***************************************************************************
						diamon.h  -  description
							-------------------
	begin                : july 2nd, 2006
	copyright            : (C) 2006 by Fr�d�ric RODRIGO
	email                : f.rodrigo free.fr
	
	$Id: diamon.h 373 2008-10-11 21:32:54Z neoneurone $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

#ifndef _OPENCITY_DIAMON_H_
#define _OPENCITY_DIAMON_H_ 1

#include "generator.h"

namespace MapGen
{


//========================================================================
/** Square and diamon generator
	- generate cyclic map
	- generate square map with side = 2^x
*/
class Diamon: public Generator {
public:
//========================================================================
/** The order is log2 of produced map side */
	Diamon( const uint seed, const uint order );
	~Diamon();


	Map* render() const;

private:
	uint	_side;


//========================================================================
/** Return a random in [-p..p[
*/
	inline static float _all( const uint p );


//========================================================================
/** Recursive render
*/
	void _sub(
		Map* map,
		const uint x1,
		const uint y1,
		const uint x2,
		const uint y2 ) const;

};

}

#endif
