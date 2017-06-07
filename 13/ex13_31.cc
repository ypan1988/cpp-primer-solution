#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class HasPtr {
  friend void swap(HasPtr&, HasPtr&);
  friend bool operator<(const HasPtr &lhs, const HasPtr &rhs);
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

inline
bool operator<(const HasPtr &lhs, const HasPtr &rhs)
{
  return *lhs.ps < *rhs.ps;
}

int main()
{
  std::vector<HasPtr> hpvec;
  hpvec.emplace_back("hello");
  hpvec.emplace_back("world");
  hpvec.emplace_back("ccc");
  hpvec.emplace_back("aaa");
  hpvec.emplace_back("bbb");

  std::sort(hpvec.begin(), hpvec.end());

  for (const auto &hp : hpvec) {
    hp.print();
  }

  return 0;
}
