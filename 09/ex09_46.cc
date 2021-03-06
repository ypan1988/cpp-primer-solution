#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

string GetName(const string &name, const string &prefix, const string &suffix)
{
  string new_name(name);
  new_name.insert(0, prefix);
  new_name.insert(new_name.size(), suffix);

  return new_name;
}

int main()
{
  string name(" Bjarne Stroustrup ");

  cout << GetName(name, "Mr.", "III") << endl;

  return 0;
}
