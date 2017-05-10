#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <map>
using std::multimap;

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

  string search_item("Stanley B. Lippman"); // author we'll look for
  string book("C++ Primer");		    // the book we'll look for
  auto entries = authors.count(search_item); // number of elements
  auto iter = authors.find(search_item);     // first entry for this author
  while (entries) {
    if (iter->second == book) {
      authors.erase(iter);
      break;
    }
    ++iter;
    --entries;
  }

  for (const auto &p : authors) {
    cout << p.first << " "
	 << p.second << endl;
  }
  cout << endl;

  book = "C++ Primer Plus";
  entries = authors.count(search_item); // number of elements
  iter = authors.find(search_item);     // first entry for this author
  while (entries) {
    if (iter->second == book) {
      authors.erase(iter);
      break;
    }
    ++iter;
    --entries;
  }

  for (const auto &p : authors) {
    cout << p.first << " "
	 << p.second << endl;
  }
  cout << endl;

  return 0;
}
