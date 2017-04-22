#include <iostream>
using std::cout; using std::endl;

int main()
{
  int a = 1;
  auto f = [a](int b)
    { return a + b; };

  cout << f(2) << endl;

  return 0;
}
