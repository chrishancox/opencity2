/***************************************************************************
						guibar.cpp    -  description
							-------------------
	begin                : december 14th, 2006
	copyright            : (C) 2006 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: guibar.cpp 375 2008-10-28 14:47:15Z neoneurone $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

#include "guibar.h"
#include "guicontainer.h"


#define OC_BAR_INITIAL_RATIO	1/20
#define OC_BAR_INITIAL_VALUE	20
#define OC_BAR_START_VALUE		1


   /*=====================================================================*/
GUIBar::GUIBar()
{
	OPENCITY_DEBUG( "Default ctor. Not used" );
	assert(0);
}


   /*=====================================================================*/
GUIBar::GUIBar(
	const int ciX,
	const int ciY,
	const uint cuiW,
	const uint cuiH ):
_eVariation( OC_VERTICAL ),
_fInitialValue( OC_BAR_INITIAL_VALUE ),
_fValue( OC_BAR_START_VALUE ),
_fWidthRatio( 1 ),
_fHeightRatio( OC_BAR_INITIAL_RATIO )
{
	OPENCITY_DEBUG( "Pctor" );

// Safe
	_pctr = NULL;

// Initialize the position of the button
// NOTE: it's relative to the postion of the container
	_iX = ciX;
	_iY = ciY;
	_uiWidth = cuiW;
	_uiHeight = cuiH;

	_cForeground = OPENCITY_PALETTE[Color::OC_BLACK];

// By default the bar is visible
	Set( OC_GUIMAIN_VISIBLE );
}


   /*=====================================================================*/
GUIBar::~GUIBar()
{
	OPENCITY_DEBUG( "Dtor" );
}


   /*=====================================================================*/
void
GUIBar::SetInitialValue( 
	const float fValue )
{
	assert( fValue != 0 );
	_fInitialValue = fValue;
}


   /*=====================================================================*/
void
GUIBar::SetValue( const float fValue )
{
	_fValue = fValue;

	switch (_eVariation) {
		case OC_HORIZONTAL:
			_fWidthRatio = _fValue / _fInitialValue;
			break;

		case OC_VERTICAL:
			_fHeightRatio = _fValue / _fInitialValue;
			break;

		case OC_BOTH:
			_fWidthRatio = _fValue / _fInitialValue;
			_fHeightRatio = _fWidthRatio;
			break;
	}
}


   /*=====================================================================*/
void
GUIBar::SetVariation(
	const OPENCITY_VARIATION eV )
{
	_eVariation = eV;
}


   /*=====================================================================*/
void
GUIBar::SetForeground(
	const Color& color )
{
	_cForeground = color;
}


   /*=====================================================================*/
void
GUIBar::Display() const
{
	uint w, h;
	assert( _pctr != NULL );

// Return immediatly if this is NOT visible
	if ( IsSet( OC_GUIMAIN_VISIBLE ) == false )
		return;

// Calculate the size of the surface to display
	w = (uint)((_uiWidth-1) * _fWidthRatio);
	h = (uint)((_uiHeight-1) * _fHeightRatio);

// Translate the button to the correct position
	glPushAttrib( GL_ENABLE_BIT );
	glDisable( GL_LIGHTING );
	glPushMatrix();
	glTranslatef( _iX, _iY, 0.0 );

	glColor4ub( _cForeground.r, _cForeground.g, _cForeground.b, _cForeground.a );

	glBegin( GL_QUADS );
	glVertex2i( 0, 0 );
	glVertex2i( w, 0 );
	glVertex2i( w, h );
	glVertex2i( 0, h );
	glEnd();

// Restore the old matrix and attribs
	glPopMatrix();
	glPopAttrib();
}


   /*=====================================================================*/
void
GUIBar::Keyboard( const SDL_KeyboardEvent& rcEvent )
{}


   /*=====================================================================*/
void
GUIBar::MouseMotion( const SDL_MouseMotionEvent& rcEvent )
{}


   /*=====================================================================*/
void
GUIBar::MouseButton( const SDL_MouseButtonEvent& rcEvent )
{}


   /*=====================================================================*/
void
GUIBar::Expose( const SDL_ExposeEvent& rcEvent )
{
	this->Display();
}


   /*=====================================================================*/
void
GUIBar::Resize( const SDL_ResizeEvent& rcEvent )
{}
































