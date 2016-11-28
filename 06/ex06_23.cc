#include <iostream>
using std::cout;
using std::endl;

#include <cstddef>
using std::size_t;

void print(const int ival) { cout << ival << endl; }
void print(const int* ia, size_t size) {
  for (size_t i = 0; i != size; ++i) {
    cout << ia[i] << " ";
  }
  cout << endl;
}

int main()
{
  int i = 0, j[2] = {0, 1};
  print(i);
  print(j, 2);

  return 0;
}
