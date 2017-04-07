#include <iostream>
using std::cout; using std::endl;

#include <array>
using std::array;

#include <vector>
using std::vector;

#include <list>
using std::list;

int main()
{
  array<int, 11> ia = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
  vector<int> ivec(ia.begin(), ia.end());
  list<int> ilst(ia.begin(), ia.end());

  auto iter1 = ivec.begin();
  while(iter1 != ivec.end()) {
    if (!*iter1 % 2) ivec.erase(iter1);
    else ++iter1;
  }

  auto iter2 = ilst.begin();
  while(iter2 != ilst.end()) {
    if (*iter2 % 2) ilst.erase(iter2);
    else ++iter2;
  }

  cout << "vector: ";
  for (const auto &ival : ivec)
    cout << ival << " ";
  cout << endl;

  cout << "list: ";
  for (const auto &ival : ilst)
    cout << ival << " ";
  cout << endl;

  return 0;
}
