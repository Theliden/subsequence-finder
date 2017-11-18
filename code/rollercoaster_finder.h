#ifndef ROLLERCOASTER_FINDER
#define ROLLERCOASTER_FINDER

#include "subsequence_finder.h"

class RollercoasterFinder: public SubsequenceFinder {
public:
    RollercoasterFinder():
        SubsequenceFinder(
            {true, true, false, false},
            {{0, 3}, {2, 1}, {1, 1}, {1, 0}, {3, 3}, {3, 2}},
            {0, 2},
            {0, 2}) {}
};

#endif
