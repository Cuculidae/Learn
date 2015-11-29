/**
 * conversion.cpp
 * Conversions from class type.
 * Compilation: g++ -o conversion conversion.cpp -std=c++11
 * Created: 2015-09-24
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;

/*
 * A conversion operator is a special kind of member function that converts a
 * value of a class type to a value of some other type. A conversion function
 * typically has the general form
 *      operator type() const;
 * where type represents a type.
 *
 * Conversion operators can be defined for any type (other than type) that can
 * be a function return type. Conversions to an array of a function type are not
 * permitted. Conversions to pointer types -- both data and function pointer --
 * and to reference types are allowed.
 *
 * A conversion function must be a member function, may not specify a return
 * type, and must have an empty parameter list. The function usually should be
 * const. Although a conversion function does not specify a return type, each
 * conversion function must return a value of its corresponding type.
 *
 * Although the compiler will apply only one user-defined conversion at a time,
 * an implicit user-defined conversion can be preceded or followed by a standard
 * built-in conversion.
 *
 * C++11 introduced explicit conversion operators. The compiler won't
 * (generally) use an explicit conversion operator for implicit conversions. 
 * If the conversion is explicit, we can still do the conversion. However with
 * one exception, we must do so explicitly through a cast.
 * The exception is that the compiler will apply an explicit conversion to an
 * expression used as a condition. That is, an explicit conversion will be used
 * implicitly to convert an expression used as
 *  # The condition of an if, while, or do statement
 *  # The condition expression in a for statement header
 *  # An operand to the logical NOT(!), OR(||), or AND(&&) operators
 *  # The condition expression in the conditional(?:) operator
 *
 * Conversion to bool is usually intended for use in conditions. As a result,
 * operator bool ordinary should be defined as explicit.
 */

class SmallInt {
    public:
        SmallInt(int i = 0): val(i) {
            if (i < 0 || i > 255)
                throw std::out_of_range("Bad SmallInt value");
        }
        operator int() const { return val; }
    private:
        std::size_t val;
};

int main(void)
{
    SmallInt si;
    si = 4;     // implicitly converts 4 to SmallInt then calls SmallInt::operator=
    si + 3;     // implicitly converts si to int followed by integer addition

    // the double argument is converted to int using the built-in conversion
    SmallInt si = 3.14;     // calls the SmallInt(int) constructor
    // the SmallInt conversion operator converts si to int:
    si + 3.14;  // that int is converted to double using the built-in conversion

    return 0;
}
