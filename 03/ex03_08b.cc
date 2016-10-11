#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

int main()
{
  string s("Hello World!!!");
  for (decltype(s.size()) index = 0; index != s.size(); ++index)
    s[index] = 'X';

  cout << s << endl;

  return 0;
}
