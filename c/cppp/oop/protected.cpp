/**
 * protected.cpp
 * protected access specifier.
 * Compilation: g++ -c protected.cpp (won't compiled)
 * Created: 2015-10-07
 */

/*
 * Each class controls access to its own members.
 *
 * # Like private, proteceted members are inaccessible to users of the class.
 * # Like public, protected members are accessible to members and friends of
 *   classes derived from this class.
 * # A derived class member or friend may access the protected members of the
 *   base class only through a derived object. The derived class no special
 *   access to the protected members of base-class objects.
 *
 * Members and friends of a derived class can access the protected members only
 * in base-class objects that are embedded inside the derived type object; they
 * have no special access to ordinary objects of the base type.
 */

class Base {
protected:
    int prot_mem;   // protected member
};
class Sneaky : public Base {
    friend void clobber(Sneaky&);   // can access Sneaky::prot_mem
    friend void clobber(Base&);     // can't access Base::prot_mem
    int j;                          // j is private by default
};
// ok: clobber can access the private and procted members in Sneaky objects
void clobber(Sneaky &s) { s.j = s.prot_mem = 0; }
// error: clobber can't access the protected members in Base
void clobber(Base &b) { b.prot_mem = 0; }
