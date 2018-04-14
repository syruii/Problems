//
// Created by Syrup on 11/04/2018.
//

#include "uglynumber.h"

using namespace std;

int Ugly::nthUglyNumber(int n) {
    if (n == 1) {
        return 1;
    }
    queue<unsigned int> twos;
    queue<unsigned int> threes;
    queue<unsigned int> fives;
    set<unsigned int> seen;
    twos.push(2);
    threes.push(3);
    fives.push(5);
    unsigned int num = 1;

    unsigned int next;
    while (num < n) {
        // get  smallest
        if (twos.front() < threes.front()) {
            if (twos.front() < fives.front()) {
                // twos is smallest
                next = twos.front();
                twos.pop();
                add_next(next, seen, twos, threes, fives);
            } else {
                // five is smallest
                next = fives.front();
                fives.pop();
                add_next(next, seen, twos, threes, fives);
            }
        } else if (threes.front() < fives.front()) {
            //three smallest
            next = threes.front();
            threes.pop();
            add_next(next, seen, twos, threes, fives);
        } else {
            //five smallest
            next = fives.front();
            fives.pop();
            add_next(next, seen, twos, threes, fives);
        }
        ++num;
    }
    return next;
}

void Ugly::add_next(unsigned int next, set<unsigned int> &seen, queue<unsigned int> &twos, queue<unsigned int> &threes, queue<unsigned int> &fives) {
    if (seen.count(next * 2) == 0) {
        seen.insert(next * 2);
        twos.push(next * 2);
    }
    if (seen.count(next * 3) == 0) {
        seen.insert(next * 3);
        threes.push(next * 3);
    }
    if (seen.count(next * 5) == 0) {
        seen.insert(next * 5);
        fives.push(next * 5);
    }


}
