// problem: 0459 repeated substring pattern
// difficulty: easy
// studysets: dsa-quest
// url: https://leetcode.com/problems/repeated-substring-pattern/
// tags: string, pattern-matching
#include <string>
using std::string;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        return t.substr(1, t.size() - 2).find(s) != string::npos;
    }
};
