#include "subsequence_finder.h"
#include "node.h"

#include <vector>

std::vector<int> SubsequenceFinder::findIndices(const std::vector<int> &perm) const {
    int n = perm.size();
    std::vector<Node> nodes;
    for(auto isDown: usesDownQueries) {
        nodes.emplace_back(isDown, n);
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
    bestNode->reconstruct(bestIndex, result);
    return result;
}

