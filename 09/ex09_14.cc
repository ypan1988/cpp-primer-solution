#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <list>
using std::list;

int main()
{
  list<const char*> clst = {"C++", "primer", "5th"};
  vector<string> svec;
  svec.assign(clst.begin(), clst.end());

  for (const auto &str : svec)
    cout << str << endl;

  return 0;
}
