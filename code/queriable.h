#ifndef QUERIABLE_H
#define QUERIABLE_H

#include <cstddef>

template<typename T> class Queriable {
public:
    virtual ~Queriable() {}
    virtual void update(size_t i, const T &x) = 0;
    virtual T query(size_t i) const = 0;
};

#endif
