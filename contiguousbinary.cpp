//
// Created by Syrup on 2/05/2018.
// https://leetcode.com/problems/contiguous-array/description/
// sum tracks 1's - 0's
// place in array/hashmap the first index encountered with that sum
// if we encounter it again we have a valid array from i to map[sum]
// keep rolling max
//

#include "contiguousbinary.h"
#include <unordered_map>
#include <algorithm>

int contiguousbinary::findMaxLength(std::vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
    // (SUM) to (lowest index)
    std::unordered_map<int,int> onesleft;
    onesleft[0] = -1;
    int sum = 0;
    int maxLength = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += (nums[i] == 0 ? -1 : 1);
        auto it = onesleft.find(sum);
        if (it != onesleft.end()) {
            maxLength = std::max(maxLength, i - it->second);
        } else {
            onesleft[sum] = i;
        }
    }
    return maxLength;
}