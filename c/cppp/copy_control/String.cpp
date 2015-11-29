#include "String.hpp"

using std::allocator;
using std::pair;

allocator<char> String::alloc;

String::String(const char []s)
{
    const char *p = s;
    while (*p) ++p;
    auto newdata = alloc_n_copy(s, p);
    elements = newdata.first;
    first_free = cap = newdata.second;
}

String::String(size_type n, char c)
{
    if (n) {
        auto newdata = alloc.allocate(n);
        elements = newdata;
        for (size_type i = 0; i < n; ++i)
            alloc.construct(newdata++, c);
        first_free = cap = newdata;
    }
}

String::String(const String &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata_second;
}

String& String::operator=(const String &rhs)
{
    auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = newdata.first;
    first_free = cap = newdata.second;
    return *this;
}

void String::push_back(char c)
{
    chk_n_copy();
    *first_free++ = c;
}

void String::reserve(size_type n)
{
    if (n > size()) {
        auto newdata = alloc.allocate(n);
        auto dest = newdata;
        auto elem = elements;
        for (size_type i = 0; i < size(); ++i)
            alloc.construct(dest++, *elem++);
        free();
        elements = newdata;
        first_free = dest;
        cap = elements + n;
    }
}

void String::realloate()
{
    if (elements) {
        auto newcapacity = size() ? 2 * size() : 1;
        auto newdata = alloc.allocate(newcapacity);
        auto dest = newdata;
        auto elem = elements;
        for (size_type i = 0; i < size(); ++i)
            alloc.construct(dest++, *elem++);
        free();
        elements = newdata;
        first_free = dest;
        cap = elements + newcapacity;
    }
}

pair<char*, char*>
alloc_n_copy(char *b, char *e)
{
    auto data = alloc.allocate(e - b);
    return {data, unitialized_copy(b, e, data)};
}

void free()
{
    while (first_free != elements) 
        alloc.destroy(--first_free);
    alloc.deallocate(elements, cap-elements);
}
