#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <map>
using std::map;

#include <algorithm>
using std::find;

int main()
{
    vector<string> exclude = {"the", "but", "and", "or", "an", "a",
			      "The", "But", "And", "Or", "An", "A"};
    map<string, size_t> word_count; // empty map from string to size_t
    string word;
    while (cin >> word) {
      if (find(exclude.begin(), exclude.end(), word) == exclude.end()) {
	++word_count[word];
      } else {
	cout << "excluded: " << word << endl;
      }
    }
    for (const auto &w : word_count) // for each element in the map
      // print the results
      cout << w.first << " occurs " << w.second
	   << ((w.second > 1) ? " times" : " time") << endl;

    return 0;
}
