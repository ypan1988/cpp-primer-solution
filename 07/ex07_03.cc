#include <iostream>

struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;

  // operations on Sales_data objects
  std::string isbn() const { return bookNo; }
  Sales_data& combine(const Sales_data&);
};

// add the value of the given Sales_data into this object
Sales_data&
Sales_data::combine(const Sales_data &rhs) {
  units_sold += rhs.units_sold;	// add the members of rhs into
  revenue += rhs.revenue;	// the members of "this" object
  return *this;			// return the object on which the function was called
}

int main()
{
  Sales_data total; // variable to hold data for the next transaction

  // read the first transaction and ensure that there are data to process
  if (std::cin >> total.bookNo >> total.units_sold >> total.revenue) {
    Sales_data trans;           // variable to hold the running sum
    // read and process the remaining transtraction
    while (std::cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
      // if we're still processing the same book
      if (total.isbn() == trans.isbn()) {
        // update the running total
        total.combine(trans);
      }
      else {
        // print results for the previous book
        std::cout << total.bookNo << " "
                  << total.units_sold << " "
                  << total.revenue << std::endl;
        total = trans;          // total now refers to the next book
      }
    }
    std::cout << total.bookNo << " "
              << total.units_sold << " "
              << total.revenue << std::endl;
  } else {
    // no input! warn the user
    std::cerr << "No data?!" << std::endl;
    return -1;                  // indicate failure
  }

  return 0;
}
