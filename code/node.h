#ifndef NODE_H
#define NODE_H

#include "queriable.h"

#include <vector>
#include <memory>

class Node {
    using T = std::pair<int, int>;
    std::vector<const Node*> dependencies;
    std::unique_ptr<Queriable<T>> tree;
    std::vector<std::pair<int, const Node*> > previous;
    int bestLength;
public:
    Node(bool downQueries, int m);
    void addDependency(const Node &other);
    void prepareChanges(int val);
    void addBaseCase();
    void applyChanges(int val, int index);
    int getBestLength() const;
    void reconstruct(int i, std::vector<int> &acc) const;
};

#endif
