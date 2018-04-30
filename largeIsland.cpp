//
// Created by Syrup on 30/04/2018.
// https://leetcode.com/problems/making-a-large-island/description/
// A pretty similar problem to getting rid of all islands
// Just paint all the stuff you want and keep track of where each square belongs
// either you can change the input grid, or you can create a hash map from coordinates
// to group, or create an entirely new grid (if you wanted to return a grid anyway)

#include "largeIsland.h"
#include <unordered_set>
#include <algorithm>

static int paint(int i, int j, int c, std::vector<std::vector<int>>& g) {
    //recurisve bfs
    if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] != 1) return 0;
    g[i][j] = c;
    return 1 + paint(i + 1, j, c, g) + paint(i - 1, j, c, g) + paint(i, j + 1, c, g) + paint(i, j - 1, c, g);
}
static int getIsland(int i, int j, std::vector<std::vector<int>>& g) {
    if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size()) {
        return 0;
    } else {
        return g[i][j];
    }
}

int largeIsland::largestIsland(std::vector<std::vector<int>>& grid) {
    int sizeX = grid.size();
    int sizeY = grid[0].size();
    std::vector<int> islandSizes;
    int totalsize = sizeX * sizeY;
    int biggestIsland = 0;
    for (int i = 0; i < sizeX; ++i) {
        for (int j = 0; j < sizeY; ++j) {
            if (grid[i][j] == 1) {
                // needs to be 2 so that it doesn't get repeated
                islandSizes.push_back(paint(i, j, islandSizes.size() + 2, grid));
                biggestIsland = std::max(biggestIsland, islandSizes.back());
            }
        }
    }
    for (int i = 0; i < sizeX; ++i) {
        for (int j = 0; j < sizeY; ++j) {
            if (grid[i][j] == 0) {
                std::unordered_set<int> neighbouringIslands = {getIsland(i-1, j, grid), getIsland(i+1,j, grid), getIsland(i, j-1, grid), getIsland(i, j+1, grid)};
                int joinedIslandSize = 0;
                for (const auto& island : neighbouringIslands) {
                    if (island) {
                        joinedIslandSize += islandSizes[island - 2];
                    }
                }
                biggestIsland = std::max(biggestIsland, joinedIslandSize + 1);
            }
        }
    }
    return biggestIsland;
}
