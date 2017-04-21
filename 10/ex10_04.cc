#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::accumulate;

int main()
{
  vector<double> ivec = {1.1, 2.2, 3.3};

  double sum = accumulate(ivec.cbegin(), ivec.cend(), 0.0);
  cout << "sum: "<< sum << endl;

  return 0;
}
