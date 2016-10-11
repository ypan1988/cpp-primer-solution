#include <string>
using std::string;

#include <cctype>
using std::ispunct;

#include <iostream>
using std::cin; using std::cout; using std::endl;


int main()
{
  string s;
  cin >> s;

  for (auto &c : s)
    if (!ispunct(c))
      cout << c;

  cout << endl;
  
  return 0;
}
