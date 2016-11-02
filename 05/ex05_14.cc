#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

int main()
{
  vector<string> svec;
  string word, word2;
  while (cin >> word) {
    svec.push_back(word);
  }
 
  unsigned n_occur = 0, max_occur = 1;
  auto it = svec.begin();
  while (it != svec.end()) {
    if (word2 != *it) { 
      if (n_occur > max_occur) {
	word = word2;
	max_occur = n_occur;
      }
      word2 = *it;
      n_occur = 1; 
    } else {
      ++n_occur;
    }
    ++it;
  }

  if (max_occur == 1) cout << "no word was repeated." << endl;
  else cout << word << " occurs " << max_occur << " times." << endl;
  
  return 0;
}
