#include <iostream>
using std::cout; using std::endl;

#include <cstddef>
using std::size_t;

int main()
{
  constexpr size_t sz = 4;
  int ia1[sz] = {0, 1, 2, 3};
  int ia2[sz] = {0, 3, 2, 1};

  cout << "ia1: ";
  for (auto i : ia1) cout << i << " ";
  cout << endl;

  cout << "ia2: ";
  for (auto i : ia2) cout << i << " ";
  cout << endl;

  bool check = true;
  for (auto i = 0; i != sz; ++i)
    if (*(ia1 + i) != *(ia2 + i))
      check = false;
  
  if (check) cout << "ia1 and ia2 are equal." << endl;
  else cout << "ia1 and ia2 are not equal." << endl;
      
  return 0;
}
