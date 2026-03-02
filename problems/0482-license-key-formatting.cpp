// problem: 0482 license key formatting
// difficulty: easy
// studysets: dsa-quest
// url: https://leetcode.com/problems/license-key-formatting/
// tags: string, formatting
#include <string>
using std::string;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        // upper
        std::string temp = "";
        for (auto& c : S) {
            if (c != '-') {
                temp += toupper(static_cast<unsigned char>(c));
            }
        }
        int rem = temp.size() % K;
        std::string res = temp.substr(0, rem);
        for (int i = rem; i < temp.size(); i += K) {
            if (res != "") {
                res += "-";
            }
            res += temp.substr(i, K);
        }
        return res;
    }
};
