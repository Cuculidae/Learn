/**
 * fill.cpp
 * Compilation: g++ -o fill fill.cpp -std=c++11
 * Created: 2015-09-17
 */

#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::fill;

int main(void)
{
    constexpr int size = 10;
    vector<int> ivec(size);

    fill(ivec.begin(), ivec.end(), 1);
    for (const int i : ivec)
        cout << i << " ";
    cout << endl;

    return 0;
}
