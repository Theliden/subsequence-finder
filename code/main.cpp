#include <iostream>
#include <algorithm>
#include <vector>

#include "subsequence_finder.h"
#include "rollercoaster_finder.h"
#include "lis_finder.h"
#include "tester.h"

void printAtIndices(const std::vector<int> is, const std::vector<int> &v) {
    for(auto i:is) std::cout << v[i] << " ";
    std::cout << std::endl;
}

void manualTest(const RollercoasterFinder &rf) {
    int n; 
    std::cin >> n;
    std::vector<int> perm(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> perm[i];
    }
    std::vector<int> result = rf.findIndices(perm);
    std::cout << result.size() << std::endl;
    printAtIndices(result, perm);
}

void randomTests(int n, int times, const RollercoasterFinder &rf) {
    std::vector<int> perm(n);
    for(int i = 0; i < n; ++i) {
        perm[i] = i + 1;
    }
    for(int r = 0; r < times; ++r) {
        std::random_shuffle(perm.begin(), perm.end());
        for(auto x:perm) std::cout << x << " ";
        std::cout << std::endl;
        printAtIndices(rf.findIndices(perm), perm);
        std::cout << std::endl;
    }
}

double expectedLength(int n, int times, const RollercoasterFinder &rf) {
    std::vector<int> perm(n);
    for(int i = 0; i < n; ++i) {
        perm[i] = i + 1;
    }
    double sum = 0;
    for(int r = 0; r < times; ++r) {
        std::random_shuffle(perm.begin(), perm.end());
        sum += rf.findIndices(perm).size();
    }
    return sum / times;
}

int main() {
    std::vector<std::pair<std::string,SubsequenceFinder>> tests{
        {"lis",LisFinder()},
        {"rollercoaster",RollercoasterFinder()},
        {"rc4",RollercoasterFinder(4)}};
    for(auto p:tests) {
        Tester t(p.first,p.second);
        if(!t.test()) return 1;
    }
}
