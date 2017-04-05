#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <fstream>
using std::ifstream;

#include <sstream>
using std::istringstream;

int main()
{
  string ifile("./data/sstream");
  ifstream in(ifile);

  string line;
  vector<string> svec;
  while (getline(in, line)) {
    svec.push_back(line);
  }

  for (const auto &s : svec) {
    istringstream str(s);
    string word;
    while (str >> word) {
      cout << word << endl;
    }
  }

  return 0;
}
