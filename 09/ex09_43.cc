#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

void Replace(string &s, const string &oldVal, const string &newVal)
{
  string::size_type index = 0;
  while (s.size() - index >= oldVal.size()) {
    if (s.substr(index, oldVal.size()) == oldVal) {
      s.erase(index, oldVal.size());
      s.insert(index, newVal);
      index += newVal.size();
    } else ++index;
  }
}

int main()
{
  string str{"hello thru world tho !!!"};
  Replace(str, "thru", "through");
  Replace(str, "tho", "though");

  std::cout << str << std::endl;

  return 0;
}
