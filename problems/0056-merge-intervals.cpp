// problem: 56 merge intervals
// difficulty: medium
// studysets: dsa-quest
// url: https://leetcode.com/problems/merge-intervals/
// tags: array, sorting, intervals

#include <algorithm>
#include <vector>

using std::max;
using std::min;
using std::sort;
using std::vector;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        vector<vector<int>> merged_intervals;
        merged_intervals.push_back({intervals[0].front(), intervals[0].back()});
        for (int i = 1; i < intervals.size(); ++i) {
            if (merged_intervals.back().back() >= intervals[i].front()) {
                merged_intervals.back().front() = min(intervals[i].front(), merged_intervals.back().front());
                merged_intervals.back().back() = max(intervals[i].back(), merged_intervals.back().back());
            } else {
                merged_intervals.push_back(intervals[i]);
            }
        }
        return merged_intervals;
    }
};
