// problem: 0084 largest rectangle in histogram
// difficulty: hard
// studysets: dsa-quest, monotonic-stack
// url: https://leetcode.com/problems/largest-rectangle-in-histogram/
// tags: array, monotonic-stack

#include <vector>
class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        const int n = static_cast<int>(heights.size());
        std::vector<int> stack;
        int maxArea = 0;
        for (int i = 0; i <= n; ++i) {
            int h = (i == n ? 0 : heights[i]);

            while (!stack.empty() && h < heights[stack.back()]) {
                int height = heights[stack.back()];
                stack.pop_back();

                int left = stack.empty() ? -1 : stack.back();
                int width = i - left - 1;

                maxArea = std::max(maxArea, height * width);
            }

            stack.push_back(i);
        }
        return maxArea;
    }
};
