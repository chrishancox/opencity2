------------------------------------------------------------------------------
README for OpenCity 0.0.6stable
------------------------------------------------------------------------------
Last modified:
	$Id: README.txt 378 2008-10-30 22:52:37Z neoneurone $

Audience:
	# End-users:
		You can find a lot of useful information in this file. So read it !
	# Packagers:
		This file contains useful information about command line options.
		For compilation and installation notes please refer to the
		INSTALL file.

Description:
	This is just another city simulation. The idea is simple: you have to
build a city with 3 types of "zones" Residential, Commercial and Industrial.
They depend on each other during their development. Try to give them what
they need and watch your city growing up.


------------------------------------------------------------------------------
Hardware requirements:
------------------------------------------------------------------------------
Processor:
	never mind

Speed:
	whatever

Graphic card:
	3D accelerated card strongly recommended

Sound card:
	anything that can work with SDL_mixer

Network:
	experimental support


------------------------------------------------------------------------------
Software requirements:
------------------------------------------------------------------------------
Operating System:
	Linux (recommended)
	or Mac OS or later
	or Microsoft Windows XP/2000 or later
	or Wine

Graphic User Interface:
	X Windows with DRI activated (recommended)
	or Darwin
	or Microsoft Windows with OpenGL support
	or Wine

Libraries:
	GL (OpenGL)
	GLU
	SDL
	SDL_image
	SDL_net
	SDL_mixer (optional)


------------------------------------------------------------------------------
Linux autopackage release's notes:
------------------------------------------------------------------------------
	Have you just downloaded the "opencity-x.y.zsomething.package" stuff ?
Give it the run permission by issuing the correct "chmod" command (refer to
your Linux distribution for more information about the "chmod" command)

	Now run it from the console or in a file browser like Konqueror. OpenCity
will be installed on your computer, and an icon will be created inside the
"Game" group.

	After installation, you can launch OpenCity by clicking on its icon or
typing "opencity" in your favorite console.


------------------------------------------------------------------------------
Microsoft Windows binary release's notes:
------------------------------------------------------------------------------
	In order to play the game, you must install it first. Once it's done,
click on the OpenCity's icon in the start menu to begin.


------------------------------------------------------------------------------
Keys' description
------------------------------------------------------------------------------
Hotkey:
		n: "Blank" tool
		r: Zone Residential tool
		c: Zone Commercial tool
		i: Zone Industrial tool
		p: Lay Paths tool
		l: Lay electric Lines tool
		x: Destroy tool
		q: Query tool
		e: Build a coal power plant
		ctrl: cancel the zoning tool action
	
		u / d: raise / lower cells tool

Navigation:
		up / down / left / right: move the map
		pageup / pagedown: rotate the map
		insert / delete: zoom in/out
		alt: multiply the effects of the buttons above by 10
	
		h: as Home
		escape: toggle the main menu

Option:
		b: Toggle building display on/off
		g: Toggle grid display on/off
		k: Toggle the main status bar display on/off
		f: Toggle wire frame mode display on/off
		o: Toggle perspective/orthogonal projection
		t: Toggle terrain display on/off
		w: Toggle water display on/off

Sound & music:
		< / >: play previous / next music
		m: music on / off
		s: sound on / off

Experimental:
		F2: Save
		F6: Load

Undocumented features, try it at your own risks:
		a: various test codes menu
		v: MAS test menu
		z: connect to the local ZeN server


------------------------------------------------------------------------------
Sound & music
------------------------------------------------------------------------------
	OpenCity uses SDL_mixer for playing sound & music. Thus, it supports
all file types that SDL_mixer supports.

	If you don't hear any sound, try to modify "sound.m3u" and
set the path accordingly to the "opencity" executable file. Please note
that OpenCity automatically appends a prefix to all the sound filenames.
The prefix is where the installation procedure has put all OpenCity's data
files.

	However, you can put a file called "music.m3u" in the "music" directory
and OpenCity will load and play your favorite musics. If you don't find
any "music" directory just create it then put your list "music.m3u" in it.

	I'd like to warn you that SDL_mixer is not that stable. It can hang
OpenCity while playing few kinds of ".mp3" song. Blame the SDL_mixer's 
guys not me ;) If you experience such a problem, just turn the music 
off (key 'm').


------------------------------------------------------------------------------
Mouse action
------------------------------------------------------------------------------
	In OpenCity, whenever you click the RMB (Right Mouse Button), you will
open the toolcircle. Click RMB again to hide the toolcircle. I try to make
everything simple and handy. But sometimes you still need your keyboard.

	OpenCity also understands the mouse's wheel ! Push the wheel forward
does a zoom in (as 'Insert' key) and roll the wheel backward does a
zoom out (as 'Delete' key).

	When you hold 'Shift' and play with your mouse's wheel you'll notice
that it translates the map in some direction. Whereas the 'Ctrl' button
translates the map along another axis.


------------------------------------------------------------------------------
Main config file "opencity.xml"
------------------------------------------------------------------------------
	See the in-line comments for more details.


------------------------------------------------------------------------------
Command-line options
------------------------------------------------------------------------------
	In OpenCity, you can overwrite the config file's options with the
command-line options. Few options are available in both short and long format.

	-fs | --full-screen
	Enable fullscreen mode. The video resolution is read from the config.xml
file. If the resolution width and height are both 0, OpenCity will try to
autodetect the best available fullscreen resolution.

	-glv | --gl-version
	Show the OpenGL driver information (vendor, renderer, version and extension)

	-gld | --gl-driver openGLDriverName
	Try to load the given driver name. Under Windows, it should be something
like opengl32.dll	

	-dd | --data-dir newDataPath
	Specify to new path to OpenCity's data. For example:
		Under linux: --data-dir /home/foo/bar/share/opencity/
		Under win32: --data-dir "C:/Program Files/OpenCity/share"

	-cd | --conf-dir newConfigPath
	Specify to new path to OpenCity's config. For example:
		Under linux: --conf-dir /home/foo/bar/etc/opencity/
		Under win32: --conf-dir "C:/Program Files/OpenCity/etc"

	-na | --no-audio:
	Disable the audio system

	--generator-seed seed
	The seed is the random integer seed used by the map generator

	--generator-map MAP-TYPE
		MAP-TYPE         : 0=plain (default), 1=hill, 2=mountain

	--generator-water WATER-TYPE
		WATER-TYPE       : 0=dry, 1=lake (default), 2=coast

	--generator-map-shape MAP-SHAPE-TYPE
		MAP-SHAPE-TYPE   : 0=none (default), 1=island, 2=volcano, 3=crater

	--generator-tree-density TREE-DENSITY-TYPE
		TREE-DENSITY-TYPE: 0=sparse (default), 1=normal, 2=dense

	--generator-height-map heightMapPicture
	Load a gray-level picture as height map (PNG). The water level is gray
level 128, each map level is one gray level. That's why the whole picture seems
to be in a medium gray, because there's only a minor difference between the
pixels. You can draw yourself the height-map or generate from any map sources.
The interesting data for this work are the DEM satellite data. The map
generator in OpenCity will crop the picture if it's too big.


------------------------------------------------------------------------------
Heightmap package
------------------------------------------------------------------------------
	OpenCity is packaged with few heightmaps which are generated from
satellite's data. Here is the full list:

	Athenes-1024x1024.png
	Athenes-51x51.png
	Dakar-51x51.png
	Ibiza-101x101.png
	Istanbul-1025x1025.png
	Mallorca-93x61.png
	Palermo-51x51.png
	Sao_Tome-101x101.png
	Strasbourg-1025x1025.png
	Woodstock-51x51.png

	In order to load those heightmaps, you have to give a command-line option
to OpenCity. For example:

	opencity --generator-height-map map/heightmap/Athenes-51x51.png

	Currently, heightmap loading still is an experimental feature, try 
at your own risks.


------------------------------------------------------------------------------
Save/Load issues
------------------------------------------------------------------------------
	The following directory is used for save/load

		* GNU/Linux:
			$HOME/.OpenCity/

		* Windows:
			C:\Documents and Settings\username\Application Data\OpenCity\
			If you are running a localized version of Windows, the above
		path may be different

		* Windows Vista:
			C:\Users\username\AppData\Roaming\OpenCity\


------------------------------------------------------------------------------
Troubleshootings
------------------------------------------------------------------------------
	1) I have a ATI Radeon 9000 M video card on my machine.
When I tested the game with "EnablePageFlip" ( see man radeon )
the game works weirdly. If you encounter the same problem,
try to disable this feature of the XFree server ( see man XF86Config )

	2) With ATI Radeon 9000M video card, the SmoothVision(tm)
must be deactivated in order to run OpenCity correctly.

	3) Here is the version of my X server

 - XFree86 Version 4.3.0
 - Release Date: 9 May 2003
 - X Protocol Version 11, Revision 0, Release 6.6
 - Build Operating System: Linux 2.4.18-23mdksmp i686 [ELF]
 - Build Date: 10 September 2003

	It seems that the driver for my ATI Radeon 9000 M is
very buggy. If you experience any trouble, try to type this
in the shell (bash) before launching OpenCity.
		"export R200_NO_VTXFMT="

	Or you should try a newer XFree.


------------------------------------------------------------------------------
Duong Khang (neoneurone) NGUYEN


