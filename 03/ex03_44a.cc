#include <iostream>
using std::cout; using std::endl;

int main()
{
  int ia[3][4] = {		// three elements; each element is an array of
				// size 4
    {0, 1, 2, 3},		// initializers for the row indexed by 0
    {4, 5, 6, 7},		// initializers for the row indexed by 1
    {8, 9, 10, 11}		// initializers for the row indexed by 2
  };

  using int_array = int[4];
  for (int_array &row : ia)
    for (int col : row)
      cout << col << endl;
  
  return 0;
}
