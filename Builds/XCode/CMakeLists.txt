cmake_minimum_required(VERSION 3.14)
project(EStringXcode CXX)
set(CMAKE_CXX_STANDARD 14) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

include_directories(src/EmbeddedString)
include_directories(src/EmbeddedString/EmbeddedString_Flash)

add_executable( EStringXcode main.cpp ) 
target_link_libraries( EStringXcode EString )
