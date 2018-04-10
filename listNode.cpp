//
// Created by Syrup on 9/04/2018.
//

#include "listNode.h"

ListNode* makeList(std::vector<int> list) {
    if (list.size() == 0) {
        return NULL;
    }
    ListNode* head = new ListNode(list.at(0));
    ListNode* curr = head;
    for (int i = 1; i < list.size(); ++i) {
        curr->next = new ListNode(list.at(i));
        curr = curr->next;
    }
    return head;
}

void deleteList(ListNode* head) {
    if (head == NULL) {
        return;
    }
    ListNode* prev = head;
    ListNode* next;
    while (prev != NULL) {
        next = prev->next;
        delete prev;
        prev = next;
    }
}