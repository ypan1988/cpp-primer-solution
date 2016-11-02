#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
  // initialize counters of each vowel
  unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0,
    spaceCnt = 0, tabCnt = 0, newlineCnt = 0,
    ffCnt = 0, flCnt = 0, fiCnt = 0;
  char ch, ch2 = ' '; 
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
      if (ch2 == 'f') ++fiCnt;
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
    case 'f':
      if (ch2 == 'f') ++ffCnt;
      break;
    case 'l':
      if (ch2 == 'l') ++flCnt;
      break;
    }
    ch2 = ch;
  }
  // print results
  cout << "Number of vowel a(A): \t" << aCnt << '\n'
       << "Number of vowel e(E): \t" << eCnt << '\n'
       << "Number of vowel i(I): \t" << iCnt << '\n'
       << "Number of vowel o(O): \t" << oCnt << '\n'
       << "Number of vowel u(U): \t" << uCnt << '\n'
       << "Number of space: \t" << spaceCnt << '\n'
       << "Number of tab: \t" << tabCnt << '\n'
       << "Number of newline: \t" << newlineCnt << '\n'
       << "Number of ff: \t" << ffCnt << '\n'
       << "Number of fl: \t" << flCnt << '\n'
       << "Number of fi: \t" << fiCnt << endl;

  return 0;
}
