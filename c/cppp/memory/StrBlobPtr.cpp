/**
 * StrBlobPtr.cpp
 * Companion pointer class for StrBlob class.
 * Compilation: g++ -c StrBlobPtr.cpp -std=c++11
 * Created: 2015-09-22
 */

#include "StrBlobPtr.hpp"

using std::shared_ptr;
using std::vector;
using std::string;
using std::runtime_error;
using std::out_of_range;

shared_ptr<vector<string>>
StrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock();     // is the vector still around
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret;     // otherwise, return a shared_ptr to the vector
}

string &StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];  // (*p) is the object to which this object points
}

// prefix: return a reference to the incremented object
StrBlobPtr &StrBlobPtr::incr()
{
    // if curr already points past the end of the container, can't increment it
    check(curr, "increment past end of StrBlobPtr");
    return *this;
}
