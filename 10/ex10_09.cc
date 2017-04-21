#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort; using std::unique;

void elimDups(vector<string> &words)
{
  // sort words alphabetically so we can find the duplicates
  sort(words.begin(), words.end());

  for (const auto &str : words) cout << str << " ";
  cout << endl;

  // unique reorders the input range so that each word appears once in the
  // front portion of the range and returns an iterator one past the unique range
  auto end_unique = unique(words.begin(), words.end());

  for (const auto &str : words) cout << str << " ";
  cout << endl;

  // erase uses a vector operation to remove the nonunique elements
  words.erase(end_unique, words.end());
}

int main()
{
  vector<string> svec = {"the", "quick", "red", "fox", "jumps", "over", "the",
			 "slow", "red", "turtle"};

  for (const auto &str : svec) cout << str << " ";
  cout << endl;

  elimDups(svec);
  
  for (const auto &str : svec) cout << str << " ";
  cout << endl;
  
  return 0;
}
