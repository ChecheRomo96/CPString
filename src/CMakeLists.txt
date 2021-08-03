# Store this directory as a variable called CPSTRING_SRC_DIRECTORY to reference in deeper directories
set( CPSTRING_SRC_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})

# Initialize CPSTRING_SOURCES and HEADER_LIST as an empty string list
set( CPSTRING_SOURCES "" )
set( HEADERS_LIST "" )

# Append Sources
list( APPEND CPSTRING_SOURCES "${CMAKE_CURRENT_LIST_DIR}/CPString.cpp")

# Append Headers
list( APPEND HEADERS_LIST "${CMAKE_CURRENT_LIST_DIR}/CPString.h")
list( APPEND HEADERS_LIST "${CMAKE_CURRENT_LIST_DIR}/CPString_BuildSettings.h")
list( APPEND HEADERS_LIST "${CMAKE_CURRENT_LIST_DIR}/CPString_Class.h")
list( APPEND HEADERS_LIST "${CMAKE_CURRENT_LIST_DIR}/CPString_Definitions.h")

# Include Flash subdirectory
add_subdirectory(Flash )

# Create the CPString library (STATIC is not justified tho)
add_library( CPString STATIC ${CPSTRING_SOURCES} )

# Include directories for install and for build 
target_include_directories( 
	CPString PUBLIC 
	$<INSTALL_INTERFACE:include/CPString> 
	$<BUILD_INTERFACE:${CPSTRING_SRC_DIRECTORY}> 
)

# CPString install process
if(CPSTRING_INSTALL STREQUAL "ON")

	install(
		FILES ${HEADERS_LIST} 
		DESTINATION ${CMAKE_INSTALL_PREFIX}/include/CPString 
	)

	install(
		TARGETS CPString 
		EXPORT CPStringExport
		DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/CPString
	)

	install(
		EXPORT CPStringExport
		FILE CPString-config.cmake
		DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/CPString
	)

endif()