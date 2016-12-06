#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

using iter = vector<int>::const_iterator;

void print(iter first, iter last)
{
  if (first != last) {
    cout << *first << " ";
    print(++first, last);
  }
}

int main()
{
  vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  print(ivec.cbegin(), ivec.cend());
  cout << endl;
  
  return 0;
}
