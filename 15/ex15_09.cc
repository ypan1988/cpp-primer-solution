#include<iostream>
#include "Quote1.h"

int main()
{
    Bulk_quote derived("0-201-82470-1", 50, 5, 0.19);

    Quote &quote_ref = derived;
    quote_ref.net_price(10);

    Quote *quote_ptr = &derived;
    quote_ptr->net_price(10);

    return 0;
}
