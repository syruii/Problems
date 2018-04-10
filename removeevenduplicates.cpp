//
// Created by Syrup on 8/04/2018.
//

#include "removeevenduplicates.h"


std::string removeDuplicates::remove(std::string arr) {
    if (arr.size() == 0) {
        return arr;
    }
    int seen[26] = {};
    int lastempty = -1;
    ++seen[arr.at(0) -'a'];
    for (int i = 1; i < arr.size(); ++i) {
        if (++seen[arr.at(i) - 'a'] % 2) {
            if (lastempty > 0) {
                arr.at(lastempty++) = arr.at(i);
            }
        } else {
            if (lastempty == -1) {
                lastempty = i;
            }
        }
    }
    if (lastempty > 0) {
        arr.resize(lastempty);
    }
    return arr;
}