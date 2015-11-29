#ifndef STRBLOB_HPP
#define STRBLOB_HPP
#
#include <memory>
#include <vector>
#include <string>
#include <initializer_list>
#include <exception>

class StrBlobPtr;
class StrBlob
{
    friend class StrBlobPtr;
    public:
        typedef std::vector<std::string>::size_type size_type;
        typedef std::vector<std::string>::iterator iterator;
        typedef std::vector<std::string>::const_iterator const_iterator;
        typedef std::vector<std::string>::reverse_iterator reverse_iterator;
        typedef std::vector<std::string>::const_reverse_iterator const_reverse_iterator;
        StrBlob();
        StrBlob(std::initializer_list<std::string> il);
        size_type size() const;
        bool empty() const;
        // add and remove elements
        void push_back(const std::string &t);
        void pop_back();
        // element access
        std::string &front();
        const std::string &front() const;
        std::string &back();
        const std::string &back() const;
        // iterator
        iterator begin();
        iterator end();
        const_iterator cbegin() const;
        const_iterator cend() const;
        reverse_iterator rbegin();
        reverse_iterator rend();
        const_reverse_iterator crbegin() const;
        const_reverse_iterator crend() const;

    private:
        std::shared_ptr<std::vector<std::string>> data;
        // throw msg if data[i] is empty
        void check(size_type i, const std::string &msg) const;
};

inline
StrBlob::StrBlob():
    data(std::make_shared<std::vector<std::string>>()) { }

inline
StrBlob::StrBlob(std::initializer_list<std::string> il):
    data(std::make_shared<std::vector<std::string>>(il)) { }
inline
StrBlob::size_type StrBlob::size() const
{
    return data->size();
}

inline
bool StrBlob::empty() const
{
    return data->empty();
}

inline
void StrBlob::push_back(const std::string &t)
{
    data->push_back(t);
}

inline
StrBlob::iterator StrBlob::begin()
{
    return data->begin();
}

inline
StrBlob::iterator StrBlob::end()
{
    return data->end();
}

inline
StrBlob::const_iterator StrBlob::cbegin() const
{
    return data->cbegin();
}

inline
StrBlob::const_iterator StrBlob::cend() const
{
    return data->cend();
}

inline
StrBlob::reverse_iterator StrBlob::rbegin()
{
    return data->rbegin();
}

inline
StrBlob::reverse_iterator StrBlob::rend()
{
    return data->rend();
}

inline
StrBlob::const_reverse_iterator StrBlob::crbegin() const
{
    return data->crbegin();
}

inline
StrBlob::const_reverse_iterator StrBlob::crend() const
{
    return data->crend();
}

#endif
