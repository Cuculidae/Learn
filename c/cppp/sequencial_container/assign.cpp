/**
 * assign.cpp
 * Sequential container assign() operation.
 * Compilation: g++ -o assign assign.cpp -std=c++11
 * Created: 2015-09-14
 */

#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::list;
using std::string;
using std::vector;

void print(list<string> ls);

/*
 * assign (Sequential containers only)
 *
 * The sequential containers (except array) also define a member named assign
 * that lets us assign from a different but compatible type, or assign from a
 * subsequence of a container. The assign operation replaces all the elements
 * in the left-hand container with (copies of) the elements specified by its
 * arguments.
 *
 * seq.assign(b, e) Replaces elements in seq with those in the range denoted by
 *                  iterators b and e. The iterators b and e must not refer to
 *                  elements in seq.
 * seq.assign(il)   Replaces the elements in seq with those in the initializer
 *                  list il.
 * seq.assign(n, t) Replaces the elements in seq with n elements with value t.
 *
 * Because the existing elements are replaced, the iterators passed to assign
 * must not refer to the container on which assign is called.
 */

int main(void)
{
    list<string> names;
    vector<const char*> oldstyle = {"Maria", "Jack", "Lucy"};
  //names = oldstyle;   // error: container types don't match
    // ok: can convert from const char* to string
    names.assign(oldstyle.cbegin(), oldstyle.cend());
    cout << "names: ";
    print(names);
    cout << endl;

    // equivalent to names.clear();
    // followed by names.insert(names.begin(), 10, "Hiya!");
    names.assign(10, "Hiya!");  // ten elements; each one is Hiya!
    cout << "names: ";
    print(names);
    cout << endl;

    return 0;
}

void print(list<string> ls)
{
    for (const auto &s : ls)
        cout << s << " ";
}
