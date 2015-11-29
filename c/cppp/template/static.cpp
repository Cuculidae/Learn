/**
 * static.cpp
 * class template static members.
 * Compilation: g++ -o static static.cpp
 * Created: 2015-09-26
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

/*
 * We define static members as a template similarly to how we define the member
 * functions of that template. Each instantiation of a class template has its
 * own instance of the static members.
 * Like any other member function, a static member function is instantiated only
 * if it is used in a program.
 */

template<typename T> class Foo {
public:
    static void count() { cout << ctr++ << endl; }
private:
    static std::size_t ctr;
};

template<typename T>
std::size_t Foo<T>::ctr = 0;    // define and initialize ctr

int main(void)
{
    // instantiates static members Foo<string>::ctr and Foo<string>::count
    Foo<string> fs;
    // all three objects share the same Foo<int>::ctr and Foo<int>::count
    // members
    Foo<int> fi1, fi2, fi3;

    Foo<int> fi;        // instantiates Foo<int> class and the static data member ctr
    Foo<int>::count();   // instantiates Foo<int>::count
    fi.count();         // uses Foo<int>::count
  //Foo::count();       // error: which template instantiation?

    return 0;
}
