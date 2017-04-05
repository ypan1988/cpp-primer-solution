#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

vector<int>::const_iterator FindVal(int val, vector<int>::const_iterator begin, vector<int>::const_iterator end)
{
  while (begin != end) {
    if (*begin == val) return begin;
    ++begin;
  }

  return end;
}

int main()
{
  vector<int> ivec = {1, 2, 3, 4, 5};
  auto iter = FindVal(3, ivec.cbegin(), ivec.cend());
  cout << *iter << endl;

  return 0;
}
