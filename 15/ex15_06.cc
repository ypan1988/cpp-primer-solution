#include <iostream>
using std::cout;

#include "Quote.h"

int main()
{
  Quote base("0-201-82470-1", 50);
  print_total(cout, base, 10);  // calls Quotes::net_price

  Bulk_quote derived("0-201-82470-1", 50, 5, 0.19);
  print_total(cout, derived, 10);  // calls Bulk_quotes::net_price

  return 0;
}
