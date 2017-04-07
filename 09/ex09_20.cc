#include <iostream>
using std::cout; using std::endl;

#include <deque>
using std::deque;

#include <list>
using std::list;

int main()
{
  list<int> ilst = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  deque<int> ideq1, ideq2;

  for (const auto &ival : ilst) {
    ival % 2 == 0 ? ideq1.push_back(ival) : ideq2.push_back(ival);
  }

  for (const auto &ival : ideq1) {
    cout << ival << " ";
  }
  cout << endl;

  for (const auto &ival : ideq2) {
    cout << ival << " ";
  }
  cout << endl;

  return 0;
}
