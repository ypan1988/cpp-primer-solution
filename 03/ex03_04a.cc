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
  
  if (s1 == s2)
    cout << "s1 is equal to s2" << endl;
  else
    if (s1 > s2) cout << "s1 is greater than s2" << endl;
    else cout << "s1 is smaller than s2" << endl;

  return 0;
}
