#include <CPString.h>

using namespace CPString;

void setup()
{
  Serial.begin(115200);

  CPString::string str = " Hello ";

  str += "Wolrd";

  Serial.println(str);
}

void loop()
{

}