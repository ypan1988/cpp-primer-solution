#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;

class Foo {
public:
  Foo sorted() &&;
  Foo sorted() const &;

private:
  vector<int> data;
};

// this object is an rvalue, so we can sort in place
Foo Foo::sorted() &&
{
  cout << "Foo sorted() &&;" << endl;
  sort(data.begin(), data.end());
  return *this;
}

// ex13_56
// Foo Foo::sorted() const & {
//   Foo ret(*this);
//   return ret.sorted();
// }

// ex13_57
Foo Foo::sorted() const & {
  cout << "Foo sorted() const &;" << endl;
  return Foo(*this).sorted();
}

int main()
{
  Foo().sorted();

  Foo f;
  f.sorted();

  return 0;  
}
