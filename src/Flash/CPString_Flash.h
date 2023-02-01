#ifndef CROSS_PLATFORM_STRING_FLASH_H
#define CROSS_PLATFORM_STRING_FLASH_H

	#include <CPString_BuildSettings.h>
	#include <CPVector.h>
	
	#include "CPString_FlashDefinitions.h"
	
	namespace CrossPlatformString
	{
		namespace Flash
		{
			const char CopyBaseChar(uint8_t ID, bool LetterCase);

			const char* CopyBaseChars(char* buff, uint8_t base, bool LetterCase);
			void CopyBaseChars(CPVector::vector<char>& buff, uint8_t base, bool LetterCase);
		}
	}

#endif//CROSS_PLATFORM_STRING_FLASH_H