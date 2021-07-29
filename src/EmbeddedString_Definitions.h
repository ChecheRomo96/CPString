#ifndef EMBEDDED_STRING_DEFINITIONS_H
#define EMBEDDED_STRING_DEFINITIONS_H

    #include <EmbeddedString_BuildSettings.h>
    
	namespace EmbeddedString
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
	

#endif//EMBEDDED_STRING_DEFINITIONS_H