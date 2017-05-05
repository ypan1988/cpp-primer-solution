#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <algorithm>
using std::copy;

#include <iterator>
using std::ostream_iterator;

int main()
{
  ostream_iterator<int> out_iter(cout, " ");

  vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  copy(ivec.cbegin(), ivec.cend(), out_iter);
  cout << endl;

  vector<int> ivec2(ivec.begin() + 3, ivec.begin() + 8);
  copy(ivec2.cbegin(), ivec2.cend(), out_iter);
  cout << endl;

  list<int> ilst(ivec2.crbegin(), ivec2.crend());
  copy(ivec2.crbegin(), ivec2.crend(), out_iter);
  cout << endl;

  return 0;
}
