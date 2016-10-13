#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

int main()
{
  vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  for (auto it = ivec.begin(); it != ivec.end(); ++it)
    *it *= 2;

  for (auto it = ivec.begin(); it != ivec.end(); ++it)
    cout << *it << " ";
  cout << endl;

  return 0;
} 
