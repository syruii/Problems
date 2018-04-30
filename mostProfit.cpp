//
// Created by Syrup on 30/04/2018.
// https://leetcode.com/problems/most-profit-assigning-work/description/
// Initialise the difficulty array with the profit values straight from vector, maxing sure to not overwrite the previous one
// if its better (in case of multiple jobs of same difficulty).
// Starting from difficulty 1 (difficulty 0 is either 0 as initialised or the best 0 difficulty job) check whether
// the job of the previous difficulty is better (array contains the best job up to that difficulty).
// At the end sum up all the relevant mappings.


#include "mostProfit.h"
#include <algorithm>


int mostProfit::maxProfitAssignment(std::vector<int> &difficulty, std::vector<int> &profit, std::vector<int> &worker) {
    int bestProfit[100000] = {0};
    // put in the base case difficulties
    for (int i = 0; i < difficulty.size(); ++i) {
        bestProfit[difficulty[i] - 1] = std::max(bestProfit[difficulty[i] - 1], profit[i]);
    }
    for (int i = 1; i  < 100000; ++i) {
        bestProfit[i] = std::max(bestProfit[i], bestProfit[i-1]);
    }
    int result = 0;
    for (int& ability : worker) result += bestProfit[ability - 1];
    return result;
}
