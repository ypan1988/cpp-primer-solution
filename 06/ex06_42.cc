#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

// return the plural version of word if ctr is greater than 1
string make_plural(size_t ctr, const string &word,
		   const string &ending = "s")
{
  return (ctr > 1) ? word + ending : word;
}

int main()
{
  string s1("success");
  string s2("failure");
  
  cout << make_plural(1, s1, "es") << endl
       << make_plural(2, s1, "es") << endl;
  cout << make_plural(1, s2, "s") << endl
       << make_plural(2, s2, "s") << endl;

  return 0;
}
 
