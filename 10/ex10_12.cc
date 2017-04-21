#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Sales_data;
std::istream& read(std::istream &is, Sales_data &item);

struct Sales_data {
  // friend declarations for nonmember Sales_data operations added
  friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
  friend std::istream& read(std::istream &is, Sales_data &item);
  friend std::ostream& print(std::ostream &os, const Sales_data &item);

  // other members and access specifiers as before
public:
  Sales_data() = default;
  Sales_data(const std::string &s): bookNo(s) { }
  Sales_data(const std::string &s, unsigned n, double p):
    bookNo(s), units_sold(n), revenue(p*n) { }
  Sales_data(std::istream &is) { read(is, *this); }

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

bool compareIsbn(const Sales_data &obj1, const Sales_data &obj2) {
  return obj1.isbn() < obj2.isbn();
}

int main()
{
  Sales_data trans1("bbb");
  Sales_data trans2("aaa");
  Sales_data trans3("ccc");
  Sales_data trans4("bb");
  
  std::vector<Sales_data> vec = {trans1, trans2, trans3, trans4};
  std::sort(vec.begin(), vec.end(), compareIsbn);

  for (const auto &trans : vec) {
    std::cout << trans.isbn() << std::endl;
  }

  return 0;
}
