#ifndef EMBEDDED_STRING_H
#define EMBEDDED_STRING_H

	namespace EmbeddedString
	{
		void SetLetterCase(bool Mode);
		void SetLetterCase_Upper();
		void SetLetterCase_Lower();

		void SetIntFormat(bool Mode);
		void SetIntFormat_Signed();
		void SetIntFormat_Absolute();
	}

	namespace EString = EmbeddedString;

	#include "EmbeddedString_BuildSettings.h"
	#include "EmbeddedString_Definitions.h"
	#include "EmbeddedString_Flash/EmbeddedString_Flash.h"
	#include "EmbeddedString_Class.h"

#endif//EMBEDDED_STRING_H