#ifndef MEMORY_HPP
#define MEMORY_HPP
#
#

template <typename T> class shared_ptr;
template <typename T> class unique_ptr {
public:
private:
};

template <typename T> class shared_ptr {
public:
    shared_ptr(T *q): p(q), cnt(0) { }
    template <typename D> shared_ptr(T *q, D d);
    template <typename D> reset(T *q, D d);
    T* get() { return p; }
    std::size_t use_count() { return cnt; }
    ~shared_ptr();

private:
    T *p;
    std::size_t cnt;
};


#endif
