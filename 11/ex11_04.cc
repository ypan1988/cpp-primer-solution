#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <cstddef>
using std::size_t;

#include <cctype>
using std::tolower; using std::ispunct;

#include <string>
using std::string;

#include <map>
using std::map;

#include <algorithm>
using std::for_each; using std::remove_if;

int main()
{
  // count the number of times each word occurs in the input
  map<string, size_t> word_count; // empty map from string to size_t
  string word;
  while (cin >> word) {
    for_each(word.begin(), word.end(), [](char &c) { tolower(c); });
    auto iter = remove_if(word.begin(), word.end(),
			  [](char c) 
			  { return ispunct(static_cast<unsigned char>(c)); });
    word.erase(iter, word.end());
    ++word_count[word];		// fetch and increment the counter for word
  }

  for (const auto &w : word_count) // for each element in the map
    // print the results
    cout << w.first << " occurs " << w.second
	 << ((w.second > 1) ? " times" : " time") << endl;

  return 0;
}
