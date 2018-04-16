//
// Created by Syrup on 16/04/2018.
//

#include "num2string.h"

static int char2digit(char a) {
    return a - '0';
}

static std::string two_digits2string(char tens, char digits) {
    /* The first string is not used, it is to make array indexing simple */
    std::string single_digits[] = { "", "one", "two", "three", "four",
                                    "five", "six", "seven", "eight", "nine"};

    /* The first string is not used, it is to make array indexing simple */
    std::string two_digits[] = {"ten", "eleven", "twelve", "thirteen", "fourteen",
                                "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    /* The first two string are not used, they are to make array indexing simple*/
    std::string tens_multiple[] = {"", "", "twenty", "thirty", "forty", "fifty",
                                   "sixty", "seventy", "eighty", "ninety"};
    if (tens == '0') {
        return single_digits[char2digit(digits)];
    } else if (tens == '1') {
        return two_digits[char2digit(digits)];
    } else {
        return tens_multiple[char2digit(tens)] + " " + single_digits[char2digit(digits)];
    }
}

std::string HumanString::toWord(int num) {
    std::string single_digits[] = { "zero", "one", "two", "three", "four",
                                    "five", "six", "seven", "eight", "nine"};
    std::string tens_power[] = {"hundred", "thousand"};

    // handling cases [0, 100 000)
    std::string number = std::to_string(num);
    int len = number.length();

    if (len == 1 ) return single_digits[char2digit(number.at(0))];
    std::string result = "";
    std::string s;
    while (len > 0) {
        switch (len) {
            case 5:
                result += two_digits2string(number.at(number.length() - len), number.at(number.length() - len + 1));
                result += " " + tens_power[1];
                len--;
                break;
            case 4:
                result += two_digits2string('0', number.at(number.length() - len));
                result += " " + tens_power[1];
                break;
            case 3:
                s = two_digits2string('0', number.at(number.length() - len));
                if (result != "" && s != "") result += " ";
                if (s != "") result += s + " " + tens_power[0];
                break;
            case 2:
                s = two_digits2string(number.at(number.length() - len), number.at(number.length() - len + 1));
                if (result != "" && s != "") result += " and ";
                if (s != "") result += s;
                len--;
                break;
        }
        len--;
    }
    return result;

}

std::string HumanString::toWordInt(std::string num) {
    /*
     * Returns the string of digits as a sequence
     * 999333310 : four nines four threes one zero
     */
}