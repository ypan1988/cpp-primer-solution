#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <string>
using std::string;

#include <deque>
using std::deque;

int main()
{
  string word;
  deque<string> sdeq;

  while (cin >> word)
    sdeq.push_back(word);

  for (const auto &str : sdeq) {
    cout << str << endl;
  }

  return 0;
}
