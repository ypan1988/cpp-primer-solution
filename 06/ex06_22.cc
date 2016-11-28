#include <iostream>
using std::cout;
using std::endl;

void swap(int *ip1, int *ip2)
{
  int temp = *ip1;
  *ip1 = *ip2;
  *ip2 = temp;
}
  
int main()
{
  int i1 = 10, i2 = 20;
  swap(&i1, &i2);

  cout << i1 << endl;
  cout << i2 << endl;

  return 0;
}
