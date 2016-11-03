#include <iostream>
using std::cin; using std::cout; using std::endl;

// factorial of val is val*(val-1)*(val-2)...*2*1
int fact(int val)
{
  int ret = 1;			// local variable to hold the results as we
				// calculate it
  while (val > 1)
    ret *= val--;		// assign ret * val to ret and decrement val
  return ret;			// return the result;
}

int main()
{
  cout << "please enter an integer: ";
  int i;
  cin >> i;
  int j = fact(i);
  cout << i << "! is " << j << endl;

  return 0;
}
