#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
  cout << "please enter two integers: ";
  int ival1, ival2;
  cin >> ival1 >> ival2;
  cout << ival1 << " divided by " << ival2
       << " is " << ival1 / ival2 << endl;

  return 0;
}
