/**
 * function.cpp
 * Compilation: g++ -o function function.cpp -std=c++11
 * Created: 2015-09-24
 */

#include <iostream>
#include <functional> // defines some function-object classes
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using std::function;
using std::cout;
using std::endl;
using std::map;
using std::vector;
using std::string;
using std::plus;
using std::minus;
using std::negate;
using std::greater;
using std::less;
using std::sort;

/*
 * The standard library defines a set of classes that represent the arithmetic,
 * relational, and logical operators. Each class defines a call operator that
 * applies the named operation. These classes are templates to which we supply a
 * single type. That type specifies the parameter type for the call operator.
 *
 * Libary Function Objects
 * Arithmetic       Relational          Logical
 * plus<T>          equal_to<T>         logical_and<T>
 * minus<T>         not_equal_to<T>     logical_or<T>
 * multiplies<T>    greater<T>          logical_not<T>
 * divids<T>        greater_equal<T>    
 * modulus<T>       less<T>
 * negate<T>        less_equal<T>
 *
 * One important aspect of these library function objects is that the libray
 * guarantees that they will work for pointers. Recall that comparing two
 * unrelated pointers is undefined.
 *
 * It is also worth noting that the associative containers use less<key_type> to
 * order their elements.
 *
 * C++11 new library type named function is defined in the <functional> header.
 * function is a template. we must supply the call signature of the objects that
 * this particular function type can represent when we create a function type.
 * Operations on function:
 * function<T> f;           f is a null function object that can store callable
 *                          objects with a call signature that is equivalent to
 *                          the function type T (i.e., T is retType(args)).
 * function<T> f(nullptr);  Explicitly construct a null function.
 * function<T> f(obj);      Stores a copy of the callable object obj in f.
 * f                        Use f as a condition; true if f holds a callable
 *                          object; false otherwise.
 * f(args)                  Calls the object in f passing args.
 * Types defined as members of function<T>
 * result_type          The type returned by this function type's callable
 *                      object 
 * argument_type        Types defined when T has exactly one or two arguments.
 * first_argument_type  If T has one argument, argument_type is a synonym for
 * second_argument_type that type. If T has two arguments, first_argument_type
 *                      and second_argument_type are synonyms for those argument
 *                      types.
 *
 * We cannot (directly) store the name of an overloaded function in an object of
 * type function. One way to resolve the ambiguity is to store a function
 * pointer instead of the name of the function.
 */

int add(int i, int j) { return i+j; }
auto mod = [](int i, int j) { return i%j; };
struct divide {
    int operator()(int denominator, int divisor) {
        return denominator / divisor;
    }
};

int main(void)
{
    plus<int> intAdd;       // function object that can add two int values
    negate<int> intNegate;  // function object that can negate an int value
    // uses intAdd::operator(int, int) to add 10 and 20
    int sum = intAdd(10, 20);       // equivalent to sum = 30
    cout << "sum: " << sum << endl;
    sum = intNegate(intAdd(10, 20));// equivalent to sum = -30
    cout << "sum: " << sum << endl;
    // uses intNegate::operator(int) to generate -10 as the second parameter
    // to intAdd::operator(int, int)
    sum = intAdd(10, intNegate(10));    // sum = 0
    cout << "sum: " << sum << endl;


    vector<int> iv{1023, 1024, 1025, 1026};
    // passes a temporary function object that applies the < operator to two
    // strings
    sort(iv.begin(), iv.end(), greater<int>());
    for (const auto &i : iv)
        cout << i << ' ';
    cout << endl;

    string a = "abc", b = "def", c = "ghi";
    vector<string*> nameTable{&a, &b, &c};
    sort(nameTable.begin(), nameTable.end(), less<string*>());
    for (auto p : nameTable)
        cout << *p << ' ';
    cout << endl;


    function<int(int, int)> f1 = add;   // function pointer
    function<int(int, int)> f2 = divide();  // object of a function-object class
    function<int(int, int)> f3 = [](int i, int j)   // lambda
                                     { return i * j; };
    cout << f1(4, 2) << endl;   // prints 6
    cout << f2(4, 2) << endl;   // prints 2
    cout << f3(4, 2) << endl;   // prints 8
    // table of callable objects corresponding to each binary operator
    // all the callables must take two ints and return an int
    // an element can be a function pointer, function object, or lambda
    map<string, function<int(int, int)>> binops = {
        {"+", add},                                 // function pointer
        {"-", minus<int>()},                        // library function object
        {"/", divide()},                            // user-defined function object
        {"*", [](int i, int j) { return i*j; }},    // unnamed lambad
        {"%", mod} };                               // named lambda object
    int i;
    i = binops["+"](10, 5);     // calls add(10, 5)
    cout << i << endl;
    i = binops["-"](10, 5);     // uses the call operator of the minus<int> object
    cout << i << endl;
    i = binops["/"](10, 5);     // uses the call operator of the divide object
    cout << i << endl;
    i = binops["*"](10, 5);     // calls the lambda function object
    cout << i << endl;
    i = binops["%"](10, 5);     // calls the lambda function object
    cout << i << endl;


    return 0;
}
    

