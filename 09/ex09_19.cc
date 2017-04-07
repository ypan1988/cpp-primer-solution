#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <string>
using std::string;

#include <list>
using std::list;

int main()
{
  string word;
  list<string> slst;

  while (cin >> word)
    slst.push_back(word);

  for (const auto &str : slst) {
    cout << str << endl;
  }

  return 0;
}
