//
// Created by Syrup on 2/05/2018.
// https://leetcode.com/problems/binary-trees-with-factors/description/
// without the modulo 10**9 + 7


#include "binarytreefactors.h"
#include <set>
#include <unordered_map>

int binarytreefactors::numFactoredBinaryTrees(std::vector<int> &A) {
    std::set<int> ints{A.begin(), A.end()};
    std::unordered_map<int, long> numfactors;
    int sum = 0;
    for (int num : ints) {
        numfactors[num] = 1;
        for (int num2 : ints) {
            if (num2 > num) {
                // numbers cant be divisible by numbers bigger than themselves
                break;
            }
            if (num % num2 == 0 and ints.find(num / num2) != ints.end()) {
                numfactors[num] += (numfactors[num / num2] * numfactors[num2]);
            }
        }
    }
    for (auto it = numfactors.begin(); it != numfactors.end(); ++it) {
        sum += it->second;
    }
    return sum;
}