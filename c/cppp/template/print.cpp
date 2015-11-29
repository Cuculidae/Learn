/**
 * print.cpp
 * exercise on function template.
 * Compilation: g++ -o print print.cpp -std=c++11
 * Created: 2015-09-26
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

template<typename T, unsigned N>
std::ostream& print(std::ostream &os, const T (&arr)[N])
{
    for (const T &a : arr)
        cout << a << ' ';
    return os;
}

int main(void)
{
    int ia[5] = {1, 2, 3, 4, 5};
    print(cout, ia) << endl;
    string sa[3] = {"a", "an", "then"};
    print(cout, sa) << endl;

    return 0;
}
