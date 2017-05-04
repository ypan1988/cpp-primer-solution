#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;
using std::find_if;
using std::accumulate;

#include <iterator>
using std::istream_iterator;

#include "Sales_item.h"

int main()
{
  istream_iterator<Sales_item> in_iter(cin), eof;
  vector<Sales_item> vec(in_iter, eof);

  sort(vec.begin(), vec.end(),
       [](const Sales_item &obj1, const Sales_item &obj2)
       { return obj1.isbn() < obj2.isbn(); });

  Sales_item sum;
  auto iter = vec.cbegin();
  while (iter != vec.cend()) {
    auto start = iter;
    auto end = vec.cend();
    end = find_if(start, end,
		  [start](const Sales_item &trans) 
		  { return trans.isbn() != start->isbn(); });
    cout << accumulate(start, end, Sales_item(start->isbn())) << endl;
    iter = end;
  }

  return 0;
}
