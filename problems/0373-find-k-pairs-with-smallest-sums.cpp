// problem: 0373 find k pairs with smallest sums
// difficulty: medium
// studysets: dsa-quest
// url: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
// tags: heap, priority-queue, matrix, k-way-merge

#include <queue>
#include <set>
#include <vector>

using std::pair;
using std::set;
using std::vector;
using T = pair<int, int>;
using U = pair<int, pair<int, int>>;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // prepare
        int m = nums1.size();
        int n = nums2.size();
        set<T> visited;
        vector<vector<int>> res;

        std::priority_queue<U, vector<U>, std::greater<U>> minHeap;
        minHeap.push({nums1[0] + nums2[0], {0, 0}});
        visited.insert({0, 0});

        while (k-- && !minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();
            int i = top.second.first;
            int j = top.second.second;

            res.push_back({nums1[i], nums2[j]});

            if (i + 1 < m && visited.find({i + 1, j}) == visited.end()) {
                minHeap.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }

            if (j + 1 < n && visited.find({i, j + 1}) == visited.end()) {
                minHeap.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }
        }

        return res;
    }
};
