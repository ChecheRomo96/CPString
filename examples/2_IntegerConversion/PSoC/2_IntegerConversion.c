extern "C"{
    #include "project.h"
}

#include<CPString.h>

using namespace CPString;

int32_t GetSerialData();

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
	UART_1_Start();
    UART_1_PutString(string("Hello this code snippet will test base conversion.\n\r").c_str());
    UART_1_PutString("We'll convert ints and uints to multiple bases.\n\r");

    UART_1_PutString("Give me a positive integer.\n\n\r");
    int32_t a = GetSerialData();
    UART_1_PutString("\n\rYou gave me the number ");  string str(a); UART_1_PutString(str.c_str()); UART_1_PutString(".\n\n\r");
    
    UART_1_PutString("We'll store this value as a uint variable called a.\n\n\r");
    UART_1_PutString("Printing a on base 2  { string(a,2 ) }: "); UART_1_PutString(string(a,2 ).c_str()); UART_1_PutString(".\n\r");
    UART_1_PutString("Printing a on base 4  { string(a,4 ) }: "); UART_1_PutString(string(a,4 ).c_str()); UART_1_PutString(".\n\r");
    UART_1_PutString("Printing a on base 8  { string(a,8 ) }: "); UART_1_PutString(string(a,8 ).c_str()); UART_1_PutString(".\n\r");
    UART_1_PutString("Printing a on base 10 { string(a,10) }: "); UART_1_PutString(string(a,10).c_str()); UART_1_PutString(".\n\r");
    UART_1_PutString("Printing a on base 16 { string(a,16) }: "); UART_1_PutString(string(a,16).c_str()); UART_1_PutString(".\n\r");
    
    UART_1_PutString("\n\rBy default the letters on the output are Upper case.\n\r");
    UART_1_PutString("We can change that by calling SetLetterCase(LetterCase::Lower)\n\n\r");

    SetLetterCase(NumberConversion::LetterCase::Lower);
    UART_1_PutString("Let's print the values of a again\n\n\r");

    UART_1_PutString("Printing a on base 2  { string(a,2 ) }: "); UART_1_PutString(string(a,2 ).c_str()); UART_1_PutString(".\n\r");
    UART_1_PutString("Printing a on base 4  { string(a,4 ) }: "); UART_1_PutString(string(a,4 ).c_str()); UART_1_PutString(".\n\r");
    UART_1_PutString("Printing a on base 8  { string(a,8 ) }: "); UART_1_PutString(string(a,8 ).c_str()); UART_1_PutString(".\n\r");
    UART_1_PutString("Printing a on base 10 { string(a,10) }: "); UART_1_PutString(string(a,10).c_str()); UART_1_PutString(".\n\r");
    UART_1_PutString("Printing a on base 16 { string(a,16) }: "); UART_1_PutString(string(a,16).c_str()); UART_1_PutString(".\n\r");
    

    UART_1_PutString(string("\nNow give me a negative integer.\n\n\r").c_str());
    int32_t b = GetSerialData();
    UART_1_PutString("\n\rYou gave me the number "); UART_1_PutString(string(b).c_str()); UART_1_PutString(".\n\n\r");
    
    UART_1_PutString("We'll store this value as a int variable called b.\n\r");
    UART_1_PutString("Printing b on base 2  { string(b,2 ) }: "); UART_1_PutString(string(b,2 ).c_str()); UART_1_PutString(".\n\r");
    UART_1_PutString("Printing b on base 4  { string(b,4 ) }: "); UART_1_PutString(string(b,4 ).c_str()); UART_1_PutString(".\n\r");
    UART_1_PutString("Printing b on base 8  { string(b,8 ) }: "); UART_1_PutString(string(b,8 ).c_str()); UART_1_PutString(".\n\r");
    UART_1_PutString("Printing b on base 10 { string(b,10) }: "); UART_1_PutString(string(b,10).c_str()); UART_1_PutString(".\n\r");
    UART_1_PutString("Printing b on base 16 { string(b,16) }: "); UART_1_PutString(string(b,16).c_str()); UART_1_PutString(".\n\r");
    
    UART_1_PutString("\n\rBy default int conversion is signed.\n\r");
    UART_1_PutString("We can change that by calling SetIntFormat(IntFormat::Absolute)\n\n\r");

    SetIntFormat(NumberConversion::IntFormat::Absolute);
    
    UART_1_PutString(string("Let's print the values of b again\n\n\r").c_str());

    UART_1_PutString("Printing b on base 2  { string(b,2 ) }: "); UART_1_PutString(string(b,2 ).c_str()); UART_1_PutString(".\n\r");
    UART_1_PutString("Printing b on base 4  { string(b,4 ) }: "); UART_1_PutString(string(b,4 ).c_str()); UART_1_PutString(".\n\r");
    UART_1_PutString("Printing b on base 8  { string(b,8 ) }: "); UART_1_PutString(string(b,8 ).c_str()); UART_1_PutString(".\n\r");
    UART_1_PutString("Printing b on base 10 { string(b,10) }: "); UART_1_PutString(string(b,10).c_str()); UART_1_PutString(".\n\r");
    UART_1_PutString("Printing b on base 16 { string(b,16) }: "); UART_1_PutString(string(b,16).c_str()); UART_1_PutString(".\n\r");

    for(;;)
    {
        /* Place your application code here. */
    }
}

int32_t GetSerialData()
{
    bool flag = 1;

    uint8_t BufferSize = 12;
    uint8_t DataBuffer[BufferSize];
    uint8_t DataIndex = 0;

    while(flag)
    {
        if(UART_1_GetRxBufferSize() != 0)
        {
          uint8_t newData = UART_1_GetChar();

            if(newData == '\r')
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
    return 0;
}