// problem: 0686 repeated string match
// difficulty: medium
// studysets: dsa-quest
// url: https://leetcode.com/problems/repeated-string-match/
// tags: string, pattern-matching, repetition
#include <string>
using std::string;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s;
        int count = 0;

        while (s.size() < b.size()) {
            s += a;
            count++;
        }

        if (s.find(b) != string::npos)
            return count;

        s += a;
        if (s.find(b) != string::npos)
            return count + 1;

        return -1;
    }
};
