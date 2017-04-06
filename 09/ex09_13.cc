#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

#include <list>
using std::list;

int main()
{
  list<int> ilst = {1, 2, 3, 4, 5};
  vector<int> ivec = {6, 7, 8, 9, 10};

  vector<double> dvec1(ilst.begin(), ilst.end());
  vector<double> dvec2(ivec.begin(), ivec.end());

  cout << "dvec1 =" << endl;
  for (const auto &dval : dvec1)
    cout << dval << endl;

  cout << "dvec2 =" << endl;
  for (const auto &dval : dvec2)
    cout << dval << endl;

  return 0;
}
