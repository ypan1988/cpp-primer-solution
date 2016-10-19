#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

int main()
{
  string s1("A string example");
  string s2("A different string");

  cout << "s1: " << s1 << endl;
  cout << "s2: " << s2 << endl;

  if (s1 == s2) cout << "s1 and s2 are the same string";
  else if (s1 > s2) cout << "s1 is greater than s2";
  else cout << "s1 is less than s2";

  return 0;
}
