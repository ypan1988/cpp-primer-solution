#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

int main()
{
  string s("Hello World!!!");
  for (char c : s) c = 'X';
  cout << s << endl;

  return 0;
}
