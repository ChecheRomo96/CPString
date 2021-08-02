# Initialize HEADER_LIST as an empty string list
set( HEADERS_LIST "" )

# Append Sources
list( APPEND ESTRING_SOURCES "${CMAKE_CURRENT_LIST_DIR}/EmbeddedString_Flash.cpp")

# Append Headers
list( APPEND HEADERS_LIST "${CMAKE_CURRENT_LIST_DIR}/EmbeddedString_Flash.h")
list( APPEND HEADERS_LIST "${CMAKE_CURRENT_LIST_DIR}/EmbeddedString_FlashDefinitions.h")

# Refresh Sources and Header Lists at PARENT_SCOPE
set(ESTRING_SOURCES "${ESTRING_SOURCES}" PARENT_SCOPE)

if(ESTRING_INSTALL STREQUAL "ON")

	install(
		FILES ${HEADERS_LIST} 
		DESTINATION ${CMAKE_INSTALL_PREFIX}/include/EString/EmbeddedString_Flash
	)

endif()