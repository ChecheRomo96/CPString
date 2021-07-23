#ifndef EMBEDDED_STRING_FLASH
#define EMBEDDED_STRING_FLASH

	#include <EmbeddedString_BuildSettings.h>
	
	#include "EmbeddedString_FlashDefinitions.h"
	
	namespace EString
	{
		namespace Flash
		{
			const char* CopyBaseChars(char* buff, uint8_t base, bool LetterCase);
		}
	}

#endif//EMBEDDED_STRING_FLASH