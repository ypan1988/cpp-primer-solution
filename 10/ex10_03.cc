#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::accumulate;

int main()
{
  vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int sum = accumulate(ivec.cbegin(), ivec.cend(), 0);
  cout << "sum: "<< sum << endl;

  return 0;
}
