#ifndef CROSS_PLATFORM_STRING_FLASH_DEFINITIONS_H
#define CROSS_PLATFORM_STRING_FLASH_DEFINITIONS_H

	#include <CPString_BuildSettings.h>

	namespace CrossPlatformString
	{
		namespace Flash
		{
            static const char NumericBaseChars[2][36] PROGMEM_MACRO =
            {
                {'0','1','2','3','4','5','6','7','8','9',
                 'a','b','c','d','e','f','g','h','i','j',
                 'k','l','m','n','o','p','q','r','s','t',
                 'u','v','w','x','y','z'},
                {'0','1','2','3','4','5','6','7','8','9',
                 'A','B','C','D','E','F','G','H','I','J',
                 'K','L','M','N','O','P','Q','R','S','T',
                 'U','V','W','X','Y','Z'}
            };
		}
	}


	

#endif//CROSS_PLATFORM_STRING_FLASH_DEFINITIONS_H
