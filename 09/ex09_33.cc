#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

int main()
{
  vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto begin = v.begin();
  while (begin != v.end()) {
    ++begin;               // advance begin because we want to insert after this
    // v.insert(begin, 42);
    begin = v.insert(begin, 42); // insert the new value
    ++begin;                     //  // advance begin past the element we just added
  }

  for (auto ival : v) {
    cout << ival << " ";
  }
  cout << endl;

  return 0;
}
