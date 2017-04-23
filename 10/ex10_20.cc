#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::count_if;

int main()
{
  vector<string> svec = {"hello", "world", "university", "of", "manchester"};

  auto cnt = count_if(svec.begin(), svec.end(),
		      [](const string &s)
		      { return s.size() > 6; });
  
  cout << cnt << " words are greater than length 6" << endl;

  return 0;
}
