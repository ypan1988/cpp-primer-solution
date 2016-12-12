#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; }

int func(int a, int b);
vector<decltype(func)*> vec;

int main()
{  
  vec.push_back(add);
  vec.push_back(subtract);
  vec.push_back(multiply);
  vec.push_back(divide);

  for (auto f : vec)
    std::cout << f(10, 5) << std::endl;

  return 0;
}
