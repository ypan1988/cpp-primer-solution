#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

int main()
{
  vector<int> ivec;

  cout << ivec.at(0) << endl;
  cout << ivec[0] << endl;       // Segmentation fault
  cout << ivec.front() << endl;  // Segmentation fault
  cout << *ivec.begin() << endl; // Segmentation fault

  return 0;
}
