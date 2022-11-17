cmake_minimum_required(VERSION 3.0)
project(MYENGINE)

include_directories(
	src
	contrib/windows-cl-amd64/include
)

link_directories(
	${PROJECT_SOURCE_DIR}/contrib/windows-cl-amd64/lib
)

add_library(rend
	src/rend/Animation.h
	src/rend/Animation.cpp

	src/rend/Buffer.h
	src/rend/Buffer.cpp

	src/rend/Mesh.h
	src/rend/Mesh.cpp

	src/rend/Model.h
	src/rend/Model.cpp

	src/rend/ModelRenderer.h
	src/rend/ModelRenderer.cpp

	src/rend/RenderTexture.h
	src/rend/RenderTexture.cpp

	src/rend/Renderer.h
	src/rend/Renderer.cpp

	src/rend/Shader.h
	src/rend/Shader.cpp

	src/rend/Texture.h
	src/rend/Texture.cpp

	src/rend/rendmath.h
	src/rend/rendmath.cpp
)

target_link_libraries(rend GLEW32 OPENGL32)

add_library(myengine
	src/myengine/myengine.h

	src/myengine/Core.h
	src/myengine/Core.cpp

	src/myengine/Entity.h
	src/myengine/Entity.cpp

	src/myengine/Component.h
	src/myengine/Component.cpp

	src/myengine/TriangleRenderer.h
	src/myengine/TriangleRenderer.cpp

	src/myengine/Transform.h
	src/myengine/Transform.cpp

	src/myengine/Keyboard.h
	src/myengine/Keyboard.cpp

	src/myengine/Enviroment.h
	src/myengine/Enviroment.cpp

	src/myengine/SoundSource.h
	src/myengine/SoundSource.cpp
)

target_link_libraries(myengine rend SDL2)

target_link_libraries(myengine SDL2 SDL2main openal32)

add_executable(game
	src/game/main.cpp
)

target_link_libraries(game myengine)