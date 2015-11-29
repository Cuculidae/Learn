/**
 * beginend.cpp
 * mimics the standard library begin and end function.
 * Compilation: g++ -o beginend beginend.cpp -std=c++11
 * Created: 2015-09-27
 */

#include <iostream>

using std::cout;
using std::endl;

template<typename T, unsigned N>
T* begin(const T (&arr)[N])
{
    return const_cast<T*>(arr);
}

template<typename T, unsigned N>
T* end(const T (&arr)[N])
{
    return const_cast<T*>(arr+N);
}

int main(void)
{
    int a[5] = {1,2,3,4,5};
    for (auto b = begin(a), e = end(a);
         b != e; ++b)
        cout << *b << ' ';
    cout << endl;

    return 0;
}
