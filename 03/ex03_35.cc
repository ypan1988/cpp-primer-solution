#include <iostream>
using std::cout; using std::endl;

#include <cstddef>
using std::size_t;

int main()
{
  constexpr size_t sz = 10;
  int ia[sz] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  for (auto i : ia) cout << i << " ";
  cout << endl;

  for (auto ptr = ia; ptr != ia + sz; ++ptr) *ptr = 0;

  for (auto i : ia) cout << i << " ";
  cout << endl;
  
  return 0;
}
