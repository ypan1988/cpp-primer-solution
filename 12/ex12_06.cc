#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

vector<int>* factory()
{
  return new vector<int>{};
}

vector<int>* read_factory(vector<int> *vec)
{
  int value;
  while (cin >> value) {
    vec->push_back(value);
  }

  return vec;
}

void print_factory(vector<int> *vec)
{
  for (auto i : *vec)
    cout << i << endl;
}

int main()
{
  vector<int>* vec = read_factory(factory());
  print_factory(vec);
  delete vec;

  return 0;
}
