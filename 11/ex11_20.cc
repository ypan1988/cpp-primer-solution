#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <cstddef>
using std::size_t;

#include <string>
using std::string;

#include <map>
using std::map;

int main()
{
  // count the number of times each word occurs in the input
  map<string, size_t> word_count; // empty map from string to size_t
  string word;
  while (cin >> word) {
    auto ret = word_count.insert({word, 1});
    if (!ret.second) ++ret.first->second;
  }
  for (const auto &w : word_count) // for each element in the map
    // print the results
    cout << w.first << " occurs " << w.second
         << ((w.second > 1) ? " times" : " time") << endl;

  return 0;
}
