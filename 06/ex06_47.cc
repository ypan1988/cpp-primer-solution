// g++ -std=c++11 ex06_47.cc
// g++ -std=c++11 -D NDEBUG ex06_47.cc

#include <iostream>
using std::cout; using std::cerr; using std::endl;

#include <vector>
using std::vector;

using iter = vector<int>::const_iterator;

void print(iter first, iter last)
{
  #ifndef NDEBUG
  // __func__ is a local static defined by the compiler that holds the
  // function's name
  cerr << __func__ << ": vector size is " << last - first << endl;
  #endif
  
  if (first != last) {
    cout << *first << endl;
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
