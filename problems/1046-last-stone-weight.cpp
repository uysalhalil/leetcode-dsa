// problem: 1046 last stone weight
// difficulty: easy
// studysets: dsa-quest
// url: https://leetcode.com/problems/last-stone-weight/
// tags: heap, priority-queue, simulation
#include <queue>
#include <vector>

using std::less;
using std::priority_queue;
using std::vector;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> heap(stones.begin(), stones.end());
        while (heap.size() > 1) {
            int stone1 = heap.top();
            heap.pop();
            int stone2 = heap.top();
            heap.pop();
            int remainingStone = stone1 - stone2;
            heap.push(remainingStone);
        }
        return heap.size() > 0 ? heap.top() : 0;
    }
};
