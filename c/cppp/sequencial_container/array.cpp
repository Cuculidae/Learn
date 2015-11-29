/**
 * array.cpp
 * C++11 array sequential container.
 * Compilation: g++ -o array array.cpp -std=c++11
 * Created: 2015-09-14
 */

#include <iostream>
#include <array>

using std::cout;
using std::endl;
using std::array;

/*
 * The library array type has fixed size. It does not support operations that
 * would change the size of the array, such as insert, erase, resize.
 *
 * The size of a library array is part of its type. To use an array type we must
 * specify both the element type and the size. array does not support
 * contrustors that specify the size implicitly or explicitly.
 *
 * Unlike the other containers, a default-constructed array is not empty: It has
 * as many elements as its size.
 *
 * The library array types does allow assignment.
 *
 * Because the size of the right-hand operand might differ from the size of the
 * lefthand operand, the array type does not support assign and it does not
 * allow assignment from a braced list of values.
 */

void print(array<int, 10> a)
{
    for (const auto &i : a)
        cout << i << " ";
    cout << endl;
}

int main(void)
{
    array<int, 10> ia1;     // ten default initialized ints
    print(ia1);
    array<int, 10> ia2 = {0,1,2,3,4,5,6,7,8,9}; // list initialization
    print(ia2);
    array<int, 10> ia3 = {42};  // ia3[0] is 42; remaining elements are 0
    print(ia3);

    array<int, 10> digits = {0,1,2,3,4,5,6,7,8,9};
    print(digits);
    array<int, 10> copy = digits;   // so long as array types match
    print(copy);

    return 0;
}
