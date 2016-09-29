/***************************************************************************
					  commercialsim.h  -  description
							-------------------
	begin                : jan 31th, 2004
	copyright            : (C) 2004-2010 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: commercialsim.h 450 2010-11-21 19:11:43Z neoneurone $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

#ifndef _OPENCITY_COMMERCIALSIM_H_
#define _OPENCITY_COMMERCIALSIM_H_ 1

#include "main.h"
#include "simulator.h"


//========================================================================
/** Handle the simulation of the commercial sub-system.
*/
class CommercialSim : public Simulator
{
public:
	CommercialSim(
		SDL_mutex* mutex,
		BuildingLayer* pblayer,
		Map* pmap );
	~CommercialSim();

	int
	Main();

	void
	RemoveStructure(
		const uint & w1,
		const uint & h1,
		const uint & w2,
		const uint & h2 );

};

#endif
