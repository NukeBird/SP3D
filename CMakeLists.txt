cmake_minimum_required(VERSION 3.0)
project(SP3D VERSION 0.1)

include("cmake/HunterGate.cmake")

HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.19.140.tar.gz"
    SHA1 "f2c30348c05d0d424976648ce3560044e007496c"
)

file(
	GLOB_RECURSE 
	SOURCE_LIST
	"src/*.cpp" 
	"src/*.hpp"
	"src/*.h"
)

add_library(${PROJECT_NAME} STATIC ${SOURCE_LIST})