#include <iostream>
#include <string>

template <typename Array>
void print(const Array &a){
  for (const auto &elem : a)
    std::cout << elem << std::endl;
  std::cout << std::endl;
}

int main()
{
  int i[] = {1, 2, 3, 4, 5};
  char c[] = {'a', 'b', 'c', 'd', 'e'};
  std::string s[] = {"aa", "bb", "cc", "dd", "ee"};

  print(i);
  print(c);
  print(s);
  
  return 0;
}
