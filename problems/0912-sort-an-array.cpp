// problem: 0912 sort an array
// difficulty: medium
// studysets: dsa-quest
// url: https://leetcode.com/problems/sort-an-array/
// tags: array, quicksort, divide-and-conquer

#include <cstdlib>
#include <utility>
#include <vector>

using std::pair;
using std::swap;
using std::vector;

class Solution {
public:
    void insert(vector<int>& nums, int idx) {
        for (int i = idx - 1; i >= 0; --i) {
            if (nums[i] > nums[i + 1])
                swap(nums[i], nums[i + 1]);
            else
                break;
        }
    }
    void insertion_sort(vector<int>& nums) {  // time limit exceed
        for (int i = 0; i < nums.size(); ++i) {
            insert(nums, i);
        }
    }

    void merge(vector<int>& nums, int l, int m, int r) {
        vector<int> temp(r - l + 1, 0);
        int k = 0;
        int i = l;
        int j = m + 1;
        while (i <= m && j <= r) {
            if (nums[i] < nums[j])
                temp[k++] = nums[i++];
            else
                temp[k++] = nums[j++];
        }
        while (i <= m)
            temp[k++] = nums[i++];
        while (j <= r)
            temp[k++] = nums[j++];

        for (int idx = l, k = 0; idx <= r; ++idx, ++k) {
            nums[idx] = temp[k];
        }
    }
    void merge_sort(vector<int>& nums, int l, int r) {
        if (l >= r)
            return;

        int m = l + (r - l) / 2;
        merge_sort(nums, l, m);
        merge_sort(nums, m + 1, r);
        merge(nums, l, m, r);
    }

    int partition(vector<int>& nums, int l, int r) {
        int range = r - l + 1;
        int rand_pivot = rand() % range + l;
        swap(nums[l], nums[rand_pivot]);
        int pivot_idx = l;
        ++l;
        while (l <= r) {
            if (nums[r] < nums[pivot_idx]) {  // 3,1,5,4,7,2 ->
                swap(nums[l], nums[r]);
                ++l;
            } else {
                --r;
            }
        }
        swap(nums[pivot_idx], nums[r]);
        return r;
    }
    void quick_sort(vector<int>& nums, int l, int r) {
        if (r <= l)
            return;

        int p_idx = partition(nums, l, r);
        quick_sort(nums, l, p_idx - 1);
        quick_sort(nums, p_idx + 1, r);
    }

    pair<int, int> partition3(vector<int>& nums, int l, int r) {
        int pivot_val = nums[l];
        int m1 = l++;
        while (l <= r) {
            if (nums[l] < pivot_val) {
                swap(nums[l], nums[m1]);
                ++m1;
                ++l;
            } else if (nums[l] > pivot_val) {
                swap(nums[l], nums[r]);
                --r;
            } else {
                ++l;
            }
        }
        return pair<int, int>({m1, r});
    }
    void quick_sort3(vector<int>& nums, int l, int r) {
        if (r <= l)
            return;

        auto [m1, m2] = partition3(nums, l, r);
        quick_sort3(nums, l, m1 - 1);
        quick_sort3(nums, m2 + 1, r);
    }

    vector<int> sortArray(vector<int>& nums) {
        // sort(nums.begin(), nums.end()); // 65 ms native implementation
        // insertion_sort(nums);
        // merge_sort(nums, 0, nums.size()-1);
        // quick_sort(nums, 0, nums.size()-1);
        quick_sort3(nums, 0, nums.size() - 1);
        return nums;
    }
};
