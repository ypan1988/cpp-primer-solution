#include <iostream>
#include <string>

class HasPtr {
  friend void swap(HasPtr&, HasPtr&);
 public:
  HasPtr(const std::string &s = std::string()):
    ps(new std::string(s)), i(0) { }
  // each HasPtr has its own copy of the string to which ps points
  HasPtr(const HasPtr &p):
    ps(new std::string(*p.ps)), i(p.i) { }
  HasPtr& operator=(const HasPtr &rhs) {
    auto newp = new std::string(*rhs.ps);  // copy the underlying string
    delete ps;    // free the old memory
    ps = newp;    // copy data from rhs into this object
    i = rhs.i;
    return *this; // return this object
  }
  ~HasPtr() { delete ps; }
  void print() const { std::cout << *ps << std::endl; }
 private:
  std::string *ps;
  int i;
};

inline 
void swap(HasPtr &lhs, HasPtr &rhs)
{
  std::cout << "inside swap(HasPtr &lhs, HasPtr &rhs)" << std::endl;
  using std::swap;
  swap(lhs.ps, rhs.ps);		// swap the pointers, not the string data
  swap(lhs.i, rhs.i);		// swap the int member
}

int main()
{
  HasPtr hp1("hello"), hp2("world");

  std::cout << "hp1: " << std::endl;
  hp1.print();
  std::cout << "hp2: " << std::endl;
  hp2.print();

  swap(hp1, hp2);

  std::cout << "hp1: " << std::endl;
  hp1.print();
  std::cout << "hp2: " << std::endl;
  hp2.print();

  return 0;
}
