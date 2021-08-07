#include <CPString.h>

int main()
{
    float var = 0.12345678;
    CPString::string str(var ,11 );
    std::cout<<str<<std::endl;    str.resize(6);
    std::cout<<str<<std::endl;
    
    
    
    return 0;
}
