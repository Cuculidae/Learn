/*
 * test_Blob.cpp
 * Test the Blob class template.
 * Compilation: g++ -o test_Blob test_Blob.cpp -std=c++11
 * Created: 2015-09-26
 */

#include "Blob.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::string;
using std::begin;
using std::end;

int main(void)
{
    Blob<string> articles{"a", "an", "the"};

    // instantiates Blob<int> and the initializer_list<int> constructor
    Blob<int> squares{0,1,2,3,4,5,6,7,8,9};
    // instantiates Blob<int>::size() const
    for (size_t i = 0; i != squares.size(); ++i)
        squares[i] = i * i; // instantiates Blob<int>::operator[](size_type i)
    for (size_t i = 0; i != squares.size(); ++i)
        cout << squares[i] << ' ';
    cout << endl;

    int ia[] = {0,1,2,3,4,5,6,7,8,9};
    vector<long> vi = {0,1,2,3,4,5,6,7,8,9};
    list<const char*> w = {"now", "is", "the", "time"};
    // instantiates the Blob<int> class
    // and the Blob<int> constructor that has two int* parameter
    Blob<int> b1(begin(ia), end(ia));
    // instantiates the Blob<int> constructor that has
    // two vector<long>::iterator parameters
    Blob<int> b2(vi.begin(), vi.end());
    // instantiates the Blob<string> class and the Blob<string>
    // constructor that has two list<const char*>::iterator parameters
    Blob<string> a3(w.begin(), w.end());

    return 0;
}
