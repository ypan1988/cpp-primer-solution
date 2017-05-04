#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort; using std::copy;

#include <iterator>
using std::istream_iterator; using std::ostream_iterator;

int main()
{
    istream_iterator<int> in_iter(cin), eof; // read ints from cin
    vector<int> vec(in_iter, eof); // construct vec from an iterator range

    sort(vec.begin(), vec.end());

    ostream_iterator<int> out_iter(cout, " ");
    copy(vec.begin(), vec.end(), out_iter);
    cout << endl;

    return 0;
}
