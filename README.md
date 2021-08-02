# Cross-Platform String
 
Library for unifiying Strings across multiple systems. These subdirectories contain a CMake build system. You can install the package with make to make it available in your computer, also you can "add" this subdirectory with cmake to compile the library when building your project. 

This library complies with the Arduino Library Specification. To achieve this, a library.properties file has been included. Also there is a keywords.txt file so the IDE knows how to color keywords, examples are in the directory examples, 

List of platforms where it has been tested.

	c++ Compiled with on Mac Os X
	Arduino IDE
	PSoC Creator IDE

##Steps to install package:

1.- Clone or download package.

2.- Open terminal and go to the the download directory (Replace <path_to_directory> with the path to the directory you downloaded) 

	cd <path_to_directory>/EmbeddedString

3.- Run 

	mkdir build && cd build

4.- Run 
	
	make

5.- Run 
	
	sudo make install


##Steps to install as an Arduino Library:

Note that you must have git installed on your computer. To istall git through homebrew:

	brew install git


1.- Go to your current arduino library 