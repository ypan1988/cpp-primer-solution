#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

int main()
{
  vector<int> ivec1 = {0, 1, 1, 2};
  vector<int> ivec2 = {0, 1, 1, 2, 3, 5};

  auto it1 = ivec1.begin();
  auto it2 = ivec2.begin();
  while (it1 != ivec1.end() && it2 != ivec2.end() && *it1 == *it2) {
    ++it1;
    ++it2;
  }
  if (it1 == ivec1.end() || it2 == ivec2.end()) cout << "yes" << endl;
  else cout << "no" << endl;

  return 0;
} 
