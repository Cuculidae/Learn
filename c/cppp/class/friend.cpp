/**
 * friend.cpp
 * Test friend declaration.
 * Compilation: g++ -c friend.cpp (Won't compiled)
 * Created: 2015-09-12
 */

class X
{
    public:
    friend void f() { /* friend function can be defined in the class body */ }
    X() { f(); }    // error: no declaration of f()
    void g();
    void h();
};

void X::g() { return f(); }     // error: f() hasn't been declared
void f();                       // declares the function defined inside X
void X::h() { return f(); }     // ok: declaration for f now is in scope
