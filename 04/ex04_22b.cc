#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

int main()
{
  vector<unsigned> grades;
  unsigned i;

  while (cin >> i)
    grades.push_back(i);

  for (auto grade : grades) {	// for each grade in grades
    string finalgrade;

    if (grade > 90) finalgrade = "high pass";
    else if (grade > 75) finalgrade = "pass";
    else if (grade >= 60) finalgrade = "low pass";
    else finalgrade = "fail";

    cout << grade << " " + finalgrade << endl; 
  }
  
  return 0;
}
