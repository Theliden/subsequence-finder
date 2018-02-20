#ifndef TESTER_H
#define TESTER_H

#include <string>

#include "subsequence_finder.h"

class Tester {
    std::string type;
    SubsequenceFinder finder;
public:
    Tester(const std::string &type, SubsequenceFinder &finder):
        type{type}, finder{finder} {}
    bool test() const;
};

#endif
