// problem: 0215 kth largest element in an array
// difficulty: medium
// studysets: dsa-quest
// url: https://leetcode.com/problems/kth-largest-element-in-an-array/
// tags: array, heap, priority-queue

#include <queue>
#include <vector>

using std::less;
using std::priority_queue;
using std::vector;
using IntMaxHeap = priority_queue<int, vector<int>, less<int>>;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        IntMaxHeap heap{nums.begin(), nums.end()};
        while (k > 1) {
            heap.pop();
            --k;
        }
        return heap.top();
    }
};
