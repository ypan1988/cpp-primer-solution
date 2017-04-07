#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

#include <list>
using std::list;

int main()
{
  vector<int> v1 = {1, 3, 5, 7, 9, 12};
  list<int> v2 = {1, 3, 9};

  std::cout << (v1 == vector<int>(v1.begin(), v1.end()) ? "v1 == v2" : "v1 != v2") << std::endl;

  return 0;
}
