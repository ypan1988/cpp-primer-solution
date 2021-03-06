#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

// forward declaration needed for friend declaration in StrBlob
class StrBlobPtr;

class StrBlob {
  friend class StrBlobPtr;
public:
  typedef std::vector<std::string>::size_type size_type;

  // constructors
  StrBlob();
  StrBlob(std::initializer_list<std::string> il);

  // size operation
  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }

  // add and remove elements
  void push_back(const std::string &t) { data->push_back(t); }
  void pop_back();

  // element access
  std::string& front();
  std::string& back();

  // interface to StrBlobPtr
  StrBlobPtr begin();
  StrBlobPtr end();

  long count() { return data.use_count(); }
private:
  std::shared_ptr<std::vector<std::string>> data;
  // throws msg if data[i] isn't valid
  void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob(): data(std::make_shared<std::vector<std::string>>()) { }
StrBlob::StrBlob(std::initializer_list<std::string> il):
  data(std::make_shared<std::vector<std::string>>(il)) { };

void StrBlob::check(size_type i, const std::string &msg) const
{
  if (i >= data->size())
    throw std::out_of_range(msg);
}

std::string& StrBlob::front()
{
  // if the vector is empty, check will throw
  check(0, "front on empty StrBlob");
  return data->front();
}

std::string& StrBlob::back()
{
  check(0, "back on empty StrBlob");
  return data->back();
}

void StrBlob::pop_back()
{
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}

// StrBlobPtr throws an exception on attempts to access a nonexistent element
class StrBlobPtr {
  friend bool eq(const StrBlobPtr &, const StrBlobPtr &);
public:
  StrBlobPtr(): curr(0) { }
  StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }

  std::string& deref() const;
  StrBlobPtr& incr();		// prefix version

  long count() { return wptr.use_count(); }
  
private:
  // check returns a shared_ptr to the vector if the check succeeds
  std::shared_ptr<std::vector<std::string>>
  check(std::size_t, const std::string &) const;

  // store a weak_ptr, which means the underlying vector might be destroyed
  std::weak_ptr<std::vector<std::string>> wptr;
  std::size_t curr;		// current position within the array
};

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg)
  const
{
  auto ret = wptr.lock();	// is the vector still around
  if (!ret)
    throw std::runtime_error("unbound StrBlobPtr");

  if (i >= ret->size())
    throw std::out_of_range(msg);

  return ret;			// otherwise, return a shared_ptr to the vector
}

std::string& StrBlobPtr::deref() const
{
  auto p = check(curr, "dereference past end");
  return (*p)[curr];		// (*p) is the vector to which this object points
}

// prefix: return a reference to the incremented object
StrBlobPtr& StrBlobPtr::incr()
{
  // if curr already points past the end of the container, can't increment it
  check(curr, "increment past end of StrBlobPtr");
  ++curr;			// advance the current state
  return *this;
}

StrBlobPtr
StrBlob::begin() { return StrBlobPtr(*this); }

StrBlobPtr
StrBlob::end() {
  auto ret = StrBlobPtr(*this, data->size());
  return ret;
}

// named equality operators for StrBlobPtr
bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
  auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
  // if the underlying vector is the same
  if (l == r)
    // then they're equal if they're both null or
    // if they point to the same element
    return (!r || lhs.curr == rhs.curr);
  else
    return false; // if they point to difference vectors, they're not equal
}

bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
  return !eq(lhs, rhs);
}

int main()
{
  StrBlob str({ "hello", "world" });
  std::cout << "before: " << str.count() << std::endl; // 1
  StrBlob str_cp(str);
  std::cout << "after: " << str.count() << std::endl;  // 2

  StrBlobPtr p(str);
  std::cout << "before: " << p.count() << std::endl; // 2
  StrBlobPtr p_cp(p);
  std::cout << "after: " << p.count() << std::endl; // 2

  return 0;
}
