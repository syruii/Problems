//
// Created by Syrup on 9/04/2018.
//

#include "reversenodeskgroups.h"

ListNode* Solution::reverseKGroup(ListNode* head, int k) {
    std::stack<ListNode*> stack;
    if (head == NULL || k == 1) {
        return head;
    }

    ListNode* topNew = head;
    ListNode* lastEnd = NULL;
    ListNode* curr = head;
    while (curr != NULL) {
        for (int i = 0; i < k ; ++i) {
            if (curr != NULL) {
                stack.push(curr);
                curr = curr->next;
            } else {
                // we reached the end of the list without reaching the required amount of nodes
                return topNew;
            }
        }
        // we pushed k nodes on to the stack, now reverse
        while (!stack.empty()) {
            if (lastEnd == NULL) {
                // first group of the list
                topNew = stack.top();
                stack.pop();
                lastEnd = topNew;
            } else {
                lastEnd->next = stack.top();
                stack.pop();
                lastEnd = lastEnd->next;
            }
        }
        lastEnd->next = curr;
    }
    return topNew;

}
