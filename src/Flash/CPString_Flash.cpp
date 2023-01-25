#include "CPString_Flash.h"

const char* CrossPlatformString::Flash::CopyBaseChars(char* buff, uint8_t base, bool LetterCase)
{
	for(uint8_t i = 0; i < base; i++)
	{
		#if defined(__AVR__)
		    buff[i] = pgm_read_byte(&CrossPlatformString::Flash::NumericBaseChars[LetterCase][i]);
		#else
		    buff[i] = CrossPlatformString::Flash::NumericBaseChars[LetterCase][i];
		#endif
	}
    return buff;
}