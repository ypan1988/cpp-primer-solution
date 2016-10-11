#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

int main()
{
  string s("Hello World!!!");

  decltype(s.size()) index = 0;
  while (index != s.size())
    s[index++] = 'X';

  cout << s << endl;

  return 0;
}
