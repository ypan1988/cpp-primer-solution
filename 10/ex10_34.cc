#include <iostream>
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
using std::copy;

#include <iterator>
using std::ostream_iterator;

int main()
{
  vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  ostream_iterator<int> out_iter(cout, "\n");
  copy(ivec.crbegin(), ivec.crend(), out_iter);
  
  return 0;
}
