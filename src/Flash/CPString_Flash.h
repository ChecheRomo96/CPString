#ifndef CROSS_PLATFORM_STRING_FLASH_H
#define EMBEDDED_STRING_FLASH

	#include <CPString_BuildSettings.h>
	
	#include "CPString_FlashDefinitions.h"
	
	namespace CrossPlatformString
	{
		namespace Flash
		{
			const char* CopyBaseChars(char* buff, uint8_t base, bool LetterCase);
		}
	}

#endif//EMBEDDED_STRING_FLASH