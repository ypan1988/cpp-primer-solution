#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

class Date {
private:
  unsigned year_, month_, day_;

public:
  Date(const string &s) {

  }

  void print() {
    cout << "year: " << year_
	 << " month: " << month_
	 << " day: " << day_ << endl;
  }

};

int main()
{
  Data data1("January 1, 1900");
  data1.print();
  
  Data data2("1/1/1900");
  data2.print();

  Data data3("Jan 1, 1900");
  data3.print();

  return 0;
}
