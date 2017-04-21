#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::fill_n;

int main()
{
  vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  fill_n(ivec.begin(), ivec.size(), 0);

  for (auto ival : ivec)
    cout << ival << " ";

  cout << endl;

  return 0;
}
