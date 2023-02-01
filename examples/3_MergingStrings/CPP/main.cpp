#include <CPString.h>

int main()
{
  CPString::string str("Hello ");

  str += CPString::string("Wolrd");

  std::cout<<str;
}