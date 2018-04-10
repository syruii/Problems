//
// Created by Syrup on 7/04/2018.
//

#include "wildcardmatching.h"

bool wildcardmatching::isMatch(string s, string p) {
    int m = s.length(), n = p.length();
    int i = 0, j = 0, asterick = -1, last_match;
    while (i < m) {
        if (j < n && p[j] == '*') {
            // we match exactly zero character (we don't increment i)
            // if we fall out of the second matching condition, we go back and increment the amount we match
            // consecutive *: the second * takes over and the first * is confirmed to match nothing since it
            // doesn't affect the outcome
            last_match = i;
            asterick = j++;
        }
        else if (j < n && (s[i] == p[j] || p[j] == '?')) {
            // if we reach here we have stopped the * match
            i++;
            j++;
        }
        else if (asterick >= 0) {
            i = ++last_match; // last_match + 1, where last_match is the last character matched by *
            j = asterick + 1;
        }
        else return false;
    }
    while (j < n && p[j] == '*') j++;
    return j == n;
}

