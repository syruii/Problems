#include <iostream>
#include <vector>
#include "asteroid-collision.h"
#include "wildcardmatching.h"
#include "median-sorted.h"
#include "removeevenduplicates.h"
#include "searchmatrix.h"
#include "compress-decompression.h"
#include "reversenodeskgroups.h"
#include "uglynumber.h"
#include "splitlist.h"
int main() {
    /*
    auto sln = AsteroidCollision();
    std::vector<int> test = {8, -8};
    auto res = sln.asteroidCollisionStack(test);
    for (int num : res) {
        std::cout << num << std::endl;
    }
    */
    /*
    vector<int> nums1{1,2,3,4,5};
    vector<int> nums2{2};

    double ret = medianSort().findMedianSortedArrays(nums1, nums2);

    std::cout << removeDuplicates().remove("you got beautiful eyes");
    */
    /*
    char grid[3][3] = {'D', 'E', 'P',
                        'E', 'C', 'E',
                        'P', 'A', 'D'};
    std::string search = "DEP";

    matrixSearch().findWord(grid, search);
     */
    /*
    std::string compressed = "1[1[1[1[1[1[1[1[1[1[1[1[1[1[1[1[1[1[1[1[xx]]]]]]]]]]]]]]]]]]]]";
    std::cout << Decompressor().decompress(compressed);
    */

    /*
    std::vector<int> v = {1, 2, 3, 4, 5};
    ListNode *list = makeList(v);
    list = Solution().reverseKGroup(list, 2);
    deleteList(list);
    */

    //std::cout << Ugly().nthUglyNumber(16500);

    vector<int> nums{1,2,3,4,5,6,7,8,9,10};
    ListNode* l = makeList(nums);
    Split().splitListToParts(l, 3);


}



