#ifndef CROSS_PLATFORM_STRING_DEFINITIONS_H
#define CROSS_PLATFORM_STRING_DEFINITIONS_H

    #include <CPString_BuildSettings.h>
    
	namespace CrossPlatformString
	{
		namespace LetterCase
		{
			extern bool Mode;
			static constexpr bool Lower = 0;
			static constexpr bool Upper = 1;
		}

		namespace IntFormat
		{
			extern bool Mode;
			static constexpr bool Signed = 0;
			static constexpr bool Absolute = 1;
		}
	}
	

#endif//CROSS_PLATFORM_STRING_DEFINITIONS_H