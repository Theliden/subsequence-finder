#ifndef FENWICK_TREE_H
#define FENWICK_TREE_H

#include "queriable.h"

#include <vector>

// A general Fenwick tree that supports prefix maximum queries
template<typename T>
class FenwickTree: public Queriable<T> {
    size_t n;
    std::vector<T> data;
    void doUpdate(size_t i, const T &x) override {
        while(i <= n) {
            if(x > data[i]) {
                data[i] = x;
            }
            i += i&-i;
        }
    }
    T doQuery(size_t i) const override {
        T x = data[i];
        i -= i&-i;
        while(i) {
            if(data[i] > x) {
                x = data[i];
            }
            i -= i&-i;
        }
        return x;
    }
public:
    ~FenwickTree() override {}
    FenwickTree(size_t n, const T &init): n(n), data(n + 1, init) {}
};

#endif
