#include <CPString.h>

void setup()
{
	Serial.begin(115200);
	Serial.print(F("This project uses CPString version:"));
	Serial.println(CPSTRING_VERSION);
}

void loop()
{
	
}