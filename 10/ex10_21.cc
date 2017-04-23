#include <iostream>
using std::cout; using std::endl;

int main()
{
  int ival = 10;

  auto f = [&ival] () -> bool { --ival; return ival == 0; };

  while (!f()) cout << ival << endl;
  
  return 0;
}
