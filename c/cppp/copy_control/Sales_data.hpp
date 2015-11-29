#ifndef SALES_DATA_HPP
#define SALES_DATA_HPP

#include <string>
#include <iostream>

/*
 * A constructor is the copy construtor if its first parameter is a reference to
 * the class type and any additional parameters have default values. The copy
 * constructor is used implicitly in several circumstances. Hence the copy
 * constructor usually should not be explicit.
 * If we do not define a copy constructor for a class, the compiler synthesizes
 * one for us. Unlike the synthesized default constructor, a copy constructor is
 * synthesized even if we define other constructors. The synthesized copy
 * constructor memberwise copies the members of its arguments into the object
 * being created.
 * Copy initialization happens not only when we define variables using an =, but
 * also when we
 *  # pass an object as argument to a parameter of nonreference type
 *  # returns an object from a function that has a nonreference return type
 *  # brace initialize the elements in an array or the members of an aggregate
 *    class.
 *
 * The compiler generates a synthesized copy-assignment operator for a class if
 * it does not defines its own. It assigns each nonstatic member of the
 * right-hand operand object to the corresponding member of the left-hand object
 * using the copy-assingment operator for the type of that member. The
 * synthesized copy-assignment operator returns a reference to its left-hand
 * object.
 *
 * The destructor is a member function with the name of the class prefixed by a
 * tilde(~). It has no return value and takes no parameters. Because it takes no
 * parameters, it cannot be overloaded. There is always only one destructor for
 * a given class. The destructor operates inversely to the constructor. In a
 * destructor, the function body is executed first and then the members are
 * destroyed. Members are destroyed in reverse order from the order in which
 * they were initialized.
 * The destructor is used automatically whenever an object of its type is
 * destroyed.
 *  # variables are destroyed when they go out of scope
 *  # Members of an object are destroyed when the object of which they are a
 *    part is destroyed
 *  # Dynamically allocated objects are destroyed when the delete operator is
 *    applied to a pointer to the object
 *  # temporary objects are destroyed at the end of the full expression in which
 *    the temporary was created
 * The destructor is not run when a reference or a pointer to an object goes out
 * of scope.
 * The compiler defines a synthesized destructor for any class that does not
 * define its own destructor. The synthesized destructor has an empty function
 * body.
 *
 * If a class needs a destructor, it almost surely also needs the copy
 * assignment operator and a copy constructor.
 *
 * In C++11, we can explicitly ask the compiler to generate the synthesized
 * versions of the copy-control members by defining them as =default. We can use
 * =default only on member functions that have a synthesized version.
 *
 * Unlike =default, =delete must appear on the first declaration of a deleted
 * function. We can specify =delete on any function.
 *
 * We cannot define variables or temporaries of a class that has a member whose
 * type has a deleted destructor. But we can dynamically allocate objects with a
 * deleted destructor.However, we cannot free them.
 *
 * The copy-control members are synthesized as deleted when it is impossible to
 * copy, assign, or destroy a member of the class.
 */

class Sales_data {
friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::ostream &print(std::ostream&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data&);
public:
	// constructors
	Sales_data() = default;
	Sales_data(const std::string &s): bookNo(s) { }
	Sales_data(const std::string &s, unsigned n, double p):
	           bookNo(s), units_sold(n), revenue(p*n) { }
	Sales_data(std::istream &);
    Sales_data(const Sales_data&);
    Sales_data& operator=(const Sales_data&);
    // no work to do other than destroying the members, which happens
    // automatically
    ~Sales_data() { }

	// operations on Sales_data objects
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

// equivalent to the copy constructor that would be synthesized for Salse_data
Sales_data::Sales_data(const Sales_data &orig):
    bookNo(orig.bookNo),        // uses the string copy constructor
    units_sold(orig.units_sold),// copies orig.units_sold
    revenue(orig.revenue)       // copies orig.revenue
    { }                         // empty body

// equivelant to the synthesized copy-assignment operator
Sales_data& Sales_data::operator=(const Sales_data &rhs)
{
    bookNo = rhs.bookNo;        // calls the string::operator==
    units_sold = rhs.units_sold;// uses the built-in int assignment
    revenue = rhs.revenue;      // uses the built-in double assignment
    return *this;               // returns a reference to this object
}

inline
double Sales_data::avg_price() const
{
    return (units_sold ? revenue/units_sold : 0);
}

// nonmember Sales_data interface functions
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

// used in future chapters
inline 
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}

#endif
