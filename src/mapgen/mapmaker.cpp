/***************************************************************************
						mapmaker.cpp    -  description
							-------------------
	begin                : july 2nd, 2006
	copyright            : (C) 2006-2007 by Fr�d�ric RODRIGO
	email                : f.rodrigo free.fr
	
	$Id: mapmaker.cpp 373 2008-10-11 21:32:54Z neoneurone $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

#include "mapmaker.h"

#include "diamon.h"
#include "heightMap.h"
#include "gaussblur.h"
#include "flattern.h"
#include "normalize.h"
#include "shaper.h"
#include "choper.h"
#include "shapeBubble.h"
#include "shapeTopRound.h"
#include "shapeVolcano.h"
#include "contextualizer.h"
#include "contextOnlyPositive.h"
#include "cutter.h"

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <ctime>


namespace MapGen
{

   /*=====================================================================*/
MapMaker::MapMaker(
	const uint w,
	const uint h,
	const string heightMap,
	const MAP_TYPE mapType,
	const WATER_TYPE waterType,
	const MAP_SHAPE_TYPE mapShapeType,
	const TREE_DENSITY_TYPE treeDensityType,
	const uint seed ):
_w(w),
_h(h),
_mapType(mapType),
_waterType(waterType),
_mapShapeType(mapShapeType),
_map(NULL),
_treeDensityType(treeDensityType),
_treeDensity(NULL),
_seed(seed)
{
	MAP_DEBUG( "ctor" );

	srand( seed );
	uint mapSeed = rand();
	uint treeDensitySeed = rand();

	if( heightMap != "" ) {
		_loadMap( heightMap );
	}
	else
	{
		_generateMap( mapSeed );
	}

	_generateTreeDensity( treeDensitySeed );

	srand( time(NULL) );
}


   /*=====================================================================*/
MapMaker::~MapMaker()
{
	MAP_DEBUG( "dtor" );

	if( _map != NULL )
		delete _map;

	if( _treeDensity != NULL )
		delete _treeDensity;
}


   /*=====================================================================*/
Map* MapMaker::_generate(
	const uint w,
	const uint h,
	const Generator* generator,
	vector<Filter*> filters ) const
{
	// Render the map
	Map* map = generator->render();
	delete generator;

	// Crop the map
	Map* cropedMap = map->crop( w, h );
	delete map;

	// Apply filters
	for( vector<Filter*>::iterator i=filters.begin() ; i!=filters.end() ; i++ )
	{
		(*i)->apply( cropedMap );
		delete *i;
	}

	return cropedMap;
}


   /*=====================================================================*/
void MapMaker::_loadMap( const string heightMap )
{
	Generator* generator;
	vector<Filter*> filters;

	generator = new HeightMap( heightMap );

	_map = _generate( _w+1, _h+1, generator, filters );
}


   /*=====================================================================*/
void MapMaker::_generateMap( const uint seed )
{
	Generator* generator;
	vector<Filter*> filters;

	// Select generator
	switch( _mapType )
	{
		default:
			uint largerSide = (_w+1) > (_h+1) ? (_w+1) : (_h+1);
			uint side = (uint) ceil( log2( (float)largerSide ) );
			generator = new Diamon( seed, side );
			break;
	}

	// Set waterLevel
	int waterLevel;
	switch( _waterType )
	{
		case DRY :
			waterLevel = 0;
			break;
		case COAST :
			waterLevel = 2;
			break;
		default:
		case LAKE :
			waterLevel = 1;
			break;
	}

	// Add map type filter
	int minLevel, maxLevel;
	switch( _mapType )
	{
		case PLAIN :
			minLevel = -3*waterLevel;
			maxLevel = 5;
			filters.push_back( new Normalize(minLevel,maxLevel) );
			filters.push_back( new Flattern(3) );
			break;
		case MOUNTAIN :
			minLevel = -10*waterLevel;
			maxLevel = 20;
			filters.push_back( new Normalize(minLevel,maxLevel) );
			filters.push_back( new Flattern(1) );
			break;
		default:
		case HILL :
			minLevel = -5*waterLevel;
			maxLevel = 10;
			filters.push_back( new Normalize(minLevel,maxLevel) );
			filters.push_back( new Flattern(2) );
			break;
	}

	// Add water filter
	switch( _mapShapeType )
	{
		case ISLAND :
			filters.push_back( new Shaper( new ShapeBubble(_w,_h,0,3,-minLevel/2) ) );
			filters.push_back( new Choper( new ShapeTopRound(_w,_h,1.-4./maxLevel/maxLevel,5,maxLevel) ) );
			filters.push_back( new Choper( new ShapeBubble(_w,_h,.5,1,maxLevel) ) );
			break;
		case VOLCANO :
			filters.push_back( new Shaper( new ShapeVolcano(_w,_h,0,0.3,maxLevel) ) );
			break;
		case CRATER :
			break;
		default:
		case NONE :
			break;
	}

	// Smooth the result
	filters.push_back( new GaussBlur(2) );

	_map = _generate( _w+1, _h+1, generator, filters );
}


   /*=====================================================================*/
void MapMaker::_generateTreeDensity( const uint seed )
{
	vector<Filter*> filters;

	// Create a new map generator
	uint largerSide = _w > _h ? _w : _h;
	uint side = (uint) ceil( log2( (float)largerSide ) );
	Generator* generator = new Diamon( seed, side );
	assert( generator != NULL );

	// Add filter
	switch( _treeDensityType )
	{
		case SPARSE:
			filters.push_back( new Flattern(1) );
			filters.push_back( new GaussBlur(5) );
			filters.push_back( new Normalize(-15,5) );
			break;

		case DENSE:
			filters.push_back( new Flattern(1) );
			filters.push_back( new GaussBlur(5) );
			filters.push_back( new Normalize(0,5) );
			break;

		case NORMAL:
		default:
			filters.push_back( new Flattern(1) );
			filters.push_back( new GaussBlur(5) );
			filters.push_back( new Normalize(-5,5) );
			break;
	}

	// Optain halfShifted map
	Map* halfShiftMap = _map->halfShift();

	// Remove trees under water
	filters.push_back( new Contextualizer( new ContextOnlyPositive(), halfShiftMap ) );

	// Remove negative density
	filters.push_back( new Cutter( new CutterFunctorOnlyPositive() ) );

	_treeDensity = _generate( _w, _h, generator, filters );

	delete halfShiftMap;
}


   /*=====================================================================*/
int* MapMaker::getMap()
{
	return _map->toIntArray();
}


   /*=====================================================================*/
int* MapMaker::getTreeDensity()
{
	return _treeDensity->toIntArray();
}


}
