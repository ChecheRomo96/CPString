#include "EmbeddedString_Flash.h"

const char* EmbeddedString::Flash::CopyBaseChars(char* buff, uint8_t base, bool LetterCase)
{
	for(uint8_t i = 0; i < base; i++)
	{
		#if defined(PSOC_CREATOR) || defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined(__APPLE__) || defined(linux)
	        buff[i] = EmbeddedString::Flash::NumericBaseChars[LetterCase][i];
	    #elif defined(ARDUINO_IDE)
		    buff[i] = pgm_read_byte(&EmbeddedString::Flash::NumericBaseChars[LetterCase][i]);
		#endif
	}
    return buff;
}