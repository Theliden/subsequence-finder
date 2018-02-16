#ifndef QUERIABLE_H
#define QUERIABLE_H

#include <cstddef>

template<typename T> class Queriable {
    virtual void doUpdate(size_t i, const T &x) = 0;
    virtual T doQuery(size_t i) const = 0;
public:
    virtual ~Queriable() {}
    void update(size_t i, const T &x) { doUpdate(i,x); }
    T query(size_t i) const { return doQuery(i); }
};

#endif
