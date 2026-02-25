// problem: 1475 final prices with a special discount in a shop
// difficulty: easy
// studysets: dsa-quest
// url:
// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
// tags: array, monotonic-stack
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int left = 0;
        int right = 1;

        while (left < prices.size() && right < prices.size()) {
            if (prices[left] >= prices[right]) {
                prices[left] -= prices[right];
                ++left;
                right = left + 1;
            } else {
                ++right;
            }

            if (right >= prices.size()) {
                ++left;
                right = left + 1;
            }
        }
        return prices;
    }
};
