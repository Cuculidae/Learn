/**
 * fill_n.cpp
 * Compilation: g++ -o fill_n fill.cpp -std=c++11
 * Created: 2015-09-17
 */

#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::fill_n;

int main(void)
{
    constexpr int size = 10;
    vector<int> ivec(size);

    fill_n(ivec.begin(), ivec.size(), 1);
    for (const int i : ivec)
        cout << i << " ";
    cout << endl;

    return 0;
}
