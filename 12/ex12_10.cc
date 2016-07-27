#include <iostream>
#include <memory>

void process(std::shared_ptr<int> ptr)
{
  std::cout << "inside the process function:"
            << ptr.use_count() << std::endl;
}

int main()
{
  std::shared_ptr<int> p(new int(42));
  std::cout << p.use_count() << "\n";
  process(std::shared_ptr<int>(p));

  /**
   * codes below shows how the reference count change.
   */
  std::cout << p.use_count() << "\n";
  auto q = p;
  std::cout << p.use_count() << "\n";
  std::cout << "the int p now points to is:" << *p << "\n";
  return 0;
}
