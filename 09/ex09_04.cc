#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

bool CheckVal(int val, vector<int>::const_iterator begin, vector<int>::const_iterator end)
{
  while (begin != end) {
    if (*begin == val) return true;
    ++begin;
  }

  return false;
}

int main()
{
  vector<int> ivec = {1, 2, 3, 4, 5};
  cout << CheckVal(3, ivec.cbegin(), ivec.cend()) << endl;

  return 0;
}
