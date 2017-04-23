#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort; using std::stable_sort;
using std::unique; using std::partition;
using std::for_each;

#include <functional>
using namespace std::placeholders;
using std::bind;

void elimDups(vector<string> &words)
{
  // sort words alphabetically so we can find the duplicates
  sort(words.begin(), words.end());

  for (const auto &str : words) cout << str << " ";
  cout << endl;

  // unique reorders the input range so that each word appears once in the
  // front portion of the range and returns an iterator one past the unique range
  auto end_unique = unique(words.begin(), words.end());

  for (const auto &str : words) cout << str << " ";
  cout << endl;

  // erase uses a vector operation to remove the nonunique elements
  words.erase(end_unique, words.end());
}

bool check_size(const string &s, string::size_type sz) 
{
  return s.size() < sz;
}

// return the plural version of word if ctr is greater than 1
string make_plural(size_t ctr, const string &word, const string &ending)
{
  return (ctr > 1) ? word + ending : word;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
  elimDups(words);		// put words in alphabetical order and remove
				// duplicates
  
  auto wc = partition(words.begin(), words.end(), bind(check_size, _1, sz));

  for (const auto &str : words) cout << str << " ";
  cout << endl;
  
  // compute the number of elements with size >= sz
  auto count = words.end() - wc;
  cout << count << " " << make_plural(count, "word", "s")
       << " of length " << sz << " or longer" << endl;

  // print words of the given size or longer, each one followed by a space
  for_each(wc, words.end(),
	   [](const string &s){ cout << s << " "; });
  cout << endl;
}

int main()
{
  vector<string> svec = {"the", "quick", "red", "fox", "jumps", "over", "the",
			 "slow", "red", "turtle"};

  for (const auto &str : svec) cout << str << " ";
  cout << endl;

  biggies(svec, 4);

  for (const auto &str : svec) cout << str << " ";
  cout << endl;

  return 0;
}
