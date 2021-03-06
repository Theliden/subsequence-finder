#include "node.h"
#include "fenwick_tree.h"
#include "reverse.h"

#include <vector>
#include <algorithm>

// Could replace FenwickTree here with another data structure
// (e.g. a vEB tree can do operations in O(log log m))
template<typename T>
using DS = FenwickTree<T>;

// All upcoming values are assumed to be in the range [1,m]
Node::Node(bool downQueries, int m):
    dependencies(),
    tree(downQueries?static_cast<std::unique_ptr<Queriable<T>>>
         (std::make_unique<DS<T>>(m, std::make_pair(-1, -1)))
         :std::make_unique<Reverse<T,DS>>(m, std::make_pair(-1, -1))),
    previous(),
    bestLength(-1) {}

void Node::addDependency(const Node &other) {
    dependencies.push_back(&other);
}

void Node::prepareChanges(int val) {
    auto best = std::make_pair(-1, -1);
    const Node *withBest = nullptr;
    for(const auto &dep: dependencies) {
        auto candidate = dep->tree->query(val);
        if(candidate.first > 0 && candidate > best) {
            best = candidate;
            withBest = dep;
        }
    }
    previous.emplace_back(best.second, withBest);
    if(best.first > 0) {
        bestLength = 1 + best.first;
    }
    else {
        bestLength = -1;
    }
}

void Node::addBaseCase() {
    if(1 > bestLength) {
        bestLength = 1;
    }
}

void Node::applyChanges(int val, int index) {
    tree->update(val, std::make_pair(bestLength, index));
}

int Node::getBestLength() const {
    return bestLength;
}

void Node::reconstruct(int i, std::vector<int> &acc) const {
    const Node *p = this;
    while(i >= 0) {
        acc.push_back(i);
        int ii = p->previous[i].first;
        p = p->previous[i].second;
        i = ii;
    }
    std::reverse(acc.begin(), acc.end());
}
