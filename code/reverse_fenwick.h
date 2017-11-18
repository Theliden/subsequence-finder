#ifndef REVERSE_FENWICK
#define REVERSE_FENWICK

#include "fenwick_tree.h"

template<typename T> class ReverseFenwick: public Queriable<T> {
    size_t n;
    FenwickTree<T> tree;
public:
    ~ReverseFenwick() {}
    ReverseFenwick(size_t n, const T &init): n(n), tree(n, init) {}
    void update(size_t i, const T &x) override {
        tree.update(n - i + 1, x);
    }
    T query(size_t i) const override {
        return tree.query(n - i + 1);
    }
};

#endif
