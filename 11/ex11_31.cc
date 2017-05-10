#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <map>
using std::map;

int main()
{
  // map from author to title; there can be multiple titles per author
  multimap<string, string> authors;
  // add data to authors
  authors.insert({"Alain de Botton", "On Love"});
  authors.insert({"Alain de Botton", "Status Anxiety"});
  authors.insert({"Alain de Botton", "Art of Travel"});
  authors.insert({"Alain de Botton", "Architecture of Happiness"});

  return 0;
}
