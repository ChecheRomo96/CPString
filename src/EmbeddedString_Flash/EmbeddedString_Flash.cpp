#include "EmbeddedString_Flash.h"

const char* EString::Flash::CopyBaseChars(char* buff, uint8_t base, bool LetterCase)
{
	for(uint8_t i = 0; i < base; i++)
	{
		#if defined(PSOC_CREATOR)
	        buff[i] = EString::Flash::NumericBaseChars[LetterCase][i];
	    #elif defined(ARDUINO_IDE)
		    buff[i] = pgm_read_byte(&EString::Flash::NumericBaseChars[LetterCase][i]);
		#endif
	}
    return buff;
}