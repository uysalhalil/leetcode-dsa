// problem: 1200 minimum absolute difference
// difficulty: easy
// studysets: dsa-quest
// url: https://leetcode.com/problems/minimum-absolute-difference/
// tags: array, sorting

#include <algorithm>
#include <climits>
#include <vector>

using std::sort;
using std::vector;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        for (int i = 1; i < arr.size(); ++i) {
            minDiff = minDiff > (arr[i] - arr[i - 1]) ? (arr[i] - arr[i - 1]) : minDiff;
        }
        for (int i = 0; i < arr.size() - 1; ++i) {
            if (arr[i] + minDiff == arr[i + 1]) {
                res.push_back({arr[i], arr[i + 1]});
            }
        }
        return res;
    }
};
