//
// https://leetcode.com/problems/split-linked-list-in-parts/
// O(2N) time complexity, O(K) space
// We can easily computer length[i] for every i by just dividend + (remainder > 0 ? 1 : 0); --remainder;
// leaving O(1) space, but a few bytes ain't nothing to worry about
//

#include "splitlist.h"

vector<ListNode *> Split::splitListToParts(ListNode *root, int k) {

    int size = 0;
    ListNode *curr = root;
    while (curr != NULL) {
        size++;
        curr = curr->next;
    }

    vector<ListNode*> out;
    curr = root;
    ListNode *next;
    // got size, see if we can split into something thats more than one
    if (size < k) {
        // we make size 1 spots and fill rest with empty
        for (int i = 0; i < k; ++i) {
            if (curr != NULL) {
                next = curr->next;
                curr->next = NULL;
            }
            // we reached NULL, so push null until we fill
            out.push_back(curr);
            curr = next;
        }
    } else {
        int length[k];
        int dividend = size / k; // greater than or equal to 1
        int remainder = size % k; // remainder is < k, we add one to first remainder
        for (int i = 0; i < k; ++i) {
            length[i] = dividend;
        }
        for (int i = 0; i < remainder; ++i) {
            ++length[i];
        }
        // now we just loop through length array and make the list
        for (int i = 0; i < k; ++i) {
            ListNode *top = curr; // top of the list we are going to push
            for (int j = 0; j < length[i] - 1; ++j) {
                curr = curr->next;
            }
            // we are at the last element of the list
            next = curr->next;
            curr->next = NULL;
            out.push_back(top);
            curr = next;
        }
    }
    return out;
}
