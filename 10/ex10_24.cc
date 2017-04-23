#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::find_if;

#include <functional>
using namespace std::placeholders;
using std::bind;

bool check_size(const string &s, string::size_type sz)
{
  return s.size() < sz;
}

int main()
{
  vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  string s("hello");

  auto iter = find_if(ivec.begin(), ivec.end(), bind(check_size, s, _1));
  
  cout << *iter << endl;
  
  return 0;
}
