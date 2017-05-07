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

#include <utility>
using std::pair;

int main()
{
  map<string, vector<pair<string, string>>> families;
  string line;
  while (getline(cin, line)) {
    istringstream str(line);
    string last_name, first_name, birthday;
    str >> last_name >> first_name >> birthday;
    families[last_name].push_back({first_name, birthday});
  }

  for (const auto &m : families) {
    cout << "Family: " << m.first << endl;
    for (const auto &v : m.second) {
      cout << "Name: " << v.first << " "
	   << "Birthday: " << v.second << endl;
    }
    cout << endl;
  }

  return 0;
}   
