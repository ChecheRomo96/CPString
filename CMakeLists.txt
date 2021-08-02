cmake_minimum_required(VERSION 3.14)

project(EString VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

if( ESTRING_BUILD_EXAMPLES  STREQUAL "ON")
	add_subdirectory(examples)
endif()