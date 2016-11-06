#include <iostream>
using std::cin; using std::cout; using std::endl;

void swap(int *ip1, int *ip2) {
  int temp = *ip1;
  *ip1 = *ip2;
  *ip2 = temp;
}

int main()
{
  cout << "please enter two integers: ";

  int ival1, ival2;
  cin >> ival1 >> ival2;

  swap(&ival1, &ival2);
  
  cout << ival1 << " "
       << ival2 << endl;

  return 0;
}
