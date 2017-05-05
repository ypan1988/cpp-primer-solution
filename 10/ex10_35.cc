#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

int main()
{
  vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  auto iter = ivec.cend();
  while (iter != ivec.begin()) {
    cout << *(--iter) << endl;
  }
  
  return 0;
}
