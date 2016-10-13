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

  for (decltype(ivec.size()) index = 0; index != ivec.size() - 1; ++index)
    cout << ivec[index] + ivec[index + 1] << " ";
  cout << endl;

  for (decltype(ivec.size()) index = 0; index != ivec.size()/2; ++index)
    cout << ivec[index] + ivec[ivec.size() - 1 - index] << " ";
  cout << endl;

  return 0;
}
