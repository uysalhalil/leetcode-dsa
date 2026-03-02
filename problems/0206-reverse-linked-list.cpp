// problem: 0206 reverse linked list
// difficulty: easy
// studysets: dsa-quest
// url: https://leetcode.com/problems/reverse-linked-list/
// tags: linked-list, two-pointers

#include "ListNode.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = curr ? curr->next : nullptr;
        while (curr) {
            curr->next = prev;
            prev = curr;
            curr = next;
            next = curr ? curr->next : nullptr;
        }
        return prev;
    }
};
