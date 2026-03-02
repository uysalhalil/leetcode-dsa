// problem: 0001 two sum
// difficulty: easy
// studysets: dsa-quest
// url: https://leetcode.com/problems/two-sum/
// tags: array, hash-table

#include <unordered_map>
#include <vector>
using std::vector, std::unordered_map;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numIndexMap;
        for (int i = 0; i < nums.size(); ++i) {
            if (numIndexMap.find(target - nums[i]) != numIndexMap.end()) {
                return {numIndexMap[target - nums[i]], i};
            }
            numIndexMap[nums[i]] = i;
        }
        return {};
    }
};
