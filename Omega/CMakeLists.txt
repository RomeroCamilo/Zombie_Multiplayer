set(HEADER_FILES
 	include/Omega.h
	OmegaApp.h
	Utilities.h
	GameWindow.h
	WindowImplementation.h
	GLFWCode/GLFWImplementation.h
	GLFWCode/OpenGLPicture.h
	GLFWCode/OpenGLRenderer.h
	GLFWCode/OpenGLShader.h
	Picture.h
	PictureImplementation.h
	Renderer.h
	RendererImplementation.h
	Shader.h
	ShaderImplementation.h
	Unit.h
	Utilities.h
	WindowImplementation.h	
)

set(SOURCE_FILES
	Events.cpp
	GameWindow.cpp
	GLFWCode/GLFWImplementation.cpp
	GLFWCode/OpenGLPicture.cpp
	GLFWCode/OpenGLRenderer.cpp
	GLFWCode/OpenGLShader.cpp
	Picture.cpp
	Renderer.cpp
	Shader.cpp
	Unit.cpp
)

add_definitions(-DOMG_DEBUG=2)
add_definitions(-DOMEGA_LIB)

include_directories(../Omega)
include_directories(../glfw/include)
include_directories(../glad/include)
include_directories(../stbi)

add_library(Omega SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Omega PRIVATE pch.h)

target_link_libraries(Omega glfw)
target_link_libraries(Omega glad)
target_link_libraries(Omega stbi)