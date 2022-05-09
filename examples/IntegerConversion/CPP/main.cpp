#include <CPString.h>

using namespace CPString;

int main()
{

    std::cout<<(string("Hello this code snippet will test base conversion.\n"));
    std::cout<<(string("We'll convert ints and uints to multiple bases.\n"));

    std::cout<<(string("Give me a positive integer.\n\n"));
    
    int32_t a;
    std::cin >> a;

    std::cout<<("\nYou gave me the number ")<<((int32_t)a)<<(".\n\n");
    
    std::cout<<("We'll store this value as a uint variable called a.\n\n");
    std::cout<<("Printing a on base 2  { string(a,2 ) }: ")<<(string(a,2 ))<<(".\n\n");
    std::cout<<("Printing a on base 4  { string(a,4 ) }: ")<<(string(a,4 ))<<(".\n\n");
    std::cout<<("Printing a on base 8  { string(a,8 ) }: ")<<(string(a,8 ))<<(".\n\n");
    std::cout<<("Printing a on base 10 { string(a,10) }: ")<<(string(a,10))<<(".\n\n");
    std::cout<<("Printing a on base 16 { string(a,16) }: ")<<(string(a,16))<<(".\n\n");
    
    std::cout<<("\nBy default the letters on the output are Upper case.\n");
    std::cout<<("We can change that by calling SetLetterCase(LetterCase::Lower)\n\n");

    SetLetterCase(NumberConversion::LetterCase::Lower);
    std::cout<<("Let's print the values of a again\n\n");

    std::cout<<("Printing a on base 2  { string(a,2 ) }: ")<<(string(a,2 ))<<(".\n\n");
    std::cout<<("Printing a on base 4  { string(a,4 ) }: ")<<(string(a,4 ))<<(".\n\n");
    std::cout<<("Printing a on base 8  { string(a,8 ) }: ")<<(string(a,8 ))<<(".\n\n");
    std::cout<<("Printing a on base 10 { string(a,10) }: ")<<(string(a,10))<<(".\n\n");
    std::cout<<("Printing a on base 16 { string(a,16) }: ")<<(string(a,16))<<(".\n\n");
    

    std::cout<<(string("\nNow give me a negative integer.\n"));
    
    int32_t b;
    std::cin >> b;

    std::cout<<("\nYou gave me the number ")<<((int32_t)b)<<(".\n\n");
    
    std::cout<<("We'll store this value as a int variable called b.\n");
    std::cout<<("Printing b on base 2  { string(b,2 ) }: ")<<(string(b,2 ))<<(".\n\n");
    std::cout<<("Printing b on base 4  { string(b,4 ) }: ")<<(string(b,4 ))<<(".\n\n");
    std::cout<<("Printing b on base 8  { string(b,8 ) }: ")<<(string(b,8 ))<<(".\n\n");
    std::cout<<("Printing b on base 10 { string(b,10) }: ")<<(string(b,10))<<(".\n\n");
    std::cout<<("Printing b on base 16 { string(b,16) }: ")<<(string(b,16))<<(".\n\n");
    
    std::cout<<("\nBy default int conversion is signed.\n");
    std::cout<<("We can change that by calling SetIntFormat(IntFormat::Absolute)\n\n");

    SetIntFormat(NumberConversion::IntFormat::Absolute);
    
    std::cout<<(string("Let's print the values of b again\n\n"));

    std::cout<<("Printing b on base 2  { string(b,2 ) }: ")<<(string(b,2 ))<<(".\n\n");
    std::cout<<("Printing b on base 4  { string(b,4 ) }: ")<<(string(b,4 ))<<(".\n\n");
    std::cout<<("Printing b on base 8  { string(b,8 ) }: ")<<(string(b,8 ))<<(".\n\n");
    std::cout<<("Printing b on base 10 { string(b,10) }: ")<<(string(b,10))<<(".\n\n");
    std::cout<<("Printing b on base 16 { string(b,16) }: ")<<(string(b,16))<<(".\n\n");
}

void loop()
{

}
