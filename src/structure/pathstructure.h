/***************************************************************************
						pathstructure.h  -  description
							-------------------
	begin                : june 17th, 2003
	copyright            : (C) 2003-2007 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: pathstructure.h 450 2010-11-21 19:11:43Z neoneurone $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

#ifndef _OPENCITY_PATHSTRUCTURE_H_
#define _OPENCITY_PATHSTRUCTURE_H_ 1

#include "structure.h"

enum OPENCITY_DIRECTION;


/** This is a specialization of Structure. It regroups all structures
like Road, Rails, WaterPipe, GasPipe, HighWay, ElecLine etc...
*/
class PathStructure : public Structure  {
public:
	/** Should not be used */
	PathStructure();
	PathStructure( const OPENCITY_STRUCTURE_CODE & enumStructCode );
	virtual ~PathStructure();   // virtual since Structure's one is


//========================================================================
/** Overload the Structure::SaveTo
	\param rfs A reference to a file stream which is ready for writing
	\see Structure::SaveTo()
*/
	void
	SaveTo( std::fstream& rfs );


//========================================================================
/** Overload the Structure::LoadFrom
	\param rfs A reference to a file stream which is ready for reading
	\see Structure::LoadFrom
*/
	void
	LoadFrom( std::fstream& rfs );


	void
	AddNeighbour(
		const PathStructure & rcNeighbour,
		const OPENCITY_DIRECTION & enumDir );


	void
	RemoveNeighbour(
		const PathStructure & rcNeighbour,
		const OPENCITY_DIRECTION & enumDir );


	const OC_BYTE &
	GetTraffic() const;

	void
	SetTraffic(
		const OC_BYTE & rubTraffic );

	const uint &
	GetLength() const;

	void
	SetLength(
		const uint & rcuiValue );


private:
	OC_BYTE ubNumberNeighbour;
	OC_BYTE ubTraffic;

	uint uiLength;		// for pathfinding purpose
};

#endif
