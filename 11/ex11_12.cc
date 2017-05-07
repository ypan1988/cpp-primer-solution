#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <utility>
using std::pair;

int main()
{
  vector<pair<string, int>> vec;
  
  string str;
  int ival;
  while (cin >> str >> ival) {
    vec.push_back({str, ival});
  }

  for (const auto &p : vec) {
    cout << p.first << " " << p.second << endl;
  }

  return 0;
}
