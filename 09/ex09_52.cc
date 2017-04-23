#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <stack>
using std::stack;

int main()
{
  string expr = "hello(1234)abc(4321)world";
  stack<char> stk;
  bool open = false;

  auto iter = expr.begin();
  while(iter != expr.end()) {
    if (*iter == '(') open = true;
    if (open) stk.push(*iter);
    if (*iter == ')') {
      while (stk.top() != '(') {
    	cout << stk.top() << " ";
    	stk.pop();
      }
      cout << stk.top() << " " << endl;
      stk.pop();
      stk.push(0);
      open = false;
    }
    ++iter;
  }  
  
  return 0;
}
