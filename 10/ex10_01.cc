#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::count;

int main()
{
  vector<int> ivec = {1, 1, 1, 1, 2, 2, 2, 3, 3, 4};

  int ival = 1;
  cout << count(ivec.cbegin(), ivec.cend(), ival)
       << " elements have value " << ival << endl;

  return 0;
}
