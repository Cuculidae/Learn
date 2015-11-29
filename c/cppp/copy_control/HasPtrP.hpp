/* pointerlike HasPtr */

#ifndef HASPTRP_HPP
#define HASPTRP_HPP
#
#include <string>

/*
 *
 */

class HasPtrP {
    public:
        // constructor allocates a new string and a new counter, which it sets
        // to 1
        HasPtrP(const std::string &s = std::string()):
            ps(new std::string(s)), i(0), use(new std::size_t(1)) { }
        // copy constructor copies all three data members and increments the
        // counter
        HasPtrP(const HasPtrP &p):
            ps(p.ps), i(p.i), use(p.use) { ++*use; }
        HasPtrP& operator=(HasPtrP&);
        ~HasPtrP();

    private:
        std::string *ps;
        int i;
        std::size_t *use;   // member to keep track how many objects share *ps
};

#endif
