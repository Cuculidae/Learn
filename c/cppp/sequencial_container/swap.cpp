/**
 * swap.cpp
 * Container swap operation.
 * Compilation: g++ -o swap swap.cpp -std=c++11
 * Created: 2015-09-14
 */

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::ostream;

ostream &print(vector<int> v);
ostream &print(vector<int>::const_iterator b,
                 vector<int>::const_iterator e);

/*
 * In C++11, the containers offer both a member and nonmember version of swap.
 * The nonmember swap is of most importance in generic programs. As a matter of
 * habit, it is best to use the nonmember version of swap.
 *
 * Excepting array, swap does not copy, delete, or insert any elements and is
 * guaranteed to run in constant time.
 *
 * The fact that elements are notmoved means that, with the exception of string,
 * iterators, references, and pointers into the containers are not invalidated.
 * However, after the swap, those elements are in a different container.
 * Differently from the containers, a call to swap on a string may invalidate
 * iterators, references and pointers.
 *
 * Unlike how swap behaves for the other containers, swapping two arrays does
 * exchange the elements.
 *
 * swap(c1, c2) Exchanges elements in c1 with those in c2. c1 and c2 must be the
 * c1.swap(c2)  same type. swap is usually much faster than copying elements
 *              from c2 to c1.
 */

int main(void)
{
    vector<int> iv1 = {0, 1, 2, 3, 4};
    vector<int>::const_iterator b1 = iv1.cbegin(), e1 = iv1.cend();
    cout << "iv1 : ";
    print(iv1) << endl;
    cout << "[b1, e1): ";
    print(b1, e1) << endl;

    vector<int> iv2 = {5, 6, 7, 8, 9};
    vector<int>::const_iterator b2 = iv2.cbegin(), e2 = iv2.cend();
    cout << "iv2 : ";
    print(iv2) << endl;
    cout << "[b2, e2): ";
    print(b2, e2) << endl;

    cout << " After swap\n";
    swap(iv1, iv2);

    cout << "iv1 : ";
    print(iv1) << endl;
    cout << "[b1, e1): ";
    print(b1, e1) << endl;
    cout << "iv2 : ";
    print(iv2) << endl;
    cout << "[b2, e2): ";
    print(b2, e2) << endl;

    return 0;
}

ostream &print(vector<int> v)
{
    for (const auto &i : v)
        cout << i << " ";
    return cout;
}

ostream &print(vector<int>::const_iterator b,
                 vector<int>::const_iterator e)
{
    while (b != e)
        cout << *b++ << " ";
    return cout;
}
