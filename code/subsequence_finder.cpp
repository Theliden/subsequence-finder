#include <vector>
#include <algorithm>

#include "subsequence_finder.h"
#include "node.h"

std::vector<int> SubsequenceFinder::findIndices(
    const std::vector<int> &vals) const {
    // default bound m is n,
    // which is the case if the input is a permutation of 1,2,...,n
    return findIndices(vals, vals.size()); 
}

std::vector<int> SubsequenceFinder::findIndices(
    const std::vector<int> &vals, int m) const {
    int n = vals.size();
    std::vector<int> perm;
    std::tie(m,perm) = compress(m,vals);
    std::vector<Node> nodes;
    for(auto isDown: usesDownQueries) {
        nodes.emplace_back(isDown, m);
    }
    for(auto d: dependencies) {
        nodes[d.first].addDependency(nodes[d.second]);
    }
    int bestLength = -1;
    const Node *bestNode = nullptr;
    int bestIndex = -1;
    
    for(int i = 0; i < n; ++i) {
        int j = perm[i];
        for(auto &node:nodes) {
            node.prepareChanges(j);
        }
        for(auto nodeid: startNodes) {
            nodes[nodeid].addBaseCase();
        }
        for(auto &node:nodes) {
            node.applyChanges(j, i);
        }
        for(auto nodeid: accepting) {
            int len = nodes[nodeid].getBestLength();
            if(len > bestLength) {
                bestLength = len;
                bestNode = &nodes[nodeid];
                bestIndex = i;
            }
        }
    }
    std::vector<int> result;
    if(bestNode) {
        bestNode->reconstruct(bestIndex, result);
    }
    return result;
}

// We want the sequence to consist of values in [1,m], with m not too large
// Given m and vals, this function checks if this requirement is violated,
// and if so, returns the compressed values and minimum possible m
std::pair<int,std::vector<int>> SubsequenceFinder::
    compress(int m, const std::vector<int> &vals) const {
    bool violations = false;
    for(int x:vals) {
        if(x<1 || x>m) violations = true;
    }
    if(!violations) return {m,vals};
    int n = vals.size();
    std::vector<int> result(n);
    std::vector<std::pair<int,int>> ps;
    for(int i=0; i<n; ++i) {
        ps.emplace_back(vals[i],i);
    }
    std::sort(ps.begin(),ps.end());
    m = 1;
    for(int i=0; i<n; ++i) {
        if(i>0 && ps[i].first>ps[i-1].first) ++m;
        result[ps[i].second] = m;
    }
    return {m,result};
}
