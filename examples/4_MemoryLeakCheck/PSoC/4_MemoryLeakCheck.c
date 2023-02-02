extern "C"{
	#include "project.h"
}

#include <CPString.h>
#include <stdlib.h>

int main(void)
{
	CyGlobalIntEnable; /* Enable global interrupts. */
	
	UART_1_Start();

	UART_1_PutString("////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////");
    UART_1_PutChar('\n'); 
    UART_1_PutChar('\r');
    
	{
		uint8_t counter = 0;
		do
		{
			if(counter <= 0xF){UART_1_PutChar('0');}
			UART_1_PutString(CPString::string(counter++,16).c_str());
			if(counter%32 == 0){UART_1_PutChar('\n'); UART_1_PutChar('\r');}
			else{UART_1_PutString(", ");}
		}
		while(counter);
	}

	UART_1_PutString("////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////");
    UART_1_PutChar('\n'); 
    UART_1_PutChar('\r');

	{
		int8_t counter = INT8_MIN;
		do
		{
			if(counter >= 0){UART_1_PutChar(' ');}
			if(abs(counter) <= 0xF){UART_1_PutChar(' ');}
			UART_1_PutString(CPString::string(counter++,16).c_str());
			if(counter%16 == 0){UART_1_PutChar('\n'); UART_1_PutChar('\r');}
			else{UART_1_PutString(", ");}
		}
		while(counter != INT8_MIN);
	}

	UART_1_PutString("////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////");
    UART_1_PutChar('\n'); 
    UART_1_PutChar('\r');

	{
		uint16_t counter = 0;
		do
		{
			if(counter <= 0xF){UART_1_PutChar('0');}
			if(counter <= 0xFF){UART_1_PutChar('0');}
			if(counter <= 0xFFF){UART_1_PutChar('0');}
			UART_1_PutString(CPString::string(counter++,16).c_str());
			if(counter%16 == 0){UART_1_PutChar('\n'); UART_1_PutChar('\r');}
			else{UART_1_PutString(", ");}
		}
		while(counter);
	}

	UART_1_PutString("////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////");
    UART_1_PutChar('\n'); 
    UART_1_PutChar('\r');

	for(;;)
	{
		/* Place your application code here. */
	}
}
