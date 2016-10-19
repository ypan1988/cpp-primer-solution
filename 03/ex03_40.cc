#include <iostream>
using std::cout; using std::endl;

#include <cstring>
using std::strcpy; using std::strcat;

int main()
{
  const char ca1[] = "Hello";
  const char ca2[] = "World";

  char largeStr[12];
  strcpy(largeStr, ca1);
  strcat(largeStr, " ");
  strcat(largeStr, ca2);

  cout << "ca1: " << ca1 << endl;
  cout << "ca2: " << ca2 << endl;
  cout << "largeStr: " << largeStr << endl;

  return 0;
}
