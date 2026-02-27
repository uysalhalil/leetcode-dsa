// problem: 2073 time needed to buy tickets
// difficulty: easy
// studysets: dsa-quest, queue
// url: https://leetcode.com/problems/time-needed-to-buy-tickets/
// tags: queue, simulation, array
#include <vector>
using std::vector;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int idx = 0;
        int time = 0;
        while (tickets[k] > 0) {
            if (tickets[idx] > 0) {
                --tickets[idx];
                ++time;
            }
            idx = (idx + 1) % tickets.size();
        }
        return time;
    }
};
