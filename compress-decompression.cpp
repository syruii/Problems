//
// Created by Syrup on 8/04/2018.
//

#include "compress-decompression.h"
#include <stack>

std::string Decompressor::decompress(std::string& input) {
    // THIS IS DEFAULT CONSTRUCTED.
    std::stack<int> repeat;
    // checking for empty case
    if (input.size() == 0) {
        return input;
    }
    std::string result;
    std::string numstring = "";
    std::string workingstring = "";
    for (int i = 0; i < input.size(); ++i) {
        if (islower(input.at(i))) {
            //its a character
            if (!repeat.empty()) {
                workingstring += input.at(i);
            } else {
                result += input.at(i);
            }
        } else if (isdigit(input.at(i))) {
            numstring += input.at(i);
        } else if (input.at(i) == '[') {
            repeat.push(std::stoi(numstring));
            numstring = "";
        } else if (input.at(i) == ']') {
            int numrepeat = repeat.top();
            repeat.pop();
            std::string finstring = "";
            for (int j = 0; j < numrepeat; ++j) {
                finstring += workingstring;
            }
            workingstring = finstring;
            if (repeat.empty()) {
                result += workingstring;
                workingstring = "";
            }
        }
    }
    return result;
}