#include <iostream>
#include <CPString.h>

int main()
{
    std::cout<<CPString::string("Hello this code snippet will test base conversion.\n");
    std::cout<<CPString::string("We'll convert ints and uints to multiple bases.\n");

    uint32_t a;

    std::cout<<CPString::string("Give me a positive integer.\n\n");
    std::cin>>a;
    std::cout<<"\nYou gave me the number "<<(unsigned int)a<<".\n\n";
    
    std::cout<<CPString::string("We'll store this value as a uint variable called a.\n\n");
    std::cout<<CPString::string("Printing a on base 2  { string(a,2 ) }: ")<<CPString::string(a,2 )<<".\n";
    std::cout<<CPString::string("Printing a on base 4  { string(a,4 ) }: ")<<CPString::string(a,4 )<<".\n";
    std::cout<<CPString::string("Printing a on base 8  { string(a,8 ) }: ")<<CPString::string(a,8 )<<".\n";
    std::cout<<CPString::string("Printing a on base 10 { string(a,10) }: ")<<CPString::string(a,10)<<".\n";
    std::cout<<CPString::string("Printing a on base 16 { string(a,16) }: ")<<CPString::string(a,16)<<".\n";
    
    std::cout<<CPString::string("\nBy default the letters on the output are Upper case.\n");
    std::cout<<CPString::string("We can change that by calling CPString::SetLetterCase(CPString::LetterCase::Lower)\n\n");

    CPString::SetLetterCase(CPString::LetterCase::Lower);
    std::cout<<CPString::string("Let's print the values of a again\n\n");

    std::cout<<CPString::string("Printing a on base 2  { string(a,2 ) }: ")<<CPString::string(a,2 )<<".\n";
    std::cout<<CPString::string("Printing a on base 4  { string(a,4 ) }: ")<<CPString::string(a,4 )<<".\n";
    std::cout<<CPString::string("Printing a on base 8  { string(a,8 ) }: ")<<CPString::string(a,8 )<<".\n";
    std::cout<<CPString::string("Printing a on base 10 { string(a,10) }: ")<<CPString::string(a,10)<<".\n";
    std::cout<<CPString::string("Printing a on base 16 { string(a,16) }: ")<<CPString::string(a,16)<<".\n";
    
    int32_t b;

  	std::cout<<CPString::string("\nNow give me a negative integer.\n\n");
    std::cin>>b;
    std::cout<<"\nYou gave me the number "<<b<<".\n\n";
    
    std::cout<<CPString::string("We'll store this value as a int variable called b.\n");
    std::cout<<CPString::string("Printing b on base 2  { string(b,2 ) }: ")<<CPString::string(b,2 )<<".\n";
    std::cout<<CPString::string("Printing b on base 4  { string(b,4 ) }: ")<<CPString::string(b,4 )<<".\n";
    std::cout<<CPString::string("Printing b on base 8  { string(b,8 ) }: ")<<CPString::string(b,8 )<<".\n";
    std::cout<<CPString::string("Printing b on base 10 { string(b,10) }: ")<<CPString::string(b,10)<<".\n";
    std::cout<<CPString::string("Printing b on base 16 { string(b,16) }: ")<<CPString::string(b,16)<<".\n";
    
    std::cout<<CPString::string("\nBy default int conversion is signed.\n");
    std::cout<<CPString::string("We can change that by calling CPString::SetIntFormat(CPString::IntFormat::Absolute)\n\n");

    CPString::SetIntFormat(CPString::IntFormat::Absolute);
    
    std::cout<<CPString::string("Let's print the values of b again\n\n");

    std::cout<<CPString::string("Printing b on base 2  { string(b,2 ) }: ")<<CPString::string(b,2 )<<".\n";
    std::cout<<CPString::string("Printing b on base 4  { string(b,4 ) }: ")<<CPString::string(b,4 )<<".\n";
    std::cout<<CPString::string("Printing b on base 8  { string(b,8 ) }: ")<<CPString::string(b,8 )<<".\n";
    std::cout<<CPString::string("Printing b on base 10 { string(b,10) }: ")<<CPString::string(b,10)<<".\n";
    std::cout<<CPString::string("Printing b on base 16 { string(b,16) }: ")<<CPString::string(b,16)<<".\n";

    return 0;
}
