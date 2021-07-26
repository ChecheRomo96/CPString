add_library(EString STATIC EmbeddedString.cpp)
target_include_directories(EString PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_subdirectory(EmbeddedString_Flash)
target_link_libraries(EString EStringFlash)