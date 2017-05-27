#include <iostream>
#include <vector>

struct X {
  X() { std::cout << "X()" << std::endl; }
  X(const X&) { std::cout << "X(const X&)" << std::endl; }
  X& operator=(const X&) { 
    std::cout << "X& operator=(const X&)" << std::endl;
    return *this;
  }
  ~X() { std::cout << "~X()" << std::endl; }
};
 
void f(X x, const X &rx) {
  std::cout << "inside f()" << std::endl;
  std::vector<X> vec;
  vec.push_back(x);
  vec.push_back(rx);
}

int main()
{
  X *px = new X;
  std::cout << "before f()" << std::endl;
  f(*px, *px);
  std::cout << "after f()" << std::endl;
  delete px;

  return 0;
}
