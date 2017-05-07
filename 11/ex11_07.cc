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
using std::map;

int main()
{
  map<string, vector<string>> families;
  string line;
  while (getline(cin, line)) {
    istringstream str(line);
    string last_name, first_name;
    str >> last_name >> first_name;
    families[last_name].push_back(first_name);
  }

  for (const auto &m : families) {
    cout << "Family: " << m.first << endl
	 << "Children: ";
    for (const auto &v : m.second) {
      cout << v << " ";
    }
    cout << endl;
  }

  return 0;
}
