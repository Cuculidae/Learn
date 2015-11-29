#ifndef ACCOUNT_HPP
#
#define ACCOUNT_HPP
#
#include <string>

/*
 * The static keyword is used only on the declaration inside the class body.
 *
 * Because static data members are not part of the individual objects of the
 * class type, they are not defined when create objects of the class. As a
 * result, they are not initialized by the class' constructors. We must define
 * and initialize each static data member outside the class body.
 *
 * Ordinarily, class static members may not be initialized in the class body.
 * However, we can provide in-class initializers for static members that have
 * const integral type and must do so for static members that are constexprs of
 * literal type. If an initializer is provided inside the class, the members 
 * definition must not specify an initial value. If we use the member in a
 * context in which the value cannot be substituted, then there must be a
 * definition for that member.
 *
 * Similarly, static member functions are not bound to any object; they do not
 * have a this pointer. As a result, static member functions may not be declared
 * as const, and we may not refer to this in the body of a static member. This
 * restriction applies both to explicit uses of this and to implicit uses of
 * this by calling a nonstatic member.
 *
 * A static member can have the same type as the class type of which it is a
 * member. We can use a static member as a default argument
 */

class Account
{
    public:
        void calculate() { amount += amount * interestRate; }
        static double rate() { return interestRate; }
        static void rate(double);

    private:
        std::string owner;
        double amount;
        static double interestRate;
        static double initRate();
        static constexpr int period = 30;   // period is constant expression
        double daily_tbl[period];
};

#endif
