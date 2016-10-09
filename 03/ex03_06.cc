#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

int main()
{
  string s("Hello World!!!");
  for (auto &c : s) c = 'X';
  cout << s << endl;

  return 0;
}
