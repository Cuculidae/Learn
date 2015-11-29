/**
 * find.cpp
 * Compilation: g++ -o find find.cpp
 * Created: 2015-09-17
 */

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::find;
using std::begin;
using std::end;

int main(void)
{
    vector<int> ivec = {1, 2, 3, 4, 5};
    int val = 5;
    // result will denote the element we want if it's in ivec, or ivec.end()
    // if not
    auto result = find(ivec.cbegin(), ivec.cend(), val);
    cout << " The value " << val
         << (result == ivec.end() ?
                 " is not present" : " is present") << endl;

    int ia[] = {27, 210, 12, 47, 109, 83};
    val = 83;
    int* res = find(begin(ia), end(ia), val);

    return 0;
}
