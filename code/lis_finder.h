#ifndef LIS_FINDER
#define LIS_FINDER

#include "subsequence_finder.h"

// finds the longest increasing subsequence

class LisFinder: public SubsequenceFinder {
public:
    LisFinder(): SubsequenceFinder({true},{{0,0}},{0},{0}) {}
};

#endif
