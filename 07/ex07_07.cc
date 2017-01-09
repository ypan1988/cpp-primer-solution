#include <iostream>

struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;

  // operations on Sales_data objects
  std::string isbn() const { return bookNo; }
  Sales_data& combine(const Sales_data&);
  double avg_price() const;
};

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

int main()
{
  Sales_data total; // variable to hold data for the next transaction

  // read the first transaction and ensure that there are data to process
  if (read(std::cin, total)) {
    Sales_data trans;           // variable to hold the running sum
    // read and process the remaining transtraction
    while (read(std::cin, trans)) {
      // if we're still processing the same book
      if (total.isbn() == trans.isbn()) {
	// update the running total
	total.combine(trans);	
      }
      else {
        // print results for the previous book
	print(std::cout, total);
        std::cout << std::endl;
        total = trans;          // total now refers to the next book
      }
    }
    print(std::cout, total);
    std::cout << std::endl;
  } else {
    // no input! warn the user
    std::cerr << "No data?!" << std::endl;
    return -1;                  // indicate failure
  }

  return 0;
}
