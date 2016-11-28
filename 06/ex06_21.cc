#include <iostream>
using std::cout;
using std::endl;

int max_int(const int ival, const int *ip) {
  return (ival > *ip) ? ival : *ip;
}

int main()
{
  int i = 50;
  
  cout << max_int(10, &i) << endl;
  cout << max_int(100, &i) << endl;

  return 0;
}
