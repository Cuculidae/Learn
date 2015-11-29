/**
 * tuple.cpp
 * C++11 tuple template.
 * Compilation: g++ -o tuple tuple.cpp -std=c++11
 * Created: 2015-10-15
 */

#include <iostream>
#include <string>
#include <tuple>

using std::cout;
using std::endl;
using std::string;
using std::tuple;
using std::make_tuple;
using std::get;

/*
 * The tuple type, along with its companion types and functions, are defined
 * in the tuple header.     (since C++11)
 *
 * A tuple can have any number of members.
 *
 *          Operations on tuples
 * *****************************************************************************
 * tuple<T1, T2, ..., Tn> t;
 *      t is a tuple with as many members as there are types T1...Tn. The
 *      members are value initialized.
 * tuple<T1, T2, ..., Tn> t(v1, v2, ..., vn);
 *      t is a tuple with types T1...Tn in which each member is initialized from
 *      the corresponding initializer, vi. This constructor is explicit.
 * make_tuple(v1, v2, ..., vn)
 *      Returns a tuple initialized from the given intializers. The type of the
 *      tuple is inferred from the types of the initializers.
 * t1 == t2 Two tuples are equal if the have the same number of members and if
 * t1 != t2 each pair of members are equal. Uses each member's underlying ==
 *          operator. Once a member is found to be unequal, subsequent members
 *          are not tested.
 * t1 relop t2  Relational operations on tuples using dictionary ordering. The
 *              tuples must have the same number of members. Members of t1 are
 *              compared with the corresponding members from t2 using the <
 *              operator
 * get<i>(t)    Returns a reference to the ith data member of t; if t is an
 *              lvalue, the result is an lvalue reference; otherwise, it is an
 *              rvalue reference. All members of a tuple are public.
 * tuple_size<tupleType>::value
 *      A class template that can be instantiated by a tuple type and has a
 *      public constexpr static data member named value of type size_t that is
 *      number of members in the specified tuple type.
 * tuple_element<i, tupleType>::type
 *      A class template that can be instantiated by an integral constant and a
 *      tuple type and has a public member named type that is the type of the
 *      specified members in the specified tuple type.
 * *****************************************************************************
 *
 * Because tuple defines the < and == operators, we can pass sequences of tuples
 * to the algorithms and can use a tuple as key type in an ordered container.
 */

int main()
{
    // tuple that represents a bookstore transaction: ISBN, count, price per book
    auto item = make_tuple("0-999-78345", 3, 20.00);    // tuple<const char*, int, double>
    auto book = get<0>(item);       // returns the first member of item
    auto cnt = get<1>(item);        // returns the second member of item
    auto price = get<2>(item)/cnt;  // returns the last member of item

    cout << "book: " << book << " "
        << cnt << " " << price << endl;

    tuple<string, string> duo("1", "2");
    tuple<size_t, size_t> twoD(1, 2);
  //bool b = (duo == twoD); // error: can't compare a size_t and a string
    tuple<size_t, size_t, size_t> threeD(1, 2, 3);
  //b = (twoD < threeD);    // error: differing number of members
    tuple<size_t, size_t> origin(0, 0);
    cout << "origin < twoD: " << std::boolalpha
        << (origin < twoD) << std::noboolalpha << endl;

    return 0;
}
