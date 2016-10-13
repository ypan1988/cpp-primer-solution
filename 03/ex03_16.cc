#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

int main()
{
  vector<int> v1;
  vector<int> v2(10);
  vector<int> v3(10, 42);
  vector<int> v4{10};
  vector<int> v5{10, 42};
  vector<string> v6{10};
  vector<string> v7{10, "hi"};

  cout << "v1 has " << v1.size() << " elements" << endl;
  for (auto i : v1)
    cout << i << " ";
  cout << endl;

  cout << "v2 has " << v2.size() << " elements" << endl;
  for (auto i : v2)
    cout << i << " ";
  cout << endl;
  
  cout << "v3 has " << v3.size() << " elements" << endl;
  for (auto i : v3)
    cout << i << " ";
  cout << endl;

  cout << "v4 has " << v4.size() << " elements" << endl;
  for (auto i : v4)
    cout << i << " ";
  cout << endl;

  cout << "v5 has " << v5.size() << " elements" << endl;
  for (auto i : v5)
    cout << i << " ";
  cout << endl;

  cout << "v6 has " << v6.size() << " elements" << endl;
  for (auto s : v6)
    cout << s << " ";
  cout << endl;
  
  cout << "v7 has " << v7.size() << " elements" << endl;
  for (auto s : v7)
    cout << s << " ";
  cout << endl;

  return 0;
}
