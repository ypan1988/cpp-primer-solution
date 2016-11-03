#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <stdexcept>
using std::runtime_error;

int main()
{
  cout << "please enter two integers: ";
  int ival1, ival2;
  while (cin >> ival1 >> ival2) {
    try {
      if (ival2 == 0) throw runtime_error("divisor is equal to zero");
      cout << ival1 << " divided by " << ival2
       << " is " << ival1 / ival2 << endl;
    } catch (runtime_error err) {
      cout << err.what()
	   << "\nTry Again? Enter y or n" << endl;
      char c;
      cin >> c;
      if (!cin || c == 'n')
	break;
    }
    cout << "please enter two integers: ";
  }
  
  return 0;
}
