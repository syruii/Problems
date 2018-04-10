//
// Created by Syrup on 8/04/2018.
//

#ifndef LEETCODE_SEARCHMATRIX_H
#define LEETCODE_SEARCHMATRIX_H
#include <vector>
#include <string>

#define ROWS 3
#define COLS 3
class matrixPath {
public:
    std::vector<std::pair<int, int>> coordinates = std::vector<std::pair<int,int>>();
};

class matrixSearch {
public:
    std::vector<matrixPath> findWord(char mat[ROWS][COLS], std::string& str);
private:
    void dfs(char mat[ROWS][COLS], int startrow, int startcol, std::string& str, std::vector<matrixPath>& result, matrixPath prev);
};

#endif //LEETCODE_SEARCHMATRIX_H
