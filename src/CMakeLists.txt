# Store this directory as a variable called ESTRING_SRC_DIRECTORY to reference in deeper directories
set( ESTRING_SRC_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})

# Initialize ESTRING_SOURCES and HEADER_LIST as an empty string list
set( ESTRING_SOURCES "" )
set( HEADERS_LIST "" )

# Append Sources
list( APPEND ESTRING_SOURCES "${CMAKE_CURRENT_LIST_DIR}/EmbeddedString.cpp")

# Append Headers
list( APPEND HEADERS_LIST "${CMAKE_CURRENT_LIST_DIR}/EmbeddedString.h")
list( APPEND HEADERS_LIST "${CMAKE_CURRENT_LIST_DIR}/EmbeddedString_BuildSettings.h")
list( APPEND HEADERS_LIST "${CMAKE_CURRENT_LIST_DIR}/EmbeddedString_Class.h")
list( APPEND HEADERS_LIST "${CMAKE_CURRENT_LIST_DIR}/EmbeddedString_Definitions.h")

# Include Flash subdirectory
add_subdirectory( EmbeddedString_Flash )

# Create the EString library (STATIC is not justified tho) and include the directories needed to compile
add_library( EString STATIC ${ESTRING_SOURCES} )

# Include directories for install and for build 
target_include_directories( 
	EString PUBLIC 
	$<INSTALL_INTERFACE:include/EString> 
	$<BUILD_INTERFACE:${ESTRING_SRC_DIRECTORY}> 
)

# EString install process
if(ESTRING_INSTALL STREQUAL "ON")

	install(
		FILES ${HEADERS_LIST} 
		DESTINATION ${CMAKE_INSTALL_PREFIX}/include/EString 
	)

	install(
		TARGETS EString 
		EXPORT EStringExport
		DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/EString
	)

	install(
		EXPORT EStringExport
		FILE EString-config.cmake
		DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/EString
	)

endif()