/**
 * X.cpp
 * Demonstrate copy costructor, copy assignment, destructor.
 * Compilation: g++ -o X X.cpp -std=c++11
 * Created: 2015-09-22
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class X
{
    public:
    X(string s = "temp"): name(s) {
        cout << "X(): " << s << endl;
    }
    X(const X &rhs) {
        cout << "X(const X&): " 
             << "copy from " << rhs.name
             << endl;
        name = rhs.name + "copy";
    }
    X& operator=(const X &rhs) { 
        cout << "operator=(const X&): " 
             << "assign from " << rhs.name
             << endl;
        name = "assignfrom" + rhs.name;
        return *this;
    }
    ~X() {
        cout << "~X(): " << name << endl;
    }
    private:
    string name;
};

X g(X x) {
    return x;
}

int main()
{
    cout << "X x(\"x\"): ";
    X x("x");
    {
        cout << "BLOCK:" << endl;
        X y(x);
        cout << "END BLOCK" << endl;
    }
    cout << endl;

    cout <<"X z = x: ";
    X z = x;
    cout << "z=x: ";
    z = x;

    cout << "calling g(x): ";
    g(x);

    cout << "X a = g(x): ";
    X a = g(x); // return value optimization, even copy constructor has side effect

    cout << "return from main" << endl;
    return 0;
}
