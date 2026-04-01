// problem: 0147 insertion sort list
// difficulty: medium
// studysets: dsa-quest
// url: https://leetcode.com/problems/insertion-sort-list/
// tags: linked-list, sorting, insertion-sort

#include "ListNode.h"

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy_head = new ListNode(-1);
        dummy_head->next = head;
        ListNode* prev = dummy_head;
        ListNode* curr = head;
        while (curr->next) {
            ListNode* prev_runner = prev;
            ListNode* runner = curr;
            while (runner) {
                if (runner->val < curr->val) {
                    prev_runner->next = prev_runner->next->next;  // remove runner

                    prev->next = runner;  // insert runner between prev and current
                    runner->next = curr;

                    curr = runner;  // move curr to smaller valued node

                    runner = prev_runner->next;  // move runner back to original position
                } else {
                    prev_runner = prev_runner->next;
                    runner = prev_runner->next;
                }
            }
            curr = curr->next;
            prev = prev->next;
        }
        return dummy_head->next;
    }
};
