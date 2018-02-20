#ifndef REVERSE_H
#define REVERSE_H

#include "queriable.h"

template<typename T, template<typename T> class DS>
class Reverse: public Queriable<T> {
    size_t n;
    DS<T> ds; // the underlying data structure
    void doUpdate(size_t i, const T &x) {
        ds.update(n - i + 1, x);
    }
    T doQuery(size_t i) const {
        return ds.query(n - i + 1);
    }
public:
    ~Reverse() {}
    Reverse(size_t n, const T &init): n(n), ds(n, init) {}
};

#endif
