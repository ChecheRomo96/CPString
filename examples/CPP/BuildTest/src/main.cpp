#include <iostream>
#include <CPString.h>

int main()
{
    //uint8_t base 2
    float uint8 = 0.0000000012345678901234567890;
    std::cout<<CPString::string(uint8 ,40 )<<std::endl;

    
    
    
    
    return 0;
}
