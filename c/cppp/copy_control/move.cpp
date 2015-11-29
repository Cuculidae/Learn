/**
 * move.cpp
 * C++ move semantics.
 * Comilation: g++ -o move move.cpp -std=c++11
 * Created: 2015-11-05
 */

#include <iostream>
#include <utility>

using std::cout;
using std::endl;

struct X {
    X() = default;
    X(const X&) {
        cout << "copy constructor" << endl;
    }
    X(X&&) {
        cout << "move constructor" << endl;
    }
    X& operator=(const X&) {
        cout << "copy assignment" << endl;
        return *this;
    }
    X& operator=(X&&) {
        cout << "move assignemnt" << endl;
        return *this;
    }
};

int main()
{
    X a;
    cout << "X b = a: ";
    X b = a;

    cout << "X c = std::move(b):";
    X c = std::move(b);

    cout << "c = a:";
    c = a;
    cout << "c = X():";
    c = X();

    return 0;
}
