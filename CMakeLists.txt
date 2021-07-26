cmake_minimum_required(VERSION 3.14)

project(EString CXX)

set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_STANDARD_REQUIRED OFF)

add_subdirectory(src)

if( ESTRING_BUILD_TESTS  STREQUAL "ON")
	add_subdirectory(tests)
endif()