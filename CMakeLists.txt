cmake_minimum_required(VERSION 3.14)

project(CPString VERSION 1.0.0 LANGUAGES CXX)

set_target_properties(
	CPString PROPERTIES
	SOVERSION 0
	VERSION 0.0.1
)

set(CMAKE_CXX_STANDARD 14) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

if( CPSTRING_BUILD_EXAMPLES  STREQUAL "ON")
	add_subdirectory(examples)
endif()