/**
 * friend.cpp
 * Compilation: g++ -c friend.cpp
 * Created: 2015-10-06
 */


/*
 * Friendship is not inherited, ach class controls access to its own members.
 *
 */

class Base {
    // added friend delcaration; other members as before
    friend class Pal;   // Pal has no access to classes derived from Base
protected:
    int prot_mem;   // protected member
};
class Sneaky : public Base {
    friend void clobber(Sneaky&);   // can access Sneaky::prot_mem
    friend void clobber(Base&);     // can't access Base::prot_mem
    int j;                          // j is private by default
};
class Pal {
public:
    int f(Base b) { return b.prot_mem; }    // ok: Pal is a friend of Base
    int f2(Sneaky s) { returns s.j; }       // error: Pal not friend of Sneaky
    // access to a base class is controlled by the base class, even inside a
    // derived class
    int f3(Sneaky s) { return s.prot_mem; } // ok: Pal is a friend
};

