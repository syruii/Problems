//
// Created by Syrup on 5/04/2018.
// https://leetcode.com/problems/asteroid-collision/description/
//
#include <vector>
#include <stack>
#include <stdlib.h>
#include "asteroid-collision.h"

std::vector<int> AsteroidCollision::asteroidCollision(std::vector<int>& asteroids) {
    auto res = std::vector<int>();
    for (int asteroid : asteroids) {
        if (asteroid > 0 || res.empty()) {
            res.push_back(asteroid);
        } else if (asteroid < 0) {
            while (res.back() > 0 && res.back() < abs(asteroid)) {
                res.pop_back();
            }
            // top of "stack" is either a negative asteroid or a positive asteroid
            // which is >= current negative asteroid
            if (res.empty()) {
                res.push_back(asteroid);
            } else if (res.back() == abs(asteroid)) {
                // destroy both if theyre equal
                res.pop_back();
            } else if (res.back() < 0) {
                res.push_back(asteroid);
            }
        }
    }
    return res;
}

std::vector<int> AsteroidCollision::asteroidCollisionStack(std::vector<int>& asteroids) {
    auto res = std::vector<int>();
    for (int asteroid : asteroids) {
        bool flag = false;
        if (asteroid > 0) {
            res.push_back(asteroid);
        } else if (asteroid < 0) {
            while (!res.empty() && res.back() > 0) {
                if (res.back() + asteroid == 0) {
                    res.pop_back();
                    flag = true;
                    break;
                } else if(res.back() + asteroid < 0) {
                    res.pop_back();
                    continue;
                }
                break;
            }
            if (!flag && (res.empty() || res.back() < 0 ) ) {
                res.push_back(asteroid);
            }
        }
    }
    return res;
}