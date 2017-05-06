#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <list>
using std::list;

#include <algorithm>
using std::sort; using std::unique;

void elimDups(list<string> &words)
{
  // sort words alphabetically so we can find the duplicates
  words.sort();

  for (const auto &str : words) cout << str << " ";
  cout << endl;

  // remove the nonunique elements
  words.unique();
}

int main()
{
  list<string> slst = {"the", "quick", "red", "fox", "jumps", "over", "the",
		       "slow", "red", "turtle"};

  for (const auto &str : slst) cout << str << " ";
  cout << endl;

  elimDups(slst);
  
  for (const auto &str : slst) cout << str << " ";
  cout << endl;
  
  return 0;
}
