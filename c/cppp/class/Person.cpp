#include "Person.hpp"

using std::string;
using std::ostream;
using std::istream;

inline
Person::Person() = default;

inline
Person::Person(const string &n, const string &a):
    name(n), addr(a) { }

inline
string Person::getName() const
    { return name;  }

inline
string Person::getAddress() const
    { return addr;  }

istream &read(istream &is, Person &p)
{
    getline(is, p.name);
    getline(is, p.addr);
    return is;
}

ostream &print(ostream &os, const Person &p)
{
    os << p.name << "; " << p.addr;
    return os;
}
