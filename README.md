# Cross-Platform String
 
Library for unifiying Strings across multiple systems. These subdirectories contain a CMake build system. You can install the package with make to make it available in your computer, also you can "add" this subdirectory with cmake to compile the library when building your project. 

This library complies with the Arduino Library Specification. To achieve this, a library.properties file has been included. Also there is a keywords.txt file so the IDE knows how to color keywords, examples are in the directory examples, 

List of platforms where it has been tested.

	c++ Compiled thorugh cmake + make on Mac Os X
	Arduino IDE
	PSoC Creator IDE

## Steps to install package:

1.- Clone or download package.

2.- Open terminal and go to the the download directory (Replace "<path_to_directory>" with the path to the directory you downloaded) 

	cd <path_to_directory>/EmbeddedString

3.- Run 

	mkdir build && cd build

4.- Run 
	
	cmake .. -DCPSTRING_INSTALL="ON"

5.- Run 
	
	make

6.- Run 
	
	sudo make install

## Steps to uninstall package:

1.- Remove the following directories

	usr/local/lib/CPString
	usr/local/include/CPString

## Steps to install as an Arduino Library:

### a) download zip file

If you downlaoded the zip file containing this repository extract ists contents and move the CPString_vX.X.X to your current Arduino Project library directory.

Even though you did not installed through git you can update the package through it.

### b) clone through git

Note that you must have git installed on your computer. To istall git through homebrew:

	brew install git

1.- Go to your current Arduino Project library directory replace <myArduinoProjectDirectory> with your directory path.

	cd <myArduinoProjectDirectory>/libraries

2.- Clone through git

	git clone https://github.com/ChecheRomo96/CPString.git

3.- To update this repository, enter to the repository and pull the newer version

	cd CPString
	git pull

