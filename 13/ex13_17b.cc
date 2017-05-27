#include <iostream>
using std::cout; using std::endl;

struct numbered {
  numbered() { mysn = unique_serial_number++; }
  numbered(const numbered& s) { mysn = unique_serial_number++; }
  int mysn;
  static int unique_serial_number;
};

int numbered::unique_serial_number = 10;

void f(numbered s) { cout << s.mysn << endl; }

int main ()
{
  numbered a, b = a, c = b;
  f(a); f(b); f(c);

  return 0;
}
