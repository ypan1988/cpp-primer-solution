#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <forward_list>
using std::forward_list;

#include <iterator>
using std::advance;

int main()
{
  // the program on page 354
  // silly loop to remove even-valued elements and insert a duplicate of odd-valued elements
  vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto iter = vi.begin();       // call begin, not cbegin because we're changing vi
  while (iter != vi.end()) {
    if (*iter % 2) {
      iter = vi.insert(iter, *iter); // duplicate the current elements
      iter += 2;                     // advance past this element and the one inserted before it
    } else {
      iter = vi.erase(iter);    // remove even elements
      // don't advance the iterator; iter denotes the element after the one we erased
    }
  }

  for (auto ival : vi) {
    cout << ival << " ";
  }
  cout << endl;

  // list
  list<int> li = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto iter2 = li.begin();
  while (iter2 != li.end()) {
    if (*iter2 % 2) {
      iter2 = li.insert(iter2, *iter2);
      advance(iter2, 2);
    } else {
      iter2 = li.erase(iter2);
    }
  }

  for (auto ival : li) {
    cout << ival << " ";
  }
  cout << endl;

  // forward_list
  forward_list<int> fli = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto prev = fli.before_begin();
  auto curr = fli.begin();
  while (curr != fli.end()) {
    if (*curr % 2) {
      curr = fli.insert_after(prev, *curr);
      advance(prev, 2); advance(curr, 2);
    } else {
      curr = fli.erase_after(prev);
    }
  }

  for (auto ival : fli) {
    cout << ival << " ";
  }
  cout << endl;


  return 0;
}
