/*
 * type_member.cpp
 * type names in class definition is special.
 * Created: 2015-09-12
 */

/*
 * In a class, if a member uses a name from an outer scope and that name is a
 * type, then the class may not subsequently redefine that name.
 *
 * Although it is an error to redefine a type name, compilers are not required
 * to diagnose this error. Some compilers will quietly accept such code, even
 * though the program is in error.
 *
 * Definitions of type names usually should appear at the beginning of a class.
 * That way any member that uses that type will be seen after the type name has
 * already been defined.
 */

typedef double Money;
class Accout
{
    public:
        Money balance() { return bal; } // uses Money from the outer scope
    private:
        typedef double Money;   // error: cannot redefine name
        Money bal;
};
