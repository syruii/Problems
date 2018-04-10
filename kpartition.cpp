//
// Created by Syrup on 10/04/2018.
//

#include "kpartition.h"
#include <numeric>

std::vector<std::vector<int>> Partitioner::partiton(std::vector<int> &nums, int sum, int k) {
    std::vector<std::vector<int>> result;
    if (k == 1) {
        result.push_back(nums);
        return result;
    }
    if (nums.size() < k) {
        return result;
    }

    // get sum
    int sumtotal = std::accumulate(nums.begin(), nums.end(), 0);
    int partOf[nums.size()] = {0};
    int sumLeft[k];
    for (int i = 0; i < k; ++i) {
        sumLeft[i] = sum/k;
    }

    bool res = !(sum % k) && subsetSums()
}

