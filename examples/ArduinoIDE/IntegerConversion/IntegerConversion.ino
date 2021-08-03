#include <CPString.h>

using namespace CPString;

int32_t GetSerialData()
{
	bool flag = 1;

	uint8_t BufferSize = 5;
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
					switch(BufferSize)
					{
						default:
						case 10: Value += ((DataBuffer[9] % 10) - '0') * 100000000;
						case 9 : Value += ((DataBuffer[8] % 10) - '0') * 10000000;
						case 8 : Value += ((DataBuffer[7] % 10) - '0') * 1000000;
						case 7 : Value += ((DataBuffer[6] % 10) - '0') * 100000;
						case 6 : Value += ((DataBuffer[5] % 10) - '0') * 10000;
						case 5 : Value += ((DataBuffer[4] % 10) - '0') * 1000;
						case 4 : Value += ((DataBuffer[3] % 10) - '0') * 100;
						case 3 : Value += ((DataBuffer[2] % 10) - '0') * 10;
						case 2 : Value += ((DataBuffer[1] % 10) - '0') * 1; 
						case 1 : 
						case 0 : break;
					}
					Value *= -1;
				}
				else
				{						
					switch(BufferSize)
					{
						default:
						case 10: Value += ((DataBuffer[9] % 10) - '0') * 10000;
						case 9 : Value += ((DataBuffer[8] % 10) - '0') * 10000;
						case 8 : Value += ((DataBuffer[7] % 10) - '0') * 10000;
						case 7 : Value += ((DataBuffer[6] % 10) - '0') * 10000;
						case 6 : Value += ((DataBuffer[5] % 10) - '0') * 10000;
						case 5 : Value += ((DataBuffer[4] % 10) - '0') * 10000;
						case 4 : Value += ((DataBuffer[3] % 10) - '0') * 1000;
						case 3 : Value += ((DataBuffer[2] % 10) - '0') * 100;
						case 2 : Value += ((DataBuffer[1] % 10) - '0') * 10;
						case 1 : Value += ((DataBuffer[0] % 10) - '0') * 1; 
						case 0 : break;
					}
				}

				DataIndex  = 0;
				
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

    Serial.print(CPString::string("Hello this code snippet will test base conversion.\n"));
    Serial.print(CPString::string("We'll convert ints and uints to multiple bases.\n"));

    Serial.print(CPString::string("Give me a positive integer.\n\n");
    uint a = GetSerialData();
    Serial.print("\nYou gave me the number "); Serial.print((uint)a); Serial.print(".\n\n";
    
    Serial.print(CPString::string("We'll store this value as a uint variable called a.\n\n"));
    Serial.print(CPString::string("Printing a on base 2  { string(a,2 ) }: ")); Serial.print(CPString::string(a,2 )); Serial.print(".\n");
    Serial.print(CPString::string("Printing a on base 4  { string(a,4 ) }: ")); Serial.print(CPString::string(a,4 )); Serial.print(".\n");
    Serial.print(CPString::string("Printing a on base 8  { string(a,8 ) }: ")); Serial.print(CPString::string(a,8 )); Serial.print(".\n");
    Serial.print(CPString::string("Printing a on base 10 { string(a,10) }: ")); Serial.print(CPString::string(a,10)); Serial.print(".\n");
    Serial.print(CPString::string("Printing a on base 16 { string(a,16) }: ")); Serial.print(CPString::string(a,16)); Serial.print(".\n");
    
    Serial.print(CPString::string("\nBy default the letters on the output are Upper case.\n"));
    Serial.print(CPString::string("We can change that by calling CPString::SetLetterCase(CPString::LetterCase::Lower)\n\n"));

    CPString::SetLetterCase(CPString::LetterCase::Lower));
    Serial.print(CPString::string("Let's print the values of a again\n\n"));

    Serial.print(CPString::string("Printing a on base 2  { string(a,2 ) }: ")); Serial.print(CPString::string(a,2 )); Serial.print(".\n");
    Serial.print(CPString::string("Printing a on base 4  { string(a,4 ) }: ")); Serial.print(CPString::string(a,4 )); Serial.print(".\n");
    Serial.print(CPString::string("Printing a on base 8  { string(a,8 ) }: ")); Serial.print(CPString::string(a,8 )); Serial.print(".\n");
    Serial.print(CPString::string("Printing a on base 10 { string(a,10) }: ")); Serial.print(CPString::string(a,10)); Serial.print(".\n");
    Serial.print(CPString::string("Printing a on base 16 { string(a,16) }: ")); Serial.print(CPString::string(a,16)); Serial.print(".\n");
    

  	Serial.print(CPString::string("\nNow give me a negative integer.\n\n"));
    int b = GetSerialData();
    Serial.print("\nYou gave me the number "); Serial.print((uint)b); Serial.print(".\n\n");
    
    Serial.print(CPString::string("We'll store this value as a int variable called b.\n");
    Serial.print(CPString::string("Printing b on base 2  { string(b,2 ) }: ")); Serial.print(CPString::string(b,2 )); Serial.print(".\n");
    Serial.print(CPString::string("Printing b on base 4  { string(b,4 ) }: ")); Serial.print(CPString::string(b,4 )); Serial.print(".\n");
    Serial.print(CPString::string("Printing b on base 8  { string(b,8 ) }: ")); Serial.print(CPString::string(b,8 )); Serial.print(".\n");
    Serial.print(CPString::string("Printing b on base 10 { string(b,10) }: ")); Serial.print(CPString::string(b,10)); Serial.print(".\n");
    Serial.print(CPString::string("Printing b on base 16 { string(b,16) }: ")); Serial.print(CPString::string(b,16)); Serial.print(".\n");
    
    Serial.print(CPString::string("\nBy default int conversion is signed.\n"));
    Serial.print(CPString::string("We can change that by calling CPString::SetIntFormat(CPString::IntFormat::Absolute)\n\n"));

    CPString::SetIntFormat(CPString::IntFormat::Absolute));
    
    Serial.print(CPString::string("Let's print the values of b again\n\n"));

    Serial.print(CPString::string("Printing b on base 2  { string(b,2 ) }: ")); Serial.print(CPString::string(b,2 )); Serial.print(".\n");
    Serial.print(CPString::string("Printing b on base 4  { string(b,4 ) }: ")); Serial.print(CPString::string(b,4 )); Serial.print(".\n");
    Serial.print(CPString::string("Printing b on base 8  { string(b,8 ) }: ")); Serial.print(CPString::string(b,8 )); Serial.print(".\n");
    Serial.print(CPString::string("Printing b on base 10 { string(b,10) }: ")); Serial.print(CPString::string(b,10)); Serial.print(".\n");
    Serial.print(CPString::string("Printing b on base 16 { string(b,16) }: ")); Serial.print(CPString::string(b,16)); Serial.print(".\n");
}

void loop()
{

}