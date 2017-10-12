#include <iostream>
#include <sstream>
#include <string>

// print any type we don't otherwise handle
template <typename T>
std::string debug_rep(const T &t)
{
  std::ostringstream ret;
  ret << t;
  return ret.str();
}

// print pointers as their pointer value, followed by the object to which the
// pointer points
//
// NB: this function will not work properly with char*
template <typename T>
std::string debug_rep(T *p)
{
  std::ostringstream ret;
  ret << "pointer: " << p;  // print the pointer's own value
  if (p) ret << " " << debug_rep(*p);  // print the value to which p points
  else ret << " null pointer";  // or indicate that the p is null
  return ret.str();  // return a copy of the string to which ret is bound
}

// print strings inside double quotes
std::string debug_rep(const std::string &s)
{
  return '"' + s + '"';
}

// convert the character pointers to string and call the string version of
// debug_rep
std::string debug_rep(char *p)
{
  return debug_rep(std::string(p));
}

std::string debug_rep(const char *p)
{
  return debug_rep(std::string(p));
}


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

// call debug_rep on each argument in the call to print
template <typename... Args>
std::ostream& errorMsg(std::ostream &os, const Args& ... rest)
{
  // print(os, debug_rep(a1), debug_rep(a2),...,debug_rep(an))
  return print(os, debug_rep(rest)...);
}


int main()
{
  int i = 0;
  double d = 3.14;
  char c[] = "hello";
  std::string s = "Hello world";
  bool b = true;

  errorMsg(std::cout, i, d, c, s, b);

  return 0;
}
