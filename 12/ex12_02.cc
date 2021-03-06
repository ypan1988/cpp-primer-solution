#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <exception>
#include <memory>

class StrBlob {
public:
  typedef std::vector<std::string>::size_type size_type;

  // constructors
  StrBlob();
  StrBlob(std::initializer_list<std::string> il);

  // size operations
  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }

  // add and remove elements
  void push_back(const std::string &t) { data->push_back(t); }
  void pop_back();

  // element access
  std::string& front();
  std::string& back();
    
  const std::string& front() const;
  const std::string& back() const;

private:
  std::shared_ptr<std::vector<std::string>> data;
  // throws msg if data[i] isn't valid
  void check(size_type i, const std::string &msg) const;
};

// constructor
inline StrBlob::StrBlob(): data(std::make_shared<std::vector<std::string>>()) { }
inline StrBlob::StrBlob(std::initializer_list<std::string> il):
  data(std::make_shared<std::vector<std::string>>(il)) { }

std::string& StrBlob::front()
{
  // if the vector is empty, check will throw
  check(0, "front on empty StrBlob");
  return data->front();
}

const std::string& StrBlob::front() const
{
  // if the vector is empty, check will throws
  check(0, "front on empty StrBlob");
  return data->front();
}

std::string& StrBlob::back()
{
  check(0, "back on empty StrBlob");
  return data->back();
}

const std::string& StrBlob::back() const
{
  check(0, "back on empty StrBlob");
  return data->back();
}

void StrBlob::pop_back()
{
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}

void StrBlob::check(size_type i, const std::string &msg) const
{
  if (i >= data->size())
    throw std::out_of_range(msg);
}

int main()
{
  const StrBlob b1 = {"a", "an", "the"};
  StrBlob b2 = {"Hello", "World", "!"};

  std::cout << b1.front() << " " << b1.back() << std::endl;
  b2.back() = "!!!";
  std::cout << b2.front() << " " << b2.back() << std::endl;

  return 0;
}
