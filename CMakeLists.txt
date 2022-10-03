cmake_minimum_required(VERSION 3.0)
project(MYENGINE)

include_directories(
	src
)

add_library(myengine
	src/myengine/myengine.h
	src/myengine/Core.h

	src/myengine/Core.cpp
)

add_executable(game
	src/game/main.cpp
)

target_link_libraries(game myengine)