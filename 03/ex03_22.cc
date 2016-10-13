#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <string>
using std::string;

#include <cctype>
using std::islower; using std::toupper;

#include <vector>
using std::vector;


int main()
{
  string word;
  vector<string> text;
  while (cin >> word)
    text.push_back(word);

  for (auto it1 = text.begin();
       it1 != text.end() && !it1->empty(); ++it1) 
    for (auto it2 = it1->begin(); it2 != it1->end(); ++it2) 
      if (islower(*it2))
	*it2 = toupper(*it2);

  for (auto it = text.begin();
       it != text.end() && !it->empty(); ++it) 
    cout << *it << " ";
  cout << endl;
  
  return 0;
}
