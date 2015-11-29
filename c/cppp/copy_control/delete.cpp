/**
 * delete.cpp
 * C++11 delete keyword.
 * Compilation: g++ -o delete delete.cpp -std=c++11
 * Created: 2015-11-04
 */

#include <iostream>

using namespace std;

/*
 * In C++11, we can prevent copies by defining the copy constructor and copy
 * assignment operator as deleted functions. Unlike = default, = delete must
 * appear on the first declaration of a deleted function. Also unlike = default,
 * we can specify = delete on any function.
 *
 * The compiler will not let us define variables or create temporaries of a type
 * that has a deleted destructor. Moreover, we cannot define variables or
 * temporaries of a class that has a member whose type has a deleted destructor.
 *
 * Although we cannot define variables or members of such types, we can
 * dynamically allocate objects with a deleted destructor. However, we cannot
 * free them.
 */

struct NoDtor {
    NoDtor() = default; // uses synthesized default constructor
    ~NoDtor() = delete; // we can't destroy objects of type NoDtor
};

int main()
{
  //NoDtor nd;  // error: NoDtor destructor is deleted
    NoDtor *p = new NoDtor();   // ok: but we can't delete p
  //delete p;   // error: NoDtor destructor is deleted

    return 0;
}
