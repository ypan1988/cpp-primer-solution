#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

int main()
{
  vector<int> ivec1, ivec2;
  
  for (auto i = 0; i != 10; ++i) ivec1.push_back(i);
  ivec2 = ivec1;

  cout << "ivec1: " << endl;
  for (auto i : ivec1) cout << i << " ";
  cout << endl;

  cout << "ivec2: " << endl;
  for (auto i : ivec2) cout << i << " ";
  cout << endl;
  
  return 0;
}
