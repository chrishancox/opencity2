/***************************************************************************
						texture.h    -  description
							-------------------
	begin                : july, 2nd 2004
	copyright            : (C) 2004-2007 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: texture.h 375 2008-10-28 14:47:15Z neoneurone $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

#ifndef _OPENCITY_TEXTURE_H_
#define _OPENCITY_TEXTURE_H_ 1

#include "main.h"

#include <map>					// Used for automanaged texture loading cache
#include <utility>

using std::map;
using std::pair;

class BuildingLayer;


//========================================================================
/** This class can be considered as a tool class for texture image loading.
	Thanks to the SDL_image library, it can read all the file formats that
	SDL_image supports.
*/
class Texture {
public:
	Texture();
	Texture( const string& rcFile );
	Texture( const string& rcFile, bool b3d );		// quick hack

	~Texture();


//========================================================================
/** Return the texture name
*/
	GLuint GetName() const;

	void GetSize( uint& ruiWidth, uint& ruiHeight ) const
	{ ruiWidth = muiWidth; ruiHeight = muiHeight; }


//========================================================================
/** After calling this function, the image pixels are flipped in the
vertical direction because the SDL_image library reads the image's
pixels from the upper left corner, left to right, to the bottom right
corner whereas the glTexImage2D builds the texture from the bottom left
corner, left to right, to the upper right corner
	\param psurface A source surface
	\return A new surface with the flipped pixels from the source surface. The
returned surface must be freed by the caller
*/
	static SDL_Surface*
	HorizontalMirror(
		const SDL_Surface* const psurface
	);


//========================================================================
/** Convert a SDL surface to OpenGL texture
	\param psurface The SDL source surface to convert
	\param ruiTexture A reference to a GLuint variable.
	\return Nothing
*/
	static void
	Surface2Texture(
		const SDL_Surface* const psurface,
		GLuint& ruiTexture
	);

	static void
	Surface2Texture3D(
		const SDL_Surface* const psurface,
		GLuint& ruiTexture,
		GLint format
	);


	static void
	Building2Texture(
		const BuildingLayer* const pLayer,
		GLuint& ruiTexture
	);


private:
	static map<string, pair<GLuint, uint> >	mmapTextureCache;	///< Automanaged texture name cache

	uint muiWidth, muiHeight;
	GLuint muiTextureName;
	string msTextureFile;


//========================================================================
// PRIVATE METHODS
//========================================================================

//========================================================================
/** Open the specified image, read it into a SDL_surface then convert it
to an OpenGL texture. Use it carefully because it doesn't handle error
checking right now.
	\param rcFile The path to the image.
	\return The index of the new OpenGL texture (type const GLuint)
*/
	static const GLuint
	_Load( const string& rcFile );

	static const GLuint
	_Load3D( const string& rcFile );


//========================================================================
/** Load the specified texture file into an OpenGL texture object
	\param rcFile The path to the image.
	\param ruiW,ruiH The size of the loaded texture
	\return The index of the new OpenGL texture (type const GLuint)
	\sa Load()
*/
	static const GLuint
	_Load(
		const string& rcFile,
		uint& ruiW,
		uint& ruiH
	);

	static const GLuint
	_Load3D(
		const string& rcFile,
		uint& ruiW,
		uint& ruiH
	);

//========================================================================
/** Find the correct OpenGL dimensions for given width w and height h
	\param w, h The origial texture width and height
	\param rW, rH The corrected texture width and height
	\return True if the size has changed, false otherwise
*/
	static bool
	_GetCorrectSize(
		const uint w, const uint h,
		uint& rW,    uint& rH );


//========================================================================
/** Remove unnecessary relative path token. For example: from "abc/../file.jpg"
to "file.jpg". However it returns "/../" unchanged.
	\param rcsPath The path to process
	\return The resolved relative path
*/
	static string
	_ResolveRelativePath(const string& rcsPath);

};

#endif
































