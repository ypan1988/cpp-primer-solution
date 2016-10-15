#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <vector>
using std::vector;

int main()
{
  int i;
  vector<int> ivec;
  while (cin >> i)
    ivec.push_back(i);

  for (auto it = ivec.cbegin(); it != ivec.cend() - 1; ++it)
    cout << *it + *(it+1) << " ";
  cout << endl;

  for (auto lit = ivec.cbegin(), rit = ivec.cend() - 1;
       lit < rit; ++lit, --rit)
    cout << *lit + *rit << " ";
  cout << endl;

  return 0;
}
