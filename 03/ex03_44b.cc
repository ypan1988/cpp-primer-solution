#include <iostream>
using std::cout; using std::endl;

#include <cstddef>
using std::size_t;

int main()
{
  int ia[3][4] = {		// three elements; each element is an array of
				// size 4
    {0, 1, 2, 3},		// initializers for the row indexed by 0
    {4, 5, 6, 7},		// initializers for the row indexed by 1
    {8, 9, 10, 11}		// initializers for the row indexed by 2
  };

  for (size_t i = 0; i != 3; ++i)
    for (size_t j = 0; j != 4; ++j)
      cout << ia[i][j] << endl;
  
  return 0;
}
