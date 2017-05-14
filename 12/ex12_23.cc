#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <cstring>

int main()
{
  string s1 = "hello ";
  string s2 = "world!";
  char *c = new char[s1.size() + s2.size() + 1];
  strcat(c, s1.c_str());
  strcat(c, s2.c_str());
  cout << c << endl;
  cout << s1 + s2 << endl;

  return 0;
}
