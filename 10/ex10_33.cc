#include <string>
using std::string;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <algorithm>
using std::for_each;

#include <iterator>
using std::istream_iterator;
using std::ostream_iterator;

int main()
{
  string ifile = "./data/integers";
  ifstream in(ifile);
  
  istream_iterator<int> in_iter(in), eof;

  string ofile1 = "output1";
  string ofile2 = "output2";
  ofstream out1(ofile1), out2(ofile2);

  ostream_iterator<int> out_iter1(out1, " ");
  ostream_iterator<int> out_iter2(out2, "\n");

  for_each(in_iter, eof, 
	   [&out_iter1, &out_iter2](const int i)
	   { *(i % 2 ? out_iter1 : out_iter2)++ = i; });

  return 0;
}
