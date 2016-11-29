#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <cstddef>
using std::size_t;

int main(int argc, char *argv[]) {
  std::string s;
  for (size_t i = 1; i != argc; ++i) {
    s += string(argv[i]) + " ";
  }
  cout << s << endl;

  return 0;
}
