#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

class Date {
private:
  unsigned year_ = 2000;
  unsigned month_ = 1;
  unsigned day_ = 1;

public:
  Date(const string &s) {
    const string num("0123456789");
    const string sep("/");

    // January 1, 2000 or Jan 1, 2000
    if (s.find_first_of(',') != string::npos) {
      string mm = s.substr(0, s.find_first_of(' '));
      if (mm == "Jan" || mm == "January") month_ = 1;
      else if (mm == "Feb" || mm == "February") month_ = 2;
      else if (mm == "Mar" || mm == "March") month_ = 3;
      else if (mm == "Apr" || mm == "April") month_ = 4;
      else if (mm == "May") month_ = 5;
      else if (mm == "Jun" || mm == "June") month_ = 6;
      else if (mm == "Jul" || mm == "July") month_ = 7;
      else if (mm == "Aug" || mm == "August") month_ = 8;
    }
    
    // 1/1/2000
    if (s.find_first_of('/') != string::npos) {
    }
  }

  void print() {
    cout << "year: " << year_
	 << " month: " << month_
	 << " day: " << day_ << endl;
  }

};

int main()
{
  Date date1("August 1, 1900");
  date1.print();
  
  Date date2("1/1/1900");
  date2.print();

  Date date3("Aug 1, 1900");
  date3.print();

  return 0;
}
