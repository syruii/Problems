//
// Created by Syrup on 8/04/2018.
// https://www.geeksforgeeks.org/find-all-occurrences-of-the-word-in-a-matrix/
// Given a NXM matrix, find all occurences of the word which can move
// in a certain pattern
//

#include "searchmatrix.h"

static std::vector<std::pair<int,int>> getPossibleCoordinates(int row, int col) {
    auto v = std::vector<std::pair<int,int>>();
    if (row - 1 >= 0) {
        v.push_back(std::make_pair(row-1, col));
    }
    if (row + 1 < ROWS) {
        v.push_back(std::make_pair(row+1, col));
    }
    if (col - 1 >= 0) {
        v.push_back(std::make_pair(row, col-1));
    }
    if (col + 1 < COLS) {
        v.push_back(std::make_pair(row, col+1));
    }
    return v;
};

std::vector<matrixPath> matrixSearch::findWord(char mat[ROWS][COLS], std::string &str) {
    if (str.size() == 0) {
        return std::vector<matrixPath>();
    }
    std::vector<matrixPath> result;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            dfs(mat, i, j, str, result, matrixPath());
        }
    }

    return result;
}

//
void matrixSearch::dfs(char mat[ROWS][COLS], int startrow, int startcol, std::string &str, std::vector<matrixPath> &result, matrixPath prev) {
    if (str.at(0) != mat[startcol][startrow]) {
        return;
    }
    // correct part of the path
    prev.coordinates.push_back(std::make_pair(startrow, startcol));
    std::string rest = str.substr(1);
    if (rest.size() == 0) {
        result.push_back(prev);
        return;
    }
    for (std::pair<int,int> possibleCoord : getPossibleCoordinates(startrow, startcol)) {
        dfs(mat,possibleCoord.first, possibleCoord.second, rest, result, prev);
    }
}
