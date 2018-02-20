#include "tester.h"
#include "subsequence_finder.h"

#include <iostream>
#include <fstream>
#include <vector>

bool Tester::test() const {
    const std::string file = "../tests/"+type;
    auto input = std::ifstream(file+".in");
    auto expected = std::ifstream(file+".out");
    int n;
    while(input >> n) {
        std::vector<int> a(n);
        for(int i=0; i<n; ++i) input >> a[i];
        int result = finder.findIndices(a).size();
        int exp;
        expected >> exp;
        if(result != exp) {
            std::cerr << "Test failed in test suite " << type << std::endl;
            std::cerr << "Input:" << std::endl;
            for(int i=0; i<n; ++i) {
                std::cerr << a[i];
                if(i+1<n) std::cerr << " ";
            }
            std::cerr << std::endl;
            std::cerr << "Expected:\n" << exp << std::endl;
            std::cerr << "Output:\n" << result << std::endl;
            return false;
        }
    }
    return true;
}
