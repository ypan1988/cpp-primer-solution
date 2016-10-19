#include <iostream>
using std::cout; using std::endl;

#include <iterator>
using std::begin; using std::end;

#include <vector>
using std::vector;

int main()
{
  int int_arr[] = {0, 1, 2, 3, 4, 5};

  // ivec has six elements; each is a copy of the corresponding element in
  // int_arr
  vector<int> ivec(begin(int_arr), end(int_arr));

  cout << "int_arr: ";
  for (auto i : int_arr) cout << i << " ";
  cout << endl;
  
  cout << "ivec: ";
  for (auto i : ivec) cout << i << " ";
  cout << endl;
  
  return 0;
}
