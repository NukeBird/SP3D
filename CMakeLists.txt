cmake_minimum_required(VERSION 3.0)

include("cmake/HunterGate.cmake")

HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.19.140.tar.gz"
    SHA1 "f2c30348c05d0d424976648ce3560044e007496c"
)

project(SP3D VERSION 0.1)

option(BUILD_TESTS "Build tests" ON) #TODO: switch default value to "OFF"

file(
	GLOB_RECURSE 
	SOURCE_LIST
	"src/*.cpp" 
	"src/*.hpp"
	"src/*.h"
)

hunter_add_package(glm)
find_package(glm REQUIRED)

add_library(${PROJECT_NAME} STATIC ${SOURCE_LIST})
target_link_libraries(${PROJECT_NAME} PUBLIC glm)

if(BUILD_TESTS)
    add_subdirectory(test)
endif(BUILD_TESTS)