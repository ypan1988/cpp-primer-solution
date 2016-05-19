#include <iostream>

int main()
{
  std::cout << "Enter two numbers(v1 < v2):" << std::endl;
  int v1 = 0, v2 = 0;
  std::cin >> v1 >> v2;

  for (int val = v1; val <= v2; ++val)
    std::cout << val << std::endl;
  
  return 0;
}
