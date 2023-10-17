set(HEADER_FILES
 	include/Omega.h
	OmegaApp.h
	Utilities.h
)

set(SOURCE_FILES
	placeholder.cpp
)

add_definitions(-DOMG_DEBUG=2)
add_definitions(-DOMEGA_LIB)

include_directories(../glfw/include)

add_library(Omega SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Omega PRIVATE pch.h)

target_link_libraries(Omega glfw)