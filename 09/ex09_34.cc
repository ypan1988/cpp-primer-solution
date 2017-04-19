#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

int main()
{
  vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto iter = vi.begin();
  while (iter != vi.end()) {
    if (*iter % 2) {
      iter = vi.insert(iter, *iter);
      advance(iter, 2);
    } else {
      ++iter;
    }
  }

  for (auto ival : vi) {
    cout << ival << " ";
  }
  cout << endl;

  return 0;
}
