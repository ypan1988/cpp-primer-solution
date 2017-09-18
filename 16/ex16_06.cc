#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

template <typename T, unsigned N>
T* array_begin(T (&arr)[N])
{
  return arr;
}

template <typename T, unsigned N>
T* array_end(T (&arr)[N])
{
  return arr + N;
}

int main()
{
  string sa[] = {"aa", "bb", "cc", "dd"};
  cout << *(array_begin(sa) + 1) << endl;
  cout << *(array_end(sa) - 1) << endl;

  return 0;
}
