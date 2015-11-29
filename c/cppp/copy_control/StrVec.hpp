#ifndef STRVEC_HPP
#define STRVEC_HPP
#
#include <string>
#include <memory>
#include <utility>
#include <iterator>
#include <initializer_list>

/*
 * The move constructor has an initial parameter that is a rvalue reference to
 * the class type, any additional parameters must all have default arguments.
 *
 * We specify noexcept on a function after its parameter list. In a constructor,
 * noexcept appears between the parameter list and the : that begins the
 * constructor initializer list. We must specify noexcept on both the
 * declaration in the class header and on the definition if that definition
 * appears outside the class.
 *
 * Move constructors and move assignment operators that cannot throw exceptions
 * should be marked as noexcept.
 *
 * After move operation, the "moved-from" object must remain a valid,
 * destructible object but users may make no assumptions about its value.
 * 
 * The compiler synthesizes the move constructor and move assignment only if a
 * class does not define any of its own copy-control members and only if all the
 * data members can be moved constructed and move assigned respectively.
 */

class StrVec {
public:
    StrVec():   // the allocator member is default initialized
        elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(const StrVec&);              // copy constructor
    StrVec(StrVec&&) noexcept;          // move constructor
    StrVec(const std::initializer_list<std::string>&);
    StrVec& operator=(const StrVec&);   // copy assignment operator
    StrVec& operator=(StrVec&&) noexcept;// move assignment operator
    ~StrVec();                          // destructor
    void push_back(const std::string&); // copy the element
    void push_back(std::string&&);      // 
    std::size_t size() const { return first_free - elements; }
    std::size_t capacity() const { return cap - elements; }
    void reserve(std::size_t);
    void resize(std::size_t, std::string = "");
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }

private:
    static std::allocator<std::string> alloc;   // allocates the elements
    void chk_n_alloc()  // used by functions that add elements to a StrVec
        { if (size() == capacity()) reallocate(); }
    // utilities used by the copy constructor, assignment operator, and destructor
    std::pair<std::string*, std::string*> alloc_n_copy
        (const std::string*, const std::string*);
    void free();            // destroy the elements and free the space
    void reallocate();      // get more space and copy the existing elements
    std::string *elements;  // pointer to the first element in the array
    std::string *first_free;// pointer to the first free element in the array
    std::string *cap;       // pointer to one past the end of the array
};

#endif
