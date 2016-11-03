#include <iostream>
using std::cout; using std::endl;

#include <cstddef>
using std::size_t;

size_t count()
{
  static size_t ctr = 0;	// value will persist across calls
  return ctr++;
}

int main()
{
  for (size_t i = 0; i != 10; ++i)
    cout << count() << endl;
  
  return 0;
}
