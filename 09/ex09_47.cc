#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

int main()
{
  string s("ab2c3d7R4E6");
  string numbers("0123456789");
  string letters("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

  string::size_type pos;

  pos = 0;
  while ((pos = s.find_first_of(numbers, pos)) != string::npos) {
    cout << "found number at index: " << pos
         << " element is " << s[pos] << endl;
    ++pos;
  }

  pos = 0;
  while ((pos = s.find_first_of(letters, pos)) != string::npos) {
    cout << "found letter at index: " << pos
         << " element is " << s[pos] << endl;
    ++pos;
  }

  cout << endl;

  pos = 0;
  while ((pos = s.find_first_not_of(letters, pos)) != string::npos) {
    cout << "found number at index: " << pos
         << " element is " << s[pos] << endl;
    ++pos;
  }

  pos = 0;
  while ((pos = s.find_first_not_of(numbers, pos)) != string::npos) {
    cout << "found letter at index: " << pos
         << " element is " << s[pos] << endl;
    ++pos;
  }

  return 0;
}
