#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <string>
using std::string;

int main()
{
  string word, word2;
  bool no_repeated_word = true; 
  while (cin >> word) {
    if (word == word2) {
      no_repeated_word = false;
      cout << word << endl;
      break;
    } else {
      word2 = word; 
    }
  }

  if (no_repeated_word) cout << "no word was repeated." << endl;
  
  return 0;
}
