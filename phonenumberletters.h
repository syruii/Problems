//
// Created by Syrup on 2/05/2018.
//

#ifndef LEETCODE_PHONENUMBERLETTERS_H
#define LEETCODE_PHONENUMBERLETTERS_H
#include <string>
#include <vector>
#include <unordered_map>

class phonenumberletters {
private:
    std::unordered_map<char, std::vector<char>> letters{
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}}
    };
public:
    std::vector<std::string> letterCombinations(std::string digits);
};


#endif //LEETCODE_PHONENUMBERLETTERS_H
