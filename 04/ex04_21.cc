#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

int main()
{
  vector<int> ivec = {0, 1, 2, 3, 4};

  for (auto i : ivec) cout << i << " ";
  cout << endl;
  
  for (auto &i : ivec) {
    i = (!(i % 2) ? (2 * i) : i);
  }

  for (auto i : ivec) cout << i << " ";
  cout << endl;

  return 0;
}
