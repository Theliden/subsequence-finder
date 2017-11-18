#ifndef SUBSEQUENCE_FINDER_H
#define SUBSEQUENCE_FINDER_H

#include <vector>

class SubsequenceFinder {
    std::vector<bool> usesDownQueries;
    std::vector<std::pair<int, int>> dependencies;
    std::vector<int> startNodes;
    std::vector<int> accepting;
public:
    SubsequenceFinder(
        const std::vector<bool> &usesDownQueries,
        const std::vector<std::pair<int, int>> &dependencies,
        const std::vector<int> &startNodes,
        const std::vector<int> &accepting):
        usesDownQueries(usesDownQueries),
        dependencies(dependencies),
        startNodes(startNodes),
        accepting(accepting) {}
    virtual ~SubsequenceFinder() {}
    std::vector<int> findIndices(const std::vector<int> &perm) const;
};

#endif
