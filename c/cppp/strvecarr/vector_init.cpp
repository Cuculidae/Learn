/**
 * vector_init.cpp
 * Show initialization of vectors.
 * Compilation: g++ -o vector_init vector_init.cpp -std=c++11
 * Created: 2015-09-07
 */

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

// show elements of vector of int
void show(string prefix, vector<int> iv)
{
    cout << prefix; 
    for (auto e : iv)
        cout << e << " ";
    cout << endl;
}

// show elements of vector of string
void show(string prefix, vector<string> sv)
{
    cout << prefix;
    for (auto e : sv)
        cout << e << " ";
    cout << endl;
}

int main(void)
{
    vector<int> ivec;           // default initialization; ivec has no elements
    show("ivec: ", ivec);

    vector<int> ivec1(10, 1);   // construct 10 elements of 1
    show("ivec1: ", ivec1);

    vector<int> ivec2 = ivec1;  // copy initialization
    show("ivec2: ", ivec2);
    vector<int> ivec3(ivec2);   // the same as above
    show("ivec3: ", ivec3);

    vector<int> ivec4(10);      // value-initialization; 10 elements initialized to 0
    show("ivec4: ", ivec1);
    vector<string> svec(10);    // value-initialization; each string default initialized
    show("svec: ", svec);

    vector<string> article = {"a", "an", "the"};    // list initialization; C++11
    show("article: ", article);
    vector<string> article2{"a", "an", "the"};      // the same as above
    show("article2: ", article2);

    /* if we use curly braces, only if it is not possible to list initialize the
     * object will the other ways to initialize the object be considered.
     */
    vector<int> v1(10);     // v1 has ten elements of 0
    vector<int> v2{10};     // v2 has one element of 10
    vector<int> v3(10, 1);  // v3 has ten elemnts of 1
    vector<int> v4{10, 1};  // v4 has two elements 10, 1
    vector<string> v5{10};  // v5 has ten default initialized elements
    vector<string> v6{10, "hi"};    // v6 has ten elements of "hi"
    vector<string> v7{v6};  // v7 has the content of v6
    show("v1: ", v1);
    show("v2: ", v2);
    show("v3: ", v3);
    show("v4: ", v4);
    show("v5: ", v5);
    show("v6: ", v6);
    show("v7: ", v7);

    return 0;
}
