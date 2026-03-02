// problem: 0083 remove duplicates from sorted list
// difficulty: easy
// studysets: dsa-quest
// url: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// tags: linked-list, two-pointers

#include "ListNode.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;

        ListNode* currNode = head;
        while (currNode->next) {
            if (currNode->val == currNode->next->val) {
                ListNode* dup = currNode->next;
                currNode->next = dup->next;
                delete dup;
            } else {
                currNode = currNode->next;
            }
        }
        return head;
    }
};
