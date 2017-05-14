#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
  int size;
  cout << "Input your string length: ";
  cin >> size;

  char *str = new char[size+1]();
  cout << "Input your string: ";
  cin >> str;

  cout << str << endl;
  delete [] str;

  return 0;
}
