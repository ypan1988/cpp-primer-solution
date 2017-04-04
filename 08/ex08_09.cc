#include <iostream>
#include <sstream>

std::istream& func(std::istream &is)
{
  std::string buf;
  while (is >> buf) std::cout << buf << std::endl;
  is.clear();
  return is;
}

int main()
{
  std::istringstream in("hello world");
  std::istream &is = func(in);
  std::cout << is.rdstate() << std::endl;

  return 0;
}
