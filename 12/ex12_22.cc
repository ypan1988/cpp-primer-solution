#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

// forward declaration needed for friend declaration in StrBlob
class ConstStrBlobPtr;

class StrBlob {
  friend class ConstStrBlobPtr;
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

  // interface to ConstStrBlobPtr
  ConstStrBlobPtr begin() const;
  ConstStrBlobPtr end() const;

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

// ConstStrBlobPtr throws an exception on attempts to access a nonexistent element
class ConstStrBlobPtr {
  friend bool eq(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
public:
  ConstStrBlobPtr(): curr(0) { }
  ConstStrBlobPtr(const StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }

  const std::string& deref() const;
  ConstStrBlobPtr& incr();		// prefix version

private:
  // check returns a shared_ptr to the vector if the check succeeds
  std::shared_ptr<std::vector<std::string>>
  check(std::size_t, const std::string &) const;

  // store a weak_ptr, which means the underlying vector might be destroyed
  std::weak_ptr<std::vector<std::string>> wptr;
  std::size_t curr;		// current position within the array
};

std::shared_ptr<std::vector<std::string>>
ConstStrBlobPtr::check(std::size_t i, const std::string &msg)
  const
{
  auto ret = wptr.lock();	// is the vector still around
  if (!ret)
    throw std::runtime_error("unbound ConstStrBlobPtr");

  if (i >= ret->size())
    throw std::out_of_range(msg);

  return ret;			// otherwise, return a shared_ptr to the vector
}

const std::string& ConstStrBlobPtr::deref() const
{
  auto p = check(curr, "dereference past end");
  return (*p)[curr];		// (*p) is the vector to which this object points
}

// prefix: return a reference to the incremented object
ConstStrBlobPtr& ConstStrBlobPtr::incr()
{
  // if curr already points past the end of the container, can't increment it
  check(curr, "increment past end of ConstStrBlobPtr");
  ++curr;			// advance the current state
  return *this;
}

ConstStrBlobPtr
StrBlob::begin() const {
  return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr
StrBlob::end() const {
  auto ret = ConstStrBlobPtr(*this, data->size());
  return ret;
}

// named equality operators for ConstStrBlobPtr
bool eq(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
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

bool neq(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return !eq(lhs, rhs);
}

int main()
{
	const StrBlob b = { "a", "an", "the", "about" };

	for (auto it = b.begin(); neq(it, b.end()); it.incr())
		std::cout << it.deref() << std::endl;

	return 0;
}
