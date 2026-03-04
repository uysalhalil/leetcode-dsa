// problem: 1732 find the highest altitude
// difficulty: easy
// studysets: dsa-quest
// url: https://leetcode.com/problems/find-the-highest-altitude/
// tags: prefix-sum, array, running-maximum

#include <vector>
using std::vector;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAltitude = 0, currentAltitude = 0;
        for (auto& g : gain) {
            currentAltitude += g;
            maxAltitude = std::max(maxAltitude, currentAltitude);
        }
        return maxAltitude;
    }
};
