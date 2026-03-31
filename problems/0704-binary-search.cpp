// problem: 0704 binary search
// difficulty: easy
// studysets: dsa-quest
// url: https://leetcode.com/problems/binary-search/
// tags: array, binary-search
#include <vector>

using std::vector;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, m = 0, r = nums.size();
        while (l < r) {
            m = (r - l) / 2 + l;
            if (nums[m] == target)
                return m;
            if (nums[m] < target)
                l = m + 1;
            else
                r = m;
        }
        return -1;
    }
};
