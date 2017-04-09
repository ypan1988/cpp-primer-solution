#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <forward_list>
using std::forward_list;

void find_and_insert(forward_list<string> &list,
		     const string &to_find, 
		     const string &to_add) 
{
  auto prev = list.before_begin();
  auto curr = list.begin();
  while (curr != list.end()) {
    if (*curr == to_find) {
      curr = list.insert_after(curr, to_add);
      return;
    } else {
      prev = curr;
      ++curr;
    }
  }

  list.insert_after(prev, to_add);
}

int main()
{
  forward_list<string> slst = {"hello0", "hello1", "hello2"};
  string s1 = "hello", s2 = "world";

  find_and_insert(slst, s1, s2);

  cout << "forward_list: ";
  for (const auto &str : slst)
    cout << str << " ";
  cout << endl;

  return 0;
}
