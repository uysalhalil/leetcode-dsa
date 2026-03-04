// problem: 0041 first missing positive
// difficulty: hard
// studysets: dsa-quest
// url: https://leetcode.com/problems/first-missing-positive/
// tags: array, hash-set, brute-force-scan

#include <unordered_set>
#include <vector>
using std::unordered_set, std::vector;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> presentPosNums;
        int minMissingPosNum = 1;
        for (int& num : nums) {
            if (num > 0) {
                presentPosNums.insert(num);
                while (presentPosNums.find(minMissingPosNum) != presentPosNums.end()) {
                    ++minMissingPosNum;
                }
            }
        }
        return minMissingPosNum;
    }
};
