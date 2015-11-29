/**
 * const2.cpp
 * Demonstrate usage of keyword const.
 * Dependecies: const.cpp
 * Compilation: g++ -o const const.cpp const2.cpp
 * Created: 2015-09-03
 */

#include <iostream>
/*
 * Unlike C, by default, const objects are local to file in C++
 * To define a single instance of a const variable, use 
 * keyword extern on both its definition and declaration
 */
const int bufsize = 512; // local to this file
const int j = 2;        // local to this file

extern const int i; // reference i in const.cpp

void g(void)
{
    std::cout << "const2.cpp i = " << i << std::endl;
    std::cout << "const2.cpp j = " << j << std::endl;
}
