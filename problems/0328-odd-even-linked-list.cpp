// problem: 0328 odd even linked list
// difficulty: medium
// studysets: dsa-quest
// url: https://leetcode.com/problems/odd-even-linked-list/
// tags: linked-list, two-pointers, in-place

#include "ListNode.h"

class Solution {
private:
    int _size{0};
    ListNode* getTail(ListNode* head) {
        ListNode* curr{head};
        while (curr->next) {
            curr = curr->next;
            ++_size;
        }
        return curr;
    }

public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return head;

        ListNode* tail = getTail(head);
        ListNode* movingTail{tail};
        ListNode* curr = head;
        int i = 0;
        while (i < _size) {
            ListNode* moveToEnd = curr->next;
            curr->next = curr->next->next;
            moveToEnd->next = nullptr;
            movingTail->next = moveToEnd;
            movingTail = moveToEnd;
            curr = curr->next;
            i += 2;
        }

        return head;
    }
};
