CMAKE_MINIMUM_REQUIRED(VERSION 2.4.8)
SET(CMAKE_COLOR_MAKEFILE ON)
SET(CMAKE_VERBOSE_MAKEFILE ON)
SET(CMAKE_INCLUDE_CURRENT_DIR TRUE)

IF(UNIX AND NOT LINUX_SET)
 ADD_DEFINITIONS(-D LINUX)
ENDIF(UNIX AND NOT LINUX_SET)

INCLUDE_DIRECTORIES(
../tmolib/
.
)

LINK_LIBRARIES (
tmo
)

SET(TMO_SOURCES
 TMOKim09.cpp
 TMOPlugin.cpp
)


SET(TMOWARD_HEADERS
 TMOKim09.h
 TMOPlugin.h
)


add_library( Kim09 SHARED ${TMO_SOURCES} )
add_custom_command( TARGET Kim09 POST_BUILD 
	COMMAND cp -f libKim09.so ../TMOCmd/Kim09.tml
	COMMAND cp -f libKim09.so ../TMOgui/Kim09.tml 
	COMMAND cp -f libKim09.so ../Kim09.tml 
#	COMMAND rm -f libKim09.so 
	)


