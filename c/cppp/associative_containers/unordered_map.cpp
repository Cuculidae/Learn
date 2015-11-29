/**
 * unordered_map.cpp
 * Compilation: g++ -o unordered_map unordered_map.cpp -std=c++11\
 * Created: 2015-09-20
 */

#include <iostream>
#include <unordered_map>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::unordered_map;
using std::string;

/*
 * Aside fromoperations that manage the hashing, the unordered containers
 * provide the same operations (find, insert, and so on) as the ordered
 * containers.
 *
 * The unordered containers are organized as a collection of buckets, each of
 * which holds zero ormore elements. These containers use a hash function tomap
 * elements to buckets.
 *
 * Unordered Container Management Operations:
 * Bucket Interface 
 * c.bucket.count()     Number of buckets in use.
 * c.max_bucket_count() Largest number of buckets this container can hold.
 * c.bucket_size(n)     Number of elements in the nth bucket.
 * c.bucket(k)          Bucket in which elements with key k would be found.
 * Bucket Iteration
 * local_iterator         Iterator type that can access elements in a bucket.
 * const_local_iterator   const version of the bucket iterator.
 * c.begin(n), c.end(n)   Iterator to the first, one past the last element in bucket n.
 * c.cbegin(n), c.cend(n) Returns const_local_iterator.
 * Hash Policy
 * c.load_factor()      Average number of elements per bucket. Returns float.
 * c.max_load_factor()  Average bucket size that c tries to maintain. c adds buckets 
 *                      to keep load_factor <= max_load_factor. Returns float.
 * c.rehash(n)          Reorganize storage so that bucket_count >= n and and
 *                      bucket_count > size/max_load_factor.
 * c.reserve(n)         Reorganize so that c can hold n elements without a rehash.
 *
 * By default, the unordered containers use the == operator on the key type to
 * compare elements. They also use an object of type hash<key_type> to generate
 * the hash code for each element. The library supplies versions of the hash
 * template for the built-in types, including pointers. It also defines hash for
 * some of the library types, including strings and the smart point types.
 *
 * However,we cannot directly define an unordered container that uses a our own
 * class types for its key type. Unlike the containers, we cannot use the hash
 * template directly. Instead, we must supply our own version of the hash
 * template.
 * If our class has its own == operator we can override just the hash function.
 */

int main(void)
{
    unordered_map<string, size_t> word_count;
    cout << "bucket_count: " << word_count.bucket_count() << endl;
    cout << "load_factor: " << word_count.load_factor() << endl;

    string word;
    while (cin >> word) {
        ++word_count[word];
    }
    for (const auto &w : word_count) {
        cout << w.first << " occurs " << w.second
             << ((w.second > 1) ? " times" : " time") << endl;
    }
    auto n = word_count.bucket_count();
    for (decltype(n) i = 0; i < n; ++i) {
        cout << i << ": ";
        for (auto beg = word_count.cbegin(i), end = word_count.cend(i);
             beg != end; ++beg) {
            cout << beg->first << ' ';
        }
        cout << endl;
    }

    cout << "bucket_count: " << word_count.bucket_count() << endl;
    cout << "max_bucket_count: " << word_count.max_bucket_count() << endl;
    cout << "load_factor: " << word_count.load_factor() << endl;
    cout << "max_load_factor: " << word_count.max_load_factor() << endl;

    return 0;
}
