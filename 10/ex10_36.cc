#include <iostream>
using std::cout; using std::endl;

#include <list>
using std::list;

#include <algorithm>
using std::find;

int main()
{
  list<int> ilst = {1, 2, 3, 0, 4, 5, 6, 0, 7, 8, 9};

  auto zero = find(ilst.crbegin(), ilst.crend(), 0);
  auto iter = zero.base();
  while (iter != ilst.end()) {
    cout << *iter++ << endl;
  }
  
  return 0;
}
