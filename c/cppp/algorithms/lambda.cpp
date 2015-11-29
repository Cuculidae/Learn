/**
 * lambda.cpp
 * C++11 lambda expression.
 * Compilation: g++ -o lambda lambda.cpp -std=c++11
 * Created: 2015-09-17
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::unique;
using std::find_if;
using std::for_each;
using std::vector;
using std::string;
using std::istringstream;


/*
 * An object or expression is callable if we can apply the call operator to it.
 *
 * Four kinds of callables:
 *  #1 functions
 *  #2 function pointers
 *  #3 classes that overload the function call operator
 *  #4 lambda expressions (since C++11)
 *
 * A lamba expression has the form:
 *  [capture list](parameter list) -> return type { function body }
 *  where capture list is an (often empty) list of local variables defined in
 *  the enclosing function;
 *
 * We can omit either or both of the parameter list and return type but must
 * always include the capture list and function body. If we omit the return
 * type, the lambda has an inferred return type that depends on the code in the
 * function body. If the function body is just a return statement, the return
 * type is inferred from the type of the expression that is returned. Otherwise,
 * the return type is void.
 *
 * A lambdamay not have default arguments.
 *
 * A lambdamay use a variable local to its surrounding function only if the
 * lambda captures that variable in its capture list. The capture list is used
 * for local nonstatic variables only; lambdas can use local statics and
 * variables declared outside the function directly.
 *
 * When we define a lambda, the compiler generates a new (unnamed) class type
 * that corresponds to that lambda. when we use auto to define a variable
 * initialized by a lambda, we are defining an object of the type generated from
 * that lambda. By default, the class generated from a lambda contains a data
 * member corresponding to the variables captured by the lambda.
 *
 * The valud of a captured variable is copied when the lambda is created, not
 * when it is called.
 * When we capture a variable by reference, we must ensure that the variable
 * exists at the time that the lambda executes.
 * []                   Empty capture list. The lambda may not use variables
 *                      from the enclosing function. A lamba may use local
 *                      variables only if it captures them.
 * [&]                  Implicit by reference capture list. Entities from the
 *                      enclosing function used in the lambda body are used by
 *                      reference.
 * [=]                  Implicit by value capture list. Entities from the
 *                      enclosing function used in the lambda body are copied
 *                      into the lambda body.
 * [&, identifier_list] identifier_list is a comma-separated list of zero or
 *                      more variables from the enclosing function. These
 *                      variables are captured by value; any implicitly captured
 *                      variables are captured by reference. The names in
 *                      identifier_list must not be preceded by an &.
 * [=, reference_list]  Variables included in the reference_list are captured by
 *                      reference; any implicitly captured variables are
 *                      captured by value. The names in reference_list may not
 *                      include this and must be preceded by an &.
 *
 * By default, a lambdamay not change the value of a variable that it copies by
 * value. If we want to be able to change the value of a captured variable, we
 * must follow the parameter list with the keyword mutable. Lambdas that
 * aremutable may not omit the parameter list. Whether a variable captured by
 * reference can be changed (as usual) depends only on whether that reference
 * refers to a const or nonconst type.
 */

string make_plural(size_t count, string word, string suf);
void elimDups(vector<string> &words);
void biggies(vector<string> &words, vector<string>::size_type sz);

auto f = [] { return 42; };

void fcn1()
{
    size_t v1 = 42;
    // copies v1 into the callable object named f
    auto f = [v1] { return v1; };
    v1 = 0;
    auto j = f();   // j is 42;f stored a copy of v1 when we created it
    cout << "fcn1() j = " << j << endl;
}

void fcn2()
{
    size_t v1 = 42;
    // the objec f contains a reference to v1
    auto f = [&v1] { return v1; };
    v1 = 0;
    auto j = f();   // j is 0; f refers to v1; it doesn't store it
    cout << "fcn2() j = " << j << endl;
}

void fcn3()
{
    size_t v1 = 42;
    // f can change the value of the variable it captures
    auto f = [v1] () mutable { return ++v1; };
    v1 = 0;
    auto j = f();   // j is 43
    cout << "fcn3() j = " << j << endl;
}

void fcn4()
{
    size_t v1 = 42;
    // v1 is a reference to a nonconst variable
    // we can change that variable through the reference inside f
    auto f = [&v1] { return ++v1; };
    v1 = 0;
    auto j = f();  // j is 1
    cout << "fcn4() j = " << j << endl;
}

int main(void)
{
    cout << f() << endl;    // prints 42
    fcn1();
    fcn2();
    fcn3();
    fcn4();

    string text = "the quick red fox jumps over the slow red turtle";
    istringstream is(text);
    vector<string> words;
    string s;

    while (is >> s)
        words.push_back(s);

    biggies(words, 5);

    return 0;
}

string make_plural(size_t count, string word, string suf)
{
    return count > 1 ? word+suf : word;
}

void elimDups(vector<string> &words)
{
    // sort words alphabetically so we can find the duplicates
    sort(words.begin(), words.end());
    // eliminate duplicates and return an iterator one past the unique range
    auto end_unique = unique(words.begin(), words.end());
    // erase uses a vector operation to remove the nonunique elements
    words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);    // put words in alphabetical order and remove duplicates
    // resort by length, maintaining alphabetical order among words of the same
    // length
    stable_sort(words.begin(), words.end(),
            [](const string &s1, const string &s2)
            { return s1.size() < s2.size(); });
    // get an iterator to the first element whose size() is >= sz
    auto wc = find_if(words.begin(), words.end(),
            [sz] (const string &s) { return s.size() >= sz; });
    // compute the number of elements with size >= sz
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << endl;
    // print words of the given size or longer, each one followed by space
    for_each(wc, words.end(),
            [] (const string &s) { cout << s << " "; });
    cout << endl;
}
