extern "C"{
    #include "project.h"
}

#include<CPString.h>

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
	UART_1_Start();
    
    CPString::string myString = "Hello World";
	UART_1_PutString(myString.c_str());
    UART_1_PutChar('\n');
    UART_1_PutChar('\r');
    
    myString = "Hello ";
    myString += "Wolrd";

	UART_1_PutString(myString.c_str());
    UART_1_PutChar('\n');
    UART_1_PutChar('\r');
    
    myString = "Hello ";
	UART_1_PutString((myString + "World").c_str());
    UART_1_PutChar('\n');
    UART_1_PutChar('\r');

	UART_1_PutString(myString.c_str());
    UART_1_PutChar('\n');
    UART_1_PutChar('\r');

    for(;;)
    {
        /* Place your application code here. */
    }
}