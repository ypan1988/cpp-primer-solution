#include <iostream>
using std::cin;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;

#include "Sales_item.h"

bool compareIsbn
int main()
{
  istream_iterator<Sales_iterm> in_iter(cin), eof;
  vector<Sales_iterm> vec(in_iter, eof);

  sort(vec.begin(), vec.end(),
       [](const Sales_data &obj1, const Sales_data &obj2)
       { return obj1.isbn() < obj2.isbn(); });

  return 0;
}
