#ifndef COMPARE_HPP
#define COMPARE_HPP
#
#include <functional>

/*
 * A function template is a formula form which we can generate type-specific
 * versions of that function.
 *
 * In a template definition, the template parameter list cannot be empty.
 * Template parameters represent types or values used in the definition of a
 * class or function.
 *
 * When we call a function template, the compiler (ordinarily) uses the
 * arguments of the call to deduce the template argument(s) for us. The compiler
 * uses the deduced template argument(s) to instantiate a specific version of
 * the function for us.
 *
 * Each type parameter must be preceded by the keyword class or typename. These
 * keywords have the same meaning and can be used interchangeably inside a
 * template parameter list. It may seem more intuitive to use the keyword
 * typename rather than class to designate a template type parameter, because we
 * can use built-in (nonclass) types as a template argument.
 *
 * In addition to defining type parameters, we can define templates that take
 * nontype parameters. A nontype parameter represents a value rather than a
 * type. Nontype parameters are specified by using a specific type name instead
 * of the class or typename keyword. When the template is instantiated, nontype
 * parameters are replaced with a value supplied by the user or deduced by the
 * compiler. These values must be constant expressions, which allows the
 * compiler to instantiate template during compile time. A nontype parameter may
 * be an integral type, or a pointer or (lvalue) reference to an object or to a
 * function type. An argument bound to a nontype integral parameter must be a
 * constant expression. Arguments bound to a pointer or reference nontype
 * parameter must have static lifetime.
 *
 * A function template can be declared inline or constexpr in the same ways as
 * nontemplate functions. The inline or constexpr specifier follows the template
 * parameter list and precedes the return type.
 *
 * Template programs should try to minimize the number of requirements placed on
 * the argument type.
 *
 * When the compiler sees the definition of a template, it does not generate
 * code. It generates code only when we instantiate a specific instance of the
 * template.
 * Definitions of function templates and member functions of class templates are
 * ordinarily put into header files.
 */

// versions of compare that will be correct even if used on pointers
template <typename T> int compare(const T &v1, const T &v2)
{
    if (std::less<T>()(v1, v2)) return -1;
    if (std::less<T>()(v2, v1)) return 1;
    return 0;
}

template <unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M])
{
    return strcmp(p1, p2);
}

#endif
