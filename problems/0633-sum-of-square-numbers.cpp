// problem: 0633 sum of square numbers
// difficulty: medium
// studysets: dsa-quest
// url: https://leetcode.com/problems/sum-of-square-numbers/
// tags: math, two-pointer, brute-force

#include <cmath>

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) {
            double b = sqrt(c - a * a);
            if (b == (int)b) {
                return true;
            }
        }
        return false;
    }
};
