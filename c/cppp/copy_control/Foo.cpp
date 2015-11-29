/**
 * Foo.cpp
 * Testing copy constructor and copy initialization.
 * Compilation: g++ -o Foo Foo.cpp
 * Created: 2015-09-30
 */

#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::initializer_list;
using std::sort;

/*
 * Ordinarily, we can call a member function on an object, regardless of
 * whether that object is an lvalue or an rvalue.
 *
 * In C++11, we can indicate the lvalue/rvalue property of this in the same way
 * that we define const member functions; we place a reference qualifier after
 * the parameter list. The reference qualifier can be either & or &&, indicating
 * that this may point to an rvalue or lvalue, respectively. Like the const
 * qualifier, a reference qualifier may appear only on a (nonstatic) member
 * function and must appear in both declaration and definition of the function.
 * We may run a function qualified by & only on lvalue and may run a function
 * qualified by && only on an rvalue. A function can be both const and reference
 * qualified. In such cases, the reference qualifier must follow the const
 * qualifier.
 *
 * Just as we can overload a member function based on whether it is const, we
 * can also overload a function based on its reference qualifier.
 *
 * If a member function has a reference qualifier, all the versions of that
 * member with the same parameter list must have reference qualifiers.
 */

class Foo {
public:
    Foo() = default;
    Foo(initializer_list<int> il): data(il) { }
    Foo &operator=(const Foo&) &;   // may assign only to modifiable lvalues
    Foo sorted() &&;        // may run on modifiable rvalues
    Foo sorted() const &;   // may run on any kind of Foo
private:
    vector<int> data;
};

Foo &Foo::operator=(const Foo &rhs) &
{
    // do whatever is needed to assign rhs to this object
    return *this;
}
// this object is an rvalue, so we can sort in place
Foo Foo::sorted() &&
{
    sort(data.begin(), data.end());
    return *this;
}
// this object is either const or it is a lvalue; either way we can't sort in place
Foo Foo::sorted() const &
{
    Foo ret(*this);                         // make a copy
    sort(ret.data.begin(), ret.data.end()); // sort the copy
    return ret;                             // return the copy
}

Foo foo = {5, 4, 3, 2, 1};
Foo &retFoo() { // returns a reference; a call to retFoo is an lvalue
    return foo;
}

Foo retVal() {  // returns by value; a call to retVal is an rvalue
    return Foo({5,4,3,2,1});
}

int main()
{
    string s1 = "a value", s2 = "another";
    s1 + s2 = "wow!";   // ok, but surprising

    Foo i, j;       // i and j are lvalues
    i = j;          // ok: i is an lvalue
    retFoo() = i;   // ok: retFoo() returns an lvalue
  //retVal() = j;   // error: retVal() returns an rvalue
    i = retVal();   // ok: we can pass an rvalue as the right-hand operand to assignment

    retVal().sorted();  // retVal() is an rvalue, calls Foo::sorted() &&
    retFoo().sorted();  // retFoo() is an lvalue, calls Foo::sorted() const &

    return 0;
}
