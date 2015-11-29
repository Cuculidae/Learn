/**
 * const.cpp
 * Demonstrate usage of keyword const.
 * Dependecies: const2.cpp
 * Compilation: g++ -o const const.cpp const2.cpp
 * Created: 2015-09-03
 */

#include <iostream>

int f(void);
void g(void);

/*
 * Unlike C, by default, const objects are local to file in C++
 * To define a single instance of a const variable, use 
 * keyword extern on both its definition and declaration
 */
extern const int i = f(); // can be referenced by other translation unit
const int j = 1;          // local to this file

/*
 * Because a const object cannot change, it must be initialized.
 */
const int bufsize = 512;    // local to this file
                               // const2.cpp also defines bufsize

int main(void)
{
    std::cout << "const.cpp bufsize == " << bufsize << std::endl;

    std::cout << "const.cpp i == " << i << std::endl;
    std::cout << "const.cpp j == " << j << std::endl;

    g();

    return 0;
}

int f(void)
{
    return 1;
}
