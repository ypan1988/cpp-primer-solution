#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <memory>
using std::make_shared;
using std::shared_ptr;

shared_ptr<vector<int>> factory()
{
  return make_shared<vector<int>>();
}

shared_ptr<vector<int>> read_factory(shared_ptr<vector<int>> vec)
{
  int value;
  while (cin >> value) {
    vec->push_back(value);
  }

  return vec;
}

void print_factory(shared_ptr<vector<int>> vec)
{
  for (auto i : *vec)
    cout << i << endl;
}

int main()
{
  shared_ptr<vector<int>> vec = read_factory(factory());
  print_factory(vec);

  return 0;
}
