// problem: 1664 ways to make a fair array
// difficulty: medium
// studysets: dsa-quest
// url: https://leetcode.com/problems/ways-to-make-a-fair-array/
// tags: array, prefix-sum
#include <vector>

using std::vector;

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftEven(n), leftOdd(n), rightEven(n), rightOdd(n);

        for (int i = 0; i < n; i++) {
            if (i > 0) {
                leftEven[i] = leftEven[i - 1];
                leftOdd[i] = leftOdd[i - 1];
            }
            if (i % 2 == 0)
                leftEven[i] += nums[i];
            else
                leftOdd[i] += nums[i];
        }

        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1) {
                rightEven[i] = rightEven[i + 1];
                rightOdd[i] = rightOdd[i + 1];
            }
            if (i % 2 == 0)
                rightEven[i] += nums[i];
            else
                rightOdd[i] += nums[i];
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            int evenSum = leftEven[i] + rightOdd[i];
            int oddSum = leftOdd[i] + rightEven[i];

            if (evenSum == oddSum)
                res++;
        }

        return res;
    }
};