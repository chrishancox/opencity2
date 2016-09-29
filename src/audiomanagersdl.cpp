/***************************************************************************
						audiomanagersdl.cpp  -  description
							-------------------
	begin                : december 26th, 2003
	copyright            : (C) 2003-2005 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: audiomanagersdl.cpp 375 2008-10-28 14:47:15Z neoneurone $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

#include "audiomanagersdl.h"

#include <fstream>


   /*====================================================================*/
AudioManager::AudioManager():
boolAudioDeviceInitialized( false ),
boolMusicEnabled( true ),
boolSoundEnabled( true ),
boolRandomMusic( true ),
uiNumberSound( 0 ),
uiNumberMusic( 0 ),
uiCurrentMusic( 0 ),
boolShuffleMusic( false ),
pMusicData( NULL )
{
	OPENCITY_DEBUG("ctor");

   // if the audio system is not init. then init. it
	if (SDL_WasInit(SDL_INIT_AUDIO) == 0) {
		if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0) {
			OPENCITY_DEBUG( "Audio ERROR" );
		}
	}
}


   /*====================================================================*/
AudioManager::~AudioManager()
{
	OPENCITY_DEBUG("dtor");

   // clear the music filename list
	this->vectorMusicFilename.clear();
	this->uiNumberMusic = 0;
	this->uiCurrentMusic = 0;

   // if there's a playing music, stop it
   // and free the music loaded
	if (pMusicData != NULL) {
		if (PlayingMusic())
			StopMusic();
		Mix_FreeMusic( pMusicData );
		pMusicData = NULL; // safe
	}

   // clear the sound filename list
	_vSoundFilename.clear();
	this->uiNumberSound = 0;

   // now free all chunks
	uint uiVectorSize = _vpSoundChunk.size();
	for (uint i = 0; i < uiVectorSize; i++) {
		Mix_FreeChunk( _vpSoundChunk[i] );
	}
	_vpSoundChunk.clear();

  // quit the audio device
	SDL_QuitSubSystem( SDL_INIT_AUDIO );
}


   /*====================================================================*/
OPENCITY_ERR_CODE
AudioManager::OpenAudio(void)
{
	if ( Mix_OpenAudio( OC_AUDIO_FREQUENCY,
			     OC_AUDIO_FORMAT,
			     OC_AUDIO_CHANNELS,
			     OC_AUDIO_CHUNK_SIZE ) < 0) {
		OPENCITY_DEBUG( "Audio opening error" );
		return OC_ERR_SOMETHING;
	}
	else {
	   // reserve channels for panning effects
		if (Mix_ReserveChannels(OC_AUDIO_RESERVED_CHANNELS)
				    !=  OC_AUDIO_RESERVED_CHANNELS) {
			OPENCITY_DEBUG( "Audio reserving channels error" );
			return OC_ERR_SOMETHING;
		}

	   // register the sounds effects, this doesn't perform test
		Mix_SetPanning( AUDIO_LEFT_CHANNEL, 254, 1 );
		Mix_SetPanning( AUDIO_LEFT_HALF_CHANNEL, 254, 127 );
		Mix_SetPanning( AUDIO_RIGHT_CHANNEL, 1, 254 );
		Mix_SetPanning( AUDIO_RIGHT_HALF_CHANNEL, 127, 254 );

	   // initialize music / sound volume
		VolumeMusic( OC_AUDIO_VOLUME_MAX * 70 / 100 );
		VolumeSound( OC_AUDIO_VOLUME_MAX );

		boolAudioDeviceInitialized = true;
		return OC_ERR_FREE;
	}
}


   /*====================================================================*/
OPENCITY_ERR_CODE
AudioManager::CloseAudio(void)
{
   // warning: we are going to close the audio device
	boolAudioDeviceInitialized = false;

   // unregister all sound effects
	Mix_UnregisterAllEffects( AUDIO_LEFT_CHANNEL );
	Mix_UnregisterAllEffects( AUDIO_LEFT_HALF_CHANNEL );
	Mix_UnregisterAllEffects( AUDIO_RIGHT_CHANNEL );
	Mix_UnregisterAllEffects( AUDIO_RIGHT_HALF_CHANNEL );

   // unreserve all previously reversed channels for panning
	Mix_ReserveChannels( 0 );

   // close the audio device
	Mix_CloseAudio();

	return OC_ERR_FREE;
}


   /*====================================================================*/
OPENCITY_ERR_CODE
AudioManager::LoadMusicList(
	const string& csrFilename,
	const string& csrPrefix )
{
// Return immediatetly if the audio device is not yet initialized
	if (boolAudioDeviceInitialized == false) {
		return OC_ERR_SOMETHING;
	}

// Set the current music index to 0
	this->uiCurrentMusic = 0;
	this->strMusicList = csrFilename;

// Now parse the music M3U file liste
	if (ParseM3UList(csrFilename, this->vectorMusicFilename, this->uiNumberMusic )
		!= OC_ERR_FREE)
		return OC_ERR_SOMETHING;

// Add the prefix
	uint uiVectorSize = vectorMusicFilename.size();
	for (uint i = 0; i < uiVectorSize; i++) {
		this->vectorMusicFilename[i] = csrPrefix + this->vectorMusicFilename[i];
	} // for

	return OC_ERR_FREE;
}


   /*====================================================================*/
const uint &
AudioManager::GetNumberMusic(void) const
{
	return this->uiNumberMusic;
}


   /*====================================================================*/
bool
AudioManager::PlayingMusic(void) const
{
	return Mix_PlayingMusic();
}


   /*====================================================================*/
OPENCITY_ERR_CODE
AudioManager::PlayMusic(
	const uint & rcuiMusicIndex,
	const int & rciLoops )
{
   // return immediatetly if the audio device is not yet initialized
	if (boolAudioDeviceInitialized == false) {
		return OC_ERR_SOMETHING;
	}

   // if the music is disabled then we return
	if (boolMusicEnabled == false) {
		return OC_ERR_SOMETHING;
	}

	if (rcuiMusicIndex >= this->uiNumberMusic) {
		OPENCITY_DEBUG( "Audio play music error" );
		return OC_ERR_SOMETHING;
	}
	else {
	   // if there's a playing music, stop it
	   // and free the music loaded
		if (pMusicData != NULL) {
			if (PlayingMusic())
				StopMusic();
//WARNING: this is buggy
			Mix_FreeMusic( pMusicData );
			pMusicData = NULL; // safe
		}

	   // load the new music
		OPENCITY_DEBUG( vectorMusicFilename[ rcuiMusicIndex ].c_str() );
		pMusicData = Mix_LoadMUS(
			this->vectorMusicFilename[ rcuiMusicIndex ].c_str() );
		if (pMusicData == NULL) {
			return OC_ERR_SOMETHING;
		}
		OPENCITY_DEBUG("Music succesfully loaded ");

		if (Mix_PlayMusic( pMusicData, rciLoops ) < 0) {
			return OC_ERR_SOMETHING;
		}
		else {
		   // set the current music to rcuiMusicIndex
		   // in case this function is called directly
		   // by the user with a music file index
			this->uiCurrentMusic = rcuiMusicIndex;
		}
	} // rcuiMusicIndex OK

	OPENCITY_DEBUG("Start playing music");
	return OC_ERR_FREE;
}


   /*====================================================================*/
OPENCITY_ERR_CODE
AudioManager::PlayNextMusic(
	const int & rciLoops )
{
	if ( uiNumberMusic > 0 ) {
	   // is random function activated ?
		if ( boolRandomMusic == true ) {
			uiCurrentMusic = rand() % uiNumberMusic;
		}
		else {
			if ( this->uiCurrentMusic < this->uiNumberMusic-1 ) {
				uiCurrentMusic++;
			}
			else {
				uiCurrentMusic = 0;
			}
		}

		return PlayMusic( uiCurrentMusic, rciLoops );
	}

	return OC_ERR_SOMETHING;
}


   /*====================================================================*/
OPENCITY_ERR_CODE
AudioManager::PlayPreviousMusic(
	const int & rciLoops )
{
	if ( uiNumberMusic > 0 ) {
	   // is random function activated ?
		if ( boolRandomMusic == true ) {
			uiCurrentMusic = rand() % uiNumberMusic;
		}
		else {
			if (this->uiCurrentMusic > 0) {
				uiCurrentMusic--;
			}
			else {
				uiCurrentMusic = uiNumberMusic-1;
			}
		}

		return PlayMusic( uiCurrentMusic, rciLoops );
	}

	return OC_ERR_SOMETHING;
}


   /*====================================================================*/
void
AudioManager::StopMusic(void) const
{
	Mix_HaltMusic();
}


   /*====================================================================*/
void
AudioManager::ToggleRandomMusic(void)
{
	boolRandomMusic = !boolRandomMusic;
}


   /*====================================================================*/
void
AudioManager::ToggleMusic(void)
{
	boolMusicEnabled = !boolMusicEnabled;

	if (boolMusicEnabled == false) {
		if (this->PlayingMusic() == true)
			this->StopMusic();
	}
	else {
		if (this->PlayingMusic() == false)
			this->PlayMusic( uiCurrentMusic, 1 );
	}
}


   /*====================================================================*/
void
AudioManager::VolumeMusic(
	const int & rciVol ) const
{
   // set the volume of the music channel to rciVol
	Mix_VolumeMusic( rciVol );
}








   /*====================================================================*/
OPENCITY_ERR_CODE
AudioManager::LoadSoundList(
	const string& csrFilename,
	const string& csrPrefix )
{
// Return immediatetly if the audio device is not yet initialized
	if (boolAudioDeviceInitialized == false) {
		return OC_ERR_SOMETHING;
	}

// Save the filename of the list
	this->strSoundList = csrFilename;

// Now parse the list
	if (ParseM3UList(csrFilename, _vSoundFilename, this->uiNumberSound )
	 == OC_ERR_SOMETHING) {
	   // list parsing error
		return OC_ERR_SOMETHING;
	}

// Free any old vector of sounds loaded
	if (!_vpSoundChunk.empty()) {
		uint uiVectorSize = _vpSoundChunk.size();
		for (uint i = 0; i < uiVectorSize; i++) {
			Mix_FreeChunk(_vpSoundChunk[i]);
		} // for
		_vpSoundChunk.clear();
	} // if

// Then load all the new sounds
	for (uint i = 0; i < this->uiNumberSound; i++) {
	// Store all pointer's values even if that's NULL;
		_vpSoundChunk.push_back( Mix_LoadWAV((csrPrefix+_vSoundFilename[i]).c_str()) );
	}

// Even if some sound files don't exist
	return OC_ERR_FREE;
}


   /*====================================================================*/
const uint &
AudioManager::GetNumberSound(void) const
{
	return this->uiNumberSound;
}


   /*====================================================================*/
OPENCITY_ERR_CODE
AudioManager::PlaySound(
	const uint & rcuiSoundIndex,
	const AUDIO_CHANNEL & enumChannel )
{
   // return immediatetly if the audio device is not yet initialized
	if (boolAudioDeviceInitialized == false) {
		return OC_ERR_SOMETHING;
	}

   // if sound is disabled then we return
	if (boolSoundEnabled == false) {
		return OC_ERR_SOMETHING;
	}

	if (rcuiSoundIndex >= this->uiNumberSound) {
		OPENCITY_DEBUG( "Audio play sound error" );
		return OC_ERR_SOMETHING;
	}

	if (_vpSoundChunk[ rcuiSoundIndex ] == NULL) {
		OPENCITY_DEBUG( "The sound chunk is null" );
		return OC_ERR_SOMETHING;
	}

	// play the sound once
	if (Mix_PlayChannel( enumChannel, _vpSoundChunk[ rcuiSoundIndex ], 0 ) == -1) {
		OPENCITY_DEBUG( "Could not play the sound" );
		return OC_ERR_SOMETHING;
	}

	// re-register effects for next use
	switch ( enumChannel ) {
	case AUDIO_LEFT_CHANNEL:
		Mix_SetPanning( enumChannel, 254, 1 );
		break;
	case AUDIO_LEFT_HALF_CHANNEL:
		Mix_SetPanning( enumChannel, 254, 127 );
		break;
	case AUDIO_RIGHT_CHANNEL:
		Mix_SetPanning( enumChannel, 1, 254 );
		break;
	case AUDIO_RIGHT_HALF_CHANNEL:
		Mix_SetPanning( enumChannel, 127, 254 );
		break;
	default:
		break;
	}

	return OC_ERR_FREE;
}


   /*====================================================================*/
void
AudioManager::ToggleSound(void)
{
	boolSoundEnabled = !boolSoundEnabled;
}


   /*====================================================================*/
void
AudioManager::VolumeSound(
	const int & rciVol ) const
{
   // set the volume of all channels to rciVol
	Mix_Volume( -1, rciVol );
}







   /*====================================================================*/
OPENCITY_ERR_CODE
AudioManager::ParseM3UList(
	const string& csrFilename,
	std::vector<string>& vectorFilename,
	uint& uiNumberFiles )
{
//debug	cout << (string)csrFilename << endl;
// If there's already an old list, free it
	if (!vectorFilename.empty()) {
		vectorFilename.clear();
		uiNumberFiles = 0;
	}

// If we are here, uiNumberFiles must be 0

// Open the ifstream for reading
	std::ifstream listFile( csrFilename.c_str() );
	if (listFile == NULL) {
		OPENCITY_DEBUG( "Audio file list open error" );
		return OC_ERR_SOMETHING;
	}

	char tempStr [OC_MAX_FILENAME_LENGTH];
	do {
	// Read the next info line
		listFile.getline( tempStr, OC_MAX_FILENAME_LENGTH );
		if ((strlen(tempStr) != 0)
		 && (tempStr[0] != '#')) {
		// Implicite conversion from char* to string
			vectorFilename.push_back( tempStr );
			uiNumberFiles++;
//debug	cout << tempStr << endl;
		}
	}
	while (!listFile.eof());

	listFile.close();
	return OC_ERR_FREE;
}


























