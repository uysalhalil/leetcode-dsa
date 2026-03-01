// problem: 0520 detect capital
// difficulty: easy
// studysets: dsa-quest
// url: https://leetcode.com/problems/detect-capital/
// tags: string, character-classification

#include <string>
class Solution {
public:
    bool detectCapitalUse(std::string word) {
        // bool allCapitalFlag = true;
        // bool allLowerFlag = true;
        // bool firstLetterFlag = true;
        // for (auto& c : word) {
        //     if (c != toupper(c))
        //         allCapitalFlag = false;
        // }
        // for (auto& c : word) {
        //     if (c != tolower(c))
        //         allLowerFlag = false;
        // }
        // for (int i = 0; i < word.size(); ++i) {
        //     if (i == 0 && word[i] != toupper(word[i])) {
        //         firstLetterFlag = false;
        //     }
        //     else if (i > 0 && word[i] != tolower(word[i])) {
        //         firstLetterFlag = false;
        //     }
        // }
        // return allCapitalFlag || allLowerFlag || firstLetterFlag;

        int caps = 0;
        for (char c : word) {
            if (isupper(c)) {
                caps++;
            }
        }

        bool allCaps = caps == word.size();
        bool allLower = caps == 0;
        bool firstLetter = (caps == 1 && isupper(word[0]));
        return allCaps || allLower || firstLetter;
    }
};
