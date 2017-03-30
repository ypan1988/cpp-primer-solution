#include <iostream>
#include <string>

using std::cout;

class Screen {
public: 
  typedef std::string::size_type pos;
  Screen() = default;
  Screen(pos ht, pos wd): height(ht), width(wd), contents(ht * wd, ' ') { }
  Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) { }

  Screen move(pos r, pos c);
  Screen set(char c);
  Screen set(pos r, pos col, char ch);

  // display overloaded on whether the object is const or not
  Screen display(std::ostream &os) { do_display(os); return *this; }
  const Screen display(std::ostream &os) const { do_display(os); return *this; }

private:
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;

  // function to do the work of displaying a Screen 
  void do_display(std::ostream &os) const { os << contents; }
};   

inline Screen Screen::move(pos r, pos c)
{
  pos row = r * width;		// compute row location
  cursor = row + c;		// movew cursor to the column within that row
  return *this;			// return this object as an lvalue
}

inline Screen Screen::set(char c)
{
  contents[cursor] = c;		// set the new value at the current cursor location
  return *this;
}

inline Screen Screen::set(pos r, pos col, char c)
{
  contents[r*width + col] = c;	// set specified location to given value
  return *this;			// return this object as an lvalue
}

int main() 
{
  Screen myScreen(5, 5, 'X');
  myScreen.move(4,0).set('#').display(cout);
  cout << "\n";
  myScreen.display(cout);
  cout << "\n";
 
  return 0;
}
