#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iterator>
using std::istream_iterator;

int main()
{
    istream_iterator<string> in_iter(cin), eof;  // read ints from cin
    vector<string> vec(in_iter, eof);            // construct vec from an iterator range

    for (const auto &s : vec)
        cout << s << endl;

    return 0;
}
