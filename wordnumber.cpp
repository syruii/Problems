//
// Created by Syrup on 6/04/2018.
// Convert string of 1234 into how a human would pronounce it
//

#include <string>
#include <vector>
#include <array>

std::string num2string(int num) {
    std::string numstring = std::to_string(num);
    std::vector<int> digits = std::vector<int>();
    int magnitude = 0;
    for (auto i = numstring.begin(); i != numstring,end(); ++i) {
        digits.push_back((*i));
        ++magnitude;
    }
    int i;
    std::array<int> hundreds;
    while (magnitude > 0) {
        if (magnnitude) {
            // basically if magnitude isn't a 1s, 10s, 100s, 1000s,
            // then turn push the numbers into hundreds array
            // send to a function that computes the hundreds
            // then get the thousand/million
            // then once you reach 100s send it to compute hundreds
        }
    }

}

std::string mag2word (int i) {
    switch (i) {
        case 4:
            return std::string("thousand");
        case 5:
            return std::string("")

    }
}