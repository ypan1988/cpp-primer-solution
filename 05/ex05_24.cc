#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <stdexcept>
using std::runtime_error;

int main()
{
  cout << "please enter two integers: ";
  int ival1, ival2;
  cin >> ival1 >> ival2;
  if (ival2 == 0) throw runtime_error("divisor is equal to zero");
  cout << ival1 << " divided by " << ival2
       << " is " << ival1 / ival2 << endl;

  return 0;
}
