# Store this directory as a variable called ESTRING_SRC_DIRECTORY to reference in deeper directories
set( ESTRING_SRC_DIRECTORY  ${CMAKE_CURRENT_LIST_DIR} )

# Initialize ESTRING_SOURCES as an empty string list
set( ESTRING_SOURCES "" )

# Include Flash subdirectory
add_subdirectory( EmbeddedString_Flash )


# Create the EString library (STATIC is not justified tho) and include the directories needed to compile
add_library( EString STATIC EmbeddedString.cpp ${ESTRING_SOURCES} )
target_include_directories( EString PUBLIC ${ESTRING_SRC_DIRECTORY} )
