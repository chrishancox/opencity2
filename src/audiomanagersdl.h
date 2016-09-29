/***************************************************************************
						audiomanagersdl.h  -  description
							-------------------
	begin                : december 26th, 2003
	copyright            : (C) 2003-2008 by Duong Khang NGUYEN
	email                : neoneurone @ gmail com

	$Id: audiomanagersdl.h 375 2008-10-28 14:47:15Z neoneurone $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

#ifndef _OPENCITY_AUDIOMANAGERSDL_H_
#define _OPENCITY_AUDIOMANAGERSDL_H_ 1

#include "main.h"

#include "SDL_mixer.h"
#include <vector>

#define OC_AUDIO_FREQUENCY  44100         // CD quality
#define OC_AUDIO_FORMAT     AUDIO_S16SYS  // host system signed byte order
#define OC_AUDIO_CHANNELS   2             // 2 channels for stereo
#define OC_AUDIO_CHUNK_SIZE 4096          // mixer's sample chunk size

#define OC_AUDIO_MIX_CHANNELS 8           // total number of mix channels
#define OC_AUDIO_RESERVED_CHANNELS 4      // reserved channels for sound effects

#define OC_AUDIO_VOLUME_MIN 0
#define OC_AUDIO_VOLUME_MAX MIX_MAX_VOLUME

#define OC_MAX_FILENAME_LENGTH 255


//========================================================================
/** Handles audio aspect of OpenCity. Thanks to SDL_Mixer, it can play
most popular types of sound and music files.
*/
class AudioManager {
public:
/// This is for LR panning effects
	enum AUDIO_CHANNEL {
		AUDIO_CENTER_CHANNEL = -1,
		AUDIO_LEFT_CHANNEL = 0,
		AUDIO_LEFT_HALF_CHANNEL = 1,
		AUDIO_RIGHT_CHANNEL = 3,
		AUDIO_RIGHT_HALF_CHANNEL = 2
	};

	AudioManager();
	~AudioManager();

   //========================================================================
   /** WARNING: this method must be called before any use of AudioManager
   */
	OPENCITY_ERR_CODE OpenAudio(void);
	OPENCITY_ERR_CODE CloseAudio(void);

   //========================================================================
   /** Set the internal filename to the given M3U music list
   */
	OPENCITY_ERR_CODE
	LoadMusicList(
		const string& csrFilename,
		const string& csrPrefix = "" );

	const uint &
	GetNumberMusic(void) const;

	bool
	PlayingMusic(void) const;

	OPENCITY_ERR_CODE
	PlayMusic(
		const uint & rcuiMusicIndex,
		const int & rciLoops = 1 );

	OPENCITY_ERR_CODE
	PlayNextMusic(
		const int & rciLoops = 1 );

	OPENCITY_ERR_CODE
	PlayPreviousMusic(
		const int & rciLoops = 1 );

	void
	StopMusic(void) const;

	void
	ToggleRandomMusic(void);

	void
	ToggleMusic(void);

	void
	VolumeMusic( const int & rciVol ) const;


   //========================================================================
   /** Set the internal filename to the given M3U sound list.
       In constrast of LoadMusicList(), it loads all the sounds specified
       by the music list into memory for better performance.
   */
	OPENCITY_ERR_CODE
	LoadSoundList(
		const string& csrFilename,
		const string& csrPrefix = "" );

	const uint &
	GetNumberSound(void) const;

	OPENCITY_ERR_CODE
	PlaySound(
		const uint & rcuiSoundIndex,
		const AUDIO_CHANNEL & enumChannel = AUDIO_CENTER_CHANNEL );

	void
	ToggleSound(void);

	void
	VolumeSound( const int & rciVol ) const;



private:
	bool boolAudioDeviceInitialized;
	bool boolMusicEnabled;
	bool boolSoundEnabled;
	bool boolRandomMusic;

	string strSoundList;
	std::vector<string> _vSoundFilename;
	std::vector<Mix_Chunk*> _vpSoundChunk;
	uint uiNumberSound;

	string strMusicList;
	std::vector<string> vectorMusicFilename;
	uint uiNumberMusic;
	uint uiCurrentMusic;
	bool boolShuffleMusic;
	Mix_Music* pMusicData;


   /*=====================================================================*/
   /*                        PRIVATE     METHODS                          */
   /*=====================================================================*/
	OPENCITY_ERR_CODE
	ParseM3UList(
		const string & csrFilename,
		std::vector<string> & vectorFilename,
		uint & uiNumberFiles );

};

#endif













