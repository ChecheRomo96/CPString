#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/josemanuelromoperedo/Dropbox/Github/C++/EmbeddedString/Builds/XCode/build
  make -f /Users/josemanuelromoperedo/Dropbox/Github/C++/EmbeddedString/Builds/XCode/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/josemanuelromoperedo/Dropbox/Github/C++/EmbeddedString/Builds/XCode/build
  make -f /Users/josemanuelromoperedo/Dropbox/Github/C++/EmbeddedString/Builds/XCode/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/josemanuelromoperedo/Dropbox/Github/C++/EmbeddedString/Builds/XCode/build
  make -f /Users/josemanuelromoperedo/Dropbox/Github/C++/EmbeddedString/Builds/XCode/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/josemanuelromoperedo/Dropbox/Github/C++/EmbeddedString/Builds/XCode/build
  make -f /Users/josemanuelromoperedo/Dropbox/Github/C++/EmbeddedString/Builds/XCode/build/CMakeScripts/ReRunCMake.make
fi

