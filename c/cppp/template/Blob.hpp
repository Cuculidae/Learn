#ifndef BLOB_HPP
#define BLOB_HPP
#
#include <vector>
#include <string>
#include <memory>
#include <exception>

/*
 * A class template is a blueprint for generating classes. Class templates
 * differ from function templates in that the compiler cannot deduce the
 * template parameter type(s) for a class template.
 *
 * Each instantiation of a class template constitutes an independent class.
 *
 * A member function defined outside the class template body starts with the
 * keyword template followed by the class's template parameter list. As usual,
 * we must say to which class the member belongs. The name of a class generated
 * from a template includes its template arguments.
 *
 * By default, a member function of a class template is instantiated only if the
 * program uses that member function. This fact lets us instantiate a class with
 * a type that may not meet the requirements for some of the template's
 * operations.
 *
 * There is one exception to the rule that must supply template arguments when
 * we use a class template type. Inside the scope of the class template itself,
 * we may use the name of the template without arguments. When we are inside the
 * scope of a class template, the compiler treats references to the template
 * itself as if we had supplied template arguments matching the template's own
 * parameters.
 *
 * When a class contains a friend declaration, the class and the friend can
 * independently be templates or not. A class template that has a nontemplate
 * friend grants that friend access to all the instantiations of the template.
 * When the friend is itself a template, the class granting friendship  controls
 * whether friendship includes all instantiations of the template or only
 * specific instantiations.
 * In order to refer to a specific instantiation of a template (class or
 * function) we must first declare the template itself.
 *
 * The most common form of friendship from a class template to another template
 * (class or function) establishes friendship between corresponding
 * instantiations of the class and its friend. 
 * To allow all instantiations as friends, the friend declaration must use
 * template parameters that is differenct from those used by the class itself.
 *
 * In C++11, we can make a template type parameter a friend:
 *  template <typename Type> class Bar {
 *  friend Type;    // grants access to the type used to instantiate Bar
 *  };
 * It is worth noting that even though a friend ordinarily must be a class or
 * function, it is okay for Bar to be instantiated with a built-in type.
 *
 * Because a template is not a type, we cannot define a typedef that refers to a
 * template. However in C++11, we can define a type alias for a class template:
 *  template<typename T> using twin = pair<T, T>;
 *  twin<string> authors;   // authors is a pair<string, string>
 * When we define a template type alias, we can fix one or more of the template
 * parameters.
 *
 * We define static members as a template similarly to how we define the member
 * functions of that template. Each instantiation of a class template has its
 * own instance of the static members.
 * Like any other member function, a static member function is instantiated only
 * if it is used in a program.
 *
 * A class -- either an ordinary class or a class template -- may have a member
 * function that is itself a template. Such members are referred to as member
 * templates. Member templates may not be virtual.
 * When we define a member template of a class template, both the class and the
 * member have their own, independent, template parameters.
 * When we define a member template outside the body of a class template, we 
 * must provide the template parameter list for the class template and for the
 * function template. The parameter list for the class template comes first,
 * followed by the member's own template parameter list.
 */

// forward declarations needed for friend declarations in Blob
template <typename> class BlobPtr;
template <typename> class Blob;     // needed for parameters in operator==
template <typename T>
    bool operator==(const Blob<T>&, const Blob<T>&);
template <typename T>
    bool operator!=(const Blob<T>&, const Blob<T>&);

template <typename T> class Blob {
    // each instantiation of Blob grants access to the version of
    // BlobPtr and the equality operator instantiated with the same type
    friend class BlobPtr<T>;
    friend bool operator==<T> (const Blob<T>&, const Blob<T>&);
    friend bool operator==<T> (const Blob<T>&, const Blob<T>&);
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    Blob();
    Blob(std::initializer_list<T> il);
    template<typename It> Blob(It b, It e);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T &t) { data->push_back(t); }
    void push_bakc(T &&t) { data->push_back(std::move(t)); }
    void pop_back();
    T& back();
    const T& back() const;
    T& operator[](size_type i);
    const T& operator[](size_type i) const;

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const;
};

template <typename T>
Blob<T>::Blob(): data(std::make_shared<std::vector<T>>()) { }

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il):
    data(std::make_shared<std::vector<T>>(il)) { }

/* take two iterators and copy the range */
template <typename T>   // type parameter for the class
template <typename It>  // type parameter for the constructor
Blob<T>::Blob(It b, It e):
    data(std::make_shared<std::vector<T>>(b,e)) { }

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
        throw new std::out_of_range(msg);
}

template <typename T>
void Blob<T>::pop_back()
{
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template <typename T>
T& Blob<T>::back()
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
const T& Blob<T>::back() const
{
    return (const_cast<Blob<T>*>(this))->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i)
{
    // if i is too big, check will throw, preventing access to a nonexistent
    // element
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
const T& Blob<T>::operator[](size_type i) const
{
    return (const_cast<Blob<T>*>(this))->operator[](i);
}

template <typename T> 
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return lhs.data == rhs.data;
}

template <typename T>
bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return !(lhs == rhs);
}

// BlobPtr throws an exception on attempts to access a nonexistent element
template <typename T> class BlobPtr {
public:
    BlobPtr(): curr(0) { }
    BlobPtr(Blob<T> &a, std::size_t sz = 0):
        wptr(a.data), curr(sz) { }
    T& operator*() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];  // (*p) is the vector to which this object points
    }
    // increment and decrement
    BlobPtr& operator++();  // prefix operators
    BlobPtr& operator--();

private:
    std::shared_ptr<std::vector<T>>
        check(std::size_t i, const std::string &msg) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

template <typename T>
std::shared_ptr<std::vector<T>>
BlobPtr<T>::check(std::size_t i, const std::string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound BlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
    check(curr, "increment past end of BlobPtr");
    ++curr;
    return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
    // if curr is 0, de
    --curr;
    check(curr, "decrement past begin of BlobPtr");
    return *this;
}


#endif
