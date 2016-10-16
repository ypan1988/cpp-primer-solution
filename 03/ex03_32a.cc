#include <iostream>
using std::cout; using std::endl;

int main()
{
  int ia1[10], ia2[10];
  for (auto i = 0; i != 10; ++i) ia1[i] = i;
  for (auto i = 0; i != 10; ++i) ia2[i] = ia1[i];

  cout << "ia1: " << endl;
  for (auto i : ia1) cout << i << " ";
  cout << endl;

  cout << "ia2: " << endl;
  for (auto i : ia2) cout << i << " ";
  cout << endl;
  
  return 0;
}
