/**
 * array.cpp
 * Built-in array.
 * Compilation: g++ -o array array.cpp -std=c++
 * Created: 2015-09-08
 */

#include <iostream>

using std::cout;
using std::endl;

void show(const int a[], int sz)
{
    for (int i = 0; i < sz; ++i)
        cout << a[i] << " ";
    cout << endl;
}

int main(void)
{
    /*
     * No array copy or assignemnt!
     * If the dimension is greater than the number of initializers, the
     * initializers are used for the first elements and any remaining 
     * elements are value initialized.
     */
    constexpr int sz = 3;
    int a1[sz];             // default initialization
    int a2[sz] = {1, 2, 3}; // list initialization
    int a3[] = {1, 2, 3};   // list initialization; size infered by compiler
    int a4[sz] = {};        // list initialization;
                               // Note that the list cannot be empty in C
    show(a1, sz);
    show(a2, sz);
    show(a3, sz);
    show(a4, sz);

    /*
     * char arrays can be initialized from a string literal.
     * The null character is copied into the array along.
     */
    char a5[] = "C++";      // null terminator added automatically
  //char a6[6] = "Daniel";  // error: no space for the null!
    cout << a5 << endl;
    
    /*
     * The index used with the built-in subscript operator can be negative
     */
    int ia[] = {0, 2, 4, 6, 8};
    int *p = &ia[2];
    int j = p[1];       // p[1] is the same as ia[3]
    int k = p[-2];      // p[-2] is the same as ia[0]

    return 0;
}
