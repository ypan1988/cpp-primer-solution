#include <iostream>
using std::cout; using std::endl;

#include <iterator>
using std::begin; using std::end;

#include <vector>
using std::vector;

int main()
{
  vector<int> ivec = {0, 1, 2, 3, 4, 5};

  int int_arr[ivec.size()];
  for (auto idx = 0; idx != ivec.size(); ++idx)
    int_arr[idx] = ivec[idx];
  
  cout << "ivec: ";
  for (auto i : ivec) cout << i << " ";
  cout << endl;
  
  cout << "int_arr: ";
  for (auto i : int_arr) cout << i << " ";
  cout << endl;
  
  return 0;
}
