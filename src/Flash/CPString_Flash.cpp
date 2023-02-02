#include "CPString_Flash.h"

const char CrossPlatformString::Flash::CopyBaseChar(uint8_t ID, bool LetterCase)
{
	#if defined(__AVR__)
	    return pgm_read_byte(&CrossPlatformString::Flash::NumericBaseChars[LetterCase][ID]);
	#else
	    return CrossPlatformString::Flash::NumericBaseChars[LetterCase][ID];
	#endif
}
