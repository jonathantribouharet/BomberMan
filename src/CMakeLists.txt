cmake_minimum_required(VERSION 2.6)
project("BomberMan")

find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)
find_package(SDL_ttf REQUIRED)

if(APPLE)
	message(STATUS "Mac OS detected")

	include_directories("/Library/Frameworks/SDL.framework/headers"
						"/Library/Frameworks/SDL_image.framework/headers"
					    "/Library/Frameworks/SDL_ttf.framework/headers")
					    
	file(GLOB_RECURSE sources *.cpp *.m)
else()
	message(STATUS "Linux detected")

	include_directories("/usr/include/SDL")

	file(GLOB_RECURSE sources *.cpp)
endif()

if(CMAKE_COMPILER_IS_GNUCC)
	message(STATUS "Use gcc compiler")

	set(CMAKE_CXX_FLAGS "-Wall -O3 -s")
	#set(CMAKE_CXX_FLAGS "-Wall -DDEBUG")
else()
	message(STATUS "Use clang compiler")

	set(CMAKE_CXX_FLAGS "-Wall -O3")
	#set(CMAKE_CXX_FLAGS "-Wall -DDEBUG")
endif()

include_directories(Actions)
include_directories(Collisions)
include_directories(Components)
include_directories(Contexts)
include_directories(Engines)
include_directories(Loaders)
include_directories(Utils)

add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} ${SDL_LIBRARY} ${SDLIMAGE_LIBRARY} ${SDLTTF_LIBRARY})
