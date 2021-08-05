#include <iostream>
#include <CPString.h>

int main()
{
    // Const char array
    std::cout<<CPString::string("01\n");
    
    //char array
    char char_array[4] = {'0','2','\n','\0'};
    std::cout<<CPString::string(char_array);
    
    
    
    return 0;
}
