#include <iostream>
using std::cout; using std::endl;

#include <forward_list>
using std::forward_list;

int main()
{
  forward_list<int> ilst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  auto prev = ilst.before_begin();
  auto curr = ilst.begin();
  while (curr != ilst.end()) {
    if (*curr % 2) curr = ilst.erase_after(prev);
    else {
      prev = curr;
      ++curr;
    }
  }

  cout << "forward_list: ";
  for (const auto &ival : ilst)
    cout << ival << " ";
  cout << endl;

  return 0;
}
