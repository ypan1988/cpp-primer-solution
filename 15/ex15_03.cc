#include <iostream>
using std::cout;

#include "Quote.h"

int main()
{
  Quote base("0-201-82470-1", 50);
  print_total(cout, base, 10);  // calls Quotes::net_price

  return 0;
}
