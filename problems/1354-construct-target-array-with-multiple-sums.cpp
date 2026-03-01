// problem: 1354 construct target array with multiple sums
// difficulty: hard
// studysets: dsa-quest
// url: https://leetcode.com/problems/construct-target-array-with-multiple-sums/
// tags: heap, priority-queue, greedy, math, reverse-simulation

#include <queue>
#include <vector>
using v = std::vector<int>;
using minHeap = std::priority_queue<int>;
class Solution {
public:
    bool isPossible(v& target) {
        long long total = 0;
        minHeap pq;

        for (int x : target) {
            total += x;
            pq.push(x);
        }

        while (true) {
            long long x = pq.top();
            pq.pop();
            long long rest = total - x;

            if (x == 1 || rest == 1)
                return true;
            if (rest == 0 || x < rest)
                return false;

            long long prev = x % rest;
            if (prev == 0)
                return false;

            pq.push(prev);
            total = rest + prev;
        }
    }
};
