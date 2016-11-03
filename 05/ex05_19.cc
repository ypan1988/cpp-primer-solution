#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <string>
using std::string;

int main()
{
  string rsp;
  do {
    cout << "please enter two strings: ";
    string s1, s2;
    cin >> s1 >> s2;

    if (s1 <= s2) cout << s1 << " is less than " << s2 << endl;
    else cout << s2 << " is less than " << s1 << endl;

    cout << "More? Enter yes or no: ";
    cin >> rsp;
  } while (!rsp.empty() && rsp[0] != 'n');

  return 0;
}
