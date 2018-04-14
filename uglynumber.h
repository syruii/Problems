//
// Created by Syrup on 11/04/2018.
//

#ifndef LEETCODE_UGLYNUMBER_H
#define LEETCODE_UGLYNUMBER_H
#include <set>
#include <queue>
using namespace std;

class Ugly {
public:

    int nthUglyNumber(int n);

    void add_next(unsigned int next, set<unsigned int>& seen, queue<unsigned int>& twos, queue<unsigned int>& threes, queue<unsigned int>& fives);
};

#endif //LEETCODE_UGLYNUMBER_H
