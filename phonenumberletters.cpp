//
// Created by Syrup on 2/05/2018.
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
//

#include "phonenumberletters.h"

std::vector<std::string> phonenumberletters::letterCombinations(std::string digits) {
    std::vector<std::string> result;
    if (digits.size() == 0) {
        return {""};
    }
    char digit = digits[0];
    std::vector<char> possibleletters = letters[digit];
    std::vector<std::string> next = letterCombinations(digits.substr(1));
    for (std::string ending : next) {
        for (char letter: possibleletters) {
            result.push_back(letter + ending);
        }
    }
    return result;
}