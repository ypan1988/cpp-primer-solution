#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <string>
using std::string;

#include <cctype>
using std::toupper;

#include <vector>
using std::vector;

int main()
{
  string word;
  vector<string> text;
  while (cin >> word) {
    text.push_back(word);
  }

  for (auto &s : text)
    for (auto &c : s)
      c = toupper(c);

  for (decltype(text.size()) index = 0, cnt = 0; index != text.size(); ++index) {
    cout << text[index] << " ";
    if (++cnt % 8 == 0) cout << endl;
  }

  cout << endl;
  
  return 0;
}
