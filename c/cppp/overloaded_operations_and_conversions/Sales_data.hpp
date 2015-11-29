/*
 * An overloaded operator function has the same number of parameters as the
 * operator has operands. Except for the overloaded function-call operator,
 * operator(), an overloaded operator may not have defaut arguments. Wnen an
 * overloaded operator is a member function, this is bound to the left-hand
 * operand. Member operator functions have one less (explicit) parameter that
 * the number of operands.
 *
 * An operator function must either be a member of a class or have at least one
 * parameter of class type. This restriction means that we cannot change the
 * meaning of an operator when applied to operands of built-in type.
 *
 * We can overload most, but not all of the operators. We can overload only
 * existing operators and cannot invent new operator symbols. An overloaded
 * operator has the same precedence and associativity as the corresponding
 * built-in operator.
 *
 * Four symbols(+,-,*,&) serve as both unary and binary operators. Either or
 * both of these operators can be overloaded. The number of parameters
 * determines which operator is being defined.
 *
 * We can also call an overloaded operator function directly in the same way
 * that we call an ordinary function.
 *
 * Ordinarily, the comma, address-of, logical AND and logical OR operators
 * should not be overloaded.
 *
 * The following guidelines can be of help in deciding whether to make operator
 * a member or an ordinary nonmember function:
 *  # The assignment (=), subscript ([]), call(()), and member access arrow (->)
 *    operators must be defined as members.
 *  # The compound-assignment operators ordinarily ought to be members. However,
 *    unlike assignment, they are not required to be members.
 *  # Opeartors that change the state of their object or that are closely tied
 *    to their given type--such as increment, decrement, and dereference --
 *    usually should be members.
 *  # Symmetric operators -- those that might convert either operand, such as
 *    the arithmetic, equality, relational, and bitwise operators -- usually
 *    should be defined as ordinary nonmember functions.
 */ 

#ifndef SALES_DATA_HPP
#define SALES_DATA_HPP

#include <string>
#include <iostream>

class Sales_data {
friend Sales_data operator+(const Sales_data& lhs, const Sales_data &rhs);
friend std::ostream& operator<<(std::ostream& os, const Sales_data &item);
friend std::istream& operator>>(std::istream& is, Sales_data &item);
friend bool operator==(const Sales_data &lhs, const Sales_data &rhs);
friend bool operator!=(const Sales_data &lhs, const Sales_data &rhs);
public:
	// constructors
	Sales_data() = default;
	Sales_data(const std::string &s): bookNo(s) { }
	Sales_data(const std::string &s, unsigned n, double p):
	           bookNo(s), units_sold(n), revenue(p*n) { }
	Sales_data(std::istream &);

	// operations on Sales_data objects
	std::string isbn() const { return bookNo; }
    Sales_data& operator+=(const Sales_data&);
	double avg_price() const;
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

inline
double Sales_data::avg_price() const
{
    return (units_sold ? revenue/units_sold : 0);
}

// nonmember Sales_data interface functions
Sales_data operator+(const Sales_data& lhs, const Sales_data &rhs);
std::ostream& operator<<(std::ostream& os, const Sales_data &item);
std::istream& operator>>(std::istream& is, Sales_data &item);

// used in future chapters
inline 
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}
#endif
