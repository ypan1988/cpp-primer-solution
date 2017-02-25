#include <iostream>
#include <string>

struct Sales_data;
std::istream& read(std::istream &is, Sales_data &item);

struct Sales_data {
  // constructors added
  Sales_data() = default;
  Sales_data(const std::string &s): bookNo(s) { }
  Sales_data(const std::string &s, unsigned n, double p):
    bookNo(s), units_sold(n), revenue(p*n) { }
  Sales_data(std::istream &is) { read(is, *this); }

  // other members as before
  std::string isbn() const { return bookNo; }
  Sales_data& combine(const Sales_data&);
  double avg_price() const;

  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

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
  Sales_data item1;
  print(std::cout, item1) << std::endl;
  Sales_data item2("0-201-78345-X");
  print(std::cout, item2) << std::endl;
  Sales_data item3("0-201-78345-X", 3, 20.00);
  print(std::cout, item3) << std::endl;
  Sales_data item4(std::cin);
  print(std::cout, item4) << std::endl;
  return 0;
}
