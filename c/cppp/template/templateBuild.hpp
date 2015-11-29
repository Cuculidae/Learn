#ifndef TEMPLATEBUILD_HPP
#define TEMPLATEBUILD_HPP
#
#include "Blob.hpp"
#include "compare.hpp"
#include <string>

/*
 * C++11 explicit instantiation has the form:
 *  extern template declaration;    // instantiation declaration
 *  template declaration;           // instantiation definition
 * where declaration is a class or function declaration in which all the
 * template parameters are replaced by the template arguments.
 *
 * When the compiler sees an extern template declaration, it will not generate
 * code for that instantiation in that file. Declaring an instantiation as
 * extern is a promise that there will be a nonextern use of that instantiation
 * elsewhere in the program. Theremay be several extern declarations for a given
 * instantiation but there must be exactly one definition for that
 * instantiation.
 *
 * Because the compiler automatically instantiates a template when we use it,
 * the extern declaration must appear before any code that uses that
 * instantiation.
 *
 * An instantiation definition for a class template instantiates all the members
 * of that template including inline member functions. Consequently, we can use
 * explicit instantiation only for types that can be used with all the members
 * of that template.
 */

// these template types must be instantiated elsewhere int the program
extern template class Blob<std::string>;
extern template int compare(const int&, const int&);

#endif
