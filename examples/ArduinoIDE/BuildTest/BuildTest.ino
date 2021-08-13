#include <CPString.h>

using namespace CPString;

void setup()
{
	Serial.begin();
	Serial.print(F("CPString version: "));
	Serial.println(CPString_Version);
}

void loop()
{

}