#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;
using std::ifstream;

void read(std::istream &is, vector<string> &svec) 
{
  string buf;
  while (is >> buf)
    svec.push_back(buf);
}

int main()
{
  string ifile = "./data/book.txt";
  ifstream in(ifile);
  vector<string> svec;
  read(in, svec);
  
  for (const auto &str : svec)
    cout << str << endl;

  return 0;
}
