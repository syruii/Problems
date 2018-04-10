//
// Created by Syrup on 10/04/2018.
//

#ifndef LEETCODE_KPARTITION_H
#define LEETCODE_KPARTITION_H
#include <vector>

class Partitioner {
public:
    std::vector<std::vector<int>> partiton(std::vector<int> &nums, int sum, int k);
private:
    bool checkSum(int sumLeft[], int k);
};


#endif //LEETCODE_KPARTITION_H
