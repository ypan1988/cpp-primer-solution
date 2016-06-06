#include "Quote1.h"

#include <iostream>
using std::cout;
using std::ostream;
using std::endl;

// calculate and print the price for the give number if copies, applying any
// discount
double print_total(ostream &os, const Quote &item, size_t n)
{
  // depending on the type of the object bound to the item parameter
  // calls either Quote::net_price or Bulk_quote::net_price
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() // calls Quote::isbn
     << " # sold@ "<< n << " total due: " << ret << endl;
  return ret;
}

void Quote::debug() const
{
  cout << "Data members of the class: " << endl
       << "bookNo = " << this->bookNo << endl
       << "price = " << this->price << endl;
}

// if the specified number of items are purchased, use the discounted price
double Bulk_quote::net_price(size_t cnt) const
{
  if (cnt >= min_qty)
    return cnt * (1 - discount) * price;
  else
    return cnt * price;
}

void Bulk_quote::debug() const
{
  Quote::debug();
  cout << "min_qty = " << this->min_qty << endl
       << "discount = " << this->discount << endl;
}

// use discounted price for up to a specified number of items
// additional items priced at normal, undiscounted price
double Lim_quote::net_price(size_t cnt) const
{
  if (cnt <= max_qty)
    return cnt * (1 - discount) * price;
  else
    return cnt * price - max_qty * discount * price;
}

void Lim_quote::debug() const
{
  Quote::debug();
  cout << "max_qty = " << this->max_qty << endl
       << "discount = " << this->discount << endl;
}
