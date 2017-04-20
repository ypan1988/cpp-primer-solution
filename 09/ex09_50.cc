#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

int main()
{
  vector<string> svec = {"1", "2.1", "3", "4.2", "5"};

  int sum1 = 0;
  for (const auto &s : svec) {
    sum1 += stoi(s);
  }
  cout << "sum = " << sum1 << endl;
  
  double sum2 = 0.0;
  for (const auto &s : svec) {
    sum2 += stod(s);
  }
  cout << "sum = " << sum2 << endl;

  return 0;
}
