#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::partition;

bool isLarger5(const string &s)
{
  return s.size() >= 5;
}

int main()
{
  vector<string> svec = {"aaa", "Hello", "bbb", "world!!!", "ccc"};
  partition(svec.begin(), svec.end(), isLarger5);

  for (const auto &s : svec) cout << s << endl;
  
  return 0;
}
