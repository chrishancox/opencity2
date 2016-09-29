------------------------------------------------------------------------------
L�EME para OpenCity 0.0.5stable
------------------------------------------------------------------------------
�ltima modificaci�n:
	$Id: README_es.txt 375 2008-10-28 14:47:15Z neoneurone $

Orientado a:
	# Usuarios Finales:
		Puedes encontrar bastante informaci�n �til en este archivo. �L�elo!
	# Desarrolladores:
		Este archivo contiene informaci�n �til para las opciones a trav�s de 
		la l�nea de comandos.
		Para ayuda con la compilaci�n e instalaci�n, por favor, comprueba el
		archivo "INSTALL".

Descripci�n:
	OpenCity es, otro simulador m�s de ciudades. La idea es bastante simple: 
	tienes que construir una ciudad con 3 tipos de "zonas":
	Residenciales, Comerciales e Industriales.
	Cada una depende de la otra durante su construcci�n. Intenta conseguir
	todo lo que necesitas y podr�s ver c�mo crece tu ciudad.


------------------------------------------------------------------------------
Requisitos de Hardware:
------------------------------------------------------------------------------
Procesador:
	No importa

Velocidad:
	Cualquiera

Tarjeta Gr�fica:
	Se necesita una tarjeta aceleradora 3D.

Tarjeta de Sonido:
	Cualquiera que pueda funcionar con "SDL_mixer"

Red:
	Soporte experimental


------------------------------------------------------------------------------
Requisitos de Software:
------------------------------------------------------------------------------
Sistema Operatvo:
	Linux (recomendado)
	o Mac OS o superior,
	o Microsoft Windows XP/2000 o superior,
	o Wine

Interfaz Gr�fica de Usuario:
	X Windows con DRI activado (recomendado)
	o Darwin
	o Microsotf Windows
	o Wine

Librer�as:
	GL (OpenGL)
	GLU
	SDL
	SDL_image
	SDL_net
	SDL_mixer (opcional)


------------------------------------------------------------------------------
Notas de la publicaci�n del auto-empaquetado para Linux:
------------------------------------------------------------------------------
	�Has descargado el archivo "opencity-x-y-z_algo.package"?
Dale permiso de ejecuci�n eligiendo el comando "chmod" correcto (consulta
tu distribuci�n para conseguir m�s informaci�n sobre el comando "chmod")
	
	Ahora �brelo desde la consola o en un navegador de archivos (P.E. Konqueror). 
OpenCity se instalar� en tu ordenador, y se crear� un icono dentro del grupo
"Juegos".
	
	Despu�s de la instalaci�n, puedes abrir OpenCity pulsando en su icono o 
escribiendo "opencity" en tu consola favorita.


------------------------------------------------------------------------------
Notas de la publicaci�n del binario para Microsoft Windows:
------------------------------------------------------------------------------
	Para poder jugar a OpenCity, debes instalarlo primero. Una vez lo hayas 
	hecho, pulsa en el icono OpenCity en el men� de inicio para comenzar.

------------------------------------------------------------------------------
Descripci�n de los controles
------------------------------------------------------------------------------
Atajos del teclado:
		n: Herramienta en "Blanco"
		r: Herramienta Zona Residencial
		c: Herramienta Zona Comercial
		i: Herramienta Zona Industrial
		p: Herramienta carretera
		l: Herramienta l�neas el�ctricas
		x: Herramienta Destruir
		q: Herramienta Consulta
		e: Construir una central el�ctrica de carb�n
		ctrl: cancelar la acci�n de la herramienta seleccionada
	
		u / d: Herramienta aumentar / disminuir terreno

Navegaci�n:
		arriba/abajo/izquierda/derecha: mover el mapa
		avpag/repag: Rotar el mapa
		insertar/suprimir: Alejar / acercar Zoom
		alt: Multiplicar los efectos de los botones por 10
	
		h: Inicio
		escape: Activar/desactivar men� principal

Opciones:
		b: Activar/desactivar mostrar edificios
		g: Activar/desactivar mostrar grilla
		k: Activar/desactivar mostrar la barra de estado principal
		f: Activar/desactivar mostrar en modo grilla
		o: Activar/desactivar mostrar proyecci�n perspectiva/octogonal
		t: Activar/desactivar mostrar terreno
		w: Activar/desactivar mostrar agua

Sonido y m�sica:
		</>: reproducir canci�n anterior/siguiente
		m: Activar/desactivar la m�sica
		s: Activar/desactivar sonidos

Experimental:
		F2: Guardar
		F6: Cargar

Opciones indocumentadas (pru�balas bajo tu propio riesgo):
		a: Men� con varios c�digos de prueba
		v: Men� de prueba MAS
		z: Conectar al servidor ZeN local


------------------------------------------------------------------------------
Sonido y m�sica
------------------------------------------------------------------------------
	OpenCity usa "SDL_mixer" para reproducir los sonidos y la m�sica. A s� que,
deber�a soportar todos los tipos de archivo que admita el "SDL_mixer".

	Si no escuchas ning�n sonido, intenta modificar el archivo "sound.m3u" y
configura el directorio acorde con tu archivo ejecutable de OpenCity.

	Por favor, ten en cuenta que OpenCity autom�ticamente a�ade un "prefijo" a
todos los nombres de los archivos de audio. El prefijo es el directorio donde 
el proceso de instalaci�n haya guardado los archivos de OpenCity.

	Sin embargo, puedes poner un archivo llamado "music.m3u" el la carpeta 
"music", y OpenCity cargar� y reproducir� tu m�sica favorita. Si no encuentras
ninguna carpeta con el nombre "music" cr�ala y pon tu lista de reproducci�n 
(con el nombre "music.m3u") en �l.

	Me gustar�a advertirte de que SDL_mixer no es extremadamente estable. Puede
"colgar" OpenCity mientras reproduce algunos tipos de archivos ".mp3". Pero 
ninguno de los tipos que crearon "SDL_mixer" soy yo!! :P. Si te da problemas, tan
s�lo apaga la m�sica (tecla 'm').


------------------------------------------------------------------------------
Acciones del rat�n
------------------------------------------------------------------------------
	En OpenCity, en cualquier lado donde pulses el BDR (Bot�n Derecho del Rat�n),
abrir�s el men� de herramientas circular. Pulsa el BDR de nuevo para cerrarlo.
Estamos intentando hacer todo m�s simple y sencillo pero algunas veces necesitar�s
el teclado.

	�OpenCity tambi�n soporta la rueda del rat�n! Hazla girar hacia delante para 
acercar el zoom (tecla 'insertar') y g�rala hacia atr�s para alejar el
zoom (tecla 'suprimir').

	Cuando quedes pulsado la tecla 'May�sculas' y juegues con la rueda del rat�n 
te dar�s cuenta de que el mapa se desliza en alguna direcci�n. Pulsando la tecla
'Ctrl' desliza el mapa en la otra direcci�n.


------------------------------------------------------------------------------
Archivo de configuraci�n principal "opencity.xml"
------------------------------------------------------------------------------
	Mira los comentarios dentro del archivo para obtener m�s detalles.


------------------------------------------------------------------------------
Opciones de la l�nea de comandos
------------------------------------------------------------------------------
	En OpenCity, puedes sobrescribir las opciones del archivo de configuraci�n
con las opciones de la l�nea de comandos. Algunas opciones est�n disponibles
tanto en m�todo abreviado como en completo.

	-fs | --full-screen
	Habilita el modo pantalla completa

	-glv | --gl-version
	Muestra la informaci�n OpenGL de tu m�quina y cierra

	-dd | --data-dir newDataPath
	Especifica la carpeta con los datos de OpenCity. Por ejemplo:
		Bajo Linux: --data-dir /home/foo/bar/share/opencity/
		Bajo Win32: --data-dir "C:/Archivos de programa/OpenCity/share"

	-cd | --conf-dir newConfigPath
	Especifica la carpeta con la configuraci�n de OpenCity. Por ejemplo:
		Bajo Linux: --conf-dir /home/foo/bar/etc/opencity/
		Bajo Win32: --conf-dir "C:/Archivos de programa/OpenCity/etc"

	-na | --no-audio:
	Deshabilita el sistema de audio

	--generator-seed seed
	La semilla que ser� usada para generar el mapa

	--generator-map MAP-TYPE
		Tipo de terreno     : 0=plano (defecto), 1=colina, 2=monta�a

	--generator-water WATER-TYPE
		Tipo de agua        : 0=seco, 1=lago (defecto), 2=costa

	--generator-map-shape MAP-SHAPE-TYPE
		Tipo de forma       : 0=ninguna (defecto), 1=isla, 2=volc�n, 3=crater

	--generator-tree-density TREE-DENSITY-TYPE
		Densidad de �rboles : 0=sparse (default), 1=normal, 2=dense

	--generator-height-map heightMapPicture
	Carga una imagen a escala de grises (PNG) como mapa de altura.
El nivel del agua es gris (128), cada nivel de mapa es un niv�l de gris, es por
ello que la imagen completa debe estar en un gris medio, ya que s�lo hay una
peque�a diferencia entre los p�xeles. Puedes dibujar tu mismo el mapa de altura
o generarlo desde cualquier fuente de mapas. Esto puede ser interesante para
trabajar con datos DEM (de sat�lite). El generador de mapas de OpenCity 
cortar� la imagen si es demasiado grande.


------------------------------------------------------------------------------
Dudas de Guardar/Cargar
------------------------------------------------------------------------------
	La siguiente carpeta es usada para guardar y cargar:

		* GNU/Linux:
			$HOME/.OpenCity/

		* Windows:
			C:\Documents and Settings\nombreusuario\Application Data\OpenCity\
			Si est�s ejecutando una versi�n localizada (en otro idioma) de 
			Windows la direcci�n de tu carpeta podr�a ser diferente

		* Windows Vista:
			C:\Users\username\AppData\Roaming\OpenCity\


------------------------------------------------------------------------------
Soluci�n de problemas
------------------------------------------------------------------------------
	1) Tengo una tarjeta g�fica ATI Radeon 9000 M en mi PC.
Cuando he probado el juego con la opci�n "EnablePageFlip" (mirar manual radeon)
el juego funcionaba mal. si encuentras el mismo problema, intenta deshabilitar 
esta opci�n en el servidor XFree (ver manual XF86Config)

	2) Con la tarjeta gr�fica ATI Radeon 9000M, SmoothVision(tm) debe ser 
desactivado para poder jugar correctamente a OpenCity.

	3) Aqu� est� la versi�n de mi servidor X

 - XFree86 Versi�n 4.3.0
 - Fecha de lanzamiento: 9 May 2003
 - X Protocol Version 11, Revision 0, Release 6.6
 - Build Operating System: Linux 2.4.18-23mdksmp i686 [ELF]
 - Build Date: 10 September 2003

	Parece que el driver para mi ATI Radeon 9000 M tiene muchos fallos. Si
experimentas estos problemas, intenta escribir esto en la consola (bash)
antes de lanzar OpenCity.
		"export R200_NO_VTXFMT="

	O deber�as probar una nueva versi�n de XFree.


------------------------------------------------------------------------------
Duong Khang (neoneurone) NGUYEN
Traducci�n al Espa�ol by: Cristian Deluxe (djcristiandeluxe at gmail.com)