#include <iostream>
using std::cin;

#include <string>
using std::string;

#include <vector>
using std::vector;

int main()
{
  string s;
  vector<string> v2;

  while (cin >> s)
    v2.push_back(s);

  return 0;
}
