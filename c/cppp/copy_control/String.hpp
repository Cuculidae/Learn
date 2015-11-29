#ifndef STRING_HPP
#define STRING_HPP
#
#include <memory>
#include <utility>

class String {
public:
    String(): elements(nullptr), first_free(nullptr), cap(nullptr) { }
    String(const char s[]);
    String(size_type n, char c);
    String(const String&);
    String& operator=(const String&);
    ~String();
    size_type size() { return first_free - elements; }
    size_type capacity() { return cap - elements; }
    void reserve(size_type n);
    void resize(size_type n);
    char *begin();
    char *end();

private:
    static std::allocator<char> alloc;
    void chk_n_copy();
    void reallocate();
    std::pair<char*, char*> alloc_n_copy
        (const char*, const char*);
    char *elements;     // pointer to first element 
    char *first_free;   // pointer to one past the 
    char *cap;          // pointer to 
};

#endif
