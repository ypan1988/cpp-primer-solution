#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <cstring>
using std::strcmp;

int main()
{
  const char ca1[] = "A string example";
  const char ca2[] = "A different string";

  // Note that if you null-terminate the array, you can pass the whole thing to
  // cout, and operator<< will know when to stop
  cout << "ca1: " << ca1 << endl;
  cout << "ca2: " << ca2 << endl;

  auto check = strcmp(ca1, ca2);
  if (check == 0) cout << "ca1 and ca2 are the same string";
  else if (check > 0) cout << "ca1 is greater than ca2";
  else cout << "ca1 is less than ca2";

  return 0;
}
