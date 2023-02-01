#include "CPString_Flash.h"

const char CrossPlatformString::Flash::CopyBaseChar(uint8_t ID, bool LetterCase)
{
	#if defined(__AVR__)
	    return pgm_read_byte(&CrossPlatformString::Flash::NumericBaseChars[LetterCase][ID]);
	#else
	    return CrossPlatformString::Flash::NumericBaseChars[LetterCase][ID];
	#endif
}

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

void CrossPlatformString::Flash::CopyBaseChars(CPVector::vector<char>& buff, uint8_t base, bool LetterCase)
{
	buff.resize(base);

	for(uint8_t i = 0; i < base; i++)
	{
		#if defined(__AVR__)
		    buff[i] = pgm_read_byte(&CrossPlatformString::Flash::NumericBaseChars[LetterCase][i]);
		#else
		    buff[i] = CrossPlatformString::Flash::NumericBaseChars[LetterCase][i];
		#endif
	}
}
