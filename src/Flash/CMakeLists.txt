# Initialize HEADER_LIST as an empty string list
set( HEADERS_LIST "" )

# Append Sources
list( APPEND CPSTRING_SOURCES "${CMAKE_CURRENT_LIST_DIR}/CPString_Flash.cpp")

# Append Headers
list( APPEND HEADERS_LIST "${CMAKE_CURRENT_LIST_DIR}/CPString_Flash.h")
list( APPEND HEADERS_LIST "${CMAKE_CURRENT_LIST_DIR}/CPString_FlashDefinitions.h")

# Refresh Sources List at PARENT_SCOPE
set(CPSTRING_SOURCES "${CPSTRING_SOURCES}" PARENT_SCOPE)

if(CPSTRING_INSTALL STREQUAL "ON")

	install(
		FILES ${HEADERS_LIST} 
		DESTINATION ${CMAKE_INSTALL_PREFIX}/include/CPString/Flash
	)

endif()