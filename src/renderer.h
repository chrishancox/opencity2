/***************************************************************************
						renderer.h  -  description
							-------------------
	begin                : may 29th, 2003
	copyright            : (C) 2003-2008 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: renderer.h 474 2015-05-17 16:26:51Z neoneurone $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

#ifndef _OPENCITY_RENDERER_H_
#define _OPENCITY_RENDERER_H_ 1

#include "main.h"
#include "texture.h"


class Layer;
class Map;


//========================================================================
/** Deal with the OpenGL library to render game's objects. This class
	shouldn't play with SDL functions but OpenGL
*/
class Renderer
{
public:
	Renderer(
		const uint cityW,
		const uint cityL );

	~Renderer();


	void RotateLeft( const float & factor = 1 );
	void RotateRight( const float & factor = 1 );
	void MoveLeft( const float & factor = 1 );
	void MoveRight( const float & factor = 1 );
	void MoveUp( const float & factor = 1 );
	void MoveDown( const float & factor = 1 );


//========================================================================
/** Reinit the map's position as if the game has just been launched
*/
	void Home();

	void ZoomIn(  );
	void ZoomOut(  );

	void ToggleTerrain();
	void ToggleWater();
	void ToggleStructure();
	void ToggleGrid();
	void ToggleCompass();
	void ToggleProjection();
	void ToggleWireFrame();


//========================================================================
/** Display the splash screen at the specified coordinates
*/
	void
	DisplaySplash(
		const uint & rcuiX = 0,
		const uint & rcuiY = 0 );


//========================================================================
/** Display the layer and the map to the back buffer. The caller must
	swap the buffers to show the changes
*/
	void
	Display(
		const Map* pcMap,
		const Layer* pcLayer );


	void
	DisplayHighlight(
		const Map* pcMap,
		const Layer* pcLayer,
		const OPENCITY_TOOL_CODE & enumTool );


	void
	DisplayHighlight(
		const Map* pcMap,
		const Layer* pcLayer,
		uint uiW1,
		uint uiL1,
		uint uiW2,
		uint uiL2,
		const OPENCITY_TOOL_CODE & enumTool );


//========================================================================
/** Display the specified graphic code with a bounding rectangle
*/
	void DisplayBuildPreview(
		const uint & uiW,
		const uint & uiL,
		const GLubyte & rcubR,
		const GLubyte & rcubG,
		const GLubyte & rcubB,
		const OPENCITY_GRAPHIC_CODE & gcode ) const;


	void
	DisplaySelection(
		const Map* pcMap,
		const Layer* pcLayer );


	void
	DisplaySelection(
		const Map* pcMap,
		const Layer* pcLayer,
		const uint & rcuiW1,
		const uint & rcuiL1,
		const uint & rcuiW2,
		const uint & rcuiL2 );


//========================================================================
	void
	DisplayText(
		const uint & rcuiX,
		const uint & rcuiY,
		const GLubyte & rcubR,
		const GLubyte & rcubG,
		const GLubyte & rcubB,
		const string & rcText );


	const bool
	GetSelectedWLFrom(
		const uint & rcuiMouseX,
		const uint & rcuiMouseY,
		uint & ruiW,
		uint & ruiL,
		const Map* pcMap,
		const Layer* pcLayer );


	const bool
	GetSelectedWLFrom(
		const uint & rcuiMouseX,
		const uint & rcuiMouseY,
		uint & ruiW,
		uint & ruiL,
		const Map* pcMap,
		const Layer* pcLayer,
		const uint & rcuiW1,
		const uint & rcuiL1,
		const uint & rcuiW2,
		const uint & rcuiL2 );


//========================================================================
/** This method _must_ be called whenever the window's size changes. It
	calculates the viewport and set the correct internal window's width
	and height
*/
	void SetWinSize(
		const int & rciWidth,
		const int & rciHeight );


//========================================================================
/** The City class use this to notify the renderer class that the
	height of the map has changed and the current buffered informations
	need to be recalculated
*/
	bool bHeightChange;
	bool bMinimapChange;


private:
	bool _bDisplayTerrain;		///< Display the terrain
	bool _bDisplayWater;		///< Display the water
	bool _bDisplayStructure;	///< Display the structures built on the layer
	bool _bDisplayGrid;			///< Display the terrain grid
	bool _bDisplayCompass;		///< Display the GUI / compass
	bool _bWireFrame;			///< Wireframe mode

	OC_BYTE _ubProjectionType;
	GLfloat _fScaleRatio;
	GLfloat _fXTransDelta;	///< The delta used for translation in the X direction
	GLfloat _fZTransDelta;

// GL display lists
	GLuint _uiGridList;		///< GL list of the grid
	GLuint _uiFontBase;		///< The base font list index
	GLuint _uiTerrainList;	///< GL list of the terrain
	GLuint _uiWaterList;	///< GL list of the water texture

// Frequently use textures
	GLuint _uiMinimapTex;		///< Minimap texture
	Texture moTextureCloud;		///< Cloud texture
	Texture moTextureTerrain;	///< Terrain texture
	Texture moTextureWater;		///< Water texture
	Texture moTextureSplash;	///< Splash texture


/** Contains the X value for the translation of the layer. It is used by
	MoveLeft() and MoveRight()
   */
	GLdouble _dDeltaX;

/** Contains the Z value for the translation. It is used by
	MoveUp() and MoveDown()
*/
	GLdouble _dDeltaZ;

/// used for calculating the rotation of the map
	GLdouble _dYRotateAngle;
	GLdouble _dmatrixRotate[16];

/// The model culling grid
	bool _bCalculateCulling;
	bool* _baCulledGrid;			// The culled grid has w+1 x l+1 nodes
	bool* _baCulledModel;			// The culled model array has w x l models

/// used for calculating the viewport & the perspective ratio
	int _iWinHeight;
	int _iWinWidth;

/// The city width & height
	uint _uiCityWidth;
	uint _uiCityLength;


   /*=====================================================================*/
   /*                        PRIVATE     METHODS                          */
   /*=====================================================================*/
/** Draw the terrain as an _unique_ TRIANGLE_STRIP which is known
as the fastest primitive in OpenGL. It starts at the north-west and when
it reaches the north-east map edge, it starts drawing from the north-east
to the north-west eadge. Finally the algorithm draws from the north to
the south.
*/
	void _DisplayTerrain() const;


//========================================================================
/** This method uses the same algorithm as _DisplayTerrain() does to
draw the water layer
	\see _DisplayTerrain()
*/
	void _DisplayWater() const;


//========================================================================
/** Draw the dotted grid. This method uses OpenGL display list inside.
*/
	void _DisplayMapGrid( const Map* pcmap );


	void _DisplayCompass() const;


//========================================================================
/** Prepare the world before drawing the entire scene
*/
	void _PrepareView();

//========================================================================
/** Calulate the culled grid which has city_width + 1 and city_length + 1
nodes
*/
	void _CalculateCulledGrid(
		uint w1, uint l1,
		uint w2, uint l2,
		bool init = false);

//========================================================================
/** Calulate the culled (selected) models from the culled grid.
The culled models are drawn, the others are not drawn.
*/
	void _CalculateCulledModel( const Layer* pcLayer );


//========================================================================
/** Set the LOD according to the scale ratio
*/
	void _SetLOD() const;
};

#endif




























