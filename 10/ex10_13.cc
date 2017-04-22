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
  auto bound = partition(svec.begin(), svec.end(), isLarger5);

  for (auto iter = svec.begin(); iter != bound; ++iter) 
    cout << *iter << endl;
  
  return 0;
}
