// problem: 0739 daily temperatures
// difficulty: medium
// studysets: dsa-quest
// url: https://leetcode.com/problems/daily-temperatures/
// tags: array, monotonic-stack
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> idx;
        vector<int> res(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); ++i) {
            while (!idx.empty() && temperatures[i] > temperatures[idx.back()]) {
                res[idx.back()] = i - idx.back();
                idx.pop_back();
            }
            idx.push_back(i);
        }
        return res;
    }
};
