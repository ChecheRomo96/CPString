#include <CPString.h>

using namespace CPString;

int32_t GetSerialData()
{
  bool flag = 1;

  uint8_t BufferSize = 12;
  uint8_t DataBuffer[BufferSize];
  uint8_t DataIndex = 0;

  while(flag)
  {
    if(Serial.available() != 0)
    {
      uint8_t newData = Serial.read();

      if(newData == '\n')
      {
        
        int32_t Value = 0;
                
        if(DataBuffer[0] == '-')
        {
          switch(DataIndex)
          {
            default:
            case 11: Value -= (uint32_t)((DataBuffer[DataIndex-10] - '0') % 10)  * (uint32_t)1000000000;
            case 10: Value -= (uint32_t)((DataBuffer[DataIndex-9] - '0') % 10)  * (uint32_t)100000000;
            case 9 : Value -= (uint32_t)((DataBuffer[DataIndex-8] - '0') % 10)  * (uint32_t)10000000;
            case 8 : Value -= (uint32_t)((DataBuffer[DataIndex-7] - '0') % 10)  * (uint32_t)1000000;
            case 7 : Value -= (uint32_t)((DataBuffer[DataIndex-6] - '0') % 10)  * (uint32_t)100000;
            case 6 : Value -= (uint32_t)((DataBuffer[DataIndex-5] - '0') % 10)  * (uint32_t)10000;
            case 5 : Value -= (uint32_t)((DataBuffer[DataIndex-4] - '0') % 10)  * (uint32_t)1000;
            case 4 : Value -= (uint32_t)((DataBuffer[DataIndex-3] - '0') % 10)  * (uint32_t)100;
            case 3 : Value -= (uint32_t)((DataBuffer[DataIndex-2] - '0') % 10)  * (uint32_t)10;
            case 2 : Value -= (uint32_t)((DataBuffer[DataIndex-1] - '0') % 10)  * (uint32_t)1; 
            case 1 : 
            case 0 : break;
          }
        }
        else
        {           
          switch(DataIndex)
          {
            default:
            case 10: Value += (uint32_t)((DataBuffer[DataIndex-10] - '0') % 10)  * (uint32_t)1000000000;
            case 9 : Value += (uint32_t)((DataBuffer[DataIndex-9 ] - '0') % 10)  * (uint32_t)100000000;
            case 8 : Value += (uint32_t)((DataBuffer[DataIndex-8 ] - '0') % 10)  * (uint32_t)10000000;
            case 7 : Value += (uint32_t)((DataBuffer[DataIndex-7 ] - '0') % 10)  * (uint32_t)1000000;
            case 6 : Value += (uint32_t)((DataBuffer[DataIndex-6 ] - '0') % 10)  * (uint32_t)100000;
            case 5 : Value += (uint32_t)((DataBuffer[DataIndex-5 ] - '0') % 10)  * (uint32_t)10000;
            case 4 : Value += (uint32_t)((DataBuffer[DataIndex-4 ] - '0') % 10)  * (uint32_t)1000;
            case 3 : Value += (uint32_t)((DataBuffer[DataIndex-3 ] - '0') % 10)  * (uint32_t)100;
            case 2 : Value += (uint32_t)((DataBuffer[DataIndex-2 ] - '0') % 10)  * (uint32_t)10;
            case 1 : Value += (uint32_t)((DataBuffer[DataIndex-1 ] - '0') % 10)  * (uint32_t)1; 
            case 0 : break;
          }
        }

        flag = 0;
        
        return Value;
      }
      else
      {
        DataBuffer[DataIndex++] = newData;

        if(DataIndex >= BufferSize)
        {
          DataIndex  = 0;
        }
      }
    }
  }
}

void setup()
{
  Serial.begin(115200);

    Serial.print(string("Hello this code snippet will test base conversion.\n"));
    Serial.print(string("We'll convert ints and uints to multiple bases.\n"));

    Serial.print(string("Give me a positive integer.\n\n"));
    int32_t a = GetSerialData();
    Serial.print("\nYou gave me the number "); Serial.print((int32_t)a); Serial.print(F(".\n\n"));
    
    Serial.print(F("We'll store this value as a uint variable called a.\n\n"));
    Serial.print(F("Printing a on base 2  { string(a,2 ) }: ")); Serial.print(string(a,2 )); Serial.print(F(".\n"));
    Serial.print(F("Printing a on base 4  { string(a,4 ) }: ")); Serial.print(string(a,4 )); Serial.print(F(".\n"));
    Serial.print(F("Printing a on base 8  { string(a,8 ) }: ")); Serial.print(string(a,8 )); Serial.print(F(".\n"));
    Serial.print(F("Printing a on base 10 { string(a,10) }: ")); Serial.print(string(a,10)); Serial.print(F(".\n"));
    Serial.print(F("Printing a on base 16 { string(a,16) }: ")); Serial.print(string(a,16)); Serial.print(F(".\n"));
    
    Serial.print(F("\nBy default the letters on the output are Upper case.\n"));
    Serial.print(F("We can change that by calling SetLetterCase(LetterCase::Lower)\n\n"));

    SetLetterCase(NumberConversion::LetterCase::Lower);
    Serial.print(F("Let's print the values of a again\n\n"));

    Serial.print(F("Printing a on base 2  { string(a,2 ) }: ")); Serial.print(string(a,2 )); Serial.print(F(".\n"));
    Serial.print(F("Printing a on base 4  { string(a,4 ) }: ")); Serial.print(string(a,4 )); Serial.print(F(".\n"));
    Serial.print(F("Printing a on base 8  { string(a,8 ) }: ")); Serial.print(string(a,8 )); Serial.print(F(".\n"));
    Serial.print(F("Printing a on base 10 { string(a,10) }: ")); Serial.print(string(a,10)); Serial.print(F(".\n"));
    Serial.print(F("Printing a on base 16 { string(a,16) }: ")); Serial.print(string(a,16)); Serial.print(F(".\n"));
    

    Serial.print(string("\nNow give me a negative integer.\n"));
    int32_t b = GetSerialData();
    Serial.print("\nYou gave me the number "); Serial.print((int32_t)b); Serial.print(".\n\n");
    
    Serial.print(F("We'll store this value as a int variable called b.\n"));
    Serial.print(F("Printing b on base 2  { string(b,2 ) }: ")); Serial.print(string(b,2 )); Serial.print(F(".\n"));
    Serial.print(F("Printing b on base 4  { string(b,4 ) }: ")); Serial.print(string(b,4 )); Serial.print(F(".\n"));
    Serial.print(F("Printing b on base 8  { string(b,8 ) }: ")); Serial.print(string(b,8 )); Serial.print(F(".\n"));
    Serial.print(F("Printing b on base 10 { string(b,10) }: ")); Serial.print(string(b,10)); Serial.print(F(".\n"));
    Serial.print(F("Printing b on base 16 { string(b,16) }: ")); Serial.print(string(b,16)); Serial.print(F(".\n"));
    
    Serial.print(F("\nBy default int conversion is signed.\n"));
    Serial.print(F("We can change that by calling SetIntFormat(IntFormat::Absolute)\n\n"));

    SetIntFormat(NumberConversion::IntFormat::Absolute);
    
    Serial.print(string("Let's print the values of b again\n\n"));

    Serial.print(F("Printing b on base 2  { string(b,2 ) }: ")); Serial.print(string(b,2 )); Serial.print(F(".\n"));
    Serial.print(F("Printing b on base 4  { string(b,4 ) }: ")); Serial.print(string(b,4 )); Serial.print(F(".\n"));
    Serial.print(F("Printing b on base 8  { string(b,8 ) }: ")); Serial.print(string(b,8 )); Serial.print(F(".\n"));
    Serial.print(F("Printing b on base 10 { string(b,10) }: ")); Serial.print(string(b,10)); Serial.print(F(".\n"));
    Serial.print(F("Printing b on base 16 { string(b,16) }: ")); Serial.print(string(b,16)); Serial.print(F(".\n"));
}

void loop()
{

}