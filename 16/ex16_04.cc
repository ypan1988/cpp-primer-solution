#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <list>
using std::list;

template <typename Iterator, typename Valuetype>
Iterator find(Iterator first, Iterator last, const Valuetype &value)
{
  while (*first != value && first != last) ++first;
  return first;
}

int main()
{
  vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  cout << (ivec.cend() != find(ivec.begin(), ivec.end(), 5) ? "found" : "not found")
       << endl;
  
  list<string> slst = {"aa", "bb", "cc", "dd", "ee", "ff", "gg"};
  cout << (slst.cend() != find(slst.begin(), slst.end(), "zz") ? "found" : "not found")
       << endl;
  
  return 0;
}
