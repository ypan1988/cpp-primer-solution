#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <algorithm>
using std::copy;

#include <iterator>
using std::inserter; 
using std::back_inserter; 
using std::front_inserter;

int main()
{
  vector<int> ivec = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
  
  cout << "vector:" << endl;
  for (const auto &ival : ivec) cout << ival << " ";
  cout << endl;

  list<int> ilst1, ilst2, ilst3;

  cout << "inserter:" << endl;
  copy(ivec.begin(), ivec.end(), inserter(ilst1, ilst1.begin()));
  for (const auto &ival : ilst1) cout << ival << " ";
  cout << endl;

  cout << "back_inserter:" << endl;
  copy(ivec.begin(), ivec.end(), back_inserter(ilst2));
  for (const auto &ival : ilst2) cout << ival << " ";
  cout << endl;

  cout << "front_inserter:" << endl;
  copy(ivec.begin(), ivec.end(), front_inserter(ilst3));
  for (const auto &ival : ilst3) cout << ival << " ";
  cout << endl;

  return 0;
}
