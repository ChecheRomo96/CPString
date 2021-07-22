#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/josemanuelromoperedo/Dropbox/Github/C++/EmbeddedString/Builds/XCode/build/src/EmbeddedString
  /usr/local/Cellar/cmake/3.20.5/bin/cmake -E cmake_symlink_library /Users/josemanuelromoperedo/Dropbox/Github/C++/EmbeddedString/Builds/XCode/build/src/EmbeddedString/Debug/libEString.dylib /Users/josemanuelromoperedo/Dropbox/Github/C++/EmbeddedString/Builds/XCode/build/src/EmbeddedString/Debug/libEString.dylib /Users/josemanuelromoperedo/Dropbox/Github/C++/EmbeddedString/Builds/XCode/build/src/EmbeddedString/Debug/libEString.dylib
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/josemanuelromoperedo/Dropbox/Github/C++/EmbeddedString/Builds/XCode/build/src/EmbeddedString
  /usr/local/Cellar/cmake/3.20.5/bin/cmake -E cmake_symlink_library /Users/josemanuelromoperedo/Dropbox/Github/C++/EmbeddedString/Builds/XCode/build/src/EmbeddedString/Release/libEString.dylib /Users/josemanuelromoperedo/Dropbox/Github/C++/EmbeddedString/Builds/XCode/build/src/EmbeddedString/Release/libEString.dylib /Users/josemanuelromoperedo/Dropbox/Github/C++/EmbeddedString/Builds/XCode/build/src/EmbeddedString/Release/libEString.dylib
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/josemanuelromoperedo/Dropbox/Github/C++/EmbeddedString/Builds/XCode/build/src/EmbeddedString
  /usr/local/Cellar/cmake/3.20.5/bin/cmake -E cmake_symlink_library /Users/josemanuelromoperedo/Dropbox/Github/C++/EmbeddedString/Builds/XCode/build/src/EmbeddedString/MinSizeRel/libEString.dylib /Users/josemanuelromoperedo/Dropbox/Github/C++/EmbeddedString/Builds/XCode/build/src/EmbeddedString/MinSizeRel/libEString.dylib /Users/josemanuelromoperedo/Dropbox/Github/C++/EmbeddedString/Builds/XCode/build/src/EmbeddedString/MinSizeRel/libEString.dylib
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/josemanuelromoperedo/Dropbox/Github/C++/EmbeddedString/Builds/XCode/build/src/EmbeddedString
  /usr/local/Cellar/cmake/3.20.5/bin/cmake -E cmake_symlink_library /Users/josemanuelromoperedo/Dropbox/Github/C++/EmbeddedString/Builds/XCode/build/src/EmbeddedString/RelWithDebInfo/libEString.dylib /Users/josemanuelromoperedo/Dropbox/Github/C++/EmbeddedString/Builds/XCode/build/src/EmbeddedString/RelWithDebInfo/libEString.dylib /Users/josemanuelromoperedo/Dropbox/Github/C++/EmbeddedString/Builds/XCode/build/src/EmbeddedString/RelWithDebInfo/libEString.dylib
fi

