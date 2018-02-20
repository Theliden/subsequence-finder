#ifndef ROLLERCOASTER_FINDER
#define ROLLERCOASTER_FINDER

#include "subsequence_finder.h"

class RollercoasterFinder: public SubsequenceFinder {
    static std::vector<bool> usesDownQueries(int k);
    static std::vector<std::pair<int,int>> dependencies(int k);
public:
    RollercoasterFinder(int k = 3);
};

#endif
