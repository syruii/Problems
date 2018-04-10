//
// Created by Syrup on 6/04/2018.
// https://leetcode.com/problems/median-of-two-sorted-arrays/description/
//
#include "median-sorted.h"

double medianSort::findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
    //setup
    int max1 = nums1.size() - 1;
    int min1 = 0;
    int max2 = nums2.size() - 1;
    int min2 = 0;

    while (min1 != max1 || min2 != max2) {
        int mid1 = nums1.at(min1 + (max1 - min1) / 2);
        int mid2 = nums2.at(min2 + (max2 - min2) / 2);
        if (mid1 < mid2) {
            if (min1 != max1) {
                min1 = min1 + (max1 - min1) / 2 + 1;
            }
            if (min2 != max2) {
                max2 = min2 + (max2 - min2) / 2 - 1;
            }
        } else if (mid1 > mid2) {
            if (min2 != max2) {
                min2 = min2 + (max2 - min2) / 2 + 1;
            }
            if (max1 != min1) {
                max1 = min1 + (max1 - min1) / 2 - 1;

            }
        } else {
            break;
        }
    }
    double num1 = nums1.at(min1);
    double num2 = nums2.at(min2);
    if (num1 < num2) {
        // number of entries less than num1 = min1 + min2
        // number of entries greater than num1 are
        // numbers of entires greater than num1
        return num1;
    } else if (num1 > num2) {
        return num2;
    } else {
        return num1;
    }
}