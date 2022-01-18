######################################################################################################
# Setting up the project

	##################################################################################################
	# C Make Minimum Version
		
		cmake_minimum_required(VERSION 3.14)
	#
	##################################################################################################
	# Project Name Version and Languaje, print and add preprocessor flag
		
		project(CPString VERSION 0.0.1 LANGUAGES CXX)
		message("Building ${PROJECT_NAME} Version = ${PROJECT_VERSION}...")
		
		string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPER)
		#add_definitions( -D${PROJECT_NAME_UPPER}_VERSION="${CMAKE_PROJECT_VERSION}" )
	#
	##################################################################################################
	# Set up C++ Version

		set(CMAKE_CXX_STANDARD 14) 
		set(CMAKE_CXX_STANDARD_REQUIRED ON)
	#
	##################################################################################################
#
######################################################################################################
# Compile Configuration

	set(CPSTRING_BUILD_EXAMPLES TRUE CACHE BOOL "Build CPString Examples")
#
######################################################################################################
# Append Source

	add_subdirectory(src)
	target_compile_definitions(CPString INTERFACE ${PROJECT_NAME_UPPER}_VERSION="${PROJECT_VERSION}" )
#
######################################################################################################
# Compile Configuration

	if( ${CPSTRING_BUILD_EXAMPLES} )
		message("Building ${CMAKE_PROJECT_NAME} Examples...")
		add_subdirectory(examples)
	endif()
#
######################################################################################################

	