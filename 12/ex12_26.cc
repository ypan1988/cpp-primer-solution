#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <string>
using std::string;

#include <memory>
using std::allocator;

int main()
{
  size_t n = 10;

  allocator<string> alloc;
  auto const p = alloc.allocate(n);
  string s;
  auto q = p;
  while (cin >> s && q != p + n) {
    alloc.construct(q++, s);
  }
  
  while (q != p) {
    cout << *(q - 1) << " will be destroyed." << endl;
    alloc.destroy(--q);
  }

  alloc.deallocate(p, n);
  
  return 0;
}
