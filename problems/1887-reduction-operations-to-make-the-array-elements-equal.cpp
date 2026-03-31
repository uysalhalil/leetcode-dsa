// problem: 1887 reduction operations to make the array elements equal
// difficulty: medium
// studysets: dsa-quest
// url: https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/
// tags: array, sorting, greedy

#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int sum = 0;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i - 1] != nums[i]) {
                sum += n - i;
            }
        }
        return sum;
    }
};
