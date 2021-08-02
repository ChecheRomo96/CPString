#ifndef CROSS_PLATFORM_STRING_H
#define CROSS_PLATFORM_STRING_H

	namespace CrossPlatformString
	{
		void SetLetterCase(bool Mode);
		void SetLetterCase_Upper();
		void SetLetterCase_Lower();

		void SetIntFormat(bool Mode);
		void SetIntFormat_Signed();
		void SetIntFormat_Absolute();
	}

	namespace CPString = CrossPlatformString;

	#include "CPString_BuildSettings.h"
	#include "CPString_Definitions.h"
	#include "Flash/CPString_Flash.h"
	#include "CPString_Class.h"

#endif//CROSS_PLATFORM_STRING_H