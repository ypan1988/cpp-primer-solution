#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::count;

int main()
{
  vector<string> svec = {"aaa", "aaa", "aaa", "aaa", "bbb", "bbb", "bbb", "ccc",
                         "ccc", "ddd"};

  string s = "aaa";
  cout << count(svec.cbegin(), svec.cend(), s)
       << " strings have value " << s << endl;

  return 0;
}
