/**
 * templateBuild.cpp
 * Compilation: g++ -c templateBuild.cpp -std=c++11
 * Created: 2015-09-27
 */

#include "templateBuild.hpp"

// instantiation file must provide a (nonextern) definition for every
// type and function that other file declare as extern
template int compare(const int&, const int&);
template class Blob<std::string>;   // instantiates all members of the class template
