#include <iostream>
using std::cout;
using std::endl;

#include <initializer_list>
using std::initializer_list;

int sum(initializer_list<int> il)
{
  int result = 0;
  for (auto beg = il.begin(); beg != il.end(); ++beg)
    result += *beg;
  return result;
}

int main()
{
  cout << sum({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) << endl;

  return 0;
}
