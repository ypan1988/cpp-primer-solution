#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

template <typename T, unsigned N>
constexpr unsigned get_array_size(const T (&arr)[N])
{
  return N;
}

int main()
{
  char ca[] = "abcd";
  cout << get_array_size(ca) << endl; // 5

  string sa[] = {"aa", "bb", "cc", "dd"};
  cout << get_array_size(sa) << endl; // 4

  return 0;
}
