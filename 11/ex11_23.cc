#include <iostream>
using std::cin; using std::cout; using std::endl;

#include<sstream>
using std::istringstream;

#include <cstddef>
using std::size_t;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <map>
using std::multimap;

int main()
{
  multimap<string, string> families;
  string line;
  while (getline(cin, line)) {
    istringstream str(line);
    string last_name, first_name;
    str >> last_name >> first_name;
    families.insert({last_name, first_name});
  }

  for (const auto &m : families) {
    cout << "Family: " << m.first << endl
         << "Children: " << m.second << endl;
  }

  return 0;
}
