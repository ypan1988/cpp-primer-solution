#include <iostream>
using std::cout; using std::endl;

int main()
{
  short sval = 32767; ++sval;
  cout << sval << endl;
  
  unsigned uival = 0; --uival;
  cout << uival << endl;
  
  unsigned short usval = 65535; ++usval;
  cout << usval << endl;

  return 0;
}

