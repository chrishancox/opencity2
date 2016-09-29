/***************************************************************************
						guicontainer.cpp    -  description
							-------------------
	begin                : mar 22th, 2004
	copyright            : (C) 2004-2008 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: guicontainer.cpp 450 2010-11-21 19:11:43Z neoneurone $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

// Useful enumerations
#include "opencity_direction.h"
#include "opencity_structure_type.h"

// OpenCity headers
#include "guicontainer.h"

// Global settings
#include "globalvar.h"
extern GlobalVar gVars;


   /*=====================================================================*/
GUIContainer::GUIContainer()
{
	OPENCITY_DEBUG( "Default ctor" );

	_uiWinWidth = gVars.guiScreenWidth;
	_uiWinHeight = gVars.guiScreenHeight;
}


   /*=====================================================================*/
GUIContainer::GUIContainer
(
	const int ciX,
	const int ciY,
	const uint cuiW,
	const uint cuiH
)
{
	OPENCITY_DEBUG( "Pctor 1" );

	_uiWinWidth = gVars.guiScreenWidth;
	_uiWinHeight = gVars.guiScreenHeight;

	_iX = ciX;
	_iY = ciY;
	_uiWidth = cuiW;
	_uiHeight = cuiH;
}


   /*=====================================================================*/
GUIContainer::GUIContainer(
	const int ciX,
	const int ciY,
	const uint cuiW,
	const uint cuiH,
	const string& rcsTexFile )
{
	OPENCITY_DEBUG( "Pctor 2" );

	_uiWinWidth = gVars.guiScreenWidth;
	_uiWinHeight = gVars.guiScreenHeight;

	_iX = ciX;
	_iY = ciY;
	_uiWidth = cuiW;
	_uiHeight = cuiH;
	moTextureBackground = Texture( rcsTexFile );
}


   /*=====================================================================*/
GUIContainer::~GUIContainer()
{
	OPENCITY_DEBUG( "Dtor" );

	std::vector<GUIMain*>::size_type stvector;
	GUIMain* pguimain;

// Now remove the container pointer from all the contained controls
	for ( stvector = 0; stvector < this->vectorpguimain.size(); stvector++ ) {
		if ( (pguimain = vectorpguimain[ stvector ]) != NULL )
			pguimain->SetContainer( NULL );
	}

// Delete all the pointers in the "vector"
// Note: the pointed memory is not freed
	this->vectorpguimain.clear();
}


   /*=====================================================================*/
const uint
GUIContainer::Add( GUIMain* const pguimain )
{
// Add the new pointer to the end
	pguimain->SetContainer( this );
	this->vectorpguimain.push_back( pguimain );

// Get its index for future use
	return this->vectorpguimain.size();
}


   /*=====================================================================*/
const uint
GUIContainer::GetNumber() const
{
	return this->vectorpguimain.size();
}


   /*=====================================================================*/
void
GUIContainer::GetWinWH(
	int & riWinW,
	int & riWinH ) const
{
	riWinW = _uiWinWidth;
	riWinH = _uiWinHeight;
}


   /*=====================================================================*/
const uint
GUIContainer::GetClick() const
{
	static std::vector<GUIMain*>::size_type stvector;
	static GUIMain* pguimain;

// We return immediatly if this is NOT visible
	if ( IsSet( OC_GUIMAIN_VISIBLE ) == false )
		return 0;

// FOR each object DO
// IF we find a object which is clicked and has mouseover THEN
	for ( stvector = 0; stvector < this->vectorpguimain.size(); stvector++ ) {
		if ( (pguimain = vectorpguimain[ stvector ]) != NULL )
		if ( pguimain->IsSet( OC_GUIMAIN_CLICKED | OC_GUIMAIN_MOUSEOVER ) == true )
			return ++stvector;
	}

// There's no clicked object
	return 0;
}


   /*=====================================================================*/
void
GUIContainer::Set(
	const uint & rcuiIndex,
	const OC_BYTE & rcubAttribute ) const
{
	assert( rcuiIndex <= vectorpguimain.size() );

	vectorpguimain[ rcuiIndex-1 ]->Set( rcubAttribute );
}


   /*=====================================================================*/
void
GUIContainer::ResetAttribute(
	const OC_BYTE & rcubAttr ) const
{
	std::vector<GUIMain*>::size_type stvector;
	GUIMain* pguimain;

// Reset the attributes of all contained objects
	for ( stvector = 0; stvector < this->vectorpguimain.size(); stvector++ ) {
		if ( (pguimain = vectorpguimain[ stvector ]) != NULL )
			pguimain->Unset( rcubAttr );
	}
}


   /*=====================================================================*/
void
GUIContainer::Display() const
{
	static std::vector<GUIMain*>::size_type stvector;
	static GUIMain* pguimain;

// We return immediatly if this is NOT visible
	if ( IsSet( OC_GUIMAIN_VISIBLE ) == false )
		return;

// Save the old projection matrix before processing
	glMatrixMode( GL_PROJECTION );
	glPushMatrix();
	glLoadIdentity();
// Use the orthonormal projection
	gluOrtho2D( 0, _uiWinWidth-1, 0, _uiWinHeight-1 );

// Store the old matrix and move the container to the correct position
	glMatrixMode( GL_MODELVIEW );
	glPushMatrix();
	glLoadIdentity();
	glTranslatef( _iX, _iY, 0.0 );

// Display the background
	GLuint uiTexture = moTextureBackground.GetName();
	if (glIsTexture( uiTexture ) == GL_TRUE) {
		glPushAttrib( GL_ENABLE_BIT );
		glDisable( GL_LIGHTING );
		glEnable( GL_BLEND );
		glEnable( GL_TEXTURE_2D );
		glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE );
		glBindTexture( GL_TEXTURE_2D, uiTexture );

		glBegin( GL_QUADS );
		glTexCoord2i( 0, 0 );	glVertex2i( 0, 0 );
		glTexCoord2i( 1, 0 );	glVertex2i( _uiWidth-1, 0 );
		glTexCoord2i( 1, 1 );	glVertex2i( _uiWidth-1, _uiHeight-1 );
		glTexCoord2i( 0, 1 );	glVertex2i( 0, _uiHeight-1 );
		glEnd();

		glPopAttrib();
	}

// Now display all the contained GUI controls
	for ( stvector = 0; stvector < this->vectorpguimain.size(); stvector++ ) {
		if ( (pguimain = vectorpguimain[ stvector ]) != NULL )
			pguimain->Display();
	}

	glPopMatrix();
	glMatrixMode( GL_PROJECTION );
	glPopMatrix();
	glMatrixMode( GL_MODELVIEW );
}


   /*=====================================================================*/
void
GUIContainer::Keyboard( const SDL_KeyboardEvent& rcEvent )
{}


   /*=====================================================================*/
void
GUIContainer::MouseMotion( const SDL_MouseMotionEvent& rcEvent )
{
	static std::vector<GUIMain*>::size_type stvector;
	static GUIMain* pguimain;

// We return immediatly if this is NOT visible
	if ( IsSet( OC_GUIMAIN_VISIBLE ) == false )
		return;

// Send the motion event to all objects
	for ( stvector = 0; stvector < this->vectorpguimain.size(); stvector++ ) {
		if ( (pguimain = vectorpguimain[ stvector ]) != NULL )
			pguimain->MouseMotion( rcEvent );
	}
}


   /*=====================================================================*/
void
GUIContainer::MouseButton( const SDL_MouseButtonEvent& rcEvent )
{
	static std::vector<GUIMain*>::size_type stvector;
	static GUIMain* pguimain;

// We return immediatly if this is NOT visible
	if ( IsSet( OC_GUIMAIN_VISIBLE ) == false )
		return;

// Send the mouse button event to all objects
	for ( stvector = 0; stvector < this->vectorpguimain.size(); stvector++ ) {
		if ( (pguimain = vectorpguimain[ stvector ]) != NULL )
			pguimain->MouseButton( rcEvent );
	}
}


   /*=====================================================================*/
void
GUIContainer::Expose( const SDL_ExposeEvent& rcEvent )
{
	this->Display();
}


   /*=====================================================================*/
void
GUIContainer::Resize( const SDL_ResizeEvent& rcEvent )
{
	_uiWinWidth = rcEvent.w;
	_uiWinHeight = rcEvent.h;
}



































