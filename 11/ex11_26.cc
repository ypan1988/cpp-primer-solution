#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <map>
using std::map;

#include <typeinfo>

int main()
{
  map<string, size_t> word_count = {{"hello", 5}, {"world", 10}};

  cout << "type that can be used to subscript the map: "
       << typeid(map<string, size_t>::key_type).name()
       << endl;

  cout << "type that would be returned from the subscript operator: "
       << typeid(decltype(word_count["hello"])).name()
       << endl;

  return 0;
}
