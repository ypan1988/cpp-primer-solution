#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

int main()
{
  vector<int> v1 = {1, 3, 5, 7, 9, 12};
  vector<int> v2 = {1, 3, 9};

  std::cout << (v1 == v2 ? "v1 == v2" : "v1 != v2") << std::endl;

  return 0;
}
