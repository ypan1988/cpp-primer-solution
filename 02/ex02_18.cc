#include <iostream>

int main()
{
  int ival1 = 42, ival2 = 1024;
  int *p1 = &ival1, *p2 = &ival2;

  std::cout << ival1 << " " << *p1 << std::endl;
  p1 = p2;			// change the value of a pointer
  std::cout << *p1 << std::endl;

  std::cout << ival2 << " " << *p2 << std::endl;
  *p2 = 0;			// change the value to which the pointer points
  std::cout << *p2 << std::endl;

  return 0;
} 
