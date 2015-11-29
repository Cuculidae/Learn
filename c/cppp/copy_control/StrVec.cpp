#include "StrVec.hpp"

using std::string;
using std::allocator;
using std::uninitialized_copy;
using std::pair;
using std::initializer_list;
using std::make_move_iterator;

allocator<string> StrVec::alloc;

StrVec::StrVec(const StrVec &s)
{
    // call alloc_n_copy to allocate exactly as many elements as in s
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::StrVec(StrVec &&s) noexcept // move won't throw any exceptions
    // member initializers take over the resources in s
    : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    // leave s in a state in which it is safe to run the destructor
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec::StrVec(const initializer_list<string> &il)
{
    auto newdata = alloc.allocate(il.size());
    elements = newdata;
    first_free = cap = uninitialized_copy(il.begin(), il.end(), newdata);
}

StrVec& StrVec::operator=(const StrVec &rhs)
{
    // call alloc_n_copy to allocate exactly as many elements as in rhs
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec& StrVec::operator=(StrVec &&rhs) noexcept
{
    // direct for self-assignment
    if (this != &rhs) {
        free();             // free existing elements
        elements = rhs.elements;    // take over resources from rhs
        first_free = rhs.first_free;//
        cap = rhs.cap;              //
        // leave rhs in a destructible state
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

StrVec::~StrVec() { free(); }

void StrVec::push_back(const string &s)
{
    chk_n_alloc();  // ensure that there is room for another element
    // construct a copy of s in the element to which first_free points
    alloc.construct(first_free++, s);
}

void StrVec::push_back(string &&s)
{
    chk_n_alloc();  // reallocates the StrVec if necessary
    alloc.construct(first_free++, std::move(s));
}

void StrVec::reserve(std::size_t n)
{
    if (capacity() < n)
    {
        auto first = alloc.allocate(n);
        auto last = uninitialized_copy(make_move_iterator(elements), 
                                       make_move_iterator(first_free),
                                       first);
        free();
        elements = first;
        first_free = last;
        cap = elements + n;
    }
}

void StrVec::resize(std::size_t n, string s)
{
    if (n <= capacity()) {
        auto p = elements + n;
        if (n <= size()) {
            while (first_free != p)
                alloc.destroy(--first_free);
        } else {
            while (first_free != p)
                alloc.construct(first_free++);
        }
    } else {
        reserve(n);
        while (first_free != cap)
            alloc.construct(first_free++, s);
    }
}

void StrVec::reallocate()
{
    // we'll allocate space for twice as many elements as the current size
    auto newcapacity = size() ? 2 * size() : 1;
    // allocate new memory
    auto first = alloc.allocate(newcapacity);
    // move the elements
    auto last = uninitialized_copy(make_move_iterator(begin()),
                                   make_move_iterator(end()),
                                   first);
    free();     // free the old space once we've moved the elements
    // update our data structure to point to the new elements
    elements = first;
    first_free = last;
    cap = elements + newcapacity;
}

pair<string*, string*>
StrVec::alloc_n_copy(const string *b, const string *e)
{
    // allocate space to hold as many elements as are in the range
    auto data = alloc.allocate(e - b);
    // initialize and return a pair constructed from data and
    // the value returned by unitialized_copy
    return {data, uninitialized_copy(b, e, data) };
}

void StrVec::free()
{
    // may not pass deallocate a 0 pointer; if element is 0, there's no work to do
    if (elements) {
        // destroy the old elements in reverse order
        for (auto p = first_free; p != elements; /* empty */)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}
