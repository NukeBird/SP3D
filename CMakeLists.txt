cmake_minimum_required(VERSION 3.0)
project(SP3D VERSION 0.1)

file(
	GLOB_RECURSE 
	SOURCE_LIST
	"src/*.cpp" 
	"src/*.hpp"
	"src/*.h"
)

add_library(${PROJECT_NAME} STATIC ${SOURCE_LIST})