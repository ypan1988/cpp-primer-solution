#include <string>
using std::string;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
  string word, s;
  while (cin >> word)
    s += " " + word;
  
  cout << "s: " << s  << endl;
  
  return 0;
}
