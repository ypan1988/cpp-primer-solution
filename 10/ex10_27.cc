#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <algorithm>
using std::sort; using std::unique_copy;

#include <iterator>
using std::back_inserter;

int main()
{
  vector<string> svec = {"the", "quick", "red", "fox", "jumps", "over", "the",
			 "slow", "red", "turtle"};

  for (const auto &str : svec) cout << str << " ";
  cout << endl;

  sort(svec.begin(), svec.end());

  for (const auto &str : svec) cout << str << " ";
  cout << endl;

  list<string> lst;
  unique_copy(svec.begin(), svec.end(), back_inserter(lst));

  for (const auto &str : lst) cout << str << " ";
  cout << endl;

  return 0;
}   
