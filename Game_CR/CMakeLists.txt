set(HEADER_FILES
 	
)

set(SOURCE_FILES
	main.cpp
)

add_executable(Game_CR ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(Game_CR Omega)

include_directories(../Omega/include)