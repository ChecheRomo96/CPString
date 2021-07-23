add_subdirectory(EmbeddedString_Flash)
link_libraries(EString EStringFlash)
add_library(EString STATIC EmbeddedString.cpp)

