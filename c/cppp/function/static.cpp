#include <iostream>
#include <string>

using namespace std;

class X {
    public:
    X(string t): s(t) { cout << s << endl; }
    string s;
    static X x;
};

X a("X in global");
//X b("X in global" + X::x.s); // error: 
// the initialization order is ?
X X::x("X static member initialized");

void f() {
    static X b("X in f()");
}


int main()
{
    X c("X in main()");
    f();

    return 0;
}
