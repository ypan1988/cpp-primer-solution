#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

int main()
{
  vector<char> cvec = {'H', 'e', 'l', 'l', 'o'};
  string s(cvec.cbegin(), cvec.cend());

  cout << s << endl;

  return 0;
}
