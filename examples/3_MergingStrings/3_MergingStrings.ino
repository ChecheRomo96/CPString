#include <CPString.h>

using namespace CPString;

void setup()
{
  	Serial.begin(115200);
    CPString::string myString = "Hello World";
	Serial.println(myString);
    
    myString = "Hello ";
    myString += "Wolrd";
	Serial.println(myString);
    
    myString = "Hello ";
	Serial.println(myString + "World");
	Serial.println(myString);
}

void loop()
{

}