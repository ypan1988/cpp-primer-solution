#include <iostream>
using std::cout; using std::endl;

#include <iterator>
using std::begin; using std::end;

int main()
{
  int ia[3][4] = {		// three elements; each element is an array of
				// size 4
    {0, 1, 2, 3},		// initializers for the row indexed by 0
    {4, 5, 6, 7},		// initializers for the row indexed by 1
    {8, 9, 10, 11}		// initializers for the row indexed by 2
  };

  using int_array = int[4];
  for (int_array *p1 = begin(ia); p1 != end(ia); ++p1)
    for (int *p2 = begin(*p1); p2 != end(*p1); ++p2)
      cout << *p2 << endl;
  
  return 0;
}
