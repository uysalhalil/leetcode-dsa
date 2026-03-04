// problem: 0138 copy list with random pointer
// difficulty: medium
// studysets: dsa-quest
// url: https://leetcode.com/problems/copy-list-with-random-pointer/
// tags: linked-list, hash-table, deep-copy

#include <unordered_map>

#include "Node.h"
using std::unordered_map;

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodePairs;
        Node* currNode = head;
        // build deep copy nodes without connecting
        while (currNode) {
            nodePairs[currNode] = new Node(currNode->val);
            currNode = currNode->next;
        }
        // connect nodes with hash map
        currNode = head;
        while (currNode) {
            nodePairs[currNode]->next = nodePairs[currNode->next];
            if (currNode->random) {
                nodePairs[currNode]->random = nodePairs[currNode->random];
            }
            currNode = currNode->next;
        }
        return nodePairs[head];
    }
};

/*
// Solution without hash map, O(1) space complexity
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;

        // 1) interleave cloned nodes
        Node* curr = head;
        while (curr) {
            Node* clone = new Node(curr->val);
            clone->next = curr->next;
            curr->next = clone;
            curr = clone->next;
        }

        // 2) assign random pointers
        curr = head;
        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // 3) detach cloned list
        Node* newHead = head->next;
        curr = head;
        while (curr) {
            Node* clone = curr->next;
            curr->next = clone->next;
            clone->next = clone->next ? clone->next->next : nullptr;
            curr = curr->next;
        }

        return newHead;
    }
};
*/
