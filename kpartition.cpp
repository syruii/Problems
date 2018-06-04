//
// Created by Syrup on 10/04/2018.
//

#include "kpartition.h"
#include <numeric>
#include <vector>

using namespace std;

static bool dfs(vector<int>& nums, vector<int>& used, int currsum, int sum, int currk, int k, int idx) {
    bool res = false;
    if (currsum > sum) return false;

    if (currk >= k) return true;

    if (currsum == sum) {
        return dfs(nums, used, 0, sum, currk+1, k, 0);
    }

    for (int i = idx; i < nums.size(); i++) {
        if (used[i] == -1) {
            used[i] = currk;
            res = dfs(nums, used, currsum + nums[i], sum, currk, k, i + 1);
            if (res == true) return true;
            used[i] = -1;
        }
    }
    return res;

}

vector<vector<int>> Partitioner::partiton(vector<int> &nums, int k) {
    std::vector<int> used(nums.size(), -1);
    int total = accumulate(nums.begin(), nums.end(), 0);
    if (total % k != 0) return vector<vector<int>>();

    if (dfs(nums, used, 0, total/k, 0, k, 0)) {
        auto result = vector<vector<int>>();
        result.resize(k);
        for (int i = 0; i < used.size(); i++) {
            result[used[i]].push_back(nums[i]);
        }
        return result;
    } else {
        return vector<vector<int>>();
    }

}

