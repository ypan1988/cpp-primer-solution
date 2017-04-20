#include <iostream>
using std::cout; using std::endl;

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

int main()
{
  string ifile = "./data/words.txt";
  ifstream in(ifile);

  const string letters = "aceimnorsuvwxz";
  string word, result;
  while (in >> word) {
    if (word.find_first_not_of(letters) == string::npos &&
        result.size() < word.size())
      result = word;
  }

  cout << result << endl;

  return 0;
}
