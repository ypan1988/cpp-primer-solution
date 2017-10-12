#include <iostream>
#include <string>

// function to end the recursion and print the last element. this function must
// be declared before the variadic version of print is defined
template <typename T>
std::ostream& print(std::ostream &os, const T &t)
{
  return os << t;  // no separator after the last element in the pack
}

// this version of print will be called for all but the last element in the pack
template <typename T, typename... Args>
std::ostream& print(std::ostream &os, const T &t, const Args& ... rest)
{
  os << t << ", ";
  return print(os, rest...);
}

int main()
{
  int i = 0;
  double d = 3.14;
  char c = 'c';
  std::string s = "Hello world";
  bool b = true;

  print(std::cout, s) << std::endl;
  print(std::cout, d, s) << std::endl;
  print(std::cout, i, d, c, s, b) << std::endl;

  return 0;
}
