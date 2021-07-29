#include <iostream>
#include <EmbeddedString.h>

int main()
{
    std::cout<<EString::string("Hello this code snippet will test base conversion.\n");
    std::cout<<EString::string("We'll convert ints and uints to multiple bases.\n");

    uint a;

    std::cout<<EString::string("Give me a positive integer.\n\n");
    std::cin>>a;
    std::cout<<"\nYou gave me the number "<<(uint)a<<".\n\n";
    
    std::cout<<EString::string("We'll store this value as a uint variable called a.\n");
    std::cout<<EString::string("Printing a on base 2  { string(a,2 ) }: ")<<EString::string(a,2 )<<".\n";
    std::cout<<EString::string("Printing a on base 4  { string(a,4 ) }: ")<<EString::string(a,4 )<<".\n";
    std::cout<<EString::string("Printing a on base 8  { string(a,8 ) }: ")<<EString::string(a,8 )<<".\n";
    std::cout<<EString::string("Printing a on base 10 { string(a,10) }: ")<<EString::string(a,10)<<".\n";
    std::cout<<EString::string("Printing a on base 16 { string(a,16) }: ")<<EString::string(a,16)<<".\n";
    
    std::cout<<EString::string("\nBy default the letters on the output are Upper case.\n");
    std::cout<<EString::string("We can change that by calling EString::SetLetterCase(EString::LetterCase::Lower)\n");

    EString::SetLetterCase(EString::LetterCase::Lower);
    std::cout<<EString::string("Let's print the values of a again\n\n");

    std::cout<<EString::string("Printing a on base 2  { string(a,2 ) }: ")<<EString::string(a,2 )<<".\n";
    std::cout<<EString::string("Printing a on base 4  { string(a,4 ) }: ")<<EString::string(a,4 )<<".\n";
    std::cout<<EString::string("Printing a on base 8  { string(a,8 ) }: ")<<EString::string(a,8 )<<".\n";
    std::cout<<EString::string("Printing a on base 10 { string(a,10) }: ")<<EString::string(a,10)<<".\n";
    std::cout<<EString::string("Printing a on base 16 { string(a,16) }: ")<<EString::string(a,16)<<".\n";
    
    int b;

  	std::cout<<EString::string("\nNow give me a negative integer.\n\n");
    std::cin>>b;
    std::cout<<"\nYou gave me the number "<<(uint)a<<".\n\n";
    
    std::cout<<EString::string("We'll store this value as a int variable called b.\n");
    std::cout<<EString::string("Printing b on base 2  { string(b,2 ) }: ")<<EString::string(b,2 )<<".\n";
    std::cout<<EString::string("Printing b on base 4  { string(b,4 ) }: ")<<EString::string(b,4 )<<".\n";
    std::cout<<EString::string("Printing b on base 8  { string(b,8 ) }: ")<<EString::string(b,8 )<<".\n";
    std::cout<<EString::string("Printing b on base 10 { string(b,10) }: ")<<EString::string(b,10)<<".\n";
    std::cout<<EString::string("Printing b on base 16 { string(b,16) }: ")<<EString::string(b,16)<<".\n";
    
    std::cout<<EString::string("\nBy default int conversion is signed.\n");
    std::cout<<EString::string("We can change that by calling EString::SetIntFormat(EString::IntFormat::Absolute)\n");
    EString::SetIntFormat(EString::IntFormat::Absolute);
    std::cout<<EString::string("Let's print the values of a again\n");

    std::cout<<EString::string("Printing b on base 2  { string(b,2 ) }: ")<<EString::string(b,2 )<<".\n";
    std::cout<<EString::string("Printing b on base 4  { string(b,4 ) }: ")<<EString::string(b,4 )<<".\n";
    std::cout<<EString::string("Printing b on base 8  { string(b,8 ) }: ")<<EString::string(b,8 )<<".\n";
    std::cout<<EString::string("Printing b on base 10 { string(b,10) }: ")<<EString::string(b,10)<<".\n";
    std::cout<<EString::string("Printing b on base 16 { string(b,16) }: ")<<EString::string(b,16)<<".\n";
    
    return 0;
}
