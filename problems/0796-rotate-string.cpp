// problem: 0796 rotate string
// difficulty: easy
// studysets: dsa-quest
// url: https://leetcode.com/problems/rotate-string/
// tags: string, rotation, pattern-matching
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
private:
    bool search(string& s, string& goal, int start_idx) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[(i + start_idx) % n] != goal[i]) {
                return false;
            }
        }
        return true;
    }

public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())
            return false;

        vector<int> shiftIndices;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == goal[0]) {
                shiftIndices.push_back(i);
            }
        }

        for (int shift : shiftIndices) {
            if (search(s, goal, shift)) {
                return true;
            }
        }
        return false;
    }
};
