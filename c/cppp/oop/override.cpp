/**
 * override.cpp
 * C++11 override specifier.
 * Compilation: g++ -c override.cpp -std=c++11 (won't compile)
 * Created: 2015-10-04
 */

/*
 * The compiler will reject a program if a function marked override does not
 * override an existing virtual function.
 */

struct B {
    virtual void f1(int) const;
    virtual void f2();
    void f3();
};

struct D1 : B {
    void f1(int) const override;    // ok: f1 matches f1 in the base
    void f2(int) override;  // error: B has no f2(int) function
    void f3() override;     // error: f3 not virtual
    void f4() override;     // error: B doesn't have a function named f4
};
