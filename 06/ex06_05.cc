#include <iostream>
using std::cin; using std::cout; using std::endl;

int abs(int val) {
  return val >= 0 ? val : -val;
}

int main()
{
  cout << "please enter an integer: ";
  int i;
  cin >> i;
  int j = abs(i);
  cout << "The absolute value of " << i
       << " is " << j << endl;

  return 0;
}
