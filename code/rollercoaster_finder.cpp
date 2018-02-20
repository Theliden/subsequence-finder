#include <vector>

#include "rollercoaster_finder.h"

std::vector<bool> RollercoasterFinder::usesDownQueries(int k) {
    std::vector<bool> result(2*k, false);
    for(int i=0; i<k-1;++i) result[i] = true;
    result[2*k-1] = true;
    return result;
}

std::vector<std::pair<int,int>> RollercoasterFinder::dependencies(int k) {
    std::vector<std::pair<int,int>> result;
    for(int i=1;i<k;++i) {
        result.emplace_back(i,i-1);
        result.emplace_back(k+i,k+i-1);
    }
    result.emplace_back(1,2*k-1);
    result.emplace_back(k+1,k-1);
    result.emplace_back(k-2,k-2);
    result.emplace_back(2*k-2,2*k-2);
    return result;
}

RollercoasterFinder::RollercoasterFinder(int k):
    SubsequenceFinder(
        RollercoasterFinder::usesDownQueries(k),
        RollercoasterFinder::dependencies(k),
        {0,k}, {k-1,2*k-1}) {}
