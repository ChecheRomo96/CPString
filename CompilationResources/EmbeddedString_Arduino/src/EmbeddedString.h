#ifndef EMBEDDED_STRING_H
#define EMBEDDED_STRING_H

	#define EMBEDDED_STRING
	#define ESTRING_VERSION "0.01"

	#include "EmbeddedString_BuildSettings.h"
	#include "EmbeddedString_Definitions.h"
	#include "EmbeddedString_Class.h"

	#if defined(ARDUINO)
		#include "EmbeddedString_Flash/EmbeddedString_Flash.h"
	#elif defined(PSOC_CREATOR)
		#include "EmbeddedString_Flash\EmbeddedString_Flash.h"
	#endif

#endif//EMBEDDED_STRING_H