// problem: 0852 peak index in a mountain array
// difficulty: easy
// studysets: dsa-quest
// url: https://leetcode.com/problems/peak-index-in-a-mountain-array/
// tags: array

#include <vector>
using std::vector;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i = 0;
        while (arr[i] < arr[i + 1]) {
            ++i;
        }
        return i;
    }
};
