#include <iostream>
#include <string>

struct Sales_data;
std::istream& read(std::istream &is, Sales_data &item);

struct Sales_data {
  // friend declarations for nonmember Sales_data operations added
  friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
  friend std::istream& read(std::istream &is, Sales_data &item);
  friend std::ostream& print(std::ostream &os, const Sales_data &item);

public:
  // nondelegating constructor initializes members from corresponding arguments
    Sales_data(const std::string &s, unsigned cnt, double price):
      bookNo(s), units_sold(cnt), revenue(cnt * price) {
      std::cout << "inside of Sales_data::Sales_data(const std::string&, unsigned, double)"
		<< std::endl;
    }

  // remaining constructors all delegate to anthor constructor
  Sales_data(): Sales_data("", 0, 0) {
    std::cout << "inside of Sales_data::Sales_data()"
	      << std::endl;
  }
  Sales_data(const std::string &s): Sales_data(s, 0, 0) {
    std::cout << "inside of Sales_data::Sales_data(const std::string&)"
	      << std::endl;
  }
  Sales_data(std::istream &is): Sales_data() { 
    read(is, *this);
    std::cout << "inside of Sales_data::Sales_data(std::istream &is)"
	      << std::endl;    
  }

  // other members as before
  std::string isbn() const { return bookNo; }
  Sales_data& combine(const Sales_data&);
  double avg_price() const;

private:
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};


// definitions for nonmember parts of the Sales_data interface
Sales_data
add(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;		// copy data members from lhs into sum
  sum.combine(rhs);		// add data members from rhs into sum
  return sum;
}

// transactions contain ISBN, number of copies sold, and sales price
std::istream&
read(std::istream &is, Sales_data &item) {
  double price = 0.0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}

std::ostream&
print(std::ostream &os, const Sales_data &item) {
  os << item.isbn() << " " << item.units_sold << " "
     << item.revenue << " " << item.avg_price();
  return os;
}

// add the value of the given Sales_data into this object
Sales_data&
Sales_data::combine(const Sales_data &rhs) {
  units_sold += rhs.units_sold;	// add the members of rhs into
  revenue += rhs.revenue;	// the members of "this" object
  return *this;			// return the object on which the function was
  // called
}

double Sales_data::avg_price() const {
  if (units_sold)
    return revenue/units_sold;
  else
    return 0;
}

int main()
{
  std::cout << "1. default way: " << std::endl;
  std::cout << "----------------" << std::endl;
  Sales_data s1;   
  
  std::cout << "\n2. use std::string as parameter: " << std::endl;
  std::cout << "----------------" << std::endl;
  Sales_data s2("Cpp-Primer-5th");
  
  std::cout << "\n3. complete parameters: " << std::endl;
  std::cout << "----------------" << std::endl;
  Sales_data s3("Cpp-Primer-5th", 3, 25.8);
  
  std::cout << "\n4. use istream as parameter: " << std::endl;
  std::cout << "----------------" << std::endl;
  Sales_data s4(std::cin);
  
  return 0;
}
