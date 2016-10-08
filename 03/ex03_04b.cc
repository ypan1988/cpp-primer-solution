#include <string>
using std::string;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
  string s1, s2;
  cin >> s1 >> s2;
  cout << "s1: " << s1 << endl
       << "s2: " << s2 << endl;
  
  if (s1.size() == s2.size())
    cout << "s1 and s2 have the same length" << endl;
  else
    if (s1.size() > s2.size()) cout << "s1 is longer than s2" << endl;
    else cout << "s2 is longer than s1" << endl;

  return 0;
}
