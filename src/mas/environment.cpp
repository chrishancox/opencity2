/***************************************************************************
                       environment.h  -  description
							-------------------
	begin                : dec 11th, 2005
	copyright            : (C) 2005-2010 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com
	author               : Victor STINNER

	$Id: environment.cpp 448 2010-05-09 15:18:32Z neoneurone $
***************************************************************************/

/***************************************************************************
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   any later version.                                                    *
*                                                                         *
***************************************************************************/

// Useful enumeration
#include "opencity_direction.h"
#include "opencity_structure_type.h"

// MAS headers
#include "environment.h"
#include "kernel.h"

// OpenCity headers
#include "structure.h"
#include "layer.h"
#include "graphicmanager.h"
#include "pathfinder.h"

// Global settings
#include "globalvar.h"
extern GlobalVar gVars;


/*=====================================================================*/
unsigned char randomBool()
{
	return rand() <= (RAND_MAX / 2);
}


/*=====================================================================*/
int randomInt(int min, int max)
{
	unsigned int width = (max - min + 1);
	return static_cast<int> (min + (double)rand() * width / RAND_MAX);
}


	/*=====================================================================*/
MAS_DIRECTION rotate180(MAS_DIRECTION dir)
{
	switch (dir)
	{
		case NORTH: return SOUTH;
		case EAST:  return WEST;
		case SOUTH: return NORTH;
		case WEST:  return EAST;
	}

// We should never reach here
	assert(0);
	return NORTH;
}


	/*=====================================================================*/
MAS_DIRECTION rotateLeft(MAS_DIRECTION dir)
{
	switch (dir)
	{
		case NORTH: return WEST;
		case EAST:  return NORTH;
		case SOUTH: return EAST;
		case WEST:  return SOUTH;
	}

// We should never reach here
	assert(0);
	return NORTH;
}


	/*=====================================================================*/
MAS_DIRECTION rotateRight(MAS_DIRECTION dir)
{
	switch (dir)
	{
		case NORTH: return EAST;
		case EAST:  return SOUTH;
		case SOUTH: return WEST;
		case WEST:  return NORTH;
	}

// We should never reach here
	assert(0);
	return NORTH;
}

	/*=====================================================================*/
Environment::Environment(
	unsigned int width,
	unsigned int height,
	Layer* pBL,
	Kernel *kernel):
_width(width),
_height(height),
_pKernel(kernel),
_pBuildingLayer(pBL)
{
	_vector.assign(_width * _height, NULL);
}


/*=====================================================================*/
void Environment::displayAgent()
{
	assert( gVars.gpGraphicMgr != NULL );

	_vector_cit it=_vector.begin(), end=_vector.end();
	for (; it != end; ++it) {
		if (*it) {
			Agent *agent = *it;
			float x = agent->getX();
			float y = agent->getY();
			_last_pos_it last = _last_pos.find(agent);
			if (last != _last_pos.end()) {
				unsigned int dt = _pKernel->getStep() - last->second.step;
				if (dt  < 3) {
					int lastx = last->second.x;
					int lasty = last->second.y;
					x = x + (x - lastx) * dt / 3;
					y = y + (y - lasty) * dt / 3;
				}
				else {
					_last_pos.erase(last);
				}
			}
			gVars.gpGraphicMgr->DisplayAgent(x, y, agent);
// debug
//			cout << "Registered agent with GC : " << (*it)->GetGraphicCode() << endl;
		}
	}
}


/*=====================================================================*/
unsigned int Environment::getHeight() const
{
	return _width;
}


/*=====================================================================*/
unsigned int Environment::getWidth() const
{
	return _height;
}


/*=====================================================================*/
void Environment::registerAgent(Agent* agent, int x, int y)
{
	unsigned int pos = agent->getY()*_width + agent->getX();
	if (_vector[pos] != NULL) {
		cerr << "There's already one agent at x: " << x << " / y: " << y << endl;
		return;
	}
	_vector[pos] = agent;
}


/*=====================================================================*/
void Environment::unregisterAgent(Agent* agent)
{
	unsigned int pos = agent->getY()*_width + agent->getX();
	assert(_vector[pos] != NULL);
	_vector[pos] = NULL;
}


/*=====================================================================*/
bool Environment::hasAgentAt(const Agent *agent, int x, int y) const
{
	return (_vector.at(y*_width + x) != NULL);
}


/*=====================================================================*/
Agent* Environment::getAgentAt(int x, int y)
{
	if (x < 0 || (int)_width <= x) return NULL;
	if (y < 0 || (int)_height <= y) return NULL;
	return _vector.at(y*_width + x);
}


/*=====================================================================*/
bool Environment::moveAgent(Agent* agent, int x, int y)
{
	unsigned int pos = y*_width + x;
	unsigned int oldpos = agent->getY()*_width + agent->getX();
	if (_vector[pos] != NULL) return false;
	_last_pos[agent] = AgentPosition(agent->getX(),agent->getY(),_pKernel->getStep());
	_vector[pos] = agent;
	_vector[oldpos] = NULL;
	return true;
}


/*=====================================================================*/
const bool
Environment::findShortestPath(
	unsigned int x1, unsigned int y1,
	unsigned int x2, unsigned int y2,
	std::vector<Destination> & rvdest )
{
	assert(gVars.gpPathFinder != NULL);

	return gVars.gpPathFinder->findShortestPath(
		x1, y1, x2, y2, rvdest,
		PathFinder::OC_DISTANCE, MAX_PATH_LENGTH  );
}


/*=====================================================================*/
Structure*
Environment::getBuildingXY(
	unsigned int x,
	unsigned int y)
{
	return _pBuildingLayer->GetStructure( x, y );
}


/*=====================================================================*/
/*                         STATIC     METHODS                          */
/*=====================================================================*/
unsigned int
Environment::toSquareDistance(
	unsigned int x1, unsigned int y1,
	unsigned int x2, unsigned int y2)
{
	return ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
