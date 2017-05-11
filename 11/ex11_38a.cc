#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <cstddef>
using std::size_t;

#include <string>
using std::string;

#include <unordered_map>
using std::unordered_map;

int main()
{
  // count the number of times each word occurs in the input
  unordered_map<string, size_t> word_count; // empty map from string to size_t
  string word;
  while (cin >> word)
    ++word_count[word];		// fetch and increment the counter for word
  for (const auto &w : word_count) // for each element in the map
    // print the results
    cout << w.first << " occurs " << w.second
	 << ((w.second > 1) ? " times" : " time") << endl;

  return 0;
}
