#include <iostream>
using std::cout;
using std::endl;

#include "StrBlob.h"

int main()
{
  const StrBlob b1 = {"a", "an", "the"};
  StrBlob b2 = {"Hello", "World", "!"};

  cout << b1.front() << " " << b1.back() << endl;
  b2.back() = "!!!";
  cout << b2.front() << " " << b2.back() << endl;

  return 0;
}
