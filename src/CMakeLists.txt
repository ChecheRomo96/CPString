# Store this directory as a variable called ESTRING_SRC_DIRECTORY to reference in deeper directories
set(ESTRING_SRC_DIRECTORY  ${CMAKE_CURRENT_LIST_DIR})

# Create the EString library (STATIC is not justified tho) and include the directories needed to compile
add_library(EString STATIC EmbeddedString.cpp)
target_include_directories(EString PUBLIC ${ESTRING_SRC_DIRECTORY})

# Include Flash subdirectory and link it
add_subdirectory(EmbeddedString_Flash)
target_link_libraries(EString EStringFlash)