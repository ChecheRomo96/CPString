#include <CPString.h>

void setup()
{
	Serial.begin();
	Serial.print(F("This project uses CPString version:"));
	Serial.println(CPString_Version);
}

void loop()
{
	
}