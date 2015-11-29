/**
 * final.cpp
 * C++11 final specifier.
 * Compilation: g++ -c final.cpp -std=c++11
 * Created: 2015-10-04
 */

/*
 * Any attempt to override a function that has been defined as final will be
 * flagged as an error.
 */

struct B {
    virtual void f1(int) const;
    virtual void f2();
    void f3();
};

struct D2 : B {
    // inherits f2() and f3() from B and overrides f1(int)
    void f1(int) const final;   // subsequent classes can't override f1(int)
};

struct D3 : D2 {
    void f2();          // ok: overrides f2 inherited from the indirect base B
    void f1(int) const; // error: D2 declared f2 as final
};
