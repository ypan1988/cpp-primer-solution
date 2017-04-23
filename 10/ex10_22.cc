#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::count_if;

#include <functional>
using namespace std::placeholders;
using std::bind;

bool isShorter(const string& s, string::size_type sz) {
  return s.size() <= sz;
}

int main()
{
  vector<string> svec = {"hello", "world", "university", "of", "manchester"};

  auto cnt = count_if(svec.begin(), svec.end(), bind(isShorter, _1, 6));
  
  cout << cnt << " words are not greater than length 6" << endl;

  return 0;
}   
