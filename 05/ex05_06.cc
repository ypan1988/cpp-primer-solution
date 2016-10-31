#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

int main()
{
  // read a set of scores from the input
  vector<unsigned> grades;
  unsigned grade;
  while (cin >> grade)
    grades.push_back(grade);

  const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
  
  // now process those grades
  for (auto it : grades) {	// for each grade we read
    cout << it << " ";		// print the grade
    string lettergrade;		// hold corresponding letter grade

    lettergrade = it < 60 ? scores[0] : scores[(it - 50)/10];
    lettergrade += (it < 60 || it == 100) ? "" :
      (it % 10 > 7) ? "+" :
      (it % 10 < 3) ? "-" : "";
    
    cout << lettergrade << endl;
  }
    
  return 0;
}
