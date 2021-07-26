# Create the EStringFlash library and include the source root directory
add_library(EStringFlash STATIC EmbeddedString_Flash.cpp)
target_include_directories(EStringFlash PUBLIC ${ESTRING_SRC_DIRECTORY})