#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

int main()
{
  constexpr size_t sz = 4;
  vector<int> ivec1 = {0, 1, 2, 3};
  vector<int> ivec2 = {0, 3, 2, 1};

  cout << "ivec1: ";
  for (auto i : ivec1) cout << i << " ";
  cout << endl;

  cout << "ivec2: ";
  for (auto i : ivec2) cout << i << " ";
  cout << endl;
  
  if (ivec1 == ivec2) cout << "ivec1 and ivec2 are equal." << endl;
  else cout << "ivec1 and ivec2 are not equal." << endl;
      
  return 0;
}
