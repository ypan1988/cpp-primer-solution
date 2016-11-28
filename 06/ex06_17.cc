#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <cctype>
using std::isupper;
using std::tolower;

bool has_capital_letters(const string &s) {
  bool check = false;
  for (auto c : s) {
    if (isupper(c))
      check = true;
  }

  return check;
}

void to_lower(string &s) {
  for (auto &c : s) {
    if (isupper(c))
      c = tolower(c);
  }
}

int main()
{
  cout << has_capital_letters("Hello World") << endl;
  cout << has_capital_letters("hello world") << endl;

  string s("HELLO WORLD");
  to_lower(s);
  cout << s << endl;
  
  return 0;
}
