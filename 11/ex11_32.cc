#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <map>
using std::map; using std::multimap; 

#include <set>
using std::set;

int main()
{
  // map from author to title; there can be multiple titles per author
  multimap<string, string> authors;
  // add data to authors
  authors.insert({"Alain de Botton", "On Love"});
  authors.insert({"Alain de Botton", "Status Anxiety"});
  authors.insert({"Stanley B. Lippman", "Inside the C++ Object Model"});
  authors.insert({"Stanley B. Lippman", "C++ Primer"});
  authors.insert({"Alain de Botton", "Art of Travel"});
  authors.insert({"Alain de Botton", "Architecture of Happiness"});

  for (const auto &p : authors) {
    cout << p.first << " "
	 << p.second << endl;
  }
  cout << endl;

  map<string, set<string>> authors2;
  for (const auto &p : authors) {
    authors2[p.first].insert(p.second);
  }

  for (const auto &p : authors2) {
    for (const auto &s : p.second) {
      cout << p.first << " "
	   << s << endl;
    }
  }
  cout << endl;


  return 0;
}
