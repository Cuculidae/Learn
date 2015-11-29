/**
 * switch_geek.cpp
 * Explore more geek features of switch statement.
 * Compilation: g++ o switch_geek switch_geek.cpp
 * Created: 2015-09-08
 */

#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
    // pathological examples
    
    // the statement doesn't have to be a compound statement
    switch(0)
        cout << "this does nothing" << endl;

    // labels don't require a compound statement either
    switch(int n = 1)
        case 0:
        case 1: cout << n << endl;

    // default label need not be the last label
    for (int i = 0; i < 3; ++i) {
        switch(i) {
            default:    cout << "default" << endl;
            case 1:     cout << "case 1" << endl;
            case 2:     cout << "case 2" << endl;
        }
    }

    // Duff's device
    const int sz = 24;
    int a[sz], b[sz];
    for (int i = 0; i < sz; ++i) 
        a[i] = i;
    int *from = a, *to = b;
    int n = (sz + 7) / 8;
    switch (sz % 8) {
        case 0: do { *to++ = *from++;
        case 7:      *to++ = *from++;
        case 6:      *to++ = *from++;
        case 5:      *to++ = *from++;
        case 4:      *to++ = *from++;
        case 3:      *to++ = *from++;
        case 2:      *to++ = *from++;
        case 1:      *to++ = *from++;
                 } while (--n > 0);
    }
    for (auto i : b)
        cout << i << " ";
    cout << endl;

    return 0;
}
