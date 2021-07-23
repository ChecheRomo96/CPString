cmake_minimum_required(VERSION 3.14)
project(EStringXcode CXX)
set(CMAKE_CXX_STANDARD 14) 
#set(CMAKE_CXX_STANDARD_REQUIRED OFF)
include_directories(src/EmbeddedString)

add_subdirectory(src)


add_executable( EStringLinux main.cpp ) 
target_link_libraries( EStringLinux EString )
