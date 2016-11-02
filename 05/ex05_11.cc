#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
  // initialize counters of each vowel
  unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0,
    spaceCnt = 0, tabCnt = 0, newlineCnt = 0;
  char ch;
  while (cin.get(ch)) {
    // if ch is a vowel, invrement the appropriate
    switch (ch) {
    case 'a':
    case 'A':
      ++aCnt;
      break;
    case 'e':
    case 'E':
      ++eCnt;
      break;
    case 'i':
    case 'I':
      ++iCnt;
      break;
    case 'o':
    case 'O':
      ++oCnt;
      break;
    case 'u':
    case 'U':
      ++uCnt;
      break;
    case ' ':
      ++spaceCnt;
      break;
    case '\t':
      ++tabCnt;
      break;
    case '\n':
      ++newlineCnt;
      break;
    }
  }
  // print results
  cout << "Number of vowel a(A): \t" << aCnt << '\n'
       << "Number of vowel e(E): \t" << eCnt << '\n'
       << "Number of vowel i(I): \t" << iCnt << '\n'
       << "Number of vowel o(O): \t" << oCnt << '\n'
       << "Number of vowel u(U): \t" << uCnt << '\n'
       << "Number of space: \t" << spaceCnt << '\n'
       << "Number of tab: \t" << tabCnt << '\n'
       << "Number of newline: \t" << newlineCnt << endl;

  return 0;
}
